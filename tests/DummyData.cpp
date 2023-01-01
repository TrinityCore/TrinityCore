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

#include "DB2Stores.h"
#include "ItemDefines.h"
#include "ItemTemplate.h"
#include "ObjectMgr.h"

/*static*/ ItemTemplate& UnitTestDataLoader::GetItemTemplate(uint32 itemId, std::string_view name)
{
    ItemTemplate& t = sObjectMgr->_itemTemplateStore[itemId];
    ItemEntry* itemEntry = new ItemEntry();
    memset(itemEntry, 0, sizeof(ItemEntry));
    itemEntry->ID = itemId;
    itemEntry->ClassID = ITEM_CLASS_MISCELLANEOUS;
    t.BasicData = itemEntry;

    ItemSparseEntry* itemSparse = new ItemSparseEntry();
    itemSparse->ID = itemId;
    for (char const*& display : itemSparse->Display.Str)
        display = "";
    itemSparse->Display.Str[LOCALE_enUS] = name.data();
    itemSparse->OverallQualityID = ITEM_QUALITY_ARTIFACT;
    t.ExtendedData = itemSparse;

    return t;
}

/*static*/ void UnitTestDataLoader::SetItemLocale(uint32 id, LocaleConstant locale, std::string_view name)
{
    ItemTemplate& t = sObjectMgr->_itemTemplateStore[id];
    const_cast<ItemSparseEntry*>(t.ExtendedData)->Display.Str[locale] = name.data();
}

/*static*/ void UnitTestDataLoader::LoadItemTemplates()
{
    if (!sObjectMgr->_itemTemplateStore.empty())
        return;

    ItemTemplate& t = GetItemTemplate(6948, "Hearthstone");
    const_cast<ItemSparseEntry*>(t.ExtendedData)->OverallQualityID = ITEM_QUALITY_NORMAL;
    SetItemLocale(6948, LOCALE_esMX, "Piedra de hogar");
}

static UnitTestDataLoader::DB2<AchievementEntry, &AchievementEntry::ID> achievements(sAchievementStore);
/*static*/ void UnitTestDataLoader::LoadAchievementTemplates()
{
    auto loader = achievements.Loader();

    AchievementEntry& toc5 = loader.Add();
    toc5.ID = 4298;
    toc5.Faction = 1;
    toc5.InstanceID = 650;
    toc5.Title.Str.fill("");
    toc5.Title.Str[LOCALE_enUS] = "Heroic: Trial of the Champion";
    toc5.Title.Str[LOCALE_esES] = "Heroico: Prueba del Campe\xc3\xb3n";
    toc5.Title.Str[LOCALE_esMX] = "Heroico: Prueba del Campe\xc3\xb3n";
    toc5.Category = 14921;
    toc5.Points = 10;
    toc5.Flags = 0;
    toc5.MinimumCriteria = 0;
    toc5.SharesCriteria = 0;
}
