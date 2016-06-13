#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "UnequipAction.h"

#include "../values/ItemCountValue.h"

using namespace ai;

bool UnequipAction::Execute(Event event)
{
    string text = event.getParam();

    ItemIds ids = chat->parseItems(text);
    for (ItemIds::iterator i =ids.begin(); i != ids.end(); i++)
    {
        FindItemByIdVisitor visitor(*i);
        UnequipItem(&visitor);
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


    WorldPacket* const packet = new WorldPacket(CMSG_AUTOSTORE_BAG_ITEM, 3);
    *packet << bagIndex << slot << dstBag;
    bot->GetSession()->QueuePacket(packet);

    ostringstream out; out << chat->formatItem(item.GetTemplate()) << " unequipped";
    ai->TellMaster(out);
}

