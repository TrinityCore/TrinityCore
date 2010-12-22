/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Common.h"
#include "ObjectMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"

#include "AccountMgr.h"
#include "CellImpl.h"
#include "Chat.h"
#include "GridNotifiersImpl.h"
#include "Language.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "UpdateMask.h"
#include "SpellMgr.h"
#include "ScriptMgr.h"

// Supported shift-links (client generated and server side)
// |color|Hachievement:achievement_id:player_guid:0:0:0:0:0:0:0:0|h[name]|h|r
//                                                                        - client, item icon shift click, not used in server currently
// |color|Harea:area_id|h[name]|h|r
// |color|Hcreature:creature_guid|h[name]|h|r
// |color|Hcreature_entry:creature_id|h[name]|h|r
// |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r          - client, at shift click in recipes list dialog
// |color|Hgameevent:id|h[name]|h|r
// |color|Hgameobject:go_guid|h[name]|h|r
// |color|Hgameobject_entry:go_id|h[name]|h|r
// |color|Hglyph:glyph_slot_id:glyph_prop_id|h[%s]|h|r                    - client, at shift click in glyphs dialog, GlyphSlot.dbc, GlyphProperties.dbc
// |color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:0:0:0:reporter_level|h[name]|h|r
//                                                                        - client, item icon shift click
// |color|Hitemset:itemset_id|h[name]|h|r
// |color|Hplayer:name|h[name]|h|r                                        - client, in some messages, at click copy only name instead link
// |color|Hquest:quest_id:quest_level|h[name]|h|r                         - client, quest list name shift-click
// |color|Hskill:skill_id|h[name]|h|r
// |color|Hspell:spell_id|h[name]|h|r                                     - client, spellbook spell icon shift-click
// |color|Htalent:talent_id,rank|h[name]|h|r                              - client, talent icon shift-click
// |color|Htaxinode:id|h[name]|h|r
// |color|Htele:id|h[name]|h|r
// |color|Htitle:id|h[name]|h|r
// |color|Htrade:spell_id,cur_value,max_value,unk3int,unk3str|h[name]|h|r - client, spellbook profession icon shift-click

bool ChatHandler::load_command_table = true;

// wrapper for old-style handlers
template<bool (ChatHandler::*F)(const char*)>
bool OldHandler(ChatHandler* chatHandler, const char* args)
{
    return (chatHandler->*F)(args);
}

// get number of commands in table
static size_t getCommandTableSize(const ChatCommand* commands)
{
    if (!commands)
        return 0;
    size_t count = 0;
    while (commands[count].Name != NULL)
        count++;
    return count;
}

// append source command table to target, return number of appended commands
static size_t appendCommandTable(ChatCommand* target, const ChatCommand* source)
{
    const size_t count = getCommandTableSize(source);
    if (count)
        memcpy(target, source, count * sizeof(ChatCommand));
    return count;
}

ChatCommand * ChatHandler::getCommandTable()
{
    static ChatCommand banCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanAccountCommand>,          "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanCharacterCommand>,        "", NULL },
        { "playeraccount",  SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanAccountByCharCommand>,    "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanIPCommand>,               "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand baninfoCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanInfoAccountCommand>,      "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanInfoCharacterCommand>,    "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanInfoIPCommand>,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand banlistCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanListAccountCommand>,      "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanListCharacterCommand>,    "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleBanListIPCommand>,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand castCommandTable[] =
    {
        { "back",           SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleCastBackCommand>,            "", NULL },
        { "dist",           SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleCastDistCommand>,            "", NULL },
        { "self",           SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleCastSelfCommand>,            "", NULL },
        { "target",         SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleCastTargetCommand>,          "", NULL },
        { "",               SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleCastCommand>,                "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand characterDeletedCommandTable[] =
    {
        { "delete",         SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleCharacterDeletedDeleteCommand>,   "", NULL },
        { "list",           SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleCharacterDeletedListCommand>,     "", NULL },
        { "restore",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleCharacterDeletedRestoreCommand>,  "", NULL },
        { "old",            SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleCharacterDeletedOldCommand>,      "", NULL },
        { NULL,             0,                  false, NULL,                                                "", NULL }
    };

    static ChatCommand characterCommandTable[] =
    {
        { "customize",      SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleCharacterCustomizeCommand>,     "", NULL },
        { "changefaction",  SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleCharacterChangeFactionCommand>, "", NULL },
        { "changerace",     SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleCharacterChangeRaceCommand>,    "", NULL },
        { "deleted",        SEC_GAMEMASTER,     true,  NULL,                                              "", characterDeletedCommandTable},
        { "erase",          SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleCharacterEraseCommand>,         "", NULL },
        { "level",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleCharacterLevelCommand>,         "", NULL },
        { "rename",         SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleCharacterRenameCommand>,        "", NULL },
        { "reputation",     SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleCharacterReputationCommand>,    "", NULL },
        { "titles",         SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleCharacterTitlesCommand>,        "", NULL },
        { NULL,             0,                  false, NULL,                                              "", NULL }
    };

    static ChatCommand channelSetCommandTable[] =
    {
        { "ownership",      SEC_ADMINISTRATOR,  false,  OldHandler<&ChatHandler::HandleChannelSetOwnership>, "", NULL },
        { NULL,             0,                  false, NULL,                                                "", NULL }
    };

    static ChatCommand channelCommandTable[] =
    {
        { "set",      SEC_ADMINISTRATOR,     true,  NULL,  "", channelSetCommandTable },
        { NULL,       0,                     false, NULL,  "", NULL                   }
    };

    static ChatCommand groupCommandTable[] =
    {
        { "leader",         SEC_ADMINISTRATOR,     false,  OldHandler<&ChatHandler::HandleGroupLeaderCommand>,         "", NULL },
        { "disband",        SEC_ADMINISTRATOR,     false,  OldHandler<&ChatHandler::HandleGroupDisbandCommand>,        "", NULL },
        { "remove",         SEC_ADMINISTRATOR,     false,  OldHandler<&ChatHandler::HandleGroupRemoveCommand>,         "", NULL },
        { NULL,             0,                     false, NULL,                                           "", NULL }
    };

    static ChatCommand guildCommandTable[] =
    {
        { "create",         SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleGuildCreateCommand>,         "", NULL },
        { "delete",         SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleGuildDeleteCommand>,         "", NULL },
        { "invite",         SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleGuildInviteCommand>,         "", NULL },
        { "uninvite",       SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleGuildUninviteCommand>,       "", NULL },
        { "rank",           SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleGuildRankCommand>,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand instanceCommandTable[] =
    {
        { "listbinds",      SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleInstanceListBindsCommand>,   "", NULL },
        { "unbind",         SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleInstanceUnbindCommand>,      "", NULL },
        { "stats",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleInstanceStatsCommand>,       "", NULL },
        { "savedata",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleInstanceSaveDataCommand>,    "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand listCommandTable[] =
    {
        { "creature",       SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleListCreatureCommand>,        "", NULL },
        { "item",           SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleListItemCommand>,            "", NULL },
        { "object",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleListObjectCommand>,          "", NULL },
        { "auras",          SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleListAurasCommand>,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand lookupPlayerCommandTable[] =
    {
        { "ip",             SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleLookupPlayerIpCommand>,       "", NULL },
        { "account",        SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleLookupPlayerAccountCommand>,  "", NULL },
        { "email",          SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleLookupPlayerEmailCommand>,    "", NULL },
        { NULL,             0,                  false, NULL,                                            "", NULL }
    };

    static ChatCommand lookupCommandTable[] =
    {
        { "area",           SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleLookupAreaCommand>,          "", NULL },
        { "creature",       SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupCreatureCommand>,      "", NULL },
        { "event",          SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleLookupEventCommand>,         "", NULL },
        { "faction",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupFactionCommand>,       "", NULL },
        { "item",           SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupItemCommand>,          "", NULL },
        { "itemset",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupItemSetCommand>,       "", NULL },
        { "object",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupObjectCommand>,        "", NULL },
        { "quest",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupQuestCommand>,         "", NULL },
        { "player",         SEC_GAMEMASTER,     true,  NULL,                                           "", lookupPlayerCommandTable },
        { "skill",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupSkillCommand>,         "", NULL },
        { "spell",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupSpellCommand>,         "", NULL },
        { "taxinode",       SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupTaxiNodeCommand>,      "", NULL },
        { "tele",           SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleLookupTeleCommand>,          "", NULL },
        { "title",          SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleLookupTitleCommand>,         "", NULL },
        { "map",            SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleLookupMapCommand>,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand petCommandTable[] =
    {
        { "create",         SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleCreatePetCommand>,           "", NULL },
        { "learn",          SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandlePetLearnCommand>,            "", NULL },
        { "unlearn",        SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandlePetUnlearnCommand>,          "", NULL },
        { "tp",             SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandlePetTpCommand>,               "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand pdumpCommandTable[] =
    {
        { "load",           SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandlePDumpLoadCommand>,           "", NULL },
        { "write",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandlePDumpWriteCommand>,          "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand resetCommandTable[] =
    {
        { "achievements",   SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetAchievementsCommand>,   "", NULL },
        { "honor",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetHonorCommand>,          "", NULL },
        { "level",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetLevelCommand>,          "", NULL },
        { "spells",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetSpellsCommand>,         "", NULL },
        { "stats",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetStatsCommand>,          "", NULL },
        { "talents",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetTalentsCommand>,        "", NULL },
        { "all",            SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleResetAllCommand>,            "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand sendCommandTable[] =
    {
        { "items",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleSendItemsCommand>,           "", NULL },
        { "mail",           SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleSendMailCommand>,            "", NULL },
        { "message",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleSendMessageCommand>,         "", NULL },
        { "money",          SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleSendMoneyCommand>,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverIdleRestartCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerShutDownCancelCommand>,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerIdleRestartCommand>,   "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverIdleShutdownCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerShutDownCancelCommand>,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerIdleShutDownCommand>,  "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverRestartCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerShutDownCancelCommand>,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerRestartCommand>,       "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverShutdownCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerShutDownCancelCommand>,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerShutDownCommand>,      "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverSetCommandTable[] =
    {
        { "difftime",       SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleServerSetDiffTimeCommand>,   "", NULL },
        { "loglevel",       SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleServerSetLogLevelCommand>,   "", NULL },
        { "logfilelevel",   SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleServerSetLogFileLevelCommand>,   "", NULL },
        { "motd",           SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerSetMotdCommand>,       "", NULL },
        { "closed",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerSetClosedCommand>,     "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverCommandTable[] =
    {
        { "corpses",        SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleServerCorpsesCommand>,     "", NULL },
        { "exit",           SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleServerExitCommand>,        "", NULL },
        { "idlerestart",    SEC_ADMINISTRATOR,  true,  NULL,                                                     "", serverIdleRestartCommandTable },
        { "idleshutdown",   SEC_ADMINISTRATOR,  true,  NULL,                                                     "", serverShutdownCommandTable },
        { "info",           SEC_PLAYER,         true,  OldHandler<&ChatHandler::HandleServerInfoCommand>,        "", NULL },
        { "motd",           SEC_PLAYER,         true,  OldHandler<&ChatHandler::HandleServerMotdCommand>,        "", NULL },
        { "plimit",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleServerPLimitCommand>,      "", NULL },
        { "restart",        SEC_ADMINISTRATOR,  true,  NULL,                                                     "", serverRestartCommandTable },
        { "shutdown",       SEC_ADMINISTRATOR,  true,  NULL,                                                     "", serverShutdownCommandTable },
        { "set",            SEC_ADMINISTRATOR,  true,  NULL,                                                     "", serverSetCommandTable },
        { "togglequerylog", SEC_CONSOLE,        true,  OldHandler<&ChatHandler::HandleServerToggleQueryLogging>, "", NULL },
        { NULL,             0,                  false, NULL,                                                     "", NULL }
    };

    static ChatCommand unbanCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleUnBanAccountCommand>,       "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleUnBanCharacterCommand>,     "", NULL },
        { "playeraccount",  SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleUnBanAccountByCharCommand>, "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleUnBanIPCommand>,            "", NULL },
        { NULL,             0,                  false, NULL,                                          "", NULL }
    };

    static ChatCommand ticketResponseCommandTable[] =
    {
        { "append",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketResponseAppendCommand>,   "", NULL },
        { "appendln",       SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketResponseAppendLnCommand>, "", NULL },
        { NULL,             0,                  false, NULL,                                                "", NULL }
    };

    static ChatCommand ticketCommandTable[] =
    {
        { "list",           SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketListCommand>,             "", NULL },
        { "onlinelist",     SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketListOnlineCommand>,       "", NULL },
        { "viewname",       SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketGetByNameCommand>,        "", NULL },
        { "viewid",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketGetByIdCommand>,          "", NULL },
        { "close",          SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketCloseByIdCommand>,        "", NULL },
        { "closedlist",     SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketListClosedCommand>,       "", NULL },
        { "escalatedlist",  SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleGMTicketListEscalatedCommand>,    "", NULL },
        { "delete",         SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleGMTicketDeleteByIdCommand>,       "", NULL },
        { "assign",         SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleGMTicketAssignToCommand>,         "", NULL },
        { "unassign",       SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleGMTicketUnAssignCommand>,         "", NULL },
        { "comment",        SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketCommentCommand>,          "", NULL },
        { "togglesystem",   SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleToggleGMTicketSystem>,            "", NULL },
        { "escalate",       SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketEscalateCommand>,         "", NULL },
        { "response",       SEC_MODERATOR,      false, NULL,                                                "", ticketResponseCommandTable },
        { "complete",       SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMTicketCompleteCommand>,         "", NULL },
        { NULL,             0,                  false, NULL,                                                "", NULL }
    };

    static ChatCommand commandTable[] =
    {
        { "character",      SEC_GAMEMASTER,     true,  NULL,                                           "", characterCommandTable},
        { "list",           SEC_ADMINISTRATOR,  true,  NULL,                                           "", listCommandTable     },
        { "lookup",         SEC_ADMINISTRATOR,  true,  NULL,                                           "", lookupCommandTable   },
        { "pdump",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", pdumpCommandTable    },
        { "guild",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", guildCommandTable    },
        { "cast",           SEC_ADMINISTRATOR,  false, NULL,                                           "", castCommandTable     },
        { "reset",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", resetCommandTable    },
        { "instance",       SEC_ADMINISTRATOR,  true,  NULL,                                           "", instanceCommandTable },
        { "server",         SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverCommandTable   },

        { "channel",        SEC_ADMINISTRATOR, true, NULL,                                             "", channelCommandTable  },

        { "pet",            SEC_GAMEMASTER,     false, NULL,                                           "", petCommandTable },
        { "ticket",         SEC_MODERATOR,      false,  NULL,                                          "", ticketCommandTable },

        { "aura",           SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleAuraCommand>,                "", NULL },
        { "unaura",         SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleUnAuraCommand>,              "", NULL },
        { "nameannounce",   SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleNameAnnounceCommand>,        "", NULL },
        { "gmnameannounce", SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGMNameAnnounceCommand>,      "", NULL },
        { "announce",       SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleAnnounceCommand>,            "", NULL },
        { "gmannounce",     SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleGMAnnounceCommand>,          "", NULL },
        { "notify",         SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleNotifyCommand>,              "", NULL },
        { "gmnotify",       SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleGMNotifyCommand>,            "", NULL },
        { "appear",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleAppearCommand>,              "", NULL },
        { "summon",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleSummonCommand>,              "", NULL },
        { "groupsummon",    SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGroupSummonCommand>,         "", NULL },
        { "commands",       SEC_PLAYER,         true,  OldHandler<&ChatHandler::HandleCommandsCommand>,            "", NULL },
        { "demorph",        SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleDeMorphCommand>,             "", NULL },
        { "die",            SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleDieCommand>,                 "", NULL },
        { "revive",         SEC_ADMINISTRATOR,  true,  OldHandler<&ChatHandler::HandleReviveCommand>,              "", NULL },
        { "dismount",       SEC_PLAYER,         false, OldHandler<&ChatHandler::HandleDismountCommand>,            "", NULL },
        { "gps",            SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleGPSCommand>,                 "", NULL },
        { "guid",           SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleGUIDCommand>,                "", NULL },
        { "help",           SEC_PLAYER,         true,  OldHandler<&ChatHandler::HandleHelpCommand>,                "", NULL },
        { "itemmove",       SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleItemMoveCommand>,            "", NULL },
        { "cooldown",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleCooldownCommand>,            "", NULL },
        { "unlearn",        SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleUnLearnCommand>,             "", NULL },
        { "distance",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleGetDistanceCommand>,         "", NULL },
        { "recall",         SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleRecallCommand>,              "", NULL },
        { "save",           SEC_PLAYER,         false, OldHandler<&ChatHandler::HandleSaveCommand>,                "", NULL },
        { "saveall",        SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleSaveAllCommand>,             "", NULL },
        { "kick",           SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleKickPlayerCommand>,          "", NULL },
        { "ban",            SEC_ADMINISTRATOR,  true,  NULL,                                           "", banCommandTable      },
        { "unban",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", unbanCommandTable    },
        { "baninfo",        SEC_ADMINISTRATOR,  false, NULL,                                           "", baninfoCommandTable  },
        { "banlist",        SEC_ADMINISTRATOR,  true,  NULL,                                           "", banlistCommandTable  },
        { "start",          SEC_PLAYER,         false, OldHandler<&ChatHandler::HandleStartCommand>,               "", NULL },
        { "taxicheat",      SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleTaxiCheatCommand>,           "", NULL },
        { "linkgrave",      SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleLinkGraveCommand>,           "", NULL },
        { "neargrave",      SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleNearGraveCommand>,           "", NULL },
        { "explorecheat",   SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleExploreCheatCommand>,        "", NULL },
        { "hover",          SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleHoverCommand>,               "", NULL },
        { "levelup",        SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleLevelUpCommand>,             "", NULL },
        { "showarea",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleShowAreaCommand>,            "", NULL },
        { "hidearea",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleHideAreaCommand>,            "", NULL },
        { "additem",        SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleAddItemCommand>,             "", NULL },
        { "additemset",     SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleAddItemSetCommand>,          "", NULL },
        { "bank",           SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleBankCommand>,                "", NULL },
        { "wchange",        SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleChangeWeather>,              "", NULL },
        { "maxskill",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleMaxSkillCommand>,            "", NULL },
        { "setskill",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleSetSkillCommand>,            "", NULL },
        { "whispers",       SEC_MODERATOR,      false, OldHandler<&ChatHandler::HandleWhispersCommand>,            "", NULL },
        { "pinfo",          SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandlePInfoCommand>,               "", NULL },
        { "respawn",        SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleRespawnCommand>,             "", NULL },
        { "send",           SEC_MODERATOR,      true,  NULL,                                           "", sendCommandTable     },
        { "mute",           SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleMuteCommand>,                "", NULL },
        { "unmute",         SEC_MODERATOR,      true,  OldHandler<&ChatHandler::HandleUnmuteCommand>,              "", NULL },
        { "movegens",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleMovegensCommand>,            "", NULL },
        { "cometome",       SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleComeToMeCommand>,            "", NULL },
        { "damage",         SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleDamageCommand>,              "", NULL },
        { "combatstop",     SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleCombatStopCommand>,          "", NULL },
        { "flusharenapoints",SEC_ADMINISTRATOR, false, OldHandler<&ChatHandler::HandleFlushArenaPointsCommand>,    "", NULL },
        { "repairitems",    SEC_GAMEMASTER,     true,  OldHandler<&ChatHandler::HandleRepairitemsCommand>,         "", NULL },
        { "waterwalk",      SEC_GAMEMASTER,     false, OldHandler<&ChatHandler::HandleWaterwalkCommand>,           "", NULL },

        { "freeze",         SEC_MODERATOR,  false, OldHandler<&ChatHandler::HandleFreezeCommand>,              "", NULL },
        { "unfreeze",       SEC_MODERATOR,  false, OldHandler<&ChatHandler::HandleUnFreezeCommand>,            "", NULL },
        { "listfreeze",     SEC_MODERATOR,  false, OldHandler<&ChatHandler::HandleListFreezeCommand>,          "", NULL },

        { "possess",        SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandlePossessCommand>,             "", NULL },
        { "unpossess",      SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleUnPossessCommand>,           "", NULL },
        { "bindsight",      SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleBindSightCommand>,           "", NULL },
        { "unbindsight",    SEC_ADMINISTRATOR,  false, OldHandler<&ChatHandler::HandleUnbindSightCommand>,         "", NULL },
        { "playall",        SEC_GAMEMASTER,  false, OldHandler<&ChatHandler::HandlePlayAllCommand>,             "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    // cache for commands, needed because some commands are loaded dynamically through ScriptMgr
    // cache is never freed and will show as a memory leak in diagnostic tools
    // can't use vector as vector storage is implementation-dependent, eg, there can be alignment gaps between elements
    static ChatCommand* commandTableCache = 0;

    if (LoadCommandTable())
    {
        SetLoadCommandTable(false);

        {
            // count total number of top-level commands
            size_t total = getCommandTableSize(commandTable);
            std::vector<ChatCommand*> const& dynamic = sScriptMgr->GetChatCommands();
            for (std::vector<ChatCommand*>::const_iterator it = dynamic.begin(); it != dynamic.end(); ++it)
                total += getCommandTableSize(*it);
            total += 1; // ending zero

            // cache top-level commands
            commandTableCache = (ChatCommand*)malloc(sizeof(ChatCommand) * total);
            memset(commandTableCache, 0, sizeof(ChatCommand) * total);
            ACE_ASSERT(commandTableCache);
            size_t added = appendCommandTable(commandTableCache, commandTable);
            for (std::vector<ChatCommand*>::const_iterator it = dynamic.begin(); it != dynamic.end(); ++it)
                added += appendCommandTable(commandTableCache + added, *it);
        }

        QueryResult result = WorldDatabase.Query("SELECT name,security,help FROM command");
        if (result)
        {
            do
            {
                Field *fields = result->Fetch();
                std::string name = fields[0].GetString();

                SetDataForCommandInTable(commandTableCache, name.c_str(), fields[1].GetUInt16(), fields[2].GetString(), name);

            } while (result->NextRow());
        }
    }

    return commandTableCache;
}

const char *ChatHandler::GetTrinityString(int32 entry) const
{
    return m_session->GetTrinityString(entry);
}

bool ChatHandler::isAvailable(ChatCommand const& cmd) const
{
    // check security level only for simple  command (without child commands)
    return m_session->GetSecurity() >= AccountTypes(cmd.SecurityLevel);
}

bool ChatHandler::HasLowerSecurity(Player* target, uint64 guid, bool strong)
{
    WorldSession* target_session = NULL;
    uint32 target_account = 0;

    if (target)
        target_session = target->GetSession();
    else if (guid)
        target_account = sObjectMgr->GetPlayerAccountIdByGUID(guid);

    if (!target_session && !target_account)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return true;
    }

    return HasLowerSecurityAccount(target_session,target_account,strong);
}

bool ChatHandler::HasLowerSecurityAccount(WorldSession* target, uint32 target_account, bool strong)
{
    uint32 target_sec;

    // allow everything from console and RA console
    if (!m_session)
        return false;

    // ignore only for non-players for non strong checks (when allow apply command at least to same sec level)
    if (m_session->GetSecurity() > SEC_PLAYER && !strong && !sWorld.getBoolConfig(CONFIG_GM_LOWER_SECURITY))
        return false;

    if (target)
        target_sec = target->GetSecurity();
    else if (target_account)
        target_sec = sAccountMgr->GetSecurity(target_account);
    else
        return true;                                        // caller must report error for (target == NULL && target_account == 0)

    AccountTypes target_ac_sec = AccountTypes(target_sec);
    if (m_session->GetSecurity() < target_ac_sec || (strong && m_session->GetSecurity() <= target_ac_sec))
    {
        SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
        SetSentErrorMessage(true);
        return true;
    }

    return false;
}

bool ChatHandler::hasStringAbbr(const char* name, const char* part)
{
    // non "" command
    if (*name)
    {
        // "" part from non-"" command
        if (!*part)
            return false;

        for (;;)
        {
            if (!*part)
                return true;
            else if (!*name)
                return false;
            else if (tolower(*name) != tolower(*part))
                return false;
            ++name; ++part;
        }
    }
    // allow with any for ""

    return true;
}

void ChatHandler::SendSysMessage(const char *str)
{
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        FillSystemMessageData(&data, line);
        m_session->SendPacket(&data);
    }

    free(buf);
}

void ChatHandler::SendGlobalSysMessage(const char *str)
{
    // Chat output
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        FillSystemMessageData(&data, line);
        sWorld.SendGlobalMessage(&data);
    }

    free(buf);
}

void ChatHandler::SendGlobalGMSysMessage(const char *str)
{
    // Chat output
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        FillSystemMessageData(&data, line);
        sWorld.SendGlobalGMMessage(&data);
     }
    free(buf);
}

void ChatHandler::SendSysMessage(int32 entry)
{
    SendSysMessage(GetTrinityString(entry));
}

void ChatHandler::PSendSysMessage(int32 entry, ...)
{
    const char *format = GetTrinityString(entry);
    va_list ap;
    char str [2048];
    va_start(ap, entry);
    vsnprintf(str,2048,format, ap);
    va_end(ap);
    SendSysMessage(str);
}

void ChatHandler::PSendSysMessage(const char *format, ...)
{
    va_list ap;
    char str [2048];
    va_start(ap, format);
    vsnprintf(str,2048,format, ap);
    va_end(ap);
    SendSysMessage(str);
}

bool ChatHandler::ExecuteCommandInTable(ChatCommand *table, const char* text, const std::string& fullcmd)
{
    char const* oldtext = text;
    std::string cmd = "";

    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        ++text;
    }

    while (*text == ' ') ++text;

    for (uint32 i = 0; table[i].Name != NULL; ++i)
    {
        if (!hasStringAbbr(table[i].Name, cmd.c_str()))
            continue;

        bool match = false;
        if (strlen(table[i].Name) > strlen(cmd.c_str()))
        {
            for (uint32 j = 0; table[j].Name != NULL; ++j)
            {
                if (!hasStringAbbr(table[j].Name, cmd.c_str()))
                    continue;

                if (strcmp(table[j].Name,cmd.c_str()) != 0)
                    continue;
                else
                {
                    match = true;
                    break;
                }
            }
        }
        if (match)
            continue;

        // select subcommand from child commands list
        if (table[i].ChildCommands != NULL)
        {
            if (!ExecuteCommandInTable(table[i].ChildCommands, text, fullcmd))
            {
                if (text && text[0] != '\0')
                    SendSysMessage(LANG_NO_SUBCMD);
                else
                    SendSysMessage(LANG_CMD_SYNTAX);

                ShowHelpForCommand(table[i].ChildCommands,text);
            }

            return true;
        }

        // must be available and have handler
        if (!table[i].Handler || !isAvailable(table[i]))
            continue;

        SetSentErrorMessage(false);
        // table[i].Name == "" is special case: send original command to handler
        if ((table[i].Handler)(this, strlen(table[i].Name) != 0 ? text : oldtext))
        {
            if (table[i].SecurityLevel > SEC_PLAYER)
            {
                // chat case
                if (m_session)
                {
                    Player* p = m_session->GetPlayer();
                    uint64 sel_guid = p->GetSelection();
                    sLog.outCommand(m_session->GetAccountId(),"Command: %s [Player: %s (Account: %u) X: %f Y: %f Z: %f Map: %u Selected %s: %s (GUID: %u)]",
                        fullcmd.c_str(),p->GetName(),m_session->GetAccountId(),p->GetPositionX(),p->GetPositionY(),p->GetPositionZ(),p->GetMapId(),
                        GetLogNameForGuid(sel_guid), (p->GetSelectedUnit()) ? p->GetSelectedUnit()->GetName() : "", GUID_LOPART(sel_guid));
                }
            }
        }
        // some commands have custom error messages. Don't send the default one in these cases.
        else if (!HasSentErrorMessage())
        {
            if (!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());
            else
                SendSysMessage(LANG_CMD_SYNTAX);
        }

        return true;
    }

    return false;
}

bool ChatHandler::SetDataForCommandInTable(ChatCommand *table, const char* text, uint32 security, std::string const& help, std::string const& fullcommand)
{
    std::string cmd = "";

    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        ++text;
    }

    while (*text == ' ') ++text;

    for (uint32 i = 0; table[i].Name != NULL; i++)
    {
        // for data fill use full explicit command names
        if (table[i].Name != cmd)
            continue;

        // select subcommand from child commands list (including "")
        if (table[i].ChildCommands != NULL)
        {
            if (SetDataForCommandInTable(table[i].ChildCommands, text, security, help, fullcommand))
                return true;
            else if (*text)
                return false;

            // fail with "" subcommands, then use normal level up command instead
        }
        // expected subcommand by full name DB content
        else if (*text)
        {
            sLog.outErrorDb("Table `command` have unexpected subcommand '%s' in command '%s', skip.",text,fullcommand.c_str());
            return false;
        }

        if (table[i].SecurityLevel != security)
            sLog.outDetail("Table `command` overwrite for command '%s' default security (%u) by %u",fullcommand.c_str(),table[i].SecurityLevel,security);

        table[i].SecurityLevel = security;
        table[i].Help          = help;
        return true;
    }

    // in case "" command let process by caller
    if (!cmd.empty())
    {
        if (table == getCommandTable())
            sLog.outErrorDb("Table `command` have not existed command '%s', skip.",cmd.c_str());
        else
            sLog.outErrorDb("Table `command` have not existed subcommand '%s' in command '%s', skip.",cmd.c_str(),fullcommand.c_str());
    }

    return false;
}

int ChatHandler::ParseCommands(const char* text)
{
    ASSERT(text);
    ASSERT(*text);

    std::string fullcmd = text;

    if (m_session && m_session->GetSecurity() <= SEC_PLAYER && sWorld.getBoolConfig(CONFIG_ALLOW_PLAYER_COMMANDS) == 0)
       return 0;

    /// chat case (.command or !command format)
    if (m_session)
    {
        if (text[0] != '!' && text[0] != '.')
            return 0;
    }

    /// ignore single . and ! in line
    if (strlen(text) < 2)
        return 0;
    // original `text` can't be used. It content destroyed in command code processing.

    /// ignore messages staring from many dots.
    if ((text[0] == '.' && text[1] == '.') || (text[0] == '!' && text[1] == '!'))
        return 0;

    /// skip first . or ! (in console allowed use command with . and ! and without its)
    if (text[0] == '!' || text[0] == '.')
        ++text;

    if (!ExecuteCommandInTable(getCommandTable(), text, fullcmd))
    {
        if (m_session && m_session->GetSecurity() == SEC_PLAYER)
            return 0;

        SendSysMessage(LANG_NO_CMD);
    }
    return 1;
}

bool ChatHandler::isValidChatMessage(const char* message)
{
/*

valid examples:
|cffa335ee|Hitem:812:0:0:0:0:0:0:0:70|h[Glowing Brightwood Staff]|h|r
|cff808080|Hquest:2278:47|h[The Platinum Discs]|h|r
|cffffd000|Htrade:4037:1:150:1:6AAAAAAAAAAAAAAAAAAAAAAOAADAAAAAAAAAAAAAAAAIAAAAAAAAA|h[Engineering]|h|r
|cff4e96f7|Htalent:2232:-1|h[Taste for Blood]|h|r
|cff71d5ff|Hspell:21563|h[Command]|h|r
|cffffd000|Henchant:3919|h[Engineering: Rough Dynamite]|h|r
|cffffff00|Hachievement:546:0000000000000001:0:0:0:-1:0:0:0:0|h[Safe Deposit]|h|r
|cff66bbff|Hglyph:21:762|h[Glyph of Bladestorm]|h|r

| will be escaped to ||
*/

    if (strlen(message) > 255)
        return false;

    const char validSequence[6] = "cHhhr";
    const char* validSequenceIterator = validSequence;

    // more simple checks
    if (sWorld.getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY) < 3)
    {
        const std::string validCommands = "cHhr|";

        while (*message)
        {
            // find next pipe command
            message = strchr(message, '|');

            if (!message)
                return true;

            ++message;
            char commandChar = *message;
            if (validCommands.find(commandChar) == std::string::npos)
                return false;

            ++message;
            // validate sequence
            if (sWorld.getIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY) == 2)
            {
                if (commandChar == *validSequenceIterator)
                {
                    if (validSequenceIterator == validSequence+4)
                        validSequenceIterator = validSequence;
                    else
                        ++validSequenceIterator;
                }
                else
                    return false;
            }
        }
        return true;
    }

    std::istringstream reader(message);
    char buffer[256];

    uint32 color = 0;

    ItemPrototype const* linkedItem = NULL;
    Quest const* linkedQuest = NULL;
    SpellEntry const *linkedSpell = NULL;
    AchievementEntry const* linkedAchievement = NULL;
    ItemRandomPropertiesEntry const* itemProperty = NULL;
    ItemRandomSuffixEntry const* itemSuffix = NULL;

    while (!reader.eof())
    {
        if (validSequence == validSequenceIterator)
        {
            linkedItem = NULL;
            linkedQuest = NULL;
            linkedSpell = NULL;
            linkedAchievement = NULL;
            itemProperty = NULL;
            itemSuffix = NULL;

            reader.ignore(255, '|');
        }
        else if (reader.get() != '|')
        {
#ifdef TRINITY_DEBUG
            sLog.outBasic("ChatHandler::isValidChatMessage sequence aborted unexpectedly");
#endif
            return false;
        }

        // pipe has always to be followed by at least one char
        if (reader.peek() == '\0')
        {
#ifdef TRINITY_DEBUG
            sLog.outBasic("ChatHandler::isValidChatMessage pipe followed by \\0");
#endif
            return false;
        }

        // no further pipe commands
        if (reader.eof())
            break;

        char commandChar;
        reader >> commandChar;

        // | in normal messages is escaped by ||
        if (commandChar != '|')
        {
            if (commandChar == *validSequenceIterator)
            {
                if (validSequenceIterator == validSequence+4)
                    validSequenceIterator = validSequence;
                else
                    ++validSequenceIterator;
            }
            else
            {
#ifdef TRINITY_DEBUG
                sLog.outBasic("ChatHandler::isValidChatMessage invalid sequence, expected %c but got %c", *validSequenceIterator, commandChar);
#endif
                return false;
            }
        }
        else if (validSequence != validSequenceIterator)
        {
            // no escaped pipes in sequences
#ifdef TRINITY_DEBUG
            sLog.outBasic("ChatHandler::isValidChatMessage got escaped pipe in sequence");
#endif
            return false;
        }

        switch (commandChar)
        {
            case 'c':
                color = 0;
                // validate color, expect 8 hex chars
                for (int i=0; i<8; i++)
                {
                    char c;
                    reader >> c;
                    if (!c)
                    {
#ifdef TRINITY_DEBUG
                        sLog.outBasic("ChatHandler::isValidChatMessage got \\0 while reading color in |c command");
#endif
                        return false;
                    }

                    color <<= 4;
                    // check for hex char
                    if (c >= '0' && c <= '9')
                    {
                        color |= c-'0';
                        continue;
                    }
                    if (c >= 'a' && c <= 'f')
                    {
                        color |= 10+c-'a';
                        continue;
                    }
#ifdef TRINITY_DEBUG
                    sLog.outBasic("ChatHandler::isValidChatMessage got non hex char '%c' while reading color", c);
#endif
                    return false;
                }
                break;
            case 'H':
                // read chars up to colon  = link type
                reader.getline(buffer, 256, ':');

                if (strcmp(buffer, "item") == 0)
                {
                    // read item entry
                    reader.getline(buffer, 256, ':');

                    linkedItem= ObjectMgr::GetItemPrototype(atoi(buffer));
                    if (!linkedItem)
                    {
#ifdef TRINITY_DEBUG
                        sLog.outBasic("ChatHandler::isValidChatMessage got invalid itemID %u in |item command", atoi(buffer));
#endif
                        return false;
                    }

                    if (color != ItemQualityColors[linkedItem->Quality])
                    {
#ifdef TRINITY_DEBUG
                        sLog.outBasic("ChatHandler::isValidChatMessage linked item has color %u, but user claims %u", ItemQualityColors[linkedItem->Quality],
                                color);
#endif
                        return false;
                    }

                    // the itementry is followed by several integers which describe an instance of this item

                    // position relative after itemEntry
                    const uint8 randomPropertyPosition = 6;

                    int32 propertyId = 0;
                    bool negativeNumber = false;
                    char c = '\0';
                    for (uint8 i = 0; i < randomPropertyPosition; ++i)
                    {
                        propertyId = 0;
                        negativeNumber = false;
                        while ((c = reader.get()) != ':')
                        {
                            if (c >='0' && c <= '9')
                            {
                                propertyId*=10;
                                propertyId += c-'0';
                            } else if (c == '-')
                                negativeNumber = true;
                            else
                                return false;
                        }
                    }

                    if (negativeNumber)
                        propertyId *= -1;

                    if (propertyId > 0)
                    {
                        itemProperty = sItemRandomPropertiesStore.LookupEntry(propertyId);
                        if (!itemProperty)
                            return false;
                    }
                    else if (propertyId < 0)
                    {
                        itemSuffix = sItemRandomSuffixStore.LookupEntry(-propertyId);
                        if (!itemSuffix)
                            return false;
                    }

                    // ignore other integers
                    while ((c >= '0' && c <= '9') || c == ':')
                    {
                        reader.ignore(1);
                        c = reader.peek();
                    }
                }
                else if (strcmp(buffer, "quest") == 0)
                {
                    // no color check for questlinks, each client will adapt it anyway
                    uint32 questid= 0;
                    // read questid
                    char c = reader.peek();
                    while (c >='0' && c <= '9')
                    {
                        reader.ignore(1);
                        questid *= 10;
                        questid += c-'0';
                        c = reader.peek();
                    }

                    linkedQuest = sObjectMgr->GetQuestTemplate(questid);

                    if (!linkedQuest)
                    {
#ifdef TRINITY_DEBUG
                        sLog.outBasic("ChatHandler::isValidChatMessage Questtemplate %u not found", questid);
#endif
                        return false;
                    }
                    c = reader.peek();
                    // level
                    while (c !='|' && c != '\0')
                    {
                        reader.ignore(1);
                        c = reader.peek();
                    }
                }
                else if (strcmp(buffer, "trade") == 0)
                {
                    if (color != CHAT_LINK_COLOR_TRADE)
                        return false;

                    // read spell entry
                    reader.getline(buffer, 256, ':');
                    linkedSpell = sSpellStore.LookupEntry(atoi(buffer));
                    if (!linkedSpell)
                        return false;

                    char c = reader.peek();
                    // base64 encoded stuff
                    while (c !='|' && c != '\0')
                    {
                        reader.ignore(1);
                        c = reader.peek();
                    }
                }
                else if (strcmp(buffer, "talent") == 0)
                {
                    // talent links are always supposed to be blue
                    if (color != CHAT_LINK_COLOR_TALENT)
                        return false;

                    // read talent entry
                    reader.getline(buffer, 256, ':');
                    TalentEntry const *talentInfo = sTalentStore.LookupEntry(atoi(buffer));
                    if (!talentInfo)
                        return false;

                    linkedSpell = sSpellStore.LookupEntry(talentInfo->RankID[0]);
                    if (!linkedSpell)
                        return false;

                    char c = reader.peek();
                    // skillpoints? whatever, drop it
                    while (c !='|' && c != '\0')
                    {
                        reader.ignore(1);
                        c = reader.peek();
                    }
                }
                else if (strcmp(buffer, "spell") == 0)
                {
                    if (color != CHAT_LINK_COLOR_SPELL)
                        return false;

                    uint32 spellid = 0;
                    // read spell entry
                    char c = reader.peek();
                    while (c >='0' && c <= '9')
                    {
                        reader.ignore(1);
                        spellid *= 10;
                        spellid += c-'0';
                        c = reader.peek();
                    }
                    linkedSpell = sSpellStore.LookupEntry(spellid);
                    if (!linkedSpell)
                        return false;
                }
                else if (strcmp(buffer, "enchant") == 0)
                {
                    if (color != CHAT_LINK_COLOR_ENCHANT)
                        return false;

                    uint32 spellid = 0;
                    // read spell entry
                    char c = reader.peek();
                    while (c >='0' && c <= '9')
                    {
                        reader.ignore(1);
                        spellid *= 10;
                        spellid += c-'0';
                        c = reader.peek();
                    }
                    linkedSpell = sSpellStore.LookupEntry(spellid);
                    if (!linkedSpell)
                        return false;
                }
                else if (strcmp(buffer, "achievement") == 0)
                {
                    if (color != CHAT_LINK_COLOR_ACHIEVEMENT)
                        return false;
                    reader.getline(buffer, 256, ':');
                    uint32 achievementId = atoi(buffer);
                    linkedAchievement = sAchievementStore.LookupEntry(achievementId);

                    if (!linkedAchievement)
                        return false;

                    char c = reader.peek();
                    // skip progress
                    while (c !='|' && c != '\0')
                    {
                        reader.ignore(1);
                        c = reader.peek();
                    }
                }
                else if (strcmp(buffer, "glyph") == 0)
                {
                    if (color != CHAT_LINK_COLOR_GLYPH)
                        return false;

                    // first id is slot, drop it
                    reader.getline(buffer, 256, ':');
                    uint32 glyphId = 0;
                    char c = reader.peek();
                    while (c >= '0' && c <= '9')
                    {
                        glyphId *= 10;
                        glyphId += c-'0';
                        reader.ignore(1);
                        c = reader.peek();
                    }
                    GlyphPropertiesEntry const* glyph = sGlyphPropertiesStore.LookupEntry(glyphId);
                    if (!glyph)
                        return false;

                    linkedSpell = sSpellStore.LookupEntry(glyph->SpellId);

                    if (!linkedSpell)
                        return false;
                }
                else
                {
#ifdef TRINITY_DEBUG
                    sLog.outBasic("ChatHandler::isValidChatMessage user sent unsupported link type '%s'", buffer);
#endif
                    return false;
                }
                break;
            case 'h':
                // if h is next element in sequence, this one must contain the linked text :)
                if (*validSequenceIterator == 'h')
                {
                    // links start with '['
                    if (reader.get() != '[')
                    {
#ifdef TRINITY_DEBUG
                        sLog.outBasic("ChatHandler::isValidChatMessage link caption doesn't start with '['");
#endif
                        return false;
                    }
                    reader.getline(buffer, 256, ']');

                    // verify the link name
                    if (linkedSpell)
                    {
                        // spells with that flag have a prefix of "$PROFESSION: "
                        if (linkedSpell->Attributes & SPELL_ATTR0_TRADESPELL)
                        {
                            // lookup skillid
                            SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(linkedSpell->Id);
                            if (bounds.first == bounds.second)
                            {
                                return false;
                            }

                            SkillLineAbilityEntry const *skillInfo = bounds.first->second;

                            if (!skillInfo)
                            {
                                return false;
                            }

                            SkillLineEntry const *skillLine = sSkillLineStore.LookupEntry(skillInfo->skillId);
                            if (!skillLine)
                            {
                                return false;
                            }

                            for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
                            {
                                uint32 skillLineNameLength = strlen(skillLine->name[i]);
                                if (skillLineNameLength > 0 && strncmp(skillLine->name[i], buffer, skillLineNameLength) == 0)
                                {
                                    // found the prefix, remove it to perform spellname validation below
                                    // -2 = strlen(": ")
                                    uint32 spellNameLength = strlen(buffer)-skillLineNameLength-2;
                                    memmove(buffer, buffer+skillLineNameLength+2, spellNameLength+1);
                                }
                            }
                        }
                        bool foundName = false;
                        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
                        {
                            if (*linkedSpell->SpellName[i] && strcmp(linkedSpell->SpellName[i], buffer) == 0)
                            {
                                foundName = true;
                                break;
                            }
                        }
                        if (!foundName)
                            return false;
                    }
                    else if (linkedQuest)
                    {
                        if (linkedQuest->GetTitle() != buffer)
                        {
                            QuestLocale const *ql = sObjectMgr->GetQuestLocale(linkedQuest->GetQuestId());

                            if (!ql)
                            {
#ifdef TRINITY_DEBUG
                                sLog.outBasic("ChatHandler::isValidChatMessage default questname didn't match and there is no locale");
#endif
                                return false;
                            }

                            bool foundName = false;
                            for (uint8 i=0; i<ql->Title.size(); i++)
                            {
                                if (ql->Title[i] == buffer)
                                {
                                    foundName = true;
                                    break;
                                }
                            }
                            if (!foundName)
                            {
#ifdef TRINITY_DEBUG
                                sLog.outBasic("ChatHandler::isValidChatMessage no quest locale title matched");
#endif
                                return false;
                            }
                        }
                    }
                    else if (linkedItem)
                    {
                        char* const* suffix = itemSuffix?itemSuffix->nameSuffix:(itemProperty?itemProperty->nameSuffix:NULL);

                        std::string expectedName = std::string(linkedItem->Name1);
                        if (suffix)
                        {
                            expectedName += " ";
                            expectedName += suffix[LOCALE_enUS];
                        }

                        if (expectedName != buffer)
                        {
                            ItemLocale const *il = sObjectMgr->GetItemLocale(linkedItem->ItemId);

                            bool foundName = false;
                            for (uint8 dbIndex = LOCALE_koKR; dbIndex < TOTAL_LOCALES; ++dbIndex)
                            {
                                if (il == NULL || dbIndex >= il->Name.size())
                                    // using strange database/client combinations can lead to this case
                                    expectedName = linkedItem->Name1;
                                else
                                    expectedName = il->Name[dbIndex];
                                if (suffix)
                                {
                                    expectedName += " ";
                                    expectedName += suffix[dbIndex];
                                }
                                if (expectedName == buffer)
                                {
                                    foundName = true;
                                    break;
                                }
                            }
                            if (!foundName)
                            {
#ifdef TRINITY_DEBUG
                                sLog.outBasic("ChatHandler::isValidChatMessage linked item name wasn't found in any localization");
#endif
                                return false;
                            }
                        }
                    }
                    else if (linkedAchievement)
                    {
                        bool foundName = false;
                        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
                        {
                            if (*linkedAchievement->name[i] && strcmp(linkedAchievement->name[i], buffer) == 0)
                            {
                                foundName = true;
                                break;
                            }
                        }
                        if (!foundName)
                            return false;
                    }
                    // that place should never be reached - if nothing linked has been set in |H
                    // it will return false before
                    else
                        return false;
                }
                break;
            case 'r':
            case '|':
                // no further payload
                break;
            default:
#ifdef TRINITY_DEBUG
                sLog.outBasic("ChatHandler::isValidChatMessage got invalid command |%c", commandChar);
#endif
                return false;
        }
    }

    // check if every opened sequence was also closed properly
#ifdef TRINITY_DEBUG
    if (validSequence != validSequenceIterator)
        sLog.outBasic("ChatHandler::isValidChatMessage EOF in active sequence");
#endif
    return validSequence == validSequenceIterator;
}

bool ChatHandler::ShowHelpForSubCommands(ChatCommand *table, char const* cmd, char const* subcmd)
{
    std::string list;
    for (uint32 i = 0; table[i].Name != NULL; ++i)
    {
        // must be available (ignore handler existence for show command with possibe avalable subcomands
        if (!isAvailable(table[i]))
            continue;

        /// for empty subcmd show all available
        if (*subcmd && !hasStringAbbr(table[i].Name, subcmd))
            continue;

        if (m_session)
            list += "\n    ";
        else
            list += "\n\r    ";

        list += table[i].Name;

        if (table[i].ChildCommands)
            list += " ...";
    }

    if (list.empty())
        return false;

    if (table == getCommandTable())
    {
        SendSysMessage(LANG_AVIABLE_CMD);
        PSendSysMessage("%s",list.c_str());
    }
    else
        PSendSysMessage(LANG_SUBCMDS_LIST,cmd,list.c_str());

    return true;
}

bool ChatHandler::ShowHelpForCommand(ChatCommand *table, const char* cmd)
{
    if (*cmd)
    {
        for (uint32 i = 0; table[i].Name != NULL; ++i)
        {
            // must be available (ignore handler existence for show command with possibe avalable subcomands
            if (!isAvailable(table[i]))
                continue;

            if (!hasStringAbbr(table[i].Name, cmd))
                continue;

            // have subcommand
            char const* subcmd = (*cmd) ? strtok(NULL, " ") : "";

            if (table[i].ChildCommands && subcmd && *subcmd)
            {
                if (ShowHelpForCommand(table[i].ChildCommands, subcmd))
                    return true;
            }

            if (!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());

            if (table[i].ChildCommands)
                if (ShowHelpForSubCommands(table[i].ChildCommands,table[i].Name,subcmd ? subcmd : ""))
                    return true;

            return !table[i].Help.empty();
        }
    }
    else
    {
        for (uint32 i = 0; table[i].Name != NULL; ++i)
        {
            // must be available (ignore handler existence for show command with possibe avalable subcomands
            if (!isAvailable(table[i]))
                continue;

            if (strlen(table[i].Name))
                continue;

            if (!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());

            if (table[i].ChildCommands)
                if (ShowHelpForSubCommands(table[i].ChildCommands,"",""))
                    return true;

            return !table[i].Help.empty();
        }
    }

    return ShowHelpForSubCommands(table,"",cmd);
}

//Note: target_guid used only in CHAT_MSG_WHISPER_INFORM mode (in this case channelName ignored)
void ChatHandler::FillMessageData(WorldPacket *data, WorldSession* session, uint8 type, uint32 language, const char *channelName, uint64 target_guid, const char *message, Unit *speaker)
{
    uint32 messageLength = (message ? strlen(message) : 0) + 1;

    data->Initialize(SMSG_MESSAGECHAT, 100);                // guess size
    *data << uint8(type);
    if ((type != CHAT_MSG_CHANNEL && type != CHAT_MSG_WHISPER) || language == LANG_ADDON)
        *data << uint32(language);
    else
        *data << uint32(LANG_UNIVERSAL);

    switch(type)
    {
        case CHAT_MSG_SAY:
        case CHAT_MSG_PARTY:
        case CHAT_MSG_PARTY_LEADER:
        case CHAT_MSG_RAID:
        case CHAT_MSG_GUILD:
        case CHAT_MSG_OFFICER:
        case CHAT_MSG_YELL:
        case CHAT_MSG_WHISPER:
        case CHAT_MSG_CHANNEL:
        case CHAT_MSG_RAID_LEADER:
        case CHAT_MSG_RAID_WARNING:
        case CHAT_MSG_BG_SYSTEM_NEUTRAL:
        case CHAT_MSG_BG_SYSTEM_ALLIANCE:
        case CHAT_MSG_BG_SYSTEM_HORDE:
        case CHAT_MSG_BATTLEGROUND:
        case CHAT_MSG_BATTLEGROUND_LEADER:
            target_guid = session ? session->GetPlayer()->GetGUID() : 0;
            break;
        case CHAT_MSG_MONSTER_SAY:
        case CHAT_MSG_MONSTER_PARTY:
        case CHAT_MSG_MONSTER_YELL:
        case CHAT_MSG_MONSTER_WHISPER:
        case CHAT_MSG_MONSTER_EMOTE:
        case CHAT_MSG_RAID_BOSS_WHISPER:
        case CHAT_MSG_RAID_BOSS_EMOTE:
        case CHAT_MSG_BATTLENET:
        {
            *data << uint64(speaker->GetGUID());
            *data << uint32(0);                             // 2.1.0
            *data << uint32(strlen(speaker->GetName()) + 1);
            *data << speaker->GetName();
            uint64 listener_guid = 0;
            *data << uint64(listener_guid);
            if (listener_guid && !IS_PLAYER_GUID(listener_guid))
            {
                *data << uint32(1);                         // string listener_name_length
                *data << uint8(0);                          // string listener_name
            }
            *data << uint32(messageLength);
            *data << message;
            *data << uint8(0);
            return;
        }
        default:
            if (type != CHAT_MSG_WHISPER_INFORM && type != CHAT_MSG_IGNORED && type != CHAT_MSG_DND && type != CHAT_MSG_AFK)
                target_guid = 0;                            // only for CHAT_MSG_WHISPER_INFORM used original value target_guid
            break;
    }

    *data << uint64(target_guid);                           // there 0 for BG messages
    *data << uint32(0);                                     // can be chat msg group or something

    if (type == CHAT_MSG_CHANNEL)
    {
        ASSERT(channelName);
        *data << channelName;
    }

    *data << uint64(target_guid);
    *data << uint32(messageLength);
    *data << message;
    if (session != 0 && type != CHAT_MSG_WHISPER_INFORM && type != CHAT_MSG_DND && type != CHAT_MSG_AFK)
        *data << uint8(session->GetPlayer()->chatTag());
    else
        *data << uint8(0);
}

Player * ChatHandler::getSelectedPlayer()
{
    if (!m_session)
        return NULL;

    uint64 guid  = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return m_session->GetPlayer();

    return sObjectMgr->GetPlayer(guid);
}

Unit* ChatHandler::getSelectedUnit()
{
    if (!m_session)
        return NULL;

    uint64 guid = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return m_session->GetPlayer();

    return ObjectAccessor::GetUnit(*m_session->GetPlayer(),guid);
}

WorldObject *ChatHandler::getSelectedObject()
{
    if (!m_session)
        return NULL;

    uint64 guid = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return GetNearbyGameObject();

    return ObjectAccessor::GetUnit(*m_session->GetPlayer(),guid);
}

Creature* ChatHandler::getSelectedCreature()
{
    if (!m_session)
        return NULL;

    return ObjectAccessor::GetCreatureOrPetOrVehicle(*m_session->GetPlayer(),m_session->GetPlayer()->GetSelection());
}

char* ChatHandler::extractKeyFromLink(char* text, char const* linkType, char** something1)
{
    // skip empty
    if (!text)
        return NULL;

    // skip spaces
    while (*text == ' '||*text == '\t'||*text == '\b')
        ++text;

    if (!*text)
        return NULL;

    // return non link case
    if (text[0] != '|')
        return strtok(text, " ");

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r

    char* check = strtok(text, "|");                        // skip color
    if (!check)
        return NULL;                                        // end of data

    char* cLinkType = strtok(NULL, ":");                    // linktype
    if (!cLinkType)
        return NULL;                                        // end of data

    if (strcmp(cLinkType,linkType) != 0)
    {
        strtok(NULL, " ");                                  // skip link tail (to allow continue strtok(NULL,s) use after retturn from function
        SendSysMessage(LANG_WRONG_LINK_TYPE);
        return NULL;
    }

    char* cKeys = strtok(NULL, "|");                        // extract keys and values
    char* cKeysTail = strtok(NULL, "");

    char* cKey = strtok(cKeys, ":|");                       // extract key
    if (something1)
        *something1 = strtok(NULL, ":|");                   // extract something

    strtok(cKeysTail, "]");                                 // restart scan tail and skip name with possible spaces
    strtok(NULL, " ");                                      // skip link tail (to allow continue strtok(NULL,s) use after return from function
    return cKey;
}

char* ChatHandler::extractKeyFromLink(char* text, char const* const* linkTypes, int* found_idx, char** something1)
{
    // skip empty
    if (!text)
        return NULL;

    // skip spaces
    while (*text == ' '||*text == '\t'||*text == '\b')
        ++text;

    if (!*text)
        return NULL;

    // return non link case
    if (text[0] != '|')
        return strtok(text, " ");

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r
    // or
    // [name] Shift-click form |linkType:key|h[name]|h|r

    char* tail;

    if (text[1] == 'c')
    {
        char* check = strtok(text, "|");                    // skip color
        if (!check)
            return NULL;                                    // end of data

        tail = strtok(NULL, "");                            // tail
    }
    else
        tail = text+1;                                      // skip first |

    char* cLinkType = strtok(tail, ":");                    // linktype
    if (!cLinkType)
        return NULL;                                        // end of data

    for (int i = 0; linkTypes[i]; ++i)
    {
        if (strcmp(cLinkType,linkTypes[i]) == 0)
        {
            char* cKeys = strtok(NULL, "|");                // extract keys and values
            char* cKeysTail = strtok(NULL, "");

            char* cKey = strtok(cKeys, ":|");               // extract key
            if (something1)
                *something1 = strtok(NULL, ":|");           // extract something

            strtok(cKeysTail, "]");                         // restart scan tail and skip name with possible spaces
            strtok(NULL, " ");                              // skip link tail (to allow continue strtok(NULL,s) use after return from function
            if (found_idx)
                *found_idx = i;
            return cKey;
        }
    }

    strtok(NULL, " ");                                      // skip link tail (to allow continue strtok(NULL,s) use after return from function
    SendSysMessage(LANG_WRONG_LINK_TYPE);
    return NULL;
}

char const *fmtstring(char const *format, ...)
{
    va_list        argptr;
    #define    MAX_FMT_STRING    32000
    static char        temp_buffer[MAX_FMT_STRING];
    static char        string[MAX_FMT_STRING];
    static int        index = 0;
    char    *buf;
    int len;

    va_start(argptr, format);
    vsnprintf(temp_buffer,MAX_FMT_STRING, format, argptr);
    va_end(argptr);

    len = strlen(temp_buffer);

    if (len >= MAX_FMT_STRING)
        return "ERROR";

    if (len + index >= MAX_FMT_STRING-1)
    {
        index = 0;
    }

    buf = &string[index];
    memcpy(buf, temp_buffer, len+1);

    index += len + 1;

    return buf;
}

GameObject* ChatHandler::GetNearbyGameObject()
{
    if (!m_session)
        return NULL;

    Player* pl = m_session->GetPlayer();
    GameObject* obj = NULL;
    Trinity::NearestGameObjectCheck check(*pl);
    Trinity::GameObjectLastSearcher<Trinity::NearestGameObjectCheck> searcher(pl, obj, check);
    pl->VisitNearbyGridObject(999, searcher);
    return obj;
}

GameObject* ChatHandler::GetObjectGlobalyWithGuidOrNearWithDbGuid(uint32 lowguid,uint32 entry)
{
    if (!m_session)
        return NULL;

    Player* pl = m_session->GetPlayer();

    GameObject* obj = pl->GetMap()->GetGameObject(MAKE_NEW_GUID(lowguid, entry, HIGHGUID_GAMEOBJECT));

    if (!obj && sObjectMgr->GetGOData(lowguid))                   // guid is DB guid of object
    {
        // search near player then
        CellPair p(Trinity::ComputeCellPair(pl->GetPositionX(), pl->GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;

        Trinity::GameObjectWithDbGUIDCheck go_check(*pl,lowguid);
        Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck> checker(pl,obj,go_check);

        TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck>, GridTypeMapContainer > object_checker(checker);
        cell.Visit(p, object_checker, *pl->GetMap());
    }

    return obj;
}

enum SpellLinkType
{
    SPELL_LINK_SPELL   = 0,
    SPELL_LINK_TALENT  = 1,
    SPELL_LINK_ENCHANT = 2,
    SPELL_LINK_TRADE   = 3,
    SPELL_LINK_GLYPH   = 4
};

static char const* const spellKeys[] =
{
    "Hspell",                                               // normal spell
    "Htalent",                                              // talent spell
    "Henchant",                                             // enchanting recipe spell
    "Htrade",                                               // profession/skill spell
    "Hglyph",                                               // glyph
    0
};

uint32 ChatHandler::extractSpellIdFromLink(char* text)
{
    // number or [name] Shift-click form |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r
    // number or [name] Shift-click form |color|Hglyph:glyph_slot_id:glyph_prop_id|h[%s]|h|r
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    // number or [name] Shift-click form |color|Htalent:talent_id,rank|h[name]|h|r
    // number or [name] Shift-click form |color|Htrade:spell_id,skill_id,max_value,cur_value|h[name]|h|r
    int type = 0;
    char* param1_str = NULL;
    char* idS = extractKeyFromLink(text,spellKeys,&type,&param1_str);
    if (!idS)
        return 0;

    uint32 id = (uint32)atol(idS);

    switch(type)
    {
        case SPELL_LINK_SPELL:
            return id;
        case SPELL_LINK_TALENT:
        {
            // talent
            TalentEntry const* talentEntry = sTalentStore.LookupEntry(id);
            if (!talentEntry)
                return 0;

            int32 rank = param1_str ? (uint32)atol(param1_str) : 0;
            if (rank >= MAX_TALENT_RANK)
                return 0;

            if (rank < 0)
                rank = 0;

            return talentEntry->RankID[rank];
        }
        case SPELL_LINK_ENCHANT:
        case SPELL_LINK_TRADE:
            return id;
        case SPELL_LINK_GLYPH:
        {
            uint32 glyph_prop_id = param1_str ? (uint32)atol(param1_str) : 0;

            GlyphPropertiesEntry const* glyphPropEntry = sGlyphPropertiesStore.LookupEntry(glyph_prop_id);
            if (!glyphPropEntry)
                return 0;

            return glyphPropEntry->SpellId;
        }
    }

    // unknown type?
    return 0;
}

GameTele const* ChatHandler::extractGameTeleFromLink(char* text)
{
    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    char* cId = extractKeyFromLink(text,"Htele");
    if (!cId)
        return false;

    // id case (explicit or from shift link)
    if (cId[0] >= '0' || cId[0] >= '9')
        if (uint32 id = atoi(cId))
            return sObjectMgr->GetGameTele(id);

    return sObjectMgr->GetGameTele(cId);
}

enum GuidLinkType
{
    SPELL_LINK_PLAYER     = 0,                              // must be first for selection in not link case
    SPELL_LINK_CREATURE   = 1,
    SPELL_LINK_GAMEOBJECT = 2
};

static char const* const guidKeys[] =
{
    "Hplayer",
    "Hcreature",
    "Hgameobject",
    0
};

uint64 ChatHandler::extractGuidFromLink(char* text)
{
    int type = 0;

    // |color|Hcreature:creature_guid|h[name]|h|r
    // |color|Hgameobject:go_guid|h[name]|h|r
    // |color|Hplayer:name|h[name]|h|r
    char* idS = extractKeyFromLink(text,guidKeys,&type);
    if (!idS)
        return 0;

    switch(type)
    {
        case SPELL_LINK_PLAYER:
        {
            std::string name = idS;
            if (!normalizePlayerName(name))
                return 0;

            if (Player* player = sObjectMgr->GetPlayer(name.c_str()))
                return player->GetGUID();

            if (uint64 guid = sObjectMgr->GetPlayerGUIDByName(name))
                return guid;

            return 0;
        }
        case SPELL_LINK_CREATURE:
        {
            uint32 lowguid = (uint32)atol(idS);

            if (CreatureData const* data = sObjectMgr->GetCreatureData(lowguid))
                return MAKE_NEW_GUID(lowguid,data->id,HIGHGUID_UNIT);
            else
                return 0;
        }
        case SPELL_LINK_GAMEOBJECT:
        {
            uint32 lowguid = (uint32)atol(idS);

            if (GameObjectData const* data = sObjectMgr->GetGOData(lowguid))
                return MAKE_NEW_GUID(lowguid,data->id,HIGHGUID_GAMEOBJECT);
            else
                return 0;
        }
    }

    // unknown type?
    return 0;
}

std::string ChatHandler::extractPlayerNameFromLink(char* text)
{
    // |color|Hplayer:name|h[name]|h|r
    char* name_str = extractKeyFromLink(text,"Hplayer");
    if (!name_str)
        return "";

    std::string name = name_str;
    if (!normalizePlayerName(name))
        return "";

    return name;
}

bool ChatHandler::extractPlayerTarget(char* args, Player** player, uint64* player_guid /*=NULL*/,std::string* player_name /*= NULL*/)
{
    if (args && *args)
    {
        std::string name = extractPlayerNameFromLink(args);
        if (name.empty())
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        Player* pl = sObjectMgr->GetPlayer(name.c_str());

        // if allowed player pointer
        if (player)
            *player = pl;

        // if need guid value from DB (in name case for check player existence)
        uint64 guid = !pl && (player_guid || player_name) ? sObjectMgr->GetPlayerGUIDByName(name) : 0;

        // if allowed player guid (if no then only online players allowed)
        if (player_guid)
            *player_guid = pl ? pl->GetGUID() : guid;

        if (player_name)
            *player_name = pl || guid ? name : "";
    }
    else
    {
        Player* pl = getSelectedPlayer();
        // if allowed player pointer
        if (player)
            *player = pl;
        // if allowed player guid (if no then only online players allowed)
        if (player_guid)
            *player_guid = pl ? pl->GetGUID() : 0;

        if (player_name)
            *player_name = pl ? pl->GetName() : "";
    }

    // some from req. data must be provided (note: name is empty if player not exist)
    if ((!player || !*player) && (!player_guid || !*player_guid) && (!player_name || player_name->empty()))
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

void ChatHandler::extractOptFirstArg(char* args, char** arg1, char** arg2)
{
    char* p1 = strtok(args, " ");
    char* p2 = strtok(NULL, " ");

    if (!p2)
    {
        p2 = p1;
        p1 = NULL;
    }

    if (arg1)
        *arg1 = p1;

    if (arg2)
        *arg2 = p2;
}

char* ChatHandler::extractQuotedArg(char* args)
{
    if (!*args)
        return NULL;

    if (*args == '"')
        return strtok(args+1, "\"");
    else
    {
        char* space = strtok(args, "\"");
        if (!space)
            return false;
        return strtok(NULL, "\"");
    }
}

bool ChatHandler::needReportToTarget(Player* chr) const
{
    Player* pl = m_session->GetPlayer();
    return pl != chr && pl->IsVisibleGloballyFor(chr);
}

LocaleConstant ChatHandler::GetSessionDbcLocale() const
{
    return m_session->GetSessionDbcLocale();
}

int ChatHandler::GetSessionDbLocaleIndex() const
{
    return m_session->GetSessionDbLocaleIndex();
}

const char *CliHandler::GetTrinityString(int32 entry) const
{
    return sObjectMgr->GetTrinityStringForDBCLocale(entry);
}

bool CliHandler::isAvailable(ChatCommand const& cmd) const
{
    // skip non-console commands in console case
    return cmd.AllowConsole;
}

void CliHandler::SendSysMessage(const char *str)
{
    m_print(m_callbackArg, str);
    m_print(m_callbackArg, "\r\n");
}

std::string CliHandler::GetNameLink() const
{
    return GetTrinityString(LANG_CONSOLE_COMMAND);
}

bool CliHandler::needReportToTarget(Player* /*chr*/) const
{
    return true;
}

bool ChatHandler::GetPlayerGroupAndGUIDByName(const char* cname, Player* &plr, Group* &group, uint64 &guid, bool offline)
{
    plr  = NULL;
    guid = 0;

    if (cname)
    {
        std::string name = cname;
        if (!name.empty())
        {
            if (!normalizePlayerName(name))
            {
                PSendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }

            plr = sObjectMgr->GetPlayer(name.c_str());
            if (offline)
                guid = sObjectMgr->GetPlayerGUIDByName(name.c_str());
        }
    }

    if (plr)
    {
        group = plr->GetGroup();
        if (!guid || !offline)
            guid = plr->GetGUID();
    }
    else
    {
        if (getSelectedPlayer())
            plr = getSelectedPlayer();
        else
            plr = m_session->GetPlayer();

        if (!guid || !offline)
            guid  = plr->GetGUID();
        group = plr->GetGroup();
    }

    return true;
}

LocaleConstant CliHandler::GetSessionDbcLocale() const
{
    return sWorld.GetDefaultDbcLocale();
}

int CliHandler::GetSessionDbLocaleIndex() const
{
    return sObjectMgr->GetDBCLocaleIndex();
}
