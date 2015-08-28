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

#ifndef BATTLEPAY_MGR_H__
#define BATTLEPAY_MGR_H__

#include "Common.h"
#include "ObjectGuid.h"
#include "BattlePayPackets.h"
#include "ItemPackets.h"
#include "Player.h"
#include "WorldSession.h"

#define MAX_BATTLE_PAY_PRODUCT_TITLE_SIZE       50
#define MAX_BATTLE_PAY_PRODUCT_DESCRIPTION_SIZE 500
#define MAX_BATTLE_PAY_GROUP_NAME_SIZE          16

enum BattlePayStatus
{
    BATTLE_PAY_STATUS_ENABLED                       = 0,
    BATTLE_PAY_STATUS_AVAILABLE                     = 1,
    BATTLE_PAY_STATUS_DIABLED_BY_PARENTAL_CONTROLS  = 2,
    BATTLE_PAY_STATUS_END
};

enum BattlePayCurrency
{
    BATTLE_PAY_CURRENCY_DOLLAR              = 1,
    BATTLE_PAY_CURRENCY_POUND               = 2,
    BATTLE_PAY_CURRENCY_BATTLE_COIN         = 3,
    BATTLE_PAY_CURRENCY_EURO                = 4,
    BATTLE_PAY_CURRENCY_TEST                = 16,
    BATTLE_PAY_CURRENCY_END
};

enum BattlePayGroupType
{
    BATTLE_PAY_GROUP_TYPE_GRID              = 0,
    BATTLE_PAY_GROUP_TYPE_SINGLE            = 1,
    BATTLE_PAY_GROUP_TYPE_END
};

enum BattlePayBannerType
{
    BATTLE_PAY_BANNER_TYPE_FEATURED         = 0,
    BATTLE_PAY_BANNER_TYPE_DISCOUNT         = 1,
    BATTLE_PAY_BANNER_TYPE_NEW              = 2,
    BATTLE_PAY_BANNER_TYPE_END
};

enum BattlePayErrors
{
    BATTLE_PAY_ERROR_ITEM_UNAVAILABLE               = 0,
    BATTLE_PAY_ERROR_TOO_MANY_TOKENS                = 1,
    BATTLE_PAY_ERROR_CONSUMABLE_TOKEN_OWNED         = 2,
    BATTLE_PAY_ERROR_PURCHASE_DENIED                = 3,
    BATTLE_PAY_ERROR_PARENTAL_CONTROLS_NO_PURCHASE  = 4,
    BATTLE_PAY_ERROR_ALREADY_OWNED                  = 5,
    BATTLE_PAY_ERROR_OTHER                          = 6,
    BATTLE_PAY_ERROR_INSUFFICIENT_BALANCE           = 7,
    BATTLE_PAY_ERROR_WRONG_CURRENCY                 = 8,
    BATTLE_PAY_ERROR_BATTLEPAY_DISABLED             = 9,
    BATTLE_PAY_ERROR_PAYMENT_FAILED                 = 10,
    BATTLE_PAY_ERROR_INVALID_PAYMENT_INFO           = 11,
    BATTLE_PAY_ERROR_END
};

// Don't know all of the enums just yet
enum BattlePayTypes
{
    BATTLE_PAY_TYPE_DEFAULT = 0, // -- I think this includes WowTokens. 
    BATTLE_PAY_TYPE_FEATURE = 1,
    BATTLE_PAY_TYPE_PET = 2,
    BATTLE_PAY_TYPE_MOUNT = 3,
    BATTLE_PAY_TYPE_END
};

struct BattlePayProduct
{
    BattlePayProduct(uint32 _id, std::string _name1, std::string _name2, std::string _name3, uint32 _normal, uint32 _current, 
        uint32 _itemId, uint32 _quantity, uint32 _displayId, uint8 _type, uint32 _flags, uint32 _choiceType) 
        : ID(_id), Name1(_name1), Name2(_name2), Name3(_name3), NormalPrice(_normal), CurrentPrice(_current), ItemID(_itemId),
        Quantity(_quantity), DisplayID(_displayId), Type(_type), Flags(_flags), ChoiceType(_choiceType) { }

    uint32 ID;
    std::string Name1;
    std::string Name2;
    std::string Name3;
    uint32 NormalPrice;
    uint32 CurrentPrice;
    uint32 ItemID;
    uint32 Quantity;
    uint32 DisplayID;
    uint8 Type;
    uint32 Flags;
    uint32 ChoiceType;
};


struct BattlePayProductGroup
{
    BattlePayProductGroup(uint32 id, uint32 order, std::string name, uint32 icon, uint8 type)
        : GroupID(id), Ordering(order), Name(name), IconFileDataID(icon), DisplayType(type) { }

    uint32 GroupID;
    uint32 Ordering;
    std::string Name;
    uint32 IconFileDataID;
    uint8 DisplayType;
};

struct BattlePayShopEntry
{
    BattlePayShopEntry(uint32 id, uint32 order, uint32 groupId, uint32 productId, uint32 flags, uint8 banner)
        : EntryID(id), Ordering(order), GroupID(groupId), ProductID(productId), Flags(flags), BannerType(banner) { }

    uint32 EntryID;
    uint32 Ordering;
    uint32 GroupID;
    uint32 ProductID;
    uint32 Flags;
    uint8 BannerType;
};

typedef std::set<BattlePayProduct*> BattlePayProductSet;
typedef std::set<BattlePayProductGroup*> BattlePayProductGroupSet;
typedef std::set<BattlePayShopEntry*> BattlePayShopEntryset;

class BattlePayMgr
{
public:
    static BattlePayMgr* instance()
    {
        static BattlePayMgr instance;
        return &instance;
    }

    BattlePayMgr() : m_enabled(true), m_available(true), m_currency(BATTLE_PAY_CURRENCY_DOLLAR) { }
    ~BattlePayMgr();

    // Store states
    bool IsStoreEnabled() { return m_enabled; }
    void SetEnableState(bool enabled) { m_enabled = enabled; }
    bool IsStoreAvailable() { return m_available; }
    void SetAvailableState(bool available) { m_available = available; }
    bool IsStoreDisabled() { return m_disabledByParentalControls; }
    void SetDiabledState(bool disabled) { m_disabledByParentalControls = disabled; }

    uint32 GetTokenIndex() const { return m_tokenIndex; }
    uint32 GetTokenCurrentPrice() const { return m_tokenCurrentPrice; }

    uint32 GetStoreCurrency() const { return m_currency; }
    void SetStoreCurrency(uint32 currency) { m_currency = currency; }
    uint32 GetBattlePayType() const { return m_type; }
    
    uint32 GetProducts(uint32 id) const;
    void LoadFromDb();

    // Fill data in Handler
    BattlePayProductSet const& GetStoreProducts() { return m_productStore; }
    BattlePayProductGroupSet const& GetStoreGroups() { return m_groupStore; }
    BattlePayShopEntryset const& GetStoreEntries() { return m_shopEntryStore; }

    // Packets
    void SendBattlePayDistributionList(WorldSession* session);
    void SendBattlePayPurchaseList(WorldSession* session);
    void SendBattlePayProductList(WorldSession* session);
    void SendBattlePayUpdateVasPurchaseStates(WorldSession* session);
    void SendWowTokenEligibilityResponse(WorldSession* session, uint32 unkInt);
    void SendWowTokenMarketPriceResponse(WorldSession* session, uint32 currentPrice);
    void SendAuctionableTokenResponse(WorldSession* session, uint32 unkInt);

private:
    BattlePayProductSet m_productStore;
    BattlePayProductGroupSet m_groupStore;
    BattlePayShopEntryset m_shopEntryStore;

    bool m_enabled;
    bool m_available;
    bool m_disabledByParentalControls;

    uint32 m_tokenIndex;
    uint64 m_tokenCurrentPrice = 300000000;

    uint32 m_currency;
    uint8 m_type;

    bool HasProductId(uint32 productId);

    bool HasGroupId(uint32 groupId);
    bool HasGroupName(std::string name);

    bool LoadProductsFromDb();
    bool LoadGroupsFromDb();
    bool LoadEntriesFromDb();

    WorldSession* session;
};

#define sBattlePayMgr BattlePayMgr::instance()
#endif // BATTLEPAY_MGR_H__