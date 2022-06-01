#include "Components.h"
#include <VectorMath.h>

void MoveComponent::Start()
{
    bounds = Game_FindOfType<WorldBoundsComponent>();
}

void MoveComponent::Update(float time, float deltaTime)
{
    PositionComponent* position = gameObject->GetComponent<PositionComponent>();
    position->position += velocity * deltaTime;

    if (position->position.x < bounds->xMin) { velocity.x = -velocity.x; position->position.x = bounds->xMin; } 
    if (position->position.x > bounds->xMax) { velocity.x = -velocity.x; position->position.x = bounds->xMax; } 
    if (position->position.y < bounds->yMin) { velocity.y = -velocity.y; position->position.y = bounds->yMin; } 
    if (position->position.y > bounds->yMax) { velocity.y = -velocity.y; position->position.y = bounds->yMax; }
}
