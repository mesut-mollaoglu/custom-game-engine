#version 330 core

uniform samplerCube cubeMap;

in vec4 Position;

void main()
{
    gl_FragColor = texture(cubeMap, Position.xyz);
}