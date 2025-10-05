#ifndef MENU_HPP
#define MENU_HPP

template <typename StateEnum>
class Menu
{
private:
    std::unordered_map<std::string, Menu<StateEnum>> m_mapSubMenus;
    std::vector<std::string> m_vecMenuNames;
    std::optional<StateEnum> m_activeStateId = std::nullopt;
private:
    Color m_colBackground = Colors::Black;
    Color m_colBorder = Colors::White;
    Color m_colSelected = Colors::Gray;
    Color m_colDefault = Colors::White;
    Color m_colDisabled = Colors::DarkGray;
private:
    ivec2 m_itemPadding = {5, 3};
    ivec2 m_cursorPos = ivec2::Zero();
    ivec2 m_tableSize = ivec2::Zero();
    ivec2 m_pos = vec2::Zero();
    vec2 m_textOrigin = vec2::Zero();
    vec2 m_subMenuOffset = {5.0f, 4.0f};
    vec2 m_backgroundSize;
    vec2 m_scale = vec2::One();
    f32 m_lineWidth = 1.0f;
    bool m_menuEnabled = true;
public:
    inline void SetOrigin(const vec2& origin) 
    {
        m_textOrigin = origin;
    }
    inline void SetOrigin(f32 x, f32 y) 
    {
        m_textOrigin.x = x;
        m_textOrigin.y = y;
    }
    inline const vec2& GetOrigin() const 
    {
        return m_textOrigin;
    }
    inline void SetLineWidth(f32 w)
    {
        m_lineWidth = w;
    }
    inline f32 GetLineWidth() const
    {
        return m_lineWidth;
    }
    inline void SetScaleFactor(const vec2& scale) 
    {
        m_scale = scale;
    }
    inline void SetScaleFactor(f32 sx, f32 sy)
    {
        m_scale.x = sx;
        m_scale.y = sy;
    }
    inline const vec2& GetScaleFactor() const 
    {
        return m_scale;
    }
    inline void SetPos(const ivec2& pos) 
    {
        m_pos = pos;
    }
    inline void SetPos(i32 x, i32 y) 
    {
        m_pos.x = x;
        m_pos.y = y;
    }
    inline const ivec2& GetPos() const 
    {
        return m_pos;
    }
    inline void Enable(bool enabled) 
    {
        m_menuEnabled = enabled;
    }
    inline bool IsEnabled()
    {
        return m_menuEnabled;
    }
    inline const ivec2& GetTableSize() const 
    {
        return m_tableSize;
    }
    inline void SetTableSize(const ivec2& size) 
    {
        m_tableSize = size;
    }
    inline void SetTableSize(i32 x, i32 y) 
    {
        m_tableSize.x = x;
        m_tableSize.y = y;
    }
    inline const std::optional<StateEnum>& GetId() const 
    {
        return m_activeStateId;
    }
    inline void SetId(const StateEnum& id) 
    {
        m_activeStateId = id;
    }
    inline void SetBackgroundColor(const Color& c) 
    {
        m_colBackground = c;
    }
    inline void SetOutlineColor(const Color& c) 
    {
        m_colBorder = c;
    }
    inline void SetSelectedOptionColor(const Color& c) 
    {
        m_colSelected = c;
    }
    inline void SetDefaulOptionColor(const Color& c) 
    {
        m_colDefault = c;
    }
    inline void SetDisabledOptionColor(const Color& c) 
    {
        m_colDisabled = c;
    }
    inline const Color& GetBackgroundColor() const 
    {
        return m_colBackground;
    }
    inline const Color& GetOutlineColor() const 
    {
        return m_colBorder;
    }
    inline const Color& GetSelectedOptionColor() const 
    {
        return m_colSelected;
    }
    inline const Color& GetDefaulOptionColor() const 
    {
        return m_colDefault;
    }
    inline const Color& GetDisabledOptionColor() const 
    {
        return m_colDisabled;
    }
    inline bool Empty()
    {
        return m_mapSubMenus.empty();
    }
    inline void MoveRight()
    {
        m_cursorPos.x++;
        this->Clamp();
    }
    inline void MoveLeft()
    {
        m_cursorPos.x--;
        this->Clamp();
    }
    inline void MoveUp()
    {
        m_cursorPos.y--;
        this->Clamp();
    }
    inline void MoveDown()
    {
        m_cursorPos.y++;
        this->Clamp();
    }
    inline void Clamp()
    {
        const usize size = m_vecMenuNames.size();
        m_cursorPos = Clamp(m_cursorPos, ivec2::Zero(), m_tableSize - 1);
        if(m_cursorPos.x * m_tableSize.h + m_cursorPos.y >= size)
        {
            m_cursorPos.x = (size - 1) / m_tableSize.w;
            m_cursorPos.y = (size - 1) % m_tableSize.w;
        }
    }
public:
    void Build()
    {
        vec2 buffer;
        m_backgroundSize = 0.0f;
        for(i32 i = 0; i < m_tableSize.x; i++)
        {
            for(i32 j = 0; j < m_tableSize.y; j++)
            {
                const i32 idx = i * m_tableSize.y + j;
                if(idx < m_vecMenuNames.size())
                {
                    const vec2 stringSize = GetStringSize(m_vecMenuNames[idx], m_scale);
                    buffer.x = std::max(buffer.x, stringSize.x);
                    buffer.y += stringSize.y + m_itemPadding.y * m_scale.y;
                }
            }
            m_backgroundSize.x += buffer.x + m_itemPadding.x * m_scale.x;
            m_backgroundSize.y = std::max(buffer.y, m_backgroundSize.y);
            buffer = 0.0f;
        }
        for(auto& [name, subMenu] : m_mapSubMenus)
            if(!subMenu.m_mapSubMenus.empty())
            {
                subMenu.m_pos = m_pos + m_subMenuOffset * m_scale;
                subMenu.m_pos += m_textOrigin * m_backgroundSize;
                subMenu.m_textOrigin = m_textOrigin;
                subMenu.m_scale = m_scale;
                subMenu.Build();
            }
    }
    void Draw(Window* window)
    {
        f32 buffer = 0.0f;
        const vec2 start = m_pos - m_backgroundSize * m_textOrigin;
        vec2 drawPos = start;
        const vec2 padding = m_itemPadding * m_scale;
        window->DrawRect(drawPos - padding, m_backgroundSize + padding, m_colBackground);
        window->DrawRectOutline(drawPos - padding, m_backgroundSize + padding, m_colBorder, 0.0f, m_lineWidth);
        for(i32 i = 0; i < m_tableSize.x; i++)
        {
            for(i32 j = 0; j < m_tableSize.y; j++)
            {
                const i32 idx = i * m_tableSize.y + j;
                if(idx < m_vecMenuNames.size())
                {
                    const vec2 stringSize = GetStringSize(m_vecMenuNames[idx], m_scale);
                    window->DrawText(
                        drawPos + m_textOrigin * stringSize, m_vecMenuNames[idx], m_scale,
                        m_mapSubMenus[m_vecMenuNames[idx]].m_menuEnabled ?
                        (idx == m_cursorPos.x * m_tableSize.y + m_cursorPos.y ? 
                            m_colSelected : m_colDefault) : m_colDisabled, m_textOrigin);
                    drawPos.y += stringSize.h + padding.h;
                    buffer = std::max(buffer, stringSize.w);
                }
            }
            drawPos.x += buffer + padding.w;
            drawPos.y = start.y;
            buffer = 0.0f;
        }
    }
    void Draw(GeometryBatch& geoBatch, TextBatch& textBatch, f32 depth = 0.0f)
    {
        f32 buffer = 0.0f;
        const vec2 start = m_pos - m_backgroundSize * m_textOrigin;
        vec2 drawPos = start;
        const vec2 padding = m_itemPadding * m_scale;
        const vec2 size = m_backgroundSize + padding;
        geoBatch.DrawRect(drawPos - padding + size * 0.5f, size, 0.0f, m_colBackground, depth);
        geoBatch.DrawRectOutline(drawPos - padding + size * 0.5f, size, m_colBorder, m_lineWidth, depth);
        for(i32 i = 0; i < m_tableSize.x; i++)
        {
            for(i32 j = 0; j < m_tableSize.y; j++)
            {
                const i32 idx = i * m_tableSize.y + j;
                if(idx < m_vecMenuNames.size())
                {
                    const vec2 stringSize = GetStringSize(m_vecMenuNames[idx], m_scale);
                    textBatch.DrawText(
                        drawPos + m_textOrigin * stringSize, m_vecMenuNames[idx], m_scale, 0.0f, 
                        m_mapSubMenus[m_vecMenuNames[idx]].m_menuEnabled ? 
                        (idx == m_cursorPos.x * m_tableSize.y + m_cursorPos.y ? 
                            m_colSelected : m_colDefault) : m_colDisabled,
                            m_textOrigin, depth);
                    drawPos.y += stringSize.h + padding.h;
                    buffer = std::max(buffer, stringSize.w);
                }
            }
            drawPos.x += buffer + padding.w;
            drawPos.y = start.y;
            buffer = 0.0f;
        }
        geoBatch.Flush();
        textBatch.Flush();
    }
    inline std::reference_wrapper<Menu<StateEnum>> GetSelectedNode()
    {
        return m_mapSubMenus[m_vecMenuNames[m_cursorPos.x * m_tableSize.y + m_cursorPos.y]];
    }
    inline Menu<StateEnum>& operator[](const std::string& str)
    {
        if(m_mapSubMenus.count(str) == 0)
        {
            m_vecMenuNames.push_back(str);
            m_mapSubMenus[str] = Menu<StateEnum>();
        }
        return m_mapSubMenus[str];
    }
};

template <typename StateEnum>
struct MenuManager
{
    Window* m_windowHandle = nullptr;
    std::list<std::reference_wrapper<Menu<StateEnum>>> m_listSubMenus;
    inline void Draw()
    {
        for(auto& menu : m_listSubMenus) menu.get().Draw(m_windowHandle);
    }
    inline void Draw(GeometryBatch& geoBatch, TextBatch& textBatch, f32 depth = 0.0f)
    {
        bool depthTest = glIsEnabled(GL_DEPTH_TEST);
        glDisable(GL_DEPTH_TEST);
        for(auto& menu : m_listSubMenus) menu.get().Draw(geoBatch, textBatch, depth);
        if(depthTest) glEnable(GL_DEPTH_TEST);
    }
    inline void SetWindowHandle(Window* window)
    {
        m_windowHandle = window;
    }
    inline Window* GetWindowHandle()
    {
        return m_windowHandle;
    }
    inline std::optional<StateEnum> Update()
    {
        std::optional<StateEnum> res = std::nullopt;
        if(m_windowHandle->GetKey(GLFW_KEY_W) == Key::Pressed) m_listSubMenus.back().get().MoveUp();
        if(m_windowHandle->GetKey(GLFW_KEY_A) == Key::Pressed) m_listSubMenus.back().get().MoveLeft();
        if(m_windowHandle->GetKey(GLFW_KEY_S) == Key::Pressed) m_listSubMenus.back().get().MoveDown();
        if(m_windowHandle->GetKey(GLFW_KEY_D) == Key::Pressed) m_listSubMenus.back().get().MoveRight();
        if(m_windowHandle->GetKey(GLFW_KEY_ENTER) == Key::Pressed) res = MoveForward();
        if(m_windowHandle->GetKey(GLFW_KEY_ESCAPE) == Key::Pressed) MoveBack();
        return res;
    }
    inline void Close()
    {
        m_listSubMenus.clear();
    }
    inline void Open(std::reference_wrapper<Menu<StateEnum>> menu)
    {
        Close();
        m_listSubMenus.push_back(menu);
    }
    inline std::optional<StateEnum> MoveForward()
    {
        if(!m_listSubMenus.empty())
        {
            auto& activeNode = m_listSubMenus.back().get().GetSelectedNode().get();
            if(!activeNode.Empty())
            {
                if(activeNode.IsEnabled())
                    m_listSubMenus.push_back(activeNode);
                else
                    return std::nullopt;
            }
            else return activeNode.GetId();
        }
        return std::nullopt;
    }
    inline void MoveBack()
    {
        if(m_listSubMenus.size() > 1) m_listSubMenus.pop_back();
    }
    inline bool Empty()
    {
        return m_listSubMenus.empty();
    }
};

#endif