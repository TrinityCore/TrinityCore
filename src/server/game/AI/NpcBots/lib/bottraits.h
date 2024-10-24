#ifndef BOT_TRAITS_H
#define BOT_TRAITS_H

#include "botcommon.h"

#include "Creature.h"
#include "Log.h"
#include "SpellAuraEffects.h"

#include <array>
#include <tuple>

namespace NPCBots
{

template<typename T, std::size_t... Is>
constexpr auto fixed_tuple_helper(std::index_sequence<Is...> const&) -> decltype(std::make_tuple(((void)Is, std::declval<T>())...));

template<typename T, size_t N>
struct fixed_tuple {
    using tuple_type = decltype(fixed_tuple_helper<T>(std::make_index_sequence<N>{}));
};

template<typename T, std::size_t N, std::size_t... Is>
typename fixed_tuple<T,N>::tuple_type to_tuple_helper(std::array<T, N>&& arr, std::index_sequence<Is...>&&)
{
    return std::make_tuple(arr[Is]...);
}

template<typename T, size_t N>
typename fixed_tuple<T,N>::tuple_type to_tuple(std::array<T, N>&& arr)
{
    return to_tuple_helper(std::forward<std::array<T, N>>(arr), std::make_index_sequence<N>{});
}

template<typename T, std::size_t N, std::size_t... Is>
typename fixed_tuple<typename T::second_type, N>::tuple_type to_spell_school_affect_bool_tuple_helper(std::array<T, N>&& arr, std::index_sequence<Is...>&&)
{
    return std::make_tuple(arr[Is].second...);
}

template<typename T, size_t N>
typename fixed_tuple<typename T::second_type, N>::tuple_type to_spell_school_affect_bool_tuple(std::array<T, N>&& arr)
{
    return to_spell_school_affect_bool_tuple_helper(std::forward<std::array<T, N>>(arr), std::make_index_sequence<N>{});
}

template<typename T, std::size_t N, std::size_t... Is>
std::array<typename T::second_type,N> to_spell_school_affect_bool_arr_helper(std::array<T, N>&& arr, std::index_sequence<Is...>&&)
{
    return std::array{ arr[Is].second... };
}

template<typename T, size_t N>
std::array<typename T::second_type,N> to_spell_school_affect_bool_arr(std::array<T, N>&& arr)
{
    return to_spell_school_affect_bool_arr_helper(std::forward<std::array<T, N>>(arr), std::make_index_sequence<N>{});
}

}

template<typename School, typename... Schools>
std::enable_if_t<std::conjunction_v<std::is_same<School, SpellSchools>, std::is_same<Schools, SpellSchools>...>,
    bool>
all_schools_valid(School school, Schools... schools)
{
    if (school < SPELL_SCHOOL_NORMAL || school >= MAX_SPELL_SCHOOL)
        return false;

    if constexpr (sizeof...(Schools) > 0)
        return all_schools_valid(schools...);
    return true;
}

template<class...Schools>
std::enable_if_t<std::conjunction_v<std::is_same<Schools, SpellSchools>...>, std::array<std::pair<SpellSchools, bool>, sizeof...(Schools)>>
CanAffectVictimSchools(Unit const* target, Schools... schools)
{
    static_assert(sizeof...(Schools) > 0, "need at least 1 spell school to check for");

    using arr_type = std::array<std::pair<SpellSchools, bool>, sizeof...(Schools)>;
    using arr_iter_type = typename arr_type::iterator;
    arr_type results{ std::pair{schools, true}... };

    if (!all_schools_valid(schools...))
    {
        TC_LOG_ERROR("entities.player", "bot_ai::CanAffectVictimSchools(): trying to check invalid spell school, first: {}", uint32(results.at(0).first));
        return results;
    }

    if (Creature const* creature = target->ToCreature())
    {
        if (SpellSchoolMask immune_mask = SpellSchoolMask(creature->GetCreatureTemplate()->SpellSchoolImmuneMask))
        {
            for (uint8 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
            {
                if (immune_mask & (1 << i))
                {
                    arr_iter_type ri = std::find(results.begin(), results.end(), std::pair{ SpellSchools(i), true });
                    if (ri != results.end())
                        ri->second = false;
                }
            }
        }
    }

    for (AuraEffect const* immune_effect : target->GetAuraEffectsByType(SPELL_AURA_SCHOOL_IMMUNITY))
    {
        if (SpellSchoolMask immune_mask = SpellSchoolMask(immune_effect->GetMiscValue()))
        {
            for (uint8 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
            {
                if (immune_mask & (1 << i))
                {
                    arr_iter_type ri = std::find(results.begin(), results.end(), std::pair{ SpellSchools(i), true });
                    if (ri != results.end())
                        ri->second = false;
                }
            }
        }
    }
    return results;
}

template<class...Schools>
typename NPCBots::fixed_tuple<bool, sizeof...(Schools)>::tuple_type
CanAffectVictimBools(Unit const* target, Schools... schools)
{
    return NPCBots::to_spell_school_affect_bool_tuple(CanAffectVictimSchools(target, schools...));
}

template<class...Schools>
bool
CanAffectVictimAny(Unit const* target, Schools... schools)
{
    using arr_type = std::array<std::pair<SpellSchools, bool>, sizeof...(Schools)>;
    using pair_type = typename arr_type::value_type;

    arr_type bools = CanAffectVictimSchools(target, schools...);

    return std::any_of(bools.cbegin(), bools.cend(), [](pair_type const& p) { return p.second; });
}

template<class...Schools>
bool
CanAffectVictimAll(Unit const* target, Schools... schools)
{
    using arr_type = std::array<std::pair<SpellSchools, bool>, sizeof...(Schools)>;
    using pair_type = typename arr_type::value_type;

    arr_type bools = CanAffectVictimSchools(target, schools...);

    return std::all_of(bools.cbegin(), bools.cend(), [](pair_type const& p) { return p.second; });
}

#endif
