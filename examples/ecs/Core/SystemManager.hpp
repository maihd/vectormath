#pragma once

#include <assert.h>

#include "System.hpp"
#include "Types.hpp"

#include "Container/HashTable.h"

struct SystemManager
{
	HashTable<Signature>	mSignatures;
	HashTable<System*>		mSystems;

	inline void Init()
	{

	}

	inline void Shutdown()
	{
		for (int i = 0; i < mSystems.count; i++)
		{
			mSystems.values[i]->CleanUp();
			delete mSystems.values[i];
		}

		mSignatures.CleanUp();
		mSystems.CleanUp();
	}

	template<typename T>
	inline T* RegisterSystem()
	{
		const uint32_t hash = GetTypeHash<T>();

		assert(!mSystems.ContainsKey(hash) && "Registering system more than once.");

		auto system = new T();
		mSystems.SetValue(hash, system);
		return system;
	}

	template<typename T>
	void SetSignature(Signature signature)
	{
		const uint32_t hash = GetTypeHash<T>();

		assert(mSystems.ContainsKey(hash) && "System used before registered.");

		mSignatures.SetValue(hash, signature);
	}

	void EntityDestroyed(Entity entity)
	{
		for (int i = 0; i < mSystems.count; i++)
		{
			System* system = mSystems.values[i];
			system->entities.Push(entity);
		}
	}

	void EntitySignatureChanged(Entity entity, Signature entitySignature)
	{
		for (int i = 0; i < mSystems.count; i++)
		{
			int			type			= mSystems.keys[i];
			System*		system			= mSystems.values[i];
			Signature	systemSignature = mSignatures.GetValue(type);

			if ((entitySignature & systemSignature) == systemSignature)
			{
				system->entities.Push(entity);
			}
			else
			{
				system->entities.UnorderedRemove(entity);
			}
		}
	}
};
