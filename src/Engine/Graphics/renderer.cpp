#pragma once
#include "../../include/traylib.hpp"
#include <csignal>

void intHandler(int d) {
	status.windowShouldClose = true;
}

void InitWindow(int width, int height, const char *title) {
	// Setup Renderer
	// Setup signal handlers
	signal(SIGINT, intHandler);
	appLog("App started!", LOG_LEVEL_WARNING);

	if (config.logToFile) {
		internals.logFile.open("log.log");
		if (!internals.logFile.is_open()) {
			std::cout << "Failed to open logFile\n" << "\n";
		}
	}
}

bool WindowShouldClose() {
	if (status.windowShouldClose) {
		appLog("WINDOW MUST CLOSE!", LOG_LEVEL_ERROR);
		return true;
	}
	return false;
}

void CloseWindow() {
	// Restore previous temrinal mode
	appLog("Closed app successfully.", LOG_LEVEL_INFO);
	if (config.logToFile) internals.logFile.close();
}



void BeginDrawing() {

}

void EndDrawing() {

}
