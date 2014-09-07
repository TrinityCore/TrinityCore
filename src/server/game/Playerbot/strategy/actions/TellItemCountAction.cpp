#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TellItemCountAction.h"
#include "../values/ItemCountValue.h"

using namespace ai;

bool TellItemCountAction::Execute(Event event)
{
    string text = event.getParam();
    list<Item*> found = parseItems(text);
    for (list<Item*>::iterator i = found.begin(); i != found.end(); i++)
        TellItem((*i)->GetTemplate(), (*i)->GetCount());

    return true;
}
