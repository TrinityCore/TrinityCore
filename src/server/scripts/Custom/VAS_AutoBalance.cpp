/*
* Copyright (C) 2012 CVMagic <http://www.trinitycore.org/f/topic/6551-vas-autobalance/>
* Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* Copyright (C) 1985-2010 {VAS} KalCorp  <http://vasserver.dyndns.org/>
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

/*
* Script Name: AutoBalance
* Original Authors: KalCorp and Vaughner
* Maintainer(s): CVMagic
* Original Script Name: VAS.AutoBalance
* Description: This script is intended to scale based on number of players, instance mobs & world bosses' health, mana, and damage.
*/


//#include "ScriptPCH.h"
#include "Configuration/Config.h"
#include "Unit.h"
#include "Chat.h"
#include "Creature.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "World.h"
#include "Map.h"
#include "ScriptMgr.h"
#include <vector>

#define BOOL_TO_STRING(b) ((b) ? "true" : "false")

struct AutoBalanceCreatureInfo
{
	uint32 instancePlayerCount;
	float DamageMultiplier;
};

static std::map<uint32, AutoBalanceCreatureInfo> CreatureInfo; // A hook should be added to remove the mapped entry when the creature is dead or this should be added into the creature object
static std::map<int, int> forcedCreatureIds;                   // The map values correspond with the VAS.AutoBalance.XX.Name entries in the configuration file.

int GetValidDebugLevel()
{
	int debugLevel = sWorld->getIntConfig(VAS_VasDebug);
	
	if ((debugLevel < 0) || (debugLevel > 3))
		{
		return 1;
		}
	return debugLevel;
}

void LoadForcedCreatureIdsFromString(std::string creatureIds, int forcedPlayerCount) // Used for reading the string from the configuration file to for those creatures who need to be scaled for XX number of players.
{
	std::string delimitedValue;
	std::stringstream creatureIdsStream;
	
	creatureIdsStream.str(creatureIds);
	while (std::getline(creatureIdsStream, delimitedValue, ',')) // Process each Creature ID in the string, delimited by the comma - ","
	{
		int creatureId = atoi(delimitedValue.c_str());
		if (creatureId >= 0)
		{
			forcedCreatureIds[creatureId] = forcedPlayerCount;
		}
	}
}

int GetForcedCreatureId(int creatureId)
{
	if (forcedCreatureIds.find(creatureId) == forcedCreatureIds.end()) // Don't want the forcedCreatureIds map to blowup to a massive empty array
	{
		return 0;
	}
	return forcedCreatureIds[creatureId];
}

class VAS_AutoBalance_WorldScript : public WorldScript
{
	public:
	VAS_AutoBalance_WorldScript()
		: WorldScript("VAS_AutoBalance_WorldScript")
	{
	}
	
	void OnConfigLoad(bool /*reload*/)
	{
	}
		
	void OnStartup()
	{
	}
	
	void SetInitialWorldSettings()
	{
	// Load from the VAS.AutoBalance.XX.Name entries in the Configuration File
	forcedCreatureIds.clear();
	LoadForcedCreatureIdsFromString(sWorld->GetVAS40(), 40);
	LoadForcedCreatureIdsFromString(sWorld->GetVAS25(), 25);
	LoadForcedCreatureIdsFromString(sWorld->GetVAS10(), 10);
	LoadForcedCreatureIdsFromString(sWorld->GetVAS5(), 5);
	LoadForcedCreatureIdsFromString(sWorld->GetVAS2(), 2);
	
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "----------------------------------------------------");
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  Powered by {VAS} AutoBalance");
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "----------------------------------------------------");
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  xPlayer = %4.1f ", sWorld->getFloatConfig(VAS_Config_xPlayer));
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  AutoInstance = %u ", sWorld->getIntConfig(VAS_AutoInstance));
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  PlayerChangeNotify = %u ", sWorld->getIntConfig(VAS_PlayerChangeNotify));
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  Min.D.Mod = %4.2f ", sWorld->getFloatConfig(VAS_Min_D_Mod));
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  Min.HP.Mod = %4.2f ", sWorld->getFloatConfig(VAS_Min_HP_Mod));
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "  VasDebug   =  %u ", GetValidDebugLevel());
	//sLog->outInfo(LOG_FILTER_WORLDSERVER, "----------------------------------------------------\n");
	}
	
};

class VAS_AutoBalance_PlayerScript : public PlayerScript
{
	public:
		VAS_AutoBalance_PlayerScript()
			: PlayerScript("VAS_AutoBalance_PlayerScript")
		{
		}
		
		void OnLogin(Player *Player, bool /*firstLogin*/)
		{
			//TC_LOG_INFO("vas.player.loading", "### VAS_AutoBalance_PlayerScript - OnLogin Player=%s", Player->GetName());
		}
};

class VAS_AutoBalance_UnitScript : public UnitScript
{
	public:
	VAS_AutoBalance_UnitScript()
		: UnitScript("VAS_AutoBalance_UnitScript")
	{
	}
	
	uint32 DealDamage(Unit* AttackerUnit, Unit *playerVictim, uint32 damage, DamageEffectType damagetype)
	{
		if (AttackerUnit->GetMap()->IsDungeon() && playerVictim->GetMap()->IsDungeon())
		if (AttackerUnit->GetTypeId() != TYPEID_PLAYER)
		{
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - VAS_Unit_DealDamage Attacker=%s Victim=%s Start Damage=%u",AttackerUnit->GetName(),playerVictim->GetName(),damage);
			damage = VAS_Modifer_DealDamage(AttackerUnit, damage);
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - VAS_Unit_DealDamage Attacker=%s Victim=%s End Damage=%u",AttackerUnit->GetName(),playerVictim->GetName(),damage);
		}
		return damage;
	}
	
	uint32 HandlePeriodicDamageAurasTick(Unit *target, Unit *caster, int32 damage)
	{
		if (caster->GetMap()->IsDungeon() && target->GetMap()->IsDungeon())
		if (caster->GetTypeId() != TYPEID_PLAYER)
		{
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - VAS_Unit_HandlePeriodicDamage Attacker=%s Victim=%s Start Damage=%u",caster->GetName(),target->GetName(),damage);
			
			if (!((caster->IsHunterPet() || caster->IsPet() || caster->IsSummon()) && caster->IsControlledByPlayer()))
			damage = (float)damage * (float)CreatureInfo[caster->GetGUID()].DamageMultiplier;
			
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - VAS_Unit_HandlePeriodicDamage Attacker=%s Victim=%s End Damage=%u",caster->GetName(),target->GetName(),damage);
		}
		return damage;
	}
	
	void CalculateSpellDamageTaken(SpellNonMeleeDamage *damageInfo, int32 damage, SpellInfo const *spellInfo, WeaponAttackType attackType, bool crit)
	{
		if ((damageInfo->attacker->GetMap()->IsDungeon() && damageInfo->target->GetMap()->IsDungeon()) || (damageInfo->attacker->GetMap()->IsBattleground() && damageInfo->target->GetMap()->IsBattleground()))
		{
			if (damageInfo->attacker->GetTypeId() != TYPEID_PLAYER)
			{
				//if (GetValidDebugLevel() >= 3)
				//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - CalculateSpellDamageTaken Attacker=%s Victim=%s Start Damage=%u",damageInfo->attacker->GetName(),damageInfo->target->GetName(),damageInfo->damage);
				
				if ((damageInfo->attacker->IsHunterPet() || damageInfo->attacker->IsPet() || damageInfo->attacker->IsSummon()) && damageInfo->attacker->IsControlledByPlayer())
					return;
					
				damageInfo->damage = (float)damageInfo->damage * (float)CreatureInfo[damageInfo->attacker->GetGUID()].DamageMultiplier;
				
				//if (GetValidDebugLevel() >= 3)
				//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - CalculateSpellDamageTaken Attacker=%s Victim=%s End Damage=%u",damageInfo->attacker->GetName(),damageInfo->target->GetName(),damageInfo->damage);
			}
		}
		return;
	}
	
	void CalculateMeleeDamage(Unit *playerVictim, uint32 damage, CalcDamageInfo *damageInfo, WeaponAttackType attackType)
	{
		// Make sure the Attacker and the Victim are in the same location, in addition that the attacker is not player.
		if (((damageInfo->attacker->GetMap()->IsDungeon() && damageInfo->target->GetMap()->IsDungeon()) || (damageInfo->attacker->GetMap()->IsBattleground() && damageInfo->target->GetMap()->IsBattleground())) && (damageInfo->attacker->GetTypeId() != TYPEID_PLAYER))
		if (!((damageInfo->attacker->IsHunterPet() || damageInfo->attacker->IsPet() || damageInfo->attacker->IsSummon()) && damageInfo->attacker->IsControlledByPlayer())) // Make sure that the attacker Is not a Pet of some sort
		{
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - CalculateMeleeDamage Attacker=%s Victim=%s Start Damage=%u",damageInfo->attacker->GetName(),damageInfo->target->GetName(),damageInfo->damage);
			
			damageInfo->damage = (float)damageInfo->damage * (float)CreatureInfo[damageInfo->attacker->GetGUID()].DamageMultiplier;
			
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_UnitScript - CalculateMeleeDamage Attacker=%s Victim=%s End Damage=%u",damageInfo->attacker->GetName(),damageInfo->target->GetName(),damageInfo->damage);
		}
		return;
	}
	
	uint32 VAS_Modifer_DealDamage(Unit* AttackerUnit, uint32 damage)
	{
		if ((AttackerUnit->IsHunterPet() || AttackerUnit->IsPet() || AttackerUnit->IsSummon()) && AttackerUnit->IsControlledByPlayer())
			return damage;
		
		float damageMultiplier = CreatureInfo[AttackerUnit->GetGUID()].DamageMultiplier;
		
		return damage * damageMultiplier;
			
	}
};


class VAS_AutoBalance_AllMapScript : public AllMapScript
{
	public:
	VAS_AutoBalance_AllMapScript()
		: AllMapScript("VAS_AutoBalance_AllMapScript")
		{
		}
		
		void OnPlayerEnterAll(Map* map, Player* player)
		{
			if (GetValidDebugLevel() >= 2)
			{
				//sLog->outInfo(LOG_FILTER_TSCR, "----------------------------------------------------");
				//sLog->outInfo(LOG_FILTER_TSCR, "## VAS_AutoBalance_AllMapScript - OnPlayerEnterAll");
				//sLog->outInfo(LOG_FILTER_TSCR, "## For InsatanceID %u",map->GetInstanceId());
				//sLog->outInfo(LOG_FILTER_TSCR, "## IsDungeon= %u",map->GetEntry()->IsDungeon());
				//sLog->outInfo(LOG_FILTER_TSCR, "## For Map %u",player->GetMapId());
				//sLog->outInfo(LOG_FILTER_TSCR, "## PlayersInMap %u",map->GetPlayersCountExceptGMs());
				//sLog->outInfo(LOG_FILTER_TSCR, "## pDifficulty %u",uint32(player->GetDifficulty(player->GetMap()->IsHeroic())));
				//sLog->outInfo(LOG_FILTER_TSCR, "## pGetDungeonDifficulty %u",uint32(player->GetDungeonDifficulty()));
				//sLog->outInfo(LOG_FILTER_TSCR, "## pGetRaidDifficulty %u",uint32(player->GetRaidDifficulty()));
				//sLog->outInfo(LOG_FILTER_TSCR, "## maxPlayers %u",((InstanceMap*)sMapMgr->FindMap(player->GetMapId(), player->GetInstanceId()))->GetMaxPlayers());
				//sLog->outInfo(LOG_FILTER_TSCR, "## IsHeroic=%s IsRaid=%s IsRegularDifficulty=%s IsRaidOrHeroicDungeon=%s IsNonRaidDungeon=%s",BOOL_TO_STRING(player->GetMap()->IsHeroic()),BOOL_TO_STRING(player->GetMap()->IsRaid()),BOOL_TO_STRING(player->GetMap()->IsRegularDifficulty()),BOOL_TO_STRING(player->GetMap()->IsRaidOrHeroicDungeon()),BOOL_TO_STRING(player->GetMap()->IsNonRaidDungeon()));
				//sLog->outInfo(LOG_FILTER_TSCR, "----------------------------------------------------\n");
			}
			
			if (sWorld->getIntConfig(VAS_PlayerChangeNotify) >= 1)
			{
				if ((map->GetEntry()->IsDungeon()) && !player->IsGameMaster())
				{
					Map::PlayerList const &playerList = map->GetPlayers();
					if (!playerList.isEmpty())
					{
						for (Map::PlayerList::const_iterator playerIteration = playerList.begin(); playerIteration != playerList.end(); ++playerIteration)
						{
							if (Player* playerHandle = playerIteration->GetSource())
							{
								ChatHandler chatHandle = ChatHandler(playerHandle->GetSession());
								chatHandle.PSendSysMessage("|cffFF0000 [AutoBalance]|r|cffFF8000 %s entered the Instance %s. Auto setting player count to %u |r", player->GetName().c_str(), map->GetMapName(), map->GetPlayersCountExceptGMs());
							}
						}
					}
				}
			}
		}
		
		void OnPlayerLeaveAll(Map* map, Player* player)
		{
		
			//if (GetValidDebugLevel() >= 3)
			//sLog->outInfo(LOG_FILTER_TSCR, "#### VAS_AutoBalance_AllMapScript - OnPlayerLeaveAll map=%s player=%s", map->GetMapName(),player->GetName());
			
			int instancePlayerCount = map->GetPlayersCountExceptGMs() - 1;
			
			if (instancePlayerCount >= 1)
			{
				if (GetValidDebugLevel() >= 2)
				{
					//sLog->outInfo(LOG_FILTER_TSCR, "----------------------------------------------------");
					//sLog->outInfo(LOG_FILTER_TSCR, "## VAS_AutoBalance_AllMapScript - OnPlayerLeaveAll");
					//sLog->outInfo(LOG_FILTER_TSCR, "## For InsatanceID %u",map->GetInstanceId());
					//sLog->outInfo(LOG_FILTER_TSCR, "## IsDungeon= %u",map->GetEntry()->IsDungeon());
					//sLog->outInfo(LOG_FILTER_TSCR, "## For Map %u",player->GetMapId());
					//sLog->outInfo(LOG_FILTER_TSCR, "## PlayersInMap %u",instancePlayerCount);
					//sLog->outInfo(LOG_FILTER_TSCR, "----------------------------------------------------\n");
				}
				
				if (sWorld->getIntConfig(VAS_PlayerChangeNotify) >= 1)
				{
					if ((map->GetEntry()->IsDungeon()) && !player->IsGameMaster())
					{
						Map::PlayerList const &playerList = map->GetPlayers();
						if (!playerList.isEmpty())
						{
							for (Map::PlayerList::const_iterator playerIteration = playerList.begin(); playerIteration != playerList.end(); ++playerIteration)
							{
								if (Player* playerHandle = playerIteration->GetSource())
								{
									ChatHandler chatHandle = ChatHandler(playerHandle->GetSession());
									chatHandle.PSendSysMessage("|cffFF0000 [VAS-AutoBalance]|r|cffFF8000 %s left the Instance %s. Auto setting player count to %u |r", player->GetName().c_str(), map->GetMapName(), instancePlayerCount);
								}
							}
						}
					}
				}
			}
		}
};

class VAS_AutoBalance_WorldMapScript : public WorldMapScript
{
	public:
	VAS_AutoBalance_WorldMapScript()
		: WorldMapScript("VAS_AutoBalance_WorldMapScript", 0)
	{
	}
	
	void OnPlayerEnter(Map* map, Player* player)
	{
	
		//if (GetValidDebugLevel() >= 3)
		//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_WorldMapScript - OnPlayerEnter Map=%s player=%s",map->GetMapName(),player->GetName());
	}
	
	void OnPlayerLeave(Map* map, Player* player)
	{
	
		//if (GetValidDebugLevel() >= 3)
		//sLog->outInfo(LOG_FILTER_TSCR, "### VAS_AutoBalance_WorldMapScript - OnPlayerLeave Map=%s player=%s",map->GetMapName(),player->GetName());
	}
};


class VAS_AutoBalance_AllCreatureScript : public AllCreatureScript
{
	public:
	VAS_AutoBalance_AllCreatureScript()
		: AllCreatureScript("VAS_AutoBalance_AllCreatureScript")
	{
	}
	
	
	void Creature_SelectLevel(const CreatureTemplate *creatureTemplate, Creature* creature)
	{
	
		if (creature->GetMap()->IsDungeon())
		{
			ModifyCreatureAttributes(creature);
			CreatureInfo[creature->GetGUID()].instancePlayerCount = creature->GetMap()->GetPlayersCountExceptGMs();
		}
	}
	
	void OnAllCreatureUpdate(Creature* creature, uint32 diff)
	{
		if (!(CreatureInfo[creature->GetGUID()].instancePlayerCount == creature->GetMap()->GetPlayersCountExceptGMs()))
		{
			if (creature->GetMap()->IsDungeon() || creature->GetMap()->IsBattleground())
			ModifyCreatureAttributes(creature);
			CreatureInfo[creature->GetGUID()].instancePlayerCount = creature->GetMap()->GetPlayersCountExceptGMs();
		}
	}
	
	void ModifyCreatureAttributes(Creature* creature)
	{
		if (((creature->IsHunterPet() || creature->IsPet() || creature->IsSummon()) && creature->IsControlledByPlayer()) || sWorld->getIntConfig(VAS_AutoInstance) < 1 || creature->GetMap()->GetPlayersCountExceptGMs() <= 0)
		{
			return;
		}
		
		CreatureTemplate const *creatureTemplate = creature->GetCreatureTemplate();
		CreatureBaseStats const* creatureStats = sObjectMgr->GetCreatureBaseStats(creature->getLevel(), creatureTemplate->unit_class);
		
		float damageMultiplier = 1.0f;
		float healthMultiplier = 1.0f;
		
		uint32 baseHealth = creatureStats->GenerateHealth(creatureTemplate);
		uint32 baseMana = creatureStats->GenerateMana(creatureTemplate);
		uint32 instancePlayerCount = creature->GetMap()->GetPlayersCountExceptGMs();
		uint32 maxNumberOfPlayers = ((InstanceMap*)sMapMgr->FindMap(creature->GetMapId(), creature->GetInstanceId()))->GetMaxPlayers();
		uint32 scaledHealth = 0;
		uint32 scaledMana = 0;
		
		//   VAS SOLO  - By MobID
		if (GetForcedCreatureId(creatureTemplate->Entry) > 0)
		{
			maxNumberOfPlayers = GetForcedCreatureId(creatureTemplate->Entry); // Force maxNumberOfPlayers to be changed to match the Configuration entry.
		}
		
		// (tanh((X-2.2)/1.5) +1 )/2    // 5 Man formula X = Number of Players
		// (tanh((X-5)/2) +1 )/2        // 10 Man Formula X = Number of Players
		// (tanh((X-16.5)/6.5) +1 )/2   // 25 Man Formula X = Number of players
		//
		// Note: The 2.2, 5, and 16.5 are the number of players required to get 50% health.
		//       It's not required this be a whole number, you'd adjust this to raise or lower
		//       the hp modifier for per additional player in a non-whole group. These
		//       values will eventually be part of the configuration file once I finalize the mod.
		//
		//       The 1.5, 2, and 6.5 modify the rate of percentage increase between
		//       number of players. Generally the closer to the value of 1 you have this
		//       the less gradual the rate will be. For example in a 5 man it would take 3
		//       total players to face a mob at full health.
		//
		//       The +1 and /2 values raise the TanH function to a positive range and make
		//       sure the modifier never goes above the value or 1.0 or below 0.
		//
		//       Lastly this formula has one side effect on full groups Bosses and mobs will
		//       never have full health, this can be tested against by making sure the number
		//       of players match the maxNumberOfPlayers variable.
		
		switch (maxNumberOfPlayers)
		{
			case 40:
				healthMultiplier = (float)instancePlayerCount / (float)maxNumberOfPlayers; // 40 Man Instances oddly enough scale better with the old formula
			break;
			case 25:
				healthMultiplier = (tanh((instancePlayerCount - 16.5f) / 1.5f) + 1.0f) / 2.0f;
			break;
			case 10:
				healthMultiplier = (tanh((instancePlayerCount - 4.5f) / 1.5f) + 1.0f) / 2.0f;
			break;
			case 2:
				healthMultiplier = (float)instancePlayerCount / (float)maxNumberOfPlayers;                   // Two Man Creatures are too easy if handled by the 5 man formula, this would only
			break;                                                                         // apply in the situation where it's specified in the configuration file.
			default:
				healthMultiplier = (tanh((instancePlayerCount - 2.2f) / 1.5f) + 1.0f) / 2.0f;    // default to a 5 man group
			}
			
			//   VAS SOLO  - Map 0,1 and 530 ( World Mobs )                                                               // This may be where VAS_AutoBalance_CheckINIMaps might have come into play. None the less this is
			if ((creature->GetMapId() == 0 || creature->GetMapId() == 1 || creature->GetMapId() == 530) && (creature->isElite() || creature->isWorldBoss()))  // specific to World Bosses and elites in those Maps, this is going to use the entry XPlayer in place of instancePlayerCount.
			{
				if (baseHealth > 800000) {
				healthMultiplier = (tanh((sWorld->getFloatConfig(VAS_Config_xPlayer) - 5.0f) / 1.5f) + 1.0f) / 2.0f;
				
			}
			else {
				healthMultiplier = (tanh((sWorld->getFloatConfig(VAS_Config_xPlayer) - 2.2f) / 1.5f) + 1.0f) / 2.0f; // Assuming a 5 man configuration, as World Bosses have been relatively retired since BC so unless the boss has some substantial baseHealth
			}
	
		}
		
		// Ensure that the healthMultiplier is not lower than the configuration specified value. -- This may be Deprecated later.
		if (healthMultiplier <= sWorld->getFloatConfig(VAS_Min_HP_Mod))
		{
			healthMultiplier = sWorld->getFloatConfig(VAS_Min_HP_Mod);
		}
		
		//Getting the list of Classes in this group - this will be used later on to determine what additional scaling will be required based on the ratio of tank/dps/healer
		//GetPlayerClassList(creature, playerClassList); // Update playerClassList with the list of all the participating Classes
		
	
		scaledHealth = uint32((baseHealth * healthMultiplier) + 1.0f);
		// Now adjusting Mana, Mana is something that can be scaled linearly
		if (maxNumberOfPlayers == 0) {
			scaledMana = uint32((baseMana * healthMultiplier) + 1.0f);
			// Now Adjusting Damage, this too is linear for now .... this will have to change I suspect.
			damageMultiplier = healthMultiplier;
		}
		else {
			scaledMana = ((baseMana / maxNumberOfPlayers) * instancePlayerCount);
			// Now Adjusting Damage, this too is linear for now .... this will have to change I suspect.
			damageMultiplier = (float)instancePlayerCount / (float)maxNumberOfPlayers;

		}
		
		// Can not be less then Min_D_Mod
		if (damageMultiplier <= sWorld->getFloatConfig(VAS_Min_D_Mod))
		{
			damageMultiplier = sWorld->getFloatConfig(VAS_Min_D_Mod);
		}
		
		if ((GetValidDebugLevel() >= 3))
		{
			//sLog->outInfo(LOG_FILTER_TSCR, "## VAS-AutoBalance MobID=%u MapID=%u creatureName=%s  GUID=%llu  instancePlayerCount=%u", creatureTemplate->Entry, creature->GetMapId(), creatureTemplate->Name.c_str(), creature->GetGUID(), instancePlayerCount);
			//sLog->outInfo(LOG_FILTER_TSCR, "## VAS-AutoBalance MapDifficulty=%u Health=%u / %u healthMultiplier=%4.5f", creature->GetMap()->GetDifficulty(), scaledHealth, baseHealth, healthMultiplier);
			//sLog->outInfo(LOG_FILTER_TSCR, "## VAS-AutoBalance maxNumberOfPlayers=%u IsRaid=%s", maxNumberOfPlayers, BOOL_TO_STRING(creature->GetMap()->IsRaid()));
			//sLog->outInfo(LOG_FILTER_TSCR, "## VAS-AutoBalance Mana %u / %u", baseMana, scaledMana);
			//sLog->outInfo(LOG_FILTER_TSCR, "## VAS-AutoBalance damageMultiplier=%4.2f", damageMultiplier);
		}
		
		creature->SetCreateHealth(scaledHealth);
		creature->SetMaxHealth(scaledHealth);
		creature->ResetPlayerDamageReq();
		creature->SetCreateMana(scaledMana);
		creature->SetMaxPower(POWER_MANA, scaledMana);
		creature->SetPower(POWER_MANA, scaledMana);
		creature->SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)scaledHealth);
		creature->SetModifierValue(UNIT_MOD_MANA, BASE_VALUE, (float)scaledMana);
		CreatureInfo[creature->GetGUID()].DamageMultiplier = damageMultiplier;
	}
};

void AddSC_VAS_AutoBalance()
{
	new VAS_AutoBalance_WorldScript;
	new VAS_AutoBalance_PlayerScript;
	new VAS_AutoBalance_UnitScript;
	new VAS_AutoBalance_AllCreatureScript;
	new VAS_AutoBalance_AllMapScript;
	new VAS_AutoBalance_WorldMapScript;
}