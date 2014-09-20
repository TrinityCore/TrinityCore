#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DestroyItemAction.h"

#include "../values/ItemCountValue.h"

using namespace ai;

bool DestroyItemAction::Execute(Event event)
{
    string text = event.getParam();
    ItemIds ids = chat->parseItems(text);

    for (ItemIds::iterator i =ids.begin(); i != ids.end(); i++)
    {
        FindItemByIdVisitor visitor(*i);
        DestroyItem(&visitor);
    }

    return true;
}

void DestroyItemAction::DestroyItem(FindItemVisitor* visitor)
{
    IterateItems(visitor);
    list<Item*> items = visitor->GetResult();
	for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
    {
		Item* item = *i;
        bot->DestroyItem(item->GetBagSlot(),item->GetSlot(), true);
        ostringstream out; out << chat->formatItem(item->GetTemplate()) << " destroyed";
        ai->TellMaster(out);
    }
}
