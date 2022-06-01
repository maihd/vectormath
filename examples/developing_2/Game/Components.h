#pragma once

#include <VectorTypes.h>

typedef struct PositionComponent
{
    vec2                    position;
} PositionComponent;

typedef struct SpriteComponent
{
    vec3                    color;
    vec2                    scale;
    const struct Sprite*    sprite;
} SpriteComponent;

typedef struct MoveComponent
{
    vec2                    velocity;
    PositionComponent*      position;
} MoveComponent;

typedef struct WorldBoundsComponent
{
    float                   xMin;
    float                   xMax;
    float                   yMin;
    float                   yMax;
} WorldBoundsComponent;
