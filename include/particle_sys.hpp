#ifndef PARTICLE_SYSTEM_HPP
#define PARTICLE_SYSTEM_HPP

//TODO

struct Particle
{
    Color colStart = Colors::White, colEnd = Colors::White;
    enum class Type : u8
    {
        String,
        Sprite,
        Decal,
        Default
    };
    struct Properties
    {
        Color tint = Colors::White;
        vec2 velocity = vec2::Zero();
        vec2 position = vec2::Zero();
        vec2 scale = vec2::One();
        vec2 shear = vec2::Zero();
        f32 rotation = 0.0f;
        f32 elapsedTime = 0.0f;
        Particle::Type type = Particle::Type::Default;
    } props;
    virtual void Draw(Window* window)
    {
        
    }
    virtual void Update(Window* window)
    {
        
    }
};

struct SpriteParticle : Particle
{
    Sprite* srcSprite = nullptr;
};

struct DecalParticle : Particle
{
    Decal* srcDecal = nullptr;
};

struct StringParticle : Particle
{
    std::string srcString = "";
};

class ParticleSystem
{
public:
    enum class Mode : u8
    {
        Gravity,
        Burst,
        Gradient
    };
private:
    bool m_sysPaused = false;
    i32 m_maxParticles = 0;
    std::vector<Particle> m_vecParticles;
    Window* m_windowHandle = nullptr;
public:
    inline ParticleSystem() = default;
    inline ParticleSystem(Window* windowHandle) : m_windowHandle(windowHandle) {}
public:
    inline void Emit(const Particle::Properties& p)
    {
        return;
    }
public:
    inline void Draw()
    {
        for(auto& p : m_vecParticles)
            p.Draw(m_windowHandle);
    }
    inline void Update()
    {
        for(auto& p : m_vecParticles)
            p.Update(m_windowHandle);
    }
};

#endif