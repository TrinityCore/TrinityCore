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
Name: reload_commandscript
%Complete: 100
Comment: All reload related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "AreaTriggerDataStore.h"
#include "AuctionHouseMgr.h"
#include "BattlegroundMgr.h"
#include "CharacterTemplateDataStore.h"
#include "Chat.h"
#include "ChatCommand.h"
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
#include "SkillDiscovery.h"
#include "SkillExtraItems.h"
#include "SmartAI.h"
#include "SpellMgr.h"
#include "StringConvert.h"
#include "SupportMgr.h"
#include "WaypointManager.h"
#include "World.h"

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

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
            { "all",                           rbac::RBAC_PERM_COMMAND_RELOAD_ALL,                              true,  nullptr,                                        "", reloadAllCommandTable },
            { "areatrigger_involvedrelation",  rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_INVOLVEDRELATION,     true,  &HandleReloadQuestAreaTriggersCommand,          "" },
            { "areatrigger_tavern",            rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TAVERN,               true,  &HandleReloadAreaTriggerTavernCommand,          "" },
            { "areatrigger_teleport",          rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TELEPORT,             true,  &HandleReloadAreaTriggerTeleportCommand,        "" },
            { "areatrigger_template",          rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TEMPLATE,             true,  &HandleReloadAreaTriggerTemplateCommand,        "" },
            { "autobroadcast",                 rbac::RBAC_PERM_COMMAND_RELOAD_AUTOBROADCAST,                    true,  &HandleReloadAutobroadcastCommand,              "" },
            { "battleground_template",         rbac::RBAC_PERM_COMMAND_RELOAD_BATTLEGROUND_TEMPLATE,            true,  &HandleReloadBattlegroundTemplate,              "" },
            { "character_template",            rbac::RBAC_PERM_COMMAND_RELOAD_CHARACTER_TEMPLATE,               true,  &HandleReloadCharacterTemplate,                 "" },
            { "conditions",                    rbac::RBAC_PERM_COMMAND_RELOAD_CONDITIONS,                       true,  &HandleReloadConditions,                        "" },
            { "config",                        rbac::RBAC_PERM_COMMAND_RELOAD_CONFIG,                           true,  &HandleReloadConfigCommand,                     "" },
            { "conversation_template",         rbac::RBAC_PERM_COMMAND_RELOAD_CONVERSATION_TEMPLATE,            true,  &HandleReloadConversationTemplateCommand,       "" },
            { "creature_text",                 rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_TEXT,                    true,  &HandleReloadCreatureText,                      "" },
            { "creature_questender",           rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTENDER,              true,  &HandleReloadCreatureQuestEnderCommand,         "" },
            { "creature_linked_respawn",       rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_LINKED_RESPAWN,          true,  &HandleReloadLinkedRespawnCommand,              "" },
            { "creature_loot_template",        rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_LOOT_TEMPLATE,           true,  &HandleReloadLootTemplatesCreatureCommand,      "" },
            { "creature_movement_override",    rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_MOVEMENT_OVERRIDE,       true,  &HandleReloadCreatureMovementOverrideCommand,   "" },
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
            { "item_random_bonus_list_template", rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_RANDOM_BONUS_LIST_TEMPLATE, true, &HandleReloadItemRandomBonusListTemplatesCommand, "" },
            { "item_loot_template",            rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_LOOT_TEMPLATE,               true,  &HandleReloadLootTemplatesItemCommand,          "" },
            { "lfg_dungeon_rewards",           rbac::RBAC_PERM_COMMAND_RELOAD_LFG_DUNGEON_REWARDS,              true,  &HandleReloadLfgRewardsCommand,                 "" },
            { "achievement_reward_locale",     rbac::RBAC_PERM_COMMAND_RELOAD_ACHIEVEMENT_REWARD_LOCALE,        true,  &HandleReloadLocalesAchievementRewardCommand,   "" },
            { "creature_template_locale",      rbac::RBAC_PERM_COMMAND_RELOAD_CRETURE_TEMPLATE_LOCALE,          true,  &HandleReloadLocalesCreatureCommand,            "" },
            { "creature_text_locale",          rbac::RBAC_PERM_COMMAND_RELOAD_CRETURE_TEXT_LOCALE,              true,  &HandleReloadLocalesCreatureTextCommand,        "" },
            { "gameobject_template_locale",    rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_TEMPLATE_LOCALE,       true,  &HandleReloadLocalesGameobjectCommand,          "" },
            { "gossip_menu_option_locale",     rbac::RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU_OPTION_LOCALE,        true,  &HandleReloadLocalesGossipMenuOptionCommand,    "" },
            { "page_text_locale",              rbac::RBAC_PERM_COMMAND_RELOAD_PAGE_TEXT_LOCALE,                 true,  &HandleReloadLocalesPageTextCommand,            "" },
            { "points_of_interest_locale",     rbac::RBAC_PERM_COMMAND_RELOAD_POINTS_OF_INTEREST_LOCALE,        true,  &HandleReloadLocalesPointsOfInterestCommand,    "" },
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
            { "quest_locale",                  rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_TEMPLATE_LOCALE,            true,  &HandleReloadQuestLocaleCommand,                "" },
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
            { "spell_script_names",            rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_SCRIPT_NAMES,               true,  &HandleReloadSpellScriptNamesCommand,           "" },
            { "spell_target_position",         rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_TARGET_POSITION,            true,  &HandleReloadSpellTargetPositionCommand,        "" },
            { "spell_threats",                 rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_THREATS,                    true,  &HandleReloadSpellThreatsCommand,               "" },
            { "spell_group_stack_rules",       rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP_STACK_RULES,          true,  &HandleReloadSpellGroupStackRulesCommand,       "" },
            { "support",                       rbac::RBAC_PERM_COMMAND_RELOAD_SUPPORT_SYSTEM,                   true,  &HandleReloadSupportSystemCommand,              "" },
            { "trainer",                       rbac::RBAC_PERM_COMMAND_RELOAD_TRAINER,                          true,  &HandleReloadTrainerCommand,                    "" },
            { "trinity_string",                rbac::RBAC_PERM_COMMAND_RELOAD_TRINITY_STRING,                   true,  &HandleReloadTrinityStringCommand,              "" },
            { "waypoint_path",                 rbac::RBAC_PERM_COMMAND_RELOAD_WAYPOINT_PATH,                    true,  &HandleReloadWpCommand,                         "" },
            { "vehicle_template",              rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_TEMPLATE,                 true,  &HandleReloadVehicleTemplateCommand,            "" },
            { "vehicle_accessory",             rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_ACCESORY,                 true,  &HandleReloadVehicleAccessoryCommand,           "" },
            { "vehicle_template_accessory",    rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_TEMPLATE_ACCESSORY,       true,  &HandleReloadVehicleTemplateAccessoryCommand,   "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "reload",                        rbac::RBAC_PERM_COMMAND_RELOAD,                                  true,  nullptr,                                        "", reloadCommandTable },
        };
        return commandTable;
    }

    //reload commands
    static bool HandleReloadSupportSystemCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Support System Tables...");
        sSupportMgr->LoadBugTickets();
        sSupportMgr->LoadComplaintTickets();
        sSupportMgr->LoadSuggestionTickets();
        handler->SendGlobalGMSysMessage("DB tables `gm_*` reloaded.");
        return true;
    }

    static bool HandleReloadAllCommand(ChatHandler* handler, char const* /*args*/)
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
        HandleReloadReservedNameCommand(handler, "");
        HandleReloadTrinityStringCommand(handler, "");
        HandleReloadGameTeleCommand(handler, "");

        HandleReloadCreatureMovementOverrideCommand(handler, "");
        HandleReloadCreatureSummonGroupsCommand(handler);

        HandleReloadVehicleAccessoryCommand(handler, "");
        HandleReloadVehicleTemplateAccessoryCommand(handler, "");

        HandleReloadAutobroadcastCommand(handler, "");
        HandleReloadBattlegroundTemplate(handler, "");
        HandleReloadCharacterTemplate(handler, "");
        return true;
    }

    static bool HandleReloadAllAchievementCommand(ChatHandler* handler, char const* /*args*/)
    {
        HandleReloadCriteriaDataCommand(handler, "");
        HandleReloadAchievementRewardCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllAreaCommand(ChatHandler* handler, char const* /*args*/)
    {
        //HandleReloadQuestAreaTriggersCommand(handler, ""); -- reloaded in HandleReloadAllQuestCommand
        HandleReloadAreaTriggerTeleportCommand(handler, "");
        HandleReloadAreaTriggerTavernCommand(handler, "");
        HandleReloadGameGraveyardZoneCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllLootCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables...");
        LoadLootTables();
        handler->SendGlobalGMSysMessage("DB tables `*_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadAllNpcCommand(ChatHandler* handler, char const* args)
    {
        if (*args != 'a')                                          // will be reloaded from all_gossips
        HandleReloadTrainerCommand(handler, "a");
        HandleReloadNpcVendorCommand(handler, "a");
        HandleReloadPointsOfInterestCommand(handler, "a");
        HandleReloadSpellClickSpellsCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllQuestCommand(ChatHandler* handler, char const* /*args*/)
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

    static bool HandleReloadAllScriptsCommand(ChatHandler* handler, char const* /*args*/)
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
        HandleReloadSpellScriptNamesCommand(handler, "a");
        handler->SendGlobalGMSysMessage("DB tables `*_scripts` reloaded.");
        HandleReloadWpCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllSpellCommand(ChatHandler* handler, char const* /*args*/)
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
        HandleReloadSpellScriptNamesCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllGossipsCommand(ChatHandler* handler, char const* args)
    {
        HandleReloadGossipMenuCommand(handler, "a");
        HandleReloadGossipMenuOptionCommand(handler, "a");
        if (*args != 'a')                                          // already reload from all_scripts
        HandleReloadPointsOfInterestCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllItemCommand(ChatHandler* handler, char const* /*args*/)
    {
        HandleReloadPageTextsCommand(handler, "a");
        HandleReloadItemRandomBonusListTemplatesCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllLocalesCommand(ChatHandler* handler, char const* /*args*/)
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

    static bool HandleReloadConfigCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading config settings...");
        sWorld->LoadConfigSettings(true);
        sMapMgr->InitializeVisibilityDistanceInfo();
        handler->SendGlobalGMSysMessage("World config settings reloaded.");
        return true;
    }

    static bool HandleReloadAccessRequirementCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Access Requirement definitions...");
        sObjectMgr->LoadAccessRequirements();
        handler->SendGlobalGMSysMessage("DB table `access_requirement` reloaded.");
        return true;
    }

    static bool HandleReloadCriteriaDataCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Additional Criteria Data...");
        sCriteriaMgr->LoadCriteriaData();
        sScriptMgr->NotifyScriptIDUpdate();
        handler->SendGlobalGMSysMessage("DB table `criteria_data` reloaded.");
        return true;
    }

    static bool HandleReloadAchievementRewardCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Achievement Reward Data...");
        sAchievementMgr->LoadRewards();
        handler->SendGlobalGMSysMessage("DB table `achievement_reward` reloaded.");
        return true;
    }

    static bool HandleReloadAreaTriggerTavernCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Tavern Area Triggers...");
        sObjectMgr->LoadTavernAreaTriggers();
        handler->SendGlobalGMSysMessage("DB table `areatrigger_tavern` reloaded.");
        return true;
    }

    static bool HandleReloadAreaTriggerTeleportCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Area Trigger Teleports definitions...");
        sObjectMgr->LoadAreaTriggerTeleports();
        handler->SendGlobalGMSysMessage("DB table `areatrigger_teleport` reloaded.");
        return true;
    }

    static bool HandleReloadAutobroadcastCommand(ChatHandler* handler, char const* /*args*/)
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
        sScriptMgr->NotifyScriptIDUpdate();
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

    static bool HandleReloadOnKillReputationCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading creature award reputation definitions...");
        sObjectMgr->LoadReputationOnKill();
        handler->SendGlobalGMSysMessage("DB table `creature_onkill_reputation` reloaded.");
        return true;
    }

    static bool HandleReloadCreatureSummonGroupsCommand(ChatHandler* handler)
    {
        TC_LOG_INFO("misc", "Reloading creature summon groups...");
        sObjectMgr->LoadTempSummons();
        handler->SendGlobalGMSysMessage("DB table `creature_summon_groups` reloaded.");
        return true;
    }

    static bool HandleReloadCreatureTemplateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        for (std::string_view entryStr : Trinity::Tokenize(args, ' ', false))
        {
            uint32 entry = Trinity::StringTo<uint32>(entryStr).value_or(0);

            WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEMPLATE);
            stmt->setUInt32(0, entry);
            stmt->setUInt32(1, 0);
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

            TC_LOG_INFO("misc", "Reloading creature template entry {}", entry);

            Field* fields = result->Fetch();
            sObjectMgr->LoadCreatureTemplate(fields);
            sObjectMgr->CheckCreatureTemplate(cInfo);
        }

        sObjectMgr->InitializeQueriesData(QUERY_DATA_CREATURES);
        sScriptMgr->NotifyScriptIDUpdate();
        handler->SendGlobalGMSysMessage("Creature template reloaded.");
        return true;
    }

    static bool HandleReloadCreatureQuestStarterCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`creature_queststarter`)");
        sObjectMgr->LoadCreatureQuestStarters();
        handler->SendGlobalGMSysMessage("DB table `creature_queststarter` reloaded.");
        return true;
    }

    static bool HandleReloadLinkedRespawnCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Linked Respawns... (`creature_linked_respawn`)");
        sObjectMgr->LoadLinkedRespawn();
        handler->SendGlobalGMSysMessage("DB table `creature_linked_respawn` (creature linked respawns) reloaded.");
        return true;
    }

    static bool HandleReloadCreatureQuestEnderCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`creature_questender`)");
        sObjectMgr->LoadCreatureQuestEnders();
        handler->SendGlobalGMSysMessage("DB table `creature_questender` reloaded.");
        return true;
    }

    static bool HandleReloadGossipMenuCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `gossip_menu` Table!");
        sObjectMgr->LoadGossipMenu();
        handler->SendGlobalGMSysMessage("DB table `gossip_menu` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadGossipMenuOptionCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `gossip_menu_option` Table!");
        sObjectMgr->LoadGossipMenuItems();
        handler->SendGlobalGMSysMessage("DB table `gossip_menu_option` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadGOQuestStarterCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`gameobject_queststarter`)");
        sObjectMgr->LoadGameobjectQuestStarters();
        handler->SendGlobalGMSysMessage("DB table `gameobject_queststarter` reloaded.");
        return true;
    }

    static bool HandleReloadGOQuestEnderCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading Quests Relations... (`gameobject_questender`)");
        sObjectMgr->LoadGameobjectQuestEnders();
        handler->SendGlobalGMSysMessage("DB table `gameobject_questender` reloaded.");
        return true;
    }

    static bool HandleReloadQuestAreaTriggersCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Area Triggers...");
        sObjectMgr->LoadQuestAreaTriggers();
        handler->SendGlobalGMSysMessage("DB table `areatrigger_involvedrelation` (quest area triggers) reloaded.");
        return true;
    }

    static bool HandleReloadQuestGreetingCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Greeting ... ");
        sObjectMgr->LoadQuestGreetings();
        handler->SendGlobalGMSysMessage("DB table `quest_greeting` reloaded.");
        return true;
    }

    static bool HandleReloadQuestTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Templates...");
        sObjectMgr->LoadQuests();
        sObjectMgr->InitializeQueriesData(QUERY_DATA_QUESTS);
        handler->SendGlobalGMSysMessage("DB table `quest_template` (quest definitions) reloaded.");

        /// dependent also from `gameobject` but this table not reloaded anyway
        TC_LOG_INFO("misc", "Re-Loading GameObjects for quests...");
        sObjectMgr->LoadGameObjectForQuests();
        handler->SendGlobalGMSysMessage("Data GameObjects for quests reloaded.");
        sScriptMgr->NotifyScriptIDUpdate();

        return true;
    }

    static bool HandleReloadLootTemplatesCreatureCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`creature_loot_template`)");
        LoadLootTemplates_Creature();
        LootTemplates_Creature.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `creature_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadCreatureMovementOverrideCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Creature movement overrides...");
        sObjectMgr->LoadCreatureMovementOverrides();
        handler->SendGlobalGMSysMessage("DB table `creature_movement_override` reloaded.");
        return true;
    }

    static bool HandleReloadLootTemplatesDisenchantCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`disenchant_loot_template`)");
        LoadLootTemplates_Disenchant();
        LootTemplates_Disenchant.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `disenchant_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesFishingCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`fishing_loot_template`)");
        LoadLootTemplates_Fishing();
        LootTemplates_Fishing.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `fishing_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesGameobjectCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`gameobject_loot_template`)");
        LoadLootTemplates_Gameobject();
        LootTemplates_Gameobject.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `gameobject_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesItemCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`item_loot_template`)");
        LoadLootTemplates_Item();
        LootTemplates_Item.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `item_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesMillingCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`milling_loot_template`)");
        LoadLootTemplates_Milling();
        LootTemplates_Milling.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `milling_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesPickpocketingCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`pickpocketing_loot_template`)");
        LoadLootTemplates_Pickpocketing();
        LootTemplates_Pickpocketing.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `pickpocketing_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesProspectingCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`prospecting_loot_template`)");
        LoadLootTemplates_Prospecting();
        LootTemplates_Prospecting.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `prospecting_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesMailCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`mail_loot_template`)");
        LoadLootTemplates_Mail();
        LootTemplates_Mail.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `mail_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesReferenceCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`reference_loot_template`)");
        LoadLootTemplates_Reference();
        handler->SendGlobalGMSysMessage("DB table `reference_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesSkinningCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`skinning_loot_template`)");
        LoadLootTemplates_Skinning();
        LootTemplates_Skinning.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `skinning_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesSpellCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Loot Tables... (`spell_loot_template`)");
        LoadLootTemplates_Spell();
        LootTemplates_Spell.CheckLootRefs();
        handler->SendGlobalGMSysMessage("DB table `spell_loot_template` reloaded.");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadTrinityStringCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading trinity_string Table!");
        sObjectMgr->LoadTrinityStrings();
        handler->SendGlobalGMSysMessage("DB table `trinity_string` reloaded.");
        return true;
    }

    static bool HandleReloadTrainerCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `trainer` Table!");
        sObjectMgr->LoadTrainers();
        sObjectMgr->LoadCreatureTrainers();
        handler->SendGlobalGMSysMessage("DB table `trainer` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `trainer_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `trainer_spell` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `creature_trainer` reloaded.");
        return true;
    }

    static bool HandleReloadNpcVendorCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `npc_vendor` Table!");
        sObjectMgr->LoadVendors();
        handler->SendGlobalGMSysMessage("DB table `npc_vendor` reloaded.");
        return true;
    }

    static bool HandleReloadPointsOfInterestCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `points_of_interest` Table!");
        sObjectMgr->LoadPointsOfInterest();
        handler->SendGlobalGMSysMessage("DB table `points_of_interest` reloaded.");
        return true;
    }

    static bool HandleReloadQuestPOICommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest POI ..." );
        sObjectMgr->LoadQuestPOI();
        sObjectMgr->InitializeQueriesData(QUERY_DATA_POIS);
        handler->SendGlobalGMSysMessage("DB Table `quest_poi` and `quest_poi_points` reloaded.");
        return true;
    }

    static bool HandleReloadSpellClickSpellsCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `npc_spellclick_spells` Table!");
        sObjectMgr->LoadNPCSpellClickSpells();
        handler->SendGlobalGMSysMessage("DB table `npc_spellclick_spells` reloaded.");
        return true;
    }

    static bool HandleReloadReservedNameCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Loading ReservedNames... (`reserved_name`)");
        sObjectMgr->LoadReservedPlayersNames();
        handler->SendGlobalGMSysMessage("DB table `reserved_name` (player reserved names) reloaded.");
        return true;
    }

    static bool HandleReloadReputationRewardRateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `reputation_reward_rate` Table!" );
        sObjectMgr->LoadReputationRewardRate();
        handler->SendGlobalSysMessage("DB table `reputation_reward_rate` reloaded.");
        return true;
    }

    static bool HandleReloadReputationSpilloverTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading `reputation_spillover_template` Table!" );
        sObjectMgr->LoadReputationSpilloverTemplate();
        handler->SendGlobalSysMessage("DB table `reputation_spillover_template` reloaded.");
        return true;
    }

    static bool HandleReloadSkillDiscoveryTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Skill Discovery Table...");
        LoadSkillDiscoveryTable();
        handler->SendGlobalGMSysMessage("DB table `skill_discovery_template` (recipes discovered at crafting) reloaded.");
        return true;
    }

    static bool HandleReloadSkillPerfectItemTemplateCommand(ChatHandler* handler, char const* /*args*/)
    { // latched onto HandleReloadSkillExtraItemTemplateCommand as it's part of that table group (and i don't want to chance all the command IDs)
        TC_LOG_INFO("misc", "Re-Loading Skill Perfection Data Table...");
        LoadSkillPerfectItemTable();
        handler->SendGlobalGMSysMessage("DB table `skill_perfect_item_template` (perfect item procs when crafting) reloaded.");
        return true;
    }

    static bool HandleReloadSkillExtraItemTemplateCommand(ChatHandler* handler, char const* args)
    {
        TC_LOG_INFO("misc", "Re-Loading Skill Extra Item Table...");
        LoadSkillExtraItemTable();
        handler->SendGlobalGMSysMessage("DB table `skill_extra_item_template` (extra item creation when crafting) reloaded.");

        return HandleReloadSkillPerfectItemTemplateCommand(handler, args);
    }

    static bool HandleReloadSkillFishingBaseLevelCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Skill Fishing base level requirements...");
        sObjectMgr->LoadFishingBaseSkillLevel();
        handler->SendGlobalGMSysMessage("DB table `skill_fishing_base_level` (fishing base level for zone/subzone) reloaded.");
        return true;
    }

    static bool HandleReloadSpellAreaCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading SpellArea Data...");
        sSpellMgr->LoadSpellAreas();
        handler->SendGlobalGMSysMessage("DB table `spell_area` (spell dependences from area/quest/auras state) reloaded.");
        return true;
    }

    static bool HandleReloadSpellRequiredCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Required Data... ");
        sSpellMgr->LoadSpellRequired();
        handler->SendGlobalGMSysMessage("DB table `spell_required` reloaded.");
        return true;
    }

    static bool HandleReloadSpellGroupsCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Groups...");
        sSpellMgr->LoadSpellGroups();
        handler->SendGlobalGMSysMessage("DB table `spell_group` (spell groups) reloaded.");
        return true;
    }

    static bool HandleReloadSpellLearnSpellCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Learn Spells...");
        sSpellMgr->LoadSpellLearnSpells();
        handler->SendGlobalGMSysMessage("DB table `spell_learn_spell` reloaded.");
        return true;
    }

    static bool HandleReloadSpellLinkedSpellCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Linked Spells...");
        sSpellMgr->LoadSpellLinked();
        handler->SendGlobalGMSysMessage("DB table `spell_linked_spell` reloaded.");
        return true;
    }

    static bool HandleReloadSpellProcsCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Proc conditions and data...");
        sSpellMgr->LoadSpellProcs();
        handler->SendGlobalGMSysMessage("DB table `spell_proc` (spell proc conditions and data) reloaded.");
        return true;
    }

    static bool HandleReloadSpellTargetPositionCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell target coordinates...");
        sSpellMgr->LoadSpellTargetPositions();
        handler->SendGlobalGMSysMessage("DB table `spell_target_position` (destination coordinates for spell targets) reloaded.");
        return true;
    }

    static bool HandleReloadSpellThreatsCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Aggro Spells Definitions...");
        sSpellMgr->LoadSpellThreats();
        handler->SendGlobalGMSysMessage("DB table `spell_threat` (spell aggro definitions) reloaded.");
        return true;
    }

    static bool HandleReloadSpellGroupStackRulesCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell Group Stack Rules...");
        sSpellMgr->LoadSpellGroupStackRules();
        handler->SendGlobalGMSysMessage("DB table `spell_group_stack_rules` (spell stacking definitions) reloaded.");
        return true;
    }

    static bool HandleReloadSpellPetAurasCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Spell pet auras...");
        sSpellMgr->LoadSpellPetAuras();
        handler->SendGlobalGMSysMessage("DB table `spell_pet_auras` reloaded.");
        return true;
    }

    static bool HandleReloadPageTextsCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Page Text...");
        sObjectMgr->LoadPageTexts();
        handler->SendGlobalGMSysMessage("DB table `page_text` reloaded.");
        return true;
    }

    static bool HandleReloadItemRandomBonusListTemplatesCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Random item bonus list definitions...");
        LoadItemRandomBonusListTemplates();
        handler->SendGlobalGMSysMessage("DB table `item_random_bonus_list_template` reloaded.");
        return true;
    }

    static bool HandleReloadEventScriptsCommand(ChatHandler* handler, char const* args)
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

    static bool HandleReloadWpCommand(ChatHandler* handler, char const* args)
    {
        if (*args != 'a')
            TC_LOG_INFO("misc", "Re-Loading Waypoints data from 'waypoint_path' and 'waypoint_path_node'");

        sWaypointMgr->LoadPaths();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("DB Tables 'waypoint_path' and 'waypoint_path_node' reloaded.");

        return true;
    }

    static bool HandleReloadSpellScriptsCommand(ChatHandler* handler, char const* args)
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

    static bool HandleReloadSpellScriptNamesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading spell_script_names table...");
        sObjectMgr->LoadSpellScriptNames();
        sScriptMgr->NotifyScriptIDUpdate();
        sObjectMgr->ValidateSpellScripts();
        handler->SendGlobalGMSysMessage("Spell scripts reloaded.");
        return true;
    }

    static bool HandleReloadGameGraveyardZoneCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Graveyard-zone links...");

        sObjectMgr->LoadGraveyardZones();

        handler->SendGlobalGMSysMessage("DB table `graveyard_zone` reloaded.");

        return true;
    }

    static bool HandleReloadGameTeleCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Game Tele coordinates...");

        sObjectMgr->LoadGameTele();

        handler->SendGlobalGMSysMessage("DB table `game_tele` reloaded.");

        return true;
    }

    static bool HandleReloadDisablesCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading disables table...");
        DisableMgr::LoadDisables();
        TC_LOG_INFO("misc", "Checking quest disables...");
        DisableMgr::CheckQuestDisables();
        handler->SendGlobalGMSysMessage("DB table `disables` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesAchievementRewardCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Achievement Reward Data Locale...");
        sAchievementMgr->LoadRewardLocales();
        handler->SendGlobalGMSysMessage("DB table `achievement_reward_locale` reloaded.");
        return true;
    }

    static bool HandleReloadLfgRewardsCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading lfg dungeon rewards...");
        sLFGMgr->LoadRewards();
        handler->SendGlobalGMSysMessage("DB table `lfg_dungeon_rewards` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesCreatureCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Creature Template Locale...");
        sObjectMgr->LoadCreatureLocales();
        handler->SendGlobalGMSysMessage("DB table `creature_template_locale` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesCreatureTextCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Creature Texts Locale...");
        sCreatureTextMgr->LoadCreatureTextLocales();
        handler->SendGlobalGMSysMessage("DB table `creature_text_locale` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesGameobjectCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Gameobject Template Locale... ");
        sObjectMgr->LoadGameObjectLocales();
        handler->SendGlobalGMSysMessage("DB table `gameobject_template_locale` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesGossipMenuOptionCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Gossip Menu Option Locale... ");
        sObjectMgr->LoadGossipMenuItemsLocales();
        handler->SendGlobalGMSysMessage("DB table `gossip_menu_option_locale` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesPageTextCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Page Text Locale... ");
        sObjectMgr->LoadPageTextLocales();
        handler->SendGlobalGMSysMessage("DB table `page_text_locale` reloaded.");
        return true;
    }

    static bool HandleReloadLocalesPointsOfInterestCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Points Of Interest Locale... ");
        sObjectMgr->LoadPointOfInterestLocales();
        handler->SendGlobalGMSysMessage("DB table `points_of_interest_locale` reloaded.");
        return true;
    }

    static bool HandleReloadQuestLocaleCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Quest Locale ... ");
        sObjectMgr->LoadQuestTemplateLocale();
        sObjectMgr->LoadQuestObjectivesLocale();
        sObjectMgr->LoadQuestGreetingLocales();
        sObjectMgr->LoadQuestOfferRewardLocale();
        sObjectMgr->LoadQuestRequestItemsLocale();
        handler->SendGlobalGMSysMessage("DB table `quest_template_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_objectives_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_greeting_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_offer_reward_locale` reloaded.");
        handler->SendGlobalGMSysMessage("DB table `quest_request_items_locale` reloaded.");
        return true;
    }

    static bool HandleReloadMailLevelRewardCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Player level dependent mail rewards...");
        sObjectMgr->LoadMailLevelRewards();
        handler->SendGlobalGMSysMessage("DB table `mail_level_reward` reloaded.");
        return true;
    }

    static bool HandleReloadAuctionsCommand(ChatHandler* handler, char const* /*args*/)
    {
        ///- Reload dynamic data tables from the database
        TC_LOG_INFO("misc", "Re-Loading Auctions...");
        sAuctionMgr->LoadAuctions();
        handler->SendGlobalGMSysMessage("Auctions reloaded.");
        return true;
    }

    static bool HandleReloadConditions(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Conditions...");
        sConditionMgr->LoadConditions(true);
        sScriptMgr->NotifyScriptIDUpdate();
        handler->SendGlobalGMSysMessage("Conditions reloaded.");
        return true;
    }

    static bool HandleReloadCreatureText(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Creature Texts...");
        sCreatureTextMgr->LoadCreatureTexts();
        handler->SendGlobalGMSysMessage("Creature Texts reloaded.");
        return true;
    }

    static bool HandleReloadSmartScripts(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading Smart Scripts...");
        sSmartScriptMgr->LoadSmartAIFromDB();
        handler->SendGlobalGMSysMessage("Smart Scripts reloaded.");
        return true;
    }

    static bool HandleReloadVehicleTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading vehicle_template table...");
        sObjectMgr->LoadVehicleTemplate();
        handler->SendGlobalGMSysMessage("Vehicle templates reloaded.");
        return true;
    }

    static bool HandleReloadVehicleAccessoryCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading vehicle_accessory table...");
        sObjectMgr->LoadVehicleAccessories();
        handler->SendGlobalGMSysMessage("Vehicle accessories reloaded.");
        return true;
    }

    static bool HandleReloadVehicleTemplateAccessoryCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading vehicle_template_accessory table...");
        sObjectMgr->LoadVehicleTemplateAccessories();
        handler->SendGlobalGMSysMessage("Vehicle template accessories reloaded.");
        return true;
    }

    static bool HandleReloadAreaTriggerTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading areatrigger_template table...");
        sAreaTriggerDataStore->LoadAreaTriggerTemplates();
        sScriptMgr->NotifyScriptIDUpdate();
        handler->SendGlobalGMSysMessage("AreaTrigger templates reloaded.");
        return true;
    }

    static bool HandleReloadSceneTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading scene_template table...");
        sObjectMgr->LoadSceneTemplates();
        sScriptMgr->NotifyScriptIDUpdate();
        handler->SendGlobalGMSysMessage("Scenes templates reloaded.");
        return true;
    }

    static bool HandleReloadConversationTemplateCommand(ChatHandler* handler, char const* /*args*/)
    {
        TC_LOG_INFO("misc", "Reloading conversation_* tables...");
        sConversationDataStore->LoadConversationTemplates();
        sScriptMgr->NotifyScriptIDUpdate();
        handler->SendGlobalGMSysMessage("Conversation templates reloaded.");
        return true;
    }

    static bool HandleReloadRBACCommand(ChatHandler* handler, char const* /*args*/)
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
