#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

template <class T> struct State
{
    std::unordered_map<int, Key> mouse;
    std::unordered_map<int, Key> keys;
    Animator<T> animator;
};

template <class T> struct StateMachine
{
    std::string currStateName, defStateName;
    std::unordered_map<std::string, State<T>> states;
    inline void SwitchStates(Window& window)
    {
        if(states[currStateName].animator.data.update == AnimUpdate::Once && !states[currStateName].animator.data.played)
            return;
        for(auto& [stateName, state] : states)
        {
            if(defStateName.empty() && state.mouse.empty() && state.keys.empty())
                defStateName = stateName;

            bool change = false;
            for(auto& [keycode, action] : state.keys) change = change || (window.GetKey(keycode) == action);
            for(auto& [keycode, action] : state.mouse) change = change || (window.GetMouseButton(keycode) == action);
            if(change)
            {
                SetState(stateName);
                return;
            }
        }
        SetState(defStateName);
    }
    inline void SetState(const std::string& state)
    {
        if(currStateName != state && states.count(state) != 0)
            states[currStateName = state].animator.data.Reset();
    }
    inline void Update(Window& window)
    {
        SwitchStates(window);
        states[currStateName].animator.Update(window.GetDeltaTime());
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2f& pos, const vec2f& size = 1.0f, const float rotation = 0.0f,
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Decal>::value>::type* = 0)
    {
        sprBatch.Draw(states[currStateName].animator.GetFrame(), pos, size, rotation, hor, ver, depth);
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, const vec2f& size = 1.0f, 
        const float rotation = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Sprite>::value>::type* = 0)
    {
        Transform transform;
        transform.Translate(pos.x, pos.y);
        transform.Rotate(rotation);
        transform.Scale(size.w, size.h);
        window.DrawSprite(states[currStateName].animator.GetFrame(), transform, hor, ver);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2f& pos, const vec2f& size = 1.0f, const float rotation = 0.0f, 
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, DecalSheet>::value>::type* = 0)
    {
        states[currStateName].animator.animFrameList.renFrameSheet.Draw(sprBatch, pos, states[currStateName].animator.GetFrame(), size, rotation, depth, hor, ver);
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, const vec2f& size = 1.0f, 
        const float rotation = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, SpriteSheet>::value>::type* = 0)
    {
        states[currStateName].animator.animFrameList.renFrameSheet.Draw(window, pos, states[currStateName].animator.GetFrame(), size, rotation, hor, ver);
    }
    inline State<T>& operator[](const std::string& str)
    {
        return states[str];
    }
    inline State<T>& GetState()
    {
        return states[currStateName];
    }
};

template <class T> struct EntityDef
{
    std::unordered_map<std::string, AnimFrameList<T>> animMap;
    inline AnimFrameList<T>& operator[](const std::string& str)
    {
        return animMap[str];
    }
};

template <class T> struct EntityStateMachine
{
    std::string currStateName;
    EntityDef<T>* def = nullptr;
    std::unordered_map<std::string, AnimData> states;
    inline void SetState(const std::string& state)
    {
        if(states[currStateName].update == AnimUpdate::Once && !states[currStateName].played) return;
        if(currStateName == state || states.count(state) == 0) return;
        states[currStateName = state].Reset();
    }
    inline void DefineState(
        const std::string& name, 
        const AnimUpdate& update, 
        const float duration)
    {
        if(states.count(name) != 0) return;
        states[name].duration = duration;
        states[name].update = update;
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, const vec2f& size = 1.0f, 
        const float rotation = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Sprite>::value>::type* = 0)
    {
        assert(def);
        Transform transform;
        transform.Translate(pos.x, pos.y);
        transform.Rotate(rotation);
        transform.Scale(size.w, size.h);
        window.DrawSprite(def->animMap[currStateName].vecFrames[states[currStateName].index], transform, hor, ver);
    }
    template <class U = T> inline void Draw(
        Window& window, const vec2i& pos, const vec2f& size = 1.0f, 
        const float rotation = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, SpriteSheet>::value>::type* = 0)
    {
        assert(def);
        def->animMap[currStateName].renFrameSheet.Draw(window, pos, def->animMap[currStateName].vecFrames[states[currStateName].index], size, rotation, hor, ver);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2f& pos, const vec2f& size = 1.0f, const float rotation = 0.0f, 
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, Decal>::value>::type* = 0)
    {
        assert(def);
        sprBatch.Draw(def->animMap[currStateName].vecFrames[states[currStateName].index], pos, size, rotation, hor, ver, depth);
    }
    template <class U = T> inline void Draw(
        SpriteBatch& sprBatch, const vec2f& pos, const vec2f& size = 1.0f, const float rotation = 0.0f,
        const float depth = 0.0f, Horizontal hor = Horizontal::Norm, Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, DecalSheet>::value>::type* = 0)
    {
        assert(def);
        def->animMap[currStateName].renFrameSheet.Draw(sprBatch, pos, def->animMap[currStateName].vecFrames[states[currStateName].index], size, rotation, depth, hor, ver);
    }
    inline void Update(float deltaTime)
    {
        assert(def);
        GetState().Update(def->animMap[currStateName].vecFrames.size(), deltaTime);
    }
    inline AnimFrameList<T>& GetFrameList(const std::string& str)
    {
        return def->operator[](str);
    }
    inline AnimFrameList<T>& GetFrameList()
    {
        return def->operator[](currStateName);
    }
    inline AnimData& operator[](const std::string& str)
    {
        return states[str];
    }
    inline AnimData& GetState()
    {
        return states[currStateName];
    }
};

#endif