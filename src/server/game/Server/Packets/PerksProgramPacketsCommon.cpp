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

#include "PerksProgramPacketsCommon.h"

namespace WorldPackets::PerksProgram
{
ByteBuffer& operator<<(ByteBuffer& data, PerksVendorItem const& perksVendorItem)
{
    data << int32(perksVendorItem.VendorItemID);
    data << int32(perksVendorItem.MountID);
    data << int32(perksVendorItem.BattlePetSpeciesID);
    data << int32(perksVendorItem.TransmogSetID);
    data << int32(perksVendorItem.ItemModifiedAppearanceID);
    data << int32(perksVendorItem.TransmogIllusionID);
    data << int32(perksVendorItem.ToyID);
    data << int32(perksVendorItem.Price);
    data << int32(perksVendorItem.OriginalPrice);
    data << perksVendorItem.AvailableUntil;
    data << Bits<1>(perksVendorItem.Disabled);
    data << Bits<1>(perksVendorItem.DoesNotExpire);
    data.FlushBits();

    return data;
}
}
