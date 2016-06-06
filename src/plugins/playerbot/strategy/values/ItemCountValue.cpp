#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ItemCountValue.h"

using namespace ai;

list<Item*> InventoryItemValueBase::Find(string qualifier)
{
    list<Item*> result;

    Player* bot = InventoryAction::ai->GetBot();

    list<Item*> items = InventoryAction::parseItems(qualifier);
    for (list<Item*>::iterator i = items.begin(); i != items.end(); i++)
        result.push_back(*i);

    return result;
}


uint8 ItemCountValue::Calculate()
{
    uint8 count = 0;
    list<Item*> items = Find(qualifier);
    for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
    {
        Item* item = *i;
        count += item->GetCount();
    }

    return count;
}

list<Item*> InventoryItemValue::Calculate()
{
    return Find(qualifier);
}
