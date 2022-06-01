#pragma once

#include <stdint.h>

void Game_Setup(const struct SpriteSheet* spriteSheet, int32_t objectCount);
void Game_Shutdown();

void Game_Update(float time, float deltaTime);
void Game_Render();
