/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "CreatureAIImpl.h"
#include "ConditionMgr.h"

class Creature;

class AggressorAI : public CreatureAI
{
    public:
        explicit AggressorAI(Creature* c) : CreatureAI(c) { }

        void UpdateAI(uint32) override;
        static int Permissible(const Creature*);
};

typedef std::vector<uint32> SpellVct;

class CombatAI : public CreatureAI
{
    public:
        explicit CombatAI(Creature* c) : CreatureAI(c) { }

        void InitializeAI() override;
        void Reset() override;
        void EnterCombat(Unit* who) override;
        void JustDied(Unit* killer) override;
        void UpdateAI(uint32 diff) override;
        void SpellInterrupted(uint32 spellId, uint32 unTimeMs) override;

        static int Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    protected:
        EventMap events;
        SpellVct spells;
};

class CasterAI : public CombatAI
{
    public:
        explicit CasterAI(Creature* c) : CombatAI(c) { m_attackDist = MELEE_RANGE; }
        void InitializeAI() override;
        void AttackStart(Unit* victim) override { AttackStartCaster(victim, m_attackDist); }
        void UpdateAI(uint32 diff) override;
        void EnterCombat(Unit* /*who*/) override;
    private:
        float m_attackDist;
};

struct ArcherAI : public CreatureAI
{
    public:
        explicit ArcherAI(Creature* c);
        void AttackStart(Unit* who) override;
        void UpdateAI(uint32 diff) override;

        static int Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    protected:
        float m_minRange;
};

struct TurretAI : public CreatureAI
{
    public:
        explicit TurretAI(Creature* c);
        bool CanAIAttack(Unit const* who) const override;
        void AttackStart(Unit* who) override;
        void UpdateAI(uint32 diff) override;

        static int Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    protected:
        float m_minRange;
};

#define VEHICLE_CONDITION_CHECK_TIME 1000
#define VEHICLE_DISMISS_TIME 5000

struct VehicleAI : public CreatureAI
{
    public:
        explicit VehicleAI(Creature* creature);

        void UpdateAI(uint32 diff) override;
        void MoveInLineOfSight(Unit*) override { }
        void AttackStart(Unit*) override { }
        void OnCharmed(bool apply) override;

        static int Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

    private:
        void LoadConditions();
        void CheckConditions(uint32 diff);
        ConditionList conditions;
        uint32 m_ConditionsTimer;
        bool m_DoDismiss;
        uint32 m_DismissTimer;
};

#endif
