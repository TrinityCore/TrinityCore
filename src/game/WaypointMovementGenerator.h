/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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
#include "DestinationHolder.h"
#include "WaypointManager.h"
#include "Path.h"
#include "Traveller.h"

#include "Player.h"

#include <vector>
#include <set>

#define FLIGHT_TRAVEL_UPDATE  100
#define STOP_TIME_FOR_PLAYER  3 * 60 * 1000                         // 3 Minutes

template<class T, class P = Path>
class MANGOS_DLL_SPEC PathMovementBase
{
    public:
        PathMovementBase() : i_currentNode(0) {}
        virtual ~PathMovementBase() {};

        inline bool MovementInProgress(void) const { return i_currentNode < i_path.Size(); }

        // template pattern, not defined .. override required
        void LoadPath(T &);
        void ReloadPath(T &);
        uint32 GetCurrentNode() const { return i_currentNode; }

        bool GetDestination(float& x, float& y, float& z) const { i_destinationHolder.GetDestination(x,y,z); return true; }
    protected:
        uint32 i_currentNode;
        DestinationHolder< Traveller<T> > i_destinationHolder;
        P i_path;
};

/** WaypointMovementGenerator loads a series of way points
 * from the DB and apply it to the creature's movement generator.
 * Hence, the creature will move according to its predefined way points.
 */

template<class T>
class MANGOS_DLL_SPEC WaypointMovementGenerator;

template<>
class MANGOS_DLL_SPEC WaypointMovementGenerator<Creature>
: public MovementGeneratorMedium< Creature, WaypointMovementGenerator<Creature> >,
public PathMovementBase<Creature, WaypointPath*>
{
    TimeTrackerSmall i_nextMoveTime;
    std::vector<bool> i_hasDone;
    public:
        WaypointMovementGenerator(Creature &) : i_nextMoveTime(0) {}
        ~WaypointMovementGenerator() { ClearWaypoints(); }
        void Initialize(Creature &u)
        {
            i_nextMoveTime.Reset(0);                        // TODO: check the lower bound (0 is probably too small)
            u.StopMoving();
            LoadPath(u);
        }
        void Finalize(Creature &) {}
        void Reset(Creature &u) { ReloadPath(u); }
        bool Update(Creature &u, const uint32 &diff);

        void MovementInform(Creature &);

        MovementGeneratorType GetMovementGeneratorType() { return WAYPOINT_MOTION_TYPE; }

        // now path movement implmementation
        void LoadPath(Creature &c);
        void ReloadPath(Creature &c) { ClearWaypoints(); LoadPath(c); }

        // Player stoping creature
        bool IsStopedByPlayer() { return b_StopedByPlayer; }
        void SetStopedByPlayer(bool val) { b_StopedByPlayer = val; }

        // statics
        static void Initialize(void);
    private:
        void ClearWaypoints();
        bool b_StopedByPlayer;
};

/** FlightPathMovementGenerator generates movement of the player for the paths
 * and hence generates ground and activities for the player.
 */
class MANGOS_DLL_SPEC FlightPathMovementGenerator
: public MovementGeneratorMedium< Player, FlightPathMovementGenerator >,
public PathMovementBase<Player>
{
    uint32 i_pathId;
    std::vector<uint32> i_mapIds;
    public:
        explicit FlightPathMovementGenerator(uint32 id, uint32 startNode = 0) : i_pathId(id) { i_currentNode = startNode; }
        void Initialize(Player &);
        void Finalize(Player &);
        void Reset(Player &) {}
        bool Update(Player &, const uint32 &);
        MovementGeneratorType GetMovementGeneratorType() { return FLIGHT_MOTION_TYPE; }

        void LoadPath(Player &);
        void ReloadPath(Player &) { /* don't reload flight path */ }

        Path& GetPath() { return i_path; }
        uint32 GetPathAtMapEnd() const;
        inline bool HasArrived() const { return (i_currentNode >= i_path.Size()); }
        void SetCurrentNodeAfterTeleport();
        void SkipCurrentNode() { ++i_currentNode; }
};
#endif
