#ifndef SHADER_H
#define SHADER_H

#include "includes.h"

const std::string divider = "\\";

inline std::string ReadShader(const std::string& path)
{
    std::stringstream output;
    std::ifstream input(path.c_str());
    std::string line;
    while(std::getline(input, line))
    {
        if(line.find("#include") != std::string::npos)
        {
            const size_t start = line.find_first_of('"') + 1;
            output << ReadShader(path.substr(0, path.find_last_of(divider)) + divider + line.substr(start, line.find_last_of('"') - start));
        }
        else
        {
            while(line.find(shaderMaterialArrName) != std::string::npos)
            {
                const size_t start = line.find(shaderMaterialArrName);
                line.erase(start, shaderMaterialArrName.size());
                line.insert(start, std::to_string(materialCount));
            }
            output << line << '\n';
        }
    }
    return output.str();
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
    for(auto& shader : shaders) 
        glAttachShader(program, shader);
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
    for(auto& shader : shaders)
    {
        glDetachShader(program, shader);
        glDeleteShader(shader);
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
    inline void SetUniformInt(const std::string& name, const int i)
    {
        SetUniformInt(name, &i, 1);
    }
    inline void SetUniformBool(const std::string& name, const bool b)
    {
        const GLuint location = glGetUniformLocation(id, name.c_str());
        glUniform1i(location, b);
    }
    template <typename T, len_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<T, N, N>& mat)
    {
        return;
    }
    template <len_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<float, N, N>& mat)
    {
        SetUniformFloatMat(name, &mat[0][0], N);
    }
    template <len_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<double, N, N>& mat)
    {
        SetUniformDoubleMat(name, &mat[0][0], N);
    }
    template <typename T, len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<T, N>& vec)
    {
        return;
    }
    template <len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<float, N>& vec)
    {
        SetUniformFloat(name, &vec[0], N);
    }
    template <len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<double, N>& vec)
    {
        SetUniformDouble(name, &vec[0], N);
    }
    template <len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<int, N>& vec)
    {
        SetUniformInt(name, &vec[0], N);
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