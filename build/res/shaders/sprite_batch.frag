#version 330 core

in VertexInput
{
    vec2 Texcoord;
    vec4 Color;
    flat uint Texture;
} Input;

uniform sampler2D u_buffers[MAX_SPRITES];

vec4 Sample()
{
    if(Input.Texture >= uint(MAX_SPRITES)) return vec4(0.0);
    LOOKUP_FUNCTION
}

void main()
{
    vec4 sampledColor = Sample();
    if(sampledColor.a == 0.0) discard;
    gl_FragColor = Input.Color * sampledColor;
}