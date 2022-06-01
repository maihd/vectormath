#include <time.h>
#include <float.h>
#include <stdlib.h>
#include <VectorMath.h>

#include "Game/GameObject.h"
#include "Game/Components.h"

#include "Native/Window.h"
#include "Renderer/Renderer.h"

Array<GameObject*>      gGameObjects;
SpriteBatch             gSpriteBatch;

static GameObject* Game_NewObject(const char* name)
{
    GameObject* object = new GameObject(name);
    gGameObjects.Push(object);
    return object;
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

    GameObject* boundsObject = Game_NewObject("WorldBounds");
    WorldBoundsComponent* bounds = boundsObject->AddComponent<WorldBoundsComponent>();
    bounds->xMin = 0;
    bounds->xMax = worldWidth;
    bounds->yMin = 0;
    bounds->yMax = worldHeight;

    SpriteBatch_Init(&gSpriteBatch, spriteSheet, objectCount * 6);

    for (int i = 0; i < objectCount; i++)
    {
        GameObject* go = Game_NewObject("Sprite");
        
        PositionComponent* position = go->AddComponent<PositionComponent>();
        position->position = vec2(Random() * worldWidth, Random() * worldHeight);

        SpriteComponent* sprite = go->AddComponent<SpriteComponent>();
        sprite->scale = vec2(1.0f, 1.0f);
        sprite->color = vec3(1.0f, 1.0f, 1.0f);
//sprite->color = vec3(Random(), Random(), Random());
        sprite->sprite = &spriteSheet->sprites[(uint32_t)rand() % spriteSheet->spritesCount];

        MoveComponent* move = go->AddComponent<MoveComponent>();
        move->velocity = vec2(RandomFloat(-worldWidth * 0.5f, worldWidth * 0.5f), RandomFloat(-worldHeight * 0.5f, worldHeight * 0.5f));
    }

    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        gGameObjects[i]->Start();
    }
}

void Game_Shutdown()
{
    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        delete gGameObjects[i];
    }

    gGameObjects.CleanUp();

    SpriteBatch_CleanUp(&gSpriteBatch);
}

void Game_Update(float time, float deltaTime)
{
    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        GameObject* gameObject = gGameObjects[i];
        gameObject->Update(time, deltaTime);
    }
}

void Game_Render()
{
    SpriteBatch_Begin(&gSpriteBatch);
    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        GameObject* gameObject = gGameObjects[i];
        
        PositionComponent* position = gameObject->GetComponent<PositionComponent>();
        SpriteComponent* sprite = gameObject->GetComponent<SpriteComponent>();
        if (position && sprite)
        {
            SpriteBatch_DrawSprite(&gSpriteBatch, sprite->sprite, position->position, 0.0f, sprite->scale, sprite->color);
        }
    }
    SpriteBatch_End(&gSpriteBatch);
}
