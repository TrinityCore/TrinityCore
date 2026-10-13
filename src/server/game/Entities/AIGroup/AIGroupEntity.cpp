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

AIGroup::AIGroup() { }

bool AIGroup::Create(Creature* mainMember)
{
    if (!mainMember || !mainMember->GetSpawnId() || !mainMember->GetMap())
        return false;

    _mainMemberGuid = mainMember->GetSpawnId();
    _triggersId = mainMember->GetCurrentTriggersId();

    _Create(ObjectGuid::Create<HighGuid::AIGroup>(_mainMemberGuid));
    SetMap(mainMember->GetMap());
    _currentActionSet = 0;
    _script.OnInitialize(this);
    return true;
}

void AIGroup::Update(uint32 diff)
{
    WorldObject::Update(diff);
    _script.SetActor(GetMap()->GetCreatureBySpawnId(_mainMemberGuid));
    _script.OnUpdate(diff);
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