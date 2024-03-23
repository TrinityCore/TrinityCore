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

#include "ItemBonusMgr.h"
#include "ConditionMgr.h"
#include "DB2Stores.h"
#include "MapUtils.h"
#include "ObjectMgr.h"
#include "Player.h"

namespace
{
struct ItemLevelSelectorQualityEntryComparator
{
    bool operator()(ItemLevelSelectorQualityEntry const* left, ItemLevelSelectorQualityEntry const* right) const { return left->Quality < right->Quality; }
    bool operator()(ItemLevelSelectorQualityEntry const* left, ItemQualities quality) const { return left->Quality < quality; }
};

using ItemLevelSelectorQualities = std::set<ItemLevelSelectorQualityEntry const*, ItemLevelSelectorQualityEntryComparator>;

std::unordered_map<uint32 /*itemBonusListId*/, std::vector<ItemBonusEntry const*>> _itemBonusLists;
std::unordered_map<int16 /*itemLevelDelta*/, uint32 /*itemBonusListId*/> _itemLevelDeltaToBonusListContainer;
std::unordered_map<uint32 /*itemLevelSelectorQualitySetId*/, ItemLevelSelectorQualities> _itemLevelQualitySelectorQualities;
std::unordered_map<uint32 /*itemBonusTreeId*/, std::set<ItemBonusTreeNodeEntry const*>> _itemBonusTrees;
std::unordered_multimap<uint32 /*itemId*/, uint32 /*itemBonusTreeId*/> _itemToBonusTree;
}

namespace ItemBonusMgr
{
void Load()
{
    for (ItemBonusEntry const* bonus : sItemBonusStore)
        _itemBonusLists[bonus->ParentItemBonusListID].push_back(bonus);

    for (ItemBonusListLevelDeltaEntry const* itemBonusListLevelDelta : sItemBonusListLevelDeltaStore)
        _itemLevelDeltaToBonusListContainer[itemBonusListLevelDelta->ItemLevelDelta] = itemBonusListLevelDelta->ID;

    for (ItemLevelSelectorQualityEntry const* itemLevelSelectorQuality : sItemLevelSelectorQualityStore)
        _itemLevelQualitySelectorQualities[itemLevelSelectorQuality->ParentILSQualitySetID].insert(itemLevelSelectorQuality);

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : sItemBonusTreeNodeStore)
        _itemBonusTrees[bonusTreeNode->ParentItemBonusTreeID].insert(bonusTreeNode);

    for (ItemXBonusTreeEntry const* itemBonusTreeAssignment : sItemXBonusTreeStore)
        _itemToBonusTree.insert({ itemBonusTreeAssignment->ItemID, itemBonusTreeAssignment->ItemBonusTreeID });
}

ItemContext GetContextForPlayer(MapDifficultyEntry const* mapDifficulty, Player const* player)
{
    if (!mapDifficulty)
        return ItemContext::NONE;

    auto evalContext = [](ItemContext currentContext, ItemContext newContext)
    {
        if (newContext == ItemContext::NONE)
            newContext = currentContext;
        else if (newContext == ItemContext::Force_to_NONE)
            newContext = ItemContext::NONE;
        return newContext;
    };

    ItemContext context = ItemContext::NONE;
    if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(mapDifficulty->DifficultyID))
        context = evalContext(context, ItemContext(difficulty->ItemContext));

    context = evalContext(context, ItemContext(mapDifficulty->ItemContext));

    if (mapDifficulty->ItemContextPickerID)
    {
        uint32 contentTuningId = sDB2Manager.GetRedirectedContentTuningId(mapDifficulty->ContentTuningID, 0 /*player->m_playerData->CtrOptions->ContentTuningConditionMask*/);

        ItemContextPickerEntryEntry const* selectedPickerEntry = nullptr;
        for (ItemContextPickerEntryEntry const* itemContextPickerEntry : sItemContextPickerEntryStore)
        {
            if (itemContextPickerEntry->ItemContextPickerID != uint32(mapDifficulty->ItemContextPickerID))
                continue;

            if (itemContextPickerEntry->PVal <= 0)
                continue;

            bool meetsPlayerCondition = false;
            if (player)
                if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(itemContextPickerEntry->PlayerConditionID))
                    meetsPlayerCondition = ConditionMgr::IsPlayerMeetingCondition(player, playerCondition);

            if (itemContextPickerEntry->Flags & 0x1)
                meetsPlayerCondition = !meetsPlayerCondition;

            if (!meetsPlayerCondition)
                continue;

            if (!selectedPickerEntry || selectedPickerEntry->OrderIndex < itemContextPickerEntry->OrderIndex)
                selectedPickerEntry = itemContextPickerEntry;
        }

        if (selectedPickerEntry)
            context = evalContext(context, ItemContext(selectedPickerEntry->ItemCreationContext));
    }

    return context;
}

std::span<ItemBonusEntry const*> GetItemBonuses(uint32 bonusListId)
{
    if (std::vector<ItemBonusEntry const*>* itemBonusEntries = Trinity::Containers::MapGetValuePtr(_itemBonusLists, bonusListId))
        return std::span(*itemBonusEntries);

    return {};
}

uint32 GetItemBonusListForItemLevelDelta(int16 delta)
{
    if (uint32 const* itemBonusListId = Trinity::Containers::MapGetValuePtr(_itemLevelDeltaToBonusListContainer, delta))
        return *itemBonusListId;

    return 0;
}

bool CanApplyBonusTreeToItem(ItemTemplate const* itemTemplate, uint32 itemBonusTreeId, ItemBonusGenerationParams const& params)
{
    return false;
}

uint32 GetBonusTreeIdOverride(uint32 itemBonusTreeId, ItemBonusGenerationParams const& params)
{
    return itemBonusTreeId;
}

void ApplyBonusTreeHelper(ItemTemplate const* itemTemplate, uint32 itemBonusTreeId, ItemBonusGenerationParams const& params, int32 sequenceLevel, uint32* itemLevelSelectorId, std::vector<int32>* bonusListIDs)
{
}

int32 GetAzeriteUnlockBonusList(uint16 azeriteUnlockMappingSetId, uint16 minItemLevel, InventoryType inventoryType)
{
    return 0;
}

std::vector<int32> GetBonusListsForItem(uint32 itemId, ItemBonusGenerationParams const& params)
{
    std::vector<int32> bonusListIDs;

    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
    if (!itemTemplate)
        return bonusListIDs;

    uint32 itemLevelSelectorId = 0;

    for (auto [_, itemBonusTreeId] : Trinity::Containers::MapEqualRange(_itemToBonusTree, itemId))
        ApplyBonusTreeHelper(itemTemplate, itemBonusTreeId, params, 0, &itemLevelSelectorId, &bonusListIDs);

    if (ItemLevelSelectorEntry const* selector = sItemLevelSelectorStore.LookupEntry(itemLevelSelectorId))
    {
        int16 delta = int16(selector->MinItemLevel) - int16(itemTemplate->GetBaseItemLevel());

        if (uint32 bonus = GetItemBonusListForItemLevelDelta(delta))
            bonusListIDs.push_back(bonus);

        if (ItemLevelSelectorQualitySetEntry const* selectorQualitySet = sItemLevelSelectorQualitySetStore.LookupEntry(selector->ItemLevelSelectorQualitySetID))
        {
            auto itemSelectorQualities = _itemLevelQualitySelectorQualities.find(selector->ItemLevelSelectorQualitySetID);
            if (itemSelectorQualities != _itemLevelQualitySelectorQualities.end())
            {
                ItemQualities quality = ITEM_QUALITY_UNCOMMON;
                if (selector->MinItemLevel >= selectorQualitySet->IlvlEpic)
                    quality = ITEM_QUALITY_EPIC;
                else if (selector->MinItemLevel >= selectorQualitySet->IlvlRare)
                    quality = ITEM_QUALITY_RARE;

                auto itemSelectorQuality = std::lower_bound(itemSelectorQualities->second.begin(), itemSelectorQualities->second.end(),
                    quality, ItemLevelSelectorQualityEntryComparator{});

                if (itemSelectorQuality != itemSelectorQualities->second.end())
                    bonusListIDs.push_back((*itemSelectorQuality)->QualityItemBonusListID);
            }
        }
    }

    return bonusListIDs;
}

template<typename Visitor>
void VisitItemBonusTree(uint32 itemBonusTreeId, Visitor visitor)
{
    auto treeItr = _itemBonusTrees.find(itemBonusTreeId);
    if (treeItr == _itemBonusTrees.end())
        return;

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : treeItr->second)
    {
        visitor(bonusTreeNode);
        if (bonusTreeNode->ChildItemBonusTreeID)
            VisitItemBonusTree(bonusTreeNode->ChildItemBonusTreeID, visitor);
    }
}

std::vector<int32> GetAllBonusListsForTree(uint32 itemBonusTreeId)
{
    std::vector<int32> bonusListIDs;
    VisitItemBonusTree(itemBonusTreeId, [&bonusListIDs](ItemBonusTreeNodeEntry const* bonusTreeNode)
    {
        if (bonusTreeNode->ChildItemBonusListID)
            bonusListIDs.push_back(bonusTreeNode->ChildItemBonusListID);
    });
    return bonusListIDs;
}
}
