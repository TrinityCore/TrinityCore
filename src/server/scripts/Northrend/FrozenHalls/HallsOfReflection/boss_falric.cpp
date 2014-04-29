/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "halls_of_reflection.h"

enum Texts
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_IMPENDING_DESPAIR                         = 3,
    SAY_DEFILING_HORROR                           = 4,
};

enum Spells
{
    SPELL_QUIVERING_STRIKE                        = 72422,
    SPELL_IMPENDING_DESPAIR                       = 72426,
    SPELL_DEFILING_HORROR                         = 72435,
    SPELL_HOPELESSNESS                            = 72395,
    H_SPELL_HOPELESSNESS                          = 72390, /// @todo not in dbc. Add in DB.
};

enum Events
{
    EVENT_NONE,
    EVENT_QUIVERING_STRIKE,
    EVENT_IMPENDING_DESPAIR,
    EVENT_DEFILING_HORROR,
};

class boss_falric : public CreatureScript
{
public:
    boss_falric() : CreatureScript("boss_falric") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_falricAI>(creature);
    }

    struct boss_falricAI : public boss_horAI
    {
        boss_falricAI(Creature* creature) : boss_horAI(creature) { }

        uint8 uiHopelessnessCount;

        void Reset() override
        {
            boss_horAI::Reset();

            uiHopelessnessCount = 0;

            instance->SetBossState(DATA_FALRIC_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_FALRIC_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_QUIVERING_STRIKE, 23000);
            events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 9000);
            events.ScheduleEvent(EVENT_DEFILING_HORROR, urand(25000, 45000)); /// @todo adjust timer.
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetBossState(DATA_FALRIC_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff) override
        {
            // Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_QUIVERING_STRIKE:
                    DoCast(SPELL_QUIVERING_STRIKE);
                    events.ScheduleEvent(EVENT_QUIVERING_STRIKE, 10000);
                    break;
                case EVENT_IMPENDING_DESPAIR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        Talk(SAY_IMPENDING_DESPAIR);
                        DoCast(target, SPELL_IMPENDING_DESPAIR);
                    }
                    events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 13000);
                    break;
                case EVENT_DEFILING_HORROR:
                    DoCast(SPELL_DEFILING_HORROR);
                    events.ScheduleEvent(EVENT_DEFILING_HORROR, urand(25000, 45000)); /// @todo adjust timer.
                    break;
            }

            if ((uiHopelessnessCount < 1 && HealthBelowPct(66))
                || (uiHopelessnessCount < 2 && HealthBelowPct(33))
                || (uiHopelessnessCount < 3 && HealthBelowPct(10)))
            {
                uiHopelessnessCount++;
                DoCast(DUNGEON_MODE(SPELL_HOPELESSNESS, H_SPELL_HOPELESSNESS));
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_falric()
{
    new boss_falric();
}
