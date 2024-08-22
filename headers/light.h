#ifndef LIGHT_H
#define LIGHT_H

#include "includes.h"

struct PointLight
{
    bool enabled = false;
    vec3f position;
    vec3f color = 1.0f;
    float constant;
    float linear;
    float quadratic;
};

struct DirectionalLight
{
    bool enabled = false;
    vec3f color = 1.0f;
    vec3f position;
    vec3f direction;
};

struct SpotLight
{
    bool enabled = false;
    vec3f position;
    vec3f direction;
    vec3f color = 1.0f;
    float cutOff;
    float outerCutOff;
    float constant;
    float linear;
    float quadratic;
};

#endif