/*
6.1
Transmogrification 3.3.5a - Gossip menu
By Rochet2

ScriptName for NPC:
Creature_Transmogrify

TODO:
- Find function / filter
- use item displays instead of item entries - similar menu selection like on retail where a display lists multiple names related to it
- make sure the system allows enchants only for correct weapons - Warrior will not have cloth items added to transmog list on retail
- More settings, for example restrict enchants somehow?
- For now, all enchants are enabled always. On retail some enchants are enabled by default and others come from items that bosses drop

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
#include "DBCStores.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "GossipDef.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SpellInfo.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>

std::array<uint32, 2> ENCHANT_SLOTS = {
    EQUIPMENT_SLOT_MAINHAND,
    EQUIPMENT_SLOT_OFFHAND,
};

const uint32 max_list_items = 100000; // absolute maximum amount of items in a list to paginate
const uint32 max_page_items = GOSSIP_MAX_MENU_ITEMS-4; // maximum amount of items in a page from a paginated list
const uint32 max_pages = (max_list_items / max_page_items) + 1; // Max amount of pages for a single paginated list

enum TransmogGossipSender
{
    // sender = EQUIPMENT_SLOT_X, action = transmog entry
    SENDER_TRANSMOG_START = EQUIPMENT_SLOT_START,
    SENDER_TRANSMOG_END = EQUIPMENT_SLOT_END,

    // action = 0 or transmog/enchant entry
    // sender = SENDER_PAGINATED_EQUIPMENT_START + (equipment_slot*max_pages) + page
    // sender = SENDER_PAGINATED_EQUIPMENT_START + ((EQUIPMENT_SLOT_END+1)*max_pages) + page // main hand enchant
    // sender = SENDER_PAGINATED_EQUIPMENT_START + ((EQUIPMENT_SLOT_END+2)*max_pages) + page // off hand enchant
    SENDER_PAGINATED_EQUIPMENT_START = SENDER_TRANSMOG_END,
    SENDER_PAGINATED_EQUIPMENT_END = SENDER_PAGINATED_EQUIPMENT_START + ((EQUIPMENT_SLOT_END - EQUIPMENT_SLOT_START)*max_pages),
    SENDER_PAGINATED_ENCHANT_START = SENDER_PAGINATED_EQUIPMENT_END,
    SENDER_PAGINATED_ENCHANT_END = SENDER_PAGINATED_ENCHANT_START + (ENCHANT_SLOTS.size()*max_pages),

    SENDER_SHOW_MAIN_MENU,
    SENDER_SHOW_ITEMS,
    SENDER_SHOW_ENCHANTS,
    SENDER_SHOW_SLOTS,
    SENDER_REVERT_ALL_TRANSMOG,
    SENDER_REMOVE_ALL_TRANSMOG,
    SENDER_REVERT_TRANSMOG,
    SENDER_REVERT_ENCHANT,
    SENDER_PRESET_LIST,
    SENDER_PRESET_USE,
    SENDER_PRESET_VIEW,
    SENDER_PRESET_DELETE,
    SENDER_PRESET_SAVE,
    SENDER_PRESET_INFO,
    SENDER_TRANSMOG_INFO,
    SENDER_TRANSMOG_SAVE,
};

enum TransmogGossipSenderCode
{
    SENDER_CODE_PRESET_SAVE,
    SENDER_CODE_PRESET_RENAME,
};

struct PageData
{
    PageData(uint32 page, uint32 total_actions)
    {
        start = page * max_page_items;
        end = std::min((page + 1) * max_page_items, total_actions);
        count = end - start;
        next = end < total_actions;
        prev = page > 0;
        ismainpage = page == 0;
        current_page = page + 1;
        total_pages = static_cast<decltype(total_pages)>(std::ceil(total_actions/static_cast<double>(max_page_items)));
    }
    uint32 start;
    uint32 end;
    uint32 count;
    uint32 current_page;
    uint32 total_pages;
    bool next;
    bool prev;
    bool ismainpage;
};

typedef std::function<void(Player* player, Creature* creature, uint32 base, uint32 page, uint32 action)> TransmogFunc;

struct PendingItemsCheck : public BasicEvent
{
    PendingItemsCheck(Player* player, Creature* creature) : guid(creature->GetGUID()), player(player)
    {
        ASSERT(player->pendingTransmogCheck == nullptr, "Only one PendingTransmogCheck should be active at one time");
        player->pendingTransmogCheck = this;
        player->m_Events.AddEvent(this, player->m_Events.CalculateTime(500ms));
    }

    bool Execute(uint64, uint32) override
    {
        auto pending_transmogs = Transmogrification::instance().GetPendingTransmogs(player);
        if (!pending_transmogs.empty()) {
            Creature const* creature = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, guid);
            if (creature && creature->IsWithinDistInMap(player, creature->GetCombatReach() + 4.0f + 50.0f))
            {
                if (lastNotSavedAlert < GameTime::GetGameTimeMS() && player->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_GOSSIP) == nullptr)
                {
                    lastNotSavedAlert = GameTime::GetGameTimeMS() + 2000;
                    player->GetSession()->SendNotification("You have not saved your transmogrifications!");
                }
                player->m_Events.AddEvent(this, player->m_Events.CalculateTime(500ms));
                return false;
            }
        }
        player->pendingTransmogCheck = nullptr;
        for (auto& pending : pending_transmogs)
            Transmogrification::instance().UpdateItem(player, std::get<Item*>(pending));
        return true;
    }

    ObjectGuid guid;
    Player* player;
    uint32 lastNotSavedAlert = 0;
};

class CS_Transmogrification : public CreatureScript
{
public:
    CS_Transmogrification() : CreatureScript("Creature_Transmogrify") { }

    class TransmogAI : public ScriptedAI
    {
    public:
        TransmogAI(Creature* creature) : ScriptedAI(creature) {}

        bool OnGossipHello(Player* player) override
        {
            return OnGossipHello(player, me);
        }

        bool OnGossipSelect(Player* player, uint32 /*menu_id*/, uint32 gossipListId) override
        {
            if (auto* gossipItem = player->PlayerTalkClass->GetGossipMenu().GetItem(gossipListId))
            {
                uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
                uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                return OnGossipSelect(player, me, sender, action, gossipItem->BoxMoney);
            }
            return OnGossipHello(player, me);
        }

        bool OnGossipSelectCode(Player* player, uint32 /*menu_id*/, uint32 gossipListId, const char* code) override
        {
            uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            return GossipSelectCode(player, me, sender, action, code);
        }

        static void AddItemTransmog(Player* player, Creature* creature, uint32 base, uint32 page, uint32 action, std::string const & name)
        {
            (void)creature;
            uint32 itementry = action;
            if (itementry == RemovePending)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tRemove pending transmogrification", SENDER_REVERT_TRANSMOG, base + page);
            else if (itementry == InvisibleEntry)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Vanish:30:30:-18:0|tHide item", base + page, InvisibleEntry);
            else if (itementry == NormalEntry)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Spell_Holy_Restoration:30:30:-18:0|tRestore original look", base + page, NormalEntry);
            else
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, Transmogrification::instance().GetItemIcon(itementry, 30, 30, -18, 0) + name, base + page, itementry);
        }

        static void AddItemEnchant(Player* player, Creature* creature, uint32 base, uint32 page, uint32 action, std::string const & name)
        {
            (void)creature;
            uint32 enchantentry = action;
            if (enchantentry == RemovePending)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tRemove pending enchant", SENDER_REVERT_ENCHANT, base + page);
            else if (enchantentry == InvisibleEntry)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Vanish:30:30:-18:0|tHide enchant", base + page, InvisibleEntry);
            else if (enchantentry == NormalEntry)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Spell_Holy_Restoration:30:30:-18:0|tRestore original look", base + page, NormalEntry);
            else
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, std::string("|TInterface/ICONS/INV_Enchant_FormulaGood_01:30:30:-18:0|t") + name, base + page, enchantentry);
        }

        // value in [min, max[
        static bool isbetween(uint32 value, uint32 min, uint32 max)
        {
            return value >= min && value < max;
        }

        static bool OnGossipHello(Player* player, Creature* creature)
        {
            WorldSession* session = player->GetSession();
            if (Transmogrification::instance().EnableTransmogInfo)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-18:0|tHow transmogrification works", SENDER_TRANSMOG_INFO, 0);
            for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
            {
                if (const char* slotName = Transmogrification::instance().GetSlotName(slot, session))
                {
                    Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
                    {
                        std::string status;
                        uint32 pending;
                        uint32 entry = newItem ? newItem->GetTransmog() : 0;
                        bool hasPending = Transmogrification::instance().HasPendingTransmog(player, slot, nullptr, &pending);
                        bool hasTransmog = newItem && newItem->GetTransmog() != 0;
                        if (hasTransmog)
                            status += " [transmog]";
                        if (hasPending)
                        {
                            entry = pending;
                            status += " [pending]";
                        }
                        std::string icon;
                        if (entry == InvisibleEntry)
                            icon = "|TInterface/ICONS/Ability_Vanish:30:30:-18:0|t";
                        else if (hasPending && entry == NormalEntry)
                            icon = "|TInterface/ICONS/Spell_Holy_Restoration:30:30:-18:0|t";
                        else
                            icon = entry ? Transmogrification::instance().GetItemIcon(entry, 30, 30, -18, 0) : Transmogrification::instance().GetSlotIcon(slot, 30, 30, -18, 0);
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, icon + std::string(slotName) + status, SENDER_SHOW_ITEMS, slot);
                    }

                    for (uint32 slotindex = 0; slotindex < ENCHANT_SLOTS.size(); ++slotindex)
                    {
                        if (slot == ENCHANT_SLOTS[slotindex])
                        {
                            std::string status;
                            uint32 pending;
                            uint32 entry = newItem ? newItem->GetEnchant() : 0;
                            bool hasPending = Transmogrification::instance().HasPendingEnchant(player, slot, nullptr, &pending);
                            bool hasTransmog = newItem && newItem->GetEnchant() != 0;
                            if (hasTransmog)
                                status += " [enchant]";
                            if (hasPending)
                            {
                                entry = pending;
                                status += " [pending]";
                            }
                            std::string icon;
                            if (entry == InvisibleEntry)
                                icon = "|TInterface/ICONS/Ability_Vanish:30:30:-18:0|t";
                            else if (hasPending && entry == NormalEntry)
                                icon = "|TInterface/ICONS/Spell_Holy_Restoration:30:30:-18:0|t";
                            else if (hasPending)
                                icon = "|TInterface/ICONS/INV_Scroll_06:30:30:-18:0|t";
                            else
                                icon = "|TInterface/ICONS/INV_Scroll_03:30:30:-18:0|t";
                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, icon + std::string(slotName) + " enchant" + status, SENDER_SHOW_ENCHANTS, slotindex);
                        }
                    }
                }
            }
            if (Transmogrification::instance().EnableSets)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/RAIDFRAME/UI-RAIDFRAME-MAINASSIST:30:30:-18:0|tManage sets", SENDER_PRESET_LIST, 0);
            {
                decltype(auto) pending = Transmogrification::instance().GetPendingTransmogs(player);
                int32 copperCost = Transmogrification::instance().CalculateTransmogCost(pending);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_EssenceCosmicGreater:30:30:-18:0|tSave pending transmogrifications", SENDER_TRANSMOG_SAVE, 0, "All equipped items with pending transmogrifications will save their appearance and are made soulbound, non-refundable and non-tradeable.\n\nDo you wish to continue?", copperCost, false);
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Enchant_Disenchant:30:30:-18:0|tCancel pending transmogrifications", SENDER_REVERT_ALL_TRANSMOG, 0, "Cancel pending transmogrifications from all equipped items?", 0, false);
            }
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Spell_Holy_Restoration:30:30:-18:0|tRestore original look", SENDER_REMOVE_ALL_TRANSMOG, 0, "Equipped items are reverted to their original look with a pending change.\n\nDo you want to continue?", 0, false);
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|tUpdate menu", SENDER_SHOW_SLOTS, 0);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        static bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action, uint32 boxMoney = 0)
        {
            ClearGossipMenuFor(player);
            WorldSession* session = player->GetSession();
            switch (sender)
            {
                case SENDER_SHOW_ITEMS:
                {
                    uint32 slot = action;
                    uint32 page = 0;
                    ShowTransmogs(player, creature, SENDER_PAGINATED_EQUIPMENT_START, TRANSMOG_TYPE_ITEM, slot, page);
                } break;
                case SENDER_SHOW_ENCHANTS:
                {
                    uint32 slotindex = action;
                    uint32 page = 0;
                    ShowTransmogs(player, creature, SENDER_PAGINATED_ENCHANT_START, TRANSMOG_TYPE_ENCHANT, slotindex, page);
                } break;
                case SENDER_SHOW_MAIN_MENU:
                case SENDER_SHOW_SLOTS:
                    OnGossipHello(player, creature);
                    break;
                case SENDER_REVERT_ALL_TRANSMOG:
                {
                    Transmogrification::instance().RevertAllTransmogrifications(player);
                    OnGossipHello(player, creature);
                } break;
                case SENDER_REMOVE_ALL_TRANSMOG:
                {
                    Transmogrification::instance().RemoveAllTransmogrifications(player);
                    OnGossipHello(player, creature);
                } break;
                case SENDER_REVERT_TRANSMOG:
                {
                    uint32 slot, page;
                    GetTransmogSlotAndPage(action, SENDER_PAGINATED_EQUIPMENT_START, slot, page);
                    Transmogrification::instance().RevertTransmogrification(player, slot);
                    OnGossipSelect(player, creature, action, 0);
                } break;
                case SENDER_REVERT_ENCHANT:
                {
                    uint32 slotindex, page;
                    GetTransmogSlotAndPage(action, SENDER_PAGINATED_ENCHANT_START, slotindex, page);
                    Transmogrification::instance().RevertEnchant(player, ENCHANT_SLOTS[slotindex]);
                    OnGossipSelect(player, creature, action, 0);
                } break;
                case SENDER_PRESET_LIST: // Presets menu
                {
                    if (!Transmogrification::instance().EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    if (Transmogrification::instance().EnableSetInfo)
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Book_11:30:30:-18:0|tHow sets work", SENDER_PRESET_INFO, 0);
                    for (PresetMapType::const_iterator it = player->presetMap.begin(); it != player->presetMap.end(); ++it)
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|t" + it->second.name, SENDER_PRESET_VIEW, it->first);
                    if (player->presetMap.size() < Transmogrification::instance().MaxSets)
                        AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:30:30:-18:0|tSave set ", SENDER_CODE_PRESET_SAVE, 0, "Insert set name and click accept", 0, true);
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", SENDER_SHOW_SLOTS, 0);
                    SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                } break;
                case SENDER_PRESET_USE: // Use preset
                {
                    if (!Transmogrification::instance().EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // action = presetID

                    auto it = player->presetMap.find(action);
                    if (it != player->presetMap.end())
                    {
                        for (auto&& v : it->second.data)
                        {
                            switch (std::get<AppearanceType>(v))
                            {
                                case TRANSMOG_TYPE_ITEM:
                                    if (TransmogResult res = Transmogrification::instance().TrySetPendingTransmog(player, std::get<uint8>(v), std::get<uint32>(v)))
                                    {
                                        session->SendNotification("%s", CanTransmogrifyResultMessage(res));
                                    }
                                    break;
                                case TRANSMOG_TYPE_ENCHANT:
                                    if (TransmogResult res = Transmogrification::instance().TrySetPendingEnchant(player, std::get<uint8>(v), std::get<uint32>(v)))
                                    {
                                        session->SendNotification("%s", CanTransmogrifyResultMessage(res));
                                    }
                                    break;
                                case TRANSMOG_TYPE_COUNT:
                                    break;
                            }
                        }
                    }
                    OnGossipSelect(player, creature, SENDER_PRESET_VIEW, action);
                } break;
                case SENDER_PRESET_VIEW: // view preset
                {
                    if (!Transmogrification::instance().EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // action = presetID

                    auto it = player->presetMap.find(action);
                    if (it == player->presetMap.end())
                    {
                        OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                        return true;
                    }

                    for (auto&& v : it->second.data)
                    {
                        switch (std::get<AppearanceType>(v))
                        {
                            case TRANSMOG_TYPE_ITEM:
                                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, Transmogrification::instance().GetItemIcon(std::get<uint32>(v), 30, 30, -18, 0) + Transmogrification::instance().GetItemLink(std::get<uint32>(v), session), sender, action);
                                break;
                            case TRANSMOG_TYPE_ENCHANT:
                            {
                                auto enchant = std::get<uint32>(v);
                                if (auto* source = sSpellItemEnchantmentStore.LookupEntry(enchant)) {
                                    auto it = Transmogrification::enchant_visual_to_name.find(source->ItemVisual);
                                    if (it != Transmogrification::enchant_visual_to_name.end()) {
                                        if (const char* slotName = Transmogrification::instance().GetSlotName(std::get<uint8>(v), session))
                                            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Scroll_05:30:30:-18:0|t" + std::string(slotName) + std::string(" enchant: ") + it->second, sender, action);
                                    }
                                }
                                break;
                            }
                            case TRANSMOG_TYPE_COUNT:
                                break;
                        }
                    }

                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|tUse set", SENDER_PRESET_USE, action, "Using a set will remove pending transmogrifications and add the transmogrifications from the set as pending.\nDo you wish to continue?\n\n" + it->second.name, 0, false);
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:30:30:-18:0|tRename set", SENDER_CODE_PRESET_RENAME, action, "Insert new name\n\nOld name: " + it->second.name, 0, true);
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Opaque:30:30:-18:0|tDelete set", SENDER_PRESET_DELETE, action, "Are you sure you want to delete " + it->second.name + "?", 0, false);
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", SENDER_PRESET_LIST, 0);
                    SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                } break;
                case SENDER_PRESET_DELETE: // Delete preset
                {
                    if (!Transmogrification::instance().EnableSets)
                    {
                        OnGossipHello(player, creature);
                        return true;
                    }
                    // action = presetID

                    player->presetMap.erase(action);

                    OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                } break;
                case SENDER_PRESET_INFO: // Set info
                {
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", SENDER_PRESET_LIST, 0);
                    SendGossipMenuFor(player, Transmogrification::instance().SetNpcText, creature->GetGUID());
                } break;
                case SENDER_TRANSMOG_INFO: // Transmog info
                {
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tBack..", SENDER_SHOW_SLOTS, 0);
                    SendGossipMenuFor(player, Transmogrification::instance().TransmogNpcText, creature->GetGUID());
                } break;
                case SENDER_TRANSMOG_SAVE:
                {
                    TransmogResult res = Transmogrification::instance().TransmogrifyPending(player, boxMoney);
                    if (res == TransmogResult_Ok)
                        session->SendAreaTriggerMessage("%s", CanTransmogrifyResultMessage(res));
                    else
                        session->SendNotification("%s", CanTransmogrifyResultMessage(res));
                    OnGossipHello(player, creature);
                } break;
                default: // from 0 to EQUIPMENT_SLOT_END-1 TrySetPendingTransmog
                {
                    if (isbetween(sender, SENDER_PAGINATED_EQUIPMENT_START, SENDER_PAGINATED_EQUIPMENT_END))
                    {
                        uint32 slot, page;
                        GetTransmogSlotAndPage(sender, SENDER_PAGINATED_EQUIPMENT_START, slot, page);
                        if (action)
                        {
                            if (TrySetPendingTransmog(player, slot, action))
                                if (!player->pendingTransmogCheck)
                                    new PendingItemsCheck(player, creature);
                        }
                        ShowTransmogs(player, creature, SENDER_PAGINATED_EQUIPMENT_START, TRANSMOG_TYPE_ITEM, slot, page);
                    }
                    if (isbetween(sender, SENDER_PAGINATED_ENCHANT_START, SENDER_PAGINATED_ENCHANT_END))
                    {
                        uint32 slotindex, page;
                        GetTransmogSlotAndPage(sender, SENDER_PAGINATED_ENCHANT_START, slotindex, page);
                        if (action && slotindex < ENCHANT_SLOTS.size())
                        {
                            if (TrySetPendingEnchant(player, ENCHANT_SLOTS[slotindex], action))
                                if (!player->pendingTransmogCheck)
                                    new PendingItemsCheck(player, creature);
                        }
                        ShowTransmogs(player, creature, SENDER_PAGINATED_ENCHANT_START, TRANSMOG_TYPE_ENCHANT, slotindex, page);
                    }
                } break;
            }
            return true;
        }

        bool GossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
        {
            ClearGossipMenuFor(player);

            switch (sender)
            {
                case SENDER_CODE_PRESET_SAVE:
                {
                    if (!Transmogrification::instance().EnableSets)
                    {
                        OnGossipHello(player);
                        return true;
                    }

                    // Make sure name doesnt mess up SQL!
                    std::string name = code;

                    // length check
                    if (name.length() < 1 || name.length() > 255)
                    {
                        player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(TransmogResult_TooLongSetName));
                        OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                        return true;
                    }

                    SetTransmogs items;
                    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                    {
                        uint32 displayeditem = player->GetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2));
                        uint32 displayedenchant = player->GetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 0);
                        if (Transmogrification::instance().HasVisual(player, TRANSMOG_TYPE_ITEM, displayeditem))
                            items.emplace_back(slot, displayeditem, TRANSMOG_TYPE_ITEM);
                        if (Transmogrification::instance().HasVisual(player, TRANSMOG_TYPE_ENCHANT, displayedenchant))
                            items.emplace_back(slot, displayedenchant, TRANSMOG_TYPE_ENCHANT);
                    }

                    if (items.empty())
                    {
                        // no displays to save
                        player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(TransmogResult_NoTransmogrifications));
                        OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                        return true;
                    }

                    uint8 presetID = Transmogrification::instance().MaxSets;
                    if (player->presetMap.size() < Transmogrification::instance().MaxSets)
                    {
                        for (uint8 i = 0; i < Transmogrification::instance().MaxSets; ++i) // should never reach over max
                        {
                            if (player->presetMap.find(i) == player->presetMap.end())
                            {
                                presetID = i;
                                break;
                            }
                        }
                    }

                    if (presetID >= Transmogrification::instance().MaxSets)
                    {
                        // already saved max amount of sets, cheating?
                        player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(TransmogResult_AtMaxSets));
                        OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                        return true;
                    }

                    player->presetMap[presetID].name = name;
                    player->presetMap[presetID].data = items;

                    OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                    return true;
                } break;

                case SENDER_CODE_PRESET_RENAME:
                {
                    if (!Transmogrification::instance().EnableSets)
                    {
                        OnGossipHello(player);
                        return true;
                    }

                    // Make sure name doesnt mess up SQL!
                    std::string name = code;

                    // length check
                    if (name.length() < 1 || name.length() > 255)
                    {
                        player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(TransmogResult_TooLongSetName));
                        OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                        return true;
                    }

                    uint8 presetID = action;
                    if (player->presetMap.find(presetID) == player->presetMap.end())
                    {
                        // nonexistant setid, cheating?
                        player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(TransmogResult_NonexistantSet));
                        OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                        return true;
                    }

                    player->presetMap[presetID].name = name;

                    OnGossipSelect(player, creature, SENDER_PRESET_LIST, 0);
                    return true;
                } break;
            }

            CloseGossipMenuFor(player);
            return true;
        }

        static void BuildAndSendGossipMenu(Player* player, Creature* creature, uint32 slot, uint32 base, uint32 page, std::vector<std::tuple<uint32, std::string, std::string>> const & actions, AppearanceType transmogtype)
        {
            PageData data(page, static_cast<uint32>(actions.size()));
            if (data.count == 0)
            {
                if (!data.ismainpage)
                {
                    BuildAndSendGossipMenu(player, creature, slot, base, page - 1, actions, transmogtype);
                    return;
                }
            }
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, std::string("|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:30:30:-18:0|t") + Transmogrification::instance().GetSlotName(slot, player->GetSession()) + " - Page " + std::to_string(data.current_page) + "/" + std::to_string(data.total_pages), base + page, 0);
            if (data.next)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Spell_ChargePositive:30:30:-18:0|tNext page", base + page + 1, 0);
            if (data.prev)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Spell_ChargeNegative:30:30:-18:0|tPrevious page", base + page - 1, 0);
            if (data.ismainpage)
                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/Ability_Spy:30:30:-18:0|tShow main menu", SENDER_SHOW_MAIN_MENU, 0);
            for (uint32 i = data.start; i < data.end; ++i)
            {
                auto& value = actions.at(i);
                uint32 action = std::get<0>(value);
                std::string const& name = std::get<1>(value);
                switch (transmogtype)
                {
                    case TRANSMOG_TYPE_ITEM:
                        AddItemTransmog(player, creature, base, page, action, name);
                        break;
                    case TRANSMOG_TYPE_ENCHANT:
                        AddItemEnchant(player, creature, base, page, action, name);
                        break;
                    case TRANSMOG_TYPE_COUNT:
                        break;
                }
            }
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        }

        static void ShowTransmogs(Player* player, Creature* creature, TransmogGossipSender basesender, AppearanceType transmogtype, uint32 slot_or_slotindex, uint32 page)
        {
            uint32 sender = basesender + ((slot_or_slotindex)*max_pages);
            uint32 slot = transmogtype == TRANSMOG_TYPE_ITEM ? slot_or_slotindex : ENCHANT_SLOTS[slot_or_slotindex];
            Item* item = Transmogrification::instance().GetEquippedItem(player, slot);
            if (!item)
            {
                player->GetSession()->SendNotification("No item equipped");
                OnGossipHello(player, creature);
                return;
            }
            const ItemTemplate* target = item->GetTemplate();
            if (TransmogResult res = Transmogrification::instance().CannotTransmogrify(target))
            {
                player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(res));
                OnGossipHello(player, creature);
                return;
            }
            if (TransmogResult res = Transmogrification::instance().CannotEquip(player, target))
            {
                player->GetSession()->SendNotification("%s", CanTransmogrifyResultMessage(res));
                OnGossipHello(player, creature);
                return;
            }
            typedef std::tuple<uint32, std::string, std::string> Action;
            std::vector<Action> actions;
            switch (transmogtype)
            {
            case TRANSMOG_TYPE_ITEM:
            {
                for (uint32 appearance : player->transmogrification_appearances[transmogtype])
                {
                    decltype(auto) source = sObjectMgr->GetItemTemplate(appearance);
                    if (source && !Transmogrification::instance().CannotTransmogrifyItemWithItem(player, target, source, true))
                        actions.emplace_back(appearance, Transmogrification::instance().GetItemLink(source->ItemId, player->GetSession()), Transmogrification::instance().GetItemName(source, player->GetSession()));
                }
            }
            break;
            case TRANSMOG_TYPE_ENCHANT:
            {
                std::set<uint32> added_enchant_visuals;
                static const auto try_add_enchant = [](std::set<uint32>& added_enchant_visuals, std::vector<Action>& actions, Player* player, const ItemTemplate* target, uint32 enchant) {
                    if (!Transmogrification::instance().CannotTransmogrifyItemWithEnchant(player, target, enchant, true)) {
                        auto* source = sSpellItemEnchantmentStore.LookupEntry(enchant);
                        if (source) {
                            auto it = Transmogrification::enchant_visual_to_name.find(source->ItemVisual);
                            if (it != Transmogrification::enchant_visual_to_name.end()) {
                                auto result = added_enchant_visuals.insert(source->ItemVisual);
                                if (result.second)
                                    actions.emplace_back(enchant, it->second, it->second);
                            }
                        }
                    }
                };
                for (decltype(auto) enchant_spells : Transmogrification::instance().enchant_to_spells)
                    try_add_enchant(added_enchant_visuals, actions, player, target, enchant_spells.first);
                for (uint32 appearance : player->transmogrification_appearances[transmogtype])
                    try_add_enchant(added_enchant_visuals, actions, player, target, appearance);
            }
            break;
            case TRANSMOG_TYPE_COUNT:
                OnGossipHello(player, creature);
                return;
            }
            // Sort by name
            std::sort(actions.begin(), actions.end(),
                [&](Action const& a, Action const& b) {
                    return std::get<2>(a) < std::get<2>(b);
                }
            );
            actions.insert(actions.begin(), std::make_tuple(RemovePending, std::string(), std::string()));
            if (!(slot == SLOT_MAIN_HAND || slot == SLOT_OFF_HAND || slot == SLOT_RANGED))
                actions.insert(actions.begin(), std::make_tuple(InvisibleEntry, std::string(), std::string()));
            actions.insert(actions.begin(), std::make_tuple(NormalEntry, std::string(), std::string()));
            BuildAndSendGossipMenu(player, creature, slot, sender, page, actions, transmogtype);
        }

        static void GetTransmogSlotAndPage(uint32 sender, TransmogGossipSender basesender, uint32 & slot_or_slotindex, uint32 & page)
        {
            slot_or_slotindex = (sender - basesender) / max_pages;
            page = sender - basesender - (slot_or_slotindex*max_pages);
        }

        static bool TrySetPendingTransmog(Player* player, uint32 slot, uint32 entry)
        {
            WorldSession* session = player->GetSession();
            TransmogResult res = Transmogrification::instance().TrySetPendingTransmog(player, slot, entry);
            if (res == TransmogResult_Ok)
            {
                session->SendAreaTriggerMessage(TransmogResult_Ok_PendingMessage);
                return true;
            }
            session->SendNotification("%s", CanTransmogrifyResultMessage(res));
            return false;
        }

        static bool TrySetPendingEnchant(Player* player, uint32 slot, uint32 entry)
        {
            WorldSession* session = player->GetSession();
            TransmogResult res = Transmogrification::instance().TrySetPendingEnchant(player, slot, entry);
            if (res == TransmogResult_Ok)
            {
                session->SendAreaTriggerMessage(TransmogResult_Ok_PendingMessage);
                return true;
            }
            session->SendNotification("%s", CanTransmogrifyResultMessage(res));
            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new TransmogAI(creature);
    }
};

void AddSC_Transmogrification()
{
    new CS_Transmogrification();
}
