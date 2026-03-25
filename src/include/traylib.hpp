#pragma once

#include <cstdint>
#include <fstream>
#include "Utils.hpp"

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
