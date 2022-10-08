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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "maw_of_souls.h"
#include "Vehicle.h"
#include "GameObject.h"
#include "SpellHistory.h"
#include "SpellPackets.h"
#include <G3D/ConvexPolyhedron.h>
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "SpellAuras.h"

enum Spells
{
    // Helya
    SPELL_SUBMERGED = 196947,
    SPELL_PIERCING_TENTACLE_TARGETING = 197597,
    SPELL_TAINT_OF_SEA = 197262,
    SPELL_TAINT_OF_SEA_DISPEL_DMG = 197264,
    SPELL_TAINTED_ESSENCE_TRIGGER = 202470,
    SPELL_TAINTED_ESSENCE_DMG = 202472,
    SPELL_TORRENT = 197805,
    SPELL_TURBULENT_WATERS_AURA = 197753,
    SPELL_TURBULENT_WATERS_MISSILE = 197752,
    SPELL_TURBULENT_WATERS_DMG = 197858,
    SPELL_BRACKWATER_BARRAGE = 202088,
    SPELL_BRACKWATER_BARRAGE_DMG = 202098,

    // Phase Two
    SPELL_TORRENT_INTERRUPTIBLE = 198495,
    SPELL_WING_BUFFET = 198520,
    SPELL_CORRUPTED_BELLOW = 227233,
    SPELL_HELYA_EMERGE = 195231,
    SPELL_HELYA_MODEL_PHASE_TWO = 197734,
    SPELL_SMASH_HELYA = 197677,
    SPELL_SMASH_HELYA_MISSILE = 197689,
    SPELL_SMASH_HELYA_KNOCK = 197653,

    // Destructor Tentacle
    SPELL_SMASH = 196534,
    SPELL_RAPID_RUPTURE = 197952,
    SPELL_RAPID_RUPTURE_AURA = 185539,

    // Grasping Tentacle
    SPELL_RIDE_VEHICLE = 46598,
    SPELL_HELYA_TENTACLE = 198180,
    SPELL_HELYA_TENTACLE_2 = 196450,

    // Piercing Tentacle
    SPELL_PIERCING_TENTACLE = 197112,
    SPELL_PIERCING_TENTACLE_DMG = 197117,
    SPELL_SWIRLING_POOL = 195167,
    SPELL_SWRILING_WATER = 195309,
    SPELL_KNOCKDOWN = 194839,
};

enum Events
{
    // First Phase
    EVENT_DESTRUCTOR_TENTACLE = 1,
    EVENT_GRASPING_TENTACLE = 2,
    EVENT_TAINT_OF_SEA = 3,
    EVENT_BRACKWATER_BARRAGE = 4,
    EVENT_PIERCING_TENTACLE = 5,
    EVENT_SUBMERGED = 6,

    // Second Phase
    EVENT_SECOND_PHASE = 7,
    EVENT_CORRUPTED_BELLOW = 8,
    EVENT_TORRENT = 9,
    EVENT_WING_BUFFET = 10,

    // Destructor Tentacle
    EVENT_SMASH = 11,
    EVENT_RAPID_RUPTURE = 12,

};

enum Adds
{
    NPC_PIERCING_TENTACLE = 100188,
    NPC_DESTRUCTOR_TENTACLE = 99801,
    NPC_DESTRUCTOR_TENTACLE_DUMMY = 99803,
    NPC_GRASPING_TENTACLE = 100360,
    NPC_GRASPING_TENTACLE_2 = 100362,
    NPC_GRASPING_TENTACLE_3 = 98363,
    NPC_GRASPING_TENTACLE_DUMMY = 100359,
    NPC_GRASPING_TENTACLE_DUMMY_2 = 100361,
    NPC_GRASPING_TENTACLE_DUMMY_3 = 99800,
    NPC_SWIRLING_POOL_DUMMY = 97099,
    NPC_SWIRLING_POOL_DUMMY_2 = 102306,
    NPC_CORRUPTED_BELLOW_DUMMY = 59018,
};

enum Says
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_TAINT = 2,
    SAY_TENTACLE = 3,
    SAY_CORRUPTED = 4,
    SAY_KILL = 5,
    SAY_WIPE = 6,
    SAY_DEATH = 7,
    SAY_BRACKWATER = 8,
    SAY_CORRUPTED_EMOTE = 10,
};

enum Actions
{
    ACTION_TENTACLE_DEAD = 1,
    ACTION_PIERCING_TENTACLE = 2,
};

constexpr uint32 BRACKWATER_BARRAGE_LEFT_ANIM = 52869;
constexpr uint32 BRACKWATER_BARRAGE_RIGHT_ANIM = 52870;
constexpr uint32 CORRUPTED_BELLOW_ANIM = 61273;

constexpr uint32 DATA_BRACKWATER_SIDE = 1;
constexpr uint32 DATA_CORRUPTED_BELLOW_SIDE = 2;

uint32 TrapDoor[] =
{
    GO_TRAP_DOOR_01,
    GO_TRAP_DOOR_02,
    GO_TRAP_DOOR_03,
    GO_TRAP_DOOR_04,
    GO_TRAP_DOOR_05,
    GO_TRAP_DOOR_06,
    GO_TRAP_DOOR_07,
    GO_TRAP_DOOR_09,
    GO_TRAP_DOOR_10,
    GO_TRAP_DOOR_11,
};

uint32 TrapDoorSecondPhase[] =
{
    GO_TRAP_DOOR_01,
    GO_TRAP_DOOR_02,
    GO_TRAP_DOOR_03,
    GO_TRAP_DOOR_04,
    GO_TRAP_DOOR_06,
    GO_TRAP_DOOR_07,
    GO_TRAP_DOOR_11,
};

const Position CombatPositionPhaseTwo = { 2933.5f, 961.792f, 512.0f, 4.712389f };
const Position BrackWaterBarrageVisualPos = { 2934.499f, 1055.943f, 510.5183f };

const Position JumpingPosPhaseTwo[] =
{
    { 2951.605f, 914.6163f, 512.9623f },
{ 2946.643f, 914.5208f, 512.8687f },
{ 2954.132f, 914.6719f, 512.838f },
{ 2951.605f, 914.6163f, 512.9623f },
{ 2951.469f, 924.5151f, 512.2851f },
};

const Position CorruptedBellowPos[] =
{
    { 2918.5f, 935.8112f, 512.332f, 4.18879f }, // Left
{ 2933.5f, 931.792f, 512.332f, 4.712389f }, // Mid
{ 2948.5f, 935.8112f, 512.332f, 5.23f },    // Right
};

const Position BrackWaterBarrageRight[] =
{
    { 2926.323f, 954.963f, 512.336f },
{ 2922.935f, 933.973f, 512.339f },
{ 2921.662f, 920.746f, 512.319f },
};

const Position BrackWaterBarrageLeft[] =
{
    { 2941.427f, 953.688f, 512.336f },
{ 2942.143f, 939.082f, 512.323f },
{ 2944.178f, 923.068f, 512.412f },
};

Position CorruptedBellowMidVisualPacketPos[] =
{
    { 2926.093f, 938.0075f,  512.332f },
{ 2932.856f, 936.2736f,  512.332f },
{ 2939.905f, 937.373f,  512.332f },
{ 2925.066f, 933.538f,  512.332f },
{ 2933.052f, 932.4249f,  512.332f },
{ 2940.663f, 933.2015f,  512.332f },
{ 2923.892f, 929.2588f,  512.332f },
{ 2929.537f, 927.931f,  512.332f },
{ 2935.557f, 927.357f,  512.332f },
{ 2941.715f, 928.4929f,  512.332f },
{ 2922.882f, 924.9178f,  512.332f },
{ 2929.581f, 923.3671f,  512.332f },
{ 2935.623f, 923.5207f,  512.332f },
{ 2942.438f, 924.9455f,  512.332f },
{ 2921.475f, 920.1981f,  512.332f },
{ 2926.588f, 919.7137f,  512.332f },
{ 2932.152f, 919.1714f,  512.332f },
{ 2938.219f, 918.7126f,  512.332f },
{ 2944.007f, 920.145f,  512.332f },
{ 2920.565f, 916.2735f,  512.332f },
{ 2926.06f, 14.7321f,  512.332f },
{ 2932.37f, 14.3811f,  512.332f },
{ 2938.812f, 914.1826f,  512.332f },
{ 2944.204f, 915.7855f,  512.332f },
};

Position CorruptedBellowRightVisualPacketPos[] =
{
    { 2940.244f,  937.6467f, 512.332f },
{ 2946.176f,  940.5653f, 512.332f },
{ 2951.501f,  943.9856f, 512.332f },
{ 2940.84f,  933.6932f, 512.332f },
{ 2948.65f,  935.9445f, 512.332f },
{ 2954.534f,  940.79f, 512.332f },
{ 2941.993f,  928.8289f, 512.332f },
{ 2947.367f,  930.741f, 512.332f },
{ 2953.447f,  934.0718f, 512.332f },
{ 2957.582f,  938.2676f, 512.332f },
{ 2943.735f,  924.3937f, 512.332f },
{ 2949.589f,  927.2983f, 512.332f },
{ 2955.588f,  930.3094f, 512.332f },
{ 2960.539f,  934.8585f, 512.332f },
{ 2944.431f,  920.7468f, 512.332f },
{ 2950.383f,  921.7795f, 512.332f },
{ 2955.09f,  924.2549f, 512.332f },
{ 2959.828f,  928.2885f, 512.332f },
{ 2963.685f,  931.6357f, 512.332f },
{ 2945.518f,  916.344f, 512.332f },
{ 2951.708f,  917.4258f, 512.332f },
{ 2956.785f,  920.8843f, 512.332f },
{ 2962.582f,  924.3431f, 512.332f },
{ 2967.163f,  928.5035f, 512.332f },
};

Position CorruptedBellowLeftVisualPacketPos[] =
{
    { 2916.247f, 943.9583f, 512.332f },
{ 2921.348f, 940.188f, 512.332f },
{ 2926.536f, 937.4523f, 512.332f },
{ 2912.938f, 941.2333f, 512.332f },
{ 2919.143f, 936.2292f, 512.332f },
{ 2925.388f, 933.0137f, 512.332f },
{ 2909.453f, 938.0602f, 512.332f },
{ 2913.688f, 934.0811f, 512.332f },
{ 2918.845f, 931.1264f, 512.332f },
{ 2924.693f, 928.9584f, 512.332f },
{ 2906.485f, 934.7266f, 512.332f },
{ 2911.516f, 929.8664f, 512.332f },
{ 2917.21f, 926.6036f, 512.332f },
{ 2923.307f, 925.0822f, 512.332f },
{ 2903.385f, 931.6449f, 512.332f },
{ 2906.978f, 927.9473f, 512.332f },
{ 2912.381f, 924.1951f, 512.332f },
{ 2917.106f, 922.7062f, 512.332f },
{ 2922.387f, 920.3773f, 512.332f },
{ 2899.681f, 927.7511f, 512.332f },
{ 2904.948f, 924.1798f, 512.332f },
{ 2909.838f, 920.5865f, 512.332f },
{ 2915.148f, 917.9834f, 512.332f },
{ 2920.968f, 916.4552f, 512.332f },
};

class boss_helya_maw : public CreatureScript
{
public:
    boss_helya_maw() : CreatureScript("boss_helya_maw")
    {}

    struct boss_helya_maw_AI : public BossAI
    {
        boss_helya_maw_AI(Creature* creature) : BossAI(creature, DATA_HELYA)
        {
            me->SetDisableGravity(true);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        void Reset() override
        {
            me->SetDisableGravity(true);
            me->AddUnitState(UNIT_STATE_ROOT);
            _Reset();
            _submerged = false;
            _secondPhase = false;
            Initialize();
        }

        void EnterEvadeMode(EvadeReason reason) override
        {
            for (auto & it : _pools)
            {
                it->RemoveAllAreaTriggers();
                it->RemoveAurasDueToSpell(SPELL_SWIRLING_POOL);
            }

            _pools.clear();
            _destructors.clear();
            _graspings.clear();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            RestoreShip();
            _EnterEvadeMode();
            me->NearTeleportTo(me->GetHomePosition());
            JustReachedHome();
            Reset();
        }

        void RestoreShip()
        {
            for (uint8 i = 0; i < 10; ++i)
            {
                if (GameObject* trapDoor = me->FindNearestGameObject(TrapDoor[i], 500.0f))
                    trapDoor->SetGoState(GO_STATE_READY);
            }

            if (GameObject* ship = me->FindNearestGameObject(GO_NAGLFAR, 500.0f))
                ship->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);
        }

        void JustReachedHome() override
        {
            Talk(SAY_WIPE);
            _JustReachedHome();
        }

        void DamageTaken(Unit* /**/, uint32 &) override
        {
            if (me->HealthBelowPct(80) && !_submerged)
            {
                _submerged = true;
                events.Reset();
                events.ScheduleEvent(EVENT_SUBMERGED, Seconds(1));
            }
            else if (me->HealthBelowPct(70) && _submerged && me->HasReactState(REACT_AGGRESSIVE))
                FinalizeEncounter();
        }

        void Initialize()
        {
            me->GetCreatureListWithEntryInGrid(_destructors, NPC_DESTRUCTOR_TENTACLE_DUMMY);
            me->GetCreatureListWithEntryInGrid(_pools, NPC_SWIRLING_POOL_DUMMY);
            me->GetCreatureListWithEntryInGrid(_pools, NPC_SWIRLING_POOL_DUMMY_2);
            me->GetCreatureListWithEntryInGrid(_graspings, NPC_GRASPING_TENTACLE_DUMMY);
            me->GetCreatureListWithEntryInGrid(_graspings, NPC_GRASPING_TENTACLE_DUMMY_2);
            me->GetCreatureListWithEntryInGrid(_graspings, NPC_GRASPING_TENTACLE_DUMMY_3);

            Creature* destructor = nullptr;
            Creature* grasp_one = nullptr;
            Creature* grasp_two = nullptr;
            Creature* tentacle = nullptr;

            grasp_one = me->FindNearestCreature(NPC_GRASPING_TENTACLE_DUMMY, 250.0f);
            grasp_two = me->FindNearestCreature(NPC_GRASPING_TENTACLE_DUMMY_3, 250.0f);

            if (grasp_one)
            {
                tentacle = DoSummon(NPC_GRASPING_TENTACLE, grasp_one->GetPosition(), 5 * IN_MILLISECONDS);

                if (tentacle)
                    tentacle->EnterVehicle(grasp_one);
            }

            if (grasp_two)
            {
                tentacle = DoSummon(NPC_GRASPING_TENTACLE_3, grasp_two->GetPosition(), 5 * IN_MILLISECONDS);

                if (tentacle)
                    tentacle->EnterVehicle(grasp_two);
            }

            destructor = me->FindNearestCreature(NPC_DESTRUCTOR_TENTACLE_DUMMY, 250.0f);

            if (destructor)
            {
                tentacle = DoSummon(NPC_DESTRUCTOR_TENTACLE, destructor->GetPosition(), 5 * IN_MILLISECONDS);
                DestroyTrapDoor(destructor);

                if (tentacle)
                    tentacle->EnterVehicle(destructor);
            }
        }

        Creature* FindAvailableDummy(uint32 id)
        {
            switch (id)
            {
            case NPC_GRASPING_TENTACLE_DUMMY:
                return Trinity::Containers::SelectRandomContainerElement(_graspings);

            case NPC_DESTRUCTOR_TENTACLE_DUMMY:
                return Trinity::Containers::SelectRandomContainerElement(_destructors);

            case NPC_SWIRLING_POOL_DUMMY:
                return Trinity::Containers::SelectRandomContainerElement(_pools);

            default: return nullptr;
            }
        }

        Creature* SummonTentacle(uint32 id)
        {
            Creature* dummy = FindAvailableDummy(id);
            Creature* tentacle = nullptr;

            if (!dummy)
                return nullptr;

            Vehicle* vec = dummy->GetVehicleKit();

            if (vec && !vec->IsVehicleInUse())
            {
                switch (dummy->GetEntry())
                {
                case NPC_GRASPING_TENTACLE_DUMMY:
                    tentacle = DoSummon(NPC_GRASPING_TENTACLE, dummy->GetPosition(), 5 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    break;

                case NPC_GRASPING_TENTACLE_DUMMY_2:
                    tentacle = DoSummon(NPC_GRASPING_TENTACLE_2, dummy->GetPosition(), 5 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    break;

                case NPC_GRASPING_TENTACLE_DUMMY_3:
                    tentacle = DoSummon(NPC_GRASPING_TENTACLE_3, dummy->GetPosition(), 5 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    break;

                case NPC_DESTRUCTOR_TENTACLE_DUMMY:
                {
                    DestroyTrapDoor(dummy);
                    tentacle = DoSummon(NPC_DESTRUCTOR_TENTACLE, dummy->GetPosition(), 5 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    break;
                }


                default: break;
                }
            }
            else
                return nullptr;

            if (tentacle)
                tentacle->EnterVehicle(vec->GetBase());

            return tentacle;
        }

        uint32 GetData(uint32 id) const override
        {
            if (id == DATA_BRACKWATER_SIDE)
                return _brackwaterSide;
            else if (id == DATA_CORRUPTED_BELLOW_SIDE)
                return _bellowSide;

            return 0;
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_TENTACLE_DEAD && !_submerged)
            {
                me->SetHealth(me->GetHealth() - (me->GetHealth() * 0.033));
                Talk(SAY_TENTACLE);
                uint32 dmg = 0;
                DamageTaken(nullptr, dmg);
            }
            else if (action == ACTION_PIERCING_TENTACLE)
            {
                GameObject* ship = me->FindNearestGameObject(GO_NAGLFAR, 250.f);

                if (ship && ship->GetDestructibleState() == GO_DESTRUCTIBLE_DESTROYED)
                {
                    GameObject* door = me->FindNearestGameObject(TrapDoorSecondPhase[urand(0, 6)], 100.f);

                    if (door && door->GetGoState() == GO_STATE_ACTIVE)
                        DoSummon(NPC_PIERCING_TENTACLE, door->GetPosition(), 10 * IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN);
                }
                else
                {
                    auto* dummy = FindAvailableDummy(NPC_SWIRLING_POOL_DUMMY);

                    if (dummy)
                    {
                        DestroyTrapDoor(dummy);
                        DoSummon(NPC_PIERCING_TENTACLE, dummy->GetPosition(), 10 * IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN);
                    }
                }
            }
        }

        void FinalizeEncounter()
        {
            Talk(SAY_DEATH);
            me->SetReactState(REACT_PASSIVE);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.Reset();

            _pools.clear();
            _destructors.clear();
            _graspings.clear();

            instance->SetBossState(DATA_HELYA, DONE);
            summons.DespawnAll();
            me->CastStop();
            me->AttackStop();
            me->DespawnOrUnsummon(5000);

            _destructors.clear();
            _graspings.clear();
            _pools.clear();
        }

        void EnterCombat(Unit* /**/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            _secondPhase = false;
            _submerged = false;
            events.ScheduleEvent(EVENT_GRASPING_TENTACLE, Seconds(15));
            events.ScheduleEvent(EVENT_DESTRUCTOR_TENTACLE, Seconds(50));
            events.ScheduleEvent(EVENT_TAINT_OF_SEA, Seconds(12));
            events.ScheduleEvent(EVENT_TORRENT, Seconds(6));
            events.ScheduleEvent(EVENT_PIERCING_TENTACLE, Seconds(15));

            if (IsHeroic())
                events.ScheduleEvent(EVENT_BRACKWATER_BARRAGE, Seconds(40));

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void DestroyTrapDoor(Creature* pool_near)
        {
            for (uint8 i = 0; i < 10; ++i)
            {
                if (GameObject* trapDoor = pool_near->FindNearestGameObject(TrapDoor[i], 5.0f))
                {
                    if (trapDoor->GetGoState() != GO_STATE_ACTIVE)
                    {
                        pool_near->CastSpell(pool_near, SPELL_SWIRLING_POOL, true);
                        trapDoor->SetGoState(GO_STATE_ACTIVE);
                        break;
                    }
                }
            }
        }

        void DestroyRestantShip()
        {
            if (GameObject* ship = me->FindNearestGameObject(GO_NAGLFAR, 1000.0f))
                ship->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

            for (auto & it : _pools)
            {
                if (it->GetExactDist2d(CombatPositionPhaseTwo) <= 22.f)
                {
                    it->RemoveAllAreaTriggers();
                    it->RemoveAurasDueToSpell(SPELL_SWIRLING_POOL);
                }
            }

        }

        void ExecuteEvent(uint32 eventId) override
        {
            me->GetSpellHistory()->ResetAllCooldowns();

            switch (eventId)
            {
            case EVENT_GRASPING_TENTACLE:
            {
                if (SummonTentacle(NPC_GRASPING_TENTACLE_DUMMY))
                    events.ScheduleEvent(EVENT_GRASPING_TENTACLE, Seconds(30));
                else
                    events.ScheduleEvent(EVENT_GRASPING_TENTACLE, Seconds(5));

                break;
            }

            case EVENT_DESTRUCTOR_TENTACLE:
            {
                if (SummonTentacle(NPC_DESTRUCTOR_TENTACLE_DUMMY))
                    events.ScheduleEvent(EVENT_DESTRUCTOR_TENTACLE, Seconds(35));
                else
                    events.ScheduleEvent(EVENT_DESTRUCTOR_TENTACLE, Seconds(5));
                break;
            }

            case EVENT_PIERCING_TENTACLE:
            {
                if (Creature* pool = FindAvailableDummy(NPC_SWIRLING_POOL_DUMMY))
                {
                    if (pool->FindNearestCreature(NPC_DESTRUCTOR_TENTACLE, 5.0f))
                    {
                        events.ScheduleEvent(EVENT_PIERCING_TENTACLE, Seconds(5));
                        break;
                    }
                    DestroyTrapDoor(pool);
                    DoSummon(NPC_PIERCING_TENTACLE, pool->GetPosition(), 10 * IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN);
                }
                events.ScheduleEvent(EVENT_PIERCING_TENTACLE, Seconds(20));
                break;
            }

            case EVENT_BRACKWATER_BARRAGE:
            {
                _brackwaterSide = urand(BRACKWATER_BARRAGE_LEFT_ANIM, BRACKWATER_BARRAGE_RIGHT_ANIM);

                Talk(SAY_BRACKWATER);
                DoCast(me, SPELL_BRACKWATER_BARRAGE);

                std::list<Player*> players;
                me->GetPlayerListInGrid(players, 250.f);
                Position pos(BrackWaterBarrageVisualPos);

                for (auto& it : players)
                    me->SendPlaySpellVisual(pos, _brackwaterSide, 0, 0, 9.0f, true);

                events.ScheduleEvent(EVENT_BRACKWATER_BARRAGE, Seconds(55));
                break;
            }

            case EVENT_TAINT_OF_SEA:
            {
                Talk(SAY_TAINT);
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true));

                if (target)
                    DoCast(target, SPELL_TAINT_OF_SEA);
                else
                    DoCastVictim(SPELL_TAINT_OF_SEA);

                events.ScheduleEvent(EVENT_TAINT_OF_SEA, Seconds(12));
                break;
            }

            case EVENT_SUBMERGED:
            {
                summons.DespawnAll();
                DoCast(me, SPELL_SUBMERGED, true);

                if (!_secondPhase)
                    events.ScheduleEvent(EVENT_SECOND_PHASE, Seconds(16));

                events.ScheduleEvent(EVENT_SUBMERGED, Seconds(90));
                break;
            }

            case EVENT_SECOND_PHASE:
            {
                _secondPhase = true;
                me->RemoveAurasDueToSpell(SPELL_TURBULENT_WATERS_AURA);

                DoCast(me, SPELL_HELYA_MODEL_PHASE_TWO, true);

                me->SetDisableGravity(true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

                DoCast(me, SPELL_HELYA_EMERGE, true);
                DoCast(me, SPELL_SMASH_HELYA, true);
                DestroyRestantShip();

                events.ScheduleEvent(EVENT_CORRUPTED_BELLOW, Seconds(18));
                events.ScheduleEvent(EVENT_TORRENT, Seconds(6));
                events.ScheduleEvent(EVENT_TAINT_OF_SEA, Seconds(12));
                events.ScheduleEvent(EVENT_WING_BUFFET, Seconds(5));

                break;
            }

            case EVENT_CORRUPTED_BELLOW:
            {
                Talk(SAY_CORRUPTED);
                Talk(SAY_CORRUPTED_EMOTE);

                _bellowSide = urand(0, 2);
                Position pos = CorruptedBellowPos[_bellowSide];

                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->SetFacingTo(pos.GetOrientation(), true);
                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_CORRUPTED_BELLOW, false);
                events.ScheduleEvent(EVENT_CORRUPTED_BELLOW, Seconds(20));
                break;
            }

            case EVENT_WING_BUFFET:
            {
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                    DoCast(me, SPELL_WING_BUFFET);

                events.ScheduleEvent(EVENT_WING_BUFFET, 1500);
                break;
            }

            case EVENT_TORRENT:
            {
                if (_submerged)
                    DoCast(me, SPELL_TORRENT_INTERRUPTIBLE);
                else
                    DoCast(me, SPELL_TORRENT);

                events.ScheduleEvent(EVENT_TORRENT, Seconds(urand(10, 15)));

                break;
            }
            }
        }

    private:
        uint32 _bellowSide;
        uint32 _brackwaterSide;
        std::list<Creature*> _pools, _destructors, _graspings;
        bool _submerged, _secondPhase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_helya_maw_AI(creature);
    }
};

class npc_mos_grasping_tentacle : public CreatureScript
{
public:
    npc_mos_grasping_tentacle() : CreatureScript("npc_mos_grasping_tentacle")
    {}

    struct npc_mos_grasping_tentacle_AI : public ScriptedAI
    {
        npc_mos_grasping_tentacle_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetCollision(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
        }

        void Reset() override
        {
            me->SetDisableGravity(true);
            me->SetCollision(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
        }

        void EnterCombat(Unit* /**/) override
        {
            if (Creature* helya = me->FindNearestCreature(BOSS_HELYA, 250.0f))
                DoZoneInCombat(helya);
        }

        void JustDied(Unit* /**/) override
        {
            if (Creature* helya = me->FindNearestCreature(BOSS_HELYA, 500.0f))
                helya->GetAI()->DoAction(ACTION_TENTACLE_DEAD);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mos_grasping_tentacle_AI(creature);
    }
};

class npc_mos_destructor_tentacle : public CreatureScript
{
public:
    npc_mos_destructor_tentacle() : CreatureScript("npc_mos_destructor_tentacle")
    {}

    struct npc_mos_destructor_tentacle_AI : public ScriptedAI
    {
        npc_mos_destructor_tentacle_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetCollision(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
        }

        void Reset() override
        {
            me->SetDisableGravity(true);
            me->SetCollision(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            _events.Reset();
        }

        void JustDied(Unit* /**/) override
        {
            if (Creature* helya = me->FindNearestCreature(BOSS_HELYA, 500.0f))
                helya->GetAI()->DoAction(ACTION_TENTACLE_DEAD);
        }

        void EnterCombat(Unit* /**/) override
        {
            if (Creature* helya = me->FindNearestCreature(BOSS_HELYA, 250.0f))
                DoZoneInCombat(helya);

            _events.ScheduleEvent(EVENT_SMASH, Seconds(5));
            _events.ScheduleEvent(EVENT_RAPID_RUPTURE, Seconds(4));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                if (eventId == EVENT_SMASH)
                {
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCast(me, SPELL_SMASH);

                    _events.ScheduleEvent(EVENT_SMASH, 100);
                }
                else if (eventId == EVENT_RAPID_RUPTURE)
                {
                    for (uint8 i = 0; i < 3; ++i)
                        DoCastVictim(SPELL_RAPID_RUPTURE);

                    DoCastVictim(SPELL_RAPID_RUPTURE_AURA);
                    _events.ScheduleEvent(EVENT_RAPID_RUPTURE, Seconds(urand(10, 13)));
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mos_destructor_tentacle_AI(creature);
    }
};

class npc_mos_piercing_tentacle : public CreatureScript
{
public:
    npc_mos_piercing_tentacle() : CreatureScript("npc_mos_piercing_tentacle")
    {}

    struct npc_mos_piercing_tentacle_AI : public ScriptedAI
    {
    public:
        npc_mos_piercing_tentacle_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }

        void DoAction(int32 action) override
        {
        }

        void IsSummonedBy(Unit* /**/) override
        {
            DoCast(me, SPELL_PIERCING_TENTACLE);
            _events.ScheduleEvent(EVENT_PIERCING_TENTACLE, Seconds(3));
        }

        void EnterEvadeMode(EvadeReason) override
        {

        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                if (eventId == EVENT_PIERCING_TENTACLE)
                    DoCast(me, SPELL_PIERCING_TENTACLE_DMG);
            }
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mos_piercing_tentacle_AI(creature);
    }
};

class npc_mos_helya_dummy : public CreatureScript
{
public:
    npc_mos_helya_dummy() : CreatureScript("npc_mos_helya_dummy")
    {}

    struct npc_mos_helya_dummy_AI : public ScriptedAI
    {
        npc_mos_helya_dummy_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetCollision(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

            if (me->GetEntry() == NPC_SWIRLING_POOL_DUMMY || me->GetEntry() == NPC_SWIRLING_POOL_DUMMY_2)
            {
                me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_NO_STRAFE | MOVEMENTFLAG2_NO_JUMPING | MOVEMENTFLAG2_FULL_SPEED_TURNING);
            }
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool /*apply*/) override
        {
            if (!passenger)
                return;

            switch (passenger->GetEntry())
            {
            case NPC_GRASPING_TENTACLE:
            case NPC_GRASPING_TENTACLE_2:
                passenger->CastSpell(passenger, SPELL_HELYA_TENTACLE, true);
                break;

            case NPC_GRASPING_TENTACLE_3:
                passenger->CastSpell(passenger, SPELL_HELYA_TENTACLE_2, true);
                break;

            default: break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mos_helya_dummy_AI(creature);
    }
};

class at_mos_swirling_water : public AreaTriggerEntityScript
{
public:
    at_mos_swirling_water() : AreaTriggerEntityScript("at_mos_swirling_water")
    {}

    struct at_mos_swirling_water_AI : public AreaTriggerAI
    {
        at_mos_swirling_water_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {}

        void OnUnitEnter(Unit* unit) override
        {
            if (!unit)
                return;

            if (unit->GetTypeId() == TYPEID_PLAYER)
            {
                unit->CastSpell(unit, SPELL_KNOCKDOWN, true);
                unit->CastSpell(unit, SPELL_SWRILING_WATER, true);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_mos_swirling_water_AI(at);
    }
};

class spell_helya_maw_taint_of_sea : public SpellScriptLoader
{
public:
    spell_helya_maw_taint_of_sea() : SpellScriptLoader("spell_helya_maw_taint_of_sea")
    {}

    class spell_helya_maw_taint_of_sea_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_helya_maw_taint_of_sea_AuraScript);

        void HandleDispel(DispelInfo* dispelInfo)
        {
            if (!GetCaster() || !GetUnitOwner())
                return;

            Unit* caster = GetCaster();
            Unit* owner = GetUnitOwner();

            if (caster->GetMap()->IsHeroic())
                caster->CastSpell(owner, SPELL_TAINTED_ESSENCE_TRIGGER, true);
            else
                caster->CastSpell(owner, SPELL_TAINT_OF_SEA_DISPEL_DMG, true);
        }

        void Register() override
        {
            OnDispel += AuraDispelFn(spell_helya_maw_taint_of_sea_AuraScript::HandleDispel);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_helya_maw_taint_of_sea_AuraScript();
    }
};

class spell_helya_maw_submerged : public SpellScriptLoader
{
public:
    spell_helya_maw_submerged() : SpellScriptLoader("spell_helya_maw_submerged")
    {}

    class spell_submerged_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_submerged_AuraScript);

        void HandleOnApply(AuraEffect const* /**/, AuraEffectHandleModes /**/)
        {
            if (GetCaster())
                GetCaster()->CastSpell(GetCaster(), SPELL_TURBULENT_WATERS_AURA, true);
        }

        void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
        {
            GetCaster()->RemoveAurasDueToSpell(SPELL_TURBULENT_WATERS_AURA);
            GetCaster()->NearTeleportTo(CombatPositionPhaseTwo, false);
        }

        void HandlePeriodic(AuraEffect const* /**/)
        {
            if (!GetCaster())
                return;

            GetCaster()->GetAI()->DoAction(ACTION_PIERCING_TENTACLE);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_submerged_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_submerged_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_submerged_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_submerged_AuraScript();
    }
};

class spell_helya_maw_turbulent_waters : public SpellScriptLoader
{
public:
    spell_helya_maw_turbulent_waters() : SpellScriptLoader("spell_helya_maw_turbulent_waters")
    {}

    class spell_helya_maw_turbulent_waters_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_helya_maw_turbulent_waters_AuraScript);

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            Unit* caster = GetCaster();

            std::list<Creature*> creatures;

            caster->GetCreatureListWithEntryInGrid(creatures, NPC_SWIRLING_POOL_DUMMY_2, 500.f);

            if (creatures.empty())
                return;

            for (auto & it : creatures)
            {
                Position pos = it->GetNearPosition(10.0f, frand(0, 2 * float(M_PI)));
                caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_TURBULENT_WATERS_MISSILE, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_helya_maw_turbulent_waters_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_helya_maw_turbulent_waters_AuraScript();
    }
};

class spell_helya_maw_corrupted_bellow : public SpellScriptLoader
{
public:
    spell_helya_maw_corrupted_bellow() : SpellScriptLoader("spell_helya_maw_corrupted_bellow")
    {}

    class spell_helya_maw_corrupted_bellow_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_helya_maw_corrupted_bellow_AuraScript);

        using spell_corrupted_bellow = spell_helya_maw_corrupted_bellow_AuraScript;

        void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
        {
            if (GetCaster() && GetCaster()->ToCreature())
                GetCaster()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
        }

        void HandlePeriodic(AuraEffect const* /**/)
        {
            if (!GetCaster())
                return;

            std::list<Player*> players;
            GetCaster()->GetPlayerListInGrid(players, 150.f);

            if (players.empty())
                return;

            for (auto & it : players)
            {
                for (uint8 i = 0; i < 24; ++i)
                {
                    switch (GetCaster()->GetAI()->GetData(DATA_CORRUPTED_BELLOW_SIDE))
                    {
                        case 0:
                        {
                            GetCaster()->SendPlaySpellVisual(CorruptedBellowLeftVisualPacketPos[i], CORRUPTED_BELLOW_ANIM, 0, 0, 95.0f, false);
                            break;
                        }

                        case 1:
                        {
                            GetCaster()->SendPlaySpellVisual(CorruptedBellowMidVisualPacketPos[i], CORRUPTED_BELLOW_ANIM, 0, 0, 95.0f, false);
                            break;
                        }

                        case 2:
                        {
                            GetCaster()->SendPlaySpellVisual(CorruptedBellowRightVisualPacketPos[i], CORRUPTED_BELLOW_ANIM, 0, 0, 95.0f, false);
                            break;
                        }
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_corrupted_bellow::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            OnEffectRemove += AuraEffectRemoveFn(spell_corrupted_bellow::HandleOnRemove, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_helya_maw_corrupted_bellow_AuraScript();
    }
};

class spell_helya_maw_corrupted_bellow_dmg : public SpellScriptLoader
{
public:
    spell_helya_maw_corrupted_bellow_dmg() : SpellScriptLoader("spell_helya_maw_corrupted_bellow_dmg")
    {}


    class spell_helya_corrupted_bellow_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_helya_corrupted_bellow_SpellScript);

        void FilterTargets(SpellTargets& targets)
        {
            if (targets.empty())
                return;

            uint32 side = 0;

            targets.remove_if([&](WorldObject*& target)
            {
                return !GetCaster()->isInFront(target, float(M_PI) * 35.f / 180.f);
            });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_helya_corrupted_bellow_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_helya_corrupted_bellow_SpellScript();
    }
};

class spell_helya_maw_brackwater_barrage : public SpellScriptLoader
{
public:
    spell_helya_maw_brackwater_barrage() : SpellScriptLoader("spell_helya_maw_brackwater_barrage")
    {}

    class spell_helya_maw_brackwater_barrage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_helya_maw_brackwater_barrage_SpellScript);

        void HandleDummy(SpellEffIndex /**/)
        {
            if (!GetCaster())
                return;

            uint32 side = GetCaster()->GetAI()->GetData(DATA_BRACKWATER_SIDE);
            if (side == BRACKWATER_BARRAGE_LEFT_ANIM)
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    Position pos = BrackWaterBarrageLeft[i];
                    GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BRACKWATER_BARRAGE_DMG, true);
                }
            }
            else if (side == BRACKWATER_BARRAGE_RIGHT_ANIM)
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    Position pos = BrackWaterBarrageRight[i];
                    GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BRACKWATER_BARRAGE_DMG, true);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_helya_maw_brackwater_barrage_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_helya_maw_brackwater_barrage_SpellScript();
    }
};

class spell_helya_maw_phase_two_model : public SpellScriptLoader
{
public:
    spell_helya_maw_phase_two_model() : SpellScriptLoader("spell_helya_maw_phase_two_model")
    {}

    using spell_phase_two_model = spell_helya_maw_phase_two_model;

    class spell_phase_two_model_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_phase_two_model_SpellScript);

        void HandleTeleport()
        {
            if (!GetCaster())
                return;

            WorldLocation pos = GetCaster()->GetWorldLocation();
            pos.Relocate(CombatPositionPhaseTwo);

            SetExplTargetDest(pos);
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_phase_two_model_SpellScript::HandleTeleport);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_phase_two_model_SpellScript();
    }
};

class spell_helya_maw_wing_buffet : public SpellScriptLoader
{
public:
    spell_helya_maw_wing_buffet() : SpellScriptLoader("spell_helya_maw_wing_buffet")
    {}

    class spell_helya_maw_wing_buffet_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_helya_maw_wing_buffet_SpellScript);

        void CalculateDmg(SpellEffIndex /**/)
        {
            if (!GetCaster())
                return;

            Aura* wing = GetCaster()->GetAura(SPELL_WING_BUFFET);

            if (wing)
                SetHitDamage(GetHitDamage() * (1.0f + (wing->GetStackAmount() * 0.25f)));
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_helya_maw_wing_buffet_SpellScript::CalculateDmg, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_helya_maw_wing_buffet_SpellScript();
    }
};

class spell_helya_maw_knockdown : public SpellScriptLoader
{
public:
    spell_helya_maw_knockdown() : SpellScriptLoader("spell_helya_maw_knockdown")
    {}

    class spell_helya_maw_knockdown_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_helya_maw_knockdown_SpellScript);

        void HandleJumps()
        {
            if (!GetCaster())
                return;

            WorldLocation pos = GetCaster()->GetWorldLocation();

            pos.Relocate((JumpingPosPhaseTwo[urand(0, 4)]));
            SetExplTargetDest(pos);

        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_helya_maw_knockdown_SpellScript::HandleJumps);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_helya_maw_knockdown_SpellScript();
    }
};

class spell_mos_smash : public SpellScriptLoader
{
public:
    spell_mos_smash() : SpellScriptLoader("spell_mos_smash")
    {}

    class spell_mos_smash_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_mos_smash_SpellScript);

        void CalculateDmg(SpellEffIndex)
        {
            if (!GetCaster())
                return;

            Aura* smash = GetCaster()->GetAura(SPELL_SMASH);

            if (smash)
                SetHitDamage(GetEffectInfo(EFFECT_0)->BasePoints * (1.0f + (smash->GetStackAmount() * 0.20f)));
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_mos_smash_SpellScript::CalculateDmg, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mos_smash_SpellScript();
    }
};

class spell_mos_knockdown : public SpellScriptLoader
{
public:
    spell_mos_knockdown() : SpellScriptLoader("spell_mos_knockdown")
    {}

    class spell_mos_knockdown_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_mos_knockdown_SpellScript);

        void HandleJump()
        {
            if (!GetCaster())
                return;

            WorldLocation pos = GetCaster()->GetWorldLocation();

            float radius = 10.0f;

            pos.Relocate(GetCaster()->GetNearPosition(radius, frand(0, static_cast<float>(M_PI))));

            pos.m_positionZ += 2.0f;

            SetExplTargetDest(pos);
        }

        void Register()
        {
            BeforeCast += SpellCastFn(spell_mos_knockdown_SpellScript::HandleJump);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mos_knockdown_SpellScript();
    }
};

void AddSC_boss_helya_maw()
{
    new boss_helya_maw();

    //Creatures for Event
    new npc_mos_piercing_tentacle();
    new npc_mos_grasping_tentacle();
    new npc_mos_destructor_tentacle();
    new npc_mos_helya_dummy();
    new at_mos_swirling_water();

    // Spells for Bosses
    new spell_mos_knockdown();
    new spell_mos_smash();
    new spell_helya_maw_submerged();
    new spell_helya_maw_taint_of_sea();
    new spell_helya_maw_turbulent_waters();
    new spell_helya_maw_brackwater_barrage();
    new spell_helya_maw_phase_two_model();
    new spell_helya_maw_knockdown();
    new spell_helya_maw_corrupted_bellow();
    new spell_helya_maw_corrupted_bellow_dmg();
    new spell_helya_maw_wing_buffet();
    
}
