#include "../pchdef.h"
#include "AhBotConfig.h"
#include "SystemConfig.h"
std::vector<std::string> split(const std::string &s, char delim);

using namespace std;

AhBotConfig::AhBotConfig()
{
}

template <class T>
void LoadSet(string value, T &res)
{
    vector<string> ids = split(value, ',');
    for (vector<string>::iterator i = ids.begin(); i != ids.end(); i++)
    {
        uint32 id = atoi((*i).c_str());
        if (!id)
            continue;

        res.insert(id);
    }
}

bool AhBotConfig::Initialize()
{
    string error;
    if (!config.LoadInitial("ahbot.conf", error))
    {
        sLog->outMessage("ahbot", LOG_LEVEL_INFO, "AhBot is Disabled. Unable to open configuration file ahbot.conf");
        return false;
    }

    enabled = config.GetBoolDefault("AhBot.Enabled", true);

    if (!enabled)
        sLog->outMessage("ahbot", LOG_LEVEL_INFO, "AhBot is Disabled in ahbot.conf");

    guid = (uint64)config.GetIntDefault("AhBot.GUID", 0);
    updateInterval = config.GetIntDefault("AhBot.UpdateIntervalInSeconds", 300);
    historyDays = config.GetIntDefault("AhBot.History.Days", 30);
    itemBuyInterval = config.GetIntDefault("AhBot.ItemBuyInterval", 28800);
    itemSellInterval = config.GetIntDefault("AhBot.ItemSellInterval", 14400);
    maxSellInterval = config.GetIntDefault("AhBot.MaxSellInterval", 3600 * 8);
    alwaysAvailableMoney = config.GetIntDefault("AhBot.AlwaysAvailableMoney", 200000);
    priceMultiplier = config.GetFloatDefault("AhBot.PriceMultiplier", 1.0f);
    defaultMinPrice = config.GetIntDefault("AhBot.DefaultMinPrice", 20);
    maxItemLevel = config.GetIntDefault("AhBot.MaxItemLevel", 199);
    maxRequiredLevel = config.GetIntDefault("AhBot.MaxRequiredLevel", 80);
    priceQualityMultiplier = config.GetFloatDefault("AhBot.PriceQualityMultiplier", 1.0f);
    underPriceProbability = config.GetFloatDefault("AhBot.UnderPriceProbability", 0.05f);
    LoadSet<set<uint32> >(config.GetStringDefault("AhBot.IgnoreItemIds", "49283,52200,8494,6345,6891,2460,37164,34835"), ignoreItemIds);


    return enabled;
}
