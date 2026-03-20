#pragma once

#include <cstdint>
struct Texture;
typedef Texture Texture2D;

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

void InitWindow(int width, int height, const char *title);
void CloseWindow();
void IsKeyPressed(int key);
void IsKeyDown(int key);
void DrawTexture(Texture2D texture, int posX, int posY, Color tint);
void ClearBackground(Color color);
void BeginDrawing();
void EndDrawing();
bool WindowShouldClose();


// Logging
