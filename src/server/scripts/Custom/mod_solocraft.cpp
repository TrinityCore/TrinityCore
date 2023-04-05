/*
SPP Praevius Core Solocraft V2
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

    class solocraft_player_instance_handler : public PlayerScript
    {

    public:
        solocraft_player_instance_handler() : PlayerScript("solocraft_player_instance_handler")
        {
            TC_LOG_INFO("scripts.solocraft.player.instance", "[Solocraft] solocraft_player_instance_handler Loaded");
        }
        void OnLogin(Player* player, bool /*firstLogin*/) override
        {
            // Announce Module
            if (sConfigMgr->GetBoolDefault("Solocraft.Announce", true))
            {
                ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00SoloCraft V2 |rmodule.");
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
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Dungeon", 5));
                }
                else if (map->IsNonRaidDungeon())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Heroic", 10));
                }
                else if (map->IsHeroic())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Raid10", 10));
                }
                if (map->Is25ManRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Raid25", 25));
                }
                else if (map->IsHeroicPlusRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Raid30", 30));
                }
                else if (map->IsRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Raid40", 40));
                }
                else if (map->IsMythicRaid())
                {
                    difficulty = (sConfigMgr->GetIntDefault("Solocraft.Mythic", 15));
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

        void ApplyBuffs(Player* player, Map* map, int difficulty, int numInGroup)   //进副本公告在此处修改
        {
            ClearBuffs(player, map);
            if (difficulty > 1)
            {
                //InstanceMap *instanceMap = map->ToInstanceMap();
                //InstanceScript *instanceScript = instanceMap->GetInstanceScript();

                // Announce to player
                // 给玩家发送公告
                std::ostringstream ss;
                ss << "|cffFF0000[SoloCraft V2] |cffFF8000" << player->GetName() << " entered %s - # of Players: %d - Difficulty Offset: %0.2f.";
                //ss << "|cffFF0000[单人战斗 版本2] |cffFF8000" << player->GetName() << " 进入了副本 %s - # 玩家人数: %d - Difficulty Offset: %0.2f.";
                ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), numInGroup, difficulty + 0.0);

                _unitDifficulty[player->GetGUID()] = difficulty;

                bool m_Solocraft = sConfigMgr->GetBoolDefault("Solocraft.Enable", false);
                if (m_Solocraft)
                {
                    int SpellPowerBonus = 0;
                    SpellPowerBonus = static_cast<int>((player->GetLevel() * difficulty) * difficulty);
                    player->ApplySpellPowerBonus(SpellPowerBonus, true);
                    //player->ApplySpellPowerBonus(difficulty * 100, true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_MAINHAND), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_OFFHAND), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_RANGED), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ATTACK_POWER), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ATTACK_POWER_RANGED), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_MANA), TOTAL_VALUE, float(difficulty * 50), true);// Total mana
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_HEALTH), TOTAL_VALUE, float(difficulty * 50), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RAGE), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_FOCUS), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ENERGY), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_COMBO_POINTS), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RUNIC_POWER), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_SOUL_SHARDS), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_HOLY_POWER), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_CHI), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_INSANITY), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ARCANE_CHARGES), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_FURY), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_PAIN), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ARMOR), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_HOLY), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_FIRE), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_NATURE), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_FROST), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_SHADOW), TOTAL_VALUE, float(difficulty * 100), true);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_ARCANE), TOTAL_VALUE, float(difficulty * 100), true);
                    player->ApplyRatingMod(CR_MASTERY, difficulty * 100, true);
                    player->ApplyRatingMod(CR_AMPLIFY, difficulty * 100, true);
                    player->ApplyRatingMod(CR_BLOCK, difficulty * 100, true);
                    player->ApplyRatingMod(CR_HIT_MELEE, difficulty * 100, true);
                    player->ApplyRatingMod(CR_HIT_RANGED, difficulty * 100, true);
                    player->ApplyRatingMod(CR_HIT_SPELL, difficulty * 100, true);
                    player->ApplyRatingMod(CR_CRIT_MELEE, difficulty * 100, true);
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
                    player->ApplyRatingMod(CR_VERSATILITY_HEALING_DONE, difficulty * 100, true);
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

        void ClearBuffs(Player* player, Map* map)
        {
            std::map<ObjectGuid, int>::iterator unitDifficultyIterator = _unitDifficulty.find(player->GetGUID());
            if (unitDifficultyIterator != _unitDifficulty.end())
            {
                int difficulty = unitDifficultyIterator->second;
                _unitDifficulty.erase(unitDifficultyIterator);

                // Inform the player
                //通知玩家
                std::ostringstream ss;
                ss << "|cffFF0000[SoloCraft V2] |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f.";
                //ss << "|cffFF0000[单人战斗 版本2] |cffFF8000" << player->GetName() << " 退出了 %s - 恢复难度设置: %0.2f.";
                ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), difficulty + 0.0);

                bool m_Solocraft = sConfigMgr->GetBoolDefault("Solocraft.Enable", false);
                if (m_Solocraft)
                {
                    int SpellPowerBonus = 0;
                    SpellPowerBonus = static_cast<int>((player->GetLevel() * difficulty) * difficulty);
                    player->ApplySpellPowerBonus(SpellPowerBonus, false);
                    //player->ApplySpellPowerBonus(difficulty * 100, false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_MAINHAND), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_OFFHAND), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_DAMAGE_RANGED), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ATTACK_POWER), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ATTACK_POWER_RANGED), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_MANA), TOTAL_VALUE, float(difficulty * 50), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_HEALTH), TOTAL_VALUE, float(difficulty * 50), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RAGE), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_FOCUS), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ENERGY), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_COMBO_POINTS), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RUNIC_POWER), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_SOUL_SHARDS), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_HOLY_POWER), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_CHI), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_INSANITY), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ARCANE_CHARGES), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_FURY), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_PAIN), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_ARMOR), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_HOLY), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_FIRE), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_NATURE), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_FROST), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_SHADOW), TOTAL_VALUE, float(difficulty * 100), false);
                    player->HandleStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_ARCANE), TOTAL_VALUE, float(difficulty * 100), false);
                    player->ApplyRatingMod(CR_MASTERY, difficulty * 100, false);
                    player->ApplyRatingMod(CR_AMPLIFY, difficulty * 100, false);
                    player->ApplyRatingMod(CR_BLOCK, difficulty * 100, false);
                    player->ApplyRatingMod(CR_HIT_MELEE, difficulty * 100, false);
                    player->ApplyRatingMod(CR_HIT_RANGED, difficulty * 100, false);
                    player->ApplyRatingMod(CR_HIT_SPELL, difficulty * 100, false);
                    player->ApplyRatingMod(CR_CRIT_MELEE, difficulty * 100, false);
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
                    player->ApplyRatingMod(CR_VERSATILITY_HEALING_DONE, difficulty * 100, false);
                    player->ApplyRatingMod(CR_VERSATILITY_DAMAGE_TAKEN, difficulty * 100, false);

                    player->RemoveAurasDueToSpell(300047);
                }

            }
        }
    };

}

void AddSC_solocraft()
{
    new solocraft_player_instance_handler();
}
