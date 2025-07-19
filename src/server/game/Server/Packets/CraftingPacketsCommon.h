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

#ifndef TRINITYCORE_CRAFTING_PACKETS_COMMON_H
#define TRINITYCORE_CRAFTING_PACKETS_COMMON_H

#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"

namespace WorldPackets::Crafting
{
struct SpellReducedReagent
{
    int32 ItemID = 0;
    int32 Quantity = 0;
};

struct CraftingData
{
    int32 CraftingQualityID = 0;
    float QualityProgress = 0.0f;
    int32 SkillLineAbilityID = 0;
    int32 CraftingDataID = 0;
    int32 Multicraft = 0;
    int32 SkillFromReagents = 0;
    int32 Skill = 0;
    int32 CritBonusSkill = 0;
    float field_1C = 0.0f;
    uint64 field_20 = 0;
    bool IsCrit = false;
    bool field_29 = false;
    bool field_2A = false;
    bool BonusCraft = false;
    std::vector<SpellReducedReagent> ResourcesReturned;
    uint32 OperationID = 0;
    ObjectGuid ItemGUID;
    int32 Quantity = 0;
    Item::ItemInstance OldItem;
    Item::ItemInstance NewItem;
    int32 EnchantID = 0;
    int32 ConcentrationCurrencyID = 0;
    int32 ConcentrationSpent = 0;
    int32 IngenuityRefund = 0;
    bool HasIngenuityProc = false;
    bool ApplyConcentration = false;
};

ByteBuffer& operator<<(ByteBuffer& data, SpellReducedReagent const& spellReducedReagent);
ByteBuffer& operator<<(ByteBuffer& data, CraftingData const& craftingData);
}
#endif // TRINITYCORE_CRAFTING_PACKETS_COMMON_H
