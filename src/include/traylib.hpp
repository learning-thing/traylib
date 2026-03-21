#pragma once

#include <cstdint>

#include <fstream>
#include <iostream>
#include "utils.hpp"


inline struct {
	bool windowShouldClose = false;
} status;

static struct {
	char *frameBuffer = nullptr;
	std::ofstream logFile;
	uint_fast32_t windowWidth;
	uint_fast32_t windowHeight;
} internals;

inline struct {
	uint8_t currentLogLevel = 0;
	bool logToFile = false;
} config;

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

//Backend
void SetLogLevel(uint8_t NewLevel);

//Window
void InitWindow(int width, int height, const char *title);
bool WindowShouldClose();
void CloseWindow();

//Input
void IsKeyPressed(int key);
void IsKeyDown(int key);

// Drawing
void DrawTexture(Texture2D texture, int posX, int posY, Color tint);
void ClearBackground(Color color);
void BeginDrawing();
void EndDrawing();

// Logging
enum LogLevel {
	LOG_LEVEL_INFO    = (1 << 0),//not so relevant
	LOG_LEVEL_WARNING = (1 << 1),//might be relevant
	LOG_LEVEL_ERROR   = (1 << 2),//definitely relevant or critical
	LOG_TO_FILE       = (1 << 3),
};

void appLog(const char *msg, LogLevel level);
