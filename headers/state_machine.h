#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

template <template <typename> class _AnimatorT>
struct is_animator : std::disjunction<
    are_same_tpl<_AnimatorT<Sprite>, Animator<Decal>>,
    are_same_tpl<_AnimatorT<Sprite>, PartialAnimator<Decal>>>
    {};

template <template <typename> class _AnimatorT>
inline constexpr bool is_animator_v = is_animator<_AnimatorT>::value;

template <
    class ImageSource, 
    typename StateEnum, 
    template <typename> class _AnimatorT = Animator,
    typename = typename std::enable_if_t<is_animator_v<_AnimatorT>>>
struct EntityDef
{
    std::unordered_map<StateEnum, _AnimatorT<ImageSource>> m_animMap;
    inline _AnimatorT<ImageSource>&
    operator[](const StateEnum& state)
    {
        return m_animMap[state];
    }
    inline const _AnimatorT<ImageSource>&
    operator[](const StateEnum& state) const
    {
        return m_animMap[state];
    }
};

template <
    class ImageSource, 
    typename StateEnum, 
    template <typename> class _AnimatorT = Animator,
    typename = typename std::enable_if_t<is_animator_v<_AnimatorT>>>
class StateMachine
{
private:
    using EntDef = EntityDef<ImageSource, StateEnum, _AnimatorT>*;
    StateEnum m_currStateEnum;
    EntDef m_entityDef = nullptr;
    std::unordered_map<StateEnum, Animation> m_mapStates;
public:
    inline void SetDefinition(EntDef def)
    {
        m_entityDef = def;
    }
    inline void SetState(const StateEnum& state)
    {
        if(m_currStateEnum != state)
            m_mapStates[m_currStateEnum = state].Reset();
    }
    inline void DefineState(
        const StateEnum& state,
        float duration = 0.1f,
        const Style& style = Style::Repeat)
    {
        if(!m_mapStates.count(state))
            m_mapStates[state] = Animation(duration, style);
    }
    inline bool IsCurrentState(const StateEnum& state) const
    {
        return m_mapStates.count(state) && m_currStateEnum == state;
    }
    inline bool HasFinishedPlaying()
    {
        return m_mapStates[m_currStateEnum].HasFinishedPlaying((*m_entityDef)[m_currStateEnum].size());
    }
    template <class Source = ImageSource, template <typename> class AnimatorT = _AnimatorT> 
    inline void Draw(
        Window& window, const ivec2& pos, const vec2& size = 1.0f, float rotation = 0.0f, uint8_t flip = 0,
        typename std::enable_if_t<are_same_tpl<AnimatorT<Source>, Animator<Source>>::value 
            && std::is_same_v<Source, Sprite>>* = 0)
    {
        Transform<float> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window.DrawSprite((*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()], 
            transform, flip);
    }
    template <class Source = ImageSource, template <typename> class AnimatorT = _AnimatorT> 
    inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f, 
        float rotation = 0.0f, float depth = 0.0f, uint8_t flip = 0,
        typename std::enable_if_t<are_same_tpl<AnimatorT<Source>, Animator<Source>>::value 
            && std::is_same_v<Source, Decal>>* = 0)
    {
        sprBatch.Draw((*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()], 
            pos, scale, rotation, flip, depth);
    }
    template <class Source = ImageSource, template <typename> class AnimatorT = _AnimatorT> 
    inline void Draw(
        Window& window, const ivec2& pos, const vec2& size = 1.0f, float rotation = 0.0f, uint8_t flip = 0,
        typename std::enable_if_t<are_same_tpl<AnimatorT<Source>, PartialAnimator<Source>>::value 
            && std::is_same_v<Source, Sprite>>* = 0)
    {
        Transform<float> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window.DrawSprite((*m_entityDef)[m_currStateEnum].GetSourceImage(), transform,
            (*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()], flip);
    }
    template <class Source = ImageSource, template <typename> class AnimatorT = _AnimatorT>  
    inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f, 
        float rotation = 0.0f, float depth = 0.0f, uint8_t flip = 0,
        typename std::enable_if_t<are_same_tpl<AnimatorT<Source>, PartialAnimator<Source>>::value 
            && std::is_same_v<Source, Decal>>* = 0)
    {
        sprBatch.Draw((*m_entityDef)[m_currStateEnum].GetSourceImage(), pos, scale, rotation, flip, depth,
        {1.0f, 1.0f, 1.0f, 1.0f}, (*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()]);
    }
    inline void Update(float delta)
    {
        m_mapStates[m_currStateEnum].Update((*m_entityDef)[m_currStateEnum].size(), delta);
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