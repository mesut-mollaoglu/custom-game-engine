#ifndef COMMON_H
#define COMMON_H

#include "includes.h"

namespace Shapes 
{
    struct Shape
    {
        vec2f pos = 0.0f;
        Color color = {0, 0, 0, 255};
        float rotation = 0.0f;
        virtual void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) { return; }
        virtual void Draw(GeometryBatch& batch) { return; }
        virtual void Rotate(float angle) { return; }
        virtual void SetRotation(float angle)
        {
            if(rotation != angle)
                Rotate(angle - rotation);
        }
    };

    struct Rect : Shape
    {
        vec2f size;
        Rect() = default;
        Rect(float x, float y, float w, float h, Color color) : size({w, h}) 
        {
            pos = {x, y};
            this->color = color;
        }
        void Rotate(float angle) override 
        {
            rotation += angle;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode currDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            const vec2f half_size = size * 0.5f;
            if(rotation == 0.0f)
            {
                window.DrawRect(pos.x - half_size.w, pos.y - half_size.h, size.w, size.h, color);
                return;
            }
            const vec2f pos1 = rotate<float>(rotation, -half_size);
            const vec2f pos2 = rotate<float>(rotation, {half_size.w, -half_size.h});
            const vec2f pos3 = rotate<float>(rotation, {-half_size.w, half_size.h});
            const vec2f pos4 = rotate<float>(rotation, half_size);
            window.DrawTriangle(pos1.x + pos.x, pos1.y + pos.y, pos2.x + pos.x, pos.y + pos2.y, pos.x + pos3.x, pos.y + pos3.y, color);
            window.DrawTriangle(pos2.x + pos.x, pos.y + pos2.y, pos3.x + pos.x, pos3.y + pos.y, pos4.x + pos.x, pos4.y + pos.y, color);
            window.SetDrawMode(currDrawMode);
        }
        void Draw(GeometryBatch& batch) override
        {
            batch.DrawRect(pos, size, rotation, color.vec4<float>());
        }
    };

    struct Circle : Shape
    {
        float radius;
        Circle() = default;
        Circle(float x, float y, float radius, Color color) : radius(radius) 
        {
            pos = {x, y};
            this->color = color;
        }
        void Rotate(float angle) override
        {
            return;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode currDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawCircle(pos.x, pos.y, radius, color);
            window.SetDrawMode(currDrawMode);
        }
        void Draw(GeometryBatch& batch) override
        {
            batch.DrawCircle(pos, radius, color.vec4<float>());
        }
        void SetRotation(float angle) override
        {
            return;
        }
    };

    struct Triangle : Shape
    {
        vec2f vertices[3], rotated[3];
        Triangle() = default;
        Triangle(const vec2f v1, const vec2f v2, const vec2f v3, vec2f pos, Color color) 
        {
            rotated[0] = vertices[0] = v1;
            rotated[1] = vertices[1] = v2;
            rotated[2] = vertices[2] = v3;
            pos = pos;
            this->color = color;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode currDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawTriangle(rotated[0].x + pos.x,
            rotated[0].y + pos.y, rotated[1].x + pos.x,
            rotated[1].y + pos.y, rotated[2].x + pos.x,
            rotated[2].y + pos.y, color);
            window.SetDrawMode(currDrawMode);
        }
        void Draw(GeometryBatch& batch) override
        {
            batch.DrawTriangle(
                pos + rotated[0],
                pos + rotated[1],
                pos + rotated[2],
                color.vec4<float>()
            );
        }
        void Rotate(float angle) override
        {
            rotation += angle;
            rotated[0] = rotate(rotation, vertices[0]);
            rotated[1] = rotate(rotation, vertices[1]);
            rotated[2] = rotate(rotation, vertices[2]);
        }
    };
};

inline constexpr bool Overlaps(const Shapes::Triangle& t, const Shapes::Circle& c)
{
    return BoundingSphere<float, 2>(c.pos, c.radius).Overlaps(
        t.rotated[0] + t.pos,
        t.rotated[1] + t.pos,
        t.rotated[2] + t.pos
    );
}

inline constexpr bool Overlaps(const Shapes::Triangle& t, const Shapes::Rect& r)
{
    return BoundingBox<float, 2>(r.pos, r.size, r.rotation).Overlaps(
        t.rotated[0] + t.pos,
        t.rotated[1] + t.pos,
        t.rotated[2] + t.pos
    );
}

inline constexpr bool Overlaps(const Shapes::Triangle& t0, const Shapes::Triangle& t1)
{
    return sat_overlap(
        std::array<vec2f, 3>
        {
            t0.rotated[0] + t0.pos,
            t0.rotated[1] + t0.pos,
            t0.rotated[2] + t0.pos
        },
        std::array<vec2f, 3>
        {
            t1.rotated[0] + t1.pos,
            t1.rotated[1] + t1.pos,
            t1.rotated[2] + t1.pos
        }
    );
}

inline constexpr bool Overlaps(const Shapes::Circle& c0, const Shapes::Circle& c1)
{
    return BoundingSphere<float, 2>(c0.pos, c0.radius).Overlaps(BoundingSphere<float, 2>(c1.pos, c1.radius));
}

inline constexpr bool Overlaps(const Shapes::Rect& r, const Shapes::Circle& c)
{
    return BoundingSphere<float, 2>(c.pos, c.radius).Overlaps(BoundingBox<float, 2>(r.pos, r.size, r.rotation));
}

inline constexpr bool Overlaps(const Shapes::Rect& r0, const Shapes::Rect& r1)
{
    return BoundingBox<float, 2>(r0.pos, r0.size, r0.rotation).Overlaps(BoundingBox<float, 2>(r1.pos, r1.size, r1.rotation)); 
}

inline constexpr bool Overlaps(const Shapes::Rect& r, const vec2f& p)
{
    return BoundingBox<float, 2>(r.pos, r.size, r.rotation).Overlaps(p);
}

inline constexpr bool Overlaps(const Shapes::Circle& c, const vec2f& p)
{
    return BoundingSphere<float, 2>(c.pos, c.radius).Overlaps(p);
}

enum class pShape
{
    Rect,
    Circle,
    Triangle,
    Pixel
};

enum class pMode
{
    Normal,
    Replay
};

enum class pBehaviour
{
    Sinusoidal,
    Directional
};

struct Particle
{
    Color color;
    vec2f size;
    vec2f velocity;
    vec2f gravity;
    float rotation;
    float maxDistance;
    pMode mode;
    pShape shape;
    pBehaviour behaviour;
    vec2f startPos;
    vec2f currentPos;
    bool dead = false;
    int replayed = 0;
};

struct ParticleDataPack
{
    Rect area;
    float maxSize;
    float minSize;
    float maxAngle;
    float minAngle;
    float maxSpeed;
    float minSpeed;
    std::vector<Color> colors;
};

inline void BuildTriangle(Shapes::Triangle& tri, const vec2f& size)
{
    tri.rotated[0] = tri.vertices[0] = {0.0f, size.h};
    tri.rotated[1] = tri.vertices[1] = {size.w * 0.5f, 0.0f};
    tri.rotated[2] = tri.vertices[2] = {-size.w * 0.5f, 0.0f};
};

struct ParticleSystem
{
    std::vector<Particle> particles;
    bool pause = false;
    float totalTime = 0.0f;
    int maxReplayAmount = 10;
    vec2f pos;
    ParticleSystem(vec2f pos = 0.0f) : pause(true), pos(pos) 
    {
        return;
    }
    inline void Generate(ParticleDataPack& data, int size, pMode mode, pShape shape, pBehaviour behaviour, vec2f gravity, float distance)
    {
        for(int i = 0; i < size; i++)
        {
            particles.push_back({
                data.colors[rand(0, (int)data.colors.size())],
                {
                    rand(data.minSize, data.maxSize),
                    rand(data.minSize, data.maxSize)
                },
                {
                    rand(data.minSpeed, data.maxSpeed),
                    rand(data.minSpeed, data.maxSpeed)
                },
                gravity, rand(data.minAngle, data.maxAngle),
                distance, mode, shape, behaviour,
                {
                    rand(data.area.sx, data.area.ex) + pos.x,
                    rand(data.area.sy, data.area.ey) + pos.y
                },
            });
            particles.back().currentPos = particles.back().startPos;
        }
    }
    inline void Update(float deltaTime)
    {
        if(pause) return;
        totalTime += deltaTime;
        for(auto& p : particles)
        {
            switch(p.behaviour)
            {
                case pBehaviour::Directional:
                {
                    p.currentPos.x += std::cos(p.rotation) * p.velocity.x * deltaTime;
                    p.currentPos.y += std::sin(p.rotation) * p.velocity.y * deltaTime;
                }
                break;
                case pBehaviour::Sinusoidal:
                {
                    p.currentPos.x += std::cos(p.rotation) * p.velocity.x * deltaTime;
                    p.currentPos.y += std::sin(p.rotation) * p.velocity.y * deltaTime;
                    p.currentPos.x += std::cos(totalTime * 0.2f) * p.velocity.x;
                    p.currentPos.y += std::sin(totalTime * 0.2f) * p.velocity.y;
                }
                break;
            }

            if(std::hypot(p.currentPos.x - p.startPos.x, p.currentPos.y - p.startPos.y) > p.maxDistance)
            {
                p.dead = ++p.replayed > maxReplayAmount;
                if(p.mode != pMode::Normal)
                    p.currentPos = p.startPos;
                else
                    p.dead = true;
            }   
                          
            p.currentPos += p.gravity;
        }

        particles.erase(std::remove_if(particles.begin(), particles.end(), [&](Particle& p){return p.dead;}), particles.end());
    }
    inline void Draw(Window& window, DrawMode drawMode = DrawMode::Normal)
    {
        if(pause) return;
        for(auto& p : particles)
            switch(p.shape)
            {
                case pShape::Rect:
                {
                    Shapes::Rect rect;
                    rect.color = p.color;
                    rect.size = p.size;
                    rect.pos = p.currentPos;
                    rect.SetRotation(totalTime);
                    rect.Draw(window, drawMode);
                }
                break;
                case pShape::Circle:
                {
                    Shapes::Circle circ;
                    circ.color = p.color;
                    circ.radius = p.size.w;
                    circ.pos = p.currentPos;
                    circ.Draw(window, drawMode);
                }
                break;
                case pShape::Triangle:
                {
                    Shapes::Triangle tri;
                    tri.color = p.color;
                    tri.pos = p.currentPos;
                    BuildTriangle(tri, p.size);
                    tri.SetRotation(totalTime);
                    tri.Draw(window, drawMode);
                }
                case pShape::Pixel: 
                {
                    window.SetPixel(p.currentPos.x, p.currentPos.y, p.color);
                }
                break;
            }
    }
};

struct Timer
{
    time_point now;
    float deltaTime;
    inline Timer()
    {
        now = steady_clock::now();
    }
    inline void Update()
    {
        deltaTime = std::chrono::duration<float>(steady_clock::now() - now).count();
        now = steady_clock::now();
    }
};

#endif