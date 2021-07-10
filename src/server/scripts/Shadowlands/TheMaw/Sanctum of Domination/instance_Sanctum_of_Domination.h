/*
 * Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */
/*
 * Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */
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
#include "npc_Sanctum_of_Domination.h"
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
enum Data
{   
	DATA_npc_Sanctum_of_Domination
	DATA_Objects_Sanctum_of_Domination,
	DATA_instance_Sanctum_of_Domination,
	DATA_instance_Sanctum_of_Domination.h,
	DATA_zone_Sanctum_of_Domination,
	DATA_THE_TARRAGRUE,
	DATA_EYE_OF_THE_JAILER,
	DATA_THE_NINE,
	DATA_REMNANT_OF_NERZHUL,
	DATA_SOULRENDER_DORMAZAIN,
	DATA_PAINSMITH_RAZNAL,
	DATA_GUARDIAN_OF_THE_FIRST_ONES,
	DATA_FATESCRIBE_ROH_KALO,
	DATA_KELTHUZAD,
	DATA_SYLVANAS_WINDRUNNER,
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