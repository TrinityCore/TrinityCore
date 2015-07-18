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

        struct ClientLFGBlackListSlot
        {
            int32 Slot = 0;
            int32 Reason = 0;
            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
        };

        struct ClientLFGBlackList
        {
            ObjectGuid Guid;
            std::vector<ClientLFGBlackListSlot> Slots;
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

        struct CliPartyLFGInfo
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

        struct ClientLFGProposalUpdatePlayer
        {
            uint32 Roles = 0;
            bool Me = false;
            bool SameParty = false;
            bool MyParty = false;
            bool Responded = false;
            bool Accepted = false;
        };

        /** End Structs */

        class ClientLFGJoinResult final : public ServerPacket
        {
        public:
            ClientLFGJoinResult() : ServerPacket(SMSG_LFG_JOIN_RESULT) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
            std::vector<ClientLFGBlackList> BlackList;
            uint8 ResultDetail = 0;
            RideTicket Ticket;
        };

        class ClientLFGListJoinResult final : public ServerPacket
        {
        public:
            ClientLFGListJoinResult() : ServerPacket(SMSG_LFG_LIST_JOIN_RESULT) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 ResultDetail = 0;
            uint8 Result = 0;
        };

        class ClientLFGQueueStatus final : public ServerPacket
        {
        public:
            ClientLFGQueueStatus() : ServerPacket(SMSG_LFG_QUEUE_STATUS) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint32 QueuedTime = 0;
            uint32 AvgWaitTime = 0;
            uint32 Slot = 0;
            uint32 AvgWaitTimeMe = 0;
            uint8 LastNeeded[3];
            uint32 AvgWaitTimeByRole[3];
        };

        struct ClientLFGRoleCheckUpdateMember
        {
            ObjectGuid Guid;
            bool RoleCheckComplete = false;
            uint32 RolesDesired = 0;
            uint8 Level = 0;
        };

        class ClientLFGRoleCheckUpdate final : public ServerPacket
        {
        public:
            ClientLFGRoleCheckUpdate() : ServerPacket(SMSG_LFG_ROLE_CHECK_UPDATE) { }

            WorldPacket const* Write() override;

            bool IsBeginning = false;
            bool ShowRoleCheck = false;
            std::vector<ClientLFGRoleCheckUpdateMember> Members;
            std::vector<uint32> JoinSlots;
            uint32 ActivityID = 0;
            uint32 JoinSlotsCount = 0;
            uint32 MembersCount = 0;
            uint64 BgQueueID = 0;
            uint8 PartyIndex = 0;
            uint8 RoleCheckStatus = 0;
        };

        class ClientLFGUpdateStatus final : public ServerPacket
        {
        public:
            ClientLFGUpdateStatus() : ServerPacket(SMSG_LFG_UPDATE_STATUS) { }

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

        class ClientLFGListUpdateStatus final : public ServerPacket
        {
        public:
            ClientLFGListUpdateStatus() : ServerPacket(SMSG_LFG_LIST_UPDATE_STATUS) { }

            WorldPacket const* Write() override;

            bool Listed = false;
            LFGListJoinRequest Request;
            uint32 Unk = 0; // Roles?
            uint8 Reason = 0;
            RideTicket Ticket;
        };

        class ClientLFGListUpdateBlacklist final : public ServerPacket
        {
        public:
            ClientLFGListUpdateBlacklist() : ServerPacket(SMSG_LFG_LIST_UPDATE_BLACKLIST) { }

            WorldPacket const* Write() override;

            uint32 BlacklistEntryCount = 0;
            LFGListBlacklist Blacklist;
        };

        class ClientLFGProposalUpdate final : public ServerPacket
        {
        public:
            ClientLFGProposalUpdate() : ServerPacket(SMSG_LFG_PROPOSAL_UPDATE) { }

            WorldPacket const* Write() override;

            uint32 PlayersCount = 0;
            bool ProposalSilent = false;
            std::vector<ClientLFGProposalUpdatePlayer> Players;
            uint32 CompletedMask = 0;
            uint64 InstanceID = 0;
            bool ValidCompletedMask = false;
            uint32 Slot = 0;
            RideTicket Ticket;
            int8 State = 0;
            uint32 ProposalID = 0;
        };

        struct ClientLFGSearchResultParty
        {
            ObjectGuid Guid;
            uint32 ChangeMask = 0;
            std::string Comment;
            uint64 InstanceID = 0;
            uint32 InstanceCompletedMask = 0;
            uint8 Needs[3];
        };

        struct ClientLFGSearchResultPlayer
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

        class ClientLFGSearchResults final : public ServerPacket
        {
        public:
            ClientLFGSearchResults() : ServerPacket(SMSG_LFG_SEARCH_RESULTS) { }

            WorldPacket const* Write() override;

            bool Incremental = false;
            RideTicket Ticket;
            std::vector<ClientLFGSearchResultParty> Parties;
            std::vector<ClientLFGSearchResultPlayer> Players;
            std::vector<ObjectGuid> Removes;
            uint32 CountTotalParties = 0;
            uint32 CountTotalPlayers = 0;
            uint32 SlotID = 0;
            uint32 SlotType = 0;
        };

        class ClientLFGSlotInvalid final : public ServerPacket
        {
        public:
            ClientLFGSlotInvalid() : ServerPacket(SMSG_LFG_SLOT_INVALID) { }

            WorldPacket const* Write() override;

            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
            uint32 Reason = 0;
        };

        /* class ClientLFGTeleportDenied final : public ServerPacket
        {
        LfgTeleportResult Reason;
        }; */

        class ClientLFGOfferContinue final : public ServerPacket
        {
        public:
            ClientLFGOfferContinue() : ServerPacket(SMSG_LFG_OFFER_CONTINUE) { }

            WorldPacket const* Write() override;

            uint32 Slot = 0;
        };

        class ClientLfgBootPlayer final : public ServerPacket
        {
        public:
            ClientLfgBootPlayer() : ServerPacket(SMSG_LFG_BOOT_PLAYER) { }

            WorldPacket const* Write() override;

            LfgBootInfo Info;
        };

        class ClientLfgPartyInfo final : public ServerPacket
        {
        public:
            ClientLfgPartyInfo() : ServerPacket(SMSG_LFG_PARTY_INFO) { }

            WorldPacket const* Write() override;

            std::vector<LFGBlackList> Player;
        };

        class ClientLfgPlayerInfo final : public ServerPacket
        {
        public:
            ClientLfgPlayerInfo() : ServerPacket(SMSG_LFG_PLAYER_INFO) { }

            WorldPacket const* Write() override;

            LFGBlackList BlackList;
            std::vector<LfgPlayerDungeonInfo> Dungeon;
        };

        class ClientLFGPlayerReward final : public ServerPacket
        {
        public:
            ClientLFGPlayerReward() : ServerPacket(SMSG_LFG_PLAYER_REWARD) { }

            WorldPacket const* Write() override;

            int32 RewardMoney = 0;
            uint32 QueuedSlot = 0;
            uint32 RewardsCount = 0;
            std::vector<LFGPlayerRewards> Rewards;
            int32 AddedXP = 0;
            uint32 ActualSlot = 0;
        };

        class UserClientLFGListJoin final : public ClientPacket
        {
        public:
            UserClientLFGListJoin(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_JOIN, std::move(packet)) { }

            void Read() override;

            LFGListJoinRequest Info;
        };

        class UserClientLFGListUpdateRequest final : public ClientPacket
        {
        public:
            UserClientLFGListUpdateRequest(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_UPDATE_REQUEST, std::move(packet)) { }

            void Read() override;

            LFGListJoinRequest Info;
            RideTicket Ticket;
        };

        class UserClientLFGListLeave final : public ClientPacket
        {
        public:
            UserClientLFGListLeave(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LIST_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };

        class UserClientDFLeave final : public ClientPacket
        {
        public:
            UserClientDFLeave(WorldPacket&& packet) : ClientPacket(CMSG_DF_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };

        class UserClientDFSearchJoin final : public ClientPacket
        {
        public:
            UserClientDFSearchJoin(WorldPacket&& packet) : ClientPacket(CMSG_DF_SEARCH_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 Slot = 0;
        };

        class UserClientDFSearchLeave final : public ClientPacket
        {
        public:
            UserClientDFSearchLeave(WorldPacket&& packet) : ClientPacket(CMSG_DF_SEARCH_LEAVE, std::move(packet)) { }

            void Read() override;

            uint32 Slot = 0;
        };

        class UserClientDFGetSystemInfo final : public ClientPacket
        {
        public:
            UserClientDFGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_DF_GET_SYSTEM_INFO, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            bool Player = false;
        };

        class UserClientDFSetComment final : public ClientPacket
        {
        public:
            UserClientDFSetComment(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_COMMENT, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
            std::string Comment;
        };

        class UserClientDFSetRoles final : public ClientPacket
        {
        public:
            UserClientDFSetRoles(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_ROLES, std::move(packet)) { }

            void Read() override;

            uint32 RolesDesired = 0;
            uint8 PartyIndex = 0;
        };

        // Is this opcode not in TC yet? Could someone point me to what I'm probably missing?
        /*class UserClientDFSetNeeds final : public ClientPacket
        {
        public:
        UserClientDFSetNeeds(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_NEEDS, std::move(packet)) { }

        void Read() override;

        bool Delta = false;
        RideTicket Ticket;
        uint32 Needs[3];
        };*/

        class UserClientDFBootPlayerVote final : public ClientPacket
        {
        public:
            UserClientDFBootPlayerVote(WorldPacket&& packet) : ClientPacket(CMSG_DF_BOOT_PLAYER_VOTE, std::move(packet)) { }

            void Read() override;

            bool Vote = false;
        };

        class UserClientDFTeleport final : public ClientPacket
        {
        public:
            UserClientDFTeleport(WorldPacket&& packet) : ClientPacket(CMSG_DF_TELEPORT, std::move(packet)) { }

            void Read() override;

            bool TeleportOut = false;
        };

        class UserClientDFProposalResponse final : public ClientPacket
        {
        public:
            UserClientDFProposalResponse(WorldPacket&& packet) : ClientPacket(CMSG_DF_PROPOSAL_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 ProposalID = 0;
            RideTicket Ticket;
            bool Accepted = false;
            uint64 InstanceID = 0;
        };

        class UserClientDFJoin final : public ClientPacket
        {
        public:
            UserClientDFJoin(WorldPacket&& packet) : ClientPacket(CMSG_DF_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 slotsCount = 0;

            bool QueueAsGroup = false;
            uint32 Roles = 0;
            uint8 PartyIndex = 0;
            std::string Comment;
            std::vector<uint32> Slots;
            uint32 Needs[3];
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgBootInfo const& bootInfo);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerDungeonInfo const& playerDungeonInfo);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGPlayerRewards const& playerRewards);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGBlackList const& clientBlackList);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGBlackListSlot const& clientBlackListSlot);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestRewards);
ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest& joinRequest);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest const& joinRequest);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& blackList);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& blackListSlot);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListBlacklist const& listBlackList);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListBlacklistEntry const& listBlackListEntry);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& item);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& currency);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGProposalUpdatePlayer const& update);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGSearchResultParty const& party);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGSearchResultPlayer const& player);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGRoleCheckUpdateMember const& member);
#endif // LFGPackets_h__
