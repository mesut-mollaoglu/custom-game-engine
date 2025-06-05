#version 330 core

in VertexInput
{
    vec2 Texcoord;
    vec4 Color;
    flat uint Texture;
} Input;

uniform sampler2D u_buffers[MAX_SPRITES];

void main()
{
    vec4 sampledColor = texture(u_buffers[Input.Texture], Input.Texcoord);
    if(sampledColor.a == 0.0f) discard;
    gl_FragColor = Input.Color * sampledColor;
}