#ifndef LIGHT_H
#define LIGHT_H

#include "includes.h"

struct PointLight
{
    bool enabled = false;
    vec3 position;
    vec3 color = 1.0f;
    float constant;
    float linear;
    float quadratic;
};

struct DirectionalLight
{
    bool enabled = false;
    vec3 color = 1.0f;
    vec3 position;
    vec3 direction;
};

struct SpotLight
{
    bool enabled = false;
    vec3 position;
    vec3 direction;
    vec3 color = 1.0f;
    float cutOff;
    float outerCutOff;
    float constant;
    float linear;
    float quadratic;
};

#endif