#version 330 core

uniform samplerCube u_cubeMap;

in vec4 Position;

void main()
{
    gl_FragColor = texture(u_cubeMap, Position.xyz);
}