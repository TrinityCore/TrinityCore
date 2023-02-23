/*
 * Copyright 2023 AzgathCore
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CombatAI.h"
#include "GameObjectAI.h"
#include "Scenario.h"
#include "ScriptMgr.h"
#include "uncharted_island.h"
#include "LFGMgr.h"
#include "WorldSession.h"
#include "World.h"
#include "AzeriteItem.h"
#include "Object.h"

class npc_expedition_map : public CreatureScript
{
public:
    npc_expedition_map() : CreatureScript("npc_expedition_map") { }

    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/)
    {
        return false;
    }

    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*uiSender*/, uint32 /*uiAction*/)
    {
        
    }
};

class go_pouch_of_azerite : public GameObjectScript
{
public:
    go_pouch_of_azerite() : GameObjectScript("go_pouch_of_azerite") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (Item* item = player->GetItemByEntry(158075)) // Heart of Azeroth
            item->ToAzeriteItem()->GiveXP(50);
        return false;
    }
};

class go_azerite_crystal : public GameObjectScript
{
public:
    go_azerite_crystal() : GameObjectScript("go_azerite_crystal") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (Item* item = player->GetItemByEntry(158075)) // Heart of Azeroth
            item->ToAzeriteItem()->GiveXP(75);
            
        if (Scenario* scenario = player->GetScenario())
        {
            if (scenario->GetStep() == sScenarioStepStore.LookupEntry(STEP_INVESTIGATE))
            {
                scenario->CompleteStep(sScenarioStepStore.LookupEntry(STEP_INVESTIGATE));
                scenario->SetStep(sScenarioStepStore.LookupEntry(STEP_MINE));
            }
        }

        return false;
    }
};

void AddSC_uncharted_island_tutorial()
{
    
}
