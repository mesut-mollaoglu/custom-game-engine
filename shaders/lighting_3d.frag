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
    return 1.0 / (constant + linear * distance + quadratic * distance * distance);
}

uniform vec3 perspCameraPos;

#include "material.frag"
#include "point_light.frag"
#include "dir_light.frag"
#include "spot_light.frag"

uniform Material arrMaterials[MATERIAL_COUNT];
uniform PointLight arrPointLights[POINT_LIGHTS_COUNT];
uniform SpotLight arrSpotLights[SPOT_LIGHTS_COUNT];
uniform DirectionalLight arrDirectionalLights[DIR_LIGHTS_COUNT];

void main()
{
    vec3 finalColor;
    for(int i = 0; i < MATERIAL_COUNT; i++)
    {
        vec3 normal = normalize(arrMaterials[i].HasNormalMap ? texture(arrMaterials[i].NormalMap, Input.Texcoord).rgb * 2.0 - 1.0 : Input.Normal);
    #if (DIR_LIGHTS_COUNT > 0)
        for(int j = 0; j < DIR_LIGHTS_COUNT; j++)
            finalColor += CalculateDirectionalLight(arrMaterials[i], arrDirectionalLights[j], normal);
    #endif
    #if (POINT_LIGHTS_COUNT > 0)
        for(int j = 0; j < POINT_LIGHTS_COUNT; j++)
            finalColor += CalculatePointLight(arrMaterials[i], arrPointLights[j], normal);
    #endif
    #if (SPOT_LIGHTS_COUNT > 0)
        for(int j = 0; j < SPOT_LIGHTS_COUNT; j++)
            finalColor += CalculateSpotLight(arrMaterials[i], arrSpotLights[j], normal);
    #endif
    }
    const float gamma = 2.2;
    finalColor = pow(finalColor, vec3(1.0 / gamma));
    gl_FragColor = Input.Color * vec4(finalColor, 1.0);
}