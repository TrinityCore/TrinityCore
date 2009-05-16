/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "precompiled.h"
#include "def_naxxramas.h"

#define SPELL_MORTAL_WOUND      25646
#define SPELL_ENRAGE            HEROIC(28371,54427)
#define SPELL_DECIMATE          HEROIC(28374,54426)
#define SPELL_BERSERK           26662
#define SPELL_INFECTED_WOUND    29306

#define MOB_ZOMBIE

#define ADD_1X 3269.590
#define ADD_1Y -3161.287
#define ADD_1Z 297.423

#define ADD_2X 3277.797
#define ADD_2Y -3170.352
#define ADD_2Z 297.423

#define ADD_3X 3267.049
#define ADD_3Y -3172.820
#define ADD_3Z 297.423

#define ADD_4X 3252.157
#define ADD_4Y -3132.135
#define ADD_4Z 297.423

#define ADD_5X 3259.990
#define ADD_5Y -3126.590
#define ADD_5Z 297.423

#define ADD_6X 3259.815
#define ADD_6Y -3137.576
#define ADD_6Z 297.423

#define ADD_7X 3308.030
#define ADD_7Y -3132.135
#define ADD_7Z 297.423

#define ADD_8X 3303.046
#define ADD_8Y -3180.682
#define ADD_8Z 297.423

#define ADD_9X 3313.283
#define ADD_9Y -3180.766
#define ADD_9Z 297.423

enum Events
{
    EVENT_WOUND = 1,
    EVENT_ENRAGE,
    EVENT_DECIMATE,
    EVENT_BERSERK,
    EVENT_SUMMON,
};

struct TRINITY_DLL_DECL boss_gluthAI : public BossAI
{
    boss_gluthAI(Creature *c) : BossAI(c, BOSS_GLUTH)
    {
        // Do not let Gluth be affected by zombies' debuff
        me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true);
    }

    void MoveInLineOfSight(Unit *who)
    {
        /*if(who->GetEntry() == MOB_ZOMBIE)
        {
            me->AddThreat(who, 1000000
        }
        else
            BossAI::MoveInLineOfSight(who);*/
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_WOUND, 10000);
        events.ScheduleEvent(EVENT_ENRAGE, 30000);
        events.ScheduleEvent(EVENT_DECIMATE, 105000);
        events.ScheduleEvent(EVENT_BERSERK, 8*60000);
        events.ScheduleEvent(EVENT_SUMMON, 10000);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_WOUND:
                    DoCast(me->getVictim(), SPELL_MORTAL_WOUND);
                    events.ScheduleEvent(EVENT_WOUND, 10000);
                    return;
                case EVENT_ENRAGE:
                    DoCast(me, SPELL_ENRAGE);
                    events.ScheduleEvent(EVENT_ENRAGE, 30000);
                    return;
                case EVENT_DECIMATE:
                    DoCastAOE(SPELL_DECIMATE);
                    events.ScheduleEvent(EVENT_DECIMATE, 105000);
                    return;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    return;
                case EVENT_SUMMON:
                    for(uint32 i = 0; i < HEROIC(1,2); ++i)
                    //SummonZombie(HEROIC(1,2));
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gluth(Creature *_Creature)
{
    return new boss_gluthAI (_Creature);
}

void AddSC_boss_gluth()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_gluth";
    newscript->GetAI = &GetAI_boss_gluth;
    newscript->RegisterSelf();
}

