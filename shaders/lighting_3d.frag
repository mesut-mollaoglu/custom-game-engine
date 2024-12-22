#version 330 core
#define POINT_LIGHTS_COUNT 4
#define DIR_LIGHTS_COUNT 4
#define SPOT_LIGHTS_COUNT 4
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
    return 1.0 / (constant + linear * distance + quadratic * distance * distance);
}

uniform vec3 perspCameraPos;

#include "material.frag"
#include "point_light.frag"
#include "dir_light.frag"
#include "spot_light.frag"

uniform Material meshMaterial;
uniform PointLight arrPointLights[POINT_LIGHTS_COUNT];
uniform SpotLight arrSpotLights[SPOT_LIGHTS_COUNT];
uniform DirectionalLight arrDirectionalLights[DIR_LIGHTS_COUNT];

void main()
{
    vec3 finalLightFrag;
    vec3 normal = normalize(meshMaterial.HasNormalMap ? texture(meshMaterial.NormalMap, Input.Texcoord).rgb * 2.0 - 1.0 : Input.Normal);
    #if (DIR_LIGHTS_COUNT > 0)
    for(int i = 0; i < DIR_LIGHTS_COUNT; i++)
        finalLightFrag += CalculateDirectionalLight(meshMaterial, arrDirectionalLights[i], normal);
    #endif
    #if (POINT_LIGHTS_COUNT > 0)
    for(int i = 0; i < POINT_LIGHTS_COUNT; i++)
        finalLightFrag += CalculatePointLight(meshMaterial, arrPointLights[i], normal);
    #endif
    #if (SPOT_LIGHTS_COUNT > 0)
    for(int i = 0; i < SPOT_LIGHTS_COUNT; i++)
        finalLightFrag += CalculateSpotLight(meshMaterial, arrSpotLights[i], normal);
    #endif
    const float gamma = 2.2;
    finalLightFrag = pow(finalLightFrag, vec3(1.0 / gamma));
    gl_FragColor = Input.Color * vec4(finalLightFrag, 1.0);
}