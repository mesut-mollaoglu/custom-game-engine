#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec4 color;
layout (location = 3) in uint texture;
layout (location = 4) in int use_persp_mat;

out vert_input
{
    vec3 position;
    vec2 texcoord;
    vec4 color;
    flat uint texture;
    flat int use_persp_mat;
} vert;

uniform mat4 persp_mat;
uniform mat4 ortho_mat;

void main()
{
    vert.texcoord = texcoord;
    vert.color = color;
    vert.texture = texture;
    vert.use_persp_mat = use_persp_mat;
    gl_Position = (use_persp_mat == 1 ? persp_mat : ortho_mat) * vec4(position, 1.0);
}