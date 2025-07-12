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

#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum CallOfTheUncrownedATData
{
    QUEST_CALL_OF_THE_UNCROWNED     = 40832,

    NPC_MILTON_BEATS_ORDERHALL      = 105908
};

// XXX - Areatrigger
struct at_hall_of_shadows_call_of_the_uncrowned_clone_milton : AreaTriggerAI
{
    at_hall_of_shadows_call_of_the_uncrowned_clone_milton(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_CALL_OF_THE_UNCROWNED) != QUEST_STATUS_INCOMPLETE)
            return;

        Creature* miltonObject = GetClosestCreatureWithOptions(player, 30.0f, { .CreatureId = NPC_MILTON_BEATS_ORDERHALL, .IgnorePhases = true });
        if (!miltonObject)
            return;

        TempSummon* miltonClone = miltonObject->SummonPersonalClone(miltonObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        if (!miltonClone)
            return;
    }
};

void AddSC_orderhall_rogue()
{
    // Areatrigger
    RegisterAreaTriggerAI(at_hall_of_shadows_call_of_the_uncrowned_clone_milton);
}
