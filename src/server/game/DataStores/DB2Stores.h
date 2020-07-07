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

#ifndef TRINITY_DB2STORES_H
#define TRINITY_DB2STORES_H

#include "DB2Store.h"
#include "DB2Structure.h"

#include <map>
#include <string>

TC_GAME_API extern DB2Storage<ItemEntry>                sItemStore;
TC_GAME_API extern DB2Storage<ItemCurrencyCostEntry>    sItemCurrencyCostStore;
TC_GAME_API extern DB2Storage<ItemExtendedCostEntry>    sItemExtendedCostStore;
TC_GAME_API extern DB2Storage<ItemSparseEntry>          sItemSparseStore;
TC_GAME_API extern DB2Storage<KeyChainEntry>            sKeyChainStore;

struct HotfixNotify
{
    uint32 TableHash;
    uint32 Timestamp;
    uint32 Entry;
};

typedef std::vector<HotfixNotify> HotfixData;

class TC_GAME_API DB2Manager
{
public:
    typedef std::map<uint32 /*hash*/, DB2StorageBase*> StorageMap;

    static DB2Manager& Instance();

    uint32 LoadStores(std::string const& dataPath, uint32 defaultLocale);
    DB2StorageBase const* GetStorage(uint32 type) const;

    void LoadHotfixData();
    HotfixData const* GetHotfixData() const { return &_hotfixData; }

private:
    StorageMap _stores;
    HotfixData _hotfixData;
};

#define sDB2Manager DB2Manager::Instance()

#endif
