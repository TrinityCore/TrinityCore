/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#ifndef MANGOS_TARGETEDMOVEMENTGENERATOR_H
#define MANGOS_TARGETEDMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "FollowerReference.h"
#include "PathFinder.h"
#include "Unit.h"

class TargetedMovementGeneratorBase
{
    public:
        explicit TargetedMovementGeneratorBase(Unit &target) { i_target.link(&target, this); }
        void stopFollowing() { }
    protected:
        FollowerReference i_target;
};

template<class T, typename D>
class TargetedMovementGeneratorMedium
: public MovementGeneratorMedium< T, D >, public TargetedMovementGeneratorBase
{
    protected:
        TargetedMovementGeneratorMedium(Unit &target, float offset, float angle) :
            TargetedMovementGeneratorBase(target), m_checkDistanceTimer(0), m_fOffset(offset),
            m_fAngle(angle), m_bRecalculateTravel(false), m_bTargetReached(false),
            m_bReachable(true), m_fTargetLastX(0), m_fTargetLastY(0), m_fTargetLastZ(0), m_bTargetOnTransport(false)
        {
        }
        ~TargetedMovementGeneratorMedium() {}

    public:
        
        void UpdateAsync(T&, uint32 diff);

        bool IsReachable() const
        {
            return m_bReachable;
        }

        Unit* GetTarget() const { return i_target.getTarget(); }

        void UnitSpeedChanged() { m_bRecalculateTravel=true; }
        void UpdateFinalDistance(float fDistance);

    protected:
        void _setTargetLocation(T &);

        ShortTimeTracker m_checkDistanceTimer;

        float m_fOffset;
        float m_fAngle;
        bool m_bRecalculateTravel : 1;
        bool m_bTargetReached : 1;
        bool m_bReachable;

        float m_fTargetLastX;
        float m_fTargetLastY;
        float m_fTargetLastZ;
        bool  m_bTargetOnTransport;
};

template<class T>
class ChaseMovementGenerator : public TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >
{
    public:
        explicit ChaseMovementGenerator(Unit &target)
            : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target) {}
        ChaseMovementGenerator(Unit &target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target, offset, angle) {}
        ~ChaseMovementGenerator() {}

        MovementGeneratorType GetMovementGeneratorType() const { return CHASE_MOTION_TYPE; }

        bool Update(T &, uint32 const&);
        void Initialize(T &);
        void Finalize(T &);
        void Interrupt(T &);
        void Reset(T &);
        void MovementInform(T &);

        static void _clearUnitStateMove(T &u) { u.ClearUnitState(UNIT_STAT_CHASE_MOVE); }
        static void _addUnitStateMove(T &u)  { u.AddUnitState(UNIT_STAT_CHASE_MOVE); }
        bool EnableWalking() const { return false;}
        bool _lostTarget(T &u) const { return u.GetVictim() != this->GetTarget(); }
        void _reachTarget(T &);
    private:
        ShortTimeTracker m_spreadTimer{ 0 };
        ShortTimeTracker m_leashExtensionTimer{ 5000 };
        bool m_bIsSpreading = false;
        bool m_bCanSpread = true;
        uint8 m_uiSpreadAttempts = 0;

        void DoBackMovement(T &, Unit* target);
        void DoSpreadIfNeeded(T &, Unit* target);
        bool TargetDeepInBounds(T &, Unit* target) const;
        bool TargetWithinBoundsPercentDistance(T &, Unit* target, float pct) const;

        // Needed to compile with gcc for some reason.
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::i_target;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_fAngle;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_fOffset;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_fTargetLastX;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_fTargetLastY;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_fTargetLastZ;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_checkDistanceTimer;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_bTargetOnTransport;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_bRecalculateTravel;
        using TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >::m_bTargetReached;
};

template<class T>
class FollowMovementGenerator : public TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >
{
    public:
        explicit FollowMovementGenerator(Unit &target)
            : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target){}
        FollowMovementGenerator(Unit &target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target, offset, angle) {}
        ~FollowMovementGenerator() {}

        MovementGeneratorType GetMovementGeneratorType() const { return FOLLOW_MOTION_TYPE; }

        bool Update(T &, uint32 const&);
        void Initialize(T &);
        void Finalize(T &);
        void Interrupt(T &);
        void Reset(T &);
        void MovementInform(T &);

        static void _clearUnitStateMove(T &u) { u.ClearUnitState(UNIT_STAT_FOLLOW_MOVE); }
        static void _addUnitStateMove(T &u)  { u.AddUnitState(UNIT_STAT_FOLLOW_MOVE); }
        bool EnableWalking() const;
        bool _lostTarget(T &) const { return false; }
        void _reachTarget(T &) {}
    private:
        void _updateSpeed(T &u);

        // Needed to compile with gcc for some reason.
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::i_target;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_fAngle;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_fOffset;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_fTargetLastX;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_fTargetLastY;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_fTargetLastZ;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_checkDistanceTimer;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_bTargetOnTransport;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_bRecalculateTravel;
        using TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >::m_bTargetReached;
};

#endif
