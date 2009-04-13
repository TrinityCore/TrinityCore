/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Mail.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "UpdateMask.h"
#include "Unit.h"
#include "Language.h"
#include "AuctionHouseBot.h"
#include "DBCStores.h"

void MailItem::deleteItem( bool inDB )
{
    if(item)
    {
        if(inDB)
            CharacterDatabase.PExecute("DELETE FROM item_instance WHERE guid='%u'", item->GetGUIDLow());

        delete item;
        item=NULL;
    }
}

void WorldSession::HandleSendMail(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+1+1+1+4+4+1+4+4+8+1);

    uint64 mailbox, unk3;
    std::string receiver, subject, body;
    uint32 unk1, unk2, money, COD;
    uint8 unk4;
    recv_data >> mailbox;
    recv_data >> receiver;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    // recheck
    CHECK_PACKET_SIZE(recv_data, 8+(receiver.size()+1)+1+1+4+4+1+4+4+8+1);

    recv_data >> subject;

    // recheck
    CHECK_PACKET_SIZE(recv_data, 8+(receiver.size()+1)+(subject.size()+1)+1+4+4+1+4+4+8+1);

    recv_data >> body;

    // recheck
    CHECK_PACKET_SIZE(recv_data, 8+(receiver.size()+1)+(subject.size()+1)+(body.size()+1)+4+4+1+4+4+8+1);

    recv_data >> unk1;                                      // stationery?
    recv_data >> unk2;                                      // 0x00000000

    MailItemsInfo mi;

    uint8 items_count;
    recv_data >> items_count;                               // attached items count

    if(items_count > 12)                                    // client limit
        return;

    // recheck
    CHECK_PACKET_SIZE(recv_data, 8+(receiver.size()+1)+(subject.size()+1)+(body.size()+1)+4+4+1+items_count*(1+8)+4+4+8+1);

    if(items_count)
    {
        for(uint8 i = 0; i < items_count; ++i)
        {
            uint8  item_slot;
            uint64 item_guid;
            recv_data >> item_slot;
            recv_data >> item_guid;
            mi.AddItem(GUID_LOPART(item_guid), item_slot);
        }
    }

    recv_data >> money >> COD;                              // money and cod
    recv_data >> unk3;                                      // const 0
    recv_data >> unk4;                                      // const 0

    items_count = mi.size();                                // this is the real size after the duplicates have been removed

    if (receiver.empty())
        return;

    Player* pl = _player;

    uint64 rc = 0;
    if(normalizePlayerName(receiver))
        rc = objmgr.GetPlayerGUIDByName(receiver);

    if (!rc)
    {
        sLog.outDetail("Player %u is sending mail to %s (GUID: not existed!) with subject %s and body %s includes %u items, %u copper and %u COD copper with unk1 = %u, unk2 = %u",
            pl->GetGUIDLow(), receiver.c_str(), subject.c_str(), body.c_str(), items_count, money, COD, unk1, unk2);
        pl->SendMailResult(0, 0, MAIL_ERR_RECIPIENT_NOT_FOUND);
        return;
    }

    sLog.outDetail("Player %u is sending mail to %s (GUID: %u) with subject %s and body %s includes %u items, %u copper and %u COD copper with unk1 = %u, unk2 = %u", pl->GetGUIDLow(), receiver.c_str(), GUID_LOPART(rc), subject.c_str(), body.c_str(), items_count, money, COD, unk1, unk2);

    if(pl->GetGUID() == rc)
    {
        pl->SendMailResult(0, 0, MAIL_ERR_CANNOT_SEND_TO_SELF);
        return;
    }

    uint32 cost = items_count ? 30 * items_count : 30;  // price hardcoded in client

    uint32 reqmoney = cost + money;

    if (pl->GetMoney() < reqmoney)
    {
        pl->SendMailResult(0, 0, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    Player *receive = objmgr.GetPlayer(rc);

    uint32 rc_team = 0;
    uint8 mails_count = 0;                                  //do not allow to send to one player more than 100 mails

    if(receive)
    {
        rc_team = receive->GetTeam();
        mails_count = receive->GetMailSize();
    }
    else
    {
        rc_team = objmgr.GetPlayerTeamByGUID(rc);
        QueryResult* result = CharacterDatabase.PQuery("SELECT COUNT(*) FROM mail WHERE receiver = '%u'", GUID_LOPART(rc));
        if(result)
        {
            Field *fields = result->Fetch();
            mails_count = fields[0].GetUInt32();
            delete result;
        }
    }
    //do not allow to have more than 100 mails in mailbox.. mails count is in opcode uint8!!! - so max can be 255..
    if (mails_count > 100)
    {
        pl->SendMailResult(0, 0, MAIL_ERR_INTERNAL_ERROR);
        return;
    }
    // test the receiver's Faction...
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_MAIL) && pl->GetTeam() != rc_team && GetSecurity() == SEC_PLAYER)
    {
        pl->SendMailResult(0, 0, MAIL_ERR_NOT_YOUR_TEAM);
        return;
    }

    if (items_count)
    {
        for(MailItemMap::iterator mailItemIter = mi.begin(); mailItemIter != mi.end(); ++mailItemIter)
        {
            MailItem& mailItem = mailItemIter->second;

            if(!mailItem.item_guidlow)
            {
                pl->SendMailResult(0, 0, MAIL_ERR_INTERNAL_ERROR);
                return;
            }

            mailItem.item = pl->GetItemByGuid(MAKE_NEW_GUID(mailItem.item_guidlow, 0, HIGHGUID_ITEM));
            // prevent sending bag with items (cheat: can be placed in bag after adding equipped empty bag to mail)
            if(!mailItem.item || !mailItem.item->CanBeTraded())
            {
                pl->SendMailResult(0, 0, MAIL_ERR_INTERNAL_ERROR);
                return;
            }
            if (mailItem.item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAGS_CONJURED) || mailItem.item->GetUInt32Value(ITEM_FIELD_DURATION))
            {
                pl->SendMailResult(0, 0, MAIL_ERR_INTERNAL_ERROR);
                return;
            }

            if(COD && mailItem.item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAGS_WRAPPED))
            {
                pl->SendMailResult(0, 0, MAIL_ERR_CANT_SEND_WRAPPED_COD);
                return;
            }
        }
    }
    pl->SendMailResult(0, 0, MAIL_OK);

    uint32 itemTextId = 0;
    if (!body.empty())
    {
        itemTextId = objmgr.CreateItemText( body );
    }

    pl->ModifyMoney( -int32(reqmoney) );
    pl->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL, cost);

    bool needItemDelay = false;

    if(items_count > 0 || money > 0)
    {
        uint32 rc_account = 0;
        if(receive)
            rc_account = receive->GetSession()->GetAccountId();
        else
            rc_account = objmgr.GetPlayerAccountIdByGUID(rc);

        if (items_count > 0)
        {
            for(MailItemMap::iterator mailItemIter = mi.begin(); mailItemIter != mi.end(); ++mailItemIter)
            {
                MailItem& mailItem = mailItemIter->second;
                if(!mailItem.item)
                    continue;

                mailItem.item_template = mailItem.item ? mailItem.item->GetEntry() : 0;

                if( GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE) )
                {
                    sLog.outCommand(GetAccountId(), "GM %s (Account: %u) mail item: %s (Entry: %u Count: %u) to player: %s (Account: %u)",
                        GetPlayerName(), GetAccountId(), mailItem.item->GetProto()->Name1, mailItem.item->GetEntry(), mailItem.item->GetCount(), receiver.c_str(), rc_account);
                }

                pl->MoveItemFromInventory(mailItem.item->GetBagSlot(), mailItem.item->GetSlot(), true);
                CharacterDatabase.BeginTransaction();
                mailItem.item->DeleteFromInventoryDB();     //deletes item from character's inventory
                mailItem.item->SaveToDB();                  // recursive and not have transaction guard into self, item not in inventory and can be save standalone
                // owner in data will set at mail receive and item extracting
                CharacterDatabase.PExecute("UPDATE item_instance SET owner_guid = '%u' WHERE guid='%u'", GUID_LOPART(rc), mailItem.item->GetGUIDLow());
                CharacterDatabase.CommitTransaction();
            }

            // if item send to character at another account, then apply item delivery delay
            needItemDelay = pl->GetSession()->GetAccountId() != rc_account;
        }

        if(money > 0 &&  GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE))
        {
            sLog.outCommand(GetAccountId(),"GM %s (Account: %u) mail money: %u to player: %s (Account: %u)",
                GetPlayerName(), GetAccountId(), money, receiver.c_str(), rc_account);
        }
    }

    // If theres is an item, there is a one hour delivery delay if sent to another account's character.
    uint32 deliver_delay = needItemDelay ? sWorld.getConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;

    // will delete item or place to receiver mail list
    WorldSession::SendMailTo(receive, MAIL_NORMAL, MAIL_STATIONERY_NORMAL, pl->GetGUIDLow(), GUID_LOPART(rc), subject, itemTextId, &mi, money, COD, MAIL_CHECK_MASK_NONE, deliver_delay);

    CharacterDatabase.BeginTransaction();
    pl->SaveInventoryAndGoldToDB();
    CharacterDatabase.CommitTransaction();
}

//called when mail is read
void WorldSession::HandleMarkAsRead(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4);

    uint64 mailbox;
    uint32 mailId;
    recv_data >> mailbox;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    recv_data >> mailId;
    Player *pl = _player;
    Mail *m = pl->GetMail(mailId);
    if (m)
    {
        if (pl->unReadMails)
            --pl->unReadMails;
        m->checked = m->checked | MAIL_CHECK_MASK_READ;
        // m->expire_time = time(NULL) + (30 * DAY);  // Expire time do not change at reading mail
        pl->m_mailsUpdated = true;
        m->state = MAIL_STATE_CHANGED;
    }
}

//called when client deletes mail
void WorldSession::HandleMailDelete(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4);

    uint64 mailbox;
    uint32 mailId;
    recv_data >> mailbox;
    recv_data >> mailId;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    Player* pl = _player;
    pl->m_mailsUpdated = true;
    Mail *m = pl->GetMail(mailId);
    if(m)
        m->state = MAIL_STATE_DELETED;
    pl->SendMailResult(mailId, MAIL_DELETED, 0);
}

void WorldSession::HandleReturnToSender(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4);

    uint64 mailbox;
    uint32 mailId;
    recv_data >> mailbox;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    recv_data >> mailId;
    Player *pl = _player;
    Mail *m = pl->GetMail(mailId);
    if(!m || m->state == MAIL_STATE_DELETED || m->deliver_time > time(NULL))
    {
        pl->SendMailResult(mailId, MAIL_RETURNED_TO_SENDER, MAIL_ERR_INTERNAL_ERROR);
        return;
    }
    //we can return mail now
    //so firstly delete the old one
    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("DELETE FROM mail WHERE id = '%u'", mailId);
                                                            // needed?
    CharacterDatabase.PExecute("DELETE FROM mail_items WHERE mail_id = '%u'", mailId);
    CharacterDatabase.CommitTransaction();
    pl->RemoveMail(mailId);

    MailItemsInfo mi;

    if(m->HasItems())
    {
        for(std::vector<MailItemInfo>::iterator itr2 = m->items.begin(); itr2 != m->items.end(); ++itr2)
        {
            Item *item = pl->GetMItem(itr2->item_guid);
            if(item)
                mi.AddItem(item->GetGUIDLow(), item->GetEntry(), item);
            else
            {
                //WTF?
            }

            pl->RemoveMItem(itr2->item_guid);
        }
    }

    if (m->sender == AHBplayerGUID)
    {
        SendReturnToSender(MAIL_CREATURE, GetAccountId(), m->receiver, m->sender, m->subject, m->itemTextId, &mi, m->money, m->mailTemplateId);
    }
    else
    {
        SendReturnToSender(MAIL_NORMAL, GetAccountId(), m->receiver, m->sender, m->subject, m->itemTextId, &mi, m->money, m->mailTemplateId);
    }

    delete m;                                               //we can deallocate old mail
    pl->SendMailResult(mailId, MAIL_RETURNED_TO_SENDER, 0);
}

void WorldSession::SendReturnToSender(uint8 messageType, uint32 sender_acc, uint32 sender_guid, uint32 receiver_guid, const std::string& subject, uint32 itemTextId, MailItemsInfo *mi, uint32 money, uint16 mailTemplateId )
{
    if(messageType != MAIL_NORMAL)                          // return only to players
    {
        mi->deleteIncludedItems(true);
        return;
    }

    Player *receiver = objmgr.GetPlayer(MAKE_NEW_GUID(receiver_guid, 0, HIGHGUID_PLAYER));

    uint32 rc_account = 0;
    if(!receiver)
        rc_account = objmgr.GetPlayerAccountIdByGUID(MAKE_NEW_GUID(receiver_guid, 0, HIGHGUID_PLAYER));

    if(!receiver && !rc_account)                            // sender not exist
    {
        mi->deleteIncludedItems(true);
        return;
    }

    // prepare mail and send in other case
    bool needItemDelay = false;

    if(mi && !mi->empty())
    {
        // if item send to character at another account, then apply item delivery delay
        needItemDelay = sender_acc != rc_account;

        // set owner to new receiver (to prevent delete item with sender char deleting)
        CharacterDatabase.BeginTransaction();
        for(MailItemMap::iterator mailItemIter = mi->begin(); mailItemIter != mi->end(); ++mailItemIter)
        {
            MailItem& mailItem = mailItemIter->second;
            mailItem.item->SaveToDB();                  // item not in inventory and can be save standalone
            // owner in data will set at mail receive and item extracting
            CharacterDatabase.PExecute("UPDATE item_instance SET owner_guid = '%u' WHERE guid='%u'", receiver_guid, mailItem.item->GetGUIDLow());
        }
        CharacterDatabase.CommitTransaction();
    }

    // If theres is an item, there is a one hour delivery delay.
    uint32 deliver_delay = needItemDelay ? sWorld.getConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;

    // will delete item or place to receiver mail list
    WorldSession::SendMailTo(receiver, MAIL_NORMAL, MAIL_STATIONERY_NORMAL, sender_guid, receiver_guid, subject, itemTextId, mi, money, 0, MAIL_CHECK_MASK_RETURNED,deliver_delay,mailTemplateId);
}

//called when player takes item attached in mail
void WorldSession::HandleTakeItem(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4+4);

    uint64 mailbox;
    uint32 mailId;
    uint32 itemId;
    recv_data >> mailbox;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    recv_data >> mailId;
    recv_data >> itemId;                                    // item guid low?
    Player* pl = _player;

    Mail* m = pl->GetMail(mailId);
    if(!m || m->state == MAIL_STATE_DELETED || m->deliver_time > time(NULL))
    {
        pl->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // prevent cheating with skip client money check
    if(pl->GetMoney() < m->COD)
    {
        pl->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    Item *it = pl->GetMItem(itemId);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem( NULL_BAG, NULL_SLOT, dest, it, false );
    if( msg == EQUIP_ERR_OK )
    {
        m->RemoveItem(itemId);
        m->removedItems.push_back(itemId);

        if (m->COD > 0)                                     //if there is COD, take COD money from player and send them to sender by mail
        {
            uint64 sender_guid = MAKE_NEW_GUID(m->sender, 0, HIGHGUID_PLAYER);
            Player *receive = objmgr.GetPlayer(sender_guid);

            uint32 sender_accId = 0;

            if( GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_GM_LOG_TRADE) )
            {
                std::string sender_name;
                if(receive)
                {
                    sender_accId = receive->GetSession()->GetAccountId();
                    sender_name = receive->GetName();
                }
                else
                {
                    // can be calculated early
                    sender_accId = objmgr.GetPlayerAccountIdByGUID(sender_guid);

                    if(!objmgr.GetPlayerNameByGUID(sender_guid,sender_name))
                        sender_name = objmgr.GetTrinityStringForDBCLocale(LANG_UNKNOWN);
                }
                sLog.outCommand(GetAccountId(),"GM %s (Account: %u) receive mail item: %s (Entry: %u Count: %u) and send COD money: %u to player: %s (Account: %u)",
                    GetPlayerName(),GetAccountId(),it->GetProto()->Name1,it->GetEntry(),it->GetCount(),m->COD,sender_name.c_str(),sender_accId);
            }
            else if(!receive)
                sender_accId = objmgr.GetPlayerAccountIdByGUID(sender_guid);

            // check player existence
            if(receive || sender_accId)
            {
                WorldSession::SendMailTo(receive, MAIL_NORMAL, MAIL_STATIONERY_NORMAL, m->receiver, m->sender, m->subject, 0, NULL, m->COD, 0, MAIL_CHECK_MASK_COD_PAYMENT);
            }

            pl->ModifyMoney( -int32(m->COD) );
        }
        m->COD = 0;
        m->state = MAIL_STATE_CHANGED;
        pl->m_mailsUpdated = true;
        pl->RemoveMItem(it->GetGUIDLow());

        uint32 count = it->GetCount();                      // save counts before store and possible merge with deleting
        pl->MoveItemToInventory(dest,it,true);

        CharacterDatabase.BeginTransaction();
        pl->SaveInventoryAndGoldToDB();
        pl->_SaveMail();
        CharacterDatabase.CommitTransaction();

        pl->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_OK, 0, itemId, count);
    }
    else
        pl->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_BAG_FULL, msg);
}

void WorldSession::HandleTakeMoney(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4);

    uint64 mailbox;
    uint32 mailId;
    recv_data >> mailbox;
    recv_data >> mailId;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    Player *pl = _player;

    Mail* m = pl->GetMail(mailId);
    if(!m || m->state == MAIL_STATE_DELETED || m->deliver_time > time(NULL))
    {
        pl->SendMailResult(mailId, MAIL_MONEY_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    pl->SendMailResult(mailId, MAIL_MONEY_TAKEN, 0);

    pl->ModifyMoney(m->money);
    m->money = 0;
    m->state = MAIL_STATE_CHANGED;
    pl->m_mailsUpdated = true;

    // save money and mail to prevent cheating
    CharacterDatabase.BeginTransaction();
    pl->SaveDataFieldToDB();                                // contains money
    pl->_SaveMail();
    CharacterDatabase.CommitTransaction();
}

//called when player lists his received mails
void WorldSession::HandleGetMail(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8);

    uint64 mailbox;
    recv_data >> mailbox;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    Player* pl = _player;

    //load players mails, and mailed items
    if(!pl->m_mailsLoaded)
        pl ->_LoadMail();

    // client can't work with packets > max int16 value
    const uint32 maxPacketSize = 32767;

    uint32 mails_count = 0;                                 // real send to client mails amount

    WorldPacket data(SMSG_MAIL_LIST_RESULT, (200));         // guess size
    data << uint8(0);                                       // mail's count
    time_t cur_time = time(NULL);

    for(PlayerMails::iterator itr = pl->GetmailBegin(); itr != pl->GetmailEnd(); ++itr)
    {
        // skip deleted or not delivered (deliver delay not expired) mails
        if ((*itr)->state == MAIL_STATE_DELETED || cur_time < (*itr)->deliver_time)
            continue;

        uint8 item_count = (*itr)->items.size();            // max count is MAX_MAIL_ITEMS (12)

        size_t next_mail_size = 2+4+1+8+4*8+((*itr)->subject.size()+1)+1+item_count*(1+4+4+6*3*4+4+4+1+4+4+4);

        if(data.wpos()+next_mail_size > maxPacketSize)
            break;

        data << (uint16) 0x0040;                            // unknown 2.3.0, different values
        data << (uint32) (*itr)->messageID;                 // Message ID
        data << (uint8) (*itr)->messageType;                // Message Type

        switch((*itr)->messageType)
        {
            case MAIL_NORMAL:                               // sender guid
                data << uint64(MAKE_NEW_GUID((*itr)->sender, 0, HIGHGUID_PLAYER));
                break;
            case MAIL_CREATURE:
            case MAIL_GAMEOBJECT:
            case MAIL_AUCTION:
                data << (uint32) (*itr)->sender;            // creature/gameobject entry, auction id
                break;
            case MAIL_ITEM:                                 // item entry (?) sender = "Unknown", NYI
                break;
        }

        data << (uint32) (*itr)->COD;                       // COD
        data << (uint32) (*itr)->itemTextId;                // sure about this
        data << (uint32) 0;                                 // unknown
        data << (uint32) (*itr)->stationery;                // stationery (Stationery.dbc)
        data << (uint32) (*itr)->money;                     // Gold
        data << (uint32) 0x04;                              // unknown, 0x4 - auction, 0x10 - normal
                                                            // Time
        data << (float)  ((*itr)->expire_time-time(NULL))/DAY;
        data << (uint32) (*itr)->mailTemplateId;            // mail template (MailTemplate.dbc)
        data << (*itr)->subject;                            // Subject string - once 00, when mail type = 3

        data << (uint8) item_count;                         // client limit is 0x10

        for(uint8 i = 0; i < item_count; ++i)
        {
            Item *item = pl->GetMItem((*itr)->items[i].item_guid);
            // item index (0-6?)
            data << (uint8)  i;
            // item guid low?
            data << (uint32) (item ? item->GetGUIDLow() : 0);
            // entry
            data << (uint32) (item ? item->GetEntry() : 0);
            for(uint8 j = 0; j < MAX_INSPECTED_ENCHANTMENT_SLOT; ++j)
            {
                // unsure
                data << (uint32) (item ? item->GetEnchantmentCharges((EnchantmentSlot)j) : 0);
                // unsure
                data << (uint32) (item ? item->GetEnchantmentDuration((EnchantmentSlot)j) : 0);
                // unsure
                data << (uint32) (item ? item->GetEnchantmentId((EnchantmentSlot)j) : 0);
            }
            // can be negative
            data << (uint32) (item ? item->GetItemRandomPropertyId() : 0);
            // unk
            data << (uint32) (item ? item->GetItemSuffixFactor() : 0);
            // stack count
            data << (uint32) (item ? item->GetCount() : 0);
            // charges
            data << (uint32) (item ? item->GetSpellCharges() : 0);
            // durability
            data << (uint32) (item ? item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY) : 0);
            // durability
            data << (uint32) (item ? item->GetUInt32Value(ITEM_FIELD_DURABILITY) : 0);
            // unknown wotlk
            data << (uint8)  0;
        }

        mails_count += 1;
    }

    data.put<uint8>(0, mails_count);                        // set real send mails to client
    SendPacket(&data);

    // recalculate m_nextMailDelivereTime and unReadMails
    _player->UpdateNextMailTimeAndUnreads();
}

///this function is called when client needs mail message body, or when player clicks on item which has ITEM_FIELD_ITEM_TEXT_ID > 0
void WorldSession::HandleItemTextQuery(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,4+4+4);

    uint32 itemTextId;
    uint32 mailId;                                          //this value can be item id in bag, but it is also mail id
    uint32 unk;                                             //maybe something like state - 0x70000000

    recv_data >> itemTextId >> mailId >> unk;

    //some check needed, if player has item with guid mailId, or has mail with id mailId

    sLog.outDebug("CMSG_ITEM_TEXT_QUERY itemguid: %u, mailId: %u, unk: %u", itemTextId, mailId, unk);

    WorldPacket data(SMSG_ITEM_TEXT_QUERY_RESPONSE, (4+10));// guess size
    data << itemTextId;
    data << objmgr.GetItemText( itemTextId );
    SendPacket(&data);
}

//used when player copies mail body to his inventory
void WorldSession::HandleMailCreateTextItem(WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data,8+4);

    uint64 mailbox;
    uint32 mailId;

    recv_data >> mailbox >> mailId;

    if (!objmgr.IsGameObjectOfTypeInRange(_player, mailbox, GAMEOBJECT_TYPE_MAILBOX))
        return;

    Player *pl = _player;

    Mail* m = pl->GetMail(mailId);
    if(!m || !m->itemTextId || m->state == MAIL_STATE_DELETED || m->deliver_time > time(NULL))
    {
        pl->SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    Item *bodyItem = new Item;                              // This is not bag and then can be used new Item.
    if(!bodyItem->Create(objmgr.GenerateLowGuid(HIGHGUID_ITEM), MAIL_BODY_ITEM_TEMPLATE, pl))
    {
        delete bodyItem;
        return;
    }

    bodyItem->SetUInt32Value( ITEM_FIELD_ITEM_TEXT_ID , m->itemTextId );
    bodyItem->SetUInt32Value( ITEM_FIELD_CREATOR, m->sender);

    sLog.outDetail("HandleMailCreateTextItem mailid=%u",mailId);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem( NULL_BAG, NULL_SLOT, dest, bodyItem, false );
    if( msg == EQUIP_ERR_OK )
    {
        m->itemTextId = 0;
        m->state = MAIL_STATE_CHANGED;
        pl->m_mailsUpdated = true;

        pl->StoreItem(dest, bodyItem, true);
        //bodyItem->SetState(ITEM_NEW, pl); is set automatically
        pl->SendMailResult(mailId, MAIL_MADE_PERMANENT, 0);
    }
    else
    {
        pl->SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_ERR_BAG_FULL, msg);
        delete bodyItem;
    }
}

//TODO Fix me! ... this void has probably bad condition, but good data are sent
void WorldSession::HandleMsgQueryNextMailtime(WorldPacket & /*recv_data*/ )
{
    WorldPacket data(MSG_QUERY_NEXT_MAIL_TIME, 8);

    if(!_player->m_mailsLoaded)
        _player->_LoadMail();

    if( _player->unReadMails > 0 )
    {
        data << (uint32) 0;                                 // float
        data << (uint32) 0;                                 // count
        uint32 count = 0;
        for(PlayerMails::iterator itr = _player->GetmailBegin(); itr != _player->GetmailEnd(); ++itr)
        {
            Mail *m = (*itr);
            // not checked yet, already must be delivered
            if((m->checked & MAIL_CHECK_MASK_READ)==0 && (m->deliver_time <= time(NULL)))
            {
                ++count;

                if(count > 2)
                {
                    count = 2;
                    break;
                }

                data << (uint64) m->sender;                 // sender guid

                switch(m->messageType)
                {
                    case MAIL_AUCTION:
                        data << (uint32) 2;
                        data << (uint32) 2;
                        data << (uint32) m->stationery;
                        break;
                    default:
                        data << (uint32) 0;
                        data << (uint32) 0;
                        data << (uint32) m->stationery;
                        break;
                }
                data << (uint32) 0xC6000000;                // float unk, time or something
            }
        }
        data.put<uint32>(4, count);
    }
    else
    {
        data << (uint32) 0xC7A8C000;
        data << (uint32) 0x00000000;
    }
    SendPacket(&data);
}

void WorldSession::SendMailTo(Player* receiver, uint8 messageType, uint8 stationery, uint32 sender_guidlow_or_entry, uint32 receiver_guidlow, std::string subject, uint32 itemTextId, MailItemsInfo* mi, uint32 money, uint32 COD, uint32 checked, uint32 deliver_delay, uint16 mailTemplateId)
{
    if (receiver_guidlow == AHBplayerGUID)
    {
        if(messageType == MAIL_AUCTION && mi)        // auction mail with items
        {
            mi->deleteIncludedItems(true);
        }
        return;
    }
    uint32 mailId = objmgr.GenerateMailID();

    time_t deliver_time = time(NULL) + deliver_delay;

    //expire time if COD 3 days, if no COD 30 days, if auction sale pending 1 hour
    uint32 expire_delay;
    if(messageType == MAIL_AUCTION && !mi && !money)        // auction mail without any items and money
        expire_delay = HOUR;
    else
        expire_delay = (COD > 0) ? 3*DAY : 30*DAY;

    time_t expire_time = deliver_time + expire_delay;

    if(mailTemplateId && !sMailTemplateStore.LookupEntry(mailTemplateId))
    {
        sLog.outError( "WorldSession::SendMailTo - Mail have not existed MailTemplateId (%u), remove at send", mailTemplateId);
        mailTemplateId = 0;
    }

    if(receiver)
    {
        receiver->AddNewMailDeliverTime(deliver_time);

        if ( receiver->IsMailsLoaded() )
        {
            Mail * m = new Mail;
            m->messageID = mailId;
            m->messageType = messageType;
            m->stationery = stationery;
            m->mailTemplateId = mailTemplateId;
            m->sender = sender_guidlow_or_entry;
            m->receiver = receiver->GetGUIDLow();
            m->subject = subject;
            m->itemTextId = itemTextId;

            if(mi)
                m->AddAllItems(*mi);

            m->expire_time = expire_time;
            m->deliver_time = deliver_time;
            m->money = money;
            m->COD = COD;
            m->checked = checked;
            m->state = MAIL_STATE_UNCHANGED;

            receiver->AddMail(m);                           //to insert new mail to beginning of maillist

            if(mi)
            {
                for(MailItemMap::iterator mailItemIter = mi->begin(); mailItemIter != mi->end(); ++mailItemIter)
                {
                    MailItem& mailItem = mailItemIter->second;
                    if(mailItem.item)
                        receiver->AddMItem(mailItem.item);
                }
            }
        }
        else if(mi)
            mi->deleteIncludedItems();
    }
    else if(mi)
        mi->deleteIncludedItems();

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.escape_string(subject);
    CharacterDatabase.PExecute("INSERT INTO mail (id,messageType,stationery,mailTemplateId,sender,receiver,subject,itemTextId,has_items,expire_time,deliver_time,money,cod,checked) "
        "VALUES ('%u', '%u', '%u', '%u', '%u', '%u', '%s', '%u', '%u', '" I64FMTD "','" I64FMTD "', '%u', '%u', '%d')",
        mailId, messageType, stationery, mailTemplateId, sender_guidlow_or_entry, receiver_guidlow, subject.c_str(), itemTextId, (mi && !mi->empty() ? 1 : 0), (uint64)expire_time, (uint64)deliver_time, money, COD, checked);

    if(mi)
    {
        for(MailItemMap::const_iterator mailItemIter = mi->begin(); mailItemIter != mi->end(); ++mailItemIter)
        {
            MailItem const& mailItem = mailItemIter->second;
            CharacterDatabase.PExecute("INSERT INTO mail_items (mail_id,item_guid,item_template,receiver) VALUES ('%u', '%u', '%u','%u')", mailId, mailItem.item_guidlow, mailItem.item_template,receiver_guidlow);
        }
    }
    CharacterDatabase.CommitTransaction();
}

