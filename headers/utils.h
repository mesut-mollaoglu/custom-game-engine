#ifndef UTILS_H
#define UTILS_H

inline constexpr std::string_view whitespaces = " \n\t\v\0";

//for std::visit
template<typename... Ts>
struct overloads : Ts... { using Ts::operator()...; };

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
inline constexpr bool is_inner_type_same_v = std::is_same_v<inner_type_t<C>, T>;

template <typename T, class... V>
inline constexpr bool are_inner_types_same_v = std::conjunction_v<std::is_same<T, inner_type_t<V>>...>;

template <typename, typename = void>
struct is_contiguous : std::false_type {};

template <typename T>
struct is_contiguous<T, std::void_t<decltype(std::declval<T>().data())>>
: std::true_type {};

template <typename T>
inline constexpr bool is_contiguous_v = is_contiguous<T>::value;

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

namespace detail
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
inline constexpr bool has_begin_end_v = detail::has_begin_end<T>::value;

template<typename T> 
struct is_container : std::conjunction<has_const_iterator<T>, detail::has_begin_end<T>> {};

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

template <typename... V>
inline constexpr bool all_container_v = std::conjunction_v<is_container<V>...>;

template <typename T> 
inline T random(const T& lo, const T& hi)
{
    return ((f64)rand() / (f64)RAND_MAX) * (hi - lo) + lo;
}

template <typename CT>
inline inner_type_t<CT> random_value(
    const CT& container,
    std::enable_if_t<is_container_v<CT> &&
        has_index_operator_v<CT>>* = 0)
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
inline void safe_delete_array(T x[])
{
    delete[] x;
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

template <typename T>
inline constexpr int get_digit_count(
    const T& value, std::enable_if_t<std::is_integral_v<T>>* = 0)
{
    switch(abs(value))
    {
        case 0: case 1:
            return 1 + (value < 0);
        default:
            return ceil(log10(value)) + (value < 0);
    }
}

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
inline constexpr int get_significant_digit_count()
{
    if constexpr(std::is_same_v<T, float>)
        return FLT_DIG;
    else if constexpr(std::is_same_v<T, double>)
        return DBL_DIG;
    else if constexpr(std::is_same_v<T, long double>)
        return LDBL_DIG;
    return 0;
}

template <typename T>
inline constexpr int get_digit_count(
    const T& value, std::enable_if_t<std::is_floating_point_v<T>>* = 0)
{
    return get_digit_count<isize>(floor(value)) + get_significant_digit_count<T>() + 1;
}

template <typename T>
inline constexpr std::string_view to_string_view(
    const T& value, std::enable_if_t<std::is_floating_point_v<T>>* = 0)
{
    const int len = get_digit_count(value);
    char buffer[len]{};
    std::to_chars_result res = std::to_chars(buffer, buffer + len, value);
    if (res.ec != std::errc())
    {
        std::cout << std::make_error_code(res.ec).message() << '\n';
        return std::string_view("");
    }
    else
        return std::string_view(buffer, res.ptr - buffer);
}

template <typename T>
inline constexpr std::string_view to_string_view(
    const T& value, int base = 10, std::enable_if_t<std::is_integral_v<T>>* = 0)
{
    auto int_pow = [](int x, int p) -> int 
    {
        int res = 1;
        for(int i = 0; i < p; i++) res *= x;
        return res;
    };
    const int len = get_digit_count(value);
    char res[len + 1] = {0};
    for(int i = 0; i < len; i++)
        res[len - i - 1] = ((value % int_pow(base, i + 1)) / int_pow(base, i)) + '0';
    res[len] = '\0';
    return std::string_view(&res[0]);
}

template <>
inline constexpr std::string_view to_string_view(const bool& value, int base, std::void_t<>*)
{
    return std::string_view(value ? "true" : "false");
}

namespace detail
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
    detail::can_call_swap<T>::value &&
    (!detail::would_call_std_swap<T>::value ||
    (std::is_move_assignable<T>::value &&
    std::is_move_constructible<T>::value))> {};

template<typename T, usize N>
struct is_swappable<T[N]> : is_swappable<T> {};

template <typename T>
inline constexpr bool is_swappable_v = is_swappable<T>::value;

//The region below contains the implementations of various utilities from the concepts header.
//Since the concepts header is only available for C++20 or above, it wasn't possible to include it in this project.
//The implementations below are very similar to those in the standard library.
#pragma region concepts

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T, bool C, bool V>
struct cv_selector;

template <typename T>
struct cv_selector<T, false, false>
{using type = T;};

template <typename T>
struct cv_selector<T, true, false>
{using type = const T;};

template <typename T>
struct cv_selector<T, false, true>
{using type = volatile T;};

template <typename T>
struct cv_selector<T, true, true>
{using type = const volatile T;};

template <typename T, bool C, bool V>
using cv_selector_t = typename cv_selector<T, C, V>::type;

template <typename T, typename U,
    bool C = std::is_const_v<T>,
    bool V = std::is_volatile_v<T>>
struct match_cv_qualifiers
{using type = cv_selector_t<U, C, V>;};

template <typename T, typename U>
using copy_cv_t = typename match_cv_qualifiers<T, U>::type;

template <typename T>
struct xref
{
    template <typename U>
    using type = copy_cv_t<T, U>;
};

template <typename T>
struct xref<T&>
{
    template <typename U>
    using type = copy_cv_t<T, U>&;
};

template <typename T>
struct xref<T&&>
{
    template <typename U>
    using type = copy_cv_t<T, U>&&;
};

template <typename T>
using xref_t = typename xref<T>::type;

template <typename T, typename U>
struct same_as : std::conjunction<std::is_same<T, U>, std::is_same<U, T>> {};

template <typename T, typename U>
inline constexpr bool same_as_v = same_as<T, U>::value;

template <typename, typename, typename = void>
struct convertible_to : std::false_type {};

template <typename T, typename U>
using cast_operation = decltype(static_cast<U>(std::declval<T>()));

template <typename T, typename U>
struct convertible_to<T, U, 
std::void_t<cast_operation<T, U>>> 
: std::conjunction<std::is_convertible<T, U>,
    std::is_same<cast_operation<T, U>, U>> {};

template <typename T, typename U>
inline constexpr bool convertible_to_v = convertible_to<T, U>::value;

template <typename T>
inline constexpr auto declare_value() -> T;

template <typename T, typename U>
using cond_res = decltype(false ? std::declval<T(&)()>()() : std::declval<U(&)()>()());

template <typename T, typename U>
using cond_res_cvref = cond_res<copy_cv_t<T, U>&, copy_cv_t<U, T>&>;

namespace detail
{
    template <typename T, typename U, typename = void>
    struct common_reference_impl {};
    template <typename T, typename U>
    using common_reference = typename common_reference_impl<T, U>::type;
    template <typename T, typename U>
    struct common_reference_impl<T&, U&, std::void_t<cond_res_cvref<T, U>>>
    : std::enable_if<std::is_reference_v<cond_res_cvref<T, U>>, cond_res_cvref<T, U>> {};
    template <typename T, typename U>
    using common_reference_c = std::remove_reference_t<common_reference<T&, U&>>&&;
    template <typename T, typename U>
    struct common_reference_impl<T&&, U&&, std::enable_if_t<
        std::is_convertible_v<T&&, common_reference_c<T, U>> &&
        std::is_convertible_v<U&&, common_reference_c<T, U>>>>
    {using type = common_reference_c<T, U>;};
    template <typename T, typename U>
    using common_reference_d = common_reference<const T&, U&>;
    template <typename T, typename U>
    struct common_reference_impl<T&&, U&, std::enable_if_t<
        std::is_convertible_v<T&&, common_reference_d<T, U>>>>
    {using type = common_reference_d<T, U>;};
    template <typename T, typename U>
    struct common_reference_impl<T&, U&&> : 
        common_reference_impl<U&&, T&> {};
    template <typename T, typename U,
        template <typename> typename TQ, 
        template <typename> typename UQ>
    struct basic_common_reference {};
};

template <typename T, typename U>
using basic_common_reference = typename
    detail::basic_common_reference<
        remove_cvref_t<T>,
        remove_cvref_t<U>,
        xref<T>::template type,
        xref<U>::template type>::type;

template <typename... V>
struct common_reference;

template <typename... V>
using common_reference_t = typename common_reference<V...>::type;

template <>
struct common_reference<> {};

template <typename T>
struct common_reference<T>
{using type = T;};

template <typename T, typename U, int Index = 1, typename = void>
struct common_reference_impl
: common_reference_impl<T, U, Index + 1> {};

template <typename T, typename U>
struct common_reference<T, U> :
common_reference_impl<T, U> {};

template <typename T, typename U>
struct common_reference_impl<T&, U&, 1,
    std::void_t<detail::common_reference<T&, U&>>>
{using type = detail::common_reference<T&, U&>;};

template <typename T, typename U>
struct common_reference_impl<T&&, U&&, 1,
    std::void_t<detail::common_reference<T&&, U&&>>>
{using type = detail::common_reference<T&&, U&&>;};

template <typename T, typename U>
struct common_reference_impl<T&, U&&, 1,
    std::void_t<detail::common_reference<T&, U&&>>>
{using type = detail::common_reference<T&, U&&>;};

template <typename T, typename U>
struct common_reference_impl<T&&, U&, 1,
    std::void_t<detail::common_reference<T&&, U&>>>
{using type = detail::common_reference<T&&, U&>;};

template<typename T, typename U>
struct common_reference_impl<T, U, 2,
    std::void_t<basic_common_reference<T, U>>>
{using type = basic_common_reference<T, U>;};

template<typename T, typename U>
struct common_reference_impl<T, U, 3,
    std::void_t<cond_res<T, U>>>
{using type = cond_res<T, U>;};

template<typename T, typename U>
struct common_reference_impl<T, U, 4,
    std::void_t<std::common_type_t<T, U>>>
{using type = std::common_type_t<T, U>;};

template<typename T, typename U>
struct common_reference_impl<T, U, 5, void>
{};

template <typename T, typename U, typename... V>
struct common_reference<T, U, V...>
: std::__common_type_fold<common_reference<T, U>, 
std::__common_type_pack<V...>> {};

template<typename T, typename U, typename... V>
struct std::__common_type_fold<common_reference<T, U>,
std::__common_type_pack<V...>, std::void_t<common_reference_t<T, U>>>
: public common_reference<common_reference_t<T, U>, V...>
{};

template <typename, typename, typename = void>
struct common_reference_with : std::false_type {};

template <typename T, typename U>
struct common_reference_with<T, U, std::void_t<typename common_reference<T, U>::type>>
: std::conjunction<same_as<common_reference_t<T, U>, common_reference_t<U, T>>,
convertible_to<T, common_reference_t<T, U>>, convertible_to<U, common_reference_t<T, U>>> {};

template <typename T, typename U>
inline constexpr bool common_reference_with_v = common_reference_with<T, U>::value;

template <typename T, typename U>
inline constexpr auto assignment_operation(T t, U&& u,
    std::void_t<decltype(t = std::forward<U>(u))>* = 0) -> T;

template <typename T, typename U>
struct assignable_from : std::conjunction<
    std::is_lvalue_reference<T>,
    same_as<decltype(
        assignment_operation<T, U>(
        std::declval<T>(),
        std::declval<U&&>())), T>,
    common_reference_with<
        const std::remove_reference_t<T>&,
        const std::remove_reference_t<U>&>>
    {};

template <typename T, typename U>
inline constexpr bool assignable_from_v = assignable_from<T, U>::value;

template <typename T, typename... V>
inline constexpr bool constructible_from_v = 
    std::is_nothrow_destructible_v<T> &&
    std::is_constructible_v<T, V...>;

template <typename T>
inline constexpr bool move_constructible_v =
    constructible_from_v<T, T> &&
    convertible_to_v<T, T>;

template <typename T>
inline constexpr bool copy_constructible_v = 
    move_constructible_v<T> &&
    constructible_from_v<T, T&> && convertible_to_v<T&, T> &&
    constructible_from_v<T, const T&> && convertible_to_v<const T&, T> &&
    constructible_from_v<T, const T> && convertible_to_v<const T, T>;

template <typename T>
inline constexpr bool movable_v = 
    is_swappable_v<T> &&
    move_constructible_v<T> &&
    assignable_from_v<T&, T> &&
    std::is_object_v<T>;

template <typename T>
inline constexpr bool copyable_v = 
    copy_constructible_v<T> &&
    movable_v<T> &&
    assignable_from_v<T&, T&> &&
    assignable_from_v<T&, const T&> &&
    assignable_from_v<T&, const T>;

#pragma endregion

#endif