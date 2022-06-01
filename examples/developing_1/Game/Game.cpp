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
#include "Runtime/JobSystem.h"

struct GameFrame
{
    float                       totalTime;
    float                       deltaTime;
};

struct GameState
{
    WorldBoundsComponent        worldBounds;

    int                         entityCount;
    MoveComponent*              moveComponents;
    SpriteComponent*            spriteComponents;
    PositionComponent*          positionComponents;
};

struct MoveJobParams
{
    WorldBoundsComponent        bounds;
    PositionComponent*          positionComponents;
    MoveComponent*              moveComponents;
    int                         entityCount;
    float                       deltaTime;
};

struct RenderJobParams
{
    const PositionComponent*    positionComponents;
    const SpriteComponent*      spriteComponents;
    SpriteBatch*                spriteBatch;
    int                         entityCount;
};

JobSystem                       gJobSystem;

GameState                       gGameStates[GAME_FRAME_QUEUE_COUNT];
SpriteBatch                     gSpriteBatchs[JOB_SYSTEM_MAX_WORKERS];

static void Game_MoveEntities(WorldBoundsComponent bounds, PositionComponent* positionComponents, MoveComponent* moveComponents, int entityCount, float deltaTime)
{
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

static void Game_DrawEntities(SpriteBatch* spriteBatch, const PositionComponent* positionComponents, const SpriteComponent* spriteComponents, int entitiesCount)
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
    Game_MoveEntities(moveParams->bounds, moveParams->positionComponents, moveParams->moveComponents, moveParams->entityCount, moveParams->deltaTime);
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

void Game_Setup(const struct SpriteSheet* spriteSheet, int objectCount)
{
    srand(time(nullptr));

    const float worldWidth = Window_GetWidth();
    const float worldHeight = Window_GetHeight();

    for (int i = 0; i < GAME_FRAME_QUEUE_COUNT; i++)
    {
        gGameStates[i].worldBounds.xMin = 0;
        gGameStates[i].worldBounds.xMax = worldWidth;
        gGameStates[i].worldBounds.yMin = 0;
        gGameStates[i].worldBounds.yMax = worldHeight;

        gGameStates[i].entityCount = objectCount;
        gGameStates[i].moveComponents = (MoveComponent*)_aligned_malloc(objectCount * sizeof(MoveComponent), alignof(MoveComponent));
        gGameStates[i].spriteComponents = (SpriteComponent*)_aligned_malloc(objectCount * sizeof(SpriteComponent), alignof(SpriteComponent));
        gGameStates[i].positionComponents = (PositionComponent*)_aligned_malloc(objectCount * sizeof(PositionComponent), alignof(PositionComponent));
    }
    
    JobSystem_Create(&gJobSystem, Thread_GetCpuCores() - 2); // substract 2 threads for: game thread and render thread
    
    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        int spriteBatchCapacity = objectCount / n + (i == n - 1) * (objectCount % n);
        SpriteBatch_Create(&gSpriteBatchs[i], spriteSheet, spriteBatchCapacity);
    }

    const uint32_t gameStateIndex = 0;
    GameState* gameState = &gGameStates[gameStateIndex];
    for (int i = 0; i < objectCount; i++)
    {
        PositionComponent* position = &gameState->positionComponents[i];
        position->position = vec2(Random() * worldWidth, Random() * worldHeight);

        SpriteComponent* sprite = &gameState->spriteComponents[i];
        sprite->scale = vec2(1.0f, 1.0f);
        sprite->color = vec3(1.0f, 1.0f, 1.0f);
        sprite->sprite = &spriteSheet->sprites[(uint32_t)rand() % spriteSheet->spritesCount];

        MoveComponent* move = &gameState->moveComponents[i];
        move->position = position;
        move->velocity = vec2(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f));
    }
}

void Game_Shutdown()
{
    for (int i = 0; i < GAME_FRAME_QUEUE_COUNT; i++)
    {
        _aligned_free(gGameStates[i].moveComponents);
        _aligned_free(gGameStates[i].spriteComponents);
        _aligned_free(gGameStates[i].positionComponents);

        gGameStates[i].entityCount = 0;
        gGameStates[i].moveComponents = nullptr;
        gGameStates[i].spriteComponents = nullptr;
        gGameStates[i].positionComponents = nullptr;
    }

    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        SpriteBatch_Destroy(&gSpriteBatchs[i]);
    }

    JobSystem_Destroy(&gJobSystem);
}

void Game_Update(uint32_t frame, float time, float deltaTime)
{
    const bool parallelUpdate = false;

    const uint32_t gameStateIndex = frame % GAME_FRAME_QUEUE_COUNT;
    GameState* gameState = &gGameStates[gameStateIndex];

    const int entityCount = gameState->entityCount;
    MoveComponent* moveComponents = gameState->moveComponents;
    SpriteComponent* spriteComponents = gameState->spriteComponents;
    PositionComponent* positionComponents = gameState->positionComponents;

    MoveJobParams params[JOB_SYSTEM_MAX_WORKERS];
    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        int entityCountPerJob = entityCount / n;
        int startEntityIndex = entityCountPerJob * i;
        int entitiesNeedToHandle = entityCountPerJob + (i == n - 1) * (entityCount % n);

        MoveComponent* moveComponentsToHandle = moveComponents + startEntityIndex;
        PositionComponent* positionComponentsToHandle = positionComponents + startEntityIndex;
        
        if (parallelUpdate)
        {
            params[i] = { gameState->worldBounds, positionComponentsToHandle, moveComponentsToHandle, entitiesNeedToHandle, deltaTime };
            JobSystem_QueueJob(&gJobSystem, Game_RunMoveJob, &params[i]);
        }
        else
        {
            Game_MoveEntities(gameState->worldBounds, positionComponentsToHandle, moveComponentsToHandle, entitiesNeedToHandle, deltaTime);
        }
    }
    
    if (parallelUpdate)
    {
        JobSystem_WaitIdle(&gJobSystem);
    }

    const uint32_t nextGameStateIndex = (frame + 1) % GAME_FRAME_QUEUE_COUNT;
    if (nextGameStateIndex != gameStateIndex)
    {
        GameState* nextGameState = &gGameStates[nextGameStateIndex];

        nextGameState->worldBounds = gameState->worldBounds;
        nextGameState->entityCount = gameState->entityCount;
        memcpy(nextGameState->moveComponents, moveComponents, entityCount * sizeof(MoveComponent));
        memcpy(nextGameState->spriteComponents, spriteComponents, entityCount * sizeof(SpriteComponent));
        memcpy(nextGameState->positionComponents, positionComponents, entityCount * sizeof(PositionComponent));
    }
}

void Game_Render(uint32_t frame)
{
    const bool parallelBatching = true;

    const uint32_t gameStateIndex = frame % GAME_FRAME_QUEUE_COUNT;
    const GameState* gameState = &gGameStates[gameStateIndex];

    const int entityCount = gameState->entityCount;
    const SpriteComponent* spriteComponents = gameState->spriteComponents;
    const PositionComponent* positionComponents = gameState->positionComponents;

    RenderJobParams params[JOB_SYSTEM_MAX_WORKERS];
    for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
    {
        const int entityCountPerJob = entityCount / n;
        const int startEntityIndex = entityCountPerJob * i;
        const int entitiesNeedToDraw = entityCountPerJob + (i == n - 1) * (entityCount % n);

        SpriteBatch* spriteBatchToDraw = &gSpriteBatchs[i];
        const SpriteComponent* spriteComponentsToDraw = spriteComponents + startEntityIndex;
        const PositionComponent* positionComponentsToDraw = positionComponents + startEntityIndex;
        
        if (parallelBatching)
        {
            int entityCountPerJob = entityCount / n;
            int startEntityIndex = entityCountPerJob * i;
            int entitiesNeedToHandle = entityCountPerJob + (i == n - 1) * (entityCount % n);
            params[i] = { positionComponentsToDraw, spriteComponentsToDraw, spriteBatchToDraw, entitiesNeedToDraw };
            JobSystem_QueueJob(&gJobSystem, Game_RunRenderJob, &params[i]);
        }
        else
        {
            Game_DrawEntities(spriteBatchToDraw, positionComponentsToDraw, spriteComponentsToDraw, entitiesNeedToDraw);
            SpriteBatch_Present(spriteBatchToDraw);
        }
    }
    
    if (parallelBatching)
    {
        JobSystem_WaitIdle(&gJobSystem);

        for (int i = 0, n = gJobSystem.workerCount; i < n; i++)
        {
            SpriteBatch_Present(&gSpriteBatchs[i]);
        }
    }
}
