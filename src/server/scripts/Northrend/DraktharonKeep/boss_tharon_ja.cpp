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
#include "drak_tharon_keep.h"
#include "Player.h"

enum Spells
{
    // skeletal spells (phase 1)
    SPELL_CURSE_OF_LIFE                           = 49527,
    SPELL_RAIN_OF_FIRE                            = 49518,
    SPELL_SHADOW_VOLLEY                           = 49528,
    SPELL_DECAY_FLESH                             = 49356, // casted at end of phase 1, starts phase 2
    // flesh spells (phase 2)
    SPELL_GIFT_OF_THARON_JA                       = 52509,
    SPELL_CLEAR_GIFT_OF_THARON_JA                 = 53242,
    SPELL_EYE_BEAM                                = 49544,
    SPELL_LIGHTNING_BREATH                        = 49537,
    SPELL_POISON_CLOUD                            = 49548,
    SPELL_RETURN_FLESH                            = 53463, // Channeled spell ending phase two and returning to phase 1. This ability will stun the party for 6 seconds.
    SPELL_ACHIEVEMENT_CHECK                       = 61863
};

enum Events
{
    EVENT_CURSE_OF_LIFE                           = 1,
    EVENT_RAIN_OF_FIRE,
    EVENT_SHADOW_VOLLEY,
    EVENT_DECAY_FLESH,
    EVENT_EYE_BEAM,
    EVENT_LIGHTNING_BREATH,
    EVENT_POISON_CLOUD,
    EVENT_RETURN_FLESH,

    EVENT_PHASE_SWITCH
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
    MODEL_FLESH                                   = 27073,
    MODEL_SKELETON                                = 27511
};

enum Phases
{
    PHASE_SKELETAL,
    PHASE_GOING_FLESH,
    PHASE_FLESH,
    PHASE_GOING_SKELETAL
};

class boss_tharon_ja : public CreatureScript
{
    public:
        boss_tharon_ja() : CreatureScript("boss_tharon_ja") { }

        struct boss_tharon_jaAI : public BossAI
        {
            boss_tharon_jaAI(Creature* creature) : BossAI(creature, DATA_THARON_JA) { }

            void Reset() OVERRIDE
            {
                _Reset();
                me->SetDisplayId(me->GetNativeDisplayId());
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                events.SetPhase(PHASE_SKELETAL);
                events.ScheduleEvent(EVENT_PHASE_SWITCH, 20000);
                events.ScheduleEvent(EVENT_CURSE_OF_LIFE, 1000);
                events.ScheduleEvent(EVENT_RAIN_OF_FIRE, urand(14000, 18000));
                events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(8000, 10000));
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) || me->IsNonMeleeSpellCasted(true))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CURSE_OF_LIFE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_CURSE_OF_LIFE);
                            events.ScheduleEvent(EVENT_CURSE_OF_LIFE, urand(10000, 15000));
                            break;
                        case EVENT_SHADOW_VOLLEY:
                            DoCastVictim(SPELL_SHADOW_VOLLEY);
                            events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(8000, 10000));
                            break;
                        case EVENT_RAIN_OF_FIRE:
                            DoCastAOE(SPELL_RAIN_OF_FIRE);
                            events.ScheduleEvent(EVENT_RAIN_OF_FIRE, urand(14000, 18000));
                            break;
                        case EVENT_LIGHTNING_BREATH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_LIGHTNING_BREATH);
                            events.ScheduleEvent(EVENT_LIGHTNING_BREATH, urand(6000, 7000));
                            break;
                        case EVENT_EYE_BEAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_EYE_BEAM);
                            events.ScheduleEvent(EVENT_EYE_BEAM, urand(4000, 6000));
                            break;
                        case EVENT_POISON_CLOUD:
                            DoCastAOE(SPELL_POISON_CLOUD);
                            events.ScheduleEvent(EVENT_POISON_CLOUD, urand(10000, 12000));
                            break;
                        case EVENT_PHASE_SWITCH:
                            if (events.IsInPhase(PHASE_SKELETAL))
                            {
                                DoCastAOE(SPELL_DECAY_FLESH);
                                events.SetPhase(PHASE_GOING_FLESH);
                                events.ScheduleEvent(EVENT_PHASE_SWITCH, 6000);
                            }

                            if (events.IsInPhase(PHASE_GOING_FLESH))
                            {
                                Talk(SAY_FLESH);
                                me->SetDisplayId(MODEL_FLESH);
                                DoCast(SPELL_GIFT_OF_THARON_JA);

                                events.ScheduleEvent(EVENT_PHASE_SWITCH, 20000);
                                events.ScheduleEvent(EVENT_LIGHTNING_BREATH, urand(3000, 4000));
                                events.ScheduleEvent(EVENT_EYE_BEAM, urand(4000, 8000));
                                events.ScheduleEvent(EVENT_POISON_CLOUD, urand(6000, 7000));
                                events.SetPhase(PHASE_FLESH);
                            }

                            if (events.IsInPhase(PHASE_FLESH))
                            {
                                DoCastAOE(SPELL_RETURN_FLESH);
                                events.SetPhase(PHASE_GOING_SKELETAL);
                                events.ScheduleEvent(EVENT_PHASE_SWITCH, 6000);
                            }

                            if (events.IsInPhase(PHASE_GOING_SKELETAL))
                            {
                                Talk(SAY_SKELETON);
                                me->DeMorph();
                                events.SetPhase(PHASE_SKELETAL);
                                events.ScheduleEvent(EVENT_PHASE_SWITCH, 20000);
                                events.ScheduleEvent(EVENT_CURSE_OF_LIFE, 1000);
                                events.ScheduleEvent(EVENT_RAIN_OF_FIRE, urand(14000, 18000));
                                events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(8000, 10000));
                                DoCast(SPELL_CLEAR_GIFT_OF_THARON_JA);
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                Talk(SAY_DEATH);
                _JustDied();

                // clean morph on players
                Map::PlayerList const &PlayerList = instance->instance->GetPlayers();

                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        player->DeMorph();

                DoCastAOE(SPELL_ACHIEVEMENT_CHECK);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetDrakTharonKeepAI<boss_tharon_jaAI>(creature);
        }
};

class spell_clear_gift_of_tharon_ja : public SpellScriptLoader
{
    public:
        spell_clear_gift_of_tharon_ja() : SpellScriptLoader("spell_clear_gift_of_tharon_ja") { }

        class spell_clear_gift_of_tharon_ja_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_clear_gift_of_tharon_ja_SpellScript);

            bool Validate(SpellInfo const* spellInfo) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_GIFT_OF_THARON_JA))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->RemoveAura(SPELL_GIFT_OF_THARON_JA);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_clear_gift_of_tharon_ja_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_clear_gift_of_tharon_ja_SpellScript();
        }
};

void AddSC_boss_tharon_ja()
{
    new boss_tharon_ja();
    new spell_clear_gift_of_tharon_ja();
}
