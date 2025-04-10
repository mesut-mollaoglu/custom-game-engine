#ifndef LIGHT_H
#define LIGHT_H

struct PointLight
{
    bool enabled = true;
    vec3 position = 0.0f;
    vec3 color = 1.0f;
    f32 constant = 1.0f;
    f32 linear = 0.09f;
    f32 quadratic = 0.032f;
};

struct DirectionalLight
{
    bool enabled = true;
    vec3 color = 1.0f;
    vec3 position = 0.0f;
    vec3 direction = vec3::forward();
};

struct SpotLight
{
    bool enabled = true;
    vec3 position = 0.0f;
    vec3 direction = vec3::forward();
    vec3 color = 1.0f;
    f32 cutOff;
    f32 outerCutOff;
    f32 constant = 1.0f;
    f32 linear = 0.09f;
    f32 quadratic = 0.032f;
};

#endif