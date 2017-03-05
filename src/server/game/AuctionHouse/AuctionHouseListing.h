/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _AUCTION_HOUSE_LISTING_H
#define _AUCTION_HOUSE_LISTING_H

#include "Define.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#include <array>

enum InventoryResult;

class AuctionHouseObject;
namespace boost
{
    class mutex;
}


constexpr uint32 SkillFieldsSize = 384; // PLAYER_SKILL_INFO_1_1 size
constexpr uint32 AuctionItemPacketSize = (12 * 4 + 8 * 2 + (MAX_INSPECTED_ENCHANTMENT_SLOT * 12));

class AuctionListingEvent
{
    public:
        AuctionListingEvent(Player* player, uint32 faction);
        virtual ~AuctionListingEvent();
        virtual bool Execute() = 0;

        bool ExecuteBase(Player* player);

    protected:
        // checks
        ObjectGuid _playerGuid;
        uint32 _faction;
        uint32 _mapId;
};

class AuctionListOwnItemsEvent : public AuctionListingEvent
{
    public:
        AuctionListOwnItemsEvent(Player* player, uint32 faction, uint32 listFrom);
        bool Execute() override;

    private:
        uint32 _listFrom;
};

class AuctionListItemsEvent : public AuctionListingEvent
{
    public:
        AuctionListItemsEvent(Player* player, uint32 faction, std::string const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable, uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality, uint8 getAll);
        bool Execute() override;

    private:
        bool BuildListAuctionItems(AuctionHouseObject* auctionHouse, WorldPacket& data, Player* player,
            std::wstring const& wsearchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
            uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
            uint32& count, uint32& totalcount, bool getall);

        std::string _searchedname;
        uint32 _listfrom;
        uint8 _levelmin;
        uint8 _levelmax;
        uint8 _usable;
        uint32 _inventoryType;
        uint32 _itemClass;
        uint32 _itemSubClass;
        uint32 _quality;
        uint8 _getAll;

        // Duplication of CanUseItem

        InventoryResult CanUseItem(Item const* pItem, Player const* player) const;
        InventoryResult CanUseItem(ItemTemplate const* proto, Player const* player) const;
        bool HasSkill(uint32 skill) const;
        uint16 GetSkillValue(uint32 skill) const;
        bool HasSpell(uint32 spell) const;
        ReputationRank GetReputationRank(uint32 faction, Player const* player) const;

        bool _isAlive;
        uint8 _level;
        SkillStatusMap _mSkillStatus;
        PlayerSpellMap _spells;
        std::array<uint32, SkillFieldsSize> _skillFields;
        FactionStateList _factions;
};

class AuctionListBidsEvent : public AuctionListingEvent
{
    public:
        AuctionListBidsEvent(Player* player, uint32 faction, WorldPacket& data);
        bool Execute() override;

    private:
        WorldPacket _data;
};

namespace AuctionHouseListing
{
    void AuctionHouseListingThread();

    void AddListOwnItemsEvent(Player* player, uint32 faction, uint32 listFrom);
    void AddListItemsEvent(Player* player, uint32 faction, std::string const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable, uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality, uint8 getAll);
    void AddListBidsEvent(Player* player, uint32 faction, WorldPacket& data);

    void SetListingAllowed(bool allowed);
    bool IsListingAllowed();

    boost::mutex* GetListingLock();
}

#endif
