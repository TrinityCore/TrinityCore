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

#include "DummyData.h"

#include "AchievementMgr.h"
#include "ItemDefines.h"
#include "ItemTemplate.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

/*static*/ ItemTemplate& UnitTestDataLoader::GetItemTemplate(uint32 itemId, std::string_view name)
{
    ItemTemplate& t = sObjectMgr->_itemTemplateStore[itemId];
    t = {};
    t.ItemId = itemId;
    t.Class = ItemClass::ITEM_CLASS_MISC;
    t.SoundOverrideSubclass = -1;
    t.Name1 = name;
    t.Quality = ItemQualities::ITEM_QUALITY_ARTIFACT;
    t.BuyCount = 1;
    t.AllowableClass = static_cast<uint32>(-1);
    t.AllowableRace = static_cast<uint32>(-1);
    t.ItemLevel = 1;
    t.Stackable = 1;
    t.Material = static_cast<uint32>(-1);
    t.RequiredDisenchantSkill = static_cast<uint32>(-1);

    return t;
}

/*static*/ void UnitTestDataLoader::SetItemLocale(uint32 id, LocaleConstant locale, std::string_view name)
{
    size_t const i = static_cast<size_t>(locale);
    ItemLocale& localeData = sObjectMgr->_itemLocaleStore[id];
    if (localeData.Name.size() <= i)
        localeData.Name.resize(i + 1);
    localeData.Name[i] = name;
}

static UnitTestDataLoader::DBC<ItemRandomPropertiesEntry, &ItemRandomPropertiesEntry::ID> randomProperties(sItemRandomPropertiesStore);
static UnitTestDataLoader::DBC<ItemRandomSuffixEntry, &ItemRandomSuffixEntry::ID> randomSuffixes(sItemRandomSuffixStore);
/*static*/ void UnitTestDataLoader::LoadItemTemplates()
{
    if (!sObjectMgr->_itemTemplateStore.empty())
        return;

    ItemTemplate& hearthstone = GetItemTemplate(6948, "Hearthstone");
    hearthstone.DisplayInfoID = 6418;
    hearthstone.Quality = ItemQualities::ITEM_QUALITY_NORMAL;
    hearthstone.Flags = ItemFlags::ITEM_FLAG_PLAYERCAST;
    hearthstone.MaxCount = 1;
    hearthstone.Spells[0].SpellId = 8690;
    hearthstone.Bonding = ItemBondingType::BIND_WHEN_PICKED_UP;
    SetItemLocale(6948, LocaleConstant::LOCALE_esES, "Piedra de hogar");

    ItemTemplate& niceHat = GetItemTemplate(10250, "Master's Hat");
    niceHat.Class = ItemClass::ITEM_CLASS_ARMOR;
    niceHat.SubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_CLOTH;
    niceHat.DisplayInfoID = 27824;
    niceHat.Quality = ItemQualities::ITEM_QUALITY_UNCOMMON;
    niceHat.BuyCount = 1;
    niceHat.BuyPrice = 66902;
    niceHat.SellPrice = 13380;
    niceHat.InventoryType = InventoryType::INVTYPE_HEAD;
    niceHat.ItemLevel = 63;
    niceHat.RequiredLevel = 58;
    niceHat.Armor = 66;
    niceHat.Bonding = ItemBondingType::BIND_WHEN_EQUIPED;
    niceHat.Material = 7;
    niceHat.RandomProperty = 639;
    niceHat.MaxDurability = 45;
    niceHat.RequiredDisenchantSkill = 225;
    niceHat.DisenchantID = 11;
    SetItemLocale(10250, LocaleConstant::LOCALE_esES, "Sombrero de maestro");

    ItemTemplate& vikingShield = GetItemTemplate(36449, "Vrykul Shield");
    vikingShield.Class = ItemClass::ITEM_CLASS_ARMOR;
    vikingShield.SubClass = ItemSubclassArmor::ITEM_SUBCLASS_ARMOR_SHIELD;
    vikingShield.DisplayInfoID = 52191;
    vikingShield.Quality = ItemQualities::ITEM_QUALITY_UNCOMMON;
    vikingShield.BuyCount = 1;
    vikingShield.BuyPrice = 300510;
    vikingShield.SellPrice = 60102;
    vikingShield.InventoryType = InventoryType::INVTYPE_SHIELD;
    vikingShield.ItemLevel = 146;
    vikingShield.RequiredLevel = 71;
    vikingShield.Armor = 4476;
    vikingShield.Bonding = ItemBondingType::BIND_WHEN_EQUIPED;
    vikingShield.Material = 1;
    vikingShield.Sheath = 4;
    vikingShield.RandomSuffix = 82;
    vikingShield.Block = 138;
    vikingShield.MaxDurability = 85;
    vikingShield.RequiredDisenchantSkill = 325;
    vikingShield.DisenchantID = 34;
    SetItemLocale(36449, LOCALE_esES, "Escudo vrykul");

    for (auto& [id, data] : sObjectMgr->_itemTemplateStore)
        data.InitializeQueryData();

    auto propLoader = randomProperties.Loader();
    ItemRandomPropertiesEntry& fieryWrath = propLoader.Add();
    fieryWrath.ID = 1902;
    fieryWrath.Enchantment = {};
    fieryWrath.Enchantment[0] = 2182;
    fieryWrath.Name.fill("");
    fieryWrath.Name[LOCALE_enUS] = "of Fiery Wrath";
    fieryWrath.Name[LOCALE_esES] = "de c\xc3\xb3lera \xc3\xadgnea";

    auto suffixLoader = randomSuffixes.Loader();
    ItemRandomSuffixEntry& champion = suffixLoader.Add();
    champion.ID = 45;
    champion.Name.fill("");
    champion.Name[LOCALE_enUS] = "of the Champion";
    champion.Name[LOCALE_esES] = "del Campe\xc3\xb3n";
    champion.Enchantment[0] = 2805;
    champion.Enchantment[1] = 2803;
    champion.Enchantment[2] = 2813;
    champion.AllocationPct[0] = 5259;
    champion.AllocationPct[1] = 7889;
    champion.AllocationPct[2] = 5259;
}

static UnitTestDataLoader::DBC<AchievementEntry, &AchievementEntry::ID> achievements(sAchievementStore);
/*static*/ void UnitTestDataLoader::LoadAchievementTemplates()
{
    if (!achievements.Empty())
        return;

    auto loader = achievements.Loader();

    AchievementEntry& toc5 = loader.Add();
    toc5 = {};
    toc5.ID = 4298;
    toc5.Faction = 1;
    toc5.InstanceID = 650;
    toc5.Title.fill("");
    toc5.Title[LOCALE_enUS] = "Heroic: Trial of the Champion";
    toc5.Title[LOCALE_esES] = "Heroico: Prueba del Campe\xc3\xb3n";
    toc5.Category = 14921;
    toc5.Points = 10;
}

static UnitTestDataLoader::DBC<SpellEntry, &SpellEntry::ID> spells(sSpellStore);
static UnitTestDataLoader::DBC<TalentEntry, &TalentEntry::ID> talents(sTalentStore);
/*static*/ void UnitTestDataLoader::LoadSpellInfo()
{
    if (!sSpellMgr->mSpellInfoMap.empty())
        return;

    {
        auto spellLoader = spells.Loader();
        SpellEntry& tidalWaves1 = spellLoader.Add();
        tidalWaves1 = {};
        tidalWaves1.ID = 51562;
        tidalWaves1.Attributes = 464;
        tidalWaves1.AttributesExC = 524288;
        tidalWaves1.CastingTimeIndex = 1;
        tidalWaves1.ProcTypeMask = 17408;
        tidalWaves1.ProcChance = 20;
        tidalWaves1.SpellLevel = 1;
        tidalWaves1.RangeIndex = 1;
        tidalWaves1.EquippedItemClass = -1;
        tidalWaves1.Effect = { 6,6,6 };
        tidalWaves1.EffectDieSides = { 1,1,1 };
        tidalWaves1.EffectBasePoints = { 19,3,1 };
        tidalWaves1.EffectImplicitTargetA = { 1,1,1 };
        tidalWaves1.EffectAura = { 42, 107, 107 };
        tidalWaves1.EffectMiscValue = { 7,24,24 };
        tidalWaves1.EffectTriggerSpell = { 53390 };
        tidalWaves1.EffectSpellClassMask = { { { 192, 8192, 0}, { 64, 0, 0 }, { 128, 0, 0 } } };
        tidalWaves1.SpellIconID = 3057;
        tidalWaves1.SpellPriority = 50;
        tidalWaves1.Name.fill("");
        tidalWaves1.Name[LOCALE_enUS] = "Tidal Waves";
        tidalWaves1.Name[LOCALE_esES] = "Maremotos";
        tidalWaves1.NameSubtext.fill("");
        tidalWaves1.NameSubtext[LOCALE_enUS] = "Rank 1";
        tidalWaves1.NameSubtext[LOCALE_esES] = "Rango 1";
        tidalWaves1.SpellClassSet = 11;
        tidalWaves1.EffectChainAmplitude.fill(1.0);
        tidalWaves1.SchoolMask = 1;

        SpellEntry& tidalWaves2 = spellLoader.Add();
        tidalWaves2 = tidalWaves1;
        tidalWaves2.ID = 51563;
        tidalWaves2.ProcChance = 40;
        tidalWaves2.EffectBasePoints = { 39,7,3 };
        tidalWaves2.NameSubtext[LOCALE_enUS] = "Rank 2";
        tidalWaves2.NameSubtext[LOCALE_esES] = "Rango 2";

        SpellEntry& tidalWaves3 = spellLoader.Add();
        tidalWaves3 = tidalWaves1;
        tidalWaves3.ID = 51564;
        tidalWaves3.ProcChance = 60;
        tidalWaves3.EffectBasePoints = { 59, 11, 5 };
        tidalWaves3.NameSubtext[LOCALE_enUS] = "Rank 3";
        tidalWaves3.NameSubtext[LOCALE_esES] = "Rango 3";

        SpellEntry& tidalWaves4 = spellLoader.Add();
        tidalWaves4 = tidalWaves1;
        tidalWaves4.ID = 51565;
        tidalWaves4.ProcChance = 80;
        tidalWaves4.EffectBasePoints = { 79, 15, 7 };
        tidalWaves4.NameSubtext[LOCALE_enUS] = "Rank 4";
        tidalWaves4.NameSubtext[LOCALE_esES] = "Rango 4";

        SpellEntry& tidalWaves5 = spellLoader.Add();
        tidalWaves5 = tidalWaves1;
        tidalWaves5.ID = 51566;
        tidalWaves5.ProcChance = 100;
        tidalWaves5.EffectBasePoints = { 99, 19, 9 };
        tidalWaves5.NameSubtext[LOCALE_enUS] = "Rank 5";
        tidalWaves5.NameSubtext[LOCALE_esES] = "Rango 5";

        SpellEntry& earthShield1 = spellLoader.Add();
        earthShield1 = {};
        earthShield1.ID = 974;
        earthShield1.Category = 1195;
        earthShield1.DispelType = 1;
        earthShield1.Attributes = 327680;
        earthShield1.AttributesExD = 524288;
        earthShield1.AttributesExE = 32;
        earthShield1.AttributesExF = 67108864;
        earthShield1.AttributesExG = 1073742848;
        earthShield1.CastingTimeIndex = 1;
        earthShield1.AuraInterruptFlags = 524288;
        earthShield1.ProcTypeMask = 172712;
        earthShield1.ProcChance = 100;
        earthShield1.ProcCharges = 6;
        earthShield1.MaxLevel = 59;
        earthShield1.BaseLevel = 50;
        earthShield1.SpellLevel = 50;
        earthShield1.DurationIndex = 6;
        earthShield1.RangeIndex = 5;
        earthShield1.Effect = { 6,6,0 };
        earthShield1.EffectDieSides = { 1,1,0 };
        earthShield1.EffectBasePoints = { 149,29,0 };
        earthShield1.EffectImplicitTargetA = { 21,21,0 };
        earthShield1.EffectAura = { 4,149,0 };
        earthShield1.EffectMiscValue = { 0,126,0 };
        earthShield1.SpellVisualID = { 7362,0 };
        earthShield1.SpellIconID = 2015;
        earthShield1.Name.fill("");
        earthShield1.Name[LOCALE_enUS] = "Earth Shield";
        earthShield1.Name[LOCALE_esES] = "Escudo de tierra";
        earthShield1.NameSubtext = tidalWaves1.NameSubtext;
        earthShield1.ManaCostPct = 15;
        earthShield1.StartRecoveryCategory = 133;
        earthShield1.StartRecoveryTime = 1500;
        earthShield1.SpellClassSet = 11;
        earthShield1.SpellClassMask = { 0, 1024, 0 };
        earthShield1.DefenseType = 1;
        earthShield1.PreventionType = 1;
        earthShield1.EffectChainAmplitude.fill(1.0);
        earthShield1.SchoolMask = 8;
        earthShield1.EffectBonusCoefficient = { 1.0, 0.0, 1.0 };

        SpellEntry& impEarthShield1 = spellLoader.Add();
        impEarthShield1 = {};
        impEarthShield1.ID = 51560;
        impEarthShield1.Attributes = 464;
        impEarthShield1.CastingTimeIndex = 1;
        impEarthShield1.ProcChance = 101;
        impEarthShield1.RangeIndex = 1;
        impEarthShield1.EquippedItemClass = -1;
        impEarthShield1.Effect = { 6,6,0 };
        impEarthShield1.EffectDieSides = { 1,1,0 };
        impEarthShield1.EffectBasePoints = { 0,4,0 };
        impEarthShield1.EffectImplicitTargetA = { 1,1,0 };
        impEarthShield1.EffectAura = { 107,108,0 };
        impEarthShield1.EffectMiscValue = { 4,3,0 };
        impEarthShield1.EffectMiscValueB = { 3,0,0 };
        impEarthShield1.EffectSpellClassMask = { { {0,1024,0}, {0,1024,0}, {0,0,0} } };
        impEarthShield1.SpellIconID = 2015;
        impEarthShield1.Name.fill("");
        impEarthShield1.Name[LOCALE_enUS] = "Improved Earth Shield";
        impEarthShield1.Name[LOCALE_esES] = "Escudo de tierra mejorado";
        impEarthShield1.NameSubtext = tidalWaves1.NameSubtext;
        impEarthShield1.SpellClassSet = 11;
        impEarthShield1.EffectChainAmplitude.fill(1.0);
        impEarthShield1.SchoolMask = 1;
        impEarthShield1.EffectBonusCoefficient = { 0.0, 0.0, 1.0 };

        SpellEntry& impEarthShield2 = spellLoader.Add();
        impEarthShield2 = impEarthShield1;
        impEarthShield2.ID = 51561;
        impEarthShield2.EffectBasePoints = { 1,9,0 };
        impEarthShield2.NameSubtext = tidalWaves2.NameSubtext;

        auto talentLoader = talents.Loader();
        TalentEntry& tidalWaves = talentLoader.Add();
        tidalWaves.ID = 2063;
        tidalWaves.TabID = 262;
        tidalWaves.TierID = 9;
        tidalWaves.ColumnIndex = 1;
        tidalWaves.SpellRank = { 51562, 51563, 51564, 51565, 51566 };
        tidalWaves.PrereqTalent = 0;
        tidalWaves.PrereqRank = 0;

        TalentEntry& earthShield = talentLoader.Add();
        earthShield.ID = 1698;
        earthShield.TabID = 262;
        earthShield.TierID = 8;
        earthShield.ColumnIndex = 1;
        earthShield.SpellRank = { 974,0,0,0,0 };
        earthShield.PrereqTalent = 0;
        earthShield.PrereqRank = 2;

        TalentEntry& impEarthShield = talentLoader.Add();
        impEarthShield.ID = 2059;
        impEarthShield.TabID = 262;
        impEarthShield.TierID = 8;
        impEarthShield.ColumnIndex = 2;
        impEarthShield.SpellRank = { 51560, 51561, 0, 0, 0 };
        impEarthShield.PrereqTalent = 1698;
        impEarthShield.PrereqRank = 0;
    }

    // this needs to be after the loader destructors
    sSpellMgr->LoadSpellInfoStore();
}
