#ifndef GEO_BATCH_H
#define GEO_BATCH_H

#include "includes.h"

constexpr int circVertexCount = 60;

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
    vec3f position;
    vec4f color;
    int usePerspMat;
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
            for(uint16_t offset = 0; offset < circVertexCount - 2; offset++)
            {
                indices.push_back(0);
                indices.push_back(offset + 1);
                indices.push_back(offset + 2);
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
    inline GeometryBatch(Window* window);
    inline void DrawPoint(const vec2f& pos, const vec4f& color, float depth = 0.0f);
    inline void DrawLine(const vec2f& start, const vec2f& end, const vec4f& color, float depth = 0.0f);
    inline void DrawCircle(const vec2f& center, float radius, const vec4f& color, float depth = 0.0f);
    inline void DrawEllipse(const vec2f& center, const vec2f& size, const vec4f& color, float depth = 0.0f);
    inline void DrawPolygon(const std::vector<vec2f>& points, const std::vector<vec4f>& colors, float depth = 0.0f);
    inline void DrawRect(const vec2f& pos, const vec2f& size, float rotation, const vec4f& color, float depth = 0.0f);
    inline void DrawGradientRect(const vec2f& size, const vec2f& pos, float rotation, const std::array<vec4f, 4>& colors, float depth = 0.0f);
    inline void DrawGradientTriangle(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const std::array<vec4f, 3>& colors, float depth = 0.0f);
    inline void DrawTriangleOutline(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const vec4f& color, float depth = 0.0f);
    inline void DrawTriangle(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const vec4f& color, float depth = 0.0f);
    inline void DrawRectOutline(const vec2f& pos, const vec2f& size, const vec4f& color, float depth = 0.0f);
    inline void DrawPoint(const vec3f& pos, const vec4f& color);
    inline void DrawLine(const vec3f& start, const vec3f& end, const vec4f& color);
    inline void DrawCircle(float radius, const vec3f& pos, const vec3f& rotation, const vec4f& color);
    inline void DrawEllipse(const vec2f& size, const vec3f& pos, const vec3f& rotation, const vec4f& color);
    inline void DrawRect(const vec2f& size, const vec3f& pos, const vec3f& rotation, const vec4f& color);
    inline void DrawTriangle(const vec3f& pos0, const vec3f& pos1, const vec3f& pos2, const vec4f& color);
    inline void DrawGradientRect(const vec2f& size, const vec3f& pos, const vec3f& rotation, const std::array<vec4f, 4>& colors);
    inline void DrawGradientTriangle(const vec3f& pos0, const vec3f& pos1, const vec3f& pos2, const std::array<vec4f, 3>& colors);
    inline void DrawPolygon(const std::vector<vec3f>& points, const std::vector<vec4f>& colors);
    inline void Flush();
};

#endif

#ifdef GEO_BATCH_H
#undef GEO_BATCH_H

inline GeometryBatch::GeometryBatch(Window* window) : window(window)
{
    vao.Build();
    vbo.Build(GL_DYNAMIC_DRAW);
    ebo.Build(GL_DYNAMIC_DRAW);
    vbo.AddAttrib(0, 3, offsetof(geo_batch_vertex, position));
    vbo.AddAttrib(1, 4, offsetof(geo_batch_vertex, color));
    vbo.AddAttrib(2, 1, offsetof(geo_batch_vertex, usePerspMat));
}

inline void GeometryBatch::DrawPoint(const vec3f& pos, const vec4f& color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Point || vertices.size() + 1 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Point;
    vertices.push_back({
        .position = pos,
        .color = color,
        .usePerspMat = pass == Pass::Pass3D
    });
}

inline void GeometryBatch::DrawPoint(const vec2f& pos, const vec4f& color, float depth)
{
    DrawPoint({ScrToWorldPos(pos, window->GetScrSize()), depth}, color);
}

inline void GeometryBatch::DrawLine(const vec3f& start, const vec3f& end, const vec4f& color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Line || vertices.size() + 2 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Line;
    const bool usePerspMat = pass == Pass::Pass3D;
    vertices.push_back({
        .position = start,
        .color = color,
        .usePerspMat = usePerspMat
    });
    vertices.push_back({
        .position = end,
        .color = color,
        .usePerspMat = usePerspMat
    });
}

inline void GeometryBatch::DrawLine(const vec2f& start, const vec2f& end, const vec4f& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    const vec2f invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawLine({ScrToWorldPos(start, scrSize) * invAspect, depth}, {ScrToWorldPos(end, scrSize) * invAspect, depth}, color);
}

inline void GeometryBatch::DrawEllipse(const vec2f& center, const vec2f& size, const vec4f& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    const vec2f aspect = {scrSize.w / scrSize.h, 1.0f};
    DrawEllipse(ScrToWorldSize(size, scrSize) * aspect, {ScrToWorldPos(center, scrSize) * aspect, depth}, 0.0f, color);
}

inline void GeometryBatch::DrawEllipse(const vec2f& size, const vec3f& pos, const vec3f& rotation, const vec4f& color)
{
    if(currDrawMode != GeoDrawMode::Circle || vertices.size() + circVertexCount >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Circle;
    const vec2f scrSize = window->GetScrSize();
    const float ang = 360.0f / circVertexCount;
    const bool usePerspMat = pass == Pass::Pass3D;
    const vec3f aspect = {usePerspMat ? 1.0f : scrSize.h / scrSize.w, 1.0f, 1.0f};
    const mat4x4f transform = translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4f res;
    for(int i = 0; i < circVertexCount; i++)
    {
        const vec2f pos = size * vec2f{std::cos(ang * i), std::sin(ang * i)};
        res = transform * vec4f{pos, 0.0f, 1.0f};
        vertices.push_back({
            .position = res.xyz * aspect,
            .color = color,
            .usePerspMat = usePerspMat
        });
    }
}

inline void GeometryBatch::DrawCircle(float radius, const vec3f& pos, const vec3f& rotation, const vec4f& color)
{
    DrawEllipse({radius, radius}, pos, rotation, color);
}

inline void GeometryBatch::DrawCircle(const vec2f& center, float radius, const vec4f& color, float depth)
{
    DrawEllipse(center, {radius, radius}, color, depth);
}

inline void GeometryBatch::DrawRect(const vec2f& size, const vec3f& pos, const vec3f& rotation, const vec4f& color)
{
    DrawGradientRect(size, pos, rotation, {color, color, color, color});
}

inline void GeometryBatch::DrawRect(const vec2f& pos, const vec2f& size, float rotation, const vec4f& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    const vec2f invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawRect(ScrToWorldSize(size, scrSize) * invAspect, vec3f{ScrToWorldPos(pos, scrSize) * invAspect, depth}, {0.0f, 0.0f, -rotation}, color);
}

inline void GeometryBatch::DrawTriangle(const vec3f& pos0, const vec3f& pos1, const vec3f& pos2, const vec4f& color)
{
    DrawGradientTriangle(pos0, pos1, pos2, {color, color, color});
}

inline void GeometryBatch::DrawTriangle(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const vec4f& color, float depth)
{
    pass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    const vec2f invAspect = {scrSize.w / scrSize.h, 1.0f};
    DrawTriangle(
        {ScrToWorldPos(pos0, scrSize) * invAspect, depth}, 
        {ScrToWorldPos(pos1, scrSize) * invAspect, depth}, 
        {ScrToWorldPos(pos2, scrSize) * invAspect, depth}, 
        color);
}

inline void GeometryBatch::DrawGradientRect(const vec2f& size, const vec3f& pos, const vec3f& rotation, const std::array<vec4f, 4>& colors)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Rect || vertices.size() + 4 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Rect;
    const vec2f scrSize = window->GetScrSize();
    const bool usePerspMat = pass == Pass::Pass3D;
    const vec3f aspect = {usePerspMat ? 1.0f : scrSize.h / scrSize.w, 1.0f, 1.0f};
    const mat4x4f transform = translation_mat_3d(pos) * rotation_mat_from_euler(rotation);
    vec4f res = transform * vec4f{-size.w * 0.5f, size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = res.xyz * aspect,
        .color = colors[0],
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{-size.w * 0.5f, -size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = res.xyz * aspect,
        .color = colors[1],
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{size.w * 0.5f, size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = res.xyz * aspect,
        .color = colors[2],
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{size.w * 0.5f, -size.h * 0.5f, 0.0f, 1.0f};
    vertices.push_back({
        .position = res.xyz * aspect,
        .color = colors[3],
        .usePerspMat = usePerspMat
    });
}

inline void GeometryBatch::DrawGradientRect(const vec2f& size, const vec2f& pos, float rotation, const std::array<vec4f, 4>& colors, float depth)
{
    DrawGradientRect(size, {pos, depth}, {0.0f, 0.0f, rotation}, colors);
}

inline void GeometryBatch::DrawGradientTriangle(const vec3f& pos0, const vec3f& pos1, const vec3f& pos2, const std::array<vec4f, 3>& colors)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Triangle || vertices.size() + 3 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Triangle;
    const vec2f scrSize = window->GetScrSize();
    const bool usePerspMat = pass == Pass::Pass3D;
    const vec3f aspect = {usePerspMat ? 1.0f : scrSize.h / scrSize.w, 1.0f, 1.0f};
    vertices.push_back({
        .position = pos0 * aspect,
        .color = colors[0],
        .usePerspMat = usePerspMat
    });
    vertices.push_back({
        .position = pos1 * aspect,
        .color = colors[1], 
        .usePerspMat = usePerspMat
    });
    vertices.push_back({
        .position = pos2 * aspect,
        .color = colors[2],
        .usePerspMat = usePerspMat
    });
}

inline void GeometryBatch::DrawGradientTriangle(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const std::array<vec4f, 3>& colors, float depth)
{
    DrawGradientTriangle({pos0, depth}, {pos1, depth}, {pos2, depth}, colors);
}

inline void GeometryBatch::DrawRectOutline(const vec2f& pos, const vec2f& size, const vec4f& color, float depth)
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

inline void GeometryBatch::DrawPolygon(const std::vector<vec3f>& points, const std::vector<vec4f>& colors)
{
    assert(points.size() == colors.size() && points.size() > 3);
    const size_t size = points.size();
    for(size_t i = 1; i < size; i++)
        DrawGradientTriangle(points[0], points[i], points[(i + 1) % size], {colors[0], colors[i], colors[(i + 1) % size]});
}

inline void GeometryBatch::DrawPolygon(const std::vector<vec2f>& points, const std::vector<vec4f>& colors, float depth)
{
    assert(points.size() == colors.size() && points.size() > 3);
    const size_t size = points.size();
    for(size_t i = 1; i < size; i++)
        DrawGradientTriangle(points[0], points[i], points[(i + 1) % size], {colors[0], colors[i], colors[(i + 1) % size]}, depth);
}

inline void GeometryBatch::DrawTriangleOutline(const vec2f& pos0, const vec2f& pos1, const vec2f& pos2, const vec4f& color, float depth)
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