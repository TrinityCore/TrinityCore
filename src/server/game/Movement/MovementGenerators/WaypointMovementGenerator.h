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

#ifndef TRINITY_WAYPOINTMOVEMENTGENERATOR_H
#define TRINITY_WAYPOINTMOVEMENTGENERATOR_H

/**
 * @page PathMovementGenerator is used to generate movements
 * of waypoints and flight paths.  Each serves the purpose
 * of generate activities so that it generates updated
 * packets for the players.
 */

#include "MovementGenerator.h"
#include "Timer.h"

class Creature;
class Player;
struct TaxiPathNodeEntry;
struct WaypointPath;

template<class Entity, class BasePath>
class PathMovementBase
{
    public:
        PathMovementBase() : _path(), _currentNode(0) { }
        virtual ~PathMovementBase() { };

        uint32 GetCurrentNode() const { return _currentNode; }

    protected:
        BasePath _path;
        uint32 _currentNode;
};

template<class T>
class WaypointMovementGenerator;

template<>
class WaypointMovementGenerator<Creature> : public MovementGeneratorMedium<Creature, WaypointMovementGenerator<Creature>>, public PathMovementBase<Creature, WaypointPath const*>
{
    public:
        explicit WaypointMovementGenerator(uint32 pathId = 0, bool repeating = true);
        explicit WaypointMovementGenerator(WaypointPath& path, bool repeating = true);

        ~WaypointMovementGenerator();

        void DoInitialize(Creature*);
        void DoFinalize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, uint32 diff);

        MovementGeneratorType GetMovementGeneratorType() const override { return WAYPOINT_MOTION_TYPE; }
        void UnitSpeedChanged() override { _recalculateSpeed = true; }
        void Pause(uint32 timer = 0) override;
        void Resume(uint32 overrideTimer = 0) override;

        void MovementInform(Creature*);

        bool GetResetPos(Creature*, float& x, float& y, float& z);

    private:
        void LoadPath(Creature*);
        void OnArrived(Creature*);
        bool StartMove(Creature*);
        bool CanMove(Creature*);
        bool StartMoveNow(Creature* creature)
        {
            _nextMoveTime.Reset(0);
            return StartMove(creature);
        }

        TimeTrackerSmall _nextMoveTime;
        bool _recalculateSpeed;
        bool _isArrivalDone;
        uint32 _pathId;
        bool _repeating;
        bool _loadedFromDB;
        bool _stalled;
        bool _done;
};

/**
 * FlightPathMovementGenerator generates movement of the player for the paths
 * and hence generates ground and activities for the player.
 */
class FlightPathMovementGenerator : public MovementGeneratorMedium<Player, FlightPathMovementGenerator>, public PathMovementBase<Player, std::vector<TaxiPathNodeEntry const*>>
{
    public:
        explicit FlightPathMovementGenerator();

        void LoadPath(Player* player, uint32 startNode = 0);
        void DoInitialize(Player*);
        void DoReset(Player*);
        void DoFinalize(Player*);
        bool DoUpdate(Player*, uint32);
        MovementGeneratorType GetMovementGeneratorType() const override { return FLIGHT_MOTION_TYPE; }

        std::vector<TaxiPathNodeEntry const*> const& GetPath() { return _path; }
        uint32 GetPathAtMapEnd() const;
        bool HasArrived() const { return (_currentNode >= _path.size()); }
        void SetCurrentNodeAfterTeleport();
        void SkipCurrentNode() { ++_currentNode; }
        void DoEventIfAny(Player* player, TaxiPathNodeEntry const* node, bool departure);

        bool GetResetPos(Player*, float& x, float& y, float& z);
        void InitEndGridInfo();
        void PreloadEndGrid();

    private:

        float _endGridX;                            //! X coord of last node location
        float _endGridY;                            //! Y coord of last node location
        uint32 _endMapId;                           //! map Id of last node location
        uint32 _preloadTargetNode;                  //! node index where preloading starts

        struct TaxiNodeChangeInfo
        {
            uint32 PathIndex;
            int64 Cost;
        };

        std::deque<TaxiNodeChangeInfo> _pointsForPathSwitch;    //! node indexes and costs where TaxiPath changes
};

#endif
