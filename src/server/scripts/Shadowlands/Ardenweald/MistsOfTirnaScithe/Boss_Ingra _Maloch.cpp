///*
// * Copyright 2021 
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
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraEffects.h"
//#include "ScriptMgr.h"
//#include "Player.h"
//#include "InstanceScript.h"
//#include "instance_mists_of_tirna_scithe.cpp"
//#include "zone_mists_of_tirna_scithe.cpp"
//#include "zone_mists_of_tirna_scithe.h"
//#include "Objects_Mist_Of_Tirna_Scithe.h"
//#include "npc_Mist_Of_Tirna_Scithe.h"
//
//
//
//
//class Boss_Ingra_Maloch : public InstanceMapScript
//{
//public:
//    Boss_Ingra_Maloch() : InstanceMapScript("Boss_Ingra_Maloch", 13309) { }
//
//    InstanceScript* GetInstanceScript(InstanceMap* map) const
//    {
//        return new instance_mists_of_tirna_scithe_InstanceMapScript(map);
//    }
//
//    struct Boss_Ingra_Maloch_InstanceMapScript : public InstanceScript
//    {
//        uint64 Boss_Ingra_Maloch;
//        uint64 portalTemp instance_mist_of_tirna_scitheGuid;
//    };
//    
//    enum Spells
//{
//    SPELL_Soul_Shackle = 321010,
//    EVENT_Soul_Shackle_START = 0,
//    EVENT_Soul_Shackle_END = 1,
//};
//
////164567
//struct Boss_Ingra_Maloch : public BossAI
//{
//    Boss_Ingra_Maloch(Creature* creature) : BossAI(creature, DATA_INGRA_MALOCH) { }
// std::list<uint64> Boss_Ingra_Maloch;
//
//npc_Droman_Oulfarran yells "Pain...Confussion..."
//npc_Ingra_Maloch yells "You will do my bidding!"
//npc_Droman_Oulfarran yells "You must...endure.."
//npc_Ingra_Maloch yells "Obey me!"
//npc_Droman_Oulfarran yells "You must...endure.."
//npc_Ingra_Maloch yells "Darkness...surrounds me!"
//npc_Ingra_Maloch yells "I will break you intro splinters!"
//npc_Droman_Oulfarran yells "I cannot...control it"
//npc_Ingra_Maloch yells "Obey me!"
//
