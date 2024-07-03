#version 330 core
layout (location = 0) out vec4 res;

in vert_input
{
    vec3 position;
    vec4 color;
    flat int use_proj_mat;
} frag;

void main()
{
    res = frag.color;
}