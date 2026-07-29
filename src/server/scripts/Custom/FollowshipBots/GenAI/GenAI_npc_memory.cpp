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

#include "GenAI_npc_memory.h"

#include <mutex>

#include "Followship_bots_config.h"
#include "Timer.h"

GenAINpcMemoryMgr* GenAINpcMemoryMgr::Get()
{
    static GenAINpcMemoryMgr instance;
    return &instance;
}

void GenAINpcMemoryMgr::AddEntry(ObjectGuid npcGuid, uint32 channelId, std::string const& sender, std::string const& msg, bool isPlayer)
{
    BotChatMemoryEntry entry;
    entry.channelId = channelId;
    entry.senderName = sender;
    entry.message = msg;
    entry.isPlayer = isPlayer;
    entry.timestamp = getMSTime();

    std::unique_lock<std::shared_mutex> lock(_mutex);
    auto& memory = _memories[npcGuid];
    memory.push_back(std::move(entry));

    uint32 maxSize = FollowshipBotsConfig::configFSBBotChatMemorySize;
    if (maxSize < 1)
        maxSize = 10;

    while (memory.size() > maxSize)
        memory.pop_front();
}

std::deque<BotChatMemoryEntry> GenAINpcMemoryMgr::GetMemory(ObjectGuid npcGuid) const
{
    std::shared_lock<std::shared_mutex> lock(_mutex);
    auto it = _memories.find(npcGuid);
    if (it != _memories.end())
        return it->second;

    return {};
}

void GenAINpcMemoryMgr::ClearMemory(ObjectGuid npcGuid)
{
    std::unique_lock<std::shared_mutex> lock(_mutex);
    auto it = _memories.find(npcGuid);
    if (it != _memories.end())
        it->second.clear();
}

void GenAINpcMemoryMgr::RemoveIfUnused(ObjectGuid npcGuid)
{
    std::unique_lock<std::shared_mutex> lock(_mutex);
    auto it = _memories.find(npcGuid);
    if (it != _memories.end() && it->second.empty())
        _memories.erase(it);
}

uint8 GenAINpcMemoryMgr::GetQuestState(ObjectGuid npcGuid) const
{
    std::shared_lock<std::shared_mutex> lock(_mutex);
    auto it = _questStates.find(npcGuid);
    if (it != _questStates.end())
        return it->second;
    return 0;
}

void GenAINpcMemoryMgr::SetQuestState(ObjectGuid npcGuid, uint8 state)
{
    std::unique_lock<std::shared_mutex> lock(_mutex);
    _questStates[npcGuid] = state;
}
