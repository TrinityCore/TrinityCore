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

std::unordered_multimap<int32 /*azeriteUnlockMappingSetId*/, AzeriteUnlockMappingEntry const*> _azeriteUnlockMappings;
std::unordered_multimap<uint32 /*itemBonusTreeId*/, ChallengeModeItemBonusOverrideEntry const*> _challengeModeItemBonusOverrides;
std::unordered_map<uint32 /*itemBonusListId*/, std::vector<ItemBonusEntry const*>> _itemBonusLists;
std::unordered_multimap<int32, ItemBonusListGroupEntryEntry const*> _itemBonusListGroupEntries;
std::unordered_map<int16 /*itemLevelDelta*/, uint32 /*itemBonusListId*/> _itemLevelDeltaToBonusListContainer;
std::unordered_map<uint32 /*itemLevelSelectorQualitySetId*/, ItemLevelSelectorQualities> _itemLevelQualitySelectorQualities;
std::unordered_map<uint32 /*itemBonusTreeId*/, std::set<ItemBonusTreeNodeEntry const*>> _itemBonusTrees;
std::unordered_multimap<uint32 /*itemId*/, uint32 /*itemBonusTreeId*/> _itemToBonusTree;
}

namespace ItemBonusMgr
{
void Load()
{
    for (AzeriteUnlockMappingEntry const* azeriteUnlockMapping : sAzeriteUnlockMappingStore)
        _azeriteUnlockMappings.emplace(azeriteUnlockMapping->AzeriteUnlockMappingSetID, azeriteUnlockMapping);

    for (ChallengeModeItemBonusOverrideEntry const* challengeModeItemBonusOverride : sChallengeModeItemBonusOverrideStore)
        _challengeModeItemBonusOverrides.emplace(challengeModeItemBonusOverride->SrcItemBonusTreeID, challengeModeItemBonusOverride);

    for (ItemBonusEntry const* bonus : sItemBonusStore)
        _itemBonusLists[bonus->ParentItemBonusListID].push_back(bonus);

    for (ItemBonusListGroupEntryEntry const* bonusListGroupEntry : sItemBonusListGroupEntryStore)
        _itemBonusListGroupEntries.emplace(bonusListGroupEntry->ItemBonusListGroupID, bonusListGroupEntry);

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
        uint32 contentTuningId = sDB2Manager.GetRedirectedContentTuningId(mapDifficulty->ContentTuningID, player->m_playerData->CtrOptions->ContentTuningConditionMask);

        ItemContextPickerEntryEntry const* selectedPickerEntry = nullptr;
        for (ItemContextPickerEntryEntry const* itemContextPickerEntry : sItemContextPickerEntryStore)
        {
            if (itemContextPickerEntry->ItemContextPickerID != uint32(mapDifficulty->ItemContextPickerID))
                continue;

            if (itemContextPickerEntry->PVal <= 0)
                continue;

            bool meetsPlayerCondition = false;
            if (player)
                meetsPlayerCondition = ConditionMgr::IsPlayerMeetingCondition(player, itemContextPickerEntry->PlayerConditionID);

            if (itemContextPickerEntry->Flags & 0x1)
                meetsPlayerCondition = !meetsPlayerCondition;

            if (!meetsPlayerCondition)
                continue;

            if (itemContextPickerEntry->LabelID && !sDB2Manager.HasContentTuningLabel(contentTuningId, itemContextPickerEntry->LabelID))
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
    if (ItemBonusTreeEntry const* bonusTree = sItemBonusTreeStore.LookupEntry(itemBonusTreeId))
    {
        if (bonusTree->InventoryTypeSlotMask)
            if (!(1 << itemTemplate->GetInventoryType() & bonusTree->InventoryTypeSlotMask))
                return false;

        if (bonusTree->Flags & 0x8 && !itemTemplate->HasFlag(ITEM_FLAG2_CASTER_WEAPON))
            return false;
        if (bonusTree->Flags & 0x10 && itemTemplate->HasFlag(ITEM_FLAG2_CASTER_WEAPON))
            return false;
        if (bonusTree->Flags & 0x20 && !itemTemplate->HasFlag(ITEM_FLAG4_CC_TRINKET))
            return false;
        if (bonusTree->Flags & 0x40 && itemTemplate->HasFlag(ITEM_FLAG4_CC_TRINKET))
            return false;

        if (bonusTree->Flags & 0x4)
            return true;
    }

    if (std::set<ItemBonusTreeNodeEntry const*>* bonusTreeNodes = Trinity::Containers::MapGetValuePtr(_itemBonusTrees, itemBonusTreeId))
    {
        bool anyNodeMatched = false;
        for (ItemBonusTreeNodeEntry const* bonusTreeNode : *bonusTreeNodes)
        {
            if (bonusTreeNode->MinMythicPlusLevel > 0)
                continue;

            ItemContext nodeContext = ItemContext(bonusTreeNode->ItemContext);
            if (nodeContext == ItemContext::NONE || nodeContext == params.Context)
            {
                if (anyNodeMatched)
                    return false;

                anyNodeMatched = true;
            }
        }
    }

    return true;
}

uint32 GetBonusTreeIdOverride(uint32 itemBonusTreeId, ItemBonusGenerationParams const& params)
{
    // TODO: configure seasons globally
    if (MythicPlusSeasonEntry const* mythicPlusSeason = sMythicPlusSeasonStore.LookupEntry(0))
    {
        int32 selectedLevel = -1;
        int32 selectedMilestoneSeason = -1;
        ChallengeModeItemBonusOverrideEntry const* selectedItemBonusOverride = nullptr;
        for (auto& [_, itemBonusOverride] : Trinity::Containers::MapEqualRange(_challengeModeItemBonusOverrides, itemBonusTreeId))
        {
            if (itemBonusOverride->Type != 0)
                continue;

            if (itemBonusOverride->Value > params.MythicPlusKeystoneLevel.value_or(-1))
                continue;

            if (itemBonusOverride->MythicPlusSeasonID)
            {
                MythicPlusSeasonEntry const* overrideSeason = sMythicPlusSeasonStore.LookupEntry(itemBonusOverride->MythicPlusSeasonID);
                if (!overrideSeason)
                    continue;

                if (mythicPlusSeason->MilestoneSeason < overrideSeason->MilestoneSeason)
                    continue;

                if (selectedMilestoneSeason > overrideSeason->MilestoneSeason)
                    continue;

                if (selectedMilestoneSeason == overrideSeason->MilestoneSeason)
                    if (selectedLevel > itemBonusOverride->Value)
                        continue;

                selectedMilestoneSeason = overrideSeason->MilestoneSeason;
            }
            else if (selectedLevel > itemBonusOverride->Value)
                continue;

            selectedLevel = itemBonusOverride->Value;
            selectedItemBonusOverride = itemBonusOverride;
        }

        if (selectedItemBonusOverride && selectedItemBonusOverride->DstItemBonusTreeID)
            itemBonusTreeId = selectedItemBonusOverride->DstItemBonusTreeID;
    }

    // TODO: configure seasons globally
    if (PvpSeasonEntry const* pvpSeason = sPvpSeasonStore.LookupEntry(0))
    {
        int32 selectedLevel = -1;
        int32 selectedMilestoneSeason = -1;
        ChallengeModeItemBonusOverrideEntry const* selectedItemBonusOverride = nullptr;
        for (auto& [_, itemBonusOverride] : Trinity::Containers::MapEqualRange(_challengeModeItemBonusOverrides, itemBonusTreeId))
        {
            if (itemBonusOverride->Type != 1)
                continue;

            if (itemBonusOverride->Value > params.PvpTier.value_or(-1))
                continue;

            if (itemBonusOverride->PvPSeasonID)
            {
                PvpSeasonEntry const* overrideSeason = sPvpSeasonStore.LookupEntry(itemBonusOverride->PvPSeasonID);
                if (!overrideSeason)
                    continue;

                if (pvpSeason->MilestoneSeason < overrideSeason->MilestoneSeason)
                    continue;

                if (selectedMilestoneSeason > overrideSeason->MilestoneSeason)
                    continue;

                if (selectedMilestoneSeason == overrideSeason->MilestoneSeason)
                    if (selectedLevel > itemBonusOverride->Value)
                        continue;

                selectedMilestoneSeason = overrideSeason->MilestoneSeason;
            }
            else if (selectedLevel > itemBonusOverride->Value)
                continue;

            selectedLevel = itemBonusOverride->Value;
            selectedItemBonusOverride = itemBonusOverride;
        }

        if (selectedItemBonusOverride && selectedItemBonusOverride->DstItemBonusTreeID)
            itemBonusTreeId = selectedItemBonusOverride->DstItemBonusTreeID;
    }

    return itemBonusTreeId;
}

void ApplyBonusTreeHelper(ItemTemplate const* itemTemplate, uint32 itemBonusTreeId, ItemBonusGenerationParams const& params, int32 sequenceLevel, uint32* itemLevelSelectorId, std::vector<int32>* bonusListIDs)
{
    uint32 originalItemBonusTreeId = itemBonusTreeId;

    // override bonus tree with season specific values
    itemBonusTreeId = GetBonusTreeIdOverride(itemBonusTreeId, params);

    if (!CanApplyBonusTreeToItem(itemTemplate, itemBonusTreeId, params))
        return;

    auto treeItr = _itemBonusTrees.find(itemBonusTreeId);
    if (treeItr == _itemBonusTrees.end())
        return;

    for (ItemBonusTreeNodeEntry const* bonusTreeNode : treeItr->second)
    {
        ItemContext nodeContext = ItemContext(bonusTreeNode->ItemContext);
        ItemContext requiredContext = nodeContext != ItemContext::Force_to_NONE ? nodeContext : ItemContext::NONE;
        if (nodeContext != ItemContext::NONE && params.Context != requiredContext)
            continue;

        if (params.MythicPlusKeystoneLevel)
        {
            if (bonusTreeNode->MinMythicPlusLevel && params.MythicPlusKeystoneLevel < bonusTreeNode->MinMythicPlusLevel)
                continue;

            if (bonusTreeNode->MaxMythicPlusLevel && params.MythicPlusKeystoneLevel > bonusTreeNode->MaxMythicPlusLevel)
                continue;
        }

        if (bonusTreeNode->ChildItemBonusTreeID)
            ApplyBonusTreeHelper(itemTemplate, bonusTreeNode->ChildItemBonusTreeID, params, sequenceLevel, itemLevelSelectorId, bonusListIDs);
        else if (bonusTreeNode->ChildItemBonusListID)
            bonusListIDs->push_back(bonusTreeNode->ChildItemBonusListID);
        else if (bonusTreeNode->ChildItemLevelSelectorID)
            *itemLevelSelectorId = bonusTreeNode->ChildItemLevelSelectorID;
        else if (bonusTreeNode->ChildItemBonusListGroupID)
        {
            int32 resolvedSequenceLevel = sequenceLevel;
            switch (originalItemBonusTreeId)
            {
                case 4001:
                    resolvedSequenceLevel = 1;
                    break;
                case 4079:
                    if (params.MythicPlusKeystoneLevel)
                    {
                        switch (bonusTreeNode->IblGroupPointsModSetID)
                        {
                            case 2909: // MythicPlus_End_of_Run levels 2-8
                                resolvedSequenceLevel = sDB2Manager.GetCurveValueAt(62951, *params.MythicPlusKeystoneLevel);
                                break;
                            case 2910: // MythicPlus_End_of_Run levels 9-16
                                resolvedSequenceLevel = sDB2Manager.GetCurveValueAt(62952, *params.MythicPlusKeystoneLevel);
                                break;
                            case 2911: // MythicPlus_End_of_Run levels 17-20
                                resolvedSequenceLevel = sDB2Manager.GetCurveValueAt(62954, *params.MythicPlusKeystoneLevel);
                                break;
                            case 3007: // MythicPlus_Jackpot (weekly reward) levels 2-7
                                resolvedSequenceLevel = sDB2Manager.GetCurveValueAt(64388, *params.MythicPlusKeystoneLevel);
                                break;
                            case 3008: // MythicPlus_Jackpot (weekly reward) levels 8-15
                                resolvedSequenceLevel = sDB2Manager.GetCurveValueAt(64389, *params.MythicPlusKeystoneLevel);
                                break;
                            case 3009: // MythicPlus_Jackpot (weekly reward) levels 16-20
                                resolvedSequenceLevel = sDB2Manager.GetCurveValueAt(64395, *params.MythicPlusKeystoneLevel);
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 4125:
                    resolvedSequenceLevel = 2;
                    break;
                case 4126:
                    resolvedSequenceLevel = 3;
                    break;
                case 4127:
                    resolvedSequenceLevel = 4;
                    break;
                case 4128:
                    switch (params.Context)
                    {
                        case ItemContext::Raid_Normal:
                        case ItemContext::Raid_Raid_Finder:
                        case ItemContext::Raid_Heroic:
                            resolvedSequenceLevel = 2;
                            break;
                        case ItemContext::Raid_Mythic:
                            resolvedSequenceLevel = 6;
                            break;
                        default:
                            break;
                    }
                    break;
                case 4140:
                    switch (params.Context)
                    {
                        case ItemContext::Dungeon_Normal:
                            resolvedSequenceLevel = 2;
                            break;
                        case ItemContext::Dungeon_Mythic:
                            resolvedSequenceLevel = 4;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

            for (auto const& [_, bonusListGroupEntry] : Trinity::Containers::MapEqualRange(_itemBonusListGroupEntries, bonusTreeNode->ChildItemBonusListGroupID))
            {
                if ((resolvedSequenceLevel > 0 || bonusListGroupEntry->SequenceValue <= 0) && resolvedSequenceLevel != bonusListGroupEntry->SequenceValue)
                    continue;

                *itemLevelSelectorId = bonusListGroupEntry->ItemLevelSelectorID;
                bonusListIDs->push_back(bonusListGroupEntry->ItemBonusListID);
                break;
            }
        }
    }
}

int32 GetAzeriteUnlockBonusList(uint16 azeriteUnlockMappingSetId, uint16 minItemLevel, InventoryType inventoryType)
{
    AzeriteUnlockMappingEntry const* selectedAzeriteUnlockMapping = nullptr;
    for (auto [_, azeriteUnlockMapping] : Trinity::Containers::MapEqualRange(_azeriteUnlockMappings, azeriteUnlockMappingSetId))
    {
        if (minItemLevel < azeriteUnlockMapping->ItemLevel)
            continue;

        if (selectedAzeriteUnlockMapping && selectedAzeriteUnlockMapping->ItemLevel > azeriteUnlockMapping->ItemLevel)
            continue;

        selectedAzeriteUnlockMapping = azeriteUnlockMapping;
    }

    if (selectedAzeriteUnlockMapping)
    {
        switch (inventoryType)
        {
            case INVTYPE_HEAD:
                return selectedAzeriteUnlockMapping->ItemBonusListHead;
            case INVTYPE_SHOULDERS:
                return selectedAzeriteUnlockMapping->ItemBonusListShoulders;
            case INVTYPE_CHEST:
            case INVTYPE_ROBE:
                return selectedAzeriteUnlockMapping->ItemBonusListChest;
            default:
                break;
        }
    }

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

        if (int32 azeriteUnlockBonusListId = GetAzeriteUnlockBonusList(selector->AzeriteUnlockMappingSet, selector->MinItemLevel, itemTemplate->GetInventoryType()))
            bonusListIDs.push_back(azeriteUnlockBonusListId);
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
