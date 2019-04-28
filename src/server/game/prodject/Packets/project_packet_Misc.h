#ifndef PROJECT_PACKETS_MISC_H
#define PROJECT_PACKETS_MISC_H

#include "AchievementPackets.h"
#include "MovementPackets.h"
#include "LFGPackets.h"
#include "ItemPackets.h"

namespace PROJECT
{
    namespace Packets
    {
        namespace Misc
        {
            class BattlemasterJoinArenaSkirmish final : public WorldPackets::ClientPacket
            {
            public:
                BattlemasterJoinArenaSkirmish(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BATTLEMASTER_JOIN_SKIRMISH, std::move(packet)) { }

                void Read() override;

                uint8 TeamSizeIndex;
                uint8 Roles;
                bool JoinAsGroup;
                bool Unk;
            };

            struct ClientBracketInfo
            {
                int32 PersonalRating = 0;
                int32 Ranking = 0;
                int32 SeasonPlayed = 0;
                int32 SeasonWon = 0;
                int32 WeeklyPlayed = 0;
                int32 WeeklyWon = 0;
                int32 BestWeeklyRating = 0;
                int32 BestSeasonRating = 0;
                int32 Unk1 = 0;
                int32 Unk2 = 0;
                int32 Unk3 = 0;
            };

            enum BracketSlots
            {
                BRACKET_2v2     = 0,
                BRACKET_3v3     = 1,
                BRACKET_RATED   = 3,
            };

            class RatedBattlefieldInfo final : public WorldPackets::ServerPacket
            {
                public:
                    RatedBattlefieldInfo() : WorldPackets::ServerPacket(SMSG_RATED_BATTLEFIELD_INFO) { }
            
                    WorldPacket const* Write() override;

                    ClientBracketInfo Bracket[6];
            };

            class StartTimer final : public WorldPackets::ServerPacket
            {
            public:
                StartTimer() : WorldPackets::ServerPacket(SMSG_START_TIMER, 4 * 3) { }

                WorldPacket const* Write() override;

                uint32 CurrentTimer = 0;
                uint32 MaxTimer = 0;
                uint32 Type = 0;
            };

            class GuildShiftRank final : public WorldPackets::ClientPacket
            {
            public:
                GuildShiftRank(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_GUILD_SHIFT_RANK, std::move(packet)) { }

                void Read() override;

                bool ShiftUp = false;
                int32 RankOrder = 0;
            };

            class ShowNeutralPlayerFactionSelectUi final : WorldPackets::ServerPacket
            {
            public:
                ShowNeutralPlayerFactionSelectUi() : WorldPackets::ServerPacket(SMSG_SHOW_NEUTRAL_PLAYER_FACTION_SELECT_UI, 0) { }

                WorldPacket const* Write() { return &_worldPacket; };
            };

            class NeutralPlayerSelectFaction final : public  WorldPackets::ClientPacket
            {
            public:
                NeutralPlayerSelectFaction(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_NEUTRAL_PLAYER_SELECT_FACTION, std::move(packet)) { }

                void Read() override;

                uint32 Faction = 0;
            };

            class VignetteUpdate final : public  WorldPackets::ServerPacket
            {
            public:
                VignetteUpdate() : WorldPackets::ServerPacket(SMSG_VIGNETTE_UPDATE, 21) { }

                WorldPacket const* Write() override;

                struct VignetteClientData
                {
                    Position position;
                    ObjectGuid guid;
                    uint32 VignetteID;
                    uint32 ZoneRestriction;
                };

                bool ForceUpdate = false;
                std::vector<ObjectGuid> Removed;
                std::vector<ObjectGuid> Added;
                std::vector<VignetteClientData> VignetteClientAdded;
                std::vector<ObjectGuid> Updated;
                std::vector<VignetteClientData> VignetteClientUpdated;
            };

            class PetSlotUpdated final : public WorldPackets::ServerPacket
            {
            public:
                PetSlotUpdated() : WorldPackets::ServerPacket(SMSG_PET_SLOT_UPDATED, 4 * 4) { }

                WorldPacket const* Write() override;

                int32 OriginPetID = 0;
                int32 To = 0; // PetSlot
                int32 TargetPetID = 0;
                int32 From = 0; // PetSlot
            };

            class BuyReagentBank final : public WorldPackets::ClientPacket
            {
            public:
                BuyReagentBank(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_BUY_REAGENT_BANK, std::move(packet)) { }

                void Read() override;

                ObjectGuid Unit;
            };

            class SetPetSlot final : public WorldPackets::ClientPacket
            {
            public:
                SetPetSlot(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_SET_PET_SLOT, std::move(packet)) { }

                void Read() override;

                ObjectGuid Stable;
                uint32 PetNumberID = 0;
                int8 ToSlot = 0;
            };

            class PetStableResult final : public WorldPackets::ServerPacket
            {
            public:
                PetStableResult() : WorldPackets::ServerPacket(SMSG_PET_STABLE_RESULT) { }

                WorldPacket const* Write() override;

                uint8 Message = 0;
            };

            class GuildChallengeCompleted final : public WorldPackets::ServerPacket
            {
            public:
                GuildChallengeCompleted() : WorldPackets::ServerPacket(SMSG_GUILD_CHALLENGE_COMPLETED) { }

                WorldPacket const* Write() override;

                uint32 MaxCount = 0;
                uint32 CurrentCount = 0;
                uint32 Gold = 0;
                uint32 ChallengeType = 0;
            };

            class GuildChangeNameResult final : public WorldPackets::ServerPacket
            {
            public:
                GuildChangeNameResult() : WorldPackets::ServerPacket(SMSG_GUILD_CHANGE_NAME_RESULT) { }

                WorldPacket const* Write() override;

                bool hasRename = true;
            };

            class GuildNameChanged final : public WorldPackets::ServerPacket
            {
            public:
                GuildNameChanged() : WorldPackets::ServerPacket(SMSG_GUILD_NAME_CHANGED) { }

                WorldPacket const* Write() override;

                ObjectGuid GuildGuid;
                std::string NewName;
            };

            class DisplayToast final : public WorldPackets::ServerPacket
            {
                public:
                    DisplayToast() : WorldPackets::ServerPacket(SMSG_DISPLAY_TOAST) { }

                    WorldPacket const* Write() override;

                    uint32 EntityId = 0;
                    uint32 ToastType = 0;
                    uint64 Quantity = 1;
                    int32 RandomPropertiesID = 0;
                    uint32 QuestID = 0;
                    uint8 ToastMethod = 1; // TOAST_METHOD_POPUP
                    bool IsBonusRoll = false;
                    bool Mailed = false;
                    std::vector<int32> bonusListIDs;
            };

            class ChangePlayerDifficultyResult final : public WorldPackets::ServerPacket
            {
            public:
                ChangePlayerDifficultyResult() : WorldPackets::ServerPacket(SMSG_CHANGE_PLAYER_DIFFICULTY_RESULT) { }

                WorldPacket const* Write() override;

                uint8 Result = 0;
                bool Cooldown = false;
                uint32 CooldownReason = 0;
                uint32 InstanceMap = 0;
                uint32 DifficultyID = 0;
                ObjectGuid Guid;
            };

            class ChallengeModeStart final : public WorldPackets::ServerPacket
            {
            public:
                ChallengeModeStart() : WorldPackets::ServerPacket(SMSG_CHALLENGE_MODE_START) { }

                WorldPacket const* Write() override;

                uint32 MapID;
                uint32 KeystoneLevel = 0;
                std::array<uint32, 3> Affixes;
                uint32 UnkStructure = 0;
                bool IsCharged = true;
            };

            class StartChallengeMode final : public WorldPackets::ClientPacket
            {
            public:
                StartChallengeMode(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_START_CHALLENGE_MODE, std::move(packet)) { }

                void Read() override;

                int32 Unk1;
                int32 Unk2;
                ObjectGuid GameObject;
            };

            class ChallengeModeReset final : public WorldPackets::ServerPacket
            {
            public:
                ChallengeModeReset() : WorldPackets::ServerPacket(SMSG_CHALLENGE_MODE_RESET) { }

                WorldPacket const* Write() override;

                uint32 MapID;
            };

            class ChallengeModeComplete final : public WorldPackets::ServerPacket
            {
            public:
                ChallengeModeComplete() : WorldPackets::ServerPacket(SMSG_CHALLENGE_MODE_COMPLETE) { }

                WorldPacket const* Write() override;

                uint32 MapID = 0;
                uint32 KeystoneLevel = 0;
                uint32 Timer = 0;
            };

            class StartElapsedTimer final : public WorldPackets::ServerPacket
            {
            public:
                StartElapsedTimer() : WorldPackets::ServerPacket(SMSG_START_ELAPSED_TIMER) { }

                WorldPacket const* Write() override;

                uint32 TimerID;
                uint32 CurrentTimer;
            };

            class StopElapsedTimer final : public WorldPackets::ServerPacket
            {
            public:
                StopElapsedTimer() : WorldPackets::ServerPacket(SMSG_STOP_ELAPSED_TIMER) { }

                WorldPacket const* Write() override;

                uint32 TimerID = 0;
                bool KeepTimer = false;
            };

            class SortBag final : public WorldPackets::ClientPacket
            {
            public:
                SortBag(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_SORT_BAGS, std::move(packet)) { }

                void Read() override { }
            };

            class SortBagResult final : public WorldPackets::ServerPacket
            {
            public:
                SortBagResult() : WorldPackets::ServerPacket(SMSG_SORT_BAGS_RESULT) { }

                WorldPacket const* Write() override { return &_worldPacket; }
            };


            struct AccountCriteria
            {
                AccountCriteria() { }
                AccountCriteria(WorldPackets::Achievement::CriteriaProgress &criteriaProgress)
                {
                    CriteriaID = criteriaProgress.Id;
                    Quantity = criteriaProgress.Quantity;
                    PlayerGUID = criteriaProgress.Player;
                    Flags = criteriaProgress.Flags;
                    CurrentTime = criteriaProgress.Date;
                    ElapsedTime = criteriaProgress.TimeFromStart;
                    CreationTime = criteriaProgress.TimeFromCreate;
                }

                uint32 CriteriaID = 0;
                uint64 Quantity = 0;
                ObjectGuid PlayerGUID;
                uint32 Flags = 0;
                time_t CurrentTime = time_t(0);
                uint32 ElapsedTime = 0;
                uint32 CreationTime = 0;
            };

            class AccountCriteriaUpdate final : public WorldPackets::ServerPacket
            {
                public:
                    AccountCriteriaUpdate(WorldPackets::Achievement::CriteriaUpdate &criteriaUpdate) : WorldPackets::ServerPacket(SMSG_ACCOUNT_CRITERIA_UPDATE, 4 + 8 + 16 + 4 + 4 + 4 + 4)
                    {
                        CriteriaData.CriteriaID = criteriaUpdate.CriteriaID;
                        CriteriaData.Quantity = criteriaUpdate.Quantity;
                        CriteriaData.PlayerGUID = criteriaUpdate.PlayerGUID;
                        CriteriaData.Flags = criteriaUpdate.Flags;
                        CriteriaData.CurrentTime = criteriaUpdate.CurrentTime;
                        CriteriaData.ElapsedTime = criteriaUpdate.ElapsedTime;
                        CriteriaData.CreationTime = criteriaUpdate.CreationTime;
                    }

                    WorldPacket const* Write() override;

                    AccountCriteria CriteriaData;
            };

            class AllAccountCriteria final : public WorldPackets::ServerPacket
            {
                public:
                    AllAccountCriteria() : WorldPackets::ServerPacket(SMSG_ALL_ACCOUNT_CRITERIA) { }

                    WorldPacket const* Write() override;

                    std::vector<AccountCriteria> Criterias;
            };

			class LfgBonusFactionId final : public WorldPackets::ClientPacket
			{
				public:
				    LfgBonusFactionId(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_SET_LFG_BONUS_FACTION_ID, std::move(packet)) { }
				
			        void Read() override;

					uint32 FactionID;
			};

            class StartWarGame final : public WorldPackets::ClientPacket
            {
            	public:
            	    StartWarGame(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_START_WAR_GAME, std::move(packet)) { }
            	
                    void Read() override;

                    ObjectGuid OpposingPartyMember;
                    uint64 QueueID;
                    bool TournamentRules;
                    uint32 OpposingPartyMemberVirtualRealmAddress;
                    uint16 OpposingPartyMemberCfgRealmID;
            };

            class ShowTradeSkill final : public WorldPackets::ClientPacket
            {
            	public:
            	    ShowTradeSkill(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_SHOW_TRADE_SKILL, std::move(packet)) { }
            	
                    void Read() override;

                    ObjectGuid PlayerGUID;
                    uint32 SkillLineID;
                    uint32 SpellID;
            };

            class ShowTradeSkillResponse final : public WorldPackets::ServerPacket
            {
                public:
                    ShowTradeSkillResponse() : WorldPackets::ServerPacket(SMSG_SHOW_TRADE_SKILL_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    ObjectGuid PlayerGUID;
                    uint32 SpellID;
                    std::vector<uint32> SkillLineIDs;
                    std::vector<uint32> SkillRanks;
                    std::vector<uint32> SkillMaxRanks;
                    std::vector<uint32> KnownAbilitySpellIDs;
            };

            class KeyboundOverride final : public WorldPackets::ClientPacket
            {
            	public:
            	    KeyboundOverride(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_KEYBOUND_OVERRIDE, std::move(packet)) { }
            	
                    void Read() override;

                    uint16 OverrideID;
            };

            class GuildReplaceGuildMaster final : public WorldPackets::ClientPacket
            {
            	public:
            	    GuildReplaceGuildMaster(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_GUILD_REPLACE_GUILD_MASTER, std::move(packet)) { }
            	
                    void Read() override { }
            };

            class ScriptCast final : public WorldPackets::ServerPacket
            {
                public:
                    ScriptCast() : WorldPackets::ServerPacket(SMSG_SCRIPT_CAST) { }
            
                    WorldPacket const* Write() override;

                    uint32 SpellID;
            };

            class AddLossOfControl final : public WorldPackets::ServerPacket
            {
                public:
                    AddLossOfControl() : WorldPackets::ServerPacket(SMSG_ADD_LOSS_OF_CONTROL) { }
            
                    WorldPacket const* Write() override;

                    ObjectGuid Victim;
                    ObjectGuid Caster;
                    uint32 DurationRemaining = 0;
                    uint32 Duration = 0;
                    uint32 LockoutSchoolMask = 0;
                    int32 SpellID = 0;
                    uint8 Type = 0;
                    uint8 Mechanic = 0;
            };

            class RemoveLossOfControl final : public WorldPackets::ServerPacket
            {
                public:
                    RemoveLossOfControl() : WorldPackets::ServerPacket(SMSG_REMOVE_LOSS_OF_CONTROL) { }
            
                    WorldPacket const* Write() override;

                    ObjectGuid Caster;
                    ObjectGuid Victim;
                    int32 SpellID = 0;
                    int8 Type = 0;
            };

            class MoveApplyMovementForce final : public WorldPackets::ServerPacket
            {
                public:
                    MoveApplyMovementForce() : WorldPackets::ServerPacket(SMSG_MOVE_APPLY_MOVEMENT_FORCE) { }
            
                    WorldPacket const* Write() override;

                    WorldPackets::Movement::MovementForce Force;
                    ObjectGuid MoverGUID;
                    uint32 SequenceIndex = 0;
            };

            class MoveRemoveMovementForce final : public WorldPackets::ServerPacket
            {
                public:
                    MoveRemoveMovementForce() : WorldPackets::ServerPacket(SMSG_MOVE_REMOVE_MOVEMENT_FORCE) { }
            
                    WorldPacket const* Write() override;

                    ObjectGuid MoverGUID;
                    uint32 SequenceIndex = 0;
                    ObjectGuid TriggerGUID;
            };

            class PlayerChoiceResponseRewardEntry
            {
                public:
                    int32 Id = 0;
                    int32 DisplayID = 0;
                    int32 Quantity = 0;

                    PlayerChoiceResponseRewardEntry(uint32 _Id = 0, uint32 _DisplayID = 0, uint32 _Quantity = 0) : Id(_Id), DisplayID(_DisplayID), Quantity(_Quantity) { }
            };

            class PlayerChoiceResponseReward
            {
                public:
                    bool hasReward = false;
                    int32 TitleID = 0;
                    int32 PackageID = 0;
                    int32 SkillLineID = 0;
                    uint32 SkillPointCount = 0;
                    uint32 ArenaPointCount = 0;
                    uint32 HonorPointCount = 0;
                    uint64 Money = 0;
                    uint32 Xp = 0;
                    std::vector<PlayerChoiceResponseRewardEntry> Items;
                    std::vector<PlayerChoiceResponseRewardEntry> Currencies;
                    std::vector<PlayerChoiceResponseRewardEntry> Factions;
                    std::vector<PlayerChoiceResponseRewardEntry> ItemChoices;

                    PlayerChoiceResponseReward& operator=(const PlayerChoiceResponseReward& from)
                    {
                        this->hasReward = true;

                        this->TitleID = from.TitleID;
                        this->PackageID = from.PackageID;
                        this->SkillLineID = from.SkillLineID;
                        this->SkillPointCount = from.SkillPointCount;
                        this->ArenaPointCount = from.ArenaPointCount;
                        this->HonorPointCount = from.HonorPointCount;
                        this->Money = from.Money;
                        this->Xp = from.Xp;

                        this->Items = from.Items;
                        this->Currencies = from.Currencies;
                        this->Factions = from.Factions;
                        this->ItemChoices = from.ItemChoices;

                        return *this;
                    }
            };

            class PlayerChoiceResponse
            {
                public:
                    int32 ResponseID = 0;
                    std::string Answer;
                    std::string Title;
                    std::string Description;
                    std::string ConfirmationString;
                    int32 ChoiceArtFileID = 0;
                    PlayerChoiceResponseReward Reward;
            };

            class TC_GAME_API DisplayPlayerChoice final : public WorldPackets::ServerPacket
            {
                public:
                    DisplayPlayerChoice() : WorldPackets::ServerPacket(SMSG_DISPLAY_PLAYER_CHOICE) { }
            
                    WorldPacket const* Write() override;

#ifdef PROJECT_CUSTOM
                    void PopulateFromQuests(uint32 questId1, uint32 questId2 = 0, uint32 questId3 = 0);
                    uint32 HardcodedChoiceArtFileIDs(uint32 questId);
#else
                    void PopulateFromQuests(uint32 questId1, uint32 questId2 = 0, uint32 questId3 = 0) {};
                    uint32 HardcodedChoiceArtFileIDs(uint32 questId) { return 0; };
#endif

                    uint32 ChoiceID = 0;
                    ObjectGuid GUID;
                    std::string Question;
                    std::vector<PlayerChoiceResponse> Responses;
            };

            class ChoiceResponse final : public WorldPackets::ClientPacket
            {
            	public:
            	    ChoiceResponse(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_CHOICE_RESPONSE, std::move(packet)) { }
            	
                    void Read() override;

                    uint32 ChoiceID = 0;
                    uint32 ResponseID = 0;
            };

            class PetTameFailure final : public WorldPackets::ServerPacket
            {
                public:
                    PetTameFailure() : WorldPackets::ServerPacket(SMSG_PET_TAME_FAILURE) { }
            
                    WorldPacket const* Write() override;

                    uint8 Result = 0;
            };

            class UpdateDungeonEncounterForLoot final : public WorldPackets::ServerPacket
            {
                public:
                    UpdateDungeonEncounterForLoot() : WorldPackets::ServerPacket(SMSG_OPEN_LFG_DUNGEON_FINDER) { }
            
                    WorldPacket const* Write() override { return &_worldPacket; }
            };

            class UnlearnSpecialization final : public WorldPackets::ClientPacket
            {
            	public:
            	    UnlearnSpecialization(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_UNLEARN_SPECIALIZATION, std::move(packet)) { }
            	
                    void Read() override;

                    uint8 SpecializationIndex = 0;
            };

            class RequestPvpRewardsResponse final : public WorldPackets::ServerPacket
            {
                public:
                    RequestPvpRewardsResponse() : WorldPackets::ServerPacket(SMSG_REQUEST_PVP_REWARDS_RESPONSE) { }
            
                    WorldPacket const* Write() override;

                    WorldPackets::LFG::ShortageReward RandomBg;
                    WorldPackets::LFG::ShortageReward RatedBg;
                    WorldPackets::LFG::ShortageReward SkirmishArena;
                    WorldPackets::LFG::ShortageReward RatedArena2v2;
                    WorldPackets::LFG::ShortageReward RatedArena3v3;
                    bool HasFirstRatedBg = false;
                    bool HasFirstSkirmish = false;
                    bool HasFirstRatedArena2v2 = false;
                    bool HasFirstRatedArena3v3 = false;
            };

            class TC_GAME_API AdventureJournalOpenQuest final : public WorldPackets::ClientPacket
            {
                public:
                    AdventureJournalOpenQuest(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_ADVENTURE_JOURNAL_OPEN_QUEST, std::move(packet)) { }

                    void Read() override;

                    uint32 JournalID;
            };

            struct ClientOpponentSpecData
            {
                ObjectGuid Guid;
                uint32 SpecializationID = 0;
                uint32 Unk1 = 0;
            };

            class ArenaPrepOpponentSpecializations final : public WorldPackets::ServerPacket
            {
                public:
                    ArenaPrepOpponentSpecializations() : WorldPackets::ServerPacket(SMSG_ARENA_PREP_OPPONENT_SPECIALIZATIONS) { }
            
                    WorldPacket const* Write() override;

                    std::vector<ClientOpponentSpecData> OpponentData;
            };

            struct LFGPlayerRewards
            {
                int32 RewardItem = 0;
                uint32 RewardItemQuantity = 0;
                int32 BonusCurrency = 0;
                bool IsCurrency = false;
            };

            class LfgPlayerReward final : public WorldPackets::ServerPacket
            {
                public:
                    LfgPlayerReward() : WorldPackets::ServerPacket(SMSG_LFG_PLAYER_REWARD) { }
            
                    WorldPacket const* Write() override;

                    int32 RewardMoney = 0;
                    uint32 QueuedSlot = 0;
                    std::vector<LFGPlayerRewards> Rewards;
                    int32 AddedXP = 0;
                    uint32 ActualSlot = 0;
            };

            class TC_GAME_API SetWarMode final : public WorldPackets::ClientPacket
            {
            public:
                SetWarMode(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_SET_WAR_MODE, std::move(packet)) { }

                void Read() override;

                bool Enabled;
            };


            class AzeriteXpGain final : public WorldPackets::ServerPacket
            {
            public:
                AzeriteXpGain() : WorldPackets::ServerPacket(SMSG_AZERITE_XP_GAIN) { }

                WorldPacket const* Write() override;

                ObjectGuid AzeriteGUID;
                uint64 XP = 0;
            };
            
            class AzeriteEmpoweredItemSelectPower final : public WorldPackets::ClientPacket
            {
            public:
                AzeriteEmpoweredItemSelectPower(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_AZERITE_EMPOWERED_ITEM_SELECT_POWER, std::move(packet)) { }

                void Read() override;

                uint32 Tier;
                uint32 AzeritePowerID;
                uint8 Bag;
                uint8 Slot;

            };

            class AzeriteEmpoweredItemRespecOpen final : public WorldPackets::ServerPacket
            {
            public:
                AzeriteEmpoweredItemRespecOpen() : WorldPackets::ServerPacket(SMSG_AZERITE_EMPOWERED_ITEM_RESPEC_OPEN) { }

                WorldPacket const* Write() override;

                ObjectGuid UnitGUID;
            };

            
        }
    }
}

#endif
