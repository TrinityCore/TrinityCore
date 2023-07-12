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
#include "DBCStores.h"
#include "Group.h"
#include "ItemEnchantmentMgr.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "LootMgr.h"
#include "LootPackets.h"
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
    is_currency = li.is_currency;

    if (!is_currency)
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemid);
        freeforall = proto && (proto->GetFlags() & ITEM_FLAG_MULTI_DROP);
        follow_loot_rules = proto && (proto->FlagsCu & ITEM_FLAGS_CU_FOLLOW_LOOT_RULES);
    }
    else
    {
        freeforall = false;
        follow_loot_rules = false;
    }

    needs_quest = li.needs_quest;

    randomSuffix =  !is_currency ? GenerateEnchSuffixFactor(itemid) : 0;
    randomPropertyId = !is_currency ? GenerateItemRandomPropertyId(itemid) : ItemRandomEnchantmentId();
    count = 0;
    is_looted = 0;
    is_blocked = 0;
    is_underthreshold = 0;
    is_counted = 0;
    rollWinnerGUID = ObjectGuid::Empty;
}

// Basic checks for player/item compatibility - if false no chance to see the item in the loot
bool LootItem::AllowedForPlayer(Player const* player, bool isGivenByMasterLooter) const
{
    // DB conditions check
    if (!sConditionMgr->IsObjectMeetToConditions(const_cast<Player*>(player), conditions))
        return false;

    if (is_currency)
        return true;

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);
    if (!pProto)
        return false;

    // not show loot for not own team
    if ((pProto->GetFlags2() & ITEM_FLAG2_FACTION_HORDE) && player->GetTeam() != HORDE)
        return false;

    if ((pProto->GetFlags2() & ITEM_FLAG2_FACTION_ALLIANCE) && player->GetTeam() != ALLIANCE)
        return false;

    // Master looter can see certain items even if the character can't loot them
    if (!isGivenByMasterLooter && player->GetGroup() && player->GetGroup()->GetMasterLooterGuid() == player->GetGUID())
    {
        // check quest requirements
        if (!(pProto->FlagsCu & ITEM_FLAGS_CU_IGNORE_QUEST_STATUS) && (needs_quest || pProto->GetStartQuest()))
            return false;

        return true;
    }

    // Don't allow loot for players without profession or those who already know the recipe
    if (pProto->GetFlags() & ITEM_FLAG_HIDE_UNUSABLE_RECIPE)
    {
        if (!player->HasSkill(pProto->GetRequiredSkill()))
            return false;

        for (ItemEffect const& itemEffect : pProto->Effects)
        {
            if (itemEffect.Trigger != ITEM_SPELLTRIGGER_LEARN_SPELL_ID)
                continue;

            if (player->HasSpell(itemEffect.SpellID))
                return false;
        }
    }

    // Don't allow to loot soulbound recipes that the player has already learned
    if (pProto->GetClass() == ITEM_CLASS_RECIPE && pProto->GetBonding() == BIND_ON_ACQUIRE)
    {
        for (ItemEffect const& itemEffect : pProto->Effects)
        {
            if (itemEffect.Trigger != ITEM_SPELLTRIGGER_LEARN_SPELL_ID)
                continue;

            if (player->HasSpell(itemEffect.SpellID))
                return false;
        }
    }

    // check quest requirements
    if (!(pProto->FlagsCu & ITEM_FLAGS_CU_IGNORE_QUEST_STATUS) && ((needs_quest || (pProto->GetStartQuest() && player->GetQuestStatus(pProto->GetStartQuest()) != QUEST_STATUS_NONE)) && !player->HasQuestForItem(itemid)))
        return false;

    return true;
}

void LootItem::AddAllowedLooter(Player const* player)
{
    allowedGUIDs.insert(player->GetGUID());
}

//
// --------- Loot ---------
//

Loot::Loot(uint32 _gold /*= 0*/) : gold(_gold), unlootedCount(0), roundRobinPlayer(), loot_type(LOOT_NONE), maxDuplicates(1)
{
}

Loot::~Loot()
{
    clear();
}

// Inserts the item into the loot (called by LootTemplate processors)
void Loot::AddItem(LootStoreItem const& item)
{
    std::vector<LootItem>& lootItems = item.needs_quest ? quest_items : items;
    uint32 limit = item.needs_quest ? MAX_NR_QUEST_ITEMS : MAX_NR_LOOT_ITEMS;

    Player* player = ObjectAccessor::FindPlayer(lootOwnerGUID);

    if (item.is_currency)
    {
        CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(item.itemid);
        if (!currency)
            return;

        uint32 totalCap = currency->MaxQty > 0 ? currency->MaxQty : 1;
        uint32 count = urand(item.mincount, item.maxcount);

        // SPELL_AURA_MOD_CURRENCY_CATEGORY_GAIN_PCT bonus
        if (player)
            count *= player->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_CURRENCY_CATEGORY_GAIN_PCT, currency->CategoryID);

        uint32 stacks = count / totalCap + ((count % totalCap) ? 1 : 0);

        for (uint32 i = 0; i < stacks && lootItems.size() < limit; ++i)
        {
            LootItem generatedLoot(item);
            generatedLoot.count = std::min(count, currency->MaxQty);
            generatedLoot.itemIndex = lootItems.size();
            lootItems.push_back(generatedLoot);
            count -= currency->MaxQty;

            // In some cases, a dropped item should be visible/lootable only for some players in group
            bool canSeeItemInLootWindow = false;
            if (player)
            {
                if (Group* group = player->GetGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                        if (Player* member = itr->GetSource())
                            if (generatedLoot.AllowedForPlayer(member))
                                canSeeItemInLootWindow = true;
                }
                else if (generatedLoot.AllowedForPlayer(player))
                    canSeeItemInLootWindow = true;
            }

            if (!canSeeItemInLootWindow)
                continue;

            // Never seen a currency that needs a quest but just in case
            if (!item.needs_quest)
                ++unlootedCount;
        }
        return;
    }

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item.itemid);
    if (!proto)
        return;

    uint32 count = urand(item.mincount, item.maxcount);
    uint32 stacks = count / proto->GetMaxStackSize() + ((count % proto->GetMaxStackSize()) ? 1 : 0);

    for (uint32 i = 0; i < stacks && lootItems.size() < limit; ++i)
    {
        LootItem generatedLoot(item);
        generatedLoot.count = std::min(count, proto->GetMaxStackSize());
        generatedLoot.itemIndex = lootItems.size();
        lootItems.push_back(generatedLoot);
        count -= proto->GetMaxStackSize();

        // In some cases, a dropped item should be visible/lootable only for some players in group
        bool canSeeItemInLootWindow = false;
        if (player)
        {
            if (Group* group = player->GetGroup())
            {
                for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (Player* member = itr->GetSource())
                        if (generatedLoot.AllowedForPlayer(member))
                            canSeeItemInLootWindow = true;
            }
            else if (generatedLoot.AllowedForPlayer(player))
                canSeeItemInLootWindow = true;
        }

        if (!canSeeItemInLootWindow)
            continue;

        // non-conditional one-player only items are counted here,
        // free for all items are counted in FillFFALoot(),
        // non-ffa conditionals are counted in FillNonQuestNonFFAConditionalLoot()
        if (!item.needs_quest && item.conditions.empty() && !(proto->GetFlags() & ITEM_FLAG_MULTI_DROP))
            ++unlootedCount;
    }
}

void Loot::LootCurrencyInSlot(uint8 lootSlot, Player* player)
{
    if (items[lootSlot].is_looted || !items[lootSlot].is_currency)
        return;

    CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(items[lootSlot].itemid);
    if (!currency)
        return;

    NotifyCurrencyRemoved(lootSlot);
    player->ModifyCurrency(items[lootSlot].itemid, items[lootSlot].count);

    items[lootSlot].is_looted = true;
    unlootedCount--;
}

// Calls processor of corresponding LootTemplate (which handles everything including references)
bool Loot::FillLoot(uint32 lootId, LootStore const& store, Player* lootOwner, bool personal, bool noEmptyError, uint16 lootMode /*= LOOT_MODE_DEFAULT*/)
{
    // Must be provided
    if (!lootOwner)
        return false;

    lootOwnerGUID = lootOwner->GetGUID();

    LootTemplate const* tab = store.GetLootFor(lootId);

    if (!tab)
    {
        if (!noEmptyError)
            TC_LOG_ERROR("sql.sql", "Table '%s' loot id #%u used but it doesn't have records.", store.GetName(), lootId);
        return false;
    }

    items.reserve(MAX_NR_LOOT_ITEMS);
    quest_items.reserve(MAX_NR_QUEST_ITEMS);

    tab->Process(*this, store.IsRatesAllowed(), lootMode);          // Processing is done there, callback via Loot::AddItem()

    // Setting access rights for group loot case
    Group* group = lootOwner->GetGroup();
    if (!personal && group)
    {
        roundRobinPlayer = lootOwner->GetGUID();

        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
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
        return nullptr;
    }

    PlayerFFAItems[player->GetGUID()] = ql;
    return ql;
}

NotNormalLootItemList* Loot::FillQuestLoot(Player* player)
{
    if (items.size() == MAX_NR_LOOT_ITEMS)
        return nullptr;

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
            if (!player->GetGroup() || (player->GetGroup()->GetLootMethod() != GROUP_LOOT && player->GetGroup()->GetLootMethod() != ROUND_ROBIN))
                item.is_blocked = true;

            if (items.size() + ql->size() == MAX_NR_LOOT_ITEMS)
                break;
        }
    }
    if (ql->empty())
    {
        delete ql;
        return nullptr;
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
        return nullptr;
    }

    PlayerNonQuestNonFFAConditionalItems[player->GetGUID()] = ql;
    return ql;
}

//===================================================

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
            player->SendNotifyLootItemRemoved(lootIndex);
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
            player->SendNotifyLootMoneyRemoved();
        else
            PlayersLooting.erase(i);
    }
}

void Loot::NotifyCurrencyRemoved(uint8 lootIndex)
{
    // notify all players that are looting this that the currency was removed
    GuidSet::iterator i_next;
    for (GuidSet::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
    {
        i_next = i;
        ++i_next;
        if (Player* player = ObjectAccessor::FindPlayer(*i))
            player->SendNotifyCurrencyLootRemoved(lootIndex);
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
                    player->SendNotifyLootItemRemoved(items.size()+j);
            }
        }
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

LootItem* Loot::LootItemInSlot(uint32 lootSlot, Player* player, NotNormalLootItem* *qitem, NotNormalLootItem* *ffaitem, NotNormalLootItem* *conditem)
{
    LootItem* item = nullptr;
    bool is_looted = true;
    if (lootSlot >= items.size())
    {
        uint32 questSlot = lootSlot - items.size();
        NotNormalLootItemMap::const_iterator itr = PlayerQuestItems.find(player->GetGUID());
        if (itr != PlayerQuestItems.end() && questSlot < itr->second->size())
        {
            NotNormalLootItem* qitem2 = &itr->second->at(questSlot);
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
                for (NotNormalLootItemList::const_iterator iter=itr->second->begin(); iter!= itr->second->end(); ++iter)
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
                for (NotNormalLootItemList::const_iterator iter=itr->second->begin(); iter!= itr->second->end(); ++iter)
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
        return nullptr;

    return item;
}

uint32 Loot::GetMaxSlotInLootFor(Player* player) const
{
    NotNormalLootItemMap::const_iterator itr = PlayerQuestItems.find(player->GetGUID());
    return items.size() + (itr != PlayerQuestItems.end() ?  itr->second->size() : 0);
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
bool Loot::hasItemFor(Player* player) const
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

                    if (!items[i].is_currency)
                    {
                        WorldPackets::Loot::LootItemData lootItem;
                        lootItem.LootListID = i;
                        lootItem.UIType = slot_type;
                        lootItem.Quantity = items[i].count;
                        lootItem.Loot.Initialize(items[i]);
                        packet.Items.push_back(lootItem);
                    }
                    else
                    {
                        WorldPackets::Loot::LootCurrency lootCurrency;
                        lootCurrency.LootListID = i;
                        lootCurrency.CurrencyID = items[i].itemid;
                        lootCurrency.Quantity = items[i].count;
                        packet.Currencies.push_back(lootCurrency);
                    }
                }
            }
            break;
        }
        case ROUND_ROBIN_PERMISSION:
        {
            for (uint8 i = 0; i < items.size(); ++i)
            {
                if (!items[i].is_looted && !items[i].freeforall && items[i].conditions.empty() && items[i].AllowedForPlayer(viewer))
                {
                    if (!roundRobinPlayer.IsEmpty() && viewer->GetGUID() != roundRobinPlayer)
                        // item shall not be displayed.
                        continue;

                    if (!items[i].is_currency)
                    {
                        WorldPackets::Loot::LootItemData lootItem;
                        lootItem.LootListID = i;
                        lootItem.UIType = LOOT_SLOT_TYPE_ALLOW_LOOT;
                        lootItem.Quantity = items[i].count;
                        lootItem.Loot.Initialize(items[i]);
                        packet.Items.push_back(lootItem);
                    }
                    else
                    {
                        WorldPackets::Loot::LootCurrency lootCurrency;
                        lootCurrency.LootListID = i;
                        lootCurrency.CurrencyID = items[i].itemid;
                        lootCurrency.Quantity = items[i].count;
                        packet.Currencies.push_back(lootCurrency);
                    }
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
                    if (!items[i].is_currency)
                    {
                        WorldPackets::Loot::LootItemData lootItem;
                        lootItem.LootListID = i;
                        lootItem.UIType = permission == OWNER_PERMISSION ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;
                        lootItem.Quantity = items[i].count;
                        lootItem.Loot.Initialize(items[i]);
                        packet.Items.push_back(lootItem);
                    }
                    else
                    {
                        WorldPackets::Loot::LootCurrency lootCurrency;
                        lootCurrency.LootListID = i;
                        lootCurrency.CurrencyID = items[i].itemid;
                        lootCurrency.Quantity = items[i].count;
                        packet.Currencies.push_back(lootCurrency);
                    }
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
                if (!item.is_currency)
                {
                    WorldPackets::Loot::LootItemData lootItem;
                    lootItem.LootListID = items.size() + i;
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
                            case ROUND_ROBIN_PERMISSION:
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
                else
                {
                    WorldPackets::Loot::LootCurrency lootCurrency;
                    lootCurrency.LootListID = items.size() + i;
                    lootCurrency.CurrencyID = item.itemid;
                    lootCurrency.Quantity = item.count;
                    packet.Currencies.push_back(lootCurrency);
                }
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
                if (!item.is_currency)
                {
                    WorldPackets::Loot::LootItemData lootItem;
                    lootItem.LootListID = fi->index;
                    lootItem.UIType = slotType;
                    lootItem.Quantity = item.count;
                    lootItem.Loot.Initialize(item);
                    packet.Items.push_back(lootItem);
                }
                else
                {
                    WorldPackets::Loot::LootCurrency lootCurrency;
                    lootCurrency.LootListID = fi->index;
                    lootCurrency.CurrencyID = item.itemid;
                    lootCurrency.Quantity = item.count;
                    packet.Currencies.push_back(lootCurrency);
                }
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
                if (!item.is_currency)
                {
                    WorldPackets::Loot::LootItemData lootItem;
                    lootItem.LootListID = ci->index;
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
                else
                {
                    WorldPackets::Loot::LootCurrency lootCurrency;
                    lootCurrency.LootListID = ci->index;
                    lootCurrency.CurrencyID = item.itemid;
                    lootCurrency.Quantity = item.count;
                    packet.Currencies.push_back(lootCurrency);
                }
            }
        }
    }
}
