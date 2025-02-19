#ifndef ANIMATOR_H
#define ANIMATOR_H

enum class UpdateRoutine : uint8_t
{
    PlayOnce,
    Loop,
    PingPong
};

struct AnimationController
{
    size_t currFrameIndex = 0;
    float elapsedTime = 0.0f, duration;
    bool playedOnce = false, reverse = false;
    UpdateRoutine update = UpdateRoutine::Loop;
    inline void Update(const size_t& size, float dt)
    {
        switch(update)
        {
            case UpdateRoutine::Loop: 
            {
                elapsedTime += dt;
                currFrameIndex = (size_t)(elapsedTime / duration) % size;
            }
            break;
            case UpdateRoutine::PlayOnce: 
            {
                elapsedTime += playedOnce ? 0.0f : dt;
                currFrameIndex = std::min<size_t>(elapsedTime / duration, size - 1);
            }
            break;
            case UpdateRoutine::PingPong:
            {
                elapsedTime += dt;
                currFrameIndex = std::min<size_t>(elapsedTime / duration, size - 1);
                if(playedOnce) Reverse();
            }
            break;
        }
        playedOnce = elapsedTime >= duration * (size - 1);
        currFrameIndex = reverse ? size - 1 - currFrameIndex : currFrameIndex;
    }
    inline void Reverse()
    {
        reverse = !reverse;
        playedOnce = false;
        elapsedTime = 0.0f;
    }
    inline void Reset()
    {
        playedOnce = false;
        elapsedTime = 0.0f;
        currFrameIndex = 0ull;
    }
};

template <class T, typename = typename std::enable_if_t<is_renderable_v<T>>> 
struct RenderableSheet
{
    T renderable;
    ivec2 vecCellSize;
    inline RenderableSheet() = default;
    inline RenderableSheet(const std::string& path, const ivec2& vecCellSize) : vecCellSize(vecCellSize)
    {
        renderable = T(path);
    }
    inline Rect<int32_t> GetCellSrc(const ivec2& cell)
    {
        return {vecCellSize * cell, vecCellSize};
    }
    inline Rect<float> GetCellSrcNorm(const ivec2& cellPos)
    {
        return GetCellSrc(cellPos) * inv((vec2)renderable.GetSize());
    }
    template <class U = T> inline void Draw(
        Window& window, const ivec2& pos, 
        const ivec2& cell, const vec2& scale = 1.0f, 
        const float rotation = 0.0f, const vec2& origin = 0.0f, 
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if_t<std::is_same_v<U, Sprite>>* = 0)
    {
        Transform<float> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(scale);
        window.DrawSprite(renderable, transform, GetCellSrc(cell), hor, ver, origin);
    }
    template <class U = T> inline void Draw(
        Window& window, const ivec2& pos, 
        const Rect<float>& src, const vec2& scale = 1.0f, 
        const float rotation = 0.0f, const vec2& origin = 0.0f, 
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm, 
        typename std::enable_if_t<std::is_same_v<U, Sprite>>* = 0)
    {
        Transform<float> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(scale);
        window.DrawSprite(renderable, transform, src, hor, ver, origin);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f,
        const Rect<float>& src = {0.0f, 1.0f}, const float rotation = 0.0f,
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm, 
        typename std::enable_if_t<std::is_same_v<U, Decal>>* = 0)
    {
        sprBatch.Draw(renderable, pos, scale, rotation, hor, ver, depth, 1.0f, src);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const ivec2& cell, 
        const vec2& scale = 1.0f, const float rotation = 0.0f, const float depth = 0.0f,
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if_t<std::is_same_v<U, Decal>>* = 0)
    {
        sprBatch.Draw(renderable, pos, scale, rotation, hor, ver, depth, 1.0f, GetCellSrcNorm(cell));
    }
};

typedef RenderableSheet<Sprite> SpriteSheet;
typedef RenderableSheet<Decal> DecalSheet;

template <class T> 
struct AnimationFrames
{
    static_assert(is_renderable_v<T>);
    std::vector<T> vecFrames;
    inline void AddFrame(const std::string& path) 
    {vecFrames.emplace_back(path);}
    inline void AddFrame(const T& renderable) 
    {vecFrames.push_back(renderable);}
    inline T& GetFrame(const size_t& index) 
    {return (*this)[index];}
    inline T& operator[](const size_t& index) 
    {return vecFrames[index];}
};

template <class T> 
struct AnimationFrames<RenderableSheet<T>>
{
    RenderableSheet<T>* gfxSource;
    std::vector<ivec2> vecFrames;
    inline void AddFrame(const ivec2& cell) 
    {vecFrames.push_back(cell);}
    inline const ivec2& operator[](const size_t& index) const 
    {return vecFrames[index];}
    inline const ivec2& GetFrame(const size_t& index) const 
    {return (*this)[index];}
};

template <class T> 
struct Animator
{
    AnimationController data;
    AnimationFrames<T> animFrameList;
    inline void AddFrame(const std::string& path) 
    {animFrameList.AddFrame(path);}
    inline void AddFrame(const T& renderable) 
    {animFrameList.AddFrame(renderable);}
    inline T& GetFrame() 
    {return animFrameList[data.currFrameIndex];}
    inline T& operator[](const size_t& index) 
    {return animFrameList[index];}
    inline void Update(float deltaTime)
    {data.Update(animFrameList.vecFrames.size(), deltaTime);}
};

template <class T> 
struct Animator<RenderableSheet<T>>
{
    AnimationController data;
    AnimationFrames<RenderableSheet<T>> animFrameList;
    inline void AddFrame(const ivec2& cell) 
    {animFrameList.AddFrame(cell);}
    inline const ivec2& GetFrame() const 
    {return animFrameList[data.currFrameIndex];}
    inline const ivec2& operator[](const size_t& index) const 
    {return animFrameList[index];}
    inline void Update(float deltaTime) 
    {data.Update(animFrameList.vecFrames.size(), deltaTime);}
};

#endif