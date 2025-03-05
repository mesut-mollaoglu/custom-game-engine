#ifndef SHADER_H
#define SHADER_H

const std::string divider = "\\";
inline constexpr int32_t materialCount = 4;
inline constexpr int32_t dirLightCount = 4;
inline constexpr int32_t pointLightCount = 4;
inline constexpr int32_t spotLightCount = 4;
inline constexpr std::string_view shaderMaterialArrName = "MATERIAL_COUNT";
inline constexpr std::string_view shaderDirLightName = "DIR_LIGHTS_COUNT";
inline constexpr std::string_view shaderPointLightName = "POINT_LIGHTS_COUNT";
inline constexpr std::string_view shaderSpotLightName = "SPOT_LIGHTS_COUNT";

template <typename T>
inline void ReplaceAll(
    std::string& src, 
    const std::string_view& name, 
    const T& value,
    typename std::enable_if_t<std::is_arithmetic_v<T>>* = 0)
{
    while(src.find(name) != std::string::npos)
    {
        const size_t start = src.find(name);
        src.erase(start, name.size());
        src.insert(start, std::to_string(value));
    }
}

inline std::string ReadShader(const std::string& path)
{
    std::ifstream input(path.c_str());
    std::string line, output;
    while(std::getline(input, line))
    {
        if(line.find("#include") != std::string::npos)
        {
            const size_t start = line.find_first_of('"') + 1;
            output.append(ReadShader(path.substr(0, path.find_last_of(divider)) + divider + line.substr(start, line.find_last_of('"') - start)));
        }
        else
        {
            ReplaceAll(line, shaderMaterialArrName, materialCount);
            ReplaceAll(line, shaderDirLightName, dirLightCount);
            ReplaceAll(line, shaderSpotLightName, spotLightCount);
            ReplaceAll(line, shaderPointLightName, pointLightCount);
            output.append(line + '\n');
        }
    }
    return output;
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

class Shader
{
public:
    inline Shader(
        const GLuint& id = 0,
        const std::function<void(Shader&)>& init = nullptr,
        const std::function<void(Shader&)>& update = nullptr
    ) : m_id(id), m_funcInit(std::move(init)), m_funcUpdate(std::move(update)) {}
    inline Shader(const Shader& lhs) = default;
    inline Shader& operator=(const Shader& lhs) = default;
    inline Shader(Shader&& lhs) = default;
    inline Shader& operator=(Shader&& lhs) = default;
    inline void Set()
    {
        if(!m_id) return; 
        glUseProgram(m_id);
        if(m_funcInit)
            m_funcInit(*this);
    }
    inline void Update()
    {
        if(m_id && m_funcUpdate)
            m_funcUpdate(*this);
    }
    inline void Release()
    {
        if(m_id) glDeleteShader(m_id);
        m_funcInit = m_funcUpdate = nullptr;
    }
    inline void SetUniformInt(const std::string& name, const int* data, int count = 1)
    {
        const GLuint location = glGetUniformLocation(m_id, name.c_str());
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
        const GLuint location = glGetUniformLocation(m_id, name.c_str());
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
        const GLuint location = glGetUniformLocation(m_id, name.c_str());
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
        const GLuint location = glGetUniformLocation(m_id, name.c_str());
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
        const GLuint location = glGetUniformLocation(m_id, name.c_str());
        switch(count)
        {
            case 2: glUniformMatrix2dv(location, 1, GL_FALSE, data); break;
            case 3: glUniformMatrix3dv(location, 1, GL_FALSE, data); break;
            case 4: glUniformMatrix4dv(location, 1, GL_FALSE, data); break;
            default: break;
        }
    }
    inline void SetUniformInt(const std::string& name, const int i)
    {SetUniformInt(name, &i, 1);}
    inline void SetUniformBool(const std::string& name, const bool b)
    {SetUniformInt(name, (const int*)&b, 1);}
public:
//uniform matrices
    template <typename T, len_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<T, N, N>& mat)
    {return;}
    template <len_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<float, N, N>& mat)
    {SetUniformFloatMat(name, &mat[0][0], N);}
    template <len_t N>
    inline void SetUniformMat(const std::string& name, const Matrix<double, N, N>& mat)
    {SetUniformDoubleMat(name, &mat[0][0], N);}
public:
//uniform vectors
    template <typename T, len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<T, N>& vec)
    {return;}
    template <len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<float, N>& vec)
    {SetUniformFloat(name, &vec[0], N);}
    template <len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<double, N>& vec)
    {SetUniformDouble(name, &vec[0], N);}
    template <len_t N>
    inline void SetUniformVec(const std::string& name, const Vector<int, N>& vec)
    {SetUniformInt(name, &vec[0], N);}
    virtual ~Shader() {Release();}
public:
    inline const GLuint& GetId() const 
    {return m_id;}
    inline void SetId(const GLuint& id) 
    {m_id = id;}
private:
    GLuint m_id = 0u;
    std::function<void(Shader&)> m_funcInit = nullptr;
    std::function<void(Shader&)> m_funcUpdate = nullptr;
};

class ShaderManager
{
private:
    Shader* m_currShader = nullptr;
    std::unordered_map<key_type, Shader> m_mapShaders;
public:
    inline Shader& operator[](const key_type& key)
    {
        return m_mapShaders[key];
    }
private:
    inline void SetShader(Shader* shader)
    {
        if(!shader || (m_currShader && m_currShader->GetId() == shader->GetId()) || m_mapShaders.empty())
            return;
        m_currShader = shader;
        m_currShader->Set();
        m_currShader->Update();
    }
public:
    inline void SetShader(const key_type& key)
    {
        if(m_mapShaders.count(key))
            SetShader(&m_mapShaders.at(key));
    }
    inline void AddShader(const Shader& shader)
    {
        AddShader(m_mapShaders.size(), shader);
    }
    inline void AddShader(const key_type& key, const Shader& shader)
    {
        operator[](key) = shader;
    }
    inline void UpdateShader()
    {
        assert(m_currShader);
        m_currShader->Update();
    }
    inline Shader* GetCurrentShader()
    {
        return m_currShader;
    }
};

#endif