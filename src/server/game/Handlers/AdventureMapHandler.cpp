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

#include "WorldSession.h"
#include "AdventureMapPackets.h"
#include "DB2Stores.h"
#include "ObjectMgr.h"
#include "Player.h"

void WorldSession::HandleAdventureMapStartQuest(WorldPackets::AdventureMap::AdventureMapStartQuest& startQuest)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(startQuest.QuestID);
    if (!quest)
        return;

    auto itr = std::find_if(sAdventureMapPOIStore.begin(), sAdventureMapPOIStore.end(), [&](AdventureMapPOIEntry const* adventureMap)
    {
        return adventureMap->QuestID == uint32(startQuest.QuestID) && _player->MeetPlayerCondition(adventureMap->PlayerConditionID);
    });

    if (itr == sAdventureMapPOIStore.end())
        return;

    if (_player->CanTakeQuest(quest, true))
        _player->AddQuestAndCheckCompletion(quest, _player);
}
