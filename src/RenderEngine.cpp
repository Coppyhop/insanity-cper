#include <RenderEngine.h>
#include <GL/glew.h>
#include <GL/glut.h>

void RenderEngine::initOpenGL(){
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 1);
    loadVertices();
    lastFrame = 0; //TODO: System.nanoTime() but C++ version

    testShader = new ShaderProgram();
    testShader->Load("shader/testVert.glsl", "shader/testFrag.glsl");
}

void RenderEngine::loadVertices(){
    glGenBuffers(1, buffers);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    //Allocate 20 floats worth of bytes to the buffer
    //12 for vertices, and 8 for texture coords
    glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(float), NULL, GL_STATIC_DRAW);
    //Now put in all the data we need
    glBufferSubData(GL_ARRAY_BUFFER, 0, 12* sizeof(float),vertices);
    glBufferSubData(GL_ARRAY_BUFFER, 12 * sizeof(float), 8 * sizeof(float), 
        texCoords);
    //Make sure GL knows which pieces are part of which array
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 3, 
        BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(float) * 2, 
        BUFFER_OFFSET(12*sizeof(float)));
    //Next is the index buffer... 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6* sizeof(unsigned int), indicies, 
        GL_STATIC_DRAW);
    //Done! Bind the default buffer to make sure nothing can go wrong
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void RenderEngine::prepareRender(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    testShader->Use();
}

void RenderEngine::endRender(){
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void RenderEngine::drawRender(){

}

//void RenderEngine::renderEntity(Entity entity){}

RenderEngine::RenderEngine(int width, int height, float UIScale){
    this->width = width;
    this->height = height;
    this->uiScale = UIScale;
    deltaTime = 0;
    lastFrame = 0;
    time = 0;
    initOpenGL();
}

RenderEngine::RenderEngine(int width, int height){
    this->width = width;
    this->height = height;
    uiScale = 1;
    deltaTime = 0;
    lastFrame = 0;
    time = 0;
    initOpenGL();
}

float RenderEngine::getWidth(){
    return width;
}

float RenderEngine::getHeight(){
    return height;
}

float RenderEngine::getUIScale(){
    return uiScale;
}

float RenderEngine::getDeltaTime(){
    return deltaTime;
}

void RenderEngine::setTexture(Texture texture){
    glBindTexture(GL_TEXTURE_2D, texture.getID());
}

void RenderEngine::setTextureByID(int texture){
    glBindTexture(GL_TEXTURE_2D, texture);
}

//void RenderEngine::processEntity(Entity entity){}

void RenderEngine::render(){
    prepareRender();
    //Main rendering shtuff
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    endRender();
    drawRender();
    //Clear this frame's object list
}

void RenderEngine::cleanUp() {
    testShader->Delete();
}
