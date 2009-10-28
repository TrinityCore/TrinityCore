/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
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
#include "naxxramas.h"

#define SPELL_WEB_WRAP          28622
#define SPELL_WEB_SPRAY         HEROIC(29484,54125)
#define SPELL_POISON_SHOCK      HEROIC(28741,54122)
#define SPELL_NECROTIC_POISON   HEROIC(54121,28776)
#define SPELL_FRENZY            HEROIC(54123,54124)

#define MOB_WEB_WRAP            16486
#define MOB_SPIDERLING          17055

#define MAX_POS_WRAP            3
const float PosWrap[MAX_POS_WRAP][3] =
{
    {3546.796, -3869.082, 296.450+20},
    {3531.271, -3847.424, 299.450+20},
    {3497.067, -3843.384, 302.384+20},
};

enum Events
{
    EVENT_SPRAY = 1,
    EVENT_SHOCK,
    EVENT_POISON,
    EVENT_WRAP,
    EVENT_SUMMON,
};

struct TRINITY_DLL_DECL boss_maexxnaAI : public BossAI
{
    boss_maexxnaAI(Creature *c) : BossAI(c, BOSS_MAEXXNA) {}

    bool enraged;

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        enraged = false;
        events.ScheduleEvent(EVENT_WRAP, 20000);
        events.ScheduleEvent(EVENT_SPRAY, 40000);
        events.ScheduleEvent(EVENT_SHOCK, 10000);
        events.ScheduleEvent(EVENT_POISON, 5000);
        events.ScheduleEvent(EVENT_SUMMON, 40000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_WRAP:
                    for (uint32 i = 0; i < HEROIC(1,2); ++i)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0, true, -SPELL_WEB_WRAP))
                        {
                            pTarget->RemoveAura(SPELL_WEB_SPRAY);
                            uint32 pos = rand()%MAX_POS_WRAP;
                            pTarget->GetMotionMaster()->MoveJump(PosWrap[pos][0], PosWrap[pos][1], PosWrap[pos][2], 20, 20);
                            if (Creature *wrap = DoSummon(MOB_WEB_WRAP, pTarget, 0, 60000))
                            {
                                wrap->AI()->SetGUID(pTarget->GetGUID());
                                wrap->GetMotionMaster()->MoveJump(PosWrap[pos][0], PosWrap[pos][1], PosWrap[pos][2], 20, 20);
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_WRAP, 40000);
                    return;
                case EVENT_SPRAY:
                    DoCastAOE(SPELL_WEB_SPRAY);
                    events.ScheduleEvent(EVENT_SPRAY, 40000);
                    return;
                case EVENT_SHOCK:
                    DoCastAOE(SPELL_POISON_SHOCK);
                    events.ScheduleEvent(EVENT_SHOCK, 10000);
                    return;
                case EVENT_POISON:
                    DoCast(me->getVictim(), SPELL_NECROTIC_POISON);
                    events.ScheduleEvent(EVENT_POISON, 30000);
                    return;
                case EVENT_SUMMON:
                {
                    uint32 amount = 8+rand()%2;
                    for (uint32 i = 0; i < amount; ++i)
                        DoSummon(MOB_SPIDERLING, me);
                    events.ScheduleEvent(EVENT_SUMMON, 40000);
                    break;
                }
            }
        }

        if (!enraged && HealthBelowPct(30))
        {
            DoCast(me, SPELL_FRENZY);
            enraged = true;
        }
        else
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_maexxna(Creature* pCreature)
{
    return new boss_maexxnaAI (pCreature);
}

void AddSC_boss_maexxna()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_maexxna";
    newscript->GetAI = &GetAI_boss_maexxna;
    newscript->RegisterSelf();
}

