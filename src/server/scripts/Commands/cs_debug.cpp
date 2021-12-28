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
#include "ChannelPackets.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Conversation.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Log.h"
#include "M2Stores.h"
#include "MapManager.h"
#include "MovementPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "PoolMgr.h"
#include "QuestPools.h"
#include "RBAC.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "Transport.h"
#include "World.h"
#include "WorldSession.h"
#include <fstream>
#include <limits>
#include <map>
#include <set>
#include <sstream>

using namespace Trinity::ChatCommands;
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
            { "playerchoice",  rbac::RBAC_PERM_COMMAND_DEBUG_SEND_PLAYER_CHOICE, false, &HandleDebugSendPlayerChoiceCommand,    "" },
        };
        static std::vector<ChatCommand> debugPvpCommandTable =
        {
            { "warmode",       rbac::RBAC_PERM_COMMAND_DEBUG,                    false, &HandleDebugWarModeFactionBalanceCommand, "" },
        };
        static std::vector<ChatCommand> debugAsanCommandTable =
        {
            { "memoryleak",    rbac::RBAC_PERM_COMMAND_DEBUG_ASAN,               true,  &HandleDebugMemoryLeak,         "" },
            { "outofbounds",   rbac::RBAC_PERM_COMMAND_DEBUG_ASAN,               true,  &HandleDebugOutOfBounds,        "" },
        };
        static std::vector<ChatCommand> debugCommandTable =
        {
            { "threat",        rbac::RBAC_PERM_COMMAND_DEBUG_THREAT,        false, &HandleDebugThreatListCommand,       "" },
            { "threatinfo",    rbac::RBAC_PERM_COMMAND_DEBUG_THREATINFO,    false, &HandleDebugThreatInfoCommand,       "" },
            { "combat",        rbac::RBAC_PERM_COMMAND_DEBUG_COMBAT,        false, &HandleDebugCombatListCommand,       "" },
            { "anim",          rbac::RBAC_PERM_COMMAND_DEBUG_ANIM,          false, &HandleDebugAnimCommand,             "" },
            { "arena",         rbac::RBAC_PERM_COMMAND_DEBUG_ARENA,         true,  &HandleDebugArenaCommand,            "" },
            { "bg",            rbac::RBAC_PERM_COMMAND_DEBUG_BG,            true,  &HandleDebugBattlegroundCommand,     "" },
            { "getitemstate",  rbac::RBAC_PERM_COMMAND_DEBUG_GETITEMSTATE,  false, &HandleDebugGetItemStateCommand,     "" },
            { "lootrecipient", rbac::RBAC_PERM_COMMAND_DEBUG_LOOTRECIPIENT, false, &HandleDebugGetLootRecipientCommand, "" },
            { "play",          rbac::RBAC_PERM_COMMAND_DEBUG_PLAY,          false, nullptr,                             "", debugPlayCommandTable },
            { "send",          rbac::RBAC_PERM_COMMAND_DEBUG_SEND,          false, nullptr,                             "", debugSendCommandTable },
            { "setaurastate",  rbac::RBAC_PERM_COMMAND_DEBUG_SETAURASTATE,  false, &HandleDebugSetAuraStateCommand,     "" },
            { "spawnvehicle",  rbac::RBAC_PERM_COMMAND_DEBUG_SPAWNVEHICLE,  false, &HandleDebugSpawnVehicleCommand,     "" },
            { "setvid",        rbac::RBAC_PERM_COMMAND_DEBUG_SETVID,        false, &HandleDebugSetVehicleIdCommand,     "" },
            { "entervehicle",  rbac::RBAC_PERM_COMMAND_DEBUG_ENTERVEHICLE,  false, &HandleDebugEnterVehicleCommand,     "" },
            { "worldstate",    rbac::RBAC_PERM_COMMAND_DEBUG_WORLDSTATE,    false, &HandleDebugUpdateWorldStateCommand, "" },
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
            { "instancespawn", rbac::RBAC_PERM_COMMAND_DEBUG_INSTANCESPAWN, false, &HandleDebugInstanceSpawns,          "" },
            { "conversation" , rbac::RBAC_PERM_COMMAND_DEBUG_CONVERSATION,  false, &HandleDebugConversationCommand,     "" },
            { "worldstate" ,   rbac::RBAC_PERM_COMMAND_DEBUG,               false, &HandleDebugWorldStateCommand,       "" },
            { "wsexpression" , rbac::RBAC_PERM_COMMAND_DEBUG,               false, &HandleDebugWSExpressionCommand,     "" },
            { "pvp",           rbac::RBAC_PERM_COMMAND_DEBUG,               false, nullptr,                             "", debugPvpCommandTable },
            { "dummy",         rbac::RBAC_PERM_COMMAND_DEBUG_DUMMY,         false, &HandleDebugDummyCommand,            "" },
            { "asan",          rbac::RBAC_PERM_COMMAND_DEBUG_ASAN,          true,  nullptr,                             "", debugAsanCommandTable },
            { "guidlimits",    rbac::RBAC_PERM_COMMAND_DEBUG,               true,  &HandleDebugGuidLimitsCommand,       "" },
            { "questreset",    rbac::RBAC_PERM_COMMAND_DEBUG_QUESTRESET,    true,  &HandleDebugQuestResetCommand,       "" }
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "debug",         rbac::RBAC_PERM_COMMAND_DEBUG,               true,  nullptr,                             "", debugCommandTable },
            { "wpgps",         rbac::RBAC_PERM_COMMAND_WPGPS,               false, &HandleWPGPSCommand,                 "" },
        };
        return commandTable;
    }

    static bool TryExtractTeamId(std::string const &args, TeamId &outFaction)
    {
        if ("a" == args || "alliance" == args)
            outFaction = TEAM_ALLIANCE;
        else if ("h" == args || "horde" == args)
            outFaction = TEAM_HORDE;
        else if ("n" == args || "neutral" == args)
            outFaction = TEAM_NEUTRAL;
        else
            return false;

        return true;
    }

    static bool HandleDebugWarModeFactionBalanceCommand(ChatHandler* handler, Variant<uint32, ExactSequence<'a','l','l','i','a','n','c','e'>, ExactSequence<'h','o','r','d','e'>, ExactSequence<'n','e','u','t','r','a','l'>, ExactSequence<'o','f','f'>> command, Optional<int32> rewardValue)
    {
        // USAGE: .debug pvp fb <alliance|horde|neutral|off> [pct]
        // neutral     Sets faction balance off.
        // alliance    Set faction balance to alliance.
        // horde       Set faction balance to horde.
        // off         Reset the faction balance and use the calculated value of it
        switch (command.which())
        {
            case 0: // workaround for Variant of only ExactSequences not being supported
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            case 1:
                sWorld->SetForcedWarModeFactionBalanceState(TEAM_ALLIANCE, rewardValue.get_value_or(0));
                break;
            case 2:
                sWorld->SetForcedWarModeFactionBalanceState(TEAM_HORDE, rewardValue.get_value_or(0));
                break;
            case 3:
                sWorld->SetForcedWarModeFactionBalanceState(TEAM_NEUTRAL);
                break;
            case 4:
                sWorld->DisableForcedWarModeFactionBalanceState();
                break;
        }

        return true;
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
            handler->PSendSysMessage(SZFMTD " waypoints dumped", flyByCameras->size());
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

    //Play sound
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

        char const* soundIdToken = strtok((char*)args, " ");

        uint32 soundId = atoul(soundIdToken);

        if (!sSoundKitStore.LookupEntry(soundId))
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

        uint32 broadcastTextId = 0;
        char const* broadcastTextIdToken = strtok(nullptr, " ");
        if (broadcastTextIdToken)
            broadcastTextId = atoul(broadcastTextIdToken);

        if (player->GetTarget().IsEmpty())
            unit->PlayDistanceSound(soundId, player);
        else
            unit->PlayDirectSound(soundId, player, broadcastTextId);

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
        if (!sSoundKitStore.LookupEntry(musicId))
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
        char* s = strtok(nullptr, " ");

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

        WorldPackets::Channel::ChannelNotify channelNotify;
        channelNotify.Type = code;
        channelNotify._Channel = name;
        handler->GetSession()->SendPacket(channelNotify.Write());
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

        handler->PSendSysMessage("Loot recipient for creature %s (%s, SpawnID " UI64FMTD ") is %s",
            target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->GetSpawnId(),
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

                    if (updateQueue[qp] == nullptr)
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

                            if (updateQueue[qp] == nullptr)
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
            handler->PSendSysMessage("%s (%s) is not alive.%s", target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->IsEngaged() ? " (It is, however, engaged. Huh?)" : "");
            return true;
        }

        uint32 count = 0;
        auto const& threatenedByMe = target->GetThreatManager().GetThreatenedByMeList();
        if (threatenedByMe.empty())
            handler->PSendSysMessage("%s (%s) does not threaten any units.", target->GetName().c_str(), target->GetGUID().ToString().c_str());
        else
        {
            handler->PSendSysMessage("List of units threatened by %s (%s)", target->GetName().c_str(), target->GetGUID().ToString().c_str());
            for (auto const& pair : threatenedByMe)
            {
                Unit* unit = pair.second->GetOwner();
                handler->PSendSysMessage("   %u.   %s   (%s, SpawnID " UI64FMTD ")  - threat %f", ++count, unit->GetName().c_str(), unit->GetGUID().ToString().c_str(), unit->GetTypeId() == TYPEID_UNIT ? unit->ToCreature()->GetSpawnId() : 0, pair.second->GetThreat());
            }
            handler->SendSysMessage("End of threatened-by-me list.");
        }

        if (mgr.CanHaveThreatList())
        {
            if (!mgr.IsThreatListEmpty(true))
            {
                if (target->IsEngaged())
                    handler->PSendSysMessage("Threat list of %s (%s, SpawnID " UI64FMTD "):", target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);
                else
                    handler->PSendSysMessage("%s (%s, SpawnID " UI64FMTD ") is not engaged, but still has a threat list? Well, here it is:", target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);

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
                    handler->PSendSysMessage("   %u.   %s   (%s)  - threat %f%s%s", ++count, unit->GetName().c_str(), unit->GetGUID().ToString().c_str(), ref->GetThreat(), tauntStr, onlineStr);
                }
                handler->SendSysMessage("End of threat list.");
            }
            else if (!target->IsEngaged())
                handler->PSendSysMessage("%s (%s, SpawnID " UI64FMTD ") is not currently engaged.", target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);
            else
                handler->PSendSysMessage("%s (%s, SpawnID " UI64FMTD ") seems to be engaged, but does not have a threat list??", target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->GetTypeId() == TYPEID_UNIT ? target->ToCreature()->GetSpawnId() : 0);
        }
        else if (target->IsEngaged())
            handler->PSendSysMessage("%s (%s) is currently engaged. (This unit cannot have a threat list.)", target->GetName().c_str(), target->GetGUID().ToString().c_str());
        else
            handler->PSendSysMessage("%s (%s) is not currently engaged. (This unit cannot have a threat list.)", target->GetName().c_str(), target->GetGUID().ToString().c_str());
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
            handler->PSendSysMessage(" |-- Physical: %.2f%%", mods[SPELL_SCHOOL_NORMAL] * 100.0f);
            handler->PSendSysMessage(" |-- Holy    : %.2f%%", mods[SPELL_SCHOOL_HOLY] * 100.0f);
            handler->PSendSysMessage(" |-- Fire    : %.2f%%", mods[SPELL_SCHOOL_FIRE] * 100.0f);
            handler->PSendSysMessage(" |-- Nature  : %.2f%%", mods[SPELL_SCHOOL_NATURE] * 100.0f);
            handler->PSendSysMessage(" |-- Frost   : %.2f%%", mods[SPELL_SCHOOL_FROST] * 100.0f);
            handler->PSendSysMessage(" |-- Shadow  : %.2f%%", mods[SPELL_SCHOOL_SHADOW] * 100.0f);
            handler->PSendSysMessage(" |-- Arcane  : %.2f%%", mods[SPELL_SCHOOL_ARCANE] * 100.0f);
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
                    SpellInfo const* const spell = sSpellMgr->GetSpellInfo(outerPair.first, DIFFICULTY_NONE);
                    handler->PSendSysMessage(" |-- #%06u %s (%zu entries):", outerPair.first, spell ? (*spell->SpellName)[sWorld->GetDefaultDbcLocale()] : "<unknown>", outerPair.second.size());
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

        char* j = strtok(nullptr, " ");

        uint32 entry = atoul(i);
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

        uint32 entry = atoul(e);

        float x, y, z, o = handler->GetSession()->GetPlayer()->GetOrientation();
        handler->GetSession()->GetPlayer()->GetClosePoint(x, y, z, handler->GetSession()->GetPlayer()->GetCombatReach());

        if (!i)
            return handler->GetSession()->GetPlayer()->SummonCreature(entry, x, y, z, o) != nullptr;

        uint32 id = atoul(i);

        CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(entry);

        if (!ci)
            return false;

        VehicleEntry const* ve = sVehicleStore.LookupEntry(id);

        if (!ve)
            return false;

        Map* map = handler->GetSession()->GetPlayer()->GetMap();
        Position pos = { x, y, z, o };

        Creature* v = Creature::CreateCreature(entry, map, pos, id);
        if (!v)
            return false;

        PhasingHandler::InheritPhaseShift(v, handler->GetSession()->GetPlayer());

        map->AddToMap(v);

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

        TC_LOG_INFO("sql.dev", "(@PATH, XX, %.3f, %.3f, %.5f, %.5f, 0, 0, 0, 100, 0),", player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());

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

        PhasingHandler::PrintToChat(handler, target);
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
            handler->PSendSysMessage("'%s' is not a dungeon map.",
                    mEntry->MapName[handler->GetSessionDbcLocale()]);
            return true;
        }
        int32 difficulty = difficulty_str ? atoi(difficulty_str) : -1;
        if (!sDifficultyStore.HasRecord(difficulty) || difficulty < -1)
        {
            handler->PSendSysMessage("Invalid difficulty %d.", difficulty);
            return false;
        }
        if (difficulty >= 0 && !sDB2Manager.GetMapDifficultyData(mEntry->ID, Difficulty(difficulty)))
        {
            handler->PSendSysMessage("Difficulty %d is not valid for '%s'.",
                    difficulty, mEntry->MapName[handler->GetSessionDbcLocale()]);
            return true;
        }

        if (difficulty == -1)
        {
            handler->PSendSysMessage("Resetting all difficulties for '%s'.",
                    mEntry->MapName[handler->GetSessionDbcLocale()]);
            for (DifficultyEntry const* diff : sDifficultyStore)
            {
                if (sDB2Manager.GetMapDifficultyData(map, Difficulty(diff->ID)))
                {
                    handler->PSendSysMessage("Resetting difficulty %d for '%s'.",
                            diff->ID, mEntry->MapName[handler->GetSessionDbcLocale()]);
                    sInstanceSaveMgr->ForceGlobalReset(map, Difficulty(diff->ID));
                }
            }
        }
        else if (mEntry->IsNonRaidDungeon() && difficulty == DIFFICULTY_NORMAL)
        {
            handler->PSendSysMessage("'%s' does not have any permanent saves for difficulty %d.",
                    mEntry->MapName[handler->GetSessionDbcLocale()], difficulty);
        }
        else
        {
            handler->PSendSysMessage("Resetting difficulty %d for '%s'.",
                    difficulty, mEntry->MapName[handler->GetSessionDbcLocale()]);
            sInstanceSaveMgr->ForceGlobalReset(map, Difficulty(difficulty));
        }
        return true;
    }

    static bool HandleDebugQuestResetCommand(ChatHandler* handler, std::string arg)
    {
        if (!Utf8ToUpperOnlyLatin(arg))
            return false;

        bool daily = false, weekly = false, monthly = false;
        if (arg == "ALL")
            daily = weekly = monthly = true;
        else if (arg == "DAILY")
            daily = true;
        else if (arg == "WEEKLY")
            weekly = true;
        else if (arg == "MONTHLY")
            monthly = true;
        else
            return false;

        if (daily)
        {
            sWorld->DailyReset();
            handler->PSendSysMessage("Daily quests have been reset. Next scheduled reset: %s", TimeToHumanReadable(sWorld->getWorldState(WS_DAILY_QUEST_RESET_TIME)).c_str());
        }
        if (weekly)
        {
            sWorld->ResetWeeklyQuests();
            handler->PSendSysMessage("Weekly quests have been reset. Next scheduled reset: %s", TimeToHumanReadable(sWorld->getWorldState(WS_WEEKLY_QUEST_RESET_TIME)).c_str());
        }
        if (monthly)
        {
            sWorld->ResetMonthlyQuests();
            handler->PSendSysMessage("Monthly quests have been reset. Next scheduled reset: %s", TimeToHumanReadable(sWorld->getWorldState(WS_MONTHLY_QUEST_RESET_TIME)).c_str());
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
                if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId()))
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

            for (auto&& kvp : sObjectMgr->GetWorldSafeLocs())
            {
                if (kvp.second.Loc.GetMapId() == player->GetMapId())
                {
                    float dist = (kvp.second.Loc.GetPositionX() - x) * (kvp.second.Loc.GetPositionX() - x)
                        + (kvp.second.Loc.GetPositionY() - y) * (kvp.second.Loc.GetPositionY() - y)
                        + (kvp.second.Loc.GetPositionZ() - z) * (kvp.second.Loc.GetPositionZ() - z);
                    if (dist < distNearest)
                    {
                        distNearest = dist;
                        nearestLoc = &kvp.second;
                    }
                }
            }
        }

        if (nearestLoc)
            handler->PSendSysMessage(LANG_COMMAND_NEARGRAVEYARD, nearestLoc->ID, nearestLoc->Loc.GetPositionX(), nearestLoc->Loc.GetPositionY(), nearestLoc->Loc.GetPositionZ());
        else
            handler->PSendSysMessage(LANG_COMMAND_NEARGRAVEYARD_NOTFOUND);

        return true;
    }

    static bool HandleDebugInstanceSpawns(ChatHandler* handler, char const* args)
    {
        Player const* const player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        bool explain = false;
        uint32 groupID = 0;
        if (!stricmp(args, "explain"))
            explain = true;
        else
            groupID = atoi(args);

        if (groupID && !sObjectMgr->GetSpawnGroupData(groupID))
        {
            handler->PSendSysMessage("There is no spawn group with ID %u.", groupID);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Map const* const map = player->GetMap();
        char const* const mapName = map->GetMapName();
        InstanceScript const* const instance = player->GetInstanceScript();
        if (!instance)
        {
            handler->PSendSysMessage("%s has no instance script.", mapName);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!instance->_instanceSpawnGroups || instance->_instanceSpawnGroups->empty())
        {
            handler->PSendSysMessage("%s's instance script does not manage any spawn groups.", mapName);
            handler->SetSentErrorMessage(true);
            return false;
        }
        auto const& spawnGroups = *instance->_instanceSpawnGroups;
        std::map<uint32, std::set<std::tuple<bool, uint8, uint8>>> store;
        for (InstanceSpawnGroupInfo const& info : spawnGroups)
        {
            if (groupID && info.SpawnGroupId != groupID)
                continue;

            bool isSpawn;
            if (info.Flags & InstanceSpawnGroupInfo::FLAG_BLOCK_SPAWN)
                isSpawn = false;
            else if (info.Flags & InstanceSpawnGroupInfo::FLAG_ACTIVATE_SPAWN)
                isSpawn = true;
            else
                continue;

            store[info.SpawnGroupId].emplace(isSpawn, info.BossStateId, info.BossStates);
        }

        if (groupID && store.find(groupID) == store.end())
        {
            handler->PSendSysMessage("%s's instance script does not manage group '%s'.", mapName, sObjectMgr->GetSpawnGroupData(groupID)->name.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!groupID)
            handler->PSendSysMessage("Spawn groups managed by %s (%u):", mapName, map->GetId());

        for (auto const& pair : store)
        {
            SpawnGroupTemplateData const* groupData = sObjectMgr->GetSpawnGroupData(pair.first);
            ASSERT(groupData); // checked by objectmgr on load
            if (explain)
            {
                handler->PSendSysMessage(" |-- '%s' (%u)", groupData->name, pair.first);
                bool isBlocked = false, isSpawned = false;
                for (auto const& tuple : pair.second)
                {
                    bool const isSpawn = std::get<0>(tuple);
                    uint8 const bossStateId = std::get<1>(tuple);
                    EncounterState const actualState = instance->GetBossState(bossStateId);
                    if (std::get<2>(tuple) & (1 << actualState))
                    {
                        if (isSpawn)
                        {
                            isSpawned = true;
                            if (isBlocked)
                                handler->PSendSysMessage(" | |-- '%s' would be allowed to spawn by boss state %u being %s, but this is overruled", groupData->name, bossStateId, InstanceScript::GetBossStateName(actualState));
                            else
                                handler->PSendSysMessage(" | |-- '%s' is allowed to spawn because boss state %u is %s.", groupData->name, bossStateId, InstanceScript::GetBossStateName(bossStateId));
                        }
                        else
                        {
                            isBlocked = true;
                            handler->PSendSysMessage(" | |-- '%s' is blocked from spawning because boss state %u is %s.", groupData->name, bossStateId, InstanceScript::GetBossStateName(bossStateId));
                        }
                    }
                    else
                        handler->PSendSysMessage(" | |-- '%s' could've been %s if boss state %u matched mask 0x%02x; but it is %s -> 0x%02x, which does not match.",
                            groupData->name, isSpawn ? "allowed to spawn" : "blocked from spawning", bossStateId, std::get<2>(tuple), InstanceScript::GetBossStateName(actualState), (1 << actualState));
                }
                if (isBlocked)
                    handler->PSendSysMessage(" | |=> '%s' is not active due to a blocking rule being matched", groupData->name);
                else if (isSpawned)
                    handler->PSendSysMessage(" | |=> '%s' is active due to a spawn rule being matched", groupData->name);
                else
                    handler->PSendSysMessage(" | |=> '%s' is not active due to none of its rules being matched", groupData->name);
            }
            else
                handler->PSendSysMessage(" - '%s' (%u) is %sactive", groupData->name, pair.first, map->IsSpawnGroupActive(pair.first) ? "" : "not ");
        }
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

        return Conversation::CreateConversation(conversationEntry, target, *target, target->GetGUID()) != nullptr;
    }

    static bool HandleDebugWorldStateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* worldStateIdStr = strtok((char*)args, " ");
        char const* valueStr = args ? strtok(nullptr, " ") : nullptr;

        if (!worldStateIdStr)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 worldStateId = atoi(worldStateIdStr);
        uint32 value = valueStr ? atoi(valueStr) : 0;

        if (value)
        {
            sWorld->setWorldState(worldStateId, value);
            target->SendUpdateWorldState(worldStateId, value);
        }
        else
            handler->PSendSysMessage("Worldstate %u actual value : %u", worldStateId, sWorld->getWorldState(worldStateId));

        return true;
    }

    static bool HandleDebugWSExpressionCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char const* expressionIdStr = strtok((char*)args, " ");

        if (!expressionIdStr)
            return false;

        uint32 expressionId = atoi(expressionIdStr);
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        WorldStateExpressionEntry const* wsExpressionEntry = sWorldStateExpressionStore.LookupEntry(expressionId);
        if (!wsExpressionEntry)
            return false;

        if (sConditionMgr->IsPlayerMeetingExpression(target, wsExpressionEntry))
            handler->PSendSysMessage("Expression %u meet", expressionId);
        else
            handler->PSendSysMessage("Expression %u not meet", expressionId);

        return true;
    };

    static bool HandleDebugOutOfBounds(ChatHandler* handler, CommandArgs* /*args*/)
    {
        uint8 stack_array[10] = {};
        int size = 10;

        handler->PSendSysMessage("Triggered an array out of bounds read at address %p, value %u", stack_array + size, stack_array[size]);
        return true;
    }

    static bool HandleDebugMemoryLeak(ChatHandler* handler, CommandArgs* /*args*/)
    {
        uint8* leak = new uint8();
        handler->PSendSysMessage("Leaked 1 uint8 object at address %p", leak);
        return true;
    }

    static bool HandleDebugGuidLimitsCommand(ChatHandler* handler, CommandArgs* args)
    {
        auto mapId = args->TryConsume<uint32>();
        if (mapId)
        {
            sMapMgr->DoForAllMapsWithMapId(mapId.get(),
                [handler](Map* map) -> void
                {
                    HandleDebugGuidLimitsMap(handler, map);
                }
            );
        }
        else
        {
            sMapMgr->DoForAllMaps(
                [handler](Map* map) -> void
                {
                    HandleDebugGuidLimitsMap(handler, map);
                }
            );
        }

        handler->PSendSysMessage("Guid Warn Level: %u", sWorld->getIntConfig(CONFIG_RESPAWN_GUIDWARNLEVEL));
        handler->PSendSysMessage("Guid Alert Level: %u", sWorld->getIntConfig(CONFIG_RESPAWN_GUIDALERTLEVEL));
        return true;
    }

    static void HandleDebugGuidLimitsMap(ChatHandler* handler, Map* map)
    {
        handler->PSendSysMessage("Map Id: %u Name: '%s' Instance Id: %u Highest Guid Creature: " UI64FMTD " GameObject: " UI64FMTD,
            map->GetId(), map->GetMapName(), map->GetInstanceId(), uint64(map->GenerateLowGuid<HighGuid::Creature>()), uint64(map->GetMaxLowGuid<HighGuid::GameObject>()));
    }

    static bool HandleDebugDummyCommand(ChatHandler* handler, CommandArgs* /*args*/)
    {
        handler->SendSysMessage("This command does nothing right now. Edit your local core (cs_debug.cpp) to make it do whatever you need for testing.");
        return true;
    }
};

void AddSC_debug_commandscript()
{
    new debug_commandscript();
}
