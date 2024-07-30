#version 330 core

in VertexInput
{
    vec2 Position;
    vec2 Texcoord;
} Input;

uniform sampler2D scrQuad;
uniform int postProcessID;

vec4 InvertFrag(vec4 color)
{
    return vec4(vec3(1.0 - color.rgb), color.a);
}

void main()
{
    vec4 frag = texture(scrQuad, vec2(Input.Texcoord.x, 1.0 - Input.Texcoord.y));
    switch(postProcessID)
    {
        case 0: gl_FragColor = frag; break;
        case 1: gl_FragColor = InvertFrag(frag); break;
        default: break;
    }
}