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

#include "BattlePayMgr.h"
#include "BattlePay.h"
#include "BattlePayPackets.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"

void WorldSession::HandleBattlePayGetProductList(WorldPackets::BattlePay::BattlePayGetProductList& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_GET_PRODUCT_LIST");

    if (BattlePay* battlePay = nullptr)
        battlePay->SendBattlePayProductList();
}

void WorldSession::HandleBattlePayGetPurchaseList(WorldPackets::BattlePay::BattlePayGetPurchaseList& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_GET_PURCHSE_LIST");

    if (BattlePay* battlePay = nullptr)
        battlePay->SendBattlePayPurchaseList();
}

void WorldSession::HandleBattlePayUpdateVasPurchaseStates(WorldPackets::BattlePay::BattlePayUpdateVasPurchaseStates& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_UPDATE_VAS_PURCHASE_STATES");

    if (BattlePay* battlePay = nullptr)
        battlePay->SendBattlePayUpdateVasPurchaseStates();
}