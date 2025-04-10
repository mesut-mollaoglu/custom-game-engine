#ifndef TYPEDEFS_H
#define TYPEDEFS_H

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using usize = std::size_t;
using isize = std::ptrdiff_t;
using umax = std::uintmax_t;
using imax = std::intmax_t;
using f32 = float;
using f64 = double;

using steady_clock = std::chrono::steady_clock;
using time_point = std::chrono::time_point<steady_clock>;
using key_type = std::variant<usize, std::string>;

#endif