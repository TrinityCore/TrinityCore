#ifndef PROJECT_DBC_DEFINITIONS_LOAD_INFO
#define PROJECT_DBC_DEFINITIONS_LOAD_INFO

#include "DB2DatabaseLoader.h"
#include "DB2Metadata.h"
#include "HotfixDatabase.h"

namespace PROJECT
{
    namespace DataStores
    {
        namespace LoadInfo
        {
            struct AdventureJournal
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Title" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { false, FT_STRING_NOT_LOCALIZED, "ButtonText" },
                        { false, FT_INT, "Unk1" },
                        { false, FT_INT, "Unk2" },
                        { false, FT_STRING_NOT_LOCALIZED, "Unk3" },
                        { false, FT_STRING_NOT_LOCALIZED, "ContinueText" },
                        { false, FT_SHORT, "Unk4" },
                        { false, FT_SHORT, "Unk5" },
                        { false, FT_SHORT, "QuestID" },
                        { false, FT_SHORT, "Unk6_1" },
                        { false, FT_SHORT, "Unk6_2" },
                        { false, FT_SHORT, "Unk7" },
                        { false, FT_SHORT, "Unk8" },
                        { false, FT_BYTE, "Unk9" },
                        { false, FT_BYTE, "Unk10" },
                        { false, FT_BYTE, "Type" },
                        { false, FT_BYTE, "Unk11" },
                        { false, FT_BYTE, "Unk12" },
                        { false, FT_BYTE, "Unk13" },
                        { false, FT_BYTE, "Unk14_1" },
                        { false, FT_BYTE, "Unk14_2" },
                        { false, FT_INT, "Unk15" },
                        { false, FT_INT, "Unk16" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AdventureJournalMeta::Instance(), PROJECT_HOTFIX_SEL_ADVENTURE_JOURNAL);
                    return &loadInfo;
                }
            };

            struct AdventureMapPOI
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_FLOAT, "POI0" },
                        { false, FT_FLOAT, "POI1" },
                        { false, FT_INT, "Unk1" },
                        { false, FT_STRING_NOT_LOCALIZED, "Title" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { false, FT_BYTE, "Unk2" },
                        { false, FT_SHORT, "Unk3" },
                        { false, FT_SHORT, "QuestID" },
                        { false, FT_INT, "Unk4" },
                        { false, FT_INT, "Unk5" },
                        { false, FT_INT, "Unk6" },
                        { false, FT_INT, "Unk7" },
                        { false, FT_INT, "Unk8" },
                        { false, FT_INT, "Unk9" }
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AdventureMapPOIMeta::Instance(), PROJECT_HOTFIX_SEL_ADVENTURE_MAP_POI);
                    return &loadInfo;
                }
            };

            struct AzeriteEmpoweredItemLoadInfo
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "ItemID" },
                        { false, FT_INT, "AzeriteTierUnlockSetID" },
                        { false, FT_INT, "AzeritePowerSetID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AzeriteEmpoweredItemMeta::Instance(), PROJECT_HOTFIX_SEL_AZERITE_EMPOWERED_ITEM);
                    return &loadInfo;
                }
            };

            struct AzeriteItemLoadInfo
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "ItemID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AzeriteItemMeta::Instance(), PROJECT_HOTFIX_SEL_AZERITE_ITEM);
                    return &loadInfo;
                }
            };

            struct AzeriteTierUnlockLoadInfo
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_BYTE, "ItemCreationContext" },
                        { false, FT_BYTE, "Tier" },
                        { false, FT_BYTE, "AzeriteLevel" },
                        { false, FT_BYTE, "AzeriteTierUnlockSetId" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AzeriteTierUnlockMeta::Instance(), PROJECT_HOTFIX_SEL_AZERITE_TIER_UNLOCK);
                    return &loadInfo;
                }
            };

            struct AzeritePowerLoadInfo
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "SpellID" },
                        { true, FT_INT, "ItemBonusListID" },
                        { true, FT_INT, "SpecSet" },
                        { true, FT_INT, "Unk0" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AzeritePowerMeta::Instance(), PROJECT_HOTFIX_SEL_AZERITE_POWER);
                    return &loadInfo;
                }
            };

            struct AzeritePowerSetMemberLoadInfo
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "AzeritePowerID" },
                        { false, FT_BYTE, "Class" },
                        { false, FT_BYTE, "Tier" },
                        { false, FT_BYTE, "OrderIndex" },
                        { false, FT_SHORT, "AzeritePowerSetID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, AzeritePowerSetMemberMeta::Instance(), PROJECT_HOTFIX_SEL_AZERITE_POWER_SET_MEMBER);
                    return &loadInfo;
                }
            };

            struct BattlePetAbility
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "IconID" },
                        { false, FT_STRING, "Name" },
                        { false, FT_STRING, "Description" },
                        { false, FT_SHORT, "Unk1" },
                        { true, FT_BYTE, "FamilyId" },
                        { false, FT_BYTE, "Unk2" },
                        { false, FT_INT, "Cooldown" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, BattlePetAbilityMeta::Instance(), PROJECT_HOTFIX_SEL_BATTLE_PET_ABILITY);
                    return &loadInfo;
                }
            };

            struct BattlePetAbilityState
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "Value" },
                        { false, FT_SHORT, "AbilityId" },
                        { false, FT_BYTE, "StateId" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, BattlePetAbilityStateMeta::Instance(), PROJECT_HOTFIX_SEL_BATTLE_PET_ABILITY_STATE);
                    return &loadInfo;
                }
            };

            struct BattlePetAbilityEffect
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_SHORT, "TurnID" },
                        { false, FT_SHORT, "Unk1" },
                        { false, FT_SHORT, "Aura" },
                        { false, FT_SHORT, "Effect" },
                        { false, FT_SHORT, "Values1" },
                        { false, FT_SHORT, "Values2" },
                        { false, FT_SHORT, "Values3" },
                        { false, FT_SHORT, "Values4" },
                        { false, FT_SHORT, "Values5" },
                        { false, FT_SHORT, "Values6" },
                        { false, FT_BYTE, "TurnInstanceID" },
                        { false, FT_INT, "ID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, BattlePetAbilityEffectMeta::Instance(), PROJECT_HOTFIX_SEL_BATTLE_PET_ABILITY_EFFECT);
                    return &loadInfo;
                }
            };

            struct BattlePetAbilityTurn
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_SHORT, "AbilityID" },
                        { false, FT_SHORT, "Unk1" },
                        { false, FT_BYTE, "TurnDelay" },
                        { false, FT_BYTE, "Unk2" },
                        { true, FT_BYTE, "ProcType" },
                        { false, FT_INT, "ID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, BattlePetAbilityTurnMeta::Instance(), PROJECT_HOTFIX_SEL_BATTLE_PET_ABILITY_TURN);
                    return &loadInfo;
                }
            };

            struct BattlePetSpeciesXAbility
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "SpeciesId" },
                        { false, FT_SHORT, "AbilityID" },
                        { false, FT_BYTE, "RequiredLevel" },
                        { true, FT_BYTE, "SlotId" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, BattlePetSpeciesXAbilityMeta::Instance(), PROJECT_HOTFIX_SEL_BATTLE_PET_ABILITY_SPECIES_X_ABILITY);
                    return &loadInfo;
                }
            };

            struct BattlePetEffectProperties
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_SHORT, "ID" },
                        { false, FT_STRING, "Values1" },
                        { false, FT_STRING, "Values2" },
                        { false, FT_STRING, "Values3" },
                        { false, FT_STRING, "Values4" },
                        { false, FT_STRING, "Values5" },
                        { false, FT_STRING, "Values6" },
                        { false, FT_SHORT, "EffectType" },
                        { false, FT_BYTE, "Misc1" },
                        { false, FT_BYTE, "Misc2" },
                        { false, FT_BYTE, "Misc3" },
                        { false, FT_BYTE, "Misc4" },
                        { false, FT_BYTE, "Misc5" },
                        { false, FT_BYTE, "Misc6" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, BattlePetEffectPropertiesMeta::Instance(), PROJECT_HOTFIX_SEL_BATTLE_PET_EFFECT_PROPERTIES);
                    return &loadInfo;
                }
            };

            struct CharShipmentContainer
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { false, FT_INT, "OverrideDisplayID1" },
                        { false, FT_SHORT, "Unk1" },
                        { false, FT_SHORT, "OverrideIfAmountMet1" },
                        { false, FT_SHORT, "OverrideIfAmountMet2" },
                        { false, FT_SHORT, "ShipmentAmountNeeded1" },
                        { false, FT_SHORT, "ShipmentAmountNeeded2" },
                        { false, FT_SHORT, "Unk2" },
                        { false, FT_BYTE, "Unk3" },
                        { false, FT_BYTE, "Unk4" },
                        { false, FT_BYTE, "GarrisonType" },
                        { false, FT_BYTE, "Unk5" },
                        { false, FT_BYTE, "Unk6" },
                        { false, FT_BYTE, "Unk7" },
                        { false, FT_INT, "Unk8" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, CharShipmentContainerMeta::Instance(), PROJECT_HOTFIX_SEL_CHAR_SHIPMENT_CONTAINER);
                    return &loadInfo;
                }
            };

            struct CharShipment
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "Unk" },
                        { false, FT_INT, "Duration" },
                        { false, FT_INT, "SpellReward" },
                        { false, FT_INT, "Icon" },
                        { false, FT_INT, "SpellTutorial" },
                        { false, FT_SHORT, "ShipmentContainerID" },
                        { false, FT_SHORT, "FollowerID" },
                        { false, FT_BYTE, "MaxCount" },
                        { false, FT_BYTE, "Unk2" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, CharShipmentMeta::Instance(), PROJECT_HOTFIX_SEL_CHAR_SHIPMENT);
                    return &loadInfo;
                }
            };

            struct GarrAbilityEffect
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_FLOAT, "ModMin" },
                        { false, FT_FLOAT, "ModMax" },
                        { false, FT_FLOAT, "Amount" },
                        { false, FT_INT, "MiscValueA" },
                        { false, FT_SHORT, "AbilityID" },
                        { false, FT_BYTE, "EffectType" },
                        { false, FT_BYTE, "TargetMask" },
                        { false, FT_BYTE, "CounterMechanicTypeID" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_BYTE, "Unk2" },
                        { false, FT_BYTE, "Unk3" },
                        { false, FT_INT, "ID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrAbilityEffectMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_ABILITY_EFFECT);
                    return &loadInfo;
                }
            };

            struct GarrClassSpecPlayerCond
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "IconID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_BYTE, "Index" },
                        { false, FT_INT, "ClassSpec" },
                        { false, FT_INT, "Unk1" },
                        { false, FT_INT, "GarrStringID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrClassSpecPlayerCondMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_CLASS_SPEC_PLAYER_COND);
                    return &loadInfo;
                }
            };

            struct GarrEncounterXMechanic
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "EncounterID" },
                        { false, FT_BYTE, "MechanicID" },
                        { false, FT_BYTE, "ClassID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrEncounterXMechanicMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_ENCOUNTER_X_MECHANIC);
                    return &loadInfo;
                }
            };

            struct GarrFollowerLevelXP
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "RequiredExperience" },
                        { false, FT_SHORT, "UnkExp" },
                        { false, FT_BYTE, "Level" },
                        { false, FT_BYTE, "Class" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrFollowerLevelXPMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_FOLLOWER_LEVEL_X_P);
                    return &loadInfo;
                }
            };

            struct GarrFollowerType
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "MaxItemLevel" },
                        { false, FT_BYTE, "Flags" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_BYTE, "Unk2" },
                        { false, FT_BYTE, "Unk3" },
                        { false, FT_BYTE, "Unk4" },
                        { false, FT_BYTE, "Unk5" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrFollowerTypeMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_FOLLOWER_TYPE);
                    return &loadInfo;
                }
            };

            struct GarrFollSupportSpell
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "AllianceSpellID" },
                        { false, FT_INT, "HordeSpellID" },
                        { false, FT_BYTE, "Unk" },
                        { false, FT_INT, "GarrFollowerID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrFollSupportSpellMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_FOLL_SUPPORT_SPELL);
                    return &loadInfo;
                }
            };

            struct GarrFollowerXAbility
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "GarrAbilityID" },
                        { false, FT_BYTE, "FactionIndex" },
                        { false, FT_SHORT, "GarrFollowerID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrFollowerXAbilityMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_FOLLOWER_X_ABILITY);
                    return &loadInfo;
                }
            };

            struct GarrMechanic
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_FLOAT, "Unk1" },
                        { false, FT_BYTE, "MechanicTypeID" },
                        { false, FT_INT, "Unk2" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrMechanicMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_MECHANIC);
                    return &loadInfo;
                }
            };

            struct GarrMechanicType
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_STRING_NOT_LOCALIZED, "Environment" },
                        { false, FT_STRING_NOT_LOCALIZED, "EnvironmentDesc" },
                        { false, FT_INT, "EnvironmentTextureID" },
                        { false, FT_BYTE, "Type" },
                        { false, FT_INT, "ID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrMechanicTypeMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_MECHANIC_TYPE);
                    return &loadInfo;
                }
            };

            struct GarrMission
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { true, FT_INT, "Duration" },
                        { true, FT_INT, "OfferTime" },
                        { false, FT_STRING, "Name" },
                        { false, FT_STRING, "Description" },
                        { false, FT_STRING, "Location" },
                        { false, FT_FLOAT, "MapX" },
                        { false, FT_FLOAT, "MapY" },
                        { false, FT_FLOAT, "PosX" },
                        { false, FT_FLOAT, "PosY" },
                        { false, FT_SHORT, "RequiredItemLevel" },
                        { false, FT_SHORT, "LocPrefixID" },
                        { false, FT_SHORT, "CurrencyID" },
                        { false, FT_BYTE, "RequiredLevel" },
                        { false, FT_BYTE, "GarrMechanicTypeRecID" },
                        { false, FT_BYTE, "RequiredFollowersCount" },
                        { false, FT_BYTE, "Category" },
                        { false, FT_BYTE, "MissionType" },
                        { false, FT_BYTE, "FollowerType" },
                        { false, FT_BYTE, "BaseBonusChance" },
                        { false, FT_BYTE, "LostChance" },
                        { false, FT_BYTE, "GarrTypeID" },
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "TravelTime" },
                        { false, FT_INT, "SubCategory2" },
                        { false, FT_INT, "SubCategory1" },
                        { true, FT_INT, "CurrencyCost" },
                        { false, FT_INT, "Flags" },
                        { false, FT_INT, "RewardFollowerExperience" },
                        { true, FT_INT, "AreaID" },
                        { true, FT_INT, "Unk3" },
                        { false, FT_INT, "Unk" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrMissionMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_MISSION);
                    return &loadInfo;
                }
            };

            struct GarrMissionXEncounter
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "MissionID" },
                        { false, FT_INT, "EncounterID" },
                        { false, FT_INT, "Unk2" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrMissionXEncounterMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_MISSION_X_ENCOUNTER);
                    return &loadInfo;
                }
            };

            struct GarrTalentTree
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_BYTE, "Unk2" },
                        { false, FT_INT, "ClassID" },
                        { false, FT_INT, "GarrTypeID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrTalentTreeMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_TALENT_TREE);
                    return &loadInfo;
                }
            };

            struct GarrType
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "Unk1" },
                        { false, FT_INT, "CurrencyResource1" },
                        { false, FT_INT, "CurrencyResource2" },
                        { false, FT_INT, "Expansion" },
                        { false, FT_INT, "MapID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrTypeMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_TYPE);
                    return &loadInfo;
                }
            };

            struct GarrTalent
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "Icon" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { false, FT_INT, "InitialCooldown" },
                        { false, FT_BYTE, "TierLevel" },
                        { false, FT_BYTE, "Index" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "GarrTalentTree" },
                        { false, FT_INT, "Unk2" },
                        { false, FT_INT, "Unk3" },
                        { false, FT_INT, "InitialCurrencyAmount" },
                        { false, FT_INT, "InitialCurrencyID" },
                        { false, FT_INT, "Unk4" },
                        { false, FT_INT, "SpellID" },
                        { false, FT_INT, "Unk5" },
                        { false, FT_INT, "ChangeCurrencyAmount" },
                        { false, FT_INT, "ChangeCurrencyID" },
                        { false, FT_INT, "ChangeCooldown" },
                        { false, FT_INT, "Unk6" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GarrTalentMeta::Instance(), PROJECT_HOTFIX_SEL_GARR_TALENT);
                    return &loadInfo;
                }
            };

            struct GroupFinderActivity
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_STRING_NOT_LOCALIZED, "DifficultyString" },
                        { false, FT_SHORT, "RequiredILvl" },
                        { false, FT_SHORT, "MapID" },
                        { false, FT_SHORT, "ZoneID" },
                        { false, FT_BYTE, "CategoryID" },
                        { false, FT_BYTE, "ActivityGroupID" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_BYTE, "MinLevel" },
                        { false, FT_BYTE, "MaxLevel" },
                        { false, FT_BYTE, "Difficulty" },
                        { false, FT_BYTE, "Type" },
                        { false, FT_BYTE, "Unk2" },
                        { false, FT_BYTE, "MaxPlayers" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GroupFinderActivityMeta::Instance(), PROJECT_HOTFIX_SEL_GROUP_FINDER_ACTIVITY);
                    return &loadInfo;
                }
            };

            struct GroupFinderCategory
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_BYTE, "Unk2" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, GroupFinderCategoryMeta::Instance(), PROJECT_HOTFIX_SEL_GROUP_FINDER_CATEGORY);
                    return &loadInfo;
                }
            };

            struct ItemNameDescription
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { true, FT_INT, "Color" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, ItemNameDescriptionMeta::Instance(), PROJECT_HOTFIX_SEL_ITEM_NAME_DESCRIPTION);
                    return &loadInfo;
                }
            };

            struct MapChallengeMode
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_SHORT, "MapID" },
                        { false, FT_SHORT, "TimeBronze" },
                        { false, FT_SHORT, "TimeSilver" },
                        { false, FT_SHORT, "TimeGold" },
                        { false, FT_BYTE, "Unk" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, MapChallengeModeMeta::Instance(), PROJECT_HOTFIX_SEL_MAP_CHALLENGE_MODE);
                    return &loadInfo;
                }
            };

            struct QuestPOIPoint
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "POI" },
                        { true, FT_SHORT, "X" },
                        { true, FT_SHORT, "Y" },
                        { false, FT_INT, "ID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, QuestPOIPointMeta::Instance(), PROJECT_HOTFIX_SEL_QUEST_POI_POINT);
                    return &loadInfo;
                }
            };

            struct QuestPOIBlob
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "MapID" },
                        { false, FT_SHORT, "WorldMapAreaID" },
                        { false, FT_BYTE, "NumPoints" },
                        { false, FT_BYTE, "Unk1" },
                        { false, FT_INT, "Unk2" },
                        { false, FT_INT, "Unk3" },
                        { false, FT_INT, "Unk4" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, QuestPOIBlobMeta::Instance(), PROJECT_HOTFIX_SEL_QUEST_POI_BLOB);
                    return &loadInfo;
                }
            };

            struct QuestV2CliTask
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { true, FT_LONG, "FiltRaces" },
                        { false, FT_STRING_NOT_LOCALIZED, "QuestTile" },
                        { false, FT_STRING_NOT_LOCALIZED, "BulletText" },
                        { true, FT_INT, "StartItem" },
                        { false, FT_SHORT, "UniqueBitFlag" },
                        { false, FT_SHORT, "ConditionID" },
                        { false, FT_SHORT, "FiltClasses" },
                        { false, FT_SHORT, "FiltCompletedQuest1" },
                        { false, FT_SHORT, "FiltCompletedQuest2" },
                        { false, FT_SHORT, "FiltCompletedQuest3" },
                        { false, FT_SHORT, "FiltMinSkillID" },
                        { false, FT_SHORT, "WorldStateExpressionID" },
                        { false, FT_BYTE, "FiltActiveQuest" },
                        { false, FT_BYTE, "FiltCompletedQuestLogic" },
                        { false, FT_BYTE, "FiltMaxFactionID" },
                        { false, FT_BYTE, "FiltMaxFactionValue" },
                        { false, FT_BYTE, "FiltMaxLevel" },
                        { false, FT_BYTE, "FiltMinFactionID" },
                        { false, FT_BYTE, "FiltMinFactionValue" },
                        { false, FT_BYTE, "FiltMinLevel" },
                        { false, FT_BYTE, "FiltMinSkillValue" },
                        { false, FT_BYTE, "FiltNonActiveQuest" },
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "BreadCrumbID" },
                        { false, FT_INT, "QuestInfoID" },
                        { false, FT_INT, "SandboxScalingID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, QuestV2CliTaskMeta::Instance(), PROJECT_HOTFIX_SEL_QUEST_V2_CLI_TASK);
                    return &loadInfo;
                }
            };

            struct ResearchSite
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "POI" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_SHORT, "MapID" },
                        { false, FT_INT, "Icon" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, ResearchSiteMeta::Instance(), PROJECT_HOTFIX_SEL_RESEARCH_SITE);
                    return &loadInfo;
                }
            };

            struct ResearchProject
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { false, FT_INT, "RewardSpell" },
                        { false, FT_STRING_NOT_LOCALIZED, "Icon" },
                        { false, FT_SHORT, "Race" },
                        { false, FT_BYTE, "Rare" },
                        { false, FT_BYTE, "MaxKeystonesAllowed" },
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "RequiredCurrency" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, ResearchProjectMeta::Instance(), PROJECT_HOTFIX_SEL_RESEARCH_PROJECT);
                    return &loadInfo;
                }
            };

            struct ResearchBranch
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "RaceName" },
                        { false, FT_STRING_NOT_LOCALIZED, "Icon" },
                        { false, FT_INT, "KeystoneItemId" },
                        { false, FT_SHORT, "Currency" },
                        { false, FT_BYTE, "Unk" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, ResearchBranchMeta::Instance(), PROJECT_HOTFIX_SEL_RESEARCH_BRANCH);
                    return &loadInfo;
                }
            };

            struct SceneScriptPackageMember
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_SHORT, "PackageID" },
                        { false, FT_SHORT, "ScriptID" },
                        { false, FT_SHORT, "FrameworkPackageID" },
                        { false, FT_BYTE, "Order" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, SceneScriptPackageMemberMeta::Instance(), PROJECT_HOTFIX_SEL_SCENE_SCRIPT_PACKAGE_MEMBER);
                    return &loadInfo;
                }
            };

            struct SpecSetMemberLoadInfo
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "CharSpecialization" },
                        { true, FT_INT, "SpecSetMemberID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, SpecSetMemberMeta::Instance(), PROJECT_HOTFIX_SEL_SPEC_SET_MEMBER);
                    return &loadInfo;
                }
            };

            struct SpellKeyboundOverride
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Function" },
                        { true, FT_INT, "Data" },
                        { true, FT_BYTE, "Type" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, SpellKeyboundOverrideMeta::Instance(), PROJECT_HOTFIX_SEL_SPELL_KEYBOUND_OVERRIDE);
                    return &loadInfo;
                }
            };

            struct SpellReagentsCurrency
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_INT, "SpellID" },
                        { false, FT_SHORT, "CurrencyID" },
                        { false, FT_SHORT, "CurrencyCount" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, SpellReagentsCurrencyMeta::Instance(), PROJECT_HOTFIX_SEL_SPELL_REAGENTS_CURRENCY);
                    return &loadInfo;
                }
            };

            struct UiCamera
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_FLOAT, "Pos1_1" },
                        { false, FT_FLOAT, "Pos1_2" },
                        { false, FT_FLOAT, "Pos1_3" },
                        { false, FT_FLOAT, "Pos2_1" },
                        { false, FT_FLOAT, "Pos2_2" },
                        { false, FT_FLOAT, "Pos2_3" },
                        { false, FT_FLOAT, "Pos3_1" },
                        { false, FT_FLOAT, "Pos3_2" },
                        { false, FT_FLOAT, "Pos3_3" },
                        { true, FT_SHORT, "Unk1" },
                        { false, FT_BYTE, "CameraType" },
                        { true, FT_BYTE, "Unk2" },
                        { false, FT_BYTE, "Unk3" },
                        { false, FT_INT, "Unk4" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, UiCameraMeta::Instance(), PROJECT_HOTFIX_SEL_UI_CAMERA);
                    return &loadInfo;
                }
            };

            struct Vignette
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_INT, "ID" },
                        { false, FT_STRING_NOT_LOCALIZED, "Name" },
                        { false, FT_FLOAT, "X" },
                        { false, FT_FLOAT, "Y" },
                        { false, FT_INT, "QuestFeedbackEffectId" },
                        { false, FT_INT, "Flags" },
                        { false, FT_INT, "PlayerCondition" },
                        { false, FT_INT, "QuestID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, VignetteMeta::Instance(), PROJECT_HOTFIX_SEL_VIGNETTE);
                    return &loadInfo;
                }
            };

            struct WorldStateUI
            {
                static DB2LoadInfo const* Instance()
                {
                    static DB2FieldMeta const fields[] =
                    {
                        { false, FT_STRING_NOT_LOCALIZED, "Texture" },
                        { false, FT_STRING_NOT_LOCALIZED, "TextureFlag" },
                        { false, FT_STRING_NOT_LOCALIZED, "FlagText" },
                        { false, FT_STRING_NOT_LOCALIZED, "Text" },
                        { false, FT_STRING_NOT_LOCALIZED, "Description" },
                        { true,  FT_SHORT, "MapID" },
                        { false, FT_SHORT, "ZoneID" },
                        { false, FT_SHORT, "PhaseID" },
                        { false, FT_SHORT, "PhaseGroupID" },
                        { false, FT_SHORT, "FlagWorldState" },
                        { false, FT_SHORT, "ExtendedUIStateVariable_1" },
                        { false, FT_SHORT, "ExtendedUIStateVariable_2" },
                        { false, FT_SHORT, "ExtendedUIStateVariable_3" },
                        { false, FT_BYTE, "OrderIndex" },
                        { false, FT_BYTE, "PhaseUseFlags" },
                        { false, FT_BYTE, "Type" },
                        { false, FT_INT, "ID" },
                        { true, FT_INT, "DynamicIconFileID" },
                        { true, FT_INT, "DynamicFlashIconFileID" },
                    };
                    static DB2LoadInfo const loadInfo(&fields[0], std::extent<decltype(fields)>::value, WorldStateUIMeta::Instance(), PROJECT_HOTFIX_SEL_WORLD_STATE_UI);
                    return &loadInfo;
                }
            };
        }
    }
}

#endif
