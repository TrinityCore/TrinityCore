/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Player.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerPackets.h"
#include "MovementPackets.h"
#include "Player.h"
#include "MoveSplineInitArgs.h"
#include "GridNotifiers.h"
#include "thenighthold.h"
#include "MoveSplineInit.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"

enum Spells
{
    // Burst Of Time
    SPELL_BURST_OF_TIME_AREA                    = 219984,
    SPELL_BURST_OF_TIME_SLOW                    = 214050,
    SPELL_BURST_OF_TIME_NORMAL                  = 206613,
    SPELL_BURST_OF_TIME_FAST                    = 214049,
    SPELL_SPEED_SLOW                            = 207011,
    SPELL_SPEED_NORMAL                          = 207012,
    SPELL_SPEED_FAST                            = 207013,
    // Time Release
    SPELL_TIME_RELEASE_AREA                     = 206610,
    SPELL_TIME_RELEASE_ABSORB                   = 206609,
    SPELL_TIME_RELEASE_GREEN                    = 219964,
    SPELL_TIME_RELEASE_YELLOW                   = 219965,
    SPELL_TIME_RELEASE_RED                      = 219966,
    SPELL_TIME_RELEASE_DAMAGE                   = 206608,
    // Temporal Orb
    SPELL_TEMPORAL_ORBS_PERIODIC                = 219815,
    SPELL_TEMPORAL_ORB_AREATRIGGER_FIRST        = 227217,
    SPELL_TEMPORAL_ORB_AREATRIGGER_SECOND       = 212874,
    SPELL_TEMPORAL_ORB_DAMAGE                   = 205707,
    // Chronometric Particles
    SPELL_CHRONOMETRIC_PARTICLES                = 206607,
    SPELL_CHRONOMETRIC_OVERLOAD                 = 207491,
    // Time Bomb
    SPELL_TIME_BOMB_AREA                        = 206618,
    SPELL_TIME_BOMB_DEBUFF                      = 206617,
    SPELL_TIME_BOMB_VISUAL                      = 212845,
    SPELL_TIME_BOMB_DAMAGE                      = 206615,
    // Waning Time Particle
    SPELL_WANING_TIME_PARTICLE_SUMMON           = 206698,
    SPELL_PASSAGE_OF_TIME                       = 205653,
    SPELL_WARP_NIGHTWELL                        = 207228,
    SPELL_CHRONOMATE                            = 219808,
    SPELL_TEMPORAL_RIFT                         = 212072,
    SPELL_FADE_OUT                              = 199615,
    SPELL_TEMPORAL_RIFT_SUMMON                  = 212076,
    // Fragmented Time Particle
    SPELL_WARP_NIGHTWELL_SMALL                  = 228335,
    // Temporal Rift
    SPELL_TEMPORAL_RIFT_VISUAL                  = 212090,
    // Power Overwhelming
    SPELL_POWER_OVERWHELMING                    = 211927,
    SPELL_POWER_OVERWHELMING_STACKS             = 219823,
    // Temporal Smash
    SPELL_TEMPORAL_SMASH_VISUAL                 = 212115,
    SPELL_TEMPORAL_SMASH_DEBUFF                 = 222283,
};

enum EventPhases
{
    EVENT_PHASE_NORMAL_SLOW_FAST                = 1,
    EVENT_PHASE_NORMAL_FAST_SLOW                = 2,
};

enum Events
{
    // Chronomatic Anomaly
    EVENT_BURST_OF_TIME                         = 1,
    EVENT_TIME_RELEASE                          = 2,
    EVENT_TEMPORAL_ORB_FIRST_WAVE               = 3,
    EVENT_TEMPORAL_ORB_SECOND_WAVE              = 4,
    EVENT_CHRONOMETRIC_PARTICLES                = 5,
    EVENT_TIME_BOMB                             = 6,
    EVENT_WANING_TIME_PARTICLE_SUMMON           = 7,
    EVENT_POWER_OVERWHELMING                    = 8,
    // Waning Time Particle
    EVENT_WARP_NIGHTWELL                        = 9,
    EVENT_CHRONOMATE                            = 10,
};

enum Actions
{
    ACTION_NEXT_SPEED                           = 1,
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SPEED_NORMAL                            = 1,
    SAY_WANING_TIME_PARTICLE                    = 3,
    SAY_POWER_OVERWHELMING                      = 4,
    SAY_SPEED_SLOW_FIRST                        = 5,
    SAY_SPEED_SLOW_SECOND                       = 6,
    SAY_SPEED_FAST_FIRST                        = 7,
    SAY_SPEED_FAST_SECOND                       = 8,
    SAY_DEATH                                   = 9
};

// 104415 - Chronomatic Anomaly
class boss_chronomatic_anomaly : public CreatureScript
{
public:
    boss_chronomatic_anomaly() : CreatureScript("boss_chronomatic_anomaly") { }

    struct boss_chronomatic_anomalyAI : public BossAI
    {
        boss_chronomatic_anomalyAI(Creature* creature) : BossAI(creature, BOSS_CHRONOMATIC_ANOMALY) { }

        void StartCyclePath()
        {
            Movement::MoveSplineInit init(me);
            init.SetCyclic();
            init.SetSmooth();
            init.SetVelocity(4.0f);
            init.MovebyPath(WaypointChronomaticAnomaly, 0);
            init.Launch();
        }

        void DespawnAreaTriggers(uint32 spellId)
        {
            std::vector<AreaTrigger*> areaTriggers = me->GetAreaTriggers(spellId);
            if (areaTriggers.empty())
                return;

            for (AreaTrigger* trigger : areaTriggers)
                trigger->Remove();
        }

        void StartSlowSpeed()
        {
            events.RescheduleEvent(EVENT_TIME_RELEASE, 5000);
            events.RescheduleEvent(EVENT_CHRONOMETRIC_PARTICLES, 1000);
            events.RescheduleEvent(EVENT_BURST_OF_TIME, 13000);
            events.RescheduleEvent(EVENT_WANING_TIME_PARTICLE_SUMMON, 50000);
            events.RescheduleEvent(EVENT_TIME_BOMB, 20000);
            events.RescheduleEvent(EVENT_TEMPORAL_ORB_FIRST_WAVE, 30000);
            events.RescheduleEvent(EVENT_TEMPORAL_ORB_SECOND_WAVE, 31000);
            events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 55000);
            me->CastStop();
            me->RemoveAura(SPELL_POWER_OVERWHELMING_STACKS);
            Talk(SAY_SPEED_SLOW_FIRST);
            Talk(SAY_SPEED_SLOW_SECOND);
            DoCastSelf(SPELL_SPEED_SLOW, true);
            instance->DoCastSpellOnPlayers(SPELL_SPEED_SLOW);
            _wavesTimeReleaseCount = 2;
            _wavesBurstOfTimeCount = 5;
            _triggersCount = 0;
        }

        void StartNormalSpeed()
        {
            events.RescheduleEvent(EVENT_TIME_RELEASE, 5000);
            events.RescheduleEvent(EVENT_CHRONOMETRIC_PARTICLES, 11000);
            events.RescheduleEvent(EVENT_BURST_OF_TIME, 13000);
            events.RescheduleEvent(EVENT_WANING_TIME_PARTICLE_SUMMON, 35000);
            events.RescheduleEvent(EVENT_TIME_BOMB, 35000);
            events.RescheduleEvent(EVENT_TEMPORAL_ORB_FIRST_WAVE, 48000);
            events.RescheduleEvent(EVENT_TEMPORAL_ORB_SECOND_WAVE, 49000);
            events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 55000);
            me->CastStop();
            me->RemoveAura(SPELL_POWER_OVERWHELMING_STACKS);
            Talk(SAY_SPEED_NORMAL);
            DoCastSelf(SPELL_SPEED_NORMAL, true);
            instance->DoCastSpellOnPlayers(SPELL_SPEED_NORMAL);
            _wavesTimeReleaseCount = 2;
            _wavesBurstOfTimeCount = 6;
            _triggersCount = 0;
        }

        void StartFastSpeed()
        {
            events.RescheduleEvent(EVENT_TIME_RELEASE, 10000);
            events.RescheduleEvent(EVENT_CHRONOMETRIC_PARTICLES, 1000);
            events.RescheduleEvent(EVENT_BURST_OF_TIME, 5000);
            events.RescheduleEvent(EVENT_WANING_TIME_PARTICLE_SUMMON, 45000);
            events.RescheduleEvent(EVENT_TIME_BOMB, 5000);
            events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 55000);
            me->CastStop();
            me->RemoveAura(SPELL_POWER_OVERWHELMING_STACKS);
            Talk(SAY_SPEED_FAST_FIRST);
            Talk(SAY_SPEED_FAST_SECOND);
            DoCastSelf(SPELL_SPEED_FAST, true);
            instance->DoCastSpellOnPlayers(SPELL_SPEED_FAST);
            _wavesTimeReleaseCount = 3;
            _wavesBurstOfTimeCount = 12;
            _triggersCount = 0;
        }

        void Reset() override
        {
            _Reset();
            StartCyclePath();
            _wavesTimeReleaseCount = 0;
            _wavesBurstOfTimeCount = 0;
            _triggersCount = 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            StartNormalSpeed();
            events.SetPhase(EVENT_PHASE_NORMAL_SLOW_FAST);
            Talk(SAY_AGGRO);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _DespawnAtEvade();
            summons.DespawnAll();
            DespawnAreaTriggers(SPELL_TEMPORAL_ORB_AREATRIGGER_FIRST);
            DespawnAreaTriggers(SPELL_TEMPORAL_ORB_AREATRIGGER_SECOND);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            DespawnAreaTriggers(SPELL_TEMPORAL_ORB_AREATRIGGER_FIRST);
            DespawnAreaTriggers(SPELL_TEMPORAL_ORB_AREATRIGGER_SECOND);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(SAY_DEATH);
        }

        void DoAction(int32 /*action*/) override
        {
            switch (events.GetPhaseMask())
            {
                case EVENT_PHASE_NORMAL_SLOW_FAST:
                    if (me->HasAura(SPELL_SPEED_SLOW))
                        StartFastSpeed();
                    else if (me->HasAura(SPELL_SPEED_NORMAL))
                        StartSlowSpeed();
                    else if (me->HasAura(SPELL_SPEED_FAST))
                    {
                        StartNormalSpeed();
                        events.SetPhase(EVENT_PHASE_NORMAL_FAST_SLOW);
                    }
                    break;
                case EVENT_PHASE_NORMAL_FAST_SLOW:
                    if (me->HasAura(SPELL_SPEED_SLOW))
                    {
                        StartNormalSpeed();
                        events.SetPhase(EVENT_PHASE_NORMAL_SLOW_FAST);
                    }
                    else if (me->HasAura(SPELL_SPEED_NORMAL))
                        StartFastSpeed();
                    else if (me->HasAura(SPELL_SPEED_FAST))
                        StartSlowSpeed();
                    break;
                default:
                    break;
            }
        }

        void JustSummoned(Creature* creature) override
        {
            summons.Summon(creature);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BURST_OF_TIME:
                    if (_wavesBurstOfTimeCount)
                    {
                        DoCastAOE(SPELL_BURST_OF_TIME_AREA, true);

                        if (me->HasAura(SPELL_SPEED_SLOW))
                            events.ScheduleEvent(EVENT_BURST_OF_TIME, 6000);
                        else if (me->HasAura(SPELL_SPEED_NORMAL))
                            events.ScheduleEvent(EVENT_BURST_OF_TIME, 5000);
                        else if (me->HasAura(SPELL_SPEED_FAST))
                            events.ScheduleEvent(EVENT_BURST_OF_TIME, 4000);
                        _wavesBurstOfTimeCount--;
                    }
                    break;
                case EVENT_TIME_RELEASE:
                    if (_wavesTimeReleaseCount)
                    {
                        DoCastAOE(SPELL_TIME_RELEASE_AREA, true);

                        if (me->HasAura(SPELL_SPEED_SLOW))
                            events.ScheduleEvent(EVENT_TIME_RELEASE, 23000);
                        else if (me->HasAura(SPELL_SPEED_NORMAL))
                            events.ScheduleEvent(EVENT_TIME_RELEASE, 15000);
                        else if (me->HasAura(SPELL_SPEED_FAST))
                            events.ScheduleEvent(EVENT_TIME_RELEASE, urand(10000, 15000));
                        _wavesTimeReleaseCount--;
                    }
                    break;
                case EVENT_TEMPORAL_ORB_FIRST_WAVE:
                    for (uint8 i = 0; i < 36; i++)
                        me->CastSpell(temporalOrbsSpawnPosition.GetPositionX(), temporalOrbsSpawnPosition.GetPositionY(), temporalOrbsSpawnPosition.GetPositionZ(), SPELL_TEMPORAL_ORB_AREATRIGGER_FIRST, true);
                    for (auto at : me->GetAreaTriggers(SPELL_TEMPORAL_ORB_AREATRIGGER_FIRST))
                    {
//                        at->AI()->DoAction(_triggersCount);
                        if (at->IsAreaTrigger())
                            _triggersCount++;
                    }
                    DoCast(SPELL_TEMPORAL_ORBS_PERIODIC);
                    break;
                case EVENT_TEMPORAL_ORB_SECOND_WAVE:
                    for (uint8 i = 0; i < 36; i++)
                        me->CastSpell(temporalOrbsSpawnPosition.GetPositionX(), temporalOrbsSpawnPosition.GetPositionY(), temporalOrbsSpawnPosition.GetPositionZ(), SPELL_TEMPORAL_ORB_AREATRIGGER_SECOND, true);
                    for (auto at : me->GetAreaTriggers(SPELL_TEMPORAL_ORB_AREATRIGGER_SECOND))
                    {
 //                       at->AI()->DoAction(_triggersCount);
                        if (at->IsAreaTrigger())
                            _triggersCount++;
                    }
                    break;
                case EVENT_CHRONOMETRIC_PARTICLES:
                    DoCastVictim(SPELL_CHRONOMETRIC_PARTICLES);
                    events.ScheduleEvent(EVENT_CHRONOMETRIC_PARTICLES, 6000);
                    break;
                case EVENT_TIME_BOMB:
                    DoCastAOE(SPELL_TIME_BOMB_AREA);
                    break;
                case EVENT_WANING_TIME_PARTICLE_SUMMON:
                {
                    Talk(SAY_WANING_TIME_PARTICLE);
                    uint8 randPos = urand(0, 1);
                    me->CastSpell(waningTimeParticleSpawnPositions[randPos].GetPositionX(), waningTimeParticleSpawnPositions[randPos].GetPositionY(), waningTimeParticleSpawnPositions[randPos].GetPositionZ(), SPELL_WANING_TIME_PARTICLE_SUMMON, true);
                    break;
                }
                case EVENT_POWER_OVERWHELMING:
                    if (auto nightwell = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATAGUID_THE_NIGHTWELL)))
                        DoCast(nightwell, SPELL_POWER_OVERWHELMING);
                    Talk(SAY_POWER_OVERWHELMING);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        uint8 _wavesBurstOfTimeCount;
        uint8 _wavesTimeReleaseCount;
        int32 _triggersCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<boss_chronomatic_anomalyAI>(creature);
    }
};

// 104676 - Waning Time Particle
class npc_waning_time_particle : public CreatureScript
{
public:
    npc_waning_time_particle() : CreatureScript("npc_waning_time_particle") { }

    struct npc_waning_time_particleAI : public ScriptedAI
    {
        npc_waning_time_particleAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            _ownerGuid = summoner->GetGUID();
            me->SetControlled(true, UNIT_STATE_ROOT);
            DoCastSelf(SPELL_PASSAGE_OF_TIME);
            events.ScheduleEvent(EVENT_CHRONOMATE, 5000);
            events.ScheduleEvent(EVENT_WARP_NIGHTWELL, 10000);
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCastSelf(SPELL_TEMPORAL_RIFT, true);
            DoCastSelf(SPELL_FADE_OUT, true);
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me, 1);

            if (auto summoner = ObjectAccessor::GetCreature(*me, _ownerGuid))
            {
                summoner->CastSpell(me, SPELL_TEMPORAL_RIFT_SUMMON, true);
                summoner->SummonCreature(NPC_FRAGMENTED_TIME_PARTICLE, me->GetPositionX(), me->GetPositionY() - 5, me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                summoner->SummonCreature(NPC_FRAGMENTED_TIME_PARTICLE, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                summoner->SummonCreature(NPC_FRAGMENTED_TIME_PARTICLE, me->GetPositionX(), me->GetPositionY() + 5, me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                summoner->SummonCreature(NPC_FRAGMENTED_TIME_PARTICLE, me->GetPositionX() - 5, me->GetPositionY(), me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHRONOMATE:
                    if (auto target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 0, true))
                        DoCast(target, SPELL_CHRONOMATE);
                    else if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_CHRONOMATE);
                    events.ScheduleEvent(EVENT_CHRONOMATE, 5000);
                    break;
                case EVENT_WARP_NIGHTWELL:
                    DoCastSelf(SPELL_WARP_NIGHTWELL);
                    if (auto summoner = ObjectAccessor::GetCreature(*me, _ownerGuid))
                    {
                        if (summoner->HasAura(SPELL_SPEED_SLOW))
                            events.ScheduleEvent(EVENT_WARP_NIGHTWELL, 10000);
                        else if (summoner->HasAura(SPELL_SPEED_NORMAL))
                            events.ScheduleEvent(EVENT_WARP_NIGHTWELL, 5000);
                        else if (summoner->HasAura(SPELL_SPEED_FAST))
                            events.ScheduleEvent(EVENT_WARP_NIGHTWELL, 1000);
                    }
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        ObjectGuid _ownerGuid;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_waning_time_particleAI>(creature);
    }
};

// 114671 - Fragmented Time Particle
class npc_fragmented_time_particle : public CreatureScript
{
public:
    npc_fragmented_time_particle() : CreatureScript("npc_fragmented_time_particle") { }

    struct npc_fragmented_time_particleAI : public ScriptedAI
    {
        npc_fragmented_time_particleAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetControlled(true, UNIT_STATE_ROOT);
            DoCastSelf(SPELL_PASSAGE_OF_TIME);
            events.ScheduleEvent(EVENT_CHRONOMATE, 5000);
            events.ScheduleEvent(EVENT_WARP_NIGHTWELL, 10000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCastSelf(SPELL_TEMPORAL_RIFT, true);
            DoCastSelf(SPELL_FADE_OUT, true);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHRONOMATE:
                    if (auto target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 0, true))
                        DoCast(target, SPELL_CHRONOMATE);
                    else if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_CHRONOMATE);
                    events.ScheduleEvent(EVENT_CHRONOMATE, 5000);
                    break;
                case EVENT_WARP_NIGHTWELL:
                    DoCastSelf(SPELL_WARP_NIGHTWELL_SMALL);
                    events.ScheduleEvent(EVENT_WARP_NIGHTWELL, 10000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_fragmented_time_particleAI>(creature);
    }
};

// 106878 - Temporal Rift
class npc_temporal_rift : public CreatureScript
{
public:
    npc_temporal_rift() : CreatureScript("npc_temporal_rift") { }

    struct npc_temporal_riftAI : public ScriptedAI
    {
        npc_temporal_riftAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            DoCastSelf(SPELL_TEMPORAL_RIFT_VISUAL);
        }

        void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) override
        {
            me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_temporal_riftAI>(creature);
    }
};

// 219984 - Burst Of Time
// 7.1.5
class spell_chronomatic_anomaly_burst_of_time_area : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_burst_of_time_area() : SpellScriptLoader("spell_chronomatic_anomaly_burst_of_time_area") { }

    class spell_chronomatic_anomaly_burst_of_time_area_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chronomatic_anomaly_burst_of_time_area_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_SPEED_SLOW,
                SPELL_SPEED_NORMAL,
                SPELL_SPEED_FAST,
                SPELL_BURST_OF_TIME_SLOW,
                SPELL_BURST_OF_TIME_NORMAL,
                SPELL_BURST_OF_TIME_FAST
            });
        }

        void HandleAreaSelect(std::list<WorldObject*>& targets)
        {
            targets.reverse();
            if (targets.size() > 5)
                targets.resize(5);
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (caster->HasAura(SPELL_SPEED_SLOW))
                caster->CastSpell(target, SPELL_BURST_OF_TIME_SLOW, true);
            else if (caster->HasAura(SPELL_SPEED_NORMAL))
                caster->CastSpell(target, SPELL_BURST_OF_TIME_NORMAL, true);
            else if (caster->HasAura(SPELL_SPEED_FAST))
                caster->CastSpell(target, SPELL_BURST_OF_TIME_FAST, true);
        }

        std::list<WorldObject*> targets;

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chronomatic_anomaly_burst_of_time_area_SpellScript::HandleAreaSelect, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_chronomatic_anomaly_burst_of_time_area_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chronomatic_anomaly_burst_of_time_area_SpellScript();
    }
};

// 206610 - Time Release
// 7.1.5
class spell_chronomatic_anomaly_time_release_area : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_time_release_area() : SpellScriptLoader("spell_chronomatic_anomaly_time_release_area") { }

    class spell_chronomatic_anomaly_time_release_area_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chronomatic_anomaly_time_release_area_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_SPEED_SLOW,
                SPELL_SPEED_NORMAL,
                SPELL_SPEED_FAST,
                SPELL_TIME_RELEASE_ABSORB,
                SPELL_TIME_RELEASE_RED
            });
        }

        void HandleAreaSelect(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_SPEED_SLOW))
                targets.remove(GetExplTargetWorldObject());
            else if (caster->HasAura(SPELL_SPEED_NORMAL))
            {
                targets.reverse();
                if (targets.size() > 4)
                    targets.resize(4);
            }
            else if (caster->HasAura(SPELL_SPEED_FAST))
            {
                targets.reverse();
                if (targets.size() > 2)
                    targets.resize(2);
            }
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (caster->HasAura(SPELL_SPEED_SLOW))
            {
                caster->CastCustomSpell(SPELL_TIME_RELEASE_ABSORB, SPELLVALUE_BASE_POINT0, GetEffectValue() / 3, target, TRIGGERED_FULL_MASK);
                target->CastCustomSpell(SPELL_TIME_RELEASE_RED, SPELLVALUE_BASE_POINT0, GetEffectValue() / 3, target, TRIGGERED_FULL_MASK);
            }
            else if (caster->HasAura(SPELL_SPEED_NORMAL))
            {
                caster->CastCustomSpell(SPELL_TIME_RELEASE_ABSORB, SPELLVALUE_BASE_POINT0, GetEffectValue() / 2, target, TRIGGERED_FULL_MASK);
                target->CastCustomSpell(SPELL_TIME_RELEASE_RED, SPELLVALUE_BASE_POINT0, GetEffectValue() / 2, target, TRIGGERED_FULL_MASK);
            }
            else if (caster->HasAura(SPELL_SPEED_FAST))
            {
                caster->CastCustomSpell(SPELL_TIME_RELEASE_ABSORB, SPELLVALUE_BASE_POINT0, GetEffectValue(), target, TRIGGERED_FULL_MASK);
                target->CastCustomSpell(SPELL_TIME_RELEASE_RED, SPELLVALUE_BASE_POINT0, GetEffectValue(), target, TRIGGERED_FULL_MASK);
            }


            if (caster->HasAura(SPELL_SPEED_SLOW))
            {
                if (Aura* timeReleaseAbsorb = target->GetAura(SPELL_TIME_RELEASE_ABSORB))
                {
                    if (Aura* timeReleaseRed = target->GetAura(SPELL_TIME_RELEASE_RED))
                    {
                        timeReleaseAbsorb->SetMaxDuration(25000);
                        timeReleaseAbsorb->SetDuration(25000);
                        timeReleaseRed->SetMaxDuration(25000);
                        timeReleaseRed->SetDuration(25000);
                    }
                }
            }
            else if (caster->HasAura(SPELL_SPEED_NORMAL))
            {
                if (Aura* timeReleaseAbsorb = target->GetAura(SPELL_TIME_RELEASE_ABSORB))
                {
                    if (Aura* timeReleaseRed = target->GetAura(SPELL_TIME_RELEASE_RED))
                    {
                        timeReleaseAbsorb->SetMaxDuration(20000);
                        timeReleaseAbsorb->SetDuration(20000);
                        timeReleaseRed->SetMaxDuration(20000);
                        timeReleaseRed->SetDuration(20000);
                    }
                }
            }
            else if (caster->HasAura(SPELL_SPEED_FAST))
            {
                if (Aura* timeReleaseAbsorb = target->GetAura(SPELL_TIME_RELEASE_ABSORB))
                {
                    if (Aura* timeReleaseRed = target->GetAura(SPELL_TIME_RELEASE_RED))
                    {
                        timeReleaseAbsorb->SetMaxDuration(15000);
                        timeReleaseAbsorb->SetDuration(15000);
                        timeReleaseRed->SetMaxDuration(15000);
                        timeReleaseRed->SetDuration(15000);
                    }
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chronomatic_anomaly_time_release_area_SpellScript::HandleAreaSelect, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_chronomatic_anomaly_time_release_area_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chronomatic_anomaly_time_release_area_SpellScript();
    }
};

// 206609 - Time Release
// 7.1.5
class spell_chronomatic_anomaly_time_release_absorb : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_time_release_absorb() : SpellScriptLoader("spell_chronomatic_anomaly_time_release_absorb") { }

    class spell_chronomatic_anomaly_time_release_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_chronomatic_anomaly_time_release_absorb_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_TIME_RELEASE_GREEN,
                SPELL_TIME_RELEASE_YELLOW,
                SPELL_TIME_RELEASE_RED,
                SPELL_TIME_RELEASE_DAMAGE
            });
        }

        void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            startAbsorb = aurEff->GetAmount();
            curAbsorb = aurEff->GetAmount();
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHealInfo() && eventInfo.GetHealInfo()->GetHeal())
                return true;
            return false;
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            uint32 healAmount = eventInfo.GetHealInfo()->GetHeal();
            if (curAbsorb > healAmount)
                curAbsorb -= healAmount;
            else
            {
                Remove();
                target->RemoveAura(SPELL_TIME_RELEASE_GREEN, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
                target->RemoveAura(SPELL_TIME_RELEASE_YELLOW, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
                target->RemoveAura(SPELL_TIME_RELEASE_RED, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
                return;
            }

            uint32 countForYellow = startAbsorb / 3 * 2;
            uint32 countForGreen = startAbsorb / 3;

            if (curAbsorb <= countForYellow && curAbsorb >= countForGreen)
            {
                target->CastCustomSpell(SPELL_TIME_RELEASE_YELLOW, SPELLVALUE_BASE_POINT0, curAbsorb, target, TRIGGERED_FULL_MASK);

                if (Aura* timeReleaseYellow = target->GetAura(SPELL_TIME_RELEASE_YELLOW))
                {
                    timeReleaseYellow->SetMaxDuration(GetAura()->GetDuration());
                    timeReleaseYellow->SetDuration(GetAura()->GetDuration());
                }
            }
            else if (curAbsorb <= countForGreen)
            {
                target->CastCustomSpell(SPELL_TIME_RELEASE_GREEN, SPELLVALUE_BASE_POINT0, curAbsorb, target, TRIGGERED_FULL_MASK);

                if (Aura* timeReleaseGreen = target->GetAura(SPELL_TIME_RELEASE_GREEN))
                {
                    timeReleaseGreen->SetMaxDuration(GetAura()->GetDuration());
                    timeReleaseGreen->SetDuration(GetAura()->GetDuration());
                }
            }
            else if (curAbsorb)
            {
                target->CastCustomSpell(SPELL_TIME_RELEASE_RED, SPELLVALUE_BASE_POINT0, curAbsorb, target, TRIGGERED_FULL_MASK);

                if (Aura* timeReleaseRed = target->GetAura(SPELL_TIME_RELEASE_RED))
                {
                    timeReleaseRed->SetMaxDuration(GetAura()->GetDuration());
                    timeReleaseRed->SetDuration(GetAura()->GetDuration());
                }
            }
        }

        void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
            if (!caster || !target || removeMode != AURA_REMOVE_BY_EXPIRE)
                return;

            caster->CastCustomSpell(SPELL_TIME_RELEASE_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_chronomatic_anomaly_time_release_absorb_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            DoCheckProc += AuraCheckProcFn(spell_chronomatic_anomaly_time_release_absorb_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_chronomatic_anomaly_time_release_absorb_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
            OnEffectRemove += AuraEffectRemoveFn(spell_chronomatic_anomaly_time_release_absorb_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }

        uint32 startAbsorb;
        uint32 curAbsorb;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_chronomatic_anomaly_time_release_absorb_AuraScript();
    }
};

// 206607 - Chronometric Particles
// 7.1.5
class spell_chronomatic_anomaly_chronometric_particles : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_chronometric_particles() : SpellScriptLoader("spell_chronomatic_anomaly_chronometric_particles") { }

    class spell_chronomatic_anomaly_chronometric_particles_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_chronomatic_anomaly_chronometric_particles_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_SPEED_SLOW,
                SPELL_SPEED_NORMAL,
                SPELL_SPEED_FAST,
                SPELL_CHRONOMETRIC_OVERLOAD
            });
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (GetAura()->GetStackAmount() > 9)
                caster->CastSpell(target, SPELL_CHRONOMETRIC_OVERLOAD, true);

            if (caster->HasAura(SPELL_SPEED_SLOW))
            {
                GetAura()->GetEffect(EFFECT_0)->SetPeriodicTimer(6000);
                GetAura()->SetMaxDuration(60000);
                GetAura()->SetDuration(60000);
            }
            else if (caster->HasAura(SPELL_SPEED_NORMAL))
            {
                GetAura()->GetEffect(EFFECT_0)->SetPeriodicTimer(2000);
                GetAura()->SetMaxDuration(20000);
                GetAura()->SetDuration(20000);
            }
            else if (caster->HasAura(SPELL_SPEED_FAST))
            {
                GetAura()->GetEffect(EFFECT_0)->SetPeriodicTimer(1000);
                GetAura()->SetMaxDuration(10000);
                GetAura()->SetDuration(10000);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_chronomatic_anomaly_chronometric_particles_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_chronomatic_anomaly_chronometric_particles_AuraScript();
    }
};

// 206618 - Time Bomb Area
// 7.1.5
class spell_chronomatic_anomaly_time_bomb_area : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_time_bomb_area() : SpellScriptLoader("spell_chronomatic_anomaly_time_bomb_area") { }

    class spell_chronomatic_anomaly_time_bomb_area_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chronomatic_anomaly_time_bomb_area_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_TIME_BOMB_DEBUFF });
        }

        void HandleAreaSelect(std::list<WorldObject*>& targets)
        {
            targets.remove_if([](WorldObject* obj)
            {
                Player* player = obj->ToPlayer();
                if (!player)
                    return true;

                if (player->GetRoleForGroup() == ROLE_TANK)
                    return true;
                return false;
            });

            uint8 bobmsCount = urand(2, 3);
            targets.reverse();
            if (targets.size() > bobmsCount)
                targets.resize(bobmsCount);
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_TIME_BOMB_DEBUFF);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chronomatic_anomaly_time_bomb_area_SpellScript::HandleAreaSelect, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_chronomatic_anomaly_time_bomb_area_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chronomatic_anomaly_time_bomb_area_SpellScript();
    }
};

// 206617 - Time Bomb Periodic
// 7.1.5
class spell_chronomatic_anomaly_time_bomb_periodic : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_time_bomb_periodic() : SpellScriptLoader("spell_chronomatic_anomaly_time_bomb_periodic") { }

    class spell_chronomatic_anomaly_time_bomb_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_chronomatic_anomaly_time_bomb_periodic_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_SPEED_SLOW,
                SPELL_SPEED_NORMAL,
                SPELL_SPEED_FAST,
                SPELL_TIME_BOMB_VISUAL,
                SPELL_TIME_BOMB_DAMAGE
            });
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (caster->HasAura(SPELL_SPEED_SLOW))
            {
                GetAura()->SetMaxDuration(60000);
                GetAura()->SetDuration(60000);
            }
            else if (caster->HasAura(SPELL_SPEED_NORMAL))
            {
                GetAura()->SetMaxDuration(20000);
                GetAura()->SetDuration(20000);
            }
            else if (caster->HasAura(SPELL_SPEED_FAST))
            {
                GetAura()->SetMaxDuration(8000);
                GetAura()->SetDuration(8000);
            }
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (GetAura()->GetDuration() <= 5000 && !target->HasAura(SPELL_TIME_BOMB_VISUAL))
                caster->CastSpell(target, SPELL_TIME_BOMB_VISUAL);
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_TIME_BOMB_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_chronomatic_anomaly_time_bomb_periodic_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_chronomatic_anomaly_time_bomb_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(spell_chronomatic_anomaly_time_bomb_periodic_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_chronomatic_anomaly_time_bomb_periodic_AuraScript();
    }
};

// 206615 - Time Bomb Damage
// 7.1.5
class spell_chronomatic_anomaly_time_bomb_damage : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_time_bomb_damage() : SpellScriptLoader("spell_chronomatic_anomaly_time_bomb_damage") { }

    class spell_chronomatic_anomaly_time_bomb_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chronomatic_anomaly_time_bomb_damage_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            int32 damage = GetHitDamage();
            uint8 distance = caster->GetExactDist(target);
            AddPct(damage, -distance);
            SetHitDamage(damage);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_chronomatic_anomaly_time_bomb_damage_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chronomatic_anomaly_time_bomb_damage_SpellScript();
    }
};

// 212109 - Temporal Smash Jump
// 7.1.5
class spell_chronomatic_anomaly_temporal_smash : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_temporal_smash() : SpellScriptLoader("spell_chronomatic_anomaly_temporal_smash") { }

    class spell_chronomatic_anomaly_temporal_smash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chronomatic_anomaly_temporal_smash_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_TEMPORAL_SMASH_VISUAL });
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (WorldLocation const* dest = GetExplTargetDest())
            {
                int32 speedxy = caster->GetExactDist2d(dest);
                int32 speedz = 25;
                JumpArrivalCastArgs arrivalCast;
                arrivalCast.SpellId = SPELL_TEMPORAL_SMASH_VISUAL;
                arrivalCast.Target = target->GetGUID();
                //arrivalCast.Triggered = true;
                caster->GetMotionMaster()->MoveJump(*dest, speedxy, speedz, 0, false, &arrivalCast);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_chronomatic_anomaly_temporal_smash_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DASH);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chronomatic_anomaly_temporal_smash_SpellScript();
    }
};

// 212115 - Temporal Smash Dest
// 7.1.5
class spell_chronomatic_anomaly_temporal_smash_dest : public SpellScriptLoader
{
public:
    spell_chronomatic_anomaly_temporal_smash_dest() : SpellScriptLoader("spell_chronomatic_anomaly_temporal_smash_dest") { }

    class spell_chronomatic_anomaly_temporal_smash_dest_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chronomatic_anomaly_temporal_smash_dest_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_TEMPORAL_SMASH_DEBUFF });
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target || !target->ToCreature())
                return;

            caster->CastSpell(target, SPELL_TEMPORAL_SMASH_DEBUFF, true);
            target->ToCreature()->AI()->DoAction(ACTION_NEXT_SPEED);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_chronomatic_anomaly_temporal_smash_dest_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chronomatic_anomaly_temporal_smash_dest_SpellScript();
    }
};

// 11521 - Temporal Orb
// 7.1.5
class areatrigger_chronomatic_anomaly_temporal_orb : public AreaTriggerEntityScript
{
public:
    areatrigger_chronomatic_anomaly_temporal_orb() : AreaTriggerEntityScript("areatrigger_chronomatic_anomaly_temporal_orb") { }

    struct areatrigger_chronomatic_anomaly_temporal_orbAI : AreaTriggerAI
    {
        areatrigger_chronomatic_anomaly_temporal_orbAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnInitialize() override
        {
            _posIndex = 0;
            canStartPath = true;
            _timer = 500;
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();;
            Player* target = unit->ToPlayer();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_TEMPORAL_ORB_DAMAGE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Player* target = unit->ToPlayer();
            if (!target)
                return;

            if (target->HasAura(SPELL_TEMPORAL_ORB_DAMAGE))
                target->RemoveAura(SPELL_TEMPORAL_ORB_DAMAGE);
        }

        void OnDestinationReached() override
        {
            at->SetDuration(0);
        }

        void DoAction(int32 param)
        {
            _posIndex = param;
        }

        void OnUpdate(uint32 diff) override
        {
            if (_timer <= diff && canStartPath)
            {
                Position temporalpos = temporalOrbsDestPositions[_posIndex].GetPosition();
                std::vector<G3D::Vector3> SplinePoints;
                SplinePoints.push_back(G3D::Vector3(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ()));
                SplinePoints.push_back(G3D::Vector3(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ()));
                SplinePoints.push_back(G3D::Vector3(temporalpos.m_positionX, temporalpos.m_positionY, temporalpos.m_positionZ));
                SplinePoints.push_back(G3D::Vector3(temporalpos.m_positionX, temporalpos.m_positionY, temporalpos.m_positionZ));
                at->InitSplines(SplinePoints, 15000);
                canStartPath = false;
            }
            else
                _timer -= diff;
        }

    private:
        uint8 _posIndex;
        bool canStartPath = true;
        uint32 _timer;
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_chronomatic_anomaly_temporal_orbAI(areatrigger);
    }
};

void AddSC_boss_chronomatic_anomaly()
{
    new boss_chronomatic_anomaly();
    new npc_waning_time_particle();
    new npc_fragmented_time_particle();
    new npc_temporal_rift();
    new spell_chronomatic_anomaly_burst_of_time_area();
    new spell_chronomatic_anomaly_time_release_area();
    new spell_chronomatic_anomaly_time_release_absorb();
    new spell_chronomatic_anomaly_chronometric_particles();
    new spell_chronomatic_anomaly_time_bomb_area();
    new spell_chronomatic_anomaly_time_bomb_periodic();
    new spell_chronomatic_anomaly_time_bomb_damage();
    new spell_chronomatic_anomaly_temporal_smash();
    new spell_chronomatic_anomaly_temporal_smash_dest();
    new areatrigger_chronomatic_anomaly_temporal_orb();
}
