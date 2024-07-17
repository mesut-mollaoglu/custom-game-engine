#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texcoord;

out vert_input
{
    vec2 position;
    vec2 texcoord;
} vert;

uniform mat4 ortho;

void main()
{
    vert.texcoord = texcoord;
    gl_Position = ortho * vec4(position, 1.0, 1.0);
}