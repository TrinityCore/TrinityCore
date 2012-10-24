/*******************************************************************************************
*              _   _                                      __   _                           *
*              | \ | |   ___    _ __ ___    ___    ___    / _| | |_                        *
*              |  \| |  / _ \  | '_ ` _ \  / __|  / _ \  | |_  | __|                       *
*              | |\  | | (_) | | | | | | | \__ \ | (_) | |  _| | |_                        *
*              |_| \_|  \___/  |_| |_| |_| |___/  \___/  |_|    \__|                       *
*                               The policy of Nomsoftware states: Releasing our software   *
*                               or any other files are protected. You cannot re-release    * 
*                               anywhere unless you were given permission.                 *
*                           (C) Nomsoftware 2011-2012. All rights reserved.                *
********************************************************************************************/
/*
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('100090', '0', '0', '0', '0', '0', '27164', '0', '0', '0', 'Arena TeamTop', 'freedom-wow', '', '0', '59', '61', '0', '35', '35', '1', '1.48', '1.14286', '0.0', '0', '655.0', '663.0', '0', '158', '1.0', '1500', '1900', '1', '0', '0', '0', '0', '0', '0', '0', '0.0', '0.0', '100', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '1', '3', '1.0', '1.0', '1.0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'npc_arena_teamTop', '1');
*/ 

#include "ScriptPCH.h"
using namespace std;

class npc_arena_teamTop : public CreatureScript
{
   public:
	   npc_arena_teamTop() : CreatureScript("npc_arena_teamTop") { }

	   bool OnGossipHello(Player * player, Creature * creature)
	   {
		   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View top 2v2 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
		   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View top 3v3 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
		   player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nevermind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
		   player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		   return true;
	   }

	   bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 actions)
	   {
		   if(sender == GOSSIP_SENDER_MAIN)
		   {
			   switch(actions)
			   {
			       case GOSSIP_ACTION_INFO_DEF+1:
				   {
					   QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='2' ORDER BY rating DESC LIMIT 10");
					   if(!result)
						   return false;

					   Field * fields = NULL;
					   player->MonsterWhisper("|cff4169E1Here are the top 10 2v2 arena teams:|r", player->GetGUID());
					   do
					   {
						   fields = result->Fetch();
						   string arena_name = fields[0].GetString();
						   uint32 rating = fields[1].GetUInt32();
						   char msg[250];
						   snprintf(msg, 250, "Team Name: |cffFFFF00%s|r, Team Rating: %u \n", arena_name.c_str(), rating);
						   player->MonsterWhisper(msg, player->GetGUID());
					   }while(result->NextRow());
				   }break;

			       case GOSSIP_ACTION_INFO_DEF+2:
				   {
					   QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='3' ORDER BY rating DESC LIMIT 10");
					   if(!result)
						   return false;

					   Field * fields = NULL;
					   player->MonsterWhisper("|cff4169E1Here are the top 10 3v3 arena teams:|r", player->GetGUID());
					   do
					   {
						   fields = result->Fetch();
						   string arena_name = fields[0].GetString();
						   uint32 rating = fields[1].GetUInt32();
						   char msg[250];
						   snprintf(msg, 250, "Team Name: |cffFFFF00%s|r, Team Rating: %u \n", arena_name.c_str(), rating);
						   player->MonsterWhisper(msg, player->GetGUID());
					   }while(result->NextRow());
				   }break;

			       case GOSSIP_ACTION_INFO_DEF+3:
					   {
						   player->PlayerTalkClass->SendCloseGossip();
					   }break;
			   }
		   }

		   return true;
	   }
};

void AddSC_npc_arena_setup()
{
	new npc_arena_teamTop;
}