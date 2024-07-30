#ifndef COMMON_H
#define COMMON_H

#include "includes.h"

namespace Shapes 
{
    class Shape
    {
    protected:
        vec2f pos = 0.0f;
        Color color = {0, 0, 0, 255};
        float rotation = 0.0f;
    public:
        virtual void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) { return; }
        virtual void Draw(GeometryBatch& batch, float depth = 0.0f) { return; }
        virtual void Rotate(const float angle) { return; }
        virtual void Scale(const vec2f& scale) { return; }
        virtual void Translate(const vec2f& offset)
        {
            pos += offset;
        }
        virtual void SetPosition(const vec2f& offset)
        {
            if(pos != offset)
                Translate(offset - pos);
        }
        virtual void SetRotation(const float angle)
        {
            if(rotation != angle)
                Rotate(angle - rotation);
        }
        void SetColor(const Color& color)
        {
            this->color = color;
        }
        const vec2f GetPosition() const
        {
            return pos;
        }
        const Color GetColor() const
        {
            return color;
        }
        const float GetRotation() const
        {
            return rotation;
        }
        virtual ~Shape() {}
    };

    class Rect : public Shape
    {
    private:
        vec2f size;
        BoundingBox<float, 2> boundingBox;
    public:
        inline Rect() = default;
        inline Rect(const vec2f& pos, const vec2f& size, const Color& color) : size(size) 
        {
            boundingBox = BoundingBox<float, 2>(pos, size, 0.0f);
            this->pos = pos;
            this->color = color;
        }
        inline void Rotate(const float angle) override 
        {
            boundingBox.rotation += angle;
            rotation += angle;
        }
        inline void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            const vec2f half = size * 0.5f;
            if(mod((double)rotation, pi * 2.0) == 0.0)
            {
                window.DrawRect(pos - half, size, color);
                return;
            }
            const std::vector<vec2f> v = boundingBox.GetVertices();
            window.DrawTriangle(v[0], v[1], v[2], color);
            window.DrawTriangle(v[0], v[2], v[3], color);
            window.SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawRect(pos, size, rotation, ColorF(color), depth);
        }
        inline void SetSize(const vec2f& size)
        {
            boundingBox.size = this->size = size;
        }
        inline void Translate(const vec2f& offset) override
        {
            pos += offset;
            boundingBox.pos += offset;
        }
        inline const BoundingBox<float, 2>& GetBoundingBox() const
        {
            return boundingBox;
        }
        inline const bool Overlaps(const Rect& rect) const
        {
            return boundingBox.Overlaps(rect.GetBoundingBox());
        }
        inline const bool Overlaps(const vec2f& point) const
        {
            return boundingBox.Overlaps(point);
        }
        inline const vec2f GetSize() const
        {
            return size;
        }
    };

    class Circle : public Shape
    {
    private:
        float radius;
        BoundingSphere<float, 2> boundingSphere;
    public:
        inline Circle() = default;
        inline Circle(const vec2f& pos, const float radius, const Color& color) : radius(radius) 
        {
            boundingSphere = BoundingSphere<float, 2>(pos, radius);
            this->pos = pos;
            this->color = color;
        }
        inline void Rotate(const float angle) override
        {
            return;
        }
        inline void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawCircle(pos, radius, color);
            window.SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawCircle(pos, radius, ColorF(color), depth);
        }
        inline void SetRotation(float angle) override
        {
            return;
        }
        inline void SetSize(const float radius)
        {
            boundingSphere.radius = this->radius = radius;
        }
        inline void Translate(const vec2f& offset)
        {
            boundingSphere.pos += offset;
            pos += offset;
        }
        inline const BoundingSphere<float, 2>& GetBoundingSphere() const
        {
            return boundingSphere;
        }
        inline const bool Overlaps(const Circle& circle) const
        {
            return boundingSphere.Overlaps(circle.GetBoundingSphere());
        }
        inline const bool Overlaps(const Rect& rect) const
        {
            return boundingSphere.Overlaps(rect.GetBoundingBox());
        }
        inline const bool Overlaps(const vec2f& point) const
        {
            return boundingSphere.Overlaps(point);
        }
        inline const float GetRadius() const
        {
            return radius;
        }
    };

    class Triangle : public Shape
    {
    private:
        std::array<vec2f, 3> vertices;
    public:
        inline Triangle() = default;
        inline Triangle(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const vec2f& pos, const Color& color) 
        {
            SetVertices(pos0, pos1, pos2);
            this->pos = pos;
            this->color = color;
        }
        inline void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawTriangle(pos + vertices[0], pos + vertices[1], pos + vertices[2], color);
            window.SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawTriangle(pos + vertices[0], pos + vertices[1], pos + vertices[2], ColorF(color), depth);
        }
        inline void Rotate(const float angle) override
        {
            vertices[0] = rotate<float>(angle, vertices[0]);
            vertices[1] = rotate<float>(angle, vertices[1]);
            vertices[2] = rotate<float>(angle, vertices[2]);
            rotation += angle;
        }
        inline void SetVertices(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2)
        {
            vertices[0] = pos0;
            vertices[1] = pos1;
            vertices[2] = pos2;
        }
        inline const bool Overlaps(const Shapes::Circle& circle) const
        {
            return circle.GetBoundingSphere().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const Shapes::Triangle& triangle) const
        {
            return sat_overlap(GetVertices(), triangle.GetVertices());
        }
        inline const bool Overlaps(const Shapes::Rect& rect) const
        {
            return rect.GetBoundingBox().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const vec2f& point) const
        {
            return point_in_triangle(
                pos + vertices[0],
                pos + vertices[1],
                pos + vertices[2],
                point);
        }
        inline const std::vector<vec2f> GetVertices() const
        {
            return {pos + vertices[0], pos + vertices[1], pos + vertices[2]};
        }
    };

    class Line : public Shape
    {
    private:
        vec2f start, end;
    public:
        inline Line() = default;
        inline Line(const vec2f& start, const vec2f& end, const Color& color) : start(0.0f), end(end - start)
        {
            this->pos = start;
            this->color = color;
            rotation = std::atan2(end.y - start.y, end.x - start.x);
        }
        inline void Draw(Window& window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window.GetDrawMode();
            window.SetDrawMode(drawMode);
            window.DrawLine(pos + start, pos + end, color);
            window.SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& geoBatch, float depth = 0.0f) override
        {
            geoBatch.DrawLine(pos + start, pos + end, ColorF(color), depth);
        }
        inline void Rotate(const float angle) override
        {
            start = rotate<float>(angle, start);
            end = rotate<float>(angle, end);
            rotation += angle;
        }
        inline void SetVertices(const vec2f& start, const vec2f& end)
        {
            this->start = start;
            this->end = end;
        }
        inline const bool Overlaps(const Shapes::Triangle& triangle) const
        {
            return sat_overlap(triangle.GetVertices(), GetVertices());
        }
        inline const bool Overlaps(const Shapes::Rect& rect) const
        {
            return rect.GetBoundingBox().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const Shapes::Circle& circle) const
        {
            return circle.GetBoundingSphere().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const Shapes::Line& line) const
        {
            return sat_overlap(line.GetVertices(), GetVertices());
        }
        inline const bool Overlaps(const vec2f& point) const
        {
            return get_closest_distance_to_poly(GetVertices(), point) < epsilon;
        }
        inline const std::vector<vec2f> GetVertices() const
        {
            return {pos + start, pos + end};
        }
    };
};

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
    tri.SetVertices({0.0f, size.h}, {size.w * 0.5f, 0.0f}, {-size.w * 0.5f, 0.0f});
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
                .color = rand(data.colors), .size = RndPointInRect(data.size),
                .velocity = RndPointInRect(data.speed), .gravity = gravity, 
                .rotation = rand(data.pMinAngle, data.pMaxAngle),
                .maxDistance = distance, .mode = mode, .shape = shape, 
                .behaviour = behaviour, .startPos = RndPointInRect(data.area) + pos
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
                    rect.SetColor(p.color);
                    rect.SetSize(p.size);
                    rect.SetPosition(p.currentPos);
                    rect.SetRotation(totalTime);
                    rect.Draw(window, drawMode);
                }
                break;
                case pShape::Circle:
                {
                    Shapes::Circle circle;
                    circle.SetColor(p.color);
                    circle.SetSize(p.size.w);
                    circle.SetPosition(p.currentPos);
                    circle.Draw(window, drawMode);
                }
                break;
                case pShape::Triangle:
                {
                    Shapes::Triangle triangle;
                    triangle.SetColor(p.color);
                    triangle.SetPosition(p.currentPos);
                    BuildTriangle(triangle, p.size);
                    triangle.SetRotation(totalTime);
                    triangle.Draw(window, drawMode);
                }
                case pShape::Line:
                {
                    Shapes::Line line;
                    line.SetColor(p.color);
                    line.SetVertices(p.currentPos, p.currentPos + p.size);
                    line.SetRotation(std::atan2(p.size.y, p.size.x) + totalTime);
                    line.Draw(window, drawMode);
                }
                case pShape::Pixel: 
                {
                    window.SetPixel(p.currentPos, p.color);
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