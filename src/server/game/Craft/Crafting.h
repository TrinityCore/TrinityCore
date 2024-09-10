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

#include "Define.h"

#ifndef CRAFTING_H
#define CRAFTING_H

class Item;
class Player;
class Spell;
struct CraftingDataEntry;

class TC_GAME_API Crafting
{
public:
    Crafting(Player* player, Spell* spell) :
        _player(player), _spell(spell), _craftingData(nullptr) { }

    SpellCastResult DoCraft(uint32 craftingDataId);

private:
    uint32 GetSkillLevelForCraft();
    uint32 GetSkillIdForSpell(uint32 spellId);
    uint32 CalculateTotalReagentWeights();
    void InitCraftingStatModifier(Item* item);
    uint32 GetCraftedItemIdForQuality(uint32 qualityTier);

    Player* _player;
    Spell* _spell;

    CraftingDataEntry const* _craftingData;
};

#endif
