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
#include "AdventureJournalPackets.h"
#include "DB2Stores.h"
#include "GossipDef.h"
#include "ObjectMgr.h"
#include "Player.h"

void WorldSession::HandleAdventureJournalOpenQuest(WorldPackets::AdventureJournal::AdventureJournalOpenQuest& openQuest)
{
    if (ChrClassUIDisplayEntry const* uiDisplay = sDB2Manager.GetUiDisplayForClass(Classes(_player->getClass())))
        if (!_player->MeetPlayerCondition(uiDisplay->AdvGuidePlayerConditionID))
            return;

    AdventureJournalEntry const* adventureJournal = sAdventureJournalStore.LookupEntry(openQuest.AdventureJournalID);
    if (!adventureJournal)
        return;

    if (!_player->MeetPlayerCondition(adventureJournal->PlayerConditionID))
        return;

    Quest const* quest = sObjectMgr->GetQuestTemplate(adventureJournal->QuestID);
    if (!quest)
        return;

    if (_player->CanTakeQuest(quest, true))
        _player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, _player->GetGUID(), true, false);
}

void WorldSession::HandleAdventureJournalUpdateSuggestions(WorldPackets::AdventureJournal::AdventureJournalUpdateSuggestions& updateSuggestions)
{
    if (ChrClassUIDisplayEntry const* uiDisplay = sDB2Manager.GetUiDisplayForClass(Classes(_player->getClass())))
        if (!_player->MeetPlayerCondition(uiDisplay->AdvGuidePlayerConditionID))
            return;

    WorldPackets::AdventureJournal::AdventureJournalDataResponse response;
    response.OnLevelUp = updateSuggestions.OnLevelUp;

    for (AdventureJournalEntry const* adventureJournal : sAdventureJournalStore)
    {
        if (_player->MeetPlayerCondition(adventureJournal->PlayerConditionID))
        {
            WorldPackets::AdventureJournal::AdventureJournalEntry adventureJournalData;
            adventureJournalData.AdventureJournalID = int32(adventureJournal->ID);
            adventureJournalData.Priority = int32(adventureJournal->PriorityMax);
            response.Entries.push_back(adventureJournalData);
        }
    }

    SendPacket(response.Write());
}
