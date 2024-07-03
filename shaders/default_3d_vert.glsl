#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;
layout (location = 3) in vec4 color;

out vert_input
{
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
} vert;

uniform mat4 camera_mat;
uniform mat4 model;

void main()
{
    vert.texcoord = texcoord;
    vert.normal = normal;
    vert.color = color;
    gl_Position = camera_mat * model * vec4(position, 1.0f);
}