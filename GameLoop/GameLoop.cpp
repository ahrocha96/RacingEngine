#include "GameLoop.h"

int GameLoop::run() {
	if (initGlfw() != 0) {
		return -1;
	}
	while (!glfwWindowShouldClose(gameWindow)) {
		processInput();
		render(gameWindow);
		update();
	}

	return 0;
}

GameLoop::GameLoop(int width, int height, const std::string& title) : gameWindow(nullptr), inputManager(gameWindow), windowWidth(width), windowHeight(height), windowTitle(title) {

}

GameLoop::~GameLoop() {
	if (gameWindow) {
		glfwDestroyWindow(gameWindow);
		glfwTerminate();
	}
}

int GameLoop::initGlfw() {

	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW";
		return -1;
	}

	gameWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);

	if (gameWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // anti aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // openGL major version to be 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); // minor set to 3, which makes the version 3.3
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE); //avoid using old openGL

	glfwSetKeyCallback(gameWindow, InputManagerBase::OnKeyEvent_dispatch);
	glfwSetCursorPosCallback(gameWindow, InputManagerBase::OnMouseMove_dispatch);
	glfwSetMouseButtonCallback(gameWindow, InputManagerBase::OnMouseButtonEvent_dispatch);

	glfwMakeContextCurrent(gameWindow);
	glViewport(0, 0, windowWidth, windowHeight);
	glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);

	std::cout << "GameLoop initialized" << std::endl;

	return 0;
}

void GameLoop::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GameLoop::render(GLFWwindow* window) {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void GameLoop::update() {

}

void GameLoop::processInput() {

}