/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PartyPackets_h__
#define PartyPackets_h__

#include "ItemPackets.h"
#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace Party
    {
        class SetPartyLeader final : public ClientPacket
        {
        public:
            SetPartyLeader(WorldPacket&& packet) : ClientPacket(CMSG_SET_PARTY_LEADER, std::move(packet)) { }

            void Read() override;
            uint8 PartyIndex = 0;
            ObjectGuid TargetGUID;

        };
        
        class PartyInvite final : public ClientPacket
        {
        public:
            PartyInvite(WorldPacket&& packet) : ClientPacket(CMSG_PARTY_INVITE, std::move(packet)) { }

            void Read() override;
            uint8 PartyIndex = 0;
            uint32 ProposedRoles = 0;
            ObjectGuid TargetGUID;
            uint32 TargetCfgRealmID = 0;
            
            std::string TargetName;
            std::string TargetRealm;
            
        };
        
        class ConvertRaid final : public ClientPacket
        {
        public:
            ConvertRaid(WorldPacket&& packet) : ClientPacket(CMSG_CONVERT_RAID, std::move(packet)) { }

            void Read() override;
            bool Raid = false;

        };

    }
}
#endif // PartyPackets_h__
