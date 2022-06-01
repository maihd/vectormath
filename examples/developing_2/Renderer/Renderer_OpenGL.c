#include "OpenGL.h"
#include "Renderer.h"
#include "Native/Window.h"

#include <assert.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <3rd_party/stb/stb_image.h>
#include <3rd_party/stb/stb_easy_font.h>

#define RENDERER_FUNC(NAME, RETURN_TYPE, ...) RETURN_TYPE (*Renderer_##NAME)(##__VA_ARGS__)

RENDERER_FUNC(Clear, void);
RENDERER_FUNC(Present, void);

RENDERER_FUNC(LoadSpriteSheet, void, SpriteSheet* spriteSheet, const char* file, int spriteCount);
RENDERER_FUNC(UnloadSpriteSheet, void, SpriteSheet* spriteSheet);

RENDERER_FUNC(DrawSprite, void, const SpriteSheet* spriteSheet, vec2 position, float rotation, vec2 scale, vec3 color);

RENDERER_FUNC(TextSize, vec2, const char* text);
RENDERER_FUNC(DrawText, void, const char* text, vec2 position, vec3 color);
RENDERER_FUNC(DrawQuad, void, vec2 start, vec2 end, vec3 color);

static WindowDesc*  gMainWindow;
static void*        gGLContext;

static uint32_t     gProgramDrawText;
static uint32_t     gProgramDrawSprite;
static uint32_t     gProgramSpriteBatch;

static uint32_t     gVao;
static uint32_t     gVbo;
static uint32_t     gIbo;

static mat4         gProjection;

static const char* vshader_src =
    "#version 330 core\n"
    "layout (location = 0) in vec4 vertex;"
    "out vec2 UV;"
    "uniform mat4 Projection;"
    "uniform mat4 Model;"
    "void main() {"
        "UV = vertex.zw;"
        "gl_Position = Projection * Model * vec4(vertex.xy, 0, 1.0);"
    "}";

static const char* fshader_src =
    "#version 330 core\n"
    "in vec2 UV;"
    "out vec4 FragColor;"
    "uniform vec3 Color;"
    "uniform sampler2D Image;"
    "void main() {"
        //"FragColor = vec4(Color, 1.0);"
        "FragColor = texture(Image, UV) * vec4(Color, 1.0);"
    "}";

static const char* vshader_draw_text_src =
    "#version 330 core\n"
    "layout (location = 0) in vec2 vertex;"
    "uniform mat4 Projection;"
    "uniform mat4 Model;"
    "void main() {"
        "gl_Position = Projection * Model * vec4(vertex.xy, 0, 1.0);"
    "}";

static const char* fshader_draw_text_src =
    "#version 330 core\n"
    "in vec2 UV;"
    "out vec4 FragColor;"
    "uniform vec3 Color;"
    "uniform sampler2D Image;"
    "void main() {"
        "FragColor = vec4(Color, 1.0);"
    "}";

static const char* vshader_sprite_batch_src =
    "#version 330 core\n"
    "layout (location = 0) in vec2 vertex;"
    "layout (location = 1) in vec2 uv;"
    "layout (location = 2) in vec3 color;"
    "out vec2 UV;"
    "out vec3 Color;"
    "uniform mat4 Projection;"
    "void main() {"
        "UV = uv;"
        "Color = color;"
        "gl_Position = Projection * vec4(vertex, 0, 1.0);"
    "}";

static const char* fshader_sprite_batch_src =
    "#version 330 core\n"
    "in vec2 UV;"
    "in vec3 Color;"
    "out vec4 FragColor;"
    "uniform sampler2D Image;"
    "void main() {"
        //"FragColor = vec4(Color, 1.0);"
        "FragColor = texture(Image, UV) * vec4(Color, 1.0);"
    "}";

static uint32_t Renderer_CreateShader(uint32_t type, const char* src)
{
    uint32_t shader = glCreateShader(type);
    if (!shader)
    {
        //const char* error = (const char*)glewGetErrorString(glGetError());
        return 0;
    }

    glShaderSource(shader, 1, &src, 0);
    glCompileShader(shader);

    int status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        char errorLog[1024];
        glGetShaderInfoLog(shader, sizeof(errorLog), 0, errorLog);

        glDeleteShader(shader);
        return 0;
    }
    else
    {
        return shader;
    }
}

static uint32_t Renderer_CreateProgram(const char* vshaderSource, const char* fshaderSource)
{
    uint32_t vshader = Renderer_CreateShader(GL_VERTEX_SHADER, vshaderSource);
    uint32_t fshader = Renderer_CreateShader(GL_FRAGMENT_SHADER, fshaderSource);

    uint32_t program = glCreateProgram();
    if (!program)
    {
        glDeleteShader(vshader);
        glDeleteShader(fshader);
        return 0;
    }

    glAttachShader(program, vshader);
    glAttachShader(program, fshader);
    glLinkProgram(program);

    int status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (!status)
    {
        char errorLog[1024];
        glGetProgramInfoLog(program, sizeof(errorLog), 0, errorLog);
        glDeleteProgram(program);
        program = 0;
    }

    glDeleteShader(vshader);
    glDeleteShader(fshader);
    return program;
}

static int OpenGL_Setup(struct WindowDesc* window)
{
    assert(gMainWindow == NULL && gGLContext == NULL);

    if (glLoadFunctions() != GLLoadError_None)
    {
        return -1;
    }

    gGLContext = glCreateContext(window);
    if (!gGLContext)
    {
        return -1;
    }
    
    gMainWindow = window;
    
    // Apply default settings
    glEnable(GL_BLEND);
    glBlendEquation(GL_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Create default objects
    gProgramDrawText = Renderer_CreateProgram(vshader_draw_text_src, fshader_draw_text_src);
    gProgramDrawSprite = Renderer_CreateProgram(vshader_src, fshader_src);
    gProgramSpriteBatch = Renderer_CreateProgram(vshader_sprite_batch_src, fshader_sprite_batch_src);

    glGenVertexArrays(1, &gVao);
    glGenBuffers(1, &gVbo);
    glGenBuffers(1, &gIbo);

    glBindVertexArray(gVao);
    glBindBuffer(GL_ARRAY_BUFFER, gVbo);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 4 * sizeof(float), 0);

    glBindVertexArray(gIbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gVbo);

    return 0;
}

static void OpenGL_Shutdown(struct WindowDesc* window)
{
    if (gGLContext)
    {
        assert(window == gMainWindow);
        
        glDeleteProgram(gProgramDrawSprite);
        glDeleteProgram(gProgramDrawText);
        gProgramDrawSprite = 0;
        gProgramDrawText = 0;

        glDeleteContext(gGLContext);

        gGLContext  = NULL;
        gMainWindow = NULL;
    }
}

void OpenGL_Clear()
{
    assert(gMainWindow != NULL && gGLContext != NULL);
    
    gProjection = mat4_ortho(0, (float)gMainWindow->width, 0, (float)gMainWindow->height, -10.0f, 10.0f);

    glViewport(0, 0, gMainWindow->width, gMainWindow->height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL_Present()
{
    assert(gMainWindow != NULL && gGLContext != NULL);

    glMakeContextCurrent(gMainWindow, gGLContext);
    SwapBuffers((HDC)gMainWindow->device);
}

void OpenGL_LoadSpriteSheet(SpriteSheet* spriteSheet, const char* file, int32_t cols, int32_t rows)
{
    glGenTextures(1, &spriteSheet->textureId);
    glBindTexture(GL_TEXTURE_2D, spriteSheet->textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    int width, height, channels;
    const void* pixels = stbi_load(file, &width, &height, &channels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, channels == 4 ? GL_RGBA : GL_RGB, GL_UINT8, pixels);
    
    int32_t spriteCount = cols * rows;
    spriteSheet->sprites = (Sprite*)malloc(spriteCount * sizeof(Sprite));
    spriteSheet->spriteCount = spriteCount;
    spriteSheet->cols = cols;
    spriteSheet->rows = rows;

    const float spriteWidth  = (float)width  / (float)cols;
    const float spriteHeight = (float)height / (float)rows;
    
    const float invCols = 1.0f / (float)cols;
    const float invRows = 1.0f / (float)rows;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Sprite* sprite = &spriteSheet->sprites[i * cols + j];
            sprite->textureId = spriteSheet->textureId;
            sprite->width = spriteWidth;
            sprite->height = spriteHeight;

            glGenVertexArrays(1, &sprite->vertexArrayId);
            glGenBuffers(1, &sprite->vertexBufferId);

            glBindVertexArray(sprite->vertexArrayId);
            glBindBuffer(GL_ARRAY_BUFFER, sprite->vertexBufferId);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, false, 4 * sizeof(float), 0);

            const vec2 pos0 = vec2_new(-0.5f, -0.5f);
            const vec2 pos1 = vec2_new( 0.5f,  0.5f);

            const vec2 uv0 = vec2_new((float) j      * invCols, (float)(i + 1) * invRows);
            const vec2 uv1 = vec2_new((float)(j + 1) * invCols, (float) i      * invRows);

            sprite->uv0 = uv0;
            sprite->uv1 = uv1;

            const float vertices[] = {
                // pos              // tex
                pos0.x, pos0.y,     uv0.x, uv0.y,
                pos1.x, pos1.y,     uv1.x, uv1.y,
                pos0.x, pos1.y,     uv0.x, uv1.y,

                pos0.x, pos0.y,     uv0.x, uv0.y,
                pos1.x, pos0.y,     uv1.x, uv0.y,
                pos1.x, pos1.y,     uv1.x, uv1.y,
            };
            glBindBuffer(GL_ARRAY_BUFFER, sprite->vertexBufferId);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        }
    }
}

void OpenGL_UnloadSpriteSheet(SpriteSheet* spriteSheet)
{
    for (int i = 0, n = spriteSheet->spriteCount; i < n; i++)
    {
        Sprite sprite = spriteSheet->sprites[i];
        glDeleteBuffers(1, &sprite.vertexBufferId);
        glDeleteVertexArrays(1, &sprite.vertexArrayId);
    }

    glDeleteTextures(1, &spriteSheet->textureId);

    free(spriteSheet->sprites);

    spriteSheet->textureId = 0;

    spriteSheet->sprites = NULL;

    spriteSheet->cols = 0;
    spriteSheet->rows = 0;
    spriteSheet->spriteCount = 0;
}

static void OpenGL_DrawSprite(const Sprite* sprite, vec2 position, float rotation, vec2 scale, vec3 color)
{
    glBindVertexArray(sprite->vertexArrayId);

    glUseProgram(gProgramDrawSprite);

    const mat4 model = mat4_mul(mat4_mul(mat4_translation_v2(position), mat4_rotation_z(rotation)), mat4_scalation_v2(vec2_mul(scale, vec2_new(sprite->width, sprite->height))));
    glUniformMatrix4fv(glGetUniformLocation(gProgramDrawSprite, "Model"), 1, false, (const float*)&model);
    glUniformMatrix4fv(glGetUniformLocation(gProgramDrawSprite, "Projection"), 1, false, (const float*)&gProjection);
    glUniform3f(glGetUniformLocation(gProgramDrawSprite, "Color"), color.x, color.y, color.z);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite->textureId);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

static vec2 OpenGL_TextSize(const char* text)
{
    return vec2_mul1(vec2_new((float)stb_easy_font_width((char*)text), (float)stb_easy_font_height((char*)text)), 3.0f);
}

static void OpenGL_DrawText(const char* text, vec2 position, vec3 color)
{
    static float    vertices[4 * 10 * 1024]; // ~2000 chars
    static uint16_t indices[(sizeof(vertices) / sizeof(vertices[0])) / 4 * 6];
    
    const int quadsCount = stb_easy_font_print(0, 0, (char*)text, NULL, vertices, sizeof(vertices));
    const int vertexCount = quadsCount * 4;
    const int indexCount = quadsCount * 6;

    uint16_t* ptr = indices;
    for (int i = 0; i < quadsCount; i++)
    {
        uint16_t startIndex = i * 4;
        *ptr++ = startIndex + 0U;
        *ptr++ = startIndex + 1U;
        *ptr++ = startIndex + 2U;
        *ptr++ = startIndex + 0U;
        *ptr++ = startIndex + 2U;
        *ptr++ = startIndex + 3U;
    }
    
    glBindVertexArray(gVao);
    glBindBuffer(GL_ARRAY_BUFFER, gVbo);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 4 * sizeof(float), vertices, GL_STREAM_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint32_t), indices, GL_STREAM_DRAW);

    glUseProgram(gProgramDrawText);

    const vec2 drawPosition = vec2_sub(position, vec2_new(0.0f, 3.0f * stb_easy_font_height((char*)text)));
    const mat4 model = mat4_mul(mat4_translation_v2(drawPosition), mat4_scalation_v2(vec2_new(3.0f, -3.0f)));
    glUniformMatrix4fv(glGetUniformLocation(gProgramDrawText, "Model"), 1, false, (const float*)&model);
    glUniformMatrix4fv(glGetUniformLocation(gProgramDrawText, "Projection"), 1, false, (const float*)&gProjection);
    glUniform3f(glGetUniformLocation(gProgramDrawText, "Color"), color.x, color.y, color.z);

    glDrawElements(GL_TRIANGLES, indexCount, GL_UINT16, NULL);
}

static void OpenGL_DrawQuad(vec2 start, vec2 end, vec3 color)
{
    const vec2 pos0 = start;
    const vec2 pos1 = end;
    
    const vec2 uv0 = vec2_new1(0.0f);
    const vec2 uv1 = vec2_new1(0.0f);

    const float vertices[] = {
        // pos              // tex
        pos0.x, pos0.y,     uv0.x, uv0.y,
        pos1.x, pos1.y,     uv1.x, uv1.y,
        pos0.x, pos1.y,     uv0.x, uv1.y,

        pos0.x, pos0.y,     uv0.x, uv0.y,
        pos1.x, pos0.y,     uv1.x, uv0.y,
        pos1.x, pos1.y,     uv1.x, uv1.y,
    };

    glBindVertexArray(gVao);
    glBindBuffer(GL_ARRAY_BUFFER, gVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glUseProgram(gProgramDrawText);

    const mat4 model = mat4_identity();
    glUniformMatrix4fv(glGetUniformLocation(gProgramDrawText, "Model"), 1, false, (const float*)&model);
    glUniformMatrix4fv(glGetUniformLocation(gProgramDrawText, "Projection"), 1, false, (const float*)&gProjection);
    glUniform3f(glGetUniformLocation(gProgramDrawText, "Color"), color.x, color.y, color.z);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

int Renderer_Setup(const WindowDesc* desc, RendererType rendererType)
{
    if (OpenGL_Setup(desc) != 0)
    {
        return -1;
    }

    #define LOAD_RENDERER_FUNC(NAME) Renderer_##NAME = OpenGL_##NAME

    LOAD_RENDERER_FUNC(Clear);
    LOAD_RENDERER_FUNC(Present);

    LOAD_RENDERER_FUNC(LoadSpriteSheet);
    LOAD_RENDERER_FUNC(UnloadSpriteSheet);

    LOAD_RENDERER_FUNC(DrawSprite);

    LOAD_RENDERER_FUNC(TextSize);
    LOAD_RENDERER_FUNC(DrawText);
    LOAD_RENDERER_FUNC(DrawQuad);

    #undef LOAD_RENDERER_FUNC

    // Make black window
    Renderer_Clear();
    Renderer_Present();

    return 0;
}

void Renderer_Shutdown(const WindowDesc* desc, RendererType rendererType)
{
    OpenGL_Shutdown(desc);

    #define UNLOAD_RENDERER_FUNC(NAME) Renderer_##NAME = NULL

    UNLOAD_RENDERER_FUNC(LoadSpriteSheet);
    UNLOAD_RENDERER_FUNC(UnloadSpriteSheet);

    UNLOAD_RENDERER_FUNC(DrawSprite);

    UNLOAD_RENDERER_FUNC(TextSize);
    UNLOAD_RENDERER_FUNC(DrawText);
    UNLOAD_RENDERER_FUNC(DrawQuad);

    #undef UNLOAD_RENDERER_FUNC
}

#include "SpriteBatch.h"

void SpriteBatch_Present(SpriteBatch* spriteBatch)
{
    assert(spriteBatch->flags == SpriteBatchFlags_Idle);

    glBindVertexArray(spriteBatch->vertexArrayId);

    int vertexCount = spriteBatch->count * 6;

    glBindBuffer(GL_ARRAY_BUFFER, spriteBatch->verticesBufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2) * vertexCount, spriteBatch->vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, spriteBatch->uvsBufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2) * vertexCount, spriteBatch->uvs, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, spriteBatch->colorsBufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * vertexCount, spriteBatch->colors, GL_DYNAMIC_DRAW);

    glUseProgram(gProgramSpriteBatch);
    glUniformMatrix4fv(glGetUniformLocation(gProgramSpriteBatch, "Projection"), 1, false, (const float*)&gProjection);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
