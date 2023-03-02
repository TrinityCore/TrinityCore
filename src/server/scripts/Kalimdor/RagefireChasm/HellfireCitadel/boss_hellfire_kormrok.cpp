/*
 * Copyright 2023 AzgathCore
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
#include "hellfire_citadel.h"

enum Spells
{
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

struct boss_hellfire_kormrok : public BossAI
{
    boss_hellfire_kormrok(Creature* creature) : BossAI(creature, DATA_HELLFIRE_KORMROK) { Initialize(); }

    void Initialize()
    {
        PhaseStatus = Phases::PHASE_INTRO;
        hp20 = false;
    }

    void ScheduleTasks() override
    {
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (!hp20 && HealthBelowPct(20))
        {
            hp20 = true;
        }

        switch (eventId)
        {
        case EVENT_INTRO:
        {
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            events.ScheduleEvent(EVENT_INTRO, 1s, PHASE_NORMAL);
        }
    }
    uint8 PhaseStatus;
    bool hp20;
};

void AddSC_boss_hellfire_kormrok()
{
    RegisterCreatureAI(boss_hellfire_kormrok);
}
