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
#include "DBCStores.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "M2Stores.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "PoolMgr.h"
#include "QuestPools.h"
#include "RBAC.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "WorldSession.h"
#include <fstream>
#include <limits>
#include <map>
#include <set>

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
            { "music",         rbac::RBAC_PERM_COMMAND_DEBUG_PLAY_MUSIC,     false, &HandleDebugPlayMusicCommand,       "" },
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
        };
        static std::vector<ChatCommand> debugCommandTable =
        {
            { "setbit",        rbac::RBAC_PERM_COMMAND_DEBUG_SETBIT,        false, &HandleDebugSet32BitCommand,         "" },
            { "threat",        rbac::RBAC_PERM_COMMAND_DEBUG_THREAT,        false, &HandleDebugThreatListCommand,       "" },
            { "threatinfo",    rbac::RBAC_PERM_COMMAND_DEBUG_THREATINFO,    false, &HandleDebugThreatInfoCommand,       "" },
            { "combat",        rbac::RBAC_PERM_COMMAND_DEBUG_COMBAT,        false, &HandleDebugCombatListCommand,       "" },
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
            { "worldstate",    rbac::RBAC_PERM_COMMAND_DEBUG_WORLDSTATE,    false, &HandleDebugUpdateWorldStateCommand, "" },
            { "update",        rbac::RBAC_PERM_COMMAND_DEBUG_UPDATE,        false, &HandleDebugUpdateCommand,           "" },
            { "itemexpire",    rbac::RBAC_PERM_COMMAND_DEBUG_ITEMEXPIRE,    false, &HandleDebugItemExpireCommand,       "" },
            { "areatriggers",  rbac::RBAC_PERM_COMMAND_DEBUG_AREATRIGGERS,  false, &HandleDebugAreaTriggersCommand,     "" },
            { "los",           rbac::RBAC_PERM_COMMAND_DEBUG_LOS,           false, &HandleDebugLoSCommand,              "" },
            { "moveflags",     rbac::RBAC_PERM_COMMAND_DEBUG_MOVEFLAGS,     false, &HandleDebugMoveflagsCommand,        "" },
            { "transport",     rbac::RBAC_PERM_COMMAND_DEBUG_TRANSPORT,     false, &HandleDebugTransportCommand,        "" },
            { "phase",         rbac::RBAC_PERM_COMMAND_DEBUG_PHASE,         false, &HandleDebugPhaseCommand,            "" },
            { "loadcells",     rbac::RBAC_PERM_COMMAND_DEBUG_LOADCELLS,     false, &HandleDebugLoadCellsCommand,        "" },
            { "boundary",      rbac::RBAC_PERM_COMMAND_DEBUG_BOUNDARY,      false, &HandleDebugBoundaryCommand,         "" },
            { "raidreset",     rbac::RBAC_PERM_COMMAND_INSTANCE_UNBIND,     false, &HandleDebugRaidResetCommand,        "" },
            { "neargraveyard", rbac::RBAC_PERM_COMMAND_NEARGRAVEYARD,       false, &HandleDebugNearGraveyard,           "" },
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
        // USAGE: .debug play cinematic #cinematicId
        // #cinematicId - ID decimal number from CinemaicSequences.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 cinematicId = atoul(args);

        CinematicSequencesEntry const* cineSeq = sCinematicSequencesStore.LookupEntry(cinematicId);
        if (!cineSeq)
        {
            handler->PSendSysMessage(LANG_CINEMATIC_NOT_EXIST, cinematicId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Dump camera locations
        if (std::vector<FlyByCamera> const* flyByCameras = GetFlyByCameras(cineSeq->Camera[0]))
        {
            handler->PSendSysMessage("Waypoints for sequence %u, camera %u", cinematicId, cineSeq->Camera[0]);
            uint32 count = 1;
            for (FlyByCamera const& cam : *flyByCameras)
            {
                handler->PSendSysMessage("%02u - %7ums [%s (%f degrees)]", count, cam.timeStamp, cam.locations.ToString().c_str(), cam.locations.GetOrientation() * (180 / M_PI));
                ++count;
            }
            handler->PSendSysMessage("%u waypoints dumped", flyByCameras->size());
        }

        handler->GetSession()->GetPlayer()->SendCinematicStart(cinematicId);
        return true;
    }

    static bool HandleDebugPlayMovieCommand(ChatHandler* handler, char const* args)
    {
        // USAGE: .debug play movie #movieId
        // #movieId - ID decimal number from Movie.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 movieId = atoul(args);
        if (!sMovieStore.LookupEntry(movieId))
        {
            handler->PSendSysMessage(LANG_MOVIE_NOT_EXIST, movieId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetSession()->GetPlayer()->SendMovieStart(movieId);
        return true;
    }

    static bool HandleDebugPlaySoundCommand(ChatHandler* handler, char const* args)
    {
        // USAGE: .debug playsound #soundId
        // #soundId - ID decimal number from SoundEntries.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 soundId = atoul(args);
        if (!sSoundEntriesStore.LookupEntry(soundId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, soundId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();

        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetTarget())
            unit->PlayDistanceSound(soundId, player);
        else
            unit->PlayDirectSound(soundId, player);

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, soundId);
        return true;
    }

    static bool HandleDebugPlayMusicCommand(ChatHandler* handler, char const* args)
    {
        // USAGE: .debug play music #musicId
        // #musicId - ID decimal number from SoundEntries.dbc (1st column)
        if (!*args)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 musicId = atoul(args);
        if (!sSoundEntriesStore.LookupEntry(musicId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, musicId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();

        player->PlayDirectMusic(musicId, player);

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, musicId);
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

        char* fail1 = strtok(nullptr, " ");
        uint8 failArg1 = fail1 ? (uint8)atoi(fail1) : 0;

        char* fail2 = strtok(nullptr, " ");
        uint8 failArg2 = fail2 ? (uint8)atoi(fail2) : 0;

        WorldPacket data(SMSG_CAST_FAILED, 5);
        data << uint8(0);
        data << uint32(133);
        data << uint8(failNum);
        if (fail1 || fail2)
            data << uint32(failArg1);
        if (fail2)
            data << uint32(failArg2);

        handler->GetSession()->SendPacket(&data);
        return true;
    }

    static bool HandleDebugSendEquipErrorCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        InventoryResult msg = InventoryResult(atoi(args));
        handler->GetSession()->GetPlayer()->SendEquipError(msg, nullptr, nullptr);
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
        Player* player = nullptr;
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

        WorldPacket data(opcode, 0);

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
            else if (type == "appitsguid")
            {
                data << unit->GetPackGUID();
            }
            else if (type == "appmyguid")
            {
                data << player->GetPackGUID();
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
                data << obj->GetPackGUID();
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
        char* s = strtok(nullptr, " ");

        if (!w || !s)
            return false;

        uint32 world = (uint32)atoi(w);
        uint32 state = (uint32)atoi(s);
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
        WorldPacket data;
        ChatHandler::BuildChatPacket(data, ChatMsg(type), LANG_UNIVERSAL, handler->GetSession()->GetPlayer(), handler->GetSession()->GetPlayer(), msg, 0, "chan");
        handler->GetSession()->SendPacket(&data);
        return true;
    }

    static bool HandleDebugSendQuestPartyMsgCommand(ChatHandler* handler, char const* args)
    {
        uint32 msg = atoul(args);
        handler->GetSession()->GetPlayer()->SendPushToPartyResponse(handler->GetSession()->GetPlayer(), msg);
        return true;
    }

    static bool HandleDebugGetLootRecipientCommand(ChatHandler* handler, char const* /*args*/)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
            return false;

        handler->PSendSysMessage("Loot recipient for creature %s (GUID %u, SpawnID %u) is %s",
            target->GetName().c_str(), target->GetGUID().GetCounter(), target->GetSpawnId(),
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

                handler->PSendSysMessage("bag: %d slot: %d guid: %d - state: %s", bagSlot, item->GetSlot(), item->GetGUID().GetCounter(), st.c_str());
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
                    handler->PSendSysMessage("Item with slot %d and guid %d has an incorrect slot value: %d", i, item->GetGUID().GetCounter(), item->GetSlot());
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
                        handler->PSendSysMessage("The item with slot %d and guid %d has its queuepos (%d) larger than the update queue size! ", item->GetSlot(), item->GetGUID().GetCounter(), qp);
                        error = true;
                        continue;
                    }

                    if (updateQueue[qp] == nullptr)
                    {
                        handler->PSendSysMessage("The item with slot %d and guid %d has its queuepos (%d) pointing to nullptr in the queue!", item->GetSlot(), item->GetGUID().GetCounter(), qp);
                        error = true;
                        continue;
                    }

                    if (updateQueue[qp] != item)
                    {
                        handler->PSendSysMessage("The item with slot %d and guid %d has a queuepos (%d) that points to another item in the queue (bag: %d, slot: %d, guid: %d)", item->GetSlot(), item->GetGUID().GetCounter(), qp, updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot(), updateQueue[qp]->GetGUID().GetCounter());
                        error = true;
                        continue;
                    }
                }
                else if (item->GetState() != ITEM_UNCHANGED)
                {
                    handler->PSendSysMessage("The item with slot %d and guid %d is not in queue but should be (state: %d)!", item->GetSlot(), item->GetGUID().GetCounter(), item->GetState());
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
                            handler->PSendSysMessage("The item in bag %d and slot %d (guid: %d) has an incorrect slot value: %d", bag->GetSlot(), j, item2->GetGUID().GetCounter(), item2->GetSlot());
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
                                handler->PSendSysMessage("The item in bag %d at slot %d having guid %d has a queuepos (%d) larger than the update queue size! ", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().GetCounter(), qp);
                                error = true;
                                continue;
                            }

                            if (updateQueue[qp] == nullptr)
                            {
                                handler->PSendSysMessage("The item in bag %d at slot %d having guid %d has a queuepos (%d) that points to nullptr in the queue!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().GetCounter(), qp);
                                error = true;
                                continue;
                            }

                            if (updateQueue[qp] != item2)
                            {
                                handler->PSendSysMessage("The item in bag %d at slot %d having guid %d has a queuepos (%d) that points to another item in the queue (bag: %d, slot: %d, guid: %d)", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().GetCounter(), qp, updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot(), updateQueue[qp]->GetGUID().GetCounter());
                                error = true;
                                continue;
                            }
                        }
                        else if (item2->GetState() != ITEM_UNCHANGED)
                        {
                            handler->PSendSysMessage("The item in bag %d at slot %d having guid %d is not in queue but should be (state: %d)!", bag->GetSlot(), item2->GetSlot(), item2->GetGUID().GetCounter(), item2->GetState());
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

                if (test == nullptr)
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
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        ThreatManager& mgr = target->GetThreatManager();
        if (!target->IsAlive())
        {
            handler->PSendSysMessage("%s (GUID %u) is not alive.%s", target->GetName().c_str(), target->GetGUID().GetCounter(), target->IsEngaged() ? " (It is, however, engaged. Huh?)" : "");
            return true;
        }

        uint32 count = 0;
        auto const& threatenedByMe = target->GetThreatManager().GetThreatenedByMeList();
        if (threatenedByMe.empty())
            handler->PSendSysMessage("%s (GUID %u) does not threaten any units.", target->GetName().c_str(), target->GetGUID().GetCounter());
        else
        {
            handler->PSendSysMessage("List of units threatened by %s (GUID %u)", target->GetName().c_str(), target->GetGUID().GetCounter());
            for (auto const& pair : threatenedByMe)
            {
                Unit* unit = pair.second->GetOwner();
                handler->PSendSysMessage("   %u.   %s   (GUID %u, SpawnID %u)  - threat %f", ++count, unit->GetName().c_str(), unit->GetGUID().GetCounter(), unit->GetTypeId() == TYPEID_UNIT ? unit->ToCreature()->GetSpawnId() : 0, pair.second->GetThreat());
            }
            handler->SendSysMessage("End of threatened-by-me list.");
        }

        if (mgr.CanHaveThreatList())
        {
            if (!mgr.IsThreatListEmpty(true))
            {
                if (target->IsEngaged())
                    handler->PSendSysMessage("Threat list of %s (GUID %u, SpawnID %u):", target->GetName().c_str(), target->GetGUID().GetCounter(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);
                else
                    handler->PSendSysMessage("%s (GUID %u, SpawnID %u) is not engaged, but still has a threat list? Well, here it is:", target->GetName().c_str(), target->GetGUID().GetCounter(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);

                count = 0;
                Unit* fixateVictim = mgr.GetFixateTarget();
                for (ThreatReference const* ref : mgr.GetSortedThreatList())
                {
                    Unit* unit = ref->GetVictim();
                    char const* onlineStr;
                    switch (ref->GetOnlineState())
                    {
                        case ThreatReference::ONLINE_STATE_SUPPRESSED:
                            onlineStr = " [SUPPRESSED]";
                            break;
                        case ThreatReference::ONLINE_STATE_OFFLINE:
                            onlineStr = " [OFFLINE]";
                            break;
                        default:
                            onlineStr = "";
                    }
                    char const* tauntStr;
                    if (unit == fixateVictim)
                        tauntStr = " [FIXATE]";
                    else
                        switch (ref->GetTauntState())
                        {
                            case ThreatReference::TAUNT_STATE_TAUNT:
                                tauntStr = " [TAUNT]";
                                break;
                            case ThreatReference::TAUNT_STATE_DETAUNT:
                                tauntStr = " [DETAUNT]";
                                break;
                            default:
                                tauntStr = "";
                        }
                    handler->PSendSysMessage("   %u.   %s   (GUID %u)  - threat %f%s%s", ++count, unit->GetName().c_str(), unit->GetGUID().GetCounter(), ref->GetThreat(), tauntStr, onlineStr);
                }
                handler->SendSysMessage("End of threat list.");
            }
            else if (!target->IsEngaged())
                handler->PSendSysMessage("%s (GUID %u, SpawnID %u) is not currently engaged.", target->GetName().c_str(), target->GetGUID().GetCounter(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);
            else
                handler->PSendSysMessage("%s (GUID %u, SpawnID %u) seems to be engaged, but does not have a threat list??", target->GetName().c_str(), target->GetGUID().GetCounter(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);
        }
        else if (target->IsEngaged())
            handler->PSendSysMessage("%s (GUID %u) is currently engaged. (This unit cannot have a threat list.)", target->GetName().c_str(), target->GetGUID().GetCounter());
        else
            handler->PSendSysMessage("%s (GUID %u) is not currently engaged. (This unit cannot have a threat list.)", target->GetName().c_str(), target->GetGUID().GetCounter());
        return true;
    }

    static bool HandleDebugThreatInfoCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("Threat info for %s (%s):", target->GetName(), target->GetGUID().ToString().c_str());

        ThreatManager const& mgr = target->GetThreatManager();

        // _singleSchoolModifiers
        {
            auto& mods = mgr._singleSchoolModifiers;
            handler->SendSysMessage(" - Single-school threat modifiers:");
            handler->PSendSysMessage(" |-- Physical: %.2f%%", mods[SPELL_SCHOOL_NORMAL]*100.0f);
            handler->PSendSysMessage(" |-- Holy    : %.2f%%", mods[SPELL_SCHOOL_HOLY]*100.0f);
            handler->PSendSysMessage(" |-- Fire    : %.2f%%", mods[SPELL_SCHOOL_FIRE]*100.0f);
            handler->PSendSysMessage(" |-- Nature  : %.2f%%", mods[SPELL_SCHOOL_NATURE]*100.0f);
            handler->PSendSysMessage(" |-- Frost   : %.2f%%", mods[SPELL_SCHOOL_FROST]*100.0f);
            handler->PSendSysMessage(" |-- Shadow  : %.2f%%", mods[SPELL_SCHOOL_SHADOW]*100.0f);
            handler->PSendSysMessage(" |-- Arcane  : %.2f%%", mods[SPELL_SCHOOL_ARCANE]*100.0f);
        }

        // _multiSchoolModifiers
        {
            auto& mods = mgr._multiSchoolModifiers;
            handler->PSendSysMessage("- Multi-school threat modifiers (%zu entries):", mods.size());
            for (auto const& pair : mods)
                handler->PSendSysMessage(" |-- Mask 0x%x: %.2f%%", uint32(pair.first), pair.second);
        }

        // _redirectInfo
        {
            auto const& redirectInfo = mgr._redirectInfo;
            if (redirectInfo.empty())
                handler->SendSysMessage(" - No redirects being applied");
            else
            {
                handler->PSendSysMessage(" - %02zu redirects being applied:", redirectInfo.size());
                for (auto const& pair : redirectInfo)
                {
                    Unit* unit = ObjectAccessor::GetUnit(*target, pair.first);
                    handler->PSendSysMessage(" |-- %02u%% to %s", pair.second, unit ? unit->GetName().c_str() : pair.first.ToString().c_str());
                }
            }
        }

        // _redirectRegistry
        {
            auto const& redirectRegistry = mgr._redirectRegistry;
            if (redirectRegistry.empty())
                handler->SendSysMessage(" - No redirects are registered");
            else
            {
                handler->PSendSysMessage(" - %02zu spells may have redirects registered", redirectRegistry.size());
                for (auto const& outerPair : redirectRegistry) // (spellId, (guid, pct))
                {
                    SpellInfo const* const spell = sSpellMgr->GetSpellInfo(outerPair.first);
                    handler->PSendSysMessage(" |-- #%06u %s (%zu entries):", outerPair.first, spell ? spell->SpellName : "<unknown>", outerPair.second.size());
                    for (auto const& innerPair : outerPair.second) // (guid, pct)
                    {
                        Unit* unit = ObjectAccessor::GetUnit(*target, innerPair.first);
                        handler->PSendSysMessage("   |-- %02u%% to %s", innerPair.second, unit ? unit->GetName().c_str() : innerPair.first.ToString().c_str());
                    }
                }
            }
        }

        return true;
    }

    static bool HandleDebugCombatListCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        handler->PSendSysMessage("Combat refs: (Combat state: %d | Manager state: %d)", target->IsInCombat(), target->GetCombatManager().HasCombat());
        for (auto const& ref : target->GetCombatManager().GetPvPCombatRefs())
        {
            Unit* unit = ref.second->GetOther(target);
            handler->PSendSysMessage("[PvP] %s (SpawnID %u)", unit->GetName().c_str(), unit->GetTypeId() == TYPEID_UNIT ? unit->ToCreature()->GetSpawnId() : 0);
        }
        for (auto const& ref : target->GetCombatManager().GetPvECombatRefs())
        {
            Unit* unit = ref.second->GetOther(target);
            handler->PSendSysMessage("[PvE] %s (SpawnID %u)", unit->GetName().c_str(), unit->GetTypeId() == TYPEID_UNIT ? unit->ToCreature()->GetSpawnId() : 0);
        }
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

        uint32 id = (uint32)atoi(i);
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

        char* j = strtok(nullptr, " ");

        uint32 entry = (uint32)atoi(i);
        int8 seatId = j ? (int8)atoi(j) : -1;

        if (!entry)
            handler->GetSession()->GetPlayer()->EnterVehicle(target, seatId);
        else
        {
            Creature* passenger = nullptr;
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
        char* i = strtok(nullptr, " ");

        if (!e)
            return false;

        uint32 entry = (uint32)atoi(e);

        float x, y, z, o = handler->GetSession()->GetPlayer()->GetOrientation();
        handler->GetSession()->GetPlayer()->GetClosePoint(x, y, z, handler->GetSession()->GetPlayer()->GetCombatReach());

        if (!i)
            return handler->GetSession()->GetPlayer()->SummonCreature(entry, x, y, z, o) != nullptr;

        uint32 id = (uint32)atoi(i);

        CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(entry);

        if (!ci)
            return false;

        VehicleEntry const* ve = sVehicleStore.LookupEntry(id);

        if (!ve)
            return false;

        Creature* v = new Creature();

        Map* map = handler->GetSession()->GetPlayer()->GetMap();
        if (!v->Create(map->GenerateLowGuid<HighGuid::Vehicle>(), map, entry, { x, y, z, o }, nullptr, id))
        {
            delete v;
            return false;
        }

        PhasingHandler::InheritPhaseShift(v, handler->GetSession()->GetPlayer());

        map->AddToMap(v->ToCreature());

        return true;
    }

    static bool HandleDebugSendLargePacketCommand(ChatHandler* handler, char const* /*args*/)
    {
        char const* stuffingString = "This is a dummy string to push the packet's size beyond 128000 bytes. ";
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
        char* p = strtok(nullptr, " ");
        char* m = strtok(nullptr, " ");

        if (!t)
            return false;

        PhaseShift phaseShift;

        if (uint32 ut = (uint32)atoi(t))
            phaseShift.AddVisibleMapId(ut, nullptr);

        if (p)
            if (uint32 up = (uint32)atoi(p))
                phaseShift.AddPhase(up, PhaseFlags::None, nullptr);

        if (m)
            if (uint32 um = (uint32)atoi(m))
                phaseShift.AddUiMapPhaseId(um);

        PhasingHandler::SendToPlayer(handler->GetSession()->GetPlayer(), phaseShift);
        return true;
    }

    static bool HandleDebugGetItemValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* f = strtok(nullptr, " ");

        if (!e || !f)
            return false;

        ObjectGuid::LowType guid = (uint32)atoi(e);
        uint32 index = (uint32)atoi(f);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(ObjectGuid(HighGuid::Item, 0, guid));

        if (!i)
            return false;

        if (index >= i->GetValuesCount())
            return false;

        uint32 value = i->GetUInt32Value(index);

        handler->PSendSysMessage("Item %u: value at %u is %u", guid, index, value);

        return true;
    }

    static bool HandleDebugSetItemValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* e = strtok((char*)args, " ");
        char* f = strtok(nullptr, " ");
        char* g = strtok(nullptr, " ");

        if (!e || !f || !g)
            return false;

        ObjectGuid::LowType guid = (uint32)atoi(e);
        uint32 index = (uint32)atoi(f);
        uint32 value = (uint32)atoi(g);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(ObjectGuid(HighGuid::Item, 0, guid));

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

        ObjectGuid::LowType guid = (uint32)atoi(e);

        Item* i = handler->GetSession()->GetPlayer()->GetItemByGuid(ObjectGuid(HighGuid::Item, guid));

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
        {
            Player* player = handler->GetSession()->GetPlayer();
            handler->PSendSysMessage("Checking LoS %s -> %s:", player->GetName().c_str(), unit->GetName().c_str());
            handler->PSendSysMessage("    VMAP LoS: %s", player->IsWithinLOSInMap(unit, LINEOFSIGHT_CHECK_VMAP) ? "clear" : "obstructed");
            handler->PSendSysMessage("    GObj LoS: %s", player->IsWithinLOSInMap(unit, LINEOFSIGHT_CHECK_GOBJECT) ? "clear" : "obstructed");
            handler->PSendSysMessage("%s is %sin line of sight of %s.", unit->GetName().c_str(), (player->IsWithinLOSInMap(unit) ? "" : "not "), player->GetName().c_str());
            return true;
        }
        return false;
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
        char* y = strtok(nullptr, " ");
        char* z = strtok(nullptr, " ");

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

        uint32 field = (uint32)atoi(x);
        if (field >= target->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, field, guid.GetCounter(), target->GetValuesCount());
            return false;
        }

        bool isInt32 = true;
        if (z)
            isInt32 = atoi(z) != 0;

        if (isInt32)
        {
            uint32 value = (uint32)atoi(y);
            target->SetUInt32Value(field, value);
            handler->PSendSysMessage(LANG_SET_UINT_FIELD, guid.GetCounter(), field, value);
        }
        else
        {
            float value = (float)atof(y);
            target->SetFloatValue(field, value);
            handler->PSendSysMessage(LANG_SET_FLOAT_FIELD, guid.GetCounter(), field, value);
        }

        return true;
    }

    static bool HandleDebugGetValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* x = strtok((char*)args, " ");
        char* z = strtok(nullptr, " ");

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

        uint32 opcode = (uint32)atoi(x);
        if (opcode >= target->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, opcode, guid.GetCounter(), target->GetValuesCount());
            return false;
        }

        bool isInt32 = true;
        if (z)
            isInt32 = atoi(z) != 0;

        if (isInt32)
        {
            uint32 value = target->GetUInt32Value(opcode);
            handler->PSendSysMessage(LANG_GET_UINT_FIELD, guid.GetCounter(), opcode, value);
        }
        else
        {
            float value = target->GetFloatValue(opcode);
            handler->PSendSysMessage(LANG_GET_FLOAT_FIELD, guid.GetCounter(), opcode, value);
        }

        return true;
    }

    static bool HandleDebugMod32ValueCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* x = strtok((char*)args, " ");
        char* y = strtok(nullptr, " ");

        if (!x || !y)
            return false;

        uint32 opcode = (uint32)atoi(x);
        int value = atoi(y);

        if (opcode >= handler->GetSession()->GetPlayer()->GetValuesCount())
        {
            handler->PSendSysMessage(LANG_TOO_BIG_INDEX, opcode, handler->GetSession()->GetPlayer()->GetGUID().GetCounter(), handler->GetSession()->GetPlayer()->GetValuesCount());
            return false;
        }

        int currentValue = (int)handler->GetSession()->GetPlayer()->GetUInt32Value(opcode);

        currentValue += value;
        handler->GetSession()->GetPlayer()->SetUInt32Value(opcode, (uint32)currentValue);

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

        char* val = strtok(nullptr, " ");
        if (!val)
        {
            value = unit->GetUInt32Value(updateIndex);

            handler->PSendSysMessage(LANG_UPDATE, unit->GetGUID().GetCounter(), updateIndex, value);
            return true;
        }

        value = atoi(val);

        handler->PSendSysMessage(LANG_UPDATE_CHANGE, unit->GetGUID().GetCounter(), updateIndex, value);

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
        char* y = strtok(nullptr, " ");

        if (!x || !y)
            return false;

        uint32 opcode = (uint32)atoi(x);
        uint32 val = (uint32)atoi(y);
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

            char* mask2 = strtok(nullptr, " \n");

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
                WorldPacket data(SMSG_MOVE_UPDATE);
                target->WriteMovementInfo(data);
                target->SendMessageToSet(&data, true);
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
        Transport* transport = dynamic_cast<Transport*>(handler->GetSession()->GetPlayer()->GetTransport());
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

    static bool HandleDebugPhaseCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::stringstream phases;

        PhasingHandler::PrintToChat(handler, target->GetPhaseShift());

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
            sMapMgr->DoForAllMapsWithMapId(mapId, [&](Map* map)
            {
                HandleDebugLoadCellsCommandHelper(handler, map);
            });
            return true;
        }

        if (!map)
        {
            // Fallback to player's map if no map has been specified
            return HandleDebugLoadCellsCommandHelper(handler, player->GetMap());
        }

        return false;
    }

    static bool HandleDebugLoadCellsCommandHelper(ChatHandler* handler, Map* map)
    {
        if (!map)
            return false;

        handler->PSendSysMessage("Loading all cells (mapId: %u). Current next GameObject %u, Creature %u", map->GetId(), map->GetMaxLowGuid<HighGuid::GameObject>(), map->GetMaxLowGuid<HighGuid::Unit>());
        map->LoadAllCells();
        handler->PSendSysMessage("Cells loaded (mapId: %u) After load - Next GameObject %u, Creature %u", map->GetId(), map->GetMaxLowGuid<HighGuid::GameObject>(), map->GetMaxLowGuid<HighGuid::Unit>());

        return true;
    }

    static bool HandleDebugBoundaryCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;
        Creature* target = handler->getSelectedCreature();
        if (!target || !target->IsAIEnabled())
            return false;

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

    static bool HandleDebugRaidResetCommand(ChatHandler* handler, char const* args)
    {
        char* map_str = args ? strtok((char*)args, " ") : nullptr;
        char* difficulty_str = args ? strtok(nullptr, " ") : nullptr;

        int32 map = map_str ? atoi(map_str) : -1;
        MapEntry const* mEntry = (map >= 0) ? sMapStore.LookupEntry(map) : nullptr;
        if (!mEntry)
        {
            handler->PSendSysMessage("Invalid map specified.");
            return false;
        }
        if (!mEntry->IsDungeon())
        {
            handler->PSendSysMessage("'%s' is not a dungeon map.", mEntry->MapName[LOCALE_enUS]);
            return true;
        }
        int32 difficulty = difficulty_str ? atoi(difficulty_str) : -1;
        if (difficulty >= MAX_RAID_DIFFICULTY || difficulty < -1)
        {
            handler->PSendSysMessage("Invalid difficulty %d - specify in range [0,%d).", difficulty, MAX_RAID_DIFFICULTY);
            return false;
        }
        if (difficulty >= 0 && !sDBCManager.GetMapDifficultyData(mEntry->ID, Difficulty(difficulty)))
        {
            handler->PSendSysMessage("Difficulty %d is not valid for '%s'.", difficulty, mEntry->MapName[LOCALE_enUS]);
            return true;
        }

        if (difficulty == -1)
        {
            handler->PSendSysMessage("Resetting all difficulties for '%s'.", mEntry->MapName[LOCALE_enUS]);
            for (uint8 diff = (mEntry->IsRaid() ? 0 : 1); diff < (mEntry->IsRaid() ? MAX_RAID_DIFFICULTY : MAX_DUNGEON_DIFFICULTY); ++diff)
            {
                if (sDBCManager.GetMapDifficultyData(mEntry->ID, Difficulty(diff)))
                {
                    handler->PSendSysMessage("Resetting difficulty %d for '%s'.", diff, mEntry->MapName[LOCALE_enUS]);
                    sInstanceSaveMgr->ForceGlobalReset(mEntry->ID, Difficulty(diff));
                }
            }
        }
        else if (mEntry->IsNonRaidDungeon() && difficulty == DUNGEON_DIFFICULTY_NORMAL)
        {
            handler->PSendSysMessage("'%s' does not have any permanent saves for difficulty %d.", mEntry->MapName[LOCALE_enUS], difficulty);
        }
        else
        {
            handler->PSendSysMessage("Resetting difficulty %d for '%s'.", difficulty, mEntry->MapName[LOCALE_enUS]);
            sInstanceSaveMgr->ForceGlobalReset(mEntry->ID, Difficulty(difficulty));
        }
        return true;
    }

    static bool HandleDebugNearGraveyard(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        WorldSafeLocsEntry const* nearestLoc = nullptr;

        if (stricmp(args, "linked"))
        {
            if (Battleground* bg = player->GetBattleground())
                nearestLoc = bg->GetClosestGraveyard(player);
            else
            {
                if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetMap(), player->GetZoneId()))
                    nearestLoc = bf->GetClosestGraveyard(player);
                else
                    nearestLoc = sObjectMgr->GetClosestGraveyard(*player, player->GetTeam(), player);
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
                if (loc && loc->Continent == player->GetMapId())
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
};

void AddSC_debug_commandscript()
{
    new debug_commandscript();
}
