#include <time.h>
#include <float.h>
#include <memory.h>
#include <stdlib.h>
#include <VectorMath.h>

#include "Game/Game.h"
#include "Game/Components.h"

#include "Native/Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/SpriteBatch.h"

#include "Runtime/JobSystem.h"

struct MoveJobParams
{
    PositionComponent*          positionComponents;
    MoveComponent*              moveComponents;
    int32_t                     entityCount;
    float                       deltaTime;
};

struct RenderJobParams
{
    const PositionComponent*    positionComponents;
    const SpriteComponent*      spriteComponents;
    SpriteBatch*                spriteBatch;
    int32_t                     entityCount;
};

WorldBoundsComponent            gWorldBounds;

int32_t                         gEntityCount;
MoveComponent*                  gMoveComponents;
SpriteComponent*                gSpriteComponents;
PositionComponent*              gPositionComponents;

SpriteBatch                     gSpriteBatchs[JOB_SYSTEM_MAX_WORKERS];
JobSystem                       gJobSystem;

static void Game_MoveEntities(PositionComponent* positionComponents, MoveComponent* moveComponents, int32_t entityCount, float deltaTime)
{
    WorldBoundsComponent bounds = gWorldBounds;
    for (int i = 0; i < entityCount; i++)
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

static void Game_DrawEntities(SpriteBatch* spriteBatch, const PositionComponent* positionComponents, const SpriteComponent* spriteComponents, int32_t entitiesCount)
{
    SpriteBatch_Begin(spriteBatch);
    for (int i = 0, n = entitiesCount; i < n; i++)
    {
        const PositionComponent* positionComponent = positionComponents + i;
        const SpriteComponent* spriteComponent = spriteComponents + i;
        SpriteBatch_DrawSprite(spriteBatch, spriteComponent->sprite, positionComponent->position, 0.0f, spriteComponent->scale, spriteComponent->color);
    }
    SpriteBatch_End(spriteBatch);
}

static void Game_RunMoveJob(void* params)
{
    MoveJobParams* moveParams = (MoveJobParams*)params;
    Game_MoveEntities(moveParams->positionComponents, moveParams->moveComponents, moveParams->entityCount, moveParams->deltaTime);
}

static void Game_RunRenderJob(void* params)
{
    RenderJobParams* renderParams = (RenderJobParams*)params;
    Game_DrawEntities(renderParams->spriteBatch, renderParams->positionComponents, renderParams->spriteComponents, renderParams->entityCount);
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

void Game_Setup(const struct SpriteSheet* spriteSheet, int32_t objectCount)
{
    srand((uint32_t)time(nullptr));

    const float worldWidth = Window_GetWidth();
    const float worldHeight = Window_GetHeight();
    gWorldBounds.xMin = -2 * worldWidth;
    gWorldBounds.xMax = 4 * worldWidth;
    gWorldBounds.yMin = -2 * worldHeight;
    gWorldBounds.yMax = 4 * worldHeight;

    gEntityCount = objectCount;
    gMoveComponents = (MoveComponent*)_aligned_malloc(gEntityCount * sizeof(MoveComponent), alignof(MoveComponent));
    gSpriteComponents = (SpriteComponent*)_aligned_malloc(gEntityCount * sizeof(SpriteComponent), alignof(SpriteComponent));
    gPositionComponents = (PositionComponent*)_aligned_malloc(gEntityCount * sizeof(PositionComponent), alignof(PositionComponent));
    
    JobSystem_Create(&gJobSystem, 0);
    
    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        int spriteBatchCapacity = objectCount / n + (i == n - 1) * (gEntityCount % n);
        SpriteBatch_Create(&gSpriteBatchs[i], spriteSheet, spriteBatchCapacity);
    }

    for (int i = 0; i < objectCount; i++)
    {
        PositionComponent* position = &gPositionComponents[i];
        position->position = vec2_new(Random() * worldWidth, Random() * worldHeight);

        SpriteComponent* sprite = &gSpriteComponents[i];
        sprite->scale = vec2_new(1.0f, 1.0f);
        sprite->color = vec3_new(1.0f, 1.0f, 1.0f);
        sprite->sprite = &spriteSheet->sprites[(uint32_t)rand() % spriteSheet->spriteCount];

        MoveComponent* move = &gMoveComponents[i];
        move->position = position;
        move->velocity = vec2_new(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f));
    }
}

void Game_Shutdown()
{
    _aligned_free(gMoveComponents);
    _aligned_free(gSpriteComponents);
    _aligned_free(gPositionComponents);

    gEntityCount = 0;
    gMoveComponents = nullptr;
    gSpriteComponents = nullptr;
    gPositionComponents = nullptr;

    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        SpriteBatch_Destroy(&gSpriteBatchs[i]);
    }

    JobSystem_Destroy(&gJobSystem);
}

void Game_Update(float time, float deltaTime)
{
    MoveJobParams params[JOB_SYSTEM_MAX_WORKERS];
    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        int entityCountPerJob = gEntityCount / n;
        int startEntityIndex = entityCountPerJob * i;
        int entitiesNeedToHandle = entityCountPerJob + (i == n - 1) * (gEntityCount % n);
        params[i] = { gPositionComponents + startEntityIndex, gMoveComponents + startEntityIndex, entitiesNeedToHandle, deltaTime };
        JobSystem_QueueJob(&gJobSystem, Game_RunMoveJob, &params[i]);
    }
    
    JobSystem_WaitIdle(&gJobSystem);
}

void Game_Render()
{
    RenderJobParams params[JOB_SYSTEM_MAX_WORKERS];
    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        int entityCountPerJob = gEntityCount / n;
        int startEntityIndex = entityCountPerJob * i;
        int entitiesNeedToHandle = entityCountPerJob + (i == n - 1) * (gEntityCount % n);
        params[i] = { gPositionComponents + startEntityIndex, gSpriteComponents + startEntityIndex, &gSpriteBatchs[i], entitiesNeedToHandle };
        JobSystem_QueueJob(&gJobSystem, Game_RunRenderJob, &params[i]);
    }

    JobSystem_WaitIdle(&gJobSystem);

    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        SpriteBatch_Present(&gSpriteBatchs[i]);
    }
}
