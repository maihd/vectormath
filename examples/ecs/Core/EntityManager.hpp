#pragma once

#include <assert.h>

#include "Types.hpp"
#include "Container/Array.h"

struct EntityManager
{
	uint32_t		mEntityMark;
	uint32_t		mLivingEntityCount;

	Array<uint32_t> mAvailableEntities;
	Signature		mSignatures[MAX_ENTITIES];

	void Init()
	{
		mEntityMark			= 0;
		mLivingEntityCount	= 0;
	}

	void Shutdown()
	{
		mAvailableEntities.CleanUp();
	}

	Entity CreateEntity()
	{
		assert(mLivingEntityCount < MAX_ENTITIES && "Too many entities in existence.");

		Entity entity;
		if (mAvailableEntities.count > 0)
		{
			entity = mAvailableEntities.Pop();
		}
		else
		{
			entity = mEntityMark++;
		}

		mSignatures[entity].Reset();
		++mLivingEntityCount;

		return entity;
	}

	void DestroyEntity(Entity entity)
	{
		assert(entity < MAX_ENTITIES && "Entity out of range.");

		mAvailableEntities.Push(entity);
		--mLivingEntityCount;
	}

	void SetSignature(Entity entity, Signature signature)
	{
		assert(entity < MAX_ENTITIES && "Entity out of range.");

		mSignatures[entity] = signature;
	}

	Signature GetSignature(Entity entity)
	{
		assert(entity < MAX_ENTITIES && "Entity out of range.");

		return mSignatures[entity];
	}
};
