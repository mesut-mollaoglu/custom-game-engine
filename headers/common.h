#ifndef COMMON_H
#define COMMON_H

#include "includes.h"

namespace Shapes 
{
    struct Shape
    {
        v2f position = 0.0f;
        Color color = {0, 0, 0, 255};
        float currentAngle = 0.0f;
        virtual void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) { return; }
        virtual void Rotate(float angle) { return; }
        virtual void SetRotation(float angle)
        {
            if(currentAngle != angle)
                Rotate(angle - currentAngle);
        }
    };

    struct Rect : Shape
    {
        v2f size;
        Rect() = default;
        Rect(float x, float y, float w, float h, Color color) : size({w, h}) 
        {
            position = {x, y};
            this->color = color;
        }
        void Rotate(float angle) override 
        {
            currentAngle += angle;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode currDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            const v2f half_size = size * 0.5f;
            if(currentAngle == 0.0f)
            {
                window.DrawRect(position.x - half_size.w, position.y - half_size.h, size.w, size.h, color);
                return;
            }
            const v2f pos1 = rotate(currentAngle, -half_size);
            const v2f pos2 = rotate(currentAngle, {half_size.w, -half_size.h});
            const v2f pos3 = rotate(currentAngle, {-half_size.w, half_size.h});
            const v2f pos4 = rotate(currentAngle, half_size);
            window.DrawTriangle(pos1.x + position.x, pos1.y + position.y, pos2.x + position.x, position.y + pos2.y, position.x + pos3.x, position.y + pos3.y, color);
            window.DrawTriangle(pos2.x + position.x, position.y + pos2.y, pos3.x + position.x, pos3.y + position.y, pos4.x + position.x, pos4.y + position.y, color);
            window.SetDrawMode(currDrawMode);
        }
    };

    struct Circle : Shape
    {
        float radius;
        Circle() = default;
        Circle(float x, float y, float radius, Color color) : radius(radius) 
        {
            position = {x, y};
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
            window.DrawCircle(position.x, position.y, radius, color);
            window.SetDrawMode(currDrawMode);
        }
        void SetRotation(float angle) override
        {
            return;
        }
    };

    struct Triangle : Shape
    {
        v2f vertices[3], rotated[3];
        Triangle() = default;
        Triangle(const v2f v1, const v2f v2, const v2f v3, v2f pos, Color color) 
        {
            rotated[0] = vertices[0] = v1;
            rotated[1] = vertices[1] = v2;
            rotated[2] = vertices[2] = v3;
            position = pos;
            this->color = color;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode currDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawTriangle(rotated[0].x + position.x,
            rotated[0].y + position.y, rotated[1].x + position.x,
            rotated[1].y + position.y, rotated[2].x + position.x,
            rotated[2].y + position.y, color);
            window.SetDrawMode(currDrawMode);
        }
        void Rotate(float angle) override
        {
            currentAngle += angle;
            rotated[0] = rotate(currentAngle, vertices[0]);
            rotated[1] = rotate(currentAngle, vertices[1]);
            rotated[2] = rotate(currentAngle, vertices[2]);
        }
    };
};

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
    v2f size;
    v2f velocity;
    v2f gravity;
    float rotation;
    float maxDistance;
    pMode mode;
    pShape shape;
    pBehaviour behaviour;
    v2f startPos;
    v2f currentPos;
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

inline void BuildTriangle(Shapes::Triangle& tri, const v2f& size)
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
    v2f position;
    ParticleSystem(v2f position = 0.0f) : pause(true), position(position) 
    {
        return;
    }
    inline void Generate(ParticleDataPack& data, int size, pMode mode, pShape shape, pBehaviour behaviour, v2f gravity, float distance)
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
                    rand(data.area.sx, data.area.ex) + position.x,
                    rand(data.area.sy, data.area.ey) + position.y
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
                    p.currentPos.x += std::cos(p.rotation) * p.velocity.x;
                    p.currentPos.y += std::sin(p.rotation) * p.velocity.y;
                }
                break;
                case pBehaviour::Sinusoidal:
                {
                    p.currentPos.x += std::cos(p.rotation) * p.velocity.x;
                    p.currentPos.y += std::sin(p.rotation) * p.velocity.y;
                    p.currentPos.x += std::cos(totalTime * 0.2f) * p.velocity.x;
                    p.currentPos.y += std::sin(totalTime * 0.2f) * p.velocity.y;
                }
                break;
            }

            if(p.maxDistance > 0.0f && std::hypot(p.currentPos.x - p.startPos.x, p.currentPos.y - p.startPos.y) > p.maxDistance)
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
                    rect.position = p.currentPos;
                    rect.SetRotation(totalTime);
                    rect.Draw(window, drawMode);
                }
                break;
                case pShape::Circle:
                {
                    Shapes::Circle circ;
                    circ.color = p.color;
                    circ.radius = p.size.w;
                    circ.position = p.currentPos;
                    circ.Draw(window, drawMode);
                }
                break;
                case pShape::Triangle:
                {
                    Shapes::Triangle tri;
                    tri.color = p.color;
                    tri.position = p.currentPos;
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