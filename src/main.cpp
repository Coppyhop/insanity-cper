#include <GLFW/glfw3.h>
#include "engine.h"

int main() {
  WindowManager windowManager;

  std::cout << "Creating the window..." << std::endl;
  windowManager.init();
  GLFWwindow* window = windowManager.createWindow(640,480, "Test", false);
  while(!windowManager.shouldWindowClose(window)){
    windowManager.update(window);
  }
  windowManager.destroyWindow(window);
  return 0;
}
