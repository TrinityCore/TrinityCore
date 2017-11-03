#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SellAction.h"
#include "../ItemVisitors.h"

using namespace ai;

class SellItemsVisitor : public IterateItemsVisitor
{
public:
    SellItemsVisitor(SellAction* action) : IterateItemsVisitor()
    {
        this->action = action;
    }

    virtual bool Visit(Item* item)
    {
        action->Sell(item);
        return true;
    }

private:
    SellAction* action;
};

class SellGrayItemsVisitor : public SellItemsVisitor
{
public:
    SellGrayItemsVisitor(SellAction* action) : SellItemsVisitor(action) {}

    virtual bool Visit(Item* item)
    {
        if (item->GetTemplate()->Quality != ITEM_QUALITY_POOR)
            return true;

        return SellItemsVisitor::Visit(item);
    }
};


bool SellAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    string text = event.getParam();

    if (text == "gray" || text == "*")
    {
        SellGrayItemsVisitor visitor(this);
        IterateItems(&visitor);
        return true;
    }

    ItemIds ids = chat->parseItems(text);

    for (ItemIds::iterator i =ids.begin(); i != ids.end(); i++)
    {
        FindItemByIdVisitor visitor(*i);
        Sell(&visitor);
    }

    return true;
}


void SellAction::Sell(FindItemVisitor* visitor)
{
    IterateItems(visitor);
    list<Item*> items = visitor->GetResult();
    for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
        Sell(*i);
}

void SellAction::Sell(Item* item)
{
    Player* master = GetMaster();
    Unit* vendor = master->GetSelectedUnit();
    if (!vendor)
    {
        ai->TellMaster("Select a vendor first");
        return;
    }

    ObjectGuid itemguid = item->GetGUID();
    uint32 count = item->GetCount();

    WorldPacket p;
    p << vendor->GetGUID() << itemguid << count;
    bot->GetSession()->HandleSellItemOpcode(p);

    ostringstream out; out << chat->formatItem(item->GetTemplate()) << " sold";
    ai->TellMaster(out);
}
