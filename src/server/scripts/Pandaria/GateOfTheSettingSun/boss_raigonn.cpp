/*
 * Copyright 2021 ShadowCore
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
#include "gate_setting_sun.h"
#include "Vehicle.h"
#include "Spline.h"

enum eSpells
{
    // Raigonn
    SPELL_IMPERVIOUS_CARAPACE       = 107118,

    SPELL_BATTERING_HEADBUTT_EMOTE  = 118685,
    SPELL_BATTERING_HEADBUTT        = 111668,
    SPELL_BATTERING_STUN            = 130772,

    SPELL_BROKEN_CARAPACE           = 111742,
    SPELL_BROKEN_CARAPACE_DAMAGE    = 107146,
    SPELL_FIXATE                    = 78617,
    SPELL_STOMP                     = 34716,

    // Protectorat
    SPELL_HIVE_MIND                 = 107314,

    // Engulfer
    SPELL_ENGULFING_WINDS           = 107274,

    // Swarm Bringer
    SPELL_SCREECHING_SWARM          = 111600
};

enum ePhases
{
    PHASE_WEAK_SPOT     = 1,
    PHASE_VULNERABILITY = 2
};

enum eActions
{
    ACTION_WEAK_SPOT_DEAD   = 1
};

enum eEvents
{
    EVENT_CHECK_WIPE            = 1,
    EVENT_RAIGONN_CHARGE        = 2,

    EVENT_SUMMON_PROTECTORAT    = 3,
    EVENT_SUMMON_ENGULFER       = 4,
    EVENT_SUMMON_SWARM_BRINGER  = 5,

    EVENT_FIXATE                = 6,
    EVENT_FIXATE_STOP           = 7,

    EVENT_STOMP                 = 8
};

enum eMovements
{
    POINT_MAIN_DOOR     = 1,
    POINT_HERSE         = 2
};

Position chargePos[4] =
{
    { 958.30f, 2386.92f, 297.43f, 0.0f },
    { 958.30f, 2458.59f, 300.29f, 0.0f },
    { 958.30f, 2241.68f, 296.10f, 0.0f },
    { 958.30f, 2330.15f, 296.18f, 0.0f }
};

class boss_raigonn : public CreatureScript
{
    public:
        boss_raigonn() : CreatureScript("boss_raigonn") {}

        struct boss_raigonnAI : public BossAI
        {
            boss_raigonnAI(Creature* creature) : BossAI(creature, DATA_RAIGONN)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            uint8  eventChargeProgress;
            uint32 eventChargeTimer;

            uint8 Phase;

            bool inFight;

            void Reset() override
            {
                _Reset();

                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_IMPERVIOUS_CARAPACE, me);
                me->CombatStop();
                SetCanSeeEvenInPassiveMode(true);

                Phase = PHASE_WEAK_SPOT;

                inFight = false;

                eventChargeProgress = 0;
                events.ScheduleEvent(EVENT_RAIGONN_CHARGE, 1000, PHASE_WEAK_SPOT);

                me->RemoveAurasDueToSpell(SPELL_BROKEN_CARAPACE);
                me->RemoveAurasDueToSpell(SPELL_BROKEN_CARAPACE_DAMAGE);

                if (Vehicle* meVehicle = me->GetVehicleKit())
                {
                    meVehicle->SetPassengersSpawnedByAI(true);

                    if (Unit* passenger = meVehicle->GetPassenger(1)) // Check if weak_spot already spawned
                    {
                        passenger->SetFaction(35);
                        passenger->SetFullHealth();
                        passenger->AddUnitState(UNIT_STATE_UNATTACKABLE);
                        pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, passenger);
                        return;
                    }

                    if (Creature* weakSpot = me->SummonCreature(NPC_WEAK_SPOT, 0, 0, 0))
                    {
                        weakSpot->EnterVehicle(me, 1);

                        if (pInstance)
                            pInstance->SetGuidData(NPC_WEAK_SPOT, weakSpot->GetGUID());

                        if (Vehicle* vehicleWeakSpot = weakSpot->GetVehicleKit())
                            vehicleWeakSpot->SetCanBeCastedByPassengers(true);
                    }
                }
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (inFight)
                    return;

                if (me->GetDistance(who) > 30.0f)
                    return;

                if (pInstance)
                    if (pInstance->GetBossState(DATA_RIMOK) != DONE)
                        return;

                Player* whoPlayer = who->ToPlayer();

                if (!whoPlayer)
                    return;

                if (whoPlayer->IsGameMaster())
                    return;

                inFight = true;
                DoZoneInCombat();
                events.CancelEventGroup(PHASE_VULNERABILITY);
                events.ScheduleEvent(EVENT_SUMMON_PROTECTORAT, urand(15000, 30000));
                events.ScheduleEvent(EVENT_SUMMON_ENGULFER, urand(15000, 30000));
                events.ScheduleEvent(EVENT_SUMMON_SWARM_BRINGER, urand(15000, 30000));
                events.ScheduleEvent(EVENT_CHECK_WIPE, 1000);

                pInstance->SetBossState(DATA_RAIGONN, IN_PROGRESS);

                if (Creature* weakPoint = pInstance->instance->GetCreature(pInstance->GetGuidData(NPC_WEAK_SPOT)))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, weakPoint);
                    weakPoint->SetFaction(16);
                    weakPoint->ClearUnitState(UNIT_STATE_UNATTACKABLE);
                    weakPoint->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Phase != PHASE_VULNERABILITY)
                    return;

                _EnterCombat();
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_MAIN_DOOR:
                    case POINT_HERSE:
                        DoEventCharge();
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_WEAK_SPOT_DEAD)
                {
                    Phase = PHASE_VULNERABILITY;
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetSpeed(MOVE_RUN, 1.1f);

                    me->CastStop();
                    me->RemoveAurasDueToSpell(SPELL_IMPERVIOUS_CARAPACE);
                    me->CastSpell(me, SPELL_BROKEN_CARAPACE, true);
                    me->CastSpell(me, SPELL_BROKEN_CARAPACE_DAMAGE, true);

                    events.CancelEventGroup(PHASE_WEAK_SPOT);
                    events.ScheduleEvent(EVENT_FIXATE, 30000, PHASE_VULNERABILITY);
                    events.ScheduleEvent(EVENT_STOMP, 16000, PHASE_VULNERABILITY);

                    DoZoneInCombat();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        AttackStart(target);
                }
            }

            void JustReachedHome() override
            {
                instance->SetBossState(DATA_RAIGONN, FAIL);
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summoned) override
            {
                summons.Summon(summoned);
            }

            void RemoveWeakSpotPassengers()
            {
                if (Creature* weakPoint = pInstance->instance->GetCreature(pInstance->GetGuidData(NPC_WEAK_SPOT)))
                {
                    if (Vehicle* weakVehicle = weakPoint->GetVehicleKit())
                    {
                        const uint8 maxPassenger = 2;
                        Unit* passengerList[maxPassenger];

                        for (uint8 i = 0; i < maxPassenger; ++i)
                            passengerList[i] = weakVehicle->GetPassenger(i);

                        weakVehicle->RemoveAllPassengers();

                        for (uint8 i = 0; i < maxPassenger; ++i)
                            if (passengerList[i])
                                passengerList[i]->GetMotionMaster()->MoveJumpTo((rand() % 2) ? (M_PI / 4): (3 * M_PI / 4), 20.0f, 10.0f);
                    }
                }
            }

            void DoEventCharge()
            {
                if (!pInstance)
                    return;

                if (Phase != PHASE_WEAK_SPOT)
                    return;

                uint32 eventBrasierProgress = pInstance->GetData(DATA_BRASIER_CLICKED);
                uint8 baseMovement = eventBrasierProgress != DONE ? 0: 2;

                switch (eventChargeProgress)
                {
                    case 0:
                        me->CastSpell(me, SPELL_BATTERING_HEADBUTT_EMOTE, false);
                        events.ScheduleEvent(EVENT_RAIGONN_CHARGE, 1750, PHASE_WEAK_SPOT);
                        ++eventChargeProgress;
                        break;
                    case 1:
                        // SPELL_BATTERING_HEADBUTT_EMOTE have an effect but is used here only for it's emote, we don't let him time to do his effects
                        me->CastStop();

                        me->GetMotionMaster()->MoveCharge(chargePos[baseMovement].GetPositionX(), chargePos[baseMovement].GetPositionY(), chargePos[baseMovement].GetPositionZ(), 84.0f, POINT_HERSE);
                        ++eventChargeProgress;
                        break;
                    case 2:
                        if (eventBrasierProgress == DONE)
                            RemoveWeakSpotPassengers();

                        me->CastSpell(me, SPELL_BATTERING_HEADBUTT, true);
                        events.ScheduleEvent(EVENT_RAIGONN_CHARGE, 3000, PHASE_WEAK_SPOT);
                        ++eventChargeProgress;
                        break;
                    case 3:
                    default:
                        // We are going back to main door, restart
                        eventChargeProgress = 0;
                        me->SetSpeed(MOVE_RUN, 0.5f);
                        me->GetMotionMaster()->MoveBackward(POINT_MAIN_DOOR, chargePos[baseMovement + 1].GetPositionX(), chargePos[baseMovement + 1].GetPositionY(), chargePos[baseMovement + 1].GetPositionZ(), 1.0f);
                        break;
                }
            }

            bool checkStartBattle()
            {
                if (inFight)
                    return false;

                if (!me->SelectNearestPlayer(25.0f))
                    return false;

                if (pInstance)
                    if (pInstance->GetData(DATA_RIMOK) != DONE)
                        return false;

                inFight = true;
                return true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!pInstance)
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    case EVENT_CHECK_WIPE:
                        if (pInstance->IsWipe())
                            Reset();
                        else
                            events.ScheduleEvent(EVENT_CHECK_WIPE, 1000);
                        break;
                    case EVENT_RAIGONN_CHARGE:
                        DoEventCharge();
                        break;
                    case EVENT_SUMMON_PROTECTORAT:
                    {
                        for (uint8 i = 0; i < 8; ++i)
                            if (Creature* summon = me->SummonCreature(NPC_KRIKTHIK_PROTECTORAT, frand(941.0f, 974.0f), 2374.85f, 296.67f, 4.73f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                    if (summon->IsAIEnabled)
                                        summon->AI()->AttackStart(target);

                        events.ScheduleEvent(EVENT_SUMMON_PROTECTORAT, urand(30000, 45000), PHASE_WEAK_SPOT);
                        break;
                    }
                    case EVENT_SUMMON_ENGULFER:
                    {
                        for (uint8 i = 0; i < 3; ++i)
                            me->SummonCreature(NPC_KRIKTHIK_ENGULFER, frand(941.0f, 974.0f), me->GetPositionY(), me->GetPositionZ() + 30.0f, 4.73f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);

                        events.ScheduleEvent(EVENT_SUMMON_ENGULFER, urand(95000, 105000), PHASE_WEAK_SPOT);
                        break;
                    }
                    case EVENT_SUMMON_SWARM_BRINGER:
                    {
                        if (Creature* summon = me->SummonCreature(NPC_KRIKTHIK_SWARM_BRINGER, frand(941.0f, 974.0f), 2374.85f, 296.67f, 4.73f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                if (summon->AI())
                                    summon->AI()->AttackStart(target);

                        events.ScheduleEvent(EVENT_SUMMON_ENGULFER, urand(35000, 50000), PHASE_WEAK_SPOT);
                        break;
                    }
                    case EVENT_FIXATE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        {
                            me->CastSpell(target, SPELL_FIXATE, true);

                            me->SetReactState(REACT_PASSIVE);
                            me->GetMotionMaster()->MoveChase(target);

                        }
                        events.ScheduleEvent(EVENT_FIXATE_STOP, 15000, PHASE_VULNERABILITY);
                        break;
                    }
                    case EVENT_FIXATE_STOP:
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->GetMotionMaster()->Clear();

                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            AttackStart(target);

                        events.ScheduleEvent(EVENT_FIXATE, 30000, PHASE_VULNERABILITY);
                        break;
                    }
                    case EVENT_STOMP:
                    {
                        me->CastSpell(me, SPELL_STOMP, false);
                        events.ScheduleEvent(EVENT_STOMP, 30000, PHASE_VULNERABILITY);
                        break;
                    }
                    default:
                        break;
                }

                if (Phase == PHASE_VULNERABILITY)
                    DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
                if (instance)
                {
                    instance->SetBossState(DATA_RAIGONN, DONE);
                    instance->SaveToDB();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_raigonnAI(creature);
        }
};

class npc_raigonn_weak_spot : public CreatureScript
{
    public:
        npc_raigonn_weak_spot() :  CreatureScript("npc_raigonn_weak_spot") { }

        struct npc_raigonn_weak_spotAI : public ScriptedAI
        {
            npc_raigonn_weak_spotAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                    if (pInstance)
                        if (Creature* Raigonn = pInstance->instance->GetCreature(pInstance->GetGuidData(NPC_RAIGONN)))
                            if (Raigonn->AI())
                                Raigonn->AI()->DoAction(ACTION_WEAK_SPOT_DEAD);
            }

            bool CanBeTargetedOutOfLOS() override
            {
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_raigonn_weak_spotAI(creature);
        }
};

class npc_krikthik_protectorat : public CreatureScript
{
    public:
        npc_krikthik_protectorat() :  CreatureScript("npc_krikthik_protectorat") { }

        struct npc_krikthik_protectoratAI : public ScriptedAI
        {
            npc_krikthik_protectoratAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            bool hasCastHiveMind;

            void Reset() override
            {
                hasCastHiveMind = false;
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (!hasCastHiveMind && me->HealthBelowPctDamaged(20, damage))
                    me->CastSpell(me, SPELL_HIVE_MIND, true);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_krikthik_protectoratAI(creature);
        }
};

class npc_krikthik_engulfer : public CreatureScript
{
    public:
        npc_krikthik_engulfer() :  CreatureScript("npc_krikthik_engulfer") { }

        struct npc_krikthik_engulferAI : public ScriptedAI
        {
            npc_krikthik_engulferAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 engulfingTimer;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveRandom(25.0f);
                DoZoneInCombat();

                engulfingTimer = 10000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (engulfingTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        me->CastSpell(target, SPELL_ENGULFING_WINDS, false);

                    engulfingTimer = urand(7500, 12500);
                }
                else engulfingTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_krikthik_engulferAI(creature);
        }
};

class npc_krikthik_swarm_bringer : public CreatureScript
{
    public:
        npc_krikthik_swarm_bringer() :  CreatureScript("npc_krikthik_swarm_bringer") { }

        struct npc_krikthik_swarm_bringerAI : public ScriptedAI
        {
            npc_krikthik_swarm_bringerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 swarmTimer;

            void Reset() override
            {
                DoZoneInCombat();
                swarmTimer = 10000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (swarmTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        me->CastSpell(target, SPELL_SCREECHING_SWARM, false);

                    swarmTimer = urand(17500, 22500);
                }
                else swarmTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_krikthik_swarm_bringerAI(creature);
        }
};

class vehicle_artillery : public VehicleScript
{
    public:
        vehicle_artillery() : VehicleScript("vehicle_artillery") {}

        void OnAddPassenger(Vehicle* veh, Unit* /*passenger*/, int8 /*seatId*/) override
        {
            if (veh->GetBase())
                if (veh->GetBase()->ToCreature())
                    if (veh->GetBase()->ToCreature()->AI())
                        veh->GetBase()->ToCreature()->AI()->DoAction(0);
        }

        struct vehicle_artilleryAI : public ScriptedAI
        {
            vehicle_artilleryAI(Creature* creature) : ScriptedAI(creature)
            {
               pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 launchEventTimer;

            void Reset() override
            {
                launchEventTimer = 0;
            }

            void DoAction(int32 /*action*/) override
            {
                launchEventTimer = 2500;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!launchEventTimer)
                    return;

                if (launchEventTimer <= diff)
                {
                    if (Creature* weakSpot = pInstance->instance->GetCreature(pInstance->GetGuidData(NPC_WEAK_SPOT)))
                    {
                        if (weakSpot->GetVehicleKit())
                        {
                            if (me->GetVehicleKit())
                            {
                                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                                {
                                    passenger->ExitVehicle();

                                    const uint32 maxSeatCount = 2;
                                    uint32 availableSeatCount = weakSpot->GetVehicleKit()->GetAvailableSeatCount();
                                    passenger->EnterVehicle(weakSpot,  maxSeatCount - availableSeatCount);
                                }
                            }
                        }
                    }

                    launchEventTimer = 0;
                }
                else launchEventTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new vehicle_artilleryAI(creature);
        }
};

void AddSC_boss_raigonn()
{
    new boss_raigonn();
    new npc_raigonn_weak_spot();
    new npc_krikthik_protectorat();
    new npc_krikthik_engulfer();
    new npc_krikthik_swarm_bringer();
    new vehicle_artillery();
}
