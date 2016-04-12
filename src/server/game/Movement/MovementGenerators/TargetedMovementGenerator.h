/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
        TargetedMovementGeneratorBase(Unit* target) { m_target.link(target, this); }
        void StopFollowing() { }
    protected:
        FollowerReference m_target;
};

template<class T, typename D>
class TargetedMovementGeneratorMedium : public MovementGeneratorMedium< T, D >, public TargetedMovementGeneratorBase
{
    public:
        TargetedMovementGeneratorMedium(Unit* target, float offset, float angle) : TargetedMovementGeneratorBase(target),
            m_path(nullptr), m_recheckDistance(0), m_offset(offset), m_angle(angle), m_recalculateTravel(false), m_targetReached(false) { }

        ~TargetedMovementGeneratorMedium();

        bool DoUpdate(T*, uint32);
        Unit* GetTarget() const { return m_target.getTarget(); }

        void UnitSpeedChanged() override { m_recalculateTravel = true; }
        bool IsReachable() const { return (m_path) ? (m_path->GetPathType() & PATHFIND_NORMAL) : true; }

        virtual void ClearUnitStateMove(T*) { }
        virtual void AddUnitStateMove(T*) { }
    protected:
        void SetTargetLocation(T* owner, bool updateDestination);

        PathGenerator* m_path;
        TimeTrackerSmall m_recheckDistance;
        float m_offset;
        float m_angle;
        bool m_recalculateTravel;
        bool m_targetReached;
};

template<class T>
class ChaseMovementGenerator : public TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >
{
    public:
        ChaseMovementGenerator(Unit* target) : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target) { }
        ChaseMovementGenerator(Unit* target, float offset, float angle) : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target, offset, angle) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return CHASE_MOTION_TYPE; }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        void MovementInform(T*);

        void ClearUnitStateMove(T* owner) override { owner->ClearUnitState(UNIT_STATE_CHASE_MOVE); }
        void AddUnitStateMove(T* owner) override { owner->AddUnitState(UNIT_STATE_CHASE_MOVE); }

        bool EnableWalking() const { return false;}
        bool HasLostTarget(T* u) const { return u->GetVictim() != this->GetTarget(); }
        void HasReachedTarget(T*);
};

template<class T>
class FollowMovementGenerator : public TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >
{
    public:
        FollowMovementGenerator(Unit* target) : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target) { }
        FollowMovementGenerator(Unit* target, float offset, float angle) : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target, offset, angle) { }

        MovementGeneratorType GetMovementGeneratorType() const override { return FOLLOW_MOTION_TYPE; }

        void DoInitialize(T*);
        void DoFinalize(T*);
        void DoReset(T*);
        void MovementInform(T*);

        void ClearUnitStateMove(T* owner) override { owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE); }
        void AddUnitStateMove(T* owner) override { owner->AddUnitState(UNIT_STATE_FOLLOW_MOVE); }

        bool EnableWalking() const;
        bool HasLostTarget(T*) const { return false; }
        void HasReachedTarget(T*) { }
    private:
        void UpdateSpeed(T* owner);
};

#endif
