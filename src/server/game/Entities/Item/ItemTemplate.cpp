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

#include "DBCStores.h"
#include "DB2Stores.h"
#include "Player.h"
#include "World.h"
#include "ItemTemplate.h"

char const* ItemTemplate::GetName(LocaleConstant locale) const
{
    if (!strlen(ExtendedData->Display->Str[locale]))
        return GetDefaultLocaleName();

    return ExtendedData->Display->Str[locale];
}

char const* ItemTemplate::GetDefaultLocaleName() const
{
    return ExtendedData->Display->Str[sWorld->GetDefaultDbcLocale()];
}

bool ItemTemplate::CanChangeEquipStateInCombat() const
{
    switch (GetInventoryType())
    {
        case INVTYPE_RELIC:
        case INVTYPE_SHIELD:
        case INVTYPE_HOLDABLE:
            return true;
    }

    switch (GetClass())
    {
        case ITEM_CLASS_WEAPON:
        case ITEM_CLASS_PROJECTILE:
            return true;
    }

    return false;
}

float ItemTemplate::GetItemLevelIncludingQuality() const
{
    float itemLevel(GetBaseItemLevel());
    switch (GetQuality())
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

uint32 GetItemScalingModifier(uint32 maxIlvl, ItemQualities quality, InventoryType invType)
{
    // Believe it or not, yes
    uint32 suffixFactor = -1;
    switch (invType)
    {
        // Items of that type don`t have points
        case INVTYPE_NON_EQUIP:
        case INVTYPE_BAG:
        case INVTYPE_TABARD:
        case INVTYPE_AMMO:
        case INVTYPE_QUIVER:
        case INVTYPE_RELIC:
            break;
            // Select point coefficient
        case INVTYPE_HEAD:
        case INVTYPE_BODY:
        case INVTYPE_CHEST:
        case INVTYPE_LEGS:
        case INVTYPE_2HWEAPON:
        case INVTYPE_ROBE:
            suffixFactor = 0;
            break;
        case INVTYPE_SHOULDERS:
        case INVTYPE_WAIST:
        case INVTYPE_FEET:
        case INVTYPE_HANDS:
        case INVTYPE_TRINKET:
            suffixFactor = 1;
            break;
        case INVTYPE_NECK:
        case INVTYPE_WRISTS:
        case INVTYPE_FINGER:
        case INVTYPE_SHIELD:
        case INVTYPE_CLOAK:
        case INVTYPE_HOLDABLE:
            suffixFactor = 2;
            break;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            suffixFactor = 3;
            break;
        case INVTYPE_RANGED:
        case INVTYPE_THROWN:
        case INVTYPE_RANGEDRIGHT:
            suffixFactor = 4;
            break;
    }

    if (suffixFactor > 4)
        return 0;

    RandomPropertiesPointsEntry const* randPropEntry = sRandomPropertiesPointsStore.LookupEntry(maxIlvl);
    if (!randPropEntry)
        return 0;

    switch (quality)
    {
        case ITEM_QUALITY_UNCOMMON:
            return randPropEntry->UncommonPropertiesPoints[suffixFactor];
        case ITEM_QUALITY_RARE:
            return randPropEntry->RarePropertiesPoints[suffixFactor];
        case ITEM_QUALITY_EPIC:
        case ITEM_QUALITY_LEGENDARY:
            return randPropEntry->EpicPropertiesPoints[suffixFactor];
        default:
            return 0;
    }

    return 0;
}

uint32 ItemTemplate::GetStatValue(uint32 index, Player const* owner /*= nullptr*/) const
{
    if (!owner)
        return GetItemStatValue(index);

    ScalingStatDistributionEntry const* ssd = GetScalingStatDistribution() ? sScalingStatDistributionStore.LookupEntry(GetScalingStatDistribution()) : nullptr;
    // req. check at equip, but allow use for extended range if range limit max level, set proper level
    uint32 ssdLevel = owner->getLevel();

    if (ssd && ssdLevel > ssd->Maxlevel)
        ssdLevel = ssd->Maxlevel;
    if (ssd && ssdLevel < ssd->Minlevel)
        ssdLevel = ssd->Minlevel;
    if (ssdLevel < 1)
        ssdLevel = 1;

    ScalingStatValuesEntry const* ssv = ssd ? sScalingStatValuesStore.LookupEntry(ssdLevel) : nullptr;

    uint32 statBaseValue = 0;
    if (ssd && ssv)
    {
        if (ssd->StatID[index] < 0)
            return 0; // What do we do ?

        statBaseValue = ssv->GetStatMultiplier(GetInventoryType()) * ssd->Bonus[index] / 10000;
    }
    else
    {
        statBaseValue = GetItemStatValue(index);

        uint32 itemLevel = GetBaseItemLevel();
        uint32 maxItemLevel = owner->GetUInt32Value(UNIT_FIELD_MAXITEMLEVEL);
        if (!maxItemLevel || maxItemLevel >= itemLevel) // TODO: This might work if >=. Check.
            return statBaseValue;

        float minScaler = GetItemScalingModifier(GetBaseItemLevel(), ItemQualities(GetQuality()), ::InventoryType(GetInventoryType()));
        float maxScaler = GetItemScalingModifier(maxItemLevel, ItemQualities(GetQuality()), ::InventoryType(GetInventoryType()));

        if (maxScaler != 0.f && minScaler != 0.f)
        {
            float statAllocation = GetItemStatAllocation(index) * maxScaler * 0.0001f;
            return std::ceil(statAllocation - ((maxScaler / minScaler) * GetItemStatSocketCostMultiplier(index)));
        }
    }

    return statBaseValue;
}

uint32 ItemTemplate::GetEffectiveArmor(Player const* owner) const
{
    if (GetQuality() > ITEM_QUALITY_ARTIFACT)
        return 0;

    uint32 level = GetBaseItemLevel();
    if (owner)
    {
        uint32 maxItemLevel = owner->GetUInt32Value(UNIT_FIELD_MAXITEMLEVEL);
        if (maxItemLevel != 0 && level > maxItemLevel)
            level = maxItemLevel;
    }

    if (GetClass() != ITEM_CLASS_ARMOR || GetSubClass() != ITEM_SUBCLASS_ARMOR_SHIELD)
    {
        ItemArmorQualityEntry const* armorQuality = sItemArmorQualityStore.LookupEntry(level);
        ItemArmorTotalEntry const* armorTotal = sItemArmorTotalStore.LookupEntry(level);
        if (!armorQuality || !armorTotal)
            return 0;

        uint32 invType = GetInventoryType();
        if (invType == INVTYPE_ROBE)
            invType = INVTYPE_CHEST;

        ArmorLocationEntry const* location = sArmorLocationStore.LookupEntry(invType);
        if (!location)
            return 0;

        if (GetSubClass() < ITEM_SUBCLASS_ARMOR_CLOTH || GetSubClass() > ITEM_SUBCLASS_ARMOR_PLATE)
            return 0;

        return uint32(armorQuality->Qualitymod[GetQuality()] * armorTotal->Value[GetSubClass() - ITEM_SUBCLASS_ARMOR_CLOTH] * location->Value[GetSubClass() - ITEM_SUBCLASS_ARMOR_CLOTH] + 0.5f);
    }

    ItemArmorShieldEntry const* shield = sItemArmorShieldStore.LookupEntry(level);
    if (!shield)
        return 0;

    return uint32(shield->Quality[GetQuality()] + 0.5f);
}

bool ItemTemplate::GetWeaponDamage(Player const* owner, float& minValue, float& maxValue, float& dps) const
{
    minValue = maxValue = 0.0f;
    if (GetClass() != ITEM_CLASS_WEAPON || GetQuality() > ITEM_QUALITY_ARTIFACT)
        return false;

    uint32 level = GetBaseItemLevel();
    if (owner)
    {
        uint32 maxItemLevel = owner->GetUInt32Value(UNIT_FIELD_MAXITEMLEVEL);
        if (maxItemLevel != 0 && level > maxItemLevel)
            level = maxItemLevel;
    }

    DBCStorage<ItemDamageEntry>* store = nullptr;

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
                    return false;
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
            return false;
    }

    if (!store)
        return false;

    ItemDamageEntry const* damageInfo = store->LookupEntry(level);
    if (!damageInfo)
        return false;

    dps = damageInfo->Quality[GetQuality()];

    float avgDamage = GetDelay() * damageInfo->Quality[GetQuality()] * 0.001f;
    float scaled_stat = std::floor((GetStatScalingFactor() * 0.5f + 1.f) * avgDamage + 0.5f);
    if (GetDelay() && GetArmorDamageModifier() != 0.f)
    {
        float invMsDelay = 1000.0f / float(GetDelay());

        float v16 = (invMsDelay * ((1.f - (GetStatScalingFactor() * 0.5f)) * avgDamage)) + GetArmorDamageModifier();
        v16 = std::max(v16, 1.f);

        minValue = (1.0f / invMsDelay) * v16;

        maxValue = (1.0f / invMsDelay) * (((1000.f / float(GetDelay())) * scaled_stat) + GetArmorDamageModifier());
    }
    else
    {
        maxValue = scaled_stat;
        minValue = (1.f - (GetStatScalingFactor() * 0.5f)) * avgDamage;
    }

    return true;
}
