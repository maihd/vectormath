#include "OpenGL.h"
#include "Renderer.h"
#include "SpriteBatch.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <VectorMath.h>

void SpriteBatch_Create(SpriteBatch* spriteBatch, const SpriteSheet* sheet, int32_t capacity)
{
    assert(spriteBatch != NULL);

    spriteBatch->textureId = sheet->textureId;

    glGenBuffers(3, &spriteBatch->verticesBufferId);
    glGenVertexArrays(1, &spriteBatch->vertexArrayId);

    glBindVertexArray(spriteBatch->vertexArrayId);

    glBindBuffer(GL_ARRAY_BUFFER, spriteBatch->verticesBufferId);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, sizeof(vec2), NULL);

    glBindBuffer(GL_ARRAY_BUFFER, spriteBatch->uvsBufferId);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(vec2), NULL);

    glBindBuffer(GL_ARRAY_BUFFER, spriteBatch->colorsBufferId);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, true, sizeof(vec3), NULL);

    spriteBatch->count = 0;
    spriteBatch->capacity = capacity;

    int vertexCapacity = capacity * 6;

    spriteBatch->vertices = (vec2*)_aligned_malloc(vertexCapacity * sizeof(vec2), __alignof(vec2));
    spriteBatch->uvs = (vec2*)_aligned_malloc(vertexCapacity * sizeof(vec2), __alignof(vec2));
    spriteBatch->colors = (vec3*)_aligned_malloc(vertexCapacity * sizeof(vec3), __alignof(vec3));
}

void SpriteBatch_Destroy(SpriteBatch* spriteBatch)
{
    assert(spriteBatch->flags == SpriteBatchFlags_Idle);

    spriteBatch->flags = SpriteBatchFlags_Idle;

    glDeleteBuffers(3, &spriteBatch->verticesBufferId);
    glDeleteVertexArrays(1, &spriteBatch->vertexArrayId);

    _aligned_free(spriteBatch->vertices);
    _aligned_free(spriteBatch->uvs);
    _aligned_free(spriteBatch->colors);

    spriteBatch->vertices = NULL;
    spriteBatch->uvs = NULL;
    spriteBatch->colors = NULL;

    spriteBatch->count = 0;
    spriteBatch->capacity = 0;

    spriteBatch->textureId = 0;
    spriteBatch->vertexArrayId = 0;

    spriteBatch->verticesBufferId = 0;
    spriteBatch->uvsBufferId = 0;
    spriteBatch->colorsBufferId = 0;
}

void SpriteBatch_Begin(SpriteBatch* spriteBatch)
{
    assert(spriteBatch->flags == SpriteBatchFlags_Idle);

    spriteBatch->count = 0;
    spriteBatch->flags = SpriteBatchFlags_Batching;
}

void SpriteBatch_End(SpriteBatch* spriteBatch)
{
    assert(spriteBatch->flags == SpriteBatchFlags_Batching);

    spriteBatch->flags = SpriteBatchFlags_Idle;
}

void SpriteBatch_DrawSprite(SpriteBatch* spriteBatch, const Sprite* sprite, vec2 position, float rotation, vec2 scale, vec3 color)
{
    assert(spriteBatch->count < spriteBatch->capacity);

    const mat4 model = mat4_mul(mat4_mul(mat4_translation_v2(position), mat4_rotation_z(rotation)), mat4_scalation_v2(vec2_mul(scale, vec2_new(sprite->width, sprite->height))));

    const vec2 pos0 = vec2_from_vec3(mat4_mul_v3(model, vec3_new(-0.5f, -0.5f, 0.0f)));
    const vec2 pos1 = vec2_from_vec3(mat4_mul_v3(model, vec3_new( 0.5f,  0.5f, 0.0f)));

    const vec2 uv0 = sprite->uv0;
    const vec2 uv1 = sprite->uv1;

    int vertexIndex = 6 * spriteBatch->count;

    spriteBatch->vertices[vertexIndex + 0] = vec2_new(pos0.x, pos0.y);
    spriteBatch->vertices[vertexIndex + 1] = vec2_new(pos1.x, pos1.y);
    spriteBatch->vertices[vertexIndex + 2] = vec2_new(pos0.x, pos1.y);

    spriteBatch->vertices[vertexIndex + 3] = vec2_new(pos0.x, pos0.y);
    spriteBatch->vertices[vertexIndex + 4] = vec2_new(pos1.x, pos0.y);
    spriteBatch->vertices[vertexIndex + 5] = vec2_new(pos1.x, pos1.y);

    spriteBatch->uvs[vertexIndex + 0] = vec2_new(uv0.x, uv0.y);
    spriteBatch->uvs[vertexIndex + 1] = vec2_new(uv1.x, uv1.y);
    spriteBatch->uvs[vertexIndex + 2] = vec2_new(uv0.x, uv1.y);

    spriteBatch->uvs[vertexIndex + 3] = vec2_new(uv0.x, uv0.y);
    spriteBatch->uvs[vertexIndex + 4] = vec2_new(uv1.x, uv0.y);
    spriteBatch->uvs[vertexIndex + 5] = vec2_new(uv1.x, uv1.y);

    spriteBatch->colors[vertexIndex + 0] = color;
    spriteBatch->colors[vertexIndex + 1] = color;
    spriteBatch->colors[vertexIndex + 2] = color;

    spriteBatch->colors[vertexIndex + 3] = color;
    spriteBatch->colors[vertexIndex + 4] = color;
    spriteBatch->colors[vertexIndex + 5] = color;

    spriteBatch->count++;
}
