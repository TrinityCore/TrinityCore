/*
* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Boss Tharon'ja
SDAuthor: Tartalo
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_tharon_ja' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "drak_tharon_keep.h"

enum Spells
{
    //skeletal spells (phase 1)
    SPELL_CURSE_OF_LIFE                                    = 49527,
    H_SPELL_CURSE_OF_LIFE                                  = 59972,
    SPELL_RAIN_OF_FIRE                                     = 49518,
    H_SPELL_RAIN_OF_FIRE                                   = 59971,
    SPELL_SHADOW_VOLLEY                                    = 49528,
    H_SPELL_SHADOW_VOLLEY                                  = 59973,
    SPELL_DECAY_FLESH                                      = 49356, //casted at end of phase 1, starts phase 2
    //flesh spells (phase 2)
    SPELL_GIFT_OF_THARON_JA                                = 52509,
    SPELL_EYE_BEAM                                         = 49544,
    H_SPELL_EYE_BEAM                                       = 59965,
    SPELL_LIGHTNING_BREATH                                 = 49537,
    H_SPELL_LIGHTNING_BREATH                               = 59963,
    SPELL_POISON_CLOUD                                     = 49548,
    H_SPELL_POISON_CLOUD                                   = 59969,
    SPELL_RETURN_FLESH                                     = 53463 //Channeled spell ending phase two and returning to phase 1. This ability will stun the party for 6 seconds.
};
enum PlayerSkills
{
    //Players' skills during Phase2
    SPELL_PLAYER_PHASE2_SLAYING_STRIKE                     = 50799,
    SPELL_PLAYER_PHASE2_TAUNT                              = 49613,
    SPELL_PLAYER_PHASE2_BONE_ARMOR                         = 49609,
    SPELL_PLAYER_PHASE2_TOUCH_OF_LIFE                      = 49617
};

//not in db
enum Yells
{
    SAY_AGGRO                                              = -1600011,
    SAY_KILL_1                                             = -1600012,
    SAY_KILL_2                                             = -1600013,
    SAY_FLESH_1                                            = -1600014,
    SAY_FLESH_2                                            = -1600015,
    SAY_SKELETON_1                                         = -1600016,
    SAY_SKELETON_2                                         = -1600017,
    SAY_DEATH                                              = -1600018
};
enum Models
{
    MODEL_FLESH                                            = 27696
};
enum CombatPhase
{
    SKELETAL,
    GOING_FLESH,
    FLESH,
    GOING_SKELETAL
};

struct TRINITY_DLL_DECL boss_tharon_jaAI : public ScriptedAI
{
    boss_tharon_jaAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiPhaseTimer;
    uint32 uiCurseOfLifeTimer;
    uint32 uiRainOfFireTimer;
    uint32 uiShadowVolleyTimer;
    uint32 uiEyeBeamTimer;
    uint32 uiLightningBreathTimer;
    uint32 uiPoisonCloudTimer;
    
    CombatPhase Phase;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiPhaseTimer = 20000;
        uiCurseOfLifeTimer = 1000;
        uiRainOfFireTimer = urand(14000,18000);
        uiShadowVolleyTimer = urand(8000,10000);
        Phase = SKELETAL;
        m_creature->SetDisplayId(m_creature->GetNativeDisplayId());
        if (pInstance)
            pInstance->SetData(DATA_THARON_JA_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_THARON_JA_EVENT, IN_PROGRESS);
    }
    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        switch (Phase)
        {
            case SKELETAL:
                if (uiCurseOfLifeTimer < diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, HEROIC(SPELL_CURSE_OF_LIFE,H_SPELL_CURSE_OF_LIFE));
                    uiCurseOfLifeTimer = urand(10000,15000);
                } else uiCurseOfLifeTimer -= diff;
                
                if (uiShadowVolleyTimer < diff)
                {
                    DoCastVictim(HEROIC(SPELL_SHADOW_VOLLEY,H_SPELL_SHADOW_VOLLEY));
                    uiShadowVolleyTimer = urand(8000,10000);
                } else uiShadowVolleyTimer -= diff;
                
                if (uiRainOfFireTimer < diff)
                {
                    DoCastAOE(HEROIC(SPELL_RAIN_OF_FIRE,H_SPELL_RAIN_OF_FIRE));
                    uiRainOfFireTimer = urand(14000,18000);
                } else uiRainOfFireTimer -= diff;
                
                if (uiPhaseTimer < diff)
                {
                    DoCast(SPELL_DECAY_FLESH);
                    Phase = GOING_FLESH;
                    uiPhaseTimer = 6000;
                } else uiPhaseTimer -= diff;

                DoMeleeAttackIfReady();
                break;
            case GOING_FLESH:
                if (uiPhaseTimer < diff)
                {
                    DoScriptText(RAND(SAY_FLESH_1,SAY_FLESH_2),m_creature);
                    m_creature->SetDisplayId(MODEL_FLESH);
                    std::list<HostilReference*>& threatlist = m_creature->getThreatManager().getThreatList();
                    for (std::list<HostilReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                    {
                        Unit *pTemp = Unit::GetUnit((*m_creature),(*itr)->getUnitGuid());
                        if (pTemp && pTemp->GetTypeId() == TYPEID_PLAYER)
                        {
                            Player *pTarget = CAST_PLR(pTemp);
                            DoCast(pTemp, SPELL_GIFT_OF_THARON_JA);
                            pTarget->AddTemporarySpell(SPELL_PLAYER_PHASE2_BONE_ARMOR);
                            pTarget->AddTemporarySpell(SPELL_PLAYER_PHASE2_SLAYING_STRIKE);
                            pTarget->AddTemporarySpell(SPELL_PLAYER_PHASE2_TAUNT);
                            pTarget->AddTemporarySpell(SPELL_PLAYER_PHASE2_TOUCH_OF_LIFE);
                        }
                    }
                    uiPhaseTimer = 20000;
                    uiLightningBreathTimer = urand(3000,4000);
                    uiEyeBeamTimer = urand(4000,8000);
                    uiPoisonCloudTimer = urand(6000,7000);
                    Phase = FLESH;
                } else uiPhaseTimer -= diff;
                break;
            case FLESH:
                if (uiLightningBreathTimer < diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget,HEROIC(SPELL_LIGHTNING_BREATH,H_SPELL_LIGHTNING_BREATH));
                    uiLightningBreathTimer = urand(6000,7000);
                } else uiLightningBreathTimer -= diff;

                if (uiEyeBeamTimer < diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget,HEROIC(SPELL_EYE_BEAM,H_SPELL_EYE_BEAM));
                    uiEyeBeamTimer = urand(4000,6000);
                } else uiEyeBeamTimer -= diff;

                if (uiPoisonCloudTimer < diff)
                {
                    DoCastAOE(HEROIC(SPELL_POISON_CLOUD,H_SPELL_POISON_CLOUD));
                    uiPoisonCloudTimer = urand(10000,12000);
                } else uiPoisonCloudTimer -= diff;
                
                if (uiPhaseTimer < diff)
                {
                    DoCast(SPELL_RETURN_FLESH);
                    Phase = GOING_SKELETAL;
                    uiPhaseTimer = 6000;
                } else uiPhaseTimer -= diff;
                DoMeleeAttackIfReady();
                break;
            case GOING_SKELETAL:
                if (uiPhaseTimer < diff)
                {
                    DoScriptText(RAND(SAY_SKELETON_1,SAY_SKELETON_2), m_creature);
                    m_creature->SetDisplayId(m_creature->GetNativeDisplayId());
                    Phase = SKELETAL;
                    uiPhaseTimer = 20000;
                    uiCurseOfLifeTimer = 1000;
                    uiRainOfFireTimer = urand(14000,18000);
                    uiShadowVolleyTimer = urand(8000,10000);
                    std::list<HostilReference*>& threatlist = m_creature->getThreatManager().getThreatList();
                    for (std::list<HostilReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                    {
                        Unit *pTemp = Unit::GetUnit((*m_creature),(*itr)->getUnitGuid());
                        if (pTemp && pTemp->GetTypeId() == TYPEID_PLAYER)
                        {
                            if (pTemp->HasAura(SPELL_GIFT_OF_THARON_JA))
                                pTemp->RemoveAura(SPELL_GIFT_OF_THARON_JA);
                            Player *pTarget = CAST_PLR(pTemp);
                            pTarget->RemoveTemporarySpell(SPELL_PLAYER_PHASE2_BONE_ARMOR);
                            pTarget->RemoveTemporarySpell(SPELL_PLAYER_PHASE2_SLAYING_STRIKE);
                            pTarget->RemoveTemporarySpell(SPELL_PLAYER_PHASE2_TAUNT);
                            pTarget->RemoveTemporarySpell(SPELL_PLAYER_PHASE2_TOUCH_OF_LIFE);
                        }
                    }
                } else uiPhaseTimer -= diff;
                break;
        }
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2),m_creature);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH,m_creature);

        if (pInstance)
            pInstance->SetData(DATA_THARON_JA_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_tharon_ja(Creature* pCreature)
{
    return new boss_tharon_jaAI (pCreature);
}

void AddSC_boss_tharon_ja()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_tharon_ja";
    newscript->GetAI = &GetAI_boss_tharon_ja;
    newscript->RegisterSelf();
}
