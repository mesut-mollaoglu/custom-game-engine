#ifndef SPRITE_BATCH_H
#define SPRITE_BATCH_H

#include "includes.h"

struct sprite_batch_vertex
{
    vec2f position;
    vec2f texcoord;
    vec4f color;
    GLuint texture;
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
    inline SpriteBatch() = default;
    inline SpriteBatch(Window* window);
    inline void Draw
    (
        const Decal& dec,
        const vec2f& pos,
        const vec2f& size = 1.0f,
        const float rotation = 0.0f,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const vec4f& color = 1.0f,
        Rect src = {0.0f, 0.0f, 1.0f, 1.0f}
    );
    inline void Draw
    (
        const Decal& dec,
        Transform& transform,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const vec4f& color = 1.0f,
        Rect src = {0.0f, 0.0f, 1.0f, 1.0f}
    );
    inline void Draw
    (
        const Decal& dec,
        const Rect& dst,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm,
        const vec4f& color = 1.0f,
        Rect src = {0.0f, 0.0f, 1.0f, 1.0f}
    );
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
    vbo.AddAttrib(0, 2, offsetof(sprite_batch_vertex, position));
    vbo.AddAttrib(1, 2, offsetof(sprite_batch_vertex, texcoord));
    vbo.AddAttrib(2, 4, offsetof(sprite_batch_vertex, color));
    vbo.AddAttrib(3, 1, offsetof(sprite_batch_vertex, texture));
}

inline void SpriteBatch::Draw
(
    const Decal& dec, 
    Transform& transform,
    Horizontal hor,
    Vertical ver,
    const vec4f& color, 
    Rect src
)
{
    assert(window);
    if(hor == Horizontal::Flip) std::swap(src.sx, src.ex);
    if(ver == Vertical::Flip) std::swap(src.sy, src.ey);
    const GLuint tex = textures.size() % maxSprites;
    const vec2f scrSize = window->GetScrSize();
    const float dw = dec.width * (src.ex - src.sx);
    const float dh = dec.height * (src.ey - src.sy);
    vertices.push_back({
        .position = scrToWorld(
            transform.Forward(-dw, dh),
            scrSize
        ),
        .texcoord = {
            src.sx,
            src.ey
        },
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = scrToWorld(
            transform.Forward(-dw, -dh),
            scrSize
        ),
        .texcoord = {
            src.sx,
            src.sy
        },
        .color = color, 
        .texture = tex
    });
    vertices.push_back({
        .position = scrToWorld(
            transform.Forward(dw, dh),
            scrSize
        ),
        .texcoord = {
            src.ex,
            src.ey
        },
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = scrToWorld(
            transform.Forward(dw, -dh),
            scrSize
        ),
        .texcoord = {
            src.ex,
            src.sy
        },
        .color = color,
        .texture = tex
    });
    textures.push_back(dec.id);
}

inline void SpriteBatch::Draw
(
    const Decal& dec, 
    const Rect& dst,
    Horizontal hor,
    Vertical ver,
    const vec4f& color, 
    Rect src
)
{
    assert(window);
    if(hor == Horizontal::Flip) std::swap(src.sx, src.ex);
    if(ver == Vertical::Flip) std::swap(src.sy, src.ey);
    const vec2f scale = {src.ex - src.sx, src.ey - src.sy};
    const GLuint tex = textures.size() % maxSprites;
    const vec2f scrSize = window->GetScrSize();
    vertices.push_back({
        .position = scrToWorld(
            vec2f{dst.sx, dst.ey} * scale,
            scrSize
        ),
        .texcoord = {
            src.sx,
            src.ey
        },
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = scrToWorld(
            vec2f{dst.sx, dst.sy} * scale,
            scrSize
        ),
        .texcoord = {
            src.sx,
            src.sy
        },
        .color = color, 
        .texture = tex
    });
    vertices.push_back({
        .position = scrToWorld(
            vec2f{dst.ex, dst.ey} * scale,
            scrSize
        ),
        .texcoord = {
            src.ex,
            src.ey
        },
        .color = color,
        .texture = tex
    });
    vertices.push_back({
        .position = scrToWorld(
            vec2f{dst.ex, dst.sy} * scale,
            scrSize
        ),
        .texcoord = {
            src.ex,
            src.sy
        },
        .color = color,
        .texture = tex
    });
    textures.push_back(dec.id);
}

inline void SpriteBatch::Draw
(
    const Decal& dec, 
    const vec2f& pos, 
    const vec2f& size, 
    const float rotation,
    Horizontal hor,
    Vertical ver,
    const vec4f& color, 
    Rect src
)
{
    assert(window);
    Transform transform;
    transform.Translate(pos.x, pos.y);
    transform.Rotate(rotation);
    transform.Scale(size.w, size.h);
    this->Draw(dec, transform, hor, ver, color, src);
}

inline void SpriteBatch::Flush()
{
    assert(window);
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