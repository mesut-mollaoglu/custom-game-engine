#ifndef UTILS_HPP
#define UTILS_HPP

#define STR_HELPER(L) #L
#define STR(L) STR_HELPER(L)
#define UNICODE_STR(L) L##STR_HELPER(L)

#define DEFINE_LOG_ENUM                               \
BEGIN_ENUM(Error)                                     \
{                                                     \
    DECLARE_ENUM_ELEMENT(Error, Fatal),               \
    DECLARE_ENUM_ELEMENT(Error, InvalidShader),       \
    DECLARE_ENUM_ELEMENT(Error, Unitialized),         \
    DECLARE_ENUM_ELEMENT(Error, UnableToCreateTexture)\
};                                                    \

#define DEFINE_WARNING_ENUM                    \
BEGIN_ENUM(Warning)                            \
{                                              \
    DECLARE_ENUM_ELEMENT(Warning, Placeholder) \
};                                             \

#define BEGIN_ENUM(ENUM_NAME) enum class ENUM_NAME : u8
#define DECLARE_ENUM_ELEMENT(ENUM_NAME, ENUM_ELEMENT) ENUM_ELEMENT

class Logger
{
public:
    DEFINE_LOG_ENUM
    DEFINE_WARNING_ENUM
private:
    static inline constexpr std::string_view s_kDefaultErrorCode = "Error Code Not Found";
#undef BEGIN_ENUM
#undef DECLARE_ENUM_ELEMENT
#define DECLARE_ENUM_ELEMENT(ENUM_NAME, ENUM_ELEMENT) {ENUM_NAME::ENUM_ELEMENT, STR(ENUM_NAME::ENUM_ELEMENT)}
#define BEGIN_ENUM(ENUM_NAME) public: static inline const std::string_view& GetString(const ENUM_NAME& e)        \
{return s_kMap##ENUM_NAME##ElementNames.count(e) ? s_kMap##ENUM_NAME##ElementNames.at(e) : s_kDefaultErrorCode;} \
private: const static inline std::unordered_map<ENUM_NAME, std::string_view> s_kMap##ENUM_NAME##ElementNames =   
DEFINE_LOG_ENUM
DEFINE_WARNING_ENUM
};

#define LOG(CONDITION, ERROR, MESSAGE) if(!(CONDITION))   \
{std::cout << Logger::GetString(ERROR) << ": " << MESSAGE \
<< ", Line " << __LINE__ << ", File " << __FILE__ << ".\n";}

template <typename T>
struct is_char : std::disjunction<
    std::is_same<std::remove_cv_t<T>, char>,
    std::is_same<std::remove_cv_t<T>, wchar_t>,
    std::is_same<std::remove_cv_t<T>, c16>,
    std::is_same<std::remove_cv_t<T>, c32>
#if __cplusplus >= 202002L
    , std::is_same<std::remove_cv_t<T>, c8>
#endif
> {};

template <typename T>
inline constexpr bool is_char_v = is_char<T>::value;

template <typename CharT, typename... Args>
struct Format
{
private:
    std::basic_string<CharT> m_str;
public:
    template <typename T, typename = std::enable_if_t<std::is_convertible_v<T, std::basic_string_view<CharT>>>>
    inline Format(const T& s, const Args&... args)
    {
        return;
    }
    inline Format(const Format& f) = default;
    inline Format(Format&& f) = default;
    inline Format& operator=(const Format& f) = default;
    inline Format& operator=(Format&& f) = default;
public:
    inline const CharT* GetAddressOf() const
    {
        return &m_str[0];
    }
    inline CharT* GetAddressOf()
    {
        return &m_str[0];
    }
public:
    inline friend std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& os, const Format<CharT>& f)
    {
        return os << f.GetAddressOf();
    }
public:
    inline operator std::basic_string<CharT>() const
    {
        return m_str;
    }
    inline operator std::basic_string_view<CharT>() const
    {
        return std::basic_string_view<CharT>(this->GetAddressOf());
    }
};

#define DEFINE_ENUM_OPERATORS(ENUM_NAME)                                                                 \
template <typename T = std::underlying_type_t<ENUM_NAME>,                                                \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, T>                                          \
operator&(const ENUM_NAME& lhs, const std::underlying_type_t<ENUM_NAME>& rhs)                            \
{                                                                                                        \
    return static_cast<T>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) & rhs);                    \
}                                                                                                        \
template <typename T = ENUM_NAME,                                                                        \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, T>                                          \
operator|(const ENUM_NAME& lhs, const std::underlying_type_t<ENUM_NAME>& rhs)                            \
{                                                                                                        \
    return static_cast<T>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) | rhs);                    \
}                                                                                                        \
template <typename T = std::underlying_type_t<ENUM_NAME>,                                                \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, T>                                          \
operator&(const std::underlying_type_t<ENUM_NAME>& lhs, const ENUM_NAME& rhs)                            \
{                                                                                                        \
    return static_cast<T>(lhs & static_cast<std::underlying_type_t<ENUM_NAME>>(rhs));                    \
}                                                                                                        \
template <typename T = ENUM_NAME,                                                                        \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, T>                                          \
operator|(const std::underlying_type_t<ENUM_NAME>& lhs, const ENUM_NAME& rhs)                            \
{                                                                                                        \
    return static_cast<T>(lhs | static_cast<std::underlying_type_t<ENUM_NAME>>(rhs));                    \
}                                                                                                        \
template <typename T = std::underlying_type_t<ENUM_NAME>,                                                \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, T>                                          \
operator&(const ENUM_NAME& lhs, const ENUM_NAME& rhs)                                                    \
{                                                                                                        \
    return static_cast<T>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) &                          \
        static_cast<std::underlying_type_t<ENUM_NAME>>(rhs));                                            \
}                                                                                                        \
template <typename T = ENUM_NAME,                                                                        \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, T>                                          \
operator|(const ENUM_NAME& lhs, const ENUM_NAME& rhs)                                                    \
{                                                                                                        \
    return static_cast<T>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) |                          \
        static_cast<std::underlying_type_t<ENUM_NAME>>(rhs));                                            \
}                                                                                                        \
template <typename U, typename T = std::underlying_type_t<ENUM_NAME>,                                    \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME> && std::is_integral_v<U>, T>                 \
operator<<(const ENUM_NAME& lhs, const U& rhs)                                                           \
{                                                                                                        \
    return static_cast<T>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) << rhs);                   \
}                                                                                                        \
template <typename U, typename T = std::underlying_type_t<ENUM_NAME>,                                    \
typename = std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, ENUM_NAME>>>                      \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME> && std::is_integral_v<U>, T>                 \
operator>>(const ENUM_NAME& lhs, const U& rhs)                                                           \
{                                                                                                        \
    return static_cast<T>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) >> rhs);                   \
}                                                                                                        \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, std::add_lvalue_reference_t<ENUM_NAME>>     \
operator|=(ENUM_NAME& lhs, const std::underlying_type_t<ENUM_NAME>& rhs)                                 \
{                                                                                                        \
    return lhs = static_cast<ENUM_NAME>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) | rhs);      \
}                                                                                                        \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, std::add_lvalue_reference_t<ENUM_NAME>>     \
operator&=(ENUM_NAME& lhs, const std::underlying_type_t<ENUM_NAME>& rhs)                                 \
{                                                                                                        \
    return lhs = static_cast<ENUM_NAME>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) & rhs);      \
}                                                                                                        \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, std::add_lvalue_reference_t<ENUM_NAME>>     \
operator|=(ENUM_NAME& lhs, const ENUM_NAME& rhs)                                                         \
{                                                                                                        \
    return lhs = static_cast<ENUM_NAME>(                                                                 \
        static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) |                                            \
        static_cast<std::underlying_type_t<ENUM_NAME>>(rhs));                                            \
}                                                                                                        \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, std::add_lvalue_reference_t<ENUM_NAME>>     \
operator&=(ENUM_NAME& lhs, const ENUM_NAME& rhs)                                                         \
{                                                                                                        \
    return lhs = static_cast<ENUM_NAME>(                                                                 \
        static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) &                                            \
        static_cast<std::underlying_type_t<ENUM_NAME>>(rhs));                                            \
}                                                                                                        \
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>                                \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, std::add_lvalue_reference_t<ENUM_NAME>>     \
operator<<=(ENUM_NAME& lhs, const T& rhs)                                                                \
{                                                                                                        \
    return lhs = static_cast<ENUM_NAME>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) << rhs);     \
}                                                                                                        \
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>                                \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, std::add_lvalue_reference_t<ENUM_NAME>>     \
operator>>=(ENUM_NAME& lhs, const T& rhs)                                                                \
{                                                                                                        \
    return lhs = static_cast<ENUM_NAME>(static_cast<std::underlying_type_t<ENUM_NAME>>(lhs) >> rhs);     \
}                                                                                                        \
inline constexpr std::enable_if_t<std::is_enum_v<ENUM_NAME>, ENUM_NAME> operator~(const ENUM_NAME& lhs)  \
{                                                                                                        \
    return static_cast<ENUM_NAME>(~static_cast<std::underlying_type_t<ENUM_NAME>>(lhs));                 \
}                                                                                                        \

//for std::visit
template<typename... Ts>
struct overloads : Ts... { using Ts::operator()...; };

template <typename T>
struct type_identity {using type = T;};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

template <typename... Ts>
struct are_arithmetic : std::conjunction<std::is_arithmetic<Ts>...> {};

template <typename... Ts>
inline constexpr bool are_arithmetic_v = are_arithmetic<Ts...>::value;

template <typename T, typename... Ts>
struct are_same : std::conjunction<std::is_same<T, Ts>...> {};

template <typename T, typename... Ts>
inline constexpr bool are_same_v = are_same<T, Ts...>::value;

template <typename T, typename... Ts>
struct are_convertible : std::conjunction<std::is_convertible<T, Ts>...> {};

template <typename T, typename... Ts>
inline constexpr bool are_convertible_v = are_convertible<T, Ts...>::value;

template <typename T, typename U>
struct are_templates_same : std::is_same<T, U> {};

template <template <typename> typename T, typename TL, typename TR>
struct are_templates_same<T<TL>, T<TR>> : std::true_type {};

template <template <typename, usize> typename T, typename TL, usize UL, typename TR, usize UR>
struct are_templates_same<T<TL, UL>, T<TR, UR>> : std::true_type {};

template <template <typename, typename> typename T, typename TL, typename UL, typename TR, typename UR>
struct are_templates_same<T<TL, UL>, T<TR, UR>> : std::true_type {};

template <typename T, typename U>
inline constexpr bool are_templates_same_v = are_templates_same<T, U>::value;

template <class T, typename = void>
struct inner_type {using type = T;};

template <class T>
struct inner_type<T, std::void_t<typename T::value_type>>
{using type = typename T::value_type;};

template <typename T>
using inner_type_t = typename inner_type<T>::type;

template <typename T, class C>
struct is_inner_type_same : std::is_same<inner_type_t<C>, T> {};

template <typename T, class C>
inline constexpr bool is_inner_type_same_v = is_inner_type_same<T, C>::value;

template <typename T, class... Ts>
struct are_inner_types_same : std::conjunction<std::is_same<T, inner_type_t<Ts>>...> {};

template <typename T, class... Ts>
inline constexpr bool are_inner_types_same_v = are_inner_types_same<T, Ts...>::value;

template <typename T, class C>
struct is_inner_type_convertible : std::is_convertible<inner_type_t<C>, T> {};

template <typename T, class C>
inline constexpr bool is_inner_type_convertible_v = is_inner_type_convertible<T, C>::value;

template <typename T, class... Ts>
struct are_inner_types_convertible : std::conjunction<std::is_convertible<T, inner_type_t<Ts>>...> {};

template <typename T, class... Ts>
inline constexpr bool are_inner_types_convertible_v = are_inner_types_convertible<T, Ts...>::value;

template <typename, typename = void>
struct is_contiguous : std::false_type {};

template <typename T>
struct is_contiguous<T, std::void_t<decltype(std::declval<T>().data())>> : std::true_type {};

template <typename T>
inline constexpr bool is_contiguous_v = is_contiguous<T>::value;

template <typename, typename = std::void_t<>>
struct has_const_iterator : std::false_type {};

template <typename T>
struct has_const_iterator<T, std::void_t<typename T::const_iterator>> : std::true_type {};

template <typename T>
inline constexpr bool has_const_iterator_v = has_const_iterator<T>::value;

template <typename, typename = std::void_t<>>
struct has_index_operator : std::false_type {};

template <typename T>
struct has_index_operator<T, std::void_t<decltype(std::declval<T>().operator[](usize()))>> : std::true_type {};

template <typename C>
inline constexpr bool has_index_operator_v = has_index_operator<C>::value;

template <typename... Ts>
inline constexpr bool are_elements_accessible_by_index_v = std::conjunction_v<has_index_operator<Ts>...>;

namespace Detail
{
    template <typename T>
    struct has_begin_end
    {
        template <typename, typename = std::void_t<>>
        struct has_begin : std::false_type {};
        template <typename U>
        struct has_begin<U, std::enable_if_t<
        std::is_same_v<decltype(static_cast<typename U::const_iterator(U::*)() const>(&U::begin)),
            typename U::const_iterator(U::*)() const>, void>> : std::true_type {};
        template <typename, typename = std::void_t<>>
        struct has_end : std::false_type {};
        template <typename U>
        struct has_end<U, std::enable_if_t<
        std::is_same_v<decltype(static_cast<typename U::const_iterator(U::*)() const>(&U::end)),
            typename U::const_iterator(U::*)() const>, void>> : std::true_type {};
        static inline constexpr bool value = has_begin<T>::value && has_end<T>::value;
    };
};

template <typename T>
inline constexpr bool has_begin_end_v = Detail::has_begin_end<T>::value;

template<typename T>
struct is_container : std::conjunction<has_const_iterator<T>, Detail::has_begin_end<T>> {};

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

template <typename... Ts>
struct are_containers : std::conjunction<is_container<Ts>...> {};

template <typename... Ts>
inline constexpr bool are_containers_v = are_containers<Ts...>::value;

template <typename, typename = void>
struct has_base : std::false_type {};

template <typename T>
struct has_base<T, std::void_t<decltype(std::declval<T>().base())>> : std::true_type {};

template <typename T>
inline constexpr bool has_base_v = has_base<T>::value;

namespace Random
{
    class Seed
    {
        friend class Impl;
    private:
        static u32 s_state;
        inline static constexpr u32 M = 2147483647u;
        inline static constexpr f32 F = 4294967295.0f;
    public:
        inline static void Set(const u32& s)
        {
            s_state = s;
        }
    };
    class Impl
    {
        friend class Seed;
    private:
        inline static u32 GenerateRandomNumber()
        {
            const u64 p = (u64)Seed::s_state * 48271;
            const u32 x = (p & Seed::M) + (p >> 31);
            return Seed::s_state = ((x & Seed::M) + (x >> 31));
        }
    public:
        template <typename T>
        inline static T Next(const T& lo, const T& hi)
        {
            return (hi - lo) * (static_cast<f32>(GenerateRandomNumber()) / Seed::F) + lo;
        }
    };
    template <typename T>
    inline T Next(const T& lo, const T& hi)
    {
        return Random::Impl::Next(lo, hi);
    }
    template <typename T>
    inline inner_type_t<T> InContainer(const T& x, std::enable_if_t<is_container_v<T> && has_index_operator_v<T>>* = 0)
    {
        return x[Next(0ull, x.size())];
    }
};

template <typename T>
inline void SafeDelete(T* x)
{
    if(x)
    {
        delete x;
        x = nullptr;
    }
}

template <typename T>
inline void SafeDeleteArray(T x[])
{
    if(x)
    {
        delete[] x;
        x = nullptr;
    }
}

template <typename T>
inline void SafeRelease(T* x, std::void_t<decltype(std::declval<T>().Release())>* = 0)
{
    if(x)
    {
        x->Release();
        x = nullptr;
    }
}

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
inline constexpr int GetSignificantDigitCount()
{
    if constexpr(std::is_same_v<T, float>)
        return 6;
    else if constexpr(std::is_same_v<T, double>)
        return 15;
    else if constexpr(std::is_same_v<T, long double>)
        return 18;
#if __cplusplus >= 202302L
    else if constexpr(std::is_same_v<T, std::float16_t>)
        return 3;
    else if constexpr(std::is_same_v<T, std::float32_t>)
        return 6;
    else if constexpr(std::is_same_v<T, std::float64_t>)
        return 15;
    else if constexpr(std::is_same_v<T, std::float128_t>)
        return 18;
    else if constexpr(std::is_same_v<T, std::bfloat16_t>)
        return 3;
#endif
    return 0;
}

template <typename T>
inline int GetGLIndexType()
{
    if constexpr(std::is_same_v<T, i8>)
        return GL_BYTE;
    else if constexpr(std::is_same_v<T, u8>)
        return GL_UNSIGNED_BYTE;
    else if constexpr(std::is_same_v<T, i16>)
        return GL_SHORT;
    else if constexpr(std::is_same_v<T, u16>)
        return GL_UNSIGNED_SHORT;
    else if constexpr(std::is_same_v<T, i32>)
        return GL_INT;
    else if constexpr(std::is_same_v<T, u32>)
        return GL_UNSIGNED_INT;
    return 0;
}

template <typename T>
inline constexpr T ReverseBytes(const T& value)
{
    constexpr usize s = sizeof(T);
    union {T d; u8 b[s];} dst, src = {value};
    for(usize i = 0; i < s; i++)
        dst.b[i] = src.b[s - i - 1];
    return dst.d;
}

template <>
inline constexpr u32 ReverseBytes(const u32& x)
{
    u32 res = 0u;
    res |= ((x >> 0) & 0xFF) << 24;
    res |= ((x >> 8) & 0xFF) << 16;
    res |= ((x >> 16) & 0xFF) << 8;
    res |= ((x >> 24) & 0xFF) << 0;
    return res;
}

template <typename T>
inline std::string_view ConvertToStringView(const T& x, std::enable_if_t<std::is_arithmetic_v<T>>* = 0)
{
    i32 n = std::floor(std::log10(x)) + 2 + (x >= T(0) ? 0 : 1);
    if constexpr(std::is_floating_point_v<T>)
        n += GetSignificantDigitCount<T>();
    char res[n];
    if constexpr(std::is_same_v<T, long double>)
        snprintf(res, n, "%Lf", x);
    else if constexpr(std::is_integral_v<T>)
        snprintf(res, n, "%d", x);
    else
        snprintf(res, n, "%f", x);
    return res;
}

namespace Detail
{
    using std::swap;
    template <typename T>
    struct would_call_std_swap_impl
    {
        struct tag {};
        template <typename U>
        tag swap(U&, U&);
        template <typename U>
        static inline constexpr std::integral_constant<bool, std::is_same_v<
        decltype(swap(std::declval<U&>(), std::declval<U&>())), tag>> check(int);
        template <typename>
        static inline constexpr std::false_type check(...);
        using type = decltype(check<T>(0));
    };
    template <typename T>
    struct would_call_std_swap : would_call_std_swap_impl<T>::type {};
    template <typename T>
    struct can_call_swap_impl
    {
        template <typename U>
        static inline constexpr decltype(std::swap(
            std::declval<U&>(), std::declval<U&>()), std::true_type()) check(int);
        template <typename>
        static inline constexpr std::false_type check(...);
        using type = decltype(check<T>(0));
    };
    template <typename T>
    struct can_call_swap : can_call_swap_impl<T>::type {};
};

template<typename T>
struct is_swappable : std::integral_constant<bool,
    Detail::can_call_swap<T>::value &&
    (!Detail::would_call_std_swap<T>::value ||
    (std::is_move_assignable<T>::value &&
    std::is_move_constructible<T>::value))> {};

template<typename T, usize N>
struct is_swappable<T[N]> : is_swappable<T> {};

template <typename T>
inline constexpr bool is_swappable_v = is_swappable<T>::value;

inline constexpr void* MoveMemory(void* dst, const void* src, const usize& len)
{
    if((uptr)dst % sizeof(long) == 0 &&
        (uptr)src % sizeof(long) == 0 &&
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

inline constexpr void* SetMemory(void* dst, unsigned char b, const usize& len)
{
    if((uptr)dst % sizeof(unsigned long) == 0 &&
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

inline constexpr void* CopyMemory(void* dst, const void* src, const usize& len)
{
    if((uptr)dst % sizeof(long) == 0 && 
        (uptr)src % sizeof(long) == 0 &&
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

#endif

#ifdef UTILS_HPP
#undef UTILS_HPP

u32 Random::Seed::s_state;

#endif