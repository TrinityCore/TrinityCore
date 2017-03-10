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

#include "AuctionHouseListing.h"
#include "AuctionHouseMgr.h"
#include "Creature.h"
#include "GameEventMgr.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "GameTime.h"

#include <boost/thread/locks.hpp>
#include <boost/thread/mutex.hpp>

#include <condition_variable>
#include <vector>
#include <unordered_map>

namespace
{
    std::list<AuctionListingEvent*> _requestsNew;
    std::list<AuctionListingEvent*> _requests;

    std::mutex _listingLock;
    std::condition_variable _allowedCondition;
    std::atomic<bool> _auctionHouseListingAllowed;

    // Map of throttled players for GetAll, and throttle expiry time
    // Stored here, rather than player object to maintain persistence after logout
    std::unordered_map<ObjectGuid, time_t> GetAllThrottleMap;
}

void AuctionHouseListing::AuctionHouseListingThread()
{
    TC_LOG_INFO("misc", "Auction House Listing Thread starting");

    while (!World::IsStopped())
    {
        std::unique_lock<std::mutex> lock(_listingLock);
        while (!IsListingAllowed())
            _allowedCondition.wait(lock);

        // process new requests
        {
            if (!_requestsNew.empty())
                _requests.splice(_requests.end(), _requestsNew);
        }

        if (!_requests.empty())
        {
            for (auto itr = _requests.begin(); itr != _requests.end();)
            {
                if ((*itr)->Execute())
                {
                    delete (*itr);
                    itr = _requests.erase(itr);
                }
                else
                    ++itr;

                // main thread may be waiting for us
                if (!IsListingAllowed())
                    break;
            }
        }
    }

    TC_LOG_INFO("misc", "Auction House Listing thread exiting without problems.");
}

void AuctionHouseListing::SetListingAllowed(bool allowed)
{
    _auctionHouseListingAllowed = allowed;
}

bool AuctionHouseListing::IsListingAllowed()
{
    return _auctionHouseListingAllowed;
}

std::mutex* AuctionHouseListing::GetListingLock()
{
    return &_listingLock;
}

void AuctionHouseListing::Notify()
{
    _allowedCondition.notify_all();
}

void AuctionHouseListing::AddListOwnItemsEvent(Player* player, uint32 faction)
{
    _requestsNew.push_back(new AuctionListOwnItemsEvent(player, faction));
}

void AuctionHouseListing::AddListItemsEvent(Player* player, uint32 faction, std::string const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable, uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality, uint8 getAll)
{
    _requestsNew.push_back(new AuctionListItemsEvent(player, faction, searchedname, listfrom, levelmin, levelmax, usable, inventoryType, itemClass, itemSubClass, quality, getAll));
}

void AuctionHouseListing::AddListBidsEvent(Player* player, uint32 faction, WorldPacket& data)
{
    _requestsNew.push_back(new AuctionListBidsEvent(player, faction, data));
}

AuctionListingEvent::AuctionListingEvent(Player* player, uint32 faction) :
    _playerGuid(player->GetGUID()), _faction(faction), _mapId(player->GetMapId())
{
}

AuctionListingEvent::~AuctionListingEvent()
{
}

AuctionListOwnItemsEvent::AuctionListOwnItemsEvent(Player* player, uint32 faction) :
    AuctionListingEvent(player, faction)
{
}

AuctionListItemsEvent::AuctionListItemsEvent(Player* player, uint32 faction, std::string const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable, uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality, uint8 getAll) :
    AuctionListingEvent(player, faction), _searchedname(searchedname), _listfrom(listfrom), _levelmin(levelmin), _levelmax(levelmax), _usable(usable), _inventoryType(inventoryType), _itemClass(itemClass), _itemSubClass(itemSubClass), _quality(quality), _getAll(getAll),
    _isAlive(player->IsAlive()), _level(player->getLevel())
{
    _mSkillStatus = player->GetSkillMap();
    _spells = player->GetSpellMap();
    std::copy(player->GetUIntFieldValues() + PLAYER_SKILL_INFO_1_1, player->GetUIntFieldValues() + PLAYER_SKILL_INFO_1_1 + SkillFieldsSize, _skillFields.begin());
    _factions = player->GetReputationMgr().GetStateList();
}

AuctionListBidsEvent::AuctionListBidsEvent(Player* player, uint32 faction, WorldPacket& data) :
    AuctionListingEvent(player, faction), _data(data)
{
}

bool AuctionListingEvent::ExecuteBase(Player* player)
{
    if (!player || player->GetMapId() != _mapId)
        return false;

    return true;
}

bool AuctionListOwnItemsEvent::Execute()
{
    Player* player = ObjectAccessor::FindPlayer(_playerGuid);
    if (!AuctionListingEvent::ExecuteBase(player))
        return true;

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(_faction);
    WorldPacket listingData(SMSG_AUCTION_OWNER_LIST_RESULT, (4 + 4 + 4) + 50 * AuctionItemPacketSize);
    listingData << (uint32)0;       // placeholder

    uint32 count = 0;
    uint32 totalCount = 0;

    for (auto itr = auctionHouse->GetAuctionsBegin(); itr != auctionHouse->GetAuctionsEnd(); ++itr)
    {
        // this may be very long
        if (!AuctionHouseListing::IsListingAllowed())
            return false;

        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->owner == player->GetGUID().GetCounter())
        {
            if (Aentry->BuildAuctionInfo(listingData))
                ++count;

            ++totalCount;
        }
    }

    listingData.put<uint32>(0, count);
    listingData << (uint32)totalCount;
    listingData << (uint32)0;
    player->GetSession()->SendPacket(&listingData);
    return true;
}

bool AuctionListItemsEvent::Execute()
{
    Player* player = ObjectAccessor::FindPlayer(_playerGuid);
    if (!AuctionListingEvent::ExecuteBase(player))
        return true;

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(_faction);
    WorldPacket listingData(SMSG_AUCTION_LIST_RESULT, (4 + 4 + 4) + 50 * AuctionItemPacketSize);
    listingData << (uint32)0;       // placeholder

    uint32 count = 0;
    uint32 totalCount = 0;

    // converting string that we try to find to lower case
    std::wstring wsearchedname;
    if (!Utf8toWStr(_searchedname, wsearchedname))
        return true;

    wstrToLower(wsearchedname);

    bool finished = BuildListAuctionItems(auctionHouse, listingData, player,
        wsearchedname, _listfrom, _levelmin, _levelmax, _usable,
        _inventoryType, _itemClass, _itemSubClass, _quality,
        count, totalCount, (_getAll != 0 && sWorld->getIntConfig(CONFIG_AUCTION_GETALL_DELAY) != 0));

    if (!finished)
        return false;

    listingData.put<uint32>(0, count);
    listingData << (uint32)totalCount;
    listingData << (uint32)sWorld->getIntConfig(CONFIG_AUCTION_SEARCH_DELAY);
    player->GetSession()->SendPacket(&listingData);

    return true;
}

bool AuctionListBidsEvent::Execute()
{
    Player* player = ObjectAccessor::FindPlayer(_playerGuid);
    if (!AuctionListingEvent::ExecuteBase(player))
        return true;

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(_faction);
    WorldPacket listingData(SMSG_AUCTION_BIDDER_LIST_RESULT, (4 + 4 + 4) + 50 * AuctionItemPacketSize);
    listingData << (uint32)0;       // placeholder

    uint32 count = 0;
    uint32 totalCount = 0;

    uint32 listfrom;                                    //page of auctions
    uint32 outbiddedCount;

    _data >> listfrom;                                  // not used in fact (this list not have page control in client)
    _data >> outbiddedCount;

    if (_data.size() != (16 + outbiddedCount * 4))
    {
        TC_LOG_ERROR("network", "Client sent bad opcode!!! with count: %u and size : %lu (must be: %u)", outbiddedCount, (unsigned long)_data.size(), (16 + outbiddedCount * 4));
        outbiddedCount = 0;
    }

    while (outbiddedCount > 0)                             //add all data, which client requires
    {
        --outbiddedCount;
        uint32 outbiddedAuctionId;
        _data >> outbiddedAuctionId;
        AuctionEntry* auction = auctionHouse->GetAuction(outbiddedAuctionId);
        if (auction && auction->BuildAuctionInfo(listingData))
        {
            ++totalCount;
            ++count;
        }
    }

    for (auto itr = auctionHouse->GetAuctionsBegin(); itr != auctionHouse->GetAuctionsEnd(); ++itr)
    {
        if (itr->second && itr->second->bidder == player->GetGUID().GetCounter())
        {
            if (itr->second->BuildAuctionInfo(listingData))
                ++count;

            ++totalCount;
        }
    }

    listingData.put<uint32>(0, count);                           // add count to placeholder
    listingData << totalCount;
    listingData << (uint32)sWorld->getIntConfig(CONFIG_AUCTION_SEARCH_DELAY);
    player->GetSession()->SendPacket(&listingData);
    return true;
}

bool AuctionListItemsEvent::BuildListAuctionItems(AuctionHouseObject* auctionHouse, WorldPacket& data, Player* player,
    std::wstring const& wsearchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
    uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
    uint32& count, uint32& totalcount, bool getall)
{
    int loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
    int locdbc_idx = player->GetSession()->GetSessionDbcLocale();

    time_t curTime = GameTime::GetGameTime();

    auto itr = GetAllThrottleMap.find(player->GetGUID());
    time_t throttleTime = itr != GetAllThrottleMap.end() ? itr->second : curTime;

    if (getall && throttleTime <= curTime)
    {
        for (auto itr = auctionHouse->GetAuctionsBegin(); itr != auctionHouse->GetAuctionsEnd(); ++itr)
        {
            // this may be very long
            if (!AuctionHouseListing::IsListingAllowed())
                return false;

            AuctionEntry* Aentry = itr->second;
            // Skip expired auctions
            if (Aentry->expire_time < curTime)
                continue;

            Item* item = sAuctionMgr->GetAItem(Aentry->itemGUIDLow);
            if (!item)
                continue;

            ++count;
            ++totalcount;
            Aentry->BuildAuctionInfo(data, item);

            if (count >= MAX_GETALL_RETURN)
                break;
        }

        GetAllThrottleMap[player->GetGUID()] = curTime + sWorld->getIntConfig(CONFIG_AUCTION_GETALL_DELAY);
        return true;
    }

    // optimization, this is a simplified case
    if (itemClass == 0xffffffff && itemSubClass == 0xffffffff && inventoryType == 0xffffffff && quality == 0xffffffff && levelmin == 0x00 && levelmax == 0x00 && usable == 0x00 && wsearchedname.empty())
    {
        totalcount = auctionHouse->Getcount();
        if (listfrom < totalcount)
        {
            auto itr = auctionHouse->GetAuctionsBegin();
            std::advance(itr, listfrom);
            for (; itr != auctionHouse->GetAuctionsEnd(); ++itr)
            {
                itr->second->BuildAuctionInfo(data);
                if ((++count) >= 50)
                    break;
            }
        }
        return true;
    }

    for (auto itr = auctionHouse->GetAuctionsBegin(); itr != auctionHouse->GetAuctionsEnd(); ++itr)
    {
        // this may be very long
        if (!AuctionHouseListing::IsListingAllowed())
            return false;

        AuctionEntry* Aentry = itr->second;
        // Skip expired auctions
        if (Aentry->expire_time < curTime)
            continue;

        Item* item = sAuctionMgr->GetAItem(Aentry->itemGUIDLow);
        if (!item)
            continue;

        ItemTemplate const* proto = item->GetTemplate();

        if (itemClass != 0xffffffff && proto->Class != itemClass)
            continue;

        if (itemSubClass != 0xffffffff && proto->SubClass != itemSubClass)
            continue;

        if (inventoryType != 0xffffffff && proto->InventoryType != inventoryType)
        {
            // exception, robes are counted as chests
            if (inventoryType != INVTYPE_CHEST || proto->InventoryType != INVTYPE_ROBE)
                continue;
        }

        if (quality != 0xffffffff && proto->Quality != quality)
            continue;

        if (levelmin != 0x00 && (proto->RequiredLevel < levelmin || (levelmax != 0x00 && proto->RequiredLevel > levelmax)))
            continue;

        if (usable != 0x00)
        {
            if (CanUseItem(item, player) != EQUIP_ERR_OK)
                continue;
        }

        // Allow search by suffix (ie: of the Monkey) or partial name (ie: Monkey)
        // No need to do any of this if no search term was entered
        if (!wsearchedname.empty())
        {
            std::string name = proto->Name1;
            if (name.empty())
                continue;

            // local name
            if (loc_idx >= 0)
                if (ItemLocale const* il = sObjectMgr->GetItemLocale(proto->ItemId))
                    ObjectMgr::GetLocaleString(il->Name, loc_idx, name);

            // DO NOT use GetItemEnchantMod(proto->RandomProperty) as it may return a result
            //  that matches the search but it may not equal item->GetItemRandomPropertyId()
            //  used in BuildAuctionInfo() which then causes wrong items to be listed
            int32 propRefID = item->GetItemRandomPropertyId();

            if (propRefID)
            {
                // Append the suffix to the name (ie: of the Monkey) if one exists
                // These are found in ItemRandomSuffix.dbc and ItemRandomProperties.dbc
                //  even though the DBC names seem misleading

                char* const* suffix = nullptr;

                if (propRefID < 0)
                {
                    const ItemRandomSuffixEntry* itemRandSuffix = sItemRandomSuffixStore.LookupEntry(-propRefID);
                    if (itemRandSuffix)
                        suffix = itemRandSuffix->nameSuffix;
                }
                else
                {
                    const ItemRandomPropertiesEntry* itemRandProp = sItemRandomPropertiesStore.LookupEntry(propRefID);
                    if (itemRandProp)
                        suffix = itemRandProp->nameSuffix;
                }

                // dbc local name
                if (suffix)
                {
                    // Append the suffix (ie: of the Monkey) to the name using localization
                    // or default enUS if localization is invalid
                    name += ' ';
                    name += suffix[locdbc_idx >= 0 ? locdbc_idx : LOCALE_enUS];
                }
            }

            // Perform the search (with or without suffix)
            if (!Utf8FitTo(name, wsearchedname))
                continue;
        }

        // Add the item if no search term or if entered search term was found
        if (count < 50 && totalcount >= listfrom)
        {
            ++count;
            Aentry->BuildAuctionInfo(data, item);
        }
        ++totalcount;
    }

    return true;
}

InventoryResult AuctionListItemsEvent::CanUseItem(Item const* pItem, Player const* player) const
{
    if (pItem)
    {
        if (!_isAlive)
            return EQUIP_ERR_YOU_ARE_DEAD;

        //if (isStunned())
        //    return EQUIP_ERR_YOU_ARE_STUNNED;

        ItemTemplate const* pProto = pItem->GetTemplate();
        if (pProto)
        {
            if (pItem->IsBindedNotWith(player))
                return EQUIP_ERR_DONT_OWN_THAT_ITEM;

            InventoryResult res = CanUseItem(pProto, player);
            if (res != EQUIP_ERR_OK)
                return res;

            if (pItem->GetSkill() != 0)
            {
                bool allowEquip = false;
                uint32 itemSkill = pItem->GetSkill();
                // Armor that is binded to account can "morph" from plate to mail, etc. if skill is not learned yet.
                if (pProto->Quality == ITEM_QUALITY_HEIRLOOM && pProto->Class == ITEM_CLASS_ARMOR && !HasSkill(itemSkill))
                {
                    /// @todo when you right-click already equipped item it throws EQUIP_ERR_NO_REQUIRED_PROFICIENCY.

                    // In fact it's a visual bug, everything works properly... I need sniffs of operations with
                    // binded to account items from off server.

                    switch (player->getClass()) // cannot change
                    {
                    case CLASS_HUNTER:
                    case CLASS_SHAMAN:
                        allowEquip = (itemSkill == SKILL_MAIL);
                        break;
                    case CLASS_PALADIN:
                    case CLASS_WARRIOR:
                        allowEquip = (itemSkill == SKILL_PLATE_MAIL);
                        break;
                    }
                }
                if (!allowEquip && GetSkillValue(itemSkill) == 0)
                    return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
            }

            if (pProto->RequiredReputationFaction && uint32(GetReputationRank(pProto->RequiredReputationFaction, player)) < pProto->RequiredReputationRank)
                return EQUIP_ERR_CANT_EQUIP_REPUTATION;

            return EQUIP_ERR_OK;
        }
    }
    return EQUIP_ERR_ITEM_NOT_FOUND;
}

InventoryResult AuctionListItemsEvent::CanUseItem(ItemTemplate const* proto, Player const* player) const
{
    if (!proto)
        return EQUIP_ERR_ITEM_NOT_FOUND;

    if (((proto->Flags2 & ITEM_FLAG2_FACTION_HORDE) && player->GetTeam() != HORDE) || // cannot change
        (((proto->Flags2 & ITEM_FLAG2_FACTION_ALLIANCE) && player->GetTeam() != ALLIANCE)))   // cannot change
        return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;

    if ((proto->AllowableClass & player->getClassMask()) == 0 || (proto->AllowableRace & player->getRaceMask()) == 0) // cannot change
        return EQUIP_ERR_YOU_CAN_NEVER_USE_THAT_ITEM;

    if (proto->RequiredSkill != 0)
    {
        if (GetSkillValue(proto->RequiredSkill) == 0)
            return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;
        else if (GetSkillValue(proto->RequiredSkill) < proto->RequiredSkillRank)
            return EQUIP_ERR_CANT_EQUIP_SKILL;
    }

    if (proto->RequiredSpell != 0 && !HasSpell(proto->RequiredSpell))
        return EQUIP_ERR_NO_REQUIRED_PROFICIENCY;

    if (_level < proto->RequiredLevel)
        return EQUIP_ERR_CANT_EQUIP_LEVEL_I;

    // If World Event is not active, prevent using event dependant items
    if (proto->HolidayId && !IsHolidayActive((HolidayIds)proto->HolidayId))
        return EQUIP_ERR_CANT_DO_RIGHT_NOW;

    // learning (recipes, mounts, pets, etc.)
    if (proto->Spells[0].SpellId == 483 || proto->Spells[0].SpellId == 55884)
        if (HasSpell(proto->Spells[1].SpellId))
            return EQUIP_ERR_NONE;

    return EQUIP_ERR_OK;
}

bool AuctionListItemsEvent::HasSkill(uint32 skill) const
{
    if (!skill)
        return false;

    SkillStatusMap::const_iterator itr = _mSkillStatus.find(skill);
    return (itr != _mSkillStatus.end() && itr->second.uState != SKILL_DELETED);
}

uint16 AuctionListItemsEvent::GetSkillValue(uint32 skill) const
{
    if (!skill)
        return 0;

    SkillStatusMap::const_iterator itr = _mSkillStatus.find(skill);
    if (itr == _mSkillStatus.end() || itr->second.uState == SKILL_DELETED)
        return 0;

    uint32 bonus = _skillFields[PLAYER_SKILL_BONUS_INDEX(itr->second.pos) - PLAYER_SKILL_INFO_1_1];

    int32 result = int32(SKILL_VALUE(_skillFields[PLAYER_SKILL_VALUE_INDEX(itr->second.pos) - PLAYER_SKILL_INFO_1_1]));
    result += SKILL_TEMP_BONUS(bonus);
    result += SKILL_PERM_BONUS(bonus);
    return result < 0 ? 0 : result;
}

bool AuctionListItemsEvent::HasSpell(uint32 spell) const
{
    PlayerSpellMap::const_iterator itr = _spells.find(spell);
    return (itr != _spells.end() && itr->second.state != PLAYERSPELL_REMOVED && !itr->second.disabled);
}

ReputationRank AuctionListItemsEvent::GetReputationRank(uint32 faction, Player const* player) const
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
    int32 reputation = 0;
    if (factionEntry && factionEntry->CanHaveReputation())
    {
        FactionStateList::const_iterator repItr = _factions.find(factionEntry->reputationListID);
        if (repItr != _factions.end())
            reputation = ReputationMgr::GetBaseReputation(factionEntry, player->getRaceMask(), player->getClassMask()) + repItr->second.Standing;
    }
    return ReputationMgr::ReputationToRank(reputation);
}
