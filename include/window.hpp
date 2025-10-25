#ifndef WINDOW_HPP
#define WINDOW_HPP

inline constexpr i32 g_kDefaultTabSpace = 18;
inline constexpr i32 g_kDefaultVerticalTabSpace = 23;
inline constexpr i32 g_kMaxGeoBatchVertices = 512;
inline constexpr i32 g_kMaxGeoBatchIndices = 256;
inline constexpr i32 g_kNumCharacters = 95;
inline constexpr i32 g_kDefaultTextureSlot = 0;
inline constexpr vec3 g_kDefaultUpVector = vec3::Up();
inline constexpr vec3 g_kDefaultCameraPos = {0.0f, 0.0f, 5.0f};
inline constexpr ivec2 g_kDefaultFontSize = {8, 13};
inline constexpr mat3 g_kGaussianBlurMatrix = {1, 2, 1, 2, 4, 2, 1, 2, 1};
inline constexpr vec2 g_kCoordMap[3][3] = {
    vec2{-1.0f, -1.0f}, vec2{0.0f, -1.0f}, vec2{1.0f, -1.0f},
    vec2{-1.0f,  0.0f}, vec2{0.0f,  0.0f}, vec2{1.0f,  0.0f}, 
    vec2{-1.0f,  1.0f}, vec2{0.0f,  1.0f}, vec2{1.0f,  1.0f}
};

constexpr u8 g_kDefaultFontData[g_kNumCharacters][g_kDefaultFontSize.y] = {
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

inline constexpr f32 GetHorizontalCharSize(char c, f32 size)
{
    if(c == '\t')
        return g_kDefaultTabSpace * size;
    else
        return (g_kDefaultFontSize.x + 1) * size;
}

inline vec2 GetStringSize(const std::string& text, f32 sx, f32 sy)
{
    vec2 res = {0, g_kDefaultFontSize.y};
    f32 buffer = 0;
    for(char c : text)
    {
        if(c == '\n')
        {
            res.w = std::max(res.w, buffer);
            res.h += g_kDefaultFontSize.y + 1;
            buffer = 0;
        }
        else if(c == '\v')
        {
            res.w = std::max(res.w, buffer);
            res.h += g_kDefaultVerticalTabSpace;
            buffer = 0;
        }
        else
            buffer += GetHorizontalCharSize(c, sx);
    }
    return {std::max(res.w, buffer), res.h * sy};
}

inline vec2 GetStringSize(const std::string& text, const vec2& scale)
{
    return GetStringSize(text, scale.x, scale.y);
}

class Color
{
    using T = u8;
public:
    union
    {
        u32 color;
        struct { u8 r, g, b, a; };
        SWIZZLE2(r, g)
        SWIZZLE3(r, g, b)
        SWIZZLE4(r, g, b, a)
    };
public:
    inline constexpr Color() : r(0), g(0), b(0), a(255) {}
    inline constexpr Color(u32 c) : color(ReverseBytes(c)) {}
    inline constexpr Color(const ucvec4& rgba) : rgba(rgba) {}
    inline constexpr Color(const ucvec3& rgb, u8 a) : rgb(rgb) {this->a = a;}
    inline constexpr Color(u8 r, u8 g, u8 b, u8 a) : r(r), g(g), b(b), a(a) {}
    template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    inline constexpr Color(const Vector<T, 4>& vec) : rgba(Clamp<T, 4>(vec, T(0), T(1)) * 255) {}
    inline constexpr Color(const Color& col) = default;
    inline constexpr Color(Color&& col) = default;
    inline constexpr Color& operator=(Color&& col) = default;
    inline constexpr Color& operator=(const Color& col) = default;
public:
    inline friend constexpr Color operator*(const Color& lhs, f32 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb * rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, f32 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb / rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, f32 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb + rhs * 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, f32 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb - rhs * 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, const vec4& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb * rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const vec4& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb / rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, const vec4& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb + rhs.rgb * 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, const vec4& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb - rhs.rgb * 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, u8 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb * rhs / 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, u8 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb / rhs * 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, u8 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb + rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, u8 rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb - rhs, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator-(const Color& lhs, const Color& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb - rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator+(const Color& lhs, const Color& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb + rhs.rgb, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator*(const Color& lhs, const Color& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb * rhs.rgb / 255, 0, 255), lhs.a};
    }
    inline friend constexpr Color operator/(const Color& lhs, const Color& rhs)
    {
        return ucvec4{Clamp<int, 3>(lhs.rgb / rhs.rgb * 255, 0, 255), lhs.a};
    }
public:
    inline friend constexpr Color& operator/=(Color& lhs, f32 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb / rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator*=(Color& lhs, f32 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb * rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator+=(Color& lhs, f32 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb + rhs * 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator-=(Color& lhs, f32 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb - rhs * 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator/=(Color& lhs, const vec4& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb / rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator*=(Color& lhs, const vec4& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb * rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator+=(Color& lhs, const vec4& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb + rhs.rgb * 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator-=(Color& lhs, const vec4& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb - rhs.rgb * 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator+=(Color& lhs, u8 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb + rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator-=(Color& lhs, u8 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb - rhs, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator*=(Color& lhs, u8 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb * rhs / 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator/=(Color& lhs, u8 rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb / rhs * 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator+=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb + rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator-=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb - rhs.rgb, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator*=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb * rhs.rgb / 255, 0, 255);
        return lhs;
    }
    inline friend constexpr Color& operator/=(Color& lhs, const Color& rhs)
    {
        lhs.rgb = Clamp<int, 3>(lhs.rgb / rhs.rgb * 255, 0, 255);
        return lhs;
    }
public:
    inline friend constexpr bool operator<(const Color& lhs, const Color& rhs)
    {
        return (lhs.rgb < rhs.rgb && lhs.a <= rhs.a);
    }
    inline friend constexpr bool operator>(const Color& lhs, const Color& rhs)
    {
        return (lhs.rgb > rhs.rgb && lhs.a >= rhs.a);
    }
    inline friend constexpr bool operator<=(const Color& lhs, const Color& rhs)
    {
        return lhs.rgba <= rhs.rgba;
    }
    inline friend constexpr bool operator>=(const Color& lhs, const Color& rhs)
    {
        return lhs.rgba >= rhs.rgba;
    }
    inline friend constexpr bool operator==(const Color& lhs, const Color& rhs)
    {
        return lhs.color == rhs.color;
    }
    inline friend constexpr bool operator!=(const Color& lhs, const Color& rhs)
    {
        return lhs.color != rhs.color;
    }
public:
    template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    inline constexpr operator Vector<T, 4>() const 
    {
        return rgba / static_cast<T>(255);
    }
    template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
    inline constexpr operator Vector<T, 3>() const
    {
        return rgb / static_cast<T>(255);
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        return os << static_cast<ivec4>(color.rgba);
    }
    inline friend std::istream& operator>>(std::istream& is, Color& color)
    {
        return is >> color.rgba;
    }
public:
    inline constexpr Color Inverse() const
    {
        return ucvec4{255 - rgb, a};
    }
    inline friend constexpr Color Lerp(const Color& lhs, const Color& rhs, f64 t)
    {
        return ucvec4{Clamp<int, 4>(Lerp(lhs.rgba, rhs.rgba, t), 0, 255)};
    }
    inline static Color Random()
    {
        return ucvec4::Random(0, 255);
    }
};

namespace Colors
{
    inline constexpr Color IndianRed = {205, 92, 92, 255};
    inline constexpr Color LightCoral = {240, 128, 128, 255};
    inline constexpr Color Salmon = {250, 128, 114, 255};
    inline constexpr Color DarkSalmon = {233, 150, 122, 255};
    inline constexpr Color LightSalmon = {255, 160, 122, 255};
    inline constexpr Color FireBrick = {178, 34, 34, 255};
    inline constexpr Color Red = {255, 0, 0, 255};
    inline constexpr Color Green = {0, 255, 0, 255};
    inline constexpr Color Blue = {0, 0, 255, 255};
    inline constexpr Color White = {255, 255, 255, 255};
    inline constexpr Color Black = {0, 0, 0, 255};
    inline constexpr Color Yellow = {255, 255, 0, 255};
    inline constexpr Color Orange = {255, 165, 0, 255};
    inline constexpr Color Magenta = {255, 0, 255, 255};
    inline constexpr Color Aqua = {0, 255, 255, 255};
    inline constexpr Color Silver = {192, 192, 192, 255};
    inline constexpr Color Gray = {128, 128, 128, 255};
    inline constexpr Color DarkGray = {169, 169, 169, 255};
    inline constexpr Color Purple = {128, 0, 128, 255};
    inline constexpr Color Maroon = {128, 0, 0, 255};
    inline constexpr Color Crimson = {220, 20, 60, 255};
    inline constexpr Color DarkRed = {139, 0, 0, 255};
    inline constexpr Color LightPink = {255, 182, 193, 255};
    inline constexpr Color HotPink = {255, 105, 180, 255};
    inline constexpr Color DeepPink = {255, 20, 147, 255};
    inline constexpr Color MediumVioletRed = {199, 21, 133, 255};
    inline constexpr Color PaleVioletRed = {219, 112, 147, 255};
    inline constexpr Color Coral = {255, 127, 80, 255};
    inline constexpr Color Tomato = {255, 99, 71, 255};
    inline constexpr Color OrangeRed = {255, 69, 0, 255};
    inline constexpr Color DarkOrange = {255, 140, 0, 255};
    inline constexpr Color Gold = {255, 215, 0, 255};
    inline constexpr Color LightYellow = {255, 255, 224, 255};
    inline constexpr Color LemonChiffon = {255, 250, 205, 255};
    inline constexpr Color LightGoldenrodYellow = {250, 250, 210, 255};
    inline constexpr Color PapayaWhip = {255, 239, 213, 255};
    inline constexpr Color Moccasin = {255, 228, 181, 255};
    inline constexpr Color PeachPuff = {255, 218, 185, 255};
    inline constexpr Color PaleGoldenrod = {238, 232, 170, 255};
    inline constexpr Color Lavender = {230, 230, 250, 255};
    inline constexpr Color Thistle = {216, 191, 216, 255};
    inline constexpr Color Plum = {221, 160, 221, 255};
    inline constexpr Color Violet = {238, 130, 238, 255};
    inline constexpr Color Orchid = {218, 112, 214, 255};
    inline constexpr Color Indigo = {75, 0, 130, 255};
    inline constexpr Color DarkKhaki = {189, 183, 107, 255};
    inline constexpr Color Khaki = {240, 230, 140, 255};
    inline constexpr Color DarkGreen = {0, 100, 0, 255};
    inline constexpr Color LimeGreen = {50, 205, 50, 255};
    inline constexpr Color SkyBlue = {135, 206, 235, 255};
    inline constexpr Color MidnightBlue = {25, 25, 112, 255};
    inline constexpr Color Charcoal = {54, 69, 79, 255};
    inline constexpr Color Onyx = {53, 57, 53, 255};
    inline constexpr Color Licorice = {27, 18, 18, 255};
    inline constexpr Color MatteBlack = {40, 40, 43, 255};
    inline constexpr Color Transparent = {0, 0, 0, 0};
};

inline vec2 ScreenToWorldSize(const vec2& size, const vec2& scrSize)
{
    return {
        size.w * 2.0f / scrSize.w,
        size.h * 2.0f / scrSize.h
    };
}

inline ivec2 WorldToScreenSize(const vec2& size, const vec2& scrSize)
{
    return {
        size.w * scrSize.w * 0.5f,
        size.h * scrSize.h * 0.5f
    };
}

inline vec2 ScreenToWorldPos(const vec2& pos, const vec2& scrSize)
{
    return {
        pos.x * 2.0f / scrSize.w - 1.0f,
        -pos.y * 2.0f / scrSize.h + 1.0f
    };
}

inline ivec2 WorldToScreenPos(const vec2& pos, const vec2& scrSize)
{
    return {
        (pos.x + 1.0f) * scrSize.w * 0.5f,
        (-pos.y + 1.0f) * scrSize.h * 0.5f
    };
}

class Window;

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

class Camera
{
public:
    vec3 pos;
protected:
    Frustum<f32> m_camFrustum;
    mat4 m_matProj, m_matView;
    f32 m_nearPlane, m_farPlane;
    Window* m_windowHandle;
public:
    Frustum<f32>& GetFrustum();
    const f32& GetNearPlane() const;
    const f32& GetFarPlane() const;
    const mat4& GetViewMatrix() const;
    const mat4& GetProjMatrix() const;
    Window* GetWindowHandle();
public:
    virtual void Update() = 0;
    virtual void UpdateInternal() = 0;
    virtual void Reset() = 0;
};

class PerspCamera : public Camera
{
public:
    enum class Mode : u8
    {
        FirstPerson,
        ThirdPerson,
        Custom
    };
private:
    Mode m_camUpdateMode = Mode::FirstPerson;
public:
    vec3 up, forward, right, dir;
    f32 sensitivity = 2.5f;
    f32 speed = 5.0f;
private:
    vec2 m_prevMousePos;
    f32 m_fieldOfView;
    std::function<void(PerspCamera*)> m_camUpdateFunc = nullptr;
public:
    inline PerspCamera(const PerspCamera& cam) = default;
    inline PerspCamera(PerspCamera&& cam) = default;
    inline PerspCamera& operator=(const PerspCamera& cam) = default;
    inline PerspCamera& operator=(PerspCamera&& cam) = default;
    inline PerspCamera() = default;
    PerspCamera(Window* window, f32 near = 0.1f, f32 far = 100.0f, f32 fov = 60.0f);
public:
    void SetCameraUpdateMode(const Mode& mode);
    void SetCameraUpdateFunction(std::function<void(PerspCamera*)>&& f);
    const f32& GetFieldOfView() const;
    void SetFieldOfView(const f32& f);
public:
    void Reset() override;
    void Update() override;
    void UpdateInternal() override;
};

class OrthoCamera : public Camera
{
private:
    std::function<void(OrthoCamera*)> m_camUpdateFunc = nullptr;
public:
    inline OrthoCamera() = default;
    OrthoCamera(Window* window, f32 near = 0.1f, f32 far = 100.0f);
    inline OrthoCamera(OrthoCamera&& cam) = default;
    inline OrthoCamera(const OrthoCamera& cam) = default;
    inline OrthoCamera& operator=(const OrthoCamera& cam) = default;
    inline OrthoCamera& operator=(OrthoCamera&& cam) = default;
public:
    void SetCameraUpdateFunction(std::function<void(OrthoCamera*)>&& f);
public:
    void Reset() override;
    void Update() override;
    void UpdateInternal() override;
};

struct default_vertex
{
    vec4 position;
    vec2 texcoord;
};

class Sprite;

class Decal
{
private:
    u32 m_decId = 0;
    i32 m_decWidth = 0, m_decHeight = 0;
public:
    inline Decal() = default;
    inline Decal(const Decal& dec) = default;
    inline Decal(Decal&& dec) = default;
    inline Decal& operator=(const Decal& dec) = default;
    inline Decal& operator=(Decal&& dec) = default;
    Decal(const std::string& path);
    Decal(Sprite& spr);
public:
    u32& GetId();
    const u32& GetId() const;
    const i32& GetWidth() const;
    const i32& GetHeight() const;
    const ivec2 GetSize() const;
    const Rect<i32> GetRect() const;
    f32 GetAspectRatio() const;
public:
    void Update(Sprite& spr);
    void Resize(i32 w, i32 h);
    void Scale(f32 sx, f32 sy);
    void Resize(const ivec2& size);
    void Scale(const vec2& scale);
public:
    virtual ~Decal() {}
};

class Sprite
{
public:
    enum class SampleMode : u8
    {
        Wrap,
        Repeat,
        Clamp
    };
protected:
    SampleMode m_sprSampleMode = SampleMode::Wrap;
    i32 m_sprWidth = 0, m_sprHeight = 0;
    std::vector<Color> m_vecPixels;
public:
    inline Sprite() = default;
    inline Sprite(const Sprite& spr) = default;
    inline Sprite(Sprite&& spr) = default;
    inline Sprite& operator=(const Sprite& spr) = default;
    inline Sprite& operator=(Sprite&& spr) = default;
    Sprite(i32 w, i32 h);
    Sprite(const ivec2& size);
    Sprite(const std::string& path);
    Sprite(Decal& decal);
public:
    void SetPixel(i32 x, i32 y, const Color& color);
    void SetPixel(const ivec2& pos, const Color& color);
    const Color& GetPixel(i32 x, i32 y) const;
    const Color& GetPixel(const ivec2& pos) const;
    const Color Sample(f32 x, f32 y) const;
    const Color Sample(const vec2& pos) const;
    const Color* GetPixelData() const;
    Color* GetPixelData();
public:
    const SampleMode& GetSampleMode() const;
    void SetSampleMode(const SampleMode& s);
    const i32& GetWidth() const;
    const i32& GetHeight() const;
    const Rect<i32> GetRect() const;
    const ivec2 GetSize() const;
    f32 GetAspectRatio() const;
public:
    void Clear(const Color& color);
    void Resize(i32 w, i32 h);
    void Scale(f32 sx, f32 sy);
    void Resize(const ivec2& size);
    void Scale(const vec2& scale);
    void Tint(const Color& color);
    void Blur(f32 radius = 60.0f);
public:
    virtual ~Sprite() {}
};

class Layer : public Sprite
{
private:
    u32 m_layerId;
    bool m_camEnabled = false;
public:
    inline Layer() = default;
    inline Layer(const Layer& layer) = default;
    inline Layer(Layer&& layer) = default;
    inline Layer& operator=(const Layer& layer) = default;
    inline Layer& operator=(Layer&& layer) = default;
    Layer(i32 width, i32 height);
    Layer(const ivec2& size);
public:
    u32& GetId();
    const u32& GetId() const;
    bool IsCameraEnabled() const;
};

class Timer
{
private:
    time_point now;
    f32 m_deltaTime;
public:
    Timer();
public:
    const f32& GetDeltaTime() const;
    void Update();
};

struct Triangle
{
    vec4 pos[3];
    vec3 norm[3];
    vec3 tex[3];
    vec4 col[3];
};

enum class Pass : u8
{
    Pass2D,
    Pass3D
};

enum class PostProcMode : u8
{
    None, Invert,
    Blur, GaussianBlur,
    EdgeDetection, Sharpen,
    Emboss, Monochrome,
    Sepia, Dilation
};

enum class PixelMode : u8
{
    Normal,
    Mask,
    Alpha,
    Custom
};

enum class Flip : u8
{
    None = 0,
    Horizontal = 1,
    Vertical = 2
};

enum class Key : u8
{
    Pressed,
    Held,
    Released,
    None
};

DEFINE_ENUM_OPERATORS(Flip)

class Window
{
public:
    void Begin();
    void End();
    void Start(i32 width, i32 height, const char* name);
    void Clear(const vec4& color);
    void DrawLayers();
    void EnableStencil(bool enable);
    void EnableDepth(bool enable);
    const i32& GetWidth() const;
    const i32& GetHeight() const;
    const dvec2 GetMousePos() const;
    const ivec2 GetScreenSize() const;
    f32 GetAspectRatio() const;
    const Rect<i32>& GetViewport() const;
    f32 GetDeltaTime() const;
    Key GetKey(int key);
    Key GetMouseButton(int button);
    const Sprite::SampleMode& GetSampleMode() const;
    void SetSampleMode(const Sprite::SampleMode& sampleMode);
    Layer& GetLayer(const usize& index);
    void SetCurrentLayer(const usize& index);
    void CreateFBO(const GLenum& attachment);
    void CreateFBO(const std::vector<GLenum>& attachments);
    void BindFBO(const usize& index);
    void UnbindFBO();
    inline GLFWwindow* GetHandle();
    void CreateLayer(i32 width = 0, i32 height = 0);
    void SetShader(const MapKey& key);
    Shader* GetActiveShader();
    void SetPerspCam(const usize& index);
    void SetOrthoCam(const usize& index);
    PerspCamera& GetPerspCam();
    OrthoCamera& GetOrthoCam();
    Frustum<f32>& GetActiveFrustum(const Pass& p);
    void SetPixelMode(const PixelMode& mode);
    const PixelMode& GetPixelMode() const;
    void SetPostProcessMode(const PostProcMode& mode);
    const PostProcMode& GetPostProcessMode() const;
    void SetPixel(i32 x, i32 y, const Color& color);
    void SetAntiAliasedPixel(i32 x, i32 y, const Color& color);
    const Color& GetPixel(i32 x, i32 y) const;
    f32 CalculateSpotLight(int index, const vec3& view, const vec3& norm) const;
    f32 CalculatePointLight(int index, const vec3& view, const vec3& norm) const;
    f32 CalculateDirectionalLight(int index, const vec3& view, const vec3& norm) const;
    int ClipTriangle(const Plane<f32>& plane, Triangle& in, Triangle& out0, Triangle& out1);
    void RasterizeTriangle(const Sprite& sprite, const Triangle& triangle, const mat4& world = mat4::Identity());
    bool ClipLine(i32& sx, i32& sy, i32& ex, i32& ey);
    void DrawLine(i32 sx, i32 sy, i32 ex, i32 ey, const Color& color, f32 width = 1.0f);
    void DrawRect(i32 x, i32 y, i32 w, i32 h, const Color& color);
    void DrawRectOutline(i32 x, i32 y, i32 w, i32 h, const Color& color, f32 angle = 0.0f, f32 width = 1.0f, f32 ox = 0.0f, f32 oy = 0.0f);
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
    void DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Rect<i32>& src, const Flip& flip = Flip::None, f32 ox = 0.5f, f32 oy = 0.5f, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Flip& flip = Flip::None, f32 ox = 0.5f, f32 oy = 0.5f, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(i32 x, i32 y, const Sprite& sprite, f32 sx = 1.0f, f32 sy = 1.0f, const Flip& flip = Flip::None, f32 ox = 0.5f, f32 oy = 0.5f, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(i32 x, i32 y, const Rect<i32>& src, const Sprite& sprite, f32 sx = 1.0f, f32 sy = 1.0f, const Flip& flip = Flip::None, f32 ox = 0.5f, f32 oy = 0.5f, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Rect<i32>& dst, const Rect<i32>& src, const Sprite& sprite, const Flip& flip = Flip::None, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Rect<i32>& dst, const Sprite& sprite, const Flip& flip = Flip::None, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawCharacter(i32 x, i32 y, char c, const Flip& flip, f32 sx = 1.0f, f32 sy = 1.0f, const Color& color = Colors::White, f32 ox = 0.0f, f32 oy = 0.0f);
    void DrawCharacter(i32 x, i32 y, char c, const Flip& flip, f32 rotation, f32 sx = 1.0f, f32 sy = 1.0f, const Color& color = Colors::White, f32 ox = 0.0f, f32 oy = 0.0f);
    void DrawCharacter(const Rect<i32>& dst, char c, const Flip& flip, const Color& color = Colors::White);
    void DrawCharacter(Transform<f32>& transform, char c, const Flip& flip = Flip::None, const Color& color = Colors::White, f32 ox = 0.0f, f32 oy = 0.0f);
    void DrawText(const Rect<i32>& dst, const std::string& text, const Flip& flip, const Color& color = Colors::White);
    void DrawText(i32 x, i32 y, const std::string& text, const Flip& flip, f32 rotation, f32 sx = 1.0f, f32 sy = 1.0f, const Color& color = Colors::White, f32 ox = 0.0f, f32 oy = 0.0f);
    void DrawText(i32 x, i32 y, const std::string& text, const Flip& flip, f32 sx = 1.0f, f32 sy = 1.0f, const Color& color = Colors::White, f32 ox = 0.0f, f32 oy = 0.0f);
    void DrawText(Transform<f32>& transform, const std::string& text, const Flip& flip = Flip::None, const Color& color = Colors::White, f32 ox = 0.0f, f32 oy = 0.0f);
    void SetPixel(const ivec2& pos, const Color& color);
    void SetAntiAliasedPixel(const ivec2& pos, const Color& color);
    const Color& GetPixel(const ivec2& pos) const;
    bool ClipLine(ivec2& start, ivec2& end);
    void DrawLine(const ivec2& start, const ivec2& end, const Color& color, f32 width = 1.0f);
    void DrawRect(const ivec2& pos, const ivec2& size, const Color& color);
    void DrawRectOutline(const ivec2& pos, const ivec2& size, const Color& color, f32 angle = 0.0f, f32 width = 1.0f, const vec2& origin = vec2::Zero());
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
    void DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Flip& flip = Flip::None, const vec2& origin = {0.5f, 0.5f}, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Rect<i32>& src, const Flip& flip = Flip::None, const vec2& origin = {0.5f, 0.5f}, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const ivec2& pos, const Sprite& sprite, const vec2& scale = vec2::One(), const Flip& flip = Flip::None, const vec2& origin = {0.5f, 0.5f}, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawSprite(const ivec2& pos, const Rect<i32>& src, const Sprite& sprite, const vec2& scale = vec2::One(), const Flip& flip = Flip::None, const vec2& origin = {0.5f, 0.5f}, const std::array<Color, 4>& colors = {Colors::White, Colors::White, Colors::White, Colors::White});
    void DrawCharacter(const ivec2& pos, char c, const Flip& flip = Flip::None, const vec2& scale = vec2::One(), const Color& color = Colors::White, const vec2& origin = vec2::Zero());
    void DrawCharacter(const ivec2& pos, char c, const Flip& flip, f32 rotation, const vec2& scale = vec2::One(), const Color& color = Colors::White, const vec2& origin = vec2::Zero());
    void DrawCharacter(Transform<f32>& transform, char c, const Flip& flip = Flip::None, const Color& color = Colors::White, const vec2& origin = vec2::Zero());
    void DrawText(const ivec2& pos, const std::string& text, const Flip& flip, f32 rotation, const vec2& scale = vec2::One(), const Color& color = Colors::White, const vec2& origin = vec2::Zero());
    void DrawText(const ivec2& pos, const std::string& text, const Flip& flip = Flip::None, const vec2& scale = vec2::One(), const Color& color = Colors::White, const vec2& origin = vec2::Zero());
    void DrawText(Transform<f32>& transform, const std::string& text, const Flip& flip = Flip::None, const Color& color = Colors::White, const vec2& origin = vec2::Zero());
    Sprite CreateLabelFromText(const std::string& text, const Flip& flip = Flip::None, const vec2& scale = vec2::One(), const Color& color = Colors::White, const Color& colBackground = Colors::Black);
    void DrawTexturedTriangle(const Sprite& sprite,
        ivec2 pos0, vec3 norm0, vec3 tex0, vec4 col0,
        ivec2 pos1, vec3 norm1, vec3 tex1, vec4 col1,
        ivec2 pos2, vec3 norm2, vec3 tex2, vec4 col2);
    virtual void UserStart() = 0;
    virtual void UserUpdate() = 0;
    void DrawSkybox();
    virtual ~Window()
    {
        SafeDeleteArray(m_depthBuffer);
        glfwDestroyWindow(m_windowHandle);
        glfwTerminate();
    }
private:
    bool m_stencilEnabled = false, m_depthEnabled = true;
    std::function<bool(i32,i32,const Color&)> m_funcDrawPixel = nullptr;
    Rect<i32> m_viewport;
    std::unordered_map<int, Key> m_mapKeyboardInput;
    std::unordered_map<int, Key> m_mapMouseInput;
    PixelMode pixelMode = PixelMode::Normal;
    std::vector<Layer> m_vecDrawTargets;
    usize m_drawTarget = 0;
    GLFWwindow* m_windowHandle;
    std::vector<PerspCamera> vecPerspCameras;
    std::vector<OrthoCamera> vecOrthoCameras;
    usize activePerspCamera = 0, activeOrthoCamera = 0;
    std::array<PointLight, g_kPointLightCount> m_arrPointLights;
    std::array<DirectionalLight, g_kDirLightCount> m_arrDirLights;
    std::array<SpotLight, g_kSpotLightCount> m_arrSpotLights;
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

#ifdef WINDOW_HPP
#undef WINDOW_HPP

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
        if((i32)attachments[i] >= GL_COLOR_ATTACHMENT0 && (i32)attachments[i] <= GL_COLOR_ATTACHMENT0 + maxColorAttachments)
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

inline Sprite::Sprite(i32 w, i32 h) : m_sprWidth(w), m_sprHeight(h)
{
    m_vecPixels.resize(m_sprWidth * m_sprHeight);
}

inline Sprite::Sprite(const ivec2& size) : Sprite(size.x, size.y)
{
    return;
}

inline Sprite::Sprite(const std::string& path)
{
    int channels;
    u8 *bytes = stbi_load(path.c_str(), &m_sprWidth, &m_sprHeight, &channels, 4);
    m_vecPixels.resize(m_sprWidth * m_sprHeight);
    memcpy(m_vecPixels.data(), bytes, 4 * m_sprWidth * m_sprHeight);
    stbi_image_free(bytes);
}

inline Sprite::Sprite(Decal& decal) : m_sprWidth(decal.GetWidth()), m_sprHeight(decal.GetHeight())
{
    m_vecPixels.resize(decal.GetWidth() * decal.GetHeight());
    glBindTexture(GL_TEXTURE_2D, decal.GetId());
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_vecPixels.data());
    glBindTexture(GL_TEXTURE_2D, 0);
}

inline void Sprite::SetPixel(i32 x, i32 y, const Color& color)
{
    if(!m_vecPixels.empty() && x >= 0 && x < m_sprWidth && y >= 0 && y < m_sprHeight)
        m_vecPixels[m_sprWidth * y + x] = color;
}

inline const Color& Sprite::GetPixel(i32 x, i32 y) const
{
    if(m_vecPixels.empty())
        return Colors::Transparent;
    switch(m_sprSampleMode)
    {
        case SampleMode::Wrap:
        {
            if(x < 0 || x >= m_sprWidth || y < 0 || y >= m_sprHeight) 
                return Colors::Transparent;
        }
        break;
        case SampleMode::Repeat:
        {
            x = Abs(x % m_sprWidth);
            y = Abs(y % m_sprHeight);
        }
        break;
        case SampleMode::Clamp:
        {
            x = Clamp(x, 0, m_sprWidth - 1);
            y = Clamp(y, 0, m_sprHeight - 1);
        }
        break;
    }
    return m_vecPixels[m_sprWidth * y + x];
}

inline const Color Sprite::Sample(f32 x, f32 y) const
{
    return GetPixel(std::max<i32>(0, x * m_sprWidth), std::max<i32>(0, y * m_sprHeight));
}

inline void Sprite::SetPixel(const ivec2& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

inline const Color& Sprite::GetPixel(const ivec2& pos) const
{
    return GetPixel(pos.x, pos.y);
}

inline const Color Sprite::Sample(const vec2& pos) const
{
    return Sample(pos.x, pos.y);
}

inline void Sprite::Scale(f32 sx, f32 sy)
{
    if(sx < 0.0f || sy < 0.0f) return;
    const f32 w = m_sprWidth * sx;
    const f32 h = m_sprHeight * sy;
    Sprite spr = Sprite(w, h);
    for(f32 x = 0; x < w; x++)
        for(f32 y = 0; y < h; y++)
        {
            i32 ox = Floor(x / sx);
            i32 oy = Floor(y / sy);
            spr.SetPixel((i32)(x), (i32)(y), GetPixel(ox, oy));
        }
    *this = std::move(spr);
}

inline void Sprite::Resize(i32 w, i32 h)
{
    Scale((f32)w / (m_sprWidth ? m_sprWidth : 1), (f32)h / (m_sprHeight ? m_sprHeight : 1));
}

inline void Sprite::Clear(const Color& color)
{
    for(Color& c : m_vecPixels) c = color;
}

inline void Sprite::Tint(const Color& color)
{
    for(Color& c : m_vecPixels)
        if(c.a != 0)
            c *= color;
}

inline void Sprite::Blur(f32 radius)
{
    Sprite spr = Sprite(m_sprWidth, m_sprHeight);
    spr.Clear(0);
    for(i32 x = 0; x < m_sprWidth; x++)
        for(i32 y = 0; y < m_sprHeight; y++)
        {
            vec4 col = vec4::UnitW();
            for(i32 i = 0; i < 3; i++)
                for(i32 j = 0; j < 3; j++)
                    col.rgb += g_kGaussianBlurMatrix[i][j] * ((vec4)Sample(vec2{x, y} / GetSize() + g_kCoordMap[i][j] / radius)).rgb / 9;
            spr.SetPixel(x, y, col);
        }
    *this = std::move(spr);
}

inline const i32& Sprite::GetWidth() const
{
    return m_sprWidth;
}

inline const i32& Sprite::GetHeight() const
{
    return m_sprHeight;
}

inline Color* Sprite::GetPixelData()
{
    return m_vecPixels.data();
}

inline const Color* Sprite::GetPixelData() const
{
    return &m_vecPixels[0];
}

inline const ivec2 Sprite::GetSize() const
{
    return {m_sprWidth, m_sprHeight};
}

inline f32 Sprite::GetAspectRatio() const
{
    return (f32)m_sprWidth / m_sprHeight;
}

inline const Sprite::SampleMode& Sprite::GetSampleMode() const
{
    return m_sprSampleMode;
}

inline void Sprite::SetSampleMode(const Sprite::SampleMode& s)
{
    m_sprSampleMode = s;
}

inline const Rect<i32> Sprite::GetRect() const
{
    return {ivec2::Zero(), this->GetSize()};
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
    now = steady_clock::now();
}

inline const f32& Timer::GetDeltaTime() const
{
    return m_deltaTime;
}

inline void Timer::Update()
{
    m_deltaTime = std::chrono::duration<f32>(steady_clock::now() - now).count();
    now = steady_clock::now();
}

inline Layer::Layer(i32 width, i32 height)
{
    m_sprWidth = width;
    m_sprHeight = height;
    m_vecPixels.resize(width * height);
    CreateTexture(m_layerId, width, height);
}

inline Layer::Layer(const ivec2& size) : Layer(size.x, size.y)
{
    return;
}

inline u32& Layer::GetId()
{
    return m_layerId;
}

inline const u32& Layer::GetId() const
{
    return m_layerId;
}

inline bool Layer::IsCameraEnabled() const
{
    return m_camEnabled;
}

inline Decal::Decal(Sprite& spr) : m_decWidth(spr.GetWidth()), m_decHeight(spr.GetHeight())
{
    CreateTexture(m_decId, m_decWidth, m_decHeight);
    UpdateTexture(m_decId, m_decWidth, m_decHeight, spr.GetPixelData());
}

inline void Decal::Update(Sprite& spr)
{
    UpdateTexture(m_decId, m_decWidth, m_decHeight, spr.GetPixelData());
}

inline const ivec2 Decal::GetSize() const
{
    return {m_decWidth, m_decHeight};
}

inline Decal::Decal(const std::string& path)
{
    int channels;
    u8* data = stbi_load(path.c_str(), &m_decWidth, &m_decHeight, &channels, 4);
    CreateTexture(m_decId, m_decWidth, m_decHeight);
    UpdateTexture(m_decId, m_decWidth, m_decHeight, data);
    stbi_image_free(data);
}

inline const i32& Decal::GetWidth() const
{
    return m_decWidth;
}

inline const i32& Decal::GetHeight() const
{
    return m_decHeight;
}

inline const u32& Decal::GetId() const
{
    return m_decId;
}

inline u32& Decal::GetId()
{
    return m_decId;
}

inline void Decal::Resize(i32 w, i32 h)
{
    Sprite spr = *this;
    spr.Resize(w, h);
    *this = spr;
}

inline void Decal::Scale(f32 sx, f32 sy)
{
    this->Resize(m_decWidth * sx, m_decHeight * sy);
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
    return {ivec2::Zero(), this->GetSize()};
}

inline f32 Decal::GetAspectRatio() const
{
    return (f32)m_decWidth / m_decHeight;
}

Frustum<f32>& Camera::GetFrustum()
{
    return m_camFrustum;
}

const f32& Camera::GetNearPlane() const
{
    return m_nearPlane;
}

const f32& Camera::GetFarPlane() const
{
    return m_farPlane;
}

const mat4& Camera::GetViewMatrix() const
{
    return m_matView;
}

const mat4& Camera::GetProjMatrix() const
{
    return m_matProj;
}

inline Window* Camera::GetWindowHandle()
{
    return m_windowHandle;
}

inline PerspCamera::PerspCamera(Window* window, f32 near, f32 far, f32 fov) : m_fieldOfView(fov)
{
    m_farPlane = far;
    m_nearPlane = near;
    m_windowHandle = window;
    m_prevMousePos = m_windowHandle->GetMousePos();
    m_matProj = GetPerspectiveMatrix(window->GetAspectRatio(), fov, near, far);
    this->Reset();
}

inline void PerspCamera::Reset()
{
    dir = {0.0f, 0.0f, -g_kPi<f32> * 0.5f};
    pos = g_kDefaultCameraPos;
    UpdateInternal();
}

inline void PerspCamera::Update()
{
    switch(m_camUpdateMode)
    {
        case PerspCamera::Mode::FirstPerson:
        {
            const vec2 offset = (m_windowHandle->GetMousePos() - m_prevMousePos) * sensitivity * m_windowHandle->GetDeltaTime();
            dir.pitch = Clamp(dir.pitch - offset.y, -g_kHalfPi<f32>, g_kHalfPi<f32>); 
            dir.yaw += offset.x;
            if(m_windowHandle->GetKey(GLFW_KEY_UP) == Key::Held)
                pos += forward * speed * m_windowHandle->GetDeltaTime();
            if(m_windowHandle->GetKey(GLFW_KEY_DOWN) == Key::Held)
                pos -= forward * speed * m_windowHandle->GetDeltaTime();
            if(m_windowHandle->GetKey(GLFW_KEY_RIGHT) == Key::Held)
                pos += right * speed * m_windowHandle->GetDeltaTime();
            if(m_windowHandle->GetKey(GLFW_KEY_LEFT) == Key::Held)
                pos -= right * speed * m_windowHandle->GetDeltaTime();
            m_prevMousePos = m_windowHandle->GetMousePos();
        }
        break;
        case PerspCamera::Mode::ThirdPerson:

        break;
        case PerspCamera::Mode::Custom:
            if(m_camUpdateFunc)
                m_camUpdateFunc(this);
        break;
    }
    UpdateInternal();
}

inline void PerspCamera::UpdateInternal()
{
    forward = vec3
    {
        std::cos(dir.yaw) * std::cos(dir.pitch), 
        std::sin(dir.pitch), 
        std::sin(dir.yaw) * std::cos(dir.pitch)
    }.Norm();
    right = Cross(forward, g_kDefaultUpVector).Norm();
    up = Cross(right, forward).Norm();
    m_matView = MatrixLookAt(pos, pos + forward, up);
    m_camFrustum.SetInternalMatrix(m_matProj * m_matView);
}

inline void PerspCamera::SetCameraUpdateMode(const Mode& mode)
{
    m_camUpdateMode = mode;
}

inline void PerspCamera::SetCameraUpdateFunction(std::function<void(PerspCamera*)>&& f)
{
    m_camUpdateFunc = std::move(f);
}

inline const f32& PerspCamera::GetFieldOfView() const
{
    return m_fieldOfView;
}

inline void PerspCamera::SetFieldOfView(const f32& f)
{
    m_fieldOfView = f;
    m_matProj = GetPerspectiveMatrix(m_windowHandle->GetAspectRatio(), f, m_nearPlane, m_farPlane);
    m_camFrustum.SetInternalMatrix(m_matProj * m_matView);
}

inline OrthoCamera::OrthoCamera(Window* window, f32 near, f32 far)
{
    m_windowHandle = window;
    m_nearPlane = near;
    m_farPlane = far;
    m_matProj = GetOrthographicMatrix(1.0f, -1.0f, -1.0f, 1.0f, near, far);
    this->Reset();
}

inline void OrthoCamera::Update()
{
    if(m_camUpdateFunc != nullptr)
    {
        m_camUpdateFunc(this);
        UpdateInternal();
    }
}

inline void OrthoCamera::Reset()
{
    pos = -g_kDefaultCameraPos;
    UpdateInternal();
}

inline void OrthoCamera::UpdateInternal()
{
    m_matView = GetTranslationMatrix<f32>({pos.xy, -g_kDefaultCameraPos.z});
    m_camFrustum.SetInternalMatrix(m_matProj * m_matView);
}

inline void OrthoCamera::SetCameraUpdateFunction(std::function<void(OrthoCamera*)>&& f)
{
    m_camUpdateFunc = std::move(f);
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
    m_windowHandle = glfwCreateWindow(width, height, name, nullptr, nullptr);
    glfwMakeContextCurrent(m_windowHandle);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return;
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    EnableDepth(true);
    CreateLayer(width, height);
    SetCurrentLayer(0);
    m_viewport = {ivec2::Zero(), {width, height}};
    vecPerspCameras.emplace_back(this);
    vecOrthoCameras.emplace_back(this);
    m_depthBuffer = new f32[width * height];
    SetMemory(m_depthBuffer, 0, 4 * width * height);
    vecPerspCameras[0].SetCameraUpdateMode(PerspCamera::Mode::FirstPerson);
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res/shaders/default.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res/shaders/default.frag").c_str())
        })
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res/shaders/sprite_batch.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res/shaders/sprite_batch.frag").c_str())
        }),
        [&](Shader& instance)
        {
            for(int i = 0; i < g_kSpriteBatchMaxSprites; i++)
                instance.SetUniform("u_buffers[" + std::to_string(i) + "]", &i);
        }
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res/shaders/geo_batch.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res/shaders/geo_batch.frag").c_str())
        })
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res/shaders/lighting.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res/shaders/lighting.frag").c_str())
        }),
        [&](Shader& instance)
        {
            for(i32 i = 0; i < g_kPointLightCount; i++)
                m_arrPointLights[i].Set(instance, "u_pointLights[" + std::to_string(i) + "]");
            for(i32 i = 0; i < g_kDirLightCount; i++)
                m_arrDirLights[i].Set(instance, "u_dirLights[" + std::to_string(i) + "]");
            for(i32 i = 0; i < g_kSpotLightCount; i++)
                m_arrSpotLights[i].Set(instance, "u_spotLights[" + std::to_string(i) + "]");
        },
        [&](Shader& instance)
        {
            instance.SetUniform("u_camMatrix", GetPerspCam().GetFrustum().GetMatrix());
            instance.SetUniform("u_camPos", GetPerspCam().pos);
        }
    ));
    shaderManager.AddShader(Shader(
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res/shaders/post_processing.vert").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res/shaders/post_processing.frag").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniform("u_scrQuad", 0);
            instance.SetUniform("u_postProcMode", (int)m_postProcMode);
            BindTexture(m_vecFramebuffers[0].renderTargets[0], 0);
        }
    ));
    shaderManager.AddShader({
        CompileProgram({
            CompileShader(GL_VERTEX_SHADER, ReadShader("res/shaders/cubemap.vert").c_str()),
            CompileShader(GL_GEOMETRY_SHADER, ReadShader("res/shaders/cubemap.geom").c_str()),
            CompileShader(GL_FRAGMENT_SHADER, ReadShader("res/shaders/cubemap.frag").c_str())
        }),
        [&](Shader& instance)
        {
            instance.SetUniform("u_projection", GetPerspCam().GetProjMatrix());
            instance.SetUniform("u_view", mat4(mat3(GetPerspCam().GetViewMatrix())));
            if(m_skyboxCubeMap)
                glBindTexture(GL_TEXTURE_CUBE_MAP, m_skyboxCubeMap);
        }
    });
    SetShader(0);
    constexpr std::array<default_vertex, 4> vertices = 
    {
        default_vertex{{-1.0f,  1.0f, -0.9219219f, 1.0f}, {0.0f, 0.0f}},
        default_vertex{{-1.0f, -1.0f, -0.9219219f, 1.0f}, {0.0f, 1.0f}},
        default_vertex{{ 1.0f,  1.0f, -0.9219219f, 1.0f}, {1.0f, 0.0f}},
        default_vertex{{ 1.0f, -1.0f, -0.9219219f, 1.0f}, {1.0f, 1.0f}}
    };
    m_quadVAO.Build();
    m_quadVBO.Build(vertices);
    m_quadVBO.AddAttrib(0, 4, offsetof(default_vertex, position));
    m_quadVBO.AddAttrib(1, 2, offsetof(default_vertex, texcoord));
    m_skyboxVAO.Build();
    CreateFBO(GL_COLOR_ATTACHMENT0);
    UserStart();
    while(!glfwWindowShouldClose(m_windowHandle))
    {
        Begin();
        BindFBO(0);
        UserUpdate();
        DrawLayers();
        UnbindFBO();
        m_quadVAO.Bind();
        SetShader(4);
        EnableDepth(false);
        Clear(vec4::Zero());
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        m_quadVAO.Unbind();
        EnableDepth(true);
        End();
    }
}

inline f32 Window::GetDeltaTime() const
{
    return timer.GetDeltaTime();
}

inline f32 Window::GetAspectRatio() const
{
    return m_vecDrawTargets[m_drawTarget].GetAspectRatio();
}

inline void Window::SetShader(const MapKey& key)
{
    shaderManager.SetShader(key);
}

inline GLFWwindow* Window::GetHandle()
{
    return m_windowHandle;
}

inline Shader* Window::GetActiveShader()
{
    return shaderManager.GetActiveShader();
}

inline void Window::SetPerspCam(const usize& index)
{
    if(activePerspCamera != index && index < vecPerspCameras.size())
        activePerspCamera = index;
}

inline void Window::SetOrthoCam(const usize& index)
{
    if(activeOrthoCamera != index && index < vecOrthoCameras.size())
        activeOrthoCamera = index;
}

inline PerspCamera& Window::GetPerspCam()
{
    return vecPerspCameras[activePerspCamera];
}

inline OrthoCamera& Window::GetOrthoCam()
{
    return vecOrthoCameras[activeOrthoCamera];
}

inline Frustum<f32>& Window::GetActiveFrustum(const Pass& p)
{
    if(p == Pass::Pass2D)
        return vecOrthoCameras[activeOrthoCamera].GetFrustum();
    else
        return vecPerspCameras[activePerspCamera].GetFrustum();
}

inline Key Window::GetKey(int key)
{
    const int s = glfwGetKey(m_windowHandle, key);
    if(!m_mapKeyboardInput.count(key))
        return (m_mapKeyboardInput[key] = s == GLFW_PRESS ? Key::Pressed : Key::None);
    bool pressed = (m_mapKeyboardInput.at(key) == Key::Pressed || m_mapKeyboardInput.at(key) == Key::Held);
    if(s == GLFW_PRESS)
        m_mapKeyboardInput[key] = pressed ? Key::Held : Key::Pressed;
    else
        m_mapKeyboardInput[key] = pressed ? Key::Released : Key::None;
    return m_mapKeyboardInput[key];
}

inline Key Window::GetMouseButton(int button)
{
    const int s = glfwGetMouseButton(m_windowHandle, button);
    if(!m_mapMouseInput.count(button)) 
        return (m_mapMouseInput[button] = s == GLFW_PRESS ? Key::Pressed : Key::None);
    bool pressed = (m_mapMouseInput.at(button) == Key::Pressed || m_mapMouseInput.at(button) == Key::Held);
    if(s == GLFW_PRESS)
        m_mapMouseInput[button] = pressed ? Key::Held : Key::Pressed;
    else
        m_mapMouseInput[button] = pressed ? Key::Released : Key::None;
    return m_mapMouseInput[button];
}

inline void Window::Clear(const vec4& c)
{
    int code = GL_COLOR_BUFFER_BIT;
    if(m_depthEnabled) code |= GL_DEPTH_BUFFER_BIT;
    if(m_stencilEnabled) code |= GL_STENCIL_BUFFER_BIT;
    glClearColor(c.r, c.g, c.b, c.a);
    glClear(code);
    SetMemory(m_depthBuffer, 0, 4 * GetWidth() * GetHeight());
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
    if((m_depthEnabled = enable))
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
}

inline void Window::EnableStencil(bool enable)
{
    if((m_stencilEnabled = enable))
        glEnable(GL_STENCIL_TEST);
    else
        glDisable(GL_STENCIL_TEST);
}

inline void Window::Begin()
{
    timer.Update();
    for(auto& cam : vecPerspCameras) cam.Update();
    for(auto& cam : vecOrthoCameras) cam.Update();
    shaderManager.UpdateShader();
}

inline void Window::DrawLayers()
{
    SetShader(0);
    m_quadVAO.Bind();
    for(auto& drawTarget : m_vecDrawTargets)
    {
        UpdateTexture(
            drawTarget.GetId(),
            drawTarget.GetWidth(),
            drawTarget.GetHeight(),
            drawTarget.GetPixelData()
        );
        BindTexture(drawTarget.GetId());
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    BindTexture(0);
    m_quadVAO.Unbind();
}

inline void Window::End()
{
    glfwSwapBuffers(m_windowHandle);
    glfwPollEvents();
}

inline void Window::CreateLayer(i32 width, i32 height)
{
    if(width <= 0 || height <= 0) {width = GetWidth(); height = GetHeight();}
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

inline const i32& Window::GetWidth() const
{
    return m_vecDrawTargets[m_drawTarget].GetWidth();
}

inline const i32& Window::GetHeight() const
{
    return m_vecDrawTargets[m_drawTarget].GetHeight();
}

inline const Color& Window::GetPixel(i32 x, i32 y) const
{
    return m_vecDrawTargets[m_drawTarget].GetPixel(x, y);
}

inline void Window::SetSampleMode(const Sprite::SampleMode& s)
{
    m_vecDrawTargets[m_drawTarget].SetSampleMode(s);
}

inline const Sprite::SampleMode& Window::GetSampleMode() const
{
    return m_vecDrawTargets[m_drawTarget].GetSampleMode();
}

inline const dvec2 Window::GetMousePos() const
{
    dvec2 res;
    glfwGetCursorPos(m_windowHandle, &res.x, &res.y);
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
        if(!layer.IsCameraEnabled()) return layer.SetPixel(x, y, color);
        vec4 pos = {x, y, 0.0f, 1.0f};
        const vec2 scrSize = this->GetScreenSize();
        pos.xy = ScreenToWorldPos(pos.xy, scrSize);
        pos = this->GetOrthoCam().GetFrustum().GetMatrix() * pos;
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
        out0.pos[1].w = Lerp(insidePos[0].w, outsidePos[0].w, t);
        out0.norm[1] = Lerp(insideNorm[0], outsideNorm[0], t);
        out0.tex[1] = Lerp(insideTex[0], outsideTex[0], t);
        out0.col[1] = Lerp(insideCol[0], outsideCol[0], t);
    	out0.pos[2].xyz = plane.IntersectionPoint(insidePos[0].xyz, outsidePos[1].xyz, t);
        out0.pos[2].w = Lerp(insidePos[0].w, outsidePos[1].w, t);
        out0.norm[2] = Lerp(insideNorm[0], outsideNorm[1], t);
        out0.tex[2] = Lerp(insideTex[0], outsideTex[1], t);
        out0.col[2] = Lerp(insideCol[0], outsideCol[1], t);
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
        out1.pos[1].w = out0.pos[2].w = Lerp(insidePos[0].w, outsidePos[0].w, t);
    	out1.norm[1] = out0.norm[2] = Lerp(insideNorm[0], outsideNorm[0], t);
        out1.tex[1] = out0.tex[2] = Lerp(insideTex[0], outsideTex[0], t);
        out1.col[1] = out0.col[2] = Lerp(insideCol[0], outsideCol[0], t);
        out1.pos[2].xyz = plane.IntersectionPoint(insidePos[1].xyz, outsidePos[0].xyz, t);
        out1.pos[2].w = Lerp(insidePos[1].w, outsidePos[0].w, t);
        out1.norm[2] = Lerp(insideNorm[1], outsideNorm[0], t);
        out1.tex[2] = Lerp(insideTex[1], outsideTex[0], t);
        out1.col[2] = Lerp(insideCol[1], outsideCol[0], t);
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
    const mat3 inv = mat3(world.Inverse().Transpose());
    temp.norm[0] = inv * temp.norm[0];
    temp.norm[1] = inv * temp.norm[1];
    temp.norm[2] = inv * temp.norm[2];
    PerspCamera& cam = vecPerspCameras[activePerspCamera];
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
                case 0: trisToAdd = ClipTriangle(cam.GetFrustum().near, test, clipped[0], clipped[1]); break;
                case 1: trisToAdd = ClipTriangle(cam.GetFrustum().far, test, clipped[0], clipped[1]); break;
                case 2:	trisToAdd = ClipTriangle(cam.GetFrustum().top, test, clipped[0], clipped[1]); break;
                case 3:	trisToAdd = ClipTriangle(cam.GetFrustum().bottom, test, clipped[0], clipped[1]); break;
                case 4:	trisToAdd = ClipTriangle(cam.GetFrustum().right, test, clipped[0], clipped[1]); break;
                case 5:	trisToAdd = ClipTriangle(cam.GetFrustum().left, test, clipped[0], clipped[1]); break;
            }
            for(int j = 0; j < trisToAdd; j++)
            	listTriangles.push_back(clipped[j]);
    	}
        newTris = listTriangles.size();
    }
    for(auto &tri : listTriangles)
    {
        tri.pos[0] = cam.GetFrustum().GetMatrix() * tri.pos[0];
        tri.pos[1] = cam.GetFrustum().GetMatrix() * tri.pos[1];
        tri.pos[2] = cam.GetFrustum().GetMatrix() * tri.pos[2];
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
    i32 dx = Abs(ex - sx), px = sx < ex ? 1 : -1;
    i32 dy = Abs(ey - sy), py = sy < ey ? 1 : -1;
    i32 err;
    f32 e = Hypot<f32>(dx, dy);
    width = 255 * (width - 1);
    dx *= 255 / e;
    dy *= 255 / e;
    if(dx < dy)
    {
        ex = Round((e + width * 0.5f) / dy);
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
        ey = Round((e + width * 0.5f) / dx);
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
    w = Clamp(w, 0, GetWidth());
    h = Clamp(h, 0, GetHeight());
    for(i32 i = x; i <= x + w; i++)
        for(i32 j = y; j <= y + h; j++)
            SetPixel(i, j, color);
}

inline void Window::DrawRectOutline(i32 x, i32 y, i32 w, i32 h, const Color& color, f32 angle, f32 width, f32 ox, f32 oy)
{
    if(NotRotated(angle))
    {
        DrawLine(x, y, x, y + h, color, width);
        DrawLine(x, y, x + w, y, color, width);
        DrawLine(x + w, y + h, x, y + h, color, width);
        DrawLine(x + w, y + h, x + w, y, color, width);
        return;
    }
    const vec2 pos0 = Rotate<f32>(angle, 0, h, ox, oy);
    const vec2 pos1 = Rotate<f32>(angle, w, 0, ox, oy);
    const vec2 pos2 = Rotate<f32>(angle, w, h, ox, oy);
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
    //TODO
    return;
}

void Window::DrawRoundedRectOutline(i32 xe, i32 ye, i32 w, i32 h, i32 rx, i32 ry, const Color& color, f32 width)
{
    //TODO
    return;
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
    bool stop = false;
    if(curr == 0.0f || weight <= 0.0f) return;
    if(sx * sx + sy * sy > xx * xx + yy * yy)
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
    if(curr * sx * sy < 0)
    {
        xx *= -1;
        yy *= -1;
        xy *= -1;
        curr *= -1;
    }
    dx = 4.0f * weight * (x1 - x0) * sy * curr + xx * 0.5f;
    dy = 4.0f * weight * (y0 - y1) * sx * curr + yy * 0.5f;
    if(weight < 0.5f && (dx + xx <= 0 || dy + yy >= 0))
    {
        curr = (weight + 1.0f) * 0.5f;
        weight = Sqrt(weight);
        xy = 1.0f / (weight + 1.0f);
        sx = Round((x0 + 2.0f * weight * x1 + x2) * xy * 0.5f);
        sy = Round((y0 + 2.0f * weight * y1 + y2) * xy * 0.5f);
        dx = Round((weight * x1 + x0) * xy);
        dy = Round((y1 * weight + y0) * xy);
        DrawQuadRationalBezierSegment(x0, y0, dx, dy, sx, sy, color, curr, width);
        dx = Round((weight * x1 + x2) * xy);
        dy = Round((y1 * weight + y2) * xy);
        return DrawQuadRationalBezierSegment(sx, sy, dx, dy, x2, y2, color, curr, width);
    }
    for(err = 0; dy + 2 * yy < 0 && dx + 2 * xx > 0;)
        if(dx + dy + xy < 0)
        {
            do
            {
                ed = -dy - 2 * dy * dx * dx / (4.0f * dy * dy + dx * dx);
                weight = (width - 1) * ed;
                x1 = Floor((err - ed - weight * 0.5f) / dy);
                e = err - x1 * dy - weight * 0.5f;
                x1 = x0 - x1 * sx;
                SetAntiAliasedPixel(x1, y0, {color.rgb, (u8)(255 * e / ed)});
                for(e = -weight - dy - e; e - dy < ed; e -= dy)
                    SetPixel(x1 += sx, y0, color);
                SetAntiAliasedPixel(x1 + sx, y0, {color.rgb, (u8)(255 * e / ed)});
                if(y0 == y2) return;
                y0 += sy;
                dy += xy;
                err += dx;
                dx += xx;
                if(2 * err + dy > 0)
                {
                    x0 += sx;
                    dx += xy;
                    err += dy;
                    dy += yy;
                }
                if(x0 != x2 && (dx + 2 * xx <= 0 || dy + 2 * yy >= 0))
                {
                    if(Abs(y2 - y0) > Abs(x2 - x0))
                    {
                        stop = true;
                        break;
                    }
                    else
                        break;
                }
            } while(dx + dy + xy < 0);
            if(stop) break;
            for(curr = err - dy - weight * 0.5f, y1 = y0; curr < ed; y1 += sy, curr += dx)
            {
                for(e = curr, x1 = x0; e - dy < ed; e -= dy)
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
                y1 = Floor((err + ed + weight * 0.5f) / dx);
                e = y1 * dx - weight * 0.5f - err;
                y1 = y0 - y1 * sy;
                SetAntiAliasedPixel(x0, y1, {color.rgb, (u8)(255 * e / ed)});
                for(e = dx - e - weight; e + dx < ed; e += dx)
                    SetPixel(x0, y1 += sy, color);
                SetAntiAliasedPixel(x0, y1 + sy, {color.rgb, (u8)(255 * e / ed)});
                if(x0 == x2) return;
                x0 += sx;
                dx += xy;
                err += dy;
                dy += yy;
                if(2 * err + dx < 0)
                {
                    y0 += sy;
                    dy += xy;
                    err += dx;
                    dx += xx;
                }
                if(y0 != y2 && (dx + 2 * xx <= 0 || dy + 2 * yy >= 0))
                {
                    if(Abs(y2 - y0) <= Abs(x2 - x0))
                    {
                        stop = true;
                        break;
                    }
                    else
                        break;
                }
            } while(dx + dy + xy >= 0);
            if(stop) break;
            for(curr = -err + dx - weight * 0.5f, x1 = x0; curr < ed; x1 += sx, curr -= dy)
            {
                for(e = curr, y1 = y0; e + dx < ed; e += dx)
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
    if(xx * (x2 - x1) > 0)
    {
        if(yy * (y2 - y1) > 0)
            if(Abs(xx * y) > Abs(yy * x))
            {
                x0 = x2;
                x2 = xx + x1;
                y0 = y2;
                y2 = yy + y1;
            }
        if(x0 == x2 || weight == 1.0f)
            t = (x0 - x1) / (f32)x;
        else
        {
            q = Sqrt(4.0f * weight * weight * (x0 - x1) * (x2 - x1) + (x2 - x0) * (x2 - x0));
            if(x1 < x0) q = -q;
            t = (2.0f * weight * (x0 - x1) - x0 + x2 + q) / (2.0f * (1.0f - weight) * (x2 - x0));
        }
        q = 1.0f / (2.0f * t * (1.0f - t) * (weight - 1.0f) + 1.0f);
        xx = (t * t * (x0 - 2.0f * weight * x1 + x2) + 2.0f * t * (weight * x1 - x0) + x0) * q;
        yy = (t * t * (y0 - 2.0f * weight * y1 + y2) + 2.0f * t * (weight * y1 - y0) + y0) * q;
        ww = t * (weight - 1.0f) + 1.0f;
        ww *= ww * q;
        weight = ((1.0f - t) * (weight - 1.0f) + 1.0f) * Sqrt(q);
        x = Round(xx);
        y = Round(yy);
        yy = (xx - x0) * (y1 - y0) / (x1 - x0) + y0;
        DrawQuadRationalBezierSegment(x0, y0, x, Round(yy), x, y, color, ww, width);
        yy = (xx - x2) * (y1 - y2) / (x1 - x2) + y2;
        y1 = Round(yy);
        x0 = x1 = x;
        y0 = y;
    }
    if((y0 - y1) * (y2 - y1) > 0)
    {
        if(y0 == y2 || weight == 1.0f)
            t = (y0 - y1) / (y0 - 2.0f * y1 + y2);
        else
        {
            q = Sqrt(4.0f * weight * weight * (y0 - y1) * (y2 - y1) + (y2 - y0) * (y2 - y0));
            if(y1 < y0) q = -q;
            t = (2.0f * weight * (y0 - y1) - y0 + y2 + q) / (2.0f * (1.0f - weight) * (y2 - y0));
        }
        q = 1.0f / (2.0f * t * (1.0f - t) * (weight - 1.0f) + 1.0f);
        xx = (t * t * (x0 - 2.0f * weight * x1 + x2) + 2.0f * t * (weight * x1 - x0) + x0) * q;
        yy = (t * t * (y0 - 2.0f * weight * y1 + y2) + 2.0f * t * (weight * y1 - y0) + y0) * q;
        ww = t * (weight - 1.0f) + 1.0f;
        ww *= ww * q;
        weight = ((1.0f - t) * (weight - 1.0f) + 1.0f) * Sqrt(q);
        x = Round(xx);
        y = Round(yy);
        xx = (x1 - x0) * (yy - y0) / (y1 - y0) + x0;
        DrawQuadRationalBezierSegment(x0, y0, Round(xx), y, x, y, color, ww, width);
        xx = (x1 - x2) * (yy - y2) / (y1 - y2) + x2;
        x1 = Round(xx);
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
    const vec3 dir = -m_arrDirLights[index].direction.Norm();
    const f32 diffuse = 0.5f * Max(Dot(norm, dir), 0.0f);
    const vec3 refl = Reflect(-dir, norm);
    const f32 specular = 0.8f * std::pow(Max(Dot(view, refl), 0.0f), 32.0f);
    return 0.1f + diffuse + specular;
}

inline f32 Window::CalculatePointLight(int index, const vec3& view, const vec3& norm) const
{
    
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
    const vec2 size = sprite.GetSize();
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
    	f64 t = 0.0;
        const f64 dt = 1.0 / (f64)(ex - sx);
        for(i32 x = sx; x <= ex; x++)
    	{
            tex = Lerp(st, et, t);
            norm = Lerp(sn, en, t);
            if(m_depthBuffer[y * width + x] < tex.z)
            {
                buffer.SetPixel(x, y, sprite.GetPixel(size * tex.xy / tex.z) * Lerp(sc, ec, t));
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

inline void Window::DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Rect<i32>& src, const Flip& flip, f32 ox, f32 oy, const std::array<Color, 4>& colors)
{
    if(src.size.x == 0 || src.size.y == 0) return;
    const dvec2 step = 1.0 / sprite.GetSize();
    const vec2 norm = {src.size.x * ox, src.size.y * oy};
    const vec2 inv = {src.size.x * (1.0f - ox), src.size.y * (1.0f - oy)};
    vec2 start, end, p;
    p = start = transform.Forward(-norm);
    start = Min(p, start); end = Max(p, end);
    p = transform.Forward(inv);
    start = Min(p, start); end = Max(p, end);
    p = transform.Forward(-norm.w, inv.h);
    start = Min(p, start); end = Max(p, end);
    p = transform.Forward(inv.w, -norm.h);
    start = Min(p, start); end = Max(p, end);
    transform.Invert();
    if(end.x < start.x) std::swap(end.x, start.x);
    if(end.y < start.y) std::swap(end.y, start.y);
    for(f32 i = start.x; i < end.x; ++i)
        for(f32 j = start.y; j < end.y; ++j)
        {
            const vec2 o = transform.Backward(i, j);
            const i32 u = src.pos.x + (flip & Flip::Horizontal ? inv.w - Ceil(o.x) : norm.w + Floor(o.x));
            const i32 v = src.pos.y + (flip & Flip::Vertical ? inv.h - Ceil(o.y) : norm.h + Floor(o.y));
            if(src.Contains(u, v)) SetPixel(i, j, sprite.GetPixel(u, v) *
                Lerp(Lerp(colors[0], colors[3], o.y * step.y), Lerp(colors[1], colors[2], o.y * step.y), o.x * step.x));
        }
}

inline void Window::DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Flip& flip, f32 ox, f32 oy, const std::array<Color, 4>& colors)
{
    DrawSprite(sprite, transform, sprite.GetRect(), flip, ox, oy, colors);
}

inline void Window::DrawSprite(i32 x, i32 y, const Sprite& sprite, f32 sx, f32 sy, const Flip& flip, f32 ox, f32 oy, const std::array<Color, 4>& colors)
{
    const vec2 size = {sx * sprite.GetWidth(), sy * sprite.GetHeight()};
    DrawSprite({{x - size.x * ox, y - size.y * oy}, size}, sprite, flip, colors);
}

inline void Window::DrawSprite(i32 x, i32 y, const Rect<i32>& src, const Sprite& sprite, f32 sx, f32 sy, const Flip& flip, f32 ox, f32 oy, const std::array<Color, 4>& colors)
{
    if(src.size.x == 0 || src.size.y == 0) return;
    const vec2 size = {src.size.x * sx, src.size.y * sy};
    DrawSprite({{x - size.x * ox, y - size.y * oy}, size}, src, sprite, flip, colors);
}

inline void Window::DrawSprite(const Rect<i32>& dst, const Sprite& sprite, const Flip& flip, const std::array<Color, 4>& colors)
{
    DrawSprite(dst, sprite.GetRect(), sprite, flip, colors);
}

inline void Window::DrawSprite(const Rect<i32>& dst, const Rect<i32>& src, const Sprite& sprite, const Flip& flip, const std::array<Color, 4>& colors)
{
    if(dst.size.x == 0 || dst.size.y == 0 || src.size.x == 0 || src.size.y == 0) return;    
    const vec2 scale = (vec2)dst.size / src.size;
    const ivec2 p = {flip & Flip::Horizontal ? -1 : 1, flip & Flip::Vertical ? -1 : 1};
    const ivec2 d = {dst.pos.x + (flip & Flip::Horizontal ? dst.size.x : 0), dst.pos.y + (flip & Flip::Vertical ? dst.size.y : 0)};
    const dvec2 step = 1.0 / dst.size;
    for(i32 x = 0; x < dst.size.x; x++)
        for(i32 y = 0; y < dst.size.y; y++)
        {
            const ivec2 pos = {x, y};
            const vec2 o = Floor(pos / scale);
            SetPixel(d + pos * p, sprite.GetPixel(src.pos.x + o.x, src.pos.y + o.y) *
                Lerp(Lerp(colors[0], colors[3], y * step.y), Lerp(colors[1], colors[2], y * step.y), x * step.x));
        }
}

inline void Window::DrawCharacter(i32 x, i32 y, char c, const Flip& flip, f32 sx, f32 sy, const Color& color, f32 ox, f32 oy)
{
    DrawCharacter({{x - g_kDefaultFontSize.x * sx * ox, y - g_kDefaultFontSize.y * sy * oy}, {GetHorizontalCharSize(c, sx), sy * g_kDefaultFontSize.y}}, c, flip, color);
}

inline void Window::DrawCharacter(Transform<f32>& transform, char c, const Flip& flip, const Color& color, f32 ox, f32 oy)
{
    const vec2 norm = {g_kDefaultFontSize.x * ox, g_kDefaultFontSize.y * oy};
    const vec2 inv = {g_kDefaultFontSize.x * (1.0f - ox), g_kDefaultFontSize.y * (1.0f - oy)};
    vec2 start, end, p;
    p = start = transform.Forward(-norm);
    start = Min(p, start); end = Max(p, end);
    p = transform.Forward(inv);
    start = Min(p, start); end = Max(p, end);
    p = transform.Forward(-norm.w, inv.h);
    start = Min(p, start); end = Max(p, end);
    p = transform.Forward(inv.w, -norm.h);
    start = Min(p, start); end = Max(p, end);
    transform.Invert();
    if(end.x < start.x) std::swap(end.x, start.x);
    if(end.y < start.y) std::swap(end.y, start.y);
    for(f32 i = start.x; i < end.x; ++i)
        for(f32 j = start.y; j < end.y; ++j)
        {
            const vec2 o = transform.Backward(i, j);
            const i32 u = flip & Flip::Horizontal ? norm.w + Floor(o.x) : inv.w - Ceil(o.x);
            const i32 v = flip & Flip::Vertical ? norm.h + Floor(o.y) : inv.h - Ceil(o.y);
            if(Rect<i32>{ivec2::Zero(), g_kDefaultFontSize - 1}.Contains(u, v) && g_kDefaultFontData[(int)c - 32][v] & (1 << u))
                SetPixel(i, j, color);
        }
}

inline void Window::DrawText(i32 x, i32 y, const std::string& text, const Flip& flip, f32 sx, f32 sy, const Color& color, f32 ox, f32 oy)
{
    const vec2 size = GetStringSize(text, sx, sy);
    DrawText({{x - size.x * ox, y - size.y * oy}, size}, text, flip, color);
}

inline void Window::DrawCharacter(const Rect<i32>& dst, char c, const Flip& flip, const Color& color)
{
    if(dst.size.x == 0 || dst.size.y == 0 || std::isspace(c)) return;
    const vec2 scale = (vec2)dst.size / g_kDefaultFontSize;
    const ivec2 p = {flip & Flip::Horizontal ? 1 : -1, flip & Flip::Vertical ? 1 : -1};
    const ivec2 d = {dst.pos.x + (flip & Flip::Horizontal ? 0 : dst.size.x), dst.pos.y + (flip & Flip::Vertical ? 0 : dst.size.y)};
    for(i32 x = 0; x < dst.size.x; x++)
        for(i32 y = 0; y < dst.size.y; y++)
        {
            const vec2 pos = {x, y};
            const ivec2 o = Floor(pos / scale);
            if(g_kDefaultFontData[(int)c - 32][o.y] & (1 << o.x))
                SetPixel(d + pos * p, color);
        }
}

inline void Window::DrawCharacter(i32 x, i32 y, char c, const Flip& flip, f32 rotation, f32 sx, f32 sy, const Color& color, f32 ox, f32 oy)
{
    if(std::isspace(c)) return;
    if(NotRotated(rotation)) return DrawCharacter(x, y, c, flip, sx, sy, color, ox, oy);
    Transform<f32> transform;
    transform.Translate(x, y);
    transform.Rotate(rotation);
    transform.Scale(sx, sy);
    DrawCharacter(transform, c, flip, color, ox, oy);
}

inline void Window::DrawText(i32 x, i32 y, const std::string& text, const Flip& flip, f32 rotation, f32 sx, f32 sy, const Color& color, f32 ox, f32 oy)
{
    if(text.empty()) return;
    if(NotRotated(rotation)) return DrawText(x, y, text, flip, sx, sy, color, ox, oy);
    Transform<f32> transform;
    transform.Translate(x, y);
    transform.Rotate(rotation);
    transform.Scale(sx, sy);
    DrawText(transform, text, flip, color, ox, oy);
}

inline void Window::DrawText(Transform<f32>& transform, const std::string& text, const Flip& flip, const Color& color, f32 ox, f32 oy)
{
    if(text.empty()) return;
    transform.Invert();
    vec2 pos = vec2::Zero();
    auto drawCharacter = [this, &pos, &transform, &color, &flip](char c) -> void
    {
        if(std::isspace(c)) return;
        const Rect<f32> dst = Rect<f32>{vec2::Zero(), g_kDefaultFontSize}.Transform(transform);
        for(f32 i = 0; i < dst.size.x; ++i)
            for(f32 j = 0; j < dst.size.y; ++j)
            {
                const vec2 o = transform.Backward(dst.pos.x + i, dst.pos.y + j);
                const i32 u = flip & Flip::Horizontal ? Floor(o.x) : g_kDefaultFontSize.x - Ceil(o.x);
                const i32 v = flip & Flip::Vertical ? Floor(o.y) : g_kDefaultFontSize.y - Ceil(o.y);
                if(Rect<i32>{ivec2::Zero(), g_kDefaultFontSize - 1}.Contains(u, v) && g_kDefaultFontData[(int)c - 32][v] & (1 << u))
                    SetPixel(dst.pos.x + pos.x + i, dst.pos.y + pos.y + j, color);
            }
    };
    const vec2 scale = transform.GetScale();
    const vec2 size = GetStringSize(text, scale);
    const vec2 v = GetVectorFromAngle(transform.GetRotation());
    const ivec2 d = {flip & Flip::Horizontal ? -1 : 1, flip & Flip::Vertical ? -1 : 1};
    const vec2 s = g_kDefaultFontSize * scale;
    vec2 p = pos = Rotate(transform.GetRotation(), flip & Flip::Horizontal ? size.x - s.x : 0, flip & Flip::Vertical ? size.y - s.y : 0, size.x * ox, size.y * oy);
    for(char c : text)
    {
        drawCharacter(c);
        if(c == '\n')
            pos = p += v.Perp() * (g_kDefaultFontSize.y + 1) * scale.h * d.y;
        else if(c == '\v')
            pos = p += v.Perp() * g_kDefaultVerticalTabSpace * scale.h * d.y;
        else
            pos += v * GetHorizontalCharSize(c, scale.w) * d.x;
    }
}

inline void Window::DrawText(Transform<f32>& transform, const std::string& text, const Flip& flip, const Color& color, const vec2& origin)
{
    DrawText(transform, text, flip, color, origin.x, origin.y);
}

inline void Window::DrawText(const Rect<i32>& dst, const std::string& text, const Flip& flip, const Color& color)
{
    if(dst.size.x == 0 || dst.size.y == 0 || text.empty()) return;
    const vec2 scale = (vec2)dst.size / GetStringSize(text, vec2::One());
    const vec2 s = g_kDefaultFontSize * scale;
    const ivec2 d = {flip & Flip::Horizontal ? -1 : 1, flip & Flip::Vertical ? -1 : 1};
    const vec2 p = vec2{dst.pos.x + (flip & Flip::Horizontal ? dst.size.x - s.x : 0), dst.pos.y + (flip & Flip::Vertical ? dst.size.y - s.y : 0)};
    vec2 pos = p;
    for(char c : text)
    {
        DrawCharacter({pos, s}, c, flip, color);
        if(c == '\n')
        {
            pos.y += (g_kDefaultFontSize.y + 1) * scale.h * d.y;
            pos.x = p.x;
        }
        else if(c == '\v')
        {
            pos.y += g_kDefaultVerticalTabSpace * scale.h * d.y;
            pos.x = p.x;
        }
        else
            pos.x += GetHorizontalCharSize(c, scale.w) * d.x;
    }
}

Sprite Window::CreateLabelFromText(const std::string& text, const Flip& flip, const vec2& scale, const Color& color, const Color& colBackground)
{
    const vec2 size = GetStringSize(text, scale);
    Sprite res = Sprite(size);
    auto drawCharacter = [&res, &color, &flip](const Rect<i32>& dst, char c) -> void
    {
        if(dst.size.x == 0 || dst.size.y == 0 || std::isspace(c)) return;
        const vec2 scale = (vec2)dst.size / g_kDefaultFontSize;
        const ivec2 p = {flip & Flip::Horizontal ? 1 : -1, flip & Flip::Vertical ? 1 : -1};
        const ivec2 d = {dst.pos.x + (flip & Flip::Horizontal ? 0 : dst.size.x), dst.pos.y + (flip & Flip::Vertical ? 0 : dst.size.y)};
        for(i32 x = 0; x < dst.size.x; x++)
            for(i32 y = 0; y < dst.size.y; y++)
            {
                const vec2 pos = {x, y};
                const ivec2 o = Floor(pos / scale);
                if(g_kDefaultFontData[(int)c - 32][o.y] & (1 << o.x))
                    res.SetPixel(d + pos * p, color);
            }
    };
    res.Clear(colBackground);
    const vec2 s = g_kDefaultFontSize * scale;
    const ivec2 d = {flip & Flip::Horizontal ? -1 : 1, flip & Flip::Vertical ? -1 : 1};
    const vec2 p = {flip & Flip::Horizontal ? size.x - s.x : 0, flip & Flip::Vertical ? size.y - s.y : 0};
    vec2 pos = p;
    for(char c : text)
    {
        drawCharacter({pos, s}, c);
        if(c == '\n')
        {
            pos.y += (g_kDefaultFontSize.y + 1) * scale.h * d.y;
            pos.x = p.x;
        }
        else if(c == '\v')
        {
            pos.y += g_kDefaultVerticalTabSpace * scale.h * d.y;
            pos.x = p.x;
        }
        else
            pos.x += GetHorizontalCharSize(c, scale.w) * d.x;
    }
    return res;
}

inline void Window::SetPixel(const ivec2& pos, const Color& color)
{
    SetPixel(pos.x, pos.y, color);
}

inline void Window::SetAntiAliasedPixel(const ivec2& pos, const Color& color)
{
    SetAntiAliasedPixel(pos.x, pos.y, color);
}

inline const Color& Window::GetPixel(const ivec2& pos) const
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

inline void Window::DrawRectOutline(const ivec2& pos, const ivec2& size, const Color& color, f32 angle, f32 width, const vec2& origin)
{
    DrawRectOutline(pos.x, pos.y, size.w, size.h, color, angle, width, origin.x, origin.y);
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

inline void Window::DrawSprite(const ivec2& pos, const Sprite& sprite, const vec2& scale, const Flip& flip, const vec2& origin, const std::array<Color, 4>& colors)
{
    DrawSprite(pos.x, pos.y, sprite, scale.x, scale.y, flip, origin.x, origin.y, colors);
}

inline void Window::DrawSprite(const ivec2& pos, const Rect<i32>& src, const Sprite& sprite, const vec2& scale, const Flip& flip, const vec2& origin, const std::array<Color, 4>& colors)
{
    DrawSprite(pos.x, pos.y, src, sprite, scale.x, scale.y, flip, origin.x, origin.y, colors);
}

inline void Window::DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Rect<i32>& src, const Flip& flip, const vec2& origin, const std::array<Color, 4>& colors)
{
    DrawSprite(sprite, transform, src, flip, origin.x, origin.y, colors);
}

inline void Window::DrawSprite(const Sprite& sprite, Transform<f32>& transform, const Flip& flip, const vec2& origin, const std::array<Color, 4>& colors)
{
    DrawSprite(sprite, transform, sprite.GetRect(), flip, origin.x, origin.y, colors);
}

inline void Window::DrawCharacter(const ivec2& pos, char c, const Flip& flip, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawCharacter(pos.x, pos.y, c, flip, scale.x, scale.y, color, origin.x, origin.y);
}

inline void Window::DrawCharacter(const ivec2& pos, char c, const Flip& flip, f32 rotation, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawCharacter(pos.x, pos.y, c, flip, rotation, scale.x, scale.y, color, origin.x, origin.y);
}

inline void Window::DrawCharacter(Transform<f32>& transform, char c, const Flip& flip, const Color& color, const vec2& origin)
{
    DrawCharacter(transform, c, flip, color, origin.x, origin.y);
}

inline void Window::DrawText(const ivec2& pos, const std::string& text, const Flip& flip, f32 rotation, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawText(pos.x, pos.y, text, flip, rotation, scale.x, scale.y, color, origin.x, origin.y);
}

inline void Window::DrawText(const ivec2& pos, const std::string& text, const Flip& flip, const vec2& scale, const Color& color, const vec2& origin)
{
    DrawText(pos.x, pos.y, text, flip, scale.x, scale.y, color, origin.x, origin.y);
}

inline void Window::DrawSkybox()
{
    if(!m_skyboxCubeMap) return;
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_FALSE);
    SetShader(5);
    m_skyboxVAO.Bind();
    glDrawArrays(GL_POINTS, 0, 1);
    m_skyboxVAO.Unbind();
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
}

#endif