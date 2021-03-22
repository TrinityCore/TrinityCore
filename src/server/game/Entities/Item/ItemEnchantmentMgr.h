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

using ItemRandomBonusListId = uint32;

TC_GAME_API void LoadItemRandomBonusListTemplates();
TC_GAME_API ItemRandomBonusListId GenerateItemRandomBonusListId(uint32 item_id);
TC_GAME_API uint32 GetRandomPropertyPoints(uint32 itemLevel, uint32 quality, uint32 inventoryType, uint32 subclass);

#endif
