/*
6.1
Transmogrification 3.3.5a - Gossip menu
By Rochet2

ScriptName for NPC:
Creature_Transmogrify

TODO:
Fix the cost formula
-- Too much data handling, use default costs

Cant transmogrify rediculus items // Foereaper: would be fun to stab people with a fish
-- Cant think of any good way to handle this easily, could rip flagged items from cata DB
*/

#include "ScriptPCH.h"
#include "Config.h"
#include "Language.h"
#include "Transmogrification.h"

#define GTS session->GetTrinityString

namespace
{
    class CS_Transmogrification : public CreatureScript
    {
    public:
        CS_Transmogrification() : CreatureScript("Creature_Transmogrify") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            WorldSession* session = player->GetSession();
            if (sTransmogrification->EnableTransmogInfo)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-18:0|tHow transmogrification works", EQUIPMENT_SLOT_END + 9, 0);
            for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
            {
                if (const char* slotName = sTransmogrification->GetSlotName(slot, session))
                {
                    Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
                    uint32 entry = newItem ? sTransmogrification->GetFakeEntry(newItem) : 0;
                    std::string icon = entry ? sTransmogrification->GetItemIcon(entry, 30, 30, -18, 0) : sTransmogrification->GetSlotIcon(slot, 30, 30, -18, 0);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, icon + std::string(slotName), EQUIPMENT_SLOT_END, slot);
                }
            }
#ifdef PRESETS
            if (sTransmogrification->EnableSets)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/RAIDFRAME/UI-RAIDFRAME-MAINASSIST:30:30:-18:0|tManage sets", EQUIPMENT_SLOT_END + 4, 0);
#endif
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tRemove all transmogrifications", EQUIPMENT_SLOT_END + 2, 0, "Remove transmogrifications from all equipped items?", 0, false);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", EQUIPMENT_SLOT_END + 1, 0);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();
            WorldSession* session = player->GetSession();
            switch (sender)
            {
                case EQUIPMENT_SLOT_END: // Show items you can use
                    ShowTransmogItems(player, creature, action);
                    break;
                case EQUIPMENT_SLOT_END + 1: // Main menu
                    OnGossipHello(player, creature);
                    break;
                case EQUIPMENT_SLOT_END + 2: // Remove Transmogrifications
                {
                    bool removed = false;
                    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                    {
                        if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                        {
                            if (!sTransmogrification->GetFakeEntry(newItem))
                                continue;
                            sTransmogrification->DeleteFakeEntry(player, newItem);
                            removed = true;
                        }
                    }
                    if (removed)
                        session->SendAreaTriggerMessage("%s", GTS(LANG_ERR_UNTRANSMOG_OK));
                    else
                        session->SendNotification(LANG_ERR_UNTRANSMOG_NO_TRANSMOGS);
                    OnGossipHello(player, creature);
                } break;
                case EQUIPMENT_SLOT_END + 3: // Remove Transmogrification from single item
                {
                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action))
                    {
                        if (sTransmogrification->GetFakeEntry(newItem))
                        {
                            sTransmogrification->DeleteFakeEntry(player, newItem);
                            session->SendAreaTriggerMessage("%s", GTS(LANG_ERR_UNTRANSMOG_OK));
                        }
                        else
                            session->SendNotification(LANG_ERR_UNTRANSMOG_NO_TRANSMOGS);
                    }
                    OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, action);
                } break;
#ifdef PRESETS
                case EQUIPMENT_SLOT_END + 4: // Presets menu
                {
                    if (!sTransmogrification->EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    if (sTransmogrification->EnableSetInfo)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-18:0|tHow sets work", EQUIPMENT_SLOT_END + 10, 0);

                    if (!player->presetMap.empty())
                    {
                        for (PresetMapType::const_iterator it = player->presetMap.begin(); it != player->presetMap.end(); ++it)
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|t" + it->second.name, EQUIPMENT_SLOT_END + 6, it->first);

                        if (player->presetMap.size() < sTransmogrification->MaxSets)
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set", EQUIPMENT_SLOT_END + 8, 0);
                    }
                    else
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set", EQUIPMENT_SLOT_END + 8, 0);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                } break;
                case EQUIPMENT_SLOT_END + 5: // Use preset
                {
                    if (!sTransmogrification->EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // action = presetID

                    PresetMapType::const_iterator it = player->presetMap.find(action);
                    if (it != player->presetMap.end())
                    {
                        for (PresetslotMapType::const_iterator it2 = it->second.slotMap.begin(); it2 != it->second.slotMap.end(); ++it2)
                            if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, it2->first))
                                sTransmogrification->PresetTransmog(player, item, it2->second, it2->first);
                    }
                    OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 6, action);
                } break;
                case EQUIPMENT_SLOT_END + 6: // view preset
                {
                    if (!sTransmogrification->EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // action = presetID

                    PresetMapType::const_iterator it = player->presetMap.find(action);
                    if (it == player->presetMap.end())
                    {
                        OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
                        return true;
                    }

                    for (PresetslotMapType::const_iterator it2 = it->second.slotMap.begin(); it2 != it->second.slotMap.end(); ++it2)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(it2->second, 30, 30, -18, 0) + sTransmogrification->GetItemLink(it2->second, session), sender, action);

                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|tUse set", EQUIPMENT_SLOT_END + 5, action, "Using this set for transmogrify will bind transmogrified items to you and make them non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + it->second.name, 0, false);
                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Opaque:30:30:-18:0|tDelete set", EQUIPMENT_SLOT_END + 7, action, "Are you sure you want to delete " + it->second.name + "?", 0, false);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 4, 0);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                } break;
                case EQUIPMENT_SLOT_END + 7: // Delete preset
                {
                    if (!sTransmogrification->EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // action = presetID

                    player->presetMap.erase(action);

                    OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
                } break;
                case EQUIPMENT_SLOT_END + 8: // Save preset
                {
                    if (!sTransmogrification->EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }

                    if (player->presetMap.size() >= sTransmogrification->MaxSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }

                    uint32 cost = 0;
                    bool canSave = false;
                    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                    {
                        if (!sTransmogrification->GetSlotName(slot, session))
                            continue;
                        if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                        {
                            uint32 entry = sTransmogrification->GetFakeEntry(newItem);
                            if (!entry)
                                continue;
                            const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
                            if (!temp)
                                continue;
                            if (!sTransmogrification->SuitableForTransmogrification(player, temp)) // no need to check?
                                continue;
                            cost += sTransmogrification->GetSpecialPrice(temp);
                            canSave = true;
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(entry, 30, 30, -18, 0) + sTransmogrification->GetItemLink(entry, session), EQUIPMENT_SLOT_END + 8, 0);
                        }
                    }
                    if (canSave)
                        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set", 0, 0, "Insert set name", cost*sTransmogrification->SetCostModifier + sTransmogrification->SetCopperCost, true);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", sender, action);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 4, 0);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                } break;
                case EQUIPMENT_SLOT_END + 10: // Set info
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 4, 0);
                    player->SEND_GOSSIP_MENU(sTransmogrification->SetNpcText, creature->GetGUID());
                } break;
#endif
                case EQUIPMENT_SLOT_END + 9: // Transmog info
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);
                    player->SEND_GOSSIP_MENU(sTransmogrification->TransmogNpcText, creature->GetGUID());
                } break;
                default: // Transmogrify
                {
                    if (!sender && !action)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // sender = slot, action = display
                    TransmogTrinityStrings res = sTransmogrification->Transmogrify(player, ObjectGuid(HIGHGUID_ITEM, 0, action), sender);
                    if (res == LANG_ERR_TRANSMOG_OK)
                        session->SendAreaTriggerMessage("%s", GTS(LANG_ERR_TRANSMOG_OK));
                    else
                        session->SendNotification(res);
                    OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, sender);
                } break;
            }
            return true;
        }

#ifdef PRESETS
        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code) override
        {
            player->PlayerTalkClass->ClearMenus();
            if (sender || action)
                return true; // should never happen
            if (!sTransmogrification->EnableSets)
            {
                OnGossipHello(player, creature);
                return true;
            }

            // Allow only alnum
            std::string name = code;
            static const char* allowedcharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz _.,'1234567890";
            if (!name.length() || name.find_first_not_of(allowedcharacters) != std::string::npos)
            {
                player->GetSession()->SendNotification(LANG_PRESET_ERR_INVALID_NAME);
                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
                return true;
            }

            int32 cost = 0;
            PresetslotMapType items;
            for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
            {
                if (!sTransmogrification->GetSlotName(slot, player->GetSession()))
                    continue;
                if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                {
                    uint32 entry = sTransmogrification->GetFakeEntry(newItem);
                    if (!entry)
                        continue;
                    const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
                    if (!temp)
                        continue;
                    if (!sTransmogrification->SuitableForTransmogrification(player, temp))
                        continue;
                    cost += sTransmogrification->GetSpecialPrice(temp);
                    items[slot] = entry;
                }
            }

            if (!items.empty())
            {
                // transmogrified items were found to be saved
                cost *= sTransmogrification->SetCostModifier;
                cost += sTransmogrification->SetCopperCost;

                if (!player->HasEnoughMoney(cost))
                {
                    player->GetSession()->SendNotification(LANG_ERR_TRANSMOG_NOT_ENOUGH_MONEY);
                }
                else
                {
                    uint8 presetID = sTransmogrification->MaxSets;
                    if (player->presetMap.size() < sTransmogrification->MaxSets)
                    {
                        for (uint8 i = 0; i < sTransmogrification->MaxSets; ++i) // should never reach over max
                        {
                            if (player->presetMap.find(i) == player->presetMap.end())
                            {
                                presetID = i;
                                break;
                            }
                        }
                    }

                    if (presetID < sTransmogrification->MaxSets)
                    {
                        // Make sure code doesnt mess up SQL!
                        player->presetMap[presetID].name = name;
                        player->presetMap[presetID].slotMap = items;

                        if (cost)
                            player->ModifyMoney(-cost);
                    }
                }
            }

            OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
            return true;
        }
#endif

        void ShowTransmogItems(Player* player, Creature* creature, uint8 slot) // Only checks bags while can use an item from anywhere in inventory
        {
            WorldSession* session = player->GetSession();
            Item* oldItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
            if (oldItem)
            {
                uint32 limit = 0;
                uint32 price = sTransmogrification->GetSpecialPrice(oldItem->GetTemplate());
                price *= sTransmogrification->ScaledCostModifier;
                price += sTransmogrification->CopperCost;
                std::ostringstream ss;
                ss << std::endl;
                if (sTransmogrification->RequireToken)
                    ss << std::endl << std::endl << sTransmogrification->TokenAmount << " x " << sTransmogrification->GetItemLink(sTransmogrification->TokenEntry, session);

                for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
                {
                    if (limit >= MAX_OPTIONS)
                        break;
                    Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                    if (!newItem)
                        continue;
                    if (!sTransmogrification->CanTransmogrifyItemWithItem(player, oldItem->GetTemplate(), newItem->GetTemplate()))
                        continue;
                    if (sTransmogrification->GetFakeEntry(oldItem) == newItem->GetEntry())
                        continue;
                    ++limit;
                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(newItem->GetEntry(), 30, 30, -18, 0) + sTransmogrification->GetItemLink(newItem, session), slot, newItem->GetGUIDLow(), "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->GetItemIcon(newItem->GetEntry(), 40, 40, -15, -10) + sTransmogrification->GetItemLink(newItem, session) + ss.str(), price, false);
                }

                for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
                {
                    Bag* bag = player->GetBagByPos(i);
                    if (!bag)
                        continue;
                    for (uint32 j = 0; j < bag->GetBagSize(); ++j)
                    {
                        if (limit >= MAX_OPTIONS)
                            break;
                        Item* newItem = player->GetItemByPos(i, j);
                        if (!newItem)
                            continue;
                        if (!sTransmogrification->CanTransmogrifyItemWithItem(player, oldItem->GetTemplate(), newItem->GetTemplate()))
                            continue;
                        if (sTransmogrification->GetFakeEntry(oldItem) == newItem->GetEntry())
                            continue;
                        ++limit;
                        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(newItem->GetEntry(), 30, 30, -18, 0) + sTransmogrification->GetItemLink(newItem, session), slot, newItem->GetGUIDLow(), "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->GetItemIcon(newItem->GetEntry(), 40, 40, -15, -10) + sTransmogrification->GetItemLink(newItem, session) + ss.str(), price, false);
                    }
                }
            }

            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tRemove transmogrification", EQUIPMENT_SLOT_END + 3, slot, "Remove transmogrification from the slot?", 0, false);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", EQUIPMENT_SLOT_END, slot);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        }
    };
}

void AddSC_CS_Transmogrification()
{
    new CS_Transmogrification();
}
