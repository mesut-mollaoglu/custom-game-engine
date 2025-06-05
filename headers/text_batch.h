#ifndef TEXT_BATCH_H
#define TEXT_BATCH_H

constexpr f32 textBatchCellWidth = 1.0f / (f32)(numCharacters);

struct TextBatch
{
    SpriteBatch m_sprBatch;
    Decal m_defFontDecal;
    inline TextBatch() = default;
    TextBatch(Window* window);
    void DrawCharacter(
        const vec2& pos,
        char c,
        const vec2& scale = 1.0f,
        f32 rotation = 0.0f,
        f32 depth = 0.0f,
        const vec4& color = 1.0f
    );  
    void DrawText(
        const vec2& pos,
        const std::string& text,
        const vec2& scale = 1.0f,
        f32 rotation = 0.0f,
        const vec4& color = 1.0f,
        const vec2& origin = 0.0f,
        f32 depth = 0.0f
    );
    Sprite WriteToSpr(
        const std::string& text,
        const vec2& scale = 1.0f,
        const vec4& color = 1.0f
    );
    void Flush();
};

#endif

#ifdef TEXT_BATCH_H
#undef TEXT_BATCH_H

inline TextBatch::TextBatch(Window* window)
{
    int drawPos = 0;
    Sprite fontSpr = Sprite(numCharacters * (defFontSize.x + 1), defFontSize.y);
    fontSpr.Clear(0);
    for(int c = 0; c < numCharacters; c++)
    {
        for(int i = 0; i < defFontSize.x + 1; i++)
            for(int j = 0; j < defFontSize.y; j++)
                if(defFontData[c][j] & (1 << i))
                    fontSpr.SetPixel(drawPos + defFontSize.x - i - 1, defFontSize.y - j, Colors::White);
        drawPos += defFontSize.x + 1;
    }
    m_defFontDecal = Decal(fontSpr);
    m_sprBatch = SpriteBatch(window);
}

inline void TextBatch::DrawCharacter(
    const vec2& pos,
    char c,
    const vec2& scale,
    f32 rotation,
    f32 depth,
    const vec4& color)
{
    const f32 cell = textBatchCellWidth * ((int)c - 32);
    m_sprBatch.Draw 
    (
        m_defFontDecal,
        pos, scale, rotation,
        0, depth, 
        {color, color, color, color}, 
        Rect<f32>{
            {cell, 0.0f}, 
            {textBatchCellWidth, 1.0f}
        }, 0.0f
    );
}  

inline void TextBatch::DrawText(
    const vec2& pos,
    const std::string& text,
    const vec2& scale,
    f32 rotation,
    const vec4& color,
    const vec2& origin,
    f32 depth)
{
    const f32 vertLineOffset = (defFontSize.y + 1.0f) * scale.h;
    vec2 currDrawPos = pos;
    usize index = 0, next = text.find_first_of('\n', index);
    const vec2 ang = vec_from_angle(rotation);
    auto drawText = [&](const std::string& s)
    {
        const vec2 o = GetStringSize(s, scale) * origin;
        vec2 currPos = rotate(rotation, currDrawPos, currDrawPos + o) - o;
        for(char c : s)
        {
            DrawCharacter(currPos, c, scale, rotation, depth, color);
            currPos += GetCharSize(c, scale.w) * ang;
        }
        currDrawPos += vertLineOffset * ang.perp();
    };
    while(index < text.size() && next != std::string::npos)
    {
        drawText(text.substr(index, next - index));
        index = next;
        next = text.find_first_of('\n', ++index);
    }
    if(next == std::string::npos)
        drawText(text.substr(index, text.size() - index));
}

inline Sprite TextBatch::WriteToSpr(
    const std::string& text,
    const vec2& scale,
    const vec4& color)
{
    const vec2 stringSize = GetStringSize(text, scale);
    Sprite res = Sprite(stringSize.w, stringSize.h);
    const Color col = color;
    res.Clear(0);
    vec2 pos;
    for(char c : text)
    {
        for(f32 x = 0; x < scale.w * defFontSize.x; x++)
            for(f32 y = 0; y < scale.h * defFontSize.y; y++)
            {
                i32 ox = std::floor(x / scale.w);
                i32 oy = std::floor(y / scale.h);
                if(defFontData[(int)c - 32][oy] & (1 << ox))
                    res.SetPixel((i32)(pos.x + (defFontSize.x * scale.w - x)), (i32)(pos.y + (defFontSize.y * scale.h - y)), col);
            }
        if(c == '\n')
        {
            pos.y += (defFontSize.y + 1.0f) * scale.h;
            pos.x = 0.0f;
        }
        else
            pos.x += GetCharSize(c, scale.w);
    }
    return res;
}

inline void TextBatch::Flush()
{
    m_sprBatch.Flush();
}

#endif