#pragma once

#include <stdint.h>
#include <VectorMath.h>

typedef struct Sprite
{
    float           width;
    float           height;

    vec2            uv0, uv1;

    uint32_t        textureId;
    uint32_t        vertexArrayId;
    uint32_t        vertexBufferId;
} Sprite;

typedef struct SpriteSheet
{
    uint32_t        textureId;

    int32_t         cols;
    int32_t         rows;
    int32_t         spriteCount;

    Sprite*         sprites;
} SpriteSheet;

typedef enum RendererType
{
    RendererType_OpenGL,
    RendererType_Vulkan,
} RendererType;

#ifdef __cplusplus
extern "C" {
#endif

int     Renderer_Setup(struct WindowDesc* window, RendererType renderType);
void    Renderer_Shutdown(struct WindowDesc* window, RendererType renderType);

// -----------------------------------------------------
// Renderer API
// -----------------------------------------------------

#define DECL_RENDERER_FUNC(RETURN_TYPE, NAME, ...)              \
    typedef RETURN_TYPE (*Renderer_##NAME##Fn)(##__VA_ARGS__);  \
    extern Renderer_##NAME##Fn Renderer_##NAME

DECL_RENDERER_FUNC(void,    Clear);
DECL_RENDERER_FUNC(void,    Present);

DECL_RENDERER_FUNC(void,    LoadSpriteSheet, SpriteSheet* spriteSheet, const char* file, int32_t cols, int32_t rows);
DECL_RENDERER_FUNC(void,    UnloadSpriteSheet, SpriteSheet* spriteSheet);

DECL_RENDERER_FUNC(void,    DrawSprite, const Sprite* sprite, vec2 position, float rotation, vec2 scale, vec3 color);

DECL_RENDERER_FUNC(vec2,    TextSize, const char* text);
DECL_RENDERER_FUNC(void,    DrawText, const char* text, vec2 position, vec3 color);
DECL_RENDERER_FUNC(void,    DrawQuad, vec2 start, vec2 end, vec3 color);

#ifdef __cplusplus
}
#endif
