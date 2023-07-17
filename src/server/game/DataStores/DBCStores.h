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

#ifndef TRINITY_DBCSTORES_H
#define TRINITY_DBCSTORES_H

#include "DBCStore.h"
#include "DBCStructure.h"
#include "SharedDefines.h"
#include <list>
#include <map>
#include <unordered_map>

enum LocaleConstant : uint8;

// temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

typedef std::list<uint32> SimpleFactionsList;
typedef std::map<uint32/*pair32(map, diff)*/, MapDifficulty> MapDifficultyMap;
typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoMap;
typedef std::pair<SkillRaceClassInfoMap::iterator, SkillRaceClassInfoMap::iterator> SkillRaceClassInfoBounds;

TC_GAME_API extern DBCStorage <AchievementEntry>             sAchievementStore;
TC_GAME_API extern DBCStorage <AnimKitEntry>                 sAnimKitStore;
TC_GAME_API extern DBCStorage <AchievementCriteriaEntry>     sAchievementCriteriaStore;
TC_GAME_API extern DBCStorage <AreaTableEntry>               sAreaTableStore;
TC_GAME_API extern DBCStorage <AreaGroupEntry>               sAreaGroupStore;
TC_GAME_API extern DBCStorage <AreaPOIEntry>                 sAreaPOIStore;
TC_GAME_API extern DBCStorage <AreaTriggerEntry>             sAreaTriggerStore;
TC_GAME_API extern DBCStorage <ArmorLocationEntry>           sArmorLocationStore;
TC_GAME_API extern DBCStorage <AuctionHouseEntry>            sAuctionHouseStore;
TC_GAME_API extern DBCStorage <BankBagSlotPricesEntry>       sBankBagSlotPricesStore;
TC_GAME_API extern DBCStorage <BannedAddOnsEntry>            sBannedAddOnsStore;
TC_GAME_API extern DBCStorage <BarberShopStyleEntry>         sBarberShopStyleStore;
TC_GAME_API extern DBCStorage <BattlemasterListEntry>        sBattlemasterListStore;
TC_GAME_API extern DBCStorage <ChatChannelsEntry>            sChatChannelsStore;
TC_GAME_API extern DBCStorage <CharStartOutfitEntry>         sCharStartOutfitStore;
TC_GAME_API extern DBCStorage <CharSectionsEntry>            sCharSectionsStore;
TC_GAME_API extern DBCStorage <CharTitlesEntry>              sCharTitlesStore;
TC_GAME_API extern DBCStorage <ChrClassesEntry>              sChrClassesStore;
TC_GAME_API extern DBCStorage <ChrRacesEntry>                sChrRacesStore;
TC_GAME_API extern DBCStorage <ChrPowerTypesEntry>           sChrPowerTypesStore;
TC_GAME_API extern DBCStorage <CinematicCameraEntry>         sCinematicCameraStore;
TC_GAME_API extern DBCStorage <CinematicSequencesEntry>      sCinematicSequencesStore;
TC_GAME_API extern DBCStorage <CreatureDisplayInfoEntry>     sCreatureDisplayInfoStore;
TC_GAME_API extern DBCStorage <CreatureDisplayInfoExtraEntry> sCreatureDisplayInfoExtraStore;
TC_GAME_API extern DBCStorage <CreatureFamilyEntry>          sCreatureFamilyStore;
TC_GAME_API extern DBCStorage <CreatureModelDataEntry>       sCreatureModelDataStore;
TC_GAME_API extern DBCStorage <CreatureSpellDataEntry>       sCreatureSpellDataStore;
TC_GAME_API extern DBCStorage <CreatureTypeEntry>            sCreatureTypeStore;
TC_GAME_API extern DBCStorage <CurrencyTypesEntry>           sCurrencyTypesStore;
TC_GAME_API extern DBCStorage <DestructibleModelDataEntry>   sDestructibleModelDataStore;
TC_GAME_API extern DBCStorage <DungeonEncounterEntry>        sDungeonEncounterStore;
TC_GAME_API extern DBCStorage <DurabilityCostsEntry>         sDurabilityCostsStore;
TC_GAME_API extern DBCStorage <DurabilityQualityEntry>       sDurabilityQualityStore;
TC_GAME_API extern DBCStorage <EmotesEntry>                  sEmotesStore;
TC_GAME_API extern DBCStorage <EmotesTextEntry>              sEmotesTextStore;
TC_GAME_API extern DBCStorage <EmotesTextSoundEntry>         sEmotesTextSoundStore;
TC_GAME_API extern DBCStorage <FactionEntry>                 sFactionStore;
TC_GAME_API extern DBCStorage <FactionTemplateEntry>         sFactionTemplateStore;
TC_GAME_API extern DBCStorage <GameObjectArtKitEntry>        sGameObjectArtKitStore;
TC_GAME_API extern DBCStorage <GameObjectDisplayInfoEntry>   sGameObjectDisplayInfoStore;
TC_GAME_API extern DBCStorage <GemPropertiesEntry>           sGemPropertiesStore;
TC_GAME_API extern DBCStorage <GlyphPropertiesEntry>         sGlyphPropertiesStore;
TC_GAME_API extern DBCStorage <GlyphSlotEntry>               sGlyphSlotStore;
TC_GAME_API extern DBCStorage <GtBarberShopCostBaseEntry>    sGtBarberShopCostBaseStore;
TC_GAME_API extern DBCStorage <GtCombatRatingsEntry>         sGtCombatRatingsStore;
TC_GAME_API extern DBCStorage <GtChanceToMeleeCritBaseEntry> sGtChanceToMeleeCritBaseStore;
TC_GAME_API extern DBCStorage <GtChanceToMeleeCritEntry>     sGtChanceToMeleeCritStore;
TC_GAME_API extern DBCStorage <GtChanceToSpellCritBaseEntry> sGtChanceToSpellCritBaseStore;
TC_GAME_API extern DBCStorage <GtChanceToSpellCritEntry>     sGtChanceToSpellCritStore;
TC_GAME_API extern DBCStorage <GtNPCManaCostScalerEntry>     sGtNPCManaCostScalerStore;
TC_GAME_API extern DBCStorage <GtOCTClassCombatRatingScalarEntry> sGtOCTClassCombatRatingScalarStore;
//TC_GAME_API extern DBCStorage <GtOCTRegenMPEntry>            sGtOCTRegenMPStore; -- not used currently
TC_GAME_API extern DBCStorage <gtOCTHpPerStaminaEntry>       sGtOCTHpPerStaminaStore;
TC_GAME_API extern DBCStorage <GtRegenMPPerSptEntry>         sGtRegenMPPerSptStore;
TC_GAME_API extern DBCStorage <GtSpellScalingEntry>          sGtSpellScalingStore;
TC_GAME_API extern DBCStorage <GtOCTBaseHPByClassEntry>      sGtOCTBaseHPByClassStore;
TC_GAME_API extern DBCStorage <GtOCTBaseMPByClassEntry>      sGtOCTBaseMPByClassStore;
TC_GAME_API extern DBCStorage <GuildPerkSpellsEntry>         sGuildPerkSpellsStore;
TC_GAME_API extern DBCStorage <HolidaysEntry>                sHolidaysStore;
TC_GAME_API extern DBCStorage <ImportPriceArmorEntry>        sImportPriceArmorStore;
TC_GAME_API extern DBCStorage <ImportPriceQualityEntry>      sImportPriceQualityStore;
TC_GAME_API extern DBCStorage <ImportPriceShieldEntry>       sImportPriceShieldStore;
TC_GAME_API extern DBCStorage <ImportPriceWeaponEntry>       sImportPriceWeaponStore;
TC_GAME_API extern DBCStorage <ItemPriceBaseEntry>           sItemPriceBaseStore;
TC_GAME_API extern DBCStorage <ItemReforgeEntry>             sItemReforgeStore;
TC_GAME_API extern DBCStorage <ItemArmorQualityEntry>        sItemArmorQualityStore;
TC_GAME_API extern DBCStorage <ItemArmorShieldEntry>         sItemArmorShieldStore;
TC_GAME_API extern DBCStorage <ItemArmorTotalEntry>          sItemArmorTotalStore;
TC_GAME_API extern DBCStorage <ItemClassEntry>               sItemClassStore;
TC_GAME_API extern DBCStorage <ItemBagFamilyEntry>           sItemBagFamilyStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageAmmoStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageOneHandStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageOneHandCasterStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageRangedStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageThrownStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageTwoHandStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageTwoHandCasterStore;
TC_GAME_API extern DBCStorage <ItemDamageEntry>              sItemDamageWandStore;
//TC_GAME_API extern DBCStorage <ItemDisplayInfoEntry>      sItemDisplayInfoStore; -- not used currently
TC_GAME_API extern DBCStorage <ItemDisenchantLootEntry>      sItemDisenchantLootStore;
TC_GAME_API extern DBCStorage <ItemLimitCategoryEntry>       sItemLimitCategoryStore;
TC_GAME_API extern DBCStorage <ItemRandomPropertiesEntry>    sItemRandomPropertiesStore;
TC_GAME_API extern DBCStorage <ItemRandomSuffixEntry>        sItemRandomSuffixStore;
TC_GAME_API extern DBCStorage <ItemSetEntry>                 sItemSetStore;
TC_GAME_API extern DBCStorage <LFGDungeonEntry>              sLFGDungeonStore;
TC_GAME_API extern DBCStorage <LFGDungeonsGroupingMapEntry>  sLFGDungeonsGroupingMapStore;
TC_GAME_API extern DBCStorage <LiquidTypeEntry>              sLiquidTypeStore;
TC_GAME_API extern DBCStorage <LockEntry>                    sLockStore;
TC_GAME_API extern DBCStorage <MailTemplateEntry>            sMailTemplateStore;
TC_GAME_API extern DBCStorage <MapEntry>                     sMapStore;
TC_GAME_API extern DBCStorage <MountCapabilityEntry>         sMountCapabilityStore;
TC_GAME_API extern DBCStorage <MountTypeEntry>               sMountTypeStore;
//TC_GAME_API extern DBCStorage <NameGenEntry>                 sNameGenStore; -- use GetRandomCharacterName instead
TC_GAME_API extern DBCStorage <NumTalentsAtLevelEntry>       sNumTalentsAtLevelStore;
TC_GAME_API extern DBCStorage <PhaseEntry>                   sPhaseStore;
TC_GAME_API extern DBCStorage <PhaseGroupEntry>              sPhaseGroupStore;
TC_GAME_API extern DBCStorage <LightEntry>                   sLightStore;
//TC_GAME_API extern DBCStorage <MapDifficultyEntry>           sMapDifficultyStore; -- use GetMapDifficultyData insteed
TC_GAME_API extern MapDifficultyMap                          sMapDifficultyMap;
TC_GAME_API extern DBCStorage <MovieEntry>                   sMovieStore;
TC_GAME_API extern DBCStorage <OverrideSpellDataEntry>       sOverrideSpellDataStore;
TC_GAME_API extern DBCStorage <PlayerConditionEntry>         sPlayerConditionStore;
TC_GAME_API extern DBCStorage <PowerDisplayEntry>            sPowerDisplayStore;
TC_GAME_API extern DBCStorage <QuestSortEntry>               sQuestSortStore;
TC_GAME_API extern DBCStorage <QuestXPEntry>                 sQuestXPStore;
TC_GAME_API extern DBCStorage <QuestFactionRewEntry>         sQuestFactionRewardStore;
TC_GAME_API extern DBCStorage <QuestPOIPointEntry>           sQuestPOIPointStore;
TC_GAME_API extern DBCStorage <QuestPOIBlobEntry>            sQuestPOIBlobStore;
TC_GAME_API extern DBCStorage <RandomPropertiesPointsEntry>  sRandomPropertiesPointsStore;
TC_GAME_API extern DBCStorage <ResearchBranchEntry>          sResearchBranchStore;
TC_GAME_API extern DBCStorage <ResearchFieldEntry>           sResearchFieldStore;
TC_GAME_API extern DBCStorage <ResearchProjectEntry>         sResearchProjectStore;
TC_GAME_API extern DBCStorage <ResearchSiteEntry>            sResearchSiteStore;
TC_GAME_API extern DBCStorage <ScalingStatDistributionEntry> sScalingStatDistributionStore;
TC_GAME_API extern DBCStorage <ScalingStatValuesEntry>       sScalingStatValuesStore;
TC_GAME_API extern DBCStorage <SkillLineEntry>               sSkillLineStore;
TC_GAME_API extern DBCStorage <SkillLineAbilityEntry>        sSkillLineAbilityStore;
TC_GAME_API extern DBCStorage <SkillTiersEntry>              sSkillTiersStore;
TC_GAME_API extern DBCStorage <SoundEntriesEntry>            sSoundEntriesStore;
TC_GAME_API extern DBCStorage <SpellCastTimesEntry>          sSpellCastTimesStore;
TC_GAME_API extern DBCStorage <SpellCategoryEntry>           sSpellCategoryStore;
TC_GAME_API extern DBCStorage <SpellDifficultyEntry>         sSpellDifficultyStore;
TC_GAME_API extern DBCStorage <SpellDurationEntry>           sSpellDurationStore;
TC_GAME_API extern DBCStorage <SpellFocusObjectEntry>        sSpellFocusObjectStore;
TC_GAME_API extern DBCStorage <SpellItemEnchantmentEntry>    sSpellItemEnchantmentStore;
TC_GAME_API extern DBCStorage <SpellItemEnchantmentConditionEntry> sSpellItemEnchantmentConditionStore;
TC_GAME_API extern PetFamilySpellsStore                      sPetFamilySpellsStore;
TC_GAME_API extern DBCStorage <SpellRadiusEntry>             sSpellRadiusStore;
TC_GAME_API extern DBCStorage <SpellRangeEntry>              sSpellRangeStore;
TC_GAME_API extern DBCStorage <SpellRuneCostEntry>           sSpellRuneCostStore;
TC_GAME_API extern DBCStorage <SpellShapeshiftEntry>         sSpellShapeshiftStore;
TC_GAME_API extern DBCStorage <SpellShapeshiftFormEntry>     sSpellShapeshiftFormStore;
TC_GAME_API extern DBCStorage <SpellEntry>                   sSpellStore;
TC_GAME_API extern DBCStorage <SpellVisualEntry>             sSpellVisualStore;
TC_GAME_API extern DBCStorage <SpellVisualKitEntry>          sSpellVisualKitStore;
TC_GAME_API extern DBCStorage <SpellAuraOptionsEntry>        sSpellAuraOptionsStore;
TC_GAME_API extern DBCStorage <SpellAuraRestrictionsEntry>   sSpellAuraRestrictionsStore;
TC_GAME_API extern DBCStorage <SpellCastingRequirementsEntry> sSpellCastingRequirementsStore;
TC_GAME_API extern DBCStorage <SpellCategoriesEntry>         sSpellCategoriesStore;
TC_GAME_API extern DBCStorage <SpellClassOptionsEntry>       sSpellClassOptionsStore;
TC_GAME_API extern DBCStorage <SpellCooldownsEntry>          sSpellCooldownsStore;
TC_GAME_API extern DBCStorage <SpellEffectEntry>             sSpellEffectStore;
TC_GAME_API extern DBCStorage <SpellEquippedItemsEntry>      sSpellEquippedItemsStore;
TC_GAME_API extern DBCStorage <SpellInterruptsEntry>         sSpellInterruptsStore;
TC_GAME_API extern DBCStorage <SpellLevelsEntry>             sSpellLevelsStore;
TC_GAME_API extern DBCStorage <SpellPowerEntry>              sSpellPowerStore;
TC_GAME_API extern DBCStorage <SpellReagentsEntry>           sSpellReagentsStore;
TC_GAME_API extern DBCStorage <SpellScalingEntry>            sSpellScalingStore;
TC_GAME_API extern DBCStorage <SpellTargetRestrictionsEntry> sSpellTargetRestrictionsStore;
TC_GAME_API extern DBCStorage <SpellTotemsEntry>             sSpellTotemsStore;
TC_GAME_API extern DBCStorage <SummonPropertiesEntry>        sSummonPropertiesStore;
TC_GAME_API extern DBCStorage <TalentEntry>                  sTalentStore;
TC_GAME_API extern DBCStorage <TalentTabEntry>               sTalentTabStore;
TC_GAME_API extern DBCStorage <TaxiNodesEntry>               sTaxiNodesStore;
TC_GAME_API extern DBCStorage <TaxiPathEntry>                sTaxiPathStore;
TC_GAME_API extern TaxiMask                                  sTaxiNodesMask;
TC_GAME_API extern TaxiMask                                  sOldContinentsNodesMask;
TC_GAME_API extern TaxiMask                                  sHordeTaxiNodesMask;
TC_GAME_API extern TaxiMask                                  sAllianceTaxiNodesMask;
TC_GAME_API extern TaxiMask                                  sDeathKnightTaxiNodesMask;
TC_GAME_API extern TaxiPathSetBySource                       sTaxiPathSetBySource;
TC_GAME_API extern TaxiPathNodesByPath                       sTaxiPathNodesByPath;
TC_GAME_API extern DBCStorage <TransportAnimationEntry>      sTransportAnimationStore;
TC_GAME_API extern DBCStorage <TransportRotationEntry>       sTransportRotationStore;
TC_GAME_API extern DBCStorage <TotemCategoryEntry>           sTotemCategoryStore;
TC_GAME_API extern DBCStorage <UnitPowerBarEntry>            sUnitPowerBarStore;
TC_GAME_API extern DBCStorage <VehicleEntry>                 sVehicleStore;
TC_GAME_API extern DBCStorage <VehicleSeatEntry>             sVehicleSeatStore;
TC_GAME_API extern DBCStorage <WMOAreaTableEntry>            sWMOAreaTableStore;
TC_GAME_API extern DBCStorage <WorldMapAreaEntry>            sWorldMapAreaStore;
TC_GAME_API extern DBCStorage <WorldMapOverlayEntry>         sWorldMapOverlayStore;
TC_GAME_API extern DBCStorage <WorldSafeLocsEntry>           sWorldSafeLocsStore;

class TC_GAME_API DBCManager
{
public:
    static DBCManager& Instance();

    void LoadStores(const std::string& dataPath, uint32 defaultLocale);

    SimpleFactionsList const* GetFactionTeamList(uint32 faction);
    static char const* GetPetName(uint32 petfamily, uint32 dbclang);
    uint32 GetTalentSpellCost(uint32 spellId);
    TalentSpellPos const* GetTalentSpellPos(uint32 spellId);
    static char const* GetRaceName(uint8 race, uint8 locale);
    static char const* GetClassName(uint8 class_, uint8 locale);
    WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid);
    static uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId);
    std::string const& GetRandomCharacterName(uint8 race, uint8 gender);
    static uint32 GetMaxLevelForExpansion(uint32 expansion);
    ContentLevels GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId);
    static bool IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId);
    bool Zone2MapCoordinates(float &x, float &y, uint32 zone) const;
    void Map2ZoneCoordinates(float &x, float &y, uint32 zone);
    MapDifficulty const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty);
    MapDifficulty const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty);
    uint32 const* /*[MAX_TALENT_TABS]*/ GetTalentTabPages(uint8 cls);
    std::vector<uint32> const* GetTalentTreePrimarySpells(uint32 talentTree);
    static uint32 GetLiquidFlags(uint32 liquidType);
    static uint32 GetDefaultMapLight(uint32 mapId);
    PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
    PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);  
    CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender);
    CharSectionsEntry const* GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color);
    uint32 GetPowerIndexByClass(Powers power, uint32 classId);
    static bool IsInArea(uint32 objectAreaId, uint32 areaId);
    static LFGDungeonEntry const* GetLFGDungeon(uint32 mapId, Difficulty difficulty);
    std::vector<uint32> const* GetPhasesForGroup(uint32 group);
    std::vector<SkillLineAbilityEntry const*> const* GetSkillLineAbilitiesBySkill(uint32 skillId) const;
    SkillRaceClassInfoEntry const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_);
    ResponseCodes ValidateName(std::wstring const& name, LocaleConstant locale);
    EmotesTextSoundEntry const* FindTextSoundEmoteFor(uint32 emote, uint32 race, uint32 gender); 
};

#define sDBCManager DBCManager::Instance()

#endif
