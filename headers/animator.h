#ifndef ANIMATOR_H
#define ANIMATOR_H

template <class ImageSource> 
struct is_image : std::disjunction<
    std::is_same<ImageSource, Sprite>, 
    std::is_same<ImageSource, Decal>> {};

template <class ImageSource>
inline constexpr bool is_image_v = is_image<ImageSource>::value;

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

template <class ImageSource>
class Animator : public Animation
{
    static_assert(is_image_v<ImageSource>);
private:
    std::vector<ImageSource> m_vecFrames;
    using Animation::Update;
    using Animation::HasFinishedPlaying;
public:
    inline size_t size() const
    {
        return m_vecFrames.size();
    }
    inline void AddFrame(const std::string& path)
    {
        m_vecFrames.emplace_back(path);
    }
    inline void AddFrame(const ImageSource& image) 
    {
        m_vecFrames.push_back(image);
    }
    inline ImageSource& operator[](const size_t& index) 
    {
        if(index < m_vecFrames.size())
            return m_vecFrames[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline const ImageSource& operator[](const size_t& index) const
    {
        if(index < m_vecFrames.size())
            return m_vecFrames[index];
        else
            throw std::out_of_range("index out of range");
    }
    inline const ImageSource& GetFrame() const
    {
        return m_vecFrames[m_idx];
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

template <class ImageSource, typename = typename std::enable_if_t<is_image_v<ImageSource>>>
class PartialAnimator : public Animation {};

template <>
class PartialAnimator<Decal> : public Animation
{
private:
    Decal m_imageSource;
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
        m_imageSource = dec;
        m_invImageSize = 1.0f / dec.GetSize();
    }
    inline void SetSourceImage(const std::string& path)
    {
        m_imageSource = Decal(path);
        m_invImageSize = 1.0f / m_imageSource.GetSize();
    }
    inline const Decal& GetSourceImage() const
    {
        return m_imageSource;
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
    Sprite m_imageSource;
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
        m_imageSource = spr;
    }
    inline void SetSourceImage(const std::string& path)
    {
        m_imageSource = Sprite(path);
    }
    inline const Sprite& GetSourceImage() const
    {
        return m_imageSource;
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

#endif