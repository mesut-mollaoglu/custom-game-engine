#version 330 core
layout (location = 0) out vec4 res;

in vert_input
{
    vec2 position;
    vec2 texcoord;
} frag;

uniform sampler2D window;

void main()
{
    vec4 sampled_color = texture(window, frag.texcoord);
    if(sampled_color.a == 0.0f) discard;
    res = sampled_color;
}