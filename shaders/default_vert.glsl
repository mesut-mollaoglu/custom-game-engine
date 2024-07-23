#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texcoord;

out VertexInput
{
    vec2 Position;
    vec2 Texcoord;
} Output;

uniform mat4 orthoMat;

void main()
{
    Output.Texcoord = texcoord;
    gl_Position = orthoMat * vec4(position, 1.0, 1.0);
}