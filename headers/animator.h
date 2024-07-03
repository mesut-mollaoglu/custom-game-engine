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

struct AnimFrameList
{
    std::vector<Sprite> frames;
    inline void AddFrame(const std::string& path) { frames.emplace_back(path); }
    inline void AddFrame(const Sprite& spr) { frames.push_back(spr); }
    inline Sprite& GetFrame(const std::size_t& index) { return frames[index]; }
    inline Sprite& operator[](const std::size_t& index) { return frames[index]; }
};

struct Animator
{
    AnimData data;
    AnimFrameList frameList;
    inline void AddFrame(const std::string& path) { frameList.AddFrame(path); }
    inline void AddFrame(const Sprite& spr) { frameList.AddFrame(spr); }
    inline Sprite& GetFrame() { return frameList.GetFrame(data.index); }
    inline Sprite& operator[](const std::size_t& index) { return frameList[index]; }
    inline void Update(float deltaTime){ data.Update(frameList.frames.size(), deltaTime); }
};

#endif