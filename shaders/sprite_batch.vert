#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;
layout (location = 2) in vec4 color;
layout (location = 3) in uint texture;
layout (location = 4) in int usePerspMat;

out VertexInput
{
    vec2 Texcoord;
    vec4 Color;
    flat uint Texture;
} Output;

uniform mat4 perspMat;
uniform mat4 orthoMat;

void main()
{
    Output.Texcoord = texcoord;
    Output.Color = color;
    Output.Texture = texture;
    gl_Position = (usePerspMat == 1 ? perspMat : orthoMat) * vec4(position, 1.0);
}