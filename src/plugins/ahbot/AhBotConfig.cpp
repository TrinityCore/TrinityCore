#include "../pchdef.h"
#include "AhBotConfig.h"
#include "World.h"
#include "Log.h"

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
    vector<string> args;
    if (!config.LoadInitial("worldserver.conf", args, error))
    {
        sLog->outMessage("ahbot", LOG_LEVEL_INFO, "AhBot is Disabled. Unable to open configuration file worldserver.conf");
        return false;
    }

    enabled = sWorld->getBoolConfig(CONFIG_AHBOT_ENABLED);

    if (!enabled)
        sLog->outMessage("ahbot", LOG_LEVEL_INFO, "AhBot is Disabled in worldserver.conf");

    guid = (uint64)sWorld->getIntConfig(CONFIG_AHBOT_GUID);
    updateInterval = sWorld->getIntConfig(CONFIG_AHBOT_UPDATEINTERVAL);
    historyDays = sWorld->getIntConfig(CONFIG_AHBOT_HOSTORYDAYS);
    itemBuyMinInterval = sWorld->getIntConfig(CONFIG_AHBOT_ITEMBUYMIN);
    itemBuyMaxInterval = sWorld->getIntConfig(CONFIG_AHBOT_ITEMBUYMAX);
    itemSellMinInterval = sWorld->getIntConfig(CONFIG_AHBOT_ITEMSELLMIN);
    itemSellMaxInterval = sWorld->getIntConfig(CONFIG_AHBOT_ITEMSELLMAX);
    maxSellInterval = sWorld->getIntConfig(CONFIG_AHBOT_MAXSELL);
    alwaysAvailableMoney = sWorld->getIntConfig(CONFIG_AHBOT_ALWAYSMONEY);
    priceMultiplier = sWorld->getFloatConfig(CONFIG_AHBOT_PRICEMULTIPLIER);
    defaultMinPrice = sWorld->getIntConfig(CONFIG_AHBOT_DEFAULTMINPRICE);
    maxItemLevel = sWorld->getIntConfig(CONFIG_AHBOT_MAXITEMLEVEL);
    maxRequiredLevel = sWorld->getIntConfig(CONFIG_AHBOT_MAXREQLEVEL);
    priceQualityMultiplier = sWorld->getFloatConfig(CONFIG_AHBOT_PRICEQUALITYMULTIPLY);
    underPriceProbability = sWorld->getFloatConfig(CONFIG_AHBOT_UNDERPRICEPROB);
    LoadSet<set<uint32> >(sConfigMgr->GetStringDefault("AhBot.IgnoreItemIds", "49283,52200,8494,6345,6891,2460,37164,34835"), ignoreItemIds);


    return enabled;
}
