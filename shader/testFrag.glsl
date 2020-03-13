#version 150 core
out vec4 FragColor;
  
in vec2 passTex; 

uniform sampler2D textureSample;
void main()
{
    FragColor = texture(textureSample, passTex);
} 