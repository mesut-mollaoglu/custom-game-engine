#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

struct State
{
    std::unordered_map<int, Key> mouse;
    std::unordered_map<int, Key> keys;
    Animator animator;
};

struct StateMachine
{
    std::string currState;
    std::unordered_map<std::string, State> states;
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
        if(currState != state)
            states[currState = state].animator.data.Reset();
    }
    inline void Update(Window& window, float deltaTime)
    {
        SwitchStates(window);
        states[currState].animator.Update(deltaTime);
    }
    inline void Draw
    (
        Window& window, 
        const int32_t x, 
        const int32_t y, 
        const v2f& size = 1.0f, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm
    )
    {
        window.DrawSprite(x, y, states[currState].animator.GetFrame(), size, hor, ver);
    }
    inline State& operator[](const std::string& str)
    {
        return states[str];
    }
    inline State& GetState()
    {
        return states[currState];
    }
};

struct EntityDef
{
    std::unordered_map<std::string, AnimFrameList> animMap;
    inline AnimFrameList& operator[](const std::string& str)
    {
        return animMap[str];
    }
};

struct EntityStateMachine
{
    std::string currState;
    EntityDef* def = nullptr;
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
    inline void Draw
    (
        Window& window,
        const int32_t x,
        const int32_t y,
        const v2f& size = 1.0f,
        Horizontal hor = Horizontal::Norm,
        Vertical ver = Vertical::Norm
    )
    {
        assert(def);
        window.DrawSprite(x, y, def->animMap[currState].frames[states[currState].index], size, hor, ver);
    }
    inline void Update(float deltaTime)
    {
        assert(def);
        GetState().Update(def->animMap[currState].frames.size(), deltaTime);
    }
    inline AnimFrameList& GetFrameList(const std::string& str)
    {
        return def->operator[](str);
    }
    inline AnimFrameList& GetFrameList()
    {
        return GetFrameList(currState);
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