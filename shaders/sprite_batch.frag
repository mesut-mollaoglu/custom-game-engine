#version 330 core
#define MAX_TEXTURES 32

in VertexInput
{
    vec2 Texcoord;
    vec4 Color;
    flat uint Texture;
} Input;

uniform sampler2D buffers[MAX_TEXTURES];

void main()
{
    vec4 sampledColor = texture(buffers[Input.Texture], Input.Texcoord);
    if(sampledColor.a == 0.0f) 
        discard;
    gl_FragColor = Input.Color * sampledColor;
}