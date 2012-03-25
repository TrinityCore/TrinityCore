/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_MOTIONMASTER_H
#define TRINITY_MOTIONMASTER_H

#include "Common.h"
#include <vector>
#include "SharedDefines.h"
#include "Object.h"
#include "StateMgr.h"

// Creature Entry ID used for waypoints show, visible only for GMs
#define VISUAL_WAYPOINT 1

enum RotateDirection
{
    ROTATE_DIRECTION_LEFT,
    ROTATE_DIRECTION_RIGHT,
};

// assume it is 25 yard per 0.6 second
#define SPEED_CHARGE    42.0f

class MotionMaster //: private std::stack<MovementGenerator *>
{
    public:
        explicit MotionMaster(Unit* unit) : _owner(unit)
        {
        }
        ~MotionMaster();

        void Initialize();

        void Clear(bool reset = true);
        void MovementExpired(bool reset = true) { Clear(reset); }

        void MoveIdle();
        void MoveTargetedHome();
        void MoveRandom(float spawndist = 0.0f);
        void MoveFollow(Unit* target, float dist, float angle, UnitActionId stateId = UNIT_ACTION_DOWAYPOINTS);
        void MoveChase(Unit* target, float dist = 0.0f, float angle = 0.0f);
        void MoveConfused();
        void MoveFleeing(Unit* enemy, uint32 time = 0);
        void MovePoint(uint32 id, const Position &pos)
            { MovePoint(id, pos.m_positionX, pos.m_positionY, pos.m_positionZ); }
        void MovePoint(uint32 id, float x, float y, float z);

        // These two movement types should only be used with creatures having landing/takeoff animations
        void MoveLand(uint32 id, Position const& pos, float speed);
        void MoveTakeoff(uint32 id, Position const& pos, float speed);

        void MoveCharge(float x, float y, float z, float speed = SPEED_CHARGE, uint32 id = EVENT_CHARGE);
        void MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ);
        void MoveJumpTo(float angle, float speedXY, float speedZ);
        void MoveJump(float x, float y, float z, float speedXY, float speedZ, uint32 id = 0);
        void MoveFall(uint32 id = 0);

        void MoveSeekAssistance(float x, float y, float z);
        void MoveSeekAssistanceDistract(uint32 timer);
        void MoveTaxiFlight(uint32 path, uint32 pathnode);
        void MoveDistract(uint32 time);
        void MovePath(uint32 path_id, bool repeatable);
        void MoveRotate(uint32 time, RotateDirection direction);

        MovementGeneratorType GetCurrentMovementGeneratorType() const;
        MovementGeneratorType GetMotionSlotType(UnitActionPriority priority) const;

        bool GetDestination(float &x, float &y, float &z);

        class UnitStateMgr* impl();
        MovementGenerator*  top();
        Unit* GetOwner() { return _owner; };
        bool  empty();
    private:
        void Mutate(MovementGenerator* mgen, UnitActionId stateId);                  // use Move* functions instead

        Unit* _owner;
};
#endif

