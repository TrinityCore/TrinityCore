#ifndef DEF_TRANSMOGRIFICATION_H
#define DEF_TRANSMOGRIFICATION_H

#include "Config.h"
#include "Language.h"

class Transmogrification
{
public:
    Transmogrification() { };
    ~Transmogrification() { };

    uint32 GetRequireGold() { return RequireGold; }
    float GetGoldModifier() { return GoldModifier; }
    uint32 GetGoldCost() { return GoldCost; }

    bool GetRequireToken() { return RequireToken; }
    uint32 GetTokenEntry() { return TokenEntry; }
    uint32 GetTokenAmount() { return TokenAmount; }

    bool AllowedQuality(uint32 quality) // Only thing used elsewhere (Player.cpp)
    {
        switch(quality)
        {
        case ITEM_QUALITY_POOR: return AllowPoor;
        case ITEM_QUALITY_NORMAL: return AllowCommon;
        case ITEM_QUALITY_UNCOMMON: return AllowUncommon;
        case ITEM_QUALITY_RARE: return AllowRare;
        case ITEM_QUALITY_EPIC: return AllowEpic;
        case ITEM_QUALITY_LEGENDARY: return AllowLegendary;
        case ITEM_QUALITY_ARTIFACT: return AllowArtifact;
        case ITEM_QUALITY_HEIRLOOM: return AllowHeirloom;
        default: return false;
        }
    }

    void LoadConfig()
    {
        RequireGold = (uint32)ConfigMgr::GetIntDefault("Transmogrification.RequireGold", 1);
        GoldModifier = ConfigMgr::GetFloatDefault("Transmogrification.GoldModifier", 1.0f);
        GoldCost = (uint32)ConfigMgr::GetIntDefault("Transmogrification.GoldCost", 100000);

        RequireToken = ConfigMgr::GetBoolDefault("Transmogrification.RequireToken", false);
        TokenEntry = (uint32)ConfigMgr::GetIntDefault("Transmogrification.TokenEntry", 49426);
        TokenAmount = (uint32)ConfigMgr::GetIntDefault("Transmogrification.TokenAmount", 1);

        AllowPoor = ConfigMgr::GetBoolDefault("Transmogrification.AllowPoor", false);
        AllowCommon = ConfigMgr::GetBoolDefault("Transmogrification.AllowCommon", false);
        AllowUncommon = ConfigMgr::GetBoolDefault("Transmogrification.AllowUncommon", true);
        AllowRare = ConfigMgr::GetBoolDefault("Transmogrification.AllowRare", true);
        AllowEpic = ConfigMgr::GetBoolDefault("Transmogrification.AllowEpic", true);
        AllowLegendary = ConfigMgr::GetBoolDefault("Transmogrification.AllowLegendary", false);
        AllowArtifact = ConfigMgr::GetBoolDefault("Transmogrification.AllowArtifact", false);
        AllowHeirloom = ConfigMgr::GetBoolDefault("Transmogrification.AllowHeirloom", true);

        if(!sObjectMgr->GetItemTemplate(TokenEntry))
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Transmogrification.TokenEntry (%u) does not exist. Using default.", TokenEntry);
            TokenEntry = 49426;
        }
    }

private:

    uint32 RequireGold;
    float GoldModifier;
    uint32 GoldCost;

    bool RequireToken;
    uint32 TokenEntry;
    uint32 TokenAmount;

    bool AllowPoor;
    bool AllowCommon;
    bool AllowUncommon;
    bool AllowRare;
    bool AllowEpic;
    bool AllowLegendary;
    bool AllowArtifact;
    bool AllowHeirloom;
};
#define sTransmogrification ACE_Singleton<Transmogrification, ACE_Null_Mutex>::instance()

#endif
