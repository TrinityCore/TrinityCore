/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "azjol_nerub.h"

enum Spells
{
    SPELL_CARRION_BEETLES                         = 53520,
    SPELL_SUMMON_CARRION_BEETLES                  = 53521,
    SPELL_LEECHING_SWARM                          = 53467,
    SPELL_POUND                                   = 53472,
    SPELL_POUND_H                                 = 59433,
    SPELL_SUBMERGE                                = 53421,
    SPELL_IMPALE_DMG                              = 53454,
    SPELL_IMPALE_DMG_H                            = 59446,
    SPELL_IMPALE_SHAKEGROUND                      = 53455,
    SPELL_IMPALE_SPIKE                            = 53539,   //this is not the correct visual effect
    //SPELL_IMPALE_TARGET                           = 53458,
};

enum Creatures
{
    CREATURE_GUARDIAN                             = 29216,
    CREATURE_VENOMANCER                           = 29217,
    CREATURE_DATTER                               = 29213,
    CREATURE_IMPALE_TARGET                        = 89,
    DISPLAY_INVISIBLE                             = 11686
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

enum Phases
{
    PHASE_MELEE                                   = 0,
    PHASE_UNDERGROUND                             = 1,
    IMPALE_PHASE_TARGET                           = 0,
    IMPALE_PHASE_ATTACK                           = 1,
    IMPALE_PHASE_DMG                              = 2
};

const Position SpawnPoint[2] =
{
    { 550.7f, 282.8f, 224.3f, 0.0f },
    { 551.1f, 229.4f, 224.3f, 0.0f },
};

const Position SpawnPointGuardian[2] =
{
    { 550.348633f, 316.006805f, 234.2947f, 0.0f },
    { 550.188660f, 324.264557f, 237.7412f, 0.0f },
};

class boss_anub_arak : public CreatureScript
{
public:
    boss_anub_arak() : CreatureScript("boss_anub_arak") { }

    struct boss_anub_arakAI : public ScriptedAI
    {
        boss_anub_arakAI(Creature* c) : ScriptedAI(c), lSummons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        bool bChanneling;
        bool bGuardianSummoned;
        bool bVenomancerSummoned;
        bool bDatterSummoned;
        uint8 uiPhase;
        uint32 uiUndergroundPhase;
        uint32 uiCarrionBeetlesTimer;
        uint32 uiLeechingSwarmTimer;
        uint32 uiPoundTimer;
        uint32 uiSubmergeTimer;
        uint32 uiUndergroundTimer;
        uint32 uiVenomancerTimer;
        uint32 uiDatterTimer;

        uint32 uiImpaleTimer;
        uint32 uiImpalePhase;
        uint64 uiImpaleTarget;

        SummonList lSummons;

        void Reset()
        {
            uiCarrionBeetlesTimer = 8*IN_MILLISECONDS;
            uiLeechingSwarmTimer = 20*IN_MILLISECONDS;
            uiImpaleTimer = 9*IN_MILLISECONDS;
            uiPoundTimer = 15*IN_MILLISECONDS;

            uiPhase = PHASE_MELEE;
            uiUndergroundPhase = 0;
            bChanneling = false;
            uiImpalePhase = IMPALE_PHASE_TARGET;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAura(SPELL_SUBMERGE);

            lSummons.DespawnAll();

            if (pInstance)
            {
                pInstance->SetData(DATA_ANUBARAK_EVENT, NOT_STARTED);
                pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }
        }

        Creature* DoSummonImpaleTarget(Unit* target)
        {
            Position targetPos;
            target->GetPosition(&targetPos);

            if (TempSummon* pImpaleTarget = me->SummonCreature(CREATURE_IMPALE_TARGET, targetPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 6*IN_MILLISECONDS))
            {
                uiImpaleTarget = pImpaleTarget->GetGUID();
                pImpaleTarget->SetReactState(REACT_PASSIVE);
                pImpaleTarget->SetDisplayId(DISPLAY_INVISIBLE);
                pImpaleTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                return pImpaleTarget;
            }

            return NULL;
        }

        void EnterCombat(Unit* /*pWho*/)
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
            if (!UpdateVictim())
                return;

            switch (uiPhase)
            {
            case PHASE_UNDERGROUND:
                if (uiImpaleTimer <= diff)
                {
                    switch(uiImpalePhase)
                    {
                    case IMPALE_PHASE_TARGET:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (Creature* pImpaleTarget = DoSummonImpaleTarget(target))
                                pImpaleTarget->CastSpell(pImpaleTarget, SPELL_IMPALE_SHAKEGROUND, true);
                            uiImpaleTimer = 3*IN_MILLISECONDS;
                            uiImpalePhase = IMPALE_PHASE_ATTACK;
                        }
                        break;
                    case IMPALE_PHASE_ATTACK:
                        if (Creature* pImpaleTarget = Unit::GetCreature(*me, uiImpaleTarget))
                        {
                            pImpaleTarget->CastSpell(pImpaleTarget, SPELL_IMPALE_SPIKE, false);
                            pImpaleTarget->RemoveAurasDueToSpell(SPELL_IMPALE_SHAKEGROUND);
                        }
                        uiImpalePhase = IMPALE_PHASE_DMG;
                        uiImpaleTimer = 1*IN_MILLISECONDS;
                        break;
                    case IMPALE_PHASE_DMG:
                        if (Creature* pImpaleTarget = Unit::GetCreature(*me, uiImpaleTarget))
                            me->CastSpell(pImpaleTarget, DUNGEON_MODE(SPELL_IMPALE_DMG, SPELL_IMPALE_DMG_H), true);
                        uiImpalePhase = IMPALE_PHASE_TARGET;
                        uiImpaleTimer = 9*IN_MILLISECONDS;
                        break;
                    }
                } else uiImpaleTimer -= diff;

                if (!bGuardianSummoned)
                {
                    for (uint8 i = 0; i < 2; ++i)
                    {
                        if (Creature* Guardian = me->SummonCreature(CREATURE_GUARDIAN, SpawnPointGuardian[i], TEMPSUMMON_CORPSE_DESPAWN, 0))
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
                        if (uiUndergroundPhase > 1)
                        {
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                if (Creature* Venomancer = me->SummonCreature(CREATURE_VENOMANCER, SpawnPoint[i], TEMPSUMMON_CORPSE_DESPAWN, 0))
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
                        if (uiUndergroundPhase > 2)
                        {
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                if (Creature* Datter = me->SummonCreature(CREATURE_DATTER, SpawnPoint[i], TEMPSUMMON_CORPSE_DESPAWN, 0))
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
                    uiPhase = PHASE_MELEE;
                } else uiUndergroundTimer -= diff;
                break;

            case PHASE_MELEE:
                if (((uiUndergroundPhase == 0 && HealthBelowPct(75))
                    || (uiUndergroundPhase == 1 && HealthBelowPct(50))
                    || (uiUndergroundPhase == 2 && HealthBelowPct(25)))
                    && !me->HasUnitState(UNIT_STAT_CASTING))
                {
                    bGuardianSummoned = false;
                    bVenomancerSummoned = false;
                    bDatterSummoned = false;

                    uiUndergroundTimer = 40*IN_MILLISECONDS;
                    uiVenomancerTimer = 25*IN_MILLISECONDS;
                    uiDatterTimer = 32*IN_MILLISECONDS;

                    uiImpalePhase = 0;
                    uiImpaleTimer = 9*IN_MILLISECONDS;

                    DoCast(me, SPELL_SUBMERGE, false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

                    uiPhase = PHASE_UNDERGROUND;
                    ++uiUndergroundPhase;
                }

                if (bChanneling == true)
                {
                    for (uint8 i = 0; i < 8; ++i)
                    DoCast(me->getVictim(), SPELL_SUMMON_CARRION_BEETLES, true);
                    bChanneling = false;
                }
                else if (uiCarrionBeetlesTimer <= diff)
                {
                    bChanneling = true;
                    DoCastVictim(SPELL_CARRION_BEETLES);
                    uiCarrionBeetlesTimer = 25*IN_MILLISECONDS;
                } else uiCarrionBeetlesTimer -= diff;

                if (uiLeechingSwarmTimer <= diff)
                {
                    DoCast(me, SPELL_LEECHING_SWARM, true);
                    uiLeechingSwarmTimer = 19*IN_MILLISECONDS;
                } else uiLeechingSwarmTimer -= diff;

                if (uiPoundTimer <= diff)
                {
                    if (Unit* target = me->getVictim())
                    {
                        if (Creature* pImpaleTarget = DoSummonImpaleTarget(target))
                            me->CastSpell(pImpaleTarget, DUNGEON_MODE(SPELL_POUND, SPELL_POUND_H), false);
                    }
                    uiPoundTimer = 16500;
                } else uiPoundTimer -= diff;

                DoMeleeAttackIfReady();
                break;
            }
        }

        void JustDied(Unit* /*pKiller*/)
        {
            DoScriptText(SAY_DEATH, me);
            lSummons.DespawnAll();
            if (pInstance)
                pInstance->SetData(DATA_ANUBARAK_EVENT, DONE);
        }

        void KilledUnit(Unit* pVictim)
        {
            if (pVictim == me)
                return;
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void JustSummoned(Creature* summon)
        {
            lSummons.Summon(summon);
        }
    };

    CreatureAI *GetAI(Creature* creature) const
    {
        return new boss_anub_arakAI(creature);
    }
};

void AddSC_boss_anub_arak()
{
    new boss_anub_arak;
}
