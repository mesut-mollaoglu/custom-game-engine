#ifndef GUI_HPP
#define GUI_HPP

//TODO

namespace GUI
{
    class Element
    {
    protected:
        Color m_colBackground = Colors::White;
        Color m_colBorder = Colors::Black;
        Color m_colHover = Colors::White;
        Color m_colClicked = Colors::White;
        Color m_colReleased = Colors::White;
        Color m_colNormal = Colors::White;
        TextStyle m_textStyle = TextStyle::Default;
        Window* m_windowHandle = nullptr;
        vec2 m_scale = vec2::One();
        Flip m_flip = Flip::None;
        ivec2 m_pos = ivec2::Zero();
        bool m_enabled = true;
    public:
        inline void SetScaleFactor(const vec2& s)
        {
            m_scale = s;
        }
        inline void SetPos(const ivec2& p)
        {
            m_pos = p;
        }
        inline bool IsEnabled() const
        {
            return m_enabled;
        }
        inline void Enable(bool b)
        {
            m_enabled = b;
        }
        inline void SetBorderColor(const Color& c)
        {
            m_colBorder = c;
        }
        inline void SetBackgroundColor(const Color& c)
        {
            m_colBackground = c;
        }
        inline void SetHoverColor(const Color& c)
        {
            m_colHover = c;
        }
        inline void SetClickColor(const Color& c)
        {
            m_colClicked = c;
        }
        inline void SetReleaseColor(const Color& c)
        {
            m_colReleased = c;
        }
        inline void SetNormalColor(const Color& c)
        {
            m_colNormal = c;
        }
    public:
        inline const vec2& GetScaleFactor() const
        {
            return m_scale;
        }
        inline const ivec2& GetPos() const
        {
            return m_pos;
        }
        const Color& GetBorderColor() const
        {
            return m_colBorder;
        }
        const Color& GetBackgroundColor() const
        {
            return m_colBackground;
        }
        const Color& GetHoverColor() const
        {
            return m_colHover;
        }
        const Color& GetClickColor() const
        {
            return m_colClicked;
        }
        const Color& GetReleaseColor() const
        {
            return m_colReleased;
        }
        const Color& GetNormalColor() const
        {
            return m_colNormal;
        }
        Window* GetWindowHandle()
        {
            return m_windowHandle;
        }
    public:
        virtual void Draw() {return;}
        virtual void Update() {return;}
    };
    class Label : protected Element
    {
    private:
        bool m_drawBorder;
        bool m_drawBackground;
        std::string m_srcString;
        ivec2 m_borderOffset;
    public:
        inline Label(
            Window* windowHandle = nullptr,
            const ivec2& pos = ivec2::Zero(),
            const vec2& scale = vec2::One(),
            const Flip& flip = Flip::None,
            const std::string& srcString = "",
            bool drawBorder = false,
            bool drawBackground = false,
            const ivec2& borderOffset = {3, 3})
        : m_drawBorder(drawBorder),
        m_drawBackground(drawBackground),
        m_srcString(srcString),
        m_borderOffset(borderOffset)
        {
            m_windowHandle = windowHandle;
            m_pos = pos;
            m_scale = scale;
            m_flip = flip;
        }
    public:
        inline void Draw() override
        {
            const vec2 size = GetStringSize(m_srcString, m_scale);
            if(m_drawBorder) m_windowHandle->DrawRectOutline(m_pos - m_borderOffset, size + m_borderOffset, m_colBorder);
            if(m_drawBackground) m_windowHandle->DrawRect(m_pos - m_borderOffset, size + m_borderOffset, m_colBackground);
        }
    public:
        inline void Update() override
        {
            return;
        }
    };
    class Button : protected Element
    {
    private:
        std::string m_srcString;
        bool m_drawBackground;
        ivec2 m_borderOffset;
    public:
        inline Button(
            Window* windowHandle,
            const std::string& srcString = "",
            bool drawBackground = false,
            const ivec2& borderOffset = {3, 3})
        : m_srcString(srcString),
        m_drawBackground(drawBackground),
        m_borderOffset(borderOffset)
        {
            m_windowHandle = windowHandle;
        }
        inline void Draw() override
        {
            return;
        }
        inline void Update() override
        {
            return;
        }
    };
    class CheckBox : protected Element
    {
    private:
        bool m_boxChecked;
    public:
        inline CheckBox(
            Window* windowHandle,
            bool boxChecked = false)
        : m_boxChecked(boxChecked)
        {
            m_windowHandle = windowHandle;
        }
        inline void Draw() override
        {
            return;
        }
        inline void Update() override
        {
            return;
        }
    };
    class TextBox : protected Element
    {
    private:
        Color m_colString;
        bool m_dynamicSize;
        ivec2 m_boxSize;
        std::string m_srcString;
        i32 m_cursorIndex = 0;
    public:
        inline TextBox(
            Window* windowHandle,
            const ivec2& boxSize = ivec2::Zero(),
            bool dynamicSize = false,
            const Color& colString = Colors::White)
        : m_colString(colString),
        m_dynamicSize(dynamicSize),
        m_boxSize(boxSize)
        {
            m_windowHandle = windowHandle;
        }
        inline void Draw() override
        {
            return;
        }
        inline void Update() override
        {
            return;
        }
    };
};

#endif