#include "botpch.h"
#include "../../playerbot.h"
#include "WtsAction.h"
#include "../../AiFactory.h"
#include "../ItemVisitors.h"
#include "../../../ahbot/AhBot.h"
#include "../../../ahbot/PricingStrategy.h"
#include "../../RandomPlayerbotMgr.h"
#include "../values/ItemUsageValue.h"

using ahbot::PricingStrategy;

using namespace ai;

bool WtsAction::Execute(Event event)
{
    Player* owner = event.getOwner();
    if (!owner)
        return false;

    ostringstream out;
    string text = event.getParam();

    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
        return false;

    string link = event.getParam();

    ItemIds itemIds = chat->parseItems(link);
    if (itemIds.empty())
        return false;

    for (ItemIds::iterator i = itemIds.begin(); i != itemIds.end(); i++)
    {
        uint32 itemId = *i;
        const ItemPrototype* proto = sObjectMgr.GetItemPrototype(itemId);
        if (!proto)
            continue;

        ostringstream out; out << itemId;
        ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());
        if (usage == ITEM_USAGE_NONE)
            continue;

        int32 buyPrice = PricingStrategy::RoundPrice(auctionbot.GetBuyPrice(proto) * sRandomPlayerbotMgr.GetBuyMultiplier(bot));
        if (!buyPrice)
            continue;

        if (urand(0, 15) > 2)
            continue;

        ostringstream tell;
        tell << "I'll buy " << chat->formatItem(proto) << " for " << chat->formatMoney(buyPrice);

        // ignore random bot chat filter
        bot->Whisper(tell.str(), LANG_UNIVERSAL, owner->GetObjectGuid());
    }

    return true;
}
