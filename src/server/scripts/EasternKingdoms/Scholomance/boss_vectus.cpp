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
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

enum VectusTexts
{
    TALK_IDLE                    = 1,
    TALK_IDLE2                   = 2,
    TALK_IDLE3                   = 3
};

enum VectusSpells
{
    // Passive
    SPELL_FIRE_SHIELD            = 13377,

    // Combat
    SPELL_BLAST_WAVE             = 16046,
    SPELL_FLAMESTRIKE            = 18399
};

enum VectusEvents
{
    EVENT_BLAST_WAVE             = 1,
    EVENT_FLAMESTRIKE
};

enum VectusPaths
{
    PATH_VECTUS_IDLE = 3904400
};

// 10432 - Vectus
struct boss_vectus : public BossAI
{
    boss_vectus(Creature* creature) : BossAI(creature, DATA_VECTUS) { }

    void Reset() override
    {
        events.Reset();

        DoCastSelf(SPELL_FIRE_SHIELD);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_BLAST_WAVE, 15s, 25s);
        events.ScheduleEvent(EVENT_FLAMESTRIKE, 10s, 15s);
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
                case EVENT_BLAST_WAVE:
                    DoCastSelf(SPELL_BLAST_WAVE);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_FLAMESTRIKE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FLAMESTRIKE);
                    events.Repeat(10s, 15s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId != PATH_VECTUS_IDLE)
            return;

        if (waypointId == 2)
            Talk(TALK_IDLE);
        else if (waypointId == 3)
            Talk(TALK_IDLE2);
        else if (waypointId == 4)
            Talk(TALK_IDLE3);
    }
};

void AddSC_boss_vectus()
{
    RegisterScholomanceCreatureAI(boss_vectus);
}
