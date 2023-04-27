#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vectormath.h>

#include <raylib.h>
#include <emscripten.h>

#include "Game/Game.h"
#include "Renderer/Renderer.h"

constexpr int windowWidth = 1280;
constexpr int windowHeight = 720;
constexpr int objectCount = 1000;

static void MainLoop();

int main(int argc, const char* argv[])
{
    InitWindow(windowWidth, windowHeight, "VectorMath WebAssembly with Raylib");

    if (Renderer_Setup() != 0)
	{
		return -1;
	}

    const int spriteCount = 8;
    static SpriteBatch spriteBatch;
    Renderer_LoadSpritesHorizontal(&spriteBatch, "assets/sprites.png", spriteCount);

    Game_Setup(&spriteBatch, objectCount);

    printf("Start game =)\n");
    emscripten_set_main_loop(MainLoop, 0, 1);

    Renderer_Shutdown();
    CloseWindow();
    return 0;
}

void MainLoop()
{
    float deltaTime = GetFrameTime();

    // Update game
    Game_Update(0.0f, deltaTime);

    // Clear back buffer
    Renderer_Clear();

    // Render game
    Game_Render();

    // Draw fps
    char fpsText[1024];
    snprintf(fpsText, sizeof(fpsText), "FPS: %.3f", deltaTime > FLOAT_EPSILON ? 1.0f / deltaTime : 0.0f);

    char objectCountText[1024];
    snprintf(objectCountText, sizeof(objectCountText), "Object count: %d", objectCount);
    
    vec2 fpsTextSize = Renderer_TextSize(fpsText) * vec2_new(2.0f, 2.0f);

    Renderer_DrawQuad(
        vec2_new(0.0f, 0.0f), 
        vec2_new(fpsTextSize.x + 10.0f, 1.5f * fpsTextSize.y - 10.0f), 
        vec3_new1(0.0f));
    Renderer_DrawText(fpsText, vec2_new(5.0f, 5.0f), vec3_new(0.25f, 0.5f, 1.0f));
    Renderer_DrawText(objectCountText, vec2_new(5.0f, 45.0f), vec3_new(0.25f, 0.5f, 1.0f));

    // Present back buffer
    Renderer_Present();
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
