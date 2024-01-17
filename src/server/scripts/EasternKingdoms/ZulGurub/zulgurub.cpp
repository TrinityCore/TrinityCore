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

#include "zulgurub.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameEventMgr.h"

 /*######
 ## go_brazier_of_madness
 ######*/

enum EventGameIds
{
    EVENT_EDGE_OF_MADNESS_GRILEK = 27,
    EVENT_EDGE_OF_MADNESS_HAZZARAH = 28,
    EVENT_EDGE_OF_MADNESS_RENATAKI = 29,
    EVENT_EDGE_OF_MADNESS_WUSHOOLAY = 30
};

struct EventPair
{
    EventGameIds eventId;
    ZGCreatureIds npcEntry;
};

uint8 const MAX_EVENT_PAIRS = 4;
EventPair const EventPairs[MAX_EVENT_PAIRS] =
{
    { EVENT_EDGE_OF_MADNESS_GRILEK,     NPC_GRILEK      },
    { EVENT_EDGE_OF_MADNESS_HAZZARAH,   NPC_HAZZARAH    },
    { EVENT_EDGE_OF_MADNESS_RENATAKI,   NPC_RENATAKI    },
    { EVENT_EDGE_OF_MADNESS_WUSHOOLAY,  NPC_WUSHOOLAY   }
};

Position const MadnessSpawnPos = { -11901.229f, -1906.366f, 65.358f, 0.942f };

class go_brazier_of_madness : public GameObjectScript
{
public:
    go_brazier_of_madness() : GameObjectScript("go_brazier_of_madness") { }

    struct go_brazier_of_madnessAI : public GameObjectAI
    {
        go_brazier_of_madnessAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* /*player*/) override
        {
            uint32 bossEntry = 0;
            for (uint8 i = 0; i < MAX_EVENT_PAIRS; ++i)
            {
                if (sGameEventMgr->IsActiveEvent(EventPairs[i].eventId))
                {
                    bossEntry = EventPairs[i].npcEntry;
                    break;
                }
            }
            if (bossEntry)
                me->SummonCreature(bossEntry, MadnessSpawnPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2s * HOUR * IN_MILLISECONDS);
            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_brazier_of_madnessAI(go);
    }
};


void AddSC_zulgurub()
{
    new go_brazier_of_madness();
}
