#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "EquipAction.h"
#include "WorldSession.h"
#include "EquipmentSet.h"
#include "../values/ItemCountValue.h"
#include "Item.h"

using namespace ai;

bool EquipAction::Execute(Event event)
{
    string text = event.getParam();
    if (text == "?")
    {
        TellEquipmentSets();
        return true;
    }

    if (UseEquipmentSet(text))
        return true;

    ItemIds ids = chat->parseItems(text);

    for (ItemIds::iterator i =ids.begin(); i != ids.end(); i++)
    {
        FindItemByIdVisitor visitor(*i);
        EquipItem(&visitor);
    }

    return true;
}

bool EquipAction::UseEquipmentSet(string& name)
{
    EquipmentSetContainer &sets = bot->GetEquipmentSets();
    for (EquipmentSetContainer::iterator i = sets.begin(); i != sets.end(); i++)
    {
        if (i->second.State == EQUIPMENT_SET_DELETED)
            continue;

        UseEquipmentSet(name);

        ostringstream out; out << name << " set equipped";
        ai->TellMaster(out);
        return true;
    }
    return false;
}

bool EquipAction::UseEquipmentSet(EquipmentSetContainer& set)
{
    WorldPacket* p = new WorldPacket(CMSG_EQUIPMENT_SET_USE);
    uint8 srcbag = 0;
    for(uint8 slot = 0; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        ObjectGuid guid;
        //uint32 itemId = set.Items[slot];
        if (1 << slot)
            p->appendPackGUID((uint64(1)));
        else
            p->appendPackGUID((uint64(1)));
        *p << srcbag << slot;
    }
    bot->GetSession()->QueuePacket(p);
    return true;
}

void EquipAction::TellEquipmentSets()
{
    ai->TellMaster("=== Equipment sets ===");
    EquipmentSetContainer &sets = bot->GetEquipmentSets();
    for (EquipmentSetContainer::iterator i = sets.begin(); i != sets.end(); i++)
    {
        if (i->second.State != EQUIPMENT_SET_DELETED)
            ai->TellMaster(name);
    }
}

void EquipAction::EquipItem(FindItemVisitor* visitor)
{
    IterateItems(visitor);
    list<Item*> items = visitor->GetResult();
    if (!items.empty()) EquipItem(**items.begin());
}


void EquipAction::EquipItem(Item& item)
{
    uint8 bagIndex = item.GetBagSlot();
    uint8 slot = item.GetSlot();
    uint32 itemId = item.GetTemplate()->ItemId;

    if (item.GetTemplate()->InventoryType == INVTYPE_AMMO)
    {
        bot->SetAmmo(itemId);
    }
    else
    {
        WorldPacket* const packet = new WorldPacket(CMSG_AUTOEQUIP_ITEM, 2);
            *packet << bagIndex << slot;
        bot->GetSession()->QueuePacket(packet);
    }

    ostringstream out; out << "equipping " << chat->formatItem(item.GetTemplate());
    ai->TellMaster(out);
}
