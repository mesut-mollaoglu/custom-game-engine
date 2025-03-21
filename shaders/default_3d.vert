#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;
layout (location = 3) in vec4 color;

out VertexInput
{
    vec2 Texcoord;
    vec4 Color;
} Output;

uniform mat4 perspMat;
uniform mat4 meshWorldMatrix;

void main()
{
    Output.Texcoord = texcoord;
    Output.Color = color;
    gl_Position = perspMat * meshWorldMatrix * vec4(position, 1.0f);
}