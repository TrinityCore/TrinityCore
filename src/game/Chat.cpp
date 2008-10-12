/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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

#include "Common.h"
#include "Language.h"
#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "UpdateMask.h"
#include "Chat.h"
#include "MapManager.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

bool ChatHandler::load_command_table = true;

ChatCommand * ChatHandler::getCommandTable()
{
    static ChatCommand serverCommandTable[] =
    {
        { "idlerestart",    SEC_ADMINISTRATOR,  &ChatHandler::HandleIdleRestartCommand,         "", NULL },
        { "idleshutdown",   SEC_ADMINISTRATOR,  &ChatHandler::HandleIdleShutDownCommand,        "", NULL },
        { "info",           SEC_PLAYER,         &ChatHandler::HandleInfoCommand,                "", NULL },
        { "restart",        SEC_ADMINISTRATOR,  &ChatHandler::HandleRestartCommand,             "", NULL },
        { "shutdown",       SEC_ADMINISTRATOR,  &ChatHandler::HandleShutDownCommand,            "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand modifyCommandTable[] =
    {
        { "hp",             SEC_MODERATOR,      &ChatHandler::HandleModifyHPCommand,            "", NULL },
        { "mana",           SEC_MODERATOR,      &ChatHandler::HandleModifyManaCommand,          "", NULL },
        { "rage",           SEC_MODERATOR,      &ChatHandler::HandleModifyRageCommand,          "", NULL },
        { "energy",         SEC_MODERATOR,      &ChatHandler::HandleModifyEnergyCommand,        "", NULL },
        { "money",          SEC_MODERATOR,      &ChatHandler::HandleModifyMoneyCommand,         "", NULL },
        { "speed",          SEC_MODERATOR,      &ChatHandler::HandleModifySpeedCommand,         "", NULL },
        { "swim",           SEC_MODERATOR,      &ChatHandler::HandleModifySwimCommand,          "", NULL },
        { "scale",          SEC_MODERATOR,      &ChatHandler::HandleModifyScaleCommand,         "", NULL },
        { "bit",            SEC_MODERATOR,      &ChatHandler::HandleModifyBitCommand,           "", NULL },
        { "bwalk",          SEC_MODERATOR,      &ChatHandler::HandleModifyBWalkCommand,         "", NULL },
        { "fly",            SEC_MODERATOR,      &ChatHandler::HandleModifyFlyCommand,           "", NULL },
        { "aspeed",         SEC_MODERATOR,      &ChatHandler::HandleModifyASpeedCommand,        "", NULL },
        { "faction",        SEC_MODERATOR,      &ChatHandler::HandleModifyFactionCommand,       "", NULL },
        { "spell",          SEC_MODERATOR,      &ChatHandler::HandleModifySpellCommand,         "", NULL },
        { "tp",             SEC_MODERATOR,      &ChatHandler::HandleModifyTalentCommand,        "", NULL },
        { "titles",         SEC_MODERATOR,      &ChatHandler::HandleModifyKnownTitlesCommand,   "", NULL },
        { "mount",          SEC_MODERATOR,      &ChatHandler::HandleModifyMountCommand,         "", NULL },
        { "honor",          SEC_MODERATOR,      &ChatHandler::HandleModifyHonorCommand,         "", NULL },
        { "rep",            SEC_MODERATOR,      &ChatHandler::HandleModifyRepCommand,           "", NULL },
        { "arena",          SEC_MODERATOR,      &ChatHandler::HandleModifyArenaCommand,         "", NULL },
        { "drunk",          SEC_MODERATOR,      &ChatHandler::HandleDrunkCommand,               "", NULL },
        { "standstate",     SEC_GAMEMASTER,     &ChatHandler::HandleStandStateCommand,          "", NULL },
        { "morph",          SEC_GAMEMASTER,     &ChatHandler::HandleMorphCommand,               "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand wpCommandTable[] =
    {
        { "show",           SEC_GAMEMASTER,     &ChatHandler::HandleWpShowCommand,              "", NULL },
        { "add",            SEC_GAMEMASTER,     &ChatHandler::HandleWpAddCommand,               "", NULL },
        { "modify",         SEC_GAMEMASTER,     &ChatHandler::HandleWpModifyCommand,            "", NULL },
        { "export",         SEC_ADMINISTRATOR,  &ChatHandler::HandleWpExportCommand,            "", NULL },
        { "import",         SEC_ADMINISTRATOR,  &ChatHandler::HandleWpImportCommand,            "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand debugCommandTable[] =
    {
        { "inarc",          SEC_ADMINISTRATOR,  &ChatHandler::HandleDebugInArcCommand,          "", NULL },
        { "spellfail",      SEC_ADMINISTRATOR,  &ChatHandler::HandleDebugSpellFailCommand,      "", NULL },
        { "setpoi",         SEC_ADMINISTRATOR,  &ChatHandler::HandleSetPoiCommand,              "", NULL },
        { "qpartymsg",      SEC_ADMINISTRATOR,  &ChatHandler::HandleSendQuestPartyMsgCommand,   "", NULL },
        { "qinvalidmsg",    SEC_ADMINISTRATOR,  &ChatHandler::HandleSendQuestInvalidMsgCommand, "", NULL },
        { "equiperr",       SEC_ADMINISTRATOR,  &ChatHandler::HandleEquipErrorCommand,          "", NULL },
        { "sellerr",        SEC_ADMINISTRATOR,  &ChatHandler::HandleSellErrorCommand,           "", NULL },
        { "buyerr",         SEC_ADMINISTRATOR,  &ChatHandler::HandleBuyErrorCommand,            "", NULL },
        { "sendopcode",     SEC_ADMINISTRATOR,  &ChatHandler::HandleSendOpcodeCommand,          "", NULL },
        { "uws",            SEC_ADMINISTRATOR,  &ChatHandler::HandleUpdateWorldStateCommand,    "", NULL },
        { "ps",             SEC_ADMINISTRATOR,  &ChatHandler::HandlePlaySound2Command,          "", NULL },
        { "scn",            SEC_ADMINISTRATOR,  &ChatHandler::HandleSendChannelNotifyCommand,   "", NULL },
        { "scm",            SEC_ADMINISTRATOR,  &ChatHandler::HandleSendChatMsgCommand,         "", NULL },
        { "getitemstate",   SEC_ADMINISTRATOR,  &ChatHandler::HandleGetItemState,               "", NULL },
        { "playsound",      SEC_MODERATOR,      &ChatHandler::HandlePlaySoundCommand,           "", NULL },
        { "update",         SEC_ADMINISTRATOR,  &ChatHandler::HandleUpdate,                     "", NULL },
        { "setvalue",       SEC_ADMINISTRATOR,  &ChatHandler::HandleSetValue,                   "", NULL },
        { "getvalue",       SEC_ADMINISTRATOR,  &ChatHandler::HandleGetValue,                   "", NULL },
        { "Mod32Value",     SEC_ADMINISTRATOR,  &ChatHandler::HandleMod32Value,                 "", NULL },
        { "anim",           SEC_GAMEMASTER,     &ChatHandler::HandleAnimCommand,                "", NULL },
        { "lootrecipient",  SEC_GAMEMASTER,     &ChatHandler::HandleGetLootRecipient,           "", NULL },
        { "arena",          SEC_ADMINISTRATOR,  &ChatHandler::HandleDebugArenaCommand,          "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand eventCommandTable[] =
    {
        { "activelist",     SEC_GAMEMASTER,     &ChatHandler::HandleEventActiveListCommand,     "", NULL },
        { "start",          SEC_GAMEMASTER,     &ChatHandler::HandleEventStartCommand,          "", NULL },
        { "stop",           SEC_GAMEMASTER,     &ChatHandler::HandleEventStopCommand,           "", NULL },
        { "",               SEC_GAMEMASTER,     &ChatHandler::HandleEventInfoCommand,           "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand learnCommandTable[] =
    {
        { "all",            SEC_ADMINISTRATOR,  &ChatHandler::HandleLearnAllCommand,            "", NULL },
        { "all_gm",         SEC_GAMEMASTER,     &ChatHandler::HandleLearnAllGMCommand,          "", NULL },
        { "all_crafts",     SEC_GAMEMASTER,     &ChatHandler::HandleLearnAllCraftsCommand,      "", NULL },
        { "all_default",    SEC_MODERATOR,      &ChatHandler::HandleLearnAllDefaultCommand,     "", NULL },
        { "all_lang",       SEC_MODERATOR,      &ChatHandler::HandleLearnAllLangCommand,        "", NULL },
        { "all_myclass",    SEC_ADMINISTRATOR,  &ChatHandler::HandleLearnAllMyClassCommand,     "", NULL },
        { "all_myspells",   SEC_ADMINISTRATOR,  &ChatHandler::HandleLearnAllMySpellsCommand,    "", NULL },
        { "all_mytalents",  SEC_ADMINISTRATOR,  &ChatHandler::HandleLearnAllMyTalentsCommand,   "", NULL },
        { "all_recipes",    SEC_GAMEMASTER,     &ChatHandler::HandleLearnAllRecipesCommand,     "", NULL },
        { "",               SEC_ADMINISTRATOR,  &ChatHandler::HandleLearnCommand,               "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand reloadCommandTable[] =
    {
        { "all",            SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllCommand,           "", NULL },
        { "all_loot",       SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllLootCommand,       "", NULL },
        { "all_npc",        SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllNpcCommand,        "", NULL },
        { "all_quest",      SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllQuestCommand,      "", NULL },
        { "all_scripts",    SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllScriptsCommand,    "", NULL },
        { "all_spell",      SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllSpellCommand,      "", NULL },
        { "all_item",       SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadAllItemCommand,       "", NULL },

        { "config",         SEC_ADMINISTRATOR,  &ChatHandler::HandleReloadConfigCommand,        "", NULL },

        { "areatrigger_tavern",          SEC_ADMINISTRATOR, &ChatHandler::HandleReloadAreaTriggerTavernCommand,       "", NULL },
        { "areatrigger_teleport",        SEC_ADMINISTRATOR, &ChatHandler::HandleReloadAreaTriggerTeleportCommand,     "", NULL },
        { "areatrigger_involvedrelation",SEC_ADMINISTRATOR, &ChatHandler::HandleReloadQuestAreaTriggersCommand,       "", NULL },
        { "event_scripts",               SEC_ADMINISTRATOR, &ChatHandler::HandleReloadEventScriptsCommand,            "", NULL },
        { "command",                     SEC_ADMINISTRATOR, &ChatHandler::HandleReloadCommandCommand,                 "", NULL },
        { "creature_involvedrelation",   SEC_ADMINISTRATOR, &ChatHandler::HandleReloadCreatureQuestInvRelationsCommand,"",NULL },
        { "creature_loot_template",      SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesCreatureCommand,   "", NULL },
        { "creature_questrelation",      SEC_ADMINISTRATOR, &ChatHandler::HandleReloadCreatureQuestRelationsCommand,  "", NULL },
        { "disenchant_loot_template",    SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesDisenchantCommand, "", NULL },
        { "fishing_loot_template",       SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesFishingCommand,    "", NULL },
        { "game_graveyard_zone",         SEC_ADMINISTRATOR, &ChatHandler::HandleReloadGameGraveyardZoneCommand,       "", NULL },
        { "game_tele",                   SEC_ADMINISTRATOR, &ChatHandler::HandleReloadGameTeleCommand,                "", NULL },
        { "gameobject_involvedrelation", SEC_ADMINISTRATOR, &ChatHandler::HandleReloadGOQuestInvRelationsCommand,     "", NULL },
        { "gameobject_loot_template",    SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesGameobjectCommand, "", NULL },
        { "gameobject_questrelation",    SEC_ADMINISTRATOR, &ChatHandler::HandleReloadGOQuestRelationsCommand,        "", NULL },
        { "gameobject_scripts",          SEC_ADMINISTRATOR, &ChatHandler::HandleReloadGameObjectScriptsCommand,       "", NULL },
        { "item_enchantment_template",   SEC_ADMINISTRATOR, &ChatHandler::HandleReloadItemEnchantementsCommand,       "", NULL },
        { "item_loot_template",          SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesItemCommand,       "", NULL },
        { "mangos_string",               SEC_ADMINISTRATOR, &ChatHandler::HandleReloadMangosStringCommand,            "", NULL },
        { "npc_gossip",                  SEC_ADMINISTRATOR, &ChatHandler::HandleReloadNpcGossipCommand,               "", NULL },
        { "npc_trainer",                 SEC_ADMINISTRATOR, &ChatHandler::HandleReloadNpcTrainerCommand,              "", NULL },
        { "npc_vendor",                  SEC_ADMINISTRATOR, &ChatHandler::HandleReloadNpcVendorCommand,               "", NULL },
        { "page_text",                   SEC_ADMINISTRATOR, &ChatHandler::HandleReloadPageTextsCommand,               "", NULL },
        { "pickpocketing_loot_template", SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesPickpocketingCommand,"",NULL},
        { "prospecting_loot_template",   SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesProspectingCommand,"", NULL },
        { "quest_mail_loot_template",    SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesQuestMailCommand,  "", NULL },
        { "quest_end_scripts",           SEC_ADMINISTRATOR, &ChatHandler::HandleReloadQuestEndScriptsCommand,         "", NULL },
        { "quest_start_scripts",         SEC_ADMINISTRATOR, &ChatHandler::HandleReloadQuestStartScriptsCommand,       "", NULL },
        { "quest_template",              SEC_ADMINISTRATOR, &ChatHandler::HandleReloadQuestTemplateCommand,           "", NULL },
        { "reference_loot_template",     SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesReferenceCommand,  "", NULL },
        { "reserved_name",               SEC_ADMINISTRATOR, &ChatHandler::HandleReloadReservedNameCommand,            "", NULL },
        { "skill_discovery_template",    SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSkillDiscoveryTemplateCommand,  "", NULL },
        { "skill_extra_item_template",   SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSkillExtraItemTemplateCommand,  "", NULL },
        { "skill_fishing_base_level",    SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSkillFishingBaseLevelCommand,   "", NULL },
        { "skinning_loot_template",      SEC_ADMINISTRATOR, &ChatHandler::HandleReloadLootTemplatesSkinningCommand,   "", NULL },
        { "spell_affect",                SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellAffectCommand,             "", NULL },
        { "spell_chain",                 SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellChainCommand,              "", NULL },
        { "spell_elixir",                SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellElixirCommand,             "", NULL },
        { "spell_learn_spell",           SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellLearnSpellCommand,         "", NULL },
        { "spell_pet_auras",             SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellPetAurasCommand,           "", NULL },
        { "spell_proc_event",            SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellProcEventCommand,          "", NULL },
        { "spell_script_target",         SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellScriptTargetCommand,       "", NULL },
        { "spell_scripts",               SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellScriptsCommand,            "", NULL },
        { "spell_target_position",       SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellTargetPositionCommand,     "", NULL },
        { "spell_threats",               SEC_ADMINISTRATOR, &ChatHandler::HandleReloadSpellThreatsCommand,            "", NULL },
        { "",                            SEC_ADMINISTRATOR, &ChatHandler::HandleReloadCommand,                        "", NULL },
        { NULL,                          0,                 NULL,                                                     "", NULL }
    };

    static ChatCommand honorCommandTable[] =
    {
        { "add",            SEC_GAMEMASTER,     &ChatHandler::HandleAddHonorCommand,            "", NULL },
        { "addkill",        SEC_GAMEMASTER,     &ChatHandler::HandleHonorAddKillCommand,        "", NULL },
        { "update",         SEC_GAMEMASTER,     &ChatHandler::HandleUpdateHonorFieldsCommand,   "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand guildCommandTable[] =
    {
        { "create",         SEC_GAMEMASTER,     &ChatHandler::HandleGuildCreateCommand,         "", NULL },
        { "delete",         SEC_GAMEMASTER,     &ChatHandler::HandleGuildDeleteCommand,         "", NULL },
        { "invite",         SEC_GAMEMASTER,     &ChatHandler::HandleGuildInviteCommand,         "", NULL },
        { "uninvite",       SEC_GAMEMASTER,     &ChatHandler::HandleGuildUninviteCommand,       "", NULL },
        { "rank",           SEC_GAMEMASTER,     &ChatHandler::HandleGuildRankCommand,           "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand lookupPlayerCommandTable[] =
    {
        { "ip",            SEC_GAMEMASTER,     &ChatHandler::HandleLookupPlayerIpCommand,       "", NULL },
        { "account",       SEC_GAMEMASTER,     &ChatHandler::HandleLookupPlayerAccountCommand,  "", NULL },
        { "email",         SEC_GAMEMASTER,     &ChatHandler::HandleLookupPlayerEmailCommand,    "", NULL },
        { NULL,            0,                  NULL,                                            "", NULL }
    };

    static ChatCommand lookupCommandTable[] =
    {
        { "area",           SEC_MODERATOR,      &ChatHandler::HandleLookupAreaCommand,          "", NULL },
        { "creature",       SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupCreatureCommand,      "", NULL },
        { "event",          SEC_GAMEMASTER,     &ChatHandler::HandleLookupEventCommand,         "", NULL },
        { "faction",        SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupFactionCommand,       "", NULL },
        { "item",           SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupItemCommand,          "", NULL },
        { "itemset",        SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupItemSetCommand,       "", NULL },
        { "object",         SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupObjectCommand,        "", NULL },
        { "quest",          SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupQuestCommand,         "", NULL },
        { "player",         SEC_GAMEMASTER,     NULL,                                           "", lookupPlayerCommandTable },
        { "skill",          SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupSkillCommand,         "", NULL },
        { "spell",          SEC_ADMINISTRATOR,  &ChatHandler::HandleLookupSpellCommand,         "", NULL },
        { "tele",           SEC_MODERATOR,      &ChatHandler::HandleLookupTeleCommand,          "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand resetCommandTable[] =
    {
        { "honor",          SEC_ADMINISTRATOR,  &ChatHandler::HandleResetHonorCommand,          "", NULL },
        { "level",          SEC_ADMINISTRATOR,  &ChatHandler::HandleResetLevelCommand,          "", NULL },
        { "spells",         SEC_ADMINISTRATOR,  &ChatHandler::HandleResetSpellsCommand,         "", NULL },
        { "stats",          SEC_ADMINISTRATOR,  &ChatHandler::HandleResetStatsCommand,          "", NULL },
        { "talents",        SEC_ADMINISTRATOR,  &ChatHandler::HandleResetTalentsCommand,        "", NULL },
        { "all",            SEC_ADMINISTRATOR,  &ChatHandler::HandleResetAllCommand,            "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand castCommandTable[] =
    {
        { "back",           SEC_ADMINISTRATOR,  &ChatHandler::HandleCastBackCommand,            "", NULL },
        { "dist",           SEC_ADMINISTRATOR,  &ChatHandler::HandleCastDistCommand,            "", NULL },
        { "self",           SEC_ADMINISTRATOR,  &ChatHandler::HandleCastSelfCommand,            "", NULL },
        { "target",         SEC_ADMINISTRATOR,  &ChatHandler::HandleCastTargetCommand,          "", NULL },
        { "",               SEC_ADMINISTRATOR,  &ChatHandler::HandleCastCommand,                "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand pdumpCommandTable[] =
    {
        { "load",           SEC_ADMINISTRATOR,  &ChatHandler::HandleLoadPDumpCommand,           "", NULL },
        { "write",          SEC_ADMINISTRATOR,  &ChatHandler::HandleWritePDumpCommand,          "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand listCommandTable[] =
    {
        { "creature",       SEC_ADMINISTRATOR,  &ChatHandler::HandleListCreatureCommand,        "", NULL },
        { "item",           SEC_ADMINISTRATOR,  &ChatHandler::HandleListItemCommand,            "", NULL },
        { "object",         SEC_ADMINISTRATOR,  &ChatHandler::HandleListObjectCommand,          "", NULL },
        { "auras",          SEC_ADMINISTRATOR,  &ChatHandler::HandleListAurasCommand,           "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand teleCommandTable[] =
    {
        { "add",            SEC_ADMINISTRATOR,  &ChatHandler::HandleAddTeleCommand,             "", NULL },
        { "del",            SEC_ADMINISTRATOR,  &ChatHandler::HandleDelTeleCommand,             "", NULL },
        { "name",           SEC_MODERATOR,      &ChatHandler::HandleNameTeleCommand,            "", NULL },
        { "group",          SEC_MODERATOR,      &ChatHandler::HandleGroupTeleCommand,           "", NULL },
        { "",               SEC_MODERATOR,      &ChatHandler::HandleTeleCommand,                "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand npcCommandTable[] =
    {
        { "say",            SEC_MODERATOR,      &ChatHandler::HandleSayCommand,                 "", NULL },
        { "whisper",        SEC_MODERATOR,      &ChatHandler::HandleNpcWhisperCommand,          "", NULL },
        { "yell",           SEC_MODERATOR,      &ChatHandler::HandleYellCommand,                "", NULL },
        { "textemote",      SEC_MODERATOR,      &ChatHandler::HandleTextEmoteCommand,           "", NULL },
        { "add",            SEC_GAMEMASTER,     &ChatHandler::HandleAddSpwCommand,              "", NULL },
        { "delete",         SEC_GAMEMASTER,     &ChatHandler::HandleDelCreatureCommand,         "", NULL },
        { "spawndist",      SEC_GAMEMASTER,     &ChatHandler::HandleSpawnDistCommand,           "", NULL },
        { "spawntime",      SEC_GAMEMASTER,     &ChatHandler::HandleSpawnTimeCommand,           "", NULL },
        { "factionid",      SEC_GAMEMASTER,     &ChatHandler::HandleFactionIdCommand,           "", NULL },
        { "addmove",        SEC_GAMEMASTER,     &ChatHandler::HandleAddMoveCommand,             "", NULL },
        { "setmovetype",    SEC_GAMEMASTER,     &ChatHandler::HandleSetMoveTypeCommand,         "", NULL },
        { "move",           SEC_GAMEMASTER,     &ChatHandler::HandleMoveCreatureCommand,        "", NULL },
        { "changelevel",    SEC_GAMEMASTER,     &ChatHandler::HandleChangeLevelCommand,         "", NULL },
        { "setmodel",       SEC_GAMEMASTER,     &ChatHandler::HandleSetModelCommand,            "", NULL },
        { "additem",        SEC_GAMEMASTER,     &ChatHandler::HandleAddVendorItemCommand,       "", NULL },
        { "delitem",        SEC_GAMEMASTER,     &ChatHandler::HandleDelVendorItemCommand,       "", NULL },
        { "flag",           SEC_GAMEMASTER,     &ChatHandler::HandleNPCFlagCommand,             "", NULL },
        { "changeentry",    SEC_ADMINISTRATOR,  &ChatHandler::HandleChangeEntryCommand,         "", NULL },
        { "info",           SEC_ADMINISTRATOR,  &ChatHandler::HandleNpcInfoCommand,             "", NULL },
        { "playemote",      SEC_ADMINISTRATOR,  &ChatHandler::HandlePlayEmoteCommand,           "", NULL },

        //{ TODO: fix or remove this commands
        { "name",           SEC_GAMEMASTER,     &ChatHandler::HandleNameCommand,                "", NULL },
        { "subname",        SEC_GAMEMASTER,     &ChatHandler::HandleSubNameCommand,             "", NULL },
        { "addweapon",      SEC_ADMINISTRATOR,  &ChatHandler::HandleAddWeaponCommand,           "", NULL },
        //}

        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand goCommandTable[] =
    {
        { "grid",           SEC_MODERATOR,      &ChatHandler::HandleGoGridCommand,              "", NULL },
        { "creature",       SEC_GAMEMASTER,     &ChatHandler::HandleGoCreatureCommand,          "", NULL },
        { "object",         SEC_GAMEMASTER,     &ChatHandler::HandleGoObjectCommand,            "", NULL },
        { "trigger",        SEC_GAMEMASTER,     &ChatHandler::HandleGoTriggerCommand,           "", NULL },
        { "graveyard",      SEC_GAMEMASTER,     &ChatHandler::HandleGoGraveyardCommand,         "", NULL },
        { "zonexy",         SEC_MODERATOR,      &ChatHandler::HandleGoZoneXYCommand,            "", NULL },
        { "xy",             SEC_MODERATOR,      &ChatHandler::HandleGoXYCommand,                "", NULL },
        { "xyz",            SEC_MODERATOR,      &ChatHandler::HandleGoXYZCommand,               "", NULL },
        { "",               SEC_MODERATOR,      &ChatHandler::HandleGoXYZCommand,               "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand gobjectCommandTable[] =
    {
        { "add",            SEC_GAMEMASTER,     &ChatHandler::HandleGameObjectCommand,          "", NULL },
        { "delete",         SEC_GAMEMASTER,     &ChatHandler::HandleDelObjectCommand,           "", NULL },
        { "target",         SEC_GAMEMASTER,     &ChatHandler::HandleTargetObjectCommand,        "", NULL },
        { "turn",           SEC_GAMEMASTER,     &ChatHandler::HandleTurnObjectCommand,          "", NULL },
        { "move",           SEC_GAMEMASTER,     &ChatHandler::HandleMoveObjectCommand,          "", NULL },
        { "near",           SEC_ADMINISTRATOR,  &ChatHandler::HandleNearObjectCommand,          "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand questCommandTable[] =
    {
        { "add",            SEC_ADMINISTRATOR,  &ChatHandler::HandleAddQuest,                   "", NULL },
        { "complete",       SEC_ADMINISTRATOR,  &ChatHandler::HandleCompleteQuest,              "", NULL },
        { "remove",         SEC_ADMINISTRATOR,  &ChatHandler::HandleRemoveQuest,                "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand gmCommandTable[] =
    {
        { "chat",           SEC_MODERATOR,      &ChatHandler::HandleGMChatCommand,              "", NULL },
        { "list",           SEC_PLAYER,         &ChatHandler::HandleGMListCommand,              "", NULL },
        { "visible",        SEC_MODERATOR,      &ChatHandler::HandleVisibleCommand,             "", NULL },
        { "fly",            SEC_ADMINISTRATOR,  &ChatHandler::HandleFlyModeCommand,             "", NULL },
        { "",               SEC_MODERATOR,      &ChatHandler::HandleGMmodeCommand,              "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand instanceCommandTable[] =
    {
        { "listbinds",      SEC_MODERATOR,      &ChatHandler::HandleInstanceListBindsCommand,   "", NULL },
        { "unbind",         SEC_MODERATOR,      &ChatHandler::HandleInstanceUnbindCommand,      "", NULL },
        { "stats",          SEC_MODERATOR,      &ChatHandler::HandleInstanceStatsCommand,       "", NULL },
        { "savedata",       SEC_MODERATOR,      &ChatHandler::HandleInstanceSaveDataCommand,    "", NULL },
        { NULL,             0,                  NULL,                                           "", NULL }
    };

    static ChatCommand commandTable[] =
    {
        { "gm",             SEC_MODERATOR,      NULL,                                           "", gmCommandTable },
        { "npc",            SEC_MODERATOR,      NULL,                                           "", npcCommandTable },
        { "go",             SEC_MODERATOR,      NULL,                                           "", goCommandTable },
        { "learn",          SEC_MODERATOR,      NULL,                                           "", learnCommandTable },
        { "modify",         SEC_MODERATOR,      NULL,                                           "", modifyCommandTable },
        { "debug",          SEC_MODERATOR,      NULL,                                           "", debugCommandTable },
        { "tele",           SEC_MODERATOR,      NULL,                                           "", teleCommandTable },
        { "event",          SEC_GAMEMASTER,     NULL,                                           "", eventCommandTable },
        { "gobject",        SEC_GAMEMASTER,     NULL,                                           "", gobjectCommandTable },
        { "honor",          SEC_GAMEMASTER,     NULL,                                           "", honorCommandTable },
        { "wp",             SEC_GAMEMASTER,     NULL,                                           "", wpCommandTable },
        { "quest",          SEC_ADMINISTRATOR,  NULL,                                           "", questCommandTable },
        { "reload",         SEC_ADMINISTRATOR,  NULL,                                           "", reloadCommandTable },
        { "list",           SEC_ADMINISTRATOR,  NULL,                                           "", listCommandTable },
        { "lookup",         SEC_ADMINISTRATOR,  NULL,                                           "", lookupCommandTable },
        { "pdump",          SEC_ADMINISTRATOR,  NULL,                                           "", pdumpCommandTable },
        { "guild",          SEC_ADMINISTRATOR,  NULL,                                           "", guildCommandTable },
        { "cast",           SEC_ADMINISTRATOR,  NULL,                                           "", castCommandTable },
        { "reset",          SEC_ADMINISTRATOR,  NULL,                                           "", resetCommandTable },
        { "instance",       SEC_ADMINISTRATOR,  NULL,                                           "", instanceCommandTable },
        { "server",         SEC_ADMINISTRATOR,  NULL,                                           "", serverCommandTable },

        { "aura",           SEC_ADMINISTRATOR,  &ChatHandler::HandleAuraCommand,                "", NULL },
        { "unaura",         SEC_ADMINISTRATOR,  &ChatHandler::HandleUnAuraCommand,              "", NULL },
        { "acct",           SEC_PLAYER,         &ChatHandler::HandleAcctCommand,                "", NULL },
        { "announce",       SEC_MODERATOR,      &ChatHandler::HandleAnnounceCommand,            "", NULL },
        { "notify",         SEC_MODERATOR,      &ChatHandler::HandleNotifyCommand,              "", NULL },
        { "goname",         SEC_MODERATOR,      &ChatHandler::HandleGonameCommand,              "", NULL },
        { "namego",         SEC_MODERATOR,      &ChatHandler::HandleNamegoCommand,              "", NULL },
        { "groupgo",        SEC_MODERATOR,      &ChatHandler::HandleGroupgoCommand,             "", NULL },
        { "commands",       SEC_PLAYER,         &ChatHandler::HandleCommandsCommand,            "", NULL },
        { "demorph",        SEC_GAMEMASTER,     &ChatHandler::HandleDeMorphCommand,             "", NULL },
        { "die",            SEC_ADMINISTRATOR,  &ChatHandler::HandleDieCommand,                 "", NULL },
        { "revive",         SEC_ADMINISTRATOR,  &ChatHandler::HandleReviveCommand,              "", NULL },
        { "dismount",       SEC_PLAYER,         &ChatHandler::HandleDismountCommand,            "", NULL },
        { "gps",            SEC_MODERATOR,      &ChatHandler::HandleGPSCommand,                 "", NULL },
        { "guid",           SEC_GAMEMASTER,     &ChatHandler::HandleGUIDCommand,                "", NULL },
        { "help",           SEC_PLAYER,         &ChatHandler::HandleHelpCommand,                "", NULL },
        { "itemmove",       SEC_GAMEMASTER,     &ChatHandler::HandleItemMoveCommand,            "", NULL },
        { "cooldown",       SEC_ADMINISTRATOR,  &ChatHandler::HandleCooldownCommand,            "", NULL },
        { "unlearn",        SEC_ADMINISTRATOR,  &ChatHandler::HandleUnLearnCommand,             "", NULL },
        { "distance",       SEC_ADMINISTRATOR,  &ChatHandler::HandleGetDistanceCommand,         "", NULL },
        { "recall",         SEC_MODERATOR,      &ChatHandler::HandleRecallCommand,              "", NULL },
        { "save",           SEC_PLAYER,         &ChatHandler::HandleSaveCommand,                "", NULL },
        { "saveall",        SEC_MODERATOR,      &ChatHandler::HandleSaveAllCommand,             "", NULL },
        { "kick",           SEC_GAMEMASTER,     &ChatHandler::HandleKickPlayerCommand,          "", NULL },
        { "security",       SEC_ADMINISTRATOR,  &ChatHandler::HandleSecurityCommand,            "", NULL },
        { "ban",            SEC_ADMINISTRATOR,  &ChatHandler::HandleBanCommand,                 "", NULL },
        { "unban",          SEC_ADMINISTRATOR,  &ChatHandler::HandleUnBanCommand,               "", NULL },
        { "baninfo",        SEC_ADMINISTRATOR,  &ChatHandler::HandleBanInfoCommand,             "", NULL },
        { "banlist",        SEC_ADMINISTRATOR,  &ChatHandler::HandleBanListCommand,             "", NULL },
        { "plimit",         SEC_ADMINISTRATOR,  &ChatHandler::HandlePLimitCommand,              "", NULL },
        { "start",          SEC_PLAYER,         &ChatHandler::HandleStartCommand,               "", NULL },
        { "taxicheat",      SEC_MODERATOR,      &ChatHandler::HandleTaxiCheatCommand,           "", NULL },
        { "allowmove",      SEC_ADMINISTRATOR,  &ChatHandler::HandleAllowMovementCommand,       "", NULL },
        { "linkgrave",      SEC_ADMINISTRATOR,  &ChatHandler::HandleLinkGraveCommand,           "", NULL },
        { "neargrave",      SEC_ADMINISTRATOR,  &ChatHandler::HandleNearGraveCommand,           "", NULL },
        { "transport",      SEC_ADMINISTRATOR,  &ChatHandler::HandleSpawnTransportCommand,      "", NULL },
        { "explorecheat",   SEC_ADMINISTRATOR,  &ChatHandler::HandleExploreCheatCommand,        "", NULL },
        { "hover",          SEC_ADMINISTRATOR,  &ChatHandler::HandleHoverCommand,               "", NULL },
        { "levelup",        SEC_ADMINISTRATOR,  &ChatHandler::HandleLevelUpCommand,             "", NULL },
        { "showarea",       SEC_ADMINISTRATOR,  &ChatHandler::HandleShowAreaCommand,            "", NULL },
        { "hidearea",       SEC_ADMINISTRATOR,  &ChatHandler::HandleHideAreaCommand,            "", NULL },
        { "additem",        SEC_ADMINISTRATOR,  &ChatHandler::HandleAddItemCommand,             "", NULL },
        { "additemset",     SEC_ADMINISTRATOR,  &ChatHandler::HandleAddItemSetCommand,          "", NULL },
        { "bank",           SEC_ADMINISTRATOR,  &ChatHandler::HandleBankCommand,                "", NULL },
        { "wchange",        SEC_ADMINISTRATOR,  &ChatHandler::HandleChangeWeather,              "", NULL },
        { "ticket",         SEC_GAMEMASTER,     &ChatHandler::HandleTicketCommand,              "", NULL },
        { "delticket",      SEC_GAMEMASTER,     &ChatHandler::HandleDelTicketCommand,           "", NULL },
        { "maxskill",       SEC_ADMINISTRATOR,  &ChatHandler::HandleMaxSkillCommand,            "", NULL },
        { "setskill",       SEC_ADMINISTRATOR,  &ChatHandler::HandleSetSkillCommand,            "", NULL },
        { "whispers",       SEC_MODERATOR,      &ChatHandler::HandleWhispersCommand,            "", NULL },
        { "pinfo",          SEC_GAMEMASTER,     &ChatHandler::HandlePInfoCommand,               "", NULL },
        { "password",       SEC_PLAYER,         &ChatHandler::HandlePasswordCommand,            "", NULL },
        { "lockaccount",    SEC_PLAYER,         &ChatHandler::HandleLockAccountCommand,         "", NULL },
        { "respawn",        SEC_ADMINISTRATOR,  &ChatHandler::HandleRespawnCommand,             "", NULL },
        { "sendmail",       SEC_MODERATOR,      &ChatHandler::HandleSendMailCommand,            "", NULL },
        { "rename",         SEC_GAMEMASTER,     &ChatHandler::HandleRenameCommand,              "", NULL },
        { "loadscripts",    SEC_ADMINISTRATOR,  &ChatHandler::HandleLoadScriptsCommand,         "", NULL },
        { "mute",           SEC_GAMEMASTER,     &ChatHandler::HandleMuteCommand,                "", NULL },
        { "unmute",         SEC_GAMEMASTER,     &ChatHandler::HandleUnmuteCommand,              "", NULL },
        { "movegens",       SEC_ADMINISTRATOR,  &ChatHandler::HandleMovegensCommand,            "", NULL },
        { "cometome",       SEC_ADMINISTRATOR,  &ChatHandler::HandleComeToMeCommand,            "", NULL },
        { "damage",         SEC_ADMINISTRATOR,  &ChatHandler::HandleDamageCommand,              "", NULL },
        { "ircpm",          SEC_PLAYER,         &ChatHandler::HandleIRCpmCommand,               "", NULL },
        { "combatstop",     SEC_GAMEMASTER,     &ChatHandler::HandleCombatStopCommand,          "", NULL },
        { "flusharenapoints",    SEC_ADMINISTRATOR, &ChatHandler::HandleFlushArenaPointsCommand,         "",   NULL },

        { NULL,             0,                  NULL,                                           "", NULL }
    };

    if(load_command_table)
    {
        load_command_table = false;

        QueryResult *result = WorldDatabase.Query("SELECT name,security,help FROM command");
        if (result)
        {
            do
            {
                Field *fields = result->Fetch();
                std::string name = fields[0].GetCppString();
                for(uint32 i = 0; commandTable[i].Name != NULL; i++)
                {
                    if (name == commandTable[i].Name)
                    {
                        commandTable[i].SecurityLevel = (uint16)fields[1].GetUInt16();
                        commandTable[i].Help = fields[2].GetCppString();
                    }
                    if(commandTable[i].ChildCommands != NULL)
                    {
                        ChatCommand *ptable = commandTable[i].ChildCommands;
                        for(uint32 j = 0; ptable[j].Name != NULL; j++)
                        {
                            // first case for "" named subcommand
                            if (ptable[j].Name[0]=='\0' && name == commandTable[i].Name ||
                                name == fmtstring("%s %s", commandTable[i].Name, ptable[j].Name) )
                            {
                                ptable[j].SecurityLevel = (uint16)fields[1].GetUInt16();
                                ptable[j].Help = fields[2].GetCppString();
                            }
                        }
                    }
                }
            } while(result->NextRow());
            delete result;
        }
    }

    return commandTable;
}

const char *ChatHandler::GetMangosString(int32 entry)
{
    return m_session->GetMangosString(entry);
}

bool ChatHandler::hasStringAbbr(const char* name, const char* part)
{
    // non "" command
    if( *name )
    {
        // "" part from non-"" command
        if( !*part )
            return false;

        for(;;)
        {
            if( !*part )
                return true;
            else if( !*name )
                return false;
            else if( tolower( *name ) != tolower( *part ) )
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

    while(char* line = LineFromMessage(pos))
    {
        FillSystemMessageData(&data, line);
        m_session->SendPacket(&data);
    }

    free(buf);
}

void ChatHandler::SendGlobalSysMessage(const char *str)
{
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while(char* line = LineFromMessage(pos))
    {
        FillSystemMessageData(&data, line);
        sWorld.SendGlobalMessage(&data);
    }

    free(buf);
}

void ChatHandler::SendSysMessage(int32 entry)
{
    SendSysMessage(GetMangosString(entry));
}

void ChatHandler::PSendSysMessage(int32 entry, ...)
{
    const char *format = GetMangosString(entry);
    va_list ap;
    char str [1024];
    va_start(ap, entry);
    vsnprintf(str,1024,format, ap );
    va_end(ap);
    SendSysMessage(str);
}

void ChatHandler::PSendSysMessage(const char *format, ...)
{
    va_list ap;
    char str [1024];
    va_start(ap, format);
    vsnprintf(str,1024,format, ap );
    va_end(ap);
    SendSysMessage(str);
}

bool ChatHandler::ExecuteCommandInTable(ChatCommand *table, const char* text, std::string fullcmd)
{
    char const* oldtext = text;
    std::string cmd = "";

    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        ++text;
    }

    while (*text == ' ') ++text;

    for(uint32 i = 0; table[i].Name != NULL; i++)
    {
        if( !hasStringAbbr(table[i].Name, cmd.c_str()) )
            continue;

        // select subcommand from child commands list
        if(table[i].ChildCommands != NULL)
        {
            if(!ExecuteCommandInTable(table[i].ChildCommands, text, fullcmd))
            {
                if(text && text[0] != '\0')
                    SendSysMessage(LANG_NO_SUBCMD);
                else
                    SendSysMessage(LANG_CMD_SYNTAX);

                ShowHelpForCommand(table[i].ChildCommands,text);
            }

            return true;
        }

        // check security level only for simple  command (without child commands)
        if(m_session->GetSecurity() < table[i].SecurityLevel)
            continue;

        SetSentErrorMessage(false);
        // table[i].Name == "" is special case: send original command to handler
        if((this->*(table[i].Handler))(strlen(table[i].Name)!=0 ? text : oldtext))
        {
            if(table[i].SecurityLevel > SEC_PLAYER)
            {
                Player* p = m_session->GetPlayer();
                uint64 sel_guid = p->GetSelection();
                sLog.outCommand("Command: %s [Player: %s (Account: %u) X: %f Y: %f Z: %f Map: %u Selected: %s (GUID: %u)]",
                    fullcmd.c_str(),p->GetName(),m_session->GetAccountId(),p->GetPositionX(),p->GetPositionY(),p->GetPositionZ(),p->GetMapId(),
                    GetLogNameForGuid(sel_guid),GUID_LOPART(sel_guid));
            }
        }
        // some commands have custom error messages. Don't send the default one in these cases.
        else if(!sentErrorMessage)
        {
            if(!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());
            else
                SendSysMessage(LANG_CMD_SYNTAX);
        }

        return true;
    }

    return false;
}

int ChatHandler::ParseCommands(const char* text)
{
    ASSERT(text);
    ASSERT(*text);

    //if(m_session->GetSecurity() == 0)
    //    return 0;

    if(text[0] != '!' && text[0] != '.')
        return 0;

    // ignore single . and ! in line
    if(strlen(text) < 2)
        return 0;

    // ignore messages staring from many dots.
    if(text[0] == '.' && text[1] == '.' || text[0] == '!' && text[1] == '!')
        return 0;

    ++text;

    std::string fullcmd = text;                             // original `text` can't be used. It content destroyed in command code processing.

    if(!ExecuteCommandInTable(getCommandTable(), text, fullcmd))
        SendSysMessage(LANG_NO_CMD);

    return 1;
}

bool ChatHandler::ShowHelpForSubCommands(ChatCommand *table, char const* cmd, char const* subcmd)
{
    std::string list;
    for(uint32 i = 0; table[i].Name != NULL; ++i)
    {
        if(m_session->GetSecurity() < table[i].SecurityLevel)
            continue;

        if( !hasStringAbbr(table[i].Name, subcmd) )

        (list += "\n    ") += table[i].Name;
    }

    if(list.empty())
        return false;

    if(table==getCommandTable())
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
    if(*cmd)
    {
        for(uint32 i = 0; table[i].Name != NULL; ++i)
        {
            if(m_session->GetSecurity() < table[i].SecurityLevel)
                continue;

            if( !hasStringAbbr(table[i].Name, cmd) )
                continue;

            // have subcommand
            char const* subcmd = (*cmd) ? strtok(NULL, " ") : "";

            if(table[i].ChildCommands && subcmd && *subcmd)
            {
                if(ShowHelpForCommand(table[i].ChildCommands, subcmd))
                    return true;
            }

            if(!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());

            if(table[i].ChildCommands)
                if(ShowHelpForSubCommands(table[i].ChildCommands,table[i].Name,subcmd ? subcmd : ""))
                    return true;

            return !table[i].Help.empty();
        }
    }
    else
    {
        for(uint32 i = 0; table[i].Name != NULL; ++i)
        {
            if(m_session->GetSecurity() < table[i].SecurityLevel)
                continue;

            if(strlen(table[i].Name))
                continue;

            if(!table[i].Help.empty())
                SendSysMessage(table[i].Help.c_str());

            if(table[i].ChildCommands)
                if(ShowHelpForSubCommands(table[i].ChildCommands,"",""))
                    return true;

            return !table[i].Help.empty();
        }
    }

    return ShowHelpForSubCommands(table,"",cmd);
}

//Note: target_guid used only in CHAT_MSG_WHISPER_INFORM mode (in this case channelName ignored)
void ChatHandler::FillMessageData( WorldPacket *data, WorldSession* session, uint8 type, uint32 language, const char *channelName, uint64 target_guid, const char *message, Unit *speaker)
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
        {
            *data << uint64(speaker->GetGUID());
            *data << uint32(0);                             // 2.1.0
            *data << uint32(strlen(speaker->GetName()) + 1);
            *data << speaker->GetName();
            uint64 listener_guid = 0;
            *data << uint64(listener_guid);
            if(listener_guid && !IS_PLAYER_GUID(listener_guid))
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
            if (type != CHAT_MSG_REPLY && type != CHAT_MSG_IGNORED && type != CHAT_MSG_DND && type != CHAT_MSG_AFK)
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
    if(session != 0 && type != CHAT_MSG_REPLY && type != CHAT_MSG_DND && type != CHAT_MSG_AFK)
        *data << uint8(session->GetPlayer()->chatTag());
    else
        *data << uint8(0);
}

Player * ChatHandler::getSelectedPlayer()
{
    uint64 guid  = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return m_session->GetPlayer();

    return objmgr.GetPlayer(guid);
}

Unit* ChatHandler::getSelectedUnit()
{
    uint64 guid = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return m_session->GetPlayer();

    return ObjectAccessor::GetUnit(*m_session->GetPlayer(),guid);
}

Creature* ChatHandler::getSelectedCreature()
{
    return ObjectAccessor::GetCreatureOrPet(*m_session->GetPlayer(),m_session->GetPlayer()->GetSelection());
}

char* ChatHandler::extractKeyFromLink(char* text, char const* linkType, char** something1)
{
    // skip empty
    if(!text)
        return NULL;

    // skip speces
    while(*text==' '||*text=='\t'||*text=='\b')
        ++text;

    if(!*text)
        return NULL;

    // return non link case
    if(text[0]!='|')
        return strtok(text, " ");

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r

    char* check = strtok(text, "|");                        // skip color
    if(!check)
        return NULL;                                        // end of data

    char* cLinkType = strtok(NULL, ":");                    // linktype
    if(!cLinkType)
        return NULL;                                        // end of data

    if(strcmp(cLinkType,linkType) != 0)
    {
        strtok(NULL, " ");                                  // skip link tail (to allow continue strtok(NULL,s) use after retturn from function
        SendSysMessage(LANG_WRONG_LINK_TYPE);
        return NULL;
    }

    char* cKeys = strtok(NULL, "|");                        // extract keys and values
    char* cKeysTail = strtok(NULL, "");

    char* cKey = strtok(cKeys, ":|");                       // extract key
    if(something1)
        *something1 = strtok(NULL, ":|");                   // extract something

    strtok(cKeysTail, "]");                                 // restart scan tail and skip name with possible spaces
    strtok(NULL, " ");                                      // skip link tail (to allow continue strtok(NULL,s) use after retturn from function
    return cKey;
}

char* ChatHandler::extractKeyFromLink(char* text, char const* const* linkTypes, int* found_idx, char** something1)
{
    // skip empty
    if(!text)
        return NULL;

    // skip speces
    while(*text==' '||*text=='\t'||*text=='\b')
        ++text;

    if(!*text)
        return NULL;

    // return non link case
    if(text[0]!='|')
        return strtok(text, " ");

    // [name] Shift-click form |color|linkType:key|h[name]|h|r
    // or
    // [name] Shift-click form |color|linkType:key:something1:...:somethingN|h[name]|h|r

    char* check = strtok(text, "|");                        // skip color
    if(!check)
        return NULL;                                        // end of data

    char* cLinkType = strtok(NULL, ":");                    // linktype
    if(!cLinkType)
        return NULL;                                        // end of data

    for(int i = 0; linkTypes[i]; ++i)
    {
        if(strcmp(cLinkType,linkTypes[i]) == 0)
        {
            char* cKeys = strtok(NULL, "|");                // extract keys and values
            char* cKeysTail = strtok(NULL, "");

            char* cKey = strtok(cKeys, ":|");               // extract key
            if(something1)
                *something1 = strtok(NULL, ":|");           // extract something

            strtok(cKeysTail, "]");                         // restart scan tail and skip name with possible spaces
            strtok(NULL, " ");                              // skip link tail (to allow continue strtok(NULL,s) use after return from function
            if(found_idx)
                *found_idx = i;
            return cKey;
        }
    }

    strtok(NULL, " ");                                      // skip link tail (to allow continue strtok(NULL,s) use after return from function
    SendSysMessage(LANG_WRONG_LINK_TYPE);
    return NULL;
}

char const *fmtstring( char const *format, ... )
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

    if( len >= MAX_FMT_STRING )
        return "ERROR";

    if (len + index >= MAX_FMT_STRING-1)
    {
        index = 0;
    }

    buf = &string[index];
    memcpy( buf, temp_buffer, len+1 );

    index += len + 1;

    return buf;
}

GameObject* ChatHandler::GetObjectGlobalyWithGuidOrNearWithDbGuid(uint32 lowguid,uint32 entry)
{
    Player* pl = m_session->GetPlayer();

    GameObject* obj = ObjectAccessor::GetGameObject(*pl, MAKE_NEW_GUID(lowguid, entry, HIGHGUID_GAMEOBJECT));

    if(!obj && objmgr.GetGOData(lowguid))                   // guid is DB guid of object
    {
        // search near player then
        CellPair p(MaNGOS::ComputeCellPair(pl->GetPositionX(), pl->GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;

        MaNGOS::GameObjectWithDbGUIDCheck go_check(*pl,lowguid);
        MaNGOS::GameObjectSearcher<MaNGOS::GameObjectWithDbGUIDCheck> checker(obj,go_check);

        TypeContainerVisitor<MaNGOS::GameObjectSearcher<MaNGOS::GameObjectWithDbGUIDCheck>, GridTypeMapContainer > object_checker(checker);
        CellLock<GridReadGuard> cell_lock(cell, p);
        cell_lock->Visit(cell_lock, object_checker, *MapManager::Instance().GetMap(pl->GetMapId(), pl));
    }

    return obj;
}

static char const* const spellTalentKeys[] = {
    "Hspell",
    "Htalent",
    0
};

uint32 ChatHandler::extractSpellIdFromLink(char* text)
{
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    // number or [name] Shift-click form |color|Htalent:telen_id,rank|h[name]|h|r
    int type = 0;
    char* rankS = NULL;
    char* idS = extractKeyFromLink(text,spellTalentKeys,&type,&rankS);
    if(!idS)
        return 0;

    uint32 id = (uint32)atol(idS);

    // spell
    if(type==0)
        return id;

    // talent
    TalentEntry const* talentEntry = sTalentStore.LookupEntry(id);
    if(!talentEntry)
        return 0;

    int32 rank = rankS ? (uint32)atol(rankS) : 0;
    if(rank >= 5)
        return 0;

    if(rank < 0)
        rank = 0;

    return talentEntry->RankID[rank];
}

GameTele const* ChatHandler::extractGameTeleFromLink(char* text)
{
    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    char* cId = extractKeyFromLink(text,"Htele");
    if(!cId)
        return false;

    // id case (explicit or from shift link)
    if(cId[0] >= '0' || cId[0] >= '9')
        if(uint32 id = atoi(cId))
            return objmgr.GetGameTele(id);

    return objmgr.GetGameTele(cId);
}
