#ifndef QUI_H
#define GUI_H

namespace GUI
{
    struct Button
    {
        Sprite image;
        vec2 pos;
        vec2 scale = 1.0f;
        int button;
        Window* window = nullptr;
        inline Button() = default;
        Button(Window* window, const std::string& path, int button);
        bool Clicked();
        bool Hover();
        void Draw();
        virtual ~Button() {}
    };
    struct TextButton
    {
        std::string text;
        vec2 pos;
        vec2 scale = 1.0f;
        int button;
        Color textColor = {255, 255, 255, 255};
        Color background = {0, 0, 0, 255};
        Window* window = nullptr;
        inline TextButton() = default;
        TextButton(Window* window, const std::string& text, int button);
        bool Clicked();
        bool Hover();
        void Draw();
        virtual ~TextButton() {}
    };
    struct Slider
    {
        vec2 pos;
        vec2 size;
        float value = 0.0f;
        Color sliderColor = {255, 255, 255, 255};
        Color lineColor = {255, 255, 255, 255};
        Window* window = nullptr;
        inline Slider() = default;
        bool Hover();
        void Update();
        void Draw();
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
    const vec2 sprSize = scale * image.GetSize();
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
    const vec2 strSize = StringSize(text, scale);
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
    const vec2 size = StringSize(text, size);
    window->DrawRect(pos - size * 0.5f, size, background);
    window->DrawText(pos.x, pos.y - size.h * 0.5f, text, size, textColor, 0.5f);
}

inline bool GUI::Slider::Hover()
{
    assert(window != nullptr);
    return (window->GetMousePos() - vec2{size.w * value, 0.0f} - pos).mag() < (size.h * 0.5f);
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
    window->DrawLine(pos.x, pos.y, pos.x + size.w, pos.y, lineColor);
    window->DrawCircle(pos.x + size.w * value, pos.y, size.h * 0.5f, sliderColor);
}

#endif