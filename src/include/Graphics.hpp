#pragma once
#include <cstdint>

struct Texture;
typedef Texture Texture2D;

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r (r), g(g), b(b), a(a) {}
	Color(uint32_t fromHex) {
		a = fromHex & 0x000000FF;
		b = fromHex & 0x0000FF00;
		g = fromHex & 0x00FF0000;
		r = fromHex & 0xFF000000;
	}
};

//Window
void InitWindow(int width, int height, const char *title);
bool WindowShouldClose();
void CloseWindow();

// Drawing
void DrawTexture(Texture2D texture, int posX, int posY, Color tint);
void ClearBackground(Color color);
void BeginDrawing();
void EndDrawing();
