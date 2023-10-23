#pragma once
#include<GLFW/glfw3.h>

class InputManagerBase
{
public:

    static InputManagerBase* event_handling_instance;

    virtual void setEventHandling();

    virtual void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;
    virtual void OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods) = 0;
    virtual void OnMouseMove(GLFWwindow* window, double x, double y) = 0;

    static void OnKeyEvent_dispatch(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (event_handling_instance)
            event_handling_instance->OnKeyEvent(window, key, scancode, action, mods);
    }
    static void OnMouseButtonEvent_dispatch(GLFWwindow* window, int button, int action, int mods)
    {
        if (event_handling_instance)
            event_handling_instance->OnMouseButtonEvent(window, button, action, mods);
    }
    static void OnMouseMove_dispatch(GLFWwindow* window, double x, double y)
    {
        if (event_handling_instance)
            event_handling_instance->OnMouseMove(window, x, y);
    }
};