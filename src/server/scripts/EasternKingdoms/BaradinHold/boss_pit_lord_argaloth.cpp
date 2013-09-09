/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "baradin_hold.h"

/* TODO:
- Fel Firestorm need completion
- Need Correct timer
*/

enum Spells
{
    SPELL_METEOR_SLASH          = 88942,
    SPELL_CONSUMING_DARKNESS    = 88954,
    SPELL_FEL_FIRESTORM         = 88972,
    SPELL_BERSERK               = 47008
};

enum Events
{
    EVENT_METEOR_SLASH          = 1,
    EVENT_CONSUMING_DARKNESS    = 2,
    EVENT_BERSERK               = 3
};

class boss_pit_lord_argaloth : public CreatureScript
{
    public:
        boss_pit_lord_argaloth() : CreatureScript("boss_pit_lord_argaloth") { }

        struct boss_pit_lord_argalothAI : public BossAI
        {
            boss_pit_lord_argalothAI(Creature* creature) : BossAI(creature, DATA_ARGALOTH) { }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_METEOR_SLASH, urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, urand(20 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_BERSERK, 5 * MINUTE * IN_MILLISECONDS);
            }

            void EnterEvadeMode() OVERRIDE
            {
                me->GetMotionMaster()->MoveTargetedHome();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _DespawnAtEvade();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) OVERRIDE
            {
                if (me->HealthBelowPctDamaged(33, damage) ||
                    me->HealthBelowPctDamaged(66, damage))
                {
                    DoCastAOE(SPELL_FEL_FIRESTORM);
                }
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                        case EVENT_METEOR_SLASH:
                            DoCastAOE(SPELL_METEOR_SLASH);
                            events.ScheduleEvent(EVENT_METEOR_SLASH, urand(15 * IN_MILLISECONDS, 20 * IN_MILLISECONDS));
                            break;
                        case EVENT_CONSUMING_DARKNESS:
                            DoCastAOE(SPELL_CONSUMING_DARKNESS, true);
                            events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, urand(20 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetBaradinHoldAI<boss_pit_lord_argalothAI>(creature);
        }
};

// 88954 / 95173 - Consuming Darkness
class spell_argaloth_consuming_darkness : public SpellScriptLoader
{
    public:
        spell_argaloth_consuming_darkness() : SpellScriptLoader("spell_argaloth_consuming_darkness") { }

        class spell_argaloth_consuming_darkness_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_argaloth_consuming_darkness_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResizeList(targets, GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3);
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argaloth_consuming_darkness_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_argaloth_consuming_darkness_SpellScript();
        }
};

// 88942 / 95172 - Meteor Slash
class spell_argaloth_meteor_slash : public SpellScriptLoader
{
    public:
        spell_argaloth_meteor_slash() : SpellScriptLoader("spell_argaloth_meteor_slash") { }

        class spell_argaloth_meteor_slash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_argaloth_meteor_slash_SpellScript);

            bool Load() OVERRIDE
            {
                _targetCount = 0;
                return true;
            }

            void CountTargets(std::list<WorldObject*>& targets)
            {
                _targetCount = targets.size();
            }

            void SplitDamage()
            {
                if (!_targetCount)
                    return;

                SetHitDamage(GetHitDamage() / _targetCount);
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argaloth_meteor_slash_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnHit += SpellHitFn(spell_argaloth_meteor_slash_SpellScript::SplitDamage);
            }

        private:
            uint32 _targetCount;
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_argaloth_meteor_slash_SpellScript();
        }
};

void AddSC_boss_pit_lord_argaloth()
{
    new boss_pit_lord_argaloth();
    new spell_argaloth_consuming_darkness();
    new spell_argaloth_meteor_slash();
}
