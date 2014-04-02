/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "LootMgr.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Util.h"
#include "SharedDefines.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "Group.h"
#include "Player.h"
#include "Containers.h"

static Rates const qualityToRate[MAX_ITEM_QUALITY] =
{
    RATE_DROP_ITEM_POOR,                                    // ITEM_QUALITY_POOR
    RATE_DROP_ITEM_NORMAL,                                  // ITEM_QUALITY_NORMAL
    RATE_DROP_ITEM_UNCOMMON,                                // ITEM_QUALITY_UNCOMMON
    RATE_DROP_ITEM_RARE,                                    // ITEM_QUALITY_RARE
    RATE_DROP_ITEM_EPIC,                                    // ITEM_QUALITY_EPIC
    RATE_DROP_ITEM_LEGENDARY,                               // ITEM_QUALITY_LEGENDARY
    RATE_DROP_ITEM_ARTIFACT,                                // ITEM_QUALITY_ARTIFACT
};

LootStore LootTemplates_Creature("creature_loot_template",           "creature entry",                  true);
LootStore LootTemplates_Disenchant("disenchant_loot_template",       "item disenchant id",              true);
LootStore LootTemplates_Fishing("fishing_loot_template",             "area id",                         true);
LootStore LootTemplates_Gameobject("gameobject_loot_template",       "gameobject entry",                true);
LootStore LootTemplates_Item("item_loot_template",                   "item entry",                      true);
LootStore LootTemplates_Mail("mail_loot_template",                   "mail template id",                false);
LootStore LootTemplates_Milling("milling_loot_template",             "item entry (herb)",               true);
LootStore LootTemplates_Pickpocketing("pickpocketing_loot_template", "creature pickpocket lootid",      true);
LootStore LootTemplates_Prospecting("prospecting_loot_template",     "item entry (ore)",                true);
LootStore LootTemplates_Reference("reference_loot_template",         "reference id",                    false);
LootStore LootTemplates_Skinning("skinning_loot_template",           "creature skinning id",            true);
LootStore LootTemplates_Spell("spell_loot_template",                 "spell id (random item creating)", false);

// Selects invalid loot items to be removed from group possible entries (before rolling)
struct LootGroupInvalidSelector : public std::unary_function<LootStoreItem*, bool>
{
    explicit LootGroupInvalidSelector(Loot const& loot, uint16 lootMode) : _loot(loot), _lootMode(lootMode) { }

    bool operator()(LootStoreItem* item) const
    {
        if (!(item->lootmode & _lootMode))
            return true;

        uint8 foundDuplicates = 0;
        for (std::vector<LootItem>::const_iterator itr = _loot.items.begin(); itr != _loot.items.end(); ++itr)
            if (itr->itemid == item->itemid)
                if (++foundDuplicates == _loot.maxDuplicates)
                    return true;

        return false;
    }

private:
    Loot const& _loot;
    uint16 _lootMode;
};

class LootTemplate::LootGroup                               // A set of loot definitions for items (refs are not allowed)
{
    public:
        LootGroup() { }
        ~LootGroup();

        void AddEntry(LootStoreItem* item);                 // Adds an entry to the group (at loading stage)
        bool HasQuestDrop() const;                          // True if group includes at least 1 quest drop entry
        bool HasQuestDropForPlayer(Player const* player) const;
                                                            // The same for active quests of the player
        void Process(Loot& loot, uint16 lootMode) const;    // Rolls an item from the group (if any) and adds the item to the loot
        float RawTotalChance() const;                       // Overall chance for the group (without equal chanced items)
        float TotalChance() const;                          // Overall chance for the group

        void Verify(LootStore const& lootstore, uint32 id, uint8 group_id) const;
        void CollectLootIds(LootIdSet& set) const;
        void CheckLootRefs(LootTemplateMap const& store, LootIdSet* ref_set) const;
        LootStoreItemList* GetExplicitlyChancedItemList() { return &ExplicitlyChanced; }
        LootStoreItemList* GetEqualChancedItemList() { return &EqualChanced; }
        void CopyConditions(ConditionList conditions);
    private:
        LootStoreItemList ExplicitlyChanced;                // Entries with chances defined in DB
        LootStoreItemList EqualChanced;                     // Zero chances - every entry takes the same chance

        LootStoreItem const* Roll(Loot& loot, uint16 lootMode) const;   // Rolls an item from the group, returns NULL if all miss their chances

        // This class must never be copied - storing pointers
        LootGroup(LootGroup const&);
        LootGroup& operator=(LootGroup const&);
};

//Remove all data and free all memory
void LootStore::Clear()
{
    for (LootTemplateMap::const_iterator itr=m_LootTemplates.begin(); itr != m_LootTemplates.end(); ++itr)
        delete itr->second;
    m_LootTemplates.clear();
}

// Checks validity of the loot store
// Actual checks are done within LootTemplate::Verify() which is called for every template
void LootStore::Verify() const
{
    for (LootTemplateMap::const_iterator i = m_LootTemplates.begin(); i != m_LootTemplates.end(); ++i)
        i->second->Verify(*this, i->first);
}

// Loads a *_loot_template DB table into loot store
// All checks of the loaded template are called from here, no error reports at loot generation required
uint32 LootStore::LoadLootTable()
{
    LootTemplateMap::const_iterator tab;

    // Clearing store (for reloading case)
    Clear();

    //                                                  0     1            2               3         4         5             6
    QueryResult result = WorldDatabase.PQuery("SELECT entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount FROM %s", GetName());

    if (!result)
        return 0;

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 entry               = fields[0].GetUInt32();
        uint32 item                = fields[1].GetUInt32();
        float  chanceOrQuestChance = fields[2].GetFloat();
        uint16 lootmode            = fields[3].GetUInt16();
        uint8  group               = fields[4].GetUInt8();
        int32  mincountOrRef       = fields[5].GetInt32();
        int32  maxcount            = fields[6].GetUInt8();

        if (maxcount > std::numeric_limits<uint8>::max())
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: maxcount value (%u) to large. must be less %u - skipped", GetName(), entry, item, maxcount, std::numeric_limits<uint8>::max());
            continue;                                   // error already printed to log/console.
        }

        if (group >= 1 << 7)                                     // it stored in 7 bit field
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: group (%u) must be less %u - skipped", GetName(), entry, item, group, 1 << 7);
            return false;
        }

        LootStoreItem* storeitem = new LootStoreItem(item, chanceOrQuestChance, lootmode, group, mincountOrRef, maxcount);

        if (!storeitem->IsValid(*this, entry))            // Validity checks
        {
            delete storeitem;
            continue;
        }

        // Looking for the template of the entry
                                                        // often entries are put together
        if (m_LootTemplates.empty() || tab->first != entry)
        {
            // Searching the template (in case template Id changed)
            tab = m_LootTemplates.find(entry);
            if (tab == m_LootTemplates.end())
            {
                std::pair< LootTemplateMap::iterator, bool > pr = m_LootTemplates.insert(LootTemplateMap::value_type(entry, new LootTemplate()));
                tab = pr.first;
            }
        }
        // else is empty - template Id and iter are the same
        // finally iter refers to already existed or just created <entry, LootTemplate>

        // Adds current row to the template
        tab->second->AddEntry(storeitem);
        ++count;
    }
    while (result->NextRow());

    Verify();                                           // Checks validity of the loot store

    return count;
}

bool LootStore::HaveQuestLootFor(uint32 loot_id) const
{
    LootTemplateMap::const_iterator itr = m_LootTemplates.find(loot_id);
    if (itr == m_LootTemplates.end())
        return false;

    // scan loot for quest items
    return itr->second->HasQuestDrop(m_LootTemplates);
}

bool LootStore::HaveQuestLootForPlayer(uint32 loot_id, Player* player) const
{
    LootTemplateMap::const_iterator tab = m_LootTemplates.find(loot_id);
    if (tab != m_LootTemplates.end())
        if (tab->second->HasQuestDropForPlayer(m_LootTemplates, player))
            return true;

    return false;
}

void LootStore::ResetConditions()
{
    for (LootTemplateMap::iterator itr = m_LootTemplates.begin(); itr != m_LootTemplates.end(); ++itr)
    {
        ConditionList empty;
        itr->second->CopyConditions(empty);
    }
}

LootTemplate const* LootStore::GetLootFor(uint32 loot_id) const
{
    LootTemplateMap::const_iterator tab = m_LootTemplates.find(loot_id);

    if (tab == m_LootTemplates.end())
        return NULL;

    return tab->second;
}

LootTemplate* LootStore::GetLootForConditionFill(uint32 loot_id)
{
    LootTemplateMap::iterator tab = m_LootTemplates.find(loot_id);

    if (tab == m_LootTemplates.end())
        return NULL;

    return tab->second;
}

uint32 LootStore::LoadAndCollectLootIds(LootIdSet& lootIdSet)
{
    uint32 count = LoadLootTable();

    for (LootTemplateMap::const_iterator tab = m_LootTemplates.begin(); tab != m_LootTemplates.end(); ++tab)
        lootIdSet.insert(tab->first);

    return count;
}

void LootStore::CheckLootRefs(LootIdSet* ref_set) const
{
    for (LootTemplateMap::const_iterator ltItr = m_LootTemplates.begin(); ltItr != m_LootTemplates.end(); ++ltItr)
        ltItr->second->CheckLootRefs(m_LootTemplates, ref_set);
}

void LootStore::ReportUnusedIds(LootIdSet const& lootIdSet) const
{
    // all still listed ids isn't referenced
    for (LootIdSet::const_iterator itr = lootIdSet.begin(); itr != lootIdSet.end(); ++itr)
        TC_LOG_ERROR("sql.sql", "Table '%s' entry %d isn't %s and not referenced from loot, and then useless.", GetName(), *itr, GetEntryName());
}

void LootStore::ReportNotExistedId(uint32 id) const
{
    TC_LOG_ERROR("sql.sql", "Table '%s' entry %d (%s) does not exist but used as loot id in DB.", GetName(), id, GetEntryName());
}

//
// --------- LootStoreItem ---------
//

// Checks if the entry (quest, non-quest, reference) takes it's chance (at loot generation)
// RATE_DROP_ITEMS is no longer used for all types of entries
bool LootStoreItem::Roll(bool rate) const
{
    if (chance >= 100.0f)
        return true;

    if (mincountOrRef < 0)                                   // reference case
        return roll_chance_f(chance* (rate ? sWorld->getRate(RATE_DROP_ITEM_REFERENCED) : 1.0f));

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);

    float qualityModifier = pProto && rate ? sWorld->getRate(qualityToRate[pProto->Quality]) : 1.0f;

    return roll_chance_f(chance*qualityModifier);
}

// Checks correctness of values
bool LootStoreItem::IsValid(LootStore const& store, uint32 entry) const
{
    if (mincountOrRef == 0)
    {
        TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: wrong mincountOrRef (%d) - skipped", store.GetName(), entry, itemid, mincountOrRef);
        return false;
    }

    if (mincountOrRef > 0)                                  // item (quest or non-quest) entry, maybe grouped
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemid);
        if (!proto)
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: item entry not listed in `item_template` - skipped", store.GetName(), entry, itemid);
            return false;
        }

        if (chance == 0 && group == 0)                      // Zero chance is allowed for grouped entries only
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: equal-chanced grouped entry, but group not defined - skipped", store.GetName(), entry, itemid);
            return false;
        }

        if (chance != 0 && chance < 0.000001f)             // loot with low chance
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: low chance (%f) - skipped",
                store.GetName(), entry, itemid, chance);
            return false;
        }

        if (maxcount < mincountOrRef)                       // wrong max count
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: max count (%u) less that min count (%i) - skipped", store.GetName(), entry, itemid, int32(maxcount), mincountOrRef);
            return false;
        }
    }
    else                                                    // mincountOrRef < 0
    {
        if (needs_quest)
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: quest chance will be treated as non-quest chance", store.GetName(), entry, itemid);
        else if (chance == 0)                              // no chance for the reference
        {
            TC_LOG_ERROR("sql.sql", "Table '%s' entry %d item %d: zero chance is specified for a reference, skipped", store.GetName(), entry, itemid);
            return false;
        }
    }
    return true;                                            // Referenced template existence is checked at whole store level
}

//
// --------- LootItem ---------
//

// Constructor, copies most fields from LootStoreItem and generates random count
LootItem::LootItem(LootStoreItem const& li)
{
    itemid      = li.itemid;
    conditions   = li.conditions;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemid);
    freeforall  = proto && (proto->Flags & ITEM_PROTO_FLAG_PARTY_LOOT);
    follow_loot_rules = proto && (proto->FlagsCu & ITEM_FLAGS_CU_FOLLOW_LOOT_RULES);

    needs_quest = li.needs_quest;

    randomSuffix = GenerateEnchSuffixFactor(itemid);
    randomPropertyId = Item::GenerateItemRandomPropertyId(itemid);
    count = 0;
    is_looted = 0;
    is_blocked = 0;
    is_underthreshold = 0;
    is_counted = 0;
    canSave = true;
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
    if ((pProto->Flags & ITEM_PROTO_FLAG_SMART_LOOT) && (!player->HasSkill(pProto->RequiredSkill) || player->HasSpell(pProto->Spells[1].SpellId)))
        return false;

    // not show loot for not own team
    if ((pProto->Flags2 & ITEM_FLAGS_EXTRA_HORDE_ONLY) && player->GetTeam() != HORDE)
        return false;

    if ((pProto->Flags2 & ITEM_FLAGS_EXTRA_ALLIANCE_ONLY) && player->GetTeam() != ALLIANCE)
        return false;

    // check quest requirements
    if (!(pProto->FlagsCu & ITEM_FLAGS_CU_IGNORE_QUEST_STATUS) && ((needs_quest || (pProto->StartQuest && player->GetQuestStatus(pProto->StartQuest) != QUEST_STATUS_NONE)) && !player->HasQuestForItem(itemid)))
        return false;

    return true;
}

void LootItem::AddAllowedLooter(const Player* player)
{
    allowedGUIDs.insert(player->GetGUIDLow());
}

//
// --------- Loot ---------
//

// Inserts the item into the loot (called by LootTemplate processors)
void Loot::AddItem(LootStoreItem const& item)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item.itemid);
    if (!proto)
        return;

    uint32 count = urand(item.mincountOrRef, item.maxcount);
    uint32 stacks = count / proto->GetMaxStackSize() + ((count % proto->GetMaxStackSize()) ? 1 : 0);

    std::vector<LootItem>& lootItems = item.needs_quest ? quest_items : items;
    uint32 limit = item.needs_quest ? MAX_NR_QUEST_ITEMS : MAX_NR_LOOT_ITEMS;

    for (uint32 i = 0; i < stacks && lootItems.size() < limit; ++i)
    {
        LootItem generatedLoot(item);
        generatedLoot.count = std::min(count, proto->GetMaxStackSize());
        lootItems.push_back(generatedLoot);
        count -= proto->GetMaxStackSize();

        // non-conditional one-player only items are counted here,
        // free for all items are counted in FillFFALoot(),
        // non-ffa conditionals are counted in FillNonQuestNonFFAConditionalLoot()
        if (!item.needs_quest && item.conditions.empty() && !(proto->Flags & ITEM_PROTO_FLAG_PARTY_LOOT))
            ++unlootedCount;
    }
}

// Calls processor of corresponding LootTemplate (which handles everything including references)
bool Loot::FillLoot(uint32 lootId, LootStore const& store, Player* lootOwner, bool personal, bool noEmptyError, uint16 lootMode /*= LOOT_MODE_DEFAULT*/)
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
                FillNotNormalLootFor(player, player->IsAtGroupRewardDistance(lootOwner));

        for (uint8 i = 0; i < items.size(); ++i)
        {
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(items[i].itemid))
                if (proto->Quality < uint32(group->GetLootThreshold()))
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
    uint32 plguid = player->GetGUIDLow();

    QuestItemMap::const_iterator qmapitr = PlayerQuestItems.find(plguid);
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
            item = &quest_items[i-itemsSize];

        if (!item->is_looted && item->freeforall && item->AllowedForPlayer(player))
            if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item->itemid))
                if (proto->IsCurrencyToken())
                    player->StoreLootItem(i, this);
    }
}

QuestItemList* Loot::FillFFALoot(Player* player)
{
    QuestItemList* ql = new QuestItemList();

    for (uint8 i = 0; i < items.size(); ++i)
    {
        LootItem &item = items[i];
        if (!item.is_looted && item.freeforall && item.AllowedForPlayer(player))
        {
            ql->push_back(QuestItem(i));
            ++unlootedCount;
        }
    }
    if (ql->empty())
    {
        delete ql;
        return NULL;
    }

    PlayerFFAItems[player->GetGUIDLow()] = ql;
    return ql;
}

QuestItemList* Loot::FillQuestLoot(Player* player)
{
    if (items.size() == MAX_NR_LOOT_ITEMS)
        return NULL;

    QuestItemList* ql = new QuestItemList();

    for (uint8 i = 0; i < quest_items.size(); ++i)
    {
        LootItem &item = quest_items[i];

        if (!item.is_looted && (item.AllowedForPlayer(player) || (item.follow_loot_rules && player->GetGroup() && ((player->GetGroup()->GetLootMethod() == MASTER_LOOT && player->GetGroup()->GetMasterLooterGuid() == player->GetGUID()) || player->GetGroup()->GetLootMethod() != MASTER_LOOT))))
        {
            ql->push_back(QuestItem(i));

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
        return NULL;
    }

    PlayerQuestItems[player->GetGUIDLow()] = ql;
    return ql;
}

QuestItemList* Loot::FillNonQuestNonFFAConditionalLoot(Player* player, bool presentAtLooting)
{
    QuestItemList* ql = new QuestItemList();

    for (uint8 i = 0; i < items.size(); ++i)
    {
        LootItem &item = items[i];
        if (!item.is_looted && !item.freeforall && (item.AllowedForPlayer(player) || (item.follow_loot_rules && player->GetGroup() && ((player->GetGroup()->GetLootMethod() == MASTER_LOOT && player->GetGroup()->GetMasterLooterGuid() == player->GetGUID()) || player->GetGroup()->GetLootMethod() != MASTER_LOOT))))
        {
            if (presentAtLooting)
                item.AddAllowedLooter(player);
            if (!item.conditions.empty())
            {
                ql->push_back(QuestItem(i));
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

    PlayerNonQuestNonFFAConditionalItems[player->GetGUIDLow()] = ql;
    return ql;
}

//===================================================

void Loot::NotifyItemRemoved(uint8 lootIndex)
{
    // notify all players that are looting this that the item was removed
    // convert the index to the slot the player sees
    std::set<uint64>::iterator i_next;
    for (std::set<uint64>::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
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
    std::set<uint64>::iterator i_next;
    for (std::set<uint64>::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
    {
        i_next = i;
        ++i_next;
        if (Player* player = ObjectAccessor::FindPlayer(*i))
            player->SendNotifyLootMoneyRemoved();
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

    std::set<uint64>::iterator i_next;
    for (std::set<uint64>::iterator i = PlayersLooting.begin(); i != PlayersLooting.end(); i = i_next)
    {
        i_next = i;
        ++i_next;
        if (Player* player = ObjectAccessor::FindPlayer(*i))
        {
            QuestItemMap::const_iterator pq = PlayerQuestItems.find(player->GetGUIDLow());
            if (pq != PlayerQuestItems.end() && pq->second)
            {
                // find where/if the player has the given item in it's vector
                QuestItemList& pql = *pq->second;

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

void Loot::DeleteLootItemFromContainerItemDB(uint32 itemID)
{
    // Deletes a single item associated with an openable item from the DB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEM);
    stmt->setUInt32(0, containerID);
    stmt->setUInt32(1, itemID);
    CharacterDatabase.Execute(stmt);

    // Mark the item looted to prevent resaving
    for (LootItemList::iterator _itr = items.begin(); _itr != items.end(); ++_itr)
    {
        if (_itr->itemid != itemID)
            continue;

        _itr->canSave = true;
        break;
    }
}

void Loot::DeleteLootMoneyFromContainerItemDB()
{
    // Deletes money loot associated with an openable item from the DB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt32(0, containerID);
    CharacterDatabase.Execute(stmt);
}

LootItem* Loot::LootItemInSlot(uint32 lootSlot, Player* player, QuestItem* *qitem, QuestItem* *ffaitem, QuestItem* *conditem)
{
    LootItem* item = NULL;
    bool is_looted = true;
    if (lootSlot >= items.size())
    {
        uint32 questSlot = lootSlot - items.size();
        QuestItemMap::const_iterator itr = PlayerQuestItems.find(player->GetGUIDLow());
        if (itr != PlayerQuestItems.end() && questSlot < itr->second->size())
        {
            QuestItem* qitem2 = &itr->second->at(questSlot);
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
            QuestItemMap::const_iterator itr = PlayerFFAItems.find(player->GetGUIDLow());
            if (itr != PlayerFFAItems.end())
            {
                for (QuestItemList::const_iterator iter=itr->second->begin(); iter!= itr->second->end(); ++iter)
                    if (iter->index == lootSlot)
                    {
                        QuestItem* ffaitem2 = (QuestItem*)&(*iter);
                        if (ffaitem)
                            *ffaitem = ffaitem2;
                        is_looted = ffaitem2->is_looted;
                        break;
                    }
            }
        }
        else if (!item->conditions.empty())
        {
            QuestItemMap::const_iterator itr = PlayerNonQuestNonFFAConditionalItems.find(player->GetGUIDLow());
            if (itr != PlayerNonQuestNonFFAConditionalItems.end())
            {
                for (QuestItemList::const_iterator iter=itr->second->begin(); iter!= itr->second->end(); ++iter)
                {
                    if (iter->index == lootSlot)
                    {
                        QuestItem* conditem2 = (QuestItem*)&(*iter);
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
    QuestItemMap::const_iterator itr = PlayerQuestItems.find(player->GetGUIDLow());
    return items.size() + (itr != PlayerQuestItems.end() ?  itr->second->size() : 0);
}

// return true if there is any FFA, quest or conditional item for the player.
bool Loot::hasItemFor(Player* player) const
{
    QuestItemMap const& lootPlayerQuestItems = GetPlayerQuestItems();
    QuestItemMap::const_iterator q_itr = lootPlayerQuestItems.find(player->GetGUIDLow());
    if (q_itr != lootPlayerQuestItems.end())
    {
        QuestItemList* q_list = q_itr->second;
        for (QuestItemList::const_iterator qi = q_list->begin(); qi != q_list->end(); ++qi)
        {
            const LootItem &item = quest_items[qi->index];
            if (!qi->is_looted && !item.is_looted)
                return true;
        }
    }

    QuestItemMap const& lootPlayerFFAItems = GetPlayerFFAItems();
    QuestItemMap::const_iterator ffa_itr = lootPlayerFFAItems.find(player->GetGUIDLow());
    if (ffa_itr != lootPlayerFFAItems.end())
    {
        QuestItemList* ffa_list = ffa_itr->second;
        for (QuestItemList::const_iterator fi = ffa_list->begin(); fi != ffa_list->end(); ++fi)
        {
            const LootItem &item = items[fi->index];
            if (!fi->is_looted && !item.is_looted)
                return true;
        }
    }

    QuestItemMap const& lootPlayerNonQuestNonFFAConditionalItems = GetPlayerNonQuestNonFFAConditionalItems();
    QuestItemMap::const_iterator nn_itr = lootPlayerNonQuestNonFFAConditionalItems.find(player->GetGUIDLow());
    if (nn_itr != lootPlayerNonQuestNonFFAConditionalItems.end())
    {
        QuestItemList* conditional_list = nn_itr->second;
        for (QuestItemList::const_iterator ci = conditional_list->begin(); ci != conditional_list->end(); ++ci)
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

ByteBuffer& operator<<(ByteBuffer& b, LootItem const& li)
{
    b << uint32(li.itemid);
    b << uint32(li.count);                                  // nr of items of this type
    b << uint32(sObjectMgr->GetItemTemplate(li.itemid)->DisplayInfoID);
    b << uint32(li.randomSuffix);
    b << uint32(li.randomPropertyId);
    //b << uint8(0);                                        // slot type - will send after this function call
    return b;
}

ByteBuffer& operator<<(ByteBuffer& b, LootView const& lv)
{
    if (lv.permission == NONE_PERMISSION)
    {
        b << uint32(0);                                     // gold
        b << uint8(0);                                      // item count
        return b;
    }

    Loot &l = lv.loot;

    uint8 itemsShown = 0;

    b << uint32(l.gold);                                    //gold

    size_t count_pos = b.wpos();                            // pos of item count byte
    b << uint8(0);                                          // item count placeholder

    switch (lv.permission)
    {
        case GROUP_PERMISSION:
        case MASTER_PERMISSION:
        case RESTRICTED_PERMISSION:
        {
            // if you are not the round-robin group looter, you can only see
            // blocked rolled items and quest items, and !ffa items
            for (uint8 i = 0; i < l.items.size(); ++i)
            {
                if (!l.items[i].is_looted && !l.items[i].freeforall && l.items[i].conditions.empty() && l.items[i].AllowedForPlayer(lv.viewer))
                {
                    uint8 slot_type;

                    if (l.items[i].is_blocked) // for ML & restricted is_blocked = !is_underthreshold
                    {
                        switch (lv.permission)
                        {
                            case GROUP_PERMISSION:
                                slot_type = LOOT_SLOT_TYPE_ROLL_ONGOING;
                                break;
                            case MASTER_PERMISSION:
                                slot_type = LOOT_SLOT_TYPE_MASTER;
                                break;
                            case RESTRICTED_PERMISSION:
                                slot_type = LOOT_SLOT_TYPE_LOCKED;
                                break;
                            default:
                                continue;
                        }
                    }
                    else if (l.roundRobinPlayer == 0 || lv.viewer->GetGUID() == l.roundRobinPlayer || !l.items[i].is_underthreshold)
                    {
                        // no round robin owner or he has released the loot
                        // or it IS the round robin group owner
                        // => item is lootable
                        slot_type = LOOT_SLOT_TYPE_ALLOW_LOOT;
                    }
                    else
                        // item shall not be displayed.
                        continue;

                    b << uint8(i) << l.items[i];
                    b << uint8(slot_type);
                    ++itemsShown;
                }
            }
            break;
        }
        case ROUND_ROBIN_PERMISSION:
        {
            for (uint8 i = 0; i < l.items.size(); ++i)
            {
                if (!l.items[i].is_looted && !l.items[i].freeforall && l.items[i].conditions.empty() && l.items[i].AllowedForPlayer(lv.viewer))
                {
                    if (l.roundRobinPlayer != 0 && lv.viewer->GetGUID() != l.roundRobinPlayer)
                        // item shall not be displayed.
                        continue;

                    b << uint8(i) << l.items[i];
                    b << uint8(LOOT_SLOT_TYPE_ALLOW_LOOT);
                    ++itemsShown;
                }
            }
            break;
        }
        case ALL_PERMISSION:
        case OWNER_PERMISSION:
        {
            uint8 slot_type = lv.permission == OWNER_PERMISSION ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;
            for (uint8 i = 0; i < l.items.size(); ++i)
            {
                if (!l.items[i].is_looted && !l.items[i].freeforall && l.items[i].conditions.empty() && l.items[i].AllowedForPlayer(lv.viewer))
                {
                    b << uint8(i) << l.items[i];
                    b << uint8(slot_type);
                    ++itemsShown;
                }
            }
            break;
        }
        default:
            return b;
    }

    LootSlotType slotType = lv.permission == OWNER_PERMISSION ? LOOT_SLOT_TYPE_OWNER : LOOT_SLOT_TYPE_ALLOW_LOOT;
    QuestItemMap const& lootPlayerQuestItems = l.GetPlayerQuestItems();
    QuestItemMap::const_iterator q_itr = lootPlayerQuestItems.find(lv.viewer->GetGUIDLow());
    if (q_itr != lootPlayerQuestItems.end())
    {
        QuestItemList* q_list = q_itr->second;
        for (QuestItemList::const_iterator qi = q_list->begin(); qi != q_list->end(); ++qi)
        {
            LootItem &item = l.quest_items[qi->index];
            if (!qi->is_looted && !item.is_looted)
            {
                b << uint8(l.items.size() + (qi - q_list->begin()));
                b << item;
                if (item.follow_loot_rules)
                {
                    switch (lv.permission)
                    {
                        case MASTER_PERMISSION:
                            b << uint8(LOOT_SLOT_TYPE_MASTER);
                            break;
                        case RESTRICTED_PERMISSION:
                            b << (item.is_blocked ? uint8(LOOT_SLOT_TYPE_LOCKED) : uint8(slotType));
                            break;
                        case GROUP_PERMISSION:
                        case ROUND_ROBIN_PERMISSION:
                            if (!item.is_blocked)
                                b << uint8(LOOT_SLOT_TYPE_ALLOW_LOOT);
                            else
                                b << uint8(LOOT_SLOT_TYPE_ROLL_ONGOING);
                            break;
                        default:
                            b << uint8(slotType);
                            break;
                    }
                }
                else
                    b << uint8(slotType);
                ++itemsShown;
            }
        }
    }

    QuestItemMap const& lootPlayerFFAItems = l.GetPlayerFFAItems();
    QuestItemMap::const_iterator ffa_itr = lootPlayerFFAItems.find(lv.viewer->GetGUIDLow());
    if (ffa_itr != lootPlayerFFAItems.end())
    {
        QuestItemList* ffa_list = ffa_itr->second;
        for (QuestItemList::const_iterator fi = ffa_list->begin(); fi != ffa_list->end(); ++fi)
        {
            LootItem &item = l.items[fi->index];
            if (!fi->is_looted && !item.is_looted)
            {
                b << uint8(fi->index);
                b << item;
                b << uint8(slotType);
                ++itemsShown;
            }
        }
    }

    QuestItemMap const& lootPlayerNonQuestNonFFAConditionalItems = l.GetPlayerNonQuestNonFFAConditionalItems();
    QuestItemMap::const_iterator nn_itr = lootPlayerNonQuestNonFFAConditionalItems.find(lv.viewer->GetGUIDLow());
    if (nn_itr != lootPlayerNonQuestNonFFAConditionalItems.end())
    {
        QuestItemList* conditional_list = nn_itr->second;
        for (QuestItemList::const_iterator ci = conditional_list->begin(); ci != conditional_list->end(); ++ci)
        {
            LootItem &item = l.items[ci->index];
            if (!ci->is_looted && !item.is_looted)
            {
                b << uint8(ci->index);
                b << item;
                if (item.follow_loot_rules)
                {
                    switch (lv.permission)
                    {
                    case MASTER_PERMISSION:
                        b << uint8(LOOT_SLOT_TYPE_MASTER);
                        break;
                    case RESTRICTED_PERMISSION:
                        b << (item.is_blocked ? uint8(LOOT_SLOT_TYPE_LOCKED) : uint8(slotType));
                        break;
                    case GROUP_PERMISSION:
                    case ROUND_ROBIN_PERMISSION:
                        if (!item.is_blocked)
                            b << uint8(LOOT_SLOT_TYPE_ALLOW_LOOT);
                        else
                            b << uint8(LOOT_SLOT_TYPE_ROLL_ONGOING);
                        break;
                    default:
                        b << uint8(slotType);
                        break;
                    }
                }
                else
                    b << uint8(slotType);
                ++itemsShown;
            }
        }
    }

    //update number of items shown
    b.put<uint8>(count_pos, itemsShown);

    return b;
}

//
// --------- LootTemplate::LootGroup ---------
//

LootTemplate::LootGroup::~LootGroup()
{
    while (!ExplicitlyChanced.empty())
    {
        delete ExplicitlyChanced.back();
        ExplicitlyChanced.pop_back();
    }

    while (!EqualChanced.empty())
    {
        delete EqualChanced.back();
        EqualChanced.pop_back();
    }
}

// Adds an entry to the group (at loading stage)
void LootTemplate::LootGroup::AddEntry(LootStoreItem* item)
{
    if (item->chance != 0)
        ExplicitlyChanced.push_back(item);
    else
        EqualChanced.push_back(item);
}

// Rolls an item from the group, returns NULL if all miss their chances
LootStoreItem const* LootTemplate::LootGroup::Roll(Loot& loot, uint16 lootMode) const
{
    LootStoreItemList possibleLoot = ExplicitlyChanced;
    possibleLoot.remove_if(LootGroupInvalidSelector(loot, lootMode));

    if (!possibleLoot.empty())                             // First explicitly chanced entries are checked
    {
        float roll = (float)rand_chance();

        for (LootStoreItemList::const_iterator itr = possibleLoot.begin(); itr != possibleLoot.end(); ++itr)   // check each explicitly chanced entry in the template and modify its chance based on quality.
        {
            LootStoreItem* item = *itr;
            if (item->chance >= 100.0f)
                return item;

            roll -= item->chance;
            if (roll < 0)
                return item;
        }
    }

    possibleLoot = EqualChanced;
    possibleLoot.remove_if(LootGroupInvalidSelector(loot, lootMode));
    if (!possibleLoot.empty())                              // If nothing selected yet - an item is taken from equal-chanced part
        return Trinity::Containers::SelectRandomContainerElement(possibleLoot);

    return NULL;                                            // Empty drop from the group
}

// True if group includes at least 1 quest drop entry
bool LootTemplate::LootGroup::HasQuestDrop() const
{
    for (LootStoreItemList::const_iterator i = ExplicitlyChanced.begin(); i != ExplicitlyChanced.end(); ++i)
        if ((*i)->needs_quest)
            return true;

    for (LootStoreItemList::const_iterator i = EqualChanced.begin(); i != EqualChanced.end(); ++i)
        if ((*i)->needs_quest)
            return true;

    return false;
}

// True if group includes at least 1 quest drop entry for active quests of the player
bool LootTemplate::LootGroup::HasQuestDropForPlayer(Player const* player) const
{
    for (LootStoreItemList::const_iterator i = ExplicitlyChanced.begin(); i != ExplicitlyChanced.end(); ++i)
        if (player->HasQuestForItem((*i)->itemid))
            return true;

    for (LootStoreItemList::const_iterator i = EqualChanced.begin(); i != EqualChanced.end(); ++i)
        if (player->HasQuestForItem((*i)->itemid))
            return true;

    return false;
}

void LootTemplate::LootGroup::CopyConditions(ConditionList /*conditions*/)
{
    for (LootStoreItemList::iterator i = ExplicitlyChanced.begin(); i != ExplicitlyChanced.end(); ++i)
        (*i)->conditions.clear();

    for (LootStoreItemList::iterator i = EqualChanced.begin(); i != EqualChanced.end(); ++i)
        (*i)->conditions.clear();
}

// Rolls an item from the group (if any takes its chance) and adds the item to the loot
void LootTemplate::LootGroup::Process(Loot& loot, uint16 lootMode) const
{
    if (LootStoreItem const* item = Roll(loot, lootMode))
        loot.AddItem(*item);
}

// Overall chance for the group without equal chanced items
float LootTemplate::LootGroup::RawTotalChance() const
{
    float result = 0;

    for (LootStoreItemList::const_iterator i=ExplicitlyChanced.begin(); i != ExplicitlyChanced.end(); ++i)
        if (!(*i)->needs_quest)
            result += (*i)->chance;

    return result;
}

// Overall chance for the group
float LootTemplate::LootGroup::TotalChance() const
{
    float result = RawTotalChance();

    if (!EqualChanced.empty() && result < 100.0f)
        return 100.0f;

    return result;
}

void LootTemplate::LootGroup::Verify(LootStore const& lootstore, uint32 id, uint8 group_id) const
{
    float chance = RawTotalChance();
    if (chance > 101.0f)                                    /// @todo replace with 100% when DBs will be ready
        TC_LOG_ERROR("sql.sql", "Table '%s' entry %u group %d has total chance > 100%% (%f)", lootstore.GetName(), id, group_id, chance);

    if (chance >= 100.0f && !EqualChanced.empty())
        TC_LOG_ERROR("sql.sql", "Table '%s' entry %u group %d has items with chance=0%% but group total chance >= 100%% (%f)", lootstore.GetName(), id, group_id, chance);
}

void LootTemplate::LootGroup::CheckLootRefs(LootTemplateMap const& /*store*/, LootIdSet* ref_set) const
{
    for (LootStoreItemList::const_iterator ieItr = ExplicitlyChanced.begin(); ieItr != ExplicitlyChanced.end(); ++ieItr)
    {
        LootStoreItem* item = *ieItr;
        if (item->mincountOrRef < 0)
        {
            if (!LootTemplates_Reference.GetLootFor(-item->mincountOrRef))
                LootTemplates_Reference.ReportNotExistedId(-item->mincountOrRef);
            else if (ref_set)
                ref_set->erase(-item->mincountOrRef);
        }
    }

    for (LootStoreItemList::const_iterator ieItr = EqualChanced.begin(); ieItr != EqualChanced.end(); ++ieItr)
    {
        LootStoreItem* item = *ieItr;
        if (item->mincountOrRef < 0)
        {
            if (!LootTemplates_Reference.GetLootFor(-item->mincountOrRef))
                LootTemplates_Reference.ReportNotExistedId(-item->mincountOrRef);
            else if (ref_set)
                ref_set->erase(-item->mincountOrRef);
        }
    }
}

//
// --------- LootTemplate ---------
//

LootTemplate::~LootTemplate()
{
    for (LootStoreItemList::iterator i = Entries.begin(); i != Entries.end(); ++i)
        delete *i;

    for (size_t i = 0; i < Groups.size(); ++i)
        delete Groups[i];
}

// Adds an entry to the group (at loading stage)
void LootTemplate::AddEntry(LootStoreItem* item)
{
    if (item->group > 0 && item->mincountOrRef > 0)         // Group
    {
        if (item->group >= Groups.size())
            Groups.resize(item->group, NULL);               // Adds new group the the loot template if needed
        if (!Groups[item->group - 1])
            Groups[item->group - 1] = new LootGroup();

        Groups[item->group-1]->AddEntry(item);              // Adds new entry to the group
    }
    else                                                    // Non-grouped entries and references are stored together
        Entries.push_back(item);
}

void LootTemplate::CopyConditions(const ConditionList& conditions)
{
    for (LootStoreItemList::iterator i = Entries.begin(); i != Entries.end(); ++i)
        (*i)->conditions.clear();

    for (LootGroups::iterator i = Groups.begin(); i != Groups.end(); ++i)
        if (LootGroup* group = *i)
            group->CopyConditions(conditions);
}

void LootTemplate::CopyConditions(LootItem* li) const
{
    // Copies the conditions list from a template item to a LootItem
    for (LootStoreItemList::const_iterator _iter = Entries.begin(); _iter != Entries.end(); ++_iter)
    {
        LootStoreItem* item = *_iter;
        if (item->itemid != li->itemid)
            continue;

        li->conditions = item->conditions;
        break;
    }
}

// Rolls for every item in the template and adds the rolled items the the loot
void LootTemplate::Process(Loot& loot, bool rate, uint16 lootMode, uint8 groupId) const
{
    if (groupId)                                            // Group reference uses own processing of the group
    {
        if (groupId > Groups.size())
            return;                                         // Error message already printed at loading stage

        if (!Groups[groupId - 1])
            return;

        Groups[groupId-1]->Process(loot, lootMode);
        return;
    }

    // Rolling non-grouped items
    for (LootStoreItemList::const_iterator i = Entries.begin(); i != Entries.end(); ++i)
    {
        LootStoreItem* item = *i;
        if (!(item->lootmode & lootMode))                       // Do not add if mode mismatch
            continue;

        if (!item->Roll(rate))
            continue;                                           // Bad luck for the entry

        if (item->mincountOrRef < 0)                            // References processing
        {
            LootTemplate const* Referenced = LootTemplates_Reference.GetLootFor(-item->mincountOrRef);
            if (!Referenced)
                continue;                                       // Error message already printed at loading stage

            uint32 maxcount = uint32(float(item->maxcount) * sWorld->getRate(RATE_DROP_ITEM_REFERENCED_AMOUNT));
            for (uint32 loop = 0; loop < maxcount; ++loop)      // Ref multiplicator
                Referenced->Process(loot, rate, lootMode, item->group);
        }
        else                                                    // Plain entries (not a reference, not grouped)
            loot.AddItem(*item);                                // Chance is already checked, just add
    }

    // Now processing groups
    for (LootGroups::const_iterator i = Groups.begin(); i != Groups.end(); ++i)
        if (LootGroup* group = *i)
            group->Process(loot, lootMode);
}

// True if template includes at least 1 quest drop entry
bool LootTemplate::HasQuestDrop(LootTemplateMap const& store, uint8 groupId) const
{
    if (groupId)                                            // Group reference
    {
        if (groupId > Groups.size())
            return false;                                   // Error message [should be] already printed at loading stage

        if (!Groups[groupId - 1])
            return false;

        return Groups[groupId-1]->HasQuestDrop();
    }

    for (LootStoreItemList::const_iterator i = Entries.begin(); i != Entries.end(); ++i)
    {
        LootStoreItem* item = *i;
        if (item->mincountOrRef < 0)                        // References
        {
            LootTemplateMap::const_iterator Referenced = store.find(-item->mincountOrRef);
            if (Referenced == store.end())
                continue;                                   // Error message [should be] already printed at loading stage
            if (Referenced->second->HasQuestDrop(store, item->group))
                return true;
        }
        else if (item->needs_quest)
            return true;                                    // quest drop found
    }

    // Now processing groups
    for (LootGroups::const_iterator i = Groups.begin(); i != Groups.end(); ++i)
        if (LootGroup* group = *i)
            if (group->HasQuestDrop())
                return true;

    return false;
}

// True if template includes at least 1 quest drop for an active quest of the player
bool LootTemplate::HasQuestDropForPlayer(LootTemplateMap const& store, Player const* player, uint8 groupId) const
{
    if (groupId)                                            // Group reference
    {
        if (groupId > Groups.size())
            return false;                                   // Error message already printed at loading stage

        if (!Groups[groupId - 1])
            return false;

        return Groups[groupId-1]->HasQuestDropForPlayer(player);
    }

    // Checking non-grouped entries
    for (LootStoreItemList::const_iterator i = Entries.begin(); i != Entries.end(); ++i)
    {
        LootStoreItem* item = *i;
        if (item->mincountOrRef < 0)                        // References processing
        {
            LootTemplateMap::const_iterator Referenced = store.find(-item->mincountOrRef);
            if (Referenced == store.end())
                continue;                                   // Error message already printed at loading stage
            if (Referenced->second->HasQuestDropForPlayer(store, player, item->group))
                return true;
        }
        else if (player->HasQuestForItem(item->itemid))
            return true;                                    // active quest drop found
    }

    // Now checking groups
    for (LootGroups::const_iterator i = Groups.begin(); i != Groups.end(); ++i)
        if (LootGroup* group = *i)
            if (group->HasQuestDropForPlayer(player))
                return true;

    return false;
}

// Checks integrity of the template
void LootTemplate::Verify(LootStore const& lootstore, uint32 id) const
{
    // Checking group chances
    for (uint32 i = 0; i < Groups.size(); ++i)
        if (Groups[i])
            Groups[i]->Verify(lootstore, id, i + 1);

    /// @todo References validity checks
}

void LootTemplate::CheckLootRefs(LootTemplateMap const& store, LootIdSet* ref_set) const
{
    for (LootStoreItemList::const_iterator ieItr = Entries.begin(); ieItr != Entries.end(); ++ieItr)
    {
        LootStoreItem* item = *ieItr;
        if (item->mincountOrRef < 0)
        {
            if (!LootTemplates_Reference.GetLootFor(-item->mincountOrRef))
                LootTemplates_Reference.ReportNotExistedId(-item->mincountOrRef);
            else if (ref_set)
                ref_set->erase(-item->mincountOrRef);
        }
    }

    for (LootGroups::const_iterator grItr = Groups.begin(); grItr != Groups.end(); ++grItr)
        if (LootGroup* group = *grItr)
            group->CheckLootRefs(store, ref_set);
}

bool LootTemplate::addConditionItem(Condition* cond)
{
    if (!cond || !cond->isLoaded())//should never happen, checked at loading
    {
        TC_LOG_ERROR("loot", "LootTemplate::addConditionItem: condition is null");
        return false;
    }

    if (!Entries.empty())
    {
        for (LootStoreItemList::iterator i = Entries.begin(); i != Entries.end(); ++i)
        {
            if ((*i)->itemid == uint32(cond->SourceEntry))
            {
                (*i)->conditions.push_back(cond);
                return true;
            }
        }
    }

    if (!Groups.empty())
    {
        for (LootGroups::iterator groupItr = Groups.begin(); groupItr != Groups.end(); ++groupItr)
        {
            LootGroup* group = *groupItr;
            if (!group)
                continue;

            LootStoreItemList* itemList = group->GetExplicitlyChancedItemList();
            if (!itemList->empty())
            {
                for (LootStoreItemList::iterator i = itemList->begin(); i != itemList->end(); ++i)
                {
                    if ((*i)->itemid == uint32(cond->SourceEntry))
                    {
                        (*i)->conditions.push_back(cond);
                        return true;
                    }
                }
            }

            itemList = group->GetEqualChancedItemList();
            if (!itemList->empty())
            {
                for (LootStoreItemList::iterator i = itemList->begin(); i != itemList->end(); ++i)
                {
                    if ((*i)->itemid == uint32(cond->SourceEntry))
                    {
                        (*i)->conditions.push_back(cond);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool LootTemplate::isReference(uint32 id)
{
    for (LootStoreItemList::const_iterator ieItr = Entries.begin(); ieItr != Entries.end(); ++ieItr)
        if ((*ieItr)->itemid == id && (*ieItr)->mincountOrRef < 0)
            return true;

    return false;//not found or not reference
}

void LoadLootTemplates_Creature()
{
    TC_LOG_INFO("server.loading", "Loading creature loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Creature.LoadAndCollectLootIds(lootIdSet);

    // Remove real entries and check loot existence
    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        if (uint32 lootid = itr->second.lootid)
        {
            if (lootIdSet.find(lootid) == lootIdSet.end())
                LootTemplates_Creature.ReportNotExistedId(lootid);
            else
                lootIdSetUsed.insert(lootid);
        }
    }

    for (LootIdSet::const_iterator itr = lootIdSetUsed.begin(); itr != lootIdSetUsed.end(); ++itr)
        lootIdSet.erase(*itr);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Creature.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u creature loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 creature loot templates. DB table `creature_loot_template` is empty");
}

void LoadLootTemplates_Disenchant()
{
    TC_LOG_INFO("server.loading", "Loading disenchanting loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Disenchant.LoadAndCollectLootIds(lootIdSet);

    ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
    for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
    {
        if (uint32 lootid = itr->second.DisenchantID)
        {
            if (lootIdSet.find(lootid) == lootIdSet.end())
                LootTemplates_Disenchant.ReportNotExistedId(lootid);
            else
                lootIdSetUsed.insert(lootid);
        }
    }

    for (LootIdSet::const_iterator itr = lootIdSetUsed.begin(); itr != lootIdSetUsed.end(); ++itr)
        lootIdSet.erase(*itr);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Disenchant.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u disenchanting loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 disenchanting loot templates. DB table `disenchant_loot_template` is empty");
}

void LoadLootTemplates_Fishing()
{
    TC_LOG_INFO("server.loading", "Loading fishing loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Fishing.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    for (uint32 i = 1; i < sAreaStore.GetNumRows(); ++i)
        if (AreaTableEntry const* areaEntry = sAreaStore.LookupEntry(i))
            if (lootIdSet.find(areaEntry->ID) != lootIdSet.end())
                lootIdSet.erase(areaEntry->ID);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Fishing.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u fishing loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 fishing loot templates. DB table `fishing_loot_template` is empty");
}

void LoadLootTemplates_Gameobject()
{
    TC_LOG_INFO("server.loading", "Loading gameobject loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Gameobject.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    GameObjectTemplateContainer const* gotc = sObjectMgr->GetGameObjectTemplates();
    for (GameObjectTemplateContainer::const_iterator itr = gotc->begin(); itr != gotc->end(); ++itr)
    {
        if (uint32 lootid = itr->second.GetLootId())
        {
            if (lootIdSet.find(lootid) == lootIdSet.end())
                LootTemplates_Gameobject.ReportNotExistedId(lootid);
            else
                lootIdSetUsed.insert(lootid);
        }
    }

    for (LootIdSet::const_iterator itr = lootIdSetUsed.begin(); itr != lootIdSetUsed.end(); ++itr)
        lootIdSet.erase(*itr);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Gameobject.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u gameobject loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 gameobject loot templates. DB table `gameobject_loot_template` is empty");
}

void LoadLootTemplates_Item()
{
    TC_LOG_INFO("server.loading", "Loading item loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Item.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
    for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
        if (lootIdSet.find(itr->second.ItemId) != lootIdSet.end() && itr->second.Flags & ITEM_PROTO_FLAG_OPENABLE)
            lootIdSet.erase(itr->second.ItemId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Item.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u item loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 item loot templates. DB table `item_loot_template` is empty");
}

void LoadLootTemplates_Milling()
{
    TC_LOG_INFO("server.loading", "Loading milling loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Milling.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
    for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
    {
        if (!(itr->second.Flags & ITEM_PROTO_FLAG_MILLABLE))
            continue;

        if (lootIdSet.find(itr->second.ItemId) != lootIdSet.end())
            lootIdSet.erase(itr->second.ItemId);
    }

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Milling.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u milling loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 milling loot templates. DB table `milling_loot_template` is empty");
}

void LoadLootTemplates_Pickpocketing()
{
    TC_LOG_INFO("server.loading", "Loading pickpocketing loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Pickpocketing.LoadAndCollectLootIds(lootIdSet);

    // Remove real entries and check loot existence
    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        if (uint32 lootid = itr->second.pickpocketLootId)
        {
            if (lootIdSet.find(lootid) == lootIdSet.end())
                LootTemplates_Pickpocketing.ReportNotExistedId(lootid);
            else
                lootIdSetUsed.insert(lootid);
        }
    }

    for (LootIdSet::const_iterator itr = lootIdSetUsed.begin(); itr != lootIdSetUsed.end(); ++itr)
        lootIdSet.erase(*itr);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Pickpocketing.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u pickpocketing loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 pickpocketing loot templates. DB table `pickpocketing_loot_template` is empty");
}

void LoadLootTemplates_Prospecting()
{
    TC_LOG_INFO("server.loading", "Loading prospecting loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Prospecting.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
    for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
    {
        if (!(itr->second.Flags & ITEM_PROTO_FLAG_PROSPECTABLE))
            continue;

        if (lootIdSet.find(itr->second.ItemId) != lootIdSet.end())
            lootIdSet.erase(itr->second.ItemId);
    }

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Prospecting.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u prospecting loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 prospecting loot templates. DB table `prospecting_loot_template` is empty");
}

void LoadLootTemplates_Mail()
{
    TC_LOG_INFO("server.loading", "Loading mail loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Mail.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    for (uint32 i = 1; i < sMailTemplateStore.GetNumRows(); ++i)
        if (sMailTemplateStore.LookupEntry(i))
            if (lootIdSet.find(i) != lootIdSet.end())
                lootIdSet.erase(i);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Mail.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u mail loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 mail loot templates. DB table `mail_loot_template` is empty");
}

void LoadLootTemplates_Skinning()
{
    TC_LOG_INFO("server.loading", "Loading skinning loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Skinning.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        if (uint32 lootid = itr->second.SkinLootId)
        {
            if (lootIdSet.find(lootid) == lootIdSet.end())
                LootTemplates_Skinning.ReportNotExistedId(lootid);
            else
                lootIdSetUsed.insert(lootid);
        }
    }

    for (LootIdSet::const_iterator itr = lootIdSetUsed.begin(); itr != lootIdSetUsed.end(); ++itr)
        lootIdSet.erase(*itr);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Skinning.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u skinning loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 skinning loot templates. DB table `skinning_loot_template` is empty");
}

void LoadLootTemplates_Spell()
{
    TC_LOG_INFO("server.loading", "Loading spell loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Spell.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    for (uint32 spell_id = 1; spell_id < sSpellMgr->GetSpellInfoStoreSize(); ++spell_id)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
        if (!spellInfo)
            continue;

        // possible cases
        if (!spellInfo->IsLootCrafting())
            continue;

        if (lootIdSet.find(spell_id) == lootIdSet.end())
        {
            // not report about not trainable spells (optionally supported by DB)
            // ignore 61756 (Northrend Inscription Research (FAST QA VERSION) for example
            if (!(spellInfo->Attributes & SPELL_ATTR0_NOT_SHAPESHIFT) || (spellInfo->Attributes & SPELL_ATTR0_TRADESPELL))
            {
                LootTemplates_Spell.ReportNotExistedId(spell_id);
            }
        }
        else
            lootIdSet.erase(spell_id);
    }

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Spell.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded %u spell loot templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_ERROR("server.loading", ">> Loaded 0 spell loot templates. DB table `spell_loot_template` is empty");
}

void LoadLootTemplates_Reference()
{
    TC_LOG_INFO("server.loading", "Loading reference loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    LootTemplates_Reference.LoadAndCollectLootIds(lootIdSet);

    // check references and remove used
    LootTemplates_Creature.CheckLootRefs(&lootIdSet);
    LootTemplates_Fishing.CheckLootRefs(&lootIdSet);
    LootTemplates_Gameobject.CheckLootRefs(&lootIdSet);
    LootTemplates_Item.CheckLootRefs(&lootIdSet);
    LootTemplates_Milling.CheckLootRefs(&lootIdSet);
    LootTemplates_Pickpocketing.CheckLootRefs(&lootIdSet);
    LootTemplates_Skinning.CheckLootRefs(&lootIdSet);
    LootTemplates_Disenchant.CheckLootRefs(&lootIdSet);
    LootTemplates_Prospecting.CheckLootRefs(&lootIdSet);
    LootTemplates_Mail.CheckLootRefs(&lootIdSet);
    LootTemplates_Reference.CheckLootRefs(&lootIdSet);

    // output error for any still listed ids (not referenced from any loot table)
    LootTemplates_Reference.ReportUnusedIds(lootIdSet);

    TC_LOG_INFO("server.loading", ">> Loaded refence loot templates in %u ms", GetMSTimeDiffToNow(oldMSTime));
}
