struct Material
{
    bool HasRoughnessMap;
    sampler2D RoughnessMap;
    bool HasAlbedoMap;
    sampler2D AlbedoMap;
    bool HasEmissionMap;
    sampler2D EmissionMap;
    bool HasNormalMap;
    sampler2D NormalMap;
    bool HasMetallicMap;
    sampler2D MetallicMap;
    vec3 AmbientColor;
    vec3 DiffuseColor;
    vec3 SpecularColor;
    vec3 EmissionColor;
    float SpecularPower;
};

vec3 CalculateAmbientLight(Material material)
{
    vec3 materialAmbientColor = material.AmbientColor;
    if(material.HasAlbedoMap)
        materialAmbientColor *= texture(material.AlbedoMap, Input.Texcoord).rgb;
    return materialAmbientColor;
}

vec3 CalculateDiffuseLight(Material material, vec3 direction, vec3 normal)
{
    vec3 lightDirection = normalize(direction);
    float diffuseMultiplier = max(dot(normal, lightDirection), 0.0);
    vec3 materialDiffuseColor = material.DiffuseColor;
    if(material.HasAlbedoMap)
        materialDiffuseColor *= texture(material.AlbedoMap, Input.Texcoord).rgb;
    return materialDiffuseColor * diffuseMultiplier;
}

vec3 CalculateSpecularLight(Material material, vec3 direction, vec3 normal)
{
    vec3 viewDirection = normalize(perspCameraPos - Input.Position);
    float specularMultiplier;
    #if defined BLINN_PHONG
    vec3 halfwayDirection = normalize(normalize(direction) + viewDirection);
    specularMultiplier = pow(max(dot(normal, halfwayDirection), 0.0), material.SpecularPower);
    #elif defined PHONG
    vec3 reflectionDirection = reflect(-normalize(direction), normal);
    specularMultiplier = pow(max(dot(viewDirection, reflectionDirection), 0.0), material.SpecularPower);
    #else
    specularMultiplier = 1.0f;
    #endif
    vec3 materialSpecularColor = material.SpecularColor;
    if(material.HasMetallicMap)
        materialSpecularColor *= texture(material.MetallicMap, Input.Texcoord).rgb;
    return materialSpecularColor * specularMultiplier;
}

vec3 CalculateEmissionColor(Material material)
{
    vec3 materialEmissionColor = material.EmissionColor;
    if(material.HasEmissionMap)
        materialEmissionColor *= texture(material.EmissionMap, Input.Texcoord).rgb;
    return materialEmissionColor;
}

vec3 CalculateLight(Material material, vec3 direction, vec3 normal)
{
    vec3 result;
    result += CalculateAmbientLight(material);
    result += CalculateDiffuseLight(material, direction, normal);
    result += CalculateSpecularLight(material, direction, normal);
    result += CalculateEmissionColor(material);
    return result;
}