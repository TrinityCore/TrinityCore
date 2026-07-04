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

#ifndef TRINITYCORE_QUEST_PACKETS_H
#define TRINITYCORE_QUEST_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"
#include "QuestDef.h"

namespace WorldPackets
{
    namespace Quest
    {
        class QuestGiverStatusQuery final : public ClientPacket
        {
        public:
            explicit QuestGiverStatusQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUESTGIVER_STATUS_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
        };

        // Empty packet, server replies with quest giver status of visible creatures
        class QuestGiverStatusMultipleQuery final : public ClientPacket
        {
        public:
            explicit QuestGiverStatusMultipleQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        struct QuestGiverInfo
        {
            QuestGiverInfo() { }
            QuestGiverInfo(ObjectGuid const& guid, ::QuestGiverStatus status)
                : Guid(guid), Status(status) { }

            ObjectGuid Guid;
            ::QuestGiverStatus Status = DIALOG_STATUS_NONE;
        };

        class QuestGiverStatus final : public ServerPacket
        {
        public:
            explicit QuestGiverStatus() : ServerPacket(SMSG_QUESTGIVER_STATUS, 8 + 1) { }

            WorldPacket const* Write() override;

            QuestGiverInfo QuestGiver;
        };

        class QuestGiverStatusMultiple final : public ServerPacket
        {
        public:
            explicit QuestGiverStatusMultiple() : ServerPacket(SMSG_QUESTGIVER_STATUS_MULTIPLE, 4) { }

            WorldPacket const* Write() override;

            std::vector<QuestGiverInfo> QuestGiver;
        };

        class QueryQuestInfo final : public ClientPacket
        {
            public:
                QueryQuestInfo(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 QuestID = 0;
        };

        struct QuestInfoChoiceItem
        {
            uint32 ItemID = 0;
            uint32 Quantity = 0;
        };

        struct QuestInfo
        {
            uint32 QuestID                  = 0;
            uint32 QuestType                = 0;    // Accepted values: 0, 1 or 2. 0 == IsAutoComplete() (skip objectives/details)
            int32  QuestLevel               = 0;    // may be -1, static data, in other cases must be used dynamic level: Player::GetQuestLevel (0 is not known, but assuming this is no longer valid for quest intended for client)
            uint32 QuestMinLevel            = 0;
            int32  QuestSortID              = 0;    // zone or sort to display in quest log
            uint32 QuestInfoID              = 0;
            uint32 SuggestedGroupNum        = 0;
            int32  AllowableRaces           = -1;

            uint32 RequiredFactionId[PVP_TEAMS_COUNT]  = { };  // shown in quest log as part of quest objective (same/opposite faction)
            int32  RequiredFactionValue[PVP_TEAMS_COUNT]  = { };  // shown in quest log as part of quest objective (same/opposite faction)

            uint32 RewardNextQuest          = 0;    // client will request this quest from NPC, if not 0
            uint32 RewardXPDifficulty       = 0;    // used for calculating rewarded experience
            int32  RewardMoney              = 0;    // reward money (below max lvl)
            uint32 RewardBonusMoney         = 0;    // used in XP calculation at client
            uint32 RewardDisplaySpell       = 0;    // reward spell, this spell will be displayed (icon) (cast if RewSpellCast == 0)
            int32  RewardSpell              = 0;
            uint32 RewardHonor              = 0;
            float RewardKillHonor           = 0.0f;
            uint32 StartItem                = 0;
            uint32 Flags                    = 0;
            uint32 RewardTitle              = 0;    // new 2.4.0, player gets this title (id from CharTitles)
            uint32 RequiredPlayerKills      = 0;
            uint32 RewardTalents            = 0;
            int32  RewardArenaPoints        = 0;
            uint32 RewardFactionFlags       = 0;

            uint32 RewardItems[QUEST_REWARD_ITEM_COUNT] = { };
            uint32 RewardAmount[QUEST_REWARD_ITEM_COUNT] = { };
            QuestInfoChoiceItem UnfilteredChoiceItems[QUEST_REWARD_CHOICES_COUNT];
            uint32 RewardFactionID[QUEST_REWARD_REPUTATIONS_COUNT] = { };
            int32  RewardFactionValue[QUEST_REWARD_REPUTATIONS_COUNT] = { };
            int32  RewardFactionOverride[QUEST_REWARD_REPUTATIONS_COUNT] = { };

            uint32 POIContinent             = 0;
            float  POIx                     = 0.0f;
            float  POIy                     = 0.0f;
            uint32 POIPriority              = 0;
            std::string LogTitle;
            std::string LogDescription;
            std::string QuestDescription;
            std::string AreaDescription;
            std::string QuestCompletionLog;

            int32  RequiredNpcOrGo[QUEST_OBJECTIVES_COUNT] = { };   // >0 Creature <0 Gameobject
            uint32 RequiredNpcOrGoCount[QUEST_OBJECTIVES_COUNT] = { };

            uint32 ItemDrop[QUEST_ITEM_DROP_COUNT] = { };
            uint32 ItemDropQuantity[QUEST_ITEM_DROP_COUNT] = { };

            uint32 RequiredItemId[QUEST_ITEM_OBJECTIVES_COUNT] = { };
            uint32 RequiredItemCount[QUEST_ITEM_OBJECTIVES_COUNT] = { };

            std::string ObjectiveText[QUEST_OBJECTIVES_COUNT];
        };

        class QueryQuestInfoResponse final : public ServerPacket
        {
            public:
                QueryQuestInfoResponse() : ServerPacket(SMSG_QUEST_QUERY_RESPONSE, 2000) { }

                WorldPacket const* Write() override;

                QuestInfo Info;
        };

        struct QuestChoiceItem
        {
            QuestChoiceItem(uint32 itemID, uint32 quantity, uint32 displayID) : ItemID(itemID), Quantity(quantity),
                                                                                DisplayID(displayID) { }
            uint32 ItemID = 0;
            uint32 Quantity = 0;
            uint32 DisplayID = 0;
        };

        struct QuestRewards
        {
            std::vector<QuestChoiceItem> UnfilteredChoiceItems;
            std::vector<QuestChoiceItem> RewardItems;
            uint32 RewardMoney = 0;
            uint32 RewardXPDifficulty = 0;
            uint32 RewardHonor = 0;
            float RewardKillHonor = 0.f;
            uint32 RewardDisplaySpell = 0;
            int32 RewardSpell = 0;
            uint32 RewardTitleId = 0;
            uint32 RewardTalents = 0;
            uint32 RewardArenaPoints = 0;
            uint32 RewardFactionFlags = 0;
            std::array<uint32, QUEST_REWARD_REPUTATIONS_COUNT> RewardFactionID = { };
            std::array<int32, QUEST_REWARD_REPUTATIONS_COUNT> RewardFactionValue = { };
            std::array<int32, QUEST_REWARD_REPUTATIONS_COUNT> RewardFactionOverride = { };
        };

        struct QuestDescEmote
        {
            QuestDescEmote(int32 type, uint32 delay) : Type(type), Delay(delay) { }
            uint32 Type;
            uint32 Delay;
        };

        class QuestGiverQuestDetails final : public ServerPacket
        {
        public:
            QuestGiverQuestDetails() : ServerPacket(SMSG_QUEST_GIVER_QUEST_DETAILS, 1000) { }

            WorldPacket const* Write() override;

            ObjectGuid QuestGiverGUID;
            ObjectGuid InformUnit;
            uint32 QuestID = 0;
            std::string QuestTitle;
            std::string DescriptionText;
            std::string LogDescription;
            bool AutoLaunched = false;
            uint32 Flags = 0;
            uint32 SuggestedGroupNum = 0;
            bool StartCheat = false;
            QuestRewards Rewards;
            std::vector<QuestDescEmote> DescEmotes;
        };

        struct QuestObjectiveCollect
        {
            int32 ObjectID = 0;
            int32 Amount = 0;
            uint32 DisplayID = 0;
        };

        class QuestGiverRequestItems final : public ServerPacket
        {
        public:
            explicit QuestGiverRequestItems() : ServerPacket(SMSG_QUESTGIVER_REQUEST_ITEMS, 300) { }

            WorldPacket const* Write() override;

            ObjectGuid QuestGiverGUID;
            int32 QuestID               = 0;
            int32 CompEmoteDelay        = 0;
            int32 CompEmoteType         = 0;
            bool AutoLaunched           = false;
            int32 SuggestPartyMembers   = 0;
            int32 MoneyToGet            = 0;
            std::vector<QuestObjectiveCollect> Collect;
            uint32 Explored             = 0;
            uint32 HasItems             = 0;
            uint32 HasFaction           = 0;
            uint32 HasMoney             = 0;
            uint32 QuestFlags           = 0;
            std::string_view QuestTitle;
            std::string_view CompletionText;
        };

        class QuestGiverOfferRewardMessage final : public ServerPacket
        {
        public:
            QuestGiverOfferRewardMessage() : ServerPacket(SMSG_QUEST_GIVER_OFFER_REWARD_MESSAGE, 600) { }

            WorldPacket const* Write() override;

            ObjectGuid QuestGiverGUID;
            uint32 QuestID = 0;
            std::string QuestTitle;
            std::string RewardText;
            bool AutoLaunched = false;
            uint32 Flags = 0;
            uint32 SuggestedGroupNum = 0;
            std::vector<QuestDescEmote> Emotes;
            QuestRewards Rewards;
        };
    }
}

#endif // TRINITYCORE_QUEST_PACKETS_H
