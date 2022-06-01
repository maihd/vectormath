#include <time.h>
#include <float.h>
#include <memory.h>
#include <stdlib.h>
#include <VectorMath.h>

#include "Game/Game.h"
#include "Game/Components.h"

#include "Native/Window.h"
#include "Renderer/Renderer.h"

#include "Container/Array.h"

static WorldBoundsComponent        gWorldBounds;

static int                         gEntityCount;
static MoveComponent*              gMoveComponents;
static SpriteComponent*            gSpriteComponents;
static PositionComponent*          gPositionComponents;

static void Game_MoveEntities(PositionComponent* positionComponents, MoveComponent* moveComponents, int entitiesCount, float deltaTime)
{
    WorldBoundsComponent bounds = gWorldBounds;
    for (int i = 0; i < entitiesCount; i++)
    {
        PositionComponent* positionComponent = positionComponents + i;
        MoveComponent* moveComponent = moveComponents + i;

        vec2 velocity = moveComponent->velocity;
        vec2 position = positionComponent->position + velocity * deltaTime;

        if (position.x < bounds.xMin) { velocity.x = -velocity.x; position.x = bounds.xMin; }
        if (position.x > bounds.xMax) { velocity.x = -velocity.x; position.x = bounds.xMax; }
        if (position.y < bounds.yMin) { velocity.y = -velocity.y; position.y = bounds.yMin; }
        if (position.y > bounds.yMax) { velocity.y = -velocity.y; position.y = bounds.yMax; }

        positionComponent->position = position;
        moveComponent->velocity = velocity;
    }
}

static void Game_DrawEntities(const PositionComponent* positionComponents, const SpriteComponent* spriteComponents, int entitiesCount)
{
    for (int i = 0, n = entitiesCount; i < n; i++)
    {
        const PositionComponent* position = positionComponents + i;
        const SpriteComponent* sprite = spriteComponents + i;
        if (position && sprite)
        {
            Renderer_DrawSprite(sprite->spriteBatch, sprite->spriteIndex, position->position, 0.0f, sprite->scale, sprite->color);
        }
    }
}

float Random()
{
    union
    {
        int         i;
        uint32_t    u;
    } number = { rand() };

    return clampf(2.0f * (float)(number.u % UINT16_MAX) / (float)UINT16_MAX, 0.0f, 1.0f);
}

float RandomFloat(float min, float max)
{
    const float range = Random();
    return (max - min) * range + min;
}

void Game_Setup(struct SpriteBatch* spriteBatch, int entityCount)
{
    srand(time(nullptr));

    const float worldWidth = Window_GetWidth();
    const float worldHeight = Window_GetHeight();
    gWorldBounds.xMin = 0;
    gWorldBounds.xMax = worldWidth;
    gWorldBounds.yMin = 0;
    gWorldBounds.yMax = worldHeight;
    
    gEntityCount = entityCount;
    gMoveComponents = (MoveComponent*)_aligned_malloc(entityCount * sizeof(MoveComponent), alignof(MoveComponent));
    gSpriteComponents = (SpriteComponent*)_aligned_malloc(entityCount * sizeof(SpriteComponent), alignof(SpriteComponent));
    gPositionComponents = (PositionComponent*)_aligned_malloc(entityCount * sizeof(PositionComponent), alignof(PositionComponent));

    for (int i = 0; i < entityCount; i++)
    {
        PositionComponent* position = &gPositionComponents[i];
        position->position = vec2(Random() * worldWidth, Random() * worldHeight);

        SpriteComponent* sprite = &gSpriteComponents[i];
        sprite->scale = vec2(1.0f, 1.0f);
        sprite->color = vec3(1.0f, 1.0f, 1.0f);
        sprite->spriteIndex = (uint32_t)rand() % spriteBatch->spritesCount;
        sprite->spriteBatch = spriteBatch;

        MoveComponent* move = &gMoveComponents[i];
        move->position = position;
        move->velocity = vec2(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f));
    }
}

void Game_Shutdown()
{
    _aligned_free(gMoveComponents);
    _aligned_free(gSpriteComponents);
    _aligned_free(gPositionComponents);
}

void Game_Update(float time, float deltaTime)
{
    Game_MoveEntities(gPositionComponents, gMoveComponents, gEntityCount, deltaTime);
}

void Game_Render()
{
    Game_DrawEntities(gPositionComponents, gSpriteComponents, gEntityCount);
}
