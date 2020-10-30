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

#ifndef MOTIONMASTER_H
#define MOTIONMASTER_H

#include "Common.h"
#include "Errors.h"
#include "ObjectDefines.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include "SharedDefines.h"
#include <vector>

class MovementGenerator;
class Unit;
class PathGenerator;
struct SplineChainLink;
struct SplineChainResumeInfo;
struct WaypointPath;

namespace Movement
{
    class MoveSplineInit;
}

// Creature Entry ID used for waypoints show, visible only for GMs
#define VISUAL_WAYPOINT 1
// assume it is 25 yard per 0.6 second
#define SPEED_CHARGE    42.0f

enum MovementGeneratorType : uint8
{
    IDLE_MOTION_TYPE                = 0,                  // IdleMovementGenerator.h
    RANDOM_MOTION_TYPE              = 1,                  // RandomMovementGenerator.h
    WAYPOINT_MOTION_TYPE            = 2,                  // WaypointMovementGenerator.h
    CYCLIC_SPLINE_MOTION_TYPE       = 3,                  // CyclicMovementGenerator.h
    MAX_DB_MOTION_TYPE              = 4,                  // Below motion types can't be set in DB.
    CONFUSED_MOTION_TYPE            = 4,                  // ConfusedMovementGenerator.h
    CHASE_MOTION_TYPE               = 5,                  // TargetedMovementGenerator.h
    HOME_MOTION_TYPE                = 6,                  // HomeMovementGenerator.h
    FLIGHT_MOTION_TYPE              = 7,                  // WaypointMovementGenerator.h
    POINT_MOTION_TYPE               = 8,                  // PointMovementGenerator.h
    FLEEING_MOTION_TYPE             = 9,                  // FleeingMovementGenerator.h
    DISTRACT_MOTION_TYPE            = 10,                 // IdleMovementGenerator.h
    ASSISTANCE_MOTION_TYPE          = 11,                 // PointMovementGenerator.h
    ASSISTANCE_DISTRACT_MOTION_TYPE = 12,                 // IdleMovementGenerator.h
    TIMED_FLEEING_MOTION_TYPE       = 13,                 // FleeingMovementGenerator.h
    FOLLOW_MOTION_TYPE              = 14,                 // FollowMovementGenerator.h
    ROTATE_MOTION_TYPE              = 15,
    EFFECT_MOTION_TYPE              = 16,
    SPLINE_CHAIN_MOTION_TYPE        = 17,                 // SplineChainMovementGenerator.h
    FORMATION_MOTION_TYPE           = 18,                 // FormationMovementGenerator.h
    MAX_MOTION_TYPE                                       // limit
};

enum MovementSlot : uint8
{
    MOTION_SLOT_IDLE = 0,
    MOTION_SLOT_ACTIVE,
    MOTION_SLOT_CONTROLLED,
    MAX_MOTION_SLOT
};

enum MMCleanFlag
{
    MMCF_NONE   = 0,
    MMCF_UPDATE = 1, // Clear or Expire called from update
    MMCF_RESET  = 2  // Flag if need top()->Reset()
};

enum RotateDirection
{
    ROTATE_DIRECTION_LEFT,
    ROTATE_DIRECTION_RIGHT
};

struct ChaseAngle
{
    ChaseAngle(float angle, float tol = M_PI_4) : RelativeAngle(Position::NormalizeOrientation(angle)), Tolerance(tol) {}

    float RelativeAngle; // we want to be at this angle relative to the target (0 = front, M_PI = back)
    float Tolerance;     // but we'll tolerate anything within +- this much

    float UpperBound() const { return Position::NormalizeOrientation(RelativeAngle + Tolerance); }
    float LowerBound() const { return Position::NormalizeOrientation(RelativeAngle - Tolerance); }
    bool IsAngleOkay(float relAngle) const
    {
        float const diff = std::abs(relAngle - RelativeAngle);
        return (std::min(diff, float(2 * M_PI) - diff) <= Tolerance);
    }
};

inline bool IsInvalidMovementGeneratorType(uint8 const type) { return type == MAX_DB_MOTION_TYPE || type >= MAX_MOTION_TYPE; }
inline bool IsInvalidMovementSlot(uint8 const slot) { return slot >= MAX_MOTION_SLOT; }

class TC_GAME_API MotionMaster
{
    public:
        explicit MotionMaster(Unit* unit) : _owner(unit), _top(-1), _cleanFlag(MMCF_NONE)
        {
            for (uint8 i = 0; i < MAX_MOTION_SLOT; ++i)
            {
                _slot[i] = nullptr;
                _initialize[i] = true;
            }
        }
        ~MotionMaster();

        bool empty() const { return (_top < 0); }
        int size() const { return _top + 1; }
        MovementGenerator* topOrNull() const { return empty() ? nullptr : top(); }
        MovementGenerator* top() const { ASSERT(!empty()); return _slot[_top]; }

        void Initialize();
        void InitDefault();

        void UpdateMotion(uint32 diff);

        void Clear(bool reset = true);
        void Clear(MovementSlot slot);
        void MovementExpired(bool reset = true);

        MovementSlot GetCurrentSlot() const;
        MovementGeneratorType GetCurrentMovementGeneratorType() const;
        MovementGeneratorType GetMotionSlotType(MovementSlot slot) const;
        MovementGenerator* GetMotionSlot(MovementSlot slot) const;

        void PropagateSpeedChange();

        bool GetDestination(float &x, float &y, float &z);

        void MoveIdle();
        void MoveTargetedHome();
        void MoveRandom(float spawndist = 0.0f);
        void MoveFollow(Unit* target, float dist, float angle, bool joinFormation = false, bool catchUpToTarget = false, bool faceTarget = false, MovementSlot slot = MOTION_SLOT_IDLE);

        void MoveChase(Unit* target, float dist = 0.f, Optional<ChaseAngle> angle = {});
        void MoveChase(Unit* target, float dist, float angle) { MoveChase(target, dist, ChaseAngle(angle)); }

        void MoveConfused();
        void MoveFleeing(Unit* enemy, uint32 time = 0);
        void MovePoint(uint32 id, Position const& pos, bool generatePath = true, float speed = 0.f)
        {
            MovePoint(id, pos.m_positionX, pos.m_positionY, pos.m_positionZ, generatePath, speed);
        }

        void MovePoint(uint32 id, float x, float y, float z, bool generatePath = true, float speed = 0.f);

        /*  Makes the unit move toward the target until it is at a certain distance from it. The unit then stops.
            Only works in 2D.
            This method doesn't account for any movement done by the target. in other words, it only works if the target is stationary.
        */
        void MoveCloserAndStop(uint32 id, Unit* target, float distance);

        // These two movement types should only be used with creatures having landing/takeoff animations
        void MoveLand(uint32 id, Position const& pos, Optional<float> velocity = { });
        void MoveTakeoff(uint32 id, Position const& pos, Optional<float> velocity = { });

        void MoveCharge(float x, float y, float z, float speed = SPEED_CHARGE, uint32 id = EVENT_CHARGE, bool generatePath = false);
        void MoveCharge(PathGenerator const& path, float speed = SPEED_CHARGE);
        void MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ);
        void MoveJumpTo(float angle, float speedXY, float speedZ);
        void MoveJump(Position const& pos, float speedXY, float speedZ, uint32 id = EVENT_JUMP, bool hasOrientation = false)
        {
            MoveJump(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), speedXY, speedZ, id, hasOrientation);
        }
        void MoveJump(float x, float y, float z, float o, float speedXY, float speedZ, uint32 id = EVENT_JUMP, bool hasOrientation = false);
        void MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount, float velocity = 0.f);
        void MoveCyclicPath(Position const* pathPoints, size_t pathSize, bool walk = false, bool fly = false, float velocity = 0.f);
        void MoveCyclicPath(uint32 pathId);
        void MoveSmoothPath(uint32 pointId, Position const* pathPoints, size_t pathSize, bool walk = false, bool fly = false, float velocity = 0.f);
        // Walk along spline chain stored in DB (script_spline_chain_meta and script_spline_chain_waypoints)
        void MoveAlongSplineChain(uint32 pointId, uint16 dbChainId, bool walk);
        void MoveAlongSplineChain(uint32 pointId, std::vector<SplineChainLink> const& chain, bool walk);
        void ResumeSplineChain(SplineChainResumeInfo const& info);
        void MoveFall(uint32 id = 0);

        void MoveSeekAssistance(float x, float y, float z);
        void MoveSeekAssistanceDistract(uint32 timer);
        void MoveTaxiFlight(uint32 path, uint32 pathnode);
        void MoveDistract(uint32 time);
        void MovePath(uint32 pathId, bool repeatable);
        void MovePath(WaypointPath& path, bool repeatable);
        void MoveRotate(uint32 time, RotateDirection direction);

        void MoveFormation(Unit* leader, float range, float angle, int32 point1, int32 point2);

        void LaunchMoveSpline(Movement::MoveSplineInit&& init, uint32 id = 0, MovementSlot slot = MOTION_SLOT_ACTIVE, MovementGeneratorType type = EFFECT_MOTION_TYPE);
    private:
        typedef std::vector<MovementGenerator*> MovementList;

        void pop();

        bool NeedInitTop() const;
        void InitTop();

        void Mutate(MovementGenerator* m, MovementSlot slot);

        void DirectClean(bool reset);
        void DelayedClean();
        void DirectClean(MovementSlot slot);
        void DelayedClean(MovementSlot slot);
        void DirectExpire(bool reset);
        void DelayedExpire();
        void DirectDelete(MovementGenerator* curr);
        void DelayedDelete(MovementGenerator* curr);
        void ClearExpireList();

        MovementGenerator* _slot[MAX_MOTION_SLOT];
        bool _initialize[MAX_MOTION_SLOT];
        MovementList _expireList;
        Unit* _owner;
        int _top;
        uint8 _cleanFlag;
};

#endif // MOTIONMASTER_H
