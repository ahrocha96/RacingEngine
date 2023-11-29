#include "GameLoop.h"

int GameLoop::run() {
	while (!glfwWindowShouldClose(gameWindow)) {
		processInput();
		render(gameWindow);
		update();
	}

	return 0;
}

GameLoop::GameLoop(int width, int height, const std::string& title) {
	windowWidth = width;
	windowHeight = height;
	windowTitle = title;

	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
	}

	gameWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);

	inputManager = InputManager(gameWindow);

	if (gameWindow != NULL) {
		std::cout << "Game window created successfully" << std::endl;
	}
	else {
		std::cout << "Failed to create Game Window" << std::endl;
	}

	if (configureWindow() != 0) {
		std::cout << "Failed to configure window" << std::endl;
	}
}

GameLoop::~GameLoop() {
	if (gameWindow) {
		glfwDestroyWindow(gameWindow);
		glfwTerminate();
	}
}

int GameLoop::configureWindow() {
	//glfwWindowHint(GLFW_SAMPLES, 4); // anti aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	
	if (gameWindow != NULL) {
		glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);
		glfwSetKeyCallback(gameWindow, InputManagerBase::OnKeyEvent_dispatch);
		glfwSetCursorPosCallback(gameWindow, InputManagerBase::OnMouseMove_dispatch);
		glfwSetMouseButtonCallback(gameWindow, InputManagerBase::OnMouseButtonEvent_dispatch);
	}

	glfwMakeContextCurrent(gameWindow);

	if (!gladLoadGL()) {
		std::cerr << "Failed to initialize glad" << std::endl;
	}

	std::cout << "Game window configured" << std::endl;

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