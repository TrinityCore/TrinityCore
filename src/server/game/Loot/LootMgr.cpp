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

#include "LootMgr.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "ItemBonusMgr.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "Loot.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"

static constexpr Rates QualityToRate[MAX_ITEM_QUALITY] =
{
    RATE_DROP_ITEM_POOR,                                    // ITEM_QUALITY_POOR
    RATE_DROP_ITEM_NORMAL,                                  // ITEM_QUALITY_NORMAL
    RATE_DROP_ITEM_UNCOMMON,                                // ITEM_QUALITY_UNCOMMON
    RATE_DROP_ITEM_RARE,                                    // ITEM_QUALITY_RARE
    RATE_DROP_ITEM_EPIC,                                    // ITEM_QUALITY_EPIC
    RATE_DROP_ITEM_LEGENDARY,                               // ITEM_QUALITY_LEGENDARY
    RATE_DROP_ITEM_ARTIFACT,                                // ITEM_QUALITY_ARTIFACT,
    MAX_RATES,                                              // ITEM_QUALITY_HEIRLOOM
    MAX_RATES,                                              // ITEM_QUALITY_WOW_TOKEN
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
struct LootGroupInvalidSelector
{
    explicit LootGroupInvalidSelector(uint16 lootMode, Player const* personalLooter) : _lootMode(lootMode), _personalLooter(personalLooter) { }

    bool operator()(LootStoreItem const* item) const
    {
        if (!(item->lootmode & _lootMode))
            return true;

        if (_personalLooter && !LootItem::AllowedForPlayer(_personalLooter, nullptr, item->itemid, item->needs_quest,
            !item->needs_quest || ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(item->itemid))->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES),
            true, item->conditions))
            return true;

        return false;
    }

private:
    uint16 _lootMode;
    Player const* _personalLooter;
};

class LootTemplate::LootGroup                               // A set of loot definitions for items (refs are not allowed)
{
    public:
        LootGroup() = default;
        LootGroup(LootGroup const&) = delete;
        LootGroup(LootGroup&&) = delete;
        LootGroup& operator=(LootGroup const&) = delete;
        LootGroup& operator=(LootGroup&&) = delete;
        ~LootGroup() = default;

        void AddEntry(LootStoreItem* item);                 // Adds an entry to the group (at loading stage)
        bool HasDropForPlayer(Player const* player, bool strictUsabilityCheck) const;
        bool HasQuestDrop() const;                          // True if group includes at least 1 quest drop entry
        bool HasQuestDropForPlayer(Player const* player) const;
                                                            // The same for active quests of the player
        void Process(Loot& loot, uint16 lootMode,
            Player const* personalLooter = nullptr) const;  // Rolls an item from the group (if any) and adds the item to the loot
        float RawTotalChance() const;                       // Overall chance for the group (without equal chanced items)
        float TotalChance() const;                          // Overall chance for the group

        void Verify(LootStore const& lootstore, uint32 id, uint8 group_id) const;
        void CheckLootRefs(LootTemplateMap const& store, LootIdSet* ref_set) const;
        LootStoreItemList* GetExplicitlyChancedItemList() { return &ExplicitlyChanced; }
        LootStoreItemList* GetEqualChancedItemList() { return &EqualChanced; }
    private:
        LootStoreItemList ExplicitlyChanced;                // Entries with chances defined in DB
        LootStoreItemList EqualChanced;                     // Zero chances - every entry takes the same chance

        // Rolls an item from the group, returns NULL if all miss their chances
        LootStoreItem const* Roll(uint16 lootMode, Player const* personalLooter = nullptr) const;
};

LootStore::LootStore(LootStore&&) noexcept = default;
LootStore& LootStore::operator=(LootStore&&) noexcept = default;
LootStore::~LootStore() = default;

//Remove all data and free all memory
void LootStore::Clear()
{
    m_LootTemplates.clear();
}

// Checks validity of the loot store
// Actual checks are done within LootTemplate::Verify() which is called for every template
void LootStore::Verify() const
{
    for (auto const& [lootId, lootTemplate] : m_LootTemplates)
        lootTemplate->Verify(*this, lootId);
}

// Loads a *_loot_template DB table into loot store
// All checks of the loaded template are called from here, no error reports at loot generation required
uint32 LootStore::LoadLootTable()
{
    // Clearing store (for reloading case)
    Clear();

    //                                                    0         1     2       3              4         5        6         7         8
    QueryResult result = WorldDatabase.PQuery("SELECT Entry, ItemType, Item, Chance, QuestRequired, LootMode, GroupId, MinCount, MaxCount FROM {}", GetName());

    if (!result)
        return 0;

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 entry               = fields[0].GetUInt32();
        LootStoreItem::Type type   = static_cast<LootStoreItem::Type>(fields[1].GetInt8());
        uint32 item                = fields[2].GetUInt32();
        float  chance              = fields[3].GetFloat();
        bool   needsquest          = fields[4].GetBool();
        uint16 lootmode            = fields[5].GetUInt16();
        uint8  groupid             = fields[6].GetUInt8();
        uint8  mincount            = fields[7].GetUInt8();
        uint8  maxcount            = fields[8].GetUInt8();

        LootStoreItem* storeitem = new LootStoreItem(item, type, chance, needsquest, lootmode, groupid, mincount, maxcount);

        if (!storeitem->IsValid(*this, entry))            // Validity checks
        {
            delete storeitem;
            continue;
        }

        // Looking for the template of the entry
        auto [tab, isNew] = m_LootTemplates.try_emplace(entry);
        if (isNew)
            tab->second.reset(new LootTemplate());

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
    // scan loot for quest items
    if (LootTemplate const* lootTemplate = Trinity::Containers::MapGetValuePtr(m_LootTemplates, loot_id))
        return lootTemplate->HasQuestDrop(m_LootTemplates);

    return false;
}

bool LootStore::HaveQuestLootForPlayer(uint32 loot_id, Player const* player) const
{
    if (LootTemplate const* lootTemplate = Trinity::Containers::MapGetValuePtr(m_LootTemplates, loot_id))
        if (lootTemplate->HasQuestDropForPlayer(m_LootTemplates, player))
            return true;

    return false;
}

LootTemplate const* LootStore::GetLootFor(uint32 loot_id) const
{
    return Trinity::Containers::MapGetValuePtr(m_LootTemplates, loot_id);
}

LootTemplate* LootStore::GetLootForConditionFill(uint32 loot_id)
{
    return Trinity::Containers::MapGetValuePtr(m_LootTemplates, loot_id);
}

uint32 LootStore::LoadAndCollectLootIds(LootIdSet& lootIdSet)
{
    uint32 count = LoadLootTable();

    std::ranges::transform(m_LootTemplates, std::inserter(lootIdSet, lootIdSet.end()), &LootTemplateMap::value_type::first);

    return count;
}

void LootStore::CheckLootRefs(LootIdSet* ref_set) const
{
    for (auto const& [_, lootTemplate] : m_LootTemplates)
        lootTemplate->CheckLootRefs(m_LootTemplates, ref_set);
}

void LootStore::ReportUnusedIds(LootIdSet const& lootIdSet) const
{
    // all still listed ids isn't referenced
    for (uint32 lootId : lootIdSet)
        TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} isn't {} and not referenced from loot, and thus useless.", GetName(), lootId, GetEntryName());
}

void LootStore::ReportNonExistingId(uint32 lootId) const
{
    TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} does not exist", GetName(), lootId);
}

void LootStore::ReportNonExistingId(uint32 lootId, char const* ownerType, uint32 ownerId) const
{
    TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} does not exist but it is used by {} {}", GetName(), lootId, ownerType, ownerId);
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

    switch (type)
    {
        case Type::Item:
        {
            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(itemid);

            float qualityModifier = pProto && rate && QualityToRate[pProto->GetQuality()] != MAX_RATES ? sWorld->getRate(QualityToRate[pProto->GetQuality()]) : 1.0f;

            return roll_chance_f(chance * qualityModifier);
        }
        case Type::Reference:
            return roll_chance_f(chance * (rate ? sWorld->getRate(RATE_DROP_ITEM_REFERENCED) : 1.0f));
        default:
            break;
    }

    return false;
}

// Checks correctness of values
bool LootStoreItem::IsValid(LootStore const& store, uint32 entry) const
{
    if (mincount == 0)
    {
        TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: wrong MinCount ({}) - skipped", store.GetName(), entry, itemid, mincount);
        return false;
    }

    switch (type)
    {
        case Type::Item:
        {
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemid);
            if (!proto)
            {
                TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: item does not exist - skipped", store.GetName(), entry, itemid);
                return false;
            }

            if (chance == 0 && groupid == 0)                // Zero chance is allowed for grouped entries only
            {
                TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: equal-chanced grouped entry, but group not defined - skipped", store.GetName(), entry, itemid);
                return false;
            }

            if (chance != 0 && chance < 0.000001f)          // loot with low chance
            {
                TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: low chance ({}) - skipped",
                    store.GetName(), entry, itemid, chance);
                return false;
            }

            if (maxcount < mincount)                        // wrong max count
            {
                TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: MaxCount ({}) less that MinCount ({}) - skipped", store.GetName(), entry, itemid, int32(maxcount), mincount);
                return false;
            }
            break;
        }
        case Type::Reference:
            if (needs_quest)
                TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: quest required will be ignored", store.GetName(), entry, itemid);
            else if (chance == 0)                           // no chance for the reference
            {
                TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: zero chance is specified for a reference, skipped", store.GetName(), entry, itemid);
                return false;
            }
            break;
        default:
            TC_LOG_ERROR("sql.sql", "Table '{}' Entry {} Item {}: invalid ItemType {}, skipped", store.GetName(), entry, itemid, type);
            return false;
    }
    return true;                                            // Referenced template existence is checked at whole store level
}

//
// --------- LootTemplate::LootGroup ---------
//

// Adds an entry to the group (at loading stage)
void LootTemplate::LootGroup::AddEntry(LootStoreItem* item)
{
    if (item->chance != 0)
        ExplicitlyChanced.emplace_back(item);
    else
        EqualChanced.emplace_back(item);
}

// Rolls an item from the group, returns NULL if all miss their chances
LootStoreItem const* LootTemplate::LootGroup::Roll(uint16 lootMode, Player const* personalLooter /*= nullptr*/) const
{
    auto getValidLoot = [](LootStoreItemList const& items, uint16 lootMode, Player const* personalLooter)
    {
        std::vector<LootStoreItem const*> possibleLoot;
        possibleLoot.resize(items.size());
        std::ranges::transform(items, possibleLoot.begin(), [](std::unique_ptr<LootStoreItem> const& i) { return i.get(); });
        Trinity::Containers::EraseIf(possibleLoot, LootGroupInvalidSelector(lootMode, personalLooter));
        return possibleLoot;
    };

    std::vector<LootStoreItem const*> possibleLoot = getValidLoot(ExplicitlyChanced, lootMode, personalLooter);

    if (!possibleLoot.empty())                              // First explicitly chanced entries are checked
    {
        float roll = rand_chance();

        for (LootStoreItem const* item : possibleLoot)      // check each explicitly chanced entry in the template and modify its chance based on quality.
        {
            if (item->chance >= 100.0f)
                return item;

            roll -= item->chance;
            if (roll < 0)
                return item;
        }
    }

    possibleLoot = getValidLoot(EqualChanced, lootMode, personalLooter);
    if (!possibleLoot.empty())                              // If nothing selected yet - an item is taken from equal-chanced part
        return Trinity::Containers::SelectRandomContainerElement(possibleLoot);

    return nullptr;                                         // Empty drop from the group
}

bool LootTemplate::LootGroup::HasDropForPlayer(Player const* player, bool strictUsabilityCheck) const
{
    for (std::unique_ptr<LootStoreItem> const& lootStoreItem : ExplicitlyChanced)
        if (LootItem::AllowedForPlayer(player, nullptr, lootStoreItem->itemid, lootStoreItem->needs_quest,
            !lootStoreItem->needs_quest || ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(lootStoreItem->itemid))->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES),
            strictUsabilityCheck, lootStoreItem->conditions))
            return true;

    for (std::unique_ptr<LootStoreItem> const& lootStoreItem : EqualChanced)
        if (LootItem::AllowedForPlayer(player, nullptr, lootStoreItem->itemid, lootStoreItem->needs_quest,
            !lootStoreItem->needs_quest || ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(lootStoreItem->itemid))->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES),
            strictUsabilityCheck, lootStoreItem->conditions))
            return true;

    return false;
}

// True if group includes at least 1 quest drop entry
bool LootTemplate::LootGroup::HasQuestDrop() const
{
    if (std::ranges::any_of(ExplicitlyChanced, &LootStoreItem::needs_quest))
        return true;

    if (std::ranges::any_of(EqualChanced, &LootStoreItem::needs_quest))
        return true;

    return false;
}

// True if group includes at least 1 quest drop entry for active quests of the player
bool LootTemplate::LootGroup::HasQuestDropForPlayer(Player const* player) const
{
    if (std::ranges::any_of(ExplicitlyChanced, [player](uint32 itemId) { return player->HasQuestForItem(itemId); }, &LootStoreItem::itemid))
        return true;

    if (std::ranges::any_of(EqualChanced, [player](uint32 itemId) { return player->HasQuestForItem(itemId); }, &LootStoreItem::itemid))
        return true;

    return false;
}

// Rolls an item from the group (if any takes its chance) and adds the item to the loot
void LootTemplate::LootGroup::Process(Loot& loot, uint16 lootMode, Player const* personalLooter /*= nullptr*/) const
{
    if (LootStoreItem const* item = Roll(lootMode, personalLooter))
        loot.AddItem(*item);
}

// Overall chance for the group without equal chanced items
float LootTemplate::LootGroup::RawTotalChance() const
{
    float result = 0;

    for (std::unique_ptr<LootStoreItem> const& item : ExplicitlyChanced)
        if (!item->needs_quest)
            result += item->chance;

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
        TC_LOG_ERROR("sql.sql", "Table '{}' entry {} group {} has total chance > 100% ({})", lootstore.GetName(), id, group_id, chance);

    if (chance >= 100.0f && !EqualChanced.empty())
        TC_LOG_ERROR("sql.sql", "Table '{}' entry {} group {} has items with chance=0% but group total chance >= 100% ({})", lootstore.GetName(), id, group_id, chance);
}

void LootTemplate::LootGroup::CheckLootRefs(LootTemplateMap const& /*store*/, LootIdSet* ref_set) const
{
    for (std::unique_ptr<LootStoreItem> const& item : ExplicitlyChanced)
    {
        if (item->type == LootStoreItem::Type::Reference)
        {
            if (!LootTemplates_Reference.GetLootFor(item->itemid))
                LootTemplates_Reference.ReportNonExistingId(item->itemid, "Reference", item->itemid);
            else if (ref_set)
                ref_set->erase(item->itemid);
        }
    }

    for (std::unique_ptr<LootStoreItem> const& item : EqualChanced)
    {
        if (item->type == LootStoreItem::Type::Reference)
        {
            if (!LootTemplates_Reference.GetLootFor(item->itemid))
                LootTemplates_Reference.ReportNonExistingId(item->itemid, "Reference", item->itemid);
            else if (ref_set)
                ref_set->erase(item->itemid);
        }
    }
}

//
// --------- LootTemplate ---------
//

LootTemplate::LootTemplate() = default;
LootTemplate::LootTemplate(LootTemplate&&) noexcept = default;
LootTemplate& LootTemplate::operator=(LootTemplate&&) noexcept = default;
LootTemplate::~LootTemplate() = default;

// Adds an entry to the group (at loading stage)
void LootTemplate::AddEntry(LootStoreItem* item)
{
    if (item->groupid > 0 && item->type != LootStoreItem::Type::Reference)  // Group
    {
        std::unique_ptr<LootGroup>& group = Trinity::Containers::EnsureWritableVectorIndex(Groups, item->groupid - 1);
        if (!group)
            group.reset(new LootGroup());                     // Adds new group the the loot template if needed

        group->AddEntry(item);                                // Adds new entry to the group
    }
    else                                                      // Non-grouped entries and references are stored together
        Entries.emplace_back(item);
}

void LootTemplate::CopyConditions(LootItem* li) const
{
    // Copies the conditions list from a template item to a LootItemData
    for (std::unique_ptr<LootStoreItem> const& item : Entries)
    {
        if (item->itemid != li->itemid)
            continue;

        li->conditions = item->conditions;
        break;
    }
}

// Rolls for every item in the template and adds the rolled items the the loot
void LootTemplate::Process(Loot& loot, bool rate, uint16 lootMode, uint8 groupId, Player const* personalLooter /*= nullptr*/) const
{
    if (groupId)                                            // Group reference uses own processing of the group
    {
        if (groupId > Groups.size())
            return;                                         // Error message already printed at loading stage

        if (!Groups[groupId - 1])
            return;

        Groups[groupId - 1]->Process(loot, lootMode, personalLooter);
        return;
    }

    // Rolling non-grouped items
    for (std::unique_ptr<LootStoreItem> const& item : Entries)
    {
        if (!(item->lootmode & lootMode))                       // Do not add if mode mismatch
            continue;

        if (!item->Roll(rate))
            continue;                                           // Bad luck for the entry

        switch (item->type)
        {
            case LootStoreItem::Type::Item:
                // Plain entries (not a reference, not grouped)
                // Chance is already checked, just add
                if (!personalLooter
                    || LootItem::AllowedForPlayer(personalLooter, nullptr, item->itemid, item->needs_quest,
                        !item->needs_quest || ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(item->itemid))->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES),
                        true, item->conditions))
                    loot.AddItem(*item);

                break;
            case LootStoreItem::Type::Reference:
            {
                LootTemplate const* Referenced = LootTemplates_Reference.GetLootFor(item->itemid);
                if (!Referenced)
                    continue;                                   // Error message already printed at loading stage

                uint32 maxcount = uint32(float(item->maxcount) * sWorld->getRate(RATE_DROP_ITEM_REFERENCED_AMOUNT));
                for (uint32 loop = 0; loop < maxcount; ++loop)  // Ref multiplicator
                    Referenced->Process(loot, rate, lootMode, item->groupid, personalLooter);

                break;
            }
            default:
                break;
        }
    }

    // Now processing groups
    for (std::unique_ptr<LootGroup> const& group : Groups)
        if (group)
            group->Process(loot, lootMode, personalLooter);
}

void LootTemplate::ProcessPersonalLoot(std::unordered_map<Player*, std::unique_ptr<Loot>>& personalLoot, bool rate, uint16 lootMode) const
{
    auto getLootersForItem = [&personalLoot](auto&& predicate)
    {
        std::vector<Player*> lootersForItem;
        for (auto&& [looter, loot] : personalLoot)
        {
            if (predicate(looter))
                lootersForItem.push_back(looter);
        }
        return lootersForItem;
    };

    // Rolling non-grouped items
    for (std::unique_ptr<LootStoreItem> const& item : Entries)
    {
        if (!(item->lootmode & lootMode))                       // Do not add if mode mismatch
            continue;

        if (!item->Roll(rate))
            continue;                                           // Bad luck for the entry

        switch (item->type)
        {
            case LootStoreItem::Type::Item:
            {
                // Plain entries (not a reference, not grouped)
                // Chance is already checked, just add
                std::vector<Player*> lootersForItem = getLootersForItem([&](Player const* looter)
                {
                    return LootItem::AllowedForPlayer(looter, nullptr, item->itemid, item->needs_quest,
                        !item->needs_quest || ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(item->itemid))->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES),
                        true, item->conditions);
                });

                if (!lootersForItem.empty())
                {
                    Player* chosenLooter = Trinity::Containers::SelectRandomContainerElement(lootersForItem);
                    personalLoot[chosenLooter]->AddItem(*item);
                }
                break;
            }
            case LootStoreItem::Type::Reference:
            {
                LootTemplate const* referenced = LootTemplates_Reference.GetLootFor(item->itemid);
                if (!referenced)
                    continue;                                       // Error message already printed at loading stage

                uint32 maxcount = uint32(float(item->maxcount) * sWorld->getRate(RATE_DROP_ITEM_REFERENCED_AMOUNT));
                std::vector<Player*> gotLoot;
                for (uint32 loop = 0; loop < maxcount; ++loop)      // Ref multiplicator
                {
                    std::vector<Player*> lootersForItem = getLootersForItem([&](Player const* looter)
                    {
                        return referenced->HasDropForPlayer(looter, item->groupid, true);
                    });

                    // nobody can loot this, skip it
                    if (lootersForItem.empty())
                        break;

                    auto newEnd = std::ranges::remove_if(lootersForItem, [&](Player const* looter)
                    {
                        return std::ranges::find(gotLoot, looter) != gotLoot.end();
                    });

                    if (lootersForItem.begin() == newEnd.begin())
                    {
                        // if we run out of looters this means that there are more items dropped than players
                        // start a new cycle adding one item to everyone
                        gotLoot.clear();
                    }
                    else
                        lootersForItem.erase(newEnd.begin(), newEnd.end());

                    Player* chosenLooter = Trinity::Containers::SelectRandomContainerElement(lootersForItem);
                    referenced->Process(*personalLoot[chosenLooter], rate, lootMode, item->groupid, chosenLooter);
                    gotLoot.push_back(chosenLooter);
                }

                break;
            }
            default:
                break;
        }
    }

    // Now processing groups
    for (std::unique_ptr<LootGroup> const& group : Groups)
    {
        if (group)
        {
            std::vector<Player*> lootersForGroup = getLootersForItem([&](Player const* looter)
            {
                return group->HasDropForPlayer(looter, true);
            });

            if (!lootersForGroup.empty())
            {
                Player* chosenLooter = Trinity::Containers::SelectRandomContainerElement(lootersForGroup);
                group->Process(*personalLoot[chosenLooter], lootMode);
            }
        }
    }
}

// True if template includes at least 1 drop for the player
bool LootTemplate::HasDropForPlayer(Player const* player, uint8 groupId, bool strictUsabilityCheck) const
{
    if (groupId)                                            // Group reference
    {
        if (groupId > Groups.size())
            return false;                                   // Error message already printed at loading stage

        if (!Groups[groupId - 1])
            return false;

        return Groups[groupId - 1]->HasDropForPlayer(player, strictUsabilityCheck);
    }

    // Checking non-grouped entries
    for (std::unique_ptr<LootStoreItem> const& lootStoreItem : Entries)
    {
        switch (lootStoreItem->type)
        {
            case LootStoreItem::Type::Item:
                if (LootItem::AllowedForPlayer(player, nullptr, lootStoreItem->itemid, lootStoreItem->needs_quest,
                    !lootStoreItem->needs_quest || ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(lootStoreItem->itemid))->HasFlag(ITEM_FLAGS_CU_FOLLOW_LOOT_RULES),
                    strictUsabilityCheck, lootStoreItem->conditions))
                    return true;                                    // active quest drop found
                break;
            case LootStoreItem::Type::Reference:
            {
                LootTemplate const* referenced = LootTemplates_Reference.GetLootFor(lootStoreItem->itemid);
                if (!referenced)
                    continue;                                       // Error message already printed at loading stage
                if (referenced->HasDropForPlayer(player, lootStoreItem->groupid, strictUsabilityCheck))
                    return true;
                break;
            }
            default:
                break;
        }
    }

    // Now checking groups
    for (std::unique_ptr<LootGroup> const& group : Groups)
        if (group && group->HasDropForPlayer(player, strictUsabilityCheck))
            return true;

    return false;
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

    for (std::unique_ptr<LootStoreItem> const& item : Entries)
    {
        switch (item->type)
        {
            case LootStoreItem::Type::Item:
                if (item->needs_quest)
                    return true;                            // quest drop found
                break;
            case LootStoreItem::Type::Reference:
            {
                LootTemplateMap::const_iterator Referenced = store.find(item->itemid);
                if (Referenced == store.end())
                    continue;                               // Error message [should be] already printed at loading stage
                if (Referenced->second->HasQuestDrop(store, item->groupid))
                    return true;
                break;
            }
            default:
                break;
        }
    }

    // Now processing groups
    for (std::unique_ptr<LootGroup> const& group : Groups)
        if (group && group->HasQuestDrop())
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

        return Groups[groupId - 1]->HasQuestDropForPlayer(player);
    }

    // Checking non-grouped entries
    for (std::unique_ptr<LootStoreItem> const& item : Entries)
    {
        switch (item->type)
        {
            case LootStoreItem::Type::Item:
                if (player->HasQuestForItem(item->itemid))
                    return true;                            // active quest drop found
                break;
            case LootStoreItem::Type::Reference:
            {
                LootTemplateMap::const_iterator Referenced = store.find(item->itemid);
                if (Referenced == store.end())
                    continue;                               // Error message already printed at loading stage
                if (Referenced->second->HasQuestDropForPlayer(store, player, item->groupid))
                    return true;
                break;
            }
            default:
                break;
        }
    }

    // Now checking groups
    for (std::unique_ptr<LootGroup> const& group : Groups)
        if (group && group->HasQuestDropForPlayer(player))
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
    for (std::unique_ptr<LootStoreItem> const& item : Entries)
    {
        if (item->type == LootStoreItem::Type::Reference)
        {
            if (!LootTemplates_Reference.GetLootFor(item->itemid))
                LootTemplates_Reference.ReportNonExistingId(item->itemid, "Reference", item->itemid);
            else if (ref_set)
                ref_set->erase(item->itemid);
        }
    }

    for (std::unique_ptr<LootGroup> const& group : Groups)
        if (group)
            group->CheckLootRefs(store, ref_set);
}

bool LootTemplate::LinkConditions(ConditionId const& id, ConditionsReference reference)
{
    if (!Entries.empty())
    {
        for (std::unique_ptr<LootStoreItem>& item : Entries)
        {
            if (item->itemid == uint32(id.SourceEntry))
            {
                item->conditions = std::move(reference);
                return true;
            }
        }
    }

    if (!Groups.empty())
    {
        for (std::unique_ptr<LootGroup>& group : Groups)
        {
            if (!group)
                continue;

            LootStoreItemList* itemList = group->GetExplicitlyChancedItemList();
            if (!itemList->empty())
            {
                for (std::unique_ptr<LootStoreItem> const& item : *itemList)
                {
                    if (item->itemid == uint32(id.SourceEntry))
                    {
                        item->conditions = std::move(reference);
                        return true;
                    }
                }
            }

            itemList = group->GetEqualChancedItemList();
            if (!itemList->empty())
            {
                for (std::unique_ptr<LootStoreItem> const& item : *itemList)
                {
                    if (item->itemid == uint32(id.SourceEntry))
                    {
                        item->conditions = std::move(reference);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

std::unordered_map<ObjectGuid, std::unique_ptr<Loot>> GenerateDungeonEncounterPersonalLoot(uint32 dungeonEncounterId, uint32 lootId, LootStore const& store,
    LootType type, WorldObject const* lootOwner, uint32 minMoney, uint32 maxMoney, uint16 lootMode, MapDifficultyEntry const* mapDifficulty,
    std::vector<Player*> const& tappers)
{
    std::unordered_map<Player*, std::unique_ptr<Loot>> tempLoot;

    for (Player* tapper : tappers)
    {
        if (tapper->IsLockedToDungeonEncounter(dungeonEncounterId))
            continue;

        std::unique_ptr<Loot>& loot = tempLoot[tapper];
        loot.reset(new Loot(lootOwner->GetMap(), lootOwner->GetGUID(), type, nullptr));
        loot->SetItemContext(ItemBonusMgr::GetContextForPlayer(mapDifficulty, tapper));
        loot->SetDungeonEncounterId(dungeonEncounterId);
        loot->generateMoneyLoot(minMoney, maxMoney);
    }

    if (LootTemplate const* tab = store.GetLootFor(lootId))
        tab->ProcessPersonalLoot(tempLoot, store.IsRatesAllowed(), lootMode);

    std::unordered_map<ObjectGuid, std::unique_ptr<Loot>> personalLoot;
    for (auto&& [looter, loot] : tempLoot)
    {
        loot->FillNotNormalLootFor(looter);

        if (loot->isLooted())
            continue;

        personalLoot[looter->GetGUID()] = std::move(loot);
    }

    return personalLoot;
}

void LoadLootTemplates_Creature()
{
    TC_LOG_INFO("server.loading", "Loading creature loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Creature.LoadAndCollectLootIds(lootIdSet);

    // Remove real entries and check loot existence
    CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
    for (auto const& [creatureId, creatureTemplate] : ctc)
    {
        for (auto const& [difficulty, creatureDifficulty] : creatureTemplate.difficultyStore)
        {
            if (uint32 lootid = creatureDifficulty.LootID)
            {
                if (!lootIdSet.contains(lootid))
                    LootTemplates_Creature.ReportNonExistingId(lootid, "Creature", creatureId);
                else
                    lootIdSetUsed.insert(lootid);
            }
        }
    }

    for (uint32 lootId : lootIdSetUsed)
        lootIdSet.erase(lootId);

    // 1 means loot for player corpse
    lootIdSet.erase(PLAYER_CORPSE_LOOT_ENTRY);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Creature.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} creature loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature loot templates. DB table `creature_loot_template` is empty");
}

void LoadLootTemplates_Disenchant()
{
    TC_LOG_INFO("server.loading", "Loading disenchanting loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Disenchant.LoadAndCollectLootIds(lootIdSet);

    for (ItemDisenchantLootEntry const* disenchant : sItemDisenchantLootStore)
    {
        uint32 lootid = disenchant->ID;
        if (!lootIdSet.contains(lootid))
            LootTemplates_Disenchant.ReportNonExistingId(lootid);
        else
            lootIdSetUsed.insert(lootid);
    }

    for (uint32 lootId : lootIdSetUsed)
        lootIdSet.erase(lootId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Disenchant.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} disenchanting loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 disenchanting loot templates. DB table `disenchant_loot_template` is empty");
}

void LoadLootTemplates_Fishing()
{
    TC_LOG_INFO("server.loading", "Loading fishing loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Fishing.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    for (AreaTableEntry const* areaTable : sAreaTableStore)
        lootIdSet.erase(areaTable->ID);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Fishing.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} fishing loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 fishing loot templates. DB table `fishing_loot_template` is empty");
}

void LoadLootTemplates_Gameobject()
{
    TC_LOG_INFO("server.loading", "Loading gameobject loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Gameobject.LoadAndCollectLootIds(lootIdSet);

    auto checkLootId = [&](uint32 lootId, uint32 gameObjectId)
    {
        if (!lootIdSet.contains(lootId))
            LootTemplates_Gameobject.ReportNonExistingId(lootId, "Gameobject", gameObjectId);
        else
            lootIdSetUsed.insert(lootId);
    };

    // remove real entries and check existence loot
    GameObjectTemplateContainer const& gotc = sObjectMgr->GetGameObjectTemplates();
    for (auto const& [gameObjectId, gameObjectTemplate] : gotc)
    {
        if (uint32 lootid = gameObjectTemplate.GetLootId())
            checkLootId(lootid, gameObjectId);

        if (gameObjectTemplate.type == GAMEOBJECT_TYPE_CHEST)
        {
            if (gameObjectTemplate.chest.chestPersonalLoot)
                checkLootId(gameObjectTemplate.chest.chestPersonalLoot, gameObjectId);

            if (gameObjectTemplate.chest.chestPushLoot)
                checkLootId(gameObjectTemplate.chest.chestPushLoot, gameObjectId);
        }
    }

    for (uint32 lootId : lootIdSetUsed)
        lootIdSet.erase(lootId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Gameobject.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} gameobject loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject loot templates. DB table `gameobject_loot_template` is empty");
}

void LoadLootTemplates_Item()
{
    TC_LOG_INFO("server.loading", "Loading item loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Item.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& [itemId, itemTemplate] : its)
        if (itemTemplate.HasFlag(ITEM_FLAG_HAS_LOOT))
            if (!lootIdSet.erase(itemId))
                LootTemplates_Item.ReportNonExistingId(itemId, "Item", itemId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Item.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} item loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 item loot templates. DB table `item_loot_template` is empty");
}

void LoadLootTemplates_Milling()
{
    TC_LOG_INFO("server.loading", "Loading milling loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Milling.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& [itemId, itemTemplate] : its)
        if (itemTemplate.HasFlag(ITEM_FLAG_IS_MILLABLE))
            if (!lootIdSet.erase(itemId))
                LootTemplates_Milling.ReportNonExistingId(itemId, "Item", itemId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Milling.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} milling loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 milling loot templates. DB table `milling_loot_template` is empty");
}

void LoadLootTemplates_Pickpocketing()
{
    TC_LOG_INFO("server.loading", "Loading pickpocketing loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Pickpocketing.LoadAndCollectLootIds(lootIdSet);

    // Remove real entries and check loot existence
    CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
    for (auto const& [creatureId, creatureTemplate] : ctc)
    {
        for (auto const& [difficulty, creatureDifficulty] : creatureTemplate.difficultyStore)
        {
            if (uint32 lootid = creatureDifficulty.PickPocketLootID)
            {
                if (!lootIdSet.contains(lootid))
                    LootTemplates_Pickpocketing.ReportNonExistingId(lootid, "Creature", creatureId);
                else
                    lootIdSetUsed.insert(lootid);
            }
        }
    }

    for (uint32 lootId : lootIdSetUsed)
        lootIdSet.erase(lootId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Pickpocketing.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} pickpocketing loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 pickpocketing loot templates. DB table `pickpocketing_loot_template` is empty");
}

void LoadLootTemplates_Prospecting()
{
    TC_LOG_INFO("server.loading", "Loading prospecting loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Prospecting.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& [itemId, itemTemplate] : its)
        if (itemTemplate.HasFlag(ITEM_FLAG_IS_PROSPECTABLE))
            if (!lootIdSet.erase(itemId))
                LootTemplates_Prospecting.ReportNonExistingId(itemId, "Item", itemId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Prospecting.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} prospecting loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 prospecting loot templates. DB table `prospecting_loot_template` is empty");
}

void LoadLootTemplates_Mail()
{
    TC_LOG_INFO("server.loading", "Loading mail loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet;
    uint32 count = LootTemplates_Mail.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    for (MailTemplateEntry const* mailTemplate : sMailTemplateStore)
        lootIdSet.erase(mailTemplate->ID);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Mail.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} mail loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 mail loot templates. DB table `mail_loot_template` is empty");
}

void LoadLootTemplates_Skinning()
{
    TC_LOG_INFO("server.loading", "Loading skinning loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Skinning.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
    for (auto const& [creatureId, creatureTemplate] : ctc)
    {
        for (auto const& [difficulty, creatureDifficulty] : creatureTemplate.difficultyStore)
        {
            if (uint32 lootid = creatureDifficulty.SkinLootID)
            {
                if (!lootIdSet.contains(lootid))
                    LootTemplates_Skinning.ReportNonExistingId(lootid, "Creature", creatureId);
                else
                    lootIdSetUsed.insert(lootid);
            }
        }
    }

    for (uint32 lootId : lootIdSetUsed)
        lootIdSet.erase(lootId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Skinning.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} skinning loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 skinning loot templates. DB table `skinning_loot_template` is empty");
}

void LoadLootTemplates_Spell()
{
    // TODO: change this to use MiscValue from spell effect as id instead of spell id
    TC_LOG_INFO("server.loading", "Loading spell loot templates...");

    uint32 oldMSTime = getMSTime();

    LootIdSet lootIdSet, lootIdSetUsed;
    uint32 count = LootTemplates_Spell.LoadAndCollectLootIds(lootIdSet);

    // remove real entries and check existence loot
    sSpellMgr->ForEachSpellInfo([&](SpellInfo const* spellInfo)
    {
        // possible cases
        if (!spellInfo->IsLootCrafting())
            return;

        if (!lootIdSet.contains(spellInfo->Id))
        {
            // not report about not trainable spells (optionally supported by DB)
            // ignore 61756 (Northrend Inscription Research (FAST QA VERSION) for example
            if (!spellInfo->HasAttribute(SPELL_ATTR0_NOT_SHAPESHIFTED) || spellInfo->HasAttribute(SPELL_ATTR0_IS_TRADESKILL))
                LootTemplates_Spell.ReportNonExistingId(spellInfo->Id, "Spell", spellInfo->Id);
        }
        else
            lootIdSetUsed.insert(spellInfo->Id);
    });

    for (uint32 lootId : lootIdSetUsed)
        lootIdSet.erase(lootId);

    // output error for any still listed (not referenced from appropriate table) ids
    LootTemplates_Spell.ReportUnusedIds(lootIdSet);

    if (count)
        TC_LOG_INFO("server.loading", ">> Loaded {} spell loot templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell loot templates. DB table `spell_loot_template` is empty");
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

    TC_LOG_INFO("server.loading", ">> Loaded reference loot templates in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void LoadLootTables()
{
    LoadLootTemplates_Creature();
    LoadLootTemplates_Fishing();
    LoadLootTemplates_Gameobject();
    LoadLootTemplates_Item();
    LoadLootTemplates_Mail();
    LoadLootTemplates_Milling();
    LoadLootTemplates_Pickpocketing();
    LoadLootTemplates_Skinning();
    LoadLootTemplates_Disenchant();
    LoadLootTemplates_Prospecting();
    LoadLootTemplates_Spell();

    LoadLootTemplates_Reference();
}
