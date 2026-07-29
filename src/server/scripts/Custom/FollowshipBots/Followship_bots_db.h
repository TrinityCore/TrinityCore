/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>

#include "Player.h"
#include "Creature.h"

#include "Followship_bots_defines.h"
#include "Followship_bots_spells_handler.h"

namespace FSBUtilsDB
{
    bool LoadAllPersistentBotsFromDB(std::vector<PlayerBotData>& outBots);

    bool LoadBotOwners(std::unordered_map<ObjectGuid::LowType, ObjectGuid::LowType>& botOwners);
    bool LoadBotsForPlayer(uint64 playerGuidLow, std::vector<PlayerBotData>& outBots);
    
    bool SaveBotToDB(Creature* bot, Player* player, uint64 hireExpiry);
    bool DeleteBotByEntry(uint32 bot_entry, uint32 player_guid);    

    bool LoadBotChatterLines(std::unordered_map<uint32, std::vector<FSBChatterDBLine>>& outMap);
    bool LoadBotSpellsFromDB(std::vector<FSBSpellDefinition>& outSpells);
}
