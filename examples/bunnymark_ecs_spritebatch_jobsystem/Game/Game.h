#pragma once

void Game_Setup(const struct SpriteSheet* spriteSheet, int objectCount);
void Game_Shutdown();

void Game_Update(float time, float deltaTime);
void Game_Render();
