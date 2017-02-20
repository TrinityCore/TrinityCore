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
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
    {
        std::string locName = Name1;
        std::string locDescription = Description;

        if (ItemLocale const* il = sObjectMgr->GetItemLocale(ItemId))
        {
            ObjectMgr::GetLocaleString(il->Name, loc, locName);
            ObjectMgr::GetLocaleString(il->Description, loc, locDescription);
        }

        // guess size
        QueryData[loc].Initialize(SMSG_ITEM_QUERY_SINGLE_RESPONSE, 1);
        QueryData[loc] << ItemId;
        QueryData[loc] << Class;
        QueryData[loc] << SubClass;
        QueryData[loc] << SoundOverrideSubclass;
        QueryData[loc] << locName;
        QueryData[loc] << uint8(0x00);                                //Name2; // blizz not send name there, just uint8(0x00); <-- \0 = empty string = empty name...
        QueryData[loc] << uint8(0x00);                                //Name3; // blizz not send name there, just uint8(0x00);
        QueryData[loc] << uint8(0x00);                                //Name4; // blizz not send name there, just uint8(0x00);
        QueryData[loc] << DisplayInfoID;
        QueryData[loc] << Quality;
        QueryData[loc] << Flags;
        QueryData[loc] << Flags2;
        QueryData[loc] << BuyPrice;
        QueryData[loc] << SellPrice;
        QueryData[loc] << InventoryType;
        QueryData[loc] << AllowableClass;
        QueryData[loc] << AllowableRace;
        QueryData[loc] << ItemLevel;
        QueryData[loc] << RequiredLevel;
        QueryData[loc] << RequiredSkill;
        QueryData[loc] << RequiredSkillRank;
        QueryData[loc] << RequiredSpell;
        QueryData[loc] << RequiredHonorRank;
        QueryData[loc] << RequiredCityRank;
        QueryData[loc] << RequiredReputationFaction;
        QueryData[loc] << RequiredReputationRank;
        QueryData[loc] << int32(MaxCount);
        QueryData[loc] << int32(Stackable);
        QueryData[loc] << ContainerSlots;
        QueryData[loc] << StatsCount;                         // item stats count
        for (uint32 i = 0; i < StatsCount; ++i)
        {
            QueryData[loc] << ItemStat[i].ItemStatType;
            QueryData[loc] << ItemStat[i].ItemStatValue;
        }
        QueryData[loc] << ScalingStatDistribution;            // scaling stats distribution
        QueryData[loc] << ScalingStatValue;                   // some kind of flags used to determine stat values column
        for (int i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
        {
            QueryData[loc] << Damage[i].DamageMin;
            QueryData[loc] << Damage[i].DamageMax;
            QueryData[loc] << Damage[i].DamageType;
        }

        // resistances (7)
        QueryData[loc] << Armor;
        QueryData[loc] << HolyRes;
        QueryData[loc] << FireRes;
        QueryData[loc] << NatureRes;
        QueryData[loc] << FrostRes;
        QueryData[loc] << ShadowRes;
        QueryData[loc] << ArcaneRes;

        QueryData[loc] << Delay;
        QueryData[loc] << AmmoType;
        QueryData[loc] << RangedModRange;

        for (int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
        {
            // send DBC data for cooldowns in same way as it used in Spell::SendSpellCooldown
            // use `item_template` or if not set then only use spell cooldowns
            SpellInfo const* spell = sSpellMgr->GetSpellInfo(Spells[s].SpellId);
            if (spell)
            {
                bool db_data = Spells[s].SpellCooldown >= 0 || Spells[s].SpellCategoryCooldown >= 0;

                QueryData[loc] << Spells[s].SpellId;
                QueryData[loc] << Spells[s].SpellTrigger;
                QueryData[loc] << uint32(-abs(Spells[s].SpellCharges));

                if (db_data)
                {
                    QueryData[loc] << uint32(Spells[s].SpellCooldown);
                    QueryData[loc] << uint32(Spells[s].SpellCategory);
                    QueryData[loc] << uint32(Spells[s].SpellCategoryCooldown);
                }
                else
                {
                    QueryData[loc] << uint32(spell->RecoveryTime);
                    QueryData[loc] << uint32(spell->GetCategory());
                    QueryData[loc] << uint32(spell->CategoryRecoveryTime);
                }
            }
            else
            {
                QueryData[loc] << uint32(0);
                QueryData[loc] << uint32(0);
                QueryData[loc] << uint32(0);
                QueryData[loc] << uint32(-1);
                QueryData[loc] << uint32(0);
                QueryData[loc] << uint32(-1);
            }
        }
        QueryData[loc] << Bonding;
        QueryData[loc] << locDescription;
        QueryData[loc] << PageText;
        QueryData[loc] << LanguageID;
        QueryData[loc] << PageMaterial;
        QueryData[loc] << StartQuest;
        QueryData[loc] << LockID;
        QueryData[loc] << int32(Material);
        QueryData[loc] << Sheath;
        QueryData[loc] << RandomProperty;
        QueryData[loc] << RandomSuffix;
        QueryData[loc] << Block;
        QueryData[loc] << ItemSet;
        QueryData[loc] << MaxDurability;
        QueryData[loc] << Area;
        QueryData[loc] << Map;                                // Added in 1.12.x & 2.0.1 client branch
        QueryData[loc] << BagFamily;
        QueryData[loc] << TotemCategory;
        for (int s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
        {
            QueryData[loc] << Socket[s].Color;
            QueryData[loc] << Socket[s].Content;
        }
        QueryData[loc] << socketBonus;
        QueryData[loc] << GemProperties;
        QueryData[loc] << RequiredDisenchantSkill;
        QueryData[loc] << ArmorDamageModifier;
        QueryData[loc] << Duration;                           // added in 2.4.2.8209, duration (seconds)
        QueryData[loc] << ItemLimitCategory;                  // WotLK, ItemLimitCategory
        QueryData[loc] << HolidayId;                          // Holiday.dbc?
    }
}
