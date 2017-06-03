#pragma once

#include "../../common/Configuration/Config.h"

using namespace std;

class AhBotConfig
{
public:
    AhBotConfig();
    static AhBotConfig& instance()
    {
        static AhBotConfig instance;
        return instance;
    }

public:
    bool Initialize();

    bool enabled;
    uint64 guid;
    uint32 updateInterval;
    uint32 historyDays, maxSellInterval;
    uint32 itemBuyMinInterval, itemBuyMaxInterval;
    uint32 itemSellMinInterval, itemSellMaxInterval;
    uint32 alwaysAvailableMoney;
    float priceMultiplier, priceQualityMultiplier;
    uint32 defaultMinPrice;
    uint32 maxItemLevel, maxRequiredLevel;
    float underPriceProbability;
    std::set<uint32> ignoreItemIds;

    float GetSellPriceMultiplier(string category)
    {
        return GetCategoryParameter(sellPriceMultipliers, "PriceMultiplier.Sell", category, 1.0f);
    }

    float GetBuyPriceMultiplier(string category)
    {
        return GetCategoryParameter(buyPriceMultipliers, "PriceMultiplier.Buy", category, 1.0f);
    }

    float GetItemPriceMultiplier(string name)
    {
        return GetCategoryParameter(itemPriceMultipliers, "PriceMultiplier.Item", name, 1.0f);
    }

    int32 GetMaxAllowedAuctionCount(string category)
    {
        return (int32)GetCategoryParameter(maxAuctionCount, "MaxAuctionCount", category, 5);
    }

    std::string GetStringDefault(const char* name, const char* def)
    {
        return config.GetStringDefault(name, def);
    }

    bool GetBoolDefault(const char* name, const bool def = false)
    {
        return config.GetBoolDefault(name, def);
    }

    int32 GetIntDefault(const char* name, const int32 def)
    {
        return config.GetIntDefault(name, def);
    }

    float GetFloatDefault(const char* name, const float def)
    {
        return config.GetFloatDefault(name, def);
    }

private:
    float GetCategoryParameter(map<string, float>& cache, string type, string category, float defaultValue)
    {
        if (cache.find(category) == cache.end())
        {
            ostringstream out; out << "AhBot."<< type << "." << category;
            cache[category] = config.GetFloatDefault(out.str().c_str(), defaultValue);
        }

        return cache[category];
    }

private:
    ConfigMgr config;
    map<string, float> sellPriceMultipliers;
    map<string, float> buyPriceMultipliers;
    map<string, float> itemPriceMultipliers;
    map<string, float> maxAuctionCount;
};

#define sAhBotConfig AhBotConfig::instance()
