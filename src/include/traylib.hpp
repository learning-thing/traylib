#pragma once

#include <cstdint>
#include <cstdio>
#include <iostream>
#include "utils.hpp"

struct {
	bool windowShouldClose = false;
} status;

struct {
	char *frameBuffer = nullptr;
} internals;

struct {
	uint8_t currentLogLevel = 0;
} config;

struct Texture;
typedef Texture Texture2D;

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
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
};

void appLog(const char *msg, LogLevel level);
