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
constexpr vec2f defFontSize = {defFontWidth, defFontHeight};

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

inline vec2f StringSize(const std::string& text, const vec2f& size)
{
    vec2f res = {0.0f, defFontHeight};
    float buffer = 0.0f;
    for(const char c : text)
    {
        if(c == '\n')
        {
            res.w = std::max(res.w, buffer);
            res.h += defFontHeight + 1.0f;
            buffer = 0.0f;
        }
        else
            buffer += CharSize(c, size.w);
    }
    return {std::max(res.w, buffer), res.h * size.h};
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

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
struct Rect
{
    Vector<T, 2> pos;
    Vector<T, 2> size;
    inline constexpr Rect() : pos(T(0)), size(T(0)) {}
    inline constexpr Rect(const Vector<T, 2>& pos, const Vector<T, 2>& size) : pos(pos), size(size) {}
    inline constexpr Rect& operator=(const Rect& lhs) = default;
    inline constexpr Rect(const Rect& lhs) = default;
    inline constexpr Rect(Rect&& lhs) = default;
    template <typename U>
    inline friend constexpr auto operator*=(Rect<T>& lhs, const U& rhs)
    {
        lhs = lhs * rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator+=(Rect<T>& lhs, const U& rhs)
    {
        lhs = lhs + rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator-=(Rect<T>& lhs, const U& rhs)
    {
        lhs = lhs - rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator*=(Rect<T>& lhs, const Vector<U, 2>& rhs)
    {
        lhs = lhs * rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator+=(Rect<T>& lhs, const Vector<U, 2>& rhs)
    {
        lhs = lhs + rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator-=(Rect<T>& lhs, const Vector<U, 2>& rhs)
    {
        lhs = lhs - rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr bool operator==(const Rect<T>& lhs, const Rect<U>& rhs)
    {
        return lhs.pos == rhs.pos && lhs.size == rhs.size;
    }
    template <typename U>
    inline friend constexpr bool operator!=(const Rect<T>& lhs, const Rect<U>& rhs)
    {
        return !(lhs == rhs);
    }
    template <typename U>
    inline friend constexpr auto operator+(const Rect<T>& lhs, const U& rhs)
    {
        return lhs + Vector<U, 2>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator-(const Rect<T>& lhs, const U& rhs)
    {
        return lhs - Vector<U, 2>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator*(const Rect<T>& lhs, const U& rhs)
    {
        return lhs * Vector<U, 2>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator+(const Rect<T>& lhs, const Vector<U, 2>& rhs)
    {
        return Rect<decltype(lhs.pos.x + rhs.x)>{lhs.pos + rhs, lhs.size};
    }
    template <typename U>
    inline friend constexpr auto operator-(const Rect<T>& lhs, const Vector<U, 2>& rhs)
    {
        return Rect<decltype(lhs.pos.x - rhs.x)>{lhs.pos - rhs, lhs.size};
    }
    template <typename U>
    inline friend constexpr auto operator*(const Rect<T>& lhs, const Vector<U, 2>& rhs)
    {
        return Rect<decltype(lhs.pos.x * rhs.x)>{lhs.pos, lhs.size * rhs};
    }
    template <typename F> 
    inline constexpr operator Rect<F>()
    {
        return
        {
            static_cast<Vector<F, 2>>(pos),
            static_cast<Vector<F, 2>>(size)
        };
    }
    template <typename U>
    inline constexpr void Scale(const Vector<U, 2>& scale)
    {
        operator*=(*this, scale);
    }
    template <typename U>
    inline constexpr void Translate(const Vector<U, 2>& vec)
    {
        operator+=(*this, vec);
    }
    template <typename U>
    inline constexpr bool Contains(const Vector<U, 2>& lhs) const
    {
        return Contains(lhs.x, lhs.y);
    }
    template <typename U>
    inline constexpr bool Contains(const U& x, const U& y) const
    {
        return x >= pos.x && x <= pos.x + size.x && y <= pos.y + size.y && y >= pos.y;
    }
    template <typename U>
    inline constexpr bool Contains(const Rect<U>& lhs) const
    {
        return pos.x <= lhs.pos.x && pos.x + size.x >= lhs.pos.x + lhs.size.x && pos.y <= lhs.pos.y && pos.y + size.y >= lhs.pos.y + lhs.size.y;
    }
    template <typename U>
    inline constexpr bool Overlaps(const Rect<U>& lhs) const
    {
        return pos.x <= lhs.pos.x + lhs.size.x && lhs.pos.x <= pos.x + size.w && pos.y <= lhs.pos.y + lhs.size.y && lhs.pos.y <= pos.y + size.y;
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

template <typename T> 
inline Vector<T, 2> RndPoint(const Rect<T>& area)
{
    return area.pos + rand({0.0f}, area.size);
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
    inline void SetPixel(int32_t x, int32_t y, const Color& color);
    inline Color GetPixel(int32_t x, int32_t y);
    inline void Clear(const Color& color);
    inline void Resize(int32_t w, int32_t h);
    inline void Scale(float sx, float sy);
    inline void Tint(const Color& color);
    inline const Sprite GetSrc(const Rect<int32_t>& src);
    inline Rect<float> GetViewport();
    inline const vec2f GetSize() const;
    inline const float GetAspectRatio() const;
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

struct Window;

struct PerspCamera
{
    vec3f pos, up, forward, right, orientation;
    mat4x4f proj, view;
    vec2f prevMousePos, currMousePos;
    float sensitivity = 10.0f;
    float velocity = 2.5f;
    float fov = 60.0f;
    std::function<void(PerspCamera&, Window*)> updateFunc = nullptr;
    inline PerspCamera() = default;
    inline PerspCamera(Window* window);
    inline void Reset();
    inline void Update(Window* window);
    inline void UpdateInternal();
    inline const mat4x4f GetProjView() const;
};

struct OrthoCamera
{
    vec3f pos;
    mat4x4f proj, view;
    std::function<void(OrthoCamera&, Window*)> updateFunc = nullptr;
    inline OrthoCamera() = default;
    inline OrthoCamera(Window* window);
    inline void Reset();
    inline void Update(Window* window);
    inline void UpdateInternal();
    inline const mat4x4f GetProjView() const;
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
    Transform3D<float> transform;
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
    inline const vec2f GetSize() const;
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
    inline float GetAspectRatio();
    inline Rect<float> GetViewport();
    inline float GetDeltaTime();
    inline Key GetKey(int key);
    inline Key GetMouseButton(int button);
    inline DrawMode GetDrawMode();
    inline void SetDrawMode(DrawMode drawMode);
    inline Layer& GetLayer(const std::size_t& index);
    inline void SetCurrentLayer(const std::size_t& index);
    inline void CreateLayer(int32_t width = 0, int32_t height = 0);
    inline void SetShader(const std::size_t& index);
    inline Shader& GetShader(const std::size_t& index);
    inline void SetPerspCamera(const std::size_t& index);
    inline void SetOrthoCamera(const std::size_t& index);
    inline PerspCamera& GetCurrentPerspCamera();
    inline OrthoCamera& GetCurrentOrthoCamera();
    inline void SetPixel(int32_t x, int32_t y, const Color& color);
    inline Color GetPixel(int32_t x, int32_t y);
    inline bool ClipLine(int32_t& sx, int32_t& sy, int32_t& ex, int32_t& ey);
    inline void DrawLine(int32_t sx, int32_t sy, int32_t ex, int32_t ey, const Color& color);
    inline void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);
    inline void DrawRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);
    inline void DrawRotatedRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, float rotation, const Color& color);
    inline void DrawCircle(int32_t cx, int32_t cy, int32_t radius, const Color& color);
    inline void DrawCircleOutline(int32_t cx, int32_t cy, int32_t radius, const Color& color);
    inline void DrawTriangle(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color);
    inline void DrawTexturedTriangle(Sprite& sprite, Vertex v0, Vertex v1, Vertex v2);
    inline void DrawTriangleOutline(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color);
    inline void DrawSprite(Sprite& sprite, Transform<float>& transform, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm, const vec2f& origin = 0.5f);
    inline void DrawSprite(Sprite& sprite, Transform<float>& transform, const Rect<float>& src, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm, const vec2f& origin = 0.5f);
    inline void DrawSprite(int32_t x, int32_t y, Sprite& sprite, const vec2f& size = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(int32_t x, int32_t y, const Rect<float>& src, Sprite& sprite, const vec2f& size = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(const Rect<float>& dst, Sprite& sprite, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(const Rect<float>& dst, const Rect<float>& src, Sprite& sprite, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawCharacter(int32_t x, int32_t y, const char c, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255});
    inline void DrawRotatedCharacter(int32_t x, int32_t y, const char c, float rotation, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255});
    inline void DrawCharacter(const Rect<float>& dst, const char c, const Color& color = {0, 0, 0, 255});
    inline void DrawText(const Rect<float>& dst, const std::string& text, const Color& color = {0, 0, 0, 255});
    inline void DrawRotatedText(int32_t x, int32_t y, const std::string& text, float rotation, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2f& origin = 0.0f);
    inline void DrawText(int32_t x, int32_t y, const std::string& text, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2f& origin = 0.0f);
    inline void SetPixel(const vec2i& pos, const Color& color);
    inline Color GetPixel(const vec2i& pos);
    inline bool ClipLine(vec2i& start, vec2i& end);
    inline void DrawLine(const vec2i& start, const vec2i& end, const Color& color);
    inline void DrawRect(const vec2i& pos, const vec2i& size, const Color& color);
    inline void DrawRectOutline(const vec2i& pos, const vec2i& size, const Color& color);
    inline void DrawRotatedRectOutline(const vec2i& pos, const vec2i& size, float rotation, const Color& color);
    inline void DrawCircle(const vec2i& center, int32_t radius, const Color& color);
    inline void DrawCircleOutline(const vec2i& center, int32_t radius, const Color& color);
    inline void DrawTriangle(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color);
    inline void DrawTriangleOutline(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color);
    inline void DrawSprite(const vec2i& pos, Sprite& sprite, const vec2f& size = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawSprite(const vec2i& pos, const Rect<float>& src, Sprite& sprite, const vec2f& size = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    inline void DrawCharacter(const vec2i& pos, const char c, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255});
    inline void DrawRotatedCharacter(const vec2i& pos, const char c, float rotation, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255});
    inline void DrawRotatedText(const vec2i& pos, const std::string& text, float rotation, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2f& origin = 0.0f);
    inline void DrawText(const vec2i& pos, const std::string& text, const vec2f& size = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2f& origin = 0.0f);
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
    std::vector<PerspCamera> vecPerspCameras;
    std::vector<OrthoCamera> vecOrthoCameras;
    std::size_t currentPerspCamera = 0;
    std::size_t currentOrthoCamera = 0;
    Timer timer;
    VAO vao;
    Buffer<default_vertex, GL_ARRAY_BUFFER> vbo;
    virtual ~Window()
    {
        glfwDestroyWindow(handle);
        glfwTerminate();
    }
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

inline void Sprite::SetPixel(int32_t x, int32_t y, const Color& color)
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

inline const Sprite Sprite::GetSrc(const Rect<int32_t>& src)
{
    Sprite res = Sprite(src.size.x, src.size.y);
    for(int32_t i = 0; i < res.width; i++)
        for(int32_t j = 0; j < res.height; j++)
            res.SetPixel(i, j, GetPixel(src.pos.x + i, src.pos.y + j));
    return res;
}

inline const vec2f Sprite::GetSize() const
{
    return {(float)width, (float)height};
}

inline const float Sprite::GetAspectRatio() const
{
    return (float)width / height;
}

inline Rect<float> Sprite::GetViewport()
{
    return {0.0f, this->GetSize()};
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

inline const vec2f Decal::GetSize() const
{
    return {(float)width, (float)height};
}

inline Decal::Decal(const std::string& path)
{
    int channels;
    unsigned char *bytes = stbi_load(path.c_str(), &width, &height, &channels, 4);
    CreateTexture(id, width, height);
    UpdateTexture(id, width, height, bytes);
    stbi_image_free(bytes);
}

inline PerspCamera::PerspCamera(Window* window)
{
    prevMousePos = currMousePos = window->GetMousePos();
    this->Reset();
    proj = make_perspective_mat(window->GetAspectRatio(), fov, 0.1f, 100.0f);
}

inline void PerspCamera::Reset()
{
    orientation = {0.0f, 0.0f, -pi * 0.5f};
    pos = defCameraPos;
    UpdateInternal();
}

inline void PerspCamera::Update(Window* window)
{
    if(updateFunc != nullptr)
    {
        updateFunc(*this, window);
        UpdateInternal();
    }
}

inline void PerspCamera::UpdateInternal()
{
    forward = vec3f
    {
        std::cos(orientation.yaw) * std::cos(orientation.pitch), 
        std::sin(orientation.pitch), 
        std::sin(orientation.yaw) * std::cos(orientation.pitch)
    }.norm();
    right = cross(forward, defWorldUp).norm();
    up = cross(right, forward).norm();
    view = mat_look_at(pos, pos + forward, up);
}

inline const mat4x4f PerspCamera::GetProjView() const
{
    return proj * view;
}

inline OrthoCamera::OrthoCamera(Window* window)
{
    this->Reset();
    proj = make_ortho_mat(1.0f, -1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
}

inline void OrthoCamera::Update(Window* window)
{
    if(updateFunc != nullptr)
    {
        updateFunc(*this, window);
        UpdateInternal();
    }
}

inline void OrthoCamera::Reset()
{
    pos = -defCameraPos;
    UpdateInternal();
}

inline void OrthoCamera::UpdateInternal()
{
    view = translate_mat_3d(pos);
}

inline const mat4x4f OrthoCamera::GetProjView() const
{
    return proj * view;
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
    vecPerspCameras.emplace_back(this);
    vecOrthoCameras.emplace_back(this);
    vecPerspCameras[0].updateFunc = [](PerspCamera& cam, Window* window)
    {
        const float dt = window->timer.deltaTime;
        cam.prevMousePos = cam.currMousePos;
        cam.currMousePos = window->GetMousePos();
        const vec2f offset = (cam.prevMousePos - cam.currMousePos) * cam.sensitivity * dt;
        cam.orientation.yaw -= offset.x;
        cam.orientation.pitch += offset.y;
        cam.orientation.pitch = std::clamp<float>(cam.orientation.pitch, -pi * 0.5f, pi * 0.5f);
        if(window->GetKey(GLFW_KEY_UP) == Key::Held) cam.pos += cam.forward * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_DOWN) == Key::Held) cam.pos -= cam.forward * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_RIGHT) == Key::Held) cam.pos += cam.right * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_LEFT) == Key::Held) cam.pos -= cam.right * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_R) == Key::Pressed) cam.Reset();
    };
    shaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\default_vert.glsl").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\default_frag.glsl").c_str())
        }),
        nullptr,
        [&](Shader& instance)
        {
            instance.SetUniformMat("ortho_mat", GetCurrentOrthoCamera().GetProjView());
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
            instance.SetUniformMat("persp_mat", GetCurrentPerspCamera().GetProjView());
            instance.SetUniformMat("ortho_mat", GetCurrentOrthoCamera().GetProjView());
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
            instance.SetUniformMat("persp_mat", GetCurrentPerspCamera().GetProjView());
            instance.SetUniformMat("ortho_mat", GetCurrentOrthoCamera().GetProjView());
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
            instance.SetUniformMat("camera_mat", GetCurrentPerspCamera().GetProjView());
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

inline float Window::GetAspectRatio()
{
    return drawTargets[currentDrawTarget].buffer.GetAspectRatio();
}

inline void Window::SetShader(const std::size_t& index)
{
    if(currentShader == index || index >= shaders.size()) return;
    shaders[currentShader = index].Set();
    shaders[index].Update();
}

inline void Window::SetPerspCamera(const std::size_t& index)
{
    if(currentPerspCamera != index && index < vecPerspCameras.size())
        currentPerspCamera = index;
}

inline void Window::SetOrthoCamera(const std::size_t& index)
{
    if(currentOrthoCamera != index && index < vecOrthoCameras.size())
        currentOrthoCamera = index;
}

inline PerspCamera& Window::GetCurrentPerspCamera()
{
    return vecPerspCameras[currentPerspCamera];
}

inline OrthoCamera& Window::GetCurrentOrthoCamera()
{
    return vecOrthoCameras[currentOrthoCamera];
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
    for(auto& cam : vecPerspCameras) cam.Update(this);
    for(auto& cam : vecOrthoCameras) cam.Update(this);
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
    if(width == 0 || height == 0) {width = GetWidth(); height = GetHeight();}
    drawTargets.emplace_back(width, height);
}

inline void Window::SetCurrentLayer(const std::size_t& index)
{
    if(currentDrawTarget != index && index < drawTargets.size())
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

inline Rect<float> Window::GetViewport()
{
    return drawTargets[currentDrawTarget].buffer.GetViewport();
}

inline void Window::SetPixel(int32_t x, int32_t y, const Color& color)
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

void Window::DrawLine(int32_t sx, int32_t sy, int32_t ex, int32_t ey, const Color& color)
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

void Window::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color)
{
    w = std::clamp(w, 0, GetWidth());
    h = std::clamp(h, 0, GetHeight());
    for(int32_t i = x; i <= x + w; i++)
        for(int32_t j = y; j <= y + h; j++)
            SetPixel(i, j, color);
}

void Window::DrawRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color)
{
    DrawLine(x, y, x, y + h, color);
    DrawLine(x, y, x + w, y, color);
    DrawLine(x + w, y + h, x, y + h, color);
    DrawLine(x + w, y + h, x + w, y, color);
}

void Window::DrawRotatedRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, float rotation, const Color& color)
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

void Window::DrawCircle(int32_t cx, int32_t cy, int32_t radius, const Color& color)
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
    	for (int32_t x = sx; x <= ex; x++)
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

void Window::DrawCircleOutline(int32_t cx, int32_t cy, int32_t radius, const Color& color)
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

void Window::DrawTriangle(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color)
{
    auto drawLine = [&](int32_t sx, int32_t ex, int32_t y)
    {
        if(sx > ex) std::swap(sx, ex); 
        for(int32_t x = sx; x <= ex; x++)
            SetPixel(x, y, color);
    };
    if(y1 < y0) 
    {
        std::swap(y0, y1); 
        std::swap(x0, x1);
    }
    if(y2 < y0) 
    {   
        std::swap(y0, y2); 
        std::swap(x0, x2);
    }
    if(y2 < y1) 
    {
        std::swap(y2, y1); 
        std::swap(x2, x1);
    }
    float dx0 = (x2 - x0) / (y2 - y0 + 1.0f);
    float dx1 = (x1 - x0) / (y1 - y0 + 1.0f);
    float dx2 = (x2 - x1) / (y2 - y1 + 1.0f);
    float sx = x0;
    float ex = x0 + dx1;
    for(int32_t y = y0; y <= y2; y++)
    {
        drawLine((int32_t)sx, (int32_t)ex, y);
        sx += dx0;
        ex += (y < y1) ? dx1 : dx2;
    }
}

void Window::DrawTexturedTriangle(Sprite& sprite, Vertex v0, Vertex v1, Vertex v2)
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
            const float u = (su + curr * (eu - su)) * w;
            const float v = (sv + curr * (ev - sv)) * h;
#if defined VERTEX_COLOR
            const Color color = sc.Lerp(ec, curr);
            SetPixel(x, y, sprite.GetPixel(u, v).Lerp(color, 0.5f));
#else
            SetPixel(x, y, sprite.GetPixel(u, v));
#endif
            curr += dx;
        }
    };
    if(v1.pos.y < v0.pos.y) std::swap(v0, v1);
    if(v2.pos.y < v0.pos.y) std::swap(v0, v2);
    if(v2.pos.y < v1.pos.y) std::swap(v1, v2);
    float dx0 = (v2.pos.x - v0.pos.x) / (v2.pos.y - v0.pos.y + 1.0f);
    float dx1 = (v2.pos.x - v1.pos.x) / (v2.pos.y - v1.pos.y + 1.0f);
    float dx2 = (v1.pos.x - v0.pos.x) / (v1.pos.y - v0.pos.y + 1.0f);
    float du0 = (v2.tex.x - v0.tex.x) / (v2.pos.y - v0.pos.y + 1.0f);
    float du1 = (v2.tex.x - v1.tex.x) / (v2.pos.y - v1.pos.y + 1.0f);
    float du2 = (v1.tex.x - v0.tex.x) / (v1.pos.y - v0.pos.y + 1.0f);
    float dv0 = (v2.tex.y - v0.tex.y) / (v2.pos.y - v0.pos.y + 1.0f);
    float dv1 = (v2.tex.y - v1.tex.y) / (v2.pos.y - v1.pos.y + 1.0f);
    float dv2 = (v1.tex.y - v0.tex.y) / (v1.pos.y - v0.pos.y + 1.0f);
    float sx = v0.pos.x, ex = v0.pos.x + dx2;
    float su = v0.tex.x, eu = v0.tex.x + du2;
    float sv = v0.tex.y, ev = v0.tex.y + dv2;
#if defined VERTEX_COLOR
    float dy = 1.0f / (v2.pos.y - v0.pos.y);
    float curr = 0.0f;
#endif
    for(int32_t y = v0.pos.y; y <= v2.pos.y; y++)
    {
#if defined VERTEX_COLOR
        curr += dy;
        const Color sc = v0.color.Lerp(v2.color, curr);
        const Color ec = v1.color.Lerp(y < v1.pos.y ? v2.color : v0.color, curr);
        drawLine(sx, ex, y, su, eu, sv, ev, sc, ec);
#else
        drawLine(sx, ex, y, su, eu, sv, ev);
#endif
        sx += dx0;
        su += du0;
        sv += dv0;
        ex += y < v1.pos.y ? dx2 : dx1;
        eu += y < v1.pos.y ? du2 : du1;
        ev += y < v1.pos.y ? dv2 : dv1;
    }
}

void Window::DrawTriangleOutline(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color)
{
    DrawLine(x0, y0, x1, y1, color);
    DrawLine(x0, y0, x2, y2, color);
    DrawLine(x1, y1, x2, y2, color);
}

void Window::DrawSprite(Sprite& sprite, Transform<float>& transform, const Rect<float>& src, Horizontal hor, Vertical ver, const vec2f& origin)
{
    if(src.size.x == 0.0f || src.size.y == 0.0f) return;
    const vec2f norm = src.size * origin;
    const vec2f inv = src.size * (1.0f - origin);
    vec2f start, end, p;
    p = start = transform.Forward(-norm);
    start = min(p, start); end = max(p, end);
    p = transform.Forward(inv);
    start = min(p, start); end = max(p, end);
    p = transform.Forward(-norm.w, inv.h);
    start = min(p, start); end = max(p, end);
    p = transform.Forward(inv.w, -norm.h);
    start = min(p, start); end = max(p, end);
    transform.Invert();
    if (end.x < start.x) std::swap(end.x, start.x);
    if (end.y < start.y) std::swap(end.y, start.y);
    for (float i = start.x; i < end.x; ++i)
        for (float j = start.y; j < end.y; ++j)
        {
            const vec2f o = transform.Backward(i, j);
            const int32_t u = src.pos.x + (hor == Horizontal::Flip ? inv.w - std::ceil(o.x) : norm.w + std::floor(o.x));
            const int32_t v = src.pos.y + (ver == Vertical::Flip ? inv.h - std::ceil(o.y) : norm.h + std::floor(o.y));
            if(src.Contains(u, v)) SetPixel(i, j, sprite.GetPixel(u, v));
        }
}

void Window::DrawSprite(Sprite& sprite, Transform<float>& transform, Horizontal hor, Vertical ver, const vec2f& origin)
{
    DrawSprite(sprite, transform, {0.0f, sprite.GetSize()}, hor, ver, origin);
}

void Window::DrawSprite(int32_t x, int32_t y, Sprite& sprite, const vec2f& size, Horizontal hor, Vertical ver)
{
    const vec2f sprSize = size * sprite.GetSize();
    DrawSprite({vec2f{(float)x, (float)y} - sprSize * 0.5f, sprSize}, sprite, hor, ver);
}

void Window::DrawSprite(int32_t x, int32_t y, const Rect<float>& src, Sprite& sprite, const vec2f& size, Horizontal hor, Vertical ver)
{
    if(src.size.x == 0.0f || src.size.y == 0.0f) return;
    const vec2f sprSize = size * src.size;
    DrawSprite({vec2f{(float)x, (float)y} - sprSize * 0.5f, sprSize}, src, sprite, hor, ver);
}

void Window::DrawSprite(const Rect<float>& dst, Sprite& sprite, Horizontal hor, Vertical ver)
{
    DrawSprite(dst, {0.0f, sprite.GetSize()}, sprite, hor, ver);
}

void Window::DrawSprite(const Rect<float>& dst, const Rect<float>& src, Sprite& sprite, Horizontal hor, Vertical ver)
{
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || src.size.x == 0.0f || src.size.y == 0.0f) return;    
    const vec2f scale = dst.size / src.size;
    const vec2f p = {hor == Horizontal::Flip ? -1.0f : 1.0f, ver == Vertical::Flip ? -1.0f : 1.0f};
    const vec2f d = {dst.pos.x + (hor == Horizontal::Flip ? dst.size.x : 0.0f), dst.pos.y + (ver == Vertical::Flip ? dst.pos.y : 0.0f)};
    for(float x = 0; x < dst.size.x; x++)
        for(float y = 0; y < dst.size.y; y++)
        {
            const vec2f pos = {x, y};
            const vec2f o = floor(pos / scale);
            SetPixel(d + pos * p, sprite.GetPixel(src.pos.x + o.x, src.pos.y + o.y));
        }
}

void Window::DrawCharacter(int32_t x, int32_t y, const char c, const vec2f& size, const Color& color)
{
    DrawCharacter({{(float)x, (float)y}, {CharSize(c, size.w), size.h * defFontHeight}}, c, color);
}

void Window::DrawText(int32_t x, int32_t y, const std::string& text, const vec2f& size, const Color& color, const vec2f& origin)
{
    vec2f pos = {(float)x, (float)y - (defFontHeight + 1.0f) * size.h * origin.y};
    std::size_t index = 0, next = text.find_first_of('\n', index);
    auto drawTextFunc = [&](const std::string& str)
    {
        const vec2f strSize = StringSize(str, size);
        pos.x -= strSize.w * origin.x;
        DrawText({pos, strSize}, str, color);
        pos.x = (float)x;
        pos.y += (defFontHeight + 1.0f) * size.h;
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

void Window::DrawCharacter(const Rect<float>& dst, const char c, const Color& color)
{
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || c == '\n') return;
    const vec2f scale = dst.size / defFontSize;
    for(float x = 0; x < dst.size.x; x++)
        for(float y = 0; y < dst.size.y; y++)
        {
            const vec2f pos = {x, y};
            const vec2i o = floor(pos / scale);
            if(defFontData[(int)c - 32][o.y] & (1 << o.x))
                SetPixel(dst.pos + defFontSize * scale - pos, color);
        }
}

void Window::DrawRotatedCharacter(int32_t x, int32_t y, const char c, float rotation, const vec2f& size, const Color& color)
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
            bool canDraw = oy >= 0.0f && oy < defFontHeight && ox >= 0.0f && ox < defFontWidth;
            if(canDraw && defFontData[(int)c - 32][(int)oy] & (1 << (int)ox))
                SetPixel(x + i, y + j, color);
        }
}

void Window::DrawRotatedText(int32_t x, int32_t y, const std::string& text, float rotation, const vec2f& size, const Color& color, const vec2f& origin)
{
    if(rotation == 0.0f)
    {
        DrawText(x, y, text, size, color, origin);
        return;
    }
    const float newLineOffset = (defFontHeight + 1.0f) * size.h;
    vec2f lineStartPos = {(float)x, (float)y};
    std::size_t index = 0, next = text.find_first_of('\n', index);
    const vec2f rot = {std::cos(rotation), std::sin(rotation)};
    auto drawTextFunc = [&](const std::string& str)
    {
        const vec2f o = StringSize(str, size) * origin;
        vec2f pos = rotate(rotation, lineStartPos, lineStartPos + o) - o;
        for(const char c : str)
        {
            DrawRotatedCharacter(pos, c, rotation, size, color);
            pos += CharSize(c, size.w) * rot;
        }
        lineStartPos += newLineOffset * rot.perp();
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

void Window::DrawText(const Rect<float>& dst, const std::string& text, const Color& color)
{
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || text.empty()) return;
    const vec2f strSize = StringSize(text, 1.0f);
    const vec2f scale = dst.size / strSize;
    vec2f pos = dst.pos;
    for(const char c : text)
    {
        DrawCharacter({pos, scale * defFontSize}, c, color);
        if(c == '\n')
        {
            pos.y += (defFontHeight + 1.0f) * scale.h;
            pos.x = dst.pos.x;
        }
        else
            pos.x += CharSize(c, scale.w);
    }
}

void Window::SetPixel(const vec2i& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

Color Window::GetPixel(const vec2i& pos)
{
    return GetPixel(pos.x, pos.y);
}

bool Window::ClipLine(vec2i& start, vec2i& end)
{
    return ClipLine(start.x, start.y, end.x, end.y);
}

void Window::DrawLine(const vec2i& start, const vec2i& end, const Color& color)
{
    DrawLine(start.x, start.y, end.x, end.y, color);
}

void Window::DrawRect(const vec2i& pos, const vec2i& size, const Color& color)
{
    DrawRect(pos.x, pos.y, size.w, size.h, color);
}

void Window::DrawRectOutline(const vec2i& pos, const vec2i& size, const Color& color)
{
    DrawRectOutline(pos.x, pos.y, size.w, size.h, color);
}

void Window::DrawRotatedRectOutline(const vec2i& pos, const vec2i& size, float rotation, const Color& color)
{
    DrawRotatedRectOutline(pos.x, pos.y, size.w, size.h, rotation, color);
}

void Window::DrawCircle(const vec2i& center, int32_t radius, const Color& color)
{
    DrawCircle(center.x, center.y, radius, color);
}

void Window::DrawCircleOutline(const vec2i& center, int32_t radius, const Color& color)
{
    DrawCircleOutline(center.x, center.y, radius, color);
}

void Window::DrawTriangle(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color)
{
    DrawTriangle(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color);
}

void Window::DrawTriangleOutline(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color)
{
    DrawTriangleOutline(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color);
}

void Window::DrawSprite(const vec2i& pos, Sprite& sprite, const vec2f& size, Horizontal hor, Vertical ver)
{
    DrawSprite(pos.x, pos.y, sprite, size, hor, ver);
}

void Window::DrawSprite(const vec2i& pos, const Rect<float>& src, Sprite& sprite, const vec2f& size, Horizontal hor, Vertical ver)
{
    DrawSprite(pos.x, pos.y, src, sprite, size, hor, ver);
}

void Window::DrawCharacter(const vec2i& pos, const char c, const vec2f& size, const Color& color)
{
    DrawCharacter(pos.x, pos.y, c, size, color);
}

void Window::DrawRotatedCharacter(const vec2i& pos, const char c, float rotation, const vec2f& size, const Color& color)
{
    DrawRotatedCharacter(pos.x, pos.y, c, rotation, size, color);
}

void Window::DrawRotatedText(const vec2i& pos, const std::string& text, float rotation, const vec2f& size, const Color& color, const vec2f& origin)
{
    DrawRotatedText(pos.x, pos.y, text, rotation, size, color, origin);
}

void Window::DrawText(const vec2i& pos, const std::string& text, const vec2f& size, const Color& color, const vec2f& origin)
{
    DrawText(pos.x, pos.y, text, size, color, origin);
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

#endif