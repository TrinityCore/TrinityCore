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
#include "naxxramas.h"

#define SAY_AGGRO           RAND(-1533109,-1533110,-1533111)
#define SAY_SLAY            -1533112
#define SAY_TAUNT           RAND(-1533113,-1533114,-1533115,-1533116,-1533117)
#define SAY_DEATH           -1533118

#define SPELL_SPELL_DISRUPTION  29310
#define SPELL_DECREPIT_FEVER    HEROIC(29998,55011)
#define SPELL_PLAGUE_CLOUD      29350

enum Events
{
    EVENT_DISRUPT   = 1,
    EVENT_FEVER,
    EVENT_ERUPT,
    EVENT_PHASE,
};

enum Phases
{
    PHASE_FIGHT = 1,
    PHASE_DANCE,
};

//Spell by eye stalks
#define SPELL_MIND_FLAY     26143

struct TRINITY_DLL_DECL boss_heiganAI : public BossAI
{
    boss_heiganAI(Creature *c) : BossAI(c, BOSS_HEIGAN) {}

    uint32 eruptSection;
    bool eruptDirection;
    Phases phase;

    void KilledUnit(Unit* Victim)
    {
        if (!(rand()%5))
            DoScriptText(SAY_SLAY, me);
    }

    void JustDied(Unit* Killer)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        DoScriptText(SAY_AGGRO, me);
        EnterPhase(PHASE_FIGHT);
    }

    void EnterPhase(Phases newPhase)
    {
        phase = newPhase;
        events.Reset();
        eruptSection = 3;
        if (phase == PHASE_FIGHT)
        {
            events.ScheduleEvent(EVENT_DISRUPT, 0);
            events.ScheduleEvent(EVENT_FEVER, 20000);
            events.ScheduleEvent(EVENT_PHASE, 85000);
            events.ScheduleEvent(EVENT_ERUPT, 10000);
        }
        else
        {
            float x, y, z, o;
            me->GetHomePosition(x, y, z, o);
            me->NearTeleportTo(x, y, z, o);
            DoCastAOE(SPELL_PLAGUE_CLOUD);
            events.ScheduleEvent(EVENT_PHASE, 45000);
            events.ScheduleEvent(EVENT_ERUPT, 5000);
        }
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
                case EVENT_DISRUPT:
                    DoCastAOE(SPELL_SPELL_DISRUPTION);
                    events.ScheduleEvent(EVENT_DISRUPT, 5000);
                    return;
                case EVENT_FEVER:
                    DoCastAOE(SPELL_DECREPIT_FEVER);
                    events.ScheduleEvent(EVENT_FEVER, 20000);
                    return;
                case EVENT_PHASE:
                    EnterPhase(phase == PHASE_FIGHT ? PHASE_DANCE : PHASE_FIGHT);
                    return;
                case EVENT_ERUPT:
                    instance->SetData(DATA_HEIGAN_ERUPT, eruptSection);
                    TeleportCheaters();

                    if (eruptSection == 0)
                        eruptDirection = true;
                    else if (eruptSection == 3)
                        eruptDirection = false;

                    eruptDirection ? ++eruptSection : --eruptSection;

                    events.ScheduleEvent(EVENT_ERUPT, phase == PHASE_FIGHT ? 10000 : 3000);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_heigan(Creature* pCreature)
{
    return new boss_heiganAI (pCreature);
}

void AddSC_boss_heigan()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_heigan";
    newscript->GetAI = &GetAI_boss_heigan;
    newscript->RegisterSelf();
}
