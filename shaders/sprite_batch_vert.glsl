#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec4 color;
layout (location = 3) in uint texture;
layout (location = 4) in int use_proj_mat;

out vert_input
{
    vec3 position;
    vec2 texcoord;
    vec4 color;
    flat uint texture;
    flat int use_proj_mat;
} vert;

uniform mat4 camera_mat;

void main()
{
    vert.texcoord = texcoord;
    vert.color = color;
    vert.texture = texture;
    vert.use_proj_mat = use_proj_mat;
    gl_Position = (use_proj_mat == 1 ? camera_mat : mat4(1.0f)) * vec4(position, 1.0);
}