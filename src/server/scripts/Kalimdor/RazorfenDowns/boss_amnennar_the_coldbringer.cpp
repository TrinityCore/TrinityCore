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

/*
 * Timers requires update
 * Guardians are despawned in core, that should not happen here
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "razorfen_downs.h"

enum AmnennarTexts
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_HEALTH_75                  = 2,
    SAY_SUMMON_60                  = 3,
    SAY_SUMMON_30                  = 4,
    EMOTE_SUMMON                   = 5
};

enum AmnennarSpells
{
    SPELL_AMNENNARS_WRATH          = 13009,
    SPELL_FROSTBOLT                = 15530,
    SPELL_FROST_NOVA               = 15531,
    SPELL_SUMMON_FROST_SPECTRES    = 12642,
    SPELL_BANISH_FROST_SPECTRES    = 12660
};

enum AmnennarEvents
{
    EVENT_AMNENNARS_WRATH          = 1,
    EVENT_FROSTBOLT,
    EVENT_FROST_NOVA,

    EVENT_HEALTH_75,
    EVENT_HEALTH_60,
    EVENT_HEALTH_30
};

enum AmnennarPhases : uint8
{
    PHASE_NONE                     = 0,
    PHASE_HEALTH_75,
    PHASE_HEALTH_60,
    PHASE_HEALTH_30
};

// 7358 - Amnennar the Coldbringer
struct boss_amnennar_the_coldbringer : public BossAI
{
    boss_amnennar_the_coldbringer(Creature* creature) : BossAI(creature, DATA_AMNENNAR_THE_COLD_BRINGER), _phase(PHASE_NONE) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_AMNENNARS_WRATH, 8s);
        events.ScheduleEvent(EVENT_FROSTBOLT, 0s);
        events.ScheduleEvent(EVENT_FROST_NOVA, 10s, 15s);
        Talk(SAY_AGGRO);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_75 && me->HealthBelowPctDamaged(75, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_HEALTH_75, 0s);
        }

        if (_phase < PHASE_HEALTH_60 && me->HealthBelowPctDamaged(60, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_HEALTH_60, 0s);
        }

        if (_phase < PHASE_HEALTH_30 && me->HealthBelowPctDamaged(30, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_HEALTH_30, 0s);
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    // Despawn is handled by spell, don't store anything
    void JustSummoned(Creature* /*summon*/) override { }

    void EnterEvadeMode(EvadeReason why) override
    {
        DoCastSelf(SPELL_BANISH_FROST_SPECTRES, true);
        BossAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoCastSelf(SPELL_BANISH_FROST_SPECTRES, true);
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
                case EVENT_AMNENNARS_WRATH:
                    DoCastVictim(SPELL_AMNENNARS_WRATH);
                    events.Repeat(12s);
                    break;
                case EVENT_FROSTBOLT:
                    DoCastVictim(SPELL_FROSTBOLT);
                    events.Repeat(8s);
                    break;
                case EVENT_FROST_NOVA:
                    DoCastSelf(SPELL_FROST_NOVA);
                    events.Repeat(15s);
                    break;

                case EVENT_HEALTH_75:
                    Talk(SAY_HEALTH_75);
                    break;
                case EVENT_HEALTH_60:
                    Talk(EMOTE_SUMMON);
                    Talk(SAY_SUMMON_60);
                    DoCastSelf(SPELL_SUMMON_FROST_SPECTRES);
                    break;
                case EVENT_HEALTH_30:
                    Talk(EMOTE_SUMMON);
                    Talk(SAY_SUMMON_30);
                    DoCastSelf(SPELL_SUMMON_FROST_SPECTRES);
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

void AddSC_boss_amnennar_the_coldbringer()
{
    RegisterRazorfenDownsCreatureAI(boss_amnennar_the_coldbringer);
}
