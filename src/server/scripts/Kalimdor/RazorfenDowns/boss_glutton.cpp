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
#include "ScriptedCreature.h"
#include "razorfen_downs.h"

enum GluttonTexts
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_HEALTH_50           = 2,
    SAY_HEALTH_15           = 3
};

enum GluttonSpells
{
    SPELL_THRASH_15         = 8876,
    SPELL_DISEASE_CLOUD     = 12627,
    SPELL_THRASH_35         = 12787,
    SPELL_FRENZY            = 12795
};

enum GluttonEvents
{
    EVENT_HEALTH_50         = 1,
    EVENT_HEALTH_15
};

enum GluttonPhases : uint8
{
    PHASE_NONE              = 0,
    PHASE_HEALTH_50,
    PHASE_HEALTH_15
};

// 8567 - Glutton
struct boss_glutton : public BossAI
{
    boss_glutton(Creature* creature) : BossAI(creature, DATA_GLUTTON), _phase(PHASE_NONE) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
        DoCastSelf(SPELL_THRASH_15);
        DoCastSelf(SPELL_DISEASE_CLOUD);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_50 && me->HealthBelowPctDamaged(50, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_HEALTH_50, 0s);
        }

        if (_phase < PHASE_HEALTH_15 && me->HealthBelowPctDamaged(15, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_HEALTH_15, 0s);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
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
                case EVENT_HEALTH_50:
                    Talk(SAY_HEALTH_50);
                    me->RemoveAurasDueToSpell(SPELL_THRASH_15);
                    DoCastSelf(SPELL_THRASH_35);
                    break;
                case EVENT_HEALTH_15:
                    Talk(SAY_HEALTH_15);
                    DoCastSelf(SPELL_FRENZY);
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

void AddSC_boss_glutton()
{
    RegisterRazorfenDownsCreatureAI(boss_glutton);
}
