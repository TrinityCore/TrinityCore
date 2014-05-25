/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Ingvar_The_Plunderer
SD%Complete: 95
SDComment: Blizzlike Timers (just shadow axe summon needs a new timer)
SDCategory: Utgarde Keep
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "utgarde_keep.h"

enum Yells
{
    // Ingvar (Human/Undead)
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,

    // Annhylde The Caller
    YELL_RESURRECT              = 0
};

enum Events
{
    EVENT_CLEAVE = 1,
    EVENT_SMASH,
    EVENT_STAGGERING_ROAR,
    EVENT_ENRAGE,

    EVENT_DARK_SMASH,
    EVENT_DREADFUL_ROAR,
    EVENT_WOE_STRIKE,
    EVENT_SHADOW_AXE,
    EVENT_JUST_TRANSFORMED,
    EVENT_SUMMON_BANSHEE,

    EVENT_RESURRECT_1,
    EVENT_RESURRECT_2
};

enum Phases
{
    PHASE_HUMAN = 1,
    PHASE_UNDEAD,
    PHASE_EVENT
};

enum Spells
{
    // Ingvar Spells human form
    SPELL_CLEAVE                                = 42724,
    SPELL_SMASH                                 = 42669,
    SPELL_STAGGERING_ROAR                       = 42708,
    SPELL_ENRAGE                                = 42705,

    SPELL_INGVAR_FEIGN_DEATH                    = 42795,
    SPELL_SUMMON_BANSHEE                        = 42912,
    SPELL_SCOURG_RESURRECTION                   = 42863, // Spawn resurrect effect around Ingvar

    // Ingvar Spells undead form
    SPELL_DARK_SMASH                            = 42723,
    SPELL_DREADFUL_ROAR                         = 42729,
    SPELL_WOE_STRIKE                            = 42730,
    SPELL_WOE_STRIKE_EFFECT                     = 42739,

    SPELL_SHADOW_AXE_SUMMON                     = 42748,
    SPELL_SHADOW_AXE_PERIODIC_DAMAGE            = 42750,

    // Spells for Annhylde
    SPELL_SCOURG_RESURRECTION_HEAL              = 42704, // Heal Max + DummyAura
    SPELL_SCOURG_RESURRECTION_BEAM              = 42857, // Channeling Beam of Annhylde
    SPELL_SCOURG_RESURRECTION_DUMMY             = 42862, // Some Emote Dummy?
    SPELL_INGVAR_TRANSFORM                      = 42796
};

enum Misc
{
    ACTION_START_PHASE_2
};

class boss_ingvar_the_plunderer : public CreatureScript
{
    public:
        boss_ingvar_the_plunderer() : CreatureScript("boss_ingvar_the_plunderer") { }

        struct boss_ingvar_the_plundererAI : public BossAI
        {
            boss_ingvar_the_plundererAI(Creature* creature) : BossAI(creature, DATA_INGVAR) { }

            void Reset() override
            {
                if (me->GetEntry() != NPC_INGVAR)
                    me->UpdateEntry(NPC_INGVAR);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);

                _Reset();
                events.SetPhase(PHASE_HUMAN);

                events.ScheduleEvent(EVENT_CLEAVE, urand(6, 12)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                events.ScheduleEvent(EVENT_STAGGERING_ROAR, urand(18, 21)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                events.ScheduleEvent(EVENT_ENRAGE, urand(7, 14)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                events.ScheduleEvent(EVENT_SMASH, urand(12, 17)*IN_MILLISECONDS, 0, PHASE_HUMAN);
            }

            void DamageTaken(Unit* /*doneBy*/, uint32& damage) override
            {
                if (damage >= me->GetHealth() && events.IsInPhase(PHASE_HUMAN))
                {
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_INGVAR_FEIGN_DEATH, true);

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);

                    events.SetPhase(PHASE_EVENT);
                    events.ScheduleEvent(EVENT_SUMMON_BANSHEE, 3 * IN_MILLISECONDS, 0, PHASE_EVENT);

                    Talk(SAY_DEATH);
                }

                if (events.IsInPhase(PHASE_EVENT))
                    damage = 0;
            }

            void DoAction(int32 actionId)
            {
                if (actionId == ACTION_START_PHASE_2)
                    StartZombiePhase();
            }

            void StartZombiePhase()
            {
                me->RemoveAura(SPELL_INGVAR_FEIGN_DEATH);
                DoCast(me, SPELL_INGVAR_TRANSFORM, true);
                me->UpdateEntry(NPC_INGVAR_UNDEAD);
                events.ScheduleEvent(EVENT_JUST_TRANSFORMED, 2 * IN_MILLISECONDS, 0, PHASE_EVENT);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void ScheduleSecondPhase()
            {
                events.SetPhase(PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_DARK_SMASH, urand(14, 18)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_DREADFUL_ROAR, urand(18, 22)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_WOE_STRIKE, urand(10, 14)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS, 0, PHASE_UNDEAD);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_EVENT))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // PHASE ONE
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(6, 12)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_STAGGERING_ROAR:
                            DoCast(me, SPELL_STAGGERING_ROAR);
                            events.ScheduleEvent(EVENT_STAGGERING_ROAR, urand(18, 22)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_ENRAGE);
                            events.ScheduleEvent(EVENT_ENRAGE, urand(7, 14)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_SMASH:
                            DoCastAOE(SPELL_SMASH);
                            events.ScheduleEvent(EVENT_SMASH, urand(12, 16)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_JUST_TRANSFORMED:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                            DoZoneInCombat();
                            ScheduleSecondPhase();
                            return;
                        case EVENT_SUMMON_BANSHEE:
                            DoCast(me, SPELL_SUMMON_BANSHEE);
                            return;
                        // PHASE TWO
                        case EVENT_DARK_SMASH:
                            DoCastVictim(SPELL_DARK_SMASH);
                            events.ScheduleEvent(EVENT_DARK_SMASH, urand(12, 16)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        case EVENT_DREADFUL_ROAR:
                            DoCast(me, SPELL_DREADFUL_ROAR);
                            events.ScheduleEvent(EVENT_DREADFUL_ROAR, urand(18, 22)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        case EVENT_WOE_STRIKE:
                            DoCastVictim(SPELL_WOE_STRIKE);
                            events.ScheduleEvent(EVENT_WOE_STRIKE, urand(10, 14)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        case EVENT_SHADOW_AXE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_SHADOW_AXE_SUMMON);
                            events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        default:
                            break;
                    }
                }

                if (!events.IsInPhase(PHASE_EVENT))
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardeKeepAI<boss_ingvar_the_plundererAI>(creature);
        }
};

class npc_annhylde_the_caller : public CreatureScript
{
    public:
        npc_annhylde_the_caller() : CreatureScript("npc_annhylde_the_caller") { }

        struct npc_annhylde_the_callerAI : public ScriptedAI
        {
            npc_annhylde_the_callerAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _events.Reset();

                me->GetPosition(x, y, z);
                me->GetMotionMaster()->MovePoint(1, x, y, z - 15.0f);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case 1:
                        Talk(YELL_RESURRECT);
                        if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                        {
                            ingvar->RemoveAura(SPELL_SUMMON_BANSHEE);
                            ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_DUMMY, true);
                            DoCast(ingvar, SPELL_SCOURG_RESURRECTION_BEAM);
                        }
                        _events.ScheduleEvent(EVENT_RESURRECT_1, 8000);
                        break;
                    case 2:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void AttackStart(Unit* /*who*/) override { }
            void MoveInLineOfSight(Unit* /*who*/) override { }
            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESURRECT_1:
                            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                            {
                                ingvar->RemoveAura(SPELL_INGVAR_FEIGN_DEATH);
                                ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_HEAL, false);
                            }
                            _events.ScheduleEvent(EVENT_RESURRECT_2, 3000);
                            break;
                        case EVENT_RESURRECT_2:
                            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                            {
                                ingvar->RemoveAurasDueToSpell(SPELL_SCOURG_RESURRECTION_DUMMY);
                                ingvar->AI()->DoAction(ACTION_START_PHASE_2);
                            }

                            me->GetMotionMaster()->MovePoint(2, x, y, z + 15.0f);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            float x, y, z;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardeKeepAI<npc_annhylde_the_callerAI>(creature);
        }
};

class npc_ingvar_throw_dummy : public CreatureScript
{
    public:
        npc_ingvar_throw_dummy() : CreatureScript("npc_ingvar_throw_dummy") { }

        struct npc_ingvar_throw_dummyAI : public ScriptedAI
        {
            npc_ingvar_throw_dummyAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);

                if (Creature* target = me->FindNearestCreature(NPC_THROW_TARGET, 200.0f))
                {
                    float x, y, z;
                    target->GetPosition(x, y, z);
                    me->GetMotionMaster()->MoveCharge(x, y, z);
                    target->DespawnOrUnsummon();
                }
                else
                    me->DespawnOrUnsummon();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE && id == EVENT_CHARGE)
                {
                    me->CastSpell(me, SPELL_SHADOW_AXE_PERIODIC_DAMAGE, true);
                    me->DespawnOrUnsummon(10000);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ingvar_throw_dummyAI(creature);
        }
};

// 42912 - Summon Banshee
class spell_ingvar_summon_banshee : public SpellScriptLoader
{
    public:
        spell_ingvar_summon_banshee() : SpellScriptLoader("spell_ingvar_summon_banshee") { }

        class spell_ingvar_summon_banshee_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ingvar_summon_banshee_SpellScript);

            void SetDest(SpellDestination& dest)
            {
                dest.RelocateOffset({ 0.0f, 0.0f, 30.0f, 0.0f });
            }

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ingvar_summon_banshee_SpellScript::SetDest, EFFECT_0, TARGET_DEST_CASTER_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ingvar_summon_banshee_SpellScript();
        }
};

// 42730, 59735 - Woe Strike
class spell_ingvar_woe_strike : public SpellScriptLoader
{
    public:
        spell_ingvar_woe_strike() : SpellScriptLoader("spell_ingvar_woe_strike") { }

        class spell_ingvar_woe_strike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ingvar_woe_strike_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WOE_STRIKE_EFFECT))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetHealInfo()->GetHeal();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_WOE_STRIKE_EFFECT, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_ingvar_woe_strike_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_ingvar_woe_strike_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ingvar_woe_strike_AuraScript();
        }
};

void AddSC_boss_ingvar_the_plunderer()
{
    new boss_ingvar_the_plunderer();
    new npc_annhylde_the_caller();
    new npc_ingvar_throw_dummy();
    new spell_ingvar_summon_banshee();
    new spell_ingvar_woe_strike();
}
