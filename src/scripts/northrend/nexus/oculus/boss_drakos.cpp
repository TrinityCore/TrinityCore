/* Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org>
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
    SAY_AGGRO                                     = -1578000,
    SAY_KILL_1                                    = -1578001,
    SAY_KILL_2                                    = -1578002,
    SAY_KILL_3                                    = -1578003,
    SAY_DEATH                                     = -1578004,
    SAY_PULL_1                                    = -1578005,
    SAY_PULL_2                                    = -1578006,
    SAY_PULL_3                                    = -1578007,
    SAY_PULL_4                                    = -1578008,
    SAY_STOMP_1                                   = -1578009,
    SAY_STOMP_2                                   = -1578010,
    SAY_STOMP_3                                   = -1578011
};

enum
{
    ACHIEV_TIMED_START_EVENT                      = 18153,
};

struct boss_drakosAI : public ScriptedAI
{
    boss_drakosAI(Creature *c) : ScriptedAI(c), lSummons(me)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiMagicPullTimer ;
    uint32 uiStompTimer ;
    uint32 uiBombSummonTimer ;
    uint32 uiPostPullTimer ;
    bool bIsPulling ;
    bool bPostPull ;
    ScriptedInstance* pInstance;
    SummonList lSummons;

    void Reset()
    {
        lSummons.DespawnAll();
        uiMagicPullTimer = urand(12*IN_MILISECONDS, 15*IN_MILISECONDS);
        uiStompTimer = urand(3*IN_MILISECONDS, 6*IN_MILISECONDS);
        uiBombSummonTimer = 2*IN_MILISECONDS;
        bPostPull = false;
        bIsPulling = false;
        if (pInstance)
            pInstance->SetData(DATA_DRAKOS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

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

        if (uiBombSummonTimer < diff)
        {
            if (bPostPull)
            {
                me->SummonCreature(NPC_UNSTABLE_SPHERE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                me->SummonCreature(NPC_UNSTABLE_SPHERE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            }
            else
                me->SummonCreature(NPC_UNSTABLE_SPHERE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            uiBombSummonTimer = 2*IN_MILISECONDS;
        } else uiBombSummonTimer -= diff;

        if (uiMagicPullTimer < diff)
        {
            if (bIsPulling)
            {
                if (pInstance)
                {
                    Map::PlayerList const &players = pInstance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        DoCast(itr->getSource(), SPELL_MAGIC_PULL_EFFECT, true);
                }
                bIsPulling = false;
                bPostPull = true;
                uiPostPullTimer = 4*IN_MILISECONDS;
                uiMagicPullTimer = urand(15*IN_MILISECONDS, 25*IN_MILISECONDS);
            }
            else
            {
                DoScriptText(RAND(SAY_PULL_1,SAY_PULL_2,SAY_PULL_3,SAY_PULL_4), me);
                DoCast(SPELL_MAGIC_PULL);
                uiMagicPullTimer = 2*IN_MILISECONDS;
                bIsPulling = true;
            }
        } else uiMagicPullTimer -= diff;

        if (bPostPull)
        {
            if (uiPostPullTimer < diff)
                bPostPull = false;
            else uiPostPullTimer -= diff;
        }

        if (uiStompTimer < diff)
        {
            DoScriptText(RAND(SAY_STOMP_1,SAY_STOMP_2,SAY_STOMP_3), me);
            DoCast(SPELL_THUNDERING_STOMP);
            uiStompTimer = urand(15*IN_MILISECONDS, 18*IN_MILISECONDS);
        } else uiStompTimer -= diff ;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
        {
            pInstance->SetData(DATA_DRAKOS_EVENT, DONE);
            // start achievement timer (kill Eregos within 20 min)
            pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
    }
    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2,SAY_KILL_3), me);
    }
};

CreatureAI* GetAI_boss_drakos(Creature* pCreature)
{
    return new boss_drakosAI (pCreature);
}

struct npc_unstable_sphereAI : public ScriptedAI
{
    npc_unstable_sphereAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiPulseTimer;
    uint32 uiDeathTimer;

    void Reset()
    {
        me->SetReactState(REACT_PASSIVE) ;
        me->GetMotionMaster()->MoveRandom(40.0f);
        me->SetSpeed(MOVE_RUN, 2, true);
        me->setFaction(14);
        me->AddAura(SPELL_UNSTABLE_SPHERE_PASSIVE, me);
        me->AddAura(SPELL_UNSTABLE_SPHERE_TIMER, me);
        uiPulseTimer = 3*IN_MILISECONDS;
        uiDeathTimer = 19*IN_MILISECONDS;
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiPulseTimer < diff)
        {
            DoCast(SPELL_UNSTABLE_SPHERE_PULSE);
            uiPulseTimer = 3*IN_MILISECONDS;
        } else uiPulseTimer -= diff;

        if (uiDeathTimer < diff)
            me->DisappearAndDie();
        else uiDeathTimer -= diff;
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
