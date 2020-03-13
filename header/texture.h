#include "stb_image.h"
#include <GL/glew.h>
#include <cstdlib>
#include <iostream>
class Texture {
public:
	Texture(const char* file);
	unsigned int getID();
private:
	unsigned int textureID;
};