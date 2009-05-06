/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Heigan
SD%Complete: 0
SDComment: Place Holder
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"
#include "def_naxxramas.h"

#define SAY_AGGRO           RAND(-1533109,-1533110,-1533111)
#define SAY_SLAY            -1533112
#define SAY_TAUNT           RAND(-1533113,-1533114,-1533115,-1533116,-1533117)
#define SAY_DEATH           -1533118

//Spells by boss
#define SPELL_WILT          23772
#define SPELL_FEAVER        29998

#define SPELL_SPELL_DISRUPTION  29310
#define SPELL_DECREPIT_FEVER    HEROIC(29998,55011)
#define SPELL_PLAGUE_CLOUD      30122

enum Events
{
    EVENT_DISRUPT   = 1,
    EVENT_FEVER,
    EVENT_CLOUD,
    EVENT_ERUPT,
};

//Spell by eye stalks
#define SPELL_MIND_FLAY     26143

struct TRINITY_DLL_DECL boss_heiganAI : public ScriptedAI
{
    boss_heiganAI(Creature *c) : ScriptedAI(c)
    {
        instance = ((ScriptedInstance*)c->GetInstanceData());
    }

    EventMap events;
    ScriptedInstance *instance;

    void Reset()
    {
        events.Reset();
        instance->SetBossState(BOSS_HEIGAN, NOT_STARTED);
    }

    void KilledUnit(Unit* Victim)
    {
        if(!(rand()%5))
            DoScriptText(SAY_SLAY, me);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, me);
        instance->SetBossState(BOSS_HEIGAN, DONE);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, me);
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_FEVER, 1200);
        events.ScheduleEvent(EVENT_CLOUD, 360000);
        events.ScheduleEvent(EVENT_ERUPT, 3000);
        instance->SetBossState(BOSS_HEIGAN, IN_PROGRESS);
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
                case EVENT_DISRUPT:
                    events.ScheduleEvent(EVENT_DISRUPT, 1200);
                    return;
                case EVENT_FEVER:
                    events.ScheduleEvent(EVENT_FEVER, 2000);
                    return;
                case EVENT_CLOUD:
                    events.ScheduleEvent(EVENT_CLOUD, 2000);
                    return;
                case EVENT_ERUPT:
                    if(instance)
                    {
                        uint32 section = rand()%4;
                        instance->SetData(DATA_HEIGAN_ERUPT, section);
                    }
                    events.ScheduleEvent(EVENT_ERUPT, 2000);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_heigan(Creature *_Creature)
{
    return new boss_heiganAI (_Creature);
}

void AddSC_boss_heigan()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_heigan";
    newscript->GetAI = &GetAI_boss_heigan;
    newscript->RegisterSelf();
}
