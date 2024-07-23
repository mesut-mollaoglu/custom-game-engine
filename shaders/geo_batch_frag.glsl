#version 330 core

in VertexInput
{
    vec3 Position;
    vec4 Color;
    flat int UsePerspMat;
} Input;

void main()
{
    gl_FragColor = Input.Color;
}