#ifndef SPRITE_BATCH_HPP
#define SPRITE_BATCH_HPP

inline constexpr std::array<vec4, 4> g_kDefaultCornerColors = {vec4::One(), vec4::One(), vec4::One(), vec4::One()};

struct sprite_batch_vertex
{
    vec4 position;
    vec2 texcoord;
    vec4 color;
    u32 texture;
};

enum class SprSortMode : u8
{
    FrontToBack,
    BackToFront
};

struct SpriteBatch
{
    VAO m_vao;
    Window* m_windowHandle = nullptr;
    Buffer<sprite_batch_vertex, GL_ARRAY_BUFFER> m_vbo;
    Buffer<u16, GL_ELEMENT_ARRAY_BUFFER> m_ebo;
    std::vector<sprite_batch_vertex> m_vecVertices;
    std::vector<u16> m_vecIndices;
    std::vector<u32> m_vecTextures;
    Pass m_passMode = Pass::Pass2D;
    SprSortMode m_sprSortMode = SprSortMode::BackToFront;
    inline SpriteBatch() = default;
    SpriteBatch(Window* m_windowHandle);
    void Draw(
        const Decal& dec,
        const vec2& pos,
        const vec2& scale = vec2::One(),
        f32 rotation = 0.0f,
        const Flip& flip = Flip::None,
        f32 depth = 0.0f,
        const std::array<vec4, 4>& colors = g_kDefaultCornerColors,
        const Rect<f32>& src = {vec2::Zero(), vec2::One()},
        const vec2& origin = {0.5f, 0.5f}
    );
    void Draw(
        const Decal& dec,
        Transform<f32>& transform,
        const Flip& flip = Flip::None,
        f32 depth = 0.0f,
        const std::array<vec4, 4>& colors = g_kDefaultCornerColors,
        const Rect<f32>& src = {vec2::Zero(), vec2::One()},
        const vec2& origin = {0.5f, 0.5f}
    );
    void Draw(
        const Decal& dec,
        Rect<f32> dst,
        const Flip& flip = Flip::None,
        f32 depth = 0.0f,
        const std::array<vec4, 4>& colors = g_kDefaultCornerColors,
        const Rect<f32>& src = {vec2::Zero(), vec2::One()}
    );
    void Draw(
        const Decal& dec,
        const mat4& transform,
        const Flip& flip = Flip::None,
        const std::array<vec4, 4>& colors = g_kDefaultCornerColors,
        const Rect<f32>& src = {vec2::Zero(), vec2::One()},
        const vec2& origin = {0.5f, 0.5f}
    );
    void Draw(
        const Decal& dec,
        const std::array<vec3, 4>& points,
        const std::array<vec4, 4>& colors = g_kDefaultCornerColors,
        const Flip& flip = Flip::None,
        const Rect<f32>& src = {vec2::Zero(), vec2::One()}
    );
    void SortSprites();
    void Flush();
};

#endif

#ifdef SPRITE_BATCH_HPP
#undef SPRITE_BATCH_HPP


inline SpriteBatch::SpriteBatch(Window* window) : m_windowHandle(window)
{
    m_vao.Build();
    m_vbo.Build(GL_DYNAMIC_DRAW);
    m_ebo.Build(GL_DYNAMIC_DRAW);
    m_vbo.AddAttrib(0, 4, offsetof(sprite_batch_vertex, position));
    m_vbo.AddAttrib(1, 2, offsetof(sprite_batch_vertex, texcoord));
    m_vbo.AddAttrib(2, 4, offsetof(sprite_batch_vertex, color));
    m_vbo.AddAttrib(3, 1, offsetof(sprite_batch_vertex, texture));
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    Transform<f32>& transform,
    const Flip& flip,
    f32 depth,
    const std::array<vec4, 4>& colors, 
    const Rect<f32>& src,
    const vec2& origin)
{
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const vec2 norm = dec.GetSize() * src.size * origin;
    const vec2 inv = dec.GetSize() * src.size * (vec2::One() - origin);
    Draw(dec,
    {
        vec3{ScreenToWorldPos(transform.Forward(-norm), scrSize), depth},
        vec3{ScreenToWorldPos(transform.Forward(-norm.w, inv.h), scrSize), depth},
        vec3{ScreenToWorldPos(transform.Forward(inv.w, -norm.h), scrSize), depth},
        vec3{ScreenToWorldPos(transform.Forward(inv), scrSize), depth}
    }, colors, flip, src);
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    Rect<f32> dst,
    const Flip& flip,
    f32 depth,
    const std::array<vec4, 4>& colors,
    const Rect<f32>& src)
{
    dst *= src.size;
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    Draw(dec,
    {
        vec3{ScreenToWorldPos(dst.pos, scrSize), depth},
        vec3{ScreenToWorldPos({dst.pos.x, dst.pos.y + dst.size.y}, scrSize), depth},
        vec3{ScreenToWorldPos({dst.pos.x + dst.size.x, dst.pos.y}, scrSize), depth},
        vec3{ScreenToWorldPos(dst.pos + dst.size, scrSize), depth}
    }, colors, flip, src);
}

inline void SpriteBatch::Draw(
    const Decal& dec, 
    const vec2& pos, 
    const vec2& scale, 
    f32 rotation,
    const Flip& flip,
    f32 depth,
    const std::array<vec4, 4>& colors, 
    const Rect<f32>& src,
    const vec2& origin)
{
    Transform<f32> transform;
    transform.Translate(pos);
    transform.Rotate(rotation);
    transform.Scale(scale);
    Draw(dec, transform, flip, depth, colors, src, origin);
}

inline void SpriteBatch::Draw(
    const Decal& dec,
    const mat4& transform,
    const Flip& flip,
    const std::array<vec4, 4>& colors,
    const Rect<f32>& src,
    const vec2& origin)
{
    const vec2 scrSize = m_windowHandle->GetScreenSize();
    const f32 aspect = m_passMode == Pass::Pass3D ? 1.0f : scrSize.h / scrSize.w;
    const vec3 v = {aspect * src.size.w, src.size.h, 1.0f};
    const vec2 size = ScreenToWorldSize({dec.GetWidth() / aspect, (f32)dec.GetHeight()}, scrSize);
    const vec2 norm = size * origin; const vec2 inv = size * (vec2::One() - origin);
    Draw(dec,
    {
        (transform * vec4{-norm.w, inv.h, 0.0f, 1.0f}).xyz * v,
        (transform * vec4{-norm, 0.0f, 1.0f}).xyz * v,
        (transform * vec4{inv, 0.0f, 1.0f}).xyz * v,
        (transform * vec4{inv.w, -norm.h, 0.0f, 1.0f}).xyz * v
    }, colors, flip, src);
}

inline void SpriteBatch::Draw(
    const Decal& dec,
    const std::array<vec3, 4>& points,
    const std::array<vec4, 4>& colors,
    const Flip& flip,
    const Rect<f32>& src)
{
    assert(m_windowHandle);
    Frustum<f32>& frustum = m_windowHandle->GetActiveFrustum(m_passMode);
    vec2 suv = src.pos, euv = src.pos + src.size;
    if(flip & Flip::Horizontal) std::swap(suv.x, euv.x);
    if(flip & Flip::Vertical) std::swap(suv.y, euv.y);
    const u32 tex = m_vecTextures.size() % g_kSpriteBatchMaxSprites;
    const mat4 pv = frustum.GetMatrix();
    m_vecVertices.push_back({
        .position = pv * vec4{points[0], 1.0f},
        .texcoord = suv,
        .color = colors[0],
        .texture = tex
    });
    m_vecVertices.push_back({
        .position = pv * vec4{points[1], 1.0f},
        .texcoord = {suv.x, euv.y},
        .color = colors[1], 
        .texture = tex
    });
    m_vecVertices.push_back({
        .position = pv * vec4{points[2], 1.0f},
        .texcoord = {euv.x, suv.y},
        .color = colors[2],
        .texture = tex
    });
    m_vecVertices.push_back({
        .position = pv * vec4{points[3], 1.0f},
        .texcoord = euv,
        .color = colors[3],
        .texture = tex
    });
    m_vecTextures.push_back(dec.GetId());
}

inline void SpriteBatch::SortSprites()
{
    const usize size = m_vecVertices.size();
    switch(m_sprSortMode)
    {
        case SprSortMode::BackToFront:
            break;
        case SprSortMode::FrontToBack:
        {
            if(size > 0)
                for (usize i = 0; i < size - 1; i++)
                    for (usize j = 0; j < size - i - 1; j++)
                        if (m_vecVertices[j].position.z < m_vecVertices[j + 1].position.z)
                            std::swap(m_vecVertices[j].position.z, m_vecVertices[j + 1].position.z);
        }
        break;
    }
}

inline void SpriteBatch::Flush()
{
    assert(m_windowHandle);
    SortSprites();
    m_windowHandle->SetShader(1);
    i32 sprIndex = 0;
    auto vertBeg = m_vecVertices.begin();
    m_vao.Bind();
    while(vertBeg != m_vecVertices.end())
    {
        const i32 sprBatchSize = (m_vecVertices.end() - vertBeg) >> 2;
        const i32 sprCount = sprBatchSize < g_kSpriteBatchMaxSprites ? sprBatchSize : g_kSpriteBatchMaxSprites;
        m_vbo.Map(&(*vertBeg), sprCount * 4);
        m_vecIndices.resize(sprCount * 6);
        for (u16 i = 0, offset = 0; i < sprCount * 6; i += 6, offset += 4)
        {
            m_vecIndices[i + 0] = offset + 0;
            m_vecIndices[i + 1] = offset + 1;
            m_vecIndices[i + 2] = offset + 3;
            m_vecIndices[i + 3] = offset + 0;
            m_vecIndices[i + 4] = offset + 3;
            m_vecIndices[i + 5] = offset + 2;
        }
        m_ebo.Map(m_vecIndices);
        for(i32 i = 0; i < sprCount; i++) BindTexture(m_vecTextures[sprIndex + i], i);
        glDrawElements(GL_TRIANGLES, sprCount * 6, GL_UNSIGNED_SHORT, 0);
        sprIndex += sprCount;
        vertBeg += sprCount * 4;
        for(i32 i = 0; i < sprCount; i++) BindTexture(0, i);
    }
    m_vao.Unbind();
    m_vecTextures.clear();
    m_vecVertices.clear();
    m_vecIndices.clear();
}

#endif