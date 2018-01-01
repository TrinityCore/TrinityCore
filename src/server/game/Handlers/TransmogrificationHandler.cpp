/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "Player.h"
#include "TransmogrificationPackets.h"

void WorldSession::HandleTransmogrifyItems(WorldPackets::Transmogrification::TransmogrifyItems& transmogrifyItems)
{
    Player* player = GetPlayer();
    // Validate
    if (!player->GetNPCIfCanInteractWith(transmogrifyItems.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s not found or player can't interact with it.", transmogrifyItems.Npc.ToString().c_str());
        return;
    }

    int64 cost = 0;
    std::unordered_map<Item*, uint32> transmogItems;
    std::unordered_map<Item*, uint32> illusionItems;

    std::vector<Item*> resetAppearanceItems;
    std::vector<Item*> resetIllusionItems;
    std::vector<uint32> bindAppearances;

    for (WorldPackets::Transmogrification::TransmogrifyItem const& transmogItem : transmogrifyItems.Items)
    {
        // slot of the transmogrified item
        if (transmogItem.Slot >= EQUIPMENT_SLOT_END)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - Player (%s, name: %s) tried to transmogrify wrong slot (%u) when transmogrifying items.", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.Slot);
            return;
        }

        // transmogrified item
        Item* itemTransmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, transmogItem.Slot);
        if (!itemTransmogrified)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - Player (%s, name: %s) tried to transmogrify an invalid item in a valid slot (slot: %u).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.Slot);
            return;
        }

        if (transmogItem.ItemModifiedAppearanceID)
        {
            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(transmogItem.ItemModifiedAppearanceID);
            if (!itemModifiedAppearance)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify using invalid appearance (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.ItemModifiedAppearanceID);
                return;
            }

            bool hasAppearance, isTemporary;
            std::tie(hasAppearance, isTemporary) = GetCollectionMgr()->HasItemAppearance(transmogItem.ItemModifiedAppearanceID);
            if (!hasAppearance)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify using appearance he has not collected (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.ItemModifiedAppearanceID);
                return;
            }
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID);
            if (player->CanUseItem(itemTemplate) != EQUIP_ERR_OK)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify using appearance he can never use (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.ItemModifiedAppearanceID);
                return;
            }

            // validity of the transmogrification items
            if (!Item::CanTransmogrifyItemWithItem(itemTransmogrified, itemModifiedAppearance))
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s failed CanTransmogrifyItemWithItem (%u with appearance %d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), itemTransmogrified->GetEntry(), transmogItem.ItemModifiedAppearanceID);
                return;
            }

            transmogItems[itemTransmogrified] = transmogItem.ItemModifiedAppearanceID;
            if (isTemporary)
                bindAppearances.push_back(transmogItem.ItemModifiedAppearanceID);

            // add cost
            cost += itemTransmogrified->GetSpecialPrice();
        }
        else
            resetAppearanceItems.push_back(itemTransmogrified);

        if (transmogItem.SpellItemEnchantmentID)
        {
            if (transmogItem.Slot != EQUIPMENT_SLOT_MAINHAND && transmogItem.Slot != EQUIPMENT_SLOT_OFFHAND)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify illusion into non-weapon slot (%u).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.Slot);
                return;
            }

            SpellItemEnchantmentEntry const* illusion = sSpellItemEnchantmentStore.LookupEntry(transmogItem.SpellItemEnchantmentID);
            if (!illusion)
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify illusion using invalid enchant (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.SpellItemEnchantmentID);
                return;
            }

            if (!illusion->ItemVisual || !(illusion->Flags & ENCHANTMENT_COLLECTABLE))
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify illusion using not allowed enchant (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.SpellItemEnchantmentID);
                return;
            }

            if (PlayerConditionEntry const* condition = sPlayerConditionStore.LookupEntry(illusion->PlayerConditionID))
            {
                if (!sConditionMgr->IsPlayerMeetingCondition(player, condition))
                {
                    TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify illusion using not collected enchant (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.SpellItemEnchantmentID);
                    return;
                }
            }

            if (illusion->ScalingClassRestricted > 0 && uint8(illusion->ScalingClassRestricted) != player->getClass())
            {
                TC_LOG_DEBUG("network", "WORLD: HandleTransmogrifyItems - %s, Name: %s tried to transmogrify illusion using not allowed class enchant (%d).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), transmogItem.SpellItemEnchantmentID);
                return;
            }

            illusionItems[itemTransmogrified] = transmogItem.SpellItemEnchantmentID;
            cost += illusion->TransmogCost;
        }
        else
            resetIllusionItems.push_back(itemTransmogrified);
    }

    if (cost) // 0 cost if reverting look
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
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, transmogPair.second);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
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
            transmogrified->SetModifier(AppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], transmogPair.second);
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
            item->SetModifier(AppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], 0);
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
