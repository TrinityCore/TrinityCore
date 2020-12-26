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

/* ScriptData
SDName: Boss_Murmur
SD%Complete: 90
SDComment: Timers may be incorrect
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "ScriptMgr.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "shadow_labyrinth.h"
#include "SpellScript.h"

enum Murmur
{
    // Spell
    SPELL_RESONANCE             = 33657,
    SPELL_MAGNETIC_PULL         = 33689,
    SPELL_SONIC_SHOCK           = 38797,
    SPELL_THUNDERING_STORM      = 39365,
    SPELL_SONIC_BOOM_CAST       = 33923,
    SPELL_SONIC_BOOM_EFFECT     = 33666,
    SPELL_MURMURS_TOUCH         = 33711,
    // Text
    EMOTE_SONIC_BOOM            = 0
};

enum Events
{
    EVENT_SONIC_BOOM            = 1,
    EVENT_MURMURS_TOUCH         = 2,
    EVENT_RESONANCE             = 3,
    EVENT_MAGNETIC_PULL         = 4,
    EVENT_THUNDERING_STORM      = 5,
    EVENT_SONIC_SHOCK           = 6
};

class boss_murmur : public CreatureScript
{
    public:
        boss_murmur() : CreatureScript("boss_murmur") { }

        struct boss_murmurAI : public BossAI
        {
            boss_murmurAI(Creature* creature) : BossAI(creature, DATA_MURMUR)
            {
                SetCombatMovement(false);
            }

            void Reset() override
            {
                _Reset();
                events.ScheduleEvent(EVENT_SONIC_BOOM, 30000);
                events.ScheduleEvent(EVENT_MURMURS_TOUCH, urand(8000, 20000));
                events.ScheduleEvent(EVENT_RESONANCE, 5000);
                events.ScheduleEvent(EVENT_MAGNETIC_PULL, urand(15000, 30000));
                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_THUNDERING_STORM, 15000);
                    events.ScheduleEvent(EVENT_SONIC_SHOCK, 10000);
                }

                // database should have `RegenHealth`=0 to prevent regen
                uint32 hp = me->CountPctFromMaxHealth(40);
                if (hp)
                    me->SetHealth(hp);
                me->ResetPlayerDamageReq();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SONIC_BOOM:
                            Talk(EMOTE_SONIC_BOOM);
                            DoCast(me, SPELL_SONIC_BOOM_CAST);
                            events.ScheduleEvent(EVENT_SONIC_BOOM, 30000);
                            events.ScheduleEvent(EVENT_RESONANCE, 1500);
                            break;
                        case EVENT_MURMURS_TOUCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                                DoCast(target, SPELL_MURMURS_TOUCH);
                            events.ScheduleEvent(EVENT_MURMURS_TOUCH, urand(25000, 35000));
                            break;
                        case EVENT_RESONANCE:
                            if (!(me->IsWithinMeleeRange(me->GetVictim())))
                            {
                                DoCast(me, SPELL_RESONANCE);
                                events.ScheduleEvent(EVENT_RESONANCE, 5000);
                            }
                            break;
                        case EVENT_MAGNETIC_PULL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                DoCast(target, SPELL_MAGNETIC_PULL);
                                events.ScheduleEvent(EVENT_MAGNETIC_PULL, urand(15000, 30000));
                                break;
                            }
                            events.ScheduleEvent(EVENT_MAGNETIC_PULL, 500);
                            break;
                        case EVENT_THUNDERING_STORM:
                            DoCastAOE(SPELL_THUNDERING_STORM, true);
                            events.ScheduleEvent(EVENT_THUNDERING_STORM, 15000);
                            break;
                        case EVENT_SONIC_SHOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, false))
                                DoCast(target, SPELL_SONIC_SHOCK);
                            events.ScheduleEvent(EVENT_SONIC_SHOCK, urand(10000, 20000));
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                // Select nearest most aggro target if top aggro too far
                if (!me->isAttackReady())
                    return;

                if (!me->IsWithinMeleeRange(me->GetVictim()))
                    me->GetThreatManager().ResetThreat(me->GetVictim());

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetShadowLabyrinthAI<boss_murmurAI>(creature);
        }
};

// 33923, 38796 - Sonic Boom
class spell_murmur_sonic_boom : public SpellScriptLoader
{
    public:
        spell_murmur_sonic_boom() : SpellScriptLoader("spell_murmur_sonic_boom") { }

        class spell_murmur_sonic_boom_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_murmur_sonic_boom_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SONIC_BOOM_EFFECT });
            }

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(nullptr, SPELL_SONIC_BOOM_EFFECT, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_murmur_sonic_boom_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_murmur_sonic_boom_SpellScript();
        }
};

// 33666, 38795 - Sonic Boom Effect
class spell_murmur_sonic_boom_effect : public SpellScriptLoader
{
    public:
        spell_murmur_sonic_boom_effect() : SpellScriptLoader("spell_murmur_sonic_boom_effect") { }

        class spell_murmur_sonic_boom_effect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_murmur_sonic_boom_effect_SpellScript);

            void CalcDamage()
            {
                if (Unit* target = GetHitUnit())
                    SetHitDamage(target->CountPctFromMaxHealth(80)); /// @todo: find correct value
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_murmur_sonic_boom_effect_SpellScript::CalcDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_murmur_sonic_boom_effect_SpellScript();
        }
};

class ThunderingStormCheck
{
    public:
        ThunderingStormCheck(WorldObject* source) : _source(source) { }

        bool operator()(WorldObject* obj)
        {
            float distSq = _source->GetExactDist2dSq(obj);
            return distSq < (25.0f * 25.0f) || distSq > (100.0f * 100.0f);
        }

    private:
        WorldObject const* _source;
};

// 39365 - Thundering Storm
class spell_murmur_thundering_storm : public SpellScriptLoader
{
    public:
        spell_murmur_thundering_storm() : SpellScriptLoader("spell_murmur_thundering_storm") { }

        class spell_murmur_thundering_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_murmur_thundering_storm_SpellScript);

            void FilterTarget(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ThunderingStormCheck(GetCaster()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_murmur_thundering_storm_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_murmur_thundering_storm_SpellScript();
        }
};

void AddSC_boss_murmur()
{
    new boss_murmur();
    new spell_murmur_sonic_boom();
    new spell_murmur_sonic_boom_effect();
    new spell_murmur_thundering_storm();
}
