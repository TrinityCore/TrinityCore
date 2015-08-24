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
#include "Player.h"
#include "BattlePayMgr.h"

class BattlePay
{
public:
    struct Product
    {
        WorldPackets::BattlePay::BattlePayProduct PacketInfo;
    };

    struct ProductGroup
    {
        WorldPackets::BattlePay::BattlePayProductGroup PacketInfo;
    };

    struct ShopEntries
    {
        WorldPackets::BattlePay::BattlePayShopEntry PacketInfo;
    };

    struct Distribution
    {
        WorldPackets::BattlePay::BattlePayDistributionObject PacketInfo;
    };

    struct Purchase
    {
        WorldPackets::BattlePay::BattlePayPurchase PacketInfo;
    };

    explicit BattlePay(Player* owner);

    void SendBattlePayProductList();
    void SendBattlePayPurchaseList();
    void SendBattlePayDistributionList();
    void SendBattlePayUpdateVasPurchaseStates();

private:
    Player* _owner;

    bool m_enabled;
    bool m_available;
    bool m_disabledByParentalControls;
    uint32 m_currency;

    std::unordered_map<uint32 /*productID*/, Product> _product;
    std::unordered_map<uint32 /*GroupID*/, ProductGroup> _group;
    std::unordered_map<uint32 /*EntryID*/, ShopEntries> _entry;
    std::unordered_map<uint64 /*DistributionID*/, Distribution> _object;
    std::unordered_map<uint64 /*PurchaseID*/, Purchase> _purchase;
};

#endif // BATTLEPAY_H__