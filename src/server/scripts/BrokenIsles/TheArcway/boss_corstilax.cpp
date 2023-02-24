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
// #include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "the_arcway.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Spells
//{
//    SPELL_SUPPRESSION_PROTOCOL  = 196047,
//    SPELL_S_PROTOCOL_FIXATE     = 196068,
//    SPELL_S_PROTOCOL_DMG        = 196070,
//    SPELL_QUARANTINE            = 195791,
//    SPELL_QUARANTINE_STUN       = 195804,
//    SPELL_CLEANSING_FORCE       = 196115,
//    SPELL_CLEANSING_FORCE_AT    = 196088,
//    SPELL_DESTABILIZED_ORB      = 220481,
//    SPELL_DESTABILIZED_ORB_AT   = 220482,
//
//    SPELL_ENERGY_BURST_VISUAL   = 195516,
//    SPELL_ENERGY_BURST_AT       = 195523,
//    SPELL_NIGHTWELL_ENERGY      = 195362,
//};
//
//enum eEvents
//{
//    EVENT_PROTOCOL              = 1,
//    EVENT_QUARANTINE            = 2,
//    EVENT_CLEANSING_FORCE       = 3,
//    EVENT_ENERGY_BURST          = 4,
//    EVENT_DESTABILIZED_ORB      = 5,
//    EVENT_1,
//};
//
//Position const centrPos = {3147.14f, 4887.08f, 617.62f};
//
//class boss_corstilax : public CreatureScript
//{
//public:
//    boss_corstilax() : CreatureScript("boss_corstilax") {}
//
//    struct boss_corstilaxAI : public BossAI
//    {
//        boss_corstilaxAI(Creature* creature) : BossAI(creature, DATA_CORSTILAX) {}
//
//        uint16 checkRootTimer;
//
//        void Reset() override
//        {
//            _Reset();
//            checkRootTimer = 0;
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTWELL_ENERGY);
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            _JustEngagedWith();
//
//            events.RescheduleEvent(EVENT_PROTOCOL, 5000);
//            events.RescheduleEvent(EVENT_QUARANTINE, 20000);
//            events.RescheduleEvent(EVENT_CLEANSING_FORCE, 28000); 
//            events.RescheduleEvent(EVENT_ENERGY_BURST, 18000);
//            events.RescheduleEvent(EVENT_DESTABILIZED_ORB, 13000);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            _JustDied();
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTWELL_ENERGY);
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//                case SPELL_SUPPRESSION_PROTOCOL:
//                {
//                    float x = target->GetPositionX();
//                    float y = target->GetPositionY();
//                    float z = target->GetPositionZ();
//                    if (Creature* protocol = me->SummonCreature(NPC_SUPPRESSION_PROTOCOL, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 12000))
//                    {
//                        protocol->CastSpell(target, SPELL_S_PROTOCOL_FIXATE, true);
//                        if (target->GetTypeId() == TYPEID_PLAYER)
//                            protocol->AI()->Talk(0);
//                    }
//                    checkRootTimer = 6000;
//                    me->AddUnitState(UNIT_STATE_ROOT);
//                    DoCast(SPELL_S_PROTOCOL_DMG);
//                    break;
//                }
//                case SPELL_DESTABILIZED_ORB:
//                {
//                    float x = target->GetPositionX();
//                    float y = target->GetPositionY();
//                    float z = target->GetPositionZ();
//                    if (Creature* orb = me->SummonCreature(NPC_DESTABLIZED_ORB, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 60000))
//                        orb->CastSpell(orb, SPELL_DESTABILIZED_ORB_AT, true);
//                    break;
//                }
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (checkRootTimer) //Big hack
//            {
//                if (checkRootTimer <= diff)
//                {
//                    if (me->HasUnitState(UNIT_STATE_ROOT))
//                    {
//                        checkRootTimer = 0;
//                        me->ClearUnitState(UNIT_STATE_ROOT);
//                    }
//                } else checkRootTimer -= diff;
//            }
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_PROTOCOL:
//                        DoCast(SPELL_SUPPRESSION_PROTOCOL);
//                        events.RescheduleEvent(EVENT_PROTOCOL, 36000);
//                        break;
//                    case EVENT_QUARANTINE:
//                        DoCast(SPELL_QUARANTINE);
//                        events.RescheduleEvent(EVENT_QUARANTINE, 32000);
//                        break;
//                    case EVENT_CLEANSING_FORCE:
//                        DoCast(SPELL_CLEANSING_FORCE);
//                        events.RescheduleEvent(EVENT_CLEANSING_FORCE, 32000);
//                        break;
//                    case EVENT_ENERGY_BURST:
//                        if (Creature* pipe = me->SummonCreature(NPC_PIPE_STALKER, 3101.87f, 4908.10f, 622.39f, 5.86f, TEMPSUMMON_TIMED_DESPAWN, 10000))
//                        {
//                            pipe->CastSpell(pipe, SPELL_ENERGY_BURST_VISUAL, true);
//                            for(uint8 i = 0; i < 10; i++)
//                            {
//                                float angle = (float)rand_norm() * static_cast<float>(2 * M_PI);
//                                float dist = 40.0f * (float)rand_norm();
//                                float x = centrPos.GetPositionX() + dist * std::cos(angle);
//                                float y = centrPos.GetPositionY() + dist * std::sin(angle);
//                                Trinity::NormalizeMapCoord(x);
//                                Trinity::NormalizeMapCoord(y);
//                                pipe->CastSpell(x, y, 617.63f, SPELL_ENERGY_BURST_AT, TriggerCastFlags(TRIGGERED_IGNORE_GCD));
//                            }
//                        }
//                        events.RescheduleEvent(EVENT_ENERGY_BURST, 32000);
//                        break;
//                    case EVENT_DESTABILIZED_ORB:
//                        DoCast(SPELL_DESTABILIZED_ORB);
//                        events.RescheduleEvent(EVENT_DESTABILIZED_ORB, 32000);
//                        break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_corstilaxAI (creature);
//    }
//};
//
////99628
//class npc_corstilax_suppression_protocol : public CreatureScript
//{
//public:
//    npc_corstilax_suppression_protocol() : CreatureScript("npc_corstilax_suppression_protocol") {}
//
//    struct npc_corstilax_suppression_protocolAI : public ScriptedAI
//    {
//        npc_corstilax_suppression_protocolAI(Creature* creature) : ScriptedAI(creature) 
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        EventMap events;
//        Unit* plrTarget = nullptr;
//
//        void Reset() override {}
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_S_PROTOCOL_FIXATE)
//            {
//                plrTarget = target;
//                events.RescheduleEvent(EVENT_1, 500);
//            }
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            damage = 0;
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            events.Update(diff);
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                if (eventId == EVENT_1)
//                {
//                    if (plrTarget)
//                        me->GetMotionMaster()->MovePoint(1, plrTarget->GetPositionX(), plrTarget->GetPositionY(), plrTarget->GetPositionZ());
//                    events.RescheduleEvent(EVENT_1, 1000);
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_corstilax_suppression_protocolAI(creature);
//    }
//};
//
////99560
//class npc_corstilax_quarantine : public CreatureScript
//{
//public:
//    npc_corstilax_quarantine() : CreatureScript("npc_corstilax_quarantine") {}
//
//    bool OnGossipHello(Player* player, Creature* me)
//    {
//        if (!me || !player)
//            return false;
//        if (!player->HasAura(SPELL_QUARANTINE_STUN))
//            player->CastSpell(me, 195826);
//        return true;
//    }
//
//    struct npc_corstilax_quarantineAI : public ScriptedAI
//    {
//        npc_corstilax_quarantineAI(Creature* creature) : ScriptedAI(creature) 
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetFaction(35);
//        }
//
//        Unit* plrTarget = nullptr;
//        uint16 timerDespawn;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            if (summoner->GetTypeId() != TYPEID_PLAYER)
//                return;
//
//            timerDespawn = 21000;
//            plrTarget = summoner;
//            summoner->CastSpell(me, 195820, true); //Ride Veh
//            Talk(0);
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == 195846)
//            {
//                if (plrTarget)
//                    plrTarget->RemoveAurasDueToSpell(SPELL_QUARANTINE_STUN);
//                me->DespawnOrUnsummon();
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (timerDespawn)
//            {
//                if (timerDespawn <= diff)
//                {
//                    me->DespawnOrUnsummon();
//                    timerDespawn = 0;
//                }
//                else
//                    timerDespawn -= diff;
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_corstilax_quarantineAI(creature);
//    }
//};
//
////196115
//class spell_corstilax_cleansing_force : public SpellScriptLoader
//{
//    public:
//        spell_corstilax_cleansing_force() : SpellScriptLoader("spell_corstilax_cleansing_force") { }
//
//        class spell_corstilax_cleansing_force_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_corstilax_cleansing_force_AuraScript);
//
//            uint8 stack = 0;
//            uint16 m_Timer = 2000;
//
//            void OnPeriodic(AuraEffect const* aurEff)
//            {
//                std::list<Player*> playersList;
//                GetPlayerListInGrid(playersList, GetCaster(), 40.0f);
//                if (!playersList.empty())
//                {
//                    for (auto player : playersList)
//                    {
//                        if (Aura* aura = player->GetAura(SPELL_NIGHTWELL_ENERGY))
//                        {
//                            stack = aura->GetStackAmount();
//
//                            if (stack > 1)
//                                aura->SetStackAmount(stack - 1);
//                            else
//                                aura->Remove();
//                        }
//                    }
//                }
//            }
//            
//            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//            {
//                if (!GetCaster())
//                    return;
//
//                GetCaster()->CastSpell(GetCaster(), SPELL_CLEANSING_FORCE_AT, true);
//            }
//
//            void Register() override
//            {
//                OnEffectPeriodic += AuraEffectPeriodicFn(spell_corstilax_cleansing_force_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
//                OnEffectApply += AuraEffectApplyFn(spell_corstilax_cleansing_force_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//            }
//        };
//
//        AuraScript* GetAuraScript() const override
//        {
//            return new spell_corstilax_cleansing_force_AuraScript();
//        }
//};
//
//void AddSC_boss_corstilax()
//{
//    new boss_corstilax();
//    new npc_corstilax_suppression_protocol();
//    new npc_corstilax_quarantine();
//    new spell_corstilax_cleansing_force();
//}
