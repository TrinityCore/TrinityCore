/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITY_COMBATAI_H
#define TRINITY_COMBATAI_H

#include "CreatureAI.h"

class Creature;

class TC_GAME_API AggressorAI : public CreatureAI
{
    public:
        using CreatureAI::CreatureAI;

        void UpdateAI(uint32) override;
        static int32 Permissible(Creature const* creature);
};

typedef std::vector<uint32> SpellVector;

class TC_GAME_API CombatAI : public CreatureAI
{
    public:
        using CreatureAI::CreatureAI;

        void InitializeAI() override;
        void Reset() override;
        void JustEngagedWith(Unit* who) override;
        void JustDied(Unit* killer) override;
        void UpdateAI(uint32 diff) override;
        void SpellInterrupted(uint32 spellId, uint32 unTimeMs) override;

        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    protected:
        EventMap _events;
        SpellVector _spells;
};

class TC_GAME_API CasterAI : public CombatAI
{
    public:
        explicit CasterAI(Creature* creature, uint32 scriptId = {}) : CombatAI(creature, scriptId) { _attackDistance = MELEE_RANGE; }
        void InitializeAI() override;
        void AttackStart(Unit* victim) override { AttackStartCaster(victim, _attackDistance); }
        void UpdateAI(uint32 diff) override;
        void JustEngagedWith(Unit* /*who*/) override;
    private:
        float _attackDistance;
};

struct TC_GAME_API ArcherAI : public CreatureAI
{
    public:
        explicit ArcherAI(Creature* creature, uint32 scriptId = {});
        void AttackStart(Unit* who) override;
        void UpdateAI(uint32 diff) override;

        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    protected:
        float _minimumRange;
};

struct TC_GAME_API TurretAI : public CreatureAI
{
    public:
        explicit TurretAI(Creature* creature, uint32 scriptId = {});
        bool CanAIAttack(Unit const* who) const override;
        void AttackStart(Unit* who) override;
        void UpdateAI(uint32 diff) override;

        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    protected:
        float _minimumRange;
};

#define VEHICLE_CONDITION_CHECK_TIME 1000
#define VEHICLE_DISMISS_TIME 5000

struct TC_GAME_API VehicleAI : public CreatureAI
{
    public:
        explicit VehicleAI(Creature* creature, uint32 scriptId = {});

        void UpdateAI(uint32 diff) override;
        void MoveInLineOfSight(Unit*) override { }
        void AttackStart(Unit*) override { }
        void OnCharmed(bool isNew) override;

        static int32 Permissible(Creature const* creature);

    private:
        void LoadConditions();
        void CheckConditions(uint32 diff);

        bool _hasConditions;
        uint32 _conditionsTimer;
        bool _dismiss;
        uint32 _dismissTimer;
};

#endif
