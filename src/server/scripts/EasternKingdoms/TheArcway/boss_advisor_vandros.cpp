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
//#include "ScriptedCreature.h"
//#include "the_arcway.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_AGGRO = 2,
//    SAY_BOMB = 3,
//    SAY_TIME = 4,
//    SAY_TIME_EMOTE = 5,
//    SAY_TIME_REM = 6,
//    //    SAY_?????           = 7,    i dont know, where he say its   "Think of this as a mercy killing."
//    SAY_EVADE = 8,
//    SAY_DEATH = 9,
//};
//
//enum Spells
//{
//    SPELL_ACCELERATING_BLAST = 203176,
//    SPELL_CHRONO_SHARDS = 203254,
//    SPELL_FORCE_BOMB = 202974,
//    SPELL_FORCE_BOMB_AT = 202975,
//    SPELL_FORCE_BOMB_AT_2 = 203090, //?????????????? ?????
//    //Health - 50% 
//    SPELL_BANISH_IN_TIME_STUN = 203922,
//    SPELL_BANISH_IN_TIME_AT = 203882,
//    SPELL_BANISH_IN_TIME_TP = 203883,
//    SPELL_BANISH_IN_TIME_TIMER = 203914,
//    SPELL_BANISH_IN_TIME_REMOVE = 203941,
//    SPELL_UNSTABLE_MANA = 220871,
//
//    SPELL_TIME_SPLIT = 203833,
//    SPELL_PULSE_VISUAL = 203835, //Chrono Shard Pulse Visual
//};
//
//enum eEvents
//{
//    EVENT_A_BLAST = 1,
//    EVENT_CHRONO_SHARDS = 2,
//    EVENT_FORCE_BOMB = 3,
//    EVENT_BANISH_IN_TIME = 4,
//    EVENT_UNSTABLE_MANA = 5,
//    EVENT_1,
//    EVENT_2,
//};
//
//Position const tpPos[4] =
//{
//    {3134.70f, 4892.10f, 617.64f, 2.86f},
//    {3151.23f, 5109.96f, 623.22f, 2.06f},
//    {3154.38f, 4661.42f, 574.20f, 2.95f},
//    {3327.04f, 4523.76f, 570.80f, 3.25f}
//};
//
//Position const wraithPos[12] =
//{
//    {3202.04f, 4863.76f, 619.78f, 5.94f},
//    {3214.42f, 4990.87f, 624.14f, 1.79f},
//    {3237.84f, 4626.11f, 575.03f, 2.78f},
//    {3244.24f, 4937.37f, 619.45f, 3.66f},
//    {3263.59f, 4879.47f, 619.14f, 0.64f},
//    {3323.22f, 4962.37f, 619.30f, 0.0f},
//    {3348.97f, 4608.84f, 550.74f, 6.01f},
//    {3413.84f, 4714.62f, 590.55f, 0.0f},
//    {3415.29f, 4962.56f, 598.39f, 0.0f},
//    {3432.10f, 4775.44f, 590.94f, 0.70f},
//    {3451.70f, 4640.10f, 567.34f, 1.53f},
//    {3467.79f, 4543.19f, 571.34f, 0.03f}
//};
//
////98208
//class boss_advisor_vandros : public CreatureScript
//{
//public:
//    boss_advisor_vandros() : CreatureScript("boss_advisor_vandros") {}
//
//    struct boss_advisor_vandrosAI : public BossAI
//    {
//        boss_advisor_vandrosAI(Creature* creature) : BossAI(creature, DATA_VANDROS), summons(me)
//        {
//            me->SetVisible(false);
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        SummonList summons;
//        bool specialPhase = false;
//        bool specialPhaseComplete = false;
//
//        void Reset() override
//        {
//            _Reset();
//            summons.DespawnAll();
//            specialPhase = false;
//            specialPhaseComplete = false;
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANISH_IN_TIME_TIMER);
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//            DefaultEvents();
//        }
//
//        void DefaultEvents()
//        {
//            events.RescheduleEvent(EVENT_A_BLAST, 3000);
//            events.RescheduleEvent(EVENT_CHRONO_SHARDS, 6000);
//            events.RescheduleEvent(EVENT_FORCE_BOMB, 16000);
//        }
//
//        void EnterEvadeMode(EvadeReason w) override
//        {
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->SetReactState(REACT_AGGRESSIVE);
//            Talk(SAY_EVADE);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Talk(SAY_DEATH);
//            _JustDied();
//            summons.DespawnAll();
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANISH_IN_TIME_TIMER);
//        }
//
//        void JustSummoned(Creature* summon)
//        {
//            summons.Summon(summon);
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_BANISH_IN_TIME_AT)
//            {
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ(), me->GetHomePosition().GetOrientation());
//                me->GetMotionMaster()->Clear(false);
//
//                Map::PlayerList const& players = me->GetMap()->GetPlayers();
//                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//                    if (Player* player = itr->GetSource())
//                        if (player->IsAlive())
//                        {
//                            player->CastSpell(player, SPELL_BANISH_IN_TIME_TP, true);
//                            player->CastSpell(player, SPELL_BANISH_IN_TIME_TIMER, true);
//                            Talk(SAY_TIME_EMOTE);
//                        }
//            }
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_FORCE_BOMB)
//                DoCast(target, SPELL_FORCE_BOMB_AT, true);
//        }
//
//        void DamageTaken(Unit* attacker, uint32& damage)
//        {
//            if (me->HealthBelowPct(50) && !specialPhase)
//            {
//                specialPhase = true;
//                events.Reset();
//                me->AttackStop();
//                events.RescheduleEvent(EVENT_BANISH_IN_TIME, 500);
//
//                for (uint8 i = 0; i < 12; ++i)
//                    me->SummonCreature(NPC_TIMELESS_WRAITH, wraithPos[i]);
//            }
//        }
//
//        void OnSpellFinished(SpellInfo const* spellInfo) override
//        {
//            switch (spellInfo->Id)
//            {
//            case SPELL_BANISH_IN_TIME_REMOVE:
//            {
//                if (!specialPhaseComplete)
//                {
//                    specialPhaseComplete = true;
//                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BANISH_IN_TIME_TIMER);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    me->InterruptNonMeleeSpells(false);
//                    Talk(SAY_TIME_REM);
//                    DefaultEvents();
//                    events.RescheduleEvent(EVENT_UNSTABLE_MANA, 3000);
//                }
//                break;
//            }
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_A_BLAST:
//                    DoCast(SPELL_ACCELERATING_BLAST);
//                    events.RescheduleEvent(EVENT_A_BLAST, 6000);
//                    break;
//                case EVENT_CHRONO_SHARDS:
//                    for (uint8 i = 0; i < 3; i++)
//                        DoCast(SPELL_CHRONO_SHARDS);
//                    events.RescheduleEvent(EVENT_CHRONO_SHARDS, 6000);
//                    break;
//                case EVENT_FORCE_BOMB:
//                    Talk(SAY_BOMB);
//                    DoCast(SPELL_FORCE_BOMB);
//                    events.RescheduleEvent(EVENT_FORCE_BOMB, 16000);
//                    break;
//                case EVENT_BANISH_IN_TIME:
//                    Talk(SAY_TIME);
//                    instance->SetData(DATA_RAND_TELEPORT, urand(0, 3));
//                    DoCast(me, SPELL_BANISH_IN_TIME_STUN, true);
//                    DoCast(SPELL_BANISH_IN_TIME_AT);
//                    break;
//                case EVENT_UNSTABLE_MANA:
//                    DoCast(SPELL_UNSTABLE_MANA);
//                    events.RescheduleEvent(EVENT_UNSTABLE_MANA, 30000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_advisor_vandrosAI(creature);
//    }
//};
//
////102849
//class npc_vandros_chrono_shard : public CreatureScript
//{
//public:
//    npc_vandros_chrono_shard() : CreatureScript("npc_vandros_chrono_shard") {}
//
//    struct npc_vandros_chrono_shardAI : public ScriptedAI
//    {
//        npc_vandros_chrono_shardAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        EventMap events;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            events.RescheduleEvent(EVENT_1, 8000);
//            DoCast(me, SPELL_PULSE_VISUAL, true);
//            Position pos;
//            me->GetRandomNearPosition(10.0f);
//            me->GetMotionMaster()->MovePoint(1, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            events.Update(diff);
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    DoCast(me, SPELL_TIME_SPLIT, true);
//                    me->DespawnOrUnsummon(1000);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_vandros_chrono_shardAI(creature);
//    }
//};
//
////203883
//class spell_vandros_teleport_plr : public SpellScriptLoader
//{
//public:
//    spell_vandros_teleport_plr() : SpellScriptLoader("spell_vandros_teleport_plr") { }
//
//    class spell_vandros_teleport_plr_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_vandros_teleport_plr_SpellScript);
//
//        uint8 rand = 0;
//
//        void HandleScriptEffect(SpellEffIndex effIndex)
//        {
//            PreventHitDefaultEffect(effIndex);
//
//            Player* player = GetCaster()->ToPlayer();
//            if (!player)
//                return;
//
//            if (InstanceScript* instance = player->GetInstanceScript())
//                rand = instance->GetData(DATA_RAND_TELEPORT);
//
//            player->TeleportTo(player->GetMapId(), tpPos[rand].GetPositionX(), tpPos[rand].GetPositionY(), tpPos[rand].GetPositionZ(), tpPos[rand].GetOrientation());
//        }
//
//        void Register() override
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_vandros_teleport_plr_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_vandros_teleport_plr_SpellScript();
//    }
//};
//
////203914
//class spell_vandros_banish_in_time_timer : public SpellScriptLoader
//{
//public:
//    spell_vandros_banish_in_time_timer() : SpellScriptLoader("spell_vandros_banish_in_time_timer") { }
//
//    class spell_vandros_banish_in_time_timer_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_vandros_banish_in_time_timer_AuraScript);
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
//        {
//            if (!GetTarget())
//                return;
//
//            AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
//
//            if (removeMode == AURA_REMOVE_BY_EXPIRE)
//                Unit::Kill(GetTarget(), GetTarget());
//
//        }
//
//        void Register() override
//        {
//            OnEffectRemove += AuraEffectApplyFn(spell_vandros_banish_in_time_timer_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_vandros_banish_in_time_timer_AuraScript();
//    }
//};
//
////220871
//class spell_vandros_unstable_mana : public SpellScriptLoader
//{
//public:
//    spell_vandros_unstable_mana() : SpellScriptLoader("spell_vandros_unstable_mana") { }
//
//    class spell_vandros_unstable_mana_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_vandros_unstable_mana_AuraScript);
//
//        void OnPereodic(AuraEffect const* aurEff)
//        {
//            if (!GetCaster() || !GetTarget())
//                return;
//
//            GetCaster()->CastSpell(GetTarget(), 220872, true);
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_vandros_unstable_mana_AuraScript::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_vandros_unstable_mana_AuraScript();
//    }
//};
//
////98426 98425
//class npc_unstable_amalgamation : public CreatureScript
//{
//public:
//    npc_unstable_amalgamation() : CreatureScript("npc_unstable_amalgamation") {}
//
//    struct npc_unstable_amalgamationAI : public ScriptedAI
//    {
//        npc_unstable_amalgamationAI(Creature* creature) : ScriptedAI(creature) {}
//
//        EventMap events;
//        uint32 AddSum = 0;
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            events.RescheduleEvent(EVENT_1, 30000); //193942
//            if (me->GetEntry() == 98425)
//                events.RescheduleEvent(EVENT_2, 15000); //193938
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Position pos;
//            float x, y, z;
//            me->GetPosition(x, y, z);
//            if (me->GetEntry() == 98425)
//                AddSum = 98426;
//            if (me->GetEntry() == 98426)
//                AddSum = 98435;
//            for (uint8 i = 0; i < 4; i++)
//            {
//                if (Unit* summon = me->SummonCreature(AddSum, x, y, z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
//                {
//                    float angle = i * static_cast<float>(M_PI);
//                    me->GetNearPosition(5.0f, angle);
//                    summon->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 193852, true);
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    DoCast(193942);
//                    events.RescheduleEvent(EVENT_1, 30000);
//                    break;
//                case EVENT_2:
//                    DoCast(193938);
//                    events.RescheduleEvent(EVENT_2, 16000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_unstable_amalgamationAI(creature);
//    }
//};
//
//void AddSC_boss_advisor_vandros()
//{
//    new boss_advisor_vandros();
//    new npc_vandros_chrono_shard();
//    new spell_vandros_teleport_plr();
//    new spell_vandros_banish_in_time_timer();
//    new spell_vandros_unstable_mana();
//    new npc_unstable_amalgamation();
//}
