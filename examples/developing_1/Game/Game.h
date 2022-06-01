#pragma once

#include <stdint.h>

enum { GAME_FRAME_QUEUE_COUNT = 4 };

void Game_Setup(const struct SpriteSheet* spriteSheet, int objectCount);
void Game_Shutdown();

void Game_Update(uint32_t frame, float time, float deltaTime);
void Game_Render(uint32_t frame);
