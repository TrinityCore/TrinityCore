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

// Don't know all of the enums just yet
enum BattlePayTypes
{
    BATTLE_PAY_TYPE_DEFAULT         = 0,
    BATTLE_PAY_TYPE_FEATURE         = 1,
    BATTLE_PAY_TYPE_PET             = 2,
    BATTLE_PAY_TYPE_MOUNT           = 3,
    BATTLE_PAY_TYPE_END
};

class BattlePay
{
public:
    explicit BattlePay(Player* owner);

    void SendBattlePayProductList();
    void SendBattlePayPurchaseList();
    void SendBattlePayDistributionList();
    void SendBattlePayUpdateVasPurchaseStates();

    // Get functions
    uint32 GetProductID() const { return _productId; }

private:
    Player* _owner;

    // variables
    uint32 _productId;

    bool m_enabled;
    bool m_available;
    bool m_disabledByParentalControls;
    uint32 m_currency;
};

#endif // BATTLEPAY_H__