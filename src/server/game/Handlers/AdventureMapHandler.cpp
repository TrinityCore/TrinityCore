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

void WorldSession::HandleCheckIsAdventureMapPoiValid(WorldPackets::AdventureMap::CheckIsAdventureMapPoiValid& poiValid)
{
    AdventureMapPOIEntry const* poiEntry = sAdventureMapPOIStore.LookupEntry(poiValid.ID);
    if (!poiEntry)
        return;

    bool active = true;
    if (poiEntry->PlayerConditionID)
        active = active && _player->MeetPlayerCondition(poiEntry->PlayerConditionID);

    switch (poiValid.ID)
    {
        case 1: // Alliance Only Bro!
        case 3: // Azsuna
        case 4: // Val'sharah
        case 6: // Stormheim
            if(_player->GetTeam() == ALLIANCE)
                active = true;
            break;
        case 7: // Stormheim
            if(_player->GetTeam() == HORDE)
                active = true;
            break;
        case 8: // Highmountain
        case 9: // Test quest offer
            if(_player->GetTeam() == HORDE)
                active = true;
            break;
        case 12: // worldport 1116, 6971.02, 1004.63, 398.974, 299.925 - Test for insets
        case 14: // Sanctum of Light
        case 15: // Demon Hunt: Wingterror Ikzil
        case 16: // Echoes of the Past
        case 17: // worldport 533, 2719.85, -3098.21, 267.686, 285.619 - Test for insets 2
        case 18: // worldport 0, 2368.83, -5353.17, 52.6645, 315.291   - Test for insets 3
        case 20: // Halls of Valor
        case 21: // Test Offer - Test
        case 22: // Acherus: The Ebon Hold
        case 23: // The Fel Hammer
        case 24: // Trueshot Lodge
        case 25: // The Dreamgrove
        case 26: // Hall of the Guardian
        case 27: // The Wandering Isle
        case 28: // Netherlight Temple
        case 29: // The Halls of Shadows
        case 30: // The Maelstrom
        case 31: // Dreadscar Rift
        case 32: // Suramar
        case 40: // Zuldazar
            if(_player->GetTeam() == HORDE)
                active = true;
            break;
        case 41: // Nazmir
            if(_player->GetTeam() == HORDE)
                active = true;
            break;
        case 42: // Vol'dun
            if(_player->GetTeam() == HORDE)
                active = true;
            break;
        case 43: // Tiragarde Sound
            if(_player->GetTeam() == ALLIANCE)
                active = true;
            break;
        case 44: // Drustvar
            if(_player->GetTeam() == ALLIANCE)
                active = true;
            break;
        case 45: // Stormsong Valley
            if(_player->GetTeam() == ALLIANCE)
                active = true;
            break;
        case 148: // Tiragarde Sound
        case 149: // Drustvar
        case 150: // Stormsong Valley
        case 151: // Zuldazar
        case 152: // Nazmir
        case 153: // Vol'dun
        case 161: // Skoldus Hall
        case 162: // Fracture Chambers
        case 163: // The Soulforges
        case 164: // Deadsoul Interstitia
        case 165: // Kakophonus
        case 166: // Miscreation Wing
        case 167: // Darkness' Domain
        case 168: // Sineater Belfry
        case 169: // The Upper Reaches
        case 171: // The Winding Halls
        case 172: // Bastion
        case 173: // Maldraxxus
        case 174: // Ardenweald
        case 175: // Revendreth
        case 176: // Torghast
        case 177: // Battlegrounds
        default:
            break;
    }

    if (poiEntry->QuestID)
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(poiEntry->QuestID))
            active = active && _player->CanTakeQuest(quest, false);

    WorldPackets::AdventureMap::PlayerIsAdventureMapPoiValid result;
    result.ID = poiValid.ID;
    result.Active = active;
    SendPacket(result.Write());
}
