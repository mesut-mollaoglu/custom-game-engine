#ifndef TEXT_BATCH_H
#define TEXT_BATCH_H

#include "includes.h"

constexpr float textBatchCellWidth = 1.0f / (float)(numCharacters);

struct TextBatch
{
    SpriteBatch m_sprBatch;
    Decal m_defFontDecal;
    inline TextBatch() = default;
    TextBatch(Window* window);
    void DrawCharacter(
        const vec2& pos,
        const char c,
        const vec2& scale = 1.0f,
        float rotation = 0.0f,
        float depth = 0.0f,
        const vec4& color = 1.0f
    );  
    void DrawText(
        const vec2& pos,
        const std::string& text,
        const vec2& scale = 1.0f,
        float rotation = 0.0f,
        const vec4& color = 1.0f,
        const vec2& origin = 0.0f,
        float depth = 0.0f
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
    Sprite fontSpr = Sprite(numCharacters * (defFontSize.x + 1), defFontSize.y + 1);
    fontSpr.Clear(0);
    for(int c = 0; c < numCharacters; c++)
    {
        for(int i = 0; i < defFontSize.x + 1; i++)
            for(int j = 0; j < defFontSize.y + 1; j++)
                if(defFontData[c][j] & (1 << i))
                    fontSpr.SetPixel(drawPos + defFontSize.x - i - 1, defFontSize.y - j - 1, 0xFFFFFFFF);
        drawPos += defFontSize.x + 1;
    }
    m_defFontDecal = Decal(fontSpr);
    m_sprBatch = SpriteBatch(window);
}

inline void TextBatch::DrawCharacter(
    const vec2& pos,
    const char c,
    const vec2& scale,
    float rotation,
    float depth,
    const vec4& color)
{
    const float cell = textBatchCellWidth * ((int)c - 32);
    m_sprBatch.Draw 
    (
        m_defFontDecal,
        pos, scale, rotation,
        0, depth, 
        {color, color, color, color}, 
        Rect<float>{
            {cell, 0.0f}, 
            {textBatchCellWidth, 1.0f}
        }
    );
}  

inline void TextBatch::DrawText(
    const vec2& pos,
    const std::string& text,
    const vec2& scale,
    float rotation,
    const vec4& color,
    const vec2& origin,
    float depth)
{
    const float newLineOffset = (defFontSize.y + 1.0f) * scale.h;
    vec2 lineStartPos = pos;
    size_t index = 0, next = text.find_first_of('\n', index);
    const vec2 vec = {std::cos(rotation), std::sin(rotation)};
    auto drawTextFunc = [&](const std::string& str)
    {
        const vec2 o = GetStringSize(str, scale) * origin;
        vec2 currPos = rotate(rotation, lineStartPos, lineStartPos + o) - o;
        for(const char c : str)
        {
            DrawCharacter(currPos, c, scale, rotation, depth, color);
            currPos += GetCharSize(c, scale.w) * vec;
        }
        lineStartPos += newLineOffset * vec.perp();
    };
    while(index < text.size() && next != std::string::npos)
    {
        drawTextFunc(text.substr(index, next - index));
        index = next;
        next = text.find_first_of('\n', ++index);
    }
    if(next == std::string::npos)
        drawTextFunc(text.substr(index, text.size() - index));
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
    for(const char c : text)
    {
        for(float x = 0; x < scale.w * defFontSize.x; x++)
            for(float y = 0; y < scale.h * defFontSize.y; y++)
            {
                int32_t ox = std::floor(x / scale.w);
                int32_t oy = std::floor(y / scale.h);
                if(defFontData[(int)c - 32][oy] & (1 << ox))
                    res.SetPixel((int32_t)(pos.x + (defFontSize.x * scale.w - x)), (int32_t)(pos.y + (defFontSize.y * scale.h - y)), col);
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