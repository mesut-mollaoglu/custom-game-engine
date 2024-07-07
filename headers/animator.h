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
    std::size_t index = 0;
    bool played = false;
    bool reverse = false;
    float totalTime = 0.0f;
    AnimUpdate update = AnimUpdate::Loop;
    float duration;
    inline void Update(const std::size_t& size, float deltaTime)
    {
        switch(update)
        {
            case AnimUpdate::Loop: 
            {
                totalTime += deltaTime;
                index = (std::size_t)(totalTime / duration) % size;
            }
            break;
            case AnimUpdate::Once: 
            {
                totalTime += played ? 0.0f : deltaTime;
                index = std::min<std::size_t>(totalTime / duration, size - 1);
            }
            break;
            case AnimUpdate::PingPong:
            {
                totalTime += deltaTime;
                index = std::min<std::size_t>(totalTime / duration, size - 1);
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

template <class T> struct is_renderable : std::integral_constant
    <bool, std::is_same<T, Sprite>::value ||
    std::is_same<T, Decal>::value ||
    std::is_same<T, SpriteSheet>::value>
    {};

template <class T, typename = typename std::enable_if<is_renderable<T>::value>::type> 
struct AnimFrameList
{
    std::vector<T> vecFrames;
    inline void AddFrame(const std::string& path) { vecFrames.emplace_back(path); }
    inline void AddFrame(const T& renderable) { vecFrames.push_back(renderable); }
    inline T& GetFrame(const std::size_t& index) { return this->operator[](index); }
    inline T& operator[](const std::size_t& index) { return vecFrames[index]; }
};

template <> struct AnimFrameList<SpriteSheet>
{
    SpriteSheet sprSheet;
    std::vector<vec2i> vecFrames;
    inline void AddFrame(const vec2i& cell) { vecFrames.push_back(cell); }
    inline const vec2i& operator[](const std::size_t& index) const { return vecFrames[index]; }
    inline const vec2i& GetFrame(const std::size_t& index) const { return this->operator[](index); }
};

template <class T> struct Animator
{
    AnimData data;
    AnimFrameList<T> animFrameList;
    inline void AddFrame(const std::string& path) { animFrameList.AddFrame(path); }
    inline void AddFrame(const T& renderable) { animFrameList.AddFrame(renderable); }
    inline T& GetFrame() { return animFrameList.GetFrame(data.index); }
    inline T& operator[](const std::size_t& index) { return animFrameList[index]; }
    inline void Update(float deltaTime){ data.Update(animFrameList.vecFrames.size(), deltaTime); }
};

template <> struct Animator<SpriteSheet>
{
    AnimData data;
    AnimFrameList<SpriteSheet> animFrameList;
    inline void AddFrame(const vec2i& cell) { animFrameList.AddFrame(cell); }
    inline const vec2i& GetFrame() const { return animFrameList[data.index]; }
    inline const vec2i& operator[](const std::size_t& index) const { return animFrameList[index]; }
    inline void Update(float deltaTime) { data.Update(animFrameList.vecFrames.size(), deltaTime); }
};

#endif