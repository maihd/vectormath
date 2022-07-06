#pragma once

#include <VectorTypes.h>

struct PositionComponent
{
    vec2                    position;
};

struct SpriteComponent
{
    vec3                    color;
    vec2                    scale;
    const struct Sprite*    sprite;
};

struct MoveComponent
{
    vec2                    velocity;
    PositionComponent*      position;
};

struct WorldBoundsComponent
{
    float                   xMin;
    float                   xMax;
    float                   yMin;
    float                   yMax;
};
