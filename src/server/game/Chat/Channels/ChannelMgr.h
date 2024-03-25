/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Define.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include <string>
#include <unordered_map>

class Channel;
class Player;
struct AreaTableEntry;

class TC_GAME_API ChannelMgr
{
    typedef std::unordered_map<std::wstring, Channel*> CustomChannelContainer; // custom channels only differ in name
    typedef std::unordered_map<ObjectGuid, Channel*> BuiltinChannelContainer;

    protected:
        explicit ChannelMgr(Team team) : _team(team), _guidGenerator(HighGuid::ChatChannel) { }
        ~ChannelMgr();

    public:
        ChannelMgr(ChannelMgr const& right) = delete;
        ChannelMgr(ChannelMgr&& right) = delete;
        ChannelMgr& operator=(ChannelMgr const& right) = delete;
        ChannelMgr& operator=(ChannelMgr&& right) = delete;

        static void LoadFromDB();
        static ChannelMgr* ForTeam(Team team);
        static Channel* GetChannelForPlayerByNamePart(std::string const& namePart, Player* playerSearcher);
        static Channel* GetChannelForPlayerByGuid(ObjectGuid channelGuid, Player* playerSearcher);
        static AreaTableEntry const* SpecialLinkedArea;

        void SaveToDB();
        Channel* GetSystemChannel(uint32 channelId, AreaTableEntry const* zoneEntry = nullptr);
        Channel* CreateCustomChannel(std::string const& name);
        Channel* GetCustomChannel(std::string const& name) const;
        Channel* GetChannel(uint32 channelId, std::string const& name, Player* player, bool notify = true, AreaTableEntry const* zoneEntry = nullptr) const;
        void LeftChannel(uint32 channelId, AreaTableEntry const* zoneEntry);

    private:
        CustomChannelContainer _customChannels;
        BuiltinChannelContainer _channels;
        Team const _team;
        ObjectGuidGenerator _guidGenerator;

        static void SendNotOnChannelNotify(Player const* player, std::string const& name);
        ObjectGuid CreateCustomChannelGuid();
        ObjectGuid CreateBuiltinChannelGuid(uint32 channelId, AreaTableEntry const* zoneEntry = nullptr) const;
};

#endif
