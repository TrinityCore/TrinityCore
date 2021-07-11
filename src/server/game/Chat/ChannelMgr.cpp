/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ChannelMgr.h"
#include "Policies/SingletonImp.h"
#include "World.h"
#include "Util.h"
#include "DBCStores.h"

INSTANTIATE_SINGLETON_1(AllianceChannelMgr);
INSTANTIATE_SINGLETON_1(HordeChannelMgr);

ChannelMgr* channelMgr(Team team)
{
    if (sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        return &MaNGOS::Singleton<AllianceChannelMgr>::Instance();        // cross-faction

    if (team == ALLIANCE)
        return &MaNGOS::Singleton<AllianceChannelMgr>::Instance();
    if (team == HORDE)
        return &MaNGOS::Singleton<HordeChannelMgr>::Instance();

    return nullptr;
}

ChannelMgr::~ChannelMgr()
{
    for (const auto& channel : channels)
        delete channel.second;

    channels.clear();
}

Channel *ChannelMgr::GetJoinChannel(std::string const& name, bool allowAreaDependantChans)
{
    std::wstring wname;
    Utf8toWStr(name, wname);
    wstrToLower(wname);

    if (channels.find(wname) == channels.end())
    {
        ChatChannelsEntry const* ch = GetChannelEntryFor(name);
        if (!allowAreaDependantChans && ch && ch->flags & Channel::CHANNEL_DBC_FLAG_ZONE_DEP)
            return nullptr;
        Channel *nchan = new Channel(name);
        channels[wname] = nchan;
        return nchan;
    }

    return channels[wname];
}

Channel *ChannelMgr::GetChannel(std::string const& name, PlayerPointer p, bool pkt)
{
    std::wstring wname;
    Utf8toWStr(name, wname);
    wstrToLower(wname);

    ChannelMap::const_iterator i = channels.find(wname);

    if (i == channels.end())
    {
        if (pkt)
        {
            WorldPacket data;
            Channel::MakeNotOnPacket(&data, name);
            p->GetSession()->SendPacket(&data);
        }

        return nullptr;
    }
    else
        return i->second;
}

void ChannelMgr::LeftChannel(std::string const& name)
{
    std::wstring wname;
    Utf8toWStr(name, wname);
    wstrToLower(wname);

    ChannelMap::const_iterator i = channels.find(wname);

    if (i == channels.end())
        return;

    Channel* channel = i->second;

    if (channel->GetNumPlayers() == 0 && !channel->IsConstant() && !channel->GetSecurityLevel())
    {
        channels.erase(wname);
        delete channel;
    }
}

void ChannelMgr::CreateDefaultChannels()
{
    GetJoinChannel("Warden")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("Anticrash")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("Antiflood")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("ItemsCheck")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("GoldDupe")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("SAC")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("MailsAC")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("BotsDetector")->SetSecurityLevel(SEC_GAMEMASTER);
    GetJoinChannel("ChatSpam")->SetSecurityLevel(SEC_MODERATOR);
    GetJoinChannel("LowLevelBots")->SetSecurityLevel(SEC_GAMEMASTER);

    for (const auto& channel : channels)
        channel.second->SetAnnounce(false);
}

void ChannelMgr::AnnounceBothFactionsChannel(std::string const& channelName, ObjectGuid playerGuid, char const* message)
{
    if (Channel* c = channelMgr(HORDE)->GetJoinChannel(channelName))
        c->Say(playerGuid, message, LANG_UNIVERSAL, true);
    if (!sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        if (Channel* c = channelMgr(ALLIANCE)->GetJoinChannel(channelName))
            c->Say(playerGuid, message, LANG_UNIVERSAL, true);
}
