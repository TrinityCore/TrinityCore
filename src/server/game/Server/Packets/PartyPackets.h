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

#ifndef PartyPackets_h__
#define PartyPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"

class Player;
enum class SummonRaidMemberValidateReasonCode : int32;

namespace WorldPackets
{
    namespace Party
    {
        struct PartyMemberPhaseStates
        {
            uint32 PhaseShiftFlags = 0;
            std::vector<uint16> List;
        };

        struct PartyMemberAuraStates
        {
            int32 SpellID = 0;
            uint16 Flags = 0;
            std::vector<int32> Points;
        };

        struct PartyMemberPetStats
        {
            ObjectGuid GUID;
            std::string Name;
            int16 ModelId = 0;
            int32 CurrentHealth = 0;
            int32 MaxHealth = 0;
            uint8 PowerType = 0u;
            uint16 CurrentPower = 0;
            uint16 MaxPower = 0;
            uint64 AuraMask = 0;
            std::vector<PartyMemberAuraStates> Auras;
        };

        struct PartyMemberStats
        {
            uint16 Level = 0;
            uint16 Status = 0;
            int32 CurrentHealth = 0;
            int32 MaxHealth = 0;
            uint8 PowerType = 0u;
            uint16 CurrentPower = 0;
            uint16 MaxPower = 0;
            uint16 ZoneID = 0;
            uint16 WmoGroupID = 0;
            int16 PositionX = 0;
            int16 PositionY = 0;
            int16 PositionZ = 0;
            int32 VehicleSeat = 0;
            uint64 AuraMask = 0;
            uint32 AuraCount = 0;

            PartyMemberPhaseStates Phases;
            std::vector<PartyMemberAuraStates> Auras;
            Optional<PartyMemberPetStats> PetStats;
        };

        class PartyMemberState final : public ServerPacket
        {
        public:
            PartyMemberState(bool fullUpdate = false) : ServerPacket(fullUpdate ? SMSG_PARTY_MEMBER_FULL_STATE : SMSG_PARTY_MEMBER_STATE, 80) { }

            WorldPacket const* Write() override;
            void Initialize(Player const* player);

            bool ForEnemy = false;
            ObjectGuid MemberGuid;
            uint32 ChangeMask = 0;
            PartyMemberStats MemberStats;
        };

        class SetEveryoneIsAssistant final : public ClientPacket
        {
        public:
            SetEveryoneIsAssistant(WorldPacket&& packet) : ClientPacket(CMSG_SET_EVERYONE_IS_ASSISTANT, std::move(packet)) { }

            void Read() override;

            bool EveryoneIsAssistant = false;
        };

        class PartyCommandResult final : public ServerPacket
        {
        public:
            PartyCommandResult() : ServerPacket(SMSG_PARTY_COMMAND_RESULT, 4 + 1 + 4 + 4 + 8) { }

            WorldPacket const* Write() override;

            std::string Name;
            uint8 Command = 0u;
            uint8 Result = 0u;
            uint32 ResultData = 0u;
            ObjectGuid ResultGUID;
        };

        class PartyInviteClient final : public ClientPacket
        {
        public:
            PartyInviteClient(WorldPacket&& packet) : ClientPacket(CMSG_PARTY_INVITE, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            uint32 ProposedRoles = 0;
            uint32 TargetCfgRealmID = 0;
            std::string TargetName;
            std::string TargetRealm;
            ObjectGuid TargetGUID;
        };

        class PartyInvite final : public ServerPacket
        {
        public:
            PartyInvite() : ServerPacket(SMSG_PARTY_INVITE, 43) { }

            WorldPacket const* Write() override;

            void Initialize(Player* const inviter, int32 proposedRoles, bool canAccept);

            bool IsXRealm = false;
            bool MustBeBNetFriend = false;
            bool CanAccept = false;
            uint32 InviterCfgRealmID = 0;
            uint32 LfgCompletedMask = 0;
            uint32 ProposedRoles = 0;
            uint32 Timestamp = 0; // not in WoD client magic but 4.x sniffs send timestamp data
            std::string InviterRealmName;
            std::string InviterName;
            std::vector<uint32> LfgSlots;
            ObjectGuid InviterGUID;
        };

        class PartyInviteResponse final : public ClientPacket
        {
        public:
            PartyInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_PARTY_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            bool Accept = false;
            Optional<uint32> RolesDesired;
        };

        class GroupDecline final : public ServerPacket
        {
        public:
            GroupDecline(std::string const& name) : ServerPacket(SMSG_GROUP_DECLINE, name.size()), Name(name) { }

            WorldPacket const* Write() override;

            std::string Name;
        };

        struct PartyLFGInfo
        {
            uint8 MyLfgFlags = 0;
            uint32 LfgSlot = 0;
            bool LfgAborted = false;
        };

        struct PartyPlayerInfo
        {
            std::string Name;
            ObjectGuid Guid;
            uint8 Connected = 0;
            uint8 Subgroup = 0;
            uint8 Flags = 0;
            uint8 RolesAssigned = 0;
        };

       struct  PartyLootSettings
        {
            ObjectGuid LootMaster;
            uint8 LootMethod = 0;
            uint8 LootThreshold = 0;
        };

        struct PartyDifficultySettings
        {
            uint32 DungeonDifficulty = 0;
            uint32 RaidDifficulty = 0;
        };

        class PartyUpdate final : public ServerPacket
        {
        public:
            PartyUpdate() : ServerPacket(SMSG_PARTY_UPDATE) { }

            WorldPacket const* Write() override;

            uint8 PartyFlags = 0;
            uint8 Subgroup = 0;
            uint8 Flags = 0;
            uint8 RolesAssigned = 0;
            uint32 SequenceNum = 0;
            ObjectGuid LeaderGUID;
            ObjectGuid PartyGUID;
            std::vector<PartyPlayerInfo> PlayerList;
            PartyLootSettings LootSettings;
            PartyLFGInfo LfgInfo;
            PartyDifficultySettings DifficultySettings;
        };

        struct SummonRaidMemberValidateReason
        {
            SummonRaidMemberValidateReason(ObjectGuid const& member, int32 reasonCode) : Member(member), ReasonCode(reasonCode) { }

            ObjectGuid Member;
            int32 ReasonCode = 0;
        };

        class SummonRaidMemberValidateFailed final : public ServerPacket
        {
        public:
            SummonRaidMemberValidateFailed() : ServerPacket(SMSG_SUMMON_RAID_MEMBER_VALIDATE_FAILED, 4) { }

            SummonRaidMemberValidateFailed(ObjectGuid const& memberGuid, SummonRaidMemberValidateReasonCode reasonCode);

            WorldPacket const* Write() override;

            std::vector<SummonRaidMemberValidateReason> Members;
        };
    }
}

#endif // PartyPackets_h__
