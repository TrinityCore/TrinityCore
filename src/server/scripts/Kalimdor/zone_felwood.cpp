/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Felwood
SD%Complete: 95
SDComment: Quest support: 7632
SDCategory: Felwood
EndScriptData */

/* ContentData
at_ancient_leaf
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*######
## at_ancient_leaf
######*/

enum AncientMisc
{
    QUEST_ANCIENT_LEAF      = 7632,
    NPC_VARTRUS             = 14524,
    NPC_STOMA               = 14525,
    NPC_HASTAT              = 14526,
    CREATURE_GROUP_ANCIENTS = 1
};

class at_ancient_leaf : public AreaTriggerScript
{
    public:
        at_ancient_leaf() : AreaTriggerScript("at_ancient_leaf") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
        {
            if (player->IsGameMaster() || !player->IsAlive())
                return false;

            // Handle Call Ancients event start - The area trigger summons 3 ancients
            if ((player->GetQuestStatus(QUEST_ANCIENT_LEAF) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_ANCIENT_LEAF) == QUEST_STATUS_REWARDED))
            {
                // If ancients are already spawned, skip the rest
                if (GetClosestCreatureWithEntry(player, NPC_VARTRUS, 50.0f) || GetClosestCreatureWithEntry(player, NPC_STOMA, 50.0f) || GetClosestCreatureWithEntry(player, NPC_HASTAT, 50.0f))
                    return true;

                player->GetMap()->SummonCreatureGroup(CREATURE_GROUP_ANCIENTS);
            }
            return false;
        }
};

void AddSC_felwood()
{
    new at_ancient_leaf();
}
