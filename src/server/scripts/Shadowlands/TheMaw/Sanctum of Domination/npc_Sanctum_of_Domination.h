/* 
 * Copyright 2021 Frozen
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
#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "Map.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "zone_the_maw.cpp"
#include "objects_Sanctum_of_Domination.h"
#include "Sanctum_of_Domination.h"
#include "zone_Sanctum_of_Domination.cpp"
#include "zone_Sanctum_of_Domination.h"
#include "instance_Sanctum_of_Domination.cpp"
#include "Sanctum_of_Domination.h"
#include "Boss_The_Tarragrue.cpp"
#include "Boss_The_Eye_of_the_Jailer.cpp"
#include "Boss_The_Nine"
#include "Boss_Remnant_of_Nerzhul.cpp"
#include "Boss_Soulrender_Dormazain.cpp"
#include "Boss_Painsmith_Raznal.cpp"
#include "Boss_Guardian_of_the_First_Ones.cpp"
#include "Boss_Fatescribe_Roh_Kalo.cpp"
#include "Boss_KelThuzad.cpp"
#include "Boss_Sylvanas_Windrunner.cpp"

enum NPC
{

 NPC_EYE_OF_THE_JAILER = "Eye_of_the_Jailer";                                   
 NPC_FATESCRIBE_ROH_KALO = "Fatescribe_Roh_Kalo";                                   
 NPC_GUARDIAN_OF_THE_FIRST_ONES = "Guardian_of_the_First_Ones";                           
 NPC_KELTHUZAD = "KelThuzad";                                            
 NPC_KYRA = "Kyra <The Unending>";                                   
 NPC_PAINSMITH_RAZNAL = "Painsmith_Raznal";                                      
 NPC_REMNANT_OF_NERZHUL = "Remnant_of_Nerzhul";                                    
 NPC_SOULRENDER_DORMAZAIN = "Soulrender_Dormazain";                                  
 NPC_SYLVANAS_WINDRUNNER = "Sylvanas_Windrunner";                                   
 NPC_THE_TARRAGRUE = "The_Tarragrue";                                         
 NPC_FATESPAWN_ANOMALY = "Fatespawn_Anomaly";                                    
 NPC_FATESPAWN_MONSTROSITY = "Fatespawn_Monstrosity";                                
 NPC_FROSTBOUND_DEVOTED = "Frostbound_Devoted";                                    
 NPC_HIGHLORD_BOLVAR_FORDRAGON = "Highlord_Bolvar_Fordragon <Knights of the Ebon Blade>";
 NPC_INFUSED_GOLIATH = "Infused_Goliath";                                       
 NPC_MAWSWORN_AGONIZER = "Mawsworn_Agonizer";                                    
 NPC_MAWSWORN_COMMANDER = "Mawsworn_Commander";                                    
 NPC_MAWSWORN_DARKCASTER = "Mawsworn_Darkcaster";                                   
 NPC_MAWSWORN_GUARD = "Mawsworn_Guard";                                       
 NPC_MAWSWORN_INTERCEPTOR = "Mawsworn_Interceptor";                                    
 NPC_MAWSWORN_OVEERLORD = "Mawsworn Overlord";                                     
 NPC_ORB_OF_TORMENT = "Orb_of_Torment";                                        
 NPC_REMNANT_OF_KELTHUZAD = "Remnant_of_KelThuzad";                                  
 NPC_SHADE_OF_DESTINY = "Shade_of_Destiny";                                      
 NPC_SIGNE = "Signe <The Voice>";                                     
 NPC_SKYJA = "Skyja <The First>";                                     
 NPC_SOUL_REAVER = "Soul_Reaver";                                           
 NPC_SPIKED_BALL = "Spiked_Ball";                                                                                     
 NPC_UNSTOPPABLE_ABOMINATION = "Unstoppable_Abomination"
 NPC_FORMLESS_MASS = "Formless_Mass"                                
};

enum Creatures
{

 NPC_EYE_OF_THE_JAILER                                      = 180018,
 NPC_FATESCRIBE_ROH_KALO                                    = 179390,
 NPC_GUARDIAN_OF_THE_FIRST_ONES                             = 175731,
 NPC_KELTHUZAD                                              = 175559,
 NPC_KYRA                                                   = 178738,
 NPC_PAINSMITH_RAZNAL                                       = 176523,
 NPC_REMNANT_OF_NERZHUL                                     = 175729,
 NPC_SOULRENDER_DORMAZAIN                                   = 175727,
 NPC_SYLVANAS_WINDRUNNER                                    = 180828,
 NPC_THE_TARRAGRUE                                          = 152253,175611,
 NPC_FATESPAWN_ANOMALY                                      = 179010,
 NPC_FATESPAWN_MONSTROSITY                                  = 180323,                         
 NPC_FROSTBOUND_DEVOTED                                     = 180840,                       
 NPC_HIGHLORD_BOLVAR_FORDRAGON                              = 178592,                        
 NPC_INFUSED_GOLIATH                                        = 176535,176537,176538,176539,     
 NPC_MAWSWORN_AGONIZER                                      = 177594,
 NPC_MAWSWORN_COMMANDER                                     = 178631,
 NPC_MAWSWORN_DARKCASTER                                    = 178628,
 NPC_MAWSWORN_GUARD                                         = 178623,
 NPC_MAWSWORN_INTERCEPTOR                                   = 178661,
 NPC_MAWSWORN OVEERLORD                                     = 179177,
 NPC_ORB_OF_TORMENT                                         = 177117,
 NPC_REMNANT_OF_KELTHUZAD                                   = 176929,
 NPC_SHADE_OF_DESTINY                                       = 179124,
 NPC_SIGNE                                                  = 178736,
 NPC_SKYJA                                                  = 178684,
 NPC_SOUL_REAVER                                            = 180474,
 NPC_SPIKED_BALL                                            = 176581,
 NPC_UNSTOPPABLE_ABOMINATION                                = 180473,
 NPC_FORMLESS_MASS                                          = 177407,
};

enum Quests
{
     Quests_Sanctum_of_Domination - Damned_If_You_Dont      = 64597,64598,
     Quests_Storming_the_Sanctum                            = 63903,
}

void OnCreatureCreate(Creature* creature) override
{
    switch (creature->GetEntry())
    {
     case NPC_EYE_OF_THE_JAILER:
          Eye_of_the_Jailer() = creature->GetGUID();
          break;
     };
     case NPC_NPC_FATESCRIBE_ROH_KALO:
          Fatescribe_Roh_Kalo() = creature->GetGUID();
          break;
     };
     case NPC_GUARDIAN_OF_THE_FIRST_ONES:
          Guardian_of_the_First_Ones() = creature->GetGUID();
          break;
     };
     case NPC_KELTHUZAD:
          KelThuzad() = creature->GetGUID();
          break;
     };
     case NPC_KYRA:
          Kyra() = creature->GetGUID();
          break;
     };
     case NPC_PAINSMITH_RAZNAL:
          Painsmith_Raznal() = creature->GetGUID();
          break;
     };
     case NPC_REMNANT_OF_NERZHUL:
          Remnant_of_Nerzhul() = creature->GetGUID();
          break;
     }
     case NPC_SOULRENDER_DORMAZAIN:
          Soulrender_Dormazain() = creature->GetGUID();
          break;
     }
     case NPC_SYLVANAS_WINDRUNNER:
          Sylvanas_Windrunner() = creature->GetGUID();
          break;
     }
     case NPC_THE_TARRAGRUE:
          The_Tarragrue() = creature->GetGUID();
          break;
     }
     case NPC_FATESPAWN_ANOMALY:
          Fatespawn_Anomaly() = creature->GetGUID();
          break;
     };
     case NPC_FATESPAWN_MONSTROSITY:
          Fatespawn_Monstrosity() = creature->GetGUID();
          break;
     };
     case NPC_FROSTBOUND_DEVOTED:
          Frostbound_Devoted() = creature->GetGUID();
          break;
     };
     case NPC_HIGHLORD_BOLVAR_FORDRAGON:
          Highlord_Bolvar_Fordragon() = creature->GetGUID();
          break;
     };
     case NPC_INFUSED_GOLIATH:
          Infused_Goliath() = creature->GetGUID();
          break;
     };
     case NPC_MAWSWORN_AGONIZER:
          Mawsworn_Agonizer() = creature->GetGUID();
          break;
     };
     case NPC_MAWSWORN_COMMANDER:
          Mawsworn_Commander() = creature->GetGUID();
          break;
     };
     case NPC_MAWSWORN_DARKCASTER:
          Mawsworn_Darkcaster() = creature->GetGUID();
          break;
     };
     case NPC_MAWSWORN_GUARD:
          Mawsworn_Guard() = creature->GetGUID();
          break;
     };  
     case NPC_MAWSWORN_INTERCEPTOR:
          Mawsworn_Interceptor() = creature->GetGUID();
          break;
     };
     case NPC_MAWSWORN_OVEERLORD:
          Mawsworn_Overlord() = creature->GetGUID();
          break;
     };
     case NPC_ORB_OF_TORMENT:
          Orb_of_Torment() = creature->GetGUID();
          break;
     };
     case NPC_REMNANT_OF_KELTHUZAD:
          Remnant_of_KelThuzad() = creature->GetGUID();
          break;
     };
     case NPC_SHADE_OF_DESTINY:
          Shade_of_Destiny() = creature->GetGUID();
          break;
     };
     case NPC_SIGNE:
          Signe() = creature->GetGUID();
          break;
     };
     case NPC_SKYJA:
          Skyja() = creature->GetGUID();
          break;
     };
     case NPC_SOUL_REAVER:
          Soul_Reaver() = creature->GetGUID();
          break;
     };
     case NPC_SPIKED_BALL:
          Spiked_Ball() = creature->GetGUID();
          break;
     };
     case NPC_UNSTOPPABLE_ABOMINATION:
          Unstoppable_Abomination() = creature->GetGUID();
          break;
     };                             
};                                               

void AddSC_Sanctum_of_Domination()
{
   RegisterInstanceScript(mode_LFR);
   RegisterInstanceScript(mode_N);
   RegisterInstanceScript(mode_HC;
   RegisterInstanceScript(mode_Mythic);
};