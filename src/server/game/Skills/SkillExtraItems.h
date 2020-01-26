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

#ifndef TRINITY_SKILL_EXTRA_ITEMS_H
#define TRINITY_SKILL_EXTRA_ITEMS_H

#include "Common.h"

// predef classes used in functions
class Player;

// returns true and sets the appropriate info if the player can create a perfect item with the given spellId
TC_GAME_API bool CanCreatePerfectItem(Player* player, uint32 spellId, float &perfectCreateChance, uint32 &perfectItemType);
// load perfection proc info from DB
TC_GAME_API void LoadSkillPerfectItemTable();
// returns true and sets the appropriate info if the player can create extra items with the given spellId
TC_GAME_API bool CanCreateExtraItems(Player* player, uint32 spellId, float &additionalChance, uint8 &additionalMax);
// function to load the extra item creation info from DB
TC_GAME_API void LoadSkillExtraItemTable();

#endif
