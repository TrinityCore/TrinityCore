#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TradeStatusAction.h"

#include "../ItemVisitors.h"
#include "../../PlayerbotAIConfig.h"
#include "../../../ahbot/AhBot.h"
#include "../../RandomPlayerbotMgr.h"
#include "../../GuildTaskMgr.h"
#include "../values/ItemUsageValue.h"

using namespace ai;



bool TradeStatusAction::Execute(Event event)
{
    Player* trader = bot->GetTrader();
    Player* master = GetMaster();
    if (!trader)
        return false;

    if (trader != master)
    {
		bot->Whisper("I'm kind of busy now", LANG_UNIVERSAL, trader);
    }

    if (trader != master || !ai->GetSecurity()->CheckLevelFor(PLAYERBOT_SECURITY_ALLOW_ALL, true, master))
    {
        WorldPacket p;
        uint32 status = 0;
        p << status;
        bot->GetSession()->HandleCancelTradeOpcode(p);
        return false;
    }

    WorldPacket p(event.getPacket());
    p.rpos(0);
    uint32 status;
    p >> status;

    if (status == TRADE_STATUS_TRADE_ACCEPT)
    {
        WorldPacket p;
        uint32 status = 0;
        p << status;

        if (CheckTrade())
        {
            int32 botMoney = CalculateCost(bot->GetTradeData(), true);

            map<uint32, uint32> itemIds;
            for (uint32 slot = 0; slot < TRADE_SLOT_TRADED_COUNT; ++slot)
            {
                Item* item = master->GetTradeData()->GetItem((TradeSlots)slot);
                if (item)
                    itemIds[item->GetTemplate()->ItemId] += item->GetCount();
            }

            bot->GetSession()->HandleAcceptTradeOpcode(p);
            if (bot->GetTradeData())
                return false;

            for (map<uint32, uint32>::iterator i = itemIds.begin(); i != itemIds.end(); ++i)
                sGuildTaskMgr.CheckItemTask(i->first, i->second, master, bot);

            if (sRandomPlayerbotMgr.IsRandomBot(bot))
            {
                int32 lootAmount = sRandomPlayerbotMgr.GetLootAmount(bot);
                sRandomPlayerbotMgr.SetLootAmount(bot, max(0, lootAmount - botMoney * 10));
            }
            return true;
        }
    }
    else if (status == TRADE_STATUS_BEGIN_TRADE)
    {
        if (!bot->isInFront(trader, M_PI / 2))
            bot->SetFacingToObject(trader);
        BeginTrade();
        return true;
    }

    return false;
}


void TradeStatusAction::BeginTrade()
{
    WorldPacket p;
    bot->GetSession()->HandleBeginTradeOpcode(p);

    ListItemsVisitor visitor;
    IterateItems(&visitor);

    ai->TellMaster("=== Trade ===");
    TellItems(visitor.items);

    if (sRandomPlayerbotMgr.IsRandomBot(bot))
    {
        uint32 discount = sRandomPlayerbotMgr.GetTradeDiscount(bot);
        if (discount)
        {
            ostringstream out; out << "Discount up to: " << chat->formatMoney(discount);
            ai->TellMaster(out);
        }
    }
}

bool TradeStatusAction::CheckTrade()
{
    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
        return true;

    Player* master = GetMaster();
    if (!bot->GetTradeData() || !master->GetTradeData())
        return false;

    for (uint32 slot = 0; slot < TRADE_SLOT_TRADED_COUNT; ++slot)
    {
        Item* item = bot->GetTradeData()->GetItem((TradeSlots)slot);
        if (item && !auctionbot.GetSellPrice(item->GetTemplate()))
        {
            ostringstream out;
            out << chat->formatItem(item->GetTemplate()) << " - This is not for sale";
            ai->TellMaster(out);
            return false;
        }

        item = master->GetTradeData()->GetItem((TradeSlots)slot);
        if (item)
        {
            ostringstream out; out << item->GetTemplate()->ItemId;
            ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());
            if (!auctionbot.GetBuyPrice(item->GetTemplate()) || usage == ITEM_USAGE_NONE)
            {
                ostringstream out;
                out << chat->formatItem(item->GetTemplate()) << " - I don't need this";
                ai->TellMaster(out);
                return false;
            }
        }
    }

    int32 botItemsMoney = CalculateCost(bot->GetTradeData(), true);
    int32 botMoney = bot->GetTradeData()->GetMoney() + botItemsMoney;
    int32 playerItemsMoney = CalculateCost(master->GetTradeData(), false);
    int32 playerMoney = master->GetTradeData()->GetMoney() + playerItemsMoney;

    if (!botMoney && !playerMoney)
        return true;

    if (!botItemsMoney && !playerItemsMoney)
    {
        ai->TellMaster("There are no items to trade");
        return false;
    }

    int32 discount = min(botItemsMoney, (int32)sRandomPlayerbotMgr.GetTradeDiscount(bot));
    botMoney = max(0, botMoney - discount);

    if (playerMoney >= botMoney)
    {
        switch (urand(0, 4)) {
        case 0:
            ai->TellMaster("A pleasure doing business with you");
            break;
        case 1:
            ai->TellMaster("Fair trade");
            break;
        case 2:
            ai->TellMaster("Thanks");
            break;
        case 3:
            ai->TellMaster("Off with you");
            break;
        }
        return true;
    }

    ostringstream out;
    out << "I want " << chat->formatMoney(botMoney - playerMoney) << " for this";
    ai->TellMaster(out);
    return false;
}

int32 TradeStatusAction::CalculateCost(TradeData* data, bool sell)
{
    if (!data)
        return 0;

    uint32 sum = 0;
    for (uint32 slot = 0; slot < TRADE_SLOT_TRADED_COUNT; ++slot)
    {
        Item* item = data->GetItem((TradeSlots)slot);
        if (!item)
            continue;

        ItemTemplate const* proto = item->GetTemplate();
        if (!proto)
            continue;

        if (proto->Quality < ITEM_QUALITY_NORMAL)
            return 0;

        if (sell)
        {
            sum += item->GetCount() * auctionbot.GetSellPrice(proto) * sRandomPlayerbotMgr.GetSellMultiplier(bot);
        }
        else
        {
            sum += item->GetCount() * auctionbot.GetBuyPrice(proto) * sRandomPlayerbotMgr.GetBuyMultiplier(bot);
        }
    }

    return sum;
}
