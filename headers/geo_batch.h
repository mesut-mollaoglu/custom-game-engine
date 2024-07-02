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
    inline GeometryBatch() = default;
    inline GeometryBatch(Window* window);
    inline void DrawLine(vec2f start, vec2f end, vec4f color);
    inline void DrawCircle(vec2f center, float radius, vec4f color);
    inline void DrawRect(vec2f pos, vec2f size, float rotation, vec4f color);
    inline void DrawTriangleOutline(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color);
    inline void DrawTriangle(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color);
    inline void DrawRectOutline(vec2f pos, vec2f size, vec4f color);
    inline void DrawLine(float lineLen, const mat4x4f& transform, vec4f color);
    inline void DrawCircle(float radius, const mat4x4f& transform, vec4f color);
    inline void DrawRect(vec2f size, const mat4x4f& transform, vec4f color);
    inline void DrawTriangle(vec2f pos0, vec2f pos1, vec2f pos2, const mat4x4f& transform, vec4f color);
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
}

inline void GeometryBatch::DrawLine(float lineLen, const mat4x4f& transform, vec4f color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Line || vertices.size() + 2 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Line;
    const vec2f scrSize = window->GetScrSize();
    vec4f res = transform * vec4f{0.0f, 0.0f, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ),
            res.z    
        },
        .color = color
    });
    res = transform * vec4f{lineLen, 0.0f, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ),
            res.z    
        },
        .color = color
    });
}

inline void GeometryBatch::DrawLine(vec2f start, vec2f end, vec4f color)
{
    const vec2f scrSize = window->GetScrSize();
    const vec2f lineVec = (end - start);
    const float lineLen = lineVec.mag();
    start = scrToWorldPos(start, scrSize);
    const float angle = std::atan2(lineVec.y, lineVec.x);
    DrawLine(lineLen, translate_mat(vec3f{start}) * rotate_mat(angle, {0.0f, 0.0f, 1.0f}), color);
}

inline void GeometryBatch::DrawCircle(float radius, const mat4x4f& transform, vec4f color)
{
    if(currDrawMode != GeoDrawMode::Circle || vertices.size() + circVertexCount >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Circle;
    const vec2f scrSize = window->GetScrSize();
    const float ang = 360.0f / circVertexCount;
    vec4f res;
    for(int i = 0; i < circVertexCount; i++)
    {
        const vec2f pos = radius * vec2f{std::cos(ang * i), std::sin(ang * i)};
        res = transform * vec4f{pos, 0.0f, 1.0f};
        vertices.push_back({
            .position = {
                scrToWorldPos(
                    {res.x, res.y},
                    scrSize
                ),
                res.z    
            },
            .color = color
        });
    }
}

inline void GeometryBatch::DrawCircle(vec2f center, float radius, vec4f color)
{
    DrawCircle(radius, translate_mat(vec3f{center}), color);
}

inline void GeometryBatch::DrawRect(vec2f size, const mat4x4f& transform, vec4f color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Rect || vertices.size() + 4 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Rect;
    const vec2f scrSize = window->GetScrSize();
    size *= 0.5f;
    vec4f res = transform * vec4f{-size.w, size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color
    });
    res = transform * vec4f{-size.w, -size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color
    });
    res = transform * vec4f{size.w, size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color
    });
    res = transform * vec4f{size.w, -size.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color
    });
}

inline void GeometryBatch::DrawRect(vec2f pos, vec2f size, float rotation, vec4f color)
{
    DrawRect(size, translate_mat(vec3f{pos}) * rotate_mat(rotation, {0.0f, 0.0f, 1.0f}), color);
}

inline void GeometryBatch::DrawTriangle(vec2f pos0, vec2f pos1, vec2f pos2, const mat4x4f& transform, vec4f color)
{
    assert(window);
    if(currDrawMode != GeoDrawMode::Triangle || vertices.size() + 3 >= maxGeoBatchVertices) this->Flush();
    currDrawMode = GeoDrawMode::Triangle;
    const vec2f scrSize = window->GetScrSize();
    vec4f res = transform * vec4f{pos0, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color
    });
    res = transform * vec4f{pos1, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color, 
    });
    res = transform * vec4f{pos2, 0.0f, 1.0f};
    vertices.push_back({
        .position = {
            scrToWorldPos(
                {res.x, res.y},
                scrSize
            ), 
            res.z
        },
        .color = color
    });
}

inline void GeometryBatch::DrawTriangle(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color)
{
    DrawTriangle(pos0, pos1, pos2, mat_identity<float, 4>(), color);
}

inline void GeometryBatch::DrawRectOutline(vec2f pos, vec2f size, vec4f color)
{
    DrawLine(
    {
        pos.x - size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, color);
    DrawLine(
    {
        pos.x - size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color);
    DrawLine( 
    {
        pos.x + size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x + size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color);
    DrawLine( 
    {
        pos.x - size.w * 0.5f,
        pos.y - size.h * 0.5f
    }, 
    {
        pos.x - size.w * 0.5f,
        pos.y + size.h * 0.5f
    }, color);
}

inline void GeometryBatch::DrawTriangleOutline(vec2f pos0, vec2f pos1, vec2f pos2, vec4f color)
{
    DrawLine(pos0, pos1, color);
    DrawLine(pos1, pos2, color);
    DrawLine(pos2, pos0, color);
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