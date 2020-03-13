#include <cstdlib>
#include <iostream>
#define BUFFER_OFFSET(i) ((void*)(i))


class RenderEngine {
private:
    int width, height;
    float uiScale;
    long deltaTime;
    long lastFrame;
    int time;
    unsigned int buffers[2];
    float vertices[12] = {
        0, 0, 0,
        0, -1, 0,
        1, -1, 0,
        1, 0, 0
    };
    float texCoords[8] = { 0,0,0,1,1,1,1,0 };
    float indicies[6] = { 0,1,3,3,1,2 };

    void initOpenGL();
    void loadVertices();
    void prepareRender();
    void endRender();
    void drawRender();
    //void renderEntity(Entity entity);
public:
    RenderEngine(int width, int height, float UIScale);
    RenderEngine(int width, int height);
    float getWidth();
    float getHeight();
    float getUIScale();
    float getDeltaTime();
    //void setTexture(Texture texture);
    //void setTextureByID(int texture);
    //void processEntity(Entity entity);
    void render();
};