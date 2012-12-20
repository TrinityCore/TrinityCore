/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "azjol_nerub.h"

enum Spells
{
    SPELL_CARRION_BEETLES                         = 53520,
    SPELL_SUMMON_CARRION_BEETLES                  = 53521,
    SPELL_LEECHING_SWARM                          = 53467,
    SPELL_POUND                                   = 53472,
    SPELL_SUBMERGE                                = 53421,
    SPELL_IMPALE_DMG                              = 53454,
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
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_LOCUST                                    = 3,
    SAY_SUBMERGE                                  = 4,
    SAY_INTRO                                     = 5
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
        boss_anub_arakAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        bool Channeling;
        bool GuardianSummoned;
        bool VenomancerSummoned;
        bool DatterSummoned;
        uint8 Phase;
        uint32 UndergroundPhase;
        uint32 CarrionBeetlesTimer;
        uint32 LeechingSwarmTimer;
        uint32 PoundTimer;
        uint32 SubmergeTimer;
        uint32 UndergroundTimer;
        uint32 VenomancerTimer;
        uint32 DatterTimer;
        uint32 DelayTimer;

        uint32 ImpaleTimer;
        uint32 ImpalePhase;
        uint64 ImpaleTarget;

        SummonList Summons;

        void Reset()
        {
            CarrionBeetlesTimer = 8*IN_MILLISECONDS;
            LeechingSwarmTimer = 20*IN_MILLISECONDS;
            ImpaleTimer = 9*IN_MILLISECONDS;
            PoundTimer = 15*IN_MILLISECONDS;

            Phase = PHASE_MELEE;
            UndergroundPhase = 0;
            Channeling = false;
            ImpalePhase = IMPALE_PHASE_TARGET;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAura(SPELL_SUBMERGE);

            Summons.DespawnAll();

            if (instance)
            {
                instance->SetData(DATA_ANUBARAK_EVENT, NOT_STARTED);
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }
        }

        Creature* DoSummonImpaleTarget(Unit* target)
        {
            Position targetPos;
            target->GetPosition(&targetPos);

            if (TempSummon* impaleTarget = me->SummonCreature(CREATURE_IMPALE_TARGET, targetPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 6*IN_MILLISECONDS))
            {
                ImpaleTarget = impaleTarget->GetGUID();
                impaleTarget->SetReactState(REACT_PASSIVE);
                impaleTarget->SetDisplayId(DISPLAY_INVISIBLE);
                impaleTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                return impaleTarget;
            }

            return NULL;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            DelayTimer = 0;
            if (instance)
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void DelayEventStart()
        {
            if (instance)
                instance->SetData(DATA_ANUBARAK_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (DelayTimer && DelayTimer > 5000)
                DelayEventStart();
            else DelayTimer+=diff;

            switch (Phase)
            {
            case PHASE_UNDERGROUND:
                if (ImpaleTimer <= diff)
                {
                    switch (ImpalePhase)
                    {
                    case IMPALE_PHASE_TARGET:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (Creature* impaleTarget = DoSummonImpaleTarget(target))
                                impaleTarget->CastSpell(impaleTarget, SPELL_IMPALE_SHAKEGROUND, true);
                            ImpaleTimer = 3*IN_MILLISECONDS;
                            ImpalePhase = IMPALE_PHASE_ATTACK;
                        }
                        break;
                    case IMPALE_PHASE_ATTACK:
                        if (Creature* impaleTarget = Unit::GetCreature(*me, ImpaleTarget))
                        {
                            impaleTarget->CastSpell(impaleTarget, SPELL_IMPALE_SPIKE, false);
                            impaleTarget->RemoveAurasDueToSpell(SPELL_IMPALE_SHAKEGROUND);
                        }
                        ImpalePhase = IMPALE_PHASE_DMG;
                        ImpaleTimer = 1*IN_MILLISECONDS;
                        break;
                    case IMPALE_PHASE_DMG:
                        if (Creature* impaleTarget = Unit::GetCreature(*me, ImpaleTarget))
                            me->CastSpell(impaleTarget, SPELL_IMPALE_DMG, true);
                        ImpalePhase = IMPALE_PHASE_TARGET;
                        ImpaleTimer = 9*IN_MILLISECONDS;
                        break;
                    }
                } else ImpaleTimer -= diff;

                if (!GuardianSummoned)
                {
                    for (uint8 i = 0; i < 2; ++i)
                    {
                        if (Creature* Guardian = me->SummonCreature(CREATURE_GUARDIAN, SpawnPointGuardian[i], TEMPSUMMON_CORPSE_DESPAWN, 0))
                        {
                            Guardian->AddThreat(me->getVictim(), 0.0f);
                            DoZoneInCombat(Guardian);
                        }
                    }
                    GuardianSummoned = true;
                }

                if (!VenomancerSummoned)
                {
                    if (VenomancerTimer <= diff)
                    {
                        if (UndergroundPhase > 1)
                        {
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                if (Creature* Venomancer = me->SummonCreature(CREATURE_VENOMANCER, SpawnPoint[i], TEMPSUMMON_CORPSE_DESPAWN, 0))
                                {
                                    Venomancer->AddThreat(me->getVictim(), 0.0f);
                                    DoZoneInCombat(Venomancer);
                                }
                            }
                            VenomancerSummoned = true;
                        }
                    } else VenomancerTimer -= diff;
                }

                if (!DatterSummoned)
                {
                    if (DatterTimer <= diff)
                    {
                        if (UndergroundPhase > 2)
                        {
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                if (Creature* Datter = me->SummonCreature(CREATURE_DATTER, SpawnPoint[i], TEMPSUMMON_CORPSE_DESPAWN, 0))
                                {
                                    Datter->AddThreat(me->getVictim(), 0.0f);
                                    DoZoneInCombat(Datter);
                                }
                            }
                            DatterSummoned = true;
                        }
                    } else DatterTimer -= diff;

                    if (me->HasAura(SPELL_LEECHING_SWARM))
                        me->RemoveAurasDueToSpell(SPELL_LEECHING_SWARM);
                }

                if (UndergroundTimer <= diff)
                {
                    me->RemoveAura(SPELL_SUBMERGE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    Phase = PHASE_MELEE;
                } else UndergroundTimer -= diff;
                break;

            case PHASE_MELEE:
                if (((UndergroundPhase == 0 && HealthBelowPct(75))
                    || (UndergroundPhase == 1 && HealthBelowPct(50))
                    || (UndergroundPhase == 2 && HealthBelowPct(25)))
                    && !me->HasUnitState(UNIT_STATE_CASTING))
                {
                    GuardianSummoned = false;
                    VenomancerSummoned = false;
                    DatterSummoned = false;

                    UndergroundTimer = 40*IN_MILLISECONDS;
                    VenomancerTimer = 25*IN_MILLISECONDS;
                    DatterTimer = 32*IN_MILLISECONDS;

                    ImpalePhase = 0;
                    ImpaleTimer = 9*IN_MILLISECONDS;

                    DoCast(me, SPELL_SUBMERGE, false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

                    Phase = PHASE_UNDERGROUND;
                    ++UndergroundPhase;
                }

                if (Channeling == true)
                {
                    for (uint8 i = 0; i < 8; ++i)
                    DoCast(me->getVictim(), SPELL_SUMMON_CARRION_BEETLES, true);
                    Channeling = false;
                }
                else if (CarrionBeetlesTimer <= diff)
                {
                    Channeling = true;
                    DoCastVictim(SPELL_CARRION_BEETLES);
                    CarrionBeetlesTimer = 25*IN_MILLISECONDS;
                } else CarrionBeetlesTimer -= diff;

                if (LeechingSwarmTimer <= diff)
                {
                    DoCast(me, SPELL_LEECHING_SWARM, true);
                    LeechingSwarmTimer = 19*IN_MILLISECONDS;
                } else LeechingSwarmTimer -= diff;

                if (PoundTimer <= diff)
                {
                    if (Unit* target = me->getVictim())
                    {
                        if (Creature* pImpaleTarget = DoSummonImpaleTarget(target))
                            me->CastSpell(pImpaleTarget, SPELL_POUND, false);
                    }
                    PoundTimer = 16500;
                } else PoundTimer -= diff;

                DoMeleeAttackIfReady();
                break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            Summons.DespawnAll();
            if (instance)
                instance->SetData(DATA_ANUBARAK_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;
            Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summon)
        {
            Summons.Summon(summon);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_anub_arakAI(creature);
    }
};

void AddSC_boss_anub_arak()
{
    new boss_anub_arak;
}
