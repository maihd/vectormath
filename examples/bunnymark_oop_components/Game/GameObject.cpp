#include <time.h>
#include <float.h>
#include <stdlib.h>
#include <VectorMath.h>

#include "Game/GameObject.h"
#include "Game/Components.h"

#include "Native/Window.h"
#include "Renderer/Renderer.h"

Array<GameObject*>      gGameObjects;

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

void Game_Setup(struct SpriteBatch* spriteBatch, int objectCount)
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

    for (int i = 0; i < objectCount; i++)
    {
        GameObject* go = Game_NewObject("Sprite");
        
        PositionComponent* position = go->AddComponent<PositionComponent>();
        position->position = vec2(Random() * worldWidth, Random() * worldHeight);

        SpriteComponent* sprite = go->AddComponent<SpriteComponent>();
        sprite->scale = vec2(1.0f, 1.0f);
        sprite->color = vec3(1.0f, 1.0f, 1.0f);
//sprite->color = vec3(Random(), Random(), Random());
        sprite->spriteIndex = (uint32_t)rand() % spriteBatch->spritesCount;
        sprite->spriteBatch = spriteBatch;

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
    for (int i = 0, n = gGameObjects.count; i < n; i++)
    {
        GameObject* gameObject = gGameObjects[i];
        
        PositionComponent* position = gameObject->GetComponent<PositionComponent>();
        SpriteComponent* sprite = gameObject->GetComponent<SpriteComponent>();
        if (position && sprite)
        {
            Renderer_DrawSprite(sprite->spriteBatch, sprite->spriteIndex, position->position, 0.0f, sprite->scale, sprite->color);
        }
    }
}
