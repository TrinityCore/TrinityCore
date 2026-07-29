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
#include <shared_mutex>
#include <unordered_map>

#include "Common.h"
#include "ObjectGuid.h"

#include "GenAI_chat_memory.h"

class GenAINpcMemoryMgr
{
public:
    static GenAINpcMemoryMgr* Get();

    void AddEntry(ObjectGuid npcGuid, uint32 channelId, std::string const& sender, std::string const& msg, bool isPlayer);
    std::deque<BotChatMemoryEntry> GetMemory(ObjectGuid npcGuid) const;
    void ClearMemory(ObjectGuid npcGuid);
    void RemoveIfUnused(ObjectGuid npcGuid);

    uint8 GetQuestState(ObjectGuid npcGuid) const;
    void SetQuestState(ObjectGuid npcGuid, uint8 state);

private:
    std::unordered_map<ObjectGuid, std::deque<BotChatMemoryEntry>> _memories;
    std::unordered_map<ObjectGuid, uint8> _questStates;
    mutable std::shared_mutex _mutex;
};
