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

#include "WorldSession.h"
#include "CollectionMgr.h"
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "NPCPackets.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TransmogrificationPackets.h"

void WorldSession::HandleTransmogrifyItems(WorldPackets::Transmogrification::TransmogrifyItems& transmogrifyItems)
{
    Player* player = GetPlayer();
    // Validate
    if (!player->GetNPCIfCanInteractWith(transmogrifyItems.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER, UNIT_NPC_FLAG_2_NONE))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {} not found or player can't interact with it.", transmogrifyItems.Npc.ToString());
        return;
    }

    int64 cost = 0;
    std::unordered_map<Item*, std::pair<uint32, uint32>> transmogItems;
    std::unordered_map<Item*, uint32> illusionItems;

    std::vector<Item*> resetAppearanceItems;
    std::vector<Item*> resetIllusionItems;
    std::vector<uint32> bindAppearances;

    auto validateAndStoreTransmogItem = [&](Item* itemTransmogrified, uint32 itemModifiedAppearanceId, bool isSecondary)
    {
        ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(itemModifiedAppearanceId);
        if (!itemModifiedAppearance)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify using invalid appearance ({}).", player->GetGUID().ToString(), player->GetName(), itemModifiedAppearanceId);
            return false;
        }

        if (isSecondary && itemTransmogrified->GetTemplate()->GetInventoryType() != INVTYPE_SHOULDERS)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify secondary appearance to non-shoulder item.", player->GetGUID().ToString(), player->GetName());
            return false;
        }

        auto [hasAppearance, isTemporary] = GetCollectionMgr()->HasItemAppearance(itemModifiedAppearanceId);
        if (!hasAppearance)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify using appearance he has not collected ({}).", player->GetGUID().ToString(), player->GetName(), itemModifiedAppearanceId);
            return false;
        }
        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID);
        if (player->CanUseItem(itemTemplate) != EQUIP_ERR_OK)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify using appearance he can never use ({}).", player->GetGUID().ToString(), player->GetName(), itemModifiedAppearanceId);
            return false;
        }

        // validity of the transmogrification items
        if (!Item::CanTransmogrifyItemWithItem(itemTransmogrified, itemModifiedAppearance))
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} failed CanTransmogrifyItemWithItem ({} with appearance {}).", player->GetGUID().ToString(), player->GetName(), itemTransmogrified->GetEntry(), itemModifiedAppearanceId);
            return false;
        }

        if (!isSecondary)
            transmogItems[itemTransmogrified].first = itemModifiedAppearanceId;
        else
            transmogItems[itemTransmogrified].second = itemModifiedAppearanceId;

        if (isTemporary)
            bindAppearances.push_back(itemModifiedAppearanceId);

        return true;
    };

    for (WorldPackets::Transmogrification::TransmogrifyItem const& transmogItem : transmogrifyItems.Items)
    {
        // slot of the transmogrified item
        if (transmogItem.Slot >= EQUIPMENT_SLOT_END)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - Player ({}, name: {}) tried to transmogrify wrong slot ({}) when transmogrifying items.", player->GetGUID().ToString(), player->GetName(), transmogItem.Slot);
            return;
        }

        // transmogrified item
        Item* itemTransmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, transmogItem.Slot);
        if (!itemTransmogrified)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - Player ({}, name: {}) tried to transmogrify an invalid item in a valid slot (slot: {}).", player->GetGUID().ToString(), player->GetName(), transmogItem.Slot);
            return;
        }

        if (transmogItem.ItemModifiedAppearanceID || transmogItem.SecondaryItemModifiedAppearanceID > 0)
        {
            if (transmogItem.ItemModifiedAppearanceID > 0 && !validateAndStoreTransmogItem(itemTransmogrified, transmogItem.ItemModifiedAppearanceID, false))
                 return;

            if (transmogItem.SecondaryItemModifiedAppearanceID > 0 && !validateAndStoreTransmogItem(itemTransmogrified, transmogItem.SecondaryItemModifiedAppearanceID, true))
                return;

            // add cost
            cost += itemTransmogrified->GetSellPrice(_player);
        }
        else
            resetAppearanceItems.push_back(itemTransmogrified);

        if (transmogItem.SpellItemEnchantmentID)
        {
            if (transmogItem.Slot != EQUIPMENT_SLOT_MAINHAND && transmogItem.Slot != EQUIPMENT_SLOT_OFFHAND)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify illusion into non-weapon slot ({}).", player->GetGUID().ToString(), player->GetName(), transmogItem.Slot);
                return;
            }

            TransmogIllusionEntry const* illusion = sDB2Manager.GetTransmogIllusionForEnchantment(transmogItem.SpellItemEnchantmentID);
            if (!illusion)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify illusion using invalid enchant ({}).", player->GetGUID().ToString(), player->GetName(), transmogItem.SpellItemEnchantmentID);
                return;
            }

            if (!ConditionMgr::IsPlayerMeetingCondition(player, illusion->UnlockConditionID))
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - {}, Name: {} tried to transmogrify illusion using not allowed enchant ({}).", player->GetGUID().ToString(), player->GetName(), transmogItem.SpellItemEnchantmentID);
                return;
            }

            illusionItems[itemTransmogrified] = transmogItem.SpellItemEnchantmentID;
            cost += illusion->TransmogCost;
        }
        else
            resetIllusionItems.push_back(itemTransmogrified);
    }

    if (!player->HasAuraType(SPELL_AURA_REMOVE_TRANSMOG_COST) && cost) // 0 cost if reverting look
    {
        if (!player->HasEnoughMoney(cost))
            return;
        player->ModifyMoney(-cost);
    }

    // Everything is fine, proceed
    for (auto& transmogPair : transmogItems)
    {
        Item* transmogrified = transmogPair.first;

        if (!transmogrifyItems.CurrentSpecOnly)
        {
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, transmogPair.second.first);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
			transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, 0);

            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS, transmogPair.second.second);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, 0);
			transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, 0);
        }
        else
        {
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
			if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));

            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
			if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));

            transmogrified->SetModifier(AppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], transmogPair.second.first);
            transmogrified->SetModifier(SecondaryAppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], transmogPair.second.second);
        }

        player->SetVisibleItemSlot(transmogrified->GetSlot(), transmogrified);

        transmogrified->SetNotRefundable(player);
        transmogrified->ClearSoulboundTradeable(player);
        transmogrified->SetState(ITEM_CHANGED, player);
    }

    for (auto& illusionPair : illusionItems)
    {
        Item* transmogrified = illusionPair.first;

        if (!transmogrifyItems.CurrentSpecOnly)
        {
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, illusionPair.second);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, 0);
			transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, 0);
        }
        else
        {
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
			if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            transmogrified->SetModifier(IllusionModifierSlotBySpec[player->GetActiveTalentGroup()], illusionPair.second);
        }

        player->SetVisibleItemSlot(transmogrified->GetSlot(), transmogrified);

        transmogrified->SetNotRefundable(player);
        transmogrified->ClearSoulboundTradeable(player);
        transmogrified->SetState(ITEM_CHANGED, player);
    }

    for (Item* item : resetAppearanceItems)
    {
        if (!transmogrifyItems.CurrentSpecOnly)
        {
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
			item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, 0);

            item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, 0);
			item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, 0);
        }
        else
        {
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
			if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));

            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
			if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, item->GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));

            item->SetModifier(AppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], 0);
            item->SetModifier(SecondaryAppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, 0);
        }

        item->SetState(ITEM_CHANGED, player);
        player->SetVisibleItemSlot(item->GetSlot(), item);
    }

    for (Item* item : resetIllusionItems)
    {
        if (!transmogrifyItems.CurrentSpecOnly)
        {
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, 0);
			item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, 0);
        }
        else
        {
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
			if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));

            item->SetModifier(IllusionModifierSlotBySpec[player->GetActiveTalentGroup()], 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
        }

        item->SetState(ITEM_CHANGED, player);
        player->SetVisibleItemSlot(item->GetSlot(), item);
    }

    for (uint32 itemModifedAppearanceId : bindAppearances)
    {
        std::unordered_set<ObjectGuid> itemsProvidingAppearance = GetCollectionMgr()->GetItemsProvidingTemporaryAppearance(itemModifedAppearanceId);
        for (ObjectGuid const& itemGuid : itemsProvidingAppearance)
        {
            if (Item* item = player->GetItemByGuid(itemGuid))
            {
                item->SetNotRefundable(player);
                item->ClearSoulboundTradeable(player);
                GetCollectionMgr()->AddItemAppearance(item);
            }
        }
    }
}

void WorldSession::SendOpenTransmogrifier(ObjectGuid const& guid)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = guid;
    npcInteraction.InteractionType = PlayerInteractionType::Transmogrifier;
    npcInteraction.Success = true;
    SendPacket(npcInteraction.Write());
}

static uint8 constexpr MAX_TRANSMOG_OUTFIT_SLOTS = 30;
static uint8 constexpr MAX_TRANSMOG_OUTFITS       = 10;

enum
{
    SPELL_TRANSMOG_VISUAL_EFFECT = 372608
};

static uint8 OutfitSlotToEquipmentSlot(int8 outfitSlot)
{
    switch (outfitSlot)
    {
        case 0:  return EQUIPMENT_SLOT_HEAD;
        case 1:  return EQUIPMENT_SLOT_SHOULDERS;   // Primary shoulder
        case 2:  return EQUIPMENT_SLOT_SHOULDERS;   // Secondary shoulder (right side)
        case 3:  return EQUIPMENT_SLOT_BACK;        // Cloak
        case 4:  return EQUIPMENT_SLOT_CHEST;
        case 5:  return EQUIPMENT_SLOT_TABARD;
        case 6:  return EQUIPMENT_SLOT_BODY;        // Shirt
        case 7:  return EQUIPMENT_SLOT_WRISTS;
        case 8:  return EQUIPMENT_SLOT_HANDS;       // Gloves
        case 9:  return EQUIPMENT_SLOT_WAIST;       // Belt
        case 10: return EQUIPMENT_SLOT_LEGS;        // Pants
        case 11: return EQUIPMENT_SLOT_FEET;        // Boots
        case 12: return EQUIPMENT_SLOT_MAINHAND;
        case 13: return EQUIPMENT_SLOT_OFFHAND;
        default: return EQUIPMENT_SLOT_END;
    }
}

void WorldSession::HandleTransmogOutfitUpdateSlots(WorldPackets::Transmogrification::TransmogOutfitUpdateSlots& packet)
{
    Player* player = GetPlayer();

    // NPC validation - optional for outfit right-click apply
    bool hasNpc = player->GetNPCIfCanInteractWith(packet.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER, UNIT_NPC_FLAG_2_NONE) != nullptr;
    if (!hasNpc && !packet.Npc.IsEmpty())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitUpdateSlots - {} not found or player can't interact with it.", packet.Npc.ToString());
        return;
    }

    uint32 outfitID = uint32(packet.OutfitID);

    // Apply transmogs to equipped items
    int64 cost = 0;
    std::vector<std::pair<Item*, uint32>> pendingTransmogs;
    std::vector<std::pair<Item*, uint32>> pendingSecondaryTransmogs; // secondary shoulder
    std::vector<std::pair<Item*, uint32>> pendingIllusions;
    std::vector<Item*> resetAppearanceItems;
    std::vector<Item*> resetIllusionItems;
    std::vector<uint32> bindAppearances;

    for (auto const& outfitSlot : packet.Slots)
    {
        bool isSecondary = (outfitSlot.Slot == 2); // Secondary shoulder

        if (outfitSlot.Slot >= 12 && outfitSlot.SlotOption != 1 && outfitSlot.SlotOption != 2)
            continue;

        // For base armor slots, only accept SlotOption 0
        if (outfitSlot.Slot < 12 && outfitSlot.SlotOption != 0)
            continue;

        uint8 equipSlot = OutfitSlotToEquipmentSlot(outfitSlot.Slot);
        if (equipSlot >= EQUIPMENT_SLOT_END)
            continue;

        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipSlot);
        if (!item)
            continue;

        // Process appearance
        if (outfitSlot.AppearanceDisplayType != 0 && outfitSlot.AppearanceDisplayType != 4 && outfitSlot.ItemModifiedAppearanceID > 0)
        {
            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(outfitSlot.ItemModifiedAppearanceID);
            if (!itemModifiedAppearance)
                continue;

            auto [hasAppearance, isTemporary] = GetCollectionMgr()->HasItemAppearance(outfitSlot.ItemModifiedAppearanceID);
            if (!hasAppearance)
                continue;

            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID);
            if (!itemTemplate)
                continue;

            if (isSecondary)
            {
                pendingSecondaryTransmogs.push_back({ item, outfitSlot.ItemModifiedAppearanceID });
            }
            else
            {
                pendingTransmogs.push_back({ item, outfitSlot.ItemModifiedAppearanceID });
            }

            if (isTemporary)
                bindAppearances.push_back(outfitSlot.ItemModifiedAppearanceID);

            cost += item->GetSellPrice(player);
        }
        else if (outfitSlot.AppearanceDisplayType == 0 || outfitSlot.AppearanceDisplayType == 4)
        {
            resetAppearanceItems.push_back(item);
        }

        // Process illusion
        if (outfitSlot.SpellItemEnchantmentID > 0)
        {
            if (equipSlot != EQUIPMENT_SLOT_MAINHAND && equipSlot != EQUIPMENT_SLOT_OFFHAND)
                continue;

            TransmogIllusionEntry const* illusion = sDB2Manager.GetTransmogIllusionForEnchantment(outfitSlot.SpellItemEnchantmentID);
            if (!illusion)
                continue;

            if (!ConditionMgr::IsPlayerMeetingCondition(player, illusion->UnlockConditionID))
                continue;

            pendingIllusions.push_back({ item, outfitSlot.SpellItemEnchantmentID });
            cost += illusion->TransmogCost;
        }
        else
        {
            if (equipSlot == EQUIPMENT_SLOT_MAINHAND || equipSlot == EQUIPMENT_SLOT_OFFHAND)
                resetIllusionItems.push_back(item);
        }
    }

    // Check cost
    if (!player->HasAuraType(SPELL_AURA_REMOVE_TRANSMOG_COST) && cost)
    {
        if (!player->HasEnoughMoney(cost))
            return;
        player->ModifyMoney(-cost);
    }

    // Reset appearances before applies so applies take priority
    for (Item* item : resetAppearanceItems)
    {
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, 0);
        item->SetState(ITEM_CHANGED, player);
        player->SetVisibleItemSlot(item->GetSlot(), item);
    }

    // Reset illusions before applies so applies take priority
    for (Item* item : resetIllusionItems)
    {
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, 0);
        item->SetState(ITEM_CHANGED, player);
        player->SetVisibleItemSlot(item->GetSlot(), item);
    }

    // Apply primary transmog appearances
    for (auto& [item, appearanceId] : pendingTransmogs)
    {
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, appearanceId);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, 0);
        player->SetVisibleItemSlot(item->GetSlot(), item);
        item->SetNotRefundable(player);
        item->ClearSoulboundTradeable(player);
        item->SetState(ITEM_CHANGED, player);
    }

    // Apply secondary shoulder transmog
    for (auto& [item, appearanceId] : pendingSecondaryTransmogs)
    {
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS, appearanceId);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, 0);
        item->SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, 0);
        player->SetVisibleItemSlot(item->GetSlot(), item);
        item->SetNotRefundable(player);
        item->ClearSoulboundTradeable(player);
        item->SetState(ITEM_CHANGED, player);
    }

    // Apply illusions after resets
    for (auto& [item, enchantId] : pendingIllusions)
    {
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, enchantId);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, 0);
        item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, 0);
        player->SetVisibleItemSlot(item->GetSlot(), item);
        item->SetNotRefundable(player);
        item->ClearSoulboundTradeable(player);
        item->SetState(ITEM_CHANGED, player);
    }

    for (uint32 itemModifiedAppearanceId : bindAppearances)
    {
        std::unordered_set<ObjectGuid> itemsProvidingAppearance = GetCollectionMgr()->GetItemsProvidingTemporaryAppearance(itemModifiedAppearanceId);
        for (ObjectGuid const& itemGuid : itemsProvidingAppearance)
        {
            if (Item* item = player->GetItemByGuid(itemGuid))
            {
                item->SetNotRefundable(player);
                item->ClearSoulboundTradeable(player);
                GetCollectionMgr()->AddItemAppearance(item);
            }
        }
    }

    // Save outfit preset to UpdateFields
    auto const& outfits = player->m_activePlayerData->TransmogOutfits;
    if (outfits.Get(outfitID))
    {
        auto outfitSetter = player->m_values.ModifyValue(&Player::m_activePlayerData)
            .ModifyValue(&UF::ActivePlayerData::TransmogOutfits, outfitID);

        for (uint32 i = 0; i < packet.Slots.size(); ++i)
        {
            auto const& clientSlot = packet.Slots[i];
            auto slotRef = outfitSetter.ModifyValue(&UF::TransmogOutfitData::Slots, i);

            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::Slot), clientSlot.Slot);
            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::SlotOption), clientSlot.SlotOption);
            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::ItemModifiedAppearanceID), clientSlot.ItemModifiedAppearanceID);
            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::AppearanceDisplayType), clientSlot.AppearanceDisplayType);
            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::SpellItemEnchantmentID), clientSlot.SpellItemEnchantmentID);
            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::IllusionDisplayType), clientSlot.IllusionDisplayType);
            player->SetUpdateFieldValue(slotRef.ModifyValue(&UF::TransmogOutfitSlotData::Flags), clientSlot.Flags);
        }
    }

    // Persist changes to _equipmentSets for DB save
    for (auto& [guid, eqSet] : player->_equipmentSets)
    {
        if (eqSet.Data.Type == EquipmentSetInfo::TRANSMOG && eqSet.Data.SetID == outfitID && eqSet.State != EQUIPMENT_SET_DELETED)
        {
            // Update appearances from the transmog items we just applied
            for (auto& [item, appearanceId] : pendingTransmogs)
                eqSet.Data.Appearances[item->GetSlot()] = int32(appearanceId);

            // Clear appearances for reset items
            for (Item* item : resetAppearanceItems)
                eqSet.Data.Appearances[item->GetSlot()] = 0;

            // Update enchants (illusions)
            for (auto& [item, enchantId] : pendingIllusions)
            {
                if (item->GetSlot() == EQUIPMENT_SLOT_MAINHAND)
                    eqSet.Data.Enchants[0] = int32(enchantId);
                else if (item->GetSlot() == EQUIPMENT_SLOT_OFFHAND)
                    eqSet.Data.Enchants[1] = int32(enchantId);
            }

            // Clear illusions for reset items
            for (Item* item : resetIllusionItems)
            {
                if (item->GetSlot() == EQUIPMENT_SLOT_MAINHAND)
                    eqSet.Data.Enchants[0] = 0;
                else if (item->GetSlot() == EQUIPMENT_SLOT_OFFHAND)
                    eqSet.Data.Enchants[1] = 0;
            }

            if (eqSet.State != EQUIPMENT_SET_NEW)
                eqSet.State = EQUIPMENT_SET_CHANGED;
            break;
        }
    }

    // Send confirmation packet
    WorldPackets::Transmogrification::TransmogOutfitSlotsUpdated response;
    response.OutfitID = packet.OutfitID;
    response.Slots = packet.Slots;
    SendPacket(response.Write());

    // Cast visual effect
    player->CastSpell(player, SPELL_TRANSMOG_VISUAL_EFFECT, true);
}

void WorldSession::HandleTransmogOutfitNew(WorldPackets::Transmogrification::TransmogOutfitNew& packet)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    // Validate the NPC interaction
    if (!player->GetNPCIfCanInteractWith(packet.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER, UNIT_NPC_FLAG_2_NONE))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitNew - Player {} tried to create a new outfit without interacting with a transmogrifier.", player->GetName());
        return;
    }

    TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitNew - Player {} creating new outfit '{}' with Icon {}", player->GetName(), packet.Name, packet.Icon);

    // Find the next available Outfit ID. Outfit 1 is the default, so we start at 2.
    // Access existing outfits to find the max ID
    auto const& outfits = player->m_activePlayerData->TransmogOutfits;
    uint32 nextOutfitID = 2;
    for (auto const& [key, entry] : outfits)
    {
        if (key >= nextOutfitID)
            nextOutfitID = key + 1;
    }

    // Cap at 10 outfits
    if (nextOutfitID > MAX_TRANSMOG_OUTFITS)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitNew - Player {} already has maximum outfits.", player->GetName());
        return;
    }

    // Create the new outfit entry using UpdateField API
    {
        auto outfitSetter = player->m_values.ModifyValue(&Player::m_activePlayerData)
            .ModifyValue(&UF::ActivePlayerData::TransmogOutfits, nextOutfitID);

        player->SetUpdateFieldValue(outfitSetter.ModifyValue(&UF::TransmogOutfitData::Id), nextOutfitID);
        player->SetUpdateFieldValue(outfitSetter.ModifyValue(&UF::TransmogOutfitData::Flags), uint32(0));

        // OutfitInfo
        auto outfitInfo = outfitSetter.ModifyValue(&UF::TransmogOutfitData::OutfitInfo);
        player->SetUpdateFieldValue(outfitInfo.ModifyValue(&UF::TransmogOutfitDataInfo::SetType), uint8(1));
        player->SetUpdateFieldValue(outfitInfo.ModifyValue(&UF::TransmogOutfitDataInfo::Name), packet.Name);
        player->SetUpdateFieldValue(outfitInfo.ModifyValue(&UF::TransmogOutfitDataInfo::Icon), packet.Icon);
        player->SetUpdateFieldValue(outfitInfo.ModifyValue(&UF::TransmogOutfitDataInfo::SituationsEnabled), true);

        // Initialize situations (retail has 5 entries)
        static const uint32 situationIDs[] = { 1, 3, 13, 18, 20 };
        auto sitSetter = outfitSetter.ModifyValue(&UF::TransmogOutfitData::Situations);
        for (uint32 sitId : situationIDs)
        {
            auto sit = player->AddDynamicUpdateFieldValue(sitSetter);
            sit.ModifyValue(&UF::TransmogOutfitSituationInfo::SituationID).SetValue(sitId);
            sit.ModifyValue(&UF::TransmogOutfitSituationInfo::SpecID).SetValue(uint32(0));
            sit.ModifyValue(&UF::TransmogOutfitSituationInfo::LoadoutID).SetValue(uint32(0));
            sit.ModifyValue(&UF::TransmogOutfitSituationInfo::EquipmentSetID).SetValue(uint32(0));
        }

        // Populate 30 slots with current gear (matching _LoadTransmogOutfits layout)
        // Slots 0-11: armor, Slots 12-20: MainHand sub-slots, Slots 21-29: OffHand sub-slots
        struct SlotDef { int8 slot; uint8 slotOption; uint8 equipSlot; };
        static const SlotDef fullSlotLayout[30] =
        {
            { 0,  0, EQUIPMENT_SLOT_HEAD },
            { 1,  0, EQUIPMENT_SLOT_SHOULDERS },
            { 2,  0, EQUIPMENT_SLOT_SHOULDERS },   // Secondary shoulder
            { 3,  0, EQUIPMENT_SLOT_BACK },
            { 4,  0, EQUIPMENT_SLOT_CHEST },
            { 5,  0, EQUIPMENT_SLOT_TABARD },
            { 6,  0, EQUIPMENT_SLOT_BODY },         // Shirt
            { 7,  0, EQUIPMENT_SLOT_WRISTS },
            { 8,  0, EQUIPMENT_SLOT_HANDS },
            { 9,  0, EQUIPMENT_SLOT_WAIST },
            { 10, 0, EQUIPMENT_SLOT_LEGS },
            { 11, 0, EQUIPMENT_SLOT_FEET },
            // MainHand weapon sub-slots
            { 12, 1,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 6,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 2,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 3,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 7,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 8,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 9,  EQUIPMENT_SLOT_MAINHAND },
            { 12, 10, EQUIPMENT_SLOT_MAINHAND },
            { 12, 11, EQUIPMENT_SLOT_MAINHAND },
            // OffHand weapon sub-slots
            { 13, 1,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 6,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 7,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 5,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 4,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 8,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 9,  EQUIPMENT_SLOT_OFFHAND },
            { 13, 10, EQUIPMENT_SLOT_OFFHAND },
            { 13, 11, EQUIPMENT_SLOT_OFFHAND },
        };

        auto slotsSetter = outfitSetter.ModifyValue(&UF::TransmogOutfitData::Slots);
        for (uint32 i = 0; i < MAX_TRANSMOG_OUTFIT_SLOTS; ++i)
        {
            auto slotRef = player->AddDynamicUpdateFieldValue(slotsSetter);
            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::Slot).SetValue(int8(fullSlotLayout[i].slot));
            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::SlotOption).SetValue(uint8(fullSlotLayout[i].slotOption));

            uint32 appearanceId = 0;
            uint32 enchantId = 0;
            uint8 displayType = 0;
            uint8 illusionDisplayType = 0;

            if (fullSlotLayout[i].slotOption == 0)
            {
                Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, fullSlotLayout[i].equipSlot);
                if (pItem)
                {
                    appearanceId = pItem->GetVisibleModifiedAppearanceId(player);
                    displayType = 1;
                }
            }
            else if (fullSlotLayout[i].slotOption == 1)
            {
                Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, fullSlotLayout[i].equipSlot);
                if (pItem)
                {
                    appearanceId = pItem->GetVisibleModifiedAppearanceId(player);
                    displayType = 2;
                    illusionDisplayType = 2;

                    // Read current illusion from the item so it's saved with the outfit
                    enchantId = pItem->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS);
                    if (!enchantId)
                    {
                        // Check per-spec illusion if all-specs is empty
                        static const ItemModifier illusionBySpec[] = {
                            ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1,
                            ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2,
                            ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3,
                            ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4,
                            ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5,
                        };
                        uint8 spec = player->GetActiveTalentGroup();
                        if (spec < 5)
                            enchantId = pItem->GetModifier(illusionBySpec[spec]);
                    }
                }
            }
            else if (fullSlotLayout[i].slotOption >= 8)
            {
                displayType = 4;
                illusionDisplayType = 4;
            }

            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::ItemModifiedAppearanceID).SetValue(appearanceId);
            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::AppearanceDisplayType).SetValue(displayType);
            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::SpellItemEnchantmentID).SetValue(enchantId);
            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::IllusionDisplayType).SetValue(illusionDisplayType);
            slotRef.ModifyValue(&UF::TransmogOutfitSlotData::Flags).SetValue(uint32(0));
        }
    }

    // Persist to database via _equipmentSets
    {
        EquipmentSetInfo eqSet;
        eqSet.Data.Type = EquipmentSetInfo::TRANSMOG;
        eqSet.Data.Guid = sObjectMgr->GenerateEquipmentSetGuid();
        eqSet.Data.SetID = nextOutfitID;
        eqSet.Data.SetName = packet.Name;
        eqSet.Data.SetIcon = std::to_string(packet.Icon);
        eqSet.Data.IgnoreMask = 0;
        eqSet.State = EQUIPMENT_SET_NEW;

        // Populate appearances from current gear
        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
        {
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                eqSet.Data.Appearances[slot] = pItem->GetVisibleModifiedAppearanceId(player);
            else
                eqSet.Data.Appearances[slot] = 0;
        }

        // Populate enchants (illusions) from main hand and off hand
        for (uint8 i = 0; i < 2; ++i)
        {
            uint8 weaponSlot = (i == 0) ? EQUIPMENT_SLOT_MAINHAND : EQUIPMENT_SLOT_OFFHAND;
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, weaponSlot))
            {
                uint32 illusion = pItem->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS);
                if (!illusion)
                {
                    static const ItemModifier illusionBySpec[] = {
                        ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1,
                        ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2,
                        ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3,
                        ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4,
                        ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5,
                    };
                    uint8 spec = player->GetActiveTalentGroup();
                    if (spec < 5)
                        illusion = pItem->GetModifier(illusionBySpec[spec]);
                }
                eqSet.Data.Enchants[i] = int32(illusion);
            }
            else
                eqSet.Data.Enchants[i] = 0;
        }

        player->_equipmentSets[eqSet.Data.Guid] = eqSet;
    }

    TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitNew - Created outfit {} for player {}.", nextOutfitID, player->GetName());

    // Send confirmation packet back to the client
    WorldPackets::Transmogrification::TransmogOutfitNewEntryAdded response;
    response.OutfitID = nextOutfitID;
    SendPacket(response.Write());
}

void WorldSession::HandleClearNewAppearance(WorldPackets::Transmogrification::ClearNewAppearance& packet)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    // This is purely a visual "badge" clearing from the client UI.
    // The client sends this when the player hovers over a "New" item in the transmog collection.
    // We don't need to save this to the database, as the retail client manages its own local cache
    // for what has been "seen" across sessions, or it just reads the collection.
    TC_LOG_DEBUG("network", "WORLD: HandleClearNewAppearance - Player {} cleared 'new' flag for appearance {}", player->GetName(), packet.ItemModifiedAppearanceID);
}

void WorldSession::HandleTransmogOutfitUpdateInfo(WorldPackets::Transmogrification::TransmogOutfitUpdateInfo& packet)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    // Validate interaction
    if (!player->GetNPCIfCanInteractWith(packet.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER, UNIT_NPC_FLAG_2_NONE))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitUpdateInfo - Player {} tried to update outfit info without interacting with a transmogrifier.", player->GetName());
        return;
    }

    uint32 outfitID = uint32(packet.OutfitID);
    TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitUpdateInfo - Player {} updating outfit {} to name '{}', icon {}", player->GetName(), outfitID, packet.Name, packet.Icon);

    // Check if the outfit exists using the public Get() API
    auto const& outfits = player->m_activePlayerData->TransmogOutfits;
    if (!outfits.Get(outfitID))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogOutfitUpdateInfo - Player {} tried to update non-existent outfit {}.", player->GetName(), outfitID);
        return;
    }

    // Update Name and Icon using UpdateField API
    {
        auto outfitSetter = player->m_values.ModifyValue(&Player::m_activePlayerData)
            .ModifyValue(&UF::ActivePlayerData::TransmogOutfits, outfitID);

        auto outfitInfo = outfitSetter.ModifyValue(&UF::TransmogOutfitData::OutfitInfo);
        player->SetUpdateFieldValue(outfitInfo.ModifyValue(&UF::TransmogOutfitDataInfo::Name), packet.Name);
        player->SetUpdateFieldValue(outfitInfo.ModifyValue(&UF::TransmogOutfitDataInfo::Icon), packet.Icon);
    }

    // Send confirmation
    WorldPackets::Transmogrification::TransmogOutfitInfoUpdated response;
    response.OutfitID = outfitID;
    SendPacket(response.Write());
}

