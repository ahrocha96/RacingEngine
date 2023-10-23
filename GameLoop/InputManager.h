#pragma once
#include <GLFW/glfw3.h>
#include <array>
#include <InputManagerBase.h>

class InputManager : public InputManagerBase {
public:
    InputManager(GLFWwindow* window);
    
    virtual bool Initialize(GLFWwindow* window);

    void OnMouseMove(GLFWwindow* window, double x, double y);
    void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
    void OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods);
   
    virtual std::array<bool, GLFW_KEY_LAST> GetKeyboardState();
    virtual std::array<bool, GLFW_MOUSE_BUTTON_LAST> GetMouseButtonState();

    GLFWwindow* gameWindow;


private:
    std::array<bool, GLFW_KEY_LAST> keyboardState;
    std::array<bool, GLFW_MOUSE_BUTTON_LAST> mouseButtons;
    double mouseX;
    double mouseY;
};