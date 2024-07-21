#version 330 core
layout (location = 0) out vec4 res;
#define MAX_LIGHTS 10

in vert_input
{
    vec3 pos;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
} frag;

struct point_light
{
    bool enabled;
    vec3 pos;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform vec3 camera_pos;
uniform material mat;
uniform bool has_texture;
uniform sampler2D texture_data;
uniform point_light point_lights[MAX_LIGHTS];

vec3 get_point_light_frag(int index)
{
    vec3 point_light_frag;
    point_light_frag += mat.ambient * point_lights[index].ambient;
    vec3 norm = normalize(frag.normal);
    vec3 dir = normalize(point_lights[index].pos - frag.pos);
    float diffuse = max(dot(norm, dir), 0.0f);
    point_light_frag += mat.diffuse * diffuse * point_lights[index].diffuse;
    vec3 view = normalize(camera_pos - frag.pos);
    vec3 ref = reflect(-dir, norm);
    float specular = pow(max(dot(view, ref), 0.0), mat.shininess);
    point_light_frag += mat.specular * point_lights[index].specular * specular;  
    return point_light_frag;
}

void main()
{
    vec3 point_light_res;
    for(int i = 0; i < MAX_LIGHTS; i++) if(point_lights[i].enabled) point_light_res += get_point_light_frag(i);
    vec4 sampled_color = has_texture ? texture(texture_data, frag.texcoord) : vec4(1.0f);
    res = frag.color * sampled_color * vec4(point_light_res, 1.0f);
}