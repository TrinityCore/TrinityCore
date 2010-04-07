/*
* Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
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
#include "azjol_nerub.h"

enum Spells
{
    SPELL_CARRION_BEETLES                         = 53520,
    SPELL_SUMMON_CARRION_BEETLES                  = 53521,
    SPELL_LEECHING_SWARM                          = 53467,
    SPELL_IMPALE                                  = 53454,
    H_SPELL_IMPALE                                = 59446,
    SPELL_POUND                                   = 53472,
    H_SPELL_POUND                                 = 59433,
    SPELL_SUBMERGE                                = 53421,
};

enum Creatures
{
    CREATURE_GUARDIAN                             = 29216,
    CREATURE_VENOMANCER                           = 29217,
    CREATURE_DATTER                               = 29213
};

// not in db
enum Yells
{
    SAY_INTRO                                     = -1601010,
    SAY_AGGRO                                     = -1601000,
    SAY_SLAY_1                                    = -1601001,
    SAY_SLAY_2                                    = -1601002,
    SAY_SLAY_3                                    = -1601003,
    SAY_LOCUST_1                                  = -1601005,
    SAY_LOCUST_2                                  = -1601006,
    SAY_LOCUST_3                                  = -1601007,
    SAY_SUBMERGE_1                                = -1601008,
    SAY_SUBMERGE_2                                = -1601009,
    SAY_DEATH                                     = -1601004
};

const Position SpawnPoint[2] =
{
    { 550.7, 282.8, 224.3 },
    { 551.1, 229.4, 224.3 },
};

struct boss_anub_arakAI : public ScriptedAI
{
    boss_anub_arakAI(Creature *c) : ScriptedAI(c), lSummons(me)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    bool bChanneling;
    bool bGuardianSummoned;
    bool bVenomancerSummoned;
    bool bDatterSummoned;
    uint8 uiPhase;
    uint32 uiPhaseTimer;

    uint32 uiCarrionBeetlesTimer;
    uint32 uiLeechingSwarmTimer;
    uint32 uiImpaleTimer;
    uint32 uiPoundTimer;
    uint32 uiSubmergeTimer;
    uint32 uiUndergroundTimer;
    uint32 uiVenomancerTimer;
    uint32 uiDatterTimer;

    SummonList lSummons;

    void Reset()
    {

        uiCarrionBeetlesTimer = 8*IN_MILISECONDS;
        uiLeechingSwarmTimer = 20*IN_MILISECONDS;
        uiImpaleTimer = 9*IN_MILISECONDS;
        uiPoundTimer = 15*IN_MILISECONDS;

        uiPhase = 0;
        uiPhaseTimer = 0;
        bChanneling = false;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveAura(SPELL_SUBMERGE);

        lSummons.DespawnAll();

        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, NOT_STARTED);
    }


    void EnterCombat(Unit *pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, IN_PROGRESS);
    }


    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (bChanneling == true)
        {
            for (uint8 i = 0; i < 4; ++i)
                DoCast(m_creature->getVictim(), SPELL_SUMMON_CARRION_BEETLES, true);
            bChanneling = false;
        }

        if (uiPhase == 1)
        {
            if (uiImpaleTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    m_creature->CastSpell(pTarget, DUNGEON_MODE(SPELL_IMPALE,H_SPELL_IMPALE), true);
                uiImpaleTimer = 9*IN_MILISECONDS;
            } else uiImpaleTimer -= diff;

            if (!bGuardianSummoned)
            {
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (Creature *Guardian = m_creature->SummonCreature(CREATURE_GUARDIAN,SpawnPoint[i],TEMPSUMMON_CORPSE_DESPAWN,0))
                    {
                        Guardian->AddThreat(m_creature->getVictim(), 0.0f);
                        DoZoneInCombat(Guardian);
                    }
                }
                bGuardianSummoned = true;
            }

            if (!bVenomancerSummoned)
            {
                if (uiVenomancerTimer <= diff)
                {
                    if (uiPhaseTimer > 1)
                    {
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            if (Creature *Venomancer = m_creature->SummonCreature(CREATURE_VENOMANCER,SpawnPoint[i],TEMPSUMMON_CORPSE_DESPAWN,0))
                            {
                                Venomancer->AddThreat(m_creature->getVictim(), 0.0f);
                                DoZoneInCombat(Venomancer);
                            }
                        }
                        bVenomancerSummoned = true;
                    }
                } else uiVenomancerTimer -= diff;
            }

            if (!bDatterSummoned)
            {
                if (uiDatterTimer <= diff)
                {
                    if (uiPhaseTimer > 2)
                    {
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            if (Creature *Datter = m_creature->SummonCreature(CREATURE_DATTER,SpawnPoint[i],TEMPSUMMON_CORPSE_DESPAWN,0))
                            {
                                Datter->AddThreat(m_creature->getVictim(), 0.0f);
                                DoZoneInCombat(Datter);
                            }
                        }
                        bDatterSummoned = true;
                    }
                } else uiDatterTimer -= diff;
            }

            if (uiUndergroundTimer <= diff)
            {
                m_creature->RemoveAura(SPELL_SUBMERGE);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                uiPhase = 0;
            } else uiUndergroundTimer -= diff;
        }

        if (uiPhase == 0)
        {
            if (uiLeechingSwarmTimer <= diff)
            {
                DoCast(m_creature, SPELL_LEECHING_SWARM, true);
                uiLeechingSwarmTimer = 19*IN_MILISECONDS;
            } else uiLeechingSwarmTimer -= diff;

            if (uiCarrionBeetlesTimer <= diff)
            {
                bChanneling = true;
                DoCastVictim(SPELL_CARRION_BEETLES);
                uiCarrionBeetlesTimer = 25*IN_MILISECONDS;
            } else uiCarrionBeetlesTimer -= diff;

            if (uiPoundTimer <= diff)
            {
                 DoCastVictim(DUNGEON_MODE(SPELL_POUND, H_SPELL_POUND));
                 uiPoundTimer = 16.5*IN_MILISECONDS;
            } else uiPoundTimer -= diff;
        }

        if ((uiPhaseTimer == 0 && HealthBelowPct(75))
            || (uiPhaseTimer == 1 && HealthBelowPct(50))
            || (uiPhaseTimer == 2 && HealthBelowPct(25)))
        {
            ++uiPhaseTimer;

            bGuardianSummoned = false;
            bVenomancerSummoned = false;
            bDatterSummoned = false;

            uiUndergroundTimer = 40*IN_MILISECONDS;
            uiVenomancerTimer = 25*IN_MILISECONDS;
            uiDatterTimer = 32*IN_MILISECONDS;

            DoCast(m_creature, SPELL_SUBMERGE, false);

            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

            uiPhase = 1;
        }

        if (uiPhase != 1)
            DoMeleeAttackIfReady();
    }

    void JustDied(Unit *pKiller)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, DONE);
    }

    void KilledUnit(Unit *pVictim)
    {
        if (pVictim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }

    void JustSummoned(Creature* summon)
    {
        lSummons.Summon(summon);
    }

};

CreatureAI* GetAI_boss_anub_arak(Creature *pCreature)
{
    return new boss_anub_arakAI (pCreature);
}

void AddSC_boss_anub_arak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_anub_arak";
    newscript->GetAI = &GetAI_boss_anub_arak;
    newscript->RegisterSelf();
}
