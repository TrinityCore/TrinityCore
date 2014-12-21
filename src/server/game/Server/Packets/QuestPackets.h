/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef QuestPackets_h__
#define QuestPackets_h__

#include "Packet.h"
#include "QuestDef.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Quest
    {
        class QuestGiverStatusQuery final : public ClientPacket
        {
        public:
            QuestGiverStatusQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUESTGIVER_STATUS_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
        };

        // Empty packet, server replies with quest giver status of visible creatures
        class QuestGiverStatusMultipleQuery final : public ClientPacket
        {
        public:
            QuestGiverStatusMultipleQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        struct QuestGiverInfo
        {
            QuestGiverInfo() { }
            QuestGiverInfo(ObjectGuid const& guid, uint32 status)
                : Guid(guid), Status(status) { }

            ObjectGuid Guid;
            uint32 Status = DIALOG_STATUS_NONE;
        };

        class QuestGiverStatus final : public ServerPacket
        {
        public:
            QuestGiverStatus() : ServerPacket(SMSG_QUESTGIVER_STATUS, 22) { }

            WorldPacket const* Write() override;

            QuestGiverInfo QuestGiver;
        };

        class QuestGiverStatusMultiple final : public ServerPacket
        {
        public:
            QuestGiverStatusMultiple() : ServerPacket(SMSG_QUESTGIVER_STATUS_MULTIPLE, 24) { }

            WorldPacket const* Write() override;

            std::vector<QuestGiverInfo> QuestGiver;
        };

        class QuestGiverHello final : public ClientPacket
        {
        public:
            QuestGiverHello(WorldPacket&& packet) : ClientPacket(CMSG_QUESTGIVER_HELLO, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
        };

        class QueryQuestInfo final : public ClientPacket
        {
        public:
            QueryQuestInfo(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiver;
            int32 QuestID;
        };
        
        struct QuestInfoChoiceItem
        {
            int32 ItemID;
            int32 Quantity;
            int32 DisplayID;
        };

        struct QuestInfo
        {
            int32 QuestID                   = 0;
            int32 QuestType                 = 0; // Accepted values: 0, 1 or 2. 0 == IsAutoComplete() (skip objectives/details)
            int32 QuestLevel                = 0; // may be -1, static data, in other cases must be used dynamic level: Player::GetQuestLevel (0 is not known, but assuming this is no longer valid for quest intended for client)
            int32 QuestPackageID            = 0;
            int32 QuestMinLevel             = 0;
            int32 QuestSortID               = 0; // zone or sort to display in quest log
            int32 QuestInfoID               = 0;
            int32 SuggestedGroupNum         = 0;
            int32 RewardNextQuest           = 0; // client will request this quest from NPC, if not 0
            int32 RewardXPDifficulty        = 0; // used for calculating rewarded experience
            int32 RewardMoney               = 0; // reward money (below max lvl)
            int32 RewardMoneyDifficulty     = 0; // used in XP calculation at client
            int32 RewardBonusMoney          = 0;
            int32 RewardDisplaySpell        = 0; // reward spell, this spell will be displayed (icon)
            int32 RewardSpell               = 0;
            int32 RewardHonor               = 0;
            float RewardKillHonor           = 0.0f;
            int32 StartItem                 = 0;
            int32 Flags                     = 0;
            int32 FlagsEx                   = 0;
            int32 POIContinent              = 0;
            float POIx                      = 0.0f;
            float POIy                      = 0.0f;
            int32 POIPriority               = 0;
            std::string LogTitle;
            std::string LogDescription;
            std::string QuestDescription;
            std::string AreaDescription;
            int32 RewardTitle               = 0; // new 2.4.0, player gets this title (id from CharTitles)
            int32 RewardTalents             = 0;
            int32 RewardArenaPoints         = 0;
            int32 RewardSkillLineID         = 0; // reward skill id
            int32 RewardNumSkillUps         = 0; // reward skill points
            int32 PortraitGiver             = 0; // quest giver entry ?
            int32 PortraitTurnIn            = 0; // quest turn in entry ?
            std::string PortraitGiverText;
            std::string PortraitGiverName;
            std::string PortraitTurnInText;
            std::string PortraitTurnInName;
            std::string QuestCompletionLog;
            int32 RewardFactionFlags        = 0; // rep mask (unsure on what it does)
            int32 AcceptedSoundKitID        = 0;
            int32 CompleteSoundKitID        = 0;
            int32 AreaGroupID               = 0;
            int32 TimeAllowed               = 0;
            std::vector<QuestObjective> Objectives;
            int32 RewardItems[QUEST_REWARDS_COUNT] = {};
            int32 RewardAmount[QUEST_REWARDS_COUNT] = {};
            int32 ItemDrop[QUEST_ITEM_DROP_COUNT] = {};
            int32 ItemDropQuantity[QUEST_ITEM_DROP_COUNT] = {};
            QuestInfoChoiceItem UnfilteredChoiceItems[QUEST_REWARD_CHOICES_COUNT];
            int32 RewardFactionID[QUEST_REPUTATIONS_COUNT] = {};
            int32 RewardFactionValue[QUEST_REPUTATIONS_COUNT] = {};
            int32 RewardFactionOverride[QUEST_REPUTATIONS_COUNT] = {};
            int32 RewardCurrencyID[QUEST_REWARD_CURRENCY_COUNT] = {};
            int32 RewardCurrencyQty[QUEST_REWARD_CURRENCY_COUNT] = {};
        };

        class QueryQuestInfoResponse final : public ServerPacket
        {
        public:
            QueryQuestInfoResponse() : ServerPacket(SMSG_QUEST_QUERY_RESPONSE, 1200) { }

            WorldPacket const* Write() override;

            bool Allow = false;
            QuestInfo Info;
            uint32 QuestID = 0;
        };

        class QuestUpdateAddCredit final : public ServerPacket
        {
        public:
            QuestUpdateAddCredit() : ServerPacket(SMSG_QUESTUPDATE_ADD_KILL, 16+4+4+2+2+1) { }

            WorldPacket const* Write() override;

            ObjectGuid VictimGUID;
            int32 ObjectID      = 0;
            int32 QuestID       = 0;
            uint16 Count        = 0;
            uint16 Required     = 0;
            uint8 ObjectiveType = 0;
        };
    }
}

#endif // QuestPackets_h__
