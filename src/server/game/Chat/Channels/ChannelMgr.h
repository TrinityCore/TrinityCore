/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#ifndef __TRINITY_CHANNELMGR_H
#define __TRINITY_CHANNELMGR_H

#include "Common.h"
#include "Channel.h"

#include <map>
#include <string>

#include "World.h"

class ChannelMgr
{
    typedef std::map<std::wstring, Channel*> ChannelMap;

    protected:
        ChannelMgr() : team(0) { }
        ~ChannelMgr();

    public:
        static ChannelMgr* forTeam(uint32 team);
        void setTeam(uint32 newTeam) { team = newTeam; }

        Channel* GetJoinChannel(std::string const& name, uint32 channel_id);
        Channel* GetChannel(std::string const& name, Player* p, bool pkt = true);
        void LeftChannel(std::string const& name);

    private:
        ChannelMap channels;
        uint32 team;

        void MakeNotOnPacket(WorldPacket* data, std::string const& name);
};

#endif
