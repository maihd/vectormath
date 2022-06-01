#pragma once

#include <assert.h>

#include "Types.hpp"
#include "Container/HashTable.h"

struct IComponentArray
{
	virtual void CleanUp()						= 0;
	virtual void EntityDestroyed(Entity entity) = 0;
};

template<typename T>
struct ComponentArray : public IComponentArray
{
	int						mSize;
	T						mComponentArray[MAX_ENTITIES];

	HashTable<uint32_t>		mEntityToIndexMap;
	HashTable<Entity>		mIndexToEntityMap;

	void InsertData(Entity entity, T component)
	{
		assert(!mEntityToIndexMap.ContainsKey(entity) && "Component added to same entity more than once.");

		// Put new entry at end
		uint32_t newIndex = (uint32_t)mSize;
		mEntityToIndexMap.SetValue(entity, newIndex);
		mIndexToEntityMap.SetValue(newIndex, entity);
		mComponentArray[newIndex] = component;
		++mSize;
	}

	void RemoveData(Entity entity)
	{
		assert(mEntityToIndexMap.ContainsKey(entity) && "Removing non-existent component.");

		// Copy element at end into deleted element's place to maintain density
		uint32_t indexOfRemovedEntity = mEntityToIndexMap.GetValue(entity);
		uint32_t indexOfLastElement = mSize - 1;
		mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastElement];

		// Update map to point to moved spot
		Entity entityOfLastElement = mIndexToEntityMap.GetValue(indexOfLastElement);
		mEntityToIndexMap.SetValue(entityOfLastElement, indexOfRemovedEntity);
		mIndexToEntityMap.SetValue(indexOfRemovedEntity, entityOfLastElement);

		mEntityToIndexMap.Remove(entity);
		mIndexToEntityMap.Remove(indexOfLastElement);

		--mSize;
	}

	T& GetData(Entity entity)
	{
		assert(mEntityToIndexMap.ContainsKey(entity) && "Retrieving non-existent component.");

		return mComponentArray[mEntityToIndexMap.GetValue(entity)];
	}

	virtual void CleanUp()
	{
		mEntityToIndexMap.CleanUp();
		mIndexToEntityMap.CleanUp();
	}

	virtual void EntityDestroyed(Entity entity) override
	{
		if (mEntityToIndexMap.ContainsKey(entity))
		{
			RemoveData(entity);
		}
	}
};
