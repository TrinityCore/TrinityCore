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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "naxxramas.h"

enum NaxxEvents
{
    EVENT_SUMMON_FROGGER_WAVE = 1
};

struct npc_frogger_trigger_naxx : public ScriptedAI
{
    npc_frogger_trigger_naxx(Creature* creature) : ScriptedAI(creature), _nextFroggerWave(0) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_SUMMON_FROGGER_WAVE, 1s);
        _nextFroggerWave = 0;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_FROGGER_WAVE:
                {
                    std::list<TempSummon*> spawns;
                    me->SummonCreatureGroup(_nextFroggerWave, &spawns);
                    if (!spawns.empty())
                        spawns.front()->GetMotionMaster()->MovePath(10 * NPC_FROGGER + _nextFroggerWave, false);
                    _events.Repeat(1666ms);
                    _nextFroggerWave = (_nextFroggerWave+1) % 3;
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    uint8 _nextFroggerWave;
};

void AddSC_naxxramas()
{
    RegisterNaxxramasCreatureAI(npc_frogger_trigger_naxx);
}
