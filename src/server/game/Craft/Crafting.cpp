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
#include "ItemBonusMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellPackets.h"

void Crafting::DoCraft(uint32 craftingDataId)
{
    std::vector<ModifiedCraftingSpellSlotEntry const*> spellSlots = sDB2Manager.GetMCRSpellSlotBySpell(_spell->GetSpellInfo()->Id);
    _craftingData = sCraftingDataStore.LookupEntry(craftingDataId);

    if (!_craftingData || spellSlots.empty())
    {
        _spell->SendCastResult(SpellCastResult::SPELL_FAILED_ERROR);
        return;
    }

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
            {
                _spell->SendCastResult(SpellCastResult::SPELL_FAILED_NEED_MORE_ITEMS);
                return;
            }

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
        {
            _spell->SendCastResult(SpellCastResult::SPELL_FAILED_NEED_MORE_ITEMS);
            return;
        }
    }

    uint32 skillLevel = GetSkillLevelForCraft();
    uint32 difficultyPercentMatched = round(float(skillLevel) / float(craftingDifficulty) * 100.f);

    uint32 qualityTier = sDB2Manager.GetCraftingQualityTierByDifficultyPercent(_craftingData->CraftingDifficultyID, difficultyPercentMatched);

    // If this is a simple item (no quality), we have the id
    uint32 newItemId = _craftingData->CraftedItemID;

    // If it's a reagent, get id from CraftingDataItem
    if (!newItemId)
    {
        std::vector<uint32> craftedItemList = sDB2Manager.GetCraftingDataItemIDByCraftingData(_craftingData->ID);

        // If we didn't found anything, we have a problem. Return and don't take reagent from player.
        if (craftedItemList.size() < qualityTier)
        {
            _spell->SendCastResult(SpellCastResult::SPELL_FAILED_ERROR);
            return;
        }

        newItemId = craftedItemList[qualityTier - 1];
    }

    ItemContext context = _spell->GetSpellInfo()->HasAttribute(SPELL_ATTR0_IS_TRADESKILL) ? ItemContext::Trade_Skill : ItemContext::NONE;

    std::vector<int32> bonusLists;
    for (int32 bonusTreeID : bonusTreeIds)
    {
        std::vector<int32> treeBonusList = ItemBonusMgr::GetBonusListsForItem(newItemId, { context, {}, {}, bonusTreeID, qualityTier });
        bonusLists.insert(std::end(bonusLists), std::begin(treeBonusList), std::end(treeBonusList));
    }

    _spell->DoCreateItem(newItemId, context, &bonusLists);

    // Item has been crafted, remove reagent from player
    for (auto const& [itemId, itemCount] : usedReagentsToDestroy)
        _player->DestroyItemCount(itemId, itemCount, true);
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
                        uint32 addedSkillByReagent = round(maximumReagentBonus * reagentWeight / totalReagentWeigth);
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
