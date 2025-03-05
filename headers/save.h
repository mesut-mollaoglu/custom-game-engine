#ifndef SAVE_H
#define SAVE_H

const std::string whitespaces = " \n\t\v\0";
const std::string seperator = "->";

template <typename T> 
inline std::string convert(const T& value) 
{
    static_assert(std::is_arithmetic_v<T>);
    return std::to_string(value);
}
template <> inline std::string convert<bool>(const bool& value) {return value ? "true" : "false";}
template <typename T> inline std::optional<T> convert(const std::optional<std::string>& str) {}
template <> inline std::optional<double> convert<double>(const std::optional<std::string>& str) 
{return str.has_value() ? std::make_optional(std::stod(str.value().c_str())) : std::nullopt;}
template <> inline std::optional<float> convert<float>(const std::optional<std::string>& str) 
{return str.has_value() ? std::make_optional(std::stof(str.value().c_str())) : std::nullopt;}
template <> inline std::optional<int> convert<int>(const std::optional<std::string>& str) 
{return str.has_value() ? std::make_optional(std::stoi(str.value().c_str())) : std::nullopt;}
template <> inline std::optional<bool> convert<bool>(const std::optional<std::string>& str)
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
    inline std::optional<T> get()
    {
        return convert<T>(content);
    }
};

inline std::vector<std::string> ParseDirectory(const std::string& dir)
{
    std::vector<std::string> res;
    size_t index = 0, next = dir.find_first_of(seperator, index);
    while(index < dir.size() && next != std::string::npos)
    {
        res.emplace_back(dir.substr(index, next - index));
        index = next + seperator.size();
        next = dir.find_first_of(seperator, index);
    }
    if(next == std::string::npos)
        res.emplace_back(dir.substr(index, dir.size() - index));
    return res;    
};

template <typename T> struct allowed_id_type :
    std::integral_constant<bool, 
        std::is_integral_v<T> ||
        std::is_convertible_v<T, std::string>>
    {};

template <typename T> struct allowed_data_type : 
    std::integral_constant<bool,
        std::is_arithmetic_v<T> ||
        std::is_same_v<T, bool>>
    {};

template <typename T>
inline constexpr bool allowed_data_type_v = allowed_data_type<T>::value;

template <typename T>
inline constexpr bool allowed_id_type_v = allowed_id_type<T>::value;

struct DataNode
{
    DataNode() = default;
    template <typename Data, typename ID> 
    inline void SetData(
        const Data& data, 
        const ID& id,
        typename std::enable_if_t<allowed_data_type_v<Data> && allowed_id_type_v<ID>>* = 0)
    {
        SetString(convert<Data>(data), id);
    }
    template <typename ID> 
    inline void Rename(
        const std::string& name, 
        const ID& id,
        typename std::enable_if_t<allowed_id_type_v<ID>>* = 0)
    {
        auto container = FindContainer(id);
        if(container.has_value()) container.value().get().name = name;
    }
    std::optional<std::reference_wrapper<DataNode>> GetProperty(const std::string& dir);
    void SetString(const std::string& str, const size_t& index = 0);
    void SetString(const std::string& str, const std::string& name);
    std::optional<std::string> GetName(const size_t& index = 0);
    bool HasProperty(const std::string& dir);
    void data_foreach(std::function<void(Container)> f);
    void data_indexed_for(std::function<void(Container, size_t index)> f);
    void nodes_foreach(std::function<void(std::pair<std::string, DataNode>)> f);
    void nodes_indexed_for(std::function<void(std::pair<std::string, DataNode>, size_t)> f);
    std::optional<std::reference_wrapper<Container>> FindContainer(const size_t& index = 0);
    std::optional<std::reference_wrapper<Container>> FindContainer(const std::string& name);
    const DataNode& at(const std::string& str) const;
    void SetData(const std::string& str);
    const std::string GetData() const;
    void clear();
    DataNode& operator[](const std::string& str);
    std::vector<Container> vecContainers;
    std::unordered_map<std::string, DataNode> nodesMap;
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
    auto AddBrackets = [](std::string str)->std::string
    {
        if(str.find(whitespaces.c_str(), 0, 1) != std::string::npos) return '[' + str + ']';
        else return str;
    };
    auto Write = [&](std::pair<std::string, DataNode> p) -> void
    {
        auto WriteNode = [&](std::pair<std::string, DataNode> p, auto& WriteRef) mutable -> void
        {
            const std::string name = AddBrackets(p.first) + '>';
            const std::string data = '{' + AddBrackets(p.second.GetData()) + '}';
            if(!p.second.nodesMap.empty())
            {
                output << Indent(tabCount++) << '<' << name << '\n';
                if(!p.second.vecContainers.empty()) output << Indent(tabCount) << data << '\n';
                for(auto& node : p.second.nodesMap) WriteRef(node, WriteRef);
                output << Indent(--tabCount) << "</" << name << '\n';
            }
            else
            {
                output << Indent(tabCount) << '<' << name << data << "</" << name << '\n';
            }
        };
        WriteNode(p, WriteNode);
    };
    if(!node.vecContainers.empty()) output << Indent(tabCount) << '{' << AddBrackets(node.GetData()) << '}' << '\n';
    for(auto& p : node.nodesMap) Write(p);
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
                    }
                }
                PushExpectedToken(type);
                buffer.clear();
            }
            PushExpectedToken(tokenTypeMap.at(c));
        }
        else
        {
            if(whitespaces.find(c) != std::string::npos && !openBracketCount);
            else buffer.push_back(c);
        }
    }
    return res;
}

void Deserialize(std::reference_wrapper<DataNode> node, const std::string& path)
{
    node.get().clear();
    std::ifstream file(path);
    std::stack<std::pair<std::reference_wrapper<DataNode>, std::string>> nodeStack;
   
    const std::vector<Token>& vecTokens = Tokenize({std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()});
    
    for(size_t i = 0; i < vecTokens.size(); i++)
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
                nodeStack.top().first.get().vecContainers.back().content = vecTokens[i].value;
            break;
            case Token::Type::VariableName:
                nodeStack.top().first.get().vecContainers.back().name = vecTokens[i].value;
            break;
            case Token::Type::OpenBracket:
            case Token::Type::Comma:
            {
                if(nodeStack.empty())
                {
                    file.close();
                    throw std::runtime_error("Empty Stack!");
                }
                nodeStack.top().first.get().vecContainers.emplace_back();
            }
            break;
        }
    }

    file.close();
}

template <typename ID> 
inline std::optional<std::string> GetString(
    std::optional<DataNode> node, 
    const ID& id,
    typename std::enable_if_t<allowed_id_type_v<ID>>* = 0)
{
    if(node.has_value())
    {
        auto container = node.value().FindContainer(id);
        return container.has_value() ? std::make_optional(container.value().get().content) : std::nullopt;
    }
    return std::nullopt;
}

template <typename Data, typename ID> 
inline std::optional<Data> GetData(
    std::optional<DataNode> node, 
    const ID& id,
    typename std::enable_if_t<allowed_id_type_v<ID> && allowed_data_type_v<Data>>* = 0)
{
    return convert<Data>(GetString(node, id));
}

#endif

#ifdef SAVE_H
#undef SAVE_H


inline std::optional<std::reference_wrapper<Container>> DataNode::FindContainer(const size_t& index)
{
#if defined NO_COLLISIONS
    for(size_t i = 0, count = 0; i < vecContainers.size(); i++)
    {
        if(count == index)
            return vecContainers[i];
        count += !vecContainers[i].name.has_value();
    }
    return std::nullopt;
#else
    if(index < vecContainers.size()) return vecContainers[index];
    else return std::nullopt;
#endif
}

inline std::optional<std::reference_wrapper<Container>> DataNode::FindContainer(const std::string& name)
{
    for(auto& container : vecContainers)
        if(container.name.has_value() && container.name.value() == name)
            return container;
    return std::nullopt;
}

inline void DataNode::SetString(const std::string& str, const size_t& index)
{
    auto container = FindContainer(index);
    if(container.has_value()) 
    {
        container.value().get().content = str;
        return;
    }
#ifdef NO_COLLISIONS
    size_t size = vecContainers.size();
    for(size_t i = 0, count = 0; i < size; i++)
    {
        if(index > count && i == size - 1)
            vecContainers.resize(size = size + index - count);
        else if(index == count)
        {
            vecContainers[i].content = str;
            return;
        }
        count += !vecContainers[i].name.has_value();
    }
#else
    if(vecContainers.size() <= index)
    {
        vecContainers.resize(index);
        vecContainers.back().content = str;
    }
    else
        vecContainers[index].content = str;
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
    vecContainers.push_back({str, name.empty() ? std::nullopt : std::make_optional(name)});
}

inline std::optional<std::string> DataNode::GetName(const size_t& index)
{
    auto container = FindContainer(index);
    return container.has_value() ? container.value().get().name : std::nullopt;
}

inline DataNode& DataNode::operator[](const std::string& str)
{
    return nodesMap[str];
}

inline void DataNode::nodes_foreach(std::function<void(std::pair<std::string, DataNode>)> f)
{
    for(auto& node : nodesMap) f(node);
}

inline void DataNode::data_foreach(std::function<void(Container)> f)
{
    for(auto& c : vecContainers) f(c);
}

inline void DataNode::nodes_indexed_for(std::function<void(std::pair<std::string, DataNode>, size_t)> f)
{
    size_t index = 0;
    for(auto iter = nodesMap.begin(); iter != nodesMap.end(); iter++)
        f(*iter, index++);
}

inline void DataNode::data_indexed_for(std::function<void(Container, size_t index)> f)
{
    for(size_t index = 0; index < vecContainers.size(); index++)
        f(vecContainers[index], index);
}

inline std::optional<std::reference_wrapper<DataNode>> DataNode::GetProperty(const std::string& directory)
{
    std::reference_wrapper<DataNode> res = *this;
    const std::vector<std::string>& vecElements = ParseDirectory(directory);
    for(const std::string& str : vecElements)
    {
        if(res.get().nodesMap.count(str) != 0)
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
        if(node.get().nodesMap.count(str) == 0)
            return false;
        else
            node = node.get()[str];
    }
    return true;
}

inline void DataNode::clear()
{
    vecContainers.clear();
    for(auto& node : nodesMap) node.second.clear();
    nodesMap.clear();
}

inline const DataNode& DataNode::at(const std::string& str) const
{
    return nodesMap.at(str);
}

inline void DataNode::SetData(const std::string& data)
{
    vecContainers.clear();
    const std::vector<Token>& vecTokens = Tokenize(data);
    for(size_t i = 0; i < vecTokens.size(); i++)
    {
        if(vecContainers.empty())
            vecContainers.emplace_back();
        switch(vecTokens[i].type)
        {
            case Token::Type::Comma:
                vecContainers.emplace_back();
            break;
            case Token::Type::VariableValue:
                vecContainers.back().content = vecTokens[i].value;
            break;
            case Token::Type::VariableName:
                vecContainers.back().name = vecTokens[i].value;
            break;
            default: break;
        }
    }
}

inline const std::string DataNode::GetData() const
{
    std::string res;
    const size_t size = vecContainers.size();
    for(size_t i = 0; i < size; i++)
    {
        const Container& container = vecContainers[i];
        if(container.name.has_value()) res.append('(' + container.name.value() + ')');
        res.append(container.content);
        if(i != size - 1) res.push_back(',');
    }
    return res;
}

#endif