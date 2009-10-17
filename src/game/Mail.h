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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef TRINITY_MAIL_H
#define TRINITY_MAIL_H

#include "Common.h"
#include <map>

class Item;

#define MAIL_BODY_ITEM_TEMPLATE 8383                        // - plain letter, A Dusty Unsent Letter: 889
#define MAX_MAIL_ITEMS 12

enum MailCheckMask
{
    MAIL_CHECK_MASK_NONE        = 0,
    MAIL_CHECK_MASK_READ        = 1,
    MAIL_CHECK_MASK_AUCTION     = 4,
    MAIL_CHECK_MASK_COD_PAYMENT = 8,
    MAIL_CHECK_MASK_RETURNED    = 16
};

enum MailMessageType
{
    MAIL_NORMAL         = 0,
    MAIL_AUCTION        = 2,
    MAIL_CREATURE       = 3,                                // client send CMSG_CREATURE_QUERY on this mailmessagetype
    MAIL_GAMEOBJECT     = 4,                                // client send CMSG_GAMEOBJECT_QUERY on this mailmessagetype
    MAIL_ITEM           = 5,                                // client send CMSG_ITEM_QUERY on this mailmessagetype
};

enum MailState
{
    MAIL_STATE_UNCHANGED = 1,
    MAIL_STATE_CHANGED   = 2,
    MAIL_STATE_DELETED   = 3
};

enum MailAuctionAnswers
{
    AUCTION_OUTBIDDED           = 0,
    AUCTION_WON                 = 1,
    AUCTION_SUCCESSFUL          = 2,
    AUCTION_EXPIRED             = 3,
    AUCTION_CANCELLED_TO_BIDDER = 4,
    AUCTION_CANCELED            = 5,
    AUCTION_SALE_PENDING        = 6
};

// gathered from Stationery.dbc
enum MailStationery
{
    MAIL_STATIONERY_UNKNOWN = 0x01,
    MAIL_STATIONERY_NORMAL  = 0x29,
    MAIL_STATIONERY_GM      = 0x3D,
    MAIL_STATIONERY_AUCTION = 0x3E,
    MAIL_STATIONERY_VAL     = 0x40,
    MAIL_STATIONERY_CHR     = 0x41
};

struct MailItemInfo
{
    uint32 item_guid;
    uint32 item_template;
};

struct MailItem
{
    MailItem() : item_slot(0), item_guidlow(0), item_template(0), item(NULL) {}

    uint8 item_slot;                                        // slot in mail
    uint32 item_guidlow;                                    // item guid (low part)
    uint32 item_template;                                   // item entry
    Item *item;                                             // item pointer

    void deleteItem(bool inDB = false);
};

typedef std::map<uint32, MailItem> MailItemMap;

class MailItemsInfo
{
    public:
        MailItemMap::const_iterator begin() const { return i_MailItemMap.begin(); }
        MailItemMap::const_iterator end() const { return i_MailItemMap.end(); }
        MailItemMap::iterator begin() { return i_MailItemMap.begin(); }
        MailItemMap::iterator end() { return i_MailItemMap.end(); }

        void AddItem(uint32 guidlow, uint32 _template, Item *item, uint8 slot = 0)
        {
            MailItem mailItem;
            mailItem.item_slot = slot;
            mailItem.item_guidlow = guidlow;
            mailItem.item_template = _template;
            mailItem.item = item;
            i_MailItemMap[guidlow] = mailItem;
        }

        void AddItem(uint32 guidlow, uint8 slot = 0)
        {
            MailItem mailItem;
            mailItem.item_guidlow = guidlow;
            mailItem.item_slot = slot;
            i_MailItemMap[guidlow] = mailItem;
        }

        uint8 size() const { return i_MailItemMap.size(); }
        bool empty() const { return i_MailItemMap.empty(); }

        void deleteIncludedItems(bool inDB = false)
        {
            for (MailItemMap::iterator mailItemIter = begin(); mailItemIter != end(); ++mailItemIter)
            {
                MailItem& mailItem = mailItemIter->second;
                mailItem.deleteItem(inDB);
            }
        }
    private:
        MailItemMap i_MailItemMap;                          // Keep the items in a map to avoid duplicate guids (which can happen), store only low part of guid
};

struct Mail
{
    uint32 messageID;
    uint8 messageType;
    uint8 stationery;
    uint16 mailTemplateId;
    uint32 sender;
    uint32 receiver;
    std::string subject;
    uint32 itemTextId;
    std::vector<MailItemInfo> items;
    std::vector<uint32> removedItems;
    time_t expire_time;
    time_t deliver_time;
    uint32 money;
    uint32 COD;
    uint32 checked;
    MailState state;

    void AddItem(uint32 itemGuidLow, uint32 item_template)
    {
        MailItemInfo mii;
        mii.item_guid = itemGuidLow;
        mii.item_template = item_template;
        items.push_back(mii);
    }

    void AddAllItems(MailItemsInfo& pMailItemsInfo)
    {
        for (MailItemMap::iterator mailItemIter = pMailItemsInfo.begin(); mailItemIter != pMailItemsInfo.end(); ++mailItemIter)
        {
            MailItem& mailItem = mailItemIter->second;
            AddItem(mailItem.item_guidlow, mailItem.item_template);
        }
    }

    bool RemoveItem(uint32 item_guid)
    {
        for (std::vector<MailItemInfo>::iterator itr = items.begin(); itr != items.end(); ++itr)
        {
            if(itr->item_guid == item_guid)
            {
                items.erase(itr);
                return true;
            }
        }
        return false;
    }

    bool HasItems() const { return !items.empty(); }
};
#endif

