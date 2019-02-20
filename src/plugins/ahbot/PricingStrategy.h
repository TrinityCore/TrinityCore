#pragma once
#include "../../game/Entities/Item/ItemTemplate.h"

using namespace std;

namespace ahbot
{
    class Category;

    class PricingStrategy
    {
    public:
        PricingStrategy(Category* category) : category(category) {}

    public:
        virtual uint32 GetSellPrice(ItemTemplate const* proto, uint32 auctionHouse);
        virtual uint32 GetBuyPrice(ItemTemplate const* proto, uint32 auctionHouse);
        string ExplainSellPrice(ItemTemplate const* proto, uint32 auctionHouse);
        string ExplainBuyPrice(ItemTemplate const* proto, uint32 auctionHouse);
        virtual double GetRarityPriceMultiplier(uint32 itemId);

    protected:
        virtual uint32 GetDefaultBuyPrice(ItemTemplate const* proto);
        virtual uint32 GetDefaultSellPrice(ItemTemplate const* proto);
        virtual uint32 ApplyQualityMultiplier(ItemTemplate const* proto, uint32 price);
        virtual double GetCategoryPriceMultiplier(uint32 untilTime, uint32 auctionHouse);
        virtual double GetItemPriceMultiplier(ItemTemplate const* proto, uint32 untilTime, uint32 auctionHouse);
        double GetMultiplier(double count, double firstBuyTime, double lastBuyTime);
        double GetMarketPrice(uint32 itemId, uint32 auctionHouse);

    protected:
        Category* category;
    };

    class BuyOnlyRarePricingStrategy : public PricingStrategy
    {
    public:
        BuyOnlyRarePricingStrategy(Category* category) : PricingStrategy(category) {}

    public:
        virtual uint32 GetBuyPrice(ItemTemplate const* proto, uint32 auctionHouse);
    };

    class PricingStrategyFactory
    {
    public:
        static PricingStrategy* Create(string name, Category* category)
        {
            if (name == "buyOnlyRare")
                return new BuyOnlyRarePricingStrategy(category);

            return new PricingStrategy(category);
        }
    };
};
