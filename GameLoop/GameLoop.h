#pragma once
#include<iostream>
#include<array>
#include<GLFW/glfw3.h>
#include<InputManager.h>

class GameLoop{
public:
	GLFWwindow* gameWindow;

	int run() {
		return initGlfw();
	}
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	int initGlfw() {

		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW";
			return -1;
		}

		glfwWindowHint(GLFW_SAMPLES, 4); // anti aliasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // openGL major version to be 3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); // minor set to 3, which makes the version 3.3
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE); //avoid using old openGL

		GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
		gameWindow = window;
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwSetKeyCallback(window, InputManagerBase::OnKeyEvent_dispatch);
		glfwSetCursorPosCallback(window, InputManagerBase::OnMouseMove_dispatch);
		glfwSetMouseButtonCallback(window, InputManagerBase::OnMouseButtonEvent_dispatch);
		glfwMakeContextCurrent(window);
		glViewport(0, 0, 800, 600);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		InputManager input1(window);

		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		return 0;
	}
};