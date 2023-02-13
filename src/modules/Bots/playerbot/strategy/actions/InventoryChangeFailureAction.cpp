#include "botpch.h"
#include "../../playerbot.h"
#include "InventoryChangeFailureAction.h"


using namespace ai;

map<InventoryResult, string> InventoryChangeFailureAction::messages;

bool InventoryChangeFailureAction::Execute(Event event)
{
    if (!ai->GetMaster())
        return false;

    if (messages.empty())
    {
        messages[EQUIP_ERR_CANT_EQUIP_LEVEL_I] = "My level is too low";
        messages[EQUIP_ERR_CANT_EQUIP_SKILL] = "My skill level is too low";
        messages[EQUIP_ERR_ITEM_DOESNT_GO_TO_SLOT] = "Invalid slot";
        messages[EQUIP_ERR_BAG_FULL] = "My bags are full";
        messages[EQUIP_ERR_NONEMPTY_BAG_OVER_OTHER_BAG] = "This bag is not empty";
        messages[EQUIP_ERR_CANT_TRADE_EQUIP_BAGS] = "Cannot trade equipped bags";
        messages[EQUIP_ERR_ONLY_AMMO_CAN_GO_HERE] = "Invalid slot (only ammo is required)";
        messages[EQUIP_ERR_NO_REQUIRED_PROFICIENCY] = "I don't have necessary skill";
        messages[EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE] = "No equipment slot available";
        messages[EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM] = "I will never be able to use this";
        messages[EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM2] = "I will never be able to use this";
        messages[EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE2] = messages[EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE];
        messages[EQUIP_ERR_CANT_EQUIP_WITH_TWOHANDED] = "Cannot equip with two-handed weapon equipped";
        messages[EQUIP_ERR_CANT_DUAL_WIELD] = "I cannot dual-wield";
        messages[EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG] = "This item cannot go in this bag";
        messages[EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2] = "This item cannot go in this bag";
        messages[EQUIP_ERR_CANT_CARRY_MORE_OF_THIS] = "I can't carry anymore of those";
        messages[EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE3] = messages[EQUIP_ERR_NO_EQUIPMENT_SLOT_AVAILABLE];
        messages[EQUIP_ERR_ITEM_CANT_STACK] = "Item cannot stack";
        messages[EQUIP_ERR_ITEM_CANT_BE_EQUIPPED] = "Item cannot be equipped";
        messages[EQUIP_ERR_ITEMS_CANT_BE_SWAPPED] = "Cannot swap these items";
        messages[EQUIP_ERR_SLOT_IS_EMPTY] = "Nothing to equip";
        messages[EQUIP_ERR_ITEM_NOT_FOUND] = "Cannot find the item";
        messages[EQUIP_ERR_CANT_DROP_SOULBOUND] = "Cannot drop soulbound items";
        messages[EQUIP_ERR_OUT_OF_RANGE] = "I am out of range";
        messages[EQUIP_ERR_TRIED_TO_SPLIT_MORE_THAN_COUNT] = "Invalid split number";
        messages[EQUIP_ERR_COULDNT_SPLIT_ITEMS] = "Cannot split this";
        messages[EQUIP_ERR_MISSING_REAGENT] = "Missing reagents";
        messages[EQUIP_ERR_NOT_ENOUGH_MONEY] = "Not enough money";
        messages[EQUIP_ERR_NOT_A_BAG] = "This is not a bag";
        messages[EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS] = "The bag is not empty";
        messages[EQUIP_ERR_DONT_OWN_THAT_ITEM] = "This is not my item";
        messages[EQUIP_ERR_CAN_EQUIP_ONLY1_QUIVER] = "Only quiver can be equipped";
        messages[EQUIP_ERR_MUST_PURCHASE_THAT_BAG_SLOT] = "I must purchase the slot before";
        messages[EQUIP_ERR_TOO_FAR_AWAY_FROM_BANK] = "I am too far away from bank";
        messages[EQUIP_ERR_ITEM_LOCKED] = "This item is locked";
        messages[EQUIP_ERR_YOU_ARE_STUNNED] = "I am stunned";
        messages[EQUIP_ERR_YOU_ARE_DEAD] = "I am dead";
        messages[EQUIP_ERR_CANT_DO_RIGHT_NOW] = "I can't do this right now";
        messages[EQUIP_ERR_INT_BAG_ERROR] = "Internal error";
        messages[EQUIP_ERR_CAN_EQUIP_ONLY1_BOLT] = "Only bolts are allowed";
        messages[EQUIP_ERR_CAN_EQUIP_ONLY1_AMMOPOUCH] = "Ammo poach is allowed";
        messages[EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED] = "Item can't be wrapped";
        messages[EQUIP_ERR_EQUIPPED_CANT_BE_WRAPPED] = messages[EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED];
        messages[EQUIP_ERR_WRAPPED_CANT_BE_WRAPPED] = messages[EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED];
        messages[EQUIP_ERR_BOUND_CANT_BE_WRAPPED] = messages[EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED];
        messages[EQUIP_ERR_UNIQUE_CANT_BE_WRAPPED] = messages[EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED];
        messages[EQUIP_ERR_BAGS_CANT_BE_WRAPPED] = messages[EQUIP_ERR_STACKABLE_CANT_BE_WRAPPED];
        messages[EQUIP_ERR_ALREADY_LOOTED] = "Already looted";
        messages[EQUIP_ERR_INVENTORY_FULL] = "My inventory is full";
        messages[EQUIP_ERR_BANK_FULL] = "My bank is full";
        messages[EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT] = "Item item is sold out";
        messages[EQUIP_ERR_BAG_FULL3] = messages[EQUIP_ERR_BANK_FULL];
        messages[EQUIP_ERR_ITEM_NOT_FOUND2] = messages[EQUIP_ERR_ITEM_NOT_FOUND];
        messages[EQUIP_ERR_ITEM_CANT_STACK2] = messages[EQUIP_ERR_ITEM_CANT_STACK];
        messages[EQUIP_ERR_BAG_FULL4] = messages[EQUIP_ERR_BAG_FULL];
        messages[EQUIP_ERR_ITEM_SOLD_OUT] = messages[EQUIP_ERR_ITEM_IS_CURRENTLY_SOLD_OUT];
        messages[EQUIP_ERR_OBJECT_IS_BUSY] = "This object is busy";
        messages[EQUIP_ERR_NOT_IN_COMBAT] = "I am not in combat";
        messages[EQUIP_ERR_NOT_WHILE_DISARMED] = "Cannot do while disarmed";
        messages[EQUIP_ERR_BAG_FULL6] = messages[EQUIP_ERR_BAG_FULL];
        messages[EQUIP_ERR_CANT_EQUIP_RANK] = "Not enough rank";
        messages[EQUIP_ERR_CANT_EQUIP_REPUTATION] = "Not enough reputation";
        messages[EQUIP_ERR_TOO_MANY_SPECIAL_BAGS] = "Too many special bags";
        messages[EQUIP_ERR_LOOT_CANT_LOOT_THAT_NOW] = "Cannot loot this right now";
    }

    WorldPacket p(event.getPacket());
    p.rpos(0);
    uint8 err;
    p >> err;
    if (err == EQUIP_ERR_OK)
        return false;

    string msg = messages[(InventoryResult)err];
    if (!msg.empty())
    {
        ai->TellMaster(msg);
        return true;
    }

    return false;
}
