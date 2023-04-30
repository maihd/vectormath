#include <time.h>
#include <float.h>
#include <memory.h>
#include <stdlib.h>
#include <vectormath.h>

#include "Game/Game.h"
#include "Game/Components.h"

#include "Renderer/Renderer.h"

#if !defined(__EMSCRIPTEN__)
#include "Native/Window.h"
#endif

#include "flecs/flecs.h"

static ecs_world_t*					gWorld;

static WorldBoundsComponent			gWorldBounds;

static void Game_MoveEntity(ecs_iter_t* it)
{
    PositionComponent* positionComponent = ecs_term(it, PositionComponent, 1);
    MoveComponent* moveComponent = ecs_term(it, MoveComponent, 2);

	float deltaTime = it->delta_time;
	WorldBoundsComponent bounds = gWorldBounds;

	vec2 velocity = moveComponent->velocity;
	vec2 position = vec2_add(positionComponent->position, vec2_mul1(velocity, deltaTime));

	if (position.x < bounds.xMin) { velocity.x =  float_abs(velocity.x); position.x = bounds.xMin; }
	if (position.x > bounds.xMax) { velocity.x = -float_abs(velocity.x); position.x = bounds.xMax; }
	if (position.y < bounds.yMin) { velocity.y =  float_abs(velocity.y); position.y = bounds.yMin; }
	if (position.y > bounds.yMax) { velocity.y = -float_abs(velocity.y); position.y = bounds.yMax; }

	positionComponent->position = position;
	moveComponent->velocity = velocity;
}

static void Game_FadeEntity(ecs_iter_t *it)
{
}

static void Game_DrawEntity(const PositionComponent* position, const SpriteComponent* sprite)
{
	Renderer_DrawSprite(sprite->spriteBatch, sprite->spriteIndex, position->position, 0.0f, sprite->scale, sprite->color);
}

float Random()
{
    union
    {
        int         i;
        uint32_t    u;
    } number = { rand() };

    return float_clamp(2.0f * (float)(number.u % UINT16_MAX) / (float)UINT16_MAX, 0.0f, 1.0f);
}

float RandomFloat(float min, float max)
{
    const float range = Random();
    return (max - min) * range + min;
}

void Game_OnRender(ecs_iter_t* it);
void Game_Setup(struct SpriteBatch* spriteBatch, int entityCount)
{
	srand((unsigned int)time(NULL));

    gWorld = ecs_init();

    ECS_COMPONENT(gWorld, PositionComponent);
    ECS_COMPONENT(gWorld, SpriteComponent);
    ECS_COMPONENT(gWorld, MoveComponent);
    ECS_COMPONENT(gWorld, FadeComponent);

    ECS_SYSTEM(gWorld, Game_MoveEntity, EcsOnUpdate, PositionComponent, MoveComponent);
    ECS_SYSTEM(gWorld, Game_FadeEntity, EcsOnUpdate, SpriteComponent, FadeComponent);
    ECS_SYSTEM(gWorld, Game_OnRender, EcsOnUpdate, PositionComponent, SpriteComponent);

#if defined(__EMSCRIPTEN__)
	const float worldWidth = 1280;
	const float worldHeight = 720;
#else
    const float worldWidth = Window_GetWidth();
    const float worldHeight = Window_GetHeight();
#endif
    gWorldBounds.xMin = 0;
    gWorldBounds.xMax = worldWidth;
    gWorldBounds.yMin = 0;
    gWorldBounds.yMax = worldHeight;

    for (int i = 0; i < entityCount; i++)
    {
        PositionComponent position;
        position.position = vec2_new(Random() * worldWidth, Random() * worldHeight);

        SpriteComponent sprite;
        sprite.scale = vec2_new(1.0f, 1.0f);
        sprite.color = vec3_new(1.0f, 1.0f, 1.0f);
        sprite.spriteIndex = (uint32_t)rand() % spriteBatch->spritesCount;
        sprite.spriteBatch = spriteBatch;

        MoveComponent move;
        move.velocity = vec2_new(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f));
        
        FadeComponent fade;
        fade.alpha = Random();

        ecs_entity_t e = ecs_new_id(gWorld);
        ecs_set(gWorld, e, PositionComponent, { vec2_new(Random() * worldWidth, Random() * worldHeight) });
        ecs_set(gWorld, e, SpriteComponent, {
            .scale = vec2_new(1.0f, 1.0f),
            .color = vec3_new(1.0f, 1.0f, 1.0f),
            .spriteIndex = (uint32_t)rand() % spriteBatch->spritesCount,
            .spriteBatch = spriteBatch,
        });
        ecs_set(gWorld, e, MoveComponent, {
            vec2_new(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f))
        });
        ecs_set(gWorld, e, FadeComponent, {
            .alpha = Random()
        });
    }
}

void Game_Shutdown()
{
    ecs_fini(gWorld);
}

void Game_Update(float time, float deltaTime)
{
	ecs_progress(gWorld, deltaTime);
}

void Game_Render()
{
    //ecs_query_t* query = ecs_query_new(gWorld, "PositionComponent, SpriteComponent");
    //
    //ecs_iter_t it = ecs_query_iter(gWorld, query);
    //while (ecs_query_next(&it))
    //{
    //    const PositionComponent* position = ecs_term(&it, PositionComponent, 1);
    //    const SpriteComponent* sprite = ecs_term(&it, SpriteComponent, 2);
    //    Game_DrawEntity(position, sprite);
    //}
}

void Game_OnRender(ecs_iter_t* it)
{
    const PositionComponent* position = ecs_term(it, PositionComponent, 1);
    const SpriteComponent* sprite = ecs_term(it, SpriteComponent, 2);
    Game_DrawEntity(position, sprite);
}
