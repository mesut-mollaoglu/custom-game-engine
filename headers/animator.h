#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "includes.h"

using steady_clock = std::chrono::steady_clock;
typedef std::chrono::time_point<steady_clock> time_point;

enum class animUpdate
{
    Once,
    Loop
};

struct animData
{
    std::size_t index = 0;
    bool played = false;
    bool reverse = false;
	float totalTime = 0.0f;
    animUpdate update = animUpdate::Loop;
    float duration;
    inline void Update(const std::size_t& size, float deltaTime)
    {
        switch(update)
        {
            case animUpdate::Loop: 
            {
                totalTime += (reverse ? -1.0f : 1.0f) * deltaTime;
                index = (std::size_t)(totalTime / duration) % size;
                index += (index < 0) ? size : 0;
            }
            break;
            case animUpdate::Once: 
            {
                if(!played) 
                {
                    totalTime += deltaTime * (reverse ? -1.0f : 1.0f);
                    index = (std::size_t)(totalTime / duration);
                    played = index == (reverse ? 0 : size - 1);
                }
            }
            break;
        }
    }
    inline void Reverse(bool rev)
    {
        if(reverse != rev)
        {
            reverse = rev;
            played = false;
        }
    }
};

struct Animator
{
    std::vector<Sprite> frames;
    animData data;
    inline Sprite& GetCurrFrame() { return frames[data.index]; }
    inline void Update(float deltaTime){ data.Update(frames.size(), deltaTime); }
};

#endif