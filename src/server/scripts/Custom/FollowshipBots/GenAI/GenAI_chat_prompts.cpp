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

#include "GenAI_chat_prompts.h"

#include "Creature.h"
#include "GenAI_client.h"
#include "Followship_bots_config.h"
#include "GameTime.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "Weather.h"
#include "WowTime.h"

#include "DB2Stores.h"
#include "Log.h"

#include "Followship_bots_utils.h"

#include "GenAI_npc_memory.h"

namespace FSBNpcPrompts
{
    BotChatResponse GenerateNpcReply(NpcChatContext const& ctx, PlayerSnapshot const& player, std::string const& playerMsg,
        std::deque<BotChatMemoryEntry> const& memory)
    {
        BotChatResponse result;
        if (!ctx.entry || playerMsg.empty())
            return result;

        AreaTableEntry const* zone = sAreaTableStore.LookupEntry(ctx.zoneId);
        std::string zoneName = zone ? zone->AreaName[LOCALE_enUS] : "Unknown";

        AreaTableEntry const* area = sAreaTableStore.LookupEntry(ctx.areaId);
        std::string areaName = area ? area->AreaName[LOCALE_enUS] : zoneName;

        std::string systemPrompt =
            "You are a World of Warcraft NPC named " + ctx.npcName + ".\n";

        if (!ctx.subName.empty())
            systemPrompt += "You are also known as: " + ctx.subName + ".\n";

        systemPrompt +=
            "You currently reside in " + areaName + ", " + zoneName + ".\n";

        if (!ctx.inGameTime.empty())
            systemPrompt += "The current in-game time is " + ctx.inGameTime + ".\n";

        if (!ctx.weather.empty())
            systemPrompt += "The weather here is currently " + ctx.weather + ".\n";

        systemPrompt +=
            "A player is speaking to you directly. You are a normal inhabitant of this world.\n"
            "Never mention being an AI, bot, or NPC.\n"
            "Do not use quotation marks inside your reply.\n";

        if (!player.name.empty())
        {
            std::string playerRaceStr = "Unknown";
            if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(player.race))
                playerRaceStr = raceEntry->Name[LOCALE_enUS];

            std::string playerClassStr = "Unknown";
            if (ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(player.playerClass))
                playerClassStr = classEntry->Name[LOCALE_enUS];

            systemPrompt +=
                "The player speaking to you is " + player.name + ", a " +
                playerRaceStr + " " + playerClassStr + " of level " +
                std::to_string(player.level) + ".\n";
        }

        systemPrompt += "\nConversation History:\n";
        for (auto const& entry : memory)
            systemPrompt += entry.senderName + ": " + entry.message + "\n";

        if (ctx.hasQuest && ctx.questState > 0)
        {
            systemPrompt +=
                "\nPRIVATE QUEST CONTEXT:\n"
                "- quest_title: \"" + ctx.questTitle + "\"\n"
                "- quest_description: \"" + ctx.questDescription + "\"\n"
                "- current_quest_state: " + std::to_string(ctx.questState) + "\n"
                "\nSTATE INSTRUCTIONS:\n"
                "- State 1 (quest available): You have a task but have NOT told the player yet. Do NOT mention it unless the player explicitly offers help, asks what you need, or asks if something is wrong. If they do, describe the task naturally in 2-3 sentences and set questState to 2.\n"
                "- State 2 (quest offered): You have already told the player about your task. Answer their follow-up questions about it naturally. If the player agrees or accepts, set questState to 3.\n"
                "- State 3 (quest accepted): The player has agreed to help. Thank them briefly. Do not repeat the task details.\n"
                "\nYou MUST respond ONLY in valid JSON with exactly these fields:\n"
                "- \"questState\": the new state (1, 2, or 3) based on the player's latest message.\n"
                "- \"reply\": a short in-character reply, natural and conversational, NO quotation marks inside.\n"
                "Do not repeat or closely paraphrase any reply from the conversation history.\n";
        }
        else
        {
            systemPrompt +=
                "\nYou MUST respond ONLY in valid JSON with exactly these fields:\n"
                "- \"questState\": always 0.\n"
                "- \"reply\": a short in-character reply, natural and conversational, NO quotation marks inside.\n"
                "Do not repeat or closely paraphrase any reply from the conversation history.\n";
        }

        std::string userPrompt = playerMsg;

        if (FollowshipBotsConfig::configFSBGenAIEnabled)
        {
            std::string aiResponse = FSBGenAI::GetStructuredBotResponse(systemPrompt, userPrompt);
            if (!aiResponse.empty())
            {
                std::string reply;
                std::string action;
                uint32 amount = 0;
                uint8 questState = 0;
                if (FSBGenAI::ParseStructuredResponse(aiResponse, reply, action, amount, &questState))
                {
                    result.reply = std::move(reply);
                    result.action = std::move(action);
                    result.amount = amount;
                    result.questState = questState;
                    return result;
                }
            }
        }

        result.reply = "Greetings, traveler.";
        result.action = "none";
        result.amount = 0;
        result.questState = ctx.questState;
        return result;
    }

    NpcChatContext BuildNpcContext(Creature* npc, Player* player)
    {
        NpcChatContext ctx;
        if (!npc)
            return ctx;

        ctx.entry = npc->GetEntry();
        ctx.npcName = npc->GetName();
        ctx.zoneId = npc->GetZoneId();
        ctx.areaId = npc->GetAreaId();

        if (CreatureTemplate const* tmpl = npc->GetCreatureTemplate())
            ctx.subName = tmpl->SubName;

        if (WowTime const* wowTime = GameTime::GetWowTime())
        {
            int8 hour = wowTime->GetHour();
            int8 minute = wowTime->GetMinute();
            if (hour >= 0 && minute >= 0)
            {
                char buf[16];
                snprintf(buf, sizeof(buf), "%02d:%02d", hour, minute);
                ctx.inGameTime = buf;
            }
        }

        if (Map* map = npc->GetMap())
        {
            WeatherState ws = map->GetZoneWeather(npc->GetZoneId());
            ctx.weather = FSBUtils::WeatherStateToText(ws);
        }

        if (player)
        {
            for (uint32 questId : sObjectMgr->GetCreatureQuestRelations(npc->GetEntry()))
            {
                Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
                if (!quest)
                    continue;

                if (player->GetQuestStatus(questId) != QUEST_STATUS_NONE)
                    continue;

                if (!player->CanTakeQuest(quest, false))
                    continue;

                ctx.hasQuest = true;
                ctx.questId = questId;
                ctx.questTitle = quest->GetLogTitle();
                ctx.questDescription = quest->GetQuestDescription();
                ctx.questState = GenAINpcMemoryMgr::Get()->GetQuestState(npc->GetGUID());
                if (ctx.questState == 0)
                    ctx.questState = 1;
                break;
            }
        }

        return ctx;
    }

    PlayerSnapshot BuildPlayerSnapshot(Player* player)
    {
        PlayerSnapshot snap;
        if (!player)
            return snap;

        snap.name = player->GetName();
        snap.race = player->GetRace();
        snap.playerClass = player->GetClass();
        snap.level = player->GetLevel();
        return snap;
    }
}
