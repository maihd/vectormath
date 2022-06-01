#include "OpenGL.h"

// -----------------------------------------------------
// OpenGL functions
// -----------------------------------------------------

#undef  GL_FUNC
#define GL_FUNC(NAME, RETURN_TYPE, ...) RETURN_TYPE (GL_APICALL *NAME)(##__VA_ARGS__)

GL_FUNC(glClearColor, void, float r, float g, float b, float a);
GL_FUNC(glClear, void, uint32_t mask);

GL_FUNC(glViewport, void, int x, int y, int w, int h);
GL_FUNC(glDrawArrays, void, uint32_t type, int start, int count);
GL_FUNC(glDrawElements, void, uint32_t mode, int count, uint32_t type, const void* indices);

GL_FUNC(glEnable, void, uint32_t mode);
GL_FUNC(glDisable, void, uint32_t mode);

GL_FUNC(glBlendFunc, void, uint32_t sfactor, uint32_t dfactor);
GL_FUNC(glBlendEquation, void, uint32_t equation);

GL_FUNC(glBindTexture, void, uint32_t target, uint32_t texture);
GL_FUNC(glTexParameteri, void, uint32_t target, uint32_t pname, uint32_t param);
GL_FUNC(glTexImage2D, void, uint32_t target, int level, int internalformat, int width, int height, int border, uint32_t format, uint32_t type, const void* pixels);

GL_FUNC(glGenTextures, void, int count, uint32_t* textures);
GL_FUNC(glDeleteTextures, void, int count, uint32_t* textures);
GL_FUNC(glActiveTexture, void, uint32_t textureIndex);

GL_FUNC(glCreateProgram, uint32_t);
GL_FUNC(glDeleteProgram, void, uint32_t program);
GL_FUNC(glLinkProgram, void, uint32_t program);
GL_FUNC(glUseProgram, void, uint32_t program);

GL_FUNC(glGetProgramiv, void, uint32_t program, uint32_t pname, int* param);
GL_FUNC(glGetProgramInfoLog, void, uint32_t program, int bufSize, int* length, char* infoLog);

GL_FUNC(glCreateShader, uint32_t, uint32_t type);
GL_FUNC(glDeleteShader, void, uint32_t shader);

GL_FUNC(glAttachShader, void, uint32_t program, uint32_t shader);
GL_FUNC(glDetachShader, void, uint32_t program, uint32_t shader);

GL_FUNC(glShaderSource, void, uint32_t shader, int count, const char** sources, const int* length);
GL_FUNC(glCompileShader, void, uint32_t shader);

GL_FUNC(glGetUniformLocation, int, uint32_t program, const char* name);
GL_FUNC(glUniform3f, void, int location, float x, float y, float z);
GL_FUNC(glUniformMatrix4fv, void, int location, int count, int transpose, const float* value);

GL_FUNC(glGetShaderiv, void, uint32_t shader, uint32_t pname, int* param);
GL_FUNC(glGetShaderInfoLog, void, uint32_t shader, int bufSize, int* length, char* infoLog);

GL_FUNC(glGenBuffers, void, int count, uint32_t* buffers);
GL_FUNC(glDeleteBuffers, void, int count, const uint32_t* buffers);

GL_FUNC(glBindBuffer, void, uint32_t type, uint32_t buffer);
GL_FUNC(glBufferData, void, uint32_t type, int size, const void* data, uint32_t usage);

GL_FUNC(glGenVertexArrays, void, int count, uint32_t* vertexArrays);
GL_FUNC(glDeleteVertexArrays, void, int count, const uint32_t* vertexArrays);
GL_FUNC(glBindVertexArray, void, uint32_t vertexArray);

GL_FUNC(glEnableVertexAttribArray, void, int location);
GL_FUNC(glVertexAttribPointer, void, int location, int size, uint32_t type, uint8_t normalized, int stride, const void* pointer);

// -----------------------------------------------------
// WGL and family
// -----------------------------------------------------

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

GL_FUNC(wglCreateContextAttribsARB, void*, HDC device, void* sharedContext, const int* attribs);
GL_FUNC(wglChoosePixelFormatARB, BOOL, HDC device, const int* attribs, const float* attribFloats, uint32_t maxFormats, int* formats, uint32_t* nNumFormats);

enum
{
    WGL_DRAW_TO_WINDOW_ARB = 0x2001,
    WGL_SUPPORT_OPENGL_ARB = 0x2010,
    WGL_DOUBLE_BUFFER_ARB = 0x2011,
    WGL_PIXEL_TYPE_ARB = 0x2013,
    WGL_COLOR_BITS_ARB = 0x2014,
    WGL_RED_BITS_ARB = 0x2015,
    WGL_RED_SHIFT_ARB = 0x2016,
    WGL_GREEN_BITS_ARB = 0x2017,
    WGL_GREEN_SHIFT_ARB = 0x2018,
    WGL_BLUE_BITS_ARB = 0x2019,
    WGL_BLUE_SHIFT_ARB = 0x201A,
    WGL_ALPHA_BITS_ARB = 0x201B,
    WGL_ALPHA_SHIFT_ARB = 0x201C,
    WGL_ACCUM_BITS_ARB = 0x201D,
    WGL_ACCUM_RED_BITS_ARB = 0x201E,
    WGL_ACCUM_GREEN_BITS_ARB = 0x201F,
    WGL_ACCUM_BLUE_BITS_ARB = 0x2020,
    WGL_ACCUM_ALPHA_BITS_ARB = 0x2021,
    WGL_DEPTH_BITS_ARB = 0x2022,
    WGL_STENCIL_BITS_ARB = 0x2023,

    WGL_TYPE_RGBA_ARB = 0x202B,

    WGL_ARB_multisample = 1,
    WGL_SAMPLE_BUFFERS_ARB = 0x2041,
    WGL_SAMPLES_ARB = 0x2042,

    WGL_CONTEXT_CORE_PROFILE_BIT_ARB = 0x00000001,
    WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002,
    WGL_CONTEXT_PROFILE_MASK_ARB = 0x9126,

    WGL_CONTEXT_DEBUG_BIT_ARB = 0x0001,
    WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x0002,
    WGL_CONTEXT_MAJOR_VERSION_ARB = 0x2091,
    WGL_CONTEXT_MINOR_VERSION_ARB = 0x2092,
    WGL_CONTEXT_LAYER_PLANE_ARB = 0x2093,
    WGL_CONTEXT_FLAGS_ARB = 0x2094,
};

#endif //! defined(_WIN32)

// -----------------------------------------------------
// OpenGL functions
// -----------------------------------------------------

GLLoadError glLoadFunctions()
{
    // Define GET_PROC_ADDRESS for crossplatform
    #if defined(_WIN32)
        HMODULE _OPENGL_MODULE = LoadLibraryA("OpenGL32.dll");
        if (_OPENGL_MODULE == NULL)
        {
            return GLLoadError_LoadDriverFailed;
        }
        
        #define WGL_FUNC(NAME, RETURN_TYPE, ...)                        \
            RETURN_TYPE (GL_APICALL*NAME)(##__VA_ARGS__);               \
            do {                                                        \
                void* address = GetProcAddress(_OPENGL_MODULE, #NAME);  \
                if (address == NULL)                                    \
                {                                                       \
                    return GLLoadError_FunctionNotFound;                \
                }                                                       \
                NAME = address;                                         \
            } while (0)

        WGL_FUNC(wglCreateContext, void*, HDC device);
        WGL_FUNC(wglDeleteContext, BOOL, void* context);
        WGL_FUNC(wglMakeCurrent, BOOL, HDC device, void* context);
        WGL_FUNC(wglGetProcAddress, void*, const char* name);

        #define GET_PROC_ADDRESS(NAME) wglGetProcAddress(NAME)
    #else
        #define GET_PROC_ADDRESS(NAME) glXGetProcAddress(NAME)
    #endif

    // Create dummy context to load functions
    #if defined(_WIN32)
        WNDCLASSEXA windowClass     = { 0 };
        windowClass.cbSize          = sizeof(windowClass);
        windowClass.style           = 0;
        windowClass.cbClsExtra      = 0;
        windowClass.cbWndExtra      = 0;
        windowClass.lpfnWndProc     = DefWindowProcA;
        windowClass.hInstance       = (HINSTANCE)GetModuleHandleA(NULL);;
        windowClass.hbrBackground   = (HBRUSH)(COLOR_WINDOW + 1);
        windowClass.hIcon           = LoadIcon(NULL, IDI_APPLICATION);
        windowClass.hIconSm         = LoadIcon(NULL, IDI_APPLICATION);
        windowClass.hCursor         = LoadCursor(NULL, IDC_ARROW);
        windowClass.lpszMenuName    = NULL;
        windowClass.lpszClassName   = "GLLoader Window Class";
        if (RegisterClassExA(&windowClass) == 0)
        {
            return GLLoadError_LoadDriverFailed;
        }

        HINSTANCE hInstance = GetModuleHandleA(NULL);
        HWND hwnd = CreateWindowExA(
            0,
            windowClass.lpszClassName,
            "GLLoader Dummy Window",
            WS_OVERLAPPEDWINDOW,
            0, 0, 100, 100,
            NULL, NULL, hInstance, NULL);
        if (!hwnd)
        {
            return GLLoadError_LoadDriverFailed;
        }

        HDC hdc = GetDC(hwnd);
        if (!hdc)
        {
            DestroyWindow(hwnd);
            return GLLoadError_LoadDriverFailed;
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
            0,                    // Is reserved
            0, 0, 0               // Unused
        };
        if ((format = ChoosePixelFormat(hdc, &pfd)) == 0)
        {
            ReleaseDC(hwnd, hdc);
            DestroyWindow(hwnd);
            return GLLoadError_LoadDriverFailed;
        }

        if (!SetPixelFormat(hdc, format, &pfd))
        {
            ReleaseDC(hwnd, hdc);
            DestroyWindow(hwnd);
            return GLLoadError_LoadDriverFailed;
        }

        HGLRC context = wglCreateContext(hdc);
        if (!context)
        {
            ReleaseDC(hwnd, hdc);
            DestroyWindow(hwnd);
            return GLLoadError_LoadDriverFailed;
        }
        wglMakeCurrent(hdc, context);
    #endif

    /// Load function that have same name with address name in driver
    #define LOAD_GL_FUNC(NAME)                                      \
        do {                                                        \
            void* address = GetProcAddress(_OPENGL_MODULE, #NAME);  \
            if (address == NULL)                                    \
            {                                                       \
                return GLLoadError_FunctionNotFound;                \
            }                                                       \
            NAME = address;                                         \
        } while (0)

    // Load each functions from OpenGL32.dll with GetProcAddress
    LOAD_GL_FUNC(glClearColor);
    LOAD_GL_FUNC(glClear);

    LOAD_GL_FUNC(glViewport);
    LOAD_GL_FUNC(glDrawArrays);
    LOAD_GL_FUNC(glDrawElements);

    LOAD_GL_FUNC(glEnable);
    LOAD_GL_FUNC(glDisable);

    LOAD_GL_FUNC(glBlendFunc);

    LOAD_GL_FUNC(glBindTexture);
    LOAD_GL_FUNC(glTexParameteri);
    LOAD_GL_FUNC(glTexImage2D);

    /// Load function that have same name with address name in driver
    #define LOAD_GL_FUNC(NAME, ...)                                 \
        do {                                                        \
            void* address = GET_PROC_ADDRESS(#NAME);                \
            if (address == NULL)                                    \
            {                                                       \
                return GLLoadError_FunctionNotFound;                \
            }                                                       \
            NAME = address;                                         \
        } while (0)

    LOAD_GL_FUNC(glBlendEquation);

    LOAD_GL_FUNC(glGenTextures);
    LOAD_GL_FUNC(glDeleteTextures);
    LOAD_GL_FUNC(glActiveTexture);

    LOAD_GL_FUNC(glCreateProgram, uint32_t);
    LOAD_GL_FUNC(glDeleteProgram, void, uint32_t program);
    LOAD_GL_FUNC(glLinkProgram, void, uint32_t program);
    LOAD_GL_FUNC(glUseProgram, void, uint32_t program);

    LOAD_GL_FUNC(glGetProgramiv, void, uint32_t program, uint32_t pname, int* param);
    LOAD_GL_FUNC(glGetProgramInfoLog, void, uint32_t program, int bufSize, int* length, char* infoLog);

    LOAD_GL_FUNC(glCreateShader, uint32_t, uint32_t type);
    LOAD_GL_FUNC(glDeleteShader, void, uint32_t shader);

    LOAD_GL_FUNC(glAttachShader, void, uint32_t program, uint32_t shader);
    LOAD_GL_FUNC(glDetachShader, void, uint32_t program, uint32_t shader);

    LOAD_GL_FUNC(glShaderSource, void, uint32_t shader, int count, const char** sources, const int* length);
    LOAD_GL_FUNC(glCompileShader, void, uint32_t shader);

    LOAD_GL_FUNC(glGetUniformLocation, int, const char* name);
    LOAD_GL_FUNC(glUniform3f, void, int location, float x, float y, float z);
    LOAD_GL_FUNC(glUniformMatrix4fv, void, int location, int count, int transpose, const float* value);

    LOAD_GL_FUNC(glGetShaderiv, void, uint32_t shader, uint32_t pname, int* param);
    LOAD_GL_FUNC(glGetShaderInfoLog, void, uint32_t shader, int bufSize, int* length, char* infoLog);

    LOAD_GL_FUNC(glGenBuffers, void, int count, uint32_t * buffers);
    LOAD_GL_FUNC(glDeleteBuffers, void, int count, const uint32_t * buffers);

    LOAD_GL_FUNC(glBindBuffer, void, uint32_t type, uint32_t buffer);
    LOAD_GL_FUNC(glBufferData, void, uint32_t type, const void* data, int length, uint32_t usage);

    LOAD_GL_FUNC(glGenVertexArrays, void, int count, uint32_t* vertexArrays);
    LOAD_GL_FUNC(glDeleteVertexArrays, void, int count, const uint32_t* vertexArrays);
    LOAD_GL_FUNC(glBindVertexArray, void, uint32_t vertexArray);

    LOAD_GL_FUNC(glEnableVertexAttribArray);
    LOAD_GL_FUNC(glVertexAttribPointer);

    // Load WGL functions
    #if defined(_WIN32)
        LOAD_GL_FUNC(wglCreateContextAttribsARB);
        LOAD_GL_FUNC(wglChoosePixelFormatARB);
    #endif

    // undef all, no use in other functions
    #undef GET_PROC_ADDRESS
    #undef LOAD_GL_FUNC
    #undef LOAD_GL_FUNC2

#if defined(_WIN32)
    wglDeleteContext(context);
    wglMakeCurrent(hdc, NULL);
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);
#endif

    // All success
    return GLLoadError_None;
}

// -----------------------------------------------------
// Function to create OpenGL context
// -----------------------------------------------------

#include "../Native/Window.h"

void* glCreateContext(struct WindowDesc* window)
{
    if (!wglChoosePixelFormatARB || !wglCreateContextAttribsARB)
    {
        return NULL;
    }

    HDC hdc = (HDC)window->device;

    int format;
    int numFormats;
    int formatAttribs[] = {
        WGL_DOUBLE_BUFFER_ARB, 1,
        WGL_SUPPORT_OPENGL_ARB, 1,
        WGL_DRAW_TO_WINDOW_ARB, 1,

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
        return false;
    }

    if (!SetPixelFormat(hdc, format, NULL))
    {
        return false;
    }

    const int contextAttribs[16] =
    {
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4, // Highest current supported version
        WGL_CONTEXT_MINOR_VERSION_ARB, 5, // Highest current supported version
        WGL_CONTEXT_LAYER_PLANE_ARB, 0, // main plane
        WGL_CONTEXT_FLAGS_ARB, 0, // prevent use deprecated features
        0
    };

    void* context = wglCreateContextAttribsARB(hdc, NULL, contextAttribs);
    glMakeContextCurrent(window, context);
    return context;
}

void glDeleteContext(void* context)
{
    HMODULE module = LoadLibraryA("OpenGL32.dll");
    if (module != NULL)
    {
        BOOL (GL_APICALL*wglDeleteContext)(void* context) = GetProcAddress(module, "wglDeleteContext");
        if (wglDeleteContext != NULL)
        {
            wglDeleteContext(context);
        }
    }
}

void glMakeContextCurrent(struct WindowDesc* window, void* context)
{
    HMODULE module = LoadLibraryA("OpenGL32.dll");
    if (module != NULL)
    {
        BOOL (GL_APICALL*wglMakeCurrent)(HDC device, void* context) = GetProcAddress(module, "wglMakeCurrent");
        if (wglMakeCurrent != NULL)
        {
            wglMakeCurrent((HDC)window->device, context);
        }
    }
}
