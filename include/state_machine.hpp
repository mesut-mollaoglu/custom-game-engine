#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

template <template <typename> class AnimatorT>
struct is_animator : std::disjunction<
    std::is_same<AnimatorT<Sprite>, Animator<Sprite>>,
    std::is_same<AnimatorT<Sprite>, PartialAnimator<Sprite>>>
    {};

template <template <typename> class AnimatorT>
inline constexpr bool is_animator_v = is_animator<AnimatorT>::value;

template <
    class SourceImageT, 
    typename StateEnum, 
    template <typename> class AnimatorT = Animator,
    typename = std::enable_if_t<is_animator_v<AnimatorT>>>
struct EntityDefinition
{
private:
    std::unordered_map<StateEnum, AnimatorT<SourceImageT>> m_mapAnimations;
public:
    inline AnimatorT<SourceImageT>&
    operator[](const StateEnum& s)
    {
        return m_mapAnimations[s];
    }
    inline const AnimatorT<SourceImageT>&
    operator[](const StateEnum& s) const
    {
        return m_mapAnimations[s];
    }
};

template <
    class SourceImageT, 
    typename StateEnum, 
    template <typename> class AnimatorT = Animator,
    typename = std::enable_if_t<is_animator_v<AnimatorT>>>
class StateMachine
{
private:
    StateEnum m_activeState;
    EntityDefinition<SourceImageT, StateEnum, AnimatorT>* m_entityDef = nullptr;
    std::unordered_map<StateEnum, Animation> m_mapStates;
public:
    inline void SetDefinition(EntityDefinition<SourceImageT, StateEnum, AnimatorT>* def)
    {
        m_entityDef = def;
    }
    inline void SetState(const StateEnum& state)
    {
        if(m_activeState != state)
            m_mapStates[m_activeState = state].Reset();
    }
    inline void DefineState(
        const StateEnum& state,
        f32 duration = 0.1f,
        const Animation::Style& style = Animation::Style::Repeat)
    {
        if(!m_mapStates.count(state))
            m_mapStates[state] = Animation(duration, style);
    }
    inline bool IsCurrentState(const StateEnum& state) const
    {
        return m_mapStates.count(state) && m_activeState == state;
    }
    inline bool HasCurrentAnimationFinishedPlaying()
    {
        return m_mapStates[m_activeState].HasFinishedPlaying((*m_entityDef)[m_activeState].size());
    }
    template <class ImageT = SourceImageT, template <typename> class _AnimatorT = AnimatorT> 
    inline void Draw(Window* window, const ivec2& pos, const vec2& size = 1.0f, f32 rotation = 0.0f, Flip flip = Flip::None,
        std::enable_if_t<std::is_same_v<_AnimatorT<ImageT>, Animator<ImageT>> && std::is_same_v<ImageT, Sprite>>* = 0)
    {
        Frame<ImageT>& frame = (*m_entityDef)[m_activeState][m_mapStates[m_activeState].GetIndex()];
        Transform<f32> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window->DrawSprite(frame.GetImage(), transform, frame.GetSourceRect(), flip);
    }
    template <class ImageT = SourceImageT, template <typename> class _AnimatorT = AnimatorT> 
    inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f, 
        f32 rotation = 0.0f, f32 depth = 0.0f, Flip flip = Flip::None,
        std::enable_if_t<std::is_same_v<_AnimatorT<ImageT>, Animator<ImageT>>
            && std::is_same_v<ImageT, Decal>>* = 0)
    {
        Frame<ImageT>& frame = (*m_entityDef)[m_activeState][m_mapStates[m_activeState].GetIndex()];
        sprBatch.Draw(frame.GetImage(), pos, scale, rotation, flip, depth, {1.0f, 1.0f, 1.0f, 1.0f}, frame.GetSourceRect());
    }
    template <class ImageT = SourceImageT, template <typename> class _AnimatorT = AnimatorT> 
    inline void Draw(Window* window, const ivec2& pos, const vec2& size = 1.0f, f32 rotation = 0.0f, Flip flip = Flip::None,
        std::enable_if_t<std::is_same_v<_AnimatorT<ImageT>, PartialAnimator<ImageT>> && std::is_same_v<ImageT, Sprite>>* = 0)
    {
        Transform<f32> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window->DrawSprite((*m_entityDef)[m_activeState].GetSourceImage(), transform,
            (*m_entityDef)[m_activeState][m_mapStates[m_activeState].GetIndex()], flip);
    }
    template <class ImageT = SourceImageT, template <typename> class _AnimatorT = AnimatorT>  
    inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f, 
        f32 rotation = 0.0f, f32 depth = 0.0f, Flip flip = Flip::None,
        std::enable_if_t<std::is_same_v<_AnimatorT<ImageT>, PartialAnimator<ImageT>> 
            && std::is_same_v<ImageT, Decal>>* = 0)
    {
        sprBatch.Draw((*m_entityDef)[m_activeState].GetSourceImage(), pos, scale, rotation, flip, depth,
        {1.0f, 1.0f, 1.0f, 1.0f}, (*m_entityDef)[m_activeState][m_mapStates[m_activeState].GetIndex()]);
    }
    inline void Update(f32 delta)
    {
        m_mapStates[m_activeState].Update((*m_entityDef)[m_activeState].size(), delta);
    }
    inline Animation& 
    operator[](const StateEnum& state)
    {
        return m_mapStates[state];
    }
    inline const Animation& 
    operator[](const StateEnum& state) const
    {
        return m_mapStates[state];
    }
};

#endif