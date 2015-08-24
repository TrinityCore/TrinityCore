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

#define MAX_BATTLE_PAY_PRODUCT_TITLE_SIZE       50
#define MAX_BATTLE_PAY_PRODUCT_DESCRIPTION_SIZE 500
#define MAX_BATTLE_PAY_GROUP_NAME_SIZE          16
#include <Server/Packets/BattlepayPackets.h>

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

struct BattlePayProduct
{
    BattlePayProduct(uint32 id, std::string title, std::string description, uint64 normalPrice, uint64 currentPrice, uint32 itemId,
        uint32 quantity, uint32 displayId, uint8 type, uint8 choiceType, uint32 flags)
    : ProductID(id), Title(title), Description(description), NormalPrice(normalPrice), CurrentPrice(currentPrice), ItemID(itemId), Quantity(quantity),
        DisplayId(displayId), Type(type), ChoiceType(choiceType), Flags(flags) { }

    uint32 ProductID;
    std::string Title;
    std::string Description;
    uint64 NormalPrice;
    uint32 CurrentPrice;
    uint32 ItemID;
    uint32 Quantity;
    uint32 DisplayId;
    uint8 Type;
    uint8 ChoiceType;
    uint32 Flags;
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

    BattlePayMgr() : m_enabled(false), m_available(false), m_currency(BATTLE_PAY_CURRENCY_DOLLAR) { }
    ~BattlePayMgr();

    // Store states
    bool IsStoreEnabled() { return m_enabled; }
    void SetEnableState(bool enabled) { m_enabled = enabled; }
    bool IsStoreAvailable() { return m_available; }
    void SetAvailableState(bool available) { m_available = available; }
    bool IsStoreDisabled() { return m_disabledByParentalControls; }
    void SetDiabledState(bool disabled) { m_disabledByParentalControls = disabled; }

    uint32 GetStoreCurrency() { return m_currency; }
    void SetStoreCurrency(uint32 currency) { m_currency = currency; }

    uint32 GetProducts(uint32 id) const;
    void LoadFromDb();

private:
    BattlePayProductSet m_productStore;
    BattlePayProductGroupSet m_groupStore;
    BattlePayShopEntryset m_shopEntryStore;

    bool m_enabled;
    bool m_available;
    bool m_disabledByParentalControls;

    uint32 m_currency;

    bool HasProductId(uint32 productId);

    bool HasGroupId(uint32 groupId);
    bool HasGroupName(std::string name);

    bool LoadProductsFromDb();
    bool LoadGroupsFromDb();
    bool LoadEntriesFromDb();
};

#define sBattlePayMgr BattlePayMgr::instance()
#endif // BATTLEPAY_MGR_H__