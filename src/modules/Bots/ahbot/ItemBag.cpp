#include "../botpch.h"
#include "Category.h"
#include "ItemBag.h"
#include "ConsumableCategory.h"
#include "TradeCategory.h"
#include "AhBotConfig.h"
#include "DBCStructure.h"
#include "Log.h"
#include "QueryResult.h"
#include "DatabaseEnv.h"
#include "SQLStorage.h"
#include "DBCStore.h"
#include "SQLStorages.h"
#include "AuctionHouseMgr.h"
#include "ObjectMgr.h"

using namespace ahbot;
char * strstri (const char* str1, const char* str2);

CategoryList CategoryList::instance;

CategoryList::CategoryList()
{
    Add(new Equip());
    Add(new Quiver());
    Add(new Container());
    Add(new Projectile());
    Add(new Recipe());
    Add(new Alchemy());
    Add(new Scroll());
    Add(new Food());
    Add(new Bandage());
    Add(new ItemEnchant());
    Add(new Reagent());
    Add(new ahbot::Quest());
    Add(new DevicesAndParts());

    Add(new TradeSkill(SKILL_TAILORING));
    Add(new TradeSkill(SKILL_LEATHERWORKING));
    Add(new TradeSkill(SKILL_ENGINEERING));
    Add(new TradeSkill(SKILL_BLACKSMITHING));
    Add(new TradeSkill(SKILL_ALCHEMY));
    Add(new TradeSkill(SKILL_ENCHANTING));
    Add(new TradeSkill(SKILL_FISHING));
    Add(new TradeSkill(SKILL_FIRST_AID));
    Add(new TradeSkill(SKILL_COOKING));
    Add(new TradeSkill(SKILL_MINING));
    Add(new TradeSkill(SKILL_HERBALISM));
    Add(new TradeSkill(SKILL_SKINNING));
#ifdef MANGOSBOT_ONE
    Add(new TradeSkill(SKILL_JEWELCRAFTING));
#endif
}

void CategoryList::Add(Category* category)
{
    for (uint32 quality = ITEM_QUALITY_NORMAL; quality <= ITEM_QUALITY_EPIC; ++quality)
        categories.push_back(new QualityCategoryWrapper(category, quality));
}

CategoryList::~CategoryList()
{
    for (vector<Category*>::const_iterator i = categories.begin(); i != categories.end(); ++i)
        delete *i;
}

ItemBag::ItemBag()
{
    for (int i = 0; i < CategoryList::instance.size(); i++)
    {
        content[CategoryList::instance[i]] = vector<uint32>();
    }
}

void ItemBag::Init(bool silent)
{
    if (silent)
    {
        Load();
        return;
    }

    sLog.outString("Loading/Scanning %s...", GetName().c_str());

    Load();

    for (int i = 0; i < CategoryList::instance.size(); i++)
    {
        Category* category = CategoryList::instance[i];
        Shuffle(content[category]);
        sLog.outString("loaded %d %s items", content[category].size(), category->GetDisplayName().c_str());
    }
}

int32 ItemBag::GetCount(Category* category, uint32 item)
{
    uint32 count = 0;

    vector<uint32>& items = content[category];
    for (vector<uint32>::iterator i = items.begin(); i != items.end(); ++i)
    {
        if (*i == item)
            count++;
    }

    return count;
}

bool ItemBag::Add(ItemPrototype const* proto)
{
    if (!proto ||
        proto->Bonding == BIND_WHEN_PICKED_UP ||
        proto->Bonding == BIND_QUEST_ITEM)
        return false;

    if (proto->RequiredLevel > sAhBotConfig.maxRequiredLevel || proto->ItemLevel > sAhBotConfig.maxItemLevel)
        return false;

    if (proto->Duration & 0x80000000)
        return false;

    if (sAhBotConfig.ignoreItemIds.find(proto->ItemId) != sAhBotConfig.ignoreItemIds.end())
        return false;

    if (strstri(proto->Name1, "qa") || strstri(proto->Name1, "test") || strstri(proto->Name1, "deprecated"))
        return false;

    bool contains = false;
    for (int i = 0; i < CategoryList::instance.size(); i++)
    {
        if (CategoryList::instance[i]->Contains(proto))
        {
            content[CategoryList::instance[i]].push_back(proto->ItemId);
            contains = true;
        }
    }

    if (!contains)
        sLog.outDetail("Item %s does not included in any category", proto->Name1);

    return contains;
}

void AvailableItemsBag::Load()
{
    set<uint32> vendorItems;

      QueryResult* results = WorldDatabase.PQuery("SELECT item FROM npc_vendor where maxcount = 0");
      if (results != NULL)
      {
          do
          {
              Field* fields = results->Fetch();
              vendorItems.insert(fields[0].GetUInt32());
          } while (results->NextRow());

          delete results;
      }

      BarGoLink bar(sItemStorage.GetMaxEntry());
      for (uint32 itemId = 0; itemId < sItemStorage.GetMaxEntry(); ++itemId)
      {
          if (vendorItems.find(itemId) == vendorItems.end() || sAhBotConfig.ignoreVendorItemIds.find(itemId) != sAhBotConfig.ignoreVendorItemIds.end())
              Add(sObjectMgr.GetItemPrototype(itemId));

          bar.step();
    }

}

void InAuctionItemsBag::Load()
{
    AuctionHouseEntry const* ahEntry = sAuctionHouseStore.LookupEntry(auctionId);
    if(!ahEntry)
        return;

    AuctionHouseObject* auctionHouse = sAuctionMgr.GetAuctionsMap(ahEntry);
    AuctionHouseObject::AuctionEntryMap const& auctionEntryMap = auctionHouse->GetAuctions();
    for (AuctionHouseObject::AuctionEntryMap::const_iterator itr = auctionEntryMap.begin(); itr != auctionEntryMap.end(); ++itr)
    {
        ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itr->second->itemTemplate);
        if (!proto)
            continue;

        Add(proto);
    }
}

string InAuctionItemsBag::GetName()
{
    ostringstream out; out << "auction house " << auctionId;
    return out.str();
}
