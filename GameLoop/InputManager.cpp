#include <iostream>
#include <InputManager.h>
#include <InputManagerBase.h>

InputManager::InputManager(GLFWwindow* window) {
    Initialize(window);
}

bool InputManager::Initialize(GLFWwindow* window) {
	gameWindow = window;
	InputManager::setEventHandling();

	std::cout << "Input Manager initialized" << std::endl;
	return true;
}

void InputManager::OnMouseMove(GLFWwindow* window, double x, double y) {
	mouseX = x;
	mouseY = y;
	std::cout << "(" << x << ", ";
	std::cout << y << ")\n";
}

void InputManager::OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		keyboardState[key] = true;
		std::cout << "You pressed " << key << "!\n";
	}
	else if (action == GLFW_RELEASE) {
		std::cout << "You released " << key << "!\n";
		keyboardState[key] = false;
	}
}

void InputManager::OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		std::cout << "You pressed mouse " << button << "!\n";
		mouseButtons[button] = true;
	}
	else if (action == GLFW_RELEASE) {
		std::cout << "You released mouse " << button << "!\n";
		mouseButtons[button] = false;
	}
}

std::array<bool, GLFW_KEY_LAST> InputManager::GetKeyboardState() {
    return keyboardState;
}

std::array<bool, GLFW_MOUSE_BUTTON_LAST> InputManager::GetMouseButtonState() {
    return mouseButtons;
}