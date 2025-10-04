#version 330 core
#define BLINN_PHONG

in VertexInput
{
    vec3 Position;
    vec3 Normal;
    vec2 Texcoord;
    vec4 Color;
} Input;

float CalculateAttenuation(float distance, float constant, float linear, float quadratic)
{
    return 1.0f / (constant + linear * distance + quadratic * distance * distance);
}

uniform vec3 u_camPos;

#include "material.frag"
#include "point_light.frag"
#include "dir_light.frag"
#include "spot_light.frag"

uniform Material u_materials[MATERIAL_COUNT];
uniform PointLight u_pointLights[POINT_LIGHTS_COUNT];
uniform SpotLight u_spotLights[SPOT_LIGHTS_COUNT];
uniform DirectionalLight u_dirLights[DIR_LIGHTS_COUNT];

void main()
{
    vec3 color;
    vec3 normal = normalize(u_materials[0].HasNormalMap ? texture(u_materials[0].NormalMap, Input.Texcoord).rgb * 2.0f - 1.0f : Input.Normal);
    for(int j = 0; j < DIR_LIGHTS_COUNT; j++)
        color += CalculateDirectionalLight(u_materials[0], u_dirLights[j], normal);
    for(int j = 0; j < POINT_LIGHTS_COUNT; j++)
        color += CalculatePointLight(u_materials[0], u_pointLights[j], normal);
    for(int j = 0; j < SPOT_LIGHTS_COUNT; j++)
        color += CalculateSpotLight(u_materials[0], u_spotLights[j], normal);
    const float gamma = 2.2f;
    color = pow(color, vec3(1.0f / gamma));
    gl_FragColor = Input.Color * vec4(color, 1.0f);
}