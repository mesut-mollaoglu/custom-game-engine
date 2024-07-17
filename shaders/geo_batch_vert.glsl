#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in int use_persp_mat;

out vert_input
{
    vec3 position;
    vec4 color;
    flat int use_persp_mat;
} vert;

uniform mat4 persp;
uniform mat4 ortho;

void main()
{
    vert.color = color;
    vert.use_persp_mat = use_persp_mat;
    gl_Position = (use_persp_mat == 1 ? persp : ortho) * vec4(position, 1.0f);
}