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

#ifndef _ITEM_ENCHANTMENT_MGR_H
#define _ITEM_ENCHANTMENT_MGR_H

#include "Common.h"
#include <unordered_map>
#include <vector>

struct ItemRandomProperties
{
    ItemRandomProperties(int32 randomPropertiesId = 0, int32 randomPropertiesSeed = 0) : RandomPropertiesID(randomPropertiesId), RandomPropertiesSeed(randomPropertiesSeed) { }

    int32 RandomPropertiesID = 0;
    int32 RandomPropertiesSeed = 0;
};

struct RandomEnchantmentData
{
    std::vector<uint16> EnchantmentIDs;
    std::vector<double> Chances;
};

class TC_GAME_API ItemEnchantmentMgr
{
public:
    static ItemEnchantmentMgr* instance();

    void LoadRandomEnchantmentsTable();
    ItemRandomProperties GenerateRandomProperties(uint32 itemId);

private:
    std::unordered_map<uint32, RandomEnchantmentData> _storage;
};

#define sItemEnchantmentMgr ItemEnchantmentMgr::instance()

#endif
