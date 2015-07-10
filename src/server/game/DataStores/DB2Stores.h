/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include <array>

extern DB2Storage<AuctionHouseEntry>                    sAuctionHouseStore;
extern DB2Storage<BarberShopStyleEntry>                 sBarberShopStyleStore;
extern DB2Storage<BroadcastTextEntry>                   sBroadcastTextStore;
extern DB2Storage<CharStartOutfitEntry>                 sCharStartOutfitStore;
extern DB2Storage<CinematicSequencesEntry>              sCinematicSequencesStore;
extern DB2Storage<CreatureDisplayInfoEntry>             sCreatureDisplayInfoStore;
extern DB2Storage<CreatureTypeEntry>                    sCreatureTypeStore;
extern DB2Storage<CurrencyTypesEntry>                   sCurrencyTypesStore;
extern DB2Storage<DestructibleModelDataEntry>           sDestructibleModelDataStore;
extern DB2Storage<DurabilityQualityEntry>               sDurabilityQualityStore;
extern DB2Storage<GameObjectsEntry>                     sGameObjectsStore;
extern DB2Storage<GameTablesEntry>                      sGameTablesStore;
extern DB2Storage<GarrAbilityEntry>                     sGarrAbilityStore;
extern DB2Storage<GarrBuildingEntry>                    sGarrBuildingStore;
extern DB2Storage<GarrBuildingPlotInstEntry>            sGarrBuildingPlotInstStore;
extern DB2Storage<GarrClassSpecEntry>                   sGarrClassSpecStore;
extern DB2Storage<GarrFollowerEntry>                    sGarrFollowerStore;
extern DB2Storage<GarrFollowerXAbilityEntry>            sGarrFollowerXAbilityStore;
extern DB2Storage<GarrPlotBuildingEntry>                sGarrPlotBuildingStore;
extern DB2Storage<GarrPlotEntry>                        sGarrPlotStore;
extern DB2Storage<GarrPlotInstanceEntry>                sGarrPlotInstanceStore;
extern DB2Storage<GarrSiteLevelEntry>                   sGarrSiteLevelStore;
extern DB2Storage<GarrSiteLevelPlotInstEntry>           sGarrSiteLevelPlotInstStore;
extern DB2Storage<GlyphSlotEntry>                       sGlyphSlotStore;
extern DB2Storage<GuildPerkSpellsEntry>                 sGuildPerkSpellsStore;
extern DB2Storage<HolidaysEntry>                        sHolidaysStore;
extern DB2Storage<ImportPriceArmorEntry>                sImportPriceArmorStore;
extern DB2Storage<ImportPriceQualityEntry>              sImportPriceQualityStore;
extern DB2Storage<ImportPriceShieldEntry>               sImportPriceShieldStore;
extern DB2Storage<ImportPriceWeaponEntry>               sImportPriceWeaponStore;
extern DB2Storage<ItemClassEntry>                       sItemClassStore;
extern DB2Storage<ItemCurrencyCostEntry>                sItemCurrencyCostStore;
extern DB2Storage<ItemDisenchantLootEntry>              sItemDisenchantLootStore;
extern DB2Storage<ItemEffectEntry>                      sItemEffectStore;
extern DB2Storage<ItemEntry>                            sItemStore;
extern DB2Storage<ItemExtendedCostEntry>                sItemExtendedCostStore;
extern DB2Storage<ItemLimitCategoryEntry>               sItemLimitCategoryStore;
extern DB2Storage<ItemPriceBaseEntry>                   sItemPriceBaseStore;
extern DB2Storage<ItemRandomPropertiesEntry>            sItemRandomPropertiesStore;
extern DB2Storage<ItemRandomSuffixEntry>                sItemRandomSuffixStore;
extern DB2Storage<ItemSparseEntry>                      sItemSparseStore;
extern DB2Storage<ItemSpecEntry>                        sItemSpecStore;
extern DB2Storage<ItemSpecOverrideEntry>                sItemSpecOverrideStore;
extern DB2Storage<MailTemplateEntry>                    sMailTemplateStore;
extern DB2Storage<MountCapabilityEntry>                 sMountCapabilityStore;
extern DB2Storage<OverrideSpellDataEntry>               sOverrideSpellDataStore;
extern DB2Storage<QuestMoneyRewardEntry>                sQuestMoneyRewardStore;
extern DB2Storage<QuestSortEntry>                       sQuestSortStore;
extern DB2Storage<QuestXPEntry>                         sQuestXPStore;
extern DB2Storage<ScalingStatDistributionEntry>         sScalingStatDistributionStore;
extern DB2Storage<SoundEntriesEntry>                    sSoundEntriesStore;
extern DB2Storage<SpellAuraRestrictionsEntry>           sSpellAuraRestrictionsStore;
extern DB2Storage<SpellCastTimesEntry>                  sSpellCastTimesStore;
extern DB2Storage<SpellCastingRequirementsEntry>        sSpellCastingRequirementsStore;
extern DB2Storage<SpellClassOptionsEntry>               sSpellClassOptionsStore;
extern DB2Storage<SpellDurationEntry>                   sSpellDurationStore;
extern DB2Storage<SpellItemEnchantmentConditionEntry>   sSpellItemEnchantmentConditionStore;
extern DB2Storage<SpellLearnSpellEntry>                 sSpellLearnSpellStore;
extern DB2Storage<SpellMiscEntry>                       sSpellMiscStore;
extern DB2Storage<SpellPowerEntry>                      sSpellPowerStore;
extern DB2Storage<SpellRadiusEntry>                     sSpellRadiusStore;
extern DB2Storage<SpellRangeEntry>                      sSpellRangeStore;
extern DB2Storage<SpellReagentsEntry>                   sSpellReagentsStore;
extern DB2Storage<SpellRuneCostEntry>                   sSpellRuneCostStore;
extern DB2Storage<SpellTotemsEntry>                     sSpellTotemsStore;
extern DB2Storage<SpellXSpellVisualEntry>               sSpellXSpellVisualStore;
extern DB2Storage<TaxiNodesEntry>                       sTaxiNodesStore;
extern DB2Storage<TaxiPathEntry>                        sTaxiPathStore;
extern DB2Storage<TotemCategoryEntry>                   sTotemCategoryStore;
extern DB2Storage<UnitPowerBarEntry>                    sUnitPowerBarStore;
extern DB2Storage<WorldMapOverlayEntry>                 sWorldMapOverlayStore;

extern TaxiMask                                         sTaxiNodesMask;
extern TaxiMask                                         sOldContinentsNodesMask;
extern TaxiMask                                         sHordeTaxiNodesMask;
extern TaxiMask                                         sAllianceTaxiNodesMask;
extern TaxiMask                                         sDeathKnightTaxiNodesMask;
extern TaxiPathSetBySource                              sTaxiPathSetBySource;
extern TaxiPathNodesByPath                              sTaxiPathNodesByPath;

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
        bool operator()(structure const* left, structure const* right) const; \
    };

class DB2Manager
{
public:
    DEFINE_DB2_SET_COMPARATOR(GlyphSlotEntry);
    DEFINE_DB2_SET_COMPARATOR(MountTypeXCapabilityEntry);

    typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
    typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
    typedef std::unordered_map<uint32, CharStartOutfitEntry const*> CharStartOutfitContainer;
    typedef std::set<GlyphSlotEntry const*, GlyphSlotEntryComparator> GlyphSlotContainer;
    typedef std::map<uint32 /*curveID*/, std::map<uint32/*index*/, CurvePointEntry const*, std::greater<uint32>>> HeirloomCurvesContainer;
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
    typedef std::unordered_map<uint32, std::set<uint32>> PhaseGroupContainer;
    typedef std::unordered_map<uint32, std::vector<QuestPackageItemEntry const*>> QuestPackageItemContainer;
    typedef std::unordered_map<uint32, std::vector<SpecializationSpellsEntry const*>> SpecializationSpellsContainer;
    typedef std::unordered_map<uint32, std::vector<SpellPowerEntry const*>> SpellPowerContainer;
    typedef std::unordered_map<uint32, std::unordered_map<uint32, std::vector<SpellPowerEntry const*>>> SpellPowerDifficultyContainer;

    static DB2Manager& Instance()
    {
        static DB2Manager instance;
        return instance;
    }

    void LoadStores(std::string const& dataPath);
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
    ItemBonusList GetItemBonusList(uint32 bonusListId) const;
    std::set<uint32> GetItemBonusTree(uint32 itemId, uint32 itemBonusTreeMod) const;
    uint32 GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const;
    std::vector<ItemSpecOverrideEntry const*> const* GetItemSpecOverrides(uint32 itemId) const;
    std::string GetNameGenEntry(uint8 race, uint8 gender, LocaleConstant locale) const;
    MountEntry const* GetMount(uint32 spellId) const;
    MountEntry const* GetMountById(uint32 id) const;
    MountTypeXCapabilitySet const* GetMountCapabilities(uint32 mountType) const;
    std::vector<QuestPackageItemEntry const*> const* GetQuestPackageItems(uint32 questPackageID) const;
    uint32 GetQuestUniqueBitFlag(uint32 questId);
    std::set<uint32> GetPhasesForGroup(uint32 group) const;
    std::vector<SpecializationSpellsEntry const*> const* GetSpecializationSpells(uint32 specId) const;
    std::vector<SpellPowerEntry const*> GetSpellPowers(uint32 spellId, Difficulty difficulty = DIFFICULTY_NONE, bool* hasDifficultyPowers = nullptr) const;

private:
    StorageMap _stores;
    HotfixData _hotfixData;

    AreaGroupMemberContainer _areaGroupMembers;
    CharStartOutfitContainer _charStartOutfits;
    uint32 _powersByClass[MAX_CLASSES][MAX_POWERS];
    GlyphSlotContainer _glyphSlots;
    HeirloomCurvesContainer _heirloomCurvePoints;
    ItemBonusListContainer _itemBonusLists;
    ItemBonusTreeContainer _itemBonusTrees;
    ItemDisplayIdContainer _itemDisplayIDs;
    ItemToBonusTreeContainer _itemToBonusTree;
    ItemSpecOverridesContainer _itemSpecOverrides;
    MountContainer _mountsBySpellId;
    MountCapabilitiesByTypeContainer _mountCapabilitiesByType;
    NameGenContainer _nameGenData;
    PhaseGroupContainer _phasesByGroup;
    QuestPackageItemContainer _questPackages;
    SpecializationSpellsContainer _specializationSpellsBySpec;
    SpellPowerContainer _spellPowers;
    SpellPowerDifficultyContainer _spellPowerDifficulties;
};

#define sDB2Manager DB2Manager::Instance()

#endif
