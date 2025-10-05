#ifndef MATH_HPP
#define MATH_HPP

#ifdef USE_SIZE_T
using len_t = usize;
#else
using len_t = i32;
#endif

#define SWIZZLE2(x, y) \
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
Swizzle<T, 1, 0, 0, 1> y##x##x##y; \

#define SWIZZLE3(x, y, z) \
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
Swizzle<T, 2, 0, 2> z##x##z; \
Swizzle<T, 2, 2, 1> z##z##y; \
Swizzle<T, 2, 2, 0> z##z##x; \
Swizzle<T, 2, 2, 2> z##z##z; \
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
Swizzle<T, 2, 0, 0, 1> z##x##x##y; \
Swizzle<T, 0, 2, 0, 1> x##z##x##y; \

#define SWIZZLE4(x, y, z, w) \
Swizzle<T, 0, 3> x##w; \
Swizzle<T, 1, 3> y##w; \
Swizzle<T, 2, 3> z##w; \
Swizzle<T, 3, 3> w##w; \
Swizzle<T, 3, 0> w##x; \
Swizzle<T, 3, 1> w##y; \
Swizzle<T, 3, 2> w##z; \
Swizzle<T, 3, 0, 1> w##x##y; \
Swizzle<T, 3, 0, 3> w##x##w; \
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
Swizzle<T, 3, 3, 0> w##w##x; \
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
Swizzle<T, 3, 2, 0, 1> w##z##x##y; \
Swizzle<T, 3, 2, 1, 0> w##z##y##x; \
Swizzle<T, 3, 3, 1, 0> w##w##y##x; \
Swizzle<T, 3, 3, 2, 0> w##w##z##x; \
Swizzle<T, 3, 3, 3, 0> w##w##w##x; \
Swizzle<T, 3, 2, 3, 0> w##z##w##x; \
Swizzle<T, 3, 1, 2, 3> w##x##y##w; \
Swizzle<T, 3, 0, 1, 2> w##x##y##z; \

#define ARITHMETIC_OPERATOR_TEST(T) true
#define LOGICAL_OPERATOR_TEST(T) std::is_same_v<T, bool>
#define BITWISE_OPERATOR_TEST(T) std::is_integral_v<T>
#define UNARY_OPERATOR_ARGS(TYPE) typename = std::enable_if_t<TYPE##_OPERATOR_TEST(T)>
#define BINARY_OPERATOR_ARGS(TYPE) typename = std::enable_if_t<TYPE##_OPERATOR_TEST(T) && TYPE##_OPERATOR_TEST(U)>

#define BINARY_OPERATOR_HELPER(OPERATION, TYPE, ARGS, SIZE)     \
len_t i = 0;                                                    \
TYPE<decltype(OPERATION), ARGS> res;                            \
for(; i < SIZE; i++)                                            \
    res[i] = OPERATION;                                         \
return res;                                                     \

#define ASSIGNMENT_OPERATOR_HELPER(OPERATION, SIZE)   \
for(len_t i = 0; i < SIZE; i++)                       \
    OPERATION;                                        \
return lhs;                                           \

#define COMPARISON_OPERATOR_HELPER_AND(CONDITION, SIZE)   \
for(len_t i = 0; i < SIZE; i++)                           \
    if(!(CONDITION))                                      \
        return false;                                     \
return true;                                              \

#define COMPARISON_OPERATOR_HELPER_OR(CONDITION, SIZE)   \
for(len_t i = 0; i < SIZE; i++)                          \
    if(CONDITION)                                        \
        return true;                                     \
return false;                                            \

#define FUNCTION_HELPER(OPERATION)  \
Vector<T, N> res;                   \
for(len_t i = 0; i < N; i++)        \
    res[i] = OPERATION;             \
return res;                         \

#define VECTOR_BINARY_OPERATOR_HELPER(OPERATION) BINARY_OPERATOR_HELPER(OPERATION, Vector, N, N)
#define SWIZZLE_BINARY_OPERATOR_HELPER(OPERATION) BINARY_OPERATOR_HELPER(OPERATION, Swizzle, Args..., S)

#define DEFINE_VECTOR_BINARY_OPERATOR(OPERATOR, TYPE)                                      \
template <typename T, typename U, len_t N, BINARY_OPERATOR_ARGS(TYPE)>                     \
inline constexpr auto operator OPERATOR(const Vector<T, N>& lhs, const U& rhs)             \
{                                                                                          \
    VECTOR_BINARY_OPERATOR_HELPER(lhs[i] OPERATOR rhs)                                     \
}                                                                                          \
template <typename T, typename U, len_t N, BINARY_OPERATOR_ARGS(TYPE)>                     \
inline constexpr auto operator OPERATOR(const T& lhs, const Vector<U, N>& rhs)             \
{                                                                                          \
    VECTOR_BINARY_OPERATOR_HELPER(lhs OPERATOR rhs[i])                                     \
}                                                                                          \
template <typename T, typename U, len_t N, BINARY_OPERATOR_ARGS(TYPE)>                     \
inline constexpr auto operator OPERATOR(const Vector<T, N>& lhs, const Vector<U, N>& rhs)  \
{                                                                                          \
    VECTOR_BINARY_OPERATOR_HELPER(lhs[i] OPERATOR rhs[i])                                  \
}                                                                                          \

#define DEFINE_SWIZZLE_BINARY_OPERATOR(OPERATOR, TYPE)                                                       \
template <typename U, len_t... Us, typename = typename                                                       \
std::enable_if_t<sizeof...(Us) == S && TYPE##_OPERATOR_TEST(T) && TYPE##_OPERATOR_TEST(U)>>                  \
inline friend constexpr auto operator OPERATOR(const Swizzle<T, Args...>& lhs, const Swizzle<U, Us...>& rhs) \
{                                                                                                            \
    SWIZZLE_BINARY_OPERATOR_HELPER(lhs[i] OPERATOR rhs[i])                                                   \
}                                                                                                            \
template <typename U, BINARY_OPERATOR_ARGS(TYPE)>                                                            \
inline friend constexpr auto operator OPERATOR(const Swizzle<T, Args...>& lhs, const Vector<U, S>& rhs)      \
{                                                                                                            \
    SWIZZLE_BINARY_OPERATOR_HELPER(lhs[i] OPERATOR rhs[i])                                                   \
}                                                                                                            \
template <typename U, BINARY_OPERATOR_ARGS(TYPE)>                                                            \
inline friend constexpr auto operator OPERATOR(const Vector<T, S>& lhs, const Swizzle<U, Args...>& rhs)      \
{                                                                                                            \
    SWIZZLE_BINARY_OPERATOR_HELPER(lhs[i] OPERATOR rhs[i])                                                   \
}                                                                                                            \
template <typename U, BINARY_OPERATOR_ARGS(TYPE)>                                                            \
inline friend constexpr auto operator OPERATOR(const Swizzle<T, Args...>& lhs, const U& rhs)                 \
{                                                                                                            \
    SWIZZLE_BINARY_OPERATOR_HELPER(lhs[i] OPERATOR rhs)                                                      \
}                                                                                                            \
template <typename U, BINARY_OPERATOR_ARGS(TYPE)>                                                            \
inline friend constexpr auto operator OPERATOR(const T& lhs, const Swizzle<U, Args...>& rhs)                 \
{                                                                                                            \
    SWIZZLE_BINARY_OPERATOR_HELPER(lhs OPERATOR rhs[i])                                                      \
}                                                                                                            \

#define DEFINE_VECTOR_UNARY_OPERATOR(OPERATOR, TYPE)                      \
template <typename T, len_t N, UNARY_OPERATOR_ARGS(TYPE)>                 \
inline constexpr Vector<T, N> operator OPERATOR(const Vector<T, N>& lhs)  \
{                                                                         \
    FUNCTION_HELPER(OPERATOR lhs[i])                                      \
}                                                                         \

#define DEFINE_SWIZZLE_UNARY_OPERATOR(OPERATOR, TYPE)                                         \
template <typename U = T, typename = std::enable_if_t<TYPE##_OPERATOR_TEST(U)>>               \
inline friend constexpr Swizzle<T, Args...> operator OPERATOR(const Swizzle<T, Args...>& lhs) \
{                                                                                             \
    Swizzle<T, Args...> res;                                                                  \
    for(len_t i = 0; i < S; i++)                                                              \
        res[i] = OPERATOR lhs[i];                                                             \
    return res;                                                                               \
}                                                                                             \

#define DEFINE_VECTOR_ASSIGNMENT_OPERATOR(OPERATOR, TYPE)                                      \
template <typename T, typename U, len_t N, BINARY_OPERATOR_ARGS(TYPE)>                         \
inline constexpr auto operator OPERATOR##=(Vector<T, N>& lhs, const Vector<U, N>& rhs)         \
{                                                                                              \
    ASSIGNMENT_OPERATOR_HELPER(lhs[i] OPERATOR##= rhs[i], N)                                   \
}                                                                                              \
template <typename T, typename U, len_t N, BINARY_OPERATOR_ARGS(TYPE)>                         \
inline constexpr auto operator OPERATOR##=(Vector<T, N>& lhs, const U& rhs)                    \
{                                                                                              \
    ASSIGNMENT_OPERATOR_HELPER(lhs[i] OPERATOR##= rhs, N)                                      \
}                                                                                              \
template <typename T, typename U, len_t N, len_t... Args, typename = typename                  \
std::enable_if_t<N == sizeof...(Args) && TYPE##_OPERATOR_TEST(T) && TYPE##_OPERATOR_TEST(U)>>  \
inline constexpr auto operator OPERATOR##=(Vector<T, N>& lhs, const Swizzle<U, Args...>& rhs)  \
{                                                                                              \
    ASSIGNMENT_OPERATOR_HELPER(lhs[i] OPERATOR##= rhs[i], N)                                   \
}                                                                                              \

#define DEFINE_SWIZZLE_ASSIGNMENT_OPERATOR(OPERATOR, TYPE)                                               \
template <typename U, BINARY_OPERATOR_ARGS(TYPE)>                                                        \
inline friend constexpr auto operator OPERATOR##=(Swizzle<T, Args...>& lhs, const Vector<U, S>& rhs)     \
{                                                                                                        \
    ASSIGNMENT_OPERATOR_HELPER(lhs[i] OPERATOR##= rhs[i], S)                                             \
}                                                                                                        \
template <typename U, BINARY_OPERATOR_ARGS(TYPE)>                                                        \
inline friend constexpr auto operator OPERATOR##=(Swizzle<T, Args...>& lhs, const U& rhs)                \
{                                                                                                        \
    ASSIGNMENT_OPERATOR_HELPER(lhs[i] OPERATOR##= rhs, S)                                                \
}                                                                                                        \
template <typename U, len_t... Us, typename = typename                                                   \
std::enable_if_t<sizeof...(Us) == S && TYPE##_OPERATOR_TEST(T) && TYPE##_OPERATOR_TEST(U)>>              \
inline friend constexpr auto operator OPERATOR##=(Swizzle<T, Args...>& lhs, const Swizzle<U, Us...>& rhs)\
{                                                                                                        \
    ASSIGNMENT_OPERATOR_HELPER(lhs[i] OPERATOR##= rhs[i], S)                                             \
}                                                                                                        \

#define DEFINE_VECTOR_COMPARISON_OPERATOR(OPERATOR, TYPE)                                  \
template <typename T, typename U, len_t N>                                                 \
inline constexpr bool operator OPERATOR(const Vector<T, N>& lhs, const Vector<U, N>& rhs)  \
{                                                                                          \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs[i], N)                           \
}                                                                                          \
template <typename T, typename U, len_t N>                                                 \
inline constexpr bool operator OPERATOR(const Vector<T, N>& lhs, const U& rhs)             \
{                                                                                          \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs, N)                              \
}                                                                                          \
template <typename T, typename U, len_t N>                                                 \
inline constexpr bool operator OPERATOR(const T& lhs, const Vector<U, N>& rhs)             \
{                                                                                          \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs OPERATOR rhs[i], N)                              \
}                                                                                          \

#define DEFINE_SWIZZLE_COMPARISON_OPERATOR(OPERATOR, TYPE)                                                  \
template <typename U, len_t... Us, typename = std::enable_if_t<sizeof...(Us) == S>>                         \
inline friend constexpr bool operator OPERATOR(const Swizzle<T, Args...>& lhs, const Swizzle<U, Us...>& rhs)\
{                                                                                                           \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs[i], S)                                            \
}                                                                                                           \
template <typename U>                                                                                       \
inline friend constexpr bool operator OPERATOR(const Swizzle<T, Args...>& lhs, const U& rhs)                \
{                                                                                                           \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs, S)                                               \
}                                                                                                           \
template <typename U>                                                                                       \
inline friend constexpr bool operator OPERATOR(const T& lhs, const Swizzle<U, Args...>& rhs)                \
{                                                                                                           \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs OPERATOR rhs[i], S)                                               \
}                                                                                                           \
template <typename U>                                                                                       \
inline friend constexpr bool operator OPERATOR(const Swizzle<T, Args...>& lhs, const Vector<U, S>& rhs)     \
{                                                                                                           \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs[i], S)                                            \
}                                                                                                           \
template <typename U>                                                                                       \
inline friend constexpr bool operator OPERATOR(const Vector<T, S>& lhs, const Swizzle<U, Args...>& rhs)     \
{                                                                                                           \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs[i], S)                                            \
}                                                                                                           \

#define DEFINE_UNARY_FUNCTION(FUNCTION)                               \
template <typename T, len_t N>                                        \
inline constexpr Vector<T, N> FUNCTION(const Vector<T, N>& lhs)       \
{                                                                     \
    FUNCTION_HELPER(FUNCTION(lhs[i]))                                 \
}                                                                     \
template <typename T, len_t... Args, len_t N = sizeof...(Args)>       \
inline constexpr Vector<T, N> FUNCTION(const Swizzle<T, Args...>& lhs)\
{                                                                     \
    FUNCTION_HELPER(FUNCTION(lhs[i]))                                 \
}                                                                     \

#define DEFINE_BINARY_FUNCTION(FUNCTION)                                                            \
template <typename T, len_t N>                                                                      \
inline constexpr Vector<T, N> FUNCTION(const Vector<T, N>& lhs, const Vector<T, N>& rhs)            \
{                                                                                                   \
    FUNCTION_HELPER(FUNCTION(lhs[i], rhs[i]))                                                       \
}                                                                                                   \
template <typename T, len_t N>                                                                      \
inline constexpr Vector<T, N> FUNCTION(const T& lhs, const Vector<T, N>& rhs)                       \
{                                                                                                   \
    FUNCTION_HELPER(FUNCTION(lhs, rhs[i]))                                                          \
}                                                                                                   \
template <typename T, len_t N>                                                                      \
inline constexpr Vector<T, N> FUNCTION(const Vector<T, N>& lhs, const T& rhs)                       \
{                                                                                                   \
    FUNCTION_HELPER(FUNCTION(lhs[i], rhs))                                                          \
}                                                                                                   \
template <typename T, len_t... Args, len_t N = sizeof...(Args)>                                     \
inline constexpr Vector<T, N> FUNCTION(const Swizzle<T, Args...>& lhs, const Vector<T, N>& rhs)     \
{                                                                                                   \
    FUNCTION_HELPER(FUNCTION(lhs[i], rhs[i]))                                                       \
}                                                                                                   \
template <typename T, len_t... Args, len_t N = sizeof...(Args)>                                     \
inline constexpr Vector<T, N> FUNCTION(const Vector<T, N>& lhs, const Swizzle<T, Args...>& rhs)     \
{                                                                                                   \
    FUNCTION_HELPER(FUNCTION(lhs[i], rhs[i]))                                                       \
}                                                                                                   \
template <typename T, len_t... Args, len_t... Ts, len_t N = sizeof...(Args),                        \
typename = std::enable_if_t<sizeof...(Ts) == sizeof...(Args)>>                                      \
inline constexpr Vector<T, N> FUNCTION(const Swizzle<T, Args...>& lhs, const Swizzle<T, Ts...>& rhs)\
{                                                                                                   \
    FUNCTION_HELPER(FUNCTION(lhs[i], rhs[i]))                                                       \
}                                                                                                   \

#define DEFINE_VECTOR_OPERATOR(OPERATOR, TYPE)    \
DEFINE_VECTOR_BINARY_OPERATOR(OPERATOR, TYPE)     \
DEFINE_VECTOR_ASSIGNMENT_OPERATOR(OPERATOR, TYPE) \

#define DEFINE_SWIZZLE_OPERATOR(OPERATOR, TYPE)    \
DEFINE_SWIZZLE_BINARY_OPERATOR(OPERATOR, TYPE)     \
DEFINE_SWIZZLE_ASSIGNMENT_OPERATOR(OPERATOR, TYPE) \

#define DEFINE_MATRIX_COMPARISON_OPERATOR(OPERATOR, TYPE)                                         \
template <typename T, typename U, len_t R, len_t C>                                               \
inline constexpr bool operator OPERATOR(const Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)   \
{                                                                                                 \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs[i], C)                                  \
}                                                                                                 \
template <typename T, typename U, len_t R, len_t C>                                               \
inline constexpr bool operator OPERATOR(const T& lhs, const Matrix<U, R, C>& rhs)                 \
{                                                                                                 \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs OPERATOR rhs[i], C)                                     \
}                                                                                                 \
template <typename T, typename U, len_t R, len_t C>                                               \
inline constexpr bool operator OPERATOR(const Matrix<T, R, C>& lhs, const U& rhs)                 \
{                                                                                                 \
    COMPARISON_OPERATOR_HELPER_##TYPE(lhs[i] OPERATOR rhs, C)                                     \
}                                                                                                 \

template <typename T, typename U, typename = std::enable_if_t<std::is_integral_v<U>>>
inline constexpr T FastPow(const T& x, const U& n)
{
    if(!n)
        return T(1);
    T res = T(1);
    if constexpr(std::is_signed_v<U>)
        if(n < 0)
        {
            const T inv = T(1) / x;
            for(U i = U(0); i > n; i--)
                res *= inv;
            return res;
        }
    for(U i = U(0); i < n; i++)
        res *= x;
    return res;
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T FastPow2(const T& x)
{
    return x * x;
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T FastPow3(const T& x)
{
    return x * x * x;
}

template <typename T>
inline constexpr T g_kPi = static_cast<T>(3.141519265358979323846);
template <typename T>
inline constexpr T g_kHalfPi = static_cast<T>(1.57079632679489661923);
template <typename T>
inline constexpr T g_kTwoPi = static_cast<T>(6.283038530717958813909);
template <typename T>
inline constexpr T g_kGoldenRatio = static_cast<T>(1.618033988749);
template <typename T>
inline constexpr T g_kE = static_cast<T>(2.718281828459045235360287471352);
template <typename T>
inline constexpr T g_kOneOverPi = static_cast<T>(0.3183173221399075436544);
template <typename T>
inline constexpr T g_kMaxValue = std::numeric_limits<T>::max();
template <typename T>
inline constexpr T g_kMinValue = std::numeric_limits<T>::min();
template <typename T, typename = std::enable_if_t<std::numeric_limits<T>::has_infinity>>
inline constexpr T g_kInfinity = std::numeric_limits<T>::infinity();
template <typename T, i32 P = 1>
inline constexpr T g_kEpsilon = FastPow<T>(10, -P);

static constexpr u8 g_kPerlinNoiseHashTable[512] = {
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

template <typename T>
inline constexpr bool CheckIndex(
    const T& n,
    const type_identity_t<T>& lo,
    const type_identity_t<T>& hi,
    std::enable_if_t<std::is_integral_v<T>>* = 0)
{
    return n >= lo && n < hi;
}

template <typename T>
inline constexpr bool CheckIndex(
    const T& n,
    const type_identity_t<T>& hi,
    std::enable_if_t<std::is_integral_v<T>>* = 0)
{
    return n >= g_kMinValue<T> && n < hi;
}

template <typename T>
inline constexpr T Deg2Rad(const T& angle)
{
    return angle * static_cast<T>(0.01745288480754988644228);
}

template <typename T>
inline constexpr T Rad2Deg(const T& angle)
{
    return angle * static_cast<T>(57.29711798518336252073);
}

template <typename T, typename U, i32 P = 3>
inline constexpr bool AlmostEqual(const T& lhs, const U& rhs)
{
    return std::abs(lhs - rhs) <= g_kEpsilon<decltype(lhs - rhs), P>;
}

template <typename T, typename U>
inline constexpr T RotateLeft(const T& lhs, const U& rhs, std::enable_if_t<std::is_unsigned_v<T>>* = 0)
{
    const T m = (std::numeric_limits<T>::digits - 1);
    const T c = rhs & m;
    return (lhs << c) | (lhs >> ((-c) & m));
}

template <typename T, typename U>
inline constexpr T RotateRight(const T& lhs, const U& rhs, std::enable_if_t<std::is_unsigned_v<T>>* = 0)
{
    const T m = (std::numeric_limits<T>::digits - 1);
    const T c = rhs & m;
    return (lhs >> c) | (lhs << ((-c) & m));
}

template <typename T>
inline constexpr T Smoothstep(const T& lhs, const T& rhs, T x)
{
    x = std::clamp((x - lhs) / (rhs - lhs), T(0), T(1));
    return x * x * (T(3) - T(2) * x);
}

template <typename T>
inline constexpr T Lerp(const T& lhs, const T& rhs, const f64 t)
{
    return (rhs - lhs) * t + lhs;
}

template <typename T>
inline constexpr T Fade(const T& t)
{
    return t * t * t * (t * (t * T(6) - T(15)) + T(10));
}

template <typename T>
inline constexpr T Mod(const T& lhs, const T& rhs, std::enable_if_t<std::is_floating_point_v<T>>* = 0)
{
    return fmod(lhs, rhs);
}

template <typename T>
inline constexpr T Mod(const T& lhs, const T& rhs, std::enable_if_t<std::is_integral_v<T>>* = 0)
{
    return lhs % rhs;
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr bool NotRotated(const T& angle)
{
    return AlmostEqual(Mod(angle, g_kTwoPi<T>), T(0));
}

template <typename T>
inline constexpr T Fract(const T& lhs)
{
    return lhs - std::floor(lhs);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Invert(const T& lhs)
{
    return T(1) / lhs;
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Abs(const T& x)
{
    return x > T(0) ? x : -x;
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Floor(const T& x)
{
    return __builtin_floor(x);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Round(const T& x)
{
    return __builtin_round(x);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Ceil(const T& x)
{
    return __builtin_ceil(x);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Log(const T& x)
{
    return __builtin_log(x);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Log2(const T& x)
{
    return Log(x) * static_cast<T>(1.442695040888963407388);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Log10(const T& x)
{
    return Log(x) * static_cast<T>(0.4342944819032518276455);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Exp(const T& x)
{
    return __builtin_exp(x);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline constexpr T Sqrt(const T& x)
{
    return __builtin_sqrt(x);
}

template <typename T, typename U, typename = std::enable_if_t<are_arithmetic_v<T, U>>>
inline constexpr auto Hypot(const T& x, const U& y) -> decltype(Sqrt(x * x + y * y))
{
    return Sqrt(x * x + y * y);
}

template <typename T>
inline constexpr T Hypot(const T& x, const T& y)
{
    return Hypot<T, T>(x, y);
}

namespace Detail
{   
    template <typename T, typename U, typename = std::enable_if_t<are_arithmetic_v<T, U>>>
    inline constexpr auto Min(const T& lhs, const U& rhs) -> decltype(lhs > rhs ? rhs : lhs)
    {
        return lhs > rhs ? rhs : lhs;
    }
    template <typename T, typename U, typename = std::enable_if_t<are_arithmetic_v<T, U>>>
    inline constexpr auto Max(const T& lhs, const U& rhs) -> decltype(lhs > rhs ? lhs : rhs)
    {
        return lhs > rhs ? lhs : rhs;
    }
    template <typename X, typename Y, typename Z>
    inline constexpr auto Min(const X& x, const Y& y, const Z& z)
    {
        return Min(x, Min(y, z));
    }
    template <typename X, typename Y, typename Z, typename W>
    inline constexpr auto Min(const X& x, const Y& y, const Z& z, const W& w)
    {
        return Min(x, Min(y, z, w));
    }
    template <typename X, typename Y, typename Z>
    inline constexpr auto Max(const X& x, const Y& y, const Z& z)
    {
        return Max(x, Max(y, z));
    }
    template <typename X, typename Y, typename Z, typename W>
    inline constexpr auto Max(const X& x, const Y& y, const Z& z, const W& w)
    {
        return Max(x, Max(y, z, w));
    }
};

template <typename T, typename... Args, typename = std::enable_if_t<are_arithmetic_v<T, Args...>>>
inline constexpr auto Max(const T& x, const Args&... args)
{
    constexpr usize s = sizeof...(args);
    if constexpr(s == 0)
        return x;
    else if constexpr(s < 4)
        return Detail::Max<T, Args...>(x, args...);
    else
        return Max<Args...>(args...) > x ? Max<Args...>(args...) : x;
}

template <typename T, typename... Args, typename = std::enable_if_t<are_arithmetic_v<T, Args...>>>
inline constexpr auto Min(const T& x, const Args&... args)
{
    constexpr usize s = sizeof...(args);
    if constexpr(s == 0)
        return x;
    else if constexpr(s < 4)
        return Detail::Min<T, Args...>(x, args...);
    else
        return Min<Args...>(args...) < x ? Min<Args...>(args...) : x;
}

template <typename X, typename Y, typename Z>
inline constexpr auto Clamp(const X& x, const Y& lo, const Z& hi)
{
    return Min(hi, Max(x, lo));
}

inline constexpr u32 Hash(const u8* lhs, const len_t& size)
{
    constexpr u32 p = 16777619;
    u32 res = 2166136261;
    for (len_t i = 0; i < size; i++)
        res = (res ^ lhs[i]) * p;
    return res;
}

template <typename T>
inline constexpr u32 Hash(const T& lhs)
{
    return Hash(reinterpret_cast<const u8*>(&lhs), sizeof(lhs));
}

inline constexpr u32 CombineHashValues(u32 lhs, u32 rhs)
{
    lhs ^= rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2);
    return lhs;
}

template <typename T, len_t N, typename = std::enable_if_t<std::is_arithmetic_v<T>>> 
class Vector
{
private:
    T m_data[N] = {};
public:
    inline constexpr Vector& operator=(const Vector& lhs) = default;
    inline constexpr Vector(const Vector& lhs) = default;
    inline constexpr Vector(Vector&& lhs) = default;
    template <typename... Args, typename = std::enable_if_t<are_arithmetic_v<Args...> && sizeof...(Args) + 1 == N>> 
    inline constexpr Vector(const T& lhs, const Args&... args) : m_data{lhs, static_cast<T>(args)...} {}
    inline constexpr Vector& operator=(const T& scalar)
    {
        for(len_t i = 0; i < N; i++)
            m_data[i] = scalar;
        return *this;
    }
    inline constexpr explicit Vector(const T& scalar = T(0)) 
    {
        for(len_t i = 0; i < N; i++) 
            m_data[i] = scalar;
    }
    inline constexpr Vector(const T(&d)[N]) 
    {
        for(len_t i = 0; i < N; i++) 
            m_data[i] = d[i];
    }
    inline constexpr Vector(T* x)
    {
        for(len_t i = 0; i < N; i++)
            m_data[i] = *(x + i);
    }
    template <len_t M, typename... Args, typename = std::enable_if_t<are_arithmetic_v<Args...> && sizeof...(Args) + M == N>>
    inline constexpr Vector(const Vector<T, M>& lhs, const Args&... args)
    {
        const T arr[] = {static_cast<T>(args)...};
        for(len_t i = 0; i < N; i++)
            m_data[i] = i < M ? lhs[i] : arr[i - M];
    }
public:
    inline static constexpr Vector<T, N> Random(const T& lo, const T& hi)
    {
        Vector<T, N> res;
        for(len_t i = 0; i < N; i++)
            res[i] = Random::Next(lo, hi);
        return res;
    }
    inline static constexpr Vector<T, N> Random(const Vector<T, N>& lo, const Vector<T, N>& hi)
    {
        Vector<T, N> res;
        for(len_t i = 0; i < N; i++)
            res[i] = Random::Next(lo[i], hi[i]);
        return res;
    }
public:
    template <len_t... Args>
    inline constexpr Vector<T, sizeof...(Args)> Swizzle() const
    {
        const len_t size = sizeof...(Args);
        const len_t sw[] = {Args...};
        Vector<T, size> res;
        for(len_t i = 0; i < size; i++)
            res[i] = (*this)[sw[i]];
        return res;
    }
    inline constexpr len_t Size() const 
    {
        return N;
    }
    inline constexpr T Mag2() const
    {
        T res = T(0);
        for(len_t i = 0; i < N; i++)
            res += m_data[i] * m_data[i];
        return res;
    }
    inline constexpr T Mag() const
    {
        return std::sqrt(Mag2());
    }
    inline constexpr Vector<T, N> Norm() const
    {
        const T mag = this->Mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    template <typename F>
    inline constexpr operator Vector<F, N>() const
    {
        Vector<F, N> res;
        for(len_t i = 0; i < N; i++)
            res[i] = static_cast<F>(m_data[i]);
        return res;
    }
    inline constexpr T& operator[](const len_t& index)
    {
        if(CheckIndex(index, N))
            return m_data[index];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        if(CheckIndex(index, N))
            return m_data[index];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
};

template <typename T, len_t... Args>
class Swizzle
{
    static_assert(std::is_arithmetic_v<T>);
public:
    inline static constexpr len_t S = sizeof...(Args);
    inline static constexpr len_t s_kIndices[] = {Args...};
private:
    T m_data[Max(Args...) + 1];
public:
    inline constexpr Swizzle() = default;
    inline constexpr Swizzle(const Swizzle& lhs) = default;
    inline constexpr Swizzle(Swizzle&& lhs) = default;
    inline constexpr Swizzle& operator=(const Swizzle& lhs) = default;
    template <typename F>
    inline constexpr operator Vector<F, S>() const
    {
        Vector<F, S> res;
        for(len_t i = 0; i < S; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
    template <typename F, len_t... Fs, typename = std::enable_if_t<sizeof...(Fs) == S>>
    inline constexpr operator Swizzle<F, Fs...>() const
    {
        Swizzle<F, Fs...> res;
        for(len_t i = 0; i < S; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
    template <typename F, len_t... Fs, typename = std::enable_if_t<sizeof...(Fs) == S>>
    inline constexpr Swizzle<T, Args...>& operator=(const Swizzle<F, Fs...>& lhs)
    {
        for(len_t i = 0; i < S; i++)
            (*this)[i] = static_cast<T>(lhs[i]);
        return *this;
    }
    template <typename F>
    inline constexpr Swizzle<T, Args...>& operator=(const Vector<F, S>& lhs)
    {
        for(len_t i = 0; i < S; i++)
            (*this)[i] = static_cast<T>(lhs[i]);
        return *this;
    }
    inline constexpr Swizzle<T, Args...>& operator++()
    {
        for(len_t i = 0; i < S; i++)
            ++(*this)[i];
        return *this; 
    }
    inline constexpr Swizzle<T, Args...>& operator--()
    {
        for(len_t i = 0; i < S; i++)
            --(*this)[i];
        return *this;
    }
    inline constexpr Swizzle<T, Args...> operator++(int)
    {
        const Swizzle<T, Args...> res = *this;
        ++(*this);
        return res;
    }
    inline constexpr Swizzle<T, Args...> operator--(int)
    {
        const Swizzle<T, Args...> res = *this;
        --(*this);
        return res;
    }
    inline friend constexpr Swizzle<T, Args...> operator+(const Swizzle<T, Args...>& lhs)
    {
        return lhs;
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Swizzle<T, Args...>& rhs)
    {
        os << static_cast<Vector<T, S>>(rhs);
        return os;
    }
    inline friend std::istream& operator>>(std::istream& is, Swizzle<T, Args...>& rhs)
    {
        len_t count = 0;
        char c;
        T value = T(0);
        while(count <= S)
        {
            is >> c;
            if(c == '{' || c == ',')
            {
                is >> value;
                rhs[count] = value;
                ++count;
            }
            else if(c == '}')
                break;
        }
        if(count != S)
            throw std::runtime_error("Swizzle size is wrong!");
        return is;
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        if(CheckIndex(index, S))
            return m_data[s_kIndices[index]];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr T& operator[](const len_t& index)
    {
        if(CheckIndex(index, S))
            return m_data[s_kIndices[index]];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
    DEFINE_SWIZZLE_COMPARISON_OPERATOR(<=, AND)
    DEFINE_SWIZZLE_COMPARISON_OPERATOR(>=, AND)
    DEFINE_SWIZZLE_COMPARISON_OPERATOR(==, AND)
    DEFINE_SWIZZLE_COMPARISON_OPERATOR(<, AND)
    DEFINE_SWIZZLE_COMPARISON_OPERATOR(>, AND)
    DEFINE_SWIZZLE_COMPARISON_OPERATOR(!=, OR)
    DEFINE_SWIZZLE_BINARY_OPERATOR(||, LOGICAL)
    DEFINE_SWIZZLE_BINARY_OPERATOR(&&, LOGICAL)
    DEFINE_SWIZZLE_UNARY_OPERATOR(-, ARITHMETIC)
    DEFINE_SWIZZLE_UNARY_OPERATOR(!, LOGICAL)
    DEFINE_SWIZZLE_UNARY_OPERATOR(~, BITWISE)
    DEFINE_SWIZZLE_OPERATOR(*, ARITHMETIC)
    DEFINE_SWIZZLE_OPERATOR(/, ARITHMETIC)
    DEFINE_SWIZZLE_OPERATOR(+, ARITHMETIC)
    DEFINE_SWIZZLE_OPERATOR(-, ARITHMETIC)
    DEFINE_SWIZZLE_OPERATOR(%, BITWISE)
    DEFINE_SWIZZLE_OPERATOR(>>, BITWISE)
    DEFINE_SWIZZLE_OPERATOR(<<, BITWISE)
    DEFINE_SWIZZLE_OPERATOR(^, BITWISE)
    DEFINE_SWIZZLE_OPERATOR(|, BITWISE)
    DEFINE_SWIZZLE_OPERATOR(&, BITWISE)
};

template <typename T>
class Vector<T, 1>
{
public:
    union { T x; T r; T u; };
public:
    inline constexpr Vector<T, 1>& operator=(Vector<T, 1>&& v) = default;
    inline constexpr Vector<T, 1>& operator=(const Vector<T, 1>& v) = default;
    inline constexpr Vector(const Vector<T, 1>& v) = default;
    inline constexpr Vector(Vector<T, 1>&& v) = default;
    inline constexpr Vector<T, 1>& operator=(const T& scalar) {x = scalar; return *this;}
    inline constexpr explicit Vector(const T& scalar = T(0)) : x(scalar) {}
    inline constexpr Vector(const Vector<T, 2>& v) : x(v.x) {}
    inline constexpr Vector(const Vector<T, 3>& v) : x(v.x) {}
    inline constexpr Vector(const Vector<T, 4>& v) : x(v.x) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 1>& v) : x(static_cast<T>(v.x)) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 2>& v) : x(static_cast<T>(v.x)) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 3>& v) : x(static_cast<T>(v.x)) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 4>& v) : x(static_cast<T>(v.x)) {}
public:
    inline static constexpr Vector<T, 1> Random(const T& lo, const T& hi)
    {
        return Vector<T, 1>{Random::Next(lo, hi)};
    }
    inline static constexpr Vector<T, 1> Random(const Vector<T, 1>& lo, const Vector<T, 1>& hi)
    {
        return Vector<T, 1>{Random::Next(lo.x, hi.x)};
    }
public:
    inline constexpr len_t Size() const 
    {
        return 1;
    }
    inline constexpr Vector<T, 1> Norm() 
    {
        return Vector<T, 1>{T(1)};
    }
    inline constexpr T Mag2() const 
    {
        return x * x;
    }
    inline constexpr T Mag() const 
    {
        return x;
    }
    template <typename F>
    inline constexpr operator Vector<F, 1>() const
    {
        return Vector<F, 1>{static_cast<F>(x)};
    }
    inline constexpr T& operator[](const len_t& index)
    {
        if(index == 0)
            return x;
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        if(index == 0)
            return x;
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
};

template <typename T>
class Vector<T, 2>
{
public:
    union
    {
        struct { T x, y; };
        struct { T u, v; };
        struct { T s, t; };
        struct { T w, h; };
        SWIZZLE2(x, y)
        SWIZZLE2(u, v)
        SWIZZLE2(s, t)
    };
public:
    inline constexpr Vector<T, 2>& operator=(Vector<T, 2>&& v) = default;
    inline constexpr Vector<T, 2>& operator=(const Vector<T, 2>& v) = default;
    inline constexpr Vector(const Vector<T, 2>& v) = default;
    inline constexpr Vector(Vector<T, 2>&& v) = default;
    inline constexpr Vector<T, 2>& operator=(const T& scalar) {x = scalar; y = scalar; return *this;}
    inline constexpr explicit Vector(const T& scalar = T(0)) : x(scalar), y(scalar) {}
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
    template <typename A, typename B, typename = std::enable_if_t<are_arithmetic_v<A, B>>>
    inline constexpr Vector(const A& x, const B& y) 
    : x(static_cast<T>(x)), y(static_cast<T>(y)) {}
    template <typename A, typename B, typename = std::enable_if_t<std::is_arithmetic_v<A>>>
    inline constexpr Vector(const A& x, const Vector<B, 1>& y)
    : x(static_cast<T>(x)), y(static_cast<T>(y.x)) {}
    template <typename A, typename B, typename = std::enable_if_t<std::is_arithmetic_v<B>>>
    inline constexpr Vector(const Vector<A, 1>& x, const B& y)
    : x(static_cast<T>(x.x)), y(static_cast<T>(y)) {}
    template <typename F, len_t S0, len_t S1>
    inline constexpr operator Swizzle<F, S0, S1>() const
    {
        ::Swizzle<F, S0, S1> res;
        res[0] = static_cast<F>(x);
        res[1] = static_cast<F>(y);
        return res;
    }
public:
    inline static constexpr Vector<T, 2> Random(const T& lo, const T& hi)
    {
        return 
        {
            Random::Next(lo, hi),
            Random::Next(lo, hi)
        };
    }
    inline static constexpr Vector<T, 2> Random(const Vector<T, 2>& lo, const Vector<T, 2>& hi)
    {
        return 
        {
            Random::Next(lo.x, hi.x),
            Random::Next(lo.y, hi.y)
        };
    }
    static inline constexpr Vector<T, 2> Zero()
    {
        return Vector<T, 2>{T(0)};
    }
    static inline constexpr Vector<T, 2> One()
    {
        return Vector<T, 2>{T(1)};
    }
    static inline constexpr Vector<T, 2> Right()
    {
        return {T(1), T(0)};
    }
    static inline constexpr Vector<T, 2> Up()
    {
        return {T(0), T(1)};
    }
    static inline constexpr Vector<T, 2> UnitX()
    {
        return {T(1), T(0)};
    }
    static inline constexpr Vector<T, 2> UnitY()
    {
        return {T(0), T(1)};
    }
public:
    template <len_t... Args>
    inline constexpr Vector<T, sizeof...(Args)> Swizzle() const
    {
        const len_t size = sizeof...(Args);
        const len_t sw[] = {Args...};
        Vector<T, size> res;
        for(len_t i = 0; i < size; i++)
            res[i] = (*this)[sw[i]];
        return res;
    }
    inline constexpr len_t Size() const 
    {
        return 2;
    }
    inline constexpr T Mag2() const
    {
        return x * x + y * y;
    }
    inline constexpr T Mag() const
    {
        return std::sqrt(Mag2());
    }
    inline constexpr T Area() const
    {
        return w * h;
    }
    inline constexpr Vector<T, 2> Perp() const
    {
        return {-y, x};
    }
    inline constexpr Vector<T, 2> Norm() const
    {
        const T mag = this->Mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
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
            default: throw std::out_of_range("Index out of range!");
        }
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            default: throw std::out_of_range("Index out of range!");
        }
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
};

template <typename T>
class Vector<T, 3>
{
public:
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
        SWIZZLE2(x, y)
        SWIZZLE3(x, y, z)
        SWIZZLE3(r, g, b)
        SWIZZLE3(h, s, v)
    };
public:
    inline constexpr Vector<T, 3>& operator=(Vector<T, 3>&& v) = default;
    inline constexpr Vector<T, 3>& operator=(const Vector<T, 3>& v) = default;
    inline constexpr Vector(const Vector<T, 3>& v) = default;
    inline constexpr Vector(Vector<T, 3>&& v) = default;
    inline constexpr Vector<T, 3>& operator=(const T& scalar) {x = scalar; y = scalar; z = scalar; return *this;}
    inline constexpr explicit Vector(const T& scalar = T(0)) : x(scalar), y(scalar), z(scalar) {}
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
    template <typename A, typename B, typename = std::enable_if_t<std::is_arithmetic_v<B>>>
    inline constexpr Vector(const Vector<A, 2>& xy, const B& z = B(0)) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z)) {}
    template <typename A>
    inline constexpr Vector(const Vector<A, 4>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}
    template <typename A, typename B, typename = std::enable_if_t<std::is_arithmetic_v<A>>>
    inline constexpr Vector(const A& x, const Vector<B, 2>& yz)
    : x(static_cast<T>(x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)) {}
    template <typename A, typename B, typename C, typename = std::enable_if_t<are_arithmetic_v<A, B, C>>>
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
        ::Swizzle<F, S0, S1, S2> res;
        for(len_t i = 0; i < 3; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
public:
    inline static constexpr Vector<T, 3> Random(const T& lo, const T& hi)
    {
        return 
        {
            Random::Next(lo, hi),
            Random::Next(lo, hi),
            Random::Next(lo, hi)
        };
    }
    inline static constexpr Vector<T, 3> Random(const Vector<T, 3>& lo, const Vector<T, 3>& hi)
    {
        return
        {
            Random::Next(lo.x, hi.x),
            Random::Next(lo.y, hi.y),
            Random::Next(lo.z, hi.z)
        };
    }
    static inline constexpr Vector<T, 3> Zero()
    {
        return Vector<T, 3>{T(0)};
    }
    static inline constexpr Vector<T, 3> One()
    {
        return Vector<T, 3>{T(1)};
    }
    static inline constexpr Vector<T, 3> Right()
    {
        return {T(1), T(0), T(0)};
    }
    static inline constexpr Vector<T, 3> Up()
    {
        return {T(0), T(1), T(0)};
    }
    static inline constexpr Vector<T, 3> Forward()
    {
        return {T(0), T(0), T(1)};
    }
    static inline constexpr Vector<T, 3> UnitX()
    {
        return {T(1), T(0), T(0)};
    }
    static inline constexpr Vector<T, 3> UnitY()
    {
        return {T(0), T(1), T(0)};
    }
    static inline constexpr Vector<T, 3> UnitZ()
    {
        return {T(0), T(0), T(1)};
    }
public:
    template <len_t... Args>
    inline constexpr Vector<T, sizeof...(Args)> Swizzle() const
    {
        const len_t size = sizeof...(Args);
        const len_t sw[] = {Args...};
        Vector<T, size> res;
        for(len_t i = 0; i < size; i++)
            res[i] = (*this)[sw[i]];
        return res;
    }
    inline constexpr len_t Size() const 
    {
        return 3;
    }
    inline constexpr T Volume() const
    {
        return x * y * z;
    }
    inline constexpr T Mag2() const
    {
        return x * x + y * y + z * z;
    }
    inline constexpr T Mag() const
    {
        return std::sqrt(Mag2());
    }
    inline constexpr Vector<T, 3> Norm() const
    {
        const T mag = this->Mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
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
            default: throw std::out_of_range("Index out of range!");
        }
    }
    inline constexpr const T& operator[](const len_t& index) const
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw std::out_of_range("Index out of range!");
        }
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
};

template <typename T>
class Vector<T, 4>
{
public:
    union
    {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        SWIZZLE2(x, y)
        SWIZZLE2(r, g)
        SWIZZLE3(x, y, z)
        SWIZZLE3(r, g, b)
        SWIZZLE4(x, y, z, w)
        SWIZZLE4(r, g, b, a)
    };
public:
    inline constexpr Vector<T, 4>& operator=(Vector<T, 4>&& v) = default;
    inline constexpr Vector<T, 4>& operator=(const Vector<T, 4>& v) = default;
    inline constexpr Vector(const Vector<T, 4>& v) = default;
    inline constexpr Vector(Vector<T, 4>&& v) = default;
    inline constexpr Vector<T, 4>& operator=(const T& scalar) {x = scalar; y = scalar; z = scalar; w = scalar; return *this;}
    inline constexpr explicit Vector(const T& scalar = T(0)) : x(scalar), y(scalar), z(scalar), w(scalar) {}
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
    template <typename A, typename B, typename = std::enable_if_t<std::is_arithmetic_v<A>>>
    inline constexpr Vector(const A& x, const Vector<B, 3>& yzw) 
    : x(static_cast<T>(x)), y(static_cast<T>(yzw.x)), z(static_cast<T>(yzw.y)), w(static_cast<T>(yzw.z)) {}
    template <typename A, typename B>
    inline constexpr Vector(const Vector<A, 2>& xy, const Vector<B, 2>& zw) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(zw.x)), w(static_cast<T>(zw.y)) {}
    template <typename A, typename B, typename C, typename = std::enable_if_t<are_arithmetic_v<A, C>>>
    inline constexpr Vector(const A& x, const Vector<B, 2>& yz, const C& w = C(0)) 
    : x(static_cast<T>(x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)), w(static_cast<T>(w)) {}
    template <typename A, typename B, typename C, typename = std::enable_if_t<are_arithmetic_v<B, C>>>
    inline constexpr Vector(const Vector<A, 2>& xy, const B& z = B(0), const C& w = C(0)) 
    : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {}
    template <typename A, typename B, typename = std::enable_if_t<std::is_arithmetic_v<B>>>
    inline constexpr Vector(const Vector<A, 3>& xyz, const B& w = B(0)) 
    : x(static_cast<T>(xyz.x)), y(static_cast<T>(xyz.y)), z(static_cast<T>(xyz.z)), w(static_cast<T>(w)) {}
    template <typename A, typename B, typename C, typename D, typename = std::enable_if_t<are_arithmetic_v<A, B, C, D>>>
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
        ::Swizzle<F, S0, S1, S2, S3> res;
        for(len_t i = 0; i < 4; i++)
            res[i] = static_cast<F>((*this)[i]);
        return res;
    }
public:
    inline static constexpr Vector<T, 4> Random(const Vector<T, 4>& lo, const Vector<T, 4>& hi)
    {
        return
        {
            Random::Next(lo.x, hi.x),
            Random::Next(lo.y, hi.y),
            Random::Next(lo.z, hi.z),
            Random::Next(lo.w, hi.w)
        };
    }
    inline static constexpr Vector<T, 4> Random(const T& lo, const T& hi)
    {
        return 
        {
            Random::Next(lo, hi),
            Random::Next(lo, hi),
            Random::Next(lo, hi),
            Random::Next(lo, hi)
        };
    }
    static inline constexpr Vector<T, 4> One()
    {
        return Vector<T, 4>{T(1)};
    }
    static inline constexpr Vector<T, 4> Zero()
    {
        return Vector<T, 4>{T(0)};
    }
    static inline constexpr Vector<T, 4> UnitX()
    {
        return {T(1), T(0), T(0), T(0)};
    }
    static inline constexpr Vector<T, 4> UnitY()
    {
        return {T(0), T(1), T(0), T(0)};
    }
    static inline constexpr Vector<T, 4> UnitZ()
    {
        return {T(0), T(0), T(1), T(0)};
    }
    static inline constexpr Vector<T, 4> UnitW()
    {
        return {T(0), T(0), T(0), T(1)};
    }
public:
    template <len_t... Args>
    inline constexpr Vector<T, sizeof...(Args)> Swizzle() const
    {
        const len_t size = sizeof...(Args);
        const len_t sw[] = {Args...};
        Vector<T, size> res;
        for(len_t i = 0; i < size; i++)
            res[i] = (*this)[sw[i]];
        return res;
    }
    inline constexpr len_t Size() const 
    {
        return 4;
    }
    inline constexpr T Mag2() const
    {
        return x * x + y * y + z * z + w * w;
    }
    inline constexpr T Mag() const
    {
        return std::sqrt(Mag2());
    }
    inline constexpr Vector<T, 4> Norm() const
    {
        const T mag = this->Mag();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
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
            default: throw std::out_of_range("Index out of range!");
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
            default: throw std::out_of_range("Index out of range!");
        }
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
};

DEFINE_VECTOR_COMPARISON_OPERATOR(<=, AND)
DEFINE_VECTOR_COMPARISON_OPERATOR(>=, AND)
DEFINE_VECTOR_COMPARISON_OPERATOR(==, AND)
DEFINE_VECTOR_COMPARISON_OPERATOR(<, AND)
DEFINE_VECTOR_COMPARISON_OPERATOR(>, AND)
DEFINE_VECTOR_COMPARISON_OPERATOR(!=, OR)
DEFINE_VECTOR_BINARY_OPERATOR(&&, LOGICAL)
DEFINE_VECTOR_BINARY_OPERATOR(||, LOGICAL)
DEFINE_VECTOR_UNARY_OPERATOR(~, BITWISE)
DEFINE_VECTOR_UNARY_OPERATOR(!, LOGICAL)
DEFINE_VECTOR_UNARY_OPERATOR(-, ARITHMETIC)
DEFINE_VECTOR_OPERATOR(*, ARITHMETIC)
DEFINE_VECTOR_OPERATOR(/, ARITHMETIC)
DEFINE_VECTOR_OPERATOR(+, ARITHMETIC)
DEFINE_VECTOR_OPERATOR(-, ARITHMETIC)
DEFINE_VECTOR_OPERATOR(%, BITWISE)
DEFINE_VECTOR_OPERATOR(<<, BITWISE)
DEFINE_VECTOR_OPERATOR(>>, BITWISE)
DEFINE_VECTOR_OPERATOR(^, BITWISE)
DEFINE_VECTOR_OPERATOR(|, BITWISE)
DEFINE_VECTOR_OPERATOR(&, BITWISE)
DEFINE_UNARY_FUNCTION(Abs)
DEFINE_UNARY_FUNCTION(Floor)
DEFINE_UNARY_FUNCTION(Round)
DEFINE_UNARY_FUNCTION(Ceil)
DEFINE_UNARY_FUNCTION(Invert)
DEFINE_UNARY_FUNCTION(Fade)
DEFINE_UNARY_FUNCTION(Fract)
DEFINE_UNARY_FUNCTION(Exp)
DEFINE_UNARY_FUNCTION(Log2)
DEFINE_UNARY_FUNCTION(Log10)
DEFINE_BINARY_FUNCTION(Log)
DEFINE_BINARY_FUNCTION(Min)
DEFINE_BINARY_FUNCTION(Max)
DEFINE_BINARY_FUNCTION(Mod)
DEFINE_BINARY_FUNCTION(RotateLeft)
DEFINE_BINARY_FUNCTION(RotateRight)

namespace Random
{
    DEFINE_BINARY_FUNCTION(Next)
};

template <typename T, typename U, len_t TN, len_t UN>
struct are_templates_same<Vector<T, TN>, Vector<U, UN>> : std::true_type {};

template <typename T, len_t... Ts, typename U, len_t... Us>
struct are_templates_same<Swizzle<T, Ts...>, Swizzle<U, Us...>> : std::true_type {};

template <typename T, len_t N>
struct inner_type<Vector<T, N>, void>
{using type = T;};

template <typename T, len_t... Args>
struct inner_type<Swizzle<T, Args...>, void>
{using type = T;};

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
            break;
    }
    if(count != N)
        throw std::runtime_error("Vector size is wrong!");
    return is;
}

template <typename T, typename U, len_t N>
inline constexpr bool AlmostEqual(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(len_t i = 0; i < N; i++)
        if(!AlmostEqual(lhs[i], rhs[i]))
            return false;
    return true;
}

template <typename T, typename U, len_t N> 
inline constexpr auto Dot(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    decltype(lhs[0] * rhs[0]) res = 0;
    for(len_t i = 0; i < N; i++)
        res += lhs[i] * rhs[i];
    return res;
}

template <typename T, typename U> 
inline constexpr auto Cross(const Vector<T, 3>& lhs, const Vector<U, 3>& rhs)
{
    return Vector<std::common_type_t<T, U>, 3>
    {
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    };
}

template <typename T, len_t N>
inline constexpr Vector<T, N> Smoothstep(const Vector<T, N>& lhs, const Vector<T, N>& rhs, const Vector<T, N>& x)
{
    Vector<T, N> res;
    for(len_t i = 0; i < N; i++)
        res[i] = Smoothstep(lhs[i], rhs[i], x[i]);
    return res;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> Lerp(
    const type_identity_t<Vector<T, N>>& lhs,
    const type_identity_t<Vector<T, N>>& rhs,
    const f64 t)
{
    return (rhs - lhs) * t + lhs;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> Slerp(
    const type_identity_t<Vector<T, N>>& lhs,
    const type_identity_t<Vector<T, N>>& rhs,
    const f64 t)
{
    const T d = std::clamp(Dot(lhs, rhs), T(-1), T(1));
    const f64 theta = std::acos(d) * t;
    const Vector<T, N> v = (rhs - lhs * d).Norm();
    return lhs * std::cos(theta) + v * std::sin(theta);
}

template <typename T, len_t N>
inline constexpr Vector<T, N> Reflect(const Vector<T, N>& vec, const Vector<T, N>& norm)
{
    return vec - T(2) * Dot(vec, norm) * norm;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> Clamp(const Vector<T, N>& lhs, const Vector<T, N>& lo, const Vector<T, N>& hi)
{
    Vector<T, N> res;
    for(len_t i = 0; i < N; i++)
        res[i] = std::clamp(lhs[i], lo[i], hi[i]);
    return res;
}

template <typename T, len_t N>
inline constexpr Vector<T, N> Clamp(const Vector<T, N>& lhs, const T& lo, const T& hi)
{
    Vector<T, N> res;
    for(len_t i = 0; i < N; i++)
        res[i] = std::clamp(lhs[i], lo, hi);
    return res;
}

template <typename T, len_t N> 
inline constexpr T Min(const Vector<T, N>& lhs)
{
    T res = lhs[0];
    for(len_t i = 1; i < N; i++)
        res = std::min(lhs[i], res);
    return res;
}

template <typename T, len_t N> 
inline constexpr T Max(const Vector<T, N>& lhs)
{
    T res = lhs[0];
    for(len_t i = 1; i < N; i++)
        res = std::max(lhs[i], res);
    return res;
}

template <typename T>
inline Vector<T, 2> GetVectorFromAngle(const T& angle)
{
    return Vector<T, 2>{std::cos(angle), std::sin(angle)};
}

template <typename T>
inline constexpr T Hypot(const Vector<T, 2>& lhs)
{
    return lhs.Mag();
}

template <typename T, len_t N>
inline constexpr u32 Hash(const Vector<T, N>& lhs)
{
    return Hash(reinterpret_cast<const u8*>(lhs.GetAddressOf()), sizeof(T) * N);
}

template <typename T, len_t N>
inline constexpr bool IsAnyValueEqual(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
    COMPARISON_OPERATOR_HELPER_OR(lhs[i] == rhs[i], N)
}

template <typename T, len_t N>
inline constexpr bool IsAnyValueGreater(const Vector<T, N>& lhs, const T& rhs)
{
    return !(lhs <= rhs);
}

template <typename T, len_t N>
inline constexpr bool IsAnyValueLess(const Vector<T, N>& lhs, const T& rhs)
{
    return !(lhs >= rhs);
}

template <typename T>
inline constexpr Vector<T, 3> RGB2HSV(const Vector<T, 3>& rgb)
{
    Vector<T, 3> res;
    const T cmax = Max(rgb);
    const T cmin = Min(rgb);
    if(cmax == cmin)
        return {T(0), T(0), cmax * T(100)};
    const T delta = cmax - cmin;
    if(cmax == rgb.r)
        res.h = Mod((rgb.g - rgb.b) / delta, T(6));
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
inline constexpr Vector<T, 3> RGB2HSV(const Vector<u8, 3>& rgb)
{
    return RGB2HSV<T>(rgb / T(255));
}

using bvec1 = Vector<bool, 1>;
using bvec2 = Vector<bool, 2>;
using bvec3 = Vector<bool, 3>;
using bvec4 = Vector<bool, 4>;

using vec1 = Vector<f32, 1>;
using vec2 = Vector<f32, 2>;
using vec3 = Vector<f32, 3>;
using vec4 = Vector<f32, 4>;

using dvec1 = Vector<f64, 1>;
using dvec2 = Vector<f64, 2>;
using dvec3 = Vector<f64, 3>;
using dvec4 = Vector<f64, 4>;

using cvec1 = Vector<i8, 1>;
using cvec2 = Vector<i8, 2>;
using cvec3 = Vector<i8, 3>;
using cvec4 = Vector<i8, 4>;

using svec1 = Vector<i16, 1>;
using svec2 = Vector<i16, 2>;
using svec3 = Vector<i16, 3>;
using svec4 = Vector<i16, 4>;

using ivec1 = Vector<i32, 1>;
using ivec2 = Vector<i32, 2>;
using ivec3 = Vector<i32, 3>;
using ivec4 = Vector<i32, 4>;

using ucvec1 = Vector<u8, 1>;
using ucvec2 = Vector<u8, 2>;
using ucvec3 = Vector<u8, 3>;
using ucvec4 = Vector<u8, 4>;

using usvec1 = Vector<u16, 1>;
using usvec2 = Vector<u16, 2>;
using usvec3 = Vector<u16, 3>;
using usvec4 = Vector<u16, 4>;

using uvec1 = Vector<u32, 1>;
using uvec2 = Vector<u32, 2>;
using uvec3 = Vector<u32, 3>;
using uvec4 = Vector<u32, 4>;

using ulvec1 = Vector<u64, 1>;
using ulvec2 = Vector<u64, 2>;
using ulvec3 = Vector<u64, 3>;
using ulvec4 = Vector<u64, 4>;

using Vec1 = vec1;
using Vec2 = vec2;
using Vec3 = vec3;
using Vec4 = vec4;

template <typename T, len_t R, len_t C, typename = std::enable_if_t<std::is_arithmetic_v<T>>> 
class Matrix
{
private:
    Vector<T, R> cols[C];
public:
    inline constexpr Matrix& operator=(const Matrix& lhs) = default;
    inline constexpr Matrix& operator=(Matrix&& lhs) = default;
    inline constexpr Matrix(const Matrix& lhs) = default;
    inline constexpr Matrix(Matrix&& lhs) = default;
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
    template <typename... Args, typename = std::enable_if_t<are_arithmetic_v<Args...> && sizeof...(Args) + 1 == R * C>> 
    inline constexpr Matrix(const T& lhs, const Args&... args)
    {
        const T arr[] = {lhs, static_cast<T>(args)...};
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                cols[j][i] = arr[i * C + j];
    }
    template <typename... Args, typename = std::enable_if_t<sizeof...(Args) + 1 == R>>
    inline constexpr Matrix(const Vector<T, C>& lhs, const Vector<Args, C>&... args)
    {
        const Vector<T, C> arr[] = {lhs, static_cast<Vector<T, C>>(args)...};
        for(len_t i = 0; i < R; i++)
            SetRow(i, arr[i]);
    }
    template <len_t N, len_t M>
    inline constexpr Matrix(const Matrix<T, N, M>& lhs)
    {
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                cols[j][i] = (i < N && j < M) ? lhs[j][i] : (T)(i == j && R == C);
    }
public:
    template <len_t N = R, len_t M = C, typename = std::enable_if_t<N == M>>
    static inline constexpr Matrix<T, R, C> Identity()
    {
        Matrix<T, R, C> res;
        for(len_t i = 0; i < R; i++)
            res[i][i] = T(1);
        return res;
    }
    static inline constexpr Matrix<T, R, C> Zero()
    {
        return T(0);
    }
    inline static constexpr Matrix<T, R, C> Random(const T& lo, const T& hi)
    {
        Matrix<T, R, C> res;
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                res[j][i] = Random::Next(lo, hi);
        return res;
    }
    inline static constexpr Matrix<T, R, C> Random(const Matrix<T, R, C>& lo, const Matrix<T, R, C>& hi)
    {
        Matrix<T, R, C> res;
        for(len_t i = 0; i < R; i++)
            for(len_t j = 0; j < C; j++)
                res[j][i] = Random::Next(lo[j][i], hi[j][i]);
        return res;
    }
public:
    inline constexpr const Vector<T, C> GetRow(const len_t& lhs) const
    {
        if(CheckIndex(lhs, R))
        {
            Vector<T, C> res;
            for(len_t i = 0; i < C; i++) 
                res[i] = cols[i][lhs];
            return res;
        }
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr const Vector<T, R>& GetColumn(const len_t& lhs) const
    {
        if(CheckIndex(lhs, C))
            return cols[lhs];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr void SetRow(const len_t& lhs, const Vector<T, C>& rhs) 
    {
        if(CheckIndex(lhs, R))
            for(len_t i = 0; i < C; i++) 
                cols[i][lhs] = rhs[i];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr void SetColumn(const len_t& lhs, const Vector<T, R>& rhs)
    {
        if(CheckIndex(lhs, C))
            cols[lhs] = rhs;
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr Matrix<T, C, R> Transpose() const
    {
        Matrix<T, C, R> res;
        for(len_t i = 0; i < C; i++)
            res.SetRow(i, GetColumn(i));
        return res;
    }
    template <len_t N = R, len_t M = C, typename = std::enable_if_t<N == M>>
    inline constexpr Matrix<T, R, C> Inverse() const
    {
        Matrix<T, R, C> temp = *this;
        Matrix<T, R, C> res = Matrix<T, R, C>::Identity();
        for(len_t i = 0; i < R; i++)
        {
            const T div = temp[i][i];
            res.SetColumn(i, res.GetColumn(i) / div);
            temp.SetRow(i, temp.GetRow(i) / div);
            for(len_t j = 0; j < R; j++)
            {
                if(i != j)
                {
                    const T mul = temp[i][j];
                    res.SetColumn(j, res.GetColumn(j) - (res.GetColumn(i) * mul));
                    temp.SetRow(j, temp.GetRow(j) - (temp.GetRow(i) * mul));
                }
            }
        }
        return res.Transpose();
    }
    template <len_t N = R, len_t M = C, typename = std::enable_if_t<N == M>>
    inline constexpr Matrix<T, R, C> Pow(const len_t& lhs) const
    {
        if(lhs == 0)
            return Matrix<T, R, C>::Identity();
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
    template <len_t N = R, len_t M = C, typename = std::enable_if_t<N == M>>
    inline constexpr T Determinant() const
    {
        T res = T(1);
        Matrix<T, R, C> temp = *this;
        for(len_t i = 0; i < R; i++)
        {
            const T div = temp[i][i];
            for(len_t j = i + 1; j < R; j++)
            {
                const T mul = temp[i][j];
                temp.SetRow(j, temp.GetRow(j) - (temp.GetRow(i) / div * mul));
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
        if(CheckIndex(index, C))
            return cols[index];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr Vector<T, R>& operator[](const len_t& index)
    {
        if(CheckIndex(index, C))
            return cols[index];
        else
            throw std::out_of_range("Index out of range!");
    }
    inline constexpr T& operator()(const len_t& i, const len_t& j)
    {
        return (*this)[i][j];
    }
    inline constexpr const T& operator()(const len_t& i, const len_t& j) const
    {
        return (*this)[i][j];
    }
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0][0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0][0];
    }
};

template <typename T, typename U, len_t TR, len_t TC, len_t UR, len_t UC>
struct are_templates_same<Matrix<T, TR, TC>, Matrix<U, UR, UC>> : std::true_type {};

template <typename T, len_t R, len_t C>
struct inner_type<Matrix<T, R, C>, void>
{using type = T;};

template <typename T, typename U, len_t R, len_t C, len_t N>
inline constexpr auto operator*(const Matrix<T, R, C>& lhs, const Matrix<U, C, N>& rhs)
{
    Matrix<decltype(lhs[0][0] * rhs[0][0]), R, N> res;
    for(len_t i = 0; i < N; i++)
        for(len_t j = 0; j < R; j++)
            res[i][j] = Dot(lhs.GetRow(j), rhs.GetColumn(i));
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
    return lhs * rhs.Inverse();
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator/=(Matrix<T, R, C>& lhs, const Matrix<U, C, C>& rhs)
{
    lhs = lhs * rhs.Inverse();
    return lhs;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*(const Matrix<T, R, C>& lhs, const Vector<U, C>& rhs)
{
    Vector<decltype(lhs[0][0] * rhs[0]), R> res;
    for(len_t i = 0; i < R; i++)
        res[i] = Dot(lhs.GetRow(i), rhs);
    return res;
}

template <typename T, typename U, len_t R, len_t C>
inline constexpr auto operator*(const Vector<T, R>& lhs, const Matrix<U, R, C>& rhs)
{
    Vector<decltype(lhs[0] * rhs[0][0]), C> res;
    for(len_t i = 0; i < C; i++)
        res[i] = Dot(lhs, rhs[i]);
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
        os << mat.GetRow(i);
    return os;
}

template <typename T, len_t R, len_t C>
inline std::istream& operator>>(std::istream& is, Matrix<T, R, C>& mat)
{
    Vector<T, C> vec;
    for(len_t i = 0; i < R; i++)
    {
        is >> vec;
        mat.SetRow(i, vec);
    }
    return is;
}

DEFINE_MATRIX_COMPARISON_OPERATOR(<=, AND)
DEFINE_MATRIX_COMPARISON_OPERATOR(>=, AND)
DEFINE_MATRIX_COMPARISON_OPERATOR(==, AND)
DEFINE_MATRIX_COMPARISON_OPERATOR(<, AND)
DEFINE_MATRIX_COMPARISON_OPERATOR(>, AND)
DEFINE_MATRIX_COMPARISON_OPERATOR(!=, OR)

template <typename T>
inline constexpr Matrix<T, 4, 4> GetPerspectiveMatrix(const T& aspect, const T& fov, const T& near, const T& far)
{
    const T half_fov = std::tan(Deg2Rad(fov) / T(2));
    return Matrix<T, 4, 4>
    {
        T(1) / (aspect * half_fov), T(0), T(0), T(0),
        T(0), T(1) / (half_fov), T(0), T(0),
        T(0), T(0), (near + far) / (near - far), (T(2) * far * near) / (near - far),
        T(0), T(0), T(-1), T(0)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetOrthographicMatrix(const T& right, const T& left, const T& bottom, const T& top, const T& near, const T& far)
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
inline constexpr Matrix<T, 4, 4> MatrixLookAt(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
{
    const Vector<T, 3> en = (center - eye).Norm();
    Vector<T, 3> cn = up.Norm();
    const Vector<T, 3> un = Cross(en, cn).Norm();
    cn = Cross(un, en);
    return Matrix<T, 4, 4>
    {
        un.x, un.y, un.z, -Dot(un, eye),
        cn.x, cn.y, cn.z, -Dot(cn, eye),
        -en.x, -en.y, -en.z, Dot(en, eye),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetRotationMatrix(const T& angle, const Vector<T, 3>& axis)
{
    const T c = std::cos(angle);
    const T s = std::sin(angle);
    const Vector<T, 3> norm = axis.Norm();
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
inline constexpr Matrix<T, 4, 4> GetRotationMatrixX(const T& angle)
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
inline constexpr Matrix<T, 4, 4> GetRotationMatrixY(const T& angle)
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
inline constexpr Matrix<T, 4, 4> GetRotationMatrixZ(const T& angle)
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
inline constexpr Matrix<T, 4, 4> GetRotationMatrixFromEulerAngles(const T& r, const T& p, const T& y)
{
    const T cr = std::cos(r);
    const T sr = std::sin(r);
    const T cp = std::cos(p);
    const T sp = std::sin(p);
    const T cy = std::cos(y);
    const T sy = std::sin(y);
    return Matrix<T, 4, 4>
    {
        cp * cy, sr * sp * cy - sy * cr, cr * sp * cy + sr * sy, T(0),
        cp * sy, sr * sp * sy + cr * cy, cr * sp * sy - sr * cy, T(0),
        -sp, sr * cp, cr * cp, T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetRotationMatrixFromEulerAngles(const Vector<T, 3>& vec)
{
    return GetRotationMatrixFromEulerAngles(vec.roll, vec.pitch, vec.yaw);
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetTranslationMatrix(const T& x, const T& y, const T& z)
{
    return Matrix<T, 4, 4>
    {
        T(1), T(0), T(0), x,
        T(0), T(1), T(0), y,
        T(0), T(0), T(1), z,
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetTranslationMatrix(const Vector<T, 3>& lhs)
{
    return GetTranslationMatrix(lhs.x, lhs.y, lhs.z);
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetScalingMatrix(const T& x, const T& y, const T& z)
{
    return Matrix<T, 4, 4>
    {
        x, T(0), T(0), T(0),
        T(0), y, T(0), T(0),
        T(0), T(0), z, T(0),
        T(0), T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetScalingMatrix(const Vector<T, 3>& lhs)
{
    return GetScalingMatrix(lhs.x, lhs.y, lhs.z);
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetRotationMatrix(const T& angle)
{
    return Matrix<T, 3, 3>{GetRotationMatrixZ(angle)};
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetTranslationMatrix(const T& x, const T& y)
{
    return Matrix<T, 3, 3>
    {
        T(1), T(0), x,
        T(0), T(1), y,
        T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetTranslationMatrix(const Vector<T, 2>& lhs)
{
    return GetTranslationMatrix(lhs.x, lhs.y);
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetScalingMatrix(const T& x, const T& y)
{
    return Matrix<T, 3, 3>
    {
        x, T(0), T(0),
        T(0), y, T(0),
        T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetScalingMatrix(const Vector<T, 2>& lhs)
{
    return GetScalingMatrix(lhs.x, lhs.y);
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetShearMatrix(const T& x, const T& y)
{
    return Matrix<T, 3, 3>
    {
        T(1), x, T(0),
        y, T(1), T(0),
        T(0), T(0), T(1)
    };
}

template <typename T>
inline constexpr Matrix<T, 3, 3> GetShearMatrix(const Vector<T, 2>& lhs)
{
    return GetShearMatrix(lhs.x, lhs.y);
}

template <typename T>
inline constexpr Vector<T, 3> GetTranslationFromMatrix(const Matrix<T, 4, 4>& lhs)
{
    return {lhs[3][0], lhs[3][1], lhs[3][2]};
}

template <typename T>
inline constexpr Vector<T, 3> GetScaleFromMatrix(const Matrix<T, 4, 4>& lhs)
{
    return 
    {
        Vector<T, 3>{lhs[0].xyz}.Mag(),
        Vector<T, 3>{lhs[1].xyz}.Mag(),
        Vector<T, 3>{lhs[2].xyz}.Mag()
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetRotationFromMatrix(const Matrix<T, 4, 4>& lhs)
{
    const Vector<T, 3> scale = GetScaleFromMatrix(lhs);
    return Matrix<T, 4, 4>
    {
        Vector<T, 4>{lhs[0][0], lhs[1][0], lhs[2][0], T(0)} / scale.x,
        Vector<T, 4>{lhs[0][1], lhs[1][1], lhs[2][1], T(0)} / scale.y,
        Vector<T, 4>{lhs[0][2], lhs[1][2], lhs[2][2], T(0)} / scale.z,
        Vector<T, 4>{T(0), T(0), T(0), T(1)}
    };
}

template <typename T>
inline constexpr Vector<T, 2> GetTranslationFromMatrix(const Matrix<T, 3, 3>& lhs)
{
    return {lhs[2][0], lhs[2][1]};
}

template <typename T>
inline constexpr Vector<T, 2> GetScaleFromMatrix(const Matrix<T, 3, 3>& lhs)
{
    return 
    {
        Vector<T, 2>{lhs[0].xy}.Mag(),
        Vector<T, 2>{lhs[1].xy}.Mag()
    };
}

template <typename T>
inline constexpr T GetRotationFromMatrix(const Matrix<T, 3, 3>& lhs)
{
    return std::atan2(lhs[0][1], lhs[0][0]);
}

template <typename T>
inline constexpr Vector<T, 3> GetEulerAnglesFromMatrix(const Matrix<T, 4, 4>& lhs)
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
            g_kHalfPi<T>,
            T(0)
        };
    else
        return 
        {
            std::atan2(-lhs[1][0], -lhs[2][0]),
            -g_kHalfPi<T>,
            T(0)
        };
}

template <typename T>
inline constexpr Vector<T, 3> GetEulerAnglesFromAxis(const T& angle, const Vector<T, 3>& axis)
{
    const Vector<T, 3> norm = axis.Norm();
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
        ) - g_kHalfPi<T>,
        std::atan2
        (
            norm.z * s + v * norm.x * norm.y,
            T(1) - v * (norm.y * norm.y + norm.z * norm.z)
        )
    };
}

template <typename T, len_t N, len_t M>
inline constexpr u32 Hash(const Matrix<T, N, M>& lhs)
{
    return Hash(reinterpret_cast<const u8*>(lhs.GetAddressOf()), sizeof(T) * N * M);
}

using mat2 = Matrix<f32, 2, 2>;
using mat3 = Matrix<f32, 3, 3>;
using mat4 = Matrix<f32, 4, 4>;

using dmat2 = Matrix<f64, 2, 2>;
using dmat3 = Matrix<f64, 3, 3>;
using dmat4 = Matrix<f64, 4, 4>;

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>> 
class Quaternion
{
public:
    union
    {
        struct { T w, x, y, z; };
        struct { T scalar; Vector<T, 3> vec; };
    };
public:
    inline constexpr Quaternion& operator=(Quaternion&& lhs) = default;
    inline constexpr Quaternion& operator=(const Quaternion& lhs) = default;
    inline constexpr Quaternion(const Quaternion& lhs) = default;
    inline constexpr Quaternion(Quaternion&& lhs) = default;
    inline constexpr Quaternion() : scalar(T(1)), vec(T(0)) {}
    inline constexpr Quaternion(const T& lhs, const Vector<T, 3>& rhs) : scalar(lhs), vec(rhs) {}
    inline constexpr Quaternion(const T& w, const T& x, const T& y, const T& z) : w(w), x(x), y(y), z(z) {}
public:
    static inline constexpr Quaternion<T> Identity()
    {
        return {};
    }
    inline static constexpr Quaternion<T> Random(const Quaternion<T>& lo, const Quaternion<T>& hi)
    {
        return
        {
            Random::Next(lo.w, hi.w),
            Random::Next(lo.x, hi.x),
            Random::Next(lo.y, hi.y),
            Random::Next(lo.z, hi.z)
        };
    }
    inline static constexpr Quaternion<T> Random(const T& lo, const T& hi)
    {
        return 
        {
            Random::Next(lo, hi),
            Random::Next(lo, hi),
            Random::Next(lo, hi),
            Random::Next(lo, hi)
        };
    }
public:
    inline constexpr Quaternion<T> Conjugate() const
    {
        return {w, -vec};
    }
    inline constexpr Quaternion<T> Inverse() const
    {
        const T mag = this->Mag2();
        if(mag == T(0)) return {};
        return {w / mag, -vec / mag};
    }
    inline constexpr T Mag2() const
    {
        return vec.Mag2() + w * w;
    }
    inline constexpr T Norm() const
    {
        return std::sqrt(this->Mag2());
    }
    inline constexpr Quaternion<T> Normalize() const
    {
        const T mag = this->Norm();
        return ((mag == T(0) || mag == T(1)) ? *this : *this / mag);
    }
    inline constexpr Vector<T, 3> Rotate(const Vector<T, 3>& lhs) const
    {
        return T(2) * Dot(vec, lhs) * vec + (w * w - vec.Mag2()) * lhs + T(2) * w * Cross(vec, lhs);
    }
    inline constexpr T& operator[](const len_t& index)
    {
        switch(index)
        {
            case 0: return w;
            case 1: return x;
            case 2: return y;
            case 3: return z;
            default: throw std::out_of_range("Index out of range!");
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
            default: throw std::out_of_range("Index out of range!");
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
    inline constexpr T* GetAddressOf()
    {
        return &(*this)[0];
    }
    inline constexpr const T* GetAddressOf() const
    {
        return &(*this)[0];
    }
};

using quat = Quaternion<f32>;
using dquat = Quaternion<f64>;

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
    return lhs * rhs.Inverse();
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
    lhs = lhs * rhs.Inverse();
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
inline constexpr Quaternion<T> GetQuaternionFromEulerAngles(const Vector<T, 3>& lhs)
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
inline constexpr Quaternion<T> GetQuaternionFromAxis(const Vector<T, 3>& axis, const T& angle)
{
    Quaternion<T> res;
    res.w = std::cos(angle / T(2));
    res.vec = std::sin(angle / T(2)) * axis;
    return res;
}

template <typename T>
inline constexpr Vector<T, 3> QuaternionToEulerAngles(const Quaternion<T>& lhs)
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
        ) - g_kHalfPi<T>,
        std::atan2
        (
            T(2) * (lhs.w * lhs.z + lhs.x * lhs.y),
            T(1) - T(2) * (lhs.y * lhs.y + lhs.z * lhs.z)
        )
    };
}

template <typename T>
inline constexpr Matrix<T, 4, 4> GetMatrixFromQuaternion(const Quaternion<T>& lhs)
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
inline constexpr Quaternion<T> GetQuaternionFromMatrix(const Matrix<T, 4, 4>& lhs)
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
inline constexpr T QuaternionToAxis(const Quaternion<T>& lhs, Vector<T, 3>& rhs)
{
    const T div = std::sqrt(T(1) - lhs.w * lhs.w);
    rhs = lhs.vec / (div == T(0) ? Vector<T, 3>::Right() : div);
    return T(2) * std::acos(lhs.w);
}

template <typename T>
inline constexpr Quaternion<T> Slerp(const Quaternion<T>& lhs, const Quaternion<T>& rhs, const f64 t)
{
    const T ch = lhs.w * rhs.w + Dot(lhs.vec, rhs.vec);
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
inline constexpr Vector<T, 2> Rotate(const T& angle, const T& x, const T& y, const T& ox = T(0), const T& oy = T(0))
{
    if(NotRotated(angle))
        return {x, y};
    else
        return
        {
            ox + (std::cos(angle) * (x - ox) - std::sin(angle) * (y - oy)),
            oy + (std::sin(angle) * (x - ox) + std::cos(angle) * (y - oy))
        };
}

template <typename T>
inline constexpr Vector<T, 2> Rotate(const T& angle, const Vector<T, 2>& vec, const Vector<T, 2>& origin = Vector<T, 2>::Zero())
{
    return Rotate(angle, vec.x, vec.y, origin.x, origin.y);
}

template <typename T>
inline constexpr u32 Hash(const Quaternion<T>& lhs)
{
    return Hash(reinterpret_cast<const u8*>(lhs.GetAddressOf()), sizeof(T) * 4);
}

template <typename T>
inline constexpr T Gradient(const u8 hash, const T& x)
{
    return (hash & 1) ? x : -x;
}

template <typename T>
inline constexpr T Perlin(const T& x)
{
    const i32 xi = (i32)x & 0xFF;
    const T xf = Fract(x);
    const T u = Fade(xf);
    const u8 a = g_kPerlinNoiseHashTable[xi + 0];
    const u8 b = g_kPerlinNoiseHashTable[xi + 1];
    return (Lerp(Gradient(a, xf), Gradient(b, xf - T(1)), u) + T(1)) / T(2);
}

template <typename T>
inline constexpr T Gradient(const u8 hash, const T& x, const T& y)
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
inline constexpr T Perlin(const T& x, const T& y)
{
    const i32 xi = (i32)x & 0xFF;
    const i32 yi = (i32)y & 0xFF;
    const T xf = Fract(x);
    const T yf = Fract(y);
    const T u = Fade(xf);
    const T v = Fade(yf);
    const u8 aa = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 0] + yi + 0];
    const u8 ab = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 0] + yi + 1];
    const u8 ba = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 1] + yi + 0];
    const u8 bb = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 1] + yi + 1];
    const T x1 = Lerp(Gradient(aa, xf, yf), Gradient(ba, xf - T(1), yf), u);
    const T x2 = Lerp(Gradient(ab, xf, yf - T(1)), Gradient(bb, xf - T(1), yf - T(1)), u);
    return (Lerp(x1, x2, v) + T(1)) / T(2);
}

template <typename T>
inline constexpr T Perlin(const Vector<T, 2>& lhs)
{
    return Perlin(lhs.x, lhs.y);
}

template <typename T>
inline constexpr T Gradient(const u8 hash, const T& x, const T& y, const T& z)
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
inline constexpr T Perlin(const T& x, const T& y, const T& z)
{
    const i32 xi = (i32)x & 0xFF;
    const i32 yi = (i32)y & 0xFF;
    const i32 zi = (i32)z & 0xFF;
    const T xf = Fract(x);
    const T yf = Fract(y);
    const T zf = Fract(z);
    const T u = Fade(xf);
    const T v = Fade(yf);
    const T w = Fade(zf);
    const u8 aaa = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 0] + yi + 0] + zi + 0];
    const u8 aba = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 0] + yi + 1] + zi + 0];
    const u8 aab = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 0] + yi + 0] + zi + 1];
    const u8 abb = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 0] + yi + 1] + zi + 1];
    const u8 baa = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 1] + yi + 0] + zi + 0];
    const u8 bba = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 1] + yi + 1] + zi + 0];
    const u8 bab = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 1] + yi + 0] + zi + 1];
    const u8 bbb = g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[g_kPerlinNoiseHashTable[xi + 1] + yi + 1] + zi + 1];
    T x1, x2;
    x1 = Lerp(Gradient(aaa, xf, yf, zf), Gradient(baa, xf - T(1), yf, zf), u);
    x2 = Lerp(Gradient(aba, xf, yf - T(1), zf), Gradient(bba, xf - T(1), yf - T(1), zf), u);
    const T y1 = lerp(x1, x2, v);
    x1 = Lerp(Gradient(aab, xf, yf, zf - T(1)), Gradient(bab, xf - T(1), yf, zf - T(1)), u);
    x2 = Lerp(Gradient(abb, xf, yf - T(1), zf - T(1)), Gradient(bbb, xf - T(1), yf - T(1), zf - T(1)), u);
    const T y2 = Lerp(x1, x2, v);
    return (Lerp(y1, y2, w) + T(1)) / T(2);
}

template <typename T>
inline constexpr T Perlin(const Vector<T, 3>& lhs)
{
    return Perlin(lhs.x, lhs.y, lhs.z);
}

template <typename T, len_t N> 
inline constexpr Vector<T, N> GetClosestPointOnLine(const Vector<T, N>& start, const Vector<T, N>& end, const Vector<T, N>& p)
{
    const Vector<T, N> d = end - start;
    const T val = Dot(p - start, d) / Dot(d, d);
    return start + std::clamp(val, T(0), T(1)) * d;
}

template <typename T>
inline constexpr T GetTriangleArea(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2)
{
    return std::abs(
        pos0.x * (pos1.y - pos2.y) +
        pos1.x * (pos2.y - pos0.y) +
        pos2.x * (pos0.y - pos1.y)
    ) / T(2);
}

template <typename T>
inline constexpr T GetTriangleArea(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
{
    const Vector<T, 3> side0 = (pos1 - pos0);
    const Vector<T, 3> side1 = (pos2 - pos0);
    const f64 angle = std::acos(Dot(side0, side1) / (side0.Mag() * side1.Mag()));
    return std::sin(angle) * side0.Mag() * side1.Mag() / T(2);
}

template <typename T>
inline constexpr bool GetPointInTriangle(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2, const Vector<T, 2>& p)
{
    return (T)std::abs(GetTriangleArea(pos0, pos1, pos2) - (GetTriangleArea(pos0, pos1, p) + 
        GetTriangleArea(pos0, pos2, p) + GetTriangleArea(pos1, pos2, p))) < g_kEpsilon<T>;
}

template <typename C, typename T, typename VT = decltype(std::declval<C>().operator[](usize()))>
inline std::enable_if_t<is_container_v<C> && std::is_same_v<VT, Vector<T, 2>>, bool>
GetPointInPolygon(const C& poly, const Vector<T, 2>& vec, std::void_t<VT>* = 0)
{
    for(usize i = 1; i < poly.size(); i++)
        if(GetPointInTriangle(poly[0], poly[i], poly[(i + 1) % poly.size()], vec))
            return true;
    return false;
}

template <typename T>
inline constexpr Vector<T, 2> Project(const Vector<T, 2>& vec, const Vector<T, 2>& norm)
{
    return norm * Dot(vec, norm) / norm.Mag2();
}

template <typename T>
inline constexpr Vector<T, 3> Project(const Vector<T, 3>& vec, const Vector<T, 3>& norm)
{
    const T mag = norm.Mag2();
    const T d = Dot(vec, norm);
    if(mag < g_kEpsilon<T>) return T(0);
    return norm * d / mag;
}

template <typename T>
inline constexpr Vector<T, 3> ProjectOntoPlane(const Vector<T, 3>& vec, const Vector<T, 3>& norm)
{
    const T mag = norm.Mag2();
    const T d = Dot(vec, norm);
    if(mag < g_kEpsilon<T>) return vec;
    return vec - norm * d / mag;
}

template <typename T, len_t N>
inline constexpr bool AABBOverlap(const Vector<T, N>& pos0, const Vector<T, N>& size0, const Vector<T, N>& pos1, const Vector<T, N>& size1)
{
    for(len_t i = 0; i < N; i++)
        if(pos0[i] - size0[i] / T(2) > pos1[i] + size1[i] / T(2) || pos0[i] + size0[i] / T(2) < pos1[i] - size1[i] / T(2))
            return false;
    return true;
}

template <typename CTL, typename CTR, typename T, len_t N>
inline bool SATCheckSeperated(
    const CTL& poly0, 
    const CTR& poly1, 
    const Vector<T, N>& axis, 
    std::enable_if_t<are_containers_v<CTL, CTR> &&
    are_elements_accessible_by_index_v<CTL, CTR> && 
    are_inner_types_same_v<Vector<T, N>, CTL, CTR>>* = 0)
{
    T min0 = g_kInfinity<T>, max0 = -g_kInfinity<T>;
    for(usize k = 0; k < poly0.size(); k++)
    {
        const T res = Dot(poly0[k], axis);
        min0 = std::min(min0, res);
        max0 = std::max(max0, res);
    }
    T min1 = g_kInfinity<T>, max1 = -g_kInfinity<T>;
    for(usize p = 0; p < poly1.size(); p++)
    {
        const T res = Dot(poly1[p], axis);
        min1 = std::min(min1, res);
        max1 = std::max(max1, res);
    }
    return !(max1 >= min0 && max0 >= min1);
}

template <typename CTL, typename CTR, typename T = inner_type_t<inner_type_t<CTL>>>
inline bool SATCheck(
    const CTL& poly0,
    const CTR& poly1,
    std::enable_if_t<are_containers_v<CTL, CTR> &&
    are_elements_accessible_by_index_v<CTL, CTR> && 
    are_inner_types_same_v<Vector<T, 2>, CTL, CTR>>* = 0)
{
    for(usize i = 0; i < poly0.size(); i++)
    {
        const usize j = (i + 1) % poly0.size();
        const Vector<T, 2> proj = {poly0[i].y - poly0[j].y, poly0[j].x - poly0[i].x};
        if(SATCheckSeperated(poly0, poly1, proj)) return false;
    }
    return true;
}

template <typename CT0, typename CT1, typename CT2, typename T = inner_type_t<inner_type_t<CT0>>>
inline bool SATOverlap(
    const CT0& poly0, 
    const CT1& poly1, 
    const CT2& axes,
    std::enable_if_t<are_containers_v<CT0, CT1, CT2> 
    && are_elements_accessible_by_index_v<CT0, CT1, CT2> 
    && are_inner_types_same_v<Vector<T, 3>, CT0, CT1, CT2>>* = 0)
{
    for(usize i = 0; i < axes.size(); i++)
        if(SATCheckSeperated(poly0, poly1, axes[i]))
            return false;
    return true;
}

template <typename CTL, typename CTR, typename T = inner_type_t<inner_type_t<CTL>>>
inline bool SATOverlap(
    const CTL& poly0,
    const CTR& poly1,
    std::enable_if_t<are_containers_v<CTL, CTR> &&
    are_elements_accessible_by_index_v<CTL, CTR> && 
    are_inner_types_same_v<Vector<T, 2>, CTL, CTR>>* = 0)
{
    return SATCheck(poly0, poly1) && SATCheck(poly1, poly0);
}

template <typename C, typename T, len_t N>
inline Vector<T, N> GetClosestPointOnPolygon(
    const C& poly, 
    const Vector<T, N>& vec,
    std::enable_if_t<is_container_v<C> &&
    has_index_operator_v<C> && 
    is_inner_type_same_v<Vector<T, N>, C>>* = 0)
{
    T distance = g_kInfinity<T>;
    Vector<T, N> res;
    for(usize i = 0; i < poly.size(); i++)
    {
        const usize j = (i + 1) % poly.size();
        const Vector<T, N> point = GetClosestPointOnLine(poly[i], poly[j], vec);
        const T mag = (point - vec).Mag();
        if(mag < distance)
        {
            res = point;
            distance = mag;
        }
    }
    return res;
}

template <typename CT, typename T, len_t N>
inline T GetClosestDistanceToPolygon(
    const CT& poly, 
    const Vector<T, N>& vec,
    std::enable_if_t<is_container_v<CT> &&
    has_index_operator_v<CT> && 
    is_inner_type_same_v<Vector<T, N>, CT>>* = 0)
{
    return (GetClosestPointOnPolygon(poly, vec) - vec).Mag();
}

template <typename T>
inline constexpr Vector<T, 3> GetSurfaceNormal(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
{
    return Cross(pos1 - pos0, pos2 - pos0).Norm();
}

template <typename T, len_t N>
class BoundingBox {};

template <typename T>
class BoundingBox<T, 3>
{
public:
    Vector<T, 3> pos;
    Vector<T, 3> size;
    Vector<T, 3> rotation;
public:
    inline constexpr BoundingBox() = default;
    inline constexpr BoundingBox& operator=(BoundingBox<T, 3>&& lhs) = default;
    inline constexpr BoundingBox& operator=(const BoundingBox<T, 3>& lhs) = default;
    inline constexpr BoundingBox(BoundingBox<T, 3>&& lhs) = default;
    inline constexpr BoundingBox(const BoundingBox<T, 3>& lhs) = default;
    inline constexpr BoundingBox(const Vector<T, 3>& pos, const Vector<T, 3>& size, const Vector<T, 3>& rotation = T(0)) 
    : pos(pos), size(size), rotation(rotation) {}
public:
    inline constexpr bool Overlaps(const Vector<T, 3>& p) const
    {
        const Matrix<T, 4, 4> inv = (GetTranslationMatrix(pos) * GetRotationMatrixFromEulerAngles(rotation) * GetScalingMatrix(size)).Inverse();
        const Vector<T, 4> transformed = inv * Vector<T, 4>{p, T(1)};
        return AABBOverlap(Vector<T, 3>::Zero(), Vector<T, 3>::One(), transformed.xyz, Vector<T, 3>::Zero());
    }
    inline constexpr bool Overlaps(const BoundingBox<T, 3>& box) const
    {
        if(NotRotated(rotation) && NotRotated(box.rotation))
            return AABBOverlap(pos, size, box.pos, box.size);
        std::array<Vector<T, 3>, 15> all_axes;
        const std::array<Vector<T, 3>, 3> axes0 = GetAxes();
        const std::array<Vector<T, 3>, 3> axes1 = box.GetAxes();
        all_axes[0] = axes0[0];
        all_axes[1] = axes0[1];
        all_axes[2] = axes0[2];
        all_axes[3] = axes1[0];
        all_axes[4] = axes1[1];
        all_axes[5] = axes1[2];
        all_axes[6] = Cross(axes0[0], axes1[0]);
        all_axes[7] = Cross(axes0[1], axes1[0]);
        all_axes[8] = Cross(axes0[2], axes1[0]);
        all_axes[9] = Cross(axes0[0], axes1[1]);
        all_axes[10] = Cross(axes0[1], axes1[1]);
        all_axes[11] = Cross(axes0[2], axes1[1]);
        all_axes[12] = Cross(axes0[0], axes1[2]);
        all_axes[13] = Cross(axes0[1], axes1[2]);
        all_axes[14] = Cross(axes0[2], axes1[2]);
        return SATOverlap(box.GetVertices(), GetVertices(), all_axes);
    }
    inline constexpr bool Overlaps(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2) const
    {
        const Vector<T, 3> norm = GetSurfaceNormal(pos0, pos1, pos2);
        std::array<Vector<T, 3>, 4> all_axes = GetAxes();
        all_axes[0] = Cross(norm, all_axes[0]);
        all_axes[1] = Cross(norm, all_axes[1]);
        all_axes[2] = Cross(norm, all_axes[2]);
        all_axes[3] = norm;
        return SATOverlap(GetVertices(), std::array<Vector<T, 3>, 3>{pos0, pos1, pos2}, all_axes);
    }
    inline constexpr std::array<Vector<T, 3>, 8> GetVertices() const
    {
        const Vector<T, 3> half = size / T(2);
        const Quaternion<T> quat = GetQuaternionFromEulerAngles(rotation);
        return
        {
            pos + quat.Rotate(Vector<T, 3>{-half.x, -half.y, -half.z}),
            pos + quat.Rotate(Vector<T, 3>{-half.x, -half.y,  half.z}),
            pos + quat.Rotate(Vector<T, 3>{-half.x,  half.y,  half.z}),
            pos + quat.Rotate(Vector<T, 3>{-half.x,  half.y, -half.z}),
            pos + quat.Rotate(Vector<T, 3>{ half.x, -half.y, -half.z}),
            pos + quat.Rotate(Vector<T, 3>{ half.x,  half.y, -half.z}),
            pos + quat.Rotate(Vector<T, 3>{ half.x, -half.y,  half.z}),
            pos + quat.Rotate(Vector<T, 3>{ half.x,  half.y,  half.z})
        };
    }
    inline constexpr std::array<Vector<T, 3>, 3> GetAxes() const
    {
        const Quaternion<T> quat = GetQuaternionFromEulerAngles(rotation);
        return 
        {
            quat.Rotate(Vector<T, 3>::Right()),
            quat.Rotate(Vector<T, 3>::Up()),
            quat.Rotate(Vector<T, 3>::Forward())
        };
    }
public:
    inline friend constexpr BoundingBox<T, 3> operator*=(BoundingBox<T, 3>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        lhs.pos += GetTranslationFromMatrix(rhs);
        lhs.size *= GetScaleFromMatrix(rhs);
        lhs.rotation = QuaternionToEuler(GetQuaternionFromEulerAngles(lhs.rotation) * GetQuaternionFromMatrix(GetRotationFromMatrix(rhs)));
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
class BoundingBox<T, 2>
{
public:
    Vector<T, 2> pos;
    Vector<T, 2> size;
    T rotation = T(0);
public:
    inline constexpr BoundingBox() = default;
    inline constexpr BoundingBox& operator=(BoundingBox<T, 2>&& lhs) = default;
    inline constexpr BoundingBox& operator=(const BoundingBox<T, 2>& lhs) = default;
    inline constexpr BoundingBox(BoundingBox<T, 2>&& lhs) = default;
    inline constexpr BoundingBox(const BoundingBox<T, 2>& lhs) = default;
    inline constexpr BoundingBox(const Vector<T, 2>& pos, const Vector<T, 2>& size, const T& rotation = T(0)) 
    : pos(pos), size(size), rotation(rotation) {}
public:
    inline constexpr bool Overlaps(const Vector<T, 2>& p) const
    {
        const std::array<Vector<T, 2>, 4> vertices = GetVertices();
        return (T)std::abs(size.Area() - (GetTriangleArea(vertices[0], p, vertices[1]) + GetTriangleArea(vertices[1], p, vertices[2]) +
            GetTriangleArea(vertices[2], p, vertices[3]) + GetTriangleArea(vertices[0], p, vertices[3]))) < g_kEpsilon<T>;
    }
    inline constexpr bool Overlaps(const BoundingBox<T, 2>& box) const
    {
        if(NotRotated(rotation) && NotRotated(box.rotation))
            return AABBOverlap(pos, size, box.pos, box.size);
        return SATOverlap(box.GetVertices(), GetVertices());
    }
    inline bool Overlaps(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2) const
    {
        return this->Overlaps({pos0, pos1, pos2});
    }
    template <usize N>
    inline bool Overlaps(const std::array<Vector<T, 2>, N>& vertices) const
    {
        return SATOverlap(GetVertices(), vertices);
    }
    inline bool Overlaps(const std::vector<Vector<T, 2>>& vertices) const
    {
        return SATOverlap(this->GetVertices(), vertices);
    }
    inline constexpr std::array<Vector<T, 2>, 4> GetVertices() const
    {
        const Vector<T, 2> half = size / T(2);
        return 
        {
            pos + Rotate<T>(rotation, -half),
            pos + Rotate<T>(rotation, {half.w, -half.h}),
            pos + Rotate<T>(rotation, half),
            pos + Rotate<T>(rotation, {-half.w, half.h})
        };
    }
public:
    inline friend constexpr BoundingBox<T, 2> operator*=(BoundingBox<T, 2>& lhs, const Matrix<T, 3, 3>& rhs)
    {
        lhs.pos += GetTranslationFromMatrix(rhs);
        lhs.size *= GetScaleFromMatrix(rhs);
        lhs.rotation += GetRotationFromMatrix(rhs);
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
class BoundingSphere
{
    static_assert(N == 2 || N == 3);
public:
    Vector<T, N> pos;
    T radius;
public:
    inline constexpr BoundingSphere() = default;
    inline constexpr BoundingSphere& operator=(BoundingSphere<T, N>&& lhs) = default;
    inline constexpr BoundingSphere& operator=(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(BoundingSphere<T, N>&& lhs) = default;
    inline constexpr BoundingSphere(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(const Vector<T, N>& pos, const T& radius) : pos(pos), radius(radius) {}
public:
    inline constexpr bool Overlaps(const Vector<T, N>& p) const
    {
        return (p - pos).Mag() <= radius;
    }
    inline bool Overlaps(const BoundingBox<T, N>& box) const
    {
        return GetClosestDistanceToPolygon(box.GetVertices(), pos) <= radius;
    }
    inline constexpr bool Overlaps(const BoundingSphere<T, N>& sphere) const
    {
        return (pos - sphere.pos).Mag() <= (radius + sphere.radius);
    }
    inline bool Overlaps(const Vector<T, N>& pos0, const Vector<T, N>& pos1, const Vector<T, N>& pos2) const
    {
        return this->Overlaps({pos0, pos1, pos2});
    }
    template <usize S>
    inline bool Overlaps(const std::array<Vector<T, N>, S>& vertices) const
    {
        return GetClosestDistanceToPolygon(vertices, pos) <= radius;
    }
    inline bool Overlaps(const std::vector<Vector<T, N>>& vertices) const
    {
        return GetClosestDistanceToPolygon(vertices, pos) <= radius;
    }
};

enum class Intersection : u8
{
    Intersects = 1,
    Back = 2,
    Front = 3
};

template <typename T>
class Plane
{
public:
    Vector<T, 3> normal;
    T distance;
public:
    inline constexpr Plane() = default;
    inline constexpr Plane& operator=(Plane&& plane) = default;
    inline constexpr Plane& operator=(const Plane& plane) = default;
    inline constexpr Plane(const Plane& plane) = default;
    inline constexpr Plane(Plane&& plane) = default;
    inline constexpr Plane(const Vector<T, 3>& normal, const T& distance) : normal(normal), distance(distance) {}
    inline constexpr Plane(const Vector<T, 3>& pos, const Vector<T, 3>& norm)
    : normal(norm.Norm()), distance(Dot(normal, pos)) {}
    inline constexpr Plane(const Vector<T, 4>& vec) : normal(vec.xyz), distance(vec.w) {}
public:
    inline constexpr Intersection Intersects(const BoundingBox<T, 3>& box) const
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr Intersection Intersects(const BoundingSphere<T, 3>& sphere) const
    {
        const T d = Distance(sphere.pos);
        if(Abs(d) <= sphere.radius)
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
        t = (-distance - Dot(start, normal)) / (Dot(diff, normal));
        return start + diff * t;
    }
    inline constexpr Intersection Intersects(const Plane<T>& plane)
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr T Distance(const Vector<T, 3>& point) const
    {
        return Dot(normal, point) + distance;
    }
    inline constexpr Plane<T> Norm() const
    {
        const T mag = normal.Mag();
        return {(mag == T(0) || mag == T(1)) ? *this : Plane<T>{normal / mag, distance / mag}};
    }
public:
    inline friend constexpr Plane<T> operator*=(Plane<T>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        lhs = lhs * rhs;
        return lhs;
    }
    inline friend constexpr Plane<T> operator*(const Plane<T>& lhs, const Matrix<T, 4, 4>& rhs)
    {
        const Vector<T, 4> p = rhs * vec4{lhs.normal * lhs.distance, T(1)};
        const Vector<T, 4> n = rhs.Inverse().Transpose() * vec4{lhs.normal, T(0)};
        return Plane<T>{n.xyz, Dot(Vector<T, 3>{p.xyz}, Vector<T, 3>{n.xyz})};
    }
};

template <typename T>
inline constexpr Vector<T, 3> GetPlaneIntersectionPoint(const Plane<T>& p0, const Plane<T>& p1, const Plane<T>& p2)
{
    const T d = Matrix<T, 3, 3>{p0.normal, p1.normal, p2.normal}.Determinant();
    if(AlmostEqual(d, T(0))) return Vector<T, 3>::Zero();
    const T d0 = p0.normal.Mag2() * p0.distance;
    const T d1 = p1.normal.Mag2() * p1.distance;
    const T d2 = p2.normal.Mag2() * p2.distance;
    const Vector<T, 3> c0 = Cross(p2.normal, p1.normal);
    const Vector<T, 3> c1 = Cross(p0.normal, p2.normal);
    const Vector<T, 3> c2 = Cross(p1.normal, p0.normal);
    return (d0 * c0 + d1 * c1 + d2 * c2) / d;
}

template <typename T>
class Frustum
{
public:
    Plane<T> far, near, top, bottom, right, left;
private:
    Matrix<T, 4, 4> m_matInternal = Matrix<T, 4, 4>::Identity();
public:
    inline constexpr Frustum() = default;
    inline constexpr Frustum& operator=(Frustum&& frustum) = default;
    inline constexpr Frustum& operator=(const Frustum& frustum) = default;
    inline constexpr Frustum(const Frustum& frustum) = default;
    inline constexpr Frustum(Frustum&& frustum) = default;
public:
    inline constexpr void SetInternalMatrix(const Matrix<T, 4, 4>& lhs)
    {
        left = Plane<T>{lhs.GetRow(3) + lhs.GetRow(0)}.Norm();
        right = Plane<T>{lhs.GetRow(3) - lhs.GetRow(0)}.Norm();
        bottom = Plane<T>{lhs.GetRow(3) + lhs.GetRow(1)}.Norm();
        top = Plane<T>{lhs.GetRow(3) - lhs.GetRow(1)}.Norm();
        near = Plane<T>{lhs.GetRow(3) + lhs.GetRow(2)}.Norm();
        far = Plane<T>{lhs.GetRow(3) - lhs.GetRow(2)}.Norm();
        this->m_matInternal = lhs;
    }
    inline constexpr const Matrix<T, 4, 4>& GetMatrix() const
    {
        return m_matInternal;
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
    inline constexpr bool Overlaps(const BoundingBox<T, 2>& box)
    {
        //TODO
        return false;
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
            GetPlaneIntersectionPoint(far, right, top),
            GetPlaneIntersectionPoint(far, right, bottom),
            GetPlaneIntersectionPoint(far, left, bottom),
            GetPlaneIntersectionPoint(far, left, top),
            GetPlaneIntersectionPoint(near, left, top),
            GetPlaneIntersectionPoint(near, left, bottom),
            GetPlaneIntersectionPoint(near, right, bottom),
            GetPlaneIntersectionPoint(near, right, top)
        };
    }
};

template <typename T>
class Transform
{
private:
    Matrix<T, 3, 3> m_matTransform;
    Matrix<T, 3, 3> m_matInverted;
    bool m_invertMatrix;
public:
    inline constexpr Transform& operator=(const Transform& lhs) = default;
    inline constexpr Transform& operator=(Transform&& lhs) = default;
    inline constexpr Transform(const Transform& lhs) = default;
    inline constexpr Transform(Transform&& lhs) = default;
    inline constexpr Transform()
    {
        this->Reset();
    }
public:
    inline constexpr void Rotate(const T& ang)
    {
        m_matTransform *= GetRotationMatrix<T>(ang);
        m_invertMatrix = true;
    }
    inline constexpr void Scale(const T& w, const T& h)
    {
        m_matTransform *= GetScalingMatrix<T>(w, h);
        m_invertMatrix = true;
    }
    inline constexpr void Scale(const Vector<T, 2>& scale)
    {
        Scale(scale.w, scale.h);
    }
    inline constexpr void Translate(const T& x, const T& y)
    {
        m_matTransform *= GetTranslationMatrix<T>(x, y);
        m_invertMatrix = true;
    }
    inline constexpr void Translate(const Vector<T, 2>& offset)
    {
        Translate(offset.x, offset.y);
    }
    inline constexpr void Shear(const T& x, const T& y)
    {
        m_matTransform *= GetShearMatrix<T>(x, y);
        m_invertMatrix = true;
    }
    inline constexpr void Shear(const Vector<T, 2>& shear)
    {
        Shear(shear.x, shear.y);
    }
    inline constexpr const Vector<T, 2> GetTranslation() const
    {
        return GetTranslationFromMatrix(m_matTransform);
    }
    inline constexpr const Vector<T, 2> GetScale() const
    {
        return GetScaleFromMatrix(m_matTransform);
    }
    inline constexpr const T GetRotation() const
    {
        return GetRotationFromMatrix(m_matTransform);
    }
    inline constexpr Vector<T, 2> Forward(const Vector<T, 2>& p) const
    {
        return Forward(p.x, p.y);
    }
    inline constexpr Vector<T, 2> Forward(const T& x, const T& y) const
    {
        const Vector<T, 3> vec = m_matTransform * Vector<T, 3>{x, y, T(1)};
        return vec.xy / (vec.z == T(0) ? T(1) : vec.z);
    }
    inline constexpr Vector<T, 2> Backward(const Vector<T, 2>& p) const
    {
        return Backward(p.x, p.y);
    }
    inline constexpr Vector<T, 2> Backward(const T& x, const T& y) const
    {
        const Vector<T, 3> vec = m_matInverted * Vector<T, 3>{x, y, T(1)};
        return vec.xy / (vec.z == T(0) ? T(1) : vec.z);
    }
    inline constexpr void Reset()
    {
        m_matTransform = Matrix<T, 3, 3>::Identity();
        m_matInverted = Matrix<T, 3, 3>::Identity();
        m_invertMatrix = false;
    }
    inline constexpr void Invert()
    {
        if(m_invertMatrix)
        {
            m_matInverted = m_matTransform.Inverse();
            m_invertMatrix = false;
        }
    }
public:
    virtual ~Transform() {}
};

template <typename T>
class Transform3D
{
public:
    Vector<T, 3> position;
    Quaternion<T> rotation;
    Vector<T, 3> scale;
public:
    inline constexpr Transform3D& operator=(Transform3D&& lhs) = default;
    inline constexpr Transform3D& operator=(const Transform3D& lhs) = default;
    inline constexpr Transform3D(const Transform3D& lhs) = default;
    inline constexpr Transform3D(Transform3D&& lhs) = default;
    inline constexpr Transform3D() : position(Vector<T, 3>::Zero()), rotation(Quaternion<T>::Identity()), scale(Vector<T, 3>::One()) {}
    inline constexpr Transform3D(const Vector<T, 3>& position, const Quaternion<T>& rotation, const Vector<T, 3>& scale)
    : position(position), rotation(rotation), scale(scale) {}
public:
    inline constexpr Matrix<T, 4, 4> GetWorldMatrix() const
    {
        return GetTranslationMatrix<T>(position) * 
            GetMatrixFromQuaternion<T>(rotation) * 
            GetScalingMatrix<T>(scale);
    }
    inline constexpr void Reset()
    {
        scale = Vector<T, 3>::One();
        position = Vector<T, 3>::Zero();
        rotation = Quaternion<T>::Identity();
    }
public:
    virtual ~Transform3D() {}
};

template <typename T>
inline constexpr Transform3D<T> Lerp(const Transform3D<T>& lhs, const Transform3D<T>& rhs, const f64 t)
{
    return Transform3D<T>
    {
        Lerp(lhs.position, rhs.position, t),
        Slerp(lhs.rotation, rhs.rotation, t),
        Lerp(lhs.scale, rhs.scale, t)
    };
}

template <typename T>
inline constexpr BoundingBox<T, 3> BoundingBoxFromTransform(const Transform3D<T>& transform)
{
    return BoundingBox<T, 3>
    {
        transform.position,
        transform.scale,
        QuaternionToEulerAngles(transform.rotation)    
    };
}

template <typename T>
inline constexpr BoundingSphere<T, 3> BoundingSphereFromTransform(const Transform3D<T>& transform)
{
    return BoundingSphere<T, 3>
    {
        transform.position,
        Max(transform.scale)
    };
}

template <typename T>
inline constexpr Transform3D<T> TransformFromBoundingBox(const BoundingBox<T, 3>& box)
{
    return Transform3D<T>
    {
        box.pos,
        GetQuaternionFromEulerAngles(box.rotation),
        box.size
    };
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class Rect
{
public:
    Vector<T, 2> pos;
    Vector<T, 2> size;
public:
    inline constexpr Rect() : pos(Vector<T, 2>::Zero()), size(Vector<T, 2>::Zero()) {}
    inline constexpr Rect(const Vector<T, 2>& pos, const Vector<T, 2>& size) : pos(pos), size(size) {}
    template <typename A, typename B>
    inline constexpr Rect(const Vector<A, 2>& pos, const Vector<B, 2>& size)
    : pos(static_cast<Vector<T, 2>>(pos)), size(static_cast<Vector<T, 2>>(size)) {}
    inline constexpr Rect& operator=(const Rect& lhs) = default;
    inline constexpr Rect& operator=(Rect&& lhs) = default;
    inline constexpr Rect(const Rect& lhs) = default;
    inline constexpr Rect(Rect&& lhs) = default;
public:
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
    inline constexpr T Left() const
    {
        return pos.x;
    }
    inline constexpr T Top() const
    {
        return pos.y;
    }
    inline constexpr T Right() const
    {
        return pos.x + size.x;
    }
    inline constexpr T Bottom() const
    {
        return pos.y + size.y;
    }
    inline constexpr Vector<T, 2> TopRight() const
    {
        return {Right(), Top()};
    }
    inline constexpr Vector<T, 2> BottomRight() const
    {
        return {Right(), Bottom()};
    }
    inline constexpr Vector<T, 2> TopLeft() const
    {
        return {Left(), Top()};
    }
    inline constexpr Vector<T, 2> BottomLeft() const
    {
        return {Left(), Bottom()};
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
    inline Vector<T, 2> GetRandomPointInside() const
    {
        return pos + Random::Next(Vector<T, 2>::Zero(), size);
    }
    inline constexpr Rect<T> Transform(const Transform<T>& transform) const
    {
        Vector<T, 2> start, end, p;
        p = start = transform.Forward(TopLeft());
        start = Min(p, start); end = Max(p, end);
        p = transform.Forward(BottomRight());
        start = Min(p, start); end = Max(p, end);
        p = transform.Forward(BottomLeft());
        start = Min(p, start); end = Max(p, end);
        p = transform.Forward(TopRight());
        start = Min(p, start); end = Max(p, end);
        if(end.x < start.x) std::swap(end.x, start.x);
        if(end.y < start.y) std::swap(end.y, start.y);
        return Rect<T>{start, end - start};
    }
};

#endif