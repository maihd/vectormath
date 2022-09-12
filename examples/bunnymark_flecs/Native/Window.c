#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "Window.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// Allow compilation with old Windows SDK. MinGW doesn't have default _WIN32_WINNT/WINVER versions.
#ifndef WM_MOUSEHWHEEL
#define WM_MOUSEHWHEEL 0x020E
#endif

#ifndef DBT_DEVNODES_CHANGED
#define DBT_DEVNODES_CHANGED 0x0007
#endif

// Linking system32 libraries
//#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "GDI32.lib")

static const char* WINDOW_CLASS = "Game Window Class";
static const char* DUMMY_WINDOW = "Game Dummy Window";

static bool             sRegistered = false;
static WNDCLASSEXA      sWindowClass;

static WindowDesc*      gMainWindow;

#if 0
static KeyCode s_keyCodeMap[2048] = {};
static bool LoadKeyCodeMap()
{
    KeyCode* map = (KeyCode*)s_keyCodeMap;

    map[VK_SPACE] = KeyCode::Space;
    map[VK_BACK] = KeyCode::Backspace;
    map[VK_RETURN] = KeyCode::Return;
    map[VK_TAB] = KeyCode::Tab;

    map[VK_UP] = KeyCode::UpArrow;
    map[VK_DOWN] = KeyCode::DownArrow;
    map[VK_LEFT] = KeyCode::LeftArrow;
    map[VK_RIGHT] = KeyCode::RightArrow;

    map[VK_HOME] = KeyCode::Home;
    map[VK_END] = KeyCode::End;
    map[VK_PRIOR] = KeyCode::PageUp;
    map[VK_NEXT] = KeyCode::PageDown;
    map[VK_INSERT] = KeyCode::Insert;
    map[VK_DELETE] = KeyCode::Delete;

    map[VK_LCONTROL] = KeyCode::LeftControl;
    map[VK_RCONTROL] = KeyCode::RightControl;

    map[VK_LSHIFT] = KeyCode::LeftShift;
    map[VK_RSHIFT] = KeyCode::RightShift;

    map[VK_MULTIPLY] = KeyCode::NumpadMultiply;
    map[VK_DIVIDE] = KeyCode::NumpadDivide;
    map[VK_ADD] = KeyCode::NumpadAdd;
    map[VK_SUBTRACT] = KeyCode::NumpadSubtract;
    map[VK_NUMPAD0] = KeyCode::Numpad0;
    map[VK_NUMPAD1] = KeyCode::Numpad1;
    map[VK_NUMPAD2] = KeyCode::Numpad2;
    map[VK_NUMPAD3] = KeyCode::Numpad3;
    map[VK_NUMPAD4] = KeyCode::Numpad4;
    map[VK_NUMPAD5] = KeyCode::Numpad5;
    map[VK_NUMPAD6] = KeyCode::Numpad6;
    map[VK_NUMPAD7] = KeyCode::Numpad7;
    map[VK_NUMPAD8] = KeyCode::Numpad8;
    map[VK_NUMPAD9] = KeyCode::Numpad9;

    map[VK_OEM_PERIOD] = KeyCode::Period;
    map[VK_OEM_PLUS] = KeyCode::Plus;
    map[VK_OEM_MINUS] = KeyCode::Minus;
    map[VK_OEM_COMMA] = KeyCode::Comma;
    //s_keyCodeMap[vk_]

    map['0'] = KeyCode::Keypad0;
    map['1'] = KeyCode::Keypad1;
    map['2'] = KeyCode::Keypad2;
    map['3'] = KeyCode::Keypad3;
    map['4'] = KeyCode::Keypad4;
    map['5'] = KeyCode::Keypad5;
    map['6'] = KeyCode::Keypad6;
    map['7'] = KeyCode::Keypad7;
    map['8'] = KeyCode::Keypad8;
    map['9'] = KeyCode::Keypad9;

    map['A'] = KeyCode::A;
    map['B'] = KeyCode::B;
    map['C'] = KeyCode::C;
    map['D'] = KeyCode::D;
    map['E'] = KeyCode::E;
    map['G'] = KeyCode::G;
    map['H'] = KeyCode::H;
    map['I'] = KeyCode::I;
    map['J'] = KeyCode::J;
    map['K'] = KeyCode::K;
    map['L'] = KeyCode::L;
    map['M'] = KeyCode::M;
    map['O'] = KeyCode::O;
    map['P'] = KeyCode::P;
    map['R'] = KeyCode::R;
    map['S'] = KeyCode::S;
    map['T'] = KeyCode::T;
    map['U'] = KeyCode::U;
    map['V'] = KeyCode::V;
    map['W'] = KeyCode::W;
    map['X'] = KeyCode::X;
    map['Y'] = KeyCode::Y;
    map['Z'] = KeyCode::Z;

    map['a'] = KeyCode::A;
    map['b'] = KeyCode::B;
    map['c'] = KeyCode::C;
    map['d'] = KeyCode::D;
    map['e'] = KeyCode::E;
    map['g'] = KeyCode::G;
    map['h'] = KeyCode::H;
    map['i'] = KeyCode::I;
    map['j'] = KeyCode::J;
    map['k'] = KeyCode::K;
    map['l'] = KeyCode::L;
    map['m'] = KeyCode::M;
    map['o'] = KeyCode::O;
    map['p'] = KeyCode::P;
    map['r'] = KeyCode::R;
    map['s'] = KeyCode::S;
    map['t'] = KeyCode::T;
    map['u'] = KeyCode::U;
    map['v'] = KeyCode::V;
    map['w'] = KeyCode::W;
    map['x'] = KeyCode::X;
    map['y'] = KeyCode::Y;
    map['z'] = KeyCode::Z;

    //map[','] = KeyCode::Comma;
    //map[':'] = KeyCode::Colon;
    map[';'] = KeyCode::SemiColon;
    //map['*'] = KeyCode::Aterisk;
    //map['&'] = KeyCode::Ampersand;
    map['`'] = KeyCode::BackQuote;
    //map['~'] = KeyCode::Tilde;
    //map['%'] = KeyCode::Percent;
    //map['$'] = KeyCode::Dolla;
    //map['#'] = KeyCode::Hash;
    //map['@'] = KeyCode::At;
    //map['!'] = KeyCode::Exclaim;
    //map['?'] = KeyCode::Question;
    //map['^'] = KeyCode::Caret;
    //map['<'] = KeyCode::Less;
    //map['='] = KeyCode::Equal;
    //map['>'] = KeyCode::Greater;

    map['('] = KeyCode::LeftParen;
    map[')'] = KeyCode::RightParen;
    map['['] = KeyCode::LeftBracket;
    map[']'] = KeyCode::RightBracket;
    map['{'] = KeyCode::LeftCurlyBracket;
    map['}'] = KeyCode::RightCurlyBracket;

    //map['\''] = KeyCode::Quote;
    //map['\"'] = KeyCode::DoubleQuote;

    map['\/'] = KeyCode::Slash;
    map['\\'] = KeyCode::BackSlash;

    return true;
}
static bool s_loaded = LoadKeyCodeMap();

static inline KeyCode ConvertKeyCode(int nativeKey)
{
    return s_keyCodeMap[nativeKey];
}
#endif

static LRESULT CALLBACK Window_Proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    // Donot handle event from other window
    if (!gMainWindow || hwnd != (HWND)gMainWindow->handle)
    {
        return DefWindowProcA(hwnd, msg, wparam, lparam);;
    }

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
        //Input::UpdateKey(ConvertKeyCode((int)wparam), false);
        return 0;

    case WM_KEYDOWN:
        //Input::UpdateKey(ConvertKeyCode((int)wparam), true);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CHAR:
    case WM_UNICHAR:
        //Input::UpdateCharInput((int)wparam);
        return 0;

    case WM_QUIT:
        return 0;

    case WM_SIZE:
        //Graphics::Viewport(0, 0, Window::GetWidth(), Window::GetHeight());
        return 0;
    }

    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

static bool Window_RegisterWindowClass(void)
{
    if (!sRegistered)
    {
        memset(&sWindowClass, 0, sizeof(sWindowClass));
        
        sWindowClass.cbSize           = sizeof(sWindowClass);
        sWindowClass.style            = 0;
        sWindowClass.cbClsExtra       = 0;
        sWindowClass.cbWndExtra       = 0;
        sWindowClass.lpfnWndProc      = Window_Proc;
        sWindowClass.hInstance        = (HINSTANCE)GetModuleHandleA(NULL);;
        sWindowClass.hbrBackground    = (HBRUSH)(COLOR_WINDOW + 1);
        sWindowClass.hIcon            = LoadIcon(NULL, IDI_APPLICATION);
        sWindowClass.hIconSm          = LoadIcon(NULL, IDI_APPLICATION);
        sWindowClass.hCursor          = LoadCursor(NULL, IDC_ARROW);
        sWindowClass.lpszMenuName     = NULL;
        sWindowClass.lpszClassName    = WINDOW_CLASS;
        
        sRegistered = RegisterClassExA(&sWindowClass) != 0;
        
        if (!sRegistered)
        {
            DWORD errorMessageId = GetLastError();
            if (errorMessageId == ERROR_CLASS_ALREADY_EXISTS)
            {
                //AlertDialog::Show("NeonShooter", "Failed to register window");
            }
            else
            {
            }
        }
    }

    return sRegistered;
}

// static void Window_UnregisterWindowClass(void)
// {
//     HINSTANCE hInstance = (HINSTANCE)GetModuleHandleA(NULL);
//     UnregisterClassA(WINDOW_CLASS, hInstance);
//     sRegistered = false;
// }

bool Window_Open(WindowDesc* window)
{
    if (!Window_RegisterWindowClass())
    {
        return false;
    }
    
    WindowFlags flags = window->flags;
    DWORD nativeFlags = WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
    if (flags & WindowFlags_Visible)
    {
        nativeFlags |= WS_VISIBLE;
    }
    if (flags & WindowFlags_Resizable)
    {
        nativeFlags |= WS_OVERLAPPEDWINDOW;
    }

    HWND hwnd = CreateWindowExA(
        0,
        WINDOW_CLASS,
        window->title,
        nativeFlags,
        -1, -1, window->width, window->height,
        NULL, NULL, GetModuleHandleA(NULL), window);
    if (!hwnd)
    {
        return false;
    }

    gMainWindow = window;

    window->handle = (uintptr_t)hwnd;
    window->device = (uintptr_t)GetDC(hwnd);

    switch (flags & (WindowFlags_Borderless | WindowFlags_Fullscreen))
    {
    case WindowFlags_Borderless:
    case WindowFlags_Borderless | WindowFlags_Fullscreen:
        Window_SetBorderless();
        break;

    case WindowFlags_Fullscreen:
        Window_SetFullscreen();
        break;
    }

    Window_SetCenter();
    return true;
}

void Window_Close(WindowDesc* window)
{
    assert(window != NULL);
    assert(gMainWindow == window);

    // Destroyed native handle
    ReleaseDC((HWND)window->handle, (HDC)window->device);
    DestroyWindow((HWND)window->handle);

    // Handle quit message
    Window_PollEvents();

    // Reset window state
    window->handle = 0;
    window->device = 0;

    gMainWindow = NULL;
}

bool Window_PollEvents(void)
{
    bool quit = false;

    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);

        if (msg.message == WM_QUIT || msg.message == WM_DESTROY)
        {
            quit = true;
        }
    }

    return !quit;
}

bool Window_WaitAndPollEvents(void)
{
    MSG msg;
    if (GetMessage(&msg, NULL, 0, 0))
    {
        if (msg.message == WM_QUIT)
        {
            return false;
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                return false;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        }
    }

    return true;
}

float Window_GetWidth(void)
{
    RECT rect;
    GetClientRect((HWND)gMainWindow->handle, &rect);
    return (float)(rect.right - rect.left);
}

float Window_GetHeight(void)
{
    RECT rect;
    GetClientRect((HWND)gMainWindow->handle, &rect);
    return (float)(rect.bottom - rect.top);
}

void Window_SetBorderless(void)
{
    if (gMainWindow)
    {
        LONG_PTR styles = WS_VISIBLE;
        int      width = GetSystemMetrics(SM_CXSCREEN);
        int      height = GetSystemMetrics(SM_CYSCREEN);

        SetWindowLongPtr((HWND)gMainWindow->handle, GWL_STYLE, styles);
        SetWindowPos((HWND)gMainWindow->handle, HWND_TOP, 0, 0, width, height, 0);
    }
}

void Window_SetFullscreen(void)
{
    if (gMainWindow)
    {
        LONG_PTR styles = WS_POPUP | WS_VISIBLE;
        int      width = GetSystemMetrics(SM_CXSCREEN);
        int      height = GetSystemMetrics(SM_CYSCREEN);

        SetWindowLongPtr((HWND)gMainWindow->handle, GWL_STYLE, styles);
        SetWindowLongPtr((HWND)gMainWindow->handle, GWL_EXSTYLE, WS_EX_APPWINDOW | WS_EX_TOPMOST);
        SetWindowPos((HWND)gMainWindow->handle, HWND_TOPMOST, 0, 0, width, height, 0);
    }
}

bool Window_IsBorderless(void)
{
    return gMainWindow && (gMainWindow->flags & WindowFlags_Borderless);
}

bool Window_IsFullscreen(void)
{
    return gMainWindow && (gMainWindow->flags & WindowFlags_Fullscreen);
}

bool Window_IsWindowed(void)
{
    return !Window_IsBorderless() || !Window_IsFullscreen();
}

void Window_SetWindowed(void)
{
    if (gMainWindow)
    {
        RECT clientRect;
        RECT windowRect;
        GetClientRect((HWND)gMainWindow->handle, &clientRect);
        GetWindowRect((HWND)gMainWindow->handle, &windowRect);

        int moreWidth = (int)((windowRect.right - windowRect.left) - (clientRect.right - clientRect.left));
        int moreHeight = (int)((windowRect.bottom - windowRect.top) - (clientRect.bottom - clientRect.top));

        int width  = gMainWindow->width + moreWidth;
        int height = gMainWindow->height + moreHeight;

        int x, y;
        DWORD flags = 0;
        if (!Window_IsWindowed())
        {
            x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
            y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
            flags = SWP_NOZORDER;
        }
        else
        {
            x = 0;
            y = 0;
            flags = SWP_NOMOVE | SWP_NOZORDER;
        }

        LONG_PTR styles = WS_VISIBLE | WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME;
        SetWindowLongPtr((HWND)gMainWindow->handle, GWL_STYLE, styles);
        SetWindowPos((HWND)gMainWindow->handle, HWND_TOP, x, y, width, height, flags);
    }
}

bool Window_IsVisible(void)
{
    return IsWindowVisible((HWND)gMainWindow->handle);
}

void Window_SetVisible(bool visible)
{
    if (gMainWindow)
    {
        ShowWindow((HWND)gMainWindow->handle, visible);
    }
}

void Window_SetCenter(void)
{
    if (gMainWindow && Window_IsWindowed())
    {
        int width = gMainWindow->width + GetSystemMetrics(SM_CXBORDER);
        int height = gMainWindow->height + GetSystemMetrics(SM_CYBORDER);

        int x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
        int y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

        SetWindowPos((HWND)gMainWindow->handle, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    }
}

void Window_EnableVSync(void)
{
    Window_SetVSyncEnabled(true);
}

void Window_DisableVSync(void)
{
    Window_SetVSyncEnabled(false);
}

bool Window_IsVSyncEnabled(void)
{
    //if (wglGetSwapIntervalEXT)
    {
        //return wglGetSwapIntervalEXT() != 0;
    }
    //else
    {
        //return false;
    }

    return false;
}

void Window_SetVSyncEnabled(bool vsync)
{
    //if (wglSwapIntervalEXT)
    {
        //wglSwapIntervalEXT((int)vsync);
    }
}

bool Window_HasInputFocus(void)
{
    return (gMainWindow && GetActiveWindow() == (HWND)gMainWindow->handle);
}

bool Window_HasMouseFocus(void)
{
    if (Window_HasInputFocus())
    {
        RECT r;
        POINT p;
        GetCursorPos(&p);
        GetWindowRect((HWND)gMainWindow->handle, &r);

        if (!(p.x < r.left || p.y < r.top || p.x > r.right || p.y > r.bottom))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

const WindowDesc* Window_GetMainWindow(void)
{
    return gMainWindow;
}

void Window_MessageBox(const char* title, const char* message)
{
	MessageBoxA((HWND)gMainWindow->handle, message, title, MB_OK);
}
