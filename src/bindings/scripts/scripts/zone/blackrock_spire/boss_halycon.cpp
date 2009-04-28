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
SDName: Boss_Halycon
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "precompiled.h"

#define SPELL_CROWDPUMMEL       10887
#define SPELL_MIGHTYBLOW        14099

#define ADD_1X                  -169.839203
#define ADD_1Y                  -324.961395
#define ADD_1Z                  64.401443
#define ADD_1O                  3.124724

struct TRINITY_DLL_DECL boss_halyconAI : public ScriptedAI
{
    boss_halyconAI(Creature *c) : ScriptedAI(c) {}

    uint32 CrowdPummel_Timer;
    uint32 MightyBlow_Timer;
    bool Summoned;

    void Reset()
    {
        CrowdPummel_Timer = 8000;
        MightyBlow_Timer = 14000;
        Summoned = false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;

        //CrowdPummel_Timer
        if (CrowdPummel_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CROWDPUMMEL);
            CrowdPummel_Timer = 14000;
        }else CrowdPummel_Timer -= diff;

        //MightyBlow_Timer
        if (MightyBlow_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MIGHTYBLOW);
            MightyBlow_Timer = 10000;
        }else MightyBlow_Timer -= diff;

        //Summon Gizrul
        if ( !Summoned && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 25 )
        {
            m_creature->SummonCreature(10268,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,300000);
            Summoned = true;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_halycon(Creature *_Creature)
{
    return new boss_halyconAI (_Creature);
}

void AddSC_boss_halycon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_halycon";
    newscript->GetAI = &GetAI_boss_halycon;
    newscript->RegisterSelf();
}

