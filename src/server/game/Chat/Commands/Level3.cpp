/*
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
*
* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "AuctionHouseMgr.h"
#include "AccountMgr.h"
#include "PlayerDump.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Opcodes.h"
#include "GameObject.h"
#include "Chat.h"
#include "Log.h"
#include "Guild.h"
#include "ObjectAccessor.h"
#include "MapManager.h"
#include "Language.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "Weather.h"
#include "PointMovementGenerator.h"
#include "TargetedMovementGenerator.h"
#include "SkillDiscovery.h"
#include "SkillExtraItems.h"
#include "SystemConfig.h"
#include "Config.h"
#include "Util.h"
#include "ItemEnchantmentMgr.h"
#include "BattleGroundMgr.h"
#include "InstanceSaveMgr.h"
#include "InstanceData.h"
#include "CreatureEventAIMgr.h"
#include "SpellAuraEffects.h"
#include "DBCEnums.h"
#include "ConditionMgr.h"
#include "DisableMgr.h"
#include "Transport.h"

//reload commands
bool ChatHandler::HandleReloadAllCommand(const char*)
{
    HandleReloadSkillFishingBaseLevelCommand("");

    HandleReloadAllAchievementCommand("");
    HandleReloadAllAreaCommand("");
    HandleReloadAllEventAICommand("");
    HandleReloadAllLootCommand("");
    HandleReloadAllNpcCommand("");
    HandleReloadAllQuestCommand("");
    HandleReloadAllSpellCommand("");
    HandleReloadAllItemCommand("");
    HandleReloadAllLocalesCommand("");

    HandleReloadAccessRequirementCommand("");
    HandleReloadMailLevelRewardCommand("");
    HandleReloadCommandCommand("");
    HandleReloadReservedNameCommand("");
    HandleReloadTrinityStringCommand("");
    HandleReloadGameTeleCommand("");

    HandleReloadAutobroadcastCommand("");
    return true;
}

bool ChatHandler::HandleReloadAllAchievementCommand(const char*)
{
    HandleReloadAchievementCriteriaDataCommand("");
    HandleReloadAchievementRewardCommand("");
    return true;
}

bool ChatHandler::HandleReloadAllAreaCommand(const char*)
{
    //HandleReloadQuestAreaTriggersCommand(""); -- reloaded in HandleReloadAllQuestCommand
    HandleReloadAreaTriggerTeleportCommand("");
    HandleReloadAreaTriggerTavernCommand("");
    HandleReloadGameGraveyardZoneCommand("");
    return true;
}

bool ChatHandler::HandleReloadAllLootCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables...");
    LoadLootTables();
    SendGlobalGMSysMessage("DB tables `*_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadAllNpcCommand(const char* /*args*/)
{
    HandleReloadNpcGossipCommand("a");
    HandleReloadNpcTrainerCommand("a");
    HandleReloadNpcVendorCommand("a");
    HandleReloadPointsOfInterestCommand("a");
    HandleReloadSpellClickSpellsCommand("a");
    return true;
}

bool ChatHandler::HandleReloadAllQuestCommand(const char* /*args*/)
{
    HandleReloadQuestAreaTriggersCommand("a");
    HandleReloadQuestTemplateCommand("a");

    sLog.outString("Re-Loading Quests Relations...");
    objmgr.LoadQuestRelations();
    SendGlobalGMSysMessage("DB tables `*_questrelation` and `*_involvedrelation` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAllScriptsCommand(const char*)
{
    if (sWorld.IsScriptScheduled())
    {
        PSendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    sLog.outString("Re-Loading Scripts...");
    HandleReloadGameObjectScriptsCommand("a");
    HandleReloadEventScriptsCommand("a");
    HandleReloadQuestEndScriptsCommand("a");
    HandleReloadQuestStartScriptsCommand("a");
    HandleReloadSpellScriptsCommand("a");
    SendGlobalGMSysMessage("DB tables `*_scripts` reloaded.");
    HandleReloadDbScriptStringCommand("a");
    HandleReloadWpScriptsCommand("a");
    return true;
}

bool ChatHandler::HandleReloadAllEventAICommand(const char*)
{
    HandleReloadEventAITextsCommand("a");
    HandleReloadEventAISummonsCommand("a");
    HandleReloadEventAIScriptsCommand("a");
    return true;
}

bool ChatHandler::HandleReloadAllSpellCommand(const char*)
{
    HandleReloadSkillDiscoveryTemplateCommand("a");
    HandleReloadSkillExtraItemTemplateCommand("a");
    HandleReloadSpellRequiredCommand("a");
    HandleReloadSpellAreaCommand("a");
    HandleReloadSpellGroupsCommand("a");
    HandleReloadSpellLearnSpellCommand("a");
    HandleReloadSpellLinkedSpellCommand("a");
    HandleReloadSpellProcEventCommand("a");
    HandleReloadSpellBonusesCommand("a");
    HandleReloadSpellTargetPositionCommand("a");
    HandleReloadSpellThreatsCommand("a");
    HandleReloadSpellGroupStackRulesCommand("a");
    HandleReloadSpellPetAurasCommand("a");
    return true;
}

bool ChatHandler::HandleReloadAllItemCommand(const char*)
{
    HandleReloadPageTextsCommand("a");
    HandleReloadItemEnchantementsCommand("a");
    return true;
}

bool ChatHandler::HandleReloadAllLocalesCommand(const char* /*args*/)
{
    HandleReloadLocalesAchievementRewardCommand("a");
    HandleReloadLocalesCreatureCommand("a");
    HandleReloadLocalesGameobjectCommand("a");
    HandleReloadLocalesItemCommand("a");
    HandleReloadLocalesNpcTextCommand("a");
    HandleReloadLocalesPageTextCommand("a");
    HandleReloadLocalesPointsOfInterestCommand("a");
    HandleReloadLocalesQuestCommand("a");
    return true;
}

bool ChatHandler::HandleReloadConfigCommand(const char* /*args*/)
{
    sLog.outString("Re-Loading config settings...");
    sWorld.LoadConfigSettings(true);
    sMapMgr.InitializeVisibilityDistanceInfo();
    SendGlobalGMSysMessage("World config settings reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAccessRequirementCommand(const char*)
{
    sLog.outString("Re-Loading Access Requirement definitions...");
    objmgr.LoadAccessRequirements();
    SendGlobalGMSysMessage("DB table `access_requirement` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAchievementCriteriaDataCommand(const char*)
{
    sLog.outString("Re-Loading Additional Achievement Criteria Data...");
    achievementmgr.LoadAchievementCriteriaData();
    SendGlobalGMSysMessage("DB table `achievement_criteria_data` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAchievementRewardCommand(const char*)
{
    sLog.outString("Re-Loading Achievement Reward Data...");
    achievementmgr.LoadRewards();
    SendGlobalGMSysMessage("DB table `achievement_reward` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAreaTriggerTavernCommand(const char*)
{
    sLog.outString("Re-Loading Tavern Area Triggers...");
    objmgr.LoadTavernAreaTriggers();
    SendGlobalGMSysMessage("DB table `areatrigger_tavern` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAreaTriggerTeleportCommand(const char*)
{
    sLog.outString("Re-Loading AreaTrigger teleport definitions...");
    objmgr.LoadAreaTriggerTeleports();
    SendGlobalGMSysMessage("DB table `areatrigger_teleport` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAutobroadcastCommand(const char*)
{
    sLog.outString("Re-Loading Autobroadcast...");
    sWorld.LoadAutobroadcasts();
    SendGlobalGMSysMessage("DB table `autobroadcast` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCommandCommand(const char*)
{
    load_command_table = true;
    SendGlobalGMSysMessage("DB table `command` will be reloaded at next chat command use.");
    return true;
}

bool ChatHandler::HandleReloadOnKillReputationCommand(const char*)
{
    sLog.outString("Re-Loading creature award reputation definitions...");
    objmgr.LoadReputationOnKill();
    SendGlobalGMSysMessage("DB table `creature_onkill_reputation` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureTemplateCommand(const char* args)
{
    if (!*args)
        return false;
    
    uint32 entry = (uint32) atoi((char*)args);
    QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT difficulty_entry_1,difficulty_entry_2,difficulty_entry_3,KillCredit1,KillCredit2,modelid1,modelid2,modelid3,modelid4,name,subname,IconName,gossip_menu_id,minlevel,maxlevel,exp,faction_A,faction_H,npcflag,speed_walk,speed_run,scale,rank,mindmg,maxdmg,dmgschool,attackpower,dmg_multiplier,baseattacktime,rangeattacktime,unit_class,unit_flags,dynamicflags,family,trainer_type,trainer_spell,trainer_class,trainer_race,minrangedmg,maxrangedmg,rangedattackpower,type,type_flags,lootid,pickpocketloot,skinloot,resistance1,resistance2,resistance3,resistance4,resistance5,resistance6,spell1,spell2,spell3,spell4,spell5,spell6,spell7,spell8,PetSpellDataId,VehicleId,mingold,maxgold,AIName,MovementType,InhabitType,Health_mod,Mana_mod,Armor_mod,RacialLeader,questItem1,questItem2,questItem3,questItem4,questItem5,questItem6,movementId,RegenHealth,equipment_id,mechanic_immune_mask,flags_extra,ScriptName FROM creature_template WHERE entry = %u", entry);
    if (!result)
    {
        PSendSysMessage(LANG_COMMAND_CREATURETEMPLATE_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }
    
    CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(entry);
    if (!cInfo)
    {
        PSendSysMessage(LANG_COMMAND_CREATURESTORAGE_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }

    sLog.outString("Reloading creature template entry %u", entry);

    Field *fields = result->Fetch();

    const_cast<CreatureInfo*>(cInfo)->DifficultyEntry[0] = fields[0].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->DifficultyEntry[1] = fields[1].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->DifficultyEntry[2] = fields[2].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->KillCredit[0] = fields[3].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->KillCredit[1] = fields[4].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->Modelid1 = fields[5].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->Modelid2 = fields[6].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->Modelid3 = fields[7].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->Modelid4 = fields[8].GetUInt32();
    size_t len = 0;
    if (const char* temp = fields[9].GetString())
    {
        delete[] cInfo->Name;
        len = strlen(temp)+1;
        const_cast<CreatureInfo*>(cInfo)->Name = new char[len];
        strncpy(cInfo->Name, temp, len);
    }
    if (const char* temp = fields[10].GetString())
    {
        delete[] cInfo->SubName;
        len = strlen(temp)+1;
        const_cast<CreatureInfo*>(cInfo)->SubName = new char[len];
        strncpy(cInfo->SubName, temp, len);
    }
    if (const char* temp = fields[11].GetString())
    {
        delete[] cInfo->IconName;
        len = strlen(temp)+1;
        const_cast<CreatureInfo*>(cInfo)->IconName = new char[len];
        strncpy(cInfo->IconName, temp, len);
    }
    const_cast<CreatureInfo*>(cInfo)->GossipMenuId = fields[12].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->minlevel = fields[13].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->maxlevel = fields[14].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->expansion = fields[15].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->faction_A = fields[16].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->faction_H = fields[17].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->npcflag = fields[18].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->speed_walk = fields[19].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->speed_run = fields[20].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->scale = fields[21].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->rank = fields[22].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->mindmg = fields[23].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->maxdmg = fields[24].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->dmgschool = fields[25].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->attackpower = fields[26].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->dmg_multiplier = fields[27].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->baseattacktime = fields[28].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->rangeattacktime = fields[29].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->unit_class = fields[30].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->unit_flags = fields[31].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->dynamicflags = fields[32].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->family = fields[33].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->trainer_type = fields[34].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->trainer_spell = fields[35].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->trainer_class = fields[36].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->trainer_race = fields[37].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->minrangedmg = fields[38].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->maxrangedmg = fields[39].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->rangedattackpower = fields[40].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->type = fields[41].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->type_flags = fields[42].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->lootid = fields[43].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->pickpocketLootId = fields[44].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->SkinLootId = fields[45].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->resistance1 = fields[46].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->resistance2 = fields[47].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->resistance3 = fields[48].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->resistance4 = fields[49].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->resistance5 = fields[50].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->resistance6 = fields[51].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[0] = fields[52].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[1] = fields[53].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[2] = fields[54].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[3] = fields[55].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[4] = fields[56].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[5] = fields[57].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[6] = fields[58].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->spells[7] = fields[59].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->PetSpellDataId = fields[60].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->VehicleId = fields[61].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->mingold = fields[62].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->maxgold = fields[63].GetUInt32();
    if (const char* temp = fields[64].GetString())
    {
        delete[] cInfo->AIName;
        len = strlen(temp)+1;
        const_cast<CreatureInfo*>(cInfo)->AIName = new char[len];
        strncpy(const_cast<char*>(cInfo->AIName), temp, len);
    }
    const_cast<CreatureInfo*>(cInfo)->MovementType = fields[65].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->InhabitType = fields[66].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->ModHealth = fields[67].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->ModMana = fields[68].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->ModArmor = fields[69].GetFloat();
    const_cast<CreatureInfo*>(cInfo)->RacialLeader = fields[70].GetBool();
    const_cast<CreatureInfo*>(cInfo)->questItems[0] = fields[71].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->questItems[1] = fields[72].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->questItems[2] = fields[73].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->questItems[3] = fields[74].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->questItems[4] = fields[75].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->questItems[5] = fields[76].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->movementId = fields[77].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->RegenHealth = fields[78].GetBool();
    const_cast<CreatureInfo*>(cInfo)->equipmentId = fields[79].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->MechanicImmuneMask = fields[80].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->flags_extra = fields[81].GetUInt32();
    const_cast<CreatureInfo*>(cInfo)->ScriptID = objmgr.GetScriptId(fields[82].GetString());

    objmgr.CheckCreatureTemplate(cInfo);

    SendGlobalGMSysMessage("Creature template reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureQuestRelationsCommand(const char*)
{
    sLog.outString("Loading Quests Relations... (`creature_questrelation`)");
    objmgr.LoadCreatureQuestRelations();
    SendGlobalGMSysMessage("DB table `creature_questrelation` (creature quest givers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureLinkedRespawnCommand(const char * /*args*/)
{
    sLog.outString("Loading Linked Respawns... (`creature_linked_respawn`)");
    objmgr.LoadCreatureLinkedRespawn();
    SendGlobalGMSysMessage("DB table `creature_linked_respawn` (creature linked respawns) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadCreatureQuestInvRelationsCommand(const char*)
{
    sLog.outString("Loading Quests Relations... (`creature_involvedrelation`)");
    objmgr.LoadCreatureInvolvedRelations();
    SendGlobalGMSysMessage("DB table `creature_involvedrelation` (creature quest takers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGossipMenuCommand(const char*)
{
    sLog.outString("Re-Loading `gossip_menu` Table!");
    objmgr.LoadGossipMenu();
    SendGlobalGMSysMessage("DB table `gossip_menu` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadGossipMenuOptionCommand(const char*)
{
    sLog.outString("Re-Loading `gossip_menu_option` Table!");
    objmgr.LoadGossipMenuItems();
    SendGlobalGMSysMessage("DB table `gossip_menu_option` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadGOQuestRelationsCommand(const char*)
{
    sLog.outString("Loading Quests Relations... (`gameobject_questrelation`)");
    objmgr.LoadGameobjectQuestRelations();
    SendGlobalGMSysMessage("DB table `gameobject_questrelation` (gameobject quest givers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGOQuestInvRelationsCommand(const char*)
{
    sLog.outString("Loading Quests Relations... (`gameobject_involvedrelation`)");
    objmgr.LoadGameobjectInvolvedRelations();
    SendGlobalGMSysMessage("DB table `gameobject_involvedrelation` (gameobject quest takers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestAreaTriggersCommand(const char*)
{
    sLog.outString("Re-Loading Quest Area Triggers...");
    objmgr.LoadQuestAreaTriggers();
    SendGlobalGMSysMessage("DB table `areatrigger_involvedrelation` (quest area triggers) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestTemplateCommand(const char*)
{
    sLog.outString("Re-Loading Quest Templates...");
    objmgr.LoadQuests();
    SendGlobalGMSysMessage("DB table `quest_template` (quest definitions) reloaded.");

    /// dependent also from `gameobject` but this table not reloaded anyway
    sLog.outString("Re-Loading GameObjects for quests...");
    objmgr.LoadGameObjectForQuests();
    SendGlobalGMSysMessage("Data GameObjects for quests reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesCreatureCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`creature_loot_template`)");
    LoadLootTemplates_Creature();
    LootTemplates_Creature.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `creature_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesDisenchantCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`disenchant_loot_template`)");
    LoadLootTemplates_Disenchant();
    LootTemplates_Disenchant.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `disenchant_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesFishingCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`fishing_loot_template`)");
    LoadLootTemplates_Fishing();
    LootTemplates_Fishing.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `fishing_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesGameobjectCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`gameobject_loot_template`)");
    LoadLootTemplates_Gameobject();
    LootTemplates_Gameobject.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `gameobject_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesItemCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`item_loot_template`)");
    LoadLootTemplates_Item();
    LootTemplates_Item.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `item_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesMillingCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`milling_loot_template`)");
    LoadLootTemplates_Milling();
    LootTemplates_Milling.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `milling_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesPickpocketingCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`pickpocketing_loot_template`)");
    LoadLootTemplates_Pickpocketing();
    LootTemplates_Pickpocketing.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `pickpocketing_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesProspectingCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`prospecting_loot_template`)");
    LoadLootTemplates_Prospecting();
    LootTemplates_Prospecting.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `prospecting_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesMailCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`mail_loot_template`)");
    LoadLootTemplates_Mail();
    LootTemplates_Mail.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `mail_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesReferenceCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`reference_loot_template`)");
    LoadLootTemplates_Reference();
    SendGlobalGMSysMessage("DB table `reference_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesSkinningCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`skinning_loot_template`)");
    LoadLootTemplates_Skinning();
    LootTemplates_Skinning.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `skinning_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadLootTemplatesSpellCommand(const char*)
{
    sLog.outString("Re-Loading Loot Tables... (`spell_loot_template`)");
    LoadLootTemplates_Spell();
    LootTemplates_Spell.CheckLootRefs();
    SendGlobalGMSysMessage("DB table `spell_loot_template` reloaded.");
    sConditionMgr.LoadConditions(true);
    return true;
}

bool ChatHandler::HandleReloadTrinityStringCommand(const char*)
{
    sLog.outString("Re-Loading trinity_string Table!");
    objmgr.LoadTrinityStrings();
    SendGlobalGMSysMessage("DB table `trinity_string` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcGossipCommand(const char*)
{
    sLog.outString("Re-Loading `npc_gossip` Table!");
    objmgr.LoadNpcTextId();
    SendGlobalGMSysMessage("DB table `npc_gossip` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcTrainerCommand(const char*)
{
    sLog.outString("Re-Loading `npc_trainer` Table!");
    objmgr.LoadTrainerSpell();
    SendGlobalGMSysMessage("DB table `npc_trainer` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadNpcVendorCommand(const char*)
{
    sLog.outString("Re-Loading `npc_vendor` Table!");
    objmgr.LoadVendors();
    SendGlobalGMSysMessage("DB table `npc_vendor` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadPointsOfInterestCommand(const char*)
{
    sLog.outString("Re-Loading `points_of_interest` Table!");
    objmgr.LoadPointsOfInterest();
    SendGlobalGMSysMessage("DB table `points_of_interest` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellClickSpellsCommand(const char*)
{
    sLog.outString("Re-Loading `npc_spellclick_spells` Table!");
    objmgr.LoadNPCSpellClickSpells();
    SendGlobalGMSysMessage("DB table `npc_spellclick_spells` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadReservedNameCommand(const char*)
{
    sLog.outString("Loading ReservedNames... (`reserved_name`)");
    objmgr.LoadReservedPlayersNames();
    SendGlobalGMSysMessage("DB table `reserved_name` (player reserved names) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadReputationRewardRateCommand(const char*)
{
    sLog.outString( "Re-Loading `reputation_reward_rate` Table!" );
    objmgr.LoadReputationRewardRate();
    SendGlobalSysMessage("DB table `reputation_reward_rate` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadReputationSpilloverTemplateCommand(const char*)
{
    sLog.outString( "Re-Loading `reputation_spillover_template` Table!" );
    objmgr.LoadReputationSpilloverTemplate();
    SendGlobalSysMessage("DB table `reputation_spillover_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSkillDiscoveryTemplateCommand(const char* /*args*/)
{
    sLog.outString("Re-Loading Skill Discovery Table...");
    LoadSkillDiscoveryTable();
    SendGlobalGMSysMessage("DB table `skill_discovery_template` (recipes discovered at crafting) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSkillExtraItemTemplateCommand(const char* /*args*/)
{
    sLog.outString("Re-Loading Skill Extra Item Table...");
    LoadSkillExtraItemTable();
    SendGlobalGMSysMessage("DB table `skill_extra_item_template` (extra item creation when crafting) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSkillFishingBaseLevelCommand(const char* /*args*/)
{
    sLog.outString("Re-Loading Skill Fishing base level requirements...");
    objmgr.LoadFishingBaseSkillLevel();
    SendGlobalGMSysMessage("DB table `skill_fishing_base_level` (fishing base level for zone/subzone) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellAreaCommand(const char*)
{
    sLog.outString("Re-Loading SpellArea Data...");
    spellmgr.LoadSpellAreas();
    SendGlobalGMSysMessage("DB table `spell_area` (spell dependences from area/quest/auras state) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellRequiredCommand(const char*)
{
    sLog.outString("Re-Loading Spell Required Data... ");
    spellmgr.LoadSpellRequired();
    SendGlobalGMSysMessage("DB table `spell_required` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellGroupsCommand(const char*)
{
    sLog.outString("Re-Loading Spell Groups...");
    spellmgr.LoadSpellGroups();
    SendGlobalGMSysMessage("DB table `spell_group` (spell groups) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellLearnSpellCommand(const char*)
{
    sLog.outString("Re-Loading Spell Learn Spells...");
    spellmgr.LoadSpellLearnSpells();
    SendGlobalGMSysMessage("DB table `spell_learn_spell` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellLinkedSpellCommand(const char*)
{
    sLog.outString("Re-Loading Spell Linked Spells...");
    spellmgr.LoadSpellLinked();
    SendGlobalGMSysMessage("DB table `spell_linked_spell` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellProcEventCommand(const char*)
{
    sLog.outString("Re-Loading Spell Proc Event conditions...");
    spellmgr.LoadSpellProcEvents();
    SendGlobalGMSysMessage("DB table `spell_proc_event` (spell proc trigger requirements) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellBonusesCommand(const char*)
{
    sLog.outString("Re-Loading Spell Bonus Data...");
    spellmgr.LoadSpellBonusess();
    SendGlobalGMSysMessage("DB table `spell_bonus_data` (spell damage/healing coefficients) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellTargetPositionCommand(const char*)
{
    sLog.outString("Re-Loading Spell target coordinates...");
    spellmgr.LoadSpellTargetPositions();
    SendGlobalGMSysMessage("DB table `spell_target_position` (destination coordinates for spell targets) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellThreatsCommand(const char*)
{
    sLog.outString("Re-Loading Aggro Spells Definitions...");
    spellmgr.LoadSpellThreats();
    SendGlobalGMSysMessage("DB table `spell_threat` (spell aggro definitions) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellGroupStackRulesCommand(const char*)
{
    sLog.outString("Re-Loading Spell Group Stack Rules...");
    spellmgr.LoadSpellGroupStackRules();
    SendGlobalGMSysMessage("DB table `spell_group_stack_rules` (spell stacking definitions) reloaded.");
    return true;
}

bool ChatHandler::HandleReloadSpellPetAurasCommand(const char*)
{
    sLog.outString("Re-Loading Spell pet auras...");
    spellmgr.LoadSpellPetAuras();
    SendGlobalGMSysMessage("DB table `spell_pet_auras` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadPageTextsCommand(const char*)
{
    sLog.outString("Re-Loading Page Texts...");
    objmgr.LoadPageTexts();
    SendGlobalGMSysMessage("DB table `page_texts` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadItemEnchantementsCommand(const char*)
{
    sLog.outString("Re-Loading Item Random Enchantments Table...");
    LoadRandomEnchantmentsTable();
    SendGlobalGMSysMessage("DB table `item_enchantment_template` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadItemSetNamesCommand(const char*)
{
    sLog.outString("Re-Loading Item set names...");
    LoadRandomEnchantmentsTable();
    SendGlobalGMSysMessage("DB table `item_set_names` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGameObjectScriptsCommand(const char* arg)
{
    if (sWorld.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*arg != 'a')
        sLog.outString("Re-Loading Scripts from `gameobject_scripts`...");

    objmgr.LoadGameObjectScripts();

    if (*arg != 'a')
        SendGlobalGMSysMessage("DB table `gameobject_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadEventScriptsCommand(const char* arg)
{
    if (sWorld.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*arg != 'a')
        sLog.outString("Re-Loading Scripts from `event_scripts`...");

    objmgr.LoadEventScripts();

    if (*arg != 'a')
        SendGlobalGMSysMessage("DB table `event_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadWpScriptsCommand(const char* arg)
{
    if (sWorld.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*arg != 'a')
        sLog.outString("Re-Loading Scripts from `waypoint_scripts`...");

    objmgr.LoadWaypointScripts();

    if (*arg != 'a')
        SendGlobalGMSysMessage("DB table `waypoint_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadEventAITextsCommand(const char* /*args*/)
{

    sLog.outString("Re-Loading Texts from `creature_ai_texts`...");
    CreatureEAI_Mgr.LoadCreatureEventAI_Texts();
    SendGlobalGMSysMessage("DB table `creature_ai_texts` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadEventAISummonsCommand(const char* /*args*/)
{
    sLog.outString("Re-Loading Summons from `creature_ai_summons`...");
    CreatureEAI_Mgr.LoadCreatureEventAI_Summons();
    SendGlobalGMSysMessage("DB table `creature_ai_summons` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadEventAIScriptsCommand(const char* /*args*/)
{
    sLog.outString("Re-Loading Scripts from `creature_ai_scripts`...");
    CreatureEAI_Mgr.LoadCreatureEventAI_Scripts();
    SendGlobalGMSysMessage("DB table `creature_ai_scripts` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadQuestEndScriptsCommand(const char* arg)
{
    if (sWorld.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*arg != 'a')
        sLog.outString("Re-Loading Scripts from `quest_end_scripts`...");

    objmgr.LoadQuestEndScripts();

    if (*arg != 'a')
        SendGlobalGMSysMessage("DB table `quest_end_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadQuestStartScriptsCommand(const char* arg)
{
    if (sWorld.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*arg != 'a')
        sLog.outString("Re-Loading Scripts from `quest_start_scripts`...");

    objmgr.LoadQuestStartScripts();

    if (*arg != 'a')
        SendGlobalGMSysMessage("DB table `quest_start_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadSpellScriptsCommand(const char* arg)
{
    if (sWorld.IsScriptScheduled())
    {
        SendSysMessage("DB scripts used currently, please attempt reload later.");
        SetSentErrorMessage(true);
        return false;
    }

    if (*arg != 'a')
        sLog.outString("Re-Loading Scripts from `spell_scripts`...");

    objmgr.LoadSpellScripts();

    if (*arg != 'a')
        SendGlobalGMSysMessage("DB table `spell_scripts` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadDbScriptStringCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Script strings from `db_script_string`...");
    objmgr.LoadDbScriptStrings();
    SendGlobalGMSysMessage("DB table `db_script_string` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadGameGraveyardZoneCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Graveyard-zone links...");

    objmgr.LoadGraveyardZones();

    SendGlobalGMSysMessage("DB table `game_graveyard_zone` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadGameTeleCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Game Tele coordinates...");

    objmgr.LoadGameTele();

    SendGlobalGMSysMessage("DB table `game_tele` reloaded.");

    return true;
}

bool ChatHandler::HandleReloadDisablesCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading disables table...");
    sDisableMgr.LoadDisables();
    sLog.outString("Checking quest disables...");
    sDisableMgr.CheckQuestDisables();
    SendGlobalGMSysMessage("DB table `disables` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesAchievementRewardCommand(const char*)
{
    sLog.outString("Re-Loading Locales Achievement Reward Data...");
    achievementmgr.LoadRewardLocales();
    SendGlobalGMSysMessage("DB table `locales_achievement_reward` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesCreatureCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Creature ...");
    objmgr.LoadCreatureLocales();
    SendGlobalGMSysMessage("DB table `locales_creature` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesGameobjectCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Gameobject ... ");
    objmgr.LoadGameObjectLocales();
    SendGlobalGMSysMessage("DB table `locales_gameobject` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesItemCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Item ... ");
    objmgr.LoadItemLocales();
    SendGlobalGMSysMessage("DB table `locales_item` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesItemSetNameCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Item set name... ");
    objmgr.LoadItemSetNameLocales();
    SendGlobalGMSysMessage("DB table `locales_item_set_name` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesNpcTextCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales NPC Text ... ");
    objmgr.LoadNpcTextLocales();
    SendGlobalGMSysMessage("DB table `locales_npc_text` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesPageTextCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Page Text ... ");
    objmgr.LoadPageTextLocales();
    SendGlobalGMSysMessage("DB table `locales_page_text` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesPointsOfInterestCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Points Of Interest ... ");
    objmgr.LoadPointOfInterestLocales();
    SendGlobalGMSysMessage("DB table `locales_points_of_interest` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadLocalesQuestCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Locales Quest ... ");
    objmgr.LoadQuestLocales();
    SendGlobalGMSysMessage("DB table `locales_quest` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadMailLevelRewardCommand(const char* /*arg*/)
{
    sLog.outString("Re-Loading Player level dependent mail rewards...");
    objmgr.LoadMailLevelRewards();
    SendGlobalGMSysMessage("DB table `mail_level_reward` reloaded.");
    return true;
}

bool ChatHandler::HandleReloadAuctionsCommand(const char * /*args*/)
{
    ///- Reload dynamic data tables from the database
    sLog.outString("Re-Loading Auctions...");
    auctionmgr.LoadAuctionItems();
    auctionmgr.LoadAuctions();
    SendGlobalGMSysMessage("Auctions reloaded.");
    return true;
}

bool ChatHandler::HandleReloadConditions(const char* args)
{
    sLog.outString("Re-Loading Conditions...");
    sConditionMgr.LoadConditions(true);
    SendGlobalGMSysMessage("Conditions reloaded.");
    return true;
}

bool ChatHandler::HandleAccountSetGmLevelCommand(const char *args)
{
    if (!*args)
        return false;

    std::string targetAccountName;
    uint32 targetAccountId = 0;
    uint32 targetSecurity = 0;
    uint32 gm = 0;
    char* arg1 = strtok((char*)args, " ");
    char* arg2 = strtok(NULL, " ");
    char* arg3 = strtok(NULL, " ");
    bool isAccountNameGiven = true;

    if (arg1 && !arg3)
    {
        if (!getSelectedPlayer())
            return false;
        isAccountNameGiven = false;
    }

    // Check for second parameter
    if (!isAccountNameGiven && !arg2)
        return false;

    // Check for account
    if (isAccountNameGiven)
    {
        targetAccountName = arg1;
        if (!AccountMgr::normalizeString(targetAccountName))
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,targetAccountName.c_str());
            SetSentErrorMessage(true);
            return false;
        }
    }

    // Check for invalid specified GM level.
    gm = (isAccountNameGiven) ? atoi(arg2) : atoi(arg1);
    if (gm < SEC_PLAYER)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    // m_session == NULL only for console
    targetAccountId = (isAccountNameGiven) ? accmgr.GetId(targetAccountName) : getSelectedPlayer()->GetSession()->GetAccountId();
    int32 gmRealmID = (isAccountNameGiven) ? atoi(arg3) : atoi(arg2);
    uint32 plSecurity = m_session ? accmgr.GetSecurity(m_session->GetAccountId(), gmRealmID) : SEC_CONSOLE;

    // can set security level only for target with less security and to less security that we have
    // This is also reject self apply in fact
    targetSecurity = accmgr.GetSecurity(targetAccountId, gmRealmID);
    if (targetSecurity >= plSecurity || gm >= plSecurity)
    {
        SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
        SetSentErrorMessage(true);
        return false;
    }

    // Check and abort if the target gm has a higher rank on one of the realms and the new realm is -1
    if (gmRealmID == -1)
    {
        QueryResult_AutoPtr result = LoginDatabase.PQuery("SELECT * FROM account_access WHERE id = '%u' AND gmlevel > '%d'", targetAccountId, gm);
        if (result)
        {
            SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
            SetSentErrorMessage(true);
            return false;
        }
    }

    // Check if provided realmID has a negative value other than -1
    if (gmRealmID < -1)
    {
        SendSysMessage(LANG_INVALID_REALMID);
        SetSentErrorMessage(true);
        return false;
    }

    // If gmRealmID is -1, delete all values for the account id, else, insert values for the specific realmID
    if (gmRealmID == -1)
        LoginDatabase.PExecute("DELETE FROM account_access WHERE id = '%u'", targetAccountId);
    else
        LoginDatabase.PExecute("DELETE FROM account_access WHERE id = '%u' AND (RealmID = '%d' OR RealmID = '-1')", targetAccountId, realmID);

    if (gm != 0)
        LoginDatabase.PExecute("INSERT INTO account_access VALUES ('%u','%d','%d')", targetAccountId, gm, realmID);
    PSendSysMessage(LANG_YOU_CHANGE_SECURITY, targetAccountName.c_str(), gm);
    return true;
}

/// Set password for account
bool ChatHandler::HandleAccountSetPasswordCommand(const char *args)
{
    if (!*args)
        return false;

    ///- Get the command line arguments
    char *szAccount = strtok ((char*)args," ");
    char *szPassword1 =  strtok (NULL," ");
    char *szPassword2 =  strtok (NULL," ");

    if (!szAccount||!szPassword1 || !szPassword2)
        return false;

    std::string account_name = szAccount;
    if (!AccountMgr::normalizeString(account_name))
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    uint32 targetAccountId = accmgr.GetId(account_name);
    if (!targetAccountId)
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    /// can set password only for target with less security
    /// This is also reject self apply in fact
    if (HasLowerSecurityAccount (NULL,targetAccountId,true))
        return false;

    if (strcmp(szPassword1,szPassword2))
    {
        SendSysMessage (LANG_NEW_PASSWORDS_NOT_MATCH);
        SetSentErrorMessage (true);
        return false;
    }

    AccountOpResult result = accmgr.ChangePassword(targetAccountId, szPassword1);

    switch (result)
    {
        case AOR_OK:
            SendSysMessage(LANG_COMMAND_PASSWORD);
            break;
        case AOR_NAME_NOT_EXIST:
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        case AOR_PASS_TOO_LONG:
            SendSysMessage(LANG_PASSWORD_TOO_LONG);
            SetSentErrorMessage(true);
            return false;
        default:
            SendSysMessage(LANG_COMMAND_NOTCHANGEPASSWORD);
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

bool ChatHandler::HandleMaxSkillCommand(const char* /*args*/)
{
    Player* SelectedPlayer = getSelectedPlayer();
    if (!SelectedPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // each skills that have max skill value dependent from level seted to current level max skill value
    SelectedPlayer->UpdateSkillsToMaxSkillsForLevel();
    return true;
}

bool ChatHandler::HandleSetSkillCommand(const char *args)
{
    // number or [name] Shift-click form |color|Hskill:skill_id|h[name]|h|r
    char* skill_p = extractKeyFromLink((char*)args,"Hskill");
    if (!skill_p)
        return false;

    char *level_p = strtok (NULL, " ");

    if (!level_p)
        return false;

    char *max_p   = strtok (NULL, " ");

    int32 skill = atoi(skill_p);
    if (skill <= 0)
    {
        PSendSysMessage(LANG_INVALID_SKILL_ID, skill);
        SetSentErrorMessage(true);
        return false;
    }

    int32 level = atol (level_p);

    Player * target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    SkillLineEntry const* sl = sSkillLineStore.LookupEntry(skill);
    if (!sl)
    {
        PSendSysMessage(LANG_INVALID_SKILL_ID, skill);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = GetNameLink(target);

    if (!target->GetSkillValue(skill))
    {
        PSendSysMessage(LANG_SET_SKILL_ERROR, tNameLink.c_str(), skill, sl->name[GetSessionDbcLocale()]);
        SetSentErrorMessage(true);
        return false;
    }

    int32 max   = max_p ? atol (max_p) : target->GetPureMaxSkillValue(skill);

    if (level <= 0 || level > max || max <= 0)
        return false;

    target->SetSkill(skill, target->GetSkillStep(skill), level, max);
    PSendSysMessage(LANG_SET_SKILL, skill, sl->name[GetSessionDbcLocale()], tNameLink.c_str(), level, max);

    return true;
}

bool ChatHandler::HandleUnLearnCommand(const char *args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    uint32 spell_id = extractSpellIdFromLink((char*)args);
    if (!spell_id)
        return false;

    char const* allStr = strtok(NULL," ");
    bool allRanks = allStr ? (strncmp(allStr, "all", strlen(allStr)) == 0) : false;

    Player* target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    if (allRanks)
        spell_id = spellmgr.GetFirstSpellInChain (spell_id);

    if (target->HasSpell(spell_id))
        target->removeSpell(spell_id,false,!allRanks);
    else
        SendSysMessage(LANG_FORGET_SPELL);

    if (GetTalentSpellCost(spell_id))
        target->SendTalentsInfoData(false);

    return true;
}

bool ChatHandler::HandleCooldownCommand(const char *args)
{
    Player* target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = GetNameLink(target);

    if (!*args)
    {
        target->RemoveAllSpellCooldown();
        PSendSysMessage(LANG_REMOVEALL_COOLDOWN, tNameLink.c_str());
    }
    else
    {
        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spell_id = extractSpellIdFromLink((char*)args);
        if (!spell_id)
            return false;

        if (!sSpellStore.LookupEntry(spell_id))
        {
            PSendSysMessage(LANG_UNKNOWN_SPELL, target == m_session->GetPlayer() ? GetTrinityString(LANG_YOU) : tNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        target->RemoveSpellCooldown(spell_id,true);
        PSendSysMessage(LANG_REMOVE_COOLDOWN, spell_id, target == m_session->GetPlayer() ? GetTrinityString(LANG_YOU) : tNameLink.c_str());
   }
    return true;
}

bool ChatHandler::HandleLearnAllCommand(const char* /*args*/)
{
    static const char *allSpellList[] =
    {
        "3365",
        "6233",
        "6247",
        "6246",
        "6477",
        "6478",
        "22810",
        "8386",
        "21651",
        "21652",
        "522",
        "7266",
        "8597",
        "2479",
        "22027",
        "6603",
        "5019",
        "133",
        "168",
        "227",
        "5009",
        "9078",
        "668",
        "203",
        "20599",
        "20600",
        "81",
        "20597",
        "20598",
        "20864",
        "1459",
        "5504",
        "587",
        "5143",
        "118",
        "5505",
        "597",
        "604",
        "1449",
        "1460",
        "2855",
        "1008",
        "475",
        "5506",
        "1463",
        "12824",
        "8437",
        "990",
        "5145",
        "8450",
        "1461",
        "759",
        "8494",
        "8455",
        "8438",
        "6127",
        "8416",
        "6129",
        "8451",
        "8495",
        "8439",
        "3552",
        "8417",
        "10138",
        "12825",
        "10169",
        "10156",
        "10144",
        "10191",
        "10201",
        "10211",
        "10053",
        "10173",
        "10139",
        "10145",
        "10192",
        "10170",
        "10202",
        "10054",
        "10174",
        "10193",
        "12826",
        "2136",
        "143",
        "145",
        "2137",
        "2120",
        "3140",
        "543",
        "2138",
        "2948",
        "8400",
        "2121",
        "8444",
        "8412",
        "8457",
        "8401",
        "8422",
        "8445",
        "8402",
        "8413",
        "8458",
        "8423",
        "8446",
        "10148",
        "10197",
        "10205",
        "10149",
        "10215",
        "10223",
        "10206",
        "10199",
        "10150",
        "10216",
        "10207",
        "10225",
        "10151",
        "116",
        "205",
        "7300",
        "122",
        "837",
        "10",
        "7301",
        "7322",
        "6143",
        "120",
        "865",
        "8406",
        "6141",
        "7302",
        "8461",
        "8407",
        "8492",
        "8427",
        "8408",
        "6131",
        "7320",
        "10159",
        "8462",
        "10185",
        "10179",
        "10160",
        "10180",
        "10219",
        "10186",
        "10177",
        "10230",
        "10181",
        "10161",
        "10187",
        "10220",
        "2018",
        "2663",
        "12260",
        "2660",
        "3115",
        "3326",
        "2665",
        "3116",
        "2738",
        "3293",
        "2661",
        "3319",
        "2662",
        "9983",
        "8880",
        "2737",
        "2739",
        "7408",
        "3320",
        "2666",
        "3323",
        "3324",
        "3294",
        "22723",
        "23219",
        "23220",
        "23221",
        "23228",
        "23338",
        "10788",
        "10790",
        "5611",
        "5016",
        "5609",
        "2060",
        "10963",
        "10964",
        "10965",
        "22593",
        "22594",
        "596",
        "996",
        "499",
        "768",
        "17002",
        "1448",
        "1082",
        "16979",
        "1079",
        "5215",
        "20484",
        "5221",
        "15590",
        "17007",
        "6795",
        "6807",
        "5487",
        "1446",
        "1066",
        "5421",
        "3139",
        "779",
        "6811",
        "6808",
        "1445",
        "5216",
        "1737",
        "5222",
        "5217",
        "1432",
        "6812",
        "9492",
        "5210",
        "3030",
        "1441",
        "783",
        "6801",
        "20739",
        "8944",
        "9491",
        "22569",
        "5226",
        "6786",
        "1433",
        "8973",
        "1828",
        "9495",
        "9006",
        "6794",
        "8993",
        "5203",
        "16914",
        "6784",
        "9635",
        "22830",
        "20722",
        "9748",
        "6790",
        "9753",
        "9493",
        "9752",
        "9831",
        "9825",
        "9822",
        "5204",
        "5401",
        "22831",
        "6793",
        "9845",
        "17401",
        "9882",
        "9868",
        "20749",
        "9893",
        "9899",
        "9895",
        "9832",
        "9902",
        "9909",
        "22832",
        "9828",
        "9851",
        "9883",
        "9869",
        "17406",
        "17402",
        "9914",
        "20750",
        "9897",
        "9848",
        "3127",
        "107",
        "204",
        "9116",
        "2457",
        "78",
        "18848",
        "331",
        "403",
        "2098",
        "1752",
        "11278",
        "11288",
        "11284",
        "6461",
        "2344",
        "2345",
        "6463",
        "2346",
        "2352",
        "775",
        "1434",
        "1612",
        "71",
        "2468",
        "2458",
        "2467",
        "7164",
        "7178",
        "7367",
        "7376",
        "7381",
        "21156",
        "5209",
        "3029",
        "5201",
        "9849",
        "9850",
        "20719",
        "22568",
        "22827",
        "22828",
        "22829",
        "6809",
        "8972",
        "9005",
        "9823",
        "9827",
        "6783",
        "9913",
        "6785",
        "6787",
        "9866",
        "9867",
        "9894",
        "9896",
        "6800",
        "8992",
        "9829",
        "9830",
        "780",
        "769",
        "6749",
        "6750",
        "9755",
        "9754",
        "9908",
        "20745",
        "20742",
        "20747",
        "20748",
        "9746",
        "9745",
        "9880",
        "9881",
        "5391",
        "842",
        "3025",
        "3031",
        "3287",
        "3329",
        "1945",
        "3559",
        "4933",
        "4934",
        "4935",
        "4936",
        "5142",
        "5390",
        "5392",
        "5404",
        "5420",
        "6405",
        "7293",
        "7965",
        "8041",
        "8153",
        "9033",
        "9034",
        //"9036", problems with ghost state
        "16421",
        "21653",
        "22660",
        "5225",
        "9846",
        "2426",
        "5916",
        "6634",
        //"6718", phasing stealth, annoying for learn all case.
        "6719",
        "8822",
        "9591",
        "9590",
        "10032",
        "17746",
        "17747",
        "8203",
        "11392",
        "12495",
        "16380",
        "23452",
        "4079",
        "4996",
        "4997",
        "4998",
        "4999",
        "5000",
        "6348",
        "6349",
        "6481",
        "6482",
        "6483",
        "6484",
        "11362",
        "11410",
        "11409",
        "12510",
        "12509",
        "12885",
        "13142",
        "21463",
        "23460",
        "11421",
        "11416",
        "11418",
        "1851",
        "10059",
        "11423",
        "11417",
        "11422",
        "11419",
        "11424",
        "11420",
        "27",
        "31",
        "33",
        "34",
        "35",
        "15125",
        "21127",
        "22950",
        "1180",
        "201",
        "12593",
        "16770",
        "6057",
        "12051",
        "18468",
        "12606",
        "12605",
        "18466",
        "12502",
        "12043",
        "15060",
        "12042",
        "12341",
        "12848",
        "12344",
        "12353",
        "18460",
        "11366",
        "12350",
        "12352",
        "13043",
        "11368",
        "11113",
        "12400",
        "11129",
        "16766",
        "12573",
        "12580",
        "12472",
        "12953",
        "12488",
        "11189",
        "12985",
        "12519",
        "16758",
        "11958",
        "12490",
        "11426",
        "3565",
        "3562",
        "18960",
        "3567",
        "3561",
        "3566",
        "3563",
        "1953",
        "2139",
        "12505",
        "13018",
        "12522",
        "12523",
        "5146",
        "5144",
        "5148",
        "8419",
        "8418",
        "10213",
        "10212",
        "10157",
        "12524",
        "13019",
        "12525",
        "13020",
        "12526",
        "13021",
        "18809",
        "13031",
        "13032",
        "13033",
        "4036",
        "3920",
        "3919",
        "3918",
        "7430",
        "3922",
        "3923",
        "7411",
        "7418",
        "7421",
        "13262",
        "7412",
        "7415",
        "7413",
        "7416",
        "13920",
        "13921",
        "7745",
        "7779",
        "7428",
        "7457",
        "7857",
        "7748",
        "7426",
        "13421",
        "7454",
        "13378",
        "7788",
        "14807",
        "14293",
        "7795",
        "6296",
        "20608",
        "755",
        "444",
        "427",
        "428",
        "442",
        "447",
        "3578",
        "3581",
        "19027",
        "3580",
        "665",
        "3579",
        "3577",
        "6755",
        "3576",
        "2575",
        "2577",
        "2578",
        "2579",
        "2580",
        "2656",
        "2657",
        "2576",
        "3564",
        "10248",
        "8388",
        "2659",
        "14891",
        "3308",
        "3307",
        "10097",
        "2658",
        "3569",
        "16153",
        "3304",
        "10098",
        "4037",
        "3929",
        "3931",
        "3926",
        "3924",
        "3930",
        "3977",
        "3925",
        "136",
        "228",
        "5487",
        "43",
        "202",
        "0"
    };

    int loop = 0;
    while (strcmp(allSpellList[loop], "0"))
    {
        uint32 spell = atol((char*)allSpellList[loop++]);

        if (m_session->GetPlayer()->HasSpell(spell))
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer()))
        {
            PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spell);
            continue;
        }

        m_session->GetPlayer()->learnSpell(spell, false);
    }

    SendSysMessage(LANG_COMMAND_LEARN_MANY_SPELLS);

    return true;
}

bool ChatHandler::HandleLearnAllGMCommand(const char* /*args*/)
{
    static const char *gmSpellList[] =
    {
        "24347",                                            // Become A Fish, No Breath Bar
        "35132",                                            // Visual Boom
        "38488",                                            // Attack 4000-8000 AOE
        "38795",                                            // Attack 2000 AOE + Slow Down 90%
        "15712",                                            // Attack 200
        "1852",                                             // GM Spell Silence
        "31899",                                            // Kill
        "31924",                                            // Kill
        "29878",                                            // Kill My Self
        "26644",                                            // More Kill

        "28550",                                            //Invisible 24
        "23452",                                            //Invisible + Target
        "0"
    };

    uint16 gmSpellIter = 0;
    while (strcmp(gmSpellList[gmSpellIter], "0"))
    {
        uint32 spell = atol((char*)gmSpellList[gmSpellIter++]);

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer()))
        {
            PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spell);
            continue;
        }

        m_session->GetPlayer()->learnSpell(spell, false);
    }

    SendSysMessage(LANG_LEARNING_GM_SKILLS);
    return true;
}

bool ChatHandler::HandleLearnAllMyClassCommand(const char* /*args*/)
{
    HandleLearnAllMySpellsCommand("");
    HandleLearnAllMyTalentsCommand("");
    return true;
}

bool ChatHandler::HandleLearnAllMySpellsCommand(const char* /*args*/)
{
    ChrClassesEntry const* clsEntry = sChrClassesStore.LookupEntry(m_session->GetPlayer()->getClass());
    if (!clsEntry)
        return true;
    uint32 family = clsEntry->spellfamily;

    for (uint32 i = 0; i < sSpellStore.GetNumRows(); ++i)
    {
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(i);
        if (!spellInfo)
            continue;

        // skip server-side/triggered spells
        if (spellInfo->spellLevel == 0)
            continue;

        // skip wrong class/race skills
        if (!m_session->GetPlayer()->IsSpellFitByClassAndRace(spellInfo->Id))
            continue;

        // skip other spell families
        if (spellInfo->SpellFamilyName != family)
            continue;

        // skip spells with first rank learned as talent (and all talents then also)
        uint32 first_rank = spellmgr.GetFirstSpellInChain(spellInfo->Id);
        if (GetTalentSpellCost(first_rank) > 0)
            continue;

        // skip broken spells
        if (!SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer(),false))
            continue;

        m_session->GetPlayer()->learnSpell(i, false);
    }

    SendSysMessage(LANG_COMMAND_LEARN_CLASS_SPELLS);
    return true;
}

bool ChatHandler::HandleLearnAllMyTalentsCommand(const char* /*args*/)
{
    Player* player = m_session->GetPlayer();
    uint32 classMask = player->getClassMask();

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const *talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
        if (!talentTabInfo)
            continue;

        if ((classMask & talentTabInfo->ClassMask) == 0)
            continue;

        // search highest talent rank
        uint32 spellId = 0;
        for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
        {
            if (talentInfo->RankID[rank] != 0)
            {
                spellId = talentInfo->RankID[rank];
                break;
            }
        }

        if (!spellId)                                        // ??? none spells in talent
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer(),false))
            continue;

        // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
        player->learnSpellHighRank(spellId);
        player->AddTalent(spellId, player->GetActiveSpec(), true);
    }

    player->SetFreeTalentPoints(0);

    SendSysMessage(LANG_COMMAND_LEARN_CLASS_TALENTS);
    return true;
}

bool ChatHandler::HandleLearnAllMyPetTalentsCommand(const char* /*args*/)
{
    Player* player = m_session->GetPlayer();

    Pet* pet = player->GetPet();
    if (!pet)
    {
        SendSysMessage(LANG_NO_PET_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    CreatureInfo const *ci = pet->GetCreatureInfo();
    if (!ci)
    {
        SendSysMessage(LANG_WRONG_PET_TYPE);
        SetSentErrorMessage(true);
        return false;
    }

    CreatureFamilyEntry const *pet_family = sCreatureFamilyStore.LookupEntry(ci->family);
    if (!pet_family)
    {
        SendSysMessage(LANG_WRONG_PET_TYPE);
        SetSentErrorMessage(true);
        return false;
    }

    if (pet_family->petTalentType < 0)                       // not hunter pet
    {
        SendSysMessage(LANG_WRONG_PET_TYPE);
        SetSentErrorMessage(true);
        return false;
    }

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const *talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        TalentTabEntry const *talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
        if (!talentTabInfo)
            continue;

        // prevent learn talent for different family (cheating)
        if (((1 << pet_family->petTalentType) & talentTabInfo->petTalentMask) == 0)
            continue;

        // search highest talent rank
        uint32 spellid = 0;

        for (int8 rank = MAX_TALENT_RANK-1; rank >= 0; --rank)
        {
            if (talentInfo->RankID[rank] != 0)
            {
                spellid = talentInfo->RankID[rank];
                break;
            }
        }

        if (!spellid)                                        // ??? none spells in talent
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellid);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer(),false))
            continue;

        // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
        pet->learnSpellHighRank(spellid);
    }

    pet->SetFreeTalentPoints(0);

    SendSysMessage(LANG_COMMAND_LEARN_PET_TALENTS);
    return true;
}

bool ChatHandler::HandleLearnAllLangCommand(const char* /*args*/)
{
    // skipping UNIVERSAL language (0)
    for (uint8 i = 1; i < LANGUAGES_COUNT; ++i)
        m_session->GetPlayer()->learnSpell(lang_description[i].spell_id, false);

    SendSysMessage(LANG_COMMAND_LEARN_ALL_LANG);
    return true;
}

bool ChatHandler::HandleLearnAllDefaultCommand(const char *args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    target->learnDefaultSpells();
    target->learnQuestRewardedSpells();

    PSendSysMessage(LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST,GetNameLink(target).c_str());
    return true;
}

bool ChatHandler::HandleLearnCommand(const char *args)
{
    Player* targetPlayer = getSelectedPlayer();

    if (!targetPlayer)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = extractSpellIdFromLink((char*)args);
    if (!spell || !sSpellStore.LookupEntry(spell))
        return false;

    char const* allStr = strtok(NULL," ");
    bool allRanks = allStr ? (strncmp(allStr, "all", strlen(allStr)) == 0) : false;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
    if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spell);
        SetSentErrorMessage(true);
        return false;
    }

    if (!allRanks && targetPlayer->HasSpell(spell))
    {
        if (targetPlayer == m_session->GetPlayer())
            SendSysMessage(LANG_YOU_KNOWN_SPELL);
        else
            PSendSysMessage(LANG_TARGET_KNOWN_SPELL,GetNameLink(targetPlayer).c_str());
        SetSentErrorMessage(true);
        return false;
    }

    if (allRanks)
        targetPlayer->learnSpellHighRank(spell);
    else
        targetPlayer->learnSpell(spell, false);

    uint32 first_spell = spellmgr.GetFirstSpellInChain(spell);
    if (GetTalentSpellCost(first_spell))
        targetPlayer->SendTalentsInfoData(false);

    return true;
}

bool ChatHandler::HandleAddItemCommand(const char *args)
{
    if (!*args)
        return false;

    uint32 itemId = 0;

    if (args[0] == '[')                                        // [name] manual form
    {
        char* citemName = strtok((char*)args, "]");

        if (citemName && citemName[0])
        {
            std::string itemName = citemName+1;
            WorldDatabase.escape_string(itemName);
            QueryResult_AutoPtr result = WorldDatabase.PQuery("SELECT entry FROM item_template WHERE name = '%s'", itemName.c_str());
            if (!result)
            {
                PSendSysMessage(LANG_COMMAND_COULDNOTFIND, citemName+1);
                SetSentErrorMessage(true);
                return false;
            }
            itemId = result->Fetch()->GetUInt16();
        }
        else
            return false;
    }
    else                                                    // item_id or [name] Shift-click form |color|Hitem:item_id:0:0:0|h[name]|h|r
    {
        char* cId = extractKeyFromLink((char*)args,"Hitem");
        if (!cId)
            return false;
        itemId = atol(cId);
    }

    char* ccount = strtok(NULL, " ");

    int32 count = 1;

    if (ccount)
        count = strtol(ccount, NULL, 10);

    if (count == 0)
        count = 1;

    Player* pl = m_session->GetPlayer();
    Player* plTarget = getSelectedPlayer();
    if (!plTarget)
        plTarget = pl;

    sLog.outDetail(GetTrinityString(LANG_ADDITEM), itemId, count);

    ItemPrototype const *pProto = objmgr.GetItemPrototype(itemId);
    if (!pProto)
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
        SetSentErrorMessage(true);
        return false;
    }

    //Subtract
    if (count < 0)
    {
        plTarget->DestroyItemCount(itemId, -count, true, false);
        PSendSysMessage(LANG_REMOVEITEM, itemId, -count, GetNameLink(plTarget).c_str());
        return true;
    }

    //Adding items
    uint32 noSpaceForCount = 0;

    // check space and find places
    ItemPosCountVec dest;
    uint8 msg = plTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)                               // convert to possible store amount
        count -= noSpaceForCount;

    if (count == 0 || dest.empty())                         // can't add any
    {
        PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemId, noSpaceForCount);
        SetSentErrorMessage(true);
        return false;
    }

    Item* item = plTarget->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));

    // remove binding (let GM give it to another player later)
    if (pl == plTarget)
        for (ItemPosCountVec::const_iterator itr = dest.begin(); itr != dest.end(); ++itr)
            if (Item* item1 = pl->GetItemByPos(itr->pos))
                item1->SetBinding(false);

    if (count > 0 && item)
    {
        pl->SendNewItem(item,count,false,true);
        if (pl != plTarget)
            plTarget->SendNewItem(item,count,true,false);
    }

    if (noSpaceForCount > 0)
        PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemId, noSpaceForCount);

    return true;
}

bool ChatHandler::HandleAddItemSetCommand(const char *args)
{
    if (!*args)
        return false;

    char* cId = extractKeyFromLink((char*)args,"Hitemset"); // number or [name] Shift-click form |color|Hitemset:itemset_id|h[name]|h|r
    if (!cId)
        return false;

    uint32 itemsetId = atol(cId);

    // prevent generation all items with itemset field value '0'
    if (itemsetId == 0)
    {
        PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND,itemsetId);
        SetSentErrorMessage(true);
        return false;
    }

    Player* pl = m_session->GetPlayer();
    Player* plTarget = getSelectedPlayer();
    if (!plTarget)
        plTarget = pl;

    sLog.outDetail(GetTrinityString(LANG_ADDITEMSET), itemsetId);

    bool found = false;
    for (uint32 id = 0; id < sItemStorage.MaxEntry; id++)
    {
        ItemPrototype const *pProto = sItemStorage.LookupEntry<ItemPrototype>(id);
        if (!pProto)
            continue;

        if (pProto->ItemSet == itemsetId)
        {
            found = true;
            ItemPosCountVec dest;
            uint8 msg = plTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pProto->ItemId, 1);
            if (msg == EQUIP_ERR_OK)
            {
                Item* item = plTarget->StoreNewItem(dest, pProto->ItemId, true);

                // remove binding (let GM give it to another player later)
                if (pl == plTarget)
                    item->SetBinding(false);

                pl->SendNewItem(item,1,false,true);
                if (pl != plTarget)
                    plTarget->SendNewItem(item,1,true,false);
            }
            else
            {
                pl->SendEquipError(msg, NULL, NULL, pProto->ItemId);
                PSendSysMessage(LANG_ITEM_CANNOT_CREATE, pProto->ItemId, 1);
            }
        }
    }

    if (!found)
    {
        PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND,itemsetId);

        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

bool ChatHandler::HandleListItemCommand(const char *args)
{
    if (!*args)
        return false;

    char* cId = extractKeyFromLink((char*)args,"Hitem");
    if (!cId)
        return false;

    uint32 item_id = atol(cId);
    if (!item_id)
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, item_id);
        SetSentErrorMessage(true);
        return false;
    }

    ItemPrototype const* itemProto = objmgr.GetItemPrototype(item_id);
    if (!itemProto)
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, item_id);
        SetSentErrorMessage(true);
        return false;
    }

    char* c_count = strtok(NULL, " ");
    int count = c_count ? atol(c_count) : 10;

    if (count < 0)
        return false;

    QueryResult_AutoPtr result;

    // inventory case
    uint32 inv_count = 0;
    result=CharacterDatabase.PQuery("SELECT COUNT(item_template) FROM character_inventory WHERE item_template='%u'",item_id);
    if (result)
        inv_count = (*result)[0].GetUInt32();

    result=CharacterDatabase.PQuery(
    //          0        1             2             3        4                  5
        "SELECT ci.item, cibag.slot AS bag, ci.slot, ci.guid, characters.account,characters.name "
        "FROM character_inventory AS ci LEFT JOIN character_inventory AS cibag ON (cibag.item=ci.bag),characters "
        "WHERE ci.item_template='%u' AND ci.guid = characters.guid LIMIT %u ",
        item_id,uint32(count));

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 item_guid = fields[0].GetUInt32();
            uint32 item_bag = fields[1].GetUInt32();
            uint32 item_slot = fields[2].GetUInt32();
            uint32 owner_guid = fields[3].GetUInt32();
            uint32 owner_acc = fields[4].GetUInt32();
            std::string owner_name = fields[5].GetCppString();

            char const* item_pos = 0;
            if (Player::IsEquipmentPos(item_bag,item_slot))
                item_pos = "[equipped]";
            else if (Player::IsInventoryPos(item_bag,item_slot))
                item_pos = "[in inventory]";
            else if (Player::IsBankPos(item_bag,item_slot))
                item_pos = "[in bank]";
            else
                item_pos = "";

            PSendSysMessage(LANG_ITEMLIST_SLOT,
                item_guid,owner_name.c_str(),owner_guid,owner_acc,item_pos);
        } while (result->NextRow());

        int64 res_count = result->GetRowCount();

        if (count > res_count)
            count-=res_count;
        else if (count)
            count = 0;
    }

    // mail case
    uint32 mail_count = 0;
    result=CharacterDatabase.PQuery("SELECT COUNT(item_template) FROM mail_items WHERE item_template='%u'", item_id);
    if (result)
        mail_count = (*result)[0].GetUInt32();

    if (count > 0)
    {
        result=CharacterDatabase.PQuery(
        //          0                     1            2              3               4            5               6
            "SELECT mail_items.item_guid, mail.sender, mail.receiver, char_s.account, char_s.name, char_r.account, char_r.name "
            "FROM mail,mail_items,characters as char_s,characters as char_r "
            "WHERE mail_items.item_template='%u' AND char_s.guid = mail.sender AND char_r.guid = mail.receiver AND mail.id=mail_items.mail_id LIMIT %u",
            item_id,uint32(count));
    }
    else
        result = QueryResult_AutoPtr(NULL);

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 item_guid        = fields[0].GetUInt32();
            uint32 item_s           = fields[1].GetUInt32();
            uint32 item_r           = fields[2].GetUInt32();
            uint32 item_s_acc       = fields[3].GetUInt32();
            std::string item_s_name = fields[4].GetCppString();
            uint32 item_r_acc       = fields[5].GetUInt32();
            std::string item_r_name = fields[6].GetCppString();

            char const* item_pos = "[in mail]";

            PSendSysMessage(LANG_ITEMLIST_MAIL,
                item_guid,item_s_name.c_str(),item_s,item_s_acc,item_r_name.c_str(),item_r,item_r_acc,item_pos);
        } while (result->NextRow());

        int64 res_count = result->GetRowCount();

        if (count > res_count)
            count-=res_count;
        else if (count)
            count = 0;
    }

    // auction case
    uint32 auc_count = 0;
    result=CharacterDatabase.PQuery("SELECT COUNT(item_template) FROM auctionhouse WHERE item_template='%u'",item_id);
    if (result)
        auc_count = (*result)[0].GetUInt32();

    if (count > 0)
    {
        result=CharacterDatabase.PQuery(
        //           0                      1                       2                   3
            "SELECT  auctionhouse.itemguid, auctionhouse.itemowner, characters.account, characters.name "
            "FROM auctionhouse,characters WHERE auctionhouse.item_template='%u' AND characters.guid = auctionhouse.itemowner LIMIT %u",
            item_id,uint32(count));
    }
    else
        result = QueryResult_AutoPtr(NULL);

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 item_guid       = fields[0].GetUInt32();
            uint32 owner           = fields[1].GetUInt32();
            uint32 owner_acc       = fields[2].GetUInt32();
            std::string owner_name = fields[3].GetCppString();

            char const* item_pos = "[in auction]";

            PSendSysMessage(LANG_ITEMLIST_AUCTION, item_guid, owner_name.c_str(), owner, owner_acc,item_pos);
        } while (result->NextRow());
    }

    // guild bank case
    uint32 guild_count = 0;
    result=CharacterDatabase.PQuery("SELECT COUNT(item_entry) FROM guild_bank_item WHERE item_entry='%u'",item_id);
    if (result)
        guild_count = (*result)[0].GetUInt32();

    result=CharacterDatabase.PQuery(
        //      0             1           2
        "SELECT gi.item_guid, gi.guildid, guild.name "
        "FROM guild_bank_item AS gi, guild WHERE gi.item_entry='%u' AND gi.guildid = guild.guildid LIMIT %u ",
        item_id,uint32(count));

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 item_guid = fields[0].GetUInt32();
            uint32 guild_guid = fields[1].GetUInt32();
            std::string guild_name = fields[2].GetCppString();

            char const* item_pos = "[in guild bank]";

            PSendSysMessage(LANG_ITEMLIST_GUILD,item_guid,guild_name.c_str(),guild_guid,item_pos);
        } while (result->NextRow());

        int64 res_count = result->GetRowCount();

        if (count > res_count)
            count-=res_count;
        else if (count)
            count = 0;
    }

    if (inv_count+mail_count+auc_count+guild_count == 0)
    {
        SendSysMessage(LANG_COMMAND_NOITEMFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_COMMAND_LISTITEMMESSAGE,item_id,inv_count+mail_count+auc_count+guild_count,inv_count,mail_count,auc_count,guild_count);

    return true;
}

bool ChatHandler::HandleListObjectCommand(const char *args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hgameobject_entry");
    if (!cId)
        return false;

    uint32 go_id = atol(cId);
    if (!go_id)
    {
        PSendSysMessage(LANG_COMMAND_LISTOBJINVALIDID, go_id);
        SetSentErrorMessage(true);
        return false;
    }

    GameObjectInfo const * gInfo = objmgr.GetGameObjectInfo(go_id);
    if (!gInfo)
    {
        PSendSysMessage(LANG_COMMAND_LISTOBJINVALIDID, go_id);
        SetSentErrorMessage(true);
        return false;
    }

    char* c_count = strtok(NULL, " ");
    int count = c_count ? atol(c_count) : 10;

    if (count < 0)
        return false;

    QueryResult_AutoPtr result;

    uint32 obj_count = 0;
    result=WorldDatabase.PQuery("SELECT COUNT(guid) FROM gameobject WHERE id='%u'",go_id);
    if (result)
        obj_count = (*result)[0].GetUInt32();

    if (m_session)
    {
        Player* pl = m_session->GetPlayer();
        result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM gameobject WHERE id = '%u' ORDER BY order_ ASC LIMIT %u",
            pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(),go_id,uint32(count));
    }
    else
        result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map FROM gameobject WHERE id = '%u' LIMIT %u",
            go_id,uint32(count));

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 guid = fields[0].GetUInt32();
            float x = fields[1].GetFloat();
            float y = fields[2].GetFloat();
            float z = fields[3].GetFloat();
            int mapid = fields[4].GetUInt16();

            if (m_session)
                PSendSysMessage(LANG_GO_LIST_CHAT, guid, guid, gInfo->name, x, y, z, mapid);
            else
                PSendSysMessage(LANG_GO_LIST_CONSOLE, guid, gInfo->name, x, y, z, mapid);
        } while (result->NextRow());
    }

    PSendSysMessage(LANG_COMMAND_LISTOBJMESSAGE,go_id,obj_count);
    return true;
}

bool ChatHandler::HandleGameObjectStateCommand(const char *args)
{
    // number or [name] Shift-click form |color|Hgameobject:go_id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args, "Hgameobject");
    if (!cId)
        return false;

    uint32 lowguid = atoi(cId);
    if (!lowguid)
        return false;

    GameObject* gobj = NULL;

    if (GameObjectData const* goData = objmgr.GetGOData(lowguid))
        gobj = GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid, goData->id);

    if (!gobj)
    {
        PSendSysMessage(LANG_COMMAND_OBJNOTFOUND, lowguid);
        SetSentErrorMessage(true);
        return false;
    }

    char* ctype = strtok(NULL, " ");
    if (!ctype)
        return false;

    int32 type = atoi(ctype);
    if (type < 0)
    {
        if (type == -1)
            gobj->SendObjectDeSpawnAnim(gobj->GetGUID());
        else if (type == -2)
        {
            return false;
        }
        return true;
    }

    char* cstate = strtok(NULL, " ");
    if (!cstate)
        return false;

    int32 state = atoi(cstate);

    if (type < 4)
        gobj->SetByteValue(GAMEOBJECT_BYTES_1, type, state);
    else if (type == 4)
    {
        WorldPacket data(SMSG_GAMEOBJECT_CUSTOM_ANIM,8+4);
        data << gobj->GetGUID();
        data << (uint32)(state);
        gobj->SendMessageToSet(&data, true);
    }
    PSendSysMessage("Set gobject type %d state %d", type, state);

    return true;
}

bool ChatHandler::HandleListCreatureCommand(const char *args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hcreature_entry");
    if (!cId)
        return false;

    uint32 cr_id = atol(cId);
    if (!cr_id)
    {
        PSendSysMessage(LANG_COMMAND_INVALIDCREATUREID, cr_id);
        SetSentErrorMessage(true);
        return false;
    }

    CreatureInfo const* cInfo = objmgr.GetCreatureTemplate(cr_id);
    if (!cInfo)
    {
        PSendSysMessage(LANG_COMMAND_INVALIDCREATUREID, cr_id);
        SetSentErrorMessage(true);
        return false;
    }

    char* c_count = strtok(NULL, " ");
    int count = c_count ? atol(c_count) : 10;

    if (count < 0)
        return false;

    QueryResult_AutoPtr result;

    uint32 cr_count = 0;
    result=WorldDatabase.PQuery("SELECT COUNT(guid) FROM creature WHERE id='%u'",cr_id);
    if (result)
        cr_count = (*result)[0].GetUInt32();

    if (m_session)
    {
        Player* pl = m_session->GetPlayer();
        result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM creature WHERE id = '%u' ORDER BY order_ ASC LIMIT %u",
            pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(), cr_id,uint32(count));
    }
    else
        result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map FROM creature WHERE id = '%u' LIMIT %u",
            cr_id,uint32(count));

    if (result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint32 guid = fields[0].GetUInt32();
            float x = fields[1].GetFloat();
            float y = fields[2].GetFloat();
            float z = fields[3].GetFloat();
            int mapid = fields[4].GetUInt16();

            if  (m_session)
                PSendSysMessage(LANG_CREATURE_LIST_CHAT, guid, guid, cInfo->Name, x, y, z, mapid);
            else
                PSendSysMessage(LANG_CREATURE_LIST_CONSOLE, guid, cInfo->Name, x, y, z, mapid);
        } while (result->NextRow());
    }

    PSendSysMessage(LANG_COMMAND_LISTCREATUREMESSAGE,cr_id,cr_count);
    return true;
}

bool ChatHandler::HandleLookupItemCommand(const char *args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    // converting string that we try to find to lower case
    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    wstrToLower(wnamepart);

    bool found = false;

    // Search in `item_template`
    for (uint32 id = 0; id < sItemStorage.MaxEntry; id++)
    {
        ItemPrototype const *pProto = sItemStorage.LookupEntry<ItemPrototype >(id);
        if (!pProto)
            continue;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            ItemLocale const *il = objmgr.GetItemLocale(pProto->ItemId);
            if (il)
            {
                if (il->Name.size() > loc_idx && !il->Name[loc_idx].empty())
                {
                    std::string name = il->Name[loc_idx];

                    if (Utf8FitTo(name, wnamepart))
                    {
                        if (m_session)
                            PSendSysMessage(LANG_ITEM_LIST_CHAT, id, id, name.c_str());
                        else
                            PSendSysMessage(LANG_ITEM_LIST_CONSOLE, id, name.c_str());

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }
        }

        std::string name = pProto->Name1;
        if (name.empty())
            continue;

        if (Utf8FitTo(name, wnamepart))
        {
            if (m_session)
                PSendSysMessage(LANG_ITEM_LIST_CHAT, id, id, name.c_str());
            else
                PSendSysMessage(LANG_ITEM_LIST_CONSOLE, id, name.c_str());

            if (!found)
                found = true;
        }
    }

    if (!found)
        SendSysMessage(LANG_COMMAND_NOITEMFOUND);

    return true;
}

bool ChatHandler::HandleLookupItemSetCommand(const char *args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    bool found = false;

    // Search in ItemSet.dbc
    for (uint32 id = 0; id < sItemSetStore.GetNumRows(); id++)
    {
        ItemSetEntry const *set = sItemSetStore.LookupEntry(id);
        if (set)
        {
            int loc = GetSessionDbcLocale();
            std::string name = set->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < MAX_LOCALE; ++loc)
                {
                    if (loc == GetSessionDbcLocale())
                        continue;

                    name = set->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < MAX_LOCALE)
            {
                // send item set in "id - [namedlink locale]" format
                if (m_session)
                    PSendSysMessage(LANG_ITEMSET_LIST_CHAT,id,id,name.c_str(),localeNames[loc]);
                else
                    PSendSysMessage(LANG_ITEMSET_LIST_CONSOLE,id,name.c_str(),localeNames[loc]);

                if (!found)
                    found = true;
            }
        }
    }
    if (!found)
        SendSysMessage(LANG_COMMAND_NOITEMSETFOUND);
    return true;
}

bool ChatHandler::HandleLookupSkillCommand(const char *args)
{
    if (!*args)
        return false;

    // can be NULL in console call
    Player* target = getSelectedPlayer();

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    bool found = false;

    // Search in SkillLine.dbc
    for (uint32 id = 0; id < sSkillLineStore.GetNumRows(); id++)
    {
        SkillLineEntry const *skillInfo = sSkillLineStore.LookupEntry(id);
        if (skillInfo)
        {
            int loc = GetSessionDbcLocale();
            std::string name = skillInfo->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < MAX_LOCALE; ++loc)
                {
                    if (loc == GetSessionDbcLocale())
                        continue;

                    name = skillInfo->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < MAX_LOCALE)
            {
                char valStr[50] = "";
                char const* knownStr = "";
                if (target && target->HasSkill(id))
                {
                    knownStr = GetTrinityString(LANG_KNOWN);
                    uint32 curValue = target->GetPureSkillValue(id);
                    uint32 maxValue  = target->GetPureMaxSkillValue(id);
                    uint32 permValue = target->GetSkillPermBonusValue(id);
                    uint32 tempValue = target->GetSkillTempBonusValue(id);

                    char const* valFormat = GetTrinityString(LANG_SKILL_VALUES);
                    snprintf(valStr,50,valFormat,curValue,maxValue,permValue,tempValue);
                }

                // send skill in "id - [namedlink locale]" format
                if (m_session)
                    PSendSysMessage(LANG_SKILL_LIST_CHAT,id,id,name.c_str(),localeNames[loc],knownStr,valStr);
                else
                    PSendSysMessage(LANG_SKILL_LIST_CONSOLE,id,name.c_str(),localeNames[loc],knownStr,valStr);

                if (!found)
                    found = true;
            }
        }
    }
    if (!found)
        SendSysMessage(LANG_COMMAND_NOSKILLFOUND);
    return true;
}

bool ChatHandler::HandleLookupSpellCommand(const char *args)
{
    if (!*args)
        return false;

    // can be NULL at console call
    Player* target = getSelectedPlayer();

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    bool found = false;

    // Search in Spell.dbc
    for (uint32 id = 0; id < sSpellStore.GetNumRows(); id++)
    {
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(id);
        if (spellInfo)
        {
            int loc = GetSessionDbcLocale();
            std::string name = spellInfo->SpellName[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < MAX_LOCALE; ++loc)
                {
                    if (loc == GetSessionDbcLocale())
                        continue;

                    name = spellInfo->SpellName[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < MAX_LOCALE)
            {
                bool known = target && target->HasSpell(id);
                bool learn = (spellInfo->Effect[0] == SPELL_EFFECT_LEARN_SPELL);

                uint32 talentCost = GetTalentSpellCost(id);

                bool talent = (talentCost > 0);
                bool passive = IsPassiveSpell(id);
                bool active = target && target->HasAura(id);

                // unit32 used to prevent interpreting uint8 as char at output
                // find rank of learned spell for learning spell, or talent rank
                uint32 rank = talentCost ? talentCost : spellmgr.GetSpellRank(learn ? spellInfo->EffectTriggerSpell[0] : id);

                // send spell in "id - [name, rank N] [talent] [passive] [learn] [known]" format
                std::ostringstream ss;
                if (m_session)
                    ss << id << " - |cffffffff|Hspell:" << id << "|h[" << name;
                else
                    ss << id << " - " << name;

                // include rank in link name
                if (rank)
                    ss << GetTrinityString(LANG_SPELL_RANK) << rank;

                if (m_session)
                    ss << " " << localeNames[loc] << "]|h|r";
                else
                    ss << " " << localeNames[loc];

                if (talent)
                    ss << GetTrinityString(LANG_TALENT);
                if (passive)
                    ss << GetTrinityString(LANG_PASSIVE);
                if (learn)
                    ss << GetTrinityString(LANG_LEARN);
                if (known)
                    ss << GetTrinityString(LANG_KNOWN);
                if (active)
                    ss << GetTrinityString(LANG_ACTIVE);

                SendSysMessage(ss.str().c_str());

                if (!found)
                    found = true;
            }
        }
    }
    if (!found)
        SendSysMessage(LANG_COMMAND_NOSPELLFOUND);
    return true;
}

bool ChatHandler::HandleLookupQuestCommand(const char *args)
{
    if (!*args)
        return false;

    // can be NULL at console call
    Player* target = getSelectedPlayer();

    std::string namepart = args;
    std::wstring wnamepart;

    // converting string that we try to find to lower case
    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    wstrToLower(wnamepart);

    bool found = false;

    ObjectMgr::QuestMap const& qTemplates = objmgr.GetQuestTemplates();
    for (ObjectMgr::QuestMap::const_iterator iter = qTemplates.begin(); iter != qTemplates.end(); ++iter)
    {
        Quest * qinfo = iter->second;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            QuestLocale const *il = objmgr.GetQuestLocale(qinfo->GetQuestId());
            if (il)
            {
                if (il->Title.size() > loc_idx && !il->Title[loc_idx].empty())
                {
                    std::string title = il->Title[loc_idx];

                    if (Utf8FitTo(title, wnamepart))
                    {
                        char const* statusStr = "";

                        if (target)
                        {
                            QuestStatus status = target->GetQuestStatus(qinfo->GetQuestId());

                            if (status == QUEST_STATUS_COMPLETE)
                            {
                                if (target->GetQuestRewardStatus(qinfo->GetQuestId()))
                                    statusStr = GetTrinityString(LANG_COMMAND_QUEST_REWARDED);
                                else
                                    statusStr = GetTrinityString(LANG_COMMAND_QUEST_COMPLETE);
                            }
                            else if (status == QUEST_STATUS_INCOMPLETE)
                                statusStr = GetTrinityString(LANG_COMMAND_QUEST_ACTIVE);
                        }

                        if (m_session)
                            PSendSysMessage(LANG_QUEST_LIST_CHAT,qinfo->GetQuestId(),qinfo->GetQuestId(),qinfo->GetQuestLevel(),title.c_str(),statusStr);
                        else
                            PSendSysMessage(LANG_QUEST_LIST_CONSOLE,qinfo->GetQuestId(),title.c_str(),statusStr);

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }
        }

        std::string title = qinfo->GetTitle();
        if (title.empty())
            continue;

        if (Utf8FitTo(title, wnamepart))
        {
            char const* statusStr = "";

            if (target)
            {
                QuestStatus status = target->GetQuestStatus(qinfo->GetQuestId());

                if (status == QUEST_STATUS_COMPLETE)
                {
                    if (target->GetQuestRewardStatus(qinfo->GetQuestId()))
                        statusStr = GetTrinityString(LANG_COMMAND_QUEST_REWARDED);
                    else
                        statusStr = GetTrinityString(LANG_COMMAND_QUEST_COMPLETE);
                }
                else if (status == QUEST_STATUS_INCOMPLETE)
                    statusStr = GetTrinityString(LANG_COMMAND_QUEST_ACTIVE);
            }

            if (m_session)
                PSendSysMessage(LANG_QUEST_LIST_CHAT,qinfo->GetQuestId(),qinfo->GetQuestId(),qinfo->GetQuestLevel(),title.c_str(),statusStr);
            else
                PSendSysMessage(LANG_QUEST_LIST_CONSOLE,qinfo->GetQuestId(),title.c_str(),statusStr);

            if (!found)
                found = true;
        }
    }

    if (!found)
        SendSysMessage(LANG_COMMAND_NOQUESTFOUND);

    return true;
}

bool ChatHandler::HandleLookupCreatureCommand(const char *args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    // converting string that we try to find to lower case
    if (!Utf8toWStr (namepart,wnamepart))
        return false;

    wstrToLower (wnamepart);

    bool found = false;

    for (uint32 id = 0; id< sCreatureStorage.MaxEntry; ++id)
    {
        CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo> (id);
        if (!cInfo)
            continue;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            CreatureLocale const *cl = objmgr.GetCreatureLocale (id);
            if (cl)
            {
                if (cl->Name.size() > loc_idx && !cl->Name[loc_idx].empty ())
                {
                    std::string name = cl->Name[loc_idx];

                    if (Utf8FitTo (name, wnamepart))
                    {
                        if (m_session)
                            PSendSysMessage (LANG_CREATURE_ENTRY_LIST_CHAT, id, id, name.c_str ());
                        else
                            PSendSysMessage (LANG_CREATURE_ENTRY_LIST_CONSOLE, id, name.c_str ());

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }
        }

        std::string name = cInfo->Name;
        if (name.empty ())
            continue;

        if (Utf8FitTo(name, wnamepart))
        {
            if (m_session)
                PSendSysMessage (LANG_CREATURE_ENTRY_LIST_CHAT, id, id, name.c_str ());
            else
                PSendSysMessage (LANG_CREATURE_ENTRY_LIST_CONSOLE, id, name.c_str ());

            if (!found)
                found = true;
        }
    }

    if (!found)
        SendSysMessage (LANG_COMMAND_NOCREATUREFOUND);

    return true;
}

bool ChatHandler::HandleLookupObjectCommand(const char *args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    // converting string that we try to find to lower case
    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    wstrToLower(wnamepart);

    bool found = false;

    for (uint32 id = 0; id< sGOStorage.MaxEntry; id++)
    {
        GameObjectInfo const* gInfo = sGOStorage.LookupEntry<GameObjectInfo>(id);
        if (!gInfo)
            continue;

        int loc_idx = GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
        {
            GameObjectLocale const *gl = objmgr.GetGameObjectLocale(id);
            if (gl)
            {
                if (gl->Name.size() > loc_idx && !gl->Name[loc_idx].empty())
                {
                    std::string name = gl->Name[loc_idx];

                    if (Utf8FitTo(name, wnamepart))
                    {
                        if (m_session)
                            PSendSysMessage(LANG_GO_ENTRY_LIST_CHAT, id, id, name.c_str());
                        else
                            PSendSysMessage(LANG_GO_ENTRY_LIST_CONSOLE, id, name.c_str());

                        if (!found)
                            found = true;

                        continue;
                    }
                }
            }
        }

        std::string name = gInfo->name;
        if (name.empty())
            continue;

        if (Utf8FitTo(name, wnamepart))
        {
            if (m_session)
                PSendSysMessage(LANG_GO_ENTRY_LIST_CHAT, id, id, name.c_str());
            else
                PSendSysMessage(LANG_GO_ENTRY_LIST_CONSOLE, id, name.c_str());

            if (!found)
                found = true;
        }
    }

    if (!found)
        SendSysMessage(LANG_COMMAND_NOGAMEOBJECTFOUND);

    return true;
}

bool ChatHandler::HandleLookupFactionCommand(const char *args)
{
    if (!*args)
        return false;

    // Can be NULL at console call
    Player *target = getSelectedPlayer ();

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr (namepart,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower (wnamepart);

    bool found = false;

    for (uint32 id = 0; id < sFactionStore.GetNumRows(); ++id)
    {
        FactionEntry const *factionEntry = sFactionStore.LookupEntry (id);
        if (factionEntry)
        {
            FactionState const* repState = target ? target->GetReputationMgr().GetState(factionEntry) : NULL;

            int loc = GetSessionDbcLocale();
            std::string name = factionEntry->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < MAX_LOCALE; ++loc)
                {
                    if (loc == GetSessionDbcLocale())
                        continue;

                    name = factionEntry->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < MAX_LOCALE)
            {
                // send faction in "id - [faction] rank reputation [visible] [at war] [own team] [unknown] [invisible] [inactive]" format
                // or              "id - [faction] [no reputation]" format
                std::ostringstream ss;
                if (m_session)
                    ss << id << " - |cffffffff|Hfaction:" << id << "|h[" << name << " " << localeNames[loc] << "]|h|r";
                else
                    ss << id << " - " << name << " " << localeNames[loc];

                if (repState)                               // and then target != NULL also
                {
                    ReputationRank rank = target->GetReputationMgr().GetRank(factionEntry);
                    std::string rankName = GetTrinityString(ReputationRankStrIndex[rank]);

                    ss << " " << rankName << "|h|r (" << target->GetReputationMgr().GetReputation(factionEntry) << ")";

                    if (repState->Flags & FACTION_FLAG_VISIBLE)
                        ss << GetTrinityString(LANG_FACTION_VISIBLE);
                    if (repState->Flags & FACTION_FLAG_AT_WAR)
                        ss << GetTrinityString(LANG_FACTION_ATWAR);
                    if (repState->Flags & FACTION_FLAG_PEACE_FORCED)
                        ss << GetTrinityString(LANG_FACTION_PEACE_FORCED);
                    if (repState->Flags & FACTION_FLAG_HIDDEN)
                        ss << GetTrinityString(LANG_FACTION_HIDDEN);
                    if (repState->Flags & FACTION_FLAG_INVISIBLE_FORCED)
                        ss << GetTrinityString(LANG_FACTION_INVISIBLE_FORCED);
                    if (repState->Flags & FACTION_FLAG_INACTIVE)
                        ss << GetTrinityString(LANG_FACTION_INACTIVE);
                }
                else
                    ss << GetTrinityString(LANG_FACTION_NOREPUTATION);

                SendSysMessage(ss.str().c_str());

                if (!found)
                    found = true;
            }
        }
    }

    if (!found)
        SendSysMessage(LANG_COMMAND_FACTION_NOTFOUND);
    return true;
}

bool ChatHandler::HandleLookupTaxiNodeCommand(const char * args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart,wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    bool found = false;

    // Search in TaxiNodes.dbc
    for (uint32 id = 0; id < sTaxiNodesStore.GetNumRows(); id++)
    {
        TaxiNodesEntry const *nodeEntry = sTaxiNodesStore.LookupEntry(id);
        if (nodeEntry)
        {
            int loc = GetSessionDbcLocale();
            std::string name = nodeEntry->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = 0;
                for (; loc < MAX_LOCALE; ++loc)
                {
                    if (loc == GetSessionDbcLocale())
                        continue;

                    name = nodeEntry->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < MAX_LOCALE)
            {
                // send taxinode in "id - [name] (Map:m X:x Y:y Z:z)" format
                if (m_session)
                    PSendSysMessage (LANG_TAXINODE_ENTRY_LIST_CHAT, id, id, name.c_str(),localeNames[loc],
                        nodeEntry->map_id,nodeEntry->x,nodeEntry->y,nodeEntry->z);
                else
                    PSendSysMessage (LANG_TAXINODE_ENTRY_LIST_CONSOLE, id, name.c_str(), localeNames[loc],
                        nodeEntry->map_id,nodeEntry->x,nodeEntry->y,nodeEntry->z);

                if (!found)
                    found = true;
            }
        }
    }
    if (!found)
        SendSysMessage(LANG_COMMAND_NOTAXINODEFOUND);
    return true;
}

bool ChatHandler::HandleLookupMapCommand(const char *args)
{
    if (!*args)
        return false;

    /*std::string namepart = args;
    std::wstring wnamepart;

    // converting string that we try to find to lower case
    if (!Utf8toWStr(namepart, wnamepart))
        return false;

    wstrToLower(wnamepart);

    bool found = false;

    // search in Map.dbc
    for (uint32 id = 0; id < sMapStore.GetNumRows(); id++)
    {
        MapEntry const* MapInfo = sMapStore.LookupEntry(id);
        if (MapInfo)
        {
            uint8 loc = m_session ? m_session->GetSessionDbcLocale() : sWorld.GetDefaultDbcLocale();

            std::string name = MapInfo->name[loc];
            if (name.empty())
                continue;

            if (!Utf8FitTo(name, wnamepart))
            {
                loc = LOCALE_enUS;
                for (; loc < MAX_LOCALE; loc++)
                {
                    if (m_session && loc == m_session->GetSessionDbcLocale())
                        continue;

                    name = MapInfo->name[loc];
                    if (name.empty())
                        continue;

                    if (Utf8FitTo(name, wnamepart))
                        break;
                }
            }

            if (loc < MAX_LOCALE)
            {
                // send map in "id - [name][Continent][Instance/Battleground/Arena][Raid reset time:][Heroic reset time:][Mountable]" format
                std::ostringstream ss;

                if (m_session)
                    ss << id << " - |cffffffff|Hmap:" << id << "|h[" << name << "]";
                else // console
                    ss << id << " - [" << name << "]";

                if (MapInfo->IsContinent())
                    ss << GetTrinityString(LANG_CONTINENT);

                switch(MapInfo->map_type)
                {
                    case MAP_INSTANCE:      ss << GetTrinityString(LANG_INSTANCE);      break;
                    case MAP_BATTLEGROUND:  ss << GetTrinityString(LANG_BATTLEGROUND);  break;
                    case MAP_ARENA:         ss << GetTrinityString(LANG_ARENA);         break;
                }

                if (MapInfo->IsRaid())
                    ss << GetTrinityString(LANG_RAID);

                if (MapInfo->SupportsHeroicMode())
                    ss << GetTrinityString(LANG_HEROIC);

                uint32 ResetTimeRaid = MapInfo->resetTimeRaid;

                std::string ResetTimeRaidStr;
                if (ResetTimeRaid)
                    ResetTimeRaidStr = secsToTimeString(ResetTimeRaid, true, false);

                uint32 ResetTimeHeroic = MapInfo->resetTimeHeroic;
                std::string ResetTimeHeroicStr;
                if (ResetTimeHeroic)
                    ResetTimeHeroicStr = secsToTimeString(ResetTimeHeroic, true, false);

                if (MapInfo->IsMountAllowed())
                    ss << GetTrinityString(LANG_MOUNTABLE);

                if (ResetTimeRaid && !ResetTimeHeroic)
                    PSendSysMessage(ss.str().c_str(), ResetTimeRaidStr.c_str());
                else if (!ResetTimeRaid && ResetTimeHeroic)
                    PSendSysMessage(ss.str().c_str(), ResetTimeHeroicStr.c_str());
                else if (ResetTimeRaid && ResetTimeHeroic)
                    PSendSysMessage(ss.str().c_str(), ResetTimeRaidStr.c_str(), ResetTimeHeroicStr.c_str());
                else
                    SendSysMessage(ss.str().c_str());

                if (!found)
                    found = true;
            }
        }
    }

    if (!found)
        SendSysMessage(LANG_COMMAND_NOMAPFOUND);
    */
    return true;
}

/** \brief GM command level 3 - Create a guild.
 *
 * This command allows a GM (level 3) to create a guild.
 *
 * The "args" parameter contains the name of the guild leader
 * and then the name of the guild.
 *
 */
bool ChatHandler::HandleGuildCreateCommand(const char *args)
{
    if (!*args)
        return false;

    // if not guild name only (in "") then player name
    Player* target;
    if (!extractPlayerTarget(*args != '"' ? (char*)args : NULL, &target))
        return false;

    char* tailStr = *args != '"' ? strtok(NULL, "") : (char*)args;
    if (!tailStr)
        return false;

    char* guildStr = extractQuotedArg(tailStr);
    if (!guildStr)
        return false;

    std::string guildname = guildStr;

    if (target->GetGuildId())
    {
        SendSysMessage (LANG_PLAYER_IN_GUILD);
        return true;
    }

    Guild *guild = new Guild;
    if (!guild->Create (target,guildname))
    {
        delete guild;
        SendSysMessage (LANG_GUILD_NOT_CREATED);
        SetSentErrorMessage (true);
        return false;
    }

    objmgr.AddGuild (guild);
    return true;
}

bool ChatHandler::HandleGuildInviteCommand(const char *args)
{
    if (!*args)
        return false;

    // if not guild name only (in "") then player name
    uint64 target_guid;
    if (!extractPlayerTarget(*args != '"' ? (char*)args : NULL, NULL, &target_guid))
        return false;

    char* tailStr = *args != '"' ? strtok(NULL, "") : (char*)args;
    if (!tailStr)
        return false;

    char* guildStr = extractQuotedArg(tailStr);
    if (!guildStr)
        return false;

    std::string glName = guildStr;
    Guild* targetGuild = objmgr.GetGuildByName (glName);
    if (!targetGuild)
        return false;

    // player's guild membership checked in AddMember before add
    if (!targetGuild->AddMember (target_guid,targetGuild->GetLowestRank ()))
        return false;

    return true;
}

bool ChatHandler::HandleGuildUninviteCommand(const char *args)
{
    Player* target;
    uint64 target_guid;
    if (!extractPlayerTarget((char*)args,&target,&target_guid))
        return false;

    uint32 glId   = target ? target->GetGuildId () : Player::GetGuildIdFromDB (target_guid);
    if (!glId)
        return false;

    Guild* targetGuild = objmgr.GetGuildById (glId);
    if (!targetGuild)
        return false;

    targetGuild->DelMember (target_guid);
    return true;
}

bool ChatHandler::HandleGuildRankCommand(const char *args)
{
    char* nameStr;
    char* rankStr;
    extractOptFirstArg((char*)args,&nameStr,&rankStr);
    if (!rankStr)
        return false;

    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget(nameStr,&target,&target_guid,&target_name))
        return false;

    uint32 glId   = target ? target->GetGuildId () : Player::GetGuildIdFromDB (target_guid);
    if (!glId)
        return false;

    Guild* targetGuild = objmgr.GetGuildById (glId);
    if (!targetGuild)
        return false;

    uint32 newrank = uint32 (atoi (rankStr));
    if (newrank > targetGuild->GetLowestRank ())
        return false;

    targetGuild->ChangeRank (target_guid,newrank);
    return true;
}

bool ChatHandler::HandleGuildDeleteCommand(const char *args)
{
    if (!*args)
        return false;

    char* guildStr = extractQuotedArg((char*)args);
    if (!guildStr)
        return false;

    std::string gld = guildStr;

    Guild* targetGuild = objmgr.GetGuildByName (gld);
    if (!targetGuild)
        return false;

    targetGuild->Disband ();

    return true;
}

bool ChatHandler::HandleGetDistanceCommand(const char *args)
{
    WorldObject* obj = NULL;

    if (*args)
    {
        uint64 guid = extractGuidFromLink((char*)args);
        if (guid)
            obj = (WorldObject*)ObjectAccessor::GetObjectByTypeMask(*m_session->GetPlayer(),guid,TYPEMASK_UNIT|TYPEMASK_GAMEOBJECT);

        if (!obj)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        obj = getSelectedUnit();

        if (!obj)
        {
            SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }
    }

    PSendSysMessage(LANG_DISTANCE, m_session->GetPlayer()->GetDistance(obj), m_session->GetPlayer()->GetDistance2d(obj), m_session->GetPlayer()->GetExactDist(obj), m_session->GetPlayer()->GetExactDist2d(obj));
    return true;
}

bool ChatHandler::HandleDieCommand(const char* /*args*/)
{
    Unit* target = getSelectedUnit();

    if (!target || !m_session->GetPlayer()->GetSelection())
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (target->GetTypeId() == TYPEID_PLAYER)
    {
        if (HasLowerSecurity((Player*)target,0,false))
            return false;
    }

    if (target->isAlive())
    {
        if (sWorld.getConfig(CONFIG_DIE_COMMAND_MODE))
            m_session->GetPlayer()->Kill(target);
        else
            m_session->GetPlayer()->DealDamage(target, target->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    return true;
}

bool ChatHandler::HandleDamageCommand(const char * args)
{
    if (!*args)
        return false;

    Unit* target = getSelectedUnit();

    if (!target || !m_session->GetPlayer()->GetSelection())
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!target->isAlive())
        return true;

    char* damageStr = strtok((char*)args, " ");
    if (!damageStr)
        return false;

    int32 damage_int = atoi((char*)damageStr);
    if (damage_int <= 0)
        return true;

    uint32 damage = damage_int;

    char* schoolStr = strtok((char*)NULL, " ");

    // flat melee damage without resistence/etc reduction
    if (!schoolStr)
    {
        m_session->GetPlayer()->DealDamage(target, damage, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        if (target != m_session->GetPlayer())
            m_session->GetPlayer()->SendAttackStateUpdate (HITINFO_NORMALSWING2, target, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_NORMAL, 0);
        return true;
    }

    uint32 school = schoolStr ? atoi((char*)schoolStr) : SPELL_SCHOOL_NORMAL;
    if (school >= MAX_SPELL_SCHOOL)
        return false;

    SpellSchoolMask schoolmask = SpellSchoolMask(1 << school);

    if (schoolmask & SPELL_SCHOOL_MASK_NORMAL)
        damage = m_session->GetPlayer()->CalcArmorReducedDamage(target, damage, NULL, BASE_ATTACK);

    char* spellStr = strtok((char*)NULL, " ");

    // melee damage by specific school
    if (!spellStr)
    {
        uint32 absorb = 0;
        uint32 resist = 0;

        m_session->GetPlayer()->CalcAbsorbResist(target,schoolmask, SPELL_DIRECT_DAMAGE, damage, &absorb, &resist);

        if (damage <= absorb + resist)
            return true;

        damage -= absorb + resist;

        m_session->GetPlayer()->DealDamageMods(target,damage,&absorb);
        m_session->GetPlayer()->DealDamage(target, damage, NULL, DIRECT_DAMAGE, schoolmask, NULL, false);
        m_session->GetPlayer()->SendAttackStateUpdate (HITINFO_NORMALSWING2, target, 1, schoolmask, damage, absorb, resist, VICTIMSTATE_NORMAL, 0);
        return true;
    }

    // non-melee damage

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellid = extractSpellIdFromLink((char*)args);
    if (!spellid || !sSpellStore.LookupEntry(spellid))
        return false;

    m_session->GetPlayer()->SpellNonMeleeDamageLog(target, spellid, damage);
    return true;
}

bool ChatHandler::HandleModifyArenaCommand(const char * args)
{
    if (!*args)
        return false;

    Player *target = getSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount = (uint32)atoi(args);

    target->ModifyArenaPoints(amount);

    PSendSysMessage(LANG_COMMAND_MODIFY_ARENA, GetNameLink(target).c_str(), target->GetArenaPoints());

    return true;
}

bool ChatHandler::HandleReviveCommand(const char *args)
{
    Player* target;
    uint64 target_guid;
    if (!extractPlayerTarget((char*)args,&target,&target_guid))
        return false;

    if (target)
    {
        target->ResurrectPlayer(target->GetSession()->GetSecurity() > SEC_PLAYER ? 1.0f : 0.5f);
        target->SpawnCorpseBones();
        target->SaveToDB();
    }
    else
        // will resurrected at login without corpse
        sObjectAccessor.ConvertCorpseForPlayer(target_guid);

    return true;
}

bool ChatHandler::HandleAuraCommand(const char *args)
{
    Unit *target = getSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellID = extractSpellIdFromLink((char*)args);

    if (SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellID))
        Aura::TryCreate(spellInfo, target, target);

    return true;
}

bool ChatHandler::HandleUnAuraCommand(const char *args)
{
    Unit *target = getSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    std::string argstr = args;
    if (argstr == "all")
    {
        target->RemoveAllAuras();
        return true;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellID = extractSpellIdFromLink((char*)args);
    if (!spellID)
        return false;

    target->RemoveAurasDueToSpell(spellID);

    return true;
}

bool ChatHandler::HandleLinkGraveCommand(const char *args)
{
    if (!*args)
        return false;

    char* px = strtok((char*)args, " ");
    if (!px)
        return false;

    uint32 g_id = (uint32)atoi(px);

    uint32 g_team;

    char* px2 = strtok(NULL, " ");

    if (!px2)
        g_team = 0;
    else if (strncmp(px2,"horde",6) == 0)
        g_team = HORDE;
    else if (strncmp(px2,"alliance",9) == 0)
        g_team = ALLIANCE;
    else
        return false;

    WorldSafeLocsEntry const* graveyard =  sWorldSafeLocsStore.LookupEntry(g_id);

    if (!graveyard)
    {
        PSendSysMessage(LANG_COMMAND_GRAVEYARDNOEXIST, g_id);
        SetSentErrorMessage(true);
        return false;
    }

    Player* player = m_session->GetPlayer();

    uint32 zoneId = player->GetZoneId();

    AreaTableEntry const *areaEntry = GetAreaEntryByAreaID(zoneId);
    if (!areaEntry || areaEntry->zone !=0)
    {
        PSendSysMessage(LANG_COMMAND_GRAVEYARDWRONGZONE, g_id,zoneId);
        SetSentErrorMessage(true);
        return false;
    }

    if (objmgr.AddGraveYardLink(g_id,zoneId,g_team))
        PSendSysMessage(LANG_COMMAND_GRAVEYARDLINKED, g_id,zoneId);
    else
        PSendSysMessage(LANG_COMMAND_GRAVEYARDALRLINKED, g_id,zoneId);

    return true;
}

bool ChatHandler::HandleNearGraveCommand(const char *args)
{
    uint32 g_team;

    size_t argslen = strlen(args);

    if (!*args)
        g_team = 0;
    else if (strncmp((char*)args,"horde",argslen) == 0)
        g_team = HORDE;
    else if (strncmp((char*)args,"alliance",argslen) == 0)
        g_team = ALLIANCE;
    else
        return false;

    Player* player = m_session->GetPlayer();
    uint32 zone_id = player->GetZoneId();

    WorldSafeLocsEntry const* graveyard = objmgr.GetClosestGraveYard(
        player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(),player->GetMapId(),g_team);

    if (graveyard)
    {
        uint32 g_id = graveyard->ID;

        GraveYardData const* data = objmgr.FindGraveYardData(g_id,zone_id);
        if (!data)
        {
            PSendSysMessage(LANG_COMMAND_GRAVEYARDERROR,g_id);
            SetSentErrorMessage(true);
            return false;
        }

        g_team = data->team;

        std::string team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_NOTEAM);

        if (g_team == 0)
            team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_ANY);
        else if (g_team == HORDE)
            team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_HORDE);
        else if (g_team == ALLIANCE)
            team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_ALLIANCE);

        PSendSysMessage(LANG_COMMAND_GRAVEYARDNEAREST, g_id,team_name.c_str(),zone_id);
    }
    else
    {
        std::string team_name;

        if (g_team == 0)
            team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_ANY);
        else if (g_team == HORDE)
            team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_HORDE);
        else if (g_team == ALLIANCE)
            team_name = GetTrinityString(LANG_COMMAND_GRAVEYARD_ALLIANCE);

        if (g_team == ~uint32(0))
            PSendSysMessage(LANG_COMMAND_ZONENOGRAVEYARDS, zone_id);
        else
            PSendSysMessage(LANG_COMMAND_ZONENOGRAFACTION, zone_id,team_name.c_str());
    }

    return true;
}

//-----------------------Npc Commands-----------------------
bool ChatHandler::HandleNpcAllowMovementCommand(const char* /*args*/)
{
    if (sWorld.getAllowMovement())
    {
        sWorld.SetAllowMovement(false);
        SendSysMessage(LANG_CREATURE_MOVE_DISABLED);
    }
    else
    {
        sWorld.SetAllowMovement(true);
        SendSysMessage(LANG_CREATURE_MOVE_ENABLED);
    }
    return true;
}

bool ChatHandler::HandleNpcChangeEntryCommand(const char *args)
{
    if (!*args)
        return false;

    uint32 newEntryNum = atoi(args);
    if (!newEntryNum)
        return false;

    Unit* unit = getSelectedUnit();
    if (!unit || unit->GetTypeId() != TYPEID_UNIT)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }
    Creature* creature = unit->ToCreature();
    if (creature->UpdateEntry(newEntryNum))
        SendSysMessage(LANG_DONE);
    else
        SendSysMessage(LANG_ERROR);
    return true;
}

bool ChatHandler::HandleNpcInfoCommand(const char* /*args*/)
{
    Creature* target = getSelectedCreature();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 faction = target->getFaction();
    uint32 npcflags = target->GetUInt32Value(UNIT_NPC_FLAGS);
    uint32 displayid = target->GetDisplayId();
    uint32 nativeid = target->GetNativeDisplayId();
    uint32 Entry = target->GetEntry();
    CreatureInfo const* cInfo = target->GetCreatureInfo();

    int32 curRespawnDelay = target->GetRespawnTimeEx()-time(NULL);
    if (curRespawnDelay < 0)
        curRespawnDelay = 0;
    std::string curRespawnDelayStr = secsToTimeString(curRespawnDelay,true);
    std::string defRespawnDelayStr = secsToTimeString(target->GetRespawnDelay(),true);

    PSendSysMessage(LANG_NPCINFO_CHAR,  target->GetDBTableGUIDLow(), faction, npcflags, Entry, displayid, nativeid);
    PSendSysMessage(LANG_NPCINFO_LEVEL, target->getLevel());
    PSendSysMessage(LANG_NPCINFO_HEALTH,target->GetCreateHealth(), target->GetMaxHealth(), target->GetHealth());
    PSendSysMessage(LANG_NPCINFO_FLAGS, target->GetUInt32Value(UNIT_FIELD_FLAGS), target->GetUInt32Value(UNIT_DYNAMIC_FLAGS), target->getFaction());
    PSendSysMessage(LANG_COMMAND_RAWPAWNTIMES, defRespawnDelayStr.c_str(),curRespawnDelayStr.c_str());
    PSendSysMessage(LANG_NPCINFO_LOOT,  cInfo->lootid,cInfo->pickpocketLootId,cInfo->SkinLootId);
    PSendSysMessage(LANG_NPCINFO_DUNGEON_ID, target->GetInstanceId());
    PSendSysMessage(LANG_NPCINFO_PHASEMASK, target->GetPhaseMask());
    PSendSysMessage(LANG_NPCINFO_ARMOR, target->GetArmor());
    PSendSysMessage(LANG_NPCINFO_POSITION,float(target->GetPositionX()), float(target->GetPositionY()), float(target->GetPositionZ()));
    if (const CreatureData* const linked = target->GetLinkedRespawnCreatureData())
        if (CreatureInfo const *master = GetCreatureInfo(linked->id))
            PSendSysMessage(LANG_NPCINFO_LINKGUID, objmgr.GetLinkedRespawnGuid(target->GetDBTableGUIDLow()), linked->id, master->Name);

    if ((npcflags & UNIT_NPC_FLAG_VENDOR))
    {
        SendSysMessage(LANG_NPCINFO_VENDOR);
    }
    if ((npcflags & UNIT_NPC_FLAG_TRAINER))
    {
        SendSysMessage(LANG_NPCINFO_TRAINER);
    }

    return true;
}

//play npc emote
bool ChatHandler::HandleNpcPlayEmoteCommand(const char *args)
{
    uint32 emote = atoi((char*)args);

    Creature* target = getSelectedCreature();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (target->GetTransport())
        if (target->GetGUIDTransport())
            WorldDatabase.PQuery("UPDATE creature_transport SET emote=%u WHERE transport_entry=%u AND guid=%u", emote, target->GetTransport()->GetEntry(), target->GetGUIDTransport());

    target->SetUInt32Value(UNIT_NPC_EMOTESTATE,emote);

    return true;
}

//TODO: NpcCommands that needs to be fixed :

bool ChatHandler::HandleNpcAddWeaponCommand(const char* /*args*/)
{
    /*if (!*args)
    return false;

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
        SendSysMessage(LANG_NO_SELECTION);
        return true;
    }

    Creature *pCreature = ObjectAccessor::GetCreature(*m_session->GetPlayer(), guid);

    if (!pCreature)
    {
        SendSysMessage(LANG_SELECT_CREATURE);
        return true;
    }

    char* pSlotID = strtok((char*)args, " ");
    if (!pSlotID)
        return false;

    char* pItemID = strtok(NULL, " ");
    if (!pItemID)
        return false;

    uint32 ItemID = atoi(pItemID);
    uint32 SlotID = atoi(pSlotID);

    ItemPrototype* tmpItem = objmgr.GetItemPrototype(ItemID);

    bool added = false;
    if (tmpItem)
    {
        switch(SlotID)
        {
            case 1:
                pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, ItemID);
                added = true;
                break;
            case 2:
                pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, ItemID);
                added = true;
                break;
            case 3:
                pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_02, ItemID);
                added = true;
                break;
            default:
                PSendSysMessage(LANG_ITEM_SLOT_NOT_EXIST,SlotID);
                added = false;
                break;
        }

        if (added)
            PSendSysMessage(LANG_ITEM_ADDED_TO_SLOT,ItemID,tmpItem->Name1,SlotID);
    }
    else
    {
        PSendSysMessage(LANG_ITEM_NOT_FOUND,ItemID);
        return true;
    }
    */
    return true;
}
//----------------------------------------------------------

bool ChatHandler::HandleExploreCheatCommand(const char *args)
{
    if (!*args)
        return false;

    int flag = atoi((char*)args);

    Player *chr = getSelectedPlayer();
    if (chr == NULL)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    if (flag != 0)
    {
        PSendSysMessage(LANG_YOU_SET_EXPLORE_ALL, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_EXPLORE_SET_ALL,GetNameLink().c_str());
    }
    else
    {
        PSendSysMessage(LANG_YOU_SET_EXPLORE_NOTHING, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_EXPLORE_SET_NOTHING,GetNameLink().c_str());
    }

    for (uint8 i=0; i<PLAYER_EXPLORED_ZONES_SIZE; ++i)
    {
        if (flag != 0)
        {
            m_session->GetPlayer()->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
        }
        else
        {
            m_session->GetPlayer()->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0);
        }
    }

    return true;
}

bool ChatHandler::HandleHoverCommand(const char *args)
{
    char* px = strtok((char*)args, " ");
    uint32 flag;
    if (!px)
        flag = 1;
    else
        flag = atoi(px);

    m_session->GetPlayer()->SetHover(flag);

    if (flag)
        SendSysMessage(LANG_HOVER_ENABLED);
    else
        SendSysMessage(LANG_HOVER_DISABLED);

    return true;
}

void ChatHandler::HandleCharacterLevel(Player* player, uint64 player_guid, uint32 oldlevel, uint32 newlevel)
{
    if (player)
    {
        player->GiveLevel(newlevel);
        player->InitTalentForLevel();
        player->SetUInt32Value(PLAYER_XP,0);

        if (needReportToTarget(player))
        {
            if (oldlevel == newlevel)
                ChatHandler(player).PSendSysMessage(LANG_YOURS_LEVEL_PROGRESS_RESET,GetNameLink().c_str());
            else if (oldlevel < newlevel)
                ChatHandler(player).PSendSysMessage(LANG_YOURS_LEVEL_UP,GetNameLink().c_str(),newlevel);
            else                                                // if (oldlevel > newlevel)
                ChatHandler(player).PSendSysMessage(LANG_YOURS_LEVEL_DOWN,GetNameLink().c_str(),newlevel);
        }
    }
    else
    {
        // update level and XP at level, all other will be updated at loading
        CharacterDatabase.PExecute("UPDATE characters SET level = '%u', xp = 0 WHERE guid = '%u'", newlevel, GUID_LOPART(player_guid));
    }
}

bool ChatHandler::HandleCharacterLevelCommand(const char *args)
{
    char* nameStr;
    char* levelStr;
    extractOptFirstArg((char*)args,&nameStr,&levelStr);
    if (!levelStr)
        return false;

    // exception opt second arg: .character level $name
    if (isalpha(levelStr[0]))
    {
        nameStr = levelStr;
        levelStr = NULL;                                    // current level will used
    }

    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget(nameStr,&target,&target_guid,&target_name))
        return false;

    int32 oldlevel = target ? target->getLevel() : Player::GetLevelFromDB(target_guid);
    int32 newlevel = levelStr ? atoi(levelStr) : oldlevel;

    if (newlevel < 1)
        return false;                                       // invalid level

    if (newlevel > STRONG_MAX_LEVEL)                         // hardcoded maximum level
        newlevel = STRONG_MAX_LEVEL;

    HandleCharacterLevel(target,target_guid,oldlevel,newlevel);

    if (!m_session || m_session->GetPlayer() != target)      // including player == NULL
    {
        std::string nameLink = playerLink(target_name);
        PSendSysMessage(LANG_YOU_CHANGE_LVL,nameLink.c_str(),newlevel);
    }

    return true;
}

bool ChatHandler::HandleLevelUpCommand(const char *args)
{
    char* nameStr;
    char* levelStr;
    extractOptFirstArg((char*)args,&nameStr,&levelStr);

    // exception opt second arg: .character level $name
    if (levelStr && isalpha(levelStr[0]))
    {
        nameStr = levelStr;
        levelStr = NULL;                                    // current level will used
    }

    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget(nameStr,&target,&target_guid,&target_name))
        return false;

    int32 oldlevel = target ? target->getLevel() : Player::GetLevelFromDB(target_guid);
    int32 addlevel = levelStr ? atoi(levelStr) : 1;
    int32 newlevel = oldlevel + addlevel;

    if (newlevel < 1)
        newlevel = 1;

    if (newlevel > STRONG_MAX_LEVEL)                         // hardcoded maximum level
        newlevel = STRONG_MAX_LEVEL;

    HandleCharacterLevel(target,target_guid,oldlevel,newlevel);

    if (!m_session || m_session->GetPlayer() != target)      // including chr == NULL
    {
        std::string nameLink = playerLink(target_name);
        PSendSysMessage(LANG_YOU_CHANGE_LVL,nameLink.c_str(),newlevel);
    }

    return true;
}

bool ChatHandler::HandleShowAreaCommand(const char *args)
{
    if (!*args)
        return false;

    Player *chr = getSelectedPlayer();
    if (chr == NULL)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    int area = GetAreaFlagByAreaID(atoi((char*)args));
    int offset = area / 32;
    uint32 val = (uint32)(1 << (area % 32));

    if (area<0 || offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 currFields = chr->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);
    chr->SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields | val));

    SendSysMessage(LANG_EXPLORE_AREA);
    return true;
}

bool ChatHandler::HandleHideAreaCommand(const char *args)
{
    if (!*args)
        return false;

    Player *chr = getSelectedPlayer();
    if (chr == NULL)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    int area = GetAreaFlagByAreaID(atoi((char*)args));
    int offset = area / 32;
    uint32 val = (uint32)(1 << (area % 32));

    if (area<0 || offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 currFields = chr->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);
    chr->SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields ^ val));

    SendSysMessage(LANG_UNEXPLORE_AREA);
    return true;
}

bool ChatHandler::HandleBankCommand(const char* /*args*/)
{
    m_session->SendShowBank(m_session->GetPlayer()->GetGUID());

    return true;
}

bool ChatHandler::HandleChangeWeather(const char *args)
{
    if (!*args)
        return false;

    //Weather is OFF
    if (!sWorld.getConfig(CONFIG_WEATHER))
    {
        SendSysMessage(LANG_WEATHER_DISABLED);
        SetSentErrorMessage(true);
        return false;
    }

    //*Change the weather of a cell
    char* px = strtok((char*)args, " ");
    char* py = strtok(NULL, " ");

    if (!px || !py)
        return false;

    uint32 type = (uint32)atoi(px);                         //0 to 3, 0: fine, 1: rain, 2: snow, 3: sand
    float grade = (float)atof(py);                          //0 to 1, sending -1 is instand good weather

    Player *player = m_session->GetPlayer();
    uint32 zoneid = player->GetZoneId();

    Weather* wth = sWorld.FindWeather(zoneid);

    if (!wth)
        wth = sWorld.AddWeather(zoneid);
    if (!wth)
    {
        SendSysMessage(LANG_NO_WEATHER);
        SetSentErrorMessage(true);
        return false;
    }

    wth->SetWeather(WeatherType(type), grade);

    return true;
}

bool ChatHandler::HandleDebugSet32Bit(const char *args)
{
    if (!*args)
        return false;

    WorldObject* target = getSelectedObject();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    char* px = strtok((char*)args, " ");
    char* py = strtok(NULL, " ");

    if (!px || !py)
        return false;

    uint32 Opcode = (uint32)atoi(px);
    uint32 Value = (uint32)atoi(py);
    if (Value > 32)                                         //uint32 = 32 bits
        return false;

    sLog.outDebug(GetTrinityString(LANG_SET_32BIT), Opcode, Value);

    uint32 iValue = Value ? 1 << (Value - 1) : 0;
    target->SetUInt32Value(Opcode ,  iValue);

    PSendSysMessage(LANG_SET_32BIT_FIELD, Opcode, iValue);
    return true;
}

bool ChatHandler::HandleTeleAddCommand(const char * args)
{
    if (!*args)
        return false;

    Player *player=m_session->GetPlayer();
    if (!player)
        return false;

    std::string name = args;

    if (objmgr.GetGameTele(name))
    {
        SendSysMessage(LANG_COMMAND_TP_ALREADYEXIST);
        SetSentErrorMessage(true);
        return false;
    }

    GameTele tele;
    tele.position_x  = player->GetPositionX();
    tele.position_y  = player->GetPositionY();
    tele.position_z  = player->GetPositionZ();
    tele.orientation = player->GetOrientation();
    tele.mapId       = player->GetMapId();
    tele.name        = name;

    if (objmgr.AddGameTele(tele))
    {
        SendSysMessage(LANG_COMMAND_TP_ADDED);
    }
    else
    {
        SendSysMessage(LANG_COMMAND_TP_ADDEDERR);
        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

bool ChatHandler::HandleTeleDelCommand(const char * args)
{
    if (!*args)
        return false;

    std::string name = args;

    if (!objmgr.DeleteGameTele(name))
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    SendSysMessage(LANG_COMMAND_TP_DELETED);
    return true;
}

bool ChatHandler::HandleListAurasCommand (const char * /*args*/)
{
    Unit *unit = getSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    char const* talentStr = GetTrinityString(LANG_TALENT);
    char const* passiveStr = GetTrinityString(LANG_PASSIVE);

    Unit::AuraApplicationMap const& uAuras = unit->GetAppliedAuras();
    PSendSysMessage(LANG_COMMAND_TARGET_LISTAURAS, uAuras.size());
    for (Unit::AuraApplicationMap::const_iterator itr = uAuras.begin(); itr != uAuras.end(); ++itr)
    {
        bool talent = GetTalentSpellCost(itr->second->GetBase()->GetId()) > 0;

        AuraApplication const * aurApp = itr->second;
        Aura const * aura = aurApp->GetBase();
        char const* name = aura->GetSpellProto()->SpellName[GetSessionDbcLocale()];

        if (m_session)
        {
            std::ostringstream ss_name;
            ss_name << "|cffffffff|Hspell:" << aura->GetId() << "|h[" << name << "]|h|r";

            PSendSysMessage(LANG_COMMAND_TARGET_AURADETAIL, aura->GetId(), aurApp->GetEffectMask(),
                aura->GetCharges(), aura->GetStackAmount(), aurApp->GetSlot(),
                aura->GetDuration(), aura->GetMaxDuration(),
                ss_name.str().c_str(),
                (aura->IsPassive() ? passiveStr : ""),(talent ? talentStr : ""),
                IS_PLAYER_GUID(aura->GetCasterGUID()) ? "player" : "creature",GUID_LOPART(aura->GetCasterGUID()));
        }
        else
        {
            PSendSysMessage(LANG_COMMAND_TARGET_AURADETAIL, aura->GetId(), aurApp->GetEffectMask(),
                aura->GetCharges(), aura->GetStackAmount(), aurApp->GetSlot(),
                aura->GetDuration(), aura->GetMaxDuration(),
                name,
                (aura->IsPassive() ? passiveStr : ""),(talent ? talentStr : ""),
                IS_PLAYER_GUID(aura->GetCasterGUID()) ? "player" : "creature",GUID_LOPART(aura->GetCasterGUID()));
        }
    }
    for (uint16 i = 0; i < TOTAL_AURAS; ++i)
    {
        Unit::AuraEffectList const& uAuraList = unit->GetAuraEffectsByType(AuraType(i));
        if (uAuraList.empty()) continue;
        PSendSysMessage(LANG_COMMAND_TARGET_LISTAURATYPE, uAuraList.size(), i);
        for (Unit::AuraEffectList::const_iterator itr = uAuraList.begin(); itr != uAuraList.end(); ++itr)
        {
            //bool talent = GetTalentSpellCost((*itr)->GetId()) > 0;

            char const* name = (*itr)->GetSpellProto()->SpellName[GetSessionDbcLocale()];

            std::ostringstream ss_name;
            ss_name << "|cffffffff|Hspell:" << (*itr)->GetId() << "|h[" << name << "]|h|r";

            PSendSysMessage(LANG_COMMAND_TARGET_AURASIMPLE, (*itr)->GetId(), (*itr)->GetEffIndex(),
                (*itr)->GetAmount());
        }
    }
    return true;
}

bool ChatHandler::HandleResetAchievementsCommand (const char * args)
{
    Player* target;
    uint64 target_guid;
    if (!extractPlayerTarget((char*)args,&target,&target_guid))
        return false;

    if (target)
        target->GetAchievementMgr().Reset();
    else
        AchievementMgr::DeleteFromDB(GUID_LOPART(target_guid));

    return true;
}

bool ChatHandler::HandleResetHonorCommand (const char * args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    target->SetUInt32Value(PLAYER_FIELD_KILLS, 0);
    target->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 0);
    target->SetUInt32Value(PLAYER_FIELD_HONOR_CURRENCY, 0);
    target->SetUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION, 0);
    target->SetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION, 0);
    target->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL);

    return true;
}

static bool HandleResetStatsOrLevelHelper(Player* player)
{
    ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(player->getClass());
    if (!cEntry)
    {
        sLog.outError("Class %u not found in DBC (Wrong DBC files?)",player->getClass());
        return false;
    }

    uint8 powertype = cEntry->powerType;

    // reset m_form if no aura
    if (!player->HasAuraType(SPELL_AURA_MOD_SHAPESHIFT))
        player->m_form = FORM_NONE;

    player->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, DEFAULT_WORLD_OBJECT_SIZE);
    player->SetFloatValue(UNIT_FIELD_COMBATREACH, DEFAULT_COMBAT_REACH);

    player->setFactionForRace(player->getRace());

    player->SetUInt32Value(UNIT_FIELD_BYTES_0, ((player->getRace()) | (player->getClass() << 8) | (player->getGender() << 16) | (powertype << 24)));

    // reset only if player not in some form;
    if (player->m_form == FORM_NONE)
        player->InitDisplayIds();

    player->SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP);
    player->SetByteValue(UNIT_FIELD_BYTES_2, 3, player->m_form);

    player->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

    //-1 is default value
    player->SetUInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, uint32(-1));

    //player->SetUInt32Value(PLAYER_FIELD_BYTES, 0xEEE00000);
    return true;
}

bool ChatHandler::HandleResetLevelCommand(const char * args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    if (!HandleResetStatsOrLevelHelper(target))
        return false;

    // set starting level
    uint32 start_level = target->getClass() != CLASS_DEATH_KNIGHT
        ? sWorld.getConfig(CONFIG_START_PLAYER_LEVEL)
        : sWorld.getConfig(CONFIG_START_HEROIC_PLAYER_LEVEL);

    target->_ApplyAllLevelScaleItemMods(false);

    target->SetLevel(start_level);
    target->InitRunes();
    target->InitStatsForLevel(true);
    target->InitTaxiNodesForLevel();
    target->InitGlyphsForLevel();
    target->InitTalentForLevel();
    target->SetUInt32Value(PLAYER_XP,0);

    target->_ApplyAllLevelScaleItemMods(true);

    // reset level for pet
    if (Pet* pet = target->GetPet())
        pet->SynchronizeLevelWithOwner();

    return true;
}

bool ChatHandler::HandleResetStatsCommand(const char * args)
{
    Player* target;
    if (!extractPlayerTarget((char*)args,&target))
        return false;

    if (!HandleResetStatsOrLevelHelper(target))
        return false;

    target->InitRunes();
    target->InitStatsForLevel(true);
    target->InitTaxiNodesForLevel();
    target->InitGlyphsForLevel();
    target->InitTalentForLevel();

    return true;
}

bool ChatHandler::HandleResetSpellsCommand(const char * args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
        return false;

    if (target)
    {
        target->resetSpells(/* bool myClassOnly */);

        ChatHandler(target).SendSysMessage(LANG_RESET_SPELLS);
        if (!m_session || m_session->GetPlayer() != target)
            PSendSysMessage(LANG_RESET_SPELLS_ONLINE,GetNameLink(target).c_str());
    }
    else
    {
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '%u' WHERE guid = '%u'",uint32(AT_LOGIN_RESET_SPELLS), GUID_LOPART(target_guid));
        PSendSysMessage(LANG_RESET_SPELLS_OFFLINE,target_name.c_str());
    }

    return true;
}

bool ChatHandler::HandleResetTalentsCommand(const char * args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*)args,&target,&target_guid,&target_name))
    {
        // Try reset talents as Hunter Pet
        Creature* creature = getSelectedCreature();
        if (!*args && creature && creature->isPet())
        {
            Unit *owner = creature->GetOwner();
            if (owner && owner->GetTypeId() == TYPEID_PLAYER && ((Pet *)creature)->IsPermanentPetFor(owner->ToPlayer()))
            {
                ((Pet *)creature)->resetTalents(true);
                owner->ToPlayer()->SendTalentsInfoData(true);

                ChatHandler(owner->ToPlayer()).SendSysMessage(LANG_RESET_PET_TALENTS);
                if (!m_session || m_session->GetPlayer() != owner->ToPlayer())
          PSendSysMessage(LANG_RESET_PET_TALENTS_ONLINE,GetNameLink(owner->ToPlayer()).c_str());
            }
            return true;
        }

        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        target->resetTalents(true);
        target->SendTalentsInfoData(false);
        ChatHandler(target).SendSysMessage(LANG_RESET_TALENTS);
        if (!m_session || m_session->GetPlayer() != target)
            PSendSysMessage(LANG_RESET_TALENTS_ONLINE,GetNameLink(target).c_str());

        Pet* pet = target->GetPet();
        Pet::resetTalentsForAllPetsOf(target,pet);
        if (pet)
            target->SendTalentsInfoData(true);
        return true;
    }
    else if (target_guid)
    {
        uint32 at_flags = AT_LOGIN_NONE | AT_LOGIN_RESET_PET_TALENTS;
        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '%u' WHERE guid = '%u'",at_flags, GUID_LOPART(target_guid));
        std::string nameLink = playerLink(target_name);
        PSendSysMessage(LANG_RESET_TALENTS_OFFLINE,nameLink.c_str());
        return true;
    }

    SendSysMessage(LANG_NO_CHAR_SELECTED);
    SetSentErrorMessage(true);
    return false;
}

bool ChatHandler::HandleResetAllCommand(const char * args)
{
    if (!*args)
        return false;

    std::string casename = args;

    AtLoginFlags atLogin;

    // Command specially created as single command to prevent using short case names
    if (casename == "spells")
    {
        atLogin = AT_LOGIN_RESET_SPELLS;
        sWorld.SendWorldText(LANG_RESETALL_SPELLS);
        if (!m_session)
            SendSysMessage(LANG_RESETALL_SPELLS);
    }
    else if (casename == "talents")
    {
        atLogin = AtLoginFlags(AT_LOGIN_RESET_TALENTS | AT_LOGIN_RESET_PET_TALENTS);
        sWorld.SendWorldText(LANG_RESETALL_TALENTS);
        if (!m_session)
            SendSysMessage(LANG_RESETALL_TALENTS);
    }
    else
    {
        PSendSysMessage(LANG_RESETALL_UNKNOWN_CASE,args);
        SetSentErrorMessage(true);
        return false;
    }

    CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '%u' WHERE (at_login & '%u') = '0'",atLogin,atLogin);

    ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, *HashMapHolder<Player>::GetLock(), true);
    HashMapHolder<Player>::MapType const& plist = sObjectAccessor.GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = plist.begin(); itr != plist.end(); ++itr)
        itr->second->SetAtLoginFlag(atLogin);

    return true;
}

bool ChatHandler::HandleServerShutDownCancelCommand(const char* /*args*/)
{
    sWorld.ShutdownCancel();
    return true;
}

bool ChatHandler::HandleServerShutDownCommand(const char *args)
{
    if (!*args)
        return false;

    char* time_str = strtok ((char*) args, " ");
    char* exitcode_str = strtok (NULL, "");

    int32 time = atoi (time_str);

    ///- Prevent interpret wrong arg value as 0 secs shutdown time
    if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0')) || time < 0)
        return false;

    if (exitcode_str)
    {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld.ShutdownServ (time, 0, exitcode);
    }
    else
        sWorld.ShutdownServ(time,0,SHUTDOWN_EXIT_CODE);
    return true;
}

bool ChatHandler::HandleServerRestartCommand(const char *args)
{
    if (!*args)
        return false;

    char* time_str = strtok ((char*) args, " ");
    char* exitcode_str = strtok (NULL, "");

    int32 time = atoi (time_str);

    ///- Prevent interpret wrong arg value as 0 secs shutdown time
    if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0') || time < 0))
        return false;

    if (exitcode_str)
    {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld.ShutdownServ (time, SHUTDOWN_MASK_RESTART, exitcode);
    }
    else
        sWorld.ShutdownServ(time, SHUTDOWN_MASK_RESTART, RESTART_EXIT_CODE);
    return true;
}

bool ChatHandler::HandleServerIdleRestartCommand(const char *args)
{
    if (!*args)
        return false;

    char* time_str = strtok ((char*) args, " ");
    char* exitcode_str = strtok (NULL, "");

    int32 time = atoi (time_str);

    ///- Prevent interpret wrong arg value as 0 secs shutdown time
    if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0') || time < 0))
        return false;

    if (exitcode_str)
    {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld.ShutdownServ (time, SHUTDOWN_MASK_RESTART|SHUTDOWN_MASK_IDLE, exitcode);
    }
    else
        sWorld.ShutdownServ(time,SHUTDOWN_MASK_RESTART|SHUTDOWN_MASK_IDLE,RESTART_EXIT_CODE);
    return true;
}

bool ChatHandler::HandleServerIdleShutDownCommand(const char *args)
{
    if (!*args)
        return false;

    char* time_str = strtok ((char*) args, " ");
    char* exitcode_str = strtok (NULL, "");

    int32 time = atoi (time_str);

    ///- Prevent interpret wrong arg value as 0 secs shutdown time
    if (time == 0 && (time_str[0] != '0' || time_str[1] != '\0') || time < 0)
        return false;

    if (exitcode_str)
    {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld.ShutdownServ (time, SHUTDOWN_MASK_IDLE, exitcode);
    }
    else
        sWorld.ShutdownServ(time,SHUTDOWN_MASK_IDLE,SHUTDOWN_EXIT_CODE);
    return true;
}

bool ChatHandler::HandleQuestAdd(const char *args)
{
    Player* player = getSelectedPlayer();
    if (!player)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // .addquest #entry'
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hquest");
    if (!cId)
        return false;

    uint32 entry = atol(cId);

    Quest const* pQuest = objmgr.GetQuestTemplate(entry);

    if (!pQuest)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND,entry);
        SetSentErrorMessage(true);
        return false;
    }

    // check item starting quest (it can work incorrectly if added without item in inventory)
    for (uint32 id = 0; id < sItemStorage.MaxEntry; id++)
    {
        ItemPrototype const *pProto = sItemStorage.LookupEntry<ItemPrototype>(id);
        if (!pProto)
            continue;

        if (pProto->StartQuest == entry)
        {
            PSendSysMessage(LANG_COMMAND_QUEST_STARTFROMITEM, entry, pProto->ItemId);
            SetSentErrorMessage(true);
            return false;
        }
    }

    // ok, normal (creature/GO starting) quest
    if (player->CanAddQuest(pQuest, true))
    {
        player->AddQuest(pQuest, NULL);

        if (player->CanCompleteQuest(entry))
            player->CompleteQuest(entry);
    }

    return true;
}

bool ChatHandler::HandleQuestRemove(const char *args)
{
    Player* player = getSelectedPlayer();
    if (!player)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // .removequest #entry'
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hquest");
    if (!cId)
        return false;

    uint32 entry = atol(cId);

    Quest const* pQuest = objmgr.GetQuestTemplate(entry);

    if (!pQuest)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }

    // remove all quest entries for 'entry' from quest log
    for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 quest = player->GetQuestSlotQuestId(slot);
        if (quest == entry)
        {
            player->SetQuestSlot(slot,0);

            // we ignore unequippable quest items in this case, its' still be equipped
            player->TakeQuestSourceItem(quest, false);
        }
    }

    // set quest status to not started (will updated in DB at next save)
    player->SetQuestStatus(entry, QUEST_STATUS_NONE);

    // reset rewarded for restart repeatable quest
    player->getQuestStatusMap()[entry].m_rewarded = false;

    SendSysMessage(LANG_COMMAND_QUEST_REMOVED);
    return true;
}

bool ChatHandler::HandleQuestComplete(const char *args)
{
    Player* player = getSelectedPlayer();
    if (!player)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // .quest complete #entry
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    char* cId = extractKeyFromLink((char*)args,"Hquest");
    if (!cId)
        return false;

    uint32 entry = atol(cId);

    Quest const* pQuest = objmgr.GetQuestTemplate(entry);

    // If player doesn't have the quest
    if (!pQuest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }

    // Add quest items for quests that require items
    for (uint8 x = 0; x < QUEST_ITEM_OBJECTIVES_COUNT; ++x)
    {
        uint32 id = pQuest->ReqItemId[x];
        uint32 count = pQuest->ReqItemCount[x];
        if (!id || !count)
            continue;

        uint32 curItemCount = player->GetItemCount(id,true);

        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, id, count-curItemCount);
        if (msg == EQUIP_ERR_OK)
        {
            Item* item = player->StoreNewItem(dest, id, true);
            player->SendNewItem(item,count-curItemCount,true,false);
        }
    }

    // All creature/GO slain/casted (not required, but otherwise it will display "Creature slain 0/10")
    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        uint32 creature = pQuest->ReqCreatureOrGOId[i];
        uint32 creaturecount = pQuest->ReqCreatureOrGOCount[i];

        if (uint32 spell_id = pQuest->ReqSpell[i])
        {
            for (uint16 z = 0; z < creaturecount; ++z)
                player->CastedCreatureOrGO(creature,0,spell_id);
        }
        else if (creature > 0)
        {
            if (CreatureInfo const* cInfo = objmgr.GetCreatureTemplate(creature))
                for (uint16 z = 0; z < creaturecount; ++z)
                    player->KilledMonster(cInfo,0);
        }
        else if (creature < 0)
        {
            for (uint16 z = 0; z < creaturecount; ++z)
                player->CastedCreatureOrGO(creature,0,0);
        }
    }

    // If the quest requires reputation to complete
    if (uint32 repFaction = pQuest->GetRepObjectiveFaction())
    {
        uint32 repValue = pQuest->GetRepObjectiveValue();
        uint32 curRep = player->GetReputationMgr().GetReputation(repFaction);
        if (curRep < repValue)
            if (FactionEntry const *factionEntry = sFactionStore.LookupEntry(repFaction))
                player->GetReputationMgr().SetReputation(factionEntry,repValue);
    }

    // If the quest requires a SECOND reputation to complete
    if (uint32 repFaction = pQuest->GetRepObjectiveFaction2())
    {
        uint32 repValue2 = pQuest->GetRepObjectiveValue2();
        uint32 curRep = player->GetReputationMgr().GetReputation(repFaction);
        if (curRep < repValue2)
            if (FactionEntry const *factionEntry = sFactionStore.LookupEntry(repFaction))
                player->GetReputationMgr().SetReputation(factionEntry,repValue2);
    }

    // If the quest requires money
    int32 ReqOrRewMoney = pQuest->GetRewOrReqMoney();
    if (ReqOrRewMoney < 0)
        player->ModifyMoney(-ReqOrRewMoney);

    player->CompleteQuest(entry);
    return true;
}

bool ChatHandler::HandleBanAccountCommand(const char *args)
{
    return HandleBanHelper(BAN_ACCOUNT,args);
}

bool ChatHandler::HandleBanCharacterCommand(const char *args)
{
    return HandleBanHelper(BAN_CHARACTER,args);
}

bool ChatHandler::HandleBanIPCommand(const char *args)
{
    return HandleBanHelper(BAN_IP,args);
}

bool ChatHandler::HandleBanHelper(BanMode mode, const char *args)
{
    if (!*args)
        return false;

    char* cnameOrIP = strtok ((char*)args, " ");
    if (!cnameOrIP)
        return false;

    std::string nameOrIP = cnameOrIP;

    char* duration = strtok (NULL," ");
    if (!duration || !atoi(duration))
        return false;

    char* reason = strtok (NULL,"");
    if (!reason)
        return false;

    switch(mode)
    {
        case BAN_ACCOUNT:
            if (!AccountMgr::normalizeString(nameOrIP))
            {
                PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,nameOrIP.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_CHARACTER:
            if (!normalizePlayerName(nameOrIP))
            {
                SendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_IP:
            if (!IsIPAddress(nameOrIP.c_str()))
                return false;
            break;
    }

    switch(sWorld.BanAccount(mode, nameOrIP, duration, reason,m_session ? m_session->GetPlayerName() : ""))
    {
        case BAN_SUCCESS:
            if (atoi(duration)>0)
                PSendSysMessage(LANG_BAN_YOUBANNED,nameOrIP.c_str(),secsToTimeString(TimeStringToSecs(duration),true).c_str(),reason);
            else
                PSendSysMessage(LANG_BAN_YOUPERMBANNED,nameOrIP.c_str(),reason);
            break;
        case BAN_SYNTAX_ERROR:
            return false;
        case BAN_NOTFOUND:
            switch(mode)
            {
                default:
                    PSendSysMessage(LANG_BAN_NOTFOUND,"account",nameOrIP.c_str());
                    break;
                case BAN_CHARACTER:
                    PSendSysMessage(LANG_BAN_NOTFOUND,"character",nameOrIP.c_str());
                    break;
                case BAN_IP:
                    PSendSysMessage(LANG_BAN_NOTFOUND,"ip",nameOrIP.c_str());
                    break;
            }
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

bool ChatHandler::HandleUnBanAccountCommand(const char *args)
{
    return HandleUnBanHelper(BAN_ACCOUNT,args);
}

bool ChatHandler::HandleUnBanCharacterCommand(const char *args)
{
    return HandleUnBanHelper(BAN_CHARACTER,args);
}

bool ChatHandler::HandleUnBanIPCommand(const char *args)
{
    return HandleUnBanHelper(BAN_IP,args);
}

bool ChatHandler::HandleUnBanHelper(BanMode mode, const char *args)
{
    if (!*args)
        return false;

    char* cnameOrIP = strtok ((char*)args, " ");
    if (!cnameOrIP)
        return false;

    std::string nameOrIP = cnameOrIP;

    switch(mode)
    {
        case BAN_ACCOUNT:
            if (!AccountMgr::normalizeString(nameOrIP))
            {
                PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,nameOrIP.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_CHARACTER:
            if (!normalizePlayerName(nameOrIP))
            {
                SendSysMessage(LANG_PLAYER_NOT_FOUND);
                SetSentErrorMessage(true);
                return false;
            }
            break;
        case BAN_IP:
            if (!IsIPAddress(nameOrIP.c_str()))
                return false;
            break;
    }

    if (sWorld.RemoveBanAccount(mode,nameOrIP))
        PSendSysMessage(LANG_UNBAN_UNBANNED,nameOrIP.c_str());
    else
        PSendSysMessage(LANG_UNBAN_ERROR,nameOrIP.c_str());

    return true;
}

bool ChatHandler::HandleBanInfoAccountCommand(const char *args)
{
    if (!*args)
        return false;

    char* cname = strtok((char*)args, "");
    if (!cname)
        return false;

    std::string account_name = cname;
    if (!AccountMgr::normalizeString(account_name))
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    uint32 accountid = accmgr.GetId(account_name);
    if (!accountid)
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        return true;
    }

    return HandleBanInfoHelper(accountid,account_name.c_str());
}

bool ChatHandler::HandleBanInfoCharacterCommand(const char *args)
{
    Player* target;
    uint64 target_guid;
    if (!extractPlayerTarget((char*)args,&target,&target_guid))
        return false;

    uint32 accountid = target ? target->GetSession()->GetAccountId() : objmgr.GetPlayerAccountIdByGUID(target_guid);

    std::string accountname;
    if (!accmgr.GetName(accountid,accountname))
    {
        PSendSysMessage(LANG_BANINFO_NOCHARACTER);
        return true;
    }

    return HandleBanInfoHelper(accountid,accountname.c_str());
}

bool ChatHandler::HandleBanInfoHelper(uint32 accountid, char const* accountname)
{
    QueryResult_AutoPtr result = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(bandate), unbandate-bandate, active, unbandate,banreason,bannedby FROM account_banned WHERE id = '%u' ORDER BY bandate ASC",accountid);
    if (!result)
    {
        PSendSysMessage(LANG_BANINFO_NOACCOUNTBAN, accountname);
        return true;
    }

    PSendSysMessage(LANG_BANINFO_BANHISTORY,accountname);
    do
    {
        Field* fields = result->Fetch();

        time_t unbandate = time_t(fields[3].GetUInt64());
        bool active = false;
        if (fields[2].GetBool() && (fields[1].GetUInt64() == (uint64)0 ||unbandate >= time(NULL)))
            active = true;
        bool permanent = (fields[1].GetUInt64() == (uint64)0);
        std::string bantime = permanent?GetTrinityString(LANG_BANINFO_INFINITE):secsToTimeString(fields[1].GetUInt64(), true);
        PSendSysMessage(LANG_BANINFO_HISTORYENTRY,
            fields[0].GetString(), bantime.c_str(), active ? GetTrinityString(LANG_BANINFO_YES):GetTrinityString(LANG_BANINFO_NO), fields[4].GetString(), fields[5].GetString());
    }while (result->NextRow());

    return true;
}

bool ChatHandler::HandleBanInfoIPCommand(const char *args)
{
    if (!*args)
        return false;

    char* cIP = strtok ((char*)args, "");
    if (!cIP)
        return false;

    if (!IsIPAddress(cIP))
        return false;

    std::string IP = cIP;

    LoginDatabase.escape_string(IP);
    QueryResult_AutoPtr result = LoginDatabase.PQuery("SELECT ip, FROM_UNIXTIME(bandate), FROM_UNIXTIME(unbandate), unbandate-UNIX_TIMESTAMP(), banreason,bannedby,unbandate-bandate FROM ip_banned WHERE ip = '%s'",IP.c_str());
    if (!result)
    {
        PSendSysMessage(LANG_BANINFO_NOIP);
        return true;
    }

    Field *fields = result->Fetch();
    bool permanent = !fields[6].GetUInt64();
    PSendSysMessage(LANG_BANINFO_IPENTRY,
        fields[0].GetString(), fields[1].GetString(), permanent ? GetTrinityString(LANG_BANINFO_NEVER):fields[2].GetString(),
        permanent ? GetTrinityString(LANG_BANINFO_INFINITE):secsToTimeString(fields[3].GetUInt64(), true).c_str(), fields[4].GetString(), fields[5].GetString());

    return true;
}

bool ChatHandler::HandleBanListCharacterCommand(const char *args)
{
    LoginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate<>bandate");

    char* cFilter = strtok ((char*)args, " ");
    if (!cFilter)
        return false;

    std::string filter = cFilter;
    LoginDatabase.escape_string(filter);
    QueryResult_AutoPtr result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name "_LIKE_" "_CONCAT3_("'%%'","'%s'","'%%'"),filter.c_str());
    if (!result)
    {
        PSendSysMessage(LANG_BANLIST_NOCHARACTER);
        return true;
    }

    return HandleBanListHelper(result);
}

bool ChatHandler::HandleBanListAccountCommand(const char *args)
{
    LoginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate<>bandate");

    char* cFilter = strtok((char*)args, " ");
    std::string filter = cFilter ? cFilter : "";
    LoginDatabase.escape_string(filter);

    QueryResult_AutoPtr result;

    if (filter.empty())
    {
        result = LoginDatabase.Query("SELECT account.id, username FROM account, account_banned"
            " WHERE account.id = account_banned.id AND active = 1 GROUP BY account.id");
    }
    else
    {
        result = LoginDatabase.PQuery("SELECT account.id, username FROM account, account_banned"
            " WHERE account.id = account_banned.id AND active = 1 AND username "_LIKE_" "_CONCAT3_("'%%'","'%s'","'%%'")" GROUP BY account.id",
            filter.c_str());
    }

    if (!result)
    {
        PSendSysMessage(LANG_BANLIST_NOACCOUNT);
        return true;
    }

    return HandleBanListHelper(result);
}

bool ChatHandler::HandleBanListHelper(QueryResult_AutoPtr result)
{
    PSendSysMessage(LANG_BANLIST_MATCHINGACCOUNT);

    // Chat short output
    if (m_session)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 accountid = fields[0].GetUInt32();

            QueryResult_AutoPtr banresult = LoginDatabase.PQuery("SELECT account.username FROM account,account_banned WHERE account_banned.id='%u' AND account_banned.id=account.id",accountid);
            if (banresult)
            {
                Field* fields2 = banresult->Fetch();
                PSendSysMessage("%s",fields2[0].GetString());
            }
        } while (result->NextRow());
    }
    // Console wide output
    else
    {
        SendSysMessage(LANG_BANLIST_ACCOUNTS);
        SendSysMessage(" ===============================================================================");
        SendSysMessage(LANG_BANLIST_ACCOUNTS_HEADER);
        do
        {
            SendSysMessage("-------------------------------------------------------------------------------");
            Field *fields = result->Fetch();
            uint32 account_id = fields[0].GetUInt32 ();

            std::string account_name;

            // "account" case, name can be get in same query
            if (result->GetFieldCount() > 1)
                account_name = fields[1].GetCppString();
            // "character" case, name need extract from another DB
            else
                accmgr.GetName (account_id,account_name);

            // No SQL injection. id is uint32.
            QueryResult_AutoPtr banInfo = LoginDatabase.PQuery("SELECT bandate,unbandate,bannedby,banreason FROM account_banned WHERE id = %u ORDER BY unbandate", account_id);
            if (banInfo)
            {
                Field *fields2 = banInfo->Fetch();
                do
                {
                    time_t t_ban = fields2[0].GetUInt64();
                    tm* aTm_ban = localtime(&t_ban);

                    if (fields2[0].GetUInt64() == fields2[1].GetUInt64())
                    {
                        PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|   permanent  |%-15.15s|%-15.15s|",
                            account_name.c_str(),aTm_ban->tm_year%100, aTm_ban->tm_mon+1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                            fields2[2].GetString(),fields2[3].GetString());
                    }
                    else
                    {
                        time_t t_unban = fields2[1].GetUInt64();
                        tm* aTm_unban = localtime(&t_unban);
                        PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|%02d-%02d-%02d %02d:%02d|%-15.15s|%-15.15s|",
                            account_name.c_str(),aTm_ban->tm_year%100, aTm_ban->tm_mon+1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                            aTm_unban->tm_year%100, aTm_unban->tm_mon+1, aTm_unban->tm_mday, aTm_unban->tm_hour, aTm_unban->tm_min,
                            fields2[2].GetString(),fields2[3].GetString());
                    }
                }while (banInfo->NextRow());
            }
        }while (result->NextRow());
        SendSysMessage(" ===============================================================================");
    }
    return true;
}

bool ChatHandler::HandleBanListIPCommand(const char *args)
{
    LoginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate<>bandate");

    char* cFilter = strtok((char*)args, " ");
    std::string filter = cFilter ? cFilter : "";
    LoginDatabase.escape_string(filter);

    QueryResult_AutoPtr result;

    if (filter.empty())
    {
        result = LoginDatabase.Query ("SELECT ip,bandate,unbandate,bannedby,banreason FROM ip_banned"
            " WHERE (bandate=unbandate OR unbandate>UNIX_TIMESTAMP())"
            " ORDER BY unbandate");
    }
    else
    {
        result = LoginDatabase.PQuery("SELECT ip,bandate,unbandate,bannedby,banreason FROM ip_banned"
            " WHERE (bandate=unbandate OR unbandate>UNIX_TIMESTAMP()) AND ip "_LIKE_" "_CONCAT3_("'%%'","'%s'","'%%'")
            " ORDER BY unbandate",filter.c_str());
    }

    if (!result)
    {
        PSendSysMessage(LANG_BANLIST_NOIP);
        return true;
    }

    PSendSysMessage(LANG_BANLIST_MATCHINGIP);
    // Chat short output
    if (m_session)
    {
        do
        {
            Field* fields = result->Fetch();
            PSendSysMessage("%s",fields[0].GetString());
        } while (result->NextRow());
    }
    // Console wide output
    else
    {
        SendSysMessage(LANG_BANLIST_IPS);
        SendSysMessage(" ===============================================================================");
        SendSysMessage(LANG_BANLIST_IPS_HEADER);
        do
        {
            SendSysMessage("-------------------------------------------------------------------------------");
            Field *fields = result->Fetch();
            time_t t_ban = fields[1].GetUInt64();
            tm* aTm_ban = localtime(&t_ban);
            if (fields[1].GetUInt64() == fields[2].GetUInt64())
            {
                PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|   permanent  |%-15.15s|%-15.15s|",
                    fields[0].GetString(), aTm_ban->tm_year%100, aTm_ban->tm_mon+1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                    fields[3].GetString(), fields[4].GetString());
            }
            else
            {
                time_t t_unban = fields[2].GetUInt64();
                tm* aTm_unban = localtime(&t_unban);
                PSendSysMessage("|%-15.15s|%02d-%02d-%02d %02d:%02d|%02d-%02d-%02d %02d:%02d|%-15.15s|%-15.15s|",
                    fields[0].GetString(), aTm_ban->tm_year%100, aTm_ban->tm_mon+1, aTm_ban->tm_mday, aTm_ban->tm_hour, aTm_ban->tm_min,
                    aTm_unban->tm_year%100, aTm_unban->tm_mon+1, aTm_unban->tm_mday, aTm_unban->tm_hour, aTm_unban->tm_min,
                    fields[3].GetString(), fields[4].GetString());
            }
        }while (result->NextRow());
        SendSysMessage(" ===============================================================================");
    }

    return true;
}

bool ChatHandler::HandleRespawnCommand(const char* /*args*/)
{
    Player* pl = m_session->GetPlayer();

    // accept only explicitly selected target (not implicitly self targeting case)
    Unit* target = getSelectedUnit();
    if (pl->GetSelection() && target)
    {
        if (target->GetTypeId() != TYPEID_UNIT || target->isPet())
        {
            SendSysMessage(LANG_SELECT_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }

        if (target->isDead())
            target->ToCreature()->Respawn();
        return true;
    }

    CellPair p(Trinity::ComputeCellPair(pl->GetPositionX(), pl->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::RespawnDo u_do;
    Trinity::WorldObjectWorker<Trinity::RespawnDo> worker(pl,u_do);

    TypeContainerVisitor<Trinity::WorldObjectWorker<Trinity::RespawnDo>, GridTypeMapContainer > obj_worker(worker);
    cell.Visit(p, obj_worker, *pl->GetMap());

    return true;
}

bool ChatHandler::HandleGMFlyCommand(const char *args)
{
    if (!*args)
        return false;

    Player *target = getSelectedPlayer();
    if (!target)
        target = m_session->GetPlayer();

    WorldPacket data(12);
    if (strncmp(args, "on", 3) == 0)
        data.SetOpcode(SMSG_MOVE_SET_CAN_FLY);
    else if (strncmp(args, "off", 4) == 0)
        data.SetOpcode(SMSG_MOVE_UNSET_CAN_FLY);
    else
    {
        SendSysMessage(LANG_USE_BOL);
        return false;
    }
    data.append(target->GetPackGUID());
    data << uint32(0);                                      // unknown
    target->SendMessageToSet(&data, true);
    PSendSysMessage(LANG_COMMAND_FLYMODE_STATUS, GetNameLink(target).c_str(), args);
    return true;
}

bool ChatHandler::HandlePDumpLoadCommand(const char *args)
{
    if (!*args)
        return false;

    char * file = strtok((char*)args, " ");
    if (!file)
        return false;

    char * account = strtok(NULL, " ");
    if (!account)
        return false;

    std::string account_name = account;
    if (!AccountMgr::normalizeString(account_name))
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    uint32 account_id = accmgr.GetId(account_name);
    if (!account_id)
    {
        account_id = atoi(account);                             // use original string
        if (!account_id)
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        }
    }

    if (!accmgr.GetName(account_id,account_name))
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    char* guid_str = NULL;
    char* name_str = strtok(NULL, " ");

    std::string name;
    if (name_str)
    {
        name = name_str;
        // normalize the name if specified and check if it exists
        if (!normalizePlayerName(name))
        {
            PSendSysMessage(LANG_INVALID_CHARACTER_NAME);
            SetSentErrorMessage(true);
            return false;
        }

        if (ObjectMgr::CheckPlayerName(name,true) != CHAR_NAME_SUCCESS)
        {
            PSendSysMessage(LANG_INVALID_CHARACTER_NAME);
            SetSentErrorMessage(true);
            return false;
        }

        guid_str = strtok(NULL, " ");
    }

    uint32 guid = 0;

    if (guid_str)
    {
        guid = atoi(guid_str);
        if (!guid)
        {
            PSendSysMessage(LANG_INVALID_CHARACTER_GUID);
            SetSentErrorMessage(true);
            return false;
        }

        if (objmgr.GetPlayerAccountIdByGUID(guid))
        {
            PSendSysMessage(LANG_CHARACTER_GUID_IN_USE,guid);
            SetSentErrorMessage(true);
            return false;
        }
    }

    switch(PlayerDumpReader().LoadDump(file, account_id, name, guid))
    {
        case DUMP_SUCCESS:
            PSendSysMessage(LANG_COMMAND_IMPORT_SUCCESS);
            break;
        case DUMP_FILE_OPEN_ERROR:
            PSendSysMessage(LANG_FILE_OPEN_FAIL,file);
            SetSentErrorMessage(true);
            return false;
        case DUMP_FILE_BROKEN:
            PSendSysMessage(LANG_DUMP_BROKEN,file);
            SetSentErrorMessage(true);
            return false;
        case DUMP_TOO_MANY_CHARS:
            PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL,account_name.c_str(),account_id);
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_COMMAND_IMPORT_FAILED);
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

bool ChatHandler::HandlePDumpWriteCommand(const char *args)
{
    if (!*args)
        return false;

    char* file = strtok((char*)args, " ");
    char* p2 = strtok(NULL, " ");

    if (!file || !p2)
        return false;

    uint32 guid;
    // character name can't start from number
    if (isNumeric(p2))
        guid = atoi(p2);
    else
    {
        std::string name = extractPlayerNameFromLink(p2);
        if (name.empty())
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        guid = objmgr.GetPlayerGUIDByName(name);
    }

    if (!objmgr.GetPlayerAccountIdByGUID(guid))
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    switch(PlayerDumpWriter().WriteDump(file, guid))
    {
        case DUMP_SUCCESS:
            PSendSysMessage(LANG_COMMAND_EXPORT_SUCCESS);
            break;
        case DUMP_FILE_OPEN_ERROR:
            PSendSysMessage(LANG_FILE_OPEN_FAIL,file);
            SetSentErrorMessage(true);
            return false;
        case DUMP_CHARACTER_DELETED:
            PSendSysMessage(LANG_COMMAND_EXPORT_DELETED_CHAR);
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_COMMAND_EXPORT_FAILED);
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

bool ChatHandler::HandleMovegensCommand(const char* /*args*/)
{
    Unit* unit = getSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_MOVEGENS_LIST,(unit->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"),unit->GetGUIDLow());

    MotionMaster* mm = unit->GetMotionMaster();
    for (uint8 i = 0; i < MAX_MOTION_SLOT; ++i)
    {
        MovementGenerator* mg = mm->GetMotionSlot(i);
        if (!mg)
        {
            SendSysMessage("Empty");
            continue;
        }
        switch(mg->GetMovementGeneratorType())
        {
            case IDLE_MOTION_TYPE:          SendSysMessage(LANG_MOVEGENS_IDLE);          break;
            case RANDOM_MOTION_TYPE:        SendSysMessage(LANG_MOVEGENS_RANDOM);        break;
            case WAYPOINT_MOTION_TYPE:      SendSysMessage(LANG_MOVEGENS_WAYPOINT);      break;
            case ANIMAL_RANDOM_MOTION_TYPE: SendSysMessage(LANG_MOVEGENS_ANIMAL_RANDOM); break;
            case CONFUSED_MOTION_TYPE:      SendSysMessage(LANG_MOVEGENS_CONFUSED);      break;
            case TARGETED_MOTION_TYPE:
            {
                if (unit->GetTypeId() == TYPEID_PLAYER)
                {
                    TargetedMovementGenerator<Player> const* mgen = static_cast<TargetedMovementGenerator<Player> const*>(mg);
                    Unit* target = mgen->GetTarget();
                    if (target)
                        PSendSysMessage(LANG_MOVEGENS_TARGETED_PLAYER,target->GetName(),target->GetGUIDLow());
                    else
                        SendSysMessage(LANG_MOVEGENS_TARGETED_NULL);
                }
                else
                {
                    TargetedMovementGenerator<Creature> const* mgen = static_cast<TargetedMovementGenerator<Creature> const*>(mg);
                    Unit* target = mgen->GetTarget();
                    if (target)
                        PSendSysMessage(LANG_MOVEGENS_TARGETED_CREATURE,target->GetName(),target->GetGUIDLow());
                    else
                        SendSysMessage(LANG_MOVEGENS_TARGETED_NULL);
                }
                break;
            }
            case HOME_MOTION_TYPE:
                if (unit->GetTypeId() == TYPEID_UNIT)
                {
                    float x,y,z;
                    mg->GetDestination(x,y,z);
                    PSendSysMessage(LANG_MOVEGENS_HOME_CREATURE,x,y,z);
                }
                else
                    SendSysMessage(LANG_MOVEGENS_HOME_PLAYER);
                break;
            case FLIGHT_MOTION_TYPE:   SendSysMessage(LANG_MOVEGENS_FLIGHT);  break;
            case POINT_MOTION_TYPE:
            {
                float x,y,z;
                mg->GetDestination(x,y,z);
                PSendSysMessage(LANG_MOVEGENS_POINT,x,y,z);
                break;
            }
            case FLEEING_MOTION_TYPE:  SendSysMessage(LANG_MOVEGENS_FEAR);    break;
            case DISTRACT_MOTION_TYPE: SendSysMessage(LANG_MOVEGENS_DISTRACT);  break;
            default:
                PSendSysMessage(LANG_MOVEGENS_UNKNOWN,mg->GetMovementGeneratorType());
                break;
        }
    }
    return true;
}

bool ChatHandler::HandleServerPLimitCommand(const char *args)
{
    if (*args)
    {
        char* param = strtok((char*)args, " ");
        if (!param)
            return false;

        int l = strlen(param);

        if (strncmp(param,"player",l) == 0)
            sWorld.SetPlayerSecurityLimit(SEC_PLAYER);
        else if (strncmp(param,"moderator",l) == 0)
            sWorld.SetPlayerSecurityLimit(SEC_MODERATOR);
        else if (strncmp(param,"gamemaster",l) == 0)
            sWorld.SetPlayerSecurityLimit(SEC_GAMEMASTER);
        else if (strncmp(param,"administrator",l) == 0)
            sWorld.SetPlayerSecurityLimit(SEC_ADMINISTRATOR);
        else if (strncmp(param,"reset",l) == 0)
            sWorld.SetPlayerLimit(sConfig.GetIntDefault("PlayerLimit", DEFAULT_PLAYER_LIMIT));
        else
        {
            int val = atoi(param);
            if (val < 0)
                sWorld.SetPlayerSecurityLimit(AccountTypes(uint32(-val)));
            else
                sWorld.SetPlayerLimit(val);
        }

        // kick all low security level players
        if (sWorld.GetPlayerSecurityLimit() > SEC_PLAYER)
            sWorld.KickAllLess(sWorld.GetPlayerSecurityLimit());
    }

    uint32 pLimit = sWorld.GetPlayerAmountLimit();
    AccountTypes allowedAccountType = sWorld.GetPlayerSecurityLimit();
    char const* secName = "";
    switch(allowedAccountType)
    {
        case SEC_PLAYER:        secName = "Player";        break;
        case SEC_MODERATOR:     secName = "Moderator";     break;
        case SEC_GAMEMASTER:    secName = "Gamemaster";    break;
        case SEC_ADMINISTRATOR: secName = "Administrator"; break;
        default:                secName = "<unknown>";     break;
    }

    PSendSysMessage("Player limits: amount %u, min. security level %s.",pLimit,secName);

    return true;
}

bool ChatHandler::HandleCastCommand(const char *args)
{
    if (!*args)
        return false;

    Unit* target = getSelectedUnit();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = extractSpellIdFromLink((char*)args);
    if (!spell)
        return false;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
    if (!spellInfo)
    {
        PSendSysMessage(LANG_COMMAND_NOSPELLFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    if (!SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spell);
        SetSentErrorMessage(true);
        return false;
    }

    char* trig_str = strtok(NULL, " ");
    if (trig_str)
    {
        int l = strlen(trig_str);
        if (strncmp(trig_str,"triggered",l) != 0)
            return false;
    }

    bool triggered = (trig_str != NULL);

    m_session->GetPlayer()->CastSpell(target,spell,triggered);

    return true;
}

bool ChatHandler::HandleCastBackCommand(const char *args)
{
    Creature* caster = getSelectedCreature();

    if (!caster)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = extractSpellIdFromLink((char*)args);
    if (!spell || !sSpellStore.LookupEntry(spell))
    {
        PSendSysMessage(LANG_COMMAND_NOSPELLFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    char* trig_str = strtok(NULL, " ");
    if (trig_str)
    {
        int l = strlen(trig_str);
        if (strncmp(trig_str,"triggered",l) != 0)
            return false;
    }

    bool triggered = (trig_str != NULL);

    caster->SetFacingToObject(m_session->GetPlayer());

    caster->CastSpell(m_session->GetPlayer(),spell,triggered);

    return true;
}

bool ChatHandler::HandleCastDistCommand(const char *args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = extractSpellIdFromLink((char*)args);
    if (!spell)
        return false;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
    if (!spellInfo)
    {
        PSendSysMessage(LANG_COMMAND_NOSPELLFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    if (!SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spell);
        SetSentErrorMessage(true);
        return false;
    }

    char *distStr = strtok(NULL, " ");

    float dist = 0;

    if (distStr)
        sscanf(distStr, "%f", &dist);

    char* trig_str = strtok(NULL, " ");
    if (trig_str)
    {
        int l = strlen(trig_str);
        if (strncmp(trig_str,"triggered",l) != 0)
            return false;
    }

    bool triggered = (trig_str != NULL);

    float x,y,z;
    m_session->GetPlayer()->GetClosePoint(x,y,z,dist);

    m_session->GetPlayer()->CastSpell(x,y,z,spell,triggered);
    return true;
}

bool ChatHandler::HandleCastTargetCommand(const char *args)
{
    Creature* caster = getSelectedCreature();

    if (!caster)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!caster->getVictim())
    {
        SendSysMessage(LANG_SELECTED_TARGET_NOT_HAVE_VICTIM);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = extractSpellIdFromLink((char*)args);
    if (!spell || !sSpellStore.LookupEntry(spell))
    {
        PSendSysMessage(LANG_COMMAND_NOSPELLFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    char* trig_str = strtok(NULL, " ");
    if (trig_str)
    {
        int l = strlen(trig_str);
        if (strncmp(trig_str,"triggered",l) != 0)
            return false;
    }

    bool triggered = (trig_str != NULL);

    caster->SetFacingToObject(m_session->GetPlayer());

    caster->CastSpell(caster->getVictim(),spell,triggered);

    return true;
}

/*
ComeToMe command REQUIRED for 3rd party scripting library to have access to PointMovementGenerator
Without this function 3rd party scripting library will get linking errors (unresolved external)
when attempting to use the PointMovementGenerator
*/
bool ChatHandler::HandleComeToMeCommand(const char *args)
{
    char* newFlagStr = strtok((char*)args, " ");

    if (!newFlagStr)
        return false;

    uint32 newFlags = (uint32)strtoul(newFlagStr, NULL, 0);

    Creature* caster = getSelectedCreature();
    if (!caster)
    {
        m_session->GetPlayer()->SetUnitMovementFlags(newFlags);
        SendSysMessage(LANG_SELECT_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    caster->SetUnitMovementFlags(newFlags);

    Player* pl = m_session->GetPlayer();

    caster->GetMotionMaster()->MovePoint(0, pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ());
    return true;
}

bool ChatHandler::HandleCastSelfCommand(const char *args)
{
    if (!*args)
        return false;

    Unit* target = getSelectedUnit();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = extractSpellIdFromLink((char*)args);
    if (!spell)
        return false;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
    if (!spellInfo)
        return false;

    if (!SpellMgr::IsSpellValid(spellInfo,m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN,spell);
        SetSentErrorMessage(true);
        return false;
    }

    target->CastSpell(target,spell,false);

    return true;
}

std::string GetTimeString(uint32 time)
{
    uint16 days = time / DAY, hours = (time % DAY) / HOUR, minute = (time % HOUR) / MINUTE;
    std::ostringstream ss;
    if (days) ss << days << "d ";
    if (hours) ss << hours << "h ";
    ss << minute << "m";
    return ss.str();
}

bool ChatHandler::HandleInstanceListBindsCommand(const char* /*args*/)
{
    Player* player = getSelectedPlayer();
    if (!player) player = m_session->GetPlayer();
    uint32 counter = 0;
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
        for (Player::BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end(); ++itr)
        {
            InstanceSave *save = itr->second.save;
            std::string timeleft = GetTimeString(save->GetResetTime() - time(NULL));
            PSendSysMessage("map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no",  save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
            counter++;
        }
    }
    PSendSysMessage("player binds: %d", counter);
    counter = 0;
    Group *group = player->GetGroup();
    if (group)
    {
        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        {
            Group::BoundInstancesMap &binds = group->GetBoundInstances(Difficulty(i));
            for (Group::BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end(); ++itr)
            {
                InstanceSave *save = itr->second.save;
                std::string timeleft = GetTimeString(save->GetResetTime() - time(NULL));
                PSendSysMessage("map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no",  save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());                counter++;
            }
        }
    }
    PSendSysMessage("group binds: %d", counter);

    return true;
}

bool ChatHandler::HandleInstanceUnbindCommand(const char *args)
{
    if (!*args)
        return false;

    std::string cmd = args;
    if (cmd == "all")
    {
        Player* player = getSelectedPlayer();
        if (!player) player = m_session->GetPlayer();
        uint32 counter = 0;
        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        {
            Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
            for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
            {
                if (itr->first != player->GetMapId())
                {
                    InstanceSave *save = itr->second.save;
                    std::string timeleft = GetTimeString(save->GetResetTime() - time(NULL));
                    PSendSysMessage("unbinding map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no",  save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                    player->UnbindInstance(itr, Difficulty(i));
                    counter++;
                }
                else
                    ++itr;
            }
        }
        PSendSysMessage("instances unbound: %d", counter);
    }
    return true;
}

bool ChatHandler::HandleInstanceStatsCommand(const char* /*args*/)
{
    PSendSysMessage("instances loaded: %d", sMapMgr.GetNumInstances());
    PSendSysMessage("players in instances: %d", sMapMgr.GetNumPlayersInInstances());
    PSendSysMessage("instance saves: %d", sInstanceSaveManager.GetNumInstanceSaves());
    PSendSysMessage("players bound: %d", sInstanceSaveManager.GetNumBoundPlayersTotal());
    PSendSysMessage("groups bound: %d", sInstanceSaveManager.GetNumBoundGroupsTotal());
    return true;
}

bool ChatHandler::HandleInstanceSaveDataCommand(const char * /*args*/)
{
    Player* pl = m_session->GetPlayer();

    Map* map = pl->GetMap();
    if (!map->IsDungeon())
    {
        PSendSysMessage("Map is not a dungeon.");
        SetSentErrorMessage(true);
        return false;
    }

    if (!((InstanceMap*)map)->GetInstanceData())
    {
        PSendSysMessage("Map has no instance data.");
        SetSentErrorMessage(true);
        return false;
    }

    ((InstanceMap*)map)->GetInstanceData()->SaveToDB();
    return true;
}

/// Display the list of GMs
bool ChatHandler::HandleGMListFullCommand(const char* /*args*/)
{
    ///- Get the accounts with GM Level >0
    QueryResult_AutoPtr result = LoginDatabase.Query("SELECT a.username,aa.gmlevel FROM account a, account_access aa WHERE a.id=aa.id AND aa.gmlevel > 0");
    if (result)
    {
        SendSysMessage(LANG_GMLIST);
        SendSysMessage(" ======================== ");
        SendSysMessage(LANG_GMLIST_HEADER);
        SendSysMessage(" ======================== ");

        ///- Circle through them. Display username and GM level
        do
        {
            Field *fields = result->Fetch();
            PSendSysMessage("|%15s|%6s|", fields[0].GetString(),fields[1].GetString());
        }while (result->NextRow());

        PSendSysMessage(" ======================== ");
    }
    else
        PSendSysMessage(LANG_GMLIST_EMPTY);
    return true;
}

/// Define the 'Message of the day' for the realm
bool ChatHandler::HandleServerSetMotdCommand(const char *args)
{
    sWorld.SetMotd(args);
    PSendSysMessage(LANG_MOTD_NEW, args);
    return true;
}

/// Set whether we accept new clients
bool ChatHandler::HandleServerSetClosedCommand(const char *args)
{
    std::string arg = args;

    if (strncmp(args, "on", 3) == 0)
    {
        SendSysMessage(LANG_WORLD_CLOSED);
        sWorld.SetClosed(true);
        return true;
    }
    else if (strncmp(args, "off", 4) == 0)
    {
        SendSysMessage(LANG_WORLD_OPENED);
        sWorld.SetClosed(false);
        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

/// Set/Unset the expansion level for an account
bool ChatHandler::HandleAccountSetAddonCommand(const char *args)
{
    ///- Get the command line arguments
    char *szAcc = strtok((char*)args," ");
    char *szExp = strtok(NULL," ");

    if (!szAcc)
        return false;

    std::string account_name;
    uint32 account_id;

    if (!szExp)
    {
        Player* player = getSelectedPlayer();
        if (!player)
            return false;

        account_id = player->GetSession()->GetAccountId();
        accmgr.GetName(account_id,account_name);
        szExp = szAcc;
    }
    else
    {
        ///- Convert Account name to Upper Format
        account_name = szAcc;
        if (!AccountMgr::normalizeString(account_name))
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        account_id = accmgr.GetId(account_name);
        if (!account_id)
        {
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        }

    }

    // Let set addon state only for lesser (strong) security level
    // or to self account
    if (m_session && m_session->GetAccountId () != account_id &&
        HasLowerSecurityAccount (NULL,account_id,true))
        return false;

    int expansion = atoi(szExp);                                    //get int anyway (0 if error)
    if (expansion < 0 || expansion > sWorld.getConfig(CONFIG_EXPANSION))
         return false;

    // No SQL injection
    LoginDatabase.PExecute("UPDATE account SET expansion = '%d' WHERE id = '%u'",expansion,account_id);
    PSendSysMessage(LANG_ACCOUNT_SETADDON,account_name.c_str(),account_id,expansion);
    return true;
}

//Send items by mail
bool ChatHandler::HandleSendItemsCommand(const char *args)
{
    // format: name "subject text" "mail text" item1[:count1] item2[:count2] ... item12[:count12]
    Player* receiver;
    uint64 receiver_guid;
    std::string receiver_name;
    if (!extractPlayerTarget((char*)args,&receiver,&receiver_guid,&receiver_name))
        return false;

    char* tail1 = strtok(NULL, "");
    if (!tail1)
        return false;

    char* msgSubject = extractQuotedArg(tail1);
    if (!msgSubject)
        return false;

    char* tail2 = strtok(NULL, "");
    if (!tail2)
        return false;

    char* msgText = extractQuotedArg(tail2);
    if (!msgText)
        return false;

    // msgSubject, msgText isn't NUL after prev. check
    std::string subject = msgSubject;
    std::string text    = msgText;

    // extract items
    typedef std::pair<uint32,uint32> ItemPair;
    typedef std::list< ItemPair > ItemPairs;
    ItemPairs items;

    // get all tail string
    char* tail = strtok(NULL, "");

    // get from tail next item str
    while (char* itemStr = strtok(tail, " "))
    {
        // and get new tail
        tail = strtok(NULL, "");

        // parse item str
        char* itemIdStr = strtok(itemStr, ":");
        char* itemCountStr = strtok(NULL, " ");

        uint32 item_id = atoi(itemIdStr);
        if (!item_id)
            return false;

        ItemPrototype const* item_proto = objmgr.GetItemPrototype(item_id);
        if (!item_proto)
        {
            PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, item_id);
            SetSentErrorMessage(true);
            return false;
        }

        uint32 item_count = itemCountStr ? atoi(itemCountStr) : 1;
        if (item_count < 1 || (item_proto->MaxCount > 0 && item_count > uint32(item_proto->MaxCount)))
        {
            PSendSysMessage(LANG_COMMAND_INVALID_ITEM_COUNT, item_count,item_id);
            SetSentErrorMessage(true);
            return false;
        }

        while (item_count > item_proto->GetMaxStackSize())
        {
            items.push_back(ItemPair(item_id,item_proto->GetMaxStackSize()));
            item_count -= item_proto->GetMaxStackSize();
        }

        items.push_back(ItemPair(item_id,item_count));

        if (items.size() > MAX_MAIL_ITEMS)
        {
            PSendSysMessage(LANG_COMMAND_MAIL_ITEMS_LIMIT, MAX_MAIL_ITEMS);
            SetSentErrorMessage(true);
            return false;
        }
    }

    // from console show not existed sender
    MailSender sender(MAIL_NORMAL,m_session ? m_session->GetPlayer()->GetGUIDLow() : 0, MAIL_STATIONERY_GM);

    // fill mail
    MailDraft draft(subject, text);

    for (ItemPairs::const_iterator itr = items.begin(); itr != items.end(); ++itr)
    {
        if (Item* item = Item::CreateItem(itr->first,itr->second,m_session ? m_session->GetPlayer() : 0))
        {
            item->SaveToDB();                               // save for prevent lost at next mail load, if send fail then item will deleted
            draft.AddItem(item);
        }
    }

    draft.SendMailTo(MailReceiver(receiver,GUID_LOPART(receiver_guid)), sender);

    std::string nameLink = playerLink(receiver_name);
    PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
    return true;
}

///Send money by mail
bool ChatHandler::HandleSendMoneyCommand(const char *args)
{
    /// format: name "subject text" "mail text" money

    Player* receiver;
    uint64 receiver_guid;
    std::string receiver_name;
    if (!extractPlayerTarget((char*)args,&receiver,&receiver_guid,&receiver_name))
        return false;

    char* tail1 = strtok(NULL, "");
    if (!tail1)
        return false;

    char* msgSubject = extractQuotedArg(tail1);
    if (!msgSubject)
        return false;

    char* tail2 = strtok(NULL, "");
    if (!tail2)
        return false;

    char* msgText = extractQuotedArg(tail2);
    if (!msgText)
        return false;

    char* money_str = strtok(NULL, "");
    int32 money = money_str ? atoi(money_str) : 0;
    if (money <= 0)
        return false;

    // msgSubject, msgText isn't NUL after prev. check
    std::string subject = msgSubject;
    std::string text    = msgText;

    // from console show not existed sender
    MailSender sender(MAIL_NORMAL,m_session ? m_session->GetPlayer()->GetGUIDLow() : 0, MAIL_STATIONERY_GM);

    MailDraft(subject, text)
        .AddMoney(money)
        .SendMailTo(MailReceiver(receiver,GUID_LOPART(receiver_guid)),sender);

    std::string nameLink = playerLink(receiver_name);
    PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
    return true;
}

/// Send a message to a player in game
bool ChatHandler::HandleSendMessageCommand(const char *args)
{
    ///- Find the player
    Player *rPlayer;
    if (!extractPlayerTarget((char*)args, &rPlayer))
        return false;

    char* msg_str = strtok(NULL, "");
    if (!msg_str)
        return false;

    ///- Check that he is not logging out.
    if (rPlayer->GetSession()->isLogingOut())
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    ///- Send the message
    //Use SendAreaTriggerMessage for fastest delivery.
    rPlayer->GetSession()->SendAreaTriggerMessage("%s", msg_str);
    rPlayer->GetSession()->SendAreaTriggerMessage("|cffff0000[Message from administrator]:|r");

    //Confirmation message
    std::string nameLink = GetNameLink(rPlayer);
    PSendSysMessage(LANG_SENDMESSAGE,nameLink.c_str(),msg_str);
    return true;
}

bool ChatHandler::HandleFlushArenaPointsCommand(const char * /*args*/)
{
    sBattleGroundMgr.DistributeArenaPoints();
    return true;
}

bool ChatHandler::HandleModifyGenderCommand(const char *args)
{
    if (!*args)
        return false;

    Player *player = getSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    PlayerInfo const* info = objmgr.GetPlayerInfo(player->getRace(), player->getClass());
    if (!info)
        return false;

    char const* gender_str = (char*)args;
    int gender_len = strlen(gender_str);

    Gender gender;

    if (!strncmp(gender_str, "male", gender_len))            // MALE
    {
        if (player->getGender() == GENDER_MALE)
            return true;

        gender = GENDER_MALE;
    }
    else if (!strncmp(gender_str, "female", gender_len))    // FEMALE
    {
        if (player->getGender() == GENDER_FEMALE)
            return true;

        gender = GENDER_FEMALE;
    }
    else
    {
        SendSysMessage(LANG_MUST_MALE_OR_FEMALE);
        SetSentErrorMessage(true);
        return false;
    }

    // Set gender
    player->SetByteValue(UNIT_FIELD_BYTES_0, 2, gender);
    player->SetByteValue(PLAYER_BYTES_3, 0, gender);

    // Change display ID
    player->InitDisplayIds();

    char const* gender_full = gender ? "female" : "male";

    PSendSysMessage(LANG_YOU_CHANGE_GENDER, GetNameLink(player).c_str(), gender_full);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOUR_GENDER_CHANGED, gender_full, GetNameLink().c_str());

    return true;
}

bool ChatHandler::HandleChannelSetPublic(const char *args)
{
    if (!*args)
        return false;
    std::string channel = strtok((char*)args, " ");
    uint32 val = atoi((char*)args);

    if (val)
    {
        CharacterDatabase.PExecute("UPDATE channels SET m_public = 1 WHERE m_name LIKE '%s'", channel.c_str());
        val = 1;
    }
    else
    {
        CharacterDatabase.PExecute("UPDATE channels SET m_public = 0 WHERE m_name LIKE '%s'", channel.c_str());
        val = 0;
    }

    PSendSysMessage(LANG_CHANNEL_PUBLIC_CHANGED, channel.c_str(), val);

    return true;
}


/*------------------------------------------
 *-------------TRINITY----------------------
 *-------------------------------------*/

bool ChatHandler::HandlePlayAllCommand(const char *args)
{
    if (!*args)
        return false;

    uint32 soundId = atoi((char*)args);

    if (!sSoundEntriesStore.LookupEntry(soundId))
    {
        PSendSysMessage(LANG_SOUND_NOT_EXIST, soundId);
        SetSentErrorMessage(true);
        return false;
    }

    WorldPacket data(SMSG_PLAY_SOUND, 4);
    data << uint32(soundId) << m_session->GetPlayer()->GetGUID();
    sWorld.SendGlobalMessage(&data);

    PSendSysMessage(LANG_COMMAND_PLAYED_TO_ALL, soundId);
    return true;
}

bool ChatHandler::HandleFreezeCommand(const char *args)
{
    std::string name;
    Player *player;
    char *TargetName = strtok((char*)args, " "); //get entered name
    if (!TargetName) //if no name entered use target
    {
        player = getSelectedPlayer();
        if (player) //prevent crash with creature as target
        {
            name = player->GetName();
            normalizePlayerName(name);
        }
    }
    else // if name entered
    {
        name = TargetName;
        normalizePlayerName(name);
        player = objmgr.GetPlayer(name.c_str()); //get player by name
    }

    if (!player)
    {
        SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
        return true;
    }

    if (player == m_session->GetPlayer())
    {
        SendSysMessage(LANG_COMMAND_FREEZE_ERROR);
        return true;
    }

    //effect
    if (player && player != m_session->GetPlayer())
    {
        PSendSysMessage(LANG_COMMAND_FREEZE,name.c_str());

        //stop combat + make player unattackable + duel stop + stop some spells
        player->setFaction(35);
        player->CombatStop();
        if (player->IsNonMeleeSpellCasted(true))
            player->InterruptNonMeleeSpells(true);
        player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        player->SetUInt32Value(PLAYER_DUEL_TEAM, 1);

        //if player class = hunter || warlock remove pet if alive
        if ((player->getClass() == CLASS_HUNTER) || (player->getClass() == CLASS_WARLOCK))
        {
            if (Pet *pet = player->GetPet())
            {
                pet->SavePetToDB(PET_SAVE_AS_CURRENT);
                // not let dismiss dead pet
                if (pet && pet->isAlive())
                    player->RemovePet(pet,PET_SAVE_NOT_IN_SLOT);
            }
        }

        //m_session->GetPlayer()->CastSpell(player,spellID,false);
        if (SpellEntry const *spellInfo = sSpellStore.LookupEntry(9454))
            Aura::TryCreate(spellInfo, player, player);

        //save player
        player->SaveToDB();
    }
    return true;
}

bool ChatHandler::HandleUnFreezeCommand(const char *args)
{
    std::string name;
    Player *player;
    char *TargetName = strtok((char*)args, " "); //get entered name
    if (!TargetName) //if no name entered use target
    {
        player = getSelectedPlayer();
        if (player) //prevent crash with creature as target
            name = player->GetName();
    }

    else // if name entered
    {
        name = TargetName;
        normalizePlayerName(name);
        player = objmgr.GetPlayer(name.c_str()); //get player by name
    }

    //effect
    if (player)
    {
        PSendSysMessage(LANG_COMMAND_UNFREEZE,name.c_str());

        //Reset player faction + allow combat + allow duels
        player->setFactionForRace(player->getRace());
        player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        //allow movement and spells
        player->RemoveAurasDueToSpell(9454);

        //save player
        player->SaveToDB();
    }

    if (!player)
    {
        if (TargetName)
        {
            //check for offline players
            QueryResult_AutoPtr result = CharacterDatabase.PQuery("SELECT characters.guid FROM characters WHERE characters.name = '%s'",name.c_str());
            if (!result)
            {
                SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
                return true;
            }
            //if player found: delete his freeze aura
            Field *fields=result->Fetch();
            uint64 pguid = fields[0].GetUInt64();

            CharacterDatabase.PQuery("DELETE FROM character_aura WHERE character_aura.spell = 9454 AND character_aura.guid = '%u'",pguid);
            PSendSysMessage(LANG_COMMAND_UNFREEZE,name.c_str());
            return true;
        }
        else
        {
            SendSysMessage(LANG_COMMAND_FREEZE_WRONG);
            return true;
        }
    }

    return true;
}

bool ChatHandler::HandleListFreezeCommand(const char * /*args*/)
{
    //Get names from DB
    QueryResult_AutoPtr result = CharacterDatabase.Query("SELECT characters.name FROM characters LEFT JOIN character_aura ON (characters.guid = character_aura.guid) WHERE character_aura.spell = 9454");
    if (!result)
    {
        SendSysMessage(LANG_COMMAND_NO_FROZEN_PLAYERS);
        return true;
    }
    //Header of the names
    PSendSysMessage(LANG_COMMAND_LIST_FREEZE);

    //Output of the results
    do
    {
        Field *fields = result->Fetch();
        std::string fplayers = fields[0].GetCppString();
        PSendSysMessage(LANG_COMMAND_FROZEN_PLAYERS,fplayers.c_str());
    } while (result->NextRow());

    return true;
}

bool ChatHandler::HandleGroupLeaderCommand(const char *args)
{
    Player* plr  = NULL;
    Group* group = NULL;
    uint64 guid  = 0;
    char* cname  = strtok((char*)args, " ");

    if (GetPlayerGroupAndGUIDByName(cname, plr, group, guid))
        if (group && group->GetLeaderGUID() != guid)
            group->ChangeLeader(guid);

    return true;
}

bool ChatHandler::HandleGroupDisbandCommand(const char *args)
{
    Player* plr  = NULL;
    Group* group = NULL;
    uint64 guid  = 0;
    char* cname  = strtok((char*)args, " ");

    if (GetPlayerGroupAndGUIDByName(cname, plr, group, guid))
        if (group)
            group->Disband();

    return true;
}

bool ChatHandler::HandleGroupRemoveCommand(const char *args)
{
    Player* plr  = NULL;
    Group* group = NULL;
    uint64 guid  = 0;
    char* cname  = strtok((char*)args, " ");

    if (GetPlayerGroupAndGUIDByName(cname, plr, group, guid, true))
        if (group)
            group->RemoveMember(guid, 0);

    return true;
}

bool ChatHandler::HandlePossessCommand(const char * /*args*/)
{
    Unit *pUnit = getSelectedUnit();
    if (!pUnit)
        return false;

    m_session->GetPlayer()->CastSpell(pUnit, 530, true);
    return true;
}

bool ChatHandler::HandleUnPossessCommand(const char * /*args*/)
{
    Unit *pUnit = getSelectedUnit();
    if (!pUnit)
        pUnit = m_session->GetPlayer();

    pUnit->RemoveCharmAuras();

    return true;
}

bool ChatHandler::HandleBindSightCommand(const char * /*args*/)
{
    Unit *pUnit = getSelectedUnit();
    if (!pUnit)
        return false;

    m_session->GetPlayer()->CastSpell(pUnit, 6277, true);
    return true;
}

bool ChatHandler::HandleUnbindSightCommand(const char * /*args*/)
{
    if (m_session->GetPlayer()->isPossessing())
        return false;

    m_session->GetPlayer()->StopCastingBindSight();
    return true;
}
