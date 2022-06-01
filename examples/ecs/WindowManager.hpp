#pragma once

#include <bitset>
#include <string>

class WindowManager
{
public:
	void Init(
		std::string const& windowTitle, unsigned int windowWidth, unsigned int windowHeight,
		unsigned int windowPositionX, unsigned int windowPositionY);

	void Update();

	void ProcessEvents();

	void Shutdown();

private:
	void*			mDisplay;
	void*			mWindow;
	void*			mGLContext;

	std::bitset<8>	mButtons;
};
