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

#include "Transmogrification.h"
#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "GossipDef.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "QueryResult.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>

#define GTS session->GetTrinityString

class CS_Transmogrification : public CreatureScript
{
public:
    CS_Transmogrification() : CreatureScript("Creature_Transmogrify") { }

    class TransmogAI : public ScriptedAI
    {
    public:
        TransmogAI(Creature* creature) : ScriptedAI(creature) {}

        struct Timed : public BasicEvent
        {
            // This timed event tries to fix modify money breaking gossip
            // This event closes the gossip menu and on the second player update tries to open the next menu
            Timed(Player* player, Creature* creature, uint32 sender, uint32 action) : guid(creature->GetGUID()), player(player), sender(sender), action(action), triggered(false)
            {
                CloseGossipMenuFor(player);
                player->m_Events.AddEvent(this, player->m_Events.CalculateTime(Milliseconds(1)));
            }

            bool Execute(uint64, uint32) override
            {
                if (!triggered)
                {
                    triggered = true;
                    player->m_Events.AddEvent(this, player->m_Events.CalculateTime(Milliseconds(1)));
                    return false;
                }
                if (Creature* creature = player->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_GOSSIP))
                    OnGossipSelect(player, creature, sender, action);
                return true;
            }

            ObjectGuid guid;
            Player* player;
            uint32 sender;
            uint32 action;
            bool triggered;
        };

        bool OnGossipHello(Player* player) override
        {
            return OnGossipHello(player, me);
        }

        static bool OnGossipHello(Player* player, Creature* creature)
        {
            WorldSession* session = player->GetSession();
            if (sTransmogrification->EnableTransmogInfo)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-18:0|tHow transmogrification works", EQUIPMENT_SLOT_END + 9, 0);
            for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
            {
                if (const char* slotName = sTransmogrification->GetSlotName(slot, session))
                {
                    Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
                    uint32 entry = newItem ? newItem->transmog : 0;
                    std::string icon = entry ? sTransmogrification->GetItemIcon(entry, 30, 30, -18, 0) : sTransmogrification->GetSlotIcon(slot, 30, 30, -18, 0);
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, icon + std::string(slotName), EQUIPMENT_SLOT_END, slot);
                }
            }
#ifdef PRESETS
            if (sTransmogrification->EnableSets)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/RAIDFRAME/UI-RAIDFRAME-MAINASSIST:30:30:-18:0|tManage sets", EQUIPMENT_SLOT_END + 4, 0);
#endif
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tRemove all transmogrifications", EQUIPMENT_SLOT_END + 2, 0, "Remove transmogrifications from all equipped items?", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", EQUIPMENT_SLOT_END + 1, 0);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menu_id*/, uint32 gossipListId) override
        {
            uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            return OnGossipSelect(player, me, sender, action);
        }

        static bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            ClearGossipMenuFor(player);
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
                                if (!newItem->transmog)
                                    continue;
                                newItem->transmog = 0;
                                newItem->SetState(ITEM_CHANGED, player);
                                sTransmogrification->UpdateItem(player, newItem);
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
                            if (newItem->transmog)
                            {
                                newItem->transmog = 0;
                                newItem->SetState(ITEM_CHANGED, player);
                                sTransmogrification->UpdateItem(player, newItem);
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
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-18:0|tHow sets work", EQUIPMENT_SLOT_END + 10, 0);

                        if (!player->presetMap.empty())
                        {
                            for (PresetMapType::const_iterator it = player->presetMap.begin(); it != player->presetMap.end(); ++it)
                                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|t" + it->second.name, EQUIPMENT_SLOT_END + 6, it->first);

                            if (player->presetMap.size() < sTransmogrification->MaxSets)
                                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set", EQUIPMENT_SLOT_END + 8, 0);
                        }
                        else
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set", EQUIPMENT_SLOT_END + 8, 0);
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);
                        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
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
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(it2->second, 30, 30, -18, 0) + sTransmogrification->GetItemLink(it2->second, session), sender, action);

                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|tUse set", EQUIPMENT_SLOT_END + 5, action, "Using this set for transmogrify will bind transmogrified items to you and make them non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + it->second.name, 0, false);
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Opaque:30:30:-18:0|tDelete set", EQUIPMENT_SLOT_END + 7, action, "Are you sure you want to delete " + it->second.name + "?", 0, false);
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 4, 0);
                        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    } break;
                case EQUIPMENT_SLOT_END + 7: // Delete preset
                    {
                        if (!sTransmogrification->EnableSets)
                        {
                            OnGossipHello(player, creature);
                            return true;
                        }
                        // action = presetID

                        auto it = player->presetMap.find(action);
                        if (it != player->presetMap.end())
                        {
                            CharacterDatabase.PExecute("DELETE FROM `custom_transmogrification_sets` WHERE `Owner` = %u AND `PresetID` = %u", player->GetGUID().GetCounter(), uint32(action));
                            player->presetMap.erase(it);
                        }

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
                                uint32 entry = newItem->transmog;
                                if (!entry)
                                    continue;
                                const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
                                if (!temp)
                                    continue;
                                if (!sTransmogrification->SuitableForTransmogrification(player, temp)) // no need to check?
                                    continue;
                                cost += sTransmogrification->GetSpecialPrice(temp);
                                canSave = true;
                                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(entry, 30, 30, -18, 0) + sTransmogrification->GetItemLink(entry, session), EQUIPMENT_SLOT_END + 8, 0);
                            }
                        }
                        if (canSave)
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set", 0, 0, "Insert set name", cost*sTransmogrification->SetCostModifier + sTransmogrification->SetCopperCost, true);
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", sender, action);
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 4, 0);
                        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    } break;
                case EQUIPMENT_SLOT_END + 10: // Set info
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 4, 0);
                        SendGossipMenuFor(player, sTransmogrification->SetNpcText, creature->GetGUID());
                    } break;
#endif
                case EQUIPMENT_SLOT_END + 9: // Transmog info
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);
                        SendGossipMenuFor(player, sTransmogrification->TransmogNpcText, creature->GetGUID());
                    } break;
                default: // Transmogrify
                    {
                        if (!sender && !action)
                        {
                            OnGossipHello(player, creature);
                            return true;
                        }
                        // sender = slot, action = display
                        TransmogTrinityStrings res = sTransmogrification->Transmogrify(player, ObjectGuid(HighGuid::Item, 0, action), sender);
                        if (res == LANG_ERR_TRANSMOG_OK)
                            session->SendAreaTriggerMessage("%s", GTS(LANG_ERR_TRANSMOG_OK));
                        else
                            session->SendNotification(res);
                        // OnGossipSelect(player, EQUIPMENT_SLOT_END, sender);
                        new Timed(player, creature, EQUIPMENT_SLOT_END, sender);
                    } break;
            }
            return true;
        }

#ifdef PRESETS
        bool OnGossipSelectCode(Player* player, uint32 /*menu_id*/, uint32 gossipListId, const char* code) override
        {
            uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            return GossipSelectCode(player, me, sender, action, code);
        }

        bool GossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
        {
            ClearGossipMenuFor(player);
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
                    uint32 entry = newItem->transmog;
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
                        std::ostringstream ss;
                        for (auto const & k_v : items)
                            ss << uint32(k_v.first) << ' ' << k_v.second << ' ';
                        CharacterDatabase.PExecute("REPLACE INTO `custom_transmogrification_sets` (`Owner`, `PresetID`, `SetName`, `SetData`) VALUES (%u, %u, \"%s\", \"%s\")", player->GetGUID().GetCounter(), uint32(presetID), name.c_str(), ss.str().c_str());
                    }
                }
            }

            // OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
            new Timed(player, creature, EQUIPMENT_SLOT_END + 4, 0);
            return true;
        }
#endif

        static void ShowTransmogItems(Player* player, Creature* creature, uint8 slot) // Only checks bags while can use an item from anywhere in inventory
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
                    if (oldItem->transmog == newItem->GetEntry())
                        continue;
                    ++limit;
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(newItem->GetEntry(), 30, 30, -18, 0) + sTransmogrification->GetItemLink(newItem, session), slot, newItem->GetGUID().GetCounter(), "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->GetItemIcon(newItem->GetEntry(), 40, 40, -15, -10) + sTransmogrification->GetItemLink(newItem, session) + ss.str(), price, false);
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
                        if (oldItem->transmog == newItem->GetEntry())
                            continue;
                        ++limit;
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(newItem->GetEntry(), 30, 30, -18, 0) + sTransmogrification->GetItemLink(newItem, session), slot, newItem->GetGUID().GetCounter(), "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->GetItemIcon(newItem->GetEntry(), 40, 40, -15, -10) + sTransmogrification->GetItemLink(newItem, session) + ss.str(), price, false);
                    }
                }
            }

            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tRemove transmogrification", EQUIPMENT_SLOT_END + 3, slot, "Remove transmogrification from the slot?", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", EQUIPMENT_SLOT_END, slot);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", EQUIPMENT_SLOT_END + 1, 0);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new TransmogAI(creature);
    }
};

class PS_Transmogrification : public PlayerScript
{
public:
    PS_Transmogrification() : PlayerScript("PS_Transmogrification") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
#ifdef PRESETS
        if (sTransmogrification->EnableSets)
            sTransmogrification->LoadPlayerSets(player);
#endif
    }
};

class WS_Transmogrification : public WorldScript
{
public:
    WS_Transmogrification() : WorldScript("WS_Transmogrification") { }

    void OnConfigLoad(bool reload) override
    {
        sTransmogrification->LoadConfig(reload);
    }

    void OnStartup() override
    {
        sTransmogrification->LoadConfig(false);
    }
};

void AddSC_Transmogrification()
{
    new WS_Transmogrification();
    new PS_Transmogrification();
    new CS_Transmogrification();
}
