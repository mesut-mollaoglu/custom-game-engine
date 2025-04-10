#ifndef FIXED_SIZE_STRING_H
#define FIXED_SIZE_STRING_H

template <typename _CharT, usize N, typename Traits = std::char_traits<_CharT>>
class fs_string
{
    using traits = Traits;
    using value_type = _CharT;
    using pointer = _CharT*;
    using reference = _CharT&;
    using const_pointer = const _CharT*;
    using const_reference = const _CharT&;
    using iterator = Iterator<_CharT>;
    using const_iterator = Iterator<const _CharT>;
    using reverse_iterator = ReverseIterator<_CharT>;
    using const_reverse_iterator = ReverseIterator<const _CharT>;
    static inline constexpr usize len = N - 1;
private:
    _CharT _data[N];
public:
    inline constexpr fs_string(const fs_string& str) = default;
    inline constexpr fs_string(fs_string&& str) = default;
    inline constexpr fs_string& operator=(const fs_string& str) = default;
    inline constexpr fs_string& operator=(fs_string&& str) = default;
    inline constexpr fs_string(const _CharT(&str)[N])
    {
        for(usize i = 0; i < N; i++)
            _data[i] = str[i];
    }
    inline constexpr fs_string& operator=(const _CharT(&str)[N])
    {
        for(usize i = 0; i < N; i++)
            _data[i] = str[i];
        return *this;
    }
public:
    inline constexpr iterator begin() {return data();}
    inline constexpr iterator end() {return begin() + len;}
    inline constexpr reverse_iterator rbegin() {return end();}
    inline constexpr reverse_iterator rend() {return begin();}
    inline constexpr const_iterator cbegin() {return data();}
    inline constexpr const_iterator cend() {return cbegin() + len;}
    inline constexpr const_reverse_iterator crbegin() {return cend();}
    inline constexpr const_reverse_iterator crend() {return cbegin();}
public:
    inline constexpr usize size() {return len;}
    inline constexpr usize length() {return len;}
    inline constexpr bool empty() {return len == 0;}
    inline constexpr _CharT* data() {return &_data[0];}
public:
    template <usize M>
    inline friend constexpr bool operator==(const fs_string<_CharT, N>& lhs, const fs_string<_CharT, M>& rhs)
    {
        return N == M && !traits::compare(lhs.data(), rhs.data(), len);
    }
    template <usize M>
    inline friend constexpr bool operator==(const fs_string<_CharT, N>& lhs, const _CharT(&rhs)[M])
    {
        return N == M && !traits::compare(lhs.data(), &rhs[0], len);
    }
    template <usize M>
    inline friend constexpr bool operator==(const _CharT(&lhs)[N], const fs_string<_CharT, M>& rhs)
    {
        return N == M && !traits::compare(&lhs[0], rhs.data(), len);
    }
};

#endif