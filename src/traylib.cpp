#include "traylib.hpp"
#include <csignal>

struct {
	bool windowShouldClose;
} status;

struct {
	char *frameBuffer;
} internals;

bool WindowShouldClose() {
	return status.windowShouldClose;
}

void CloseWindow() {
	// Restore previous temrinal mode

}

void intHandler(int d) {

}

void InitWindow(int width, int height, const char *title) {
	// Setup terminal mode
	// Setup signal handlers
	signal(SIGINT, intHandler);
}

void ClearBackground(Color color) {

}

void BeginDrawing() {

}

void EndDrawing() {

}
