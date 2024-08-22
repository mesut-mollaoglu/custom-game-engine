#ifndef MATERIAL_H
#define MATERIAL_H

#include "includes.h"

struct Material
{
    GLuint albedoMap = 0;
    GLuint roughnessMap = 0;
    GLuint emissionMap = 0;
    GLuint normalMap = 0;
    GLuint metallicMap = 0;
    vec3f ambient = 1.0f;
    vec3f diffuse = 1.0f;
    vec3f specular = 1.0f;
    vec3f emission = 0.0f;
    float specularPower = 32.0f;
};

inline void SetMaterial(Shader& instance, const std::string& name, const Material& material)
{
    instance.SetUniformVec(name + ".AmbientColor", material.ambient);
    instance.SetUniformVec(name + ".DiffuseColor", material.diffuse);
    instance.SetUniformVec(name + ".SpecularColor", material.specular);
    instance.SetUniformVec(name + ".EmissionColor", material.emission);
    instance.SetUniformFloat(name + ".SpecularPower", &material.specularPower);
    instance.SetUniformBool(name + ".HasAlbedoMap", material.albedoMap);
    instance.SetUniformBool(name + ".HasRoughnessMap", material.roughnessMap);
    instance.SetUniformBool(name + ".HasEmissionMap", material.emissionMap);
    instance.SetUniformBool(name + ".HasNormalMap", material.normalMap);
    instance.SetUniformBool(name + ".HasMetallicMap", material.metallicMap);
    instance.SetUniformInt(name + ".AlbedoMap", 0);
    instance.SetUniformInt(name + ".RoughnessMap", 1);
    instance.SetUniformInt(name + ".EmissionMap", 2);
    instance.SetUniformInt(name + ".NormalMap", 3);
    instance.SetUniformInt(name + ".MetallicMap", 4);
    BindTexture(material.albedoMap, 0);
    BindTexture(material.roughnessMap, 1);
    BindTexture(material.emissionMap, 2);
    BindTexture(material.normalMap, 3);
    BindTexture(material.metallicMap, 4);
}

#endif