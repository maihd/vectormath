#pragma once

#include "Types.hpp"
#include "Container/Array.h"

struct System
{
	Array<Entity>	entities;
	
	inline void		CleanUp()
	{
		entities.CleanUp();
	}
};
