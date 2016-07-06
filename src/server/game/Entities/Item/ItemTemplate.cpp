/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "DBCStores.h"
#include "DB2Stores.h"
#include "World.h"
#include "ItemTemplate.h"
#include "Player.h"

char const* ItemTemplate::GetName(LocaleConstant locale) const
{
    if (!strlen(ExtendedData->Name->Str[locale]))
        return GetDefaultLocaleName();

    return ExtendedData->Name->Str[locale];
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
    const static uint32 item_weapon_skills[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        SKILL_AXES,     SKILL_2H_AXES,  SKILL_BOWS,          SKILL_GUNS,      SKILL_MACES,
        SKILL_2H_MACES, SKILL_POLEARMS, SKILL_SWORDS,        SKILL_2H_SWORDS, 0,
        SKILL_STAVES,   0,              0,                   SKILL_FIST_WEAPONS,   0,
        SKILL_DAGGERS,  SKILL_THROWN,   SKILL_ASSASSINATION, SKILL_CROSSBOWS, SKILL_WANDS,
        SKILL_FISHING
    };

    const static uint32 item_armor_skills[MAX_ITEM_SUBCLASS_ARMOR] =
    {
        0, SKILL_CLOTH, SKILL_LEATHER, SKILL_MAIL, SKILL_PLATE_MAIL, 0, SKILL_SHIELD, 0, 0, 0, 0
    };


    switch (GetClass())
    {
    case ITEM_CLASS_WEAPON:
        if (GetSubClass() >= MAX_ITEM_SUBCLASS_WEAPON)
            return 0;
        else
            return item_weapon_skills[GetSubClass()];

    case ITEM_CLASS_ARMOR:
        if (GetSubClass() >= MAX_ITEM_SUBCLASS_ARMOR)
            return 0;
        else
            return item_armor_skills[GetSubClass()];

    default:
        return 0;
    }
}

char const* ItemTemplate::GetDefaultLocaleName() const
{
    return ExtendedData->Name->Str[sWorld->GetDefaultDbcLocale()];
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

        return uint32(armorQuality->QualityMod[quality] * armorTotal->Value[GetSubClass() - 1] * location->Modifier[GetSubClass() - 1] + 0.5f);
    }

    // shields
    ItemArmorShieldEntry const* shield = sItemArmorShieldStore.LookupEntry(itemLevel);
    if (!shield)
        return 0;

    return uint32(shield->Quality[quality] + 0.5f);
}

void ItemTemplate::GetDamage(uint32 itemLevel, float& minDamage, float& maxDamage) const
{
    minDamage = maxDamage = 0.0f;
    uint32 quality = ItemQualities(GetQuality()) != ITEM_QUALITY_HEIRLOOM ? ItemQualities(GetQuality()) : ITEM_QUALITY_RARE;
    if (GetClass() != ITEM_CLASS_WEAPON || quality > ITEM_QUALITY_ARTIFACT)
        return;

    DBCStorage<ItemDamageEntry>* store = NULL;
    // get the right store here
    if (GetInventoryType() > INVTYPE_RANGEDRIGHT)
        return;

    switch (GetInventoryType())
    {
        case INVTYPE_AMMO:
            store = &sItemDamageAmmoStore;
            break;
        case INVTYPE_2HWEAPON:
            if (GetFlags2() & ITEM_FLAG2_CASTER_WEAPON)
                store = &sItemDamageTwoHandCasterStore;
            else
                store = &sItemDamageTwoHandStore;
            break;
        case INVTYPE_RANGED:
        case INVTYPE_THROWN:
        case INVTYPE_RANGEDRIGHT:
            switch (GetSubClass())
            {
                case ITEM_SUBCLASS_WEAPON_WAND:
                    store = &sItemDamageWandStore;
                    break;
                case ITEM_SUBCLASS_WEAPON_THROWN:
                    store = &sItemDamageThrownStore;
                    break;
                case ITEM_SUBCLASS_WEAPON_BOW:
                case ITEM_SUBCLASS_WEAPON_GUN:
                case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    store = &sItemDamageRangedStore;
                    break;
                default:
                    return;
            }
            break;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            if (GetFlags2() & ITEM_FLAG2_CASTER_WEAPON)
                store = &sItemDamageOneHandCasterStore;
            else
                store = &sItemDamageOneHandStore;
            break;
        default:
            return;
    }

    ASSERT(store);

    ItemDamageEntry const* damageInfo = store->LookupEntry(itemLevel);
    if (!damageInfo)
        return;

    float dps = damageInfo->DPS[quality];
    float avgDamage = dps * GetDelay() * 0.001f;
    minDamage = (GetStatScalingFactor() * -0.5f + 1.0f) * avgDamage;
    maxDamage = floor(float(avgDamage * (GetStatScalingFactor() * 0.5f + 1.0f) + 0.5f));
}

bool ItemTemplate::IsUsableBySpecialization(Player const* player) const
{
    uint32 spec = player->GetSpecId(player->GetActiveTalentGroup());
    if (!spec)
        spec = player->GetDefaultSpecId();

    ChrSpecializationEntry const* chrSpecialization = sChrSpecializationStore.LookupEntry(spec);
    if (!chrSpecialization)
        return false;

    return Specializations[player->getLevel() > 40].test(CalculateItemSpecBit(chrSpecialization));
}

std::size_t ItemTemplate::CalculateItemSpecBit(ChrSpecializationEntry const* spec)
{
    return (spec->ClassID - 1) * MAX_SPECIALIZATIONS + spec->OrderIndex;
}
