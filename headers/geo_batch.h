#ifndef GEO_BATCH_H
#define GEO_BATCH_H

#include "includes.h"

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
        [](const size_t& size, std::vector<uint16_t>& indices)
        {
            const size_t count = (size >> 2) * 6;
            for (uint16_t i = 0, offset = 0; i < count; i += 6, offset += 4)
            {
                indices.push_back(offset + 0);
                indices.push_back(offset + 1);
                indices.push_back(offset + 3);
                indices.push_back(offset + 0);
                indices.push_back(offset + 3);
                indices.push_back(offset + 2);
            }
        }
    },
    {
        GeoDrawMode::Triangle,
        [](const size_t& size, std::vector<uint16_t>& indices)
        {
            for(uint16_t offset = 0; offset < size; offset += 3)
            {
                indices.push_back(offset + 0);
                indices.push_back(offset + 1);
                indices.push_back(offset + 2);
            }
        }
    },
    {
        GeoDrawMode::Line,
        [](const size_t& size, std::vector<uint16_t>& indices)
        {
            for(uint16_t offset = 0; offset < size; offset += 2)
            {
                indices.push_back(offset + 0);
                indices.push_back(offset + 1);
            }
        }
    },
    {
        GeoDrawMode::Circle,
        [](const size_t& size, std::vector<uint16_t>& indices)
        {
            indices.reserve(size * 3);
            const int count = size / circleVertexCount;
            for(uint16_t i = 0; i < count; i++)
            {
                const uint16_t center = i * circleVertexCount;
                for(uint16_t offset = 0; offset < circleVertexCount - 2; offset++)
                {
                    indices.push_back(center);
                    indices.push_back(center + offset + 1);
                    indices.push_back(center + offset + 2);
                }
            }
        }
    },
    {
        GeoDrawMode::Point,
        [](const size_t& size, std::vector<uint16_t>& indices)
        {
            for(uint16_t offset = 0; offset < size; offset++)
                indices.push_back(offset);
        }
    },
    {
        GeoDrawMode::None,
        [](const size_t& size, std::vector<uint16_t>& indices)
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
    VAO vao;
    Window* window = nullptr;
    Buffer<geo_batch_vertex, GL_ARRAY_BUFFER> vbo;
    Buffer<uint16_t, GL_ELEMENT_ARRAY_BUFFER> ebo;
    GeoDrawMode currDrawMode = GeoDrawMode::None;
    std::vector<geo_batch_vertex> vertices;
    std::vector<uint16_t> indices;
    Pass pass = Pass::Pass2D;
    inline GeometryBatch() = default;
    GeometryBatch(Window* window);
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

inline GeometryBatch::GeometryBatch(Window* window) : window(window)
{
    vao.Build();
    vbo.Build(GL_DYNAMIC_DRAW);
    ebo.Build(GL_DYNAMIC_DRAW);
    vbo.AddAttrib(0, 4, offsetof(geo_batch_vertex, position));
    vbo.AddAttrib(1, 4, offsetof(geo_batch_vertex, color));
}

inline void GeometryBatch::DrawPoint(const vec3& pos, const vec4& color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Point || vertices.size() + 1 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Point;
    vertices.push_back({
        .position = window->GetFrustum(pass).mat * vec4{pos, 1.0f},
        .color = color,
    });
}

inline void GeometryBatch::DrawPoint(const vec2& pos, const vec4& color, float depth)
{
    DrawPoint({ScrToWorldPos(pos, window->GetScrSize()), depth}, color);
}

inline void GeometryBatch::DrawLine(const vec3& start, const vec3& end, const vec4& color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Line || vertices.size() + 2 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Line;
    const mat4 pv = window->GetFrustum(pass).mat;
    vertices.push_back({
        .position = pv * vec4{start, 1.0f},
        .color = color
    });
    vertices.push_back({
        .position = pv * vec4{end, 1.0f},
        .color = color,
    });
}

inline void GeometryBatch::DrawLine(const vec2& start, const vec2& end, const vec4& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2 scrSize = window->GetScrSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawLine({ScrToWorldPos(start, scrSize) * invAspect, depth}, {ScrToWorldPos(end, scrSize) * invAspect, depth}, color);
}

inline void GeometryBatch::DrawEllipse(const vec2& center, const vec2& size, const vec4& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2 scrSize = window->GetScrSize();
    const vec2 aspect = {scrSize.w / scrSize.h, 1.0f};
    DrawEllipse(ScrToWorldSize(size, scrSize) * aspect, {ScrToWorldPos(center, scrSize) * aspect, depth}, 0.0f, color);
}

inline void GeometryBatch::DrawEllipse(const vec2& size, const vec3& pos, const vec3& rotation, const vec4& color)
{
    if(currDrawMode != GeoDrawMode::Circle || vertices.size() + circleVertexCount >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Circle;
    vertices.reserve(vertices.size() + circleVertexCount);
    const vec2 scrSize = window->GetScrSize();
    const float ang = 360.0f / circleVertexCount;
    const float aspect = (pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    const mat4 transform = window->GetFrustum(pass).mat * translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4 res;
    for(int i = 0; i < circleVertexCount; i++)
    {
        const vec2 pos = size * vec2{std::cos(ang * i), std::sin(ang * i)};
        res = transform * vec4{pos, 0.0f, 1.0f};
        vertices.push_back({
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
    pass = Pass::Pass2D;
    const vec2 scrSize = window->GetScrSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawRect(ScrToWorldSize(size, scrSize) * invAspect, vec3{ScrToWorldPos(pos, scrSize) * invAspect, depth}, {0.0f, 0.0f, -rotation}, color);
}

inline void GeometryBatch::DrawTriangle(const vec3& pos0, const vec3& pos1, const vec3& pos2, const vec4& color)
{
    DrawGradientTriangle(pos0, pos1, pos2, {color, color, color});
}

inline void GeometryBatch::DrawTriangle(const vec2& pos0, const vec2& pos1, const vec2& pos2, const vec4& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2 scrSize = window->GetScrSize();
    const vec2 invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawTriangle(
        {ScrToWorldPos(pos0, scrSize) * invAspect, depth}, 
        {ScrToWorldPos(pos1, scrSize) * invAspect, depth}, 
        {ScrToWorldPos(pos2, scrSize) * invAspect, depth}, 
        color);
}

inline void GeometryBatch::DrawGradientRect(const vec2& size, const vec3& pos, const vec3& rotation, const std::array<vec4, 4>& colors)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Rect || vertices.size() + 4 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Rect;
    const vec2 scrSize = window->GetScrSize();
    const float aspect = (pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    const mat4 transform = window->GetFrustum(pass).mat * translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4 res = transform * vec4{-size.w * 0.5f, size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[0]
    });
    res = transform * vec4{-size.w * 0.5f, -size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[1]
    });
    res = transform * vec4{size.w * 0.5f, size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.yzw},
        .color = colors[2]
    });
    res = transform * vec4{size.w * 0.5f, -size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
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
    assert(window);
    if(currDrawMode != GeoDrawMode::Triangle || vertices.size() + 3 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Triangle;
    const vec2 scrSize = window->GetScrSize();
    const mat4 pv = window->GetFrustum(pass).mat;
    const float aspect = (pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w);
    vertices.push_back({
        .position = pv * vec4{pos0.x * aspect, pos0.yz, 1.0f},
        .color = colors[0]
    });
    vertices.push_back({
        .position = pv * vec4{pos1.x * aspect, pos1.yz, 1.0f},
        .color = colors[1]
    });
    vertices.push_back({
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
    assert(window);
    window->SetShader(2);
    const size_t size = vertices.size();
    indexBuildFunc.at(currDrawMode)(size, indices);
    vao.Bind();
    vbo.Map(vertices);
    ebo.Map(indices);
    const int mode = renderModeMap.at(currDrawMode);
    if(mode != -1) glDrawElements(mode, indices.size(), GL_UNSIGNED_SHORT, 0);
    vao.Unbind();
    indices.clear();
    vertices.clear();
}

#endif