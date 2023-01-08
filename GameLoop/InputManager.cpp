#include<GLFW/glfw3.h>

class InputManager {
public:
	InputManager();

	~InputManager();

private:
	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);
};

InputManager::InputManager() {
}

InputManager::~InputManager() {

}
int main() {

}