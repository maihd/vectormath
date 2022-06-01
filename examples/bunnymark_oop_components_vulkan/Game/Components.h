#pragma once

#include <VectorTypes.h>
#include "GameObject.h"

struct WorldBoundsComponent;

struct PositionComponent : public Component
{
    vec2                    position;
};

struct SpriteComponent : public Component
{
    vec3                    color;
    vec2                    scale;

    const struct Sprite*    sprite;
};

struct MoveComponent : public Component
{
    vec2                    velocity;
    WorldBoundsComponent*   bounds;

    virtual void            Start() override;
    virtual void            Update(float time, float deltaTime) override;
};

struct WorldBoundsComponent : public Component
{
    float                   xMin;
    float                   xMax;
    float                   yMin;
    float                   yMax;
};
