#ifndef UTILS_H
#define UTILS_H

template <typename T>
struct type_identity {using type = T;};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

template <typename... V>
struct all_arithmetic : std::conjunction<std::is_arithmetic<V>...> {};

template <typename... V>
inline constexpr bool all_arithmetic_v = all_arithmetic<V...>::value;

template <typename T, typename... V>
inline constexpr bool all_same_v = std::conjunction_v<std::is_same<T, V>...>;

template <typename T, typename... V>
inline constexpr bool all_convertible_v = std::conjunction_v<std::is_convertible<T, V>...>;

template <typename T, typename U>
struct are_same_tpl : std::is_same<T, U> {};

template <template <typename> typename T, typename TL, typename TR>
struct are_same_tpl<T<TL>, T<TR>> : std::true_type {};

template <template <typename, usize> typename T, typename TL, usize UL, typename TR, usize UR>
struct are_same_tpl<T<TL, UL>, T<TR, UR>> : std::true_type {};

template <template <typename, typename> typename T, typename TL, typename UL, typename TR, typename UR>
struct are_same_tpl<T<TL, UL>, T<TR, UR>> : std::true_type {};

template <class T, typename = void>
struct inner_type {using type = T;};

template <class T>
struct inner_type<T, std::void_t<typename T::value_type>>
{using type = typename T::value_type;};

template <typename T>
using inner_type_t = typename inner_type<T>::type;

template <typename T, class C>
inline constexpr bool is_inner_type_same_v = std::is_same_v<inner_type_t<C>, T>;

template <typename T, class... V>
inline constexpr bool are_inner_types_same_v = std::conjunction_v<std::is_same<T, inner_type_t<V>>...>;

template <typename, typename = std::void_t<>>
struct has_const_iterator : std::false_type {};

template <typename T>
struct has_const_iterator<T, std::void_t<typename T::const_iterator>> 
: std::true_type {};

template <typename T>
inline constexpr bool has_const_iterator_v = has_const_iterator<T>::value;

template <typename, typename = std::void_t<>>
struct has_index_operator : std::false_type {};

template <typename T>
struct has_index_operator<T, std::void_t<decltype(std::declval<T>().operator[](usize()))>>
: std::true_type {};

template <typename C>
inline constexpr bool has_index_operator_v = has_index_operator<C>::value;

template <typename... V>
inline constexpr bool all_have_index_operators_v = std::conjunction_v<has_index_operator<V>...>;

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

template <typename... V>
inline constexpr bool all_container_v = std::conjunction_v<is_container<V>...>;

template <typename T> 
inline T random(const T& lo, const T& hi)
{
    return ((f64)rand() / (f64)RAND_MAX) * (hi - lo) + lo;
}

template <typename _ContainerT>
inline inner_type_t<_ContainerT> RandomIndex(
    const _ContainerT& container,
    typename std::enable_if_t<
        is_container_v<_ContainerT> &&
        has_index_operator_v<_ContainerT>>* = 0)
{
    return container[random<usize>(0, container.size())];
}

template <typename T>
inline void safe_delete(T* x)
{
    delete x;
    x = nullptr;
}

template <typename T>
inline void safe_release(T* x, std::void_t<decltype(std::declval<T>().Release())>* = 0)
{
    if(x)
    {
        x->Release();
        x = nullptr;
    }
}

inline constexpr void* 
cmemmove(void* dst, const void* src, const usize& len)
{
    if((uintptr_t)dst % sizeof(long) == 0 &&
        (uintptr_t)src % sizeof(long) == 0 &&
        len % sizeof(long) == 0)
    {
        long* d = (long*)dst;
        const long* s = (const long*)src;
        const usize l = len / sizeof(long);
        if(d < s)
            for(usize i = 0; i < l; i++)
                *(d + i) = *(s + i);
        else
        {
            long* ld = d + l - 1;
            const long* ls = s + l - 1;
            for(usize i = 0; i < l; i++)
                *(ld - i) = *(ls - i);
        }
        return dst;
    }
    char* d = (char*)dst;
    const char* s = (const char*)src;
    if(d < s)
        for(usize i = 0; i < len; i++)
            *(d + i) = *(s + i);
    else
    {
        char* ld = d + len - 1;
        const char* ls = s + len - 1;
        for(usize i = 0; i < len; i++)
            *(ld - i) = *(ls - i);
    }
    return dst;
}

inline constexpr void*
cmemset(void* dst, unsigned char b, const usize& len)
{
    if((uintptr_t)dst % sizeof(unsigned long) == 0 &&
        len % sizeof(unsigned long) == 0)
    {
        unsigned long* d = (unsigned long*)dst;
        const usize s = sizeof(unsigned long) / sizeof(unsigned char);
        union {unsigned long l; unsigned char c[s];} u = {0ul};
        for(usize i = 0; i < s; i++) u.c[i] = b;
        const usize l = len / sizeof(unsigned long);
        for(usize i = 0; i < l; i++)
            *(d + i) = u.l;
        return dst;
    }
    unsigned char* d = (unsigned char*)dst;
    for(usize i = 0; i < len; i++)
        *(d + i) = b;
    return dst;
}

inline constexpr void* 
cmemcpy(void* dst, const void* src, const usize& len)
{
    if((uintptr_t)dst % sizeof(long) == 0 && 
        (uintptr_t)src % sizeof(long) == 0 &&
        len % sizeof(long) == 0)
    {
        long* d = (long*)dst;
        const long* s = (const long*)src;
        for(usize i = 0; i < len / sizeof(long); i++)
            *(d + i) = *(s + i);
        return dst;
    }
    char* d = (char*)dst;
    const char* s = (const char*)src;
    for(usize i = 0; i < len; i++)
        *(d + i) = *(s + i);
    return dst;
}

template <typename T>
inline constexpr T reverse_bytes(const T& value)
{
    constexpr usize s = sizeof(T);
    union {T d; u8 b[s];} dst, src = {value};
    for(usize i = 0; i < s; i++)
        dst.b[i] = src.b[s - i - 1];
    return dst.d;
}

template <>
inline constexpr u32 reverse_bytes(const u32& value)
{
    u32 res = 0u;
    res |= ((value >> 0) & 0xFF) << 24;
    res |= ((value >> 8) & 0xFF) << 16;
    res |= ((value >> 16) & 0xFF) << 8;
    res |= ((value >> 24) & 0xFF) << 0;
    return res;
}

#endif