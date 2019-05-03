/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "SpellInfo.h"
#include "SpellMgr.h"

#include "Packets/QueryPackets.h"

bool ItemTemplate::HasSignature() const
{
    return GetMaxStackSize() == 1 &&
        Class != ITEM_CLASS_CONSUMABLE &&
        Class != ITEM_CLASS_QUEST &&
        (Flags & ITEM_FLAG_NO_CREATOR) == 0 &&
        ItemId != 6948; /*Hearthstone*/
}

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
        QueryData[loc] = BuildQueryData(static_cast<LocaleConstant>(loc));
}

WorldPacket ItemTemplate::BuildQueryData(LocaleConstant loc) const
{
    WorldPackets::Query::QueryItemSingleResponse response;

    std::string locName = Name1;
    std::string locDescription = Description;

    if (ItemLocale const* il = sObjectMgr->GetItemLocale(ItemId))
    {
        ObjectMgr::GetLocaleString(il->Name, loc, locName);
        ObjectMgr::GetLocaleString(il->Description, loc, locDescription);
    }

    response.ItemID = ItemId;
    response.Allow = true;

    response.Stats.Class = Class;
    response.Stats.SubClass = SubClass;
    response.Stats.SoundOverrideSubclass = SoundOverrideSubclass;
    response.Stats.Name = locName;
    response.Stats.DisplayInfoID = DisplayInfoID;
    response.Stats.Quality = Quality;
    response.Stats.Flags = Flags;
    response.Stats.Flags2 = Flags2;
    response.Stats.BuyPrice = BuyPrice;
    response.Stats.SellPrice = SellPrice;
    response.Stats.InventoryType = InventoryType;
    response.Stats.AllowableClass = AllowableClass;
    response.Stats.AllowableRace = AllowableRace;
    response.Stats.ItemLevel = ItemLevel;
    response.Stats.RequiredLevel = RequiredLevel;
    response.Stats.RequiredSkill = RequiredSkill;
    response.Stats.RequiredSkillRank = RequiredSkillRank;
    response.Stats.RequiredSpell = RequiredSpell;
    response.Stats.RequiredHonorRank = RequiredHonorRank;
    response.Stats.RequiredCityRank = RequiredCityRank;
    response.Stats.RequiredReputationFaction = RequiredReputationFaction;
    response.Stats.RequiredReputationRank = RequiredReputationRank;
    response.Stats.MaxCount = MaxCount;
    response.Stats.Stackable = Stackable;
    response.Stats.ContainerSlots = ContainerSlots;
    response.Stats.StatsCount = StatsCount;
    for (uint32 i = 0; i < StatsCount; ++i)
    {
        response.Stats.ItemStat[i].ItemStatType = ItemStat[i].ItemStatType;
        response.Stats.ItemStat[i].ItemStatValue = ItemStat[i].ItemStatValue;
    }

    response.Stats.ScalingStatDistribution = ScalingStatDistribution;
    response.Stats.ScalingStatValue = ScalingStatValue;

    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        response.Stats.Damage[i].DamageMin = Damage[i].DamageMin;
        response.Stats.Damage[i].DamageMax = Damage[i].DamageMax;
        response.Stats.Damage[i].DamageType = Damage[i].DamageType;
    }

    response.Stats.Resistance[SPELL_SCHOOL_NORMAL] = Armor;
    response.Stats.Resistance[SPELL_SCHOOL_HOLY] = HolyRes;
    response.Stats.Resistance[SPELL_SCHOOL_FIRE] = FireRes;
    response.Stats.Resistance[SPELL_SCHOOL_NATURE] = NatureRes;
    response.Stats.Resistance[SPELL_SCHOOL_FROST] = FrostRes;
    response.Stats.Resistance[SPELL_SCHOOL_SHADOW] = ShadowRes;
    response.Stats.Resistance[SPELL_SCHOOL_ARCANE] = ArcaneRes;

    response.Stats.Delay = Delay;
    response.Stats.AmmoType = AmmoType;
    response.Stats.RangedModRange = RangedModRange;

    for (uint8 s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
    {
        response.Stats.Spells[s].SpellId = Spells[s].SpellId;
        response.Stats.Spells[s].SpellTrigger = Spells[s].SpellTrigger;
        response.Stats.Spells[s].SpellCharges = Spells[s].SpellCharges;
        response.Stats.Spells[s].SpellCooldown = Spells[s].SpellCooldown;
        response.Stats.Spells[s].SpellCategory = Spells[s].SpellCategory;
        response.Stats.Spells[s].SpellCategoryCooldown = Spells[s].SpellCategoryCooldown;
    }

    response.Stats.Bonding = Bonding;
    response.Stats.Description = locDescription;
    response.Stats.PageText = PageText;
    response.Stats.LanguageID = LanguageID;
    response.Stats.PageMaterial = PageMaterial;
    response.Stats.StartQuest = StartQuest;
    response.Stats.LockID = LockID;
    response.Stats.Material = Material;
    response.Stats.Sheath = Sheath;
    response.Stats.RandomProperty = RandomProperty;
    response.Stats.RandomSuffix = RandomSuffix;
    response.Stats.Block = Block;
    response.Stats.ItemSet = ItemSet;
    response.Stats.MaxDurability = MaxDurability;
    response.Stats.Area = Area;
    response.Stats.Map = Map;
    response.Stats.BagFamily = BagFamily;
    response.Stats.TotemCategory = TotemCategory;

    for (uint8 s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
    {
        response.Stats.Socket[s].Color = Socket[s].Color;
        response.Stats.Socket[s].Content = Socket[s].Content;
    }

    response.Stats.SocketBonus = socketBonus;
    response.Stats.GemProperties = GemProperties;
    response.Stats.RequiredDisenchantSkill = RequiredDisenchantSkill;
    response.Stats.ArmorDamageModifier = ArmorDamageModifier;
    response.Stats.Duration = Duration;
    response.Stats.ItemLimitCategory = ItemLimitCategory;
    response.Stats.HolidayId = HolidayId;

    response.Write();
    response.ShrinkToFit();
    return response.Move();
}
