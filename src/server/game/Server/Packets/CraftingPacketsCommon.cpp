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
#include "PacketOperators.h"

namespace WorldPackets::Crafting
{
ByteBuffer& operator>>(ByteBuffer& data, CraftingReagentBase& reagent)
{
    data.ResetBitPos();
    data >> OptionalInit(reagent.ItemID);
    data >> OptionalInit(reagent.CurrencyID);

    if (reagent.ItemID)
        data >> *reagent.ItemID;

    if (reagent.CurrencyID)
        data >> *reagent.CurrencyID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CraftingReagentBase const& reagent)
{
    data << OptionalInit(reagent.ItemID);
    data << OptionalInit(reagent.CurrencyID);
    data.FlushBits();

    if (reagent.ItemID)
        data << int32(*reagent.ItemID);

    if (reagent.CurrencyID)
        data << int32(*reagent.CurrencyID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellReducedReagent const& spellReducedReagent)
{
    data << int32(spellReducedReagent.Quantity);
    data << spellReducedReagent.Reagent;

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
    data << float(craftingData.ModSkillGain);
    data << uint64(craftingData.OrderID);
    data << Size<uint32>(craftingData.ResourcesReturned);
    data << uint32(craftingData.OperationID);
    data << craftingData.ItemGUID;
    data << int32(craftingData.Quantity);
    data << int32(craftingData.EnchantID);
    data << int32(craftingData.ConcentrationCurrencyID);
    data << int32(craftingData.ConcentrationSpent);
    data << int32(craftingData.IngenuityRefund);

    data << Bits<1>(craftingData.IsCrit);
    data << Bits<1>(craftingData.IsRecraft);
    data << Bits<1>(craftingData.IsInitialRecraft);
    data << Bits<1>(craftingData.IsFirstCraft);
    data << Bits<1>(craftingData.HasIngenuityProc);
    data << Bits<1>(craftingData.ApplyConcentration);
    data.FlushBits();

    data << craftingData.OldItem;
    data << craftingData.NewItem;

    for (SpellReducedReagent const& spellReducedReagent : craftingData.ResourcesReturned)
        data << spellReducedReagent;

    return data;
}
}
