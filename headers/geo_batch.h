#ifndef GEO_BATCH_H
#define GEO_BATCH_H

inline constexpr int circleVertexCount = 60;

enum class GeoDrawMode
{
    Rect,
    Triangle,
    Line,
    Circle,
    Point,
    None
};

struct geo_batch_vertex
{
    vec4 position;
    vec4 color;
};

const std::unordered_map<GeoDrawMode, std::function<void(const size_t&, std::vector<uint16_t>&)>> indexBuildFunc = 
{
    {
        GeoDrawMode::Rect,
        [](const size_t& size, std::vector<uint16_t>& m_vecIndices)
        {
            const size_t count = (size >> 2) * 6;
            for (uint16_t i = 0, offset = 0; i < count; i += 6, offset += 4)
            {
                m_vecIndices.push_back(offset + 0);
                m_vecIndices.push_back(offset + 1);
                m_vecIndices.push_back(offset + 3);
                m_vecIndices.push_back(offset + 0);
                m_vecIndices.push_back(offset + 3);
                m_vecIndices.push_back(offset + 2);
            }
        }
    },
    {
        GeoDrawMode::Triangle,
        [](const size_t& size, std::vector<uint16_t>& m_vecIndices)
        {
            for(uint16_t offset = 0; offset < size; offset += 3)
            {
                m_vecIndices.push_back(offset + 0);
                m_vecIndices.push_back(offset + 1);
                m_vecIndices.push_back(offset + 2);
            }
        }
    },
    {
        GeoDrawMode::Line,
        [](const size_t& size, std::vector<uint16_t>& m_vecIndices)
        {
            for(uint16_t offset = 0; offset < size; offset += 2)
            {
                m_vecIndices.push_back(offset + 0);
                m_vecIndices.push_back(offset + 1);
            }
        }
    },
    {
        GeoDrawMode::Circle,
        [](const size_t& size, std::vector<uint16_t>& m_vecIndices)
        {
            m_vecIndices.reserve(size * 3);
            const int count = size / circleVertexCount;
            for(uint16_t i = 0; i < count; i++)
            {
                const uint16_t center = i * circleVertexCount;
                for(uint16_t offset = 0; offset < circleVertexCount - 2; offset++)
                {
                    m_vecIndices.push_back(center);
                    m_vecIndices.push_back(center + offset + 1);
                    m_vecIndices.push_back(center + offset + 2);
                }
            }
        }
    },
    {
        GeoDrawMode::Point,
        [](const size_t& size, std::vector<uint16_t>& m_vecIndices)
        {
            for(uint16_t offset = 0; offset < size; offset++)
                m_vecIndices.push_back(offset);
        }
    },
    {
        GeoDrawMode::None,
        [](const size_t& size, std::vector<uint16_t>& m_vecIndices)
        {
            return;
        }
    },
};

const std::unordered_map<GeoDrawMode, int> renderModeMap = 
{
    {GeoDrawMode::Rect, GL_TRIANGLES},
    {GeoDrawMode::Triangle, GL_TRIANGLES},
    {GeoDrawMode::Line, GL_LINES},
    {GeoDrawMode::Circle, GL_TRIANGLES},
    {GeoDrawMode::Point, GL_POINTS},
    {GeoDrawMode::None, -1}
};

struct GeometryBatch
{
    VAO m_vao;
    Window* m_windowHandle = nullptr;
    Buffer<geo_batch_vertex, GL_ARRAY_BUFFER> m_vbo;
    Buffer<uint16_t, GL_ELEMENT_ARRAY_BUFFER> m_ebo;
    GeoDrawMode m_currDrawMode = GeoDrawMode::None;
    std::vector<geo_batch_vertex> m_vecVertices;
    std::vector<uint16_t> m_vecIndices;
    Pass m_pass = Pass::Pass2D;
    inline GeometryBatch() = default;
    GeometryBatch(Window* m_windowHandle);
    void DrawPoint(const vec2& pos, const vec4& color, float depth = 0.0f);
    void DrawLine(const vec2& start, const vec2& end, const vec4& color, float depth = 0.0f);
    void DrawCircle(const vec2& center, float radius, const vec4& color, float depth = 0.0f);
    void DrawEllipse(const vec2& center, const vec2& size, const vec4& color, float depth = 0.0f);
    void DrawPolygon(const std::vector<vec2>& points, const std::vector<vec4>& colors, float depth = 0.0f);
    void DrawRect(const vec2& pos, const vec2& size, float rotation, const vec4& color, float depth = 0.0f);
    void DrawGradientRect(const vec2& size, const vec2& pos, float rotation, const std::array<vec4, 4>& colors, float depth = 0.0f);
    void DrawGradientTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const std::array<vec4, 3>& colors, float depth = 0.0f);
    void DrawTriangleOutline(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, float depth = 0.0f);
    void DrawTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, float depth = 0.0f);
    void DrawRectOutline(const vec2& pos, const vec2& size, const vec4& color, float depth = 0.0f);
    void DrawPoint(const vec3& pos, const vec4& color);
    void DrawLine(const vec3& start, const vec3& end, const vec4& color);
    void DrawCircle(float radius, const vec3& pos, const vec3& rotation, const vec4& color);
    void DrawEllipse(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color);
    void DrawRect(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color);
    void DrawTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const vec4& color);
    void DrawGradientRect(const vec2& size, const vec3& pos, const vec3& rotation, const std::array<vec4, 4>& colors);
    void DrawGradientTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const std::array<vec4, 3>& colors);
    void DrawPolygon(const std::vector<vec3>& points, const std::vector<vec4>& colors);
    void Flush();
};

#endif

#ifdef GEO_BATCH_H
#undef GEO_BATCH_H

inline GeometryBatch::GeometryBatch(Window* window) : m_windowHandle(window)
{
    m_vao.Build();
    m_vbo.Build(GL_DYNAMIC_DRAW);
    m_ebo.Build(GL_DYNAMIC_DRAW);
    m_vbo.AddAttrib(0, 4, offsetof(geo_batch_vertex, position));
    m_vbo.AddAttrib(1, 4, offsetof(geo_batch_vertex, color));
}

inline void GeometryBatch::DrawPoint(const vec3& pos, const vec4& color)
{
    assert(m_windowHandle);
    if(m_currDrawMode != GeoDrawMode::Point || m_vecVertices.size() + 1 >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Point;
    m_vecVertices.push_back({
        .position = m_windowHandle->GetFrustum(m_pass).m_fMatrix * vec4{pos, 1.0f},
        .color = color,
    });
}

inline void GeometryBatch::DrawPoint(const vec2& pos, const vec4& color, float depth)
{
    DrawPoint({ScreenToWorldPos(pos, m_windowHandle->GetScreenSize()), depth}, color);
}

inline void GeometryBatch::DrawLine(const vec3& start, const vec3& end, const vec4& color)
{
    assert(m_windowHandle);
    if(m_currDrawMode != GeoDrawMode::Line || m_vecVertices.size() + 2 >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Line;
    const mat4 pv = m_windowHandle->GetFrustum(m_pass).m_fMatrix;
    m_vecVertices.push_back({
        .position = pv * vec4{start, 1.0f},
        .color = color
    });
    m_vecVertices.push_back({
        .position = pv * vec4{end, 1.0f},
        .color = color,
    });
}

inline void GeometryBatch::DrawLine(const vec2& start, const vec2& end, const vec4& color, float depth)
{
    m_pass = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawLine({ScreenToWorldPos(start, scrSize) * invAspect, depth}, {ScreenToWorldPos(end, scrSize) * invAspect, depth}, color);
}

inline void GeometryBatch::DrawEllipse(const vec2& center, const vec2& size, const vec4& color, float depth)
{
    m_pass = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 aspect = {scrSize.w / scrSize.h, 1.0f};
    DrawEllipse(ScreenToWorldSize(size, scrSize) * aspect, {ScreenToWorldPos(center, scrSize) * aspect, depth}, 0.0f, color);
}

inline void GeometryBatch::DrawEllipse(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color)
{
    if(m_currDrawMode != GeoDrawMode::Circle || m_vecVertices.size() + circleVertexCount >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Circle;
    m_vecVertices.reserve(m_vecVertices.size() + circleVertexCount);
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const float ang = 360.0f / circleVertexCount;
    const float aspect = (m_pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    const mat4 transform = m_windowHandle->GetFrustum(m_pass).m_fMatrix * translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4 res;
    for(int i = 0; i < circleVertexCount; i++)
    {
        const vec2 pos = size * vec2{std::cos(ang * i), std::sin(ang * i)};
        res = transform * vec4{pos, 0.0f, 1.0f};
        m_vecVertices.push_back({
            .position = {res.x * aspect, res.yzw},
            .color = color
        });
    }
}

inline void GeometryBatch::DrawCircle(float radius, const vec3& pos, const vec3& rotation, const vec4& color)
{
    DrawEllipse({radius, radius}, pos, rotation, color);
}

inline void GeometryBatch::DrawCircle(const vec2& center, float radius, const vec4& color, float depth)
{
    DrawEllipse(center, {radius, radius}, color, depth);
}

inline void GeometryBatch::DrawRect(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color)
{
    DrawGradientRect(size, pos, rotation, {color, color, color, color});
}

inline void GeometryBatch::DrawRect(const vec2& pos, const vec2& size, float rotation, const vec4& color, float depth)
{
    m_pass = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawRect(ScreenToWorldSize(size, scrSize) * invAspect, vec3{ScreenToWorldPos(pos, scrSize) * invAspect, depth}, {0.0f, 0.0f, -rotation}, color);
}

inline void GeometryBatch::DrawTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const vec4& color)
{
    DrawGradientTriangle(pos0, pos1, pos2, {color, color, color});
}

inline void GeometryBatch::DrawTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, float depth)
{
    m_pass = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawTriangle(
        {ScreenToWorldPos(pos0, scrSize) * invAspect, depth}, 
        {ScreenToWorldPos(pos1, scrSize) * invAspect, depth}, 
        {ScreenToWorldPos(pos2, scrSize) * invAspect, depth}, 
        color);
}

inline void GeometryBatch::DrawGradientRect(const vec2& size, const vec3& pos, const vec3& rotation, const std::array<vec4, 4>& colors)
{
    assert(m_windowHandle);
    if(m_currDrawMode != GeoDrawMode::Rect || m_vecVertices.size() + 4 >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Rect;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const float aspect = (m_pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    const mat4 transform = m_windowHandle->GetFrustum(m_pass).m_fMatrix * translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4 res = transform * vec4{-size.w * 0.5f, size.h * 0.5f, 0.0f, 1.0f};
    m_vecVertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[0]
    });
    res = transform * vec4{-size.w * 0.5f, -size.h * 0.5f, 0.0f, 1.0f};
    m_vecVertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[1]
    });
    res = transform * vec4{size.w * 0.5f, size.h * 0.5f, 0.0f, 1.0f};
    m_vecVertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[2]
    });
    res = transform * vec4{size.w * 0.5f, -size.h * 0.5f, 0.0f, 1.0f};
    m_vecVertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[3]
    });
}

inline void GeometryBatch::DrawGradientRect(const vec2& size, const vec2& pos, float rotation, const std::array<vec4, 4>& colors, float depth)
{
    DrawGradientRect(size, {pos, depth}, {0.0f, 0.0f, rotation}, colors);
}

inline void GeometryBatch::DrawGradientTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const std::array<vec4, 3>& colors)
{
    assert(m_windowHandle);
    if(m_currDrawMode != GeoDrawMode::Triangle || m_vecVertices.size() + 3 >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Triangle;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const mat4 pv = m_windowHandle->GetFrustum(m_pass).m_fMatrix;
    const float aspect = (m_pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    m_vecVertices.push_back({
        .position = pv * vec4{pos0.x * aspect, pos0.yz, 1.0f},
        .color = colors[0]
    });
    m_vecVertices.push_back({
        .position = pv * vec4{pos1.x * aspect, pos1.yz, 1.0f},
        .color = colors[1]
    });
    m_vecVertices.push_back({
        .position = pv * vec4{pos2.x * aspect, pos2.yz, 1.0f},
        .color = colors[2]
    });
}

inline void GeometryBatch::DrawGradientTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const std::array<vec4, 3>& colors, float depth)
{
    DrawGradientTriangle({pos0, depth}, {pos1, depth}, {pos2, depth}, colors);
}

inline void GeometryBatch::DrawRectOutline(const vec2& pos, const vec2& size, const vec4& color, float depth)
{
    DrawLine(
    {
        pos.x - size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, color, depth);
    DrawLine(
    {
        pos.x - size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color, depth);
    DrawLine( 
    {
        pos.x + size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color, depth);
    DrawLine( 
    {
        pos.x - size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x - size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color, depth);
}

inline void GeometryBatch::DrawPolygon(const std::vector<vec3>& points, const std::vector<vec4>& colors)
{
    assert(points.size() == colors.size() && points.size() > 3);
    const size_t size = points.size();
    for(size_t i = 1; i < size; i++)
        DrawGradientTriangle(points[0], points[i], points[(i + 1) % size], {colors[0], colors[i], colors[(i + 1) % size]});
}

inline void GeometryBatch::DrawPolygon(const std::vector<vec2>& points, const std::vector<vec4>& colors, float depth)
{
    assert(points.size() == colors.size() && points.size() > 3);
    const size_t size = points.size();
    for(size_t i = 1; i < size; i++)
        DrawGradientTriangle(points[0], points[i], points[(i + 1) % size], {colors[0], colors[i], colors[(i + 1) % size]}, depth);
}

inline void GeometryBatch::DrawTriangleOutline(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, float depth)
{
    DrawLine(pos0, pos1, color, depth);
    DrawLine(pos1, pos2, color, depth);
    DrawLine(pos2, pos0, color, depth);
}

inline void GeometryBatch::Flush()
{
    assert(m_windowHandle);
    m_windowHandle->SetShader(2ull);
    const size_t size = m_vecVertices.size();
    indexBuildFunc.at(m_currDrawMode)(size, m_vecIndices);
    m_vao.Bind();
    m_vbo.Map(m_vecVertices);
    m_ebo.Map(m_vecIndices);
    const int mode = renderModeMap.at(m_currDrawMode);
    if(mode != -1) glDrawElements(mode, m_vecIndices.size(), GL_UNSIGNED_SHORT, 0);
    m_vao.Unbind();
    m_vecIndices.clear();
    m_vecVertices.clear();
}

#endif