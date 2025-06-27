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
#include "SpellInfo.h"
#include "mechanar.h"
#include "ScriptedCreature.h"

enum GyroKillTexts
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_SAW_BLADES                  = 2,
    SAY_DEATH                       = 3
};

enum GyroKillSpells
{
    SPELL_STREAM_OF_MACHINE_FLUID   = 35311,
    SPELL_SAW_BLADE                 = 35318,
    SPELL_SHADOW_POWER              = 35322
};

enum GyroKillEvents
{
    EVENT_STREAM_OF_MACHINE_FLUID   = 1,
    EVENT_SAW_BLADE,
    EVENT_SHADOW_POWER
};

// 19218 - Gatewatcher Gyro-Kill
struct boss_gatewatcher_gyrokill : public BossAI
{
    boss_gatewatcher_gyrokill(Creature* creature) : BossAI(creature, DATA_GATEWATCHER_GYROKILL) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, 10s);
        events.ScheduleEvent(EVENT_SAW_BLADE, 20s);
        events.ScheduleEvent(EVENT_SHADOW_POWER, 25s);
        Talk(SAY_AGGRO);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SAW_BLADE)
            Talk(SAY_SAW_BLADES);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                case EVENT_STREAM_OF_MACHINE_FLUID:
                    DoCastVictim(SPELL_STREAM_OF_MACHINE_FLUID);
                    events.Repeat(13s, 17s);
                    break;
                case EVENT_SAW_BLADE:
                    DoCastVictim(SPELL_SAW_BLADE);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_SHADOW_POWER:
                    DoCastSelf(SPELL_SHADOW_POWER);
                    events.Repeat(25s, 35s);
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

void AddSC_boss_gatewatcher_gyrokill()
{
    RegisterMechanarCreatureAI(boss_gatewatcher_gyrokill);
}
