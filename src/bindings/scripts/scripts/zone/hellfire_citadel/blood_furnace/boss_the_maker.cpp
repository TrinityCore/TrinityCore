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
SDName: Boss_The_Maker
SD%Complete: 80
SDComment: Mind control no support
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "precompiled.h"
#include "def_blood_furnace.h"

#define SAY_AGGRO_1                 -1542009
#define SAY_AGGRO_2                 -1542010
#define SAY_AGGRO_3                 -1542011
#define SAY_KILL_1                  -1542012
#define SAY_KILL_2                  -1542013
#define SAY_DIE                     -1542014

#define SPELL_ACID_SPRAY            38153                   // heroic 38973 ??? 38153
#define SPELL_EXPLODING_BREAKER     30925
#define SPELL_KNOCKDOWN             20276
#define SPELL_DOMINATION            25772                   // ???

struct TRINITY_DLL_DECL boss_the_makerAI : public ScriptedAI
{
    boss_the_makerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 AcidSpray_Timer;
    uint32 ExplodingBreaker_Timer;
    uint32 Domination_Timer;
    uint32 Knockdown_Timer;

    void Reset()
    {
        AcidSpray_Timer = 15000;
        ExplodingBreaker_Timer = 6000;
        Domination_Timer = 120000;
        Knockdown_Timer = 10000;
        
        ToggleDoors(0, DATA_DOOR2);
        if(pInstance)
            pInstance->SetData(TYPE_THE_MAKER_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit *who)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_AGGRO_1, m_creature); break;
            case 1: DoScriptText(SAY_AGGRO_2, m_creature); break;
            case 2: DoScriptText(SAY_AGGRO_3, m_creature); break;
        }
        
        ToggleDoors(1, DATA_DOOR2);
        if(pInstance)
            pInstance->SetData(TYPE_THE_MAKER_EVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_KILL_1, m_creature); break;
            case 1: DoScriptText(SAY_KILL_2, m_creature); break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DIE, m_creature);
        ToggleDoors(0, DATA_DOOR2);
        ToggleDoors(0, DATA_DOOR3);
        
        if(pInstance)
            pInstance->SetData(TYPE_THE_MAKER_EVENT, DONE);
     }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (AcidSpray_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ACID_SPRAY);
            AcidSpray_Timer = 15000+rand()%8000;
        }else AcidSpray_Timer -=diff;

        if (ExplodingBreaker_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_EXPLODING_BREAKER);
            ExplodingBreaker_Timer = 4000+rand()%8000;
        }else ExplodingBreaker_Timer -=diff;

        /* // Disabled until Core Support for mind control
        if(domination_timer_timer < diff)
        {
        Unit* target;
        target = SelectUnit(SELECT_TARGET_RANDOM,0);

        DoCast(target,SPELL_DOMINATION);

        domination_timer = 120000;
        }else domination_timer -=diff;
        */

        if (Knockdown_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_KNOCKDOWN);
            Knockdown_Timer = 4000+rand()%8000;
        }else Knockdown_Timer -=diff;

        DoMeleeAttackIfReady();
    }
    
    void ToggleDoors(uint8 close, uint64 DOOR)
    {
        if (pInstance)
        {
            if (GameObject* Doors = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DOOR)))
            {
                if (close == 1)
                    Doors->SetGoState(GO_STATE_READY);                // Closed
                else
                    Doors->SetGoState(GO_STATE_ACTIVE);                // Open
            }
        }
    }
};

CreatureAI* GetAI_boss_the_makerAI(Creature *_Creature)
{
    return new boss_the_makerAI (_Creature);
}

void AddSC_boss_the_maker()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_the_maker";
    newscript->GetAI = &GetAI_boss_the_makerAI;
    newscript->RegisterSelf();
}

