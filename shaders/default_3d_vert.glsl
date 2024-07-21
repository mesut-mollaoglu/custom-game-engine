#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;
layout (location = 3) in vec4 color;

out vert_input
{
    vec3 pos;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
} vert;

uniform mat4 persp;
uniform mat4 model;

void main()
{
    vert.texcoord = texcoord;
    vert.color = color;
    vert.normal = mat3(transpose(inverse(model))) * normal;
    vert.pos = vec3(model * vec4(position, 1.0f));
    gl_Position = persp * vec4(vert.pos, 1.0f);
}