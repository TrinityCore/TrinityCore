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
Name: reload_commandscript
%Complete: 100
Comment: All reload related commands
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "AreaTriggerDataStore.h"
#include "AuctionHouseMgr.h"
#include "BattlegroundMgr.h"
#include "CharacterTemplateDataStore.h"
#include "Chat.h"
#include "ConversationDataStore.h"
#include "CreatureTextMgr.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "ItemEnchantmentMgr.h"
#include "Language.h"
#include "LFGMgr.h"
#include "Log.h"
#include "LootMgr.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SkillDiscovery.h"
#include "SkillExtraItems.h"
#include "SmartAI.h"
#include "SpellMgr.h"
#include "SupportMgr.h"
#include "WardenCheckMgr.h"
#include "WaypointManager.h"
#include "World.h"

class reload_commandscript : public CommandScript
{
public:
    reload_commandscript() : CommandScript("reload_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> reloadAllCommandTable =
        {
            { "achievement",                   rbac::RBAC_PERM_COMMAND_RELOAD_ALL_ACHIEVEMENT,                  true,  &HandleReloadAllAchievementCommand,              "" },
            { "area",                          rbac::RBAC_PERM_COMMAND_RELOAD_ALL_AREA,                         true,  &HandleReloadAllAreaCommand,                     "" },
            { "gossips",                       rbac::RBAC_PERM_COMMAND_RELOAD_ALL_GOSSIP,                       true,  &HandleReloadAllGossipsCommand,                  "" },
            { "item",                          rbac::RBAC_PERM_COMMAND_RELOAD_ALL_ITEM,                         true,  &HandleReloadAllItemCommand,                     "" },
            { "locales",                       rbac::RBAC_PERM_COMMAND_RELOAD_ALL_LOCALES,                      true,  &HandleReloadAllLocalesCommand,                  "" },
            { "loot",                          rbac::RBAC_PERM_COMMAND_RELOAD_ALL_LOOT,                         true,  &HandleReloadAllLootCommand,                     "" },
            { "npc",                           rbac::RBAC_PERM_COMMAND_RELOAD_ALL_NPC,                          true,  &HandleReloadAllNpcCommand,                      "" },
            { "quest",                         rbac::RBAC_PERM_COMMAND_RELOAD_ALL_QUEST,                        true,  &HandleReloadAllQuestCommand,                    "" },
            { "scripts",                       rbac::RBAC_PERM_COMMAND_RELOAD_ALL_SCRIPTS,                      true,  &HandleReloadAllScriptsCommand,                  "" },
            { "spell",                         rbac::RBAC_PERM_COMMAND_RELOAD_ALL_SPELL,                        true,  &HandleReloadAllSpellCommand,                    "" },
            { "",                              rbac::RBAC_PERM_COMMAND_RELOAD_ALL,                              true,  &HandleReloadAllCommand,                         "" },
        };
        static std::vector<ChatCommand> reloadCommandTable =
        {
            { "auctions",                      rbac::RBAC_PERM_COMMAND_RELOAD_AUCTIONS,                         true,  &HandleReloadAuctionsCommand,                   "" },
            { "access_requirement",            rbac::RBAC_PERM_COMMAND_RELOAD_ACCESS_REQUIREMENT,               true,  &HandleReloadAccessRequirementCommand,          "" },
            { "achievement_reward",            rbac::RBAC_PERM_COMMAND_RELOAD_ACHIEVEMENT_REWARD,               true,  &HandleReloadAchievementRewardCommand,          "" },
            { "all",                           rbac::RBAC_PERM_COMMAND_RELOAD_ALL,                              true,  NULL,                                           "", reloadAllCommandTable },
            { "areatrigger_involvedrelation",  rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_INVOLVEDRELATION,     true,  &HandleReloadQuestAreaTriggersCommand,          "" },
            { "areatrigger_tavern",            rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TAVERN,               true,  &HandleReloadAreaTriggerTavernCommand,          "" },
            { "areatrigger_teleport",          rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TELEPORT,             true,  &HandleReloadAreaTriggerTeleportCommand,        "" },
            { "areatrigger_template",          rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TEMPLATE,             true,  &HandleReloadAreaTriggerTemplateCommand,        "" },
            { "autobroadcast",                 rbac::RBAC_PERM_COMMAND_RELOAD_AUTOBROADCAST,                    true,  &HandleReloadAutobroadcastCommand,              "" },
            { "battleground_template",         rbac::RBAC_PERM_COMMAND_RELOAD_BATTLEGROUND_TEMPLATE,            true,  &HandleReloadBattlegroundTemplate,              "" },
            { "character_template",            rbac::RBAC_PERM_COMMAND_RELOAD_CHARACTER_TEMPLATE,               true,  &HandleReloadCharacterTemplate,                 "" },
            { "command",                       rbac::RBAC_PERM_COMMAND_RELOAD_COMMAND,                          true,  &HandleReloadCommandCommand,                    "" },
            { "conditions",                    rbac::RBAC_PERM_COMMAND_RELOAD_CONDITIONS,                       true,  &HandleReloadConditions,                        "" },
            { "config",                        rbac::RBAC_PERM_COMMAND_RELOAD_CONFIG,                           true,  &HandleReloadConfigCommand,                     "" },
            { "conversation_template",         rbac::RBAC_PERM_COMMAND_RELOAD_CONVERSATION_TEMPLATE,            true,  &HandleReloadConversationTemplateCommand,       "" },
            { "creature_text",                 rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_TEXT,                    true,  &HandleReloadCreatureText,                      "" },
            { "creature_questender",           rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTENDER,              true,  &HandleReloadCreatureQuestEnderCommand,         "" },
            { "creature_linked_respawn",       rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_LINKED_RESPAWN,          true,  &HandleReloadLinkedRespawnCommand,              "" },
            { "creature_loot_template",        rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_LOOT_TEMPLATE,           true,  &HandleReloadLootTemplatesCreatureCommand,      "" },
            { "creature_onkill_reputation",    rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_ONKILL_REPUTATION,       true,  &HandleReloadOnKillReputationCommand,           "" },
            { "creature_queststarter",         rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTSTARTER,            true,  &HandleReloadCreatureQuestStarterCommand,       "" },
            { "creature_summon_groups",        rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_SUMMON_GROUPS,           true,  &HandleReloadCreatureSummonGroupsCommand,       "" },
            { "creature_template",             rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_TEMPLATE,                true,  &HandleReloadCreatureTemplateCommand,           "" },
            { "criteria_data",                 rbac::RBAC_PERM_COMMAND_RELOAD_CRITERIA_DATA,                    true,  &HandleReloadCriteriaDataCommand,               "" },
            { "disables",                      rbac::RBAC_PERM_COMMAND_RELOAD_DISABLES,                         true,  &HandleReloadDisablesCommand,                   "" },
            { "disenchant_loot_template",      rbac::RBAC_PERM_COMMAND_RELOAD_DISENCHANT_LOOT_TEMPLATE,         true,  &HandleReloadLootTemplatesDisenchantCommand,    "" },
            { "event_scripts",                 rbac::RBAC_PERM_COMMAND_RELOAD_EVENT_SCRIPTS,                    true,  &HandleReloadEventScriptsCommand,               "" },
            { "fishing_loot_template",         rbac::RBAC_PERM_COMMAND_RELOAD_FISHING_LOOT_TEMPLATE,            true,  &HandleReloadLootTemplatesFishingCommand,       "" },
            { "graveyard_zone",                rbac::RBAC_PERM_COMMAND_RELOAD_GRAVEYARD_ZONE,                   true,  &HandleReloadGameGraveyardZoneCommand,          "" },
            { "game_tele",                     rbac::RBAC_PERM_COMMAND_RELOAD_GAME_TELE,                        true,  &HandleReloadGameTeleCommand,                   "" },
            { "gameobject_questender",         rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUESTENDER,            true,  &HandleReloadGOQuestEnderCommand,               "" },
            { "gameobject_loot_template",      rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUEST_LOOT_TEMPLATE,   true,  &HandleReloadLootTemplatesGameobjectCommand,    "" },
            { "gameobject_queststarter",       rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUESTSTARTER,          true,  &HandleReloadGOQuestStarterCommand,             "" },
            { "gossip_menu",                   rbac::RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU,                      true,  &HandleReloadGossipMenuCommand,                 "" },
            { "gossip_menu_option",            rbac::RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU_OPTION,               true,  &HandleReloadGossipMenuOptionCommand,           "" },
            { "item_enchantment_template",     rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_ENCHANTMENT_TEMPLATE,        true,  &HandleReloadItemEnchantementsCommand,          "" },
            { "item_loot_template",            rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_LOOT_TEMPLATE,               true,  &HandleReloadLootTemplatesItemCommand,          "" },
            { "lfg_dungeon_rewards",           rbac::RBAC_PERM_COMMAND_RELOAD_LFG_DUNGEON_REWARDS,              true,  &HandleReloadLfgRewardsCommand,                 "" },
            { "locales_achievement_reward",    rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_ACHIEVEMENT_REWARD,       true,  &HandleReloadLocalesAchievementRewardCommand,   "" },
            { "locales_creature",              rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_CRETURE,                  true,  &HandleReloadLocalesCreatureCommand,            "" },
            { "locales_creature_text",         rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_CRETURE_TEXT,             true,  &HandleReloadLocalesCreatureTextCommand,        "" },
            { "locales_gameobject",            rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_GAMEOBJECT,               true,  &HandleReloadLocalesGameobjectCommand,          "" },
            { "locales_gossip_menu_option",    rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_GOSSIP_MENU_OPTION,       true,  &HandleReloadLocalesGossipMenuOptionCommand,    "" },
            { "locales_page_text",             rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_PAGE_TEXT,                true,  &HandleReloadLocalesPageTextCommand,            "" },
            { "locales_points_of_interest",    rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_POINTS_OF_INTEREST,       true,  &HandleReloadLocalesPointsOfInterestCommand,    "" },
            { "mail_level_reward",             rbac::RBAC_PERM_COMMAND_RELOAD_MAIL_LEVEL_REWARD,                true,  &HandleReloadMailLevelRewardCommand,            "" },
            { "mail_loot_template",            rbac::RBAC_PERM_COMMAND_RELOAD_MAIL_LOOT_TEMPLATE,               true,  &HandleReloadLootTemplatesMailCommand,          "" },
            { "milling_loot_template",         rbac::RBAC_PERM_COMMAND_RELOAD_MILLING_LOOT_TEMPLATE,            true,  &HandleReloadLootTemplatesMillingCommand,       "" },
            { "npc_spellclick_spells",         rbac::RBAC_PERM_COMMAND_RELOAD_NPC_SPELLCLICK_SPELLS,            true,  &HandleReloadSpellClickSpellsCommand,           "" },
            { "npc_vendor",                    rbac::RBAC_PERM_COMMAND_RELOAD_NPC_VENDOR,                       true,  &HandleReloadNpcVendorCommand,                  "" },
            { "page_text",                     rbac::RBAC_PERM_COMMAND_RELOAD_PAGE_TEXT,                        true,  &HandleReloadPageTextsCommand,                  "" },
            { "pickpocketing_loot_template",   rbac::RBAC_PERM_COMMAND_RELOAD_PICKPOCKETING_LOOT_TEMPLATE,      true,  &HandleReloadLootTemplatesPickpocketingCommand, "" },
            { "points_of_interest",            rbac::RBAC_PERM_COMMAND_RELOAD_POINTS_OF_INTEREST,               true,  &HandleReloadPointsOfInterestCommand,           "" },
            { "prospecting_loot_template",     rbac::RBAC_PERM_COMMAND_RELOAD_PROSPECTING_LOOT_TEMPLATE,        true,  &HandleReloadLootTemplatesProspectingCommand,   "" },
            { "quest_greeting",                rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_GREETING,                   true,  &HandleReloadQuestGreetingCommand,              "" },
            { "quest_locale",                  rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_LOCALE,                     true,  &HandleReloadQuestLocaleCommand,                "" },
            { "quest_poi",                     rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_POI,                        true,  &HandleReloadQuestPOICommand,                   "" },
            { "quest_template",                rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_TEMPLATE,                   true,  &HandleReloadQuestTemplateCommand,              "" },
            { "rbac",                          rbac::RBAC_PERM_COMMAND_RELOAD_RBAC,                             true,  &HandleReloadRBACCommand,                       "" },
            { "reference_loot_template",       rbac::RBAC_PERM_COMMAND_RELOAD_REFERENCE_LOOT_TEMPLATE,          true,  &HandleReloadLootTemplatesReferenceCommand,     "" },
            { "reserved_name",                 rbac::RBAC_PERM_COMMAND_RELOAD_RESERVED_NAME,                    true,  &HandleReloadReservedNameCommand,               "" },
            { "reputation_reward_rate",        rbac::RBAC_PERM_COMMAND_RELOAD_REPUTATION_REWARD_RATE,           true,  &HandleReloadReputationRewardRateCommand,       "" },
            { "reputation_spillover_template", rbac::RBAC_PERM_COMMAND_RELOAD_SPILLOVER_TEMPLATE,               true,  &HandleReloadReputationRewardRateCommand,       "" },
            { "skill_discovery_template",      rbac::RBAC_PERM_COMMAND_RELOAD_SKILL_DISCOVERY_TEMPLATE,         true,  &HandleReloadSkillDiscoveryTemplateCommand,     "" },
            { "scene_template",                rbac::RBAC_PERM_COMMAND_RELOAD_SCENE_TEMPLATE,                   true,  &HandleReloadSceneTemplateCommand,              "" },
            { "skill_extra_item_template",     rbac::RBAC_PERM_COMMAND_RELOAD_SKILL_EXTRA_ITEM_TEMPLATE,        true,  &HandleReloadSkillExtraItemTemplateCommand,     "" },
            { "skill_fishing_base_level",      rbac::RBAC_PERM_COMMAND_RELOAD_SKILL_FISHING_BASE_LEVEL,         true,  &HandleReloadSkillFishingBaseLevelCommand,      "" },
            { "skinning_loot_template",        rbac::RBAC_PERM_COMMAND_RELOAD_SKINNING_LOOT_TEMPLATE,           true,  &HandleReloadLootTemplatesSkinningCommand,      "" },
            { "smart_scripts",                 rbac::RBAC_PERM_COMMAND_RELOAD_SMART_SCRIPTS,                    true,  &HandleReloadSmartScripts,                      "" },
            { "spell_required",                rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_REQUIRED,                   true,  &HandleReloadSpellRequiredCommand,              "" },
            { "spell_area",                    rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_AREA,                       true,  &HandleReloadSpellAreaCommand,                  "" },
            { "spell_group",                   rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP,                      true,  &HandleReloadSpellGroupsCommand,                "" },
            { "spell_learn_spell",             rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_LEARN_SPELL,                true,  &HandleReloadSpellLearnSpellCommand,            "" },
            { "spell_loot_template",           rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_LOOT_TEMPLATE,              true,  &HandleReloadLootTemplatesSpellCommand,         "" },
            { "spell_linked_spell",            rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_LINKED_SPELL,               true,  &HandleReloadSpellLinkedSpellCommand,           "" },
            { "spell_pet_auras",               rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_PET_AURAS,                  true,  &HandleReloadSpellPetAurasCommand,              "" },
            { "spell_proc",                    rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_PROC,                       true,  &HandleReloadSpellProcsCommand,                 "" },
            { "spell_scripts",                 rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_SCRIPTS,                    true,  &HandleReloadSpellScriptsCommand,               "" },
            { "spell_target_position",         rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_TARGET_POSITION,            true,  &HandleReloadSpellTargetPositionCommand,        "" },
            { "spell_threats",                 rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_THREATS,                    true,  &HandleReloadSpellThreatsCommand,               "" },
            { "spell_group_stack_rules",       rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP_STACK_RULES,          true,  &HandleReloadSpellGroupStackRulesCommand,       "" },
            { "support",                       rbac::RBAC_PERM_COMMAND_RELOAD_SUPPORT_SYSTEM,                   true,  &HandleReloadSupportSystemCommand,              "" },
            { "trainer",                       rbac::RBAC_PERM_COMMAND_RELOAD_TRAINER,                          true,  &HandleReloadTrainerCommand,                    "" },
            { "trinity_string",                rbac::RBAC_PERM_COMMAND_RELOAD_TRINITY_STRING,                   true,  &HandleReloadTrinityStringCommand,              "" },
            { "warden_action",                 rbac::RBAC_PERM_COMMAND_RELOAD_WARDEN_ACTION,                    true,  &HandleReloadWardenactionCommand,               "" },
            { "waypoint_scripts",              rbac::RBAC_PERM_COMMAND_RELOAD_WAYPOINT_SCRIPTS,                 true,  &HandleReloadWpScriptsCommand,                  "" },
            { "waypoint_data",                 rbac::RBAC_PERM_COMMAND_RELOAD_WAYPOINT_DATA,                    true,  &HandleReloadWpCommand,                         "" },
            { "vehicle_accessory",             rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_ACCESORY,                 true,  &HandleReloadVehicleAccessoryCommand,           "" },
            { "vehicle_template_accessory",    rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_TEMPLATE_ACCESSORY,       true,  &HandleReloadVehicleTemplateAccessoryCommand,   "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "reload",                        rbac::RBAC_PERM_COMMAND_RELOAD,                                  true,  NULL,                                           "", reloadCommandTable },
        };
        return commandTable;
    }

    //reload commands
    static bool HandleReloadSupportSystemCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Support System Tables...");
        sSupportMgr->LoadBugTickets();
        sSupportMgr->LoadComplaintTickets();
        sSupportMgr->LoadSuggestionTickets();
        handler->SendGlobalGMSysMessage("DB tables `gm_*` reloaded.");
        return true;
    }

    static bool HandleReloadAllCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadSkillFishingBaseLevelCommand(handler, "");

        HandleReloadAllAchievementCommand(handler, "");
        HandleReloadAllAreaCommand(handler, "");
        HandleReloadAllLootCommand(handler, "");
        HandleReloadAllNpcCommand(handler, "");
        HandleReloadAllQuestCommand(handler, "");
        HandleReloadAllSpellCommand(handler, "");
        HandleReloadAllItemCommand(handler, "");
        HandleReloadAllGossipsCommand(handler, "");
        HandleReloadAllLocalesCommand(handler, "");

        HandleReloadAccessRequirementCommand(handler, "");
        HandleReloadMailLevelRewardCommand(handler, "");
        HandleReloadCommandCommand(handler, "");
        HandleReloadReservedNameCommand(handler, "");
        HandleReloadTrinityStringCommand(handler, "");
        HandleReloadGameTeleCommand(handler, "");

        HandleReloadCreatureSummonGroupsCommand(handler, "");

        HandleReloadVehicleAccessoryCommand(handler, "");
        HandleReloadVehicleTemplateAccessoryCommand(handler, "");

        HandleReloadAutobroadcastCommand(handler, "");
        HandleReloadBattlegroundTemplate(handler, "");
        HandleReloadCharacterTemplate(handler, "");
        return true;
    }

    static bool HandleReloadAllAchievementCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadCriteriaDataCommand(handler, "");
        HandleReloadAchievementRewardCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllAreaCommand(ChatHandler* handler, const char* /*args*/)
    {
        //HandleReloadQuestAreaTriggersCommand(handler, ""); -- reloaded in HandleReloadAllQuestCommand
        HandleReloadAreaTriggerTeleportCommand(handler, "");
        HandleReloadAreaTriggerTavernCommand(handler, "");
        HandleReloadGameGraveyardZoneCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllLootCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables...");
        LoadLootTables();
        handler->SendGlobalGMSysMessage("DB tables `*_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadAllNpcCommand(ChatHandler* handler, const char* args)
    {
        if (*args != 'a')                                          // will be reloaded from all_gossips
        HandleReloadTrainerCommand(handler, "a");
        HandleReloadNpcVendorCommand(handler, "a");
        HandleReloadPointsOfInterestCommand(handler, "a");
        HandleReloadSpellClickSpellsCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllQuestCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadQuestAreaTriggersCommand(handler, "a");
        HandleReloadQuestGreetingCommand(handler, "a");
        HandleReloadQuestPOICommand(handler, "a");
        HandleReloadQuestTemplateCommand(handler, "a");

        TC_LOG_INFO("misc", "Re-Loading Quests Relations...");
        sObjectMgr->LoadQuestStartersAndEnders();
        handler->SendGlobalGMSysMessage("DB tables `*_queststarter` and `*_questender` reloaded.");
        return true;
    }

    static bool HandleReloadAllScriptsCommand(ChatHandler* handler, const char* /*args*/)
    {
        if (sMapMgr->IsScriptScheduled())
        {
            handler->PSendSysMessage("DB scripts used currently, please attempt reload later.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        TC_LOG_INFO("misc", "Re-Loading Scripts...");
        HandleReloadEventScriptsCommand(handler, "a");
        HandleReloadSpellScriptsCommand(handler, "a");
        handler->SendGlobalGMSysMessage("DB tables `*_scripts` reloaded.");
        HandleReloadWpScriptsCommand(handler, "a");
        HandleReloadWpCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadSkillDiscoveryTemplateCommand(handler, "a");
        HandleReloadSkillExtraItemTemplateCommand(handler, "a");
        HandleReloadSpellRequiredCommand(handler, "a");
        HandleReloadSpellAreaCommand(handler, "a");
        HandleReloadSpellGroupsCommand(handler, "a");
        HandleReloadSpellLearnSpellCommand(handler, "a");
        HandleReloadSpellLinkedSpellCommand(handler, "a");
        HandleReloadSpellProcsCommand(handler, "a");
        HandleReloadSpellTargetPositionCommand(handler, "a");
        HandleReloadSpellThreatsCommand(handler, "a");
        HandleReloadSpellGroupStackRulesCommand(handler, "a");
        HandleReloadSpellPetAurasCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllGossipsCommand(ChatHandler* handler, const char* args)
    {
        HandleReloadGossipMenuCommand(handler, "a");
        HandleReloadGossipMenuOptionCommand(handler, "a");
        if (*args != 'a')                                          // already reload from all_scripts
        HandleReloadPointsOfInterestCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllItemCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadPageTextsCommand(handler, "a");
        HandleReloadItemEnchantementsCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllLocalesCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadLocalesAchievementRewardCommand(handler, "a");
        HandleReloadLocalesCreatureCommand(handler, "a");
        HandleReloadLocalesCreatureTextCommand(handler, "a");
        HandleReloadLocalesGameobjectCommand(handler, "a");
        HandleReloadLocalesGossipMenuOptionCommand(handler, "a");
        HandleReloadLocalesPageTextCommand(handler, "a");
        HandleReloadLocalesPointsOfInterestCommand(handler, "a");
        HandleReloadQuestLocaleCommand(handler, "a");
        return true;
    }

    static bool HandleReloadConfigCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading config settings...");
        sWorld->LoadConfigSettings(true);
        sMapMgr->InitializeVisibilityDistanceInfo();
        handler->SendGlobalGMSysMessage("World config settings reloaded.");
        return true;
    }

    static bool HandleReloadAccessRequirementCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Access Requirement definitions...");
        sObjectMgr->LoadAccessRequirements();
        handler->SendGlobalGMSysMessage("DB table `access_requirement` reloaded.");
        return true;
    }

    static bool HandleReloadCriteriaDataCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Additional Criteria Data...");
        sCriteriaMgr->LoadCriteriaData();
        handler->SendGlobalGMSysMessage("DB table `criteria_data` reloaded.");
        return true;
    }

    static bool HandleReloadAchievementRewardCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Achievement Reward Data...");
        sAchievementMgr->LoadRewards();
        handler->SendGlobalGMSysMessage("DB table `achievement_reward` reloaded.");
        return true;
    }

    static bool HandleReloadAreaTriggerTavernCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Tavern Area Triggers...");
        sObjectMgr->LoadTavernAreaTriggers();
        handler->SendGlobalGMSysMessage("DB table `areatrigger_tavern` reloaded.");
        return true;
    }

    static bool HandleReloadAreaTriggerTeleportCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading AreaTrigger teleport definitions...");
        sObjectMgr->LoadAreaTriggerTeleports();
        handler->SendGlobalGMSysMessage("DB table `areatrigger_teleport` reloaded.");
        return true;
    }

    static bool HandleReloadAutobroadcastCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Autobroadcasts...");
        sWorld->LoadAutobroadcasts();
        handler->SendGlobalGMSysMessage("DB table `autobroadcast` reloaded.");
        return true;
    }

    static bool HandleReloadBattlegroundTemplate(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Battleground Templates...");
        sBattlegroundMgr->LoadBattlegroundTemplates();
        handler->SendGlobalGMSysMessage("DB table `battleground_template` reloaded.");
        return true;
    }

    static bool HandleReloadCharacterTemplate(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Character Templates...");
        sCharacterTemplateDataStore->LoadCharacterTemplates();
        handler->SendGlobalGMSysMessage("DB table `character_template` and `character_template_class` reloaded.");
        return true;
    }

    static bool HandleReloadCommandCommand(ChatHandler* handler, const char* /*args*/)
    {
        ChatHandler::invalidateCommandTable();
        handler->SendGlobalGMSysMessage("DB table `command` will be reloaded at next chat command use.");
        return true;
    }

    static bool HandleReloadOnKillReputationCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading creature award reputation definitions...");
        sObjectMgr->LoadReputationOnKill();
        handler->SendGlobalGMSysMessage("DB table `creature_onkill_reputation` reloaded.");
        return true;
    }

    static bool HandleReloadCreatureSummonGroupsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading creature summon groups...");
        sObjectMgr->LoadTempSummons();
        handler->SendGlobalGMSysMessage("DB table `creature_summon_groups` reloaded.");
        return true;
    }

    static bool HandleReloadCreatureTemplateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Tokenizer entries(std::string(args), ' ');

        for (Tokenizer::const_iterator itr = entries.begin(); itr != entries.end(); ++itr)
        {
            uint32 entry = atoul(*itr);

            PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEMPLATE);
            stmt->setUInt32(0, entry);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage(LANG_COMMAND_CREATURETEMPLATE_NOTFOUND, entry);
                continue;
            }

            CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(entry);
            if (!cInfo)
            {
                handler->PSendSysMessage(LANG_COMMAND_CREATURESTORAGE_NOTFOUND, entry);
                continue;
            }

            TC_LOG_INFO("misc", "Reloading creature template entry %u", entry);

            Field* fields = result->Fetch();
            sObjectMgr->LoadCreatureTemplate(fields);
            sObjectMgr->CheckCreatureTemplate(cInfo);
        }

        handler->SendGlobalGMSysMessage("Creature template reloaded.");
        return true;
    }

    static bool HandleReloadCreatureQuestStarterCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`creature_queststarter`)");
        sObjectMgr->LoadCreatureQuestStarters();
        handler->SendGlobalGMSysMessage("DB table `creature_queststarter` reloaded.");
        return true;
    }

    static bool HandleReloadLinkedRespawnCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Linked Respawns... (`creature_linked_respawn`)");
        sObjectMgr->LoadLinkedRespawn();
        handler->SendGlobalGMSysMessage("DB table `creature_linked_respawn` (creature linked respawns) reloaded.");
        return true;
    }

    static bool HandleReloadCreatureQuestEnderCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`creature_questender`)");
        sObjectMgr->LoadCreatureQuestEnders();
        handler->SendGlobalGMSysMessage("DB table `creature_questender` reloaded.");
        return true;
    }

    static bool HandleReloadGossipMenuCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `gossip_menu` Table!");
        sObjectMgr->LoadGossipMenu();
        handler->SendGlobalGMSysMessage("DB table `gossip_menu` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadGossipMenuOptionCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `gossip_menu_option` Table!");
        sObjectMgr->LoadGossipMenuItems();
        handler->SendGlobalGMSysMessage("DB table `gossip_menu_option` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadGOQuestStarterCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`gameobject_queststarter`)");
        sObjectMgr->LoadGameobjectQuestStarters();
        handler->SendGlobalGMSysMessage("DB table `gameobject_queststarter` reloaded.");
        return true;
    }

    static bool HandleReloadGOQuestEnderCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`gameobject_questender`)");
        sObjectMgr->LoadGameobjectQuestEnders();
        handler->SendGlobalGMSysMessage("DB table `gameobject_questender` reloaded.");
        return true;
    }

    static bool HandleReloadQuestAreaTriggersCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Area Triggers...");
        sObjectMgr->LoadQuestAreaTriggers();
        handler->SendGlobalGMSysMessage("DB table `areatrigger_involvedrelation` (quest area triggers) reloaded.");
        return true;
    }

    static bool HandleReloadQuestGreetingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Greeting ... ");
        sObjectMgr->LoadQuestGreetings();
        handler->SendGlobalGMSysMessage("DB table `quest_greeting` reloaded.");
        return true;
    }

    static bool HandleReloadQuestTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Templates...");
        sObjectMgr->LoadQuests();
        handler->SendGlobalGMSysMessage("DB table `quest_template` (quest definitions) reloaded.");

        /// dependent also from `gameobject` but this table not reloaded anyway
        TC_LOG_INFO("misc", "Re-Loading GameObjects for quests...");
        sObjectMgr->LoadGameObjectForQuests();
        handler->SendGlobalGMSysMessage("Data GameObjects for quests reloaded.");
        return true;
    }

    static bool HandleReloadLootTemplatesCreatureCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`creature_loot_template`)");
        LoadLootTemplates_Creature();
        LootTemplates_Creature.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `creature_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesDisenchantCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`disenchant_loot_template`)");
        LoadLootTemplates_Disenchant();
        LootTemplates_Disenchant.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `disenchant_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesFishingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`fishing_loot_template`)");
        LoadLootTemplates_Fishing();
        LootTemplates_Fishing.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `fishing_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesGameobjectCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`gameobject_loot_template`)");
        LoadLootTemplates_Gameobject();
        LootTemplates_Gameobject.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `gameobject_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesItemCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`item_loot_template`)");
        LoadLootTemplates_Item();
        LootTemplates_Item.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `item_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesMillingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`milling_loot_template`)");
        LoadLootTemplates_Milling();
        LootTemplates_Milling.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `milling_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesPickpocketingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`pickpocketing_loot_template`)");
        LoadLootTemplates_Pickpocketing();
        LootTemplates_Pickpocketing.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `pickpocketing_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesProspectingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`prospecting_loot_template`)");
        LoadLootTemplates_Prospecting();
        LootTemplates_Prospecting.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `prospecting_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesMailCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`mail_loot_template`)");
        LoadLootTemplates_Mail();
        LootTemplates_Mail.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `mail_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesReferenceCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`reference_loot_template`)");
        LoadLootTemplates_Reference();
        handler->SendGlobalGMSysMessage("DB table `reference_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesSkinningCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`skinning_loot_template`)");
        LoadLootTemplates_Skinning();
        LootTemplates_Skinning.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `skinning_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`spell_loot_template`)");
        LoadLootTemplates_Spell();
        LootTemplates_Spell.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `spell_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadTrinityStringCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading trinity_string Table!");
        sObjectMgr->LoadTrinityStrings();
        handler->SendGlobalGMSysMessage("DB table `trinity_string` reloaded.");
        return true;
    }

    static bool HandleReloadWardenactionCommand(ChatHandler* handler, const char* /*args*/)
    {
        if (!sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED))
        {
            handler->SendSysMessage("Warden system disabled by config - reloading warden_action skipped.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        TC_LOG_INFO("misc", "Re-Loading warden_action Table!");
        sWardenCheckMgr->LoadWardenOverrides();
        handler->SendGlobalGMSysMessage("DB table `warden_action` reloaded.");
        return true;
    }

    static bool HandleReloadTrainerCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `trainer` Table!");
        sObjectMgr->LoadTrainers();
        sObjectMgr->LoadCreatureDefaultTrainers();
        handler->SendGlobalGMSysMessage("DB table `trainer` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `trainer_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `trainer_spell` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `creature_default_trainer` reloaded.");
        return true;
    }

    static bool HandleReloadNpcVendorCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `npc_vendor` Table!");
        sObjectMgr->LoadVendors();
        handler->SendGlobalGMSysMessage("DB table `npc_vendor` reloaded.");
        return true;
    }

    static bool HandleReloadPointsOfInterestCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `points_of_interest` Table!");
        sObjectMgr->LoadPointsOfInterest();
        handler->SendGlobalGMSysMessage("DB table `points_of_interest` reloaded.");
        return true;
    }

    static bool HandleReloadQuestPOICommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest POI ..." );
        sObjectMgr->LoadQuestPOI();
        handler->SendGlobalGMSysMessage("DB Table `quest_poi` and `quest_poi_points` reloaded.");
        return true;
    }

    static bool HandleReloadSpellClickSpellsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `npc_spellclick_spells` Table!");
        sObjectMgr->LoadNPCSpellClickSpells();
        handler->SendGlobalGMSysMessage("DB table `npc_spellclick_spells` reloaded.");
        return true;
    }

    static bool HandleReloadReservedNameCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading ReservedNames... (`reserved_name`)");
        sObjectMgr->LoadReservedPlayersNames();
        handler->SendGlobalGMSysMessage("DB table `reserved_name` (player reserved names) reloaded.");
        return true;
    }

    static bool HandleReloadReputationRewardRateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `reputation_reward_rate` Table!" );
        sObjectMgr->LoadReputationRewardRate();
        handler->SendGlobalSysMessage("DB table `reputation_reward_rate` reloaded.");
        return true;
    }

    static bool HandleReloadReputationSpilloverTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `reputation_spillover_template` Table!" );
        sObjectMgr->LoadReputationSpilloverTemplate();
        handler->SendGlobalSysMessage("DB table `reputation_spillover_template` reloaded.");
        return true;
    }

    static bool HandleReloadSkillDiscoveryTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Skill Discovery Table...");
        LoadSkillDiscoveryTable();
        handler->SendGlobalGMSysMessage("DB table `skill_discovery_template` (recipes discovered at crafting) reloaded.");
        return true;
    }

    static bool HandleReloadSkillPerfectItemTemplateCommand(ChatHandler* handler, const char* /*args*/)
    { // latched onto HandleReloadSkillExtraItemTemplateCommand as it's part of that table group (and i don't want to chance all the command IDs)
        TC_LOG_INFO("misc", "Re-Loading Skill Perfection Data Table...");
        LoadSkillPerfectItemTable();
        handler->SendGlobalGMSysMessage("DB table `skill_perfect_item_template` (perfect item procs when crafting) reloaded.");
        return true;
    }

    static bool HandleReloadSkillExtraItemTemplateCommand(ChatHandler* handler, const char* args)
    {
        TC_LOG_INFO("misc", "Re-Loading Skill Extra Item Table...");
        LoadSkillExtraItemTable();
        handler->SendGlobalGMSysMessage("DB table `skill_extra_item_template` (extra item creation when crafting) reloaded.");

        return HandleReloadSkillPerfectItemTemplateCommand(handler, args);
    }

    static bool HandleReloadSkillFishingBaseLevelCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Skill Fishing base level requirements...");
        sObjectMgr->LoadFishingBaseSkillLevel();
        handler->SendGlobalGMSysMessage("DB table `skill_fishing_base_level` (fishing base level for zone/subzone) reloaded.");
        return true;
    }

    static bool HandleReloadSpellAreaCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading SpellArea Data...");
        sSpellMgr->LoadSpellAreas();
        handler->SendGlobalGMSysMessage("DB table `spell_area` (spell dependences from area/quest/auras state) reloaded.");
        return true;
    }

    static bool HandleReloadSpellRequiredCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Required Data... ");
        sSpellMgr->LoadSpellRequired();
        handler->SendGlobalGMSysMessage("DB table `spell_required` reloaded.");
        return true;
    }

    static bool HandleReloadSpellGroupsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Groups...");
        sSpellMgr->LoadSpellGroups();
        handler->SendGlobalGMSysMessage("DB table `spell_group` (spell groups) reloaded.");
        return true;
    }

    static bool HandleReloadSpellLearnSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Learn Spells...");
        sSpellMgr->LoadSpellLearnSpells();
        handler->SendGlobalGMSysMessage("DB table `spell_learn_spell` reloaded.");
        return true;
    }

    static bool HandleReloadSpellLinkedSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Linked Spells...");
        sSpellMgr->LoadSpellLinked();
        handler->SendGlobalGMSysMessage("DB table `spell_linked_spell` reloaded.");
        return true;
    }

    static bool HandleReloadSpellProcsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Proc conditions and data...");
        sSpellMgr->LoadSpellProcs();
        handler->SendGlobalGMSysMessage("DB table `spell_proc` (spell proc conditions and data) reloaded.");
        return true;
    }

    static bool HandleReloadSpellTargetPositionCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell target coordinates...");
        sSpellMgr->LoadSpellTargetPositions();
        handler->SendGlobalGMSysMessage("DB table `spell_target_position` (destination coordinates for spell targets) reloaded.");
        return true;
    }

    static bool HandleReloadSpellThreatsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Aggro Spells Definitions...");
        sSpellMgr->LoadSpellThreats();
        handler->SendGlobalGMSysMessage("DB table `spell_threat` (spell aggro definitions) reloaded.");
        return true;
    }

    static bool HandleReloadSpellGroupStackRulesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Group Stack Rules...");
        sSpellMgr->LoadSpellGroupStackRules();
        handler->SendGlobalGMSysMessage("DB table `spell_group_stack_rules` (spell stacking definitions) reloaded.");
        return true;
    }

    static bool HandleReloadSpellPetAurasCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell pet auras...");
        sSpellMgr->LoadSpellPetAuras();
        handler->SendGlobalGMSysMessage("DB table `spell_pet_auras` reloaded.");
        return true;
    }

    static bool HandleReloadPageTextsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Page Text...");
        sObjectMgr->LoadPageTexts();
        handler->SendGlobalGMSysMessage("DB table `page_text` reloaded.");
        return true;
    }

    static bool HandleReloadItemEnchantementsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Item Random Enchantments Table...");
        LoadRandomEnchantmentsTable();
        handler->SendGlobalGMSysMessage("DB table `item_enchantment_template` reloaded.");
        return true;
    }

    static bool HandleReloadEventScriptsCommand(ChatHandler* handler, const char* args)
    {
        if (sMapMgr->IsScriptScheduled())
        {
            handler->SendSysMessage("DB scripts used currently, please attempt reload later.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (*args != 'a')
            TC_LOG_INFO("misc", "Re-Loading Scripts from `event_scripts`...");

        sObjectMgr->LoadEventScripts();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("DB table `event_scripts` reloaded.");

        return true;
    }

    static bool HandleReloadWpScriptsCommand(ChatHandler* handler, const char* args)
    {
        if (sMapMgr->IsScriptScheduled())
        {
            handler->SendSysMessage("DB scripts used currently, please attempt reload later.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (*args != 'a')
            TC_LOG_INFO("misc", "Re-Loading Scripts from `waypoint_scripts`...");

        sObjectMgr->LoadWaypointScripts();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("DB table `waypoint_scripts` reloaded.");

        return true;
    }

    static bool HandleReloadWpCommand(ChatHandler* handler, const char* args)
    {
        if (*args != 'a')
            TC_LOG_INFO("misc", "Re-Loading Waypoints data from 'waypoints_data'");

        sWaypointMgr->Load();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("DB Table 'waypoint_data' reloaded.");

        return true;
    }

    static bool HandleReloadSpellScriptsCommand(ChatHandler* handler, const char* args)
    {
        if (sMapMgr->IsScriptScheduled())
        {
            handler->SendSysMessage("DB scripts used currently, please attempt reload later.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (*args != 'a')
            TC_LOG_INFO("misc", "Re-Loading Scripts from `spell_scripts`...");

        sObjectMgr->LoadSpellScripts();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("DB table `spell_scripts` reloaded.");

        return true;
    }

    static bool HandleReloadGameGraveyardZoneCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Graveyard-zone links...");

        sObjectMgr->LoadGraveyardZones();

        handler->SendGlobalGMSysMessage("DB table `graveyard_zone` reloaded.");

        return true;
    }

    static bool HandleReloadGameTeleCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Game Tele coordinates...");

        sObjectMgr->LoadGameTele();

        handler->SendGlobalGMSysMessage("DB table `game_tele` reloaded.");

        return true;
    }

    static bool HandleReloadDisablesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading disables table...");
        DisableMgr::LoadDisables();
        TC_LOG_INFO("misc", "Checking quest disables...");
        DisableMgr::CheckQuestDisables();
        handler->SendGlobalGMSysMessage("DB table `disables` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesAchievementRewardCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Achievement Reward Data...");
        sAchievementMgr->LoadRewardLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_achievement_reward` reloaded.");
        return true;
    }

    static bool HandleReloadLfgRewardsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading lfg dungeon rewards...");
        sLFGMgr->LoadRewards();
        handler->SendGlobalGMSysMessage("DB table `lfg_dungeon_rewards` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesCreatureCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Creature ...");
        sObjectMgr->LoadCreatureLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_creature` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesCreatureTextCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Creature Texts...");
        sCreatureTextMgr->LoadCreatureTextLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_creature_text` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesGameobjectCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Gameobject ... ");
        sObjectMgr->LoadGameObjectLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_gameobject` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesGossipMenuOptionCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Gossip Menu Option ... ");
        sObjectMgr->LoadGossipMenuItemsLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_gossip_menu_option` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesPageTextCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Page Text ... ");
        sObjectMgr->LoadPageTextLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_page_text` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesPointsOfInterestCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Locales Points Of Interest ... ");
        sObjectMgr->LoadPointOfInterestLocales();
        handler->SendGlobalGMSysMessage("DB table `locales_points_of_interest` reloaded.");
        return true;
    }

    static bool HandleReloadQuestLocaleCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Locale ... ");
        sObjectMgr->LoadQuestTemplateLocale();
        sObjectMgr->LoadQuestObjectivesLocale();
        sObjectMgr->LoadQuestOfferRewardLocale();
        sObjectMgr->LoadQuestRequestItemsLocale();
        handler->SendGlobalGMSysMessage("DB table `quest_template_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_objectives_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_offer_reward_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_request_items_locale` reloaded.");
        return true;
    }

    static bool HandleReloadMailLevelRewardCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Player level dependent mail rewards...");
        sObjectMgr->LoadMailLevelRewards();
        handler->SendGlobalGMSysMessage("DB table `mail_level_reward` reloaded.");
        return true;
    }

    static bool HandleReloadAuctionsCommand(ChatHandler* handler, const char* /*args*/)
    {
        ///- Reload dynamic data tables from the database
        TC_LOG_INFO("misc", "Re-Loading Auctions...");
        sAuctionMgr->LoadAuctionItems();
        sAuctionMgr->LoadAuctions();
        handler->SendGlobalGMSysMessage("Auctions reloaded.");
        return true;
    }

    static bool HandleReloadConditions(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Conditions...");
        sConditionMgr->LoadConditions(true);
        handler->SendGlobalGMSysMessage("Conditions reloaded.");
        return true;
    }

    static bool HandleReloadCreatureText(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Creature Texts...");
        sCreatureTextMgr->LoadCreatureTexts();
        handler->SendGlobalGMSysMessage("Creature Texts reloaded.");
        return true;
    }

    static bool HandleReloadSmartScripts(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Smart Scripts...");
        sSmartScriptMgr->LoadSmartAIFromDB();
        handler->SendGlobalGMSysMessage("Smart Scripts reloaded.");
        return true;
    }

    static bool HandleReloadVehicleAccessoryCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading vehicle_accessory table...");
        sObjectMgr->LoadVehicleAccessories();
        handler->SendGlobalGMSysMessage("Vehicle accessories reloaded.");
        return true;
    }

    static bool HandleReloadVehicleTemplateAccessoryCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading vehicle_template_accessory table...");
        sObjectMgr->LoadVehicleTemplateAccessories();
        handler->SendGlobalGMSysMessage("Vehicle template accessories reloaded.");
        return true;
    }

    static bool HandleReloadPhaseDefinitionsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading terrain_phase_info table...");
        sObjectMgr->LoadTerrainPhaseInfo();
        handler->SendGlobalGMSysMessage("Terrain phase infos reloaded.");
        return true;
    }

    static bool HandleReloadAreaTriggerTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading areatrigger_template table...");
        sAreaTriggerDataStore->LoadAreaTriggerTemplates();
        handler->SendGlobalGMSysMessage("AreaTrigger templates reloaded. Already spawned AT won't be affected. New scriptname need a reboot.");
        return true;
    }

    static bool HandleReloadSceneTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading scene_template table...");
        sObjectMgr->LoadSceneTemplates();
        handler->SendGlobalGMSysMessage("Scenes templates reloaded. New scriptname need a reboot.");
        return true;
    }

    static bool HandleReloadConversationTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading conversation_* tables...");
        sConversationDataStore->LoadConversationTemplates();
        handler->SendGlobalGMSysMessage("Conversation templates reloaded.");
        return true;
    }

    static bool HandleReloadRBACCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading RBAC tables...");
        sAccountMgr->LoadRBAC();
        sWorld->ReloadRBAC();
        handler->SendGlobalGMSysMessage("RBAC data reloaded.");
        return true;
    }
};

void AddSC_reload_commandscript()
{
    new reload_commandscript();
}
