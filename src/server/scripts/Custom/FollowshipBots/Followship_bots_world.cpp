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

#include "ScriptMgr.h"
#include "Storages/WhoListStorage.h"
#include "Chat.h"
#include "Player.h"

#include "Followship_bots_chat_handler.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_npc_chat_manager.h"

class followship_bots_world_script : public WorldScript
{
public:
    followship_bots_world_script() : WorldScript("followship_bots_world_script") { }

    void OnUpdate(uint32 diff) override
    {
        FSBChatMgr::Get()->Update(diff);
        FSBNpcChatMgr::Get()->Update(diff);
    }
};

static void FSBHandleBotWhisper(Player* sender, std::string const& targetName, std::string const& msg)
{
    if (!sender)
        return;

    if (Creature* bot = FSBChatMgr::Get()->FindActiveBotByName(targetName))
    {
        FSBChatMgr::Get()->HandleBotWhisper(sender, bot, msg);
        return;
    }

    // Strip realm suffix if present (e.g., "BotName-Realm")
    size_t dashPos = targetName.find('-');
    if (dashPos != std::string::npos)
    {
        std::string nameOnly = targetName.substr(0, dashPos);
        if (Creature* bot = FSBChatMgr::Get()->FindActiveBotByName(nameOnly))
            FSBChatMgr::Get()->HandleBotWhisper(sender, bot, msg);
    }
}

static void FSBAddBotsToWhoList(WhoListInfoVector& whoList)
{
    for (Creature* bot : FSBChatMgr::Get()->GetActiveBots())
    {
        if (!bot || !bot->IsInWorld() || !bot->IsAlive())
            continue;

        std::string botName = bot->GetName();
        std::string displayName = FSBChatMgr::SanitizeBotName(botName);
        std::wstring wideBotName;
        if (!Utf8toWStr(displayName, wideBotName))
            continue;
        wstrToLower(wideBotName);

        Team botTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
        uint8 tcClass = FSBUtils::FSBToTCClass(botClass);
        uint8 tcRace = FSBUtils::BotRaceToTC(botRace);
        Gender gender = FSBMgr::Get()->GetBotGenderForEntry(bot->GetEntry());

        whoList.emplace_back(
            bot->GetGUID(),
            botTeam,
            SEC_PLAYER,
            bot->GetLevel(),
            uint8(tcClass),
            uint8(tcRace),
            bot->GetZoneId(),
            uint8(gender),
            true,
            false,
            wideBotName,
            std::wstring(),
            displayName,
            std::string(),
            ObjectGuid::Empty
        );
    }
}

void AddSC_followship_bots_world()
{
    sWhoListStorageMgr->SetBotCallback(&FSBAddBotsToWhoList);
    g_BotWhisperCallback = &FSBHandleBotWhisper;

    new followship_bots_world_script();
}
