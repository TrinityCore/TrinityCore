#ifndef PROJECT_DBC_DEFINITIONS
#define PROJECT_DBC_DEFINITIONS

#include "project_db2_LoadInfo.h"
#include "DB2Store.h"
#include "DBCEnums.h"

namespace PROJECT
{
    namespace DataStores
    {
        void AfterLoadDatastores();
        void LoadDB2(LocaleConstant locale);

        #if defined(__GNUC__)
        #pragma pack(1)
        #else
        #pragma pack(push, 1)
        #endif

        namespace Structs
        {
            struct AdventureJournal
            {
                uint32 ID;
                char* Title;
                char* Description;
                char* ButtonText;
                uint32 Unk1;
                uint32 Unk2;
                char* Unk3;
                char* ContinueText;
                uint16 Unk4;
                uint16 Unk5;
                uint16 QuestID;
                uint16 Unk6[2];
                uint16 Unk7;
                uint16 Unk8;
                uint8 Unk9;
                uint8 Unk10;
                uint8 Type;
                uint8 Unk11;
                uint8 Unk12;
                uint8 Unk13;
                uint8 Unk14[2];
                uint32 Unk15;
                uint32 Unk16;
            };

            struct AdventureMapPOI
            {
                uint32 ID;
                float POI[2];
                uint32 Unk1;
                char* Title;
                char* Description;
                uint8 Unk2;
                uint16 Unk3;
                uint16 QuestID;
                uint32 Unk4;
                uint32 Unk5;
                uint32 Unk6;
                uint32 Unk7;
                uint32 Unk8;
                uint32 Unk9;
            };

            struct AzeriteEmpoweredItemEntry
            {
                uint32 ID;
                int32 ItemID;
                int32 AzeriteTierUnlockSetID;
                int32 AzeritePowerSetID;
            };

            struct AzeriteItemEntry
            {
                uint32 ID;
                int32 ItemID;
            };

            struct AzeriteTierUnlockEntry
            {
                uint32 ID;
                uint8 ItemCreationContext;
                uint8 Tier;
                uint8 AzeriteLevel;
                uint8 AzeriteTierUnlockSetId;
            };

            struct AzeritePowerEntry
            {
                uint32 ID;
                int32 SpellID;
                int32 ItemBonusListID;
                int32 SpecSet;
                int32 Unk0;
            };

            struct AzeritePowerSetMemberEntry
            {
                uint32 ID;
                int16 AzeritePowerID;
                uint8 Class;
                uint8 Tier;
                uint8 OrderIndex;
                uint16 AzeritePowerSetID;
            };

            struct BattlePetAbilityTurn
            {
                uint16 AbilityID;
                uint16 Unk1;
                uint8 TurnDelay;
                uint8 Unk2;
                int8 ProcType;
                uint32 ID;
            };

            struct BattlePetAbilityState
            {
                uint32 Id;
                int32 Value;
                uint16 AbilityId;
                uint8 StateId;
            };

            struct BattlePetAbility
            {
                uint32 AbilityId;
                uint32 IconId;
                LocalizedString* Name;                                  // 6 - name text
                LocalizedString* Description;                           // 7 - description text
                uint16 Unk1;
                int8 FamilyId;
                uint8 Unk2;
                uint32 Cooldown;
            };

            struct BattlePetSpeciesXAbility
            {
                uint32 Id;
                uint16 SpeciesId;
                uint16 AbilityId;
                uint8 RequiredLevel;
                int8 SlotId;
            };

            #define PROJECT_DBC_MAX_PET_BATTLE_EFFECT_VALUES 6
            struct BattlePetAbilityEffect
            {
                uint16 TurnID;
                uint16 Unk1;
                uint16 Aura;
                uint16 Effect;
                int16 Values[PROJECT_DBC_MAX_PET_BATTLE_EFFECT_VALUES];
                uint8 TurnInstanceID;
                uint32 ID;

                bool IsPeriodic() const;
                bool HasVariance() const;
                uint32 GetEffectPropertyType() const;
                uint32 GetHitChance() const;
            };

            struct BattlePetEffectProperties
            {
                uint32 ID;
                LocalizedString* Values[PROJECT_DBC_MAX_PET_BATTLE_EFFECT_VALUES];
                uint16 EffectType;
                uint8 Misc[PROJECT_DBC_MAX_PET_BATTLE_EFFECT_VALUES];
            };

            struct CharShipmentContainer
            {
                uint32 ID;
                char* Name;
                char* Description;
                uint32 OverrideDisplayID1;
                uint16 Unk1;
                uint16 OverrideIfAmountMet[2];
                uint16 ShipmentAmountNeeded[2];
                uint16 Unk2;
                uint8 Unk3;
                uint8 Unk4;
                uint8 GarrisonType;
                uint8 Unk5;
                uint8 Unk6;
                uint8 Unk7;
                uint32 Unk8;
            };

            struct CharShipment
            {
                uint32 ID;
                uint32 Unk;
                uint32 Duration;
                uint32 SpellReward;
                uint32 Icon;
                uint32 SpellTutorial;
                uint16 ShipmentContainerID;
                uint16 FollowerID;
                uint8 MaxCount;
                uint8 Unk2;
            };

            struct GarrAbilityEffect
            {
                float  ModMin;
                float  ModMax;
                float  Amount;
                uint32 MiscValueA;
                uint16 AbilityID;
                uint8 EffectType;
                uint8 TargetMask;
                uint8 CounterMechanicTypeID;
                uint8 Unk1;
                uint8 Unk2;
                uint8 Unk3;
                uint32 ID;
            };

            struct GarrClassSpecPlayerCond
            {
                uint32 ID;
                uint32 IconID;
                char* Name;
                uint8 Index;
                uint32 ClassSpec;
                uint32 Unk1;
                uint32 GarrStringID;
            };

            struct GarrEncounterXMechanic
            {
                uint32 ID;
                uint32 EncounterID;
                uint8  MechanicID;
                uint8  ClassID;
            };


            struct GarrFollowerLevelXP
            {
                uint32 ID;
                uint16 RequiredExperience;
                uint16 UnkExp;
                uint8  Level;
                uint8  Class;
            };

            struct GarrFollowerType
            {
                uint32 ID;
                uint16 MaxItemLevel;
                uint8  Flags;
                uint8  Unk1;
                uint8  Unk2;
                uint8  Unk3;
                uint8  Unk4;
                uint8  Unk5;
            };

            struct GarrFollowerXAbility
            {
                uint32 ID;
                uint16 GarrAbilityID;
                uint8 FactionIndex;
                uint16 GarrFollowerID;
            };

            struct GarrFollSupportSpell
            {
                uint32 ID;
                uint32 AllianceSpellID;
                uint32 HordeSpellID;
                uint8 Unk;
                uint32 GarrFollowerID;
            };

            struct GarrMechanic
            {
                uint32 ID;
                float Unk1;
                uint8 MechanicTypeID;
                uint32 Unk2;
            };

            struct GarrMechanicType
            {
                char* Environment;
                char* EnvironmentDesc;
                uint32 EnvironmentTextureID;
                uint8 Type;
                uint32 ID;
            };

            struct GarrMission
            {
                int32  Duration;
                int32  OfferTime;
                LocalizedString const* Name;
                LocalizedString const* Description;
                LocalizedString const* Location;
                DBCPosition2D Map;
                DBCPosition2D Pos;
                uint16 RequiredItemLevel;
                uint16 LocPrefixID;
                uint16 CurrencyID;
                uint8 RequiredLevel;
                uint8 GarrMechanicTypeRecID;
                uint8 RequiredFollowersCount;
                uint8 Category;
                uint8 MissionType;
                uint8 FollowerType;
                uint8 BaseBonusChance;
                uint8 LostChance;
                uint8 GarrTypeID;
                uint32 ID;
                int32 TravelTime;
                uint32 SubCategory2;
                uint32 SubCategory1;
                int32 CurrencyCost;
                uint32 Flags;
                uint32 RewardFollowerExperience;
                int32 AreaID;
                int32 Unk3;
                uint32 Unk;
            };

            struct GarrMissionXEncounter
            {
                uint8 Unk1;
                uint32 ID;
                uint32 MissionID;
                uint32 EncounterID;
                uint32 Unk2;
            };

            struct GarrTalentTree
            {
                uint32 ID;
                uint8  Unk1;
                uint8  Unk2;
                uint32 ClassID;
                uint32 GarrTypeID;
            };

            struct GarrTalent
            {
                uint32 Icon;
                char* Name;
                char* Description;
                uint32 InitialCooldown;
                uint8 TierLevel;
                uint8 Index;
                uint8 Unk1;
                uint32 ID;
                uint32 GarrTalentTree;
                uint32 Unk2;
                uint32 ModifierTreeID;
                uint32 InitialCurrencyAmount;
                uint32 InitialCurrencyID;
                uint32 Unk4;
                uint32 SpellID;
                uint32 Unk5;
                uint32 ChangeCurrencyAmount;
                uint32 ChangeCurrencyID;
                uint32 ChangeCooldown;
                uint32 Unk6;
            };

            struct GarrType
            {
                uint32 ID;
                uint32 Unk1;
                uint32 CurrencyResource1;
                uint32 CurrencyResource2;
                uint32 Expansion;
                uint32 MapID;
            };

            struct GroupFinderActivityEntry
            {
                uint32 ID;
                char* Name;
                char* DifficultyString;
                uint16  RequiredILvl;
                uint16  MapID;
                uint16  ZoneID;
                uint8  CategoryID;
                uint8  ActivityGroupID;
                uint8  Unk1;
                uint8  MinLevel;
                uint8  MaxLevel;
                uint8  Difficulty;
                uint8  Type;
                uint8  Unk2;
                uint8  MaxPlayers;
            };

            struct GroupFinderCategoryEntry
            {
                uint32 ID;
                char* Name;
                uint8 Unk1;
                uint8 Unk2;
            };

            struct ItemNameDescription
            {
                uint32 ID;
                char* Description;
                uint32 Color;
            };

            struct QuestV2CliTaskEntry
            {
                uint64 FiltRaces;
                char* QuestTitle;
                char* BulletText;
                uint32  StartItem;
                uint16 UniqueBitFlag;
                uint16 ConditionID;
                uint16 FiltClasses;
                uint16 FiltCompletedQuest[3];
                uint16 FiltMinSkillID;
                uint16 WorldStateExpressionID;
                uint8 FiltActiveQuest;
                uint8 FiltCompletedQuestLogic;
                uint8 FiltMaxFactionID;
                uint8 FiltMaxFactionValue;
                uint8 FiltMaxLevel;
                uint8 FiltMinFactionID;
                uint8 FiltMinFactionValue;
                uint8 FiltMinLevel;
                uint8 FiltMinSkillValue;
                uint8 FiltNonActiveQuest;
                uint32 ID;
                uint32 BreadCrumbID;
                uint32 QuestInfoID;
                uint32 SandboxScalingID;
            };

            struct MapChallengeMode
            {
                uint32 ID;
                char* Name;
                uint16 MapID;
                uint16 TimeBronze;
                uint16 TimeSilver;
                uint16 TimeGold;
                uint8 Unk;
            };

            struct PvpTalent
            {
                uint32      ID;                                             // 0
                char*       Description_lang;                               // 1
                uint32      SpellID;                                        // 2
                uint32      OverridesSpellID;                               // 3 spellid that is replaced by talent
                uint32      ActionBarSpellID;                               // 4
                uint32      TierID;                                         // 5
                uint32      ColumnIndex;                                    // 6
                uint32      Flags;                                          // 7
                uint32      ClassID;                                        // 8
                uint32      SpecID;                                         // 9
                uint32      Role;                                           // 10
            };

            struct PvpTalentUnlock
            {
                uint32 ID;
                uint32 TierID;
                uint32 ColumnIndex;
                uint32 HonorLevel;
            };

            struct PvpReward
            {
                uint32 ID;
                uint32 HonorLevel;
                uint32 PrestigeLevel;
                uint32 Reward;
            };

            struct QuestPOIPoint
            {
                uint32 POI;
                int16 X;
                int16 Y;
                uint32 ID;
            };

            struct QuestPOIBlob
            {
                uint32 ID;
                uint16 MapID;
                uint16 WorldMapAreaID;
                uint8 NumPoints;
                uint8 Unk1;
                uint32 Unk2;
                uint32 Unk3;
                uint32 Unk4;
            };

            struct ResearchSite
            {
                uint32 ID;
                uint32 POI;
                char* Name;
                uint16 MapID;
                uint32 Icon;
            };

            struct ResearchProject
            {
                char* Name;
                char* Description;
                uint32 RewardSpell;
                char* Icon;
                uint16 Race;
                uint8 Rare;
                uint8 MaxKeystonesAllowed;
                uint32 ID;
                uint32 RequiredCurrency;
            };

            struct ResearchBranch
            {
                uint32 ID;
                char* RaceName;
                char* Icon;
                uint32 KeystoneItemId;
                uint16 Currency;
                uint8 Unk;
            };

            struct RewardPack
            {
                uint32 ID;
                uint32 Money;
                float ArtifactXPMultiplier;
                uint8 ArtifactXPDifficulty;
                uint8 ArtifactXPCategoryID;
                uint32 CharTitleID;
                uint32 TreasurePickerID;
            };

            struct RewardPackXItem
            {
                uint32 ID;
                uint32 ItemID;
                uint32 ItemQuantity;
                uint32 RewardPackID;
            };

            struct SceneScriptPackageMember
            {
                uint32 ID;
                uint16 PackageID;
                uint16 ScriptID;
                uint16 FrameworkPackageID;
                uint8 Order;
            };

            struct SpecSetMemberEntry
            {
                uint32 ID;
                uint32 CharSpecialization;
                uint32 SpecSetMemberID;
            };

            struct SpellKeyboundOverride
            {
                uint32 ID;
                char* Function;
                int32 Data;
                int8 Type;
            };

            struct SpellReagentsCurrency
            {
                uint32 ID;
                uint32 SpellID;
                uint16 CurrencyID;
                uint16 CurrencyCount;
            };

            struct VignetteEntry
            {
                uint32 ID;
                char* Name;
                float X;
                float Y;
                uint32 QuestFeedbackEffectId;
                uint32 Flags;
                uint32 PlayerCondition;
                uint32 QuestID;
            };

            struct UiCamera
            {
                uint32 ID;
                char* Name;
                float Pos1[3];
                float Pos2[3];
                float Pos3[3];
                int16 Unk1;
                uint8 CameraType;
                int8 Unk2;
                uint8 Unk3;
                uint32 Unk4;
            };

            struct WorldStateUI
            {
                char* Texture;
                char* TextureFlag;
                char* FlagText;
                char* Text;
                char* Description;
                int16 MapID;
                uint16 ZoneID;
                uint16 PhaseID;
                uint16 PhaseGroupID;
                uint16 FlagWorldState;
                uint16 ExtendedUIStateVariable[3];
                uint8 OrderIndex;
                uint8 PhaseUseFlags;
                uint8 Type;
                uint32 ID;
                int32 DynamicIconFileID;
                int32 DynamicFlashIconFileID;
            };
        }

        #if defined(__GNUC__)
        #pragma pack()
        #else
        #pragma pack(pop)
        #endif

        TC_GAME_API extern DB2Storage<Structs::AdventureJournal>                AdventureJournal;
        TC_GAME_API extern DB2Storage<Structs::AdventureMapPOI>                 AdventureMapPOI;
        TC_GAME_API extern DB2Storage<Structs::AzeritePowerEntry>               sAzeritePowerStore;
        TC_GAME_API extern DB2Storage<Structs::BattlePetAbility>                BattlePetAbility;
        TC_GAME_API extern DB2Storage<Structs::BattlePetAbilityState>           BattlePetAbilityState;
        TC_GAME_API extern DB2Storage<Structs::BattlePetAbilityTurn>            BattlePetAbilityTurn;
        TC_GAME_API extern DB2Storage<Structs::BattlePetAbilityEffect>          BattlePetAbilityEffect;
        TC_GAME_API extern DB2Storage<Structs::BattlePetSpeciesXAbility>        BattlePetSpeciesXAbility;
        TC_GAME_API extern DB2Storage<Structs::BattlePetEffectProperties>       BattlePetEffectProperties;
        TC_GAME_API extern DB2Storage<Structs::CharShipment>                    CharShipment;
        TC_GAME_API extern DB2Storage<Structs::CharShipmentContainer>           CharShipmentContainer;
        TC_GAME_API extern DB2Storage<Structs::GarrAbilityEffect>               GarrAbilityEffect;
        TC_GAME_API extern DB2Storage<Structs::GarrClassSpecPlayerCond>         GarrClassSpecPlayerCond;
        TC_GAME_API extern DB2Storage<Structs::GarrEncounterXMechanic>          GarrEncounterXMechanic;
        TC_GAME_API extern DB2Storage<Structs::GarrFollowerLevelXP>             GarrFollowerLevelXP;
        TC_GAME_API extern DB2Storage<Structs::GarrFollowerType>                GarrFollowerType;
        TC_GAME_API extern DB2Storage<Structs::GarrFollSupportSpell>            GarrFollSupportSpell;
        TC_GAME_API extern DB2Storage<Structs::GarrFollowerXAbility>            GarrFollowerXAbility;
        TC_GAME_API extern DB2Storage<Structs::GarrMechanic>                    GarrMechanic;
        TC_GAME_API extern DB2Storage<Structs::GarrMechanicType>                GarrMechanicType;
        TC_GAME_API extern DB2Storage<Structs::GarrMission>                     GarrMission;
        TC_GAME_API extern DB2Storage<Structs::GarrMissionXEncounter>           GarrMissionXEncounter;
        TC_GAME_API extern DB2Storage<Structs::GarrTalent>                      GarrTalent;
        TC_GAME_API extern DB2Storage<Structs::GarrTalentTree>                  GarrTalentTree;
        TC_GAME_API extern DB2Storage<Structs::GarrType>                        GarrType;
        TC_GAME_API extern DB2Storage<Structs::GroupFinderActivityEntry>        sGroupFinderActivityStore;
        TC_GAME_API extern DB2Storage<Structs::GroupFinderCategoryEntry>        sGroupFinderCategoryStore;
        TC_GAME_API extern DB2Storage<Structs::ItemNameDescription>             ItemNameDescription;
        TC_GAME_API extern DB2Storage<Structs::MapChallengeMode>                MapChallengeMode;
        TC_GAME_API extern DB2Storage<Structs::PvpTalent>                       PvpTalent;
        TC_GAME_API extern DB2Storage<Structs::QuestPOIPoint>                   QuestPOIPoint;
        TC_GAME_API extern DB2Storage<Structs::QuestPOIBlob>                    QuestPOIBlob;
        TC_GAME_API extern DB2Storage<Structs::QuestV2CliTaskEntry>             sQuestV2CliTaskStore;
        TC_GAME_API extern DB2Storage<Structs::ResearchSite>                    ResearchSite;
        TC_GAME_API extern DB2Storage<Structs::ResearchProject>                 ResearchProject;
        TC_GAME_API extern DB2Storage<Structs::ResearchBranch>                  ResearchBranch;
        TC_GAME_API extern DB2Storage<Structs::RewardPack>                      RewardPack;
        TC_GAME_API extern DB2Storage<Structs::RewardPackXItem>                 RewardPackXItem;
        TC_GAME_API extern DB2Storage<Structs::SceneScriptPackageMember>        SceneScriptPackageMember;
        TC_GAME_API extern DB2Storage<Structs::SpellKeyboundOverride>           SpellKeyboundOverride;
        TC_GAME_API extern DB2Storage<Structs::SpellReagentsCurrency>           SpellReagentsCurrency;
        TC_GAME_API extern DB2Storage<Structs::UiCamera>                        UiCamera;
        TC_GAME_API extern DB2Storage<Structs::VignetteEntry>                   VignetteStore;
        TC_GAME_API extern DB2Storage<Structs::WorldStateUI>                    WorldStateUI;
    }
}

#endif
