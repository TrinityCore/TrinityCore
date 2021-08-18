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

#ifndef LFGPackets_h__
#define LFGPackets_h__

#include "Packet.h"
#include "LFGPacketsCommon.h"
#include "Optional.h"
#include <array>

namespace lfg
{
    enum LfgTeleportResult : uint8;
}

namespace WorldPackets
{
    namespace LFG
    {
        class LFGJoin final : public ClientPacket
        {
        public:
            LFGJoin(WorldPacket&& packet) : ClientPacket(CMSG_LFG_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 Roles = 0;
            std::string Comment;
            Array<uint32, 50> Slots;
            std::array<uint32, 3> Needs = { };
        };

        class LFGLeave final : public ClientPacket
        {
        public:
            LFGLeave(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LEAVE, std::move(packet)) { }

            void Read() override;

            uint32 Roles = 0;
            RideTicket Ticket;
        };

        class LFGProposalResponse final : public ClientPacket
        {
        public:
            LFGProposalResponse(WorldPacket&& packet) : ClientPacket(CMSG_LFG_PROPOSAL_RESULT, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
            uint64 InstanceID = 0;
            uint32 ProposalID = 0;
            bool Accepted = false;
        };

        class LFGSetRoles final : public ClientPacket
        {
        public:
            LFGSetRoles(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_ROLES, std::move(packet)) { }

            void Read() override;

            uint32 RolesDesired = 0;
        };

        class LFGSetComment final : public ClientPacket
        {
        public:
            LFGSetComment(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_COMMENT, std::move(packet)) { }

            void Read() override;

            std::string Comment;
        };

        class LFGBootPlayerVote final : public ClientPacket
        {
        public:
            LFGBootPlayerVote(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_BOOT_VOTE, std::move(packet)) { }

            void Read() override;

            bool Vote = false;
        };

        class LFGTeleport final : public ClientPacket
        {
        public:
            LFGTeleport(WorldPacket&& packet) : ClientPacket(CMSG_LFG_TELEPORT, std::move(packet)) { }

            void Read() override;

            bool TeleportOut = false;
        };

        class LFGGetSystemInfo final : public ClientPacket
        {
        public:
            LFGGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LOCK_INFO_REQUEST, std::move(packet)) { }

            void Read() override;

            bool Player = false;
        };

        struct LFGBlackListSlot
        {
            LFGBlackListSlot() { }
            LFGBlackListSlot(uint32 slot, uint32 reason, int32 subReason1, int32 subReason2)
                : Slot(slot), Reason(reason), SubReason1(subReason1), SubReason2(subReason2) { }

            uint32 Slot = 0;
            uint32 Reason = 0;
            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
        };

        struct LFGBlackList
        {
            Optional<ObjectGuid> PlayerGuid;
            std::vector<LFGBlackListSlot> Slot;
        };

        struct LfgPlayerQuestRewardItem
        {
            LfgPlayerQuestRewardItem() { }
            LfgPlayerQuestRewardItem(int32 itemId, int32 quantity) : ItemID(itemId), Quantity(quantity) { }

            int32 ItemID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestRewardCurrency
        {
            LfgPlayerQuestRewardCurrency() { }
            LfgPlayerQuestRewardCurrency(int32 currencyID, int32 quantity) : CurrencyID(currencyID), Quantity(quantity) { }

            int32 CurrencyID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestReward
        {
            int32 RewardMoney = 0;                                      // Only used by SMSG_LFG_PLAYER_INFO
            int32 RewardXP = 0;
            std::vector<LfgPlayerQuestRewardItem> Item;
            std::vector<LfgPlayerQuestRewardCurrency> Currency;         // Only used by SMSG_LFG_PLAYER_INFO
            Optional<int32> Honor;                                      // Only used by SMSG_REQUEST_PVP_REWARDS_RESPONSE
        };

        struct LfgPlayerDungeonInfo
        {
            uint32 Slot = 0;
            uint32 CompletionQuantity = 0;
            uint32 CompletionLimit = 0;
            uint32 CompletionCurrencyID = 0;
            uint32 SpecificQuantity = 0;
            uint32 SpecificLimit = 0;
            uint32 OverallQuantity = 0;
            uint32 OverallLimit = 0;
            uint32 PurseWeeklyQuantity = 0;
            uint32 PurseWeeklyLimit = 0;
            uint32 PurseQuantity = 0;
            uint32 PurseLimit = 0;
            uint32 Quantity = 0;
            uint32 CompletedMask = 0;
            uint32 ShortageRoleMask = 0;
            bool ShortageEligible = false;
            bool FirstReward = false;
            LfgPlayerQuestReward Rewards;
            LfgPlayerQuestReward ShortageReward;
        };

        class LFGPlayerInfo final : public ServerPacket
        {
        public:
            LFGPlayerInfo() : ServerPacket(SMSG_LFG_PLAYER_INFO) { }

            WorldPacket const* Write() override;

            LFGBlackList BlackList;
            std::vector<LfgPlayerDungeonInfo> Dungeon;
        };

        class LFGPartyInfo final : public ServerPacket
        {
        public:
            LFGPartyInfo() : ServerPacket(SMSG_LFG_PARTY_INFO) { }

            WorldPacket const* Write() override;
            std::vector<LFGBlackList> Player;
        };

        class LFGUpdateStatus final : public ServerPacket
        {
        public:
            LFGUpdateStatus() : ServerPacket(SMSG_LFG_UPDATE_STATUS) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 Reason = 0;
            std::vector<uint32> Slots;
            uint32 RequestedRoles = 0;
            std::vector<ObjectGuid> SuspendedPlayers;
            std::string Comment;
            bool IsParty = false;
            bool Joined = false;
            bool LfgJoined = false;
            bool Queued = false;
        };

        class RoleChosen final : public ServerPacket
        {
        public:
            RoleChosen() : ServerPacket(SMSG_LFG_ROLE_CHOSEN, 16 + 1 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            uint32 RoleMask = 0;
            bool Accepted = false;
        };

        struct LFGRoleCheckUpdateMember
        {
            LFGRoleCheckUpdateMember() { }
            LFGRoleCheckUpdateMember(ObjectGuid guid, uint32 rolesDesired, uint8 level, bool roleCheckComplete)
                : Guid(guid), RolesDesired(rolesDesired), Level(level), RoleCheckComplete(roleCheckComplete) { }

            ObjectGuid Guid;
            uint32 RolesDesired = 0;
            uint8 Level = 0;
            bool RoleCheckComplete = false;
        };

        class LFGRoleCheckUpdate final : public ServerPacket
        {
        public:
            LFGRoleCheckUpdate() : ServerPacket(SMSG_LFG_ROLE_CHECK_UPDATE) { }

            WorldPacket const* Write() override;

            uint8 RoleCheckStatus = 0;
            std::vector<uint32> JoinSlots;
            std::vector<LFGRoleCheckUpdateMember> Members;
            bool IsBeginning = false;
        };

        struct LFGJoinBlackListSlot
        {
            LFGJoinBlackListSlot() { }
            LFGJoinBlackListSlot(int32 slot, int32 reason, int32 subReason1, int32 subReason2)
                : Slot(slot), Reason(reason), SubReason1(subReason1), SubReason2(subReason2) { }

            int32 Slot = 0;
            int32 Reason = 0;
            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
        };

        struct LFGJoinBlackList
        {
            ObjectGuid Guid;
            std::vector<LFGJoinBlackListSlot> Slots;
        };

        class LFGJoinResult final : public ServerPacket
        {
        public:
            LFGJoinResult() : ServerPacket(SMSG_LFG_JOIN_RESULT) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 Result = 0;
            uint8 ResultDetail = 0;
            std::vector<LFGJoinBlackList> BlackList;
        };

        class LFGQueueStatus final : public ServerPacket
        {
        public:
            LFGQueueStatus() : ServerPacket(SMSG_LFG_QUEUE_STATUS, 16 + 4 + 4 + 4 + 4 + 4 + 4 + 4 * 3 + 3 + 4) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint32 Slot = 0;
            uint32 AvgWaitTimeMe = 0;
            uint32 AvgWaitTime = 0;
            uint32 AvgWaitTimeByRole[3] = {};
            uint8 LastNeeded[3] = {};
            uint32 QueuedTime = 0;
        };

        struct LFGPlayerRewards
        {
            LFGPlayerRewards() { }
            LFGPlayerRewards(int32 rewardItem, uint32 rewardItemQuantity, bool isCurrency)
                : RewardItem(rewardItem), RewardItemQuantity(rewardItemQuantity), IsCurrency(isCurrency) { }

            int32 RewardItem = 0;
            uint32 RewardItemQuantity = 0;
            bool IsCurrency = false;
        };

        class LFGPlayerReward final : public ServerPacket
        {
        public:
            LFGPlayerReward() : ServerPacket(SMSG_LFG_PLAYER_REWARD) { }

            WorldPacket const* Write() override;

            uint32 QueuedSlot = 0;
            uint32 ActualSlot = 0;
            int32 RewardMoney = 0;
            int32 AddedXP = 0;
            std::vector<LFGPlayerRewards> Rewards;
        };

        struct LfgBootInfo
        {
            bool VoteInProgress = false;
            bool VotePassed = false;
            bool MyVoteCompleted = false;
            bool MyVote = false;
            ObjectGuid Target;
            uint32 TotalVotes = 0;
            uint32 BootVotes = 0;
            int32 TimeLeft = 0;
            uint32 VotesNeeded = 0;
            std::string Reason;
        };

        class LfgBootPlayer final : public ServerPacket
        {
        public:
            LfgBootPlayer() : ServerPacket(SMSG_LFG_BOOT_PROPOSAL_UPDATE) { }

            WorldPacket const* Write() override;

            LfgBootInfo Info;
        };

        struct LFGProposalUpdatePlayer
        {
            uint32 Roles = 0;
            bool Me = false;
            bool SameParty = false;
            bool MyParty = false;
            bool Responded = false;
            bool Accepted = false;
        };

        class LFGProposalUpdate final : public ServerPacket
        {
        public:
            LFGProposalUpdate() : ServerPacket(SMSG_LFG_PROPOSAL_UPDATE) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint64 InstanceID = 0;
            uint32 ProposalID = 0;
            uint32 Slot = 0;
            int8 State = 0;
            uint32 CompletedMask = 0;
            uint8 Unused = 0;
            bool ProposalSilent = false;
            std::vector<LFGProposalUpdatePlayer> Players;
        };

        class LFGDisabled final : public ServerPacket
        {
        public:
            LFGDisabled() : ServerPacket(SMSG_LFG_DISABLED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class LFGOfferContinue final : public ServerPacket
        {
        public:
            LFGOfferContinue(uint32 slot) : ServerPacket(SMSG_LFG_OFFER_CONTINUE, 4), Slot(slot) { }

            WorldPacket const* Write() override;

            uint32 Slot = 0;
        };

        class LFGTeleportDenied final : public ServerPacket
        {
        public:
            LFGTeleportDenied(lfg::LfgTeleportResult reason) : ServerPacket(SMSG_LFG_TELEPORT_DENIED, 4), Reason(reason) { }

            WorldPacket const* Write() override;

            lfg::LfgTeleportResult Reason;
        };

        struct ClientLFGSearchResultParty
        {
            ObjectGuid Guid;
            uint32 ChangeMask = 0;
            std::string Comment;
            ObjectGuid InstanceID;
            uint32 InstanceCompletedMask = 0;
            uint8 Needs[3] = { };
        };

        struct ClientLFGSearchResultPlayer
        {
            ObjectGuid Guid;
            uint32 ChangeMask = 0;
            uint8 Level = 0;
            uint8 ChrClass = 0;
            uint8 Race = 0;
            uint32 Armor = 0;
            uint32 SpellDamage = 0;
            uint32 PlusHealing = 0;
            uint32 CritMelee = 0;
            uint32 CritRanged = 0;
            uint32 CritSpell = 0;
            float Mp5 = 0.0f;
            float Mp5InCombat = 0.0f;
            uint32 AttackPower = 0;
            uint32 Agility = 0;
            uint32 MaxHealth = 0;
            uint32 MaxMana = 0;
            uint32 BossKills = 0;
            float GearRating = 0.0f;
            float AvgItemLevel = 0.0f;
            uint32 DefenseRating = 0;
            uint32 DodgeRating = 0;
            uint32 BlockRating = 0;
            uint32 ParryRating = 0;
            uint32 HasteRating = 0;
            float Expertise = 0.0f;
            uint32 SpecID = 0;
            std::string Comment;
            bool IsLeader = false;
            ObjectGuid PartyGuid;
            uint8 RolesDesired = 0;
            uint32 Area = 0;
            uint8 Status = 0;
            ObjectGuid InstanceID;
            uint32 InstanceCompletedMask = 0;
            int32 FreeTalentPoints = 0;
            std::array<int8, 3> Talents = { };
        };

        class LFGSearchResults final : public ServerPacket
        {
        public:
            LFGSearchResults() : ServerPacket(SMSG_LFG_SEARCH_RESULT, 4) { }

            WorldPacket const* Write() override;

            bool Incremental = false;
            std::vector<ObjectGuid> Removes;
            RideTicket Ticket;
            uint32 SlotID = 0;
            uint32 CountTotalParties = 0;
            uint32 CountTotalPlayers = 0;
            uint32 SlotType = 0;
            std::vector<ClientLFGSearchResultParty> Parties;
            std::vector<ClientLFGSearchResultPlayer> Players;
        };
    }
}

#endif // LFGPackets_h__
