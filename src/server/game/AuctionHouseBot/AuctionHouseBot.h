#ifndef AUCTION_HOUSE_BOT_H
#define AUCTION_HOUSE_BOT_H

#include "World.h"
#include "AuctionHouseMgr.h"
#include "SharedDefines.h"
#include "Item.h"

// shadow of ItemQualities with skipped ITEM_QUALITY_HEIRLOOM, anything after ITEM_QUALITY_ARTIFACT(6) in fact
enum AuctionQuality
{
    AUCTION_QUALITY_GREY   = ITEM_QUALITY_POOR,
    AUCTION_QUALITY_WHITE  = ITEM_QUALITY_NORMAL,
    AUCTION_QUALITY_GREEN  = ITEM_QUALITY_UNCOMMON,
    AUCTION_QUALITY_BLUE   = ITEM_QUALITY_RARE,
    AUCTION_QUALITY_PURPLE = ITEM_QUALITY_EPIC,
    AUCTION_QUALITY_ORANGE = ITEM_QUALITY_LEGENDARY,
    AUCTION_QUALITY_YELLOW = ITEM_QUALITY_ARTIFACT,
};

#define MAX_AUCTION_QUALITY 7

enum AuctionHouseType
{
    AUCTION_HOUSE_ALLIANCE  = 0,
    AUCTION_HOUSE_HORDE     = 1,
    AUCTION_HOUSE_NEUTRAL   = 2
};

#define MAX_AUCTION_HOUSE_TYPE 3

enum AuctionBotConfigUInt32Values
{

    CONFIG_AHBOT_MAXTIME,
    CONFIG_AHBOT_MINTIME,
    CONFIG_AHBOT_ITEMS_PER_CYCLE_BOOST,
    CONFIG_AHBOT_ITEMS_PER_CYCLE_NORMAL,
    CONFIG_AHBOT_ALLIANCE_ITEM_AMOUNT_RATIO,
    CONFIG_AHBOT_HORDE_ITEM_AMOUNT_RATIO,
    CONFIG_AHBOT_NEUTRAL_ITEM_AMOUNT_RATIO,
    CONFIG_AHBOT_ITEM_MIN_ITEM_LEVEL,
    CONFIG_AHBOT_ITEM_MAX_ITEM_LEVEL,
    CONFIG_AHBOT_ITEM_MIN_REQ_LEVEL,
    CONFIG_AHBOT_ITEM_MAX_REQ_LEVEL,
    CONFIG_AHBOT_ITEM_MIN_SKILL_RANK,
    CONFIG_AHBOT_ITEM_MAX_SKILL_RANK,
    CONFIG_AHBOT_ITEM_GREY_AMOUNT,
    CONFIG_AHBOT_ITEM_WHITE_AMOUNT,
    CONFIG_AHBOT_ITEM_GREEN_AMOUNT,
    CONFIG_AHBOT_ITEM_BLUE_AMOUNT,
    CONFIG_AHBOT_ITEM_PURPLE_AMOUNT,
    CONFIG_AHBOT_ITEM_ORANGE_AMOUNT,
    CONFIG_AHBOT_ITEM_YELLOW_AMOUNT,
    CONFIG_AHBOT_CLASS_CONSUMABLE_AMOUNT,
    CONFIG_AHBOT_CLASS_CONTAINER_AMOUNT,
    CONFIG_AHBOT_CLASS_WEAPON_AMOUNT,
    CONFIG_AHBOT_CLASS_GEM_AMOUNT,
    CONFIG_AHBOT_CLASS_ARMOR_AMOUNT,
    CONFIG_AHBOT_CLASS_REAGENT_AMOUNT,
    CONFIG_AHBOT_CLASS_PROJECTILE_AMOUNT,
    CONFIG_AHBOT_CLASS_TRADEGOOD_AMOUNT,
    CONFIG_AHBOT_CLASS_GENERIC_AMOUNT,
    CONFIG_AHBOT_CLASS_RECIPE_AMOUNT,
    CONFIG_AHBOT_CLASS_QUIVER_AMOUNT,
    CONFIG_AHBOT_CLASS_QUEST_AMOUNT,
    CONFIG_AHBOT_CLASS_KEY_AMOUNT,
    CONFIG_AHBOT_CLASS_MISC_AMOUNT,
    CONFIG_AHBOT_CLASS_GLYPH_AMOUNT,
    CONFIG_AHBOT_ALLIANCE_PRICE_RATIO,
    CONFIG_AHBOT_HORDE_PRICE_RATIO,
    CONFIG_AHBOT_NEUTRAL_PRICE_RATIO,
    CONFIG_AHBOT_BUYER_CHANCE_RATIO_ALLIANCE,
    CONFIG_AHBOT_BUYER_CHANCE_RATIO_HORDE,
    CONFIG_AHBOT_BUYER_CHANCE_RATIO_NEUTRAL,
    CONFIG_AHBOT_BUYER_RECHECK_INTERVAL,
    CONFIG_AHBOT_CLASS_MISC_MOUNT_MIN_REQ_LEVEL,
    CONFIG_AHBOT_CLASS_MISC_MOUNT_MAX_REQ_LEVEL,
    CONFIG_AHBOT_CLASS_MISC_MOUNT_MIN_SKILL_RANK,
    CONFIG_AHBOT_CLASS_MISC_MOUNT_MAX_SKILL_RANK,
    CONFIG_AHBOT_CLASS_GLYPH_MIN_REQ_LEVEL,
    CONFIG_AHBOT_CLASS_GLYPH_MAX_REQ_LEVEL,
    CONFIG_AHBOT_CLASS_GLYPH_MIN_ITEM_LEVEL,
    CONFIG_AHBOT_CLASS_GLYPH_MAX_ITEM_LEVEL,
    CONFIG_AHBOT_CLASS_TRADEGOOD_MIN_ITEM_LEVEL,
    CONFIG_AHBOT_CLASS_TRADEGOOD_MAX_ITEM_LEVEL,
    CONFIG_AHBOT_CLASS_CONTAINER_MIN_ITEM_LEVEL,
    CONFIG_AHBOT_CLASS_CONTAINER_MAX_ITEM_LEVEL,
    CONFIG_UINT32_AHBOT_UINT32_COUNT
};

enum AuctionBotConfigBoolValues
{
    CONFIG_AHBOT_BUYER_ALLIANCE_ENABLED,
    CONFIG_AHBOT_BUYER_HORDE_ENABLED,
    CONFIG_AHBOT_BUYER_NEUTRAL_ENABLED,
    CONFIG_AHBOT_ITEMS_VENDOR,
    CONFIG_AHBOT_ITEMS_LOOT,
    CONFIG_AHBOT_ITEMS_MISC,
    CONFIG_AHBOT_BIND_NO,
    CONFIG_AHBOT_BIND_PICKUP,
    CONFIG_AHBOT_BIND_EQUIP,
    CONFIG_AHBOT_BIND_USE,
    CONFIG_AHBOT_BIND_QUEST,
    CONFIG_AHBOT_BUYPRICE_SELLER,
    CONFIG_AHBOT_BUYPRICE_BUYER,
    CONFIG_AHBOT_SELLER_ENABLED,
    CONFIG_AHBOT_BUYER_ENABLED,
    CONFIG_AHBOT_LOCKBOX_ENABLED,
    CONFIG_UINT32_AHBOT_BOOL_COUNT
};

// All basic config data used by other AHBot classes for self-configure.
class AuctionBotConfig
{
public:
    AuctionBotConfig() {}

    bool Initialize();
    const char* GetAHBotIncludes() const { return _AHBotIncludes.c_str(); }
    const char* GetAHBotExcludes() const { return _AHBotExcludes.c_str(); }

    uint32 getConfig(AuctionBotConfigUInt32Values index) const { return _configUint32Values[index]; }
    bool getConfig(AuctionBotConfigBoolValues index) const { return _configBoolValues[index]; }
    void setConfig(AuctionBotConfigBoolValues index, bool value) { _configBoolValues[index]=value; }
    void setConfig(AuctionBotConfigUInt32Values index, uint32 value) { _configUint32Values[index]=value; }

    uint32 getConfigItemAmountRatio(AuctionHouseType houseType) const;
    bool getConfigBuyerEnabled(AuctionHouseType houseType) const;
    uint32 getConfigItemQualityAmount(AuctionQuality quality) const;

    uint32 GetItemPerCycleBoost() const { return _itemsPerCycleBoost; }
    uint32 GetItemPerCycleNormal() const { return _itemsPerCycleNormal; }
    void Reload();

    static char const* GetHouseTypeName(AuctionHouseType houseType);

private:
    std::string _AHBotIncludes;
    std::string _AHBotExcludes;
    uint32 _itemsPerCycleBoost;
    uint32 _itemsPerCycleNormal;

    uint32 _configUint32Values[CONFIG_UINT32_AHBOT_UINT32_COUNT];
    bool _configBoolValues[CONFIG_UINT32_AHBOT_BOOL_COUNT];

    void SetAHBotIncludes(const std::string& AHBotIncludes) { _AHBotIncludes = AHBotIncludes; }
    void SetAHBotExcludes(const std::string& AHBotExcludes) { _AHBotExcludes = AHBotExcludes; }

    void setConfig(AuctionBotConfigUInt32Values index, char const* fieldname, uint32 defvalue);
    void setConfigMax(AuctionBotConfigUInt32Values index, char const* fieldname, uint32 defvalue, uint32 maxvalue);
    void setConfigMinMax(AuctionBotConfigUInt32Values index, char const* fieldname, uint32 defvalue, uint32 minvalue, uint32 maxvalue);
    void setConfig(AuctionBotConfigBoolValues index, char const* fieldname, bool defvalue);
    void GetConfigFromFile();
};

#define sAuctionBotConfig ACE_Singleton<AuctionBotConfig, ACE_Null_Mutex>::instance()

class AuctionBotAgent
{
public:
    AuctionBotAgent() {}
    virtual ~AuctionBotAgent() {}
public:
    virtual bool Initialize() =0;
    virtual bool Update(AuctionHouseType houseType) =0;
};

struct AuctionHouseBotStatusInfoPerType
{
    uint32 ItemsCount;
    uint32 QualityInfo[MAX_AUCTION_QUALITY];
};

typedef AuctionHouseBotStatusInfoPerType AuctionHouseBotStatusInfo[MAX_AUCTION_HOUSE_TYPE];

// This class handle both Selling and Buying method
// (holder of AuctionBotBuyer and AuctionBotSeller objects)
class AuctionHouseBot
{
public:
    AuctionHouseBot();
    ~AuctionHouseBot();

    void Update();
    void Initialize();

    // Followed method is mainly used by level3.cpp for ingame/console command
    void SetItemsRatio(uint32 al, uint32 ho, uint32 ne);
    void SetItemsRatioForHouse(AuctionHouseType house, uint32 val);
    void SetItemsAmount(uint32 (&vals) [MAX_AUCTION_QUALITY]);
    void SetItemsAmountForQuality(AuctionQuality quality, uint32 val);
    void ReloadAllConfig();
    void Rebuild(bool all);

    void PrepareStatusInfos(AuctionHouseBotStatusInfo& statusInfo);
private:
    void InitilizeAgents();

    AuctionBotAgent* _buyer;
    AuctionBotAgent* _seller;

    uint32 m_OperationSelector;                         // 0..2*MAX_AUCTION_HOUSE_TYPE-1
};

#define sAuctionBot ACE_Singleton<AuctionHouseBot, ACE_Null_Mutex>::instance()

#endif
