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

        class RequestPartyMemberStats final : public ClientPacket
        {
        public:
            RequestPartyMemberStats(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_PARTY_MEMBER_STATS, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            ObjectGuid Target;

        };

        class RequestPartyJoinUpdates final : public ClientPacket
        {
        public:
            RequestPartyJoinUpdates(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_PARTY_JOIN_UPDATES, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;

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

        struct PlayerList
        {
            ObjectGuid Guid;
            uint8 Connected = 0;
            uint8 Subgroup = 0;
            uint8 Flags = 0;
            uint8 RolesAssigned = 0;
            uint8 UnkByte = 0;
            std::string Name;
        };
        
        class PartyUpdate final : public ServerPacket
        {
        public:
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
            std::vector<PlayerList> Players;

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

        struct Phase
        {
            uint16 PhaseFlags = 0;
            uint16 Id = 0;
        };

        struct Aura
        {
            uint32 SpellId = 0;
            uint8 Scalings = 0;
            uint32 EffectMask = 0;
            uint32 EffectCount = 0;
            //float Scale  has to be some kind of array
        };

        class PartyMemberState final : public ServerPacket
        {
        public:
            PartyMemberState() : ServerPacket(SMSG_PARTY_MEMBER_STATE, 50) { }

            WorldPacket const* Write() override;

            bool ForEnemy = false;
            ObjectGuid MemberGuid;

            uint8 Unk704 = 0; //2 of these. First is 1, Second is 0

            GroupMemberStatus Status; //either define this or find where its defined

            uint8 PowerType = 0;
            uint16 Unk322 = 0;
            uint32 CurrentHealth = 0;
            uint32 MaxHealth = 0;
            uint16 CurrentPower = 0;
            uint16 MaxPower = 0;
            uint16 Level = 0;
            uint16 Unk200000 = 0;
            uint16 ZoneId = 0;

            uint16 Unk2000000 = 0;
            uint32 Unk4000000 = 0;

            uint16 PositionX = 0;
            uint16 PositionY = 0;
            uint16 PositionZ = 0;

            uint32 VehicleSeat = 0;
            uint32 AuraCount = 0;

            uint32 PhaseShiftFlags = 0;
            uint32 PhaseCount = 0;
            ObjectGuid PersonalGUID;
            std::vector<Phase> PhasesList;
            std::vector<Aura> AuraList;

            bool HasPet = false;
            ObjectGuid PetGUID;
            uint16 PetModelId = 0;
            uint32 PetCurrentHealth = 0;
            uint32 PetMaxHealth = 0;
            uint32 PetAuraCount = 0;
            std::vector<Aura> PetAuraList;
            std::string PetName;

        };

    }
}
#endif // PartyPackets_h__
