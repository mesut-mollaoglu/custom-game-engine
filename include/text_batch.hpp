#ifndef TEXT_BATCH_HPP
#define TEXT_BATCH_HPP

constexpr f32 g_kDefaultTextBatchCellWidth = 1.0f / (f32)(g_kNumCharacters);

struct TextBatch
{
    SpriteBatch m_sprBatch;
    Decal m_defFontDecal;
    inline TextBatch() = default;
    TextBatch(Window* window);
    void DrawCharacter(
        const vec2& pos,
        char c,
        const vec2& scale = vec2::One(),
        Flip flip = Flip::None,
        f32 rotation = 0.0f,
        f32 depth = 0.0f,
        const vec4& color = vec4::One()
    );  
    void DrawText(
        const vec2& pos,
        const std::string& text,
        const vec2& scale = vec2::One(),
        Flip flip = Flip::None,
        f32 rotation = 0.0f,
        const vec4& color = vec4::One(),
        const vec2& origin = vec2::Zero(),
        f32 depth = 0.0f
    );
    void DrawText(
        const std::string& text,
        Transform<f32>& transform,
        Flip flip = Flip::None,
        const vec4& color = vec4::One(),
        const vec2& origin = vec2::Zero(),
        f32 depth = 0.0f
    );
    void Flush();
};

#endif

#ifdef TEXT_BATCH_HPP
#undef TEXT_BATCH_HPP

inline TextBatch::TextBatch(Window* window)
{
    int p = 0;
    Sprite fontSpr = Sprite(g_kNumCharacters * (g_kDefaultFontSize.x + 1), g_kDefaultFontSize.y);
    fontSpr.Clear(0);
    for(int c = 0; c < g_kNumCharacters; c++)
    {
        for(int i = 0; i < g_kDefaultFontSize.x + 1; i++)
            for(int j = 0; j < g_kDefaultFontSize.y; j++)
                if(g_kDefaultFontData[c][j] & (1 << i))
                    fontSpr.SetPixel(p + g_kDefaultFontSize.x - i - 1, g_kDefaultFontSize.y - j, Colors::White);
        p += g_kDefaultFontSize.x + 1;
    }
    m_defFontDecal = Decal(fontSpr);
    m_sprBatch = SpriteBatch(window);
}

inline void TextBatch::DrawCharacter(
    const vec2& pos,
    char c,
    const vec2& scale,
    Flip flip,
    f32 rotation,
    f32 depth,
    const vec4& color)
{
    const f32 cell = g_kDefaultTextBatchCellWidth * ((int)c - 32);
    m_sprBatch.Draw 
    (
        m_defFontDecal,
        pos, scale, rotation,
        flip, depth, 
        {color, color, color, color}, 
        Rect<f32>{{cell, 0.0f}, {g_kDefaultTextBatchCellWidth, 1.0f}},
        vec2::Zero()
    );
}

inline void TextBatch::DrawText(
    const vec2& pos,
    const std::string& text,
    const vec2& scale,
    Flip flip,
    f32 rotation,
    const vec4& color,
    const vec2& origin,
    f32 depth)
{
    Transform<f32> transform;
    transform.Translate(pos);
    transform.Rotate(rotation);
    transform.Scale(scale);
    DrawText(text, transform, flip, color, origin, depth);
}

inline void TextBatch::DrawText(
    const std::string& text,
    Transform<f32>& transform,
    Flip flip,
    const vec4& color,
    const vec2& origin,
    f32 depth)
{
    if(text.empty()) return;
    transform.Invert();
    vec2 pos = vec2::Zero();
    const vec2 scale = transform.GetScale();
    const vec2 size = GetStringSize(text, scale);
    const vec2 v = GetVectorFromAngle(transform.GetRotation());
    const ivec2 d = {flip & Flip::Horizontal ? -1 : 1, flip & Flip::Vertical ? -1 : 1};
    const vec2 s = g_kDefaultFontSize * scale;
    vec2 p = pos = Rotate(transform.GetRotation(), {flip & Flip::Horizontal ? size.x - s.x : 0, flip & Flip::Vertical ? size.y - s.y : 0}, size * origin);
    for(char c : text)
    {
        DrawCharacter(pos, c, scale, flip, transform.GetRotation(), depth, color);
        if(c == '\n')
            pos = p += v.Perp() * (g_kDefaultFontSize.y + 1) * scale.h * d.y;
        else if(c == '\v')
            pos = p += v.Perp() * g_kDefaultVerticalTabSpace * scale.h * d.y;
        else
            pos += v * GetHorizontalCharSize(c, scale.w) * d.x;
    }
}

inline void TextBatch::Flush()
{
    m_sprBatch.Flush();
}

#endif