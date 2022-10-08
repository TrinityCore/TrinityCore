/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "karazhan_legion.h"

enum Spells
{
    // The Curator
    SPELL_EVOCATION                         = 227254,
    SPELL_OVERLOAD                          = 227256,
    SPELL_OVERLOAD_DMG                      = 227257,
    SPELL_POWER_DISCHARGE                   = 227278,
    SPELL_POWER_DISCHARGE_TRIGGER           = 227279,
    SPELL_POWER_DISCHARGE_DMG               = 227465,
    SPELL_SUMMON_VOLATILE_ENERGY            = 234416,
    SPELL_SUMMON_VOLATILE_ENERGY_ADD        = 227267,

    // Volatile Energy
    SPELL_VOLATILE_ENERGY_PASSIVE           = 227268,
    SPELL_ARC_LIGHTNING_DMG                 = 227270,
    SPELL_STATIC_CHARGE                     = 228736,
    SPELL_STATIC_CHARGE_DMG                 = 228738
};

enum Events
{
    EVENT_VOLATILE_ENERGY                   = 1,
    EVENT_POWER_DISCHARGE                   = 2,
    EVENT_EVOCATION                         = 3,
    EVENT_REDUCE_MANA                       = 4
};

enum Says
{
    SAY_INTRO                               = 0,
    SAY_AGGRO                               = 1,
    SAY_VOLATILE_ENERGY                     = 2,
    SAY_EVOCATION                           = 3,
    SAY_EVOCATION_END                       = 4,
    SAY_KILL                                = 5,
    SAY_DEATH                               = 6
};

constexpr uint32 NPC_VOLATILE_ENERGY        = 114249;
constexpr uint32 NPC_SOUL_FRAGMENT_KARA     = 115113;
constexpr int32 ACTION_CHECK_MANA           = 1;

class boss_new_curator : public CreatureScript
{
    public:
        boss_new_curator() : CreatureScript("boss_new_curator") { }

        struct boss_new_curator_AI : public BossAI
        {
            explicit boss_new_curator_AI(Creature* creature) : BossAI(creature, DATA_CURATOR) { }

            void JustDied(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                Talk(SAY_DEATH);
                _JustDied();
                me->SummonCreature(NPC_SOUL_FRAGMENT_KARA, me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 480 * IN_MILLISECONDS);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (uint64(damage) > me->GetHealth())
                {
                    _JustDied();

                    if (GameObject* go = instance->GetGameObject(GO_DOOR_BIBLIOTEK))
                        go->GetPhaseShift().AddPhase(169, PhaseFlags::None, nullptr);
                }
            }

            void EnterCombat(Unit* /**/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                Talk(SAY_AGGRO);
                _EnterCombat();
                me->SetMaxPower(POWER_MANA, 100);
                me->SetPower(POWER_MANA, 100);
                events.ScheduleEvent(EVENT_VOLATILE_ENERGY, 5s);
                events.ScheduleEvent(EVENT_POWER_DISCHARGE, 15s);
                events.ScheduleEvent(EVENT_REDUCE_MANA, 1s);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                BossAI::EnterEvadeMode(why);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_CHECK_MANA)
                    events.ScheduleEvent(EVENT_REDUCE_MANA, 1s);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_VOLATILE_ENERGY:
                    {
                        if (roll_chance_i(50))
                            Talk(SAY_VOLATILE_ENERGY);

                        DoCast(me, SPELL_SUMMON_VOLATILE_ENERGY);
                        events.ScheduleEvent(EVENT_VOLATILE_ENERGY, 12s);
                        break;
                    }

                    case EVENT_POWER_DISCHARGE:
                    {
                        DoCast(me, SPELL_POWER_DISCHARGE);
                        events.ScheduleEvent(EVENT_POWER_DISCHARGE, 12s, 15s);
                        break;
                    }

                    case EVENT_EVOCATION:
                    {
                        Talk(SAY_EVOCATION);
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        DoCast(me, SPELL_EVOCATION);
                        break;
                    }

                    case EVENT_REDUCE_MANA:
                    {
                        me->ModifyPower(POWER_MANA, -1);

                        if (me->GetPower(POWER_MANA) <= 0)
                            events.ScheduleEvent(EVENT_EVOCATION, 500ms);
                        else
                            events.ScheduleEvent(EVENT_REDUCE_MANA, 1s);

                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_new_curator_AI(creature);
        }
};

class npc_kara_volatile_energy : public CreatureScript
{
    public:
        npc_kara_volatile_energy() : CreatureScript("npc_kara_volatile_energy") { }

        struct npc_kara_volatile_energy_AI : public ScriptedAI
        {
            public:
                explicit npc_kara_volatile_energy_AI(Creature* creature) : ScriptedAI(creature)
                {
                    me->CastSpell(me, SPELL_VOLATILE_ENERGY_PASSIVE, true);
                }

                void IsSummonedBy(Unit* /**/) override
                {
                    _timerJump = urand(9, 13) * IN_MILLISECONDS;
                }

                void UpdateAI(uint32 diff) override
                {
                    _timerJump -= diff;

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (_timerJump <= 0)
                    {
                        _timerJump = urand(9, 13) * IN_MILLISECONDS;

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_STATIC_CHARGE);
                    }
                }

                private:
                    int32 _timerJump;

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_volatile_energy_AI(creature);
        }
};

class spell_curator_power_discharge : public SpellScriptLoader
{
    public:
        spell_curator_power_discharge() : SpellScriptLoader("spell_curator_power_discharge") { }

        class spell_power_discharge_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_power_discharge_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_POWER_DISCHARGE_TRIGGER, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_power_discharge_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_power_discharge_SpellScript();
        }
};

class spell_curator_overload : public SpellScriptLoader
{
    public:
        spell_curator_overload() : SpellScriptLoader("spell_curator_overload") { }

        class spell_overload_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_overload_SpellScript);

                void HandleOnLaunch(SpellEffIndex /**/)
                {
                    if (!GetCaster())
                        return;

                    if (Aura* aura = GetCaster()->GetAura(SPELL_OVERLOAD_DMG))
                        SetHitDamage(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints * (aura->GetStackAmount()));
                }

                void Register() override
                {
                    OnEffectLaunchTarget += SpellEffectFn(spell_overload_SpellScript::HandleOnLaunch, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_overload_SpellScript();
        }
};

class spell_curator_evocation : public SpellScriptLoader
{
    public:
        spell_curator_evocation() : SpellScriptLoader("spell_curator_evocation") { }

        class spell_evocation_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_evocation_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetCaster()->ToCreature())
                        return;

                    GetCaster()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                    GetCaster()->CastSpell(GetCaster(), SPELL_OVERLOAD, true);
                    GetCaster()->GetAI()->DoAction(ACTION_CHECK_MANA);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_evocation_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_evocation_AuraScript();
        }
};

class spell_kara_arc_lightning : public SpellScriptLoader
{
    public:
        spell_kara_arc_lightning() : SpellScriptLoader("spell_kara_arc_lightning")
        {}

        class spell_arc_lightning_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_arc_lightning_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_ARC_LIGHTNING_DMG, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_arc_lightning_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_arc_lightning_SpellScript();
        }
};

class spell_kara_arc_lightning_dmg : public SpellScriptLoader
{
    public:
        spell_kara_arc_lightning_dmg() : SpellScriptLoader("spell_kara_arc_lightning_dmg") { }

        class spell_arc_lightning_dmg_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_arc_lightning_dmg_SpellScript);

                void HandleDamage(SpellEffIndex /**/)
                {
                    if (Aura* aura = GetCaster()->GetAura(SPELL_ARC_LIGHTNING_DMG))
                        SetHitDamage(GetEffectInfo(EFFECT_0)->BasePoints * (1.0f + aura->GetStackAmount()));
                }

                void Register() override
                {
                    OnEffectLaunchTarget += SpellEffectFn(spell_arc_lightning_dmg_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_arc_lightning_dmg_SpellScript();
        }
};

class at_kara_power_discharge : public AreaTriggerEntityScript
{
    public:
        at_kara_power_discharge() : AreaTriggerEntityScript("at_kara_power_discharge") { }

        struct at_kara_power_dischargue_AI : public AreaTriggerAI
        {
            explicit at_kara_power_dischargue_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    at->GetCaster()->CastSpell(target, SPELL_POWER_DISCHARGE_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_POWER_DISCHARGE_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_power_dischargue_AI(at);
        }
};

void AddSC_boss_curator_karazhan_legion()
{
    new boss_new_curator();
    new npc_kara_volatile_energy();
    new spell_curator_evocation();
    new spell_curator_overload();
    new spell_curator_power_discharge();
    new spell_kara_arc_lightning();
    new spell_kara_arc_lightning_dmg();
    new at_kara_power_discharge();
}
