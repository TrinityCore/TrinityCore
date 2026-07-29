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

#include <deque>
#include <string>

class Creature;
class Player;

#include "GenAI_chat_memory.h"

namespace FSBNpcPrompts
{
    struct NpcChatContext
    {
        uint32 entry = 0;
        std::string npcName;
        std::string subName;
        uint32 zoneId = 0;
        uint32 areaId = 0;
        bool hasQuest = false;
        uint8 questState = 0;
        uint32 questId = 0;
        std::string questTitle;
        std::string questDescription;
        std::string inGameTime;
        std::string weather;
    };

    struct BotChatResponse
    {
        std::string reply;
        std::string action = "none";
        uint32 amount = 0;
        uint8 questState = 0;
    };

    struct PlayerSnapshot
    {
        std::string name;
        uint8 race = 0;
        uint8 playerClass = 0;
        uint32 level = 0;
    };

    BotChatResponse GenerateNpcReply(NpcChatContext const& ctx, PlayerSnapshot const& player, std::string const& playerMsg,
        std::deque<BotChatMemoryEntry> const& memory);

    NpcChatContext BuildNpcContext(Creature* npc, Player* player);
    PlayerSnapshot BuildPlayerSnapshot(Player* player);
}
