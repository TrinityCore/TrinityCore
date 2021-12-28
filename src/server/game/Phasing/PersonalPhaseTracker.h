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

#ifndef PersonalPhaseTracker_h__
#define PersonalPhaseTracker_h__

#include "Common.h"
#include "Duration.h"
#include "GridDefines.h"
#include "ObjectGuid.h"
#include "Optional.h"

class Map;
class PhaseShift;
class WorldObject;
struct Cell;

struct PersonalPhaseSpawns
{
    static constexpr Milliseconds DELETE_TIME_DEFAULT = 1min;

    std::unordered_set<WorldObject*> Objects;
    std::unordered_set<uint16> Grids;
    Optional<Milliseconds> DurationRemaining;

    bool IsEmpty() const { return Objects.empty() && Grids.empty(); }
};

/* Tracks personal phases for a single owner */
struct PlayerPersonalPhasesTracker
{
public:
    void RegisterTrackedObject(uint32 phaseId, WorldObject* object);
    void UnregisterTrackedObject(WorldObject* object);

    void OnOwnerPhasesChanged(WorldObject const* owner);
    void MarkAllPhasesForDeletion();

    void Update(Map* map, uint32 diff);

    bool IsGridLoadedForPhase(uint32 gridId, uint32 phaseId) const;
    void SetGridLoadedForPhase(uint32 gridId, uint32 phaseId);
    void SetGridUnloaded(uint32 gridId);

    bool IsEmpty() const { return _spawns.empty(); }

private:
    void DespawnPhase(Map* map, PersonalPhaseSpawns& spawns);

    std::unordered_map<uint32 /*phaseId*/, PersonalPhaseSpawns> _spawns;
};

/* Handles personal phase trackers for all owners */
struct MultiPersonalPhaseTracker
{
    void LoadGrid(PhaseShift const& phaseShift, NGridType& grid, Map* map, Cell const& cell);
    void UnloadGrid(NGridType& grid);

    void RegisterTrackedObject(uint32 phaseId, ObjectGuid const& phaseOwner, WorldObject* object);
    void UnregisterTrackedObject(WorldObject* object);

    void OnOwnerPhaseChanged(WorldObject const* phaseOwner, NGridType* grid, Map* map, Cell const& cell);
    void MarkAllPhasesForDeletion(ObjectGuid const& phaseOwner);

    void Update(Map* map, uint32 diff);

private:
    std::unordered_map<ObjectGuid /*owner*/, PlayerPersonalPhasesTracker> _playerData;
};

#endif // PersonalPhaseTracker_h__
