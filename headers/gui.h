#ifndef QUI_H
#define GUI_H

namespace GUI
{
    struct Button
    {
        Sprite m_buttonImg;
        vec2 m_buttonPos;
        vec2 m_buttonScale = 1.0f;
        i32 m_code;
        Window* m_windowHandle = nullptr;
        inline Button() = default;
        Button(Window* window, const std::string& path, i32 button);
        bool Clicked();
        bool Hover();
        void Draw();
        virtual ~Button() {}
    };
    struct TextButton
    {
        std::string m_buttonText;
        vec2 m_buttonPos;
        vec2 m_buttonScale = 1.0f;
        i32 m_code;
        Color m_textColor = Colors::White;
        Color m_background = Colors::Black;
        Window* m_windowHandle = nullptr;
        inline TextButton() = default;
        TextButton(Window* window, const std::string& text, i32 button);
        bool Clicked();
        bool Hover();
        void Draw();
        virtual ~TextButton() {}
    };
    struct Slider
    {
        vec2 m_buttonPos;
        vec2 m_buttonSize;
        f32 m_sliderValue = 0.0f;
        Color m_sliderColor = Colors::White;
        Color m_lineColor = Colors::White;
        Window* m_windowHandle = nullptr;
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

inline GUI::Button::Button(Window* window, const std::string& path, i32 code) 
: m_windowHandle(m_windowHandle), m_code(code), m_buttonImg(path) {}

inline bool GUI::Button::Clicked()
{
    assert(m_windowHandle);
    return m_windowHandle->GetMouseButton(m_code) == Key::Pressed && Hover();
}

inline bool GUI::Button::Hover()
{
    assert(m_windowHandle);
    const vec2 sprSize = m_buttonScale * m_buttonImg.GetSize();
    return Rect<f32>{m_buttonPos - sprSize * 0.5f, sprSize}.Contains(m_windowHandle->GetMousePos());
}

inline void GUI::Button::Draw()
{
    assert(m_windowHandle);
    m_windowHandle->DrawSprite(m_buttonPos, m_buttonImg, m_buttonScale);
}

inline GUI::TextButton::TextButton(Window* window, const std::string& text, i32 code) 
: m_windowHandle(window), m_code(code), m_buttonText(text) {}

inline bool GUI::TextButton::Hover()
{
    assert(m_windowHandle);
    const vec2 strSize = GetStringSize(m_buttonText, m_buttonScale);
    return Rect<f32>{m_buttonPos - strSize * 0.5f, strSize}.Contains(m_windowHandle->GetMousePos());
}

inline bool GUI::TextButton::Clicked()
{
    assert(m_windowHandle);
    return m_windowHandle->GetMouseButton(m_code) == Key::Pressed && Hover();
}

inline void GUI::TextButton::Draw()
{
    assert(m_windowHandle);
    const vec2 size = GetStringSize(m_buttonText, m_buttonScale);
    m_windowHandle->DrawRect(m_buttonPos - size * 0.5f, size, m_background);
    m_windowHandle->DrawText(m_buttonPos.x, m_buttonPos.y - size.h * 0.5f, m_buttonText, size, m_textColor, 0.5f);
}

inline bool GUI::Slider::Hover()
{
    assert(m_windowHandle);
    return (m_windowHandle->GetMousePos() - vec2{m_buttonSize.w * m_sliderValue, 0.0f} - m_buttonPos).mag() < (m_buttonSize.h * 0.5f);
}

inline void GUI::Slider::Update()
{
    assert(m_windowHandle);
    if(Hover() && m_windowHandle->GetMouseButton(0) == Key::Held)
        m_sliderValue = std::clamp<f32>((m_windowHandle->GetMousePos().x - m_buttonPos.x) / m_buttonSize.w, 0.0f, 1.0f);
}

inline void GUI::Slider::Draw()
{
    assert(m_windowHandle);
    m_windowHandle->DrawLine(m_buttonPos.x, m_buttonPos.y, m_buttonPos.x + m_buttonSize.w, m_buttonPos.y, m_lineColor);
    m_windowHandle->DrawCircle(m_buttonPos.x + m_buttonSize.w * m_sliderValue, m_buttonPos.y, m_buttonSize.h * 0.5f, m_sliderColor);
}

#endif