#include "WindowManager.h"
#include "RenderEngine.h"

int main() {
  WindowManager windowManager;
  windowManager.init();
  GLFWwindow* window = windowManager.createWindow(640,480, "Test", false);
  RenderEngine* renderEngine = new RenderEngine(640, 480);
  while(!windowManager.shouldWindowClose(window)){
      renderEngine->render();
    windowManager.update(window);
  }
  windowManager.destroyWindow(window);
  return 0;
}
