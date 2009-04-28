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
SDName: Boss_Luetenant_Drake
SD%Complete: 70
SDComment: Missing proper code for patrolling area after being spawned. Script for GO (barrels) quest 10283
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "precompiled.h"
#include "def_old_hillsbrad.h"
#include "../../../npc/npc_escortAI.h"

/*######
## go_barrel_old_hillsbrad
######*/

bool GOHello_go_barrel_old_hillsbrad(Player *player, GameObject* _GO)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)_GO->GetInstanceData();

    if (!pInstance)
        return false;

    if (pInstance->GetData(TYPE_BARREL_DIVERSION) == DONE)
        return false;

    pInstance->SetData(TYPE_BARREL_DIVERSION, IN_PROGRESS);

    return false;
}

/*######
## boss_lieutenant_drake
######*/

#define SAY_ENTER               -1560006
#define SAY_AGGRO               -1560007
#define SAY_SLAY1               -1560008
#define SAY_SLAY2               -1560009
#define SAY_MORTAL              -1560010
#define SAY_SHOUT               -1560011
#define SAY_DEATH               -1560012

#define SPELL_WHIRLWIND         31909
#define SPELL_HAMSTRING         9080
#define SPELL_MORTAL_STRIKE     31911
#define SPELL_FRIGHTENING_SHOUT 33789

struct Location
{
    uint32 wpId;
    float x;
    float y;
    float z;
};

static Location DrakeWP[]=
{
    {0, 2125.84, 88.2535, 54.8830},
    {1, 2111.01, 93.8022, 52.6356},
    {2, 2106.70, 114.753, 53.1965},
    {3, 2107.76, 138.746, 52.5109},
    {4, 2114.83, 160.142, 52.4738},
    {5, 2125.24, 178.909, 52.7283},
    {6, 2151.02, 208.901, 53.1551},
    {7, 2177.00, 233.069, 52.4409},
    {8, 2190.71, 227.831, 53.2742},
    {9, 2178.14, 214.219, 53.0779},
    {10, 2154.99, 202.795, 52.6446},
    {11, 2132.00, 191.834, 52.5709},
    {12, 2117.59, 166.708, 52.7686},
    {13, 2093.61, 139.441, 52.7616},
    {14, 2086.29, 104.950, 52.9246},
    {15, 2094.23, 81.2788, 52.6946},
    {16, 2108.70, 85.3075, 53.3294},
    {17, 2125.50, 88.9481, 54.7953},
    {18, 2128.20, 70.9763, 64.4221}
};

struct TRINITY_DLL_DECL boss_lieutenant_drakeAI : public ScriptedAI
{
    boss_lieutenant_drakeAI(Creature *c) : ScriptedAI(c) {}

    bool CanPatrol;
    uint32 wpId;

    uint32 Whirlwind_Timer;
    uint32 Fear_Timer;
    uint32 MortalStrike_Timer;
    uint32 ExplodingShout_Timer;

    void Reset()
    {
        CanPatrol = true;
        wpId = 0;

        Whirlwind_Timer = 20000;
        Fear_Timer = 30000;
        MortalStrike_Timer = 45000;
        ExplodingShout_Timer = 25000;
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        //TODO: make this work
        if (CanPatrol && wpId == 0)
        {
            m_creature->GetMotionMaster()->MovePoint(DrakeWP[0].wpId, DrakeWP[0].x, DrakeWP[0].y, DrakeWP[0].z);
            wpId++;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Whirlwind
        if (Whirlwind_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_WHIRLWIND);
            Whirlwind_Timer = 20000+rand()%5000;
        }else Whirlwind_Timer -= diff;

        //Fear
        if (Fear_Timer < diff)
        {
            DoScriptText(SAY_SHOUT, m_creature);
            DoCast(m_creature->getVictim(), SPELL_FRIGHTENING_SHOUT);
            Fear_Timer = 25000+rand()%10000;
        }else Fear_Timer -= diff;

        //Mortal Strike
        if (MortalStrike_Timer < diff)
        {
            DoScriptText(SAY_MORTAL, m_creature);
            DoCast(m_creature->getVictim(), SPELL_MORTAL_STRIKE);
            MortalStrike_Timer = 20000+rand()%10000;
        }else MortalStrike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_lieutenant_drake(Creature *_Creature)
{
    return new boss_lieutenant_drakeAI (_Creature);
}

void AddSC_boss_lieutenant_drake()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="go_barrel_old_hillsbrad";
    newscript->pGOHello = &GOHello_go_barrel_old_hillsbrad;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_lieutenant_drake";
    newscript->GetAI = &GetAI_boss_lieutenant_drake;
    newscript->RegisterSelf();
}

