#include "Renderer.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>
#include <vectormath.h>

#ifdef __cplusplus
extern "C" {
#endif

int Renderer_Setup(void)
{
    return 0;
}

void Renderer_Shutdown(void)
{
}

void Renderer_Clear(void)
{
    BeginDrawing();
    ClearBackground(BLACK);
}

void Renderer_Present(void)
{
    EndDrawing();
}

void Renderer_LoadSpritesHorizontal(SpriteBatch* spriteBatch, const char* file, int spriteCount)
{
    Texture texture = LoadTexture(file);

    int width = texture.width;
    int height = texture.height;

    spriteBatch->sprites = (Rectangle*)malloc(spriteCount * sizeof(Rectangle));
    spriteBatch->spritesCount = spriteCount;

    const float frameWidth = (float)width / (float)spriteCount;
    const float frameHeight = (float)height;

    for (int i = 0; i < spriteCount; i++)
    {
        Rectangle* frame = &spriteBatch->sprites[i];
        frame->x = (float)i * frameWidth;
        frame->y = 0.0f;
        frame->width = frameWidth;
        frame->height = frameHeight;
    }
}

void Renderer_DrawSprite(const SpriteBatch* spriteBatch, int index, vec2 position, float rotation, vec2 scale, vec3 color)
{
    Rectangle frame = spriteBatch->sprites[index];
    Rectangle drawFrame = Rectangle{
        position.x, position.y, frame.width * scale.x, frame.height * scale.y
    };
    Vector2 origin = Vector2{ frame.width * 0.5f, frame.height * 0.5f };
    Color color4B = Color{ (uint8_t)(color.x * 255), (uint8_t)(color.y * 255), (uint8_t)(color.z * 255), 255 };
    DrawTexturePro(spriteBatch->texture, frame, drawFrame, origin, rotation, color4B);
    DrawTexture(spriteBatch->texture, GetScreenWidth() >> 1, GetScreenHeight() >> 1, WHITE);
}

vec2 Renderer_TextSize(const char* text)
{
    int height = 16;
    int width = MeasureText(text, height);
    return vec2_new((float)width, (float)height);
}

void Renderer_DrawText(const char* text, vec2 position, vec3 color)
{
    Color color4B = Color{ (uint8_t)(color.x * 255), (uint8_t)(color.y * 255), (uint8_t)(color.z * 255), 255 };
    DrawText(text, (int)position.x, (int)position.y, 16, color4B);
}

void Renderer_DrawQuad(vec2 start, vec2 end, vec3 color)
{
    Color color4B = Color{ (uint8_t)(color.x * 255), (uint8_t)(color.y * 255), (uint8_t)(color.z * 255), 255 };
    DrawRectangle((int)start.x, (int)start.y, (int)(end.x - start.x), (int)(end.y - start.y), color4B);
}

#ifdef __cplusplus
}
#endif
