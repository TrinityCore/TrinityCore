#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "InventoryChangeFailureAction.h"


using namespace ai;

bool InventoryChangeFailureAction::Execute(Event event)
{
    WorldPacket p(event.getPacket());
    p.rpos(0);
    uint8 err;
    p >> err;
    if (err == EQUIP_ERR_OK)
        return false;

    switch (err)
    {
    case EQUIP_ERR_CANT_CARRY_MORE_OF_THIS:
		bot->Say("I can't carry anymore of those.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_MISSING_REAGENT:
		bot->Say("I'm missing some reagents for that.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_ITEM_LOCKED:
		bot->Say("That item is locked.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_ALREADY_LOOTED:
        break;
    case EQUIP_ERR_INVENTORY_FULL:
		bot->Say("My inventory is full.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_NOT_IN_COMBAT:
		bot->Say("I can't use that in combat.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW:
		bot->Say("I can't get that now.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE:
		bot->Say("I can only have one of those equipped.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_BANK_FULL:
		bot->Say("My bank is full.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_ITEM_NOT_FOUND:
		bot->Say("I can't find the item.", LANG_UNIVERSAL);
        break;
    case EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK:
		bot->Say("I'm too far from the bank.", LANG_UNIVERSAL);
        break;
    default:
		bot->Say("I can't use that.", LANG_UNIVERSAL);
    }
    return true;
}
