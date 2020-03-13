#include "WindowManager.h"

WindowManager::WindowManager(){}

void WindowManager::init(){
    //glfwSetErrorCallback(glfwerror_callback);
    if(!glfwInit()){
        std::cerr << "Unable to Initialize GLFW" << std::endl;
    }
}

GLFWwindow* WindowManager::createWindow(int width, int height, 
        const char * title, bool vSync){
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    glfwShowWindow(window);
    return window;
}

bool WindowManager::shouldWindowClose(GLFWwindow* window){
    return glfwWindowShouldClose(window);
}

void WindowManager::update(GLFWwindow* window){
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void WindowManager::destroyWindow(GLFWwindow* window){
    glfwDestroyWindow(window);
    glfwTerminate();
}
