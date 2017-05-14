/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_DB2STORES_H
#define TRINITY_DB2STORES_H

#include "DB2Store.h"
#include "DB2Structure.h"
#include "Hash.h"
#include "SharedDefines.h"
#include "Regex.h"
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

 // temporary hack until includes are sorted out (don't want to pull in Windows.h)
#ifdef GetClassName
#undef GetClassName
#endif

TC_GAME_API extern DB2Storage<AchievementEntry>                     sAchievementStore;
TC_GAME_API extern DB2Storage<AnimKitEntry>                         sAnimKitStore;
TC_GAME_API extern DB2Storage<AreaTableEntry>                       sAreaTableStore;
TC_GAME_API extern DB2Storage<AreaTriggerEntry>                     sAreaTriggerStore;
TC_GAME_API extern DB2Storage<ArmorLocationEntry>                   sArmorLocationStore;
TC_GAME_API extern DB2Storage<ArtifactEntry>                        sArtifactStore;
TC_GAME_API extern DB2Storage<ArtifactCategoryEntry>                sArtifactCategoryStore;
TC_GAME_API extern DB2Storage<ArtifactAppearanceEntry>              sArtifactAppearanceStore;
TC_GAME_API extern DB2Storage<ArtifactAppearanceSetEntry>           sArtifactAppearanceSetStore;
TC_GAME_API extern DB2Storage<ArtifactPowerEntry>                   sArtifactPowerStore;
TC_GAME_API extern DB2Storage<ArtifactPowerPickerEntry>             sArtifactPowerPickerStore;
TC_GAME_API extern DB2Storage<AuctionHouseEntry>                    sAuctionHouseStore;
TC_GAME_API extern DB2Storage<BankBagSlotPricesEntry>               sBankBagSlotPricesStore;
TC_GAME_API extern DB2Storage<BannedAddOnsEntry>                    sBannedAddOnsStore;
TC_GAME_API extern DB2Storage<BarberShopStyleEntry>                 sBarberShopStyleStore;
TC_GAME_API extern DB2Storage<BattlePetBreedQualityEntry>           sBattlePetBreedQualityStore;
TC_GAME_API extern DB2Storage<BattlePetBreedStateEntry>             sBattlePetBreedStateStore;
TC_GAME_API extern DB2Storage<BattlePetSpeciesEntry>                sBattlePetSpeciesStore;
TC_GAME_API extern DB2Storage<BattlePetSpeciesStateEntry>           sBattlePetSpeciesStateStore;
TC_GAME_API extern DB2Storage<BattlemasterListEntry>                sBattlemasterListStore;
TC_GAME_API extern DB2Storage<BroadcastTextEntry>                   sBroadcastTextStore;
TC_GAME_API extern DB2Storage<CharStartOutfitEntry>                 sCharStartOutfitStore;
TC_GAME_API extern DB2Storage<CharTitlesEntry>                      sCharTitlesStore;
TC_GAME_API extern DB2Storage<ChatChannelsEntry>                    sChatChannelsStore;
TC_GAME_API extern DB2Storage<ChrClassesEntry>                      sChrClassesStore;
TC_GAME_API extern DB2Storage<ChrRacesEntry>                        sChrRacesStore;
TC_GAME_API extern DB2Storage<ChrSpecializationEntry>               sChrSpecializationStore;
TC_GAME_API extern DB2Storage<CinematicCameraEntry>                 sCinematicCameraStore;
TC_GAME_API extern DB2Storage<CinematicSequencesEntry>              sCinematicSequencesStore;
TC_GAME_API extern DB2Storage<ConversationLineEntry>                sConversationLineStore;
TC_GAME_API extern DB2Storage<CreatureDisplayInfoEntry>             sCreatureDisplayInfoStore;
TC_GAME_API extern DB2Storage<CreatureDisplayInfoExtraEntry>        sCreatureDisplayInfoExtraStore;
TC_GAME_API extern DB2Storage<CreatureFamilyEntry>                  sCreatureFamilyStore;
TC_GAME_API extern DB2Storage<CreatureModelDataEntry>               sCreatureModelDataStore;
TC_GAME_API extern DB2Storage<CreatureTypeEntry>                    sCreatureTypeStore;
TC_GAME_API extern DB2Storage<CriteriaEntry>                        sCriteriaStore;
TC_GAME_API extern DB2Storage<CriteriaTreeEntry>                    sCriteriaTreeStore;
TC_GAME_API extern DB2Storage<CurrencyTypesEntry>                   sCurrencyTypesStore;
TC_GAME_API extern DB2Storage<CurveEntry>                           sCurveStore;
TC_GAME_API extern DB2Storage<DestructibleModelDataEntry>           sDestructibleModelDataStore;
TC_GAME_API extern DB2Storage<DifficultyEntry>                      sDifficultyStore;
TC_GAME_API extern DB2Storage<DungeonEncounterEntry>                sDungeonEncounterStore;
TC_GAME_API extern DB2Storage<DurabilityCostsEntry>                 sDurabilityCostsStore;
TC_GAME_API extern DB2Storage<DurabilityQualityEntry>               sDurabilityQualityStore;
TC_GAME_API extern DB2Storage<EmotesEntry>                          sEmotesStore;
TC_GAME_API extern DB2Storage<EmotesTextEntry>                      sEmotesTextStore;
TC_GAME_API extern DB2Storage<FactionEntry>                         sFactionStore;
TC_GAME_API extern DB2Storage<FactionTemplateEntry>                 sFactionTemplateStore;
TC_GAME_API extern DB2Storage<GameObjectsEntry>                     sGameObjectsStore;
TC_GAME_API extern DB2Storage<GameObjectDisplayInfoEntry>           sGameObjectDisplayInfoStore;
TC_GAME_API extern DB2Storage<GarrAbilityEntry>                     sGarrAbilityStore;
TC_GAME_API extern DB2Storage<GarrBuildingEntry>                    sGarrBuildingStore;
TC_GAME_API extern DB2Storage<GarrBuildingPlotInstEntry>            sGarrBuildingPlotInstStore;
TC_GAME_API extern DB2Storage<GarrClassSpecEntry>                   sGarrClassSpecStore;
TC_GAME_API extern DB2Storage<GarrFollowerEntry>                    sGarrFollowerStore;
TC_GAME_API extern DB2Storage<GarrFollowerXAbilityEntry>            sGarrFollowerXAbilityStore;
TC_GAME_API extern DB2Storage<GarrPlotBuildingEntry>                sGarrPlotBuildingStore;
TC_GAME_API extern DB2Storage<GarrPlotEntry>                        sGarrPlotStore;
TC_GAME_API extern DB2Storage<GarrPlotInstanceEntry>                sGarrPlotInstanceStore;
TC_GAME_API extern DB2Storage<GarrSiteLevelEntry>                   sGarrSiteLevelStore;
TC_GAME_API extern DB2Storage<GarrSiteLevelPlotInstEntry>           sGarrSiteLevelPlotInstStore;
TC_GAME_API extern DB2Storage<GemPropertiesEntry>                   sGemPropertiesStore;
TC_GAME_API extern DB2Storage<GlyphPropertiesEntry>                 sGlyphPropertiesStore;
TC_GAME_API extern DB2Storage<GuildColorBackgroundEntry>            sGuildColorBackgroundStore;
TC_GAME_API extern DB2Storage<GuildColorBorderEntry>                sGuildColorBorderStore;
TC_GAME_API extern DB2Storage<GuildColorEmblemEntry>                sGuildColorEmblemStore;
TC_GAME_API extern DB2Storage<GuildPerkSpellsEntry>                 sGuildPerkSpellsStore;
TC_GAME_API extern DB2Storage<HolidaysEntry>                        sHolidaysStore;
TC_GAME_API extern DB2Storage<ImportPriceArmorEntry>                sImportPriceArmorStore;
TC_GAME_API extern DB2Storage<ImportPriceQualityEntry>              sImportPriceQualityStore;
TC_GAME_API extern DB2Storage<ImportPriceShieldEntry>               sImportPriceShieldStore;
TC_GAME_API extern DB2Storage<ImportPriceWeaponEntry>               sImportPriceWeaponStore;
TC_GAME_API extern DB2Storage<ItemAppearanceEntry>                  sItemAppearanceStore;
TC_GAME_API extern DB2Storage<ItemArmorQualityEntry>                sItemArmorQualityStore;
TC_GAME_API extern DB2Storage<ItemArmorShieldEntry>                 sItemArmorShieldStore;
TC_GAME_API extern DB2Storage<ItemArmorTotalEntry>                  sItemArmorTotalStore;
TC_GAME_API extern DB2Storage<ItemBagFamilyEntry>                   sItemBagFamilyStore;
TC_GAME_API extern DB2Storage<ItemDamageAmmoEntry>                  sItemDamageAmmoStore;
TC_GAME_API extern DB2Storage<ItemDamageOneHandEntry>               sItemDamageOneHandStore;
TC_GAME_API extern DB2Storage<ItemDamageOneHandCasterEntry>         sItemDamageOneHandCasterStore;
TC_GAME_API extern DB2Storage<ItemDamageTwoHandEntry>               sItemDamageTwoHandStore;
TC_GAME_API extern DB2Storage<ItemDamageTwoHandCasterEntry>         sItemDamageTwoHandCasterStore;
TC_GAME_API extern DB2Storage<ItemDisenchantLootEntry>              sItemDisenchantLootStore;
TC_GAME_API extern DB2Storage<ItemEffectEntry>                      sItemEffectStore;
TC_GAME_API extern DB2Storage<ItemEntry>                            sItemStore;
TC_GAME_API extern DB2Storage<ItemExtendedCostEntry>                sItemExtendedCostStore;
TC_GAME_API extern DB2Storage<ItemLimitCategoryEntry>               sItemLimitCategoryStore;
TC_GAME_API extern DB2Storage<ItemModifiedAppearanceEntry>          sItemModifiedAppearanceStore;
TC_GAME_API extern DB2Storage<ItemPriceBaseEntry>                   sItemPriceBaseStore;
TC_GAME_API extern DB2Storage<ItemRandomPropertiesEntry>            sItemRandomPropertiesStore;
TC_GAME_API extern DB2Storage<ItemRandomSuffixEntry>                sItemRandomSuffixStore;
TC_GAME_API extern DB2Storage<ItemSearchNameEntry>                  sItemSearchNameStore;
TC_GAME_API extern DB2Storage<ItemSetEntry>                         sItemSetStore;
TC_GAME_API extern DB2Storage<ItemSetSpellEntry>                    sItemSetSpellStore;
TC_GAME_API extern DB2Storage<ItemSparseEntry>                      sItemSparseStore;
TC_GAME_API extern DB2Storage<ItemSpecEntry>                        sItemSpecStore;
TC_GAME_API extern DB2Storage<ItemSpecOverrideEntry>                sItemSpecOverrideStore;
TC_GAME_API extern DB2Storage<ItemUpgradeEntry>                     sItemUpgradeStore;
TC_GAME_API extern DB2Storage<LfgDungeonsEntry>                     sLfgDungeonsStore;
TC_GAME_API extern DB2Storage<LiquidTypeEntry>                      sLiquidTypeStore;
TC_GAME_API extern DB2Storage<LockEntry>                            sLockStore;
TC_GAME_API extern DB2Storage<MailTemplateEntry>                    sMailTemplateStore;
TC_GAME_API extern DB2Storage<MapEntry>                             sMapStore;
TC_GAME_API extern DB2Storage<ModifierTreeEntry>                    sModifierTreeStore;
TC_GAME_API extern DB2Storage<MountCapabilityEntry>                 sMountCapabilityStore;
TC_GAME_API extern DB2Storage<MountEntry>                           sMountStore;
TC_GAME_API extern DB2Storage<MovieEntry>                           sMovieStore;
TC_GAME_API extern DB2Storage<OverrideSpellDataEntry>               sOverrideSpellDataStore;
TC_GAME_API extern DB2Storage<PhaseEntry>                           sPhaseStore;
TC_GAME_API extern DB2Storage<PlayerConditionEntry>                 sPlayerConditionStore;
TC_GAME_API extern DB2Storage<PowerDisplayEntry>                    sPowerDisplayStore;
TC_GAME_API extern DB2Storage<QuestFactionRewardEntry>              sQuestFactionRewardStore;
TC_GAME_API extern DB2Storage<QuestMoneyRewardEntry>                sQuestMoneyRewardStore;
TC_GAME_API extern DB2Storage<QuestSortEntry>                       sQuestSortStore;
TC_GAME_API extern DB2Storage<QuestXPEntry>                         sQuestXPStore;
TC_GAME_API extern DB2Storage<RandPropPointsEntry>                  sRandPropPointsStore;
TC_GAME_API extern DB2Storage<ScalingStatDistributionEntry>         sScalingStatDistributionStore;
TC_GAME_API extern DB2Storage<ScenarioEntry>                        sScenarioStore;
TC_GAME_API extern DB2Storage<ScenarioStepEntry>                    sScenarioStepStore;
TC_GAME_API extern DB2Storage<SkillLineEntry>                       sSkillLineStore;
TC_GAME_API extern DB2Storage<SceneScriptEntry>                     sSceneScriptStore;
TC_GAME_API extern DB2Storage<SceneScriptPackageEntry>              sSceneScriptPackageStore;
TC_GAME_API extern DB2Storage<SkillLineAbilityEntry>                sSkillLineAbilityStore;
TC_GAME_API extern DB2Storage<SkillRaceClassInfoEntry>              sSkillRaceClassInfoStore;
TC_GAME_API extern DB2Storage<SoundKitEntry>                        sSoundKitStore;
TC_GAME_API extern DB2Storage<SpellEntry>                           sSpellStore;
TC_GAME_API extern DB2Storage<SpellAuraOptionsEntry>                sSpellAuraOptionsStore;
TC_GAME_API extern DB2Storage<SpellAuraRestrictionsEntry>           sSpellAuraRestrictionsStore;
TC_GAME_API extern DB2Storage<SpellCastTimesEntry>                  sSpellCastTimesStore;
TC_GAME_API extern DB2Storage<SpellCastingRequirementsEntry>        sSpellCastingRequirementsStore;
TC_GAME_API extern DB2Storage<SpellCategoriesEntry>                 sSpellCategoriesStore;
TC_GAME_API extern DB2Storage<SpellCategoryEntry>                   sSpellCategoryStore;
TC_GAME_API extern DB2Storage<SpellClassOptionsEntry>               sSpellClassOptionsStore;
TC_GAME_API extern DB2Storage<SpellCooldownsEntry>                  sSpellCooldownsStore;
TC_GAME_API extern DB2Storage<SpellDurationEntry>                   sSpellDurationStore;
TC_GAME_API extern DB2Storage<SpellEffectEntry>                     sSpellEffectStore;
TC_GAME_API extern DB2Storage<SpellEffectScalingEntry>              sSpellEffectScalingStore;
TC_GAME_API extern DB2Storage<SpellEquippedItemsEntry>              sSpellEquippedItemsStore;
TC_GAME_API extern DB2Storage<SpellFocusObjectEntry>                sSpellFocusObjectStore;
TC_GAME_API extern DB2Storage<SpellInterruptsEntry>                 sSpellInterruptsStore;
TC_GAME_API extern DB2Storage<SpellItemEnchantmentEntry>            sSpellItemEnchantmentStore;
TC_GAME_API extern DB2Storage<SpellItemEnchantmentConditionEntry>   sSpellItemEnchantmentConditionStore;
TC_GAME_API extern DB2Storage<SpellLearnSpellEntry>                 sSpellLearnSpellStore;
TC_GAME_API extern DB2Storage<SpellLevelsEntry>                     sSpellLevelsStore;
TC_GAME_API extern DB2Storage<SpellMiscEntry>                       sSpellMiscStore;
TC_GAME_API extern DB2Storage<SpellPowerEntry>                      sSpellPowerStore;
TC_GAME_API extern DB2Storage<SpellProcsPerMinuteEntry>             sSpellProcsPerMinuteStore;
TC_GAME_API extern DB2Storage<SpellRadiusEntry>                     sSpellRadiusStore;
TC_GAME_API extern DB2Storage<SpellRangeEntry>                      sSpellRangeStore;
TC_GAME_API extern DB2Storage<SpellReagentsEntry>                   sSpellReagentsStore;
TC_GAME_API extern DB2Storage<SpellScalingEntry>                    sSpellScalingStore;
TC_GAME_API extern DB2Storage<SpellShapeshiftEntry>                 sSpellShapeshiftStore;
TC_GAME_API extern DB2Storage<SpellShapeshiftFormEntry>             sSpellShapeshiftFormStore;
TC_GAME_API extern DB2Storage<SpellTargetRestrictionsEntry>         sSpellTargetRestrictionsStore;
TC_GAME_API extern DB2Storage<SpellTotemsEntry>                     sSpellTotemsStore;
TC_GAME_API extern DB2Storage<SpellXSpellVisualEntry>               sSpellXSpellVisualStore;
TC_GAME_API extern DB2Storage<SummonPropertiesEntry>                sSummonPropertiesStore;
TC_GAME_API extern DB2Storage<TalentEntry>                          sTalentStore;
TC_GAME_API extern DB2Storage<TaxiNodesEntry>                       sTaxiNodesStore;
TC_GAME_API extern DB2Storage<TaxiPathEntry>                        sTaxiPathStore;
TC_GAME_API extern DB2Storage<UnitPowerBarEntry>                    sUnitPowerBarStore;
TC_GAME_API extern DB2Storage<VehicleEntry>                         sVehicleStore;
TC_GAME_API extern DB2Storage<VehicleSeatEntry>                     sVehicleSeatStore;
TC_GAME_API extern DB2Storage<WorldMapOverlayEntry>                 sWorldMapOverlayStore;
TC_GAME_API extern DB2Storage<WorldSafeLocsEntry>                   sWorldSafeLocsStore;

struct TaxiPathBySourceAndDestination
{
    TaxiPathBySourceAndDestination() : ID(0), price(0) { }
    TaxiPathBySourceAndDestination(uint32 _id, uint32 _price) : ID(_id), price(_price) { }

    uint32 ID;
    uint32 price;
};

typedef std::map<uint32, TaxiPathBySourceAndDestination> TaxiPathSetForSource;
typedef std::map<uint32, TaxiPathSetForSource> TaxiPathSetBySource;

typedef std::vector<TaxiPathNodeEntry const*> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

TC_GAME_API extern TaxiMask                                         sTaxiNodesMask;
TC_GAME_API extern TaxiMask                                         sOldContinentsNodesMask;
TC_GAME_API extern TaxiMask                                         sHordeTaxiNodesMask;
TC_GAME_API extern TaxiMask                                         sAllianceTaxiNodesMask;
TC_GAME_API extern TaxiPathSetBySource                              sTaxiPathSetBySource;
TC_GAME_API extern TaxiPathNodesByPath                              sTaxiPathNodesByPath;

struct HotfixRecord
{
    HotfixRecord(uint32 tableHash, int32 recordId) : TableHash(tableHash), RecordId(recordId) { }

    uint32 TableHash;
    int32 RecordId;
};

struct HotfixData
{
    int32 Id;
    std::vector<HotfixRecord> Records;
};

#define DEFINE_DB2_SET_COMPARATOR(structure) \
    struct structure ## Comparator \
    { \
        bool operator()(structure const* left, structure const* right) const { return Compare(left, right); } \
        static bool Compare(structure const* left, structure const* right); \
    };

class TC_GAME_API DB2Manager
{
public:
    DEFINE_DB2_SET_COMPARATOR(ChrClassesXPowerTypesEntry)
    DEFINE_DB2_SET_COMPARATOR(MountTypeXCapabilityEntry)

    typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
    typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
    typedef std::unordered_map<uint32, std::vector<ArtifactPowerEntry const*>> ArtifactPowersContainer;
    typedef std::unordered_map<uint32, std::unordered_set<uint32>> ArtifactPowerLinksContainer;
    typedef std::unordered_map<std::pair<uint32, uint8>, ArtifactPowerRankEntry const*> ArtifactPowerRanksContainer;
    typedef std::unordered_multimap<uint32, CharSectionsEntry const*> CharSectionsContainer;
    typedef std::unordered_map<uint32, CharStartOutfitEntry const*> CharStartOutfitContainer;
    typedef ChrSpecializationEntry const* ChrSpecializationByIndexContainer[MAX_CLASSES + 1][MAX_SPECIALIZATIONS];
    typedef std::unordered_map<uint32, ChrSpecializationEntry const*> ChrSpecialzationByClassContainer;
    typedef std::unordered_map<uint32 /*curveID*/, std::vector<CurvePointEntry const*>> CurvePointsContainer;
    typedef std::map<std::tuple<uint32, uint8, uint8, uint8>, EmotesTextSoundEntry const*> EmotesTextSoundContainer;
    typedef std::unordered_map<uint32, std::vector<uint32>> FactionTeamContainer;
    typedef std::unordered_map<uint32, HeirloomEntry const*> HeirloomItemsContainer;
    typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphBindableSpellsContainer;
    typedef std::unordered_map<uint32 /*glyphPropertiesId*/, std::vector<uint32>> GlyphRequiredSpecsContainer;
    typedef std::vector<ItemBonusEntry const*> ItemBonusList;
    typedef std::unordered_map<uint32 /*bonusListId*/, ItemBonusList> ItemBonusListContainer;
    typedef std::unordered_map<int16, uint32> ItemBonusListLevelDeltaContainer;
    typedef std::unordered_multimap<uint32 /*itemId*/, uint32 /*bonusTreeId*/> ItemToBonusTreeContainer;
    typedef std::unordered_map<uint32 /*itemId*/, ItemChildEquipmentEntry const*> ItemChildEquipmentContainer;
    typedef std::array<ItemClassEntry const*, 19> ItemClassByOldEnumContainer;
    typedef std::unordered_map<uint32 /*itemId | appearanceMod << 24*/, ItemModifiedAppearanceEntry const*> ItemModifiedAppearanceByItemContainer;
    typedef std::unordered_map<uint32, std::set<ItemBonusTreeNodeEntry const*>> ItemBonusTreeContainer;
    typedef std::unordered_map<uint32, std::vector<ItemSetSpellEntry const*>> ItemSetSpellContainer;
    typedef std::unordered_map<uint32, std::vector<ItemSpecOverrideEntry const*>> ItemSpecOverridesContainer;
    typedef std::unordered_map<uint32, std::unordered_map<uint32, MapDifficultyEntry const*>> MapDifficultyContainer;
    typedef std::unordered_map<uint32, MountEntry const*> MountContainer;
    typedef std::set<MountTypeXCapabilityEntry const*, MountTypeXCapabilityEntryComparator> MountTypeXCapabilitySet;
    typedef std::unordered_map<uint32, MountTypeXCapabilitySet> MountCapabilitiesByTypeContainer;
    typedef std::vector<MountXDisplayEntry const*> MountXDisplayContainer;
    typedef std::unordered_map<uint32, MountXDisplayContainer> MountDisplaysCointainer;
    typedef std::unordered_map<uint32, std::array<std::vector<NameGenEntry const*>, 2>> NameGenContainer;
    typedef std::array<std::vector<Trinity::wregex>, TOTAL_LOCALES + 1> NameValidationRegexContainer;
    typedef std::unordered_map<uint32, std::set<uint32>> PhaseGroupContainer;
    typedef std::array<PowerTypeEntry const*, MAX_POWERS> PowerTypesContainer;
    typedef std::unordered_map<uint32, std::pair<std::vector<QuestPackageItemEntry const*>, std::vector<QuestPackageItemEntry const*>>> QuestPackageItemContainer;
    typedef std::unordered_map<uint32, uint32> RulesetItemUpgradeContainer;
    typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoContainer;
    typedef std::unordered_map<uint32, std::vector<SpecializationSpellsEntry const*>> SpecializationSpellsContainer;
    typedef std::unordered_map<uint32, std::vector<SpellPowerEntry const*>> SpellPowerContainer;
    typedef std::unordered_map<uint32, std::unordered_map<uint32, std::vector<SpellPowerEntry const*>>> SpellPowerDifficultyContainer;
    typedef std::unordered_map<uint32, std::vector<SpellProcsPerMinuteModEntry const*>> SpellProcsPerMinuteModContainer;
    typedef std::vector<TalentEntry const*> TalentsByPosition[MAX_CLASSES][MAX_TALENT_TIERS][MAX_TALENT_COLUMNS];
    typedef std::unordered_set<uint32> ToyItemIdsContainer;
    typedef std::tuple<int16, int8, int32> WMOAreaTableKey;
    typedef std::map<WMOAreaTableKey, WMOAreaTableEntry const*> WMOAreaTableLookupContainer;
    typedef std::unordered_map<uint32, WorldMapAreaEntry const*> WorldMapAreaByAreaIDContainer;

    static DB2Manager& Instance();

    void LoadStores(std::string const& dataPath, uint32 defaultLocale);
    DB2StorageBase const* GetStorage(uint32 type) const;

    void LoadHotfixData();
    std::map<int32, HotfixData> const& GetHotfixData() const { return _hotfixData; }

    std::vector<uint32> GetAreasForGroup(uint32 areaGroupId) const;
    std::vector<ArtifactPowerEntry const*> GetArtifactPowers(uint8 artifactId) const;
    std::unordered_set<uint32> const* GetArtifactPowerLinks(uint32 artifactPowerId) const;
    ArtifactPowerRankEntry const* GetArtifactPowerRank(uint32 artifactPowerId, uint8 rank) const;
    static char const* GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale = DEFAULT_LOCALE, uint8 gender = GENDER_MALE, bool forceGender = false);
    CharSectionsEntry const* GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color) const;
    CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender) const;
    static char const* GetClassName(uint8 class_, LocaleConstant locale = DEFAULT_LOCALE);
    uint32 GetPowerIndexByClass(uint32 powerType, uint32 classId) const;
    static char const* GetChrRaceName(uint8 race, LocaleConstant locale = DEFAULT_LOCALE);
    ChrSpecializationEntry const* GetChrSpecializationByIndex(uint32 class_, uint32 index) const;
    ChrSpecializationEntry const* GetDefaultChrSpecializationForClass(uint32 class_) const;
    static char const* GetCreatureFamilyPetName(uint32 petfamily, uint32 locale);
    float GetCurveValueAt(uint32 curveId, float x) const;
    EmotesTextSoundEntry const* GetTextSoundEmoteFor(uint32 emote, uint8 race, uint8 gender, uint8 class_) const;
    std::vector<uint32> const* GetFactionTeamList(uint32 faction) const;
    HeirloomEntry const* GetHeirloomByItemId(uint32 itemId) const;
    std::vector<uint32> const* GetGlyphBindableSpells(uint32 glyphPropertiesId) const;
    std::vector<uint32> const* GetGlyphRequiredSpecs(uint32 glyphPropertiesId) const;
    ItemBonusList const* GetItemBonusList(uint32 bonusListId) const;
    uint32 GetItemBonusListForItemLevelDelta(int16 delta) const;
    std::set<uint32> GetItemBonusTree(uint32 itemId, uint32 itemBonusTreeMod) const;
    ItemChildEquipmentEntry const* GetItemChildEquipment(uint32 itemId) const;
    ItemClassEntry const* GetItemClassByOldEnum(uint32 itemClass) const;
    bool HasItemCurrencyCost(uint32 itemId) const { return _itemsWithCurrencyCost.count(itemId) > 0; }
    uint32 GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const;
    ItemModifiedAppearanceEntry const* GetItemModifiedAppearance(uint32 itemId, uint32 appearanceModId) const;
    ItemModifiedAppearanceEntry const* GetDefaultItemModifiedAppearance(uint32 itemId) const;
    std::vector<ItemSetSpellEntry const*> const* GetItemSetSpells(uint32 itemSetId) const;
    std::vector<ItemSpecOverrideEntry const*> const* GetItemSpecOverrides(uint32 itemId) const;
    static LfgDungeonsEntry const* GetLfgDungeon(uint32 mapId, Difficulty difficulty);
    static uint32 GetDefaultMapLight(uint32 mapId);
    static uint32 GetLiquidFlags(uint32 liquidType);
    MapDifficultyContainer const& GetMapDifficulties() const { return _mapDifficulties; }
    MapDifficultyEntry const* GetDefaultMapDifficulty(uint32 mapId, Difficulty* difficulty = nullptr) const;
    MapDifficultyEntry const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty) const;
    MapDifficultyEntry const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty) const;
    std::string GetNameGenEntry(uint8 race, uint8 gender, LocaleConstant locale) const;
    MountEntry const* GetMount(uint32 spellId) const;
    MountEntry const* GetMountById(uint32 id) const;
    MountTypeXCapabilitySet const* GetMountCapabilities(uint32 mountType) const;
    MountXDisplayContainer const* GetMountDisplays(uint32 mountId) const;
    ResponseCodes ValidateName(std::wstring const& name, LocaleConstant locale) const;
    std::set<uint32> GetPhasesForGroup(uint32 group) const;
    PowerTypeEntry const* GetPowerTypeEntry(Powers power) const;
    static PvpDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
    static PvpDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);
    std::vector<QuestPackageItemEntry const*> const* GetQuestPackageItems(uint32 questPackageID) const;
    std::vector<QuestPackageItemEntry const*> const* GetQuestPackageItemsFallback(uint32 questPackageID) const;
    uint32 GetQuestUniqueBitFlag(uint32 questId);
    uint32 GetRulesetItemUpgrade(uint32 itemId) const;
    SkillRaceClassInfoEntry const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_);
    std::vector<SpecializationSpellsEntry const*> const* GetSpecializationSpells(uint32 specId) const;
    std::vector<SpellPowerEntry const*> GetSpellPowers(uint32 spellId, Difficulty difficulty = DIFFICULTY_NONE, bool* hasDifficultyPowers = nullptr) const;
    std::vector<SpellProcsPerMinuteModEntry const*> GetSpellProcsPerMinuteMods(uint32 spellprocsPerMinuteId) const;
    std::vector<TalentEntry const*> const& GetTalentsByPosition(uint32 class_, uint32 tier, uint32 column) const;
    static bool IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId);
    bool IsToyItem(uint32 toy) const;
    WMOAreaTableEntry const* GetWMOAreaTable(int32 rootId, int32 adtId, int32 groupId) const;
    uint32 GetVirtualMapForMapAndZone(uint32 mapId, uint32 zoneId) const;
    void Zone2MapCoordinates(uint32 areaId, float& x, float& y) const;
    void Map2ZoneCoordinates(uint32 areaId, float& x, float& y) const;
    static void DeterminaAlternateMapPosition(uint32 mapId, float x, float y, float z, uint32* newMapId = nullptr, DBCPosition2D* newPos = nullptr);

private:
    StorageMap _stores;
    std::map<int32, HotfixData> _hotfixData;

    AreaGroupMemberContainer _areaGroupMembers;
    ArtifactPowersContainer _artifactPowers;
    ArtifactPowerLinksContainer _artifactPowerLinks;
    ArtifactPowerRanksContainer _artifactPowerRanks;
    CharSectionsContainer _charSections;
    CharStartOutfitContainer _charStartOutfits;
    uint32 _powersByClass[MAX_CLASSES][MAX_POWERS];
    ChrSpecializationByIndexContainer _chrSpecializationsByIndex;
    ChrSpecialzationByClassContainer _defaultChrSpecializationsByClass;
    CurvePointsContainer _curvePoints;
    EmotesTextSoundContainer _emoteTextSounds;
    FactionTeamContainer _factionTeams;
    HeirloomItemsContainer _heirlooms;
    GlyphBindableSpellsContainer _glyphBindableSpells;
    GlyphRequiredSpecsContainer _glyphRequiredSpecs;
    ItemBonusListContainer _itemBonusLists;
    ItemBonusListLevelDeltaContainer _itemLevelDeltaToBonusListContainer;
    ItemBonusTreeContainer _itemBonusTrees;
    ItemChildEquipmentContainer _itemChildEquipment;
    ItemClassByOldEnumContainer _itemClassByOldEnum;
    std::unordered_set<uint32> _itemsWithCurrencyCost;
    ItemModifiedAppearanceByItemContainer _itemModifiedAppearancesByItem;
    ItemToBonusTreeContainer _itemToBonusTree;
    ItemSetSpellContainer _itemSetSpells;
    ItemSpecOverridesContainer _itemSpecOverrides;
    MapDifficultyContainer _mapDifficulties;
    MountContainer _mountsBySpellId;
    MountCapabilitiesByTypeContainer _mountCapabilitiesByType;
    MountDisplaysCointainer _mountDisplays;
    NameGenContainer _nameGenData;
    NameValidationRegexContainer _nameValidators;
    PhaseGroupContainer _phasesByGroup;
    PowerTypesContainer _powerTypes;
    QuestPackageItemContainer _questPackages;
    RulesetItemUpgradeContainer _rulesetItemUpgrade;
    SkillRaceClassInfoContainer _skillRaceClassInfoBySkill;
    SpecializationSpellsContainer _specializationSpellsBySpec;
    SpellPowerContainer _spellPowers;
    SpellPowerDifficultyContainer _spellPowerDifficulties;
    SpellProcsPerMinuteModContainer _spellProcsPerMinuteMods;
    TalentsByPosition _talentsByPosition;
    ToyItemIdsContainer _toys;
    WMOAreaTableLookupContainer _wmoAreaTableLookup;
    WorldMapAreaByAreaIDContainer _worldMapAreaByAreaID;
};

#define sDB2Manager DB2Manager::Instance()

#endif
