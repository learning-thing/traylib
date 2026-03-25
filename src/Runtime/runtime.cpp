#include "../include/traylib.hpp"

int main(int argc, char **argv) {
	setLogLevel(LOG_LEVEL_ERROR | LOG_LEVEL_INFO | LOG_TO_FILE | LOG_LEVEL_WARNING);
	InitWindow(1080, 720, "Hello world");
	while (!WindowShouldClose()) {
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
