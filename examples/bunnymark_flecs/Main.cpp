#include "Native/Window.h"
#include <Threading/ThreadFunctions.h>
#include "Renderer/Renderer.h"
#include "Game/Game.h"

#include <float.h>
#include <stdio.h>
#include <vectormath.h>

int main(const int argc, const char* argv[])
{
    WindowDesc window;
    window.title = "VectorMath Example - Bunnymark + Flecs";
    window.width = 1280;
    window.height = 720;
    window.flags = WindowFlags_Default;
    Window_Open(&window);
    
	if (Renderer_Setup(&window) != 0)
	{
		Window_MessageBox(window.title, "Initialize Renderer failed!");
		Window_Close(&window);
		return -1;
	}

    int spriteCount = 8;
    SpriteBatch spriteBatch;
    Renderer_LoadSpritesHorizontal(&spriteBatch, "../../examples/assets/sprites.png", spriteCount);

    int objectCount = 10000;
    Game_Setup(&spriteBatch, objectCount);

    float   deltaTime           = 0.0f;
    int64_t timerFrequency      = Threading_GetCpuFrequency();
    int64_t timerTicks          = Threading_GetCpuTicks();
    int64_t timerInterval       = timerFrequency / 60;
    double  invTimerFrequency   = 1.0 / (double)timerFrequency;
    while (Window_PollEvents())
    {
        Game_Update(0.0f, deltaTime);

        Renderer_Clear();

        //Renderer_DrawSprite(nullptr, vec2((float)window.width * 0.5f, (float)window.height * 0.5f), 0.0f, vec2(100.0f), vec3(0.5f, 0.5f, 1.0f));
        
        Game_Render();

        char fpsText[1024];
        snprintf(fpsText, sizeof(fpsText), "FPS: %.3f", deltaTime > FLT_EPSILON ? 1.0f / deltaTime : 0.0f);

        char objectCountText[1024];
        snprintf(objectCountText, sizeof(objectCountText), "Object count: %d", objectCount);
        
        vec2 fpsTextSize = Renderer_TextSize(fpsText) * vec2_new(2.0f, 2.0f);

        Renderer_DrawQuad(
            vec2_new(0.0f, (float)window.height), 
            vec2_new(fpsTextSize.x + 10.0f, (float)window.height - 1.5f * fpsTextSize.y - 10.0f), 
            vec3_new1(0.0f));
        Renderer_DrawText(fpsText, vec2_new(5.0f, (float)window.height - 5.0f), vec3_new(0.25f, 0.5f, 1.0f));
        Renderer_DrawText(objectCountText, vec2_new(5.0f, (float)window.height - 45.0f), vec3_new(0.25f, 0.5f, 1.0f));

        Renderer_Present();

        // Update timers
        int64_t currentTicks = Threading_GetCpuTicks();
        int64_t elapsedTicks = currentTicks - timerTicks;
        
        #if defined(SLEEPY_MAIN_LOOP)
            if (elapsedTicks < timerInterval)
            {
                double sleepSeconds = (double)(timerInterval - elapsedTicks) * invTimerFrequency;
                Thread_MicroSleep((int64_t)(sleepSeconds * 1000 * 1000));

                elapsedTicks = timerInterval;
            }
        #endif

        deltaTime = (float)((double)elapsedTicks * invTimerFrequency);
        timerTicks = timerTicks + elapsedTicks;
    }

    Game_Shutdown();
    
    Renderer_Shutdown(&window);
    Window_Close(&window);
    return 0;
}