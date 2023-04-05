/*
SPP Praevius Core Combat.Rating.Craft V2
Original Script Provided by Conanhun
Re-Written by MDic
*/
#include <map>  //系统库 D:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\include\map

#include "Config.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Pet.h"
#include "Map.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Chat.h"
#include "Log.h"

namespace { //命名空间

	class CombatRatingCraft_player_instance_handler : public PlayerScript
	{

	public:
		CombatRatingCraft_player_instance_handler() : PlayerScript("Combat.Rating.Craft_player_instance_handler")
		{
            TC_LOG_INFO("scripts.CRcraft.player.instance", "[Combat.Rating.Craft] Combat.Rating.Craft_player_instance_handler Loaded");
		}
        void OnLogin(Player* player, bool /*firstLogin*/) override
		{
			// Announce Module
			if (sConfigMgr->GetBoolDefault("Combat.Rating.Craft.Announce", true))
			{
				ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Combat Rating.Craft V2 |rmodule.");
			}
		}
		void OnMapChanged(Player *player) override
		{
			Map *map = player->GetMap();
			int difficulty = CalculateDifficulty(map, player);
			int numInGroup = GetNumInGroup(player);
			ApplyBuffs(player, map, difficulty, numInGroup);
		}
	private:
		std::map<ObjectGuid, int> _unitDifficulty;

		int CalculateDifficulty(Map *map, Player */*player*/)
		{
			int difficulty = 1;
			{
				if (map->IsDungeon())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Dungeon", 5));
				}
				else if (map->IsNonRaidDungeon())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Heroic", 10));
				}
				else if (map->IsHeroic())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Raid10", 10));
				}
				if (map->Is25ManRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Raid25", 25));
				}
				else if (map->IsHeroicPlusRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Raid30", 30));
				}
				else if (map->IsRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Raid40", 40));
				}
				else if (map->IsMythicRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("Combat.Rating.Craft.Mythic", 15));
				}
			}
			return difficulty;
		}

		int GetNumInGroup(Player *player)
		{
			int numInGroup = 1;
			Group *group = player->GetGroup();
			if (group)
			{
				Group::MemberSlotList const& groupMembers = group->GetMemberSlots();
				numInGroup = groupMembers.size();
			}
			return numInGroup;
		}

		void ApplyBuffs(Player *player, Map *map, int difficulty, int numInGroup)
		{
			ClearBuffs(player, map);
			if (difficulty > 1)
			{
				//InstanceMap *instanceMap = map->ToInstanceMap();
				//InstanceScript *instanceScript = instanceMap->GetInstanceScript();

				// Announce to player
				std::ostringstream ss;
				ss << "|cffFF0000[Combat Rating Craft V2] |cffFF8000" << player->GetName() << " entered %s - # of Players: %d - Difficulty Offset: %0.2f.";
				ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), numInGroup, difficulty + 0.0);

				_unitDifficulty[player->GetGUID()] = difficulty;

				bool m_CombatRatingCraft = sConfigMgr->GetBoolDefault("Combat.Rating.Craft.Enable", false);
				if (m_CombatRatingCraft)
				{
					player->ApplyRatingMod(CR_MASTERY, difficulty * 100, true);
					player->ApplyRatingMod(CR_AMPLIFY, difficulty * 100, true);
					player->ApplyRatingMod(CR_BLOCK, difficulty * 100, true);
					player->ApplyRatingMod(CR_HIT_RANGED, difficulty * 100, true);
					player->ApplyRatingMod(CR_HIT_SPELL, difficulty * 100, true);
					player->ApplyRatingMod(CR_CRIT_RANGED, difficulty * 100, true);
					player->ApplyRatingMod(CR_CRIT_SPELL, difficulty * 100, true);
					player->ApplyRatingMod(CR_RESILIENCE_CRIT_TAKEN, difficulty * 100, true);
					player->ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE, difficulty * 100, true);
					player->ApplyRatingMod(CR_AVOIDANCE, difficulty * 100, true);
					player->ApplyRatingMod(CR_STURDINESS, difficulty * 100, true);
					player->ApplyRatingMod(CR_EXPERTISE, difficulty * 100, true);
					player->ApplyRatingMod(CR_ARMOR_PENETRATION, difficulty * 100, true);
					player->ApplyRatingMod(CR_CLEAVE, difficulty * 100, true);
					player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_DONE, difficulty * 100, true);
					player->ApplyRatingMod(CR_VERSATILITY_HEALING_DONE, difficulty * 1000, true);
					player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_TAKEN, difficulty * 100, true);


					player->RemoveAurasDueToSpell(300047);
					player->AddAura(300047, player);

					player->SetFullHealth();
					if (player->GetPowerType() == POWER_MANA)
					{
						player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));

					}
				}
			}
		}

		void ClearBuffs(Player *player, Map *map)
		{
			std::map<ObjectGuid, int>::iterator unitDifficultyIterator = _unitDifficulty.find(player->GetGUID());
			if (unitDifficultyIterator != _unitDifficulty.end())
			{
				int difficulty = unitDifficultyIterator->second;
				_unitDifficulty.erase(unitDifficultyIterator);

				// Inform the player
				std::ostringstream ss;
				ss << "|cffFF0000[Combat Rating Craft V2] |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f.";
				ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), difficulty + 0.0);

				bool m_CombatRatingCraft = sConfigMgr->GetBoolDefault("Combat.Rating.Craft.Enable", false);
				if (m_CombatRatingCraft)
				{
					player->ApplyRatingMod(CR_MASTERY, difficulty * 100, false);
					player->ApplyRatingMod(CR_AMPLIFY, difficulty * 100, false);
					player->ApplyRatingMod(CR_BLOCK, difficulty * 100, false);
					player->ApplyRatingMod(CR_HIT_RANGED, difficulty * 100, false);
					player->ApplyRatingMod(CR_HIT_SPELL, difficulty * 100, false);
					player->ApplyRatingMod(CR_CRIT_RANGED, difficulty * 100, false);
					player->ApplyRatingMod(CR_CRIT_SPELL, difficulty * 100, false);
					player->ApplyRatingMod(CR_RESILIENCE_CRIT_TAKEN, difficulty * 100, false);
					player->ApplyRatingMod(CR_RESILIENCE_PLAYER_DAMAGE, difficulty * 100, false);
					player->ApplyRatingMod(CR_AVOIDANCE, difficulty * 100, false);
					player->ApplyRatingMod(CR_STURDINESS, difficulty * 100, false);
					player->ApplyRatingMod(CR_EXPERTISE, difficulty * 100, false);
					player->ApplyRatingMod(CR_ARMOR_PENETRATION, difficulty * 100, false);
					player->ApplyRatingMod(CR_CLEAVE, difficulty * 100, false);
					player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_DONE, difficulty * 100, false);
					player->ApplyRatingMod(CR_VERSATILITY_HEALING_DONE, difficulty * 1000, false);
					player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_TAKEN, difficulty * 100, false);

					player->RemoveAurasDueToSpell(300047);
				}

			}
		}
	};

}

void AddSC_CombatRatingCraft()
{
	new CombatRatingCraft_player_instance_handler();
}
