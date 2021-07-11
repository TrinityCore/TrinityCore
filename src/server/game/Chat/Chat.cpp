/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Chat.h"
#include "Language.h"
#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "Realm.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"
#include <boost/algorithm/string/replace.hpp>
#include <sstream>
#include "Group.h"
#include "UpdateMask.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "AccountMgr.h"
#include "SpellMgr.h"
#include "PoolManager.h"
#include "GameEventMgr.h"

// Supported shift-links (client generated and server side)
// |color|Harea:area_id|h[name]|h|r
// |color|Hareatrigger:id|h[name]|h|r
// |color|Hareatrigger_target:id|h[name]|h|r
// |color|Hcreature:creature_guid|h[name]|h|r
// |color|Hcreature_entry:creature_id|h[name]|h|r
// |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r          - client, at shift click in recipes list dialog
// |color|Hgameevent:id|h[name]|h|r
// |color|Hgameobject:go_guid|h[name]|h|r
// |color|Hgameobject_entry:go_id|h[name]|h|r
// |color|Hitem:item_id:perm_ench_id:gem1:gem2:gem3:0:0:0:0|h[name]|h|r   - client, item icon shift click
// |color|Hitemset:itemset_id|h[name]|h|r
// |color|Hplayer:name|h[name]|h|r                                        - client, in some messages, at click copy only name instead link, so no way generate it in client string send to server
// |color|Hpool:pool_id|h[name]|h|r
// |color|Hquest:quest_id:quest_level|h[name]|h|r                         - client, quest list name shift-click
// |color|Hskill:skill_id|h[name]|h|r
// |color|Hspell:spell_id|h[name]|h|r                                     - client, spellbook spell icon shift-click
// |color|Htalent:talent_id,rank|h[name]|h|r                              - client, talent icon shift-click rank==-1 if shift-copy unlearned talent
// |color|Htaxinode:id|h[name]|h|r
// |color|Htele:id|h[name]|h|r

bool ChatHandler::load_command_table = true;

ChatCommand * ChatHandler::getCommandTable()
{
    static ChatCommand groupSpellCommandTable[] =
    {
        { "add",        SEC_ADMINISTRATOR,    true,  &ChatHandler::HandleGroupAddSpellCommand,         "", nullptr },
        { "rule",       SEC_ADMINISTRATOR,    true,  &ChatHandler::HandleGroupSetRuleCommand,          "", nullptr },
        { nullptr,      0,                    false, nullptr,                                          "", nullptr }
    };
    static ChatCommand ahbotCommandTable[] =
    {
        { "reload",     SEC_ADMINISTRATOR,    true,  &ChatHandler::HandleAHBotReloadCommand,           "Reload table and config", nullptr},
        { "update",     SEC_ADMINISTRATOR,    true,  &ChatHandler::HandleAHBotUpdateCommand,           "Add items for sale", nullptr},
        { nullptr,      0,                    false, nullptr,                                          "", nullptr }
    };
    static ChatCommand botCommandTable[] =
    {
        { "add",        SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotAddCommand,              "", nullptr },
        { "add_all",    SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotAddAllCommand,           "", nullptr },
        { "delete",     SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotDeleteCommand,           "", nullptr },
        { "info",       SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotInfoCommand,             "", nullptr },
        { "reload",     SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotReloadCommand,           "", nullptr },
        { "stop",       SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotStopCommand,             "", nullptr },
        { "start",      SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotStartCommand,            "", nullptr },
        { "ranadd",     SEC_ADMINISTRATOR,      true,  &ChatHandler::HandleBotAddRandomCommand,        "", nullptr },
        { nullptr,      0,                      false, nullptr,                                        "", nullptr },
    };
    static ChatCommand partyBotCommandTable[] =
    {
        { "add",        SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotAddCommand,         "", nullptr },
        { "clone",      SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotCloneCommand,       "", nullptr },
        { "setrole",    SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotSetRoleCommand,     "", nullptr },
        { "attackstart",SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotAttackStartCommand, "", nullptr },
        { "attackstop", SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotAttackStopCommand,  "", nullptr },
        { "aoe",        SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotAoECommand,         "", nullptr },
        { "ccmark",     SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotControlMarkCommand, "", nullptr },
        { "focusmark",  SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotFocusMarkCommand,   "", nullptr },
        { "clearmarks", SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotClearMarksCommand,  "", nullptr },
        { "cometome",   SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotComeToMeCommand,    "", nullptr },
        { "usegobject", SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotUseGObjectCommand,  "", nullptr },
        { "pause",      SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotPauseCommand,       "", nullptr },
        { "unpause",    SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotUnpauseCommand,     "", nullptr },
        { "remove",     SEC_ADMINISTRATOR,      false, &ChatHandler::HandlePartyBotRemoveCommand,      "", nullptr },
        { nullptr,      0,                      false, nullptr,                                        "", nullptr },
    };
    static ChatCommand battleBotAddCommandTable[] =
    {
        { "alterac",    SEC_ADMINISTRATOR,      false, &ChatHandler::HandleBattleBotAddAlteracCommand, "", nullptr },
        { "arathi",     SEC_ADMINISTRATOR,      false, &ChatHandler::HandleBattleBotAddArathiCommand,  "", nullptr },
        { "warsong",    SEC_ADMINISTRATOR,      false, &ChatHandler::HandleBattleBotAddWarsongCommand, "", nullptr },
        { nullptr,      0,                      false, nullptr,                                        "", nullptr },
    };
    static ChatCommand battleBotCommandTable[] =
    {
        { "add",          SEC_ADMINISTRATOR,    false, nullptr,            "Add a new bot", battleBotAddCommandTable },
        { "remove",       SEC_ADMINISTRATOR,    false, &ChatHandler::HandleBattleBotRemoveCommand,       "", nullptr },
        { "showpath",     SEC_ADMINISTRATOR,    false, &ChatHandler::HandleBattleBotShowPathCommand,     "", nullptr },
        { "showallpaths", SEC_ADMINISTRATOR,    false, &ChatHandler::HandleBattleBotShowAllPathsCommand, "", nullptr },
        { nullptr,        0,                    false, nullptr,                                          "", nullptr },
    };
    static ChatCommand accountSetCommandTable[] =
    {
        { "addon",          SEC_CONSOLE,        true,  &ChatHandler::HandleAccountSetAddonCommand,     "", nullptr },
        { "gmlevel",        SEC_CONSOLE,        true,  &ChatHandler::HandleAccountSetGmLevelCommand,   "", nullptr },
        { "password",       SEC_CONSOLE,        true,  &ChatHandler::HandleAccountSetPasswordCommand,  "", nullptr },
        { "locked",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleAccountSetLockedCommand,    "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand accountCommandTable[] =
    {
        { "characters",     SEC_GAMEMASTER,     true,  &ChatHandler::HandleAccountCharactersCommand,   "", nullptr },
        { "create",         SEC_CONSOLE,        true,  &ChatHandler::HandleAccountCreateCommand,       "", nullptr },
        { "delete",         SEC_CONSOLE,        true,  &ChatHandler::HandleAccountDeleteCommand,       "", nullptr },
        { "onlinelist",     SEC_CONSOLE,        true,  &ChatHandler::HandleAccountOnlineListCommand,   "", nullptr },
        { "lock",           SEC_PLAYER,         true,  &ChatHandler::HandleAccountLockCommand,         "", nullptr },
        { "set",            SEC_ADMINISTRATOR,  true,  nullptr,                                        "", accountSetCommandTable },
        { "password",       SEC_PLAYER,         true,  &ChatHandler::HandleAccountPasswordCommand,     "", nullptr },
        { "",               SEC_PLAYER,         true,  &ChatHandler::HandleAccountCommand,             "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand auctionCommandTable[] =
    {
        { "alliance",       SEC_TICKETMASTER,    false, &ChatHandler::HandleAuctionAllianceCommand,    "", nullptr },
        { "goblin",         SEC_TICKETMASTER,    false, &ChatHandler::HandleAuctionGoblinCommand,      "", nullptr },
        { "horde",          SEC_TICKETMASTER,    false, &ChatHandler::HandleAuctionHordeCommand,       "", nullptr },
        { "",               SEC_TICKETMASTER,    false, &ChatHandler::HandleAuctionCommand,            "", nullptr },
        { nullptr,          0,                   false, nullptr,                                       "", nullptr }
    };

    static ChatCommand banCommandTable[] =
    {
        { "account",        SEC_GAMEMASTER,     true,  &ChatHandler::HandleBanAccountCommand,          "", nullptr },
        { "allip",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanAllIPCommand,            "", nullptr },
        { "character",      SEC_GAMEMASTER,     true,  &ChatHandler::HandleBanCharacterCommand,        "", nullptr },
        { "ip",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanIPCommand,               "", nullptr },
        { "note",           SEC_TICKETMASTER,   true,  &ChatHandler::HandleAddCharacterNoteCommand,    "", nullptr },
        { "warn",           SEC_TICKETMASTER,   true,  &ChatHandler::HandleWarnCharacterCommand,       "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand baninfoCommandTable[] =
    {
        { "account",        SEC_TICKETMASTER,    true,  &ChatHandler::HandleBanInfoAccountCommand,     "", nullptr },
        { "character",      SEC_TICKETMASTER,    true,  &ChatHandler::HandleBanInfoCharacterCommand,   "", nullptr },
        { "ip",             SEC_GAMEMASTER,      true,  &ChatHandler::HandleBanInfoIPCommand,          "", nullptr },
        { nullptr,          0,                   false, nullptr,                                       "", nullptr }
    };

    static ChatCommand banlistCommandTable[] =
    {
        { "account",        SEC_TICKETMASTER,    true,  &ChatHandler::HandleBanListAccountCommand,     "", nullptr },
        { "character",      SEC_TICKETMASTER,    true,  &ChatHandler::HandleBanListCharacterCommand,   "", nullptr },
        { "ip",             SEC_GAMEMASTER,      true,  &ChatHandler::HandleBanListIPCommand,          "", nullptr },
        { nullptr,          0,                   false, nullptr,                                       "", nullptr }
    };

    static ChatCommand castCommandTable[] =
    {
        { "back",           SEC_DEVELOPER,   false, &ChatHandler::HandleCastBackCommand,               "", nullptr },
        { "dist",           SEC_DEVELOPER,   false, &ChatHandler::HandleCastDistCommand,               "", nullptr },
        { "self",           SEC_DEVELOPER,   false, &ChatHandler::HandleCastSelfCommand,               "", nullptr },
        { "target",         SEC_DEVELOPER,   false, &ChatHandler::HandleCastTargetCommand,             "", nullptr },
        { "",               SEC_DEVELOPER,   false, &ChatHandler::HandleCastCommand,                   "", nullptr },
        { nullptr,          0,               false, nullptr,                                           "", nullptr }
    };

    static ChatCommand characterDeletedListCommandTable[] =
    {
        { "account",        SEC_GAMEMASTER, true, &ChatHandler::HandleCharacterDeletedListAccountCommand, "", nullptr },
        { "name",           SEC_GAMEMASTER, true, &ChatHandler::HandleCharacterDeletedListNameCommand,    "", nullptr },
        { nullptr,          0,              false, nullptr,                                               "", nullptr }
    };

    static ChatCommand characterDeletedCommandTable[] =
    {
        { "delete",         SEC_CONSOLE,        true,  &ChatHandler::HandleCharacterDeletedDeleteCommand,  "", nullptr },
        { "list",           SEC_GAMEMASTER,     true,  nullptr                                          ,  "", characterDeletedListCommandTable },
        { "restore",        SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleCharacterDeletedRestoreCommand, "", nullptr },
        { "old",            SEC_CONSOLE,        true,  &ChatHandler::HandleCharacterDeletedOldCommand,     "", nullptr },
        { nullptr,          0,                  false, nullptr,                                            "", nullptr }
    };


    static ChatCommand characterCleanCommandTable[] =
    {
        { "todelete",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleCleanCharactersToDeleteCommand,     "", nullptr },
        { "items",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleCleanCharactersItemsCommand,        "", nullptr },
        { nullptr,          0,                  false, nullptr,                                                "", nullptr }
    };

    static ChatCommand characterPremadeCommandTable[] =
    {
        { "gear",          SEC_BASIC_ADMIN,     false, &ChatHandler::HandleCharacterPremadeGearCommand,     "", nullptr },
        { "spec",          SEC_BASIC_ADMIN,     false, &ChatHandler::HandleCharacterPremadeSpecCommand,     "", nullptr },
        { "savegear",      SEC_DEVELOPER,       false, &ChatHandler::HandleCharacterPremadeSaveGearCommand, "", nullptr },
        { "savespec",      SEC_DEVELOPER,       false, &ChatHandler::HandleCharacterPremadeSaveSpecCommand, "", nullptr },
        { nullptr,         0,                   false, nullptr,                                             "", nullptr }
    };

    static ChatCommand characterCommandTable[] =
    {
        { "aiinfo",         SEC_MODERATOR,      true,  &ChatHandler::HandleCharacterAIInfoCommand,     "", nullptr },
        { "deleted",        SEC_GAMEMASTER,     true, nullptr,                                         "", characterDeletedCommandTable},
        { "erase",          SEC_CONSOLE,        true,  &ChatHandler::HandleCharacterEraseCommand,      "", nullptr },
        { "level",          SEC_DEVELOPER,      true,  &ChatHandler::HandleCharacterLevelCommand,      "", nullptr },
        { "rename",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleCharacterRenameCommand,     "", nullptr },
        { "reputation",     SEC_TICKETMASTER,   true,  &ChatHandler::HandleCharacterReputationCommand, "", nullptr },
        { "hasitem",        SEC_TICKETMASTER,   true,  &ChatHandler::HandleCharacterHasItemCommand,    "", nullptr },
        { "race",           SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleCharacterChangeRaceCommand, "", nullptr },
        { "skin",           SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleCharacterCopySkinCommand,   "", nullptr },
        { "fillflys",       SEC_GAMEMASTER,     true,  &ChatHandler::HandleCharacterFillFlysCommand,   "", nullptr },
        { "premade",        SEC_BASIC_ADMIN,    false, nullptr,                                        "", characterPremadeCommandTable },
        { "clean",          SEC_ADMINISTRATOR,  true,  nullptr,                                        "", characterCleanCommandTable },
        { "citytitle",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCharacterCityTitleCommand,  "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand cheatCommandTable[] =
    {
        { "god",            SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatGodCommand,            "", nullptr },
        { "cooldown",       SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatCooldownCommand,       "", nullptr },
        { "casttime",       SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatCastTimeCommand,       "", nullptr },
        { "powercost",      SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatPowerCommand,          "", nullptr },
        { "debuffs",        SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatDebuffImmunityCommand, "", nullptr },
        { "criticals",      SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatAlwaysCritCommand,     "", nullptr },
        { "castchecks",     SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatNoCastCheckCommand,    "", nullptr },
        { "procs",          SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatAlwaysProcCommand,     "", nullptr },
        { "triggerpass",    SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatTriggerPassCommand,    "", nullptr },
        { "ignoretriggers", SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatIgnoreTriggersCommand, "", nullptr },
        { "waterwalk",      SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatWaterwalkCommand,      "", nullptr },
        { "wallclimb",      SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatWallclimbCommand,      "", nullptr },
        { "status",         SEC_GAMEMASTER,     false, &ChatHandler::HandleCheatStatusCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand cooldownCommandTable[] =
    {
        { "list",            SEC_GAMEMASTER,    false, &ChatHandler::HandleCooldownListCommand,             "", nullptr },
        { "clear",           SEC_GAMEMASTER,    false, &ChatHandler::HandleCooldownClearCommand,            "", nullptr },
        { "clearclientside", SEC_GAMEMASTER,    false, &ChatHandler::HandleCooldownClearClientSideCommand,  "", nullptr },
        { nullptr,             0,               false, nullptr,                                             "", nullptr }
    };

    static ChatCommand debugPlayCommandTable[] =
    {
        { "cinematic",      SEC_TICKETMASTER,   false, &ChatHandler::HandleDebugPlayCinematicCommand,       "", nullptr },
        { "sound",          SEC_TICKETMASTER,   false, &ChatHandler::HandleDebugPlaySoundCommand,           "", nullptr },
        { "text",           SEC_TICKETMASTER,   false, &ChatHandler::HandleDebugPlayScriptText,             "", nullptr },
        { "music",          SEC_TICKETMASTER,   false, &ChatHandler::HandleDebugPlayMusicCommand,           "", nullptr },
        { nullptr,          0,                  false, nullptr,                                             "", nullptr }
    };

    static ChatCommand debugLosCommandTable[] =
    {
        { "check",          SEC_DEVELOPER,      false, &ChatHandler::HandleDebugLoSCommand,                 "", nullptr },
        { "allow",          SEC_DEVELOPER,      false, &ChatHandler::HandleDebugLoSAllowCommand,            "", nullptr },
        { nullptr,          0,                  false, nullptr,                                             "", nullptr }
    };

    static ChatCommand debugSendCommandTable[] =
    {
        { "buyerror",       SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendBuyErrorCommand,        "", nullptr },
        { "channelnotify",  SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendChannelNotifyCommand,   "", nullptr },
        { "chatmmessage",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendChatMsgCommand,         "", nullptr },
        { "equiperror",     SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendEquipErrorCommand,      "", nullptr },
        { "opcode",         SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendOpcodeCommand,          "", nullptr },
        { "poi",            SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendPoiCommand,             "", nullptr },
        { "qpartymsg",      SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendQuestPartyMsgCommand,   "", nullptr },
        { "qinvalidmsg",    SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendQuestInvalidMsgCommand, "", nullptr },
        { "mailerror",      SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendMailErrorCommand,       "", nullptr },
        { "sellerror",      SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendSellErrorCommand,       "", nullptr },
        { "spellfail",      SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSendSpellFailCommand,       "", nullptr },
        { "visual",         SEC_DEVELOPER,      true,  &ChatHandler::HandleSendSpellVisualCommand,          "", nullptr },
        { "chanvisual",     SEC_DEVELOPER,      true,  &ChatHandler::HandleSendSpellChannelVisualCommand,   "", nullptr },
        { "chanvisualnext", SEC_DEVELOPER,      true,  &ChatHandler::HandleDebugSendNextChannelSpellVisualCommand, "", nullptr },
        { "impact",         SEC_DEVELOPER,      true,  &ChatHandler::HandleSendSpellImpactCommand,          "", nullptr },
        { "openbag",        SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugSendOpenBagCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                             "", nullptr }
    };

    static ChatCommand debugCommandTable[] =
    {
        { "anim",           SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugAnimCommand,                "", nullptr },
        { "bg",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleDebugBattlegroundCommand,        "", nullptr },
        { "bytes1",         SEC_DEVELOPER,      true,  &ChatHandler::HandleDebugUnitBytes1Command,          "", nullptr },
        { "bytes2",         SEC_DEVELOPER,      true,  &ChatHandler::HandleDebugUnitBytes2Command,          "", nullptr },
        { "condition",      SEC_TICKETMASTER,   false, &ChatHandler::HandleDebugConditionCommand,           "", nullptr },
        { "getitemstate",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugGetItemStateCommand,        "", nullptr },
        { "lrecipient",     SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugGetLootRecipientCommand,    "", nullptr },
        { "getitemvalue",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugGetItemValueCommand,        "", nullptr },
        { "getvaluebyindex",SEC_DEVELOPER,      false, &ChatHandler::HandleDebugGetValueByIndexCommand,     "", nullptr },
        { "getvaluebyname", SEC_DEVELOPER,      false, &ChatHandler::HandleDebugGetValueByNameCommand,      "", nullptr },
        { "moditemvalue",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugModItemValueCommand,        "", nullptr },
        { "modvalue",       SEC_DEVELOPER,      false, &ChatHandler::HandleDebugModValueCommand,            "", nullptr },
        { "play",           SEC_TICKETMASTER,   false, nullptr,                                             "", debugPlayCommandTable },
        { "send",           SEC_GAMEMASTER,     false, nullptr,                                             "", debugSendCommandTable },
        { "setaurastate",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSetAuraStateCommand,        "", nullptr },
        { "setitemvalue",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSetItemValueCommand,        "", nullptr },
        { "setvaluebyindex",SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSetValueByIndexCommand,     "", nullptr },
        { "setvaluebyname", SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSetValueByNameCommand,     "", nullptr },
        { "spellcheck",     SEC_CONSOLE,        true,  &ChatHandler::HandleDebugSpellCheckCommand,          "", nullptr },
        { "spellcoefs",     SEC_DEVELOPER,      true,  &ChatHandler::HandleDebugSpellCoefsCommand,          "", nullptr },
        { "spellmods",      SEC_DEVELOPER,      false, &ChatHandler::HandleDebugSpellModsCommand,           "", nullptr },
        { "uws",            SEC_DEVELOPER,      false, &ChatHandler::HandleDebugUpdateWorldStateCommand,    "", nullptr },
        { "forceupdate",    SEC_DEVELOPER,      false, &ChatHandler::HandleDebugForceUpdateCommand,         "", nullptr },
        { "los",            SEC_DEVELOPER,      false, &ChatHandler::HandleDebugLoSCommand,                 "", debugLosCommandTable },
        { "moveto",         SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugMoveToCommand,              "", nullptr },
        { "movedistance",   SEC_DEVELOPER,      false, &ChatHandler::HandleDebugMoveDistanceCommand,        "", nullptr },
        { "faceme",         SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugFaceMeCommand,              "", nullptr },
        { "assert",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleDebugAssertFalseCommand,         "", nullptr },
        { "pvpcredit",      SEC_DEVELOPER,      false, &ChatHandler::HandleDebugPvPCreditCommand,           "", nullptr },
        { "unitstate",      SEC_GAMEMASTER,     false, &ChatHandler::HandleUnitStatCommand,                 "", nullptr },
        { "control",        SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugControlCommand,             "", nullptr },
        { "monster",        SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugMonsterChatCommand,         "", nullptr },
        { "target",         SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugUnitCommand,                "", nullptr },
        { "time",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleDebugTimeCommand,                "", nullptr },
        { "moveflags",      SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugMoveFlagsCommand,           "", nullptr },
        { "movespline",     SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugMoveSplineCommand,          "", nullptr },
        { "dump",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleDebugRecvPacketDumpWrite,        "", nullptr },
        { "movemotion",     SEC_DEVELOPER,      false, &ChatHandler::HandleDebugMoveCommand,                "", nullptr },
        { "factionchange_items", SEC_ADMINISTRATOR, true, &ChatHandler::HandleFactionChangeItemsCommand,    "", nullptr },
        { "loottable",      SEC_DEVELOPER,      true,  &ChatHandler::HandleDebugLootTableCommand,           "", nullptr },
        { "utf8overflow",   SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleDebugOverflowCommand,            "", nullptr },
        { "chatfreeze",     SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleDebugChatFreezeCommand,          "", nullptr },
        {  nullptr,         0,                  false, nullptr,                                             "", nullptr }
    };

    static ChatCommand eventCommandTable[] =
    {
        { "list",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleEventListCommand,           "", nullptr },
        { "start",          SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleEventStartCommand,          "", nullptr },
        { "stop",           SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleEventStopCommand,           "", nullptr },
        { "enable",         SEC_DEVELOPER,      true,  &ChatHandler::HandleEventEnableCommand,         "", nullptr },
        { "disable",        SEC_DEVELOPER,      true,  &ChatHandler::HandleEventDisableCommand,        "", nullptr },
        { "",               SEC_GAMEMASTER,     true,  &ChatHandler::HandleEventInfoCommand,           "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand gmCommandTable[] =
    {
        { "chat",           SEC_MODERATOR,      false, &ChatHandler::HandleGMChatCommand,              "", nullptr },
        { "fly",            SEC_GAMEMASTER,     false, &ChatHandler::HandleGMFlyCommand,               "", nullptr },
        { "ingame",         SEC_PLAYER,         true,  &ChatHandler::HandleGMListIngameCommand,        "", nullptr },
        { "list",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleGMListFullCommand,          "", nullptr },
        { "visible",        SEC_TICKETMASTER,   false, &ChatHandler::HandleGMVisibleCommand,           "", nullptr },
        { "setview",        SEC_TICKETMASTER,   false, &ChatHandler::HandleSetViewCommand,             "", nullptr },
        { "",               SEC_TICKETMASTER,   false, &ChatHandler::HandleGMCommand,                  "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand goCommandTable[] =
    {
        { "creature",       SEC_TICKETMASTER, false, &ChatHandler::HandleGoCreatureCommand,          "", nullptr },
        { "graveyard",      SEC_TICKETMASTER, false, &ChatHandler::HandleGoGraveyardCommand,         "", nullptr },
        { "grid",           SEC_TICKETMASTER, false, &ChatHandler::HandleGoGridCommand,              "", nullptr },
        { "object",         SEC_TICKETMASTER, false, &ChatHandler::HandleGoObjectCommand,            "", nullptr },
        { "target",         SEC_TICKETMASTER, false, &ChatHandler::HandleGoTargetCommand,            "", nullptr },
        { "taxinode",       SEC_TICKETMASTER, false, &ChatHandler::HandleGoTaxinodeCommand,          "", nullptr },
        { "trigger",        SEC_TICKETMASTER, false, &ChatHandler::HandleGoTriggerCommand,           "", nullptr },
        { "zonexy",         SEC_TICKETMASTER, false, &ChatHandler::HandleGoZoneXYCommand,            "", nullptr },
        { "xy",             SEC_TICKETMASTER, false, &ChatHandler::HandleGoXYCommand,                "", nullptr },
        { "xyz",            SEC_TICKETMASTER, false, &ChatHandler::HandleGoXYZCommand,               "", nullptr },
        { "xyzo",           SEC_TICKETMASTER, false, &ChatHandler::HandleGoXYZOCommand,              "", nullptr },
        // Nostalrius
        { "forward",        SEC_TICKETMASTER, false, &ChatHandler::HandleGoForwardCommand,           "", nullptr },
        { "up",             SEC_TICKETMASTER, false, &ChatHandler::HandleGoUpCommand,                "", nullptr },
        { "relative",       SEC_TICKETMASTER, false, &ChatHandler::HandleGoRelativeCommand,          "", nullptr },
        // Battleground join
        { "warsong",        SEC_TICKETMASTER, false, &ChatHandler::HandleGoWarsongCommand,           "", nullptr },
        { "arathi",         SEC_TICKETMASTER, false, &ChatHandler::HandleGoArathiCommand,            "", nullptr },
        { "alterac",        SEC_TICKETMASTER, false, &ChatHandler::HandleGoAlteracCommand,           "", nullptr },
        { "",               SEC_TICKETMASTER, false, &ChatHandler::HandleGoCommand,                  "", nullptr },
        { nullptr,          0,                false, nullptr,                                        "", nullptr }
    };

    static ChatCommand gobjectCommandTable[] =
    {
        { "add",            SEC_DEVELOPER,      false, &ChatHandler::HandleGameObjectAddCommand,       "", nullptr },
        { "tmpadd",         SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectTempAddCommand,   "", nullptr },
        { "delete",         SEC_DEVELOPER,      false, &ChatHandler::HandleGameObjectDeleteCommand,    "", nullptr },
        { "move",           SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectMoveCommand,      "", nullptr },
        { "near",           SEC_TICKETMASTER,   false, &ChatHandler::HandleGameObjectNearCommand,      "", nullptr },
        { "target",         SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectTargetCommand,    "", nullptr },
        { "turn",           SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectTurnCommand,      "", nullptr },
        { "info",           SEC_TICKETMASTER,   false, &ChatHandler::HandleGameObjectInfoCommand,      "", nullptr },
        { "ufinfo",         SEC_DEVELOPER,      false, &ChatHandler::HandleGameObjectUpdateFieldsInfoCommand, "", nullptr },
        { "select",         SEC_TICKETMASTER,   false, &ChatHandler::HandleGameObjectSelectCommand,    "", nullptr },
        { "despawn",        SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectDespawnCommand,   "", nullptr },
        { "toggle",         SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectToggleCommand,    "", nullptr },
        { "reset",          SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectResetCommand,     "", nullptr },
        { "respawn",        SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectRespawnCommand,   "", nullptr },
        { "use",            SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectUseCommand,       "", nullptr },
        { "setgostate",     SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectSetGoStateCommand,"", nullptr },
        { "setlootstate",   SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectSetLootStateCommand,"", nullptr },
        { "customanim",     SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectSendCustomAnimCommand,"", nullptr },
        { "spawnanim",      SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectSendSpawnAnimCommand,"", nullptr },
        { "despawnanim",    SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectSendDespawnAnimCommand,"", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand guildCommandTable[] =
    {
        { "create",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildCreateCommand,         "", nullptr },
        { "delete",         SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleGuildDeleteCommand,         "", nullptr },
        { "invite",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildInviteCommand,         "", nullptr },
        { "uninvite",       SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildUninviteCommand,       "", nullptr },
        { "rank",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildRankCommand,           "", nullptr },
        { "rename",         SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleGuildRenameCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand groupCommandTable[] =
    {
        { "additem",         SEC_GAMEMASTER,    false, &ChatHandler::HandleGroupAddItemCommand,        "", nullptr },
        { "revive",          SEC_GAMEMASTER,    false, &ChatHandler::HandleGroupReviveCommand,         "", nullptr },
        { "replenish",       SEC_GAMEMASTER,    false, &ChatHandler::HandleGroupReplenishCommand,      "", nullptr },
        { "summon",          SEC_GAMEMASTER,    false, &ChatHandler::HandleGroupSummonCommand,         "", nullptr },
        { nullptr,           0,                 false, nullptr,                                        "", nullptr }
    };

    static ChatCommand honorCommandTable[] =
    {
        { "add",            SEC_BASIC_ADMIN,    false, &ChatHandler::HandleHonorAddCommand,            "", nullptr },
        { "addkill",        SEC_BASIC_ADMIN,    false, &ChatHandler::HandleHonorAddKillCommand,        "", nullptr },
        { "show",           SEC_TICKETMASTER,   false, &ChatHandler::HandleHonorShow,                  "", nullptr },
        { "setrp",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleHonorSetRPCommand,          "", nullptr },
        { "reset",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleHonorResetCommand,          "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand instanceCommandTable[] =
    {
        { "continents",     SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleInstanceContinentsCommand,  "", nullptr },
        { "getdata",        SEC_GAMEMASTER,     false, &ChatHandler::HandleInstanceGetDataCommand,     "", nullptr },
        { "listbinds",      SEC_GAMEMASTER,     false, &ChatHandler::HandleInstanceListBindsCommand,   "", nullptr },
        { "unbind",         SEC_GAMEMASTER,     false, &ChatHandler::HandleInstanceUnbindCommand,      "", nullptr },
        { "groupunbind",    SEC_BASIC_ADMIN,    false, &ChatHandler::HandleInstanceGroupUnbindCommand, "", nullptr },
        { "stats",          SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleInstanceStatsCommand,       "", nullptr },
        { "savedata",       SEC_BASIC_ADMIN,    false, &ChatHandler::HandleInstanceSaveDataCommand,    "", nullptr },
        { "switch",         SEC_BASIC_ADMIN,    false, &ChatHandler::HandleInstanceSwitchCommand,      "", nullptr },
        { "perfinfos",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleInstancePerfInfosCommand,   "", nullptr },
        { "smartrebind",    SEC_TICKETMASTER,   false, &ChatHandler::HandleInstanceBindingMode,        "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand learnCommandTable[] =
    {
        { "all",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLearnAllCommand,            "", nullptr },
        { "all_gm",         SEC_GAMEMASTER,     false, &ChatHandler::HandleLearnAllGMCommand,          "", nullptr },
        { "all_crafts",     SEC_GAMEMASTER,     false, &ChatHandler::HandleLearnAllCraftsCommand,      "", nullptr },
        { "all_default",    SEC_TICKETMASTER,   false, &ChatHandler::HandleLearnAllDefaultCommand,     "", nullptr },
        { "all_lang",       SEC_MODERATOR,      false, &ChatHandler::HandleLearnAllLangCommand,        "", nullptr },
        { "all_myclass",    SEC_DEVELOPER,      false, &ChatHandler::HandleLearnAllMyClassCommand,     "", nullptr },
        { "all_myspells",   SEC_DEVELOPER,      false, &ChatHandler::HandleLearnAllMySpellsCommand,    "", nullptr },
        { "all_mytalents",  SEC_DEVELOPER,      false, &ChatHandler::HandleLearnAllMyTalentsCommand,   "", nullptr },
        { "all_mytaxis",    SEC_TICKETMASTER,   false, &ChatHandler::HandleLearnAllMyTaxisCommand,     "", nullptr },
        { "all_recipes",    SEC_GAMEMASTER,     false, &ChatHandler::HandleLearnAllRecipesCommand,     "", nullptr },
        { "",               SEC_DEVELOPER,      false, &ChatHandler::HandleLearnCommand,               "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand unlearnCommandTable[] =
    {
        { "all_gm",         SEC_GAMEMASTER,     false, &ChatHandler::HandleUnLearnAllGMCommand,        "", nullptr },
        { "all_crafts",     SEC_GAMEMASTER,     false, &ChatHandler::HandleUnLearnAllCraftsCommand,    "", nullptr },
        { "all_recipes",    SEC_GAMEMASTER,     false, &ChatHandler::HandleUnLearnAllRecipesCommand,   "", nullptr },
        { "",               SEC_GAMEMASTER,     false, &ChatHandler::HandleUnLearnCommand,             "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand listCommandTable[] =
    {
        { "auras",          SEC_TICKETMASTER,  false, &ChatHandler::HandleListAurasCommand,          "", nullptr },
        { "creature",       SEC_TICKETMASTER,  true,  &ChatHandler::HandleListCreatureCommand,       "", nullptr },
        { "item",           SEC_TICKETMASTER,  true,  &ChatHandler::HandleListItemCommand,           "", nullptr },
        { "object",         SEC_TICKETMASTER,  true,  &ChatHandler::HandleListObjectCommand,         "", nullptr },
        { "talents",        SEC_TICKETMASTER,  false, &ChatHandler::HandleListTalentsCommand,        "", nullptr },
        { "movegens",       SEC_TICKETMASTER,  false, &ChatHandler::HandleListMoveGensCommand,       "", nullptr },
        { "hostilerefs",    SEC_TICKETMASTER,  false, &ChatHandler::HandleListHostileRefsCommand,    "", nullptr },
        { "threat",         SEC_TICKETMASTER,  false, &ChatHandler::HandleListThreatCommand,         "", nullptr },
        { nullptr,          0,                 false, nullptr,                                       "", nullptr }
    };

    static ChatCommand lookupAccountCommandTable[] =
    {
        { "email",          SEC_BASIC_ADMIN,   false, &ChatHandler::HandleLookupAccountEmailCommand,     "", nullptr },
        { "ip",             SEC_BASIC_ADMIN,   false, &ChatHandler::HandleLookupAccountIpCommand,        "", nullptr },
        { "iponline",       SEC_BASIC_ADMIN,   false, &ChatHandler::HandleLookupAccountIponlineCommand,  "", nullptr },
        { "name",           SEC_GAMEMASTER,    false, &ChatHandler::HandleLookupAccountNameCommand,      "", nullptr },
        { nullptr,          0,                 false, nullptr,                                           "", nullptr }
    };

    // TODO: Add console output support to async player lookups
    static ChatCommand lookupPlayerCommandTable[] =
    {
        { "account",        SEC_GAMEMASTER,   false,  &ChatHandler::HandleLookupPlayerAccountCommand,   "", nullptr },
        { "email",          SEC_BASIC_ADMIN,  false,  &ChatHandler::HandleLookupPlayerEmailCommand,     "", nullptr },
        { "ip",             SEC_BASIC_ADMIN,  false,  &ChatHandler::HandleLookupPlayerIpCommand,        "", nullptr },
        { "name",           SEC_MODERATOR,    false,  &ChatHandler::HandleLookupPlayerNameCommand,      "", nullptr },
        { "character",      SEC_TICKETMASTER, false,  &ChatHandler::HandleLookupPlayerCharacterCommand, "", nullptr },
        { nullptr,          0,                false,  nullptr,                                          "", nullptr }
    };

    static ChatCommand lookupCommandTable[] =
    {
        { "account",        SEC_GAMEMASTER,   true, nullptr,                                         "", lookupAccountCommandTable },
        { "area",           SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupAreaCommand,          "", nullptr },
        { "creature",       SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupCreatureCommand,      "", nullptr },
        { "creaturemodel",  SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupCreatureModelCommand, "", nullptr },
        { "event",          SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupEventCommand,         "", nullptr },
        { "faction",        SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupFactionCommand,       "", nullptr },
        { "item",           SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupItemCommand,          "", nullptr },
        { "itemset",        SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupItemSetCommand,       "", nullptr },
        { "object",         SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupObjectCommand,        "", nullptr },
        { "quest",          SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupQuestCommand,         "", nullptr },
        { "player",         SEC_MODERATOR,    true,  nullptr,                                        "", lookupPlayerCommandTable },
        { "pool",           SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupPoolCommand,          "", nullptr },
        { "skill",          SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupSkillCommand,         "", nullptr },
        { "spell",          SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupSpellCommand,         "", nullptr },
        { "sound",          SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupSoundCommand,         "", nullptr },
        { "taxinode",       SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupTaxiNodeCommand,      "", nullptr },
        { "tele",           SEC_TICKETMASTER, true,  &ChatHandler::HandleLookupTeleCommand,          "", nullptr },
        { "guild",          SEC_MODERATOR,    true,  &ChatHandler::HandleLookupGuildCommand,         "", nullptr },
        { nullptr,          0,                false, nullptr,                                        "", nullptr }
    };

    static ChatCommand modifyCommandTable[] =
    {
        { "hp",             SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyHPCommand,            "", nullptr },
        { "mana",           SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyManaCommand,          "", nullptr },
        { "rage",           SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyRageCommand,          "", nullptr },
        { "energy",         SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyEnergyCommand,        "", nullptr },
        { "money",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyMoneyCommand,         "", nullptr },
        { "speed",          SEC_TICKETMASTER,   false, &ChatHandler::HandleModifySpeedCommand,         "", nullptr },
        { "swim",           SEC_TICKETMASTER,   false, &ChatHandler::HandleModifySwimCommand,          "", nullptr },
        { "scale",          SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyScaleCommand,         "", nullptr },
        { "bwalk",          SEC_TICKETMASTER,   false, &ChatHandler::HandleModifyBWalkCommand,         "", nullptr },
        { "fly",            SEC_TICKETMASTER,   false, &ChatHandler::HandleModifyFlyCommand,           "", nullptr },
        { "aspeed",         SEC_TICKETMASTER,   false, &ChatHandler::HandleModifyASpeedCommand,        "", nullptr },
        { "faction",        SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyFactionCommand,       "", nullptr },
        { "tp",             SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyTalentCommand,        "", nullptr },
        { "mount",          SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyMountCommand,         "", nullptr },
        { "honor",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyHonorCommand,         "", nullptr },
        { "rep",            SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyRepCommand,           "", nullptr },
        { "drunk",          SEC_TICKETMASTER,   false, &ChatHandler::HandleModifyDrunkCommand,         "", nullptr },
        { "exhaustion",     SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyExhaustionCommand,    "", nullptr },
        { "emotestate",     SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyEmoteStateCommand,    "", nullptr },
        { "morph",          SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyMorphCommand,         "", nullptr },
        { "gender",         SEC_GAMEMASTER,     false, &ChatHandler::HandleModifyGenderCommand,        "", nullptr },
        { "strength",       SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyStrengthCommand,      "", nullptr },
        { "agility",        SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyAgilityCommand,       "", nullptr },
        { "stamina",        SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyStaminaCommand,       "", nullptr },
        { "intellect",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyIntellectCommand,     "", nullptr },
        { "spirit",         SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifySpiritCommand,        "", nullptr },
        { "armor",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyArmorCommand,         "", nullptr },
        { "holy",           SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyHolyCommand,          "", nullptr },
        { "fire",           SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyFireCommand,          "", nullptr },
        { "nature",         SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyNatureCommand,        "", nullptr },
        { "frost",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyFrostCommand,         "", nullptr },
        { "shadow",         SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyShadowCommand,        "", nullptr },
        { "arcane",         SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyArcaneCommand,        "", nullptr },
        { "ap",             SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyMeleeApCommand,       "", nullptr },
        { "rangeap",        SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyRangedApCommand,      "", nullptr },
        { "spellpower",     SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifySpellPowerCommand,    "", nullptr },
        { "crit",           SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyMeleeCritCommand,     "", nullptr },
        { "rangecrit",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyRangedCritCommand,    "", nullptr },
        { "spellcrit",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifySpellCritCommand,     "", nullptr },
        { "mainspeed",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyMainSpeedCommand,     "", nullptr },
        { "offspeed",       SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyOffSpeedCommand,      "", nullptr },
        { "rangespeed",     SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyRangedSpeedCommand,   "", nullptr },
        { "castspeed",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyCastSpeedCommand,     "", nullptr },
        { "block",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyBlockCommand,         "", nullptr },
        { "dodge",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyDodgeCommand,         "", nullptr },
        { "parry",          SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyParryCommand,         "", nullptr },
        { "combreach",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyCrCommand,            "", nullptr },
        { "boundrad",       SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyBrCommand,            "", nullptr },
        { "xprate",         SEC_PLAYER,         false, &ChatHandler::HandleModifyXpRateCommand,        "", nullptr },
        { "hairstyle",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyHairStyleCommand,     "", nullptr },
        { "haircolor",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyHairColorCommand,     "", nullptr },
        { "skincolor",      SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifySkinColorCommand,     "", nullptr },
        { "accessories",    SEC_BASIC_ADMIN,    false, &ChatHandler::HandleModifyAccessoriesCommand,   "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand creatureGroupsCommandTable[] =
    {
        { "add",            SEC_DEVELOPER,      false, &ChatHandler::HandleNpcGroupAddCommand,         "", nullptr },
        { "addrel",         SEC_DEVELOPER,      false, &ChatHandler::HandleNpcGroupAddRelCommand,      "", nullptr },
        { "del",            SEC_DEVELOPER,      false, &ChatHandler::HandleNpcGroupDelCommand,         "", nullptr },
        { "link",           SEC_DEVELOPER,      false, &ChatHandler::HandleNpcGroupLinkCommand,        "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand creatureSpawnsSetCommandTable[] =
    {
        { "entry",          SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSpawnSetEntryCommand,    "", nullptr },
        { "displayid",      SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSpawnSetDisplayIdCommand,"", nullptr },
        { "movetype",       SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSpawnSetMoveTypeCommand, "", nullptr },
        { "wanderdistance", SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSpawnWanderDistCommand,  "", nullptr },
        { "respawntime",    SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSpawnSpawnTimeCommand,   "", nullptr },
        { "deathstate",     SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSetDeathStateCommand,    "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand creatureSpawnsCommandTable[] =
    {
        { "add",            SEC_DEVELOPER,      false, &ChatHandler::HandleNpcAddCommand,              "", nullptr },
        { "addentry",       SEC_DEVELOPER,      false, &ChatHandler::HandleNpcAddEntryCommand,         "", nullptr },
        { "delete",         SEC_DEVELOPER,      false, &ChatHandler::HandleNpcDeleteCommand,           "", nullptr },
        { "info",           SEC_MODERATOR,      false, &ChatHandler::HandleNpcSpawnInfoCommand,        "", nullptr },
        { "set",            SEC_DEVELOPER,      false, nullptr,                                        "", creatureSpawnsSetCommandTable },
        { "move",           SEC_DEVELOPER,      false, &ChatHandler::HandleNpcSpawnMoveCommand,        "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand creatureSetCommandTable[] =
    {
        { "entry",          SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetEntryCommand,         "", nullptr },
        { "level",          SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetLevelCommand,         "", nullptr },
        { "faction",        SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetFactionIdCommand,     "", nullptr },
        { "flag",           SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetFlagCommand,          "", nullptr },
        { "displayid",      SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetDisplayIdCommand,     "", nullptr },
        { "movetype",       SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetMoveTypeCommand,      "", nullptr },
        { "wanderdistance", SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetWanderDistCommand,    "", nullptr },
        { "respawntime",    SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetSpawnTimeCommand,     "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand npcCommandTable[] =
    {
        { "additem",        SEC_DEVELOPER,      false, &ChatHandler::HandleNpcAddVendorItemCommand,    "", nullptr },
        { "addweapon",      SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcAddWeaponCommand,        "", nullptr },
        { "aiinfo",         SEC_MODERATOR,      false, &ChatHandler::HandleNpcAIInfoCommand,           "", nullptr },
        { "allowmove",      SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcAllowMovementCommand,    "", nullptr },
        { "allowattack",    SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcAllowAttackCommand,      "", nullptr },
        { "despawn",        SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcDespawnCommand,          "", nullptr },
        { "delitem",        SEC_DEVELOPER,      false, &ChatHandler::HandleNpcDelVendorItemCommand,    "", nullptr },
        { "evade",          SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcEvadeCommand,            "", nullptr },
        { "follow",         SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcFollowCommand,           "", nullptr },
        { "unfollow",       SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcUnFollowCommand,         "", nullptr },
        { "info",           SEC_MODERATOR,      false, &ChatHandler::HandleNpcInfoCommand,             "", nullptr },
        { "move",           SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcMoveCommand,             "", nullptr },
        { "playemote",      SEC_TICKETMASTER,   false, &ChatHandler::HandleNpcPlayEmoteCommand,        "", nullptr },
        { "say",            SEC_TICKETMASTER,   false, &ChatHandler::HandleNpcSayCommand,              "", nullptr },
        { "summon",         SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSummonCommand,           "", nullptr },
        { "textemote",      SEC_TICKETMASTER,   false, &ChatHandler::HandleNpcTextEmoteCommand,        "", nullptr },
        { "whisper",        SEC_TICKETMASTER,   false, &ChatHandler::HandleNpcWhisperCommand,          "", nullptr },
        { "yell",           SEC_TICKETMASTER,   false, &ChatHandler::HandleNpcYellCommand,             "", nullptr },
        { "tame",           SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcTameCommand,             "", nullptr },
        { "spawn",          SEC_MODERATOR,      false, nullptr,                                        "", creatureSpawnsCommandTable },
        { "set",            SEC_GAMEMASTER,     false, nullptr,                                        "", creatureSetCommandTable },
        { "group",          SEC_DEVELOPER,      false, nullptr,                                        "", creatureGroupsCommandTable },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand unitCommandTable[] =
    {
        { "aiinfo",         SEC_MODERATOR,      false, &ChatHandler::HandleUnitAIInfoCommand,          "", nullptr },
        { "info",           SEC_MODERATOR,      false, &ChatHandler::HandleUnitInfoCommand,            "", nullptr },
        { "speedinfo",      SEC_MODERATOR,      false, &ChatHandler::HandleUnitSpeedInfoCommand,       "", nullptr },
        { "statinfo",       SEC_MODERATOR,      false, &ChatHandler::HandleUnitStatInfoCommand,        "", nullptr },
        { "ufinfo",         SEC_DEVELOPER,      false, &ChatHandler::HandleUnitUpdateFieldsInfoCommand,"", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand pbcastCommandTable[] =
    {
        { "stats",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandlePBCastStatsCommand,         "", nullptr },
        { "setthreads",     SEC_ADMINISTRATOR,  true,  &ChatHandler::HandlePBCastSetThreadsCommand,    "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand pdumpCommandTable[] =
    {
        { "load",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandlePDumpLoadCommand,           "", nullptr },
        { "write",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandlePDumpWriteCommand,          "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand poolCommandTable[] =
    {
        { "list",           SEC_GAMEMASTER,     false, &ChatHandler::HandlePoolListCommand,            "", nullptr },
        { "update",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandlePoolUpdateCommand,          "", nullptr },
        { "spawns",         SEC_GAMEMASTER,     false, &ChatHandler::HandlePoolSpawnsCommand,          "", nullptr },
        { "",               SEC_GAMEMASTER,     true,  &ChatHandler::HandlePoolInfoCommand,            "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand questCommandTable[] =
    {
        { "add",            SEC_BASIC_ADMIN,    false, &ChatHandler::HandleQuestAddCommand,            "", nullptr },
        { "complete",       SEC_BASIC_ADMIN,    false, &ChatHandler::HandleQuestCompleteCommand,       "", nullptr },
        { "status",         SEC_GAMEMASTER,     false, &ChatHandler::HandleQuestStatusCommand,         "", nullptr },
        { "remove",         SEC_GAMEMASTER,     false, &ChatHandler::HandleQuestRemoveCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand petCommandTable[] =
    {
        { "list",           SEC_GAMEMASTER,     true,  &ChatHandler::HandlePetListCommand,              "", nullptr },
        { "rename",         SEC_GAMEMASTER,     true,  &ChatHandler::HandlePetRenameCommand,            "", nullptr },
        { "delete",         SEC_GAMEMASTER,     true,  &ChatHandler::HandlePetDeleteCommand,            "", nullptr },
        { "loyalty",        SEC_GAMEMASTER,     false, &ChatHandler::HandlePetLoyaltyCommand,           "", nullptr },
        { "info",           SEC_MODERATOR,      false, &ChatHandler::HandlePetInfoCommand,              "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };

    static ChatCommand reloadCommandTable[] =
    {
        { "all",            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllCommand,           "", nullptr },
        { "all_area",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllAreaCommand,       "", nullptr },
        { "all_gossips",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllGossipsCommand,    "", nullptr },
        { "all_item",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllItemCommand,       "", nullptr },
        { "all_locales",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllLocalesCommand,    "", nullptr },
        { "all_loot",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllLootCommand,       "", nullptr },
        { "all_npc",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllNpcCommand,        "", nullptr },
        { "all_quest",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllQuestCommand,      "", nullptr },
        { "all_scripts",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllScriptsCommand,    "", nullptr },
        { "all_spell",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllSpellCommand,      "", nullptr },

        { "anticheat",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAnticheatCommand,     "", nullptr },
        { "config",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadConfigCommand,        "", nullptr },

        { "areatrigger_involvedrelation", SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadQuestAreaTriggersCommand,       "", nullptr },
        { "areatrigger_tavern",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadAreaTriggerTavernCommand,       "", nullptr },
        { "areatrigger_teleport",         SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadAreaTriggerTeleportCommand,     "", nullptr },
        { "character_pet",                SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCharacterPetCommand,            "", nullptr },
        { "command",                      SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCommandCommand,                 "", nullptr },
        { "conditions",                   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadConditionsCommand,              "", nullptr },
        { "creature",                     SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureCommand,                "", nullptr },
        { "creature_ai_events",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadEventAIEventsCommand,           "", nullptr },
        { "creature_battleground",        SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadBattleEventCommand,             "", nullptr },
        { "creature_involvedrelation",    SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureQuestInvRelationsCommand, "", nullptr },
        { "creature_loot_template",       SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesCreatureCommand,   "", nullptr },
        { "creature_questrelation",       SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureQuestRelationsCommand,  "", nullptr },
        { "creature_spells",              SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureSpellsCommand,          "", nullptr },
        { "creature_spells_scripts",      SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureSpellScriptsCommand,    "", nullptr },
        { "disenchant_loot_template",     SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesDisenchantCommand, "", nullptr },
        { "event_scripts",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadEventScriptsCommand,            "", nullptr },
        { "fishing_loot_template",        SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesFishingCommand,    "", nullptr },
        { "game_graveyard_zone",          SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGameGraveyardZoneCommand,       "", nullptr },
        { "game_tele",                    SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGameTeleCommand,                "", nullptr },
        { "taxi_path_transitions",        SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadTaxiPathTransitionsCommand,     "", nullptr },
        { "gameobject",                   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGameObjectCommand,              "", nullptr },
        { "gameobject_involvedrelation",  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGOQuestInvRelationsCommand,     "", nullptr },
        { "gameobject_loot_template",     SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesGameobjectCommand, "", nullptr },
        { "gameobject_questrelation",     SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGOQuestRelationsCommand,        "", nullptr },
        { "gameobject_requirement",       SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGORequirementsCommand,          "", nullptr },
        { "gameobject_scripts",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGameObjectScriptsCommand,       "", nullptr },
        { "gameobject_battleground",      SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadBattleEventCommand,             "", nullptr },
        { "gossip_menu",                  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGossipMenuCommand,              "", nullptr },
        { "gossip_menu_option",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGossipMenuOptionCommand,        "", nullptr },
        { "generic_scripts",              SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGenericScriptsCommand,          "", nullptr },
        { "gossip_scripts",               SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGossipScriptsCommand,           "", nullptr },
        { "item_enchantment_template",    SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadItemEnchantementsCommand,       "", nullptr },
        { "item_loot_template",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesItemCommand,       "", nullptr },
        { "item_required_target",         SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadItemRequiredTragetCommand,      "", nullptr },
        { "locales_creature",             SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesCreatureCommand,         "", nullptr },
        { "locales_gameobject",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesGameobjectCommand,       "", nullptr },
        { "locales_gossip_menu_option",   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesGossipMenuOptionCommand, "", nullptr },
        { "locales_item",                 SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesItemCommand,             "", nullptr },
        { "locales_page_text",            SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesPageTextCommand,         "", nullptr },
        { "locales_points_of_interest",   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesPointsOfInterestCommand, "", nullptr },
        { "locales_quest",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLocalesQuestCommand,            "", nullptr },
        { "mail_loot_template",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesMailCommand,       "", nullptr },
        { "mangos_string",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadMangosStringCommand,            "", nullptr },
        { "npc_gossip",                   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadNpcGossipCommand,               "", nullptr },
        { "npc_text",                     SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadNpcTextCommand,                 "", nullptr },
        { "npc_trainer",                  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadNpcTrainerCommand,              "", nullptr },
        { "npc_vendor",                   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadNpcVendorCommand,               "", nullptr },
        { "page_text",                    SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadPageTextsCommand,               "", nullptr },
        { "pickpocketing_loot_template",  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesPickpocketingCommand, "", nullptr},
        { "points_of_interest",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadPointsOfInterestCommand,        "", nullptr },
        { "quest_end_scripts",            SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadQuestEndScriptsCommand,         "", nullptr },
        { "quest_start_scripts",          SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadQuestStartScriptsCommand,       "", nullptr },
        { "quest_template",               SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadQuestTemplateCommand,           "", nullptr },
        { "quest_greeting",               SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadQuestGreetingCommand,           "", nullptr },
        { "trainer_greeting",             SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadTrainerGreetingCommand,         "", nullptr },
        { "reference_loot_template",      SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesReferenceCommand,  "", nullptr },
        { "reserved_name",                SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadReservedNameCommand,            "", nullptr },
        { "reputation_reward_rate",       SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadReputationRewardRateCommand,    "", nullptr },
        { "reputation_spillover_template", SEC_DEVELOPER,    true, &ChatHandler::HandleReloadReputationSpilloverTemplateCommand, "", nullptr },
        { "skill_fishing_base_level",     SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSkillFishingBaseLevelCommand,   "", nullptr },
        { "skinning_loot_template",       SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadLootTemplatesSkinningCommand,   "", nullptr },
        { "spell_affect",                 SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellAffectCommand,             "", nullptr },
        { "spell_area",                   SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellAreaCommand,               "", nullptr },
        { "spell_chain",                  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellChainCommand,              "", nullptr },
        { "spell_elixir",                 SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellElixirCommand,             "", nullptr },
        { "spell_learn_spell",            SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellLearnSpellCommand,         "", nullptr },
        { "spell_pet_auras",              SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellPetAurasCommand,           "", nullptr },
        { "spell_proc_event",             SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellProcEventCommand,          "", nullptr },
        { "spell_proc_item_enchant",      SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellProcItemEnchantCommand,    "", nullptr },
        { "spell_script_target",          SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellScriptTargetCommand,       "", nullptr },
        { "spell_scripts",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellScriptsCommand,            "", nullptr },
        { "spell_target_position",        SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellTargetPositionCommand,     "", nullptr },
        { "spell_threats",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellThreatsCommand,            "", nullptr },
        { "spell_disabled",               SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellDisabledCommand,           "", nullptr },
        { "autobroadcast",                SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadAutoBroadcastCommand,           "", nullptr },
        { "spell_mod",                    SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellModsCommand,               "", nullptr },
        { "map_loot_disabled",            SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadMapLootDisabledCommand,         "", nullptr },
        { "cinematic_waypoints",          SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCinematicWaypointsCommand,      "", nullptr },
        { "variables",                    SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadVariablesCommand,               "", nullptr },
        { "spell_group",                  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellGroupCommand,              "", nullptr },
        { "spell_group_stack_rules",      SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadSpellGroupStackRulesCommand,    "", nullptr },
        { "creature_groups",              SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureGroupsCommand,          "", nullptr },

        { "creature_template",           SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureTemplate,               "", nullptr },
        { "item_template",               SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadItemTemplate,                   "", nullptr },
        { "map_template",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadMapTemplate,                    "", nullptr },
        { "gameobject_template",         SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGameObjectTemplate,             "", nullptr },
        { "exploration_basexp",          SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadExplorationBaseXp,              "", nullptr },
        { "pet_name_generation",         SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadPetNameGeneration,              "", nullptr },
        { "creature_onkill_reputation",  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureOnKillReputation,       "", nullptr },
        { "game_weather",                SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadGameWeather,                    "", nullptr },
        { "player_factionchange_reputations", SEC_DEVELOPER,  true,  &ChatHandler::HandleReloadFactionChangeReputations,     "", nullptr },
        { "player_factionchange_spells", SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadFactionChangeSpells,            "", nullptr },
        { "player_factionchange_items",  SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadFactionChangeItems,             "", nullptr },
        { "player_factionchange_quests", SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadFactionChangeQuests,            "", nullptr },
        { "player_factionchange_mounts", SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadFactionChangeMounts,            "", nullptr },
        { "creature_display_info_addon", SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadCreatureDisplayInfoAddon,       "", nullptr },
        { "ip_banned",                   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadIPBanList,                      "", nullptr },
        { "account_banned",              SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadAccountBanList,                 "", nullptr },
        { "instance_buff_removal",       SEC_DEVELOPER,     true,  &ChatHandler::HandleReloadInstanceBuffRemoval,            "", nullptr },
        { "petitions",                   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadPetitions,                      "", nullptr },
        { nullptr,                       0,                 false, nullptr,                                                  "", nullptr }
    };

    static ChatCommand resetCommandTable[] =
    {
        { "honor",          SEC_DEVELOPER,      true,  &ChatHandler::HandleResetHonorCommand,          "", nullptr },
        { "level",          SEC_DEVELOPER,      true,  &ChatHandler::HandleResetLevelCommand,          "", nullptr },
        { "spells",         SEC_DEVELOPER,      true,  &ChatHandler::HandleResetSpellsCommand,         "", nullptr },
        { "stats",          SEC_DEVELOPER,      true,  &ChatHandler::HandleResetStatsCommand,          "", nullptr },
        { "talents",        SEC_GAMEMASTER,     true,  &ChatHandler::HandleResetTalentsCommand,        "", nullptr },
        { "items",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleResetItemsCommand,          "", nullptr },
        { "all",            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleResetAllCommand,            "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand sendMassCommandTable[] =
    {
        { "items",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMassItemsCommand,       "", nullptr },
        { "mail",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMassMailCommand,        "", nullptr },
        { "money",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMassMoneyCommand,       "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand sendCommandTable[] =
    {
        { "mass",           SEC_ADMINISTRATOR,  true, nullptr,                                         "", sendMassCommandTable },

        { "items",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendItemsCommand,           "", nullptr },
        { "mail",           SEC_MODERATOR,      true,  &ChatHandler::HandleSendMailCommand,            "", nullptr },
        { "message",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMessageCommand,         "", nullptr },
        { "money",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMoneyCommand,           "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand serverIdleRestartCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand, "", nullptr },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerIdleRestartCommand,    "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };

    static ChatCommand serverIdleShutdownCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand, "", nullptr },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerIdleShutDownCommand,   "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };

    static ChatCommand serverRestartCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand, "", nullptr },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerRestartCommand,        "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };

    static ChatCommand serverShutdownCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand, "", nullptr },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCommand,       "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };

    static ChatCommand serverLogCommandTable[] =
    {
        { "filter",         SEC_CONSOLE,        true,  &ChatHandler::HandleServerLogFilterCommand,     "", nullptr },
        { "level",          SEC_CONSOLE,        true,  &ChatHandler::HandleServerLogLevelCommand,      "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand serverSetCommandTable[] =
    {
        { "motd",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerSetMotdCommand,       "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand serverCommandTable[] =
    {
        { "corpses",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerCorpsesCommand,       "", nullptr },
        { "exit",           SEC_CONSOLE,        true,  &ChatHandler::HandleServerExitCommand,          "", nullptr },
        { "idlerestart",    SEC_ADMINISTRATOR,  true, nullptr,                                         "", serverIdleRestartCommandTable },
        { "idleshutdown",   SEC_ADMINISTRATOR,  true, nullptr,                                         "", serverIdleShutdownCommandTable },
        { "info",           SEC_PLAYER,         true,  &ChatHandler::HandleServerInfoCommand,          "", nullptr },
        { "log",            SEC_CONSOLE,        true, nullptr,                                         "", serverLogCommandTable },
        { "motd",           SEC_PLAYER,         true,  &ChatHandler::HandleServerMotdCommand,          "", nullptr },
        { "plimit",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerPLimitCommand,        "", nullptr },
        { "resetallraids",  SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerResetAllRaidCommand,  "", nullptr },
        { "restart",        SEC_ADMINISTRATOR,  true, nullptr,                                         "", serverRestartCommandTable },
        { "shutdown",       SEC_ADMINISTRATOR,  true, nullptr,                                         "", serverShutdownCommandTable },
        { "set",            SEC_ADMINISTRATOR,  true, nullptr,                                         "", serverSetCommandTable },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand teleCommandTable[] =
    {
        { "add",            SEC_DEVELOPER,      false, &ChatHandler::HandleTeleAddCommand,             "", nullptr },
        { "del",            SEC_DEVELOPER,      true,  &ChatHandler::HandleTeleDelCommand,             "", nullptr },
        { "name",           SEC_TICKETMASTER,   true,  &ChatHandler::HandleTeleNameCommand,            "", nullptr },
        { "group",          SEC_TICKETMASTER,   false, &ChatHandler::HandleTeleGroupCommand,           "", nullptr },
        { "",               SEC_TICKETMASTER,   false, &ChatHandler::HandleTeleCommand,                "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand triggerCommandTable[] =
    {
        { "active",         SEC_TICKETMASTER,   false, &ChatHandler::HandleTriggerActiveCommand,       "", nullptr },
        { "near",           SEC_TICKETMASTER,   false, &ChatHandler::HandleTriggerNearCommand,         "", nullptr },
        { "",               SEC_TICKETMASTER,   true,  &ChatHandler::HandleTriggerCommand,             "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand unbanCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleUnBanAccountCommand,      "", nullptr },
        { "character",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleUnBanCharacterCommand,    "", nullptr },
        { "ip",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleUnBanIPCommand,           "", nullptr },
        { nullptr,          0,                  false, nullptr,                                      "", nullptr }
    };

    static ChatCommand wpCommandTable[] =
    {
        { "show",           SEC_TICKETMASTER,   false, &ChatHandler::HandleWpShowCommand,              "", nullptr },
        { "add",            SEC_DEVELOPER,      false, &ChatHandler::HandleWpAddCommand,               "", nullptr },
        { "modify",         SEC_DEVELOPER,      false, &ChatHandler::HandleWpModifyCommand,            "", nullptr },
        { "export",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleWpExportCommand,            "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand worldCommandTable[] =
    {
        { "update",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleWorldUpdateCommand,         "", nullptr },
        { "cansee",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleWorldTestCommand,           "", nullptr },
        { "detail",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleWorldDetailCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand cinematicCommandTable[] =
    {
        { "addwp",          SEC_DEVELOPER,      false, &ChatHandler::HandleCinematicAddWpCommand,      "", nullptr },
        { "gotime",         SEC_DEVELOPER,      false, &ChatHandler::HandleCinematicGoTimeCommand,     "", nullptr },
        { "listwp",         SEC_DEVELOPER,      false, &ChatHandler::HandleCinematicListWpCommand,     "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand escortCommandTable[] =
    {
        { "create",         SEC_DEVELOPER,      false, &ChatHandler::HandleEscortCreateCommand,        "", nullptr },
        { "addwp",          SEC_DEVELOPER,      false, &ChatHandler::HandleEscortAddWpCommand,         "", nullptr },
        { "modwp",          SEC_DEVELOPER,      false, &ChatHandler::HandleEscortModifyWpCommand,      "", nullptr },
        { "clearwp",        SEC_DEVELOPER,      false, &ChatHandler::HandleEscortClearWpCommand,       "", nullptr },
        { "showwp",         SEC_TICKETMASTER,   false, &ChatHandler::HandleEscortShowWpCommand,        "", nullptr },
        { "hidewp",         SEC_TICKETMASTER,   false, &ChatHandler::HandleEscortHideWpCommand,        "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };
    static ChatCommand worldStateCommandTable[] =
    {
        { "test",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUpdateWorldStateCommand,    "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };
    static ChatCommand bgCommandTable[] =
    {
        { "status",         SEC_GAMEMASTER,     false, &ChatHandler::HandleBGStatusCommand,            "", nullptr },
        { "start",          SEC_GAMEMASTER,     false, &ChatHandler::HandleBGStartCommand,             "", nullptr },
        { "stop",           SEC_GAMEMASTER,     false, &ChatHandler::HandleBGStopCommand,              "", nullptr },
        { "",               SEC_GAMEMASTER,     false, &ChatHandler::HandleBGCustomCommand,            "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };
    static ChatCommand spellCommandTable[] =
    {
        { "effects",        SEC_GAMEMASTER,     true, &ChatHandler::HandleSpellEffectsCommand,         "", nullptr },
        { "info",           SEC_GAMEMASTER,     true, &ChatHandler::HandleSpellInfosCommand,           "", nullptr },
        { "search",         SEC_GAMEMASTER,     true, &ChatHandler::HandleSpellSearchCommand,          "", nullptr },
        { "iconfix",        SEC_DEVELOPER,      true, &ChatHandler::HandleSpellIconFixCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };
    static ChatCommand mmapCommandTable[] =
    {
        { "path",           SEC_GAMEMASTER,     false, &ChatHandler::HandleMmapPathCommand,            "", nullptr },
        { "loc",            SEC_GAMEMASTER,     false, &ChatHandler::HandleMmapLocCommand,             "", nullptr },
        { "loadedtiles",    SEC_GAMEMASTER,     false, &ChatHandler::HandleMmapLoadedTilesCommand,     "", nullptr },
        { "stats",          SEC_GAMEMASTER,     false, &ChatHandler::HandleMmapStatsCommand,           "", nullptr },
        { "testarea",       SEC_GAMEMASTER,     false, &ChatHandler::HandleMmapTestArea,               "", nullptr },
        { "connect",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMmapConnection,             "", nullptr },
        { "reload",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMmapLoad,                   "", nullptr },
        { "unload",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMmapUnload,                 "", nullptr },
        { "",               SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMmap,                       "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand videosCommandTable[] =
    {
        { "expendables",    SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugExp,                   "", nullptr },
        { "turn",           SEC_GAMEMASTER,     false, &ChatHandler::HandleVideoTurn,                  "", nullptr },
        { "",               SEC_GAMEMASTER,     false, &ChatHandler::HandleDebugExp,                   "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand anticheatClientCommandTable[] =
    {
        { "find",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleClientSearchCommand,        "", nullptr },
        { "",               SEC_GAMEMASTER,     true,  &ChatHandler::HandleClientInfosCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    static ChatCommand anticheatCommandTable[] =
    {
        { "server",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleAnticheatCommand,            "", nullptr },
        { "client",         SEC_GAMEMASTER,     true, nullptr,                                          "", anticheatClientCommandTable },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };
    static ChatCommand replayCommandTable[] =
    {
        { "play",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReplayPlayCommand,           "", nullptr },
        { "forward",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReplayForwardCommand,        "", nullptr },
        { "stop",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReplayStopCommand,           "", nullptr },
        { "record",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReplayRecordCommand,         "", nullptr },
        { "speed",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReplaySpeedCommand,          "", nullptr },
        { "",               SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReplayPlayCommand,           "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };
    static ChatCommand channelCommandTable[] =
    {
        { "join",           SEC_MODERATOR,      false, &ChatHandler::HandleChannelJoinCommand,          "", nullptr },
        { "leave",          SEC_MODERATOR,      false, &ChatHandler::HandleChannelLeaveCommand,         "", nullptr },
        { nullptr,          0,                  false, nullptr,                                         "", nullptr }
    };
    static ChatCommand ticketResponseCommandTable[] =
    {
        { "reset",          SEC_GAMEMASTER,     true,  &ChatHandler::HandleGMTicketResponseResetCommand,    "", nullptr },
        { "append",         SEC_TICKETMASTER,   true,  &ChatHandler::HandleGMTicketResponseAppendCommand,   "", nullptr },
        { "appendln",       SEC_TICKETMASTER,   true,  &ChatHandler::HandleGMTicketResponseAppendLnCommand, "", nullptr },
        { nullptr,          0,                  false, nullptr,                                             "", nullptr }
    };
    static ChatCommand ticketCommandTable[] =
    {
        { "assign",        SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketAssignToCommand,         "", nullptr },
        { "close",         SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketCloseByIdCommand,        "", nullptr },
        { "closedlist",    SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketListClosedCommand,       "", nullptr },
        { "counter",       SEC_TICKETMASTER,  false, &ChatHandler::HandleGMTicketCounterCommand,          "", nullptr },
        { "comment",       SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketCommentCommand,          "", nullptr },
        { "complete",      SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketCompleteCommand,         "", nullptr },
        { "delete",        SEC_GAMEMASTER,    true,  &ChatHandler::HandleGMTicketDeleteByIdCommand,       "", nullptr },
        { "escalate",      SEC_TICKETMASTER,  false, &ChatHandler::HandleGMTicketEscalateCommand,         "", nullptr },
        { "escalatedlist", SEC_GAMEMASTER,    true,  &ChatHandler::HandleGMTicketListEscalatedCommand,    "", nullptr },
        { "list",          SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketListCommand,             "", nullptr },
        { "next",          SEC_TICKETMASTER,  false, &ChatHandler::HandleGMTicketNextCommand,             "", nullptr },
        { "notify",        SEC_TICKETMASTER,  false, &ChatHandler::HandleGMTicketNotifyCommand,           "", nullptr },
        { "onlinelist",    SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketListOnlineCommand,       "", nullptr },
        { "previous",      SEC_TICKETMASTER,  false, &ChatHandler::HandleGMTicketPreviousCommand,         "", nullptr },
        { "reload",        SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketReloadCommand,           "", nullptr },
        { "reset",         SEC_ADMINISTRATOR, true,  &ChatHandler::HandleGMTicketResetCommand,            "", nullptr },
        { "response",      SEC_TICKETMASTER,  true,  nullptr,                          "", ticketResponseCommandTable },
        { "togglesystem",  SEC_ADMINISTRATOR, true,  &ChatHandler::HandleToggleGMTicketSystem,            "", nullptr },
        { "unassign",      SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketUnAssignCommand,         "", nullptr },
        { "viewid",        SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketGetByIdCommand,          "", nullptr },
        { "viewname",      SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketGetByNameCommand,        "", nullptr },
        { "",              SEC_TICKETMASTER,  true,  &ChatHandler::HandleGMTicketGetByIdOrNameCommand,    "", nullptr },
        { nullptr,         0,                 false, nullptr,                                             "", nullptr }
    };
    
    static ChatCommand serviceCommandTable[] =
    {
        { "del_characters",     SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServiceDeleteCharacters,   "", nullptr },
        { nullptr,              0,                  false, nullptr,                                       "", nullptr }
    };

    static ChatCommand spamerCommandTable[] =
    {
        { "mute",               SEC_MODERATOR,      true,  &ChatHandler::HandleSpamerMute,                "", nullptr },
        { "unmute",             SEC_TICKETMASTER,   true,  &ChatHandler::HandleSpamerUnmute,              "", nullptr },
        { "list",               SEC_TICKETMASTER,   true,  &ChatHandler::HandleSpamerList,                "", nullptr },
        { nullptr,              0,                  false, nullptr,                                       "", nullptr }
    };

Player* ChatHandler::GetPlayer() const { return m_session ? m_session->GetPlayer() : nullptr; }
    static ChatCommand AntiSpamCommandTable[] =
    {
        { "add",                SEC_TICKETMASTER,   true,  &ChatHandler::HandleAntiSpamAdd,                "", nullptr },
        { "remove",             SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleAntiSpamRemove,             "", nullptr },
        { "replace",            SEC_TICKETMASTER,   true,  &ChatHandler::HandleAntiSpamReplace,            "", nullptr },
        { "removereplace",      SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleAntiSpamRemoveReplace,      "", nullptr },
        { nullptr,              0,                  false, nullptr,                                        "", nullptr }
    };

char* ChatHandler::LineFromMessage(char*& pos)
{
    char* start = strtok(pos, "\n");
    pos = nullptr;
    return start;
}
    static ChatCommand goldCommandTable[] =
    {
        { "remove",             SEC_BASIC_ADMIN,    false, &ChatHandler::HandleGoldRemoval,               "", nullptr },
        { nullptr,              0,                  false, nullptr,                                       "", nullptr }
    };

    static ChatCommand commandTable[] =
    {
        { "account",        SEC_PLAYER,         true, nullptr,                                         "", accountCommandTable  },
        { "auction",        SEC_TICKETMASTER,   false, nullptr,                                        "", auctionCommandTable  },
        { "cast",           SEC_DEVELOPER,      false, nullptr,                                        "", castCommandTable     },
        { "character",      SEC_TICKETMASTER,   true, nullptr,                                         "", characterCommandTable},
        { "cheat",          SEC_GAMEMASTER,     false, nullptr,                                        "", cheatCommandTable    },
        { "debug",          SEC_TICKETMASTER,   true, nullptr,                                         "", debugCommandTable    },
        { "replenish",      SEC_GAMEMASTER,     false, &ChatHandler::HandleReplenishCommand,           "", nullptr              },
        { "replay",         SEC_ADMINISTRATOR,  false, nullptr,                                        "", replayCommandTable   },
        { "event",          SEC_GAMEMASTER,     false, nullptr,                                        "", eventCommandTable    },
        { "gm",             SEC_PLAYER,         true, nullptr,                                         "", gmCommandTable       },
        { "honor",          SEC_GAMEMASTER,     false, nullptr,                                        "", honorCommandTable    },
        { "go",             SEC_TICKETMASTER,   false, nullptr,                                        "", goCommandTable       },
        { "gobject",        SEC_TICKETMASTER,   false, nullptr,                                        "", gobjectCommandTable  },
        { "guild",          SEC_GAMEMASTER,     true, nullptr,                                         "", guildCommandTable    },
        { "instance",       SEC_TICKETMASTER,   true, nullptr,                                         "", instanceCommandTable },
        { "learn",          SEC_MODERATOR,      false, nullptr,                                        "", learnCommandTable    },
        { "list",           SEC_TICKETMASTER,   true, nullptr,                                         "", listCommandTable     },
        { "lookup",         SEC_MODERATOR,      true, nullptr,                                         "", lookupCommandTable   },
        { "modify",         SEC_TICKETMASTER,   false, nullptr,                                        "", modifyCommandTable   },
        { "npc",            SEC_MODERATOR,      false, nullptr,                                        "", npcCommandTable      },
        { "unit",           SEC_MODERATOR,      false, nullptr,                                        "", unitCommandTable     },
        { "pool",           SEC_GAMEMASTER,     true, nullptr,                                         "", poolCommandTable     },
        { "pdump",          SEC_ADMINISTRATOR,  true, nullptr,                                         "", pdumpCommandTable    },
        { "quest",          SEC_GAMEMASTER,     false, nullptr,                                        "", questCommandTable    },
        { "reload",         SEC_DEVELOPER,      true, nullptr,                                         "", reloadCommandTable   },
        { "reset",          SEC_GAMEMASTER,     true, nullptr,                                         "", resetCommandTable    },
        { "server",         SEC_PLAYER,         true, nullptr,                                         "", serverCommandTable   },
        { "tele",           SEC_TICKETMASTER,   true, nullptr,                                         "", teleCommandTable     },
        { "trigger",        SEC_TICKETMASTER,   false, nullptr,                                        "", triggerCommandTable  },
        { "wp",             SEC_TICKETMASTER,   false, nullptr,                                        "", wpCommandTable       },
        { "service",        SEC_ADMINISTRATOR,  true, nullptr,                                         "", serviceCommandTable  },
        { "bot",            SEC_ADMINISTRATOR,  true, nullptr,                              "Manage bots", botCommandTable      },
        { "ahbot",          SEC_ADMINISTRATOR,  true, nullptr,                            "Manage AH bot", ahbotCommandTable    },
        { "partybot",       SEC_ADMINISTRATOR,  false, nullptr,                       "Manage party bots", partyBotCommandTable },
        { "battlebot",      SEC_ADMINISTRATOR,  false, nullptr,                      "Manage battle bots", battleBotCommandTable},
        { "world",          SEC_ADMINISTRATOR,  false, nullptr,                                        "", worldCommandTable    },
        { "possess",        SEC_GAMEMASTER,     false, &ChatHandler::HandlePossessCommand,             "", nullptr              },
        { "cinematic",      SEC_DEVELOPER,      false, nullptr,                                        "", cinematicCommandTable},
        { "escort",         SEC_TICKETMASTER,   false, nullptr,                                        "", escortCommandTable   },
        { "worldstate",     SEC_ADMINISTRATOR,  false, nullptr,                                        "", worldStateCommandTable},
        { "bg",             SEC_GAMEMASTER,     false, nullptr,                                        "", bgCommandTable       },
        { "spell",          SEC_GAMEMASTER,     true, nullptr,                                         "", spellCommandTable    },
        { "variable",       SEC_DEVELOPER,      true,  &ChatHandler::HandleVariableCommand,            "", nullptr},
        { "aura",           SEC_BASIC_ADMIN,    false, &ChatHandler::HandleAuraCommand,                "", nullptr },
        { "nameaura",       SEC_BASIC_ADMIN,    false, &ChatHandler::HandleNameAuraCommand,            "", nullptr },
        { "unaura",         SEC_GAMEMASTER,     false, &ChatHandler::HandleUnAuraCommand,              "", nullptr },
        { "announce",       SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleAnnounceCommand,            "", nullptr },
        { "notify",         SEC_BASIC_ADMIN,    true,  &ChatHandler::HandleNotifyCommand,              "", nullptr },
        { "goname",         SEC_TICKETMASTER,   false, &ChatHandler::HandleGonameCommand,              "", nullptr },
        { "namego",         SEC_TICKETMASTER,   false, &ChatHandler::HandleNamegoCommand,              "", nullptr },
        { "group",          SEC_GAMEMASTER,     true, nullptr,                                         "", groupCommandTable },
        { "groupgo",        SEC_TICKETMASTER,   false, &ChatHandler::HandleGroupgoCommand,             "", nullptr },
        { "gocorpse",       SEC_TICKETMASTER,   false, &ChatHandler::HandleGocorpseCommand,            "", nullptr },
        { "commands",       SEC_PLAYER,         true,  &ChatHandler::HandleCommandsCommand,            "", nullptr },
        { "demorph",        SEC_GAMEMASTER,     false, &ChatHandler::HandleDeMorphCommand,             "", nullptr },
        { "namedie",        SEC_GAMEMASTER,     false, &ChatHandler::HandleNameDieCommand,             "", nullptr },
        { "die",            SEC_GAMEMASTER,     false, &ChatHandler::HandleDieCommand,                 "", nullptr },
        { "fear",           SEC_GAMEMASTER,     false, &ChatHandler::HandleFearCommand,                "", nullptr },
        { "knockback",      SEC_GAMEMASTER,     false, &ChatHandler::HandleKnockBackCommand,           "", nullptr },
        { "revive",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleReviveCommand,              "", nullptr },
        { "mount",          SEC_GAMEMASTER,     false, &ChatHandler::HandleMountCommand,               "", nullptr },
        { "dismount",       SEC_PLAYER,         false, &ChatHandler::HandleDismountCommand,            "", nullptr },
        { "gps",            SEC_MODERATOR,      false, &ChatHandler::HandleGPSCommand,                 "", nullptr },
        { "guid",           SEC_MODERATOR,      false, &ChatHandler::HandleGUIDCommand,                "", nullptr },
        { "help",           SEC_PLAYER,         true,  &ChatHandler::HandleHelpCommand,                "", nullptr },
        { "itemmove",       SEC_GAMEMASTER,     false, &ChatHandler::HandleItemMoveCommand,            "", nullptr },
        { "cooldown",       SEC_GAMEMASTER,     false, nullptr,                                        "", cooldownCommandTable },
        { "unlearn",        SEC_GAMEMASTER,     false, nullptr,                                        "", unlearnCommandTable },
        { "removeriding",   SEC_GAMEMASTER,     false, &ChatHandler::HandleRemoveRidingCommand,        "", nullptr },
        { "distance",       SEC_MODERATOR,      false, &ChatHandler::HandleGetDistanceCommand,         "", nullptr },
        { "angle",          SEC_MODERATOR,      false, &ChatHandler::HandleGetAngleCommand,            "", nullptr },
        { "recall",         SEC_MODERATOR,      false, &ChatHandler::HandleRecallCommand,              "", nullptr },
        { "save",           SEC_PLAYER,         false, &ChatHandler::HandleSaveCommand,                "", nullptr },
        { "wareffortget",   SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleGetWarEffortResource,       "", nullptr },
        { "wareffortset",   SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSetWarEffortResource,       "", nullptr },
        { "saveall",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSaveAllCommand,             "", nullptr },
        { "kick",           SEC_TICKETMASTER,   true,  &ChatHandler::HandleKickPlayerCommand,          "", nullptr },
        { "ban",            SEC_TICKETMASTER,   true, nullptr,                                         "", banCommandTable      },
        { "unban",          SEC_ADMINISTRATOR,  true, nullptr,                                         "", unbanCommandTable    },
        { "baninfo",        SEC_TICKETMASTER,   false, nullptr,                                        "", baninfoCommandTable  },
        { "banlist",        SEC_TICKETMASTER,   true, nullptr,                                         "", banlistCommandTable  },
        { "start",          SEC_PLAYER,         false, &ChatHandler::HandleStartCommand,               "", nullptr },
        { "unstuck",        SEC_PLAYER,         false, &ChatHandler::HandleUnstuckCommand,             "", nullptr },
        { "taxicheat",      SEC_TICKETMASTER,   false, &ChatHandler::HandleTaxiCheatCommand,           "", nullptr },
        { "linkgrave",      SEC_DEVELOPER,      false, &ChatHandler::HandleLinkGraveCommand,           "", nullptr },
        { "neargrave",      SEC_TICKETMASTER,   false, &ChatHandler::HandleNearGraveCommand,           "", nullptr },
        { "explorecheat",   SEC_TICKETMASTER,   false, &ChatHandler::HandleExploreCheatCommand,        "", nullptr },
        { "hover",          SEC_TICKETMASTER,   false, &ChatHandler::HandleHoverCommand,               "", nullptr },
        { "levelup",        SEC_GAMEMASTER,     false, &ChatHandler::HandleLevelUpCommand,             "", nullptr },
        { "showarea",       SEC_TICKETMASTER,   false, &ChatHandler::HandleShowAreaCommand,            "", nullptr },
        { "hidearea",       SEC_TICKETMASTER,   false, &ChatHandler::HandleHideAreaCommand,            "", nullptr },
        { "additem",        SEC_GAMEMASTER,     false, &ChatHandler::HandleAddItemCommand,             "", nullptr },
        { "deleteitem",     SEC_GAMEMASTER,     false, &ChatHandler::HandleDeleteItemCommand,          "", nullptr },
        { "additemset",     SEC_GAMEMASTER,     false, &ChatHandler::HandleAddItemSetCommand,          "", nullptr },
        { "bank",           SEC_TICKETMASTER,   false, &ChatHandler::HandleBankCommand,                "", nullptr },
        { "wchange",        SEC_BASIC_ADMIN,    false, &ChatHandler::HandleChangeWeatherCommand,       "", nullptr },
        { "ticket",         SEC_TICKETMASTER,   true, nullptr,                                         "", ticketCommandTable },
        { "maxskill",       SEC_GAMEMASTER,     false, &ChatHandler::HandleMaxSkillCommand,            "", nullptr },
        { "setskill",       SEC_GAMEMASTER,     false, &ChatHandler::HandleSetSkillCommand,            "", nullptr },
        { "whispers",       SEC_MODERATOR,      false, &ChatHandler::HandleWhispersCommand,            "", nullptr },
        { "wr",             SEC_PLAYER,         false, &ChatHandler::HandleWhisperRestrictionCommand,  "", nullptr },
        { "pinfo",          SEC_TICKETMASTER,   false, &ChatHandler::HandlePInfoCommand,               "", nullptr },
        { "groupinfo",      SEC_TICKETMASTER,   true,  &ChatHandler::HandleGroupInfoCommand,           "", nullptr },
        { "pbcast",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandlePBCastStatsCommand,         "", pbcastCommandTable },
        { "addons",         SEC_GAMEMASTER,     false, &ChatHandler::HandleListAddonsCommand,          "", nullptr },
        { "respawn",        SEC_BASIC_ADMIN,    false, &ChatHandler::HandleRespawnCommand,             "", nullptr },
        { "send",           SEC_MODERATOR,      true, nullptr,                                         "", sendCommandTable     },
        { "mute",           SEC_MODERATOR,      true,  &ChatHandler::HandleMuteCommand,                "", nullptr },
        { "unmute",         SEC_TICKETMASTER,   true,  &ChatHandler::HandleUnmuteCommand,              "", nullptr },
        { "movegens",       SEC_TICKETMASTER,   false, &ChatHandler::HandleMovegensCommand,            "", nullptr },
        { "cometome",       SEC_GAMEMASTER,     false, &ChatHandler::HandleComeToMeCommand,            "", nullptr },
        { "aoedamage",      SEC_GAMEMASTER,     false, &ChatHandler::HandleAoEDamageCommand,              "", nullptr },
        { "damage",         SEC_GAMEMASTER,     false, &ChatHandler::HandleDamageCommand,              "", nullptr },
        { "combatstop",     SEC_GAMEMASTER,     false, &ChatHandler::HandleCombatStopCommand,          "", nullptr },
        { "repairitems",    SEC_GAMEMASTER,     true,  &ChatHandler::HandleRepairitemsCommand,         "", nullptr },
        { "stable",         SEC_TICKETMASTER,   false, &ChatHandler::HandleStableCommand,              "", nullptr },
        { "quit",           SEC_CONSOLE,        true,  &ChatHandler::HandleQuitCommand,                "", nullptr },
        { "mmap",           SEC_GAMEMASTER,     false, nullptr,                                        "", mmapCommandTable },
        { "video",          SEC_GAMEMASTER,     false, nullptr,                                        "", videosCommandTable },
        { "freeze",         SEC_TICKETMASTER,   false, &ChatHandler::HandleFreezeCommand,              "", nullptr },
        { "unfreeze",       SEC_TICKETMASTER,   false, &ChatHandler::HandleUnfreezeCommand,            "", nullptr },
        { "anticheat",      SEC_GAMEMASTER,     false, nullptr,                                        "", anticheatCommandTable },
        { "groupspell",     SEC_ADMINISTRATOR,  true, nullptr,                                         "", groupSpellCommandTable},
        { "pet",            SEC_GAMEMASTER,     true, nullptr,                                         "", petCommandTable},
        { "channel",        SEC_MODERATOR,      false, nullptr,                                        "", channelCommandTable},
        { "log",            SEC_GAMEMASTER,     true,  &ChatHandler::HandleViewLogCommand,             "", nullptr },
        { "spamer",         SEC_MODERATOR,      true, nullptr,                                         "", spamerCommandTable },
        { "antispam",       SEC_TICKETMASTER,   true, nullptr,                                         "", AntiSpamCommandTable },
        { "gold",           SEC_BASIC_ADMIN,    true, nullptr,                                         "", goldCommandTable },
        { nullptr,          0,                  false, nullptr,                                        "", nullptr }
    };

    if (load_command_table)
    {
        load_command_table = false;

        // check hardcoded part integrity
        //CheckIntegrity(commandTable, nullptr);
        FillFullCommandsName(commandTable, "");

        QueryResult* result = WorldDatabase.Query("SELECT `name`, `security`, `help`, `flags` FROM `command`");
        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                std::string name = fields[0].GetCppString();

                SetDataForCommandInTable(commandTable, name.c_str(), fields[1].GetUInt8(), fields[2].GetCppString(), fields[3].GetUInt8());

            }
            while (result->NextRow());
            delete result;
        }
    }

    return commandTable;
}

ChatHandler::ChatHandler(WorldSession* session) :
    m_session(session), sentErrorMessage(false)
{
}

char const* ChatHandler::GetTrinityString(uint32 entry) const
ChatHandler::ChatHandler(Player* player) : ChatHandler(player->GetSession()) {}

ChatHandler::~ChatHandler() {}

char const* ChatHandler::GetMangosString(int32 entry) const
{
    return m_session->GetMangosString(entry);
}

char const* ChatHandler::GetOnOffStr(bool value) const
{
    return value ?  GetMangosString(LANG_ON) : GetMangosString(LANG_OFF);
}

uint32 ChatHandler::GetAccountId() const
{
    return m_session->GetAccountId();
}

bool ChatHandler::HasPermission(uint32 permission) const
AccountTypes ChatHandler::GetAccessLevel() const
{
    return m_session->GetSecurity();
}

bool ChatHandler::isAvailable(ChatCommand const& cmd) const
{
    // check security level only for simple  command (without child commands)
    return GetAccessLevel() >= (AccountTypes)cmd.SecurityLevel;
}

std::string ChatHandler::GetNameLink() const
{
    return GetNameLink(m_session->GetPlayer());
}

bool ChatHandler::HasLowerSecurity(Player* target, ObjectGuid guid, bool strong)
{
    WorldSession* target_session = nullptr;
    uint32 target_account = 0;

    if (target)
        target_session = target->GetSession();
    else if (guid)
        target_account = sObjectMgr.GetPlayerAccountIdByGUID(guid);

    if (!target_session && !target_account)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return true;
    }

    return HasLowerSecurityAccount(target_session, target_account, strong);
}

bool ChatHandler::HasLowerSecurityAccount(WorldSession* target, uint32 target_account, bool strong)
{
    AccountTypes target_sec;

    // ignore only for non-players for non strong checks (when allow apply command at least to same sec level)
    if (GetAccessLevel() > SEC_PLAYER && !strong && !sWorld.getConfig(CONFIG_BOOL_GM_LOWER_SECURITY))
        return false;

    if (target)
        target_sec = target->GetSecurity();
    else if (target_account)
        target_sec = sAccountMgr.GetSecurity(target_account);
    else
        return true;                                        // caller must report error for (target==nullptr && target_account==0)

    if (GetAccessLevel() < target_sec || (strong && GetAccessLevel() <= target_sec))
    {
        SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
        SetSentErrorMessage(true);
        return true;
    }

    return false;
}

void ChatHandler::SendSysMessage(std::string_view str, bool escapeCharacters)
bool ChatHandler::hasStringAbbr(char const* name, char const* part)
{
    std::string msg{ str };

    // Replace every "|" with "||" in msg
    if (escapeCharacters && msg.find('|') != std::string::npos)
    {
        std::vector<std::string_view> tokens = Trinity::Tokenize(msg, '|', true);
        std::ostringstream stream;
        for (size_t i = 0; i < tokens.size() - 1; ++i)
            stream << tokens[i] << "||";
        stream << tokens[tokens.size() - 1];
        for (;;)
        {
            if (!*part)
                return true;
            else if (!*name)
                return false;
            else if (tolower(*name) != tolower(*part))
                return false;
            ++name;
            ++part;
        }
    }
    // allow with any for ""

        msg = stream.str();
    }

    WorldPackets::Chat::Chat packet;
    for (std::string_view line : Trinity::Tokenize(str, '\n', true))
    {
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        m_session->SendPacket(packet.Write());
    }
void ChatHandler::SendSysMessage(char const* str)
{
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = mangos_strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, line);
        m_session->SendPacket(&data);
    }

    delete [] buf;
    SetSentErrorMessage(true);
}

void ChatHandler::SendGlobalSysMessage(char const* str)
{
    // Chat output
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = mangos_strdup(str);
    char* pos = buf;

    while (char* line = LineFromMessage(pos))
    {
        ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, line);
        sWorld.SendGlobalMessage(&data);
    }

    delete [] buf;
}

void ChatHandler::SendSysMessage(int32 entry)
{
    SendSysMessage(GetMangosString(entry));
}

void ChatHandler::PSendSysMessage(int32 entry, ...)
{
    WorldPackets::Chat::Chat packet;
    for (std::string_view line : Trinity::Tokenize(str, '\n', true))
    {
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        sWorld->SendGlobalMessage(packet.Write());
    }
    char const* format = GetMangosString(entry);
    va_list ap;
    char str [2048];
    va_start(ap, entry);
    vsnprintf(str, 2048, format, ap);
    va_end(ap);
    SendSysMessage(str);
}

void ChatHandler::PSendSysMessage(char const* format, ...)
{
    va_list ap;
    char str [2048];
    va_start(ap, format);
    vsnprintf(str, 2048, format, ap);
    va_end(ap);
    SendSysMessage(str);
}

std::string ChatHandler::PGetParseString(int32 entry, ...)
{
    char const* format = GetMangosString(entry);
    va_list ap;
    char str [2048];
    va_start(ap, entry);
    vsnprintf(str, 2048, format, ap);
    va_end(ap);
    return std::string(str);
}

void ChatHandler::FillFullCommandsName(ChatCommand* table, std::string prefix)
{
    for (uint32 i = 0; table[i].Name != nullptr; ++i)
    {
        std::string newPrefix = prefix;
        if (!newPrefix.empty())
            newPrefix += " ";
        newPrefix += table[i].Name;
        table[i].FullName = newPrefix;
        if (table[i].ChildCommands)
            FillFullCommandsName(table[i].ChildCommands, newPrefix);

    }
}

void ChatHandler::SendGlobalGMSysMessage(const char *str)
{
    WorldPackets::Chat::Chat packet;
    for (std::string_view line : Trinity::Tokenize(str, '\n', true))
    {
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        sWorld->SendGlobalGMMessage(packet.Write());
    }
void ChatHandler::CheckIntegrity(ChatCommand *table, ChatCommand *parentCommand)
{
    for (uint32 i = 0; table[i].Name != nullptr; ++i)
    {
        ChatCommand* command = &table[i];

        if (parentCommand && command->SecurityLevel < parentCommand->SecurityLevel)
            sLog.outError("Subcommand '%s' of command '%s' have less access level (%hhu) that parent (%hhu)",
                          command->Name, parentCommand->Name, command->SecurityLevel, parentCommand->SecurityLevel);

        if (!parentCommand && strlen(command->Name) == 0)
            sLog.outError("Subcommand '' at top level");

        if (command->ChildCommands)
        {
            if (command->Handler)
            {
                if (parentCommand)
                    sLog.outError("Subcommand '%s' of command '%s' have handler and subcommands in same time, must be used '' subcommand for handler instead.",
                                  command->Name, parentCommand->Name);
                else
                    sLog.outError("First level command '%s' have handler and subcommands in same time, must be used '' subcommand for handler instead.",
                                  command->Name);
            }

            if (parentCommand && strlen(command->Name) == 0)
                sLog.outError("Subcommand '' of command '%s' have subcommands", parentCommand->Name);

            CheckIntegrity(command->ChildCommands, command);
        }
        else if (!command->Handler)
        {
            if (parentCommand)
                sLog.outError("Subcommand '%s' of command '%s' not have handler and subcommands in same time. Must have some from its!",
                              command->Name, parentCommand->Name);
            else
                sLog.outError("First level command '%s' not have handler and subcommands in same time. Must have some from its!",
                              command->Name);
        }
    }
}

/**
 * Search (sub)command for command line available for chat handler access level
 *
 * @param text  Command line string that will parsed for (sub)command search
 *
 * @return Pointer to found command structure or nullptr if appropriate command not found
 */
ChatCommand const* ChatHandler::FindCommand(char const* text)
{
    ChatCommand* command = nullptr;
    char const* textPtr = text;

    return FindCommand(getCommandTable(), textPtr, command) == CHAT_COMMAND_OK ? command : nullptr;
}

bool ChatHandler::_ParseCommands(std::string_view text)
/**
 * Search (sub)command for command line available for chat handler access level with options and fail case additional info
 *
 * @param table         Pointer to command C-style array first level command where will be searched
 * @param text          Command line string that will parsed for (sub)command search,
 *                      it modified at return from function and pointed to not parsed tail
 * @param command       At success this is found command, at other cases this is last found parent command
 *                      before subcommand search fail
 * @param parentCommand Output arg for optional return parent command for command arg.
 * @param cmdNamePtr    Output arg for optional return last parsed command name.
 * @param allAvailable  Optional arg (with false default value) control use command access level checks while command search.
 * @param exactlyName   Optional arg (with false default value) control use exactly name in checks while command search.
 *
 * @return one from enum value of ChatCommandSearchResult. Output args return values highly dependent from this return result:
 *
 *      CHAT_COMMAND_OK       - Command found!
 *                              text point to non parsed tail with possible command specific data, command store found command pointer,
 *                              parentCommand have parent of found command or nullptr if command found in table array directly
 *                              cmdNamePtr store found command name in original form from command line
 *      CHAT_COMMAND_UNKNOWN  - Command not found in table directly
 *                              text only skip possible whitespaces,
 *                              command is nullptr
 *                              parentCommand is nullptr
 *                              cmdNamePtr store command name that not found as it extracted from command line
 *      CHAT_COMMAND_UNKNOWN_SUBCOMMAND - Subcommand not found in some deed subcomand lists
 *                              text point to non parsed tail including not found command name in command line,
 *                              command store last found parent command if any
 *                              parentCommand have parent of command in command arg or nullptr
 *                              cmdNamePtr store command name that not found as it extracted from command line
 */
ChatCommandSearchResult ChatHandler::FindCommand(ChatCommand* table, char const* &text, ChatCommand*& command, ChatCommand** parentCommand /*= nullptr*/, std::string* cmdNamePtr /*= nullptr*/, bool allAvailable /*= false*/, bool exactlyName /*= false*/)
{
    if (Trinity::ChatCommands::TryExecuteCommand(*this, text))
        return true;
    std::string cmd;

    // skip whitespaces
    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        ++text;
    }

    while (*text == ' ') ++text;

    // search first level command in table
    for (uint32 i = 0; table[i].Name != nullptr; ++i)
    {
        if (exactlyName)
        {
            size_t len = strlen(table[i].Name);
            if (strncmp(table[i].Name, cmd.c_str(), len + 1) != 0)
                continue;
        }
        else
        {
            if (!hasStringAbbr(table[i].Name, cmd.c_str()))
                continue;
        }
        // select subcommand from child commands list
        if (table[i].ChildCommands != nullptr)
        {
            char const* oldchildtext = text;
            ChatCommand* parentSubcommand = nullptr;
            ChatCommandSearchResult res = FindCommand(table[i].ChildCommands, text, command, &parentSubcommand, cmdNamePtr, allAvailable, exactlyName);

            switch (res)
            {
                case CHAT_COMMAND_OK:
                {
                    // if subcommand success search not return parent command, then this parent command is owner of child commands
                    if (parentCommand)
                        *parentCommand = parentSubcommand ? parentSubcommand : &table[i];

                    // Name == "" is special case: restore original command text for next level "" (where parentSubcommand==nullptr)
                    if (strlen(command->Name) == 0 && !parentSubcommand)
                        text = oldchildtext;

                    return CHAT_COMMAND_OK;
                }
                case CHAT_COMMAND_UNKNOWN:
                {
                    // command not found directly in child command list, return child command list owner
                    command = &table[i];
                    if (parentCommand)
                        *parentCommand = nullptr;              // we don't known parent of table list at this point

                    text = oldchildtext;                    // restore text to stated just after parse found parent command
                    return CHAT_COMMAND_UNKNOWN_SUBCOMMAND; // we not found subcommand for table[i]
                }
                case CHAT_COMMAND_UNKNOWN_SUBCOMMAND:
                default:
                {
                    // some deep subcommand not found, if this second level subcommand then parentCommand can be nullptr, use known value for it
                    if (parentCommand)
                        *parentCommand = parentSubcommand ? parentSubcommand : &table[i];
                    return res;
                }
            }
        }

        // must be available (not checked for subcommands case because parent command expected have most low access that all subcommands always
        if (!allAvailable && !isAvailable(table[i]))
            continue;

        // must be have handler is explicitly selected
        if (!table[i].Handler)
            continue;

        // command found directly in to table
        command = &table[i];

        // unknown table owner at this point
        if (parentCommand)
            *parentCommand = nullptr;

        if (cmdNamePtr)
            *cmdNamePtr = cmd;

        return CHAT_COMMAND_OK;
    }

    // command not found in table directly
    command = nullptr;

    // unknown table owner at this point
    if (parentCommand)
        *parentCommand = nullptr;

    if (cmdNamePtr)
        *cmdNamePtr = cmd;

    return CHAT_COMMAND_UNKNOWN;
}

/**
 * Execute (sub)command available for chat handler access level with options in command line string
 *
 * @param text  Command line string that will parsed for (sub)command search and command specific data
 *
 * Command output and errors in command execution will send to chat handler.
 */
void ChatHandler::ExecuteCommand(char const* text)
{
    std::string fullcmd = text;                             // original `text` can't be used. It content destroyed in command code processing.

    ChatCommand* command = nullptr;
    ChatCommand* parentCommand = nullptr;

    ChatCommandSearchResult res = FindCommand(getCommandTable(), text, command, &parentCommand);

    switch (res)
    {
        case CHAT_COMMAND_OK:
        {
            std::string realCommandFull = command->FullName;

            if (text[0])
            {
                realCommandFull += " ";
                realCommandFull += text;
            }
            if (m_session && command->Flags & COMMAND_FLAGS_ONLY_ON_SELF)
            {
                ObjectGuid selGuid = m_session->GetPlayer()->GetSelectionGuid();
                if (!selGuid.IsEmpty() && selGuid != m_session->GetPlayer()->GetObjectGuid())
                {
                    PSendSysMessage("|cFF8DE2FFYou can use the command [%s] only on yourself|r", command->FullName.c_str());
                    return;
                }
            }
            SetSentErrorMessage(false);

            // Always log GM commands, regardless of success
            if (command->SecurityLevel > SEC_PLAYER)
            {
                // chat case
                if (m_session && m_session->GetPlayer())
                {
                    Player* p = m_session->GetPlayer();
                    ObjectGuid sel_guid = p->GetSelectionGuid();
                    sLog.outCommand(GetAccountId(), "Command: %s [Player: %s (Group Leader \"%s\", Account: %u) X: %f Y: %f Z: %f Map: %u Selected: %s]",
                        realCommandFull.c_str(), p->GetName(), p->GetGroup() ? p->GetGroup()->GetLeaderGuid().GetString().c_str() : "NULL", GetAccountId(), p->GetPositionX(), p->GetPositionY(), p->GetPositionZ(), p->GetMapId(),
                        sel_guid.GetString().c_str());
                }
                else                                        // 0 account -> console
                {
                    sLog.outCommand(GetAccountId(), "Command: %s [Account: %u from %s]",
                        realCommandFull.c_str(), GetAccountId(), GetAccountId() ? "RA-connection" : "Console");
                }
            }

            if ((this->*(command->Handler))((char*)text))   // text content destroyed at call
            {
                if (m_session && command->Flags & COMMAND_FLAGS_CRITICAL)
                {
                    if (Unit* target = GetSelectedUnit())
                        sLog.out(LOG_GM_CRITICAL, "%s: %s. Selected %s. Map %u", m_session->GetUsername().c_str(), realCommandFull.c_str(), target->GetObjectGuid().GetString().c_str(), target->GetMapId());
                    else
                        sLog.out(LOG_GM_CRITICAL, "%s: %s.", m_session->GetUsername().c_str(), realCommandFull.c_str());
                }
            }
            // some commands have custom error messages. Don't send the default one in these cases.
            else if (!HasSentErrorMessage())
            {
                if (!command->Help.empty())
                    SendSysMessage(command->Help.c_str());
                else
                    SendSysMessage(LANG_CMD_SYNTAX);

                if (ChatCommand* showCommand = (strlen(command->Name) == 0 && parentCommand ? parentCommand : command))
                    if (ChatCommand* childs = showCommand->ChildCommands)
                        ShowHelpForSubCommands(childs, showCommand->Name);

                SetSentErrorMessage(true);
            }
            break;
        }
        case CHAT_COMMAND_UNKNOWN_SUBCOMMAND:
        {
            SendSysMessage(LANG_NO_SUBCMD);
            ShowHelpForCommand(command->ChildCommands, text);
            SetSentErrorMessage(true);
            break;
        }
        case CHAT_COMMAND_UNKNOWN:
        {
            SendSysMessage(LANG_NO_CMD);
            SetSentErrorMessage(true);
            break;
        }
    }
}

/**
 * Function find appropriate command and update command security level and help text
 *
 * @param commandTable  Table for first level command search
 * @param text          Command line string that will parsed for (sub)command search
 * @param security      New security level for command
 * @param help          New help text  for command
 *
 * @return true if command has been found, and false in other case
 *
 * All problems found while command search and updated output as to DB errors log
 */
bool ChatHandler::SetDataForCommandInTable(ChatCommand *commandTable, char const* text, uint8 security, std::string const& help, uint8 flags)
{
    std::string fullcommand = text;                         // original `text` can't be used. It content destroyed in command code processing.

    ChatCommand* command = nullptr;
    std::string cmdName;

    ChatCommandSearchResult res = FindCommand(commandTable, text, command, nullptr, &cmdName, true, true);

    switch (res)
    {
        case CHAT_COMMAND_OK:
        {
            if (command->SecurityLevel != security)
                DETAIL_LOG("Table `command` overwrite for command '%s' default security (%hhu) by %hhu",
                           fullcommand.c_str(), command->SecurityLevel, security);

            command->SecurityLevel = security;
            command->Help          = help;
            command->Flags         = flags;
            return true;
        }
        case CHAT_COMMAND_UNKNOWN_SUBCOMMAND:
        {
            // command have subcommands, but not '' subcommand and then any data in `command` useless for it.
            if (cmdName.empty())
                sLog.outErrorDb("Table `command` have command '%s' that only used with some subcommand selection, it can't have help or overwritten access level, skip.", cmdName.c_str());
            else
                sLog.outErrorDb("Table `command` have unexpected subcommand '%s' in command '%s', skip.", cmdName.c_str(), fullcommand.c_str());
            return false;
        }
        case CHAT_COMMAND_UNKNOWN:
        {
            sLog.outErrorDb("Table `command` have nonexistent command '%s', skip.", cmdName.c_str());
            return false;
        }
    }

    return false;
}

bool ChatHandler::ParseCommands(char const* text)
{
    MANGOS_ASSERT(text);
    MANGOS_ASSERT(*text);

    /// chat case (.command or !command format)
    if (m_session)
    {
        if (text[0] != '!' && text[0] != '.')
            return false;

        /// ignore single . and ! in line
        if (strlen(text) < 2)
            return false;

        if (m_session->GetSecurity() == SEC_PLAYER && !sWorld.getConfig(CONFIG_BOOL_PLAYER_COMMANDS))
            return false;
    }

    /// ignore messages staring from many dots.
    if ((text[0] == '.' && text[1] == '.') || (text[0] == '!' && text[1] == '!'))
        return false;

    /// skip first . or ! (in console allowed use command with . and ! and without its)
    if (text[0] == '!' || text[0] == '.')
        ++text;

    ExecuteCommand(text);

    return true;
}

    // Pretend commands don't exist for regular players
    if (m_session && !m_session->HasPermission(rbac::RBAC_PERM_COMMANDS_NOTIFY_COMMAND_NOT_FOUND_ERROR))
        return false;
bool ChatHandler::ShowHelpForSubCommands(ChatCommand *table, char const* cmd)
{
    std::string list;
    for (uint32 i = 0; table[i].Name != nullptr; ++i)
    {
        // must be available (ignore handler existence for show command with possible available subcommands
        if (!isAvailable(table[i]))
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
        SendSysMessage(list.c_str());
    }
    else
    {
        PSendSysMessage(LANG_SUBCMDS_LIST, cmd);
        SendSysMessage(list.c_str());
    }
    return true;
}

bool ChatHandler::ShowHelpForCommand(ChatCommand *table, char const* cmd)
{
    char const* oldCmd = cmd;
    ChatCommand* command = nullptr;
    ChatCommand* parentCommand = nullptr;

    ChatCommand* showCommand = nullptr;
    ChatCommand* childCommands = nullptr;

    // Send error message for GMs
    PSendSysMessage(LANG_CMD_INVALID, STRING_VIEW_FMT_ARG(text));
    SetSentErrorMessage(true);
    return true;
}
    ChatCommandSearchResult res = FindCommand(table, cmd, command, &parentCommand);

bool ChatHandler::ParseCommands(std::string_view text)
{
    ASSERT(!text.empty());
    switch (res)
    {
        case CHAT_COMMAND_OK:
        {
            // for "" subcommand use parent command if any for subcommands list output
            if (strlen(command->Name) == 0 && parentCommand)
                showCommand = parentCommand;
            else
                showCommand = command;

            childCommands = showCommand->ChildCommands;
            break;
        }
        case CHAT_COMMAND_UNKNOWN_SUBCOMMAND:
            showCommand = command;
            childCommands = showCommand->ChildCommands;
            break;
        case CHAT_COMMAND_UNKNOWN:
            // not show command list at error in first level command find fail
            childCommands = table != getCommandTable() || strlen(oldCmd) == 0 ? table : nullptr;
            command = nullptr;
            break;
    }

    // chat case (.command or !command format)
    if ((text[0] != '!') && (text[0] != '.'))
        return false;
    if (command && !command->Help.empty())
        SendSysMessage(command->Help.c_str());

    // ignore single . and ! in line
    if (text.length() < 2)
        return false;
    if (childCommands)
        if (ShowHelpForSubCommands(childCommands, showCommand ? showCommand->Name : ""))
            return true;

    // ignore messages staring from many dots.
    if (text[1] == text[0])
        return false;
    if (command && command->Help.empty())
        SendSysMessage(LANG_NO_HELP_CMD);

    // ignore messages with separator after .
    if (text[1] == Trinity::Impl::ChatCommands::COMMAND_DELIMITER)
    return command || childCommands;
}

bool ChatHandler::isValidChatMessage(char const* message)
{
    /*

    valid examples:
    |cffa335ee|Hitem:812:0:0:0:0:0:0:0:70|h[Glowing Brightwood Staff]|h|r
    |cff808080|Hquest:2278:47|h[The Platinum Discs]|h|r
    |cff4e96f7|Htalent:2232:-1|h[Taste for Blood]|h|r
    |cff71d5ff|Hspell:21563|h[Command]|h|r
    |cffffd000|Henchant:3919|h[Engineering: Rough Dynamite]|h|r

    | will be escaped to ||
    */

    if (strlen(message) > 255)
        return false;

    return _ParseCommands(text.substr(1));
}
    char const validSequence[6] = "cHhhr";
    char const* validSequenceIterator = validSequence;

    // more simple checks
    if (sWorld.getConfig(CONFIG_UINT32_CHAT_STRICT_LINK_CHECKING_SEVERITY) < 3)
    {
        std::string const validCommands = "cHhr|";

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
            if (sWorld.getConfig(CONFIG_UINT32_CHAT_STRICT_LINK_CHECKING_SEVERITY) == 2)
            {
                if (commandChar == *validSequenceIterator)
                {
                    if (validSequenceIterator == validSequence + 4)
                        validSequenceIterator = validSequence;
                    else
                        ++validSequenceIterator;
                }
                else if (commandChar != '|')
                    return false;
            }
        }
        return true;
    }

    std::istringstream reader(message);
    char buffer[256];

    uint32 color = 0;

    ItemPrototype const* linkedItem = nullptr;
    SpellEntry const* linkedSpell = nullptr;

    std::list<int> properties;

    while (!reader.eof())
    {
        if (validSequence == validSequenceIterator)
        {
            linkedItem = nullptr;

            reader.ignore(255, '|');
        }
        else if (reader.get() != '|')
        {
            DEBUG_LOG("ChatHandler::isValidChatMessage sequence aborted unexpectedly");
            return false;
        }

        // pipe has always to be followed by at least one char
        if (reader.peek() == '\0')
        {
            DEBUG_LOG("ChatHandler::isValidChatMessage pipe followed by \\0");
            return false;
        }

        // no further pipe commands
        if (reader.eof())
            break;

        char commandChar;
        reader >> std::noskipws >> commandChar;

        // | in normal messages is escaped by ||
        if (commandChar != '|')
        {
            if (commandChar == *validSequenceIterator)
            {
                if (validSequenceIterator == validSequence + 4)
                    validSequenceIterator = validSequence;
                else
                    ++validSequenceIterator;
            }
            else
            {
                DEBUG_LOG("ChatHandler::isValidChatMessage invalid sequence, expected %c but got %c", *validSequenceIterator, commandChar);
                return false;
            }
        }
        else if (validSequence != validSequenceIterator)
        {
            // no escaped pipes in sequences
            DEBUG_LOG("ChatHandler::isValidChatMessage got escaped pipe in sequence");
            return false;
        }

        switch (commandChar)
        {
            case 'c':
                color = 0;
                // validate color, expect 8 hex chars
                for (int i = 0; i < 8; i++)
                {
                    char c;
                    reader >> c;
                    if (!c)
                    {
                        DEBUG_LOG("ChatHandler::isValidChatMessage got \\0 while reading color in |c command");
                        return false;
                    }

                    color <<= 4;
                    // check for hex char
                    if (c >= '0' && c <= '9')
                    {
                        color |= c - '0';
                        continue;
                    }
                    if (c >= 'a' && c <= 'f')
                    {
                        color |= 10 + c - 'a';
                        continue;
                    }
                    DEBUG_LOG("ChatHandler::isValidChatMessage got non hex char '%c' while reading color", c);
                    return false;
                }
                break;
            case 'H':
                // read chars up to colon  = link type
                reader.getline(buffer, 256, ':');
                if (reader.eof())                           // : must be
                    return false;

Player* ChatHandler::getSelectedPlayer()
{
    if (!m_session)
        return nullptr;
                if (strcmp(buffer, "item") == 0)
                {
                    // read item entry
                    reader.getline(buffer, 256, ':');
                    if (reader.eof())                       // : must be
                        return false;

                    linkedItem = ObjectMgr::GetItemPrototype(atoi(buffer));
                    if (!linkedItem)
                    {
                        DEBUG_LOG("ChatHandler::isValidChatMessage got invalid itemID %u in |item command", atoi(buffer));
                        return false;
                    }

                    if (color != ItemQualityColors[linkedItem->Quality])
                    {
                        DEBUG_LOG("ChatHandler::isValidChatMessage linked item has color %u, but user claims %u", ItemQualityColors[linkedItem->Quality],
                                  color);
                        return false;
                    }

                    // the itementry is followed by several integers which describe an instance of this item
                    int32 propertyId = 0, propCount = 0;
                    bool negativeNumber = false;
                    char c = 0;
                    while (reader.peek() != '|' && !reader.eof() && propCount < 3)
                    {
                        c = reader.get();

                        // Reset at the property switch
                        if (c == ':')
                        {
                            if (negativeNumber)
                                propertyId *= -1;

                            ++propCount;
                            // Only check if it's a non-zero prop
                            if (propertyId > 0)
                                properties.push_back(propertyId);

                            propertyId = 0;
                            negativeNumber = false;

                            continue;
                        }

                        if (c >= '0' && c <= '9')
                        {
                            propertyId *= 10;
                            propertyId += c - '0';
                        }
                        else if (c == '-')
                            negativeNumber = true;
                        else
                            return false;
                    }

                    // ignore other integers
                    c = reader.peek();
                    while (((c >= '0' && c <= '9') || c == ':') && c != '|' && !reader.eof())
                    {
                        reader.ignore(1);
                        c = reader.peek();
                    }
                }
                else if (strcmp(buffer, "enchant") == 0)
                {
                    if (color != CHAT_LINK_COLOR_ENCHANT)
                        return false;

                    uint32 spellid = 0;
                    // read spell entry
                    char c = reader.peek();
                    while (c >= '0' && c <= '9')
                    {
                        reader.ignore(1);
                        spellid *= 10;
                        spellid += c - '0';
                        c = reader.peek();
                    }
                    linkedSpell = sSpellMgr.GetSpellEntry(spellid);
                    if (!linkedSpell)
                        return false;
                }
                else
                {
                    DEBUG_LOG("ChatHandler::isValidChatMessage user sent unsupported link type '%s'", buffer);
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
                        DEBUG_LOG("ChatHandler::isValidChatMessage link caption doesn't start with '['");
                        return false;
                    }
                    reader.getline(buffer, 256, ']');
                    if (reader.eof())                       // ] must be
                        return false;

                    // verify the link name
                    if (linkedSpell)
                    {
                        bool foundName = false;
                        for (uint8 i = 0; i < MAX_DBC_LOCALE; ++i)
                        {
                            if (!linkedSpell->SpellName[i].empty() && strcmp(linkedSpell->SpellName[i].c_str(), buffer) == 0)
                            {
                                foundName = true;
                                break;
                            }
                        }
                        if (!foundName)
                            return false;
                    }
                    else if (linkedItem)
                    {
                        bool hasValidRandomProperty = false;
                        bool hasRandomProperty = linkedItem->RandomProperty > 0;
                        int enchantCount = 0;

                        // Item has no random property. All properties must be enchants, of which
                        // there can only be two. One permanent, one temporary
                        if (!hasRandomProperty && properties.size() > 2)
                            return false;

                        ItemRandomPropertiesEntry const* iProp = nullptr;
                        for (const auto prop : properties)
                        {
                            iProp = nullptr;

                            if (!hasRandomProperty)
                            {
                                if (sSpellItemEnchantmentStore.LookupEntry(prop))
                                    ++enchantCount;
                                else
                                    return false;
                            }
                            else
                            {
                                // This is tricky - some enchants and random properties share IDs!
                                // do we just compare all of the names?
                                if (!hasValidRandomProperty)
                                    iProp = sItemRandomPropertiesStore.LookupEntry(prop);

                                // Check if we have a valid random property with this prop...
                                if (iProp)
                                {
                                    // Compare the name. If the name isn't correct, maybe it's an enchantment instead.
                                    for (int localeIndex = DB_LOCALE_enUS; localeIndex <= DB_LOCALE_ruRU; ++localeIndex)
                                    {
                                        std::string expectedName = linkedItem->Name1;
                                        Item::GetLocalizedNameWithSuffix(expectedName, linkedItem, iProp, localeIndex, GetDbcLocaleFromDbLocale(DBLocaleConstant(localeIndex)));
                                        if (expectedName == buffer)
                                        {
                                            hasValidRandomProperty = true;
                                            break;
                                        }
                                    }
                                }

                                // Still don't have a valid random prop. If it's an enchantment, inc count.
                                // Else this property is entirely invalid.
                                if (!hasValidRandomProperty)
                                {
                                    if (sSpellItemEnchantmentStore.LookupEntry(prop))
                                        ++enchantCount;
                                    else
                                        return false;
                                }
                            }

                            if (enchantCount > 2)
                                return false;
                        }

                        if (hasRandomProperty && !hasValidRandomProperty)
                            return false;
                        else if (!hasRandomProperty)
                        {
                            // Finally compare base name
                            bool validName = false;
                            for (int localeIndex = DB_LOCALE_enUS; localeIndex <= DB_LOCALE_ruRU; ++localeIndex)
                            {
                                std::string expectedName = linkedItem->Name1;
                                Item::GetLocalizedNameWithSuffix(expectedName, linkedItem, nullptr, localeIndex, GetDbcLocaleFromDbLocale(DBLocaleConstant(localeIndex)));
                                if (expectedName == buffer)
                                {
                                    validName = true;
                                    break;
                                }
                            }
                            if (!validName)
                                return false;
                        }
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
                DEBUG_LOG("ChatHandler::isValidChatMessage got invalid command |%c", commandChar);
                return false;
        }
    }

    // check if every opened sequence was also closed properly
    if (validSequence != validSequenceIterator)
        DEBUG_LOG("ChatHandler::isValidChatMessage EOF in active sequence");

    return validSequence == validSequenceIterator;
}

void ChatHandler::BuildChatPacket(WorldPacket& data, ChatMsg msgtype, char const* message, Language language /*= LANG_UNIVERSAL*/, uint32 chatTag /*= CHAT_TAG_NONE*/,
                                  ObjectGuid const& senderGuid /*= ObjectGuid()*/, char const* senderName /*= nullptr*/,
                                  ObjectGuid const& targetGuid /*= ObjectGuid()*/, char const* targetName /*= nullptr*/,
                                  char const* channelName /*= nullptr*/, uint8 playerRank /*= 0*/)
{
    data.Initialize(SMSG_MESSAGECHAT);
    data << uint8(msgtype);
    data << uint32(language);

    switch (msgtype)
    {
        case CHAT_MSG_MONSTER_WHISPER:
        //case CHAT_MSG_RAID_BOSS_WHISPER:
        case CHAT_MSG_RAID_BOSS_EMOTE:
        case CHAT_MSG_MONSTER_EMOTE:
            MANGOS_ASSERT(senderName);
            data << uint32(strlen(senderName) + 1);
            data << senderName;
            data << ObjectGuid(targetGuid);
            break;

        case CHAT_MSG_SAY:
        case CHAT_MSG_PARTY:
        case CHAT_MSG_YELL:
            data << ObjectGuid(senderGuid);
            data << ObjectGuid(senderGuid);
            break;

        case CHAT_MSG_MONSTER_SAY:
        case CHAT_MSG_MONSTER_YELL:
            MANGOS_ASSERT(senderName);
            data << ObjectGuid(senderGuid);
            data << uint32(strlen(senderName) + 1);
            data << senderName;
            data << ObjectGuid(targetGuid);
            break;

        case CHAT_MSG_CHANNEL:
            MANGOS_ASSERT(channelName);
            data << channelName;
            data << uint32(playerRank);
            data << ObjectGuid(senderGuid);
            break;

        default:
            data << ObjectGuid(senderGuid);
            break;
    }

    MANGOS_ASSERT(message);
    data << uint32(strlen(message) + 1);
    data << message;
    data << uint8(chatTag);
}

Player* ChatHandler::GetSelectedPlayer() const
{
    if (!m_session)
        return nullptr;

    ObjectGuid guid  = m_session->GetPlayer()->GetSelectionGuid();

    if (!guid)
        return m_session->GetPlayer();

    return sObjectMgr.GetPlayer(guid);
}

Unit* ChatHandler::GetSelectedUnit() const
{
    if (!m_session)
        return nullptr;

    ObjectGuid guid = m_session->GetPlayer()->GetSelectionGuid();

    if (!guid)
        return m_session->GetPlayer();

    // can be selected player at another map
    return ObjectAccessor::GetUnit(*m_session->GetPlayer(), guid);
}

Creature* ChatHandler::GetSelectedCreature() const
{
    if (!m_session)
        return nullptr;

    return m_session->GetPlayer()->GetMap()->GetAnyTypeCreature(m_session->GetPlayer()->GetSelectionGuid());
}

Pet* ChatHandler::GetSelectedPet() const
{
    if (!m_session)
        return nullptr;

    return m_session->GetPlayer()->GetMap()->GetPet(m_session->GetPlayer()->GetSelectionGuid());
}

/**
 * Function skip all whitespaces in args string
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *             allowed nullptr string pointer stored in *args
 */
void ChatHandler::SkipWhiteSpaces(char** args)
{
    if (!*args)
        return;

    while (isWhiteSpace(**args))
        ++(*args);
}

/**
 * Function extract to val arg signed integer value or fail
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val  return extracted value if function success, in fail case original value unmodified
 * @return     true if value extraction successful
 */
bool  ChatHandler::ExtractInt32(char** args, int32& val)
{
    if (!*args || !**args)
        return false;

    char* tail = *args;

    long valRaw = strtol(*args, &tail, 10);

    if (tail != *args && isWhiteSpace(*tail))
        *(tail++) = '\0';
    else if (tail && *tail)                                 // some not whitespace symbol
        return false;                                       // args not modified and can be re-parsed

    if (valRaw < std::numeric_limits<int32>::min() || valRaw > std::numeric_limits<int32>::max())
        return false;

    // value successfully extracted
    val = int32(valRaw);
    *args = tail;
    return true;
}

/**
 * Function extract to val arg optional signed integer value or use default value. Fail if extracted not signed integer.
 *
 * @param args    variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val     return extracted value if function success, in fail case original value unmodified
 * @param defVal  default value used if no data for extraction in args
 * @return        true if value extraction successful
 */
bool  ChatHandler::ExtractOptInt32(char** args, int32& val, int32 defVal)
{
    if (!*args || !**args)
    {
        val = defVal;
        return true;
    }

    return ExtractInt32(args, val);
}

/**
 * Function extract to val arg unsigned integer value or fail
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val  return extracted value if function success, in fail case original value unmodified
 * @param base set used base for extracted value format (10 for decimal, 16 for hex, etc), 0 let auto select by system internal function
 * @return     true if value extraction successful
 */
bool  ChatHandler::ExtractUInt32Base(char** args, uint32& val, uint32 base)
{
    if (!*args || !**args)
        return false;

    char* tail = *args;

    unsigned long valRaw = strtoul(*args, &tail, base);

    if (tail != *args && isWhiteSpace(*tail))
        *(tail++) = '\0';
    else if (tail && *tail)                                 // some not whitespace symbol
        return false;                                       // args not modified and can be re-parsed

    if (valRaw > std::numeric_limits<uint32>::max())
        return false;

    // value successfully extracted
    val = uint32(valRaw);
    *args = tail;

    SkipWhiteSpaces(args);
    return true;
}

/**
 * Function extract to val arg optional unsigned integer value or use default value. Fail if extracted not unsigned integer.
 *
 * @param args    variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val     return extracted value if function success, in fail case original value unmodified
 * @param defVal  default value used if no data for extraction in args
 * @return        true if value extraction successful
 */
bool  ChatHandler::ExtractOptUInt32(char** args, uint32& val, uint32 defVal)
{
    if (!*args || !**args)
    {
        val = defVal;
        return true;
    }

    return ExtractUInt32(args, val);
}

/**
 * Function extract to val arg float value or fail
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val  return extracted value if function success, in fail case original value unmodified
 * @return     true if value extraction successful
 */
bool  ChatHandler::ExtractFloat(char** args, float& val)
{
    if (!*args || !**args)
        return false;

    char* tail = *args;

    double valRaw = strtod(*args, &tail);

    if (tail != *args && isWhiteSpace(*tail))
        *(tail++) = '\0';
    else if (tail && *tail)                                 // some not whitespace symbol
        return false;                                       // args not modified and can be re-parsed

    // value successfully extracted
    val = float(valRaw);
    *args = tail;

    SkipWhiteSpaces(args);
    return true;
}

/**
 * Function extract to val arg optional float value or use default value. Fail if extracted not float.
 *
 * @param args    variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val     return extracted value if function success, in fail case original value unmodified
 * @param defVal  default value used if no data for extraction in args
 * @return        true if value extraction successful
 */
bool  ChatHandler::ExtractOptFloat(char** args, float& val, float defVal)
{
    if (!*args || !**args)
    {
        val = defVal;
        return true;
    }

    return ExtractFloat(args, val);
}

/**
 * Function extract name-like string (from non-numeric or special symbol until whitespace)
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param lit  optional explicit literal requirement. function fail if literal is not starting substring of lit.
 *             Note: function in same way fail if no any literal or literal not fit in this case. Need additional check for select specific fail case
 * @return     name/number-like string without whitespaces, or nullptr if args empty or not appropriate content.
 */
char* ChatHandler::ExtractLiteralArg(char** args, char const* lit /*= nullptr*/)
{
    if (!*args || !**args)
        return nullptr;

    char* head = *args;

    // reject quoted string or link (|-started text)
    switch (head[0])
    {
        // reject quoted string
        case '[':
        case '\'':
        case '"':
            return nullptr;
        // reject link (|-started text)
        case '|':
            // client replace all | by || in raw text
            if (head[1] != '|')
                return nullptr;
            ++head;                                         // skip one |
            break;
        default:
            break;
    }

    if (lit)
    {
        int l = strlen(lit);
        int diff = strncmp(head, lit, l);

        if (diff != 0)
            return nullptr;

        if (head[l] && !isWhiteSpace(head[l]))
            return nullptr;

        char* arg = head;

        if (head[l])
        {
            head[l] = '\0';

            head += l + 1;

            *args = head;
        }
        else
            *args = head + l;

        SkipWhiteSpaces(args);
        return arg;
    }

    char* name = strtok(head, " ");

    char* tail = strtok(nullptr, "");

    *args = tail ? tail : (char*)"";                        // *args don't must be nullptr

    SkipWhiteSpaces(args);

    return name;
}

/**
 * Function extract quote-like string (any characters guarded by some special character, in our cases ['")
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param asis control save quote string wrappers
 * @return     quote-like string, or nullptr if args empty or not appropriate content.
 */
char* ChatHandler::ExtractQuotedArg(char** args, bool asis /*= false*/)
{
    if (!*args || !**args)
        return nullptr;

    if (**args != '\'' && **args != '"' && **args != '[')
        return nullptr;

    char guard = (*args)[0];

    if (guard == '[')
        guard = ']';

    char* tail = (*args) + 1;                               // start scan after first quote symbol
    char* head = asis ? *args : tail;                       // start arg

    while (*tail && *tail != guard)
        ++tail;

    if (!*tail || (tail[1] && !isWhiteSpace(tail[1])))      // fail
        return nullptr;

    if (!tail[1])                                           // quote is last char in string
    {
        if (!asis)
            *tail = '\0';
    }
    else                                                    // quote isn't last char
    {
        if (asis)
            ++tail;

        *tail = '\0';
    }

    *args = tail + 1;

    SkipWhiteSpaces(args);

    return head;
}

/**
 * Function extract quote-like string or literal if quote not detected
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param asis control save quote string wrappers
 * @return     quote/literal string, or nullptr if args empty or not appropriate content.
 */
char* ChatHandler::ExtractQuotedOrLiteralArg(char** args, bool asis /*= false*/)
{
    char *arg = ExtractQuotedArg(args, asis);
    if (!arg)
        arg = ExtractLiteralArg(args);
    return arg;
}

/**
 * Function extract on/off literals as boolean values
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param val  return extracted value if function success, in fail case original value unmodified
 * @return     true at success
 */
bool  ChatHandler::ExtractOnOff(char** args, bool& value)
{
    char* arg = ExtractLiteralArg(args);
    if (!arg)
        return false;

    if (strncmp(arg, "on", 3) == 0 || strncmp(arg, "ON", 3) == 0)
        value = true;
    else if (strncmp(arg, "off", 4) == 0 || strncmp(arg, "OFF", 4) == 0)
        value = false;
    else
        return false;

    return true;
}

/**
 * Function extract shift-link-like string (any characters guarded by | and |h|r with some additional internal structure check)
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *
 * @param linkTypes  optional nullptr-terminated array of link types, shift-link must fit one from link type from array if provided or extraction fail
 *
 * @param found_idx  if not nullptr then at return index in linkTypes that fit shift-link type, if extraction fail then non modified
 *
 * @param keyPair    if not nullptr then pointer to 2-elements array for return start and end pointer for found key
 *                   if extraction fail then non modified
 *
 * @param somethingPair then pointer to 2-elements array for return start and end pointer if found.
 *                   if not nullptr then shift-link must have data field, if extraction fail then non modified
 *
 * @return     shift-link-like string, or nullptr if args empty or not appropriate content.
 */
char* ChatHandler::ExtractLinkArg(char** args, char const* const* linkTypes /*= nullptr*/, int* foundIdx /*= nullptr*/, char** keyPair /*= nullptr*/, char** somethingPair /*= nullptr*/)
{
    if (!*args || !**args)
        return nullptr;

    // skip if not linked started or encoded single | (doubled by client)
    if ((*args)[0] != '|' || (*args)[1] == '|')
        return nullptr;

    // |color|Hlinktype:key:data...|h[name]|h|r

    char* head = *args;

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r
    // or
    // [name] Shift-click form |linkType:key|h[name]|h|r

    // |color|Hlinktype:key:data...|h[name]|h|r

    char* tail = (*args) + 1;                               // skip |

    if (*tail != 'H')                                       // skip color part, some links can not have color part
    {
        while (*tail && *tail != '|')
            ++tail;

        if (!*tail)
            return nullptr;

        // |Hlinktype:key:data...|h[name]|h|r

        ++tail;                                             // skip |
    }

    // Hlinktype:key:data...|h[name]|h|r

    if (*tail != 'H')
        return nullptr;

    int linktype_idx = 0;

    if (linkTypes)                                          // check link type if provided
    {
        // check linktypes (its include H in name)
        for (; linkTypes[linktype_idx]; ++linktype_idx)
        {
            // exactly string with follow : or |
            int l = strlen(linkTypes[linktype_idx]);
            if (strncmp(tail, linkTypes[linktype_idx], l) == 0 &&
                    (tail[l] == ':' || tail[l] == '|'))
                break;
        }

        // is search fail?
        if (!linkTypes[linktype_idx])                       // nullptr terminator in last element
            return nullptr;

        tail += strlen(linkTypes[linktype_idx]);            // skip linktype string

        // :key:data...|h[name]|h|r

        if (*tail != ':')
            return nullptr;
    }
    else
    {
        while (*tail && *tail != ':')                       // skip linktype string
            ++tail;

        if (!*tail)
            return nullptr;
    }

    ++tail;

    // key:data...|h[name]|h|r
    char* keyStart = tail;                                  // remember key start for return
    char* keyEnd   = tail;                                  // key end for truncate, will updated

    while (*tail && *tail != '|' && *tail != ':')
        ++tail;

    if (!*tail)
        return nullptr;

    keyEnd = tail;                                          // remember key end for truncate

    // |h[name]|h|r or :something...|h[name]|h|r

    char* somethingStart = tail + 1;
    char* somethingEnd   = tail + 1;                        // will updated later if need

    if (*tail == ':' && somethingPair)                      // optional data extraction
    {
        // :something...|h[name]|h|r
        ++tail;

        // something|h[name]|h|r or something:something2...|h[name]|h|r

        while (*tail && *tail != '|' && *tail != ':')
            ++tail;

        if (!*tail)
            return nullptr;

        somethingEnd = tail;                                // remember data end for truncate
    }

    // |h[name]|h|r or :something2...|h[name]|h|r

    while (*tail && (*tail != '|' || *(tail + 1) != 'h'))   // skip ... part if exist
        ++tail;

    if (!*tail)
        return nullptr;

    // |h[name]|h|r

    tail += 2;                                              // skip |h

    // [name]|h|r
    if (!*tail || *tail != '[')
        return nullptr;

    while (*tail && (*tail != ']' || *(tail + 1) != '|'))   // skip name part
        ++tail;

    tail += 2;                                              // skip ]|

    // h|r
    if (!*tail || *tail != 'h'  || *(tail + 1) != '|')
        return nullptr;

    tail += 2;                                              // skip h|

    // r
    if (!*tail || *tail != 'r' || (*(tail + 1) && !isWhiteSpace(*(tail + 1))))
        return nullptr;

    ++tail;                                                 // skip r

    // success

    if (*tail)                                              // truncate all link string
        *(tail++) = '\0';

    if (foundIdx)
        *foundIdx = linktype_idx;

    if (keyPair)
    {
        keyPair[0] = keyStart;
        keyPair[1] = keyEnd;
    }

    if (somethingPair)
    {
        somethingPair[0] = somethingStart;
        somethingPair[1] = somethingEnd;
    }

    *args = tail;

    SkipWhiteSpaces(args);

    return head;
}

/**
 * Function extract name/number/quote/shift-link-like string
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 * @param asis control save quote string wrappers
 * @return     extracted arg string, or nullptr if args empty or not appropriate content.
 */
char* ChatHandler::ExtractArg(char** args, bool asis /*= false*/)
{
    if (!*args || !**args)
        return nullptr;

    char* arg = ExtractQuotedOrLiteralArg(args, asis);
    if (!arg)
        arg = ExtractLinkArg(args);

    return arg;
}

/**
 * Function extract name/quote/number/shift-link-like string, and return it if args have more non-whitespace data
 *
 * @param args variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *             if args have only single arg then args still pointing to this arg (unmodified pointer)
 * @return     extracted string, or nullptr if args empty or not appropriate content or have single arg totally.
 */
char* ChatHandler::ExtractOptNotLastArg(char** args)
{
    char* arg = ExtractArg(args, true);

    // have more data
    if (*args && **args)
        return arg;

    // optional name not found
    *args = arg ? arg : (char*)"";                          // *args don't must be nullptr

    return nullptr;
}

/**
 * Function extract data from shift-link "|color|LINKTYPE:RETURN:SOMETHING1|h[name]|h|r if linkType == LINKTYPE
 * It also extract literal/quote if not shift-link in args
 *
 * @param args       variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *                   if args have sift link with linkType != LINKTYPE then args still pointing to this arg (unmodified pointer)
 *
 * @param linkType   shift-link must fit by link type to this arg value or extraction fail
 *
 * @param something1 if not nullptr then shift-link must have data field and it returned into this arg
 *                   if extraction fail then non modified
 *
 * @return           extracted key, or nullptr if args empty or not appropriate content or not fit to linkType.
 */
char* ChatHandler::ExtractKeyFromLink(char** text, char const* linkType, char** something1 /*= nullptr*/)
{
    char const* linkTypes[2];
    linkTypes[0] = linkType;
    linkTypes[1] = nullptr;

    int foundIdx;

    return ExtractKeyFromLink(text, linkTypes, &foundIdx, something1);
}

/**
 * Function extract data from shift-link "|color|LINKTYPE:RETURN:SOMETHING1|h[name]|h|r if LINKTYPE in linkTypes array
 * It also extract literal/quote if not shift-link in args
 *
 * @param args       variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *                   if args have sift link with linkType != LINKTYPE then args still pointing to this arg (unmodified pointer)
 *
 * @param linkTypes  nullptr-terminated array of link types, shift-link must fit one from link type from array or extraction fail
 *
 * @param found_idx  if not nullptr then at return index in linkTypes that fit shift-link type, for non-link case return -1
 *                   if extraction fail then non modified
 *
 * @param something1 if not nullptr then shift-link must have data field and it returned into this arg
 *                   if extraction fail then non modified
 *
 * @return           extracted key, or nullptr if args empty or not appropriate content or not fit to linkType.
 */
char* ChatHandler::ExtractKeyFromLink(char** text, char const* const* linkTypes, int* found_idx, char** something1 /*= nullptr*/)
{
    // skip empty
    if (!*text || !**text)
        return nullptr;

    // return non link case
    char* arg = ExtractQuotedOrLiteralArg(text);
    if (arg)
    {
        if (found_idx)
            *found_idx = -1;                                // special index case

        return arg;
    }

    char* keyPair[2];
    char* somethingPair[2];

    arg = ExtractLinkArg(text, linkTypes, found_idx, keyPair, something1 ? somethingPair : nullptr);
    if (!arg)
        return nullptr;

    *keyPair[1] = '\0';                                     // truncate key string

    if (something1)
    {
        *somethingPair[1] = '\0';                           // truncate data string
        *something1 = somethingPair[0];
    }

    return keyPair[0];
}

/**
 * Function extract uint32 key from shift-link "|color|LINKTYPE:RETURN|h[name]|h|r if linkType == LINKTYPE
 * It also extract direct number if not shift-link in args
 *
 * @param args       variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *                   if args have sift link with linkType != LINKTYPE then args still pointing to this arg (unmodified pointer)
 *
 * @param linkType   shift-link must fit by link type to this arg value or extraction fail
 *
 * @param value      store result value at success return, not modified at fail
 *
 * @return           true if extraction succesful
 */
bool ChatHandler::ExtractUint32KeyFromLink(char** text, char const* linkType, uint32& value)
{
    char* arg = ExtractKeyFromLink(text, linkType);
    if (!arg)
        return false;

    return ExtractUInt32(&arg, value);
}

GameObject* ChatHandler::GetGameObjectWithGuid(uint32 lowguid, uint32 entry)
{
    if (!m_session)
        return nullptr;

    Player* pl = m_session->GetPlayer();

    return pl->GetMap()->GetGameObject(ObjectGuid(HIGHGUID_GAMEOBJECT, entry, lowguid));
}

enum SpellLinkType
{
    SPELL_LINK_RAW     = -1,                                // non-link case
    SPELL_LINK_SPELL   = 0,
    SPELL_LINK_TALENT  = 1,
    SPELL_LINK_ENCHANT = 2,
};

static char const* const spellKeys[] =
{
    "Hspell",                                               // normal spell
    "Htalent",                                              // talent spell
    "Henchant",                                             // enchanting recipe spell
    nullptr
};

uint32 ChatHandler::ExtractSpellIdFromLink(char** text)
{
    // number or [name] Shift-click form |color|Henchant:recipe_spell_id|h[prof_name: recipe_name]|h|r
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    // number or [name] Shift-click form |color|Htalent:talent_id,rank|h[name]|h|r
    int type;
    char* param1_str = nullptr;
    char* idS = ExtractKeyFromLink(text, spellKeys, &type, &param1_str);
    if (!idS)
        return 0;

    uint32 id;
    if (!ExtractUInt32(&idS, id))
        return 0;

    switch (type)
    {
        case SPELL_LINK_RAW:
        case SPELL_LINK_SPELL:
        case SPELL_LINK_ENCHANT:
            return id;
        case SPELL_LINK_TALENT:
        {
            // talent
            TalentEntry const* talentEntry = sTalentStore.LookupEntry(id);
            if (!talentEntry)
                return 0;

            int32 rank;
            if (!ExtractInt32(&param1_str, rank))
                return 0;

            if (rank < 0)                                   // unlearned talent have in shift-link field -1 as rank
                rank = 0;

            return rank < MAX_TALENT_RANK ? talentEntry->RankID[rank] : 0;
        }
    }

    // unknown type?
    return 0;
}

GameTele const* ChatHandler::ExtractGameTeleFromLink(char** text)
{
    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    char* cId = ExtractKeyFromLink(text, "Htele");
    if (!cId)
        return nullptr;

    // id case (explicit or from shift link)
    uint32 id;
    if (ExtractUInt32(&cId, id))
        return sObjectMgr.GetGameTele(id);
    else
        return sObjectMgr.GetGameTele(cId);
}

enum GuidLinkType
{
    GUID_LINK_RAW        = -1,                              // non-link case
    GUID_LINK_PLAYER     = 0,
    GUID_LINK_CREATURE   = 1,
    GUID_LINK_GAMEOBJECT = 2,
};

static char const* const guidKeys[] =
{
    "Hplayer",
    "Hcreature",
    "Hgameobject",
    nullptr
};

ObjectGuid ChatHandler::ExtractGuidFromLink(char** text)
{
    int type = 0;

    // |color|Hcreature:creature_guid|h[name]|h|r
    // |color|Hgameobject:go_guid|h[name]|h|r
    // |color|Hplayer:name|h[name]|h|r
    char* idS = ExtractKeyFromLink(text, guidKeys, &type);
    if (!idS)
        return ObjectGuid();

    switch (type)
    {
        case GUID_LINK_RAW:
        case GUID_LINK_PLAYER:
        {
            std::string name = idS;
            if (!normalizePlayerName(name))
                return ObjectGuid();

            if (Player* player = sObjectMgr.GetPlayer(name.c_str()))
                return player->GetObjectGuid();

            return sObjectMgr.GetPlayerGuidByName(name);
        }
        case GUID_LINK_CREATURE:
        {
            uint32 lowguid;
            if (!ExtractUInt32(&idS, lowguid))
                return ObjectGuid();

            if (CreatureData const* data = sObjectMgr.GetCreatureData(lowguid))
                return data->GetObjectGuid(lowguid);
            else
                return ObjectGuid();
        }
        case GUID_LINK_GAMEOBJECT:
        {
            uint32 lowguid;
            if (!ExtractUInt32(&idS, lowguid))
                return ObjectGuid();

            if (GameObjectData const* data = sObjectMgr.GetGOData(lowguid))
                return ObjectGuid(HIGHGUID_GAMEOBJECT, data->id, lowguid);
            else
                return ObjectGuid();
        }
    }

    // unknown type?
    return ObjectGuid();
}

enum LocationLinkType
{
    LOCATION_LINK_RAW               = -1,                   // non-link case
    LOCATION_LINK_PLAYER            = 0,
    LOCATION_LINK_TELE              = 1,
    LOCATION_LINK_TAXINODE          = 2,
    LOCATION_LINK_CREATURE          = 3,
    LOCATION_LINK_GAMEOBJECT        = 4,
    LOCATION_LINK_CREATURE_ENTRY    = 5,
    LOCATION_LINK_GAMEOBJECT_ENTRY  = 6,
    LOCATION_LINK_AREATRIGGER       = 7,
    LOCATION_LINK_AREATRIGGER_TARGET = 8,
};

static char const* const locationKeys[] =
{
    "Htele",
    "Htaxinode",
    "Hplayer",
    "Hcreature",
    "Hgameobject",
    "Hcreature_entry",
    "Hgameobject_entry",
    "Hareatrigger",
    "Hareatrigger_target",
    nullptr
};

bool ChatHandler::ExtractLocationFromLink(char** text, uint32& mapid, float& x, float& y, float& z)
{
    int type = 0;

    // |color|Hplayer:name|h[name]|h|r
    // |color|Htele:id|h[name]|h|r
    // |color|Htaxinode:id|h[name]|h|r
    // |color|Hcreature:creature_guid|h[name]|h|r
    // |color|Hgameobject:go_guid|h[name]|h|r
    // |color|Hcreature_entry:creature_id|h[name]|h|r
    // |color|Hgameobject_entry:go_id|h[name]|h|r
    // |color|Hareatrigger:id|h[name]|h|r
    // |color|Hareatrigger_target:id|h[name]|h|r
    char* idS = ExtractKeyFromLink(text, locationKeys, &type);
    if (!idS)
        return false;

    switch (type)
    {
        case LOCATION_LINK_RAW:
        case LOCATION_LINK_PLAYER:
        {
            std::string name = idS;
            if (!normalizePlayerName(name))
                return false;

            if (Player* player = sObjectMgr.GetPlayer(name.c_str()))
            {
                mapid = player->GetMapId();
                x = player->GetPositionX();
                y = player->GetPositionY();
                z = player->GetPositionZ();
                return true;
            }

            if (ObjectGuid guid = sObjectMgr.GetPlayerGuidByName(name))
            {
                // to point where player stay (if loaded)
                float o;
                bool in_flight;
                return Player::LoadPositionFromDB(guid, mapid, x, y, z, o, in_flight);
            }

            return false;
        }
        case LOCATION_LINK_TELE:
        {
            uint32 id;
            if (!ExtractUInt32(&idS, id))
                return false;

            GameTele const* tele = sObjectMgr.GetGameTele(id);
            if (!tele)
                return false;
            mapid = tele->mapId;
            x = tele->x;
            y = tele->y;
            z = tele->z;
            return true;
        }
        case LOCATION_LINK_TAXINODE:
        {
            uint32 id;
            if (!ExtractUInt32(&idS, id))
                return false;

            TaxiNodesEntry const* node = sObjectMgr.GetTaxiNodeEntry(id);
            if (!node)
                return false;
            mapid = node->map_id;
            x = node->x;
            y = node->y;
            z = node->z;
            return true;
        }
        case LOCATION_LINK_CREATURE:
        {
            uint32 lowguid;
            if (!ExtractUInt32(&idS, lowguid))
                return false;

            if (CreatureData const* data = sObjectMgr.GetCreatureData(lowguid))
            {
                mapid = data->position.mapId;
                x = data->position.x;
                y = data->position.y;
                z = data->position.z;
                return true;
            }
            else
                return false;
        }
        case LOCATION_LINK_GAMEOBJECT:
        {
            uint32 lowguid;
            if (!ExtractUInt32(&idS, lowguid))
                return false;

            if (GameObjectData const* data = sObjectMgr.GetGOData(lowguid))
            {
                mapid = data->position.mapId;
                x = data->position.x;
                y = data->position.y;
                z = data->position.z;
                return true;
            }
            else
                return false;
        }
        case LOCATION_LINK_CREATURE_ENTRY:
        {
            uint32 id;
            if (!ExtractUInt32(&idS, id))
                return false;

            if (ObjectMgr::GetCreatureTemplate(id))
            {
                FindCreatureData worker(id, m_session ? m_session->GetPlayer() : nullptr);

                sObjectMgr.DoCreatureData(worker);

                if (CreatureDataPair const* dataPair = worker.GetResult())
                {
                    mapid = dataPair->second.position.mapId;
                    x = dataPair->second.position.x;
                    y = dataPair->second.position.y;
                    z = dataPair->second.position.z;
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        case LOCATION_LINK_GAMEOBJECT_ENTRY:
        {
            uint32 id;
            if (!ExtractUInt32(&idS, id))
                return false;

            if (ObjectMgr::GetGameObjectInfo(id))
            {
                FindGOData worker(id, m_session ? m_session->GetPlayer() : nullptr);

                sObjectMgr.DoGOData(worker);

                if (GameObjectDataPair const* dataPair = worker.GetResult())
                {
                    mapid = dataPair->second.position.mapId;
                    x = dataPair->second.position.x;
                    y = dataPair->second.position.y;
                    z = dataPair->second.position.z;
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        case LOCATION_LINK_AREATRIGGER:
        {
            uint32 id;
            if (!ExtractUInt32(&idS, id))
                return false;

            AreaTriggerEntry const* atEntry = sObjectMgr.GetAreaTrigger(id);
            if (!atEntry)
            {
                PSendSysMessage(LANG_COMMAND_GOAREATRNOTFOUND, id);
                SetSentErrorMessage(true);
                return false;
            }

            mapid = atEntry->mapid;
            x = atEntry->x;
            y = atEntry->y;
            z = atEntry->z;
            return true;
        }
        case LOCATION_LINK_AREATRIGGER_TARGET:
        {
            uint32 id;
            if (!ExtractUInt32(&idS, id))
                return false;

            if (!sObjectMgr.GetAreaTrigger(id))
            {
                PSendSysMessage(LANG_COMMAND_GOAREATRNOTFOUND, id);
                SetSentErrorMessage(true);
                return false;
            }

            AreaTriggerTeleport const* at = sObjectMgr.GetAreaTriggerTeleport(id);
            if (!at)
            {
                PSendSysMessage(LANG_AREATRIGER_NOT_HAS_TARGET, id);
                SetSentErrorMessage(true);
                return false;
            }

            mapid = at->destination.mapId;
            x = at->destination.x;
            y = at->destination.y;
            z = at->destination.z;
            return true;
        }
    }

    // unknown type?
    return false;
}

std::string ChatHandler::ExtractPlayerNameFromLink(char** text)
{
    // |color|Hplayer:name|h[name]|h|r
    char* name_str = ExtractKeyFromLink(text, "Hplayer");
    if (!name_str)
        return "";

    std::string name = name_str;
    if (!normalizePlayerName(name))
        return "";

    return name;
}

/**
 * Function extract at least one from request player data (pointer/guid/name) from args name/shift-link or selected player if no args
 *
 * @param args        variable pointer to non parsed args string, updated at function call to new position (with skipped white spaces)
 *
 * @param player      optional arg   One from 3 optional args must be provided at least (or more).
 * @param player_guid optional arg   For function success only one from provided args need get result
 * @param player_name optional arg   But if early arg get value then all later args will have its (if requested)
 *                                   if player_guid requested and not found then name also will not found
 *                                   So at success can be returned 2 cases: (player/guid/name) or (guid/name)
 *
 * @return           true if extraction successful
 */
bool ChatHandler::ExtractPlayerTarget(char** args, Player** player /*= nullptr*/, ObjectGuid* player_guid /*= nullptr*/, std::string* player_name /*= nullptr*/, bool use_extended_response)
{
    std::string name;
    if (*args && **args)
    {
        name = ExtractPlayerNameFromLink(args);
        if (name.empty())
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        Player* pl = sObjectMgr.GetPlayer(name.c_str());

        // if allowed player pointer
        if (player)
            *player = pl;

        // if need guid value from DB (in name case for check player existence)
        ObjectGuid guid = !pl && (player_guid || player_name) ? sObjectMgr.GetPlayerGuidByName(name) : ObjectGuid();

        // if allowed player guid (if no then only online players allowed)
        if (player_guid)
            *player_guid = pl ? pl->GetObjectGuid() : guid;

        if (player_name)
            *player_name = pl || guid ? name : "";
    }
    else
    {
        // populate strtok buffer to prevent crashes
        static char dummy[1] = "";
        strtok(dummy, "");

        Player* pl = getSelectedPlayerOrSelf();
        Player* pl = GetSelectedPlayer();
        // if allowed player pointer
        if (player)
            *player = pl;
        // if allowed player guid (if no then only online players allowed)
        if (player_guid)
            *player_guid = pl ? pl->GetObjectGuid() : ObjectGuid();

        if (player_name)
            *player_name = pl ? pl->GetName() : "";
    }

    // some from req. data must be provided (note: name is empty if player not exist)
    if ((!player || !*player) && (!player_guid || !*player_guid) && (!player_name || player_name->empty()))
    {
        if (use_extended_response && !name.empty())
        {
            std::string message(GetMangosString(LANG_PLAYER_NOT_FOUND));
            message.append(" (" + name + ")");
            SendSysMessage(message.c_str());
        }
        else
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
        }
        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

uint32 ChatHandler::ExtractAccountId(char** args, std::string* accountName /*= nullptr*/, Player** targetIfNullArg /*= nullptr*/)
{
    uint32 account_id = 0;

    ///- Get the account name from the command line
    char* account_str = ExtractLiteralArg(args);

    if (!account_str)
    {
        if (!targetIfNullArg)
            return 0;

        /// only target player different from self allowed (if targetPlayer!=nullptr then not console)
        Player* targetPlayer = GetSelectedPlayer();
        if (!targetPlayer)
            return 0;

        account_id = targetPlayer->GetSession()->GetAccountId();

        if (accountName)
            sAccountMgr.GetName(account_id, *accountName);

        if (targetIfNullArg)
            *targetIfNullArg = targetPlayer;

        return account_id;
    }

char* ChatHandler::extractQuotedArg(char* args)
{
    if (!args || !*args)
        return nullptr;
    std::string account_name;

    if (ExtractUInt32(&account_str, account_id))
    {
        if (!sAccountMgr.GetName(account_id, account_name))
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, account_str);
            SetSentErrorMessage(true);
            return 0;
        }
    }
    else
    {
        account_name = account_str;
        if (!AccountMgr::normalizeString(account_name))
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, account_name.c_str());
            SetSentErrorMessage(true);
            return 0;
        }

        account_id = sAccountMgr.GetId(account_name);
        if (!account_id)
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, account_name.c_str());
            SetSentErrorMessage(true);
            return 0;
        }
    }

    if (accountName)
        *accountName = account_name;

    if (targetIfNullArg)
        *targetIfNullArg = nullptr;

    return account_id;
}

struct RaceMaskName
{
    char const* literal;
    uint32 raceMask;
};

static RaceMaskName const raceMaskNames[] =
{
    // races
    { "human", (1 << (RACE_HUMAN - 1))   },
    { "orc", (1 << (RACE_ORC - 1))     },
    { "dwarf", (1 << (RACE_DWARF - 1))   },
    { "nightelf", (1 << (RACE_NIGHTELF - 1))},
    { "undead", (1 << (RACE_UNDEAD - 1))  },
    { "tauren", (1 << (RACE_TAUREN - 1))  },
    { "gnome", (1 << (RACE_GNOME - 1))   },
    { "troll", (1 << (RACE_TROLL - 1))   },

    // masks
    { "alliance", RACEMASK_ALLIANCE },
    { "horde",    RACEMASK_HORDE },
    { "all", RACEMASK_ALL_PLAYABLE },

    // terminator
    {nullptr, 0 }
};

bool ChatHandler::ExtractRaceMask(char** text, uint32& raceMask, char const** maskName /*=nullptr*/)
{
    if (ExtractUInt32(text, raceMask))
    {
        if (maskName)
            *maskName = "custom mask";
    }
    else
    {
        for (RaceMaskName const* itr = raceMaskNames; itr->literal; ++itr)
        {
            if (ExtractLiteralArg(text, itr->literal))
            {
                raceMask = itr->raceMask;

                if (maskName)
                    *maskName = itr->literal;
                break;
            }
        }

        if (!raceMask)
            return false;
    }

    return true;
}

std::string ChatHandler::GetNameLink(Player* chr) const
{
    return playerLink(chr->GetName());
}

std::string ChatHandler::GetItemLink(ItemPrototype const* pItem) const
{
    if (m_session)
    {
        uint32 color = ItemQualityColors[pItem->Quality];
        std::ostringstream itemStr;
        itemStr << "|c" << std::hex << color << "|Hitem:" << std::to_string(pItem->ItemId) << ":0:0:0:0:0:0:0|h[" << pItem->Name1 << "]|h|r";
        return itemStr.str();
    }

    return pItem->Name1;
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

std::string ChatHandler::playerLink(std::string const& name) const
{
    return m_session ? "|cffffffff|Hplayer:" + name + "|h[" + name + "]|h|r" : name;
}

std::string ChatHandler::GetNameLink(Player* chr) const
char const* CliHandler::GetMangosString(int32 entry) const
{
    return sObjectMgr.GetMangosStringForDBCLocale(entry);
}

uint32 CliHandler::GetAccountId() const
{
    return m_accountId;
}

AccountTypes CliHandler::GetAccessLevel() const
{
    return m_loginAccessLevel;
}

void CliHandler::SendSysMessage(std::string_view str, bool /*escapeCharacters*/)
{
    // skip non-console commands in console case
    if (!cmd.AllowConsole)
        return false;

    // normal case
    return GetAccessLevel() >= (AccountTypes)cmd.SecurityLevel;
}

void CliHandler::SendSysMessage(char const* str)
{
    m_print(m_callbackArg, str);
    m_print(m_callbackArg, "\r\n");
}

std::string CliHandler::GetNameLink() const
{
    return GetMangosString(LANG_CONSOLE_COMMAND);
}

bool CliHandler::needReportToTarget(Player* /*chr*/) const
{
    return true;
}

LocaleConstant CliHandler::GetSessionDbcLocale() const
{
    return sWorld.GetDefaultDbcLocale();
}

int CliHandler::GetSessionDbLocaleIndex() const
{
    return sObjectMgr.GetDBCLocaleIndex();
}

// Check/ Output if a NPC or GO (by guid) is part of a pool or game event
template <typename T>
void ChatHandler::ShowNpcOrGoSpawnInformation(uint32 guid)
{
    if (uint16 pool_id = sPoolMgr.IsPartOfAPool<T>(guid))
    {
        uint16 top_pool_id = sPoolMgr.IsPartOfTopPool<Pool>(pool_id);
        if (!top_pool_id || top_pool_id == pool_id)
            PSendSysMessage(LANG_NPC_GO_INFO_POOL, pool_id);
        else
            PSendSysMessage(LANG_NPC_GO_INFO_TOP_POOL, pool_id, top_pool_id);

        if (int16 event_id = sGameEventMgr.GetGameEventId<Pool>(top_pool_id))
        {
            GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();
            GameEventData const& eventData = events[std::abs(event_id)];

            if (event_id > 0)
                PSendSysMessage(LANG_NPC_GO_INFO_POOL_GAME_EVENT_S, top_pool_id, std::abs(event_id), eventData.description.c_str());
            else
                PSendSysMessage(LANG_NPC_GO_INFO_POOL_GAME_EVENT_D, top_pool_id, std::abs(event_id), eventData.description.c_str());
        }
    }
    else if (int16 event_id = sGameEventMgr.GetGameEventId<T>(guid))
    {
        GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();
        GameEventData const& eventData = events[std::abs(event_id)];

        if (event_id > 0)
            PSendSysMessage(LANG_NPC_GO_INFO_GAME_EVENT_S, uint32(event_id), eventData.description.c_str());
        else
            PSendSysMessage(LANG_NPC_GO_INFO_GAME_EVENT_D, uint32(-event_id), eventData.description.c_str());
    }
}

std::string const AddonChannelCommandHandler::PREFIX = "TrinityCore";

bool AddonChannelCommandHandler::ParseCommands(std::string_view str)
// Prepare ShortString for a NPC or GO (by guid) with pool or game event IDs
template <typename T>
std::string ChatHandler::PrepareStringNpcOrGoSpawnInformation(uint32 guid)
{
    if (str.length() < 5)
        return false;
    char opcode = str[0];
    echo = &str[1];

    switch (opcode)
    std::string str;
    if (uint16 pool_id = sPoolMgr.IsPartOfAPool<T>(guid))
    {
        case 'p': // p Ping
            SendAck();
            return true;
        case 'h': // h Issue human-readable command
        case 'i': // i Issue command
        {
            if (!str[5])
                return false;
            humanReadable = (opcode == 'h');
            std::string_view cmd = str.substr(5);
            if (_ParseCommands(cmd)) // actual command starts at str[5]
            {
                if (!hadAck)
                    SendAck();
                if (HasSentErrorMessage())
                    SendFailed();
                else
                    SendOK();
            }
            else
            {
                PSendSysMessage(LANG_CMD_INVALID, STRING_VIEW_FMT_ARG(cmd));
                SendFailed();
            }
            return true;
        }
        default:
            return false;
    }
}

void AddonChannelCommandHandler::Send(std::string const& msg)
{
    WorldPackets::Chat::Chat chat;
    chat.Initialize(CHAT_MSG_WHISPER, LANG_ADDON, GetSession()->GetPlayer(), GetSession()->GetPlayer(), msg, 0, "", LOCALE_enUS, PREFIX);
    GetSession()->SendPacket(chat.Write());
}
        uint16 top_pool_id = sPoolMgr.IsPartOfTopPool<T>(guid);
        if (int16 event_id = sGameEventMgr.GetGameEventId<Pool>(top_pool_id))
        {
            char buffer[100];
            char const* format = GetMangosString(LANG_NPC_GO_INFO_POOL_EVENT_STRING);
            sprintf(buffer, format, pool_id, event_id);
            str = buffer;
        }
        else
        {
            char buffer[100];
            char const* format = GetMangosString(LANG_NPC_GO_INFO_POOL_STRING);
            sprintf(buffer, format, pool_id);
            str = buffer;
        }
    }
    else if (int16 event_id = sGameEventMgr.GetGameEventId<T>(guid))
    {
        char buffer[100];
        char const* format = GetMangosString(LANG_NPC_GO_INFO_EVENT_STRING);
        sprintf(buffer, format, event_id);
        str = buffer;
    }

    return str;
}

// Instantiate template for helper function
template void ChatHandler::ShowNpcOrGoSpawnInformation<Creature>(uint32 guid);
template void ChatHandler::ShowNpcOrGoSpawnInformation<GameObject>(uint32 guid);

template std::string ChatHandler::PrepareStringNpcOrGoSpawnInformation<Creature>(uint32 guid);
template std::string ChatHandler::PrepareStringNpcOrGoSpawnInformation<GameObject>(uint32 guid);


LocaleConstant NullChatHandler::GetSessionDbcLocale() const
{
    return sWorld.GetDefaultDbcLocale();
}

int NullChatHandler::GetSessionDbLocaleIndex() const
{
    return sObjectMgr.GetDBCLocaleIndex();
}

// m Command message, message in body
void AddonChannelCommandHandler::SendSysMessage(std::string_view str, bool escapeCharacters)
{
    ASSERT(echo);
    if (!hadAck)
        SendAck();

    std::string msg = "m";
    msg.append(echo, 4);
    std::string body(str);
    if (escapeCharacters)
        boost::replace_all(body, "|", "||");
    size_t pos, lastpos;
    for (lastpos = 0, pos = body.find('\n', lastpos); pos != std::string::npos; lastpos = pos + 1, pos = body.find('\n', lastpos))
    {
        std::string line(msg);
        line.append(body, lastpos, pos - lastpos);
        Send(line);
    }
    msg.append(body, lastpos, pos - lastpos);
    Send(msg);
char const* NullChatHandler::GetMangosString(int32 entry) const
{
    return sObjectMgr.GetMangosStringForDBCLocale(entry);
}
