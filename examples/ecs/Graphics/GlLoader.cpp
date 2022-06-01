#include "GlLoader.hpp"

#pragma comment(lib, "OpenGL32.lib")

void LoadGlFunctions()
{
	glewInit();
}
