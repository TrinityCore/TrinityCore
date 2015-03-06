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

extern DB2Storage<BroadcastTextEntry>            sBroadcastTextStore;
extern DB2Storage<HolidaysEntry>                 sHolidaysStore;
extern DB2Storage<CurrencyTypesEntry>            sCurrencyTypesStore;
extern DB2Storage<ItemCurrencyCostEntry>         sItemCurrencyCostStore;
extern DB2Storage<ItemEffectEntry>               sItemEffectStore;
extern DB2Storage<ItemEntry>                     sItemStore;
extern DB2Storage<ItemExtendedCostEntry>         sItemExtendedCostStore;
extern DB2Storage<ItemSparseEntry>               sItemSparseStore;
extern DB2Storage<OverrideSpellDataEntry>        sOverrideSpellDataStore;
extern DB2Storage<SoundEntriesEntry>             sSoundEntriesStore;
extern DB2Storage<SpellAuraRestrictionsEntry>    sSpellAuraRestrictionsStore;
extern DB2Storage<SpellCastingRequirementsEntry> sSpellCastingRequirementsStore;
extern DB2Storage<SpellClassOptionsEntry>        sSpellClassOptionsStore;
extern DB2Storage<SpellLearnSpellEntry>          sSpellLearnSpellStore;
extern DB2Storage<SpellMiscEntry>                sSpellMiscStore;
extern DB2Storage<SpellPowerEntry>               sSpellPowerStore;
extern DB2Storage<SpellReagentsEntry>            sSpellReagentsStore;
extern DB2Storage<SpellRuneCostEntry>            sSpellRuneCostStore;
extern DB2Storage<SpellTotemsEntry>              sSpellTotemsStore;
extern DB2Storage<TaxiNodesEntry>                sTaxiNodesStore;
extern DB2Storage<TaxiPathEntry>                 sTaxiPathStore;

extern SpellPowerBySpellIDMap                    sSpellPowerBySpellIDStore;
extern TaxiMask                                  sTaxiNodesMask;
extern TaxiMask                                  sOldContinentsNodesMask;
extern TaxiMask                                  sHordeTaxiNodesMask;
extern TaxiMask                                  sAllianceTaxiNodesMask;
extern TaxiMask                                  sDeathKnightTaxiNodesMask;
extern TaxiPathSetBySource                       sTaxiPathSetBySource;
extern TaxiPathNodesByPath                       sTaxiPathNodesByPath;

struct HotfixNotify
{
    uint32 TableHash;
    uint32 Timestamp;
    uint32 Entry;
};

typedef std::vector<HotfixNotify> HotfixData;

class DB2Manager
{
public:
    typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;
    typedef std::unordered_map<uint32 /*areaGroupId*/, std::vector<uint32/*areaId*/>> AreaGroupMemberContainer;
    typedef std::map<uint32 /*curveID*/, std::map<uint32/*index*/, CurvePointEntry const*, std::greater<uint32>>> HeirloomCurvesContainer;
    typedef std::vector<ItemBonusEntry const*> ItemBonusList;
    typedef std::unordered_map<uint32 /*bonusListId*/, ItemBonusList> ItemBonusListContainer;
    typedef std::unordered_multimap<uint32 /*itemId*/, uint32 /*bonusTreeId*/> ItemToBonusTreeContainer;
    typedef std::unordered_map<uint32 /*itemId | appearanceMod << 24*/, uint32> ItemDisplayIdContainer;
    typedef std::unordered_map<uint32, std::set<ItemBonusTreeNodeEntry const*>> ItemBonusTreeContainer;
    typedef std::unordered_map<uint32, MountEntry const*> MountContainer;
    typedef std::unordered_map<uint32, std::set<uint32>> PhaseGroupContainer;

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
    uint32 GetHeirloomItemLevel(uint32 curveId, uint32 level) const;
    ItemBonusList GetItemBonusList(uint32 bonusListId) const;
    std::set<uint32> GetItemBonusTree(uint32 itemId, uint32 itemBonusTreeMod) const;
    uint32 GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const;
    MountEntry const* GetMount(uint32 spellId) const;
    std::set<uint32> GetPhasesForGroup(uint32 group) const;

private:
    StorageMap _stores;
    HotfixData _hotfixData;

    AreaGroupMemberContainer _areaGroupMembers;
    HeirloomCurvesContainer _heirloomCurvePoints;
    ItemBonusListContainer _itemBonusLists;
    ItemBonusTreeContainer _itemBonusTrees;
    ItemDisplayIdContainer _itemDisplayIDs;
    ItemToBonusTreeContainer _itemToBonusTree;
    MountContainer _mountsBySpellId;
    PhaseGroupContainer _phasesByGroup;
};

#define sDB2Manager DB2Manager::Instance()

#endif
