#pragma once

#include "Event.hpp"
#include "Types.hpp"
#include <functional>
#include <list>
#include <unordered_map>

struct EventManager
{
	std::unordered_map<EventId, std::list<std::function<void(Event&)>>> listeners;

	void Init()
	{

	}

	void Shutdown()
	{

	}

	void AddListener(EventId eventId, std::function<void(Event&)> const& listener)
	{
		listeners[eventId].push_back(listener);
	}

	void SendEvent(Event& event)
	{
		uint32_t type = event.GetType();

		for (auto const& listener : listeners[type])
		{
			listener(event);
		}
	}

	void SendEvent(EventId eventId)
	{
		Event event(eventId);

		for (auto const& listener : listeners[eventId])
		{
			listener(event);
		}
	}
};
