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

#include "Followship_bots_npc_chat_manager.h"

#include <mutex>
#include <thread>

#include "Creature.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "Random.h"
#include "SharedDefines.h"
#include "Timer.h"

#include "Followship_bots_config.h"
#include "GenAI_npc_memory.h"

FSBNpcChatMgr* FSBNpcChatMgr::Get()
{
    static FSBNpcChatMgr instance;
    return &instance;
}

void FSBNpcChatMgr::AddPendingReply(ObjectGuid npcGuid, ObjectGuid playerGuid, std::string const& playerName,
    FSBNpcPrompts::NpcChatContext const& ctx, FSBNpcPrompts::PlayerSnapshot const& playerSnap,
    std::string const& playerMsg, std::deque<BotChatMemoryEntry> const& memory)
{
    auto state = std::make_shared<PendingNpcReply>();
    state->npcGuid = npcGuid;
    state->playerGuid = playerGuid;
    state->playerName = playerName;
    state->questId = ctx.questId;

    std::thread([state, ctx, playerSnap, playerMsg, memory]() mutable
    {
        try
        {
            FSBNpcPrompts::BotChatResponse resp =
                FSBNpcPrompts::GenerateNpcReply(ctx, playerSnap, playerMsg, memory);

            {
                std::lock_guard<std::mutex> lock(state->mutex);
                state->reply = std::move(resp.reply);
                state->questState = resp.questState;
            }
        }
        catch (...)
        {
            // Silently drop LLM failures
        }
        state->ready.store(true, std::memory_order_release);
    }).detach();

    {
        std::lock_guard<std::mutex> lock(_pendingMutex);
        _pendingReplies.push_back(std::move(state));
    }
}

void FSBNpcChatMgr::Update(uint32 /*diff*/)
{
    uint32 now = getMSTime();

    std::vector<std::shared_ptr<PendingNpcReply>> readyReplies;
    {
        std::lock_guard<std::mutex> lock(_pendingMutex);
        for (auto it = _pendingReplies.begin(); it != _pendingReplies.end(); )
        {
            auto& state = *it;

            if (!state->ready.load(std::memory_order_acquire))
            {
                ++it;
                continue;
            }

            if (state->deliverAfter == 0)
                state->deliverAfter = now + urand(2000, 5000);

            if (now < state->deliverAfter)
            {
                ++it;
                continue;
            }

            readyReplies.push_back(std::move(state));
            it = _pendingReplies.erase(it);
        }
    }

    for (auto& state : readyReplies)
    {
        std::string reply;
        uint8 questState = 0;
        {
            std::lock_guard<std::mutex> lock(state->mutex);
            reply = std::move(state->reply);
            questState = state->questState;
        }

        if (reply.empty())
            continue;

        Player* player = ObjectAccessor::FindPlayer(state->playerGuid);
        if (!player)
            continue;

        Creature* npc = ObjectAccessor::GetCreature(*player, state->npcGuid);
        if (!npc || !npc->IsInWorld() || !npc->IsAlive())
            continue;

        npc->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
        npc->Say(reply, LANG_UNIVERSAL, player);

        GenAINpcMemoryMgr::Get()->AddEntry(state->npcGuid, CHAT_MSG_SAY, npc->GetName(), reply, false);
        GenAINpcMemoryMgr::Get()->SetQuestState(state->npcGuid, questState);

        if (questState == 3 && state->questId != 0)
        {
            if (!FollowshipBotsConfig::configFSBGenAIAutoStartQuest)
            {
                TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: quest state 3 reached for quest {} but AutoStartQuestFromChat is disabled", state->questId);
            }
            else
            {
                Quest const* quest = sObjectMgr->GetQuestTemplate(state->questId);
                if (!quest)
                    TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: quest template {} not found", state->questId);
                else if (!player->CanTakeQuest(quest, false))
                    TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: player cannot take quest {}", state->questId);
                else if (!player->CanAddQuest(quest, false))
                    TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: player cannot add quest {} (quest log full?)", state->questId);
                else
                {
                    player->AddQuestAndCheckCompletion(quest, npc);
                    GenAINpcMemoryMgr::Get()->SetQuestState(state->npcGuid, 0);
                    TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: quest {} auto-started for player {}", state->questId, player->GetName());
                }
            }
        }
    }
}

