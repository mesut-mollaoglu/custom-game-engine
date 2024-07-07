#ifndef WINDOW_H
#define WINDOW_H

#include "includes.h"

constexpr float defFontWidth = 8;
constexpr float defFontHeight = 13;
constexpr float defTabSpace = 18;
constexpr int maxSprites = 32;
constexpr int maxGeoBatchVertices = 48;
constexpr int maxGeoBatchIndices = 64;
constexpr int numCharacters = 95;
constexpr int defTextureSlot = 0;
constexpr vec3f defWorldUp = {0.0f, 1.0f, 0.0f};
constexpr vec3f defCameraPos = {0.0f, 0.0f, 5.0f};

constexpr uint8_t defFontData[numCharacters][(int)defFontHeight] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36},
{0x00, 0x00, 0x00, 0x66, 0x66, 0xff, 0x66, 0x66, 0xff, 0x66, 0x66, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x7e, 0xff, 0x1b, 0x1f, 0x7e, 0xf8, 0xd8, 0xff, 0x7e, 0x18},
{0x00, 0x00, 0x0e, 0x1b, 0xdb, 0x6e, 0x30, 0x18, 0x0c, 0x76, 0xdb, 0xd8, 0x70},
{0x00, 0x00, 0x7f, 0xc6, 0xcf, 0xd8, 0x70, 0x70, 0xd8, 0xcc, 0xcc, 0x6c, 0x38},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x0c, 0x0e},
{0x00, 0x00, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c},
{0x00, 0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x30},
{0x00, 0x00, 0x00, 0x00, 0x99, 0x5a, 0x3c, 0xff, 0x3c, 0x5a, 0x99, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 0x00, 0x00},
{0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x06, 0x03, 0x03},
{0x00, 0x00, 0x3c, 0x66, 0xc3, 0xe3, 0xf3, 0xdb, 0xcf, 0xc7, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x38, 0x18},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0xe7, 0x7e},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0x07, 0x03, 0x03, 0xe7, 0x7e},
{0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xcc, 0x6c, 0x3c, 0x1c, 0x0c},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x03, 0x03, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x03, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x1c, 0x1c, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06},
{0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60},
{0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x18, 0x0c, 0x06, 0x03, 0xc3, 0xc3, 0x7e},
{0x00, 0x00, 0x3f, 0x60, 0xcf, 0xdb, 0xd3, 0xdd, 0xc3, 0x7e, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff},
{0x00, 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c},
{0x00, 0x03, 0x03, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x60, 0x60},
{0x00, 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18},
{0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x38, 0x30, 0x70},
{0x00, 0x00, 0x7f, 0xc3, 0xc3, 0x7f, 0x03, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0x7e, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03},
{0x00, 0x00, 0x7f, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x33, 0x1e},
{0x7e, 0xc3, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x00},
{0x38, 0x6c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x0c, 0x00},
{0x00, 0x00, 0xc6, 0xcc, 0xf8, 0xf0, 0xd8, 0xcc, 0xc6, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78},
{0x00, 0x00, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xfe, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00},
{0xc0, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0x00, 0x00, 0x00, 0x00},
{0x03, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xfe, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xfe, 0x03, 0x03, 0x7e, 0xc0, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x1c, 0x36, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x00},
{0x00, 0x00, 0x7e, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xdb, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0xc0, 0x60, 0x60, 0x30, 0x18, 0x3c, 0x66, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xff, 0x60, 0x30, 0x18, 0x0c, 0x06, 0xff, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x0f, 0x18, 0x18, 0x18, 0x38, 0xf0, 0x38, 0x18, 0x18, 0x18, 0x0f},
{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
{0x00, 0x00, 0xf0, 0x18, 0x18, 0x18, 0x1c, 0x0f, 0x1c, 0x18, 0x18, 0x18, 0xf0},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x8f, 0xf1, 0x60, 0x00, 0x00, 0x00}};

inline float CharSize(const char c, float size)
{
    if(c == '\t')
        return defTabSpace * size;
    else
        return (defFontWidth + 1) * size;
}

inline vec2f StringSize(const std::string& text, vec2f size)
{
    vec2f stringSize = {0.0f, defFontHeight};
    float buffer = 0.0f;
    for(const char c : text)
    {
        if(c == '\n')
        {
            stringSize.w = std::max(stringSize.w, buffer);
            stringSize.h += defFontHeight + 1.0f;
            buffer = 0.0f;
        }
        else
            buffer += CharSize(c, size.w);
    }
    return {std::max(stringSize.w, buffer), stringSize.h * size.h};
}

enum class DrawMode
{
    Normal,
    Clamp,
    Periodic
};

enum class PixelMode
{
    Normal,
    Mask
};

enum class Horizontal
{
    Norm,
    Flip
};

enum class Vertical
{
    Norm,
    Flip
};

struct Rect
{
    union 
    {
        struct { float sx, sy, ex, ey; };
        struct { float left, top, right, bottom; };
    };
    inline constexpr Rect() : sx(0.0f), sy(0.0f), ex(0.0f), ey(0.0f) {}
    inline constexpr Rect(float sx, float sy, float ex, float ey) : sx(sx), sy(sy), ex(ex), ey(ey) {}
    inline friend constexpr Rect operator*=(Rect& lhs, const float rhs)
    {
        lhs.sx *= rhs; lhs.ex *= rhs;
        lhs.sy *= rhs; lhs.ey *= rhs;
        return lhs;
    }
    inline friend constexpr Rect operator+=(Rect& lhs, const float rhs)
    {
        lhs.sx += rhs; lhs.ex += rhs;
        lhs.sy += rhs; lhs.ey += rhs;
        return lhs;
    }
    inline friend constexpr Rect operator-=(Rect& lhs, const float rhs)
    {
        lhs.sx -= rhs; lhs.ex -= rhs;
        lhs.sy -= rhs; lhs.ey -= rhs;
        return lhs;
    }
    inline friend constexpr Rect operator*=(Rect& lhs, const vec2f& rhs)
    {
        lhs.sx *= rhs.x; lhs.ex *= rhs.x;
        lhs.sy *= rhs.y; lhs.ey *= rhs.y;
        return lhs;
    }
    inline friend constexpr Rect operator+=(Rect& lhs, const vec2f& rhs)
    {
        lhs.sx += rhs.x; lhs.ex += rhs.x;
        lhs.sy += rhs.y; lhs.ey += rhs.y;
        return lhs;
    }
    inline friend constexpr Rect operator-=(Rect& lhs, const vec2f& rhs)
    {
        lhs.sx -= rhs.x; lhs.ex -= rhs.x;
        lhs.sy -= rhs.y; lhs.ey -= rhs.y;
        return lhs;
    }
    inline friend constexpr bool operator==(const Rect& lhs, const Rect& rhs)
    {
        return lhs.sx == rhs.sx && lhs.ex == rhs.ex && lhs.sy == rhs.sy && lhs.ey == rhs.ey;
    }
    inline friend constexpr bool operator!=(const Rect& lhs, const Rect& rhs)
    {
        return !(lhs == rhs);
    }
    inline friend constexpr Rect operator+(const Rect& lhs, const float rhs)
    {
        Rect res = lhs;
        res += rhs;
        return res;
    }
    inline friend constexpr Rect operator-(const Rect& lhs, const float rhs)
    {
        Rect res = lhs;
        res -= rhs;
        return res;
    }
    inline friend constexpr Rect operator*(const Rect& lhs, const float rhs)
    {
        Rect res = lhs;
        res *= rhs;
        return res;
    }
    inline friend constexpr Rect operator+(const Rect& lhs, const vec2f& rhs)
    {
        Rect res = lhs;
        res += rhs;
        return res;
    }
    inline friend constexpr Rect operator-(const Rect& lhs, const vec2f& rhs)
    {
        Rect res = lhs;
        res -= rhs;
        return res;
    }
    inline friend constexpr Rect operator*(const Rect& lhs, const vec2f& rhs)
    {
        Rect res = lhs;
        res *= rhs;
        return res;
    }
    inline constexpr void Scale(float scale)
    {
        operator*=(*this, scale);
    }
    inline constexpr void Translate(float dx, float dy)
    {
        sx += dx; ex += dx;
        sy += dy; ey += dy;
    }
    inline constexpr bool Contains(const vec2f& lhs)
    {
        return lhs.x >= sx && lhs.x <= ex && lhs.y <= ey && lhs.y >= sy;
    }
    inline constexpr bool Overlaps(const Rect& lhs)
    {
        return sx <= lhs.ex && lhs.sx <= ex && sy <= lhs.ey && lhs.sy <= ey;
    }
};

struct Color
{
    union
    {
        uint32_t color;
        uint8_t data[4];
        struct { uint8_t r, g, b, a; };
    };
    inline constexpr Color() : r(0), g(0), b(0), a(255) {}
    inline constexpr Color(const uint32_t& lhs) : color(lhs) {}
    inline constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
    inline constexpr Color(const Color& lhs) = default;
    inline constexpr Color& operator=(const Color& lhs) = default;
    inline friend constexpr Color operator/=(Color& lhs, const float rhs)
    {
        lhs.r = std::clamp<uint8_t>(lhs.r / rhs, 0, 255);
        lhs.g = std::clamp<uint8_t>(lhs.g / rhs, 0, 255);
        lhs.b = std::clamp<uint8_t>(lhs.b / rhs, 0, 255);
        lhs.a = std::clamp<uint8_t>(lhs.a / rhs, 0, 255);    
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, const float rhs)
    {
        lhs.r = std::clamp<uint8_t>(lhs.r * rhs, 0, 255);
        lhs.g = std::clamp<uint8_t>(lhs.g * rhs, 0, 255);
        lhs.b = std::clamp<uint8_t>(lhs.b * rhs, 0, 255);
        lhs.a = std::clamp<uint8_t>(lhs.a * rhs, 0, 255);    
        return lhs;
    }
    inline friend constexpr Color operator+=(Color& lhs, const uint8_t rhs)
    {
        lhs.r = std::clamp(lhs.r + rhs, 0, 255);
        lhs.g = std::clamp(lhs.g + rhs, 0, 255);
        lhs.b = std::clamp(lhs.b + rhs, 0, 255);
        lhs.a = std::clamp(lhs.a + rhs, 0, 255);    
        return lhs;
    }
    inline friend constexpr Color operator-=(Color& lhs, const uint8_t rhs)
    {
        lhs.r = std::clamp(lhs.r - rhs, 0, 255);
        lhs.g = std::clamp(lhs.g - rhs, 0, 255);
        lhs.b = std::clamp(lhs.b - rhs, 0, 255);
        lhs.a = std::clamp(lhs.a - rhs, 0, 255);    
        return lhs;
    }
    inline friend constexpr Color operator+=(Color& lhs, const Color& rhs)
    {
        lhs.r = std::clamp(lhs.r + rhs.r, 0, 255);
        lhs.g = std::clamp(lhs.g + rhs.g, 0, 255);
        lhs.b = std::clamp(lhs.b + rhs.b, 0, 255);
        lhs.a = std::clamp(lhs.a + rhs.a, 0, 255);    
        return lhs;
    }
    inline friend constexpr Color operator-=(Color& lhs, const Color& rhs)
    {
        lhs.r = std::clamp(lhs.r - rhs.r, 0, 255);
        lhs.g = std::clamp(lhs.g - rhs.g, 0, 255);
        lhs.b = std::clamp(lhs.b - rhs.b, 0, 255);
        lhs.a = std::clamp(lhs.a - rhs.a, 0, 255);    
        return lhs;
    }
    inline friend constexpr Color operator*(const Color& lhs, const float rhs)
    {
        Color res = lhs;
        res *= rhs;
        return res;
    }
    inline friend constexpr Color operator/(const Color& lhs, const float rhs)
    {
        Color res = lhs;
        res /= rhs;
        return res;
    }
    inline friend constexpr Color operator+(const Color& lhs, const uint8_t rhs)
    {
        Color res = lhs;
        res += rhs;
        return res;
    }
    inline friend constexpr Color operator-(const Color& lhs, const uint8_t rhs)
    {
        Color res = lhs;
        res -= rhs;
        return res;
    }
    inline friend constexpr Color operator-(const Color& lhs, const Color& rhs)
    {
        Color res = lhs;
        res -= rhs;
        return res;
    }
    inline friend constexpr Color operator+(const Color& lhs, const Color& rhs)
    {
        Color res = lhs;
        res += rhs;
        return res;
    }
    inline friend constexpr bool operator==(const Color& lhs, const Color& rhs)
    {
        return lhs.color == rhs.color;
    }
    inline friend constexpr bool operator!=(const Color& lhs, const Color& rhs)
    {
        return lhs.color != rhs.color;
    }
    inline friend constexpr bool operator<(const Color& lhs, const Color& rhs)
    {
        return (lhs.r < rhs.r && lhs.g < rhs.g && lhs.b < rhs.b && lhs.a <= rhs.a);
    }
    inline friend constexpr bool operator>(const Color& lhs, const Color& rhs)
    {
        return (lhs.r > rhs.r && lhs.g > rhs.g && lhs.b > rhs.b && lhs.a >= rhs.a);
    }
    inline const uint8_t operator[](const std::size_t& index) const
    {
        return data[index];
    }
    inline uint8_t& operator[](const std::size_t& index)
    {
        return data[index];
    }
    inline constexpr Color Lerp(const Color& color, float frac)
    {
        return 
        {
            static_cast<uint8_t>((color.r - r) * frac + r),
            static_cast<uint8_t>((color.g - g) * frac + g),
            static_cast<uint8_t>((color.b - b) * frac + b),
            static_cast<uint8_t>((color.a - a) * frac + a)
        };
    }
    template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
    inline constexpr Vector<T, 4> vec4() const
    {
        return 
        {
            static_cast<T>(r) / 255, 
            static_cast<T>(g) / 255, 
            static_cast<T>(b) / 255, 
            static_cast<T>(a) / 255
        };
    }
};

template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
inline Color from_vec4(const Vector<T, 4>& vec)
{
    return
    {
        static_cast<uint8_t>(vec.r * T(255)),
        static_cast<uint8_t>(vec.g * T(255)),
        static_cast<uint8_t>(vec.b * T(255)),
        static_cast<uint8_t>(vec.a * T(255))
    };
}

inline Color RndColor()
{
    return 
    {
        rand<uint8_t>(0, 255),
        rand<uint8_t>(0, 255),
        rand<uint8_t>(0, 255),
        rand<uint8_t>(0, 255)
    };
}

struct Vertex
{
    vec2f pos;
    vec2f tex;
#if defined VERTEX_COLOR
    Color color;
#endif
};

struct Sprite
{
    DrawMode drawMode = DrawMode::Normal;
    int32_t width = 0, height = 0;
    std::vector<Color> data;
    inline Sprite() = default;
    inline Sprite(int32_t w, int32_t h);
    inline Sprite(const std::string& path);
    inline void SetPixel(int32_t x, int32_t y, Color color);
    inline Color GetPixel(int32_t x, int32_t y);
    inline void Clear(const Color& color);
    inline void Resize(int32_t w, int32_t h);
    inline void Scale(float sx, float sy);
    inline void Tint(const Color& color);
    inline Sprite GetSrc(const Rect& src);
    inline Rect GetViewport();
    inline vec2f GetSize();
};

inline void CreateTexture(GLuint& id, const int32_t& width, const int32_t& height)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
}

inline void UpdateTexture(GLuint& id, const int32_t& width, const int32_t& height, void* data)
{
    glBindTexture(GL_TEXTURE_2D, id);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

inline void BindTexture(GLuint id, int slot = 0)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

inline vec2f scrToWorldSize(vec2f size, vec2f scrSize)
{
    return {
        size.w * 2.0f / scrSize.w,
        size.h * 2.0f / scrSize.h
    };
}

inline vec2f worldToScrSize(vec2f size, vec2f scrSize)
{
    return {
        size.w * scrSize.w / 2.0f,
        size.h * scrSize.h / 2.0f
    };
}

inline vec2f scrToWorldPos(vec2f pos, vec2f scrSize)
{
    return {
        pos.x * 2.0f / scrSize.w - 1.0f,
        -pos.y * 2.0f / scrSize.h + 1.0f
    };
}

inline vec2f worldToScrPos(vec2f pos, vec2f scrSize)
{
    return {
        (pos.x + 1.0f) * scrSize.w / 2.0f,
        (-pos.y + 1.0f) * scrSize.h / 2.0f
    };
}

enum class CameraType
{
    Persp,
    Ortho
};

struct Window;

struct Camera
{
    vec3f pos;
    vec3f up;
    vec3f forward;
    vec3f right;
    vec3f orientation;
    mat4x4f proj, view;
    vec2f prevMousePos, currMousePos;
    float sensitivity = 100.0f;
    float velocity = 2.5f;
    std::function<void(Camera&, Window*)> updateFunc = nullptr;
    inline Camera() = default;
    inline Camera(Window* window, const CameraType& camType);
    inline void Update(Window* window);
    inline void UpdateVectors();
};

struct Layer
{
    Sprite buffer;
    uint32_t id;
    vec2f offset = 0.0f;
    bool camEnabled = false;
    inline Layer() = default;
    inline Layer(int32_t width, int32_t height);
};

struct default_vertex
{
    vec2f position;
    vec2f texcoord;
};

struct default_3d_vertex
{
    vec3f position;
    vec3f normal;
    vec2f texcoord;
    vec4f color;
};

struct Renderable3D
{
    VAO vao;
    Buffer<default_3d_vertex, GL_ARRAY_BUFFER> vbo;
    Buffer<uint16_t, GL_ELEMENT_ARRAY_BUFFER> ebo;
    Transform3D transform;
    vec4f material = 1.0f;
    GLuint texture = 0;
    std::function<void()> drawFunc = nullptr;
};

struct Decal
{
    GLuint id = 0;
    int32_t width = 0, height = 0;
    inline Decal() = default;
    inline Decal(Sprite& spr);
    inline Decal(const std::string& path);
    inline void Update(Sprite& spr);
};

enum class Key
{
    Pressed,
    Held,
    Released,
    None
};

struct Timer
{
    time_point now;
    float deltaTime;
    inline Timer();
    inline void Update();
};

enum class Pass
{
    Pass2D,
    Pass3D
};

struct Window
{
    inline Window() = default;
    inline Window(int32_t width, int32_t height);
    inline void Clear(const Color& color);
    inline void Begin();
    inline void End();
    inline void EnableDepth(bool depth);
    inline int32_t GetWidth();
    inline int32_t GetHeight();
    inline vec2d GetMousePos();
    inline vec2f GetScrSize();
    inline Rect GetViewport();
    inline float GetDeltaTime();
    inline Key GetKey(int key);
    inline Key GetMouseButton(int button);
    inline DrawMode GetDrawMode();
    inline void SetDrawMode(DrawMode drawMode);
    inline Layer& GetLayer(const std::size_t& index);
    inline void SetCurrentLayer(const std::size_t& index);
    inline void CreateLayer(int32_t width, int32_t height);
    inline void SetShader(const std::size_t& index);
    inline Shader& GetShader(const std::size_t& index);
    inline void SetPixel(int32_t x, int32_t y, Color color);
    inline Color GetPixel(int32_t x, int32_t y);
    inline bool ClipLine(int32_t& sx, int32_t& sy, int32_t& ex, int32_t& ey);
    inline void DrawLine(int32_t sx, int32_t sy, int32_t ex, int32_t ey, Color color);
    inline void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, Color color);
    inline void DrawRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, Color color);
    inline void DrawRotatedRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, float rotation, Color color);
    inline void DrawCircle(int32_t cx, int32_t cy, int32_t radius, Color color);
    inline void DrawCircleOutline(int32_t cx, int32_t cy, int32_t radius, Color color);
    inline void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, Color color);
    inline void DrawTexturedTriangle(Sprite& sprite, Vertex v1, Vertex v2, Vertex v3);
    inline void DrawTriangleOutline(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, Color color);
    inline void DrawSprite(Sprite& sprite, Transform& transform, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(int32_t x, int32_t y, Sprite& sprite, vec2f size = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(int32_t x, int32_t y, Rect dst, Sprite& sprite, vec2f size = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(Rect dst, Sprite& sprite, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(Rect dst, Rect src, Sprite& sprite, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawCharacter(int32_t x, int32_t y, const char c, vec2f size = 1.0f, Color color = {0, 0, 0, 255});
    inline void DrawRotatedCharacter(int32_t x, int32_t y, const char c, float rotation, vec2f size = 1.0f, Color color = {0, 0, 0, 255});
    inline void DrawCharacter(Rect dst, const char c, Color color = {0, 0, 0, 255});
    inline void DrawText(Rect dst, const std::string& text, Color color = {0, 0, 0, 255});
    inline void DrawRotatedText(int32_t x, int32_t y, const std::string& text, float rotation, vec2f size = 1.0f, Color color = {0, 0, 0, 255}, float textOffset = 0.0f);
    inline void DrawText(int32_t x, int32_t y, const std::string& text, vec2f size = 1.0f, Color color = {0, 0, 0, 255}, float textOffset = 0.0f);
    inline void Draw3D(Renderable3D& renderable);
    std::vector<Shader> shaders;
    std::unordered_map<int, Key> currKeyboardState;
    std::unordered_map<int, Key> currMouseState;
    PixelMode pixelMode = PixelMode::Normal;
    std::vector<Layer> drawTargets;
    std::size_t currentDrawTarget;
    std::size_t currentShader;
    GLFWwindow* handle;
    bool depthEnabled = false;
    std::vector<Camera> cameras;
    Timer timer;
    VAO vao;
    Buffer<default_vertex, GL_ARRAY_BUFFER> vbo;
    virtual ~Window()
    {
        glfwDestroyWindow(handle);
        glfwTerminate();
    }
};

struct Button
{
    Sprite image;
    vec2f position;
    vec2f size = 1.0f;
    int button;
    Window* window = nullptr;
    inline Button() = default;
    inline Button(Window* window, const std::string& path, int button);
    inline bool Clicked();
    inline bool Hover();
    inline void Draw();
    ~Button() {}
};

struct SpriteSheet
{
    Sprite sprite;
    vec2i cellSize;
    inline SpriteSheet() = default;
    inline SpriteSheet(const std::string& path, const vec2i& cellSize);
    inline Rect GetCell(const vec2i& cell);
    inline void Draw
    (
        Window& window, 
        const vec2i& pos, 
        const vec2f& size, 
        const vec2i& cell, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm
    );
    ~SpriteSheet() {}
};

#endif

#ifdef WINDOW_H
#undef WINDOW_H

inline Sprite::Sprite(int32_t w, int32_t h) : width(w), height(h)
{
    data.resize(width * height);
}

inline Sprite::Sprite(const std::string& path)
{
    int channels;
    unsigned char *bytes = stbi_load(path.c_str(), &width, &height, &channels, 4);
    data.resize(width * height);
    memcpy(data.data(), bytes, 4 * width * height);
    stbi_image_free(bytes);
}

inline void Sprite::SetPixel(int32_t x, int32_t y, Color color)
{
    switch(drawMode)
    {
        case DrawMode::Normal:
        {
            if(x < 0 || x >= width || y < 0 || y >= height) 
                return;
        }
        break;
        case DrawMode::Periodic:
        {
            x = x % width; x += (x < 0) ? width : 0;
            y = y % height; y += (y < 0) ? height : 0;
        }
        break;
        default: break;
    }
    data[width * y + x] = color;
}

inline Color Sprite::GetPixel(int32_t x, int32_t y)
{
    switch(drawMode)
    {
        case DrawMode::Normal:
        {
            if(x < 0 || x >= width || y < 0 || y >= height) 
                return 0x00000000;
        }
        break;
        case DrawMode::Periodic:
        {
            x = x % width; x += (x < 0) ? width : 0;
            y = y % height; y += (y < 0) ? height : 0;
        }
        break;
        case DrawMode::Clamp:
        {
            x = std::clamp(x, 0, width - 1);
            y = std::clamp(y, 0, height - 1);
        }
        break;
    }
    return data[width * y + x];
}

inline void Sprite::Scale(float sx, float sy)
{
    const float w = width * sx;
    const float h = height * sy;
    Sprite res = Sprite(w, h);
    for(float x = 0; x < w; x++)
        for(float y = 0; y < h; y++)
        {
            int32_t ox = std::floor(x / sx);
            int32_t oy = std::floor(y / sy);
            res.SetPixel((int32_t)(x), (int32_t)(y), GetPixel(ox, oy));
        }
    *this = res;
}

inline void Sprite::Resize(int32_t w, int32_t h)
{
    Scale((float)w / width, (float)h / height);
}

inline void Sprite::Clear(const Color& color)
{
    for(Color& c : data) c = color;
}

inline void Sprite::Tint(const Color& color)
{
    Sprite res = Sprite(width, height);
    for(int i = 0; i < width * height; i++)
        res.data[i] = data[i].a == 0 ? data[i] : data[i].Lerp(color, 0.5f);
    *this = res;
}

inline Sprite Sprite::GetSrc(const Rect& src)
{
    Sprite res = Sprite(src.ex - src.sx, src.ey - src.sy);
    for(int32_t i = 0; i < res.width; i++)
        for(int32_t j = 0; j < res.height; j++)
            res.SetPixel(i, j, GetPixel(src.sx + i, src.sy + j));
    return res;
}

inline vec2f Sprite::GetSize()
{
    return {(float)width, (float)height};
}

inline Rect Sprite::GetViewport()
{
    return {0.0f, 0.0f, (float)width, (float)height};
}

inline Timer::Timer()
{
    now = steady_clock::now();
}

inline void Timer::Update()
{
    deltaTime = std::chrono::duration<float>(steady_clock::now() - now).count();
    now = steady_clock::now();
}

inline Layer::Layer(int32_t width, int32_t height)
{
    buffer = Sprite(width, height);
    CreateTexture(id, width, height);
}

inline Decal::Decal(Sprite& spr) : width(spr.width), height(spr.height)
{
    CreateTexture(id, width, height);
    UpdateTexture(id, width, height, spr.data.data());
}

inline void Decal::Update(Sprite& spr)
{
    UpdateTexture(id, width, height, spr.data.data());
}

inline Decal::Decal(const std::string& path)
{
    int channels;
    unsigned char *bytes = stbi_load(path.c_str(), &width, &height, &channels, 4);
    CreateTexture(id, width, height);
    UpdateTexture(id, width, height, bytes);
    stbi_image_free(bytes);
}

inline Camera::Camera(Window* window, const CameraType& camType) : orientation({0.0f, 0.0f, -90.0f}), pos(defCameraPos)
{
    prevMousePos = currMousePos = window->GetMousePos();
    const vec2f scrSize = window->GetScrSize();
    UpdateVectors();
    if(camType == CameraType::Persp) proj = make_perspective_mat(scrSize.w / scrSize.h, 90.0f, 0.1f, 100.0f);
    else proj = make_ortho_mat(1.0f, -1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
}

inline void Camera::Update(Window* window)
{
    if(updateFunc != nullptr) updateFunc(*this, window);
}

inline void Camera::UpdateVectors()
{
    const float yaw = deg2rad(orientation.yaw);
    const float pitch = deg2rad(orientation.pitch);
    forward = vec3f{std::cos(yaw) * std::cos(pitch), std::sin(pitch), std::sin(yaw) * std::cos(pitch)}.norm();
    right = cross(forward, defWorldUp).norm();
    up = cross(right, forward).norm();
    view = mat_look_at(pos, pos + forward, up);
}

inline Window::Window(int32_t width, int32_t height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    handle = glfwCreateWindow(width, height, "opengl-window", nullptr, nullptr);
    glfwMakeContextCurrent(handle);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return;
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    EnableDepth(true);
    CreateLayer(width, height);
    SetCurrentLayer(0);
    cameras.emplace_back(this, CameraType::Persp);
    cameras.emplace_back(this, CameraType::Ortho);
    cameras[0].updateFunc = [](Camera& cam, Window* window)
    {
        const float dt = window->timer.deltaTime;
        cam.prevMousePos = cam.currMousePos;
        cam.currMousePos = window->GetMousePos();
        const vec2f offset = (cam.prevMousePos - cam.currMousePos) * cam.sensitivity * dt;
        cam.orientation.yaw -= offset.x;
        cam.orientation.pitch += offset.y;
        cam.orientation.pitch = std::clamp(cam.orientation.pitch, -89.0f, 89.0f);
        if(window->GetKey(GLFW_KEY_UP) == Key::Held) cam.pos += cam.forward * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_DOWN) == Key::Held) cam.pos -= cam.forward * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_RIGHT) == Key::Held) cam.pos += cam.right * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_LEFT) == Key::Held) cam.pos -= cam.right * cam.velocity * dt;
        cam.UpdateVectors();
    };
    shaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\default_vert.glsl").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\default_frag.glsl").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniformMat("ortho_mat", cameras[1].proj * cameras[1].view);
        }
    ));
    shaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\sprite_batch_vert.glsl").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\sprite_batch_frag.glsl").c_str())
        }),
        [&](Shader& instance)
        {
            for(int i = 0; i < maxSprites; i++)
                instance.SetUniformInt("buffers[" + std::to_string(i) + "]", &i);
        },
        [&](Shader& instance)
        {
            instance.SetUniformMat("persp_mat", cameras[0].proj * cameras[0].view);
            instance.SetUniformMat("ortho_mat", cameras[1].proj * cameras[1].view);
        }
    ));
    shaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\geo_batch_vert.glsl").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\geo_batch_frag.glsl").c_str())
        }),
        nullptr,
        [&](Shader& instance)
        {
            instance.SetUniformMat("persp_mat", cameras[0].proj * cameras[0].view);
            instance.SetUniformMat("ortho_mat", cameras[1].proj * cameras[1].view);
        }
    ));
    shaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\default_3d_vert.glsl").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\default_3d_frag.glsl").c_str())
        }),
        nullptr,
        [&](Shader& instance)
        {
            instance.SetUniformMat("camera_mat", cameras[0].proj * cameras[0].view);
        }
    ));
    SetShader(0);
    std::vector<default_vertex> vertices = 
    {
        {{-1.0f,  1.0f}, {0.0f, 0.0f}},
        {{-1.0f, -1.0f}, {0.0f, 1.0f}},
        {{ 1.0f,  1.0f}, {1.0f, 0.0f}},
        {{ 1.0f, -1.0f}, {1.0f, 1.0f}}
    };
    vao.Build();
    vbo.Build(vertices);
    vbo.AddAttrib(0, 2, offsetof(default_vertex, position));
    vbo.AddAttrib(1, 2, offsetof(default_vertex, texcoord));
}

inline float Window::GetDeltaTime()
{
    return timer.deltaTime;
}

inline void Window::SetShader(const std::size_t& index)
{
    if(currentShader == index || index >= shaders.size()) return;
    shaders[index].Set();
    shaders[index].Update();
    currentShader = index;
}

inline Key Window::GetKey(int key)
{
    const int count = currKeyboardState.count(key);
    const int currState = glfwGetKey(handle, key);
    if(count == 0)
    {
        currKeyboardState[key] = currState == GLFW_PRESS ? Key::Pressed : Key::None;
        return currKeyboardState[key];
    }
    const Key prevState = currKeyboardState.at(key);
    bool pressed = (prevState == Key::Pressed || prevState == Key::Held);
    switch(currState)
    {
        case GLFW_PRESS: currKeyboardState[key] = pressed ? Key::Held : Key::Pressed; break;
        case GLFW_RELEASE: currKeyboardState[key] = pressed ? Key::Released : Key::None; break;
    }
    return currKeyboardState[key];
}

inline Key Window::GetMouseButton(int button)
{
    const int count = currMouseState.count(button);
    const int currState = glfwGetMouseButton(handle, button);
    if(count == 0) 
    {
        currMouseState[button] = currState == GLFW_PRESS ? Key::Pressed : Key::None;
        return currMouseState[button];
    }
    const Key prevState = currMouseState.at(button);
    bool pressed = (prevState == Key::Pressed || prevState == Key::Held);
    switch(currState)
    {
        case GLFW_PRESS: currMouseState[button] = pressed ? Key::Held : Key::Pressed; break;
        case GLFW_RELEASE: currMouseState[button] = pressed ? Key::Released : Key::None; break;
    }
    return currMouseState[button];
}

inline void Window::Clear(const Color& color)
{
    int code = GL_COLOR_BUFFER_BIT;
    if(depthEnabled) code |= GL_DEPTH_BUFFER_BIT;
    const vec4f vec = color.vec4<float>();
    glClearColor(vec.r, vec.g, vec.b, vec.a);
    glClear(code);
    drawTargets[currentDrawTarget].buffer.Clear(0x00000000);
}

inline void Window::EnableDepth(bool depth)
{
    if(depth)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
    depthEnabled = depth;
}

inline void Window::Begin()
{
    timer.Update();
    for(auto& cam : cameras) cam.Update(this);
    shaders[currentShader].Update();
}

inline void Window::End()
{
    SetShader(0);
    vao.Bind();
    for(auto& drawTarget : drawTargets)
    {
        UpdateTexture(
            drawTarget.id,
            drawTarget.buffer.width,
            drawTarget.buffer.height,
            drawTarget.buffer.data.data()
        );
        BindTexture(drawTarget.id);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    vao.Unbind();
    BindTexture(0);
    glfwSwapBuffers(handle);
    glfwPollEvents();
}

inline void Window::CreateLayer(int32_t width, int32_t height)
{
    drawTargets.emplace_back(width, height);
}

inline void Window::SetCurrentLayer(const std::size_t& index)
{
    currentDrawTarget = index;
}

inline Layer& Window::GetLayer(const std::size_t& index)
{
    return drawTargets[index];
}

inline Shader& Window::GetShader(const std::size_t& index)
{
    return shaders[index];
}

inline int32_t Window::GetWidth()
{
    return drawTargets[currentDrawTarget].buffer.width;
}

inline int32_t Window::GetHeight()
{
    return drawTargets[currentDrawTarget].buffer.height;
}

inline Color Window::GetPixel(int32_t x, int32_t y)
{
    return drawTargets[currentDrawTarget].buffer.GetPixel(x, y);
}

inline void Window::SetDrawMode(DrawMode drawMode)
{
    drawTargets[currentDrawTarget].buffer.drawMode = drawMode;
}

inline DrawMode Window::GetDrawMode()
{
    return drawTargets[currentDrawTarget].buffer.drawMode;
}

inline vec2d Window::GetMousePos()
{
    vec2d res;
    glfwGetCursorPos(handle, &res.x, &res.y);
    return res;
}

inline vec2f Window::GetScrSize()
{
    return drawTargets[currentDrawTarget].buffer.GetSize();
}

inline Rect Window::GetViewport()
{
    return drawTargets[currentDrawTarget].buffer.GetViewport();
}

inline void Window::SetPixel(int32_t x, int32_t y, Color color)
{
    if(pixelMode == PixelMode::Mask && color.a == 0) return;
    const bool camEnabled = drawTargets[currentDrawTarget].camEnabled;
    x -= camEnabled ? drawTargets[currentDrawTarget].offset.x : 0;
    y -= camEnabled ? drawTargets[currentDrawTarget].offset.y : 0;
    drawTargets[currentDrawTarget].buffer.SetPixel(x, y, color);
}

inline bool Window::ClipLine(int32_t& sx, int32_t& sy, int32_t& ex, int32_t& ey)
{
    static constexpr int regInside = 0, regLeft = 1, regRight = 2, regBottom = 4, regTop = 8;
    const int32_t w = GetWidth();
    const int32_t h = GetHeight();
    auto regCode = [&](int32_t x, int32_t y) -> int
    {
        int res = regInside;
        if(x < 0) res |= regLeft; else if(x > w) res |= regRight;
        if(y < 0) res |= regBottom; else if(y > h) res |= regTop;
        return res;
    };
    int sc = regCode(sx, sy);
    int ec = regCode(ex, ey);
    while(true)
    {
        if(!(sc | ec)) return true;
        else if(ec & sc) return false;
        else
        {
            int code = sc ? sc : ec;
            int x = 0, y = 0;
            if (code & regTop) {x = sx + (ex - sx) * (h - sy) / (ey - sy); y = h;}
            else if (code & regBottom) {x = sx + (sx - ex) * (sy) / (ey - sy); y = 0;}
            else if (code & regRight) {y = sy + (ey - sy) * (w - sx) / (ex - sx); x = w;}
            else if (code & regLeft) {y = sy + (sy - ey) * (sx) / (ex - sx); x = 0;}
            if(code == sc) {sx = x; sy = y; sc = regCode(sx, sy);}
            else {ex = x; ey = y; ec = regCode(ex, ey);}
        }
    }
    return true;
}

void Window::DrawLine(int32_t sx, int32_t sy, int32_t ex, int32_t ey, Color color)
{
    if(GetDrawMode() != DrawMode::Periodic && !ClipLine(sx, sy, ex, ey)) return;
    int32_t dx = ex - sx;
    int32_t dy = ey - sy;
    int32_t absdx = std::abs(dx);
    int32_t absdy = std::abs(dy);
    int32_t x = sx;
    int32_t y = sy;
    if(absdx > absdy) 
    {
        int32_t d = absdy * 2 - absdx;
        for(int32_t i = 0; i < absdx; i++) 
        {
            x = dx < 0 ? x - 1: x + 1;
            if(d < 0)
                d = d + 2 * absdy;
            else 
            {
                y = dy < 0 ? y - 1 : y + 1;
                d = d + 2 * (absdy - absdx); 
            }
            SetPixel(x, y, color);
        }
    } 
    else 
    {
        int32_t d = 2 * absdx - absdy;
        for(int32_t i = 0; i < absdy ; i++)
        {
            y = dy < 0 ? y - 1 : y + 1;
            if(d < 0)
                d = d + 2 * absdx;
            else
            {
                x = dx < 0 ? x - 1 : x + 1;
                d = d + 2 * (absdx - absdy);
            }
            SetPixel(x, y, color);
        }
    }
}

void Window::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, Color color)
{
    w = std::clamp(w, 0, GetWidth());
    h = std::clamp(h, 0, GetHeight());
    for(int32_t i = x; i < x + w; i++)
        for(int32_t j = y; j < y + h; j++)
            SetPixel(i, j, color);
}

void Window::DrawRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, Color color)
{
    DrawLine(x, y, x, y + h, color);
    DrawLine(x, y, x + w, y, color);
    DrawLine(x + w, y + h, x, y + h, color);
    DrawLine(x + w, y + h, x + w, y, color);
}

void Window::DrawRotatedRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, float rotation, Color color)
{
    if(rotation == 0.0f)
    {
        DrawRectOutline(x, y, w, h, color);
        return;
    }
    const vec2f pos1 = rotate<float>(rotation, {0.0f, (float)h});
    const vec2f pos2 = rotate<float>(rotation, {(float)w, 0.0f});
    const vec2f pos3 = rotate<float>(rotation, {(float)w, (float)h});
    DrawLine(x + pos3.x, y + pos3.y, x + pos2.x, y + pos2.y, color);
    DrawLine(x + pos3.x, y + pos3.y, x + pos1.x, y + pos1.y, color);
    DrawLine(x, y, x + pos2.x, y + pos2.y, color);
    DrawLine(x + pos1.x, y + pos1.y, x, y, color);
}

void Window::DrawCircle(int32_t cx, int32_t cy, int32_t radius, Color color)
{
    const int32_t w = GetWidth();
    const int32_t h = GetHeight();
    if(cx + radius > w && cx - radius < 0 && cy + radius > h && cy - radius < 0) 
    {
        DrawRect(0, 0, w, h, color);
        return;
    }
    auto drawLine = [&](int32_t sx, int32_t ex, int32_t y)
    {
    	for (int32_t x = sx; x < ex; x++)
    		SetPixel(x, y, color);
    };
    int32_t x = radius;
    int32_t y = 0;
    int32_t dx = 1 - radius * 2;
    int32_t dy = 0;
    int32_t err = 0;
    while (x >= y)
    {
        
        drawLine(cx - x, cx + x, cy + y);
        drawLine(cx - x, cx + x, cy - y);
        drawLine(cx - y, cx + y, cy + x);
        drawLine(cx - y, cx + y, cy - x);
        y++;
        err += dy;
        dy += 2;
        if (err * 2 + dx > 0)
        {
            x--;
            err += dx;
            dx += 2;
        }
    }
}

void Window::DrawCircleOutline(int32_t cx, int32_t cy, int32_t radius, Color color)
{
    if(GetDrawMode() == DrawMode::Normal && (radius < 0 || cx - radius > GetWidth() || cx + radius < 0 || cy - radius > GetHeight() || cy + radius < 0)) return;
    auto drawPixels = [&](int32_t x, int32_t y)
    {
        SetPixel(cx + x, cy + y, color); 
        SetPixel(cx - x, cy + y, color); 
        SetPixel(cx + x, cy - y, color); 
        SetPixel(cx - x, cy - y, color); 
        SetPixel(cx + y, cy + x, color); 
        SetPixel(cx - y, cy + x, color); 
        SetPixel(cx + y, cy - x, color); 
        SetPixel(cx - y, cy - x, color); 
    };
    int32_t x = 0;
    int32_t y = radius;
    int32_t d1 = 1 - radius;
    int32_t c1 = 3;
    int32_t c2 = 5 - 2 * radius;
    drawPixels(x, y);
    while(x < y)
    {
        if(d1 < 0)
        {
            d1 += c1;
            c2 += 2;
        }
        else
        {
            d1 += c2;
            c2 += 4;
            y--;
        }
        c1 += 2;
        x++;
        drawPixels(x, y);
    }
}

void Window::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, Color color)
{
    auto drawLine = [&](int32_t sx, int32_t ex, int32_t y)
    {
        if(sx > ex) std::swap(sx, ex); 
        for(int32_t x = sx; x < ex; x++)
            SetPixel(x, y, color);
    };
    if(y2 < y1) 
    {
        std::swap(y1, y2); 
        std::swap(x1, x2);
    }
    if(y3 < y1) 
    {   
        std::swap(y1, y3); 
        std::swap(x1, x3);
    }
    if(y3 < y2) 
    {
        std::swap(y3, y2); 
        std::swap(x3, x2);
    }
    float dx0 = (x3 - x1) / (y3 - y1 + 1.0f);
    float dx1 = (x2 - x1) / (y2 - y1 + 1.0f);
    float dx2 = (x3 - x2) / (y3 - y2 + 1.0f);
    float sx = x1;
    float ex = x1 + dx1;
    for(int32_t y = y1; y <= y3; y++)
    {
        drawLine((int32_t)sx, (int32_t)ex, y);
        sx += dx0;
        ex += (y < y2) ? dx1 : dx2;
    }
}

void Window::DrawTexturedTriangle(Sprite& sprite, Vertex v1, Vertex v2, Vertex v3)
{
    const int32_t w = sprite.width;
    const int32_t h = sprite.height;
#if defined VERTEX_COLOR
    auto drawLine = [&](int32_t sx, int32_t ex, int32_t y, float su, float eu, float sv, float ev, Color sc, Color ec)
#else
    auto drawLine = [&](int32_t sx, int32_t ex, int32_t y, float su, float eu, float sv, float ev)
#endif
    {
        if(ex < sx)
        {
            std::swap(sx, ex);
            std::swap(su, eu);
            std::swap(sv, ev);
        }
        float dx = 1.0f / (ex - sx), curr = 0.0f;
        for(int32_t x = sx; x < ex; x++)
        {
            float u = (su + curr * (eu - su)) * w;
            float v = (sv + curr * (ev - sv)) * h;
#if defined VERTEX_COLOR
            Color color = sc.Lerp(ec, curr);
            SetPixel(x, y, sprite.GetPixel(u, v).Lerp(color, 0.5f));
#else
            SetPixel(x, y, sprite.GetPixel(u, v));
#endif
            curr += dx;
        }
    };
    if(v2.pos.y < v1.pos.y) std::swap(v1, v2);
    if(v3.pos.y < v1.pos.y) std::swap(v1, v3);
    if(v3.pos.y < v2.pos.y) std::swap(v2, v3);
    float dx1 = (v3.pos.x - v1.pos.x) / (v3.pos.y - v1.pos.y + 1.0f);
    float dx2 = (v3.pos.x - v2.pos.x) / (v3.pos.y - v2.pos.y + 1.0f);
    float dx3 = (v2.pos.x - v1.pos.x) / (v2.pos.y - v1.pos.y + 1.0f);
    float du1 = (v3.tex.x - v1.tex.x) / (v3.pos.y - v1.pos.y + 1.0f);
    float du2 = (v3.tex.x - v2.tex.x) / (v3.pos.y - v2.pos.y + 1.0f);
    float du3 = (v2.tex.x - v1.tex.x) / (v2.pos.y - v1.pos.y + 1.0f);
    float dv1 = (v3.tex.y - v1.tex.y) / (v3.pos.y - v1.pos.y + 1.0f);
    float dv2 = (v3.tex.y - v2.tex.y) / (v3.pos.y - v2.pos.y + 1.0f);
    float dv3 = (v2.tex.y - v1.tex.y) / (v2.pos.y - v1.pos.y + 1.0f);
    float sx = v1.pos.x, ex = v1.pos.x + dx3;
    float su = v1.tex.x, eu = v1.tex.x + du3;
    float sv = v1.tex.y, ev = v1.tex.y + dv3;
#if defined VERTEX_COLOR
    float dy = 1.0f / (v3.pos.y - v1.pos.y);
    float curr = 0.0f;
#endif
    for(int32_t y = v1.pos.y; y <= v3.pos.y; y++)
    {
#if defined VERTEX_COLOR
        curr += dy;
        Color sc = v1.color.Lerp(v3.color, curr);
        Color ec = v2.color.Lerp(y < v2.pos.y ? v3.color : v1.color, curr);
        drawLine(sx, ex, y, su, eu, sv, ev, sc, ec);
#else
        drawLine(sx, ex, y, su, eu, sv, ev);
#endif
        sx += dx1;
        su += du1;
        sv += dv1;
        ex += y < v2.pos.y ? dx3 : dx2;
        eu += y < v2.pos.y ? du3 : du2;
        ev += y < v2.pos.y ? dv3 : dv2;
    }
}

void Window::DrawTriangleOutline(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, Color color)
{
    DrawLine(x1, y1, x2, y2, color);
    DrawLine(x1, y1, x3, y3, color);
    DrawLine(x2, y2, x3, y3, color);
}

void Window::DrawSprite(Sprite& sprite, Transform& transform, Horizontal hor, Vertical ver)
{
    const float w = (float)sprite.width;
    const float h = (float)sprite.height;
    vec2f start, end, p;
    p = start = transform.Forward(0.0f, 0.0f);
    start = min(p, start); end = max(p, end);
    p = transform.Forward(w, h);
    start = min(p, start); end = max(p, end);
    p = transform.Forward(0.0f, h);
    start = min(p, start); end = max(p, end);
    p = transform.Forward(w, 0.0f);
    start = min(p, start); end = max(p, end);
    transform.Invert();
    if (end.x < start.x) std::swap(end.x, start.x);
    if (end.y < start.y) std::swap(end.y, start.y);
    for (float i = start.x; i < end.x; ++i)
        for (float j = start.y; j < end.y; ++j)
        {
            const vec2f o = transform.Backward(i, j);
            const int32_t u = hor == Horizontal::Flip ? w - std::ceil(o.x) : std::floor(o.x);
            const int32_t v = ver == Vertical::Flip ? h - std::ceil(o.y) : std::floor(o.y);
            SetPixel(i, j, sprite.GetPixel(u, v));
        }
}

void Window::DrawSprite(int32_t x, int32_t y, Sprite& sprite, vec2f size, Horizontal hor, Vertical ver)
{
    Rect dst;
    dst.sx = x - sprite.width * size.w * 0.5f;
    dst.sy = y - sprite.height * size.h * 0.5f;
    dst.ex = x + sprite.width * size.w * 0.5f;
    dst.ey = y + sprite.height * size.h * 0.5f;
    DrawSprite(dst, sprite, hor, ver);
}

void Window::DrawSprite(int32_t x, int32_t y, Rect src, Sprite& sprite, vec2f size, Horizontal hor, Vertical ver)
{
    if(src.ex == src.sx || src.ey == src.sy) return;
    if(src.ex < src.sx) std::swap(src.ex, src.sx);
    if(src.ey < src.sy) std::swap(src.ey, src.sy);
    Rect dst;
    dst.sx = x - (src.ex - src.sx) * 0.5f * size.w;
    dst.sy = y - (src.ey - src.sy) * 0.5f * size.h;
    dst.ex = x + (src.ex - src.sx) * 0.5f * size.w;
    dst.ey = y + (src.ey - src.sy) * 0.5f * size.h;
    DrawSprite(dst, src, sprite, hor, ver);
}

void Window::DrawSprite(Rect dst, Sprite& sprite, Horizontal hor, Vertical ver)
{
    if(dst.ex == dst.sx || dst.ey == dst.sy) return;
    if(dst.ex < dst.sx) std::swap(dst.sx, dst.ex);
    if(dst.ey < dst.sy) std::swap(dst.sy, dst.ey);
    const float scx = (dst.ex - dst.sx) / sprite.width;
    const float scy = (dst.ey - dst.sy) / sprite.height;
    float px = hor == Horizontal::Flip ? -1.0f : 1.0f;
    float dx = hor == Horizontal::Flip ? dst.ex : dst.sx;
    float py = ver == Vertical::Flip ? -1.0f : 1.0f;
    float dy = ver == Vertical::Flip ? dst.ey : dst.sy;
    for(float x = 0; x < dst.ex - dst.sx; x++)
        for(float y = 0; y < dst.ey - dst.sy; y++)
        {
            int32_t ox = std::floor(x / scx);
            int32_t oy = std::floor(y / scy);
            SetPixel((int32_t)(dx + x * px), (int32_t)(dy + y * py), sprite.GetPixel(ox, oy));
        }
}

void Window::DrawSprite(Rect dst, Rect src, Sprite& sprite, Horizontal hor, Vertical ver)
{
    if(dst.ex == dst.sx || dst.ey == dst.sy || src.ex == src.sx || src.ey == src.sy) return;
    if(dst.ex < dst.sx) std::swap(dst.sx, dst.ex);
    if(dst.ey < dst.sy) std::swap(dst.sy, dst.ey);
    if(src.ex < src.sx) std::swap(src.sx, src.ex);
    if(src.ey < src.sy) std::swap(src.sy, src.ey);
    const float scx = (dst.ex - dst.sx) / (src.ex - src.sx);
    const float scy = (dst.ey - dst.sy) / (src.ey - src.sy);
    float px = hor == Horizontal::Flip ? -1.0f : 1.0f;
    float dx = hor == Horizontal::Flip ? dst.ex : dst.sx;
    float py = ver == Vertical::Flip ? -1.0f : 1.0f;
    float dy = ver == Vertical::Flip ? dst.ey : dst.sy;
    for(float x = 0; x < dst.ex - dst.sx; x++)
        for(float y = 0; y < dst.ey - dst.sy; y++)
        {
            int32_t ox = std::floor(x / scx);
            int32_t oy = std::floor(y / scy);
            SetPixel((int32_t)(dx + x * px), (int32_t)(dy + y * py), sprite.GetPixel(src.sx + ox, src.sy + oy));
        }
}

void Window::DrawCharacter(int32_t x, int32_t y, const char c, vec2f size, Color color)
{
    Rect dst;
    dst.sx = (float)x;
    dst.sy = (float)y;
    dst.ex = dst.sx + CharSize(c, size.w);
    dst.ey = dst.sy + defFontHeight * size.h;
    DrawCharacter(dst, c, color);
}

void Window::DrawText(int32_t x, int32_t y, const std::string& text, vec2f size, Color color, float textOffset)
{
    Rect dst;
    const std::size_t index = text.find_first_of('\n');
    auto CalcStringPos = [&](const std::string& str)
    {
        const vec2f stringSize = StringSize(str, size);
        dst.sx = (float)x - stringSize.w * textOffset;
        dst.sy = (float)y;
        dst.ex = dst.sx + stringSize.w;
        dst.ey = dst.sy + stringSize.h;
    };    
    if(index == std::string::npos)
    {
        CalcStringPos(text);
        DrawText(dst, text, color);
        return;
    }
    CalcStringPos(text.substr(0, index));
    DrawText(dst, text.substr(0, index), color);
    DrawText(x, y + (defFontHeight + 1.0f) * size.h, text.substr(index+1, text.size() - index), size, color, textOffset);
    return;
}

void Window::DrawCharacter(Rect dst, const char c, Color color)
{
    if(dst.ex == dst.sx || dst.sy == dst.ey) return;
    if(dst.ex < dst.sx) std::swap(dst.ex, dst.sx);
    if(dst.ey < dst.sy) std::swap(dst.ey, dst.sy);
    const float scx = (dst.ex - dst.sx) / defFontWidth;
    const float scy = (dst.ey - dst.sy) / defFontHeight;
    for(float x = 0; x < dst.ex - dst.sx; x++)
        for(float y = 0; y < dst.ey - dst.sy; y++)
        {
            int32_t ox = std::floor(x / scx);
            int32_t oy = std::floor(y / scy);
            if(defFontData[(int)c - 32][oy] & (1 << ox))
                SetPixel((int32_t)(dst.sx + (defFontWidth * scx - x)), (int32_t)(dst.sy + (defFontHeight * scy - y)), color);
        }
}

void Window::DrawRotatedCharacter(int32_t x, int32_t y, const char c, float rotation, vec2f size, Color color)
{
    if(rotation == 0.0f)
    {
        DrawCharacter(x, y, c, size, color);
        return;
    }
    float ex = 0.0f, ey = 0.0f;
    float sx = 0.0f, sy = 0.0f;
    float px = 0.0f, py = 0.0f;
    auto CalcForward = [&](float cx, float cy)
    {
        px = cx * std::cos(rotation) * size.w - cy * std::sin(rotation) * size.h;
        py = cx * std::sin(rotation) * size.w + cy * std::cos(rotation) * size.h;
        sx = std::min(sx, px); sy = std::min(sy, py);
        ex = std::max(ex, px); ey = std::max(ey, py);
    };
    CalcForward(0.0f, 0.0f);
    CalcForward(defFontWidth, defFontHeight);
    CalcForward(0.0f, defFontHeight);
    CalcForward(defFontWidth, 0.0f);
    if (ex < sx) std::swap(ex, sx);
    if (ey < sy) std::swap(ey, sy);
    for (float i = sx; i < ex; ++i)
        for (float j = sy; j < ey; ++j)
        {
            float ox = defFontWidth - i * std::cos(rotation) / size.w - j * std::sin(rotation) / size.h;
            float oy = defFontHeight - j * std::cos(rotation) / size.h + i * std::sin(rotation) / size.w;
            bool canDraw = oy >= 0.0f && oy < (float)defFontHeight && ox >= 0.0f && ox < (float)defFontWidth;
            if(canDraw && defFontData[(int)c - 32][(int)oy] & (1 << (int)ox))
                SetPixel(x + i, y + j, color);
        }
}

void Window::DrawRotatedText(int32_t x, int32_t y, const std::string& text, float rotation, vec2f size, Color color, float textOffset)
{
    if(rotation == 0.0f)
    {
        DrawText(x, y, text, size, color, textOffset);
        return;
    }
    const std::size_t index = text.find_first_of('\n');
    const vec2f rot = {std::cos(rotation), std::sin(rotation)};
    vec2f pos = {(float)x, (float)y};
    if(index == std::string::npos)
    {
        pos -= rot * textOffset * StringSize(text, size).w;
        for(const char c : text)
        {
            DrawRotatedCharacter(pos.x, pos.y, c, rotation, size, color);
            pos += CharSize(c, size.w) * rot;
        }
        return;
    }
    const float hypot = (defFontHeight + 1.0f) * size.h;
    DrawRotatedText(x, y, text.substr(0, index), rotation, size, color, textOffset);
    DrawRotatedText(x - hypot * rot.y, y + hypot * rot.x, text.substr(index + 1, text.size() - index), rotation, size, color, textOffset);
}

void Window::DrawText(Rect dst, const std::string& text, Color color)
{
    if(dst.ex == dst.sx || dst.sy == dst.ey || text.empty()) return;
    if(dst.ex < dst.sx) std::swap(dst.ex, dst.sx);
    if(dst.ey < dst.sy) std::swap(dst.ey, dst.sy);
    const vec2f stringSize = StringSize(text, 1.0f);
    const float scx = (dst.ex - dst.sx) / stringSize.w;
    const float scy = (dst.ey - dst.sy) / stringSize.h;
    float sx = dst.sx, sy = dst.sy;
    for(const char c : text)
    {
        DrawCharacter({sx, sy, sx + scx * defFontWidth, sy + scy * defFontHeight}, c, color);
        if(c == '\n')
        {
            sy += (defFontHeight + 1.0f) * scy;
            sx = dst.sx;
        }
        else
            sx += CharSize(c, scx);
    }
}

void Window::Draw3D(Renderable3D& renderable)
{
    SetShader(3);
    Shader& shader = GetShader(3);
    renderable.vao.Bind();
    shader.SetUniformMat("model", renderable.transform.GetModelMat());
    shader.SetUniformVec("material", renderable.material);
    shader.SetUniformInt("texture_data", &defTextureSlot);
    shader.SetUniformBool("has_texture", renderable.texture);
    BindTexture(renderable.texture, defTextureSlot);
    if(renderable.drawFunc != nullptr) renderable.drawFunc();
    renderable.vao.Unbind();
}

SpriteSheet::SpriteSheet(const std::string& path, const vec2i& cellSize) : cellSize(cellSize)
{
    sprite = Sprite(path);
}

Rect SpriteSheet::GetCell(const vec2i& cell)
{
    Rect res;
    res.sx = cell.x * cellSize.w;
    res.ex = res.sx + cellSize.w;
    res.sy = cell.y * cellSize.h;
    res.ey = res.sy + cellSize.h;
    return res;
}

void SpriteSheet::Draw
(
    Window& window, 
    const vec2i& pos, 
    const vec2f& size, 
    const vec2i& cell, 
    Horizontal hor, 
    Vertical ver
)
{
    window.DrawSprite(pos.x, pos.y, GetCell(cell), sprite, size, hor, ver);
}

Button::Button(Window* window, const std::string& path, int button) : window(window), button(button)
{
    image = Sprite(path);
}

bool Button::Clicked()
{
    return window->GetMouseButton(button) == Key::Pressed && Hover();
}

bool Button::Hover()
{
    assert(window);
    const int32_t w = image.width * size.w;
    const int32_t h = image.height * size.h;
    const int32_t x = window->GetMousePos().x;
    const int32_t y = window->GetMousePos().y;
    return (x < position.x + w * 0.5f && x > position.x - w * 0.5f && y < position.y + h * 0.5f && y > position.y - h * 0.5f);
}

void Button::Draw()
{
    assert(window);
    window->pixelMode = PixelMode::Mask;
    window->DrawSprite(position.x, position.y, image, size);
    window->pixelMode = PixelMode::Normal;
}

#endif