#include<GLFW/glfw3.h>
#include <iostream>
#include <array>

class InputManager {
public:
	InputManager(GLFWwindow* window);

	~InputManager();

	bool Initialize(GLFWwindow* window);

	static std::array<bool, GLFW_KEY_LAST>GetKeyboardState();

	static std::array<bool, GLFW_MOUSE_BUTTON_LAST>GetMouseButtonState();

	static void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void OnMouseMove(GLFWwindow* window, double x, double y);
	
	static void OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods);

private:
	GLFWwindow* window;
	static std::array<bool, GLFW_KEY_LAST> keyboardState;
	static std::array<bool, GLFW_MOUSE_BUTTON_LAST> mouseButtons;
	static double mouseX;
	static double mouseY;
};

InputManager::InputManager(GLFWwindow* window){
	Initialize(window);
}

InputManager::~InputManager() {
	glfwTerminate();
}

bool InputManager::Initialize(GLFWwindow* window) {
	mouseX = mouseY = 0;
	this->window = window;

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	glfwSetKeyCallback(window, &InputManager::OnKeyEvent);
	glfwSetCursorPosCallback(window, &InputManager::OnMouseMove);
	glfwSetMouseButtonCallback(window, &InputManager::OnMouseButtonEvent);

	return true;
}

void InputManager::OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		keyboardState[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keyboardState[key] = false;
	}
}

void InputManager::OnMouseMove(GLFWwindow* window, double x, double y) {
	mouseX = x;
	mouseY = y;
}

void InputManager::OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		mouseButtons[button] = true;
	}
	else if(action == GLFW_RELEASE){
		mouseButtons[button] = false;
	}
}

std::array<bool, GLFW_KEY_LAST> InputManager::GetKeyboardState() {
	return keyboardState;
}

std::array<bool, GLFW_MOUSE_BUTTON_LAST> InputManager::GetMouseButtonState()  {
	return mouseButtons;
}


int main() {

}