#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in int use_proj_mat;

out vert_input
{
    vec3 position;
    vec4 color;
    flat int use_proj_mat;
} vert;

uniform mat4 camera_mat;

void main()
{
    vert.color = color;
    vert.use_proj_mat = use_proj_mat;
    gl_Position = (use_proj_mat == 1 ? camera_mat : mat4(1.0f)) * vec4(position, 1.0f);
}