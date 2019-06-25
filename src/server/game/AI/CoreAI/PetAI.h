/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_PETAI_H
#define TRINITY_PETAI_H

#include "CreatureAI.h"
#include "Timer.h"

class Creature;
class Spell;

typedef std::vector<std::pair<Unit*, Spell*>> TargetSpellList;

class TC_GAME_API PetAI : public CreatureAI
{
    public:
        static int32 Permissible(Creature const* creature);

        explicit PetAI(Creature* creature);

        void UpdateAI(uint32) override;
        void KilledUnit(Unit* /*victim*/) override;
        // only start attacking if not attacking something else already
        void AttackStart(Unit* target) override;
        // always start attacking if possible
        void _AttackStart(Unit* target);
        void MovementInform(uint32 type, uint32 id) override;
        void OwnerAttackedBy(Unit* attacker) override;
        void OwnerAttacked(Unit* target) override;
        void DamageTaken(Unit* attacker, uint32& /*damage*/) override { AttackStart(attacker); }
        void ReceiveEmote(Player* player, uint32 textEmote) override;

        // The following aren't used by the PetAI but need to be defined to override
        // default CreatureAI functions which interfere with the PetAI

        void MoveInLineOfSight(Unit* /*who*/) override { } // CreatureAI interferes with returning pets
        void MoveInLineOfSight_Safe(Unit* /*who*/) { } // CreatureAI interferes with returning pets
        void JustAppeared() override { } // we will control following manually
        void EnterEvadeMode(EvadeReason /*why*/) override { } // For fleeing, pets don't use this type of Evade mechanic

    private:
        bool NeedToStop();
        void StopAttack();
        void UpdateAllies();
        Unit* SelectNextTarget(bool allowAutoSelect) const;
        void HandleReturnMovement();
        void DoAttack(Unit* target, bool chase);
        bool CanAttack(Unit* target);
        // Quick access to set all flags to FALSE
        void ClearCharmInfoFlags();

        TimeTracker _tracker;
        GuidSet _allySet;
        uint32 _updateAlliesTimer;
};

#endif
