#include "include/traylib.hpp"
#include <csignal>


bool WindowShouldClose() {
	if (status.windowShouldClose) {
		appLog("WINDOW MUST CLOSE!\n", LOG_LEVEL_ERROR);
		return true;
	}
	return false;
}

void CloseWindow() {
	// Restore previous temrinal mode
	appLog("Closed app successfully.\n", LOG_LEVEL_INFO);
}

void intHandler(int d) {
	status.windowShouldClose = true;
}

void InitWindow(int width, int height, const char *title) {
	// Setup terminal mode
	// Setup signal handlers
	signal(SIGINT, intHandler);
	appLog("app started!\n", LOG_LEVEL_WARNING);
}

void ClearBackground(Color color) {

}

void BeginDrawing() {

}

void EndDrawing() {

}
