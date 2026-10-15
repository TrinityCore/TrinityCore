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

#include "AIGroupEntity.h"
#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "Random.h"
#include "AIGroupMgr.h"
#include "ObjectMgr.h"
#include "ByteBuffer.h"
#include <unordered_map>

namespace
{
    using AIGroupMap = std::unordered_multimap<ObjectGuid::LowType, std::unique_ptr<AIGroup>>;
    AIGroupMap AIGroupMaps;
}

AIGroup::AIGroup() { }

AIGroup* AIGroup::GetAIGroupByMainMemberGuid(Creature* creature, ObjectGuid::LowType mainMemberGuid)
{
    if (!creature || !creature->GetMap())
        return nullptr;

    auto const [groupBegin, groupEnd] = AIGroupMaps.equal_range(mainMemberGuid);
    for (auto groupItr = groupBegin; groupItr != groupEnd; ++groupItr)
        if (groupItr->second->GetMap() == creature->GetMap())
            return groupItr->second.get();

    return nullptr;
}

void AIGroup::AddAIGroup(std::unique_ptr<AIGroup> group)
{
    AIGroupMaps.emplace(group->GetMainMemberGuid(), std::move(group));
}

void AIGroup::AddUnitToAIGroup(Creature* unit)
{
    if (!unit || !unit->GetSpawnId() || !unit->GetMap())
        return;

    if (GetAIGroupByMainMemberGuid(unit, unit->GetSpawnId()))
        return;

    if (!sAIGroupMgr->GetGroupMembers(unit->GetSpawnId()) && unit->GetAIName() != "AIGroup" && !unit->GetNativeTriggersId())
        return;

    auto group = std::make_unique<AIGroup>();
    if (!group->Create(unit))
        return;

    group->GetScript()->SetActor(unit);
    group->GetScript()->ProcessEventsFor(ActionTriggers::OnSpawn);
    AddAIGroup(std::move(group));
}

void AIGroup::RemoveUnitFromAIGroup(Creature* unit)
{
    if (!unit || !unit->GetMap() || !unit->GetSpawnId())
        return;

    Map* map = unit->GetMap();
    ObjectGuid::LowType unitGuid = unit->GetSpawnId();
    for (auto groupItr = AIGroupMaps.begin(); groupItr != AIGroupMaps.end();)
    {
        if (groupItr->second->GetMap() != map)
        {
            ++groupItr;
            continue;
        }

        ObjectGuid::LowType mainMemberGuid = groupItr->first;
        std::vector<AIGroupMemberData> const* memberData = sAIGroupMgr->GetGroupMembers(mainMemberGuid);
        bool containsUnit = mainMemberGuid == unitGuid;
        if (memberData)
            for (AIGroupMemberData const& member : *memberData)
                if (member.MemberType == AIGroupMemberType::Creature && member.MemberGuid == unitGuid)
                    containsUnit = true;

        if (!containsUnit)
        {
            ++groupItr;
            continue;
        }

        bool hasRemainingMembers = mainMemberGuid != unitGuid && map->GetCreatureBySpawnId(mainMemberGuid);
        if (memberData)
            for (AIGroupMemberData const& member : *memberData)
            {
                if (member.MemberGuid == unitGuid)
                    continue;

                if (member.MemberType == AIGroupMemberType::Creature && map->GetCreatureBySpawnId(member.MemberGuid))
                    hasRemainingMembers = true;
                else if (member.MemberType == AIGroupMemberType::GameObject && map->GetGameObjectBySpawnId(member.MemberGuid))
                    hasRemainingMembers = true;
            }

        if (hasRemainingMembers)
            ++groupItr;
        else
            groupItr = AIGroupMaps.erase(groupItr);
    }
}

bool AIGroup::Create(Creature* mainMember)
{
    if (!mainMember || !mainMember->GetSpawnId() || !mainMember->GetMap())
        return false;

    _mainMemberGuid = mainMember->GetSpawnId();

    ObjectGuid::LowType lowGuid = static_cast<ObjectGuid::LowType>(_mainMemberGuid);
    _guid = ObjectGuid::Create<HighGuid::AIGroup>(lowGuid);
    _triggersId = mainMember->GetCurrentTriggersId();

    SetMap(mainMember->GetMap());
    _currentActionSet = 0;
    _script.OnInitialize(this);
    return true;
}

void AIGroup::Update(uint32 diff)
{
    if (!GetMap())
        return;

    if (Creature* mainMember = GetMap()->GetCreatureBySpawnId(_mainMemberGuid))
    {
        _script.SetActor(mainMember);
        _script.OnUpdate(diff);
    }
}

void AIGroup::SetCurrentActionSet(uint32 actionSetId)
{
    _currentActionSet = actionSetId;
}

void AIGroup::SetTriggersId(uint32 triggersId)
{
    _triggersId = triggersId;
}

std::vector<WorldObject*> AIGroup::GetMembers(AIGroupUnit unit, AIGroupMgr::ObjectTypeMask typeMask) const
{
    std::vector<WorldObject*> members;
    std::vector<AIGroupMemberData> const* memberData = sAIGroupMgr->GetGroupMembers(_mainMemberGuid);
    if (!memberData)
        return members;

    for (AIGroupMemberData const& member : *memberData)
    {
        if (unit != AIGroupUnit::AllUnits && unit != AIGroupUnit::RandomUnit && member.Unit != unit)
            continue;

        if ((typeMask & AIGroupMgr::ObjectTypeMaskUnit) && member.MemberType == AIGroupMemberType::Creature)
            if (Creature* creature = GetMap()->GetCreatureBySpawnId(member.MemberGuid))
                members.push_back(creature);

        if ((typeMask & AIGroupMgr::ObjectTypeMaskObject) && member.MemberType == AIGroupMemberType::GameObject)
            if (GameObject* gameObject = GetMap()->GetGameObjectBySpawnId(member.MemberGuid))
                members.push_back(gameObject);
    }

    if (unit == AIGroupUnit::RandomUnit && members.size() > 1)
    {
        WorldObject* selected = members[urand(0, uint32(members.size() - 1))];
        members.assign(1, selected);
    }

    return members;
}