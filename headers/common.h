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
        virtual const std::vector<vec2f> GetVertices() const { return {}; }
        virtual void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) { return; }
        virtual void Draw(GeometryBatch& batch, float depth = 0.0f) { return; }
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
        Rect(const vec2f& pos, const vec2f& size, const Color& color) : size(size) 
        {
            this->pos = pos;
            this->color = color;
        }
        void Rotate(float angle) override 
        {
            rotation += angle;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            const vec2f half = size * 0.5f;
            if(rotation == 0.0f)
            {
                window.DrawRect(pos.x - half.w, pos.y - half.h, size.w, size.h, color);
                return;
            }
            const std::vector<vec2f> v = GetVertices();
            window.DrawTriangle(v[0].x, v[0].y, v[1].x, v[1].y, v[2].x, v[2].y, color);
            window.DrawTriangle(v[1].x, v[1].y, v[2].x, v[2].y, v[3].x, v[3].y, color);
            window.SetDrawMode(prevDrawMode);
        }
        void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawRect(pos, size, rotation, color.vec4<float>(), depth);
        }
        const std::vector<vec2f> GetVertices() const override
        {
            const vec2f half = size * 0.5f;
            return 
            {
                pos + rotate<float>(rotation, -half),
                pos + rotate<float>(rotation, {half.w, -half.h}),
                pos + rotate<float>(rotation, {-half.w, half.h}),
                pos + rotate<float>(rotation, half)
            };
        }
    };

    struct Circle : Shape
    {
        float radius;
        Circle() = default;
        Circle(const vec2f& pos, const float radius, const Color& color) : radius(radius) 
        {
            this->pos = pos;
            this->color = color;
        }
        void Rotate(float angle) override
        {
            return;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawCircle(pos.x, pos.y, radius, color);
            window.SetDrawMode(prevDrawMode);
        }
        void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawCircle(pos, radius, color.vec4<float>(), depth);
        }
        void SetRotation(float angle) override
        {
            return;
        }
    };

    struct Triangle : Shape
    {
        std::array<vec2f, 3> vertices;
        Triangle() = default;
        Triangle(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const vec2f& pos, const Color& color) 
        {
            vertices[0] = pos0;
            vertices[1] = pos1;
            vertices[2] = pos2;
            this->pos = pos;
            this->color = color;
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            const std::vector<vec2f> v = GetVertices();
            window.DrawTriangle(v[0].x, v[0].y, v[1].x, v[1].y, v[2].x, v[2].y, color);
            window.SetDrawMode(prevDrawMode);
        }
        void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            const std::vector<vec2f> v = GetVertices();
            batch.DrawTriangle(v[0], v[1], v[2], color.vec4<float>(), depth);
        }
        void Rotate(float angle) override
        {
            rotation += angle;
        }
        const std::vector<vec2f> GetVertices() const override
        {
            return
            {
                pos + rotate<float>(rotation, vertices[0]),
                pos + rotate<float>(rotation, vertices[1]),
                pos + rotate<float>(rotation, vertices[2])
            };
        }
    };

    struct Line : Shape
    {
        float length = 0;
        Line() = default;
        Line(const float len, const vec2f& pos, const Color& color) : length(len)
        {
            this->pos = pos;
            this->color = color;
        }
        Line(const vec2f& start, const vec2f& end, const Color& color) : length((start - end).mag())
        {
            this->pos = start;
            this->color = color;
            rotation = std::atan2(end.y - start.y, end.x - start.x);
        }
        void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            const std::vector<vec2f> v = GetVertices();
            window.DrawLine(v[0].x, v[0].y, v[1].x, v[1].y, color);
            window.SetDrawMode(prevDrawMode);
        }
        void Draw(GeometryBatch& geoBatch, float depth = 0.0f) override
        {
            const std::vector<vec2f> v = GetVertices();
            geoBatch.DrawLine(v[0], v[1], color.vec4<float>(), depth);
        }
        void Rotate(const float angle) override
        {
            rotation += angle;
        }
        const std::vector<vec2f> GetVertices() const override
        {
            return 
            {
                pos + rotate<float>(rotation, 0.0f),
                pos + rotate<float>(rotation, {length, 0.0f})
            };
        }
    };
};

inline bool Overlaps(const Shapes::Triangle& triangle, const Shapes::Circle& circle)
{
    return BoundingSphere<float, 2>(circle.pos, circle.radius).Overlaps(triangle.GetVertices());
}

inline bool Overlaps(const Shapes::Triangle& triangle, const Shapes::Rect& rect)
{
    return BoundingBox<float, 2>(rect.pos, rect.size, rect.rotation).Overlaps(triangle.GetVertices());
}

inline bool Overlaps(const Shapes::Triangle& triangle0, const Shapes::Triangle& triangle1)
{
    return sat_overlap(triangle0.GetVertices(), triangle1.GetVertices());
}

inline constexpr bool Overlaps(const Shapes::Circle& circle0, const Shapes::Circle& circle1)
{
    return BoundingSphere<float, 2>(circle0.pos, circle0.radius).Overlaps(BoundingSphere<float, 2>(circle1.pos, circle1.radius));
}

inline bool Overlaps(const Shapes::Rect& rect, const Shapes::Circle& circle)
{
    return BoundingSphere<float, 2>(circle.pos, circle.radius).Overlaps(BoundingBox<float, 2>(rect.pos, rect.size, rect.rotation));
}

inline bool Overlaps(const Shapes::Rect& rect0, const Shapes::Rect& rect1)
{
    return BoundingBox<float, 2>(rect0.pos, rect0.size, rect0.rotation).Overlaps(BoundingBox<float, 2>(rect1.pos, rect1.size, rect1.rotation)); 
}

inline bool Overlaps(const Shapes::Rect& rect, const vec2f& point)
{
    return BoundingBox<float, 2>(rect.pos, rect.size, rect.rotation).Overlaps(point);
}

inline constexpr bool Overlaps(const Shapes::Circle& circle, const vec2f& point)
{
    return BoundingSphere<float, 2>(circle.pos, circle.radius).Overlaps(point);
}

inline bool Overlaps(const Shapes::Triangle& triangle, const vec2f& point)
{
    const std::vector<vec2f> v = triangle.GetVertices();
    return point_in_triangle(v[0], v[1], v[2], point);
}

inline bool Overlaps(const Shapes::Rect& rect, const Shapes::Line& line)
{
    return BoundingBox<float, 2>(rect.pos, rect.size, rect.rotation).Overlaps(line.GetVertices());
}

inline bool Overlaps(const Shapes::Circle& circle, const Shapes::Line& line)
{
    return BoundingSphere<float, 2>(circle.pos, circle.radius).Overlaps(line.GetVertices());
}

inline bool Overlaps(const Shapes::Triangle& triangle, const Shapes::Line& line)
{
    return sat_overlap(triangle.GetVertices(), line.GetVertices());
}

inline bool Overlaps(const Shapes::Line& line, const vec2f& point)
{
    return get_closest_distance_to_poly(line.GetVertices(), point) < epsilon;
}

enum class pShape
{
    Rect,
    Circle,
    Triangle,
    Line,
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
    int selfReplayCount = 0;
};

struct ParticleDataPack
{
    Rect<float> area;
    Rect<float> size;
    Rect<float> speed;
    float pMaxAngle;
    float pMinAngle;
    std::vector<Color> colors;
};

inline void BuildTriangle(Shapes::Triangle& tri, const vec2f& size)
{
    tri.vertices[0] = {0.0f, size.h};
    tri.vertices[1] = {size.w * 0.5f, 0.0f};
    tri.vertices[2] = {-size.w * 0.5f, 0.0f};
};

template <class T> inline T rand(const std::vector<T>& vec)
{
    return vec[rand<std::size_t>(0, vec.size())];
}

inline vec2f vec_from_angle(const float angle)
{
    return {std::cos(angle), std::sin(angle)};
}

struct ParticleSystem
{
    std::vector<Particle> vecParticles;
    bool pause = false;
    float totalTime = 0.0f;
    int maxReplayCount = 10;
    vec2f pos;
    ParticleSystem(vec2f pos = 0.0f) : pause(true), pos(pos) 
    {
        return;
    }
    inline void Generate(
        ParticleDataPack& data, int size, pMode mode, 
        pShape shape, pBehaviour behaviour, 
        vec2f gravity, float distance)
    {
        for(std::size_t i = 0; i < size; i++)
        {
            vecParticles.push_back({
                .color = rand(data.colors), .size = RndVec(data.size),
                .velocity = RndVec(data.speed), .gravity = gravity, 
                .rotation = rand(data.pMinAngle, data.pMaxAngle),
                .maxDistance = distance, .mode = mode, .shape = shape, 
                .behaviour = behaviour, .startPos = RndVec(data.area) + pos
            });
            vecParticles.back().currentPos = vecParticles.back().startPos;
        }
    }
    inline void Update(float deltaTime)
    {
        if(pause) return;
        totalTime += deltaTime;
        for(auto& p : vecParticles)
        {
            switch(p.behaviour)
            {
                case pBehaviour::Directional:
                    p.currentPos += vec_from_angle(p.rotation) * p.velocity * deltaTime;
                break;
                case pBehaviour::Sinusoidal:
                {
                    p.currentPos += vec_from_angle(p.rotation) * p.velocity * deltaTime;
                    p.currentPos += vec_from_angle(totalTime * 0.2f) * p.velocity;
                }
                break;
            }

            if((p.currentPos - p.startPos).mag() > p.maxDistance)
            {
                p.dead = ++p.selfReplayCount > maxReplayCount;
                if(p.mode != pMode::Normal)
                    p.currentPos = p.startPos;
                else
                    p.dead = true;
            }   
                          
            p.currentPos += p.gravity * deltaTime;
        }

        vecParticles.erase(std::remove_if(vecParticles.begin(), vecParticles.end(), [&](Particle& p)
        {
            return p.dead;
        }), vecParticles.end());
    }
    inline void Draw(Window& window, DrawMode drawMode = DrawMode::Normal)
    {
        if(pause) return;
        for(auto& p : vecParticles)
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
                    Shapes::Circle circle;
                    circle.color = p.color;
                    circle.radius = p.size.w;
                    circle.pos = p.currentPos;
                    circle.Draw(window, drawMode);
                }
                break;
                case pShape::Triangle:
                {
                    Shapes::Triangle triangle;
                    triangle.color = p.color;
                    triangle.pos = p.currentPos;
                    BuildTriangle(triangle, p.size);
                    triangle.SetRotation(totalTime);
                    triangle.Draw(window, drawMode);
                }
                case pShape::Line:
                {
                    Shapes::Line line;
                    line.color = p.color;
                    line.pos = p.currentPos;
                    line.length = p.size.mag();
                    line.SetRotation(std::atan2(p.size.y, p.size.x) + totalTime);
                    line.Draw(window, drawMode);
                }
                case pShape::Pixel: 
                {
                    window.SetPixel(p.currentPos.x, p.currentPos.y, p.color);
                }
                break;
            }
    }
    inline void Clear()
    {
        vecParticles.clear();
    }
};

#endif