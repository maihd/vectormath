#include "WindowManager.hpp"

#include "Core/Coordinator.hpp"
#include "Graphics/GlLoader.hpp"

#include <bitset>
#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <GL/wglew.h>

extern Coordinator gCoordinator;

constexpr const char* WINDOW_CLASS = "__nexus_window__";
constexpr const char* DUMMY_WINDOW = "__dummy_window__";

static LRESULT CALLBACK Window_Proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	WindowManager* window = (WindowManager*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

	//XEvent xEvent;
	//	else if (xEvent.type == KeyRelease)
	//	{
	//		KeySym key = XkbKeycodeToKeysym(
	//			mDisplay,
	//			static_cast<KeyCode>(xEvent.xkey.keycode),
	//			0, 0);
	//
	//		bool buttonStateChanged = true;
	//
	//		if (key == XK_Escape)
	//		{
	//			gCoordinator.SendEvent(Events::Window::QUIT);
	//		}
	//
	//		else if (key == XK_w)
	//		{
	//			mButtons.reset(static_cast<std::size_t>(InputButtons::W));
	//		}
	//
	//		else if (key == XK_a)
	//		{
	//			mButtons.reset(static_cast<std::size_t>(InputButtons::A));
	//		}
	//
	//		else if (key == XK_s)
	//		{
	//			mButtons.reset(static_cast<std::size_t>(InputButtons::S));
	//		}
	//
	//		else if (key == XK_d)
	//		{
	//			mButtons.reset(static_cast<std::size_t>(InputButtons::D));
	//		}
	//		else if (key == XK_q)
	//		{
	//			mButtons.reset(static_cast<std::size_t>(InputButtons::Q));
	//		}
	//
	//		else if (key == XK_e)
	//		{
	//			mButtons.reset(static_cast<std::size_t>(InputButtons::E));
	//		}
	//		else
	//		{
	//			buttonStateChanged = false;
	//			XFlush(mDisplay);
	//		}
	//
	//		if (buttonStateChanged)
	//		{
	//			Event event(Events::Window::INPUT);
	//			event.SetParam(Events::Window::Input::INPUT, mButtons);
	//			gCoordinator.SendEvent(event);
	//		}
	//	}
	//	else
	//	{
	//		XFlush(mDisplay);
	//	}
	//}

	// Donot handle event from unknown window
	if (!window)
	{
		return ::DefWindowProcA(hwnd, msg, wparam, lparam);
	}

	// Send event base on type of message
	switch (msg)
	{
	case WM_LBUTTONUP:
		//Input::UpdateMouse(MouseButton::Left, false);
		return 0;

	case WM_LBUTTONDOWN:
		//Input::UpdateMouse(MouseButton::Left, true);
		return 0;

	case WM_RBUTTONUP:
		//Input::UpdateMouse(MouseButton::Right, false);
		return 0;

	case WM_RBUTTONDOWN:
		//Input::UpdateMouse(MouseButton::Right, true);
		return 0;

	case WM_MBUTTONUP:
		//Input::UpdateMouse(MouseButton::Middle, false);
		return 0;

	case WM_MBUTTONDOWN:
		//Input::UpdateMouse(MouseButton::Middle, true);
		return 0;

	case WM_XBUTTONUP:
		//Input::UpdateMouse(MouseButton::XButton1, false);
		return 0;

	case WM_XBUTTONDOWN:
		//Input::UpdateMouse(MouseButton::XButton1, true);
		return 0;

	case WM_MOUSEMOVE:
		//Input::UpdateMouseMove((float)GET_X_LPARAM(lparam), (float)GET_Y_LPARAM(lparam));
		return 0;

	case WM_MOUSEWHEEL:
		//Input::UpdateMouseWheel(0, (float)GET_WHEEL_DELTA_WPARAM(wparam));
		return 0;

	case WM_MOUSEHWHEEL:
		//Input::UpdateMouseWheel((float)GET_WHEEL_DELTA_WPARAM(wparam), 0);
		return 0;

	case WM_KEYUP:
	{
		//KeySym key = XkbKeycodeToKeysym(
		//			mDisplay,
		//			static_cast<KeyCode>(xEvent.xkey.keycode),
		//			0, 0);
		//
		//		bool buttonStateChanged = true;
		//
		//		if (key == XK_Escape)
		//		{
		//			gCoordinator.SendEvent(Events::Window::QUIT);
		//		}
		//
		//		else if (key == XK_w)
		//		{
		//			mButtons.set(static_cast<std::size_t>(InputButtons::W));
		//		}
		//
		//		else if (key == XK_a)
		//		{
		//			mButtons.set(static_cast<std::size_t>(InputButtons::A));
		//		}
		//
		//		else if (key == XK_s)
		//		{
		//			mButtons.set(static_cast<std::size_t>(InputButtons::S));
		//		}
		//
		//		else if (key == XK_d)
		//		{
		//			mButtons.set(static_cast<std::size_t>(InputButtons::D));
		//		}
		//
		//		else if (key == XK_q)
		//		{
		//			mButtons.set(static_cast<std::size_t>(InputButtons::Q));
		//		}
		//
		//		else if (key == XK_e)
		//		{
		//			mButtons.set(static_cast<std::size_t>(InputButtons::E));
		//		}
		//		else
		//		{
		//			buttonStateChanged = false;
		//			XFlush(mDisplay);
		//		}
		//
		//		if (buttonStateChanged)
		//		{
		//			Event event(Events::Window::INPUT);
		//			event.SetParam(Events::Window::Input::INPUT, mButtons);
		//			gCoordinator.SendEvent(event);
		//		}
		//Input::UpdateKey(ConvertKeyCode((int)wparam), false);
		return 0;
	} //! WM_KEYUP

	case WM_KEYDOWN:
		//Input::UpdateKey(ConvertKeyCode((int)wparam), true);
		return 0;

	case WM_DESTROY:
	{
		gCoordinator.SendEvent(Events::Window::QUIT);
		::PostQuitMessage(0);
		return 0;
	} //! WM_DESTROY

	case WM_CHAR:
	case WM_UNICHAR:
		
		return 0;

	case WM_QUIT:
	{
		return 0;
	} //! WM_QUIT

	case WM_SIZE:
	{
		RECT rect;
		GetClientRect(hwnd, &rect);

		int width = (rect.right - rect.left);
		int height = (rect.bottom - rect.top);

		glViewport(0, 0, width, height);
		
		Event event(Events::Window::RESIZED);
		event.SetParam(Events::Window::Resized::WIDTH, new int(width));
		event.SetParam(Events::Window::Resized::HEIGHT, new int(height));
		gCoordinator.SendEvent(event);
		return 0;
	} //! WM_SIZE
	
	// End switch (msg)
	}

	return ::DefWindowProcA(hwnd, msg, wparam, lparam);
}

static bool RegisterWindowClass(void)
{
	static bool registered = false;

	if (!registered)
	{
		WNDCLASSA wc = {};
		wc.lpfnWndProc = Window_Proc;
		wc.hInstance = ::GetModuleHandleA(nullptr);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpszClassName = WINDOW_CLASS;

		registered = ::RegisterClassA(&wc);
	}

	return registered;
}

static bool InitBaseContext(void)
{
	static bool init = false;
	if (init)
	{
		return true;
	}

	HINSTANCE hInstance = ::GetModuleHandleA(nullptr);
	HWND hwnd = ::CreateWindowA(
		WINDOW_CLASS, DUMMY_WINDOW,
		0,
		0, 0, 100, 100,
		nullptr, nullptr, hInstance, nullptr);
	if (!hwnd)
	{
		return false;
	}

	HDC hdc = GetDC(hwnd);
	if (!hdc)
	{
		return false;
	}

	int format;
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_STEREO,    // Flags
		PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
		32,                   // Color bits of the framebuffer.
		8, 0, 8, 8, 8, 16,    // Red, Green, Blue - [bits, shift]
		8, 24,                // Alpha - [bits, shift]
		32,                   // Accum bits
		8, 8, 8, 8,           // Accum channel bits: r, g, b, a
		24,                   // Number of bits for the depthbuffer
		8,                    // Number of bits for the stencilbuffer
		0,                    // Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,       // Layer type
		0,                    // Is rerversed
		0, 0, 0               // Unused
	};
	if ((format = ::ChoosePixelFormat(hdc, &pfd)) == 0)
	{
		return false;
	}

	if (!::SetPixelFormat(hdc, format, &pfd))
	{
		return false;
	}

	HGLRC context = wglCreateContext(hdc);
	if (!context)
	{
		return false;
	}
	wglMakeCurrent(hdc, context);

	glewExperimental = false;
	GLenum glewState = glewInit();
	if (glewState != GLEW_OK)
	{
		return false;
	}

	wglDeleteContext(context);
	::DestroyWindow(hwnd);

	return (init = true);
}

// TODO: Return error to caller
void WindowManager::Init(
	std::string const& windowTitle, unsigned int windowWidth, unsigned int windowHeight, unsigned int windowPositionX,
	unsigned int windowPositionY)
{
	if (!RegisterWindowClass() || !InitBaseContext())
	{
		return;
	}

	DWORD winFlags = WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	//if (flags & WindowFlag::Visible)
	//{
	//	winFlags |= WS_VISIBLE;
	//}

	//if (flags & WindowFlag::Resizable)
	//{
	//	winFlags |= WS_OVERLAPPEDWINDOW;
	//}

	HWND hwnd = CreateWindowA(
		WINDOW_CLASS,
		windowTitle.c_str(),
		winFlags,
		windowPositionX, windowPositionY, windowWidth, windowHeight,
		nullptr, nullptr, ::GetModuleHandleA(nullptr), nullptr);
	if (!hwnd)
	{
		return;
	}

	SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this);
	ShowWindow(hwnd, 1);

	mWindow = hwnd;
	mDisplay = ::GetDC(hwnd);

	// Make sure window is initialized
	HDC hdc = (HDC)mDisplay;
	if (!hdc)
	{
		return;
	}

	// Modern api require differences extension to create _context
	if (!wglewIsSupported("WGL_ARB_create_context"))
	{
		return;
	}

	int format;
	int numFormats;
	int formatAttribs[] = {
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,

		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
		//WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,

		WGL_ACCUM_RED_BITS_ARB, 8,
		WGL_ACCUM_GREEN_BITS_ARB, 8,
		WGL_ACCUM_BLUE_BITS_ARB, 8,
		WGL_ACCUM_ALPHA_BITS_ARB, 8,

		WGL_RED_BITS_ARB, 8,
		WGL_GREEN_BITS_ARB, 8,
		WGL_BLUE_BITS_ARB, 8,
		WGL_ALPHA_BITS_ARB, 8,

		WGL_RED_SHIFT_ARB, 0,
		WGL_GREEN_SHIFT_ARB, 8,
		WGL_BLUE_SHIFT_ARB, 16,
		WGL_ALPHA_SHIFT_ARB, 24,

		WGL_ACCUM_BITS_ARB, 32,
		WGL_COLOR_BITS_ARB, 32,
		WGL_DEPTH_BITS_ARB, 24,
		WGL_STENCIL_BITS_ARB, 8,

		//WGL_ARB_multisample && settings.multisamples > 1 ? WGL_SAMPLE_BUFFERS_ARB : 0, 1,
		//WGL_ARB_multisample && settings.multisamples > 1 ? WGL_SAMPLES_ARB : 0, settings.multisamples,

		0
	};
	if (!wglChoosePixelFormatARB(hdc, formatAttribs, NULL, 1, &format, (UINT*)&numFormats))
	{
		return;
	}

	if (!::SetPixelFormat(hdc, format, NULL))
	{
		return;
	}

	// We initialize wgl runtime, so wglCreateContext will do it
	HGLRC tmpContext = wglCreateContext(hdc);
	if (!tmpContext)
	{
		return;
	}
	if (!wglMakeCurrent(hdc, tmpContext))
	{
		wglDeleteContext(tmpContext);
		return;
	}

	int contextAttribs[16] =
	{
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		WGL_CONTEXT_MAJOR_VERSION_ARB, 4, // Highest current supported version
		WGL_CONTEXT_MINOR_VERSION_ARB, 5, // Highest current supported version
		WGL_CONTEXT_LAYER_PLANE_ARB, 0, // main plane
		WGL_CONTEXT_FLAGS_ARB, 0, // prevent use deprecated features
		0
	};
	HGLRC context = wglCreateContextAttribsARB(hdc, 0, contextAttribs);
	if (!context)
	{
		wglDeleteContext(tmpContext);
		return;
	}

	if (!wglMakeCurrent(hdc, context))
	{
		wglDeleteContext(tmpContext);
		wglDeleteContext(context);
		return;
	}
	mGLContext = context;

	// Delete 2.x context
	wglDeleteContext(tmpContext);

	// By default, vsync is enable
	if (wglSwapIntervalEXT)
	{
		wglSwapIntervalEXT(1);
	}

	// Set viewport
	glViewport(0, 0, windowWidth, windowHeight);
	
	// Clear buffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	this->Update();
}


void WindowManager::Update()
{
	wglMakeCurrent((HDC)mDisplay, (HGLRC)mGLContext);
	SwapBuffers((HDC)mDisplay);
}


void WindowManager::Shutdown()
{
	::wglDeleteContext((HGLRC)mGLContext);
	::DestroyWindow((HWND)mWindow);
	
	ProcessEvents();
}

void WindowManager::ProcessEvents()
{
	MSG msg;
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
