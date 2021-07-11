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

#ifndef MANGOS_WAYPOINTMOVEMENTGENERATOR_H
#define MANGOS_WAYPOINTMOVEMENTGENERATOR_H

/** @page PathMovementGenerator is used to generate movements
 * of waypoints and flight paths.  Each serves the purpose
 * of generate activities so that it generates updated
 * packets for the players.
 */

#include "MovementGenerator.h"
#include "WaypointManager.h"

class Creature;
class Unit;
struct WaypointPath;
#include "Player.h"

#include <vector>
#include <set>

#define FLIGHT_TRAVEL_UPDATE  100
#define STOP_TIME_FOR_PLAYER  (30 * IN_MILLISECONDS)

struct CreatureGroupMember;

template<class T, class P>
class PathMovementBase
{
    public:
        PathMovementBase() : i_currentNode(0) {}
        virtual ~PathMovementBase() {};

        bool MovementInProgress(void) const { return (i_currentNode+1) < i_path->size(); }

        // template pattern, not defined .. override required
        void LoadPath(T &);
        uint32 GetCurrentNode() const { return i_currentNode; }

    protected:
        P i_path;
        uint32 i_currentNode;
};

/** WaypointMovementGenerator loads a series of way points
 * from the DB and apply it to the creature's movement generator.
 * Hence, the creature will move according to its predefined way points.
 */

template<class T>
class WaypointMovementGenerator;

template<>
class WaypointMovementGenerator<Creature>
: public MovementGeneratorMedium< Creature, WaypointMovementGenerator<Creature> >,
  public PathMovementBase<Creature, WaypointPath const*>
{
    public:
        explicit WaypointMovementGenerator(uint32 pathId = 0, bool repeating = true);
        explicit WaypointMovementGenerator(WaypointPath& path, bool repeating = true);
        ~WaypointMovementGenerator() { _path = nullptr; }
        WaypointMovementGenerator(Creature &, bool repeating = true) : i_nextMoveTime(0), m_isArrivalDone(false), m_repeating(repeating), m_isWandering(false), m_lastReachedWaypoint(0) {}
        ~WaypointMovementGenerator() { i_path = nullptr; }
        void Initialize(Creature &u);
        void Interrupt(Creature &);
        void Finalize(Creature &);
        void Reset(Creature &u);
        bool Update(Creature &u, uint32 const& diff);
        void InitializeWaypointPath(Creature& creature, uint32 startPoint, WaypointPathOrigin wpSource, uint32 initialDelay, uint32 overwriteGuid, uint32 overwriteEntry, bool repeat);

        MovementGeneratorType GetMovementGeneratorType() const { return WAYPOINT_MOTION_TYPE; }

        // now path movement implementation
        bool GetResetPosition(Creature&, float& x, float& y, float& z);
        uint32 getLastReachedWaypoint() const { return m_lastReachedWaypoint; }
        void GetPathInformation(WaypointPathOrigin& wpOrigin) const { wpOrigin = m_PathOrigin; }
        void GetPathInformation(std::ostringstream& oss) const;
        bool SetNextWaypoint(uint32 pointId);

        void AddPauseTime(int32 waitTimeDiff)
        {
            if (i_nextMoveTime.GetExpiry() < waitTimeDiff)
                i_nextMoveTime.Reset(waitTimeDiff);
        }
        
    protected:
        void LoadPath(uint32 guid, uint32 entry, WaypointPathOrigin wpOrigin);
        void Stop(int32 time) { i_nextMoveTime.Reset(time);}

        bool Stopped() { return !i_nextMoveTime.Passed();}

        MovementGeneratorType GetMovementGeneratorType() const override;
        bool CanMove(int32 diff)
        {
            i_nextMoveTime.Update(diff);
            return i_nextMoveTime.Passed();
        }

        void UnitSpeedChanged() override { AddFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING); }
        void Pause(uint32 timer = 0) override;
        void Resume(uint32 overrideTimer = 0) override;
        bool GetResetPosition(Unit*, float& x, float& y, float& z) override;
        bool OnArrived(Creature&);
        void StartMove(Creature&);

        void StartMoveNow(Creature& creature)
        {
            i_nextMoveTime.Reset(0);
            StartMove(creature);
        }

        void DoInitialize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, uint32);
        void DoDeactivate(Creature*);
        void DoFinalize(Creature*, bool, bool);
        ShortTimeTracker i_nextMoveTime;
        bool m_isArrivalDone;
        bool m_repeating;
        bool m_isWandering;
        uint32 m_lastReachedWaypoint;

        std::string GetDebugInfo() const override;
        WaypointPathOrigin m_PathOrigin;
};

    private:
        void MovementInform(Creature*);
        void OnArrived(Creature*);
        void StartMove(Creature*, bool relaunch = false);
        bool ComputeNextNode();
        bool UpdateTimer(uint32 diff)
        {
            _nextMoveTime.Update(diff);
            if (_nextMoveTime.Passed())
            {
                _nextMoveTime.Reset(0);
                return true;
            }
            return false;
/** FlightPathMovementGenerator generates movement of the player for the paths
 * and hence generates ground and activities for the player.
 */
class FlightPathMovementGenerator
: public MovementGeneratorMedium< Player, FlightPathMovementGenerator >,
  public PathMovementBase<Player,TaxiPathNodeList const*>
{
    public:
        explicit FlightPathMovementGenerator(TaxiPathNodeList const& pathnodes, uint32 startNode = 0)
        {
            i_path = &pathnodes;
            i_currentNode = startNode;
        }
        void Initialize(Player &);
        void Finalize(Player &);
        void Interrupt(Player &);
        void Reset(Player &, float modSpeed = 1.0f);
        bool Update(Player &, uint32 const&);
        MovementGeneratorType GetMovementGeneratorType() const { return FLIGHT_MOTION_TYPE; }

        TaxiPathNodeList const& GetPath() { return *i_path; }
        uint32 GetPathAtMapEnd() const;
        bool HasArrived() const { return (i_currentNode >= i_path->size()); }
        void SetCurrentNodeAfterTeleport();
        void SkipCurrentNode() { ++i_currentNode; }
        void DoEventIfAny(Player& player, TaxiPathNodeEntry const& node, bool departure);
        bool GetResetPosition(Player&, float& x, float& y, float& z);
};

class PatrolMovementGenerator
: public MovementGeneratorMedium<Creature, PatrolMovementGenerator >
{
    public:
        explicit PatrolMovementGenerator(Creature& c) { ASSERT(InitPatrol(c)); }
        explicit PatrolMovementGenerator(ObjectGuid leader, CreatureGroupMember const* member) : _leaderGuid(leader), _groupMember(member) {}
        bool InitPatrol(Creature& c);

        void LoadPath(Creature &c);
        void Initialize(Creature &);
        void Finalize(Creature &);
        void Interrupt(Creature &);
        void Reset(Creature &);
        bool Update(Creature &, uint32 const&);
        void StartMove(Creature&);
        MovementGeneratorType GetMovementGeneratorType() const { return PATROL_MOTION_TYPE; }

        TimeTracker _nextMoveTime;
        uint32 _pathId;
        bool _repeating;
        bool _loadedFromDB;
        bool GetResetPosition(Creature&, float& x, float& y, float& z);
    private:
        ObjectGuid _leaderGuid;
        CreatureGroupMember const* _groupMember;
};

#endif
