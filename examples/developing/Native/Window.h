#pragma once

#include <stdint.h>

#ifndef __cplusplus
#include <stdbool.h>
#else
#include <assert.h> // For auto unclosed window attempt to be destroyed
#endif

typedef enum WindowFlags
{
    WindowFlags_None          = 0,
    WindowFlags_Visible       = 1 << 0,
    WindowFlags_Resizable     = 1 << 1,
    WindowFlags_Fullscreen    = 1 << 2,
    WindowFlags_Borderless    = 1 << 3,

    WindowFlags_Default       = WindowFlags_Visible,
} WindowFlags;

typedef struct WindowDesc
{
    uintptr_t       handle;
    uintptr_t       device;

    uint32_t        flags;
    const char*     title;
    int32_t         width;
    int32_t         height;

    #ifdef __cplusplus
    inline WindowDesc()
        : handle(0)
        , device(0)
        , flags(WindowFlags_None)
        , title("")
        , width(0)
        , height(0)
    {
    }

    inline ~WindowDesc()
    {
        assert(handle == 0 && device == 0);
    }
    #endif
} WindowDesc;

// -------------------------------------------------------------
// Main functions
// -------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

bool                Window_Open(WindowDesc* window);
void                Window_Close(WindowDesc* window);

/// Process all coming events
/// Return true if the window is alive, false otherwise, and the loop should shutdown
bool                Window_PollEvents(void); 

/// Wait a events and then process all coming events
/// Return true if the window is alive, false otherwise, and the loop should shutdown
bool                Window_WaitAndPollEvents(void);

float               Window_GetWidth(void);
float               Window_GetHeight(void);

bool                Window_IsBorderless(void);
bool                Window_IsFullscreen(void);
//bool              Window_IsFullscreenSettings(void);

void                Window_SetBorderless(void);
void                Window_SetFullscreen(void);

bool                Window_IsWindowed(void);
void                Window_SetWindowed(void);

bool                Window_IsVisible(void);
void                Window_SetVisible(bool visible);

void                Window_SetCenter(void);

void                Window_EnableVSync(void);
void                Window_DisableVSync(void);
bool                Window_IsVSyncEnabled(void);
void                Window_SetVSyncEnabled(bool value);

bool                Window_HasInputFocus(void);
bool                Window_HasMouseFocus(void);

const WindowDesc*   Window_GetMainWindow(void);

#ifdef __cplusplus
}
#endif

// -------------------------------------------------------------
// C++ Extensions
// -------------------------------------------------------------

#ifdef __cplusplus
//inline float Window_GetWidth()
//{
//    return Window_GetWidth(nullptr);
//}
#endif