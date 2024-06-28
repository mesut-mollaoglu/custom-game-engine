#version 330 core
layout (location = 0) out vec4 res;

in vert_input
{
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
} frag;

uniform vec4 material;
uniform bool has_texture;
uniform sampler2D texture_data;

void main()
{
    vec4 sampled_color = has_texture ? texture(texture_data, frag.texcoord) : vec4(1.0f);
    res = frag.color * material * sampled_color;
}