#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

template <class T, typename StateEnum> 
struct EntityDef
{
    std::unordered_map<StateEnum, AnimationFrames<T>> animMap;
    inline AnimationFrames<T>& operator[](const StateEnum& state)
    {return animMap[state];}
};

template <class T, typename StateEnum> 
struct StateMachine
{
    StateEnum currStateName;
    EntityDef<T, StateEnum>* def = nullptr;
    std::unordered_map<StateEnum, AnimationController> states;
    inline void SetState(const StateEnum& state)
    {
        if(states[currStateName].update == UpdateRoutine::PlayOnce && !states[currStateName].playedOnce) return;
        if(currStateName == state || states.count(state) == 0) return;
        states[currStateName = state].Reset();
    }
    inline void DefineState(
        const StateEnum& name, 
        const UpdateRoutine& update, 
        const float duration)
    {
        if(states.count(name) != 0) return;
        states[name].duration = duration;
        states[name].update = update;
    }
    template <class U = T> inline void Draw(
        Window& window, const ivec2& pos, 
        const vec2& size = 1.0f, const float rotation = 0.0f, 
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if_t<std::is_same_v<U, Sprite>>* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        Transform<float> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window.DrawSprite(def->animMap[currStateName].vecFrames[states[currStateName].currFrameIndex], transform, hor, ver);
    }
    template <class U = T> inline void Draw(
        Window& window, const ivec2& pos, 
        const vec2& size = 1.0f, const float rotation = 0.0f, 
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if_t<std::is_same_v<U, SpriteSheet>>* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        def->animMap[currStateName].gfxSource->Draw(window, pos, def->animMap[currStateName].vecFrames[states[currStateName].currFrameIndex], size, rotation, hor, ver);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& size = 1.0f, const float rotation = 0.0f, 
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if_t<std::is_same_v<U, Decal>>* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        sprBatch.Draw(def->animMap[currStateName].vecFrames[states[currStateName].currFrameIndex], pos, size, rotation, hor, ver, depth);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& size = 1.0f, const float rotation = 0.0f,
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if_t<std::is_same_v<U, DecalSheet>>* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        def->animMap[currStateName].gfxSource->Draw(sprBatch, pos, def->animMap[currStateName].vecFrames[states[currStateName].currFrameIndex], size, rotation, depth, hor, ver);
    }
    inline void Update(float deltaTime)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        GetState().Update(def->animMap[currStateName].vecFrames.size(), deltaTime);
    }
    inline AnimationFrames<T>& GetFrames(const StateEnum& state)
    {return (*def)[state];}
    inline AnimationFrames<T>& GetFrames()
    {return (*def)[currStateName];}
    inline AnimationController& operator[](const StateEnum& state)
    {return states[state];}
    inline AnimationController& GetState()
    {return states[currStateName];}
};

#endif