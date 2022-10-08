/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "cathedral_of_eternal_night.h"

enum Spells
{
    SPELL_CHAOTIC_ENERGY = 234107,
    SPELL_FELSOUL_CLEAVE = 236543,
    SPELL_FRENZY = 243157,
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
    EVENT_SUMMON = 2,
};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_MOVEINLINEOFSIGHT,           EVENT_TYPE_TALK,            0 },
    { EVENT_ON_ENTERCOMBAT,                 EVENT_TYPE_TALK,            1 },
    //{ EVENT_SUMMON,                  EVENT_TYPE_TALK,            2 },
    //{ EVENT_SUMMON,                    EVENT_TYPE_TALK,            3 },
    { EVENT_ON_JUSTDIED,                    EVENT_TYPE_TALK,            4 },
};


std::vector<EventData> const eventData =
{
    { PHASE_01, PHASE_01, SPELL_CHAOTIC_ENERGY,   5000 },
    { PHASE_01, PHASE_01, SPELL_FELSOUL_CLEAVE,   5000 },
    { PHASE_01, PHASE_01, SPELL_FRENZY,           5000 },
};


struct boss_domatrax : public BossAI
{
    boss_domatrax(Creature* creature) : BossAI(creature, DATA_DOMATRAX) { Initialize(); }

    void Initialize()
    {
        PhaseStatus = PHASE_00;
        //SetDungeonEncounterID(2053);
        LoadEventData(&eventData);
        LoadTalkData(&talkData);
        hp25 = false;
        hp50 = false;
        hp90 = false;
    }

    void ScheduleTasks() override
    {
        GetEventData(PHASE_01);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (!hp25 && HealthBelowPct(25))
        {
            hp25 = true;
            events.ScheduleEvent(EVENT_SUMMON, 1000);
        }
        if (!hp50 && HealthBelowPct(50))
        {
            hp50 = true;
            events.ScheduleEvent(EVENT_SUMMON, 1000);
        }
        if (!hp90 && HealthBelowPct(90))
        {
            hp90 = true;
            events.ScheduleEvent(EVENT_SUMMON, 1000);
        }
        switch (eventId)
        {
        case EVENT_SUMMON:
        {
            break;
        }
        case SPELL_CHAOTIC_ENERGY:
        {
            DoCast(SPELL_CHAOTIC_ENERGY);
            events.Repeat(5s);
            break;
        }
        case SPELL_FELSOUL_CLEAVE:
        {
            DoCast(SPELL_FELSOUL_CLEAVE);
            events.Repeat(5s);
            break;
        }
        case SPELL_FRENZY:
        {
            DoCast(SPELL_FRENZY);
            events.Repeat(5s);
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && PhaseStatus == PHASE_00)
        {
            PhaseStatus = PHASE_01;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            GetTalkData(EVENT_ON_MOVEINLINEOFSIGHT);
        }
    }
    uint8 PhaseStatus;
    bool hp25;
    bool hp50;
    bool hp90;
};

void AddSC_boss_domatrax()
{
    RegisterCreatureAI(boss_domatrax);
}
