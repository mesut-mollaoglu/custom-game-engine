#ifndef SHAPES_HPP
#define SHAPES_HPP

namespace Shapes 
{
    class Shape
    {
    protected:
        vec2 m_pos = vec2::Zero();
        Color m_col = Colors::Black;
        f32 m_rot = 0.0f;
    public:
        virtual void Draw(Window* /*window*/) { return; }
        virtual void Draw(GeometryBatch& /*batch*/, [[maybe_unused]] f32 depth = 0.0f) { return; }
        virtual void Rotate(f32 /*angle*/) { return; }
        virtual void Scale(const vec2& /*scale*/) { return; }
        virtual void Translate(const vec2& offset)
        {
            m_pos += offset;
        }
        virtual void SetPosition(const vec2& offset)
        {
            if(m_pos != offset)
                Translate(offset - m_pos);
        }
        virtual void SetRotation(f32 angle)
        {
            if(m_rot != angle)
                Rotate(angle - m_rot);
        }
        inline void SetColor(const Color& color)
        {
            m_col = color;
        }
        inline const vec2& GetPosition() const
        {
            return m_pos;
        }
        inline const Color& GetColor() const
        {
            return m_col;
        }
        inline f32 GetRotation() const
        {
            return m_rot;
        }
        virtual ~Shape() {}
    };

    class Rect : public Shape
    {
    private:
        vec2 m_size;
        BoundingBox<f32, 2> m_boundBox;
    public:
        inline Rect() = default;
        inline Rect(const vec2& pos, const vec2& size, const Color& color) : m_size(size) 
        {
            m_boundBox = BoundingBox<f32, 2>(pos, size, 0.0f);
            m_pos = pos;
            m_col = color;
        }
        inline void Rotate(f32 angle) override 
        {
            m_boundBox.rotation += angle;
            m_rot += angle;
        }
        inline void Draw(Window* window) override
        {
            const vec2 half = m_size * 0.5f;
            if(NotRotated(m_rot))
            {
                window->DrawRect(m_pos - half, m_size, m_col);
                return;
            }
            const std::array<vec2, 4> v = m_boundBox.GetVertices();
            window->DrawTriangle(v[0], v[1], v[2], m_col);
            window->DrawTriangle(v[0], v[2], v[3], m_col);
        }
        inline void Draw(GeometryBatch& batch, f32 depth = 0.0f) override
        {
            batch.DrawRect(m_pos, m_size, m_rot, m_col, depth);
        }
        inline void SetSize(const vec2& size)
        {
            m_boundBox.size = m_size = size;
        }
        inline void Translate(const vec2& offset) override
        {
            m_pos += offset;
            m_boundBox.pos += offset;
        }
        inline const BoundingBox<f32, 2>& GetBoundingBox() const
        {
            return m_boundBox;
        }
        inline bool Overlaps(const Rect& rect) const
        {
            return m_boundBox.Overlaps(rect.GetBoundingBox());
        }
        inline bool Overlaps(const vec2& point) const
        {
            return m_boundBox.Overlaps(point);
        }
        inline const vec2& GetSize() const
        {
            return m_size;
        }
    };

    class Circle : public Shape
    {
    private:
        f32 m_radius;
        BoundingSphere<f32, 2> m_boundCircle;
    public:
        inline Circle() = default;
        inline Circle(const vec2& pos, f32 radius, const Color& color) : m_radius(radius) 
        {
            m_boundCircle = BoundingSphere<f32, 2>(pos, radius);
            m_pos = pos;
            m_col = color;
        }
        inline void Rotate([[maybe_unused]] f32 angle) override
        {
            return;
        }
        inline void Draw(Window* window) override
        {
            window->DrawCircle(m_pos, m_radius, m_col);
        }
        inline void Draw(GeometryBatch& batch, f32 depth = 0.0f) override
        {
            batch.DrawCircle(m_pos, m_radius, m_col, depth);
        }
        inline void SetRotation([[maybe_unused]] f32 angle) override
        {
            return;
        }
        inline void SetSize(f32 radius)
        {
            m_boundCircle.radius = m_radius = radius;
        }
        inline void Translate(const vec2& offset)
        {
            m_boundCircle.pos += offset;
            m_pos += offset;
        }
        inline const BoundingSphere<f32, 2>& GetBoundingCircle() const
        {
            return m_boundCircle;
        }
        inline bool Overlaps(const Circle& circle) const
        {
            return m_boundCircle.Overlaps(circle.GetBoundingCircle());
        }
        inline bool Overlaps(const Rect& rect) const
        {
            return m_boundCircle.Overlaps(rect.GetBoundingBox());
        }
        inline bool Overlaps(const vec2& point) const
        {
            return m_boundCircle.Overlaps(point);
        }
        inline f32 GetRadius() const
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
            m_col = color;
        }
        inline void Draw(Window* window) override
        {
            window->DrawTriangle(m_pos + m_arrVertices[0], m_pos + m_arrVertices[1], m_pos + m_arrVertices[2], m_col);
        }
        inline void Draw(GeometryBatch& batch, f32 depth = 0.0f) override
        {
            batch.DrawTriangle(m_pos + m_arrVertices[0], m_pos + m_arrVertices[1], m_pos + m_arrVertices[2], m_col, depth);
        }
        inline void Rotate(f32 angle) override
        {
            m_arrVertices[0] = ::Rotate<f32>(angle, m_arrVertices[0]);
            m_arrVertices[1] = ::Rotate<f32>(angle, m_arrVertices[1]);
            m_arrVertices[2] = ::Rotate<f32>(angle, m_arrVertices[2]);
            m_rot += angle;
        }
        inline void SetVertices(const vec2& pos0, const vec2& pos1, const vec2& pos2)
        {
            m_arrVertices[0] = pos0;
            m_arrVertices[1] = pos1;
            m_arrVertices[2] = pos2;
        }
        inline bool Overlaps(const Shapes::Circle& circle) const
        {
            return circle.GetBoundingCircle().Overlaps(GetVertices());
        }
        inline bool Overlaps(const Shapes::Triangle& triangle) const
        {
            return SATOverlap(GetVertices(), triangle.GetVertices());
        }
        inline bool Overlaps(const Shapes::Rect& rect) const
        {
            return rect.GetBoundingBox().Overlaps(GetVertices());
        }
        inline bool Overlaps(const vec2& point) const
        {
            return GetPointInTriangle(
                m_pos + m_arrVertices[0],
                m_pos + m_arrVertices[1],
                m_pos + m_arrVertices[2],
                point);
        }
        inline const std::array<vec2, 3> GetVertices() const
        {
            return {m_pos + m_arrVertices[0], m_pos + m_arrVertices[1], m_pos + m_arrVertices[2]};
        }
    };

    class Line : public Shape
    {
    private:
        vec2 m_startPos, m_endPos;
        f32 m_lineWidth = 1.0f;
    public:
        inline Line() = default;
        inline Line(const vec2& start, const vec2& end, const Color& color, f32 width = 1.0f)
        : m_startPos(0.0f), m_endPos(end - start), m_lineWidth(width)
        {
            m_pos = start;
            m_col = color;
            m_rot = std::atan2(end.y - start.y, end.x - start.x);
        }
        inline void Draw(Window* window) override
        {
            window->DrawLine(m_pos + m_startPos, m_pos + m_endPos, m_col, m_lineWidth);
        }
        inline void Draw(GeometryBatch& geoBatch, f32 depth = 0.0f) override
        {
            geoBatch.DrawLine(m_pos + m_startPos, m_pos + m_endPos, m_col, m_lineWidth, depth);
        }
        inline void Rotate(f32 angle) override
        {
            m_startPos = ::Rotate<f32>(angle, m_startPos);
            m_endPos = ::Rotate<f32>(angle, m_endPos);
            m_rot += angle;
        }
        inline void SetVertices(const vec2& start, const vec2& end)
        {
            m_startPos = start;
            m_endPos = end;
        }
        inline void SetWidth(f32 width)
        {
            if(width > 0.0f)
                m_lineWidth = width;
        }
        inline f32 GetWidth() const
        {
            return m_lineWidth;
        }
        inline bool Overlaps(const Shapes::Triangle& triangle) const
        {
            return SATOverlap(triangle.GetVertices(), GetVertices());
        }
        inline bool Overlaps(const Shapes::Rect& rect) const
        {
            return rect.GetBoundingBox().Overlaps(GetVertices());
        }
        inline bool Overlaps(const Shapes::Circle& circle) const
        {
            return circle.GetBoundingCircle().Overlaps(GetVertices());
        }
        inline bool Overlaps(const Shapes::Line& line) const
        {
            return SATOverlap(line.GetVertices(), GetVertices());
        }
        inline bool Overlaps(const vec2& point) const
        {
            return GetClosestDistanceToPolygon(GetVertices(), point) < g_kEpsilon<f32>;
        }
        inline const std::array<vec2, 2> GetVertices() const
        {
            return {m_pos + m_startPos, m_pos + m_endPos};
        }
    };
};

#endif