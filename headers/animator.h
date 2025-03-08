#ifndef ANIMATOR_H
#define ANIMATOR_H

template <class _SourceImageT> 
struct is_image : std::disjunction<
    std::is_same<_SourceImageT, Sprite>, 
    std::is_same<_SourceImageT, Decal>> {};

template <class _SourceImageT>
inline constexpr bool is_image_v = is_image<_SourceImageT>::value;

enum class Style : uint8_t
{
    PlayOnce,
    Repeat,
    PingPong
};

class Animation
{
protected:
    size_t m_idx = 0ull;
    float m_elapsedTime = 0.0f;
    float m_duration = 0.0f;
    bool m_playReverse = false;
    Style m_style = Style::Repeat;
public:
    inline Animation(float duration = 0.1f, const Style& style = Style::Repeat)
    {
        m_duration = duration;
        m_style = style;
    }
    inline void Update(const size_t& size, float delta)
    {
        switch(m_style)
        {
            case Style::Repeat:
            {
                m_elapsedTime += delta;
                m_idx = (size_t)(m_elapsedTime / m_duration) % size;
            }
            break;
            case Style::PlayOnce: 
            {
                m_elapsedTime += this->HasFinishedPlaying(size) ? 0.0f : delta;
                m_idx = std::min<size_t>(m_elapsedTime / m_duration, size - 1);
            }
            break;
            case Style::PingPong:
            {
                m_elapsedTime += delta;
                m_idx = std::min<size_t>(m_elapsedTime / m_duration, size - 1);
                if(this->HasFinishedPlaying(size))
                {
                    m_elapsedTime = 0.0f;
                    m_idx = 0ull;
                    this->Reverse();
                }
            }
            break;
        }
        m_idx = m_playReverse ? size - 1 - m_idx : m_idx;
    }
    inline void Reset()
    {
        m_playReverse = false;
        m_elapsedTime = 0.0f;
        m_idx = 0ull;
    }
    inline bool HasFinishedPlaying(const size_t& size) const
    {
        return (m_playReverse && m_idx == 0) || (!m_playReverse && m_idx == size - 1);
    }
    inline void Reverse()
    {
        m_playReverse = !m_playReverse;
    }
    inline void SetReverse(bool reverse)
    {
        m_playReverse = reverse;
    }
    inline const Style& GetStyle() const
    {
        return m_style;
    }
    inline void SetStyle(const Style& style)
    {
        m_style = style;
    }
    inline const size_t& GetIndex() const
    {
        return m_idx;
    }
    inline void SetDuration(float duration)
    {
        m_duration = duration;
    }
    inline float GetDuration() const
    {
        return m_duration;
    }
};

template <class _SourceImageT, typename = typename std::enable_if_t<is_image_v<_SourceImageT>>>
class PartialAnimator : public Animation {};

template <>
class PartialAnimator<Decal> : public Animation
{
private:
    Decal m_sourceImage;
    std::vector<Rect<float>> m_vecFrames;
    vec2 m_invImageSize;
    using Animation::Update;
    using Animation::HasFinishedPlaying;
public:
    inline size_t size() const
    {
        return m_vecFrames.size();
    }
    inline void SetSourceImage(const Decal& dec)
    {
        m_sourceImage = dec;
        m_invImageSize = 1.0f / dec.GetSize();
    }
    inline void SetSourceImage(const std::string& path)
    {
        m_sourceImage = Decal(path);
        m_invImageSize = 1.0f / m_sourceImage.GetSize();
    }
    inline const Decal& GetSourceImage() const
    {
        return m_sourceImage;
    }
    inline void AddFrame(const Rect<int32_t>& src)
    {
        m_vecFrames.push_back(src * m_invImageSize);
    }
    inline void AddFrame(const ivec2& pos, const ivec2& size)
    {
        m_vecFrames.emplace_back(pos * m_invImageSize, size * m_invImageSize);
    }
    inline Rect<float>& operator[](const size_t& idx)
    {
        if(idx < m_vecFrames.size())
            return m_vecFrames[idx];
        else
            throw std::out_of_range("index out of range");
    }
    inline const Rect<float>& operator[](const size_t& idx) const
    {
        if(idx < m_vecFrames.size())
            return m_vecFrames[idx];
        else
            throw std::out_of_range("index out of range");
    }
    inline const Rect<float>& GetFrame() const
    {
        return operator[](m_idx);
    }
    inline void Update(float delta)
    {
        Update(m_vecFrames.size(), delta);
    }
    inline bool HasFinishedPlaying() const
    {
        return HasFinishedPlaying(m_vecFrames.size());
    }
};

template <>
class PartialAnimator<Sprite> : public Animation
{
private:
    Sprite m_sourceImage;
    std::vector<Rect<int32_t>> m_vecFrames;
    using Animation::Update;
    using Animation::HasFinishedPlaying;
public:
    inline size_t size() const
    {
        return m_vecFrames.size();
    }
    inline void SetSourceImage(const Sprite& spr)
    {
        m_sourceImage = spr;
    }
    inline void SetSourceImage(const std::string& path)
    {
        m_sourceImage = Sprite(path);
    }
    inline const Sprite& GetSourceImage() const
    {
        return m_sourceImage;
    }
    inline void AddFrame(const Rect<int32_t>& src)
    {
        m_vecFrames.push_back(src);
    }
    inline void AddFrame(const ivec2& pos, const ivec2& size)
    {
        m_vecFrames.emplace_back(pos, size);
    }
    inline Rect<int32_t>& operator[](const size_t& idx)
    {
        if(idx < m_vecFrames.size())
            return m_vecFrames[idx];
        else
            throw std::out_of_range("index out of range");
    }
    inline const Rect<int32_t>& operator[](const size_t& idx) const
    {
        if(idx < m_vecFrames.size())
            return m_vecFrames[idx];
        else
            throw std::out_of_range("index out of range");
    }
    inline const Rect<int32_t>& GetFrame() const
    {
        return operator[](m_idx);
    }
    inline void Update(float delta)
    {
        Update(m_vecFrames.size(), delta);
    }
    inline bool HasFinishedPlaying() const
    {
        return HasFinishedPlaying(m_vecFrames.size());
    }
};

template <class _SourceImageT, typename = typename std::enable_if_t<is_image_v<_SourceImageT>>>
struct Frame {};

template <>
struct Frame<Sprite>
{
private:
    Sprite m_sourceImage;
    Rect<int32_t> m_sourceRect;
public:
    inline Frame(const Sprite& spr, const Rect<int32_t>& src = {0, 0})
    : m_sourceImage(spr), m_sourceRect(src.size == 0 && src.pos == 0 ? Rect<int32_t>{0, spr.GetSize()} : src) {}
    inline Frame(const std::string& path, const Rect<int32_t>& src = {0, 0})
    : m_sourceImage(path), m_sourceRect(src.size == 0 && src.pos == 0 ? Rect<int32_t>{0, m_sourceImage.GetSize()} : src) {}
public:
    inline const Sprite& GetImage() const
    {
        return m_sourceImage;
    }
    inline const Rect<int32_t>& GetSourceRect() const
    {
        return m_sourceRect;
    }
};

template <>
struct Frame<Decal>
{
private:
    Decal m_sourceImage;
    Rect<float> m_sourceRect;
public:
    inline Frame(const Decal& dec, const Rect<int32_t>& src = {0, 0}) : m_sourceImage(dec), 
    m_sourceRect(src.size == 0 && src.pos == 0 ? Rect<float>{0.0f, 1.0f} : src * inv((vec2)dec.GetSize())) {}
    inline Frame(const std::string& path, const Rect<int32_t>& src = {0, 0}) : m_sourceImage(path), 
    m_sourceRect(src.size == 0 && src.pos == 0 ? Rect<float>{0.0f, 1.0f} : src * inv((vec2)m_sourceImage.GetSize())) {}
public:
    inline const Decal& GetImage() const
    {
        return m_sourceImage;
    }
    inline const Rect<float>& GetSourceRect() const
    {
        return m_sourceRect;
    }
};

template <class _SourceImageT>
class Animator : public Animation
{
private:
    std::vector<Frame<_SourceImageT>> m_vecFrames;
    using Animation::Update;
    using Animation::HasFinishedPlaying;
public:
    inline size_t size() const
    {
        return m_vecFrames.size();
    }
    inline void AddFrame(const std::string& path, const Rect<int32_t>& src = {0, 0})
    {
        m_vecFrames.emplace_back(path, src);
    }
    inline void AddFrame(const _SourceImageT& image, const Rect<int32_t>& src = {0, 0}) 
    {
        m_vecFrames.emplace_back(image, src);
    }
    inline Frame<_SourceImageT>& operator[](const size_t& index) 
    {
        if(index < m_vecFrames.size())
            return m_vecFrames[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline const Frame<_SourceImageT>& operator[](const size_t& index) const
    {
        if(index < m_vecFrames.size())
            return m_vecFrames[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline const Frame<_SourceImageT>& GetFrame() const
    {
        return m_vecFrames[m_idx];
    }
    inline const _SourceImageT& GetImage() const
    {
        return m_vecFrames[m_idx].GetImage();
    }
    inline const Rect<int32_t>& GetSourceRect() const
    {
        return m_vecFrames[m_idx].GetSourceRect();
    }
    inline void Update(float delta)
    {
        Update(m_vecFrames.size(), delta);
    }
    inline bool HasFinishedPlaying() const
    {
        return HasFinishedPlaying(m_vecFrames.size());
    }
};

#endif