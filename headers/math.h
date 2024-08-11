#ifndef MATH_H
#define MATH_H

#include "includes.h"

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

constexpr double pi = 3.141519265358979323846;
constexpr double half_pi = 1.57079632679489661923;
constexpr double two_pi = 6.283038530717958813909;
constexpr double golden_ratio = 1.618033988749;
constexpr double one_over_pi = 0.3183173221399075436544;
constexpr double epsilon = 0.1;

inline constexpr double deg2rad(const double angle)
{
    return (angle / 180.0) * pi;
}

inline constexpr double rad2deg(const double angle)
{
    return (angle / pi) * 180.0;
}

template <typename T, typename... V>
struct all_convertible : std::integral_constant
    <bool, (std::is_convertible<V, T>::value && ...)> 
    {};

template <typename T, size_t N, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type> 
struct Vector
{
    T data[N] = {T(0)};
    inline constexpr Vector& operator=(const Vector& lhs) = default;
    inline constexpr Vector(const Vector& lhs) = default;
    inline constexpr Vector(Vector&& lhs) = default;
    inline constexpr Vector(const T& lhs = T(0))
    {
        for(size_t i = 0; i < N; i++)
            data[i] = lhs;
    }
    inline constexpr Vector(const T(&lhs)[N])
    {
        for(size_t i = 0; i < N; i++)
            data[i] = lhs[i];
    }
    template <typename... V, typename = typename std::enable_if<all_convertible<T, V...>::value && sizeof...(V) + 1 == N>::type> 
    inline constexpr Vector(const T& lhs, const V&... args) : data{lhs, args...}
    {
        return;
    }
    template <size_t M, typename... V, typename = typename std::enable_if<all_convertible<T, V...>::value && sizeof...(V) + M == N>::type>
    inline constexpr Vector(const Vector<T, M>& lhs, const V&... args)
    {
        const T arr[] = {args...};
        for(size_t i = 0; i < N; i++)
            data[i] = i < M ? lhs[i] : arr[i - M];
    }
    inline constexpr T mag2() const
    {
        T res = T(0);
        for(size_t i = 0; i < N; i++)
            res += data[i] * data[i];
        return res;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr Vector<T, N> norm() const
    {
        Vector<T, N> res;
        const T mag = this->mag();
        for(size_t i = 0; i < N; i++)
            res[i] = data[i] / mag;
        return res;
    }
    template <typename F> 
    inline constexpr operator Vector<F, N>() const
    {
        Vector<F, N> res;
        for(size_t i = 0; i < N; i++)
            res[i] = static_cast<F>(data[i]);
        return res;
    }
    inline constexpr T& operator[](const size_t& index)
    {
        if(index < N)
            return data[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr const T& operator[](const size_t& index) const
    {
        if(index < N)
            return data[index];
        else
            throw std::out_of_range("index out of range");
    }
};

template <typename T, size_t... V>
struct Swizzle
{
    T data[sizeof...(V)] = {T(0)};
    static constexpr size_t size = sizeof...(V);
    static constexpr size_t sw[] = {V...};
    inline constexpr Swizzle() = default;
    inline constexpr Swizzle(const Swizzle& lhs) = default;
    inline constexpr Swizzle(Swizzle&& lhs) = default;
    inline constexpr Swizzle& operator=(const Swizzle& lhs) = default;
    template <typename F>
    inline constexpr operator Vector<F, size>() const
    {
        Vector<F, size> res;
        for(size_t i = 0; i < size; i++)
            res[i] = static_cast<F>(data[sw[i]]);
        return res;
    }
    template <typename F, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline constexpr operator Swizzle<F, SW...>() const
    {
        Swizzle<F, SW...> res;
        for(size_t i = 0; i < size; i++)
            res[i] = static_cast<F>(data[sw[i]]);
        return res;
    }
    template <typename F, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline constexpr Swizzle<T, V...>& operator=(const Swizzle<F, SW...>& lhs)
    {
        for(size_t i = 0; i < size; i++)
            data[sw[i]] = static_cast<T>(lhs[i]);
        return *this;
    }
    template <typename F>
    inline constexpr Swizzle<T, V...>& operator=(const Vector<F, size>& lhs)
    {
        for(size_t i = 0; i < size; i++)
            data[sw[i]] = static_cast<T>(lhs[i]);
        return *this;
    }
    inline constexpr Swizzle<T, V...>& operator++()
    {
        for(size_t i = 0; i < size; i++)
            ++data[sw[i]];
        return *this; 
    }
    inline constexpr Swizzle<T, V...>& operator--()
    {
        for(size_t i = 0; i < size; i++)
            --data[sw[i]];
        return *this;
    }
    inline constexpr Swizzle<T, V...> operator++(int)
    {
        Swizzle<T, V...> res = *this;
        ++res;
        return res;
    }
    inline constexpr Swizzle<T, V...> operator--(int)
    {
        Swizzle<T, V...> res = *this;
        --res;
        return res;
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator*=(Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) * static_cast<Vector<U, sizeof...(SW)>>(rhs);
        return lhs;
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator+=(Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) + static_cast<Vector<U, sizeof...(SW)>>(rhs);
        return lhs;
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator/=(Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) / static_cast<Vector<U, sizeof...(SW)>>(rhs);
        return lhs;
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator-=(Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) - static_cast<Vector<U, sizeof...(SW)>>(rhs);
        return lhs;
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator*(const Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) * static_cast<Vector<U, sizeof...(SW)>>(rhs);
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator+(const Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) + static_cast<Vector<U, sizeof...(SW)>>(rhs);
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator/(const Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) / static_cast<Vector<U, sizeof...(SW)>>(rhs);
    }
    template <typename U, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == size>::type>
    inline friend constexpr auto operator-(const Swizzle<T, V...>& lhs, const Swizzle<U, SW...>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) - static_cast<Vector<U, sizeof...(SW)>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator*=(Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) * rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator+=(Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) + rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator/=(Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) / rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator-=(Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) - rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator*=(Swizzle<T, V...>& lhs, const U& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) * rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator+=(Swizzle<T, V...>& lhs, const U& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) + rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator/=(Swizzle<T, V...>& lhs, const U& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) / rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator-=(Swizzle<T, V...>& lhs, const U& rhs)
    {
        lhs = static_cast<Vector<T, size>>(lhs) - rhs;
        return lhs;
    }
    template <typename U>
    inline friend constexpr auto operator*(const Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) * rhs;
    }
    template <typename U>
    inline friend constexpr auto operator+(const Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) + rhs;
    }
    template <typename U>
    inline friend constexpr auto operator/(const Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) / rhs;
    }
    template <typename U>
    inline friend constexpr auto operator-(const Swizzle<T, V...>& lhs, const Vector<U, size>& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) - rhs;
    }
    template <typename U>
    inline friend constexpr auto operator*(const Vector<T, size>& lhs, const Swizzle<U, V...>& rhs)
    {
        return lhs * static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator+(const Vector<T, size>& lhs, const Swizzle<U, V...>& rhs)
    {
        return lhs + static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator/(const Vector<T, size>& lhs, const Swizzle<U, V...>& rhs)
    {
        return lhs / static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator-(const Vector<T, size>& lhs, const Swizzle<U, V...>& rhs)
    {
        return lhs - static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator*(const Swizzle<T, V...>& lhs, const U& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) * Vector<U, size>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator+(const Swizzle<T, V...>& lhs, const U& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) + Vector<U, size>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator/(const Swizzle<T, V...>& lhs, const U& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) / Vector<U, size>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator-(const Swizzle<T, V...>& lhs, const U& rhs)
    {
        return static_cast<Vector<T, size>>(lhs) - Vector<U, size>{rhs};
    }
    template <typename U>
    inline friend constexpr auto operator*(const T& lhs, const Swizzle<U, V...>& rhs)
    {
        return Vector<T, size>{lhs} * static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator+(const T& lhs, const Swizzle<U, V...>& rhs)
    {
        return Vector<T, size>{lhs} + static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator/(const T& lhs, const Swizzle<U, V...>& rhs)
    {
        return Vector<T, size>{lhs} / static_cast<Vector<U, size>>(rhs);
    }
    template <typename U>
    inline friend constexpr auto operator-(const T& lhs, const Swizzle<U, V...>& rhs)
    {
        return Vector<T, size>{lhs} - static_cast<Vector<U, size>>(rhs);
    }
    inline friend constexpr std::ostream& operator<<(std::ostream& os, const Swizzle<T, V...>& rhs)
    {
        os << static_cast<Vector<T, size>>(rhs);
        return os;
    }
    inline constexpr const T& operator[](const size_t& index) const
    {
        if(index < size)
            return data[sw[index]];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr T& operator[](const size_t& index)
    {
        if(index < size)
            return data[sw[index]];
        else
            throw std::out_of_range("index out of range");
    }
};

template <typename T> 
struct Vector<T, 2>
{
    union
    {
        T data[2];
        struct { T x, y; };
        struct { T u, v; };
        struct { T s, t; };
        struct { T w, h; };
        swizzle2(x, y);
        swizzle2(u, v);
        swizzle2(s, t);
    };
    inline constexpr Vector(const T& lhs = T(0)) : x(lhs), y(lhs) {}
    inline constexpr Vector(const T& x, const T& y) : x(x), y(y) {}
    template <typename F, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == 2>::type>
    inline constexpr operator Swizzle<F, SW...>() const
    {
        Swizzle<F, SW...> res;
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
        return {x / mag, y / mag};
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
    inline constexpr T& operator[](const size_t& index)
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline constexpr const T& operator[](const size_t& index) const
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
        T data[3];
        struct { T x, y, z; };
        struct { T r, g, b; };
        struct { T h, s, v; };
        struct 
        { 
            T roll;
            T pitch;
            T yaw; 
        };
        swizzle2(x, y);
        swizzle3(x, y, z);
        swizzle3(r, g, b);
        swizzle3(h, s, v);
    };
    inline constexpr Vector(const T& lhs = T(0)) : x(lhs), y(lhs), z(lhs) {}
    inline constexpr Vector(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
    inline constexpr Vector(const Vector<T, 2>& v, const T& z = T(0)) : x(v.x), y(v.y), z(z) {}
    template <typename F, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == 3>::type>
    inline constexpr operator Swizzle<F, SW...>() const
    {
        Swizzle<F, SW...> res;
        res[0] = static_cast<F>(x);
        res[1] = static_cast<F>(y);
        res[2] = static_cast<F>(z);
        return res;
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
        return {x / mag, y / mag, z / mag};
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
    inline constexpr T& operator[](const size_t& index)
    {
        switch(index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw std::out_of_range("index out of range");
        }
    }
    inline constexpr const T& operator[](const size_t& index) const
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
        T data[4];
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        swizzle2(x, y);
        swizzle3(x, y, z);
        swizzle3(r, g, b);
        swizzle4(x, y, z, w);
        swizzle4(r, g, b, a);
    };
    inline constexpr Vector(const T& lhs = T(0)) : x(lhs), y(lhs), z(lhs), w(lhs) {}
    inline constexpr Vector(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
    inline constexpr Vector(const Vector<T, 2>& v, const T& z = T(0), const T& w = T(0)) : x(v.x), y(v.y), z(z), w(w) {}
    inline constexpr Vector(const Vector<T, 3>& v, const T& w = T(0)) : x(v.x), y(v.y), z(v.z), w(w) {}
    template <typename F, size_t... SW, typename = typename std::enable_if<sizeof...(SW) == 4>::type>
    inline constexpr operator Swizzle<F, SW...>() const
    {
        Swizzle<F, SW...> res;
        res[0] = static_cast<F>(x);
        res[1] = static_cast<F>(y);
        res[2] = static_cast<F>(z);
        res[3] = static_cast<F>(w);
        return res;
    }
    inline constexpr T mag2() const
    {
        return x * x + y * y +  z * z + w * w;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr Vector<T, 4> norm() const
    {
        const T mag = this->mag();
        return {x / mag, y / mag, z / mag, w / mag};
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
    inline constexpr T& operator[](const size_t& index)
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
    inline constexpr const T& operator[](const size_t& index) const
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

template <typename T, typename U, size_t N> 
inline constexpr auto operator*(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    Vector<decltype(lhs[0] * rhs[0]), N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = lhs[i] * rhs[i];
    return res;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator/(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    Vector<decltype(lhs[0] / rhs[0]), N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = lhs[i] / rhs[i];
    return res;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator+(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    Vector<decltype(lhs[0] + rhs[0]), N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = lhs[i] + rhs[i];
    return res;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator-(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    Vector<decltype(lhs[0] - rhs[0]), N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = lhs[i] - rhs[i];
    return res;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator-(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} - rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator+(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} + rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator*(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} * rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator/(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} / rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator*(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs * Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator/(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs / Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator+(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs + Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator-(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs - Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator*=(Vector<T, N>& lhs, const U& rhs) 
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator/=(Vector<T, N>& lhs, const U& rhs) 
{
    lhs = lhs / rhs;
    return lhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator+=(Vector<T, N>& lhs, const U& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator-=(Vector<T, N>& lhs, const U& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator+=(Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

template <typename T, typename U, size_t N>
inline constexpr auto operator-=(Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator*=(Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T, typename U, size_t N> 
inline constexpr auto operator/=(Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

template <typename T, size_t N>
inline constexpr Vector<T, N>& operator++(Vector<T, N>& lhs)
{
    for(size_t i = 0; i < N; i++)
        ++lhs[i];
    return lhs;
}

template <typename T, size_t N>
inline constexpr Vector<T, N>& operator--(Vector<T, N>& lhs)
{
    for(size_t i = 0; i < N; i++)
        --lhs[i];
    return lhs;
}

template <typename T, size_t N>
inline constexpr Vector<T, N> operator++(const Vector<T, N>& lhs, int)
{
    Vector<T, N> res = lhs;
    ++res;
    return res;
}

template <typename T, size_t N>
inline constexpr Vector<T, N> operator--(const Vector<T, N>& lhs, int)
{
    Vector<T, N> res = lhs;
    --res;
    return res;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator==(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(size_t i = 0; i < N; i++)
        if(lhs[i] != rhs[i])
            return false;
    return true;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator==(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs == Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator<(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(size_t i = 0; i < N; i++)
        if(lhs[i] >= rhs[i])
            return false;
    return true;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator>(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(size_t i = 0; i < N; i++)
        if(lhs[i] <= rhs[i])
            return false;
    return true;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator<(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs < Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator>(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs > Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator<(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} < rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator>(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} > rhs;
}

template <typename T, typename U, size_t N>
inline constexpr bool operator>=(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(size_t i = 0; i < N; i++)
        if(lhs[i] < rhs[i])
            return false;
    return true;
}

template <typename T, typename U, size_t N>
inline constexpr bool operator<=(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    for(size_t i = 0; i < N; i++)
        if(lhs[i] > rhs[i])
            return false;
    return true;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator<=(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs <= Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator>=(const Vector<T, N>& lhs, const U& rhs)
{
    return lhs >= Vector<U, N>{rhs};
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator<=(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} <= rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator>=(const T& lhs, const Vector<U, N>& rhs)
{
    return Vector<T, N>{lhs} >= rhs;
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator!=(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    return !(lhs == rhs);
}

template <typename T, typename U, size_t N> 
inline constexpr bool operator!=(const Vector<T, N>& lhs, const U& rhs)
{
    return !(lhs == rhs);
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> operator-(const Vector<T, N>& lhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = -lhs[i];
    return res;
}

template <typename T, size_t N> 
inline constexpr std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vec)
{
    os << '{';
    for(size_t i = 0; i < N; i++)
        os << vec[i] << (i != N - 1 ? ',' : '}');
    return os;
}

template <typename T, typename U, size_t N> 
inline constexpr auto dot(const Vector<T, N>& lhs, const Vector<U, N>& rhs)
{
    decltype(lhs[0] * rhs[0]) res = 0;
    for(size_t i = 0; i < N; i++)
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

template <typename T, size_t N> 
inline constexpr Vector<T, N> max(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = std::max(lhs[i], rhs[i]);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> min(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = std::min(lhs[i], rhs[i]);
    return res;
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

template <typename T, size_t N>
inline constexpr Vector<T, N> smoothstep(const Vector<T, N>& lhs, const Vector<T, N>& rhs, T x)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = smoothstep(lhs[i], rhs[i], x);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> lerp(const Vector<T, N>& lhs, const Vector<T, N>& rhs, const double t)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = lerp(lhs[i], rhs[i], t);
    return res;
}

template <typename T, size_t N>
inline constexpr Vector<T, N> reflect(const Vector<T, N>& vec, const Vector<T, N>& norm)
{
    return vec - T(2) * dot(vec, norm) * norm;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> clamp(const Vector<T, N>& lhs, const Vector<T, N>& min, const Vector<T, N>& max)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = std::clamp(lhs[i], min[i], max[i]);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> abs(const Vector<T, N>& lhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = std::abs(lhs[i]);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> floor(const Vector<T, N>& lhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = std::floor(lhs[i]);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> ceil(const Vector<T, N>& lhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = std::ceil(lhs[i]);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> inv(const Vector<T, N>& lhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = T(1) / lhs[i];
    return res;
}

template <typename T, size_t N> 
inline constexpr T min(const Vector<T, N>& lhs)
{
    T res = lhs[0];
    for(size_t i = 1; i < N; i++)
        res = std::min(lhs[i], res);
    return res;
}

template <typename T, size_t N> 
inline constexpr T max(const Vector<T, N>& lhs)
{
    T res = lhs[0];
    for(size_t i = 1; i < N; i++)
        res = std::max(lhs[i], res);
    return res;
}

template <typename T>
inline constexpr T mod(const T& lhs, const T& rhs, typename std::enable_if<std::is_floating_point<T>::value>::type* = 0)
{
    return fmod(lhs, rhs);
}

template <typename T>
inline constexpr T mod(const T& lhs, const T& rhs, typename std::enable_if<std::is_integral<T>::value>::type* = 0)
{
    return lhs % rhs;
}

template <typename T, size_t N>
inline constexpr Vector<T, N> mod(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = mod(lhs[i], rhs[i]);
    return res;
}

template <typename T, size_t N>
inline constexpr Vector<T, N> mod(const Vector<T, N>& lhs, const T& rhs)
{
    return mod(lhs, Vector<T, N>{rhs});
}

template <typename T, size_t N>
inline constexpr Vector<T, N> mod(const T& lhs, const Vector<T, N>& rhs)
{
    return mod(Vector<T, N>{lhs}, rhs);
}

template <typename T, size_t N, size_t... V> 
inline constexpr Vector<T, sizeof...(V)> swizzle(const Vector<T, N>& lhs)
{
    const size_t size = sizeof...(V);
    const size_t sw[] = {V...};
    Vector<T, size> res;
    for(size_t i = 0; i < size; i++)
        res[i] = lhs[sw[i]];
    return res;
}

template <typename T, size_t N>
inline constexpr const uint32_t hash(const T(&lhs)[N])
{
   uint32_t res = 1315423911;
   for(size_t i = 0; i < N; i++)
       res ^= ((res << 5) + lhs[i] + (res >> 2));
   return (res & 0x7FFFFFFF);
}

template <typename T, size_t N>
inline constexpr const uint32_t hash(const Vector<T, N>& lhs)
{
    return hash(lhs.data);
}

template <typename T, size_t N>
inline constexpr bool any_equal_to(const Vector<T, N>& lhs, const T& rhs)
{
    for(size_t i = 0; i < N; i++)
        if(lhs[i] == rhs)
            return true;
    return false;
}

template <typename T, size_t N>
inline constexpr bool any_greater(const Vector<T, N>& lhs, const T& rhs)
{
    return !(lhs <= rhs);
}

template <typename T, size_t N>
inline constexpr bool any_less(const Vector<T, N>& lhs, const T& rhs)
{
    return !(lhs >= rhs);
}

typedef Vector<bool, 2> vec2b;
typedef Vector<float, 2> vec2f;
typedef Vector<double, 2> vec2d;
typedef Vector<int32_t, 2> vec2i;
typedef Vector<uint8_t, 2> vec2ub;
typedef Vector<uint16_t, 2> vec2us;
typedef Vector<uint32_t, 2> vec2u;

typedef Vector<bool, 3> vec3b;
typedef Vector<float, 3> vec3f;
typedef Vector<double, 3> vec3d;
typedef Vector<int32_t, 3> vec3i;
typedef Vector<uint8_t, 3> vec3ub;
typedef Vector<uint16_t, 3> vec3us;
typedef Vector<uint32_t, 3> vec3u;

typedef Vector<bool, 4> vec4b;
typedef Vector<float, 4> vec4f;
typedef Vector<double, 4> vec4d;
typedef Vector<int32_t, 4> vec4i;
typedef Vector<uint8_t, 4> vec4ub;
typedef Vector<uint16_t, 4> vec4us;
typedef Vector<uint32_t, 4> vec4u;

template <typename T, size_t R, size_t C, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type> 
struct Matrix
{
    union
    {
        T mat[C][R];
        T data[R * C];
    };
    inline constexpr Matrix& operator=(const Matrix& lhs) = default;
    inline constexpr Matrix(const Matrix& lhs) = default;
    inline constexpr Matrix(Matrix&& lhs) = default;
    template <size_t N = R, size_t M = C, typename = typename std::enable_if<N == M>::type>
    static inline constexpr Matrix<T, R, C> identity()
    {
        Matrix<T, R, C> res = T(0);
        for(size_t i = 0; i < R; i++)
            res.mat[i][i] = T(1);
        return res;
    }
    static inline constexpr Matrix<T, R, C> zero()
    {
        return T(0);
    }
    inline constexpr Matrix(const T& lhs = T(0))
    {
        for(size_t i = 0; i < R * C; i++)
            data[i] = lhs;
    }
    inline constexpr Matrix(const T(&lhs)[R * C])
    {
        for(size_t i = 0; i < R * C; i++)
            data[i] = lhs[i];
    }
    template <typename... V, typename = typename std::enable_if<all_convertible<T, V...>::value && sizeof...(V) + 1 == R * C>::type> 
    inline constexpr Matrix(const T& lhs, const V&... args) : data{lhs, args...}
    {
        return;
    }
    template <size_t N, size_t M>
    inline constexpr Matrix(const Matrix<T, N, M>& lhs)
    {
        for(size_t i = 0; i < R; i++)
            for(size_t j = 0; j < C; j++)
                mat[j][i] = (i < N && j < M) ? lhs.mat[j][i] : (i == j && R == C ? T(1) : T(0));
    }
    inline constexpr Vector<T, C> row(const size_t& lhs) const
    {
        Vector<T, C> res;
        for(size_t i = 0; i < C; i++) 
            res[i] = mat[i][lhs];
        return res;
    }
    inline constexpr Vector<T, R> col(const size_t& lhs) const
    {
        Vector<T, R> res; 
        for(size_t i = 0; i < R; i++) 
            res[i] = mat[lhs][i]; 
        return res;
    }
    inline constexpr void set_row(const size_t& lhs, const Vector<T, C>& rhs) 
    {
        for(size_t i = 0; i < C; i++) 
            mat[i][lhs] = rhs[i];
    }
    inline constexpr void set_col(const size_t& lhs, const Vector<T, R>& rhs)
    {
        for(size_t i = 0; i < R; i++)
            mat[lhs][i] = rhs[i];
    }
    template <typename U>
    inline friend constexpr bool operator==(const Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)
    {
        for(size_t i = 0; i < R * C; i++)
            if(lhs.data[i] != rhs.data[i])
                return false;
        return true;
    }
    template <typename U>
    inline friend constexpr bool operator!=(const Matrix<T, R, C>& lhs, const Matrix<U, R, C>& rhs)
    {
        return !(lhs == rhs);
    }
    inline constexpr Matrix<T, C, R> transpose() const
    {
        Matrix<T, C, R> res;
        for(size_t i = 0; i < C; i++)
            res.set_row(i, col(i));
        return res;
    }
    template <size_t N = R, size_t M = C, typename = typename std::enable_if<N == M>::type>
    inline constexpr Matrix<T, R, C> inverse() const
    {
        Matrix<T, R, C> temp = *this;
        Matrix<T, R, C> res = Matrix<T, R, C>::identity();
        for(size_t i = 0; i < R; i++)
        {
            const T div = temp.mat[i][i];
            res.set_col(i, res.col(i) / div);
            temp.set_row(i, temp.row(i) / div);
            for(size_t j = 0; j < R; j++)
            {
                if(i != j)
                {
                    const T mul = temp.mat[i][j];
                    res.set_col(j, res.col(j) - (res.col(i) * mul));
                    temp.set_row(j, temp.row(j) - (temp.row(i) * mul));
                }
            }
        }
        return res.transpose();
    }
    template <size_t N = R, size_t M = C, typename = typename std::enable_if<N == M>::type>
    inline constexpr Matrix<T, R, C> pow(const size_t& lhs) const
    {
        if(lhs == 0)
        {
            return Matrix<T, R, C>::identity();
        }
        else if(lhs == 1)
        {
            return *this;
        }
        else 
        {
            Matrix<T, R, C> res = *this;
            for(size_t j = 1; j < lhs; j++)
                res = res * (*this);
            return res;
        }
    }
    template <size_t N = R, size_t M = C, typename = typename std::enable_if<N == M>::type>
    inline constexpr T determinant() const
    {
        T res = T(1);
        Matrix<T, R, C> temp = *this;
        for(size_t i = 0; i < R; i++)
        {
            const T div = temp.mat[i][i];
            for(size_t j = i + 1; j < R; j++)
            {
                const T mul = temp.mat[i][j];
                temp.set_row(j, temp.row(j) - (temp.row(i) / div * mul));
            }
        }
        for(size_t i = 0; i < R; i++)
        {
            res *= temp.mat[i][i];
        }
        return res;
    }
    template <size_t N, typename U>
    inline friend constexpr auto operator*(const Matrix<T, R, C>& lhs, const Matrix<U, C, N>& rhs)
    {
        Matrix<decltype(lhs.data[0] * rhs.data[0]), R, N> res;
        for(size_t i = 0; i < N; i++)
            for(size_t j = 0; j < R; j++)
                res.mat[i][j] = dot(lhs.row(j), rhs.col(i));
        return res;
    }
    template <typename U>
    inline friend constexpr auto operator*(const Matrix<T, R, C>& lhs, const Vector<U, C>& rhs)
    {
        Vector<decltype(lhs.data[0] * rhs[0]), R> res;
        for(size_t i = 0; i < R; i++)
            res[i] = dot(lhs.row(i), rhs);
        return res;
    }
    template <typename U>
    inline friend constexpr auto operator*(const Vector<T, R>& lhs, const Matrix<U, R, C>& rhs)
    {
        Vector<decltype(lhs[0] * rhs.data[0]), C> res;
        for(size_t i = 0; i < C; i++)
            res[i] = dot(lhs, rhs.col(i));
        return res;
    }
    template <typename F> 
    inline constexpr operator Matrix<F, R, C>()
    {
        Matrix<F, R, C> res;
        for(size_t i = 0; i < R * C; i++)
            res.data[i] = static_cast<F>(data[i]);
        return res;
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Matrix<T, R, C>& mat)
    {
        for(size_t i = 0; i < R; i++)
            os << mat.row(i);
        return os;
    }
};

template <typename T> 
inline constexpr Matrix<T, 4, 4> make_perspective_mat(const T& aspect, const T& fov, const T& near, const T& far)
{
    const T half_fov = std::tan(deg2rad(fov) / T(2));
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::zero();
    res.mat[0][0] = T(1) / (aspect * half_fov);
    res.mat[1][1] = T(1) / (half_fov);
    res.mat[2][2] = (near + far) / (near - far);
    res.mat[2][3] = T(-1);
    res.mat[3][2] = (T(2) * far * near) / (near - far);
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> make_ortho_mat(const T& right, const T& left, const T& bottom, const T& top, const T& near, const T& far)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = T(2) / (right - left);
    res.mat[1][1] = T(2) / (top - bottom);
    res.mat[2][2] = T(2) / (near - far);
    res.mat[3][0] = (right + left) / (left - right);
    res.mat[3][1] = (top + bottom) / (bottom - top);
    res.mat[3][2] = (far + near) / (near - far);
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> mat_look_at(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
{
    Vector<T, 3> en = (center - eye).norm();
    Vector<T, 3> cn = up.norm();
    Vector<T, 3> un = cross(en, cn).norm();
    cn = cross(un, en);
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = un.x;
    res.mat[1][0] = un.y;
    res.mat[2][0] = un.z;
    res.mat[0][1] = cn.x;
    res.mat[1][1] = cn.y;
    res.mat[2][1] = cn.z;
    res.mat[0][2] = -en.x;
    res.mat[1][2] = -en.y;
    res.mat[2][2] = -en.z;
    res.mat[3][0] = -dot(un, eye);
    res.mat[3][1] = -dot(cn, eye);
    res.mat[3][2] = dot(en, eye);
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> rotation_mat_3d(const T& angle, const Vector<T, 3>& axis)
{
    const T c = std::cos(angle);
    const T s = std::sin(angle);
    const Vector<T, 3> norm = axis.norm();
    const Vector<T, 3> vec = norm * (1 - c);
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = c + vec.x * norm.x;
    res.mat[0][1] = vec.x * norm.y + s * norm.z;
    res.mat[0][2] = vec.x * norm.z - s * norm.y;
    res.mat[1][0] = vec.y * norm.x - s * norm.z;
    res.mat[1][1] = c + vec.y * norm.y;
    res.mat[1][2] = vec.y * norm.z + s * norm.x;
    res.mat[2][0] = vec.z * norm.x + s * norm.y;
    res.mat[2][1] = vec.z * norm.y - s * norm.x;
    res.mat[2][2] = c + vec.z * norm.z;
    return res;
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_x(const T& angle)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[1][1] = std::cos(angle);
    res.mat[2][2] = std::cos(angle);
    res.mat[1][2] = std::sin(angle);
    res.mat[2][1] = -std::sin(angle);
    return res;
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_y(const T& angle)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = std::cos(angle);
    res.mat[2][0] = std::sin(angle);
    res.mat[0][2] = -std::sin(angle);
    res.mat[2][2] = std::cos(angle);
    return res;
}

template <typename T>
inline constexpr Matrix<T, 4, 4> rotation_mat_z(const T& angle)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = std::cos(angle);
    res.mat[1][0] = -std::sin(angle);
    res.mat[0][1] = std::sin(angle);
    res.mat[1][1] = std::cos(angle);
    return res;
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
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = cp * cy;
    res.mat[0][1] = sr * sp * cy - sy * cr;
    res.mat[0][2] = cr * sp * cy + sr * sy;
    res.mat[1][0] = cp * sy;
    res.mat[1][1] = sr * sp * sy + cr * cy;
    res.mat[1][2] = cr * sp * sy - sr * cy;
    res.mat[2][0] = -sp;
    res.mat[2][1] = sr * cp;
    res.mat[2][2] = cr * cp;
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> translation_mat_3d(const Vector<T, 3>& lhs)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[3][0] = lhs.x;
    res.mat[3][1] = lhs.y;
    res.mat[3][2] = lhs.z;
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> scale_mat_3d(const Vector<T, 3>& lhs)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    res.mat[0][0] = lhs.x;
    res.mat[1][1] = lhs.y;
    res.mat[2][2] = lhs.z;
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 3, 3> rotation_mat_2d(const T& angle)
{
    return Matrix<T, 3, 3>{rotation_mat_z(angle)};
}

template <typename T> 
inline constexpr Matrix<T, 3, 3> translation_mat_2d(const Vector<T, 2>& lhs)
{
    Matrix<T, 3, 3> res = Matrix<T, 3, 3>::identity();
    res.mat[2][0] = lhs.x;
    res.mat[2][1] = lhs.y;
    return res;
}

template <typename T> 
inline constexpr Matrix<T, 3, 3> scale_mat_2d(const Vector<T, 2>& lhs)
{
    Matrix<T, 3, 3> res = Matrix<T, 3, 3>::identity();
    res.mat[0][0] = lhs.x;
    res.mat[1][1] = lhs.y;
    return res;
}

template <typename T> 
inline constexpr Vector<T, 3> translation_from_mat_3d(const Matrix<T, 4, 4>& lhs)
{
    return {lhs.mat[3][0], lhs.mat[3][1], lhs.mat[3][2]};
}

template <typename T> 
inline constexpr Vector<T, 3> scale_from_mat_3d(const Matrix<T, 4, 4>& lhs)
{
    return 
    {
        Vector<T, 3>{lhs.mat[0][0], lhs.mat[0][1], lhs.mat[0][2]}.mag(),
        Vector<T, 3>{lhs.mat[1][0], lhs.mat[1][1], lhs.mat[1][2]}.mag(),
        Vector<T, 3>{lhs.mat[2][0], lhs.mat[2][1], lhs.mat[2][2]}.mag()
    };
}

template <typename T> 
inline constexpr Matrix<T, 4, 4> rotation_from_mat_3d(const Matrix<T, 4, 4>& lhs)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
    const Vector<T, 3> scale = scale_from_mat_3d(lhs);
    res.set_col(0, {Vector<T, 3>{lhs.mat[0][0], lhs.mat[0][1], lhs.mat[0][2]} / scale.x, T(0)});
    res.set_col(1, {Vector<T, 3>{lhs.mat[1][0], lhs.mat[1][1], lhs.mat[1][2]} / scale.y, T(0)});
    res.set_col(2, {Vector<T, 3>{lhs.mat[2][0], lhs.mat[2][1], lhs.mat[2][2]} / scale.z, T(0)});
    return res;
}

template <typename T> 
inline constexpr Vector<T, 2> translation_from_mat_2d(const Matrix<T, 3, 3>& lhs)
{
    return {lhs.mat[2][0], lhs.mat[2][1]};
}

template <typename T> 
inline constexpr Vector<T, 2> scale_from_mat_2d(const Matrix<T, 3, 3>& lhs)
{
    return 
    {
        Vector<T, 2>{lhs.mat[0][0], lhs.mat[0][1]}.mag(),
        Vector<T, 2>{lhs.mat[1][0], lhs.mat[1][1]}.mag()
    };
}

template <typename T> 
inline constexpr T rotation_from_mat_2d(const Matrix<T, 3, 3>& lhs)
{
    return std::atan2(lhs.mat[0][1], lhs.mat[0][0]);
}

template <typename T> 
inline constexpr Vector<T, 3> euler_from_mat(const Matrix<T, 4, 4>& lhs)
{
    if(std::abs(lhs.mat[0][2]) != T(1))
    {
        const T pitch = -std::asin(lhs.mat[0][2]);
        const T c = std::cos(pitch);
        return 
        {
            std::atan2(lhs.mat[1][2] / c, lhs.mat[2][2] / c),
            pitch,
            std::atan2(lhs.mat[0][1] / c, lhs.mat[0][0] / c)
        };
    }
    if(lhs.mat[0][2] == T(-1))
        return 
        {
            std::atan2(lhs.mat[1][0], lhs.mat[2][0]),
            T(half_pi),
            T(0)
        };
    else
        return 
        {
            std::atan2(-lhs.mat[1][0], -lhs.mat[2][0]),
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

template <typename T, size_t R, size_t C>
inline constexpr const uint32_t hash(const Matrix<T, R, C>& lhs)
{
    return hash(lhs.data);
}

typedef Matrix<float, 2, 2> mat2x2f;
typedef Matrix<double, 2, 2> mat2x2d;
typedef Matrix<int32_t, 2, 2> mat2x2i;
typedef Matrix<uint32_t, 2, 2> mat2x2u;
typedef Matrix<float, 3, 3> mat3x3f;
typedef Matrix<double, 3, 3> mat3x3d;
typedef Matrix<int32_t, 3, 3> mat3x3i;
typedef Matrix<uint32_t, 3, 3> mat3x3u;
typedef Matrix<float, 4, 4> mat4x4f;
typedef Matrix<double, 4, 4> mat4x4d;
typedef Matrix<int32_t, 4, 4> mat4x4i;
typedef Matrix<uint32_t, 4, 4> mat4x4u;

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type> 
struct Quaternion
{
    union
    {
        T data[4];
        struct { T w, x, y, z; };
        struct { T scalar; Vector<T, 3> vec; };
    };
    inline constexpr Quaternion& operator=(const Quaternion& lhs) = default;
    inline constexpr Quaternion(const Quaternion& lhs) = default;
    inline constexpr Quaternion(Quaternion&& lhs) = default;
    inline constexpr Quaternion()
    {
        w = T(1);
        vec = T(0);
    }
    static inline constexpr Quaternion<T> identity()
    {
        return {};
    }
    inline constexpr Quaternion(const T& lhs, const Vector<T, 3>& rhs)
    {
        w = lhs;
        vec = rhs;
    }
    inline constexpr Quaternion(const T& w, const T& x, const T& y, const T& z)
    {
        this->w = w;
        vec = {x, y, z};
    }
    template <typename U>
    inline friend constexpr bool operator==(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
    {
        return lhs.w == rhs.w && lhs.vec == rhs.vec;
    }
    template <typename U>
    inline friend constexpr bool operator!=(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
    {
        return !(lhs == rhs);
    }
    template <typename U>
    inline friend constexpr auto operator*(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
    {
        return Quaternion<decltype(lhs.w * rhs.w)>
        {
            lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
            lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
            lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w
        };
    }
    template <typename U>
    inline friend constexpr auto operator/(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
    {
        return lhs * rhs.inverse();
    }
    template <typename U>
    inline friend constexpr auto operator+(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
    {
        return Quaternion<decltype(lhs.w + rhs.w)>{lhs.w + rhs.w, lhs.vec + rhs.vec};
    }
    template <typename U>
    inline friend constexpr Quaternion<U> operator-(const Quaternion<T>& lhs, const Quaternion<U>& rhs)
    {
        return Quaternion<decltype(lhs.w - rhs.w)>{lhs.w - rhs.w, lhs.vec - rhs.vec};
    }
    template <typename U>
    inline friend constexpr auto operator/(const Quaternion<T>& lhs, const U& rhs)
    {
        return Quaternion<decltype(lhs.w / rhs)>{lhs.w / rhs, lhs.vec / rhs};
    }
    template <typename U>
    inline friend constexpr auto operator*(const Quaternion<T>& lhs, const U& rhs)
    {
        return Quaternion<decltype(lhs.w * rhs)>{lhs.w * rhs, lhs.vec * rhs};
    }
    template <typename U>
    inline friend constexpr auto operator+(const Quaternion<T>& lhs, const U& rhs)
    {
        return Quaternion<decltype(lhs.w + rhs)>{lhs.w + rhs, lhs.vec + rhs};
    }
    template <typename U>
    inline friend constexpr auto operator-(const Quaternion<T>& lhs, const U& rhs)
    {
        return Quaternion<decltype(lhs.w - rhs)>{lhs.w - rhs, lhs.vec - rhs};
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
        return {w / mag, vec / mag};
    }
    inline constexpr T& operator[](const size_t& index)
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
    inline constexpr const T& operator[](const size_t& index) const
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
    inline friend std::ostream& operator<<(std::ostream& os, const Quaternion<T>& quat)
    {
        os << '{' << quat.w << ',' << quat.vec << '}';
        return os;
    }
    template <typename F> 
    inline constexpr operator Quaternion<F>()
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
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>::identity();
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
    res.mat[0][0] = T(1) - T(2) * (sy + sz) * inv;
    res.mat[1][0] = T(2) * (xy - zw) * inv;
    res.mat[2][0] = T(2) * (xz + yw) * inv;
    res.mat[0][1] = T(2) * (xy + zw) * inv;
    res.mat[1][1] = T(1) - T(2) * (sx + sz) * inv;
    res.mat[2][1] = T(2) * (yz - xw) * inv;
    res.mat[0][2] = T(2) * (xz - yw) * inv;
    res.mat[1][2] = T(2) * (yz + xw) * inv;
    res.mat[2][2] = T(1) - T(2) * (sx + sy) * inv;
    return res;
}

template <typename T> 
inline constexpr Quaternion<T> quat_from_mat(const Matrix<T, 4, 4>& lhs)
{
    Quaternion<T> res;
    res.w = std::sqrt(std::max(T(0), T(1) + lhs.mat[0][0] + lhs.mat[1][1] + lhs.mat[2][2])) / T(2);
    res.x = std::sqrt(std::max(T(0), T(1) + lhs.mat[0][0] - lhs.mat[1][1] - lhs.mat[2][2])) / T(2);
    res.y = std::sqrt(std::max(T(0), T(1) - lhs.mat[0][0] + lhs.mat[1][1] - lhs.mat[2][2])) / T(2);
    res.z = std::sqrt(std::max(T(0), T(1) - lhs.mat[0][0] - lhs.mat[1][1] + lhs.mat[2][2])) / T(2);
    res.x = std::copysign(res.x, lhs.mat[2][1] - lhs.mat[1][2]);
    res.y = std::copysign(res.y, lhs.mat[0][2] - lhs.mat[2][0]);
    res.z = std::copysign(res.z, lhs.mat[1][0] - lhs.mat[0][1]);
    return res;
}

template <typename T> 
inline constexpr T quat_to_axis(const Quaternion<T>& lhs, Vector<T, 3>& rhs)
{
    const T div = std::sqrt(T(1) - lhs.w * lhs.w);
    rhs = lhs.vec / (div == T(0) ? Vector<T, 3>{1, 0, 0} : div);
    return T(2) * std::acos(lhs.w);
}

template <typename T> 
inline constexpr Vector<T, 3> quat_rotate(const Quaternion<T>& lhs, const Vector<T, 3>& rhs)
{
    return T(2) * dot(lhs.vec, rhs) * lhs.vec + (lhs.w * lhs.w - lhs.vec.mag2()) * rhs + T(2) * lhs.w * cross(lhs.vec, rhs);
}

template <typename T> 
inline constexpr Quaternion<T> quat_slerp(const Quaternion<T>& lhs, const Quaternion<T>& rhs, const double t)
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
    return hash(lhs.data);
}

template <typename T> 
inline T rand(const T& lhs, const T& rhs)
{
    return ((double)rand() / (double)RAND_MAX) * (rhs - lhs) + lhs;
}

template <typename T, size_t N> 
inline Vector<T, N> rand(const T& lhs, const T& rhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = rand(lhs, rhs);
    return res;
}

template <typename T, size_t N> 
inline Vector<T, N> rand(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
    Vector<T, N> res;
    for(size_t i = 0; i < N; i++)
        res[i] = rand(lhs[i], rhs[i]);
    return res;
}

template <typename T, size_t N, size_t M> 
inline Matrix<T, N, M> rand(const T& lhs, const T& rhs)
{
    Matrix<T, N, M> res;
    for(size_t i = 0; i < N * M; i++)
        res.data[i] = rand(lhs, rhs);
    return res;
}

template <typename T, size_t N> 
inline constexpr Vector<T, N> closest_point_on_line(const Vector<T, N>& start, const Vector<T, N>& end, const Vector<T, N>& p)
{
    const Vector<T, N> d = end - start;
    const T val = dot(p - start, d) / dot(d, d);
    return start + std::min(std::max(val, T(0)), T(1)) * d;
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
    for(size_t i = 1; i < poly.size(); i++)
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

template <typename T, size_t N>
inline constexpr bool aabb_overlap(const Vector<T, N>& pos0, const Vector<T, N>& size0, const Vector<T, N>& pos1, const Vector<T, N>& size1)
{
    for(size_t i = 0; i < N; i++)
        if(pos0[i] - size0[i] / T(2) > pos1[i] + size1[i] / T(2) || pos0[i] + size0[i] / T(2) < pos1[i] - size1[i] / T(2))
            return false;
    return true;
}

template <typename T, size_t N>
inline bool sat_seperated(const std::vector<Vector<T, N>>& poly0, const std::vector<Vector<T, N>>& poly1, const Vector<T, N>& axis)
{
    T min0 = T(INFINITY), max0 = T(-INFINITY);
    for(size_t k = 0; k < poly0.size(); k++)
    {
        const T res = dot(poly0[k], axis);
        min0 = std::min(min0, res);
        max0 = std::max(max0, res);
    }
    T min1 = T(INFINITY), max1 = T(-INFINITY);
    for(size_t p = 0; p < poly1.size(); p++)
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
    for(size_t i = 0; i < poly0.size(); i++)
    {
        const size_t j = (i + 1) % poly0.size();
        const Vector<T, 2> proj = {poly0[i].y - poly0[j].y, poly0[j].x - poly0[i].x};
        if(sat_seperated(poly0, poly1, proj)) return false;
    }
    return true;
}

template <typename T>
inline bool sat_overlap(const std::vector<Vector<T, 3>>& poly0, const std::vector<Vector<T, 3>>& poly1, const std::vector<Vector<T, 3>>& axes)
{
    for(size_t i = 0; i < axes.size(); i++)
        if(sat_seperated(poly0, poly1, axes[i]))
            return false;
    return true;
}

template <typename T>
inline bool sat_overlap(const std::vector<Vector<T, 2>>& poly0, const std::vector<Vector<T, 2>>& poly1)
{
    return sat_check(poly0, poly1) && sat_check(poly1, poly0);
}

template <typename T, size_t N>
inline Vector<T, N> get_closest_point_on_poly(const std::vector<Vector<T, N>>& poly, const Vector<T, N>& vec)
{
    T distance = T(INFINITY);
    Vector<T, N> res;
    for(size_t i = 0; i < poly.size(); i++)
    {
        const size_t j = (i + 1) % poly.size();
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

template <typename T, size_t N>
inline T get_closest_distance_to_poly(const std::vector<Vector<T, N>>& poly, const Vector<T, N>& vec)
{
    return (get_closest_point_on_poly(poly, vec) - vec).mag();
}

template <typename T>
inline constexpr Vector<T, 3> surface_normal(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
{
    return cross(pos1 - pos0, pos2 - pos0).norm();
}

template <typename T, size_t N> 
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
    inline constexpr BoundingBox(const Vector<T, 3>& pos, const Vector<T, 3>& size, const Vector<T, 3>& rotation = T(0)) : pos(pos), size(size), rotation(rotation)
    {
        return;
    }
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
    inline bool Overlaps(const std::vector<Vector<T, 3>>& vertices)
    {
        //TODO
        return false;
    }
    inline std::vector<Vector<T, 3>> GetVertices() const
    {
        const Vector<T, 3> half = size / T(2);
        const Quaternion<T> quat = quat_from_euler(rotation);
        return
        {
            pos + quat_rotate(quat, {-half.x, -half.y, -half.z}),
            pos + quat_rotate(quat, {-half.x, -half.y,  half.z}),
            pos + quat_rotate(quat, {-half.x,  half.y,  half.z}),
            pos + quat_rotate(quat, {-half.x,  half.y, -half.z}),
            pos + quat_rotate(quat, { half.x, -half.y, -half.z}),
            pos + quat_rotate(quat, { half.x,  half.y, -half.z}),
            pos + quat_rotate(quat, { half.x, -half.y,  half.z}),
            pos + quat_rotate(quat, { half.x,  half.y,  half.z})
        };
    }
    inline std::vector<Vector<T, 3>> GetAxes() const
    {
        const Quaternion<T> quat = quat_from_euler(rotation);
        return 
        {
            quat_rotate(quat, Vector<T, 3>::right()),
            quat_rotate(quat, Vector<T, 3>::up()),
            quat_rotate(quat, Vector<T, 3>::forward())
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
    inline constexpr BoundingBox(const Vector<T, 2>& pos, const Vector<T, 2>& size, const T& rotation = T(0)) : pos(pos), size(size), rotation(rotation)
    {
        return;
    }
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

template <typename T, size_t N> 
struct BoundingSphere
{
    Vector<T, N> pos;
    T radius;
    inline constexpr BoundingSphere() = default;
    inline constexpr BoundingSphere& operator=(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(BoundingSphere<T, N>&& lhs) = default;
    inline constexpr BoundingSphere(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(const Vector<T, N>& pos, const T& radius) : pos(pos), radius(radius)
    {
        return;
    }
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
    inline constexpr Plane(Plane&& plane) = default;
    inline constexpr Plane(const Vector<T, 3>& normal, const T& distance) : normal(normal), distance(distance)
    {
        return;
    }
    inline constexpr Intersection Intersects(const BoundingBox<T, 3>& box)
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr Intersection Intersects(const BoundingSphere<T, 3>& sphere)
    {
        const T distance = Distance(sphere.pos);
        if(std::abs(distance) < sphere.radius)
            return Intersection::Intersects;
        else if(distance > 0.0f)
            return Intersection::Front;
        else
            return Intersection::Back;
    }
    inline constexpr Intersection Intersects(const Plane<T>& plane)
    {
        //TODO
        return Intersection::Intersects;
    }
    inline constexpr T Distance(const Vector<T, 3>& point)
    {
        return dot(normal, point) - distance;
    }
};

template <typename T>
struct Frustum
{
    Plane<T> far, near, top, bottom, right, left;
    Matrix<T, 4, 4> mat;
    inline constexpr Frustum() = default;
    inline constexpr Frustum& operator=(const Frustum& frustum) = default;
    inline constexpr Frustum(Frustum&& frustum) = default;
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
    inline constexpr Transform() : invertMatrix(false), transform(Matrix<T, 3, 3>::identity()), inverted(Matrix<T, 3, 3>::identity())
    {
        return;
    }
    inline constexpr void Rotate(const T& ang)
    {
        transform = transform * rotation_mat_2d<T>(ang);
        invertMatrix = true;
    }
    inline constexpr void Scale(const T& w, const T& h)
    {
        Scale({w, h});
    }
    inline constexpr void Scale(const Vector<T, 2>& scale)
    {
        transform = transform * scale_mat_2d<T>(scale);
        invertMatrix = true;
    }
    inline constexpr void Translate(const T& x, const T& y)
    {
        Translate({x, y});
    }
    inline constexpr void Translate(const Vector<T, 2>& offset)
    {
        transform = transform * translation_mat_2d<T>(offset);
        invertMatrix = true;
    }
    inline constexpr Vector<T, 2> Forward(const Vector<T, 2>& p) const
    {
        return Forward(p.x, p.y);
    }
    inline constexpr Vector<T, 2> Forward(const T& x, const T& y) const
    {
        const Vector<T, 3> vec = transform * Vector<T, 3>{x, y, T(1)};
        return Vector<T, 2>{vec.x, vec.y} / (vec.z == T(0) ? T(1) : vec.z);
    }
    inline constexpr Vector<T, 2> Backward(const Vector<T, 2>& p) const
    {
        return Backward(p.x, p.y);
    }
    inline constexpr Vector<T, 2> Backward(const T& x, const T& y) const
    {
        const Vector<T, 3> vec = inverted * Vector<T, 3>{x, y, T(1)};
        return Vector<T, 2>{vec.x, vec.y} / (vec.z == T(0) ? T(1) : vec.z);
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
    inline constexpr Transform3D() : scale(T(1)), position(T(0)), rotation({T(1), T(0)})
    {
        return;
    }
    inline constexpr Transform3D(const Vector<T, 3>& position, const Quaternion<T>& rotation, const Vector<T, 3>& scale)
    : position(position), rotation(rotation), scale(scale)
    {
        return;
    }
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
        quat_slerp(lhs.rotation, rhs.rotation, t),
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