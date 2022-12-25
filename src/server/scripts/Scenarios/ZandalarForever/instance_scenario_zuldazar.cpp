/*
 * Copyright 2023 AzgathCore
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
// #include "Player.h"
// #include "ScriptMgr.h"
// #include "CombatAI.h"
// #include "Creature.h"
// #include "CreatureGroups.h"
// #include "GameObject.h"
// #include "InstanceScript.h"
// #include "Scenario.h"
// #include "scenario_zuldazar.h"


// /*
//DoUpdateCriteria(CRITERIA_TYPE_KILL_CREATURE, eventId, 0, nullptr);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_MOUNT_OLD_K_ZLOTEC);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_BLOOD_TROLL_ARMY_SLAIN);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_SECURE_THE_BRIDGE_TO_DAZAR_ALOR);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_REACH_THE_ZOCALO);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_CIVILIANS_RESCUED);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_REACH_DAZAR_ALOR);
// DoSendScenarioEventByType(CRITERIA_TYPE_SEND_EVENT_SCENARIO, SCENARIO_EVENT_FIND_KING_RASTAKHAN_AT_THE_ENTRANCE_TO_DAZAR_ALOR);
// DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_REACH_ZUL);
//DoUpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, eventId, 0, nullptr);
// */

// struct instance_scenario_zuldazar : public InstanceScript
// {
    // instance_scenario_zuldazar(InstanceMap* map) : InstanceScript(map) { }

    // bool isFirstIntro = false;
    // uint32 SecondCount = 0;
    // bool isThirdIntro = false;
    // uint32 FiveCount1 = 0;
    // uint32 FiveCount2 = 0;

    // void OnPlayerEnter(Player* player) override
    // {
        // if (isFirstIntro)
            // return;

        // isFirstIntro = true;

        // player->GetScheduler().Schedule(2s, [=](TaskContext /*context*/)
        // {
            // DoPlayScenePackageIdOnPlayers(SCENE_1);
            // DoPlayScenePackageIdOnPlayers(SCENE_2);
        // });
    // }

    // void OnCompletedCriteriaTree(CriteriaTree const* tree) override
    // {
        // switch (tree->ID)
        // {
        // case CRITERIA_TREE_GATHER_YOUR_FORCES_AND_MOUNT_OLD_K_ZLOTEC:   break;
        // case CRITERIA_TREE_DESTROY_THE_NAZMANI_INVADERS_IN_THE_SLIVER:
            // DoOnPlayers([](Player* player)
            // {
                // player->GetScheduler().Schedule(10s, [=](TaskContext /*context*/)
                // {
                    // player->CompletedCriteriaTreeId(CRITERIA_TREE_SECURE_THE_BRIDGE_TO_DAZAR_ALOR);
                // });
            // });
            // break;
        // case CRITERIA_TREE_SECURE_THE_BRIDGE_TO_DAZAR_ALOR:
            // if (isThirdIntro)
                // return;

            // isThirdIntro = true;
//            ????? NPC_KRAGWA_THE_HUGE -496.65f, 574.15f, 220.54f, 6.269f
            // if (Creature* kragwa = GetKragwa())
            // {
                // kragwa->GetMotionMaster()->MoveJump(Position(-496.65f, 574.15f, 220.54f), 10.0f, 10.0f);
            // }
//           ????NPC NPC_PA_KU 
            // if (TempSummon* paku = instance->SummonCreature(NPC_PA_KU, Position(-545.9045f, 595.3007f, 222.849f)))
            // {
              
            // }
            // DoPlayConversation(7133);
            // break;
        // case CRITERIA_TREE_RIDE_PA_KU_TO_THE_ZOCALO:
            // DoPlayConversation(7135);
            // break;
        // case CRITERIA_TREE_RESCUE_THE_CIVILIANS_OF_THE_ZOCALO_AND_SLAY_THE_SETHRAK_ARMY_THERE:
            // DoOnPlayers([](Player* player)
            // {
                // player->GetScheduler().Schedule(5s, [=](TaskContext /*context*/)
                // {
//                   near teleport
                // });
            // });        
            // break;
        // case CRITERIA_TREE_JOIN_GONK_AND_HIS_PACK_AT_THE_BRIDGE_TO_DAZAR_ALOR:   break;
        // case CRITERIA_TREE_FIND_KING_RASTAKHAN_AT_THE_ENTRANCE_TO_DAZAR_ALOR:
            // if (TempSummon* bwonsamdi = instance->SummonCreature(NPC_BWONSAMDI, Position(-772.4f, 1021.5f, 323.384f, 0.73136f)))
            // {
                // bwonsamdi->CastSpell(bwonsamdi, 243010, true);
                // bwonsamdi->GetScheduler().Schedule(5s, [=](TaskContext /*context*/)
                // {
                    // DoPlayConversation(7440);
//                    267959 Call of the Dead
                    // bwonsamdi->CastSpell(bwonsamdi, 267959, true);
                // });
                // bwonsamdi->GetScheduler().Schedule(9s, [=](TaskContext /*context*/)
                // {
                    // std::list<Creature*> list;
                    // bwonsamdi->GetCreatureListWithEntryInGrid(list, NPC_RASTARI_SPIRIT);
                    // for (Creature* spirit : list)
                        // spirit->AI()->SetData(1, 1);                  
                // });
            // }
            // break;
        // case CRITERIA_TREE_ASSAULT_DAZAR_ALOR_TO_REACH_ZUL_BEFORE_HE_CAN_DESTROY_THE_PYRAMID:         
            // DoOnPlayers([](Player* player)
            // {
                // player->AddMovieDelayedAction(863, [player]
                // {
                    // player->TeleportTo(1642, Position(-1115.32f, 804.83f, 497.08f, 3.12117f));
                // });
                // player->SendMovieStart(863);
            // });
            // break;
        // default:
            // break;
        // }
    // }

    // void OnUnitDeath(Unit* unit) override
    // {
        // switch (unit->GetEntry())
        // {
        // case NPC_BLOOD_CRAWG:
        // case NPC_BLOOD_HEXXER:
        // case NPC_BLOOD_TROLL:
        // case NPC_SIEGE_MONSTROSITY:
        // case NPC_BLOOD_TROLL_WARMOTHER:
            // for (uint8 i = 1; i <= 10; ++i)
            // {
                // DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_BLOOD_TROLL_ARMY_SLAIN, 1);

                // SecondCount++;
            // }
//            KilledMonsterCredit
            // DoOnPlayers([](Player* player)
            // {
                // player->KilledMonsterCredit(SCENARIO_EVENT_BLOOD_TROLL_ARMY_SLAIN);
            // });
//            printf("first  entry=%u  kill count =%u \n", unit->GetEntry(), SecondCount);
            // if (SecondCount >= 200)
            // {
                // DoOnPlayers([](Player* player)
                // {
                    // player->CompletedCriteriaTreeId(CRITERIA_TREE_DESTROY_THE_NAZMANI_INVADERS_IN_THE_SLIVER);
                // });
            // }
            // break;
        // case NPC_SETHRAK_SKYCALLER:
        // case NPC_BLADESWORN_DIAMONDBACK:
        // case NPC_DIAMONDBACK_WARBRINGER:
            // FiveCount2++;
            // DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_SETHRAK_SLAIN, 1);
            // if (FiveCount1 >= 10 && FiveCount2 >= 10)
            // {
                // DoOnPlayers([](Player* player)
                // {
                    // player->CompletedCriteriaTreeId(CRITERIA_TREE_RESCUE_THE_CIVILIANS_OF_THE_ZOCALO_AND_SLAY_THE_SETHRAK_ARMY_THERE);
                // });
            // }
            // break;
        // }
    // }

    // void SetData(uint32 type, uint32 /*value*/) override
    // {
        // if (type == SCENARIO_EVENT_CIVILIANS_RESCUED)
        // {
            // FiveCount1++;
            // DoSendScenarioEventByType(CRITERIA_TYPE_KILL_CREATURE, SCENARIO_EVENT_CIVILIANS_RESCUED, 1);
            // if (FiveCount1 >= 10 && FiveCount2 >= 10)
            // {
                // DoOnPlayers([](Player* player)
                // {
                    // player->CompletedCriteriaTreeId(CRITERIA_TREE_RESCUE_THE_CIVILIANS_OF_THE_ZOCALO_AND_SLAY_THE_SETHRAK_ARMY_THERE);
                // });
            // }
        // }
    // }

    // Creature* GetKragwa() { return GetCreature(NPC_KRAGWA_THE_HUGE); }
// };

// void AddSC_instance_scenario_zuldazar()
// {
    // RegisterInstanceScript(instance_scenario_zuldazar, 1906);
// }
