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
    None
};

struct geo_batch_vertex
{
    vec3f position;
    vec4f color;
    int usePerspMat;
};

const std::unordered_map<GeoDrawMode, std::function<void(const std::size_t&, std::vector<uint16_t>&)>> indexBuildFunc = 
{
    {
        GeoDrawMode::Rect,
        [](const std::size_t& size, std::vector<uint16_t>& indices)
        {
            const std::size_t count = (size >> 2) * 6;
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
        [](const std::size_t& size, std::vector<uint16_t>& indices)
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
        [](const std::size_t& size, std::vector<uint16_t>& indices)
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
        [](const std::size_t& size, std::vector<uint16_t>& indices)
        {
            const int triCount = circVertexCount - 2;
            for(uint16_t offset = 0, center = 0; offset < size; offset++)
            {
                indices.push_back(center);
                indices.push_back(offset + 1);
                indices.push_back(offset + 2);
                if(offset % (triCount - 1) == 0)
                    center += triCount;
            }
        }
    },
    {
        GeoDrawMode::None,
        [](const std::size_t& size, std::vector<uint16_t>& indices)
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
    {GeoDrawMode::None, 0}
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
    Pass renderPass = Pass::Pass2D;
    inline GeometryBatch() = default;
    inline GeometryBatch(Window* window);
    inline void DrawLine(vec2f start, vec2f end, vec4f color, float depth = 0.0f);
    inline void DrawCircle(vec2f center, float radius, vec4f color, float depth = 0.0f);
    inline void DrawRect(vec2f pos, vec2f size, float rotation, vec4f color, float depth = 0.0f);
    inline void DrawTriangleOutline(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color, float depth = 0.0f);
    inline void DrawTriangle(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color, float depth = 0.0f);
    inline void DrawRectOutline(vec2f pos, vec2f size, vec4f color, float depth = 0.0f);
    inline void DrawLine(vec3f start, vec3f end, vec4f color);
    inline void DrawCircle(float radius, const mat4x4f& transform, vec4f color);
    inline void DrawRect(vec2f size, const mat4x4f& transform, vec4f color);
    inline void DrawTriangle(vec3f pos0, vec3f pos1, vec3f pos2, vec4f color);
    inline void DrawGradientRect(vec2f size, const mat4x4f& transform, std::array<vec4f, 4> colors);
    inline void DrawGradientTriangle(vec3f pos0, vec3f pos1, vec3f pos2, std::array<vec4f, 3> colors);
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

inline void GeometryBatch::DrawLine(vec3f start, vec3f end, vec4f color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Line || vertices.size() + 2 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Line;
    const bool usePerspMat = renderPass == Pass::Pass3D;
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

inline void GeometryBatch::DrawLine(vec2f start, vec2f end, vec4f color, float depth)
{
    renderPass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    const float invAspect = scrSize.w / scrSize.h;
    start = scrToWorldPos(start, scrSize);
    end = scrToWorldPos(end, scrSize);
    start.x *= invAspect;
    end.x *= invAspect;
    DrawLine({start, depth}, {end, depth}, color);
}

inline void GeometryBatch::DrawCircle(float radius, const mat4x4f& transform, vec4f color)
{
    if(currDrawMode != GeoDrawMode::Circle || vertices.size() + circVertexCount >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Circle;
    const vec2f scrSize = window->GetScrSize();
    const float ang = 360.0f / circVertexCount;
    const bool usePerspMat = renderPass == Pass::Pass3D;
    const float aspect = usePerspMat ? 1.0f : scrSize.h / scrSize.w;
    vec4f res;
    for(int i = 0; i < circVertexCount; i++)
    {
        const vec2f pos = radius * vec2f{std::cos(ang * i), std::sin(ang * i)};
        res = transform * vec4f{pos, 0.0f, 1.0f};
        vertices.push_back({
            .position = {res.x * aspect, res.y, res.z},
            .color = color,
            .usePerspMat = usePerspMat
        });
    }
}

inline void GeometryBatch::DrawCircle(vec2f center, float radius, vec4f color, float depth)
{
    renderPass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    radius = radius * 2.0f / scrSize.h;
    radius *= scrSize.h / scrSize.w;
    center = scrToWorldPos(center, scrSize);
    DrawCircle(radius, translate_mat_3d(vec3f{center, depth}), color);
}

inline void GeometryBatch::DrawRect(vec2f size, const mat4x4f& transform, vec4f color)
{
    DrawGradientRect(size, transform, {color, color, color, color});
}

inline void GeometryBatch::DrawRect(vec2f pos, vec2f size, float rotation, vec4f color, float depth)
{
    renderPass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    pos = scrToWorldPos(pos, scrSize);
    size = scrToWorldSize(size, scrSize);
    size.w *= scrSize.w / scrSize.h;
    DrawRect(size, translate_mat_3d(vec3f{pos, depth}) * rotate_mat_3d(-rotation, {0.0f, 0.0f, 1.0f}), color);
}

inline void GeometryBatch::DrawTriangle(vec3f pos0, vec3f pos1, vec3f pos2, vec4f color)
{
    DrawGradientTriangle(pos0, pos1, pos2, {color, color, color});
}

inline void GeometryBatch::DrawTriangle(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color, float depth)
{
    renderPass = Pass::Pass2D;
    const vec2f scrSize = window->GetScrSize();
    const float invAspect = scrSize.w / scrSize.h;
    pos0 = scrToWorldPos(pos0, scrSize);
    pos1 = scrToWorldPos(pos1, scrSize);
    pos2 = scrToWorldPos(pos2, scrSize);
    pos0.x *= invAspect;
    pos1.x *= invAspect;
    pos2.x *= invAspect;
    DrawTriangle({pos0, depth}, {pos1, depth}, {pos2, depth}, color);
}

inline void GeometryBatch::DrawGradientRect(vec2f size, const mat4x4f& transform, std::array<vec4f, 4> colors)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Rect || vertices.size() + 4 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Rect;
    const vec2f scrSize = window->GetScrSize();
    const bool usePerspMat = renderPass == Pass::Pass3D;
    const float aspect = usePerspMat ? 1.0f : scrSize.h / scrSize.w;
    size *= 0.5f;
    vec4f res = transform * vec4f{-size.w, size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.y, res.z},
        .color = colors[0],
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{-size.w, -size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.y, res.z},
        .color = colors[1],
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{size.w, size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.y, res.z},
        .color = colors[2],
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{size.w, -size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {res.x * aspect, res.y, res.z},
        .color = colors[3],
        .usePerspMat = usePerspMat
    });
}

inline void GeometryBatch::DrawGradientTriangle(vec3f pos0, vec3f pos1, vec3f pos2, std::array<vec4f, 3> colors)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Triangle || vertices.size() + 3 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Triangle;
    const vec2f scrSize = window->GetScrSize();
    const bool usePerspMat = renderPass == Pass::Pass3D;
    const float aspect = usePerspMat ? 1.0f : scrSize.h / scrSize.w;
    vertices.push_back({
        .position = {pos0.x * aspect, pos0.y, pos0.z},
        .color = colors[0],
        .usePerspMat = usePerspMat
    });
    vertices.push_back({
        .position = {pos1.x * aspect, pos1.y, pos1.z},
        .color = colors[1], 
        .usePerspMat = usePerspMat
    });
    vertices.push_back({
        .position = {pos2.x * aspect, pos2.y, pos2.z},
        .color = colors[2],
        .usePerspMat = usePerspMat
    });
}

inline void GeometryBatch::DrawRectOutline(vec2f pos, vec2f size, vec4f color, float depth)
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

inline void GeometryBatch::DrawTriangleOutline(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color, float depth)
{
    DrawLine(pos0, pos1, color, depth);
    DrawLine(pos1, pos2, color, depth);
    DrawLine(pos2, pos0, color, depth);
}

inline void GeometryBatch::Flush()
{
    assert(window);
    window->SetShader(2);
    const std::size_t size = vertices.size();
    indexBuildFunc.at(currDrawMode)(size, indices);
    vao.Bind();
    vbo.Map(vertices);
    ebo.Map(indices);
    const int mode = renderModeMap.at(currDrawMode);
    if(mode) glDrawElements(mode, indices.size(), GL_UNSIGNED_SHORT, 0);
    vao.Unbind();
    indices.clear();
    vertices.clear();
}

#endif