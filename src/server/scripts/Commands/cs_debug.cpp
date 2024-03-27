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
#include "Channel.h"
#include "ChannelPackets.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "ChatPackets.h"
#include "Conversation.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GameTime.h"
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
#include "RBAC.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "Transport.h"
#include "Warden.h"
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

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable debugPlayCommandTable =
        {
            { "cinematic",          HandleDebugPlayCinematicCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,  Console::No },
            { "movie",              HandleDebugPlayMovieCommand,            rbac::RBAC_PERM_COMMAND_DEBUG,  Console::No },
            { "sound",              HandleDebugPlaySoundCommand,            rbac::RBAC_PERM_COMMAND_DEBUG,  Console::No },
            { "music",              HandleDebugPlayMusicCommand,            rbac::RBAC_PERM_COMMAND_DEBUG,  Console::No },
            { "objectsound",        HandleDebugPlayObjectSoundCommand,      rbac::RBAC_PERM_COMMAND_DEBUG,  Console::No },
        };
        static ChatCommandTable debugSendCommandTable =
        {
            { "buyerror",           HandleDebugSendBuyErrorCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "channelnotify",      HandleDebugSendChannelNotifyCommand,   rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "chatmessage",        HandleDebugSendChatMsgCommand,         rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "equiperror",         HandleDebugSendEquipErrorCommand,      rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "largepacket",        HandleDebugSendLargePacketCommand,     rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "opcode",             HandleDebugSendOpcodeCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "qpartymsg",          HandleDebugSendQuestPartyMsgCommand,   rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "qinvalidmsg",        HandleDebugSendQuestInvalidMsgCommand, rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "sellerror",          HandleDebugSendSellErrorCommand,       rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "setphaseshift",      HandleDebugSendSetPhaseShiftCommand,   rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "spellfail",          HandleDebugSendSpellFailCommand,       rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "playerchoice",       HandleDebugSendPlayerChoiceCommand,    rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
        };
        static ChatCommandTable debugCommandTable =
        {
            { "threat",             HandleDebugThreatListCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "threatinfo",         HandleDebugThreatInfoCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "combat",             HandleDebugCombatListCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "anim",               HandleDebugAnimCommand,                rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "arena",              HandleDebugArenaCommand,               rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "bg",                 HandleDebugBattlegroundCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "getitemstate",       HandleDebugGetItemStateCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "lootrecipient",      HandleDebugGetLootRecipientCommand,    rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "play",               debugPlayCommandTable },
            { "send",               debugSendCommandTable },
            { "setaurastate",       HandleDebugSetAuraStateCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "spawnvehicle",       HandleDebugSpawnVehicleCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "entervehicle",       HandleDebugEnterVehicleCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "worldstate" ,        HandleDebugUpdateWorldStateCommand,    rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "itemexpire",         HandleDebugItemExpireCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "areatriggers",       HandleDebugAreaTriggersCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "los",                HandleDebugLoSCommand,                 rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "moveflags",          HandleDebugMoveflagsCommand,           rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "transport",          HandleDebugTransportCommand,           rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "loadcells",          HandleDebugLoadCellsCommand,           rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "phase",              HandleDebugPhaseCommand,               rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "boundary",           HandleDebugBoundaryCommand,            rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "raidreset",          HandleDebugRaidResetCommand,           rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "neargraveyard",      HandleDebugNearGraveyard,              rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "instancespawn",      HandleDebugInstanceSpawns,             rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "conversation",       HandleDebugConversationCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "wsexpression",       HandleDebugWSExpressionCommand,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "playercondition",    HandleDebugPlayerConditionCommand,     rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "pvp warmode",        HandleDebugWarModeBalanceCommand,      rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "dummy",              HandleDebugDummyCommand,               rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
            { "asan memoryleak",    HandleDebugMemoryLeak,                 rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "asan outofbounds",   HandleDebugOutOfBounds,                rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "guidlimits",         HandleDebugGuidLimitsCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "objectcount",        HandleDebugObjectCountCommand,         rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "questreset",         HandleDebugQuestResetCommand,          rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "warden force",       HandleDebugWardenForce,                rbac::RBAC_PERM_COMMAND_DEBUG,   Console::Yes },
            { "personalclone",      HandleDebugBecomePersonalClone,        rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No }
        };
        static ChatCommandTable commandTable =
        {
            { "debug",              debugCommandTable },
            { "wpgps",              HandleWPGPSCommand,                    rbac::RBAC_PERM_COMMAND_DEBUG,   Console::No },
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

    static bool HandleDebugWarModeBalanceCommand(ChatHandler* handler, Variant<uint32, EXACT_SEQUENCE("alliance"), EXACT_SEQUENCE("horde"), EXACT_SEQUENCE("neutral"), EXACT_SEQUENCE("off")> command, Optional<int32> rewardValue)
    {
        // USAGE: .debug pvp fb <alliance|horde|neutral|off> [pct]
        // neutral     Sets faction balance off.
        // alliance    Set faction balance to alliance.
        // horde       Set faction balance to horde.
        // off         Reset the faction balance and use the calculated value of it
        switch (command.index())
        {
            case 0: // workaround for Variant of only ExactSequences not being supported
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            case 1:
                sWorld->SetForcedWarModeFactionBalanceState(TEAM_ALLIANCE, rewardValue.value_or(0));
                break;
            case 2:
                sWorld->SetForcedWarModeFactionBalanceState(TEAM_HORDE, rewardValue.value_or(0));
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

    // cinematicId - ID from CinematicSequences.dbc
    static bool HandleDebugPlayCinematicCommand(ChatHandler* handler, uint32 cinematicId)
    {
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

        handler->GetPlayer()->SendCinematicStart(cinematicId);
        return true;
    }

    // movieId - ID from Movie.dbc
    static bool HandleDebugPlayMovieCommand(ChatHandler* handler, uint32 movieId)
    {

        if (!sMovieStore.LookupEntry(movieId))
        {
            handler->PSendSysMessage(LANG_MOVIE_NOT_EXIST, movieId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->GetPlayer()->SendMovieStart(movieId);
        return true;
    }

    // soundId - ID from SoundKit.db2
    static bool HandleDebugPlaySoundCommand(ChatHandler* handler, uint32 soundId, Optional<uint32> broadcastTextId)
    {
        if (!sSoundKitStore.LookupEntry(soundId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, soundId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetPlayer();

        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetTarget().IsEmpty())
            unit->PlayDistanceSound(soundId, player);
        else
            unit->PlayDirectSound(soundId, player, broadcastTextId.value_or(0));

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, soundId);
        return true;
    }

    // musicId - ID from SoundEntries.dbc
    static bool HandleDebugPlayMusicCommand(ChatHandler* handler, uint32 musicId)
    {
        if (!sSoundKitStore.LookupEntry(musicId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, musicId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetPlayer();

        player->PlayDirectMusic(musicId, player);

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, musicId);
        return true;
    }

    static bool HandleDebugPlayObjectSoundCommand(ChatHandler* handler, int32 soundKitId, Optional<int32> broadcastTextId)
    {
        if (!sSoundKitStore.LookupEntry(soundKitId))
        {
            handler->PSendSysMessage(LANG_SOUND_NOT_EXIST, soundKitId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetPlayer();

        player->PlayObjectSound(soundKitId, player->GetGUID(), player, broadcastTextId.has_value() ? *broadcastTextId : 0);

        handler->PSendSysMessage(LANG_YOU_HEAR_SOUND, soundKitId);
        return true;
    }

    static bool HandleDebugSendSpellFailCommand(ChatHandler* handler, SpellCastResult result, Optional<int32> failArg1, Optional<int32> failArg2)
    {
        WorldPackets::Spells::CastFailed castFailed;
        castFailed.CastID = ObjectGuid::Empty;
        castFailed.SpellID = 133;
        castFailed.Reason = result;
        castFailed.FailedArg1 = failArg1.value_or(-1);
        castFailed.FailedArg2 = failArg2.value_or(-1);
        handler->GetSession()->SendPacket(castFailed.Write());

        return true;
    }

    static bool HandleDebugSendPlayerChoiceCommand(ChatHandler* handler, int32 choiceId)
    {
        Player* player = handler->GetPlayer();
        player->SendPlayerChoice(player->GetGUID(), choiceId);
        return true;
    }

    static bool HandleDebugSendEquipErrorCommand(ChatHandler* handler, InventoryResult error)
    {
        handler->GetPlayer()->SendEquipError(error, nullptr, nullptr);
        return true;
    }

    static bool HandleDebugSendSellErrorCommand(ChatHandler* handler, SellResult error)
    {
        handler->GetPlayer()->SendSellError(error, nullptr, ObjectGuid::Empty);
        return true;
    }

    static bool HandleDebugSendBuyErrorCommand(ChatHandler* handler, BuyResult error)
    {
        handler->GetPlayer()->SendBuyError(error, nullptr, 0, 0);
        return true;
    }

    static bool HandleDebugSendOpcodeCommand(ChatHandler* handler)
    {
        Unit* unit = handler->getSelectedUnit();
        Player* player = nullptr;
        if (!unit || (unit->GetTypeId() != TYPEID_PLAYER))
            player = handler->GetPlayer();
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
            char commentToken[2] = {};
            ifs.get(commentToken[0]);
            if (ifs.eof())
                break;
            if (commentToken[0] == '/')
            {
                ifs.get(commentToken[1]);
                if (!ifs.eof())
                {
                    // /* comment
                    if (commentToken[1] == '*')
                    {
                        while (!ifs.eof())
                        {
                            ifs.get(commentToken[0]);
                            if (ifs.eof())
                                break;
                            if (commentToken[0] == '*')
                            {
                                ifs.get(commentToken[1]);
                                if (ifs.eof())
                                    break;
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
                        if (ifs.eof())
                            break;
                        continue;
                    }
                    // regular data
                    else
                        ifs.putback(commentToken[1]);
                }
            }
            parsedStream.put(commentToken[0]);
        }
        ifs.close();

        uint32 opcode = 0;
        parsedStream >> opcode;

        if (!opcode)
            return false;

        WorldPacket data(OpcodeServer(opcode), 0);

        while (!parsedStream.eof() && !parsedStream.fail())
        {
            std::string type;
            parsedStream >> type;

            if (type.empty())
                break;

            if (type == "uint8")
            {
                if (parsedStream.eof())
                    return false;
                uint16 val1 = 0;
                parsedStream >> val1;
                if (parsedStream.fail())
                    return false;
                data << uint8(val1);
            }
            else if (type == "uint16")
            {
                if (parsedStream.eof())
                    return false;
                uint16 val2 = 0;
                parsedStream >> val2;
                if (parsedStream.fail())
                    return false;
                data << val2;
            }
            else if (type == "uint32")
            {
                if (parsedStream.eof())
                    return false;
                uint32 val3 = 0;
                parsedStream >> val3;
                if (parsedStream.fail())
                    return false;
                data << val3;
            }
            else if (type == "uint64")
            {
                if (parsedStream.eof())
                    return false;
                uint64 val4 = 0;
                parsedStream >> val4;
                if (parsedStream.fail())
                    return false;
                data << val4;
            }
            else if (type == "float")
            {
                if (parsedStream.eof())
                    return false;
                float val5 = 0.0f;
                parsedStream >> val5;
                if (parsedStream.fail())
                    return false;
                data << val5;
            }
            else if (type == "string")
            {
                std::string val6;
                parsedStream >> val6;
                // empty string is allowed so no need to check eof/fail here
                data << val6;
            }
            else if (type == "goguid")
            {
                GameObject* obj = handler->GetNearbyGameObject();
                if (!obj)
                {
                    handler->PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, "0");
                    handler->SetSentErrorMessage(true);
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
                TC_LOG_ERROR("misc", "Sending opcode that has unknown type '{}'", type);
                break;
            }
        }
        TC_LOG_DEBUG("network", "Sending opcode {}", data.GetOpcode());
        data.hexlike();
        player->GetSession()->SendPacket(&data, true);
        handler->PSendSysMessage(LANG_COMMAND_OPCODESENT, data.GetOpcode(), unit->GetName().c_str());
        return true;
    }

    static bool HandleDebugUpdateWorldStateCommand(ChatHandler* handler, uint32 variable, uint32 value)
    {
        handler->GetPlayer()->SendUpdateWorldState(variable, value);
        return true;
    }

    static bool HandleDebugAreaTriggersCommand(ChatHandler* handler)
    {
        Player* player = handler->GetPlayer();
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
        player->UpdateObjectVisibility();
        return true;
    }

    static bool HandleDebugSendChannelNotifyCommand(ChatHandler* handler, ChatNotify type)
    {
        WorldPackets::Channel::ChannelNotify channelNotify;
        channelNotify.Type = type;
        channelNotify._Channel = "test";
        handler->GetSession()->SendPacket(channelNotify.Write());
        return true;
    }

    static bool HandleDebugSendChatMsgCommand(ChatHandler* handler, ChatMsg type)
    {
        WorldPackets::Chat::Chat packet;
        packet.Initialize(type, LANG_UNIVERSAL, handler->GetPlayer(), handler->GetPlayer(), "testtest", 0, "chan");
        handler->GetSession()->SendPacket(packet.Write());
        return true;
    }

    static bool HandleDebugSendQuestPartyMsgCommand(ChatHandler* handler, QuestPushReason msg)
    {
        handler->GetSession()->GetPlayer()->SendPushToPartyResponse(handler->GetPlayer(), msg);
        return true;
    }

    static bool HandleDebugGetLootRecipientCommand(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
            return false;

        handler->PSendSysMessage("Loot recipients for creature %s (%s, SpawnID " UI64FMTD ") are:",
            target->GetName().c_str(), target->GetGUID().ToString().c_str(), target->GetSpawnId());

        for (ObjectGuid tapperGuid : target->GetTapList())
        {
            Player* tapper = ObjectAccessor::GetPlayer(*target, tapperGuid);
            handler->PSendSysMessage("* %s", tapper ? tapper->GetName().c_str() : "offline");
        }

        return true;
    }

    static bool HandleDebugSendQuestInvalidMsgCommand(ChatHandler* handler, QuestFailedReason msg)
    {
        handler->GetPlayer()->SendCanTakeQuestResponse(msg);
        return true;
    }

    static bool HandleDebugGetItemStateCommand(ChatHandler* handler, std::string itemState)
    {
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
            player = handler->GetPlayer();

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

    static bool HandleDebugBattlegroundCommand(ChatHandler* /*handler*/)
    {
        sBattlegroundMgr->ToggleTesting();
        return true;
    }

    static bool HandleDebugArenaCommand(ChatHandler* /*handler*/)
    {
        sBattlegroundMgr->ToggleArenaTesting();
        return true;
    }

    static bool HandleDebugThreatListCommand(ChatHandler* handler)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetPlayer();

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

    static bool HandleDebugThreatInfoCommand(ChatHandler* handler)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("Threat info for %s (%s):", target->GetName().c_str(), target->GetGUID().ToString().c_str());

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

    static bool HandleDebugCombatListCommand(ChatHandler* handler)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetPlayer();

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

    static bool HandleDebugEnterVehicleCommand(ChatHandler* handler, uint32 entry, Optional<int8> seatId)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target || !target->IsVehicle())
            return false;

        if (!seatId)
            seatId = -1;

        if (!entry)
            handler->GetPlayer()->EnterVehicle(target, *seatId);
        else
        {
            Creature* passenger = nullptr;
            Trinity::AllCreaturesOfEntryInRange check(handler->GetPlayer(), entry, 20.0f);
            Trinity::CreatureSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(handler->GetPlayer(), passenger, check);
            Cell::VisitAllObjects(handler->GetPlayer(), searcher, 30.0f);
            if (!passenger || passenger == target)
                return false;
            passenger->EnterVehicle(target, *seatId);
        }

        handler->PSendSysMessage("Unit %u entered vehicle %hhd", entry, *seatId);
        return true;
    }

    static bool HandleDebugSpawnVehicleCommand(ChatHandler* handler, uint32 entry, Optional<uint32> id)
    {
        float x, y, z, o = handler->GetPlayer()->GetOrientation();
        handler->GetPlayer()->GetClosePoint(x, y, z, handler->GetPlayer()->GetCombatReach());

        if (!id)
            return handler->GetPlayer()->SummonCreature(entry, x, y, z, o) != nullptr;

        CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(entry);

        if (!ci)
            return false;

        VehicleEntry const* ve = sVehicleStore.LookupEntry(*id);

        if (!ve)
            return false;

        Map* map = handler->GetPlayer()->GetMap();
        Position pos = { x, y, z, o };

        Creature* v = Creature::CreateCreature(entry, map, pos, *id);
        if (!v)
            return false;

        PhasingHandler::InheritPhaseShift(v, handler->GetPlayer());

        map->AddToMap(v);

        return true;
    }

    static bool HandleDebugSendLargePacketCommand(ChatHandler* handler)
    {
        std::ostringstream ss;
        while (ss.str().size() < 128000)
            ss << "This is a dummy string to push the packet's size beyond 128000 bytes. ";
        handler->SendSysMessage(ss.str().c_str());
        return true;
    }

    static bool HandleDebugSendSetPhaseShiftCommand(ChatHandler* handler, Optional<uint32> phaseId, Optional<uint32> visibleMapId, Optional<uint32> uiMapPhaseId)
    {
        PhaseShift phaseShift;

        if (phaseId)
            phaseShift.AddPhase(*phaseId, PhaseFlags::None, nullptr);

        if (visibleMapId)
            phaseShift.AddVisibleMapId(*visibleMapId, nullptr);

        if (uiMapPhaseId)
            phaseShift.AddUiMapPhaseId(*uiMapPhaseId);

        PhasingHandler::SendToPlayer(handler->GetSession()->GetPlayer(), phaseShift);
        return true;
    }

    static bool HandleDebugItemExpireCommand(ChatHandler* handler, ObjectGuid::LowType guid)
    {
        Item* i = handler->GetPlayer()->GetItemByGuid(ObjectGuid::Create<HighGuid::Item>(guid));

        if (!i)
            return false;

        handler->GetPlayer()->DestroyItem(i->GetBagSlot(), i->GetSlot(), true);
        sScriptMgr->OnItemExpire(handler->GetPlayer(), i->GetTemplate());

        return true;
    }

    // Play emote animation
    static bool HandleDebugAnimCommand(ChatHandler* handler, Emote emote)
    {
        if (Unit* unit = handler->getSelectedUnit())
            unit->HandleEmoteCommand(emote);

        handler->PSendSysMessage("Playing emote %s", EnumUtils::ToConstant(emote));

        return true;
    }

    static bool HandleDebugLoSCommand(ChatHandler* handler)
    {
        if (Unit* unit = handler->getSelectedUnit())
        {
            Player* player = handler->GetPlayer();
            handler->PSendSysMessage("Checking LoS %s -> %s:", player->GetName().c_str(), unit->GetName().c_str());
            handler->PSendSysMessage("    VMAP LoS: %s", player->IsWithinLOSInMap(unit, LINEOFSIGHT_CHECK_VMAP) ? "clear" : "obstructed");
            handler->PSendSysMessage("    GObj LoS: %s", player->IsWithinLOSInMap(unit, LINEOFSIGHT_CHECK_GOBJECT) ? "clear" : "obstructed");
            handler->PSendSysMessage("%s is %sin line of sight of %s.", unit->GetName().c_str(), (player->IsWithinLOSInMap(unit) ? "" : "not "), player->GetName().c_str());
            return true;
        }
        return false;
    }

    static bool HandleDebugSetAuraStateCommand(ChatHandler* handler, Optional<AuraStateType> state, bool apply)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!state)
        {
            // reset all states
            for (AuraStateType s : EnumUtils::Iterate<AuraStateType>())
                unit->ModifyAuraState(s, false);
            return true;
        }

        unit->ModifyAuraState(*state, apply);
        return true;
    }

    static bool HandleDebugMoveflagsCommand(ChatHandler* handler, Optional<uint32> moveFlags, Optional<uint32> moveFlagsExtra)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetPlayer();

        if (!moveFlags)
        {
            //! Display case
            handler->PSendSysMessage(LANG_MOVEFLAGS_GET, target->GetUnitMovementFlags(), target->GetExtraUnitMovementFlags());
        }
        else
        {
            /// @fixme: port master's HandleDebugMoveflagsCommand; flags need different handling

            if (moveFlagsExtra)
            {
                target->SetExtraUnitMovementFlags(*moveFlagsExtra);
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

    static bool HandleWPGPSCommand(ChatHandler* handler)
    {
        Player* player = handler->GetPlayer();

        TC_LOG_INFO("sql.dev", "(@PATH, XX, {:.3f}, {:.3f}, {:.5f}, {:.5f}, 0, 0, 0, 100, 0),", player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());

        handler->PSendSysMessage("Waypoint SQL written to SQL Developer log");
        return true;
    }

    static bool HandleDebugTransportCommand(ChatHandler* handler, std::string operation)
    {
        Transport* transport = dynamic_cast<Transport*>(handler->GetPlayer()->GetTransport());
        if (!transport)
            return false;

        bool start = false;
        if (StringEqualI(operation, "stop"))
            transport->EnableMovement(false);
        else if (StringEqualI(operation, "start"))
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

    static bool HandleDebugLoadCellsCommand(ChatHandler* handler, Optional<uint32> mapId, Optional<uint32> tileX, Optional<uint32> tileY)
    {
        if (mapId)
        {
            sMapMgr->DoForAllMapsWithMapId(*mapId, [&](Map* map)
            {
                HandleDebugLoadCellsCommandHelper(handler, map, tileX, tileY);
            });
            return true;
        }

        if (Player* player = handler->GetPlayer())
        {
            // Fallback to player's map if no map has been specified
            return HandleDebugLoadCellsCommandHelper(handler, player->GetMap(), tileX, tileY);
        }

        return false;
    }

    static bool HandleDebugLoadCellsCommandHelper(ChatHandler* handler, Map* map, Optional<uint32> tileX, Optional<uint32> tileY)
    {
        if (!map)
            return false;

        // Load 1 single tile if specified, otherwise load the whole map
        if (tileX && tileY)
        {
            handler->PSendSysMessage("Loading cell (mapId: %u tile: %u, %u). Current GameObjects " SZFMTD ", Creatures " SZFMTD,
                map->GetId(), *tileX, *tileY, map->GetObjectsStore().Size<GameObject>(), map->GetObjectsStore().Size<Creature>());

            // Some unit convertions to go from TileXY to GridXY to WorldXY
            float x = ((float(64 - 1 - *tileX) - 0.5f - CENTER_GRID_ID) * SIZE_OF_GRIDS) + (CENTER_GRID_OFFSET * 2);
            float y = ((float(64 - 1 - *tileY) - 0.5f - CENTER_GRID_ID) * SIZE_OF_GRIDS) + (CENTER_GRID_OFFSET * 2);
            map->LoadGrid(x, y);

            handler->PSendSysMessage("Cell loaded (mapId: %u tile: %u, %u) After load - GameObject " SZFMTD ", Creatures " SZFMTD,
                map->GetId(), *tileX, *tileY, map->GetObjectsStore().Size<GameObject>(), map->GetObjectsStore().Size<Creature>());
        }
        else
        {
            handler->PSendSysMessage("Loading all cells (mapId: %u). Current GameObjects " SZFMTD ", Creatures " SZFMTD, map->GetId(), map->GetObjectsStore().Size<GameObject>(), map->GetObjectsStore().Size<Creature>());

            map->LoadAllCells();

            handler->PSendSysMessage("Cells loaded (mapId: %u) After load - GameObject " SZFMTD ", Creatures " SZFMTD, map->GetId(), map->GetObjectsStore().Size<GameObject>(), map->GetObjectsStore().Size<Creature>());
        }

        return true;
    }

    static bool HandleDebugBoundaryCommand(ChatHandler* handler, Optional<EXACT_SEQUENCE("fill")> fill, Optional<uint32> durationArg)
    {
        Player* player = handler->GetPlayer();
        if (!player)
            return false;
        Creature* target = handler->getSelectedCreature();
        if (!target || !target->IsAIEnabled())
            return false;

        Seconds duration = durationArg ? Seconds(*durationArg) : 0s;
        if (duration <= 0s || duration >= 30min) // arbitrary upper limit
            duration = 3min;

        int32 errMsg = target->AI()->VisualizeBoundary(duration, player, fill.has_value());
        if (errMsg > 0)
            handler->PSendSysMessage(errMsg);

        return true;
    }

    static bool HandleDebugPhaseCommand(ChatHandler* handler)
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

    static bool HandleDebugRaidResetCommand(ChatHandler* handler, uint32 mapId, Optional<uint32> difficulty)
    {
        MapEntry const* mEntry = sMapStore.LookupEntry(mapId);
        if (!mEntry)
        {
            handler->PSendSysMessage("Invalid map specified.");
            return true;
        }
        if (!mEntry->IsDungeon())
        {
            handler->PSendSysMessage("'%s' is not a dungeon map.", mEntry->MapName[handler->GetSessionDbcLocale()]);
            return true;
        }
        if (difficulty && !sDifficultyStore.HasRecord(*difficulty))
        {
            handler->PSendSysMessage("Invalid difficulty %d.", *difficulty);
            return false;
        }
        if (difficulty && !sDB2Manager.GetMapDifficultyData(mEntry->ID, Difficulty(*difficulty)))
        {
            handler->PSendSysMessage("Difficulty %d is not valid for '%s'.", *difficulty, mEntry->MapName[handler->GetSessionDbcLocale()]);
            return true;
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
            handler->PSendSysMessage("Daily quests have been reset. Next scheduled reset: %s", TimeToHumanReadable(sWorld->GetPersistentWorldVariable(World::NextDailyQuestResetTimeVarId)).c_str());
        }
        if (weekly)
        {
            sWorld->ResetWeeklyQuests();
            handler->PSendSysMessage("Weekly quests have been reset. Next scheduled reset: %s", TimeToHumanReadable(sWorld->GetPersistentWorldVariable(World::NextWeeklyQuestResetTimeVarId)).c_str());
        }
        if (monthly)
        {
            sWorld->ResetMonthlyQuests();
            handler->PSendSysMessage("Monthly quests have been reset. Next scheduled reset: %s", TimeToHumanReadable(sWorld->GetPersistentWorldVariable(World::NextMonthlyQuestResetTimeVarId)).c_str());
        }

        return true;
    }

    static bool HandleDebugNearGraveyard(ChatHandler* handler, Optional<EXACT_SEQUENCE("linked")> linked)
    {
        Player* player = handler->GetPlayer();
        WorldSafeLocsEntry const* nearestLoc = nullptr;

        if (linked)
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

    static bool HandleDebugInstanceSpawns(ChatHandler* handler, Variant<uint32, EXACT_SEQUENCE("explain")> optArg)
    {
        Player const* const player = handler->GetPlayer();
        if (!player)
            return false;

        bool explain = false;
        uint32 groupID = 0;
        if (optArg.holds_alternative<uint32>())
            groupID = optArg.get<uint32>();
        else
            explain = true;

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
                handler->PSendSysMessage(" |-- '%s' (%u)", groupData->name.c_str(), pair.first);
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
                                handler->PSendSysMessage(" | |-- '%s' would be allowed to spawn by boss state %u being %s, but this is overruled", groupData->name.c_str(), bossStateId, InstanceScript::GetBossStateName(actualState));
                            else
                                handler->PSendSysMessage(" | |-- '%s' is allowed to spawn because boss state %u is %s.", groupData->name.c_str(), bossStateId, InstanceScript::GetBossStateName(bossStateId));
                        }
                        else
                        {
                            isBlocked = true;
                            handler->PSendSysMessage(" | |-- '%s' is blocked from spawning because boss state %u is %s.", groupData->name.c_str(), bossStateId, InstanceScript::GetBossStateName(bossStateId));
                        }
                    }
                    else
                        handler->PSendSysMessage(" | |-- '%s' could've been %s if boss state %u matched mask 0x%02x; but it is %s -> 0x%02x, which does not match.",
                            groupData->name.c_str(), isSpawn ? "allowed to spawn" : "blocked from spawning", bossStateId, std::get<2>(tuple), InstanceScript::GetBossStateName(actualState), (1 << actualState));
                }
                if (isBlocked)
                    handler->PSendSysMessage(" | |=> '%s' is not active due to a blocking rule being matched", groupData->name.c_str());
                else if (isSpawned)
                    handler->PSendSysMessage(" | |=> '%s' is active due to a spawn rule being matched", groupData->name.c_str());
                else
                    handler->PSendSysMessage(" | |=> '%s' is not active due to none of its rules being matched", groupData->name.c_str());
            }
            else
                handler->PSendSysMessage(" - '%s' (%u) is %sactive", groupData->name.c_str(), pair.first, map->IsSpawnGroupActive(pair.first) ? "" : "not ");
        }
        return true;
    }

    static bool HandleDebugConversationCommand(ChatHandler* handler, uint32 conversationEntry)
    {
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return Conversation::CreateConversation(conversationEntry, target, *target, target->GetGUID()) != nullptr;
    }

    static bool HandleDebugWSExpressionCommand(ChatHandler* handler, uint32 expressionId)
    {
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

        if (ConditionMgr::IsMeetingWorldStateExpression(target->GetMap(), wsExpressionEntry))
            handler->PSendSysMessage("Expression %u meet", expressionId);
        else
            handler->PSendSysMessage("Expression %u not meet", expressionId);

        return true;
    }

    static bool HandleDebugPlayerConditionCommand(ChatHandler* handler, uint32 playerConditionId)
    {
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (ConditionMgr::IsPlayerMeetingCondition(target, playerConditionId))
            handler->PSendSysMessage("PlayerCondition %u met", playerConditionId);
        else
            handler->PSendSysMessage("PlayerCondition %u not met", playerConditionId);

        return true;
    }

    static bool HandleDebugOutOfBounds([[maybe_unused]] ChatHandler* handler)
    {
#ifdef ASAN
        uint8 stack_array[10] = {};
        int size = 10;

        handler->PSendSysMessage("Triggered an array out of bounds read at address %p, value %u", static_cast<void*>(stack_array + size), stack_array[size]);
#endif
        return true;
    }

    static bool HandleDebugMemoryLeak([[maybe_unused]] ChatHandler* handler)
    {
#ifdef ASAN
        uint8* leak = new uint8();
        handler->PSendSysMessage("Leaked 1 uint8 object at address %p", static_cast<void*>(leak));
#endif
        return true;
    }

    static bool HandleDebugWardenForce(ChatHandler* handler, std::vector<uint16> checkIds)
    {
        if (checkIds.empty())
            return false;

        Warden* const warden = handler->GetSession()->GetWarden();
        if (!warden)
        {
            handler->SendSysMessage("Warden system is not enabled");
            return true;
        }

        size_t const nQueued = warden->DEBUG_ForceSpecificChecks(checkIds);
        handler->PSendSysMessage("%zu/%zu checks queued for your Warden, they should be sent over the next few minutes (depending on settings)", nQueued, checkIds.size());
        return true;
    }

    static bool HandleDebugGuidLimitsCommand(ChatHandler* handler, Optional<uint32> mapId)
    {
        if (mapId)
        {
            sMapMgr->DoForAllMapsWithMapId(mapId.value(),
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

    static bool HandleDebugObjectCountCommand(ChatHandler* handler, Optional<uint32> mapId)
    {
        if (mapId)
        {
            sMapMgr->DoForAllMapsWithMapId(mapId.value(),
                [handler](Map* map) -> void
                {
                    HandleDebugObjectCountMap(handler, map);
                }
            );
        }
        else
        {
            sMapMgr->DoForAllMaps(
                [handler](Map* map) -> void
                {
                    HandleDebugObjectCountMap(handler, map);
                }
            );
        }

        return true;
    }

    class CreatureCountWorker
    {
    public:
        CreatureCountWorker() { }

        void Visit(std::unordered_map<ObjectGuid, Creature*>& creatureMap)
        {
            for (auto const& p : creatureMap)
            {
                uint32& count = creatureIds[p.second->GetEntry()];
                ++count;
            }
        }

        template<class T>
        void Visit(std::unordered_map<ObjectGuid, T*>&) { }

        std::vector<std::pair<uint32, uint32>> GetTopCreatureCount(uint32 count)
        {
            auto comp = [](std::pair<uint32, uint32> const& a, std::pair<uint32, uint32> const& b)
            {
                return a.second > b.second;
            };
            std::set<std::pair<uint32, uint32>, decltype(comp)> set(creatureIds.begin(), creatureIds.end(), comp);

            count = std::min(count, uint32(set.size()));
            std::vector<std::pair<uint32, uint32>> result(count);
            std::copy_n(set.begin(), count, result.begin());

            return result;
        }

    private:
        std::unordered_map<uint32, uint32> creatureIds;
    };

    static void HandleDebugObjectCountMap(ChatHandler* handler, Map* map)
    {
        handler->PSendSysMessage("Map Id: %u Name: '%s' Instance Id: %u Creatures: " UI64FMTD " GameObjects: " UI64FMTD " SetActive Objects: " UI64FMTD,
            map->GetId(), map->GetMapName(), map->GetInstanceId(),
            uint64(map->GetObjectsStore().Size<Creature>()),
            uint64(map->GetObjectsStore().Size<GameObject>()),
            uint64(map->GetActiveNonPlayersCount()));

        CreatureCountWorker worker;
        TypeContainerVisitor<CreatureCountWorker, MapStoredObjectTypesContainer> visitor(worker);
        visitor.Visit(map->GetObjectsStore());

        handler->PSendSysMessage("Top Creatures count:");

        for (auto&& p : worker.GetTopCreatureCount(5))
            handler->PSendSysMessage("Entry: %u Count: %u", p.first, p.second);
    }

    static bool HandleDebugBecomePersonalClone(ChatHandler* handler)
    {
        Creature* selection = handler->getSelectedCreature();
        if (!selection)
            return false;

        Player* player = handler->GetSession()->GetPlayer();
        selection->SummonPersonalClone(player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        return true;
    }

    static bool HandleDebugDummyCommand(ChatHandler* handler)
    {
        handler->SendSysMessage("This command does nothing right now. Edit your local core (cs_debug.cpp) to make it do whatever you need for testing.");
        return true;
    }
};

void AddSC_debug_commandscript()
{
    new debug_commandscript();
}
