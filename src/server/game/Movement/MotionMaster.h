/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "Optional.h"
#include "MovementDefines.h"
#include "SharedDefines.h"
#include <vector>

class MovementGenerator;
class Unit;
class PathGenerator;
struct Position;
struct SplineChainLink;
struct SplineChainResumeInfo;
struct WaypointPath;

class TC_GAME_API MotionMaster
{
    public:
        explicit MotionMaster(Unit* unit) : _owner(unit), _top(-1), _cleanFlag(MOTIONMMASTER_CLEANFLAG_NONE)
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
        MovementGenerator* top() const;

        void Initialize();
        void InitDefault();

        void UpdateMotion(uint32 diff);

        void Clear(bool reset = true);
        void Clear(MovementSlot slot);
        void MovementExpired(bool reset = true);

        MovementGeneratorType GetCurrentMovementGeneratorType() const;
        MovementGeneratorType GetMotionSlotType(MovementSlot slot) const;
        MovementGenerator* GetMotionSlot(MovementSlot slot) const;

        void PropagateSpeedChange();

        bool GetDestination(float &x, float &y, float &z);

        void MoveIdle();
        void MoveTargetedHome();
        void MoveRandom(float spawndist = 0.0f);
        void MoveFollow(Unit* target, float dist, ChaseAngle angle, MovementSlot slot = MOTION_SLOT_ACTIVE);
        void MoveChase(Unit* target, Optional<ChaseRange> dist = {}, Optional<ChaseAngle> angle = {});
        void MoveChase(Unit* target, float dist, float angle = 0.0f) { MoveChase(target, Optional<ChaseRange>(dist), Optional<ChaseAngle>(angle)); }
        void MoveConfused();
        void MoveFleeing(Unit* enemy, uint32 time = 0);
        void MovePoint(uint32 id, Position const& pos, bool generatePath = true, Optional<float> finalOrient = {});
        void MovePoint(uint32 id, float x, float y, float z, bool generatePath = true, Optional<float> finalOrient = {});

        /*  Makes the unit move toward the target until it is at a certain distance from it. The unit then stops.
            Only works in 2D.
            This method doesn't account for any movement done by the target. in other words, it only works if the target is stationary.
        */
        void MoveCloserAndStop(uint32 id, Unit* target, float distance);

        // These two movement types should only be used with creatures having landing/takeoff animations
        void MoveLand(uint32 id, Position const& pos);
        void MoveTakeoff(uint32 id, Position const& pos);

        void MoveCharge(float x, float y, float z, float speed = SPEED_CHARGE, uint32 id = EVENT_CHARGE, bool generatePath = false);
        void MoveCharge(PathGenerator const& path, float speed = SPEED_CHARGE);
        void MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ);
        void MoveJumpTo(float angle, float speedXY, float speedZ);
        void MoveJump(Position const& pos, float speedXY, float speedZ, uint32 id = EVENT_JUMP, bool hasOrientation = false);
        void MoveJump(float x, float y, float z, float o, float speedXY, float speedZ, uint32 id = EVENT_JUMP, bool hasOrientation = false);
        void MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount);
        void MoveSmoothPath(uint32 pointId, Position const* pathPoints, size_t pathSize, bool walk);
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

        void MoveFormation(uint32 id, Position destination, uint32 moveType, bool forceRun = false, bool forceOrientation = false);

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
