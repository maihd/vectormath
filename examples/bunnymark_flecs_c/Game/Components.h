#pragma once

#include <vectormath/vectormath_types.h>

typedef struct PositionComponent
{
    vec2                    position;
} PositionComponent;

typedef struct SpriteComponent
{
    vec3                    color;
    vec2                    scale;

    int                     spriteIndex;
    struct SpriteBatch*     spriteBatch;
} SpriteComponent;

typedef struct MoveComponent
{
    vec2                    velocity;
} MoveComponent;

typedef struct FadeComponent
{
	float					alpha;
} FadeComponent;

typedef struct WorldBoundsComponent
{
    float                   xMin;
    float                   xMax;
    float                   yMin;
    float                   yMax;
} WorldBoundsComponent;
