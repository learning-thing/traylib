#pragma once
#include <cstdint>
#include <iostream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//                                                   Logging
enum LogLevel {
	LOG_LEVEL_INFO    = (1 << 0),//not so relevant
	LOG_LEVEL_WARNING = (1 << 1),//might be relevant
	LOG_LEVEL_ERROR   = (1 << 2),//definitely relevant or critical
	LOG_TO_FILE       = (1 << 3),
};

void setLogLevel(uint8_t NewLevel);
void appLog(const char *msg, LogLevel level);
