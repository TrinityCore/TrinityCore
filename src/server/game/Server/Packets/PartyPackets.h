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
        
        class ClientPartyInvite final : public ClientPacket
        {
        public:
            ClientPartyInvite(WorldPacket&& packet) : ClientPacket(CMSG_PARTY_INVITE, std::move(packet)) { }

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

        class PartyInvite final : public ServerPacket
        {
        public:
            PartyInvite() : ServerPacket(SMSG_PARTY_INVITE, 100) { } //TODO: Fix Size

            WorldPacket const* Write() override;
            
            bool CanAccept = false;
            bool MightCRZYou = false;
            bool MustBeBNetFriend = false;
            bool AllowMultipleRoles = false;
            bool IsXRealm = false;

            ObjectGuid InviterGuid;
            ObjectGuid InviterBNetAccountID;
            uint32 InviterCfgRealmID = 0;
            uint16 Unk1 = 0;

            bool IsLocal = false;
            bool Unk2 = false;

            std::string InviterRealmNameActual;
            std::string InviterRealmNameNormalized;
            uint32 ProposedRoles = 0;
            uint32 LfgSlotsCount = 0;
            uint32 LfgCompletedMask = 0;
            std::string InviterName;
            uint32 LfgSlots = 0; //Seems like there's normnally more than one of these, so should it be an array?
        };

        class PartyCommandResult final : public ServerPacket
        {
        public:
            PartyCommandResult() : ServerPacket(SMSG_PARTY_COMMAND_RESULT, 50) { } //TODO: Fix Size

            WorldPacket const* Write() override;

            PartyOperation Command = PARTY_OP_INVITE;
            PartyResult Result = ERR_PARTY_RESULT_OK;
            uint32 ResultData = 0;
            ObjectGuid ResultGUID;
            std::string Name;

        };

    }
}
#endif // PartyPackets_h__
