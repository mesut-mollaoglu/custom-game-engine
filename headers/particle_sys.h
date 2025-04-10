#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

//TODO

enum class PSystemModes
{
    Gravity,
    Burst,
    Gradient
};

enum class PSysDeltaTime
{
    Scaled,
    NonScaled
};

struct Particle
{
    f32 m_duration = 0.0f;
    bool m_loop = false;
    f32 m_delay = 0.0f;
    vec2 m_velocity = vec2::zero();
    vec2 m_scale = vec2::one();
    ivec2 m_pos = ivec2::zero();
    f32 m_rotAngle = 0.0f;
    Color m_tintColor = Colors::White;
    PSysDeltaTime m_delta = PSysDeltaTime::Scaled;
};

struct SprParticle : Particle
{
    Sprite* m_sprSource;    
};

struct DecParticle : Particle
{
    Decal* m_decSource;  
};

struct DefParticle : Particle
{
    Color m_startColor;
    Color m_endColor;
};

struct PSystem
{
    bool m_isPaused = false;
    i32 m_maxParticles = 0;
    f32 m_elapsedTime = 0.0f;
};

#endif