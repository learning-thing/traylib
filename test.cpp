#include "traylib.hpp"

int main(int argc, char **arg) {
	SetLogLevel(LOG_LEVEL_ERROR | LOG_LEVEL_INFO | LOG_LEVEL_WARNING | LOG_TO_FILE);
	InitWindow(200, 100, "Test game");
	while (!WindowShouldClose()) {
		BeginDrawing();
		//ClearBackground({255, 255, 255, 255});
		ClearBackground(0xFFFFFFFF);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
