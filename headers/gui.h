#ifndef QUI_H
#define GUI_H

#include "includes.h"

namespace GUI
{
    struct Button
    {
        Sprite image;
        vec2f position;
        vec2f size = 1.0f;
        int button;
        Window* window = nullptr;
        inline Button() = default;
        inline Button(Window* window, const std::string& path, int button);
        inline bool Clicked();
        inline bool Hover();
        inline void Draw();
        ~Button() {}
    };
    struct TextButton
    {
        std::string text;
        vec2f position;
        vec2f size = 1.0f;
        int button;
        Color textColor = {255, 255, 255, 255};
        Color background = {0, 0, 0, 255};
        Window* window = nullptr;
        inline TextButton() = default;
        inline TextButton(Window* window, const std::string& text, int button);
        inline bool Clicked();
        inline bool Hover();
        inline void Draw();
        ~TextButton() {}
    };
    struct Slider
    {
        vec2f position;
        float p = 0.0f;
        float lineLength = 0.0f;
        float sliderRadius = 1.0f;
        Color sliderColor = Color(255, 255, 255, 255);
        Color lineColor = Color(255, 255, 255, 255);
        Window* window;
        inline Slider() = default;
        inline bool Hover();
        inline void Update();
        inline void Draw();
    };
};

#endif

#ifdef GUI_H
#undef GUI_H

inline GUI::Button::Button(Window* window, const std::string& path, int button) : window(window), button(button)
{
    image = Sprite(path);
}

inline bool GUI::Button::Clicked()
{
    return window->GetMouseButton(button) == Key::Pressed && Hover();
}

inline bool GUI::Button::Hover()
{
    assert(window);
    const vec2f hs = size * image.GetSize() * 0.5f;
    const Rect<float> rect = {position - hs, position + hs};
    return rect.Contains(window->GetMousePos());
}

inline void GUI::Button::Draw()
{
    assert(window);
    window->pixelMode = PixelMode::Mask;
    window->DrawSprite(position.x, position.y, image, size);
    window->pixelMode = PixelMode::Normal;
}

inline GUI::TextButton::TextButton(Window* window, const std::string& text, int button) : window(window), button(button), text(text)
{
    return;
}

inline bool GUI::TextButton::Hover()
{
    assert(window);
    const vec2f hs = StringSize(text, size) * 0.5f;
    const Rect<float> rect = {position - hs, position + hs};
    return rect.Contains(window->GetMousePos());
}

inline bool GUI::TextButton::Clicked()
{
    return window->GetMouseButton(button) == Key::Pressed && Hover();
}

inline void GUI::TextButton::Draw()
{
    assert(window);
    const vec2f size = StringSize(text, size);
    window->DrawRect(position.x - size.w * 0.5f, position.y - size.h * 0.5f, size.w, size.h, background);
    window->DrawText(position.x, position.y - size.h * 0.5f, text, size, textColor, 0.5f);
}

inline bool GUI::Slider::Hover()
{
    //TODO
    return false;
}

inline void GUI::Slider::Update()
{
    //TODO
    return;
}

inline void GUI::Slider::Draw()
{
    //TODO
    return;
}

#endif