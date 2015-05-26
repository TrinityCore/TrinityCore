/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FunctionalFunctionalCreatureAI_h__
#define FunctionalFunctionalCreatureAI_h__

#include "FunctionalAIBase.h"
#include "CreatureAI.h"

struct OnEnterCombatEvent
{
    OnEnterCombatEvent(Unit const* _victim)
        : victim(_victim) { }

    Unit const* const victim;
};

struct OnJustDiedEvent
{
    OnJustDiedEvent(Unit const* _killer)
        : killer(_killer) { }

    Unit const* const killer;
};

struct OnSpellHitEvent
{
    OnSpellHitEvent(Unit const* _caster, SpellInfo const* _spell)
        : caster(_caster), spell(_spell) { }

    Unit const* const caster;

    SpellInfo const* const spell;
};

class FunctionalCreatureAI : public CreatureAI
{
public:
    explicit FunctionalCreatureAI(Creature* creature) : CreatureAI(creature) { }

    virtual ~FunctionalCreatureAI() { }

    // bool CanRespawn() { return true; }

    //void EnterEvadeMode() final override
    //{
    //}

    /////////////////////////////////
    // OnEnterCombatEvent
    DEFINE_HOOK(FunctionalCreatureAI, OnEnterCombatEvent)

    void EnterCombat(Unit* victim) final override;

    /////////////////////////////////
    // OnJustDiedEvent
    DEFINE_HOOK(FunctionalCreatureAI, OnJustDiedEvent)

    void JustDied(Unit* killer) final override;

    //void KilledUnit(Unit* /*victim*/) final override
    //{
    //}

    //void JustSummoned(Creature* /*summon*/) final override
    //{
    //}

    //void IsSummonedBy(Unit* /*summoner*/) final override
    //{
    //}

    //void SummonedCreatureDespawn(Creature* /*summon*/) final override
    //{
    //}

    //void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) final override
    //{
    //}

    DEFINE_HOOK(FunctionalCreatureAI, OnSpellHitEvent)

    void SpellHit(Unit* caster, SpellInfo const* spell) final override;

    //void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) final override
    //{
    //}

    //void AttackedBy(Unit* /*attacker*/) final override
    //{
    //}

    // bool IsEscorted() { return false; }

    // void JustRespawned() { Reset(); }

    //void MovementInform(uint32 /*type*/, uint32 /*id*/) final override
    //{
    //}

    //void OnCharmed(bool apply) final override
    //{
    //}

    //void JustReachedHome() final override
    //{
    //}

    //void ReceiveEmote(Player* /*player*/, uint32 /*emoteId*/) final override
    //{
    //}

    //void OwnerAttackedBy(Unit* /*attacker*/) final override
    //{
    //}

    //void OwnerAttacked(Unit* /*target*/) final override
    //{
    //}

    //void CorpseRemoved(uint32& /*respawnDelay*/) final override
    //{
    //}

    //void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool /*apply*/) final override
    //{
    //}

    //void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) final override
    //{
    //}

    // bool CanSeeAlways(WorldObject const* /*obj*/) { return false; }

protected:
    // void MoveInLineOfSight(Unit* /*who*/);
};

#endif // FunctionalFunctionalCreatureAI_h__
