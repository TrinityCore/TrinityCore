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

#include "CommonHelpers.h"
#include "Common.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Player.h"
#include "SharedDefines.h"

uint8 Trinity::Helpers::Entity::GetPlayerSpecialization(Player const* who)
{
    if (!who)
        return 0;

    uint32 tabId = who->GetPrimaryTalentTree();
    TalentTabEntry const* tabEntry = sTalentTabStore.LookupEntry(tabId);
    if (!tabEntry)
        return 0;

    return tabEntry->OrderIndex;
}

bool Trinity::Helpers::Entity::IsPlayerHealer(Player const* who)
{
    if (!who)
        return false;

    switch (who->GetClass())
    {
        case CLASS_WARRIOR:
        case CLASS_HUNTER:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        default:
            return false;
        case CLASS_PALADIN:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_PALADIN_HOLY);
        case CLASS_PRIEST:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) != SPEC_PRIEST_SHADOW);
        case CLASS_SHAMAN:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_SHAMAN_RESTORATION);
        case CLASS_DRUID:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_DRUID_RESTORATION);
        }
}

bool Trinity::Helpers::Entity::IsPlayerRangedAttacker(Player const* who)
{
    if (!who)
        return false;

    switch (who->GetClass())
    {
        case CLASS_WARRIOR:
        case CLASS_PALADIN:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        default:
            return false;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            return true;
        case CLASS_HUNTER:
        {
            // check if we have a ranged weapon equipped
            Item const* rangedSlot = who->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (ItemTemplate const* rangedTemplate = rangedSlot ? rangedSlot->GetTemplate() : nullptr)
                if ((1 << rangedTemplate->GetSubClass()) & ITEM_SUBCLASS_MASK_WEAPON_RANGED)
                    return true;
            return false;
        }
        case CLASS_PRIEST:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_PRIEST_SHADOW);
        case CLASS_SHAMAN:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_SHAMAN_ELEMENTAL);
        case CLASS_DRUID:
            return (Trinity::Helpers::Entity::GetPlayerSpecialization(who) == SPEC_DRUID_BALANCE);
    }
}
