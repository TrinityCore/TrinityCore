/*
Transmog display vendor
Code by Rochet2
Ideas LilleCarl

ScriptName for NPC:
NPC_TransmogDisplayVendor

Compatible with Transmogrification 6.1 by Rochet2
http://rochet2.github.io/Transmogrification
*/

#include "TransmogDisplayVendorConf.h"
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
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>

class NPC_TransmogDisplayVendor : public CreatureScript
{
public:
    NPC_TransmogDisplayVendor() : CreatureScript("NPC_TransmogDisplayVendor") { } // If you change this, also change in Player.cpp: if (creature->GetScriptName() == "NPC_TransmogDisplayVendor")

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);
        TransmogDisplayVendorMgr::selectionStore.RemoveSelection(player->GetGUID().GetCounter());
        WorldSession* session = player->GetSession();
        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
        {
            // if (player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            if (const char* slotName = TransmogDisplayVendorMgr::getSlotName(slot, session))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, slotName, SENDER_SELECT_VENDOR, slot);
        }
        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "Remove transmogrifications", SENDER_REMOVE_MENU, 0);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        WorldSession* session = player->GetSession();
        ClearGossipMenuFor(player);
        switch (sender)
        {
            case SENDER_SELECT_VENDOR: // action = slot
            {
                Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action);
                if (!item)
                {
                    if (const char* slotname = TransmogDisplayVendorMgr::getSlotName(action, player->GetSession()))
                        session->SendNotification("No item equipped in %s slot", slotname);
                    OnGossipHello(player, creature);
                    return true;
                }
                const ItemTemplate * itemTemplate = item->GetTemplate();
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, (std::string)"Update selected; " + TransmogDisplayVendorMgr::getItemName(itemTemplate, session), sender, action);

                // [quality] = {size}
                std::map<uint32, uint32> L;
                if (itemTemplate->Class != ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedArmorTypes)
                {
                    for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_ARMOR; ++i)
                    {
                        TransmogDisplayVendorMgr::EntryVector** oM = TransmogDisplayVendorMgr::optionMap[MAX_ITEM_SUBCLASS_WEAPON + i][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)];
                        for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i, ++oM)
                            if (TransmogDisplayVendorMgr::IsAllowedQuality(i)) // skip not allowed qualities
                                if (*oM)
                                    L[i] += (*oM)->size();
                    }
                }
                else if (itemTemplate->Class == ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedWeaponTypes)
                {
                    for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON; ++i)
                    {
                        TransmogDisplayVendorMgr::EntryVector** oM = TransmogDisplayVendorMgr::optionMap[i][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)];
                        for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i, ++oM)
                            if (TransmogDisplayVendorMgr::IsAllowedQuality(i)) // skip not allowed qualities
                                if (*oM)
                                    L[i] += (*oM)->size();
                    }
                }
                else
                {
                    TransmogDisplayVendorMgr::EntryVector** oM = TransmogDisplayVendorMgr::optionMap[(itemTemplate->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTemplate->SubClass][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)];
                    for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i, ++oM)
                        if (TransmogDisplayVendorMgr::IsAllowedQuality(i)) // skip not allowed qualities
                            if (*oM)
                                L[i] += (*oM)->size();
                }

                for (std::map<uint32, uint32>::const_iterator it = L.begin(); it != L.end(); ++it)
                {
                    for (uint32 count = 0; count*MAX_VENDOR_ITEMS < it->second; ++count)
                    {
                        std::ostringstream ss;
                        ss << TransmogDisplayVendorMgr::getQualityName(it->first);
                        if (count)
                            ss << " [" << count << "]";
                        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, ss.str().c_str(), it->first, count*MAX_VENDOR_ITEMS);
                    }
                }

                if (player->PlayerTalkClass->GetGossipMenu().GetMenuItemCount() <= 1)
                {
                    if (const char* slotname = TransmogDisplayVendorMgr::getSlotName(action, player->GetSession()))
                        session->SendNotification("No transmogrifications available for %s", slotname);
                    OnGossipHello(player, creature);
                    return true;
                }

                SelectionStore::Selection temp = { item->GetEntry(), static_cast<uint8>(action), 0, 0 }; // entry, slot, offset, quality
                TransmogDisplayVendorMgr::selectionStore.SetSelection(player->GetGUID().GetCounter(), temp);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Back..", SENDER_BACK, 0);
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            } break;
            case SENDER_BACK: // Back
            {
                OnGossipHello(player, creature);
            } break;
            case SENDER_REMOVE_ALL: // Remove TransmogDisplayVendorMgrs
            {
                bool removed = false;
                for (uint8 Slot = EQUIPMENT_SLOT_START; Slot < EQUIPMENT_SLOT_END; Slot++)
                {
                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, Slot))
                    {
                        if (!TransmogDisplayVendorMgr::GetFakeEntry(newItem))
                            continue;
                        TransmogDisplayVendorMgr::DeleteFakeEntry(player, newItem);
                        removed = true;
                    }
                }
                if (removed)
                {
                    session->SendAreaTriggerMessage("Transmogrifications removed from equipped items");
                    player->PlayDirectSound(3337);
                }
                else
                {
                    session->SendNotification("You have no transmogrified items equipped");
                }
                OnGossipSelect(player, creature, SENDER_REMOVE_MENU, 0);
            } break;
            case SENDER_REMOVE_ONE: // Remove TransmogDisplayVendorMgr from single item
            {
                const char* slotname = TransmogDisplayVendorMgr::getSlotName(action, player->GetSession());
                if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action))
                {
                    if (TransmogDisplayVendorMgr::GetFakeEntry(newItem))
                    {
                        TransmogDisplayVendorMgr::DeleteFakeEntry(player, newItem);
                        if (slotname)
                            session->SendAreaTriggerMessage("%s transmogrification removed", slotname);
                        player->PlayDirectSound(3337);
                    }
                    else if (slotname)
                    {
                        session->SendNotification("No transmogrification on %s slot", slotname);
                    }
                }
                else if (slotname)
                {
                    session->SendNotification("No item equipped in %s slot", slotname);
                }
                OnGossipSelect(player, creature, SENDER_REMOVE_MENU, 0);
            } break;
            case SENDER_REMOVE_MENU:
            {
                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
                {
                    const char* slotname = TransmogDisplayVendorMgr::getSlotName(slot, player->GetSession());
                    if (!slotname)
                        continue;
                    std::ostringstream ss;
                    ss << "Remove transmogrification from " << slotname << "?";
                    AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, (std::string)"Remove from " + slotname, SENDER_REMOVE_ONE, slot, ss.str().c_str(), 0, false);
                }
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Remove all transmogrifications", SENDER_REMOVE_ALL, 0, "Are you sure you want to remove all transmogrifications?", 0, false);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, "Back..", SENDER_BACK, 0);
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            } break;
            default: // Show items you can use
            {
                if (sender >= MAX_ITEM_QUALITY) // sender = quality, action = iterator
                    return false; // cheat

                SelectionStore::Selection selection;
                if (!TransmogDisplayVendorMgr::selectionStore.GetSelection(player->GetGUID().GetCounter(), selection))
                    return false; // cheat
                if (selection.offset != 0 || selection.quality != 0)
                    return false; // cheat (something is off)

                selection.offset = action;
                selection.quality = sender;
                uint32 slot = selection.slot; // slot
                TransmogDisplayVendorMgr::selectionStore.SetSelection(player->GetGUID().GetCounter(), selection);

                if (const ItemTemplate* itemTemplate = sObjectMgr->GetItemTemplate(selection.item))
                {
                    if (!TransmogDisplayVendorMgr::SuitableForTransmogrification(player, itemTemplate))
                    {
                        player->GetSession()->SendNotification("Equipped item is not suitable for transmogrification");
                        OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                        return true;
                    }

                    // {{entry}, {entry}, ...}
                    std::list<uint32> L;
                    uint32 counter = 0;
                    bool over = false;
                    if (itemTemplate->Class != ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedArmorTypes)
                    {
                        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_ARMOR; ++i)
                        {
                            const TransmogDisplayVendorMgr::EntryVector* oM = TransmogDisplayVendorMgr::optionMap[MAX_ITEM_SUBCLASS_WEAPON + i][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                            if (!oM)
                                continue;
                            if (!over && counter + oM->size() < selection.offset)
                            {
                                counter += oM->size();
                            }
                            else
                            {
                                over = true;
                                L.insert(L.end(), oM->begin(), oM->end());
                            }
                        }
                    }
                    else if (itemTemplate->Class == ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedWeaponTypes)
                    {
                        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON; ++i)
                        {
                            const TransmogDisplayVendorMgr::EntryVector* oM = TransmogDisplayVendorMgr::optionMap[i][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                            if (!oM)
                                continue;
                            if (!over && counter + oM->size() < selection.offset)
                                counter += oM->size();
                            else
                            {
                                over = true;
                                L.insert(L.end(), oM->begin(), oM->end());
                            }
                        }
                    }
                    else
                    {
                        const TransmogDisplayVendorMgr::EntryVector* oM = TransmogDisplayVendorMgr::optionMap[(itemTemplate->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTemplate->SubClass][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                        if (oM)
                        {
                            if (!over && counter + oM->size() < selection.offset)
                            {
                                counter += oM->size();
                            }
                            else
                            {
                                over = true;
                                L.insert(L.end(), oM->begin(), oM->end());
                            }
                        }
                    }

                    // TransmogDisplayVendorMgr::EntryVector oM = TransmogDisplayVendorMgr::optionMap[(itemTemplate->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTemplate->SubClass][TransmogDisplayVendorMgr::getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                    uint32 itemCount = L.size() - (selection.offset - counter);
                    if (itemCount > MAX_VENDOR_ITEMS)
                        itemCount = MAX_VENDOR_ITEMS;

                    if (!itemCount)
                    {
                        session->SendAreaTriggerMessage("No items found");
                        OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                        return true;
                    }
                    CloseGossipMenuFor(player);

                    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_LIST_INVENTORY");

                    Creature* vendor = player->GetNPCIfCanInteractWith(creature->GetGUID(), UNIT_NPC_FLAG_VENDOR);
                    if (!vendor)
                    {
                        TC_LOG_DEBUG("network", "WORLD: SendListInventory - Unit (GUID: %u) not found or you can not interact with him.", creature->GetGUID().GetCounter());
                        player->SendSellError(SELL_ERR_CANT_FIND_VENDOR, NULL, ObjectGuid::Empty, 0);
                        return true;
                    }

                    if (player->HasUnitState(UNIT_STATE_DIED))
                        player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

                    if (vendor->HasUnitState(UNIT_STATE_MOVING))
                        vendor->StopMoving();

                    uint8 count = 0;

                    WorldPacket data(SMSG_LIST_INVENTORY, 8 + 1 + itemCount * 8 * 4);
                    data << uint64(creature->GetGUID());

                    size_t countPos = data.wpos();
                    data << uint8(count);

                    uint32 item_amount = 0;
                    std::list<uint32>::const_iterator it = L.begin();
                    std::advance(it, (selection.offset - counter));
                    for (; it != L.end() && count < itemCount; ++it, ++count)
                    {
                        if (ItemTemplate const* curtemp = sObjectMgr->GetItemTemplate(*it))
                        {
                            if (!TransmogDisplayVendorMgr::CanTransmogrifyItemWithItem(player, itemTemplate, curtemp))
                                continue;

                            data << uint32(count + 1);
                            data << uint32(curtemp->ItemId);
                            data << uint32(curtemp->DisplayInfoID);
                            data << int32(0xFFFFFFFF);
                            data << uint32(0);
                            data << uint32(curtemp->MaxDurability);
                            data << uint32(curtemp->BuyCount);
                            data << uint32(0);
                            ++item_amount;
                        }
                    }

                    if (!item_amount)
                    {
                        session->SendAreaTriggerMessage("No transmogrifications found for equipped item");
                        OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                        return true;
                    }
                    else
                    {
                        data.put<uint8>(countPos, item_amount);
                        session->SendPacket(&data);
                    }
                }
                else
                {
                    session->SendNotification("Invalid item equipped");
                    OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                    return true;
                }
            } break;
        }
        return true;
    }
};

#if !TRANSMOGRIFICATION_ALREADY_INSTALLED
class Player_Transmogrify : public PlayerScript
{
public:
    Player_Transmogrify() : PlayerScript("Player_Transmogrify") { }

    std::vector<ObjectGuid> GetItemList(const Player* player) const
    {
        std::vector<ObjectGuid> itemlist;

        // Copy paste from Player::GetItemByGuid(guid)

        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                itemlist.push_back(pItem->GetGUID());

        for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                itemlist.push_back(pItem->GetGUID());

        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                itemlist.push_back(pItem->GetGUID());

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            if (Bag* pBag = player->GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        itemlist.push_back(pItem->GetGUID());

        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
            if (Bag* pBag = player->GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        itemlist.push_back(pItem->GetGUID());

        return itemlist;
    }

    void OnSave(Player* player) override
    {
        uint32 lowguid = player->GetGUID().GetCounter();
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->PAppend("DELETE FROM `custom_transmogrification` WHERE `Owner` = %u", lowguid);

        if (!player->transmogMap.empty())
        {
            // Only save items that are in inventory / bank / etc
            std::vector<ObjectGuid> items = GetItemList(player);
            for (std::vector<ObjectGuid>::const_iterator it = items.begin(); it != items.end(); ++it)
            {
                TransmogMapType::const_iterator it2 = player->transmogMap.find(*it);
                if (it2 == player->transmogMap.end())
                    continue;

                trans->PAppend("REPLACE INTO custom_transmogrification (GUID, FakeEntry, Owner) VALUES (%u, %u, %u)", it2->first.GetCounter(), it2->second, lowguid);
            }
        }

        if (trans->GetSize()) // basically never false
            CharacterDatabase.CommitTransaction(trans);
    }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT GUID, FakeEntry FROM custom_transmogrification WHERE Owner = %u", player->GetGUID().GetCounter());

        if (result)
        {
            do
            {
                Field* field = result->Fetch();
                ObjectGuid itemGUID(HighGuid::Item, 0, field[0].GetUInt32());
                uint32 fakeEntry = field[1].GetUInt32();
                // Only load items that are in inventory / bank / etc
                if (sObjectMgr->GetItemTemplate(fakeEntry) && player->GetItemByGuid(itemGUID))
                {
                    player->transmogMap[itemGUID] = fakeEntry;
                }
                else
                {
                    // Ignore, will be erased on next save.
                    // Additionally this can happen if an item was deleted from DB but still exists for the player
                    // TC_LOG_ERROR("custom.transmog", "Item entry (Entry: %u, itemGUID: %u, playerGUID: %u) does not exist, ignoring.", fakeEntry, GUID_LOPART(itemGUID), player->GetGUID().GetCounter());
                    // CharacterDatabase.PExecute("DELETE FROM custom_transmogrification WHERE FakeEntry = %u", fakeEntry);
                }
            } while (result->NextRow());

            if (!player->transmogMap.empty())
            {
                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                {
                    if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        player->SetVisibleItemSlot(slot, item);
                        if (player->IsInWorld())
                            item->SendUpdateToPlayer(player);
                    }
                }
            }
        }
    }

    void OnLogout(Player* player) override
    {
        TransmogDisplayVendorMgr::selectionStore.RemoveSelection(player->GetGUID().GetCounter());
    }
};
#endif

class PREP_TransmogDisplayVendor : public WorldScript
{
public:
    PREP_TransmogDisplayVendor() : WorldScript("PREP_TransmogDisplayVendor") { }

    void OnStartup() override
    {
        for (uint32 v : TransmogDisplayVendorMgr::AllowedItems)
            TransmogDisplayVendorMgr::Allowed.push_back(v);
        for (uint32 v : TransmogDisplayVendorMgr::NotAllowedItems)
            TransmogDisplayVendorMgr::NotAllowed.push_back(v);

        TC_LOG_INFO("server.loading", "Creating a list of usable transmogrification entries...");
        // initialize .. for reload in future?
        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR; ++i)
            for (uint32 j = 0; j < MAX_INVTYPE; ++j)
                for (uint32 k = 0; k < MAX_ITEM_QUALITY; ++k)
                    delete TransmogDisplayVendorMgr::optionMap[i][j][k], TransmogDisplayVendorMgr::optionMap[i][j][k] = NULL;

        std::unordered_set<uint32> displays;
        ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
        for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
        {
            if (itr->second.Class != ITEM_CLASS_WEAPON && itr->second.Class != ITEM_CLASS_ARMOR)
                continue;
            if (!TransmogDisplayVendorMgr::SuitableForTransmogrification(NULL, &itr->second))
                continue;
            if (displays.find(itr->second.DisplayInfoID) != displays.end()) // skip duplicate item displays
                continue;
            TransmogDisplayVendorMgr::EntryVector* oM = TransmogDisplayVendorMgr::optionMap[(itr->second.Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itr->second.SubClass][TransmogDisplayVendorMgr::getCorrectInvType(itr->second.InventoryType)][itr->second.Quality];
            if (!oM)
            {
                oM = new TransmogDisplayVendorMgr::EntryVector();
                TransmogDisplayVendorMgr::optionMap[(itr->second.Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itr->second.SubClass][TransmogDisplayVendorMgr::getCorrectInvType(itr->second.InventoryType)][itr->second.Quality] = oM;
            }
            if (oM->size() < MAX_VENDOR_ITEMS * 3)
            {
                oM->push_back(itr->second.ItemId);
                displays.insert(itr->second.DisplayInfoID);
            }
            else
            {
                TC_LOG_INFO("server.loading", "Too many items for transmogrification: Class: %u SubClass: %u InventoryType: %u Quality: %u", itr->second.Class, itr->second.SubClass, TransmogDisplayVendorMgr::getCorrectInvType(itr->second.InventoryType), itr->second.Quality);
            }
        }

        // resize entry lists
        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR; ++i)
            for (uint32 j = 0; j < MAX_INVTYPE; ++j)
                for (uint32 k = 0; k < MAX_ITEM_QUALITY; ++k)
                    if (TransmogDisplayVendorMgr::optionMap[i][j][k])
                        TransmogDisplayVendorMgr::optionMap[i][j][k]->resize(TransmogDisplayVendorMgr::optionMap[i][j][k]->size());

#if !TRANSMOGRIFICATION_ALREADY_INSTALLED
        TC_LOG_INFO("custom.transmog", "Deleting non-existing transmogrification entries...");
        CharacterDatabase.DirectExecute("DELETE FROM custom_transmogrification WHERE NOT EXISTS (SELECT 1 FROM item_instance WHERE item_instance.guid = custom_transmogrification.GUID)");
#endif
    }

    void OnShutdown() override
    {
        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR; ++i)
            for (uint32 j = 0; j < MAX_INVTYPE; ++j)
                for (uint32 k = 0; k < MAX_ITEM_QUALITY; ++k)
                    delete TransmogDisplayVendorMgr::optionMap[i][j][k], TransmogDisplayVendorMgr::optionMap[i][j][k] = NULL;
    }
};

void AddSC_NPC_TransmogDisplayVendor()
{
    new NPC_TransmogDisplayVendor();
    new PREP_TransmogDisplayVendor();

#if !TRANSMOGRIFICATION_ALREADY_INSTALLED
    new Player_Transmogrify();
#endif
}
