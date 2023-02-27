/////*
//// * Copyright 2023 AzgathCore
//// *
//// * This program is free software; you can redistribute it and/or modify it
//// * under the terms of the GNU General Public License as published by the
//// * Free Software Foundation; either version 2 of the License, or (at your
//// * option) any later version.
//// *
//// * This program is distributed in the hope that it will be useful, but WITHOUT
//// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//// * more details.
//// *
//// * You should have received a copy of the GNU General Public License along
//// * with this program. If not, see <http://www.gnu.org/licenses/>.
//// */
////
////#include "ScriptMgr.h"
////#include "Player.h"
////#include "Creature.h"
////#include "CreatureAI.h"
////#include "GameObject.h"
////#include "GameObjectAI.h"
////#include "AreaTrigger.h"
////#include "AreaTriggerAI.h"
////#include "SpellAuraEffects.h"
////#include "Map.h"
////#include "necrotic_wake.h"
////#include "necrotic_wake.h"
////#include "InstanceScript.h"
////#include "Transport.h"
////#include "TransportMgr.h"
////#include "AreaTrigger.h"
////#include "AreaTriggerAI.h"
////#include "necrotic_wake.h"
////#include "npc_necrotic_wake.h"
////#include "Objects_necrotic_wake.h"
////#include "npc_Data_NecroticWake.h"
////#include "Objects_Aura_NecroticWake.h"
////#include "Objects_Data_NecroticWake.h"
////#include "Objects_Effect_NecroticWake.h"
////#include "Objects_Spawn_NecroticWake.h"
////
////enum Spells
////{
////    SPELL_ANIMA_MISSILE = 335159,
////    SPELL_ANIMA_CREATE_AT = 335160,
////    SPELL_ANIMA_BUFF = 335161,
////    SPELL_COLLAPSED_GOLIATH = 335155,
////};
////
//////171750
////struct npc_malfunctioning_goliath : public ScriptedAI
////{
////    npc_malfunctioning_goliath(Creature* c) : ScriptedAI(c) { }
////
////    void Reset() override
////    {
////        ScriptedAI::Reset();
//////        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
////    }
////};
////
//////25432
////struct at_anima_exhaust : public AreaTriggerAI
////{
////    at_anima_exhaust(AreaTrigger* at) : AreaTriggerAI(at) { }
////
////    void OnUnitEnter(Unit* unit) override
////    {
////        if (!unit->IsPlayer())
////            return;
////
////        if (!unit->HasAura(SPELL_ANIMA_BUFF))
////            at->GetCaster()->AddAura(SPELL_ANIMA_BUFF, unit);
////    }
////};
////
////void AddSC_necrotic_wake()
////{
////    RegisterCreatureAI(npc_malfunctioning_goliath);
////    RegisterAreaTriggerAI(at_anima_exhaust);
////}
