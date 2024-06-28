#ifndef MATH_H
#define MATH_H

#include "includes.h"

constexpr float pi = 3.141519265358979323846;
constexpr float epsilon = 0.1;

inline constexpr float deg2rad(float angle)
{
    return (angle / 180.f) * pi;
}

inline constexpr float rad2deg(float angle)
{
    return (angle / pi) * 180.f;
}

template <typename T, std::size_t size> struct Vector
{
    static_assert(std::is_arithmetic<T>::value);
    T data[size];
    inline constexpr Vector& operator=(const Vector<T, size>& lhs) = default;
    inline constexpr Vector(const Vector<T, size>& lhs) = default;
    inline constexpr Vector(const T& lhs = T(0))
    {
        for(std::size_t i = 0; i < size; i++)
            data[i] = lhs;
    }
    inline constexpr Vector(const T(&lhs)[size])
    {
        for(std::size_t i = 0; i < size; i++)
            data[i] = lhs[i];
    }
    template <typename... Args, typename = typename std::enable_if<(std::is_convertible<Args, T>::value && ...) && sizeof...(Args) + 1 == size>::type> 
    inline constexpr Vector(const T& lhs, const Args&... args) : data{lhs, args...}
    {
        return;
    }
    template <std::size_t N, typename... Args, typename = typename std::enable_if<(std::is_convertible<Args, T>::value && ...) && sizeof...(Args) + N == size>::type>
    inline constexpr Vector(const Vector<T, N>& lhs, const Args&... args)
    {
        const T values[] = {args...};
        for(std::size_t i = 0; i < size; i++)
            data[i] = i < N ? lhs.data[i] : values[i];
    }
    inline constexpr T mag2() const
    {
        T res = T(0);
        for(std::size_t i = 0; i < size; i++)
            res += data[i] * data[i];
        return res;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr T min_element() const
    {
        T res = data[0];
        for(std::size_t i = 0; i < size; i++)
            res = std::min(res, data[i]);
        return res;
    }
    inline constexpr T max_element() const
    {
        T res = data[0];
        for(std::size_t i = 0; i < size; i++)
            res = std::max(res, data[i]);
        return res;
    }
    inline constexpr Vector<T, size> abs() const
    {
        Vector<T, size> res;
        for(std::size_t i = 0; i < size; i++)
            res.data[i] = std::abs(data[i]);
        return res;
    }
    inline constexpr Vector<T, size> norm() const
    {
        Vector<T, size> res;
        const T mag = this->mag();
        for(std::size_t i = 0; i < size; i++)
            res.data[i] = data[i] / mag;
        return res;
    }
    template <typename F> inline constexpr operator Vector<F, size>()
    {
        Vector<F, size> res;
        for(std::size_t i = 0; i < size; i++)
            res.data[i] = static_cast<F>(data[i]);
        return res;
    }
    inline T& operator[](const std::size_t& index)
    {
        return data[index];
    }
    inline const T operator[](const std::size_t& index) const
    {
        return data[index];
    }
};

template <typename T> struct Vector<T, 2>
{
    union
    {
        T data[2];
        struct { T x, y; };
        struct { T u, v; };
        struct { T s, t; };
        struct { T w, h; };
    };
    inline constexpr Vector(const T& lhs = T(0)) : x(lhs), y(lhs) {}
    inline constexpr Vector(const T& x, const T& y) : x(x), y(y) {}
    inline constexpr T mag2() const
    {
        return x * x + y * y;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr T min_element() const
    {
        return std::min(x, y);
    }
    inline constexpr T max_element() const
    {
        return std::max(x, y);
    }
    inline constexpr T area() const
    {
        return w * h;
    }
    inline constexpr Vector<T, 2> norm() const
    {
        const T mag = this->mag();
        return {x / mag, y / mag};
    }
    template <typename F> inline constexpr operator Vector<F, 2>()
    {
        return 
        {
            static_cast<F>(x), 
            static_cast<F>(y)
        };
    }
    inline T& operator[](const std::size_t& index)
    {
        return data[index];
    }
    inline const T operator[](const std::size_t& index) const
    {
        return data[index];
    }
};

template <typename T> struct Vector<T, 3>
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
    };
    inline constexpr Vector(const T& lhs = T(0)) : x(lhs), y(lhs), z(lhs) {}
    inline constexpr Vector(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}
    inline constexpr T mag2() const
    {
        return x * x + y * y + z * z;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr T min_element() const
    {
        return std::min({x, y, z});
    }
    inline constexpr T max_element() const
    {
        return std::max({x, y, z});
    }
    inline constexpr Vector<T, 3> norm() const
    {
        const T mag = this->mag();
        return {x / mag, y / mag, z / mag};
    }
    template <typename F> inline constexpr operator Vector<F, 3>()
    {
        return 
        {
            static_cast<F>(x), 
            static_cast<F>(y),
            static_cast<F>(z)
        };
    }
    inline T& operator[](const std::size_t& index)
    {
        return data[index];
    }
    inline const T operator[](const std::size_t& index) const
    {
        return data[index];
    }
};

template <typename T> struct Vector<T, 4>
{
    union
    {
        T data[4];
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
    };
    inline constexpr Vector(const T& lhs = T(0)) : x(lhs), y(lhs), z(lhs), w(lhs) {}
    inline constexpr Vector(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}
    inline constexpr T mag2() const
    {
        return x * x + y * y +  z * z + w * w;
    }
    inline constexpr T mag() const
    {
        return std::sqrt(mag2());
    }
    inline constexpr T min_element() const
    {
        return std::min({x, y, z, w});
    }
    inline constexpr T max_element() const
    {
        return std::max({x, y, z, w});
    }
    inline constexpr Vector<T, 4> norm() const
    {
        const T mag = this->mag();
        return {x / mag, y / mag, z / mag, w / mag};
    }
    template <typename F> inline constexpr operator Vector<F, 4>()
    {
        return 
        {
            static_cast<F>(x), 
            static_cast<F>(y), 
            static_cast<F>(z), 
            static_cast<F>(w)
        };
    }
    inline T& operator[](const std::size_t& index)
    {
        return data[index];
    }
    inline const T operator[](const std::size_t& index) const
    {
        return data[index];
    }
};

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator*=(Vector<T, size>& lhs, const T& rhs) 
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] *= rhs;
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator/=(Vector<T, size>& lhs, const T& rhs) 
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] /= rhs;
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator+=(Vector<T, size>& lhs, const T& rhs)
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] += rhs;
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator-=(Vector<T, size>& lhs, const T& rhs)
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] -= rhs;
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator+=(Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] += rhs.data[i];
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator-=(Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] -= rhs.data[i];
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator*=(Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] *= rhs.data[i];
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator/=(Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    for(std::size_t i = 0; i < size; i++)
        lhs.data[i] /= rhs.data[i];
    return lhs;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator-(const T& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res -= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator+(const T& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res += rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator*(const T& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res *= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator/(const T& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res /= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator*(const Vector<T, size>& lhs, const T& rhs)
{
    Vector<T, size> res = lhs;
    res *= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator/(const Vector<T, size>& lhs, const T& rhs)
{
    Vector<T, size> res = lhs;
    res /= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator+(const Vector<T, size>& lhs, const T& rhs)
{
    Vector<T, size> res = lhs;
    res += rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator-(const Vector<T, size>& lhs, const T& rhs)
{
    Vector<T, size> res = lhs;
    res -= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator*(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res *= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator/(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res /= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator+(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res += rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator-(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res = lhs;
    res -= rhs;
    return res;
}

template <typename T, std::size_t size> inline constexpr bool operator==(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    bool res = true;
    for(std::size_t i = 0; i < size; i++)
        res = res && (lhs.data[i] == rhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr bool operator==(const Vector<T, size>& lhs, const T& rhs)
{
    bool res = true;
    for(std::size_t i = 0; i < size; i++)
        res = res && (lhs.data[i] == rhs);
    return res;
}

template <typename T, std::size_t size> inline constexpr bool operator<(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    bool res = true;
    for(std::size_t i = 0; i < size; i++)
        res = res && (lhs.data[i] < rhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr bool operator>(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    bool res = true;
    for(std::size_t i = 0; i < size; i++)
        res = res && (lhs.data[i] > rhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr bool operator<(const Vector<T, size>& lhs, const T& rhs)
{
    return lhs < Vector<T, size>(rhs);
}

template <typename T, std::size_t size> inline constexpr bool operator>(const Vector<T, size>& lhs, const T& rhs)
{
    return lhs > Vector<T, size>(rhs);
}

template <typename T, std::size_t size> inline constexpr bool operator<(const T& lhs, const Vector<T, size>& rhs)
{
    return Vector<T, size>(lhs) < rhs;
}

template <typename T, std::size_t size> inline constexpr bool operator>(const T& lhs, const Vector<T, size>& rhs)
{
    return Vector<T, size>(lhs) > rhs;
}

template <typename T, std::size_t size> inline constexpr bool operator!=(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    return !(lhs == rhs);
}

template <typename T, std::size_t size> inline constexpr bool operator!=(const Vector<T, size>& lhs, const T& rhs)
{
    return !(lhs == rhs);
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> operator-(const Vector<T, size>& lhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = -lhs.data[i];
    return res;
}

template <typename T, std::size_t size> inline constexpr std::ostream& operator<<(std::ostream& os, const Vector<T, size>& vec)
{
    os << '{';
    for(std::size_t i = 0; i < size; i++)
        os << vec.data[i] << (i != size - 1 ? ',' : '}');
    return os;
}

template <typename T, std::size_t size> inline constexpr T dot(const Vector<T, size>& lhs, const Vector<T, size>& rhs){
    T res = T(0);
    for(std::size_t i = 0; i < size; i++)
        res += lhs.data[i] * rhs.data[i];
    return res;
}

template <typename T> inline constexpr Vector<T, 3> cross(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs)
{
    return 
    {
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    };
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> max(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = std::max(lhs.data[i], rhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> min(const Vector<T, size>& lhs, const Vector<T, size>& rhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = std::min(lhs.data[i], rhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> lerp(const Vector<T, size>& lhs, const Vector<T, size>& rhs, float frac)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = (rhs.data[i] - lhs.data[i]) * frac + lhs.data[i];
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> clamp(const Vector<T, size>& lhs, const Vector<T, size>& min, const Vector<T, size>& max)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = std::clamp(lhs.data[i], min.data[i], max.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> abs(const Vector<T, size>& lhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = std::abs(lhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> floor(const Vector<T, size>& lhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = std::floor(lhs.data[i]);
    return res;
}

template <typename T, std::size_t size> inline constexpr Vector<T, size> ceil(const Vector<T, size>& lhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = std::ceil(lhs.data[i]);
    return res;
}

typedef Vector<float, 2> vec2f;
typedef Vector<double, 2> vec2d;
typedef Vector<int32_t, 2> vec2i;
typedef Vector<uint32_t, 4> vec2u;
typedef Vector<float, 3> vec3f;
typedef Vector<double, 3> vec3d;
typedef Vector<int32_t, 3> vec3i;
typedef Vector<uint32_t, 4> vec3u;
typedef Vector<float, 4> vec4f;
typedef Vector<double, 4> vec4d;
typedef Vector<int32_t, 4> vec4i;
typedef Vector<uint32_t, 4> vec4u;

template <typename T, std::size_t rows, std::size_t cols> struct Matrix
{
    static_assert(std::is_arithmetic<T>::value);
    union
    {
        T mat[cols][rows];
        T data[rows * cols];
    };
    inline constexpr Matrix& operator=(const Matrix<T, rows, cols>& lhs) = default;
    inline constexpr Matrix(const Matrix<T, rows, cols>& lhs) = default;
    template <std::size_t N = rows, std::size_t M = cols>
    inline constexpr Matrix(const T& lhs = T(0), typename std::enable_if<M == N>::type* = 0)
    {
        for(std::size_t i = 0; i < cols; i++)
            for(std::size_t j = 0; j < rows; j++)
                mat[i][j] = (i == j) ? lhs : T(0);
    }
    template <std::size_t N = rows, std::size_t M = cols>
    inline constexpr Matrix(const T& lhs = T(0), typename std::enable_if<M != N>::type* = 0)
    {
        for(std::size_t i = 0; i < rows * cols; i++)
            data[i] = lhs;
    }
    inline constexpr Matrix(const T(&lhs)[rows * cols])
    {
        for(std::size_t i = 0; i < rows * cols; i++)
            data[i] = lhs[i];
    }
    template <typename... Args, typename = typename std::enable_if<(std::is_convertible<Args, T>::value && ...) && sizeof...(Args) + 1 == rows * cols>::type> 
    inline constexpr Matrix(const T& lhs, const Args&... args) : data{lhs, args...}
    {
        return;
    }
    template <std::size_t N, std::size_t M, typename = typename std::enable_if<N < rows && M < cols>::type> 
    inline constexpr Matrix(const Matrix<T, N, M>& lhs)
    {
        for(std::size_t i = 0; i < N; i++)
            for(std::size_t j = 0; j < M; j++)
                this->mat[i][j] = lhs.mat[i][j];
    }
    inline constexpr Vector<T, cols> row(const std::size_t& lhs) const
    {
        Vector<T, cols> res;
        for(std::size_t i = 0; i < cols; i++) 
            res[i] = mat[i][lhs];
        return res;
    }
    inline constexpr Vector<T, rows> col(const std::size_t& lhs) const
    {
        Vector<T, rows> res; 
        for(std::size_t i = 0; i < rows; i++) 
            res[i] = mat[lhs][i]; 
        return res;
    }
    inline constexpr void set_row(const std::size_t& lhs, const Vector<T, cols>& rhs) 
    {
        for(std::size_t i = 0; i < cols; i++) 
            mat[i][lhs] = rhs[i];
    }
    inline constexpr void set_col(const std::size_t& lhs, const Vector<T, rows>& rhs)
    {
        for(std::size_t i = 0; i < rows; i++)
            mat[lhs][i] = rhs[i];
    }
    inline friend constexpr bool operator==(const Matrix<T, rows, cols>& lhs, const Matrix<T, rows, cols>& rhs)
    {
        bool res = true;
        for(std::size_t i = 0; i < rows * cols; i++)
            res = res && (lhs.data[i] == rhs.data[i]);
        return res;
    }
    inline friend constexpr bool operator!=(const Matrix<T, rows, cols>& lhs, const Matrix<T, rows, cols>& rhs)
    {
        return !(lhs == rhs);
    }
    inline constexpr Matrix<T, cols, rows> transpose() const
    {
        Matrix<T, cols, rows> res;
        for(std::size_t i = 0; i < cols; i++)
            res.set_row(i, col(i));
        return res;
    }
    template <std::size_t N = rows, std::size_t M = cols, typename = typename std::enable_if<N == M>::type>
    inline constexpr Matrix<T, rows, cols> inverse() const
    {
        Matrix<T, rows, cols> temp = *this;
        Matrix<T, rows, cols> res = Matrix<T, rows, cols>(T(1));
        for(std::size_t i = 0; i < rows; i++)
        {
            const T div = temp.mat[i][i];
            res.set_col(i, res.col(i) / div);
            temp.set_row(i, temp.row(i) / div);
            for(std::size_t j = 0; j < rows; j++)
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
    template <std::size_t N = rows, std::size_t M = cols, typename = typename std::enable_if<N == M>::type>
    inline constexpr Matrix<T, rows, cols> pow(const std::size_t& lhs) const
    {
        if(lhs == 0)
        {
            return Matrix<T, rows, cols>(T(1));
        }
        else if(lhs == 1)
        {
            return *this;
        }
        else 
        {
            Matrix<T, rows, cols> res = *this;
            for(std::size_t j = 1; j < lhs; j++)
                res = res * (*this);
            return res;
        }
    }
    template <std::size_t N = rows, std::size_t M = cols, typename = typename std::enable_if<N == M>::type>
    inline constexpr T determinant() const
    {
        T res = T(1);
        Matrix<T, rows, cols> temp = *this;
        for(std::size_t i = 0; i < rows; i++)
        {
            const T div = temp.mat[i][i];
            for(std::size_t j = i + 1; j < rows; j++)
            {
                const T mul = temp.mat[i][j];
                temp.set_row(j, temp.row(j) - (temp.row(i) / div * mul));
            }
        }
        for(std::size_t i = 0; i < rows; i++)
        {
            res *= temp.mat[i][i];
        }
        return res;
    }
    template <std::size_t N>
    inline friend constexpr Matrix<T, rows, N> operator*(const Matrix<T, rows, cols>& lhs, const Matrix<T, cols, N>& rhs)
    {
        Matrix<T, rows, N> res;
        for(std::size_t i = 0; i < N; i++)
            for(std::size_t j = 0; j < rows; j++)
                res.mat[i][j] = dot(lhs.row(j), rhs.col(i));
        return res;
    }
    inline friend constexpr Vector<T, rows> operator*(const Matrix<T, rows, cols>& lhs, const Vector<T, cols>& rhs)
    {
        Vector<T, rows> res;
        for(std::size_t i = 0; i < rows; i++)
            res.data[i] = dot(lhs.row(i), rhs);
        return res;
    }
    inline friend constexpr Vector<T, cols> operator*(const Vector<T, rows>& lhs, const Matrix<T, rows, cols>& rhs)
    {
        Vector<T, cols> res;
        for(std::size_t i = 0; i < cols; i++)
            res.data[i] = dot(lhs, rhs.col(i));
        return res;
    }
    template <typename F> inline constexpr operator Matrix<F, rows, cols>()
    {
        Matrix<F, rows, cols> res;
        for(std::size_t i = 0; i < rows * cols; i++)
            res.data[i] = static_cast<F>(data[i]);
        return res;
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Matrix<T, rows, cols>& mat)
    {
        for(std::size_t i = 0; i < rows; i++)
            os << mat.row(i);
        return os;
    }
};

template <typename T, std::size_t N> Matrix<T, N, N> mat_identity()
{
    return Matrix<T, N, N>(T(1));
}

template <typename T> inline constexpr Matrix<T, 4, 4> make_perspective_mat(const T& aspect, const T& fov, const T& near, const T& far)
{
    const T half_fov = std::tan(deg2rad(fov) / T(2));
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(0);
    res.mat[0][0] = T(1) / (aspect * half_fov);
    res.mat[1][1] = T(1) / (half_fov);
    res.mat[2][2] = (near + far) / (near - far);
    res.mat[2][3] = T(-1);
    res.mat[3][2] = (T(2) * far * near) / (near - far);
    return res;
}

template <typename T> inline constexpr Matrix<T, 4, 4> make_ortho_mat(const T& right, const T& left, const T& bottom, const T& top, const T& near, const T& far)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(1);
    res.mat[0][0] = T(2) / (right - left);
    res.mat[1][1] = T(2) / (top - bottom);
    res.mat[2][2] = T(2) / (near - far);
    res.mat[3][0] = (right + left) / (left - right);
    res.mat[3][1] = (top + bottom) / (bottom - top);
    res.mat[3][2] = (far + near) / (near - far);
    return res;
}

template <typename T> inline constexpr Matrix<T, 4, 4> mat_look_at(const Vector<T, 3>& eye, const Vector<T, 3>& center, const Vector<T, 3>& up)
{
    Vector<T, 3> en = (center - eye).norm();
    Vector<T, 3> cn = up.norm();
    Vector<T, 3> un = cross(en, cn).norm();
    cn = cross(un, en);
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(1);
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

template <typename T> inline constexpr Matrix<T, 4, 4> rotate_mat(const T& angle, const Vector<T, 3>& axis)
{
    const T c = std::cos(angle);
    const T s = std::sin(angle);
    const Vector<T, 3> norm = axis.norm();
    const Vector<T, 3> vec = norm * (1 - c);
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(1);
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

template <typename T> inline constexpr Matrix<T, 4, 4> translate_mat(const Vector<T, 3>& lhs)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(1);
    res.mat[3][0] = lhs.x;
    res.mat[3][1] = lhs.y;
    res.mat[3][2] = lhs.z;
    return res;
}

template <typename T> inline constexpr Matrix<T, 4, 4> scale_mat(const Vector<T, 3>& lhs)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(1);
    res.mat[0][0] = lhs.x;
    res.mat[1][1] = lhs.y;
    res.mat[2][2] = lhs.z;
    return res;
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

template <typename T> struct Quaternion
{
    static_assert(std::is_arithmetic<T>::value);
    union
    {
        T data[4];
        struct { T scalar; Vector<T, 3> vec; };
    };
    inline constexpr Quaternion& operator=(const Quaternion<T>& lhs) = default;
    inline constexpr Quaternion(const Quaternion<T>& lhs) = default;
    inline constexpr Quaternion()
    {
        scalar = T(1);
        vec = T(0);
    }
    inline constexpr Quaternion(const T& lhs, const Vector<T, 3>& rhs)
    {
        scalar = lhs;
        vec = rhs;
    }
    inline constexpr Quaternion(const T& w, const T& x, const T& y, const T& z)
    {
        scalar = w;
        vec = Vector<T, 3>(x, y, z);
    }
    inline friend constexpr bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
    {
        return lhs.scalar == rhs.scalar && lhs.vec == rhs.vec;
    }
    inline friend constexpr bool operator!=(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
    {
        return !(lhs == rhs);
    }
    inline friend constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
    {
        Quaternion<T> res;
        res.scalar = lhs.scalar * rhs.scalar - lhs.vec.x * rhs.vec.x - lhs.vec.y * rhs.vec.y - lhs.vec.z * rhs.vec.z;
        res.vec.x = lhs.scalar * rhs.vec.x + lhs.vec.x * rhs.scalar + lhs.vec.y * rhs.vec.z - lhs.vec.z * rhs.vec.y;
        res.vec.y = lhs.scalar * rhs.vec.y - lhs.vec.x * rhs.vec.z + lhs.vec.y * rhs.scalar + lhs.vec.z * rhs.vec.x;
        res.vec.z = lhs.scalar * rhs.vec.z + lhs.vec.x * rhs.vec.y - lhs.vec.y * rhs.vec.x + lhs.vec.z * rhs.scalar;
        return res;
    }
    inline friend constexpr Quaternion<T> operator/(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
    {
        Quaternion<T> res;
        const T inv = T(1) / rhs.norm();
        res.scalar = (lhs.scalar * rhs.scalar + lhs.vec.x * rhs.vec.x + lhs.vec.y * rhs.vec.y + lhs.vec.z * rhs.vec.z) * inv;
        res.scalar = (lhs.scalar * rhs.vec.x - lhs.vec.x * rhs.scalar - lhs.vec.y * rhs.vec.z + lhs.vec.z * rhs.vec.y) * inv;
        res.scalar = (lhs.scalar * rhs.vec.y + lhs.vec.x * rhs.vec.z - lhs.vec.y * rhs.scalar - lhs.vec.z * rhs.vec.x) * inv;
        res.scalar = (lhs.scalar * rhs.vec.z - lhs.vec.x * rhs.vec.y + lhs.vec.y * rhs.vec.x - lhs.vec.z * rhs.scalar) * inv;
        return res;
    }
    inline friend constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
    {
        Quaternion<T> res;
        res.scalar = lhs.scalar + rhs.scalar;
        res.vec = lhs.vec + rhs.vec;
        return res;
    }
    inline friend constexpr Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
    {
        Quaternion<T> res;
        res.scalar = lhs.scalar - rhs.scalar;
        res.vec = lhs.vec - rhs.vec;
        return res;
    }
    inline friend constexpr Quaternion<T> operator/(const Quaternion<T>& lhs, const T& rhs)
    {
        return Quaternion<T>(lhs.scalar / rhs, lhs.vec / rhs);
    }
    inline friend constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const T& rhs)
    {
        return Quaternion<T>(lhs.scalar * rhs, lhs.vec * rhs);
    }
    inline friend constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const T& rhs)
    {
        return Quaternion<T>(lhs.scalar + rhs, lhs.vec + rhs);
    }
    inline friend constexpr Quaternion<T> operator-(const Quaternion<T>& lhs, const T& rhs)
    {
        return Quaternion<T>(lhs.scalar - rhs, lhs.vec - rhs);
    }
    inline constexpr Quaternion<T> conjugate() const
    {
        return Quaternion<T>(scalar, -vec);
    }
    inline constexpr Quaternion<T> inverse() const
    {
        const T mag = this->mag2();
        return Quaternion<T>(scalar / mag, -vec / mag);
    }
    inline constexpr T mag2() const
    {
        return vec.mag2() + scalar * scalar;
    }
    inline constexpr T norm() const
    {
        return std::sqrt(this->mag2());
    }
    inline constexpr Quaternion<T> normalize() const
    {
        const T mag = this->norm();
        return Quaternion<T>(scalar / mag, vec / mag);
    }
    inline const T operator[](const std::size_t& index) const
    {
        return data[index];
    }
    inline T& operator[](const std::size_t& index)
    {
        return data[index];
    }
    inline friend std::ostream& operator<<(std::ostream& os, const Quaternion<T>& quat)
    {
        os << '{' << quat.scalar << ',' << quat.vec << '}';
        return os;
    }
};

typedef Quaternion<float> quatf;
typedef Quaternion<double> quatd;

template <typename T> inline constexpr Quaternion<T> quat_from_euler(const Vector<T, 3>& lhs)
{
    Quaternion<T> res;
    const Vector<T, 3> vec = lhs / T(2);
    const T cr = std::cos(vec.roll);
    const T sr = std::sin(vec.roll);
    const T cp = std::cos(vec.pitch);
    const T sp = std::sin(vec.pitch);
    const T cy = std::cos(vec.yaw);
    const T sy = std::sin(vec.yaw);
    res.scalar = cr * cp * cy + sr * sp * sy;
    res.vec.x = sr * cp * cy - cr * sp * sy;
    res.vec.y = cr * sp * cy + sr * cp * sy;
    res.vec.z = cr * cp * sy - sr * sp * cy;
    return res;
}

template <typename T> inline constexpr Quaternion<T> quat_from_axis(const Vector<T, 3>& axis, float angle)
{
    Quaternion<T> res;
    res.scalar = std::cos(angle / T(2));
    res.vec = std::sin(angle / T(2)) * axis;
    return res;
}

template <typename T> inline constexpr Vector<T, 3> quat_to_euler(const Quaternion<T>& lhs)
{
    return 
    {
        std::atan2
        (
            T(2) * (lhs.scalar * lhs.vec.x + lhs.vec.y * lhs.vec.z),
            T(1) - T(2) * (lhs.vec.x * lhs.vec.x + lhs.vec.y * lhs.vec.y)
        ),
        T(2) * std::atan2
        (
            std::sqrt(T(1) + T(2) * (lhs.scalar * lhs.vec.y - lhs.vec.x * lhs.vec.z)),
            std::sqrt(T(1) - T(2) * (lhs.scalar * lhs.vec.y - lhs.vec.x * lhs.vec.z))
        ) - pi / T(2),
        std::atan2
        (
            T(2) * (lhs.scalar * lhs.vec.z + lhs.vec.x * lhs.vec.y),
            T(1) - T(2) * (lhs.vec.y * lhs.vec.y + lhs.vec.z * lhs.vec.z)
        )
    };
}

template <typename T> inline constexpr Matrix<T, 4, 4> mat_from_quat(const Quaternion<T>& lhs)
{
    Matrix<T, 4, 4> res = Matrix<T, 4, 4>(1);
    const T sx = lhs.vec.x * lhs.vec.x;
    const T sy = lhs.vec.y * lhs.vec.y;
    const T sz = lhs.vec.z * lhs.vec.z;
    const T sw = lhs.scalar * lhs.scalar;
    const T xy = lhs.vec.x * lhs.vec.y;
    const T zw = lhs.vec.z * lhs.scalar;
    const T xw = lhs.scalar * lhs.vec.x;
    const T yz = lhs.vec.z * lhs.vec.y;
    const T xz = lhs.vec.z * lhs.vec.x;
    const T yw = lhs.scalar * lhs.vec.y;
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

template <typename T> inline constexpr Quaternion<T> quat_from_mat(const Matrix<T, 4, 4>& lhs)
{
    Quaternion<T> res;
    res.scalar = std::sqrt(std::max(T(0), T(1) + lhs.mat[0][0] + lhs.mat[1][1] + lhs.mat[2][2])) / T(2);
    res.vec.x = std::sqrt(std::max(T(0), T(1) + lhs.mat[0][0] - lhs.mat[1][1] - lhs.mat[2][2])) / T(2);
    res.vec.y = std::sqrt(std::max(T(0), T(1) - lhs.mat[0][0] + lhs.mat[1][1] - lhs.mat[2][2])) / T(2);
    res.vec.z = std::sqrt(std::max(T(0), T(1) - lhs.mat[0][0] - lhs.mat[1][1] + lhs.mat[2][2])) / T(2);
    res.vec.x = std::copysign(res.vec.x, lhs.mat[2][1] - lhs.mat[1][2]);
    res.vec.y = std::copysign(res.vec.y, lhs.mat[0][2] - lhs.mat[2][0]);
    res.vec.z = std::copysign(res.vec.z, lhs.mat[1][0] - lhs.mat[0][1]);
    return res;
}

template <typename T> inline constexpr T quat_to_axis(const Quaternion<T>& lhs, Vector<T, 3>& rhs)
{
    const T div = std::sqrt(T(1) - lhs.scalar * lhs.scalar);
    rhs /= div == T(0) ? Vector<T, 3>(1, 0, 0) : div;
    return T(2) * std::acos(lhs.scalar);
}

template <typename T> inline constexpr Vector<T, 3> quat_rotate(const Quaternion<T>& lhs, const Vector<T, 3>& rhs)
{
    Vector<T, 3> vec = cross(lhs.vec * T(2), rhs);
    return rhs + lhs.scalar * vec + cross(vec, lhs.vec);
}

template <typename T> inline constexpr Quaternion<T> quat_slerp(const Quaternion<T>& lhs, const Quaternion<T>& rhs, float frac)
{
    const T ch = lhs.scalar * rhs.scalar + dot(lhs.vec, rhs.vec);
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
            lhs.scalar / T(2) + rhs.scalar / T(2),
            lhs.vec / T(2) + rhs.vec / T(2)
        };
    }
    const T ra = std::sin((1 - frac) * ht) / sh;
    const T rb = std::sin(frac * ht) / sh;
    return 
    {
        lhs.scalar * ra + rhs.scalar * rb,
        lhs.vec * ra + rhs.vec * rb
    };
}

template <typename T> inline constexpr Vector<T, 2> rotate(float angle, const Vector<T, 2>& vec)
{
    return 
    {
        std::cos(angle) * vec.x - std::sin(angle) * vec.y,
        std::sin(angle) * vec.x + std::cos(angle) * vec.y
    };
}

template <typename T> inline T rand(const T& lhs, const T& rhs)
{
    return ((float)rand() / (float)RAND_MAX) * (rhs - lhs) + lhs;
}

template <typename T, std::size_t size> inline Vector<T, size> rand(const T& lhs, const T& rhs)
{
    Vector<T, size> res;
    for(std::size_t i = 0; i < size; i++)
        res.data[i] = rand(lhs, rhs);
    return res;
}

template <typename T, std::size_t N, std::size_t M> inline Matrix<T, N, M> rand(const T& lhs, const T& rhs)
{
    Matrix<T, N, M> res;
    for(std::size_t i = 0; i < N * M; i++)
        res.data[i] = rand(lhs, rhs);
    return res;
}

template <typename T, std::size_t N> 
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
    const float angle = std::acos(dot(side0, side1) / (side0.mag() * side1.mag()));
    return std::sin(angle) * side0.mag() * side1.mag() / T(2);
}

template <typename T>
inline constexpr bool point_in_triangle(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2, const Vector<T, 2>& p)
{
    return (float)std::abs(triangle_area(pos0, pos1, pos2) - (triangle_area(pos0, pos1, p) + 
        triangle_area(pos0, pos2, p) + triangle_area(pos1, pos2, p))) < epsilon;
}

template <typename T, std::size_t N>
inline constexpr bool point_in_poly(const std::array<Vector<T, 2>, N>& poly, const Vector<T, 2>& vec)
{
    for(std::size_t i = 1; i < N; i++)
    {
        const std::size_t j = (i + 1) % N;
        if(point_in_triangle(poly[0], poly[i], poly[j], vec))
            return true;
    }
    return false;
}

template <typename T>
inline constexpr Vector<T, 2> project(const Vector<T, 2>& vec, const Vector<T, 2>& norm)
{
    return norm.norm() * vec.norm() * dot(vec, norm) / norm.mag();
}

template <typename T>
inline constexpr Vector<T, 3> project(const Vector<T, 3>& vec, const Vector<T, 3>& norm)
{
    const T mag = norm.mag2();
    const T dot = dot(vec, norm);
    if(mag < epsilon)
        return T(0);
    return
    {
        norm.x * dot / mag,
        norm.y * dot / mag,
        norm.z * dot / mag
    };
}

template <typename T>
inline constexpr Vector<T, 3> project_onto_plane(const Vector<T, 3>& vec, const Vector<T, 3>& norm)
{
    const T mag = norm.mag2();
    const T dot = dot(vec, norm);
    if(mag < epsilon)
        return vec;
    return
    {
        vec.x - norm.x * dot / mag,
        vec.y - norm.y * dot / mag,
        vec.z - norm.z * dot / mag
    };
}

template <typename T, std::size_t N>
inline constexpr Vector<T, N> triple_product(const Vector<T, N>& vec0, const Vector<T, N>& vec1, const Vector<T, N>& vec2)
{
    return vec1 * dot(vec0, vec2) - vec0 * dot(vec1, vec2);
}

template <typename T, std::size_t N>
inline constexpr bool aabb_overlap(const Vector<T, N>& pos0, const Vector<T, N>& size0, const Vector<T, N>& pos1, const Vector<T, N>& size1)
{
    bool res = true;
    for(std::size_t i = 0; i < N; i++)
        res = res && !(pos0[i] - size0[i] / T(2) > pos1[i] + size1[i] / T(2) || pos0[i] + size0[i] / T(2) < pos1[i] - size1[i] / T(2));
    return res;
}

template <typename T, std::size_t N, std::size_t M>
inline constexpr bool sat_overlap(const std::array<Vector<T, 2>, N>& poly0, const std::array<Vector<T, 2>, M>& poly1)
{
    auto check = [](const std::array<Vector<T, 2>, N>& poly0, const std::array<Vector<T, 2>, M>& poly1) -> bool
    {
        for(std::size_t i = 0; i < N; i++)
        {
            const std::size_t j = (i + 1) % N;
            const Vector<T, 2> proj = {poly0[i].y - poly0[j].y, poly0[j].x - poly0[i].x};
            T min0 = T(INFINITY), max0 = T(-INFINITY);
            for(std::size_t k = 0; k < N; k++)
            {
                const T res = dot(poly0[k], proj);
                min0 = std::min(min0, res);
                max0 = std::max(max0, res);
            }
            T min1 = T(INFINITY), max1 = T(-INFINITY);
            for(std::size_t p = 0; p < M; p++)
            {
                const T res = dot(poly1[p], proj);
                min1 = std::min(min1, res);
                max1 = std::max(max1, res);
            }
            if(!(max1 >= min0 && max0 >= min1)) return false;
        }
        return true;
    };
    return check(poly0, poly1) && check(poly1, poly0);
}

template <typename T, std::size_t N, std::size_t M>
inline constexpr Vector<T, N> get_closest_point_on_poly(const std::array<Vector<T, N>, M>& poly, const Vector<T, N>& vec)
{
    T distance = T(INFINITY);
    Vector<T, N> res;
    for(std::size_t i = 0; i < M; i++)
    {
        const std::size_t j = (i + 1) % M;
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

template <typename T, std::size_t N, std::size_t M>
inline constexpr T get_closest_distance_to_poly(const std::array<Vector<T, N>, M>& poly, const Vector<T, N>& vec)
{
    return (get_closest_point_on_poly(poly, vec) - vec).mag();
}

template <typename T, std::size_t N> struct BoundingBox {};

template <typename T> struct BoundingBox<T, 3>
{
    Vector<T, 3> pos;
    Vector<T, 3> size;
    vec3f rotation = 0.0f;
    inline constexpr BoundingBox() = default;
    inline constexpr BoundingBox& operator=(const BoundingBox<T, 3>& lhs) = default;
    inline constexpr BoundingBox(BoundingBox<T, 3>&& lhs) = default;
    inline constexpr BoundingBox(const Vector<T, 3>& pos, const Vector<T, 3>& size, const vec3f& rotation = 0.0f) : pos(pos), size(size), rotation(rotation)
    {
        return;
    }
    inline constexpr bool Overlaps(const Vector<T, 3>& p)
    {
        // TODO
        return false;
    }
    inline constexpr bool Overlaps(const BoundingBox<T, 3>& box)
    {
        if(rotation == 0.0f && box.rotation == 0.0f)
            return aabb_overlap(pos, size, box.pos, box.size);
        //TODO
        return false;
    }
    inline constexpr bool Overlaps(const Vector<T, 3>& pos0, const Vector<T, 3>& pos1, const Vector<T, 3>& pos2)
    {
        //TODO
        return false;
    }
    inline constexpr std::array<Vector<T, 3>, 8> GetVertices() const
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
};

template <typename T> struct BoundingBox<T, 2>
{
    Vector<T, 2> pos;
    Vector<T, 2> size;
    float rotation = 0.0f;
    inline constexpr BoundingBox() = default;
    inline constexpr BoundingBox& operator=(const BoundingBox<T, 2>& lhs) = default;
    inline constexpr BoundingBox(BoundingBox<T, 2>&& lhs) = default;
    inline constexpr BoundingBox(const Vector<T, 2>& pos, const Vector<T, 2>& size, const float rotation = 0.0f) : pos(pos), size(size), rotation(rotation)
    {
        return;
    }
    inline constexpr bool Overlaps(const Vector<T, 2>& p)
    {
        const std::array<Vector<T, 2>, 4> vertices = GetVertices();
        return (float)std::abs(size.area() - (triangle_area(vertices[0], p, vertices[1]) + triangle_area(vertices[1], p, vertices[2]) +
            triangle_area(vertices[2], p, vertices[3]) + triangle_area(vertices[0], p, vertices[3]))) < epsilon;
    }
    inline constexpr bool Overlaps(const BoundingBox<T, 2>& box)
    {
        if(rotation == 0.0f && box.rotation == 0.0f)
            return aabb_overlap(pos, size, box.pos, box.size);
        return sat_overlap(box.GetVertices(), GetVertices());
    }
    inline constexpr bool Overlaps(const Vector<T, 2>& pos0, const Vector<T, 2>& pos1, const Vector<T, 2>& pos2)
    {
        return sat_overlap(GetVertices(), {pos0, pos1, pos2});
    }
    inline constexpr std::array<Vector<T, 2>, 4> GetVertices() const
    {
        const Vector<T, 2> half = size / T(2);
        return 
        {
            pos + rotate<float>(rotation, -half),
            pos + rotate<float>(rotation, {half.w, -half.h}),
            pos + rotate<float>(rotation, half),
            pos + rotate<float>(rotation, {-half.w, half.h})
        };
    }
};

template <typename T, std::size_t N> struct BoundingSphere
{
    Vector<T, N> pos;
    T radius;
    inline constexpr BoundingSphere() = default;
    inline constexpr BoundingSphere& operator=(const BoundingSphere<T, N>& lhs) = default;
    inline constexpr BoundingSphere(BoundingSphere<T, N>&& lhs) = default;
    inline constexpr BoundingSphere(const Vector<T, N>& pos, const T& radius) : pos(pos), radius(radius)
    {
        return;
    }
    inline constexpr bool Overlaps(const Vector<T, N>& p)
    {
        return (p - pos).mag() <= radius;
    }
    inline constexpr bool Overlaps(const BoundingBox<T, N>& box)
    {
        return get_closest_distance_to_poly(box.GetVertices(), pos) <= radius;
    }
    inline constexpr bool Overlaps(const BoundingSphere<T, N>& sphere)
    {
        return (pos - sphere.pos).mag() <= (radius + sphere.radius);
    }
    inline constexpr bool Overlaps(const Vector<T, N>& pos0, const Vector<T, N>& pos1, const Vector<T, N>& pos2)
    {
        return get_closest_distance_to_poly(std::array<Vector<T, N>, 3>{pos0, pos1, pos2}, pos) <= radius;
    }
};

struct Transform
{
    mat3x3f transform;
    mat3x3f inverted;
    bool invertMatrix;
    inline Transform();
    inline void Rotate(float ang);
    inline void Scale(float sx, float sy);
    inline void Translate(float dx, float dy);
    inline vec2f Forward(float x, float y);
    inline vec2f Backward(float x, float y);
    inline void Reset();
    inline void Invert();
    ~Transform() {}
};

struct Transform3D
{
    vec3f position;
    quatf rotation;
    vec3f scale;
    inline Transform3D();
    inline void Reset();
    inline mat4x4f GetModelMat();
    inline ~Transform3D() {}
};

#endif

#ifdef MATH_H
#undef MATH_H

inline Transform::Transform()
{
    this->Reset();
}

inline void Transform::Rotate(float ang)
{
    mat3x3f rotate = mat3x3f(1.0f);
    rotate.mat[0][0] = std::cos(ang);
    rotate.mat[1][0] = -std::sin(ang);
    rotate.mat[0][1] = std::sin(ang);
    rotate.mat[1][1] = std::cos(ang);
    transform = transform * rotate;
    invertMatrix = true;
}

inline void Transform::Translate(float dx, float dy)
{
    mat3x3f translate = mat3x3f(1.0f);
    translate.mat[2][0] = dx;
    translate.mat[2][1] = dy;
    transform = transform * translate;
    invertMatrix = true;   
}

inline void Transform::Scale(float sx, float sy)
{
    mat3x3f scale = mat3x3f(1.0f);
    scale.mat[0][0] = sx;
    scale.mat[1][1] = sy;
    transform = transform * scale;
    invertMatrix = true;
}

inline void Transform::Reset()
{
    transform = mat3x3f(1.0f);
    inverted = mat3x3f(1.0f);
    invertMatrix = false;
}

inline vec2f Transform::Forward(float x, float y)
{
    const vec3f vec = transform * vec3f{x, y, 1.0f};
    return vec2f{vec.x, vec.y} / (vec.z == 0.0f ? 1.0f : vec.z);
}

inline vec2f Transform::Backward(float x, float y)
{
    const vec3f vec = inverted * vec3f{x, y, 1.0f};
    return vec2f{vec.x, vec.y} / (vec.z == 0.0f ? 1.0f : vec.z);
}

inline void Transform::Invert()
{
    if(invertMatrix)
    {
        inverted = transform.inverse();
        invertMatrix = false;
    }
}

inline void Transform3D::Reset()
{
    scale = {1.0f, 1.0f, 1.0f};
    position = {0.0f, 0.0f, 0.0f};
    rotation = {1.0f, 0.0f, 0.0f, 0.0f};
}

inline Transform3D::Transform3D()
{
    this->Reset();
}

inline mat4x4f Transform3D::GetModelMat()
{
    return translate_mat(position) * mat_from_quat(rotation) * scale_mat(scale);
}

#endif