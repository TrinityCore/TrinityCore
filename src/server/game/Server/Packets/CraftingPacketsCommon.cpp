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

#include "CraftingPacketsCommon.h"

namespace WorldPackets::Crafting
{
ByteBuffer& operator<<(ByteBuffer& data, SpellReducedReagent const& spellReducedReagent)
{
    data << int32(spellReducedReagent.ItemID);
    data << int32(spellReducedReagent.Quantity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CraftingData const& craftingData)
{
    data << int32(craftingData.CraftingQualityID);
    data << float(craftingData.QualityProgress);
    data << int32(craftingData.SkillLineAbilityID);
    data << int32(craftingData.CraftingDataID);
    data << int32(craftingData.Multicraft);
    data << int32(craftingData.SkillFromReagents);
    data << int32(craftingData.Skill);
    data << int32(craftingData.CritBonusSkill);
    data << float(craftingData.field_1C);
    data << uint64(craftingData.field_20);
    data << uint32(craftingData.ResourcesReturned.size());
    data << uint32(craftingData.OperationID);
    data << craftingData.ItemGUID;
    data << int32(craftingData.Quantity);
    data << int32(craftingData.EnchantID);

    for (SpellReducedReagent const& spellReducedReagent : craftingData.ResourcesReturned)
        data << spellReducedReagent;

    data << Bits<1>(craftingData.IsCrit);
    data << Bits<1>(craftingData.field_29);
    data << Bits<1>(craftingData.field_2A);
    data << Bits<1>(craftingData.BonusCraft);
    data.FlushBits();

    data << craftingData.OldItem;
    data << craftingData.NewItem;

    return data;
}
}
