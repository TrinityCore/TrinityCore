///*
// * Copyright 2021 FuzionCore Project
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
///* Script Data Start
//SDName: 
//SDAuthor: Frozen
//SD%Complete: %
//SDComment: still working on structure.
//Script Data End */
//
//#include "ScriptMgr.h"
//#include "GameObject.h"
//#include "Player.h"
//#include "ObjectAccessor.h"
//#include "PassiveAI.h"
//#include "ScriptedCreature.h"
//#include "ScriptedGossip.h"
//#include "TaskScheduler.h"
//#include "TemporarySummon.h"
//#include "GameObjectAI.h"
//#include "zone_Sanctum_of_Domination.h"
//
//enum SanctumOfDomination
//{
//    THE_TARRAGRUE                      = 152253,
//    EYE_OF_THE_JAILER                  = 180018,
//
//    QUEST_DAMNED_IF_YOU_DONT           = 64597,64598,
//    QUEST_STORMING_THE_SANCTUM         = 63903,
//
//    AREA_SANCTUM_OF_DOMINATION         = 13561,
//};
//
////178592
//struct npc_Highlord_Bolvar_Fordragon_178592 : public ScriptedAI
//{
//    npc_Highlord_Bolvar_Fordragon_178592(Creature* creature) : ScriptedAI(creature) { }
//
//    void OnClick(Unit* clicker, bool& /*result*/) override
//    {
//        if (Player* player) = GetQuest(64597);
//        return;
//        if (Player* player) = GetQuest(64598);
//        return;
//        if (Player* player) = GetQuest(63903);
//        return;
//        if (Player* player = clicker->npc_Highlord_Bolvar_Fordragon_178592())
//        {
//            if (player->GetQuestStatus(QUEST_DAMNED_IF_YOU_DONT) == QUEST_STATUS_INCOMPLETE)
//            {
//                clicker->ToPlayer()->Phylactery_Shard(187529);
//                me->CollectItem(ITEM_PHYLACTERY_SHARD);
//                PHYLACTERY_SHARD->npc_kelthuzad_175559;
//                {
//                    if (me && player)
//                    {
//                        player->KilledNpc_kelthuzad_175559(175559);
//                        player->Loot(187529)->Npc_kelthuzad_175559();
//                    };
//                };
//            }
//            if (player->GetQuestStatus(QUEST_DAMNED_IF_YOU_DONT) == QUEST_STATUS_COMPLETE)
//            {
//                if (me && player)    
//                {
//                    player->GetLoot(187529) = 4;
//                }
//            }    
//        }
//    }
//private:
//    TaskScheduler _scheduler;
//    std::unordered_set<uint32> _randomEmotes;
//};
//
//class sanctum_of_domination : public PlayerScript
//{
//public:
//    sanctum_of_domination() : PlayerScript("sanctum_of_domination") { }
//
//    void OnLogin(Player* player,bool /*fristlogin*/) override
//    {
//        // Set zone as Raid
//        if (player->GetMapId() == AREA_SANCTUM_OF_DOMINATION)
//            player->GoMapId()  == GetMapId;
//    }
//        
//        void OnUpdateArea(Player* player, uint32 /*newArea*/, uint32 /*oldArea*/) override
//    {
//        // Set zone as Raid
//        if (player->GetMapId() == MAP_NPE)
//            player->GoMapId()  == GetMapId;
//    }
//};
//
//class sanctum_of_domination : public ZoneScript
//{
//public:
//    zone_sanctum_of_domination() : ZoneScript("zone_sanctum_of_domination") { }
//
//    void OnPlayerExit(Player* player) override
//    {
//        // Remove sanctuary flag when leaving sanctum of domination
//        player->GoOutside(sanctum_of_domination);
//    }
//};
//    
//
///*
// * Copyright 2021 FuzionCore Project
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
///* Script Data Start
//SDName: 
//SDAuthor: Frozen
//SD%Complete: %
//SDComment: still working on structure.
//Script Data End */
//
//#include "ScriptMgr.h"
//#include "GameObject.h"
//#include "Player.h"
//#include "ObjectAccessor.h"
//#include "PassiveAI.h"
//#include "ScriptedCreature.h"
//#include "ScriptedGossip.h"
//#include "TaskScheduler.h"
//#include "TemporarySummon.h"
//#include "GameObjectAI.h"
///*
// * Copyright (C) 2021
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//#include "ScriptMgr.h"
//#include "Player.h"
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraEffects.h"
//#include "Map.h"
//#include "InstanceScript.h"
//#include "Transport.h"
//#include "TransportMgr.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "zone_the_maw.cpp"
//#include "objects_Sanctum_of_Domination.h"
//#include "npc_Sanctum_of_Domination.h"
//#include "Sanctum_of_Domination.h" 
//#include "zone_Sanctum_of_Domination.h"
//#include "instance_Sanctum_of_Domination.cpp"
//#include "Sanctum_of_Domination.h"
//#include "Boss_The_Tarragrue.cpp"
//#include "Boss_The_Eye_of_the_Jailer.cpp"
//#include "Boss_The_Nine"
//#include "Boss_Remnant_of_Nerzhul.cpp"
//#include "Boss_Soulrender_Dormazain.cpp"
//#include "Boss_Painsmith_Raznal.cpp"
//#include "Boss_Guardian_of_the_First_Ones.cpp"
//#include "Boss_Fatescribe_Roh_Kalo.cpp"
//#include "Boss_KelThuzad.cpp"
//#include "Boss_Sylvanas_Windrunner.cpp"
//
//
//void AddSC_zone_Sanctum_of_Domination()
//{
//}
//
//void AddSC_Zone_De_Maw()
//{
//}
//
//void AddSC_Instance_Sanctum_of_Domination()
//{
//}
//
//void AddSC_Sanctum_of_Domination()
//{ 
//}    
//
//enum NPC
//{
//    NPC_1;
//}
//
//enum Objects
//{
//    Objects_1;
//}    
//
//enum Loot
//{
//    Loot_1;
//}
//
//enum phase
//{
//    phase_1;
//}
//
//enum Npcspawn
//{
//    spawnNpc_1;
//}    
//
//enum ObjectSpawn
//{
//    ObjectSpawn_1;
//}
//
//struct sanctum_of_domination : public InstanceScript
//enum Achievements
//{
//    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
//};
//    AHEAD_OF_THE_CURVE_SYLVANAS_WINDRUNNER                                          = 15134,
//    CUTTING_EDGE_SYLVANAS_WINDRUNNER                                                = 15135,
//    EYE_WISH_YOU_WERE_HERE                                                          = 15065,
//    FLAWLESS_FATE                                                                   = 15040,
//    HALL_OF_FAME_SYLVANAS_ALLIANCE                                                  = 15197,
//    HALL_OF_FAME_SYLVANAS_HORDE                                                     = 15196,
//    HEROIC_SANCTUM_OF_DOMINAIION                                                    = 15127,
//    HEROIC_SANCTUM_OF_DOMINAIION_GUILD_RUN                                          = 15183,
//    I_USED_TO_BULLSEYE_DEEPRUN_RATS_BACK_HOME                                       = 15058,
//    KNOWLEDGE_IS_POWER                                                              = 15132,
//    MYTHIC_FATESCRIBE_ROH_KALO                                                      = 15119,
//    MYTHIC_GUARDIAN_OF_THE_FIRST_ONES                                               = 15118,
//    MYTHIC_KELTHUZAD                                                                = 15120,
//    MYTHIC_PAINSMITH_RAZNAL                                                         = 15117,
//    MYTHIC_REMNANT_OF_NERZHUL                                                       = 15115,
//    MYTHIC_SANCTUM_OF_DOMINATION                                                    = 15128,
//    MYTHIC_SOULRENDER_DORMAZAIN                                                     = 15116,
//    MYTHIC_SYLVANAS_WINDRUNNER                                                      = 15121,
//    MYTHIC_SYLVANAS_WINDRUNNER_GUILD_RUN                                            = 15184,
//    MYTHIC_THE_EYE_OF_THE_JAILER                                                    = 15113,
//    MYTHIC_THE_NINE                                                                 = 15114,
//    MYTHIC_THE_TARRAGRUE                                                            = 15112,
//    NAME_A_BETTER_DUO_ILL_WAIT                                                      = 14998,
//    SANCTUM_OF_DOMINAIION                                                           = 15126,
//    SANCTUM_OF_DOMINAIION_GUILD_RUN                                                 = 15182,
//    SHACKLES_OF_FATE                                                                = 15124,
//    THE_DARK_BASTILLE                                                               = 15123,
//    THE_JAILERS_VANGUARD                                                            = 15122,
//    THE_RECKONING                                                                   = 15125,
//    THIS_WORLD_IS_A_PRISM                                                           = 15133,
//    TO_THE_NINES                                                                    = 15003,
//    TOGETHER_FOREVER                                                                = 15108,
//    TORMENTORS_TANGO                                                                = 15105,
//    WHACK_A_SOUL                                                                    = 15131,
//}
