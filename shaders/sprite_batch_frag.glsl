#version 330 core
layout (location = 0) out vec4 res;
#define NUM_TEXTURES 32

in vert_input
{
    vec3 position;
    vec2 texcoord;
    vec4 color;
    flat uint texture;
    flat int use_proj_mat;
} frag;

uniform sampler2D buffers[NUM_TEXTURES];

void main()
{
    vec4 sampled_color = texture(buffers[frag.texture], frag.texcoord);
    if(sampled_color.a == 0.0f) discard;
    res = frag.color * sampled_color;
}