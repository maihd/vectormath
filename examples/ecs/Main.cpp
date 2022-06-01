#include "Components/Camera.hpp"
#include "Components/Gravity.hpp"
#include "Components/Player.hpp"
#include "Components/Renderable.hpp"
#include "Components/RigidBody.hpp"
#include "Components/Thrust.hpp"
#include "Components/Transform.hpp"
#include "Core/Coordinator.hpp"
#include "Systems/CameraControlSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Systems/PlayerControlSystem.hpp"
#include "Systems/RenderSystem.hpp"
#include "WindowManager.hpp"

#include <chrono>
#include <random>
#include <thread>


Coordinator gCoordinator;

static bool quit = false;


void QuitHandler(Event& event)
{
	quit = true;
}

int main()
{
	gCoordinator.Init();


	WindowManager windowManager;
	windowManager.Init("Nexus", 1280, 720, 0, 0);

	LoadGlFunctions();


	gCoordinator.AddEventListener(FUNCTION_LISTENER(Events::Window::QUIT, QuitHandler));


	gCoordinator.RegisterComponent<Camera>();
	gCoordinator.RegisterComponent<Gravity>();
	gCoordinator.RegisterComponent<Player>();
	gCoordinator.RegisterComponent<Renderable>();
	gCoordinator.RegisterComponent<RigidBody>();
	gCoordinator.RegisterComponent<Thrust>();
	gCoordinator.RegisterComponent<Transform>();


	PhysicsSystem* physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
	{
		Signature signature;
		signature.Set(gCoordinator.GetComponentType<Gravity>());
		signature.Set(gCoordinator.GetComponentType<RigidBody>());
		signature.Set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
	}

	physicsSystem->Init();


	CameraControlSystem* cameraControlSystem = gCoordinator.RegisterSystem<CameraControlSystem>();
	{
		Signature signature;
		signature.Set(gCoordinator.GetComponentType<Camera>());
		signature.Set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<CameraControlSystem>(signature);
	}

	cameraControlSystem->Init();


	PlayerControlSystem* playerControlSystem = gCoordinator.RegisterSystem<PlayerControlSystem>();
	{
		Signature signature;
		signature.Set(gCoordinator.GetComponentType<Player>());
		signature.Set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<PlayerControlSystem>(signature);
	}

	playerControlSystem->Init();


	RenderSystem* renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
	{
		Signature signature;
		signature.Set(gCoordinator.GetComponentType<Renderable>());
		signature.Set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<RenderSystem>(signature);
	}

	renderSystem->Init();

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, PI * 2.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randColor(0.0f, 1.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

	for (int i = 0; i < MAX_ENTITIES - 2; i++)
	{
		float scale = randScale(generator);

		Entity entity = gCoordinator.CreateEntity();
		gCoordinator.AddComponent(entity, Player{});

		gCoordinator.AddComponent<Gravity>(
			entity,
			{vec3(0.0f, randGravity(generator), 0.0f)});

		gCoordinator.AddComponent(
			entity,
			RigidBody{
				vec3(0.0f, 0.0f, 0.0f),
				vec3(0.0f, 0.0f, 0.0f)
			});

		gCoordinator.AddComponent(
			entity,
			Transform{
				vec3(randPosition(generator), randPosition(generator), randPosition(generator)),
				vec3(randRotation(generator), randRotation(generator), randRotation(generator)),
				vec3(scale, scale, scale)
			});

		gCoordinator.AddComponent(
			entity,
			Renderable{
				vec3(randColor(generator), randColor(generator), randColor(generator))
			});
	}

	float dt = 0.0f;
	float interval = 1.0f / 60.0f;
	while (!quit)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		windowManager.ProcessEvents();

		playerControlSystem->Update(dt);

		cameraControlSystem->Update(dt);

		physicsSystem->Update(dt);

		renderSystem->Update(dt);

		windowManager.Update();

		auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
		if (dt < interval)
		{
			float sleep = dt - interval;
			std::this_thread::sleep_for(std::chrono::duration<float, std::chrono::seconds::period>(sleep));
			dt = interval;
		}
	}

	gCoordinator.Shutdown();
	windowManager.Shutdown();

	return 0;
}
