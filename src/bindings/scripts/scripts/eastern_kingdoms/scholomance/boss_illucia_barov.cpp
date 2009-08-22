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
SDName: Boss_Illucia_Barov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"
#include "def_scholomance.h"

#define SPELL_CURSEOFAGONY      18671
#define SPELL_SHADOWSHOCK       20603
#define SPELL_SILENCE           15487
#define SPELL_FEAR              6215

struct TRINITY_DLL_DECL boss_illuciabarovAI : public ScriptedAI
{
    boss_illuciabarovAI(Creature *c) : ScriptedAI(c) {}

    uint32 CurseOfAgony_Timer;
    uint32 ShadowShock_Timer;
    uint32 Silence_Timer;
    uint32 Fear_Timer;

    void Reset()
    {
        CurseOfAgony_Timer = 18000;
        ShadowShock_Timer = 9000;
        Silence_Timer = 5000;
        Fear_Timer = 30000;
    }

    void JustDied(Unit *killer)
    {
        ScriptedInstance *pInstance = m_creature->GetInstanceData();
        if (pInstance)
        {
            pInstance->SetData(DATA_LADYILLUCIABAROV_DEATH, 0);

            if (pInstance->GetData(TYPE_GANDLING) == IN_PROGRESS)
                m_creature->SummonCreature(1853, 180.73, -9.43856, 75.507, 1.61399, TEMPSUMMON_DEAD_DESPAWN, 0);
        }
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //CurseOfAgony_Timer
        if (CurseOfAgony_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CURSEOFAGONY);
            CurseOfAgony_Timer = 30000;
        }else CurseOfAgony_Timer -= diff;

        //ShadowShock_Timer
        if (ShadowShock_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_SHADOWSHOCK);

            ShadowShock_Timer = 12000;
        }else ShadowShock_Timer -= diff;

        //Silence_Timer
        if (Silence_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SILENCE);
            Silence_Timer = 14000;
        }else Silence_Timer -= diff;

        //Fear_Timer
        if (Fear_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FEAR);
            Fear_Timer = 30000;
        }else Fear_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_illuciabarov(Creature* pCreature)
{
    return new boss_illuciabarovAI (pCreature);
}

void AddSC_boss_illuciabarov()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_illucia_barov";
    newscript->GetAI = &GetAI_boss_illuciabarov;
    newscript->RegisterSelf();
}

