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

#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum WitchHuntData
{
    NPC_HELENA_GENTLE_HUMAN  = 124922,

    SPELL_TAKE_A_SEAT_CURSED = 248423
};

// EventID: 59332
class event_listen_to_helenas_story : public EventScript
{
public:
    event_listen_to_helenas_story() : EventScript("event_listen_to_helenas_story") {}

    void OnTrigger(WorldObject* /*object*/, WorldObject* invoker, uint32 /*eventId*/) override
    {
        if (Player* player = invoker->ToPlayer())
        {
            player->CastSpell(player, SPELL_TAKE_A_SEAT_CURSED);

            Creature* helenaObject = player->FindNearestCreatureWithOptions(25.0f, { .CreatureId = NPC_HELENA_GENTLE_HUMAN, .IgnorePhases = true });
            if (!helenaObject)
                return;

            helenaObject->SummonPersonalClone(helenaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

void AddSC_drustvar_chapter_1_the_final_effigy()
{
    // EventScripts
    new event_listen_to_helenas_story();
}
