/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <memory.h>
#include "Object.h"
#include "Guild.h"

#include "TSIncludes.h"
#include "TSGuild.h"
#include "TSPlayer.h"
#include "TSWorldPacket.h"

TSGuild::TSGuild(Guild *guild)
{
    this->guild = guild;
}

TSGuild::TSGuild()
{
    this->guild = nullptr;
}

/**
 * Returns a table with the [Player]s in this [Guild]
 *
 * Only the players that are online and on some map.
 *
 * @return table guildPlayers : table of [Player]s
 */
TSArray<TSPlayer> TSGuild::GetMembers() 
{
    return TSArray<TSPlayer>();
}
    
/**
 * Returns the member count of this [Guild]
 *
 * @return uint32 memberCount
 */
uint32 TSGuild::GetMemberCount() 
{
#if defined TRINITY || AZEROTHCORE
    return guild->GetMemberCount();
#else
    return guild->GetMemberSize();
#endif
}
    
/**
 * Finds and returns the [Guild] leader by their GUID if logged in
 *
 * @return [Player] leader
 */
TSPlayer  TSGuild::GetLeader() 
{
#if defined TRINITY || AZEROTHCORE
     return TSPlayer(eObjectAccessor()FindPlayer(guild->GetLeaderGUID()));
#else
     return TSPlayer(eObjectAccessor()FindPlayer(guild->GetLeaderGuid()));
#endif
}
    
/**
 * Returns [Guild] leader GUID
 *
 * @return uint64 leaderGUID
 */
uint64 TSGuild::GetLeaderGUID() 
{
#if defined TRINITY || AZEROTHCORE
    return guild->GetLeaderGUID();
#else
    return guild->GetLeaderGuid();
#endif
}
    
/**
 * Returns the [Guild]s entry ID
 *
 * @return uint32 entryId
 */
uint32 TSGuild::GetId() 
{
    return guild->GetId();
}
    
/**
 * Returns the [Guild]s name
 *
 * @return string guildName
 */
TSString TSGuild::GetName()
{
     return TSString(guild->GetName());
}
    
/**
 * Returns the [Guild]s current Message Of The Day
 *
 * @return string guildMOTD
 */
TSString TSGuild::GetMOTD()
{
     return TSString(guild->GetMOTD());
}
    
/**
 * Returns the [Guild]s current info
 *
 * @return string guildInfo
 */
TSString TSGuild::GetInfo()
{
#if defined TRINITY || AZEROTHCORE
     return TSString(guild->GetInfo());
#else
     return TSString(guild->GetGINFO());
#endif
}
    
#if defined(CLASSIC) || defined(TBC) || defined(WOTLK)
/**
 * Sets the leader of this [Guild]
 *
 * @param [Player] leader : the [Player] leader to change
 */
void TSGuild::SetLeader(TSPlayer _player)
{
    auto player = _player.player;
    
#if defined TRINITY || AZEROTHCORE
    guild->HandleSetLeader(player->GetSession(), player->GetName());
#else
    guild->SetLeader(player->TS_GET_GUID());
#endif
}
#endif
    
#ifndef CLASSIC
/**
 * Sets the information of the bank tab specified
 *
 * @param uint8 tabId : the ID of the tab specified
 * @param string info : the information to be set to the bank tab
 */
void TSGuild::SetBankTabText(uint8 tabId,TSString text) 
{
#if defined TRINITY || AZEROTHCORE
    guild->SetBankTabText(tabId, text._value);
#else
    guild->SetGuildBankTabText(tabId, text);
#endif
}
#endif

void TSGuild::SendPacket(std::shared_ptr<TSWorldPacket> _data)
{
    SendPacket(*_data);
}
    
// SendPacketToGuild(packet)
/**
 * Sends a [WorldPacket] to all the [Player]s in the [Guild]
 *
 * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
 */
void TSGuild::SendPacket(TSWorldPacket _data)
{
    auto data = _data.packet;
    
#ifdef CMANGOS
    guild->BroadcastPacket(*data);
#else
    guild->BroadcastPacket(data);
#endif
}

void TSGuild::SendPacketToRanked(std::shared_ptr<TSWorldPacket> _data,uint8 ranked)
{
    SendPacketToRanked(*_data,ranked);
}
    
// SendPacketToRankedInGuild(packet, rankId)
/**
 * Sends a [WorldPacket] to all the [Player]s at the specified rank in the [Guild]
 *
 * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
 * @param uint8 rankId : the rank ID
 */
void TSGuild::SendPacketToRanked(TSWorldPacket _data,uint8 ranked)
{
    auto data = _data.packet;
    
#ifdef CMANGOS
    guild->BroadcastPacketToRank(*data, ranked);
#else
    guild->BroadcastPacketToRank(data, ranked);
#endif
}
    
/**
 * Disbands the [Guild]
 */
void TSGuild::Disband() 
{
    guild->Disband();
}
    
/**
 * Adds the specified [Player] to the [Guild] at the specified rank.
 *
 * If no rank is specified, defaults to none.
 *
 * @param [Player] player : the [Player] to be added to the guild
 * @param uint8 rankId : the rank ID
 */
void TSGuild::AddMember(TSPlayer _player,uint8 rankId)
{
    auto player = _player.player;
    
#ifdef TRINITY
CharacterDatabaseTransaction trans(nullptr);
    guild->AddMember(trans, player->TS_GET_GUID(), rankId);
#else
    guild->AddMember(player->TS_GET_GUID(), rankId);
#endif
}
    
/**
 * Removes the specified [Player] from the [Guild].
 *
 * @param [Player] player : the [Player] to be removed from the guild
 * @param bool isDisbanding : default 'false', should only be set to 'true' if the guild is triggered to disband
 */
void TSGuild::DeleteMember(TSPlayer _player,bool isDisbanding)
{
    auto player = _player.player;
    
#if defined TRINITY
CharacterDatabaseTransaction trans(nullptr);
    guild->DeleteMember(trans, player->TS_GET_GUID(), isDisbanding);
#elif defined AZEROTHCORE
SQLTransaction trans(nullptr);
    guild->DeleteMember(trans, player->TS_GET_GUID(), isDisbanding);
#else
    guild->DelMember(player->TS_GET_GUID(), isDisbanding);
#endif
}
    
/**
 * Promotes/demotes the [Player] to the specified rank.
 *
 * @param [Player] player : the [Player] to be promoted/demoted
 * @param uint8 rankId : the rank ID
 */
void TSGuild::SetMemberRank(TSPlayer _player,uint8 newRank)
{
    auto player = _player.player;
    
#ifdef TRINITY
CharacterDatabaseTransaction trans(nullptr);
    guild->ChangeMemberRank(trans, player->TS_GET_GUID(), newRank);
#else
    guild->ChangeMemberRank(player->TS_GET_GUID(), newRank);
#endif
}
    