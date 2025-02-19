#ifndef MATERIAL_H
#define MATERIAL_H

struct Material
{
    GLuint albedoMap = 0;
    GLuint roughnessMap = 0;
    GLuint emissionMap = 0;
    GLuint normalMap = 0;
    GLuint metallicMap = 0;
    vec3 ambient = 1.0f;
    vec3 diffuse = 1.0f;
    vec3 specular = 1.0f;
    vec3 emission = 0.0f;
    float specularPower = 32.0f;
};

inline void SetMaterial(Shader& shader, const std::string& name, const Material& material)
{
    shader.SetUniformVec(name + ".AmbientColor", material.ambient);
    shader.SetUniformVec(name + ".DiffuseColor", material.diffuse);
    shader.SetUniformVec(name + ".SpecularColor", material.specular);
    shader.SetUniformVec(name + ".EmissionColor", material.emission);
    shader.SetUniformFloat(name + ".SpecularPower", &material.specularPower);
    shader.SetUniformBool(name + ".HasAlbedoMap", material.albedoMap);
    shader.SetUniformBool(name + ".HasRoughnessMap", material.roughnessMap);
    shader.SetUniformBool(name + ".HasEmissionMap", material.emissionMap);
    shader.SetUniformBool(name + ".HasNormalMap", material.normalMap);
    shader.SetUniformBool(name + ".HasMetallicMap", material.metallicMap);
    shader.SetUniformInt(name + ".AlbedoMap", 0);
    shader.SetUniformInt(name + ".RoughnessMap", 1);
    shader.SetUniformInt(name + ".EmissionMap", 2);
    shader.SetUniformInt(name + ".NormalMap", 3);
    shader.SetUniformInt(name + ".MetallicMap", 4);
    BindTexture(material.albedoMap, 0);
    BindTexture(material.roughnessMap, 1);
    BindTexture(material.emissionMap, 2);
    BindTexture(material.normalMap, 3);
    BindTexture(material.metallicMap, 4);
}

#endif