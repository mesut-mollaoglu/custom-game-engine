#ifndef FONT_LOADER_HPP
#define FONT_LOADER_HPP

inline void ReadBE8(i8* src, u8* dst, bool move = true)
{
    *dst = *src;
    if(move) ++src;
}

inline void ReadBE16(i8* src, u8* dst, bool move = true)
{
    dst[0] = src[0];
    dst[1] = src[1];
    if(move) src += 2;
}

inline void ReadBE32(i8* src, u8* dst, bool move = true)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    if(move) src += 4;
}

inline void ReadBE64(i8* src, u8* dst, bool move = true)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    if(move) src += 8;
}

inline void ReadLE8(i8* src, u8* dst, bool move = true)
{
    *dst = *src;
    if(move) ++src;
}

inline void ReadLE16(i8* src, u8* dst, bool move = true)
{
    dst[0] = src[1];
    dst[1] = src[0];
    if(move) src += 2;
}

inline void ReadLE32(i8* src, u8* dst, bool move = true)
{
    dst[0] = src[3];
    dst[1] = src[2];
    dst[2] = src[1];
    dst[3] = src[0];
    if(move) src += 4;
}

inline void ReadLE64(i8* src, u8* dst, bool move = true)
{
    dst[0] = src[7];
    dst[1] = src[6];
    dst[2] = src[5];
    dst[3] = src[4];
    dst[4] = src[3];
    dst[5] = src[2];
    dst[6] = src[1];
    dst[7] = src[0];
    if(move) src += 8;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
inline void ReadBEInteger(i8* src, T& dst, bool move = true)
{
    if constexpr(std::is_same_v<T, u8> || std::is_same_v<T, i8>)
        ReadBE8(src, reinterpret_cast<u8*>(&dst), move); 
    else if constexpr(std::is_same_v<T, u16> || std::is_same_v<T, i16>)
        ReadBE16(src, reinterpret_cast<u8*>(&dst), move);
    else if constexpr(std::is_same_v<T, u32> || std::is_same_v<T, i32>)
        ReadBE32(src, reinterpret_cast<u8*>(&dst), move);
    else if constexpr(std::is_same_v<T, u64> || std::is_same_v<T, i64>)
        ReadBE64(src, reinterpret_cast<u8*>(&dst), move);
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
inline void ReadLEInteger(i8* src, T& dst, bool move = true)
{
    if constexpr(std::is_same_v<T, u8> || std::is_same_v<T, i8>)
        ReadLE8(src, reinterpret_cast<u8*>(&dst), move); 
    else if constexpr(std::is_same_v<T, u16> || std::is_same_v<T, i16>)
        ReadLE16(src, reinterpret_cast<u8*>(&dst), move);
    else if constexpr(std::is_same_v<T, u32> || std::is_same_v<T, i32>)
        ReadLE32(src, reinterpret_cast<u8*>(&dst), move);
    else if constexpr(std::is_same_v<T, u64> || std::is_same_v<T, i64>)
        ReadLE64(src, reinterpret_cast<u8*>(&dst), move);
}

template <typename T, len_t N, typename = std::enable_if_t<std::is_integral_v<T>>>
inline void ReadBEVector(i8* src, Vector<T, N>& dst, bool move = true)
{
    for(len_t i = 0; i < N; i++)
        ReadBEInteger(src, dst[i], (i == N - 1 ? move : true));
}

template <typename T, len_t N, typename = std::enable_if_t<std::is_integral_v<T>>>
inline void ReadLEVector(i8* src, Vector<T, N>& dst, bool move = true)
{
    for(len_t i = 0; i < N; i++)
        ReadLEInteger(src, dst[i], (i == N - 1 ? move : true));
}

//TODO

#endif