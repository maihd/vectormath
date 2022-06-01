#pragma once

#include <stdint.h>
#include <VectorMath.h>

struct SpriteMesh
{
    float       width;
    float       height;

    uint32_t    vao;
    uint32_t    vbo;
};

typedef struct SpriteBatch
{
    uint32_t    textureId;

    int         spritesCount;
    SpriteMesh* sprites;
} SpriteBatch;

int     Renderer_Setup(struct WindowDesc* window);
void    Renderer_Shutdown(struct WindowDesc* window);

void    Renderer_Clear();
void    Renderer_Present();

void    Renderer_LoadSpritesHorizontal(SpriteBatch* spriteBatch, const char* file, int spriteCount);
void    Renderer_DrawSprite(const SpriteBatch* spriteBatch, int spriteIndex, const vec2& position, float rotation, const vec2& scale, const vec3& color);

vec2    Renderer_TextSize(const char* text);
void    Renderer_DrawText(const char* text, const vec2& position, const vec3& color);
void    Renderer_DrawQuad(const vec2& start, const vec2& end, const vec3& color);
