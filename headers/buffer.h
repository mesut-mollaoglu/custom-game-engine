#ifndef BUFFER_H
#define BUFFER_H

#include "includes.h"

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
    return 0;
}

struct VAO
{
    inline VAO(const VAO& vao) = delete;
    inline VAO& operator=(const VAO& vao) = delete;
    inline VAO()
    {
        id = 0;
    }
    inline VAO(VAO&& vao) : id(vao.id)
    {
        vao.id = 0;
    }
    inline VAO& operator=(VAO&& vao)
    {
        if(this != &vao)
        {
            Release();
            id = vao.id;
            vao.id = 0;
        }
        return *this;
    }
    inline void Build()
    {
        glGenVertexArrays(1, &id);
        glBindVertexArray(id);
    }
    inline void Bind()
    {
        if(!id) Build();
        glBindVertexArray(id);
    }
    inline void Unbind()
    {
        glBindVertexArray(0);
    }
    inline void Release()
    {
        if(id)
        { 
            glDeleteVertexArrays(1, &id);
            id = 0;
        }
    }
    virtual ~VAO()
    {
        Release();
    }
private:
    GLuint id;
};

template <class T, GLenum BufferType> 
struct Buffer
{
    inline Buffer(const Buffer<T, BufferType>& buffer) = delete;
    inline Buffer& operator=(const Buffer<T, BufferType>& buffer) = delete;
    inline Buffer(Buffer<T, BufferType>&& buffer) 
    : id(buffer.id), mapFlag(buffer.mapFlag), size(buffer.size)
    {
        buffer.id = 0;
        buffer.size = 0;
    }
    inline Buffer(const size_t& size = 0, const GLenum& mapFlag = GL_STATIC_DRAW) 
    : mapFlag(mapFlag), size(size)
    {
        id = 0;
    }
    inline Buffer& operator=(Buffer<T, BufferType>&& buffer)
    {
        if(this != &buffer)
        {
            Release();
            id = buffer.id;
            size = buffer.size;
            mapFlag = buffer.mapFlag;
            buffer.id = 0;
            buffer.size = 0;
        }
        return *this;
    }
    inline void Build(const T* data, const size_t& num, const GLenum& flag = GL_STATIC_DRAW) 
    {
        size = num;
        mapFlag = flag;
        glGenBuffers(1, &id);
        glBindBuffer(BufferType, id);
        glBufferData(BufferType, size * sizeof(T), data, mapFlag);
    }
    inline void Build(const std::vector<T>& vec, const GLenum& flag = GL_STATIC_DRAW)
    {
        Build(vec.data(), vec.size(), flag);
    }
    inline void Build(const GLenum& flag = GL_STATIC_DRAW)
    {
        Build(NULL, 0, flag);
    }
    inline void Map(const T* data, const size_t& num, const size_t& offset = 0)
    {
        if(!id)
        {
            Build(data, num, mapFlag);
            return;
        }
        glBindBuffer(BufferType, id);
        if(size < num)
        {
            glBufferData(BufferType, sizeof(T) * num, data, mapFlag);
            size = num;
        } 
        else
            glBufferSubData(BufferType, sizeof(T) * offset, sizeof(T) * num, data);
    }
    inline void Map(typename std::vector<T>::iterator& begin, typename std::vector<T>::iterator& end, const size_t& offset = 0)
    {
        Map(&(*begin), end - begin, offset);
    }
    inline void Map(const std::vector<T>& vec, const size_t& offset = 0)
    {
        Map(vec.data(), vec.size(), offset);
    }
    template <GLenum U = BufferType, typename = typename std::enable_if<U == GL_ARRAY_BUFFER>::type>
    inline void AddAttrib(const size_t& index, const size_t& num, const size_t& offset, const GLenum& type = GL_FLOAT)
    {
        if(!id) Build(mapFlag);
        glVertexAttribPointer(index, num, type, GL_FALSE, sizeof(T), (void*)offset);
        glEnableVertexAttribArray(index);
    }
    inline void AddAttribMat(const size_t& index, const size_t& num, const size_t& offset, const GLenum& type = GL_FLOAT)
    {
        for(size_t i = 0; i < num; i++)
            AddAttrib(index + i, num, offset + i * sizeof_glenum_type(type) * num);
    }
    inline void Clear()
    {
        if(size != 0)
        {
            glBindBuffer(BufferType, id);
            glBufferSubData(BufferType, 0, size * sizeof(T), NULL);
        }
    }
    inline void Resize(const size_t& num)
    {
        if(size != num)
        {
            glBindBuffer(BufferType, id);
            glBufferData(BufferType, num * sizeof(T), NULL, mapFlag);
            size = num;
        }
    }
    inline void Bind()
    {
        if(!id) Build(mapFlag);
        glBindBuffer(BufferType, id);
    }
    inline void Unbind()
    {
        glBindBuffer(BufferType, 0);
    }
    inline void Release()
    {
        if(id)
        {
            glDeleteBuffers(1, &id);
            id = 0;
            size = 0;
        }
    }
    virtual ~Buffer() 
    {
        Release();
    }
private:
    GLuint id;
    GLenum mapFlag;
    size_t size;
};

#endif