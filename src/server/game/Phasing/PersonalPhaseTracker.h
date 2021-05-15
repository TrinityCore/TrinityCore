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

#ifndef _PERSONAL_PHASE_TRACKER_H
#define _PERSONAL_PHASE_TRACKER_H

#include "Common.h"
#include "ObjectGuid.h"
#include <unordered_map>
#include <set>

class Map;
class WorldObject;

struct PersonalPhaseTrackerGroup
{
    static const int32 DELETE_TIME_NEVER = -1;
    static const int32 DELETE_TIME_DEFAULT = 30 * IN_MILLISECONDS;

    using TrackedObjectSet = std::set<WorldObject*>;

    TrackedObjectSet objects;
    int32 deleteAfter; // will be deleted when reaches 0.
    std::set<uint16> gridsLoaded;

    PersonalPhaseTrackerGroup() : objects(), deleteAfter(DELETE_TIME_NEVER), gridsLoaded() { }

    bool AnyLoaded() const { return objects.size() > 0 || gridsLoaded.size() > 0; }
};

/* Tracks personal phases for a single owner */
struct PersonalPhaseTracker
{
public:
    PersonalPhaseTracker();

    void AddPersonalPhaseObject(WorldObject const* owner, uint32 phaseId, WorldObject* worldObject);
    void OnOwnerPhasesChanged(WorldObject const* owner);
    void RemoveObjectFromPhases(WorldObject* object);

    void CleanAllGroups();

    void Update(Map* map, uint32 diff);

    bool IsGridLoadedForPhase(uint32 gridId, uint32 phaseId) const;
    void SetGridLoadedForPhase(uint32 gridId, uint32 phaseId);

private:
    void DestroyGroup(Map* map, PersonalPhaseTrackerGroup& group);

    std::unordered_map<uint32 /*phaseId*/, PersonalPhaseTrackerGroup> _phasedGroups;
};

/* Handles personal phase trackers for all owners */
struct MultiPersonalPhaseTracker
{
    void AddPersonalPhaseObject(WorldObject const* phaseOwner, uint32 phaseId, WorldObject* obj);
    void CleanOwnerGroups(WorldObject const* phaseOwner);
    void RemoveObjectFromPhases(WorldObject* object);

    void OnOwnerPhaseChanged(WorldObject const* phaseOwner);

    void Update(Map* map, uint32 diff);

    PersonalPhaseTracker& GetPersonalPhaseTracker(ObjectGuid const& guid) { return _data[guid]; }

private:
    std::unordered_map<ObjectGuid /*owner*/, PersonalPhaseTracker> _data;
};

#endif /* _PERSONAL_PHASE_TRACKER_H */
