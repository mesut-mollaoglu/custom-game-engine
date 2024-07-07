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
    std::string currState;
    std::unordered_map<std::string, State<T>> states;
    inline void SwitchStates(Window& window)
    {
        if(states[currState].animator.data.update == AnimUpdate::Once)
        {
            if(states[currState].animator.data.played) SetState("Idle");
            else return;
        }
        for(auto& state : states)
        {
            if(!state.second.keys.empty() || !state.second.mouse.empty())
            {
                bool change = false;
                for(auto& key : state.second.keys) 
                {
                    Key state = window.GetKey(key.first);
                    change = change || (state == key.second);
                }
                for(auto& button : state.second.mouse)
                {
                    Key state = window.GetMouseButton(button.first);
                    change = change || (state == button.second);
                }
                if(change)
                {
                    SetState(state.first);
                    return;
                }
            }
        }
        SetState("Idle");
    }
    inline void SetState(const std::string& state)
    {
        if(currState != state && states.count(state) != 0)
            states[currState = state].animator.data.Reset();
    }
    inline void Update(Window& window)
    {
        SwitchStates(window);
        states[currState].animator.Update(window.timer.deltaTime);
    }
    template <class U = T> inline void Draw
    (
        Window& window, 
        const vec2i& pos, 
        const vec2f& size = 1.0f, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm,
        typename std::enable_if<!std::is_same<U, SpriteSheet>::value>::type* = 0
    )
    {
        window.DrawSprite(pos.x, pos.y, states[currState].animator.GetFrame(), size, hor, ver);
    }
    template <class U = T> inline void Draw
    (
        Window& window, 
        const vec2i& pos, 
        const vec2f& size = 1.0f, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, SpriteSheet>::value>::type* = 0
    )
    {
        states[currState].animator.animFrameList.sprSheet.Draw(window, pos, size, states[currState].animator.GetFrame(), hor, ver);
    }
    inline State<T>& operator[](const std::string& str)
    {
        return states[str];
    }
    inline State<T>& GetState()
    {
        return states[currState];
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
    std::string currState;
    EntityDef<T>* def = nullptr;
    std::unordered_map<std::string, AnimData> states;
    inline void SetState(std::string state)
    {
        if(states[currState].update == AnimUpdate::Once)
        {
            if(states[currState].played) state = "Idle";
            else return;
        }
        if(currState == state || states.count(state) == 0) return;
        states[currState = state].Reset();
    }
    inline void DefineState
    (
        const std::string& name, 
        const AnimUpdate& update, 
        const float duration
    )
    {
        if(states.count(name) != 0) return;
        states[name].duration = duration;
        states[name].update = update;
    }
    template <class U = T> inline void Draw
    (
        Window& window, 
        const vec2i& pos, 
        const vec2f& size = 1.0f, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm,
        typename std::enable_if<!std::is_same<U, SpriteSheet>::value>::type* = 0
    )
    {
        assert(def);
        window.DrawSprite(pos.x, pos.y, def->animMap[currState].vecFrames[states[currState].index], size, hor, ver);
    }
    template <class U = T> inline void Draw
    (
        Window& window, 
        const vec2i& pos, 
        const vec2f& size = 1.0f, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm,
        typename std::enable_if<std::is_same<U, SpriteSheet>::value>::type* = 0
    )
    {
        assert(def);
        def->animMap[currState].sprSheet.Draw(window, pos, size, def->animMap[currState].vecFrames[states[currState].index], hor, ver);
    }
    inline void Update(float deltaTime)
    {
        assert(def);
        GetState().Update(def->animMap[currState].vecFrames.size(), deltaTime);
    }
    inline AnimFrameList<T>& GetFrameList(const std::string& str)
    {
        return def->operator[](str);
    }
    inline AnimFrameList<T>& GetFrameList()
    {
        return def->operator[](currState);
    }
    inline AnimData& operator[](const std::string& str)
    {
        return states[str];
    }
    inline AnimData& GetState()
    {
        return states[currState];
    }
};

#endif