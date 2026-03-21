#include "include/traylib.hpp"
#include "include/utils.hpp"
#include <csignal>
#include <fstream>

void intHandler(int d) {
	status.windowShouldClose = true;
}

void InitWindow(int width, int height, const char *title) {
	// Setup terminal mode
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

void ClearBackground(Color color) {
	for (int y = 0; y < internals.windowHeight; ++y) {
		for (int x = 0; x < internals.windowWidth; ++x) {
			//std::cout << "#";
		}
	}
}

void BeginDrawing() {

}

void EndDrawing() {

}
