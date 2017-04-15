#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "BuyAction.h"
#include "../ItemVisitors.h"
#include "../values/ItemCountValue.h"

using namespace ai;

bool BuyAction::Execute(Event event)
{
    string link = event.getParam();

    ItemIds itemIds = chat->parseItems(link);
    if (itemIds.empty())
        return false;

    Player* master = GetMaster();

    if (!master)
        return false;

    Unit* vendor = master->GetSelectedUnit();
    if (!vendor)
        return false;

    Creature *pCreature = bot->GetNPCIfCanInteractWith(vendor->GetGUID(), UNIT_NPC_FLAG_VENDOR);
    if (!pCreature)
    {
		bot->Say("Cannot talk to vendor", LANG_UNIVERSAL);
        return false;
    }

    VendorItemData const* tItems = pCreature->GetVendorItems();
    if (!tItems)
    {
		bot->Say("This vendor has no items", LANG_UNIVERSAL);
        return false;
    }

    for (ItemIds::iterator i = itemIds.begin(); i != itemIds.end(); i++)
    {
        for (uint32 slot = 0; slot < tItems->GetItemCount(); slot++)
        {
            if (tItems->GetItem(slot)->item == *i)
            {
                bot->BuyItemFromVendorSlot(vendor->GetGUID(), slot, *i, 1, NULL_BAG, NULL_SLOT);
                ai->TellMaster("Bought item");
            }
        }
    }

    return true;
}
