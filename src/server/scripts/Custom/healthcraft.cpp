/*
SPP Praevius Core HealthCraft V2
Original Script Provided by Conanhun
Re-Written by MDic
*/
#include <map>

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

namespace {

	class HealthCraft_player_instance_handler : public PlayerScript
	{

	public:
		HealthCraft_player_instance_handler() : PlayerScript("HealthCraft_player_instance_handler")
		{
            TC_LOG_INFO("scripts.healthcraft.player.instance", "[HealthCraft] HealthCraft_player_instance_handler Loaded");
		}
        void OnLogin(Player* player, bool /*firstLogin*/) override
		{
			// Announce Module
			if (sConfigMgr->GetBoolDefault("HealthCraft.Announce", true))
			{
				ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00HealthCraft V2 |rmodule.");
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
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Dungeon", 5));
				}
				else if (map->IsNonRaidDungeon())
				{
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Heroic", 10));
				}
				else if (map->IsHeroic())
				{
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Raid10", 10));
				}
				if (map->Is25ManRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Raid25", 25));
				}
				else if (map->IsHeroicPlusRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Raid30", 30));
				}
				else if (map->IsRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Raid40", 40));
				}
				else if (map->IsMythicRaid())
				{
					difficulty = (sConfigMgr->GetIntDefault("HealthCraft.Mythic", 15));
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
				ss << "|cffFF0000[HealthCraft V2] |cffFF8000" << player->GetName() << " entered %s - # of Players: %d - Difficulty Offset: %0.2f.";
				ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), numInGroup, difficulty + 0.0);

				_unitDifficulty[player->GetGUID()] = difficulty;

				bool m_HealthCraft = sConfigMgr->GetBoolDefault("HealthCraft.Enable", false);
				if (m_HealthCraft)
				{
					player->HandleStatFlatModifier(UnitMods(UNIT_MOD_HEALTH), TOTAL_VALUE, float(difficulty * 50), true);

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
				ss << "|cffFF0000[HealthCraft V2] |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f.";
				ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), difficulty + 0.0);

				bool m_HealthCraft = sConfigMgr->GetBoolDefault("HealthCraft.Enable", false);
				if (m_HealthCraft)
				{
					player->HandleStatFlatModifier(UnitMods(UNIT_MOD_HEALTH), TOTAL_VALUE, float(difficulty * 50), false);
					player->RemoveAurasDueToSpell(300047);
				}

			}
		}
	};

}

void AddSC_HealthCraft()
{
	new HealthCraft_player_instance_handler();
}
