#include<GLFW/glfw3.h>
#include <iostream>
#include <array>
#include <InputManagerBase.h>

class InputManager : public InputManagerBase {
public:
	virtual void setEventHandling() { event_handling_instance = this; }

	InputManager(GLFWwindow* window) {
		Initialize(window);
	}

	bool Initialize(GLFWwindow* window) {
		mouseX = mouseY = 0;
		gameWindow = window;
		setEventHandling();
		glfwSetKeyCallback(window, InputManagerBase::OnKeyEvent_dispatch);
		glfwSetCursorPosCallback(window, InputManagerBase::OnMouseMove_dispatch);
		glfwSetMouseButtonCallback(window, InputManagerBase::OnMouseButtonEvent_dispatch);
		std::cout << "initialized";
		return true;
	}

	~InputManager() {
		glfwTerminate();
	}

	void OnMouseMove(GLFWwindow* window, double x, double y) {
		mouseX = x;
		mouseY = y;
		/*std::cout << "(" << x << ", ";s
		std::cout << y << ")\n";*/
	}

	void OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods) {
		if (action == GLFW_PRESS) {
			//std::cout << "You pressed mouse " << button << "!\n";
			mouseButtons[button] = true;
		}
		else if (action == GLFW_RELEASE) {
			std::cout << "You released mouse " << button << "!\n";
			mouseButtons[button] = false;
		}
	}

	std::array<bool, GLFW_KEY_LAST> GetKeyboardState() {
		return keyboardState;
	}

	std::array<bool, GLFW_MOUSE_BUTTON_LAST> GetMouseButtonState() {
		return mouseButtons;
	}

	void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (action == GLFW_PRESS) {
			keyboardState[key] = true;
			//std::cout << "You pressed " << key << "!\n";
		}
		else if (action == GLFW_RELEASE) {
			std::cout << "You released " << key << "!\n";
			keyboardState[key] = false;
		}
	}

private:
	GLFWwindow* gameWindow;
	std::array<bool, GLFW_KEY_LAST> keyboardState;
	std::array<bool, GLFW_MOUSE_BUTTON_LAST> mouseButtons;
	double mouseX;
	double mouseY;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
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

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

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
int main() {
	return initGlfw();
}


