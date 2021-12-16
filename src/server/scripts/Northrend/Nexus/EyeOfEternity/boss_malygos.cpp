/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* Script Data Start
SDName: Boss Malygos
Script Data End */

#include "ScriptMgr.h"
#include "CombatAI.h"
#include "CreatureTextMgr.h"
#include "eye_of_eternity.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum Events
{
    // =========== INTRO BEFORE WE START ENCOUNTER ===============
    EVENT_STOP_PORTAL_BEAM           = 1,
    EVENT_RANDOM_PORTAL              = 2,
    EVENT_SAY_INTRO                  = 3,
    EVENT_LAND_START_ENCOUNTER       = 4,

    // =========== PHASE ONE ===============
    EVENT_ARCANE_BREATH              = 5,
    EVENT_ARCANE_STORM               = 6,
    EVENT_VORTEX                     = 7,
    EVENT_POWER_SPARKS               = 8,

    // =========== PHASE TWO ===============
    EVENT_FLY_OUT_OF_PLATFORM        = 9,
    EVENT_DELAYED_REINFORCEMENTS     = 10,
    EVENT_PATHING_AROUND_PLATFORM    = 11,
    EVENT_SURGE_OF_POWER_P_TWO       = 12,
    EVENT_SUMMON_ARCANE_BOMB         = 13,
    EVENT_MOVE_TO_POINT_SURGE_P_TWO  = 14,
    EVENT_LIGHT_DIMENSION_CHANGE     = 15,
    EVENT_MOVE_TO_P_THREE_POINT      = 16,
    EVENT_START_P_THREE              = 17,

    // =========== PHASE THREE =============
    EVENT_ARCANE_PULSE               = 18,
    EVENT_SURGE_OF_POWER_P_THREE     = 19,
    EVENT_STATIC_FIELD               = 20,

    // ========== MISC MECHANICS ===========
    EVENT_PREVENT_SAY_SPAM_ON_KILL   = 21,
    EVENT_MOVE_TO_VORTEX_POINT       = 22, // This should be fixed someday in core, we can't call new movement from MovementInform
    EVENT_START_FIRST_RANDOM_PORTAL  = 23, // There is something that is still loading when we first enter instance and it breaks
                                           // first visual cast of intro portal beam mechanic, so we need short delay from the event.
    EVENT_DELAY_MOVE_TO_DESTROY_P    = 24, // If Malygos is too close to destroy platform point and transition from II to III is hit,
                                           // this event will be sheduled to start after 5 seconds so there is enough time for "dimension change".

    // ============ NEXUS LORDS ============
    EVENT_ARCANE_SHOCK               = 1,
    EVENT_HASTE_BUFF                 = 2,
    EVENT_NUKE_DUMMY                 = 3,

    // ======== SCIONS OF ETERNITY =========
    EVENT_ARCANE_BARRAGE             = 1,

    // ======== WYRMREST SKYTALON ==========
    EVENT_CAST_RIDE_SPELL            = 1
};

enum Phases
{
    PHASE_NOT_STARTED      = 1,
    PHASE_ONE              = 2,
    PHASE_TWO              = 3,
    PHASE_THREE            = 4
};

enum Spells
{
    // Intro
    SPELL_RANDOM_PORTAL                      = 56047,
    SPELL_PORTAL_BEAM                        = 56046, // Malygos cast on portal to activate it during PHASE_NOT_STARTED

    //Phase I
    SPELL_BERSERK                           = 60670,
    SPELL_MALYGOS_BERSERK                    = 47008, // it's the berserk spell that will hit only Malygos after 10 min of 60670
    SPELL_PORTAL_VISUAL_CLOSED               = 55949,
    SPELL_SUMMON_POWER_PARK                  = 56142,
    SPELL_POWER_SPARK_DEATH                  = 55852,
    SPELL_POWER_SPARK_MALYGOS                = 56152,
    SPELL_ARCANE_BREATH                      = 56272,
    SPELL_ARCANE_STORM_P_I                   = 61693,
    SPELL_VORTEX_1                           = 56237, // seems that frezze object animation
    SPELL_VORTEX_2                           = 55873, // visual effect
    SPELL_VORTEX_3                           = 56105, // this spell must handle all the script - cast by the boss and to himself
    SPELL_VORTEX_6                           = 73040, // teleport - (cast to all raid), caster vortex bunnies, targets players.

    // Phase II
    SPELL_TELEPORT_VISUAL_ONLY               = 41232, // Light blue animation cast by arcane NPCs when spawned on Hover Disks
    SPELL_RIDE_HOVER_DISK                    = 61421,
    SPELL_ALIGN_DISK_AGGRO                   = 61210,
    SPELL_DUMMY_NUKE                         = 61215,
    SPELL_SUMMON_ARCANE_BOMB                 = 56429,
    SPELL_ARCANE_BOMB_TRIGGER                = 56430,
    SPELL_ARCANE_BOMB_KNOCKBACK_DAMAGE       = 56431,
    SPELL_ARCANE_OVERLOAD_1                  = 56432, // cast by npc Arcane Overload ID: 30282
    // SPELL_ARCANE_OVERLOAD_2               = 56435, // Triggered by 56432 - resizing target
    // SPELL_ARCANE_OVERLOAD_3               = 56438, // Triggered by 56432 - damage reduction
    SPELL_SURGE_OF_POWER_P_II                = 56505,
    // SPELL_SURGE_OF_POWER_TRIGGERED        = 56548,
    SPELL_ARCANE_SHOCK                       = 57058, // used by Nexus Lords
    SPELL_HASTE                              = 57060, // used by Nexus Lords
    SPELL_ARCANE_BARRAGE                     = 56397, // used by Scions of Eternity
    SPELL_ARCANE_BARRAGE_DAMAGE              = 63934, // the actual damage - cast by affected player by script spell

    // Transition /II-III/
    SPELL_RIDE_RED_DRAGON_BUDDY              = 56071,
    SPELL_SUMMON_RED_DRAGON_BUDDY_F_CAST     = 58846, // After implicitly hit player targets they will force cast 56070 on self
    SPELL_DESTROY_PLATFORM_CHANNEL           = 58842,
    SPELL_DESTROY_PLATFORM_BOOM_VISUAL       = 59084,
    SPELL_DESTROY_PLATFORM_EVENT             = 59099,

    // Phase III
    SPELL_CLEAR_ALL_DEBUFFS                  = 34098,
    SPELL_IMMUNE_CURSES                      = 64515,
    SPELL_STATIC_FIELD_MISSLE                = 57430,
    SPELL_ARCANE_PULSE                       = 57432,
    SPELL_SURGE_OF_POWER_PHASE_3_10          = 57407,
    SPELL_SURGE_OF_POWER_PHASE_3_25          = 60936,
    SPELL_SURGE_OF_POWER_WARNING_SELECTOR_25 = 60939, // used in 25 player mode for selecting targets for warnings and then sends to actual spell
    SPELL_ARCANE_STORM_P_III                 = 57459,

    // Phase I and III
    SPELL_ARCANE_STORM_EXTRA_VISUAL          = 57473,

    // Outro
    SPELL_ALEXSTRASZAS_GIFT_BEAM_VISUAL      = 61023
};

enum Movements
{
    POINT_NEAR_RANDOM_PORTAL_P_NONE         = 1,
    POINT_LAND_P_ONE,
    POINT_VORTEX_P_ONE,
    POINT_LAND_AFTER_VORTEX_P_ONE,
    POINT_LIFT_IN_AIR_P_ONE,
    POINT_PHASE_ONE_TO_TWO_TRANSITION,
    POINT_FLY_OUT_OF_PLATFORM_P_TWO,
    POINT_SURGE_OF_POWER_P_TWO,
    POINT_DESTROY_PLATFORM_P_TWO,
    POINT_IDLE_P_THREE,
};

enum Seats
{
    SEAT_0       = 0
};

enum Actions
{
    // Malygos
    ACTION_LAND_ENCOUNTER_START                = 0,
    ACTION_EXECUTE_VORTEX                      = 1,
    ACTION_HANDLE_P_THREE_INTRO                = 2,
    ACTION_LIFT_IN_AIR                         = 3,
    ACTION_HANDLE_RESPAWN                      = 4,
    ACTION_CYCLIC_MOVEMENT                     = 5,

    // Caster hover disk despawn action
    ACTION_DELAYED_DESPAWN                     = 8,

    // Nexus Lord's action used to shedule casting spell that determine disk's target to chase
    ACTION_SET_DISK_VICTIM_CHASE               = 0
};

enum Texts
{
    // Malygos
    SAY_INTRO_EVENT                     = 0,
    SAY_START_P_ONE                     = 1,
    SAY_DEEP_BREATH                     = 2,
    SAY_KILLED_PLAYER_P_ONE             = 3,
    SAY_END_P_ONE                       = 4,
    // SAY_START_P_TWO                  = 5, // Unused by Blizzard for some reason on any version
    SAY_ANTI_MAGIC_SHELL                = 6,
    SAY_MAGIC_BLAST                     = 7,
    SAY_KILLED_PLAYER_P_TWO             = 8,
    SAY_END_P_TWO                       = 9,
    SAY_START_P_THREE                   = 10,
    // SAY_START_P_THREE                = 11, // Unused by Blizzard for some reason on any version
    EMOTE_SURGE_OF_POWER_WARNING_P2     = 12,
    SAY_SURGE_OF_POWER                  = 13,
    SAY_BUFF_SPARK                      = 14,
    SAY_KILLED_PLAYER_P_THREE           = 15,
    SAY_SPELL_CASTING_P_THREE           = 16,
    SAY_DEATH                           = 17,
    EMOTE_SURGE_OF_POWER_WARNING_P3     = 18,
    EMOTE_HIT_BERSERKER_TIMER           = 19,

    // Alexstrasza
    SAY_ONE                             = 0,
    SAY_TWO                             = 1,
    SAY_THREE                           = 2,
    SAY_FOUR                            = 3,

    // Power Sparks
    EMOTE_POWER_SPARK_SUMMONED          = 0
};

#define MAX_SUMMONS_PHASE_TWO_10MAN       6
#define MAX_SUMMONS_PHASE_TWO_25MAN       12

#define MAX_RANGE_HOVER_DISK_SPAWNPOINTS       8
Position const RangeHoverDisksSpawnPositions[MAX_RANGE_HOVER_DISK_SPAWNPOINTS] =
{
    { 782.9821f, 1296.652f, 282.1114f, 0.0f },
    { 764.3126f, 1328.871f, 282.3091f, 0.0f },
    { 725.8506f, 1306.749f, 282.2698f, 0.0f },
    { 744.5175f, 1274.396f, 282.3402f, 0.0f },
    { 764.3936f, 1274.371f, 282.6011f, 0.0f },
    { 779.3761f, 1316.166f, 282.1653f, 0.0f },
    { 744.4915f, 1328.901f, 282.2112f, 0.0f },
    { 729.2364f, 1287.328f, 282.4173f, 0.0f }
};

#define MAX_MELEE_HOVER_DISK_SPAWNPOINTS       4
Position const MeleeHoverDisksSpawnPositions[MAX_RANGE_HOVER_DISK_SPAWNPOINTS] =
{
    { 754.4617f, 1283.859f, 285.0522f, 0.0f },
    { 771.7864f, 1301.853f, 285.0522f, 0.0f },
    { 753.9635f, 1319.003f, 285.0522f, 0.0f },
    { 736.4914f, 1301.683f, 285.0522f, 0.0f }
};

#define MAX_MELEE_HOVER_DISK_WAYPOINTS       16
Position const MeleeHoverDisksWaypoints[MAX_MELEE_HOVER_DISK_WAYPOINTS] =
{
    // First melee hover disk wps
    { 766.2931f, 1312.904f, 277.0551f, 0.0f },
    { 754.3397f, 1319.759f, 274.0536f, 0.0f },
    { 742.1018f, 1312.714f, 270.1367f, 0.0f },
    { 735.6851f, 1301.422f, 266.7208f, 0.0f },
    // Second melee hover disk wps
    { 742.6257f, 1313.471f, 275.9713f, 0.0f },
    { 736.8845f, 1301.921f, 274.0264f, 0.0f },
    { 742.6632f, 1289.951f, 269.8603f, 0.0f },
    { 754.3682f, 1283.942f, 266.6098f, 0.0f },
    // Third melee hover disk wps
    { 742.2078f, 1290.518f, 276.2484f, 0.0f },
    { 754.5398f, 1284.311f, 273.5815f, 0.0f },
    { 766.5588f, 1290.345f, 269.6655f, 0.0f },
    { 773.4768f, 1301.474f, 266.5821f, 0.0f },
    // Forth melee hover disk wps
    { 766.1189f, 1290.197f, 276.9436f, 0.0f },
    { 771.9507f, 1301.602f, 273.9712f, 0.0f },
    { 766.1253f, 1313.451f, 270.4991f, 0.0f },
    { 754.5378f, 1319.399f, 266.6653f, 0.0f }
};

#define MAX_MALYGOS_POS 10
Position const MalygosPositions[MAX_MALYGOS_POS] =
{
    { 754.544f, 1301.71f, 320.01f, 0.0f }, // Point destroy platform
    { 754.393f, 1301.27f, 292.91f, 0.0f }, // Point Vortex
    { 754.362f, 1301.61f, 266.17f, 0.0f }, // Point land after Vortex
    { 754.695f, 1301.66f, 316.65f, 0.0f }, // Point Surge of Power phase II
    { 755.681f, 1298.41f, 220.06f, 0.0f }  // Point idle phase III
};

Position const AlexstraszaSpawnPos  = { 854.551f, 1225.31f, 300.901f, 0.0f }; // Alexstrasza's spawn position
Position const HeartOfMagicSpawnPos = { 755.351f, 1298.31f, 223.909f, 0.0f }; // Heart of Magic spawn position

#define TEN_MINUTES         (10*MINUTE*IN_MILLISECONDS)

enum Achievements
{
    ACHIEV_TIMED_START_EVENT       = 20387
};

enum AreaIds
{
    AREA_EYE_OF_ETERNITY         = 4500
};

enum MiscData
{
    // Lights
    LIGHT_DEFAULT                    = 1773,
    LIGHT_OBSCURE_SPACE              = 1822,
    LIGHT_CHANGE_DIMENSIONS          = 1823,
    LIGHT_ARCANE_RUNES               = 1824,
    LIGHT_OBSCURE_ARCANE_RUNES       = 1825,

    // Data (setters/getters)
    DATA_SUMMON_DEATHS               = 0, // phase 2
    DATA_PHASE                       = 1,

    // Target guids
    DATA_LAST_OVERLOAD_GUID          = 13, // used to store last Arcane Overload guid
    DATA_FIRST_SURGE_TARGET_GUID     = 14,
    // DATA_SECOND_SURGE_TARGET_GUID = 15,
    // DATA_THIRD_SURGE_TARGET_GUID  = 16,
    DATA_LAST_TARGET_BARRAGE_GUID    = 17,

    NUM_MAX_SURGE_TARGETS            = 3,
};

// Used to check if summons guids come from vehicles
class VehicleCheckPredicate
{
    public:
        bool operator()(ObjectGuid guid) { return guid.IsVehicle(); }
};

struct boss_malygos : public BossAI
{
    boss_malygos(Creature* creature) : BossAI(creature, DATA_MALYGOS_EVENT)
    {
        Initialize();
        _despawned = instance->GetBossState(DATA_MALYGOS_EVENT) == FAIL;
        _flySpeed = me->GetSpeed(MOVE_FLIGHT); // Get initial fly speed, otherwise on each wipe fly speed would add up if we get it
        _phase = PHASE_NOT_STARTED;
    }

    void Initialize()
    {
        _summonDeaths = 0;
        _preparingPulsesChecker = 0;
        _arcaneOverloadGUID.Clear();
        _lastHitByArcaneBarrageGUID.Clear();
        for (ObjectGuid& guid : _surgeTargetGUID)
            guid.Clear();

        _killSpamFilter = false;
        _executingVortex = false;
        _arcaneReinforcements = true;
        _flyingOutOfPlatform = false;
        _firstCyclicMovementStarted = false;
        _performingSurgeOfPower = false;
        _performingDestroyPlatform = false;
    }

    void Reset() override
    {
        // EnterEvadeMode and Reset() links are cut for the sake of properly functioning despawner.
        if (!_despawned)
            _Reset();

        Initialize();

        me->SetDisableGravity(true);
        me->SetImmuneToAll(true);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
        // TO DO: find what in core is making boss slower than in retail (when correct speed data) or find missing movement flag update or forced spline change
        me->SetSpeedRate(MOVE_FLIGHT, _flySpeed * 0.25f);
        if (_despawned)
            DoAction(ACTION_HANDLE_RESPAWN);

        SetPhase(PHASE_NOT_STARTED, true);
        me->SetReactState(REACT_PASSIVE);
        instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        instance->SetBossState(DATA_MALYGOS_EVENT, NOT_STARTED);
    }

    uint32 GetData(uint32 data) const override
    {
        switch (data)
        {
            case DATA_SUMMON_DEATHS:
                return _summonDeaths;
            case DATA_PHASE:
                return _phase;
        }

        return 0;
    }

    void SetData(uint32 data, uint32 value) override
    {
        if (data == DATA_SUMMON_DEATHS && _phase == PHASE_TWO && !_despawned)
        {
            _summonDeaths = value;

            if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
            {
                if (_summonDeaths == MAX_SUMMONS_PHASE_TWO_10MAN)
                {
                    _performingDestroyPlatform = true;
                    DoAction(ACTION_HANDLE_P_THREE_INTRO);
                }
            }
            else if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
            {
                if (_summonDeaths == MAX_SUMMONS_PHASE_TWO_25MAN)
                {
                    _performingDestroyPlatform = true;
                    DoAction(ACTION_HANDLE_P_THREE_INTRO);
                }
            }
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        if (type >= DATA_FIRST_SURGE_TARGET_GUID && type < DATA_FIRST_SURGE_TARGET_GUID + NUM_MAX_SURGE_TARGETS)
            return _surgeTargetGUID[type - DATA_FIRST_SURGE_TARGET_GUID];
        else if (type == DATA_LAST_TARGET_BARRAGE_GUID)
            return _lastHitByArcaneBarrageGUID;

        return ObjectGuid::Empty;
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        switch (id)
        {
            case DATA_LAST_OVERLOAD_GUID:
                _arcaneOverloadGUID = guid;
                break;
            case DATA_FIRST_SURGE_TARGET_GUID:
            case DATA_FIRST_SURGE_TARGET_GUID + 1:
            case DATA_FIRST_SURGE_TARGET_GUID + 2:
                _surgeTargetGUID[id - DATA_FIRST_SURGE_TARGET_GUID] = guid;
                break;
            case DATA_LAST_TARGET_BARRAGE_GUID:
                _lastHitByArcaneBarrageGUID = guid;
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_LAND_ENCOUNTER_START:
                events.CancelEventGroup(1);
                if (Creature* alexstraszaBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ALEXSTRASZA_BUNNY_GUID)))
                {
                    Position pos;
                    pos.m_positionZ = alexstraszaBunny->GetPositionZ();
                    alexstraszaBunny->GetNearPoint2D(nullptr, pos.m_positionX, pos.m_positionY, 30.0f, alexstraszaBunny->GetAbsoluteAngle(me));
                    me->GetMotionMaster()->MoveLand(POINT_LAND_P_ONE, pos);
                    me->SetImmuneToAll(false);
                    DoZoneInCombat();
                    events.ScheduleEvent(EVENT_LAND_START_ENCOUNTER, 7s, 1, PHASE_NOT_STARTED);
                }
                break;
            case ACTION_EXECUTE_VORTEX:
                DoCast(me, SPELL_VORTEX_1, true);
                DoCast(me, SPELL_VORTEX_2, true);
                // the vortex execution continues in the dummy effect of this spell (see it's script)
                DoCast(me, SPELL_VORTEX_3, true);
                break;
            case ACTION_LIFT_IN_AIR:
            {
                Position _zToLift = me->GetPosition();
                if (_phase == PHASE_ONE)
                {
                    _zToLift.m_positionZ += 20.0f;
                    me->GetMotionMaster()->MoveTakeoff(POINT_LIFT_IN_AIR_P_ONE, _zToLift);
                }
                else if (_phase == PHASE_TWO)
                {
                    _zToLift.m_positionZ = 300.1f;
                    me->GetMotionMaster()->MoveTakeoff(POINT_PHASE_ONE_TO_TWO_TRANSITION, _zToLift);
                }
                break;
            }
            case ACTION_HANDLE_P_THREE_INTRO:
                events.CancelEventGroup(0);
                events.CancelEventGroup(1);
                events.CancelEventGroup(2);
                // Vehicles shouldn't be despawned with 0 delay if the call comes from virtual function that overrides PassengerBoarded.
                // Aside from that he doesn't despawn both vehicles and arcane overloads right away, but with some delay.
                DummyEntryCheckPredicate pred;
                summons.DoAction(ACTION_DELAYED_DESPAWN, pred);
                Talk(SAY_END_P_TWO);
                me->GetMotionMaster()->Clear();
                me->StopMoving();
                if (me->GetPositionZ() > 300.0f)
                    events.ScheduleEvent(EVENT_DELAY_MOVE_TO_DESTROY_P, 5s, 0, PHASE_TWO);
                else
                    me->GetMotionMaster()->MovePoint(POINT_DESTROY_PLATFORM_P_TWO, MalygosPositions[0]);

                events.ScheduleEvent(EVENT_LIGHT_DIMENSION_CHANGE, 1s, 0, PHASE_TWO);
                break;
            case ACTION_HANDLE_RESPAWN:
                // Teleport to spawn position, we can't use normal relocate
                float x, y, z, o;
                me->GetRespawnPosition(x, y, z, &o);
                me->NearTeleportTo(x, y, z, o);
                // Respawn Iris
                instance->SetData(DATA_RESPAWN_IRIS, 0);
                _despawned = false;
                break;
            case ACTION_CYCLIC_MOVEMENT:
                me->GetMotionMaster()->MoveCirclePath(MalygosPositions[3].GetPositionX(), MalygosPositions[3].GetPositionY(), 283.2763f, 120.0f, true, 16);
                break;
        }
    }

    void SetPhase(uint8 phase, bool setEvents = false)
    {
        events.Reset();
        events.SetPhase(phase);
        _phase = phase;
        if (setEvents)
            SetPhaseEvents();
    }

    void SetPhaseEvents()
    {
        switch (_phase)
        {
            case PHASE_NOT_STARTED:
                events.ScheduleEvent(EVENT_SAY_INTRO, 1s, 1, _phase);
                events.ScheduleEvent(EVENT_START_FIRST_RANDOM_PORTAL, 2s, 1, _phase);
                break;
            case PHASE_ONE:
                events.ScheduleEvent(EVENT_ARCANE_BREATH, 8s, 10s, 0, _phase);
                events.ScheduleEvent(EVENT_ARCANE_STORM, 3s, 6s, 0, _phase);
                events.ScheduleEvent(EVENT_VORTEX, 30s, 35s, 0, _phase);
                events.ScheduleEvent(EVENT_POWER_SPARKS, 20s, 30s, 0, _phase);
                break;
            case PHASE_TWO:
                events.ScheduleEvent(EVENT_MOVE_TO_POINT_SURGE_P_TWO, 60s, 0, _phase);
                DoAction(ACTION_LIFT_IN_AIR);
                break;
            case PHASE_THREE:
                events.ScheduleEvent(EVENT_ARCANE_PULSE, 7s, 0, _phase);
                events.ScheduleEvent(EVENT_ARCANE_STORM, 10s, 0, _phase);
                events.ScheduleEvent(EVENT_SURGE_OF_POWER_P_THREE, 4s, 6s, 0, _phase);
                events.ScheduleEvent(EVENT_STATIC_FIELD, 20s, 30s, 0, _phase);
                break;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        // We can't call full function here since it includes DoZoneInCombat(),
        // if someone does it will be returned with a warning.
        me->setActive(true);
        if (!instance->CheckRequiredBosses(DATA_MALYGOS_EVENT))
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            return;
        }

        instance->SetBossState(DATA_MALYGOS_EVENT, IN_PROGRESS);

        Talk(SAY_START_P_ONE);
        DoCast(SPELL_BERSERK); // periodic aura, first tick in 10 minutes
        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SetBossState(DATA_MALYGOS_EVENT, FAIL);

        me->GetMap()->SetZoneOverrideLight(AREA_EYE_OF_ETERNITY, LIGHT_DEFAULT, 0, 1s);

        if (!summons.empty())
        {
            if (_phase == PHASE_TWO)
            {
                VehicleCheckPredicate pred;
                summons.DoAction(ACTION_DELAYED_DESPAWN, pred);
                summons.DespawnIf(pred);
                summons.DespawnAll();
            }
            else if (_phase == PHASE_THREE)
                summons.DespawnAll();
        }

        me->DespawnOrUnsummon(0s, 30s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (!_killSpamFilter)
        {
            switch (_phase)
            {
                case PHASE_ONE:
                    Talk(SAY_KILLED_PLAYER_P_ONE);
                    events.ScheduleEvent(EVENT_PREVENT_SAY_SPAM_ON_KILL, 5s, 0, _phase);
                    _killSpamFilter = true;
                    break;
                case PHASE_TWO:
                    Talk(SAY_KILLED_PLAYER_P_TWO);
                    events.ScheduleEvent(EVENT_PREVENT_SAY_SPAM_ON_KILL, 5s, 0, _phase);
                    _killSpamFilter = true;
                    break;
                case PHASE_THREE:
                    Talk(SAY_KILLED_PLAYER_P_THREE);
                    events.ScheduleEvent(EVENT_PREVENT_SAY_SPAM_ON_KILL, 5s, 0, _phase);
                    _killSpamFilter = true;
                    break;
            }
        }
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_POWER_SPARK_MALYGOS)
        {
            if (Creature* creature = caster->ToCreature())
                creature->DespawnOrUnsummon();

            Talk(SAY_BUFF_SPARK);
        }
        else if (spellInfo->Id == SPELL_MALYGOS_BERSERK)
            Talk(EMOTE_HIT_BERSERKER_TIMER);
    }

    void MoveInLineOfSight(Unit* who) override

    {
        if (!me->IsInCombat() || _phase != PHASE_ONE)
            return;

        if (who->GetEntry() == NPC_POWER_SPARK)
            if (who->GetDistance(me) <= 2.5f)
                who->CastSpell(me, SPELL_POWER_SPARK_MALYGOS, true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_NEAR_RANDOM_PORTAL_P_NONE:
                if (Creature* portal = me->FindNearestCreature(NPC_PORTAL_TRIGGER, 31.0f, true))
                {
                    events.ScheduleEvent(EVENT_STOP_PORTAL_BEAM, 10s, 1, PHASE_NOT_STARTED);
                    events.ScheduleEvent(EVENT_RANDOM_PORTAL, 14s, 1, PHASE_NOT_STARTED);
                    DoCast(portal, SPELL_PORTAL_BEAM);
                }
                break;
            case POINT_LAND_P_ONE:
                me->SetDisableGravity(false);
                break;
            case POINT_VORTEX_P_ONE:
                me->GetMotionMaster()->MoveIdle();
                DoAction(ACTION_EXECUTE_VORTEX);
                break;
            case POINT_LAND_AFTER_VORTEX_P_ONE:
                me->SetDisableGravity(false);
                _executingVortex = false;
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case POINT_LIFT_IN_AIR_P_ONE:
                me->SetDisableGravity(true);
                events.ScheduleEvent(EVENT_MOVE_TO_VORTEX_POINT, 1ms, 0, PHASE_ONE);
                break;
            case POINT_FLY_OUT_OF_PLATFORM_P_TWO:
                if (!_firstCyclicMovementStarted)
                {
                    _firstCyclicMovementStarted = true;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    if (Creature* alexstraszaBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ALEXSTRASZA_BUNNY_GUID)))
                        me->SetFacingToObject(alexstraszaBunny);
                    events.ScheduleEvent(EVENT_SUMMON_ARCANE_BOMB, 1s, 0, PHASE_TWO);
                }
                _flyingOutOfPlatform = false;
                _performingSurgeOfPower = false;
                events.ScheduleEvent(EVENT_PATHING_AROUND_PLATFORM, 1s, 0, PHASE_TWO);
                break;
            case POINT_PHASE_ONE_TO_TWO_TRANSITION:
                me->SetDisableGravity(true);
                if (Creature* alexstraszaBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ALEXSTRASZA_BUNNY_GUID)))
                    me->SetFacingToObject(alexstraszaBunny);
                me->GetMap()->SetZoneOverrideLight(AREA_EYE_OF_ETERNITY, LIGHT_DEFAULT, LIGHT_ARCANE_RUNES, 5s);
                events.ScheduleEvent(EVENT_FLY_OUT_OF_PLATFORM, 18s, 0, PHASE_TWO);
                break;
            case POINT_SURGE_OF_POWER_P_TWO:
                if (!_performingDestroyPlatform)
                {
                    Talk(EMOTE_SURGE_OF_POWER_WARNING_P2);
                    DoCastAOE(SPELL_SURGE_OF_POWER_P_II, true);
                    events.ScheduleEvent(EVENT_FLY_OUT_OF_PLATFORM, 7s, 0, PHASE_TWO);
                }
                break;
            case POINT_DESTROY_PLATFORM_P_TWO:
                me->GetMap()->SetZoneOverrideLight(AREA_EYE_OF_ETERNITY, LIGHT_DEFAULT, LIGHT_OBSCURE_SPACE, 1s);
                DoCast(me, SPELL_DESTROY_PLATFORM_CHANNEL);
                events.ScheduleEvent(EVENT_MOVE_TO_P_THREE_POINT, 11s, 0, PHASE_TWO);
                break;
            case POINT_IDLE_P_THREE:
                me->SetControlled(true, UNIT_STATE_ROOT);
                events.ScheduleEvent(EVENT_START_P_THREE, 5s, 0, PHASE_TWO);
                break;
        }
    }

    void DamageTaken(Unit* /*cause*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage > me->GetHealth() && _phase != PHASE_THREE)
            damage = me->GetHealth() - 1;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && _phase != PHASE_NOT_STARTED && _phase != PHASE_TWO)
            return;

        events.Update(diff);

        // we can't cast if we are casting already unless in PHASE_NOT_STARTED channeling PORTAL_BEAM
        if (me->HasUnitState(UNIT_STATE_CASTING) && _phase != PHASE_NOT_STARTED)
            return;

        // at 50% hp Malygos switchs to phase 2 and removes hovering until reset or end of encounter
        if (_phase == PHASE_ONE && me->GetHealthPct() <= 50.0f)
        {
            SetPhase(PHASE_TWO, true);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            Talk(SAY_END_P_ONE);
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_FIRST_RANDOM_PORTAL:
                case EVENT_RANDOM_PORTAL:
                    DoCastAOE(SPELL_RANDOM_PORTAL, { SPELLVALUE_MAX_TARGETS,1 });
                    break;
                case EVENT_STOP_PORTAL_BEAM:
                    me->InterruptNonMeleeSpells(true);
                    break;
                case EVENT_LAND_START_ENCOUNTER:
                    if (GameObject* iris = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_FOCUSING_IRIS_GUID)))
                    {
                        me->SetFacingToObject(iris);
                        iris->Delete(); // this is not the best way.
                    }
                    me->SetReactState(REACT_AGGRESSIVE);
                    SetPhase(PHASE_ONE, true);
                    break;
                case EVENT_SAY_INTRO:
                    Talk(SAY_INTRO_EVENT);
                    events.ScheduleEvent(EVENT_SAY_INTRO, 85s, 95s, 1, PHASE_NOT_STARTED);
                    break;
                case EVENT_VORTEX:
                    _executingVortex = true;
                    DoAction(ACTION_LIFT_IN_AIR);
                    events.ScheduleEvent(EVENT_VORTEX, 60s, 80s, 0, PHASE_ONE);
                    break;
                case EVENT_MOVE_TO_VORTEX_POINT:
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->GetMotionMaster()->MovePoint(POINT_VORTEX_P_ONE, MalygosPositions[1]);
                    break;
                case EVENT_POWER_SPARKS:
                    instance->SetData(DATA_POWER_SPARKS_HANDLING, 0);
                    events.ScheduleEvent(EVENT_POWER_SPARKS, 30s, 35s, 0, PHASE_ONE);
                    break;
                case EVENT_ARCANE_BREATH:
                    if (_executingVortex)
                    {
                        events.ScheduleEvent(EVENT_ARCANE_BREATH, 20s, 0, PHASE_ONE);
                        break;
                    }

                    me->CastSpell(me->GetVictim(), SPELL_ARCANE_BREATH);
                    events.ScheduleEvent(EVENT_ARCANE_BREATH, 20s, 0, PHASE_ONE);
                    break;
                case EVENT_ARCANE_STORM:
                    if (_phase == PHASE_ONE)
                    {
                        if (_executingVortex)
                        {
                            events.ScheduleEvent(EVENT_ARCANE_STORM, 10s, 0, PHASE_ONE);
                            break;
                        }

                        DoCastAOE(SPELL_ARCANE_STORM_P_I, true);
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 10s, 0, PHASE_ONE);
                    }
                    else if (_phase == PHASE_THREE)
                    {
                        DoCastAOE(SPELL_ARCANE_STORM_P_III, true);
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 6s, 12s, 0, PHASE_THREE);
                    }
                    break;
                case EVENT_FLY_OUT_OF_PLATFORM:
                    if (!_performingDestroyPlatform)
                    {
                        if (Creature* alexstraszaBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ALEXSTRASZA_BUNNY_GUID)))
                        {
                            Position randomPosOnRadius;
                            // Hardcodded retail value, reason is Z getters can fail... (TO DO: Change to getter when height calculation works on 100%!)
                            randomPosOnRadius.m_positionZ = 283.0521f;
                            alexstraszaBunny->GetNearPoint2D(nullptr, randomPosOnRadius.m_positionX, randomPosOnRadius.m_positionY, 120.0f, alexstraszaBunny->GetAbsoluteAngle(me));
                            me->GetMotionMaster()->MovePoint(POINT_FLY_OUT_OF_PLATFORM_P_TWO, randomPosOnRadius);
                            _flyingOutOfPlatform = true;
                        }
                    }

                    if (_arcaneReinforcements)
                    {
                        for (uint8 rangeDisks = 0; rangeDisks < (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? 4 : 5); rangeDisks++)
                        {
                            Creature* casterDiskSummon = me->SummonCreature(NPC_HOVER_DISK_CASTER, RangeHoverDisksSpawnPositions[rangeDisks]);

                            if (casterDiskSummon->IsAIEnabled())
                                casterDiskSummon->AI()->DoAction(rangeDisks);
                        }

                        for (uint8 meleeDisks = 0; meleeDisks < 2; meleeDisks++)
                        {
                            Creature* meleeDiskSummon = me->SummonCreature(NPC_HOVER_DISK_MELEE, MeleeHoverDisksSpawnPositions[meleeDisks]);
                            meleeDiskSummon->GetMotionMaster()->MovePoint(meleeDisks * MAX_MELEE_HOVER_DISK_SPAWNPOINTS, MeleeHoverDisksWaypoints[meleeDisks * MAX_MELEE_HOVER_DISK_SPAWNPOINTS]);
                        }

                        _arcaneReinforcements = false;

                        if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                            events.ScheduleEvent(EVENT_DELAYED_REINFORCEMENTS, 1s, 0, PHASE_TWO);
                    }
                    break;
                case EVENT_DELAYED_REINFORCEMENTS:
                    for (uint8 rangeDisks = 5; rangeDisks < 8; rangeDisks++)
                    {
                        Creature* casterDiskSummon = me->SummonCreature(NPC_HOVER_DISK_CASTER, RangeHoverDisksSpawnPositions[rangeDisks]);

                        if (casterDiskSummon->IsAIEnabled())
                            casterDiskSummon->AI()->DoAction(rangeDisks);
                    }

                    for (uint8 meleeDisks = 2; meleeDisks < 4; meleeDisks++)
                    {
                        Creature* meleeDiskSummon = me->SummonCreature(NPC_HOVER_DISK_MELEE, MeleeHoverDisksSpawnPositions[meleeDisks]);
                        meleeDiskSummon->GetMotionMaster()->MovePoint(meleeDisks * MAX_MELEE_HOVER_DISK_SPAWNPOINTS, MeleeHoverDisksWaypoints[meleeDisks * MAX_MELEE_HOVER_DISK_SPAWNPOINTS]);
                    }
                    break;
                case EVENT_PATHING_AROUND_PLATFORM:
                    if (!_performingSurgeOfPower && !_performingDestroyPlatform)
                        DoAction(ACTION_CYCLIC_MOVEMENT);
                    break;
                case EVENT_MOVE_TO_POINT_SURGE_P_TWO:
                    if (!_performingDestroyPlatform)
                    {
                        _performingSurgeOfPower = true;
                        Talk(SAY_DEEP_BREATH);
                        me->GetMotionMaster()->MovePoint(POINT_SURGE_OF_POWER_P_TWO, MalygosPositions[3]);
                        events.ScheduleEvent(EVENT_MOVE_TO_POINT_SURGE_P_TWO, 60s, 2, PHASE_TWO);
                    }
                    break;
                case EVENT_SUMMON_ARCANE_BOMB:
                    if (!_performingSurgeOfPower && !_performingDestroyPlatform)
                    {
                        me->StopMoving();
                        events.ScheduleEvent(EVENT_PATHING_AROUND_PLATFORM, 3s, 0, PHASE_TWO);
                    }

                    if (!_flyingOutOfPlatform)
                    {
                        DoCast(me, SPELL_SUMMON_ARCANE_BOMB, true);
                        if (Creature* lastArcaneOverloadBunny = ObjectAccessor::GetCreature(*me, _arcaneOverloadGUID))
                            DoCast(lastArcaneOverloadBunny, SPELL_ARCANE_BOMB_TRIGGER, true);
                    }
                    events.ScheduleEvent(EVENT_SUMMON_ARCANE_BOMB, 15s, 16s, 2, PHASE_TWO);
                    break;
                case EVENT_ARCANE_PULSE:
                    if (_preparingPulsesChecker < 2)
                    {
                        DoCastAOE(SPELL_ARCANE_PULSE, true);
                        events.ScheduleEvent(EVENT_ARCANE_PULSE, 7s, 0, PHASE_THREE);
                        _preparingPulsesChecker++;
                    }
                    else
                    {
                        DoCastAOE(SPELL_ARCANE_PULSE, true);
                        events.ScheduleEvent(EVENT_ARCANE_PULSE, 2s, 0, PHASE_THREE);
                    }
                    break;
                case EVENT_LIGHT_DIMENSION_CHANGE:
                    me->GetMap()->SetZoneOverrideLight(AREA_EYE_OF_ETERNITY, LIGHT_DEFAULT, LIGHT_CHANGE_DIMENSIONS, 2s);
                    break;
                case EVENT_DELAY_MOVE_TO_DESTROY_P:
                    me->GetMotionMaster()->MovePoint(POINT_DESTROY_PLATFORM_P_TWO, MalygosPositions[0]);
                    break;
                case EVENT_MOVE_TO_P_THREE_POINT:
                    Talk(SAY_START_P_THREE);
                    me->GetMotionMaster()->MovePoint(POINT_IDLE_P_THREE, MalygosPositions[4]);
                    break;
                case EVENT_START_P_THREE:
                    me->GetMap()->SetZoneOverrideLight(AREA_EYE_OF_ETERNITY, LIGHT_DEFAULT, LIGHT_OBSCURE_ARCANE_RUNES, 1s);
                    DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                    DoCast(me, SPELL_IMMUNE_CURSES);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    SetPhase(PHASE_THREE, true);
                    break;
                case EVENT_SURGE_OF_POWER_P_THREE:
                    if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                    {
                        if (Unit* tempSurgeTarget = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, false, true, SPELL_RIDE_RED_DRAGON_BUDDY))
                        {
                            if (Vehicle* drakeVehicle = tempSurgeTarget->GetVehicleKit())
                            {
                                if (Unit* passenger = drakeVehicle->GetPassenger(0))
                                {
                                    if (passenger->GetTypeId() == TYPEID_PLAYER)
                                    {
                                        Talk(EMOTE_SURGE_OF_POWER_WARNING_P3, passenger);
                                        DoCast(tempSurgeTarget, SPELL_SURGE_OF_POWER_PHASE_3_10, true);
                                    }
                                }
                            }
                        }
                    }
                    else if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                    {
                        for (ObjectGuid& guid : _surgeTargetGUID)
                            guid.Clear();

                        DoCastAOE(SPELL_SURGE_OF_POWER_WARNING_SELECTOR_25, true);
                    }

                    events.ScheduleEvent(EVENT_SURGE_OF_POWER_P_THREE, 9s, 18s, 0, PHASE_THREE);
                    break;
                case EVENT_STATIC_FIELD:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f, false, true, SPELL_RIDE_RED_DRAGON_BUDDY))
                        DoCast(target, SPELL_STATIC_FIELD_MISSLE, true);

                    events.ScheduleEvent(EVENT_STATIC_FIELD, 15s, 30s, 0, PHASE_THREE);
                    break;
                case EVENT_PREVENT_SAY_SPAM_ON_KILL:
                    _killSpamFilter = false;
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING) && _phase != PHASE_NOT_STARTED)
                return;
        }

        if (_phase != PHASE_THREE)
            DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        if (Creature* alexstraszaGiftBoxBunny = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GIFT_BOX_BUNNY_GUID)))
            alexstraszaGiftBoxBunny->SummonGameObject(RAID_MODE(GO_HEART_OF_MAGIC_10, GO_HEART_OF_MAGIC_25), HeartOfMagicSpawnPos, QuaternionData(), 0s);

        me->SummonCreature(NPC_ALEXSTRASZA, AlexstraszaSpawnPos, TEMPSUMMON_MANUAL_DESPAWN);
        me->DespawnOrUnsummon(5s);
    }

private:
    uint8 _phase; // Counter for phases used with a getter.
    uint8 _summonDeaths; // Keeps count of arcane trash.
    uint8 _preparingPulsesChecker; // In retail they use 2 preparing pulses with 7 sec CD, after they pass 2 seconds.
    ObjectGuid _arcaneOverloadGUID; // Last Arcane Overload summoned to know to which should visual be cast to (the purple ball, not bubble).
    ObjectGuid _lastHitByArcaneBarrageGUID; // Last hit player by Arcane Barrage, will be removed if targets > 1.
    ObjectGuid _surgeTargetGUID[3]; // All these three are used to keep current tagets to which warning should be sent.

    bool _killSpamFilter; // Prevent text spamming on killed player by helping implement a CD.
    bool _despawned; // Checks if boss pass through evade on reset.
    bool _executingVortex; // Prevents some events being sheduled during Vortex takeoff/land.
    bool _arcaneReinforcements; // Checks if 10 or 25 man arcane trash will be spawned.
    bool _flyingOutOfPlatform; // Used to prevent Malygos casting Arcane Overload shields while leaving platform.
    bool _firstCyclicMovementStarted; // At first movement start he throws one shield asap, so this check is needed for it only.
    bool _performingSurgeOfPower; // Used to prevent starting Cyclic Movement called in Arcane Bomb event.
    bool _performingDestroyPlatform; // Used to prevent starting some movements right when Destroy Platfrom event starts.

    float _flySpeed; // Used to store base fly speed to prevent stacking on each evade.
};

struct npc_portal_eoe : public ScriptedAI
{
    npc_portal_eoe(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_PORTAL_OPENED)
        {
            if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
            {
                if (malygos->AI()->GetData(DATA_PHASE) == PHASE_ONE)
                    DoCast(me, SPELL_SUMMON_POWER_PARK, true);
            }
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        // When duration of opened riff visual ends, closed one should be cast
        if (!me->HasAura(SPELL_PORTAL_VISUAL_CLOSED) && !me->HasAura(SPELL_PORTAL_OPENED))
            DoCast(me, SPELL_PORTAL_VISUAL_CLOSED, true);

        if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
        {
            if (malygos->AI()->GetData(DATA_PHASE) != PHASE_ONE && me->HasAura(SPELL_PORTAL_OPENED))
            {
                me->RemoveAura(SPELL_PORTAL_OPENED);
                DoCast(me, SPELL_PORTAL_VISUAL_CLOSED, true);
            }
        }
    }

private:
    InstanceScript* _instance;
};

struct npc_power_spark : public ScriptedAI
{
    npc_power_spark(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
        Talk(EMOTE_POWER_SPARK_SUMMONED);
        MoveToMalygos();
    }

    void MoveToMalygos()
    {
        me->GetMotionMaster()->MoveIdle();

        if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
            me->GetMotionMaster()->MoveFollow(malygos, 0.0f, 0.0f);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!_instance)
            return;

        if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
        {
            if (malygos->AI()->GetData(DATA_PHASE) != PHASE_ONE || _instance->GetBossState(DATA_MALYGOS_EVENT) == FAIL)
            {
                me->DespawnOrUnsummon();
                return;
            }

            if (malygos->HasAura(SPELL_VORTEX_1))
            {
                me->GetMotionMaster()->MoveIdle();
                return;
            }

            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
                me->GetMotionMaster()->MoveFollow(malygos, 0.0f, 0.0f);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->CastSpell(me, SPELL_POWER_SPARK_DEATH, true); // not supposed to hide the fact it's there by not selectable
    }

private:
    InstanceScript* _instance;
};

struct npc_melee_hover_disk : public VehicleAI
{
    npc_melee_hover_disk(Creature* creature) : VehicleAI(creature)
    {
        Initialize();
        _instance = creature->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
        // TO DO: These were a bit faster than what they should be. Not sure what is the reason.
        me->SetSpeedRate(MOVE_FLIGHT, 1.25f);
    }

    void Initialize()
    {
        _wpCount = 0;
    }

    void Reset() override
    {
        VehicleAI::Reset();

        Initialize();
    }

    void PassengerBoarded(Unit* unit, int8 /*seat*/, bool apply) override
    {
        if (apply)
        {
            if (unit->GetTypeId() == TYPEID_UNIT)
            {
                unit->CastSpell(unit, SPELL_TELEPORT_VISUAL_ONLY);
                DoZoneInCombat(unit->ToCreature());
            }
            else if (unit->GetTypeId() == TYPEID_PLAYER)
                me->SetDisableGravity(true);
        }
        else
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
            {

                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                me->SetDisableGravity(false);
                me->SetCanFly(false);
            }
            else if (unit->GetTypeId() == TYPEID_PLAYER)
            {
                me->SetDisableGravity(false);
                me->SetCanFly(false);
            }

            me->SetFaction(FACTION_FRIENDLY);
            me->RemoveAllAuras();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
            me->GetMotionMaster()->MovePoint(eventId, MeleeHoverDisksWaypoints[eventId]);
    }

    void DoAction(int32 /*action*/) override
    {
        if (Vehicle* vehicleTemp = me->GetVehicleKit())
        {
            if (vehicleTemp->GetPassenger(0) && vehicleTemp->GetPassenger(0)->GetTypeId() == TYPEID_PLAYER)
            {
                vehicleTemp->RemoveAllPassengers();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
            }
        }

        me->DespawnOrUnsummon(3s);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (_wpCount < 3)
        {
            _events.ScheduleEvent(id + 1, 1ms);
            ++_wpCount;
        }
        else if (Vehicle* hoverDisk = me->GetVehicleKit())
            if (Unit* passenger = hoverDisk->GetPassenger(0))
                if (Creature* lordPassenger = passenger->ToCreature())
                    lordPassenger->AI()->DoAction(ACTION_SET_DISK_VICTIM_CHASE);
    }

private:
    uint8 _wpCount; // how many points are triggered
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_caster_hover_disk : public VehicleAI
{
    npc_caster_hover_disk(Creature* creature) : VehicleAI(creature)
    {
        _instance = creature->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
        // TO DO: Something is wrong with calculations for flying creatures that are on WP/Cyclic path.
        // They should get the same difference as to when at ground from run creature switch to walk.
        me->SetSpeedRate(MOVE_FLIGHT, 0.45f);
    }

    void Reset() override
    {
        VehicleAI::Reset();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
    }

    void PassengerBoarded(Unit* unit, int8 /*seat*/, bool apply) override
    {
        if (apply)
        {
            if (unit->GetTypeId() == TYPEID_UNIT)
                unit->CastSpell(unit, SPELL_TELEPORT_VISUAL_ONLY);
        }
        else
        {
            me->StopMoving();
            me->SetDisableGravity(false);
            me->SetCanFly(false);
            me->RemoveAllAuras();
        }
    }

    void DoAction(int32 action) override
    {
        if (action < ACTION_DELAYED_DESPAWN)
        {
            me->GetMotionMaster()->MoveCirclePath(MalygosPositions[3].GetPositionX(), MalygosPositions[3].GetPositionY(), 282.3402f, 35.0f, true, 16);
        }
        else
        {
            me->DespawnOrUnsummon(3s);
        }
    }

private:
    InstanceScript* _instance;
};

struct npc_nexus_lord : public ScriptedAI
{
    npc_nexus_lord(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        _events.Reset();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
    }

    void DoAction(int32 /*action*/) override
    {
        _events.ScheduleEvent(EVENT_NUKE_DUMMY, 1ms);
        _events.ScheduleEvent(EVENT_ARCANE_SHOCK, 2s);
        _events.ScheduleEvent(EVENT_HASTE_BUFF, 12s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_SHOCK:
                    if (Unit* victim = SelectTarget(SelectTargetMethod::Random, 0, 5.0f, true))
                        DoCast(victim, SPELL_ARCANE_SHOCK);
                    _events.ScheduleEvent(EVENT_ARCANE_SHOCK, 7s, 15s);
                    break;
                case EVENT_HASTE_BUFF:
                    DoCast(me, SPELL_HASTE);
                    _events.ScheduleEvent(EVENT_HASTE_BUFF, 15s);
                    break;
                case EVENT_NUKE_DUMMY:
                    DoCastVictim(SPELL_DUMMY_NUKE, true);
                    DoCast(me, SPELL_ALIGN_DISK_AGGRO, true);
                    _events.ScheduleEvent(EVENT_NUKE_DUMMY, 1s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
            malygos->AI()->SetData(DATA_SUMMON_DEATHS, malygos->AI()->GetData(DATA_SUMMON_DEATHS) + 1);
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_scion_of_eternity : public ScriptedAI
{
    npc_scion_of_eternity(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        _events.Reset();
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 14s, 29s);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
    }

    void AttackStart(Unit* /*target*/) override
    {
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_BARRAGE:
                    DoCast(me, SPELL_ARCANE_BARRAGE);
                    _events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 3s, 15s);
                    break;
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
            malygos->AI()->SetData(DATA_SUMMON_DEATHS, malygos->AI()->GetData(DATA_SUMMON_DEATHS) + 1);
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_arcane_overload : public ScriptedAI
{
    npc_arcane_overload(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Creature* creature = summoner->ToCreature())
            creature->AI()->SetGUID(me->GetGUID(), DATA_LAST_OVERLOAD_GUID);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
    }

    void DoAction(int32 /*action*/) override
    {
        if (Creature* malygos = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MALYGOS)))
        {
            if (malygos->AI()->GetData(DATA_PHASE) == PHASE_TWO)
                me->DespawnOrUnsummon(6s);
            // If evade is hit during phase II shields should disappear with no delay
            else if (malygos->AI()->GetData(DATA_PHASE) == 0)
                me->DespawnOrUnsummon();
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ARCANE_BOMB_TRIGGER)
        {
            DoCastAOE(SPELL_ARCANE_BOMB_KNOCKBACK_DAMAGE, true);
            DoCastSelf(SPELL_ARCANE_OVERLOAD_1, true);
        }
    }

private:
    InstanceScript* _instance;
};

// SmartAI does not work correctly for vehicles
struct npc_wyrmrest_skytalon : public VehicleAI
{
    npc_wyrmrest_skytalon(Creature* creature) : VehicleAI(creature)
    {
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        _summoner.Clear();
        if (Player* player = summoner->ToPlayer())
        {
            _summoner = player->GetGUID();
            _events.ScheduleEvent(EVENT_CAST_RIDE_SPELL, 2s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        VehicleAI::UpdateAI(diff);
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CAST_RIDE_SPELL:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _summoner))
                        me->CastSpell(player, SPELL_RIDE_RED_DRAGON_TRIGGERED, true);
                    break;
            }
        }
    }

    void PassengerBoarded(Unit* /*unit*/, int8 /*seat*/, bool apply) override
    {
        if (!apply)
        {
            me->DespawnOrUnsummon(2050ms);
            me->SetOrientation(2.5f);
            me->SetSpeedRate(MOVE_FLIGHT, 1.0f);
            Position pos = me->GetPosition();
            pos.m_positionX += 10.0f;
            pos.m_positionY += 10.0f;
            pos.m_positionZ += 12.0f;
            me->GetMotionMaster()->MovePoint(1, pos);
        }
    }

private:
    ObjectGuid _summoner;
    EventMap _events;
};

// We shouldn't use SAI for stuff that aren't within boss main mechanic
// and SAI type of despawn can cause problems here.
struct npc_static_field : public ScriptedAI
{
    npc_static_field(Creature* creature) : ScriptedAI(creature)
    {
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        // For some great reason the spell doesn't time it...
        me->DespawnOrUnsummon(30s);
    }
};

// 56046 - Portal Beam
class spell_malygos_portal_beam : public AuraScript
{
    PrepareAuraScript(spell_malygos_portal_beam);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PORTAL_OPENED });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->CastSpell(target, SPELL_PORTAL_OPENED);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->RemoveAura(SPELL_PORTAL_OPENED);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_malygos_portal_beam::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_malygos_portal_beam::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 56047 - Random Portal
class spell_malygos_random_portal : public SpellScript
{
    PrepareSpellScript(spell_malygos_random_portal);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Creature* malygos = GetCaster()->ToCreature();
        if (Creature* target = GetHitCreature())
        {
            Position pos;
            pos.m_positionZ = target->GetPositionZ();
            target->GetNearPoint2D(nullptr, pos.m_positionX, pos.m_positionY, frand(29.1f, 30.0f), target->GetAbsoluteAngle(malygos));
            malygos->GetMotionMaster()->MovePoint(POINT_NEAR_RANDOM_PORTAL_P_NONE, pos);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malygos_random_portal::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class IsCreatureVehicleCheck
{
    public:
        IsCreatureVehicleCheck(bool isVehicle) : _isVehicle(isVehicle) { }

        bool operator()(WorldObject* obj)
        {
            if (Unit* unit = obj->ToUnit())
                if (unit->GetTypeId() == TYPEID_UNIT && unit->GetVehicleKit())
                    return _isVehicle;

            return !_isVehicle;
        }

    private:
        bool _isVehicle;
};

// 57459, 61693, 61694 - Arcane Storm
class spell_malygos_arcane_storm : public SpellScript
{
    PrepareSpellScript(spell_malygos_arcane_storm);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ARCANE_STORM_EXTRA_VISUAL });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Creature* malygos = GetCaster()->ToCreature();
        if (GetSpellInfo()->Id == SPELL_ARCANE_STORM_P_III)
        {
            // Resize list only to objects that are vehicles.
            IsCreatureVehicleCheck check(true);
            Trinity::Containers::RandomResize(targets, check, (malygos->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? 4 : 10));
        }
        else
            Trinity::Containers::RandomResize(targets, (malygos->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? 4 : 10));
    }

    void HandleVisual(SpellEffIndex /*effIndex*/)
    {
        // Both missiles should start approx at same time (with SPELL_ARCANE_STORM_EXTRA_VISUAL having advantage - it should lead)
        if (!GetHitUnit())
            return;

        GetCaster()->CastSpell(GetHitUnit(), SPELL_ARCANE_STORM_EXTRA_VISUAL, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malygos_arcane_storm::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectLaunchTarget += SpellEffectFn(spell_malygos_arcane_storm::HandleVisual, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 56105 - Vortex
class spell_malygos_vortex_dummy : public SpellScript
{
    PrepareSpellScript(spell_malygos_vortex_dummy);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        // Each player will enter to the trigger vehicle (entry 30090) which is already spawned (each one can hold up to 5 players, it has 5 seats,
        // the players enter the vehicles casting SPELL_VORTEX_4 or SPELL_VORTEX_5.
        if (InstanceScript* instance = caster->GetInstanceScript())
            instance->SetData(DATA_VORTEX_HANDLING, 0);

        // the rest of the vortex execution continues when SPELL_VORTEX_2 is removed.
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malygos_vortex_dummy::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 55873 - Vortex
class spell_malygos_vortex_visual : public AuraScript
{
    PrepareAuraScript(spell_malygos_vortex_visual);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_VORTEX_1, SPELL_VORTEX_6 });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
        {
            for (ThreatReference const* ref : caster->GetThreatManager().GetUnsortedThreatList())
            {
                if (Player* targetPlayer = ref->GetVictim()->ToPlayer())
                {
                    if (targetPlayer->IsGameMaster())
                        continue;

                    if (InstanceScript* instance = caster->GetInstanceScript())
                    {
                        // Teleport spell - I'm not sure but might be it must be cast by each vehicle when it's passenger leaves it.
                        if (Creature* trigger = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_TRIGGER)))
                            trigger->CastSpell(targetPlayer, SPELL_VORTEX_6, true);
                    }
                }
            }

            if (Creature* malygos = caster->ToCreature())
            {
                malygos->GetMotionMaster()->MoveLand(POINT_LAND_AFTER_VORTEX_P_ONE, MalygosPositions[2]);
                malygos->RemoveAura(SPELL_VORTEX_1);
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_malygos_vortex_visual::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class ExactDistanceCheck
{
    public:
        ExactDistanceCheck(Unit* source, float dist) : _source(source), _dist(dist) { }

        bool operator()(WorldObject* unit)
        {
            return _source->GetExactDist2d(unit) > _dist;
        }

    private:
        Unit* _source;
        float _dist;
};

// 56438 - Arcane Overload
class spell_arcane_overload : public SpellScript
{
    PrepareSpellScript(spell_arcane_overload);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void ResizeEffectRadiusTargetChecker(std::list<WorldObject*>& targets)
    {
        Creature* arcaneOverload = GetCaster()->ToCreature();
        targets.remove_if(ExactDistanceCheck(arcaneOverload,
            GetEffectInfo(EFFECT_0).CalcRadius(arcaneOverload) * arcaneOverload->GetObjectScale()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arcane_overload::ResizeEffectRadiusTargetChecker, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 61210 - Align Disk Aggro
class spell_nexus_lord_align_disk_aggro : public SpellScript
{
    PrepareSpellScript(spell_nexus_lord_align_disk_aggro);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (Creature* target = GetHitCreature())
            target->GetMotionMaster()->MoveChase(caster->GetVictim());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_nexus_lord_align_disk_aggro::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class IsPlayerOnHoverDisk
{
    public:
        IsPlayerOnHoverDisk(bool isOnHoverDisk) : _isOnHoverDisk(isOnHoverDisk) { }

        bool operator()(WorldObject* obj)
        {
            if (Unit* passenger = obj->ToUnit())
                if (passenger->GetVehicleBase() && passenger->GetVehicleBase()->GetEntry() == NPC_HOVER_DISK_MELEE)
                    return _isOnHoverDisk;

            return !_isOnHoverDisk;
        }

    private:
        bool _isOnHoverDisk;
};

// 56397 - Arcane Barrage
class spell_scion_of_eternity_arcane_barrage : public SpellScript
{
    PrepareSpellScript(spell_scion_of_eternity_arcane_barrage);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT && GetCaster()->GetInstanceScript() != nullptr;
    }

    void FilterMeleeHoverDiskPassangers(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Creature* caster = GetCaster()->ToCreature();
        InstanceScript* instance = caster->GetInstanceScript();
        Creature* malygos = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_MALYGOS));

        // If max possible targets are more than 1 then Scions wouldn't select previosly selected target,
        // in longer terms this means if spell picks target X then 2nd cast of this spell will pick smth else
        // and if 3rd picks X again 4th will pick smth else (by not limiting the cast to certain caster).
        if (targets.size() > 1)
            if (malygos && malygos->AI()->GetGUID(DATA_LAST_TARGET_BARRAGE_GUID))
                targets.remove_if(Trinity::ObjectGUIDCheck(malygos->AI()->GetGUID(DATA_LAST_TARGET_BARRAGE_GUID)));

        // Remove players not on Hover Disk from second list
        std::list<WorldObject*> playersWithoutDisk;
        IsPlayerOnHoverDisk check(false);
        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            if (check(*itr))
                playersWithoutDisk.push_back(*itr);

        // if it's empty than we can have player on Hover disk as target.
        if (!playersWithoutDisk.empty())
            targets = playersWithoutDisk;

        // Finally here we remove all targets that have been damaged by Arcane Barrage
        // and have 2 seconds long aura still lasting. Used to give healers some time.
        if (!targets.empty())
            targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_ARCANE_BARRAGE_DAMAGE));

        // Now we resize the list to max output targets which can be only 1
        // to take it's guid and send/store it to DATA_LAST_TARGET_BARRAGE_GUID.
        // Same target is never picked until next pick pass. This doesn't mean
        // that it can't be hit more than once. In fact all is chance and raid speed.
        if (!targets.empty())
        {
            if (targets.size() > 1)
                Trinity::Containers::RandomResize(targets, 1);

            if (WorldObject* filteredTarget = targets.front())
                if (malygos)
                    malygos->AI()->SetGUID(filteredTarget->GetGUID(), DATA_LAST_TARGET_BARRAGE_GUID);
        }
    }

    void TriggerDamageSpellFromPlayer()
    {
        if (Player* hitTarget = GetHitPlayer())
            hitTarget->CastSpell(hitTarget, SPELL_ARCANE_BARRAGE_DAMAGE, GetCaster()->GetGUID());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_scion_of_eternity_arcane_barrage::FilterMeleeHoverDiskPassangers, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnHit += SpellHitFn(spell_scion_of_eternity_arcane_barrage::TriggerDamageSpellFromPlayer);
    }
};

// 58842 - Destroy Platform Channel
class spell_malygos_destroy_platform_channel : public AuraScript
{
    PrepareAuraScript(spell_malygos_destroy_platform_channel);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DESTROY_PLATFORM_BOOM_VISUAL });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            if (InstanceScript* instance = target->GetInstanceScript())
                if (Creature* platformTrigger = target->GetMap()->GetCreature(instance->GetGuidData(DATA_ALEXSTRASZA_BUNNY_GUID)))
                    platformTrigger->CastSpell(platformTrigger, SPELL_DESTROY_PLATFORM_BOOM_VISUAL);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_malygos_destroy_platform_channel::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 59084 - Destroy Platform Boom Visual
class spell_alexstrasza_bunny_destroy_platform_boom_visual : public SpellScript
{
    PrepareSpellScript(spell_alexstrasza_bunny_destroy_platform_boom_visual);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DESTROY_PLATFORM_EVENT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            target->CastSpell(target, SPELL_DESTROY_PLATFORM_EVENT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alexstrasza_bunny_destroy_platform_boom_visual::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 59099 - Destroy Platform Event
class spell_alexstrasza_bunny_destroy_platform_event : public SpellScript
{
    PrepareSpellScript(spell_alexstrasza_bunny_destroy_platform_event);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleSendEvent(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (InstanceScript* instance = caster->GetInstanceScript())
            if (GameObject* platform = caster->GetMap()->GetGameObject(instance->GetGuidData(DATA_PLATFORM)))
                platform->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_SUMMON_RED_DRAGON_BUDDY_F_CAST);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_alexstrasza_bunny_destroy_platform_event::HandleSendEvent, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
        OnEffectHit += SpellEffectFn(spell_alexstrasza_bunny_destroy_platform_event::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 56070 - Summon Red Dragon Buddy
class spell_wyrmrest_skytalon_summon_red_dragon_buddy : public SpellScript
{
    PrepareSpellScript(spell_wyrmrest_skytalon_summon_red_dragon_buddy);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void SetDest(SpellDestination& dest)
    {
        // Adjust effect summon position to lower Z
        Position const offset = { 0.0f, 0.0f, -80.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_wyrmrest_skytalon_summon_red_dragon_buddy::SetDest, EFFECT_0, TARGET_DEST_CASTER_RADIUS);
    }
};

// 56072 - Ride Red Dragon Buddy
class spell_wyrmrest_skytalon_ride_red_dragon_buddy_trigger : public SpellScript
{
    PrepareSpellScript(spell_wyrmrest_skytalon_ride_red_dragon_buddy_trigger);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(GetCaster(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wyrmrest_skytalon_ride_red_dragon_buddy_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 60939 - Surge of Power
class spell_malygos_surge_of_power_warning_selector_25 : public SpellScript
{
    PrepareSpellScript(spell_malygos_surge_of_power_warning_selector_25);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SURGE_OF_POWER_PHASE_3_25 });
    }

    void SendThreeTargets(std::list<WorldObject*>& targets)
    {
        // This spell hits only vehicles (SMSG_SPELL_GO target)
        Creature* caster = GetCaster()->ToCreature();
        // Remove all objects that aren't* vehicles.
        targets.remove_if(IsCreatureVehicleCheck(false));
        if (targets.empty())
            return;

        // But in fact it selects 3 targets (SMSG_SPELL_GO target are not filtered)
        std::list<WorldObject*> selectedTargets = targets;

        uint8 guidDataSlot = DATA_FIRST_SURGE_TARGET_GUID; // SetGuid in Malygos AI is reserved for 14th, 15th and 16th Id for the three targets
        Trinity::Containers::RandomResize(selectedTargets, 3);
        for (std::list<WorldObject*>::const_iterator itr = selectedTargets.begin(); itr != selectedTargets.end(); ++itr)
        {
            Creature* target = (*itr)->ToCreature();
            caster->AI()->SetGUID(target->GetGUID(), guidDataSlot++);

            if (Vehicle* vehicle = target->GetVehicleKit())
                if (Unit* passenger = vehicle->GetPassenger(0))
                    if (passenger->GetTypeId() == TYPEID_PLAYER)
                        caster->AI()->Talk(EMOTE_SURGE_OF_POWER_WARNING_P3, passenger);
        }
    }

    void ExecuteMainSpell()
    {
        GetCaster()->ToCreature()->CastSpell(nullptr, SPELL_SURGE_OF_POWER_PHASE_3_25);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malygos_surge_of_power_warning_selector_25::SendThreeTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterHit += SpellHitFn(spell_malygos_surge_of_power_warning_selector_25::ExecuteMainSpell);
    }
};

// 60936 - Surge of Power
class spell_malygos_surge_of_power_25 : public SpellScript
{
    PrepareSpellScript(spell_malygos_surge_of_power_25);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Creature* caster = GetCaster()->ToCreature();

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
        {
            bool found = false;
            WorldObject* target = *itr;

            for (uint32 guidSlot = DATA_FIRST_SURGE_TARGET_GUID; guidSlot < DATA_FIRST_SURGE_TARGET_GUID + NUM_MAX_SURGE_TARGETS; ++guidSlot)
            {
                if (target->GetGUID() == caster->AI()->GetGUID(guidSlot))
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                targets.erase(itr++);
            else
                ++itr;
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malygos_surge_of_power_25::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 61028 - Alexstrasza's Gift Beam
class spell_alexstrasza_gift_beam : public AuraScript
{
    PrepareAuraScript(spell_alexstrasza_gift_beam);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ALEXSTRASZAS_GIFT_BEAM_VISUAL });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->CastSpell(target, SPELL_ALEXSTRASZAS_GIFT_BEAM_VISUAL);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->RemoveAura(SPELL_ALEXSTRASZAS_GIFT_BEAM_VISUAL);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_alexstrasza_gift_beam::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_alexstrasza_gift_beam::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 61023 - Alexstrasza's Gift Visual
class spell_alexstrasza_gift_beam_visual : public AuraScript
{
    PrepareAuraScript(spell_alexstrasza_gift_beam_visual);

public:
    spell_alexstrasza_gift_beam_visual()
    {
        _alexstraszaGift = nullptr;
    }

private:
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
        {
            if (target->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                _alexstraszaGift = target->SummonGameObject(GO_ALEXSTRASZA_S_GIFT_10, *target, QuaternionData(), 0s);
            else if (target->GetMap()->GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                _alexstraszaGift = target->SummonGameObject(GO_ALEXSTRASZA_S_GIFT_25, *target, QuaternionData(), 0s);
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            {
                _alexstraszaGift->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                if (GameObject* heartMagic = target->GetMap()->GetGameObject(instance->GetGuidData(DATA_HEART_OF_MAGIC_GUID)))
                {
                    heartMagic->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    // TO DO: This is hack, core doesn't have support for these flags,
                    // remove line below if it ever gets supported otherwise object won't be accessible.
                    heartMagic->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                }
            }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_alexstrasza_gift_beam_visual::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_alexstrasza_gift_beam_visual::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

    GameObject* _alexstraszaGift;
};

class achievement_denyin_the_scion : public AchievementCriteriaScript
{
    public:
        achievement_denyin_the_scion() : AchievementCriteriaScript("achievement_denyin_the_scion") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            // Only melee disks can be used
            if (Unit* disk = source->GetVehicleBase())
                if (disk->GetEntry() == NPC_HOVER_DISK_MELEE)
                    return true;

            return false;
        }
};

void AddSC_boss_malygos()
{
    RegisterEyeOfEternityCreatureAI(boss_malygos);
    RegisterEyeOfEternityCreatureAI(npc_portal_eoe);
    RegisterEyeOfEternityCreatureAI(npc_power_spark);
    RegisterEyeOfEternityCreatureAI(npc_melee_hover_disk);
    RegisterEyeOfEternityCreatureAI(npc_caster_hover_disk);
    RegisterEyeOfEternityCreatureAI(npc_nexus_lord);
    RegisterEyeOfEternityCreatureAI(npc_scion_of_eternity);
    RegisterEyeOfEternityCreatureAI(npc_arcane_overload);
    RegisterEyeOfEternityCreatureAI(npc_wyrmrest_skytalon);
    RegisterEyeOfEternityCreatureAI(npc_static_field);

    RegisterSpellScript(spell_malygos_portal_beam);
    RegisterSpellScript(spell_malygos_random_portal);
    RegisterSpellScript(spell_malygos_arcane_storm);
    RegisterSpellScript(spell_malygos_vortex_dummy);
    RegisterSpellScript(spell_malygos_vortex_visual);
    RegisterSpellScript(spell_arcane_overload);
    RegisterSpellScript(spell_nexus_lord_align_disk_aggro);
    RegisterSpellScript(spell_scion_of_eternity_arcane_barrage);
    RegisterSpellScript(spell_malygos_destroy_platform_channel);
    RegisterSpellScript(spell_alexstrasza_bunny_destroy_platform_boom_visual);
    RegisterSpellScript(spell_alexstrasza_bunny_destroy_platform_event);
    RegisterSpellScript(spell_wyrmrest_skytalon_summon_red_dragon_buddy);
    RegisterSpellScript(spell_wyrmrest_skytalon_ride_red_dragon_buddy_trigger);
    RegisterSpellScript(spell_malygos_surge_of_power_warning_selector_25);
    RegisterSpellScript(spell_malygos_surge_of_power_25);
    RegisterSpellScript(spell_alexstrasza_gift_beam);
    RegisterSpellScript(spell_alexstrasza_gift_beam_visual);

    new achievement_denyin_the_scion();
}
