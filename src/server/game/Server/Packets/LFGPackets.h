/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace LFG
    {
        /** Begin Structs */

        struct RideTicket
        {
            ObjectGuid RequesterGuid;
            int32 Id = 0;
            int32 Type = 0;
            uint32 Time = 0;
        };

        struct LFGBlackListSlot
        {
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

        struct LFGListBlacklistEntry
        {
            uint32 ActivityID = 0;
            uint32 Reason = 0;
        };

        struct LFGListBlacklist
        {
            std::vector<LFGListBlacklistEntry> Entries;
        };

        struct LfgPlayerQuestRewardItem
        {
            int32 ItemID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestRewardCurrency
        {
            int32 CurrencyID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestReward
        {
            uint32 Mask = 0;
            int32 RewardMoney = 0;
            int32 RewardXP = 0;
            std::vector<LfgPlayerQuestRewardItem> Item;
            std::vector<LfgPlayerQuestRewardCurrency> Currency;
            std::vector<LfgPlayerQuestRewardCurrency> BonusCurrency;
            bool UnkBit = true;
            uint32 UnkWoD62 = 0;
        };

        struct LfgPlayerDungeonInfo
        {
            uint32 Slot = 0;
            bool FirstReward = false;
            int32 CompletionQuantity = 0;
            int32 CompletionLimit = 0;
            int32 CompletionCurrencyID = 0;
            int32 SpecificQuantity = 0;
            int32 SpecificLimit = 0;
            int32 OverallQuantity = 0;
            int32 OverallLimit = 0;
            int32 PurseWeeklyQuantity = 0;
            int32 PurseWeeklyLimit = 0;
            int32 PurseQuantity = 0;
            int32 PurseLimit = 0;
            int32 Quantity = 0;
            uint32 CompletedMask = 0;
            bool ShortageEligible = false;
            std::vector<LfgPlayerQuestReward> ShortageReward;
            LfgPlayerQuestReward Rewards;

            uint32 ShortageRewardCount = 0;
        };

        struct LFGPlayerRewards
        {
            int32 RewardItem = 0;
            uint32 RewardItemQuantity = 0;
            int32 BonusCurrency = 0;
            bool IsCurrency = false;
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

        struct LFGListJoinRequest
        {
            uint32 ActivityID = 0;
            uint32 RequiredItemLevel = 0;
            std::string Name;
            std::string Comment;
            std::string VoiceChat;
        };

        struct PartyLFGInfo
        {
            uint8 MyLfgFlags = 0;
            uint32 LfgSlot = 0;
            uint32 MyLfgRandomSlot = 0;
            bool LfgAborted = false;
            uint8 MyLfgPartialClear = 0;
            float MyLfgGearDiff = 0.0f;
            uint8 MyLfgStrangerCount = 0;
            uint8 MyLfgKickVoteCount = 0;
            uint8 LfgBootCount = 0;
            bool MyLfgFirstReward = false;
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

        /** End Structs */

        class LFGJoinResult final : public ServerPacket
        {
        public:
            LFGJoinResult() : ServerPacket(SMSG_LFG_JOIN_RESULT) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
            std::vector<LFGBlackList> BlackList;
            uint8 ResultDetail = 0;
            RideTicket Ticket;
        };

        class LFGListJoinResult final : public ServerPacket
        {
        public:
            LFGListJoinResult() : ServerPacket(SMSG_LFG_LIST_JOIN_RESULT) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 ResultDetail = 0;
            uint8 Result = 0;
        };

        class LFGQueueStatus final : public ServerPacket
        {
        public:
            LFGQueueStatus() : ServerPacket(SMSG_LFG_QUEUE_STATUS) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint32 QueuedTime = 0;
            uint32 AvgWaitTime = 0;
            uint32 Slot = 0;
            uint32 AvgWaitTimeMe = 0;
            uint8 LastNeeded[3];
            uint32 AvgWaitTimeByRole[3];
        };

        struct LFGRoleCheckUpdateMember
        {
            ObjectGuid Guid;
            bool RoleCheckComplete = false;
            uint32 RolesDesired = 0;
            uint8 Level = 0;
        };

        class LFGRoleCheckUpdate final : public ServerPacket
        {
        public:
            LFGRoleCheckUpdate() : ServerPacket(SMSG_LFG_ROLE_CHECK_UPDATE) { }

            WorldPacket const* Write() override;

            bool IsBeginning = false;
            bool ShowRoleCheck = false;
            std::vector<LFGRoleCheckUpdateMember> Members;
            std::vector<uint32> JoinSlots;
            uint32 ActivityID = 0;
            uint64 BgQueueID = 0;
            uint8 PartyIndex = 0;
            uint8 RoleCheckStatus = 0;
        };

        class LFGUpdateStatus final : public ServerPacket
        {
        public:
            LFGUpdateStatus() : ServerPacket(SMSG_LFG_UPDATE_STATUS) { }

            WorldPacket const* Write() override;

            uint32 SlotsCount = 0;
            uint32 SuspendedPlayersCount = 0;

            bool IsParty = false;
            bool Joined = false;
            bool LfgJoined = false;
            bool NotifyUI = false;
            bool Queued = false;
            RideTicket Ticket;
            std::string Comment;
            std::vector<ObjectGuid> SuspendedPlayers;
            std::vector<uint32> Slots;
            uint32 RequestedRoles = 0;
            uint8 Needs[3];
            uint8 Reason = 0;
            uint8 SubType = 0;
        };

        class LFGListUpdateStatus final : public ServerPacket
        {
        public:
            LFGListUpdateStatus() : ServerPacket(SMSG_LFG_LIST_UPDATE_STATUS) { }

            WorldPacket const* Write() override;

            bool Listed = false;
            LFGListJoinRequest Request;
            uint32 Unk = 0; // Roles?
            uint8 Reason = 0;
            RideTicket Ticket;
        };

        class LFGListUpdateBlacklist final : public ServerPacket
        {
        public:
            LFGListUpdateBlacklist() : ServerPacket(SMSG_LFG_LIST_UPDATE_BLACKLIST) { }

            WorldPacket const* Write() override;

            uint32 BlacklistEntryCount = 0;
            LFGListBlacklist Blacklist;
        };

        class LFGProposalUpdate final : public ServerPacket
        {
        public:
            LFGProposalUpdate() : ServerPacket(SMSG_LFG_PROPOSAL_UPDATE) { }

            WorldPacket const* Write() override;

            uint32 PlayersCount = 0;
            bool ProposalSilent = false;
            std::vector<LFGProposalUpdatePlayer> Players;
            uint32 CompletedMask = 0;
            uint64 InstanceID = 0;
            bool ValidCompletedMask = false;
            uint32 Slot = 0;
            RideTicket Ticket;
            int8 State = 0;
            uint32 ProposalID = 0;
        };

        struct LFGSearchResultParty
        {
            ObjectGuid Guid;
            uint32 ChangeMask = 0;
            std::string Comment;
            uint64 InstanceID = 0;
            uint32 InstanceCompletedMask = 0;
            uint8 Needs[3];
        };

        struct LFGSearchResultPlayer
        {
            bool IsLeader = false;
            float AvgItemLevel = 0.0f;
            float Expertise = 0.0f;
            float GearRating = 0.0f;
            float Mp5 = 0.0f;
            float Mp5InCombat = 0.0f;
            ObjectGuid Guid;
            ObjectGuid PartyGuid;
            std::string Comment;
            uint32 Agility = 0;
            uint32 Area = 0;
            uint32 Armor = 0;
            uint32 AttackPower = 0;
            uint32 BlockRating = 0;
            uint32 BossKills = 0;
            uint32 ChangeMask = 0;
            uint32 CritMelee = 0;
            uint32 CritRanged = 0;
            uint32 CritSpell = 0;
            uint32 DefenseRating = 0;
            uint32 DodgeRating = 0;
            uint32 HasteRating = 0;
            uint32 InstanceCompletedMask = 0;
            uint32 MaxHealth = 0;
            uint32 MaxMana = 0;
            uint32 NativeRealmAddress = 0;
            uint32 ParryRating = 0;
            uint32 PlusHealing = 0;
            uint32 SpecID = 0;
            uint32 SpellDamage = 0;
            uint32 VirtualRealmAddress = 0;
            uint64 InstanceID = 0;
            uint8 ChrClass = 0;
            uint8 Level = 0;
            uint8 Race = 0;
            uint8 RolesDesired = 0;
            uint8 Status = 0;
        };

        class LFGSearchResults final : public ServerPacket
        {
        public:
            LFGSearchResults() : ServerPacket(SMSG_LFG_SEARCH_RESULTS) { }

            WorldPacket const* Write() override;

            bool Incremental = false;
            RideTicket Ticket;
            std::vector<LFGSearchResultParty> Parties;
            std::vector<LFGSearchResultPlayer> Players;
            std::vector<ObjectGuid> Removes;
            uint32 CountTotalParties = 0;
            uint32 CountTotalPlayers = 0;
            uint32 SlotID = 0;
            uint32 SlotType = 0;
        };

        class LFGSlotInvalid final : public ServerPacket
        {
        public:
            LFGSlotInvalid() : ServerPacket(SMSG_LFG_SLOT_INVALID) { }

            WorldPacket const* Write() override;

            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
            uint32 Reason = 0;
        };

        /* class LFGTeleportDenied final : public ServerPacket
        {
        LfgTeleportResult Reason;
        }; */

        class LFGOfferContinue final : public ServerPacket
        {
        public:
            LFGOfferContinue() : ServerPacket(SMSG_LFG_OFFER_CONTINUE) { }

            WorldPacket const* Write() override;

            uint32 Slot = 0;
        };

        class LFGBootPlayer final : public ServerPacket
        {
        public:
            LFGBootPlayer() : ServerPacket(SMSG_LFG_BOOT_PLAYER) { }

            WorldPacket const* Write() override;

            LfgBootInfo Info;
        };

        class LFGPartyInfo final : public ServerPacket
        {
        public:
            LFGPartyInfo() : ServerPacket(SMSG_LFG_PARTY_INFO) { }

            WorldPacket const* Write() override;

            std::vector<LFGBlackList> Player;
        };

        class LFGPlayerInfo final : public ServerPacket
        {
        public:
            LFGPlayerInfo() : ServerPacket(SMSG_LFG_PLAYER_INFO) { }

            WorldPacket const* Write() override;

            uint32 DungeonCount = 0;

            LFGBlackList BlackList;
            std::vector<LfgPlayerDungeonInfo> Dungeon;
        };

        class LFGPlayerReward final : public ServerPacket
        {
        public:
            LFGPlayerReward() : ServerPacket(SMSG_LFG_PLAYER_REWARD) { }

            WorldPacket const* Write() override;

            int32 RewardMoney = 0;
            uint32 QueuedSlot = 0;
            uint32 RewardsCount = 0;
            std::vector<LFGPlayerRewards> Rewards;
            int32 AddedXP = 0;
            uint32 ActualSlot = 0;
        };

        class LFGListJoin final : public ClientPacket
        {
        public:
            LFGListJoin(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_JOIN, std::move(packet)) { }

            void Read() override;

            LFGListJoinRequest Info;
        };

        class LFGListUpdateRequest final : public ClientPacket
        {
        public:
            LFGListUpdateRequest(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_UPDATE_REQUEST, std::move(packet)) { }

            void Read() override;

            LFGListJoinRequest Info;
            RideTicket Ticket;
        };

        class LFGListLeave final : public ClientPacket
        {
        public:
            LFGListLeave(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };

        class DfLeave final : public ClientPacket
        {
        public:
            DfLeave(WorldPacket&& packet) : ClientPacket(CMSG_DF_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };

        class DfSearchJoin final : public ClientPacket
        {
        public:
            DfSearchJoin(WorldPacket&& packet) : ClientPacket(CMSG_DF_SEARCH_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 Slot = 0;
        };

        class DfSearchLeave final : public ClientPacket
        {
        public:
            DfSearchLeave(WorldPacket&& packet) : ClientPacket(CMSG_DF_SEARCH_LEAVE, std::move(packet)) { }

            void Read() override;

            uint32 Slot = 0;
        };

        class DfGetSystemInfo final : public ClientPacket
        {
        public:
            DfGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_DF_GET_SYSTEM_INFO, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            bool Player = false;
        };

        class DfSetComment final : public ClientPacket
        {
        public:
            DfSetComment(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_COMMENT, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
            std::string Comment;
        };

        class DfSetRoles final : public ClientPacket
        {
        public:
            DfSetRoles(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_ROLES, std::move(packet)) { }

            void Read() override;

            uint32 RolesDesired = 0;
            uint8 PartyIndex = 0;
        };

        // Is this opcode not in TC yet? Could someone point me to what I'm probably missing?
        /*class DfSetNeeds final : public ClientPacket
        {
        public:
        DfSetNeeds(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_NEEDS, std::move(packet)) { }

        void Read() override;

        bool Delta = false;
        RideTicket Ticket;
        uint32 Needs[3];
        };*/

        class DfBootPlayerVote final : public ClientPacket
        {
        public:
            DfBootPlayerVote(WorldPacket&& packet) : ClientPacket(CMSG_DF_BOOT_PLAYER_VOTE, std::move(packet)) { }

            void Read() override;

            bool Vote = false;
        };

        class DfTeleport final : public ClientPacket
        {
        public:
            DfTeleport(WorldPacket&& packet) : ClientPacket(CMSG_DF_TELEPORT, std::move(packet)) { }

            void Read() override;

            bool TeleportOut = false;
        };

        class DfProposalResponse final : public ClientPacket
        {
        public:
            DfProposalResponse(WorldPacket&& packet) : ClientPacket(CMSG_DF_PROPOSAL_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 ProposalID = 0;
            RideTicket Ticket;
            bool Accepted = false;
            uint64 InstanceID = 0;
        };

        class DfJoin final : public ClientPacket
        {
        public:
            DfJoin(WorldPacket&& packet) : ClientPacket(CMSG_DF_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 slotsCount = 0;

            bool QueueAsGroup = false;
            uint32 Roles = 0;
            uint8 PartyIndex = 0;
            std::string Comment;
            std::vector<uint32> Slots;
            uint32 Needs[3];
        };

        class DfGetJoinStatus final : public ClientPacket
        {
        public:
            DfGetJoinStatus(WorldPacket&& packet) : ClientPacket(CMSG_DF_GET_JOIN_STATUS, std::move(packet)) { }

            void Read() override { }
        };

        class LFGListGetStatus final : public ClientPacket
        {
        public:
            LFGListGetStatus(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_GET_STATUS, std::move(packet)) { }

            void Read() override { }
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& clientBlackList);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& clientBlackListSlot);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestRewards);
ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest& joinRequest);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest const& joinRequest);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& blackListSlot);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListBlacklist const& listBlackList);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListBlacklistEntry const& listBlackListEntry);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& item);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& currency);
#endif // LFGPackets_h__
