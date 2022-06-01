#pragma once

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "EventManager.hpp"
#include "SystemManager.hpp"
#include "Types.hpp"
#include <memory>

struct Coordinator
{
	ComponentManager	mComponentManager;
	EntityManager		mEntityManager;
	EventManager		mEventManager;
	SystemManager		mSystemManager;

	inline void Init()
	{
		mComponentManager.Init();
		mEntityManager.Init();
		mEventManager.Init();
		mSystemManager.Init();
	}

	inline void Shutdown()
	{
		mComponentManager.Shutdown();
		mEntityManager.Shutdown();
		mEventManager.Shutdown();
		mSystemManager.Shutdown();
	}

	// Entity methods
	inline Entity CreateEntity()
	{
		return mEntityManager.CreateEntity();
	}

	inline void DestroyEntity(Entity entity)
	{
		mEntityManager.DestroyEntity(entity);

		mComponentManager.EntityDestroyed(entity);

		mSystemManager.EntityDestroyed(entity);
	}

	// Component methods
	template<typename T>
	inline void RegisterComponent()
	{
		mComponentManager.RegisterComponent<T>();
	}

	template<typename T>
	inline void AddComponent(Entity entity, const T& component)
	{
		mComponentManager.AddComponent<T>(entity, component);

		auto signature = mEntityManager.GetSignature(entity);
		signature.Set(mComponentManager.GetComponentType<T>(), true);
		mEntityManager.SetSignature(entity, signature);

		mSystemManager.EntitySignatureChanged(entity, signature);
	}

	template<typename T>
	inline void RemoveComponent(Entity entity)
	{
		mComponentManager.RemoveComponent<T>(entity);

		auto signature = mEntityManager.GetSignature(entity);
		signature.Set(mComponentManager.GetComponentType<T>(), false);
		mEntityManager.SetSignature(entity, signature);

		mSystemManager.EntitySignatureChanged(entity, signature);
	}

	template<typename T>
	inline T& GetComponent(Entity entity)
	{
		return mComponentManager.GetComponent<T>(entity);
	}

	template<typename T>
	inline ComponentType GetComponentType()
	{
		return mComponentManager.GetComponentType<T>();
	}

	// System methods
	template<typename T>
	inline T* RegisterSystem()
	{
		return mSystemManager.RegisterSystem<T>();
	}

	template<typename T>
	inline void SetSystemSignature(Signature signature)
	{
		mSystemManager.SetSignature<T>(signature);
	}

	// Event methods
	inline void AddEventListener(EventId eventId, std::function<void(Event&)> const& listener)
	{
		mEventManager.AddListener(eventId, listener);
	}

	inline void SendEvent(Event& event)
	{
		mEventManager.SendEvent(event);
	}

	inline void SendEvent(EventId eventId)
	{
		mEventManager.SendEvent(eventId);
	}
};
