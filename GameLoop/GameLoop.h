#pragma once
#include<iostream>
#include<array>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<InputManager.h>

class GameLoop{
public:
	GLFWwindow* gameWindow;
	GameLoop(int width, int height, const std::string& title);
	~GameLoop();
	int run();

private:
	int windowWidth;
	int windowHeight;
	std::string windowTitle;
	InputManager inputManager = NULL;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	int configureWindow();
	void processInput();
	void update();
	void render(GLFWwindow* window);
};