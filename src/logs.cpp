#include "include/traylib.hpp"
#include "include/utils.hpp"
#include <fstream>

void SetLogLevel(uint8_t NewLevel) {
	config.currentLogLevel = NewLevel;
	if (NewLevel & LOG_TO_FILE) config.logToFile = true;
}

void appLog(const char *msg, LogLevel level) {
	if (config.logToFile) {
		internals.logFile << msg;
	}
	switch (level) {
		case LOG_LEVEL_INFO:
			if (config.currentLogLevel & LOG_LEVEL_INFO) std::cout << ANSI_COLOR_CYAN << msg << ANSI_COLOR_RESET << std::endl;
			break;
		case LOG_LEVEL_WARNING:
			if (config.currentLogLevel & LOG_LEVEL_WARNING) std::cout << ANSI_COLOR_YELLOW << msg << ANSI_COLOR_RESET << std::endl;
			break;
		case LOG_LEVEL_ERROR:
			if (config.currentLogLevel & LOG_LEVEL_ERROR)  std::cout << ANSI_COLOR_RED << msg << ANSI_COLOR_RESET << std::endl;
			break;
		default:
			break;
	};
}
