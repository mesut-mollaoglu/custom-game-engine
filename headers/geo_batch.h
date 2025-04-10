#ifndef GEO_BATCH_H
#define GEO_BATCH_H

inline constexpr i32 circleVertexCount = 60;

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

const std::unordered_map<GeoDrawMode, std::function<void(const usize&, std::vector<u16>&)>> indexBuildFunc = 
{
    {
        GeoDrawMode::Rect,
        [](const usize& size, std::vector<u16>& m_vecIndices)
        {
            const usize count = (size >> 2) * 6;
            for (u16 i = 0, offset = 0; i < count; i += 6, offset += 4)
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
        [](const usize& size, std::vector<u16>& m_vecIndices)
        {
            for(u16 offset = 0; offset < size; offset += 3)
            {
                m_vecIndices.push_back(offset + 0);
                m_vecIndices.push_back(offset + 1);
                m_vecIndices.push_back(offset + 2);
            }
        }
    },
    {
        GeoDrawMode::Line,
        [](const usize& size, std::vector<u16>& m_vecIndices)
        {
            for(u16 offset = 0; offset < size; offset += 2)
            {
                m_vecIndices.push_back(offset + 0);
                m_vecIndices.push_back(offset + 1);
            }
        }
    },
    {
        GeoDrawMode::Circle,
        [](const usize& size, std::vector<u16>& m_vecIndices)
        {
            m_vecIndices.reserve(size * 3);
            const i32 count = size / circleVertexCount;
            for(u16 i = 0; i < count; i++)
            {
                const u16 center = i * circleVertexCount;
                for(u16 offset = 0; offset < circleVertexCount - 2; offset++)
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
        [](const usize& size, std::vector<u16>& m_vecIndices)
        {
            for(u16 offset = 0; offset < size; offset++)
                m_vecIndices.push_back(offset);
        }
    },
    {
        GeoDrawMode::None,
        [](const usize& size, std::vector<u16>& m_vecIndices)
        {
            return;
        }
    },
};

const std::unordered_map<GeoDrawMode, i32> renderModeMap = 
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
    Buffer<u16, GL_ELEMENT_ARRAY_BUFFER> m_ebo;
    GeoDrawMode m_currDrawMode = GeoDrawMode::None;
    std::vector<geo_batch_vertex> m_vecVertices;
    std::vector<u16> m_vecIndices;
    Pass m_passMode = Pass::Pass2D;
    f32 m_lineWidth = 1.0f;
    inline GeometryBatch() = default;
    GeometryBatch(Window* m_windowHandle);
    void DrawPoint(const vec2& pos, const vec4& color, f32 depth = 0.0f);
    void DrawLine(const vec2& start, const vec2& end, const vec4& color, f32 width = 1.0f, f32 depth = 0.0f);
    void DrawCircle(const vec2& center, f32 radius, const vec4& color, f32 depth = 0.0f);
    void DrawEllipse(const vec2& center, const vec2& size, const vec4& color, f32 depth = 0.0f);
    void DrawPolygon(const std::vector<vec2>& points, const std::vector<vec4>& colors, f32 depth = 0.0f);
    void DrawRect(const vec2& pos, const vec2& size, f32 rotation, const vec4& color, f32 depth = 0.0f);
    void DrawGradientRect(const vec2& size, const vec2& pos, f32 rotation, const std::array<vec4, 4>& colors, f32 depth = 0.0f);
    void DrawGradientTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const std::array<vec4, 3>& colors, f32 depth = 0.0f);
    void DrawTriangleOutline(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, f32 width = 1.0f, f32 depth = 0.0f);
    void DrawTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, f32 depth = 0.0f);
    void DrawRectOutline(const vec2& pos, const vec2& size, const vec4& color, f32 width = 1.0f, f32 depth = 0.0f);
    void DrawPoint(const vec3& pos, const vec4& color);
    void DrawLine(const vec3& start, const vec3& end, const vec4& color, f32 width = 1.0f);
    void DrawCircle(f32 radius, const vec3& pos, const vec3& rotation, const vec4& color);
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
        .position = m_windowHandle->GetFrustum(m_passMode).GetMatrix() * vec4{pos, 1.0f},
        .color = color,
    });
}

inline void GeometryBatch::DrawPoint(const vec2& pos, const vec4& color, f32 depth)
{
    DrawPoint({ScreenToWorldPos(pos, m_windowHandle->GetScreenSize()), depth}, color);
}

inline void GeometryBatch::DrawLine(const vec3& start, const vec3& end, const vec4& color, f32 width)
{
    assert(m_windowHandle);
    if(m_currDrawMode != GeoDrawMode::Line || m_vecVertices.size() + 2 >= maxGeoBatchVertices || m_lineWidth != width)
    {
        this->Flush();
        m_lineWidth = width;
    }
    m_currDrawMode = GeoDrawMode::Line;
    const mat4 pv = m_windowHandle->GetFrustum(m_passMode).GetMatrix();
    m_vecVertices.push_back({
        .position = pv * vec4{start, 1.0f},
        .color = color
    });
    m_vecVertices.push_back({
        .position = pv * vec4{end, 1.0f},
        .color = color,
    });
}

inline void GeometryBatch::DrawLine(const vec2& start, const vec2& end, const vec4& color, f32 width, f32 depth)
{
    m_passMode = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    DrawLine({ScreenToWorldPos(start, scrSize), depth}, {ScreenToWorldPos(end, scrSize), depth}, color, width);
}

inline void GeometryBatch::DrawEllipse(const vec2& center, const vec2& size, const vec4& color, f32 depth)
{
    m_passMode = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawEllipse(ScreenToWorldSize(size, scrSize) * invAspect, {ScreenToWorldPos(center, scrSize) * invAspect, depth}, 0.0f, color);
}

inline void GeometryBatch::DrawEllipse(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color)
{
    if(m_currDrawMode != GeoDrawMode::Circle || m_vecVertices.size() + circleVertexCount >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Circle;
    m_vecVertices.reserve(m_vecVertices.size() + circleVertexCount);
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const f32 ang = 360.0f / circleVertexCount;
    const f32 aspect = (m_passMode == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    const mat4 transform = m_windowHandle->GetFrustum(m_passMode).GetMatrix() * translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4 res;
    for(i32 i = 0; i < circleVertexCount; i++)
    {
        const vec2 pos = size * vec2{std::cos(ang * i), std::sin(ang * i)};
        res = transform * vec4{pos, 0.0f, 1.0f};
        m_vecVertices.push_back({
            .position = {res.x * aspect, res.yzw},
            .color = color
        });
    }
}

inline void GeometryBatch::DrawCircle(f32 radius, const vec3& pos, const vec3& rotation, const vec4& color)
{
    DrawEllipse({radius, radius}, pos, rotation, color);
}

inline void GeometryBatch::DrawCircle(const vec2& center, f32 radius, const vec4& color, f32 depth)
{
    DrawEllipse(center, {radius, radius}, color, depth);
}

inline void GeometryBatch::DrawRect(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color)
{
    DrawGradientRect(size, pos, rotation, {color, color, color, color});
}

inline void GeometryBatch::DrawRect(const vec2& pos, const vec2& size, f32 rotation, const vec4& color, f32 depth)
{
    m_passMode = Pass::Pass2D;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawRect(ScreenToWorldSize(size, scrSize) * invAspect, vec3{ScreenToWorldPos(pos, scrSize) * invAspect, depth}, {0.0f, 0.0f, -rotation}, color);
}

inline void GeometryBatch::DrawTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const vec4& color)
{
    DrawGradientTriangle(pos0, pos1, pos2, {color, color, color});
}

inline void GeometryBatch::DrawTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, f32 depth)
{
    m_passMode = Pass::Pass2D;
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
    const f32 aspect = (m_passMode == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    const mat4 transform = m_windowHandle->GetFrustum(m_passMode).GetMatrix() * translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
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

inline void GeometryBatch::DrawGradientRect(const vec2& size, const vec2& pos, f32 rotation, const std::array<vec4, 4>& colors, f32 depth)
{
    DrawGradientRect(size, {pos, depth}, {0.0f, 0.0f, rotation}, colors);
}

inline void GeometryBatch::DrawGradientTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const std::array<vec4, 3>& colors)
{
    assert(m_windowHandle);
    if(m_currDrawMode != GeoDrawMode::Triangle || m_vecVertices.size() + 3 >= maxGeoBatchVertices) this->Flush();
    m_currDrawMode = GeoDrawMode::Triangle;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const mat4 pv = m_windowHandle->GetFrustum(m_passMode).GetMatrix();
    const f32 aspect = (m_passMode == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
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

inline void GeometryBatch::DrawGradientTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const std::array<vec4, 3>& colors, f32 depth)
{
    DrawGradientTriangle({pos0, depth}, {pos1, depth}, {pos2, depth}, colors);
}

inline void GeometryBatch::DrawRectOutline(const vec2& pos, const vec2& size, const vec4& color, f32 width, f32 depth)
{
    DrawLine(
    {
        pos.x - size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, color, width, depth);
    DrawLine(
    {
        pos.x - size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color, width, depth);
    DrawLine( 
    {
        pos.x + size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color, width, depth);
    DrawLine( 
    {
        pos.x - size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x - size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color, width, depth);
}

inline void GeometryBatch::DrawPolygon(const std::vector<vec3>& points, const std::vector<vec4>& colors)
{
    assert(points.size() == colors.size() && points.size() > 3);
    const usize size = points.size();
    for(usize i = 1; i < size; i++)
        DrawGradientTriangle(points[0], points[i], points[(i + 1) % size], {colors[0], colors[i], colors[(i + 1) % size]});
}

inline void GeometryBatch::DrawPolygon(const std::vector<vec2>& points, const std::vector<vec4>& colors, f32 depth)
{
    assert(points.size() == colors.size() && points.size() > 3);
    const usize size = points.size();
    for(usize i = 1; i < size; i++)
        DrawGradientTriangle(points[0], points[i], points[(i + 1) % size], {colors[0], colors[i], colors[(i + 1) % size]}, depth);
}

inline void GeometryBatch::DrawTriangleOutline(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, f32 width, f32 depth)
{
    DrawLine(pos0, pos1, color, width, depth);
    DrawLine(pos1, pos2, color, width, depth);
    DrawLine(pos2, pos0, color, width, depth);
}

inline void GeometryBatch::Flush()
{
    assert(m_windowHandle);
    glLineWidth(m_lineWidth);
    m_windowHandle->SetShader(2ull);
    const usize size = m_vecVertices.size();
    indexBuildFunc.at(m_currDrawMode)(size, m_vecIndices);
    m_vao.Bind();
    m_vbo.Map(m_vecVertices);
    m_ebo.Map(m_vecIndices);
    const i32 mode = renderModeMap.at(m_currDrawMode);
    if(mode != -1) glDrawElements(mode, m_vecIndices.size(), GL_UNSIGNED_SHORT, 0);
    m_vao.Unbind();
    m_vecIndices.clear();
    m_vecVertices.clear();
}

#endif