#version 330 core
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec4 color;
layout (location = 3) in uint texture;

out VertexInput
{
    vec2 Texcoord;
    vec4 Color;
    flat uint Texture;
} Output;

void main()
{
    Output.Texcoord = texcoord;
    Output.Color = color;
    Output.Texture = texture;
    gl_Position = position;
}