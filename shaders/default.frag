#version 330 core

in VertexInput
{
    vec2 Texcoord;
} Input;

uniform sampler2D scrQuad;

void main()
{
    vec4 sampledColor = texture(scrQuad, Input.Texcoord);
    if(sampledColor.a == 0.0f) 
        discard;
    gl_FragColor = sampledColor;
}