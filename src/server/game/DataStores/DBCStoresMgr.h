/*
 * Copyright (C) 2019+ ATieshCore <https://at-wow.org/>
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

#ifndef _DBCMGR_H
#define _DBCMGR_H

#include "Common.h"
#include "DBCStructure.h"
#include "Regex.h"
#include "Log.h"
#include "SharedDefines.h"
#include <tuple>
#include <map>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_map<uint32 /*ID*/, AchievementDBC> AchievementDBCMap;
typedef std::unordered_map<uint32 /*ID*/, AchievementCriteriaDBC> AchievementCriteriaDBCMap;
typedef std::unordered_map<uint32 /*ID*/, AreaTableDBC> AreaTableDBCMap;
typedef std::unordered_map<uint32 /*ID*/, AreaGroupDBC> AreaGroupDBCMap;
typedef std::unordered_map<uint32 /*ID*/, AreaPOIDBC> AreaPOIDBCMap;
typedef std::unordered_map<uint32 /*ID*/, AreaTriggerDBC> AreaTriggerDBCMap;
typedef std::unordered_map<uint32 /*ID*/, AuctionHouseDBC> AuctionHouseDBCMap;
typedef std::unordered_map<uint32 /*ID*/, BankBagSlotPricesDBC> BankBagSlotPricesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, BannedAddOnsDBC> BannedAddOnsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, BarberShopStyleDBC> BarberShopStyleDBCMap;
typedef std::unordered_map<uint32 /*ID*/, BattlemasterListDBC> BattlemasterListDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CharacterFacialHairStylesDBC> CharacterFacialHairStylesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CharSectionsDBC> CharSectionsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CharStartOutfitDBC> CharStartOutfitDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CharTitlesDBC> CharTitlesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ChatChannelsDBC> ChatChannelsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ChrClassesDBC> ChrClassesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ChrRacesDBC> ChrRacesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CinematicCameraDBC> CinematicCameraDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CinematicSequencesDBC> CinematicSequencesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CreatureDisplayInfoDBC> CreatureDisplayInfoDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CreatureDisplayInfoExtraDBC> CreatureDisplayInfoExtraDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CreatureFamilyDBC> CreatureFamilyDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CreatureModelDataDBC> CreatureModelDataDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CreatureSpellDataDBC> CreatureSpellDataDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CreatureTypeDBC> CreatureTypeDBCMap;
typedef std::unordered_map<uint32 /*ID*/, CurrencyCategoryDBC> CurrencyCategoryDBCMap;
typedef std::unordered_map<uint32 /*ItemID*/, CurrencyTypesDBC> CurrencyTypesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, DestructibleModelDataDBC> DestructibleModelDataDBCMap;
typedef std::unordered_map<uint32 /*ID*/, DungeonEncounterDBC> DungeonEncounterDBCMap;
typedef std::unordered_map<uint32 /*ID*/, DurabilityCostsDBC> DurabilityCostsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, DurabilityQualityDBC> DurabilityQualityDBCMap;
typedef std::unordered_map<uint32 /*ID*/, EmotesDBC> EmotesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, EmotesTextDBC> EmotesTextDBCMap;
typedef std::unordered_map<uint32 /*ID*/, EmotesTextSoundDBC> EmotesTextSoundDBCMap;
typedef std::unordered_map<uint32 /*ID*/, FactionDBC> FactionDBCMap;
typedef std::unordered_map<uint32 /*ID*/, FactionTemplateDBC> FactionTemplateDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GameObjectArtKitDBC> GameObjectArtKitDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GameObjectDisplayInfoDBC> GameObjectDisplayInfoDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GemPropertiesDBC> GemPropertiesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GlyphPropertiesDBC> GlyphPropertiesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GlyphSlotDBC> GlyphSlotDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtBarberShopCostBaseDBC> GtBarberShopCostBaseDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtCombatRatingsDBC> GtCombatRatingsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtChanceToMeleeCritBaseDBC> GtChanceToMeleeCritBaseDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtChanceToMeleeCritDBC> GtChanceToMeleeCritDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtChanceToSpellCritBaseDBC> GtChanceToSpellCritBaseDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtChanceToSpellCritDBC> GtChanceToSpellCritDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtNPCManaCostScalerDBC> GtNPCManaCostScalerDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtOCTClassCombatRatingScalarDBC> GtOCTClassCombatRatingScalarDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtOCTRegenHPDBC> GtOCTRegenHPDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtOCTRegenMPDBC> GtOCTRegenMPDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtRegenHPPerSptDBC> GtRegenHPPerSptDBCMap;
typedef std::unordered_map<uint32 /*ID*/, GtRegenMPPerSptDBC> GtRegenMPPerSptDBCMap;
typedef std::unordered_map<uint32 /*ID*/, HolidaysDBC> HolidaysDBCMap;

typedef std::unordered_map<uint32 /*ID*/, ItemDBC> ItemDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemBagFamilyDBC> ItemBagFamilyDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemDisplayInfoDBC> ItemDisplayInfoDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemExtendedCostDBC> ItemExtendedCostDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemLimitCategoryDBC> ItemLimitCategoryDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemRandomPropertiesDBC> ItemRandomPropertiesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemRandomSuffixDBC> ItemRandomSuffixDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ItemSetDBC> ItemSetDBCMap;
typedef std::unordered_map<uint32 /*ID*/, LFGDungeonDBC> LFGDungeonDBCMap;
typedef std::unordered_map<uint32 /*ID*/, LightDBC> LightDBCMap;
typedef std::unordered_map<uint32 /*ID*/, LiquidTypeDBC> LiquidTypeDBCMap;
typedef std::unordered_map<uint32 /*ID*/, LockDBC> LockDBCMap;
typedef std::unordered_map<uint32 /*ID*/, MailTemplateDBC> MailTemplateDBCMap;
typedef std::unordered_map<uint32 /*ID*/, MapDBC> MapDBCMap;
typedef std::unordered_map<uint32 /*ID*/, MapDifficultyDBC> MapDifficultyDBCMap;
typedef std::unordered_map<uint32 /*ID*/, MovieDBC> MovieDBCMap;
typedef std::unordered_map<uint32 /*ID*/, NamesProfanityDBC> NamesProfanityDBCMap;
typedef std::unordered_map<uint32 /*ID*/, NamesReservedDBC> NamesReservedDBCMap;
typedef std::unordered_map<uint32 /*ID*/, OverrideSpellDataDBC> OverrideSpellDataDBCMap;
typedef std::unordered_map<uint32 /*ID*/, PowerDisplayDBC> PowerDisplayDBCMap;
typedef std::unordered_map<uint32 /*ID*/, PvPDifficultyDBC> PvPDifficultyDBCMap;
typedef std::unordered_map<uint32 /*ID*/, QuestSortDBC> QuestSortDBCMap;
typedef std::unordered_map<uint32 /*ID*/, QuestXPDBC> QuestXPDBCMap;
typedef std::unordered_map<uint32 /*ID*/, QuestFactionRewardDBC> QuestFactionRewardDBCMap;
typedef std::unordered_map<uint32 /*ID*/, RandPropPointsDBC> RandPropPointsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ScalingStatDistributionDBC> ScalingStatDistributionDBCMap;
typedef std::unordered_map<uint32 /*ID*/, ScalingStatValuesDBC> ScalingStatValuesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SkillLineDBC> SkillLineDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SkillLineAbilityDBC> SkillLineAbilityDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SkillRaceClassInfoDBC> SkillRaceClassInfoDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SkillTiersDBC> SkillTiersDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SoundEntriesDBC> SoundEntriesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellDBC> SpellDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellCastTimesDBC> SpellCastTimesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellCategoryDBC> SpellCategoryDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellItemEnchantmentDBC> SpellItemEnchantmentDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellDifficultyDBC> SpellDifficultyDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellDurationDBC> SpellDurationDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellFocusObjectDBC> SpellFocusObjectDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellItemEnchantmentConditionDBC> SpellItemEnchantmentConditionDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellRadiusDBC> SpellRadiusDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellRangeDBC> SpellRangeDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellRuneCostDBC> SpellRuneCostDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellShapeshiftFormDBC> SpellShapeshiftFormDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SpellVisualDBC> SpellVisualDBCMap;
typedef std::unordered_map<uint32 /*ID*/, StableSlotPricesDBC> StableSlotPricesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, SummonPropertiesDBC> SummonPropertiesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TalentDBC> TalentDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TalentTabDBC> TalentTabDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TaxiNodesDBC> TaxiNodesDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TaxiPathDBC> TaxiPathDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TaxiPathNodeDBC> TaxiPathNodeDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TeamContributionPointsDBC> TeamContributionPointsDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TotemCategoryDBC> TotemCategoryDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TransportAnimationDBC> TransportAnimationDBCMap;
typedef std::unordered_map<uint32 /*ID*/, TransportRotationDBC> TransportRotationDBCMap;
typedef std::unordered_map<uint32 /*ID*/, VehicleDBC> VehicleDBCMap;
typedef std::unordered_map<uint32 /*ID*/, VehicleSeatDBC> VehicleSeatDBCMap;
typedef std::unordered_map<uint32 /*ID*/, WMOAreaTableDBC> WMOAreaTableDBCMap;
typedef std::unordered_map<uint32 /*AreaID*/, WorldMapAreaDBC> WorldMapAreaDBCMap;
typedef std::unordered_map<uint32 /*ID*/, WorldMapOverlayDBC> WorldMapOverlayDBCMap;
typedef std::unordered_map<uint32 /*ID*/, WorldSafeLocsDBC> WorldSafeLocsDBCMap;

// HELPERS
// regex
typedef std::array<std::vector<Trinity::wregex>, TOTAL_LOCALES> NameValidationRegexContainer;

// PetFamilySpells
typedef std::unordered_set<uint32> PetFamilySpellsSet;
typedef std::unordered_map<uint32, PetFamilySpellsSet> PetFamilySpellsStore;

// PetTalentSpells
typedef std::unordered_map<uint32, TalentSpellPos> TalentSpellPosMap;
typedef std::unordered_set<uint32> PetTalentSpells;

// TaxiPathSetBySource
typedef std::unordered_map<uint32, TaxiPathBySourceAndDestination> TaxiPathSetForSource;
typedef std::unordered_map<uint32, TaxiPathSetForSource> TaxiPathSetBySource;

// TaxiPathNodesByPath
typedef std::vector<TaxiPathNodeDBC const*> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

// SkillRaceClassInfoBounds
typedef std::unordered_multimap<uint32, SkillRaceClassInfoDBC const*> SkillRaceClassInfoMap;
typedef std::pair<SkillRaceClassInfoMap::iterator, SkillRaceClassInfoMap::iterator> SkillRaceClassInfoBounds;

// tuples for the Fastest search by more indexes
// CharacterFacialHairStylesByTripple
typedef std::tuple<uint8, uint8, uint8> CharacterFacialHairStylesKey;
typedef std::map<CharacterFacialHairStylesKey, CharacterFacialHairStylesDBC const*> CharacterFacialHairStylesByTripple;

// CharSectionsByPenta
typedef std::tuple<uint8, CharSectionType, uint8, uint8, uint8> CharSectionsKey;
typedef std::map<CharSectionsKey, CharSectionsDBC const*> CharSectionsByPenta;

// CharStartOutfitByTripple
typedef std::tuple<uint8, uint8, uint8> CharStartOutfitKey;
typedef std::map<CharStartOutfitKey, CharStartOutfitDBC const*> CharStartOutfitByTripple;

// EmotesTextSoundByTripple
typedef std::tuple<uint32, uint8, uint8> EmotesTextSoundKey;
typedef std::map<EmotesTextSoundKey, EmotesTextSoundDBC const*> EmotesTextSoundByTripple;

// LFGDungeonDBCByDouble
typedef std::tuple<int32, Difficulty> LFGDungeonKey;
typedef std::map<LFGDungeonKey, LFGDungeonDBC const*> LFGDungeonDBCByDouble;

// MapDifficultyByDouble
typedef std::tuple<uint32, Difficulty> MapDifficultyKey;
typedef std::map<MapDifficultyKey, MapDifficultyDBC const*> MapDifficultyByDouble;

// WMOAreaInfoByTripple
typedef std::tuple<int32, int32, int32> WMOAreaTableKey;
typedef std::map<WMOAreaTableKey, WMOAreaTableDBC const*> WMOAreaInfoByTripple;

enum ContentLevels : uint8
{
    CONTENT_1_60 = 0,
    CONTENT_61_70,
    CONTENT_71_80
};

class TC_GAME_API DBCStoresMgr
{
private:
    DBCStoresMgr();
    ~DBCStoresMgr();

public:
    static DBCStoresMgr* instance();

    void Initialize();

    AchievementDBCMap const& GetAchievementDBCMap() const { return _achievementMap; }
    uint32 GetAchievementDBCSize() { return _achievementMap.size(); }
    AchievementDBC const* GetAchievementDBC(uint32 id) const
    {
        AchievementDBCMap::const_iterator itr = _achievementMap.find(id);
        if (itr != _achievementMap.end())
            return &itr->second;
        return nullptr;
    }

    AchievementCriteriaDBCMap const& GetAchievementCriteriaDBCMap() const { return _achievementCriteriaMap; }
    uint32 GetAchievementCriteriaDBCSize() { return _achievementCriteriaMap.size(); }
    AchievementCriteriaDBC const* GetAchievementCriteriaDBC(uint32 id) const
    {
        AchievementCriteriaDBCMap::const_iterator itr = _achievementCriteriaMap.find(id);
        if (itr != _achievementCriteriaMap.end())
            return &itr->second;
        return nullptr;
    }

    AreaTableDBCMap const& GetAreaTableDBCMap() const { return _areaTableMap; }
    AreaTableDBC const* GetAreaTableDBC(uint32 id) const
    {
        AreaTableDBCMap::const_iterator itr = _areaTableMap.find(id);
        if (itr != _areaTableMap.end())
            return &itr->second;
        return nullptr;
    }

    AreaGroupDBC const* GetAreaGroupDBC(uint32 id) const
    {
        AreaGroupDBCMap::const_iterator itr = _areaGroupMap.find(id);
        if (itr != _areaGroupMap.end())
            return &itr->second;
        return nullptr;
    }

    AreaPOIDBC const* GetAreaPOIDBC(uint32 id) const
    {
        AreaPOIDBCMap::const_iterator itr = _areaPOIMap.find(id);
        if (itr != _areaPOIMap.end())
            return &itr->second;
        return nullptr;
    }

    AreaTriggerDBC const* GetAreaTriggerDBC(uint32 id) const
    {
        AreaTriggerDBCMap::const_iterator itr = _areaTriggerMap.find(id);
        if (itr != _areaTriggerMap.end())
            return &itr->second;
        return nullptr;
    }

    AuctionHouseDBC const* GetAuctionHouseDBC(uint32 id) const
    {
        AuctionHouseDBCMap::const_iterator itr = _auctionHouseMap.find(id);
        if (itr != _auctionHouseMap.end())
            return &itr->second;
        return nullptr;
    }

    BankBagSlotPricesDBC const* GetBankBagSlotPricesDBC(uint32 id) const
    {
        BankBagSlotPricesDBCMap::const_iterator itr = _bankBagSlotPricesMap.find(id);
        if (itr != _bankBagSlotPricesMap.end())
            return &itr->second;
        return nullptr;
    }

    uint32 GetBannedAddOnsNumRow() { return _bannedAddonsNumRow; }
    BannedAddOnsDBC const* GetBannedAddOnsDBC(uint32 id) const
    {
        BannedAddOnsDBCMap::const_iterator itr = _bannedAddonsMap.find(id);
        if (itr != _bannedAddonsMap.end())
            return &itr->second;
        return nullptr;
    }

    BarberShopStyleDBC const* GetBarberShopStyleDBC(uint32 id) const
    {
        BarberShopStyleDBCMap::const_iterator itr = _barberShopStyleMap.find(id);
        if (itr != _barberShopStyleMap.end())
            return &itr->second;
        return nullptr;
    }

    BattlemasterListDBCMap const& GetBattlemasterListDBCMap() const { return _battlemasterListMap; }
    BattlemasterListDBC const* GetBattlemasterListDBC(uint32 id) const
    {
        BattlemasterListDBCMap::const_iterator itr = _battlemasterListMap.find(id);
        if (itr != _battlemasterListMap.end())
            return &itr->second;
        return nullptr;
    }

    CharacterFacialHairStylesDBC const* GetCharFacialHairDBC(uint8 race, uint8 gender, uint8 facialHairID)
    {
        auto i = _characterFacialHairStylesByTripple.find(CharacterFacialHairStylesKey(race, gender, facialHairID));
        if (i != _characterFacialHairStylesByTripple.end())
            return i->second;
        return nullptr;
    }

    CharSectionsDBC const* GetCharSectionsDBC(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color)
    {
        auto i = _charSectionsByPenta.find(CharSectionsKey(race, genType, gender, type, color));
        if (i != _charSectionsByPenta.end())
            return i->second;
        return nullptr;
    }

    CharStartOutfitDBCMap const& GetCharStartOutfitDBCMap() const { return _charStartOutfitMap; }
    CharStartOutfitDBC const* GetCharStartOutfitDBCWithParam(uint8 race, uint8 classID, uint8 gender)
    {
        auto i = _charStartOutfitByTripple.find(CharStartOutfitKey(race, classID, gender));
        if (i != _charStartOutfitByTripple.end())
            return i->second;
        return nullptr;
    }

    CharTitlesDBCMap const& GetCharTitlesDBCMap() const { return _charTitlesMap; }
    CharTitlesDBC const* GetCharTitlesDBC(uint32 id)
    {
        CharTitlesDBCMap::const_iterator itr = _charTitlesMap.find(id);
        if (itr != _charTitlesMap.end())
            return &itr->second;
        return nullptr;
    }

    ChatChannelsDBCMap const& GetChatChannelsDBCMap() const { return _chatChannelsMap; }
    ChatChannelsDBC const* GetChatChannelsDBC(uint32 id)
    {
        ChatChannelsDBCMap::const_iterator itr = _chatChannelsMap.find(id);
        if (itr != _chatChannelsMap.end())
            return &itr->second;
        return nullptr;
    }

    ChrClassesDBC const* GetChrClassesDBC(uint32 id)
    {
        ChrClassesDBCMap::const_iterator itr = _chrClassesMap.find(id);
        if (itr != _chrClassesMap.end())
                return &itr->second;
        return nullptr;
    }

    char const* GetChrClassName(uint8 class_, uint8 locale)
    {
        ChrClassesDBCMap::const_iterator itr = _chrClassesMap.find(class_);
        if (itr != _chrClassesMap.end())
            return itr->second.Name[locale].c_str();
        return nullptr;
    }

    ChrRacesDBC const* GetChrRacesDBC(uint32 id)
    {
        ChrRacesDBCMap::const_iterator itr = _chrRacesMap.find(id);
        if (itr != _chrRacesMap.end())
            return &itr->second;
        return nullptr;
    }

    char const* GetRaceName(uint8 race, uint8 locale)
    {
        ChrRacesDBCMap::const_iterator itr = _chrRacesMap.find(race);
        if (itr != _chrRacesMap.end())
            return itr->second.Name[locale].c_str();
        return nullptr;
    }

    CinematicCameraDBCMap const& GetCinematicCameraDBCMap() const { return _cinematicCameraMap; }

    CinematicSequencesDBC const* GetCinematicSequencesDBC(uint32 id)
    {
        CinematicSequencesDBCMap::const_iterator itr = _cinematicSequencesMap.find(id);
        if (itr != _cinematicSequencesMap.end())
            return &itr->second;
        return nullptr;
    }

    CreatureDisplayInfoDBC const* GetCreatureDisplayInfoDBC(uint32 id)
    {
        CreatureDisplayInfoDBCMap::const_iterator itr = _creatureDisplayInfoMap.find(id);
        if (itr != _creatureDisplayInfoMap.end())
            return &itr->second;
        return nullptr;
    }

    CreatureDisplayInfoExtraDBC const* GetCreatureDisplayInfoExtraDBC(uint32 id)
    {
        CreatureDisplayInfoExtraDBCMap::const_iterator itr = _creatureDisplayInfoExtraMap.find(id);
        if (itr != _creatureDisplayInfoExtraMap.end())
            return &itr->second;
        return nullptr;
    }

    CreatureFamilyDBCMap const& GetCreatureFamilyDBCMap() const { return _creatureFamilyMap; }
    CreatureFamilyDBC const* GetCreatureFamilyDBC(uint32 id)
    {
        CreatureFamilyDBCMap::const_iterator itr = _creatureFamilyMap.find(id);
        if (itr != _creatureFamilyMap.end())
            return &itr->second;
        return nullptr;
    }

    char const* GetPetName(uint32 petfamily, uint32 dbclang)
    {
        if (!petfamily)
            return nullptr;
        CreatureFamilyDBC const* pet_family = GetCreatureFamilyDBC(petfamily);
        if (!pet_family)
            return nullptr;
        return pet_family->Name[dbclang].c_str();
    }

    CreatureModelDataDBC const* GetCreatureModelDataDBC(uint32 id)
    {
        CreatureModelDataDBCMap::const_iterator itr = _creatureModelDataMap.find(id);
        if (itr != _creatureModelDataMap.end())
            return &itr->second;
        return nullptr;
    }

    CreatureSpellDataDBC const* GetCreatureSpellDataDBC(uint32 id)
    {
        CreatureSpellDataDBCMap::const_iterator itr = _creatureSpellDataMap.find(id);
        if (itr != _creatureSpellDataMap.end())
            return &itr->second;
        return nullptr;
    }

    CreatureTypeDBC const* GetCreatureTypeDBC(uint32 id)
    {
        CreatureTypeDBCMap::const_iterator itr = _creatureTypeMap.find(id);
        if (itr != _creatureTypeMap.end())
            return &itr->second;
        return nullptr;
    }

    CurrencyCategoryDBC const* GetCurrencyCategoryDBC(uint32 id)
    {
        CurrencyCategoryDBCMap::const_iterator itr = _currencyCategoryMap.find(id);
        if (itr != _currencyCategoryMap.end())
            return &itr->second;
        return nullptr;
    }

    CurrencyTypesDBC const* GetCurrencyTypesDBCByItemID(uint32 ItemID)
    {
        CurrencyTypesDBCMap::const_iterator itr = _currencyTypesMap.find(ItemID);
        if (itr != _currencyTypesMap.end())
            return &itr->second;
        return nullptr;
    }

    DestructibleModelDataDBC const* GetDestructibleModelDataDBC(uint32 ID)
    {
        DestructibleModelDataDBCMap::const_iterator itr = _destructibleModelDataMap.find(ID);
        if (itr != _destructibleModelDataMap.end())
            return &itr->second;
        return nullptr;
    }

    DungeonEncounterDBC const* GetDungeonEncounterDBC(uint32 ID)
    {
        DungeonEncounterDBCMap::const_iterator itr = _dungeonEncounterMap.find(ID);
        if (itr != _dungeonEncounterMap.end())
            return &itr->second;
        return nullptr;
    }

    DurabilityCostsDBC const* GetDurabilityCostsDBC(uint32 ID)
    {
        DurabilityCostsDBCMap::const_iterator itr = _durabilityCoastsMap.find(ID);
        if (itr != _durabilityCoastsMap.end())
            return &itr->second;
        return nullptr;
    }

    DurabilityQualityDBC const* GetDurabilityQualityDBC(uint32 ID)
    {
        DurabilityQualityDBCMap::const_iterator itr = _durabilityQualityMap.find(ID);
        if (itr != _durabilityQualityMap.end())
            return &itr->second;
        return nullptr;
    }

    EmotesDBC const* GetEmotesDBC(uint32 ID)
    {
        EmotesDBCMap::const_iterator itr = _emotesMap.find(ID);
        if (itr != _emotesMap.end())
            return &itr->second;
        return nullptr;
    }

    EmotesTextDBC const* GetEmotesTextDBC(uint32 ID)
    {
        EmotesTextDBCMap::const_iterator itr = _emotesTextMap.find(ID);
        if (itr != _emotesTextMap.end())
            return &itr->second;
        return nullptr;
    }

    EmotesTextSoundDBC const* GetEmotesTextSoundDBCWithParam(uint32 emote, uint8 race, uint8 gender)
    {
        auto i = _emotesTextSoundByTripple.find(EmotesTextSoundKey(emote, race, gender));
        if (i != _emotesTextSoundByTripple.end())
            return i->second;
        return nullptr;
    }

    FactionDBCMap const& GetFactionDBCMap() const { return _factionMap; }
    FactionDBC const* GetFactionDBC(uint32 ID)
    {
        FactionDBCMap::const_iterator itr = _factionMap.find(ID);
        if (itr != _factionMap.end())
            return &itr->second;
        return nullptr;
    }

    FactionTemplateDBC const* GetFactionTemplateDBC(uint32 ID)
    {
        FactionTemplateDBCMap::const_iterator itr = _factionTemplateMap.find(ID);
        if (itr != _factionTemplateMap.end())
            return &itr->second;
        return nullptr;
    }

    GameObjectArtKitDBC const* GetGameObjectArtKitDBC(uint32 ID)
    {
        GameObjectArtKitDBCMap::const_iterator itr = _gameobjectArtKitMap.find(ID);
        if (itr != _gameobjectArtKitMap.end())
            return &itr->second;
        return nullptr;
    }

    GameObjectDisplayInfoDBC const* GetGameObjectDisplayInfoDBC(uint32 ID)
    {
        GameObjectDisplayInfoDBCMap::const_iterator itr = _gameobjectDisplayInfoMap.find(ID);
        if (itr != _gameobjectDisplayInfoMap.end())
            return &itr->second;
        return nullptr;
    }

    GemPropertiesDBC const* GetGemPropertiesDBC(uint32 ID)
    {
        GemPropertiesDBCMap::const_iterator itr = _gemPropertiesMap.find(ID);
        if (itr != _gemPropertiesMap.end())
            return &itr->second;
        return nullptr;
    }

    GlyphPropertiesDBC const* GetGlyphPropertiesDBC(uint32 ID)
    {
        GlyphPropertiesDBCMap::const_iterator itr = _glyphPropertiesMap.find(ID);
        if (itr != _glyphPropertiesMap.end())
            return &itr->second;
        return nullptr;
    }

    GlyphSlotDBCMap const& GetGlyphSlotDBCMap() const { return _glyphSlotMap; }
    GlyphSlotDBC const* GetGlyphSlotDBC(uint32 ID)
    {
        GlyphSlotDBCMap::const_iterator itr = _glyphSlotMap.find(ID);
        if (itr != _glyphSlotMap.end())
            return &itr->second;
        return nullptr;
    }

    GtBarberShopCostBaseDBC const* GetGtBarberShopCostBaseDBC(uint32 ID)
    {
        GtBarberShopCostBaseDBCMap::const_iterator itr = _gtBarberShopCostBaseMap.find(ID);
        if (itr != _gtBarberShopCostBaseMap.end())
            return &itr->second;
        return nullptr;
    }

    GtCombatRatingsDBC const* GetGtCombatRatingsDBC(uint32 ID)
    {
        GtCombatRatingsDBCMap::const_iterator itr = _gtCombatRatingsMap.find(ID);
        if (itr != _gtCombatRatingsMap.end())
            return &itr->second;
        return nullptr;
    }

    GtChanceToMeleeCritBaseDBC const* GetGtChanceToMeleeCritBaseDBC(uint32 ID)
    {
        GtChanceToMeleeCritBaseDBCMap::const_iterator itr = _gtChanceToMeleeCritBaseMap.find(ID);
        if (itr != _gtChanceToMeleeCritBaseMap.end())
            return &itr->second;
        return nullptr;
    }

    GtChanceToMeleeCritDBC const* GetGtChanceToMeleeCritDBC(uint32 ID)
    {
        GtChanceToMeleeCritDBCMap::const_iterator itr = _gtChanceToMeleeCritMap.find(ID);
        if (itr != _gtChanceToMeleeCritMap.end())
            return &itr->second;
        return nullptr;
    }

    GtChanceToSpellCritBaseDBC const* GetGtChanceToSpellCritBaseDBC(uint32 ID)
    {
        GtChanceToSpellCritBaseDBCMap::const_iterator itr = _gtChanceToSpellCritBaseMap.find(ID);
        if (itr != _gtChanceToSpellCritBaseMap.end())
            return &itr->second;
        return nullptr;
    }

    GtChanceToSpellCritDBC const* GetGtChanceToSpellCritDBC(uint32 ID)
    {
        GtChanceToSpellCritDBCMap::const_iterator itr = _gtChanceToSpellCritMap.find(ID);
        if (itr != _gtChanceToSpellCritMap.end())
            return &itr->second;
        return nullptr;
    }

    GtNPCManaCostScalerDBC const* GetGtNPCManaCostScalerDBC(uint32 ID)
    {
        GtNPCManaCostScalerDBCMap::const_iterator itr = _gtNPCManaCostScalerMap.find(ID);
        if (itr != _gtNPCManaCostScalerMap.end())
            return &itr->second;
        return nullptr;
    }

    GtOCTClassCombatRatingScalarDBC const* GetGtOCTClassCombatRatingScalarDBC(uint32 ID)
    {
        GtOCTClassCombatRatingScalarDBCMap::const_iterator itr = _gtOCTClassCombatRatingScalarMap.find(ID);
        if (itr != _gtOCTClassCombatRatingScalarMap.end())
            return &itr->second;
        return nullptr;
    }

    GtOCTRegenHPDBC const* GetGtOCTRegenHPDBC(uint32 ID)
    {
        GtOCTRegenHPDBCMap::const_iterator itr = _gtOCTRegenHPMap.find(ID);
        if (itr != _gtOCTRegenHPMap.end())
            return &itr->second;
        return nullptr;
    }

    GtOCTRegenMPDBC const* GetGtOCTRegenMPDBC(uint32 ID)
    {
        GtOCTRegenMPDBCMap::const_iterator itr = _gtOCTRegenMPMap.find(ID);
        if (itr != _gtOCTRegenMPMap.end())
            return &itr->second;
        return nullptr;
    }

    GtRegenHPPerSptDBC const* GetGtRegenHPPerSptDBC(uint32 ID)
    {
        GtRegenHPPerSptDBCMap::const_iterator itr = _gtRegenHPPerSptMap.find(ID);
        if (itr != _gtRegenHPPerSptMap.end())
            return &itr->second;
        return nullptr;
    }

    GtRegenMPPerSptDBC const* GetGtRegenMPPerSptDBC(uint32 ID)
    {
        GtRegenMPPerSptDBCMap::const_iterator itr = _gtRegenMPPerSptMap.find(ID);
        if (itr != _gtRegenMPPerSptMap.end())
            return &itr->second;
        return nullptr;
    }

    HolidaysDBC const* GetHolidaysDBC(uint32 ID)
    {
        HolidaysDBCMap::const_iterator itr = _holidaysMap.find(ID);
        if (itr != _holidaysMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemDBCMap const& GetItemDBCMap() const { return _itemMap; }
    ItemDBC const* GetItemDBC(uint32 ID)
    {
        ItemDBCMap::const_iterator itr = _itemMap.find(ID);
        if (itr != _itemMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemBagFamilyDBC const* GetItemBagFamilyDBC(uint32 ID)
    {
        ItemBagFamilyDBCMap::const_iterator itr = _itemBagFamilyMap.find(ID);
        if (itr != _itemBagFamilyMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemDisplayInfoDBC const* GetItemDisplayInfoDBC(uint32 ID)
    {
        ItemDisplayInfoDBCMap::const_iterator itr = _itemDisplayInfoMap.find(ID);
        if (itr != _itemDisplayInfoMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemExtendedCostDBC const* GetItemExtendedCostDBC(uint32 ID)
    {
        ItemExtendedCostDBCMap::const_iterator itr = _itemExtendedCostMap.find(ID);
        if (itr != _itemExtendedCostMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemLimitCategoryDBC const* GetItemLimitCategoryDBC(uint32 ID)
    {
        ItemLimitCategoryDBCMap::const_iterator itr = _itemLimitCategoryMap.find(ID);
        if (itr != _itemLimitCategoryMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemRandomPropertiesDBC const* GetItemRandomPropertiesDBC(uint32 ID)
    {
        ItemRandomPropertiesDBCMap::const_iterator itr = _itemRandomPropertiesMap.find(ID);
        if (itr != _itemRandomPropertiesMap.end())
            return &itr->second;
        return nullptr;
    }

    uint32 GetNumRowItemRandomSuffixMap() const { return _itemRandomSuffixNumRow; }
    ItemRandomSuffixDBC const* GetItemRandomSuffixDBC(uint32 ID)
    {
        ItemRandomSuffixDBCMap::const_iterator itr = _itemRandomSuffixMap.find(ID);
        if (itr != _itemRandomSuffixMap.end())
            return &itr->second;
        return nullptr;
    }

    ItemSetDBCMap const& GetItemSetMap() const { return _itemSetMap; }
    ItemSetDBC const* GetItemSetDBC(uint32 ID)
    {
        ItemSetDBCMap::const_iterator itr = _itemSetMap.find(ID);
        if (itr != _itemSetMap.end())
            return &itr->second;
        return nullptr;
    }

    LFGDungeonDBCMap const& GetLFGDungeonDBCMap() const { return _lfgDungeonMap; }
    LFGDungeonDBC const* GetLFGDungeonDBC(uint32 ID)
    {
        LFGDungeonDBCMap::const_iterator itr = _lfgDungeonMap.find(ID);
        if (itr != _lfgDungeonMap.end())
            return &itr->second;
        return nullptr;
    }

    LightDBC const* GetLightDBC(uint32 ID)
    {
        LightDBCMap::const_iterator itr = _lightMap.find(ID);
        if (itr != _lightMap.end())
            return &itr->second;
        return nullptr;
    }

    uint32 GetDefaultMapLight(uint32 mapId) // UNUSED
    {
        for (LightDBCMap::const_iterator itr = _lightMap.begin(); itr != _lightMap.end(); ++itr)
        {
            if (itr->second.ContinentID == mapId &&
                itr->second.GameCoords.X == 0.0f &&
                itr->second.GameCoords.Y == 0.0f &&
                itr->second.GameCoords.Z == 0.0f)
                return itr->second.ID;
        }
        return 0;
    }

    LFGDungeonDBC const* GetLFGDungeon(uint32 mapId, Difficulty difficulty)
    {
        auto i = _lfgDungeonByDouble.find(LFGDungeonKey(mapId, difficulty));
        if (i != _lfgDungeonByDouble.end())
            return i->second;
        return nullptr;
    }

    LiquidTypeDBCMap const& GetLiquidTypeDBCMap() const { return _liquidTypeMap; }
    LiquidTypeDBC const* GetLiquidTypeDBC(uint32 ID)
    {
        LiquidTypeDBCMap::const_iterator itr = _liquidTypeMap.find(ID);
        if (itr != _liquidTypeMap.end())
            return &itr->second;
        return nullptr;
    }

    LockDBC const* GetLockDBC(uint32 ID)
    {
        LockDBCMap::const_iterator itr = _lockMap.find(ID);
        if (itr != _lockMap.end())
            return &itr->second;
        return nullptr;
    }

    MailTemplateDBCMap const& GetMailTemplateDBCMap() const { return _mailTemplateMap; }
    MailTemplateDBC const* GetMailTemplateDBC(uint32 ID)
    {
        MailTemplateDBCMap::const_iterator itr = _mailTemplateMap.find(ID);
        if (itr != _mailTemplateMap.end())
            return &itr->second;
        return nullptr;
    }

    MapDBCMap const& GetMapDBCMap() const { return _mapMap; }
    MapDBC const* GetMapDBC(uint32 ID)
    {
        MapDBCMap::const_iterator itr = _mapMap.find(ID);
        if (itr != _mapMap.end())
            return &itr->second;
        return nullptr;
    }

    MapDifficultyDBCMap const& GetMapDifficultyDBCMap() const { return _mapDifficultyMap; }
    MapDifficultyDBC const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty)
    {
        auto i = _mapDifficultyByDouble.find(MapDifficultyKey(mapId, difficulty));
        if (i != _mapDifficultyByDouble.end())
            return i->second;
        return nullptr;
    }

    MapDifficultyDBC const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty& difficulty)
    {
        uint32 tmpDiff = difficulty;
        MapDifficultyDBC const* mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff));
        if (!mapDiff)
        {
            if (tmpDiff > RAID_DIFFICULTY_25MAN_NORMAL) // heroic, downscale to normal
                tmpDiff -= 2;
            else
                tmpDiff -= 1;   // any non-normal mode for raids like tbc (only one mode)

            // pull new data
            mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // we are 10 normal or 25 normal
            if (!mapDiff)
            {
                tmpDiff -= 1;
                mapDiff = GetMapDifficultyData(mapId, Difficulty(tmpDiff)); // 10 normal
            }
        }

        difficulty = Difficulty(tmpDiff);
        return mapDiff;
    }

    MovieDBC const* GetMovieDBC(uint32 ID)
    {
        MovieDBCMap::const_iterator itr = _movieMap.find(ID);
        if (itr != _movieMap.end())
            return &itr->second;
        return nullptr;
    }

    OverrideSpellDataDBC const* GetOverrideSpellDataDBC(uint32 ID)
    {
        OverrideSpellDataDBCMap::const_iterator itr = _overrideSpellDataMap.find(ID);
        if (itr != _overrideSpellDataMap.end())
            return &itr->second;
        return nullptr;
    }

    PowerDisplayDBC const* GetPowerDisplayDBC(uint32 ID)
    {
        PowerDisplayDBCMap::const_iterator itr = _powerDisplayMap.find(ID);
        if (itr != _powerDisplayMap.end())
            return &itr->second;
        return nullptr;
    }

    PvPDifficultyDBC const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level)
    {
        PvPDifficultyDBC const* maxEntry = nullptr;              // used for level > max listed level case
        for (PvPDifficultyDBCMap::const_iterator itr = _pvpDifficultyMap.begin(); itr != _pvpDifficultyMap.end(); ++itr)
        {
            // skip unrelated and too-high brackets
            if (itr->second.MapID != mapid || itr->second.MinLevel > level)
                continue;

            // exactly fit
            if (itr->second.MaxLevel >= level)
                return &itr->second;

            // remember for possible out-of-range case (search higher from existed)
            if (!maxEntry || maxEntry->MaxLevel < itr->second.MaxLevel)
                maxEntry = &itr->second;
        }
        return maxEntry;
    }

    PvPDifficultyDBC const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id)
    {
        for (PvPDifficultyDBCMap::const_iterator itr = _pvpDifficultyMap.begin(); itr != _pvpDifficultyMap.end(); ++itr)
        {
            if (itr->second.MapID == mapid && itr->second.GetBracketId() == id)
                return &itr->second;
        }
        return nullptr;
    }

    QuestSortDBC const* GetQuestSortDBC(uint32 ID)
    {
        QuestSortDBCMap::const_iterator itr = _questSortMap.find(ID);
        if (itr != _questSortMap.end())
            return &itr->second;
        return nullptr;
    }

    QuestXPDBC const* GetQuestXPDBC(uint32 ID)
    {
        QuestXPDBCMap::const_iterator itr = _questXPMap.find(ID);
        if (itr != _questXPMap.end())
            return &itr->second;
        return nullptr;
    }

    QuestFactionRewardDBC const* GetQuestFactionRewardDBC(uint32 ID)
    {
        QuestFactionRewardDBCMap::const_iterator itr = _questFactionRewardMap.find(ID);
        if (itr != _questFactionRewardMap.end())
            return &itr->second;
        return nullptr;
    }

    RandPropPointsDBC const* GetRandPropPointsDBC(uint32 ID)
    {
        RandPropPointsDBCMap::const_iterator itr = _randPropPointsMap.find(ID);
        if (itr != _randPropPointsMap.end())
            return &itr->second;
        return nullptr;
    }

    ScalingStatDistributionDBC const* GetScalingStatDistributionDBC(uint32 ID)
    {
        ScalingStatDistributionDBCMap::const_iterator itr = _scalingStatDistributionMap.find(ID);
        if (itr != _scalingStatDistributionMap.end())
            return &itr->second;
        return nullptr;
    }

    ScalingStatValuesDBC const* GetScalingStatValuesDBC(uint32 ID)
    {
        ScalingStatValuesDBCMap::const_iterator itr = _scalingStatValuesMap.find(ID);
        if (itr != _scalingStatValuesMap.end())
            return &itr->second;
        return nullptr;
    }

    SkillLineDBCMap const& GetSkillLineDBCMap() const { return _skillLineMap; }
    SkillLineDBC const* GetSkillLineDBC(uint32 ID)
    {
        SkillLineDBCMap::const_iterator itr = _skillLineMap.find(ID);
        if (itr != _skillLineMap.end())
            return &itr->second;
        return nullptr;
    }

    SkillLineAbilityDBCMap const& GetSkillLineAbilityDBCMap() const { return _skillLineAbilityMap; }
    SkillLineAbilityDBC const* GetSkillLineAbilityDBC(uint32 ID)
    {
        SkillLineAbilityDBCMap::const_iterator itr = _skillLineAbilityMap.find(ID);
        if (itr != _skillLineAbilityMap.end())
            return &itr->second;
        return nullptr;
    }

    SkillRaceClassInfoDBC const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_)
    {
        SkillRaceClassInfoBounds bounds = _skillRaceClassInfoBySkill.equal_range(skill);
        for (SkillRaceClassInfoMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
        {
            if (itr->second->RaceMask && !(itr->second->RaceMask & (1 << (race - 1))))
                continue;
            if (itr->second->ClassMask && !(itr->second->ClassMask & (1 << (class_ - 1))))
                continue;

            return itr->second;
        }
        return nullptr;
    }

    SkillTiersDBC const* GetSkillTiersDBC(uint32 ID)
    {
        SkillTiersDBCMap::const_iterator itr = _skillTiersMap.find(ID);
        if (itr != _skillTiersMap.end())
            return &itr->second;
        return nullptr;
    }

    SoundEntriesDBC const* GetSoundEntriesDBC(uint32 ID)
    {
        SoundEntriesDBCMap::const_iterator itr = _soundEntriesMap.find(ID);
        if (itr != _soundEntriesMap.end())
            return &itr->second;
        return nullptr;
    }

    uint32 GetNumRowSpellDBCMap() const { return _spellNumRow; }
    SpellDBCMap const& GetSpellDBCMap() const { return _spellMap; }
    SpellDBC const* GetSpellDBC(uint32 ID)
    {
        SpellDBCMap::const_iterator itr = _spellMap.find(ID);
        if (itr != _spellMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellCastTimesDBC const* GetSpellCastTimesDBC(uint32 ID)
    {
        SpellCastTimesDBCMap::const_iterator itr = _spellCastTimesMap.find(ID);
        if (itr != _spellCastTimesMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellCategoryDBC const* GetSpellCategoryDBC(uint32 ID)
    {
        SpellCategoryDBCMap::const_iterator itr = _spellCategoryMap.find(ID);
        if (itr != _spellCategoryMap.end())
            return &itr->second;
        return nullptr;
    }

    uint32 GetNumRowSpellItemEnchantmentDBCMap() const { return _spellItemEnchantmentNumRow; }
    SpellItemEnchantmentDBC const* GetSpellItemEnchantmentDBC(uint32 ID)
    {
        SpellItemEnchantmentDBCMap::const_iterator itr = _spellItemEnchantmentMap.find(ID);
        if (itr != _spellItemEnchantmentMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellDifficultyDBCMap const& GetSpellDifficultyDBCMap() const { return _spellDiffucultyMap; }
    SpellDifficultyDBC const* GetSpellDifficultyDBC(uint32 ID)
    {
        SpellDifficultyDBCMap::const_iterator itr = _spellDiffucultyMap.find(ID);
        if (itr != _spellDiffucultyMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellDurationDBC const* GetSpellDurationDBC(uint32 ID)
    {
        SpellDurationDBCMap::const_iterator itr = _spellDurationMap.find(ID);
        if (itr != _spellDurationMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellFocusObjectDBC const* GetSpellFocusObjectDBC(uint32 ID)
    {
        SpellFocusObjectDBCMap::const_iterator itr = _spellFocusObjectMap.find(ID);
        if (itr != _spellFocusObjectMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellItemEnchantmentConditionDBC const* GetSpellItemEnchantmentConditionDBC(uint32 ID)
    {
        SpellItemEnchantmentConditionDBCMap::const_iterator itr = _spellItemEnchantmentConditionMap.find(ID);
        if (itr != _spellItemEnchantmentConditionMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellRadiusDBC const* GetSpellRadiusDBC(uint32 ID)
    {
        SpellRadiusDBCMap::const_iterator itr = _spellRadiusMap.find(ID);
        if (itr != _spellRadiusMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellRangeDBC const* GetSpellRangeDBC(uint32 ID)
    {
        SpellRangeDBCMap::const_iterator itr = _spellRangeMap.find(ID);
        if (itr != _spellRangeMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellRuneCostDBC const* GetSpellRuneCostDBC(uint32 ID)
    {
        SpellRuneCostDBCMap::const_iterator itr = _spellRuneCostMap.find(ID);
        if (itr != _spellRuneCostMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellShapeshiftFormDBC const* GetSpellShapeshiftFormDBC(uint32 ID)
    {
        SpellShapeshiftFormDBCMap::const_iterator itr = _spellShapeShiftFormMap.find(ID);
        if (itr != _spellShapeShiftFormMap.end())
            return &itr->second;
        return nullptr;
    }

    SpellVisualDBC const* GetSpellVisualDBC(uint32 ID)
    {
        SpellVisualDBCMap::const_iterator itr = _spellVisualMap.find(ID);
        if (itr != _spellVisualMap.end())
            return &itr->second;
        return nullptr;
    }

    StableSlotPricesDBC const* GetStableSlotPricesDBC(uint32 ID)
    {
        StableSlotPricesDBCMap::const_iterator itr = _stableSlotPricesMap.find(ID);
        if (itr != _stableSlotPricesMap.end())
            return &itr->second;
        return nullptr;
    }

    SummonPropertiesDBC const* GetSummonPropertiesDBC(uint32 ID)
    {
        SummonPropertiesDBCMap::const_iterator itr = _summonPropertiesMap.find(ID);
        if (itr != _summonPropertiesMap.end())
            return &itr->second;
        return nullptr;
    }

    TalentDBCMap const& GetTalentDBCMap() const { return _talentMap; }
    TalentDBC const* GetTalentDBC(uint32 ID)
    {
        TalentDBCMap::const_iterator itr = _talentMap.find(ID);
        if (itr != _talentMap.end())
            return &itr->second;
        return nullptr;
    }

    TalentTabDBCMap const& GetTalentTabDBCMap() const { return _talentTabMap; }
    TalentTabDBC const* GetTalentTabDBC(uint32 ID)
    {
        TalentTabDBCMap::const_iterator itr = _talentTabMap.find(ID);
        if (itr != _talentTabMap.end())
            return &itr->second;
        return nullptr;
    }

    TaxiNodesDBCMap const& GetTaxiNodesDBCMap() const { return _taxiNodesMap; }
    TaxiNodesDBC const* GetTaxiNodesDBC(uint32 ID)
    {
        TaxiNodesDBCMap::const_iterator itr = _taxiNodesMap.find(ID);
        if (itr != _taxiNodesMap.end())
            return &itr->second;
        return nullptr;
    }

    TaxiPathDBC const* GetTaxiPathDBC(uint32 ID)
    {
        TaxiPathDBCMap::const_iterator itr = _taxiPathMap.find(ID);
        if (itr != _taxiPathMap.end())
            return &itr->second;
        return nullptr;
    }

    TaxiPathNodeDBC const* GetTaxiPathNodeDBC(uint32 ID)
    {
        TaxiPathNodeDBCMap::const_iterator itr = _taxiPathNodeMap.find(ID);
        if (itr != _taxiPathNodeMap.end())
            return &itr->second;
        return nullptr;
    }

    TeamContributionPointsDBC const* GetTeamContributionPointsDBC(uint32 ID)
    {
        TeamContributionPointsDBCMap::const_iterator itr = _teamContributionPointsMap.find(ID);
        if (itr != _teamContributionPointsMap.end())
            return &itr->second;
        return nullptr;
    }

    TotemCategoryDBC const* GetTotemCategoryDBC(uint32 ID)
    {
        TotemCategoryDBCMap::const_iterator itr = _totemCategoryMap.find(ID);
        if (itr != _totemCategoryMap.end())
            return &itr->second;
        return nullptr;
    }

    bool IsTotemCategoryCompatiableWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId)
    {
        if (requiredTotemCategoryId == 0)
            return true;
        if (itemTotemCategoryId == 0)
            return false;

        TotemCategoryDBC const* itemEntry = GetTotemCategoryDBC(itemTotemCategoryId);
        if (!itemEntry)
            return false;
        TotemCategoryDBC const* reqEntry = GetTotemCategoryDBC(requiredTotemCategoryId);
        if (!reqEntry)
            return false;

        if (itemEntry->TotemCategoryType != reqEntry->TotemCategoryType)
            return false;

        return (itemEntry->TotemCategoryMask & reqEntry->TotemCategoryMask) == reqEntry->TotemCategoryMask;
    }

    TransportAnimationDBCMap const& GetTransportAnimationDBCMap() const { return _transportAnimationMap; }
    TransportAnimationDBC const* GetTransportAnimationDBC(uint32 ID)
    {
        TransportAnimationDBCMap::const_iterator itr = _transportAnimationMap.find(ID);
        if (itr != _transportAnimationMap.end())
            return &itr->second;
        return nullptr;
    }

    TransportRotationDBCMap const& GetTransportRotationDBCMap() const { return _transportRotationMap; }
    TransportRotationDBC const* GetTransportRotationDBC(uint32 ID)
    {
        TransportRotationDBCMap::const_iterator itr = _transportRotationMap.find(ID);
        if (itr != _transportRotationMap.end())
            return &itr->second;
        return nullptr;
    }

    VehicleDBC const* GetVehicleDBC(uint32 ID)
    {
        VehicleDBCMap::const_iterator itr = _vehicleMap.find(ID);
        if (itr != _vehicleMap.end())
            return &itr->second;
        return nullptr;
    }

    VehicleSeatDBC const* GetVehicleSeatDBC(uint32 ID)
    {
        VehicleSeatDBCMap::const_iterator itr = _vehicleSeatMap.find(ID);
        if (itr != _vehicleSeatMap.end())
            return &itr->second;
        return nullptr;
    }

    WMOAreaTableDBC const* GetWMOAreaTableDBC(uint32 ID)
    {
        WMOAreaTableDBCMap::const_iterator itr = _wmoAreaTableMap.find(ID);
        if (itr != _wmoAreaTableMap.end())
            return &itr->second;
        return nullptr;
    }

    WMOAreaTableDBC const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid)
    {
        auto i = _wmoAreaInfoByTripple.find(WMOAreaTableKey(rootid, adtid, groupid));
        if (i != _wmoAreaInfoByTripple.end())
            return i->second;
        return nullptr;
    }

    WorldMapAreaDBC const* GetWorldMapAreaDBCByAreaID(uint32 AreaID)
    {
        WorldMapAreaDBCMap::const_iterator itr = _worldMapAreaMap.find(AreaID);
        if (itr != _worldMapAreaMap.end())
            return &itr->second;
        return nullptr;
    }

    uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId)
    {
        if (mapid != 530 && mapid != 571)                        // speed for most cases
            return mapid;

        if (WorldMapAreaDBC const* wma = GetWorldMapAreaDBCByAreaID(zoneId))
            return wma->DisplayMapID >= 0 ? wma->DisplayMapID : wma->MapID;

        return mapid;
    }

    ContentLevels GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId)
    {
        mapid = GetVirtualMapForMapAndZone(mapid, zoneId);
        if (mapid < 2)
            return CONTENT_1_60;

        MapDBC const* mapEntry = GetMapDBC(mapid);
        if (!mapEntry)
            return CONTENT_1_60;

        switch (mapEntry->Expansion())
        {
            default: return CONTENT_1_60;
            case 1:  return CONTENT_61_70;
            case 2:  return CONTENT_71_80;
        }
    }

    void Zone2MapCoordinates(float& x, float& y, uint32 zone)
    {
        WorldMapAreaDBC const* maEntry = GetWorldMapAreaDBCByAreaID(zone);

        // if not listed then map coordinates (instance)
        if (!maEntry)
            return;

        std::swap(x, y);                                         // at client map coords swapped
        x = x * ((maEntry->LocBottom - maEntry->LocTop) / 100) + maEntry->LocTop;
        y = y * ((maEntry->LocRight - maEntry->LocLeft) / 100) + maEntry->LocLeft;      // client y coord from top to down
    }

    void Map2ZoneCoordinates(float& x, float& y, uint32 zone)
    {
        WorldMapAreaDBC const* maEntry = GetWorldMapAreaDBCByAreaID(zone);

        // if not listed then map coordinates (instance)
        if (!maEntry)
            return;

        x = (x - maEntry->LocTop) / ((maEntry->LocBottom - maEntry->LocTop) / 100);
        y = (y - maEntry->LocLeft) / ((maEntry->LocRight - maEntry->LocLeft) / 100);    // client y coord from top to down
        std::swap(x, y);                                         // client have map coords swapped
    }

    WorldMapOverlayDBC const* GetWorldMapOverlayDBC(uint32 ID)
    {
        WorldMapOverlayDBCMap::const_iterator itr = _worldMapOverlayMap.find(ID);
        if (itr != _worldMapOverlayMap.end())
            return &itr->second;
        return nullptr;
    }

    WorldSafeLocsDBCMap const& GetWorldSafeLocsDBCMap() const { return _worldSafeLocsMap; }
    WorldSafeLocsDBC const* GetWorldSafeLocsDBC(uint32 ID)
    {
        WorldSafeLocsDBCMap::const_iterator itr = _worldSafeLocsMap.find(ID);
        if (itr != _worldSafeLocsMap.end())
            return &itr->second;
        return nullptr;
    }

    // Handlers for working with DBC data
    ResponseCodes ValidateName(std::wstring const& name, LocaleConstant locale)
    {
        if (locale >= TOTAL_LOCALES)
            return RESPONSE_FAILURE;

        for (Trinity::wregex const& regex : NamesProfaneValidators[locale])
            if (Trinity::regex_search(name, regex))
                return CHAR_NAME_PROFANE;

        // regexes at TOTAL_LOCALES are loaded from NamesReserved which is not locale specific
        for (Trinity::wregex const& regex : NamesReservedValidators[locale])
            if (Trinity::regex_search(name, regex))
                return CHAR_NAME_RESERVED;

        return CHAR_NAME_SUCCESS;
    }

    PetFamilySpellsStore const& GetPetFamilySpellsStore() { return _petFamilySpellsStore; }

    TalentSpellPos const* GetTalentSpellPos(uint32 spellId)
    {
        TalentSpellPosMap::const_iterator itr = _talentSpellPos.find(spellId);
        if (itr == _talentSpellPos.end())
            return nullptr;
        return &itr->second;
    }

    uint32 GetTalentSpellCost(uint32 spellId)
    {
        if (TalentSpellPos const* pos = GetTalentSpellPos(spellId))
            return pos->rank + 1;
        return 0;
    }

    PetTalentSpells const& GetPetTalentSpells() { return _petTalentSpells; }

    uint32 const* GetTalentTabPages(uint8 cls)
    {
        return _TalentTabPages[cls];
    }

    TaxiMask const GetTaxiNodesMask() { return _TaxiNodesMask; }
    TaxiMask const GetOldContinentsNodesMask() { return _OldContinentsNodesMask; }
    TaxiMask const GetHordeTaxiNodesMask() { return _HordeTaxiNodesMask; }
    TaxiMask const GetAllianceTaxiNodesMask() { return _AllianceTaxiNodesMask; }
    TaxiMask const GetDeathKnightTaxiNodesMask() { return _DeathKnightTaxiNodesMask; }

    TaxiPathSetBySource const& GetTaxiPathSetBySource() { return _taxiPathSetBySource; }
    TaxiPathNodesByPath const& GetTaxiPathNodesByPath() { return _taxiPathNodesByPath; }

    void Handle_SpellDifficultyInSpellMgr();

protected:
    void _Load_Achievement();
    void _Load_AchievementCriteria();
    void _Load_AreaTable();
    void _Load_AreaGroup();
    void _Load_AreaPOI();
    void _Load_AreaTrigger();
    void _Load_AuctionHouse();
    void _Load_BankBagSlotPrices();
    void _Load_BannedAddOns();
    void _Load_BarberShopStyle();
    void _Load_BattlemasterList();
    void _Load_CharacterFacialHairStyles();
    void _Load_CharSections();
    void _Load_CharStartOutfit();
    void _Load_CharTitles();
    void _Load_ChatChannels();
    void _Load_ChrClasses();
    void _Load_ChrRaces();
    void _Load_CinematicCamera();
    void _Load_CinematicSequences();
    void _Load_CreatureDisplayInfo();
    void _Load_CreatureDisplayInfoExtra();
    void _Load_CreatureFamily();
    void _Load_CreatureModelData();
    void _Load_CreatureSpellData();
    void _Load_CreatureType();
    void _Load_CurrencyCategory();
    void _Load_CurrencyTypes();
    void _Load_DestructibleModelData();
    void _Load_DungeonEncounter();
    void _Load_DurabilityCosts();
    void _Load_DurabilityQuality();
    void _Load_Emotes();
    void _Load_EmotesText();
    void _Load_EmotesTextSound();
    void _Load_Faction();
    void _Load_FactionTemplate();
    void _Load_GameObjectArtKit();
    void _Load_GameObjectDisplayInfo();
    void _Load_GemProperties();
    void _Load_GlyphProperties();
    void _Load_GlyphSlot();
    void _Load_gtBarberShopCostBase();
    void _Load_gtCombatRatings();
    void _Load_gtChanceToMeleeCritBase();
    void _Load_gtChanceToMeleeCrit();
    void _Load_gtChanceToSpellCritBase();
    void _Load_gtChanceToSpellCrit();
    void _Load_gtNPCManaCostScaler();
    void _Load_gtOCTClassCombatRatingScalar();
    void _Load_gtOCTRegenHP();
    void _Load_gtOCTRegenMP();
    void _Load_gtRegenHPPerSpt();
    void _Load_gtRegenMPPerSpt();
    void _Load_Holidays();
    void _Load_Item();
    void _Load_ItemBagFamily();
    void _Load_ItemDisplayInfo();
    void _Load_ItemExtendedCost();
    void _Load_ItemLimitCategory();
    void _Load_ItemRandomProperties();
    void _Load_ItemRandomSuffix();
    void _Load_ItemSet();
    void _Load_LFGDungeons();
    void _Load_Light();
    void _Load_LiquidType();
    void _Load_Lock();
    void _Load_MailTemplate();
    void _Load_Map();
    void _Load_MapDifficulty();
    void _Load_Movie();
    void _Load_NamesProfanity();
    void _Load_NamesReserved();
    void _Load_OverrideSpellData();
    void _Load_PowerDisplay();
    void _Load_PvpDifficulty();
    void _Load_QuestSort();
    void _Load_QuestXP();
    void _Load_QuestFactionReward();
    void _Load_RandPropPoints();
    void _Load_ScalingStatDistribution();
    void _Load_ScalingStatValues();
    void _Load_SkillLine();
    void _Load_SkillLineAbility();
    void _Load_SkillRaceClassInfo();
    void _Load_SkillTiers();
    void _Load_SoundEntries();
    void _Load_Spell();
    void _Load_SpellCastTimes();
    void _Load_SpellCategory();
    void _Load_SpellItemEnchantment();
    void _Load_SpellDifficulty();
    void _Load_SpellDuration();
    void _Load_SpellFocusObject();
    void _Load_SpellItemEnchantmentCondition();
    void _Load_SpellRadius();
    void _Load_SpellRange();
    void _Load_SpellRuneCost();
    void _Load_SpellShapeshiftForm();
    void _Load_SpellVisual();
    void _Load_StableSlotPrices();
    void _Load_SummonProperties();
    void _Load_Talent();
    void _Load_TalentTab();
    void _Load_TaxiNodes();
    void _Load_TaxiPath();
    void _Load_TaxiPathNode();
    void _Load_TeamContributionPoints();
    void _Load_TotemCategory();
    void _Load_TransportAnimation();
    void _Load_TransportRotation();
    void _Load_Vehicle();
    void _Load_VehicleSeat();
    void _Load_WMOAreaTable();
    void _Load_WorldMapArea();
    void _Load_WorldMapOverlay();
    void _Load_WorldSafeLocs();
    
    void Initialize_WorldDBC_Corrections();
    void Initialize_Additional_Data();

    // Handle Additional dbc from world db
    void _Handle_World_Achievement();
    void _Handle_World_Spell();
    void _Handle_World_SpellDifficulty();

    // Handle others containers
    void _Handle_NamesProfanityRegex();
    void _Handle_NamesReservedRegex();
    void _Handle_PetFamilySpellsStore();
    void _Handle_TalentSpellPosStore();
    void _Handle_TalentTabPages();
    void _Handle_TaxiNodesMask();
    void _Handle_TaxiPathSetBySource();
    void _Handle_TaxiPathNodesByPath();

    void _Handle_CharacterFacialHairStylesByTripple();
    void _Handle_CharSectionsByPenta();
    void _Handle_CharStartOutfitByTripple();
    void _Handle_EmotesTextSoundByTripple();
    void _Handle_LFGDungeonDBCByDouble();
    void _Handle_MapDifficultyByDouble();
    void _Handle_SkillRaceClassInfo();
    void _Handle_WMOAreaInfoByTripple();

private:
    AchievementDBCMap _achievementMap;
    AchievementCriteriaDBCMap _achievementCriteriaMap;
    AreaTableDBCMap _areaTableMap;
    AreaGroupDBCMap _areaGroupMap;
    AreaPOIDBCMap _areaPOIMap;
    AreaTriggerDBCMap _areaTriggerMap;
    AuctionHouseDBCMap _auctionHouseMap;
    BankBagSlotPricesDBCMap _bankBagSlotPricesMap;
    BannedAddOnsDBCMap _bannedAddonsMap;
    BarberShopStyleDBCMap _barberShopStyleMap;
    BattlemasterListDBCMap _battlemasterListMap;
    CharacterFacialHairStylesDBCMap _characterFacialHairStyleMap;
    CharSectionsDBCMap _charSectionMap;
    CharStartOutfitDBCMap _charStartOutfitMap;
    CharTitlesDBCMap _charTitlesMap;
    ChatChannelsDBCMap _chatChannelsMap;
    ChrClassesDBCMap _chrClassesMap;
    ChrRacesDBCMap _chrRacesMap;
    CinematicCameraDBCMap _cinematicCameraMap;
    CinematicSequencesDBCMap _cinematicSequencesMap;
    CreatureDisplayInfoDBCMap _creatureDisplayInfoMap;
    CreatureDisplayInfoExtraDBCMap _creatureDisplayInfoExtraMap;
    CreatureFamilyDBCMap _creatureFamilyMap;
    CreatureModelDataDBCMap _creatureModelDataMap;
    CreatureSpellDataDBCMap _creatureSpellDataMap;
    CreatureTypeDBCMap _creatureTypeMap;
    CurrencyCategoryDBCMap _currencyCategoryMap;
    CurrencyTypesDBCMap _currencyTypesMap;
    DestructibleModelDataDBCMap _destructibleModelDataMap;
    DungeonEncounterDBCMap _dungeonEncounterMap;
    DurabilityCostsDBCMap _durabilityCoastsMap;
    DurabilityQualityDBCMap _durabilityQualityMap;
    EmotesDBCMap _emotesMap;
    EmotesTextDBCMap _emotesTextMap;
    EmotesTextSoundDBCMap _emotesTextSoundMap;
    FactionDBCMap _factionMap;
    FactionTemplateDBCMap _factionTemplateMap;
    GameObjectArtKitDBCMap _gameobjectArtKitMap;
    GameObjectDisplayInfoDBCMap _gameobjectDisplayInfoMap;
    GemPropertiesDBCMap _gemPropertiesMap;
    GlyphPropertiesDBCMap _glyphPropertiesMap;
    GlyphSlotDBCMap _glyphSlotMap;
    GtBarberShopCostBaseDBCMap _gtBarberShopCostBaseMap;
    GtCombatRatingsDBCMap _gtCombatRatingsMap;
    GtChanceToMeleeCritBaseDBCMap _gtChanceToMeleeCritBaseMap;
    GtChanceToMeleeCritDBCMap _gtChanceToMeleeCritMap;
    GtChanceToSpellCritBaseDBCMap _gtChanceToSpellCritBaseMap;
    GtChanceToSpellCritDBCMap _gtChanceToSpellCritMap;
    GtNPCManaCostScalerDBCMap _gtNPCManaCostScalerMap;
    GtOCTClassCombatRatingScalarDBCMap _gtOCTClassCombatRatingScalarMap;
    GtOCTRegenHPDBCMap _gtOCTRegenHPMap;
    GtOCTRegenMPDBCMap _gtOCTRegenMPMap;
    GtRegenHPPerSptDBCMap _gtRegenHPPerSptMap;
    GtRegenMPPerSptDBCMap _gtRegenMPPerSptMap;
    HolidaysDBCMap _holidaysMap;
    ItemDBCMap _itemMap;
    ItemBagFamilyDBCMap _itemBagFamilyMap;
    ItemDisplayInfoDBCMap _itemDisplayInfoMap;
    ItemExtendedCostDBCMap _itemExtendedCostMap;
    ItemLimitCategoryDBCMap _itemLimitCategoryMap;
    ItemRandomPropertiesDBCMap _itemRandomPropertiesMap;
    ItemRandomSuffixDBCMap _itemRandomSuffixMap;    
    ItemSetDBCMap _itemSetMap;
    LFGDungeonDBCMap _lfgDungeonMap;
    LightDBCMap _lightMap;
    LiquidTypeDBCMap _liquidTypeMap;
    LockDBCMap _lockMap;
    MailTemplateDBCMap _mailTemplateMap;
    MapDBCMap _mapMap;
    MapDifficultyDBCMap _mapDifficultyMap;
    MovieDBCMap _movieMap;
    NamesProfanityDBCMap _namesProfanityMap;
    NamesReservedDBCMap _namesReservedMap;
    OverrideSpellDataDBCMap _overrideSpellDataMap;
    PowerDisplayDBCMap _powerDisplayMap;
    PvPDifficultyDBCMap _pvpDifficultyMap;
    QuestSortDBCMap _questSortMap;
    QuestXPDBCMap _questXPMap;
    QuestFactionRewardDBCMap _questFactionRewardMap;
    RandPropPointsDBCMap _randPropPointsMap;
    ScalingStatDistributionDBCMap _scalingStatDistributionMap;
    ScalingStatValuesDBCMap _scalingStatValuesMap;
    SkillLineDBCMap _skillLineMap;
    SkillLineAbilityDBCMap _skillLineAbilityMap;
    SkillRaceClassInfoDBCMap _skillRaceClassInfoMap;
    SkillTiersDBCMap _skillTiersMap;
    SoundEntriesDBCMap _soundEntriesMap;
    SpellDBCMap _spellMap;
    SpellCastTimesDBCMap _spellCastTimesMap;
    SpellCategoryDBCMap _spellCategoryMap;
    SpellItemEnchantmentDBCMap _spellItemEnchantmentMap;
    SpellDifficultyDBCMap _spellDiffucultyMap;
    SpellDurationDBCMap _spellDurationMap;
    SpellFocusObjectDBCMap _spellFocusObjectMap;
    SpellItemEnchantmentConditionDBCMap _spellItemEnchantmentConditionMap;
    SpellRadiusDBCMap _spellRadiusMap;
    SpellRangeDBCMap _spellRangeMap;
    SpellRuneCostDBCMap _spellRuneCostMap;
    SpellShapeshiftFormDBCMap _spellShapeShiftFormMap;
    SpellVisualDBCMap _spellVisualMap;
    StableSlotPricesDBCMap _stableSlotPricesMap;
    SummonPropertiesDBCMap _summonPropertiesMap;
    TalentDBCMap _talentMap;
    TalentTabDBCMap _talentTabMap;
    TaxiNodesDBCMap _taxiNodesMap;
    TaxiPathDBCMap _taxiPathMap;
    TaxiPathNodeDBCMap _taxiPathNodeMap;
    TeamContributionPointsDBCMap _teamContributionPointsMap;
    TotemCategoryDBCMap _totemCategoryMap;
    TransportAnimationDBCMap _transportAnimationMap;
    TransportRotationDBCMap _transportRotationMap;
    VehicleDBCMap _vehicleMap;
    VehicleSeatDBCMap _vehicleSeatMap;
    WMOAreaTableDBCMap _wmoAreaTableMap;
    WorldMapAreaDBCMap _worldMapAreaMap;
    WorldMapOverlayDBCMap _worldMapOverlayMap;
    WorldSafeLocsDBCMap _worldSafeLocsMap;

    // handler containers
    NameValidationRegexContainer NamesProfaneValidators;
    NameValidationRegexContainer NamesReservedValidators;
    PetFamilySpellsStore _petFamilySpellsStore;
    PetTalentSpells _petTalentSpells;
    TalentSpellPosMap _talentSpellPos;

    uint32 _bannedAddonsNumRow;
    uint32 _itemRandomSuffixNumRow;
    uint32 _spellNumRow;
    uint32 _spellItemEnchantmentNumRow;
    uint32 _taxiPathNumRow;
    // store absolute bit position for first rank for talent inspect
    uint32 _TalentTabPages[MAX_CLASSES][3];

    TaxiMask _TaxiNodesMask;
    TaxiMask _OldContinentsNodesMask;
    TaxiMask _HordeTaxiNodesMask;
    TaxiMask _AllianceTaxiNodesMask;
    TaxiMask _DeathKnightTaxiNodesMask;
    TaxiPathSetBySource _taxiPathSetBySource;
    TaxiPathNodesByPath _taxiPathNodesByPath;

    CharacterFacialHairStylesByTripple _characterFacialHairStylesByTripple;
    CharSectionsByPenta _charSectionsByPenta;
    CharStartOutfitByTripple _charStartOutfitByTripple;
    EmotesTextSoundByTripple _emotesTextSoundByTripple;
    LFGDungeonDBCByDouble _lfgDungeonByDouble;
    MapDifficultyByDouble _mapDifficultyByDouble;
    SkillRaceClassInfoMap _skillRaceClassInfoBySkill;
    WMOAreaInfoByTripple _wmoAreaInfoByTripple;
};

#define sDBCStoresMgr DBCStoresMgr::instance()

#endif // _DBCMGR_H
