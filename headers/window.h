#ifndef WINDOW_H
#define WINDOW_H

inline constexpr f32 defTabSpace = 18;
inline constexpr i32 maxGeoBatchVertices = 256;
inline constexpr i32 maxGeoBatchIndices = 256;
inline constexpr i32 numCharacters = 95;
inline constexpr i32 defTextureSlot = 0;
inline constexpr vec3 defWorldUp = vec3::up();
inline constexpr vec3 defCameraPos = {0.0f, 0.0f, 5.0f};
inline constexpr ivec2 defFontSize = {8, 13};

constexpr u8 defFontData[numCharacters][defFontSize.y] = {
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

inline f32 GetCharSize(char c, f32 size)
{
    if(c == '\t')
        return defTabSpace * size;
    else
        return (defFontSize.x + 1) * size;
}

inline vec2 GetStringSize(const std::string& text, const vec2& scale)
{
    vec2 res = {0.0f, defFontSize.y};
    f32 buffer = 0.0f;
    for(char c : text)
    {
        if(c == '\n')
        {
            res.w = std::max(res.w, buffer);
            res.h += defFontSize.y + 1.0f;
            buffer = 0.0f;
        }
        else
            buffer += GetCharSize(c, scale.w);
    }
    return {std::max(res.w, buffer), res.h * scale.h};
}

struct Color
{
    using T = u8;
    union
    {
        u32 color;
        struct { u8 r, g, b, a; };
        swizzle2(r, g)
        swizzle3(r, g, b)
        swizzle4(r, g, b, a)
    };
    inline constexpr Color() : r(0), g(0), b(0), a(255) {}
    inline constexpr Color(u32 c) : color(reverse_bytes(c)) {}
    inline constexpr Color(const ubvec4& rgba) : rgba(rgba) {}
    inline constexpr Color(const ubvec3& rgb, u8 a) : rgb(rgb) {this->a = a;}
    inline constexpr Color(u8 r, u8 g, u8 b, u8 a) 
    : r(r), g(g), b(b), a(a) {}
    inline constexpr Color(const vec4& lhs) 
    : rgba(clamp<f32, 4>(lhs, 0.0f, 1.0f) * 255) {}
    inline constexpr Color(const Color& lhs) = default;
    inline constexpr Color(Color&& lhs) = default;
    inline constexpr Color& operator=(Color&& lhs) = default;
    inline constexpr Color& operator=(const Color& lhs) = default;
    inline friend constexpr Color operator*(const Color& lhs, const f32 rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb * rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const f32 rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb / rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, const vec4& rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb * rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const vec4& rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb / rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, u8 rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb + rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, u8 rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb - rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, const Color& rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb - rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, const Color& rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb + rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, const Color& rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb * rhs.rgb / 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const Color& rhs)
    {
        return ubvec4{clamp<int, 3>(lhs.rgb / rhs.rgb * 255, 0, 255), lhs.a};
    }
    inline constexpr Color inverse() const
    {
        return ubvec4{255 - rgb, a};
    }
    inline friend constexpr bool operator<(const Color& lhs, const Color& rhs)
    {
        return (lhs.rgb < rhs.rgb && lhs.a <= rhs.a);
    }
    inline friend constexpr bool operator>(const Color& lhs, const Color& rhs)
    {
        return (lhs.rgb > rhs.rgb && lhs.a >= rhs.a);
    }
    inline friend constexpr bool operator==(const Color& lhs, const Color& rhs)
    {
        return lhs.color == rhs.color;
    }
    inline friend constexpr bool operator!=(const Color& lhs, const Color& rhs)
    {
        return lhs.color != rhs.color;
    }
    inline friend constexpr Color lerp(const Color& lhs, const Color& rhs, double t)
    {
        return ubvec4{clamp<int, 4>(lerp(lhs.rgba, rhs.rgba, t), 0, 255)};
    }
    inline static Color random()
    {
        return ubvec4::random(0, 255);
    }
    inline constexpr operator vec4() const 
    {
        return rgba / 255.0f;
    }
    inline friend constexpr Color operator/=(Color& lhs, f32 rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb / rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, f32 rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb * rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator/=(Color& lhs, const vec4& rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb / rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, const vec4& rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb * rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator+=(Color& lhs, u8 rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb + rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator-=(Color& lhs, u8 rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb - rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator+=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb + rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator-=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb - rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator*=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb * rhs.rgb / 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color operator/=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = clamp<int, 3>(lhs.rgb / rhs.rgb * 255, 0, 255);
        return lhs;
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        os << static_cast<ivec4>(color.rgba);
        return os;
    }
    inline friend std::istream& operator>>(std::istream& is, Color& color)
    {
        is >> color.rgba;
        return is;
    }
};

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

inline void CreateCubeMap(u32& id, const std::array<std::string, 6>& faces)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);
    for(usize i = 0; i < faces.size(); i++)
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

inline vec2 ScreenToWorldSize(vec2 size, vec2 scrSize)
{
    return {
        size.w * 2.0f / scrSize.w,
        size.h * 2.0f / scrSize.h
    };
}

inline ivec2 WorldToScreenSize(vec2 size, vec2 scrSize)
{
    return {
        size.w * scrSize.w * 0.5f,
        size.h * scrSize.h * 0.5f
    };
}

inline vec2 ScreenToWorldPos(vec2 pos, vec2 scrSize)
{
    return {
        pos.x * 2.0f / scrSize.w - 1.0f,
        -pos.y * 2.0f / scrSize.h + 1.0f
    };
}

inline ivec2 WorldToScreenPos(vec2 pos, vec2 scrSize)
{
    return {
        (pos.x + 1.0f) * scrSize.w * 0.5f,
        (-pos.y + 1.0f) * scrSize.h * 0.5f
    };
}

struct Window;

struct Framebuffer
{
    u32 id, rbo;
    std::vector<u32> renderTargets;
    i32 width = 0, height = 0;
    inline Framebuffer() = default;
    void Build(const std::vector<GLenum>& attachments);
    Framebuffer(const GLenum& attachment, i32 width, i32 height);
    Framebuffer(const std::vector<GLenum>& attachments, i32 width, i32 height);
    void Bind();
};

struct BaseCamera
{
    virtual void Update(Window* window) = 0;
    virtual void UpdateInternal() = 0;
    virtual void Reset() = 0;
};

struct PerspCamera : BaseCamera
{
    vec3 pos, up, forward, right, dir;
    mat4 proj, view;
    f32 sensitivity = 2.5f;
    f32 speed = 5.0f;
    f32 near, far, fov;
    Frustum<f32> m_frustum;
    std::function<void(PerspCamera&, Window*)> m_funcUpdate = nullptr;
    inline PerspCamera(const PerspCamera& lhs) = default;
    inline PerspCamera() = default;
    PerspCamera(Window* window, f32 near = 0.1f, f32 far = 100.0f, f32 fov = 60.0f);
    void Reset() override;
    void Update(Window* window) override;
    void UpdateInternal() override;
};

struct OrthoCamera : BaseCamera
{
    vec3 pos;
    mat4 proj, view;
    f32 near, far;
    Frustum<f32> m_frustum;
    std::function<void(OrthoCamera&, Window*)> m_funcUpdate = nullptr;
    OrthoCamera(Window* window, f32 near = 0.1f, f32 far = 100.0f);
    inline OrthoCamera() = default;
    void Reset() override;
    void Update(Window* window) override;
    void UpdateInternal() override;
};

class CameraManager
{
//TODO
private:
    std::unordered_map<key_type, BaseCamera*> m_mapCameras;
    OrthoCamera* m_currOrthoCam = nullptr;
    PerspCamera* m_currPerspCam = nullptr;
    Window* m_windowHandle = nullptr;
public:
    inline void Update()
    {
        if(!m_windowHandle) 
            return;
        if(m_currOrthoCam)
            m_currOrthoCam->Update(m_windowHandle);
        if(m_currPerspCam)
            m_currPerspCam->Update(m_windowHandle);
    }
    inline void AddCamera(BaseCamera* cam)
    {
        m_mapCameras[m_mapCameras.size()] = cam;
    }
    inline void AddCamera(const key_type& key, BaseCamera* cam)
    {
        m_mapCameras[key] = cam;
    }
    inline void SetCamera(const key_type& key)
    {
        if(m_mapCameras.count(key))
        {
            PerspCamera* cam = dynamic_cast<PerspCamera*>(m_mapCameras.at(key));
            if(cam != nullptr)
                m_currPerspCam = cam;
            else
                m_currOrthoCam = dynamic_cast<OrthoCamera*>(m_mapCameras.at(key));
        }
    }
};

struct default_vertex
{
    vec4 position;
    vec2 texcoord;
};

struct Sprite;

struct Decal
{
    u32 id = 0;
    i32 width = 0, height = 0;
    inline Decal() = default;
    Decal(Sprite& spr);
    Decal(const std::string& path);
    void Update(Sprite& spr);
    const ivec2 GetSize() const;
    void Resize(i32 w, i32 h);
    void Scale(f32 sx, f32 sy);
    void Resize(const ivec2& size);
    void Scale(const vec2& scale);
    const Rect<i32> GetRect() const;
    f32 GetAspectRatio() const;
    virtual ~Decal() {}
};

enum class DrawMode
{
    Normal,
    Clamp,
    Periodic
};

enum class PixelMode
{
    Normal,
    Mask,
    Alpha,
    Custom
};

enum Flip
{
    None = 0,
    Horizontal = 1,
    Vertical = 2
};

enum class Key
{
    Pressed,
    Held,
    Released,
    None
};

struct Sprite
{
    DrawMode drawMode = DrawMode::Normal;
    i32 width = 0, height = 0;
    std::vector<Color> data;
    inline Sprite() = default;
    Sprite(i32 w, i32 h);
    Sprite(const std::string& path);
    Sprite(Decal& decal);
    void SetPixel(i32 x, i32 y, const Color& color);
    void SetPixel(const ivec2& pos, const Color& color);
    const Color GetPixel(i32 x, i32 y) const;
    const Color GetPixel(const ivec2& pos) const;
    const Color Sample(f32 x, f32 y) const;
    const Color Sample(const vec2& pos) const;
    const Rect<i32> GetRect() const;
    void Clear(const Color& color);
    void Resize(i32 w, i32 h);
    void Scale(f32 sx, f32 sy);
    void Resize(const ivec2& size);
    void Scale(const vec2& scale);
    void Tint(const Color& color);
    void Blur(i32 radius);
    const ivec2 GetSize() const;
    f32 GetAspectRatio() const;
    virtual ~Sprite() {}
};

struct Layer : public Sprite
{
    u32 id;
    bool camEnabled = false;
    inline Layer() = default;
    Layer(i32 width, i32 height);
};

struct Timer
{
    time_point m_now;
    f32 m_delta;
    Timer();
    void Update();
};

enum class Pass
{
    Pass2D,
    Pass3D
};

enum class PostProcMode
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
    void Start(i32 width, i32 height, const char* name);
    void Clear(const Color& color);
    void DrawLayers();
    void EnableStencil(bool enable);
    void EnableDepth(bool enable);
    const i32 GetWidth() const;
    const i32 GetHeight() const;
    const dvec2 GetMousePos() const;
    const ivec2 GetScreenSize() const;
    const vec2 GetMouseDelta() const;
    f32 GetAspectRatio() const;
    const Rect<i32>& GetViewport() const;
    f32 GetDeltaTime() const;
    Key GetKey(int key);
    Key GetMouseButton(int button);
    const DrawMode GetDrawMode() const;
    void SetDrawMode(DrawMode drawMode);
    Layer& GetLayer(const usize& index);
    void SetCurrentLayer(const usize& index);
    void CreateFBO(const GLenum& attachment);
    void CreateFBO(const std::vector<GLenum>& attachments);
    void BindFBO(const usize& index);
    void UnbindFBO();
    void CreateLayer(i32 width = 0, i32 height = 0);
    void SetShader(const key_type& key);
    Shader& GetShader(const key_type& key);
    void SetPerspCam(const usize& index);
    void SetOrthoCam(const usize& index);
    PerspCamera& GetPerspCam();
    OrthoCamera& GetOrthoCam();
    Frustum<f32>& GetFrustum(const Pass& p);
    void SetPixelMode(const PixelMode& mode);
    const PixelMode& GetPixelMode() const;
    void SetPostProcessMode(const PostProcMode& mode);
    const PostProcMode& GetPostProcessMode() const;
    void SetPixel(i32 x, i32 y, const Color& color);
    void SetAntiAliasedPixel(i32 x, i32 y, const Color& color);
    const Color GetPixel(i32 x, i32 y) const;
    f32 CalculateSpotLight(int index, const vec3& view, const vec3& norm) const;
    f32 CalculatePointLight(int index, const vec3& view, const vec3& norm) const;
    f32 CalculateDirectionalLight(int index, const vec3& view, const vec3& norm) const;
    int ClipTriangle(const Plane<f32>& plane, Triangle& in, Triangle& out0, Triangle& out1);
    void RasterizeTriangle(const Sprite& sprite, const Triangle& triangle, const mat4& world = mat4::identity());
    bool ClipLine(i32& sx, i32& sy, i32& ex, i32& ey);
    void DrawLine(i32 sx, i32 sy, i32 ex, i32 ey, const Color& color, f32 width = 1.0f);
    void DrawRect(i32 x, i32 y, i32 w, i32 h, const Color& color);
    void DrawRectOutline(i32 x, i32 y, i32 w, i32 h, const Color& color, f32 angle = 0.0f, f32 width = 1.0f);
    void DrawCircle(i32 cx, i32 cy, i32 radius, const Color& color);
    void DrawCircleOutline(i32 cx, i32 cy, i32 radius, const Color& color);
    void DrawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color);
    void DrawTriangleOutline(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 width = 1.0f);
    void DrawEllipse(i32 xe, i32 ye, i32 rx, i32 ry, const Color& color);
    void DrawEllipseOutline(i32 xe, i32 ye, i32 rx, i32 ry, const Color& color);
    void DrawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 rx, i32 ry, const Color& color);
    void DrawRoundedRectOutline(i32 xe, i32 ye, i32 w, i32 h, i32 rx, i32 ry, const Color& color, f32 width = 1.0f);
    void DrawQuadBezierCurve(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 width = 1.0f);
    void DrawQuadBezierSegment(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 width = 1.0f);
    void DrawQuadRationalBezierCurve(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 weight = 1.0f, f32 width = 1.0f);
    void DrawQuadRationalBezierSegment(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 weight = 1.0f, f32 width = 1.0f);
    void DrawSprite(const Sprite& sprite, Transform<f32>& transform, u8 flip = 0, const vec2& origin = 0.5f, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Rect<i32>& src, u8 flip = 0, const vec2& origin = 0.5f, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(i32 x, i32 y, const Sprite& sprite, const vec2& scale = 1.0f, u8 flip = 0, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(i32 x, i32 y, const Rect<i32>& src, const Sprite& sprite, const vec2& scale = 1.0f, u8 flip = 0, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Rect<i32>& dst, const Rect<i32>& src, const Sprite& sprite, u8 flip = 0, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Rect<i32>& dst, const Sprite& sprite, u8 flip = 0, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawCharacter(i32 x, i32 y, char c, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawRotatedCharacter(i32 x, i32 y, char c, f32 rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawCharacter(const Rect<i32>& dst, char c, const Color& color = {0, 0, 0, 255});
    void DrawText(const Rect<i32>& dst, const std::string& text, const Color& color = {0, 0, 0, 255});
    void DrawRotatedText(i32 x, i32 y, const std::string& text, f32 rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void DrawText(i32 x, i32 y, const std::string& text, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void SetPixel(const ivec2& pos, const Color& color);
    const Color GetPixel(const ivec2& pos) const;
    bool ClipLine(ivec2& start, ivec2& end);
    void DrawLine(const ivec2& start, const ivec2& end, const Color& color, f32 width = 1.0f);
    void DrawRect(const ivec2& pos, const ivec2& size, const Color& color);
    void DrawRectOutline(const ivec2& pos, const ivec2& size, const Color& color, f32 angle = 0.0f, f32 width = 1.0f);
    void DrawCircle(const ivec2& center, i32 radius, const Color& color);
    void DrawCircleOutline(const ivec2& center, i32 radius, const Color& color);
    void DrawEllipse(const ivec2& center, const ivec2& size, const Color& color);
    void DrawEllipseOutline(const ivec2& center, const ivec2& size, const Color& color);
    void DrawQuadBezierCurve(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 width = 1.0f);
    void DrawQuadBezierSegment(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 width = 1.0f);
    void DrawQuadRationalBezierCurve(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 weight = 1.0f, f32 width = 1.0f);
    void DrawQuadRationalBezierSegment(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 weight = 1.0f, f32 width = 1.0f);
    void DrawTriangle(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color);
    void DrawTriangleOutline(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 width = 1.0f);
    void DrawSprite(const ivec2& pos, const Sprite& sprite, const vec2& scale = 1.0f, u8 flip = 0, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const ivec2& pos, const Rect<i32>& src, const Sprite& sprite, const vec2& scale = 1.0f, u8 flip = 0, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawCharacter(const ivec2& pos, char c, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawRotatedCharacter(const ivec2& pos, char c, f32 rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255});
    void DrawRotatedText(const ivec2& pos, const std::string& text, f32 rotation, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void DrawText(const ivec2& pos, const std::string& text, const vec2& scale = 1.0f, const Color& color = {0, 0, 0, 255}, const vec2& origin = 0.0f);
    void DrawMesh(Mesh& mesh);
    inline GLFWwindow* GetHandle() {return handle;}
    void DrawTexturedTriangle(const Sprite& sprite,
        ivec2 pos0, vec3 norm0, vec3 tex0, vec4 col0,
        ivec2 pos1, vec3 norm1, vec3 tex1, vec4 col1,
        ivec2 pos2, vec3 norm2, vec3 tex2, vec4 col2);
    virtual void UserStart() = 0;
    virtual void UserUpdate() = 0;
    void DrawSkybox();
    virtual ~Window()
    {
        delete[] m_depthBuffer;
        glfwDestroyWindow(handle);
        glfwTerminate();
    }
protected:
    std::function<bool(i32,i32,const Color&)> m_funcDrawPixel = nullptr;
    Rect<i32> m_viewport;
    std::unordered_map<int, Key> m_mapKeyboardInput;
    std::unordered_map<int, Key> m_mapMouseInput;
    PixelMode pixelMode = PixelMode::Normal;
    std::vector<Layer> m_vecDrawTargets;
    usize m_drawTarget = 0;
    GLFWwindow* handle;
    std::vector<PerspCamera> vecPerspCameras;
    std::vector<OrthoCamera> vecOrthoCameras;
    usize currPerspCamera = 0, currOrthoCamera = 0;
    std::array<PointLight, pointLightCount> m_pointLights;
    std::array<DirectionalLight, dirLightCount> m_dirLights;
    std::array<SpotLight, spotLightCount> m_spotLights;
    vec2 currMousePos, prevMousePos;
    std::vector<Framebuffer> m_vecFramebuffers;
    Buffer<default_vertex, GL_ARRAY_BUFFER> m_quadVBO;
    PostProcMode m_postProcMode = PostProcMode::None;
    ShaderManager shaderManager;
    u32 m_skyboxCubeMap = 0;
    f32* m_depthBuffer;
    VAO m_quadVAO;
    VAO m_skyboxVAO;
    Timer timer;
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
    const usize size = attachments.size();
    renderTargets.resize(size);
    for(usize i = 0; i < size; i++)
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

inline Framebuffer::Framebuffer(const std::vector<GLenum>& attachments, i32 width, i32 height) : width(width), height(height)
{
    Build(attachments);
}

inline Framebuffer::Framebuffer(const GLenum& attachment, i32 width, i32 height) : width(width), height(height)
{
    Build({attachment});
}

inline void Framebuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, id);
}

inline Sprite::Sprite(i32 w, i32 h) : width(w), height(h)
{
    data.resize(width * height);
}

inline Sprite::Sprite(const std::string& path)
{
    int channels;
    u8 *bytes = stbi_load(path.c_str(), &width, &height, &channels, 4);
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

inline void Sprite::SetPixel(i32 x, i32 y, const Color& color)
{
    if(!data.empty() && x >= 0 && x < width && y >= 0 && y < height)
        data[width * y + x] = color;
}

inline const Color Sprite::GetPixel(i32 x, i32 y) const
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
            x = std::abs(x % width);
            y = std::abs(y % height);
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

inline const Color Sprite::Sample(f32 x, f32 y) const
{
    return GetPixel(std::max<i32>(0, x * width), std::max<i32>(0, y * height));
}

inline void Sprite::SetPixel(const ivec2& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

inline const Color Sprite::GetPixel(const ivec2& pos) const
{
    return GetPixel(pos.x, pos.y);
}

inline const Color Sprite::Sample(const vec2& pos) const
{
    return Sample(pos.x, pos.y);
}

inline void Sprite::Scale(f32 sx, f32 sy)
{
    if(sx < 0.0f || sy < 0.0f || width * height <= 0) return;
    const f32 w = width * sx;
    const f32 h = height * sy;
    Sprite res = Sprite(w, h);
    for(f32 x = 0; x < w; x++)
        for(f32 y = 0; y < h; y++)
        {
            i32 ox = std::floor(x / sx);
            i32 oy = std::floor(y / sy);
            res.SetPixel((i32)(x), (i32)(y), GetPixel(ox, oy));
        }
    *this = res;
}

inline void Sprite::Resize(i32 w, i32 h)
{
    Scale((f32)w / width, (f32)h / height);
}

inline void Sprite::Clear(const Color& color)
{
    for(Color& c : data) c = color;
}

inline void Sprite::Tint(const Color& color)
{
    for(int i = 0; i < width * height; i++)
        if(data[i].a != 0)
            data[i] *= color;
}

inline void Sprite::Blur(i32 radius)
{
    //TODO: Fix it
    Color buffer[radius];
    for (i32 x = 0; x < width; ++x)
    {
        usvec4 diff = 0, sum = 0;
        for (i32 y = -2 * radius; y < height; ++y)
        {
            sum += diff;
            diff += GetPixel(x, y + radius).rgba;
            if (y >= 0)
            {
                diff += buffer[y % radius].rgba;
                SetPixel(x, y, (ubvec4)(sum / (radius * radius)));
            }
            if (y + radius >= 0)
            {
                const Color c = GetPixel(x, y);
                buffer[y % radius] = c;
                diff -= 2 * c.rgba;
            }
        }
    }
    for (i32 y = 0; y < height; ++y)
    {
        usvec4 diff = 0, sum = 0;
        for (i32 x = -2 * radius; x < width; ++x)
        {
            sum += diff;
            diff += GetPixel(x + radius, y).rgba;
            if (x >= 0)
            {
                diff += buffer[x % radius].rgba;
                SetPixel(x, y, (ubvec4)(sum / (radius * radius)));
            }
            if (x + radius >= 0)
            {
                const Color c = GetPixel(x, y);
                buffer[x % radius] = c;
                diff -= 2 * c.rgba;
            }
        }
    }
}

inline const ivec2 Sprite::GetSize() const
{
    return {width, height};
}

inline f32 Sprite::GetAspectRatio() const
{
    return (f32)width / height;
}

inline const Rect<i32> Sprite::GetRect() const
{
    return {0, this->GetSize()};
}

inline void Sprite::Resize(const ivec2& size)
{
    Resize(size.x, size.y);
}

inline void Sprite::Scale(const vec2& scale)
{
    Scale(scale.x, scale.y);
}

inline Timer::Timer()
{
    m_now = steady_clock::now();
}

inline void Timer::Update()
{
    m_delta = std::chrono::duration<f32>(steady_clock::now() - m_now).count();
    m_now = steady_clock::now();
}

inline Layer::Layer(i32 width, i32 height)
{
    this->width = width;
    this->height = height;
    this->data.resize(width * height);
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

inline const ivec2 Decal::GetSize() const
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

inline void Decal::Resize(i32 w, i32 h)
{
    Sprite spr = *this;
    spr.Resize(w, h);
    *this = spr;
}

inline void Decal::Scale(f32 sx, f32 sy)
{
    this->Resize(width * sx, height * sy);
}

inline void Decal::Resize(const ivec2& size)
{
    Resize(size.x, size.y);
}

inline void Decal::Scale(const vec2& scale)
{
    Scale(scale.x, scale.y);
}

inline const Rect<i32> Decal::GetRect() const
{
    return {0, this->GetSize()};
}

inline f32 Decal::GetAspectRatio() const
{
    return (f32)width / height;
}

inline PerspCamera::PerspCamera(Window* window, f32 near, f32 far, f32 fov) 
: far(far), near(near), fov(fov)
{
    proj = make_perspective_mat(window->GetAspectRatio(), fov, near, far);
    this->Reset();
}

inline void PerspCamera::Reset()
{
    dir = {0.0f, 0.0f, -pi<f32> * 0.5f};
    pos = defCameraPos;
    UpdateInternal();
}

inline void PerspCamera::Update(Window* window)
{
    if(m_funcUpdate != nullptr)
    {
        m_funcUpdate(*this, window);
        UpdateInternal();
    }
}

inline void PerspCamera::UpdateInternal()
{
    forward = vec3
    {
        std::cos(dir.yaw) * std::cos(dir.pitch), 
        std::sin(dir.pitch), 
        std::sin(dir.yaw) * std::cos(dir.pitch)
    }.norm();
    right = cross(forward, defWorldUp).norm();
    up = cross(right, forward).norm();
    view = mat_look_at(pos, pos + forward, up);
    m_frustum.SetMatrix(proj * view);
}

inline OrthoCamera::OrthoCamera(Window* window, f32 near, f32 far)
: near(near), far(far)
{
    proj = make_ortho_mat(1.0f, -1.0f, -1.0f, 1.0f, near, far);
    this->Reset();
}

inline void OrthoCamera::Update(Window* window)
{
    if(m_funcUpdate != nullptr)
    {
        m_funcUpdate(*this, window);
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
    view = translation_mat_3d<f32>({pos.xy, -defCameraPos.z});
    m_frustum.SetMatrix(proj * view);
}

inline void Window::SetPixelMode(const PixelMode& mode)
{
    if(pixelMode != mode)
        pixelMode = mode;
}

inline const PixelMode& Window::GetPixelMode() const
{
    return pixelMode;
}

inline void Window::SetPostProcessMode(const PostProcMode& mode)
{
    if(m_postProcMode != mode)
        m_postProcMode = mode;
}
const PostProcMode& Window::GetPostProcessMode() const
{
    return m_postProcMode;
}

void Window::Start(i32 width, i32 height, const char* name)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    handle = glfwCreateWindow(width, height, name, nullptr, nullptr);
    glfwMakeContextCurrent(handle);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return;
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    EnableDepth(true);
    CreateLayer(width, height);
    SetCurrentLayer(0);
    m_viewport = {0, {width, height}};
    vecPerspCameras.emplace_back(this);
    vecOrthoCameras.emplace_back(this);
    m_depthBuffer = new f32[width * height];
    memset(m_depthBuffer, 0, 4 * width * height);
    vecPerspCameras[0].m_funcUpdate = [this](PerspCamera& cam, Window* window)
    {
        const vec2 offset = window->GetMouseDelta() * cam.sensitivity * GetDeltaTime();
        cam.dir.pitch = std::clamp(cam.dir.pitch - offset.y, -half_pi<f32>, half_pi<f32>); 
        cam.dir.yaw += offset.x;
        if(window->GetKey(GLFW_KEY_UP) == Key::Held)
            cam.pos += cam.forward * cam.speed * GetDeltaTime();
        if(window->GetKey(GLFW_KEY_DOWN) == Key::Held)
            cam.pos -= cam.forward * cam.speed * GetDeltaTime();
        if(window->GetKey(GLFW_KEY_RIGHT) == Key::Held)
            cam.pos += cam.right * cam.speed * GetDeltaTime();
        if(window->GetKey(GLFW_KEY_LEFT) == Key::Held)
            cam.pos -= cam.right * cam.speed * GetDeltaTime();
    };
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res\\shaders\\default.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res\\shaders\\default.frag").c_str())
        })
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res\\shaders\\sprite_batch.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res\\shaders\\sprite_batch.frag").c_str())
        }),
        [&](Shader& instance)
        {
            for(int i = 0; i < sprBatchMaxSprites; i++)
                instance.SetUniformInt("u_buffers[" + std::to_string(i) + "]", &i);
        }
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res\\shaders\\geo_batch.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res\\shaders\\geo_batch.frag").c_str())
        })
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res\\shaders\\lighting.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res\\shaders\\lighting.frag").c_str())
        }),
        [&](Shader& instance)
        {
            for(usize i = 0; i < pointLightCount; i++)
            {
                const PointLight& light = m_pointLights[i];
                const std::string prefix = "u_pointLights[" + std::to_string(i) + "]";
                instance.SetUniformBool(prefix + ".Enabled", light.enabled);
                instance.SetUniformVector(prefix + ".Position", light.position);
                instance.SetUniformVector(prefix + ".Color", light.color);
                instance.SetUniformFloat(prefix + ".Constant", &light.constant);
                instance.SetUniformFloat(prefix + ".Linear", &light.linear);
                instance.SetUniformFloat(prefix + ".Quadratic", &light.quadratic);
            }
            for(usize i = 0; i < dirLightCount; i++)
            {
                const DirectionalLight& light = m_dirLights[i];
                const std::string prefix = "u_dirLights[" + std::to_string(i) + "]";
                instance.SetUniformBool(prefix + ".Enabled", light.enabled);
                instance.SetUniformVector(prefix + ".Direction", light.direction);
                instance.SetUniformVector(prefix + ".Color", light.color);
            }
            for(usize i = 0; i < spotLightCount; i++)
            {
                const SpotLight& light = m_spotLights[i];
                const std::string prefix = "u_spotLights[" + std::to_string(i) + "]";
                instance.SetUniformBool(prefix + ".Enabled", light.enabled);
                instance.SetUniformVector(prefix + ".Color", light.color);
                instance.SetUniformFloat(prefix + ".Constant", &light.constant);
                instance.SetUniformFloat(prefix + ".Linear", &light.linear);
                instance.SetUniformFloat(prefix + ".Quadratic", &light.quadratic);
                instance.SetUniformFloat(prefix + ".CutOff", &light.cutOff);
                instance.SetUniformFloat(prefix + ".OuterCutOff", &light.outerCutOff);
                instance.SetUniformVector(prefix + ".Position", light.position);
                instance.SetUniformVector(prefix + ".Direction", light.direction);
            }
        },
        [&](Shader& instance)
        {
            instance.SetUniformMatrix("u_camMatrix", GetPerspCam().m_frustum.GetMatrix());
            instance.SetUniformVector("u_camPos", GetPerspCam().pos);
        }
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res\\shaders\\post_processing.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res\\shaders\\post_processing.frag").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniformInt("u_scrQuad", 0);
            instance.SetUniformInt("u_postProcMode", (int)m_postProcMode);
            BindTexture(m_vecFramebuffers[0].renderTargets[0], 0);
        }
    ));
    shaderManager.AddShader({
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res\\shaders\\cubemap.vert").c_str()),
            CompileShader(GL_GEOMETRY_SHADER, ReadShader("res\\shaders\\cubemap.geom").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res\\shaders\\cubemap.frag").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniformMatrix("u_projection", GetPerspCam().proj);
            instance.SetUniformMatrix("u_view", mat4(mat3(GetPerspCam().view)));
            if(m_skyboxCubeMap)
                glBindTexture(GL_TEXTURE_CUBE_MAP, m_skyboxCubeMap);
        }
    });
    SetShader(0ull);
    currMousePos = prevMousePos = GetMousePos();
    constexpr std::array<default_vertex, 4> vertices = 
    {
        default_vertex{{-1.0f,  1.0f, -0.92192190f, 1.0f}, {0.0f, 0.0f}},
        default_vertex{{-1.0f, -1.0f, -0.92192190f, 1.0f}, {0.0f, 1.0f}},
        default_vertex{{ 1.0f,  1.0f, -0.92192190f, 1.0f}, {1.0f, 0.0f}},
        default_vertex{{ 1.0f, -1.0f, -0.92192190f, 1.0f}, {1.0f, 1.0f}}
    };
    m_quadVAO.Build();
    m_quadVBO.Build(vertices);
    m_quadVBO.AddAttrib(0, 4, offsetof(default_vertex, position));
    m_quadVBO.AddAttrib(1, 2, offsetof(default_vertex, texcoord));
    m_skyboxVAO.Build();
    CreateFBO(GL_COLOR_ATTACHMENT0);
    UserStart();
    while(!glfwWindowShouldClose(handle))
    {
        Begin();
        BindFBO(0);
        UserUpdate();
        DrawLayers();
        UnbindFBO();
        m_quadVAO.Bind();
        SetShader(4ull);
        EnableDepth(false);
        Clear(0);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        m_quadVAO.Unbind();
        EnableDepth(true);
        End();
    }
}

inline f32 Window::GetDeltaTime() const
{
    return timer.m_delta;
}

inline f32 Window::GetAspectRatio() const
{
    return m_vecDrawTargets[m_drawTarget].GetAspectRatio();
}

inline void Window::SetShader(const key_type& key)
{
    shaderManager.SetShader(key);
}

inline Shader& Window::GetShader(const key_type& key)
{
    return shaderManager[key];
}

inline void Window::SetPerspCam(const usize& index)
{
    if(currPerspCamera != index && index < vecPerspCameras.size())
        currPerspCamera = index;
}

inline void Window::SetOrthoCam(const usize& index)
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

inline Frustum<f32>& Window::GetFrustum(const Pass& p)
{
    if(p == Pass::Pass2D)
        return vecOrthoCameras[currOrthoCamera].m_frustum;
    else
        return vecPerspCameras[currPerspCamera].m_frustum;
}

inline Key Window::GetKey(int key)
{
    const int currState = glfwGetKey(handle, key);
    if(!m_mapKeyboardInput.count(key))
        return (m_mapKeyboardInput[key] = currState == GLFW_PRESS ? Key::Pressed : Key::None);
    const Key prevState = m_mapKeyboardInput.at(key);
    bool pressed = (prevState == Key::Pressed || prevState == Key::Held);
    if(currState == GLFW_PRESS)
        m_mapKeyboardInput[key] = pressed ? Key::Held : Key::Pressed;
    else
        m_mapKeyboardInput[key] = pressed ? Key::Released : Key::None;
    return m_mapKeyboardInput[key];
}

inline Key Window::GetMouseButton(int button)
{
    const int currState = glfwGetMouseButton(handle, button);
    if(!m_mapMouseInput.count(button)) 
        return (m_mapMouseInput[button] = currState == GLFW_PRESS ? Key::Pressed : Key::None);
    const Key prevState = m_mapMouseInput.at(button);
    bool pressed = (prevState == Key::Pressed || prevState == Key::Held);
    if(currState == GLFW_PRESS)
        m_mapMouseInput[button] = pressed ? Key::Held : Key::Pressed;
    else
        m_mapMouseInput[button] = pressed ? Key::Released : Key::None;
    return m_mapMouseInput[button];
}

inline void Window::Clear(const Color& color)
{
    int code = GL_COLOR_BUFFER_BIT;
    if(glIsEnabled(GL_DEPTH_TEST)) code |= GL_DEPTH_BUFFER_BIT;
    if(glIsEnabled(GL_STENCIL_TEST)) code |= GL_STENCIL_BUFFER_BIT;
    const vec4 c = color;
    glClearColor(c.r, c.g, c.b, c.a);
    glClear(code);
    cmemset(m_depthBuffer, 0, 4 * GetWidth() * GetHeight());
    m_vecDrawTargets[m_drawTarget].Clear(0);
}

inline void Window::CreateFBO(const GLenum& attachment)
{
    m_vecFramebuffers.emplace_back(attachment, GetWidth(), GetHeight());
}

inline void Window::CreateFBO(const std::vector<GLenum>& attachments)
{
    m_vecFramebuffers.emplace_back(attachments, GetWidth(), GetHeight());
}

inline void Window::BindFBO(const usize& index)
{
    if(index < m_vecFramebuffers.size())
        m_vecFramebuffers[index].Bind();
}

inline void Window::UnbindFBO()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

inline void Window::EnableDepth(bool enable)
{
    if(enable)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
}

inline void Window::EnableStencil(bool enable)
{
    if(enable)
        glEnable(GL_STENCIL_TEST);
    else
        glDisable(GL_STENCIL_TEST);
}

inline void Window::Begin()
{
    timer.Update();
    for(auto& cam : vecPerspCameras) cam.Update(this);
    for(auto& cam : vecOrthoCameras) cam.Update(this);
    shaderManager.UpdateShader();
    prevMousePos = currMousePos;
    currMousePos = GetMousePos();
}

inline void Window::DrawLayers()
{
    SetShader(0ull);
    m_quadVAO.Bind();
    for(auto& drawTarget : m_vecDrawTargets)
    {
        UpdateTexture(
            drawTarget.id,
            drawTarget.width,
            drawTarget.height,
            drawTarget.data.data()
        );
        BindTexture(drawTarget.id);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    BindTexture(0);
    m_quadVAO.Unbind();
}

inline void Window::End()
{
    glfwSwapBuffers(handle);
    glfwPollEvents();
}

inline void Window::CreateLayer(i32 width, i32 height)
{
    if(width == 0 || height == 0) {width = GetWidth(); height = GetHeight();}
    m_vecDrawTargets.emplace_back(width, height);
}

inline void Window::SetCurrentLayer(const usize& index)
{
    if(m_drawTarget != index && index < m_vecDrawTargets.size())
        m_drawTarget = index;
}

inline Layer& Window::GetLayer(const usize& index)
{
    return m_vecDrawTargets[index];
}

inline const i32 Window::GetWidth() const
{
    return m_vecDrawTargets[m_drawTarget].width;
}

inline const i32 Window::GetHeight() const
{
    return m_vecDrawTargets[m_drawTarget].height;
}

inline const vec2 Window::GetMouseDelta() const
{
    return currMousePos - prevMousePos;
}

inline const Color Window::GetPixel(i32 x, i32 y) const
{
    return m_vecDrawTargets[m_drawTarget].GetPixel(x, y);
}

inline void Window::SetDrawMode(DrawMode drawMode)
{
    m_vecDrawTargets[m_drawTarget].drawMode = drawMode;
}

inline const DrawMode Window::GetDrawMode() const
{
    return m_vecDrawTargets[m_drawTarget].drawMode;
}

inline const dvec2 Window::GetMousePos() const
{
    dvec2 res;
    glfwGetCursorPos(handle, &res.x, &res.y);
    return res;
}

inline const ivec2 Window::GetScreenSize() const
{
    return m_vecDrawTargets[m_drawTarget].GetSize();
}

inline const Rect<i32>& Window::GetViewport() const
{
    return m_viewport;
}

inline void Window::SetPixel(i32 x, i32 y, const Color& color)
{
    Layer& layer = m_vecDrawTargets[m_drawTarget];
    auto setPixel = [this, &layer, x, y, color]() -> void
    {
        if(!layer.camEnabled)
        {
            layer.SetPixel(x, y, color);
            return; 
        }
        vec4 pos = {x, y, 0.0f, 1.0f};
        const vec2 scrSize = this->GetScreenSize();
        pos.xy = ScreenToWorldPos(pos.xy, scrSize);
        pos = this->GetOrthoCam().m_frustum.GetMatrix() * pos;
        pos.xy = WorldToScreenPos(pos.xy / (pos.w != 0.0f ? pos.w : 1.0f), scrSize);
        layer.SetPixel(pos.x, pos.y, color);
    };
    switch(pixelMode)
    {
        case PixelMode::Mask:
            if(color.a == 255)
                setPixel();
        break;
        case PixelMode::Alpha:
            if(color.a != 0)
                setPixel();
        break;
        case PixelMode::Normal:
            setPixel();
        break;
        case PixelMode::Custom:
            if(m_funcDrawPixel && m_funcDrawPixel(x,y,color))
                setPixel();
        break;
    }
}

inline void Window::SetAntiAliasedPixel(i32 x, i32 y, const Color& color)
{
    const Color c = {color.rgb, (u8)(255 - color.a)};
    if(GetPixel(x, y).a <= c.a)
        SetPixel(x, y, c);
}

inline bool Window::ClipLine(i32& sx, i32& sy, i32& ex, i32& ey)
{
    static constexpr int regInside = 0, regLeft = 1, regRight = 2, regBottom = 4, regTop = 8;
    const i32 w = GetWidth();
    const i32 h = GetHeight();
    auto regCode = [&](i32 x, i32 y) -> int
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
            if(code & regTop) {x = sx + (ex - sx) * (h - sy) / (ey - sy); y = h;}
            else if(code & regBottom) {x = sx + (sx - ex) * (sy) / (ey - sy); y = 0;}
            else if(code & regRight) {y = sy + (ey - sy) * (w - sx) / (ex - sx); x = w;}
            else if(code & regLeft) {y = sy + (sy - ey) * (sx) / (ex - sx); x = 0;}
            if(code == sc) {sx = x; sy = y; sc = regCode(sx, sy);}
            else {ex = x; ey = y; ec = regCode(ex, ey);}
        }
    }
    return true;
}

int Window::ClipTriangle(const Plane<f32>& plane, Triangle& in, Triangle& out0, Triangle& out1)
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
    if(insideCount == 0)
        return 0;
    if(insideCount == 3)
    {
        out0 = in;
        return 1;
    }
    if(insideCount == 1 && outsideCount == 2)
    {
    	f32 t;
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
    if(insideCount == 2 && outsideCount == 1)
    {
    	f32 t;
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

void Window::RasterizeTriangle(const Sprite& sprite, const Triangle& triangle, const mat4& world)
{
    std::list<Triangle> listTriangles;
    const vec2 scrSize = GetScreenSize();
    Triangle temp = triangle;
    temp.pos[0].w = temp.pos[1].w = temp.pos[2].w = 1.0f;
    temp.tex[0].z = temp.tex[1].z = temp.tex[2].z = 1.0f;
    temp.pos[0] = world * temp.pos[0];
    temp.pos[1] = world * temp.pos[1];
    temp.pos[2] = world * temp.pos[2];
    const mat3 inv = mat3(world.inverse().transpose());
    temp.norm[0] = inv * temp.norm[0];
    temp.norm[1] = inv * temp.norm[1];
    temp.norm[2] = inv * temp.norm[2];
    PerspCamera& cam = vecPerspCameras[currPerspCamera];
    Triangle clipped[2];
    listTriangles.push_back(temp);
    int newTris = 1;
    for(int i = 0; i < 6; i++)
    {
    	int trisToAdd = 0;
    	while(newTris > 0)
    	{
            Triangle test = listTriangles.front();
    		listTriangles.pop_front();
    		newTris--;
    		switch (i)
    		{
                case 0: trisToAdd = ClipTriangle(cam.m_frustum.near, test, clipped[0], clipped[1]); break;
                case 1: trisToAdd = ClipTriangle(cam.m_frustum.far, test, clipped[0], clipped[1]); break;
                case 2:	trisToAdd = ClipTriangle(cam.m_frustum.top, test, clipped[0], clipped[1]); break;
                case 3:	trisToAdd = ClipTriangle(cam.m_frustum.bottom, test, clipped[0], clipped[1]); break;
                case 4:	trisToAdd = ClipTriangle(cam.m_frustum.right, test, clipped[0], clipped[1]); break;
                case 5:	trisToAdd = ClipTriangle(cam.m_frustum.left, test, clipped[0], clipped[1]); break;
            }
            for(int j = 0; j < trisToAdd; j++)
            	listTriangles.push_back(clipped[j]);
    	}
        newTris = listTriangles.size();
    }
    for(auto &tri : listTriangles)
    {
        tri.pos[0] = cam.m_frustum.GetMatrix() * tri.pos[0];
        tri.pos[1] = cam.m_frustum.GetMatrix() * tri.pos[1];
        tri.pos[2] = cam.m_frustum.GetMatrix() * tri.pos[2];
        tri.pos[0].xyz /= tri.pos[0].w;
        tri.pos[1].xyz /= tri.pos[1].w;
        tri.pos[2].xyz /= tri.pos[2].w;
        tri.tex[0] /= tri.pos[0].w;
        tri.tex[1] /= tri.pos[1].w;
        tri.tex[2] /= tri.pos[2].w;
        tri.norm[0] /= tri.pos[0].w;
        tri.norm[1] /= tri.pos[1].w;
        tri.norm[2] /= tri.pos[2].w;
        tri.pos[0].xy = WorldToScreenPos(tri.pos[0].xy, scrSize);
        tri.pos[1].xy = WorldToScreenPos(tri.pos[1].xy, scrSize);
        tri.pos[2].xy = WorldToScreenPos(tri.pos[2].xy, scrSize);
        DrawTexturedTriangle(sprite,
            tri.pos[0].xy, tri.norm[0], tri.tex[0], tri.col[0],
            tri.pos[1].xy, tri.norm[1], tri.tex[1], tri.col[1],
            tri.pos[2].xy, tri.norm[2], tri.tex[2], tri.col[2]);
    }
}

void Window::DrawLine(i32 sx, i32 sy, i32 ex, i32 ey, const Color& color, f32 width)
{
    if(!ClipLine(sx, sy, ex, ey) || width <= 0.0f) return;
    i32 dx = std::abs(ex - sx), px = sx < ex ? 1 : -1;
    i32 dy = std::abs(ey - sy), py = sy < ey ? 1 : -1;
    i32 err;
    f32 e = hypot<f32>(dx, dy);
    width = 255 * (width - 1);
    dx *= 255 / e;
    dy *= 255 / e;
    if(dx < dy)
    {
        ex = std::round((e + width * 0.5f) / dy);
        err = ex * dy - width * 0.5f;
        for(sx -= ex * px; ; sy += py)
        {
            SetAntiAliasedPixel(ex = sx, sy, {color.rgb, (u8)err});
            for(e = dy - err - width; e + dy < 255; e += dy)  
                SetPixel(ex += px, sy, color);
            SetAntiAliasedPixel(ex + px, sy, {color.rgb, (u8)e});
            if(sy == ey) break;
            err += dx;
            if(err > 255)
            {
                err -= dy;
                sx += px;
            }
        }
    }
    else
    {
        ey = std::round((e + width * 0.5f) / dx);
        err = ey * dx - width * 0.5f;
        for(sy -= ey * py; ; sx += px)
        {
            SetAntiAliasedPixel(sx, ey = sy, {color.rgb, (u8)err});
            for(e = dx - err - width; e + dx < 255; e += dx)
                SetPixel(sx, ey += py, color);
            SetAntiAliasedPixel(sx, ey + py, {color.rgb, (u8)e});
            if(sx == ex) break;
            err += dy;
            if(err > 255)
            {
                err -= dx;
                sy += py;
            }
        } 
    }
}

inline void Window::DrawRect(i32 x, i32 y, i32 w, i32 h, const Color& color)
{
    w = std::clamp(w, 0, GetWidth());
    h = std::clamp(h, 0, GetHeight());
    for(i32 i = x; i <= x + w; i++)
        for(i32 j = y; j <= y + h; j++)
            SetPixel(i, j, color);
}

inline void Window::DrawRectOutline(i32 x, i32 y, i32 w, i32 h, const Color& color, f32 angle, f32 width)
{
    if(almost_equal(mod(angle, two_pi<f32>), 0.0f))
    {
        DrawLine(x, y, x, y + h, color, width);
        DrawLine(x, y, x + w, y, color, width);
        DrawLine(x + w, y + h, x, y + h, color, width);
        DrawLine(x + w, y + h, x + w, y, color, width);
        return;
    }
    const vec2 pos0 = rotate<f32>(angle, {0, h});
    const vec2 pos1 = rotate<f32>(angle, {w, 0});
    const vec2 pos2 = rotate<f32>(angle, {w, h});
    DrawLine(x + pos2.x, y + pos2.y, x + pos1.x, y + pos1.y, color, width);
    DrawLine(x + pos2.x, y + pos2.y, x + pos0.x, y + pos0.y, color, width);
    DrawLine(x, y, x + pos1.x, y + pos1.y, color, width);
    DrawLine(x + pos0.x, y + pos0.y, x, y, color, width);
}

inline void Window::DrawCircle(i32 cx, i32 cy, i32 radius, const Color& color)
{
    if(cx + radius > GetWidth() && cx - radius < 0 && cy + radius > GetHeight() && cy - radius < 0) return DrawRect(0, 0, GetWidth(), GetHeight(), color);
    auto drawLine = [this, color](i32 sx, i32 ex, i32 y)
    {
    	for(i32 x = sx; x <= ex; x++) SetPixel(x, y, color);
    };
    i32 x = radius;
    i32 y = 0;
    i32 dx = 1 - radius * 2;
    i32 dy = 0;
    i32 err = 0;
    while(x >= y)
    {
        drawLine(cx - x, cx + x, cy + y);
        drawLine(cx - x, cx + x, cy - y);
        drawLine(cx - y, cx + y, cy + x);
        drawLine(cx - y, cx + y, cy - x);
        y++;
        err += dy;
        dy += 2;
        if(err * 2 + dx > 0)
        {
            x--;
            err += dx;
            dx += 2;
        }
    }
}

inline void Window::DrawCircleOutline(i32 cx, i32 cy, i32 radius, const Color& color)
{
    if(radius < 0 || cx - radius > GetWidth() || cx + radius < 0 || cy - radius > GetHeight() || cy + radius < 0) return;
    auto drawPixels = [&](i32 x, i32 y)
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
    i32 x = 0;
    i32 y = radius;
    i32 d1 = 1 - radius;
    i32 c1 = 3;
    i32 c2 = 5 - 2 * radius;
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

void Window::DrawEllipse(i32 xe, i32 ye, i32 rx, i32 ry, const Color& color)
{
    if(xe + rx > GetWidth() && xe - rx < 0 && ye + ry > GetHeight() && ye - ry < 0) return DrawRect(0, 0, GetWidth(), GetHeight(), color);
    if(rx == ry) return DrawCircle(xe, ye, rx, color);
    auto drawLine = [this, color](i32 sx, i32 ex, i32 y)
    {
        for(i32 x = sx; x <= ex; x++) SetPixel(x, y, color);
    };
    f32 x = 0.0f;
    f32 y = ry;
    const f32 sry = ry * ry;
    const f32 srx = rx * rx;
    f32 p1 = sry - srx * ry + srx * 0.25f;
    f32 dx = 0.0f;
    f32 dy = 2 * y * srx;
    while(dx < dy)
    {
        drawLine(xe - x, xe + x, ye + y);
        drawLine(xe - x, xe + x, ye - y);
        if(p1 < 0.0f)
        {
            x++;
            dx += 2 * sry;
            p1 += dx + sry;
        }
        else
        {
            x++;
            y--;
            dx += 2 * sry;
            dy -= 2 * srx;
            p1 += dx - dy + sry;
        }
    }
    f32 p2 = sry * (x + 0.5f) * (x + 0.5f) + srx * (y - 1.0f) * (y - 1.0f) - srx * sry;
    while(y >= 0.0f)
    {
        drawLine(xe - x, xe + x, ye + y);
        drawLine(xe - x, xe + x, ye - y);
        if(p2 > 0.0f)
        {
            y--;
            dy -= 2 * srx;
            p2 += srx - dy;
        }
        else
        {
            x++;
            y--;
            dy -= 2 * srx;
            dx += 2 * sry;
            p2 += dx - dy + srx;
        }
    }
}

void Window::DrawEllipseOutline(i32 xe, i32 ye, i32 rx, i32 ry, const Color& color)
{
    if(rx < 0 || xe - rx > GetWidth() || xe + rx < 0 || ye - ry > GetHeight() || ye + ry < 0) return;
    if(rx == ry) return DrawCircleOutline(xe, ye, rx, color);
    auto setPixels = [this, color, xe, ye](i32 x, i32 y)
    {
        SetPixel(xe - x, ye - y, color);
        SetPixel(xe + x, ye - y, color);
        SetPixel(xe - x, ye + y, color);
        SetPixel(xe + x, ye + y, color);
    };
    f32 x = 0.0f;
    f32 y = ry;
    const f32 sry = ry * ry;
    const f32 srx = rx * rx;
    f32 p1 = sry - srx * ry + srx * 0.25f;
    f32 dx = 0.0f;
    f32 dy = 2 * y * srx;
    while(dx < dy)
    {
        setPixels(x, y);
        if(p1 < 0.0f)
        {
            x++;
            dx += 2 * sry;
            p1 += dx + sry;
        }
        else
        {
            x++;
            y--;
            dx += 2 * sry;
            dy -= 2 * srx;
            p1 += dx - dy + sry;
        }
    }
    f32 p2 = sry * (x + 0.5f) * (x + 0.5f) + srx * (y - 1.0f) * (y - 1.0f) - srx * sry;
    while(y >= 0.0f)
    {
        setPixels(x, y);
        if(p2 > 0.0f)
        {
            y--;
            dy -= 2 * srx;
            p2 += srx - dy;
        }
        else
        {
            x++;
            y--;
            dy -= 2 * srx;
            dx += 2 * sry;
            p2 += dx - dy + srx;
        }
    }
}

void Window::DrawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 rx, i32 ry, const Color& color)
{
    return;
}

void Window::DrawRoundedRectOutline(i32 xe, i32 ye, i32 w, i32 h, i32 rx, i32 ry, const Color& color, f32 width)
{
    rx = std::clamp(rx, 0, w / 2);
    ry = std::clamp(ry, 0, h / 2);
    //TODO
}

void Window::DrawQuadBezierSegment(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 width)
{
    DrawQuadRationalBezierSegment(x0, y0, x1, y1, x2, y2, color, 1.0f, width);
}

void Window::DrawQuadBezierCurve(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 width)
{
    DrawQuadRationalBezierCurve(x0, y0, x1, y1, x2, y2, color, 1.0f, width);
}

void Window::DrawQuadRationalBezierSegment(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 weight, f32 width)
{
    i32 sx = x2 - x1, sy = y2 - y1;
    i32 dx = x0 - x2, dy = y0 - y2, xx = x0 - x1, yy = y0 - y1;
    f32 xy = xx * sy + yy * sx, curr = xx * sy - yy * sx, err = 0.0f, e = 0.0f, ed = 0.0f;
    bool full_break = false;
    if (curr == 0.0f || weight <= 0.0f) return;
    if (sx * sx + sy * sy > xx * xx + yy * yy)
    {
        x2 = x0;
        x0 -= dx;
        y2 = y0;
        y0 -= dy;
        curr *= -1;
    }
    xx = 2.0f * (4.0f * weight * sx * xx + dx * dx);
    yy = 2.0f * (4.0f * weight * sy * yy + dy * dy);
    sx = x0 < x2 ? 1 : -1;
    sy = y0 < y2 ? 1 : -1;
    xy = -2.0f * sx * sy * (2.0f * weight * xy + dx * dy);
    if (curr * sx * sy < 0)
    {
        xx *= -1;
        yy *= -1;
        xy *= -1;
        curr *= -1;
    }
    dx = 4.0f * weight * (x1 - x0) * sy * curr + xx * 0.5f;
    dy = 4.0f * weight * (y0 - y1) * sx * curr + yy * 0.5f;
    if (weight < 0.5f && (dx + xx <= 0 || dy + yy >= 0))
    {
        curr = (weight + 1.0f) * 0.5f;
        weight = std::sqrt(weight);
        xy = 1.0f / (weight + 1.0f);
        sx = std::round((x0 + 2.0f * weight * x1 + x2) * xy * 0.5f);
        sy = std::round((y0 + 2.0f * weight * y1 + y2) * xy * 0.5f);
        dx = std::round((weight * x1 + x0) * xy);
        dy = std::round((y1 * weight + y0) * xy);
        DrawQuadRationalBezierSegment(x0, y0, dx, dy, sx, sy, color, curr, width);
        dx = std::round((weight * x1 + x2) * xy);
        dy = std::round((y1 * weight + y2) * xy);
        return DrawQuadRationalBezierSegment(sx, sy, dx, dy, x2, y2, color, curr, width);
    }
    for (err = 0; dy + 2 * yy < 0 && dx + 2 * xx > 0;)
        if (dx + dy + xy < 0)
        {
            do
            {
                ed = -dy - 2 * dy * dx * dx / (4.0f * dy * dy + dx * dx);
                weight = (width - 1) * ed;
                x1 = std::floor((err - ed - weight * 0.5f) / dy);
                e = err - x1 * dy - weight * 0.5f;
                x1 = x0 - x1 * sx;
                SetAntiAliasedPixel(x1, y0, {color.rgb, (u8)(255 * e / ed)});
                for (e = -weight - dy - e; e - dy < ed; e -= dy)
                    SetPixel(x1 += sx, y0, color);
                SetAntiAliasedPixel(x1 + sx, y0, {color.rgb, (u8)(255 * e / ed)});
                if (y0 == y2) return;
                y0 += sy;
                dy += xy;
                err += dx;
                dx += xx;
                if (2 * err + dy > 0)
                {
                    x0 += sx;
                    dx += xy;
                    err += dy;
                    dy += yy;
                }
                if (x0 != x2 && (dx + 2 * xx <= 0 || dy + 2 * yy >= 0))
                    if (std::abs(y2 - y0) > std::abs(x2 - x0))
                    {
                        full_break = true;
                        break;
                    }
                    else
                        break;
            } while (dx + dy + xy < 0);
            if (full_break) break;
            for (curr = err - dy - weight * 0.5f, y1 = y0; curr < ed; y1 += sy, curr += dx)
            {
                for (e = curr, x1 = x0; e - dy < ed; e -= dy)
                    SetPixel(x1 -= sx, y1, color);
                SetAntiAliasedPixel(x1 - sx, y1, {color.rgb, (u8)(255 * e / ed)});
            }
        }
        else
        {
            do
            {
                ed = dx + 2 * dx * dy * dy / (4.0f * dx * dx + dy * dy);
                weight = (width - 1) * ed;
                y1 = std::floor((err + ed + weight * 0.5f) / dx);
                e = y1 * dx - weight * 0.5f - err;
                y1 = y0 - y1 * sy;
                SetAntiAliasedPixel(x0, y1, {color.rgb, (u8)(255 * e / ed)});
                for (e = dx - e - weight; e + dx < ed; e += dx)
                    SetPixel(x0, y1 += sy, color);
                SetAntiAliasedPixel(x0, y1 + sy, {color.rgb, (u8)(255 * e / ed)});
                if (x0 == x2) return;
                x0 += sx;
                dx += xy;
                err += dy;
                dy += yy;
                if (2 * err + dx < 0)
                {
                    y0 += sy;
                    dy += xy;
                    err += dx;
                    dx += xx;
                }
                if (y0 != y2 && (dx + 2 * xx <= 0 || dy + 2 * yy >= 0))
                    if (std::abs(y2 - y0) <= std::abs(x2 - x0))
                    {
                        full_break = true;
                        break;
                    }
                    else
                        break;
            } while (dx + dy + xy >= 0);
            if (full_break) break;
            for (curr = -err + dx - weight * 0.5f, x1 = x0; curr < ed; x1 += sx, curr -= dy)
            {
                for (e = curr, y1 = y0; e + dx < ed; e += dx)
                    SetPixel(x1, y1 -= sy, color);
                SetAntiAliasedPixel(x1, y1 - sy, {color.rgb, (u8)(255 * e / ed)});
            }
        }
    DrawLine(x0, y0, x2, y2, color, width);
}

void Window::DrawQuadRationalBezierCurve(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 weight, f32 width)
{
    i32 x = x0 - 2 * x1 + x2, y = y0 - 2 * y1 + y2;
    f32 xx = x0 - x1, yy = y0 - y1, ww = 0.0f, t = 0.0f, q = 0.0f;
    if (xx * (x2 - x1) > 0)
    {
        if (yy * (y2 - y1) > 0)
            if (std::abs(xx * y) > std::abs(yy * x))
            {
                x0 = x2;
                x2 = xx + x1;
                y0 = y2;
                y2 = yy + y1;
            }
        if (x0 == x2 || weight == 1.0f)
            t = (x0 - x1) / (f32)x;
        else
        {
            q = std::sqrt(4.0f * weight * weight * (x0 - x1) * (x2 - x1) + (x2 - x0) * (x2 - x0));
            if (x1 < x0) q = -q;
            t = (2.0f * weight * (x0 - x1) - x0 + x2 + q) / (2.0f * (1.0f - weight) * (x2 - x0));
        }
        q = 1.0f / (2.0f * t * (1.0f - t) * (weight - 1.0f) + 1.0f);
        xx = (t * t * (x0 - 2.0f * weight * x1 + x2) + 2.0f * t * (weight * x1 - x0) + x0) * q;
        yy = (t * t * (y0 - 2.0f * weight * y1 + y2) + 2.0f * t * (weight * y1 - y0) + y0) * q;
        ww = t * (weight - 1.0f) + 1.0f;
        ww *= ww * q;
        weight = ((1.0f - t) * (weight - 1.0f) + 1.0f) * std::sqrt(q);
        x = std::round(xx);
        y = std::round(yy);
        yy = (xx - x0) * (y1 - y0) / (x1 - x0) + y0;
        DrawQuadRationalBezierSegment(x0, y0, x, std::round(yy), x, y, color, ww, width);
        yy = (xx - x2) * (y1 - y2) / (x1 - x2) + y2;
        y1 = std::round(yy);
        x0 = x1 = x;
        y0 = y;
    }
    if ((y0 - y1) * (y2 - y1) > 0)
    {
        if (y0 == y2 || weight == 1.0f)
            t = (y0 - y1) / (y0 - 2.0f * y1 + y2);
        else
        {
            q = std::sqrt(4.0f * weight * weight * (y0 - y1) * (y2 - y1) + (y2 - y0) * (y2 - y0));
            if (y1 < y0) q = -q;
            t = (2.0f * weight * (y0 - y1) - y0 + y2 + q) / (2.0f * (1.0f - weight) * (y2 - y0));
        }
        q = 1.0f / (2.0f * t * (1.0f - t) * (weight - 1.0f) + 1.0f);
        xx = (t * t * (x0 - 2.0f * weight * x1 + x2) + 2.0f * t * (weight * x1 - x0) + x0) * q;
        yy = (t * t * (y0 - 2.0f * weight * y1 + y2) + 2.0f * t * (weight * y1 - y0) + y0) * q;
        ww = t * (weight - 1.0f) + 1.0f;
        ww *= ww * q;
        weight = ((1.0f - t) * (weight - 1.0f) + 1.0f) * std::sqrt(q);
        x = std::round(xx);
        y = std::round(yy);
        xx = (x1 - x0) * (yy - y0) / (y1 - y0) + x0;
        DrawQuadRationalBezierSegment(x0, y0, std::round(xx), y, x, y, color, ww, width);
        xx = (x1 - x2) * (yy - y2) / (y1 - y2) + x2;
        x1 = std::round(xx);
        x0 = x;
        y0 = y1 = y;
    }
    DrawQuadRationalBezierSegment(x0, y0, x1, y1, x2, y2, color, weight * weight, width);
}

inline void Window::DrawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color)
{
    auto drawLine = [this, color](i32 sx, i32 ex, i32 y)
    {
        if(sx > ex) std::swap(sx, ex); 
        for(i32 x = sx; x <= ex; x++) SetPixel(x, y, color);
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
    const f32 dx0 = (x2 - x0) / (y2 - y0 + 1.0f);
    const f32 dx1 = (x1 - x0) / (y1 - y0 + 1.0f);
    const f32 dx2 = (x2 - x1) / (y2 - y1 + 1.0f);
    f32 sx = x0;
    f32 ex = x0 + dx1;
    for(i32 y = y0; y <= y2; y++)
    {
        drawLine(sx, ex, y);
        sx += dx0;
        ex += y < y1 ? dx1 : dx2;
    }
}

inline f32 Window::CalculateDirectionalLight(int index, const vec3& view, const vec3& norm) const
{
    const vec3 dir = -m_dirLights[index].direction.norm();
    const f32 diffuse = 0.5f * std::max(dot(norm, dir), 0.0f);
    const vec3 refl = reflect(-dir, norm);
    const f32 specular = 0.8f * std::pow(std::max(dot(view, refl), 0.0f), 32.0f);
    return 0.1f + diffuse + specular;
}

inline f32 Window::CalculatePointLight(int index, const vec3& view, const vec3& norm) const
{
    //TODO
    return 0.0f;
}

inline f32 Window::CalculateSpotLight(int index, const vec3& view, const vec3& norm) const
{
    //TODO
    return 0.0f;
}

void Window::DrawTexturedTriangle(const Sprite& sprite,
    ivec2 pos0, vec3 norm0, vec3 tex0, vec4 col0,
    ivec2 pos1, vec3 norm1, vec3 tex1, vec4 col1,
    ivec2 pos2, vec3 norm2, vec3 tex2, vec4 col2)
{
    //TODO: Implement shader-like lighting
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
    Layer& buffer = m_vecDrawTargets[m_drawTarget];
    const vec2 sprSize = sprite.GetSize();
    const i32 width = GetWidth();
    auto drawLine = [&](i32 sx, i32 ex, i32 y, vec3 st, vec3 et, vec3 sn, vec3 en, vec4 sc, vec4 ec)
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
        for(i32 x = sx; x <= ex; x++)
    	{
            tex = lerp(st, et, t);
            norm = lerp(sn, en, t);
            if(m_depthBuffer[y * width + x] < tex.z)
            {
                buffer.SetPixel(x, y, sprite.GetPixel(sprSize * tex.xy / tex.z) * lerp(sc, ec, t));
                m_depthBuffer[y * width + x] = tex.z;
            }
            t += dt;
    	}
    };
    const f32 dy0 = pos2.y - pos0.y + 1.0f;
    const f32 dy1 = pos1.y - pos0.y + 1.0f;
    const f32 dy2 = pos2.y - pos1.y + 1.0f;
    const f32 dx0 = (pos2.x - pos0.x) / dy0;
    const f32 dx1 = (pos1.x - pos0.x) / dy1;
    const f32 dx2 = (pos2.x - pos1.x) / dy2;
    const vec3 dn0 = (norm2 - norm0) / dy0;
    const vec3 dn1 = (norm1 - norm0) / dy1;
    const vec3 dn2 = (norm2 - norm1) / dy2;
    const vec3 dt0 = (tex2 - tex0) / dy0;
    const vec3 dt1 = (tex1 - tex0) / dy1;
    const vec3 dt2 = (tex2 - tex1) / dy2;
    const vec4 dc0 = (col2 - col0) / dy0;
    const vec4 dc1 = (col1 - col0) / dy1;
    const vec4 dc2 = (col2 - col1) / dy2;
    f32 sx = pos0.x, ex = pos0.x + dx1;
    vec3 st = tex0, et = tex0 + dt1;
    vec3 sn = norm0, en = norm0 + dn1;
    vec4 sc = col0, ec = col0 + dc1;
    for(i32 y = pos0.y; y <= pos2.y; y++)
    {
        drawLine(sx, ex, y, st, et, sn, en, sc, ec);
        sx += dx0;
        st += dt0;
        sn += dn0;
        sc += dc0;
        ex += y < pos1.y ? dx1 : dx2;
        et += y < pos1.y ? dt1 : dt2;
        en += y < pos1.y ? dn1 : dn2;
        ec += y < pos1.y ? dc1 : dc2;
    }
}

inline void Window::DrawTriangleOutline(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2, const Color& color, f32 width)
{
    DrawLine(x0, y0, x1, y1, color, width);
    DrawLine(x0, y0, x2, y2, color, width);
    DrawLine(x1, y1, x2, y2, color, width);
}

inline void Window::DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Rect<i32>& src, u8 flip, const vec2& origin, const std::array<Color, 4>& colors)
{
    if(src.size.x == 0 || src.size.y == 0) return;
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
    if(end.x < start.x) std::swap(end.x, start.x);
    if(end.y < start.y) std::swap(end.y, start.y);
    for(f32 i = start.x; i < end.x; ++i)
        for(f32 j = start.y; j < end.y; ++j)
        {
            const vec2 o = transform.Backward(i, j);
            const i32 u = src.pos.x + (flip & Flip::Horizontal ? inv.w - std::ceil(o.x) : norm.w + std::floor(o.x));
            const i32 v = src.pos.y + (flip & Flip::Vertical ? inv.h - std::ceil(o.y) : norm.h + std::floor(o.y));
            if(src.Contains(u, v)) SetPixel(i, j, sprite.GetPixel(u, v));
        }
}

inline void Window::DrawSprite(const Sprite& sprite, Transform<f32>& transform, u8 flip, const vec2& origin, const std::array<Color, 4>& colors)
{
    DrawSprite(sprite, transform, {0, sprite.GetSize()}, flip, origin, colors);
}

inline void Window::DrawSprite(i32 x, i32 y, const Sprite& sprite, const vec2& scale, u8 flip, const std::array<Color, 4>& colors)
{
    const vec2 sprSize = scale * sprite.GetSize();
    DrawSprite({ivec2{x, y} - sprSize / 2, (ivec2)sprSize}, sprite, flip, colors);
}

inline void Window::DrawSprite(i32 x, i32 y, const Rect<i32>& src, const Sprite& sprite, const vec2& scale, u8 flip, const std::array<Color, 4>& colors)
{
    if(src.size.x == 0 || src.size.y == 0) return;
    const vec2 sprSize = scale * src.size;
    DrawSprite({ivec2{x, y} - sprSize / 2, (ivec2)sprSize}, src, sprite, flip, colors);
}

inline void Window::DrawSprite(const Rect<i32>& dst, const Sprite& sprite, u8 flip, const std::array<Color, 4>& colors)
{
    DrawSprite(dst, {0, sprite.GetSize()}, sprite, flip, colors);
}

inline void Window::DrawSprite(const Rect<i32>& dst, const Rect<i32>& src, const Sprite& sprite, u8 flip, const std::array<Color, 4>& colors)
{
    if(dst.size.x == 0 || dst.size.y == 0 || src.size.x == 0 || src.size.y == 0) return;    
    const vec2 scale = (vec2)dst.size / src.size;
    const ivec2 p = {flip & Flip::Horizontal ? -1 : 1, flip & Flip::Vertical ? -1 : 1};
    const ivec2 d = {dst.pos.x + (flip & Flip::Horizontal ? dst.size.x : 0), dst.pos.y + (flip & Flip::Vertical ? dst.pos.y : 0)};
    const dvec2 step = 1.0 / dst.size;
    for(i32 x = 0; x < dst.size.x; x++)
        for(i32 y = 0; y < dst.size.y; y++)
        {
            const ivec2 pos = {x, y};
            const vec2 o = floor(pos / scale);
            SetPixel(d + pos * p, sprite.GetPixel(src.pos.x + o.x, src.pos.y + o.y) *
                lerp(lerp(colors[0], colors[3], y * step.y), lerp(colors[1], colors[2], y * step.y), x * step.x));
        }
}

inline void Window::DrawCharacter(i32 x, i32 y, char c, const vec2& scale, const Color& color)
{
    DrawCharacter({{x, y}, {GetCharSize(c, scale.w), scale.h * defFontSize.y}}, c, color);
}

inline void Window::DrawText(i32 x, i32 y, const std::string& text, const vec2& scale, const Color& color, const vec2& origin)
{
    vec2 pos = {x, y - (defFontSize.y + 1) * scale.h * origin.y};
    usize index = 0, next = text.find_first_of('\n', index);
    auto drawText = [&](const std::string& s)
    {
        const vec2 size = GetStringSize(s, scale);
        pos.x -= size.w * origin.x;
        DrawText(Rect<i32>{pos, size}, s, color);
        pos.x = x;
        pos.y += (defFontSize.y + 1) * scale.h;
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

inline void Window::DrawCharacter(const Rect<i32>& dst, char c, const Color& color)
{
    if(dst.size.x == 0 || dst.size.y == 0 || whitespaces.find(c) != std::string_view::npos) return;
    const vec2 scale = (vec2)dst.size / defFontSize;
    for(i32 x = 0; x < dst.size.x; x++)
        for(i32 y = 0; y < dst.size.y; y++)
        {
            const vec2 pos = {x, y};
            const ivec2 o = floor(pos / scale);
            if(defFontData[(int)c - 32][o.y] & (1 << o.x))
                SetPixel(dst.pos + defFontSize * scale - pos, color);
        }
}

inline void Window::DrawRotatedCharacter(i32 x, i32 y, char c, f32 rotation, const vec2& scale, const Color& color)
{
    if(whitespaces.find(c) != std::string_view::npos) return;
    if(almost_equal(mod(rotation, two_pi<f32>), 0.0f)) return DrawCharacter(x, y, c, scale, color);
    f32 ex = 0.0f, ey = 0.0f;
    f32 sx = 0.0f, sy = 0.0f;
    f32 px = 0.0f, py = 0.0f;
    auto calcForward = [&](f32 cx, f32 cy)
    {
        px = cx * std::cos(rotation) * scale.w - cy * std::sin(rotation) * scale.h;
        py = cx * std::sin(rotation) * scale.w + cy * std::cos(rotation) * scale.h;
        sx = std::min(sx, px); sy = std::min(sy, py);
        ex = std::max(ex, px); ey = std::max(ey, py);
    };
    calcForward(0.0f, 0.0f);
    calcForward(defFontSize.x, defFontSize.y);
    calcForward(0.0f, defFontSize.y);
    calcForward(defFontSize.x, 0.0f);
    if(ex < sx) std::swap(ex, sx);
    if(ey < sy) std::swap(ey, sy);
    for(f32 i = sx; i < ex; ++i)
        for(f32 j = sy; j < ey; ++j)
        {
            const f32 ox = defFontSize.x - i * std::cos(rotation) / scale.w - j * std::sin(rotation) / scale.h;
            const f32 oy = defFontSize.y - j * std::cos(rotation) / scale.h + i * std::sin(rotation) / scale.w;
            bool canDrawPixel = oy >= 0.0f && oy < defFontSize.y && ox >= 0.0f && ox < defFontSize.x;
            if(canDrawPixel && defFontData[(int)c - 32][(int)oy] & (1 << (int)ox))
                SetPixel(x + i, y + j, color);
        }
}

inline void Window::DrawRotatedText(i32 x, i32 y, const std::string& text, f32 rotation, const vec2& scale, const Color& color, const vec2& origin)
{
    if(almost_equal(mod(rotation, two_pi<f32>), 0.0f))
        return DrawText(x, y, text, scale, color, origin);
    const f32 vertLineOffset = (defFontSize.y + 1) * scale.h;
    vec2 currDrawPos = {x, y};
    usize index = 0, next = text.find_first_of('\n', index);
    const vec2 ang = vec_from_angle(rotation);
    auto drawText = [&](const std::string& s)
    {
        const vec2 o = GetStringSize(s, scale) * origin;
        vec2 pos = rotate(rotation, currDrawPos, currDrawPos + o) - o;
        for(char c : s)
        {
            DrawRotatedCharacter(pos, c, rotation, scale, color);
            pos += GetCharSize(c, scale.w) * ang;
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

inline void Window::DrawText(const Rect<i32>& dst, const std::string& text, const Color& color)
{
    if(dst.size.x == 0.0f || dst.size.y == 0.0f || text.empty()) return;
    const vec2 stringSize = GetStringSize(text, 1.0f);
    const vec2 scale = (vec2)dst.size / stringSize;
    ivec2 pos = dst.pos;
    for(char c : text)
    {
        DrawCharacter({pos, scale * defFontSize}, c, color);
        if(c == '\n')
        {
            pos.y += (defFontSize.y + 1) * scale.h;
            pos.x = dst.pos.x;
        }
        else
            pos.x += GetCharSize(c, scale.w);
    }
}

inline void Window::SetPixel(const ivec2& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

inline const Color Window::GetPixel(const ivec2& pos) const
{
    return GetPixel(pos.x, pos.y);
}

inline bool Window::ClipLine(ivec2& start, ivec2& end)
{
    return ClipLine(start.x, start.y, end.x, end.y);
}

inline void Window::DrawLine(const ivec2& start, const ivec2& end, const Color& color, f32 width)
{
    DrawLine(start.x, start.y, end.x, end.y, color, width);
}

inline void Window::DrawRect(const ivec2& pos, const ivec2& size, const Color& color)
{
    DrawRect(pos.x, pos.y, size.w, size.h, color);
}

inline void Window::DrawRectOutline(const ivec2& pos, const ivec2& size, const Color& color, f32 angle, f32 width)
{
    DrawRectOutline(pos.x, pos.y, size.w, size.h, color, angle, width);
}

inline void Window::DrawCircle(const ivec2& center, i32 radius, const Color& color)
{
    DrawCircle(center.x, center.y, radius, color);
}

inline void Window::DrawCircleOutline(const ivec2& center, i32 radius, const Color& color)
{
    DrawCircleOutline(center.x, center.y, radius, color);
}

inline void Window::DrawEllipse(const ivec2& center, const ivec2& size, const Color& color)
{
    DrawEllipse(center.x, center.y, size.x, size.y, color);
}

inline void Window::DrawEllipseOutline(const ivec2& center, const ivec2& size, const Color& color)
{
    DrawEllipseOutline(center.x, center.y, size.x, size.y, color);
}

inline void Window::DrawQuadBezierCurve(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 width)
{
    DrawQuadRationalBezierCurve(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color, 1.0f, width);
}

inline void Window::DrawQuadBezierSegment(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 width)
{
    DrawQuadRationalBezierSegment(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color, 1.0f, width);
}

inline void Window::DrawQuadRationalBezierCurve(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 weight, f32 width)
{
    DrawQuadRationalBezierCurve(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color, weight, width);
}

inline void Window::DrawQuadRationalBezierSegment(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 weight, f32 width)
{
    DrawQuadRationalBezierSegment(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color, weight, width);
}

inline void Window::DrawTriangle(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color)
{
    DrawTriangle(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color);
}

inline void Window::DrawTriangleOutline(const ivec2& pos0, const ivec2& pos1, const ivec2& pos2, const Color& color, f32 width)
{
    DrawTriangleOutline(pos0.x, pos0.y, pos1.x, pos1.y, pos2.x, pos2.y, color, width);
}

inline void Window::DrawSprite(const ivec2& pos, const Sprite& sprite, const vec2& scale, u8 flip, const std::array<Color, 4>& colors)
{
    DrawSprite(pos.x, pos.y, sprite, scale, flip, colors);
}

inline void Window::DrawSprite(const ivec2& pos, const Rect<i32>& src, const Sprite& sprite, const vec2& scale, u8 flip, const std::array<Color, 4>& colors)
{
    DrawSprite(pos.x, pos.y, src, sprite, scale, flip, colors);
}

inline void Window::DrawCharacter(const ivec2& pos, char c, const vec2& scale, const Color& color)
{
    DrawCharacter(pos.x, pos.y, c, scale, color);
}

inline void Window::DrawRotatedCharacter(const ivec2& pos, char c, f32 rotation, const vec2& scale, const Color& color)
{
    DrawRotatedCharacter(pos.x, pos.y, c, rotation, scale, color);
}

inline void Window::DrawRotatedText(const ivec2& pos, const std::string& text, f32 rotation, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawRotatedText(pos.x, pos.y, text, rotation, scale, color, origin);
}

inline void Window::DrawText(const ivec2& pos, const std::string& text, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawText(pos.x, pos.y, text, scale, color, origin);
}

inline void Window::DrawMesh(Mesh& mesh)
{
    if(mesh.indexCount == 0) return;
    SetShader(3ull);
    Shader* shader = shaderManager.GetCurrentShader();
    shader->SetUniformMatrix("u_meshWorldMatrix", mesh.transform.GetWorldMatrix());
    SetMaterial(shader, "u_materials[0]", mesh.materials[0]);
    mesh.vao.Bind();
    if(mesh.drawIndexed)
        glDrawElements(mesh.drawMode, mesh.indexCount, GL_UNSIGNED_INT, NULL);
    else
        glDrawArrays(mesh.drawMode, 0, mesh.indexCount);
    mesh.vao.Unbind();
}

inline void Window::DrawSkybox()
{
    if(!m_skyboxCubeMap) return;
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_FALSE);
    SetShader(5ull);
    m_skyboxVAO.Bind();
    glDrawArrays(GL_POINTS, 0, 1);
    m_skyboxVAO.Unbind();
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
}

#endif