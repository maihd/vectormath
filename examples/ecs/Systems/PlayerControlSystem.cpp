#include "PlayerControlSystem.hpp"

#include "Components/Player.hpp"
#include "Components/Thrust.hpp"
#include "Components/Transform.hpp"
#include "Core/Coordinator.hpp"

#include <vectormath.h>

extern Coordinator gCoordinator;


void PlayerControlSystem::Init()
{
	gCoordinator.AddEventListener(METHOD_LISTENER(Events::Window::INPUT, PlayerControlSystem::InputListener));
}

void PlayerControlSystem::Update(float dt)
{
	//for (int i = 0; i < entities.count; i++)
	//{
	//	Entity entity = entities[i];
	//	auto& transform = gCoordinator.Get<Transform>(entity);


	//	if (mButtons.test(static_cast<std::size_t>(InputButtons::W)))
	//	{
	//		transform.position.z += (dt * 10.0f);
	//	}

	//	else if (mButtons.test(static_cast<std::size_t>(InputButtons::S)))
	//	{
	//		transform.position.z -= (dt * 10.0f);
	//	}


	//	if (mButtons.test(static_cast<std::size_t>(InputButtons::Q)))
	//	{
	//		transform.position.y += (dt * 10.0f);
	//	}

	//	else if (mButtons.test(static_cast<std::size_t>(InputButtons::E)))
	//	{
	//		transform.position.y -= (dt * 10.0f);
	//	}


	//	if (mButtons.test(static_cast<std::size_t>(InputButtons::A)))
	//	{
	//		transform.position.x += (dt * 10.0f);
	//	}

	//	else if (mButtons.test(static_cast<std::size_t>(InputButtons::D)))
	//	{
	//		transform.position.x -= (dt * 10.0f);
	//	}
	//}
}

void PlayerControlSystem::InputListener(Event& event)
{
	mButtons = *event.GetParam<std::bitset<8>>(Events::Window::Input::INPUT);
}
