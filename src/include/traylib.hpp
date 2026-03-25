#pragma once

#include <cstdint>
#include <fstream>
#include "Utils.hpp"
#include "Graphics.hpp"

struct appWindow_t {
	std::ofstream logFile;
	GLFWwindow *window;
	uint_fast32_t windowWidth;
	uint_fast32_t windowHeight;
};

extern struct appWindow_t appWindow;

struct status_t {
	bool windowShouldClose = false;
};

extern status_t status;

inline struct {
	uint8_t currentLogLevel = 0;
	bool logToFile = false;
} config;
