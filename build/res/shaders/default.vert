#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 texcoord;

out VertexInput
{
    vec2 Texcoord;
} Output;

void main()
{
    Output.Texcoord = texcoord;
    gl_Position = position;
}