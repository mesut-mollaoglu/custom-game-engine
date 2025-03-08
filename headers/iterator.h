#ifndef ITERATOR_H
#define ITERATOR_H

template <typename, typename = std::void_t<>>
struct has_base : std::false_type {};

template <typename T>
struct has_base<T, std::void_t<decltype(std::declval<T>().base())>>
: std::true_type {};

template <typename T>
class Iterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using const_pointer = const T*;
    using const_reference = const T&;
    using difference_type = std::ptrdiff_t;
public:
    template <typename _Container, 
        template <typename, typename> typename _Iter, 
        typename U = T>
    inline constexpr Iterator(
        const _Iter<U, _Container>& iter,
        typename std::enable_if_t<
            is_container_v<_Container> && 
            are_same_tpl<_Iter<U, _Container>, typename _Container::iterator>::value>* = 0) 
    noexcept : m_ptr(&(*iter)) {}
    inline constexpr Iterator(pointer ptr = nullptr) : m_ptr(ptr) {}
    inline constexpr Iterator(const Iterator<T>& lhs) = default;
    inline constexpr Iterator(Iterator<T>&& lhs) = default;
    inline constexpr Iterator<T>& operator=(const Iterator<T>& lhs) = default;
    inline constexpr operator const_pointer() const {return m_ptr;}
    inline constexpr operator pointer() {return m_ptr;}
    inline constexpr pointer ptr() const {return m_ptr;}
    inline constexpr const_pointer c_ptr() const {return m_ptr;}
    virtual inline constexpr reference operator*() {return *m_ptr;}
    virtual inline constexpr const_reference operator*() const {return *m_ptr;}
    virtual inline constexpr pointer operator->() {return m_ptr;}
    inline constexpr difference_type operator-(const Iterator<T>& lhs) const 
    {return m_ptr - lhs.ptr();}
    inline constexpr Iterator<T>& operator=(pointer ptr)
    {
        m_ptr = ptr; 
        return *this;
    }
    inline constexpr Iterator<T>&
    operator+=(const difference_type& n)
    {
        m_ptr += n; 
        return *this;
    }
    inline constexpr Iterator<T>&
    operator-=(const difference_type& n)
    {
        m_ptr -= n; 
        return *this;
    }
    inline constexpr Iterator<T>& operator++()
    {
        ++m_ptr; 
        return *this;
    }
    inline constexpr Iterator<T>& operator--()
    {
        --m_ptr; 
        return *this;
    }
    inline constexpr Iterator<T> operator++(int)
    {
        Iterator<T> res = *this; 
        ++m_ptr; 
        return res;
    }
    inline constexpr Iterator<T> operator--(int)
    {
        Iterator<T> res = *this; 
        --m_ptr; 
        return res;
    }
    inline constexpr const_reference
    operator[](const difference_type& n) const
    {
        return *(*this + n);
    }
    inline constexpr reference 
    operator[](const difference_type& n)
    {
        return *(*this + n);
    }
    template <typename F, typename = typename std::enable_if_t<std::is_convertible_v<T, F>>>
    inline constexpr operator Iterator<F>() const
    {
        return Iterator<F>(static_cast<F*>(m_ptr));
    }
protected:
    pointer m_ptr;
};

template<typename T>
class ReverseIterator : public Iterator<T>
{
public:
    using typename Iterator<T>::const_reference;
    using typename Iterator<T>::const_pointer;
    using typename Iterator<T>::reference;
    using typename Iterator<T>::pointer;
    using typename Iterator<T>::difference_type;
public:
    template <typename _Container, 
        template <typename, typename> typename _Iter,
        template <typename> typename _ReverseIter, 
        typename U = T>
    inline constexpr ReverseIterator(
        const _ReverseIter<_Iter<U, _Container>>& iter,
        typename std::enable_if_t<
            is_container_v<_Container> && are_same_tpl<_Iter<U, _Container>, typename _Container::iterator>::value &&
            are_same_tpl<_ReverseIter<_Iter<U, _Container>>, typename _Container::reverse_iterator>::value &&  
            has_base<_ReverseIter<_Iter<U, _Container>>>::value>* = 0) noexcept 
        {*this = static_cast<ReverseIterator<T>>(iter.base());}
    inline constexpr ReverseIterator(pointer ptr = nullptr) : Iterator<T>(ptr) {}
    inline constexpr ReverseIterator(const Iterator<T>& lhs) {this->m_ptr = lhs.ptr();}
    inline constexpr ReverseIterator(const ReverseIterator<T>& lhs) = default;
    inline constexpr ReverseIterator(ReverseIterator<T>&& lhs) = default;
    inline constexpr ReverseIterator<T>& operator=(const ReverseIterator<T>& lhs) = default;
    inline constexpr difference_type operator-(const ReverseIterator<T>& lhs) const
    {return lhs.ptr() - this->m_ptr;}
    inline constexpr pointer operator->() override
    {return &(operator*());}
    inline constexpr ReverseIterator<T>& operator=(pointer ptr) 
    {
        this->m_ptr = ptr; 
        return *this;
    }
    inline constexpr ReverseIterator<T>& operator=(const Iterator<T>& lhs) 
    {
        this->m_ptr = lhs.ptr(); 
        return *this;
    }
    inline constexpr ReverseIterator<T>& operator++() 
    {
        --this->m_ptr; 
        return *this;
    }
    inline constexpr ReverseIterator<T>& operator--() 
    {
        ++this->m_ptr; 
        return *this;
    }
    inline constexpr reference operator*() override
    {
        Iterator<T> res = this->m_ptr;
        return *--res;
    }
    inline constexpr const_reference operator*() const override
    {
        Iterator<T> res = this->m_ptr;
        return *--res;
    }
    inline constexpr ReverseIterator<T> operator++(int)
    {
        ReverseIterator<T> res = *this;
        --this->m_ptr;
        return res;
    }
    inline constexpr ReverseIterator<T> operator--(int)
    {
        ReverseIterator<T> res = *this;
        ++this->m_ptr;
        return res;
    }
    inline constexpr ReverseIterator<T>& 
    operator+=(const difference_type& n) 
    {
        this->m_ptr -= n;
        return *this;
    }
    inline constexpr ReverseIterator<T>& 
    operator-=(const difference_type& n) 
    {
        this->m_ptr += n; 
        return *this;
    }
    inline constexpr pointer base() const
    {
        return this->m_ptr;
    }
    inline constexpr operator Iterator<T>() const
    {
        return base();
    }
    template <typename F, typename = typename std::enable_if_t<std::is_convertible_v<T, F>>>
    inline constexpr operator ReverseIterator<F>() const
    {
        return ReverseIterator<F>(static_cast<F*>(this->m_ptr));
    }
};

template <typename T>
inline constexpr Iterator<T> 
operator+(const typename Iterator<T>::difference_type& lhs, const Iterator<T>& rhs)
{
    Iterator<T> res = rhs;
    res += lhs;
    return res;
}    

template <typename T>
inline constexpr Iterator<T> 
operator-(const typename Iterator<T>::difference_type& lhs, const Iterator<T>& rhs)
{
    Iterator<T> res = rhs;
    res -= lhs;
    return res;
}

template <typename T>
inline constexpr Iterator<T> 
operator+(const Iterator<T>& lhs, const typename Iterator<T>::difference_type& rhs)
{
    Iterator<T> res = lhs;
    res += rhs;
    return res;
}

template <typename T>
inline constexpr Iterator<T> 
operator-(const Iterator<T>& lhs, const typename Iterator<T>::difference_type& rhs)
{
    Iterator<T> res = lhs;
    res -= rhs;
    return res;
}

template <typename T>
inline constexpr ReverseIterator<T> 
operator+(const typename ReverseIterator<T>::difference_type& lhs, const ReverseIterator<T>& rhs)
{
    ReverseIterator<T> res = rhs;
    res += lhs;
    return res;
}    

template <typename T>
inline constexpr ReverseIterator<T> 
operator-(const typename ReverseIterator<T>::difference_type& lhs, const ReverseIterator<T>& rhs)
{
    ReverseIterator<T> res = rhs;
    res -= lhs;
    return res;
}

template <typename T>
inline constexpr ReverseIterator<T> 
operator+(const ReverseIterator<T>& lhs, const typename ReverseIterator<T>::difference_type& rhs)
{
    ReverseIterator<T> res = lhs;
    res += rhs;
    return res;
}

template <typename T>
inline constexpr ReverseIterator<T> 
operator-(const ReverseIterator<T>& lhs, const typename ReverseIterator<T>::difference_type& rhs)
{
    ReverseIterator<T> res = lhs;
    res -= rhs;
    return res;
}

template <typename T>
inline constexpr bool operator==(const Iterator<T>& lhs, const Iterator<T>& rhs)
{return lhs.c_ptr() == rhs.c_ptr();}

template <typename T>
inline constexpr bool operator!=(const Iterator<T>& lhs, const Iterator<T>& rhs)
{return !(lhs == rhs);}

template <typename T>
inline constexpr bool operator<(const Iterator<T>& lhs, const Iterator<T>& rhs)
{return lhs.c_ptr() < rhs.c_ptr();}

template <typename T>
inline constexpr bool operator>(const Iterator<T>& lhs, const Iterator<T>& rhs)
{return lhs.c_ptr() > rhs.c_ptr();}

template <typename T>
inline constexpr bool operator<=(const Iterator<T>& lhs, const Iterator<T>& rhs)
{return lhs.c_ptr() <= rhs.c_ptr();}

template <typename T>
inline constexpr bool operator>=(const Iterator<T>& lhs, const Iterator<T>& rhs)
{return lhs.c_ptr() >= rhs.c_ptr();}

template <typename T>
inline constexpr bool operator==(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs)
{return lhs.base() == rhs.base();}

template <typename T>
inline constexpr bool operator!=(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs)
{return !(lhs == rhs);}

template <typename T>
inline constexpr bool operator<(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs)
{return rhs.base() < lhs.base();}

template <typename T>
inline constexpr bool operator>(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs)
{return rhs.base() > lhs.base();}

template <typename T>
inline constexpr bool operator<=(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs)
{return rhs.base() <= lhs.base();}

template <typename T>
inline constexpr bool operator>=(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs)
{return rhs.base() >= lhs.base();}

template <template <typename> typename IteratorType, typename T, typename U>
class IteratorPair
{
    static_assert(are_same_tpl<IteratorType<T>, Iterator<U>>::value || are_same_tpl<IteratorType<T>, ReverseIterator<U>>::value);
public:
    IteratorType<T> first;
    IteratorType<U> second;
public:
    using difference_type = typename IteratorType<T>::difference_type;
    template <typename A> 
    using pointer = typename IteratorType<A>::pointer;
    template <typename... A> 
    inline static constexpr bool all_container_v = std::conjunction_v<is_container<A>...>;
public:
    inline constexpr IteratorPair() = default;
    inline constexpr IteratorPair& operator=(const IteratorPair& p) = default;
    inline constexpr IteratorPair(const IteratorPair& p) = default;
    inline constexpr IteratorPair(IteratorPair&& p) = default;
    inline constexpr IteratorPair(const std::pair<pointer<T>, pointer<U>>& p) : first(p.first), second(p.second) {}
    inline constexpr IteratorPair(const pointer<T> first, const pointer<U> second) : first(first), second(second) {}
    template <typename First, typename Second, typename = typename std::enable_if_t<all_container_v<First, Second>>>
    inline constexpr IteratorPair(const typename First::iterator& first, const typename Second::iterator& second)
    : first(first), second(second) {}
    template <typename First, typename Second, typename = typename std::enable_if_t<all_container_v<First, Second>>>
    inline constexpr IteratorPair(const std::pair<typename First::iterator, typename Second::iterator>& p) 
    : first(p.first), second(p.second) {}
    inline constexpr IteratorPair(const IteratorType<T>& first, const IteratorType<U>& second)
    : first(first), second(second) {}
    template <template <typename> typename A = IteratorType>
    inline constexpr IteratorPair(
        const ReverseIterator<T>& first, 
        const ReverseIterator<U>& second,
        typename std::enable_if_t<are_same_tpl<A<T>, Iterator<U>>::value>* = 0)
    : first(first.base()), second(second.base()) {}
    template <template <typename> typename A = IteratorType>
    inline constexpr IteratorPair(
        const std::pair<ReverseIterator<T>, ReverseIterator<U>>& p,
        typename std::enable_if_t<are_same_tpl<A<T>, Iterator<U>>::value>* = 0)
    : first(p.first.base()), second(p.second.base()) {}
    template <template <typename> typename A = IteratorType>
    inline constexpr IteratorPair(
        const Iterator<T>& first, 
        const Iterator<U>& second,
        typename std::enable_if_t<are_same_tpl<A<T>, ReverseIterator<U>>::value>* = 0)
    : first(first), second(second) {}
    template <template <typename> typename A = IteratorType>
    inline constexpr IteratorPair(
        const std::pair<Iterator<T>, Iterator<U>>& p, 
        typename std::enable_if_t<are_same_tpl<A<T>, ReverseIterator<U>>::value>* = 0)
    : first(p.first), second(p.second) {}
public:
    inline constexpr IteratorPair& operator++()
    {
        ++first;
        ++second;
        return *this;
    }
    inline constexpr IteratorPair& operator--()
    {
        --first;
        --second;
        return *this;
    }
    inline constexpr IteratorPair operator++(int)
    {
        IteratorPair res;
        res.first = first++;
        res.second = second++;
        return res;
    }
    inline constexpr IteratorPair operator--(int)
    {
        IteratorPair res;
        res.first = first--;
        res.second = second--;
        return res;
    }
    inline constexpr IteratorPair& 
    operator+=(const difference_type& n)
    {
        first += n;
        second += n;
        return *this;
    }
    inline constexpr IteratorPair&
    operator-=(const difference_type& n)
    {
        first -= n;
        second -= n;
        return *this;
    }
    inline constexpr operator std::pair<T, U>() const
    {
        std::make_pair<T, U>(*first, *second);
    }
    inline constexpr operator 
    std::pair<IteratorType<T>, IteratorType<U>>() const
    {
        return std::make_pair(first, second);
    }
    inline constexpr std::pair<difference_type, difference_type> 
    operator-(const IteratorPair<IteratorType, T, U>& iter)
    {
        return std::make_pair(first - iter.first, second - iter.second);
    }
};

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr IteratorPair<IteratorType, T, U> 
operator+(const typename IteratorPair<IteratorType, T, U>::difference_type& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{
    IteratorPair<IteratorType, T, U> res = rhs;
    res += lhs;
    return res;
}    

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr IteratorPair<IteratorType, T, U>  
operator-(const typename IteratorPair<IteratorType, T, U>::difference_type& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{
    IteratorPair<IteratorType, T, U> res = rhs;
    res -= lhs;
    return res;
}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr IteratorPair<IteratorType, T, U> 
operator+(const IteratorPair<IteratorType, T, U>& lhs, const typename IteratorPair<IteratorType, T, U>::difference_type& rhs)
{
    IteratorPair<IteratorType, T, U> res = lhs;
    res += rhs;
    return res;
}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr IteratorPair<IteratorType, T, U> 
operator-(const IteratorPair<IteratorType, T, U>& lhs, const typename IteratorPair<IteratorType, T, U>::difference_type& rhs)
{
    IteratorPair<IteratorType, T, U> res = lhs;
    res -= rhs;
    return res;
}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr bool operator==(const IteratorPair<IteratorType, T, U>& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{return lhs.first.c_ptr() == rhs.first.c_ptr() && lhs.second.c_ptr() == rhs.second.c_ptr();}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr bool operator!=(const IteratorPair<IteratorType, T, U>& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{return !(lhs == rhs);}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr bool operator<(const IteratorPair<IteratorType, T, U>& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{return lhs.first.c_ptr() < rhs.first.c_ptr() && lhs.second.c_ptr() < rhs.second.c_ptr();}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr bool operator>(const IteratorPair<IteratorType, T, U>& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{return lhs.first.c_ptr() > rhs.first.c_ptr() && lhs.second.c_ptr() > rhs.second.c_ptr();}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr bool operator<=(const IteratorPair<IteratorType, T, U>& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{return lhs.first.c_ptr() <= rhs.first.c_ptr() && lhs.second.c_ptr() <= rhs.second.c_ptr();}

template <template <typename> typename IteratorType, typename T, typename U>
inline constexpr bool operator>=(const IteratorPair<IteratorType, T, U>& lhs, const IteratorPair<IteratorType, T, U>& rhs)
{return lhs.first.c_ptr() >= rhs.first.c_ptr() && lhs.second.c_ptr() >= rhs.second.c_ptr();}

template <typename T>
inline constexpr Iterator<T> find(
    Iterator<T> first,
    Iterator<T> last,
    const T& value)
{
    for(; first != last; first++)
        if(*first == value)
            return first;
    return last;
}

template <typename T>
inline constexpr Iterator<T> find_if(
    Iterator<T> first,
    Iterator<T> last,
    const std::function<bool(T)>& p)
{
    for(; first != last; first++)
        if(p(*first))
            return first;
    return last;
}

template <typename T>
inline constexpr Iterator<T> find_if_not(
    Iterator<T> first,
    Iterator<T> last,
    const std::function<bool(T)>& q)
{
    for(; first != last; first++)
        if(!q(*first))
            return first;
    return last;
}

#endif