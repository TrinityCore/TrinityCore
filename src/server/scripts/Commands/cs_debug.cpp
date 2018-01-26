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

/* ScriptData
Name: debug_commandscript
%Complete: 100
Comment: All debug related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Bag.h"
#include "BattlefieldMgr.h"
#include "BattlegroundMgr.h"
#include "CellImpl.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Conversation.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "Language.h"
#include "Log.h"
#include "M2Stores.h"
#include "MapManager.h"
#include "MovementPackets.h"
#include "ObjectMgr.h"
#include "RBAC.h"
#include "SpellPackets.h"
#include "Transport.h"
#include "WorldSession.h"
#include <fstream>
#include <limits>

class debug_commandscript : public CommandScript
{
public:
    debug_commandscript() : CommandScript("debug_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> debugPlayCommandTable =
        {
            { "cinematic",     rbac::RBAC_PERM_COMMAND_DEBUG_PLAY_CINEMATIC, false, &HandleDebugPlayCinematicCommand,   "" },
            { "movie",         rbac::RBAC_PERM_COMMAND_DEBUG_PLAY_MOVIE,     false, &HandleDebugPlayMovieCommand,       "" },
            { "sound",         rbac::RBAC_PERM_COMMAND_DEBUG_PLAY_SOUND,     false, &HandleDebugPlaySoundCommand,       "" },
        };
        static std::vector<ChatCommand> debugSendCommandTable =
        {
            { "buyerror",      rbac::RBAC_PERM_COMMAND_DEBUG_SEND_BUYERROR,      false, &HandleDebugSendBuyErrorCommand,        "" },
            { "channelnotify", rbac::RBAC_PERM_COMMAND_DEBUG_SEND_CHANNELNOTIFY, false, &HandleDebugSendChannelNotifyCommand,   "" },
            { "chatmessage",   rbac::RBAC_PERM_COMMAND_DEBUG_SEND_CHATMESSAGE,   false, &HandleDebugSendChatMsgCommand,         "" },
            { "equiperror",    rbac::RBAC_PERM_COMMAND_DEBUG_SEND_EQUIPERROR,    false, &HandleDebugSendEquipErrorCommand,      "" },
            { "largepacket",   rbac::RBAC_PERM_COMMAND_DEBUG_SEND_LARGEPACKET,   false, &HandleDebugSendLargePacketCommand,     "" },
            { "opcode",        rbac::RBAC_PERM_COMMAND_DEBUG_SEND_OPCODE,        false, &HandleDebugSendOpcodeCommand,          "" },
            { "qpartymsg",     rbac::RBAC_PERM_COMMAND_DEBUG_SEND_QPARTYMSG,     false, &HandleDebugSendQuestPartyMsgCommand,   "" },
            { "qinvalidmsg",   rbac::RBAC_PERM_COMMAND_DEBUG_SEND_QINVALIDMSG,   false, &HandleDebugSendQuestInvalidMsgCommand, "" },
            { "sellerror",     rbac::RBAC_PERM_COMMAND_DEBUG_SEND_SELLERROR,     false, &HandleDebugSendSellErrorCommand,       "" },
            { "setphaseshift", rbac::RBAC_PERM_COMMAND_DEBUG_SEND_SETPHASESHIFT, false, &HandleDebugSendSetPhaseShiftCommand,   "" },
            { "spellfail",     rbac::RBAC_PERM_COMMAND_DEBUG_SEND_SPELLFAIL,     false, &HandleDebugSendSpellFailCommand,       "" },
            { "playerchoice",  rbac::RBAC_PERM_COMMAND_DEBUG_SEND_PLAYER_CHOICE, false, &HandleDebugSendPlayerChoiceCommand,    "" },
        };
        static std::vector<ChatCommand> debugCommandTable =
        {
            { "setbit",        rbac::RBAC_PERM_COMMAND_DEBUG_SETBIT,        false, &HandleDebugSet32BitCommand,         "" },
            { "threat",        rbac::RBAC_PERM_COMMAND_DEBUG_THREAT,        false, &HandleDebugThreatListCommand,       "" },
            { "hostil",        rbac::RBAC_PERM_COMMAND_DEBUG_HOSTIL,        false, &HandleDebugHostileRefListCommand,   "" },
            { "anim",          rbac::RBAC_PERM_COMMAND_DEBUG_ANIM,          false, &HandleDebugAnimCommand,             "" },
            { "arena",         rbac::RBAC_PERM_COMMAND_DEBUG_ARENA,         true,  &HandleDebugArenaCommand,            "" },
            { "bg",            rbac::RBAC_PERM_COMMAND_DEBUG_BG,            true,  &HandleDebugBattlegroundCommand,     "" },
            { "getitemstate",  rbac::RBAC_PERM_COMMAND_DEBUG_GETITEMSTATE,  false, &HandleDebugGetItemStateCommand,     "" },
            { "lootrecipient", rbac::RBAC_PERM_COMMAND_DEBUG_LOOTRECIPIENT, false, &HandleDebugGetLootRecipientCommand, "" },
            { "getvalue",      rbac::RBAC_PERM_COMMAND_DEBUG_GETVALUE,      false, &HandleDebugGetValueCommand,         "" },
            { "getitemvalue",  rbac::RBAC_PERM_COMMAND_DEBUG_GETITEMVALUE,  false, &HandleDebugGetItemValueCommand,     "" },
            { "Mod32Value",    rbac::RBAC_PERM_COMMAND_DEBUG_MOD32VALUE,    false, &HandleDebugMod32ValueCommand,       "" },
            { "play",          rbac::RBAC_PERM_COMMAND_DEBUG_PLAY,          false, nullptr,                             "", debugPlayCommandTable },
            { "send",          rbac::RBAC_PERM_COMMAND_DEBUG_SEND,          false, nullptr,                             "", debugSendCommandTable },
            { "setaurastate",  rbac::RBAC_PERM_COMMAND_DEBUG_SETAURASTATE,  false, &HandleDebugSetAuraStateCommand,     "" },
            { "setitemvalue",  rbac::RBAC_PERM_COMMAND_DEBUG_SETITEMVALUE,  false, &HandleDebugSetItemValueCommand,     "" },
            { "setvalue",      rbac::RBAC_PERM_COMMAND_DEBUG_SETVALUE,      false, &HandleDebugSetValueCommand,         "" },
            { "spawnvehicle",  rbac::RBAC_PERM_COMMAND_DEBUG_SPAWNVEHICLE,  false, &HandleDebugSpawnVehicleCommand,     "" },
            { "setvid",        rbac::RBAC_PERM_COMMAND_DEBUG_SETVID,        false, &HandleDebugSetVehicleIdCommand,     "" },
            { "entervehicle",  rbac::RBAC_PERM_COMMAND_DEBUG_ENTERVEHICLE,  false, &HandleDebugEnterVehicleCommand,     "" },
            { "uws",           rbac::RBAC_PERM_COMMAND_DEBUG_UWS,           false, &HandleDebugUpdateWorldStateCommand, "" },
            { "update",        rbac::RBAC_PERM_COMMAND_DEBUG_UPDATE,        false, &HandleDebugUpdateCommand,           "" },
            { "itemexpire",    rbac::RBAC_PERM_COMMAND_DEBUG_ITEMEXPIRE,    false, &HandleDebugItemExpireCommand,       "" },
            { "areatriggers",  rbac::RBAC_PERM_COMMAND_DEBUG_AREATRIGGERS,  false, &HandleDebugAreaTriggersCommand,     "" },
            { "los",           rbac::RBAC_PERM_COMMAND_DEBUG_LOS,           false, &HandleDebugLoSCommand,              "" },
            { "moveflags",     rbac::RBAC_PERM_COMMAND_DEBUG_MOVEFLAGS,     false, &HandleDebugMoveflagsCommand,        "" },
            { "transport",     rbac::RBAC_PERM_COMMAND_DEBUG_TRANSPORT,     false, &HandleDebugTransportCommand,        "" },
            { "loadcells",     rbac::RBAC_PERM_COMMAND_DEBUG_LOADCELLS,     false, &HandleDebugLoadCellsCommand,        "",},
            { "phase",         rbac::RBAC_PERM_COMMAND_DEBUG_PHASE,         false, &HandleDebugPhaseCommand,            "" },
            { "boundary",      rbac::RBAC_PERM_COMMAND_DEBUG_BOUNDARY,      false, &HandleDebugBoundaryCommand,         "" },
            { "raidreset",     rbac::RBAC_PERM_COMMAND_INSTANCE_UNBIND,     false, &HandleDebugRaidResetCommand,        "" },
            { "neargraveyard", rbac::RBAC_PERM_COMMAND_NEARGRAVEYARD,       false, &HandleDebugNearGraveyard,           "" },
            { "conversation" , rbac::RBAC_PERM_COMMAND_DEBUG_CONVERSATION,  false, &HandleDebugConversationCommand,     "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "debug",         rbac::RBAC_PERM_COMMAND_DEBUG,               true,  nullptr,                             "", debugCommandTable },
            { "wpgps",         rbac::RBAC_PERM_COMMAND_WPGPS,               false, &HandleWPGPSCommand,                 "" },
        };
        return commandTable;
    }

    static bool HandleDebugPlayCinematicCommand(ChatHandler* handler, char const* args)
    {
        // USAGE: .debug play cinematic #cinematicid
        // #cinematicid - ID decimal number from CinemaicSequences.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 id = atoul(args);

        CinematicSequencesEntry const* cineSeq = sCinematicSequencesStore.LookupEntry(id);
        if (!cineSeq)
        {
            handler->PSendSysMessage(LANG_CINEMATIC_NOT_EXIST, id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Dump camera locations
        if (std::vector<FlyByCamera> const* flyByCameras = GetFlyByCameras(cineSeq->Camera[0]))
        {
            handler->PSendSysMessage("Waypoints for sequence %u, camera %u", id, cineSeq->Camera[0]);
            uint32 count = 1;
            for (FlyByCamera const& cam : *flyByCameras)
            {
                handler->PSendSysMessage("%02u - %7ums [%s (%f degrees)]", count, cam.timeStamp, cam.locations.ToString().c_str(), cam.locations.GetOrientation() * (180 / M_PI));
                count++;
            }
            handler->PSendSysMessage(SZFMTD " waypoints dumped", flyByCameras->size());
        }

        handler->GetSession()->GetPlayer()->SendCinematicStart(id);
        return true;
    }

    static bool HandleDebugPlayMovieCommand(ChatHandler* handler, char const* args)
    {
        // USAGE: .debug play movie #movieid
        // #movieid - ID decimal number from Movie.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 id = atoul(args);

        if (!sMovieStore.LookupEntry(id))
        {
            handler->PSendSysMessage(LANG_MOVIE_NOT_EXIST, id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->GetPlayer()->SendMovieStart(id);
        return true;
    }

    //Play sound
    static bool HandleDebugPlaySoundCommand(ChatHandler* handler, char const* args)
    {
        // USAGE: .debug playsound #soundid
        // #soundid - ID decimal number from SoundEntries.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 soundId = atoul(args);

        if (!sSoundKitStore.LookupEntry(soundId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, soundId);
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

        if (!handler->GetSession()->GetPlayer()->GetTarget().IsEmpty())
            unit->PlayDistanceSound(soundId, handler->GetSession()->GetPlayer());
        else
            unit->PlayDirectSound(soundId, handler->GetSession()->GetPlayer());

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, soundId);
        return true;
    }

    static bool HandleDebugSendSpellFailCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* result = strtok((char*)args, " ");
        if (!result)
            return false;

        uint8 failNum = (uint8)atoi(result);
        if (failNum == 0 && *result != '0')
            return false;

        char* fail1 = strtok(NULL, " ");
        uint8 failArg1 = fail1 ? (uint8)atoi(fail1) : 0;

        char* fail2 = strtok(NULL, " ");
        uint8 failArg2 = fail2 ? (uint8)atoi(fail2) : 0;

        WorldPackets::Spells::CastFailed castFailed;
        castFailed.CastID = ObjectGuid::Empty;
        castFailed.SpellID = 133;
        castFailed.Reason = failNum;
        castFailed.FailedArg1 = failArg1;
        castFailed.FailedArg2 = failArg2;
        handler->GetSession()->SendPacket(castFailed.Write());

        return true;
    }

    static bool HandleDebugSendPlayerChoiceCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        int32 choiceId = atoi(args);
        Player* player = handler->GetSession()->GetPlayer();

        player->SendPlayerChoice(player->GetGUID(), choiceId);
        return true;
    }

    static bool HandleDebugSendEquipErrorCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        InventoryResult msg = InventoryResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendEquipError(msg, NULL, NULL);
        return true;
    }

    static bool HandleDebugSendSellErrorCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        SellResult msg = SellResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendSellError(msg, nullptr, ObjectGuid::Empty);
        return true;
    }

    static bool HandleDebugSendBuyErrorCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        BuyResult msg = BuyResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendBuyError(msg, nullptr, 0, 0);
        return true;
    }

    static bool HandleDebugSendOpcodeCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        Player* player = NULL;
        if (!unit || (unit->GetTypeId() != TYPEID_PLAYER))
            player = handler->GetSession()->GetPlayer();
        else
            player = unit->ToPlayer();

        if (!unit)
            unit = player;

        std::ifstream ifs("opcode.txt");
        if (ifs.fail())
            return false;

        // remove comments from file
        std::stringstream parsedStream;
        while (!ifs.eof())
        {
            char commentToken[2];
            ifs.get(commentToken[0]);
            if (commentToken[0] == '/' && !ifs.eof())
            {
                ifs.get(commentToken[1]);
                // /* comment
                if (commentToken[1] == '*')
                {
                    while (!ifs.eof())
                    {
                        ifs.get(commentToken[0]);
                        if (commentToken[0] == '*' && !ifs.eof())
                        {
                            ifs.get(commentToken[1]);
                            if (commentToken[1] == '/')
                                break;
                            else
                                ifs.putback(commentToken[1]);
                        }
                    }
                    continue;
                }
                // line comment
                else if (commentToken[1] == '/')
                {
                    std::string str;
                    std::getline(ifs, str);
                    continue;
                }
                // regular data
                else
                    ifs.putback(commentToken[1]);
            }
            parsedStream.put(commentToken[0]);
        }
        ifs.close();

        uint32 opcode;
        parsedStream >> opcode;

        WorldPacket data(OpcodeServer(opcode), 0);

        while (!parsedStream.eof())
        {
            std::string type;
            parsedStream >> type;

            if (type.empty())
                break;

            if (type == "uint8")
            {
                uint16 val1;
                parsedStream >> val1;
                data << uint8(val1);
            }
            else if (type == "uint16")
            {
                uint16 val2;
                parsedStream >> val2;
                data << val2;
            }
            else if (type == "uint32")
            {
                uint32 val3;
                parsedStream >> val3;
                data << val3;
            }
            else if (type == "uint64")
            {
                uint64 val4;
                parsedStream >> val4;
                data << val4;
            }
            else if (type == "float")
            {
                float val5;
                parsedStream >> val5;
                data << val5;
            }
            else if (type == "string")
            {
                std::string val6;
                parsedStream >> val6;
                data << val6;
            }
            else if (type == "goguid")
            {
                GameObject* obj = handler->GetNearbyGameObject();
                if (!obj)
                {
                    handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, "0");
                    handler->SetSentErrorMessage(true);
                    ifs.close();
                    return false;
                }
                data << obj->GetGUID();
            }
            else if (type == "myguid")
            {
                data << player->GetGUID();
            }
            else if (type == "itsguid")
            {
                data << unit->GetGUID();
            }
            else if (type == "itspos")
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
                TC_LOG_ERROR("misc", "Sending opcode that has unknown type '%s'", type.c_str());
                break;
            }
        }
        TC_LOG_DEBUG("network", "Sending opcode %u", data.GetOpcode());
        data.hexlike();
        player->GetSession()->SendPacket(&data, true);
        handler->PSendSysMessage(LANG_COMMAND_OPCODESENT, data.GetOpcode(), unit->GetName().c_str());
        return true;
    }

    static bool HandleDebugUpdateWorldStateCommand(ChatHandler* handler, char const* args)
    {
        char* w = strtok((char*)args, " ");
        char* s = strtok(NULL, " ");

        if (!w || !s)
            return false;

        uint32 world = atoul(w);
        uint32 state = atoul(s);
        handler->GetSession()->GetPlayer()->SendUpdateWorldState(world, state);
        return true;
    }

    static bool HandleDebugAreaTriggersCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player->isDebugAreaTriggers)
        {
            handler->PSendSysMessage(LANG_DEBUG_AREATRIGGER_ON);
            player->isDebugAreaTriggers = true;
        }
        else
        {
            handler->PSendSysMessage(LANG_DEBUG_AREATRIGGER_OFF);
            player->isDebugAreaTriggers = false;
        }
        return true;
    }

    //Send notification in channel
    static bool HandleDebugSendChannelNotifyCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* name = "test";
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
    static bool HandleDebugSendChatMsgCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* msg = "testtest";
        uint8 type = atoi(args);
        WorldPackets::Chat::Chat packet;
        packet.Initialize(ChatMsg(type), LANG_UNIVERSAL, handler->GetSession()->GetPlayer(), handler->GetSession()->GetPlayer(), msg, 0, "chan");
        handler->GetSession()->SendPacket(packet.Write());
        return true;
    }

    static bool HandleDebugSendQuestPartyMsgCommand(ChatHandler* handler, char const* args)
    {
        uint32 msg = atoul(args);
        handler->GetSession()->GetPlayer()->SendPushToPartyResponse(handler->GetSession()->GetPlayer(), static_cast<QuestPushReason>(msg));
        return true;
    }

    static bool HandleDebugGetLootRecipientCommand(ChatHandler* handler, char const* /*args*/)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
            return false;

        handler->PSendSysMessage("Loot recipient for creature %s (%s, DB GUID %s) is %s",
            target->GetName().c_str(), target->GetGUID().ToString().c_str(), std::to_string(target->GetSpawnId()).c_str(),
            target->hasLootRecipient() ? (target->GetLootRecipient() ? target->GetLootRecipient()->GetName().c_str() : "offline") : "no loot recipient");
        return true;
    }

    static bool HandleDebugSendQuestInvalidMsgCommand(ChatHandler* handler, char const* args)
    {
        QuestFailedReason msg = static_cast<QuestFailedReason>(atoul(args));
        handler->GetSession()->GetPlayer()->SendCanTakeQuestResponse(msg);
        return true;
    }

    static bool HandleDebugGetItemStateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string itemState = args;

        ItemUpdateState state = ITEM_UNCHANGED;
        bool listQueue = false;
        bool checkAll = false;

        if (itemState == "unchanged")
            state = ITEM_UNCHANGED;
        else if (itemState == "changed")
            state = ITEM_CHANGED;
        else if (itemState == "new")
            state = ITEM_NEW;
        else if (itemState == "removed")
            state = ITEM_REMOVED;
        else if (itemState == "queue")
            listQueue = true;
        else if (itemState == "check_all")
            checkAll = true;
        else
            return false;

        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        if (!listQueue && !checkAll)
        {
            itemState = "The player has the following " + itemState + " items: ";
            handler->SendSysMessage(itemState.c_str());
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
                                    handler->PSendSysMessage("bag: 255 slot: %d %s owner: %s", item2->GetSlot(), item2->GetGUID().ToString().c_str(), item2->GetOwnerGUID().ToString().c_str());
                    }
                    else if (item->GetState() == state)
                        handler->PSendSysMessage("bag: 255 slot: %d %s owner: %s", item->GetSlot(), item->GetGUID().ToString().c_str(), item->GetOwnerGUID().ToString().c_str());
                }
            }
        }

        if (listQueue)
        {
            std::vector<Item*>& updateQueue = player->GetItemUpdateQueue();
            for (size_t i = 0; i < updateQueue.size(); ++i)
            {
                Item* item = updateQueue[i];
                if (!item)
                    continue;

                Bag* container = item->GetContainer();
                uint8 bagSlot = container ? container->GetSlot() : uint8(INVENTORY_SLOT_BAG_0);

                std::string st;
                switch (item->GetState())
                {
                    case ITEM_UNCHANGED:
                        st = "unchanged";
                        break;
                    case ITEM_CHANGED:
                        st = "changed";
                        break;
                    case ITEM_NEW:
                        st = "new";
                        break;
                    case ITEM_REMOVED:
                        st = "removed";
                        break;
                }

                handler->PSendSysMessage("bag: %d slot: %d %s - state: %s", bagSlot, item->GetSlot(), item->GetGUID().ToString().c_str(), st.c_str());
            }
            if (updateQueue.empty())
                handler->PSendSysMessage("The player's updatequeue is empty");
        }

        if (checkAll)
        {
            bool error = false;
            std::vector<Item*>& updateQueue = player->GetItemUpdateQueue();
            for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
            {
                if (i >= BUYBACK_SLOT_START && i < BUYBACK_SLOT_END)
                    continue;

                Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
                if (!item)
                    continue;

                if (item->GetSlot() != i)
                {
                    handler->PSendSysMessage("Item with slot %d and %s has an incorrect slot value: %d", i, item->GetGUID().ToString().c_str(), item->GetSlot());
                    error = true;
                    continue;
                }

                if (item->GetOwnerGUID() != player->GetGUID())
                {
                    handler->PSendSysMessage("The item with slot %d %s does have non-matching owner guid %s and %s!", item->GetSlot(), item->GetGUID().ToString().c_str(), item->GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
                    error = true;
                    continue;
                }

                if (Bag* container = item->GetContainer())
                {
                    handler->PSendSysMessage("The item with slot %d %s has a container (slot: %d, %s) but shouldn't!", item->GetSlot(), item->GetGUID().ToString().c_str(), container->GetSlot(), container->GetGUID().ToString().c_str());
                    error = true;
                    continue;
                }

                if (item->IsInUpdateQueue())
                {
                    uint16 qp = item->GetQueuePos();
                    if (qp > updateQueue.size())
                    {
                        handler->PSendSysMessage("The item with slot %d and %s has its queuepos (%d) larger than the update queue size! ", item->GetSlot(), item->GetGUID().ToString().c_str(), qp);
                        error = true;
                        continue;
                    }

                    if (updateQueue[qp] == NULL)
                    {
                        handler->PSendSysMessage("The item with slot %d and %s has its queuepos (%d) pointing to NULL in the queue!", item->GetSlot(), item->GetGUID().ToString().c_str(), qp);
                        error = true;
                        continue;
                    }

                    if (updateQueue[qp] != item)
                    {
                        handler->PSendSysMessage("The item with slot %d and %s has a queuepos (%d) that points to another item in the queue (bag: %d, slot: %d, %s)", item->GetSlot(), item->GetGUID().ToString().c_str(), qp, updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot(), updateQueue[qp]->GetGUID().ToString().c_str());
                        error = true;
                        continue;
                    }
                }
                else if (item->GetState() != ITEM_UNCHANGED)
                {
                    handler->PSendSysMessage("The item with slot %d and %s is not in queue but should be (state: %d)!", item->GetSlot(), item->GetGUID().ToString().c_str(), item->GetState());
                    error = true;
                    continue;
                }

                if (Bag* bag = item->ToBag())
                {
                    for (uint8 j = 0; j < bag->GetBagSize(); ++j)
                    {
                        Item* item2 = bag->GetItemByPos(j);
                        if (!item2)
                            continue;

                        if (item2->GetSlot() != j)
                        {
                            handler->PSendSysMessage("The item in bag %d and slot %d (%s) has an incorrect slot value: %d", bag->GetSlot(), j, item2->GetGUID().ToString().c_str(), item2->GetSlot());
                            error = true;
                            continue;
                        }

                        if (item2->GetOwnerGUID() != player->GetGUID())
                        {
                            handler->PSendSysMessage("The item in bag %d at slot %d and %s, the owner (%s) and the player (%s) don't match!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str(), item2->GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
                            error = true;
                            continue;
                        }

                        Bag* container = item2->GetContainer();
                        if (!container)
                        {
                            handler->PSendSysMessage("The item in bag %d at slot %d %s has no container!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str());
                            error = true;
                            continue;
                        }

                        if (container != bag)
                        {
                            handler->PSendSysMessage("The item in bag %d at slot %d %s has a different container(slot %d %s)!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str(), container->GetSlot(), container->GetGUID().ToString().c_str());
                            error = true;
                            continue;
                        }

                        if (item2->IsInUpdateQueue())
                        {
                            uint16 qp = item2->GetQueuePos();
                            if (qp > updateQueue.size())
                            {
                                handler->PSendSysMessage("The item in bag %d at slot %d having %s has a queuepos (%d) larger than the update queue size! ", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str(), qp);
                                error = true;
                                continue;
                            }

                            if (updateQueue[qp] == NULL)
                            {
                                handler->PSendSysMessage("The item in bag %d at slot %d having %s has a queuepos (%d) that points to NULL in the queue!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str(), qp);
                                error = true;
                                continue;
                            }

                            if (updateQueue[qp] != item2)
                            {
                                handler->PSendSysMessage("The item in bag %d at slot %d having %s has a queuepos (%d) that points to another item in the queue (bag: %d, slot: %d, %s)", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str(), qp, updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot(), updateQueue[qp]->GetGUID().ToString().c_str());
                                error = true;
                                continue;
                            }
                        }
                        else if (item2->GetState() != ITEM_UNCHANGED)
                        {
                            handler->PSendSysMessage("The item in bag %d at slot %d having %s is not in queue but should be (state: %d)!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().ToString().c_str(), item2->GetState());
                            error = true;
                            continue;
                        }
                    }
                }
            }

            for (size_t i = 0; i < updateQueue.size(); ++i)
            {
                Item* item = updateQueue[i];
                if (!item)
                    continue;

                if (item->GetOwnerGUID() != player->GetGUID())
                {
                    handler->PSendSysMessage("queue(%zu): For the item %s, the owner (%s) and the player (%s) don't match!", i, item->GetGUID().ToString().c_str(), item->GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
                    error = true;
                    continue;
                }

                if (item->GetQueuePos() != i)
                {
                    handler->PSendSysMessage("queue(%zu): For the item %s, the queuepos doesn't match it's position in the queue!", i, item->GetGUID().ToString().c_str());
                    error = true;
                    continue;
                }

                if (item->GetState() == ITEM_REMOVED)
                    continue;

                Item* test = player->GetItemByPos(item->GetBagSlot(), item->GetSlot());

                if (test == NULL)
                {
                    handler->PSendSysMessage("queue(%zu): The bag(%d) and slot(%d) values for %s are incorrect, the player doesn't have any item at that position!", i, item->GetBagSlot(), item->GetSlot(), item->GetGUID().ToString().c_str());
                    error = true;
                    continue;
                }

                if (test != item)
                {
                    handler->PSendSysMessage("queue(%zu): The bag(%d) and slot(%d) values for the %s are incorrect, %s is there instead!", i, item->GetBagSlot(), item->GetSlot(), item->GetGUID().ToString().c_str(), test->GetGUID().ToString().c_str());
                    error = true;
                    continue;
                }
            }
            if (!error)
                handler->SendSysMessage("All OK!");
        }

        return true;
    }

    static bool HandleDebugBattlegroundCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        sBattlegroundMgr->ToggleTesting();
        return true;
    }

    static bool HandleDebugArenaCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        sBattlegroundMgr->ToggleArenaTesting();
        return true;
    }

    static bool HandleDebugThreatListCommand(ChatHandler* handler, char const* /*args*/)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target || target->IsTotem() || target->IsPet())
            return false;

        ThreatContainer::StorageType const &threatList = target->getThreatManager().getThreatList();
        ThreatContainer::StorageType::const_iterator itr;
        uint32 count = 0;
        handler->PSendSysMessage("Threat list of %s (%s)", target->GetName().c_str(), target->GetGUID().ToString().c_str());
        for (itr = threatList.begin(); itr != threatList.end(); ++itr)
        {
            Unit* unit = (*itr)->getTarget();
            if (!unit)
                continue;
            ++count;
            handler->PSendSysMessage("   %u.   %s   (%s)  - threat %f", count, unit->GetName().c_str(), unit->GetGUID().ToString().c_str(), (*itr)->getThreat());
        }
        handler->SendSysMessage("End of threat list.");
        return true;
    }

    static bool HandleDebugHostileRefListCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();
        HostileReference* ref = target->getHostileRefManager().getFirst();
        uint32 count = 0;
        handler->PSendSysMessage("Hostil reference list of %s (%s)", target->GetName().c_str(), target->GetGUID().ToString().c_str());
        while (ref)
        {
            if (Unit* unit = ref->GetSource()->GetOwner())
            {
                ++count;
                handler->PSendSysMessage("   %u.   %s   (%s, SpawnId: %s)  - threat %f", count, unit->GetName().c_str(), unit->GetGUID().ToString().c_str(), unit->GetTypeId() == TYPEID_UNIT ? std::to_string(unit->ToCreature()->GetSpawnId()).c_str() : "0", ref->getThreat());
            }
            ref = ref->next();
        }
        handler->SendSysMessage("End of hostil reference list.");
        return true;
    }

    static bool HandleDebugSetVehicleIdCommand(ChatHandler* handler, char const* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target || target->IsVehicle())
            return false;

        if (!args)
            return false;

        char* i = strtok((char*)args, " ");
        if (!i)
            return false;

        uint32 id = atoul(i);
        //target->SetVehicleId(id);
        handler->PSendSysMessage("Vehicle id set to %u", id);
        return true;
    }

    static bool HandleDebugEnterVehicleCommand(ChatHandler* handler, char const* args)
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

        uint32 entry = atoul(i);
        int8 seatId = j ? (int8)atoi(j) : -1;

        if (!entry)
            handler->GetSession()->GetPlayer()->EnterVehicle(target, seatId);
        else
        {
            Creature* passenger = NULL;
            Trinity::AllCreaturesOfEntryInRange check(handler->GetSession()->GetPlayer(), entry, 20.0f);
            Trinity::CreatureSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(handler->GetSession()->GetPlayer(), passenger, check);
            Cell::VisitAllObjects(handler->GetSession()->GetPlayer(), searcher, 30.0f);
            if (!passenger || passenger == target)
                return false;
            passenger->EnterVehicle(target, seatId);
        }

        handler->PSendSysMessage("Unit %u entered vehicle %d", entry, (int32)seatId);
        return true;
    }

    static bool HandleDebugSpawnVehicleCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* i = strtok(NULL, " ");

        if (!e)
            return false;

        uint32 entry = atoul(e);

        float x, y, z, o = handler->GetSession()->GetPlayer()->GetOrientation();
        handler->GetSession()->GetPlayer()->GetClosePoint(x, y, z, handler->GetSession()->GetPlayer()->GetObjectSize());

        if (!i)
            return handler->GetSession()->GetPlayer()->SummonCreature(entry, x, y, z, o) != nullptr;

        uint32 id = atoul(i);

        CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(entry);

        if (!ci)
            return false;

        VehicleEntry const* ve = sVehicleStore.LookupEntry(id);

        if (!ve)
            return false;

        Creature* v = new Creature();

        Map* map = handler->GetSession()->GetPlayer()->GetMap();

        if (!v->Create(map->GenerateLowGuid<HighGuid::Vehicle>(), map, entry, x, y, z, o, nullptr, id))
        {
            delete v;
            return false;
        }

        v->CopyPhaseFrom(handler->GetSession()->GetPlayer());

        map->AddToMap(v->ToCreature());

        return true;
    }

    static bool HandleDebugSendLargePacketCommand(ChatHandler* handler, char const* /*args*/)
    {
        const char* stuffingString = "This is a dummy string to push the packet's size beyond 128000 bytes. ";
        std::ostringstream ss;
        while (ss.str().size() < 128000)
            ss << stuffingString;
        handler->SendSysMessage(ss.str().c_str());
        return true;
    }

    static bool HandleDebugSendSetPhaseShiftCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* t = strtok((char*)args, " ");
        char* p = strtok(NULL, " ");
        char* m = strtok(NULL, " ");

        if (!t)
            return false;

        std::set<uint32> terrainswap;
        std::set<uint32> phaseId;
        std::set<uint32> worldMapSwap;

        if (uint32 ut = (uint32)atoi(t))
            terrainswap.insert(ut);

        if (p)
            if (uint32 up = (uint32)atoi(p))
                phaseId.insert(up);

        if (m)
            if (uint32 um = (uint32)atoi(m))
                worldMapSwap.insert(um);

        handler->GetSession()->SendSetPhaseShift(phaseId, terrainswap, worldMapSwap);
        return true;
    }

    static bool HandleDebugGetItemValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* f = strtok(NULL, " ");

        if (!e || !f)
            return false;

        ObjectGuid::LowType guid = strtoull(e, nullptr, 10);
        uint32 index = atoul(f);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(ObjectGuid::Create<HighGuid::Item>(guid));

        if (!i)
            return false;

        if (index >= i->GetValuesCount())
            return false;

        uint32 value = i->GetUInt32Value(index);

        handler->PSendSysMessage("Item " UI64FMTD ": value at %u is %u", guid, index, value);

        return true;
    }

    static bool HandleDebugSetItemValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* f = strtok(NULL, " ");
        char* g = strtok(NULL, " ");

        if (!e || !f || !g)
            return false;

        ObjectGuid::LowType guid = strtoull(e, nullptr, 10);
        uint32 index = atoul(f);
        uint32 value = atoul(g);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(ObjectGuid::Create<HighGuid::Item>(guid));

        if (!i)
            return false;

        if (index >= i->GetValuesCount())
            return false;

        i->SetUInt32Value(index, value);

        return true;
    }

    static bool HandleDebugItemExpireCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        if (!e)
            return false;

        ObjectGuid::LowType guid = strtoull(e, nullptr, 10);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(ObjectGuid::Create<HighGuid::Item>(guid));

        if (!i)
            return false;

        handler->GetSession()->GetPlayer()->DestroyItem(i->GetBagSlot(), i->GetSlot(), true);
        sScriptMgr->OnItemExpire(handler->GetSession()->GetPlayer(), i->GetTemplate());

        return true;
    }

    //show animation
    static bool HandleDebugAnimCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 animId = atoi((char*)args);
        if (Unit* unit = handler->getSelectedUnit())
            unit->HandleEmoteCommand(animId);
        return true;
    }

    static bool HandleDebugLoSCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (Unit* unit = handler->getSelectedUnit())
            handler->PSendSysMessage("Unit %s (%s) is %sin LoS", unit->GetName().c_str(), unit->GetGUID().ToString().c_str(), handler->GetSession()->GetPlayer()->IsWithinLOSInMap(unit) ? "" : "not ");
        return true;
    }

    static bool HandleDebugSetAuraStateCommand(ChatHandler* handler, char const* args)
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
                unit->ModifyAuraState(AuraStateType(i), false);
            return true;
        }

        unit->ModifyAuraState(AuraStateType(abs(state)), state > 0);
        return true;
    }

    static bool HandleDebugSetValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* x = strtok((char*)args, " ");
        char* y = strtok(NULL, " ");
        char* z = strtok(NULL, " ");

        if (!x || !y)
            return false;

        WorldObject* target = handler->getSelectedObject();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ObjectGuid guid = target->GetGUID();

        uint32 field = atoul(x);
        if (field >= target->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, field, guid.ToString().c_str(), target->GetValuesCount());
            return false;
        }

        bool isInt32 = true;
        if (z)
            isInt32 = atoi(z) != 0;

        if (isInt32)
        {
            uint32 value = atoul(y);
            target->SetUInt32Value(field, value);
            handler->PSendSysMessage(LANG_SET_UINT_FIELD, guid.ToString().c_str(), field, value);
        }
        else
        {
            float value = (float)atof(y);
            target->SetFloatValue(field, value);
            handler->PSendSysMessage(LANG_SET_FLOAT_FIELD, guid.ToString().c_str(), field, value);
        }

        return true;
    }

    static bool HandleDebugGetValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* x = strtok((char*)args, " ");
        char* z = strtok(NULL, " ");

        if (!x)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ObjectGuid guid = target->GetGUID();

        uint32 opcode = atoul(x);
        if (opcode >= target->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, opcode, guid.ToString().c_str(), target->GetValuesCount());
            return false;
        }

        bool isInt32 = true;
        if (z)
            isInt32 = atoi(z) != 0;

        if (isInt32)
        {
            uint32 value = target->GetUInt32Value(opcode);
            handler->PSendSysMessage(LANG_GET_UINT_FIELD, guid.ToString().c_str(), opcode, value);
        }
        else
        {
            float value = target->GetFloatValue(opcode);
            handler->PSendSysMessage(LANG_GET_FLOAT_FIELD, guid.ToString().c_str(), opcode, value);
        }

        return true;
    }

    static bool HandleDebugMod32ValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* x = strtok((char*)args, " ");
        char* y = strtok(NULL, " ");

        if (!x || !y)
            return false;

        uint32 opcode = atoul(x);
        int value = atoi(y);

        if (opcode >= handler->GetSession()->GetPlayer()->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, opcode, handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(), handler->GetSession()->GetPlayer()->GetValuesCount());
            return false;
        }

        uint32 currentValue = handler->GetSession()->GetPlayer()->GetUInt32Value(opcode);

        currentValue += value;
        handler->GetSession()->GetPlayer()->SetUInt32Value(opcode, currentValue);

        handler->PSendSysMessage(LANG_CHANGE_32BIT_FIELD, opcode, currentValue);

        return true;
    }

    static bool HandleDebugUpdateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 updateIndex;
        uint32 value;

        char* index = strtok((char*)args, " ");

        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!index)
            return true;

        updateIndex = atoi(index);
        //check updateIndex
        if (unit->GetTypeId() == TYPEID_PLAYER)
        {
            if (updateIndex >= PLAYER_END)
                return true;
        }
        else if (updateIndex >= UNIT_END)
            return true;

        char* val = strtok(NULL, " ");
        if (!val)
        {
            value = unit->GetUInt32Value(updateIndex);

            handler->PSendSysMessage(LANG_UPDATE, unit->GetGUID().ToString().c_str(), updateIndex, value);
            return true;
        }

        value = atoi(val);

        handler->PSendSysMessage(LANG_UPDATE_CHANGE, unit->GetGUID().ToString().c_str(), updateIndex, value);

        unit->SetUInt32Value(updateIndex, value);

        return true;
    }

    static bool HandleDebugSet32BitCommand(ChatHandler* handler, char const* args)
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

        char* x = strtok((char*)args, " ");
        char* y = strtok(NULL, " ");

        if (!x || !y)
            return false;

        uint32 opcode = atoul(x);
        uint32 val = atoul(y);
        if (val > 32)                                         //uint32 = 32 bits
            return false;

        uint32 value = val ? 1 << (val - 1) : 0;
        target->SetUInt32Value(opcode,  value);

        handler->PSendSysMessage(LANG_SET_32BIT_FIELD, opcode, value);
        return true;
    }

    static bool HandleDebugMoveflagsCommand(ChatHandler* handler, char const* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        if (!*args)
        {
            //! Display case
            handler->PSendSysMessage(LANG_MOVEFLAGS_GET, target->GetUnitMovementFlags(), target->GetExtraUnitMovementFlags());
        }
        else
        {
            char* mask1 = strtok((char*)args, " ");
            if (!mask1)
                return false;

            char* mask2 = strtok(NULL, " \n");

            uint32 moveFlags = (uint32)atoi(mask1);
            target->SetUnitMovementFlags(moveFlags);

            /// @fixme: port master's HandleDebugMoveflagsCommand; flags need different handling

            if (mask2)
            {
                uint32 moveFlagsExtra = uint32(atoi(mask2));
                target->SetExtraUnitMovementFlags(moveFlagsExtra);
            }

            if (target->GetTypeId() != TYPEID_PLAYER)
                target->DestroyForNearbyPlayers();  // Force new SMSG_UPDATE_OBJECT:CreateObject
            else
            {
                WorldPackets::Movement::MoveUpdate moveUpdate;
                moveUpdate.Status = &target->m_movementInfo;
                target->SendMessageToSet(moveUpdate.Write(), true);
            }

            handler->PSendSysMessage(LANG_MOVEFLAGS_SET, target->GetUnitMovementFlags(), target->GetExtraUnitMovementFlags());
        }

        return true;
    }

    static bool HandleWPGPSCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();

        TC_LOG_INFO("sql.dev", "(@PATH, XX, %.3f, %.3f, %.5f, 0, 0, 0, 100, 0),", player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

        handler->PSendSysMessage("Waypoint SQL written to SQL Developer log");
        return true;
    }

    static bool HandleDebugTransportCommand(ChatHandler* handler, char const* args)
    {
        Transport* transport = handler->GetSession()->GetPlayer()->GetTransport();
        if (!transport)
            return false;

        bool start = false;
        if (!stricmp(args, "stop"))
            transport->EnableMovement(false);
        else if (!stricmp(args, "start"))
        {
            transport->EnableMovement(true);
            start = true;
        }
        else
        {
            Position pos = transport->GetPosition();
            handler->PSendSysMessage("Transport %s is %s", transport->GetName().c_str(), transport->GetGoState() == GO_STATE_READY ? "stopped" : "moving");
            handler->PSendSysMessage("Transport position: %s", pos.ToString().c_str());
            return true;
        }

        handler->PSendSysMessage("Transport %s %s", transport->GetName().c_str(), start ? "started" : "stopped");
        return true;
    }

    static bool HandleDebugLoadCellsCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        Map* map = nullptr;

        if (*args)
        {
            int32 mapId = atoi(args);
            map = sMapMgr->FindBaseNonInstanceMap(mapId);
        }
        if (!map)
            map = player->GetMap();

        map->LoadAllCells();
        handler->PSendSysMessage("Cells loaded (mapId: %u)", map->GetId());
        return true;
    }

    static bool HandleDebugBoundaryCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;
        Creature* target = handler->getSelectedCreature();
        if (!target || !target->IsAIEnabled || !target->AI())
        {
            return false;
        }

        char* fill_str = args ? strtok((char*)args, " ") : nullptr;
        char* duration_str = args ? strtok(nullptr, " ") : nullptr;

        int duration = duration_str ? atoi(duration_str) : -1;
        if (duration <= 0 || duration >= 30 * MINUTE) // arbitary upper limit
            duration = 3 * MINUTE;

        bool doFill = fill_str ? (stricmp(fill_str, "FILL") == 0) : false;

        int32 errMsg = target->AI()->VisualizeBoundary(duration, player, doFill);
        if (errMsg > 0)
            handler->PSendSysMessage(errMsg);

        return true;
    }

    static bool HandleDebugPhaseCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->GetDBPhase() > 0)
            handler->PSendSysMessage("Target creature's PhaseId in DB: %d", target->GetDBPhase());
        else if (target->GetDBPhase() < 0)
            handler->PSendSysMessage("Target creature's PhaseGroup in DB: %d", abs(target->GetDBPhase()));

        std::stringstream phases;

        for (uint32 phase : target->GetPhases())
        {
            phases << phase << " ";
        }

        if (!phases.str().empty())
            handler->PSendSysMessage("Target's current phases: %s", phases.str().c_str());
        else
            handler->SendSysMessage("Target is not phased");
        return true;
    }

    static bool HandleDebugRaidResetCommand(ChatHandler* /*handler*/, char const* args)
    {
        char* map_str = args ? strtok((char*)args, " ") : nullptr;
        char* difficulty_str = args ? strtok(nullptr, " ") : nullptr;

        int32 map = map_str ? atoi(map_str) : -1;
        if (map <= 0)
            return false;
        MapEntry const* mEntry = sMapStore.LookupEntry(map);
        if (!mEntry || !mEntry->IsRaid())
            return false;
        int32 difficulty = difficulty_str ? atoi(difficulty_str) : -1;
        if (difficulty >= MAX_DIFFICULTY || difficulty < -1)
            return false;

        if (difficulty == -1)
            for (uint8 diff = 0; diff < MAX_DIFFICULTY; ++diff)
            {
                if (sDB2Manager.GetMapDifficultyData(map, Difficulty(diff)))
                    sInstanceSaveMgr->ForceGlobalReset(map, Difficulty(diff));
            }
        else
            sInstanceSaveMgr->ForceGlobalReset(map, Difficulty(difficulty));
        return true;
    }

    static bool HandleDebugNearGraveyard(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        WorldSafeLocsEntry const* nearestLoc = nullptr;

        if (stricmp(args, "linked"))
        {
            if (Battleground* bg = player->GetBattleground())
                nearestLoc = bg->GetClosestGraveYard(player);
            else
            {
                if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId()))
                    nearestLoc = bf->GetClosestGraveYard(player);
                else
                    nearestLoc = sObjectMgr->GetClosestGraveYard(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), player->GetTeam());
            }
        }
        else
        {
            float x = player->GetPositionX();
            float y = player->GetPositionY();
            float z = player->GetPositionZ();
            float distNearest = std::numeric_limits<float>::max();

            for (uint32 i = 0; i < sWorldSafeLocsStore.GetNumRows(); ++i)
            {
                WorldSafeLocsEntry const* loc = sWorldSafeLocsStore.LookupEntry(i);
                if (loc && loc->MapID == player->GetMapId())
                {
                    float dist = (loc->Loc.X - x) * (loc->Loc.X - x) + (loc->Loc.Y - y) * (loc->Loc.Y - y) + (loc->Loc.Z - z) * (loc->Loc.Z - z);
                    if (dist < distNearest)
                    {
                        distNearest = dist;
                        nearestLoc = loc;
                    }
                }
            }
        }

        if (nearestLoc)
            handler->PSendSysMessage(LANG_COMMAND_NEARGRAVEYARD, nearestLoc->ID, nearestLoc->Loc.X, nearestLoc->Loc.Y, nearestLoc->Loc.Z);
        else
            handler->PSendSysMessage(LANG_COMMAND_NEARGRAVEYARD_NOTFOUND);

        return true;
    }

    static bool HandleDebugConversationCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* conversationEntryStr = strtok((char*)args, " ");

        if (!conversationEntryStr)
            return false;

        uint32 conversationEntry = atoi(conversationEntryStr);
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return Conversation::CreateConversation(conversationEntry, target, *target, { target->GetGUID() }) != nullptr;
    }
};

void AddSC_debug_commandscript()
{
    new debug_commandscript();
}
