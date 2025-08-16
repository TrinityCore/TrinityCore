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

#include "GameObject.h"
#include "GameObjectAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"

// 233664 - Master Surveyor
enum MasterSurveyorMisc
{
    // Quest
    QUEST_ESTABLISH_YOUR_GARRISON_HORDE              = 34378,

    // Spells
    SPELL_QUEST_34378_KILLCREDIT                     = 161033,
    SPELL_CREATE_GARRISON_FROSTFIRE_RIDGE_HORDE      = 160767
};

Position const GarrisonLevelOneCreationPlayerPosition = { 5568.66f, 4635.45f, 146.61f, 5.079972743988037109f };

// 233664 - Master Surveyor
struct go_master_surveyor : public GameObjectAI
{
    go_master_surveyor(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* player) override
    {
        if (player->GetQuestStatus(QUEST_ESTABLISH_YOUR_GARRISON_HORDE) == QUEST_STATUS_INCOMPLETE)
        {
            me->UseDoorOrButton();
            player->CastSpell(player, SPELL_QUEST_34378_KILLCREDIT, true);
            player->CastSpell(player, SPELL_CREATE_GARRISON_FROSTFIRE_RIDGE_HORDE, true);
            player->NearTeleportTo(GarrisonLevelOneCreationPlayerPosition);
            PhasingHandler::OnConditionChange(player);

            return true;
        }

        return false;
    }
};

void AddSC_frostfire_ridge()
{
    RegisterGameObjectAI(go_master_surveyor);
};
