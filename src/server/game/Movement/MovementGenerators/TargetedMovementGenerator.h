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

#ifndef TRINITY_TARGETEDMOVEMENTGENERATOR_H
#define TRINITY_TARGETEDMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "FollowerReference.h"
#include "Timer.h"
#include "Unit.h"
#include "PathGenerator.h"

class TargetedMovementGeneratorBase
{
    public:
        TargetedMovementGeneratorBase(Unit* target) { i_target.link(target, this); }
        void stopFollowing() { }
    protected:
        FollowerReference i_target;
};

template<class T, typename D>
class TargetedMovementGeneratorMedium : public MovementGeneratorMedium< T, D >, public TargetedMovementGeneratorBase
{
    protected:
        TargetedMovementGeneratorMedium(Unit* target, float offset, float angle) :
            TargetedMovementGeneratorBase(target), i_path(NULL),
            i_recheckDistance(0), i_offset(offset), i_angle(angle),
            i_recalculateTravel(false), i_targetReached(false)
        {
        }
        ~TargetedMovementGeneratorMedium() { delete i_path; }

    public:
        bool DoUpdate(T*, uint32);
        Unit* GetTarget() const { return i_target.getTarget(); }

        void unitSpeedChanged() override { i_recalculateTravel = true; }
        bool IsReachable() const { return (i_path) ? (i_path->GetPathType() & PATHFIND_NORMAL) : true; }
    protected:
        void _setTargetLocation(T* owner, bool updateDestination);

        PathGenerator* i_path;
        TimeTrackerSmall i_recheckDistance;
        float i_offset;
        float i_angle;
        bool i_recalculateTravel : 1;
        bool i_targetReached : 1;
};

template<class T>
class ChaseMovementGenerator : public TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >
{
    public:
        ChaseMovementGenerator(Unit* target)
            : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target) { }
        ChaseMovementGenerator(Unit* target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target, offset, angle) { }
        ~ChaseMovementGenerator() { }

        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        void MovementInform(T*);

        static void _clearUnitStateMove(T* u) { u->ClearUnitState(UNIT_STATE_CHASE_MOVE); }
        static void _addUnitStateMove(T* u)  { u->AddUnitState(UNIT_STATE_CHASE_MOVE); }
        bool EnableWalking() const { return false;}
        bool _lostTarget(T* u) const { return u->GetVictim() != this->GetTarget(); }
        void _reachTarget(T*);
};

template<class T>
class FollowMovementGenerator : public TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >
{
    public:
        FollowMovementGenerator(Unit* target)
            : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target){ }
        FollowMovementGenerator(Unit* target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target, offset, angle) { }
        ~FollowMovementGenerator() { }

        MovementGeneratorType GetMovementGeneratorType() const override { return FOLLOW_MOTION_TYPE; }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        void MovementInform(T*);

        static void _clearUnitStateMove(T* u) { u->ClearUnitState(UNIT_STATE_FOLLOW_MOVE); }
        static void _addUnitStateMove(T* u)  { u->AddUnitState(UNIT_STATE_FOLLOW_MOVE); }
        bool EnableWalking() const;
        bool _lostTarget(T*) const { return false; }
        void _reachTarget(T*) { }
    private:
        void _updateSpeed(T* owner);
};

#endif
