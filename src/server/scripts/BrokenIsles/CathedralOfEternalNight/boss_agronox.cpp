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
    SPELL_FULMINATING_LASHERS = 236527,
    SPELL_POISONOUS_SPORES = 236524,
    SPELL_TIMBER_SMASH = 235751,
    SPELL_SUCCULENT_LASHERS = 236639,//Mythic
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_ENTERCOMBAT,                 EVENT_TYPE_TALK,            0 },
    { EVENT_ON_KILLEDUNIT,                  EVENT_TYPE_TALK,            2 },
    { EVENT_ON_JUSTDIED,                    EVENT_TYPE_TALK,            3 },
};

std::vector<EventData> const eventData =
{
    { PHASE_01, PHASE_01, SPELL_FULMINATING_LASHERS,    5000 },
    { PHASE_01, PHASE_01, SPELL_POISONOUS_SPORES,       5000 },
    { PHASE_01, PHASE_01, SPELL_TIMBER_SMASH,           5000 },
    { PHASE_01, PHASE_01, SPELL_SUCCULENT_LASHERS,      5000 },
};

struct boss_agronox : public BossAI
{
    boss_agronox(Creature* creature) : BossAI(creature, DATA_AGRONOX) { Initialize(); }

    void Initialize()
    {
        PhaseStatus = PHASE_00;
        //SetDungeonEncounterID(2055);
        LoadEventData(&eventData);
        LoadTalkData(&talkData);
    }

    void ScheduleTasks() override
    {
        GetEventData(PHASE_01);
    }

    void ExecuteEvent(uint32 eventId) override
    {

        switch (eventId)
        {
            case SPELL_FULMINATING_LASHERS:
            {
                DoCast(SPELL_FULMINATING_LASHERS);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_POISONOUS_SPORES:
            {
                DoCast(SPELL_POISONOUS_SPORES);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_TIMBER_SMASH:
            {
                DoCast(SPELL_TIMBER_SMASH);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_SUCCULENT_LASHERS:
            {
                if (IsMythic())
                    DoCast(SPELL_SUCCULENT_LASHERS);
                events.Repeat(5s, 10s);
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
            //events.ScheduleEvent(EVENT_INTRO, 1s, PHASE_NORMAL);
        }
    }
    uint8 PhaseStatus;
};

void AddSC_boss_agronox()
{
    RegisterCreatureAI(boss_agronox);
}
