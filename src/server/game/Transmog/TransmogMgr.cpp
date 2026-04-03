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

#include "TransmogMgr.h"
#include "DB2Stores.h"
#include "FlatSet.h"
#include "MapUtils.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TransmogrificationPackets.h"
#include "Util.h"

namespace
{
struct TransmogOutfitSlotOptionInfo
{
    TransmogOutfitSlotOptionEntry const* Data = nullptr;
    int32 SlotIndex = -1;
};

struct TransmogOutfitSlotInfo
{
    TransmogOutfitSlotInfoEntry const* Data = nullptr;
    std::variant<int32, std::unique_ptr<TransmogOutfitSlotOptionInfo[]>> SlotIndexOrOptions;

    int32 GetSlotIndex(TransmogOutfitSlotOption slotOption) const
    {
        switch (SlotIndexOrOptions.index())
        {
            case 0:
                return std::get<0>(SlotIndexOrOptions);
            case 1:
                return std::get<1>(SlotIndexOrOptions)[AsUnderlyingType(slotOption)].SlotIndex;
            default:
                return -1;
        }
    }
};

std::unordered_map<std::pair<uint32 /*itemId*/, uint32 /*appearanceMod*/>, ItemModifiedAppearanceEntry const*> ItemModifiedAppearancesByItem;
std::unordered_map<uint32, TransmogIllusionEntry const*> TransmogIllusionBySpellItemEnchantment;
std::unordered_map<uint32, Trinity::Containers::FlatSet<TransmogSetEntry const*>> TransmogSetsByItemModifiedAppearance;
std::vector<TransmogSetItemEntry const*> TransmogSetItemsByTransmogSet;
std::array<std::vector<TransmogOutfitEntryEntry const*>, AsUnderlyingType(TransmogOutfitEntrySource::Max)> TransmogOutfitsBySource;
std::vector<TransmogOutfitEntryEntry const*> TransmogOutfitsAutomaticallyCreated;
std::vector<TransmogMgr::TransmogOutfitSlotAndOptionInfo> AllSlots;
std::array<TransmogOutfitSlotInfo, AsUnderlyingType(TransmogOutfitSlot::Max)> SlotInfoByOutfitSlot;
std::array<TransmogOutfitSlotInfo const*, EQUIPMENT_SLOT_END> SlotInfoByInvSlot;
std::vector<TransmogSituationEntry const*> DefaultSituations;

constexpr bool IsArtifactTransmogOutfitSlotOption(TransmogOutfitSlotOption option)
{
    return option == TransmogOutfitSlotOption::ArtifactSpecOne
        || option == TransmogOutfitSlotOption::ArtifactSpecTwo
        || option == TransmogOutfitSlotOption::ArtifactSpecThree
        || option == TransmogOutfitSlotOption::ArtifactSpecFour;
}

bool IsValidTransmogOutfitSlotForItem(ItemTemplate const* item, TransmogOutfitSlot slot, TransmogOutfitSlotOption option)
{
    if (IsArtifactTransmogOutfitSlotOption(option))
        if (ArtifactEntry const* artifact = sArtifactStore.LookupEntry(item->GetArtifactID()))
            if (ChrSpecializationEntry const* specialization = sChrSpecializationStore.LookupEntry(artifact->ChrSpecializationID))
                if ((int8(option) - int8(TransmogOutfitSlotOption::ArtifactSpecOne)) != specialization->OrderIndex)
                    return false;

    switch (item->GetInventoryType())
    {
        case INVTYPE_HEAD:
            return slot == TransmogOutfitSlot::Head;
        case INVTYPE_SHOULDERS:
            return slot == TransmogOutfitSlot::ShoulderLeft || slot == TransmogOutfitSlot::ShoulderRight;
        case INVTYPE_BODY:
            return slot == TransmogOutfitSlot::Body;
        case INVTYPE_CHEST:
        case INVTYPE_ROBE:
            return slot == TransmogOutfitSlot::Chest;
        case INVTYPE_WAIST:
            return slot == TransmogOutfitSlot::Waist;
        case INVTYPE_LEGS:
            return slot == TransmogOutfitSlot::Legs;
        case INVTYPE_FEET:
            return slot == TransmogOutfitSlot::Feet;
        case INVTYPE_WRISTS:
            return slot == TransmogOutfitSlot::Wrist;
        case INVTYPE_HANDS:
            return slot == TransmogOutfitSlot::Hand;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            return slot == TransmogOutfitSlot::WeaponMainHand || slot == TransmogOutfitSlot::WeaponOffHand || IsArtifactTransmogOutfitSlotOption(option);
        case INVTYPE_SHIELD:
        case INVTYPE_HOLDABLE:
            return slot == TransmogOutfitSlot::WeaponOffHand || IsArtifactTransmogOutfitSlotOption(option);
        case INVTYPE_RANGED:
            return (slot == TransmogOutfitSlot::WeaponMainHand && option == TransmogOutfitSlotOption::RangedWeapon) || IsArtifactTransmogOutfitSlotOption(option);
        case INVTYPE_CLOAK:
            return slot == TransmogOutfitSlot::Back;
        case INVTYPE_2HWEAPON:
            return slot == TransmogOutfitSlot::WeaponMainHand || (slot == TransmogOutfitSlot::WeaponOffHand && option == TransmogOutfitSlotOption::FuryTwoHandedWeapon) || IsArtifactTransmogOutfitSlotOption(option);
        case INVTYPE_TABARD:
            return slot == TransmogOutfitSlot::Tabard;
        case INVTYPE_RANGEDRIGHT:
            return slot == (item->GetSubClass() == ITEM_SUBCLASS_WEAPON_WAND ? TransmogOutfitSlot::WeaponMainHand : TransmogOutfitSlot::WeaponRanged) || IsArtifactTransmogOutfitSlotOption(option);
        default:
            break;
    }
    return false;
}
}

void TransmogMgr::Load()
{
    for (ItemModifiedAppearanceEntry const* appearanceMod : sItemModifiedAppearanceStore)
        ItemModifiedAppearancesByItem[{ appearanceMod->ItemID, appearanceMod->ItemAppearanceModifierID }] = appearanceMod;

    for (TransmogIllusionEntry const* transmogIllusion : sTransmogIllusionStore)
        TransmogIllusionBySpellItemEnchantment[transmogIllusion->SpellItemEnchantmentID] = transmogIllusion;

    for (TransmogSetItemEntry const* transmogSetItem : sTransmogSetItemStore)
    {
        TransmogSetEntry const* set = sTransmogSetStore.LookupEntry(transmogSetItem->TransmogSetID);
        if (!set)
            continue;

        TransmogSetsByItemModifiedAppearance[transmogSetItem->ItemModifiedAppearanceID].insert(set);
        TransmogSetItemsByTransmogSet.push_back(transmogSetItem);
    }

    std::ranges::sort(TransmogSetItemsByTransmogSet, {}, &TransmogSetItemEntry::TransmogSetID);

    for (TransmogOutfitEntryEntry const* transmogOutfitEntry : sTransmogOutfitEntryStore)
    {
        if (transmogOutfitEntry->HasFlag(TransmogOutfitEntryFlags::AutomaticallyAwardedOnLogin))
            TransmogOutfitsAutomaticallyCreated.push_back(transmogOutfitEntry);

        if (transmogOutfitEntry->GetSetType() == TransmogOutfitSetType::Outfit)
            TransmogOutfitsBySource[AsUnderlyingType(transmogOutfitEntry->GetSource())].push_back(transmogOutfitEntry);
    }

    for (std::vector<TransmogOutfitEntryEntry const*>& transmogOutfitEntries : TransmogOutfitsBySource)
        std::ranges::sort(transmogOutfitEntries, {}, &TransmogOutfitEntryEntry::OrderIndex);

    for (TransmogOutfitSlotInfoEntry const* transmogOutfitSlot : sTransmogOutfitSlotInfoStore)
    {
        ASSERT(transmogOutfitSlot->GetSlot() < TransmogOutfitSlot::Max);

        TransmogOutfitSlotInfo* slot = &SlotInfoByOutfitSlot[AsUnderlyingType(transmogOutfitSlot->GetSlot())];
        slot->Data = transmogOutfitSlot;

        if (!transmogOutfitSlot->HasFlag(TransmogOutfitSlotFlags::IsSecondarySlot))
        {
            ASSERT(transmogOutfitSlot->InventorySlotEnum < EQUIPMENT_SLOT_END);
            SlotInfoByInvSlot[transmogOutfitSlot->InventorySlotEnum] = slot;
        }
    }

    for (TransmogOutfitSlotOptionEntry const* transmogOutfitSlotOption : sTransmogOutfitSlotOptionInfoStore)
    {
        ASSERT(transmogOutfitSlotOption->GetOption() < TransmogOutfitSlotOption::Max);

        TransmogOutfitSlotInfoEntry const* transmogOutfitSlot = sTransmogOutfitSlotInfoStore.AssertEntry(transmogOutfitSlotOption->TransmogOutfitSlotInfoID);

        TransmogOutfitSlotInfo& slotInfo = SlotInfoByOutfitSlot[AsUnderlyingType(transmogOutfitSlot->GetSlot())];
        if (!std::holds_alternative<std::unique_ptr<TransmogOutfitSlotOptionInfo[]>>(slotInfo.SlotIndexOrOptions))
            slotInfo.SlotIndexOrOptions.emplace<std::unique_ptr<TransmogOutfitSlotOptionInfo[]>>(new TransmogOutfitSlotOptionInfo[AsUnderlyingType(TransmogOutfitSlotOption::Max)]);

        std::get<std::unique_ptr<TransmogOutfitSlotOptionInfo[]>>(slotInfo.SlotIndexOrOptions)[AsUnderlyingType(transmogOutfitSlotOption->GetOption())].Data = transmogOutfitSlotOption;
    }

    for (TransmogOutfitSlotInfo& slotInfo : SlotInfoByOutfitSlot)
    {
        if (!slotInfo.Data)
            continue;

        TransmogOutfitSlotAndOptionInfo& slot = AllSlots.emplace_back();
        slot.Slot = slotInfo.Data;
        slot.SlotIndex = AllSlots.size() - 1;

        if (std::holds_alternative<std::unique_ptr<TransmogOutfitSlotOptionInfo[]>>(slotInfo.SlotIndexOrOptions))
        {
            // if slot has options, keep adding transmog slots for every option
            auto options = std::span<TransmogOutfitSlotOptionInfo, AsUnderlyingType(TransmogOutfitSlotOption::Max)>(
                &std::get<std::unique_ptr<TransmogOutfitSlotOptionInfo[]>>(slotInfo.SlotIndexOrOptions)[0],
                AsUnderlyingType(TransmogOutfitSlotOption::Max));

            auto optionItr = std::ranges::find_if(options,
                [](TransmogOutfitSlotOptionEntry const* option) { return option != nullptr; },
                &TransmogOutfitSlotOptionInfo::Data);

            slot.SlotOption = optionItr->Data;
            optionItr->SlotIndex = AllSlots.size() - 1;

            while (++optionItr != options.end())
            {
                if (!optionItr->Data)
                    continue;

                TransmogOutfitSlotAndOptionInfo& newSlot = AllSlots.emplace_back();
                newSlot.Slot = slotInfo.Data;
                newSlot.SlotOption = optionItr->Data;
                newSlot.SlotIndex = AllSlots.size() - 1;
                optionItr->SlotIndex = AllSlots.size() - 1;
            }
        }
        if (std::holds_alternative<int32>(slotInfo.SlotIndexOrOptions))
            std::get<int32>(slotInfo.SlotIndexOrOptions) = AllSlots.size() - 1;
    }

    for (TransmogSituationEntry const* transmogSituation : sTransmogSituationStore)
        if (transmogSituation->HasFlag(TransmogSituationFlags::DefaultsToOn))
            DefaultSituations.push_back(transmogSituation);
}

ItemModifiedAppearanceEntry const* TransmogMgr::GetItemModifiedAppearance(uint32 itemId, uint32 appearanceModId)
{
    auto itr = ItemModifiedAppearancesByItem.find({ itemId, appearanceModId });
    if (itr != ItemModifiedAppearancesByItem.end())
        return itr->second;

    // Fall back to unmodified appearance
    if (appearanceModId)
        return GetDefaultItemModifiedAppearance(itemId);

    return nullptr;
}

ItemModifiedAppearanceEntry const* TransmogMgr::GetDefaultItemModifiedAppearance(uint32 itemId)
{
    return Trinity::Containers::MapGetValuePtr(ItemModifiedAppearancesByItem, { itemId, 0 });
}

TransmogIllusionEntry const* TransmogMgr::GetTransmogIllusionForSpellItemEnchantment(uint32 spellItemEnchantmentId)
{
    return Trinity::Containers::MapGetValuePtr(TransmogIllusionBySpellItemEnchantment, spellItemEnchantmentId);
}

std::span<TransmogSetEntry const* const> TransmogMgr::GetTransmogSetsForItemModifiedAppearance(uint32 itemModifiedAppearanceId)
{
    std::span<TransmogSetEntry const* const> result;
    auto itr = TransmogSetsByItemModifiedAppearance.find(itemModifiedAppearanceId);
    if (itr != TransmogSetsByItemModifiedAppearance.end())
        result = itr->second;

    return result;
}

std::span<TransmogSetItemEntry const* const> TransmogMgr::GetTransmogSetItems(uint32 transmogSetId)
{
    return std::ranges::equal_range(TransmogSetItemsByTransmogSet, transmogSetId, {}, &TransmogSetItemEntry::TransmogSetID);
}

std::span<TransmogOutfitEntryEntry const* const> TransmogMgr::GetAutomaticallyUnlockedOutfits()
{
    return TransmogOutfitsAutomaticallyCreated;
}

std::span<TransmogMgr::TransmogOutfitSlotAndOptionInfo const> TransmogMgr::GetAllSlots()
{
    return AllSlots;
}

TransmogMgr::TransmogOutfitSlotAndOptionInfo const* TransmogMgr::GetSlotAndOption(TransmogOutfitSlot slot, TransmogOutfitSlotOption slotOption)
{
    int32 slotIndex = SlotInfoByOutfitSlot[AsUnderlyingType(slot)].GetSlotIndex(slotOption);
    if (slotIndex >= 0)
        return &AllSlots[slotIndex];

    return nullptr;
}

TransmogMgr::TransmogOutfitSlotAndOptionInfo const* TransmogMgr::GetSlotAndOption(EquipmentSlots inventorySlot, TransmogOutfitSlotOption slotOption)
{
    if (TransmogOutfitSlotInfo const* slotInfo = SlotInfoByInvSlot[inventorySlot])
        if (int32 slotIndex = slotInfo->GetSlotIndex(slotOption); slotIndex >= 0)
            return &AllSlots[slotIndex];

    return nullptr;
}

std::span<TransmogSituationEntry const* const> TransmogMgr::GetDefaultSituations()
{
    return DefaultSituations;
}

TransmogOutfitEntryEntry const* TransmogMgr::GetNextOutfitToUnlock(TransmogOutfitEntrySource source, Player const* player)
{
    if (source >= TransmogOutfitEntrySource::Max)
        return nullptr;

    TransmogOutfitEntryEntry const* lastOwnedOutfit = nullptr;
    for (auto const& [id, transmogOutfit] : player->m_activePlayerData->TransmogOutfits)
    {
        TransmogOutfitEntryEntry const* transmogOutfitEntry = sTransmogOutfitEntryStore.LookupEntry(transmogOutfit.value.Id);
        if (!transmogOutfitEntry || transmogOutfitEntry->GetSource() != source)
            continue;

        if (!lastOwnedOutfit || transmogOutfitEntry->OrderIndex > lastOwnedOutfit->OrderIndex)
            lastOwnedOutfit = transmogOutfitEntry;
    }

    if (!lastOwnedOutfit)
        return TransmogOutfitsBySource[AsUnderlyingType(source)].front();

    auto itr = std::ranges::find(TransmogOutfitsBySource[AsUnderlyingType(source)], lastOwnedOutfit) + 1;
    if (itr != TransmogOutfitsBySource[AsUnderlyingType(source)].end())
        return *itr;

    return nullptr;
}

bool TransmogMgr::ValidateSituations(std::span<WorldPackets::Transmogrification::TransmogOutfitSituationInfo const> situations)
{
    struct SituationTriggerStatus
    {
        uint8 AllSituationCount = 0;
        uint8 NoneSituationCount = 0;
        uint8 RegularSituationCount = 0;
    };

    std::array<SituationTriggerStatus, AsUnderlyingType(TransmogSituationTrigger::Max)> statusByTrigger;

    for (WorldPackets::Transmogrification::TransmogOutfitSituationInfo const& situation : situations)
    {
        TransmogSituationEntry const* transmogSituation = sTransmogSituationStore.LookupEntry(situation.SituationID);
        if (!transmogSituation)
            return false;

        TransmogSituationGroupEntry const* transmogSituationGroup = sTransmogSituationGroupStore.LookupEntry(transmogSituation->TransmogSituationGroupID);
        if (!transmogSituationGroup)
            return false;

        TransmogSituationTriggerEntry const* transmogSituationTrigger = sTransmogSituationTriggerStore.LookupEntry(transmogSituationGroup->TransmogSituationTriggerID);
        if (!transmogSituationTrigger)
            return false;

        SituationTriggerStatus& triggers = statusByTrigger[AsUnderlyingType(transmogSituationTrigger->GetTrigger())];
        uint8* count = nullptr;
        if (transmogSituation->HasFlag(TransmogSituationFlags::AllSituation))
            count = &triggers.AllSituationCount;
        else if (transmogSituation->HasFlag(TransmogSituationFlags::NoneSituation))
            count = &triggers.NoneSituationCount;
        else
            count = &triggers.RegularSituationCount;

        *count += 1;
        if (transmogSituationTrigger->HasFlag(TransmogSituationTriggerFlags::SituationsAreExclusive) && *count > 1)
            return false;
    }

    for (SituationTriggerStatus const& triggers : statusByTrigger)
        if ((triggers.AllSituationCount > 0) + (triggers.NoneSituationCount > 0) + (triggers.RegularSituationCount > 0) > 1) // only 1 group can be active
            return false;

    return true;
}

bool TransmogMgr::ValidateSlots(std::span<WorldPackets::Transmogrification::TransmogOutfitSlotData const> slots)
{
    for (WorldPackets::Transmogrification::TransmogOutfitSlotData const& slot : slots)
    {
        if (slot.Slot >= TransmogOutfitSlot::Max)
            return false;

        if (slot.SlotOption >= TransmogOutfitSlotOption::Max)
            return false;

        if (slot.AppearanceDisplayType >= TransmogOutfitDisplayType::Max)
            return false;

        if (slot.IllusionDisplayType >= TransmogOutfitDisplayType::Max)
            return false;

        if (!GetSlotAndOption(slot.Slot, slot.SlotOption))
            return false;

        if (slot.ItemModifiedAppearanceID)
        {
            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(slot.ItemModifiedAppearanceID);
            if (!itemModifiedAppearance)
                return false;

            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID);
            if (!itemTemplate)
                return false;

            if (!IsValidTransmogOutfitSlotForItem(itemTemplate, slot.Slot, slot.SlotOption))
                return false;

            TransmogOutfitSlotOption appearanceSlotOption = itemTemplate->GetWeaponTransmogOutfitSlotOption();
            if (appearanceSlotOption != slot.SlotOption
                && (slot.SlotOption != TransmogOutfitSlotOption::FuryTwoHandedWeapon
                    || appearanceSlotOption != TransmogOutfitSlotOption::TwoHandedWeapon))
                return false;
        }

        if (slot.SpellItemEnchantmentID && !TransmogIllusionBySpellItemEnchantment.contains(slot.SpellItemEnchantmentID))
            return false;
    }

    return true;
}
