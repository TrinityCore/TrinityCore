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
 */

#include "Followship_bots_ai_base.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_battleground_handler.h"

FSB_BaseAI::~FSB_BaseAI()
{
    FSBChatMgr::Get()->LeaveBotChannels(me);
    FSBChatMgr::Get()->UnregisterActiveBot(me);
    delete botDungeonData;
    delete botBattlegroundData;
}

FSB_BattlegroundData* FSB_BaseAI::GetBattlegroundData()
{
    return botBattlegroundData;
}

void FSB_BaseAI::AddChatMemory(uint32 channelId, std::string const& sender, std::string const& msg, bool isPlayer)
{
    GenAINpcMemoryMgr::Get()->AddEntry(me->GetGUID(), channelId, sender, msg, isPlayer);
}

std::deque<BotChatMemoryEntry> FSB_BaseAI::GetChatMemory() const
{
    return GenAINpcMemoryMgr::Get()->GetMemory(me->GetGUID());
}

void FSB_BaseAI::ClearChatMemory()
{
    GenAINpcMemoryMgr::Get()->ClearMemory(me->GetGUID());
}
