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

#ifndef QuestPackets_h__
#define QuestPackets_h__

#include "Packet.h"
#include "QuestDef.h"
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace Quest
    {
        struct QuestObjectiveCollect
        {
            QuestObjectiveCollect(int32 objectID = 0, int32 amount = 0, uint32 displayId = 0) : ObjectID(objectID), Amount(amount), DisplayID(displayId) { }
            uint32 ObjectID;
            uint32 Amount;
            uint32 DisplayID;
        };

        struct QuestCurrency
        {
            QuestCurrency(int32 currencyID = 0, int32 amount = 0) : CurrencyID(currencyID), Amount(amount) { }
            uint32 CurrencyID;
            uint32 Amount;
        };

        class QuestGiverRequestItems final : public ServerPacket
        {
        public:
            QuestGiverRequestItems() : ServerPacket(SMSG_QUEST_GIVER_REQUEST_ITEMS, 300) { }

            WorldPacket const* Write() override;

            ObjectGuid QuestGiverGUID;
            uint32 QuestID = 0;
            uint32 CompEmoteDelay = 0;
            uint32 CompEmoteType = 0;
            bool AutoLaunched = false;
            uint32 SuggestPartyMembers = 0;
            uint32 MoneyToGet = 0;
            std::vector<QuestObjectiveCollect> Collect;
            std::vector<QuestCurrency> Currency;
            uint32 StatusFlags[5] = { };
            uint32 QuestFlags = 0;
            std::string QuestTitle;
            std::string CompletionText;
        };

        class QuestGiverAcceptQuest final : public ClientPacket
        {
        public:
            QuestGiverAcceptQuest(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_ACCEPT_QUEST, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
            uint32 QuestID = 0;
            uint32 StartCheat = 0;
        };

        class QuestGiverChooseReward final : public ClientPacket
        {
        public:
            QuestGiverChooseReward(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_CHOOSE_REWARD, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
            int32 QuestID = 0;
            int32 ItemChoiceID = 0;
        };

        class QuestGiverCompleteQuest final : public ClientPacket
        {
        public:
            QuestGiverCompleteQuest(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_COMPLETE_QUEST, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID; // NPC / GameObject guid for normal quest completion. Player guid for self-completed quests
            int32 QuestID = 0;
            bool FromScript = false; // 0 - standart complete quest mode with npc, 1 - auto-complete mode
        };

        class QuestGiverHello final : public ClientPacket
        {
        public:
            QuestGiverHello(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_HELLO, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
        };

        class QuestGiverQueryQuest final : public ClientPacket
        {
        public:
            QuestGiverQueryQuest(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_QUERY_QUEST, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
            int32 QuestID = 0;
            bool RespondToGiver = false;
        };

        class QuestGiverRequestReward final : public ClientPacket
        {
        public:
            QuestGiverRequestReward(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_REQUEST_REWARD, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
            int32 QuestID = 0;
        };

        // Empty packet, server replies with quest giver status of visible creatures
        class QuestGiverStatusMultipleQuery final : public ClientPacket
        {
        public:
            QuestGiverStatusMultipleQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_STATUS_MULTIPLE_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        class QuestGiverStatusQuery final : public ClientPacket
        {
        public:
            QuestGiverStatusQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_GIVER_STATUS_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid QuestGiverGUID;
        };

        class QuestLogRemoveQuest final : public ClientPacket
        {
        public:
            QuestLogRemoveQuest(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_LOG_REMOVE_QUEST, std::move(packet)) { }

            void Read() override;

            uint8 Entry = 0;
        };

        class QuestConfirmAccept final : public ClientPacket
        {
        public:
            QuestConfirmAccept(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_CONFIRM_ACCEPT, std::move(packet)) { }

            void Read() override;

            int32 QuestID = 0;
        };

        class QueryQuestInfo final : public ClientPacket
        {
        public:
            QueryQuestInfo(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_QUEST_INFO, std::move(packet)) { }

            void Read() override;

            int32 QuestID = 0;
        };

        struct QuestInfoChoiceItem
        {
            int32 ItemID = 0;
            int32 Quantity = 0;
            int32 DisplayID = 0;
        };

        struct QuestInfo
        {
            uint32 QuestID                  = 0;
            int32  QuestType                = 0;    // Accepted values: 0, 1 or 2. 0 == IsAutoComplete() (skip objectives/details)
            int32  QuestLevel               = 0;    // may be -1, static data, in other cases must be used dynamic level: Player::GetQuestLevel (0 is not known, but assuming this is no longer valid for quest intended for client)
            int32  QuestMinLevel            = 0;
            int32  QuestSortID              = 0;    // zone or sort to display in quest log
            int32  QuestInfoID              = 0;
            uint32 SuggestedGroupNum        = 0;
            int32  AllowableRaces           = -1;

            std::array<uint32, BG_TEAMS_COUNT> RequiredFactionId = {};  // shown in quest log as part of quest objective (same/opposite faction)
            std::array<int32, BG_TEAMS_COUNT> RequiredFactionValue = {}; // shown in quest log as part of quest objective (same/opposite faction)

            int32 RewardNextQuest           = 0;    // client will request this quest from NPC, if not 0
            uint32 RewardXPDifficulty       = 0;    // used for calculating rewarded experience
            int32  RewardMoney              = 0;    // reward money (below max lvl)
            uint32 RewardBonusMoney         = 0;    // used in XP calculation at client
            int32 RewardDisplaySpell        = 0;    // reward spell, this spell will be displayed (icon) (cast if RewSpellCast == 0)
            int32  RewardSpell              = 0;
            int32 RewardHonor               = 0;
            float RewardKillHonor           = 0.0f;
            uint32 StartItem                = 0;
            uint32 Flags                    = 0;
            uint32 MinimapTargetMark        = 0;
            uint32 RewardTitle              = 0;    // new 2.4.0, player gets this title (id from CharTitles)
            uint32 RequiredPlayerKills      = 0;
            uint32 RewardTalents            = 0;
            int32  RewardArenaPoints        = 0;
            uint32 RewardSkillLineID        = 0;
            uint32 RewardNumSkillUps        = 0;
            uint32 RewardReputationMask     = 0;
            uint32 PortraitGiver            = 0;
            uint32 PortraitTurnIn           = 0;

            std::array<int32, QUEST_REWARDS_COUNT> RewardItems = {};
            std::array<uint32, QUEST_REWARDS_COUNT> RewardAmount = {};
            std::array<QuestInfoChoiceItem, QUEST_REWARD_CHOICES_COUNT> UnfilteredChoiceItems = {};
            std::array<uint32, QUEST_REPUTATIONS_COUNT> RewardFactionID = {};
            std::array<int32, QUEST_REPUTATIONS_COUNT> RewardFactionValue = {};
            std::array<uint32, QUEST_REPUTATIONS_COUNT> RewardFactionValueOverride = {};

            uint32 POIContinent             = 0;
            float  POIx                     = 0.0f;
            float  POIy                     = 0.0f;
            uint32 POIPriority              = 0;
            std::string LogTitle;
            std::string LogDescription;
            std::string QuestDescription;
            std::string AreaDescription;
            std::string QuestCompletionLog;              // display in quest objectives window once all objectives are completed

            std::array<int32, QUEST_OBJECTIVES_COUNT>  RequiredNpcOrGo = {};   // >0 Creature <0 Gameobject
            std::array<uint32, QUEST_OBJECTIVES_COUNT> RequiredNpcOrGoCount = {};

            std::array<int32, QUEST_OBJECTIVES_COUNT>  ItemDrop = {};
            std::array<uint32, QUEST_OBJECTIVES_COUNT> ItemDropQuantity = {};

            std::array<uint32, QUEST_ITEM_OBJECTIVES_COUNT> RequiredItemId = {};
            std::array<uint32, QUEST_ITEM_OBJECTIVES_COUNT> RequiredItemCount = {};

            uint32 RequiredSpell            = 0;

            std::array<std::string, QUEST_OBJECTIVES_COUNT> ObjectiveText = {};

            std::array<uint32, QUEST_REWARD_CURRENCY_COUNT> RewardCurrencyID = {};
            std::array<uint32, QUEST_REWARD_CURRENCY_COUNT> RewardCurrencyQty = {};
            std::array<uint32, QUEST_REQUIRED_CURRENCY_COUNT> RequiredCurrencyID = {};
            std::array<uint32, QUEST_REQUIRED_CURRENCY_COUNT> RequiredCurrencyQty = {};

            std::string PortraitGiverText;
            std::string PortraitGiverName;
            std::string PortraitTurnintext;
            std::string PortraitTurnInName;

            uint32 AcceptedSoundKitID = 0;
            uint32 CompleteSoundKitID = 0;
        };

        class QueryQuestInfoResponse final : public ServerPacket
        {
            public:
                QueryQuestInfoResponse() : ServerPacket(SMSG_QUEST_QUERY_RESPONSE, 2000) { }

                WorldPacket const* Write() override;

                QuestInfo Info;
        };

        struct GossipText
        {
            GossipText(uint32 questID, uint32 questType, int32 questLevel, uint32 questFlags, bool repeatable, std::string questTitle) :
                QuestID(questID), QuestType(questType), QuestLevel(questLevel), QuestFlags(questFlags), Repeatable(repeatable),
                QuestTitle(std::move(questTitle)) { }
            uint32 QuestID;
            uint32 QuestType;
            int32 QuestLevel;
            uint32 QuestFlags;
            bool Repeatable;
            std::string QuestTitle;
        };

        class QuestGiverQuestListMessage final : public ServerPacket
        {
        public:
            QuestGiverQuestListMessage() : ServerPacket(SMSG_QUEST_GIVER_QUEST_LIST_MESSAGE, 100) { }

            WorldPacket const* Write() override;

            ObjectGuid QuestGiverGUID;
            uint32 GreetEmoteDelay = 0;
            uint32 GreetEmoteType = 0;
            std::vector<GossipText> QuestDataText;
            std::string Greeting;
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
            QuestGiverStatus() : ServerPacket(SMSG_QUEST_GIVER_STATUS, 8) { }

            WorldPacket const* Write() override;

            QuestGiverInfo QuestGiver;
        };

        struct QuestRewards
        {
            int32 ChoiceItemCount = 0;
            int32 ItemCount = 0;
            int32 Money = 0;
            int32 XP = 0;
            int32 Title = 0;
            int32 FactionFlags = 0;
            int32 SpellCompletionID = 0;
            int32 SpellCompletionDisplayID = 0;
            int32 SkillLineID = 0;
            int32 NumSkillUps = 0;
            int32 NumBonusTalents = 0;
            QuestInfoChoiceItem ChoiceItems[QUEST_REWARD_CHOICES_COUNT];
            int32 ItemID[QUEST_REWARDS_COUNT] = { };
            int32 ItemQty[QUEST_REWARDS_COUNT] = { };
            int32 ItemDisplayID[QUEST_REWARDS_COUNT] = { };
            int32 FactionID[QUEST_REPUTATIONS_COUNT] = { };
            int32 FactionValue[QUEST_REPUTATIONS_COUNT] = { };
            int32 FactionOverride[QUEST_REPUTATIONS_COUNT] = { };
            int32 CurrencyID[QUEST_REWARD_CURRENCY_COUNT] = { };
            int32 CurrencyQty[QUEST_REWARD_CURRENCY_COUNT] = { };
        };

        struct QuestDescEmote
        {
            QuestDescEmote(int32 type = 0, uint32 delay = 0) : Type(type), Delay(delay) { }
            int32 Type;
            uint32 Delay;
        };

        class QuestGiverQuestDetails final : public ServerPacket
        {
        public:
            QuestGiverQuestDetails() : ServerPacket(SMSG_QUEST_GIVER_QUEST_DETAILS, 100) { }

            WorldPacket const* Write() override;

            ObjectGuid QuestGiverGUID;
            ObjectGuid InformUnit;
            int32 QuestID = 0;
            uint32 QuestFlags = 0;
            int32 SuggestedPartyMembers = 0;
            QuestRewards Rewards;
            std::vector<QuestDescEmote> DescEmotes;
            int32 PortraitTurnIn = 0;
            int32 PortraitGiver = 0;
            int32 QuestStartItemID = 0;
            int32 RequiredSpellID = 0;
            std::string PortraitGiverText;
            std::string PortraitGiverName;
            std::string PortraitTurnInText;
            std::string PortraitTurnInName;
            std::string QuestTitle;
            std::string LogDescription;
            std::string DescriptionText;
            std::string Objectives;
            bool DisplayPopup = false;
            bool StartCheat = false;
            bool AutoLaunched = false;
        };

        class QuestGiverQuestComplete final : public ServerPacket
        {
        public:
            QuestGiverQuestComplete() : ServerPacket(SMSG_QUEST_GIVER_QUEST_COMPLETE, 26) { }

            WorldPacket const* Write() override;

            int32 SkillLineIDReward = 0;
            int32 MoneyReward = 0;
            int32 NumSkillUpsReward = 0;
            int32 XPReward = 0;
            int32 QuestID = 0;
            int32 TalentReward = 0;
            bool  LaunchGossip = false;
            bool  UseQuestReward =  false;
        };

        class QuestConfirmAcceptResponse final : public ServerPacket
        {
        public:
            QuestConfirmAcceptResponse() : ServerPacket(SMSG_QUEST_CONFIRM_ACCEPT, 13) { }

            WorldPacket const* Write() override;

            ObjectGuid InitiatedBy;
            int32 QuestID = 0;
            std::string QuestTitle;
        };

        class QuestUpdateAddCredit final : public ServerPacket
        {
        public:
            QuestUpdateAddCredit() : ServerPacket(SMSG_QUEST_UPDATE_ADD_CREDIT, 8 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid VictimGUID;
            int32 ObjectID = 0;
            int32 QuestID  = 0;
            uint32 Count = 0;
            uint32 Required = 0;
        };

        class QuestUpdateAddPvPCredit final : public ServerPacket
        {
        public:
            QuestUpdateAddPvPCredit() : ServerPacket(SMSG_QUEST_UPDATE_ADD_PVP_CREDIT, 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 QuestID = 0;
            uint32 Count = 0;
            uint32 Required = 0;
        };

        class QuestUpdateComplete final : public ServerPacket
        {
        public:
            QuestUpdateComplete() : ServerPacket(SMSG_QUEST_UPDATE_COMPLETE, 4) { }

            WorldPacket const* Write() override;

            int32 QuestID = 0;
        };

        class QuestUpdateFailedTimer final : public ServerPacket
        {
        public:
            QuestUpdateFailedTimer() : ServerPacket(SMSG_QUEST_UPDATE_FAILED_TIMER, 4) { }

            WorldPacket const* Write() override;

            uint32 QuestID = 0;
        };

        class QuestGiverInvalidQuest final : public ServerPacket
        {
        public:
            QuestGiverInvalidQuest() : ServerPacket(SMSG_QUEST_GIVER_INVALID_QUEST, 6) { }

            WorldPacket const* Write() override;

            uint32 Reason = 0;
        };

        class QuestGiverQuestFailed final : public ServerPacket
        {
        public:
            QuestGiverQuestFailed() : ServerPacket(SMSG_QUEST_GIVER_QUEST_FAILED, 8) { }

            WorldPacket const* Write() override;

            uint32 QuestID = 0;
            uint32 Reason = 0;
        };

        class QuestPushResultResponse final : public ServerPacket
        {
        public:
            QuestPushResultResponse() : ServerPacket(OpcodeServer(MSG_QUEST_PUSH_RESULT), 8 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid SenderGUID;
            uint8 Result = 0;
        };

        class QuestGiverStatusMultiple final : public ServerPacket
        {
        public:
            QuestGiverStatusMultiple() : ServerPacket(SMSG_QUEST_GIVER_STATUS_MULTIPLE, 24) { }

            WorldPacket const* Write() override;

            std::vector<QuestGiverInfo> QuestGiver;
        };

        class QuestLogFull final : public ServerPacket
        {
        public:
            QuestLogFull() : ServerPacket(SMSG_QUEST_LOG_FULL, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        struct QuestGiverOfferReward
        {
            ObjectGuid QuestGiverGUID;
            int32 QuestFlags                = 0;
            int32 QuestID                   = 0;
            int32 SuggestedPartyMembers     = 0;
            QuestRewards Rewards;
            std::vector<QuestDescEmote> Emotes;
            bool AutoLaunched = false;
        };

        class QuestGiverOfferRewardMessage final : public ServerPacket
        {
        public:
            QuestGiverOfferRewardMessage() : ServerPacket(SMSG_QUEST_GIVER_OFFER_REWARD_MESSAGE, 600) { }

            WorldPacket const* Write() override;

            QuestGiverOfferReward QuestData;
            int32 PortraitTurnIn = 0;
            int32 PortraitGiver = 0;
            std::string QuestTitle;
            std::string RewardText;
            std::string PortraitGiverText;
            std::string PortraitGiverName;
            std::string PortraitTurnInText;
            std::string PortraitTurnInName;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::QuestRewards const& questRewards);

#endif // QuestPackets_h__
