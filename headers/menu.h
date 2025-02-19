#ifndef MENU_H
#define MENU_H

template <typename StateEnum>
struct Menu
{
    vec2 textOrigin = 0.0f;
    std::unordered_map<std::string, Menu<StateEnum>> subMenuMap;
    std::vector<std::string> menuNamesVec;
    Color backgroundColor = {0, 0, 0, 255};
    Color bgOutlineColor = {255, 255, 255, 255};
    Color currentOptionColor = {255, 0, 0, 255};
    Color defOptionColor = {255, 255, 255, 255};
    Color disabledOptionColor = {125, 125, 125, 255};
    vec2 menuElementPadding = {5.0f, 3.0f};
    vec2 subMenuOffset = {5.0f, 4.0f};
    vec2 menuBackgroundSize;
    ivec2 cursorPos;
    ivec2 tableSize;
    vec2 position;
    vec2 size = 1.0f;
    bool enabled = true;
    StateEnum id;
    void BuildMenu()
    {
        vec2 buffer;
        menuBackgroundSize = 0.0f;
        for(int i = 0; i < tableSize.w; i++)
        {
            for(int j = 0; j < tableSize.h; j++)
            {
                const int index = i * tableSize.h + j;
                if(index < menuNamesVec.size())
                {
                    const vec2 strSize = StringSize(menuNamesVec[index], size);
                    buffer.x = std::max(strSize.w, buffer.x);
                    buffer.y += strSize.h + menuElementPadding.y * size.h;
                }
            }
            menuBackgroundSize.x += buffer.x + menuElementPadding.x * size.w;
            menuBackgroundSize.y = std::max(buffer.y, menuBackgroundSize.y);
            buffer = 0.0f;
        }
        for(auto& subMenu : subMenuMap)
            if(!subMenu.second.subMenuMap.empty())
            {
                subMenu.second.position = position + subMenuOffset * size;
                subMenu.second.position += textOrigin * menuBackgroundSize;
                subMenu.second.textOrigin = textOrigin;
                subMenu.second.size = size;
                subMenu.second.BuildMenu();
            }
    }
    void Draw(Window* window)
    {
        float buffer = 0.0f;
        vec2 drawPos = position - menuBackgroundSize * textOrigin;
        const vec2 padding = menuElementPadding * size;
        window->DrawRect(drawPos - padding, menuBackgroundSize + padding, backgroundColor);
        window->DrawRectOutline(drawPos - padding, menuBackgroundSize + padding, bgOutlineColor);
        for(int i = 0; i < tableSize.w; i++)
        {
            for(int j = 0; j < tableSize.h; j++)
            {
                const int index = i * tableSize.h + j;
                if(index < menuNamesVec.size())
                {
                    const vec2 strSize = StringSize(menuNamesVec[index], size);
                    const bool enabled = subMenuMap[menuNamesVec[index]].enabled;
                    const int currIndex = cursorPos.x * tableSize.h + cursorPos.y;
                    const Color color = enabled ? (index == currIndex ? currentOptionColor : defOptionColor) : disabledOptionColor;
                    window->DrawText(drawPos + textOrigin * strSize, menuNamesVec[index], size, color, textOrigin);
                    drawPos.y += strSize.h + padding.h;
                    buffer = std::max(buffer, strSize.w);
                }
            }
            drawPos.x += buffer + padding.w;
            drawPos.y = position.y;
            buffer = 0.0f;
        }
    }
    void Draw(GeometryBatch& geoBatch, TextBatch& textBatch, float depth = 0.0f)
    {
        float buffer = 0.0f;
        vec2 drawPos = position - menuBackgroundSize * textOrigin;
        const vec2 padding = menuElementPadding * size;
        geoBatch.DrawRect(drawPos - padding, menuBackgroundSize + padding, 0.0f, backgroundColor, depth);
        geoBatch.DrawRectOutline(drawPos - padding, menuBackgroundSize + padding, bgOutlineColor, depth);
        for(int i = 0; i < tableSize.w; i++)
        {
            for(int j = 0; j < tableSize.h; j++)
            {
                const int index = i * tableSize.h + j;
                if(index < menuNamesVec.size())
                {
                    const vec2 strSize = StringSize(menuNamesVec[index], size);
                    const bool enabled = subMenuMap[menuNamesVec[index]].enabled;
                    const int currIndex = cursorPos.x * tableSize.h + cursorPos.y;
                    const Color color = enabled ? (index == currIndex ? currentOptionColor : defOptionColor) : disabledOptionColor;
                    textBatch.DrawText(drawPos + strSize * textOrigin, menuNamesVec[index], size, 0.0f, color, depth);
                    drawPos.y += strSize.h + padding.h;
                    buffer = std::max(buffer, strSize.w);
                }
            }
            drawPos.x += buffer + padding.w;
            drawPos.y = position.y;
            buffer = 0.0f;
        }
    }
    inline std::reference_wrapper<Menu<StateEnum>> CurrentNode()
    {
        return subMenuMap[menuNamesVec[cursorPos.x * tableSize.h + cursorPos.y]];
    }
    inline Menu<StateEnum>& operator[](const std::string& str)
    {
        if(subMenuMap.count(str) == 0)
        {
            menuNamesVec.push_back(str);
            subMenuMap[str] = Menu<StateEnum>();
        }
        return subMenuMap[str];
    }
};

template <typename StateEnum>
struct MenuManager
{
    Window* window;
    std::list<std::reference_wrapper<Menu<StateEnum>>> subMenuList;
    inline void Draw()
    {
        for(auto& menu : subMenuList) menu.get().Draw(window);
    }
    inline void Draw(GeometryBatch& geoBatch, TextBatch& textBatch, float depth)
    {
        for(auto& menu : subMenuList) menu.get().Draw(geoBatch, textBatch, depth);
    }
    inline std::optional<StateEnum> Update()
    {
        std::optional<StateEnum> res = std::nullopt;
        if(window->GetKey(GLFW_KEY_W) == Key::Pressed) MoveUp();
        if(window->GetKey(GLFW_KEY_A) == Key::Pressed) MoveLeft();
        if(window->GetKey(GLFW_KEY_S) == Key::Pressed) MoveDown();
        if(window->GetKey(GLFW_KEY_D) == Key::Pressed) MoveRight();
        if(window->GetKey(GLFW_KEY_ENTER) == Key::Pressed) res = MoveForward();
        if(window->GetKey(GLFW_KEY_ESCAPE) == Key::Pressed) MoveBack();
        return res;
    }
    inline void Close()
    {
        subMenuList.clear();
    }
    inline void Open(std::reference_wrapper<Menu<StateEnum>> menu)
    {
        Close();
        subMenuList.push_back(menu);
    }
    inline std::optional<StateEnum> MoveForward()
    {
        if(!subMenuList.empty())
        {
            auto& currNode = subMenuList.back().get().CurrentNode().get();
            if(!currNode.subMenuMap.empty())
            {
                if(currNode.enabled) 
                    subMenuList.push_back(currNode);
                else
                    return std::nullopt;
            }
            else return currNode.id;
        }
        return std::nullopt;
    }
    inline void MoveRight()
    {
        subMenuList.back().get().cursorPos.x++;
        Clamp();
    }
    inline void MoveLeft()
    {
        subMenuList.back().get().cursorPos.x--;
        Clamp();
    }
    inline void MoveDown()
    {
        subMenuList.back().get().cursorPos.y++;
        Clamp();
    }
    inline void MoveUp()
    {
        subMenuList.back().get().cursorPos.y--;
        Clamp();
    }
    inline void MoveBack()
    {
        if(subMenuList.size() > 1) subMenuList.pop_back();
    }
    inline void Clamp()
    {
        auto& currMenu = subMenuList.back().get();
        const size_t size = currMenu.menuNamesVec.size();
        currMenu.cursorPos.x = std::clamp(currMenu.cursorPos.x, 0, currMenu.tableSize.w - 1);
        currMenu.cursorPos.y = std::clamp(currMenu.cursorPos.y, 0, currMenu.tableSize.h - 1);
        if(currMenu.cursorPos.y * currMenu.tableSize.w + currMenu.cursorPos.x >= size)
        {
            currMenu.cursorPos.x = (size - 1) / currMenu.tableSize.w;
            currMenu.cursorPos.y = (size - 1) % currMenu.tableSize.w;
        }
    }
    inline bool Empty()
    {
        return subMenuList.empty();
    }
};

#endif

#ifdef MENU_H
#undef MENU_H


#endif