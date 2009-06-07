/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#include "TicketMgr.h"

bool ChatHandler::load_command_table = true;

ChatCommand * ChatHandler::getCommandTable()
{
    static ChatCommand accountSetCommandTable[] =
    {
        { "addon",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleAccountSetAddonCommand,     "", NULL },
        { "gmlevel",        SEC_CONSOLE,        true,  &ChatHandler::HandleAccountSetGmLevelCommand,   "", NULL },
        { "password",       SEC_CONSOLE,        true,  &ChatHandler::HandleAccountSetPasswordCommand,  "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand accountCommandTable[] =
    {
        { "create",         SEC_CONSOLE,        true,  &ChatHandler::HandleAccountCreateCommand,       "", NULL },
        { "delete",         SEC_CONSOLE,        true,  &ChatHandler::HandleAccountDeleteCommand,       "", NULL },
        { "onlinelist",     SEC_CONSOLE,        true,  &ChatHandler::HandleAccountOnlineListCommand,   "", NULL },
        { "set",            SEC_ADMINISTRATOR,  true,  NULL,                                           "", accountSetCommandTable },
        { "",               SEC_PLAYER,         false, &ChatHandler::HandleAccountCommand,             "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverSetCommandTable[] =
    {
        { "loglevel",       SEC_CONSOLE,        true,  &ChatHandler::HandleServerSetLogLevelCommand,   "", NULL },
        { "difftime",       SEC_CONSOLE,        true,  &ChatHandler::HandleServerSetDiffTimeCommand,   "", NULL },
        { "motd",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerSetMotdCommand,       "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverIdleRestartCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerIdleRestartCommand,   "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverIdleShutdownCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerIdleShutDownCommand,  "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverRestartCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerRestartCommand,       "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverShutdownCommandTable[] =
    {
        { "cancel",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCancelCommand,"", NULL },
        { ""   ,            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleServerShutDownCommand,      "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand serverCommandTable[] =
    {
        { "corpses",        SEC_GAMEMASTER,     true,  &ChatHandler::HandleServerCorpsesCommand,       "", NULL },
        { "exit",           SEC_CONSOLE,        true,  &ChatHandler::HandleServerExitCommand,          "", NULL },
        { "idlerestart",    SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverIdleRestartCommandTable },
        { "idleshutdown",   SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverShutdownCommandTable },
        { "info",           SEC_PLAYER,         true,  &ChatHandler::HandleServerInfoCommand,          "", NULL },
        { "motd",           SEC_PLAYER,         true,  &ChatHandler::HandleServerMotdCommand,          "", NULL },
        { "restart",        SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverRestartCommandTable },
        { "shutdown",       SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverShutdownCommandTable },
        { "set",            SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverSetCommandTable },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand modifyCommandTable[] =
    {
        { "hp",             SEC_MODERATOR,      false, &ChatHandler::HandleModifyHPCommand,            "", NULL },
        { "mana",           SEC_MODERATOR,      false, &ChatHandler::HandleModifyManaCommand,          "", NULL },
        { "rage",           SEC_MODERATOR,      false, &ChatHandler::HandleModifyRageCommand,          "", NULL },
        { "energy",         SEC_MODERATOR,      false, &ChatHandler::HandleModifyEnergyCommand,        "", NULL },
        { "money",          SEC_MODERATOR,      false, &ChatHandler::HandleModifyMoneyCommand,         "", NULL },
        { "speed",          SEC_MODERATOR,      false, &ChatHandler::HandleModifySpeedCommand,         "", NULL },
        { "swim",           SEC_MODERATOR,      false, &ChatHandler::HandleModifySwimCommand,          "", NULL },
        { "scale",          SEC_MODERATOR,      false, &ChatHandler::HandleModifyScaleCommand,         "", NULL },
        { "bit",            SEC_MODERATOR,      false, &ChatHandler::HandleModifyBitCommand,           "", NULL },
        { "bwalk",          SEC_MODERATOR,      false, &ChatHandler::HandleModifyBWalkCommand,         "", NULL },
        { "fly",            SEC_MODERATOR,      false, &ChatHandler::HandleModifyFlyCommand,           "", NULL },
        { "aspeed",         SEC_MODERATOR,      false, &ChatHandler::HandleModifyASpeedCommand,        "", NULL },
        { "faction",        SEC_MODERATOR,      false, &ChatHandler::HandleModifyFactionCommand,       "", NULL },
        { "spell",          SEC_MODERATOR,      false, &ChatHandler::HandleModifySpellCommand,         "", NULL },
        { "tp",             SEC_MODERATOR,      false, &ChatHandler::HandleModifyTalentCommand,        "", NULL },
        { "titles",         SEC_MODERATOR,      false, &ChatHandler::HandleModifyKnownTitlesCommand,   "", NULL },
        { "mount",          SEC_MODERATOR,      false, &ChatHandler::HandleModifyMountCommand,         "", NULL },
        { "honor",          SEC_MODERATOR,      false, &ChatHandler::HandleModifyHonorCommand,         "", NULL },
        { "rep",            SEC_MODERATOR,      false, &ChatHandler::HandleModifyRepCommand,           "", NULL },
        { "arena",          SEC_MODERATOR,      false, &ChatHandler::HandleModifyArenaCommand,         "", NULL },
        { "drunk",          SEC_MODERATOR,      false, &ChatHandler::HandleDrunkCommand,               "", NULL },
        { "standstate",     SEC_GAMEMASTER,     false, &ChatHandler::HandleStandStateCommand,          "", NULL },
        { "morph",          SEC_GAMEMASTER,     false, &ChatHandler::HandleMorphCommand,               "", NULL },
        { "gender",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleModifyGenderCommand,        "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand wpCommandTable[] =
    {
        { "show",           SEC_GAMEMASTER,     false, &ChatHandler::HandleWpShowCommand,              "", NULL },
        { "addwp",          SEC_GAMEMASTER,     false, &ChatHandler::HandleWpAddCommand,               "", NULL },
        { "load",           SEC_GAMEMASTER,     false, &ChatHandler::HandleWpLoadPathCommand,          "", NULL },
        { "modify",         SEC_GAMEMASTER,     false, &ChatHandler::HandleWpModifyCommand,            "", NULL },
        { "event",          SEC_GAMEMASTER,     false, &ChatHandler::HandleWpEventCommand,              "", NULL },
        { "unload",         SEC_GAMEMASTER,     false, &ChatHandler::HandleWpUnLoadPathCommand,     "", NULL },

        { NULL,             0,                  false, NULL,                                           "", NULL }
    };


    static ChatCommand banCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanAccountCommand,          "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanCharacterCommand,        "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanIPCommand,               "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand baninfoCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanInfoAccountCommand,      "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanInfoCharacterCommand,    "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanInfoIPCommand,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand banlistCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanListAccountCommand,      "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanListCharacterCommand,    "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleBanListIPCommand,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand unbanCommandTable[] =
    {
        { "account",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleUnBanAccountCommand,      "", NULL },
        { "character",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleUnBanCharacterCommand,    "", NULL },
        { "ip",             SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleUnBanIPCommand,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand debugCommandTable[] =
    {
        { "inarc",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleDebugInArcCommand,          "", NULL },
        { "spellfail",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleDebugSpellFailCommand,      "", NULL },
        { "setpoi",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSetPoiCommand,              "", NULL },
        { "qpartymsg",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSendQuestPartyMsgCommand,   "", NULL },
        { "qinvalidmsg",    SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSendQuestInvalidMsgCommand, "", NULL },
        { "equiperr",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleEquipErrorCommand,          "", NULL },
        { "sellerr",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSellErrorCommand,           "", NULL },
        { "buyerr",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleBuyErrorCommand,            "", NULL },
        { "sendopcode",     SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSendOpcodeCommand,          "", NULL },
        { "uws",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUpdateWorldStateCommand,    "", NULL },
        { "ps",             SEC_ADMINISTRATOR,  false, &ChatHandler::HandlePlaySound2Command,          "", NULL },
        { "scn",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSendChannelNotifyCommand,   "", NULL },
        { "scm",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSendChatMsgCommand,         "", NULL },
        { "getitemstate",   SEC_ADMINISTRATOR,  false, &ChatHandler::HandleGetItemState,               "", NULL },
        { "playsound",      SEC_MODERATOR,      false, &ChatHandler::HandlePlaySoundCommand,           "", NULL },
        { "update",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUpdate,                     "", NULL },
        { "setvalue",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSetValue,                   "", NULL },
        { "getvalue",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleGetValue,                   "", NULL },
        { "Mod32Value",     SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMod32Value,                 "", NULL },
        { "anim",           SEC_GAMEMASTER,     false, &ChatHandler::HandleAnimCommand,                "", NULL },
        { "lootrecipient",  SEC_GAMEMASTER,     false, &ChatHandler::HandleGetLootRecipient,           "", NULL },
        { "arena",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleDebugArenaCommand,          "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand eventCommandTable[] =
    {
        { "activelist",     SEC_GAMEMASTER,     true,  &ChatHandler::HandleEventActiveListCommand,     "", NULL },
        { "start",          SEC_GAMEMASTER,     true,  &ChatHandler::HandleEventStartCommand,          "", NULL },
        { "stop",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleEventStopCommand,           "", NULL },
        { "",               SEC_GAMEMASTER,     true, &ChatHandler::HandleEventInfoCommand,            "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand learnCommandTable[] =
    {
        { "all",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLearnAllCommand,            "", NULL },
        { "all_gm",         SEC_GAMEMASTER,     false, &ChatHandler::HandleLearnAllGMCommand,          "", NULL },
        { "all_crafts",     SEC_GAMEMASTER,     false, &ChatHandler::HandleLearnAllCraftsCommand,      "", NULL },
        { "all_default",    SEC_MODERATOR,      false, &ChatHandler::HandleLearnAllDefaultCommand,     "", NULL },
        { "all_lang",       SEC_MODERATOR,      false, &ChatHandler::HandleLearnAllLangCommand,        "", NULL },
        { "all_myclass",    SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLearnAllMyClassCommand,     "", NULL },
        { "all_myspells",   SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLearnAllMySpellsCommand,    "", NULL },
        { "all_mytalents",  SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLearnAllMyTalentsCommand,   "", NULL },
        { "all_recipes",    SEC_GAMEMASTER,     false, &ChatHandler::HandleLearnAllRecipesCommand,     "", NULL },
        { "",               SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLearnCommand,               "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand reloadCommandTable[] =
    {
        { "all",            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllCommand,           "", NULL },
        { "all_loot",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllLootCommand,       "", NULL },
        { "all_npc",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllNpcCommand,        "", NULL },
        { "all_quest",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllQuestCommand,      "", NULL },
        { "all_scripts",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllScriptsCommand,    "", NULL },
        { "all_spell",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllSpellCommand,      "", NULL },
        { "all_item",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllItemCommand,       "", NULL },
        { "all_locales",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadAllLocalesCommand,    "", NULL },

        { "config",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleReloadConfigCommand,        "", NULL },

        { "areatrigger_tavern",          SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadAreaTriggerTavernCommand,       "", NULL },
        { "areatrigger_teleport",        SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadAreaTriggerTeleportCommand,     "", NULL },
        { "access_requirement",          SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadAccessRequirementCommand,       "", NULL },
        { "areatrigger_involvedrelation",SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadQuestAreaTriggersCommand,       "", NULL },
        { "event_scripts",               SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadEventScriptsCommand,            "", NULL },
        { "command",                     SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCommandCommand,                 "", NULL },
        { "creature_involvedrelation",   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCreatureQuestInvRelationsCommand,"",NULL },
        { "creature_linked_respawn",     SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCreatureLinkedRespawnCommand,   "", NULL },
        { "creature_loot_template",      SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesCreatureCommand,   "", NULL },
        { "creature_questrelation",      SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCreatureQuestRelationsCommand,  "", NULL },
        //{ "db_script_string",            SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadDbScriptStringCommand,          "", NULL },
        { "disenchant_loot_template",    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesDisenchantCommand, "", NULL },
        { "fishing_loot_template",       SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesFishingCommand,    "", NULL },
        { "game_graveyard_zone",         SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadGameGraveyardZoneCommand,       "", NULL },
        { "game_tele",                   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadGameTeleCommand,                "", NULL },
        { "gameobject_involvedrelation", SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadGOQuestInvRelationsCommand,     "", NULL },
        { "gameobject_loot_template",    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesGameobjectCommand, "", NULL },
        { "gameobject_questrelation",    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadGOQuestRelationsCommand,        "", NULL },
        { "gameobject_scripts",          SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadGameObjectScriptsCommand,       "", NULL },
        { "item_enchantment_template",   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadItemEnchantementsCommand,       "", NULL },
        { "item_loot_template",          SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesItemCommand,       "", NULL },
        { "trinity_string",              SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadTrinityStringCommand,           "", NULL },
        { "npc_gossip",                  SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadNpcGossipCommand,               "", NULL },
        { "npc_option",                  SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadNpcOptionCommand,               "", NULL },
        { "npc_trainer",                 SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadNpcTrainerCommand,              "", NULL },
        { "npc_vendor",                  SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadNpcVendorCommand,               "", NULL },
        { "page_text",                   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadPageTextsCommand,               "", NULL },
        { "pickpocketing_loot_template", SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesPickpocketingCommand,"",NULL},
        { "prospecting_loot_template",   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesProspectingCommand,"", NULL },
        { "quest_mail_loot_template",    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesQuestMailCommand,  "", NULL },
        { "quest_end_scripts",           SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadQuestEndScriptsCommand,         "", NULL },
        { "quest_start_scripts",         SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadQuestStartScriptsCommand,       "", NULL },
        { "quest_template",              SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadQuestTemplateCommand,           "", NULL },
        { "reference_loot_template",     SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesReferenceCommand,  "", NULL },
        { "reserved_name",               SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadReservedNameCommand,            "", NULL },
        { "skill_discovery_template",    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSkillDiscoveryTemplateCommand,  "", NULL },
        { "skill_extra_item_template",   SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSkillExtraItemTemplateCommand,  "", NULL },
        { "skill_fishing_base_level",    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSkillFishingBaseLevelCommand,   "", NULL },
        { "skinning_loot_template",      SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLootTemplatesSkinningCommand,   "", NULL },
        { "spell_affect",                SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellAffectCommand,             "", NULL },
        { "spell_required",              SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellRequiredCommand,           "", NULL },
        { "spell_elixir",                SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellElixirCommand,             "", NULL },
        { "spell_learn_spell",           SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellLearnSpellCommand,         "", NULL },
        { "spell_linked_spell",          SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellLinkedSpellCommand,        "", NULL },
        { "spell_pet_auras",             SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellPetAurasCommand,           "", NULL },
        { "spell_proc_event",            SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellProcEventCommand,          "", NULL },
        { "spell_script_target",         SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellScriptTargetCommand,       "", NULL },
        { "spell_scripts",               SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellScriptsCommand,            "", NULL },
        { "spell_target_position",       SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellTargetPositionCommand,     "", NULL },
        { "spell_threats",               SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellThreatsCommand,            "", NULL },
        { "spell_disabled",              SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadSpellDisabledCommand,           "", NULL },
        { "locales_creature",            SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLocalesCreatureCommand,         "", NULL },
        { "locales_gameobject",          SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLocalesGameobjectCommand,       "", NULL },
        { "locales_item",                SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLocalesItemCommand,             "", NULL },
        { "locales_npc_text",            SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLocalesNpcTextCommand,          "", NULL },
        { "locales_page_text",           SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLocalesPageTextCommand,         "", NULL },
        { "locales_quest",               SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadLocalesQuestCommand,            "", NULL },
        { "auctions",                    SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadAuctionsCommand,                "", NULL },
        { "waypoint_scripts",            SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadWpScriptsCommand,               "", NULL },
        { "gm_tickets",                  SEC_ADMINISTRATOR, true,  &ChatHandler::HandleGMTicketReloadCommand,                "", NULL },

        { "",                            SEC_ADMINISTRATOR, true,  &ChatHandler::HandleReloadCommand,                        "", NULL },
        { NULL,                          0,                 false, NULL,                                                     "", NULL }
    };

    static ChatCommand honorCommandTable[] =
    {
        { "add",            SEC_GAMEMASTER,     false, &ChatHandler::HandleAddHonorCommand,            "", NULL },
        { "addkill",        SEC_GAMEMASTER,     false, &ChatHandler::HandleHonorAddKillCommand,        "", NULL },
        { "update",         SEC_GAMEMASTER,     false, &ChatHandler::HandleUpdateHonorFieldsCommand,   "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand guildCommandTable[] =
    {
        { "create",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildCreateCommand,         "", NULL },
        { "delete",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildDeleteCommand,         "", NULL },
        { "invite",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildInviteCommand,         "", NULL },
        { "uninvite",       SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildUninviteCommand,       "", NULL },
        { "rank",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleGuildRankCommand,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand petCommandTable[] =
    {
        { "create",         SEC_GAMEMASTER,     false, &ChatHandler::HandleCreatePetCommand,           "", NULL },
        { "learn",          SEC_GAMEMASTER,     false, &ChatHandler::HandlePetLearnCommand,            "", NULL },
        { "unlearn",        SEC_GAMEMASTER,     false, &ChatHandler::HandlePetUnlearnCommand,          "", NULL },
        { "tp",             SEC_GAMEMASTER,     false, &ChatHandler::HandlePetTpCommand,               "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };


    static ChatCommand groupCommandTable[] =
    {
        { "leader",         SEC_ADMINISTRATOR,     false,  &ChatHandler::HandleGroupLeaderCommand,         "", NULL },
        { "disband",        SEC_ADMINISTRATOR,     false,  &ChatHandler::HandleGroupDisbandCommand,        "", NULL },
        { "remove",         SEC_ADMINISTRATOR,     false,  &ChatHandler::HandleGroupRemoveCommand,         "", NULL },
        { NULL,             0,                     false, NULL,                                           "", NULL }
    };

    static ChatCommand lookupPlayerCommandTable[] =
    {
        { "ip",             SEC_GAMEMASTER,     true,  &ChatHandler::HandleLookupPlayerIpCommand,       "", NULL },
        { "account",        SEC_GAMEMASTER,     true,  &ChatHandler::HandleLookupPlayerAccountCommand,  "", NULL },
        { "email",          SEC_GAMEMASTER,     true,  &ChatHandler::HandleLookupPlayerEmailCommand,    "", NULL },
        { NULL,             0,                  false, NULL,                                            "", NULL }
    };

    static ChatCommand lookupCommandTable[] =
    {
        { "area",           SEC_MODERATOR,      true,  &ChatHandler::HandleLookupAreaCommand,          "", NULL },
        { "creature",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupCreatureCommand,      "", NULL },
        { "event",          SEC_GAMEMASTER,     true,  &ChatHandler::HandleLookupEventCommand,         "", NULL },
        { "faction",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupFactionCommand,       "", NULL },
        { "item",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupItemCommand,          "", NULL },
        { "itemset",        SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupItemSetCommand,       "", NULL },
        { "object",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupObjectCommand,        "", NULL },
        { "quest",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupQuestCommand,         "", NULL },
        { "player",         SEC_GAMEMASTER,     true,  NULL,                                           "", lookupPlayerCommandTable },
        { "skill",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupSkillCommand,         "", NULL },
        { "spell",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLookupSpellCommand,         "", NULL },
        { "tele",           SEC_MODERATOR,      true,  &ChatHandler::HandleLookupTeleCommand,          "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand resetCommandTable[] =
    {
        { "honor",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleResetHonorCommand,          "", NULL },
        { "level",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleResetLevelCommand,          "", NULL },
        { "spells",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleResetSpellsCommand,         "", NULL },
        { "stats",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleResetStatsCommand,          "", NULL },
        { "talents",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleResetTalentsCommand,        "", NULL },
        { "all",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleResetAllCommand,            "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand castCommandTable[] =
    {
        { "back",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCastBackCommand,            "", NULL },
        { "dist",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCastDistCommand,            "", NULL },
        { "self",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCastSelfCommand,            "", NULL },
        { "target",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCastTargetCommand,          "", NULL },
        { "",               SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCastCommand,                "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand pdumpCommandTable[] =
    {
        { "load",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLoadPDumpCommand,           "", NULL },
        { "write",          SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleWritePDumpCommand,          "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand listCommandTable[] =
    {
        { "creature",       SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleListCreatureCommand,        "", NULL },
        { "item",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleListItemCommand,            "", NULL },
        { "object",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleListObjectCommand,          "", NULL },
        { "auras",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleListAurasCommand,           "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand teleCommandTable[] =
    {
        { "add",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAddTeleCommand,             "", NULL },
        { "del",            SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleDelTeleCommand,             "", NULL },
        { "name",           SEC_MODERATOR,      true,  &ChatHandler::HandleNameTeleCommand,            "", NULL },
        { "group",          SEC_MODERATOR,      false, &ChatHandler::HandleGroupTeleCommand,           "", NULL },
        { "",               SEC_MODERATOR,      false, &ChatHandler::HandleTeleCommand,                "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand npcCommandTable[] =
    {
        { "say",            SEC_MODERATOR,      false, &ChatHandler::HandleNpcSayCommand,              "", NULL },
        { "textemote",      SEC_MODERATOR,      false, &ChatHandler::HandleNpcTextEmoteCommand,        "", NULL },
        { "add",            SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcAddCommand,              "", NULL },
        { "delete",         SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcDeleteCommand,           "", NULL },
        { "spawndist",      SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSpawnDistCommand,        "", NULL },
        { "spawntime",      SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSpawnTimeCommand,        "", NULL },
        { "factionid",      SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcFactionIdCommand,        "", NULL },
        { "addmove",        SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcAddMoveCommand,          "", NULL },
        { "setmovetype",    SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetMoveTypeCommand,      "", NULL },
        { "move",           SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcMoveCommand,             "", NULL },
        { "changelevel",    SEC_GAMEMASTER,     false, &ChatHandler::HandleChangeLevelCommand,         "", NULL },
        { "setmodel",       SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcSetModelCommand,         "", NULL },
        { "additem",        SEC_GAMEMASTER,     false, &ChatHandler::HandleAddVendorItemCommand,       "", NULL },
        { "delitem",        SEC_GAMEMASTER,     false, &ChatHandler::HandleDelVendorItemCommand,       "", NULL },
        { "flag",           SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcFlagCommand,             "", NULL },
        { "changeentry",    SEC_ADMINISTRATOR,  false, &ChatHandler::HandleNpcChangeEntryCommand,      "", NULL },
        { "info",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleNpcInfoCommand,             "", NULL },
        { "playemote",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleNpcPlayEmoteCommand,        "", NULL },
        { "follow",         SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcFollowCommand,           "", NULL },
        { "unfollow",       SEC_GAMEMASTER,     false, &ChatHandler::HandleNpcUnFollowCommand,         "", NULL },
        { "whisper",        SEC_MODERATOR,      false, &ChatHandler::HandleNpcWhisperCommand,          "", NULL },
        { "yell",           SEC_MODERATOR,      false, &ChatHandler::HandleNpcYellCommand,             "", NULL },
        { "addtemp",        SEC_GAMEMASTER,     false, &ChatHandler::HandleTempAddSpwCommand,          "", NULL },
        { "addformation",   SEC_MODERATOR,      false, &ChatHandler::HandleNpcAddFormationCommand,     "", NULL },
        { "setlink",        SEC_MODERATOR,      false, &ChatHandler::HandleNpcSetLinkCommand,          "", NULL },

        //{ TODO: fix or remove this commands
        { "name",           SEC_GAMEMASTER,     false, &ChatHandler::HandleNameCommand,                "", NULL },
        { "subname",        SEC_GAMEMASTER,     false, &ChatHandler::HandleSubNameCommand,             "", NULL },
        { "addweapon",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAddWeaponCommand,           "", NULL },
        //}

        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand goCommandTable[] =
    {
        { "grid",           SEC_MODERATOR,      false, &ChatHandler::HandleGoGridCommand,              "", NULL },
        { "creature",       SEC_GAMEMASTER,     false, &ChatHandler::HandleGoCreatureCommand,          "", NULL },
        { "object",         SEC_GAMEMASTER,     false, &ChatHandler::HandleGoObjectCommand,            "", NULL },
        { "ticket",         SEC_MODERATOR,      false, &ChatHandler::HandleGoTicketCommand,            "", NULL },
        { "trigger",        SEC_GAMEMASTER,     false, &ChatHandler::HandleGoTriggerCommand,           "", NULL },
        { "graveyard",      SEC_GAMEMASTER,     false, &ChatHandler::HandleGoGraveyardCommand,         "", NULL },
        { "zonexy",         SEC_MODERATOR,      false, &ChatHandler::HandleGoZoneXYCommand,            "", NULL },
        { "xy",             SEC_MODERATOR,      false, &ChatHandler::HandleGoXYCommand,                "", NULL },
        { "xyz",            SEC_MODERATOR,      false, &ChatHandler::HandleGoXYZCommand,               "", NULL },
        { "",               SEC_MODERATOR,      false, &ChatHandler::HandleGoXYZCommand,               "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand gobjectCommandTable[] =
    {
        { "add",            SEC_GAMEMASTER,     false, &ChatHandler::HandleGameObjectCommand,          "", NULL },
        { "delete",         SEC_GAMEMASTER,     false, &ChatHandler::HandleDelObjectCommand,           "", NULL },
        { "target",         SEC_GAMEMASTER,     false, &ChatHandler::HandleTargetObjectCommand,        "", NULL },
        { "turn",           SEC_GAMEMASTER,     false, &ChatHandler::HandleTurnObjectCommand,          "", NULL },
        { "move",           SEC_GAMEMASTER,     false, &ChatHandler::HandleMoveObjectCommand,          "", NULL },
        { "near",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleNearObjectCommand,          "", NULL },
        { "activate",       SEC_GAMEMASTER,     false, &ChatHandler::HandleActivateObjectCommand,      "", NULL },
        { "addtemp",        SEC_GAMEMASTER,     false, &ChatHandler::HandleTempGameObjectCommand,      "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand questCommandTable[] =
    {
        { "add",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAddQuest,                   "", NULL },
        { "complete",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCompleteQuest,              "", NULL },
        { "remove",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleRemoveQuest,                "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand gmCommandTable[] =
    {
        { "chat",           SEC_MODERATOR,      false, &ChatHandler::HandleGMChatCommand,              "", NULL },
        { "ingame",         SEC_PLAYER,         true,  &ChatHandler::HandleGMListIngameCommand,        "", NULL },
        { "list",           SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleGMListFullCommand,          "", NULL },
        { "visible",        SEC_MODERATOR,      false, &ChatHandler::HandleVisibleCommand,             "", NULL },
        { "fly",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleFlyModeCommand,             "", NULL },
        { "",               SEC_MODERATOR,      false, &ChatHandler::HandleGMmodeCommand,              "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand instanceCommandTable[] =
    {
        { "listbinds",      SEC_MODERATOR,      false, &ChatHandler::HandleInstanceListBindsCommand,   "", NULL },
        { "unbind",         SEC_MODERATOR,      false, &ChatHandler::HandleInstanceUnbindCommand,      "", NULL },
        { "stats",          SEC_MODERATOR,      true,  &ChatHandler::HandleInstanceStatsCommand,       "", NULL },
        { "savedata",       SEC_MODERATOR,      false, &ChatHandler::HandleInstanceSaveDataCommand,    "", NULL },
        { NULL,             0,                  false, NULL,                                           "", NULL }
    };

    static ChatCommand ticketCommandTable[] =
    {
        { "list",           SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketListCommand,             "", NULL },
        { "onlinelist",     SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketListOnlineCommand,       "", NULL },
        { "viewname",       SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketGetByNameCommand,        "", NULL },
        { "viewid",         SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketGetByIdCommand,          "", NULL },
        { "close",          SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketCloseByIdCommand,        "", NULL },
        { "closedlist",     SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketListClosedCommand,       "", NULL },
        { "delete",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleGMTicketDeleteByIdCommand,       "", NULL },
        { "assign",         SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketAssignToCommand,         "", NULL },
        { "unassign",       SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketUnAssignCommand,         "", NULL },
        { "comment",        SEC_MODERATOR,      false, &ChatHandler::HandleGMTicketCommentCommand,          "", NULL },
        { NULL,             0,                  false, NULL,                                                "", NULL }
    };

    static ChatCommand commandTable[] =
    {
        { "account",        SEC_PLAYER,         true,  NULL,                                           "", accountCommandTable },
        { "gm",             SEC_MODERATOR,      true,  NULL,                                           "", gmCommandTable },
        { "ticket",         SEC_MODERATOR,      false,  NULL,                                          "", ticketCommandTable },
        { "npc",            SEC_MODERATOR,      false, NULL,                                           "", npcCommandTable },
        { "go",             SEC_MODERATOR,      false, NULL,                                           "", goCommandTable },
        { "learn",          SEC_MODERATOR,      false, NULL,                                           "", learnCommandTable },
        { "modify",         SEC_MODERATOR,      false, NULL,                                           "", modifyCommandTable },
        { "debug",          SEC_MODERATOR,      false, NULL,                                           "", debugCommandTable },
        { "tele",           SEC_MODERATOR,      true,  NULL,                                           "", teleCommandTable },
        { "event",          SEC_GAMEMASTER,     false, NULL,                                           "", eventCommandTable },
        { "gobject",        SEC_GAMEMASTER,     false, NULL,                                           "", gobjectCommandTable },
        { "honor",          SEC_GAMEMASTER,     false, NULL,                                           "", honorCommandTable },

        //wp commands
        { "path",           SEC_GAMEMASTER,     false, NULL,                                           "", wpCommandTable },
        { "loadpath",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReloadAllPaths,             "", NULL },

        { "quest",          SEC_ADMINISTRATOR,  false, NULL,                                           "", questCommandTable },
        { "reload",         SEC_ADMINISTRATOR,  true,  NULL,                                           "", reloadCommandTable },
        { "list",           SEC_ADMINISTRATOR,  true,  NULL,                                           "", listCommandTable },
        { "lookup",         SEC_ADMINISTRATOR,  true,  NULL,                                           "", lookupCommandTable },
        { "pdump",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", pdumpCommandTable },
        { "guild",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", guildCommandTable },
        { "cast",           SEC_ADMINISTRATOR,  false, NULL,                                           "", castCommandTable },
        { "reset",          SEC_ADMINISTRATOR,  false, NULL,                                           "", resetCommandTable },
        { "instance",       SEC_ADMINISTRATOR,  true,  NULL,                                           "", instanceCommandTable },
        { "server",         SEC_ADMINISTRATOR,  true,  NULL,                                           "", serverCommandTable },
        { "pet",            SEC_GAMEMASTER,     false, NULL,                                           "", petCommandTable },

        { "aura",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAuraCommand,                "", NULL },
        { "unaura",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUnAuraCommand,              "", NULL },
        { "nameannounce",   SEC_MODERATOR,      false, &ChatHandler::HandleNameAnnounceCommand,        "", NULL },
        { "gmnameannounce", SEC_MODERATOR,      false, &ChatHandler::HandleGMNameAnnounceCommand,      "", NULL },
        { "announce",       SEC_MODERATOR,      true,  &ChatHandler::HandleAnnounceCommand,            "", NULL },
        { "gmannounce",     SEC_MODERATOR,      true,  &ChatHandler::HandleGMAnnounceCommand,          "", NULL },
        { "notify",         SEC_MODERATOR,      true,  &ChatHandler::HandleNotifyCommand,              "", NULL },
        { "gmnotify",       SEC_MODERATOR,      true,  &ChatHandler::HandleGMNotifyCommand,            "", NULL },
        { "goname",         SEC_MODERATOR,      false, &ChatHandler::HandleGonameCommand,              "", NULL },
        { "namego",         SEC_MODERATOR,      false, &ChatHandler::HandleNamegoCommand,              "", NULL },
        { "groupgo",        SEC_MODERATOR,      false, &ChatHandler::HandleGroupgoCommand,             "", NULL },
        { "commands",       SEC_PLAYER,         true,  &ChatHandler::HandleCommandsCommand,            "", NULL },
        { "demorph",        SEC_GAMEMASTER,     false, &ChatHandler::HandleDeMorphCommand,             "", NULL },
        { "die",            SEC_ADMINISTRATOR,  false, &ChatHandler::HandleDieCommand,                 "", NULL },
        { "revive",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleReviveCommand,              "", NULL },
        { "dismount",       SEC_PLAYER,         false, &ChatHandler::HandleDismountCommand,            "", NULL },
        { "gps",            SEC_MODERATOR,      false, &ChatHandler::HandleGPSCommand,                 "", NULL },
        { "guid",           SEC_GAMEMASTER,     false, &ChatHandler::HandleGUIDCommand,                "", NULL },
        { "help",           SEC_PLAYER,         true,  &ChatHandler::HandleHelpCommand,                "", NULL },
        { "itemmove",       SEC_GAMEMASTER,     false, &ChatHandler::HandleItemMoveCommand,            "", NULL },
        { "cooldown",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleCooldownCommand,            "", NULL },
        { "unlearn",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUnLearnCommand,             "", NULL },
        { "distance",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleGetDistanceCommand,         "", NULL },
        { "recall",         SEC_MODERATOR,      false, &ChatHandler::HandleRecallCommand,              "", NULL },
        { "save",           SEC_PLAYER,         false, &ChatHandler::HandleSaveCommand,                "", NULL },
        { "saveall",        SEC_MODERATOR,      true,  &ChatHandler::HandleSaveAllCommand,             "", NULL },
        { "kick",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleKickPlayerCommand,          "", NULL },
        { "ban",            SEC_ADMINISTRATOR,  true,  NULL,                                           "", banCommandTable },
        { "unban",          SEC_ADMINISTRATOR,  true,  NULL,                                           "", unbanCommandTable },
        { "baninfo",        SEC_ADMINISTRATOR,  false, NULL,                                           "", baninfoCommandTable },
        { "banlist",        SEC_ADMINISTRATOR,  true,  NULL,                                           "", banlistCommandTable },
        { "plimit",         SEC_ADMINISTRATOR,  true,  &ChatHandler::HandlePLimitCommand,              "", NULL },
        { "start",          SEC_PLAYER,         false, &ChatHandler::HandleStartCommand,               "", NULL },
        { "taxicheat",      SEC_MODERATOR,      false, &ChatHandler::HandleTaxiCheatCommand,           "", NULL },
        { "allowmove",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAllowMovementCommand,       "", NULL },
        { "linkgrave",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLinkGraveCommand,           "", NULL },
        { "neargrave",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleNearGraveCommand,           "", NULL },
        { "explorecheat",   SEC_ADMINISTRATOR,  false, &ChatHandler::HandleExploreCheatCommand,        "", NULL },
        { "hover",          SEC_ADMINISTRATOR,  false, &ChatHandler::HandleHoverCommand,               "", NULL },
        { "waterwalk",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleWaterwalkCommand,           "", NULL },
        { "levelup",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleLevelUpCommand,             "", NULL },
        { "showarea",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleShowAreaCommand,            "", NULL },
        { "hidearea",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleHideAreaCommand,            "", NULL },
        { "additem",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAddItemCommand,             "", NULL },
        { "additemset",     SEC_ADMINISTRATOR,  false, &ChatHandler::HandleAddItemSetCommand,          "", NULL },
        { "bank",           SEC_ADMINISTRATOR,  false, &ChatHandler::HandleBankCommand,                "", NULL },
        { "wchange",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleChangeWeather,              "", NULL },
        { "maxskill",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMaxSkillCommand,            "", NULL },
        { "setskill",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleSetSkillCommand,            "", NULL },
        { "whispers",       SEC_MODERATOR,      false, &ChatHandler::HandleWhispersCommand,            "", NULL },
        { "pinfo",          SEC_GAMEMASTER,     true,  &ChatHandler::HandlePInfoCommand,               "", NULL },
        { "password",       SEC_PLAYER,         false, &ChatHandler::HandlePasswordCommand,            "", NULL },
        { "lockaccount",    SEC_PLAYER,         false, &ChatHandler::HandleLockAccountCommand,         "", NULL },
        { "respawn",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandleRespawnCommand,             "", NULL },
        { "senditems",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendItemsCommand,           "", NULL },
        { "sendmail",       SEC_MODERATOR,      true,  &ChatHandler::HandleSendMailCommand,            "", NULL },
        { "sendmoney",      SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMoneyCommand,           "", NULL },
        { "rename",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleRenameCommand,              "", NULL },
        { "loadscripts",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleLoadScriptsCommand,         "", NULL },
        { "mute",           SEC_GAMEMASTER,     true,  &ChatHandler::HandleMuteCommand,                "", NULL },
        { "unmute",         SEC_GAMEMASTER,     true,  &ChatHandler::HandleUnmuteCommand,              "", NULL },
        { "movegens",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleMovegensCommand,            "", NULL },
        { "cometome",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleComeToMeCommand,            "", NULL },
        { "damage",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleDamageCommand,              "", NULL },
        { "combatstop",     SEC_GAMEMASTER,     false, &ChatHandler::HandleCombatStopCommand,          "", NULL },
        { "ahbotoptions",   SEC_ADMINISTRATOR,  true,    &ChatHandler::HandleAHBotOptionsCommand,        "", NULL },
        { "flusharenapoints",    SEC_ADMINISTRATOR, false, &ChatHandler::HandleFlushArenaPointsCommand,         "",   NULL },
        { "chardelete",     SEC_CONSOLE,        true,  &ChatHandler::HandleCharacterDeleteCommand,     "", NULL },
        { "sendmessage",    SEC_ADMINISTRATOR,  true,  &ChatHandler::HandleSendMessageCommand,         "", NULL },
        { "playall",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandlePlayAllCommand,             "", NULL },
        { "repairitems",    SEC_GAMEMASTER,     false, &ChatHandler::HandleRepairitemsCommand,         "", NULL },
        { "freeze",         SEC_ADMINISTRATOR,  false, &ChatHandler::HandleFreezeCommand,              "", NULL },
        { "unfreeze",       SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUnFreezeCommand,            "", NULL },
        { "listfreeze",     SEC_ADMINISTRATOR,  false, &ChatHandler::HandleListFreezeCommand,          "", NULL },
        { "possess",        SEC_ADMINISTRATOR,  false, &ChatHandler::HandlePossessCommand,             "", NULL },
        { "unpossess",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUnPossessCommand,           "", NULL },
        { "bindsight",      SEC_ADMINISTRATOR,  false, &ChatHandler::HandleBindSightCommand,           "", NULL },
        { "unbindsight",    SEC_ADMINISTRATOR,  false, &ChatHandler::HandleUnbindSightCommand,         "", NULL },

        { NULL,             0,                  false, NULL,                                           "", NULL }
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

const char *ChatHandler::GetTrinityString(int32 entry) const
{
    return m_session->GetTrinityString(entry);
}

bool ChatHandler::isAvailable(ChatCommand const& cmd) const
{
    // check security level only for simple  command (without child commands)
    return m_session->GetSecurity() >= cmd.SecurityLevel;
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
    // Chat output
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

void ChatHandler::SendGlobalGMSysMessage(const char *str)
{
    // Chat output
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(str);
    char* pos = buf;

    while(char* line = LineFromMessage(pos))
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

        // must be available and have handler
        if(!table[i].Handler || !isAvailable(table[i]))
            continue;

        SetSentErrorMessage(false);
        // table[i].Name == "" is special case: send original command to handler
        if((this->*(table[i].Handler))(strlen(table[i].Name)!=0 ? text : oldtext))
        {
            if(table[i].SecurityLevel > SEC_PLAYER)
            {
                // chat case
                if(m_session)
                {
                    Player* p = m_session->GetPlayer();
                    uint64 sel_guid = p->GetSelection();
                    sLog.outCommand(m_session->GetAccountId(),"Command: %s [Player: %s (Account: %u) X: %f Y: %f Z: %f Map: %u Selected: %s (GUID: %u)]",
                        fullcmd.c_str(),p->GetName(),m_session->GetAccountId(),p->GetPositionX(),p->GetPositionY(),p->GetPositionZ(),p->GetMapId(),
                        GetLogNameForGuid(sel_guid),GUID_LOPART(sel_guid));
                }
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

    std::string fullcmd = text;

    /// chat case (.command or !command format)
    if(m_session)
    {
        if(text[0] != '!' && text[0] != '.')
            return 0;
    }

    /// ignore single . and ! in line
    if(strlen(text) < 2)
        return 0;
    // original `text` can't be used. It content destroyed in command code processing.

    /// ignore messages staring from many dots.
    if(text[0] == '.' && text[1] == '.' || text[0] == '!' && text[1] == '!')
        return 0;

    /// skip first . or ! (in console allowed use command with . and ! and without its)
    if(text[0] == '!' || text[0] == '.')
        ++text;

    if(!ExecuteCommandInTable(getCommandTable(), text, fullcmd))
    {
        if(m_session && m_session->GetSecurity() == SEC_PLAYER)
            return 0;
        SendSysMessage(LANG_NO_CMD);
    }
    return 1;
}

bool ChatHandler::ShowHelpForSubCommands(ChatCommand *table, char const* cmd, char const* subcmd)
{
    std::string list;
    for(uint32 i = 0; table[i].Name != NULL; ++i)
    {
        // must be available (ignore handler existence for show command with possibe avalable subcomands
        if(!isAvailable(table[i]))
            continue;

        /// for empty subcmd show all available
        if( *subcmd && !hasStringAbbr(table[i].Name, subcmd))
            continue;

        if(m_session)
            list += "\n    ";
        else
            list += "\n\r    ";

        list += table[i].Name;

        if(table[i].ChildCommands)
            list += " ...";
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
            // must be available (ignore handler existence for show command with possibe avalable subcomands
            if(!isAvailable(table[i]))
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
            // must be available (ignore handler existence for show command with possibe avalable subcomands
            if(!isAvailable(table[i]))
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
    if(!m_session)
        return NULL;

    uint64 guid  = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return m_session->GetPlayer();

    return objmgr.GetPlayer(guid);
}

Unit* ChatHandler::getSelectedUnit()
{
    if(!m_session)
        return NULL;

    uint64 guid = m_session->GetPlayer()->GetSelection();

    if (guid == 0)
        return m_session->GetPlayer();

    return ObjectAccessor::GetUnit(*m_session->GetPlayer(),guid);
}

Creature* ChatHandler::getSelectedCreature()
{
    if(!m_session)
        return NULL;

    return ObjectAccessor::GetCreatureOrPet(*m_session->GetPlayer(),m_session->GetPlayer()->GetSelection());
}

char* ChatHandler::extractKeyFromLink(char* text, char const* linkType, char** something1)
{
    // skip empty
    if(!text)
        return NULL;

    // skip spaces
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

    // skip spaces
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
    if(!m_session)
        return NULL;

    Player* pl = m_session->GetPlayer();

    GameObject* obj = ObjectAccessor::GetGameObject(*pl, MAKE_NEW_GUID(lowguid, entry, HIGHGUID_GAMEOBJECT));

    if(!obj && objmgr.GetGOData(lowguid))                   // guid is DB guid of object
    {
        // search near player then
        CellPair p(Trinity::ComputeCellPair(pl->GetPositionX(), pl->GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;

        Trinity::GameObjectWithDbGUIDCheck go_check(*pl,lowguid);
        Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck> checker(obj,go_check);

        TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck>, GridTypeMapContainer > object_checker(checker);
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
    // number or [name] Shift-click form |color|Htalent:talent_id,rank|h[name]|h|r
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

const char *ChatHandler::GetName() const
{
    return m_session->GetPlayer()->GetName();
}

bool ChatHandler::needReportToTarget(Player* chr) const
{
    Player* pl = m_session->GetPlayer();
    return pl != chr && pl->IsVisibleGloballyFor(chr);
}

const char *CliHandler::GetTrinityString(int32 entry) const
{
    return objmgr.GetTrinityStringForDBCLocale(entry);
}

bool CliHandler::isAvailable(ChatCommand const& cmd) const
{
    // skip non-console commands in console case
    return cmd.AllowConsole;
}

void CliHandler::SendSysMessage(const char *str)
{
    m_print(str);
    m_print("\r\n");
}

const char *CliHandler::GetName() const
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

    if(cname)
    {
        std::string name = cname;
        if(!name.empty())
        {
            if(!normalizePlayerName(name))
            {
                PSendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }

            plr = objmgr.GetPlayer(name.c_str());
            if(offline)
                guid = objmgr.GetPlayerGUIDByName(name.c_str());
        }
    }

    if(plr)
    {
        group = plr->GetGroup();
        if(!guid || !offline)
            guid = plr->GetGUID();
    }
    else
    {
        if(getSelectedPlayer())
            plr = getSelectedPlayer();
        else
            plr = m_session->GetPlayer();

        if(!guid || !offline)
            guid  = plr->GetGUID();
        group = plr->GetGroup();
    }

    return true;
}

