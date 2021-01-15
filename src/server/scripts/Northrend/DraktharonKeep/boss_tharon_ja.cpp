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
#include "drak_tharon_keep.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

/*
 * Known Issues: Spell 49356 and 53463 will be interrupted for an unknown reason
 */

enum Spells
{
    // Skeletal Spells (phase 1)
    SPELL_CURSE_OF_LIFE                           = 49527,
    SPELL_RAIN_OF_FIRE                            = 49518,
    SPELL_SHADOW_VOLLEY                           = 49528,
    SPELL_DECAY_FLESH                             = 49356, // cast at end of phase 1, starts phase 2
    // Flesh Spells (phase 2)
    SPELL_GIFT_OF_THARON_JA                       = 52509,
    SPELL_CLEAR_GIFT_OF_THARON_JA                 = 53242,
    SPELL_EYE_BEAM                                = 49544,
    SPELL_LIGHTNING_BREATH                        = 49537,
    SPELL_POISON_CLOUD                            = 49548,
    SPELL_RETURN_FLESH                            = 53463, // Channeled spell ending phase two and returning to phase 1. This ability will stun the party for 6 seconds.
    SPELL_ACHIEVEMENT_CHECK                       = 61863,
    SPELL_FLESH_VISUAL                            = 52582,
    SPELL_DUMMY                                   = 49551
};

enum Events
{
    EVENT_CURSE_OF_LIFE                           = 1,
    EVENT_RAIN_OF_FIRE,
    EVENT_SHADOW_VOLLEY,

    EVENT_EYE_BEAM,
    EVENT_LIGHTNING_BREATH,
    EVENT_POISON_CLOUD,

    EVENT_DECAY_FLESH,
    EVENT_GOING_FLESH,
    EVENT_RETURN_FLESH,
    EVENT_GOING_SKELETAL
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_KILL                                      = 1,
    SAY_FLESH                                     = 2,
    SAY_SKELETON                                  = 3,
    SAY_DEATH                                     = 4
};

enum Models
{
    MODEL_FLESH                                   = 27073
};

class boss_tharon_ja : public CreatureScript
{
    public:
        boss_tharon_ja() : CreatureScript("boss_tharon_ja") { }

        struct boss_tharon_jaAI : public BossAI
        {
            boss_tharon_jaAI(Creature* creature) : BossAI(creature, DATA_THARON_JA) { }

            void Reset() override
            {
                _Reset();
                me->RestoreDisplayId();
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_DECAY_FLESH, 20s);
                events.ScheduleEvent(EVENT_CURSE_OF_LIFE, 1s);
                events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 14s, 18s);
                events.ScheduleEvent(EVENT_SHADOW_VOLLEY, 8s, 10s);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);
                DoCastAOE(SPELL_CLEAR_GIFT_OF_THARON_JA, true);
                DoCastAOE(SPELL_ACHIEVEMENT_CHECK, true);
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
                        case EVENT_CURSE_OF_LIFE:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_CURSE_OF_LIFE);
                            events.ScheduleEvent(EVENT_CURSE_OF_LIFE, 10s, 15s);
                            return;
                        case EVENT_SHADOW_VOLLEY:
                            DoCastVictim(SPELL_SHADOW_VOLLEY);
                            events.ScheduleEvent(EVENT_SHADOW_VOLLEY, 8s, 10s);
                            return;
                        case EVENT_RAIN_OF_FIRE:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_RAIN_OF_FIRE);
                            events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 14s, 18s);
                            return;
                        case EVENT_LIGHTNING_BREATH:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_LIGHTNING_BREATH);
                            events.ScheduleEvent(EVENT_LIGHTNING_BREATH, 6s, 7s);
                            return;
                        case EVENT_EYE_BEAM:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_EYE_BEAM);
                            events.ScheduleEvent(EVENT_EYE_BEAM, 4s, 6s);
                            return;
                        case EVENT_POISON_CLOUD:
                            DoCastAOE(SPELL_POISON_CLOUD);
                            events.ScheduleEvent(EVENT_POISON_CLOUD, 10s, 12s);
                            return;
                        case EVENT_DECAY_FLESH:
                            DoCastAOE(SPELL_DECAY_FLESH);
                            events.ScheduleEvent(EVENT_GOING_FLESH, 6s);
                            return;
                        case EVENT_GOING_FLESH:
                            Talk(SAY_FLESH);
                            me->SetDisplayId(MODEL_FLESH);
                            DoCastAOE(SPELL_GIFT_OF_THARON_JA, true);
                            DoCast(me, SPELL_FLESH_VISUAL, true);
                            DoCast(me, SPELL_DUMMY, true);

                            events.Reset();
                            events.ScheduleEvent(EVENT_RETURN_FLESH, 20s);
                            events.ScheduleEvent(EVENT_LIGHTNING_BREATH, 3s, 4s);
                            events.ScheduleEvent(EVENT_EYE_BEAM, 4s, 8s);
                            events.ScheduleEvent(EVENT_POISON_CLOUD, 6s, 7s);
                            break;
                        case EVENT_RETURN_FLESH:
                            DoCastAOE(SPELL_RETURN_FLESH);
                            events.ScheduleEvent(EVENT_GOING_SKELETAL, 6s);
                            return;
                        case EVENT_GOING_SKELETAL:
                            Talk(SAY_SKELETON);
                            me->RestoreDisplayId();
                            DoCastAOE(SPELL_CLEAR_GIFT_OF_THARON_JA, true);

                            events.Reset();
                            events.ScheduleEvent(EVENT_DECAY_FLESH, 20s);
                            events.ScheduleEvent(EVENT_CURSE_OF_LIFE, 1s);
                            events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 14s, 18s);
                            events.ScheduleEvent(EVENT_SHADOW_VOLLEY, 8s, 10s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDrakTharonKeepAI<boss_tharon_jaAI>(creature);
        }
};

class spell_tharon_ja_clear_gift_of_tharon_ja : public SpellScriptLoader
{
    public:
        spell_tharon_ja_clear_gift_of_tharon_ja() : SpellScriptLoader("spell_tharon_ja_clear_gift_of_tharon_ja") { }

        class spell_tharon_ja_clear_gift_of_tharon_ja_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_tharon_ja_clear_gift_of_tharon_ja_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_GIFT_OF_THARON_JA });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->RemoveAura(SPELL_GIFT_OF_THARON_JA);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_tharon_ja_clear_gift_of_tharon_ja_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_tharon_ja_clear_gift_of_tharon_ja_SpellScript();
        }
};

void AddSC_boss_tharon_ja()
{
    new boss_tharon_ja();
    new spell_tharon_ja_clear_gift_of_tharon_ja();
}
