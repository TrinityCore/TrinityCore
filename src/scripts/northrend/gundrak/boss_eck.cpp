/*
* Copyright (C) 2009-2010 TrinityCore <http://www.trinitycore.org/>
*
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

#include "ScriptedPch.h"
#include "gundrak.h"

enum Spells
{
    SPELL_ECK_BERSERK                       = 55816, //Eck goes berserk, increasing his attack speed by 150% and all damage he deals by 500%.
    SPELL_ECK_BITE                          = 55813, //Eck bites down hard, inflicting 150% of his normal damage to an enemy.
    SPELL_ECK_SPIT                          = 55814, //Eck spits toxic bile at enemies in a cone in front of him, inflicting 2970 Nature damage and draining 220 mana every 1 sec for 3 sec.
    SPELL_ECK_SPRING_1                      = 55815, //Eck leaps at a distant target.  --> Drops aggro and charges a random player. Tank can simply taunt him back.
    SPELL_ECK_SPRING_2                      = 55837  //Eck leaps at a distant target.
};

static Position EckSpawnPoint = { 1643.877930, 936.278015, 107.204948, 0.668432 };

struct boss_eckAI : public ScriptedAI
{
    boss_eckAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiBerserkTimer;
    uint32 uiBiteTimer;
    uint32 uiSpitTimer;
    uint32 uiSpringTimer;

    bool bBerserk;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiBerserkTimer = 60000 + rand()%30000; //60-90 secs according to wowwiki
        uiBiteTimer = 5000;
        uiSpitTimer = 10000;
        uiSpringTimer = 8000;

        bBerserk = false;

        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiBiteTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ECK_BITE);
            uiBiteTimer = 8000 + rand()%4000;
        } else uiBiteTimer -= diff;

        if (uiSpitTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ECK_SPIT);
            uiSpitTimer = 6000 + rand()%8000;
        } else uiSpitTimer -= diff;

        if (uiSpringTimer <= diff)
        {
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
            if(pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(pTarget, RAND(SPELL_ECK_SPRING_1, SPELL_ECK_SPRING_2));
                uiSpringTimer = 5000 + rand()%10000;
            }
        } else uiSpringTimer -= diff;

        //Berserk on timer or 20% of health
        if (!bBerserk)
        {
            if (uiBerserkTimer <= diff)
            {
                DoCast(m_creature, SPELL_ECK_BERSERK);
                bBerserk = true;
            }
            else
            {
                uiBerserkTimer -= diff;
                if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 20)
                {
                    DoCast(m_creature, SPELL_ECK_BERSERK);
                    bBerserk = true;
                }
            }
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_eck(Creature* pCreature)
{
    return new boss_eckAI (pCreature);
}

struct npc_ruins_dwellerAI : public ScriptedAI
{
    npc_ruins_dwellerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    void JustDied(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_RUIN_DWELLER_DIED,m_creature->GetGUID());
            if (pInstance->GetData(DATA_ALIVE_RUIN_DWELLERS) == 0)
                m_creature->SummonCreature(CREATURE_ECK, EckSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILISECONDS);
        }
    }
};

CreatureAI* GetAI_npc_ruins_dweller(Creature* pCreature)
{
    return new npc_ruins_dwellerAI (pCreature);
}

void AddSC_boss_eck()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_eck";
    newscript->GetAI = &GetAI_boss_eck;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ruins_dweller";
    newscript->GetAI = &GetAI_npc_ruins_dweller;
    newscript->RegisterSelf();
}
