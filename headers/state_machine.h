#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

template <class T, typename StateEnum> struct EntityDef
{
    std::unordered_map<StateEnum, AnimFrameList<T>> animMap;
    inline AnimFrameList<T>& operator[](const StateEnum& state)
    {
        return animMap[state];
    }
};

template <class T, typename StateEnum> struct StateMachine
{
    StateEnum currStateName;
    EntityDef<T, StateEnum>* def = nullptr;
    std::unordered_map<StateEnum, AnimData> states;
    inline void SetState(const StateEnum& state)
    {
        if(states[currStateName].update == AnimUpdate::Once && !states[currStateName].played) return;
        if(currStateName == state || states.count(state) == 0) return;
        states[currStateName = state].Reset();
    }
    inline void DefineState(
        const StateEnum& name, 
        const AnimUpdate& update, 
        const float duration)
    {
        if(states.count(name) != 0) return;
        states[name].duration = duration;
        states[name].update = update;
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, 
        const vec2f& size = 1.0f, const float rotation = 0.0f, 
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Sprite>::value>::type* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        Transform transform;
        transform.Translate(pos.x, pos.y);
        transform.Rotate(rotation);
        transform.Scale(size.w, size.h);
        window.DrawSprite(def->animMap[currStateName].vecFrames[states[currStateName].index], transform, hor, ver);
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, 
        const vec2f& size = 1.0f, const float rotation = 0.0f, 
        Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, SpriteSheet>::value>::type* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        def->animMap[currStateName].gfxSource->Draw(window, pos, def->animMap[currStateName].vecFrames[states[currStateName].index], size, rotation, hor, ver);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2f& pos, const vec2f& size = 1.0f, const float rotation = 0.0f, 
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Decal>::value>::type* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        sprBatch.Draw(def->animMap[currStateName].vecFrames[states[currStateName].index], pos, size, rotation, hor, ver, depth);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2f& pos, const vec2f& size = 1.0f, const float rotation = 0.0f,
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, DecalSheet>::value>::type* = 0)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        def->animMap[currStateName].gfxSource->Draw(sprBatch, pos, def->animMap[currStateName].vecFrames[states[currStateName].index], size, rotation, depth, hor, ver);
    }
    inline void Update(float deltaTime)
    {
        assert(def != nullptr && def->animMap.count(currStateName) != 0);
        GetState().Update(def->animMap[currStateName].vecFrames.size(), deltaTime);
    }
    inline AnimFrameList<T>& GetFrameList(const StateEnum& state)
    {
        return def->operator[](state);
    }
    inline AnimFrameList<T>& GetFrameList()
    {
        return def->operator[](currStateName);
    }
    inline AnimData& operator[](const StateEnum& state)
    {
        return states[state];
    }
    inline AnimData& GetState()
    {
        return states[currStateName];
    }
};

#endif