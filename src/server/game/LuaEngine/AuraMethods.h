/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef AURAMETHODS_H
#define AURAMETHODS_H

/***
 * The persistent effect of a [Spell] that remains on a [Unit] after the [Spell]
 *   has been cast.
 *
 * As an example, if you cast a damage-over-time spell on a target, an [Aura] is
 *   put on the target that deals damage continuously.
 *
 * [Aura]s on your player are displayed in-game as a series of icons to the left
 *   of the mini-map.
 *
 * Inherits all methods from: none
 */
namespace LuaAura
{
    /**
     * Returns the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
     *
     * @return [Unit] caster
     */
    int GetCaster(lua_State* L, Aura* aura)
    {
        Eluna::Push(L, aura->GetCaster());
        return 1;
    }

    /**
     * Returns the GUID of the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
     *
     * @return string caster_guid : the GUID of the Unit as a decimal string
     */
    int GetCasterGUID(lua_State* L, Aura* aura)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, aura->GetCasterGUID());
#else
        Eluna::Push(L, aura->GetCasterGuid());
#endif
        return 1;
    }

    /**
     * Returns the level of the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
     *
     * @return uint32 caster_level
     */
    int GetCasterLevel(lua_State* L, Aura* aura)
    {
#ifdef TRINITY
        Eluna::Push(L, aura->GetCaster()->GetLevel());
#else
        Eluna::Push(L, aura->GetCaster()->getLevel());
#endif
        return 1;
    }

    /**
     * Returns the amount of time left until the [Aura] expires.
     *
     * @return int32 duration : amount of time left in milliseconds
     */
    int GetDuration(lua_State* L, Aura* aura)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, aura->GetDuration());
#else
        Eluna::Push(L, aura->GetAuraDuration());
#endif
        return 1;
    }

    /**
     * Returns the ID of the [Spell] that caused this [Aura] to be applied.
     *
     * @return uint32 aura_id
     */
    int GetAuraId(lua_State* L, Aura* aura)
    {
        Eluna::Push(L, aura->GetId());
        return 1;
    }

    /**
     * Returns the amount of time this [Aura] lasts when applied.
     *
     * To determine how much time has passed since this Aura was applied,
     *   subtract the result of [Aura]:GetDuration from the result of this method.
     *
     * @return int32 max_duration : the maximum duration of the Aura, in milliseconds
     */
    int GetMaxDuration(lua_State* L, Aura* aura)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, aura->GetMaxDuration());
#else
        Eluna::Push(L, aura->GetAuraMaxDuration());
#endif
        return 1;
    }

    /**
     * Returns the number of times the [Aura] has "stacked".
     *
     * This is the same as the number displayed on the [Aura]'s icon in-game.
     *
     * @return uint32 stack_amount
     */
    int GetStackAmount(lua_State* L, Aura* aura)
    {
        Eluna::Push(L, aura->GetStackAmount());
        return 1;
    }

    /**
     * Returns the [Unit] that the [Aura] has been applied to.
     *
     * @return [Unit] owner
     */
    int GetOwner(lua_State* L, Aura* aura)
    {
#if defined TRINITY || defined AZEROTHCORE
        Eluna::Push(L, aura->GetOwner());
#else
        Eluna::Push(L, aura->GetTarget());
#endif
        return 1;
    }

    /**
     * Change the amount of time before the [Aura] expires.
     *
     * @param int32 duration : the new duration of the Aura, in milliseconds
     */
    int SetDuration(lua_State* L, Aura* aura)
    {
        int32 duration = Eluna::CHECKVAL<int32>(L, 2);
#if defined TRINITY || defined AZEROTHCORE
        aura->SetDuration(duration);
#else
        aura->GetHolder()->SetAuraDuration(duration);
#if (defined(TBC) || defined(CLASSIC))
        aura->GetHolder()->UpdateAuraDuration();
#else
        aura->GetHolder()->SendAuraUpdate(false);
#endif
#endif
        return 0;
    }

    /**
     * Change the maximum amount of time before the [Aura] expires.
     *
     * This does not affect the current duration of the [Aura], but if the [Aura]
     *   is reset to the maximum duration, it will instead change to `duration`.
     *
     * @param int32 duration : the new maximum duration of the Aura, in milliseconds
     */
    int SetMaxDuration(lua_State* L, Aura* aura)
    {
        int32 duration = Eluna::CHECKVAL<int32>(L, 2);
#if defined TRINITY || defined AZEROTHCORE
        aura->SetMaxDuration(duration);
#else
        aura->GetHolder()->SetAuraMaxDuration(duration);
#if (defined(TBC) || defined(CLASSIC))
        aura->GetHolder()->UpdateAuraDuration();
#else
        aura->GetHolder()->SendAuraUpdate(false);
#endif
#endif
        return 0;
    }

    /**
     * Change the amount of times the [Aura] has "stacked" on the [Unit].
     *
     * If `amount` is greater than or equal to the current number of stacks,
     *   then the [Aura] has its duration reset to the maximum duration.
     *
     * @param uint32 amount
     */
    int SetStackAmount(lua_State* L, Aura* aura)
    {
        uint8 amount = Eluna::CHECKVAL<uint8>(L, 2);
#if defined TRINITY || defined AZEROTHCORE
        aura->SetStackAmount(amount);
#else
        aura->GetHolder()->SetStackAmount(amount);
#endif
        return 0;
    }

    /**
     * Remove this [Aura] from the [Unit] it is applied to.
     */
    int Remove(lua_State* L, Aura* aura)
    {
#if defined TRINITY || defined AZEROTHCORE
        aura->Remove();
#else
        aura->GetTarget()->RemoveSpellAuraHolder(aura->GetHolder(), AURA_REMOVE_BY_CANCEL);
#endif
        Eluna::CHECKOBJ<ElunaObject>(L, 1)->Invalidate();
        return 0;
    }
};
#endif
