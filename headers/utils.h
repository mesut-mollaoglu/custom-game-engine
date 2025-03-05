#ifndef UTILS_H
#define UTILS_H

using steady_clock = std::chrono::steady_clock;
using time_point = std::chrono::time_point<steady_clock>;
using key_type = std::variant<size_t, std::string>;

template <typename T>
struct type_identity {using type = T;};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

template <typename... V>
struct all_arithmetic : std::conjunction<std::is_arithmetic<V>...> {};

template <typename... V>
inline constexpr bool all_arithmetic_v = all_arithmetic<V...>::value;

template <typename T, typename U>
struct are_same_tpl : std::is_same<T, U> {};

template <template <typename> typename T, typename TL, typename TR>
struct are_same_tpl<T<TL>, T<TR>> : std::true_type {};

template <template <typename, size_t> typename T, typename TL, size_t UL, typename TR, size_t UR>
struct are_same_tpl<T<TL, UL>, T<TR, UR>> : std::true_type {};

template <template <typename, typename> typename T, typename TL, typename UL, typename TR, typename UR>
struct are_same_tpl<T<TL, UL>, T<TR, UR>> : std::true_type {};

template<typename, typename = std::void_t<>>
struct has_const_iterator : std::false_type {};

template <typename T>
struct has_const_iterator<T, std::void_t<typename T::const_iterator>> 
: std::true_type {};

template <typename T>
inline constexpr bool has_const_iterator_v = has_const_iterator<T>::value;

template <typename T>
struct has_begin_end
{
    template <typename, typename = std::void_t<>>
    struct has_begin : std::false_type {};
    template <typename U>
    struct has_begin<U, typename std::enable_if_t<
    std::is_same_v<decltype(static_cast<typename U::const_iterator(U::*)() const>(&U::begin)),
        typename U::const_iterator(U::*)() const>, void>> : std::true_type {};
    template <typename, typename = std::void_t<>>
    struct has_end : std::false_type {};
    template <typename U>
    struct has_end<U, typename std::enable_if_t<
    std::is_same_v<decltype(static_cast<typename U::const_iterator(U::*)() const>(&U::end)),
        typename U::const_iterator(U::*)() const>, void>> : std::true_type {};
    static inline constexpr bool value = has_begin<T>::value && has_end<T>::value;
};

template <typename T>
inline constexpr bool has_begin_end_v = has_begin_end<T>::value;

template<typename T> 
struct is_container : std::conjunction<has_const_iterator<T>, has_begin_end<T>> {};

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

template <template <typename> class Container, typename T>
inline T RandomIndex(
    const Container<T>& container,
    typename std::enable_if_t<is_container_v<Container<T>>>* = 0)
{
    return container[rand(0ull, container.size())];
}

template <typename T>
inline void safe_delete(T* x)
{
    delete x;
    x = NULL;
}

inline constexpr void* 
cmemmove(void* dst, const void* src, const size_t& len)
{
    if((uintptr_t)dst % sizeof(long) == 0 &&
        (uintptr_t)src % sizeof(long) == 0 &&
        len % sizeof(long) == 0)
    {
        long* d = (long*)dst;
        const long* s = (const long*)src;
        const size_t l = len / sizeof(long);
        if(d < s)
            for(size_t i = 0; i < l; i++)
                *(d + i) = *(s + i);
        else
        {
            long* ld = d + l - 1;
            const long* ls = s + l - 1;
            for(size_t i = 0; i < l; i++)
                *(ld - i) = *(ls - i);
        }
        return dst;
    }
    char* d = (char*)dst;
    const char* s = (const char*)src;
    if(d < s)
        for(size_t i = 0; i < len; i++)
            *(d + i) = *(s + i);
    else
    {
        char* ld = d + len - 1;
        const char* ls = s + len - 1;
        for(size_t i = 0; i < len; i++)
            *(ld - i) = *(ls - i);
    }
    return dst;
}

inline constexpr void*
cmemset(void* dst, unsigned char b, const size_t& len)
{
    if((uintptr_t)dst % sizeof(unsigned long) == 0 &&
        len % sizeof(unsigned long) == 0)
    {
        unsigned long* d = (unsigned long*)dst;
        const size_t s = sizeof(unsigned long) / sizeof(unsigned char);
        union {unsigned long l; unsigned char c[s];} u = {0ul};
        for(size_t i = 0; i < s; i++) u.c[i] = b;
        const size_t l = len / sizeof(unsigned long);
        for(size_t i = 0; i < l; i++)
            *(d + i) = u.l;
        return dst;
    }
    unsigned char* d = (unsigned char*)dst;
    for(size_t i = 0; i < len; i++)
        *(d + i) = b;
    return dst;
}

inline constexpr void* 
cmemcpy(void* dst, const void* src, const size_t& len)
{
    if((uintptr_t)dst % sizeof(long) == 0 && 
        (uintptr_t)src % sizeof(long) == 0 &&
        len % sizeof(long) == 0)
    {
        long* d = (long*)dst;
        const long* s = (const long*)src;
        for(size_t i = 0; i < len / sizeof(long); i++)
            *(d + i) = *(s + i);
        return dst;
    }
    char* d = (char*)dst;
    const char* s = (const char*)src;
    for(size_t i = 0; i < len; i++)
        *(d + i) = *(s + i);
    return dst;
}

template <typename T>
inline constexpr T reverse_bytes(const T& v)
{
    constexpr size_t s = sizeof(T);
    union {T d; unsigned char b[s];} dst, src = {v};
    for(size_t i = 0; i < s; i++)
        dst.b[i] = src.b[s - i - 1];
    return dst.d;
}

template <>
inline constexpr uint32_t reverse_bytes(const uint32_t& v)
{
    return (((v >> 0) & 0xFF) << 24) |
           (((v >> 8) & 0xFF) << 16) |
           (((v >> 16) & 0xFF) << 8) |
           (((v >> 24) & 0xFF) << 0);
}

template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T max()
{
    return std::numeric_limits<T>::max();
}

template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T min()
{
    return std::numeric_limits<T>::min();
}

#endif