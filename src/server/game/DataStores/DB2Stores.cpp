/*
 * Copyright (C) 2011 TrintiyCore <http://www.trinitycore.org/>
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

#include "DB2Stores.h"
#include "DBCStores.h"
#include "DB2fmt.h"
#include "Common.h"
#include "Log.h"
#include "World.h"
#include <functional>

DB2Storage<BroadcastTextEntry>              sBroadcastTextStore(BroadcastTextEntryfmt, HOTFIX_SEL_BROADCAST_TEXT);
DB2Storage<CurvePointEntry>                 sCurvePointStore(CurvePointEntryfmt);
DB2Storage<HolidaysEntry>                   sHolidaysStore(HolidaysEntryfmt);
DB2Storage<ItemEntry>                       sItemStore(Itemfmt);
DB2Storage<ItemAppearanceEntry>             sItemAppearanceStore(ItemAppearanceEntryfmt);
DB2Storage<ItemBonusEntry>                  sItemBonusStore(ItemBonusEntryfmt);
DB2Storage<ItemCurrencyCostEntry>           sItemCurrencyCostStore(ItemCurrencyCostfmt);
DB2Storage<ItemExtendedCostEntry>           sItemExtendedCostStore(ItemExtendedCostEntryfmt);
DB2Storage<ItemEffectEntry>                 sItemEffectStore(ItemEffectEntryfmt);
DB2Storage<ItemModifiedAppearanceEntry>     sItemModifiedAppearanceStore(ItemModifiedAppearanceEntryfmt);
DB2Storage<ItemSparseEntry>                 sItemSparseStore(ItemSparsefmt);
DB2Storage<KeyChainEntry>                   sKeyChainStore(KeyChainfmt);
DB2Storage<OverrideSpellDataEntry>          sOverrideSpellDataStore(OverrideSpellDataEntryfmt);
DB2Storage<PhaseGroupEntry>                 sPhaseGroupStore(PhaseGroupEntryfmt);
DB2Storage<SpellAuraRestrictionsEntry>      sSpellAuraRestrictionsStore(SpellAuraRestrictionsEntryfmt);
DB2Storage<SpellCastingRequirementsEntry>   sSpellCastingRequirementsStore(SpellCastingRequirementsEntryfmt);
DB2Storage<SpellClassOptionsEntry>          sSpellClassOptionsStore(SpellClassOptionsEntryfmt);
DB2Storage<SpellMiscEntry>                  sSpellMiscStore(SpellMiscEntryfmt);
DB2Storage<SpellPowerEntry>                 sSpellPowerStore(SpellPowerEntryfmt);
SpellPowerBySpellIDMap                      sSpellPowerBySpellIDStore;
DB2Storage<SpellReagentsEntry>              sSpellReagentsStore(SpellReagentsEntryfmt);
DB2Storage<SpellRuneCostEntry>              sSpellRuneCostStore(SpellRuneCostEntryfmt);
DB2Storage<SpellTotemsEntry>                sSpellTotemsStore(SpellTotemsEntryfmt);
DB2Storage<TaxiNodesEntry>                  sTaxiNodesStore(TaxiNodesEntryfmt);
DB2Storage<TaxiPathEntry>                   sTaxiPathStore(TaxiPathEntryfmt);
DB2Storage<TaxiPathNodeEntry>               sTaxiPathNodeStore(TaxiPathNodeEntryfmt, HOTFIX_SEL_TAXI_PATH_NODE);
TaxiMask                                    sTaxiNodesMask;
TaxiMask                                    sOldContinentsNodesMask;
TaxiMask                                    sHordeTaxiNodesMask;
TaxiMask                                    sAllianceTaxiNodesMask;
TaxiMask                                    sDeathKnightTaxiNodesMask;
TaxiPathSetBySource                         sTaxiPathSetBySource;
TaxiPathNodesByPath                         sTaxiPathNodesByPath;

typedef std::list<std::string> DB2StoreProblemList;

uint32 DB2FilesCount = 0;

template<class T>
inline void LoadDB2(uint32& availableDb2Locales, DB2StoreProblemList& errlist, DB2Manager::StorageMap& stores, DB2Storage<T>& storage, std::string const& db2_path, std::string const& filename)
{
    // compatibility format and C++ structure sizes
    ASSERT(DB2FileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (%u).",
        DB2FileLoader::GetFormatRecordSize(storage.GetFormat()), sizeof(T), filename.c_str());

    ++DB2FilesCount;

    std::string db2_filename = db2_path + filename;
    if (storage.Load(db2_filename.c_str(), uint32(sWorld->GetDefaultDbcLocale())))
    {
        storage.LoadSQLData();

        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (!(availableDb2Locales & (1 << i)))
                continue;

            if (uint32(sWorld->GetDefaultDbcLocale()) == i)
                continue;

            std::string localizedName(db2_path);
            localizedName.append(localeNames[i]);
            localizedName.push_back('/');
            localizedName.append(filename);

            if (!storage.LoadStringsFrom(localizedName.c_str(), i))
                availableDb2Locales &= ~(1<<i);             // mark as not available for speedup next checks
        }
    }
    else
    {
        // sort problematic db2 to (1) non compatible and (2) nonexistent
        if (FILE* f = fopen(db2_filename.c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << db2_filename << " exists, and has " << storage.GetFieldCount() << " field(s) (expected " << strlen(storage.GetFormat()) << "). Extracted file might be from wrong client version.";
            std::string buf = stream.str();
            errlist.push_back(buf);
            fclose(f);
        }
        else
            errlist.push_back(db2_filename);
    }

    stores[storage.GetHash()] = &storage;
}

void DB2Manager::LoadStores(std::string const& dataPath)
{
    std::string db2Path = dataPath + "dbc/";

    DB2StoreProblemList bad_db2_files;
    uint32 availableDb2Locales = 0xFF;

    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sBroadcastTextStore,        db2Path,    "BroadcastText.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sCurvePointStore,           db2Path,    "CurvePoint.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sHolidaysStore,             db2Path,    "Holidays.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemStore,                 db2Path,    "Item.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemAppearanceStore,       db2Path,    "ItemAppearance.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemBonusStore,            db2Path,    "ItemBonus.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemCurrencyCostStore,     db2Path,    "ItemCurrencyCost.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemExtendedCostStore,     db2Path,    "ItemExtendedCost.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemEffectStore,           db2Path,    "ItemEffect.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemModifiedAppearanceStore, db2Path,  "ItemModifiedAppearance.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sItemSparseStore,           db2Path,    "Item-sparse.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sKeyChainStore,             db2Path,    "KeyChain.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sOverrideSpellDataStore,    db2Path,    "OverrideSpellData.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sPhaseGroupStore,           db2Path,    "PhaseXPhaseGroup.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellAuraRestrictionsStore, db2Path,   "SpellAuraRestrictions.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellCastingRequirementsStore, db2Path, "SpellCastingRequirements.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellClassOptionsStore,    db2Path,    "SpellClassOptions.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellMiscStore,            db2Path,    "SpellMisc.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellPowerStore,           db2Path,    "SpellPower.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellReagentsStore,        db2Path,    "SpellReagents.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellRuneCostStore,        db2Path,    "SpellRuneCost.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sSpellTotemsStore,          db2Path,    "SpellTotems.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sTaxiNodesStore,            db2Path,    "TaxiNodes.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sTaxiPathStore,             db2Path,    "TaxiPath.db2");
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, sTaxiPathNodeStore,         db2Path,    "TaxiPathNode.db2");

    for (uint32 i = 0; i < sItemBonusStore.GetNumRows(); ++i)
        if (ItemBonusEntry const* bonus = sItemBonusStore.LookupEntry(i))
            _itemBonusLists[bonus->BonusListID].push_back(bonus);

    for (uint32 i = 0; i < sItemModifiedAppearanceStore.GetNumRows(); ++i)
        if (ItemModifiedAppearanceEntry const* appearanceMod = sItemModifiedAppearanceStore.LookupEntry(i))
            if (ItemAppearanceEntry const* appearance = sItemAppearanceStore.LookupEntry(appearanceMod->AppearanceID))
                _itemDisplayIDs[appearanceMod->ItemID | (appearanceMod->AppearanceModID << 24)] = appearance->DisplayID;

    {
        std::set<uint32> scalingCurves;
        for (uint32 i = 0; i < sScalingStatDistributionStore.GetNumRows(); ++i)
            if (ScalingStatDistributionEntry const* ssd = sScalingStatDistributionStore.LookupEntry(i))
                scalingCurves.insert(ssd->ItemLevelCurveID);

        for (uint32 i = 0; i < sCurvePointStore.GetNumRows(); ++i)
            if (CurvePointEntry const* curvePoint = sCurvePointStore.LookupEntry(i))
                if (scalingCurves.count(curvePoint->CurveID))
                    _heirloomCurvePoints[curvePoint->CurveID][curvePoint->Index] = curvePoint;
    }

    for (uint32 i = 0; i < sSpellPowerStore.GetNumRows(); ++i)
        if (SpellPowerEntry const* power = sSpellPowerStore.LookupEntry(i))
            sSpellPowerBySpellIDStore[power->SpellID] = power;

    for (uint32 i = 0; i < sPhaseGroupStore.GetNumRows(); ++i)
        if (PhaseGroupEntry const* group = sPhaseGroupStore.LookupEntry(i))
            if (PhaseEntry const* phase = sPhaseStore.LookupEntry(group->PhaseID))
                _phasesByGroup[group->PhaseGroupID].insert(phase->ID);

    for (uint32 i = 1; i < sTaxiPathStore.GetNumRows(); ++i)
        if (TaxiPathEntry const* entry = sTaxiPathStore.LookupEntry(i))
            sTaxiPathSetBySource[entry->From][entry->To] = TaxiPathBySourceAndDestination(entry->ID, entry->Cost);
    uint32 pathCount = sTaxiPathStore.GetNumRows();

    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount);                           // 0 and some other indexes not used
    for (uint32 i = 1; i < sTaxiPathNodeStore.GetNumRows(); ++i)
    {
        if (TaxiPathNodeEntry const* entry = sTaxiPathNodeStore.LookupEntry(i))
        {
            if (pathLength[entry->PathID] < entry->NodeIndex + 1)
                pathLength[entry->PathID] = entry->NodeIndex + 1;
        }
    }

    // Set path length
    sTaxiPathNodesByPath.resize(pathCount);                 // 0 and some other indexes not used
    for (uint32 i = 1; i < sTaxiPathNodesByPath.size(); ++i)
        sTaxiPathNodesByPath[i].resize(pathLength[i]);

    // fill data
    for (uint32 i = 1; i < sTaxiPathNodeStore.GetNumRows(); ++i)
        if (TaxiPathNodeEntry const* entry = sTaxiPathNodeStore.LookupEntry(i))
            sTaxiPathNodesByPath[entry->PathID].set(entry->NodeIndex, entry);

    // Initialize global taxinodes mask
    // include existed nodes that have at least single not spell base (scripted) path
    {
        std::set<uint32> spellPaths;
        for (uint32 i = 1; i < sSpellEffectStore.GetNumRows(); ++i)
            if (SpellEffectEntry const* sInfo = sSpellEffectStore.LookupEntry (i))
                if (sInfo->Effect == SPELL_EFFECT_SEND_TAXI)
                    spellPaths.insert(sInfo->EffectMiscValue);

        memset(sTaxiNodesMask, 0, sizeof(sTaxiNodesMask));
        memset(sOldContinentsNodesMask, 0, sizeof(sOldContinentsNodesMask));
        memset(sHordeTaxiNodesMask, 0, sizeof(sHordeTaxiNodesMask));
        memset(sAllianceTaxiNodesMask, 0, sizeof(sAllianceTaxiNodesMask));
        memset(sDeathKnightTaxiNodesMask, 0, sizeof(sDeathKnightTaxiNodesMask));
        for (uint32 i = 1; i < sTaxiNodesStore.GetNumRows(); ++i)
        {
            TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(i);
            if (!node)
                continue;

            TaxiPathSetBySource::const_iterator src_i = sTaxiPathSetBySource.find(i);
            if (src_i != sTaxiPathSetBySource.end() && !src_i->second.empty())
            {
                bool ok = false;
                for (TaxiPathSetForSource::const_iterator dest_i = src_i->second.begin(); dest_i != src_i->second.end(); ++dest_i)
                {
                    // not spell path
                    if (spellPaths.find(dest_i->second.ID) == spellPaths.end())
                    {
                        ok = true;
                        break;
                    }
                }

                if (!ok)
                    continue;
            }

            // valid taxi network node
            uint8  field   = (uint8)((i - 1) / 8);
            uint32 submask = 1 << ((i-1) % 8);

            sTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[0] && node->MountCreatureID[0] != 32981)
                sHordeTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[1] && node->MountCreatureID[1] != 32981)
                sAllianceTaxiNodesMask[field] |= submask;
            if (node->MountCreatureID[0] == 32981 || node->MountCreatureID[1] == 32981)
                sDeathKnightTaxiNodesMask[field] |= submask;

            // old continent node (+ nodes virtually at old continents, check explicitly to avoid loading map files for zone info)
            if (node->MapID < 2 || i == 82 || i == 83 || i == 93 || i == 94)
                sOldContinentsNodesMask[field] |= submask;

            // fix DK node at Ebon Hold and Shadow Vault flight master
            if (i == 315 || i == 333)
                ((TaxiNodesEntry*)node)->MountCreatureID[1] = 32981;
        }
    }

    // error checks
    if (bad_db2_files.size() >= DB2FilesCount)
    {
        TC_LOG_ERROR("misc", "\nIncorrect DataDir value in worldserver.conf or ALL required *.db2 files (%d) not found by path: %sdb2", DB2FilesCount, dataPath.c_str());
        exit(1);
    }
    else if (!bad_db2_files.empty())
    {
        std::string str;
        for (std::list<std::string>::iterator i = bad_db2_files.begin(); i != bad_db2_files.end(); ++i)
            str += *i + "\n";

        TC_LOG_ERROR("misc", "\nSome required *.db2 files (%u from %d) not found or not compatible:\n%s", (uint32)bad_db2_files.size(), DB2FilesCount, str.c_str());
        exit(1);
    }

    // Check loaded DB2 files proper version
    if (!sItemStore.LookupEntry(120406)             ||       // last item added in 6.0.3 (19342)
        !sItemExtendedCostStore.LookupEntry(5491)  )        // last item extended cost added in 6.0.3 (19342)
    {
        TC_LOG_ERROR("misc", "You have _outdated_ DB2 files. Please extract correct versions from current using client.");
        exit(1);
    }

    TC_LOG_INFO("misc", ">> Initialized %d DB2 data stores.", DB2FilesCount);
}

DB2StorageBase const* DB2Manager::GetStorage(uint32 type) const
{
    StorageMap::const_iterator itr = _stores.find(type);
    if (itr != _stores.end())
        return itr->second;

    return nullptr;
}

void DB2Manager::LoadHotfixData()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT TableHash, RecordID, `Timestamp` FROM hotfix_data");

    if (!result)
    {
        TC_LOG_INFO("misc", ">> Loaded 0 hotfix info entries.");
        return;
    }

    uint32 count = 0;

    _hotfixData.reserve(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        HotfixNotify info;
        info.TableHash = fields[0].GetUInt32();
        info.Entry = fields[1].GetUInt32();
        info.Timestamp = fields[2].GetUInt32();
        _hotfixData.push_back(info);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("misc", ">> Loaded %u hotfix info entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

time_t DB2Manager::GetHotfixDate(uint32 entry, uint32 type) const
{
    time_t ret = 0;
    for (HotfixNotify const& hotfix : _hotfixData)
        if (hotfix.Entry == entry && hotfix.TableHash == type)
            if (time_t(hotfix.Timestamp) > ret)
                ret = time_t(hotfix.Timestamp);

    return ret ? ret : time(NULL);
}

char const* DB2Manager::GetBroadcastTextValue(BroadcastTextEntry const* broadcastText, LocaleConstant locale /*= DEFAULT_LOCALE*/, uint8 gender /*= GENDER_MALE*/, bool forceGender /*= false*/)
{
    if (gender == GENDER_FEMALE && (forceGender || broadcastText->FemaleText->Str[DEFAULT_LOCALE][0] != '\0'))
    {
        if (broadcastText->FemaleText->Str[locale][0] != '\0')
            return broadcastText->FemaleText->Str[locale];

        return broadcastText->FemaleText->Str[DEFAULT_LOCALE];
    }

    if (broadcastText->MaleText->Str[locale][0] != '\0')
        return broadcastText->MaleText->Str[locale];

    return broadcastText->MaleText->Str[DEFAULT_LOCALE];
}

uint32 DB2Manager::GetHeirloomItemLevel(uint32 curveId, uint32 level) const
{
    // Assuming linear item level scaling for heirlooms
    auto itr = _heirloomCurvePoints.find(curveId);
    if (itr == _heirloomCurvePoints.end())
        return 0;

    auto it2 = itr->second.begin(); // Highest scaling point
    if (level >= it2->second->X)
        return it2->second->Y;

    auto previousItr = it2++;
    for (; it2 != itr->second.end(); ++it2, ++previousItr)
        if (level >= it2->second->X)
            return uint32((previousItr->second->Y - it2->second->Y) / (previousItr->second->X - it2->second->X) * (float(level) - it2->second->X) + it2->second->Y);

    return uint32(previousItr->second->Y);  // Lowest scaling point
}

uint32 DB2Manager::GetItemDisplayId(uint32 itemId, uint32 appearanceModId) const
{
    auto itr = _itemDisplayIDs.find(itemId | (appearanceModId << 24));
    if (itr != _itemDisplayIDs.end())
        return itr->second;

    // Fall back to unmodified appearance
    if (appearanceModId)
    {
        itr = _itemDisplayIDs.find(itemId);
        if (itr != _itemDisplayIDs.end())
            return itr->second;
    }

    return 0;
}

DB2Manager::ItemBonusList DB2Manager::GetItemBonusList(uint32 bonusListId) const
{
    auto itr = _itemBonusLists.find(bonusListId);
    if (itr != _itemBonusLists.end())
        return itr->second;

    return ItemBonusList();
}

std::set<uint32> DB2Manager::GetPhasesForGroup(uint32 group) const
{
    auto itr = _phasesByGroup.find(group);
    if (itr != _phasesByGroup.end())
        return itr->second;

    return std::set<uint32>();
}
