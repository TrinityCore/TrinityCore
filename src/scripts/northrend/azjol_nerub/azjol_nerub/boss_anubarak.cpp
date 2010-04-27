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

enum
{
    ACHIEV_TIMED_START_EVENT                      = 20381,
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

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        me->RemoveAura(SPELL_SUBMERGE);

        lSummons.DespawnAll();

        if (pInstance)
        {
            pInstance->SetData(DATA_ANUBARAK_EVENT, NOT_STARTED);
            pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

        if (pInstance)
        {
            pInstance->SetData(DATA_ANUBARAK_EVENT, IN_PROGRESS);
            pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
    }


    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (bChanneling == true)
        {
            for (uint8 i = 0; i < 4; ++i)
                DoCast(me->getVictim(), SPELL_SUMMON_CARRION_BEETLES, true);
            bChanneling = false;
        }

        if (uiPhase == 1)
        {
            if (uiImpaleTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(pTarget, DUNGEON_MODE(SPELL_IMPALE,H_SPELL_IMPALE), true);
                uiImpaleTimer = 9*IN_MILISECONDS;
            } else uiImpaleTimer -= diff;

            if (!bGuardianSummoned)
            {
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (Creature *Guardian = me->SummonCreature(CREATURE_GUARDIAN,SpawnPoint[i],TEMPSUMMON_CORPSE_DESPAWN,0))
                    {
                        Guardian->AddThreat(me->getVictim(), 0.0f);
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
                            if (Creature *Venomancer = me->SummonCreature(CREATURE_VENOMANCER,SpawnPoint[i],TEMPSUMMON_CORPSE_DESPAWN,0))
                            {
                                Venomancer->AddThreat(me->getVictim(), 0.0f);
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
                            if (Creature *Datter = me->SummonCreature(CREATURE_DATTER,SpawnPoint[i],TEMPSUMMON_CORPSE_DESPAWN,0))
                            {
                                Datter->AddThreat(me->getVictim(), 0.0f);
                                DoZoneInCombat(Datter);
                            }
                        }
                        bDatterSummoned = true;
                    }
                } else uiDatterTimer -= diff;
            }

            if (uiUndergroundTimer <= diff)
            {
                me->RemoveAura(SPELL_SUBMERGE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                uiPhase = 0;
            } else uiUndergroundTimer -= diff;
        }

        if (uiPhase == 0)
        {
            if (uiLeechingSwarmTimer <= diff)
            {
                DoCast(me, SPELL_LEECHING_SWARM, true);
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
                 DoCastVictim(SPELL_POUND);
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

            DoCast(me, SPELL_SUBMERGE, false);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

            uiPhase = 1;
        }

        if (uiPhase != 1)
            DoMeleeAttackIfReady();
    }

    void JustDied(Unit * /*pKiller*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, DONE);
    }

    void KilledUnit(Unit *pVictim)
    {
        if (pVictim == me)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
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
