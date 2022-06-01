#pragma once

#include "Core/System.hpp"


class PhysicsSystem : public System
{
public:
	void Init();

	void Update(float dt);
};
