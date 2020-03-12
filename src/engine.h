#include<string>
#undef GLFW_DLL
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

class WindowManager{
    public: 
        WindowManager();
        void init();
        GLFWwindow* createWindow(int width, int height, const char * title, bool vSync);
        bool shouldWindowClose(GLFWwindow* window);
        void update(GLFWwindow* window);
        void destroyWindow(GLFWwindow* window);
};
