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
    inline void DrawCharacter
    (
        const int32_t x,
        const int32_t y,
        const char c,
        const v2f& size = 1.0f,
        const float rotation = 0.0f,
        const v4f& color = 1.0f
    );  
    inline void DrawText
    (
        const int32_t x,
        const int32_t y,
        const std::string& text,
        const v2f& size = 1.0f,
        const float rotation = 0.0f,
        const v4f& color = 1.0f,
        TextRenderMode renderMode = TextRenderMode::Right
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

inline void TextBatch::DrawCharacter
(
    const int32_t x,
    const int32_t y,
    const char c,
    const v2f& size,
    const float rotation,
    const v4f& color
)
{
    const float cell = textBatchCellWidth * ((int)c - 32);
    sprBatch.Draw 
    (
        defFontDecal,
        x, y, size, rotation,
        Horizontal::Norm,
        Vertical::Norm,
        color, Rect{
            cell, 0.0f, 
            cell + textBatchCellWidth, 1.0f
        }
    );
}  

inline void TextBatch::DrawText
(
    const int32_t x,
    const int32_t y,
    const std::string& text,
    const v2f& size,
    const float rotation,
    const v4f& color,
    TextRenderMode renderMode
)
{
    const std::size_t index = text.find_first_of('\n');
    const v2f rot = {std::cos(rotation), std::sin(rotation)};
    v2f pos = {(float)x, (float)y};
    if(index == std::string::npos)
    {
        pos -= rot * textModeMap.at(renderMode) * StringSize(text, size).w * 2.0f;
        for(const char c : text)
        {
            DrawCharacter(pos.x, pos.y, c, size, rotation, color);
            pos += CharSize(c, size.w) * rot * 2.0f;
        }
        return;
    }
    const float hypot = (defFontHeight + 1.0f) * size.h * 2.0f;
    DrawText(x, y, text.substr(0, index), size, rotation, color, renderMode);
    DrawText(x - hypot * rot.y, y + hypot * rot.x, text.substr(index + 1, text.size() - index), size, rotation, color, renderMode);
}

inline void TextBatch::Flush()
{
    sprBatch.Flush();
}

#endif