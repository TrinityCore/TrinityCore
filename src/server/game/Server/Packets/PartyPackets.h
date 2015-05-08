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
#include "LFG.h"

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

        class SetRole final : public ClientPacket
        {
        public:
            SetRole(WorldPacket&& packet) : ClientPacket(CMSG_SET_ROLE, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            ObjectGuid ChangedUnit;
            uint32 Role = 0;

        };
        
        class PartyUninvite final : public ClientPacket
        {
        public:
            PartyUninvite(WorldPacket&& packet) : ClientPacket(CMSG_PARTY_UNINVITE, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            ObjectGuid TargetGUID;
            std::string Reason;

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
        
        class PartyInviteResponse final : public ClientPacket
        {
        public:
            PartyInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_PARTY_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;

            bool Accept = false;
            bool HasRolesDesired = false;
            uint32 RolesDesired = 0;

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
            uint32 LfgSlots = 0; //Seems like there's normally more than one of these, so should it be an array?
        };

        class PartyCommandResult final : public ServerPacket
        {
        public:
            PartyCommandResult() : ServerPacket(SMSG_PARTY_COMMAND_RESULT, 50) { }

            WorldPacket const* Write() override;

            PartyOperation Command = PARTY_OP_INVITE;
            PartyResult Result = ERR_PARTY_RESULT_OK;
            uint32 ResultData = 0;
            ObjectGuid ResultGUID;
            std::string Name;

        };

        class RoleChangedInform final : public ServerPacket
        {
        public:
            RoleChangedInform() : ServerPacket(SMSG_ROLE_CHANGED_INFORM, 50) { }

            WorldPacket const* Write() override;

            uint8 PartyIndex = 0;
            ObjectGuid From;
            ObjectGuid ChangedUnit;
            uint32 OldRole = 0;
            uint32 NewRole = 0;

        };

        class PartyUpdate final : public ServerPacket
        {
        public:
            struct PlayerList
            {
                PlayerList(ObjectGuid const& guid, uint8 connected, uint8 subgroup, uint8 flags, uint8 roles, uint8 unk, std::string name) :
                    Guid(guid), Connected(connected), Subgroup(subgroup), Flags(flags), RolesAssigned(flags), UnkByte(unk), Name(name) { }

                ObjectGuid Guid;
                uint8 Connected;
                uint8 Subgroup;
                uint8 Flags;
                uint8 RolesAssigned;
                uint8 UnkByte;
                std::string Name;
            };

            PartyUpdate() : ServerPacket(SMSG_PARTY_UPDATE, 100) { }

            WorldPacket const* Write() override;

            uint8 PartyFlags = 0;
            uint8 PartyIndex = 0;
            uint8 PartyType = 0;

            uint32 MyIndex = 0;
            ObjectGuid LeaderGUID;
            uint32 SequenceNum = 0;
            ObjectGuid PartyGUID;

            uint32 PlayerListCount = 0;
            std::vector<PlayerList> _PlayerLists;

            bool HasLfgInfo = false;
            bool HasLootSettings = false;
            bool HasDifficultySettings = false;

            uint8 MyLfgFlags = 0;
            uint32 LfgSlot = 0;
            uint32 MyLfgRandomSlot = 0;
            uint8 MyLfgPartialClear = 0;
            float MyLfgGearDiff = 0.0;
            uint8 MyLfgStrangerCount = 0;
            uint8 MyLfgKickVoteCount = 0;
            uint8 LfgBootCount = 0;

            bool LfgAborted = false;
            bool MyLfgFirstReward = false;

            uint8 LootMethod = 0;
            ObjectGuid LootMaster;
            uint8 LootThreshold;

            uint32 UnkInt4 = 0;
            uint32 DungeonDifficultyID = 0;
            uint32 RaidDifficultyID = 0;
        };

    }
}
#endif // PartyPackets_h__
