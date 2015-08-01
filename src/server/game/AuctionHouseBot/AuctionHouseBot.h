/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef AUCTION_HOUSE_BOT_H
#define AUCTION_HOUSE_BOT_H

#include "Define.h"

class AuctionBotSeller;
class AuctionBotBuyer;

// shadow of ItemQualities with skipped ITEM_QUALITY_HEIRLOOM, anything after ITEM_QUALITY_ARTIFACT(6) in fact
enum AuctionQuality
{
    AUCTION_QUALITY_GRAY    = ITEM_QUALITY_POOR,
    AUCTION_QUALITY_WHITE   = ITEM_QUALITY_NORMAL,
    AUCTION_QUALITY_GREEN   = ITEM_QUALITY_UNCOMMON,
    AUCTION_QUALITY_BLUE    = ITEM_QUALITY_RARE,
    AUCTION_QUALITY_PURPLE  = ITEM_QUALITY_EPIC,
    AUCTION_QUALITY_ORANGE  = ITEM_QUALITY_LEGENDARY,
    AUCTION_QUALITY_YELLOW  = ITEM_QUALITY_ARTIFACT,
};

#define MAX_AUCTION_QUALITY 7

enum AuctionHouseType
{
    AUCTION_HOUSE_NEUTRAL   = 0,
    AUCTION_HOUSE_ALLIANCE  = 1,
    AUCTION_HOUSE_HORDE     = 2
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
    CONFIG_AHBOT_ITEM_GRAY_AMOUNT,
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
    CONFIG_AHBOT_ITEM_GRAY_PRICE_RATIO,
    CONFIG_AHBOT_ITEM_WHITE_PRICE_RATIO,
    CONFIG_AHBOT_ITEM_GREEN_PRICE_RATIO,
    CONFIG_AHBOT_ITEM_BLUE_PRICE_RATIO,
    CONFIG_AHBOT_ITEM_PURPLE_PRICE_RATIO,
    CONFIG_AHBOT_ITEM_ORANGE_PRICE_RATIO,
    CONFIG_AHBOT_ITEM_YELLOW_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_CONSUMABLE_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_CONTAINER_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_WEAPON_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_GEM_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_ARMOR_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_REAGENT_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_PROJECTILE_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_TRADEGOOD_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_GENERIC_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_RECIPE_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_MONEY_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_QUIVER_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_QUEST_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_KEY_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_PERMANENT_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_MISC_PRICE_RATIO,
    CONFIG_AHBOT_CLASS_GLYPH_PRICE_RATIO,
    CONFIG_AHBOT_BUYER_RECHECK_INTERVAL,
    CONFIG_AHBOT_BUYER_BASEPRICE_GRAY,
    CONFIG_AHBOT_BUYER_BASEPRICE_WHITE,
    CONFIG_AHBOT_BUYER_BASEPRICE_GREEN,
    CONFIG_AHBOT_BUYER_BASEPRICE_BLUE,
    CONFIG_AHBOT_BUYER_BASEPRICE_PURPLE,
    CONFIG_AHBOT_BUYER_BASEPRICE_ORANGE,
    CONFIG_AHBOT_BUYER_BASEPRICE_YELLOW,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_GRAY,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_WHITE,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_GREEN,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_BLUE,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_PURPLE,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_ORANGE,
    CONFIG_AHBOT_BUYER_CHANCEMULTIPLIER_YELLOW,
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
    CONFIG_AHBOT_SELLER_ENABLED,
    CONFIG_AHBOT_BUYER_ENABLED,
    CONFIG_AHBOT_LOCKBOX_ENABLED,
    CONFIG_AHBOT_CLASS_CONSUMABLE_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_CONTAINER_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_WEAPON_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_GEM_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_ARMOR_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_REAGENT_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_PROJECTILE_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_TRADEGOOD_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_RECIPE_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_QUIVER_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_QUEST_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_KEY_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_MISC_ALLOW_ZERO,
    CONFIG_AHBOT_CLASS_GLYPH_ALLOW_ZERO,
    CONFIG_UINT32_AHBOT_BOOL_COUNT
};

enum AuctionBotConfigFloatValues
{
    CONFIG_AHBOT_BUYER_CHANCE_FACTOR,
    CONFIG_AHBOT_FLOAT_COUNT
};

// All basic config data used by other AHBot classes for self-configure.
class AuctionBotConfig
{
private:
    AuctionBotConfig(): _itemsPerCycleBoost(1000), _itemsPerCycleNormal(20) {}
    ~AuctionBotConfig() {}
    AuctionBotConfig(const AuctionBotConfig&);
    AuctionBotConfig& operator=(const AuctionBotConfig&);

public:
    static AuctionBotConfig* instance()
    {
        static AuctionBotConfig instance;
        return &instance;
    }

    bool Initialize();
    const std::string& GetAHBotIncludes() const { return _AHBotIncludes; }
    const std::string& GetAHBotExcludes() const { return _AHBotExcludes; }

    uint32 GetConfig(AuctionBotConfigUInt32Values index) const { return _configUint32Values[index]; }
    bool GetConfig(AuctionBotConfigBoolValues index) const { return _configBoolValues[index]; }
    float GetConfig(AuctionBotConfigFloatValues index) const { return _configFloatValues[index]; }
    void SetConfig(AuctionBotConfigBoolValues index, bool value) { _configBoolValues[index] = value; }
    void SetConfig(AuctionBotConfigUInt32Values index, uint32 value) { _configUint32Values[index] = value; }
    void SetConfig(AuctionBotConfigFloatValues index, float value) { _configFloatValues[index] = value; }

    uint32 GetConfigItemAmountRatio(AuctionHouseType houseType) const;
    bool GetConfigBuyerEnabled(AuctionHouseType houseType) const;
    uint32 GetConfigItemQualityAmount(AuctionQuality quality) const;

    uint32 GetItemPerCycleBoost() const { return _itemsPerCycleBoost; }
    uint32 GetItemPerCycleNormal() const { return _itemsPerCycleNormal; }
    void Reload() { GetConfigFromFile(); }

    static char const* GetHouseTypeName(AuctionHouseType houseType);

private:
    std::string _AHBotIncludes;
    std::string _AHBotExcludes;
    uint32 _itemsPerCycleBoost;
    uint32 _itemsPerCycleNormal;

    uint32 _configUint32Values[CONFIG_UINT32_AHBOT_UINT32_COUNT];
    bool _configBoolValues[CONFIG_UINT32_AHBOT_BOOL_COUNT];
    float _configFloatValues[CONFIG_AHBOT_FLOAT_COUNT];

    void SetAHBotIncludes(const std::string& AHBotIncludes) { _AHBotIncludes = AHBotIncludes; }
    void SetAHBotExcludes(const std::string& AHBotExcludes) { _AHBotExcludes = AHBotExcludes; }

    void SetConfig(AuctionBotConfigUInt32Values index, char const* fieldname, uint32 defvalue);
    void SetConfigMax(AuctionBotConfigUInt32Values index, char const* fieldname, uint32 defvalue, uint32 maxvalue);
    void SetConfigMinMax(AuctionBotConfigUInt32Values index, char const* fieldname, uint32 defvalue, uint32 minvalue, uint32 maxvalue);
    void SetConfig(AuctionBotConfigBoolValues index, char const* fieldname, bool defvalue);
    void SetConfig(AuctionBotConfigFloatValues index, char const* fieldname, float defvalue);
    void GetConfigFromFile();
};

#define sAuctionBotConfig AuctionBotConfig::instance()

class AuctionBotAgent
{
public:
    AuctionBotAgent() {}
    virtual ~AuctionBotAgent() {}
    virtual bool Initialize() = 0;
    virtual bool Update(AuctionHouseType houseType) = 0;
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
private:
    AuctionHouseBot();
    ~AuctionHouseBot();
    AuctionHouseBot(const AuctionHouseBot&);
    AuctionHouseBot& operator=(const AuctionHouseBot&);

public:
    static AuctionHouseBot* instance()
    {
        static AuctionHouseBot instance;
        return &instance;
    }

    void Update();
    void Initialize();

    // Followed method is mainly used by cs_ahbot.cpp for in-game/console command
    void SetItemsRatio(uint32 al, uint32 ho, uint32 ne);
    void SetItemsRatioForHouse(AuctionHouseType house, uint32 val);
    void SetItemsAmount(uint32(&vals)[MAX_AUCTION_QUALITY]);
    void SetItemsAmountForQuality(AuctionQuality quality, uint32 val);
    void ReloadAllConfig();
    void Rebuild(bool all);

    void PrepareStatusInfos(AuctionHouseBotStatusInfo& statusInfo);
private:
    void InitializeAgents();

    AuctionBotBuyer* _buyer;
    AuctionBotSeller* _seller;

    uint32 _operationSelector; // 0..2*MAX_AUCTION_HOUSE_TYPE-1
};

#define sAuctionBot AuctionHouseBot::instance()

#endif
