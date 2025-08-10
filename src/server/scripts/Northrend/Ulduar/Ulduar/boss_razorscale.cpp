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

#include "ScriptMgr.h"
#include "G3DPosition.hpp"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ulduar.h"

enum Says
{
    // Expedition Commander
    SAY_COMMANDER_AGGRO             = 0,
    SAY_COMMANDER_GROUND_PHASE      = 1,
    SAY_COMMANDER_ENGINEERS_DEAD    = 2,

    // Expedition Engineer
    SAY_AGGRO                       = 0,
    SAY_START_REPAIR                = 1,
    SAY_REBUILD_TURRETS             = 2,

    // Razorscale Controller
    EMOTE_HARPOON                   = 0,

    // Razorscale
    EMOTE_PERMA_GROUND              = 0,
    EMOTE_BREATH                    = 1,
    EMOTE_BERSERK                   = 2
};

enum Spells
{
    SPELL_FIREBALL                          = 63815,
    SPELL_DEVOURING_FLAME                   = 63236,
    SPELL_WING_BUFFET                       = 62666,
    SPELL_FIREBOLT                          = 62669,
    SPELL_FUSE_ARMOR                        = 64821,
    SPELL_FUSED_ARMOR                       = 64774,
    SPELL_STUN_SELF                         = 62794,
    SPELL_BERSERK                           = 47008,

    // Razorscale Harpoon Fire State
    SPELL_HARPOON_FIRE_STATE                = 62696,

    // Harpoon
    SPELL_HARPOON_TRIGGER                   = 62505,
    SPELL_HARPOON_SHOT_1                    = 63658,
    SPELL_HARPOON_SHOT_2                    = 63657,
    SPELL_HARPOON_SHOT_3                    = 63659,
    SPELL_HARPOON_SHOT_4                    = 63524,

    // Razorscale Spawner
    SPELL_SUMMON_MOLE_MACHINE               = 62899,
    SPELL_SUMMON_IRON_DWARF_GUARDIAN        = 62926,
    SPELL_TRIGGER_SUMMON_IRON_DWARVES       = 63968,
    SPELL_TRIGGER_SUMMON_IRON_DWARVES_2     = 63970,
    SPELL_TRIGGER_SUMMON_IRON_DWARVES_3     = 63969,
    SPELL_TRIGGER_SUMMON_IRON_VRYKUL        = 63798,
    SPELL_SUMMON_IRON_DWARF_WATCHER         = 63135,

    // Dark Rune Guardian
    SPELL_STORMSTRIKE                       = 64757,

    // Dark Rune Sentinel
    SPELL_BATTLE_SHOUT                      = 46763,
    SPELL_HEROIC_STRIKE                     = 45026,
    SPELL_WHIRLWIND                         = 63808,

    // Expedition Defender
    SPELL_THREAT                            = 65146,

    // Expedition Trapper
    SPELL_SHACKLE                           = 62646
};

#define DEVOURING_FLAME_GROUND RAID_MODE<uint32>(64709, 64734)
#define FLAME_BREATH           RAID_MODE<uint32>(63317, 64021)
#define CHAIN_LIGHTNING        RAID_MODE<uint32>(64758, 64759)
#define LIGHTNING_BOLT         RAID_MODE<uint32>(63809, 64696)

enum Actions
{
    ACTION_START_FIGHT = 1,
    ACTION_FIX_HARPOONS,
    ACTION_GROUND_PHASE,
    ACTION_ENGINEER_DEAD,
    ACTION_SHACKLE_RAZORSCALE,
    ACTION_START_PERMA_GROUND,
    ACTION_RETURN_TO_BASE,
    ACTION_BUILD_HARPOON_1,
    ACTION_BUILD_HARPOON_2,
    ACTION_BUILD_HARPOON_3,
    ACTION_BUILD_HARPOON_4,
    ACTION_DESTROY_HARPOONS,
    ACTION_STOP_CONTROLLERS,
    ACTION_STOP_CAST
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_FIREBALL,
    EVENT_DEVOURING_FLAME,
    EVENT_SUMMON_MINIONS,
    EVENT_SUMMON_MINIONS_2,
    EVENT_FLAME_BREATH,
    EVENT_FLAME_BREATH_GROUND,
    EVENT_WING_BUFFET,
    EVENT_RESUME_AIR_PHASE,
    EVENT_FIREBOLT,
    EVENT_FUSE_ARMOR,
    EVENT_RESUME_MOVE_CHASE,

    // Expedition Commander
    EVENT_BUILD_HARPOON_1,
    EVENT_BUILD_HARPOON_2,
    EVENT_BUILD_HARPOON_3,
    EVENT_BUILD_HARPOON_4,
    EVENT_HANDLE_DESTROY_HARPOON,

    // Dark Rune Sentinel
    EVENT_START_COMBAT,
    EVENT_HEROIC_STRIKE,
    EVENT_BATTLE_SHOUT,
    EVENT_WHIRLWIND,

    // Dark Rune Watcher
    EVENT_LIGHTNING_BOLT,
    EVENT_CHAIN_LIGHTNING,

    // Dark Rune Guardian
    EVENT_STORMSTRIKE
};

enum Misc
{
    DATA_QUICK_SHAVE                = 29192921, // 2919, 2921 are achievement IDs
    DATA_IRON_DWARF_MEDIUM_RARE     = 29232924,
    GOSSIP_START_ENCOUNTER          = 0,
    DATA_EXPEDITION_NUMBER          = 1,
    RAZORSCALE_EXPEDITION_GROUP     = 1,
    RAZORSCALE_FIRE_STATE_10_GROUP  = 2,
    RAZORSCALE_FIRE_STATE_25_GROUP  = 3,
    ENGINEER_NORTH                  = 0,
    ENGINEER_EAST                   = 1,
    ENGINEER_WEST                   = 2,
    HARPOON_1                       = 0,
    HARPOON_2                       = 1,
    HARPOON_3                       = 2,
    HARPOON_4                       = 3,
    WORLD_STATE_RAZORSCALE_MUSIC    = 4162
};

enum MovePoints
{
    POINT_DEFENDER_ATTACK = 1,
    POINT_SHACKLE_RAZORSCALE,
    POINT_BASE,
    POINT_HARPOON_1,
    POINT_HARPOON_1_25,
    POINT_HARPOON_2,
    POINT_HARPOON_2_25,
    POINT_HARPOON_3,
    POINT_HARPOON_4,
    POINT_RAZORSCALE_FLIGHT,
    POINT_RAZORSCALE_TAKEOFF,
    POINT_RAZORSCALE_FLIGHT_2,
    POINT_RAZORSCALE_LAND,
    POINT_RAZORSCALE_GROUND,
    POINT_START_WAYPOINT
};

enum EngineersSplineMovements
{
    SPLINE_ENGINEER_NORTH_10_HARPOON_1  = 1,
    SPLINE_ENGINEER_NORTH_10_HARPOON_2  = 2,
    SPLINE_ENGINEER_NORTH_10_BASE       = 3,
    SPLINE_ENGINEER_NORTH_25_HARPOON_1  = 4,
    SPLINE_ENGINEER_NORTH_25_HARPOON_2  = 5,
    SPLINE_ENGINEER_NORTH_25_HARPOON_3  = 6,
    SPLINE_ENGINEER_NORTH_25_HARPOON_4  = 7,
    SPLINE_ENGINEER_NORTH_25_BASE       = 8,
    SPLINE_ENGINEER_EAST_10_HARPOON_1   = 9,
    SPLINE_ENGINEER_EAST_10_HARPOON_2   = 10,
    SPLINE_ENGINEER_EAST_10_BASE        = 11,
    SPLINE_ENGINEER_EAST_25_HARPOON_1   = 12,
    SPLINE_ENGINEER_EAST_25_HARPOON_2   = 13,
    SPLINE_ENGINEER_EAST_25_HARPOON_3   = 14,
    SPLINE_ENGINEER_EAST_25_HARPOON_4   = 15,
    SPLINE_ENGINEER_WEST_10_HARPOON_1   = 16,
    SPLINE_ENGINEER_WEST_10_HARPOON_2   = 17,
    SPLINE_ENGINEER_WEST_10_BASE        = 18,
    SPLINE_ENGINEER_WEST_25_HARPOON_1   = 19,
    SPLINE_ENGINEER_WEST_25_HARPOON_2   = 20,
    SPLINE_ENGINEER_WEST_25_HARPOON_3   = 21,
    SPLINE_ENGINEER_WEST_25_HARPOON_4   = 22,
    SPLINE_ENGINEER_WEST_25_BASE        = 23
};

enum RazorscalePhases
{
    PHASE_NONE = 0,
    PHASE_COMBAT,
    PHASE_GROUND,
    PHASE_AIR,
    PHASE_PERMA_GROUND
};

constexpr Position PosBrokenHarpoon[4] =
{
    { 571.9465f, -136.0118f, 391.5171f, 2.286379f }, // 1
    { 589.9233f, -133.6223f, 391.8968f, 3.298687f }, // 2
    { 559.1199f, -140.5058f, 391.1803f, 4.049168f }, // 0
    { 606.2297f, -136.7212f, 391.1803f, 5.131269f }  // 3
};

constexpr Position PosHarpoon[4] =
{
    { 571.9012f, -136.5541f, 391.5171f, 4.921829f }, // GO_RAZOR_HARPOON_1
    { 589.9233f, -133.6223f, 391.8968f, 4.81711f  }, // GO_RAZOR_HARPOON_2
    { 559.1199f, -140.5058f, 391.1803f, 5.061456f }, // GO_RAZOR_HARPOON_3
    { 606.2297f, -136.7212f, 391.1803f, 4.537859f }  // GO_RAZOR_HARPOON_4
};

constexpr Position DefendersPosition[6] =
{
    { 624.3065f, -154.4163f, 391.6442f },
    { 611.6274f, -170.9375f, 391.8087f },
    { 572.1548f, -167.4471f, 391.8087f },
    { 558.4640f, -165.0114f, 391.8087f },
    { 603.3345f, -164.4297f, 391.8087f },
    { 549.1727f, -159.1180f, 391.8087f }
};

constexpr Position TrapperPosition[3] =
{
    { 574.9293f, -184.5150f, 391.8921f },
    { 539.7838f, -178.5337f, 391.3053f },
    { 627.1754f, -177.9638f, 391.5553f }
};

constexpr uint32 SummonMinionsSpells[4] =
{
    SPELL_TRIGGER_SUMMON_IRON_DWARVES,
    SPELL_TRIGGER_SUMMON_IRON_DWARVES_2,
    SPELL_TRIGGER_SUMMON_IRON_DWARVES_3,
    SPELL_TRIGGER_SUMMON_IRON_VRYKUL
};

constexpr Position RazorscalePath[] =
{
    { 657.0227f, -361.1278f, 519.5406f },
    { 698.9319f, -340.9654f, 520.4857f },
    { 713.8673f, -290.2219f, 518.4573f },
    { 711.1782f, -259.6798f, 524.6802f },
    { 695.5101f, -234.6734f, 529.1528f },
    { 666.9619f, -220.7599f, 531.4860f },
    { 629.2765f, -219.7951f, 528.9301f },
    { 597.4018f, -233.7745f, 526.6508f },
    { 577.5307f, -275.4489f, 528.1241f },
    { 583.1092f, -319.5873f, 527.9302f },
    { 611.5800f, -353.1930f, 526.2653f }
};

constexpr Position RazorFlightPosition       = { 585.3610f, -173.5592f, 456.8430f, 1.526665f };
constexpr Position RazorFlightPositionPhase2 = { 619.1450f, -238.0780f, 475.1800f, 1.423917f };
constexpr Position RazorscaleLand            = { 585.4010f, -173.5430f, 408.5080f, 1.570796f };
constexpr Position RazorscaleGroundPosition  = { 585.4010f, -173.5430f, 391.6421f, 1.570796f };

struct boss_razorscale : public BossAI
{
    boss_razorscale(Creature* creature) : BossAI(creature, DATA_RAZORSCALE)
    {
        Initialize();
    }

    void Initialize()
    {
        _engineersCount = 3;
        _defendersCount = 0;
        _engineersSummonCount = 0;
        _harpoonHitCount = 0;
        _trappersCount = 0;
        _permaGround = false;
        _flyCount = 0;
        me->SetDisableGravity(true);
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        events.SetPhase(PHASE_NONE);
        me->SummonCreatureGroup(RAZORSCALE_EXPEDITION_GROUP);
        me->SummonCreatureGroup(RAZORSCALE_FIRE_STATE_10_GROUP);
        if (Is25ManRaid())
            me->SummonCreatureGroup(RAZORSCALE_FIRE_STATE_25_GROUP);
        // @Developer remove this comment when someone create a way to change view distance for objects
        // me->GetMotionMaster()->MovePoint(POINT_START_WAYPOINT, RazorscaleFirstPoint);
        // And apply it on DB: UPDATE `creature` SET `position_x`=699.7847, `position_y`=-424.8246, `position_z`=589.2745, `orientation`=1.972222 WHERE `guid`=137611; -- Razorscale
        SetCombatMovement(false);
    }

    void HandleInitialMovement()
    {
        std::function<void(Movement::MoveSplineInit&)> initializer = [](Movement::MoveSplineInit& init)
        {
            Movement::PointsArray path(std::size(RazorscalePath));
            std::transform(std::begin(RazorscalePath), std::end(RazorscalePath), path.begin(), [](Position pos) { return PositionToVector3(pos); });
            init.MovebyPath(path, 0);
            init.SetCyclic();
            init.SetFly();
        };
        me->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), 0, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
    }

    bool CanAIAttack(Unit const* target) const override
    {
        switch (target->GetEntry())
        {
            case NPC_EXPEDITION_DEFENDER:
            case NPC_EXPEDITION_TRAPPER:
            case NPC_EXPEDITION_COMMANDER:
            case NPC_EXPEDITION_ENGINEER:
                return false;
            default:
                return BossAI::CanAIAttack(target);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        ScheduleAirPhaseEvents();
        summons.DoAction(ACTION_START_FIGHT, DummyEntryCheckPredicate());
        events.ScheduleEvent(EVENT_BERSERK, 15min);
        HandleMusic(true);
    }

    void ScheduleAirPhaseEvents()
    {
        events.ScheduleEvent(EVENT_FIREBALL, Seconds(3), 0, PHASE_AIR);
        events.ScheduleEvent(EVENT_DEVOURING_FLAME, Seconds(9), 0, PHASE_AIR);
        events.ScheduleEvent(EVENT_SUMMON_MINIONS, Seconds(1), 0, PHASE_AIR);
    }

    void ScheduleGroundPhaseEvents()
    {
        events.ScheduleEvent(EVENT_FIREBOLT, Seconds(3), 0, PHASE_PERMA_GROUND);
        events.ScheduleEvent(EVENT_FUSE_ARMOR, Seconds(15), 0, PHASE_PERMA_GROUND);
        events.ScheduleEvent(EVENT_FLAME_BREATH_GROUND, Seconds(18), 0, PHASE_PERMA_GROUND);
        events.ScheduleEvent(EVENT_DEVOURING_FLAME, Seconds(22), 0, PHASE_PERMA_GROUND);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_START_FIGHT:
                me->SetImmuneToPC(false);
                me->SetSpeedRate(MOVE_RUN, 3.0f);
                me->StopMoving();
                me->GetMotionMaster()->MovePoint(POINT_RAZORSCALE_FLIGHT, RazorFlightPosition);
                break;
            case ACTION_GROUND_PHASE:
                me->InterruptNonMeleeSpells(false);
                events.SetPhase(PHASE_GROUND);
                _harpoonHitCount = 0;
                me->SetSpeedRate(MOVE_RUN, 3.0f);
                me->GetMotionMaster()->MovePoint(POINT_RAZORSCALE_LAND, RazorscaleLand);
                break;
            case ACTION_START_PERMA_GROUND:
            {
                me->SetDisableGravity(false);
                me->RemoveAurasDueToSpell(SPELL_STUN_SELF);
                Talk(EMOTE_PERMA_GROUND);
                DoCastSelf(SPELL_WING_BUFFET);
                EntryCheckPredicate pred(NPC_EXPEDITION_TRAPPER);
                summons.DoAction(ACTION_STOP_CAST, pred);
                events.ScheduleEvent(EVENT_RESUME_MOVE_CHASE, Milliseconds(1));
                ScheduleGroundPhaseEvents();
                break;
            }
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_START_WAYPOINT:
                HandleInitialMovement();
                break;
            case POINT_RAZORSCALE_FLIGHT:
                me->UpdateSpeed(MOVE_RUN);
                me->SetFacingTo(RazorFlightPosition.GetOrientation());
                DoZoneInCombat();
                break;
            case POINT_RAZORSCALE_GROUND:
                me->SetDisableGravity(false);
                if (!_permaGround)
                {
                    DoCastSelf(SPELL_STUN_SELF, true);
                    EntryCheckPredicate pred(NPC_EXPEDITION_TRAPPER);
                    summons.DoAction(ACTION_SHACKLE_RAZORSCALE, pred);
                    if (Creature* commander = instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                        commander->AI()->DoAction(ACTION_GROUND_PHASE);
                    events.ScheduleEvent(EVENT_FLAME_BREATH, Seconds(30), 0, PHASE_GROUND);
                }
                break;
            case POINT_RAZORSCALE_TAKEOFF:
                me->SetSpeedRate(MOVE_RUN, 3.0f);
                me->GetMotionMaster()->MovePoint(POINT_RAZORSCALE_FLIGHT_2, RazorFlightPositionPhase2);
                break;
            case POINT_RAZORSCALE_FLIGHT_2:
                me->SetFacingTo(RazorFlightPositionPhase2.GetOrientation());
                me->SetReactState(REACT_AGGRESSIVE);
                ScheduleAirPhaseEvents();
                ++_flyCount;
                me->UpdateSpeed(MOVE_RUN);
                break;
            case POINT_RAZORSCALE_LAND:
                me->UpdateSpeed(MOVE_RUN);
                me->SetFacingTo(RazorscaleLand.GetOrientation());
                me->GetMotionMaster()->MoveLand(POINT_RAZORSCALE_GROUND, RazorscaleGroundPosition);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        switch (summon->GetEntry())
        {
            case NPC_EXPEDITION_DEFENDER:
                summon->AI()->SetData(DATA_EXPEDITION_NUMBER, _defendersCount);
                ++_defendersCount;
                break;
            case NPC_EXPEDITION_ENGINEER:
                summon->AI()->SetData(DATA_EXPEDITION_NUMBER, _engineersSummonCount);
                ++_engineersSummonCount;
                break;
            case NPC_EXPEDITION_TRAPPER:
                summon->AI()->SetData(DATA_EXPEDITION_NUMBER, _trappersCount);
                ++_trappersCount;
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_EXPEDITION_ENGINEER)
        {
            _engineersCount--;
            if (_engineersCount == 0)
                if (Creature* commander = instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                    commander->AI()->DoAction(ACTION_ENGINEER_DEAD);
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_HARPOON_TRIGGER)
        {
            _harpoonHitCount++;
            if (_harpoonHitCount == RAID_MODE(2, 4))
                DoAction(ACTION_GROUND_PHASE);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_QUICK_SHAVE && _flyCount <= 1)
            return 1;
        return 0;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (why == EvadeReason::Boundary && !events.IsInPhase(PHASE_PERMA_GROUND))
            return;

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        HandleMusic(false);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        HandleMusic(false);
    }

    void HandleMusic(bool active)
    {
        int32 enabled = active ? 1 : 0;
        instance->DoUpdateWorldState(WORLD_STATE_RAZORSCALE_MUSIC, enabled);
    }

    void SummonMinions()
    {
        float x = frand(540.0f, 640.0f);       // Safe range is between 500 and 650
        float y = frand(-230.0f, -195.0f);     // Safe range is between -235 and -145
        float z = 391.517f;                     // Ground level
        me->SummonCreature(NPC_RAZORSCALE_SPAWNER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 15s);
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_permaGround && me->HealthBelowPctDamaged(50, damage) && events.IsInPhase(PHASE_GROUND))
        {
            _permaGround = true;
            me->SetReactState(REACT_AGGRESSIVE);
            events.SetPhase(PHASE_PERMA_GROUND);
            DoAction(ACTION_START_PERMA_GROUND);
        }
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
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    Talk(EMOTE_BERSERK, me);
                    break;
                case EVENT_FIREBALL:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        DoCast(target, SPELL_FIREBALL);
                    events.Repeat(Seconds(2), Seconds(3));
                    break;
                case EVENT_DEVOURING_FLAME:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        DoCast(target, SPELL_DEVOURING_FLAME);
                    if (_permaGround)
                        events.Repeat(Seconds(10), Seconds(12));
                    else
                        events.Repeat(Seconds(6), Seconds(12));
                    break;
                case EVENT_SUMMON_MINIONS:
                {
                    uint8 random = RAID_MODE<uint8>(2, urand(2, 4));
                    uint8 time = 5;
                    for (uint8 n = 0; n < random; ++n)
                    {
                        events.ScheduleEvent(EVENT_SUMMON_MINIONS_2, Seconds(time), 0, PHASE_AIR);
                        time += urand(2, 5);
                    }
                    events.Repeat(Seconds(40));
                    break;
                }
                case EVENT_SUMMON_MINIONS_2:
                    SummonMinions();
                    break;
                case EVENT_FLAME_BREATH:
                    me->RemoveAurasDueToSpell(SPELL_STUN_SELF);
                    Talk(EMOTE_BREATH, me);
                    DoCastVictim(FLAME_BREATH);
                    events.ScheduleEvent(EVENT_WING_BUFFET, Seconds(2), 0, PHASE_GROUND);
                    break;
                case EVENT_FLAME_BREATH_GROUND:
                    Talk(EMOTE_BREATH, me);
                    DoCastVictim(FLAME_BREATH);
                    events.Repeat(Seconds(15), Seconds(18));
                    break;
                case EVENT_WING_BUFFET:
                {
                    DoCastSelf(SPELL_WING_BUFFET);
                    events.ScheduleEvent(EVENT_FIREBOLT, Seconds(2), 0, PHASE_GROUND);
                    events.ScheduleEvent(EVENT_RESUME_AIR_PHASE, Seconds(4), 0, PHASE_GROUND);
                    EntryCheckPredicate pred(NPC_EXPEDITION_TRAPPER);
                    summons.DoAction(ACTION_STOP_CAST, pred);
                    break;
                }
                case EVENT_RESUME_AIR_PHASE:
                {
                    me->SetDisableGravity(true);
                    events.SetPhase(PHASE_AIR);
                    me->SetReactState(REACT_PASSIVE);
                    Position pos = me->GetPosition();
                    pos.m_positionZ += 10.0f;
                    me->GetMotionMaster()->MoveTakeoff(POINT_RAZORSCALE_TAKEOFF, pos);
                    EntryCheckPredicate pred(NPC_EXPEDITION_ENGINEER);
                    summons.DoAction(ACTION_FIX_HARPOONS, pred);
                    break;
                }
                case EVENT_FIREBOLT:
                    DoCastSelf(SPELL_FIREBOLT);
                    break;
                case EVENT_FUSE_ARMOR:
                    if (Unit* victim = me->GetVictim())
                        if (!victim->HasAura(SPELL_FUSED_ARMOR))
                            DoCast(victim, SPELL_FUSE_ARMOR);
                    events.Repeat(Seconds(10), Seconds(15));
                    break;
                case EVENT_RESUME_MOVE_CHASE:
                    SetCombatMovement(true);
                    if (Unit* victim = me->GetVictim())
                        me->GetMotionMaster()->MoveChase(victim);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    uint8 _engineersCount;
    uint8 _engineersSummonCount;
    uint8 _defendersCount;
    uint8 _harpoonHitCount;
    uint8 _trappersCount;
    bool _permaGround;
    uint32 _flyCount;
};

struct npc_expedition_commander : public ScriptedAI
{
    npc_expedition_commander(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()),
        _is25Man(Is25ManRaid()), _building(false), _destroy(false), _stopControllers(false) { }

    void Reset() override
    {
        _events.Reset();
        _events.SetPhase(PHASE_NONE);
        BuildBrokenHarpoons();
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId == GOSSIP_START_ENCOUNTER)
        {
            CloseGossipMenuFor(player);
            _events.SetPhase(PHASE_COMBAT);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            if (Creature* razorscale = _instance->GetCreature(DATA_RAZORSCALE))
                razorscale->AI()->DoAction(ACTION_START_FIGHT);
            return true;
        }
        return false;
    }

    void BuildBrokenHarpoons()
    {
        uint8 harpoonNumber = _is25Man ? 4 : 2;
        for (uint8 i = 0; i < harpoonNumber; ++i)
            me->SummonGameObject(GO_RAZOR_BROKEN_HARPOON, PosBrokenHarpoon[i], QuaternionData(0.0f, 0.0f, -0.8987932f, 0.4383728f), 7_days);
    }

    void DestroyHarpoons()
    {
        for (ObjectGuid harpoonGuid : _harpoons)
            if (GameObject* harpoon = ObjectAccessor::GetGameObject(*me, harpoonGuid))
                harpoon->RemoveFromWorld();

        _harpoons.clear();
        BuildBrokenHarpoons();
        _events.ScheduleEvent(EVENT_HANDLE_DESTROY_HARPOON, 10s);
    }

    void HandleControllersStopCast()
    {
        std::list<Creature*> Controllers;
        me->GetCreatureListWithEntryInGrid(Controllers, NPC_RAZORSCALE_CONTROLLER, 100.0f);

        for (Creature* controller : Controllers)
            controller->InterruptNonMeleeSpells(false);

        _stopControllers = false;
    }

    void BuildHarpoon(uint8 harpoonNumber)
    {

        if (_is25Man)
        {
            switch (harpoonNumber)
            {
                case HARPOON_1:
                    if (GameObject* harpoon = me->SummonGameObject(GO_RAZOR_HARPOON_3, PosHarpoon[2], QuaternionData(0.0f, 0.0f, -0.573576f, 0.8191524f), 7_days))
                        _harpoons.emplace_back(harpoon->GetGUID());
                    break;
                case HARPOON_2:
                    if (GameObject* harpoon = me->SummonGameObject(GO_RAZOR_HARPOON_1, PosHarpoon[0], QuaternionData(0.0f, 0.0f, -0.6293201f, 0.7771462f), 7_days))
                        _harpoons.emplace_back(harpoon->GetGUID());
                    break;
                case HARPOON_3:
                    if (GameObject* harpoon = me->SummonGameObject(GO_RAZOR_HARPOON_2, PosHarpoon[1], QuaternionData(0.0f, 0.0f, -0.6691303f, 0.743145f), 7_days))
                        _harpoons.emplace_back(harpoon->GetGUID());
                    break;
                case HARPOON_4:
                    if (GameObject* harpoon = me->SummonGameObject(GO_RAZOR_HARPOON_4, PosHarpoon[3], QuaternionData(0.0f, 0.0f, -0.7660437f, 0.6427886f), 7_days))
                        _harpoons.emplace_back(harpoon->GetGUID());
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (harpoonNumber)
            {
                case HARPOON_1:
                    if (GameObject* harpoon = me->SummonGameObject(GO_RAZOR_HARPOON_1, PosHarpoon[harpoonNumber], QuaternionData(0.0f, 0.0f, -0.6293201f, 0.7771462f), 0s))
                        _harpoons.emplace_back(harpoon->GetGUID());
                    break;
                case HARPOON_2:
                    if (GameObject* harpoon = me->SummonGameObject(GO_RAZOR_HARPOON_2, PosHarpoon[harpoonNumber], QuaternionData(0.0f, 0.0f, -0.6691303f, 0.743145f), 0s))
                        _harpoons.emplace_back(harpoon->GetGUID());
                    break;
                default:
                    break;
            }
        }
    }

    void DoAction(int32 actionId) override
    {
        if (_building && actionId != ACTION_ENGINEER_DEAD)
            return;

        switch (actionId)
        {
            case ACTION_START_FIGHT:
                Talk(SAY_COMMANDER_AGGRO);
                break;
            case ACTION_GROUND_PHASE:
                Talk(SAY_COMMANDER_GROUND_PHASE);
                break;
            case ACTION_ENGINEER_DEAD:
                Talk(SAY_COMMANDER_ENGINEERS_DEAD);
                _events.Reset();
                _building = false;
                break;
            case ACTION_BUILD_HARPOON_1:
                _building = true;
                _events.ScheduleEvent(EVENT_BUILD_HARPOON_1, Seconds(18));
                break;
            case ACTION_BUILD_HARPOON_2:
                _building = true;
                _events.ScheduleEvent(EVENT_BUILD_HARPOON_2, Seconds(18));
                break;
            case ACTION_BUILD_HARPOON_3:
                _building = true;
                _events.ScheduleEvent(EVENT_BUILD_HARPOON_3, Seconds(18));
                break;
            case ACTION_BUILD_HARPOON_4:
                _building = true;
                _events.ScheduleEvent(EVENT_BUILD_HARPOON_4, Seconds(18));
                break;
            case ACTION_DESTROY_HARPOONS:
                if (_destroy)
                    return;
                _destroy = true;
                DestroyHarpoons();
                break;
            case ACTION_STOP_CONTROLLERS:
                if (_stopControllers)
                    return;
                _stopControllers = true;
                HandleControllersStopCast();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_events.IsInPhase(PHASE_COMBAT))
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BUILD_HARPOON_1:
                    BuildHarpoon(HARPOON_1);
                    _building = false;
                    break;
                case EVENT_BUILD_HARPOON_2:
                    BuildHarpoon(HARPOON_2);
                    _building = false;
                    break;
                case EVENT_BUILD_HARPOON_3:
                    BuildHarpoon(HARPOON_3);
                    _building = false;
                    break;
                case EVENT_BUILD_HARPOON_4:
                    BuildHarpoon(HARPOON_4);
                    _building = false;
                    break;
                case EVENT_HANDLE_DESTROY_HARPOON:
                    _destroy = false;
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    GuidVector _harpoons;
    bool _is25Man;
    bool _building;
    bool _destroy;
    bool _stopControllers;
    EventMap _events;
};

struct npc_expedition_defender : public ScriptedAI
{
    npc_expedition_defender(Creature* creature) : ScriptedAI(creature), _myPositionNumber(0), _instance(creature->GetInstanceScript())
    {
        me->SetRegenerateHealth(false);
    }

    void Reset() override
    {
        DoCastSelf(SPELL_THREAT);
    }

    bool CanAIAttack(Unit const* target) const override
    {
        if (target->GetEntry() == NPC_RAZORSCALE || target->GetEntry() == NPC_RAZORSCALE_SPAWNER)
            return false;

        return ScriptedAI::CanAIAttack(target);
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_EXPEDITION_NUMBER)
            _myPositionNumber = value;
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_START_FIGHT)
            me->GetMotionMaster()->MovePoint(POINT_DEFENDER_ATTACK, DefendersPosition[_myPositionNumber]);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && pointId != POINT_DEFENDER_ATTACK)
            return;

        me->SetHomePosition(DefendersPosition[_myPositionNumber]);
        me->SetImmuneToNPC(false);
    }

private:
    uint8 _myPositionNumber;
    InstanceScript* _instance;
};

struct npc_expedition_trapper : public ScriptedAI
{
    npc_expedition_trapper(Creature* creature) : ScriptedAI(creature), _myPositionNumber(0), _instance(creature->GetInstanceScript())
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
    }

    void DoAction(int32 actionId) override
    {
        if (!me->IsAlive())
            return;

        switch (actionId)
        {
            case ACTION_SHACKLE_RAZORSCALE:
                me->GetMotionMaster()->MovePoint(POINT_SHACKLE_RAZORSCALE, TrapperPosition[_myPositionNumber]);
                break;
            case ACTION_RETURN_TO_BASE:
                me->GetMotionMaster()->MoveTargetedHome();
                break;
            case ACTION_START_FIGHT:
                me->SetImmuneToNPC(false);
                break;
            case ACTION_STOP_CAST:
                me->InterruptNonMeleeSpells(false);
                _scheduler.Schedule(Seconds(2), [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MoveTargetedHome();
                });
                if (Creature* commander = _instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                    commander->AI()->DoAction(ACTION_STOP_CONTROLLERS);
                break;
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_EXPEDITION_NUMBER)
            _myPositionNumber = value;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && pointId != POINT_SHACKLE_RAZORSCALE)
            return;

        DoCastSelf(SPELL_SHACKLE);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    uint8 _myPositionNumber;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

struct npc_expedition_engineer : public ScriptedAI
{
    npc_expedition_engineer(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _myPositionNumber(0), _canUpdateAI(false) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _scheduler.CancelAll();
    }

    void DoAction(int32 actionId) override
    {
        if (!me->IsAlive())
            return;

        if (actionId == ACTION_START_FIGHT)
        {
            _canUpdateAI = true;
            if (_myPositionNumber == ENGINEER_EAST)
                Talk(SAY_AGGRO);
            _scheduler.Schedule(Seconds(28), [this](TaskContext /*context*/)
            {
                HandleHarpoonMovement();
                me->SetImmuneToNPC(false);
            });
        }
        else if (actionId == ACTION_FIX_HARPOONS)
        {
            if (_myPositionNumber == ENGINEER_EAST)
                Talk(SAY_AGGRO);
            _scheduler.Schedule(Seconds(28), [this](TaskContext /*context*/)
            {
                HandleHarpoonMovement();
            });
        }
    }

    void ChangeOrientation(float orientation)
    {
        _scheduler.Schedule(Milliseconds(1), [this, orientation](TaskContext /*context*/)
        {
            me->SetFacingTo(orientation);
        });
    }

    void HandleHarpoonMovement()
    {
        switch (_myPositionNumber)
        {
            case ENGINEER_NORTH:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_1_25, SPLINE_ENGINEER_NORTH_25_HARPOON_1, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_1, SPLINE_ENGINEER_NORTH_10_HARPOON_1, false);
                break;
            case ENGINEER_EAST:
                Talk(SAY_START_REPAIR);
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_1_25, SPLINE_ENGINEER_EAST_25_HARPOON_1, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_1, SPLINE_ENGINEER_EAST_10_HARPOON_1, false);
                break;
            case ENGINEER_WEST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_1_25, SPLINE_ENGINEER_WEST_25_HARPOON_1, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_1, SPLINE_ENGINEER_WEST_10_HARPOON_1, false);
                break;
            default:
                break;
        }
    }

    void HandleSecondHarpoonMovement()
    {
        switch (_myPositionNumber)
        {
            case ENGINEER_NORTH:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_2_25, SPLINE_ENGINEER_NORTH_25_HARPOON_2, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_2, SPLINE_ENGINEER_NORTH_10_HARPOON_2, false);
                break;
            case ENGINEER_EAST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_2_25, SPLINE_ENGINEER_EAST_25_HARPOON_2, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_2, SPLINE_ENGINEER_EAST_10_HARPOON_2, false);
                break;
            case ENGINEER_WEST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_2_25, SPLINE_ENGINEER_WEST_25_HARPOON_2, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_2, SPLINE_ENGINEER_WEST_10_HARPOON_2, false);
                break;
            default:
                break;
        }
    }

    void HandleThirdHarpoonMovement()
    {
        switch (_myPositionNumber)
        {
            case ENGINEER_NORTH:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_3, SPLINE_ENGINEER_NORTH_25_HARPOON_3, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_BASE, SPLINE_ENGINEER_NORTH_10_BASE, false);
                break;
            case ENGINEER_EAST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_3, SPLINE_ENGINEER_EAST_25_HARPOON_3, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_BASE, SPLINE_ENGINEER_EAST_10_BASE, false);
                break;
            case ENGINEER_WEST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_3, SPLINE_ENGINEER_WEST_25_HARPOON_3, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_BASE, SPLINE_ENGINEER_WEST_10_BASE, false);
                break;
            default:
                break;
        }
    }

    void HandleFourthHarpoonMovement()
    {
        switch (_myPositionNumber)
        {
            case ENGINEER_NORTH:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_4, SPLINE_ENGINEER_NORTH_25_HARPOON_4, false);
                break;
            case ENGINEER_EAST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_4, SPLINE_ENGINEER_EAST_25_HARPOON_4, false);
                break;
            case ENGINEER_WEST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_HARPOON_4, SPLINE_ENGINEER_WEST_25_HARPOON_4, false);
                break;
            default:
                break;
        }
    }

    void HandleBaseMovement()
    {
        switch (_myPositionNumber)
        {
            case ENGINEER_NORTH:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_BASE, SPLINE_ENGINEER_NORTH_25_BASE, false);
                break;
            case ENGINEER_EAST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MovePoint(POINT_BASE, me->GetHomePosition());
                break;
            case ENGINEER_WEST:
                if (Is25ManRaid())
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_BASE, SPLINE_ENGINEER_WEST_25_BASE, false);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_canUpdateAI)
            return;

        _scheduler.Update(diff);
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_EXPEDITION_NUMBER)
            _myPositionNumber = value;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != SPLINE_CHAIN_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_HARPOON_1:
            case POINT_HARPOON_1_25:
                if (Creature* commander = _instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                    commander->AI()->DoAction(ACTION_BUILD_HARPOON_1);

                _scheduler.
                    Schedule(Seconds(3), [this](TaskContext /*context*/)
                {
                    me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                })
                    .Schedule(Seconds(18), [this](TaskContext /*context*/)
                {
                    HandleSecondHarpoonMovement();
                });
                break;
            case POINT_HARPOON_2:
            case POINT_HARPOON_2_25:
                if (Creature* commander = _instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                    commander->AI()->DoAction(ACTION_BUILD_HARPOON_2);
                _scheduler.Schedule(Seconds(18), [this](TaskContext /*context*/)
                {
                    HandleThirdHarpoonMovement();
                });
                break;
            case POINT_HARPOON_3:
                if (Creature* commander = _instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                    commander->AI()->DoAction(ACTION_BUILD_HARPOON_3);
                _scheduler.Schedule(Seconds(18), [this](TaskContext /*context*/)
                {
                    HandleFourthHarpoonMovement();
                });
                break;
            case POINT_HARPOON_4:
                if (Creature* commander = _instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                    commander->AI()->DoAction(ACTION_BUILD_HARPOON_4);
                _scheduler.Schedule(Seconds(18), [this](TaskContext /*context*/)
                {
                    HandleBaseMovement();
                });
                break;
            case POINT_BASE:
                ChangeOrientation(4.61684f);
                break;
            default:
                break;
        }
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    uint8 _myPositionNumber;
    bool _canUpdateAI;
};

struct npc_razorscale_spawner : public ScriptedAI
{
    npc_razorscale_spawner(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->setActive(true);
        me->SetFarVisible(true);
        me->SetReactState(REACT_PASSIVE);
        _scheduler.
            Schedule(Seconds(1), [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_SUMMON_MOLE_MACHINE);
        }).Schedule(Seconds(6), [this](TaskContext /*context*/)
        {
            DoCastSelf(SummonMinionsSpells[urand(0, 3)]);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_darkrune_watcher : public ScriptedAI
{
    npc_darkrune_watcher(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_START_COMBAT, 2s);
        if (Creature* razorscale = _instance->GetCreature(DATA_RAZORSCALE))
            razorscale->AI()->JustSummoned(me);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 5s);
        _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 34s);
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
            switch (eventId)
            {
                case EVENT_START_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                case EVENT_LIGHTNING_BOLT:
                    DoCastVictim(LIGHTNING_BOLT);
                    _events.Repeat(Seconds(3));
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    DoCastVictim(CHAIN_LIGHTNING);
                    _events.Repeat(Seconds(9), Seconds(15));
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_darkrune_guardian : public ScriptedAI
{
    npc_darkrune_guardian(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _killedByBreath(false) { }

    void Reset() override
    {
        _events.Reset();
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_START_COMBAT, 2s);
        if (Creature* razorscale = _instance->GetCreature(DATA_RAZORSCALE))
            razorscale->AI()->JustSummoned(me);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_STORMSTRIKE, 23s);
    }

    uint32 GetData(uint32 type) const override
    {
        return type == DATA_IRON_DWARF_MEDIUM_RARE ? _killedByBreath : 0;
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_IRON_DWARF_MEDIUM_RARE)
            _killedByBreath = value != 0;
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
            switch (eventId)
            {
                case EVENT_START_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                case EVENT_STORMSTRIKE:
                    DoCastVictim(SPELL_STORMSTRIKE);
                    _events.Repeat(Seconds(13), Seconds(25));
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    bool _killedByBreath;
};

struct npc_darkrune_sentinel : public ScriptedAI
{
    npc_darkrune_sentinel(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_START_COMBAT, 2s);
        if (Creature* razorscale = _instance->GetCreature(DATA_RAZORSCALE))
            razorscale->AI()->JustSummoned(me);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_HEROIC_STRIKE, 9s);
        _events.ScheduleEvent(EVENT_BATTLE_SHOUT, 15s);
        _events.ScheduleEvent(EVENT_WHIRLWIND, 17s);
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
            switch (eventId)
            {
                case EVENT_START_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                case EVENT_HEROIC_STRIKE:
                    DoCastVictim(SPELL_HEROIC_STRIKE);
                    _events.Repeat(Seconds(5), Seconds(9));
                    break;
                case EVENT_BATTLE_SHOUT:
                    DoCastSelf(SPELL_BATTLE_SHOUT);
                    _events.Repeat(Seconds(25));
                    break;
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    _events.Repeat(Seconds(10), Seconds(13));
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_razorscale_harpoon_fire_state : public ScriptedAI
{
    npc_razorscale_harpoon_fire_state(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FIREBOLT)
        {
            DoCastSelf(SPELL_HARPOON_FIRE_STATE);
            if (Creature* commander = _instance->GetCreature(DATA_EXPEDITION_COMMANDER))
                commander->AI()->DoAction(ACTION_DESTROY_HARPOONS);
        }
    }

private:
    InstanceScript* _instance;
};

struct npc_razorscale_devouring_flame : public ScriptedAI
{
    npc_razorscale_devouring_flame(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(DEVOURING_FLAME_GROUND, true);
    }

    // Evade caused by Spell::SummonGuardian. Creature dont need evade at all, is despawned if razorscale enter in evade
    void EnterEvadeMode(EvadeReason /*why*/) override { }
};

class go_razorscale_harpoon : public GameObjectScript
{
public:
    go_razorscale_harpoon() : GameObjectScript("go_razorscale_harpoon") { }

    struct go_razorscale_harpoonAI : public GameObjectAI
    {
        go_razorscale_harpoonAI(GameObject* go) : GameObjectAI(go) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(1), [this](TaskContext /*context*/)
            {
                if (Creature* controller = me->FindNearestCreature(NPC_RAZORSCALE_CONTROLLER, 5.0f))
                    controller->AI()->Talk(EMOTE_HARPOON);

                if (GameObject* brokenHarpoon = me->FindNearestGameObject(GO_RAZOR_BROKEN_HARPOON, 5.0f))
                    brokenHarpoon->RemoveFromWorld();
            });
        }

        uint32 SelectRightSpell()
        {
            switch (me->GetEntry())
            {
                case GO_RAZOR_HARPOON_1:
                    return SPELL_HARPOON_SHOT_1;
                case GO_RAZOR_HARPOON_2:
                    return SPELL_HARPOON_SHOT_2;
                case GO_RAZOR_HARPOON_3:
                    return SPELL_HARPOON_SHOT_3;
                case GO_RAZOR_HARPOON_4:
                    return SPELL_HARPOON_SHOT_4;
                default:
                    return 0;
            }
        }

        bool OnGossipHello(Player* /*player*/) override
        {
            me->SetFlag(GO_FLAG_NOT_SELECTABLE);
            if (Creature* controller = me->FindNearestCreature(NPC_RAZORSCALE_CONTROLLER, 5.0f))
            {
                // Prevent 2 players clicking at "same time"
                if (controller->HasUnitState(UNIT_STATE_CASTING))
                    return true;

                uint32 spellId = SelectRightSpell();
                controller->CastSpell(nullptr, spellId, true);
            }

            return true;
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetUlduarAI<go_razorscale_harpoonAI>(go);
    }
};

class go_razorscale_mole_machine : public GameObjectScript
{
public:
    go_razorscale_mole_machine() : GameObjectScript("go_razorscale_mole_machine") { }

    struct go_razorscale_mole_machineAI : public GameObjectAI
    {
        go_razorscale_mole_machineAI(GameObject* go) : GameObjectAI(go) { }

        void Reset() override
        {
            me->SetFlag(GO_FLAG_NOT_SELECTABLE);
            _scheduler.Schedule(Seconds(1), [this](TaskContext /*context*/)
            {
                me->UseDoorOrButton();
            });
            _scheduler.Schedule(Seconds(10), [this](TaskContext /*context*/)
            {
                me->Delete();
            });
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };
    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetUlduarAI<go_razorscale_mole_machineAI>(go);
    }
};

/* 63317 - Flame Breath
   64021 - Flame Breath */
class spell_razorscale_flame_breath : public SpellScript
{
    void CheckDamage()
    {
        Creature* target = GetHitCreature();
        if (!target || target->GetEntry() != NPC_DARK_RUNE_GUARDIAN || !target->IsAlive())
            return;

        if (GetHitDamage() >= int32(target->GetHealth()))
            target->AI()->SetData(DATA_IRON_DWARF_MEDIUM_RARE, 1);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj)
        {
            if (Creature* target = obj->ToCreature())
                if (target->IsTrigger())
                    return true;

            return false;
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_razorscale_flame_breath::CheckDamage);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_razorscale_flame_breath::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENTRY);
    }
};

/* 63968 - Summon Iron Dwarves
   63970 - Summon Iron Dwarves
   63969 - Summon Iron Dwarves */
class spell_razorscale_summon_iron_dwarves : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_IRON_DWARF_GUARDIAN,
            SPELL_SUMMON_IRON_DWARF_WATCHER
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        switch (GetSpellInfo()->Id)
        {
            case SPELL_TRIGGER_SUMMON_IRON_DWARVES:
                caster->CastSpell(caster, SPELL_SUMMON_IRON_DWARF_GUARDIAN, true);
                caster->CastSpell(caster, SPELL_SUMMON_IRON_DWARF_GUARDIAN, true);
                caster->CastSpell(caster, SPELL_SUMMON_IRON_DWARF_WATCHER, true);
                break;
            case SPELL_TRIGGER_SUMMON_IRON_DWARVES_2:
            case SPELL_TRIGGER_SUMMON_IRON_DWARVES_3:
                caster->CastSpell(caster, SPELL_SUMMON_IRON_DWARF_GUARDIAN, true);
                caster->CastSpell(caster, SPELL_SUMMON_IRON_DWARF_WATCHER, true);
                caster->CastSpell(caster, SPELL_SUMMON_IRON_DWARF_WATCHER, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_razorscale_summon_iron_dwarves::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 64821 - Fuse Armor
class spell_razorscale_fuse_armor : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FUSED_ARMOR });
    }

    void HandleFused(AuraEffect const* /*aurEff*/)
    {
        if (GetStackAmount() != GetSpellInfo()->StackAmount)
            return;

        GetTarget()->CastSpell(nullptr, SPELL_FUSED_ARMOR, true);
        Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_razorscale_fuse_armor::HandleFused, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 62669 - Firebolt
class spell_razorscale_firebolt : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return obj->GetEntry() != NPC_RAZORSCALE_HARPOON_FIRE_STATE; });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_razorscale_firebolt::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class achievement_iron_dwarf_medium_rare : public AchievementCriteriaScript
{
    public:
        achievement_iron_dwarf_medium_rare() : AchievementCriteriaScript("achievement_iron_dwarf_medium_rare") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI() && target->GetAI()->GetData(DATA_IRON_DWARF_MEDIUM_RARE);
        }
};

class achievement_quick_shave : public AchievementCriteriaScript
{
    public:
        achievement_quick_shave() : AchievementCriteriaScript("achievement_quick_shave") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target)
                if (Creature* razorscale = target->ToCreature())
                    if (razorscale->AI()->GetData(DATA_QUICK_SHAVE))
                        return true;

            return false;
        }
};

void AddSC_boss_razorscale()
{
    RegisterUlduarCreatureAI(boss_razorscale);
    RegisterUlduarCreatureAI(npc_expedition_defender);
    RegisterUlduarCreatureAI(npc_expedition_trapper);
    RegisterUlduarCreatureAI(npc_expedition_engineer);
    RegisterUlduarCreatureAI(npc_expedition_commander);
    RegisterUlduarCreatureAI(npc_razorscale_spawner);
    RegisterUlduarCreatureAI(npc_darkrune_watcher);
    RegisterUlduarCreatureAI(npc_darkrune_guardian);
    RegisterUlduarCreatureAI(npc_darkrune_sentinel);
    RegisterUlduarCreatureAI(npc_razorscale_harpoon_fire_state);
    RegisterUlduarCreatureAI(npc_razorscale_devouring_flame);
    new go_razorscale_harpoon();
    new go_razorscale_mole_machine();
    RegisterSpellScript(spell_razorscale_flame_breath);
    RegisterSpellScript(spell_razorscale_summon_iron_dwarves);
    RegisterSpellScript(spell_razorscale_fuse_armor);
    RegisterSpellScript(spell_razorscale_firebolt);
    new achievement_iron_dwarf_medium_rare();
    new achievement_quick_shave();
}
