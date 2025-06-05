#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

template <template <typename> class AnimT>
struct is_animator : std::disjunction<
    std::is_same<AnimT<Sprite>, Animator<Sprite>>,
    std::is_same<AnimT<Sprite>, PartialAnimator<Sprite>>>
    {};

template <template <typename> class AnimT>
inline constexpr bool is_animator_v = is_animator<AnimT>::value;

template <
    class SourceImageT, 
    typename StateEnum, 
    template <typename> class AnimT = Animator,
    typename = std::enable_if_t<is_animator_v<AnimT>>>
struct EntityDef
{
    std::unordered_map<StateEnum, AnimT<SourceImageT>> m_animMap;
    inline AnimT<SourceImageT>&
    operator[](const StateEnum& state)
    {
        return m_animMap[state];
    }
    inline const AnimT<SourceImageT>&
    operator[](const StateEnum& state) const
    {
        return m_animMap[state];
    }
};

template <
    class SourceImageT, 
    typename StateEnum, 
    template <typename> class AnimT = Animator,
    typename = std::enable_if_t<is_animator_v<AnimT>>>
class StateMachine
{
private:
    using EntDef = EntityDef<SourceImageT, StateEnum, AnimT>*;
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
        f32 duration = 0.1f,
        const Style& style = Style::Repeat)
    {
        if(!m_mapStates.count(state))
            m_mapStates[state] = Animation(duration, style);
    }
    inline bool IsCurrentState(const StateEnum& state) const
    {
        return m_mapStates.count(state) && m_currStateEnum == state;
    }
    inline bool HasCurrentAnimationFinishedPlaying()
    {
        return m_mapStates[m_currStateEnum].HasFinishedPlaying((*m_entityDef)[m_currStateEnum].size());
    }
    template <class ImageT = SourceImageT, template <typename> class AnimatorT = AnimT> 
    inline void Draw(
        Window* window, const ivec2& pos, const vec2& size = 1.0f, f32 rotation = 0.0f, u8 flip = 0,
        std::enable_if_t<std::is_same_v<AnimatorT<ImageT>, Animator<ImageT>> 
            && std::is_same_v<ImageT, Sprite>>* = 0)
    {
        Frame<ImageT>& frame = (*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()];
        Transform<f32> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window->DrawSprite(frame.GetImage(), transform, frame.GetSourceRect(), flip);
    }
    template <class ImageT = SourceImageT, template <typename> class AnimatorT = AnimT> 
    inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f, 
        f32 rotation = 0.0f, f32 depth = 0.0f, u8 flip = 0,
        std::enable_if_t<std::is_same_v<AnimatorT<ImageT>, Animator<ImageT>>
            && std::is_same_v<ImageT, Decal>>* = 0)
    {
        Frame<ImageT>& frame = (*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()];
        sprBatch.Draw(frame.GetImage(), pos, scale, rotation, flip, depth, {1.0f, 1.0f, 1.0f, 1.0f}, frame.GetSourceRect());
    }
    template <class ImageT = SourceImageT, template <typename> class AnimatorT = AnimT> 
    inline void Draw(
        Window* window, const ivec2& pos, const vec2& size = 1.0f, f32 rotation = 0.0f, u8 flip = 0,
        std::enable_if_t<std::is_same_v<AnimatorT<ImageT>, PartialAnimator<ImageT>>
            && std::is_same_v<ImageT, Sprite>>* = 0)
    {
        Transform<f32> transform;
        transform.Translate(pos);
        transform.Rotate(rotation);
        transform.Scale(size);
        window->DrawSprite((*m_entityDef)[m_currStateEnum].GetSourceImage(), transform,
            (*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()], flip);
    }
    template <class ImageT = SourceImageT, template <typename> class AnimatorT = AnimT>  
    inline void Draw(
        SpriteBatch& sprBatch, const vec2& pos, const vec2& scale = 1.0f, 
        f32 rotation = 0.0f, f32 depth = 0.0f, u8 flip = 0,
        std::enable_if_t<std::is_same_v<AnimatorT<ImageT>, PartialAnimator<ImageT>> 
            && std::is_same_v<ImageT, Decal>>* = 0)
    {
        sprBatch.Draw((*m_entityDef)[m_currStateEnum].GetSourceImage(), pos, scale, rotation, flip, depth,
        {1.0f, 1.0f, 1.0f, 1.0f}, (*m_entityDef)[m_currStateEnum][m_mapStates[m_currStateEnum].GetIndex()]);
    }
    inline void Update(f32 delta)
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