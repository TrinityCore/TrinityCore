/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
Name: debug_commandscript
%Complete: 100
Comment: All debug related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "BattlegroundMgr.h"
#include "Chat.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "GossipDef.h"

#include <fstream>

class debug_commandscript : public CommandScript
{
public:
    debug_commandscript() : CommandScript("debug_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand debugPlayCommandTable[] =
        {
            { "cinematic",      SEC_MODERATOR,      false, &HandleDebugPlayCinematicCommand,   "", NULL },
            { "movie",          SEC_MODERATOR,      false, &HandleDebugPlayMovieCommand,       "", NULL },
            { "sound",          SEC_MODERATOR,      false, &HandleDebugPlaySoundCommand,       "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        static ChatCommand debugSendCommandTable[] =
        {
            { "buyerror",       SEC_ADMINISTRATOR,  false, &HandleDebugSendBuyErrorCommand,       "", NULL },
            { "channelnotify",  SEC_ADMINISTRATOR,  false, &HandleDebugSendChannelNotifyCommand,  "", NULL },
            { "chatmmessage",   SEC_ADMINISTRATOR,  false, &HandleDebugSendChatMsgCommand,        "", NULL },
            { "equiperror",     SEC_ADMINISTRATOR,  false, &HandleDebugSendEquipErrorCommand,     "", NULL },
            { "largepacket",    SEC_ADMINISTRATOR,  false, &HandleDebugSendLargePacketCommand,    "", NULL },
            { "opcode",         SEC_ADMINISTRATOR,  false, &HandleDebugSendOpcodeCommand,         "", NULL },
            { "qpartymsg",      SEC_ADMINISTRATOR,  false, &HandleDebugSendQuestPartyMsgCommand,  "", NULL },
            { "qinvalidmsg",    SEC_ADMINISTRATOR,  false, &HandleDebugSendQuestInvalidMsgCommand, "", NULL },
            { "sellerror",      SEC_ADMINISTRATOR,  false, &HandleDebugSendSellErrorCommand,      "", NULL },
            { "setphaseshift",  SEC_ADMINISTRATOR,  false, &HandleDebugSendSetPhaseShiftCommand,  "", NULL },
            { "spellfail",      SEC_ADMINISTRATOR,  false, &HandleDebugSendSpellFailCommand,      "", NULL },
            { NULL,             0,                  false, NULL,                                  "", NULL }
        };
        static ChatCommand debugCommandTable[] =
        {
            { "setbit",         SEC_ADMINISTRATOR,  false, &HandleDebugSet32BitCommand,        "", NULL },
            { "threat",         SEC_ADMINISTRATOR,  false, &HandleDebugThreatListCommand,      "", NULL },
            { "hostil",         SEC_ADMINISTRATOR,  false, &HandleDebugHostileRefListCommand,  "", NULL },
            { "anim",           SEC_GAMEMASTER,     false, &HandleDebugAnimCommand,            "", NULL },
            { "arena",          SEC_ADMINISTRATOR,  false, &HandleDebugArenaCommand,           "", NULL },
            { "bg",             SEC_ADMINISTRATOR,  false, &HandleDebugBattlegroundCommand,    "", NULL },
            { "getitemstate",   SEC_ADMINISTRATOR,  false, &HandleDebugGetItemStateCommand,    "", NULL },
            { "lootrecipient",  SEC_GAMEMASTER,     false, &HandleDebugGetLootRecipientCommand, "", NULL },
            { "getvalue",       SEC_ADMINISTRATOR,  false, &HandleDebugGetValueCommand,        "", NULL },
            { "getitemvalue",   SEC_ADMINISTRATOR,  false, &HandleDebugGetItemValueCommand,    "", NULL },
            { "Mod32Value",     SEC_ADMINISTRATOR,  false, &HandleDebugMod32ValueCommand,      "", NULL },
            { "play",           SEC_MODERATOR,      false, NULL,              "", debugPlayCommandTable },
            { "send",           SEC_ADMINISTRATOR,  false, NULL,              "", debugSendCommandTable },
            { "setaurastate",   SEC_ADMINISTRATOR,  false, &HandleDebugSetAuraStateCommand,    "", NULL },
            { "setitemvalue",   SEC_ADMINISTRATOR,  false, &HandleDebugSetItemValueCommand,    "", NULL },
            { "setvalue",       SEC_ADMINISTRATOR,  false, &HandleDebugSetValueCommand,        "", NULL },
            { "spawnvehicle",   SEC_ADMINISTRATOR,  false, &HandleDebugSpawnVehicleCommand,    "", NULL },
            { "setvid",         SEC_ADMINISTRATOR,  false, &HandleDebugSetVehicleIdCommand,    "", NULL },
            { "entervehicle",   SEC_ADMINISTRATOR,  false, &HandleDebugEnterVehicleCommand,    "", NULL },
            { "uws",            SEC_ADMINISTRATOR,  false, &HandleDebugUpdateWorldStateCommand, "", NULL },
            { "update",         SEC_ADMINISTRATOR,  false, &HandleDebugUpdateCommand,          "", NULL },
            { "itemexpire",     SEC_ADMINISTRATOR,  false, &HandleDebugItemExpireCommand,      "", NULL },
            { "areatriggers",   SEC_ADMINISTRATOR,  false, &HandleDebugAreaTriggersCommand,    "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "debug",          SEC_MODERATOR,      true,  NULL,                  "", debugCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleDebugPlayCinematicCommand(ChatHandler* handler, const char* args)
    {
        // USAGE: .debug play cinematic #cinematicid
        // #cinematicid - ID decimal number from CinemaicSequences.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 dwId = atoi((char*)args);

        if (!sCinematicSequencesStore.LookupEntry(dwId))
        {
            handler->PSendSysMessage(LANG_CINEMATIC_NOT_EXIST, dwId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->GetPlayer()->SendCinematicStart(dwId);
        return true;
    }

    static bool HandleDebugPlayMovieCommand(ChatHandler* handler, const char* args)
    {
        // USAGE: .debug play movie #movieid
        // #movieid - ID decimal number from Movie.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 dwId = atoi((char*)args);

        if (!sMovieStore.LookupEntry(dwId))
        {
            handler->PSendSysMessage(LANG_MOVIE_NOT_EXIST, dwId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->GetPlayer()->SendMovieStart(dwId);
        return true;
    }

    //Play sound
    static bool HandleDebugPlaySoundCommand(ChatHandler* handler, const char* args)
    {
        // USAGE: .debug playsound #soundid
        // #soundid - ID decimal number from SoundEntries.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 dwSoundId = atoi((char*)args);

        if (!sSoundEntriesStore.LookupEntry(dwSoundId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, dwSoundId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (handler->GetSession()->GetPlayer()->GetSelection())
            unit->PlayDistanceSound(dwSoundId, handler->GetSession()->GetPlayer());
        else
            unit->PlayDirectSound(dwSoundId, handler->GetSession()->GetPlayer());

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, dwSoundId);
        return true;
    }

    static bool HandleDebugSendSpellFailCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* px = strtok((char*)args, " ");
        if (!px)
            return false;

        uint8 failnum = (uint8)atoi(px);
        if (failnum == 0 && *px != '0')
            return false;

        char* p1 = strtok(NULL, " ");
        uint8 failarg1 = p1 ? (uint8)atoi(p1) : 0;

        char* p2 = strtok(NULL, " ");
        uint8 failarg2 = p2 ? (uint8)atoi(p2) : 0;

        WorldPacket data(SMSG_CAST_FAILED, 5);
        data << uint8(0);
        data << uint32(133);
        data << uint8(failnum);
        if (p1 || p2)
            data << uint32(failarg1);
        if (p2)
            data << uint32(failarg2);

        handler->GetSession()->SendPacket(&data);

        return true;
    }

    static bool HandleDebugSendEquipErrorCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        InventoryResult msg = InventoryResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendEquipError(msg, NULL, NULL);
        return true;
    }

    static bool HandleDebugSendSellErrorCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        SellResult msg = SellResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendSellError(msg, 0, 0, 0);
        return true;
    }

    static bool HandleDebugSendBuyErrorCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        BuyResult msg = BuyResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendBuyError(msg, 0, 0, 0);
        return true;
    }

    static bool HandleDebugSendOpcodeCommand(ChatHandler* handler, const char* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        Player* player = NULL;
        if (!unit || (unit->GetTypeId() != TYPEID_PLAYER))
            player = handler->GetSession()->GetPlayer();
        else
            player = (Player*)unit;
        if (!unit) unit = player;

        std::ifstream ifs("opcode.txt");
        if (ifs.bad())
            return false;

        uint32 opcode;
        ifs >> opcode;

        WorldPacket data(opcode, 0);

        while (!ifs.eof())
        {
            std::string type;
            ifs >> type;

            if (type == "")
                break;

            if (type == "uint8")
            {
                uint16 val1;
                ifs >> val1;
                data << uint8(val1);
            }
            else if (type == "uint16")
            {
                uint16 val2;
                ifs >> val2;
                data << val2;
            }
            else if (type == "uint32")
            {
                uint32 val3;
                ifs >> val3;
                data << val3;
            }
            else if (type == "uint64")
            {
                uint64 val4;
                ifs >> val4;
                data << val4;
            }
            else if (type == "float")
            {
                float val5;
                ifs >> val5;
                data << val5;
            }
            else if (type == "string")
            {
                std::string val6;
                ifs >> val6;
                data << val6;
            }
            else if (type == "appitsguid")
            {
                data.append(unit->GetPackGUID());
            }
            else if (type == "appmyguid")
            {
                data.append(player->GetPackGUID());
            }
            else if (type == "appgoguid")
            {
                GameObject* obj = handler->GetNearbyGameObject();
                if (!obj)
                {
                    handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, 0);
                    handler->SetSentErrorMessage(true);
                    ifs.close();
                    return false;
                }
                data.append(obj->GetPackGUID());
            }
            else if (type == "goguid")
            {
                GameObject* obj = handler->GetNearbyGameObject();
                if (!obj)
                {
                    handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, 0);
                    handler->SetSentErrorMessage(true);
                    ifs.close();
                    return false;
                }
                data << uint64(obj->GetGUID());
            }
            else if (type == "myguid")
            {
                data << uint64(player->GetGUID());
            }
            else if (type == "itsguid")
            {
                data << uint64(unit->GetGUID());
            }
            else if (type == "pos")
            {
                data << unit->GetPositionX();
                data << unit->GetPositionY();
                data << unit->GetPositionZ();
            }
            else if (type == "mypos")
            {
                data << player->GetPositionX();
                data << player->GetPositionY();
                data << player->GetPositionZ();
            }
            else
            {
                sLog->outError("Sending opcode: unknown type '%s'", type.c_str());
                break;
            }
        }
        ifs.close();
        sLog->outDebug(LOG_FILTER_NETWORKIO, "Sending opcode %u", data.GetOpcode());
        data.hexlike();
        player->GetSession()->SendPacket(&data);
        handler->PSendSysMessage(LANG_COMMAND_OPCODESENT, data.GetOpcode(), unit->GetName());
        return true;
    }

    static bool HandleDebugUpdateWorldStateCommand(ChatHandler* handler, const char* args)
    {
        char* w = strtok((char*)args, " ");
        char* s = strtok(NULL, " ");

        if (!w || !s)
            return false;

        uint32 world = (uint32)atoi(w);
        uint32 state = (uint32)atoi(s);
        handler->GetSession()->GetPlayer()->SendUpdateWorldState(world, state);
        return true;
    }

    static bool HandleDebugAreaTriggersCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player->isDebugAreaTriggers)
        {
            handler->PSendSysMessage(LANG_DEBUG_AREATRIGGER_ON);
            player->isDebugAreaTriggers = true;
        } else {
            handler->PSendSysMessage(LANG_DEBUG_AREATRIGGER_OFF);
            player->isDebugAreaTriggers = false;
        }
        return true;
    }

    //Send notification in channel
    static bool HandleDebugSendChannelNotifyCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        const char *name = "test";
        uint8 code = atoi(args);

        WorldPacket data(SMSG_CHANNEL_NOTIFY, (1+10));
        data << code;                                           // notify type
        data << name;                                           // channel name
        data << uint32(0);
        data << uint32(0);
        handler->GetSession()->SendPacket(&data);
        return true;
    }

    //Send notification in chat
    static bool HandleDebugSendChatMsgCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        const char *msg = "testtest";
        uint8 type = atoi(args);
        WorldPacket data;
        ChatHandler::FillMessageData(&data, handler->GetSession(), type, 0, "chan", handler->GetSession()->GetPlayer()->GetGUID(), msg, handler->GetSession()->GetPlayer());
        handler->GetSession()->SendPacket(&data);
        return true;
    }

    static bool HandleDebugSendQuestPartyMsgCommand(ChatHandler* handler, const char* args)
    {
        uint32 msg = atol((char*)args);
        handler->GetSession()->GetPlayer()->SendPushToPartyResponse(handler->GetSession()->GetPlayer(), msg);
        return true;
    }

    static bool HandleDebugGetLootRecipientCommand(ChatHandler* handler, const char* /*args*/)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
            return false;

        handler->PSendSysMessage("loot recipient: %s", target->hasLootRecipient()?(target->GetLootRecipient()?target->GetLootRecipient()->GetName():"offline"):"no loot recipient");
        return true;
    }

    static bool HandleDebugSendQuestInvalidMsgCommand(ChatHandler* handler, const char* args)
    {
        uint32 msg = atol((char*)args);
        handler->GetSession()->GetPlayer()->SendCanTakeQuestResponse(msg);
        return true;
    }

    static bool HandleDebugGetItemStateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        std::string state_str = args;

        ItemUpdateState state = ITEM_UNCHANGED;
        bool list_queue = false, check_all = false;
        if (state_str == "unchanged") state = ITEM_UNCHANGED;
        else if (state_str == "changed") state = ITEM_CHANGED;
        else if (state_str == "new") state = ITEM_NEW;
        else if (state_str == "removed") state = ITEM_REMOVED;
        else if (state_str == "queue") list_queue = true;
        else if (state_str == "check_all") check_all = true;
        else return false;

        Player* player = handler->getSelectedPlayer();
        if (!player) player = handler->GetSession()->GetPlayer();

        if (!list_queue && !check_all)
        {
            state_str = "The player has the following " + state_str + " items: ";
            handler->SendSysMessage(state_str.c_str());
            for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
            {
                if (i >= BUYBACK_SLOT_START && i < BUYBACK_SLOT_END)
                    continue;

                if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                {
                    if (Bag* bag = item->ToBag())
                    {
                        for (uint8 j = 0; j < bag->GetBagSize(); ++j)
                            if (Item* item2 = bag->GetItemByPos(j))
                                if (item2->GetState() == state)
                                    handler->PSendSysMessage("bag: 255 slot: %d guid: %d owner: %d", item2->GetSlot(), item2->GetGUIDLow(), GUID_LOPART(item2->GetOwnerGUID()));
                    }
                    else if (item->GetState() == state)
                        handler->PSendSysMessage("bag: 255 slot: %d guid: %d owner: %d", item->GetSlot(), item->GetGUIDLow(), GUID_LOPART(item->GetOwnerGUID()));
                }
            }
        }

        if (list_queue)
        {
            std::vector<Item *> &updateQueue = player->GetItemUpdateQueue();
            for (size_t i = 0; i < updateQueue.size(); ++i)
            {
                Item* item = updateQueue[i];
                if (!item) continue;

                Bag *container = item->GetContainer();
                uint8 bag_slot = container ? container->GetSlot() : uint8(INVENTORY_SLOT_BAG_0);

                std::string st;
                switch(item->GetState())
                {
                case ITEM_UNCHANGED: st = "unchanged"; break;
                case ITEM_CHANGED: st = "changed"; break;
                case ITEM_NEW: st = "new"; break;
                case ITEM_REMOVED: st = "removed"; break;
                }

                handler->PSendSysMessage("bag: %d slot: %d guid: %d - state: %s", bag_slot, item->GetSlot(), item->GetGUIDLow(), st.c_str());
            }
            if (updateQueue.empty())
                handler->PSendSysMessage("updatequeue empty");
        }

        if (check_all)
        {
            bool error = false;
            std::vector<Item *> &updateQueue = player->GetItemUpdateQueue();
            for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
            {
                if (i >= BUYBACK_SLOT_START && i < BUYBACK_SLOT_END)
                    continue;

                Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                if (!item) continue;

                if (item->GetSlot() != i)
                {
                    handler->PSendSysMessage("item at slot %d, guid %d has an incorrect slot value: %d", i, item->GetGUIDLow(), item->GetSlot());
                    error = true; continue;
                }

                if (item->GetOwnerGUID() != player->GetGUID())
                {
                    handler->PSendSysMessage("for the item at slot %d and itemguid %d, owner's guid (%d) and player's guid (%d) don't match!", item->GetSlot(), item->GetGUIDLow(), GUID_LOPART(item->GetOwnerGUID()), player->GetGUIDLow());
                    error = true; continue;
                }

                if (Bag *container = item->GetContainer())
                {
                    handler->PSendSysMessage("item at slot: %d guid: %d has a container (slot: %d, guid: %d) but shouldnt!", item->GetSlot(), item->GetGUIDLow(), container->GetSlot(), container->GetGUIDLow());
                    error = true; continue;
                }

                if (item->IsInUpdateQueue())
                {
                    uint16 qp = item->GetQueuePos();
                    if (qp > updateQueue.size())
                    {
                        handler->PSendSysMessage("item at slot: %d guid: %d has a queuepos (%d) larger than the update queue size! ", item->GetSlot(), item->GetGUIDLow(), qp);
                        error = true; continue;
                    }

                    if (updateQueue[qp] == NULL)
                    {
                        handler->PSendSysMessage("item at slot: %d guid: %d has a queuepos (%d) that points to NULL in the queue!", item->GetSlot(), item->GetGUIDLow(), qp);
                        error = true; continue;
                    }

                    if (updateQueue[qp] != item)
                    {
                        handler->PSendSysMessage("item at slot: %d guid: %d has has a queuepos (%d) that points to another item in the queue (bag: %d, slot: %d, guid: %d)", item->GetSlot(), item->GetGUIDLow(), qp, updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot(), updateQueue[qp]->GetGUIDLow());
                        error = true; continue;
                    }
                }
                else if (item->GetState() != ITEM_UNCHANGED)
                {
                    handler->PSendSysMessage("item at slot: %d guid: %d is not in queue but should be (state: %d)!", item->GetSlot(), item->GetGUIDLow(), item->GetState());
                    error = true; continue;
                }

                if (Bag* bag = item->ToBag())
                {
                    for (uint8 j = 0; j < bag->GetBagSize(); ++j)
                    {
                        Item* item2 = bag->GetItemByPos(j);
                        if (!item2) continue;

                        if (item2->GetSlot() != j)
                        {
                            handler->PSendSysMessage("the item in bag %d slot %d, guid %d has an incorrect slot value: %d", bag->GetSlot(), j, item2->GetGUIDLow(), item2->GetSlot());
                            error = true; continue;
                        }

                        if (item2->GetOwnerGUID() != player->GetGUID())
                        {
                            handler->PSendSysMessage("for the item in bag %d at slot %d and itemguid %d, owner's guid (%d) and player's guid (%d) don't match!", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow(), GUID_LOPART(item2->GetOwnerGUID()), player->GetGUIDLow());
                            error = true; continue;
                        }

                        Bag *container = item2->GetContainer();
                        if (!container)
                        {
                            handler->PSendSysMessage("the item in bag %d at slot %d with guid %d has no container!", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow());
                            error = true; continue;
                        }

                        if (container != bag)
                        {
                            handler->PSendSysMessage("the item in bag %d at slot %d with guid %d has a different container(slot %d guid %d)!", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow(), container->GetSlot(), container->GetGUIDLow());
                            error = true; continue;
                        }

                        if (item2->IsInUpdateQueue())
                        {
                            uint16 qp = item2->GetQueuePos();
                            if (qp > updateQueue.size())
                            {
                                handler->PSendSysMessage("item in bag: %d at slot: %d guid: %d has a queuepos (%d) larger than the update queue size! ", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow(), qp);
                                error = true; continue;
                            }

                            if (updateQueue[qp] == NULL)
                            {
                                handler->PSendSysMessage("item in bag: %d at slot: %d guid: %d has a queuepos (%d) that points to NULL in the queue!", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow(), qp);
                                error = true; continue;
                            }

                            if (updateQueue[qp] != item2)
                            {
                                handler->PSendSysMessage("item in bag: %d at slot: %d guid: %d has has a queuepos (%d) that points to another item in the queue (bag: %d, slot: %d, guid: %d)", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow(), qp, updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot(), updateQueue[qp]->GetGUIDLow());
                                error = true; continue;
                            }
                        }
                        else if (item2->GetState() != ITEM_UNCHANGED)
                        {
                            handler->PSendSysMessage("item in bag: %d at slot: %d guid: %d is not in queue but should be (state: %d)!", bag->GetSlot(), item2->GetSlot(), item2->GetGUIDLow(), item2->GetState());
                            error = true; continue;
                        }
                    }
                }
            }

            for (size_t i = 0; i < updateQueue.size(); ++i)
            {
                Item* item = updateQueue[i];
                if (!item) continue;

                if (item->GetOwnerGUID() != player->GetGUID())
                {
                    handler->PSendSysMessage("queue(" SIZEFMTD "): for the an item (guid %d), the owner's guid (%d) and player's guid (%d) don't match!", i, item->GetGUIDLow(), GUID_LOPART(item->GetOwnerGUID()), player->GetGUIDLow());
                    error = true; continue;
                }

                if (item->GetQueuePos() != i)
                {
                    handler->PSendSysMessage("queue(" SIZEFMTD "): for the an item (guid %d), the queuepos doesn't match it's position in the queue!", i, item->GetGUIDLow());
                    error = true; continue;
                }

                if (item->GetState() == ITEM_REMOVED) continue;
                Item* test = player->GetItemByPos(item->GetBagSlot(), item->GetSlot());

                if (test == NULL)
                {
                    handler->PSendSysMessage("queue(" SIZEFMTD "): the bag(%d) and slot(%d) values for the item with guid %d are incorrect, the player doesn't have an item at that position!", i, item->GetBagSlot(), item->GetSlot(), item->GetGUIDLow());
                    error = true; continue;
                }

                if (test != item)
                {
                    handler->PSendSysMessage("queue(" SIZEFMTD "): the bag(%d) and slot(%d) values for the item with guid %d are incorrect, the item with guid %d is there instead!", i, item->GetBagSlot(), item->GetSlot(), item->GetGUIDLow(), test->GetGUIDLow());
                    error = true; continue;
                }
            }
            if (!error)
                handler->SendSysMessage("All OK!");
        }

        return true;
    }

    static bool HandleDebugBattlegroundCommand(ChatHandler* /*handler*/, const char* /*args*/)
    {
        sBattlegroundMgr->ToggleTesting();
        return true;
    }

    static bool HandleDebugArenaCommand(ChatHandler* /*handler*/, const char* /*args*/)
    {
        sBattlegroundMgr->ToggleArenaTesting();
        return true;
    }

    static bool HandleDebugThreatListCommand(ChatHandler* handler, const char* /*args*/)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target || target->isTotem() || target->isPet())
            return false;

        std::list<HostileReference*>& tlist = target->getThreatManager().getThreatList();
        std::list<HostileReference*>::iterator itr;
        uint32 cnt = 0;
        handler->PSendSysMessage("Threat list of %s (guid %u)", target->GetName(), target->GetGUIDLow());
        for (itr = tlist.begin(); itr != tlist.end(); ++itr)
        {
            Unit* unit = (*itr)->getTarget();
            if (!unit)
                continue;
            ++cnt;
            handler->PSendSysMessage("   %u.   %s   (guid %u)  - threat %f", cnt, unit->GetName(), unit->GetGUIDLow(), (*itr)->getThreat());
        }
        handler->SendSysMessage("End of threat list.");
        return true;
    }

    static bool HandleDebugHostileRefListCommand(ChatHandler* handler, const char* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();
        HostileReference* ref = target->getHostileRefManager().getFirst();
        uint32 cnt = 0;
        handler->PSendSysMessage("Hostil reference list of %s (guid %u)", target->GetName(), target->GetGUIDLow());
        while (ref)
        {
            if (Unit* unit = ref->getSource()->getOwner())
            {
                ++cnt;
                handler->PSendSysMessage("   %u.   %s   (guid %u)  - threat %f", cnt, unit->GetName(), unit->GetGUIDLow(), ref->getThreat());
            }
            ref = ref->next();
        }
        handler->SendSysMessage("End of hostil reference list.");
        return true;
    }

    static bool HandleDebugSetVehicleIdCommand(ChatHandler* handler, const char* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target || target->IsVehicle())
            return false;

        if (!args)
            return false;

        char* i = strtok((char*)args, " ");
        if (!i)
            return false;

        uint32 id = (uint32)atoi(i);
        //target->SetVehicleId(id);
        handler->PSendSysMessage("Vehicle id set to %u", id);
        return true;
    }

    static bool HandleDebugEnterVehicleCommand(ChatHandler* handler, const char* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target || !target->IsVehicle())
            return false;

        if (!args)
            return false;

        char* i = strtok((char*)args, " ");
        if (!i)
            return false;

        char* j = strtok(NULL, " ");

        uint32 entry = (uint32)atoi(i);
        int8 seatId = j ? (int8)atoi(j) : -1;

        if (!entry)
            handler->GetSession()->GetPlayer()->EnterVehicle(target, seatId);
        else
        {
            Creature* passenger = NULL;
            Trinity::AllCreaturesOfEntryInRange check(handler->GetSession()->GetPlayer(), entry, 20.0f);
            Trinity::CreatureSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(handler->GetSession()->GetPlayer(), passenger, check);
            handler->GetSession()->GetPlayer()->VisitNearbyObject(30.0f, searcher);
            if (!passenger || passenger == target)
                return false;
            passenger->EnterVehicle(target, seatId);
        }

        handler->PSendSysMessage("Unit %u entered vehicle %d", entry, (int32)seatId);
        return true;
    }

    static bool HandleDebugSpawnVehicleCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* i = strtok(NULL, " ");

        if (!e)
            return false;

        uint32 entry = (uint32)atoi(e);

        float x, y, z, o = handler->GetSession()->GetPlayer()->GetOrientation();
        handler->GetSession()->GetPlayer()->GetClosePoint(x, y, z, handler->GetSession()->GetPlayer()->GetObjectSize());

        if (!i)
            return handler->GetSession()->GetPlayer()->SummonCreature(entry, x, y, z, o);

        uint32 id = (uint32)atoi(i);

        CreatureTemplate const *ci = sObjectMgr->GetCreatureTemplate(entry);

        if (!ci)
            return false;

        VehicleEntry const *ve = sVehicleStore.LookupEntry(id);

        if (!ve)
            return false;

        Creature* v = new Creature;

        Map *map = handler->GetSession()->GetPlayer()->GetMap();

        if (!v->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_VEHICLE), map, handler->GetSession()->GetPlayer()->GetPhaseMask(), entry, id, handler->GetSession()->GetPlayer()->GetTeam(), x, y, z, o))
        {
            delete v;
            return false;
        }

        map->Add(v->ToCreature());

        return true;
    }

    static bool HandleDebugSendLargePacketCommand(ChatHandler* handler, const char* /*args*/)
    {
        const char* stuffingString = "This is a dummy string to push the packet's size beyond 128000 bytes. ";
        std::ostringstream ss;
        while (ss.str().size() < 128000)
            ss << stuffingString;
        handler->SendSysMessage(ss.str().c_str());
        return true;
    }

    static bool HandleDebugSendSetPhaseShiftCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 PhaseShift = atoi(args);
        handler->GetSession()->SendSetPhaseShift(PhaseShift);
        return true;
    }

    static bool HandleDebugGetItemValueCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* f = strtok(NULL, " ");

        if (!e || !f)
            return false;

        uint32 guid = (uint32)atoi(e);
        uint32 index = (uint32)atoi(f);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(MAKE_NEW_GUID(guid, 0, HIGHGUID_ITEM));

        if (!i)
            return false;

        if (index >= i->GetValuesCount())
            return false;

        uint32 value = i->GetUInt32Value(index);

        handler->PSendSysMessage("Item %u: value at %u is %u", guid, index, value);

        return true;
    }

    static bool HandleDebugSetItemValueCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* f = strtok(NULL, " ");
        char* g = strtok(NULL, " ");

        if (!e || !f || !g)
            return false;

        uint32 guid = (uint32)atoi(e);
        uint32 index = (uint32)atoi(f);
        uint32 value = (uint32)atoi(g);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(MAKE_NEW_GUID(guid, 0, HIGHGUID_ITEM));

        if (!i)
            return false;

        if (index >= i->GetValuesCount())
            return false;

        i->SetUInt32Value(index, value);

        return true;
    }

    static bool HandleDebugItemExpireCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        if (!e)
            return false;

        uint32 guid = (uint32)atoi(e);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(MAKE_NEW_GUID(guid, 0, HIGHGUID_ITEM));

        if (!i)
            return false;

        handler->GetSession()->GetPlayer()->DestroyItem(i->GetBagSlot(), i->GetSlot(), true);
        sScriptMgr->OnItemExpire(handler->GetSession()->GetPlayer(), i->GetTemplate());

        return true;
    }

    //show animation
    static bool HandleDebugAnimCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 anim_id = atoi((char*)args);
        handler->GetSession()->GetPlayer()->HandleEmoteCommand(anim_id);
        return true;
    }

    static bool HandleDebugSetAuraStateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 state = atoi((char*)args);
        if (!state)
        {
            // reset all states
            for (int i = 1; i <= 32; ++i)
                unit->ModifyAuraState(AuraState(i), false);
            return true;
        }

        unit->ModifyAuraState(AuraState(abs(state)), state > 0);
        return true;
    }

    static bool HandleDebugSetValueCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* px = strtok((char*)args, " ");
        char* py = strtok(NULL, " ");
        char* pz = strtok(NULL, " ");

        if (!px || !py)
            return false;

        WorldObject* target = handler->getSelectedObject();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint64 guid = target->GetGUID();

        uint32 Opcode = (uint32)atoi(px);
        if (Opcode >= target->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, Opcode, GUID_LOPART(guid), target->GetValuesCount());
            return false;
        }
        uint32 iValue;
        float fValue;
        bool isint32 = true;
        if (pz)
            isint32 = (bool)atoi(pz);
        if (isint32)
        {
            iValue = (uint32)atoi(py);
            target->SetUInt32Value(Opcode , iValue);
            handler->PSendSysMessage(LANG_SET_UINT_FIELD, GUID_LOPART(guid), Opcode, iValue);
        }
        else
        {
            fValue = (float)atof(py);
            target->SetFloatValue(Opcode , fValue);
            handler->PSendSysMessage(LANG_SET_FLOAT_FIELD, GUID_LOPART(guid), Opcode, fValue);
        }

        return true;
    }

    static bool HandleDebugGetValueCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* px = strtok((char*)args, " ");
        char* pz = strtok(NULL, " ");

        if (!px)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint64 guid = target->GetGUID();

        uint32 Opcode = (uint32)atoi(px);
        if (Opcode >= target->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, Opcode, GUID_LOPART(guid), target->GetValuesCount());
            return false;
        }
        uint32 iValue;
        float fValue;
        bool isint32 = true;
        if (pz)
            isint32 = (bool)atoi(pz);

        if (isint32)
        {
            iValue = target->GetUInt32Value(Opcode);
            handler->PSendSysMessage(LANG_GET_UINT_FIELD, GUID_LOPART(guid), Opcode,    iValue);
        }
        else
        {
            fValue = target->GetFloatValue(Opcode);
            handler->PSendSysMessage(LANG_GET_FLOAT_FIELD, GUID_LOPART(guid), Opcode, fValue);
        }

        return true;
    }

    static bool HandleDebugMod32ValueCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* px = strtok((char*)args, " ");
        char* py = strtok(NULL, " ");

        if (!px || !py)
            return false;

        uint32 Opcode = (uint32)atoi(px);
        int Value = atoi(py);

        if (Opcode >= handler->GetSession()->GetPlayer()->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, Opcode, handler->GetSession()->GetPlayer()->GetGUIDLow(), handler->GetSession()->GetPlayer()->GetValuesCount());
            return false;
        }

        int CurrentValue = (int)handler->GetSession()->GetPlayer()->GetUInt32Value(Opcode);

        CurrentValue += Value;
        handler->GetSession()->GetPlayer()->SetUInt32Value(Opcode , (uint32)CurrentValue);

        handler->PSendSysMessage(LANG_CHANGE_32BIT_FIELD, Opcode, CurrentValue);

        return true;
    }

    static bool HandleDebugUpdateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 updateIndex;
        uint32 value;

        char* pUpdateIndex = strtok((char*)args, " ");

        Unit* chr = handler->getSelectedUnit();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!pUpdateIndex)
        {
            return true;
        }
        updateIndex = atoi(pUpdateIndex);
        //check updateIndex
        if (chr->GetTypeId() == TYPEID_PLAYER)
        {
            if (updateIndex >= PLAYER_END) return true;
        }
        else
        {
            if (updateIndex >= UNIT_END) return true;
        }

        char*  pvalue = strtok(NULL, " ");
        if (!pvalue)
        {
            value=chr->GetUInt32Value(updateIndex);

            handler->PSendSysMessage(LANG_UPDATE, chr->GetGUIDLow(), updateIndex, value);
            return true;
        }

        value=atoi(pvalue);

        handler->PSendSysMessage(LANG_UPDATE_CHANGE, chr->GetGUIDLow(), updateIndex, value);

        chr->SetUInt32Value(updateIndex, value);

        return true;
    }
    static bool HandleDebugSet32BitCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        WorldObject* target = handler->getSelectedObject();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* px = strtok((char*)args, " ");
        char* py = strtok(NULL, " ");

        if (!px || !py)
            return false;

        uint32 Opcode = (uint32)atoi(px);
        uint32 Value = (uint32)atoi(py);
        if (Value > 32)                                         //uint32 = 32 bits
            return false;

        uint32 iValue = Value ? 1 << (Value - 1) : 0;
        target->SetUInt32Value(Opcode ,  iValue);

        handler->PSendSysMessage(LANG_SET_32BIT_FIELD, Opcode, iValue);
        return true;
    }
};

void AddSC_debug_commandscript()
{
    new debug_commandscript();
}
