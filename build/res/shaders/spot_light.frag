struct SpotLight
{
    bool Enabled;
    vec3 Position;
    vec3 Direction;
    vec3 Color;
    float CutOff;
    float OuterCutOff;
    float Constant;
    float Linear;
    float Quadratic;
};

vec3 CalculateSpotLight(Material material, SpotLight light, vec3 normal)
{
    if(!light.Enabled) return vec3(0.0);
    float theta = dot(normalize(light.Position - Input.Position), normalize(light.Direction));
    float intensity = clamp((theta - light.OuterCutOff) / (light.CutOff - light.OuterCutOff), 0.0, 1.0);
    float distance = length(light.Position - Input.Position);
    float attenuation = CalculateAttenuation(distance, light.Constant, light.Linear, light.Quadratic);
    return CalculateLight(material, light.Position - Input.Position, normal) * light.Color * attenuation * intensity;
}