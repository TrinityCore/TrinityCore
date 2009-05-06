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
SDName: Boss_Patchwerk
SD%Complete: 80
SDComment: Some issues with hateful strike inturrupting the melee swing timer.
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO               RAND(-1533017,-1533018)
#define SAY_SLAY                -1533019
#define SAY_DEATH               -1533020

#define EMOTE_BERSERK           -1533021
#define EMOTE_ENRAGE            -1533022

#define SPELL_HATEFULSTRIKE     HEROIC(41926,59192)
#define SPELL_FRENZY            28131
#define SPELL_BERSERK           26662
#define SPELL_SLIMEBOLT         32309

#define EVENT_BERSERK   1
#define EVENT_HATEFUL   2
#define EVENT_SLIME     3

struct TRINITY_DLL_DECL boss_patchwerkAI : public ScriptedAI
{
    boss_patchwerkAI(Creature *c) : ScriptedAI(c) {}

    bool Enraged;
    EventMap events;

    void Reset()
    {
        events.Reset();
        Enraged = false;
    }

    void KilledUnit(Unit* Victim)
    {
        if(!(rand()%5))
            DoScriptText(SAY_SLAY, me);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, me);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, me);
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_HATEFUL, 1200);
        events.ScheduleEvent(EVENT_BERSERK, 360000);
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
                case EVENT_HATEFUL:
                {
                    //Cast Hateful strike on the player with the highest
                    //amount of HP within melee distance
                    uint32 MostHP = 0;
                    Unit* pMostHPTarget = NULL;
                    std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
                    for(; i != m_creature->getThreatManager().getThreatList().end();)
                    {
                        Unit* pTemp = Unit::GetUnit(*m_creature, (*i)->getUnitGuid());
                        ++i;
                        if (pTemp && pTemp->isAlive() && pTemp->GetHealth() > MostHP && m_creature->IsWithinMeleeRange(pTemp))
                        {
                            MostHP = pTemp->GetHealth();
                            pMostHPTarget = pTemp;
                        }
                    }

                    if (pMostHPTarget)
                        DoCast(pMostHPTarget, SPELL_HATEFULSTRIKE, true);

                    events.ScheduleEvent(EVENT_HATEFUL, 1200);
                    return;
                }
                case EVENT_BERSERK:
                    DoCast(m_creature, SPELL_BERSERK);
                    DoScriptText(EMOTE_BERSERK, m_creature);
                    events.ScheduleEvent(EVENT_SLIME, 2000);
                    return;
                case EVENT_SLIME:
                    DoCast(m_creature->getVictim(), SPELL_SLIMEBOLT);
                    events.ScheduleEvent(EVENT_SLIME, 2000);
                    return;
            }
        }

        if(!Enraged && HealthBelowPct(5))
        {
            DoCast(m_creature, SPELL_FRENZY);
            DoScriptText(EMOTE_ENRAGE, NULL);
            Enraged = true;
            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_patchwerk(Creature *_Creature)
{
    return new boss_patchwerkAI (_Creature);
}

void AddSC_boss_patchwerk()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_patchwerk";
    newscript->GetAI = &GetAI_boss_patchwerk;
    newscript->RegisterSelf();
}
