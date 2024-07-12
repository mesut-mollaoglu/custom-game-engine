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
};

#endif

#ifdef GUI_H
#undef GUI_H

GUI::Button::Button(Window* window, const std::string& path, int button) : window(window), button(button)
{
    image = Sprite(path);
}

bool GUI::Button::Clicked()
{
    return window->GetMouseButton(button) == Key::Pressed && Hover();
}

bool GUI::Button::Hover()
{
    assert(window);
    const int32_t w = image.width * size.w;
    const int32_t h = image.height * size.h;
    const int32_t x = window->GetMousePos().x;
    const int32_t y = window->GetMousePos().y;
    return (x < position.x + w * 0.5f && x > position.x - w * 0.5f && y < position.y + h * 0.5f && y > position.y - h * 0.5f);
}

void GUI::Button::Draw()
{
    assert(window);
    window->pixelMode = PixelMode::Mask;
    window->DrawSprite(position.x, position.y, image, size);
    window->pixelMode = PixelMode::Normal;
}

#endif