/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Boss_Interrogator_Vishas
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"
#include "def_scarlet_monastery.h"

#define SAY_AGGRO                       -1189011
#define SAY_HEALTH1                     -1189012
#define SAY_HEALTH2                     -1189013
#define SAY_KILL                        -1189014
#define SAY_TRIGGER_VORREL              -1189015

#define SPELL_POWERWORDSHIELD           2767

struct TRINITY_DLL_DECL boss_interrogator_vishasAI : public ScriptedAI
{
    boss_interrogator_vishasAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = (ScriptedInstance*)m_creature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* pInstance;

    bool Yell30;
    bool Yell60;
    uint32 PowerWordShield_Timer;

    void Reset()
    {
        PowerWordShield_Timer = 60000;
    }

    void Aggro(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void KilledUnit(Unit* Victim)
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void JustDied(Unit* Killer)
    {
        if (!pInstance)
            return;

        //Any other actions to do with vorrel? setStandState?
        if (Unit *vorrel = Unit::GetUnit(*m_creature,pInstance->GetData64(DATA_VORREL)))
            DoScriptText(SAY_TRIGGER_VORREL, vorrel);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are low on hp Do sayings
        if (!Yell60 && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() <= 60))
        {
            DoScriptText(SAY_HEALTH1, m_creature);
            Yell60 = true;
        }

        if (!Yell30 && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() <= 30))
        {
            DoScriptText(SAY_HEALTH2, m_creature);
            Yell30 = true;
        }

        //PowerWordShield_Timer
        if (PowerWordShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_POWERWORDSHIELD);
            PowerWordShield_Timer = 60000;
        }else PowerWordShield_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_interrogator_vishas(Creature *_Creature)
{
    return new boss_interrogator_vishasAI (_Creature);
}

void AddSC_boss_interrogator_vishas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_interrogator_vishas";
    newscript->GetAI = &GetAI_boss_interrogator_vishas;
    newscript->RegisterSelf();
}

