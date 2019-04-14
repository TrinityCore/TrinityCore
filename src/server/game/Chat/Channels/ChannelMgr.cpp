/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ChannelMgr.h"
#include "Channel.h"
#include "ChannelPackets.h"
#include "DB2Stores.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"

ChannelMgr::~ChannelMgr()
{
    for (auto itr = _channels.begin(); itr != _channels.end(); ++itr)
        delete itr->second;

    for (auto itr = _customChannels.begin(); itr != _customChannels.end(); ++itr)
        delete itr->second;
}

ChannelMgr* ChannelMgr::ForTeam(uint32 team)
{
    static ChannelMgr allianceChannelMgr(ALLIANCE);
    static ChannelMgr hordeChannelMgr(HORDE);

    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        return &allianceChannelMgr;        // cross-faction

    if (team == ALLIANCE)
        return &allianceChannelMgr;

    if (team == HORDE)
        return &hordeChannelMgr;

    return nullptr;
}

Channel* ChannelMgr::GetChannelForPlayerByNamePart(std::string const& namePart, Player* playerSearcher)
{
    std::wstring channelNamePart;
    if (!Utf8toWStr(namePart, channelNamePart))
        return nullptr;

    wstrToLower(channelNamePart);
    for (Channel* channel : playerSearcher->GetJoinedChannels())
    {
        std::string chanName = channel->GetName(playerSearcher->GetSession()->GetSessionDbcLocale());

        std::wstring channelNameW;
        if (!Utf8toWStr(chanName, channelNameW))
            continue;

        wstrToLower(channelNameW);
        if (!channelNameW.compare(0, channelNamePart.size(), channelNamePart))
            return channel;
    }

    return nullptr;
}

Channel* ChannelMgr::GetJoinChannel(uint32 channelId, std::string const& name, AreaTableEntry const* zoneEntry /*= nullptr*/)
{
    if (channelId) // builtin
    {
        ChatChannelsEntry const* channelEntry = sChatChannelsStore.AssertEntry(channelId);
        uint32 zoneId = zoneEntry ? zoneEntry->ID : 0;
        if (channelEntry->Flags & (CHANNEL_DBC_FLAG_GLOBAL | CHANNEL_DBC_FLAG_CITY_ONLY))
            zoneId = 0;

        std::pair<uint32, uint32> key = std::make_pair(channelId, zoneId);
        auto itr = _channels.find(key);
        if (itr != _channels.end())
            return itr->second;

        Channel* newChannel = new Channel(channelId, _team, zoneEntry);
        _channels[key] = newChannel;
        return newChannel;
    }
    else // custom
    {
        std::wstring channelName;
        if (!Utf8toWStr(name, channelName))
            return nullptr;

        wstrToLower(channelName);

        auto itr = _customChannels.find(channelName);
        if (itr != _customChannels.end())
            return itr->second;

        Channel* newChannel = new Channel(name, _team);
        _customChannels[channelName] = newChannel;
        return newChannel;
    }
}

Channel* ChannelMgr::GetChannel(uint32 channelId, std::string const& name, Player* player, bool notify /*= true*/, AreaTableEntry const* zoneEntry /*= nullptr*/) const
{
    Channel* result = nullptr;
    if (channelId) // builtin
    {
        ChatChannelsEntry const* channelEntry = sChatChannelsStore.AssertEntry(channelId);
        uint32 zoneId = zoneEntry ? zoneEntry->ID : 0;
        if (channelEntry->Flags & (CHANNEL_DBC_FLAG_GLOBAL | CHANNEL_DBC_FLAG_CITY_ONLY))
            zoneId = 0;

        std::pair<uint32, uint32> key = std::make_pair(channelId, zoneId);
        auto itr = _channels.find(key);
        if (itr != _channels.end())
            result = itr->second;
    }
    else // custom
    {
        std::wstring channelName;
        if (!Utf8toWStr(name, channelName))
            return nullptr;

        wstrToLower(channelName);

        auto itr = _customChannels.find(channelName);
        if (itr != _customChannels.end())
            result = itr->second;
    }

    if (!result && notify)
    {
        std::string channelName = name;
        Channel::GetChannelName(channelName, channelId, player->GetSession()->GetSessionDbcLocale(), zoneEntry);

        SendNotOnChannelNotify(player, channelName);
    }

    return result;
}

void ChannelMgr::LeftChannel(std::string const& name)
{
    std::wstring channelName;
    if (!Utf8toWStr(name, channelName))
        return;

    wstrToLower(channelName);
    auto itr = _customChannels.find(channelName);
    if (itr == _customChannels.end())
        return;

    Channel* channel = itr->second;
    if (!channel->GetNumPlayers())
    {
        _customChannels.erase(itr);
        delete channel;
    }
}

void ChannelMgr::LeftChannel(uint32 channelId, AreaTableEntry const* zoneEntry)
{
    ChatChannelsEntry const* channelEntry = sChatChannelsStore.AssertEntry(channelId);
    uint32 zoneId = zoneEntry ? zoneEntry->ID : 0;
    if (channelEntry->Flags & (CHANNEL_DBC_FLAG_GLOBAL | CHANNEL_DBC_FLAG_CITY_ONLY))
        zoneId = 0;

    std::pair<uint32, uint32> key = std::make_pair(channelId, zoneId);
    auto itr = _channels.find(key);
    if (itr == _channels.end())
        return;

    Channel* channel = itr->second;
    if (!channel->GetNumPlayers())
    {
        _channels.erase(itr);
        delete channel;
    }
}

void ChannelMgr::SendNotOnChannelNotify(Player const* player, std::string const& name)
{
    WorldPackets::Channel::ChannelNotify notify;
    notify.Type = CHAT_NOT_MEMBER_NOTICE;
    notify._Channel = name;
    player->SendDirectMessage(notify.Write());
}
