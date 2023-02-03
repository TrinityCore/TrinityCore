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

#include "TraitMgr.h"
#include "DB2Stores.h"
#include "IteratorPair.h"
#include "MapUtils.h"
#include "TraitPacketsCommon.h"
#include "UpdateFields.h"

namespace TraitMgr
{
namespace
{
struct NodeEntry;
struct Node;
struct NodeGroup;
struct Tree;

struct NodeEntry
{
    TraitNodeEntryEntry const* Data = nullptr;
    std::vector<TraitCondEntry const*> Conditions;
    std::vector<TraitCostEntry const*> Costs;
};

struct Node
{
    TraitNodeEntry const* Data = nullptr;
    std::vector<NodeEntry> Entries;
    std::vector<NodeGroup const*> Groups;
    std::vector<std::pair<Node const*, TraitEdgeType>> ParentNodes; // TraitEdge::LeftTraitNodeID
    std::vector<TraitCondEntry const*> Conditions;
    std::vector<TraitCostEntry const*> Costs;
};

struct NodeGroup
{
    TraitNodeGroupEntry const* Data = nullptr;
    std::vector<TraitCondEntry const*> Conditions;
    std::vector<TraitCostEntry const*> Costs;
    std::vector<Node const*> Nodes;
};

struct Tree
{
    TraitTreeEntry const* Data = nullptr;
    std::vector<Node const*> Nodes;
    std::vector<TraitCostEntry const*> Costs;
    std::vector<TraitCurrencyEntry const*> Currencies;
    TraitConfigType ConfigType = TraitConfigType::Invalid;
};

std::unordered_map<int32, NodeGroup> _traitGroups;
std::unordered_map<int32, Node> _traitNodes;
std::unordered_map<int32, Tree> _traitTrees;
std::array<int32, MAX_CLASSES> _skillLinesByClass;
std::unordered_map<int32, std::vector<Tree const*>> _traitTreesBySkillLine;
std::unordered_map<int32, std::vector<Tree const*>> _traitTreesByTraitSystem;
int32 _configIdGenerator = 0;
std::unordered_map<int32, std::vector<TraitCurrencySourceEntry const*>> _traitCurrencySourcesByCurrency;
std::unordered_map<int32, std::vector<TraitDefinitionEffectPointsEntry const*>> _traitDefinitionEffectPointModifiers;
std::unordered_map<int32, std::vector<TraitTreeLoadoutEntryEntry const*>> _traitTreeLoadoutsByChrSpecialization;
}

void Load()
{
    _configIdGenerator = time(nullptr);

    std::unordered_map<int32, std::vector<TraitCondEntry const*>> nodeEntryConditions;
    for (TraitNodeEntryXTraitCondEntry const* traitNodeEntryXTraitCondEntry : sTraitNodeEntryXTraitCondStore)
        if (TraitCondEntry const* traitCondEntry = sTraitCondStore.LookupEntry(traitNodeEntryXTraitCondEntry->TraitCondID))
            nodeEntryConditions[traitNodeEntryXTraitCondEntry->TraitNodeEntryID].push_back(traitCondEntry);

    std::unordered_map<int32, std::vector<TraitCostEntry const*>> nodeEntryCosts;
    for (TraitNodeEntryXTraitCostEntry const* traitNodeEntryXTraitCostEntry : sTraitNodeEntryXTraitCostStore)
        if (TraitCostEntry const* traitCostEntry = sTraitCostStore.LookupEntry(traitNodeEntryXTraitCostEntry->TraitCostID))
            nodeEntryCosts[traitNodeEntryXTraitCostEntry->TraitNodeEntryID].push_back(traitCostEntry);

    std::unordered_map<int32, std::vector<TraitCondEntry const*>> nodeGroupConditions;
    for (TraitNodeGroupXTraitCondEntry const* traitNodeGroupXTraitCondEntry : sTraitNodeGroupXTraitCondStore)
        if (TraitCondEntry const* traitCondEntry = sTraitCondStore.LookupEntry(traitNodeGroupXTraitCondEntry->TraitCondID))
            nodeGroupConditions[traitNodeGroupXTraitCondEntry->TraitNodeGroupID].push_back(traitCondEntry);

    std::unordered_map<int32, std::vector<TraitCostEntry const*>> nodeGroupCosts;
    for (TraitNodeGroupXTraitCostEntry const* traitNodeGroupXTraitCostEntry : sTraitNodeGroupXTraitCostStore)
        if (TraitCostEntry const* traitCondEntry = sTraitCostStore.LookupEntry(traitNodeGroupXTraitCostEntry->TraitCostID))
            nodeGroupCosts[traitNodeGroupXTraitCostEntry->TraitNodeGroupID].push_back(traitCondEntry);

    std::unordered_multimap<int32, int32> nodeGroups;
    for (TraitNodeGroupXTraitNodeEntry const* traitNodeGroupXTraitNodeEntry : sTraitNodeGroupXTraitNodeStore)
            nodeGroups.emplace(traitNodeGroupXTraitNodeEntry->TraitNodeID, traitNodeGroupXTraitNodeEntry->TraitNodeGroupID);

    std::unordered_map<int32, std::vector<TraitCondEntry const*>> nodeConditions;
    for (TraitNodeXTraitCondEntry const* traitNodeXTraitCondEntry : sTraitNodeXTraitCondStore)
        if (TraitCondEntry const* traitCondEntry = sTraitCondStore.LookupEntry(traitNodeXTraitCondEntry->TraitCondID))
            nodeConditions[traitNodeXTraitCondEntry->TraitNodeID].push_back(traitCondEntry);

    std::unordered_map<int32, std::vector<TraitCostEntry const*>> nodeCosts;
    for (TraitNodeXTraitCostEntry const* traitNodeXTraitCostEntry : sTraitNodeXTraitCostStore)
        if (TraitCostEntry const* traitCostEntry = sTraitCostStore.LookupEntry(traitNodeXTraitCostEntry->TraitCostID))
            nodeCosts[traitNodeXTraitCostEntry->TraitNodeID].push_back(traitCostEntry);

    std::unordered_multimap<int32, TraitNodeEntryEntry const*> nodeEntries;
    for (TraitNodeXTraitNodeEntryEntry const* traitNodeXTraitNodeEntryEntry : sTraitNodeXTraitNodeEntryStore)
        if (TraitNodeEntryEntry const* traitNodeEntryEntry = sTraitNodeEntryStore.LookupEntry(traitNodeXTraitNodeEntryEntry->TraitNodeEntryID))
            nodeEntries.emplace(traitNodeXTraitNodeEntryEntry->TraitNodeID, traitNodeEntryEntry);

    std::unordered_map<int32, std::vector<TraitCostEntry const*>> treeCosts;
    for (TraitTreeXTraitCostEntry const* traitTreeXTraitCostEntry : sTraitTreeXTraitCostStore)
        if (TraitCostEntry const* traitCostEntry = sTraitCostStore.LookupEntry(traitTreeXTraitCostEntry->TraitCostID))
            treeCosts[traitTreeXTraitCostEntry->TraitTreeID].push_back(traitCostEntry);

    std::unordered_map<int32, std::vector<TraitCurrencyEntry const*>> treeCurrencies;
    for (TraitTreeXTraitCurrencyEntry const* traitTreeXTraitCurrencyEntry : sTraitTreeXTraitCurrencyStore)
        if (TraitCurrencyEntry const* traitCurrencyEntry = sTraitCurrencyStore.LookupEntry(traitTreeXTraitCurrencyEntry->TraitCurrencyID))
            treeCurrencies[traitTreeXTraitCurrencyEntry->TraitTreeID].push_back(traitCurrencyEntry);

    std::unordered_map<int32, std::vector<int32>> traitTreesIdsByTraitSystem;

    for (TraitTreeEntry const* traitTree : sTraitTreeStore)
    {
        Tree& tree = _traitTrees[traitTree->ID];
        tree.Data = traitTree;

        if (std::vector<TraitCostEntry const*>* costs = Trinity::Containers::MapGetValuePtr(treeCosts, traitTree->ID))
            tree.Costs = std::move(*costs);

        if (std::vector<TraitCurrencyEntry const*>* currencies = Trinity::Containers::MapGetValuePtr(treeCurrencies, traitTree->ID))
            tree.Currencies = std::move(*currencies);

        if (traitTree->TraitSystemID)
        {
            traitTreesIdsByTraitSystem[traitTree->TraitSystemID].push_back(traitTree->ID);
            tree.ConfigType = TraitConfigType::Generic;
        }
    }

    for (TraitNodeGroupEntry const* traitNodeGroup : sTraitNodeGroupStore)
    {
        NodeGroup& nodeGroup = _traitGroups[traitNodeGroup->ID];
        nodeGroup.Data = traitNodeGroup;

        if (std::vector<TraitCondEntry const*>* conditions = Trinity::Containers::MapGetValuePtr(nodeGroupConditions, traitNodeGroup->ID))
            nodeGroup.Conditions = std::move(*conditions);

        if (std::vector<TraitCostEntry const*>* costs = Trinity::Containers::MapGetValuePtr(nodeGroupCosts, traitNodeGroup->ID))
            nodeGroup.Costs = std::move(*costs);
    }

    for (TraitNodeEntry const* traitNode : sTraitNodeStore)
    {
        Node& node = _traitNodes[traitNode->ID];
        node.Data = traitNode;

        if (Tree* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, traitNode->TraitTreeID))
            tree->Nodes.push_back(&node);

        for (auto&& [_, traitNodeEntry] : Trinity::Containers::MapEqualRange(nodeEntries, traitNode->ID))
        {
            NodeEntry& entry = node.Entries.emplace_back();
            entry.Data = traitNodeEntry;

            if (std::vector<TraitCondEntry const*>* conditions = Trinity::Containers::MapGetValuePtr(nodeEntryConditions, traitNodeEntry->ID))
                entry.Conditions = std::move(*conditions);

            if (std::vector<TraitCostEntry const*>* costs = Trinity::Containers::MapGetValuePtr(nodeEntryCosts, traitNodeEntry->ID))
                entry.Costs = std::move(*costs);
        }

        for (auto&& [_, nodeGroupId] : Trinity::Containers::MapEqualRange(nodeGroups, traitNode->ID))
        {
            NodeGroup* nodeGroup = Trinity::Containers::MapGetValuePtr(_traitGroups, nodeGroupId);
            if (!nodeGroup)
                continue;

            nodeGroup->Nodes.push_back(&node);
            node.Groups.push_back(nodeGroup);
        }

        if (std::vector<TraitCondEntry const*>* conditions = Trinity::Containers::MapGetValuePtr(nodeConditions, traitNode->ID))
            node.Conditions = std::move(*conditions);

        if (std::vector<TraitCostEntry const*>* costs = Trinity::Containers::MapGetValuePtr(nodeCosts, traitNode->ID))
            node.Costs = std::move(*costs);
    }

    for (TraitEdgeEntry const* traitEdgeEntry : sTraitEdgeStore)
    {
        Node* left = Trinity::Containers::MapGetValuePtr(_traitNodes, traitEdgeEntry->LeftTraitNodeID);
        Node* right = Trinity::Containers::MapGetValuePtr(_traitNodes, traitEdgeEntry->RightTraitNodeID);
        if (!left || !right)
            continue;

        right->ParentNodes.emplace_back(left, static_cast<TraitEdgeType>(traitEdgeEntry->Type));
    }

    for (SkillLineXTraitTreeEntry const* skillLineXTraitTreeEntry : sSkillLineXTraitTreeStore)
    {
        Tree* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, skillLineXTraitTreeEntry->TraitTreeID);
        if (!tree)
            continue;

        SkillLineEntry const* skillLineEntry = sSkillLineStore.LookupEntry(skillLineXTraitTreeEntry->SkillLineID);
        if (!skillLineEntry)
            continue;

        _traitTreesBySkillLine[skillLineXTraitTreeEntry->SkillLineID].push_back(tree);
        if (skillLineEntry->CategoryID == SKILL_CATEGORY_CLASS)
        {
            for (SkillRaceClassInfoEntry const* skillRaceClassInfo : sDB2Manager.GetSkillRaceClassInfo(skillLineEntry->ID))
                for (int32 i = 1; i < MAX_CLASSES; ++i)
                    if (skillRaceClassInfo->ClassMask & (1 << (i - 1)))
                        _skillLinesByClass[i] = skillLineXTraitTreeEntry->SkillLineID;

            tree->ConfigType = TraitConfigType::Combat;
        }
        else
            tree->ConfigType = TraitConfigType::Profession;
    }

    for (auto&& [traitSystemId, traitTreeIds] : traitTreesIdsByTraitSystem)
        for (int32 traitTreeId : traitTreeIds)
            if (Tree* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, traitTreeId))
                _traitTreesByTraitSystem[traitSystemId].push_back(tree);

    for (TraitCurrencySourceEntry const* traitCurrencySource : sTraitCurrencySourceStore)
        _traitCurrencySourcesByCurrency[traitCurrencySource->TraitCurrencyID].push_back(traitCurrencySource);

    for (TraitDefinitionEffectPointsEntry const* traitDefinitionEffectPoints : sTraitDefinitionEffectPointsStore)
        _traitDefinitionEffectPointModifiers[traitDefinitionEffectPoints->TraitDefinitionID].push_back(traitDefinitionEffectPoints);

    std::unordered_map<int32, std::vector<TraitTreeLoadoutEntryEntry const*>> traitTreeLoadoutEntries;
    for (TraitTreeLoadoutEntryEntry const* traitTreeLoadoutEntry : sTraitTreeLoadoutEntryStore)
        traitTreeLoadoutEntries[traitTreeLoadoutEntry->TraitTreeLoadoutID].push_back(traitTreeLoadoutEntry);

    for (TraitTreeLoadoutEntry const* traitTreeLoadout : sTraitTreeLoadoutStore)
    {
        if (std::vector<TraitTreeLoadoutEntryEntry const*>* entries = Trinity::Containers::MapGetValuePtr(traitTreeLoadoutEntries, traitTreeLoadout->ID))
        {
            std::sort(entries->begin(), entries->end(), [](TraitTreeLoadoutEntryEntry const* left, TraitTreeLoadoutEntryEntry const* right)
            {
                return left->OrderIndex < right->OrderIndex;
            });
            // there should be only one loadout per spec, we take last one encountered
            _traitTreeLoadoutsByChrSpecialization[traitTreeLoadout->ChrSpecializationID] = std::move(*entries);
        }
    }
}

/**
 * Generates new TraitConfig identifier.
 * Because this only needs to be unique for each character we let it overflow
*/
int32 GenerateNewTraitConfigId()
{
    if (_configIdGenerator == std::numeric_limits<int32>::max())
        _configIdGenerator = 0;

    return ++_configIdGenerator;
}

TraitConfigType GetConfigTypeForTree(int32 traitTreeId)
{
    Tree const* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, traitTreeId);
    if (!tree)
        return TraitConfigType::Invalid;

    return tree->ConfigType;
}

/**
 * @brief Finds relevant TraitTree identifiers
 * @param traitConfig config data
 * @return Trait tree data
*/
std::vector<Tree const*> const* GetTreesForConfig(WorldPackets::Traits::TraitConfig const& traitConfig)
{
    switch (traitConfig.Type)
    {
        case TraitConfigType::Combat:
            if (ChrSpecializationEntry const* chrSpecializationEntry = sChrSpecializationStore.LookupEntry(traitConfig.ChrSpecializationID))
                return Trinity::Containers::MapGetValuePtr(_traitTreesBySkillLine, _skillLinesByClass[chrSpecializationEntry->ClassID]);
            break;
        case TraitConfigType::Profession:
            return Trinity::Containers::MapGetValuePtr(_traitTreesBySkillLine, traitConfig.SkillLineID);
        case TraitConfigType::Generic:
            return Trinity::Containers::MapGetValuePtr(_traitTreesByTraitSystem, traitConfig.TraitSystemID);
        default:
            break;
    }

    return nullptr;
}

bool HasEnoughCurrency(WorldPackets::Traits::TraitEntry const& entry, std::map<int32, int32> const& currencies)
{
    auto getCurrencyCount = [&](int32 currencyId)
    {
        int32 const* count = Trinity::Containers::MapGetValuePtr(currencies, currencyId);
        return count ? *count : 0;
    };

    Node const* node = Trinity::Containers::MapGetValuePtr(_traitNodes, entry.TraitNodeID);
    for (NodeGroup const* group : node->Groups)
        for (TraitCostEntry const* cost : group->Costs)
            if (getCurrencyCount(cost->TraitCurrencyID) < cost->Amount * entry.Rank)
                return false;

    auto nodeEntryItr = std::find_if(node->Entries.begin(), node->Entries.end(), [&entry](NodeEntry const& nodeEntry) { return int32(nodeEntry.Data->ID) == entry.TraitNodeEntryID; });
    if (nodeEntryItr != node->Entries.end())
        for (TraitCostEntry const* cost : nodeEntryItr->Costs)
            if (getCurrencyCount(cost->TraitCurrencyID) < cost->Amount * entry.Rank)
                return false;

    for (TraitCostEntry const* cost : node->Costs)
        if (getCurrencyCount(cost->TraitCurrencyID) < cost->Amount * entry.Rank)
            return false;

    if (Tree const* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, node->Data->TraitTreeID))
        for (TraitCostEntry const* cost : tree->Costs)
            if (getCurrencyCount(cost->TraitCurrencyID) < cost->Amount * entry.Rank)
                return false;

    return true;
}

void TakeCurrencyCost(WorldPackets::Traits::TraitEntry const& entry, std::map<int32, int32>& currencies)
{
    Node const* node = Trinity::Containers::MapGetValuePtr(_traitNodes, entry.TraitNodeID);
    for (NodeGroup const* group : node->Groups)
        for (TraitCostEntry const* cost : group->Costs)
            currencies[cost->TraitCurrencyID] -= cost->Amount * entry.Rank;

    auto nodeEntryItr = std::find_if(node->Entries.begin(), node->Entries.end(), [&entry](NodeEntry const& nodeEntry) { return int32(nodeEntry.Data->ID) == entry.TraitNodeEntryID; });
    if (nodeEntryItr != node->Entries.end())
        for (TraitCostEntry const* cost : nodeEntryItr->Costs)
            currencies[cost->TraitCurrencyID] -= cost->Amount * entry.Rank;

    for (TraitCostEntry const* cost : node->Costs)
        currencies[cost->TraitCurrencyID] -= cost->Amount * entry.Rank;

    if (Tree const* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, node->Data->TraitTreeID))
        for (TraitCostEntry const* cost : tree->Costs)
            currencies[cost->TraitCurrencyID] -= cost->Amount * entry.Rank;
}

void FillOwnedCurrenciesMap(WorldPackets::Traits::TraitConfig const& traitConfig, PlayerDataAccessor player, std::map<int32, int32>& currencies)
{
    std::vector<Tree const*> const* trees = GetTreesForConfig(traitConfig);
    if (!trees)
        return;

    auto hasTraitNodeEntry = [&traitConfig](int32 traitNodeEntryId)
    {
        return std::find_if(traitConfig.Entries.begin(), traitConfig.Entries.end(), [traitNodeEntryId](WorldPackets::Traits::TraitEntry const& traitEntry)
        {
            return traitEntry.TraitNodeEntryID == traitNodeEntryId && (traitEntry.Rank > 0 || traitEntry.GrantedRanks > 0);
        }) != traitConfig.Entries.end();
    };

    for (Tree const* tree : *trees)
    {
        for (TraitCurrencyEntry const* currency : tree->Currencies)
        {
            switch (currency->GetType())
            {
                case TraitCurrencyType::Gold:
                {
                    int32& amount = currencies[currency->ID];
                    if (player.GetMoney() > uint64(std::numeric_limits<int32>::max() - amount))
                        amount = std::numeric_limits<int32>::max();
                    else
                        amount += player.GetMoney();
                    break;
                }
                case TraitCurrencyType::CurrencyTypesBased:
                    currencies[currency->ID] += player.GetCurrencyQuantity(currency->CurrencyTypesID);
                    break;
                case TraitCurrencyType::TraitSourced:
                    if (std::vector<TraitCurrencySourceEntry const*>* currencySources = Trinity::Containers::MapGetValuePtr(_traitCurrencySourcesByCurrency, currency->ID))
                    {
                        for (TraitCurrencySourceEntry const* currencySource : *currencySources)
                        {
                            if (currencySource->QuestID && !player.IsQuestRewarded(currencySource->QuestID))
                                continue;

                            if (currencySource->AchievementID && !player.HasAchieved(currencySource->AchievementID))
                                continue;

                            if (currencySource->PlayerLevel && player.GetLevel() < currencySource->PlayerLevel)
                                continue;

                            if (currencySource->TraitNodeEntryID && !hasTraitNodeEntry(currencySource->TraitNodeEntryID))
                                continue;

                            currencies[currencySource->TraitCurrencyID] += currencySource->Amount;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

void FillSpentCurrenciesMap(WorldPackets::Traits::TraitEntry const& entry, std::map<int32, int32>& cachedCurrencies)
{
    Node const* node = Trinity::Containers::MapGetValuePtr(_traitNodes, entry.TraitNodeID);
    for (NodeGroup const* group : node->Groups)
        for (TraitCostEntry const* cost : group->Costs)
            cachedCurrencies[cost->TraitCurrencyID] += cost->Amount * entry.Rank;

    auto nodeEntryItr = std::find_if(node->Entries.begin(), node->Entries.end(), [&entry](NodeEntry const& nodeEntry) { return int32(nodeEntry.Data->ID) == entry.TraitNodeEntryID; });
    if (nodeEntryItr != node->Entries.end())
        for (TraitCostEntry const* cost : nodeEntryItr->Costs)
            cachedCurrencies[cost->TraitCurrencyID] += cost->Amount * entry.Rank;

    for (TraitCostEntry const* cost : node->Costs)
        cachedCurrencies[cost->TraitCurrencyID] += cost->Amount * entry.Rank;

    if (Tree const* tree = Trinity::Containers::MapGetValuePtr(_traitTrees, node->Data->TraitTreeID))
        for (TraitCostEntry const* cost : tree->Costs)
            cachedCurrencies[cost->TraitCurrencyID] += cost->Amount * entry.Rank;
}

void FillSpentCurrenciesMap(WorldPackets::Traits::TraitConfig const& traitConfig, std::map<int32, int32>& cachedCurrencies)
{
    for (WorldPackets::Traits::TraitEntry const& entry : traitConfig.Entries)
        FillSpentCurrenciesMap(entry, cachedCurrencies);
}

bool MeetsTraitCondition(WorldPackets::Traits::TraitConfig const& traitConfig, PlayerDataAccessor player, TraitCondEntry const* condition,
    Optional<std::map<int32, int32>>& cachedCurrencies)
{
    if (condition->QuestID && !player.IsQuestRewarded(condition->QuestID))
        return false;

    if (condition->AchievementID && !player.HasAchieved(condition->AchievementID))
        return false;

    if (condition->SpecSetID)
    {
        uint32 chrSpecializationId = player.GetPrimarySpecialization();
        if (traitConfig.Type == TraitConfigType::Combat)
            chrSpecializationId = traitConfig.ChrSpecializationID;

        if (!sDB2Manager.IsSpecSetMember(condition->SpecSetID, chrSpecializationId))
            return false;
    }

    if (condition->TraitCurrencyID && condition->SpentAmountRequired)
    {
        if (!cachedCurrencies)
            FillSpentCurrenciesMap(traitConfig, cachedCurrencies.emplace());

        if (condition->TraitNodeGroupID)
        {
            auto itr = cachedCurrencies->try_emplace(condition->TraitCurrencyID, 0).first;
            if (itr->second < condition->SpentAmountRequired)
                return false;
        }
        else if (condition->TraitNodeID)
        {
            auto itr = cachedCurrencies->try_emplace(condition->TraitCurrencyID, 0).first;
            if (itr->second < condition->SpentAmountRequired)
                return false;
        }
    }

    if (condition->RequiredLevel && player.GetLevel() < condition->RequiredLevel)
        return false;

    return true;
}

std::vector<UF::TraitEntry> GetGrantedTraitEntriesForConfig(WorldPackets::Traits::TraitConfig const& traitConfig, PlayerDataAccessor player)
{
    std::vector<UF::TraitEntry> entries;
    std::vector<Tree const*> const* trees = GetTreesForConfig(traitConfig);
    if (!trees)
        return entries;

    auto getOrCreateEntry = [&entries](int32 nodeId, int32 entryId)
    {
        auto itr = std::find_if(entries.begin(), entries.end(), [&](UF::TraitEntry const& traitEntry)
        {
            return traitEntry.TraitNodeID == nodeId && traitEntry.TraitNodeEntryID == entryId;
        });
        if (itr == entries.end())
        {
            itr = entries.emplace(entries.end());
            itr->TraitNodeID = nodeId;
            itr->TraitNodeEntryID = entryId;
            itr->Rank = 0;
            itr->GrantedRanks = 0;
        }
        return &*itr;
    };

    Optional<std::map<int32, int32>> cachedCurrencies;

    for (Tree const* tree : *trees)
    {
        for (Node const* node : tree->Nodes)
        {
            for (NodeEntry const& entry : node->Entries)
                for (TraitCondEntry const* condition : entry.Conditions)
                    if (condition->GetCondType() == TraitConditionType::Granted && MeetsTraitCondition(traitConfig, player, condition, cachedCurrencies))
                        getOrCreateEntry(node->Data->ID, entry.Data->ID)->GrantedRanks += condition->GrantedRanks;

            for (TraitCondEntry const* condition : node->Conditions)
                if (condition->GetCondType() == TraitConditionType::Granted && MeetsTraitCondition(traitConfig, player, condition, cachedCurrencies))
                    for (NodeEntry const& entry : node->Entries)
                        getOrCreateEntry(node->Data->ID, entry.Data->ID)->GrantedRanks += condition->GrantedRanks;

            for (NodeGroup const* group : node->Groups)
                for (TraitCondEntry const* condition : group->Conditions)
                    if (condition->GetCondType() == TraitConditionType::Granted && MeetsTraitCondition(traitConfig, player, condition, cachedCurrencies))
                        for (NodeEntry const& entry : node->Entries)
                            getOrCreateEntry(node->Data->ID, entry.Data->ID)->GrantedRanks += condition->GrantedRanks;
        }
    }

    return entries;
}

bool IsValidEntry(WorldPackets::Traits::TraitEntry const& traitEntry)
{
    Node const* node = Trinity::Containers::MapGetValuePtr(_traitNodes, traitEntry.TraitNodeID);
    if (!node)
        return false;

    auto entryItr = std::find_if(node->Entries.begin(), node->Entries.end(), [&](NodeEntry const& entry) { return entry.Data->ID == uint32(traitEntry.TraitNodeEntryID); });
    if (entryItr == node->Entries.end())
        return false;

    if (entryItr->Data->MaxRanks < traitEntry.Rank + traitEntry.GrantedRanks)
        return false;

    return true;
}

LearnResult ValidateConfig(WorldPackets::Traits::TraitConfig const& traitConfig, PlayerDataAccessor player, bool requireSpendingAllCurrencies /*= false*/)
{
    auto getNodeEntryCount = [&](int32 traitNodeId)
    {
        return std::count_if(traitConfig.Entries.begin(), traitConfig.Entries.end(), [traitNodeId](WorldPackets::Traits::TraitEntry const& traitEntry)
        {
            return traitEntry.TraitNodeID == traitNodeId;
        });
    };

    auto getNodeEntry = [&](int32 traitNodeId, int32 traitNodeEntryId)
    {
        auto entryItr = std::find_if(traitConfig.Entries.begin(), traitConfig.Entries.end(), [=](WorldPackets::Traits::TraitEntry const& traitEntry)
        {
            return traitEntry.TraitNodeID == traitNodeId && traitEntry.TraitNodeEntryID == traitNodeEntryId;
        });
        return entryItr != traitConfig.Entries.end() ? &*entryItr : nullptr;
    };

    auto isNodeFullyFilled = [&](Node const* node)
    {
        if (node->Data->GetType() == TraitNodeType::Selection)
            return std::any_of(node->Entries.begin(), node->Entries.end(), [&](NodeEntry const& nodeEntry)
            {
                WorldPackets::Traits::TraitEntry const* traitEntry = getNodeEntry(node->Data->ID, nodeEntry.Data->ID);
                return traitEntry && (traitEntry->Rank + traitEntry->GrantedRanks) == nodeEntry.Data->MaxRanks;
            });

        return std::all_of(node->Entries.begin(), node->Entries.end(), [&](NodeEntry const& nodeEntry)
        {
            WorldPackets::Traits::TraitEntry const* traitEntry = getNodeEntry(node->Data->ID, nodeEntry.Data->ID);
            return traitEntry && (traitEntry->Rank + traitEntry->GrantedRanks) == nodeEntry.Data->MaxRanks;
        });
    };

    Optional<std::map<int32, int32>> spentCurrencies;
    FillSpentCurrenciesMap(traitConfig, spentCurrencies.emplace());

    auto meetsConditions = [&](std::vector<TraitCondEntry const*> const& conditions)
    {
        bool hasConditions = false;
        for (TraitCondEntry const* condition : conditions)
        {
            if (condition->GetCondType() == TraitConditionType::Available || condition->GetCondType() == TraitConditionType::Visible)
            {
                if (MeetsTraitCondition(traitConfig, player, condition, spentCurrencies))
                   return true;

                hasConditions = true;
            }
        }

        return !hasConditions;
    };

    for (WorldPackets::Traits::TraitEntry const& traitEntry : traitConfig.Entries)
    {
        if (!IsValidEntry(traitEntry))
            return LearnResult::Unknown;

        Node const* node = Trinity::Containers::MapGetValuePtr(_traitNodes, traitEntry.TraitNodeID);
        if (node->Data->GetType() == TraitNodeType::Selection)
            if (getNodeEntryCount(traitEntry.TraitNodeID) != 1)
                return LearnResult::Unknown;

        for (NodeEntry const& entry : node->Entries)
            if (!meetsConditions(entry.Conditions))
                return LearnResult::Unknown;

        if (!meetsConditions(node->Conditions))
            return LearnResult::Unknown;

        for (NodeGroup const* group : node->Groups)
            if (!meetsConditions(group->Conditions))
                return LearnResult::Unknown;

        if (!node->ParentNodes.empty())
        {
            bool hasAnyParentTrait = false;
            for (auto const& [parentNode, edgeType] : node->ParentNodes)
            {
                if (!isNodeFullyFilled(parentNode))
                {
                    if (edgeType == TraitEdgeType::RequiredForAvailability)
                        return LearnResult::NotEnoughTalentsInPrimaryTree;

                    continue;
                }

                hasAnyParentTrait = true;
            }

            if (!hasAnyParentTrait)
                return LearnResult::NotEnoughTalentsInPrimaryTree;
        }
    }

    std::map<int32, int32> grantedCurrencies;
    FillOwnedCurrenciesMap(traitConfig, player, grantedCurrencies);

    for (auto [traitCurrencyId, spentAmount] : *spentCurrencies)
    {
        if (sTraitCurrencyStore.AssertEntry(traitCurrencyId)->GetType() != TraitCurrencyType::TraitSourced)
            continue;

        if (!spentAmount)
            continue;

        int32* grantedCount = Trinity::Containers::MapGetValuePtr(grantedCurrencies, traitCurrencyId);
        if (!grantedCount || *grantedCount < spentAmount)
            return LearnResult::NotEnoughTalentsInPrimaryTree;

    }

    if (requireSpendingAllCurrencies && traitConfig.Type == TraitConfigType::Combat)
    {
        for (auto [traitCurrencyId, grantedAmount] : grantedCurrencies)
        {
            if (!grantedAmount)
                continue;

            int32* spentAmount = Trinity::Containers::MapGetValuePtr(*spentCurrencies, traitCurrencyId);
            if (!spentAmount || *spentAmount != grantedAmount)
                return LearnResult::UnspentTalentPoints;
        }
    }

    return LearnResult::Ok;
}

std::vector<TraitDefinitionEffectPointsEntry const*> const* GetTraitDefinitionEffectPointModifiers(int32 traitDefinitionId)
{
    return Trinity::Containers::MapGetValuePtr(_traitDefinitionEffectPointModifiers, traitDefinitionId);
}

void InitializeStarterBuildTraitConfig(WorldPackets::Traits::TraitConfig& traitConfig, PlayerDataAccessor player)
{
    traitConfig.Entries.clear();
    std::vector<Tree const*> const* trees = GetTreesForConfig(traitConfig);
    if (!trees)
        return;

    for (UF::TraitEntry const& grant : GetGrantedTraitEntriesForConfig(traitConfig, player))
    {
        WorldPackets::Traits::TraitEntry& newEntry = traitConfig.Entries.emplace_back();
        newEntry.TraitNodeID = grant.TraitNodeID;
        newEntry.TraitNodeEntryID = grant.TraitNodeEntryID;
        newEntry.GrantedRanks = grant.GrantedRanks;
    }

    std::map<int32, int32> currencies;
    FillOwnedCurrenciesMap(traitConfig, player, currencies);

    if (std::vector<TraitTreeLoadoutEntryEntry const*> const* loadoutEntries = Trinity::Containers::MapGetValuePtr(_traitTreeLoadoutsByChrSpecialization, traitConfig.ChrSpecializationID))
    {
        auto findEntry = [](WorldPackets::Traits::TraitConfig& config, int32 traitNodeId, int32 traitNodeEntryId) -> WorldPackets::Traits::TraitEntry*
        {
            auto entryItr = std::find_if(config.Entries.begin(), config.Entries.end(), [=](WorldPackets::Traits::TraitEntry const& traitEntry)
            {
                return traitEntry.TraitNodeID == traitNodeId && traitEntry.TraitNodeEntryID == traitNodeEntryId;
            });
            return entryItr != config.Entries.end() ? &*entryItr : nullptr;
        };

        for (TraitTreeLoadoutEntryEntry const* loadoutEntry : *loadoutEntries)
        {
            int32 addedRanks = loadoutEntry->NumPoints;
            Node const* node = Trinity::Containers::MapGetValuePtr(_traitNodes, loadoutEntry->SelectedTraitNodeID);

            WorldPackets::Traits::TraitEntry newEntry;
            newEntry.TraitNodeID = loadoutEntry->SelectedTraitNodeID;
            newEntry.TraitNodeEntryID = loadoutEntry->SelectedTraitNodeEntryID;
            if (!newEntry.TraitNodeEntryID)
                newEntry.TraitNodeEntryID = node->Entries[0].Data->ID;

            WorldPackets::Traits::TraitEntry* entryInConfig = findEntry(traitConfig, newEntry.TraitNodeID, newEntry.TraitNodeEntryID);

            if (entryInConfig)
                addedRanks -= entryInConfig->Rank;

            newEntry.Rank = addedRanks;

            if (!HasEnoughCurrency(newEntry, currencies))
                continue;

            if (entryInConfig)
                entryInConfig->Rank += addedRanks;
            else
                traitConfig.Entries.push_back(newEntry);

            TakeCurrencyCost(newEntry, currencies);
        }
    }
}
}
