#ifndef MATERIAL_HPP
#define MATERIAL_HPP

struct Material
{
    bool enabled = false;
    u32 mapAlbedo = 0u;
    u32 mapRoughness = 0u;
    u32 mapEmission = 0u;
    u32 mapNormal = 0u;
    u32 mapMetallic = 0u;
    vec3 colAmbient = vec3::One();
    vec3 colDiffuse = vec3::One();
    vec3 colSpecular = vec3::One();
    vec3 colEmission = vec3::Zero();
    inline void Set(Shader* shader, const std::string& s)
    {
        shader->SetUniform(s + ".Enabled", enabled);
        shader->SetUniform(s + ".AmbientColor", colAmbient);
        shader->SetUniform(s + ".DiffuseColor", colDiffuse);
        shader->SetUniform(s + ".SpecularColor", colSpecular);
        shader->SetUniform(s + ".EmissionColor", colEmission);
        shader->SetUniform(s + ".HasAlbedoMap", mapAlbedo);
        shader->SetUniform(s + ".HasRoughnessMap", mapRoughness);
        shader->SetUniform(s + ".HasEmissionMap", mapEmission);
        shader->SetUniform(s + ".HasNormalMap", mapNormal);
        shader->SetUniform(s + ".HasMetallicMap", mapMetallic);
        shader->SetUniform(s + ".AlbedoMap", 0);
        shader->SetUniform(s + ".RoughnessMap", 1);
        shader->SetUniform(s + ".EmissionMap", 2);
        shader->SetUniform(s + ".NormalMap", 3);
        shader->SetUniform(s + ".MetallicMap", 4);
        BindTexture(mapAlbedo, 0);
        BindTexture(mapRoughness, 1);
        BindTexture(mapEmission, 2);
        BindTexture(mapNormal, 3);
        BindTexture(mapMetallic, 4);
    }
};

#endif