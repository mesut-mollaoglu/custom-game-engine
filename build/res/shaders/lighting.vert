#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;
layout (location = 3) in vec4 color;

out VertexInput
{
    vec3 Position;
    vec3 Normal;
    vec2 Texcoord;
    vec4 Color;
} Output;

uniform mat4 u_camMatrix;
uniform mat4 u_meshWorldMatrix;

void main()
{
    Output.Texcoord = texcoord;
    Output.Color = color;
    Output.Normal = mat3(transpose(inverse(u_meshWorldMatrix))) * normal;
    Output.Position = vec3(u_meshWorldMatrix * vec4(position, 1.0f));
    gl_Position = u_camMatrix * vec4(Output.Position, 1.0f);
}