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
        ai->TellMaster("I can't carry anymore of those.");
        break;
    case EQUIP_ERR_MISSING_REAGENT:
        ai->TellMaster("I'm missing some reagents for that.");
        break;
    case EQUIP_ERR_ITEM_LOCKED:
        ai->TellMaster("That item is locked.");
        break;
    case EQUIP_ERR_ALREADY_LOOTED:
        break;
    case EQUIP_ERR_INVENTORY_FULL:
        ai->TellMaster("My inventory is full.");
        break;
    case EQUIP_ERR_NOT_IN_COMBAT:
        ai->TellMaster("I can't use that in combat.");
        break;
    case EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW:
        ai->TellMaster("I can't get that now.");
        break;
    case EQUIP_ERR_ITEM_UNIQUE_EQUIPABLE:
        ai->TellMaster("I can only have one of those equipped.");
        break;
    case EQUIP_ERR_BANK_FULL:
        ai->TellMaster("My bank is full.");
        break;
    case EQUIP_ERR_ITEM_NOT_FOUND:
        ai->TellMaster("I can't find the item.");
        break;
    case EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK:
        ai->TellMaster("I'm too far from the bank.");
        break;
    default:
        ai->TellMaster("I can't use that.");
    }
    return true;
}
