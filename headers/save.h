#ifndef SAVE_H
#define SAVE_H

#include "includes.h"

const std::string whitespaces = " \n\t\v\0";
const std::string seperator = "->";

template <typename T> 
inline std::string convert(const T& value) 
{
    static_assert(std::is_arithmetic<T>::value);
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
    std::string content;
    std::optional<std::string> name = std::nullopt;
    template <typename T> inline std::optional<T> get()
    {
        return convert<T>(content);
    }
};

inline std::vector<std::string> ParseDirectory(const std::string& dir)
{
    std::vector<std::string> directory;
    std::string buffer;
    auto ClearBuffer = [&]()
    {   
        directory.push_back(buffer);
        buffer.clear();
    };
    size_t index = 0, next = dir.find_first_of(seperator, index);
    while(index < dir.size() && next != std::string::npos)
    {
        directory.push_back(dir.substr(index, next - index));
        index = next + seperator.size();
        next = dir.find_first_of(seperator, index);
    }
    if(next == std::string::npos)
        directory.push_back(dir.substr(index, dir.size() - index));
    return directory;    
};

template <typename T> struct allowed_id_type :
    std::integral_constant<bool, 
        std::is_integral<T>::value ||
        std::is_convertible<T, std::string>::value>
    {};

template <typename T> struct allowed_data_type : 
    std::integral_constant<bool,
        std::is_arithmetic<T>::value ||
        std::is_same<T, bool>::value>
    {};

struct DataNode
{
    DataNode() = default;
    template <typename Data, typename ID> 
    inline void SetData(
        const Data& data, 
        const ID& id,
        typename std::enable_if<allowed_data_type<Data>::value && allowed_id_type<ID>::value>::type* = 0)
    {
        SetString(convert<Data>(data), id);
    }
    template <typename ID> 
    inline void Rename(
        const std::string& name, 
        const ID& id,
        typename std::enable_if<allowed_id_type<ID>::value>::type* = 0)
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
    void SetData(const std::string& str);
    const std::string GetData() const;
    void clear();
    const DataNode& at(const std::string& str) const;
    DataNode& operator[](const std::string& str);
    std::vector<Container> data;
    std::unordered_map<std::string, DataNode> nodes;
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
            if(!p.second.nodes.empty())
            {
                output << Indent(tabCount++) << '<' << name << '\n';
                if(!p.second.data.empty()) output << Indent(tabCount) << data << '\n';
                for(auto& node : p.second.nodes) WriteRef(node, WriteRef);
                output << Indent(--tabCount) << "</" << name << '\n';
            }
            else
            {
                output << Indent(tabCount) << '<' << name << data << "</" << name << '\n';
            }
        };
        WriteNode(p, WriteNode);
    };
    if(!node.data.empty()) output << Indent(tabCount) << '{' << AddBrackets(node.GetData()) << '}' << '\n';
    for(auto& p : node.nodes) Write(p);
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
    {Token::Type::Slash, {Token::Type::ContainerName}},
    {Token::Type::VariableName, {Token::Type::CloseParentheses}},
    {Token::Type::ContainerName, {Token::Type::ComparisonOpRight}},
    {Token::Type::CloseBracket, {Token::Type::ComparisonOpLeft}},
    {Token::Type::VariableValue, {Token::Type::Comma, Token::Type::CloseBracket}},
    {Token::Type::CloseParentheses, {Token::Type::VariableValue, Token::Type::Comma}},
    {Token::Type::ComparisonOpLeft, {Token::Type::ContainerName, Token::Type::Slash}},
    {Token::Type::OpenParentheses, {Token::Type::VariableName, Token::Type::CloseParentheses}},
    {Token::Type::Comma, {Token::Type::Comma, Token::Type::VariableValue, Token::Type::CloseBracket}},
    {Token::Type::OpenBracket, {Token::Type::VariableValue, Token::Type::OpenParentheses, Token::Type::Comma}},
    {Token::Type::ComparisonOpRight, {Token::Type::ComparisonOpLeft, Token::Type::OpenBracket}},
    {Token::Type::None, {}}
};

void Deserialize(std::reference_wrapper<DataNode> node, const std::string& path)
{
    node.get().clear();
    std::ifstream file(path.c_str());
    std::stack<std::pair<std::reference_wrapper<DataNode>, std::string>> nodeStack;
    std::vector<Token> vecTokens;
    std::string buffer;

    int openBracketCount = 0;
    char c;

    auto TerminateParsing = [&]()
    {
        buffer.clear();
        vecTokens.clear();
        file.close();
    };

    auto Contains = [](const std::list<Token::Type>& list, const Token::Type& t) -> bool {return std::find(list.begin(), list.end(), t) != list.end();};

    auto PushExpectedToken = [Contains, &openBracketCount, TerminateParsing, &vecTokens, &buffer](const Token::Type& type) -> void
    {
        if(type == Token::Type::OpenSquareBracket)
            openBracketCount++;
        else if(type == Token::Type::CloseSquareBracket)
            openBracketCount--;
        else if(vecTokens.empty() || (!vecTokens.empty() && Contains(expectedTokenMap.at(vecTokens.back().type), type)))
            vecTokens.emplace_back(buffer, type);
        else
        {
            TerminateParsing();
            throw std::runtime_error("Invalid Token!");
        }
    };

    while(file.get(c))
    {
        if(tokenTypeMap.count(c))
        {
            if(!buffer.empty())
            {
                Token::Type type = Token::Type::None;
                if(!vecTokens.empty())
                {
                    switch(vecTokens.back().type)
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
                    TerminateParsing();
                    throw std::runtime_error("Invalid Token!");
                }
            }
            break;
            case Token::Type::VariableValue:
                nodeStack.top().first.get().data.back().content = vecTokens[i].value;
            break;
            case Token::Type::VariableName:
                nodeStack.top().first.get().data.back().name = vecTokens[i].value;
            break;
            case Token::Type::OpenBracket:
            case Token::Type::Comma:
            {
                if(nodeStack.empty())
                {
                    TerminateParsing();
                    throw std::runtime_error("Empty Stack!");
                }
                nodeStack.top().first.get().data.emplace_back();
            }
            break;
        }
    }

    TerminateParsing();
}

template <typename ID> 
inline std::optional<std::string> GetString(
    std::optional<DataNode> node, 
    const ID& id,
    typename std::enable_if<allowed_id_type<ID>::value>::type* = 0)
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
    typename std::enable_if<allowed_id_type<ID>::value && allowed_data_type<Data>::value>::type* = 0)
{
    return convert<Data>(GetString(node, id));
}

#endif

#ifdef SAVE_H
#undef SAVE_H


inline std::optional<std::reference_wrapper<Container>> DataNode::FindContainer(const size_t& index)
{
#if defined NO_COLLISIONS
    for(size_t i = 0, count = 0; i < data.size(); i++, count += data[i].name.has_value() ? 0 : 1)
        if(count == index)
            return data[i];
    return std::nullopt;
#else
    if(index < data.size()) return data[index];
    else return std::nullopt;
#endif
}

inline std::optional<std::reference_wrapper<Container>> DataNode::FindContainer(const std::string& name)
{
    for(auto& element : data)
        if(element.name.has_value() && element.name.value() == name)
            return element;
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
    if(data.size() > index)
        data[index].content = str;
    else
    {
        data.resize(index + 1);
        data.back().content = str;
    }
}

inline void DataNode::SetString(const std::string& str, const std::string& name)
{
    auto container = FindContainer(name);
    if(container.has_value())
    {
        container.value().get().content = str;
        return;
    }
    data.push_back({str, name.empty() ? std::nullopt : std::make_optional(name)});
}

inline std::optional<std::string> DataNode::GetName(const size_t& index)
{
    auto container = FindContainer(index);
    return container.has_value() ? container.value().get().name : std::nullopt;
}

inline DataNode& DataNode::operator[](const std::string& str)
{
    if(nodes.count(str) == 0) nodes[str] = DataNode();
    return nodes[str];
}

inline void DataNode::nodes_foreach(std::function<void(std::pair<std::string, DataNode>)> f)
{
    for(auto& node : nodes) f(node);
}

inline void DataNode::data_foreach(std::function<void(Container)> f)
{
    for(auto& c : data) f(c);
}

inline void DataNode::nodes_indexed_for(std::function<void(std::pair<std::string, DataNode>, size_t)> f)
{
    size_t index = 0;
    for(auto iter = nodes.begin(); iter != nodes.end(); iter++)
        f(*iter, index++);
}

inline void DataNode::data_indexed_for(std::function<void(Container, size_t index)> f)
{
    for(size_t index = 0; index < data.size(); index++)
        f(data[index], index);
}

inline std::optional<std::reference_wrapper<DataNode>> DataNode::GetProperty(const std::string& directory)
{
    std::reference_wrapper<DataNode> res = *this;
    for(auto& element : ParseDirectory(directory))
    {
        if(res.get().nodes.count(element) != 0)
            res = res.get()[element];
        else
            return std::nullopt;
    }
    return res;
}

inline bool DataNode::HasProperty(const std::string& directory)
{
    std::reference_wrapper<DataNode> node = *this;
    for(auto& element : ParseDirectory(directory))
    {
        if(node.get().nodes.count(element) == 0)
            return false;
        else
            node = node.get()[element];
    }
    return true;
}

inline void DataNode::clear()
{
    data.clear();
    for(auto& node : nodes) node.second.clear();
    nodes.clear();
}

inline const DataNode& DataNode::at(const std::string& str) const
{
    return nodes.at(str);
}

inline void DataNode::SetData(const std::string& str)
{
    data.clear();
    auto ClearBuffer = [&](const std::string& buffer)
    {
        Container container;
        for(size_t index = 0; index < buffer.size(); index++)
        {
            if(buffer.at(index) == '(')
            {
                const size_t end = buffer.find_first_of(')', ++index);
                container.name = buffer.substr(index, end - index);
                index = end;
            }
            else
                container.content += buffer.at(index);
        }
        data.push_back(container);
    };
    size_t index = 0, next = str.find_first_of(',', index);
    while(index < str.size() && next != std::string::npos)
    {
        ClearBuffer(str.substr(index, next - index));
        index = next;
        next = str.find_first_of(',', ++index);
    }
    if(next == std::string::npos)
        ClearBuffer(str.substr(index, str.size() - index));    
}

inline const std::string DataNode::GetData() const
{
    std::string res;
    size_t index = 0;
    while(index < data.size()) 
    {
        res += data.at(index).name.has_value() ? '(' + data.at(index).name.value() + ')' : "";
        res += data.at(index).content;
        res += ++index < data.size() ? "," : "";
    }
    return res;
}

#endif