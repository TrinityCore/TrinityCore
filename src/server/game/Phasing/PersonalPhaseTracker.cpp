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
#include "Map.h"
#include "Object.h"

 /*********************************************************/
 /***             PersonalPhaseTracker                  ***/
 /*********************************************************/

PersonalPhaseTracker::PersonalPhaseTracker() : _phasedGroups() { }

void PersonalPhaseTracker::AddPersonalPhaseObject(WorldObject const* owner, uint32 phaseId, WorldObject* worldObject)
{
    worldObject->GetPhaseShift().SetPersonalOwner(owner);
    _phasedGroups[phaseId].objects.insert(worldObject);
}

void PersonalPhaseTracker::OnOwnerPhasesChanged(WorldObject const* owner)
{
    PhaseShift const& phaseShift = owner->GetPhaseShift();

    // Loop over all our tracked phases. If any don't exist - delete them
    for (auto& iter : _phasedGroups)
        if (iter.second.deleteAfter == -1 && !phaseShift.HasPhase(iter.first) && iter.second.AnyLoaded())
            iter.second.deleteAfter = PersonalPhaseTrackerGroup::DELETE_TIME_DEFAULT;

    // loop over all owner phases. If any exist and marked for deletion - reset delete
    for (PhaseShift::PhaseRef const& phaseRef : phaseShift.GetPhases())
    {
        auto iter = _phasedGroups.find(phaseRef.Id);
        if (iter != _phasedGroups.cend() && iter->second.deleteAfter >= 0)
            iter->second.deleteAfter = PersonalPhaseTrackerGroup::DELETE_TIME_NEVER;
    }
}

void PersonalPhaseTracker::Update(Map* map, uint32 diff)
{
    for (auto& iter : _phasedGroups)
    {
        if (iter.second.deleteAfter > 0)
        {
            if (iter.second.deleteAfter <= int32(diff))
                DestroyGroup(map, iter.second);
            else
                iter.second.deleteAfter -= diff;
        }
    }
}

void PersonalPhaseTracker::DestroyGroup(Map* map, PersonalPhaseTrackerGroup& group)
{
    for (WorldObject* obj : group.objects)
        map->AddObjectToRemoveList(obj);

    group.objects.clear();
    group.gridsLoaded.clear();
    group.deleteAfter = PersonalPhaseTrackerGroup::DELETE_TIME_NEVER;
}

void PersonalPhaseTracker::CleanAllGroups()
{
    for (auto& iter : _phasedGroups)
        if (iter.second.AnyLoaded())
            iter.second.deleteAfter = PersonalPhaseTrackerGroup::DELETE_TIME_DEFAULT;
}

void PersonalPhaseTracker::RemoveObjectFromPhases(WorldObject* object)
{
    for (auto& iter : _phasedGroups)
        iter.second.objects.erase(object);
}

bool PersonalPhaseTracker::IsGridLoadedForPhase(uint32 gridId, uint32 phaseId) const
{
    auto iter = _phasedGroups.find(phaseId);
    if (iter == _phasedGroups.cend())
        return false;

    return iter->second.gridsLoaded.find(gridId) != iter->second.gridsLoaded.cend();
}

void PersonalPhaseTracker::SetGridLoadedForPhase(uint32 gridId, uint32 phaseId)
{
    PersonalPhaseTrackerGroup& group = _phasedGroups[phaseId];
    group.gridsLoaded.insert(gridId);
}

/*********************************************************/
/***           MultiPersonalPhaseTracker               ***/
/*********************************************************/

void MultiPersonalPhaseTracker::AddPersonalPhaseObject(WorldObject const* phaseOwner, uint32 phaseId, WorldObject* obj)
{
    ASSERT(phaseOwner);
    ASSERT(obj);

    _data[phaseOwner->GetGUID()].AddPersonalPhaseObject(phaseOwner, phaseId, obj);
}

void MultiPersonalPhaseTracker::CleanOwnerGroups(WorldObject const* phaseOwner)
{
    auto iter = _data.find(phaseOwner->GetGUID());
    if (iter == _data.cend())
        return;

    iter->second.CleanAllGroups();
}

void MultiPersonalPhaseTracker::RemoveObjectFromPhases(WorldObject* object)
{
    if (!object->GetPhaseShift().HasPersonalPhase())
        return;

    ObjectGuid const& personalGuid = object->GetPhaseShift().GetPersonalGuid();

    auto iter = _data.find(personalGuid);
    if (iter == _data.cend())
        return;

    iter->second.RemoveObjectFromPhases(object);
}

void MultiPersonalPhaseTracker::Update(Map* map, uint32 diff)
{
    for (auto& iter : _data)
        iter.second.Update(map, diff);
}

void MultiPersonalPhaseTracker::OnOwnerPhaseChanged(WorldObject const* phaseOwner)
{
    auto iter = _data.find(phaseOwner->GetGUID());
    if (iter == _data.cend())
        return;

    iter->second.OnOwnerPhasesChanged(phaseOwner);
}
