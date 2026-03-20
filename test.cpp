#include "traylib.hpp"

int main(int argc, char **arg) {
	InitWindow(200, 100, "Test game");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground({255, 255, 255, 255});
		EndDrawing();
	}
	return 0;
}
