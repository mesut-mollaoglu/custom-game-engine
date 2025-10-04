struct DirectionalLight
{
    bool Enabled;
    vec3 Direction;
    vec3 Color;
};

vec3 CalculateDirectionalLight(Material material, DirectionalLight light, vec3 normal)
{
    if(!light.Enabled) return vec3(0.0f);
    return CalculateLight(material, light.Direction, normal) * light.Color;
}