#pragma once

#include <cstdint>
struct Texture;
typedef Texture Texture2D;

struct Color {
	union {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
	union {
		uint8_t x;
		uint8_t y;
		uint8_t z;
		uint8_t w;
	};
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
