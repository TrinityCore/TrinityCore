/*
SPP Praevius Core Leech Craft V2
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

//本脚本为副本急速增强脚本

namespace {

    class LeechCraft_player_instance_handler : public PlayerScript
    {

    public:
        LeechCraft_player_instance_handler() : PlayerScript("Leech.Craft_player_instance_handler")
        {
            TC_LOG_INFO("scripts.leech.player.instance", "[Leech Craft] Leech Craft_player_instance_handler Loaded");
        }
        void OnLogin(Player* player, bool /*firstLogin*/) override
        {
            // Announce Module
            //公告模块
            if (sConfigMgr->GetBoolDefault("Leech.Craft.Announce", true))
            {
                ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Leech Craft V2 |rmodule.");
                //ChatHandler(player->GetSession()).SendSysMessage("服务器正在运行 |cff4CFF00急速战斗 版本2 |r模块.");
            }
        }
        void OnMapChanged(Player* player) override
        {
            Map* map = player->GetMap();
            int difficulty = CalculateDifficulty(map, player);
            int numInGroup = GetNumInGroup(player);
            ApplyBuffs(player, map, difficulty, numInGroup);
        }
    private:
        std::map<ObjectGuid, int> _unitDifficulty;

        int CalculateDifficulty(Map* map, Player* /*player*/)
        {
            int difficulty = 1;
            {
                if (map->IsDungeon())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Dungeon", 5));
                }
                else if (map->IsNonRaidDungeon())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Heroic", 10));
                }
                else if (map->IsHeroic())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Raid10", 10));
                }
                if (map->Is25ManRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Raid25", 25));
                }
                else if (map->IsHeroicPlusRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Raid30", 30));
                }
                else if (map->IsRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Raid40", 40));
                }
                else if (map->IsMythicRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Leech.Craft.Mythic", 15));
                }
            }
            return difficulty;
        }

        int GetNumInGroup(Player* player)
        {
            int numInGroup = 1;
            Group* group = player->GetGroup();
            if (group)
            {
                Group::MemberSlotList const& groupMembers = group->GetMemberSlots();
                numInGroup = groupMembers.size();
            }
            return numInGroup;
        }

        void ApplyBuffs(Player* player, Map* map, int difficulty, int numInGroup)
        {
            ClearBuffs(player, map);
            if (difficulty > 1)
            {
                //InstanceMap *instanceMap = map->ToInstanceMap();
                //InstanceScript *instanceScript = instanceMap->GetInstanceScript();

                // Announce to player
                // 发送公告给玩家
                std::ostringstream ss;
                ss << "|cffFF0000[Leech Craft V2] |cffFF8000" << player->GetName() << " entered %s - # of Players: %d - Difficulty Offset: %0.2f.";
                //ss << "|cffFF0000[急速战斗 版本2] |cffFF8000" << player->GetName() << " 进入了副本 %s - # 队伍人数: %d - 难度设置为: %0.2f.";
                ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), numInGroup, difficulty + 0.0);

                _unitDifficulty[player->GetGUID()] = difficulty;

                bool m_LeechCraft = sConfigMgr->GetBoolDefault("Leech.Craft.Enable", false);
                if (m_LeechCraft)
                {
                    player->ApplyRatingMod(CR_LIFESTEAL, difficulty * 100, true);
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

        void ClearBuffs(Player* player, Map* map)
        {
            std::map<ObjectGuid, int>::iterator unitDifficultyIterator = _unitDifficulty.find(player->GetGUID());
            if (unitDifficultyIterator != _unitDifficulty.end())
            {
                int difficulty = unitDifficultyIterator->second;
                _unitDifficulty.erase(unitDifficultyIterator);

                // Inform the player
                std::ostringstream ss;
                ss << "|cffFF0000[Leech Craft V2] |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f.";
                ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), difficulty + 0.0);

                bool m_LeechCraft = sConfigMgr->GetBoolDefault("Leech.Craft.Enable", false);
                if (m_LeechCraft)
                {
                    player->ApplyRatingMod(CR_LIFESTEAL, difficulty * 100, false);
                    player->RemoveAurasDueToSpell(300047);
                }

            }
        }
    };

}

void AddSC_LeechCraft()
{
    new LeechCraft_player_instance_handler();
}
