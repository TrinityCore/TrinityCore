/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "ChannelPackets.h"
#include "Player.h"
#include "World.h"

ChannelMgr::~ChannelMgr()
{
    for (ChannelMap::iterator itr = _channels.begin(); itr != _channels.end(); ++itr)
        delete itr->second;
}

ChannelMgr* ChannelMgr::ForTeam(uint32 team)
{
    static ChannelMgr allianceChannelMgr;
    static ChannelMgr hordeChannelMgr;
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        return &allianceChannelMgr;        // cross-faction

    if (team == ALLIANCE)
        return &allianceChannelMgr;

    if (team == HORDE)
        return &hordeChannelMgr;

    return nullptr;
}

Channel* ChannelMgr::GetJoinChannel(std::string const& name, uint32 channelId)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return nullptr;

    wstrToLower(wname);

    ChannelMap::const_iterator i = _channels.find(wname);
    if (i == _channels.end())
    {
        Channel* nchan = new Channel(name, channelId, _team);
        _channels[wname] = nchan;
        return nchan;
    }

    return i->second;
}

Channel* ChannelMgr::GetChannel(std::string const& name, Player* player, bool notify /*= true*/)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return nullptr;

    wstrToLower(wname);

    ChannelMap::const_iterator i = _channels.find(wname);
    if (i == _channels.end())
    {
        if (notify)
            SendNotOnChannelNotify(player, name);

        return nullptr;
    }

    return i->second;
}

void ChannelMgr::LeftChannel(std::string const& name)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return;

    wstrToLower(wname);

    ChannelMap::const_iterator i = _channels.find(wname);
    if (i == _channels.end())
        return;

    Channel* channel = i->second;

    if (!channel->GetNumPlayers() && !channel->IsConstant())
    {
        _channels.erase(i);
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
