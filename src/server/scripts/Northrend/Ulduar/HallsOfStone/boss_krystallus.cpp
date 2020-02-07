/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "halls_of_stone.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_BOULDER_TOSS                          = 50843,
    SPELL_GROUND_SPIKE                          = 59750,
    SPELL_GROUND_SLAM                           = 50827,
    SPELL_SHATTER                               = 50810,
    SPELL_SHATTER_EFFECT                        = 50811,
    SPELL_STONED                                = 50812,
    SPELL_STOMP                                 = 48131
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_KILL                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SHATTER                                 = 3
};

enum Events
{
    EVENT_BOULDER_TOSS                          = 1,
    EVENT_GROUND_SPIKE,
    EVENT_GROUND_SLAM,
    EVENT_STOMP,
    EVENT_SHATTER
};

class boss_krystallus : public CreatureScript
{
    public:
        boss_krystallus() : CreatureScript("boss_krystallus") { }

        struct boss_krystallusAI : public BossAI
        {
            boss_krystallusAI(Creature* creature) : BossAI(creature, DATA_KRYSTALLUS) { }

            void Reset() override
            {
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_BOULDER_TOSS, 3s, 9s);
                events.ScheduleEvent(EVENT_GROUND_SLAM, 15s, 18s);
                events.ScheduleEvent(EVENT_STOMP, 20s, 29s);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_GROUND_SPIKE, 9s, 14s);
            }

            void UpdateAI(uint32 diff) override
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOULDER_TOSS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                                DoCast(target, SPELL_BOULDER_TOSS);
                            events.ScheduleEvent(EVENT_BOULDER_TOSS, 9s, 15s);
                            break;
                        case EVENT_GROUND_SPIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_GROUND_SPIKE);
                            events.ScheduleEvent(EVENT_GROUND_SPIKE, 12s, 17s);
                            break;
                        case EVENT_GROUND_SLAM:
                            DoCast(me, SPELL_GROUND_SLAM);
                            events.ScheduleEvent(EVENT_SHATTER, 10s);
                            events.ScheduleEvent(EVENT_GROUND_SLAM, 15s, 18s);
                            break;
                        case EVENT_STOMP:
                            DoCast(me, SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, 20s, 29s);
                            break;
                        case EVENT_SHATTER:
                            DoCast(me, SPELL_SHATTER);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfStoneAI<boss_krystallusAI>(creature);
        }
};

class spell_krystallus_shatter : public SpellScriptLoader
{
    public:
        spell_krystallus_shatter() : SpellScriptLoader("spell_krystallus_shatter") { }

        class spell_krystallus_shatter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_krystallus_shatter_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    target->RemoveAurasDueToSpell(SPELL_STONED);
                    target->CastSpell(nullptr, SPELL_SHATTER_EFFECT, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_krystallus_shatter_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_krystallus_shatter_SpellScript();
        }
};

class spell_krystallus_shatter_effect : public SpellScriptLoader
{
    public:
        spell_krystallus_shatter_effect() : SpellScriptLoader("spell_krystallus_shatter_effect") { }

        class spell_krystallus_shatter_effect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_krystallus_shatter_effect_SpellScript);

            void CalculateDamage()
            {
                if (!GetHitUnit())
                    return;

                float radius = GetSpellInfo()->Effects[EFFECT_0].CalcRadius(GetCaster());
                if (!radius)
                    return;

                float distance = GetCaster()->GetDistance2d(GetHitUnit());
                if (distance > 1.0f)
                    SetHitDamage(int32(GetHitDamage() * ((radius - distance) / radius)));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_krystallus_shatter_effect_SpellScript::CalculateDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_krystallus_shatter_effect_SpellScript();
        }
};

void AddSC_boss_krystallus()
{
    new boss_krystallus();
    new spell_krystallus_shatter();
    new spell_krystallus_shatter_effect();
}
