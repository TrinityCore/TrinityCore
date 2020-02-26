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

#ifndef TRINITY_PASSIVEAI_H
#define TRINITY_PASSIVEAI_H

#include "CreatureAI.h"

class TC_GAME_API PassiveAI : public CreatureAI
{
    public:
        explicit PassiveAI(Creature* creature);

        void MoveInLineOfSight(Unit*) override { }
        void AttackStart(Unit*) override { }
        void UpdateAI(uint32) override;

        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }
};

class TC_GAME_API PossessedAI : public CreatureAI
{
    public:
        explicit PossessedAI(Creature* creature);

        void MoveInLineOfSight(Unit*) override { }
        void AttackStart(Unit* target) override;
        void JustEnteredCombat(Unit* who) override { EngagementStart(who); }
        void JustExitedCombat() override { EngagementOver(); }
        void JustStartedThreateningMe(Unit*) override { }
        void UpdateAI(uint32) override;
        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void JustDied(Unit*) override;
        void KilledUnit(Unit* victim) override;

        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }
};

class TC_GAME_API NullCreatureAI : public CreatureAI
{
    public:
        explicit NullCreatureAI(Creature* creature);

        void MoveInLineOfSight(Unit*) override { }
        void AttackStart(Unit*) override { }
        void JustStartedThreateningMe(Unit*) override { }
        void JustEnteredCombat(Unit*) override { }
        void UpdateAI(uint32) override { }
        void JustAppeared() override { }
        void EnterEvadeMode(EvadeReason /*why*/) override { }
        void OnCharmed(bool /*isNew*/) override { }

        static int32 Permissible(Creature const* creature);
};

class TC_GAME_API CritterAI : public PassiveAI
{
    public:
        explicit CritterAI(Creature* creature) : PassiveAI(creature) { }

        void DamageTaken(Unit* done_by, uint32& /*damage*/) override;
        void EnterEvadeMode(EvadeReason why) override;

        static int32 Permissible(Creature const* creature);
};

class TC_GAME_API TriggerAI : public NullCreatureAI
{
    public:
        explicit TriggerAI(Creature* creature) : NullCreatureAI(creature) { }
        void IsSummonedBy(WorldObject* summoner) override;

        static int32 Permissible(Creature const* creature);
};

#endif
