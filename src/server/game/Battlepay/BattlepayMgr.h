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

#ifndef BATTLEPAY_H__
#define BATTLEPAY_H__

#include "Common.h"
#include "ObjectGuid.h"
#include "BattlepayPackets.h"
#include "ItemPackets.h"
#include "Item.h"

#define MAX_BATTLE_PAY_PRODUCT_TITLE_SIZE       50
#define MAX_BATTLE_PAY_PRODUCT_DESCRIPTION_SIZE 500
#define MAX_BATTLE_PAY_GROUP_NAME_SIZE          16
#include <Server/Packets/BattlepayPackets.h>

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
    BATTLE_PAY_BANNER_TYPE_NEW              = 2,
    BATTLE_PAY_BANNER_TYPE_END
};

typedef std::set<WorldPackets::Battlepay::BattlePayProduct*> BattlePayProductSet;
typedef std::set<WorldPackets::Battlepay::BattlePayProductGroup*> BattlePayProductGroupSet;
typedef std::set<WorldPackets::Battlepay::BattlePayShopEntry*> BattlePayShopEntryset;

class BattlepayMgr
{
public:
    static BattlepayMgr* instance()
    {
        static BattlepayMgr instance;
        return &instance;
    }

    BattlepayMgr() : m_enabled(false), m_currency(BATTLE_PAY_CURRENCY_DOLLAR) { }
    ~BattlepayMgr();

    bool IsStoreEnabled() { return m_enabled; }
    void LoadFromDb(Field* fields);

private:
    BattlePayProductSet m_productStore;
    BattlePayProductGroupSet m_groupStore;
    BattlePayShopEntryset m_shopEntryStore;

    bool m_enabled;
    uint32 m_currency;

    bool HasProductId(uint32 productId);

    bool HasGroupId(uint32 groupId);
    bool HasGroupName(std::string name);

    bool LoadProductsFromDb(Field* fields);
    bool LoadGroupsFromDb(Field* fields);
    bool LoadEntriesFromDb(Field* fields);
};

#define sBattlepayMgr BattlepayMgr::instance()
#endif // BATTLEPAY_H__