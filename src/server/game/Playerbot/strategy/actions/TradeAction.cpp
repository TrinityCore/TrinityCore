#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TradeAction.h"
#include "../ItemVisitors.h"
#include "../values/ItemCountValue.h"

using namespace ai;

bool TradeAction::Execute(Event event)
{
    string text = event.getParam();
    uint32 copper = chat->parseMoney(text);
    if (copper > 0)
    {
        WorldPacket* const packet = new WorldPacket(CMSG_SET_TRADE_GOLD, 4);
        *packet << copper;
        bot->GetSession()->QueuePacket(packet);
    }

    int8 slot = -1;

    list<Item*> found = parseItems(text);
    if (found.empty())
        return false;

    for (list<Item*>::iterator i = found.begin(); i != found.end(); i++)
        TradeItem(**i, slot);

    return true;
}

bool TradeAction::TradeItem(const Item& item, int8 slot)
{
    if (!bot->GetTrader() || item.IsInTrade())
        return false;

    if (!item.CanBeTraded() && slot != TRADE_SLOT_NONTRADED)
        slot = TRADE_SLOT_NONTRADED;

    int8 tradeSlot = -1;
    Item* itemPtr = const_cast<Item*>(&item);

    TradeData* pTrade = bot->GetTradeData();
    if ((slot >= 0 && slot < TRADE_SLOT_COUNT) && pTrade->GetItem(TradeSlots(slot)) == NULL)
        tradeSlot = slot;

    if (slot == TRADE_SLOT_NONTRADED)
        pTrade->SetItem(TRADE_SLOT_NONTRADED, itemPtr);
    else
    {
        for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT && tradeSlot == -1; i++)
        {
            if (pTrade->GetItem(TradeSlots(i)) == itemPtr)
            {
                tradeSlot = i;

                WorldPacket* const packet = new WorldPacket(CMSG_CLEAR_TRADE_ITEM, 1);
                *packet << (uint8) tradeSlot;
                bot->GetSession()->QueuePacket(packet);
                pTrade->SetItem(TradeSlots(i), NULL);
                return true;
            }
        }

        for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT && tradeSlot == -1; i++)
        {
            if (pTrade->GetItem(TradeSlots(i)) == NULL)
            {
                pTrade->SetItem(TradeSlots(i), itemPtr);
                tradeSlot = i;
            }
        }
    }

    if (tradeSlot == -1) return false;

    WorldPacket* const packet = new WorldPacket(CMSG_SET_TRADE_ITEM, 3);
    *packet << (uint8) tradeSlot << (uint8) item.GetBagSlot()
        << (uint8) item.GetSlot();
    bot->GetSession()->QueuePacket(packet);
    return true;
}

