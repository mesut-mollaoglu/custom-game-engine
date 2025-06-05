#ifndef FIXED_SIZE_STRING_H
#define FIXED_SIZE_STRING_H

template <usize N, typename CharT = char, typename Traits = std::char_traits<CharT>>
class fs_string
{
public:
//typedefs
    using traits = Traits;
    using size_type = usize;
    using difference_type = isize;
    using value_type = CharT;
    using pointer = CharT*;
    using reference = CharT&;
    using const_pointer = const CharT*;
    using const_reference = const CharT&;
    using iterator = Iterator<CharT>;
    using const_iterator = Iterator<const CharT>;
    using reverse_iterator = ReverseIterator<CharT>;
    using const_reverse_iterator = ReverseIterator<const CharT>;
    static inline constexpr size_type len = N - 1;
    static inline constexpr size_type npos = static_cast<size_type>(-1);
    static inline constexpr bool check_len(
        const size_type& num,
        const size_type& lo = min_value<size_type>,
        const size_type& hi = max_value<size_type>)
    {
        return num < hi && num >= lo;
    }
private:
    CharT m_data[N];
public:
//constructors and assignment operator overloads
    inline constexpr fs_string(const fs_string& str) = default;
    inline constexpr fs_string(fs_string&& str) = default;
    inline constexpr fs_string& operator=(const fs_string& str) = default;
    inline constexpr fs_string& operator=(fs_string&& str) = default;
    inline constexpr fs_string(const CharT(&str)[N])
    {
        for(size_type i = 0; i < N; i++)
            m_data[i] = str[i];
    }
    inline constexpr fs_string& operator=(const CharT(&str)[N])
    {
        for(size_type i = 0; i < N; i++)
            m_data[i] = str[i];
        return *this;
    }
public:
//iterators
    inline constexpr iterator begin() {return data();}
    inline constexpr iterator end() {return begin() + len;}
    inline constexpr reverse_iterator rbegin() {return end();}
    inline constexpr reverse_iterator rend() {return begin();}
    inline constexpr const_iterator cbegin() const {return data();}
    inline constexpr const_iterator cend() const {return cbegin() + len;}
    inline constexpr const_reverse_iterator crbegin() const {return cend();}
    inline constexpr const_reverse_iterator crend() const {return cbegin();}
public:
    inline constexpr size_type size() const {return len;}
    inline constexpr size_type length() const {return len;}
    inline constexpr bool empty() const {return len == 0;}
    inline constexpr const_pointer data() const {return &m_data[0];}
    inline constexpr pointer data() {return &m_data[0];}
public:
//index operator
    inline constexpr CharT& operator[](const size_type& idx)
    {
        if(idx < len)
            return m_data[idx];
        else
            throw std::out_of_range("index out of range");
    }
    inline constexpr const CharT& operator[](const size_type& idx) const
    {
        if(idx < len)
            return m_data[idx];
        else
            throw std::out_of_range("index out of range");
    }
public:
//equals operator
    template <size_type M>
    inline friend constexpr bool operator==(const fs_string<N, CharT>& lhs, const fs_string<M, CharT>& rhs)
    {
        return N == M && !traits::compare(lhs.data(), rhs.data(), len);
    }
    template <size_type M>
    inline friend constexpr bool operator==(const fs_string<N, CharT>& lhs, const CharT(&rhs)[M])
    {
        return N == M && !traits::compare(lhs.data(), &rhs[0], len);
    }
    template <size_type M>
    inline friend constexpr bool operator==(const CharT(&lhs)[N], const fs_string<M, CharT>& rhs)
    {
        return N == M && !traits::compare(&lhs[0], rhs.data(), len);
    }
public:
//find
    inline constexpr size_type find(const_reference c, const size_type& pos = 0) const
    {
        if(!check_len(pos, 0, len))
            return npos;
        for(size_type i = pos; i < len; i++)
            if(traits::eq((*this)[i], c))
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find(const fs_string<M, CharT>& s, const size_type& pos = 0) const
    {
        if(!check_len(pos, 0, len) || !check_len(pos + s.length() - 1, 0, len))
            return npos;
        for(size_type i = pos; i < len; i++)
            if(!traits::compare(&(*this)[i], s.data(), s.length()))
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find(const CharT(&str)[M], const size_type& pos = 0) const
    {
        return this->find(fs_string<M, CharT>(str), pos);
    }
public:
//find_first_of
    inline constexpr size_type find_first_of(const_reference c, const size_type& pos = 0) const
    {
        if(!check_len(pos, 0, len))
            return npos;
        for(size_type i = pos; i < len; i++)
            if(traits::eq((*this)[i], c))
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_first_of(const fs_string<M, CharT>& s, const size_type& pos = 0) const
    {
        if(!check_len(pos, 0, len) || !check_len(pos + s.length() - 1, 0, len))
            return npos;
        for(size_type i = pos; i < len; i++)
            if(s.find((*this)[i]) != npos)
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_first_of(const CharT(&str)[M], const size_type& pos = 0) const
    {
        return this->find_first_of(fs_string<M, CharT>(str), pos);
    }
public:
//find_last_of
    inline constexpr size_type find_last_of(const_reference c, const size_type& pos = npos) const
    {
        size_type i = std::min(pos, len - 1);
        for(; i >= 0; i--)
            if(traits::eq((*this)[i], c))
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_last_of(const fs_string<M, CharT>& s, const size_type& pos = npos) const
    {
        size_type i = std::min(pos, len - 1);
        for(; i >= 0; i--)
            if(s.find((*this)[i]) != npos)
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_last_of(const CharT(&str)[M], const size_type& pos = npos) const
    {
        return this->find_last_of(fs_string<M, CharT>(str), pos);
    }
public:
//find_first_not_of
    inline constexpr size_type find_first_not_of(const_reference c, const size_type& pos = 0) const
    {
        if(!check_len(pos, 0, len))
            return npos;
        for(size_type i = pos; i < len; i++)
            if(!traits::eq((*this)[i], c))
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_first_not_of(const fs_string<M, CharT>& s, const size_type& pos = 0) const
    {
        if(!check_len(pos, 0, len) || !check_len(pos + s.length() - 1, 0, len))
            return npos;
        for(size_type i = pos; i < len; i++)
            if(s.find((*this)[i]) == npos)
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_first_not_of(const CharT(&str)[M], const size_type& pos = 0) const
    {
        return this->find_first_not_of(fs_string<M, CharT>(str), pos);
    }
public:
//find_last_not_of
    inline constexpr size_type find_last_not_of(const_reference c, const size_type& pos = npos) const
    {
        size_type i = std::min(pos, len - 1);
        for(; i >= 0; i--)
            if(!traits::eq((*this)[i], c))
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_last_not_of(const fs_string<M, CharT>& s, const size_type& pos = npos) const
    {
        size_type i = std::min(pos, len - 1);
        for(; i >= 0; i--)
            if(s.find((*this)[i]) == npos)
                return i;
        return npos;
    }
    template <size_type M>
    inline constexpr size_type find_last_not_of(const CharT(&str)[M], const size_type& pos = npos) const
    {
        return this->find_last_not_of(fs_string<M, CharT>(str), pos);
    }
public:
//substr
    template <size_type M>
    inline constexpr fs_string<M, CharT> substr(const size_type& pos = 0) const
    {
        assert(M <= N && check_len(pos, 0, len));
        fs_string<M, CharT> res;
        for(size_type i = 0; i < res.length(); i++)
            res[i] = (*this)[pos + i];
        return res;
    }
public:
//ostream & istream
    inline friend std::basic_ostream<CharT>&
    operator<<(std::basic_ostream<CharT>& os, const fs_string<N, CharT>& s)
    {
        os.write(s.data(), s.length());
        return os;
    }
    inline friend std::basic_istream<CharT>&
    operator>>(std::basic_istream<CharT>& is, fs_string<N, CharT>& s)
    {
        is.read(s.data(), s.length());
        return is;
    }
};

#endif