#ifndef SHADER_H
#define SHADER_H

#include "includes.h"

inline std::string ReadShader(const char* path)
{
    std::string res;
    FILE* src = fopen(path, "r");
    fseek(src, 0, SEEK_END);
    const std::size_t size = ftell(src);
    res.resize(size);
    rewind(src);
    fread(res.data(), sizeof(char), size, src);
    return res;
}

inline GLuint CompileShader(GLenum type, const char* source) 
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) 
    {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        GLchar *info = new GLchar[length];
        glGetShaderInfoLog(shader, length, NULL, info);
        std::cout << info << std::endl;
        delete[] info;
    }
    return shader;
}

inline GLuint CompileProgram(const std::initializer_list<GLuint>& shaders) 
{
    GLuint program = glCreateProgram();
    for(auto& s : shaders) glAttachShader(program, s);
    glLinkProgram(program);
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) 
    {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        GLchar *info = new GLchar[length];
        glGetProgramInfoLog(program, length, NULL, info);
        std::cout << info << std::endl;
        delete[] info;
    }
    for(auto& s : shaders)
    {
        glDetachShader(program, s);
        glDeleteShader(s);
    }
    return program;
}

struct Shader
{
    inline Shader(
        const GLuint& id = 0,
        const std::function<void(Shader&)>& start = nullptr,
        const std::function<void(Shader&)>& update = nullptr
    ) : id(id), start(std::move(start)), update(std::move(update)) 
    {
        return;
    }
    inline Shader(const Shader& lhs) = delete;
    inline Shader& operator=(const Shader& lhs) = delete;
    inline Shader(Shader&& lhs) : id(lhs.id), start(std::move(lhs.start)), update(std::move(lhs.update))
    {
        lhs.id = 0;
        lhs.start = nullptr;
        lhs.update = nullptr;
    }
    inline Shader& operator=(Shader&& lhs)
    {
        if(this != &lhs)
        {
            Release();
            id = lhs.id;
            start = std::move(lhs.start);
            update = std::move(lhs.update);
            lhs.id = 0;
            lhs.start = nullptr;
            lhs.update = nullptr;
        }
        return *this;
    }
    inline void Set()
    {
        if(id) 
        {
            glUseProgram(id);
            if(start != nullptr)
                start(*this);
        }
    }
    inline void Update()
    {
        if(id && update != nullptr)
            update(*this);
    }
    inline void Release()
    {
        if(id) glDeleteShader(id);
        start = update = nullptr;
    }
    inline void SetUniformInt(const std::string& name, const int* data, int count = 1)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        switch(count)
        {
            case 1: glUniform1i(location, data[0]); break;
            case 2: glUniform2i(location, data[0], data[1]); break;
            case 3: glUniform3i(location, data[0], data[1], data[2]); break;
            case 4: glUniform4i(location, data[0], data[1], data[2], data[3]); break;
            default: break;
        }
    }
    inline void SetUniformFloat(const std::string& name, const float* data, int count = 1)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        switch(count)
        {
            case 1: glUniform1f(location, data[0]); break;
            case 2: glUniform2f(location, data[0], data[1]); break;
            case 3: glUniform3f(location, data[0], data[1], data[2]); break;
            case 4: glUniform4f(location, data[0], data[1], data[2], data[3]); break;
            default: break;
        }
    }
    inline void SetUniformDouble(const std::string& name, const double* data, int count = 1)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        switch(count)
        {
            case 1: glUniform1d(location, data[0]); break;
            case 2: glUniform2d(location, data[0], data[1]); break;
            case 3: glUniform3d(location, data[0], data[1], data[2]); break;
            case 4: glUniform4d(location, data[0], data[1], data[2], data[3]); break;
            default: break;
        }
    }
    inline void SetUniformFloatMat(const std::string& name, const float* data, int count = 2)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        switch(count)
        {
            case 2: glUniformMatrix2fv(location, 1, GL_FALSE, data); break;
            case 3: glUniformMatrix3fv(location, 1, GL_FALSE, data); break;
            case 4: glUniformMatrix4fv(location, 1, GL_FALSE, data); break;
            default: break;
        }
    }
    inline void SetUniformDoubleMat(const std::string& name, const double* data, int count = 2)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        switch(count)
        {
            case 2: glUniformMatrix2dv(location, 1, GL_FALSE, data); break;
            case 3: glUniformMatrix3dv(location, 1, GL_FALSE, data); break;
            case 4: glUniformMatrix4dv(location, 1, GL_FALSE, data); break;
            default: break;
        }
    }
    inline void SetUniformBool(const std::string& name, const bool& b)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        glUniform1i(location, b);
    }
    template <typename T, std::size_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<T, N, N>& mat)
    {
        return;
    }
    template <std::size_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<float, N, N>& mat)
    {
        SetUniformFloatMat(name, mat.data, N);
    }
    template <std::size_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<double, N, N>& mat)
    {
        SetUniformDoubleMat(name, mat.data, N);
    }
    template <typename T, std::size_t N>
    inline void SetUniformVec(const std::string& name, const Vector<T, N>& vec)
    {
        return;
    }
    template <std::size_t N>
    inline void SetUniformVec(const std::string& name, const Vector<float, N>& vec)
    {
        SetUniformFloat(name, vec.data, N);
    }
    template <std::size_t N>
    inline void SetUniformVec(const std::string& name, const Vector<double, N>& vec)
    {
        SetUniformDouble(name, vec.data, N);
    }
    template <std::size_t N>
    inline void SetUniformVec(const std::string& name, const Vector<int, N>& vec)
    {
        SetUniformInt(name, vec.data, N);
    }
    inline virtual ~Shader()
    {
        Release();
    }
    GLuint id = 0;
    std::function<void(Shader&)> start = nullptr;
    std::function<void(Shader&)> update = nullptr;
};

#endif