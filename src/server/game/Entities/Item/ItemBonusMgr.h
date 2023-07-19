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

#ifndef TRINITY_ITEM_BONUS_MGR_H
#define TRINITY_ITEM_BONUS_MGR_H

#include "Define.h"
#include "Optional.h"
#include <span>
#include <vector>

class Player;
struct ItemBonusEntry;
struct MapDifficultyEntry;
enum class ItemContext : uint8;

namespace ItemBonusMgr
{
TC_GAME_API void Load();

TC_GAME_API ItemContext GetContextForPlayer(MapDifficultyEntry const* mapDifficulty, Player const* player);

TC_GAME_API std::span<ItemBonusEntry const*> GetItemBonuses(uint32 bonusListId);

TC_GAME_API uint32 GetItemBonusListForItemLevelDelta(int16 delta);

struct ItemBonusGenerationParams
{
    /*implicit*/ ItemBonusGenerationParams(ItemContext context, Optional<int32> mythicPlusKeystoneLevel = {}, Optional<int32> pvpTier = {})
        : Context(context), MythicPlusKeystoneLevel(mythicPlusKeystoneLevel), PvpTier(pvpTier) { }

    ItemContext Context;
    Optional<int32> MythicPlusKeystoneLevel;
    Optional<int32> PvpTier;
};

TC_GAME_API std::vector<int32> GetBonusListsForItem(uint32 itemId, ItemBonusGenerationParams const& params);
TC_GAME_API std::vector<int32> GetAllBonusListsForTree(uint32 itemBonusTreeId);
}

#endif // TRINITY_ITEM_BONUS_MGR_H
