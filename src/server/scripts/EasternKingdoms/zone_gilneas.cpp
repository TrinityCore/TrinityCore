/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

enum Quests
{
    // 1 - wargen attack
    LOCKDOWN                   = 14078
    // 2 - forsaken invasion

    // 3 - cataclism
};

enum Says
{
    // 1 - wargen attack

    // 2 - forsaken invasion

    // 3 - cataclism
};

enum Spells
{
    // 1 - wargen attack 
    SPELL_PHASE_2               = 59073      // good spell ?
    // 2 - forsaken invasion

    // 3 - cataclism
};

enum Events
{
    // 1 - wargen attack
    EVENT_NPC_PRINCE_LIAM_GREYMANE_1_SAY       = 1
    // 2 - forsaken invasion

    // 3 - cataclism
};

// 1 - wargen attack
/************************************ Phase 1 ************************************/
class npc_prince_liam_greymane_1 : public CreatureScript
{
public:
    npc_prince_liam_greymane_1() : CreatureScript("npc_prince_liam_greymane_1") {}

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_prince_liam_greymane_1AI (creature);
    }

    struct npc_prince_liam_greymane_1AI : public ScriptedAI
    {
        bool cantalk;
        int prince_liam_say;

        npc_prince_liam_greymane_1AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() OVERRIDE
        {
            cantalk = true;
            prince_liam_say = 0;
            events.ScheduleEvent(EVENT_NPC_PRINCE_LIAM_GREYMANE_1_SAY, 30000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent()) 
            {
                switch (eventId)
                {
                    case EVENT_NPC_PRINCE_LIAM_GREYMANE_1_SAY:
                        events.ScheduleEvent(EVENT_NPC_PRINCE_LIAM_GREYMANE_1_SAY, 30000);
                        if (prince_liam_say > 2) prince_liam_say = 0;
                        Talk(prince_liam_say);
                        ++prince_liam_say;
                        break;
                    default:
                        break;
                }
            } 
        }

    private:
        EventMap events;
    };
};
/*********************************************************************************/

void AddSC_gilneas()
{
    // 1 - wargen attack
    new npc_prince_liam_greymane_1();
    // 2 - forsaken invasion

    // 3 - cataclism
}
