///*
// * Copyright 2023 AzgathCore
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
//#include "ScriptMgr.h"
//#include "Player.h"
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraEffects.h"
//#include "necrotic_wake.h"
//#include "npc_Bastion"
//#include "objects_Bastion"
//
//enum Spells
//{
//    SPELL_FINAL_HARVEST = 321247,
//    SPELL_LAND_OF_THE_DEAD = 321226,
//    SPELL_FINAL_HARVEST = 321247,
//    SPELL_NECROTIC_BOLT = 320170,
//    SPELL_UNHOLY_FRENZY = 320012,
//    EVENT_LAND_OF_THE_DEAD = 1,
//    EVENT_NECROTIC_BREATH
//};
//
////163157
//struct boss_nalthor : public BossAI
//{
//    boss_nalthor(Creature* creature) : BossAI(creature, DATA_AMARTH) 
//    { 
//        Vehicle* vehicle = me->GetVehicleKit();
//    }
//
//    void Reset() override
//    {
//        BossAI::Reset();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        Talk(0);
//        events.ScheduleEvent(SPELL_NECROTIC_BOLT, 3s);
//        events.ScheduleEvent(EVENT_LAND_OF_THE_DEAD, 5s);
//        events.ScheduleEvent(SPELL_FINAL_HARVEST, 8s);
//        events.ScheduleEvent(EVENT_NECROTIC_BREATH, 10s);
//        if (Creature* amarth = me->FindNearestCreature(NPC_NALTHOR, 30.0f, true))
//            amarth->EnterVehicle(me);
//    }
//
//    void OnSpellFinished(SpellInfo const* spellInfo)
//    {
//        switch (spellInfo->Id)
//        {
//        case SPELL_FINAL_HARVEST:
//            DoCastAOE(SPELL_FINAL_HARVEST_DAMAGE, true);
//            break;
//        }
//    }
//
//    void ExecuteEvent(uint32 eventId) override
//    {
//        switch (eventId)
//        {
//        case SPELL_NECROTIC_BOLT:
//            DoCastVictim(SPELL_NECROTIC_BOLT, false);
//            events.Repeat(15s);
//            break;
//
//        case EVENT_LAND_OF_THE_DEAD:
//            me->CastSpell(nullptr, SPELL_LAND_OF_THE_DEAD_CAST, false);
//            me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_LAND_OF_THE_DEAD_MISSILE, true);
//            me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_LAND_OF_THE_DEAD_MISSILE_SECOND, true);
//            me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_LAND_OF_THE_DEAD_MISSILE_THIRD, true);
//            events.Repeat(20s);
//            break;
//
//        case SPELL_FINAL_HARVEST:
//            me->CastSpell(nullptr, SPELL_FINAL_HARVEST, false);
//            events.Repeat(25s);
//            break;
//
//        case EVENT_NECROTIC_BREATH:            
//            SetCombatMovement(false);
//            me->AddAura(SPELL_NECROTIC_BREATH_TRIGGER, me);
//            events.Repeat(30s);
//            break;
//        }
//    }
//
//    void JustReachedHome() override
//    {
//        _JustReachedHome();
//        me->RemoveAllAreaTriggers();
//    }
//
//    void JustDied(Unit* /*who*/) override
//    {
//        _JustDied();
//        Talk(1);
//        me->RemoveAllAreaTriggers();
//    }
//};
//
////162692
//struct npc_nalthor : public ScriptedAI
//{
//    npc_nalthor(Creature* c) : ScriptedAI(c) { }
//
//    void Reset() override
//    {
//        ScriptedAI::Reset();
//        me->SetReactState(REACT_PASSIVE);
//        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
//    }
//};
//
//void void AddSC_boss_nalthor()
//{
//    RegisterCreatureAI(boss_nalthor);
//    RegisterCreatureAI(npc_nalthor);
//}
