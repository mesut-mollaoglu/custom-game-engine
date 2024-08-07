#ifndef MENU_H
#define MENU_H

#include "includes.h"

struct Menu
{
    vec2f textOrigin = 0.0f;
    std::unordered_map<std::string, Menu> subMenuMap;
    std::vector<std::string> menuNamesVec;
    Color backgroundColor = {0, 0, 0, 255};
    Color bgOutlineColor = {255, 255, 255, 255};
    Color currentOptionColor = {255, 0, 0, 255};
    Color defOptionColor = {255, 255, 255, 255};
    Color disabledOptionColor = {125, 125, 125, 255};
    vec2f menuElementPadding = {5.0f, 3.0f};
    vec2f subMenuOffset = {5.0f, 4.0f};
    vec2i cursorPosition;
    vec2f menuBackgroundSize;
    vec2i tableSize;
    vec2f position;
    int32_t id = 0;
    vec2f size = 1.0f;
    bool enabled = true;
    inline void BuildMenu();
    inline void Draw(Window& window);
    inline void Draw(GeometryBatch& geoBatch, TextBatch& textBatch, float depth = 0.0f);
    inline std::reference_wrapper<Menu> CurrentNode();
    inline Menu& operator[](const std::string& str);
};

struct MenuManager
{
    std::list<std::reference_wrapper<Menu>> subMenuList;
    inline void Open(std::reference_wrapper<Menu> menu);
    inline void Draw(GeometryBatch& geoBatch, TextBatch& textBatch, float depth = 0.0f);
    inline void Draw(Window& window);
    inline int32_t Update(Window& window);
    inline void MoveRight();
    inline void MoveLeft();
    inline void MoveDown();
    inline void MoveUp();
    inline void Clamp();
    inline void Close();
    inline int32_t MoveForward();
    inline void MoveBack();
    inline bool Empty();
};

#endif

#ifdef MENU_H
#undef MENU_H

inline Menu& Menu::operator[](const std::string& str)
{
    if(subMenuMap.count(str) == 0)
    {
        menuNamesVec.push_back(str);
        subMenuMap[str] = Menu();
    }
    return subMenuMap[str];
}

inline std::reference_wrapper<Menu> Menu::CurrentNode()
{
    return subMenuMap[menuNamesVec[cursorPosition.x * tableSize.h + cursorPosition.y]];
}

inline void Menu::Draw(Window& window)
{
    float buffer = 0.0f;
    vec2f drawPos = position - menuBackgroundSize * textOrigin;
    const vec2f padding = menuElementPadding * size;
    window.DrawRect(drawPos - padding, menuBackgroundSize + padding, backgroundColor);
    window.DrawRectOutline(drawPos - padding, menuBackgroundSize + padding, bgOutlineColor);
    for(int i = 0; i < tableSize.w; i++)
    {
        for(int j = 0; j < tableSize.h; j++)
        {
            const int index = i * tableSize.h + j;
            if(index < menuNamesVec.size())
            {
                const vec2f strSize = StringSize(menuNamesVec[index], size);
                const bool enabled = subMenuMap[menuNamesVec[index]].enabled;
                const int currIndex = cursorPosition.x * tableSize.h + cursorPosition.y;
                const Color color = enabled ? (index == currIndex ? currentOptionColor : defOptionColor) : disabledOptionColor;
                window.DrawText(drawPos + textOrigin * strSize, menuNamesVec[index], size, color, textOrigin);
                drawPos.y += strSize.h + padding.h;
                buffer = std::max(buffer, strSize.w);
            }
        }
        drawPos.x += buffer + padding.w;
        drawPos.y = position.y;
        buffer = 0.0f;
    }
}

inline void Menu::Draw(GeometryBatch& geoBatch, TextBatch& textBatch, float depth)
{
    float buffer = 0.0f;
    vec2f drawPos = position - menuBackgroundSize * textOrigin;
    const vec2f padding = menuElementPadding * size;
    geoBatch.DrawRect(drawPos - padding, menuBackgroundSize + padding, 0.0f, ColorF(backgroundColor), depth);
    geoBatch.DrawRectOutline(drawPos - padding, menuBackgroundSize + padding, ColorF(bgOutlineColor), depth);
    for(int i = 0; i < tableSize.w; i++)
    {
        for(int j = 0; j < tableSize.h; j++)
        {
            const int index = i * tableSize.h + j;
            if(index < menuNamesVec.size())
            {
                const vec2f strSize = StringSize(menuNamesVec[index], size);
                const bool enabled = subMenuMap[menuNamesVec[index]].enabled;
                const int currIndex = cursorPosition.x * tableSize.h + cursorPosition.y;
                const Color color = enabled ? (index == currIndex ? currentOptionColor : defOptionColor) : disabledOptionColor;
                textBatch.DrawText(drawPos + strSize * textOrigin, menuNamesVec[index], size, 0.0f, ColorF(color), depth);
                drawPos.y += strSize.h + padding.h;
                buffer = std::max(buffer, strSize.w);
            }
        }
        drawPos.x += buffer + padding.w;
        drawPos.y = position.y;
        buffer = 0.0f;
    }
}

inline void Menu::BuildMenu()
{
    vec2f buffer;
    menuBackgroundSize = 0.0f;
    for(int i = 0; i < tableSize.w; i++)
    {
        for(int j = 0; j < tableSize.h; j++)
        {
            const int index = i * tableSize.h + j;
            if(index < menuNamesVec.size())
            {
                const vec2f strSize = StringSize(menuNamesVec[index], size);
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

inline void MenuManager::Draw(Window& window)
{
    for(auto& menu : subMenuList) menu.get().Draw(window);
}

inline void MenuManager::Draw(GeometryBatch& geoBatch, TextBatch& textBatch, float depth)
{
    for(auto& menu : subMenuList) menu.get().Draw(geoBatch, textBatch, depth);
}

inline int32_t MenuManager::Update(Window& window)
{
    int32_t res = -1;
    if(window.GetKey(GLFW_KEY_W) == Key::Pressed) MoveUp();
    if(window.GetKey(GLFW_KEY_A) == Key::Pressed) MoveLeft();
    if(window.GetKey(GLFW_KEY_S) == Key::Pressed) MoveDown();
    if(window.GetKey(GLFW_KEY_D) == Key::Pressed) MoveRight();
    if(window.GetKey(GLFW_KEY_ENTER) == Key::Pressed) res = MoveForward();
    if(window.GetKey(GLFW_KEY_ESCAPE) == Key::Pressed) MoveBack();
    return res;
}

inline void MenuManager::Close()
{
    subMenuList.clear();
}

inline void MenuManager::Open(std::reference_wrapper<Menu> menu)
{
    Close();
    subMenuList.push_back(menu);
}

inline int32_t MenuManager::MoveForward()
{
    if(!subMenuList.empty())
    {
        auto& currNode = subMenuList.back().get().CurrentNode().get();
        if(!currNode.subMenuMap.empty())
        {
            if(currNode.enabled) 
                subMenuList.push_back(currNode);
            else
                return -1;
        }
        else return currNode.id;
    }
    return -1;
}

inline void MenuManager::MoveRight()
{
    subMenuList.back().get().cursorPosition.x++;
    Clamp();
}

inline void MenuManager::MoveLeft()
{
    subMenuList.back().get().cursorPosition.x--;
    Clamp();
} 

inline void MenuManager::MoveDown()
{
    subMenuList.back().get().cursorPosition.y++;
    Clamp();
}

inline void MenuManager::MoveUp()
{
    subMenuList.back().get().cursorPosition.y--;
    Clamp();
}

inline void MenuManager::MoveBack()
{
    if(subMenuList.size() > 1) subMenuList.pop_back();
}

inline void MenuManager::Clamp()
{
    auto& currMenu = subMenuList.back().get();
    const size_t size = currMenu.menuNamesVec.size();
    currMenu.cursorPosition.x = std::clamp(currMenu.cursorPosition.x, 0, currMenu.tableSize.w - 1);
    currMenu.cursorPosition.y = std::clamp(currMenu.cursorPosition.y, 0, currMenu.tableSize.h - 1);
    if(currMenu.cursorPosition.y * currMenu.tableSize.w + currMenu.cursorPosition.x >= size)
    {
        currMenu.cursorPosition.x = (size - 1) / currMenu.tableSize.w;
        currMenu.cursorPosition.y = (size - 1) % currMenu.tableSize.w;
    }
}

inline bool MenuManager::Empty()
{
    return subMenuList.empty();
}

#endif