/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_DBCSTORES_H
#define TRINITY_DBCSTORES_H

#include "Common.h"
#include "DBCStore.h"
#include "DBCStructure.h"

#include <list>

typedef std::list<uint32> SimpleFactionsList;
SimpleFactionsList const* GetFactionTeamList(uint32 faction);

char const* GetPetName(uint32 petfamily, uint32 dbclang);
uint32 GetTalentSpellCost(uint32 spellId);
TalentSpellPos const* GetTalentSpellPos(uint32 spellId);
SpellEffectEntry const* GetSpellEffectEntry(uint32 spellId, uint32 effect);
SpellReagentsEntry const* GetSpellReagentEntry(uint32 spellId, uint8 reagent);
SpellTotemsEntry const* GetSpellTotemEntry(uint32 spellId, uint8 totem);

int32 GetAreaFlagByAreaID(uint32 area_id);                  // -1 if not found
AreaTableEntry const* GetAreaEntryByAreaID(uint32 area_id);
AreaTableEntry const* GetAreaEntryByAreaFlagAndMap(uint32 area_flag, uint32 map_id);
uint32 GetAreaFlagByMapId(uint32 mapid);

WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid);

uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId);

enum ContentLevels
{
    CONTENT_1_60 = 0,
    CONTENT_61_70,
    CONTENT_71_80
};
ContentLevels GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId);

bool IsTotemCategoryCompatiableWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId);

void Zone2MapCoordinates(float &x, float &y, uint32 zone);
void Map2ZoneCoordinates(float &x, float &y, uint32 zone);

typedef std::map<uint32/*pair32(map, diff)*/, MapDifficulty> MapDifficultyMap;
MapDifficulty const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty);
MapDifficulty const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty);

uint32 const* /*[MAX_TALENT_TABS]*/ GetTalentTabPages(uint8 cls);

PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);

extern DBCStorage <AchievementEntry>             sAchievementStore;
extern DBCStorage <AchievementCriteriaEntry>     sAchievementCriteriaStore;
extern DBCStorage <AreaTableEntry>               sAreaStore;// recommend access using functions
extern DBCStorage <AreaGroupEntry>               sAreaGroupStore;
extern DBCStorage <AreaPOIEntry>                 sAreaPOIStore;
extern DBCStorage <AreaTriggerEntry>             sAreaTriggerStore;
extern DBCStorage <ArmorLocationEntry>           sArmorLocationStore;
extern DBCStorage <AuctionHouseEntry>            sAuctionHouseStore;
extern DBCStorage <BankBagSlotPricesEntry>       sBankBagSlotPricesStore;
extern DBCStorage <BarberShopStyleEntry>         sBarberShopStyleStore;
extern DBCStorage <BattlemasterListEntry>        sBattlemasterListStore;
extern DBCStorage <ChatChannelsEntry>            sChatChannelsStore;
extern DBCStorage <CharStartOutfitEntry>         sCharStartOutfitStore;
extern DBCStorage <CharTitlesEntry>              sCharTitlesStore;
extern DBCStorage <ChrClassesEntry>              sChrClassesStore;
extern DBCStorage <ChrRacesEntry>                sChrRacesStore;
extern DBCStorage <ChrPowerTypesEntry>           sChrPowerTypesStore;
extern DBCStorage <CinematicSequencesEntry>      sCinematicSequencesStore;
extern DBCStorage <CreatureDisplayInfoEntry>     sCreatureDisplayInfoStore;
extern DBCStorage <CreatureFamilyEntry>          sCreatureFamilyStore;
extern DBCStorage <CreatureSpellDataEntry>       sCreatureSpellDataStore;
extern DBCStorage <CreatureTypeEntry>            sCreatureTypeStore;
extern DBCStorage <CurrencyTypesEntry>           sCurrencyTypesStore;
extern DBCStorage <DestructibleModelDataEntry>   sDestructibleModelDataStore;
extern DBCStorage <DungeonEncounterEntry>        sDungeonEncounterStore;
extern DBCStorage <DurabilityCostsEntry>         sDurabilityCostsStore;
extern DBCStorage <DurabilityQualityEntry>       sDurabilityQualityStore;
extern DBCStorage <EmotesEntry>                  sEmotesStore;
extern DBCStorage <EmotesTextEntry>              sEmotesTextStore;
extern DBCStorage <FactionEntry>                 sFactionStore;
extern DBCStorage <FactionTemplateEntry>         sFactionTemplateStore;
extern DBCStorage <GameObjectDisplayInfoEntry>   sGameObjectDisplayInfoStore;
extern DBCStorage <GemPropertiesEntry>           sGemPropertiesStore;
extern DBCStorage <GlyphPropertiesEntry>         sGlyphPropertiesStore;
extern DBCStorage <GlyphSlotEntry>               sGlyphSlotStore;

extern DBCStorage <GtBarberShopCostBaseEntry>    sGtBarberShopCostBaseStore;
extern DBCStorage <GtCombatRatingsEntry>         sGtCombatRatingsStore;
extern DBCStorage <GtChanceToMeleeCritBaseEntry> sGtChanceToMeleeCritBaseStore;
extern DBCStorage <GtChanceToMeleeCritEntry>     sGtChanceToMeleeCritStore;
extern DBCStorage <GtChanceToSpellCritBaseEntry> sGtChanceToSpellCritBaseStore;
extern DBCStorage <GtChanceToSpellCritEntry>     sGtChanceToSpellCritStore;
extern DBCStorage <GtOCTClassCombatRatingScalarEntry> sGtOCTClassCombatRatingScalarStore;
//extern DBCStorage <GtOCTRegenMPEntry>            sGtOCTRegenMPStore; -- not used currently
extern DBCStorage <GtRegenHPPerSptEntry>         sGtRegenHPPerSptStore;
extern DBCStorage <gtOCTHpPerStaminaEntry>       sGtOCTHpPerStaminaStore;
extern DBCStorage <GtRegenMPPerSptEntry>         sGtRegenMPPerSptStore;
extern DBCStorage <HolidaysEntry>                sHolidaysStore;
extern DBCStorage <ItemArmorQualityEntry>        sItemArmorQualityStore;
extern DBCStorage <ItemArmorShieldEntry>         sItemArmorShieldStore;
extern DBCStorage <ItemArmorTotalEntry>          sItemArmorTotalStore;
extern DBCStorage <ItemBagFamilyEntry>           sItemBagFamilyStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageAmmoStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageOneHandStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageOneHandCasterStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageRangedStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageThrownStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageTwoHandStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageTwoHandCasterStore;
extern DBCStorage <ItemDamageEntry>              sItemDamageWandStore;
//extern DBCStorage <ItemDisplayInfoEntry>      sItemDisplayInfoStore; -- not used currently
extern DBCStorage <ItemLimitCategoryEntry>       sItemLimitCategoryStore;
extern DBCStorage <ItemRandomPropertiesEntry>    sItemRandomPropertiesStore;
extern DBCStorage <ItemRandomSuffixEntry>        sItemRandomSuffixStore;
extern DBCStorage <ItemSetEntry>                 sItemSetStore;
extern DBCStorage <LFGDungeonEntry>              sLFGDungeonStore;
extern DBCStorage <LockEntry>                    sLockStore;
extern DBCStorage <MailTemplateEntry>            sMailTemplateStore;
extern DBCStorage <MapEntry>                     sMapStore;
extern DBCStorage <PhaseEntry>                   sPhaseStore;
//extern DBCStorage <MapDifficultyEntry>           sMapDifficultyStore; -- use GetMapDifficultyData insteed
extern MapDifficultyMap                          sMapDifficultyMap;
extern DBCStorage <MovieEntry>                   sMovieStore;
extern DBCStorage <OverrideSpellDataEntry>       sOverrideSpellDataStore;
extern DBCStorage <QuestSortEntry>               sQuestSortStore;
extern DBCStorage <QuestXPEntry>                 sQuestXPStore;
extern DBCStorage <QuestFactionRewEntry>         sQuestFactionRewardStore;
extern DBCStorage <RandomPropertiesPointsEntry>  sRandomPropertiesPointsStore;
extern DBCStorage <ScalingStatDistributionEntry> sScalingStatDistributionStore;
extern DBCStorage <ScalingStatValuesEntry>       sScalingStatValuesStore;
extern DBCStorage <SkillLineEntry>               sSkillLineStore;
extern DBCStorage <SkillLineAbilityEntry>        sSkillLineAbilityStore;
extern DBCStorage <SoundEntriesEntry>            sSoundEntriesStore;
extern DBCStorage <SpellCastTimesEntry>          sSpellCastTimesStore;
extern DBCStorage <SpellDifficultyEntry>         sSpellDifficultyStore;
extern DBCStorage <SpellDurationEntry>           sSpellDurationStore;
extern DBCStorage <SpellFocusObjectEntry>        sSpellFocusObjectStore;
extern DBCStorage <SpellItemEnchantmentEntry>    sSpellItemEnchantmentStore;
extern DBCStorage <SpellItemEnchantmentConditionEntry> sSpellItemEnchantmentConditionStore;
extern SpellCategoryStore                        sSpellCategoryStore;
extern PetFamilySpellsStore                      sPetFamilySpellsStore;
extern DBCStorage <SpellRadiusEntry>             sSpellRadiusStore;
extern DBCStorage <SpellRangeEntry>              sSpellRangeStore;
extern DBCStorage <SpellRuneCostEntry>           sSpellRuneCostStore;
extern DBCStorage <SpellShapeshiftEntry>         sSpellShapeshiftStore;
extern DBCStorage <SpellShapeshiftFormEntry>     sSpellShapeshiftFormStore;
extern DBCStorage <SpellEntry>                   sSpellStore;
extern DBCStorage <SpellAuraOptionsEntry>        sSpellAuraOptionsStore;
extern DBCStorage <SpellAuraRestrictionsEntry>   sSpellAuraRestrictionsStore;
extern DBCStorage <SpellCastingRequirementsEntry> sSpellCastingRequirementsStore;
extern DBCStorage <SpellCategoriesEntry>         sSpellCategoriesStore;
extern DBCStorage <SpellClassOptionsEntry>       sSpellClassOptionsStore;
extern DBCStorage <SpellCooldownsEntry>          sSpellCooldownsStore;
extern DBCStorage <SpellEffectEntry>             sSpellEffectStore;
extern DBCStorage <SpellEquippedItemsEntry>      sSpellEquippedItemsStore;
extern DBCStorage <SpellInterruptsEntry>         sSpellInterruptsStore;
extern DBCStorage <SpellLevelsEntry>             sSpellLevelsStore;
extern DBCStorage <SpellPowerEntry>              sSpellPowerStore;
extern DBCStorage <SpellReagentsEntry>           sSpellReagentsStore;
extern DBCStorage <SpellScalingEntry>            sSpellScalingStore;
extern DBCStorage <SpellTargetRestrictionsEntry> sSpellTargetRestrictionsStore;
extern DBCStorage <SpellTotemsEntry>             sSpellTotemsStore;
//extern DBCStorage <StableSlotPricesEntry>        sStableSlotPricesStore;
extern DBCStorage <SummonPropertiesEntry>        sSummonPropertiesStore;
extern DBCStorage <TalentEntry>                  sTalentStore;
extern DBCStorage <TalentTabEntry>               sTalentTabStore;
extern DBCStorage <TaxiNodesEntry>               sTaxiNodesStore;
extern DBCStorage <TaxiPathEntry>                sTaxiPathStore;
extern TaxiMask                                  sTaxiNodesMask;
extern TaxiMask                                  sOldContinentsNodesMask;
extern TaxiMask                                  sHordeTaxiNodesMask;
extern TaxiMask                                  sAllianceTaxiNodesMask;
extern TaxiMask                                  sDeathKnightTaxiNodesMask;
extern TaxiPathSetBySource                       sTaxiPathSetBySource;
extern TaxiPathNodesByPath                       sTaxiPathNodesByPath;
extern DBCStorage <TotemCategoryEntry>           sTotemCategoryStore;
extern DBCStorage <VehicleEntry>                 sVehicleStore;
extern DBCStorage <VehicleSeatEntry>             sVehicleSeatStore;
extern DBCStorage <WMOAreaTableEntry>            sWMOAreaTableStore;
//extern DBCStorage <WorldMapAreaEntry>           sWorldMapAreaStore; -- use Zone2MapCoordinates and Map2ZoneCoordinates
extern DBCStorage <WorldMapOverlayEntry>         sWorldMapOverlayStore;
extern DBCStorage <WorldSafeLocsEntry>           sWorldSafeLocsStore;

void LoadDBCStores(const std::string& dataPath);

// script support functions
 DBCStorage <SoundEntriesEntry>          const* GetSoundEntriesStore();
 DBCStorage <SpellRangeEntry>            const* GetSpellRangeStore();
 DBCStorage <FactionEntry>               const* GetFactionStore();
// DBCStorage <ItemEntry>                  const* GetItemDisplayStore();
 DBCStorage <CreatureDisplayInfoEntry>   const* GetCreatureDisplayStore();
 DBCStorage <EmotesEntry>                const* GetEmotesStore();
 DBCStorage <EmotesTextEntry>            const* GetEmotesTextStore();
 DBCStorage <AchievementEntry>           const* GetAchievementStore();
#endif
