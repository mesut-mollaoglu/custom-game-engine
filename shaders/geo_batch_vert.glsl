#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in int usePerspMat;

out VertexInput
{
    vec3 Position;
    vec4 Color;
    flat int UsePerspMat;
} Output;

uniform mat4 perspMat;
uniform mat4 orthoMat;

void main()
{
    Output.Color = color;
    Output.UsePerspMat = usePerspMat;
    gl_Position = (usePerspMat == 1 ? perspMat : orthoMat) * vec4(position, 1.0f);
}