/* Copyright (C) 2006 - 2010 TrinityCore <http://www.trinitycore.org>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "ScriptedPch.h"
#include "oculus.h"

enum Spells
{
    SPELL_MAGIC_PULL                              = 51336,
    SPELL_MAGIC_PULL_EFFECT                       = 50770,
    SPELL_THUNDERING_STOMP                        = 50774,
    SPELL_THUNDERING_STOMP_H                      = 59370,
    SPELL_UNSTABLE_SPHERE_PASSIVE                 = 50756,
    SPELL_UNSTABLE_SPHERE_PULSE                   = 50757,
    SPELL_UNSTABLE_SPHERE_TIMER                   = 50758,
    NPC_UNSTABLE_SPHERE                           = 28166,
};

//not in db
enum Yells
{
    SAY_AGGRO                               = -1578000,
    SAY_KILL_1                              = -1578001,
    SAY_KILL_2                              = -1578002,
    SAY_KILL_3                              = -1578003,
    SAY_DEATH                               = -1578004,
    SAY_PULL_1                              = -1578005,
    SAY_PULL_2                              = -1578006,
    SAY_PULL_3                              = -1578007,
    SAY_PULL_4                              = -1578008,
    SAY_STOMP_1                             = -1578009,
    SAY_STOMP_2                             = -1578010,
    SAY_STOMP_3                             = -1578011
};

struct boss_drakosAI : public ScriptedAI
{
    boss_drakosAI(Creature *c) : ScriptedAI(c), lSummons(me)
    {
        pInstance = c->GetInstanceData();
    }
    
    uint32 magicPullTimer ;
    uint32 stompTimer ;
    uint32 bombSummonTimer ;
    uint32 postPullTimer ;
    bool isPulling ;
    bool postPull ;
    ScriptedInstance* pInstance;
    SummonList lSummons;

    void Reset()
    {
        lSummons.DespawnAll();
        magicPullTimer = urand(12000, 15000);
        stompTimer = urand(3000, 6000);
        bombSummonTimer = 2000;
        postPull = false;
        isPulling = false;
        if (pInstance)
            pInstance->SetData(DATA_DRAKOS_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_DRAKOS_EVENT, IN_PROGRESS);
    }
	void JustSummoned(Creature* summon)
	{
		lSummons.Summon(summon);
	}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if(bombSummonTimer < diff)
        {
            if(postPull)
            {
                m_creature->SummonCreature(NPC_UNSTABLE_SPHERE, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
                m_creature->SummonCreature(NPC_UNSTABLE_SPHERE, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
            }
            else
                m_creature->SummonCreature(NPC_UNSTABLE_SPHERE, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
            bombSummonTimer = 2000;
        } else bombSummonTimer -= diff;

        if(magicPullTimer < diff)
        {
            if(isPulling)
            {
                if (pInstance)
                {
                    Map::PlayerList const &players = pInstance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        DoCast(itr->getSource(), SPELL_MAGIC_PULL_EFFECT, true);
                }
                isPulling = false;
                postPull = true;
                postPullTimer = 4000;
                magicPullTimer = urand(15000, 25000);
            }
            else
            {
                DoScriptText(RAND(SAY_PULL_1,SAY_PULL_2,SAY_PULL_3,SAY_PULL_4), m_creature);
                DoCast(SPELL_MAGIC_PULL);
                magicPullTimer = 2000;
                isPulling = true;
            }
        } else magicPullTimer -= diff;

        if(postPull)
        {
            if (postPullTimer < diff)
                postPull = false;
            else postPullTimer -= diff;
        }

        if(stompTimer < diff)
        {
            DoScriptText(RAND(SAY_STOMP_1,SAY_STOMP_2,SAY_STOMP_3), m_creature);
            DoCast(DUNGEON_MODE(SPELL_THUNDERING_STOMP, SPELL_THUNDERING_STOMP_H));
            stompTimer = urand(15000, 18000);
		} else stompTimer -= diff ;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_DRAKOS_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2,SAY_KILL_3), m_creature);
    }
};

CreatureAI* GetAI_boss_drakos(Creature* pCreature)
{
    return new boss_drakosAI (pCreature);
}

struct npc_unstable_sphereAI : public ScriptedAI
{
    npc_unstable_sphereAI(Creature *c) : ScriptedAI(c) {}

    uint32 pulseTimer;
    uint32 deathTimer;

    void Reset()
    {
        m_creature->SetReactState(REACT_PASSIVE) ;
        m_creature->GetMotionMaster()->MoveRandom(40.0f);
        m_creature->SetSpeed(MOVE_RUN, 2, true);
        m_creature->setFaction(14);
        m_creature->AddAura(SPELL_UNSTABLE_SPHERE_PASSIVE, m_creature);
        m_creature->AddAura(SPELL_UNSTABLE_SPHERE_TIMER, m_creature);
        pulseTimer = 3000;
        deathTimer = 19000;
    }

    void UpdateAI(const uint32 diff)
    {
        if(pulseTimer < diff)
        {
            DoCast(SPELL_UNSTABLE_SPHERE_PULSE);
            pulseTimer = 3000;
        } pulseTimer -= diff;

        if(deathTimer < diff)
            m_creature->DisappearAndDie();
        else deathTimer -= diff;
    }
};

CreatureAI* GetAI_npc_unstable_sphere(Creature* pCreature)
{
    return new npc_unstable_sphereAI (pCreature);
}

void AddSC_boss_drakos()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_drakos";
    newscript->GetAI = &GetAI_boss_drakos;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_unstable_sphere";
    newscript->GetAI = &GetAI_npc_unstable_sphere;
    newscript->RegisterSelf();
}
