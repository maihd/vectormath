#pragma once

#include "Types.hpp"
#include <unordered_map>

struct Event
{
	EventId								mType;
	std::unordered_map<EventId, void*>	mData;

	Event() = delete;

	explicit Event(EventId type)
		: mType(type)
	{}

	~Event()
	{
		for (auto pair : mData)
		{
			delete pair.second;
		}
	}

	void SetParam(EventId id, void* value)
	{
		mData[id] = value;
	}

	template<typename T>
	void SetParam(EventId id, const T& value)
	{
		mData[id] = new T(value);
	}

	template<typename T>
	T* GetParam(EventId id)
	{
		return (T*)(mData[id]);
	}

	EventId GetType() const
	{
		return mType;
	}
};
