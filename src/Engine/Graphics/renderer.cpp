#include "../../include/traylib.hpp"

void BeginDrawing() {

}

void EndDrawing() {
	//Check for Close requested
	glfwSwapBuffers(appWindow.window);
	glfwPollEvents();
	if (glfwWindowShouldClose(appWindow.window)) { status.windowShouldClose = true; }
}
