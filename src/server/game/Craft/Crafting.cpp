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

#include "Crafting.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "DB2Structure.h"
#include "Item.h"
#include "ItemBonusMgr.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "Player.h"

SpellCastResult Crafting::DoCraft(uint32 craftingDataId)
{
    std::vector<ModifiedCraftingSpellSlotEntry const*> spellSlots = sDB2Manager.GetMCRSpellSlotBySpell(_spell->GetSpellInfo()->Id);
    _craftingData = sCraftingDataStore.LookupEntry(craftingDataId);

    if (!_craftingData || spellSlots.empty())
        return SpellCastResult::SPELL_FAILED_ERROR;

    std::unordered_map<uint32 /*itemId*/, uint32 /*quantity*/> usedReagentsToDestroy;
    std::vector<uint32> bonusTreeIds;

    if (_craftingData->ItemBonusTreeID)
        bonusTreeIds.push_back(_craftingData->ItemBonusTreeID);

    uint32 craftingDifficulty = _craftingData->CraftingDifficulty;

    // List all reagent "slots" for this craft, with ReagentSlotID & ReagentCount
    for (ModifiedCraftingSpellSlotEntry const* spellSlot : spellSlots)
    {
        // If no ReagentCount used by spell why even bother ?
        if (spellSlot->ReagentCount < 1)
            continue;

        ModifiedCraftingReagentSlotEntry const* reagentSlot = sModifiedCraftingReagentSlotStore.LookupEntry(spellSlot->ModifiedCraftingReagentSlotID);
        uint32 reagentCountForSlot = 0;

        auto providedReagentItr = _spell->m_targets.ModifiedCraftingReagents.find(spellSlot->Slot);
        if (providedReagentItr != _spell->m_targets.ModifiedCraftingReagents.end())
        {
            for (WorldPackets::Spells::SpellCraftingReagent const& providedReagentForSlot : providedReagentItr->second)
            {
                if (_player->HasItemCount(providedReagentForSlot.ItemID, providedReagentForSlot.Quantity))
                {
                    reagentCountForSlot += providedReagentForSlot.Quantity;
                    usedReagentsToDestroy[providedReagentForSlot.ItemID] = providedReagentForSlot.Quantity;

                    if (CraftingReagentQualityEntry const* reagentQuality = sDB2Manager.GetCraftingReagentQualityByItem(providedReagentForSlot.ItemID))
                        craftingDifficulty += reagentQuality->MaxDifficultyAdjustment;
                }
            }
        }

        if (reagentCountForSlot < uint32(spellSlot->ReagentCount))
        {
            // If we don't have enough Reagent for this slot and it is required, craft failed
            if (reagentSlot->ReagentType == MCR_REAGENT_TYPE_REQUIRED)
                return SpellCastResult::SPELL_FAILED_NEED_MORE_ITEMS;

            // Still not enough but the reagent is optional, just skip
            continue;
        }

        std::vector<ModifiedCraftingCategoryEntry const*> categories = sDB2Manager.GetMCRCategoryByReagentSlot(spellSlot->ModifiedCraftingReagentSlotID);
        bool hasOneMatchingItem = false;

        for (ModifiedCraftingCategoryEntry const* category : categories)
        {
            std::vector<ModifiedCraftingReagentItemEntry const*> reagentItems = sDB2Manager.GetMCRReagentItemByCategory(category->ID);

            for (ModifiedCraftingReagentItemEntry const* reagentItem : reagentItems)
            {
                std::set<ItemSparseEntry const*> requiredItems = sDB2Manager.GetItemSparseByMCRReagentItem(reagentItem->ID);

                for (WorldPackets::Spells::SpellCraftingReagent const& providedReagent : providedReagentItr->second)
                {
                    bool hasItem = std::count_if(std::cbegin(requiredItems), std::cend(requiredItems), [providedReagent](ItemSparseEntry const* itemSparse) {
                        return itemSparse->ID == uint32(providedReagent.ItemID);
                    });

                    if (hasItem)
                        bonusTreeIds.push_back(reagentItem->ItemBonusTreeID);

                    hasOneMatchingItem = hasOneMatchingItem || hasItem;
                }
            }
        }

        // If any item provided do not match, probably a cheater, return
        if (!hasOneMatchingItem)
            return SpellCastResult::SPELL_FAILED_NEED_MORE_ITEMS;
    }

    uint32 skillLevel = GetSkillLevelForCraft();
    uint32 difficultyPercentMatched = round(float(skillLevel) / float(craftingDifficulty) * 100.f);

    uint32 qualityTier = sDB2Manager.GetCraftingQualityTierByDifficultyPercent(_craftingData->CraftingDifficultyID, difficultyPercentMatched);

    uint32 craftedItemId = GetCraftedItemIdForQuality(qualityTier);

    // If we didn't found anything, we have a problem. Return and don't take reagent from player.
    if (!craftedItemId)
        return SpellCastResult::SPELL_FAILED_ERROR;

    ItemContext context = _spell->GetSpellInfo()->HasAttribute(SPELL_ATTR0_IS_TRADESKILL) ? ItemContext::Trade_Skill : ItemContext::NONE;

    std::vector<int32> bonusLists;
    for (int32 bonusTreeID : bonusTreeIds)
    {
        std::vector<int32> treeBonusList = ItemBonusMgr::GetBonusListsForItem(craftedItemId, { context, {}, {}, bonusTreeID, qualityTier });
        bonusLists.insert(std::end(bonusLists), std::begin(treeBonusList), std::end(treeBonusList));
    }

    if (Item* createdItem = _spell->DoCreateItem(craftedItemId, context, &bonusLists, false))
    {
        InitCraftingStatModifier(createdItem);

        createdItem->AddToWorld();
        createdItem->SendUpdateToPlayer(_player);
    }

    // Item has been crafted, remove reagent from player
    for (auto const& [itemId, itemCount] : usedReagentsToDestroy)
        _player->DestroyItemCount(itemId, itemCount, true);

    return SpellCastResult::SPELL_CAST_OK;
}

uint32 Crafting::GetSkillLevelForCraft()
{
    uint32 skillId = GetSkillIdForSpell(_spell->GetSpellInfo()->Id);
    uint32 skillValue = _player->GetSkillValue(skillId);

    uint32 totalReagentWeigth = CalculateTotalReagentWeights();

    CraftingDifficultyEntry const* craftingDifficultyEntry = sCraftingDifficultyStore.LookupEntry(_craftingData->CraftingDifficultyID);
    if (!craftingDifficultyEntry)
        return skillValue;

    float maximumReagentBonus = round(float(_craftingData->CraftingDifficulty) * float(craftingDifficultyEntry->CraftSkillBonusPercent) / 100.f);

    for (ModifiedCraftingSpellSlotEntry const* spellSlot : sDB2Manager.GetMCRSpellSlotBySpell(_spell->GetSpellInfo()->Id))
    {
        for (ModifiedCraftingCategoryEntry const* category : sDB2Manager.GetMCRCategoryByReagentSlot(spellSlot->ModifiedCraftingReagentSlotID))
        {
            auto providedReagentItr = _spell->m_targets.ModifiedCraftingReagents.find(spellSlot->Slot);
            if (providedReagentItr != _spell->m_targets.ModifiedCraftingReagents.end())
            {
                for (WorldPackets::Spells::SpellCraftingReagent const& providedReagentForSlot : providedReagentItr->second)
                {
                    if (CraftingReagentQualityEntry const* reagentQuality = sDB2Manager.GetCraftingReagentQualityByItem(providedReagentForSlot.ItemID))
                    {
                        float reagentWeight = float(category->MatQualityWeight) * float(providedReagentForSlot.Quantity) / 2.0f * float(reagentQuality->OrderIndex);
                        uint32 addedSkillByReagent = round(maximumReagentBonus * reagentWeight / float(totalReagentWeigth));
                        skillValue += addedSkillByReagent;
                    }
                }
            }
        }
    }

    return skillValue;
}

uint32 Crafting::GetSkillIdForSpell(uint32 spellId)
{
    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellId);
    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
        if (_spell_idx->second->SkillupSkillLineID)
            return _spell_idx->second->SkillupSkillLineID;

    return 0;
}

uint32 Crafting::CalculateTotalReagentWeights()
{
    uint32 totalWeight = 0;

    for (ModifiedCraftingSpellSlotEntry const* spellSlot : sDB2Manager.GetMCRSpellSlotBySpell(_spell->GetSpellInfo()->Id))
        for (ModifiedCraftingCategoryEntry const* category : sDB2Manager.GetMCRCategoryByReagentSlot(spellSlot->ModifiedCraftingReagentSlotID))
            totalWeight += category->MatQualityWeight * spellSlot->ReagentCount;

    return totalWeight;
}

// Todo : We currently only set random stats, but crafter
// can define stats using a "Missive" item
void Crafting::InitCraftingStatModifier(Item* item)
{
    std::vector<uint32> allowedStats = {
        ITEM_MOD_MASTERY_RATING,
        ITEM_MOD_HASTE_RATING,
        ITEM_MOD_VERSATILITY,
        ITEM_MOD_CRIT_RATING,
    };

    Trinity::Containers::RandomShuffle(allowedStats);

    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
    {
        if (item->GetItemStatType(i) == ITEM_MOD_MODIFIED_CRAFTING_STAT_1)
            item->SetModifier(ITEM_MODIFIER_CHANGE_MODIFIED_CRAFTING_STAT_1, allowedStats[0]);
        else if (item->GetItemStatType(i) == ITEM_MOD_MODIFIED_CRAFTING_STAT_2)
            item->SetModifier(ITEM_MODIFIER_CHANGE_MODIFIED_CRAFTING_STAT_2, allowedStats[1]);
    }
}

uint32 Crafting::GetCraftedItemIdForQuality(uint32 qualityTier)
{
    // If this is a simple item (no quality), we have the id
    uint32 newItemId = _craftingData->CraftedItemID;

    // If it's a reagent with quality, get id from CraftingDataItem
    if (!newItemId)
    {
        std::vector<uint32> craftedItemList = sDB2Manager.GetCraftingDataItemIDByCraftingData(_craftingData->ID);
        if (craftedItemList.size() < qualityTier)
            return 0;

        newItemId = craftedItemList[qualityTier - 1];
    }

    return newItemId;
}
