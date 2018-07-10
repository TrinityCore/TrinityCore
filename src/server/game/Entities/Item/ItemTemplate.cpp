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
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Packets/QueryPackets.h"


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


void ItemTemplate::InitializeQueryData(LocaleConstant lc)
{
    _response[lc] = new WorldPackets::Query::QueryItemSingleResponse();
    BuildQueryData(lc);
    _response[lc]->Write();
}

WorldPacket* ItemTemplate::GetQueryDataRef(LocaleConstant lc)
{
    if (!_response[lc])
    {
        GetQueryData(lc);
    }
    return (WorldPacket*)_response[lc]->GetRawPacket();
}

WorldPacket ItemTemplate::GetQueryData(LocaleConstant lc)
{
    if (!_response[lc])
    {
        _response[lc] = new WorldPackets::Query::QueryItemSingleResponse();
        BuildQueryData(lc);
    }
    const WorldPacket* wp = _response[lc]->Write();
    return *wp;
}

void ItemTemplate::BuildQueryData(LocaleConstant lc) const
{
    if (lc == LOCALE_enUS)
    {
        _response[lc]->Stats.Name = Name1;
        _response[lc]->Stats.Description = Description;
    }
    else if (ItemLocale const* il = sObjectMgr->GetItemLocale(ItemId))
    {
        ObjectMgr::GetLocaleString(il->Name, lc, _response[lc]->Stats.Name);
        ObjectMgr::GetLocaleString(il->Description, lc, _response[lc]->Stats.Description);
    }

    _response[lc]->ItemID = ItemId;
    _response[lc]->Allow = true;

    _response[lc]->Stats.Class = Class;
    _response[lc]->Stats.SubClass = SubClass;
    _response[lc]->Stats.SoundOverrideSubclass = SoundOverrideSubclass;
    _response[lc]->Stats.DisplayInfoID = DisplayInfoID;
    _response[lc]->Stats.Quality = Quality;
    _response[lc]->Stats.Flags = Flags;
    _response[lc]->Stats.Flags2 = Flags2;
    _response[lc]->Stats.BuyPrice = BuyPrice;
    _response[lc]->Stats.SellPrice = SellPrice;
    _response[lc]->Stats.InventoryType = InventoryType;
    _response[lc]->Stats.AllowableClass = AllowableClass;
    _response[lc]->Stats.AllowableRace = AllowableRace;
    _response[lc]->Stats.ItemLevel = ItemLevel;
    _response[lc]->Stats.RequiredLevel = RequiredLevel;
    _response[lc]->Stats.RequiredSkill = RequiredSkill;
    _response[lc]->Stats.RequiredSkillRank = RequiredSkillRank;
    _response[lc]->Stats.RequiredSpell = RequiredSpell;
    _response[lc]->Stats.RequiredHonorRank = RequiredHonorRank;
    _response[lc]->Stats.RequiredCityRank = RequiredCityRank;
    _response[lc]->Stats.RequiredReputationFaction = RequiredReputationFaction;
    _response[lc]->Stats.RequiredReputationRank = RequiredReputationRank;
    _response[lc]->Stats.MaxCount = MaxCount;
    _response[lc]->Stats.Stackable = Stackable;
    _response[lc]->Stats.ContainerSlots = ContainerSlots;
    _response[lc]->Stats.StatsCount = StatsCount;
    for (uint32 i = 0; i < StatsCount; ++i)
    {
        _response[lc]->Stats.ItemStat[i].ItemStatType = ItemStat[i].ItemStatType;
        _response[lc]->Stats.ItemStat[i].ItemStatValue = ItemStat[i].ItemStatValue;
    }

    _response[lc]->Stats.ScalingStatDistribution = ScalingStatDistribution;
    _response[lc]->Stats.ScalingStatValue = ScalingStatValue;

    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        _response[lc]->Stats.Damage[i].DamageMin = Damage[i].DamageMin;
        _response[lc]->Stats.Damage[i].DamageMax = Damage[i].DamageMax;
        _response[lc]->Stats.Damage[i].DamageType = Damage[i].DamageType;
    }

    _response[lc]->Stats.Resistance[SPELL_SCHOOL_NORMAL] = Armor;
    _response[lc]->Stats.Resistance[SPELL_SCHOOL_HOLY] = HolyRes;
    _response[lc]->Stats.Resistance[SPELL_SCHOOL_FIRE] = FireRes;
    _response[lc]->Stats.Resistance[SPELL_SCHOOL_NATURE] = NatureRes;
    _response[lc]->Stats.Resistance[SPELL_SCHOOL_FROST] = FrostRes;
    _response[lc]->Stats.Resistance[SPELL_SCHOOL_SHADOW] = ShadowRes;
    _response[lc]->Stats.Resistance[SPELL_SCHOOL_ARCANE] = ArcaneRes;

    _response[lc]->Stats.Delay = Delay;
    _response[lc]->Stats.AmmoType = AmmoType;
    _response[lc]->Stats.RangedModRange = RangedModRange;

    for (uint8 s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
    {
        _response[lc]->Stats.Spells[s].SpellId = Spells[s].SpellId;
        _response[lc]->Stats.Spells[s].SpellTrigger = Spells[s].SpellTrigger;
        _response[lc]->Stats.Spells[s].SpellCharges = Spells[s].SpellCharges;
        _response[lc]->Stats.Spells[s].SpellCooldown = Spells[s].SpellCooldown;
        _response[lc]->Stats.Spells[s].SpellCategory = Spells[s].SpellCategory;
        _response[lc]->Stats.Spells[s].SpellCategoryCooldown = Spells[s].SpellCategoryCooldown;
    }

    _response[lc]->Stats.Bonding = Bonding;
    _response[lc]->Stats.PageText = PageText;
    _response[lc]->Stats.LanguageID = LanguageID;
    _response[lc]->Stats.PageMaterial = PageMaterial;
    _response[lc]->Stats.StartQuest = StartQuest;
    _response[lc]->Stats.LockID = LockID;
    _response[lc]->Stats.Material = Material;
    _response[lc]->Stats.Sheath = Sheath;
    _response[lc]->Stats.RandomProperty = RandomProperty;
    _response[lc]->Stats.RandomSuffix = RandomSuffix;
    _response[lc]->Stats.Block = Block;
    _response[lc]->Stats.ItemSet = ItemSet;
    _response[lc]->Stats.MaxDurability = MaxDurability;
    _response[lc]->Stats.Area = Area;
    _response[lc]->Stats.Map = Map;
    _response[lc]->Stats.BagFamily = BagFamily;
    _response[lc]->Stats.TotemCategory = TotemCategory;

    for (uint8 s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
    {
        _response[lc]->Stats.Socket[s].Color = Socket[s].Color;
        _response[lc]->Stats.Socket[s].Content = Socket[s].Content;
    }

    _response[lc]->Stats.SocketBonus = socketBonus;
    _response[lc]->Stats.GemProperties = GemProperties;
    _response[lc]->Stats.RequiredDisenchantSkill = RequiredDisenchantSkill;
    _response[lc]->Stats.ArmorDamageModifier = ArmorDamageModifier;
    _response[lc]->Stats.Duration = Duration;
    _response[lc]->Stats.ItemLimitCategory = ItemLimitCategory;
    _response[lc]->Stats.HolidayId = HolidayId;
}
