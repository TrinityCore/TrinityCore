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

#include "PersonalPhaseTracker.h"
#include "Containers.h"
#include "Log.h"
#include "Map.h"
#include "Object.h"
#include "ObjectGridLoader.h"
#include "ObjectMgr.h"

 /*********************************************************/
 /***            PlayerPersonalPhasesTracker            ***/
 /*********************************************************/

void PlayerPersonalPhasesTracker::RegisterTrackedObject(uint32 phaseId, WorldObject* object)
{
    _spawns[phaseId].Objects.insert(object);
}

void PlayerPersonalPhasesTracker::UnregisterTrackedObject(WorldObject* object)
{
    for (auto& [_, spawns] : _spawns)
        spawns.Objects.erase(object);
}

void PlayerPersonalPhasesTracker::OnOwnerPhasesChanged(WorldObject const* owner)
{
    PhaseShift const& phaseShift = owner->GetPhaseShift();

    // Loop over all our tracked phases. If any don't exist - delete them
    for (auto& [phaseId, spawns] : _spawns)
        if (!spawns.DurationRemaining && !phaseShift.HasPhase(phaseId))
            spawns.DurationRemaining = PersonalPhaseSpawns::DELETE_TIME_DEFAULT;

    // loop over all owner phases. If any exist and marked for deletion - reset delete
    for (PhaseShift::PhaseRef const& phaseRef : phaseShift.GetPhases())
        if (PersonalPhaseSpawns* spawns = Trinity::Containers::MapGetValuePtr(_spawns, phaseRef.Id))
            spawns->DurationRemaining.reset();
}

void PlayerPersonalPhasesTracker::MarkAllPhasesForDeletion()
{
    for (auto& [_, spawns] : _spawns)
        spawns.DurationRemaining = PersonalPhaseSpawns::DELETE_TIME_DEFAULT;
}

void PlayerPersonalPhasesTracker::Update(Map* map, uint32 diff)
{
    for (auto itr = _spawns.begin(); itr != _spawns.end(); )
    {
        if (itr->second.DurationRemaining)
        {
            itr->second.DurationRemaining = *itr->second.DurationRemaining - Milliseconds(diff);
            if (itr->second.DurationRemaining <= Milliseconds::zero())
            {
                DespawnPhase(map, itr->second);
                itr = _spawns.erase(itr);
                continue;
            }
        }
        ++itr;
    }
}

bool PlayerPersonalPhasesTracker::IsGridLoadedForPhase(uint32 gridId, uint32 phaseId) const
{
    if (PersonalPhaseSpawns const* spawns = Trinity::Containers::MapGetValuePtr(_spawns, phaseId))
        return spawns->Grids.find(gridId) != spawns->Grids.cend();

    return false;
}

void PlayerPersonalPhasesTracker::SetGridLoadedForPhase(uint32 gridId, uint32 phaseId)
{
    PersonalPhaseSpawns& group = _spawns[phaseId];
    group.Grids.insert(gridId);
}

void PlayerPersonalPhasesTracker::SetGridUnloaded(uint32 gridId)
{
    for (auto itr = _spawns.begin(); itr != _spawns.end(); )
    {
        itr->second.Grids.erase(gridId);
        if (itr->second.IsEmpty())
            itr = _spawns.erase(itr);
        else
            ++itr;
    }
}

void PlayerPersonalPhasesTracker::DespawnPhase(Map* map, PersonalPhaseSpawns& spawns)
{
    for (WorldObject* obj : spawns.Objects)
        map->AddObjectToRemoveList(obj);

    spawns.Objects.clear();
    spawns.Grids.clear();
}

/*********************************************************/
/***             MultiPersonalPhaseTracker             ***/
/*********************************************************/

void MultiPersonalPhaseTracker::LoadGrid(PhaseShift const& phaseShift, NGridType& grid, Map* map, Cell const& cell)
{
    if (!phaseShift.HasPersonalPhase())
        return;

    PersonalPhaseGridLoader loader(grid, map, cell, phaseShift.GetPersonalGuid());
    PlayerPersonalPhasesTracker& playerTracker = _playerData[phaseShift.GetPersonalGuid()];

    for (PhaseShift::PhaseRef const& phaseRef : phaseShift.GetPhases())
    {
        if (!phaseRef.IsPersonal())
            continue;

        if (!sObjectMgr->HasPersonalSpawns(map->GetId(), map->GetDifficultyID(), phaseRef.Id))
            continue;

        if (playerTracker.IsGridLoadedForPhase(grid.GetGridId(), phaseRef.Id))
            continue;

        TC_LOG_DEBUG("maps", "Loading personal phase objects (phase %u) in grid[%u, %u] for map %u instance %u",
            phaseRef.Id, cell.GridX(), cell.GridY(), map->GetId(), map->GetInstanceId());

        loader.Load(phaseRef.Id);

        playerTracker.SetGridLoadedForPhase(grid.GetGridId(), phaseRef.Id);
    }

    if (loader.GetLoadedGameObjects())
        map->Balance();
}

void MultiPersonalPhaseTracker::UnloadGrid(NGridType& grid)
{
    for (auto itr = _playerData.begin(); itr != _playerData.end(); )
    {
        itr->second.SetGridUnloaded(grid.GetGridId());
        if (itr->second.IsEmpty())
            itr = _playerData.erase(itr);
        else
            ++itr;
    }
}

void MultiPersonalPhaseTracker::RegisterTrackedObject(uint32 phaseId, ObjectGuid const& phaseOwner, WorldObject* object)
{
    ASSERT(phaseId);
    ASSERT(!phaseOwner.IsEmpty());
    ASSERT(object);

    _playerData[phaseOwner].RegisterTrackedObject(phaseId, object);
}

void MultiPersonalPhaseTracker::UnregisterTrackedObject(WorldObject* object)
{
    if (PlayerPersonalPhasesTracker* playerTracker = Trinity::Containers::MapGetValuePtr(_playerData, object->GetPhaseShift().GetPersonalGuid()))
        playerTracker->UnregisterTrackedObject(object);
}

void MultiPersonalPhaseTracker::OnOwnerPhaseChanged(WorldObject const* phaseOwner, NGridType* grid, Map* map, Cell const& cell)
{
    if (PlayerPersonalPhasesTracker* playerTracker = Trinity::Containers::MapGetValuePtr(_playerData, phaseOwner->GetGUID()))
        playerTracker->OnOwnerPhasesChanged(phaseOwner);

    if (grid)
        LoadGrid(phaseOwner->GetPhaseShift(), *grid, map, cell);
}

void MultiPersonalPhaseTracker::MarkAllPhasesForDeletion(ObjectGuid const& phaseOwner)
{
    if (PlayerPersonalPhasesTracker* playerTracker = Trinity::Containers::MapGetValuePtr(_playerData, phaseOwner))
        playerTracker->MarkAllPhasesForDeletion();
}

void MultiPersonalPhaseTracker::Update(Map* map, uint32 diff)
{
    for (auto itr = _playerData.begin(); itr != _playerData.end(); )
    {
        itr->second.Update(map, diff);
        if (itr->second.IsEmpty())
            itr = _playerData.erase(itr);
        else
            ++itr;
    }
}
