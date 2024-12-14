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

enum Yells
{
    YELL_AGGRO                                    = 0,
    YELL_EVADE                                    = 1,
  //YELL_RESPAWN1                                 = -1810010, // Missing in database
  //YELL_RESPAWN2                                 = -1810011, // Missing in database
    YELL_RANDOM                                   = 2,
    YELL_SPELL                                    = 3,
};

enum Spells
{
    SPELL_AVATAR                                  = 19135,
    SPELL_THUNDERCLAP                             = 15588,
    SPELL_STORMBOLT                               = 20685 // not sure
};

struct boss_vanndar : public ScriptedAI
{
    boss_vanndar(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .Schedule(3s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_AVATAR);
                task.Repeat(15s, 20s);
            })
            .Schedule(4s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_THUNDERCLAP);
                task.Repeat(5s, 15s);
            })
            .Schedule(6s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_STORMBOLT);
                task.Repeat(10s, 25s);
            })
            .Schedule(20s, 30s, [this](TaskContext task)
            {
                Talk(YELL_RANDOM);
                task.Repeat(20s, 30s);
            })
            .Schedule(5s, [this](TaskContext task)
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                {
                    EnterEvadeMode();
                    Talk(YELL_EVADE);
                }
                task.Repeat();
            });

        Talk(YELL_AGGRO);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_vanndar()
{
    RegisterCreatureAI(boss_vanndar);
}
