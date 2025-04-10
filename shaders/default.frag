#version 330 core

in VertexInput
{
    vec2 Texcoord;
} Input;

uniform sampler2D u_scrQuad;

void main()
{
    vec4 sampledColor = texture(u_scrQuad, Input.Texcoord);
    if(sampledColor.a == 0.0f) discard;
    gl_FragColor = sampledColor;
}