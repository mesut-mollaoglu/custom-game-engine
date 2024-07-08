#ifndef TEXT_BATCH_H
#define TEXT_BATCH_H

#include "includes.h"

constexpr float textBatchCellWidth = 1.0f / (float)(numCharacters);

struct TextBatch
{
    SpriteBatch sprBatch;
    Decal defFontDecal;
    inline TextBatch() = default;
    inline TextBatch(Window& window);
    inline void DrawCharacter(
        const vec2f& pos,
        const char c,
        const vec2f& size = 1.0f,
        const float rotation = 0.0f,
        const float depth = 0.0f,
        const vec4f& color = 1.0f
    );  
    inline void DrawText(
        const vec2f& pos,
        const std::string& text,
        const vec2f& size = 1.0f,
        const float rotation = 0.0f,
        const vec4f& color = 1.0f,
        float textOffset = 0.0f,
        const float depth = 0.0f
    );
    inline Sprite WriteToSpr(
        const std::string& text,
        const vec2f& size = 1.0f,
        const vec4f& color = 1.0f
    );
    inline void Flush();
};

#endif

#ifdef TEXT_BATCH_H
#undef TEXT_BATCH_H

inline TextBatch::TextBatch(Window& window)
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
    sprBatch = SpriteBatch(&window);
}

inline void TextBatch::DrawCharacter(
    const vec2f& pos,
    const char c,
    const vec2f& size,
    const float rotation,
    const float depth,
    const vec4f& color)
{
    const float cell = textBatchCellWidth * ((int)c - 32);
    sprBatch.Draw 
    (
        defFontDecal,
        pos, size, rotation,
        Horizontal::Norm,
        Vertical::Norm,
        depth, color, 
        Rect<float>{
            {cell, 0.0f}, 
            {cell + textBatchCellWidth, 1.0f}
        }
    );
}  

inline void TextBatch::DrawText(
    const vec2f& pos,
    const std::string& text,
    const vec2f& size,
    const float rotation,
    const vec4f& color,
    float textOffset,
    const float depth)
{
    const std::size_t index = text.find_first_of('\n');
    const vec2f rot = {std::cos(rotation), std::sin(rotation)};
    vec2f drawPos = pos;
    if(index == std::string::npos)
    {
        drawPos -= rot * textOffset * StringSize(text, size).w * 2.0f;
        for(const char c : text)
        {
            DrawCharacter(drawPos, c, size, rotation, depth, color);
            drawPos += CharSize(c, size.w) * rot * 2.0f;
        }
        return;
    }
    const float hypot = (defFontHeight + 1.0f) * size.h * 2.0f;
    DrawText(pos, text.substr(0, index), size, rotation, color, textOffset, depth);
    DrawText(pos + hypot * vec2f{-rot.y, rot.x}, text.substr(index + 1, text.size() - index), size, rotation, color, textOffset, depth);
}

inline Sprite TextBatch::WriteToSpr(
    const std::string& text,
    const vec2f& size,
    const vec4f& color)
{
    const vec2f stringSize = StringSize(text, size);
    Sprite res = Sprite(stringSize.w, stringSize.h);
    const Color col = from_vec4(color);
    res.Clear(0x00000000);
    vec2f pos;
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