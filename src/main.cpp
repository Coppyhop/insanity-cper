#include "InsanityEngine.h"


int main() {
    WindowManager windowManager;
    windowManager.init();
    GLFWwindow* window = windowManager.createWindow(640,480, "Test", false);
    RenderEngine renderEngine (640, 480);

    Texture test("assets/container.jpg");

    while(!windowManager.shouldWindowClose(window)){
        renderEngine.setTexture(test);
        renderEngine.render();
        windowManager.update(window);
    }
    renderEngine.cleanUp();
    windowManager.destroyWindow(window);
    return 0;
}
