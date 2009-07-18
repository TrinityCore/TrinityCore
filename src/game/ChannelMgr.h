/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
#ifndef TRINITYCORE_CHANNELMGR_H
#define TRINITYCORE_CHANNELMGR_H

#include <map>
#include <string>

#include "Policies/Singleton.h"

#include "Channel.h"
#include "World.h"

class ChannelMgr
{
    public:
        uint32 team;
        typedef std::map<std::string,Channel *> ChannelMap;
        ChannelMgr() {team = 0;}
        ~ChannelMgr()
        {
            for(ChannelMap::const_iterator itr = channels.begin();itr!=channels.end(); ++itr)
                delete itr->second;
            channels.clear();
        }
        Channel *GetJoinChannel(const std::string& name, uint32 channel_id)
        {
            if (channels.find(name) == channels.end())
            {
                Channel *nchan = new Channel(name,channel_id, team);
                channels[name] = nchan;
            }
            return channels[name];
        }
        Channel *GetChannel(const std::string& name, Player *p)
        {
            ChannelMap::const_iterator i = channels.find(name);

            if(i == channels.end())
            {
                WorldPacket data;
                MakeNotOnPacket(&data,name);
                p->GetSession()->SendPacket(&data);
                return NULL;
            }
            else
                return i->second;
        }
        void LeftChannel(const std::string& name)
        {
            ChannelMap::const_iterator i = channels.find(name);

            if(i == channels.end())
                return;

            Channel* channel = i->second;

            if(channel->GetNumPlayers() == 0 && !channel->IsConstant())
            {
                channels.erase(name);
                delete channel;
            }
        }
    private:
        ChannelMap channels;
        void MakeNotOnPacket(WorldPacket *data, const std::string& name)
        {
            data->Initialize(SMSG_CHANNEL_NOTIFY, (1+10));  // we guess size
            (*data) << (uint8)0x05 << name;
        }
};

class AllianceChannelMgr : public ChannelMgr {};
class HordeChannelMgr    : public ChannelMgr {};

inline ChannelMgr* channelMgr(uint32 team)
{
    if (sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
                                                            //For Test,No Seprate Faction
        return &Trinity::Singleton<AllianceChannelMgr>::Instance();

    if(team==ALLIANCE)
        return &Trinity::Singleton<AllianceChannelMgr>::Instance();
    if(team==HORDE)
        return &Trinity::Singleton<HordeChannelMgr>::Instance();
    return NULL;
}
#endif

