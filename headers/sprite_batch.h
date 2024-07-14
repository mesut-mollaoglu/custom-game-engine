#ifndef SPRITE_BATCH_H
#define SPRITE_BATCH_H

#include "includes.h"

struct sprite_batch_vertex
{
    vec3f position;
    vec2f texcoord;
    vec4f color;
    GLuint texture;
    int usePerspMat = 0;
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
    Pass renderPass = Pass::Pass2D;
    SprSortMode sortMode = SprSortMode::BackToFront;
    inline SpriteBatch() = default;
    inline SpriteBatch(Window* window);
    inline void Draw(
        const Decal& dec,
        const vec2f& pos,
        const vec2f& size = 1.0f,
        const float rotation = 0.0f,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const float depth = 0.0f,
        const vec4f& color = 1.0f,
        const Rect<float>& src = {0.0f, 1.0f},
        const vec2f& origin = 0.5f
    );
    inline void Draw(
        const Decal& dec,
        Transform<float>& transform,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const float depth = 0.0f,
        const vec4f& color = 1.0f,
        const Rect<float>& src = {0.0f, 1.0f},
        const vec2f& origin = 0.5f
    );
    inline void Draw(
        const Decal& dec,
        Rect<float> dst,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const float depth = 0.0f,
        const vec4f& color = 1.0f,
        const Rect<float>& src = {0.0f, 1.0f}
    );
    inline void Draw(
        const Decal& dec,
        const mat4x4f& transform,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const vec4f& color = 1.0f,
        const Rect<float>& src = {0.0f, 1.0f},
        const vec2f& origin = 0.5f
    );
    inline void SortSprites();
    inline void Flush();
};

#endif

#ifdef SPRITE_BATCH_H
#undef SPRITE_BATCH_H


inline SpriteBatch::SpriteBatch(Window* window) : window(window)
{
    vao.Build();
    vbo.Build(GL_DYNAMIC_DRAW);
    ebo.Build(GL_DYNAMIC_DRAW);
    vbo.AddAttrib(0, 3, offsetof(sprite_batch_vertex, position));
    vbo.AddAttrib(1, 2, offsetof(sprite_batch_vertex, texcoord));
    vbo.AddAttrib(2, 4, offsetof(sprite_batch_vertex, color));
    vbo.AddAttrib(3, 1, offsetof(sprite_batch_vertex, texture));
    vbo.AddAttrib(4, 1, offsetof(sprite_batch_vertex, usePerspMat));
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    Transform<float>& transform,
    Horizontal hor,
    Vertical ver,
    const float depth,
    const vec4f& color, 
    const Rect<float>& src,
    const vec2f& origin)
{
    assert(window);
    vec2f suv = src.pos, euv = src.pos + src.size;
    if(hor == Horizontal::Flip) std::swap(suv.x, euv.x);
    if(ver == Vertical::Flip) std::swap(suv.y, euv.y);
    const GLuint tex = textures.size() % maxSprites;
    const vec2f scrSize = window->GetScrSize();
    const vec2f norm = dec.GetSize() * src.size * origin;
    const vec2f inv = dec.GetSize() * src.size * (1.0f - origin);
    vertices.push_back({
        .position = {scrToWorldPos(transform.Forward(-norm.w, inv.h), scrSize), depth},
        .texcoord = {suv.x, euv.y},
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = {scrToWorldPos(transform.Forward(-norm), scrSize), depth},
        .texcoord = suv,
        .color = color, 
        .texture = tex
    });
    vertices.push_back({
        .position = {scrToWorldPos(transform.Forward(inv), scrSize), depth},
        .texcoord = euv,
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = {scrToWorldPos(transform.Forward(inv.w, -norm.h), scrSize), depth},
        .texcoord = {euv.x, suv.y},
        .color = color,
        .texture = tex
    });
    textures.push_back(dec.id);
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    Rect<float> dst,
    Horizontal hor,
    Vertical ver,
    const float depth,
    const vec4f& color, 
    const Rect<float>& src)
{
    assert(window);
    vec2f suv = src.pos, euv = src.pos + src.size;
    if(hor == Horizontal::Flip) std::swap(suv.x, euv.x);
    if(ver == Vertical::Flip) std::swap(suv.y, euv.y);
    const GLuint tex = textures.size() % maxSprites;
    dst *= src.size;
    const vec2f scrSize = window->GetScrSize();
    vertices.push_back({
        .position = {scrToWorldPos({dst.pos.x, dst.pos.y + dst.size.y}, scrSize), depth},
        .texcoord = {suv.x, euv.y},
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = {scrToWorldPos(dst.pos, scrSize), depth},
        .texcoord = suv,
        .color = color, 
        .texture = tex
    });
    vertices.push_back({
        .position = {scrToWorldPos(dst.pos + dst.size, scrSize), depth},
        .texcoord = euv,
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = {scrToWorldPos({dst.pos.x + dst.size.x, dst.pos.y}, scrSize), depth},
        .texcoord = {euv.x, suv.y},
        .color = color,
        .texture = tex
    });
    textures.push_back(dec.id);
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    const vec2f& pos, 
    const vec2f& size, 
    const float rotation,
    Horizontal hor,
    Vertical ver,
    const float depth,
    const vec4f& color, 
    const Rect<float>& src,
    const vec2f& origin)
{
    assert(window);
    Transform<float> transform;
    transform.Translate(pos);
    transform.Rotate(rotation);
    transform.Scale(size);
    this->Draw(dec, transform, hor, ver, depth, color, src, origin);
}

inline void SpriteBatch::Draw(
    const Decal& dec,
    const mat4x4f& transform,
    Horizontal hor,
    Vertical ver,
    const vec4f& color,
    const Rect<float>& src,
    const vec2f& origin)
{
    assert(window);
    vec2f suv = src.pos, euv = src.pos + src.size;
    if(hor == Horizontal::Flip) std::swap(suv.x, euv.x);
    if(ver == Vertical::Flip) std::swap(suv.y, euv.y);
    const GLuint tex = textures.size() % maxSprites;
    const vec2f scrSize = window->GetScrSize();
    const bool usePerspMat = renderPass == Pass::Pass3D;
    const float aspect = usePerspMat ? 1.0f : scrSize.h / scrSize.w;
    const vec2f size = scrToWorldSize({dec.width / aspect, (float)dec.height}, scrSize);
    const vec2f norm = size * origin; const vec2f inv = size * (1.0f - origin);
    vec4f res = transform * vec4f{-norm.w, inv.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {vec2f{res.x * aspect, res.y} * src.size, res.z},
        .texcoord = suv,
        .color = color,
        .texture = tex,
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{-norm, 0.0f, 1.0f};
    vertices.push_back({
        .position = {vec2f{res.x * aspect, res.y} * src.size, res.z},
        .texcoord = {suv.x, euv.y},
        .color = color, 
        .texture = tex,
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{inv, 0.0f, 1.0f};
    vertices.push_back({
        .position = {vec2f{res.x * aspect, res.y} * src.size, res.z},
        .texcoord = {euv.x, suv.y},
        .color = color,
        .texture = tex,
        .usePerspMat = usePerspMat
    });
    res = transform * vec4f{inv.w, -norm.h, 0.0f, 1.0f};
    vertices.push_back({
        .position = {vec2f{res.x * aspect, res.y} * src.size, res.z},
        .texcoord = euv,
        .color = color,
        .texture = tex,
        .usePerspMat = usePerspMat
    });
    textures.push_back(dec.id);
}

inline void SpriteBatch::SortSprites()
{
    const std::size_t size = vertices.size();
    switch(sortMode)
    {
        case SprSortMode::BackToFront:
            break;
        case SprSortMode::FrontToBack:
        {
            if(size > 0)
                for (std::size_t i = 0; i < size - 1; i++)
                    for (std::size_t j = 0; j < size - i - 1; j++)
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
        const std::size_t sprBatchSize = (vertices.end() - vertBeg) >> 2;
        const std::size_t sprCount = sprBatchSize < maxSprites ? sprBatchSize : maxSprites;
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