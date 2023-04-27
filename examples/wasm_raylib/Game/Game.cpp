#include <time.h>
#include <float.h>
#include <memory.h>
#include <stdlib.h>
#include <raylib.h>
#include <vectormath.h>

#include "Game/Game.h"
#include "Game/Components.h"

#include "Renderer/Renderer.h"

#include "flecs/flecs.h"

static flecs::world					gWorld;

static WorldBoundsComponent			gWorldBounds;

static void Game_MoveEntity(PositionComponent& positionComponent, MoveComponent& moveComponent)
{
	float deltaTime = gWorld.delta_time();
	WorldBoundsComponent bounds = gWorldBounds;

	vec2 velocity = moveComponent.velocity;
	vec2 position = positionComponent.position + velocity * deltaTime;

	if (position.x < bounds.xMin) { velocity.x =  float_abs(velocity.x); position.x = bounds.xMin; }
	if (position.x > bounds.xMax) { velocity.x = -float_abs(velocity.x); position.x = bounds.xMax; }
	if (position.y < bounds.yMin) { velocity.y =  float_abs(velocity.y); position.y = bounds.yMin; }
	if (position.y > bounds.yMax) { velocity.y = -float_abs(velocity.y); position.y = bounds.yMax; }

	positionComponent.position = position;
	moveComponent.velocity = velocity;
}

static void Game_FadeEntity(SpriteComponent& sprite, FadeComponent& fade)
{
}

static void Game_DrawEntity(const PositionComponent& position, const SpriteComponent& sprite)
{
	Renderer_DrawSprite(sprite.spriteBatch, sprite.spriteIndex, position.position, 0.0f, sprite.scale, sprite.color);
	// Renderer_DrawQuad(position.position, position.position + vec2_new(10.0f, 10.0f) * sprite.scale, sprite.color);
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

void Game_Setup(struct SpriteBatch* spriteBatch, int entityCount)
{
	srand((unsigned int)time(nullptr));

	gWorld.add<PositionComponent>();
	gWorld.add<SpriteComponent>();
	gWorld.add<MoveComponent>();

	gWorld.system<PositionComponent, MoveComponent>()
		.each(Game_MoveEntity);

	gWorld.system<SpriteComponent, FadeComponent>()
		.each(Game_FadeEntity);

    const float worldWidth = (float)GetScreenWidth();
    const float worldHeight = (float)GetScreenHeight();

    gWorldBounds.xMin = 0;
    gWorldBounds.xMax = worldWidth;
    gWorldBounds.yMin = 0;
    gWorldBounds.yMax = worldHeight;

    for (int i = 0; i < entityCount; i++)
    {
		gWorld.entity().set([=](PositionComponent& position, SpriteComponent& sprite, MoveComponent& move, FadeComponent& fade){
			position.position = vec2_new(Random() * worldWidth, Random() * worldHeight);

			sprite.scale = vec2_new(1.0f, 1.0f);
			sprite.color = vec3_new(1.0f, 1.0f, 1.0f);
			sprite.spriteIndex = (uint32_t)(rand() % spriteBatch->spritesCount);
			sprite.spriteBatch = spriteBatch;

			move.velocity = vec2_new(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f));
			fade.alpha = Random();
		});
    }
}

void Game_Shutdown()
{
}

void Game_Update(float time, float deltaTime)
{
	gWorld.progress(deltaTime);
}

void Game_Render()
{
	auto query = gWorld.query_builder<const PositionComponent, const SpriteComponent>().build();
	query.each(Game_DrawEntity);
}
