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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

const Position pos = { };

enum Spells
{
    SPELL_CONSUME_CHARGE = 266512,
    SPELL_CAPACITANCE = 266511,
    SPELL_INDUCTION = 265974,
    //Energy core
    SPELL_BEAM = 265973,
    SPELL_ENERGY_CORE_VISUAL = 265977,
    SPELL_SUMMON_ENERGY_CORE = 274006,
    SPELL_ARC = 265986,
    SPELL_GALVANIZE = 266923,
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_ENERGY_CORE,
    EVENT_INDUCTION,

    EVENT_CHECK_INBETWEEN,
    EVENT_CONSUME_CHARGE,
};

//enum Timers
////133389
//struct boss_galvazzt : public BossAI
//{
//    TIMER_CHECK_ENERGY = 1 * IN_MILLISECONDS,
//    TIMER_ENERGY_CORE = 15 * IN_MILLISECONDS,
//    TIMER_INDUCTION = 5 * IN_MILLISECONDS,
//    boss_galvazzt(Creature* creature) : BossAI(creature, DATA_GALVAZZT) 
//    {
//        me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
//    }
//
//    TIMER_CHECK_INBETWEEN = 1 * IN_MILLISECONDS,
//};
//private:
//    uint8 energyCore;
//
//enum Creatures
//    void Reset() override
//    {
//    BOSS_GALVAZZT = 133389,
//    NPC_ENERGY_CORE_BFA = 135445,
//        BossAI::Reset();
//        me->SetPowerType(POWER_ENERGY);
//        me->SetMaxPower(POWER_ENERGY, 100);
//        me->SetPower(POWER_ENERGY, 0);
//        me->AddAura(AURA_OVERRIDE_POWER_COLOR_OCEAN);
//        this->energyCore = 0;
//    }
//
//    void EnterCombat(Unit* who) override
//    {
//        _EnterCombat();
//        events.ScheduleEvent(EVENT_ENERGY_CORE, 15s);
//    }
//
//    void ExecuteEvent(uint32 eventId) override
//    {
//        if (me->GetPower(POWER_ENERGY) == 100)
//        {
//            me->SetPower(POWER_ENERGY, 0);
//            me->CastSpell(nullptr, SPELL_CONSUME_CHARGE, false);
//        }
//        switch (eventId)
//        {
//        case EVENT_ENERGY_CORE:
//            for (uint8 i = 0; i < 3; i++)
//            {                
//                me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_SUMMON_ENERGY_CORE, true);
//            }
//            events.Repeat(15s, 30s);
//            break;
//        }
//    }
//
//    void EnterEvadeMode(EvadeReason /*why*/) override
//    {
//        me->DespawnCreaturesInArea(NPC_ENERGY_CORE, 125.0f);
//    }
//
//    void JustDied(Unit* u) override
//    {
//        _JustDied();
//        me->DespawnCreaturesInArea(NPC_ENERGY_CORE, 125.0f);
//        if (auto* GalvazztDoor = me->FindNearestGameObject(GO_GALVAZZT_EXIT, 100.0f))
//            GalvazztDoor->SetGoState(GO_STATE_ACTIVE);
//    }
//};
//
//const Position centerPos = { 3704.30f, 3412.07f, 6.75f }; //30y
////135445
//struct npc_energy_core : public ScriptedAI
//{
//    npc_energy_core(Creature* c) : ScriptedAI(c) { }
//
//private: 
//    uint32 Timer = 0;
//
//    void Reset() override
//    {
//        ScriptedAI::Reset();
//        me->SetReactState(REACT_PASSIVE);
//        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC));
//        me->CastSpell(nullptr, SPELL_ENERGY_CORE_VISUAL, true);
//        me->CastSpell(nullptr, SPELL_ARC, true);
//        me->GetOwnerGUID();
//    }
//
//    void Initialize()
//    {
//        Timer = 0;
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (Timer <= diff)
//        {
//            if (Unit* owner = me->GetOwner())
//            {
//                if (owner->IsInCombat())
//                {
//                    if (Player* player = me->SelectNearestPlayer(5.0f))
//                    {
//                        me->CastSpell(player, SPELL_GALVANIZE, true);
//                        return;
//                    }
//                    else
//                    {
//                        if (Creature* galvazzt = me->FindNearestCreature(NPC_GALVAZZT, 100.0f, true))                            
//                            galvazzt->ModifyPower(POWER_ENERGY, +1);
//                    }
//                }
//                Timer = 1000;
//            }
//        }
//        else Timer -= diff;
//    }
//};
//
//void AddSC_boss_galvazzt()
//{
//   
//    RegisterCreatureAI(boss_galvazzt);
//    RegisterCreatureAI(npc_energy_core);
//}
