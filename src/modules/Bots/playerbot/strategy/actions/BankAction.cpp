#include "botpch.h"
#include "../../playerbot.h"
#include "BankAction.h"

#include "../values/ItemCountValue.h"

using namespace std;
using namespace ai;

bool BankAction::Execute(Event event)
{
    string text = event.getParam();

    list<ObjectGuid> npcs = AI_VALUE(list<ObjectGuid>, "nearest npcs");
    for (list<ObjectGuid>::iterator i = npcs.begin(); i != npcs.end(); i++)
    {
        Unit* npc = ai->GetUnit(*i);
        if (!npc || !npc->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BANKER))
            continue;

        return Execute(text, npc);
    }

    ai->TellMaster("Cannot find banker nearby");
    return false;
}

bool BankAction::Execute(string text, Unit* bank)
{
    if (text.empty() || text == "?")
    {
        ListItems();
        return true;
    }

    bool result = false;
    if (text[0] == '-')
    {
        list<Item*> found = parseItems(text.substr(1), ITERATE_ITEMS_IN_BANK);
        for (list<Item*>::iterator i = found.begin(); i != found.end(); i++)
        {
            Item* item = *i;
            result &= Withdraw(item->GetProto()->ItemId);
        }
    }
    else
    {
        list<Item*> found = parseItems(text, ITERATE_ITEMS_IN_BAGS);
        if (found.empty())
            return false;

        for (list<Item*>::iterator i = found.begin(); i != found.end(); i++)
        {
            Item* item = *i;
            if (!item)
                continue;

            result &= Deposit(item);
        }
    }

    return result;
}

bool BankAction::Withdraw(const uint32 itemid)
{
    Item* pItem = FindItemInBank(itemid);
    if (!pItem)
        return false;

    ItemPosCountVec dest;
    InventoryResult msg = bot->CanStoreItem(NULL_BAG, NULL_SLOT, dest, pItem, false);
    if (msg != EQUIP_ERR_OK)
    {
        bot->SendEquipError(msg, pItem, NULL);
        return false;
    }

    bot->RemoveItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
    bot->StoreItem(dest, pItem, true);

    std::ostringstream out;
    out << "got " << chat->formatItem(pItem->GetProto(), pItem->GetCount()) << " from bank";
    ai->TellMaster(out.str());
    return true;
}

bool BankAction::Deposit(Item* pItem)
{
    std::ostringstream out;

    ItemPosCountVec dest;
    InventoryResult msg = bot->CanBankItem(NULL_BAG, NULL_SLOT, dest, pItem, false);
    if (msg != EQUIP_ERR_OK)
    {
        bot->SendEquipError(msg, pItem, NULL);
        return false;
    }

    bot->RemoveItem(pItem->GetBagSlot(), pItem->GetSlot(), true);
    bot->BankItem(dest, pItem, true);

    out << "put " << chat->formatItem(pItem->GetProto(), pItem->GetCount()) << " to bank";
    ai->TellMaster(out.str());
	return true;
}

void BankAction::ListItems()
{
    ai->TellMaster("=== Bank ===");

    map<uint32, int> items;
    map<uint32, bool> soulbound;
    for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
        if (Item* pItem = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem)
            {
                items[pItem->GetProto()->ItemId] += pItem->GetCount();
                soulbound[pItem->GetProto()->ItemId] = pItem->IsSoulBound();
            }

    for (int i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        if (Bag* pBag = (Bag*)bot->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pBag)
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        if (pItem)
                        {
                            items[pItem->GetProto()->ItemId] += pItem->GetCount();
                            soulbound[pItem->GetProto()->ItemId] = pItem->IsSoulBound();
                        }

    TellItems(items, soulbound);
}

Item* BankAction::FindItemInBank(uint32 ItemId)
{
    for (uint8 slot = BANK_SLOT_ITEM_START; slot < BANK_SLOT_ITEM_END; slot++)
    {
        Item* const pItem = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        if (pItem)
        {
            const ItemPrototype* const pItemProto = pItem->GetProto();
            if (!pItemProto)
                continue;

            if (pItemProto->ItemId == ItemId)   // have required item
                return pItem;
        }
    }

    for (uint8 bag = BANK_SLOT_BAG_START; bag < BANK_SLOT_BAG_END; ++bag)
    {
        const Bag* const pBag = (Bag *) bot->GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
        if (pBag)
            for (uint8 slot = 0; slot < pBag->GetBagSize(); ++slot)
            {
                Item* const pItem = bot->GetItemByPos(bag, slot);
                if (pItem)
                {
                    const ItemPrototype* const pItemProto = pItem->GetProto();
                    if (!pItemProto)
                        continue;

                    if (pItemProto->ItemId == ItemId)
                        return pItem;
                }
            }
    }
    return NULL;
}
