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

/*static*/ ItemTemplate& UnitTestDataLoader::GetItemTemplate(uint32 itemId, std::string_view name)
{
    ItemTemplate& t = sObjectMgr->_itemTemplateStore[itemId];
    t.ItemId = itemId;
    t.Class = ItemClass::ITEM_CLASS_MISC;
    t.SubClass = 0;
    t.SoundOverrideSubclass = -1;
    t.Name1 = name;
    t.DisplayInfoID = 0;
    t.Quality = ItemQualities::ITEM_QUALITY_ARTIFACT;
    t.Flags = 0;
    t.Flags2 = 0;
    t.BuyCount = 1;
    t.BuyPrice = 0;
    t.SellPrice = 0;
    t.InventoryType = InventoryType::INVTYPE_NON_EQUIP;
    t.AllowableClass = static_cast<uint32>(-1);
    t.AllowableRace = static_cast<uint32>(-1);
    t.ItemLevel = 1;
    t.RequiredLevel = 0;
    t.RequiredSkill = 0;
    t.RequiredSkillRank = 0;
    t.RequiredSpell = 0;
    t.RequiredHonorRank = 0;
    t.RequiredCityRank = 0;
    t.RequiredReputationFaction = 0;
    t.RequiredReputationRank = 0;
    t.MaxCount = 0;
    t.Stackable = 1;
    t.ContainerSlots = 0;
    t.StatsCount = 0;
    t.ItemStat = {};
    t.ScalingStatDistribution = 0;
    t.ScalingStatValue = 0;
    t.Damage = {};
    t.Armor = 0;
    t.HolyRes = 0;
    t.FireRes = 0;
    t.NatureRes = 0;
    t.FrostRes = 0;
    t.ShadowRes = 0;
    t.ArcaneRes = 0;
    t.Delay = 0;
    t.AmmoType = 0;
    t.RangedModRange = 0.0f;
    t.Spells = {};
    t.Bonding = ItemBondingType::NO_BIND;
    t.Description = "";
    t.PageText = 0;
    t.LanguageID = 0;
    t.PageMaterial = 0;
    t.StartQuest = 0;
    t.LockID = 0;
    t.Material = static_cast<uint32>(-1);
    t.Sheath = 0;
    t.RandomProperty = 0;
    t.RandomSuffix = 0;
    t.Block = 0;
    t.ItemSet = 0;
    t.MaxDurability = 0;
    t.Area = 0;
    t.Map = 0;
    t.BagFamily = 0;
    t.TotemCategory = 0;
    t.Socket = {};
    t.socketBonus = 0;
    t.GemProperties = 0;
    t.RequiredDisenchantSkill = static_cast<uint32>(-1);
    t.ArmorDamageModifier = 0.0;
    t.Duration = 0;
    t.ItemLevel = 0;
    t.HolidayId = 0;
    t.ScriptId = 0;
    t.DisenchantID = 0;
    t.FoodType = 0;
    t.MinMoneyLoot = 0;
    t.MaxMoneyLoot = 0;

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
    auto loader = achievements.Loader();

    AchievementEntry& toc5 = loader.Add();
    toc5.ID = 4298;
    toc5.Faction = 1;
    toc5.InstanceID = 650;
    toc5.Title.fill("");
    toc5.Title[LOCALE_enUS] = "Heroic: Trial of the Champion";
    toc5.Title[LOCALE_esES] = "Heroico: Prueba del Campe\xc3\xb3n";
    toc5.Category = 14921;
    toc5.Points = 10;
    toc5.Flags = 0;
    toc5.MinimumCriteria = 0;
    toc5.SharesCriteria = 0;
}
