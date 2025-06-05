#ifndef SHADER_H
#define SHADER_H

inline constexpr char divider = '\\';

inline constexpr i32 materialCount = 4;
inline constexpr i32 dirLightCount = 4;
inline constexpr i32 pointLightCount = 4;
inline constexpr i32 spotLightCount = 4;
inline constexpr i32 sprBatchMaxSprites = 32;

struct AcceptedTypeBase
{
    inline virtual operator std::string() const = 0;
};

template <typename T>
struct AcceptedType : public AcceptedTypeBase
{
    static_assert(std::is_arithmetic_v<T>);
private:
    T value;
public:
    inline AcceptedType(const T& value = T(0)) : value(value) {}
    inline operator std::string() const override
    {
        return std::to_string(value);
    }
    inline const T& GetValue() const
    {
        return value;
    }
};

template <>
struct AcceptedType<std::string> : public AcceptedTypeBase
{
private:
    std::string value;
public:
    inline AcceptedType(const std::string& s = "") : value(s) {}
    inline operator std::string() const override
    {
        return value;
    }
};

const std::unordered_map<std::string_view, AcceptedTypeBase*> mapShaderConstants = 
{
    {"MATERIAL_COUNT", new AcceptedType(materialCount)},
    {"DIR_LIGHTS_COUNT", new AcceptedType(dirLightCount)},
    {"SPOT_LIGHTS_COUNT", new AcceptedType(spotLightCount)},
    {"POINT_LIGHTS_COUNT", new AcceptedType(pointLightCount)},
    {"MAX_SPRITES", new AcceptedType(sprBatchMaxSprites)}
};

inline void ReplaceAll(
    std::string& src, 
    const std::string_view& name, 
    const std::string& value)
{
    while(src.find(name) != std::string::npos)
    {
        const usize start = src.find(name);
        src.erase(start, name.size());
        src.insert(start, value);
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
            const usize start = line.find_first_of('"') + 1;
            output.append(ReadShader(path.substr(0, path.find_last_of(divider)) + divider + line.substr(start, line.find_last_of('"') - start)));
        }
        else
        {
            for(auto& [name, value] : mapShaderConstants)
                ReplaceAll(line, name, *value);
            output.append(line + '\n');
        }
    }
    return output;
}

inline u32 CompileShader(GLenum type, const char* source) 
{
    u32 shader = glCreateShader(type);
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

inline u32 CompileProgram(const std::initializer_list<u32>& shaders) 
{
    u32 program = glCreateProgram();
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
        const u32& id = 0,
        const std::function<void(Shader&)>& funcInit = nullptr,
        const std::function<void(Shader&)>& funcUpdate = nullptr
    ) : m_id(id), m_funcInit(std::move(funcInit)), m_funcUpdate(std::move(funcUpdate)) {}
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
    inline void SetUniformInt(const std::string& name, const i32* data, i32 count = 1)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        switch(count)
        {
            case 1: glUniform1i(loc, data[0]); break;
            case 2: glUniform2i(loc, data[0], data[1]); break;
            case 3: glUniform3i(loc, data[0], data[1], data[2]); break;
            case 4: glUniform4i(loc, data[0], data[1], data[2], data[3]); break;
            default: break;
        }
    }
    inline void SetUniformFloat(const std::string& name, const f32* data, i32 count = 1)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        switch(count)
        {
            case 1: glUniform1f(loc, data[0]); break;
            case 2: glUniform2f(loc, data[0], data[1]); break;
            case 3: glUniform3f(loc, data[0], data[1], data[2]); break;
            case 4: glUniform4f(loc, data[0], data[1], data[2], data[3]); break;
            default: break;
        }
    }
    inline void SetUniformDouble(const std::string& name, const f64* data, i32 count = 1)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        switch(count)
        {
            case 1: glUniform1d(loc, data[0]); break;
            case 2: glUniform2d(loc, data[0], data[1]); break;
            case 3: glUniform3d(loc, data[0], data[1], data[2]); break;
            case 4: glUniform4d(loc, data[0], data[1], data[2], data[3]); break;
            default: break;
        }
    }
    inline void SetUniformFloatMatrix(const std::string& name, const f32* data, i32 count = 2)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        switch(count)
        {
            case 2: glUniformMatrix2fv(loc, 1, GL_FALSE, data); break;
            case 3: glUniformMatrix3fv(loc, 1, GL_FALSE, data); break;
            case 4: glUniformMatrix4fv(loc, 1, GL_FALSE, data); break;
            default: break;
        }
    }
    inline void SetUniformDoubleMatrix(const std::string& name, const f64* data, i32 count = 2)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        switch(count)
        {
            case 2: glUniformMatrix2dv(loc, 1, GL_FALSE, data); break;
            case 3: glUniformMatrix3dv(loc, 1, GL_FALSE, data); break;
            case 4: glUniformMatrix4dv(loc, 1, GL_FALSE, data); break;
            default: break;
        }
    }
    inline void SetUniformInt(const std::string& name, const i32 i)
    {
        SetUniformInt(name, &i, 1);
    }
    inline void SetUniformBool(const std::string& name, const bool b)
    {
        SetUniformInt(name, (const i32*)&b, 1);
    }
public:
//uniform matrices
    template <typename T, len_t N>
    inline void SetUniformMatrix(const std::string& name, const Matrix<T, N, N>& mat)
    {
        return;
    }
    template <len_t N>
    inline void SetUniformMatrix(const std::string& name, const Matrix<f32, N, N>& mat)
    {
        SetUniformFloatMatrix(name, &mat[0][0], N);
    }
    template <len_t N>
    inline void SetUniformMatrix(const std::string& name, const Matrix<f64, N, N>& mat)
    {
        SetUniformDoubleMatrix(name, &mat[0][0], N);
    }
public:
//uniform vectors
    template <typename T, len_t N>
    inline void SetUniformVector(const std::string& name, const Vector<T, N>& vec)
    {
        return;
    }
    template <len_t N>
    inline void SetUniformVector(const std::string& name, const Vector<f32, N>& vec)
    {
        SetUniformFloat(name, &vec[0], N);
    }
    template <len_t N>
    inline void SetUniformVector(const std::string& name, const Vector<f64, N>& vec)
    {
        SetUniformDouble(name, &vec[0], N);
    }
    template <len_t N>
    inline void SetUniformVector(const std::string& name, const Vector<i32, N>& vec)
    {
        SetUniformInt(name, &vec[0], N);
    }
    virtual ~Shader() 
    {
        Release();
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
private:
    u32 m_id = 0u;
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