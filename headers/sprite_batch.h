#ifndef SPRITE_BATCH_H
#define SPRITE_BATCH_H

#include "includes.h"

struct sprite_batch_vertex
{
    vec4 position;
    vec2 texcoord;
    vec4 color;
    GLuint texture;
};

enum class SprSortMode
{
    FrontToBack,
    BackToFront
};

struct SpriteBatch
{
    VAO vao;
    Window* window = nullptr;
    Buffer<sprite_batch_vertex, GL_ARRAY_BUFFER> vbo;
    Buffer<uint16_t, GL_ELEMENT_ARRAY_BUFFER> ebo;
    std::vector<sprite_batch_vertex> vertices;
    std::vector<uint16_t> indices;
    std::vector<GLuint> textures;
    Pass pass = Pass::Pass2D;
    SprSortMode sortMode = SprSortMode::BackToFront;
    inline SpriteBatch() = default;
    SpriteBatch(Window* window);
    void Draw(
        const Decal& dec,
        const vec2& pos,
        const vec2& size = 1.0f,
        const float rotation = 0.0f,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const float depth = 0.0f,
        const std::array<vec4, 4>& colors = 
        {1.0f, 1.0f, 1.0f, 1.0f},
        const Rect<float>& src = {0.0f, 1.0f},
        const vec2& origin = 0.5f
    );
    void Draw(
        const Decal& dec,
        Transform<float>& transform,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const float depth = 0.0f,
        const std::array<vec4, 4>& colors = 
        {1.0f, 1.0f, 1.0f, 1.0f},
        const Rect<float>& src = {0.0f, 1.0f},
        const vec2& origin = 0.5f
    );
    void Draw(
        const Decal& dec,
        Rect<float> dst,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const float depth = 0.0f,
        const std::array<vec4, 4>& colors = 
        {1.0f, 1.0f, 1.0f, 1.0f},
        const Rect<float>& src = {0.0f, 1.0f}
    );
    void Draw(
        const Decal& dec,
        const mat4& transform,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const std::array<vec4, 4>& colors = 
        {1.0f, 1.0f, 1.0f, 1.0f},
        const Rect<float>& src = {0.0f, 1.0f},
        const vec2& origin = 0.5f
    );
    void Draw(
        const Decal& dec,
        const std::array<vec3, 4>& points,
        const std::array<vec4, 4>& colors =
        {1.0f, 1.0f, 1.0f, 1.0f},
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const Rect<float>& src = {0.0f, 1.0f}
    );
    void SortSprites();
    void Flush();
};

#endif

#ifdef SPRITE_BATCH_H
#undef SPRITE_BATCH_H


inline SpriteBatch::SpriteBatch(Window* window) : window(window)
{
    vao.Build();
    vbo.Build(GL_DYNAMIC_DRAW);
    ebo.Build(GL_DYNAMIC_DRAW);
    vbo.AddAttrib(0, 4, offsetof(sprite_batch_vertex, position));
    vbo.AddAttrib(1, 2, offsetof(sprite_batch_vertex, texcoord));
    vbo.AddAttrib(2, 4, offsetof(sprite_batch_vertex, color));
    vbo.AddAttrib(3, 1, offsetof(sprite_batch_vertex, texture));
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    Transform<float>& transform,
    Horizontal hor,
    Vertical ver,
    const float depth,
    const std::array<vec4, 4>& colors, 
    const Rect<float>& src,
    const vec2& origin)
{
    const vec2 scrSize = window->GetScrSize();
    const vec2 norm = dec.GetSize() * src.size * origin;
    const vec2 inv = dec.GetSize() * src.size * (1.0f - origin);
    Draw(dec,
    {
        vec3{ScrToWorldPos(transform.Forward(-norm), scrSize), depth},
        vec3{ScrToWorldPos(transform.Forward(-norm.w, inv.h), scrSize), depth},
        vec3{ScrToWorldPos(transform.Forward(inv.w, -norm.h), scrSize), depth},
        vec3{ScrToWorldPos(transform.Forward(inv), scrSize), depth}
    }, colors, hor, ver, src);
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    Rect<float> dst,
    Horizontal hor,
    Vertical ver,
    const float depth,
    const std::array<vec4, 4>& colors,
    const Rect<float>& src)
{
    dst *= src.size;
    const vec2 scrSize = window->GetScrSize();
    Draw(dec,
    {
        vec3{ScrToWorldPos(dst.pos, scrSize), depth},
        vec3{ScrToWorldPos({dst.pos.x, dst.pos.y + dst.size.y}, scrSize), depth},
        vec3{ScrToWorldPos({dst.pos.x + dst.size.x, dst.pos.y}, scrSize), depth},
        vec3{ScrToWorldPos(dst.pos + dst.size, scrSize), depth}
    }, colors, hor, ver, src);
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    const vec2& pos, 
    const vec2& size, 
    const float rotation,
    Horizontal hor,
    Vertical ver,
    const float depth,
    const std::array<vec4, 4>& colors, 
    const Rect<float>& src,
    const vec2& origin)
{
    Transform<float> transform;
    transform.Translate(pos);
    transform.Rotate(rotation);
    transform.Scale(size);
    Draw(dec, transform, hor, ver, depth, colors, src, origin);
}

inline void SpriteBatch::Draw(
    const Decal& dec,
    const mat4& transform,
    Horizontal hor,
    Vertical ver,
    const std::array<vec4, 4>& colors,
    const Rect<float>& src,
    const vec2& origin)
{
    const vec2 scrSize = window->GetScrSize();
    const float aspect = pass == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w;
    const vec3 v = {aspect * src.size.w, src.size.h, 1.0f};
    const vec2 size = ScrToWorldSize({dec.width / aspect, (float)dec.height}, scrSize);
    const vec2 norm = size * origin; const vec2 inv = size * (1.0f - origin);
    Draw(dec,
    {
        (transform * vec4{-norm.w, inv.h, 0.0f, 1.0f}).xyz * v,
        (transform * vec4{-norm, 0.0f, 1.0f}).xyz * v,
        (transform * vec4{inv, 0.0f, 1.0f}).xyz * v,
        (transform * vec4{inv.w, -norm.h, 0.0f, 1.0f}).xyz * v
    }, colors, hor, ver, src);
}

inline void SpriteBatch::Draw(
    const Decal& dec,
    const std::array<vec3, 4>& points,
    const std::array<vec4, 4>& colors,
    Horizontal hor,
    Vertical ver,
    const Rect<float>& src)
{
    assert(window);
    vec2 suv = src.pos, euv = src.pos + src.size;
    if(hor == Horizontal::Flip) std::swap(suv.x, euv.x);
    if(ver == Vertical::Flip) std::swap(suv.y, euv.y);
    const GLuint tex = textures.size() % maxSprites;
    const mat4 pv = window->GetFrustum(pass).mat;
    vertices.push_back({
        .position = pv * vec4{points[0], 1.0f},
        .texcoord = suv,
        .color = colors[0],
        .texture = tex
    });
    vertices.push_back({
        .position = pv * vec4{points[1], 1.0f},
        .texcoord = {suv.x, euv.y},
        .color = colors[1], 
        .texture = tex
    });
    vertices.push_back({
        .position = pv * vec4{points[2], 1.0f},
        .texcoord = {euv.x, suv.y},
        .color = colors[2],
        .texture = tex
    });
    vertices.push_back({
        .position = pv * vec4{points[3], 1.0f},
        .texcoord = euv,
        .color = colors[3],
        .texture = tex
    });
    textures.push_back(dec.id);
}

inline void SpriteBatch::SortSprites()
{
    const size_t size = vertices.size();
    switch(sortMode)
    {
        case SprSortMode::BackToFront:
            break;
        case SprSortMode::FrontToBack:
        {
            if(size > 0)
                for (size_t i = 0; i < size - 1; i++)
                    for (size_t j = 0; j < size - i - 1; j++)
                        if (vertices[j].position.z < vertices[j + 1].position.z)
                            std::swap(vertices[j].position.z, vertices[j + 1].position.z);
        }
        break;
    }
}

inline void SpriteBatch::Flush()
{
    assert(window);
    SortSprites();
    window->SetShader(1);
    int sprIndex = 0;
    auto vertBeg = vertices.begin();
    vao.Bind();
    while(vertBeg != vertices.end())
    {
        const size_t sprBatchSize = (vertices.end() - vertBeg) >> 2;
        const size_t sprCount = sprBatchSize < maxSprites ? sprBatchSize : maxSprites;
        vbo.Resize(sprCount * 4);
        vbo.Map(&(*vertBeg), sprCount * 4);
        indices.resize(sprCount * 6);
        for (uint16_t i = 0, offset = 0; i < sprCount * 6; i += 6, offset += 4)
        {
            indices[i + 0] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 3;
            indices[i + 3] = offset + 0;
            indices[i + 4] = offset + 3;
            indices[i + 5] = offset + 2;
        }
        ebo.Map(indices);
        for(int i = 0; i < sprCount; i++) BindTexture(textures[sprIndex + i], i);
        glDrawElements(GL_TRIANGLES, sprCount * 6, GL_UNSIGNED_SHORT, 0);
        sprIndex += sprCount;
        vertBeg += sprCount * 4;
        for(int i = 0; i < sprCount; i++) BindTexture(0, i);
    }
    vao.Unbind();
    textures.clear();
    vertices.clear();
    indices.clear();
}

#endif