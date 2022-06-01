#include "RenderSystem.hpp"

#include "Components/Camera.hpp"
#include "Components/Renderable.hpp"
#include "Components/Transform.hpp"
#include "Core/Coordinator.hpp"
#include "Graphics/Shader.hpp"

#include <math.h>
#include <vectormath.h>


extern Coordinator gCoordinator;


void RenderSystem::Init()
{
	gCoordinator.AddEventListener(METHOD_LISTENER(Events::Window::RESIZED, RenderSystem::WindowSizeListener));

	shader = std::make_unique<Shader>("../../examples/Shaders/vertex.glsl", "../../examples/Shaders/fragment.glsl");

	mCamera = gCoordinator.CreateEntity();
	Transform mCameraTransform = { vec3(0.0f, 0.0f, 500.0f) };

	gCoordinator.AddComponent(mCamera, mCameraTransform);

	gCoordinator.AddComponent(
		mCamera,
		Camera{
			//Camera::MakeProjectionTransform(45.0f, 0.1f, 1000.0f, 1920.0f, 1080.0f)
			//mat4Perspective(radians(45.0f), 1920.0f / 1080.0f, 0.1f, 1000.0f)
			mat4Ortho(-192.0f, 192.0f, -108.0f, 108.0f, -1000.0f, 1000.0f)
		});


	auto& cameraTransform = gCoordinator.GetComponent<Transform>(mCamera);

	const vec3 vertices[] = {
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(0.5f, -0.5f, -0.5f),
		vec3(0.5f, 0.5f, -0.5f),
		vec3(0.5f, 0.5f, -0.5f),
		vec3(-0.5f, 0.5f, -0.5f),
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(-0.5f, -0.5f, 0.5),
		vec3(0.5f, -0.5f, 0.5),
		vec3(0.5f, 0.5f, 0.5),
		vec3(0.5f, 0.5f, 0.5),
		vec3(-0.5f, 0.5f, 0.5),
		vec3(-0.5f, -0.5f, 0.5),
		vec3(-0.5f, 0.5f, 0.5f),
		vec3(-0.5f, 0.5f, -0.5f),
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(-0.5f, -0.5f, 0.5f),
		vec3(-0.5f, 0.5f, 0.5f),
		vec3(0.5f, 0.5f, 0.5),
		vec3(0.5f, 0.5f, -0.5),
		vec3(0.5f, -0.5f, -0.5),
		vec3(0.5f, -0.5f, -0.5),
		vec3(0.5f, -0.5f, 0.5),
		vec3(0.5f, 0.5f, 0.5),
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(0.5f, -0.5f, -0.5f),
		vec3(0.5f, -0.5f, 0.5f),
		vec3(0.5f, -0.5f, 0.5f),
		vec3(-0.5f, -0.5f, 0.5f),
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(-0.5f, 0.5f, -0.5),
		vec3(0.5f, 0.5f, -0.5),
		vec3(0.5f, 0.5f, 0.5),
		vec3(0.5f, 0.5f, 0.5),
		vec3(-0.5f, 0.5f, 0.5),
		vec3(-0.5f, 0.5f, -0.5)
	};

	const vec3 normals[] = {
		vec3(0.0f, 0.0f, -1.0f),
		vec3(0.0f, 0.0f, -1.0f),
		vec3(0.0f, 0.0f, -1.0f),
		vec3(0.0f, 0.0f, -1.0f),
		vec3(0.0f, 0.0f, -1.0f),
		vec3(0.0f, 0.0f, -1.0f),
		vec3(0.0f, 0.0f, 1.0f),
		vec3(0.0f, 0.0f, 1.0f),
		vec3(0.0f, 0.0f, 1.0f),
		vec3(0.0f, 0.0f, 1.0f),
		vec3(0.0f, 0.0f, 1.0f),
		vec3(0.0f, 0.0f, 1.0f),
		vec3(-1.0f, 0.0f, 0.0f),
		vec3(-1.0f, 0.0f, 0.0f),
		vec3(-1.0f, 0.0f, 0.0f),
		vec3(-1.0f, 0.0f, 0.0f),
		vec3(-1.0f, 0.0f, 0.0f),
		vec3(-1.0f, 0.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),
		vec3(1.0f, 0.0f, 0.0f),
		vec3(0.0f, -1.0f, 0.0f),
		vec3(0.0f, -1.0f, 0.0f),
		vec3(0.0f, -1.0f, 0.0f),
		vec3(0.0f, -1.0f, 0.0f),
		vec3(0.0f, -1.0f, 0.0f),
		vec3(0.0f, -1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0f),
		vec3(0.0f, 1.0f, 0.0)
	};

	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);

	// Vertices
	glGenBuffers(1, &mVboVertices);
	glBindBuffer(GL_ARRAY_BUFFER, mVboVertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), (void*)nullptr);
	glEnableVertexAttribArray(0);

	// Surface normal
	glGenBuffers(1, &mVboNormals);
	glBindBuffer(GL_ARRAY_BUFFER, mVboNormals);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), (void*)nullptr);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}


void RenderSystem::Update(float dt)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // NOLINT (hicpp-signed-bitwise)

	shader->Activate();
	glBindVertexArray(mVao);

	auto& cameraTransform = gCoordinator.GetComponent<Transform>(mCamera);
	auto& camera = gCoordinator.GetComponent<Camera>(mCamera);

	//const mat4 view = mat4LookAt(cameraTransform.position, vec3(0.0f), vec3(0.0f, 1.0f, 0.0f));
	const mat4 view = mat4Translation(-cameraTransform.position);
	shader->SetUniform("uView", view);

	const mat4 projection = camera.projectionTransform;
	shader->SetUniform("uProjection", projection);

	for (int i = 0; i < entities.count; i++)
	{
		Entity entity = entities[i];

		const Transform& transform = gCoordinator.GetComponent<Transform>(entity);
		const Renderable& renderable = gCoordinator.GetComponent<Renderable>(entity);

		const mat4 rotX = mat4RotationX(transform.rotation.x);
		const mat4 rotY = mat4RotationY(transform.rotation.y);
		const mat4 rotZ = mat4RotationZ(transform.rotation.z);

		const mat4 translate = mat4Translation(transform.position);
		const mat4 scaleMat = mat4Scalation(transform.scale);

		const mat4 model = mul(mul(translate, rotY), scaleMat);

		shader->SetUniform("uModel", model);
		shader->SetUniform("uColor", renderable.color);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	glBindVertexArray(0);
}

void RenderSystem::WindowSizeListener(Event& event)
{
	auto windowWidth = *event.GetParam<unsigned int>(Events::Window::Resized::WIDTH);
	auto windowHeight = *event.GetParam<unsigned int>(Events::Window::Resized::HEIGHT);

	auto& camera = gCoordinator.GetComponent<Camera>(mCamera);
	camera.projectionTransform =
		mat4Perspective(radians(45.0f), (float)windowWidth / windowHeight, 0.1f, 1000.0f);
}

