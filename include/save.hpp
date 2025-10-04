#ifndef SAVE_HPP
#define SAVE_HPP

inline constexpr std::string_view g_kSeperatorToken = "->";

template <typename T> 
inline std::string Convert(const T& value) 
{
    static_assert(std::is_arithmetic_v<T>);
    return std::to_string(value);
}
template <> inline std::string Convert<bool>(const bool& value) {return value ? "true" : "false";}
template <typename T> inline std::optional<T> Convert(const std::optional<std::string>& str) {}
template <> inline std::optional<f64> Convert<f64>(const std::optional<std::string>& str) 
{return str.has_value() ? std::make_optional(std::stod(str.value().c_str())) : std::nullopt;}
template <> inline std::optional<f32> Convert<f32>(const std::optional<std::string>& str) 
{return str.has_value() ? std::make_optional(std::stof(str.value().c_str())) : std::nullopt;}
template <> inline std::optional<i32> Convert<i32>(const std::optional<std::string>& str) 
{return str.has_value() ? std::make_optional(std::stoi(str.value().c_str())) : std::nullopt;}
template <> inline std::optional<bool> Convert<bool>(const std::optional<std::string>& str)
{
    if(str.has_value())
    {
        if(str.value() == "true") return true;
        else if(str.value() == "false") return false;
        else return std::nullopt;
    }
    return std::nullopt;
}

struct Container
{
    std::string content = "";
    std::optional<std::string> name = std::nullopt;
    template <typename T> 
    inline std::optional<T> Convert()
    {
        return ::Convert<T>(content);
    }
};

inline std::vector<std::string> ParseDirectory(const std::string& dir)
{
    std::vector<std::string> res;
    usize index = 0, next = dir.find_first_of(g_kSeperatorToken, index);
    while(index < dir.size() && next != std::string::npos)
    {
        res.emplace_back(dir.substr(index, next - index));
        index = next + g_kSeperatorToken.size();
        next = dir.find_first_of(g_kSeperatorToken, index);
    }
    if(next == std::string::npos)
        res.emplace_back(dir.substr(index, dir.size() - index));
    return res;    
};

template <typename T>
struct allowed_id_type : std::disjunction<std::is_integral<T>, std::is_convertible<T, std::string>> {};

template <typename T>
struct allowed_data_type : std::disjunction<std::is_arithmetic<T>, std::is_convertible<T, std::string>> {};

template <typename T>
inline constexpr bool allowed_data_type_v = allowed_data_type<T>::value;

template <typename T>
inline constexpr bool allowed_id_type_v = allowed_id_type<T>::value;

struct DataNode
{
    DataNode() = default;
    template <typename DataT, typename IdT> 
    inline void SetData(
        const DataT& data,
        const IdT& id,
        std::enable_if_t<
            allowed_data_type_v<DataT> &&
            allowed_id_type_v<IdT>>* = 0)
    {
        SetString(Convert<DataT>(data), id);
    }
    template <typename IdT> 
    inline void Rename(
        const std::string& name, 
        const IdT& id,
        std::enable_if_t<allowed_id_type_v<IdT>>* = 0)
    {
        auto container = FindContainer(id);
        if(container.has_value()) container.value().get().name = name;
    }
    std::optional<std::reference_wrapper<DataNode>> GetProperty(const std::string& dir);
    void SetString(const std::string& str, const usize& index = 0);
    void SetString(const std::string& str, const std::string& name);
    std::optional<std::string> GetName(const usize& index = 0);
    bool HasProperty(const std::string& dir);
    void ForeachContainer(std::function<void(Container)> f);
    void IndexedForeachContainer(std::function<void(Container, usize index)> f);
    void ForeachNode(std::function<void(std::pair<std::string, DataNode>)> f);
    void IndexedForeachNode(std::function<void(std::pair<std::string, DataNode>, usize)> f);
    std::optional<std::reference_wrapper<Container>> FindContainer(const usize& index = 0);
    std::optional<std::reference_wrapper<Container>> FindContainer(const std::string& name);
    void SetData(const std::string& str);
    const std::string GetData() const;
    DataNode& operator[](const std::string& str);
    void Clear();
    std::vector<Container> m_vecContainers;
    std::unordered_map<std::string, DataNode> m_mapNodes;
};

void Serialize(DataNode& node, const std::string& file)
{
    std::ofstream output(file.c_str(), std::ios::trunc);
    int tabCount = 0;
    auto Indent = [](int count)->std::string
    {
        std::string res;
        for(int index = 0; index < count; index++) res += '\t';
        return res;
    };
    auto AddBrackets = [](const std::string& str) -> std::string
    {
        using std::literals::string_view_literals::operator""sv;
        if(" \n\v\t\0"sv.find_first_of(str) != std::string_view::npos) return '[' + str + ']';
        else return str;
    };
    auto Write = [&](std::pair<std::string, DataNode> p) -> void
    {
        auto WriteNode = [&](std::pair<std::string, DataNode> p, auto& WriteRef) mutable -> void
        {
            const std::string name = AddBrackets(p.first) + '>';
            if(!p.second.m_mapNodes.empty())
            {
                output << Indent(tabCount++) << '<' << name << '\n';
                if(!p.second.m_vecContainers.empty()) output << Indent(tabCount) << AddBrackets(p.second.GetData()) << '\n';
                for(auto& node : p.second.m_mapNodes) WriteRef(node, WriteRef);
                output << Indent(--tabCount) << "</" << name << '\n';
            }
            else
            {
                output << Indent(tabCount) << '<' << name << AddBrackets(p.second.GetData()) << "</" << name << '\n';
            }
        };
        WriteNode(p, WriteNode);
    };
    if(!node.m_vecContainers.empty()) output << Indent(tabCount) << '{' << AddBrackets(node.GetData()) << '}' << '\n';
    for(auto& p : node.m_mapNodes) Write(p);
    output.close();
}

struct Token
{
    enum class Type : uint8_t
    {
        VariableName,
        VariableValue,
        ContainerName,
        CloseBracket,
        OpenBracket,
        CloseParentheses,
        OpenParentheses,
        OpenSquareBracket,
        CloseSquareBracket,
        ComparisonOpLeft,
        ComparisonOpRight,
        Slash,
        Comma,
        None
    };
    std::string value = "";
    Token::Type type = Token::Type::None;
    Token() = default;
    Token(const std::string& value, const Token::Type& type) : value(value), type(type) {}
};

const std::unordered_map<char, Token::Type> tokenTypeMap = 
{
    {'{', Token::Type::OpenBracket},
    {'}', Token::Type::CloseBracket},
    {',', Token::Type::Comma},
    {'/', Token::Type::Slash},
    {'(', Token::Type::OpenParentheses},
    {')', Token::Type::CloseParentheses},
    {'[', Token::Type::OpenSquareBracket},
    {']', Token::Type::CloseSquareBracket},
    {'<', Token::Type::ComparisonOpLeft},
    {'>', Token::Type::ComparisonOpRight}
};

const std::unordered_map<Token::Type, std::list<Token::Type>> expectedTokenMap = 
{
    {Token::Type::VariableName, {Token::Type::CloseParentheses}},
    {Token::Type::ContainerName, {Token::Type::ComparisonOpRight}},
    {Token::Type::CloseBracket, {Token::Type::ComparisonOpLeft}},
    {Token::Type::VariableValue, {Token::Type::Comma, Token::Type::CloseBracket}},
    {Token::Type::CloseParentheses, {Token::Type::VariableValue, Token::Type::Comma}},
    {Token::Type::Slash, {Token::Type::ContainerName, Token::Type::ComparisonOpRight}},
    {Token::Type::OpenParentheses, {Token::Type::VariableName, Token::Type::CloseParentheses}},
    {Token::Type::ComparisonOpRight, {Token::Type::ComparisonOpLeft, Token::Type::OpenBracket}},
    {Token::Type::OpenBracket, {Token::Type::VariableValue, Token::Type::OpenParentheses, Token::Type::Comma}},
    {Token::Type::ComparisonOpLeft, {Token::Type::ContainerName, Token::Type::Slash, Token::Type::ComparisonOpRight}},
    {Token::Type::Comma, {Token::Type::Comma, Token::Type::VariableValue, Token::Type::CloseBracket, Token::Type::OpenParentheses}},
    {Token::Type::None, {}}
};

std::vector<Token> Tokenize(const std::string& data)
{
    std::vector<Token> res;
    std::string buffer;
    int openBracketCount = 0;

    auto Contains = [](const std::list<Token::Type>& list, const Token::Type& t) -> bool {return std::find(list.begin(), list.end(), t) != list.end();};

    auto PushExpectedToken = [Contains, &openBracketCount, &res, &buffer](const Token::Type& type) -> void
    {
        if(type == Token::Type::OpenSquareBracket)
            openBracketCount++;
        else if(type == Token::Type::CloseSquareBracket)
            openBracketCount--;
        else if(res.empty() || (!res.empty() && Contains(expectedTokenMap.at(res.back().type), type)))
            res.emplace_back(buffer, type);
        else
            throw std::runtime_error("Invalid Token!");
    };

    for(const char c : data)
    {
        if(tokenTypeMap.count(c))
        {
            if(!buffer.empty())
            {
                Token::Type type = Token::Type::None;
                if(!res.empty())
                {
                    switch(res.back().type)
                    {
                        case Token::Type::ComparisonOpLeft:
                        case Token::Type::Slash:
                            type = Token::Type::ContainerName;
                        break;
                        case Token::Type::OpenParentheses:
                            type = Token::Type::VariableName;
                        break;
                        case Token::Type::OpenBracket:
                        case Token::Type::Comma:
                        case Token::Type::CloseParentheses:
                            type = Token::Type::VariableValue;
                        break;
                        default:
                        break;
                    }
                }
                PushExpectedToken(type);
                buffer.clear();
            }
            PushExpectedToken(tokenTypeMap.at(c));
        }
        else
        {
            if(std::isspace(c) && !openBracketCount);
            else buffer.push_back(c);
        }
    }
    return res;
}

void Deserialize(std::reference_wrapper<DataNode> node, const std::string& path)
{
    node.get().Clear();
    std::ifstream file(path);
    std::stack<std::pair<std::reference_wrapper<DataNode>, std::string>> nodeStack;
   
    const std::vector<Token>& vecTokens = Tokenize({std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()});
    
    for(usize i = 0; i < vecTokens.size(); i++)
    {
        switch(vecTokens[i].type)
        {
            case Token::Type::ContainerName:
            {
                if(vecTokens[i - 1].type == Token::Type::Slash)
                {
                    if(!nodeStack.empty() && nodeStack.top().second == vecTokens[i].value)
                        nodeStack.pop();
                }
                else if(vecTokens[i - 1].type == Token::Type::ComparisonOpLeft)
                {
                    std::reference_wrapper<DataNode> newNode = nodeStack.empty() ? node.get()[vecTokens[i].value] : nodeStack.top().first.get()[vecTokens[i].value];
                    nodeStack.push(std::make_pair(newNode, vecTokens[i].value));
                }
                else
                {
                    file.close();
                    throw std::runtime_error("Invalid Token!");
                }
            }
            break;
            case Token::Type::VariableValue:
                nodeStack.top().first.get().m_vecContainers.back().content = vecTokens[i].value;
            break;
            case Token::Type::VariableName:
                nodeStack.top().first.get().m_vecContainers.back().name = vecTokens[i].value;
            break;
            case Token::Type::OpenBracket:
            case Token::Type::Comma:
            {
                if(nodeStack.empty())
                {
                    file.close();
                    throw std::runtime_error("Empty Stack!");
                }
                nodeStack.top().first.get().m_vecContainers.emplace_back();
            }
            break;
            default:
            break;
        }
    }

    file.close();
}

template <typename IdT> 
inline std::optional<std::string> GetString(
    std::optional<DataNode> node, 
    const IdT& id,
    std::enable_if_t<allowed_id_type_v<IdT>>* = 0)
{
    if(node.has_value())
    {
        auto container = node.value().FindContainer(id);
        return container.has_value() ? std::make_optional(container.value().get().content) : std::nullopt;
    }
    return std::nullopt;
}

template <typename DataT, typename IdT> 
inline std::optional<DataT> GetData(
    std::optional<DataNode> node, 
    const IdT& id,
    std::enable_if_t<
        allowed_id_type_v<IdT> &&
        allowed_data_type_v<DataT>>* = 0)
{
    return Convert<DataT>(GetString(node, id));
}

#endif

#ifdef SAVE_HPP
#undef SAVE_HPP

inline std::optional<std::reference_wrapper<Container>> DataNode::FindContainer(const usize& index)
{
#if defined NO_COLLISIONS
    for(usize i = 0, count = 0; i < m_vecContainers.size(); i++)
    {
        if(count == index)
            return m_vecContainers[i];
        count += !m_vecContainers[i].name.has_value();
    }
    return std::nullopt;
#else
    if(index < m_vecContainers.size()) return m_vecContainers[index];
    else return std::nullopt;
#endif
}

inline std::optional<std::reference_wrapper<Container>> DataNode::FindContainer(const std::string& name)
{
    for(auto& container : m_vecContainers)
        if(container.name.has_value() && container.name.value() == name)
            return container;
    return std::nullopt;
}

inline void DataNode::SetString(const std::string& str, const usize& index)
{
    auto container = FindContainer(index);
    if(container.has_value()) 
    {
        container.value().get().content = str;
        return;
    }
#ifdef NO_COLLISIONS
    usize size = m_vecContainers.size();
    for(usize i = 0, count = 0; i < size; i++)
    {
        if(index > count && i == size - 1)
            m_vecContainers.resize(size = size + index - count);
        else if(index == count)
        {
            m_vecContainers[i].content = str;
            return;
        }
        count += !m_vecContainers[i].name.has_value();
    }
#else
    if(m_vecContainers.size() <= index)
    {
        m_vecContainers.resize(index);
        m_vecContainers.back().content = str;
    }
    else
        m_vecContainers[index].content = str;
#endif
}

inline void DataNode::SetString(const std::string& str, const std::string& name)
{
    auto container = FindContainer(name);
    if(container.has_value())
    {
        container.value().get().content = str;
        return;
    }
    m_vecContainers.push_back({str, name.empty() ? std::nullopt : std::make_optional(name)});
}

inline std::optional<std::string> DataNode::GetName(const usize& index)
{
    auto container = FindContainer(index);
    return container.has_value() ? container.value().get().name : std::nullopt;
}

inline DataNode& DataNode::operator[](const std::string& str)
{
    return m_mapNodes[str];
}

inline void DataNode::ForeachNode(std::function<void(std::pair<std::string, DataNode>)> f)
{
    for(auto& node : m_mapNodes) f(node);
}

inline void DataNode::ForeachContainer(std::function<void(Container)> f)
{
    for(auto& c : m_vecContainers) f(c);
}

inline void DataNode::IndexedForeachNode(std::function<void(std::pair<std::string, DataNode>, usize)> f)
{
    usize index = 0;
    for(auto iter = m_mapNodes.begin(); iter != m_mapNodes.end(); iter++)
        f(*iter, index++);
}

inline void DataNode::IndexedForeachContainer(std::function<void(Container, usize index)> f)
{
    for(usize index = 0; index < m_vecContainers.size(); index++)
        f(m_vecContainers[index], index);
}

inline std::optional<std::reference_wrapper<DataNode>> DataNode::GetProperty(const std::string& directory)
{
    std::reference_wrapper<DataNode> res = *this;
    const std::vector<std::string>& vecElements = ParseDirectory(directory);
    for(const std::string& str : vecElements)
    {
        if(res.get().m_mapNodes.count(str) != 0)
            res = res.get()[str];
        else
            return std::nullopt;
    }
    return res;
}

inline bool DataNode::HasProperty(const std::string& directory)
{
    std::reference_wrapper<DataNode> node = *this;
    const std::vector<std::string>& vecElements = ParseDirectory(directory);
    for(const std::string& str : vecElements)
    {
        if(node.get().m_mapNodes.count(str) == 0)
            return false;
        else
            node = node.get()[str];
    }
    return true;
}

inline void DataNode::Clear()
{
    m_vecContainers.clear();
    for(auto& [name, node] : m_mapNodes) node.Clear();
    m_mapNodes.clear();
}

inline void DataNode::SetData(const std::string& data)
{
    m_vecContainers.clear();
    const std::vector<Token>& vecTokens = Tokenize(data);
    for(usize i = 0; i < vecTokens.size(); i++)
    {
        if(m_vecContainers.empty())
            m_vecContainers.emplace_back();
        switch(vecTokens[i].type)
        {
            case Token::Type::Comma:
                m_vecContainers.emplace_back();
            break;
            case Token::Type::VariableValue:
                m_vecContainers.back().content = vecTokens[i].value;
            break;
            case Token::Type::VariableName:
                m_vecContainers.back().name = vecTokens[i].value;
            break;
            default: break;
        }
    }
}

inline const std::string DataNode::GetData() const
{
    std::string res = "{";
    const usize size = m_vecContainers.size();
    for(usize i = 0; i < size; i++)
    {
        const Container& container = m_vecContainers[i];
        if(container.name.has_value()) res.append('(' + container.name.value() + ')');
        res.append(container.content);
        if(i != size - 1) res.push_back(',');
    }
    return res + '}';
}

#endif