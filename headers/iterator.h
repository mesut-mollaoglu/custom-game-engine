#ifndef ITERATOR_H
#define ITERATOR_H

template <typename, typename = void>
struct has_base : std::false_type {};

template <typename T>
struct has_base<T, std::void_t<decltype(std::declval<T>().base())>>
: std::true_type {};

template <typename T>
inline constexpr bool has_base_v = has_base<T>::value;

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
    using difference_type = isize;
public:
    template <
        typename CT, 
        template <typename, typename> typename IterT, 
        typename U = T>
    inline constexpr Iterator(
        const IterT<U, CT>& iter,
        std::enable_if_t<is_container_v<CT> && 
        are_templates_same_v<IterT<U, CT>, decltype(std::declval<CT>().begin())>>* = 0) 
    noexcept : Iterator<T>(&(*iter)) {}
    inline constexpr Iterator(pointer ptr = nullptr) noexcept : m_ptr(ptr) {}
    inline constexpr Iterator(const Iterator<T>& lhs) noexcept = default;
    inline constexpr Iterator(Iterator<T>&& lhs) noexcept = default;
    inline constexpr Iterator<T>& operator=(const Iterator<T>& lhs) noexcept = default;
    inline constexpr Iterator<T>& operator=(Iterator<T>&& lhs) noexcept = default;
    inline constexpr operator const_pointer() const noexcept {return m_ptr;}
    inline constexpr operator pointer() noexcept {return m_ptr;}
    inline constexpr pointer ptr() const noexcept {return m_ptr;}
    inline constexpr const_pointer c_ptr() const noexcept {return m_ptr;}
    virtual inline constexpr reference operator*() noexcept {return *m_ptr;}
    virtual inline constexpr pointer operator->() noexcept {return m_ptr;}
    virtual inline constexpr const_reference operator*() const noexcept {return *m_ptr;}
    virtual inline constexpr const_pointer operator->() const noexcept {return m_ptr;}
    inline constexpr difference_type
    operator-(const Iterator<T>& lhs) const noexcept
    {
        return std::distance(m_ptr, lhs.ptr());
    }
    inline constexpr Iterator<T>& operator=(pointer ptr) noexcept
    {
        m_ptr = ptr; 
        return *this;
    }
    inline constexpr Iterator<T>&
    operator+=(const difference_type& n) noexcept
    {
        m_ptr = std::advance(m_ptr, n);
        return *this;
    }
    inline constexpr Iterator<T>&
    operator-=(const difference_type& n) noexcept
    {
        m_ptr = std::advance(m_ptr, -n);
        return *this;
    }
    inline constexpr Iterator<T>& operator++() noexcept
    {
        m_ptr = std::next(m_ptr); 
        return *this;
    }
    inline constexpr Iterator<T>& operator--() noexcept
    {
        m_ptr = std::prev(m_ptr); 
        return *this;
    }
    inline constexpr Iterator<T> operator++(int) noexcept
    {
        Iterator<T> res = *this; 
        m_ptr = std::next(m_ptr); 
        return res;
    }
    inline constexpr Iterator<T> operator--(int) noexcept
    {
        Iterator<T> res = *this; 
        m_ptr = std::prev(m_ptr); 
        return res;
    }
    inline constexpr const_reference
    operator[](const difference_type& n) const noexcept
    {
        return *(*this + n);
    }
    inline constexpr reference 
    operator[](const difference_type& n) noexcept
    {
        return *(*this + n);
    }
    template <
        typename CT,
        template <typename, typename> typename IterT,
        typename U = T,
        typename CIterT = decltype(std::declval<CT>().begin()),
        typename = std::enable_if_t<is_container_v<CT> &&
        are_templates_same_v<IterT<U, CT>, CIterT>>>
    inline constexpr operator CIterT() const noexcept
    {
        return m_ptr;
    }
protected:
    pointer m_ptr;
};

template<typename T>
class ReverseIterator : public Iterator<T>
{
public:
    using typename Iterator<T>::iterator_category;
    using typename Iterator<T>::const_reference;
    using typename Iterator<T>::const_pointer;
    using typename Iterator<T>::reference;
    using typename Iterator<T>::pointer;
    using typename Iterator<T>::difference_type;
public:
    template <
        typename CT, 
        template <typename, typename> typename IterT,
        template <typename> typename RevIterT, 
        typename U = T,
        typename IT = IterT<U, CT>,
        typename RevIT = RevIterT<IT>>
    inline constexpr ReverseIterator(
        const RevIT& iter,
        std::enable_if_t<is_container_v<CT> &&
        are_templates_same_v<IterT<U, CT>, decltype(std::declval<CT>().begin())> &&
        are_templates_same_v<RevIterT<IterT<U, CT>>, decltype(std::declval<CT>().rbegin())> &&  
        has_base_v<RevIterT<IterT<U, CT>>>>* = 0) noexcept 
        : ReverseIterator<T>(iter.base()) {}
    inline constexpr ReverseIterator(pointer ptr = nullptr) noexcept : Iterator<T>(ptr) {}
    inline constexpr ReverseIterator(const Iterator<T>& lhs) noexcept {this->m_ptr = lhs.ptr();}
    inline constexpr ReverseIterator(const ReverseIterator<T>& lhs) noexcept = default;
    inline constexpr ReverseIterator(ReverseIterator<T>&& lhs) noexcept = default;
    inline constexpr ReverseIterator<T>& operator=(const ReverseIterator<T>& lhs) noexcept = default;
    inline constexpr difference_type
    operator-(const ReverseIterator<T>& lhs) const noexcept
    {
        return std::distance(lhs.ptr(), this->m_ptr);
    }
    inline constexpr pointer
    operator->() noexcept override
    {
        return &(operator*());
    }
    inline constexpr const_pointer
    operator->() const noexcept override
    {
        return &(operator*());
    }
    inline constexpr ReverseIterator<T>&
    operator=(pointer ptr) noexcept
    {
        this->m_ptr = ptr; 
        return *this;
    }
    inline constexpr ReverseIterator<T>&
    operator=(const Iterator<T>& lhs) noexcept
    {
        this->m_ptr = lhs.ptr(); 
        return *this;
    }
    inline constexpr ReverseIterator<T>& operator++() noexcept 
    {
        this->m_ptr = std::prev(this->m_ptr); 
        return *this;
    }
    inline constexpr ReverseIterator<T>& operator--() noexcept
    {
        this->m_ptr = std::next(this->m_ptr); 
        return *this;
    }
    inline constexpr ReverseIterator<T> operator++(int) noexcept
    {
        ReverseIterator<T> res = *this;
        this->m_ptr = std::prev(this->m_ptr);
        return res;
    }
    inline constexpr ReverseIterator<T> operator--(int) noexcept
    {
        ReverseIterator<T> res = *this;
        this->m_ptr = std::next(this->m_ptr);
        return res;
    }
    inline constexpr reference
    operator*() noexcept override
    {
        Iterator<T> res = this->m_ptr;
        return *--res;
    }
    inline constexpr const_reference
    operator*() const noexcept override
    {
        Iterator<T> res = this->m_ptr;
        return *--res;
    }
    inline constexpr ReverseIterator<T>& 
    operator+=(const difference_type& n) noexcept
    {
        this->m_ptr = std::advance(this->m_ptr, -n);
        return *this;
    }
    inline constexpr ReverseIterator<T>& 
    operator-=(const difference_type& n) noexcept
    {
        this->m_ptr = std::advance(this->m_ptr, n); 
        return *this;
    }
    inline constexpr pointer base() const noexcept
    {
        return this->m_ptr;
    }
    inline constexpr operator Iterator<T>() const noexcept
    {
        return this->base();
    }
    template <
        typename CT,
        template <typename, typename> typename IterT,
        template <typename> typename RevIterT,
        typename U = T,
        typename CRevIterT = decltype(std::declval<CT>().rbegin()),
        typename = std::enable_if_t<is_container_v<CT> &&
        has_base_v<RevIterT<IterT<U, CT>>> &&
        are_templates_same_v<RevIterT<IterT<U, CT>>, CRevIterT>>>
    inline constexpr operator CRevIterT() const noexcept
    {
        return this->base();
    }
};

template <typename T, typename difference_type = typename Iterator<T>::difference_type>
inline constexpr Iterator<T> 
operator+(const difference_type& lhs, const Iterator<T>& rhs)
{
    Iterator<T> res = rhs;
    res += lhs;
    return res;
}

template <typename T, typename difference_type = typename Iterator<T>::difference_type>
inline constexpr Iterator<T> 
operator+(const Iterator<T>& lhs, const difference_type& rhs) noexcept
{
    Iterator<T> res = lhs;
    res += rhs;
    return res;
}

template <typename T, typename difference_type = typename Iterator<T>::difference_type>
inline constexpr Iterator<T> 
operator-(const Iterator<T>& lhs, const difference_type& rhs) noexcept
{
    Iterator<T> res = lhs;
    res -= rhs;
    return res;
}

template <typename T, typename difference_type = typename ReverseIterator<T>::difference_type>
inline constexpr ReverseIterator<T> 
operator+(const difference_type& lhs, const ReverseIterator<T>& rhs) noexcept
{
    ReverseIterator<T> res = rhs;
    res += lhs;
    return res;
}    

template <typename T, typename difference_type = typename ReverseIterator<T>::difference_type>
inline constexpr ReverseIterator<T> 
operator+(const ReverseIterator<T>& lhs, const difference_type& rhs) noexcept
{
    ReverseIterator<T> res = lhs;
    res += rhs;
    return res;
}

template <typename T, typename difference_type = typename ReverseIterator<T>::difference_type>
inline constexpr ReverseIterator<T> 
operator-(const ReverseIterator<T>& lhs, const difference_type& rhs) noexcept
{
    ReverseIterator<T> res = lhs;
    res -= rhs;
    return res;
}

template <typename T>
inline constexpr bool operator==(const Iterator<T>& lhs, const Iterator<T>& rhs) noexcept
{return lhs.c_ptr() == rhs.c_ptr();}

template <typename T>
inline constexpr bool operator!=(const Iterator<T>& lhs, const Iterator<T>& rhs) noexcept
{return !(lhs == rhs);}

template <typename T>
inline constexpr bool operator<(const Iterator<T>& lhs, const Iterator<T>& rhs) noexcept
{return lhs.c_ptr() < rhs.c_ptr();}

template <typename T>
inline constexpr bool operator>(const Iterator<T>& lhs, const Iterator<T>& rhs) noexcept
{return lhs.c_ptr() > rhs.c_ptr();}

template <typename T>
inline constexpr bool operator<=(const Iterator<T>& lhs, const Iterator<T>& rhs) noexcept
{return lhs.c_ptr() <= rhs.c_ptr();}

template <typename T>
inline constexpr bool operator>=(const Iterator<T>& lhs, const Iterator<T>& rhs) noexcept
{return lhs.c_ptr() >= rhs.c_ptr();}

template <typename T>
inline constexpr bool operator==(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs) noexcept
{return lhs.base() == rhs.base();}

template <typename T>
inline constexpr bool operator!=(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs) noexcept
{return !(lhs == rhs);}

template <typename T>
inline constexpr bool operator<(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs) noexcept
{return rhs.base() < lhs.base();}

template <typename T>
inline constexpr bool operator>(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs) noexcept
{return rhs.base() > lhs.base();}

template <typename T>
inline constexpr bool operator<=(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs) noexcept
{return rhs.base() <= lhs.base();}

template <typename T>
inline constexpr bool operator>=(const ReverseIterator<T>& lhs, const ReverseIterator<T>& rhs) noexcept
{return rhs.base() >= lhs.base();}

template <template <typename> typename IteratorType, typename T, typename U>
class IteratorPair
{
    static_assert(std::is_same_v<IteratorType<T>, Iterator<T>> || 
        std::is_same_v<IteratorType<T>, ReverseIterator<T>>);
public:
    IteratorType<T> first;
    IteratorType<U> second;
public:
    using difference_type = isize;
    template <typename Q> 
    using pointer = typename IteratorType<Q>::pointer;
public:
    inline constexpr IteratorPair() noexcept = default;
    inline constexpr IteratorPair& operator=(const IteratorPair& p) noexcept = default;
    inline constexpr IteratorPair(const IteratorPair& p) noexcept = default;
    inline constexpr IteratorPair(IteratorPair&& p) noexcept = default;
    inline constexpr IteratorPair(const std::pair<pointer<T>, pointer<U>>& p) noexcept
    : IteratorPair(p.first, p.second) {}
    inline constexpr IteratorPair(const pointer<T> first, const pointer<U> second) noexcept
    : first(first), second(second) {}
    template <
        typename FirstT,
        typename SecondT,
        typename Q = T,
        template <typename> typename IterT = IteratorType,
        typename FirstIterT = decltype(std::declval<FirstT>().begin()),
        typename SecondIterT = decltype(std::declval<SecondT>().begin())>
    inline constexpr IteratorPair(const FirstIterT& first, const SecondIterT& second,
        std::enable_if_t<all_container_v<FirstT, SecondT> &&
        std::is_same_v<Iterator<Q>, IterT<Q>>>* = 0) noexcept
    : first(first), second(second) {}
    template <
        typename FirstT,
        typename SecondT,
        typename Q = T,
        template <typename> typename IterT = IteratorType,
        typename FirstRevIterT = decltype(std::declval<FirstT>().rbegin()),
        typename SecondRevIterT = decltype(std::declval<SecondT>().rbegin())>
    inline constexpr IteratorPair(const FirstRevIterT& first, const SecondRevIterT& second,
        std::enable_if_t<all_container_v<FirstT, SecondT> &&
        std::is_same_v<ReverseIterator<Q>, IterT<Q>>>* = 0) noexcept
    : first(first), second(second) {}
    inline constexpr IteratorPair(const IteratorType<T>& first, const IteratorType<U>& second) noexcept
    : first(first), second(second) {}
    inline constexpr IteratorPair(const std::pair<IteratorType<T>, IteratorType<U>>& p) noexcept
    : first(p.first), second(p.second) {}
    template <template <typename> typename IterT = IteratorType, typename Q = T>
    inline constexpr IteratorPair(const ReverseIterator<T>& first, const ReverseIterator<U>& second,
        std::enable_if_t<std::is_same_v<IterT<Q>, Iterator<Q>>>* = 0) noexcept
    : first(first.base()), second(second.base()) {}
    template <template <typename> typename IterT = IteratorType, typename Q>
    inline constexpr IteratorPair(const std::pair<ReverseIterator<T>, ReverseIterator<U>>& p,
        std::enable_if_t<std::is_same_v<IterT<Q>, Iterator<Q>>>* = 0) noexcept
    : IteratorPair(p.first, p.second) {}
    template <template <typename> typename IterT = IteratorType, typename Q = T>
    inline constexpr IteratorPair(const Iterator<T>& first, const Iterator<U>& second,
        std::enable_if_t<std::is_same_v<IterT<Q>, ReverseIterator<Q>>>* = 0) noexcept
    : first(first), second(second) {}
    template <template <typename> typename IterT = IteratorType, typename Q = T>
    inline constexpr IteratorPair(const std::pair<Iterator<T>, Iterator<U>>& p,
        std::enable_if_t<std::is_same_v<IterT<Q>, ReverseIterator<Q>>>* = 0) noexcept
    : IteratorPair(p.first, p.second) {}
public:
    inline constexpr IteratorPair& operator++() noexcept
    {
        ++first;
        ++second;
        return *this;
    }
    inline constexpr IteratorPair& operator--() noexcept
    {
        --first;
        --second;
        return *this;
    }
    inline constexpr IteratorPair operator++(int) noexcept
    {
        IteratorPair res;
        res.first = first++;
        res.second = second++;
        return res;
    }
    inline constexpr IteratorPair operator--(int) noexcept
    {
        IteratorPair res;
        res.first = first--;
        res.second = second--;
        return res;
    }
    inline constexpr IteratorPair& 
    operator+=(const difference_type& n) noexcept
    {
        first += n;
        second += n;
        return *this;
    }
    inline constexpr IteratorPair&
    operator-=(const difference_type& n) noexcept
    {
        first -= n;
        second -= n;
        return *this;
    }
    inline constexpr operator 
    std::pair<IteratorType<T>, IteratorType<U>>() const noexcept
    {
        return std::make_pair(first, second);
    }
};

template <
    typename T, typename U,
    template <typename> typename IteratorType,
    typename IterPairT = IteratorPair<IteratorType, T, U>,
    typename difference_type = typename IterPairT::difference_type>
inline constexpr IterPairT operator+(const difference_type& lhs, const IterPairT& rhs) noexcept
{
    IterPairT res = rhs;
    res += lhs;
    return res;
}    

template <
    typename T, typename U,
    template <typename> typename IteratorType,
    typename IterPairT = IteratorPair<IteratorType, T, U>,
    typename difference_type = typename IterPairT::difference_type>
inline constexpr IterPairT operator+(const IterPairT& lhs, const difference_type& rhs) noexcept
{
    IterPairT res = lhs;
    res += rhs;
    return res;
}

template <
    typename T, typename U,
    template <typename> typename IteratorType,
    typename IterPairT = IteratorPair<IteratorType, T, U>,
    typename difference_type = typename IterPairT::difference_type>
inline constexpr IterPairT operator-(const IterPairT& lhs, const difference_type& rhs) noexcept
{
    IterPairT res = lhs;
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