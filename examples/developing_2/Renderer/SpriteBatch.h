#pragma once

#include <VectorTypes.h>

typedef struct SpriteBatch
{
    uint32_t            flags;
    
    union
    {
        struct // OpenGL
        {
            uint32_t    textureId;
            uint32_t    vertexArrayId;
            uint32_t    verticesBufferId;
            uint32_t    uvsBufferId;
            uint32_t    colorsBufferId;
        };

        //struct // Vulkan
        //{
        //    void*       bufferId;
        //};
    };
    
    int32_t             count;
    int32_t             capacity;

    vec2*               vertices;
    vec2*               uvs;
    vec3*               colors;
} SpriteBatch;

enum SpriteBatchFlags
{
    SpriteBatchFlags_Idle,
    SpriteBatchFlags_Batching,
};

#ifdef __cplusplus
extern "C" {
#endif

void    SpriteBatch_Create(SpriteBatch* spriteBatch, const SpriteSheet* sheet, int32_t vertexCapacity);
void    SpriteBatch_Destroy(SpriteBatch* spriteBatch);

void    SpriteBatch_Begin(SpriteBatch* spriteBatch);
void    SpriteBatch_End(SpriteBatch* spriteBatch);

void    SpriteBatch_DrawSprite(SpriteBatch* spriteBatch, const Sprite* sprite, vec2 position, float rotation, vec2 scale, vec3 color);
void    SpriteBatch_Present(SpriteBatch* spriteBatch);

#ifdef __cplusplus
}
#endif
