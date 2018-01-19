/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ItemTemplate.h"

bool ItemTemplate::CanChangeEquipStateInCombat() const
{
    switch (InventoryType)
    {
        case INVTYPE_RELIC:
        case INVTYPE_SHIELD:
        case INVTYPE_HOLDABLE:
            return true;
    }

    switch (Class)
    {
        case ITEM_CLASS_WEAPON:
        case ITEM_CLASS_PROJECTILE:
            return true;
    }

    return false;
}

float ItemTemplate::GetItemLevelIncludingQuality() const
{
    float itemLevel(ItemLevel);
    switch (Quality)
    {
        case ITEM_QUALITY_POOR:
        case ITEM_QUALITY_NORMAL:
        case ITEM_QUALITY_UNCOMMON:
        case ITEM_QUALITY_ARTIFACT:
        case ITEM_QUALITY_HEIRLOOM:
            itemLevel -= 13.f; // leaving this as a separate statement since we do not know the real behavior in this case
            break;
        case ITEM_QUALITY_RARE:
            itemLevel -= 13.f;
            break;
        case ITEM_QUALITY_EPIC:
        case ITEM_QUALITY_LEGENDARY:
        default:
            break;
    }

    return std::max<float>(0.f, itemLevel);
}

uint32 ItemTemplate::GetSkill() const
{
    static uint32 const itemWeaponSkills[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        SKILL_AXES,     SKILL_2H_AXES,  SKILL_BOWS,          SKILL_GUNS,         SKILL_MACES,
        SKILL_2H_MACES, SKILL_POLEARMS, SKILL_SWORDS,        SKILL_2H_SWORDS,    0,
        SKILL_STAVES,   0,              0,                   SKILL_FIST_WEAPONS, 0,
        SKILL_DAGGERS,  SKILL_THROWN,   SKILL_ASSASSINATION, SKILL_CROSSBOWS,    SKILL_WANDS,
        SKILL_FISHING
    };

    static uint32 const itemArmorSkills[MAX_ITEM_SUBCLASS_ARMOR] =
    {
        0, SKILL_CLOTH, SKILL_LEATHER, SKILL_MAIL, SKILL_PLATE_MAIL, 0, SKILL_SHIELD, 0, 0, 0, 0
    };

    switch (Class)
    {
        case ITEM_CLASS_WEAPON:
            if (SubClass >= MAX_ITEM_SUBCLASS_WEAPON)
                return 0;
            else
                return itemWeaponSkills[SubClass];

        case ITEM_CLASS_ARMOR:
            if (SubClass >= MAX_ITEM_SUBCLASS_ARMOR)
                return 0;
            else
                return itemArmorSkills[SubClass];

        default:
            return 0;
    }
}
