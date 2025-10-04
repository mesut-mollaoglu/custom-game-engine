#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light
{
public:
    enum class Type : u8
    {
        Point,
        Directional,
        Spot
    };
public:
    bool enabled = false;
    vec3 lightPos = vec3::Zero();
    vec3 colLight = vec3::One();
public:
    virtual void Set(Shader& shader, const std::string& s) = 0;
    virtual Type GetType() const = 0;
};

class PointLight : public Light
{
public:
    Light::Type GetType() const override;
    void Set(Shader& shader, const std::string& s) override;
public:
    f32 constant = 1.0f;
    f32 linear = 0.09f;
    f32 quadratic = 0.032f;
};

class DirectionalLight : public Light
{
public:
    Light::Type GetType() const override;
    void Set(Shader& shader, const std::string& s) override;
public:
    vec3 direction = vec3::Forward();
};

class SpotLight : public Light
{
public:
    Light::Type GetType() const override;
    void Set(Shader& shader, const std::string& s) override;
public:
    vec3 direction = vec3::Forward();
    f32 cutOff;
    f32 outerCutOff;
    f32 constant = 1.0f;
    f32 linear = 0.09f;
    f32 quadratic = 0.032f;
};

//for debugging
inline std::ostream& operator<<(std::ostream& os, const Light::Type& t)
{
    switch(t)
    {
        case Light::Type::Point: return os << "Light::Type::Point";
        case Light::Type::Spot: return os << "Light::Type::Spot";
        case Light::Type::Directional : return os << "Light::Type::Directional";
    }
    return os;
}

#endif

#ifdef LIGHT_HPP
#undef LIGHT_HPP

inline Light::Type PointLight::GetType() const
{
    return Light::Type::Point;
}

inline void PointLight::Set(Shader& shader, const std::string& s)
{
    shader.SetUniform(s + ".Enabled", enabled);
    shader.SetUniform(s + ".Position", lightPos);
    shader.SetUniform(s + ".Color", colLight);
    shader.SetUniform(s + ".Constant", constant);
    shader.SetUniform(s + ".Linear", linear);
    shader.SetUniform(s + ".Quadratic", quadratic);
}

inline Light::Type DirectionalLight::GetType() const
{
    return Light::Type::Directional;
}

inline void DirectionalLight::Set(Shader& shader, const std::string& s)
{
    shader.SetUniform(s + ".Enabled", enabled);
    shader.SetUniform(s + ".Direction", direction);
    shader.SetUniform(s + ".Color", colLight);
}

inline Light::Type SpotLight::GetType() const
{
    return Light::Type::Spot;
}

inline void SpotLight::Set(Shader& shader, const std::string& s)
{
    shader.SetUniform(s + ".Enabled", enabled);
    shader.SetUniform(s + ".Color", colLight);
    shader.SetUniform(s + ".Constant", constant);
    shader.SetUniform(s + ".Linear", linear);
    shader.SetUniform(s + ".Quadratic", quadratic);
    shader.SetUniform(s + ".CutOff", cutOff);
    shader.SetUniform(s + ".OuterCutOff", outerCutOff);
    shader.SetUniform(s + ".Position", lightPos);
    shader.SetUniform(s + ".Direction", direction);
}

#endif