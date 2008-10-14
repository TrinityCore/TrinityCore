/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SD%Complete: 100
SDComment: Some issues with hateful strike inturrupting the melee swing timer. Probably core issue.
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO1      "Patchwerk want to play!"
#define SAY_AGGRO2      "Kel'Thuzad make Patchwerk his Avatar of War!"
#define SAY_SLAY        "No more play?"
#define SAY_DEATH       "What happened to... Patch..."

#define SOUND_AGGRO1    8909
#define SOUND_AGGRO2    8910
#define SOUND_SLAY      8912
#define SOUND_DEATH     8911

#define EMOTE_BERSERK   "Patchwerk goes into a berserker rage!"
#define EMOTE_ENRAGE    "Patchwerk becomes enraged!"

#define SPELL_HATEFULSTRIKE     28308
#define SPELL_ENRAGE            29691
#define SPELL_BERSERK           27680
#define SPELL_SLIMEBOLT         32309

struct TRINITY_DLL_DECL boss_patchwerkAI : public ScriptedAI
{
    boss_patchwerkAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 HatefullStrike_Timer;
    uint32 Enrage_Timer;
    uint32 Slimebolt_Timer;
    bool Enraged;

    void Reset()
    {
        HatefullStrike_Timer = 1200;                        //1.2 seconds
        Enrage_Timer = 420000;                              //7 minutes 420,000
        Slimebolt_Timer = 450000;                           //7.5 minutes 450,000
        Enraged = false;
    }

    void KilledUnit(Unit* Victim)
    {
        if (rand()%5)
            return;

        DoYell(SAY_SLAY, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_SLAY);
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
        if (rand()%2)
        {
            DoYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_AGGRO1);
        }
        else
        {
            DoYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_AGGRO2);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //HatefullStrike_Timer
        if (HatefullStrike_Timer < diff)
        {
            //Cast Hateful strike on the player with the highest
            //amount of HP within melee distance
            uint32 MostHP = 0;
            Unit* pMostHPTarget = NULL;
            Unit* pTemp = NULL;
            std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();

            for (i = m_creature->getThreatManager().getThreatList().begin(); i!=m_creature->getThreatManager().getThreatList().end(); ++i)
            {
                pTemp = Unit::GetUnit((*m_creature),(*i)->getUnitGuid());
                if (pTemp && pTemp->isAlive() && pTemp->GetHealth() > MostHP && m_creature->GetDistance2d(pTemp) < 5)
                {
                    MostHP = pTemp->GetHealth();
                    pMostHPTarget = pTemp;
                }
            }

            if (pMostHPTarget)
                DoCast(pMostHPTarget, SPELL_HATEFULSTRIKE);

            HatefullStrike_Timer = 1200;
        }else HatefullStrike_Timer -= diff;

        //Enrage_Timer
        if (Enrage_Timer < diff)
        {
            DoCast(m_creature, SPELL_BERSERK);
            DoTextEmote(EMOTE_BERSERK, m_creature->getVictim());

            Enrage_Timer = 300000;
        }else Enrage_Timer -= diff;

        //Slimebolt_Timer
        if (Slimebolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SLIMEBOLT);
            Slimebolt_Timer = 5000;
        }else Slimebolt_Timer -= diff;

        //Enrage if not already enraged and below 5%
        if (!Enraged && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 5)
        {
            DoCast(m_creature,SPELL_ENRAGE);
            DoTextEmote(EMOTE_ENRAGE,NULL);
            Enraged = true;
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
    newscript->GetAI = GetAI_boss_patchwerk;
    m_scripts[nrscripts++] = newscript;
}
