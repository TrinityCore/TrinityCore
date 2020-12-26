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

#include "DB2Stores.h"
#include "World.h"
#include "ItemTemplate.h"
#include "Player.h"

int32 const SocketColorToGemTypeMask[19] =
{
    0,
    SOCKET_COLOR_META,
    SOCKET_COLOR_RED,
    SOCKET_COLOR_YELLOW,
    SOCKET_COLOR_BLUE,
    SOCKET_COLOR_HYDRAULIC,
    SOCKET_COLOR_COGWHEEL,
    SOCKET_COLOR_PRISMATIC,
    SOCKET_COLOR_RELIC_IRON,
    SOCKET_COLOR_RELIC_BLOOD,
    SOCKET_COLOR_RELIC_SHADOW,
    SOCKET_COLOR_RELIC_FEL,
    SOCKET_COLOR_RELIC_ARCANE,
    SOCKET_COLOR_RELIC_FROST,
    SOCKET_COLOR_RELIC_FIRE,
    SOCKET_COLOR_RELIC_WATER,
    SOCKET_COLOR_RELIC_LIFE,
    SOCKET_COLOR_RELIC_WIND,
    SOCKET_COLOR_RELIC_HOLY
};

char const* ItemTemplate::GetName(LocaleConstant locale) const
{
    if (!strlen(ExtendedData->Display[locale]))
        return GetDefaultLocaleName();

    return ExtendedData->Display[locale];
}


bool ItemTemplate::CanChangeEquipStateInCombat() const
{
    switch (GetInventoryType())
    {
        case INVTYPE_RELIC:
        case INVTYPE_SHIELD:
        case INVTYPE_HOLDABLE:
            return true;
        default:
            break;
    }

    switch (GetClass())
    {
        case ITEM_CLASS_WEAPON:
        case ITEM_CLASS_PROJECTILE:
            return true;
    }

    return false;
}

uint32 ItemTemplate::GetSkill() const
{
    static uint32 const itemWeaponSkills[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        SKILL_AXES,             SKILL_TWO_HANDED_AXES, SKILL_BOWS,   SKILL_GUNS,              SKILL_MACES,
        SKILL_TWO_HANDED_MACES, SKILL_POLEARMS,        SKILL_SWORDS, SKILL_TWO_HANDED_SWORDS, SKILL_WARGLAIVES,
        SKILL_STAVES,           0,                     0,            SKILL_FIST_WEAPONS,      0,
        SKILL_DAGGERS,          0,                     0,            SKILL_CROSSBOWS,         SKILL_WANDS,
        SKILL_FISHING
    };

    static uint32 const itemArmorSkills[MAX_ITEM_SUBCLASS_ARMOR] =
    {
        0, SKILL_CLOTH, SKILL_LEATHER, SKILL_MAIL, SKILL_PLATE_MAIL, 0, SKILL_SHIELD, 0, 0, 0, 0
    };


    switch (GetClass())
    {
        case ITEM_CLASS_WEAPON:
            if (GetSubClass() >= MAX_ITEM_SUBCLASS_WEAPON)
                return 0;
            else
                return itemWeaponSkills[GetSubClass()];

        case ITEM_CLASS_ARMOR:
            if (GetSubClass() >= MAX_ITEM_SUBCLASS_ARMOR)
                return 0;
            else
                return itemArmorSkills[GetSubClass()];

        default:
            return 0;
    }
}

char const* ItemTemplate::GetDefaultLocaleName() const
{
    return ExtendedData->Display[sWorld->GetDefaultDbcLocale()];
}

uint32 ItemTemplate::GetArmor(uint32 itemLevel) const
{
    uint32 quality = ItemQualities(GetQuality()) != ITEM_QUALITY_HEIRLOOM ? ItemQualities(GetQuality()) : ITEM_QUALITY_RARE;
    if (quality > ITEM_QUALITY_ARTIFACT)
        return 0;

    // all items but shields
    if (GetClass() != ITEM_CLASS_ARMOR || GetSubClass() != ITEM_SUBCLASS_ARMOR_SHIELD)
    {
        ItemArmorQualityEntry const* armorQuality = sItemArmorQualityStore.LookupEntry(itemLevel);
        ItemArmorTotalEntry const* armorTotal = sItemArmorTotalStore.LookupEntry(itemLevel);
        if (!armorQuality || !armorTotal)
            return 0;

        uint32 inventoryType = GetInventoryType();
        if (inventoryType == INVTYPE_ROBE)
            inventoryType = INVTYPE_CHEST;

        ArmorLocationEntry const* location = sArmorLocationStore.LookupEntry(inventoryType);
        if (!location)
            return 0;

        if (GetSubClass() < ITEM_SUBCLASS_ARMOR_CLOTH || GetSubClass() > ITEM_SUBCLASS_ARMOR_PLATE)
            return 0;

        float total = 1.0f;
        float locationModifier = 1.0f;
        switch (GetSubClass())
        {
            case ITEM_SUBCLASS_ARMOR_CLOTH:
                total = armorTotal->Cloth;
                locationModifier = location->Clothmodifier;
                break;
            case ITEM_SUBCLASS_ARMOR_LEATHER:
                total = armorTotal->Leather;
                locationModifier = location->Leathermodifier;
                break;
            case ITEM_SUBCLASS_ARMOR_MAIL:
                total = armorTotal->Mail;
                locationModifier = location->Chainmodifier;
                break;
            case ITEM_SUBCLASS_ARMOR_PLATE:
                total = armorTotal->Plate;
                locationModifier = location->Platemodifier;
                break;
            default:
                break;
        }

        return uint32(armorQuality->Qualitymod[quality] * total * locationModifier + 0.5f);
    }

    // shields
    ItemArmorShieldEntry const* shield = sItemArmorShieldStore.LookupEntry(itemLevel);
    if (!shield)
        return 0;

    return uint32(shield->Quality[quality] + 0.5f);
}

float ItemTemplate::GetDPS(uint32 itemLevel) const
{
    uint32 quality = ItemQualities(GetQuality()) != ITEM_QUALITY_HEIRLOOM ? ItemQualities(GetQuality()) : ITEM_QUALITY_RARE;
    if (GetClass() != ITEM_CLASS_WEAPON || quality > ITEM_QUALITY_ARTIFACT)
        return 0.0f;

    float dps = 0.0f;
    switch (GetInventoryType())
    {
        case INVTYPE_AMMO:
            dps = sItemDamageAmmoStore.AssertEntry(itemLevel)->Quality[quality];
            break;
        case INVTYPE_2HWEAPON:
            if (GetFlags2() & ITEM_FLAG2_CASTER_WEAPON)
                dps = sItemDamageTwoHandCasterStore.AssertEntry(itemLevel)->Quality[quality];
            else
                dps = sItemDamageTwoHandStore.AssertEntry(itemLevel)->Quality[quality];
            break;
        case INVTYPE_RANGED:
        case INVTYPE_THROWN:
        case INVTYPE_RANGEDRIGHT:
            switch (GetSubClass())
            {
                case ITEM_SUBCLASS_WEAPON_WAND:
                    dps = sItemDamageOneHandCasterStore.AssertEntry(itemLevel)->Quality[quality];
                    break;
                case ITEM_SUBCLASS_WEAPON_BOW:
                case ITEM_SUBCLASS_WEAPON_GUN:
                case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    if (GetFlags2() & ITEM_FLAG2_CASTER_WEAPON)
                        dps = sItemDamageTwoHandCasterStore.AssertEntry(itemLevel)->Quality[quality];
                    else
                        dps = sItemDamageTwoHandStore.AssertEntry(itemLevel)->Quality[quality];
                    break;
                default:
                    break;
            }
            break;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            if (GetFlags2() & ITEM_FLAG2_CASTER_WEAPON)
                dps = sItemDamageOneHandCasterStore.AssertEntry(itemLevel)->Quality[quality];
            else
                dps = sItemDamageOneHandStore.AssertEntry(itemLevel)->Quality[quality];
            break;
        default:
            break;
    }

    return dps;
}

void ItemTemplate::GetDamage(uint32 itemLevel, float& minDamage, float& maxDamage) const
{
    minDamage = maxDamage = 0.0f;
    float dps = GetDPS(itemLevel);
    if (dps > 0.0f)
    {
        float avgDamage = dps * GetDelay() * 0.001f;
        minDamage = (GetDmgVariance() * -0.5f + 1.0f) * avgDamage;
        maxDamage = floor(float(avgDamage * (GetDmgVariance() * 0.5f + 1.0f) + 0.5f));
    }
}

bool ItemTemplate::IsUsableByLootSpecialization(Player const* player, bool alwaysAllowBoundToAccount) const
{
    if (GetFlags() & ITEM_FLAG_IS_BOUND_TO_ACCOUNT && alwaysAllowBoundToAccount)
        return true;

    uint32 spec = player->GetLootSpecId();
    if (!spec)
        spec = player->GetPrimarySpecialization();
    if (!spec)
        spec = player->GetDefaultSpecId();

    ChrSpecializationEntry const* chrSpecialization = sChrSpecializationStore.LookupEntry(spec);
    if (!chrSpecialization)
        return false;

    std::size_t levelIndex = 0;
    if (player->getLevel() >= 110)
        levelIndex = 2;
    else if (player->getLevel() > 40)
        levelIndex = 1;

    return Specializations[levelIndex].test(CalculateItemSpecBit(chrSpecialization));
}

std::size_t ItemTemplate::CalculateItemSpecBit(ChrSpecializationEntry const* spec)
{
    return (spec->ClassID - 1) * MAX_SPECIALIZATIONS + spec->OrderIndex;
}
