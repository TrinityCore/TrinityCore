/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "cathedral_of_eternal_night.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum Says
{
    SAY_AGGRO           = 1,
    SAY_DEATH           = 2,
}; 

enum Spells
{
    SPELL_DEMONIC_UPHEAVAL              = 233196,  // 27 + script on remove (236370)
    SPELL_DARK_SOLITUDE                 = 234817, // 12   
    SPELL_CARRION_SWARM                 = 233155, // 18 + script on line attack (233175) + at (233177)
    SPELL_SHADOW_FADE                   = 233206,
    
    // while invis Phase 2
    SPELL_CREEPING_SHADOWS              = 234369,
    SPELL_SHADOW_FADE_VISUAL_DEST       = 239454,
    SPELL_INVIS_HIDE                    = 239428,
    SPELL_CONVERSATION_INVIS            = 242457,
    SPELL_INVIS_REMOVED                 = 234705,
    
    SPELL_ADD_DESPAWN                   = 243090,
    SPELL_SHADOW_HIT_EGIDA              = 234413,  
    SPELL_SHADOW_HIT_PLR                = 236242,
    SPELL_SHADOW_HIT_ILLIDAN            = 234018,    
    
    // illidan (117855)
    SPELL_ILLIDAN_SPAWN                 = 239484,
    SPELL_PREPARE                       = 234875,
    SPELL_FOUND_MEPHISTROTH             = 234217,
    SPELL_CONVERSATION_FOUND            = 242456,
    SPELL_ILLIDAN_DESPAWN               = 239485,
    
    SPELL_EGIDA_BUFF                    = 234083, //  (234114)
    SPELL_EGIDA_OVERRIDE                = 234114, //  (234114)
    
};

enum eEvents
{
    EVENT_CHECK_ENERGY     = 1,
    EVENT_DEMONIC_UPHEAVAL,
    EVENT_DARK_SOLITUDE,
    EVENT_CARRION_SWARM,
    EVENT_PHASE_TWO_TICK
};

Position const adds_pos[8]
{
    {-515.09f, 2511.28f, 533.94f, 2.64f},
    {-530.12f, 2496.94f, 533.94f, 1.95f},
    {-552.74f, 2496.88f, 533.94f, 1.24f},
    {-570.11f, 2510.35f, 533.94f, 0.50f},
    {-570.77f, 2541.98f, 533.94f, 5.77f},
    {-555.74f, 2555.67f, 533.94f, 5.11f},
    {-531.29f, 2555.90f, 533.94f, 4.36f},
    {-515.62f, 2545.86f, 533.94f, 3.79f}    
};

// 116944
class boss_mephistroth : public CreatureScript
{
public:
    boss_mephistroth() : CreatureScript("boss_mephistroth") {}

    struct boss_mephistrothAI : public BossAI
    {
        boss_mephistrothAI(Creature* creature) : BossAI(creature, DATA_MEPHISTROTH) {}
        
        std::map<uint8, ObjectGuid> justUseIt{};
        
        Creature* illidan_saved = nullptr;

        void Reset() override
        {
            illidan_saved = nullptr;
            me->RemoveAurasDueToSpell(SPELL_SHADOW_FADE);
            me->RemoveAurasDueToSpell(SPELL_CREEPING_SHADOWS);
            instance->DoRemoveAurasDueToSpellOnPlayers(234370);
            instance->DoRemoveAurasDueToSpellOnPlayers(234382);
            
                    
                    
            _Reset();
            me->SetPower(POWER_ENERGY, 0);
            justUseIt.clear();
            
            if (instance->GetBossState(DATA_DOMATRAX) == DONE)
            {
                me->SetVisible(true);
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC |UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1));
                
                 instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EGIDA_BUFF);
                 me->SummonCreature(NPC_EGIDA_GIVE_BUFF, -548.56f, 2527.75f, 533.94f, 3.19f);
            }
        }

        void DefaultEvents(uint8 phase)
        {
            events.Reset();
            justUseIt.clear();
            
            switch(phase)
            {
                case 1:
                    summons.DespawnAll();
                    me->RemoveAurasDueToSpell(SPELL_CREEPING_SHADOWS);
                    instance->DoRemoveAurasDueToSpellOnPlayers(234370);
                    instance->DoRemoveAurasDueToSpellOnPlayers(234382);
                    
                    events.RescheduleEvent(EVENT_CHECK_ENERGY, 1000);
                    events.RescheduleEvent(EVENT_DEMONIC_UPHEAVAL, 3200);
                    events.RescheduleEvent(EVENT_DARK_SOLITUDE, 8000);
                    events.RescheduleEvent(EVENT_CARRION_SWARM, 15000);
                    break;
                case 2:
                    events.RescheduleEvent(EVENT_PHASE_TWO_TICK, Difficulty() == DIFFICULTY_HEROIC ? 5000 : 4000);
                    break;
            }
            
        }
        
        void JustSummoned(Creature* summon) override
        {            
            summons.Summon(summon);
            
            summon->SetControlled(true, UNIT_STATE_ROOT);
            summon->SetReactState(REACT_PASSIVE);
            
            if (summon->GetEntry() == NPC_SHADOW_OF_MEPHISTROTH)
                if (illidan_saved)
                {
                    summon->AI()->AttackStart(illidan_saved);
                  //  summon->SetFacingTo(illidan_saved);
                    summon->AddUnitState(UNIT_STATE_ROTATING);
                }
                
            DoZoneInCombat(summon, 150.0f);
        }
        
        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            me->SetPower(POWER_ENERGY, 50);
            DefaultEvents(1);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EGIDA_BUFF);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EGIDA_OVERRIDE);
        }
        
        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() == NPC_SHADOW_OF_MEPHISTROTH)
            {
                for (auto& ptr : justUseIt)
                    if (ptr.second == summon->GetGUID())
                        ptr.second = ObjectGuid::Empty;
                    
                    
                summon->CastSpell(summon, SPELL_ADD_DESPAWN);
            }
        }
        
        void OnSpellCasted(SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_SHADOW_FADE)
            {
                me->SetVisible(false);
                me->AttackStop();
                me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

                instance->SetData(NPC_ILLIDAN_VISUAL_OUT, 0);

                if (Creature* illidan = me->SummonCreature(NPC_ILLIDAN_MEPHISTROTH, -542.10f, 2526.12f, 533.94f, 0.0f))
                {
                    illidan_saved = illidan;
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, illidan);
                }

                DoCast(SPELL_CONVERSATION_INVIS);
                DoCast(SPELL_CREEPING_SHADOWS);

                for (uint8 i = 0; i < 8; ++i)
                    me->CastSpell(adds_pos[i], SPELL_SHADOW_FADE_VISUAL_DEST, true);
            }
            else if (spell->Id == SPELL_INVIS_REMOVED)
            {
                me->SetVisible(true);
                illidan_saved = nullptr;
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetReactState(REACT_DEFENSIVE);
                DefaultEvents(1);
                instance->SetData(NPC_ILLIDAN_VISUAL_OUT, 1);
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_ENERGY:
                        if (me->GetPower(POWER_ENERGY) < 100)
                        {
                            if (!me->HasAura(SPELL_SHADOW_FADE))
                                me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 2));
                            events.RescheduleEvent(EVENT_CHECK_ENERGY, 1000);
                        }
                        else
                        {
                            DoCast(SPELL_SHADOW_FADE);
                            DefaultEvents(2);
                        }
                        break;
                    case EVENT_DEMONIC_UPHEAVAL:
                        DoCast(SPELL_DEMONIC_UPHEAVAL);
                        events.RescheduleEvent(EVENT_DEMONIC_UPHEAVAL, 27000);
                        break;
                    case EVENT_DARK_SOLITUDE:
                        DoCast(SPELL_DARK_SOLITUDE);
                        events.RescheduleEvent(EVENT_DARK_SOLITUDE, 12000);
                        break;
                    case EVENT_CARRION_SWARM:
                        DoCastVictim(SPELL_CARRION_SWARM);
                        events.RescheduleEvent(EVENT_CARRION_SWARM, 18000);
                        break;
                    case EVENT_PHASE_TWO_TICK:
                    {
                        std::vector<uint8> freeIds{};
                        for (uint8 i = 0; i < 8; ++i)
                            if (!justUseIt[i]) 
                                freeIds.push_back(i);
                            
                        if (freeIds.size() > 0)
                        {
                            uint8 select = freeIds[urand(0, freeIds.size()-1)];
                            if (Creature* add = me->SummonCreature(NPC_SHADOW_OF_MEPHISTROTH, adds_pos[select]))
                                justUseIt[select] = add->GetGUID();
                        }
                        events.RescheduleEvent(EVENT_PHASE_TWO_TICK, Difficulty() == DIFFICULTY_HEROIC ? 5000 : 4000);
                        break;
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_mephistrothAI (creature);
    }
};

// 117855
class npc_mephistroth_illidan : public CreatureScript
{
public:
    npc_mephistroth_illidan() : CreatureScript("npc_mephistroth_illidan") {}

    struct npc_mephistroth_illidanAI : public ScriptedAI
    {
        npc_mephistroth_illidanAI(Creature* creature) : ScriptedAI(creature) 
        {
            me->GetScheduler().Schedule(Milliseconds(100), [this](TaskContext context)
            {
                me->CastSpell(me, SPELL_ILLIDAN_SPAWN);
            });
        }
        
        EventMap events;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->GetScheduler().Schedule(Milliseconds(2000), [this](TaskContext context)
            {
                DoCast(SPELL_PREPARE);
                events.ScheduleEvent(1, 1000);
            });            
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (events.ExecuteEvent() == 1)
            {
                if (me->GetPower(POWER_ALTERNATE_POWER) < 300)
                {
                    events.RescheduleEvent(1, 1000);
                    if (urand(1, 4) == 1)
                        me->SetFacingTo(frand(0, 2*float(M_PI)));
                }
                //else
                {
                    DoCast(SPELL_FOUND_MEPHISTROTH);
                    DoCast(SPELL_CONVERSATION_FOUND);
                    if (InstanceScript* instance = me->GetInstanceScript())
                        if (Creature* meph = instance->instance->GetCreature(instance->GetGuidData(BOSS_MEPHISTROTH)))
                        {
                            meph->CastSpell(meph, SPELL_INVIS_REMOVED);
                            meph->RemoveAurasDueToSpell(SPELL_SHADOW_FADE);
                            meph->RemoveAurasDueToSpell(SPELL_CREEPING_SHADOWS);
                        }
                        
                    me->GetScheduler().Schedule(Milliseconds(300), [this](TaskContext context)
                    {
                        me->CastSpell(me, SPELL_ILLIDAN_DESPAWN);
                        me->DespawnOrUnsummon(2100);
                    });
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mephistroth_illidanAI (creature);
    }
};

// 233155
class spell_mephistroth_carrion_swarm : public SpellScriptLoader
{
public:
    spell_mephistroth_carrion_swarm() : SpellScriptLoader("spell_mephistroth_carrion_swarm") {}

    class spell_mephistroth_carrion_swarm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mephistroth_carrion_swarm_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
                
            if (caster && target)
            {
                Position pos;
                float angle = caster->GetRelativeAngle(target);
                uint32 hit_range = 2;
                for (uint8 i = 0; i < 3; i++)
                {
                    caster->GetNearPoint2D(pos.m_positionX, pos.m_positionY, hit_range, angle);
                    pos.m_positionZ = caster->GetPositionZ();
                    caster->GetScheduler().Schedule(Milliseconds(100 + i), [caster, pos](TaskContext context)
                    {
                        caster->CastSpell(pos, 233175, false);
                    });
                    hit_range += 5;
                }
                
            }
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_mephistroth_carrion_swarm_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mephistroth_carrion_swarm_SpellScript();
    }
};

// 234114
class spell_mephistroth_egida : public SpellScriptLoader
{
    public:
        spell_mephistroth_egida() : SpellScriptLoader("spell_mephistroth_egida") { }

        class spell_mephistroth_egida_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mephistroth_egida_AuraScript);

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                    if (removeMode == AURA_REMOVE_BY_DEATH || removeMode == AURA_REMOVE_BY_CANCEL || removeMode == AURA_REMOVE_BY_EXPIRE)
                        caster->SummonCreature(NPC_EGIDA_GIVE_BUFF, caster->GetPosition());
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mephistroth_egida_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override 
        {
            return new spell_mephistroth_egida_AuraScript();
        }
};


// 15295
    struct areatrigger_mephistroth_shadow_blast : AreaTriggerAI
{
    areatrigger_mephistroth_shadow_blast(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    //void ActionOnUpdate(GuidList& affectedPlayers) override
    void OnUnitEnter(Unit* unit)override
    {
        Unit* caster = at->GetCaster();
         if (InstanceScript* instance = at->GetInstanceScript())
             caster = instance->instance->GetCreature(instance->GetGuidData(BOSS_MEPHISTROTH));

        if (!caster)
            return;

        std::list<Player*> playerList;
        //at->GetPlayerListInGrid(playerList, at->GetFloatValue(DYNAMICOBJECT_RADIUS) + 2.4f); // i rly need it, because player + shield > at->GetRadius()

        bool can_delete = false;

        if (unit)
        {
            if (unit->GetEntry() == NPC_ILLIDAN_MEPHISTROTH)
            {
                caster->CastSpell(unit, SPELL_SHADOW_HIT_ILLIDAN);
                unit->SetPower(POWER_ALTERNATE_POWER, 0);
                can_delete = true;
            }
            else if (unit->HasAura(SPELL_EGIDA_BUFF) && unit->IsPlayer() && unit->isInFront(at) && at->isInFront(unit, 7 * float(M_PI) / 6))
            {
                caster->CastSpell(unit, SPELL_SHADOW_HIT_EGIDA);
                can_delete = true;
            }
            else if (unit->IsPlayer())
            {
                caster->CastSpell(unit, SPELL_SHADOW_HIT_PLR, true);
                can_delete = true;
            }
        }

        if (can_delete)
            at->Remove();
    }

};

void AddSC_boss_mephistroth()
{
    new boss_mephistroth();
    new npc_mephistroth_illidan();
    new spell_mephistroth_carrion_swarm();
    new spell_mephistroth_egida();
    RegisterAreaTriggerAI(areatrigger_mephistroth_shadow_blast);
}
