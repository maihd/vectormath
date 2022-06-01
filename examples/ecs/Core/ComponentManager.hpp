#pragma once

#include "ComponentArray.hpp"
#include "Types.hpp"

#include "Container/HashTable.h"

struct ComponentManager
{
	HashTable<ComponentType>		mComponentTypes;
	HashTable<IComponentArray*>		mComponentArrays;
	ComponentType					mNextComponentType;

	inline void Init()
	{
		mNextComponentType = 0;
	}

	inline void Shutdown()
	{
		for (int i = 0; i < mComponentArrays.count; i++)
		{
			mComponentArrays.values[i]->CleanUp();
			delete mComponentArrays.values[i];
		}
		
		mComponentArrays.CleanUp();
		mComponentTypes.CleanUp();
	}

	template<typename T>
	void RegisterComponent()
	{
		const uint32_t hash = GetTypeHash<T>();

		assert(!mComponentTypes.ContainsKey(hash) && "Registering component type more than once.");

		mComponentTypes.SetValue(hash, mNextComponentType);
		mComponentArrays.SetValue(hash, new ComponentArray<T>());

		++mNextComponentType;
	}

	template<typename T>
	ComponentType GetComponentType()
	{
		const uint32_t hash = GetTypeHash<T>();

		assert(mComponentTypes.ContainsKey(hash) && "Component not registered before use.");

		return mComponentTypes.GetValue(hash);
	}

	template<typename T>
	ComponentArray<T>* GetComponentArray()
	{
		const uint32_t hash = GetTypeHash<T>();

		assert(mComponentArrays.ContainsKey(hash) && "Component not registered before use.");

		return (ComponentArray<T>*)mComponentArrays.GetValue(hash);
	}

	template<typename T>
	void AddComponent(Entity entity, T component)
	{
		GetComponentArray<T>()->InsertData(entity, component);
	}

	template<typename T>
	void RemoveComponent(Entity entity)
	{
		GetComponentArray<T>()->RemoveData(entity);
	}

	template<typename T>
	T& GetComponent(Entity entity)
	{
		return GetComponentArray<T>()->GetData(entity);
	}

	void EntityDestroyed(Entity entity)
	{
		for (int i = 0; i < mComponentArrays.count; i++)
		{
			mComponentArrays.values[i]->EntityDestroyed(entity);
		}
	}
};
