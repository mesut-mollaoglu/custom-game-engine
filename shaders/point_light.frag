#ifndef POINT_LIGHTS_COUNT
#define POINT_LIGHTS_COUNT 0
#endif

struct PointLight
{
    bool Enabled;
    vec3 Position;
    vec3 Color;
    float Constant;
    float Linear;
    float Quadratic;
};

vec3 CalculatePointLight(Material material, PointLight light, vec3 normal)
{
    if(!light.Enabled) return vec3(0.0);
    float attenuation = CalculateAttenuation(length(Input.Position - light.Position), light.Constant, light.Linear, light.Quadratic);
    return CalculateLight(material, light.Position - Input.Position, normal) * attenuation;
}