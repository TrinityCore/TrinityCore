/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_MOTIONMASTER_H
#define MANGOS_MOTIONMASTER_H

#include "Common.h"
#include <stack>
#include <vector>

class MovementGenerator;
class Unit;

// Creature Entry ID used for waypoints show, visible only for GMs
#define VISUAL_WAYPOINT 1

// values 0 ... MAX_DB_MOTION_TYPE-1 used in DB
enum MovementGeneratorType
{
    IDLE_MOTION_TYPE                = 0,                    // IdleMovementGenerator.h
    RANDOM_MOTION_TYPE              = 1,                    // RandomMovementGenerator.h
    WAYPOINT_MOTION_TYPE            = 2,                    // WaypointMovementGenerator.h
    MAX_DB_MOTION_TYPE              = 3,                    // *** this and below motion types can't be set in DB.

    CONFUSED_MOTION_TYPE            = 4,                    // ConfusedMovementGenerator.h
    CHASE_MOTION_TYPE               = 5,                    // TargetedMovementGenerator.h
    HOME_MOTION_TYPE                = 6,                    // HomeMovementGenerator.h
    FLIGHT_MOTION_TYPE              = 7,                    // WaypointMovementGenerator.h
    POINT_MOTION_TYPE               = 8,                    // PointMovementGenerator.h
    FLEEING_MOTION_TYPE             = 9,                    // FleeingMovementGenerator.h
    DISTRACT_MOTION_TYPE            = 10,                   // IdleMovementGenerator.h
    ASSISTANCE_MOTION_TYPE          = 11,                   // PointMovementGenerator.h (first part of flee for assistance)
    ASSISTANCE_DISTRACT_MOTION_TYPE = 12,                   // IdleMovementGenerator.h (second part of flee for assistance)
    TIMED_FLEEING_MOTION_TYPE       = 13,                   // FleeingMovementGenerator.h (alt.second part of flee for assistance)
    FOLLOW_MOTION_TYPE              = 14,                   // TargetedMovementGenerator.h
    EFFECT_MOTION_TYPE              = 15,
    PATROL_MOTION_TYPE              = 16,
    CHARGE_MOTION_TYPE              = 17,
    DISTANCING_MOTION_TYPE          = 18,
};

enum MMCleanFlag
{
    MMCF_NONE   = 0,
    MMCF_UPDATE = 1,                                        // Clear or Expire called from update
    MMCF_RESET  = 2                                         // Flag if need top()->Reset()
};

enum MoveOptions
{
    MOVE_NONE                = 0x000,
    MOVE_PATHFINDING         = 0x001,
    MOVE_WALK_MODE           = 0x002,
    MOVE_RUN_MODE            = 0x004,
    MOVE_FLY_MODE            = 0x008,
    MOVE_CYCLIC              = 0x010,
    MOVE_FALLING             = 0x020,
    MOVE_FORCE_DESTINATION   = 0x040,
    MOVE_EXCLUDE_STEEP_SLOPES= 0x080,
    MOVE_STRAIGHT_PATH       = 0x100,
};

class MotionMaster : std::stack<MovementGenerator *>
{
        typedef stack<MovementGenerator *> Impl;
        typedef std::vector<MovementGenerator *> ExpireList;

    public:

        explicit MotionMaster(Unit* unit) : m_needsAsyncUpdate(false), m_owner(unit), m_expList(nullptr), m_cleanFlag(MMCF_NONE) {}
        ~MotionMaster();

        void Initialize();
        void InitializeNewDefault(bool alwaysReplace);

        MovementGenerator const* GetCurrent() const { return top(); }
        //MovementGenerator* top() { return std::stack<MovementGenerator *>::top(); }

        using Impl::top;
        using Impl::empty;

        typedef container_type::const_iterator const_iterator;
        const_iterator begin() const { return c.begin(); }
        const_iterator end() const { return c.end(); }
        typedef container_type::iterator iterator;
        iterator begin() { return c.begin(); }
        iterator end() { return c.end(); }
        void erase(iterator it) { c.erase(it); }

        void UpdateMotion(uint32 diff);
        void UpdateMotionAsync(uint32 diff);
        void Clear(bool reset = true, bool all = false)
        {
            if (m_cleanFlag & MMCF_UPDATE)
                DelayedClean(reset, all);
            else
                DirectClean(reset, all);
        }
        void MovementExpired(bool reset = true)
        {
            if (m_cleanFlag & MMCF_UPDATE)
                DelayedExpire(reset);
            else
                DirectExpire(reset);
        }
        void ClearType(MovementGeneratorType moveType);

        void MoveIdle();
        void MoveRandom(bool use_current_position = false, float wander_distance = 0.0f, uint32 expire_time = 0);
        void MoveTargetedHome();
        void MoveFollow(Unit* target, float dist, float angle);
        void MoveChase(Unit* target, float dist = 0.0f, float angle = 0.0f);
        void MoveConfused();
        void MoveFleeing(Unit* enemy, uint32 time = 0);
        void MoveFeared(Unit* enemy, uint32 time = 0);
        void MovePoint(uint32 id, float x, float y, float z, uint32 options = MOVE_NONE, float speed = 0.0f, float finalOrientation = -10);
        void MoveSeekAssistance(float x,float y,float z);
        void MoveSeekAssistanceDistract(uint32 timer);
        void MoveWaypoint(uint32 startPoint = 0, uint32 source = 0, uint32 initialDelay = 0, uint32 overwriteGuid = 0, uint32 overwriteEntry = 0, bool repeat = true);
        void MoveWaypointAsDefault(uint32 startPoint = 0, uint32 source = 0, uint32 initialDelay = 0, uint32 overwriteGuid = 0, uint32 overwriteEntry = 0, bool repeat = true);
        void MoveTaxiFlight(uint32 path, uint32 pathnode);
        void MoveTaxiFlight();
        void MoveDistract(uint32 timeLimit);
        void MoveJump(float x, float y, float z, float horizontalSpeed, float max_height, uint32 id = 0);
        void MoveCharge(Unit* target, uint32 delay = 0, bool triggerAutoAttack = false);
        bool MoveDistance(Unit* target, float distance);
        void ReInitializePatrolMovement();

        MovementGeneratorType GetCurrentMovementGeneratorType() const;
        static char const* GetMovementGeneratorTypeName(MovementGeneratorType generator);
        void GetUsedMovementGeneratorsList(std::vector<MovementGeneratorType>& list) const;

        void PropagateSpeedChange();
        bool SetNextWaypoint(uint32 pointId);

        uint32 getLastReachedWaypoint() const;
        void GetWaypointPathInformation(std::ostringstream& oss) const;
        bool GetDestination(float& x, float& y, float& z);

        // will only work in MMgens where we have a target (TARGETED_MOTION_TYPE)
        void UpdateFinalDistanceToTarget(float fDistance);

        bool NeedsAsyncUpdate() const { return m_needsAsyncUpdate; }
        void SetNeedAsyncUpdate() { m_needsAsyncUpdate = true; }
    private:
        void Mutate(MovementGenerator* m);                  // use Move* functions instead

        void DirectClean(bool reset, bool all);
        void DelayedClean(bool reset, bool all);

        void DirectExpire(bool reset);
        void DelayedExpire(bool reset);

        bool        m_needsAsyncUpdate;
        Unit       *m_owner;
        ExpireList *m_expList;
        uint8       m_cleanFlag;
};
#endif
