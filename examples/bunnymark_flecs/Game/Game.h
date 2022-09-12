#pragma once

void Game_Setup(struct SpriteBatch* spriteBatch, int objectCount);
void Game_Shutdown();

void Game_Update(float time, float deltaTime);
void Game_Render();
