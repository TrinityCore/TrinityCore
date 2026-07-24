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
#include "arcatraz.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"

enum SkyrissTexts
{
    SAY_INTRO                    = 0,
    SAY_AGGRO                    = 1,
    SAY_SLAY                     = 2,
    SAY_MIND                     = 3,
    SAY_FEAR                     = 4,
    SAY_IMAGE                    = 5,
    SAY_DEATH                    = 6
};

enum SkyrissSpells
{
    // Intro
    SPELL_SIMPLE_TELEPORT        = 12980,
    SPELL_MIND_REND_COSMETIC     = 36859,
    // Combat
    SPELL_FEAR                   = 39415,
    SPELL_MIND_REND              = 36924,
    SPELL_DOMINATION             = 37162,
    SPELL_DOMINATION_H           = 39019,
    SPELL_MANA_BURN              = 39020,

    SPELL_SUMMON_66_ILLUSION     = 36931,
    SPELL_SUMMON_33_ILLUSION     = 36932,
    // Illusion
    SPELL_BIRTH                  = 26262,
    SPELL_BLINK_VISUAL           = 36937,
    SPELL_66_HEALTH              = 36928,
    SPELL_33_HEALTH              = 36930,
    SPELL_MIND_REND_IMAGE        = 36929,
    SPELL_MIND_REND_IMAGE_H      = 39021
};

enum SkyrissEvents
{
    EVENT_MIND_REND              = 1,
    EVENT_FEAR,
    EVENT_DOMINATION,
    EVENT_MANA_BURN,
    EVENT_SUMMON_66,
    EVENT_SUMMON_33,

    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3
};

enum SkyrissMisc
{
    NPC_ILLUSION_66              = 21466,
    NPC_ILLUSION_33              = 21467
};

enum SkyrissPhases : uint8
{
    PHASE_NONE                   = 0,
    PHASE_HEALTH_66,
    PHASE_HEALTH_33
};

// 20912 - Harbinger Skyriss
struct boss_harbinger_skyriss : public BossAI
{
    boss_harbinger_skyriss(Creature* creature) : BossAI(creature, DATA_HARBINGER_SKYRISS), _phase(PHASE_NONE) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_INTRO_1, 0s);
    }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_MIND_REND, 2s, 10s);
        events.ScheduleEvent(EVENT_FEAR, 10s, 20s);
        events.ScheduleEvent(EVENT_DOMINATION, 30s, 40s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_MANA_BURN, 25s);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_FEAR:
                Talk(SAY_FEAR);
                break;
            case SPELL_DOMINATION:
            case SPELL_DOMINATION_H:
                Talk(SAY_MIND);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_66 && me->HealthBelowPctDamaged(66, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON_66, 0s);
        }
        if (_phase < PHASE_HEALTH_33 && me->HealthBelowPctDamaged(33, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON_33, 0s);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_1:
                        Talk(SAY_INTRO);
                        DoCastSelf(SPELL_SIMPLE_TELEPORT);
                        events.ScheduleEvent(EVENT_INTRO_2, 30s);
                        break;
                    case EVENT_INTRO_2:
                        Talk(SAY_AGGRO);
                        DoCastSelf(SPELL_MIND_REND_COSMETIC);
                        events.ScheduleEvent(EVENT_INTRO_3, 2s);
                        break;
                    case EVENT_INTRO_3:
                        me->SetImmuneToAll(false);
                        DoZoneInCombat();
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MIND_REND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_MIND_REND);
                    events.Repeat(8s, 12s);
                    break;
                case EVENT_FEAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FEAR);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_DOMINATION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_DOMINATION);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_MANA_BURN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_MANA_BURN);
                    events.Repeat(15s, 30s);
                    break;
                case EVENT_SUMMON_66:
                    Talk(SAY_IMAGE);
                    DoCastSelf(SPELL_SUMMON_66_ILLUSION);
                    DoCastSelf(SPELL_BLINK_VISUAL);
                    break;
                case EVENT_SUMMON_33:
                    Talk(SAY_IMAGE);
                    DoCastSelf(SPELL_SUMMON_33_ILLUSION);
                    DoCastSelf(SPELL_BLINK_VISUAL);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
};

// 21466, 21467 - Harbinger Skyriss
struct boss_harbinger_skyriss_illusion : public ScriptedAI
{
    boss_harbinger_skyriss_illusion(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
        me->SetCorpseDelay(0, true);
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(0s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_BIRTH);
            })
            .Schedule(0s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_BLINK_VISUAL);
            })
            .Schedule(0s, [this](TaskContext /*task*/)
            {
                switch (me->GetEntry())
                {
                    case NPC_ILLUSION_66:
                        DoCastSelf(SPELL_66_HEALTH);
                        break;
                    case NPC_ILLUSION_33:
                        DoCastSelf(SPELL_33_HEALTH);
                        break;
                    default:
                       break;
                }
            })
            .Schedule(2s, 10s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, IsHeroic() ? SPELL_MIND_REND_IMAGE_H : SPELL_MIND_REND_IMAGE);
                task.Repeat(8s, 12s);
            });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

// 36928 - 66% Health
// 36930 - 33% Health
class spell_harbinger_skyriss_health : public SpellScript
{
    PrepareSpellScript(spell_harbinger_skyriss_health);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->SetHealth(GetCaster()->CountPctFromMaxHealth(uint32(GetEffectValue())));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_harbinger_skyriss_health::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_harbinger_skyriss()
{
    RegisterArcatrazCreatureAI(boss_harbinger_skyriss);
    RegisterArcatrazCreatureAI(boss_harbinger_skyriss_illusion);
    RegisterSpellScript(spell_harbinger_skyriss_health);
}
