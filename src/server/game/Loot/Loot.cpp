/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Loot.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Group.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "LootMgr.h"
#include "LootPackets.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "World.h"

//
// --------- LootItem ---------
//

// Constructor, copies most fields from LootStoreItem and generates random count
LootItem::LootItem(LootStoreItem const& li)
{
    itemid      = li.itemid;
    conditions   = li.conditions;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemid);
    freeforall = proto && (proto->GetFlags() & ITEM_FLAG_MULTI_DROP);
    follow_loot_rules = proto && (proto->FlagsCu & ITEM_FLAGS_CU_FOLLOW_LOOT_RULES);

    needs_quest = li.needs_quest;

    randomBonusListId = GenerateItemRandomBonusListId(itemid);
    context = ItemContext::NONE;
    count = 0;
    is_looted = 0;
    is_blocked = 0;
    is_underthreshold = 0;
    is_counted = 0;
    rollWinnerGUID = ObjectGuid::Empty;
}

// Basic checks for player/item compatibility - if false no chance to see the item in the loot
bool LootItem::AllowedForPlayer(Player const* player) const
{
    // DB conditions check
    if (!sConditionMgr->IsObjectMeetToConditions(const_cast<Player*>(player), conditions))
        return false;

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);
    if (!pProto)
        return false;

    // not show loot for players without profession or those who already know the recipe
    if ((pProto->GetFlags() & ITEM_FLAG_HIDE_UNUSABLE_RECIPE) && (!player->HasSkill(pProto->GetRequiredSkill()) || player->HasSpell(pProto->Effects[1]->SpellID)))
        return false;

    // not show loot for not own team
    if ((pProto->GetFlags2() & ITEM_FLAG2_FACTION_HORDE) && player->GetTeam() != HORDE)
        return false;

    if ((pProto->GetFlags2() & ITEM_FLAG2_FACTION_ALLIANCE) && player->GetTeam() != ALLIANCE)
        return false;

    // check quest requirements
    if (!(pProto->FlagsCu & ITEM_FLAGS_CU_IGNORE_QUEST_STATUS) && ((needs_quest || (pProto->GetStartQuest() && player->GetQuestStatus(pProto->GetStartQuest()) != QUEST_STATUS_NONE)) && !player->HasQuestForItem(itemid)))
        return false;

    return true;
}

void LootItem::AddAllowedLooter(const Player* player)
{
    allowedGUIDs.insert(player->GetGUID());
}

//
// --------- Loot ---------
//

Loot::Loot(uint32 _gold /*= 0*/) : gold(_gold), unlootedCount(0), roundRobinPlayer(), loot_type(LOOT_NONE), maxDuplicates(1), _itemContext(ItemContext::NONE)
{
}

Loot::~Loot()
{
    clear();
}

void Loot::clear()
{
    for (NotNormalLootItemMap::const_iterator itr = PlayerQuestItems.begin(); itr != PlayerQuestItems.end(); ++itr)
        delete itr->second;
    PlayerQuestItems.clear();

    for (NotNormalLootItemMap::const_iterator itr = PlayerFFAItems.begin(); itr != PlayerFFAItems.end(); ++itr)
        delete itr->second;
    PlayerFFAItems.clear();

    for (NotNormalLootItemMap::const_iterator itr = PlayerNonQuestNonFFAConditionalItems.begin(); itr != PlayerNonQuestNonFFAConditionalItems.end(); ++itr)
        delete itr->second;
    PlayerNonQuestNonFFAConditionalItems.clear();

    PlayersLooting.clear();
    items.clear();
    quest_items.clear();
    gold = 0;
    unlootedCount = 0;
    roundRobinPlayer.Clear();
    loot_type = LOOT_NONE;
    i_LootValidatorRefManager.clearReferences();
    _itemContext = ItemContext::NONE;
}

void Loot::NotifyItemRemoved(uint8 lootIndex)
{
    // notify all players that are looting this that the item was removed
    // convert the index to the slot the player sees
    GuidSet::iterator i_next;
    for (GuidSet::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
    {
        i_next = i;
        ++i_next;
        if (Player* player = ObjectAccessor::FindPlayer(*i))
            player->SendNotifyLootItemRemoved(GetGUID(), lootIndex);
        else
            PlayersLooting.erase(i);
    }
}

void Loot::NotifyQuestItemRemoved(uint8 questIndex)
{
    // when a free for all questitem is looted
    // all players will get notified of it being removed
    // (other questitems can be looted by each group member)
    // bit inefficient but isn't called often

    GuidSet::iterator i_next;
    for (GuidSet::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
    {
        i_next = i;
        ++i_next;
        if (Player* player = ObjectAccessor::FindPlayer(*i))
        {
            NotNormalLootItemMap::const_iterator pq = PlayerQuestItems.find(player->GetGUID());
            if (pq != PlayerQuestItems.end() && pq->second)
            {
                // find where/if the player has the given item in it's vector
                NotNormalLootItemList& pql = *pq->second;

                uint8 j;
                for (j = 0; j < pql.size(); ++j)
                    if (pql[j].index == questIndex)
                        break;

                if (j < pql.size())
                    player->SendNotifyLootItemRemoved(GetGUID(), items.size() + j);
            }
        }
        else
            PlayersLooting.erase(i);
    }
}

void Loot::NotifyMoneyRemoved()
{
    // notify all players that are looting this that the money was removed
    GuidSet::iterator i_next;
    for (GuidSet::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
    {
        i_next = i;
        ++i_next;
        if (Player* player = ObjectAccessor::FindPlayer(*i))
            player->SendNotifyLootMoneyRemoved(GetGUID());
        else
            PlayersLooting.erase(i);
    }
}

void Loot::generateMoneyLoot(uint32 minAmount, uint32 maxAmount)
{
    if (maxAmount > 0)
    {
        if (maxAmount <= minAmount)
            gold = uint32(maxAmount * sWorld->getRate(RATE_DROP_MONEY));
        else if ((maxAmount - minAmount) < 32700)
            gold = uint32(urand(minAmount, maxAmount) * sWorld->getRate(RATE_DROP_MONEY));
        else
            gold = uint32(urand(minAmount >> 8, maxAmount >> 8) * sWorld->getRate(RATE_DROP_MONEY)) << 8;
    }
}

// Calls processor of corresponding LootTemplate (which handles everything including references)
bool Loot::FillLoot(uint32 lootId, LootStore const& store, Player* lootOwner, bool personal, bool noEmptyError, uint16 lootMode /*= LOOT_MODE_DEFAULT*/, ItemContext context /*= ItemContext::NONE*/)
{
    // Must be provided
    if (!lootOwner)
        return false;

    LootTemplate const* tab = store.GetLootFor(lootId);

    if (!tab)
    {
        if (!noEmptyError)
            TC_LOG_ERROR("sql.sql", "Table '%s' loot id #%u used but it doesn't have records.", store.GetName(), lootId);
        return false;
    }

    _itemContext = context;

    items.reserve(MAX_NR_LOOT_ITEMS);
    quest_items.reserve(MAX_NR_QUEST_ITEMS);

    tab->Process(*this, store.IsRatesAllowed(), lootMode);          // Processing is done there, callback via Loot::AddItem()

    // Setting access rights for group loot case
    Group* group = lootOwner->GetGroup();
    if (!personal && group)
    {
        roundRobinPlayer = lootOwner->GetGUID();

        for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            if (Player* player = itr->GetSource())   // should actually be looted object instead of lootOwner but looter has to be really close so doesnt really matter
                if (player->IsInMap(lootOwner))
                    FillNotNormalLootFor(player, player->IsAtGroupRewardDistance(lootOwner));

        for (uint8 i = 0; i < items.size(); ++i)
        {
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(items[i].itemid))
                if (proto->GetQuality() < uint32(group->GetLootThreshold()))
                    items[i].is_underthreshold = true;
        }
    }
    // ... for personal loot
    else
        FillNotNormalLootFor(lootOwner, true);

    return true;
}

// Inserts the item into the loot (called by LootTemplate processors)
void Loot::AddItem(LootStoreItem const& item)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item.itemid);
    if (!proto)
        return;

    uint32 count = urand(item.mincount, item.maxcount);
    uint32 stacks = count / proto->GetMaxStackSize() + ((count % proto->GetMaxStackSize()) ? 1 : 0);

    std::vector<LootItem>& lootItems = item.needs_quest ? quest_items : items;
    uint32 limit = item.needs_quest ? MAX_NR_QUEST_ITEMS : MAX_NR_LOOT_ITEMS;

    for (uint32 i = 0; i < stacks && lootItems.size() < limit; ++i)
    {
        LootItem generatedLoot(item);
        generatedLoot.context = _itemContext;
        generatedLoot.count = std::min(count, proto->GetMaxStackSize());
        if (_itemContext != ItemContext::NONE)
        {
            std::set<uint32> bonusListIDs = sDB2Manager.GetDefaultItemBonusTree(generatedLoot.itemid, _itemContext);
            generatedLoot.BonusListIDs.insert(generatedLoot.BonusListIDs.end(), bonusListIDs.begin(), bonusListIDs.end());
        }

        lootItems.push_back(generatedLoot);
        count -= proto->GetMaxStackSize();

        // non-conditional one-player only items are counted here,
        // free for all items are counted in FillFFALoot(),
        // non-ffa conditionals are counted in FillNonQuestNonFFAConditionalLoot()
        if (!item.needs_quest && item.conditions.empty() && !(proto->GetFlags() & ITEM_FLAG_MULTI_DROP))
            ++unlootedCount;
    }
}

LootItem const* Loot::GetItemInSlot(uint32 lootSlot) const
{
    if (lootSlot < items.size())
        return &items[lootSlot];

    lootSlot -= uint32(items.size());
    if (lootSlot < quest_items.size())
        return &quest_items[lootSlot];

    return nullptr;
}

LootItem* Loot::LootItemInSlot(uint32 lootSlot, Player* player, NotNormalLootItem* *qitem, NotNormalLootItem* *ffaitem, NotNormalLootItem* *conditem)
{
    LootItem* item = NULL;
    bool is_looted = true;
    if (lootSlot >= items.size())
    {
        uint32 questSlot = lootSlot - items.size();
        NotNormalLootItemMap::const_iterator itr = PlayerQuestItems.find(player->GetGUID());
        if (itr != PlayerQuestItems.end() && questSlot < itr->second->size())
        {
            NotNormalLootItem* qitem2 = &(*itr->second)[questSlot];
            if (qitem)
                *qitem = qitem2;
            item = &quest_items[qitem2->index];
            is_looted = qitem2->is_looted;
        }
    }
    else
    {
        item = &items[lootSlot];
        is_looted = item->is_looted;
        if (item->freeforall)
        {
            NotNormalLootItemMap::const_iterator itr = PlayerFFAItems.find(player->GetGUID());
            if (itr != PlayerFFAItems.end())
            {
                for (NotNormalLootItemList::const_iterator iter = itr->second->begin(); iter != itr->second->end(); ++iter)
                    if (iter->index == lootSlot)
                    {
                        NotNormalLootItem* ffaitem2 = (NotNormalLootItem*)&(*iter);
                        if (ffaitem)
                            *ffaitem = ffaitem2;
                        is_looted = ffaitem2->is_looted;
                        break;
                    }
            }
        }
        else if (!item->conditions.empty())
        {
            NotNormalLootItemMap::const_iterator itr = PlayerNonQuestNonFFAConditionalItems.find(player->GetGUID());
            if (itr != PlayerNonQuestNonFFAConditionalItems.end())
            {
                for (NotNormalLootItemList::const_iterator iter = itr->second->begin(); iter != itr->second->end(); ++iter)
                {
                    if (iter->index == lootSlot)
                    {
                        NotNormalLootItem* conditem2 = (NotNormalLootItem*)&(*iter);
                        if (conditem)
                            *conditem = conditem2;
                        is_looted = conditem2->is_looted;
                        break;
                    }
                }
            }
        }
    }

    if (is_looted)
        return NULL;

    return item;
}

uint32 Loot::GetMaxSlotInLootFor(Player* player) const
{
    NotNormalLootItemMap::const_iterator itr = PlayerQuestItems.find(player->GetGUID());
    return items.size() + (itr != PlayerQuestItems.end() ? itr->second->size() : 0);
}

// return true if there is any item that is lootable for any player (not quest item, FFA or conditional)
bool Loot::hasItemForAll() const
{
    // Gold is always lootable
    if (gold)
        return true;

    for (LootItem const& item : items)
        if (!item.is_looted && !item.freeforall && item.conditions.empty())
            return true;
    return false;
}

// return true if there is any FFA, quest or conditional item for the player.
bool Loot::hasItemFor(Player const* player) const
{
    NotNormalLootItemMap const& lootPlayerQuestItems = GetPlayerQuestItems();
    NotNormalLootItemMap::const_iterator q_itr = lootPlayerQuestItems.find(player->GetGUID());
    if (q_itr != lootPlayerQuestItems.end())
    {
        NotNormalLootItemList* q_list = q_itr->second;
        for (NotNormalLootItemList::const_iterator qi = q_list->begin(); qi != q_list->end(); ++qi)
        {
            const LootItem &item = quest_items[qi->index];
            if (!qi->is_looted && !item.is_looted)
                return true;
        }
    }

    NotNormalLootItemMap const& lootPlayerFFAItems = GetPlayerFFAItems();
    NotNormalLootItemMap::const_iterator ffa_itr = lootPlayerFFAItems.find(player->GetGUID());
    if (ffa_itr != lootPlayerFFAItems.end())
    {
        NotNormalLootItemList* ffa_list = ffa_itr->second;
        for (NotNormalLootItemList::const_iterator fi = ffa_list->begin(); fi != ffa_list->end(); ++fi)
        {
            const LootItem &item = items[fi->index];
            if (!fi->is_looted && !item.is_looted)
                return true;
        }
    }

    NotNormalLootItemMap const& lootPlayerNonQuestNonFFAConditionalItems = GetPlayerNonQuestNonFFAConditionalItems();
    NotNormalLootItemMap::const_iterator nn_itr = lootPlayerNonQuestNonFFAConditionalItems.find(player->GetGUID());
    if (nn_itr != lootPlayerNonQuestNonFFAConditionalItems.end())
    {
        NotNormalLootItemList* conditional_list = nn_itr->second;
        for (NotNormalLootItemList::const_iterator ci = conditional_list->begin(); ci != conditional_list->end(); ++ci)
        {
            const LootItem &item = items[ci->index];
            if (!ci->is_looted && !item.is_looted)
                return true;
        }
    }

    return false;
}

// return true if there is any item over the group threshold (i.e. not underthreshold).
bool Loot::hasOverThresholdItem() const
{
    for (uint8 i = 0; i < items.size(); ++i)
    {
        if (!items[i].is_looted && !items[i].is_underthreshold && !items[i].freeforall)
            return true;
    }

    return false;
}

void Loot::BuildLootResponse(WorldPackets::Loot::LootResponse& packet, Player* viewer, PermissionTypes permission) const
{
    if (permission == NONE_PERMISSION)
        return;

    packet.Coins = gold;

    switch (permission)
    {
        case GROUP_PERMISSION:
        case MASTER_PERMISSION:
        case RESTRICTED_PERMISSION:
        {
            // if you are not the round-robin group looter, you can only see
            // blocked rolled items and quest items, and !ffa items
            for (uint8 i = 0; i < items.size(); ++i)
            {
                if (!items[i].is_looted && !items[i].freeforall && items[i].conditions.empty() && items[i].AllowedForPlayer(viewer))
                {
                    uint8 slot_type;

                    if (items[i].is_blocked) // for ML & restricted is_blocked = !is_underthreshold
                    {
                        switch (permission)
                        {
                            case GROUP_PERMISSION:
                                slot_type = LOOT_SLOT_TYPE_ROLL_ONGOING;
                                break;
                            case MASTER_PERMISSION:
                            {
                                if (viewer->GetGroup() && viewer->GetGroup()->GetMasterLooterGuid() == viewer->GetGUID())
                                    slot_type = LOOT_SLOT_TYPE_MASTER;
                                else
                                    slot_type = LOOT_SLOT_TYPE_LOCKED;
                                break;
                            }
                            case RESTRICTED_PERMISSION:
                                slot_type = LOOT_SLOT_TYPE_LOCKED;
                                break;
                            default:
                                continue;
                        }
                    }
                    else if (roundRobinPlayer.IsEmpty() || viewer->GetGUID() == roundRobinPlayer || !items[i].is_underthreshold)
                    {
                        // no round robin owner or he has released the loot
                        // or it IS the round robin group owner
                        // => item is lootable
                        slot_type = LOOT_SLOT_TYPE_ALLOW_LOOT;
                    }
                    else if (!items[i].rollWinnerGUID.IsEmpty())
                    {
                        if (items[i].rollWinnerGUID == viewer->GetGUID())
                            slot_type = LOOT_SLOT_TYPE_OWNER;
                        else
                            continue;
                    }
                    else
                        // item shall not be displayed.
                        continue;

                    WorldPackets::Loot::LootItemData lootItem;
                    lootItem.LootListID = i + 1;
                    lootItem.UIType = slot_type;
                    lootItem.Quantity = items[i].count;
                    lootItem.Loot.Initialize(items[i]);
                    packet.Items.push_back(lootItem);
                }
            }
            break;
        }
        case ALL_PERMISSION:
        case OWNER_PERMISSION:
        {
            for (uint8 i = 0; i < items.size(); ++i)
            {
                if (!items[i].is_looted && !items[i].freeforall && items[i].conditions.empty() && items[i].AllowedForPlayer(viewer))
                {
                    WorldPackets::Loot::LootItemData lootItem;
                    lootItem.LootListID = i + 1;
                    lootItem.UIType = permission == OWNER_PERMISSION ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;
                    lootItem.Quantity = items[i].count;
                    lootItem.Loot.Initialize(items[i]);
                    packet.Items.push_back(lootItem);
                }
            }
            break;
        }
        default:
            return;
    }

    LootSlotType slotType = permission == OWNER_PERMISSION ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;
    NotNormalLootItemMap const& lootPlayerQuestItems = GetPlayerQuestItems();
    NotNormalLootItemMap::const_iterator q_itr = lootPlayerQuestItems.find(viewer->GetGUID());
    if (q_itr != lootPlayerQuestItems.end())
    {
        NotNormalLootItemList const& q_list = *q_itr->second;
        for (std::size_t i = 0; i < q_list.size(); ++i)
        {
            NotNormalLootItem const& qi = q_list[i];
            LootItem const& item = quest_items[qi.index];
            if (!qi.is_looted && !item.is_looted)
            {
                WorldPackets::Loot::LootItemData lootItem;
                lootItem.LootListID = items.size() + i + 1;
                lootItem.Quantity = item.count;
                lootItem.Loot.Initialize(item);

                if (item.follow_loot_rules)
                {
                    switch (permission)
                    {
                        case MASTER_PERMISSION:
                            lootItem.UIType = LOOT_SLOT_TYPE_MASTER;
                            break;
                        case RESTRICTED_PERMISSION:
                            lootItem.UIType = item.is_blocked ? LOOT_SLOT_TYPE_LOCKED : LOOT_SLOT_TYPE_ALLOW_LOOT;
                            break;
                        case GROUP_PERMISSION:
                            if (!item.is_blocked)
                                lootItem.UIType = LOOT_SLOT_TYPE_ALLOW_LOOT;
                            else
                                lootItem.UIType = LOOT_SLOT_TYPE_ROLL_ONGOING;
                            break;
                        default:
                            lootItem.UIType = slotType;
                            break;
                    }
                }
                else
                    lootItem.UIType = slotType;

                packet.Items.push_back(lootItem);
            }
        }
    }

    NotNormalLootItemMap const& lootPlayerFFAItems = GetPlayerFFAItems();
    NotNormalLootItemMap::const_iterator ffa_itr = lootPlayerFFAItems.find(viewer->GetGUID());
    if (ffa_itr != lootPlayerFFAItems.end())
    {
        NotNormalLootItemList* ffa_list = ffa_itr->second;
        for (NotNormalLootItemList::const_iterator fi = ffa_list->begin(); fi != ffa_list->end(); ++fi)
        {
            LootItem const& item = items[fi->index];
            if (!fi->is_looted && !item.is_looted)
            {
                WorldPackets::Loot::LootItemData lootItem;
                lootItem.LootListID = fi->index + 1;
                lootItem.UIType = slotType;
                lootItem.Quantity = item.count;
                lootItem.Loot.Initialize(item);
                packet.Items.push_back(lootItem);
            }
        }
    }

    NotNormalLootItemMap const& lootPlayerNonQuestNonFFAConditionalItems = GetPlayerNonQuestNonFFAConditionalItems();
    NotNormalLootItemMap::const_iterator nn_itr = lootPlayerNonQuestNonFFAConditionalItems.find(viewer->GetGUID());
    if (nn_itr != lootPlayerNonQuestNonFFAConditionalItems.end())
    {
        NotNormalLootItemList* conditional_list = nn_itr->second;
        for (NotNormalLootItemList::const_iterator ci = conditional_list->begin(); ci != conditional_list->end(); ++ci)
        {
            LootItem const& item = items[ci->index];
            if (!ci->is_looted && !item.is_looted)
            {
                WorldPackets::Loot::LootItemData lootItem;
                lootItem.LootListID = ci->index + 1;
                lootItem.Quantity = item.count;
                lootItem.Loot.Initialize(item);

                switch (permission)
                {
                    case MASTER_PERMISSION:
                        lootItem.UIType = LOOT_SLOT_TYPE_MASTER;
                        break;
                    case RESTRICTED_PERMISSION:
                        lootItem.UIType = item.is_blocked ? LOOT_SLOT_TYPE_LOCKED : LOOT_SLOT_TYPE_ALLOW_LOOT;
                        break;
                    case GROUP_PERMISSION:
                        if (!item.is_blocked)
                            lootItem.UIType = LOOT_SLOT_TYPE_ALLOW_LOOT;
                        else
                            lootItem.UIType = LOOT_SLOT_TYPE_ROLL_ONGOING;
                        break;
                    default:
                        lootItem.UIType = slotType;
                        break;
                }

                packet.Items.push_back(lootItem);
            }
        }
    }
}

void Loot::FillNotNormalLootFor(Player* player, bool presentAtLooting)
{
    ObjectGuid plguid = player->GetGUID();

    NotNormalLootItemMap::const_iterator qmapitr = PlayerQuestItems.find(plguid);
    if (qmapitr == PlayerQuestItems.end())
        FillQuestLoot(player);

    qmapitr = PlayerFFAItems.find(plguid);
    if (qmapitr == PlayerFFAItems.end())
        FillFFALoot(player);

    qmapitr = PlayerNonQuestNonFFAConditionalItems.find(plguid);
    if (qmapitr == PlayerNonQuestNonFFAConditionalItems.end())
        FillNonQuestNonFFAConditionalLoot(player, presentAtLooting);

    // if not auto-processed player will have to come and pick it up manually
    if (!presentAtLooting)
        return;

    // Process currency items
    uint32 max_slot = GetMaxSlotInLootFor(player);
    LootItem const* item = NULL;
    uint32 itemsSize = uint32(items.size());
    for (uint32 i = 0; i < max_slot; ++i)
    {
        if (i < items.size())
            item = &items[i];
        else
            item = &quest_items[i - itemsSize];

        if (!item->is_looted && item->freeforall && item->AllowedForPlayer(player))
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item->itemid))
                if (proto->IsCurrencyToken())
                    player->StoreLootItem(i, this);
    }
}

NotNormalLootItemList* Loot::FillFFALoot(Player* player)
{
    NotNormalLootItemList* ql = new NotNormalLootItemList();

    for (uint8 i = 0; i < items.size(); ++i)
    {
        LootItem &item = items[i];
        if (!item.is_looted && item.freeforall && item.AllowedForPlayer(player))
        {
            ql->push_back(NotNormalLootItem(i));
            ++unlootedCount;
        }
    }
    if (ql->empty())
    {
        delete ql;
        return NULL;
    }

    PlayerFFAItems[player->GetGUID()] = ql;
    return ql;
}

NotNormalLootItemList* Loot::FillQuestLoot(Player* player)
{
    if (items.size() == MAX_NR_LOOT_ITEMS)
        return NULL;

    NotNormalLootItemList* ql = new NotNormalLootItemList();

    for (uint8 i = 0; i < quest_items.size(); ++i)
    {
        LootItem &item = quest_items[i];

        if (!item.is_looted && (item.AllowedForPlayer(player) || (item.follow_loot_rules && player->GetGroup() && ((player->GetGroup()->GetLootMethod() == MASTER_LOOT && player->GetGroup()->GetMasterLooterGuid() == player->GetGUID()) || player->GetGroup()->GetLootMethod() != MASTER_LOOT))))
        {
            ql->push_back(NotNormalLootItem(i));

            // quest items get blocked when they first appear in a
            // player's quest vector
            //
            // increase once if one looter only, looter-times if free for all
            if (item.freeforall || !item.is_blocked)
                ++unlootedCount;
            if (!player->GetGroup() || (player->GetGroup()->GetLootMethod() != GROUP_LOOT))
                item.is_blocked = true;

            if (items.size() + ql->size() == MAX_NR_LOOT_ITEMS)
                break;
        }
    }
    if (ql->empty())
    {
        delete ql;
        return NULL;
    }

    PlayerQuestItems[player->GetGUID()] = ql;
    return ql;
}

NotNormalLootItemList* Loot::FillNonQuestNonFFAConditionalLoot(Player* player, bool presentAtLooting)
{
    NotNormalLootItemList* ql = new NotNormalLootItemList();

    for (uint8 i = 0; i < items.size(); ++i)
    {
        LootItem &item = items[i];
        if (!item.is_looted && !item.freeforall && (item.AllowedForPlayer(player)))
        {
            if (presentAtLooting)
                item.AddAllowedLooter(player);
            if (!item.conditions.empty())
            {
                ql->push_back(NotNormalLootItem(i));
                if (!item.is_counted)
                {
                    ++unlootedCount;
                    item.is_counted = true;
                }
            }
        }
    }
    if (ql->empty())
    {
        delete ql;
        return NULL;
    }

    PlayerNonQuestNonFFAConditionalItems[player->GetGUID()] = ql;
    return ql;
}

//
// --------- AELootResult ---------
//

void AELootResult::Add(Item* item, uint8 count, LootType lootType)
{
    auto itr = _byItem.find(item);
    if (itr != _byItem.end())
        _byOrder[itr->second].count += count;
    else
    {
        _byItem[item] = _byOrder.size();
        ResultValue value;
        value.item = item;
        value.count = count;
        value.lootType = lootType;
        _byOrder.push_back(value);
    }
}

AELootResult::OrderedStorage::const_iterator AELootResult::begin() const
{
    return _byOrder.begin();
}

AELootResult::OrderedStorage::const_iterator AELootResult::end() const
{
    return _byOrder.end();
}
