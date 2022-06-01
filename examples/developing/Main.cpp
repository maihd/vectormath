#include "Native/Window.h"
#include "Native/Thread.h"
#include "Renderer/Renderer.h"
#include "Game/Game.h"

#include <float.h>
#include <stdio.h>

#define RUN_UNIT_TESTS
#define UNIT_TESTS_MAIN RunAllUnitTests
#include "../unit_tests/test_framework.h"

int main(const int argc, const char* argv[])
{
    int runTestsStatus = RunAllUnitTests(argc, argv);
    if (runTestsStatus != 0)
    {
        return runTestsStatus;
    }

    WindowDesc window;
    window.title = "VectorMath Examples + ECS + SpriteBatch + JobSystem";
    window.width = 1280;
    window.height = 720;
    window.flags = WindowFlags_Default;
    Window_Open(&window);
    Renderer_Setup(&window);

    int spriteCount = 8;
    SpriteSheet spriteBatch;
    Renderer_LoadSpriteSheet(&spriteBatch, "../../assets/sprites.png", spriteCount);

    int objectCount = 100000;
    Game_Setup(&spriteBatch, objectCount);

    float   deltaTime           = 0.0f;
    int64_t timerFrequency      = Thread_GetCpuFrequency();
    int64_t timerTicks          = Thread_GetCpuTicks();
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
        
		vec2 fpsTextSize = Renderer_TextSize(fpsText) * vec2 { 2.0f, 2.0f };

        Renderer_DrawQuad(
			vec2{ 0.0f, (float)window.height },
			vec2{ fpsTextSize.x + 10.0f, (float)window.height - 1.5f * fpsTextSize.y - 10.0f },
			vec3{0.0f});
		Renderer_DrawText(fpsText, vec2{ 5.0f, (float)window.height - 5.0f }, vec3{ 0.25f, 0.5f, 1.0f });
		Renderer_DrawText(objectCountText, vec2{ 5.0f, (float)window.height - 45.0f }, vec3{ 0.25f, 0.5f, 1.0f });

        Renderer_Present();

        // Update timers
        int64_t currentTicks = Thread_GetCpuTicks();
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