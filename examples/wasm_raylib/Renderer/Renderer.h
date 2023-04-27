#pragma once

#include <stdint.h>
#include <raylib.h>
#include <vectormath/vectormath_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SpriteBatch
{
    Texture     texture;

    int         spritesCount;
    Rectangle*  sprites;
} SpriteBatch;

int     Renderer_Setup(void);
void    Renderer_Shutdown(void);

void    Renderer_Clear(void);
void    Renderer_Present(void);

void    Renderer_LoadSpritesHorizontal(SpriteBatch* spriteBatch, const char* file, int spriteCount);
void    Renderer_DrawSprite(const SpriteBatch* spriteBatch, int spriteIndex, vec2 position, float rotation, vec2 scale, vec3 color);

vec2    Renderer_TextSize(const char* text);
void    Renderer_DrawText(const char* text, vec2 position, vec3 color);
void    Renderer_DrawQuad(vec2 start, vec2 end, vec3 color);

#ifdef __cplusplus
}
#endif
