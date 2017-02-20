/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "SpellMgr.h"
#include "SpellInfo.h"

#include "SpellInfo.h"
#include "SpellMgr.h"

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


float ItemTemplate::getDPS() const
{
    if (!Delay)
        return 0.f;

    float temp = 0.f;
    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
        temp += Damage[i].DamageMin + Damage[i].DamageMax;

    return temp * 500.f / Delay;
}

int32 ItemTemplate::getFeralBonus(int32 extraDPS /*= 0*/) const
{
    // 0x02A5F3 - is mask for Melee weapon from ItemSubClassMask.dbc
    if (Class == ITEM_CLASS_WEAPON && (1 << SubClass) & 0x02A5F3)
    {
        int32 bonus = int32((extraDPS + getDPS()) * 14.0f) - 767;
        if (bonus < 0)
            return 0;
        return bonus;
    }

    return 0;
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

void ItemTemplate::_LoadTotalAP()
{
    int32 totalAP = 0;
    for (uint32 i = 0; i < StatsCount; ++i)
        if (ItemStat[i].ItemStatType == ITEM_MOD_ATTACK_POWER)
            totalAP += ItemStat[i].ItemStatValue;

    // some items can have equip spells with +AP
    for (uint32 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
        if (Spells[i].SpellId > 0 && Spells[i].SpellTrigger == ITEM_SPELLTRIGGER_ON_EQUIP)
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(Spells[i].SpellId))
                for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
                    if (spellInfo->Effects[j].IsAura(SPELL_AURA_MOD_ATTACK_POWER))
                        totalAP += spellInfo->Effects[j].CalcValue();

    _totalAP = totalAP;
}

void ItemTemplate::InitializeQueryData()
{
    WorldPacket queryTemp;
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
    {
        queryTemp = BuildQueryData(static_cast<LocaleConstant>(loc));
        QueryData[loc] = queryTemp;
    }
}

WorldPacket ItemTemplate::BuildQueryData(LocaleConstant loc) const
{
    WorldPacket queryTemp(SMSG_ITEM_QUERY_SINGLE_RESPONSE, 500);

    std::string locName = Name1;
    std::string locDescription = Description;

    if (ItemLocale const* il = sObjectMgr->GetItemLocale(ItemId))
    {
        ObjectMgr::GetLocaleString(il->Name, loc, locName);
        ObjectMgr::GetLocaleString(il->Description, loc, locDescription);
    }

    queryTemp << ItemId;
    queryTemp << Class;
    queryTemp << SubClass;
    queryTemp << SoundOverrideSubclass;
    queryTemp << locName;
    queryTemp << uint8(0x00);                                //Name2; // blizz not send name there, just uint8(0x00); <-- \0 = empty string = empty name...
    queryTemp << uint8(0x00);                                //Name3; // blizz not send name there, just uint8(0x00);
    queryTemp << uint8(0x00);                                //Name4; // blizz not send name there, just uint8(0x00);
    queryTemp << DisplayInfoID;
    queryTemp << Quality;
    queryTemp << Flags;
    queryTemp << Flags2;
    queryTemp << BuyPrice;
    queryTemp << SellPrice;
    queryTemp << InventoryType;
    queryTemp << AllowableClass;
    queryTemp << AllowableRace;
    queryTemp << ItemLevel;
    queryTemp << RequiredLevel;
    queryTemp << RequiredSkill;
    queryTemp << RequiredSkillRank;
    queryTemp << RequiredSpell;
    queryTemp << RequiredHonorRank;
    queryTemp << RequiredCityRank;
    queryTemp << RequiredReputationFaction;
    queryTemp << RequiredReputationRank;
    queryTemp << int32(MaxCount);
    queryTemp << int32(Stackable);
    queryTemp << ContainerSlots;
    queryTemp << StatsCount;                         // item stats count
    for (uint32 i = 0; i < StatsCount; ++i)
    {
        queryTemp << ItemStat[i].ItemStatType;
        queryTemp << ItemStat[i].ItemStatValue;
    }
    queryTemp << ScalingStatDistribution;            // scaling stats distribution
    queryTemp << ScalingStatValue;                   // some kind of flags used to determine stat values column
    for (int i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        queryTemp << Damage[i].DamageMin;
        queryTemp << Damage[i].DamageMax;
        queryTemp << Damage[i].DamageType;
    }

    // resistances (7)
    queryTemp << Armor;
    queryTemp << HolyRes;
    queryTemp << FireRes;
    queryTemp << NatureRes;
    queryTemp << FrostRes;
    queryTemp << ShadowRes;
    queryTemp << ArcaneRes;

    queryTemp << Delay;
    queryTemp << AmmoType;
    queryTemp << RangedModRange;

    for (uint8 s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
    {
        // spells are validated on template loading
        if (Spells[s].SpellId > 0)
        {
            queryTemp << Spells[s].SpellId;
            queryTemp << Spells[s].SpellTrigger;
            queryTemp << uint32(-abs(Spells[s].SpellCharges));
            queryTemp << uint32(Spells[s].SpellCooldown);
            queryTemp << uint32(Spells[s].SpellCategory);
            queryTemp << uint32(Spells[s].SpellCategoryCooldown);
        }
        else
        {
            queryTemp << uint32(0);
            queryTemp << uint32(0);
            queryTemp << uint32(0);
            queryTemp << uint32(-1);
            queryTemp << uint32(0);
            queryTemp << uint32(-1);
        }
    }
    queryTemp << Bonding;
    queryTemp << locDescription;
    queryTemp << PageText;
    queryTemp << LanguageID;
    queryTemp << PageMaterial;
    queryTemp << StartQuest;
    queryTemp << LockID;
    queryTemp << int32(Material);
    queryTemp << Sheath;
    queryTemp << RandomProperty;
    queryTemp << RandomSuffix;
    queryTemp << Block;
    queryTemp << ItemSet;
    queryTemp << MaxDurability;
    queryTemp << Area;
    queryTemp << Map;                                // Added in 1.12.x & 2.0.1 client branch
    queryTemp << BagFamily;
    queryTemp << TotemCategory;
    for (int s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
    {
        queryTemp << Socket[s].Color;
        queryTemp << Socket[s].Content;
    }
    queryTemp << socketBonus;
    queryTemp << GemProperties;
    queryTemp << RequiredDisenchantSkill;
    queryTemp << ArmorDamageModifier;
    queryTemp << Duration;                           // added in 2.4.2.8209, duration (seconds)
    queryTemp << ItemLimitCategory;                  // WotLK, ItemLimitCategory
    queryTemp << HolidayId;                          // Holiday.dbc?
    return queryTemp;
}
