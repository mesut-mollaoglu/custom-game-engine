#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

//integral types
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using usize = std::size_t;
using iptr = std::intptr_t;
using uptr = std::uintptr_t;
using umax = std::uintmax_t;
using imax = std::intmax_t;
using c16 = char16_t;
using c32 = char32_t;

//C++20 integral type
#if __cplusplus >= 202002L
using c8 = char8_t;
#endif

//floating point types
using f32 = float;
using f64 = double;

//C++23 floating point types
#if __cplusplus >= 202302L
using f16 = std::float16_t;
using f128 = std::float128_t;
using bf16 = std::bfloat16_t;
#endif

using std::chrono::steady_clock;
using time_point = std::chrono::time_point<steady_clock>;

class MapKey;

using TypeInfoRef = std::reference_wrapper<const std::type_info>;

namespace std
{
    template <>
    struct hash<MapKey>
    {
        size_t operator()(const MapKey& key) const;
    };
    template <>
    struct hash<TypeInfoRef>
    {
        inline size_t operator()(const TypeInfoRef& key) const
        {
            return key.get().hash_code();
        }
    };
    template <>
    struct equal_to<TypeInfoRef>
    {
        inline bool operator()(const TypeInfoRef& lhs, const TypeInfoRef& rhs) const
        {
            return lhs.get() == rhs.get();
        }
    };
};

//unordered_map key type
class MapKey : public std::variant<usize, std::string>
{
public:
    using std::variant<usize, std::string>::variant;
    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    inline MapKey(const T& x) noexcept : std::variant<usize, std::string>(static_cast<usize>(x)) {}
    inline std::variant<usize, std::string>* GetAddressOf() noexcept {return this;}
};

inline size_t std::hash<MapKey>::operator()(const MapKey& key) const
{
    return std::hash<std::variant<usize, std::string>>()(*const_cast<MapKey&>(key).GetAddressOf());
}

#endif