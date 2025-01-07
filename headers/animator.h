#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "includes.h"

enum class AnimUpdate
{
    Once,
    Loop,
    PingPong
};

struct AnimData
{
    size_t index = 0;
    bool played = false;
    bool reverse = false;
    float totalTime = 0.0f;
    AnimUpdate update = AnimUpdate::Loop;
    float duration;
    inline void Update(const size_t& size, float deltaTime)
    {
        switch(update)
        {
            case AnimUpdate::Loop: 
            {
                totalTime += deltaTime;
                index = (size_t)(totalTime / duration) % size;
            }
            break;
            case AnimUpdate::Once: 
            {
                totalTime += played ? 0.0f : deltaTime;
                index = std::min<size_t>(totalTime / duration, size - 1);
            }
            break;
            case AnimUpdate::PingPong:
            {
                totalTime += deltaTime;
                index = std::min<size_t>(totalTime / duration, size - 1);
                if(played) Reverse();
            }
            break;
        }
        played = totalTime >= duration * (size - 1);
        index = reverse ? size - 1 - index : index;
    }
    inline void Reverse()
    {
        reverse = !reverse;
        played = false;
        totalTime = 0.0f;
    }
    inline void Reset()
    {
        played = false;
        totalTime = 0.0f;
        index = 0;
    }
};

template <class T> 
struct is_renderable : std::integral_constant
    <bool, std::is_same<T, Sprite>::value ||
    std::is_same<T, Decal>::value>
    {};

template <class T, typename = typename std::enable_if<is_renderable<T>::value>::type> 
struct RenderableSheet
{
    T renderable;
    vec2i cellSize;
    inline RenderableSheet() = default;
    inline RenderableSheet(const std::string& path, const vec2i& cellSize) : cellSize(cellSize)
    {
        renderable = T(path);
    }
    inline Rect<int32_t> GetCellSrc(const vec2i& cell)
    {
        return {cellSize * cell, cellSize};
    }
    inline Rect<float> GetCellSrcNorm(const vec2i& cell)
    {
        return static_cast<Rect<float>>(GetCellSrc(cell)) * inv((vec2)renderable.GetSize());
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, const vec2i& cell, 
        const vec2& size = 1.0f, const float rotation = 0.0f,
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Sprite>::value>::type* = 0)
    {
        Transform<float> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window.DrawSprite(renderable, transform, GetCellSrc(cell), hor, ver);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2i& cell, 
        const vec2& size = 1.0f, const float rotation = 0.0f, const float depth = 0.0f,
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Decal>::value>::type* = 0)
    {
        sprBatch.Draw(renderable, pos, size, rotation, hor, ver, depth, 1.0f, GetCellSrcNorm(cell));
    }
};

typedef RenderableSheet<Sprite> SpriteSheet;
typedef RenderableSheet<Decal> DecalSheet;

template <class T> 
struct AnimFrameList
{
    static_assert(is_renderable<T>::value);
    std::vector<T> vecFrames;
    inline void AddFrame(const std::string& path) 
    { 
        vecFrames.emplace_back(path); 
    }
    inline void AddFrame(const T& renderable) 
    { 
        vecFrames.push_back(renderable); 
    }
    inline T& GetFrame(const size_t& index) 
    { 
        return (*this)[index]; 
    }
    inline T& operator[](const size_t& index) 
    { 
        return vecFrames[index]; 
    }
};

template <class T> 
struct AnimFrameList<RenderableSheet<T>>
{
    RenderableSheet<T>* gfxSource;
    std::vector<vec2i> vecFrames;
    inline void AddFrame(const vec2i& cell) 
    { 
        vecFrames.push_back(cell); 
    }
    inline const vec2i& operator[](const size_t& index) const 
    { 
        return vecFrames[index]; 
    }
    inline const vec2i& GetFrame(const size_t& index) const 
    { 
        return (*this)[index]; 
    }
};

template <class T> 
struct Animator
{
    AnimData data;
    AnimFrameList<T> animFrameList;
    inline void AddFrame(const std::string& path) 
    { 
        animFrameList.AddFrame(path); 
    }
    inline void AddFrame(const T& renderable) 
    { 
        animFrameList.AddFrame(renderable); 
    }
    inline T& GetFrame() 
    { 
        return animFrameList[data.index]; 
    }
    inline T& operator[](const size_t& index) 
    { 
        return animFrameList[index]; 
    }
    inline void Update(float deltaTime)
    { 
        data.Update(animFrameList.vecFrames.size(), deltaTime); 
    }
};

template <class T> 
struct Animator<RenderableSheet<T>>
{
    AnimData data;
    AnimFrameList<RenderableSheet<T>> animFrameList;
    inline void AddFrame(const vec2i& cell) 
    { 
        animFrameList.AddFrame(cell); 
    }
    inline const vec2i& GetFrame() const 
    { 
        return animFrameList[data.index]; 
    }
    inline const vec2i& operator[](const size_t& index) const 
    { 
        return animFrameList[index]; 
    }
    inline void Update(float deltaTime) 
    { 
        data.Update(animFrameList.vecFrames.size(), deltaTime); 
    }
};

#endif