/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

#include"ScriptMgr.h"
#include"SpellAuraEffects.h"
#include"hour_of_twilight.h"
#include "DynamicObject.h"

enum Spells
{
    SPELL_CHOKING_SMOKE_MOB_INTERFERE   = 103790,
    SPELL_MARK_OF_SILENCE               = 102726,
    SPELL_BLADE_BARRIER                 = 103419,
    SPELL_LESSER_BLADE_BARRIER          = 103562,
    SPELL_ENGULFING_TWILIGHT            = 103762,
    SPELL_CHOKING_SMOKE_BOMB            = 103558,
    SPELL_THROW_KNIFE                   = 103597,
};

enum Events
{
    EVENT_MARK_OF_SILENCE = 1,
    EVENT_CHOKING_SMOKE_BOMB,
    EVENT_CHOKING_SMOKE_MOB_INTERFERE,
    EVENT_BLADE_BARRIER,
    EVENT_CHECK_PLAYER

};


class boss_asira_dawnslayer : public CreatureScript
{
public:
    boss_asira_dawnslayer() : CreatureScript("boss_asira_dawnslayer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_asira_dawnslayerAI (creature);
    }

    struct boss_asira_dawnslayerAI : public BossAI
    {
        boss_asira_dawnslayerAI(Creature* creature) : BossAI(creature, DATA_ASIRA_DAWNSLAYER_EVENT)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript *instance;
        EventMap events;
        bool doneBarrier;
        bool cooldownVictim;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SetVisible(false);
        }

        void Reset() override
        {
            _Reset();
            events.Reset();
            if (instance)
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_SILENCE);
            doneBarrier = false;
            cooldownVictim = false;
        }

        void JustDied(Unit* /*Kill*/) override
        {
            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_SILENCE);
                instance->SetData(DATA_ASIRA_DAWNSLAYER_EVENT, DONE);
            }
            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
            {
                thrall->AI()->DoAction(ACTION_THRALL_STOP_CAST);
            }
        }

        void EnterCombat(Unit* /*Ent*/) override
        {
            DoZoneInCombat();

            if (instance)
                instance->SetData(DATA_ASIRA_DAWNSLAYER_EVENT, IN_PROGRESS);

            if (me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
            {
                events.ScheduleEvent(EVENT_MARK_OF_SILENCE, 1000);
                events.ScheduleEvent(EVENT_CHOKING_SMOKE_BOMB, 10000);
            }
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if(damage > 0 && doneBarrier == false)
            {
                if(me->HealthBelowPct(30))
                {
                    events.ScheduleEvent(EVENT_BLADE_BARRIER, 500);
                    doneBarrier = true;
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
            {
                if (me->GetVictim() == thrall && cooldownVictim == false)
                {
                    cooldownVictim = true;
                    events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                }
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MARK_OF_SILENCE:
                        if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            me->CastSpell(target, SPELL_MARK_OF_SILENCE, false);
                        }
                        break;
                    case EVENT_CHOKING_SMOKE_BOMB:
                        me->CastSpell(me, SPELL_CHOKING_SMOKE_BOMB, false);
                        events.ScheduleEvent(EVENT_CHOKING_SMOKE_BOMB, 20000);
                        break;
                    case EVENT_BLADE_BARRIER:
                        me->CastSpell(me, SPELL_BLADE_BARRIER, false);
                        break;
                    case EVENT_CHECK_PLAYER:
                    {
                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 100.0f);
                        if (targets.size() == 0)
                        {
                            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_SECOND, 100.0f, true))
                            {
                                me->SetReactState(REACT_PASSIVE);
                                thrall->RemoveAura(SPELL_ENGULFING_TWILIGHT);
                                thrall->SetReactState(REACT_PASSIVE);
                                thrall->AI()->EnterEvadeMode();
                                thrall->AI()->DoAction(ACTION_THRALL_STOP_CAST);

                                if (instance)
                                {
                                    instance->SetData(DATA_ASIRA_DAWNSLAYER_EVENT, NOT_STARTED);
                                    instance->SetBossState(DATA_ASIRA_DAWNSLAYER, NOT_STARTED);
                                }
                                EnterEvadeMode();


                                Reset();
                                me->SetReactState(REACT_AGGRESSIVE);
                            }
                        }
                        cooldownVictim = false;
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class TypeCheck
{
    public:
        explicit TypeCheck(Unit* caster) : _victim(caster->GetVictim()) { }

        bool operator() (WorldObject* unit) const
        {
            if (!unit->ToPlayer() || unit == _victim)
                return true;
            return false;
        }

        Unit* _victim;
};

class spell_mark_of_silence : public SpellScriptLoader
{
    public:
        spell_mark_of_silence() : SpellScriptLoader("spell_mark_of_silence") { }

        class spell_mark_of_silence_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mark_of_silence_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() != 1)
                {
                    targets.remove_if(TypeCheck(GetCaster()));
                }

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mark_of_silence_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        class spell_mark_of_silence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mark_of_silence_AuraScript);

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                if(Unit* caster = aurEff->GetCaster())
                {
                    if(Unit* owner = aurEff->GetBase()->GetUnitOwner())
                    {
                        std::list<Player*> betweeners;
                        std::list<Player*> targets;
                        caster->GetPlayerListInGrid(targets, 100.0f);

                        for (std::list<Player*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                        {
                            if((*iter)->ToPlayer())
                            {
                                if((*iter)->IsInBetween(caster, owner, 4.0f))
                                {
                                    betweeners.push_back((*iter));
                                }
                            }
                        }
                        if(betweeners.size() > 0)
                        {
                            betweeners.sort(Trinity::ObjectDistanceOrderPred(caster));

                            if(Unit* target = betweeners.front())
                            {
                                caster->CastSpell(target, SPELL_THROW_KNIFE, false);
                            }
                        }
                        else
                        {
                            caster->CastSpell(owner, SPELL_THROW_KNIFE, false);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mark_of_silence_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);

            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mark_of_silence_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_mark_of_silence_AuraScript();
        }
};

class spell_choking_smoke_bomb : public SpellScriptLoader
{
    public:
        spell_choking_smoke_bomb() : SpellScriptLoader("spell_choking_smoke_bomb") { }

        class spell_choking_smoke_bomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_choking_smoke_bomb_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if(Unit* caster = GetCaster())
                {
                    if (DynamicObject* dynObj = caster->GetDynObject(SPELL_CHOKING_SMOKE_BOMB))
                    {
                        // Casts aoe interfere targetting aura
                        caster->CastSpell(dynObj->GetPositionX(), dynObj->GetPositionY(), dynObj->GetPositionZ(), SPELL_CHOKING_SMOKE_MOB_INTERFERE, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_choking_smoke_bomb_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_choking_smoke_bomb_AuraScript();
        }
};

class spell_throw_knife : public SpellScriptLoader
{
    public:
        spell_throw_knife() : SpellScriptLoader("spell_throw_knife") { }

        class spell_throw_knife_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_throw_knife_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if(Unit* target = GetHitUnit())
                {
                    if(target->HasAura(SPELL_MARK_OF_SILENCE))
                    {
                        target->CastSpell(target, GetSpellInfo()->GetEffect(effIndex)->BasePoints, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_throw_knife_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_throw_knife_SpellScript();
        }
};

class spell_blade_barrier : public SpellScriptLoader
{
    public:
        spell_blade_barrier() : SpellScriptLoader("spell_blade_barrier") { }

        class spell_blade_barrier_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_blade_barrier_AuraScript);

            void HandleOnEffectAbsorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                if(Unit* caster = aurEff->GetCaster())
                {
                    if(aurEff->GetId() == SPELL_BLADE_BARRIER)
                    {
                        if(dmgInfo.GetDamage() > 40000 && dmgInfo.GetAttacker()->ToPlayer())
                        {
                            caster->RemoveAura(SPELL_BLADE_BARRIER);
                            caster->CastSpell(caster, SPELL_LESSER_BLADE_BARRIER, false);
                        }
                        else
                        {
                            absorbAmount = dmgInfo.GetDamage();
                        }
                    }
                    else
                    {
                        if (dmgInfo.GetDamage() > 30000 && dmgInfo.GetAttacker()->ToPlayer())
                        {
                            caster->RemoveAura(SPELL_LESSER_BLADE_BARRIER);
                        }
                        else
                        {
                            absorbAmount = dmgInfo.GetDamage();
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_blade_barrier_AuraScript::HandleOnEffectAbsorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_blade_barrier_AuraScript();
        }
};

void AddSC_boss_asira_dawnslayer()
{
    new boss_asira_dawnslayer();
    new spell_mark_of_silence();
    new spell_choking_smoke_bomb();
    new spell_throw_knife();
    new spell_blade_barrier();
}
