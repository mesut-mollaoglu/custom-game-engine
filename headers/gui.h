#ifndef QUI_H
#define GUI_H

#include "includes.h"

namespace GUI
{
    struct Button
    {
        Sprite image;
        vec2f pos;
        vec2f scale = 1.0f;
        int button;
        Window* window = nullptr;
        inline Button() = default;
        inline Button(Window* window, const std::string& path, int button);
        inline bool Clicked();
        inline bool Hover();
        inline void Draw();
        virtual ~Button() {}
    };
    struct TextButton
    {
        std::string text;
        vec2f pos;
        vec2f scale = 1.0f;
        int button;
        Color textColor = {255, 255, 255, 255};
        Color background = {0, 0, 0, 255};
        Window* window = nullptr;
        inline TextButton() = default;
        inline TextButton(Window* window, const std::string& text, int button);
        inline bool Clicked();
        inline bool Hover();
        inline void Draw();
        virtual ~TextButton() {}
    };
    struct Slider
    {
        vec2f pos;
        vec2f size;
        float value = 0.0f;
        Color endSliderColor = {255, 255, 255, 255};
        Color bgLineColor = {255, 255, 255, 255};
        Color startSliderColor = {255, 255, 255, 255};
        Window* window;
        inline Slider() = default;
        inline bool Hover();
        inline void Update();
        inline void Draw();
        virtual ~Slider() {}
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
    assert(window != nullptr);
    return window->GetMouseButton(button) == Key::Pressed && Hover();
}

inline bool GUI::Button::Hover()
{
    assert(window != nullptr);
    const vec2f sprSize = scale * image.GetSize();
    return Rect<float>{pos - sprSize * 0.5f, sprSize}.Contains(window->GetMousePos());
}

inline void GUI::Button::Draw()
{
    assert(window != nullptr);
    window->DrawSprite(pos, image, scale);
}

inline GUI::TextButton::TextButton(Window* window, const std::string& text, int button) : window(window), button(button), text(text)
{
    return;
}

inline bool GUI::TextButton::Hover()
{
    assert(window != nullptr);
    const vec2f strSize = StringSize(text, scale);
    return Rect<float>{pos - strSize * 0.5f, strSize}.Contains(window->GetMousePos());
}

inline bool GUI::TextButton::Clicked()
{
    assert(window != nullptr);
    return window->GetMouseButton(button) == Key::Pressed && Hover();
}

inline void GUI::TextButton::Draw()
{
    assert(window != nullptr);
    const vec2f size = StringSize(text, size);
    window->DrawRect(pos - size * 0.5f, size, background);
    window->DrawText(pos.x, pos.y - size.h * 0.5f, text, size, textColor, 0.5f);
}

inline bool GUI::Slider::Hover()
{
    assert(window != nullptr);
    return (window->GetMousePos() - vec2f{size.w * value, 0.0f} - pos).mag() < (size.h * 0.5f);
}

inline void GUI::Slider::Update()
{
    assert(window != nullptr);
    if(Hover() && window->GetMouseButton(0) == Key::Held)
        value = std::clamp<float>((window->GetMousePos().x - pos.x) / size.w, 0.0f, 1.0f);
}

inline void GUI::Slider::Draw()
{
    assert(window != nullptr);
    window->DrawLine(pos.x, pos.y, pos.x + size.w, pos.y, bgLineColor);
    window->DrawCircle(pos.x + size.w * value, pos.y, size.h * 0.5f, startSliderColor.Lerp(endSliderColor, value));
}

#endif