#ifndef WINDOW_H
#define WINDOW_H

#include "includes.h"

inline constexpr float defFontWidth = 8;
inline constexpr float defFontHeight = 13;
inline constexpr float defTabSpace = 18;
inline constexpr int maxSprites = 32;
inline constexpr int maxGeoBatchVertices = 256;
inline constexpr int maxGeoBatchIndices = 256;
inline constexpr int numCharacters = 95;
inline constexpr int defTextureSlot = 0;
inline constexpr vec3 defWorldUp = vec3::up();
inline constexpr vec3 defCameraPos = {0.0f, 0.0f, 5.0f};
inline constexpr vec2 defFontSize = {defFontWidth, defFontHeight};

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

inline vec2 StringSize(const std::string& text, const vec2& scale)
{
    vec2 res = {0.0f, defFontHeight};
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
            buffer += CharSize(c, scale.w);
    }
    return {std::max(res.w, buffer), res.h * scale.h};
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
    Alpha
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
        return Rect<decltype(lhs.pos.x * rhs.x)>{lhs.pos * rhs, lhs.size * rhs};
    }
    template <typename F> 
    inline constexpr operator Rect<F>() const
    {
        return
        {
            static_cast<Vector<F, 2>>(pos),
            static_cast<Vector<F, 2>>(size)
        };
    }
    template <typename U>
    inline constexpr auto Scale(const Vector<U, 2>& scale)
    {
        (*this) *= scale;
        return *this;
    }
    template <typename U>
    inline constexpr auto Translate(const Vector<U, 2>& offset)
    {
        pos += offset;
        return *this;
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
        vec4ub v;
        uint32_t color;
        struct { uint8_t r, g, b, a; };
    };
    inline constexpr Color() : r(0), g(0), b(0), a(255) {}
    inline constexpr Color(const uint32_t lhs) : color(reverse_bytes(lhs)) {}
    inline constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
    inline constexpr Color(const vec4ub& lhs) : v(lhs) {}
    inline constexpr Color(const Color& lhs) = default;
    inline constexpr Color& operator=(const Color& lhs) = default;
    inline friend constexpr Color operator/=(Color& lhs, const float rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb / rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, const float rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb * rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator/=(Color& lhs, const vec4& rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb / rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, const vec4& rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb * rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator+=(Color& lhs, const uint8_t rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb + rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator-=(Color& lhs, const uint8_t rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb - rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator+=(Color& lhs, const Color& rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb + rhs.v.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator-=(Color& lhs, const Color& rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb - rhs.v.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, const Color& rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb * rhs.v.rgb / 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator/=(Color& lhs, const Color& rhs)
    {
        lhs.v.rgb = clamp<uint8_t, 3>(lhs.v.rgb / rhs.v.rgb * 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*(const Color& lhs, const float rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb * rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const float rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb / rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, const vec4& rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb * rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const vec4& rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb / rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, const uint8_t rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb + rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, const uint8_t rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb - rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, const Color& rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb - rhs.v.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, const Color& rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb + rhs.v.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, const Color& rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb * rhs.v.rgb / 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const Color& rhs)
    {
        return vec4ub{clamp<uint8_t, 3>(lhs.v.rgb / rhs.v.rgb * 255, 0, 255), lhs.a};
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
        return (lhs.v.rgb < rhs.v.rgb && lhs.a <= rhs.a);
    }
    inline friend constexpr bool operator>(const Color& lhs, const Color& rhs)
    {
        return (lhs.v.rgb > rhs.v.rgb && lhs.a >= rhs.a);
    }
    inline constexpr const uint8_t& operator[](const size_t& index) const
    {
        return v[index];
    }
    inline constexpr uint8_t& operator[](const size_t& index)
    {
        return v[index];
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        os << static_cast<vec4i>(color.v);
        return os;
    }
};

inline constexpr vec4 ColorF(const Color& color)
{
    return static_cast<vec4>(color.v) / 255;
}

inline constexpr Color ColorU(const vec4& color)
{
    return static_cast<vec4ub>(color * 255);
}

inline constexpr Color Lerp(const Color& lhs, const Color& rhs, const double t)
{
    return lerp(lhs.v, rhs.v, t);
}

inline Color RndColor()
{
    return rand<vec4ub>(0, 255);
}

namespace Colors
{
    constexpr Color Red = {255, 0, 0, 255};
    constexpr Color Green = {0, 255, 0, 255};
    constexpr Color Blue = {0, 0, 255, 255};
    constexpr Color White = {255, 255, 255, 255};
    constexpr Color Black = {0, 0, 0, 255};
    constexpr Color Yellow = {255, 255, 0, 255};
    constexpr Color Orange = {255, 165, 0, 255};
    constexpr Color Magenta = {255, 0, 255, 255};
    constexpr Color Aqua = {0, 255, 255, 255};
    constexpr Color Silver = {192, 192, 192, 255};
    constexpr Color Gray = {128, 128, 128, 255};
    constexpr Color Purple = {128, 0, 128, 255};
    constexpr Color Maroon = {128, 0, 0, 255};
    constexpr Color Crimson = {220, 20, 60, 255};
    constexpr Color DarkRed = {139, 0, 0, 255};
    constexpr Color DarkKhaki = {189, 183, 107, 255};
    constexpr Color Khaki = {240, 230, 140, 255};
    constexpr Color DarkGreen = {0, 100, 0, 255};
    constexpr Color LimeGreen = {50, 205, 50, 255};
    constexpr Color SkyBlue = {135, 206, 235, 255};
    constexpr Color MidnightBlue = {25, 25, 112, 255};
    constexpr Color Transparent = {0, 0, 0, 0};
};

template <typename T> 
inline Vector<T, 2> RndPointInRect(const Rect<T>& area)
{
    return rand(area.pos, area.pos + area.size);
}

struct Decal;

struct Sprite
{
    DrawMode drawMode = DrawMode::Normal;
    int32_t width = 0, height = 0;
    std::vector<Color> data;
    inline Sprite() = default;
    Sprite(int32_t w, int32_t h);
    Sprite(const std::string& path);
    Sprite(Decal& decal);
    void SetPixel(int32_t x, int32_t y, const Color& color);
    void SetPixel(const vec2i& pos, const Color& color);
    const Color GetPixel(int32_t x, int32_t y) const;
    const Color GetPixel(const vec2i& pos) const;
    void Clear(const Color& color);
    void Resize(int32_t w, int32_t h);
    void Scale(float sx, float sy);
    void Resize(const vec2i& size);
    void Scale(const vec2& scale);
    void Tint(const Color& color);
    const Rect<int32_t> GetViewport() const;
    const vec2i GetSize() const;
    const float GetAspectRatio() const;
    virtual ~Sprite() {}
};

inline void CreateCubeMap(GLuint& id, const std::array<std::string, 6>& faces)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);
    for (size_t i = 0; i < faces.size(); i++)
    {
        int width, height, channels;
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &channels, 0);
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

inline vec2 ScrToWorldSize(vec2 size, vec2 scrSize)
{
    return {
        size.w * 2.0f / scrSize.w,
        size.h * 2.0f / scrSize.h
    };
}

inline vec2 WorldToScrSize(vec2 size, vec2 scrSize)
{
    return {
        size.w * scrSize.w * 0.5f,
        size.h * scrSize.h * 0.5f
    };
}

inline vec2 ScrToWorldPos(vec2 pos, vec2 scrSize)
{
    return {
        pos.x * 2.0f / scrSize.w - 1.0f,
        -pos.y * 2.0f / scrSize.h + 1.0f
    };
}

inline vec2 WorldToScrPos(vec2 pos, vec2 scrSize)
{
    return {
        (pos.x + 1.0f) * scrSize.w * 0.5f,
        (-pos.y + 1.0f) * scrSize.h * 0.5f
    };
}

struct Window;

struct Framebuffer
{
    GLuint id, rbo;
    std::vector<GLuint> renderTargets;
    int32_t width = 0, height = 0;
    inline Framebuffer() = default;
    void Build(const std::vector<GLenum>& attachments);
    Framebuffer(const GLenum& attachment, int32_t width, int32_t height);
    Framebuffer(const std::vector<GLenum>& attachments, int32_t width, int32_t height);
    void Bind();
};

struct PerspCamera
{
    vec3 pos, up, forward, right, orientation;
    mat4 proj, view;
    float sensitivity = 2.5f;
    float velocity = 5.0f;
    float near, far, fov;
    Frustum<float> frustum;
    std::function<void(PerspCamera&, Window*)> updateFunc = nullptr;
    inline PerspCamera(const PerspCamera& lhs) = default;
    inline PerspCamera() = default;
    PerspCamera(Window* window, float near = 0.1f, float far = 100.0f, float fov = 60.0f);
    void Reset();
    void Update(Window* window);
    void UpdateInternal();
};

struct OrthoCamera
{
    vec3 pos;
    mat4 proj, view;
    float near, far;
    Frustum<float> frustum;
    std::function<void(OrthoCamera&, Window*)> updateFunc = nullptr;
    OrthoCamera(Window* window, float near = 0.1f, float far = 100.0f);
    inline OrthoCamera() = default;
    void Reset();
    void Update(Window* window);
    void UpdateInternal();
};

struct Layer
{
    Sprite buffer;
    uint32_t id;
    bool camEnabled = false;
    inline Layer() = default;
    Layer(int32_t width, int32_t height);
};

struct default_vertex
{
    vec4 position;
    vec2 texcoord;
};

struct Decal
{
    GLuint id = 0;
    int32_t width = 0, height = 0;
    inline Decal() = default;
    Decal(Sprite& spr);
    Decal(const std::string& path);
    void Update(Sprite& spr);
    const vec2i GetSize() const;
    void Resize(int32_t w, int32_t h);
    void Scale(float sx, float sy);
    void Resize(const vec2i& size);
    void Scale(const vec2& scale);
    const Rect<int32_t> GetViewport() const;
    const float GetAspectRatio() const;
    virtual ~Decal() {}
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
    Timer();
    void Update();
};

enum class Pass
{
    Pass2D,
    Pass3D
};

enum class PostProcess
{
    None, Invert,
    Blur, GaussianBlur,
    EdgeDetection, Sharpen,
    Emboss, Monochrome,
    Sepia, Dilation
};

struct Triangle
{
    vec4 pos[3];
    vec3 norm[3];
    vec3 tex[3];
    vec4 col[3];
};

struct Window
{
    void Begin();
    void End();
    void Start(int32_t width, int32_t height);
    void Clear(const Color& color);
    void DrawScene(bool updateLayers = true);
    void DrawLayers(bool updateLayers = true);
    void EnableStencil(bool stencil);
    void EnableDepth(bool depth);
    const int32_t GetWidth() const;
    const int32_t GetHeight() const;
    const vec2d GetMousePos() const;
    const vec2i GetScrSize() const;
    const vec2 GetMouseDelta() const;
    const float GetAspectRatio() const;
    const Rect<int32_t> GetViewport() const;
    const float GetDeltaTime() const;
    Key GetKey(int key);
    Key GetMouseButton(int button);
    const DrawMode GetDrawMode() const;
    void SetDrawMode(DrawMode drawMode);
    Layer& GetLayer(const size_t& index);
    void SetCurrentLayer(const size_t& index);
    void CreateFBO(const GLenum& attachment);
    void CreateFBO(const std::vector<GLenum>& attachments);
    void BindFBO(const size_t& index);
    void UnbindFBO();
    void CreateLayer(int32_t width = 0, int32_t height = 0);
    void SetShader(const size_t& index);
    Shader& GetShader(const size_t& index);
    void SetPerspCam(const size_t& index);
    void SetOrthoCam(const size_t& index);
    PerspCamera& GetPerspCam();
    OrthoCamera& GetOrthoCam();
    Frustum<float>& GetFrustum(const Pass& p);
    void SetPixel(int32_t x, int32_t y, const Color& color);
    const Color GetPixel(int32_t x, int32_t y) const;
    float CalculateSpotLight(int index, const vec3& view, const vec3& norm) const;
    float CalculatePointLight(int index, const vec3& view, const vec3& norm) const;
    float CalculateDirectionalLight(int index, const vec3& view, const vec3& norm) const;
    int ClipTriangle(const Plane<float>& plane, Triangle& in, Triangle& out0, Triangle& out1);
    void RasterizeTriangle(Sprite& sprite, const Triangle& triangle, const mat4& model = mat4::identity());
    bool ClipLine(int32_t& sx, int32_t& sy, int32_t& ex, int32_t& ey);
    void DrawLine(int32_t sx, int32_t sy, int32_t ex, int32_t ey, const Color& color);
    void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);
    void DrawRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);
    void DrawRotatedRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, float rotation, const Color& color);
    void DrawCircle(int32_t cx, int32_t cy, int32_t radius, const Color& color);
    void DrawCircleOutline(int32_t cx, int32_t cy, int32_t radius, const Color& color);
    void DrawTriangle(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color);
    void DrawTriangleOutline(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color);
    void DrawSprite(Sprite& sprite, Transform<float>& transform, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm, const vec2& origin = 0.5f);
    void DrawSprite(Sprite& sprite, Transform<float>& transform, const Rect<float>& src, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm, const vec2& origin = 0.5f);
    void DrawSprite(int32_t x, int32_t y, Sprite& sprite, const vec2& scale = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    void DrawSprite(int32_t x, int32_t y, const Rect<float>& src, Sprite& sprite, const vec2& scale = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    void DrawSprite(const Rect<float>& dst, Sprite& sprite, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    void DrawSprite(const Rect<float>& dst, const Rect<float>& src, Sprite& sprite, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    void DrawCharacter(int32_t x, int32_t y, const char c, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawRotatedCharacter(int32_t x, int32_t y, const char c, float rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawCharacter(const Rect<float>& dst, const char c, const Color& color = {0, 0, 0, 255});
    void DrawText(const Rect<float>& dst, const std::string& text, const Color& color = {0, 0, 0, 255});
    void DrawRotatedText(int32_t x, int32_t y, const std::string& text, float rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void DrawText(int32_t x, int32_t y, const std::string& text, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void SetPixel(const vec2i& pos, const Color& color);
    const Color GetPixel(const vec2i& pos) const;
    bool ClipLine(vec2i& start, vec2i& end);
    void DrawLine(const vec2i& start, const vec2i& end, const Color& color);
    void DrawRect(const vec2i& pos, const vec2i& size, const Color& color);
    void DrawRectOutline(const vec2i& pos, const vec2i& size, const Color& color);
    void DrawRotatedRectOutline(const vec2i& pos, const vec2i& size, float rotation, const Color& color);
    void DrawCircle(const vec2i& center, int32_t radius, const Color& color);
    void DrawCircleOutline(const vec2i& center, int32_t radius, const Color& color);
    void DrawTriangle(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color);
    void DrawTriangleOutline(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color);
    void DrawSprite(const vec2i& pos, Sprite& sprite, const vec2& scale = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    void DrawSprite(const vec2i& pos, const Rect<float>& src, Sprite& sprite, const vec2& scale = 1.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm);
    void DrawCharacter(const vec2i& pos, const char c, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawRotatedCharacter(const vec2i& pos, const char c, float rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawRotatedText(const vec2i& pos, const std::string& text, float rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void DrawText(const vec2i& pos, const std::string& text, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void DrawMesh(Mesh& mesh, bool lighting = true, bool wireframe = false);
    void DrawSkybox();
    void DrawTexturedTriangle(Sprite& sprite,
        vec2i pos0, vec3 norm0, vec3 tex0, vec4 col0,
        vec2i pos1, vec3 norm1, vec3 tex1, vec4 col1,
        vec2i pos2, vec3 norm2, vec3 tex2, vec4 col2);
    virtual void UserStart() = 0;
    virtual void UserUpdate() = 0;
    std::vector<Shader> vecShaders;
    std::unordered_map<int, Key> currKeyboardState;
    std::unordered_map<int, Key> currMouseState;
    PixelMode pixelMode = PixelMode::Normal;
    std::vector<Layer> vecDrawTargets;
    size_t currDrawTarget;
    size_t currShader;
    GLFWwindow* handle;
    bool depthEnabled = false;
    bool stencilEnabled = false;
    std::vector<PerspCamera> vecPerspCameras;
    std::vector<OrthoCamera> vecOrthoCameras;
    size_t currPerspCamera = 0;
    size_t currOrthoCamera = 0;
    std::array<PointLight, 4> arrPointLights;
    std::array<DirectionalLight, 4> arrDirectionalLights;
    std::array<SpotLight, 4> arrSpotLights;
    vec2 currMousePos, prevMousePos;
    std::vector<Framebuffer> vecFramebuffers;
    Timer timer;
    VAO vao;
    Buffer<default_vertex, GL_ARRAY_BUFFER> vbo;
    VAO skyboxVAO;
    GLuint skyboxCubeMap = 0;
    float* depthBuffer;
#ifdef POST_PROCESS
    PostProcess postProcess = PostProcess::None;
#endif
    virtual ~Window()
    {
        glfwDestroyWindow(handle);
        glfwTerminate();
    }
};

#endif

#ifdef WINDOW_H
#undef WINDOW_H

inline void Framebuffer::Build(const std::vector<GLenum>& attachments)
{
    glGenFramebuffers(1, &id);
    glGenRenderbuffers(1, &rbo);
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    int maxColorAttachments = 0;
    glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &maxColorAttachments);
    const size_t size = attachments.size();
    renderTargets.resize(size);
    for(size_t i = 0; i < size; i++)
    {
        if(attachments[i] >= GL_COLOR_ATTACHMENT0 && attachments[i] <= GL_COLOR_ATTACHMENT0 + maxColorAttachments)
            CreateTexture(renderTargets[i], width, height);
        else if(attachments[i] == GL_DEPTH_STENCIL_ATTACHMENT)
            CreateTexture(renderTargets[i], width, height, GL_DEPTH24_STENCIL8, GL_UNSIGNED_INT_24_8);
        else if(attachments[i] == GL_DEPTH_ATTACHMENT)
            CreateTexture(renderTargets[i], width, height, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT);
        else if(attachments[i] == GL_STENCIL_ATTACHMENT)
            CreateTexture(renderTargets[i], width, height, GL_STENCIL_INDEX, GL_UNSIGNED_BYTE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, attachments[i], GL_TEXTURE_2D, renderTargets[i], 0);
    }
    glDrawBuffers(size, attachments.data());
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

inline Framebuffer::Framebuffer(const std::vector<GLenum>& attachments, int32_t width, int32_t height) : width(width), height(height)
{
    Build(attachments);
}

inline Framebuffer::Framebuffer(const GLenum& attachment, int32_t width, int32_t height) : width(width), height(height)
{
    Build({attachment});
}

inline void Framebuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, id);
}

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

inline Sprite::Sprite(Decal& decal) : width(decal.width), height(decal.height)
{
    data.resize(decal.width * decal.height);
    glBindTexture(GL_TEXTURE_2D, decal.id);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());
    glBindTexture(GL_TEXTURE_2D, 0);
}

inline void Sprite::SetPixel(int32_t x, int32_t y, const Color& color)
{
    if(data.empty())
        return;
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

inline const Color Sprite::GetPixel(int32_t x, int32_t y) const
{
    if(data.empty())
        return 0;
    switch(drawMode)
    {
        case DrawMode::Normal:
        {
            if(x < 0 || x >= width || y < 0 || y >= height) 
                return 0;
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

inline void Sprite::SetPixel(const vec2i& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

inline const Color Sprite::GetPixel(const vec2i& pos) const
{
    return GetPixel(pos.x, pos.y);
}

inline void Sprite::Scale(float sx, float sy)
{
    if(sx < 0.0f || sy < 0.0f || width * height <= 0)
        return;
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
    for(int i = 0; i < width * height; i++)
        data[i] = data[i].a == 0 ? data[i] : lerp(data[i], color, 0.5f);
}

inline const vec2i Sprite::GetSize() const
{
    return {width, height};
}

inline const float Sprite::GetAspectRatio() const
{
    return (float)width / height;
}

inline const Rect<int32_t> Sprite::GetViewport() const
{
    return {0, this->GetSize()};
}

inline void Sprite::Resize(const vec2i& size)
{
    Resize(size.x, size.y);
}

inline void Sprite::Scale(const vec2& scale)
{
    Scale(scale.x, scale.y);
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

inline const vec2i Decal::GetSize() const
{
    return {width, height};
}

inline Decal::Decal(const std::string& path)
{
    int channels;
    unsigned char *bytes = stbi_load(path.c_str(), &width, &height, &channels, 4);
    CreateTexture(id, width, height);
    UpdateTexture(id, width, height, bytes);
    stbi_image_free(bytes);
}

inline void Decal::Resize(int32_t w, int32_t h)
{
    Sprite spr = *this;
    spr.Resize(w, h);
    *this = spr;
}

inline void Decal::Scale(float sx, float sy)
{
    this->Resize(width * sx, height * sy);
}

inline void Decal::Resize(const vec2i& size)
{
    Resize(size.x, size.y);
}

inline void Decal::Scale(const vec2& scale)
{
    Scale(scale.x, scale.y);
}

inline const Rect<int32_t> Decal::GetViewport() const
{
    return {0, this->GetSize()};
}

inline const float Decal::GetAspectRatio() const
{
    return (float)width / height;
}

inline PerspCamera::PerspCamera(Window* window, float near, float far, float fov) 
: far(far), near(near), fov(fov)
{
    proj = make_perspective_mat(window->GetAspectRatio(), fov, near, far);
    this->Reset();
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
    forward = vec3
    {
        std::cos(orientation.yaw) * std::cos(orientation.pitch), 
        std::sin(orientation.pitch), 
        std::sin(orientation.yaw) * std::cos(orientation.pitch)
    }.norm();
    right = cross(forward, defWorldUp).norm();
    up = cross(right, forward).norm();
    view = mat_look_at(pos, pos + forward, up);
    frustum.Set(proj * view);
}

inline OrthoCamera::OrthoCamera(Window* window, float near, float far)
: near(near), far(far)
{
    proj = make_ortho_mat(1.0f, -1.0f, -1.0f, 1.0f, near, far);
    this->Reset();
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
    view = translation_mat_3d<float>({pos.xy, -defCameraPos.z});
    frustum.Set(proj * view);
}

void Window::Start(int32_t width, int32_t height)
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
    depthBuffer = new float[width * height];
    memset(depthBuffer, 0, 4 * width * height);
    vecPerspCameras[0].updateFunc = [](PerspCamera& cam, Window* window)
    {
        const float dt = window->timer.deltaTime;
        const vec2 offset = window->GetMouseDelta() * cam.sensitivity * dt;
        cam.orientation += vec3{0.0f, -offset.y, offset.x};
        cam.orientation.pitch = std::clamp<float>(cam.orientation.pitch, -pi * 0.5f, pi * 0.5f);
        if(window->GetKey(GLFW_KEY_UP) == Key::Held) cam.pos += cam.forward * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_DOWN) == Key::Held) cam.pos -= cam.forward * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_RIGHT) == Key::Held) cam.pos += cam.right * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_LEFT) == Key::Held) cam.pos -= cam.right * cam.velocity * dt;
        if(window->GetKey(GLFW_KEY_R) == Key::Pressed) cam.Reset();
    };
    vecShaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\default.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\default.frag").c_str())
        })
    ));
    vecShaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\sprite_batch.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\sprite_batch.frag").c_str())
        }),
        [&](Shader& instance)
        {
            for(int i = 0; i < maxSprites; i++)
                instance.SetUniformInt("buffers[" + std::to_string(i) + "]", &i);
        }
    ));
    vecShaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\geo_batch.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\geo_batch.frag").c_str())
        })
    ));
    vecShaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\lighting_3d.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\lighting_3d.frag").c_str())
        }),
        [&](Shader& instance)
        {
            for(size_t i = 0; i < arrPointLights.size(); i++)
            {
                const PointLight light = arrPointLights[i];
                const std::string prefix = "arrPointLights[" + std::to_string(i) + "]";
                instance.SetUniformBool(prefix + ".Enabled", light.enabled);
                instance.SetUniformVec(prefix + ".Position", light.position);
                instance.SetUniformVec(prefix + ".Color", light.color);
                instance.SetUniformFloat(prefix + ".Constant", &light.constant);
                instance.SetUniformFloat(prefix + ".Linear", &light.linear);
                instance.SetUniformFloat(prefix + ".Quadratic", &light.quadratic);
            }
            for(size_t i = 0; i < arrDirectionalLights.size(); i++)
            {
                const DirectionalLight light = arrDirectionalLights[i];
                const std::string prefix = "arrDirectionalLights[" + std::to_string(i) + "]";
                instance.SetUniformBool(prefix + ".Enabled", light.enabled);
                instance.SetUniformVec(prefix + ".Direction", light.direction);
                instance.SetUniformVec(prefix + ".Color", light.color);
            }
            for(size_t i = 0; i < arrSpotLights.size(); i++)
            {
                const SpotLight light = arrSpotLights[i];
                const std::string prefix = "arrSpotLights[" + std::to_string(i) + "]";
                instance.SetUniformBool(prefix + ".Enabled", light.enabled);
                instance.SetUniformVec(prefix + ".Color", light.color);
                instance.SetUniformFloat(prefix + ".Constant", &light.constant);
                instance.SetUniformFloat(prefix + ".Linear", &light.linear);
                instance.SetUniformFloat(prefix + ".Quadratic", &light.quadratic);
                instance.SetUniformFloat(prefix + ".CutOff", &light.cutOff);
                instance.SetUniformFloat(prefix + ".OuterCutOff", &light.outerCutOff);
                instance.SetUniformVec(prefix + ".Position", light.position);
                instance.SetUniformVec(prefix + ".Direction", light.direction);
            }
        },
        [&](Shader& instance)
        {
            instance.SetUniformMat("perspMat", GetPerspCam().frustum.mat);
            instance.SetUniformVec("perspCameraPos", GetPerspCam().pos);
        }
    ));
    vecShaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\default_3d.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\default_3d.frag").c_str())
        }),
        nullptr,
        [&](Shader& instance)
        {
            instance.SetUniformMat("perspMat", GetPerspCam().frustum.mat);
        }
    ));
#ifdef POST_PROCESS
    vecShaders.push_back(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\post_processing.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\post_processing.frag").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniformInt("scrQuad", 0);
            instance.SetUniformInt("postProcess", (int)postProcess);
            BindTexture(vecFramebuffers[0].renderTargets[0], 0);
        }
    ));
#else
        vecShaders.emplace_back();
#endif
    vecShaders.push_back({
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("custom-game-engine\\shaders\\cubemap.vert").c_str()),
            CompileShader(GL_GEOMETRY_SHADER, ReadShader("custom-game-engine\\shaders\\cubemap.geom").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("custom-game-engine\\shaders\\cubemap.frag").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniformMat("projection", GetPerspCam().proj);
            instance.SetUniformMat("view", mat4(mat3(GetPerspCam().view)));
            if(skyboxCubeMap)
                glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxCubeMap);
        }
    });
    SetShader(0);
    currMousePos = prevMousePos = GetMousePos();
    vao.Build();
    vbo.Build({
        {{-1.0f,  1.0f, -0.92192190f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f, -1.0f, -0.92192190f, 1.0f}, {0.0f, 1.0f}},
        {{ 1.0f,  1.0f, -0.92192190f, 1.0f}, {1.0f, 0.0f}},
        {{ 1.0f, -1.0f, -0.92192190f, 1.0f}, {1.0f, 1.0f}}
    });
    vbo.AddAttrib(0, 4, offsetof(default_vertex, position));
    vbo.AddAttrib(1, 2, offsetof(default_vertex, texcoord));
    skyboxVAO.Build();
#ifdef POST_PROCESS
    CreateFBO(GL_COLOR_ATTACHMENT0);
#endif
    UserStart();
    while(!glfwWindowShouldClose(handle))
    {
        Begin();
#ifndef POST_PROCESS
        DrawScene();
#endif
        End();
    }
}

inline const float Window::GetDeltaTime() const
{
    return timer.deltaTime;
}

inline const float Window::GetAspectRatio() const
{
    return vecDrawTargets[currDrawTarget].buffer.GetAspectRatio();
}

inline void Window::SetShader(const size_t& index)
{
    if(currShader == index || index >= vecShaders.size()) return;
    vecShaders[currShader = index].Set();
    vecShaders[index].Update();
}

inline void Window::SetPerspCam(const size_t& index)
{
    if(currPerspCamera != index && index < vecPerspCameras.size())
        currPerspCamera = index;
}

inline void Window::SetOrthoCam(const size_t& index)
{
    if(currOrthoCamera != index && index < vecOrthoCameras.size())
        currOrthoCamera = index;
}

inline PerspCamera& Window::GetPerspCam()
{
    return vecPerspCameras[currPerspCamera];
}

inline OrthoCamera& Window::GetOrthoCam()
{
    return vecOrthoCameras[currOrthoCamera];
}

inline Frustum<float>& Window::GetFrustum(const Pass& p)
{
    if(p == Pass::Pass2D)
        return vecOrthoCameras[currOrthoCamera].frustum;
    else
        return vecPerspCameras[currPerspCamera].frustum;
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
    if(stencilEnabled) code |= GL_STENCIL_BUFFER_BIT;
    const vec4 vec = ColorF(color);
    glClearColor(vec.r, vec.g, vec.b, vec.a);
    glClear(code);
    memset(depthBuffer, 0, 4 * GetWidth() * GetHeight());
    vecDrawTargets[currDrawTarget].buffer.Clear(0);
}

inline void Window::CreateFBO(const GLenum& attachment)
{
    vecFramebuffers.emplace_back(attachment, GetWidth(), GetHeight());
}

inline void Window::CreateFBO(const std::vector<GLenum>& attachments)
{
    vecFramebuffers.emplace_back(attachments, GetWidth(), GetHeight());
}

inline void Window::BindFBO(const size_t& index)
{
    if(index < vecFramebuffers.size())
        vecFramebuffers[index].Bind();
}

inline void Window::UnbindFBO()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

inline void Window::EnableDepth(bool depth)
{
    if(depth)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
    depthEnabled = depth;
}

inline void Window::EnableStencil(bool stencil)
{
    if(stencil)
        glEnable(GL_STENCIL_TEST);
    else
        glDisable(GL_STENCIL_TEST);
    stencilEnabled = stencil;
}

inline void Window::Begin()
{
    timer.Update();
    for(auto& cam : vecPerspCameras) cam.Update(this);
    for(auto& cam : vecOrthoCameras) cam.Update(this);
    vecShaders[currShader].Update();
    prevMousePos = currMousePos;
    currMousePos = GetMousePos();
}

inline void Window::DrawScene(bool updateLayers)
{
    UserUpdate();
    DrawLayers(updateLayers);
}

inline void Window::DrawLayers(bool updateLayers)
{
    SetShader(0);
    vao.Bind();
    for(auto& drawTarget : vecDrawTargets)
    {
        if(updateLayers)
            UpdateTexture(
                drawTarget.id,
                drawTarget.buffer.width,
                drawTarget.buffer.height,
                drawTarget.buffer.data.data()
            );
        BindTexture(drawTarget.id);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    BindTexture(0);
    vao.Unbind();
}

inline void Window::End()
{
#ifdef POST_PROCESS
    BindFBO(0);
    DrawScene();
    UnbindFBO();
    vao.Bind();
    SetShader(5);
    EnableDepth(false);
    Clear(0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    vao.Unbind();
    EnableDepth(true);
#endif
    glfwSwapBuffers(handle);
    glfwPollEvents();
}

inline void Window::CreateLayer(int32_t width, int32_t height)
{
    if(width == 0 || height == 0) {width = GetWidth(); height = GetHeight();}
    vecDrawTargets.emplace_back(width, height);
}

inline void Window::SetCurrentLayer(const size_t& index)
{
    if(currDrawTarget != index && index < vecDrawTargets.size())
        currDrawTarget = index;
}

inline Layer& Window::GetLayer(const size_t& index)
{
    return vecDrawTargets[index];
}

inline Shader& Window::GetShader(const size_t& index)
{
    return vecShaders[index];
}

inline const int32_t Window::GetWidth() const
{
    return vecDrawTargets[currDrawTarget].buffer.width;
}

inline const int32_t Window::GetHeight() const
{
    return vecDrawTargets[currDrawTarget].buffer.height;
}

inline const vec2 Window::GetMouseDelta() const
{
    return currMousePos - prevMousePos;
}

inline const Color Window::GetPixel(int32_t x, int32_t y) const
{
    return vecDrawTargets[currDrawTarget].buffer.GetPixel(x, y);
}

inline void Window::SetDrawMode(DrawMode drawMode)
{
    vecDrawTargets[currDrawTarget].buffer.drawMode = drawMode;
}

inline const DrawMode Window::GetDrawMode() const
{
    return vecDrawTargets[currDrawTarget].buffer.drawMode;
}

inline const vec2d Window::GetMousePos() const
{
    vec2d res;
    glfwGetCursorPos(handle, &res.x, &res.y);
    return res;
}

inline const vec2i Window::GetScrSize() const
{
    return vecDrawTargets[currDrawTarget].buffer.GetSize();
}

inline const Rect<int32_t> Window::GetViewport() const
{
    return vecDrawTargets[currDrawTarget].buffer.GetViewport();
}

inline void Window::SetPixel(int32_t x, int32_t y, const Color& color)
{
    if(pixelMode == PixelMode::Alpha && color.a == 0) 
        return;
    vec4 pos = {(float)x, (float)y, 0.0f, 1.0f};
    if(vecDrawTargets[currDrawTarget].camEnabled)
    {
        const vec2 scrSize = GetScrSize();
        pos.xy = ScrToWorldPos(pos.xy, scrSize);
        pos = GetOrthoCam().frustum.mat * pos;
        pos.xy = WorldToScrPos(pos.xy / (pos.w != 0.0f ? pos.w : 1.0f), scrSize);
    }
    vecDrawTargets[currDrawTarget].buffer.SetPixel(pos.x, pos.y, color);
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

int Window::ClipTriangle(const Plane<float>& plane, Triangle& in, Triangle& out0, Triangle& out1)
{
    vec4 insidePos[3], insideCol[3]; 
    vec3 insideNorm[3], insideTex[3];
    vec4 outsidePos[3], outsideCol[3]; 
    vec3 outsideNorm[3], outsideTex[3];
    int insideCount = 0, outsideCount = 0;
    if(plane.Intersects(in.pos[0]) != Intersection::Back)
    {
        insidePos[insideCount] = in.pos[0];
        insideNorm[insideCount] = in.norm[0];
        insideTex[insideCount] = in.tex[0];
        insideCol[insideCount] = in.col[0];
        ++insideCount;
    }
    else
    {
        outsidePos[outsideCount] = in.pos[0];
        outsideNorm[outsideCount] = in.norm[0];
        outsideTex[outsideCount] = in.tex[0];
        outsideCol[outsideCount] = in.col[0];
        ++outsideCount;
    }
    if(plane.Intersects(in.pos[1]) != Intersection::Back)
    {
        insidePos[insideCount] = in.pos[1];
        insideNorm[insideCount] = in.norm[1];
        insideTex[insideCount] = in.tex[1];
        insideCol[insideCount] = in.col[1];
        ++insideCount;
    }
    else
    {
        outsidePos[outsideCount] = in.pos[1];
        outsideNorm[outsideCount] = in.norm[1];
        outsideTex[outsideCount] = in.tex[1];
        outsideCol[outsideCount] = in.col[1];
        ++outsideCount;
    }
    if(plane.Intersects(in.pos[2]) != Intersection::Back)
    {
        insidePos[insideCount] = in.pos[2];
        insideNorm[insideCount] = in.norm[2];
        insideTex[insideCount] = in.tex[2];
        insideCol[insideCount] = in.col[2];
        ++insideCount;
    }
    else
    {
        outsidePos[outsideCount] = in.pos[2];
        outsideNorm[outsideCount] = in.norm[2];
        outsideTex[outsideCount] = in.tex[2];
        outsideCol[outsideCount] = in.col[2];
        ++outsideCount;
    }
    if (insideCount == 0)
        return 0;
    if (insideCount == 3)
    {
        out0 = in;
        return 1;
    }
    if (insideCount == 1 && outsideCount == 2)
    {
    	float t;
    	out0.pos[0] = insidePos[0];
        out0.norm[0] = insideNorm[0];
        out0.tex[0] = insideTex[0];
        out0.col[0] = insideCol[0];
    	out0.pos[1].xyz = plane.IntersectionPoint(insidePos[0].xyz, outsidePos[0].xyz, t);
        out0.pos[1].w = lerp(insidePos[0].w, outsidePos[0].w, t);
        out0.norm[1] = lerp(insideNorm[0], outsideNorm[0], t);
        out0.tex[1] = lerp(insideTex[0], outsideTex[0], t);
        out0.col[1] = lerp(insideCol[0], outsideCol[0], t);
    	out0.pos[2].xyz = plane.IntersectionPoint(insidePos[0].xyz, outsidePos[1].xyz, t);
        out0.pos[2].w = lerp(insidePos[0].w, outsidePos[1].w, t);
        out0.norm[2] = lerp(insideNorm[0], outsideNorm[1], t);
        out0.tex[2] = lerp(insideTex[0], outsideTex[1], t);
        out0.col[2] = lerp(insideCol[0], outsideCol[1], t);
        return 1;
    }
    if (insideCount == 2 && outsideCount == 1)
    {
    	float t;
        out0.pos[0] = insidePos[0];
        out0.norm[0] = insideNorm[0];
        out0.tex[0] = insideTex[0];
        out0.col[0] = insideCol[0];
        out1.pos[0] = out0.pos[1] = insidePos[1];
        out1.norm[0] = out0.norm[1] = insideNorm[1];
        out1.tex[0] = out0.tex[1] = insideTex[1];
        out1.col[0] = out0.col[1] = insideCol[1];
    	out1.pos[1].xyz = out0.pos[2].xyz = plane.IntersectionPoint(insidePos[0].xyz, outsidePos[0].xyz, t);
        out1.pos[1].w = out0.pos[2].w = lerp(insidePos[0].w, outsidePos[0].w, t);
    	out1.norm[1] = out0.norm[2] = lerp(insideNorm[0], outsideNorm[0], t);
        out1.tex[1] = out0.tex[2] = lerp(insideTex[0], outsideTex[0], t);
        out1.col[1] = out0.col[2] = lerp(insideCol[0], outsideCol[0], t);
        out1.pos[2].xyz = plane.IntersectionPoint(insidePos[1].xyz, outsidePos[0].xyz, t);
        out1.pos[2].w = lerp(insidePos[1].w, outsidePos[0].w, t);
        out1.norm[2] = lerp(insideNorm[1], outsideNorm[0], t);
        out1.tex[2] = lerp(insideTex[1], outsideTex[0], t);
        out1.col[2] = lerp(insideCol[1], outsideCol[0], t);
    	return 2;
    }
    return 0;
}

void Window::RasterizeTriangle(Sprite& sprite, const Triangle& triangle, const mat4& model)
{
    std::list<Triangle> listTriangles;
    const vec2 scrSize = GetScrSize();
    Triangle temp = triangle;
    temp.pos[0].w = temp.pos[1].w = temp.pos[2].w = 1.0f;
    temp.tex[0].z = temp.tex[1].z = temp.tex[2].z = 1.0f;
    temp.pos[0] = model * temp.pos[0];
    temp.pos[1] = model * temp.pos[1];
    temp.pos[2] = model * temp.pos[2];
    const mat3 inv = mat3(model.inverse().transpose());
    temp.norm[0] = inv * temp.norm[0];
    temp.norm[1] = inv * temp.norm[1];
    temp.norm[2] = inv * temp.norm[2];
    PerspCamera& cam = vecPerspCameras[currPerspCamera];
    Triangle clipped[2];
    listTriangles.push_back(temp);
    int newTris = 1;
    for (int i = 0; i < 6; i++)
    {
    	int trisToAdd = 0;
    	while (newTris > 0)
    	{
            Triangle test = listTriangles.front();
    		listTriangles.pop_front();
    		newTris--;
    		switch (i)
    		{
                case 0: trisToAdd = ClipTriangle(cam.frustum.near, test, clipped[0], clipped[1]); break;
                case 1: trisToAdd = ClipTriangle(cam.frustum.far, test, clipped[0], clipped[1]); break;
                case 2:	trisToAdd = ClipTriangle(cam.frustum.top, test, clipped[0], clipped[1]); break;
                case 3:	trisToAdd = ClipTriangle(cam.frustum.bottom, test, clipped[0], clipped[1]); break;
                case 4:	trisToAdd = ClipTriangle(cam.frustum.right, test, clipped[0], clipped[1]); break;
                case 5:	trisToAdd = ClipTriangle(cam.frustum.left, test, clipped[0], clipped[1]); break;
            }
            for (int j = 0; j < trisToAdd; j++)
            	listTriangles.push_back(clipped[j]);
    	}
        newTris = listTriangles.size();
    }
    for (auto &tri : listTriangles)
    {
        tri.pos[0] = cam.frustum.mat * tri.pos[0];
        tri.pos[1] = cam.frustum.mat * tri.pos[1];
        tri.pos[2] = cam.frustum.mat * tri.pos[2];
        tri.pos[0].xyz /= tri.pos[0].w;
        tri.pos[1].xyz /= tri.pos[1].w;
        tri.pos[2].xyz /= tri.pos[2].w;
        tri.tex[0] /= tri.pos[0].w;
        tri.tex[1] /= tri.pos[1].w;
        tri.tex[2] /= tri.pos[2].w;
        tri.norm[0] /= tri.pos[0].w;
        tri.norm[1] /= tri.pos[1].w;
        tri.norm[2] /= tri.pos[2].w;
        tri.pos[0].xy = WorldToScrPos(tri.pos[0].xy, scrSize);
        tri.pos[1].xy = WorldToScrPos(tri.pos[1].xy, scrSize);
        tri.pos[2].xy = WorldToScrPos(tri.pos[2].xy, scrSize);
        DrawTexturedTriangle(sprite,
            tri.pos[0].xy, tri.norm[0], tri.tex[0], tri.col[0],
            tri.pos[1].xy, tri.norm[1], tri.tex[1], tri.col[1],
            tri.pos[2].xy, tri.norm[2], tri.tex[2], tri.col[2]);
    }
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

inline void Window::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color)
{
    w = std::clamp(w, 0, GetWidth());
    h = std::clamp(h, 0, GetHeight());
    for(int32_t i = x; i <= x + w; i++)
        for(int32_t j = y; j <= y + h; j++)
            SetPixel(i, j, color);
}

inline void Window::DrawRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color)
{
    DrawLine(x, y, x, y + h, color);
    DrawLine(x, y, x + w, y, color);
    DrawLine(x + w, y + h, x, y + h, color);
    DrawLine(x + w, y + h, x + w, y, color);
}

inline void Window::DrawRotatedRectOutline(int32_t x, int32_t y, int32_t w, int32_t h, float rotation, const Color& color)
{
    if(rotation == 0.0f) { DrawRectOutline(x, y, w, h, color); return; }
    const vec2 pos0 = rotate<float>(rotation, {0.0f, (float)h});
    const vec2 pos1 = rotate<float>(rotation, {(float)w, 0.0f});
    const vec2 pos2 = rotate<float>(rotation, {(float)w, (float)h});
    DrawLine(x + pos2.x, y + pos2.y, x + pos1.x, y + pos1.y, color);
    DrawLine(x + pos2.x, y + pos2.y, x + pos0.x, y + pos0.y, color);
    DrawLine(x, y, x + pos1.x, y + pos1.y, color);
    DrawLine(x + pos0.x, y + pos0.y, x, y, color);
}

inline void Window::DrawCircle(int32_t cx, int32_t cy, int32_t radius, const Color& color)
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

inline void Window::DrawCircleOutline(int32_t cx, int32_t cy, int32_t radius, const Color& color)
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
        drawPixels(++x, y);
    }
}

inline void Window::DrawTriangle(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color)
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
    const float dx0 = (x2 - x0) / (y2 - y0 + 1.0f);
    const float dx1 = (x1 - x0) / (y1 - y0 + 1.0f);
    const float dx2 = (x2 - x1) / (y2 - y1 + 1.0f);
    float sx = x0;
    float ex = x0 + dx1;
    for(int32_t y = y0; y <= y2; y++)
    {
        drawLine((int32_t)sx, (int32_t)ex, y);
        sx += dx0;
        ex += (y < y1) ? dx1 : dx2;
    }
}

inline float Window::CalculateDirectionalLight(int index, const vec3& view, const vec3& norm) const
{
    const vec3 dir = -arrDirectionalLights[index].direction.norm();
    const float diffuse = 0.5f * std::max(dot(norm, dir), 0.0f);
    const vec3 refl = reflect(-dir, norm);
    const float specular = 0.8f * std::pow(std::max(dot(view, refl), 0.0f), 32.0f);
    return 0.1f + diffuse + specular;
}

inline float Window::CalculatePointLight(int index, const vec3& view, const vec3& norm) const
{
    return 0.0f;
}

inline float Window::CalculateSpotLight(int index, const vec3& view, const vec3& norm) const
{
    return 0.0f;
}

void Window::DrawTexturedTriangle(Sprite& sprite,
    vec2i pos0, vec3 norm0, vec3 tex0, vec4 col0,
    vec2i pos1, vec3 norm1, vec3 tex1, vec4 col1,
    vec2i pos2, vec3 norm2, vec3 tex2, vec4 col2)
{
    if(pos1.y < pos0.y)
    {
        std::swap(pos0, pos1);
        std::swap(norm0, norm1);
        std::swap(tex0, tex1);
        std::swap(col0, col1);
    }
    if(pos2.y < pos0.y)
    {
        std::swap(pos0, pos2);
        std::swap(norm0, norm2);
        std::swap(tex0, tex2);
        std::swap(col0, col2);
    }
    if(pos2.y < pos1.y)
    {
        std::swap(pos1, pos2);
        std::swap(norm1, norm2);
        std::swap(tex1, tex2);
        std::swap(col1, col2);
    }
    Sprite& buffer = vecDrawTargets[currDrawTarget].buffer;
    const vec2 sprSize = sprite.GetSize();
    const int32_t width = GetWidth();
    auto drawLine = [&](int32_t sx, int32_t ex, int32_t y, vec3 st, vec3 et, vec3 sn, vec3 en, vec4 sc, vec4 ec)
    {
        if(sx > ex)
    	{
    		std::swap(sx, ex);
    		std::swap(st, et);
            std::swap(sc, ec);
            std::swap(sn, en);
    	}
    	vec3 tex, norm;
    	double t = 0.0;
        const double dt = 1.0 / (double)(ex - sx);
        for(int32_t x = sx; x <= ex; x++)
    	{
            tex = lerp(st, et, t);
    		norm = lerp(sn, en, t);
            if(depthBuffer[y * width + x] < tex.z)
            {
                buffer.SetPixel(x, y, sprite.GetPixel(sprSize * tex.xy / tex.z) * lerp(sc, ec, t));
                depthBuffer[y * width + x] = tex.z;
            }
    		t += dt;
    	}
    };
    const float dy0 = pos2.y - pos0.y + 1.0f;
    const float dy1 = pos1.y - pos0.y + 1.0f;
    const float dy2 = pos2.y - pos1.y + 1.0f;
    const float dx0 = (pos2.x - pos0.x) / dy0;
    const float dx1 = (pos1.x - pos0.x) / dy1;
    const float dx2 = (pos2.x - pos1.x) / dy2;
    const vec3 dn0 = (norm2 - norm0) / dy0;
    const vec3 dn1 = (norm1 - norm0) / dy1;
    const vec3 dn2 = (norm2 - norm1) / dy2;
    const vec3 dt0 = (tex2 - tex0) / dy0;
    const vec3 dt1 = (tex1 - tex0) / dy1;
    const vec3 dt2 = (tex2 - tex1) / dy2;
    const vec4 dc0 = (col2 - col0) / dy0;
    const vec4 dc1 = (col1 - col0) / dy1;
    const vec4 dc2 = (col2 - col1) / dy2;
    float sx = pos0.x, ex = pos0.x + dx1;
    vec3 st = tex0, et = tex0 + dt1;
    vec3 sn = norm0, en = norm0 + dn1;
    vec4 sc = col0, ec = col0 + dc1;
    for(int32_t y = pos0.y; y <= pos2.y; y++)
    {
        drawLine((int32_t)sx, (int32_t)ex, y, st, et, sn, en, sc, ec);
        sx += dx0;
        st += dt0;
        sn += dn0;
        sc += dc0;
        ex += (y < pos1.y) ? dx1 : dx2;
        et += (y < pos1.y) ? dt1 : dt2;
        en += (y < pos1.y) ? dn1 : dn2;
        ec += (y < pos1.y) ? dc1 : dc2;
    }
}

inline void Window::DrawTriangleOutline(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color)
{
    DrawLine(x0, y0, x1, y1, color);
    DrawLine(x0, y0, x2, y2, color);
    DrawLine(x1, y1, x2, y2, color);
}

inline void Window::DrawSprite(Sprite& sprite, Transform<float>& transform, const Rect<float>& src, Horizontal hor, Vertical ver, const vec2& origin)
{
    if(src.size.x == 0.0f || src.size.y == 0.0f) return;
    const vec2 norm = src.size * origin;
    const vec2 inv = src.size * (1.0f - origin);
    vec2 start, end, p;
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
            const vec2 o = transform.Backward(i, j);
            const int32_t u = src.pos.x + (hor == Horizontal::Flip ? inv.w - std::ceil(o.x) : norm.w + std::floor(o.x));
            const int32_t v = src.pos.y + (ver == Vertical::Flip ? inv.h - std::ceil(o.y) : norm.h + std::floor(o.y));
            if(src.Contains(u, v)) SetPixel(i, j, sprite.GetPixel(u, v));
        }
}

inline void Window::DrawSprite(Sprite& sprite, Transform<float>& transform, Horizontal hor, Vertical ver, const vec2& origin)
{
    DrawSprite(sprite, transform, {0.0f, sprite.GetSize()}, hor, ver, origin);
}

inline void Window::DrawSprite(int32_t x, int32_t y, Sprite& sprite, const vec2& scale, Horizontal hor, Vertical ver)
{
    const vec2 sprSize = scale * sprite.GetSize();
    DrawSprite({vec2{(float)x, (float)y} - sprSize * 0.5f, sprSize}, sprite, hor, ver);
}

inline void Window::DrawSprite(int32_t x, int32_t y, const Rect<float>& src, Sprite& sprite, const vec2& scale, Horizontal hor, Vertical ver)
{
    if(src.size.x == 0.0f || src.size.y == 0.0f) return;
    const vec2 sprSize = scale * src.size;
    DrawSprite({vec2{(float)x, (float)y} - sprSize * 0.5f, sprSize}, src, sprite, hor, ver);
}

inline void Window::DrawSprite(const Rect<float>& dst, Sprite& sprite, Horizontal hor, Vertical ver)
{
    DrawSprite(dst, {0.0f, sprite.GetSize()}, sprite, hor, ver);
}

inline void Window::DrawSprite(const Rect<float>& dst, const Rect<float>& src, Sprite& sprite, Horizontal hor, Vertical ver)
{
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || src.size.x == 0.0f || src.size.y == 0.0f) return;    
    const vec2 scale = dst.size / src.size;
    const vec2 p = {hor == Horizontal::Flip ? -1.0f : 1.0f, ver == Vertical::Flip ? -1.0f : 1.0f};
    const vec2 d = {dst.pos.x + (hor == Horizontal::Flip ? dst.size.x : 0.0f), dst.pos.y + (ver == Vertical::Flip ? dst.pos.y : 0.0f)};
    for(float x = 0; x < dst.size.x; x++)
        for(float y = 0; y < dst.size.y; y++)
        {
            const vec2 pos = {x, y};
            const vec2 o = floor(pos / scale);
            SetPixel(d + pos * p, sprite.GetPixel(src.pos.x + o.x, src.pos.y + o.y));
        }
}

inline void Window::DrawCharacter(int32_t x, int32_t y, const char c, const vec2& scale, const Color& color)
{
    DrawCharacter({{(float)x, (float)y}, {CharSize(c, scale.w), scale.h * defFontHeight}}, c, color);
}

inline void Window::DrawText(int32_t x, int32_t y, const std::string& text, const vec2& scale, const Color& color, const vec2& origin)
{
    vec2 pos = {(float)x, (float)y - (defFontHeight + 1.0f) * scale.h * origin.y};
    size_t index = 0, next = text.find_first_of('\n', index);
    auto drawText = [&](const std::string& str)
    {
        const vec2 strSize = StringSize(str, scale);
        pos.x -= strSize.w * origin.x;
        DrawText({pos, strSize}, str, color);
        pos.x = (float)x;
        pos.y += (defFontHeight + 1.0f) * scale.h;
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

inline void Window::DrawCharacter(const Rect<float>& dst, const char c, const Color& color)
{
    static constexpr std::string_view whitespaces = " \n\t\v\0";
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || whitespaces.find(c) != std::string_view::npos) return;
    const vec2 scale = dst.size / defFontSize;
    for(float x = 0; x < dst.size.x; x++)
        for(float y = 0; y < dst.size.y; y++)
        {
            const vec2 pos = {x, y};
            const vec2i o = floor(pos / scale);
            if(defFontData[(int)c - 32][o.y] & (1 << o.x))
                SetPixel(dst.pos + defFontSize * scale - pos, color);
        }
}

inline void Window::DrawRotatedCharacter(int32_t x, int32_t y, const char c, float rotation, const vec2& scale, const Color& color)
{
    static constexpr std::string_view whitespaces = " \n\t\v\0";
    if(whitespaces.find(c) != std::string_view::npos)
        return;
    if(rotation == 0.0f)
    {
        DrawCharacter(x, y, c, scale, color);
        return;
    }
    float ex = 0.0f, ey = 0.0f;
    float sx = 0.0f, sy = 0.0f;
    float px = 0.0f, py = 0.0f;
    auto calcForward = [&](float cx, float cy)
    {
        px = cx * std::cos(rotation) * scale.w - cy * std::sin(rotation) * scale.h;
        py = cx * std::sin(rotation) * scale.w + cy * std::cos(rotation) * scale.h;
        sx = std::min(sx, px); sy = std::min(sy, py);
        ex = std::max(ex, px); ey = std::max(ey, py);
    };
    calcForward(0.0f, 0.0f);
    calcForward(defFontWidth, defFontHeight);
    calcForward(0.0f, defFontHeight);
    calcForward(defFontWidth, 0.0f);
    if (ex < sx) std::swap(ex, sx);
    if (ey < sy) std::swap(ey, sy);
    for (float i = sx; i < ex; ++i)
        for (float j = sy; j < ey; ++j)
        {
            const float ox = defFontWidth - i * std::cos(rotation) / scale.w - j * std::sin(rotation) / scale.h;
            const float oy = defFontHeight - j * std::cos(rotation) / scale.h + i * std::sin(rotation) / scale.w;
            bool canDraw = oy >= 0.0f && oy < defFontHeight && ox >= 0.0f && ox < defFontWidth;
            if(canDraw && defFontData[(int)c - 32][(int)oy] & (1 << (int)ox))
                SetPixel(x + i, y + j, color);
        }
}

inline void Window::DrawRotatedText(int32_t x, int32_t y, const std::string& text, float rotation, const vec2& scale, const Color& color, const vec2& origin)
{
    if(rotation == 0.0f)
    {
        DrawText(x, y, text, scale, color, origin);
        return;
    }
    const float newLineOffset = (defFontHeight + 1.0f) * scale.h;
    vec2 lineStartPos = {(float)x, (float)y};
    size_t index = 0, next = text.find_first_of('\n', index);
    const vec2 vec = {std::cos(rotation), std::sin(rotation)};
    auto drawText = [&](const std::string& str)
    {
        const vec2 o = StringSize(str, scale) * origin;
        vec2 pos = rotate(rotation, lineStartPos, lineStartPos + o) - o;
        for(const char c : str)
        {
            DrawRotatedCharacter(pos, c, rotation, scale, color);
            pos += CharSize(c, scale.w) * vec;
        }
        lineStartPos += newLineOffset * vec.perp();
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

inline void Window::DrawText(const Rect<float>& dst, const std::string& text, const Color& color)
{
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || text.empty()) return;
    const vec2 strSize = StringSize(text, 1.0f);
    const vec2 scale = dst.size / strSize;
    vec2 pos = dst.pos;
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

inline void Window::SetPixel(const vec2i& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

inline const Color Window::GetPixel(const vec2i& pos) const
{
    return GetPixel(pos.x, pos.y);
}

inline bool Window::ClipLine(vec2i& start, vec2i& end)
{
    return ClipLine(start.x, start.y, end.x, end.y);
}

inline void Window::DrawLine(const vec2i& start, const vec2i& end, const Color& color)
{
    DrawLine(start.x, start.y, end.x, end.y, color);
}

inline void Window::DrawRect(const vec2i& pos, const vec2i& size, const Color& color)
{
    DrawRect(pos.x, pos.y, size.w, size.h, color);
}

inline void Window::DrawRectOutline(const vec2i& pos, const vec2i& size, const Color& color)
{
    DrawRectOutline(pos.x, pos.y, size.w, size.h, color);
}

inline void Window::DrawRotatedRectOutline(const vec2i& pos, const vec2i& size, float rotation, const Color& color)
{
    DrawRotatedRectOutline(pos.x, pos.y, size.w, size.h, rotation, color);
}

inline void Window::DrawCircle(const vec2i& center, int32_t radius, const Color& color)
{
    DrawCircle(center.x, center.y, radius, color);
}

inline void Window::DrawCircleOutline(const vec2i& center, int32_t radius, const Color& color)
{
    DrawCircleOutline(center.x, center.y, radius, color);
}

inline void Window::DrawTriangle(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color)
{
    DrawTriangle(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color);
}

inline void Window::DrawTriangleOutline(const vec2i& pos0, const vec2i& pos1, const vec2i& pos2, const Color& color)
{
    DrawTriangleOutline(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color);
}

inline void Window::DrawSprite(const vec2i& pos, Sprite& sprite, const vec2& scale, Horizontal hor, Vertical ver)
{
    DrawSprite(pos.x, pos.y, sprite, scale, hor, ver);
}

inline void Window::DrawSprite(const vec2i& pos, const Rect<float>& src, Sprite& sprite, const vec2& scale, Horizontal hor, Vertical ver)
{
    DrawSprite(pos.x, pos.y, src, sprite, scale, hor, ver);
}

inline void Window::DrawCharacter(const vec2i& pos, const char c, const vec2& scale, const Color& color)
{
    DrawCharacter(pos.x, pos.y, c, scale, color);
}

inline void Window::DrawRotatedCharacter(const vec2i& pos, const char c, float rotation, const vec2& scale, const Color& color)
{
    DrawRotatedCharacter(pos.x, pos.y, c, rotation, scale, color);
}

inline void Window::DrawRotatedText(const vec2i& pos, const std::string& text, float rotation, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawRotatedText(pos.x, pos.y, text, rotation, scale, color, origin);
}

inline void Window::DrawText(const vec2i& pos, const std::string& text, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawText(pos.x, pos.y, text, scale, color, origin);
}

inline void Window::DrawMesh(Mesh& mesh, bool lighting, bool wireframe)
{
    if(mesh.indexCount == 0)
        return;
    SetShader(lighting ? 3 : 4);
    Shader& shader = vecShaders[currShader];
    shader.SetUniformMat("meshModelMat", mesh.transform.GetModelMat());
    if(!lighting)
    {
        for(int i = 0; i < materialCount; i++)
        {
            const std::string index = '[' + std::to_string(i) +']';
            shader.SetUniformBool("meshHasTexture" + index, mesh.arrMaterials[i].albedoMap);
            shader.SetUniformVec("meshColor" + index, mesh.arrMaterials[i].diffuse);
            shader.SetUniformInt("meshTextureData" + index, i);
            BindTexture(mesh.arrMaterials[i].albedoMap, i);
        }
    }
    else
        for(int i = 0; i < materialCount; i++)
            SetMaterial(shader, "arrMaterials[" + std::to_string(i) + "]", mesh.arrMaterials[i]);
    const int mode = mesh.drawMode;
    const size_t count = mesh.indexCount;
    if(wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    mesh.vao.Bind();
    if(mesh.drawIndexed)
        glDrawElements(mode, count, GL_UNSIGNED_SHORT, NULL);
    else
        glDrawArrays(mode, 0, count);
    mesh.vao.Unbind();
    if(wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

inline void Window::DrawSkybox()
{
    if(!skyboxCubeMap)
        return;
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_FALSE);
    SetShader(6);
    skyboxVAO.Bind();
    glDrawArrays(GL_POINTS, 0, 1);
    skyboxVAO.Unbind();
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
}

#endif