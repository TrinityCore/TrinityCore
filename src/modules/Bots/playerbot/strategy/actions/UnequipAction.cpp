#include "botpch.h"
#include "../../playerbot.h"
#include "UnequipAction.h"

#include "../values/ItemCountValue.h"

using namespace ai;

vector<string> split(const string &s, char delim);

bool UnequipAction::Execute(Event event)
{
    string text = event.getParam();

    ItemIds ids = chat->parseItems(text);
    if (ids.empty())
    {
        vector<string> names = split(text, ',');
        for (vector<string>::iterator i = names.begin(); i != names.end(); ++i)
        {
            uint32 slot = chat->parseSlot(*i);
            if (slot != EQUIPMENT_SLOT_END)
            {
                Item* const pItem = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
                if (pItem) UnequipItem(*pItem);
            }
        }
    }
    else
    {
        for (ItemIds::iterator i =ids.begin(); i != ids.end(); i++)
        {
            FindItemByIdVisitor visitor(*i);
            UnequipItem(&visitor);
        }
    }

    return true;
}


void UnequipAction::UnequipItem(FindItemVisitor* visitor)
{
    IterateItems(visitor, ITERATE_ALL_ITEMS);
    list<Item*> items = visitor->GetResult();
	if (!items.empty()) UnequipItem(**items.begin());
}

void UnequipAction::UnequipItem(Item& item)
{
    uint8 bagIndex = item.GetBagSlot();
    uint8 slot = item.GetSlot();
    uint8 dstBag = NULL_BAG;


    WorldPacket packet(CMSG_AUTOSTORE_BAG_ITEM, 3);
    packet << bagIndex << slot << dstBag;
    bot->GetSession()->HandleAutoStoreBagItemOpcode(packet);

    ostringstream out; out << chat->formatItem(item.GetProto()) << " unequipped";
    ai->TellMaster(out);
}

