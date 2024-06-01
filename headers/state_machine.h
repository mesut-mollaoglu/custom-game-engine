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
    std::unordered_map<std::string, State> states;
    std::string currentState;
    inline void SwitchStates(Window& window)
    {
        if(states[currentState].animator.data.update == animUpdate::Once)
        {
            if(states[currentState].animator.data.played) SetState("Idle");
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
        if(currentState != state)
        {
            auto& animator = states[currentState].animator;
            const std::size_t size = animator.frames.size() - 1;
            const bool reverse = animator.data.reverse;
            const float total = animator.data.duration * size;
            animator.data.index = (reverse ? size : 0);
            animator.data.totalTime = (reverse ? total : 0.0f);
            animator.data.played = false;
            currentState = state;
        }
    }
    inline void Update(Window& window, float deltaTime)
    {
        SwitchStates(window);
        states[currentState].animator.Update(deltaTime);
    }
    inline void Draw(
        Window& window, 
        const int32_t x, 
        const int32_t y, 
        const v2f& size = 1.0f, 
        Horizontal hor = Horizontal::Norm, 
        Vertical ver = Vertical::Norm)
    {
        window.DrawSprite(x, y, states[currentState].animator.GetCurrFrame(), size, hor, ver);
    }
};

#endif