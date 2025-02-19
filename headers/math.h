#ifndef MATH_H
#define MATH_H

#ifdef USE_SIZE_T
typedef size_t len_t;
inline constexpr bool check_len(const len_t& len, const len_t& max)
{
    return len < max;
}
#else
typedef int len_t;
inline constexpr bool check_len(const len_t& len, const len_t& max)
{
    return len >= 0 && len < max;
}
#endif

#define swizzle2(x, y) \
Swizzle<T, 0, 1> x##y; \
Swizzle<T, 1, 0> y##x; \
Swizzle<T, 1, 1> y##y; \
Swizzle<T, 0, 0> x##x; \
Swizzle<T, 0, 1, 0> x##y##x; \
Swizzle<T, 0, 1, 1> x##y##y; \
Swizzle<T, 0, 0, 1> x##x##y; \
Swizzle<T, 0, 0, 0> x##x##x; \
Swizzle<T, 1, 1, 0> y##y##x; \
Swizzle<T, 1, 0, 1> y##x##y; \
Swizzle<T, 1, 1, 1> y##y##y; \
Swizzle<T, 1, 0, 0> y##x##x; \
Swizzle<T, 0, 0, 0, 0> x##x##x##x; \
Swizzle<T, 0, 0, 1, 1> x##x##y##y; \
Swizzle<T, 0, 0, 1, 0> x##x##y##x; \
Swizzle<T, 0, 0, 0, 1> x##x##x##y; \
Swizzle<T, 0, 1, 1, 0> x##y##y##x; \
Swizzle<T, 0, 1, 0, 0> x##y##x##x; \
Swizzle<T, 0, 1, 0, 1> x##y##x##y; \
Swizzle<T, 0, 1, 1, 1> x##y##y##y; \
Swizzle<T, 1, 0, 0, 0> y##x##x##x; \
Swizzle<T, 1, 0, 1, 0> y##x##y##x; \
Swizzle<T, 1, 0, 1, 1> y##x##y##y; \
Swizzle<T, 1, 1, 0, 0> y##y##x##x; \
Swizzle<T, 1, 1, 0, 1> y##y##x##y; \
Swizzle<T, 1, 1, 1, 0> y##y##y##x; \
Swizzle<T, 1, 1, 1, 1> y##y##y##y; \

#define swizzle3(x, y, z) \
Swizzle<T, 2, 1> z##y; \
Swizzle<T, 2, 0> z##x; \
Swizzle<T, 1, 2> y##z; \
Swizzle<T, 2, 2> z##z; \
Swizzle<T, 0, 2> x##z; \
Swizzle<T, 0, 1, 2> x##y##z; \
Swizzle<T, 0, 2, 1> x##z##y; \
Swizzle<T, 0, 2, 2> x##z##z; \
Swizzle<T, 1, 0, 2> y##x##z; \
Swizzle<T, 1, 2, 0> y##z##x; \
Swizzle<T, 1, 2, 2> y##z##z; \
Swizzle<T, 2, 0, 1> z##x##y; \
Swizzle<T, 2, 1, 0> z##y##x; \
Swizzle<T, 2, 0, 0> z##x##x; \
Swizzle<T, 2, 1, 1> z##y##y; \
Swizzle<T, 2, 1, 2> z##y##z; \
Swizzle<T, 0, 0, 1, 2> x##x##y##z; \
Swizzle<T, 0, 0, 2, 1> x##x##z##y; \
Swizzle<T, 0, 0, 2, 2> x##x##z##z; \
Swizzle<T, 0, 1, 2, 2> x##y##z##z; \
Swizzle<T, 0, 1, 1, 2> x##y##y##z; \
Swizzle<T, 0, 1, 2, 1> x##y##z##y; \
Swizzle<T, 0, 1, 0, 2> x##y##x##z; \
Swizzle<T, 0, 1, 2, 0> x##y##z##x; \
Swizzle<T, 0, 0, 2, 0> x##x##z##x; \
Swizzle<T, 0, 0, 0, 2> x##x##x##z; \
Swizzle<T, 1, 0, 1, 2> y##x##y##z; \
Swizzle<T, 2, 0, 1, 2> z##x##y##z; \
Swizzle<T, 2, 0, 0, 2> z##x##x##z; \
Swizzle<T, 1, 0, 0, 2> y##x##x##z; \
Swizzle<T, 1, 2, 1, 2> y##z##y##z; \
Swizzle<T, 2, 2, 1, 2> z##z##y##z; \
Swizzle<T, 2, 1, 2, 0> z##y##z##x; \
Swizzle<T, 2, 1, 0, 2> z##y##x##z; \
Swizzle<T, 2, 1, 2, 2> z##y##z##z; \
Swizzle<T, 2, 2, 2, 2> z##z##z##z; \

#define swizzle4(x, y, z, w) \
Swizzle<T, 0, 3> x##w; \
Swizzle<T, 1, 3> y##w; \
Swizzle<T, 2, 3> z##w; \
Swizzle<T, 3, 3> w##w; \
Swizzle<T, 3, 0> w##x; \
Swizzle<T, 3, 1> w##y; \
Swizzle<T, 3, 2> w##z; \
Swizzle<T, 3, 0, 1> w##x##y; \
Swizzle<T, 3, 1, 0> w##y##x; \
Swizzle<T, 3, 1, 1> w##y##y; \
Swizzle<T, 3, 0, 0> w##x##x; \
Swizzle<T, 3, 2, 0> w##z##x; \
Swizzle<T, 3, 0, 2> w##x##z; \
Swizzle<T, 3, 2, 2> w##z##z; \
Swizzle<T, 3, 1, 2> w##y##z; \
Swizzle<T, 3, 2, 1> w##z##y; \
Swizzle<T, 3, 3, 3> w##w##w; \
Swizzle<T, 3, 1, 3> w##y##w; \
Swizzle<T, 3, 3, 1> w##w##y; \
Swizzle<T, 3, 2, 3> w##z##w; \
Swizzle<T, 3, 3, 2> w##w##z; \
Swizzle<T, 1, 2, 3> y##z##w; \
Swizzle<T, 3, 0, 0, 0> w##x##x##x; \
Swizzle<T, 3, 0, 0, 1> w##x##x##y; \
Swizzle<T, 3, 0, 0, 2> w##x##x##z; \
Swizzle<T, 3, 0, 0, 3> w##x##x##w; \
Swizzle<T, 3, 0, 1, 0> w##x##y##x; \
Swizzle<T, 3, 0, 2, 0> w##x##z##x; \
Swizzle<T, 3, 0, 3, 0> w##x##w##x; \
Swizzle<T, 3, 1, 0, 0> w##y##x##x; \
Swizzle<T, 3, 1, 1, 0> w##y##y##x; \
Swizzle<T, 0, 0, 0, 3> x##x##x##w; \
Swizzle<T, 0, 1, 2, 3> x##y##z##w; \
Swizzle<T, 0, 1, 0, 3> x##y##x##w; \
Swizzle<T, 0, 1, 3, 3> x##y##w##w; \
Swizzle<T, 0, 1, 1, 3> x##y##y##w; \
Swizzle<T, 0, 2, 2, 3> x##z##z##w; \
Swizzle<T, 1, 1, 1, 3> y##y##y##w; \
Swizzle<T, 2, 2, 2, 3> z##z##z##w; \
Swizzle<T, 3, 3, 3, 3> w##w##w##w; \
Swizzle<T, 0, 0, 3, 3> x##x##w##w; \

using std::abs;
using std::floor;
using std::ceil;
using std::max;
using std::min;
using std::log;
using std::log10;
using std::log2;
using std::exp;

#define arithmetic_operator_test(T) true
#define logical_operator_test(T) std::is_same_v<T, bool>
#define bitwise_operator_test(T) std::is_integral_v<T>
#define unary_operator_args(_type) typename = typename std::enable_if_t<_type##_operator_test(T)>
#define binary_operator_args(_type) typename = typename std::enable_if_t<_type##_operator_test(T) && _type##_operator_test(U)>

#define binary_operator_helper(_operation, _type, _args, _size) \
len_t i = 0;                                                    \
_type<decltype(_operation), _args> res;                         \
for(; i < _size; i++)                                           \
    res[i] = _operation;                                        \
return res;                                                     \

#define assignment_operator_helper(_operation, _size) \
for(len_t i = 0; i < _size; i++)                      \
    _operation;                                       \
return lhs;                                           \

#define comparison_operator_helper_and(_condition, _size) \
for(len_t i = 0; i < _size; i++)                          \
    if(!(_condition))                                     \
        return false;                                     \
return true;                                              \

#define comparison_operator_helper_or(_condition, _size) \
for(len_t i = 0; i < _size; i++)                         \
    if(_condition)                                       \
        return true;                                     \
return false;                                            \

#define function_helper(_operation) \
Vector<T, N> res;                   \
for(len_t i = 0; i < N; i++)        \
    res[i] = _operation;            \
return res;                         \

#define vector_binary_operator_helper(_operation) binary_operator_helper(_operation, Vector, N, N)
#define swizzle_binary_operator_helper(_operation) binary_operator_helper(_operation, Swizzle, V..., len)

#define define_vector_binary_operator(_operator, _type)                                    \
template <typename T, typename U, len_t N, binary_operator_args(_type)>                    \
inline constexpr auto operator _operator(const Vector<T, N>& lhs, const U& rhs)            \
{                                                                                          \
    vector_binary_operator_helper(lhs[i] _operator rhs)                                    \
}                                                                                          \
template <typename T, typename U, len_t N, binary_operator_args(_type)>                    \
inline constexpr auto operator _operator(const T& lhs, const Vector<U, N>& rhs)            \
{                                                                                          \
    vector_binary_operator_helper(lhs _operator rhs[i])                                    \
}                                                                                          \
template <typename T, typename U, len_t N, binary_operator_args(_type)>                    \
inline constexpr auto operator _operator(const Vector<T, N>& lhs, const Vector<U, N>& rhs) \
{                                                                                          \
    vector_binary_operator_helper(lhs[i] _operator rhs[i])                                 \
}                                                                                          \

#define define_swizzle_binary_operator(_operator, _type)                                                  \
template <typename U, len_t... SW, typename = typename                                                    \
std::enable_if_t<sizeof...(SW) == len && _type##_operator_test(T) && _type##_operator_test(U)>>           \
inline friend constexpr auto operator _operator(const Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)\
{                                                                                                         \
    swizzle_binary_operator_helper(lhs[i] _operator rhs[i])                                               \
}                                                                                                         \
template <typename U, binary_operator_args(_type)>                                                        \
inline friend constexpr auto operator _operator(const Swizzle<T, V...>& lhs, const Vector<U, len>& rhs)   \
{                                                                                                         \
    swizzle_binary_operator_helper(lhs[i] _operator rhs[i])                                               \
}                                                                                                         \
template <typename U, binary_operator_args(_type)>                                                        \
inline friend constexpr auto operator _operator(const Vector<T, len>& lhs, const Swizzle<U, V...>& rhs)   \
{                                                                                                         \
    swizzle_binary_operator_helper(lhs[i] _operator rhs[i])                                               \
}                                                                                                         \
template <typename U, binary_operator_args(_type)>                                                        \
inline friend constexpr auto operator _operator(const Swizzle<T, V...>& lhs, const U& rhs)                \
{                                                                                                         \
    swizzle_binary_operator_helper(lhs[i] _operator rhs)                                                  \
}                                                                                                         \
template <typename U, binary_operator_args(_type)>                                                        \
inline friend constexpr auto operator _operator(const T& lhs, const Swizzle<U, V...>& rhs)                \
{                                                                                                         \
    swizzle_binary_operator_helper(lhs _operator rhs[i])                                                  \
}                                                                                                         \

#define define_vector_unary_operator(_operator, _type)                    \
template <typename T, len_t N, unary_operator_args(_type)>                \
inline constexpr Vector<T, N> operator _operator(const Vector<T, N>& lhs) \
{                                                                         \
    function_helper(_operator lhs[i])                                     \
}                                                                         \

#define define_swizzle_unary_operator(_operator, _type)                                       \
template <typename U = T, typename = typename std::enable_if_t<_type##_operator_test(U)>>     \
inline friend constexpr Swizzle<T, V...> operator _operator(const Swizzle<T, V...>& lhs)      \
{                                                                                             \
    Swizzle<T, V...> res;                                                                     \
    for(len_t i = 0; i < len; i++)                                                            \
        res[i] = _operator lhs[i];                                                            \
    return res;                                                                               \
}                                                                                             \

#define define_vector_assignment_operator(_operator, _type)                             \
template <typename T, typename U, len_t N, binary_operator_args(_type)>                 \
inline constexpr auto operator _operator##=(Vector<T, N>& lhs, const Vector<U, N>& rhs) \
{                                                                                       \
    assignment_operator_helper(lhs[i] _operator##= rhs[i], N)                           \
}                                                                                       \
template <typename T, typename U, len_t N, binary_operator_args(_type)>                 \
inline constexpr auto operator _operator##=(Vector<T, N>& lhs, const U& rhs)            \
{                                                                                       \
    assignment_operator_helper(lhs[i] _operator##= rhs, N)                              \
}                                                                                       \

#define define_swizzle_assignment_operator(_operator, _type)                                            \
template <typename U, binary_operator_args(_type)>                                                      \
inline friend constexpr auto operator _operator##=(Swizzle<T, V...>& lhs, const Vector<U, len>& rhs)    \
{                                                                                                       \
    assignment_operator_helper(lhs[i] _operator##= rhs[i], len)                                         \
}                                                                                                       \
template <typename U, binary_operator_args(_type)>                                                      \
inline friend constexpr auto operator _operator##=(Swizzle<T, V...>& lhs, const U& rhs)                 \
{                                                                                                       \
    assignment_operator_helper(lhs[i] _operator##= rhs, len)                                            \
}                                                                                                       \
template <typename U, len_t... SW, typename = typename                                                  \
std::enable_if_t<sizeof...(SW) == len && _type##_operator_test(T) && _type##_operator_test(U)>>         \
inline friend constexpr auto operator _operator##=(Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs) \
{                                                                                                       \
    assignment_operator_helper(lhs[i] _operator##= rhs[i], len)                                         \
}                                                                                                       \

#define define_vector_comparison_operator(_operator, _type)                                \
template <typename T, typename U, len_t N>                                                 \
inline constexpr bool operator _operator(const Vector<T, N>& lhs, const Vector<U, N>& rhs) \
{                                                                                          \
    comparison_operator_helper_##_type(lhs[i] _operator rhs[i], N)                         \
}                                                                                          \
template <typename T, typename U, len_t N>                                                 \
inline constexpr bool operator _operator(const Vector<T, N>& lhs, const U& rhs)            \
{                                                                                          \
    comparison_operator_helper_##_type(lhs[i] _operator rhs, N)                            \
}                                                                                          \
template <typename T, typename U, len_t N>                                                 \
inline constexpr bool operator _operator(const T& lhs, const Vector<U, N>& rhs)            \
{                                                                                          \
    comparison_operator_helper_##_type(lhs _operator rhs[i], N)                            \
}                                                                                          \

#define define_swizzle_comparison_operator(_operator, _type)                                               \
template <typename U, len_t... SW, typename = typename std::enable_if_t<sizeof...(SW) == len>>             \
inline friend constexpr bool operator _operator(const Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs) \
{                                                                                                          \
    comparison_operator_helper_##_type(lhs[i] _operator rhs[i], len)                                       \
}                                                                                                          \
template <typename U>                                                                                      \
inline friend constexpr bool operator _operator(const Swizzle<T, V...>& lhs, const U& rhs)                 \
{                                                                                                          \
    comparison_operator_helper_##_type(lhs[i] _operator rhs, len)                                          \
}                                                                                                          \
template <typename U>                                                                                      \
inline friend constexpr bool operator _operator(const T& lhs, const Swizzle<U, V...>& rhs)                 \
{                                                                                                          \
    comparison_operator_helper_##_type(lhs _operator rhs[i], len)                                          \
}                                                                                                          \
template <typename U>                                                                                      \
inline friend constexpr bool operator _operator(const Swizzle<T, V...>& lhs, const Vector<U, len>& rhs)    \
{                                                                                                          \
    comparison_operator_helper_##_type(lhs[i] _operator rhs[i], len)                                       \
}                                                                                                          \
template <typename U>                                                                                      \
inline friend constexpr bool operator _operator(const Vector<T, len>& lhs, const Swizzle<U, V...>& rhs)    \
{                                                                                                          \
    comparison_operator_helper_##_type(lhs[i] _operator rhs[i], len)                                       \
}                                                                                                          \

#define define_unary_function(_function)                             \
template <typename T, len_t N>                                       \
inline constexpr Vector<T, N> _function(const Vector<T, N>& lhs)     \
{                                                                    \
    function_helper(_function(lhs[i]))                               \
}                                                                    \
template <typename T, len_t... V, len_t N = sizeof...(V)>            \
inline constexpr Vector<T, N> _function(const Swizzle<T, V...>& lhs) \
{                                                                    \
    function_helper(_function(lhs[i]))                               \
}                                                                    \

#define define_binary_function(_function)                                                           \
template <typename T, len_t N>                                                                      \
inline constexpr Vector<T, N> _function(const Vector<T, N>& lhs, const Vector<T, N>& rhs)           \
{                                                                                                   \
    function_helper(_function(lhs[i], rhs[i]))                                                      \
}                                                                                                   \
template <typename T, len_t N>                                                                      \
inline constexpr Vector<T, N> _function(const T& lhs, const Vector<T, N>& rhs)                      \
{                                                                                                   \
    function_helper(_function(lhs, rhs[i]))                                                         \
}                                                                                                   \
template <typename T, len_t N>                                                                      \
inline constexpr Vector<T, N> _function(const Vector<T, N>& lhs, const T& rhs)                      \
{                                                                                                   \
    function_helper(_function(lhs[i], rhs))                                                         \
}                                                                                                   \
template <typename T, len_t... V, len_t N = sizeof...(V)>                                           \
inline constexpr Vector<T, N> _function(const Swizzle<T, V...>& lhs, const Vector<T, N>& rhs)       \
{                                                                                                   \
    function_helper(_function(lhs[i], rhs[i]))                                                      \
}                                                                                                   \
template <typename T, len_t... V, len_t... SW, len_t N = sizeof...(V),                              \
typename = typename std::enable_if_t<sizeof...(SW) == sizeof...(V)>>                                \
inline constexpr Vector<T, N> _function(const Swizzle<T, V...>& lhs, const Swizzle<T, SW...>& rhs)  \
{                                                                                                   \
    function_helper(_function(lhs[i], rhs[i]))                                                      \
}                                                                                                   \

#define define_vector_operator(_operator, _type)    \
define_vector_binary_operator(_operator, _type)     \
define_vector_assignment_operator(_operator, _type) \

#define define_swizzle_operator(_operator, _type)    \
define_swizzle_binary_operator(_operator, _type)     \
define_swizzle_assignment_operator(_operator, _type) \

#define define_matrix_comparison_operator(_operator, _type)                                       \
template <typename T, typename U, len_t R, len_t C>                                               \
inline constexpr bool operator _operator(const Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)  \
{                                                                                                 \
    comparison_operator_helper_##_type(lhs[i] _operator rhs[i], C)                                \
}                                                                                                 \
template <typename T, typename U, len_t R, len_t C>                                               \
inline constexpr bool operator _operator(const T& lhs, const Matrix<U, R, C>& rhs)                \
{                                                                                                 \
    comparison_operator_helper_##_type(lhs _operator rhs[i], C)                                   \
}                                                                                                 \
template <typename T, typename U, len_t R, len_t C>                                               \
inline constexpr bool operator _operator(const Matrix<T, R, C>& lhs, const U& rhs)                \
{                                                                                                 \
    comparison_operator_helper_##_type(lhs[i] _operator rhs, C)                                   \
}                                                                                                 \

#define define_iterators(_ptr, _len)                                         \
using iterator = Iterator<T>;                                                \
using const_iterator = Iterator<const T>;                                    \
using reverse_iterator = ReverseIterator<T>;                                 \
using const_reverse_iterator = ReverseIterator<const T>;                     \
inline constexpr iterator begin() {return _ptr;}                             \
inline constexpr iterator end() {return _ptr + _len;}                        \
inline constexpr const_iterator cbegin() const {return _ptr + _len;}         \
inline constexpr const_iterator cend() const {return _ptr;}                  \
inline constexpr reverse_iterator rbegin() {return _ptr;}                    \
inline constexpr reverse_iterator rend() {return _ptr + _len;}               \
inline constexpr const_reverse_iterator crbegin() const {return _ptr + _len;}\
inline constexpr const_reverse_iterator crend() const {return _ptr;}         \

inline constexpr double pi = 3.141519265358979323846;
inline constexpr double half_pi = 1.57079632679489661923;
inline constexpr double two_pi = 6.283038530717958813909;
inline constexpr double golden_ratio = 1.618033988749;
inline constexpr double one_over_pi = 0.3183173221399075436544;
inline constexpr double epsilon = 0.1;

static constexpr uint8_t p[512] = {
0x97, 0xA0, 0x89, 0x5B, 0x5A, 0x0F, 0x83, 0x0D, 0xC9, 0x5F, 0x60, 0x35, 0xC2, 0xE9, 0x07, 0xE1,
0x8C, 0x24, 0x67, 0x1E, 0x45, 0x8E, 0x08, 0x63, 0x25, 0xF0, 0x15, 0x0A, 0x17, 0xBE, 0x06, 0x94,
0xF7, 0x78, 0xEA, 0x4B, 0x00, 0x1A, 0xC5, 0x3E, 0x5E, 0xFC, 0xDB, 0xCB, 0x75, 0x23, 0x0B, 0x20,
0x39, 0xB1, 0x21, 0x58, 0xED, 0x95, 0x38, 0x57, 0xAE, 0x14, 0x7D, 0x88, 0xAB, 0xA8, 0x44, 0xAF,
0x4A, 0xA5, 0x47, 0x86, 0x8B, 0x30, 0x1B, 0xA6, 0x4D, 0x92, 0x9E, 0xE7, 0x53, 0x6F, 0xE5, 0x7A,
0x3C, 0xD3, 0x85, 0xE6, 0xDC, 0x69, 0x5C, 0x29, 0x37, 0x2E, 0xF5, 0x28, 0xF4, 0x66, 0x8F, 0x36,
0x41, 0x19, 0x3F, 0xA1, 0x01, 0xD8, 0x50, 0x49, 0xD1, 0x4C, 0x84, 0xBB, 0xD0, 0x59, 0x12, 0xA9,
0xC8, 0xC4, 0x87, 0x82, 0x74, 0xBC, 0x9F, 0x56, 0xA4, 0x64, 0x6D, 0xC6, 0xAD, 0xBA, 0x03, 0x40,
0x34, 0xD9, 0xE2, 0xFA, 0x7C, 0x7B, 0x05, 0xCA, 0x26, 0x93, 0x76, 0x7E, 0xFF, 0x52, 0x55, 0xD4,
0xCF, 0xCE, 0x3B, 0xE3, 0x2F, 0x10, 0x3A, 0x11, 0xB6, 0xBD, 0x1C, 0x2A, 0xDF, 0xB7, 0xAA, 0xD5,
0x77, 0xF8, 0x98, 0x02, 0x2C, 0x9A, 0xA3, 0x46, 0xDD, 0x99, 0x65, 0x9B, 0xA7, 0x2B, 0xAC, 0x09,
0x81, 0x16, 0x27, 0xFD, 0x13, 0x62, 0x6C, 0x6E, 0x4F, 0x71, 0xE0, 0xE8, 0xB2, 0xB9, 0x70, 0x68,
0xDA, 0xF6, 0x61, 0xE4, 0xFB, 0x22, 0xF2, 0xC1, 0xEE, 0xD2, 0x90, 0x0C, 0xBF, 0xB3, 0xA2, 0xF1,
0x51, 0x33, 0x91, 0xEB, 0xF9, 0x0E, 0xEF, 0x6B, 0x31, 0xC0, 0xD6, 0x1F, 0xB5, 0xC7, 0x6A, 0x9D,
0xB8, 0x54, 0xCC, 0xB0, 0x73, 0x79, 0x32, 0x2D, 0x7F, 0x04, 0x96, 0xFE, 0x8A, 0xEC, 0xCD, 0x5D,
0xDE, 0x72, 0x43, 0x1D, 0x18, 0x48, 0xF3, 0x8D, 0x80, 0xC3, 0x4E, 0x42, 0xD7, 0x3D, 0x9C, 0xB4,
0x97, 0xA0, 0x89, 0x5B, 0x5A, 0x0F, 0x83, 0x0D, 0xC9, 0x5F, 0x60, 0x35, 0xC2, 0xE9, 0x07, 0xE1,
0x8C, 0x24, 0x67, 0x1E, 0x45, 0x8E, 0x08, 0x63, 0x25, 0xF0, 0x15, 0x0A, 0x17, 0xBE, 0x06, 0x94,
0xF7, 0x78, 0xEA, 0x4B, 0x00, 0x1A, 0xC5, 0x3E, 0x5E, 0xFC, 0xDB, 0xCB, 0x75, 0x23, 0x0B, 0x20,
0x39, 0xB1, 0x21, 0x58, 0xED, 0x95, 0x38, 0x57, 0xAE, 0x14, 0x7D, 0x88, 0xAB, 0xA8, 0x44, 0xAF,
0x4A, 0xA5, 0x47, 0x86, 0x8B, 0x30, 0x1B, 0xA6, 0x4D, 0x92, 0x9E, 0xE7, 0x53, 0x6F, 0xE5, 0x7A,
0x3C, 0xD3, 0x85, 0xE6, 0xDC, 0x69, 0x5C, 0x29, 0x37, 0x2E, 0xF5, 0x28, 0xF4, 0x66, 0x8F, 0x36,
0x41, 0x19, 0x3F, 0xA1, 0x01, 0xD8, 0x50, 0x49, 0xD1, 0x4C, 0x84, 0xBB, 0xD0, 0x59, 0x12, 0xA9,
0xC8, 0xC4, 0x87, 0x82, 0x74, 0xBC, 0x9F, 0x56, 0xA4, 0x64, 0x6D, 0xC6, 0xAD, 0xBA, 0x03, 0x40,
0x34, 0xD9, 0xE2, 0xFA, 0x7C, 0x7B, 0x05, 0xCA, 0x26, 0x93, 0x76, 0x7E, 0xFF, 0x52, 0x55, 0xD4,
0xCF, 0xCE, 0x3B, 0xE3, 0x2F, 0x10, 0x3A, 0x11, 0xB6, 0xBD, 0x1C, 0x2A, 0xDF, 0xB7, 0xAA, 0xD5,
0x77, 0xF8, 0x98, 0x02, 0x2C, 0x9A, 0xA3, 0x46, 0xDD, 0x99, 0x65, 0x9B, 0xA7, 0x2B, 0xAC, 0x09,
0x81, 0x16, 0x27, 0xFD, 0x13, 0x62, 0x6C, 0x6E, 0x4F, 0x71, 0xE0, 0xE8, 0xB2, 0xB9, 0x70, 0x68,
0xDA, 0xF6, 0x61, 0xE4, 0xFB, 0x22, 0xF2, 0xC1, 0xEE, 0xD2, 0x90, 0x0C, 0xBF, 0xB3, 0xA2, 0xF1,
0x51, 0x33, 0x91, 0xEB, 0xF9, 0x0E, 0xEF, 0x6B, 0x31, 0xC0, 0xD6, 0x1F, 0xB5, 0xC7, 0x6A, 0x9D,
0xB8, 0x54, 0xCC, 0xB0, 0x73, 0x79, 0x32, 0x2D, 0x7F, 0x04, 0x96, 0xFE, 0x8A, 0xEC, 0xCD, 0x5D,
0xDE, 0x72, 0x43, 0x1D, 0x18, 0x48, 0xF3, 0x8D, 0x80, 0xC3, 0x4E, 0x42, 0xD7, 0x3D, 0x9C, 0xB4};

inline constexpr double deg2rad(const double angle)
{
    return angle * 0.01745288480754988644228;
}

inline constexpr double rad2deg(const double angle)
{
    return angle * 57.29711798518336252073;
}

template <typename T, typename U>
inline constexpr bool almost_equal(const T& lhs, const U& rhs)
{
    return std::abs(lhs - rhs) < epsilon;
}

template <typename T, typename U>
inline constexpr T rotl(const T& lhs, const U& rhs, typename std::enable_if_t<std::is_unsigned_v<T>>* = 0)
{
    const T m = (std::numeric_limits<T>::digits - 1);
    const T c = rhs & m;
    return (lhs << c) | (lhs >> ((-c) & m));
}

template <typename T, typename U>
inline constexpr T rotr(const T& lhs, const U& rhs, typename std::enable_if_t<std::is_unsigned_v<T>>* = 0)
{
    const T m = (std::numeric_limits<T>::digits - 1);
    const T c = rhs & m;
    return (lhs >> c) | (lhs << ((-c) & m));
}

template <typename T>
inline constexpr T smoothstep(const T& lhs, const T& rhs, T x)
{
    x = std::clamp((x - lhs) / (rhs - lhs), T(0), T(1));
    return x * x * (T(3) - T(2) * x);
}

template <typename T>
inline constexpr T lerp(const T& lhs, const T& rhs, const double t)
{
    return (rhs - lhs) * t + lhs;
}

template <typename T>
inline constexpr T fade(const T& t)
{
    return t * t * t * (t * (t * T(6) - T(15)) + T(10));
}

template <typename T> 
inline T rand(const T& lhs, const T& rhs)
{
    return ((double)rand() / (double)RAND_MAX) * (rhs - lhs) + lhs;
}

template <typename T>
inline constexpr T mod(const T& lhs, const T& rhs, typename std::enable_if_t<std::is_floating_point_v<T>>* = 0)
{
    return fmod(lhs, rhs);
}

template <typename T>
inline constexpr T mod(const T& lhs, const T& rhs, typename std::enable_if_t<std::is_integral_v<T>>* = 0)
{
    return lhs % rhs;
}

template <typename T>
inline constexpr T fract(const T& lhs)
{
    return lhs - std::floor(lhs);
}

template <typename T>
inline constexpr T inv(const T& lhs)
{
    return T(1) / lhs;
}

template <typename T>
inline constexpr T min(const T& x, const T& y, const T& z)
{
    return min(x, min(y, z));
}

template <typename T>
inline constexpr T min(const T& x, const T& y, const T& z, const T& w)
{
    return min(x, min(y, z, w));
}

template <typename T>
inline constexpr T max(const T& x, const T& y, const T& z)
{
    return max(x, max(y, z));
}

template <typename T>
inline constexpr T max(const T& x, const T& y, const T& z, const T& w)
{
    return max(x, max(y, z, w));
}

inline constexpr const uint32_t hash(const uint8_t* lhs, const len_t& size)
{
    constexpr uint32_t p = 16777619;
    uint32_t res = 2166136261;
    for (len_t i = 0; i < size; i++)
        res = (res ^ lhs[i]) * p;
    return res;
}

template <typename T>
inline constexpr const uint32_t hash(const T& lhs)
{
    return hash(reinterpret_cast<const uint8_t*>(&lhs), sizeof(lhs));
}

inline constexpr const uint32_t hash_combine(uint32_t lhs, uint32_t rhs)
{
    lhs ^= rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2);
    return lhs;
}

template <typename T, len_t N, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>> 
class Vector
{
public:
    inline constexpr len_t size() const {return len;}
    inline static constexpr len_t len = N;
    define_iterators(&data[0], len)
private:
    T data[N] = {};
public:
    inline constexpr Vector& operator=(const Vector& lhs) = default;
    inline constexpr Vector(const Vector& lhs) = default;
    inline constexpr Vector(Vector&& lhs) = default;
    template <typename... V, typename = typename std::enable_if_t<all_arithmetic_v<V...> && sizeof...(V) + 1 == N>> 
    inline constexpr Vector(const T& lhs, const V&... args) : data{lhs, static_cast<T>(args)...} {}
    inline constexpr Vector(const T& scalar = T(0)) 
    {
        for(len_t i = 0; i < N; i++) 
            data[i] = scalar;
    }
    inline constexpr Vector(const T(&d)[N]) 
    {
        for(len_t i = 0; i < N; i++) 
            data[i] = d[i];
    }
    template <len_t M, typename... V, typename = typename std::enable_if_t<all_arithmetic_v<V...> && sizeof...(V) + M == N>>
    inline constexpr Vector(const Vector<T, M>& lhs, const V&... args)
    {
        const T arr[] = {static_cast<T>(args)...};
        for(len_t i = 0; i < N; i++)
            data[i] = i < M ? lhs[i] : arr[i - M];
    }
    inline constexpr T mag2() const
    {
        T res = T(0);
        for(len_t i = 0; i < N; i++)
            res += data[i] * data[i];
        return res;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr Vector<T, N> norm() const
    {
        const T mag = this->mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    template <typename F>
    inline constexpr operator Vector<F, N>() const
    {
        Vector<F, N> res;
        for(len_t i = 0; i < N; i++)
            res[i] = static_cast<F>(data[i]);
        return res;
    }
    inline constexpr T& operator[](const len_t& index)
    {
        if(check_len(index, N))
            return data[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        if(check_len(index, N))
            return data[index];
        else
            throw std::out_of_range("index out of range");
    }
};

template <typename T, len_t... V>
class Swizzle
{
public:
    inline static constexpr len_t len = sizeof...(V);
    inline static constexpr len_t sw[] = {V...};
private:
    T data[std::max({V...}) + 1];
public:
    inline constexpr Swizzle() = default;
    inline constexpr Swizzle(const Swizzle& lhs) = default;
    inline constexpr Swizzle(Swizzle&& lhs) = default;
    inline constexpr Swizzle& operator=(const Swizzle& lhs) = default;
    template <typename F>
    inline constexpr operator Vector<F, len>() const
    {
        Vector<F, len> res;
        for(len_t i = 0; i < len; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
    template <typename F, len_t... SW, typename = typename std::enable_if_t<sizeof...(SW) == len>>
    inline constexpr operator Swizzle<F, SW...>() const
    {
        Swizzle<F, SW...> res;
        for(len_t i = 0; i < len; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
    template <typename F, len_t... SW, typename = typename std::enable_if_t<sizeof...(SW) == len>>
    inline constexpr Swizzle<T, V...>& operator=(const Swizzle<F, SW...>& lhs)
    {
        for(len_t i = 0; i < len; i++)
            (*this)[i] = static_cast<T>(lhs[i]);
        return *this;
    }
    template <typename F>
    inline constexpr Swizzle<T, V...>& operator=(const Vector<F, len>& lhs)
    {
        for(len_t i = 0; i < len; i++)
            (*this)[i] = static_cast<T>(lhs[i]);
        return *this;
    }
    inline constexpr Swizzle<T, V...>& operator++()
    {
        for(len_t i = 0; i < len; i++)
            ++(*this)[i];
        return *this; 
    }
    inline constexpr Swizzle<T, V...>& operator--()
    {
        for(len_t i = 0; i < len; i++)
            --(*this)[i];
        return *this;
    }
    inline constexpr Swizzle<T, V...> operator++(int)
    {
        const Swizzle<T, V...> res = *this;
        ++(*this);
        return res;
    }
    inline constexpr Swizzle<T, V...> operator--(int)
    {
        const Swizzle<T, V...> res = *this;
        --(*this);
        return res;
    }
    inline friend constexpr Swizzle<T, V...> operator+(const Swizzle<T, V...>& lhs)
    {
        return lhs;
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Swizzle<T, V...>& rhs)
    {
        os << static_cast<Vector<T, len>>(rhs);
        return os;
    }
    inline friend std::istream& operator>>(std::istream& is, Swizzle<T, V...>& rhs)
    {
        is >> static_cast<Vector<T, len>>(rhs);
        return is;
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        if(check_len(index, len))
            return data[sw[index]];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr T& operator[](const len_t& index)
    {
        if(check_len(index, len))
            return data[sw[index]];
        else
            throw std::out_of_range("index out of range");
    }
    define_swizzle_comparison_operator(<=, and)
    define_swizzle_comparison_operator(>=, and)
    define_swizzle_comparison_operator(==, and)
    define_swizzle_comparison_operator(<, and)
    define_swizzle_comparison_operator(>, and)
    define_swizzle_comparison_operator(!=, or)
    define_swizzle_binary_operator(||, logical)
    define_swizzle_binary_operator(&&, logical)
    define_swizzle_unary_operator(-, arithmetic)
    define_swizzle_unary_operator(!, logical)
    define_swizzle_unary_operator(~, bitwise)
    define_swizzle_operator(*, arithmetic)
    define_swizzle_operator(/, arithmetic)
    define_swizzle_operator(+, arithmetic)
    define_swizzle_operator(-, arithmetic)
    define_swizzle_operator(>>, bitwise)
    define_swizzle_operator(<<, bitwise)
    define_swizzle_operator(^, bitwise)
    define_swizzle_operator(|, bitwise)
    define_swizzle_operator(&, bitwise)
};

template <typename T>
struct Vector<T, 1>
{
    union { T x; T r; T u; };
    inline static constexpr len_t len = 1;
    inline constexpr len_t size() const {return len;}
    inline constexpr Vector<T, 1>& operator=(const Vector<T, 1>& v) = default;
    inline constexpr Vector(const Vector<T, 1>& v) = default;
    inline constexpr Vector(Vector<T, 1>&& v) = default;
    inline constexpr explicit Vector(const T& scalar = T(0)) : x(scalar) {}
    inline constexpr Vector(const Vector<T, 2>& v) : x(v.x) {}
    inline constexpr Vector(const Vector<T, 3>& v) : x(v.x) {}
    inline constexpr Vector(const Vector<T, 4>& v) : x(v.x) {}
    template <typename U, typename = typename std::enable_if_t<std::is_arithmetic_v<U>>>
    inline constexpr Vector(const Vector<U, 1>& v) : x(static_cast<T>(v.x)) {}
    template <typename U, typename = typename std::enable_if_t<std::is_arithmetic_v<U>>>
    inline constexpr Vector(const Vector<U, 2>& v) : x(static_cast<T>(v.x)) {}
    template <typename U, typename = typename std::enable_if_t<std::is_arithmetic_v<U>>>
    inline constexpr Vector(const Vector<U, 3>& v) : x(static_cast<T>(v.x)) {}
    template <typename U, typename = typename std::enable_if_t<std::is_arithmetic_v<U>>>
    inline constexpr Vector(const Vector<U, 4>& v) : x(static_cast<T>(v.x)) {}
    inline constexpr Vector<T, 1> norm() {return Vector<T, 1>{T(1)};}
    inline constexpr T mag2() const {return x;}
    inline constexpr T mag() const {return x;}
    template <typename F>
    inline constexpr operator Vector<F, 1>() const
    {
        return static_cast<F>(x);
    }
    inline constexpr T& operator[](const len_t& index)
    {
        if(index == 0)
            return x;
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        if(index == 0)
            return x;
        else
            throw std::out_of_range("index out of range");
    }
};

template <typename T> 
struct Vector<T, 2>
{
    union
    {
        struct { T x, y; };
        struct { T u, v; };
        struct { T s, t; };
        struct { T w, h; };
        swizzle2(x, y)
        swizzle2(u, v)
        swizzle2(s, t)
    };
    define_iterators(&(*this)[0], len)
    inline static constexpr len_t len = 2;
    inline constexpr len_t size() const {return len;}
    inline constexpr Vector<T, 2>& operator=(const Vector<T, 2>& v) = default;
    inline constexpr Vector(const Vector<T, 2>& v) = default;
    inline constexpr Vector(Vector<T, 2>&& v) = default;
    inline constexpr Vector(const T& scalar = T(0)) : x(scalar), y(scalar) {}
    inline constexpr Vector(const T& x, const T& y) : x(x), y(y) {}
    inline constexpr Vector(const Vector<T, 3>& v) : x(v.x), y(v.y) {}
    inline constexpr Vector(const Vector<T, 4>& v) : x(v.x), y(v.y) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 1>& v) 
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.x)) {}
    template <typename A> 
    inline constexpr Vector(const Vector<A, 3>& v) 
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}
    template <typename A> 
    inline constexpr Vector(const Vector<A, 4>& v) 
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 1>& x, const Vector<B, 1>& y)
    : x(static_cast<T>(x.x)), y(static_cast<T>(y.x)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<all_arithmetic_v<A, B>>>
    inline constexpr Vector(const A& x, const B& y) 
    : x(static_cast<T>(x)), y(static_cast<T>(y)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<std::is_arithmetic_v<A>>>
    inline constexpr Vector(const A& x, const Vector<B, 1>& y)
    : x(static_cast<T>(x)), y(static_cast<T>(y.x)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<std::is_arithmetic_v<B>>>
    inline constexpr Vector(const Vector<A, 1>& x, const B& y)
    : x(static_cast<T>(x.x)), y(static_cast<T>(y)) {}
    template <typename F, len_t S0, len_t S1>
    inline constexpr operator Swizzle<F, S0, S1>() const
    {
        Swizzle<F, S0, S1> res;
        res[0] = static_cast<F>(x);
        res[1] = static_cast<F>(y);
        return res;
    }
    inline constexpr T mag2() const
    {
        return x * x + y * y;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr T area() const
    {
        return w * h;
    }
    inline constexpr Vector<T, 2> perp() const
    {
        return {-y, x};
    }
    inline constexpr Vector<T, 2> norm() const
    {
        const T mag = this->mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    static inline constexpr Vector<T, 2> zero()
    {
        return T(0);
    }
    static inline constexpr Vector<T, 2> one()
    {
        return T(1);
    }
    static inline constexpr Vector<T, 2> right()
    {
        return {T(1), T(0)};
    }
    static inline constexpr Vector<T, 2> up()
    {
        return {T(0), T(1)};
    }
    template <typename F> 
    inline constexpr operator Vector<F, 2>() const
    {
        return 
        {
            static_cast<F>(x), 
            static_cast<F>(y)
        };
    }
    inline constexpr T& operator[](const len_t& index)
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            default: throw std::out_of_range("index out of range");
        }
    }
};

template <typename T> 
struct Vector<T, 3>
{
    union 
    {
        struct { T x, y, z; };
        struct { T r, g, b; };
        struct { T h, s, v; };
        struct 
        { 
            T roll;
            T pitch;
            T yaw; 
        };
        swizzle2(x, y)
        swizzle3(x, y, z)
        swizzle3(r, g, b)
        swizzle3(h, s, v)
    };
    define_iterators(&(*this)[0], len)
    inline static constexpr len_t len = 3;
    inline constexpr len_t size() const {return len;}
    inline constexpr Vector<T, 3>& operator=(const Vector<T, 3>& v) = default;
    inline constexpr Vector(const Vector<T, 3>& v) = default;
    inline constexpr Vector(Vector<T, 3>&& v) = default;
    inline constexpr Vector(const T& scalar = T(0)) : x(scalar), y(scalar), z(scalar) {}
    inline constexpr Vector(const Vector<T, 2>& xy, const T& z = T(0)) : x(xy.x), y(xy.y), z(z) {}
    inline constexpr Vector(const T& x, const Vector<T, 2>& yz) : x(x), y(yz.x), z(yz.y) {}
    inline constexpr Vector(const Vector<T, 4>& v) : x(v.x), y(v.y), z((v.z)) {}
    inline constexpr Vector(const T& x, const T& y, const T& z = T(0)) : x(x), y(y), z(z) {}
    inline constexpr Vector(const Vector<T, 1>& x, const Vector<T, 1>& y, const Vector<T, 1>& z) : x(x.x), y(y.x), z(z.x) {}
    inline constexpr Vector(const Vector<T, 1>& x, const Vector<T, 2>& yz) : x(x.x), y(yz.x), z(yz.y) {}
    inline constexpr Vector(const Vector<T, 2>& xy, const Vector<T, 1>& z) : x(xy.x), y(xy.y), z(z.x) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 1>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<std::is_arithmetic_v<B>>>
    inline constexpr Vector(const Vector<A, 2>& xy, const B& z = B(0)) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z)) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 4>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<std::is_arithmetic_v<A>>>
    inline constexpr Vector(const A& x, const Vector<B, 2>& yz)
    : x(static_cast<T>(x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)) {}
    template <typename A, typename B, typename C, typename = typename std::enable_if_t<all_arithmetic_v<A, B, C>>>
    inline constexpr Vector(const A& x, const B& y, const C& z = C(0))
    : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)) {}
    template <typename A, typename B, typename C>
    inline constexpr Vector(const Vector<A, 1>& x, const Vector<B, 1>& y, const Vector<C, 1>& z) 
    : x(static_cast<T>(x.x)), y(static_cast<T>(y.x)), z(static_cast<T>(z.x)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 1>& x, const Vector<B, 2>& yz) 
    : x(static_cast<T>(x.x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 2>& xy, const Vector<B, 1>& z) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z.x)) {}
    template <typename F, len_t S0, len_t S1, len_t S2>
    inline constexpr operator Swizzle<F, S0, S1, S2>() const
    {
        Swizzle<F, S0, S1, S2> res;
        for(len_t i = 0; i < len; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
    inline constexpr T vol() const
    {
        return x * y * z;
    }
    inline constexpr T mag2() const
    {
        return x * x + y * y + z * z;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr Vector<T, 3> norm() const
    {
        const T mag = this->mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    static inline constexpr Vector<T, 3> zero()
    {
        return T(0);
    }
    static inline constexpr Vector<T, 3> one()
    {
        return T(1);
    }
    static inline constexpr Vector<T, 3> right()
    {
        return {T(1), T(0), T(0)};
    }
    static inline constexpr Vector<T, 3> up()
    {
        return {T(0), T(1), T(0)};
    }
    static inline constexpr Vector<T, 3> forward()
    {
        return {T(0), T(0), T(1)};
    }
    template <typename F> 
    inline constexpr operator Vector<F, 3>() const
    {
        return 
        {
            static_cast<F>(x), 
            static_cast<F>(y),
            static_cast<F>(z)
        };
    }
    inline constexpr T& operator[](const len_t& index)
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw std::out_of_range("index out of range");
        }
    }
};

template <typename T> 
struct Vector<T, 4>
{
    union
    {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        swizzle2(x, y)
        swizzle2(r, g)
        swizzle3(x, y, z)
        swizzle3(r, g, b)
        swizzle4(x, y, z, w)
        swizzle4(r, g, b, a)
    };
    define_iterators(&(*this)[0], len)
    static inline constexpr len_t len = 4;
    inline constexpr len_t size() const {return len;}
    inline constexpr Vector<T, 4>& operator=(const Vector<T, 4>& v) = default;
    inline constexpr Vector(const Vector<T, 4>& v) = default;
    inline constexpr Vector(Vector<T, 4>&& v) = default;
    inline constexpr Vector(const T& scalar = T(0)) : x(scalar), y(scalar), z(scalar), w(scalar) {}
    inline constexpr Vector(const T& x, const Vector<T, 3>& yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}
    inline constexpr Vector(const Vector<T, 2>& xy, const Vector<T, 2>& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
    inline constexpr Vector(const T& x, const Vector<T, 2>& yz, const T& w = T(0)) : x(x), y(yz.x), z(yz.y), w(w) {}
    inline constexpr Vector(const Vector<T, 2>& xy, const T& z = T(0), const T& w = T(0)) : x(xy.x), y(xy.y), z(z), w(w) {}
    inline constexpr Vector(const Vector<T, 3>& xyz, const T& w = T(0)) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
    inline constexpr Vector(const T& x, const T& y, const T& z = T(0), const T& w = T(0)) : x(x), y(y), z(z), w(w) {}
    inline constexpr Vector(const Vector<T, 1>& x, const Vector<T, 3>& yzw) : x(x.x), y(yzw.x), z(yzw.y), w(yzw.z) {}
    inline constexpr Vector(const Vector<T, 1>& x, const Vector<T, 2>& yz, const Vector<T, 1>& w) : x(x.x), y(yz.x), z(yz.y), w(w.x) {}
    inline constexpr Vector(const Vector<T, 2>& xy, const Vector<T, 1>& z, const Vector<T, 1>& w) : x(xy.x), y(xy.y), z(z.x), w(w.x) {}
    inline constexpr Vector(const Vector<T, 3>& xyz, const Vector<T, 1>& w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w.x) {}
    inline constexpr Vector(const Vector<T, 1>& x, const Vector<T, 1>& y, const Vector<T, 1>& z, const Vector<T, 1>& w)
    : x(x.x), y(y.x), z(z.x), w(w.x) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 1>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x)), w(static_cast<T>(v.x)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<std::is_arithmetic_v<A>>>
    inline constexpr Vector(const A& x, const Vector<B, 3>& yzw) 
    : x(static_cast<T>(x)), y(static_cast<T>(yzw.x)), z(static_cast<T>(yzw.y)), w(static_cast<T>(yzw.z)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 2>& xy, const Vector<B, 2>& zw) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(zw.x)), w(static_cast<T>(zw.y)) {}
    template <typename A, typename B, typename C, typename = typename std::enable_if_t<all_arithmetic_v<A, C>>>
    inline constexpr Vector(const A& x, const Vector<B, 2>& yz, const C& w = C(0)) 
    : x(static_cast<T>(x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)), w(static_cast<T>(w)) {}
    template <typename A, typename B, typename C, typename = typename std::enable_if_t<all_arithmetic_v<B, C>>>
    inline constexpr Vector(const Vector<A, 2>& xy, const B& z = B(0), const C& w = C(0)) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}
    template <typename A, typename B, typename = typename std::enable_if_t<std::is_arithmetic_v<B>>>
    inline constexpr Vector(const Vector<A, 3>& xyz, const B& w = B(0)) 
    : x(static_cast<T>(xyz.x)), y(static_cast<T>(xyz.y)), z(static_cast<T>(xyz.z)), w(static_cast<T>(w)) {}
    template <typename A, typename B, typename C, typename D, typename = typename std::enable_if_t<all_arithmetic_v<A, B, C, D>>>
    inline constexpr Vector(const A& x, const B& y, const C& z = C(0), const D& w = D(0))
    : x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 1>& x, const Vector<B, 3>& yzw) 
    : x(static_cast<T>(x.x)), y(static_cast<T>(yzw.x)), z(static_cast<T>(yzw.y)), w(static_cast<T>(yzw.z)) {}
    template <typename A, typename B, typename C>
    inline constexpr Vector(const Vector<A, 1>& x, const Vector<B, 2>& yz, const Vector<C, 1>& w) 
    : x(static_cast<T>(x.x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)), w(static_cast<T>(w.x)) {}
    template <typename A, typename B, typename C>
    inline constexpr Vector(const Vector<A, 2>& xy, const Vector<B, 1>& z, const Vector<C, 1>& w) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z.x)), w(static_cast<T>(w.x)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 3>& xyz, const Vector<B, 1>& w) 
    : x(static_cast<T>(xyz.x)), y(static_cast<T>(xyz.y)), z(static_cast<T>(xyz.z)), w(static_cast<T>(w.x)) {}
    template <typename A, typename B, typename C, typename D>
    inline constexpr Vector(const Vector<A, 1>& x, const Vector<B, 1>& y, const Vector<C, 1>& z, const Vector<D, 1>& w)
    : x(static_cast<T>(x.x)), y(static_cast<T>(y.x)), z(static_cast<T>(z.x)), w(static_cast<T>(w.x)) {}
    template <typename F, len_t S0, len_t S1, len_t S2, len_t S3>
    inline constexpr operator Swizzle<F, S0, S1, S2, S3>() const
    {
        Swizzle<F, S0, S1, S2, S3> res;
        for(len_t i = 0; i < len; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
    inline constexpr T mag2() const
    {
        return x * x + y * y + z * z + w * w;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr Vector<T, 4> norm() const
    {
        const T mag = this->mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    static inline constexpr Vector<T, 4> one()
    {
        return T(1);
    }
    static inline constexpr Vector<T, 4> zero()
    {
        return T(0);
    }
    template <typename F> 
    inline constexpr operator Vector<F, 4>() const
    {
        return 
        {
            static_cast<F>(x), 
            static_cast<F>(y), 
            static_cast<F>(z), 
            static_cast<F>(w)
        };
    }
    inline constexpr T& operator[](const len_t& index)
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            case 3: return w;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            case 3: return w;
            default: throw std::out_of_range("index out of range");
        }
    }
};

define_vector_comparison_operator(<=, and)
define_vector_comparison_operator(>=, and)
define_vector_comparison_operator(==, and)
define_vector_comparison_operator(<, and)
define_vector_comparison_operator(>, and)
define_vector_comparison_operator(!=, or)
define_vector_binary_operator(&&, logical)
define_vector_binary_operator(||, logical)
define_vector_unary_operator(~, bitwise)
define_vector_unary_operator(!, logical)
define_vector_unary_operator(-, arithmetic)
define_vector_operator(*, arithmetic)
define_vector_operator(/, arithmetic)
define_vector_operator(+, arithmetic)
define_vector_operator(-, arithmetic)
define_vector_operator(<<, bitwise)
define_vector_operator(>>, bitwise)
define_vector_operator(^, bitwise)
define_vector_operator(|, bitwise)
define_vector_operator(&, bitwise)
define_unary_function(abs)
define_unary_function(floor)
define_unary_function(ceil)
define_unary_function(inv)
define_unary_function(fade)
define_unary_function(fract)
define_unary_function(exp)
define_unary_function(log2)
define_unary_function(log10)
define_unary_function(log)
define_binary_function(min)
define_binary_function(max)
define_binary_function(mod)
define_binary_function(rotl)
define_binary_function(rotr)
define_binary_function(rand)

template <typename T, typename U, len_t TN, len_t UN>
struct are_same_tpl<Vector<T, TN>, Vector<U, UN>> : std::true_type {};

template <typename T, len_t N>
inline constexpr Vector<T, N>& operator++(Vector<T, N>& lhs)
{
    for(len_t i = 0; i < N; i++)
        ++lhs[i];
    return lhs;
}

template <typename T, len_t N>
inline constexpr Vector<T, N>& operator--(Vector<T, N>& lhs)
{
    for(len_t i = 0; i < N; i++)
        --lhs[i];
    return lhs;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> operator++(Vector<T, N>& lhs, int)
{
    const Vector<T, N> res = lhs;
    ++lhs;
    return res;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> operator--(Vector<T, N>& lhs, int)
{
    const Vector<T, N> res = lhs;
    --lhs;
    return res;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> operator+(const Vector<T, N>& lhs)
{
    return lhs;
}

template <typename T, len_t N> 
inline std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vec)
{
    os << '{';
    for(len_t i = 0; i < N; i++)
        os << vec[i] << (i != N - 1 ? ',' : '}');
    return os;
}

template <typename T, len_t N>
inline std::istream& operator>>(std::istream& is, Vector<T, N>& vec)
{
    len_t count = 0;
    char c;
    T value = T(0);
    while(count <= N)
    {
        is >> c;
        if(c == '{' || c == ',')
        {
            is >> value;
            vec[count] = value;
            ++count;
        }
        else if(c == '}')
            goto done;
    }
done:
    if(count != N)
        throw std::runtime_error("Vector size is wrong!");
    return is;
}

template <typename T, typename U, len_t N>
inline constexpr bool almost_equal(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(len_t i = 0; i < N; i++)
        if(!almost_equal(lhs[i], rhs[i]))
            return false;
    return true;
}

template <typename T, typename U, len_t N> 
inline constexpr auto dot(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    decltype(lhs[0] * rhs[0]) res = 0;
    for(len_t i = 0; i < N; i++)
        res += lhs[i] * rhs[i];
    return res;
}

template <typename T, typename U> 
inline constexpr auto cross(const Vector<T, 3>& lhs, const Vector<U, 3>& rhs)
{
    return decltype(lhs * rhs)
    {
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    };
}

template <typename T, len_t N>
inline constexpr Vector<T, N> smoothstep(const Vector<T, N>& lhs, const Vector<T, N>& rhs, const Vector<T, N>& x)
{
    Vector<T, N> res;
    for(len_t i = 0; i < N; i++)
        res[i] = smoothstep(lhs[i], rhs[i], x[i]);
    return res;
}

template <typename T, len_t N> 
inline constexpr Vector<T, N> lerp(const Vector<T, N>& lhs, const Vector<T, N>& rhs, const double t)
{
    return (rhs - lhs) * t + lhs;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> slerp(const Vector<T, N>& lhs, const Vector<T, N>& rhs, const double t)
{
    const T d = std::clamp(dot(lhs, rhs), T(-1), T(1));
    const double theta = std::acos(d) * t;
    const Vector<T, N> v = (rhs - lhs * d).norm();
    return lhs * std::cos(theta) + v * std::sin(theta);
}

template <typename T, len_t N>
inline constexpr Vector<T, N> reflect(const Vector<T, N>& vec, const Vector<T, N>& norm)
{
    return vec - T(2) * dot(vec, norm) * norm;
}

template <typename T, len_t N> 
inline constexpr Vector<T, N> clamp(const Vector<T, N>& lhs, const Vector<T, N>& min, const Vector<T, N>& max)
{
    Vector<T, N> res;
    for(len_t i = 0; i < N; i++)
        res[i] = std::clamp(lhs[i], min[i], max[i]);
    return res;
}

template <typename T, len_t N> 
inline constexpr T min(const Vector<T, N>& lhs)
{
    T res = lhs[0];
    for(len_t i = 1; i < N; i++)
        res = std::min(lhs[i], res);
    return res;
}

template <typename T, len_t N> 
inline constexpr T max(const Vector<T, N>& lhs)
{
    T res = lhs[0];
    for(len_t i = 1; i < N; i++)
        res = std::max(lhs[i], res);
    return res;
}

template <typename T, len_t N>
inline constexpr const uint32_t hash(const Vector<T, N>& lhs)
{
    return hash(reinterpret_cast<const uint8_t*>(&lhs[0]), sizeof(T) * N);
}

template <typename T, len_t N, len_t... V> 
inline constexpr Vector<T, sizeof...(V)> swizzle(const Vector<T, N>& lhs)
{
    const len_t size = sizeof...(V);
    const len_t sw[] = {V...};
    Vector<T, size> res;
    for(len_t i = 0; i < size; i++)
        res[i] = lhs[sw[i]];
    return res;
}

template <typename T, len_t N>
inline constexpr bool any_equal(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
    comparison_operator_helper_or(lhs[i] == rhs[i], N)
}

template <typename T, len_t N>
inline constexpr bool any_greater(const Vector<T, N>& lhs, const T& rhs)
{
    return !(lhs <= rhs);
}

template <typename T, len_t N>
inline constexpr bool any_less(const Vector<T, N>& lhs, const T& rhs)
{
    return !(lhs >= rhs);
}

template <typename T>
inline constexpr Vector<T, 3> rgb_to_hsv(const Vector<T, 3>& rgb)
{
    Vector<T, 3> res;
    const T cmax = max(rgb);
    const T cmin = min(rgb);
    if(cmax == cmin)
        return {T(0), T(0), cmax * T(100)};
    const T delta = cmax - cmin;
    if(cmax == rgb.r)
        res.h = mod((rgb.g - rgb.b) / delta, T(6));
    else if(cmax == rgb.g)
        res.h = (rgb.b - rgb.r) / delta + T(2);
    else
        res.h = (rgb.r - rgb.g) / delta + T(4);
    res.h *= T(60);
    res.s = (delta / cmax) * T(100);
    res.v = cmax * T(100);
    return res;
}

template <typename T>
inline constexpr Vector<T, 3> rgb_to_hsv_ub(const Vector<uint8_t, 3>& rgb)
{
    return rgb_to_hsv<T>(rgb / T(255));
}

typedef Vector<float, 1> vec1;
typedef Vector<double, 1> dvec1;

typedef Vector<bool, 2> bvec2;
typedef Vector<float, 2> vec2;
typedef Vector<double, 2> dvec2;
typedef Vector<int32_t, 2> ivec2;
typedef Vector<uint8_t, 2> ubvec2;
typedef Vector<uint16_t, 2> usvec2;
typedef Vector<uint32_t, 2> uvec2;

typedef Vector<bool, 3> bvec3;
typedef Vector<float, 3> vec3;
typedef Vector<double, 3> dvec3;
typedef Vector<int32_t, 3> ivec3;
typedef Vector<uint8_t, 3> ubvec3;
typedef Vector<uint16_t, 3> usvec3;
typedef Vector<uint32_t, 3> uvec3;

typedef Vector<bool, 4> bvec4;
typedef Vector<float, 4> vec4;
typedef Vector<double, 4> dvec4;
typedef Vector<int32_t, 4> ivec4;
typedef Vector<uint8_t, 4> ubvec4;
typedef Vector<uint16_t, 4> usvec4;
typedef Vector<uint32_t, 4> uvec4;

template <typename T, len_t R, len_t C, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>> 
struct Matrix
{
    Vector<T, R> cols[C];
    inline constexpr Matrix& operator=(const Matrix& lhs) = default;
    inline constexpr Matrix(const Matrix& lhs) = default;
    inline constexpr Matrix(Matrix&& lhs) = default;
    template <len_t N = R, len_t M = C, typename = typename std::enable_if_t<N == M>>
    static inline constexpr Matrix<T, R, C> identity()
    {
        Matrix<T, R, C> res;
        for(len_t i = 0; i < R; i++)
            res[i][i] = T(1);
        return res;
    }
    static inline constexpr Matrix<T, R, C> zero()
    {
        return T(0);
    }
    inline constexpr Matrix(const T& lhs = T(0))
    {
        for(len_t i = 0; i < C; i++)
            cols[i] = lhs;
    }
    inline constexpr Matrix(const T(&lhs)[R * C])
    {
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                cols[j][i] = lhs[i * C + j];
    }
    template <typename... V, typename = typename std::enable_if_t<all_arithmetic_v<V...> && sizeof...(V) + 1 == R * C>> 
    inline constexpr Matrix(const T& lhs, const V&... args)
    {
        const T arr[] = {lhs, static_cast<T>(args)...};
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                cols[j][i] = arr[i * C + j];
    }
    template <typename... V, typename = typename std::enable_if_t<sizeof...(V) + 1 == R>>
    inline constexpr Matrix(const Vector<T, C>& lhs, const Vector<V, C>&... args)
    {
        const Vector<T, C> arr[] = {lhs, static_cast<Vector<T, C>>(args)...};
        for(len_t i = 0; i < R; i++)
            set_row(i, arr[i]);
    }
    template <len_t N, len_t M>
    inline constexpr Matrix(const Matrix<T, N, M>& lhs)
    {
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                cols[j][i] = (i < N && j < M) ? lhs[j][i] : (T)(i == j && R == C);
    }
    inline constexpr const Vector<T, C> row(const len_t& lhs) const
    {
        if(check_len(lhs, R))
        {
            Vector<T, C> res;
            for(len_t i = 0; i < C; i++) 
                res[i] = cols[i][lhs];
            return res;
        }
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr const Vector<T, R>& col(const len_t& lhs) const
    {
        if(check_len(lhs, C))
            return cols[lhs];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr void set_row(const len_t& lhs, const Vector<T, C>& rhs) 
    {
        if(check_len(lhs, R))
            for(len_t i = 0; i < C; i++) 
                cols[i][lhs] = rhs[i];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr void set_col(const len_t& lhs, const Vector<T, R>& rhs)
    {
        if(check_len(lhs, C))
            cols[lhs] = rhs;
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr Matrix<T, C, R> transpose() const
    {
        Matrix<T, C, R> res;
        for(len_t i = 0; i < C; i++)
            res.set_row(i, col(i));
        return res;
    }
    template <len_t N = R, len_t M = C, typename = typename std::enable_if_t<N == M>>
    inline constexpr Matrix<T, R, C> inverse() const
    {
        Matrix<T, R, C> temp = *this;
        Matrix<T, R, C> res = Matrix<T, R, C>::identity();
        for(len_t i = 0; i < R; i++)
        {
            const T div = temp[i][i];
            res.set_col(i, res.col(i) / div);
            temp.set_row(i, temp.row(i) / div);
            for(len_t j = 0; j < R; j++)
            {
                if(i != j)
                {
                    const T mul = temp[i][j];
                    res.set_col(j, res.col(j) - (res.col(i) * mul));
                    temp.set_row(j, temp.row(j) - (temp.row(i) * mul));
                }
            }
        }
        return res.transpose();
    }
    template <len_t N = R, len_t M = C, typename = typename std::enable_if_t<N == M>>
    inline constexpr Matrix<T, R, C> pow(const len_t& lhs) const
    {
        if(lhs == 0)
            return Matrix<T, R, C>::identity();
        else if(lhs == 1)
            return *this;
        else 
        {
            Matrix<T, R, C> res = *this;
            for(len_t j = 1; j < lhs; j++)
                res *= (*this);
            return res;
        }
    }
    template <len_t N = R, len_t M = C, typename = typename std::enable_if_t<N == M>>
    inline constexpr T determinant() const
    {
        T res = T(1);
        Matrix<T, R, C> temp = *this;
        for(len_t i = 0; i < R; i++)
        {
            const T div = temp[i][i];
            for(len_t j = i + 1; j < R; j++)
            {
                const T mul = temp[i][j];
                temp.set_row(j, temp.row(j) - (temp.row(i) / div * mul));
            }
        }
        for(len_t i = 0; i < R; i++)
        {
            res *= temp[i][i];
        }
        return res;
    }
    template <typename F> 
    inline constexpr operator Matrix<F, R, C>() const
    {
        Matrix<F, R, C> res;
        for(len_t i = 0; i < C; i++)
            res[i] = static_cast<Vector<F, R>>(cols[i]);
        return res;
    }
    inline constexpr const Vector<T, R>& operator[](const len_t& index) const
    {
        if(check_len(index, C))
            return cols[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr Vector<T, R>& operator[](const len_t& index)
    {
        if(check_len(index, C))
            return cols[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr T& operator()(const len_t& i, const len_t& j)
    {
        return (*this)[i][j];
    }
    inline constexpr const T& operator()(const len_t& i, const len_t& j) const
    {
        return (*this)[i][j];
    }
};

template <typename T, typename U, len_t TR, len_t TC, len_t UR, len_t UC>
struct are_same_tpl<Matrix<T, TR, TC>, Matrix<U, UR, UC>> : std::true_type {};

template <typename T, typename U, len_t R, len_t C, len_t N>
inline constexpr auto operator*(const Matrix<T, R, C>& lhs, const Matrix<U, C, N>& rhs)
{
    Matrix<decltype(lhs[0][0] * rhs[0][0]), R, N> res;
    for(len_t i = 0; i < N; i++)
        for(len_t j = 0; j < R; j++)
            res[i][j] = dot(lhs.row(j), rhs.col(i));
    return res;
}

template <typename T, typename U, len_t R, len_t C, len_t N>
inline constexpr auto operator*=(Matrix<T, R, C>& lhs, const Matrix<U, C, N>& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator/(const Matrix<T, R, C>& lhs, const Matrix<U, C, C>& rhs)
{
    return lhs * rhs.inverse();
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator/=(Matrix<T, R, C>& lhs, const Matrix<U, C, C>& rhs)
{
    lhs = lhs * rhs.inverse();
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*(const Matrix<T, R, C>& lhs, const Vector<U, C>& rhs)
{
    Vector<decltype(lhs[0][0] * rhs[0]), R> res;
    for(len_t i = 0; i < R; i++)
        res[i] = dot(lhs.row(i), rhs);
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*(const Vector<T, R>& lhs, const Matrix<U, R, C>& rhs)
{
    Vector<decltype(lhs[0] * rhs[0][0]), C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = dot(lhs, rhs[i]);
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator+(const Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)
{
    Matrix<decltype(lhs[0][0] + rhs[0][0]), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs[i] + rhs[i];
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator+=(Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)
{
    for(len_t i = 0; i < C; i++)
        lhs[i] += rhs[i];
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator-(const Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)
{
    Matrix<decltype(lhs[0][0] - rhs[0][0]), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs[i] - rhs[i];
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator-=(Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)
{
    for(len_t i = 0; i < C; i++)
        lhs[i] -= rhs[i];
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator+(const Matrix<T, R, C>& lhs, const U& rhs)
{
    Matrix<decltype(lhs[0][0] + rhs), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs[i] + rhs;
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator-(const Matrix<T, R, C>& lhs, const U& rhs)
{
    Matrix<decltype(lhs[0][0] - rhs), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs[i] - rhs;
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator/(const Matrix<T, R, C>& lhs, const U& rhs)
{
    Matrix<decltype(lhs[0][0] / rhs), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs[i] / rhs;
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*(const Matrix<T, R, C>& lhs, const U& rhs)
{
    Matrix<decltype(lhs[0][0] * rhs), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs[i] * rhs;
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator+(const T& lhs, const Matrix<U, R, C>& rhs)
{
    Matrix<decltype(lhs + rhs[0][0]), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs + rhs[i];
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator-(const T& lhs, const Matrix<U, R, C>& rhs)
{
    Matrix<decltype(lhs - rhs[0][0]), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs - rhs[i];
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator/(const T& lhs, const Matrix<U, R, C>& rhs)
{
    Matrix<decltype(lhs / rhs[0][0]), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs / rhs[i];
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*(const T& lhs, const Matrix<U, R, C>& rhs)
{
    Matrix<decltype(lhs * rhs[0][0]), R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = lhs * rhs[i];
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator+=(Matrix<T, R, C>& lhs, const U& rhs)
{
    for(len_t i = 0; i < C; i++)
        lhs[i] += rhs;
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator-=(Matrix<T, R, C>& lhs, const U& rhs)
{
    for(len_t i = 0; i < C; i++)
        lhs[i] -= rhs;
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator/=(Matrix<T, R, C>& lhs, const U& rhs)
{
    for(len_t i = 0; i < C; i++)
        lhs[i] /= rhs;
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*=(Matrix<T, R, C>& lhs, const U& rhs)
{
    for(len_t i = 0; i < C; i++)
        lhs[i] *= rhs;
    return lhs;
}

template <typename T, len_t R, len_t C>
inline constexpr Matrix<T, R, C>& operator++(Matrix<T, R, C>& lhs)
{
    for(len_t i = 0; i < C; i++)
        ++lhs[i];
    return lhs;
}

template <typename T, len_t R, len_t C>
inline constexpr Matrix<T, R, C>& operator--(Matrix<T, R, C>& lhs)
{
    for(len_t i = 0; i < C; i++)
        --lhs[i];
    return lhs;
}

template <typename T, len_t R, len_t C>
inline constexpr Matrix<T, R, C> operator++(Matrix<T, R, C>& lhs, int)
{
    const Matrix<T, R, C> res = lhs;
    ++lhs;
    return res;
}

template <typename T, len_t R, len_t C>
inline constexpr Matrix<T, R, C> operator--(Matrix<T, R, C>& lhs, int)
{
    const Matrix<T, R, C> res = lhs;
    --lhs;
    return res;
}

template <typename T, len_t R, len_t C>
inline constexpr Matrix<T, R, C> operator-(const Matrix<T, R, C>& lhs)
{
    Matrix<T, R, C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = -lhs[i];
    return res;
}

template <typename T, len_t R, len_t C>
inline constexpr Matrix<T, R, C> operator+(const Matrix<T, R, C>& lhs)
{
    return lhs;
}

template <typename T, len_t R, len_t C>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T, R, C>& mat)
{
    for(len_t i = 0; i < R; i++)
        os << mat.row(i);
    return os;
}

template <typename T, len_t R, len_t C>
inline std::istream& operator>>(std::istream& is, Matrix<T, R, C>& mat)
{
    Vector<T, C> vec;
    for(len_t i = 0; i < R; i++)
    {
        is >> vec;
        mat.set_row(i, vec);
    }
    return is;
}

define_matrix_comparison_operator(<=, and)
define_matrix_comparison_operator(>=, and)
define_matrix_comparison_operator(==, and)
define_matrix_comparison_operator(<, and)
define_matrix_comparison_operator(>, and)
define_matrix_comparison_operator(!=, or)

template <typename T> 
inline constexpr Matrix<T, 4, 4> make_perspective_mat(const T& aspect, const T& fov, const T& near, const T& far)
{
    const T half_fov = std::tan(deg2rad(fov) / T(2));
    return Matrix<T, 4, 4>
    {
        T(1) / (aspect * half_fov), T(0), T(0), T(0),
        T(0), T(1) / (half_fov), T(0), T(0),
        T(0), T(0), (near + far) / (near - far), (T(2) * far * near) / (near - far),
        T(0), T(0), T(-1), T(0)
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> make_ortho_mat(const T& right, const T& left, const T& bottom, const T& top, const T& near, const T& far)
{
    return Matrix<T, 4, 4>
    {
        T(2) / (right - left), T(0), T(0), (right + left) / (left - right),
        T(0), T(2) / (top - bottom), T(0), (top + bottom) / (bottom - top),
        T(0), T(0), T(2) / (near - far), (far + near) / (near - far),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> mat_look_at(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
{
    const Vector<T, 3> en = (center - eye).norm();
    Vector<T, 3> cn = up.norm();
    const Vector<T, 3> un = cross(en, cn).norm();
    cn = cross(un, en);
    return Matrix<T, 4, 4>
    {
        un.x, un.y, un.z, -dot(un, eye),
        cn.x, cn.y, cn.z, -dot(cn, eye),
        -en.x, -en.y, -en.z, dot(en, eye),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> rotation_mat_3d(const T& angle, const Vector<T, 3>& axis)
{
    const T c = std::cos(angle);
    const T s = std::sin(angle);
    const Vector<T, 3> norm = axis.norm();
    const Vector<T, 3> vec = norm * (1 - c);
    return Matrix<T, 4, 4>
    {
        c + vec.x * norm.x, vec.y * norm.x - s * norm.z, vec.z * norm.x + s * norm.y, T(0),
        vec.x * norm.y + s * norm.z, c + vec.y * norm.y, vec.z * norm.y - s * norm.x, T(0),
        vec.x * norm.z - s * norm.y, vec.y * norm.z + s * norm.x, c + vec.z * norm.z, T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_x(const T& angle)
{
    return Matrix<T, 4, 4>
    {
        T(1), T(0), T(0), T(0),
        T(0), std::cos(angle), -std::sin(angle), T(0),
        T(0), std::sin(angle), std::cos(angle), T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_y(const T& angle)
{
    return Matrix<T, 4, 4>
    {
        std::cos(angle), T(0), std::sin(angle), T(0),
        T(0), T(1), T(0), T(0),
        -std::sin(angle), T(0), std::cos(angle), T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_z(const T& angle)
{
    return Matrix<T, 4, 4>
    {
        std::cos(angle), -std::sin(angle), T(0), T(0),
        std::sin(angle), std::cos(angle), T(0), T(0),
        T(0), T(0), T(1), T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_from_euler(const Vector<T, 3>& vec)
{
    const T cr = std::cos(vec.roll);
    const T sr = std::sin(vec.roll);
    const T cp = std::cos(vec.pitch);
    const T sp = std::sin(vec.pitch);
    const T cy = std::cos(vec.yaw);
    const T sy = std::sin(vec.yaw);
    return Matrix<T, 4, 4>
    {
        cp * cy, sr * sp * cy - sy * cr, cr * sp * cy + sr * sy, T(0),
        cp * sy, sr * sp * sy + cr * cy, cr * sp * sy - sr * cy, T(0),
        -sp, sr * cp, cr * cp, T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> translation_mat_3d(const Vector<T, 3>& lhs)
{
    return Matrix<T, 4, 4>
    {
        T(1), T(0), T(0), lhs.x,
        T(0), T(1), T(0), lhs.y,
        T(0), T(0), T(1), lhs.z,
        T(0), T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> scale_mat_3d(const Vector<T, 3>& lhs)
{
    return Matrix<T, 4, 4>
    {
        lhs.x, T(0), T(0), T(0),
        T(0), lhs.y, T(0), T(0),
        T(0), T(0), lhs.z, T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Matrix<T, 3, 3> rotation_mat_2d(const T& angle)
{
    return Matrix<T, 3, 3>{rotation_mat_z(angle)};
}

template <typename T> 
inline constexpr Matrix<T, 3, 3> translation_mat_2d(const Vector<T, 2>& lhs)
{
    return Matrix<T, 3, 3>
    {
        T(1), T(0), lhs.x,
        T(0), T(1), lhs.y,
        T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Matrix<T, 3, 3> scale_mat_2d(const Vector<T, 2>& lhs)
{
    return Matrix<T, 3, 3>
    {
        lhs.x, T(0), T(0),
        T(0), lhs.y, T(0),
        T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Vector<T, 3> translation_from_mat_3d(const Matrix<T, 4, 4>& lhs)
{
    return {lhs[3][0], lhs[3][1], lhs[3][2]};
}

template <typename T> 
inline constexpr Vector<T, 3> scale_from_mat_3d(const Matrix<T, 4, 4>& lhs)
{
    return 
    {
        Vector<T, 3>{lhs[0].xyz}.mag(),
        Vector<T, 3>{lhs[1].xyz}.mag(),
        Vector<T, 3>{lhs[2].xyz}.mag()
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> rotation_from_mat_3d(const Matrix<T, 4, 4>& lhs)
{
    const Vector<T, 3> scale = scale_from_mat_3d(lhs);
    return Matrix<T, 4, 4>
    {
        Vector<T, 4>{lhs[0][0], lhs[1][0], lhs[2][0], T(0)} / scale.x,
        Vector<T, 4>{lhs[0][1], lhs[1][1], lhs[2][1], T(0)} / scale.y,
        Vector<T, 4>{lhs[0][2], lhs[1][2], lhs[2][2], T(0)} / scale.z,
        Vector<T, 4>{T(0), T(0), T(0), T(1)}
    };
}

template <typename T> 
inline constexpr Vector<T, 2> translation_from_mat_2d(const Matrix<T, 3, 3>& lhs)
{
    return {lhs[2][0], lhs[2][1]};
}

template <typename T> 
inline constexpr Vector<T, 2> scale_from_mat_2d(const Matrix<T, 3, 3>& lhs)
{
    return 
    {
        Vector<T, 2>{lhs[0].xy}.mag(),
        Vector<T, 2>{lhs[1].xy}.mag()
    };
}

template <typename T> 
inline constexpr T rotation_from_mat_2d(const Matrix<T, 3, 3>& lhs)
{
    return std::atan2(lhs[0][1], lhs[0][0]);
}

template <typename T> 
inline constexpr Vector<T, 3> euler_from_mat(const Matrix<T, 4, 4>& lhs)
{
    if(std::abs(lhs[0][2]) != T(1))
    {
        const T pitch = -std::asin(lhs[0][2]);
        const T c = std::cos(pitch);
        return 
        {
            std::atan2(lhs[1][2] / c, lhs[2][2] / c),
            pitch,
            std::atan2(lhs[0][1] / c, lhs[0][0] / c)
        };
    }
    if(lhs[0][2] == T(-1))
        return 
        {
            std::atan2(lhs[1][0], lhs[2][0]),
            T(half_pi),
            T(0)
        };
    else
        return 
        {
            std::atan2(-lhs[1][0], -lhs[2][0]),
            -T(half_pi),
            T(0)
        };
}

template <typename T> 
inline constexpr Vector<T, 3> euler_from_axis(const T& angle, const Vector<T, 3>& axis)
{
    const Vector<T, 3> norm = axis.norm();
    const T s = std::sin(angle);
    const T h = std::sin(angle / T(2));
    const T v = T(2) * h * h;
    return
    {
        std::atan2
        (
            norm.x * s + norm.y * norm.z * v, 
            T(1) - (norm.x * norm.x + norm.y * norm.y) * v
        ),
        T(2) * std::atan2
        (
            std::sqrt(T(1) + norm.y * s - v * norm.x * norm.z),
            std::sqrt(T(1) - norm.y * s + v * norm.x * norm.z)
        ) - T(half_pi),
        std::atan2
        (
            norm.z * s + v * norm.x * norm.y,
            T(1) - v * (norm.y * norm.y + norm.z * norm.z)
        )
    };
}

template <typename T, len_t N, len_t M>
inline constexpr const uint32_t hash(const Matrix<T, N, M>& lhs)
{
    return hash(reinterpret_cast<const uint8_t*>(&lhs[0][0]), sizeof(T) * N * M);
}

typedef Matrix<float, 2, 2> mat2;
typedef Matrix<double, 2, 2> dmat2;
typedef Matrix<float, 3, 3> mat3;
typedef Matrix<double, 3, 3> dmat3;
typedef Matrix<float, 4, 4> mat4;
typedef Matrix<double, 4, 4> dmat4;

template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>> 
struct Quaternion
{
    union
    {
        struct { T w, x, y, z; };
        struct { T scalar; Vector<T, 3> vec; };
    };
    inline constexpr Quaternion& operator=(const Quaternion& lhs) = default;
    inline constexpr Quaternion(const Quaternion& lhs) = default;
    inline constexpr Quaternion(Quaternion&& lhs) = default;
    inline constexpr Quaternion() : scalar(T(1)), vec(T(0)) {}
    inline constexpr Quaternion(const T& lhs, const Vector<T, 3>& rhs) : scalar(lhs), vec(rhs) {}
    inline constexpr Quaternion(const T& w, const T& x, const T& y, const T& z) : w(w), x(x), y(y), z(z) {}
    static inline constexpr Quaternion<T> identity()
    {
        return {};
    }
    inline constexpr Quaternion<T> conjugate() const
    {
        return {w, -vec};
    }
    inline constexpr Quaternion<T> inverse() const
    {
        const T mag = this->mag2();
        if(mag == T(0)) return {};
        return {w / mag, -vec / mag};
    }
    inline constexpr T mag2() const
    {
        return vec.mag2() + w * w;
    }
    inline constexpr T norm() const
    {
        return std::sqrt(this->mag2());
    }
    inline constexpr Quaternion<T> normalize() const
    {
        const T mag = this->norm();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    inline constexpr Vector<T, 3> rotate(const Vector<T, 3>& lhs) const
    {
        return T(2) * dot(vec, lhs) * vec + (w * w - vec.mag2()) * lhs + T(2) * w * cross(vec, lhs);
    }
    inline constexpr T& operator[](const len_t& index)
    {
        switch(index)
        {
            case 0: return w;
            case 1: return x;
            case 2: return y;
            case 3: return z;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        switch(index)
        {
            case 0: return w;
            case 1: return x;
            case 2: return y;
            case 3: return z;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Quaternion<T>& quat)
    {
        os << '{' << quat.w << ',' << quat.vec << '}';
        return os;
    }
    inline friend std::istream& operator>>(std::istream& is, Quaternion<T>& quat)
    {
        char c;
        while(is >> c)
        {
            if(c == '{')
                is >> quat.w;
            else if(c == ',')
                is >> quat.vec;
            else if(c == '}')
                return is;
        }
        return is;
    }
    template <typename F> 
    inline constexpr operator Quaternion<F>() const
    {
        return 
        {
            static_cast<F>(w),
            static_cast<Vector<F, 3>>(vec)
        };
    }
};

typedef Quaternion<float> quatf;
typedef Quaternion<double> quatd;
typedef quatf quat;

template <typename T, typename U>
inline constexpr bool operator==(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    return lhs.w == rhs.w && lhs.vec == rhs.vec;
}

template <typename T, typename U>
inline constexpr bool operator!=(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    return !(lhs == rhs);
}

template <typename T, typename U>
inline constexpr auto operator*(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs.w * rhs.w)>
    {
        lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
        lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
        lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w
    };
}

template <typename T, typename U>
inline constexpr auto operator/(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    return lhs * rhs.inverse();
}

template <typename T, typename U>
inline constexpr auto operator+(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs.w + rhs.w)>{lhs.w + rhs.w, lhs.vec + rhs.vec};
}

template <typename T, typename U>
inline constexpr auto operator-(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs.w - rhs.w)>{lhs.w - rhs.w, lhs.vec - rhs.vec};
}

template <typename T, typename U>
inline constexpr auto operator/(const Quaternion<T>& lhs, const U& rhs)
{
    return Quaternion<decltype(lhs.w / rhs)>{lhs.w / rhs, lhs.vec / rhs};
}

template <typename T, typename U>
inline constexpr auto operator*(const Quaternion<T>& lhs, const U& rhs)
{
    return Quaternion<decltype(lhs.w * rhs)>{lhs.w * rhs, lhs.vec * rhs};
}

template <typename T, typename U>
inline constexpr auto operator+(const Quaternion<T>& lhs, const U& rhs)
{
    return Quaternion<decltype(lhs.w + rhs)>{lhs.w + rhs, lhs.vec + rhs};
}

template <typename T, typename U>
inline constexpr auto operator-(const Quaternion<T>& lhs, const U& rhs)
{
    return Quaternion<decltype(lhs.w - rhs)>{lhs.w - rhs, lhs.vec - rhs};
}

template <typename T, typename U>
inline constexpr auto operator/(const T& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs / rhs.w)>{lhs / rhs.w, lhs / rhs.vec};
}

template <typename T, typename U>
inline constexpr auto operator*(const T& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs * rhs.w)>{lhs * rhs.w, lhs * rhs.vec};
}

template <typename T, typename U>
inline constexpr auto operator+(const T& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs + rhs.w)>{lhs + rhs.w, lhs + rhs.vec};
}

template <typename T, typename U>
inline constexpr auto operator-(const T& lhs, const Quaternion<U>& rhs)
{
    return Quaternion<decltype(lhs - rhs.w)>{lhs - rhs.w, lhs - rhs.vec};
}

template <typename T, typename U>
inline constexpr auto operator+=(Quaternion<T>& lhs, const U& rhs)
{
    lhs.w += rhs;
    lhs.vec += rhs;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator-=(Quaternion<T>& lhs, const U& rhs)
{
    lhs.w -= rhs;
    lhs.vec -= rhs;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator*=(Quaternion<T>& lhs, const U& rhs)
{
    lhs.w *= rhs;
    lhs.vec *= rhs;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator/=(Quaternion<T>& lhs, const U& rhs)
{
    lhs.w /= rhs;
    lhs.vec /= rhs;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator+=(Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    lhs.w += rhs.w;
    lhs.vec += rhs.vec;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator-=(Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    lhs.w -= rhs.w;
    lhs.vec -= rhs.vec;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator*=(Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T, typename U>
inline constexpr auto operator/=(Quaternion<T>& lhs, const Quaternion<U>& rhs)
{
    lhs = lhs * rhs.inverse();
    return lhs;
}

template <typename T>
inline constexpr Quaternion<T>& operator++(Quaternion<T>& lhs)
{
    ++lhs.w;
    ++lhs.vec;
    return lhs; 
}

template <typename T>
inline constexpr Quaternion<T>& operator--(Quaternion<T>& lhs)
{
    --lhs.w;
    --lhs.vec;
    return lhs;
}

template <typename T>
inline constexpr Quaternion<T> operator++(Quaternion<T>& lhs, int)
{
    const Quaternion<T> res = lhs;
    ++lhs;
    return res;
}

template <typename T>
inline constexpr Quaternion<T> operator--(Quaternion<T>& lhs, int)
{
    const Quaternion<T> res = lhs;
    --lhs;
    return res;
}

template <typename T>
inline constexpr Quaternion<T> operator-(const Quaternion<T>& lhs)
{
    return {-lhs.w, -lhs.vec};
}

template <typename T>
inline constexpr Quaternion<T> operator+(const Quaternion<T>& lhs)
{
    return lhs;
}

template <typename T> 
inline constexpr Quaternion<T> quat_from_euler(const Vector<T, 3>& lhs)
{
    Quaternion<T> res;
    const Vector<T, 3> vec = lhs / T(2);
    const T cr = std::cos(vec.roll);
    const T sr = std::sin(vec.roll);
    const T cp = std::cos(vec.pitch);
    const T sp = std::sin(vec.pitch);
    const T cy = std::cos(vec.yaw);
    const T sy = std::sin(vec.yaw);
    res.w = cr * cp * cy + sr * sp * sy;
    res.x = sr * cp * cy - cr * sp * sy;
    res.y = cr * sp * cy + sr * cp * sy;
    res.z = cr * cp * sy - sr * sp * cy;
    return res;
}

template <typename T> 
inline constexpr Quaternion<T> quat_from_axis(const Vector<T, 3>& axis, const T& angle)
{
    Quaternion<T> res;
    res.w = std::cos(angle / T(2));
    res.vec = std::sin(angle / T(2)) * axis;
    return res;
}

template <typename T> 
inline constexpr Vector<T, 3> quat_to_euler(const Quaternion<T>& lhs)
{
    return 
    {
        std::atan2
        (
            T(2) * (lhs.w * lhs.x + lhs.y * lhs.z),
            T(1) - T(2) * (lhs.x * lhs.x + lhs.y * lhs.y)
        ),
        T(2) * std::atan2
        (
            std::sqrt(T(1) + T(2) * (lhs.w * lhs.y - lhs.x * lhs.z)),
            std::sqrt(T(1) - T(2) * (lhs.w * lhs.y - lhs.x * lhs.z))
        ) - T(half_pi),
        std::atan2
        (
            T(2) * (lhs.w * lhs.z + lhs.x * lhs.y),
            T(1) - T(2) * (lhs.y * lhs.y + lhs.z * lhs.z)
        )
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> mat_from_quat(const Quaternion<T>& lhs)
{
    const T sx = lhs.x * lhs.x;
    const T sy = lhs.y * lhs.y;
    const T sz = lhs.z * lhs.z;
    const T sw = lhs.w * lhs.w;
    const T xy = lhs.x * lhs.y;
    const T zw = lhs.z * lhs.w;
    const T xw = lhs.w * lhs.x;
    const T yz = lhs.z * lhs.y;
    const T xz = lhs.z * lhs.x;
    const T yw = lhs.w * lhs.y;
    const T inv = T(1) / (sx + sy + sz + sw);
    return Matrix<T, 4, 4>
    {
        T(1) - T(2) * (sy + sz) * inv, T(2) * (xy - zw) * inv, T(2) * (xz + yw) * inv, T(0),
        T(2) * (xy + zw) * inv, T(1) - T(2) * (sx + sz) * inv, T(2) * (yz - xw) * inv, T(0),
        T(2) * (xz - yw) * inv, T(2) * (yz + xw) * inv, T(1) - T(2) * (sx + sy) * inv, T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T> 
inline constexpr Quaternion<T> quat_from_mat(const Matrix<T, 4, 4>& lhs)
{
    Quaternion<T> res;
    res.w = std::sqrt(std::max(T(0), T(1) + lhs[0][0] + lhs[1][1] + lhs[2][2])) / T(2);
    res.x = std::sqrt(std::max(T(0), T(1) + lhs[0][0] - lhs[1][1] - lhs[2][2])) / T(2);
    res.y = std::sqrt(std::max(T(0), T(1) - lhs[0][0] + lhs[1][1] - lhs[2][2])) / T(2);
    res.z = std::sqrt(std::max(T(0), T(1) - lhs[0][0] - lhs[1][1] + lhs[2][2])) / T(2);
    res.x = std::copysign(res.x, lhs[2][1] - lhs[1][2]);
    res.y = std::copysign(res.y, lhs[0][2] - lhs[2][0]);
    res.z = std::copysign(res.z, lhs[1][0] - lhs[0][1]);
    return res;
}

template <typename T> 
inline constexpr T quat_to_axis(const Quaternion<T>& lhs, Vector<T, 3>& rhs)
{
    const T div = std::sqrt(T(1) - lhs.w * lhs.w);
    rhs = lhs.vec / (div == T(0) ? Vector<T, 3>::right() : div);
    return T(2) * std::acos(lhs.w);
}

template <typename T> 
inline constexpr Quaternion<T> slerp(const Quaternion<T>& lhs, const Quaternion<T>& rhs, const double t)
{
    const T ch = lhs.w * rhs.w + dot(lhs.vec, rhs.vec);
    if(std::abs(ch) >= T(1))
    {
        return lhs;
    }
    const T ht = std::acos(ch);
    const T sh = std::sqrt(T(1) - ch * ch);
    if(std::abs(sh) == T(0))
    {
        return 
        {
            lhs.w / T(2) + rhs.w / T(2),
            lhs.vec / T(2) + rhs.vec / T(2)
        };
    }
    const T ra = std::sin((1 - t) * ht) / sh;
    const T rb = std::sin(t * ht) / sh;
    return 
    {
        lhs.w * ra + rhs.w * rb,
        lhs.vec * ra + rhs.vec * rb
    };
}

template <typename T> 
inline constexpr Vector<T, 2> rotate(const T& angle, const Vector<T, 2>& vec, const Vector<T, 2>& origin = T(0))
{
    if(mod(angle, T(two_pi)) == T(0))
        return vec;
    return origin + Vector<T, 2>
    {
        std::cos(angle) * (vec.x - origin.x) - std::sin(angle) * (vec.y - origin.y),
        std::sin(angle) * (vec.x - origin.x) + std::cos(angle) * (vec.y - origin.y)
    };
}

template <typename T>
inline constexpr const uint32_t hash(const Quaternion<T>& lhs)
{
    return hash(reinterpret_cast<const uint8_t*>(&lhs[0]), sizeof(T) * 4);
}

template <typename T, len_t N> 
inline Vector<T, N> rand(const T& lhs, const T& rhs)
{
    Vector<T, N> res;
    for(len_t i = 0; i < N; i++)
        res[i] = rand(lhs, rhs);
    return res;
}

template <typename T, len_t N, len_t M> 
inline Matrix<T, N, M> rand(const T& lhs, const T& rhs)
{
    Matrix<T, N, M> res;
    for(len_t i = 0; i < N; i++)
        for(len_t j = 0; j < M; j++)
            res[j][i] = rand(lhs, rhs);
    return res;
}

template <typename T>
inline constexpr T grad(const uint8_t hash, const T& x)
{
    return (hash & 1) ? x : -x;
}

template <typename T>
inline constexpr T perlin(const T& x)
{
    const int xi = (int)x & 0xFF;
    const T xf = fract(x);
    const T u = fade(xf);
    const uint8_t a = p[xi + 0];
    const uint8_t b = p[xi + 1];
    return (lerp(grad(a, xf), grad(b, xf - T(1)), u) + T(1)) / T(2);
}

template <typename T>
inline constexpr T grad(const uint8_t hash, const T& x, const T& y)
{
    switch (hash & 7) 
    {
        case 0: return x + y;
        case 1: return x;
        case 2: return x - y;
        case 3: return -y;
        case 4: return -x - y;
        case 5: return -x;
        case 6: return -x + y;
        case 7: return y;
        default: return T(0);
    }
}

template <typename T>
inline constexpr T perlin(const T& x, const T& y)
{
    const int xi = (int)x & 0xFF;
    const int yi = (int)y & 0xFF;
    const T xf = fract(x);
    const T yf = fract(y);
    const T u = fade(xf);
    const T v = fade(yf);
    const uint8_t aa = p[p[xi + 0] + yi + 0];
    const uint8_t ab = p[p[xi + 0] + yi + 1];
    const uint8_t ba = p[p[xi + 1] + yi + 0];
    const uint8_t bb = p[p[xi + 1] + yi + 1];
    const T x1 = lerp(grad(aa, xf, yf), grad(ba, xf - T(1), yf), u);
    const T x2 = lerp(grad(ab, xf, yf - T(1)), grad(bb, xf - T(1), yf - T(1)), u);
    return (lerp(x1, x2, v) + T(1)) / T(2);
}

template <typename T>
inline constexpr T perlin(const Vector<T, 2>& lhs)
{
    return perlin(lhs.x, lhs.y);
}

template <typename T>
inline constexpr T grad(const uint8_t hash, const T& x, const T& y, const T& z)
{
    switch(hash & 15)
    {
        case 0: return x + y;
        case 1: return -x + y;
        case 2: return x - y;
        case 3: return -x - y;
        case 4: return x + z;
        case 5: return -x + z;
        case 6: return x - z;
        case 7: return -x - z;
        case 8: return y + z;
        case 9: return -y + z;
        case 10: return y - z;
        case 11: return -y - z;
        case 12: return y + x;
        case 13: return -y + z;
        case 14: return y - x;
        case 15: return -y - z;
        default: return T(0);
    }
}

template <typename T>
inline constexpr T perlin(const T& x, const T& y, const T& z)
{
    const int xi = (int)x & 0xFF;
    const int yi = (int)y & 0xFF;
    const int zi = (int)z & 0xFF;
    const T xf = fract(x);
    const T yf = fract(y);
    const T zf = fract(z);
    const T u = fade(xf);
    const T v = fade(yf);
    const T w = fade(zf);
    const uint8_t aaa = p[p[p[xi + 0] + yi + 0] + zi + 0];
    const uint8_t aba = p[p[p[xi + 0] + yi + 1] + zi + 0];
    const uint8_t aab = p[p[p[xi + 0] + yi + 0] + zi + 1];
    const uint8_t abb = p[p[p[xi + 0] + yi + 1] + zi + 1];
    const uint8_t baa = p[p[p[xi + 1] + yi + 0] + zi + 0];
    const uint8_t bba = p[p[p[xi + 1] + yi + 1] + zi + 0];
    const uint8_t bab = p[p[p[xi + 1] + yi + 0] + zi + 1];
    const uint8_t bbb = p[p[p[xi + 1] + yi + 1] + zi + 1];
    T x1, x2;
    x1 = lerp(grad(aaa, xf, yf, zf), grad(baa, xf - T(1), yf, zf), u);
    x2 = lerp(grad(aba, xf, yf - T(1), zf), grad(bba, xf - T(1), yf - T(1), zf), u);
    const T y1 = lerp(x1, x2, v);
    x1 = lerp(grad(aab, xf, yf, zf - T(1)), grad(bab, xf - T(1), yf, zf - T(1)), u);
    x2 = lerp(grad(abb, xf, yf - T(1), zf - T(1)), grad(bbb, xf - T(1), yf - T(1), zf - T(1)), u);
    const T y2 = lerp(x1, x2, v);
    return (lerp(y1, y2, w) + T(1)) / T(2);
}

template <typename T>
inline constexpr T perlin(const Vector<T, 3>& lhs)
{
    return perlin(lhs.x, lhs.y, lhs.z);
}

template <typename T, len_t N> 
inline constexpr Vector<T, N> closest_point_on_line(const Vector<T, N>& start, const Vector<T, N>& end, const Vector<T, N>& p)
{
    const Vector<T, N> d = end - start;
    const T val = dot(p - start, d) / dot(d, d);
    return start + std::clamp(val, T(0), T(1)) * d;
}

template <typename T>
inline constexpr T triangle_area(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2)
{
    return std::abs(
        pos0.x * (pos1.y - pos2.y) +
        pos1.x * (pos2.y - pos0.y) +
        pos2.x * (pos0.y - pos1.y)
    ) / T(2);
}

template <typename T>
inline constexpr T triangle_area(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
{
    const Vector<T, 3> side0 = (pos1 - pos0);
    const Vector<T, 3> side1 = (pos2 - pos0);
    const double angle = std::acos(dot(side0, side1) / (side0.mag() * side1.mag()));
    return std::sin(angle) * side0.mag() * side1.mag() / T(2);
}

template <typename T>
inline constexpr bool point_in_triangle(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2, const Vector<T, 2>& p)
{
    return (double)std::abs(triangle_area(pos0, pos1, pos2) - (triangle_area(pos0, pos1, p) + 
        triangle_area(pos0, pos2, p) + triangle_area(pos1, pos2, p))) < epsilon;
}

template <typename T>
inline bool point_in_poly(const std::vector<Vector<T, 2>>& poly, const Vector<T, 2>& vec)
{
    for(len_t i = 1; i < poly.size(); i++)
        if(point_in_triangle(poly[0], poly[i], poly[(i + 1) % poly.size()], vec))
            return true;
    return false;
}

template <typename T>
inline constexpr Vector<T, 2> project(const Vector<T, 2>& vec, const Vector<T, 2>& norm)
{
    return norm * dot(vec, norm) / norm.mag2();
}

template <typename T>
inline constexpr Vector<T, 3> project(const Vector<T, 3>& vec, const Vector<T, 3>& norm)
{
    const T mag = norm.mag2();
    const T d = dot(vec, norm);
    if(mag < epsilon) return T(0);
    return norm * d / mag;
}

template <typename T>
inline constexpr Vector<T, 3> project_onto_plane(const Vector<T, 3>& vec, const Vector<T, 3>& norm)
{
    const T mag = norm.mag2();
    const T d = dot(vec, norm);
    if(mag < epsilon) return vec;
    return vec - norm * d / mag;
}

template <typename T, len_t N>
inline constexpr bool aabb_overlap(const Vector<T, N>& pos0, const Vector<T, N>& size0, const Vector<T, N>& pos1, const Vector<T, N>& size1)
{
    for(len_t i = 0; i < N; i++)
        if(pos0[i] - size0[i] / T(2) > pos1[i] + size1[i] / T(2) || pos0[i] + size0[i] / T(2) < pos1[i] - size1[i] / T(2))
            return false;
    return true;
}

template <typename T, len_t N>
inline bool sat_seperated(const std::vector<Vector<T, N>>& poly0, const std::vector<Vector<T, N>>& poly1, const Vector<T, N>& axis)
{
    T min0 = T(INFINITY), max0 = T(-INFINITY);
    for(len_t k = 0; k < poly0.size(); k++)
    {
        const T res = dot(poly0[k], axis);
        min0 = std::min(min0, res);
        max0 = std::max(max0, res);
    }
    T min1 = T(INFINITY), max1 = T(-INFINITY);
    for(len_t p = 0; p < poly1.size(); p++)
    {
        const T res = dot(poly1[p], axis);
        min1 = std::min(min1, res);
        max1 = std::max(max1, res);
    }
    return !(max1 >= min0 && max0 >= min1);
}

template <typename T>
inline bool sat_check(const std::vector<Vector<T, 2>>& poly0, const std::vector<Vector<T, 2>>& poly1)
{
    for(len_t i = 0; i < poly0.size(); i++)
    {
        const len_t j = (i + 1) % poly0.size();
        const Vector<T, 2> proj = {poly0[i].y - poly0[j].y, poly0[j].x - poly0[i].x};
        if(sat_seperated(poly0, poly1, proj)) return false;
    }
    return true;
}

template <typename T>
inline bool sat_overlap(const std::vector<Vector<T, 3>>& poly0, const std::vector<Vector<T, 3>>& poly1, const std::vector<Vector<T, 3>>& axes)
{
    for(len_t i = 0; i < axes.size(); i++)
        if(sat_seperated(poly0, poly1, axes[i]))
            return false;
    return true;
}

template <typename T>
inline bool sat_overlap(const std::vector<Vector<T, 2>>& poly0, const std::vector<Vector<T, 2>>& poly1)
{
    return sat_check(poly0, poly1) && sat_check(poly1, poly0);
}

template <typename T, len_t N>
inline Vector<T, N> get_closest_point_on_poly(const std::vector<Vector<T, N>>& poly, const Vector<T, N>& vec)
{
    T distance = T(INFINITY);
    Vector<T, N> res;
    for(len_t i = 0; i < poly.size(); i++)
    {
        const len_t j = (i + 1) % poly.size();
        const Vector<T, N> point = closest_point_on_line(poly[i], poly[j], vec);
        const T mag = (point - vec).mag();
        if(mag < distance)
        {
            res = point;
            distance = mag;
        }
    }
    return res;
}

template <typename T, len_t N>
inline T get_closest_distance_to_poly(const std::vector<Vector<T, N>>& poly, const Vector<T, N>& vec)
{
    return (get_closest_point_on_poly(poly, vec) - vec).mag();
}

template <typename T>
inline constexpr Vector<T, 3> surface_normal(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
{
    return cross(pos1 - pos0, pos2 - pos0).norm();
}

template <typename T, len_t N> 
struct BoundingBox {};

template <typename T> 
struct BoundingBox<T, 3>
{
    Vector<T, 3> pos;
    Vector<T, 3> size;
    Vector<T, 3> rotation;
    inline constexpr BoundingBox() = default;
    inline constexpr BoundingBox& operator=(const BoundingBox<T, 3>& lhs) = default;
    inline constexpr BoundingBox(BoundingBox<T, 3>&& lhs) = default;
    inline constexpr BoundingBox(const BoundingBox<T, 3>& lhs) = default;
    inline constexpr BoundingBox(const Vector<T, 3>& pos, const Vector<T, 3>& size, const Vector<T, 3>& rotation = T(0)) 
    : pos(pos), size(size), rotation(rotation) {}
    inline bool Overlaps(const Vector<T, 3>& p)
    {
        const Matrix<T, 4, 4> inv = (translation_mat_3d(pos) * rotation_mat_from_euler(rotation) * scale_mat_3d(size)).inverse();
        const Vector<T, 4> transformed = inv * Vector<T, 4>{p, T(1)};
        return aabb_overlap(Vector<T, 3>::zero(), Vector<T, 3>::one(), transformed.xyz, Vector<T, 3>::zero());
    }
    inline bool Overlaps(const BoundingBox<T, 3>& box)
    {
        if(mod(rotation, T(two_pi)) == T(0) && mod(box.rotation, T(two_pi)) == T(0))
            return aabb_overlap(pos, size, box.pos, box.size);
        std::vector<Vector<T, 3>> all_axes;
        all_axes.reserve(15);
        const std::vector<Vector<T, 3>> axes0 = GetAxes();
        const std::vector<Vector<T, 3>> axes1 = box.GetAxes();
        all_axes.push_back(axes0[0]);
        all_axes.push_back(axes0[1]);
        all_axes.push_back(axes0[2]);
        all_axes.push_back(axes1[0]);
        all_axes.push_back(axes1[1]);
        all_axes.push_back(axes1[2]);
        all_axes.push_back(cross(axes0[0], axes1[0]));
        all_axes.push_back(cross(axes0[1], axes1[0]));
        all_axes.push_back(cross(axes0[2], axes1[0]));
        all_axes.push_back(cross(axes0[0], axes1[1]));
        all_axes.push_back(cross(axes0[1], axes1[1]));
        all_axes.push_back(cross(axes0[2], axes1[1]));
        all_axes.push_back(cross(axes0[0], axes1[2]));
        all_axes.push_back(cross(axes0[1], axes1[2]));
        all_axes.push_back(cross(axes0[2], axes1[2]));
        return sat_overlap(box.GetVertices(), GetVertices(), all_axes);
    }
    inline bool Overlaps(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
    {
        const Vector<T, 3> norm = surface_normal(pos0, pos1, pos2);
        std::vector<Vector<T, 3>> all_axes = GetAxes();
        all_axes.push_back(cross(norm, all_axes[0]));
        all_axes.push_back(cross(norm, all_axes[1]));
        all_axes.push_back(cross(norm, all_axes[2]));
        all_axes.push_back(norm);
        return sat_overlap(GetVertices(), {pos0, pos1, pos2}, all_axes);
    }
    inline std::vector<Vector<T, 3>> GetVertices() const
    {
        const Vector<T, 3> half = size / T(2);
        const Quaternion<T> quat = quat_from_euler(rotation);
        return
        {
            pos + quat.rotate(Vector<T, 3>{-half.x, -half.y, -half.z}),
            pos + quat.rotate(Vector<T, 3>{-half.x, -half.y,  half.z}),
            pos + quat.rotate(Vector<T, 3>{-half.x,  half.y,  half.z}),
            pos + quat.rotate(Vector<T, 3>{-half.x,  half.y, -half.z}),
            pos + quat.rotate(Vector<T, 3>{ half.x, -half.y, -half.z}),
            pos + quat.rotate(Vector<T, 3>{ half.x,  half.y, -half.z}),
            pos + quat.rotate(Vector<T, 3>{ half.x, -half.y,  half.z}),
            pos + quat.rotate(Vector<T, 3>{ half.x,  half.y,  half.z})
        };
    }
    inline std::vector<Vector<T, 3>> GetAxes() const
    {
        const Quaternion<T> quat = quat_from_euler(rotation);
        return 
        {
            quat.rotate(Vector<T, 3>::right()),
            quat.rotate(Vector<T, 3>::up()),
            quat.rotate(Vector<T, 3>::forward())
        };
    }
    inline friend constexpr BoundingBox<T, 3> operator*=(BoundingBox<T, 3>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        lhs.pos += translation_from_mat_3d(rhs);
        lhs.size *= scale_from_mat_3d(rhs);
        lhs.rotation = quat_to_euler(quat_from_euler(lhs.rotation) * quat_from_mat(rotation_from_mat_3d(rhs)));
        return lhs;
    }
    inline friend constexpr BoundingBox<T, 3> operator*(const BoundingBox<T, 3>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        BoundingBox<T, 3> res = lhs;
        res *= rhs;
        return res;
    }
};

template <typename T> 
struct BoundingBox<T, 2>
{
    Vector<T, 2> pos;
    Vector<T, 2> size;
    T rotation = T(0);
    inline constexpr BoundingBox() = default;
    inline constexpr BoundingBox& operator=(const BoundingBox<T, 2>& lhs) = default;
    inline constexpr BoundingBox(BoundingBox<T, 2>&& lhs) = default;
    inline constexpr BoundingBox(const BoundingBox<T, 2>& lhs) = default;
    inline constexpr BoundingBox(const Vector<T, 2>& pos, const Vector<T, 2>& size, const T& rotation = T(0)) 
    : pos(pos), size(size), rotation(rotation) {}
    inline bool Overlaps(const Vector<T, 2>& p) const
    {
        const std::vector<Vector<T, 2>> vertices = GetVertices();
        return (double)std::abs(size.area() - (triangle_area(vertices[0], p, vertices[1]) + triangle_area(vertices[1], p, vertices[2]) +
            triangle_area(vertices[2], p, vertices[3]) + triangle_area(vertices[0], p, vertices[3]))) < epsilon;
    }
    inline bool Overlaps(const BoundingBox<T, 2>& box) const
    {
        if(mod(rotation, T(two_pi)) == T(0) && mod(box.rotation, T(two_pi)) == T(0))
            return aabb_overlap(pos, size, box.pos, box.size);
        return sat_overlap(box.GetVertices(), GetVertices());
    }
    inline const bool Overlaps(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2) const
    {
        return this->Overlaps({pos0, pos1, pos2});
    }
    inline const bool Overlaps(const std::vector<Vector<T, 2>>& vertices) const
    {
        return sat_overlap(this->GetVertices(), vertices);
    }
    inline std::vector<Vector<T, 2>> GetVertices() const
    {
        const Vector<T, 2> half = size / T(2);
        return 
        {
            pos + rotate<T>(rotation, -half),
            pos + rotate<T>(rotation, {half.w, -half.h}),
            pos + rotate<T>(rotation, half),
            pos + rotate<T>(rotation, {-half.w, half.h})
        };
    }
    inline friend constexpr BoundingBox<T, 2> operator*=(BoundingBox<T, 2>& lhs, const Matrix<T, 3, 3>& rhs)
    {
        lhs.pos += translation_from_mat_2d(rhs);
        lhs.size *= scale_from_mat_2d(rhs);
        lhs.rotation += rotation_from_mat_2d(rhs);
        return lhs;
    }
    inline friend constexpr BoundingBox<T, 2> operator*(const BoundingBox<T, 2>& lhs, const Matrix<T, 3, 3>& rhs)
    {
        BoundingBox<T, 2> res = lhs;
        res *= rhs;
        return res;
    }
};

template <typename T, len_t N> 
struct BoundingSphere
{
    static_assert(N == 2 || N == 3);
    Vector<T, N> pos;
    T radius;
    inline constexpr BoundingSphere() = default;
    inline constexpr BoundingSphere& operator=(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(BoundingSphere<T, N>&& lhs) = default;
    inline constexpr BoundingSphere(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(const Vector<T, N>& pos, const T& radius) : pos(pos), radius(radius) {}
    inline constexpr bool Overlaps(const Vector<T, N>& p) const
    {
        return (p - pos).mag() <= radius;
    }
    inline bool Overlaps(const BoundingBox<T, N>& box) const
    {
        return get_closest_distance_to_poly(box.GetVertices(), pos) <= radius;
    }
    inline constexpr bool Overlaps(const BoundingSphere<T, N>& sphere) const
    {
        return (pos - sphere.pos).mag() <= (radius + sphere.radius);
    }
    inline bool Overlaps(const Vector<T, N>& pos0, const Vector<T, N>& pos1, const Vector<T, N>& pos2) const
    {
        return this->Overlaps({pos0, pos1, pos2});
    }
    inline bool Overlaps(const std::vector<Vector<T, N>>& vertices) const
    {
        return get_closest_distance_to_poly(vertices, pos) <= radius;
    }
};

enum class Intersection : uint8_t
{
    Intersects = 1,
    Back = 2,
    Front = 3
};

template <typename T>
struct Plane
{
    Vector<T, 3> normal;
    T distance;
    inline constexpr Plane() = default;
    inline constexpr Plane& operator=(const Plane& plane) = default;
    inline constexpr Plane(const Plane& plane) = default;
    inline constexpr Plane(Plane&& plane) = default;
    inline constexpr Plane(const Vector<T, 3>& normal, const T& distance) : normal(normal), distance(distance) {}
    inline constexpr Plane(const Vector<T, 3>& pos, const Vector<T, 3>& norm)
    : normal(norm.norm()), distance(dot(normal, pos)) {}
    inline constexpr Plane(const Vector<T, 4>& vec) : normal(vec.xyz), distance(vec.w) {}
    inline constexpr Intersection Intersects(const BoundingBox<T, 3>& box) const
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr Intersection Intersects(const BoundingSphere<T, 3>& sphere) const
    {
        const T d = Distance(sphere.pos);
        if(std::abs(d) <= sphere.radius)
            return Intersection::Intersects;
        else if(d > T(0))
            return Intersection::Front;
        else
            return Intersection::Back;
    }
    inline constexpr Intersection Intersects(const Vector<T, 3>& point) const
    {
        const T d = Distance(point);
        if(d < T(0))
            return Intersection::Back;
        else if(d > T(0))
            return Intersection::Front;
        else
            return Intersection::Intersects;
    }
    inline constexpr Vector<T, 3> IntersectionPoint(const Vector<T, 3>& start, const Vector<T, 3>& end, T& t) const
    {
        const Vector<T, 3> diff = end - start;
        t = (-distance - dot(start, normal)) / (dot(diff, normal));
        return start + diff * t;
    }
    inline constexpr Intersection Intersects(const Plane<T>& plane)
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr T Distance(const Vector<T, 3>& point) const
    {
        return dot(normal, point) + distance;
    }
    inline constexpr Plane<T> norm() const
    {
        const T mag = normal.mag();
        return {(mag == T(0) || mag == T(1)) ? *this : Plane<T>{normal / mag, distance / mag}};
    }
    inline friend constexpr Plane<T> operator*=(Plane<T>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        lhs = lhs * rhs;
        return lhs;
    }
    inline friend constexpr Plane<T> operator*(const Plane<T>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        const Vector<T, 4> p = rhs * vec4{lhs.normal * lhs.distance, T(1)};
        const Vector<T, 4> n = rhs.inverse().transpose() * vec4{lhs.normal, T(0)};
        return Plane<T>{n.xyz, dot(Vector<T, 3>{p.xyz}, Vector<T, 3>{n.xyz})};
    }
};

template <typename T>
inline constexpr Vector<T, 3> plane_intersection_point(const Plane<T>& p0, const Plane<T>& p1, const Plane<T>& p2)
{
    //TODO
    return Vector<T, 3>::zero();
}

template <typename T>
struct Frustum
{
    Plane<T> far, near, top, bottom, right, left;
    Matrix<T, 4, 4> m_fMatrix = Matrix<T, 4, 4>::identity();
    inline constexpr Frustum() = default;
    inline constexpr Frustum& operator=(const Frustum& frustum) = default;
    inline constexpr Frustum(const Frustum& frustum) = default;
    inline constexpr Frustum(Frustum&& frustum) = default;
    inline constexpr void Set(const Matrix<T, 4, 4>& lhs)
    {
        left = Plane<T>{lhs.row(3) + lhs.row(0)}.norm();
        right = Plane<T>{lhs.row(3) - lhs.row(0)}.norm();
        bottom = Plane<T>{lhs.row(3) + lhs.row(1)}.norm();
        top = Plane<T>{lhs.row(3) - lhs.row(1)}.norm();
        near = Plane<T>{lhs.row(3) + lhs.row(2)}.norm();
        far = Plane<T>{lhs.row(3) - lhs.row(2)}.norm();
        m_fMatrix = lhs;
    }
    inline constexpr bool Overlaps(const BoundingBox<T, 3>& box)
    {
        //TODO
        return false;
    }
    inline constexpr bool Overlaps(const BoundingSphere<T, 3>& sphere)
    {
        return far.Intersects(sphere) != Intersection::Back &&
        near.Intersects(sphere) != Intersection::Back &&
        top.Intersects(sphere) != Intersection::Back &&
        bottom.Intersects(sphere) != Intersection::Back &&
        left.Intersects(sphere) != Intersection::Back &&
        right.Intersects(sphere) != Intersection::Back;
    }
    inline constexpr Intersection Intersects(const Plane<T>& plane)
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr bool Overlaps(const Vector<T, 3>& point)
    {
        if(near.Distance(point) <= T(0))
            return false;
        if(far.Distance(point) <= T(0))
            return false;
        if(left.Distance(point) <= T(0))
            return false;
        if(right.Distance(point) <= T(0))
            return false;
        if(top.Distance(point) <= T(0))
            return false;
        if(bottom.Distance(point) <= T(0))
            return false;
        return true;
    }
    inline constexpr const std::array<Vector<T, 3>, 8> GetCorners() const
    {
        return
        {
            plane_intersection_point(far, right, top),
            plane_intersection_point(far, right, bottom),
            plane_intersection_point(far, left, bottom),
            plane_intersection_point(far, left, top),
            plane_intersection_point(near, left, top),
            plane_intersection_point(near, left, bottom),
            plane_intersection_point(near, right, bottom),
            plane_intersection_point(near, right, top)
        };
    }
};

template <typename T> 
struct Transform
{
    Matrix<T, 3, 3> transform;
    Matrix<T, 3, 3> inverted;
    bool invertMatrix;
    inline constexpr Transform& operator=(const Transform& lhs) = default;
    inline constexpr Transform(const Transform& lhs) = default;
    inline constexpr Transform(Transform&& lhs) = default;
    inline constexpr Transform()
    {
        Reset();
    }
    inline constexpr void Rotate(const T& ang)
    {
        transform *= rotation_mat_2d<T>(ang);
        invertMatrix = true;
    }
    inline constexpr void Scale(const T& w, const T& h)
    {
        Scale({w, h});
    }
    inline constexpr void Scale(const Vector<T, 2>& scale)
    {
        transform *= scale_mat_2d<T>(scale);
        invertMatrix = true;
    }
    inline constexpr void Translate(const T& x, const T& y)
    {
        Translate({x, y});
    }
    inline constexpr void Translate(const Vector<T, 2>& offset)
    {
        transform *= translation_mat_2d<T>(offset);
        invertMatrix = true;
    }
    inline constexpr Vector<T, 2> Forward(const Vector<T, 2>& p) const
    {
        return Forward(p.x, p.y);
    }
    inline constexpr Vector<T, 2> Forward(const T& x, const T& y) const
    {
        const Vector<T, 3> vec = transform * Vector<T, 3>{x, y, T(1)};
        return vec.xy / (vec.z == T(0) ? T(1) : vec.z);
    }
    inline constexpr Vector<T, 2> Backward(const Vector<T, 2>& p) const
    {
        return Backward(p.x, p.y);
    }
    inline constexpr Vector<T, 2> Backward(const T& x, const T& y) const
    {
        const Vector<T, 3> vec = inverted * Vector<T, 3>{x, y, T(1)};
        return vec.xy / (vec.z == T(0) ? T(1) : vec.z);
    }
    inline constexpr void Reset()
    {
        transform = Matrix<T, 3, 3>::identity();
        inverted = Matrix<T, 3, 3>::identity();
        invertMatrix = false;
    }
    inline constexpr void Invert()
    {
        if(invertMatrix)
        {
            inverted = transform.inverse();
            invertMatrix = false;
        }
    }
    ~Transform() {}
};

template <typename T> 
struct Transform3D
{
    Vector<T, 3> position;
    Quaternion<T> rotation;
    Vector<T, 3> scale;
    inline constexpr Transform3D& operator=(const Transform3D& lhs) = default;
    inline constexpr Transform3D(const Transform3D& lhs) = default;
    inline constexpr Transform3D(Transform3D&& lhs) = default;
    inline constexpr Transform3D() : scale(T(1)), position(T(0)), rotation({T(1), T(0)}) {}
    inline constexpr Transform3D(const Vector<T, 3>& position, const Quaternion<T>& rotation, const Vector<T, 3>& scale)
    : position(position), rotation(rotation), scale(scale) {}
    inline constexpr Matrix<T, 4, 4> GetModelMat() const
    {
        return translation_mat_3d<T>(position) * mat_from_quat<T>(rotation) * scale_mat_3d<T>(scale);
    }
    inline constexpr void Reset()
    {
        scale = Vector<T, 3>::one();
        position = Vector<T, 3>::zero();
        rotation = Quaternion<T>::identity();
    }
    ~Transform3D() {}
};

template <typename T>
inline constexpr Transform3D<T> transform_lerp(const Transform3D<T>& lhs, const Transform3D<T>& rhs, const double t)
{
    return Transform3D<T>
    {
        lerp(lhs.position, rhs.position, t),
        slerp(lhs.rotation, rhs.rotation, t),
        lerp(lhs.scale, rhs.scale, t)
    };
}

template <typename T>
inline constexpr BoundingBox<T, 3> box_from_transform(const Transform3D<T>& transform)
{
    return BoundingBox<T, 3>
    {
        transform.position,
        transform.scale,
        quat_to_euler(transform.rotation)    
    };
}

template <typename T>
inline constexpr BoundingSphere<T, 3> sphere_from_transform(const Transform3D<T>& transform)
{
    return BoundingSphere<T, 3>
    {
        transform.position,
        max(transform.scale)
    };
}

template <typename T>
inline constexpr Transform3D<T> transform_from_box(const BoundingBox<T, 3>& box)
{
    return Transform3D<T>
    {
        box.pos,
        quat_from_euler(box.rotation),
        box.size
    };
}

#endif