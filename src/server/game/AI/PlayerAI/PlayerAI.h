/*
 * Copyright (C) 2016-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_PLAYERAI_H
#define TRINITY_PLAYERAI_H

#include "UnitAI.h"
#include "Player.h"
#include "Spell.h"
#include "Creature.h"

class TC_GAME_API PlayerAI : public UnitAI
{
    public:
        explicit PlayerAI(Player* player) : UnitAI(static_cast<Unit*>(player)), me(player), _selfSpec(PlayerAI::GetPlayerSpec(player)), _isSelfHealer(PlayerAI::IsPlayerHealer(player)), _isSelfRangedAttacker(PlayerAI::IsPlayerRangedAttacker(player)) { }

        void OnCharmed(bool /*apply*/) override { } // charm AI application for players is handled by Unit::SetCharmedBy / Unit::RemoveCharmedBy

        // helper functions to determine player info
        // Return values range from 0 (left-most spec) to 2 (right-most spec). If two specs have the same number of talent points, the left-most of those specs is returned.
        static uint8 GetPlayerSpec(Player const* who);
        // Return values range from 0 (left-most spec) to 2 (right-most spec). If two specs have the same number of talent points, the left-most of those specs is returned.
        uint8 GetSpec(Player const* who = nullptr) const { return (!who || who == me) ? _selfSpec : GetPlayerSpec(who); }
        static bool IsPlayerHealer(Player const* who);
        bool IsHealer(Player const* who = nullptr) const { return (!who || who == me) ? _isSelfHealer : IsPlayerHealer(who); }
        static bool IsPlayerRangedAttacker(Player const* who);
        bool IsRangedAttacker(Player const* who = nullptr) const { return (!who || who == me) ? _isSelfRangedAttacker : IsPlayerRangedAttacker(who); }

    protected:
        struct TargetedSpell : public std::pair<Spell*, Unit*>
        {
            TargetedSpell() : pair<Spell*, Unit*>() { }
            TargetedSpell(Spell* first, Unit* second) : pair<Spell*, Unit*>(first, second) { }
            explicit operator bool() { return !!first; }
        };
        typedef std::pair<TargetedSpell, uint32> PossibleSpell;
        typedef std::vector<PossibleSpell> PossibleSpellVector;

        Player* const me;
        void SetIsRangedAttacker(bool state) { _isSelfRangedAttacker = state; } // this allows overriding of the default ranged attacker detection

        enum SpellTarget
        {
            TARGET_NONE,
            TARGET_VICTIM,
            TARGET_CHARMER,
            TARGET_SELF
        };
        /* Check if the specified spell can be cast on that target.
           Caller is responsible for cleaning up created Spell object from pointer. */
        TargetedSpell VerifySpellCast(uint32 spellId, Unit* target);
        /* Check if the specified spell can be cast on that target.
        Caller is responsible for cleaning up created Spell object from pointer. */
        TargetedSpell VerifySpellCast(uint32 spellId, SpellTarget target);

        /* Helper method - checks spell cast, then pushes it onto provided vector if valid. */
        template<typename T> inline void VerifyAndPushSpellCast(PossibleSpellVector& spells, uint32 spellId, T target, uint32 weight)
        {
            if (TargetedSpell spell = VerifySpellCast(spellId, target))
                spells.push_back({ spell,weight });
        }

        /* Helper method - selects one spell from the vector and returns it, while deleting everything else.
           This invalidates the vector, and empties it to prevent accidental misuse. */
        TargetedSpell SelectSpellCast(PossibleSpellVector& spells);
        /* Helper method - casts the included spell at the included target */
        inline void DoCastAtTarget(TargetedSpell spell)
        {
            SpellCastTargets targets;
            targets.SetUnitTarget(spell.second);
            spell.first->prepare(&targets);
        }

        virtual Unit* SelectAttackTarget() const { return me->GetCharmer() ? me->GetCharmer()->GetVictim() : nullptr; }
        void DoRangedAttackIfReady();
        void DoAutoAttackIfReady();

        // Cancels all shapeshifts that the player could voluntarily cancel
        void CancelAllShapeshifts();

    private:
        uint8 const _selfSpec;
        bool const _isSelfHealer;
        bool _isSelfRangedAttacker;
};

class SimpleCharmedPlayerAI : public PlayerAI
{
    public:
        SimpleCharmedPlayerAI(Player* player) : PlayerAI(player), _castCheckTimer(500), _chaseCloser(false), _forceFacing(true) { }
        void UpdateAI(uint32 diff) override;
        void OnCharmed(bool apply) override;

    protected:
        Unit* SelectAttackTarget() const override;

    private:
        TargetedSpell SelectAppropriateCastForSpec();
        uint32 _castCheckTimer;
        bool _chaseCloser;
        bool _forceFacing;
};

#endif
