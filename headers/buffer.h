#ifndef BUFFER_H
#define BUFFER_H

inline constexpr usize sizeof_glenum_type(const i32& type)
{
    switch(type)
    {
    	case GL_BYTE:
    	case GL_UNSIGNED_BYTE:
    		return sizeof(GLbyte);
    	case GL_SHORT:
    	case GL_UNSIGNED_SHORT:
    		return sizeof(GLshort);
    	case GL_INT_2_10_10_10_REV:
    	case GL_INT:
    	case GL_UNSIGNED_INT_2_10_10_10_REV:
    	case GL_UNSIGNED_INT:
    		return sizeof(GLint);
    	case GL_FLOAT:
    		return sizeof(GLfloat);
    	case GL_DOUBLE:
    		return sizeof(GLdouble);
    	case GL_FIXED:
    		return sizeof(GLfixed);
    	case GL_HALF_FLOAT:
    		return sizeof(GLhalf);
    }
    return 0ull;
}

struct VAO
{
    inline VAO(const VAO& vao) = delete;
    inline VAO& operator=(const VAO& vao) = delete;
    inline VAO(VAO&& vao) : m_id(vao.m_id) {vao.m_id = 0u;}
    inline VAO() : m_id(0u) {}
    inline VAO& operator=(VAO&& vao)
    {
        if(this != &vao)
        {
            Release();
            m_id = vao.m_id;
            vao.m_id = 0u;
        }
        return *this;
    }
    inline void Build()
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }
    inline void Bind()
    {
        if(!m_id) Build();
        glBindVertexArray(m_id);
    }
    inline void Unbind()
    {
        glBindVertexArray(0);
    }
    inline void Release()
    {
        if(!m_id) return;
        glDeleteVertexArrays(1, &m_id);
        m_id = 0u;
    }
    inline const u32 GetId() const
    {
        return m_id;
    }
    inline void SetId(const u32& id)
    {
        m_id = id;
    }
    virtual ~VAO()
    {
        Release();
    }
private:
    u32 m_id;
};

template <class T, i32 _BufferT> 
struct Buffer
{
    inline Buffer(const Buffer<T, _BufferT>& buffer) = delete;
    inline Buffer& operator=(const Buffer<T, _BufferT>& buffer) = delete;
    inline Buffer(Buffer<T, _BufferT>&& buffer) 
    : m_id(buffer.m_id), m_flag(buffer.m_flag), m_size(buffer.m_size)
    {buffer.m_id = 0u; buffer.m_size = 0ull;}
    inline Buffer(const usize& size = 0ull, const i32& flag = GL_STATIC_DRAW) 
    : m_flag(flag), m_size(size), m_id(0u) {}
    inline Buffer& operator=(Buffer<T, _BufferT>&& buffer)
    {
        if(this != &buffer)
        {
            Release();
            m_id = buffer.m_id;
            m_size = buffer.m_size;
            m_flag = buffer.m_flag;
            buffer.m_id = 0u;
            buffer.m_size = 0ull;
        }
        return *this;
    }
public:
//build
    template<typename _ContainerT, typename U = T>
    inline void Build(
        const _ContainerT& container,
        const i32& flag = GL_STATIC_DRAW,
        typename std::enable_if_t<
            is_container_v<_ContainerT> &&
            is_inner_type_same_v<U, _ContainerT>>* = 0)
    {
        const usize size = container.size();
        T data[size];
        usize idx = 0ull;
        for(const T& v : container)
            data[idx++] = v;
        Build(&data[0], size, flag);
    }
    template <
        typename _ContainerT,
        typename U = T,
        typename _IterT = typename _ContainerT::iterator>
    inline void Build(
        const _IterT& begin,
        const _IterT& end,
        const usize& size,
        const i32& flag = GL_STATIC_DRAW,
        typename std::enable_if_t<
            is_container_v<_ContainerT> &&
            is_inner_type_same_v<U, _ContainerT>>* = 0)
    {
        T data[size];
        usize idx = 0ull;
        for(_IterT beg = begin; beg != end; beg++)
            data[idx++] = *beg;
        Build(&data[0], size, flag);
    }
    inline void Build(const i32& flag = GL_STATIC_DRAW)
    {
        Build(NULL, 0ull, flag);
    }
    inline void Build(
        const T* data,
        const usize& size,
        const i32& flag = GL_STATIC_DRAW) 
    {
        m_size = size;
        m_flag = flag;
        glGenBuffers(1, &m_id);
        glBindBuffer(_BufferT, m_id);
        glBufferData(_BufferT, m_size * sizeof(T), data, m_flag);
    }
public:
//map
    template <typename _ContainerT, typename U = T>
    inline void Map(
        const _ContainerT& container,
        const usize& offset = 0ull,
        typename std::enable_if_t<
            is_container_v<_ContainerT> &&
            is_inner_type_same_v<U, _ContainerT>>* = 0)
    {
        const usize size = container.size();
        T data[size];
        usize idx = 0ull;
        for(const T& v : container)
            data[idx++] = v;
        Map(&data[0], size, offset);
    }
    template <
        typename _ContainerT,
        typename U = T,
        typename _IterT = typename _ContainerT::iterator>
    inline void Map(
        const _IterT& begin,
        const _IterT& end,
        const usize& size,
        const usize& offset = 0ull,
        typename std::enable_if_t<
            is_container_v<_ContainerT> &&
            is_inner_type_same_v<U, _ContainerT>>* = 0)
    {
        usize idx = 0ull;
        T data[size];
        for(_IterT beg = begin; beg != end; beg++)
            data[idx++] = *beg;
        Map(&data[0], size, offset);
    }
    inline void Map(
        const T* data, 
        const usize& size, 
        const usize& offset = 0ull)
    {
        if(!m_id) return Build(data, size, m_flag);
        glBindBuffer(_BufferT, m_id);
        if(m_size < size)
            glBufferData(_BufferT, sizeof(T) * (m_size = size), data, m_flag);
        else
            glBufferSubData(_BufferT, sizeof(T) * offset, sizeof(T) * size, data);
    }
public:
//add attribute
    template <i32 U = _BufferT, typename = typename std::enable_if_t<U == GL_ARRAY_BUFFER>>
    inline void AddAttrib(
        const usize& index, 
        const usize& size, 
        const usize& offset, 
        const i32& type = GL_FLOAT)
    {
        if(!m_id) Build(m_flag);
        glVertexAttribPointer(index, size, type, GL_FALSE, sizeof(T), (void*)offset);
        glEnableVertexAttribArray(index);
    }
    inline void AddMatrixAttrib(
        const usize& index, 
        const usize& size, 
        const usize& offset, 
        const i32& type = GL_FLOAT)
    {
        for(usize i = 0ull; i < size; i++)
            AddAttrib(index + i, size, offset + i * sizeof_glenum_type(type) * size);
    }
public:
//bind & unbind
    inline void Bind()
    {
        if(!m_id) Build(m_flag);
        glBindBuffer(_BufferT, m_id);
    }
    inline void Unbind() 
    {
        glBindBuffer(_BufferT, 0);
    }
public:
    inline const u32& GetId() const
    {
        return m_id;
    }
    inline void SetId(const u32& id)
    {
        m_id = id;
    }
    inline void Resize(const usize& size)
    {
        if(m_size == size) return;
        glBindBuffer(_BufferT, m_id);
        glBufferData(_BufferT, (m_size = size) * sizeof(T), NULL, m_flag);
    }
    inline const usize& GetSize() const
    {
        return m_size;
    }
public:
//destructors
    inline void Clear()
    {
        if(!m_size) return;
        glBindBuffer(_BufferT, m_id);
        glBufferSubData(_BufferT, 0, m_size * sizeof(T), NULL);
    }
    inline void Release()
    {
        if(!m_id) return;
        glDeleteBuffers(1, &m_id);
        m_id = 0u;
        m_size = 0ull;
    }
    virtual ~Buffer() 
    {
        Release();
    }
private:
    u32 m_id;
    i32 m_flag;
    usize m_size;
};

#endif