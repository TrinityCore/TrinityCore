/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
Name: Transmogrification
By Rochet2
Remake By Saqirmdev
%Complete: 100
Comment: Script allow spectate arena games
Category: Custom Script
EndScriptData */

#include "ScriptPCH.h"
#include "Transmogrification.h"

typedef UNORDERED_MAP<uint32, uint32> transmogData;
typedef UNORDERED_MAP<uint32, transmogData> transmogMap;
transmogMap entryMap; // entryMap[pGUID][iGUID] = entry
transmogData dataMap; // dataMap[iGUID] = pGUID

uint32 Transmogrification::GetFakeEntry(Item* item)
{
    transmogData::iterator itr = dataMap.find(item->GetGUIDLow());
    if (itr == dataMap.end()) return 0;
    transmogMap::iterator itr2 = entryMap.find(itr->second);
    if (itr2 == entryMap.end()) return 0;
    transmogData::iterator itr3 = itr2->second.find(item->GetGUIDLow());
    if (itr3 == itr2->second.end()) return 0;
    return itr3->second;
}
void Transmogrification::DeleteFakeFromDB(uint32 itemGUID)
{
    if (dataMap.find(itemGUID) != dataMap.end())
    {
        entryMap.erase(dataMap[itemGUID]);
        dataMap.erase(itemGUID);
    }
    CharacterDatabase.PExecute("DELETE FROM custom_transmogrification WHERE GUID = %u", itemGUID);
}
bool Transmogrification::DeleteFakeEntry(Item* item)
{
    if (!GetFakeEntry(item))
        return false;
    item->GetOwner()->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (item->GetSlot() * 2), item->GetEntry());
    DeleteFakeFromDB(item->GetGUIDLow());
    return true;
}
void Transmogrification::SetFakeEntry(Item* item, uint32 entry)
{
    if(Player* player = item->GetOwner())
    {
        uint32 pGUID = player->GetGUIDLow();
        uint32 iGUID = item->GetGUIDLow();
        player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (item->GetSlot() * 2), entry);
        entryMap[pGUID][iGUID] = entry;
        dataMap[iGUID] = pGUID;
        CharacterDatabase.PExecute("REPLACE INTO custom_transmogrification (GUID, FakeEntry, Owner) VALUES (%u, %u, %u)", iGUID, entry, pGUID);
    }
}
uint32 Transmogrification::SuitableForTransmogrification(Player* player, Item* oldItem, Item* newItem)
{
    // not possibly the best structure here, but atleast I got my head around this
    if (!sTransmogrification->AllowedQuality(newItem->GetTemplate()->Quality))
        return ERR_FAKE_NEW_BAD_QUALITY;
    if (!sTransmogrification->AllowedQuality(oldItem->GetTemplate()->Quality))
        return ERR_FAKE_OLD_BAD_QUALITY;

    if (oldItem->GetTemplate()->DisplayInfoID == newItem->GetTemplate()->DisplayInfoID)
        return ERR_FAKE_SAME_DISPLAY;
    if (GetFakeEntry(oldItem))
        if (const ItemTemplate* fakeItemTemplate = sObjectMgr->GetItemTemplate(GetFakeEntry(oldItem)))
            if (fakeItemTemplate->DisplayInfoID == newItem->GetTemplate()->DisplayInfoID)
                return ERR_FAKE_SAME_DISPLAY_FAKE;
    if (player->CanUseItem(newItem, false) != EQUIP_ERR_OK)
        return ERR_FAKE_CANT_USE;
    uint32 newClass = newItem->GetTemplate()->Class;
    uint32 oldClass = oldItem->GetTemplate()->Class;
    uint32 newSubClass = newItem->GetTemplate()->SubClass;
    uint32 oldSubClass = oldItem->GetTemplate()->SubClass;
    uint32 newInventorytype = newItem->GetTemplate()->InventoryType;
    uint32 oldInventorytype = oldItem->GetTemplate()->InventoryType;
    if (newClass != oldClass)
        return ERR_FAKE_NOT_SAME_CLASS;
    if (newClass == ITEM_CLASS_WEAPON && newSubClass != ITEM_SUBCLASS_WEAPON_FISHING_POLE && oldSubClass != ITEM_SUBCLASS_WEAPON_FISHING_POLE)
    {
        if (newSubClass == oldSubClass || ((newSubClass == ITEM_SUBCLASS_WEAPON_BOW || newSubClass == ITEM_SUBCLASS_WEAPON_GUN || newSubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW) && (oldSubClass == ITEM_SUBCLASS_WEAPON_BOW || oldSubClass == ITEM_SUBCLASS_WEAPON_GUN || oldSubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW)))
            if (newInventorytype == oldInventorytype || (newInventorytype == INVTYPE_WEAPON && (oldInventorytype == INVTYPE_WEAPONMAINHAND || oldInventorytype == INVTYPE_WEAPONOFFHAND)))
                return ERR_FAKE_OK;
            else
                return ERR_FAKE_BAD_INVENTORYTYPE;
        else
            return ERR_FAKE_BAD_SUBLCASS;
    }
    else if (newClass == ITEM_CLASS_ARMOR)
        if (newSubClass == oldSubClass)
            if (newInventorytype == oldInventorytype || (newInventorytype == INVTYPE_CHEST && oldInventorytype == INVTYPE_ROBE) || (newInventorytype == INVTYPE_ROBE && oldInventorytype == INVTYPE_CHEST))
                return ERR_FAKE_OK;
           else
                return ERR_FAKE_BAD_INVENTORYTYPE;
        else
            return ERR_FAKE_BAD_SUBLCASS;
    return ERR_FAKE_BAD_CLASS;
}

class NPC_Transmogrify : public CreatureScript
{
public:
    NPC_Transmogrify() : CreatureScript("NPC_Transmogrify") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        WorldSession* session = player->GetSession();
        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_TABARD; slot++) // EQUIPMENT_SLOT_END
        {
            if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            {
                if (sTransmogrification->AllowedQuality(newItem->GetTemplate()->Quality))
                {
                    if (const char* slotName = GetSlotName(slot, session))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, slotName, EQUIPMENT_SLOT_END, slot);
                }
            }
        }
        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, session->GetTrinityString(LANG_OPTION_REMOVE_ALL), EQUIPMENT_SLOT_END+2, 0, session->GetTrinityString(LANG_POPUP_REMOVE_ALL), 0, false);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, session->GetTrinityString(LANG_OPTION_UPDATE_MENU), EQUIPMENT_SLOT_END+1, 0);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 uiAction)
    {
        WorldSession* session = player->GetSession();
        player->PlayerTalkClass->ClearMenus();
        switch(sender)
        {
        case EQUIPMENT_SLOT_END: // Show items you can use
            {
                if (Item* oldItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, uiAction))
                {
                    uint32 lowGUID = player->GetGUIDLow();
                    _items[lowGUID].clear();
                    uint32 limit = 0;
                    uint32 price = 0;
                    switch (sTransmogrification->GetRequireGold())
                    {
                    case 1: { price = (unsigned int)(GetFakePrice(oldItem)*sTransmogrification->GetGoldModifier()); } break;
                    case 2: { price = (unsigned int)sTransmogrification->GetGoldCost(); } break;
                    }
                    char tokenCost[250] = "\n";
                    if(sTransmogrification->GetRequireToken())
                        snprintf(tokenCost, 250, "\n\n%u x %s", sTransmogrification->GetTokenAmount(), GetItemName(sObjectMgr->GetItemTemplate(sTransmogrification->GetTokenEntry()), session).c_str());

                    for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++)
                    {
                        if (limit > 30)
                            break;
                        if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        {
                            uint32 display = newItem->GetTemplate()->DisplayInfoID;
                            if (Transmogrification::SuitableForTransmogrification(player, oldItem, newItem) == ERR_FAKE_OK)
                            {
                                if (_items[lowGUID].find(display) == _items[lowGUID].end())
                                {
                                    limit++;
                                    _items[lowGUID][display] = newItem;
                                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, GetItemName(newItem->GetTemplate(), session), uiAction, display, session->GetTrinityString(LANG_POPUP_TRANSMOGRIFY)+GetItemName(newItem->GetTemplate(), session)+tokenCost, price, false);
                                }
                            }
                        }
                    }

                    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
                    {
                        if (Bag* bag = player->GetBagByPos(i))
                        {
                            for (uint32 j = 0; j < bag->GetBagSize(); j++)
                            {
                                if (limit > 30)
                                    break;
                                if (Item* newItem = player->GetItemByPos(i, j))
                                {
                                    uint32 display = newItem->GetTemplate()->DisplayInfoID;
                                    if (Transmogrification::SuitableForTransmogrification(player, oldItem, newItem) == ERR_FAKE_OK)
                                    {
                                        if (_items[lowGUID].find(display) == _items[lowGUID].end())
                                        {
                                            limit++;
                                            _items[lowGUID][display] = newItem;
                                            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, GetItemName(newItem->GetTemplate(), session), uiAction, display, session->GetTrinityString(LANG_POPUP_TRANSMOGRIFY)+GetItemName(newItem->GetTemplate(), session)+tokenCost, price, false);
                                        }
                                    }
                                }
                            }
                        }
                    }

                    char removeOnePopup[250];
                    snprintf(removeOnePopup, 250, session->GetTrinityString(LANG_POPUP_REMOVE_ONE), GetSlotName(uiAction, session));
                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, session->GetTrinityString(LANG_OPTION_REMOVE_ONE), EQUIPMENT_SLOT_END+3, uiAction, removeOnePopup, 0, false);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, session->GetTrinityString(LANG_OPTION_BACK), EQUIPMENT_SLOT_END+1, 0);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
                else
                    OnGossipHello(player, creature);
            } break;
        case EQUIPMENT_SLOT_END+1: // Back
            {
                OnGossipHello(player, creature);
            } break;
        case EQUIPMENT_SLOT_END+2: // Remove Transmogrifications
            {
                bool removed = false;
                for (uint8 Slot = EQUIPMENT_SLOT_START; Slot < EQUIPMENT_SLOT_END; Slot++)
                {
                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, Slot))
                    {
                        if (Transmogrification::DeleteFakeEntry(newItem) && !removed)
                            removed = true;
                    }
                }
                if (removed)
                {
                    session->SendAreaTriggerMessage(session->GetTrinityString(LANG_REM_TRANSMOGRIFICATIONS_ITEMS));
                    player->PlayDirectSound(3337);
                }
                else
                    session->SendNotification(session->GetTrinityString(LANG_ERR_NO_TRANSMOGRIFICATIONS));
                OnGossipHello(player, creature);
            } break;
        case EQUIPMENT_SLOT_END+3: // Remove Transmogrification from single item
            {
                if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, uiAction))
                {
                    if (Transmogrification::DeleteFakeEntry(newItem))
                    {
                        session->SendAreaTriggerMessage(session->GetTrinityString(LANG_REM_TRANSMOGRIFICATION_ITEM), GetSlotName(uiAction, session));
                        player->PlayDirectSound(3337);
                    }
                    else
                        session->SendNotification(session->GetTrinityString(LANG_ERR_NO_TRANSMOGRIFICATION), GetSlotName(uiAction, session));
                }
                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, uiAction);
            } break;
        default: // Transmogrify
            {
                uint32 lowGUID = player->GetGUIDLow();
                if(!sTransmogrification->GetRequireToken() || player->GetItemCount(sTransmogrification->GetTokenEntry()) >= sTransmogrification->GetTokenAmount())
                {
                    if (Item* oldItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, sender))
                    {
                        if (_items[lowGUID].find(uiAction) != _items[lowGUID].end() && _items[lowGUID][uiAction]->IsInWorld())
                        {
                            Item* newItem = _items[lowGUID][uiAction];
                            if (newItem->GetOwnerGUID() == player->GetGUIDLow() && (newItem->IsInBag() || newItem->GetBagSlot() == INVENTORY_SLOT_BAG_0) && Transmogrification::SuitableForTransmogrification(player, oldItem, newItem) == ERR_FAKE_OK)
                            {
                                switch(sTransmogrification->GetRequireGold())
                                {
                                case 1: { player->ModifyMoney(-1*(uint32)(GetFakePrice(oldItem)*sTransmogrification->GetGoldModifier())); } break;
                                case 2: { player->ModifyMoney(-1*(unsigned int)sTransmogrification->GetGoldCost()); } break;
                                }
                                if(sTransmogrification->GetRequireToken())
                                    player->DestroyItemCount(sTransmogrification->GetTokenEntry(), sTransmogrification->GetTokenAmount(), true);
                                Transmogrification::SetFakeEntry(oldItem, newItem->GetEntry());
                                newItem->SetNotRefundable(player);
                                newItem->SetBinding(true);
                                player->PlayDirectSound(3337);
                                session->SendAreaTriggerMessage(session->GetTrinityString(LANG_ITEM_TRANSMOGRIFIED), GetSlotName(sender, session));
                            }
                            else
                                session->SendNotification(session->GetTrinityString(LANG_ERR_NO_ITEM_SUITABLE));
                        }
                        else
                            session->SendNotification(session->GetTrinityString(LANG_ERR_NO_ITEM_EXISTS));
                    }
                    else
                        session->SendNotification(session->GetTrinityString(LANG_ERR_EQUIP_SLOT_EMPTY));
                }
                else
                    session->SendNotification(session->GetTrinityString(LANG_ERR_NO_TOKEN), GetItemName(sObjectMgr->GetItemTemplate(sTransmogrification->GetTokenEntry()), session).c_str());
                _items[lowGUID].clear();
                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, sender);
            } break;
        }
        return true;
    }

private:
    std::map<uint64, std::map<uint32, Item*> > _items; // _items[lowGUID][DISPLAY] = item

    const char * GetSlotName(uint8 slot, WorldSession* session)
    {
        switch (slot)
        {
        case EQUIPMENT_SLOT_HEAD      : return session->GetTrinityString(LANG_SLOT_NAME_HEAD);
        case EQUIPMENT_SLOT_SHOULDERS : return session->GetTrinityString(LANG_SLOT_NAME_SHOULDERS);
        case EQUIPMENT_SLOT_BODY      : return session->GetTrinityString(LANG_SLOT_NAME_BODY);
        case EQUIPMENT_SLOT_CHEST     : return session->GetTrinityString(LANG_SLOT_NAME_CHEST);
        case EQUIPMENT_SLOT_WAIST     : return session->GetTrinityString(LANG_SLOT_NAME_WAIST);
        case EQUIPMENT_SLOT_LEGS      : return session->GetTrinityString(LANG_SLOT_NAME_LEGS);
        case EQUIPMENT_SLOT_FEET      : return session->GetTrinityString(LANG_SLOT_NAME_FEET);
        case EQUIPMENT_SLOT_WRISTS    : return session->GetTrinityString(LANG_SLOT_NAME_WRISTS);
        case EQUIPMENT_SLOT_HANDS     : return session->GetTrinityString(LANG_SLOT_NAME_HANDS);
        case EQUIPMENT_SLOT_BACK      : return session->GetTrinityString(LANG_SLOT_NAME_BACK);
        case EQUIPMENT_SLOT_MAINHAND  : return session->GetTrinityString(LANG_SLOT_NAME_MAINHAND);
        case EQUIPMENT_SLOT_OFFHAND   : return session->GetTrinityString(LANG_SLOT_NAME_OFFHAND);
        case EQUIPMENT_SLOT_RANGED    : return session->GetTrinityString(LANG_SLOT_NAME_RANGED);
        case EQUIPMENT_SLOT_TABARD    : return session->GetTrinityString(LANG_SLOT_NAME_TABARD);
        default: return NULL;
        }
    }

    std::string GetItemName(const ItemTemplate* itemTemplate, WorldSession* session)
    {
        std::string name = itemTemplate->Name1;
        int loc_idx = session->GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
            if (ItemLocale const* il = sObjectMgr->GetItemLocale(itemTemplate->ItemId))
                sObjectMgr->GetLocaleString(il->Name, loc_idx, name);
        return name;
    }

    uint32 GetFakePrice(Item* item)
    {
        uint32 sellPrice = item->GetTemplate()->SellPrice;
        uint32 minPrice = item->GetTemplate()->RequiredLevel * 1176;
        if (sellPrice < minPrice)
            sellPrice = minPrice;
        return sellPrice;
    }
};

class Player_Transmogrify : public PlayerScript
{
 public:
    Player_Transmogrify() : PlayerScript("Player_Transmogrify") { }

    void OnLogin(Player* player)
    {
        uint32 playerGUID = player->GetGUIDLow();
        entryMap.erase(playerGUID);
        QueryResult result = CharacterDatabase.PQuery("SELECT GUID, FakeEntry FROM custom_transmogrification WHERE Owner = %u", playerGUID);
        if (result)
        {
            do
            {
                uint32 itemGUID = (*result)[0].GetUInt32();
                uint32 fakeEntry = (*result)[1].GetUInt32();
                if (sObjectMgr->GetItemTemplate(fakeEntry))
                {
                   dataMap[itemGUID] = playerGUID;
				   entryMap[playerGUID][itemGUID] = fakeEntry;
                }
                else
                {
                    sLog->outError(LOG_FILTER_SQL, "Item entry (Entry: %u, itemGUID: %u, playerGUID: %u) does not exist, deleting.", fakeEntry, itemGUID, playerGUID);
                    Transmogrification::DeleteFakeFromDB(itemGUID);
                }
            } while (result->NextRow());

            for (uint8 Slot = EQUIPMENT_SLOT_START; Slot < EQUIPMENT_SLOT_END; Slot++)
            {
                if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, Slot))
                    if(entryMap.find(playerGUID) != entryMap.end())
                        if(entryMap[playerGUID].find(item->GetGUIDLow()) != entryMap[playerGUID].end())
                            player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (item->GetSlot() * 2), entryMap[playerGUID][item->GetGUIDLow()]);
            }
        }
    }

    void OnLogout(Player* player)
    {
        uint32 pGUID = player->GetGUIDLow();
        if(entryMap.find(pGUID) == entryMap.end())
            return;
        for(transmogData::iterator it = entryMap[pGUID].begin(); it != entryMap[pGUID].end(); ++it)
        {
            dataMap.erase(it->first);
        }
        entryMap.erase(pGUID);
    }
};

class Config_Transmogrify : public WorldScript
{
public:
    Config_Transmogrify() : WorldScript("Config_Transmogrify") { }

    void OnConfigLoad(bool reload)
    {
        sTransmogrification->LoadConfig();
    }

    void OnStartup()
    {
        sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Deleting non-existing transmogrification entries...");
        CharacterDatabase.Execute("DELETE FROM custom_transmogrification WHERE NOT EXISTS (SELECT 1 FROM item_instance WHERE item_instance.guid = custom_transmogrification.GUID)");
    }
};

void AddSC_NPC_Transmogrify()
{
    new NPC_Transmogrify();
    new Player_Transmogrify();
    new Config_Transmogrify();
}