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
SDName: boss_cannon_master_willey
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

//front, left
#define ADD_1X 3553.851807
#define ADD_1Y -2945.885986
#define ADD_1Z 125.001015
#define ADD_1O 0.592007
//front, right
#define ADD_2X 3559.206299
#define ADD_2Y -2952.929932
#define ADD_2Z 125.001015
#define ADD_2O 0.592007
//mid, left
#define ADD_3X 3552.417480
#define ADD_3Y -2948.667236
#define ADD_3Z 125.001015
#define ADD_3O 0.592007
//mid, right
#define ADD_4X 3555.651855
#define ADD_4Y -2953.519043
#define ADD_4Z 125.001015
#define ADD_4O 0.592007
//back, left
#define ADD_5X 3547.927246
#define ADD_5Y -2950.977295
#define ADD_5Z 125.001015
#define ADD_5O 0.592007
//back, mid
#define ADD_6X 3553.094697
#define ADD_6Y -2952.123291
#define ADD_6Z 125.001015
#define ADD_6O 0.592007
//back, right
#define ADD_7X 3552.727539
#define ADD_7Y -2957.776123
#define ADD_7Z 125.001015
#define ADD_7O 0.592007
//behind, left
#define ADD_8X 3547.156250
#define ADD_8Y -2953.162354
#define ADD_8Z 125.001015
#define ADD_8O 0.592007
//behind, right
#define ADD_9X 3550.202148
#define ADD_9Y -2957.437744
#define ADD_9Z 125.001015
#define ADD_9O 0.592007

#define SPELL_KNOCKAWAY    10101
#define SPELL_PUMMEL    15615
#define SPELL_SHOOT    16496
//#define SPELL_SUMMONCRIMSONRIFLEMAN    17279

struct TRINITY_DLL_DECL boss_cannon_master_willeyAI : public ScriptedAI
{
    boss_cannon_master_willeyAI(Creature *c) : ScriptedAI(c) {}

    uint32 KnockAway_Timer;
    uint32 Pummel_Timer;
    uint32 Shoot_Timer;
    uint32 SummonRifleman_Timer;

    void Reset()
    {
        Shoot_Timer = 1000;
        Pummel_Timer = 7000;
        KnockAway_Timer = 11000;
        SummonRifleman_Timer = 15000;
    }

    void JustDied(Unit* Victim)
    {
        m_creature->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
        m_creature->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
        m_creature->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
        m_creature->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
        m_creature->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
        m_creature->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
        m_creature->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Pummel
        if (Pummel_Timer < diff)
        {
            //Cast
            if (rand()%100 < 90) //90% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_PUMMEL);
            }
            //12 seconds until we should cast this again
            Pummel_Timer = 12000;
        }else Pummel_Timer -= diff;

        //KnockAway
        if (KnockAway_Timer < diff)
        {
            //Cast
            if (rand()%100 < 80) //80% chance to cast
            {
                DoCast(m_creature->getVictim(),SPELL_KNOCKAWAY);
            }
            //14 seconds until we should cast this again
            KnockAway_Timer = 14000;
        }else KnockAway_Timer -= diff;

        //Shoot
        if (Shoot_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_SHOOT);
            //1 seconds until we should cast this again
            Shoot_Timer = 1000;
        }else Shoot_Timer -= diff;

        //SummonRifleman
        if (SummonRifleman_Timer < diff)
        {
            //Cast
            switch (rand()%9)
            {
            case 0:
                m_creature->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 1:
                m_creature->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 2:
                m_creature->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_6X,ADD_6Y,ADD_6Z,ADD_6O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 3:
                m_creature->SummonCreature(11054,ADD_4X,ADD_4Y,ADD_4Z,ADD_4O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 4:
                m_creature->SummonCreature(11054,ADD_5X,ADD_5Y,ADD_5Z,ADD_5O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_6X,ADD_6Y,ADD_6Z,ADD_6O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_8X,ADD_8Y,ADD_8Z,ADD_8O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 5:
                m_creature->SummonCreature(11054,ADD_6X,ADD_6Y,ADD_6Z,ADD_6O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 6:
                m_creature->SummonCreature(11054,ADD_7X,ADD_7Y,ADD_7Z,ADD_7O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_8X,ADD_8Y,ADD_8Z,ADD_8O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 7:
                m_creature->SummonCreature(11054,ADD_8X,ADD_8Y,ADD_8Z,ADD_8O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            case 8:
                m_creature->SummonCreature(11054,ADD_9X,ADD_9Y,ADD_9Z,ADD_9O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,240000);
                m_creature->SummonCreature(11054,ADD_3X,ADD_3Y,ADD_3Z,ADD_3O,TEMPSUMMON_TIMED_DESPAWN,240000);
                break;
            }
            //30 seconds until we should cast this again
            SummonRifleman_Timer = 30000;
        }else SummonRifleman_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_cannon_master_willey(Creature* pCreature)
{
    return new boss_cannon_master_willeyAI (pCreature);
}

void AddSC_boss_cannon_master_willey()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_cannon_master_willey";
    newscript->GetAI = &GetAI_boss_cannon_master_willey;
    newscript->RegisterSelf();
}

