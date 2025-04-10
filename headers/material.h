#ifndef MATERIAL_H
#define MATERIAL_H

struct Material
{
    bool enabled = false;
    u32 albedoMap = 0u;
    u32 roughnessMap = 0u;
    u32 emissionMap = 0u;
    u32 normalMap = 0u;
    u32 metallicMap = 0u;
    vec3 ambientColor = 1.0f;
    vec3 diffuseColor = 1.0f;
    vec3 specularColor = 1.0f;
    vec3 emissionColor = 0.0f;
    f32 specularPower = 32.0f;
};

inline void SetMaterial(Shader* shader, const std::string& name, const Material& material)
{
    shader->SetUniformBool(name + ".Enabled", material.enabled);
    shader->SetUniformVector(name + ".AmbientColor", material.ambientColor);
    shader->SetUniformVector(name + ".DiffuseColor", material.diffuseColor);
    shader->SetUniformVector(name + ".SpecularColor", material.specularColor);
    shader->SetUniformVector(name + ".EmissionColor", material.emissionColor);
    shader->SetUniformFloat(name + ".SpecularPower", &material.specularPower);
    shader->SetUniformBool(name + ".HasAlbedoMap", material.albedoMap);
    shader->SetUniformBool(name + ".HasRoughnessMap", material.roughnessMap);
    shader->SetUniformBool(name + ".HasEmissionMap", material.emissionMap);
    shader->SetUniformBool(name + ".HasNormalMap", material.normalMap);
    shader->SetUniformBool(name + ".HasMetallicMap", material.metallicMap);
    shader->SetUniformInt(name + ".AlbedoMap", 0);
    shader->SetUniformInt(name + ".RoughnessMap", 1);
    shader->SetUniformInt(name + ".EmissionMap", 2);
    shader->SetUniformInt(name + ".NormalMap", 3);
    shader->SetUniformInt(name + ".MetallicMap", 4);
    BindTexture(material.albedoMap, 0);
    BindTexture(material.roughnessMap, 1);
    BindTexture(material.emissionMap, 2);
    BindTexture(material.normalMap, 3);
    BindTexture(material.metallicMap, 4);
}

#endif