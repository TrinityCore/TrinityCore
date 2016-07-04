/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "SharedDefines.h"
#include <boost/regex.hpp>
#include <array>

TC_GAME_API extern DB2Storage<AchievementEntry>                     sAchievementStore;
TC_GAME_API extern DB2Storage<AuctionHouseEntry>                    sAuctionHouseStore;
TC_GAME_API extern DB2Storage<BarberShopStyleEntry>                 sBarberShopStyleStore;
TC_GAME_API extern DB2Storage<BattlePetBreedQualityEntry>           sBattlePetBreedQualityStore;
TC_GAME_API extern DB2Storage<BattlePetBreedStateEntry>             sBattlePetBreedStateStore;
TC_GAME_API extern DB2Storage<BattlePetSpeciesEntry>                sBattlePetSpeciesStore;
TC_GAME_API extern DB2Storage<BattlePetSpeciesStateEntry>           sBattlePetSpeciesStateStore;
TC_GAME_API extern DB2Storage<BroadcastTextEntry>                   sBroadcastTextStore;
TC_GAME_API extern DB2Storage<CharStartOutfitEntry>                 sCharStartOutfitStore;
TC_GAME_API extern DB2Storage<CinematicSequencesEntry>              sCinematicSequencesStore;
TC_GAME_API extern DB2Storage<CreatureDisplayInfoEntry>             sCreatureDisplayInfoStore;
TC_GAME_API extern DB2Storage<CreatureTypeEntry>                    sCreatureTypeStore;
TC_GAME_API extern DB2Storage<CriteriaEntry>                        sCriteriaStore;
TC_GAME_API extern DB2Storage<CriteriaTreeEntry>                    sCriteriaTreeStore;
TC_GAME_API extern DB2Storage<CurrencyTypesEntry>                   sCurrencyTypesStore;
TC_GAME_API extern DB2Storage<DestructibleModelDataEntry>           sDestructibleModelDataStore;
TC_GAME_API extern DB2Storage<DurabilityQualityEntry>               sDurabilityQualityStore;
TC_GAME_API extern DB2Storage<GameObjectsEntry>                     sGameObjectsStore;
TC_GAME_API extern DB2Storage<GameTablesEntry>                      sGameTablesStore;
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
TC_GAME_API extern DB2Storage<GlyphSlotEntry>                       sGlyphSlotStore;
TC_GAME_API extern DB2Storage<GuildPerkSpellsEntry>                 sGuildPerkSpellsStore;
TC_GAME_API extern DB2Storage<HeirloomEntry>                        sHeirloomStore;
TC_GAME_API extern DB2Storage<HolidaysEntry>                        sHolidaysStore;
TC_GAME_API extern DB2Storage<ImportPriceArmorEntry>                sImportPriceArmorStore;
TC_GAME_API extern DB2Storage<ImportPriceQualityEntry>              sImportPriceQualityStore;
TC_GAME_API extern DB2Storage<ImportPriceShieldEntry>               sImportPriceShieldStore;
TC_GAME_API extern DB2Storage<ImportPriceWeaponEntry>               sImportPriceWeaponStore;
TC_GAME_API extern DB2Storage<ItemClassEntry>                       sItemClassStore;
TC_GAME_API extern DB2Storage<ItemCurrencyCostEntry>                sItemCurrencyCostStore;
TC_GAME_API extern DB2Storage<ItemDisenchantLootEntry>              sItemDisenchantLootStore;
TC_GAME_API extern DB2Storage<ItemEffectEntry>                      sItemEffectStore;
TC_GAME_API extern DB2Storage<ItemEntry>                            sItemStore;
TC_GAME_API extern DB2Storage<ItemExtendedCostEntry>                sItemExtendedCostStore;
TC_GAME_API extern DB2Storage<ItemLimitCategoryEntry>               sItemLimitCategoryStore;
TC_GAME_API extern DB2Storage<ItemPriceBaseEntry>                   sItemPriceBaseStore;
TC_GAME_API extern DB2Storage<ItemRandomPropertiesEntry>            sItemRandomPropertiesStore;
TC_GAME_API extern DB2Storage<ItemRandomSuffixEntry>                sItemRandomSuffixStore;
TC_GAME_API extern DB2Storage<ItemSparseEntry>                      sItemSparseStore;
TC_GAME_API extern DB2Storage<ItemSpecEntry>                        sItemSpecStore;
TC_GAME_API extern DB2Storage<ItemSpecOverrideEntry>                sItemSpecOverrideStore;
TC_GAME_API extern DB2Storage<ItemToBattlePetSpeciesEntry>          sItemToBattlePetSpeciesStore;
TC_GAME_API extern DB2Storage<ItemUpgradeEntry>                     sItemUpgradeStore;
TC_GAME_API extern DB2Storage<MailTemplateEntry>                    sMailTemplateStore;
TC_GAME_API extern DB2Storage<ModifierTreeEntry>                    sModifierTreeStore;
TC_GAME_API extern DB2Storage<MountCapabilityEntry>                 sMountCapabilityStore;
TC_GAME_API extern DB2Storage<OverrideSpellDataEntry>               sOverrideSpellDataStore;
TC_GAME_API extern DB2Storage<PlayerConditionEntry>                 sPlayerConditionStore;
TC_GAME_API extern DB2Storage<QuestMoneyRewardEntry>                sQuestMoneyRewardStore;
TC_GAME_API extern DB2Storage<QuestSortEntry>                       sQuestSortStore;
TC_GAME_API extern DB2Storage<QuestXPEntry>                         sQuestXPStore;
TC_GAME_API extern DB2Storage<ScalingStatDistributionEntry>         sScalingStatDistributionStore;
TC_GAME_API extern DB2Storage<SoundEntriesEntry>                    sSoundEntriesStore;
TC_GAME_API extern DB2Storage<SpellAuraRestrictionsEntry>           sSpellAuraRestrictionsStore;
TC_GAME_API extern DB2Storage<SpellCastTimesEntry>                  sSpellCastTimesStore;
TC_GAME_API extern DB2Storage<SpellCastingRequirementsEntry>        sSpellCastingRequirementsStore;
TC_GAME_API extern DB2Storage<SpellClassOptionsEntry>               sSpellClassOptionsStore;
TC_GAME_API extern DB2Storage<SpellDurationEntry>                   sSpellDurationStore;
TC_GAME_API extern DB2Storage<SpellItemEnchantmentConditionEntry>   sSpellItemEnchantmentConditionStore;
TC_GAME_API extern DB2Storage<SpellLearnSpellEntry>                 sSpellLearnSpellStore;
TC_GAME_API extern DB2Storage<SpellMiscEntry>                       sSpellMiscStore;
TC_GAME_API extern DB2Storage<SpellPowerEntry>                      sSpellPowerStore;
TC_GAME_API extern DB2Storage<SpellProcsPerMinuteEntry>             sSpellProcsPerMinuteStore;
TC_GAME_API extern DB2Storage<SpellRadiusEntry>                     sSpellRadiusStore;
TC_GAME_API extern DB2Storage<SpellRangeEntry>                      sSpellRangeStore;
TC_GAME_API extern DB2Storage<SpellReagentsEntry>                   sSpellReagentsStore;
TC_GAME_API extern DB2Storage<SpellRuneCostEntry>                   sSpellRuneCostStore;
TC_GAME_API extern DB2Storage<SpellTotemsEntry>                     sSpellTotemsStore;
TC_GAME_API extern DB2Storage<SpellXSpellVisualEntry>               sSpellXSpellVisualStore;
TC_GAME_API extern DB2Storage<TaxiNodesEntry>                       sTaxiNodesStore;
TC_GAME_API extern DB2Storage<TaxiPathEntry>                        sTaxiPathStore;
TC_GAME_API extern DB2Storage<TotemCategoryEntry>                   sTotemCategoryStore;
TC_GAME_API extern DB2Storage<ToyEntry>                             sToyStore;
TC_GAME_API extern DB2Storage<UnitPowerBarEntry>                    sUnitPowerBarStore;
TC_GAME_API extern DB2Storage<WorldMapOverlayEntry>                 sWorldMapOverlayStore;

TC_GAME_API extern TaxiMask                                         sTaxiNodesMask;
TC_GAME_API extern TaxiMask                                         sOldContinentsNodesMask;
TC_GAME_API extern TaxiMask                                         sHordeTaxiNodesMask;
TC_GAME_API extern TaxiMask                                         sAllianceTaxiNodesMask;
TC_GAME_API extern TaxiPathSetBySource                              sTaxiPathSetBySource;
TC_GAME_API extern TaxiPathNodesByPath                              sTaxiPathNodesByPath;

struct HotfixNotify
{
    uint32 TableHash;
    uint32 Timestamp;
    uint32 Entry;
};

typedef std::vector<HotfixNotify> HotfixData;

#define DEFINE_DB2_SET_COMPARATOR(structure) \
    struct structure ## Comparator : public std::binary_function<structure const*, structure const*, bool> \
    { \
        bool operator()(structure const* left, structure const* right) const { return Compare(left, right); } \
        static bool Compare(structure const* left, structure const* right); \
    };

class TC_GAME_API DB2Manager
{
public:
    DEFINE_DB2_SET_COMPARATOR(ChrClassesXPowerTypesEntry);
    DEFINE_DB2_SET_COMPARATOR(GlyphSlotEntry);
    DEFINE_DB2_SET_COMPARATOR(MountTypeXCapabilityEntry);

    typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
    typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
    typedef std::unordered_map<uint32, CharStartOutfitEntry const*> CharStartOutfitContainer;
    typedef std::set<GlyphSlotEntry const*, GlyphSlotEntryComparator> GlyphSlotContainer;
    typedef std::map<uint32 /*curveID*/, std::map<uint32/*index*/, CurvePointEntry const*, std::greater<uint32>>> HeirloomCurvesContainer;
    typedef std::unordered_map<uint32, HeirloomEntry const*> HeirloomItemsContainer;
    typedef std::vector<ItemBonusEntry const*> ItemBonusList;
    typedef std::unordered_map<uint32 /*bonusListId*/, ItemBonusList> ItemBonusListContainer;
    typedef std::unordered_multimap<uint32 /*itemId*/, uint32 /*bonusTreeId*/> ItemToBonusTreeContainer;
    typedef std::unordered_map<uint32 /*itemId | appearanceMod << 24*/, uint32> ItemDisplayIdContainer;
    typedef std::unordered_map<uint32, std::set<ItemBonusTreeNodeEntry const*>> ItemBonusTreeContainer;
    typedef std::unordered_map<uint32, std::vector<ItemSpecOverrideEntry const*>> ItemSpecOverridesContainer;
    typedef std::unordered_map<uint32, MountEntry const*> MountContainer;
    typedef std::set<MountTypeXCapabilityEntry const*, MountTypeXCapabilityEntryComparator> MountTypeXCapabilitySet;
    typedef std::unordered_map<uint32, MountTypeXCapabilitySet> MountCapabilitiesByTypeContainer;
    typedef std::unordered_map<uint32, std::array<std::vector<NameGenEntry const*>, 2>> NameGenContainer;
    typedef std::array<std::vector<boost::regex>, TOTAL_LOCALES + 1> NameValidationRegexContainer;
    typedef std::unordered_map<uint32, std::set<uint32>> PhaseGroupContainer;
    typedef std::unordered_map<uint32, std::vector<QuestPackageItemEntry const*>> QuestPackageItemContainer;
    typedef std::unordered_map<uint32, uint32> RulesetItemUpgradeContainer;
    typedef std::unordered_map<uint32, std::vector<SpecializationSpellsEntry const*>> SpecializationSpellsContainer;
    typedef std::unordered_map<uint32, std::vector<SpellPowerEntry const*>> SpellPowerContainer;
    typedef std::unordered_map<uint32, std::unordered_map<uint32, std::vector<SpellPowerEntry const*>>> SpellPowerDifficultyContainer;
    typedef std::unordered_map<uint32, std::vector<SpellProcsPerMinuteModEntry const*>> SpellProcsPerMinuteModContainer;
    typedef std::unordered_set<uint32> ToyItemIdsContainer;

    static DB2Manager& Instance();

    void LoadStores(std::string const& dataPath, uint32 defaultLocale);
    DB2StorageBase const* GetStorage(uint32 type) const;

    void LoadHotfixData();
    HotfixData const* GetHotfixData() const { return &_hotfixData; }
    time_t GetHotfixDate(uint32 entry, uint32 type) const;

    std::vector<uint32> GetAreasForGroup(uint32 areaGroupId) const;
    static char const* GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale = DEFAULT_LOCALE, uint8 gender = GENDER_MALE, bool forceGender = false);
    CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender) const;
    uint32 GetPowerIndexByClass(uint32 powerType, uint32 classId) const;
    GlyphSlotContainer const& GetGlyphSlots() const { return _glyphSlots; }
    uint32 GetHeirloomItemLevel(uint32 curveId, uint32 level) const;
    HeirloomEntry const* GetHeirloomByItemId(uint32 itemId) const;
    ItemBonusList const* GetItemBonusList(uint32 bonusListId) const;
    std::set<uint32> GetItemBonusTree(uint32 itemId, uint32 itemBonusTreeMod) const;
    uint32 GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const;
    std::vector<ItemSpecOverrideEntry const*> const* GetItemSpecOverrides(uint32 itemId) const;
    std::string GetNameGenEntry(uint8 race, uint8 gender, LocaleConstant locale) const;
    MountEntry const* GetMount(uint32 spellId) const;
    MountEntry const* GetMountById(uint32 id) const;
    MountTypeXCapabilitySet const* GetMountCapabilities(uint32 mountType) const;
    ResponseCodes ValidateName(std::string const& name, LocaleConstant locale) const;
    std::vector<QuestPackageItemEntry const*> const* GetQuestPackageItems(uint32 questPackageID) const;
    uint32 GetQuestUniqueBitFlag(uint32 questId);
    std::set<uint32> GetPhasesForGroup(uint32 group) const;
    uint32 GetRulesetItemUpgrade(uint32 itemId) const;
    std::vector<SpecializationSpellsEntry const*> const* GetSpecializationSpells(uint32 specId) const;
    std::vector<SpellPowerEntry const*> GetSpellPowers(uint32 spellId, Difficulty difficulty = DIFFICULTY_NONE, bool* hasDifficultyPowers = nullptr) const;
    std::vector<SpellProcsPerMinuteModEntry const*> GetSpellProcsPerMinuteMods(uint32 spellprocsPerMinuteId) const;
    bool IsToyItem(uint32 toy) const;

private:
    StorageMap _stores;
    HotfixData _hotfixData;

    AreaGroupMemberContainer _areaGroupMembers;
    CharStartOutfitContainer _charStartOutfits;
    uint32 _powersByClass[MAX_CLASSES][MAX_POWERS];
    GlyphSlotContainer _glyphSlots;
    HeirloomItemsContainer _heirlooms;
    HeirloomCurvesContainer _heirloomCurvePoints;
    ItemBonusListContainer _itemBonusLists;
    ItemBonusTreeContainer _itemBonusTrees;
    ItemDisplayIdContainer _itemDisplayIDs;
    ItemToBonusTreeContainer _itemToBonusTree;
    ItemSpecOverridesContainer _itemSpecOverrides;
    MountContainer _mountsBySpellId;
    MountCapabilitiesByTypeContainer _mountCapabilitiesByType;
    NameGenContainer _nameGenData;
    NameValidationRegexContainer _nameValidators;
    PhaseGroupContainer _phasesByGroup;
    RulesetItemUpgradeContainer _rulesetItemUpgrade;
    QuestPackageItemContainer _questPackages;
    SpecializationSpellsContainer _specializationSpellsBySpec;
    SpellPowerContainer _spellPowers;
    SpellPowerDifficultyContainer _spellPowerDifficulties;
    SpellProcsPerMinuteModContainer _spellProcsPerMinuteMods;
    ToyItemIdsContainer _toys;
};

#define sDB2Manager DB2Manager::Instance()

#endif
