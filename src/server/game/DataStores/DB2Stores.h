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

#ifndef TRINITY_DB2STORES_H
#define TRINITY_DB2STORES_H

#include "DB2Store.h"
#include "DB2Structure.h"
#include <string>

enum DB2Hash
{
    DB2_HASH_ITEM               = 0x50238EC2,
    DB2_HASH_ITEM_CURRENCY_COST = 0x6FE05AE9,
    DB2_HASH_ITEM_EXTENDED_COST = 0xBB858355,
    DB2_HASH_ITEM_SPARSE        = 0x919BE54E,
    DB2_HASH_KEYCHAIN           = 0x6D8A2694,
};

extern DB2Storage<ItemEntry> sItemStore;
extern DB2Storage<ItemCurrencyCostEntry> sItemCurrencyCostStore;
extern DB2Storage<ItemExtendedCostEntry> sItemExtendedCostStore;
extern DB2Storage<ItemSparseEntry> sItemSparseStore;
extern DB2Storage<KeyChainEntry> sKeyChainStore;

void LoadDB2Stores(std::string const& dataPath);

#endif