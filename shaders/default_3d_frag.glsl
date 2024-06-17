#version 330 core
layout (location = 0) out vec4 res;

in vert_input
{
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
} frag;

void main()
{
    res = frag.color;
}