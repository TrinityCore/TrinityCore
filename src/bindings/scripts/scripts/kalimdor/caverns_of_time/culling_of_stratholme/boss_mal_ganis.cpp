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
SDName: Boss mal_ganis
SDAuthor: Tartalo
SD%Complete: 80
SDComment: TODO: Intro & outro
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_mal_ganis' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CARRION_SWARM                           = 52720, //A cresting wave of chaotic magic splashes over enemies in front of the caster, dealing 3230 to 3570 Shadow damage and 380 to 420 Shadow damage every 3 sec. for 15 sec.
    H_SPELL_CARRION_SWARM                         = 58852,
    SPELL_MIND_BLAST                              = 52722, //Inflicts 4163 to 4837 Shadow damage to an enemy.
    H_SPELL_MIND_BLAST                            = 58850,
    SPELL_SLEEP                                   = 52721, //Puts an enemy to sleep for up to 10 sec. Any damage caused will awaken the target.
    H_SPELL_SLEEP                                 = 58849,
    SPELL_VAMPIRIC_TOUCH                          = 52723 //Heals the caster for half the damage dealt by a melee attack.
};

//not in db
enum Yells
{
    SAY_INTRO_1                                  = -1595009,
    SAY_INTRO_2                                  = -1595010,
    SAY_OUTRO                                    = -1595011,
    SAY_AGGRO                                    = -1595012,
    SAY_KILL_1                                   = -1595013,
    SAY_KILL_2                                   = -1595014,
    SAY_KILL_3                                   = -1595015,
    SAY_SLAY_1                                   = -1595016,
    SAY_SLAY_2                                   = -1595017,
    SAY_SLAY_3                                   = -1595018,
    SAY_SLAY_4                                   = -1595019,
    SAY_SLEEP_1                                  = -1595020,
    SAY_SLEEP_2                                  = -1595021,
    SAY_30HEALTH                                 = -1595022,
    SAY_15HEALTH                                 = -1595023,
    SAY_ESCAPE_SPEECH_1                          = -1595024,
    SAY_ESCAPE_SPEECH_2                          = -1595025
};

enum CombatPhases
{
    COMBAT,
    OUTRO
};

struct TRINITY_DLL_DECL boss_mal_ganisAI : public ScriptedAI
{
    boss_mal_ganisAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiCarrionSwarmTimer;
    uint32 uiMindBlastTimer;
    uint32 uiVampiricTouchTimer;
    uint32 uiSleepTimer;

    uint8 uiOutroStep;

    bool bYelled;
    bool bYelled2;

    Creature *pArthas;
    CombatPhases Phase;
         
    ScriptedInstance* pInstance;

    void Reset()
    {
         bYelled = false;
         bYelled2 = false;
         pArthas = NULL;
         Phase = COMBAT;
         uiCarrionSwarmTimer = 6000;
         uiMindBlastTimer = 11000;
         uiVampiricTouchTimer = urand(10000,15000);
         uiSleepTimer = urand(15000,20000);
         
         if (pInstance)
             pInstance->SetData(DATA_MAL_GANIS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        pArthas = GetClosestCreatureWithEntry(m_creature, NPC_ARTHAS, 150.0f);
        
        if (pInstance)
            pInstance->SetData(DATA_MAL_GANIS_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        switch(Phase)
        {
            case COMBAT:
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (!bYelled && HealthBelowPct(30))
                {
                    DoScriptText(SAY_30HEALTH, m_creature);
                    bYelled = true;
                }

                if (!bYelled2 && HealthBelowPct(15))
                {
                    DoScriptText(SAY_15HEALTH, m_creature);
                    bYelled2 = true;
                }

                if (HealthBelowPct(1))
                {
                    //Handle Escape Event: Don't forget to add Player::RewardPlayerAndGroupAtEvent
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    uiOutroStep = 1;
                    Phase = OUTRO;
                    return;
                }

                if (pArthas && pArthas->isDead())
                {
                    EnterEvadeMode();
                    m_creature->DisappearAndDie();
                    if (pInstance)
                        pInstance->SetData(DATA_MAL_GANIS_EVENT, FAIL);
                }

                if (uiCarrionSwarmTimer < diff)
                {
                    DoCastVictim(HEROIC(SPELL_CARRION_SWARM,H_SPELL_CARRION_SWARM));
                    uiCarrionSwarmTimer = 7000;
                } else uiCarrionSwarmTimer -= diff;

                if (uiMindBlastTimer < diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, HEROIC(SPELL_MIND_BLAST,H_SPELL_MIND_BLAST));
                } else uiMindBlastTimer -= diff;

                if (uiVampiricTouchTimer < diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, SPELL_VAMPIRIC_TOUCH);
                } else uiVampiricTouchTimer -= diff;

                if (uiSleepTimer < diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, HEROIC(SPELL_SLEEP,H_SPELL_SLEEP));
                    uiSleepTimer = urand(15000,20000);
                } else uiSleepTimer -= diff;

                DoMeleeAttackIfReady();
                break;
        }
    }
    void JustDied(Unit* killer)
    {
        if (pInstance)
             pInstance->SetData(DATA_MAL_GANIS_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3,SAY_SLAY_4), m_creature);
    }
};

CreatureAI* GetAI_boss_mal_ganis(Creature* pCreature)
{
    return new boss_mal_ganisAI (pCreature);
}

void AddSC_boss_mal_ganis()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_mal_ganis";
    newscript->GetAI = &GetAI_boss_mal_ganis;
    newscript->RegisterSelf();
}
