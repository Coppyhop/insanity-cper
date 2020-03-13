#version 150 core
in vec3 aPos; 
in vec2 texCoords;

out vec2 passTex;

void main()
{
    gl_Position = vec4(aPos, 1.0); 
    passTex = texCoords;
}