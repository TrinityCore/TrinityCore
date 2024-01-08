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
#include "baradin_hold.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

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

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_METEOR_SLASH, 10s, 20s);
                events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 20s, 25s);
                events.ScheduleEvent(EVENT_BERSERK, 5min);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _DespawnAtEvade();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (me->HealthBelowPctDamaged(33, damage) ||
                    me->HealthBelowPctDamaged(66, damage))
                {
                    DoCastAOE(SPELL_FEL_FIRESTORM);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
                        case EVENT_METEOR_SLASH:
                            DoCastAOE(SPELL_METEOR_SLASH);
                            events.ScheduleEvent(EVENT_METEOR_SLASH, 15s, 20s);
                            break;
                        case EVENT_CONSUMING_DARKNESS:
                            DoCastAOE(SPELL_CONSUMING_DARKNESS, true);
                            events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 20s, 25s);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argaloth_consuming_darkness_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
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

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argaloth_meteor_slash_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CONE_CASTER_TO_DEST_ENEMY);
                OnHit += SpellHitFn(spell_argaloth_meteor_slash_SpellScript::SplitDamage);
            }

        private:
            uint32 _targetCount = 0;
        };

        SpellScript* GetSpellScript() const override
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
