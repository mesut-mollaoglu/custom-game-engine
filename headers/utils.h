#ifndef UTILS_H
#define UTILS_H

template <typename T>
inline constexpr T reverse_bytes(const T& input)
{
    constexpr size_t size = sizeof(T);
    union { T data; uint8_t bytes[size]; } src, dst;
    src.data = input;
    for(size_t i = 0; i < size; i++)
        dst.bytes[i] = src.bytes[size - i - 1];
    return dst.data;
}

template <>
inline constexpr uint32_t reverse_bytes(const uint32_t& input)
{
    return (((input >> 0) & 0xFF) << 24) |
           (((input >> 8) & 0xFF) << 16) |
           (((input >> 16) & 0xFF) << 8) |
           (((input >> 24) & 0xFF) << 0);
}

inline constexpr vec3 rgb_to_hsv(const vec3& rgb)
{
    vec3 res;
    const float cmax = max(rgb);
    const float cmin = min(rgb);
    if(cmax == cmin)
        return {0.0f, 0.0f, cmax * 100.0f};
    const float delta = cmax - cmin;
    if(cmax == rgb.r)
        res.h = mod((rgb.g - rgb.b) / delta, 6.0f);
    else if(cmax == rgb.g)
        res.h = (rgb.b - rgb.r) / delta + 2.0f;
    else
        res.h = (rgb.r - rgb.g) / delta + 4.0f;
    res.h *= 60.0f;
    res.s = (delta / cmax) * 100.0f;
    res.v = cmax * 100.0f;
    return res;
}

inline constexpr vec3 rgb_to_hsv_ub(const vec3ub& rgb)
{
    return rgb_to_hsv(rgb / 255.0f);
}

#endif