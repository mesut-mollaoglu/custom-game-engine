#ifndef BUFFER_HPP
#define BUFFER_HPP

inline constexpr usize GetSizeOfGLEnumTypes(const i32& type)
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
    return 0;
}

class VAO
{
public:
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
public:
    inline void Build()
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }
public:
    inline void Bind()
    {
        if(!m_id) Build();
        glBindVertexArray(m_id);
    }
    inline void Unbind()
    {
        glBindVertexArray(0);
    }
public:
    inline const u32& GetId() const
    {
        return m_id;
    }
public:
    inline void Release()
    {
        if(!m_id) return;
        glDeleteVertexArrays(1, &m_id);
        m_id = 0u;
    }
    virtual ~VAO()
    {
        Release();
    }
private:
    u32 m_id;
};

template <class T, i32 BufferT> 
class Buffer
{
public:
    inline Buffer(const Buffer<T, BufferT>& buffer) = delete;
    inline Buffer& operator=(const Buffer<T, BufferT>& buffer) = delete;
    inline Buffer(Buffer<T, BufferT>&& buffer) 
    : m_id(buffer.m_id), m_flag(buffer.m_flag), m_size(buffer.m_size)
    {buffer.m_id = 0u; buffer.m_size = 0ull;}
    inline Buffer(const usize& size = 0ull, const i32& flag = GL_STATIC_DRAW) 
    : m_id(0u), m_flag(flag), m_size(size) {}
    inline Buffer& operator=(Buffer<T, BufferT>&& buffer)
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
    template <typename CT, typename U = T>
    inline void Build(
        const CT& container,
        const i32& flag = GL_STATIC_DRAW,
        std::enable_if_t<is_container_v<CT> &&
            is_inner_type_same_v<U, CT> &&
            is_contiguous_v<CT>>* = 0)
    {
        Build(container.data(), container.size(), flag);
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
        glGenBuffers(1, &m_id);
        glBindBuffer(BufferT, m_id);
        glBufferData(BufferT, (m_size = size) * sizeof(T), data, m_flag = flag);
    }
public:
    template <typename CT, typename U = T>
    inline void Map(
        const CT& container,
        const usize& offset = 0ull,
        std::enable_if_t<is_container_v<CT> &&
            is_inner_type_same_v<U, CT> &&
            is_contiguous_v<CT>>* = 0)
    {
        this->Map(container.data(), container.size(), offset);
    }
    inline void Map(
        const T* data, 
        const usize& size, 
        const usize& offset = 0ull)
    {
        if(!m_id) return Build(data, size, m_flag);
        glBindBuffer(BufferT, m_id);
        if(size + offset <= m_size)
            glBufferSubData(BufferT, sizeof(T) * offset, sizeof(T) * size, data);
        else
            glBufferData(BufferT, sizeof(T) * (m_size = size + offset), data, m_flag);
    }
public:
    template <i32 U = BufferT, typename = std::enable_if_t<U == GL_ARRAY_BUFFER>>
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
            AddAttrib(index + i, size, offset + i * GetSizeOfGLEnumTypes(type) * size);
    }
public:
    inline void Bind()
    {
        if(!m_id) Build(m_flag);
        glBindBuffer(BufferT, m_id);
    }
    inline void Unbind() 
    {
        glBindBuffer(BufferT, 0);
    }
public:
    inline const u32& GetId() const
    {
        return m_id;
    }
public:
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