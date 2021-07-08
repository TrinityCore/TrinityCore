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
	DATA_zone_Sanctum_of_Domination,
	DATA_The_Tarragrue ,
	DATA_The_Eye_of_the_Jailer,
	DATA_The_Nine,
	DATA_Remnant_of_Nerzhul,
	DATA_Soulrender_Dormazain,
	DATA_Painsmith_Raznal,
	DATA_Guardian_of_the_First_Ones,
	DATA_Fatescribe_Roh_Kalo,
	DATA_KelThuzad,
	DATA_Sylvanas_Windrunner,
};

enum Creatures
{
	NPC_The_Tarragrue = 152253,
	NPC_The_Eye_of_the_Jailer = 180018,
	NPC_The_Nine = 178738,
	NPC_Remnant_of_Nerzhul = 175729,
	NPC_Soulrender_Dormazain = 175727,
	NPC_Painsmith_Raznal = 176523,
	NPC_Guardian_of_the_First_Ones = 175731,
	NPC_Fatescribe_Roh_Kalo = 179390,
	NPC_KelThuzad = 15990,
	NPC_Sylvanas_Windrunner = 180828,
};