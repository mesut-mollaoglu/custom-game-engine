#ifndef TEXT_BATCH_H
#define TEXT_BATCH_H

#include "includes.h"

constexpr float textBatchCellWidth = 1.0f / (float)(numCharacters);

struct TextBatch
{
    SpriteBatch sprBatch;
    Decal defFontDecal;
    inline TextBatch() = default;
    TextBatch(Window* window);
    void DrawCharacter(
        const vec2& pos,
        const char c,
        const vec2& size = 1.0f,
        const float rotation = 0.0f,
        const float depth = 0.0f,
        const vec4& color = 1.0f
    );  
    void DrawText(
        const vec2& pos,
        const std::string& text,
        const vec2& size = 1.0f,
        const float rotation = 0.0f,
        const vec4& color = 1.0f,
        const vec2& origin = 0.0f,
        const float depth = 0.0f
    );
    Sprite WriteToSpr(
        const std::string& text,
        const vec2& size = 1.0f,
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
    Sprite fontSpr = Sprite(numCharacters * (defFontWidth + 1), defFontHeight + 1);
    fontSpr.Clear(0x00000000);
    for(int c = 0; c < numCharacters; c++)
    {
        for(int i = 0; i < defFontWidth + 1; i++)
            for(int j = 0; j < defFontHeight + 1; j++)
                if(defFontData[c][j] & (1 << i))
                    fontSpr.SetPixel(drawPos + defFontWidth - i - 1, defFontHeight - j - 1, 0xFFFFFFFF);
        drawPos += defFontWidth + 1;
    }
    defFontDecal = Decal(fontSpr);
    sprBatch = SpriteBatch(window);
}

inline void TextBatch::DrawCharacter(
    const vec2& pos,
    const char c,
    const vec2& size,
    const float rotation,
    const float depth,
    const vec4& color)
{
    const float cell = textBatchCellWidth * ((int)c - 32);
    sprBatch.Draw 
    (
        defFontDecal,
        pos, size, rotation,
        Horizontal::Norm,
        Vertical::Norm,
        depth, {color, color, color, color}, 
        Rect<float>{
            {cell, 0.0f}, 
            {textBatchCellWidth, 1.0f}
        }
    );
}  

inline void TextBatch::DrawText(
    const vec2& pos,
    const std::string& text,
    const vec2& size,
    const float rotation,
    const vec4& color,
    const vec2& origin,
    const float depth)
{
    const float newLineOffset = (defFontHeight + 1.0f) * size.h;
    vec2 lineStartPos = pos;
    size_t index = 0, next = text.find_first_of('\n', index);
    const vec2 vec = {std::cos(rotation), std::sin(rotation)};
    auto drawTextFunc = [&](const std::string& str)
    {
        const vec2 o = StringSize(str, size) * origin;
        vec2 currPos = rotate(rotation, lineStartPos, lineStartPos + o) - o;
        for(const char c : str)
        {
            DrawCharacter(currPos, c, size, rotation, depth, color);
            currPos += CharSize(c, size.w) * vec;
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
    const vec2& size,
    const vec4& color)
{
    const vec2 stringSize = StringSize(text, size);
    Sprite res = Sprite(stringSize.w, stringSize.h);
    const Color col = ColorU(color);
    res.Clear(0x00000000);
    vec2 pos;
    for(const char c : text)
    {
        for(float x = 0; x < size.w * defFontWidth; x++)
            for(float y = 0; y < size.h * defFontHeight; y++)
            {
                int32_t ox = std::floor(x / size.w);
                int32_t oy = std::floor(y / size.h);
                if(defFontData[(int)c - 32][oy] & (1 << ox))
                    res.SetPixel((int32_t)(pos.x + (defFontWidth * size.w - x)), (int32_t)(pos.y + (defFontHeight * size.h - y)), col);
            }
        if(c == '\n')
        {
            pos.y += (defFontHeight + 1.0f) * size.h;
            pos.x = 0.0f;
        }
        else
            pos.x += CharSize(c, size.w);
    }
    return res;
}

inline void TextBatch::Flush()
{
    sprBatch.Flush();
}

#endif