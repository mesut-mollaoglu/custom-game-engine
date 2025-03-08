#ifndef BUFFER_H
#define BUFFER_H

inline constexpr size_t sizeof_glenum_type(const GLenum& type)
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
    {glBindVertexArray(0);}
    inline void Release()
    {
        if(!m_id) return;
        glDeleteVertexArrays(1, &m_id);
        m_id = 0u;
    }
    inline const GLuint GetId() const
    {return m_id;}
    inline void SetId(const GLuint& id)
    {m_id = id;}
    virtual ~VAO()
    {Release();}
private:
    GLuint m_id;
};

template <class T, GLenum _BufferT> 
struct Buffer
{
    inline Buffer(const Buffer<T, _BufferT>& buffer) = delete;
    inline Buffer& operator=(const Buffer<T, _BufferT>& buffer) = delete;
    inline Buffer(Buffer<T, _BufferT>&& buffer) 
    : m_id(buffer.m_id), m_flag(buffer.m_flag), m_size(buffer.m_size)
    {buffer.m_id = 0u; buffer.m_size = 0ull;}
    inline Buffer(const size_t& size = 0ull, const GLenum& flag = GL_STATIC_DRAW) 
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
    template<typename _Container>
    inline void Build(
        const _Container& container, 
        const GLenum& flag = GL_STATIC_DRAW,
        typename std::enable_if_t<is_container_v<_Container>>* = 0)
    {Build(container.data(), container.size(), flag);}
    inline void Build(const GLenum& flag = GL_STATIC_DRAW)
    {Build(NULL, 0ull, flag);}
    inline void Build(
        const T* data, 
        const size_t& size, 
        const GLenum& flag = GL_STATIC_DRAW) 
    {
        m_size = size;
        m_flag = flag;
        glGenBuffers(1, &m_id);
        glBindBuffer(_BufferT, m_id);
        glBufferData(_BufferT, m_size * sizeof(T), data, m_flag);
    }
public:
//map
    template <typename _Container>
    inline void Map(
        const _Container& container, 
        const size_t& offset = 0ull,
        typename std::enable_if_t<is_container_v<_Container>>* = 0)
    {Map(container.data(), container.size(), offset);}
    template <typename _Container>
    inline void Map(
        const typename _Container::iterator& begin,
        const typename _Container::iterator& end, 
        const size_t& offset = 0ull,
        typename std::enable_if_t<is_container_v<_Container>>* = 0)
    {Map(&(*begin), end - begin, offset);}
    inline void Map(
        const T* data, 
        const size_t& size, 
        const size_t& offset = 0ull)
    {
        if(!m_id)
        {
            Build(data, size, m_flag);
            return;
        }
        glBindBuffer(_BufferT, m_id);
        if(m_size < size)
        {
            glBufferData(_BufferT, sizeof(T) * size, data, m_flag);
            m_size = size;
        }
        else
            glBufferSubData(_BufferT, sizeof(T) * offset, sizeof(T) * size, data);
    }
public:
//add attribute
    template <GLenum U = _BufferT, typename = typename std::enable_if_t<U == GL_ARRAY_BUFFER>>
    inline void AddAttrib(
        const size_t& index, 
        const size_t& size, 
        const size_t& offset, 
        const GLenum& type = GL_FLOAT)
    {
        if(!m_id) Build(m_flag);
        glVertexAttribPointer(index, size, type, GL_FALSE, sizeof(T), (void*)offset);
        glEnableVertexAttribArray(index);
    }
    inline void AddMatrixAttrib(
        const size_t& index, 
        const size_t& size, 
        const size_t& offset, 
        const GLenum& type = GL_FLOAT)
    {
        for(size_t i = 0ull; i < size; i++)
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
    {glBindBuffer(_BufferT, 0);}
public:
    inline const GLuint& GetId() const
    {return m_id;}
    inline void SetId(const GLuint& id)
    {m_id = id;}
    inline void Resize(const size_t& size)
    {
        if(m_size == size) return;
        glBindBuffer(_BufferT, m_id);
        glBufferData(_BufferT, size * sizeof(T), NULL, m_flag);
        m_size = size;
    }
    inline const size_t& GetSize() const
    {return m_size;}
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
    {Release();}
private:
    GLuint m_id;
    GLenum m_flag;
    size_t m_size;
};

#endif