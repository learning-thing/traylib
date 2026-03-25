#include "../../include/traylib.hpp"
#include "../../include/Graphics.hpp"
#include <cstdio>

appWindow_t appWindow;
status_t status;

void intHandler(int d) {
	status.windowShouldClose = true;
}

void InitWindow(int width, int height, const char *title) {
	// Setup Renderer
	// Setup signal handlers
	signal(SIGINT, intHandler);
	appLog("App initialized!", LOG_LEVEL_WARNING);

	glfwInit();
	appWindow.window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (appWindow.window) {
		appLog("GLFW Window created successfully!", LOG_LEVEL_INFO);
		glfwMakeContextCurrent(appWindow.window);
	} else {
		appLog("GLFW Window could not be created!", LOG_LEVEL_ERROR);
		const char *errorBuffer[256] = {};
		glfwGetError(errorBuffer);
		appLog(errorBuffer[0], LOG_LEVEL_ERROR);
	}

	if (config.logToFile) {
		appWindow.logFile.open("log.log");
		if (!appWindow.logFile.is_open()) { std::cout << "Failed to open logFile\n" << "\n"; } }
}

bool WindowShouldClose() {
	if (status.windowShouldClose) {
		appLog("Window exit requested!", LOG_LEVEL_INFO);
		return true;
	}
	return false;
}

void CloseWindow() {
	if (appWindow.window) {
		glfwDestroyWindow(appWindow.window);
		appLog("GLFW Window Closed!", LOG_LEVEL_WARNING);
	}

	// Restore previous temrinal mode
	appLog("Closed app successfully.", LOG_LEVEL_INFO);
	if (config.logToFile) appWindow.logFile.close();
}
