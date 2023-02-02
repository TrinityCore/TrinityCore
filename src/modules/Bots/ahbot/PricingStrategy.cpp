#include "PricingStrategy.h"
#include "Category.h"
#include "ItemBag.h"
#include "AhBotConfig.h"
#include "../../shared/Database/DatabaseEnv.h"
#include "../playerbot/RandomItemMgr.h"
#include "AhBot.h"

using namespace ahbot;

double PricingStrategy::CalculatePrice(ostringstream *explain, ...)
{
    va_list vl;
    va_start(vl, explain);

    double result = 1.0;
    if (explain) *explain << "1";
    do
    {
        const char* name = va_arg(vl, const char*);
        if (!name) break;
        double v = va_arg(vl, double);

        result *= v;
        if (explain)
        {
            *explain << " * " << v << " (" << name << ")";
        }
    }
    while (true);

    va_end(vl);

    return result;
}

uint32 PricingStrategy::GetSellPrice(ItemPrototype const* proto, uint32 auctionHouse, bool ignoreMarket, ostringstream *explain)
{
    double marketPrice = GetMarketPrice(proto->ItemId, auctionHouse);

    if (!ignoreMarket && marketPrice > 0)
    {
        if (explain) *explain << "market";
        return marketPrice;
    }

    uint32 now = time(0);
    double price = CalculatePrice(explain,
            "sell",
            (double)GetDefaultSellPrice(proto),
            "item name",
            (double)sAhBotConfig.GetItemPriceMultiplier(proto->Name1),
            "category name",
            (double)auctionbot.GetCategoryMultiplier(category->GetName()),
            "rarity",
            (double)GetRarityPriceMultiplier(proto->ItemId),
            "level",
            (double)GetLevelPriceMultiplier(proto),
            "category",
            (double)GetCategoryPriceMultiplier(now, auctionHouse),
            "item",
            (double)GetItemPriceMultiplier(proto, now, auctionHouse),
            "category sell",
            (double)sAhBotConfig.GetSellPriceMultiplier(category->GetName()),
            "quality",
            (double)GetQualityMultiplier(proto),
            "static",
            (double)sAhBotConfig.priceMultiplier,
            NULL);
    return RoundPrice(price);
}

double PricingStrategy::GetMarketPrice(uint32 itemId, uint32 auctionHouse)
{
    double marketPrice = 0;

    QueryResult* results = PlayerbotDatabase.PQuery("SELECT price FROM ahbot_price WHERE item = '%u' AND auction_house = '%u'", itemId, auctionHouse);
    if (results)
    {
        marketPrice = results->Fetch()[0].GetFloat();
        delete results;
    }

    return RoundPrice(marketPrice);
}

uint32 PricingStrategy::GetBuyPrice(ItemPrototype const* proto, uint32 auctionHouse, ostringstream *explain)
{
    uint32 untilTime = time(0) - 3600 * 12;
    double price = CalculatePrice(explain,
            "buy",
            (double)GetDefaultBuyPrice(proto),
            "item name",
            (double)sAhBotConfig.GetItemPriceMultiplier(proto->Name1),
            "category name",
            (double)auctionbot.GetCategoryMultiplier(category->GetName()),
            "rarity",
            (double)GetRarityPriceMultiplier(proto->ItemId),
            "level",
            (double)GetLevelPriceMultiplier(proto),
            "category price",
            (double)GetCategoryPriceMultiplier(untilTime, auctionHouse),
            "item price",
            (double)GetItemPriceMultiplier(proto, untilTime, auctionHouse),
            "category buy",
            (double)sAhBotConfig.GetBuyPriceMultiplier(category->GetName()),
            "quality",
            (double)GetQualityMultiplier(proto),
            "static",
            (double)sAhBotConfig.priceMultiplier,
            NULL);
    return RoundPrice(price);
}

double PricingStrategy::GetRarityPriceMultiplier(uint32 itemId)
{
    float x = sRandomItemMgr.GetItemRarity(itemId);
    if (x < 0.001) return 1.0f;
    return 0.75 + exp((140 - x) / 50) / 6;
}

double PricingStrategy::GetLevelPriceMultiplier(ItemPrototype const* proto)
{
    float x = 0.1f + proto->ItemLevel;
    return 0.5 + exp(x / 60) / 2;
}

double PricingStrategy::GetCategoryPriceMultiplier(uint32 untilTime, uint32 auctionHouse)
{
    double result = 1.0;

    QueryResult* results = PlayerbotDatabase.PQuery(
        "SELECT count(*) FROM (SELECT round(buytime/3600/24/5) as days FROM ahbot_history WHERE category = '%s' AND won = '1' AND buytime <= '%u' AND auction_house = '%u' group by days) q",
        category->GetName().c_str(), untilTime, AhBot::factions[auctionHouse]);
    if (results)
    {
        Field* fields = results->Fetch();
        uint32 count = fields[0].GetUInt32();

        if (count)
            result += count;

        delete results;
    }

    return result;
}

double PricingStrategy::GetMultiplier(double count, double firstBuyTime, double lastBuyTime)
{
    double k1 = (double)count / (double)((time(0) - firstBuyTime) / 3600 / 24 + 1);
    double k2 = (double)count / (double)((time(0) - lastBuyTime) / 3600 / 24 + 1);
    return max(1.0, k1 + k2) * sAhBotConfig.priceMultiplier;
}

double PricingStrategy::GetItemPriceMultiplier(ItemPrototype const* proto, uint32 untilTime, uint32 auctionHouse)
{
    double result = 1.0;

    QueryResult* results = PlayerbotDatabase.PQuery(
        "SELECT count(*) FROM (SELECT round(buytime/3600/24/5) as days FROM ahbot_history WHERE won = '1' AND item = '%u' AND buytime <= '%u' AND auction_house = '%u' group by days) q",
        proto->ItemId, untilTime, AhBot::factions[auctionHouse]);
    if (results)
    {
        Field* fields = results->Fetch();
        uint32 count = fields[0].GetUInt32();

        if (count)
            result += count;

        delete results;
    }

    return result;
}

double PricingStrategy::GetQualityMultiplier(ItemPrototype const* proto)
{
    if (proto->Quality == ITEM_QUALITY_POOR)
        return 1.0;

    return sqrt((double)proto->Quality) * sAhBotConfig.priceQualityMultiplier;
}

uint32 PricingStrategy::GetDefaultBuyPrice(ItemPrototype const* proto)
{
    uint32 price = 0;

    if (proto->SellPrice)
        price = proto->SellPrice;
    if (proto->BuyPrice)
        price = max(price, proto->BuyPrice / 4);

    price *= 2;

    uint32 level = max(proto->ItemLevel, proto->RequiredLevel);
    if (proto->Class == ITEM_CLASS_QUEST)
    {
        double result = 1.0;

        QueryResult* results = WorldDatabase.PQuery(
            "select max(QuestLevel), max(MinLevel) from quest_template where ReqItemId1 = %u or ReqItemId2 = %u or ReqItemId3 = %u or ReqItemId4 = %u",
            proto->ItemId, proto->ItemId, proto->ItemId, proto->ItemId);
        if (results)
        {
            Field* fields = results->Fetch();
            level = max(fields[0].GetUInt32(), fields[1].GetUInt32());
            delete results;
        }
    }
    if (!price) price = sAhBotConfig.defaultMinPrice * level * level / 40;
    price = max(price, (uint32)1);

    return price;
}

uint32 PricingStrategy::GetDefaultSellPrice(ItemPrototype const* proto)
{
    return GetDefaultBuyPrice(proto) * 4 / 3;
}


uint32 BuyOnlyRarePricingStrategy::GetBuyPrice(ItemPrototype const* proto, uint32 auctionHouse, ostringstream *explain)
{
    if (proto->Quality < ITEM_QUALITY_RARE)
    {
        if (explain) *explain << "(not rare)";
        return 0;
    }

    return PricingStrategy::GetBuyPrice(proto, auctionHouse, explain);
}

uint32 BuyOnlyRarePricingStrategy::GetSellPrice(ItemPrototype const* proto, uint32 auctionHouse, bool ignoreMarket, ostringstream *explain)
{
    return PricingStrategy::GetSellPrice(proto, auctionHouse, ignoreMarket, explain);
}

uint32 PricingStrategy::RoundPrice(double price)
{
    if (price < 100) {
        return (uint32) price;
    }

    if (price < 10000) {
        return (uint32) (price / 100.0) * 100;
    }

    if (price < 100000) {
        return (uint32) (price / 1000.0) * 1000;
    }

    return (uint32) (price / 10000.0) * 10000;
}
