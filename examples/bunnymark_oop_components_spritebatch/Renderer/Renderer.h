#pragma once

#include <stdint.h>
#include <VectorMath.h>

#include "Container/Array.h"

struct Sprite
{
    float           width;
    float           height;

    vec2            uv0, uv1;

    uint32_t        textureId;
    uint32_t        vertexArrayId;
    uint32_t        vertexBufferId;
};

struct SpriteSheet
{
    uint32_t        textureId;

    int             spritesCount;
    Sprite*         sprites;
};

struct SpriteBatch
{
    uint32_t        textureId;

    uint32_t        vertexArrayId;
    
    uint32_t        verticesBufferId;
    uint32_t        uvsBufferId;
    uint32_t        colorsBufferId;

    Array<vec2>     vertices;
    Array<vec2>     uvs;
    Array<vec3>     colors;
};

void    SpriteBatch_Init(SpriteBatch* spriteBatch, const SpriteSheet* sheet, int vertexCount);
void    SpriteBatch_CleanUp(SpriteBatch* spriteBatch);

void    SpriteBatch_Begin(SpriteBatch* spriteBatch);
void    SpriteBatch_End(SpriteBatch* spriteBatch);

void    SpriteBatch_DrawSprite(SpriteBatch* spriteBatch, const Sprite* sprite, const vec2& position, float rotation, const vec2& scale, const vec3& color);

int     Renderer_Setup(struct WindowDesc* window);
void    Renderer_Shutdown(struct WindowDesc* window);

void    Renderer_Clear();
void    Renderer_Present();

void    Renderer_LoadSpriteSheet(SpriteSheet* spritesheet, const char* file, int spriteCount);
void    Renderer_UnloadSpriteSheet(SpriteSheet* spritesheet);

void    Renderer_DrawSprite(const Sprite* sprite, const vec2& position, float rotation, const vec2& scale, const vec3& color);

vec2    Renderer_TextSize(const char* text);
void    Renderer_DrawText(const char* text, const vec2& position, const vec3& color);
void    Renderer_DrawQuad(const vec2& start, const vec2& end, const vec3& color);
