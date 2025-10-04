#ifndef SHADER_HPP
#define SHADER_HPP

inline constexpr char g_kDividerToken = '/';

inline constexpr i32 g_kMaterialCount = 4;
inline constexpr i32 g_kDirLightCount = 4;
inline constexpr i32 g_kPointLightCount = 4;
inline constexpr i32 g_kSpotLightCount = 4;
inline constexpr i32 g_kSpriteBatchMaxSprites = 32;

class AcceptedType
{
private:
    std::string s;
public:
    inline AcceptedType(const std::string& s = "") : s(s) {}
    template <typename T>
    inline AcceptedType(const T& x = g_kZero<T>,
        std::enable_if_t<std::is_arithmetic_v<T>>* = nullptr)
    {
        this->s = std::to_string(x);
    }
    inline operator std::string() const
    {
        return s;
    }
};

const std::unordered_map<std::string_view, AcceptedType> g_kMapShaderConstants = 
{
    {"MATERIAL_COUNT", g_kMaterialCount},
    {"DIR_LIGHTS_COUNT", g_kDirLightCount},
    {"SPOT_LIGHTS_COUNT", g_kSpotLightCount},
    {"POINT_LIGHTS_COUNT", g_kPointLightCount},
    {"MAX_SPRITES", g_kSpriteBatchMaxSprites}
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
            output.append(ReadShader(path.substr(0, path.find_last_of(g_kDividerToken)) + g_kDividerToken + line.substr(start, line.find_last_of('"') - start)));
        }
        else
        {
            for(auto& [name, value] : g_kMapShaderConstants)
                ReplaceAll(line, name, value);
            output.append(line + '\n');
        }
    }
    return output;
}

inline u32 CompileShader(GLenum type, const char* src) 
{
    u32 shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
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
        SafeDeleteArray(info);
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
        SafeDeleteArray(info);
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
        const u32& id = 0u,
        std::function<void(Shader&)>&& funcInit = nullptr,
        std::function<void(Shader&)>&& funcUpdate = nullptr
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
    template <typename T>
    inline void SetUniform(const std::string& name, const T* data, GLsizei count)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        if constexpr(std::is_same_v<T, i32> || std::is_same_v<T, bool>)
            switch(count)
            {
                case 1: glUniform1i(loc, data[0]); break;
                case 2: glUniform2i(loc, data[0], data[1]); break;
                case 3: glUniform3i(loc, data[0], data[1], data[2]); break;
                case 4: glUniform4i(loc, data[0], data[1], data[2], data[3]); break;
            }
        else if constexpr(std::is_same_v<T, f32>)
            switch(count)
            {
                case 1: glUniform1f(loc, data[0]); break;
                case 2: glUniform2f(loc, data[0], data[1]); break;
                case 3: glUniform3f(loc, data[0], data[1], data[2]); break;
                case 4: glUniform4f(loc, data[0], data[1], data[2], data[3]); break;
            }
        else if constexpr(std::is_same_v<T, u32>)
            switch(count)
            {
                case 1: glUniform1ui(loc, data[0]); break;
                case 2: glUniform2ui(loc, data[0], data[1]); break;
                case 3: glUniform3ui(loc, data[0], data[1], data[2]); break;
                case 4: glUniform4ui(loc, data[0], data[1], data[2], data[3]); break;
            }
        else if constexpr(std::is_same_v<T, f64>)
            switch(count)
            {
                case 1: glUniform1d(loc, data[0]); break;
                case 2: glUniform2d(loc, data[0], data[1]); break;
                case 3: glUniform3d(loc, data[0], data[1], data[2]); break;
                case 4: glUniform4d(loc, data[0], data[1], data[2], data[3]); break;
            }
    }
    template <typename T>
    inline void SetUniform(const std::string& name, const T* data, GLsizei x, GLsizei y)
    {
        const u32 loc = glGetUniformLocation(m_id, name.c_str());
        if constexpr(std::is_same_v<T, f32>)
            switch(x)
            {
                case 2:
                    switch(y)
                    {
                        case 2: glUniformMatrix2fv(loc, 1, GL_FALSE, data); break;
                        case 3: glUniformMatrix3x2fv(loc, 1, GL_FALSE, data); break;
                        case 4: glUniformMatrix4x2fv(loc, 1, GL_FALSE, data); break;
                    }
                break;
                case 3:
                    switch(y)
                    {
                        case 2: glUniformMatrix2x3fv(loc, 1, GL_FALSE, data); break;
                        case 3: glUniformMatrix3fv(loc, 1, GL_FALSE, data); break;
                        case 4: glUniformMatrix4x3fv(loc, 1, GL_FALSE, data); break;
                    }
                break;
                case 4:
                    switch(y)
                    {
                        case 2: glUniformMatrix2x4fv(loc, 1, GL_FALSE, data); break;
                        case 3: glUniformMatrix3x4fv(loc, 1, GL_FALSE, data); break;
                        case 4: glUniformMatrix4fv(loc, 1, GL_FALSE, data); break;
                    }
                break;
            }
        else if constexpr(std::is_same_v<T, f64>)
            switch(x)
            {
                case 2:
                    switch(y)
                    {
                        case 2: glUniformMatrix2dv(loc, 1, GL_FALSE, data); break;
                        case 3: glUniformMatrix3x2dv(loc, 1, GL_FALSE, data); break;
                        case 4: glUniformMatrix4x2dv(loc, 1, GL_FALSE, data); break;
                    }
                break;
                case 3:
                    switch(y)
                    {
                        case 2: glUniformMatrix2x3dv(loc, 1, GL_FALSE, data); break;
                        case 3: glUniformMatrix3dv(loc, 1, GL_FALSE, data); break;
                        case 4: glUniformMatrix4x3dv(loc, 1, GL_FALSE, data); break;
                    }
                break;
                case 4:
                    switch(y)
                    {
                        case 2: glUniformMatrix2x4dv(loc, 1, GL_FALSE, data); break;
                        case 3: glUniformMatrix3x4dv(loc, 1, GL_FALSE, data); break;
                        case 4: glUniformMatrix4dv(loc, 1, GL_FALSE, data); break;
                    }
                break;
            }
    }
    template <typename T>
    inline void SetUniform(const std::string& name, const T x)
    {
        SetUniform(name, &x, 1);
    }
public:
//uniform matrices
    template <typename T, len_t N, len_t M>
    inline void SetUniform(const std::string& name, const Matrix<T, N, M>& mat)
    {
        SetUniform<T>(name, mat.GetAddressOf(), N, M);
    }
public:
//uniform vectors
    template <typename T, len_t N>
    inline void SetUniform(const std::string& name, const Vector<T, N>& vec)
    {
        SetUniform<T>(name, vec.GetAddressOf(), N);
    }
public:
//destructor
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
    Shader* m_activeShader = nullptr;
    std::unordered_map<umap_id_t, Shader> m_mapShaders;
public:
    inline Shader& operator[](const umap_id_t& key)
    {
        return m_mapShaders[key];
    }
private:
    inline void SetShader(Shader* shader)
    {
        if(!shader || (m_activeShader && m_activeShader->GetId() == shader->GetId()) || m_mapShaders.empty())
            return;
        m_activeShader = shader;
        m_activeShader->Set();
        m_activeShader->Update();
    }
public:
    inline void SetShader(const umap_id_t& key)
    {
        if(m_mapShaders.count(key))
            SetShader(&m_mapShaders.at(key));
    }
    inline void AddShader(const Shader& shader)
    {
        AddShader(m_mapShaders.size(), shader);
    }
    inline void AddShader(const umap_id_t& key, const Shader& shader)
    {
        this->operator[](key) = shader;
    }
    inline void UpdateShader()
    {
        assert(m_activeShader);
        m_activeShader->Update();
    }
    inline Shader* GetActiveShader()
    {
        return m_activeShader;
    }
};

#endif