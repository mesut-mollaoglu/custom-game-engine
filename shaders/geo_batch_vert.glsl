#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

out vert_input
{
    vec3 position;
    vec4 color;
} vert;

void main()
{
    vert.color = color;
    gl_Position = vec4(position, 1.0);
}