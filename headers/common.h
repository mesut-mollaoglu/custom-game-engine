#ifndef COMMON_H
#define COMMON_H

namespace Shapes 
{
    class Shape
    {
    protected:
        vec2 m_pos = 0.0f;
        Color m_color = {0, 0, 0, 255};
        float m_rotation = 0.0f;
    public:
        virtual void Draw(Window* window, DrawMode drawMode = DrawMode::Normal) { return; }
        virtual void Draw(GeometryBatch& batch, float depth = 0.0f) { return; }
        virtual void Rotate(float angle) { return; }
        virtual void Scale(const vec2& scale) { return; }
        virtual void Translate(const vec2& offset)
        {
            m_pos += offset;
        }
        virtual void SetPosition(const vec2& offset)
        {
            if(m_pos != offset)
                Translate(offset - m_pos);
        }
        virtual void SetRotation(float angle)
        {
            if(m_rotation != angle)
                Rotate(angle - m_rotation);
        }
        inline void SetColor(const Color& color)
        {
            m_color = color;
        }
        inline const vec2& GetPosition() const
        {
            return m_pos;
        }
        inline const Color& GetColor() const
        {
            return m_color;
        }
        inline float GetRotation() const
        {
            return m_rotation;
        }
        virtual ~Shape() {}
    };

    class Rect : public Shape
    {
    private:
        vec2 m_size;
        BoundingBox<float, 2> m_bBox;
    public:
        inline Rect() = default;
        inline Rect(const vec2& pos, const vec2& size, const Color& color) : m_size(size) 
        {
            m_bBox = BoundingBox<float, 2>(pos, size, 0.0f);
            m_pos = pos;
            m_color = color;
        }
        inline void Rotate(float angle) override 
        {
            m_bBox.rotation += angle;
            m_rotation += angle;
        }
        inline void Draw(Window* window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window->GetDrawMode();
            window->SetDrawMode(drawMode);
            const vec2 half = m_size * 0.5f;
            if(mod((double)m_rotation, pi * 2.0) == 0.0)
            {
                window->DrawRect(m_pos - half, m_size, m_color);
                return;
            }
            const std::vector<vec2> v = m_bBox.GetVertices();
            window->DrawTriangle(v[0], v[1], v[2], m_color);
            window->DrawTriangle(v[0], v[2], v[3], m_color);
            window->SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawRect(m_pos, m_size, m_rotation, m_color, depth);
        }
        inline void SetSize(const vec2& size)
        {
            m_bBox.size = m_size = size;
        }
        inline void Translate(const vec2& offset) override
        {
            m_pos += offset;
            m_bBox.pos += offset;
        }
        inline const BoundingBox<float, 2>& GetBBox() const
        {
            return m_bBox;
        }
        inline const bool Overlaps(const Rect& rect) const
        {
            return m_bBox.Overlaps(rect.GetBBox());
        }
        inline const bool Overlaps(const vec2& point) const
        {
            return m_bBox.Overlaps(point);
        }
        inline const vec2& GetSize() const
        {
            return m_size;
        }
    };

    class Circle : public Shape
    {
    private:
        float m_radius;
        BoundingSphere<float, 2> m_bCircle;
    public:
        inline Circle() = default;
        inline Circle(const vec2& pos, float radius, const Color& color) : m_radius(radius) 
        {
            m_bCircle = BoundingSphere<float, 2>(pos, radius);
            m_pos = pos;
            m_color = color;
        }
        inline void Rotate(float angle) override
        {
            return;
        }
        inline void Draw(Window* window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window->GetDrawMode();
            window->SetDrawMode(drawMode);
            window->DrawCircle(m_pos, m_radius, m_color);
            window->SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawCircle(m_pos, m_radius, m_color, depth);
        }
        inline void SetRotation(float angle) override
        {
            return;
        }
        inline void SetSize(float radius)
        {
            m_bCircle.radius = m_radius = radius;
        }
        inline void Translate(const vec2& offset)
        {
            m_bCircle.pos += offset;
            m_pos += offset;
        }
        inline const BoundingSphere<float, 2>& GetBCircle() const
        {
            return m_bCircle;
        }
        inline const bool Overlaps(const Circle& circle) const
        {
            return m_bCircle.Overlaps(circle.GetBCircle());
        }
        inline const bool Overlaps(const Rect& rect) const
        {
            return m_bCircle.Overlaps(rect.GetBBox());
        }
        inline const bool Overlaps(const vec2& point) const
        {
            return m_bCircle.Overlaps(point);
        }
        inline float GetRadius() const
        {
            return m_radius;
        }
    };

    class Triangle : public Shape
    {
    private:
        std::array<vec2, 3> m_arrVertices;
    public:
        inline Triangle() = default;
        inline Triangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec2& pos, const Color& color) 
        {
            SetVertices(pos0, pos1, pos2);
            m_pos = pos;
            m_color = color;
        }
        inline void Draw(Window* window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window->GetDrawMode();
            window->SetDrawMode(drawMode);
            window->DrawTriangle(m_pos + m_arrVertices[0], m_pos + m_arrVertices[1], m_pos + m_arrVertices[2], m_color);
            window->SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& batch, float depth = 0.0f) override
        {
            batch.DrawTriangle(m_pos + m_arrVertices[0], m_pos + m_arrVertices[1], m_pos + m_arrVertices[2], m_color, depth);
        }
        inline void Rotate(float angle) override
        {
            m_arrVertices[0] = rotate<float>(angle, m_arrVertices[0]);
            m_arrVertices[1] = rotate<float>(angle, m_arrVertices[1]);
            m_arrVertices[2] = rotate<float>(angle, m_arrVertices[2]);
            m_rotation += angle;
        }
        inline void SetVertices(const vec2& pos0, const vec2& pos1, const vec2& pos2)
        {
            m_arrVertices[0] = pos0;
            m_arrVertices[1] = pos1;
            m_arrVertices[2] = pos2;
        }
        inline const bool Overlaps(const Shapes::Circle& circle) const
        {
            return circle.GetBCircle().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const Shapes::Triangle& triangle) const
        {
            return sat_overlap(GetVertices(), triangle.GetVertices());
        }
        inline const bool Overlaps(const Shapes::Rect& rect) const
        {
            return rect.GetBBox().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const vec2& point) const
        {
            return point_in_triangle(
                m_pos + m_arrVertices[0],
                m_pos + m_arrVertices[1],
                m_pos + m_arrVertices[2],
                point);
        }
        inline const std::vector<vec2> GetVertices() const
        {
            return {m_pos + m_arrVertices[0], m_pos + m_arrVertices[1], m_pos + m_arrVertices[2]};
        }
    };

    class Line : public Shape
    {
    private:
        vec2 m_start, m_end;
    public:
        inline Line() = default;
        inline Line(const vec2& start, const vec2& end, const Color& color) : m_start(0.0f), m_end(end - start)
        {
            m_pos = start;
            m_color = color;
            m_rotation = std::atan2(end.y - start.y, end.x - start.x);
        }
        inline void Draw(Window* window, DrawMode drawMode = DrawMode::Normal) override
        {
            const DrawMode prevDrawMode = window->GetDrawMode();
            window->SetDrawMode(drawMode);
            window->DrawLine(m_pos + m_start, m_pos + m_end, m_color);
            window->SetDrawMode(prevDrawMode);
        }
        inline void Draw(GeometryBatch& geoBatch, float depth = 0.0f) override
        {
            geoBatch.DrawLine(m_pos + m_start, m_pos + m_end, m_color, depth);
        }
        inline void Rotate(float angle) override
        {
            m_start = rotate<float>(angle, m_start);
            m_end = rotate<float>(angle, m_end);
            m_rotation += angle;
        }
        inline void SetVertices(const vec2& start, const vec2& end)
        {
            m_start = start;
            m_end = end;
        }
        inline const bool Overlaps(const Shapes::Triangle& triangle) const
        {
            return sat_overlap(triangle.GetVertices(), GetVertices());
        }
        inline const bool Overlaps(const Shapes::Rect& rect) const
        {
            return rect.GetBBox().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const Shapes::Circle& circle) const
        {
            return circle.GetBCircle().Overlaps(GetVertices());
        }
        inline const bool Overlaps(const Shapes::Line& line) const
        {
            return sat_overlap(line.GetVertices(), GetVertices());
        }
        inline const bool Overlaps(const vec2& point) const
        {
            return get_closest_distance_to_poly(GetVertices(), point) < epsilon;
        }
        inline const std::vector<vec2> GetVertices() const
        {
            return {m_pos + m_start, m_pos + m_end};
        }
    };
};

#endif