/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "WorldSession.h"
#include "AccountMgr.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SocialMgr.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "TradeData.h"
#include "TradePackets.h"
#include "World.h"

void WorldSession::SendTradeStatus(WorldPackets::Trade::TradeStatus& info)
{
    info.Clear();   // reuse packet
    Player* trader = _player->GetTrader();
    info.PartnerIsSameBnetAccount = trader && trader->GetSession()->GetBattlenetAccountId() == GetBattlenetAccountId();
    SendPacket(info.Write());
}

void WorldSession::HandleIgnoreTradeOpcode(WorldPackets::Trade::IgnoreTrade& /*ignoreTrade*/)
{
}

void WorldSession::HandleBusyTradeOpcode(WorldPackets::Trade::BusyTrade& /*busyTrade*/)
{
}

void WorldSession::SendUpdateTrade(bool trader_data /*= true*/)
{
    TradeData* view_trade = trader_data ? _player->GetTradeData()->GetTraderData() : _player->GetTradeData();

    WorldPackets::Trade::TradeUpdated tradeUpdated;
    tradeUpdated.WhichPlayer = trader_data;
    tradeUpdated.ClientStateIndex = view_trade->GetClientStateIndex();
    tradeUpdated.CurrentStateIndex = view_trade->GetServerStateIndex();
    tradeUpdated.Gold = view_trade->GetMoney();
    tradeUpdated.ProposedEnchantment = view_trade->GetSpell();

    for (uint8 i = 0; i < TRADE_SLOT_COUNT; ++i)
    {
        if (Item* item = view_trade->GetItem(TradeSlots(i)))
        {
            WorldPackets::Trade::TradeUpdated::TradeItem tradeItem;
            tradeItem.Slot = i;
            tradeItem.Item.Initialize(item);
            tradeItem.StackCount = item->GetCount();
            tradeItem.GiftCreator = item->GetGuidValue(ITEM_FIELD_GIFTCREATOR);
            if (!item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))
            {
                tradeItem.Unwrapped = boost::in_place();

                tradeItem.Unwrapped->EnchantID = item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT);
                tradeItem.Unwrapped->OnUseEnchantmentID = item->GetEnchantmentId(USE_ENCHANTMENT_SLOT);
                tradeItem.Unwrapped->Creator = item->GetGuidValue(ITEM_FIELD_CREATOR);
                tradeItem.Unwrapped->Charges = item->GetSpellCharges();
                tradeItem.Unwrapped->Lock = item->GetTemplate()->GetLockID() && !item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_UNLOCKED);
                tradeItem.Unwrapped->MaxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
                tradeItem.Unwrapped->Durability = item->GetUInt32Value(ITEM_FIELD_DURABILITY);

                uint8 g = 0;
                for (ItemDynamicFieldGems const& gemData : item->GetGems())
                {
                    if (gemData.ItemId)
                    {
                        WorldPackets::Item::ItemGemData gem;
                        gem.Slot = g;
                        gem.Item.Initialize(&gemData);
                        tradeItem.Unwrapped->Gems.push_back(gem);
                    }
                    ++g;
                }
            }

            tradeUpdated.Items.push_back(tradeItem);
        }
    }

    SendPacket(tradeUpdated.Write());
}

//==============================================================
// transfer the items to the players

void WorldSession::moveItems(Item* myItems[], Item* hisItems[])
{
    Player* trader = _player->GetTrader();
    if (!trader)
        return;

    for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT; ++i)
    {
        ItemPosCountVec traderDst;
        ItemPosCountVec playerDst;
        bool traderCanTrade = (myItems[i] == NULL || trader->CanStoreItem(NULL_BAG, NULL_SLOT, traderDst, myItems[i], false) == EQUIP_ERR_OK);
        bool playerCanTrade = (hisItems[i] == NULL || _player->CanStoreItem(NULL_BAG, NULL_SLOT, playerDst, hisItems[i], false) == EQUIP_ERR_OK);
        if (traderCanTrade && playerCanTrade)
        {
            // Ok, if trade item exists and can be stored
            // If we trade in both directions we had to check, if the trade will work before we actually do it
            // A roll back is not possible after we stored it
            if (myItems[i])
            {
                // logging
                TC_LOG_DEBUG("network", "partner storing: %s", myItems[i]->GetGUID().ToString().c_str());
                if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
                {
                    sLog->outCommand(_player->GetSession()->GetAccountId(), "GM %s (Account: %u) trade: %s (Entry: %d Count: %u) to player: %s (Account: %u)",
                        _player->GetName().c_str(), _player->GetSession()->GetAccountId(),
                        myItems[i]->GetTemplate()->GetDefaultLocaleName(), myItems[i]->GetEntry(), myItems[i]->GetCount(),
                        trader->GetName().c_str(), trader->GetSession()->GetAccountId());
                }

                // adjust time (depends on /played)
                if (myItems[i]->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
                    myItems[i]->SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, trader->GetTotalPlayedTime()-(_player->GetTotalPlayedTime()-myItems[i]->GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME)));
                // store
                trader->MoveItemToInventory(traderDst, myItems[i], true, true);
            }
            if (hisItems[i])
            {
                // logging
                TC_LOG_DEBUG("network", "player storing: %s", hisItems[i]->GetGUID().ToString().c_str());
                if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
                {
                    sLog->outCommand(trader->GetSession()->GetAccountId(), "GM %s (Account: %u) trade: %s (Entry: %d Count: %u) to player: %s (Account: %u)",
                        trader->GetName().c_str(), trader->GetSession()->GetAccountId(),
                        hisItems[i]->GetTemplate()->GetDefaultLocaleName(), hisItems[i]->GetEntry(), hisItems[i]->GetCount(),
                        _player->GetName().c_str(), _player->GetSession()->GetAccountId());
                }

                // adjust time (depends on /played)
                if (hisItems[i]->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
                    hisItems[i]->SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, _player->GetTotalPlayedTime()-(trader->GetTotalPlayedTime()-hisItems[i]->GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME)));
                // store
                _player->MoveItemToInventory(playerDst, hisItems[i], true, true);
            }
        }
        else
        {
            // in case of fatal error log error message
            // return the already removed items to the original owner
            if (myItems[i])
            {
                if (!traderCanTrade)
                    TC_LOG_ERROR("network", "trader can't store item: %s", myItems[i]->GetGUID().ToString().c_str());
                if (_player->CanStoreItem(NULL_BAG, NULL_SLOT, playerDst, myItems[i], false) == EQUIP_ERR_OK)
                    _player->MoveItemToInventory(playerDst, myItems[i], true, true);
                else
                    TC_LOG_ERROR("network", "player can't take item back: %s", myItems[i]->GetGUID().ToString().c_str());
            }
            // return the already removed items to the original owner
            if (hisItems[i])
            {
                if (!playerCanTrade)
                    TC_LOG_ERROR("network", "player can't store item: %s", hisItems[i]->GetGUID().ToString().c_str());
                if (trader->CanStoreItem(NULL_BAG, NULL_SLOT, traderDst, hisItems[i], false) == EQUIP_ERR_OK)
                    trader->MoveItemToInventory(traderDst, hisItems[i], true, true);
                else
                    TC_LOG_ERROR("network", "trader can't take item back: %s", hisItems[i]->GetGUID().ToString().c_str());
            }
        }
    }
}

//==============================================================

static void setAcceptTradeMode(TradeData* myTrade, TradeData* hisTrade, Item* *myItems, Item* *hisItems)
{
    myTrade->SetInAcceptProcess(true);
    hisTrade->SetInAcceptProcess(true);

    // store items in local list and set 'in-trade' flag
    for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT; ++i)
    {
        if (Item* item = myTrade->GetItem(TradeSlots(i)))
        {
            TC_LOG_DEBUG("network", "player trade %s bag: %u slot: %u", item->GetGUID().ToString().c_str(), item->GetBagSlot(), item->GetSlot());
            //Can return NULL
            myItems[i] = item;
            myItems[i]->SetInTrade();
        }

        if (Item* item = hisTrade->GetItem(TradeSlots(i)))
        {
            TC_LOG_DEBUG("network", "partner trade %s bag: %u slot: %u", item->GetGUID().ToString().c_str(), item->GetBagSlot(), item->GetSlot());
            hisItems[i] = item;
            hisItems[i]->SetInTrade();
        }
    }
}

static void clearAcceptTradeMode(TradeData* myTrade, TradeData* hisTrade)
{
    myTrade->SetInAcceptProcess(false);
    hisTrade->SetInAcceptProcess(false);
}

static void clearAcceptTradeMode(Item* *myItems, Item* *hisItems)
{
    // clear 'in-trade' flag
    for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT; ++i)
    {
        if (myItems[i])
            myItems[i]->SetInTrade(false);
        if (hisItems[i])
            hisItems[i]->SetInTrade(false);
    }
}

void WorldSession::HandleAcceptTradeOpcode(WorldPackets::Trade::AcceptTrade& acceptTrade)
{
    TradeData* my_trade = _player->m_trade;
    if (!my_trade)
        return;

    Player* trader = my_trade->GetTrader();

    TradeData* his_trade = trader->m_trade;
    if (!his_trade)
        return;

    Item* myItems[TRADE_SLOT_TRADED_COUNT]  = { NULL, NULL, NULL, NULL, NULL, NULL };
    Item* hisItems[TRADE_SLOT_TRADED_COUNT] = { NULL, NULL, NULL, NULL, NULL, NULL };

    // set before checks for propertly undo at problems (it already set in to client)
    my_trade->SetAccepted(true);

    WorldPackets::Trade::TradeStatus info;
    if (his_trade->GetServerStateIndex() != acceptTrade.StateIndex)
    {
        info.Status = TRADE_STATUS_STATE_CHANGED;
        SendTradeStatus(info);
        my_trade->SetAccepted(false);
        return;
    }

    if (!_player->IsWithinDistInMap(trader, TRADE_DISTANCE, false))
    {
        info.Status = TRADE_STATUS_TOO_FAR_AWAY;
        SendTradeStatus(info);
        my_trade->SetAccepted(false);
        return;
    }

    // not accept case incorrect money amount
    if (!_player->HasEnoughMoney(my_trade->GetMoney()))
    {
        info.Status = TRADE_STATUS_FAILED;
        info.BagResult = EQUIP_ERR_NOT_ENOUGH_MONEY;
        SendTradeStatus(info);
        my_trade->SetAccepted(false, true);
        return;
    }

    // not accept case incorrect money amount
    if (!trader->HasEnoughMoney(his_trade->GetMoney()))
    {
        info.Status = TRADE_STATUS_FAILED;
        info.BagResult = EQUIP_ERR_NOT_ENOUGH_MONEY;
        trader->GetSession()->SendTradeStatus(info);
        his_trade->SetAccepted(false, true);
        return;
    }

    if (_player->GetMoney() > MAX_MONEY_AMOUNT - his_trade->GetMoney())
    {
        info.Status = TRADE_STATUS_FAILED;
        info.BagResult = EQUIP_ERR_TOO_MUCH_GOLD;
        SendTradeStatus(info);
        my_trade->SetAccepted(false, true);
        return;
    }

    if (trader->GetMoney() > MAX_MONEY_AMOUNT - my_trade->GetMoney())
    {
        info.Status = TRADE_STATUS_FAILED;
        info.BagResult = EQUIP_ERR_TOO_MUCH_GOLD;
        trader->GetSession()->SendTradeStatus(info);
        his_trade->SetAccepted(false, true);
        return;
    }

    // not accept if some items now can't be trade (cheating)
    for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT; ++i)
    {
        if (Item* item = my_trade->GetItem(TradeSlots(i)))
        {
            if (!item->CanBeTraded(false, true))
            {
                info.Status = TRADE_STATUS_CANCELLED;
                SendTradeStatus(info);
                return;
            }

            if (item->IsBindedNotWith(trader))
            {
                info.Status = TRADE_STATUS_FAILED;
                info.BagResult = EQUIP_ERR_TRADE_BOUND_ITEM;
                SendTradeStatus(info);
                return;
            }
        }

        if (Item* item = his_trade->GetItem(TradeSlots(i)))
        {
            if (!item->CanBeTraded(false, true))
            {
                info.Status = TRADE_STATUS_CANCELLED;
                SendTradeStatus(info);
                return;
            }
            //if (item->IsBindedNotWith(_player))   // dont mark as invalid when his item isnt good (not exploitable because if item is invalid trade will fail anyway later on the same check)
            //{
            //    SendTradeStatus(TRADE_STATUS_NOT_ELIGIBLE);
            //    his_trade->SetAccepted(false, true);
            //    return;
            //}
        }
    }

    if (his_trade->IsAccepted())
    {
        setAcceptTradeMode(my_trade, his_trade, myItems, hisItems);

        Spell* my_spell = NULL;
        SpellCastTargets my_targets;

        Spell* his_spell = NULL;
        SpellCastTargets his_targets;

        // not accept if spell can't be cast now (cheating)
        if (uint32 my_spell_id = my_trade->GetSpell())
        {
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(my_spell_id);
            Item* castItem = my_trade->GetSpellCastItem();

            if (!spellEntry || !his_trade->GetItem(TRADE_SLOT_NONTRADED) ||
                (my_trade->HasSpellCastItem() && !castItem))
            {
                clearAcceptTradeMode(my_trade, his_trade);
                clearAcceptTradeMode(myItems, hisItems);

                my_trade->SetSpell(0);
                return;
            }

            my_spell = new Spell(_player, spellEntry, TRIGGERED_FULL_MASK);
            my_spell->m_CastItem = castItem;
            my_targets.SetTradeItemTarget(_player);
            my_spell->m_targets = my_targets;

            SpellCastResult res = my_spell->CheckCast(true);
            if (res != SPELL_CAST_OK)
            {
                my_spell->SendCastResult(res);

                clearAcceptTradeMode(my_trade, his_trade);
                clearAcceptTradeMode(myItems, hisItems);

                delete my_spell;
                my_trade->SetSpell(0);
                return;
            }
        }

        // not accept if spell can't be cast now (cheating)
        if (uint32 his_spell_id = his_trade->GetSpell())
        {
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(his_spell_id);
            Item* castItem = his_trade->GetSpellCastItem();

            if (!spellEntry || !my_trade->GetItem(TRADE_SLOT_NONTRADED) || (his_trade->HasSpellCastItem() && !castItem))
            {
                delete my_spell;
                his_trade->SetSpell(0);

                clearAcceptTradeMode(my_trade, his_trade);
                clearAcceptTradeMode(myItems, hisItems);
                return;
            }

            his_spell = new Spell(trader, spellEntry, TRIGGERED_FULL_MASK);
            his_spell->m_CastItem = castItem;
            his_targets.SetTradeItemTarget(trader);
            his_spell->m_targets = his_targets;

            SpellCastResult res = his_spell->CheckCast(true);
            if (res != SPELL_CAST_OK)
            {
                his_spell->SendCastResult(res);

                clearAcceptTradeMode(my_trade, his_trade);
                clearAcceptTradeMode(myItems, hisItems);

                delete my_spell;
                delete his_spell;

                his_trade->SetSpell(0);
                return;
            }
        }

        // inform partner client
        info.Status = TRADE_STATUS_ACCEPTED;
        trader->GetSession()->SendTradeStatus(info);

        // test if item will fit in each inventory
        WorldPackets::Trade::TradeStatus myCanCompleteInfo, hisCanCompleteInfo;
        hisCanCompleteInfo.BagResult = trader->CanStoreItems(myItems, TRADE_SLOT_TRADED_COUNT, &hisCanCompleteInfo.ItemID);
        myCanCompleteInfo.BagResult = _player->CanStoreItems(hisItems, TRADE_SLOT_TRADED_COUNT, &myCanCompleteInfo.ItemID);

        clearAcceptTradeMode(myItems, hisItems);

        // in case of missing space report error
        if (myCanCompleteInfo.BagResult != EQUIP_ERR_OK)
        {
            clearAcceptTradeMode(my_trade, his_trade);

            myCanCompleteInfo.Status = TRADE_STATUS_FAILED;
            trader->GetSession()->SendTradeStatus(myCanCompleteInfo);
            myCanCompleteInfo.FailureForYou = true;
            SendTradeStatus(myCanCompleteInfo);
            my_trade->SetAccepted(false);
            his_trade->SetAccepted(false);
            delete my_spell;
            delete his_spell;
            return;
        }
        else if (hisCanCompleteInfo.BagResult != EQUIP_ERR_OK)
        {
            clearAcceptTradeMode(my_trade, his_trade);

            hisCanCompleteInfo.Status = TRADE_STATUS_FAILED;
            SendTradeStatus(hisCanCompleteInfo);
            hisCanCompleteInfo.FailureForYou = true;
            trader->GetSession()->SendTradeStatus(hisCanCompleteInfo);
            my_trade->SetAccepted(false);
            his_trade->SetAccepted(false);
            delete my_spell;
            delete his_spell;
            return;
        }

        // execute trade: 1. remove
        for (uint8 i = 0; i < TRADE_SLOT_TRADED_COUNT; ++i)
        {
            if (myItems[i])
            {
                myItems[i]->SetGuidValue(ITEM_FIELD_GIFTCREATOR, _player->GetGUID());
                _player->MoveItemFromInventory(myItems[i]->GetBagSlot(), myItems[i]->GetSlot(), true);
            }
            if (hisItems[i])
            {
                hisItems[i]->SetGuidValue(ITEM_FIELD_GIFTCREATOR, trader->GetGUID());
                trader->MoveItemFromInventory(hisItems[i]->GetBagSlot(), hisItems[i]->GetSlot(), true);
            }
        }

        // execute trade: 2. store
        moveItems(myItems, hisItems);

        // logging money
        if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
        {
            if (my_trade->GetMoney() > 0)
            {
                sLog->outCommand(_player->GetSession()->GetAccountId(), "GM %s (Account: %u) give money (Amount: " UI64FMTD ") to player: %s (Account: %u)",
                    _player->GetName().c_str(), _player->GetSession()->GetAccountId(),
                    my_trade->GetMoney(),
                    trader->GetName().c_str(), trader->GetSession()->GetAccountId());
            }

            if (his_trade->GetMoney() > 0)
            {
                sLog->outCommand(trader->GetSession()->GetAccountId(), "GM %s (Account: %u) give money (Amount: " UI64FMTD ") to player: %s (Account: %u)",
                    trader->GetName().c_str(), trader->GetSession()->GetAccountId(),
                    his_trade->GetMoney(),
                    _player->GetName().c_str(), _player->GetSession()->GetAccountId());
            }
        }

        // update money
        _player->ModifyMoney(-int64(my_trade->GetMoney()));
        _player->ModifyMoney(his_trade->GetMoney());
        trader->ModifyMoney(-int64(his_trade->GetMoney()));
        trader->ModifyMoney(my_trade->GetMoney());

        if (my_spell)
            my_spell->prepare(&my_targets);

        if (his_spell)
            his_spell->prepare(&his_targets);

        // cleanup
        clearAcceptTradeMode(my_trade, his_trade);
        delete _player->m_trade;
        _player->m_trade = NULL;
        delete trader->m_trade;
        trader->m_trade = NULL;

        // desynchronized with the other saves here (SaveInventoryAndGoldToDB() not have own transaction guards)
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        _player->SaveInventoryAndGoldToDB(trans);
        trader->SaveInventoryAndGoldToDB(trans);
        CharacterDatabase.CommitTransaction(trans);

        info.Status = TRADE_STATUS_COMPLETE;
        trader->GetSession()->SendTradeStatus(info);
        SendTradeStatus(info);
    }
    else
    {
        info.Status = TRADE_STATUS_ACCEPTED;
        trader->GetSession()->SendTradeStatus(info);
    }
}

void WorldSession::HandleUnacceptTradeOpcode(WorldPackets::Trade::UnacceptTrade& /*unacceptTrade*/)
{
    TradeData* my_trade = _player->GetTradeData();
    if (!my_trade)
        return;

    my_trade->SetAccepted(false, true);
}

void WorldSession::HandleBeginTradeOpcode(WorldPackets::Trade::BeginTrade& /*beginTrade*/)
{
    TradeData* my_trade = _player->m_trade;
    if (!my_trade)
        return;

    WorldPackets::Trade::TradeStatus info;
    info.Status = TRADE_STATUS_INITIATED;
    my_trade->GetTrader()->GetSession()->SendTradeStatus(info);
    SendTradeStatus(info);
}

void WorldSession::SendCancelTrade()
{
    if (PlayerRecentlyLoggedOut() || PlayerLogout())
        return;

    WorldPackets::Trade::TradeStatus info;
    info.Status = TRADE_STATUS_CANCELLED;
    SendTradeStatus(info);
}

void WorldSession::HandleCancelTradeOpcode(WorldPackets::Trade::CancelTrade& /*cancelTrade*/)
{
    // sent also after LOGOUT COMPLETE
    if (_player)                                             // needed because STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT
        _player->TradeCancel(true);
}

void WorldSession::HandleInitiateTradeOpcode(WorldPackets::Trade::InitiateTrade& initiateTrade)
{
    if (GetPlayer()->m_trade)
        return;

    WorldPackets::Trade::TradeStatus info;
    if (!GetPlayer()->IsAlive())
    {
        info.Status = TRADE_STATUS_DEAD;
        SendTradeStatus(info);
        return;
    }

    if (GetPlayer()->HasUnitState(UNIT_STATE_STUNNED))
    {
        info.Status = TRADE_STATUS_STUNNED;
        SendTradeStatus(info);
        return;
    }

    if (isLogingOut())
    {
        info.Status = TRADE_STATUS_LOGGING_OUT;
        SendTradeStatus(info);
        return;
    }

    if (GetPlayer()->IsInFlight())
    {
        info.Status = TRADE_STATUS_TOO_FAR_AWAY;
        SendTradeStatus(info);
        return;
    }

    if (GetPlayer()->getLevel() < sWorld->getIntConfig(CONFIG_TRADE_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_TRADE_REQ), sWorld->getIntConfig(CONFIG_TRADE_LEVEL_REQ));
        return;
    }

    Player* pOther = ObjectAccessor::FindPlayer(initiateTrade.Guid);
    if (!pOther)
    {
        info.Status = TRADE_STATUS_NO_TARGET;
        SendTradeStatus(info);
        return;
    }

    if (pOther == GetPlayer() || pOther->m_trade)
    {
        info.Status = TRADE_STATUS_PLAYER_BUSY;
        SendTradeStatus(info);
        return;
    }

    if (!pOther->IsAlive())
    {
        info.Status = TRADE_STATUS_TARGET_DEAD;
        SendTradeStatus(info);
        return;
    }

    if (pOther->IsInFlight())
    {
        info.Status = TRADE_STATUS_TOO_FAR_AWAY;
        SendTradeStatus(info);
        return;
    }

    if (pOther->HasUnitState(UNIT_STATE_STUNNED))
    {
        info.Status = TRADE_STATUS_TARGET_STUNNED;
        SendTradeStatus(info);
        return;
    }

    if (pOther->GetSession()->isLogingOut())
    {
        info.Status = TRADE_STATUS_TARGET_LOGGING_OUT;
        SendTradeStatus(info);
        return;
    }

    if (pOther->GetSocial()->HasIgnore(GetPlayer()->GetGUID()))
    {
        info.Status = TRADE_STATUS_PLAYER_IGNORED;
        SendTradeStatus(info);
        return;
    }

    if ((pOther->GetTeam() != _player->GetTeam() ||
        pOther->HasFlag(PLAYER_FLAGS_EX, PLAYER_FLAGS_EX_MERCENARY_MODE) ||
        _player->HasFlag(PLAYER_FLAGS_EX, PLAYER_FLAGS_EX_MERCENARY_MODE)) &&
        (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_TRADE) &&
        !HasPermission(rbac::RBAC_PERM_ALLOW_TWO_SIDE_TRADE)))
    {
        info.Status = TRADE_STATUS_WRONG_FACTION;
        SendTradeStatus(info);
        return;
    }

    if (!pOther->IsWithinDistInMap(_player, TRADE_DISTANCE, false))
    {
        info.Status = TRADE_STATUS_TOO_FAR_AWAY;
        SendTradeStatus(info);
        return;
    }

    if (pOther->getLevel() < sWorld->getIntConfig(CONFIG_TRADE_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_TRADE_OTHER_REQ), sWorld->getIntConfig(CONFIG_TRADE_LEVEL_REQ));
        return;
    }

    // OK start trade
    _player->m_trade = new TradeData(_player, pOther);
    pOther->m_trade = new TradeData(pOther, _player);

    info.Status = TRADE_STATUS_PROPOSED;
    info.Partner = _player->GetGUID();
    pOther->GetSession()->SendTradeStatus(info);
}

void WorldSession::HandleSetTradeGoldOpcode(WorldPackets::Trade::SetTradeGold& setTradeGold)
{
    TradeData* my_trade = _player->GetTradeData();
    if (!my_trade)
        return;

    my_trade->UpdateClientStateIndex();
    my_trade->SetMoney(setTradeGold.Coinage);
}

void WorldSession::HandleSetTradeItemOpcode(WorldPackets::Trade::SetTradeItem& setTradeItem)
{
    TradeData* my_trade = _player->GetTradeData();
    if (!my_trade)
        return;

    WorldPackets::Trade::TradeStatus info;
    // invalid slot number
    if (setTradeItem.TradeSlot >= TRADE_SLOT_COUNT)
    {
        info.Status = TRADE_STATUS_CANCELLED;
        SendTradeStatus(info);
        return;
    }

    // check cheating, can't fail with correct client operations
    Item* item = _player->GetItemByPos(setTradeItem.PackSlot, setTradeItem.ItemSlotInPack);
    if (!item || (setTradeItem.TradeSlot != TRADE_SLOT_NONTRADED && !item->CanBeTraded(false, true)))
    {
        info.Status = TRADE_STATUS_CANCELLED;
        SendTradeStatus(info);
        return;
    }

    ObjectGuid iGUID = item->GetGUID();

    // prevent place single item into many trade slots using cheating and client bugs
    if (my_trade->HasItem(iGUID))
    {
        // cheating attempt
        info.Status = TRADE_STATUS_CANCELLED;
        SendTradeStatus(info);
        return;
    }

    my_trade->UpdateClientStateIndex();

    if (setTradeItem.TradeSlot != TRADE_SLOT_NONTRADED && item->IsBindedNotWith(my_trade->GetTrader()))
    {
        info.Status = TRADE_STATUS_NOT_ON_TAPLIST;
        info.TradeSlot = setTradeItem.TradeSlot;
        SendTradeStatus(info);
        return;
    }

    my_trade->SetItem(TradeSlots(setTradeItem.TradeSlot), item);
}

void WorldSession::HandleClearTradeItemOpcode(WorldPackets::Trade::ClearTradeItem& clearTradeItem)
{
    TradeData* my_trade = _player->m_trade;
    if (!my_trade)
        return;

    my_trade->UpdateClientStateIndex();

    // invalid slot number
    if (clearTradeItem.TradeSlot >= TRADE_SLOT_COUNT)
        return;

    my_trade->SetItem(TradeSlots(clearTradeItem.TradeSlot), NULL);
}

void WorldSession::HandleSetTradeCurrencyOpcode(WorldPackets::Trade::SetTradeCurrency& /*setTradeCurrency*/)
{
}
