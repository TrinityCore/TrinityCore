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

#include <atomic>
#include <deque>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "ObjectGuid.h"

#include "GenAI_chat_prompts.h"
#include "GenAI_chat_memory.h"

class FSBNpcChatMgr
{
public:
    static FSBNpcChatMgr* Get();

    struct PendingNpcReply
    {
        std::atomic<bool> ready{ false };
        std::mutex mutex;

        std::string reply;
        uint8 questState = 0;
        uint32 questId = 0;

        ObjectGuid npcGuid;
        ObjectGuid playerGuid;
        std::string playerName;
        uint32 deliverAfter = 0;
    };

    void AddPendingReply(ObjectGuid npcGuid, ObjectGuid playerGuid, std::string const& playerName,
        FSBNpcPrompts::NpcChatContext const& ctx, FSBNpcPrompts::PlayerSnapshot const& playerSnap,
        std::string const& playerMsg, std::deque<BotChatMemoryEntry> const& memory);

    void Update(uint32 diff);

private:
    std::vector<std::shared_ptr<PendingNpcReply>> _pendingReplies;
    std::mutex _pendingMutex;
};
