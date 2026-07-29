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

#include "GenAI_battleground_prompts.h"
#include "GenAI_chatter_prompts.h"
#include "GenAI_client.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_chat_battleground.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots_battleground_handler.h"

#include "Battleground.h"
#include "Log.h"
#include "Map.h"
#include "StringFormat.h"

#include <mutex>
#include <thread>

namespace FSBGenAIPrompts
{
    static std::string GetBattlegroundName(Creature* bot)
    {
        if (Map* map = bot->GetMap())
            if (BattlegroundMap* bgMap = map->ToBattlegroundMap())
                if (Battleground* bg = bgMap->GetBG())
                    return std::string(bg->GetName());
        return "Battleground";
    }

    static std::string GetTeamName(Team team)
    {
        if (team == ALLIANCE)
            return "Alliance";
        if (team == HORDE)
            return "Horde";
        return "Neutral";
    }

    static std::string GetEnemyTeamName(Team team)
    {
        if (team == ALLIANCE)
            return "Horde";
        if (team == HORDE)
            return "Alliance";
        return "Enemy";
    }

    static std::string GetStateText(FSBBattlegroundChat::BGChatState state)
    {
        switch (state)
        {
            case FSBBattlegroundChat::BGChatState::Defend:
                return "Defend our base and flag";
            case FSBBattlegroundChat::BGChatState::HoldMid:
                return "Hold the midfield";
            case FSBBattlegroundChat::BGChatState::Attack:
                return "Attack the enemy flag";
            case FSBBattlegroundChat::BGChatState::Return:
                return "Return our flag to base";
            case FSBBattlegroundChat::BGChatState::Protect:
                return "Protect the flag carrier";
            case FSBBattlegroundChat::BGChatState::None:
            default:
                return "No specific objective";
        }
    }

    void DispatchBotBattlegroundSpawnChat(Creature* bot, std::string const& seedMsg)
    {
        if (!bot || seedMsg.empty())
            return;

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded text.", bot->GetName());
            FSBChat::BotSendRaidChat(bot, seedMsg);
            return;
        }

        if (!FSBGenAI::IsEnabled())
        {
            FSBChat::BotSendRaidChat(bot, seedMsg);
            return;
        }

        std::string systemPrompt = BuildStandardSystemPrompt(bot);
        std::string bgName = GetBattlegroundName(bot);
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        std::string ownTeam = GetTeamName(botTeam);
        std::string enemyTeam = GetEnemyTeamName(botTeam);

        std::string userMessage = Trinity::StringFormat(
            "You have just spawned into the battleground. Say a short, natural line to your team in raid chat that shows you are ready and fits the battleground atmosphere.\n\n"
            "Battleground: {}\n"
            "Your team: {}\n"
            "Enemy team: {}\n\n"
            "Example style (do not copy): \"{}\"",
            bgName,
            ownTeam,
            enemyTeam,
            seedMsg);

        ai->genAIFallbackAction = [bot, seedMsg]()
        {
            FSBChat::BotSendRaidChat(bot, seedMsg);
        };
        ai->genAIDeliverAction = [bot](std::string const& response)
        {
            FSBChat::BotSendRaidChat(bot, response);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;

        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched battleground spawn chat for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]()
        {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotBattlegroundStateChat(Creature* bot, uint32 bgTypeId, Team botTeam,
        FSBBattlegroundChat::BGChatState state, std::string const& fallbackMsg,
        std::string const& nodeName)
    {
        (void)bgTypeId;

        if (!bot || fallbackMsg.empty())
            return;

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded text.", bot->GetName());
            FSBChat::BotSendRaidChat(bot, fallbackMsg);
            return;
        }

        if (!FSBGenAI::IsEnabled())
        {
            FSBChat::BotSendRaidChat(bot, fallbackMsg);
            return;
        }

        std::string systemPrompt = BuildStandardSystemPrompt(bot);
        std::string bgName = GetBattlegroundName(bot);
        std::string ownTeam = GetTeamName(botTeam);
        std::string enemyTeam = GetEnemyTeamName(botTeam);
        std::string stateText = GetStateText(state);

        std::string nodeContext;
        if (!nodeName.empty())
            nodeContext = Trinity::StringFormat(" You are focusing on the {}.", nodeName);

        std::string userMessage = Trinity::StringFormat(
            "The current battleground objective is: {}.{}\n"
            "You are in battleground {}.\n"
            "Your team is {}; the enemy team is {}.\n"
            "Say a short, natural line to your team in raid chat that reflects this objective.\n\n"
            "Example style (do not copy): \"{}\"",
            stateText,
            nodeContext,
            bgName,
            ownTeam,
            enemyTeam,
            fallbackMsg);

        ai->genAIFallbackAction = [bot, fallbackMsg]()
        {
            FSBChat::BotSendRaidChat(bot, fallbackMsg);
        };
        ai->genAIDeliverAction = [bot](std::string const& response)
        {
            FSBChat::BotSendRaidChat(bot, response);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto requestState = ai->pendingGenAIState;

        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched battleground state chat for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, requestState]()
        {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(requestState->mutex);
            requestState->result = std::move(result);
            requestState->ready = true;
        }).detach();
    }
}
