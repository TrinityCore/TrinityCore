/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells
{
    SPELL_FIRE_BOOM_TARGET  = 216427,
    SPELL_FIRE_BOOM_DAMAGE  = 216429,

    SPELL_EARTHSHAKE_STOMP  = 216430,

    SPELL_ICE_FIST_DAMAGE   = 216432,

    SPELL_MAKE_SNOW_CAST    = 216467,
    SPELL_MAKE_SNOW_AT      = 216471,
    SPELL_MAKE_SNOW_DAMAGE  = 216476,

    SPELL_YOU_GO_BANG_TARGET = 216817,
    SPELL_YOU_GO_BANG_DAMAGE = 216822,
    SPELL_YOU_GO_BANG_AURA   = 227177
};

enum Events
{
    EVENT_FIRE_BOOM         = 1,
    EVENT_EARTHSHAKE_STOMP  = 2,
    EVENT_ICE_FIST          = 3,
    EVENT_MAKE_SNOW         = 4,
    EVENT_YOU_GO_BANG       = 5
};

enum Talks
{
    //Naming scheme :
    //TALK_H/P with H for Humongris, P for Padawsen

    //On fire boom cast
    TALK_H_FIRE_BOOM = 0,      //Make the boomy fire thing! Make the boom!
    TALK_P_FIRE_BOOM_1 = 114800,    //Stop shaking me !
    TALK_P_FIRE_BOOM_2 = 114802,    //Whaaaaaaaaaaaaa!

    //On Ice Fist cast
    TALK_H_ICE_FIST = 1,       //Do Ice Fist human!

    //On Make the Snow cast
    TALK_H_MAKE_THE_SNOW_1 = 1, //I want snow! Make the snow!
    TALK_H_MAKE_THE_SNOW_2 = 114627, //I want Snow! Make it snow! Make it Snow! Make it Snow!
    TALK_P_MAKE_THE_SNOW = 114800,   //Stop shaking me!
    //While Make the snow is casting
    TALK_P_MAKE_THE_SNOW_CASTING = 114810 //Come on, don't stand in the Blizzard!
};

class boss_humongris : public CreatureScript
{
public:
    boss_humongris() : CreatureScript("boss_humongris") { }

    struct boss_humongrisAI : public WorldBossAI
    {
        boss_humongrisAI(Creature* creature) : WorldBossAI(creature) { }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->CombatStop(true);
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();
        }

        void EnterCombat(Unit* who) override
        {
            if (!who)
                return;

            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
            events.ScheduleEvent(EVENT_FIRE_BOOM, 14000);
            events.ScheduleEvent(EVENT_EARTHSHAKE_STOMP, 28800);
            events.ScheduleEvent(EVENT_ICE_FIST, 29000);
            events.ScheduleEvent(EVENT_MAKE_SNOW, 35000);
            events.ScheduleEvent(EVENT_YOU_GO_BANG, 24400);
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            //We don't want a boss not casting anything now, do we ?
            if (me->IsInCombat())
            {
                if (events.Empty())
                {
                    events.ScheduleEvent(EVENT_FIRE_BOOM, 14000);
                    events.ScheduleEvent(EVENT_EARTHSHAKE_STOMP, 28800);
                    events.ScheduleEvent(EVENT_ICE_FIST, 29000);
                    events.ScheduleEvent(EVENT_MAKE_SNOW, 35000);
                    events.ScheduleEvent(EVENT_YOU_GO_BANG, 24400);
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIRE_BOOM:
                {
                    me->AI()->Talk(TALK_H_FIRE_BOOM);
                    DoCastAOE(SPELL_FIRE_BOOM_TARGET);
                    events.ScheduleEvent(EVENT_FIRE_BOOM, 14000);
                    break;
                }
                case EVENT_EARTHSHAKE_STOMP:
                {
                    DoCastAOE(SPELL_EARTHSHAKE_STOMP, false);
                    events.ScheduleEvent(EVENT_EARTHSHAKE_STOMP, 28800);
                    break;
                }
                case EVENT_ICE_FIST:
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 10.0f, true);
                    if (!target)
                        break;

                    me->AI()->Talk(TALK_H_ICE_FIST);
                    DoCast(target, SPELL_ICE_FIST_DAMAGE);
                    events.ScheduleEvent(EVENT_ICE_FIST, 29000);
                    break;
                }
                case EVENT_MAKE_SNOW:
                {
                    me->AI()->Talk(TALK_H_MAKE_THE_SNOW_1);

                    DoCast(SPELL_MAKE_SNOW_CAST);
                    events.ScheduleEvent(EVENT_MAKE_SNOW, 35000);
                    break;
                }
                case EVENT_YOU_GO_BANG:
                {
                    Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0.0, 0.0, true);
                    if (!target)
                        break;
                    DoCast(target, SPELL_YOU_GO_BANG_TARGET, false);
                    events.ScheduleEvent(EVENT_YOU_GO_BANG, 24400);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_humongrisAI(creature);
    }
};

class spell_humongris_fire_boom_target : public SpellScriptLoader
{
public:
    spell_humongris_fire_boom_target() : SpellScriptLoader("spell_humongris_fire_boom_target") { }

    class spell_humongris_fire_boom_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_humongris_fire_boom_target_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_FIRE_BOOM_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_humongris_fire_boom_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_humongris_fire_boom_target_SpellScript();
    }
};

class at_humongris_make_the_snow : public AreaTriggerEntityScript
{
public:
    at_humongris_make_the_snow() : AreaTriggerEntityScript("at_humongris_make_the_snow") {}

    struct at_humongris_make_the_snowAI : AreaTriggerAI
    {
        at_humongris_make_the_snowAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            at->SetUInt32Value(AREATRIGGER_DECAL_PROPERTIES_ID, 13);

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        unit->CastSpell(unit, SPELL_MAKE_SNOW_DAMAGE, true);
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            if (!unit)
                return;

            if (unit->GetTypeId() == TYPEID_PLAYER)
                unit->CastSpell(unit, SPELL_MAKE_SNOW_DAMAGE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (!unit)
                return;

            if (unit->HasAura(SPELL_MAKE_SNOW_DAMAGE))
                unit->RemoveAura(SPELL_MAKE_SNOW_DAMAGE);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->HasAura(SPELL_MAKE_SNOW_DAMAGE))
                        unit->RemoveAura(SPELL_MAKE_SNOW_DAMAGE);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_humongris_make_the_snowAI(areatrigger);
    }
};

//216817
class spell_humongris_you_go_bang : public SpellScriptLoader
{
public:
    spell_humongris_you_go_bang() : SpellScriptLoader("spell_humongris_you_go_bang") { }

    class spell_humongris_you_go_bang_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_humongris_you_go_bang_AuraScript);

        void HandleHitDamage(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            target->CastSpell(target, SPELL_YOU_GO_BANG_DAMAGE, false);
        }

        void HandleHitBuff(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            target->CastSpell(target, SPELL_YOU_GO_BANG_AURA, false);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_humongris_you_go_bang_AuraScript::HandleHitDamage, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_humongris_you_go_bang_AuraScript::HandleHitBuff, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_humongris_you_go_bang_AuraScript();
    }
};

void AddSC_boss_humongris()
{
    new at_humongris_make_the_snow();

    new boss_humongris();

    new spell_humongris_fire_boom_target();
    new spell_humongris_you_go_bang();
}
