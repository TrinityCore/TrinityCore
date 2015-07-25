/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_CORROSIVE_SALIVA                     = 54527,
    SPELL_OPTIC_LINK                           = 54396,
    SPELL_RAY_OF_PAIN                          = 54438, // NYI missing spelldifficulty
    SPELL_RAY_OF_SUFFERING                     = 54442, // NYI missing spelldifficulty

    // Visual
    SPELL_OPTIC_LINK_LEVEL_1                   = 54393,
    SPELL_OPTIC_LINK_LEVEL_2                   = 54394,
    SPELL_OPTIC_LINK_LEVEL_3                   = 54395
};

enum MoraggEvents
{
    EVENT_CORROSIVE_SALIVA                      = 1,
    EVENT_OPTIC_LINK
};

class boss_moragg : public CreatureScript
{
public:
    boss_moragg() : CreatureScript("boss_moragg") { }

    struct boss_moraggAI : public ScriptedAI
    {
        boss_moraggAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (GameObject* door = instance->GetGameObject(DATA_MORAGG_CELL))
                if (door->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, IN_PROGRESS);

            me->SetInCombatWithZone();

            DoCast(SPELL_RAY_OF_PAIN);
            DoCast(SPELL_RAY_OF_SUFFERING);
            events.ScheduleEvent(EVENT_OPTIC_LINK, 15000);
            events.ScheduleEvent(EVENT_CORROSIVE_SALIVA, 5000);
        }

        void AttackStart(Unit* who) override
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_OPTIC_LINK:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_OPTIC_LINK);
                    events.ScheduleEvent(EVENT_OPTIC_LINK, 25000);
                    break;
                case EVENT_CORROSIVE_SALIVA:
                    DoCastVictim(SPELL_CORROSIVE_SALIVA);
                    events.ScheduleEvent(EVENT_CORROSIVE_SALIVA, 10000);
                    break;
                default:
                    break;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
            {
                instance->SetBossState(DATA_1ST_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
            {
                instance->SetBossState(DATA_2ND_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 13);
            }
        }

    private:
        EventMap events;
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_moraggAI>(creature);
    }
};

class spell_moragg_ray_of_suffering : public SpellScriptLoader
{
public:
    spell_moragg_ray_of_suffering() : SpellScriptLoader("spell_moragg_ray_of_suffering") { }

    class spell_moragg_ray_of_suffering_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_moragg_ray_of_suffering_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            std::list<HostileReference*> players = GetTarget()->getThreatManager().getThreatList();
            if (!players.empty())
            {
                std::list<HostileReference*>::iterator itr = players.begin();
                std::advance(itr, urand(0, players.size() - 1));

                uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                GetTarget()->CastCustomSpell(triggerSpell, SPELLVALUE_MAX_TARGETS, 1, (*itr)->getTarget(), TRIGGERED_FULL_MASK, NULL, aurEff);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_ray_of_suffering_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_moragg_ray_of_suffering_AuraScript();
    }
};

class spell_moragg_ray_of_pain : public SpellScriptLoader
{
public:
    spell_moragg_ray_of_pain() : SpellScriptLoader("spell_moragg_ray_of_pain") { }

    class spell_moragg_ray_of_pain_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_moragg_ray_of_pain_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            std::list<HostileReference*> players = GetTarget()->getThreatManager().getThreatList();
            if (!players.empty())
            {
                std::list<HostileReference*>::iterator itr = players.begin();
                std::advance(itr, urand(0, players.size() - 1));

                uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                GetTarget()->CastCustomSpell(triggerSpell, SPELLVALUE_MAX_TARGETS, 1, (*itr)->getTarget(), TRIGGERED_FULL_MASK, NULL, aurEff);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_ray_of_pain_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_moragg_ray_of_pain_AuraScript();
    }
};

class spell_moragg_optic_link : public SpellScriptLoader
{
public:
    spell_moragg_optic_link() : SpellScriptLoader("spell_moragg_optic_link") { }

    class spell_moragg_optic_link_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_moragg_optic_link_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            switch (aurEff->GetTickNumber()) // Different visual based on tick
            {
                case 1:
                case 2:
                case 3:
                    GetTarget()->CastCustomSpell(SPELL_OPTIC_LINK_LEVEL_1, SPELLVALUE_MAX_TARGETS, 1, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    GetTarget()->CastCustomSpell(SPELL_OPTIC_LINK_LEVEL_1, SPELLVALUE_MAX_TARGETS, 1, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
                    GetTarget()->CastCustomSpell(SPELL_OPTIC_LINK_LEVEL_2, SPELLVALUE_MAX_TARGETS, 1, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                    GetTarget()->CastCustomSpell(SPELL_OPTIC_LINK_LEVEL_1, SPELLVALUE_MAX_TARGETS, 1, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
                    GetTarget()->CastCustomSpell(SPELL_OPTIC_LINK_LEVEL_2, SPELLVALUE_MAX_TARGETS, 1, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
                    GetTarget()->CastCustomSpell(SPELL_OPTIC_LINK_LEVEL_3, SPELLVALUE_MAX_TARGETS, 1, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
                    break;
                default:
                    break;
            }
        }

        void OnUpdate(AuraEffect* aurEff)
        {
            switch (aurEff->GetTickNumber())
            {
                case 1:
                    aurEff->SetAmount(aurEff->GetAmount() + 250); // base amount is 500
                    break;
                case 4:
                    aurEff->SetAmount(aurEff->GetAmount() * 2); // goes to 1500
                    break;
                case 8:
                    aurEff->SetAmount(aurEff->GetAmount() * 2); // goes to 3000
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_optic_link_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_moragg_optic_link_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_moragg_optic_link_AuraScript();
    }
};

void AddSC_boss_moragg()
{
    new boss_moragg();
    new spell_moragg_ray_of_suffering();
    new spell_moragg_ray_of_pain();
    new spell_moragg_optic_link();
}
