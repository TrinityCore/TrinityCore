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

#include "CreatureGroups.h"
#include "Containers.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "ObjectMgr.h"
#include "ZoneScript.h"

FormationMgr::FormationMgr() = default;
FormationMgr::~FormationMgr() = default;

FormationMgr* FormationMgr::instance()
{
    static FormationMgr instance;
    return &instance;
}

void FormationMgr::AddCreatureToGroup(ObjectGuid::LowType leaderSpawnId, Creature* creature)
{
    Map* map = creature->GetMap();

    auto [itr, isNew] = map->CreatureGroupHolder.try_emplace(leaderSpawnId, nullptr);
    if (!isNew)
    {
        //Add member to an existing group
        TC_LOG_DEBUG("entities.unit", "Group found: {}, inserting creature {}, Group InstanceID {}", leaderSpawnId, creature->GetGUID(), creature->GetInstanceId());

        // With dynamic spawn the creature may have just respawned
        // we need to find previous instance of creature and delete it from the formation, as it'll be invalidated
        auto bounds = Trinity::Containers::MapEqualRange(map->GetCreatureBySpawnIdStore(), creature->GetSpawnId());
        for (auto const& [spawnId, other] : bounds)
        {
            if (other == creature)
                continue;

            if (itr->second->HasMember(other))
                itr->second->RemoveMember(other);
        }
    }
    else
    {
        //Create new group
        TC_LOG_DEBUG("entities.unit", "Group not found: {}. Creating new group.", leaderSpawnId);
        itr->second = new CreatureGroup(leaderSpawnId);
    }

    itr->second->AddMember(creature);
}

void FormationMgr::RemoveCreatureFromGroup(CreatureGroup* group, Creature* member)
{
    ObjectGuid::LowType leaderSpawnId = group->GetLeaderSpawnId();

    TC_LOG_DEBUG("entities.unit", "Deleting member pointer to GUID: {} from group {}", leaderSpawnId, member->GetSpawnId());
    group->RemoveMember(member);

    // If removed member was alive we need to check if we have any other alive members
    // if not - fire OnCreatureGroupDepleted
    if (ZoneScript* script = member->GetZoneScript())
        if (member->IsAlive() && !group->HasAliveMembers())
            script->OnCreatureGroupDepleted(group);

    if (group->IsEmpty())
    {
        if (leaderSpawnId)
        {
            Map* map = member->GetMap();
            TC_LOG_DEBUG("entities.unit", "Deleting group with InstanceID {}", map->GetInstanceId());
            std::size_t erased = map->CreatureGroupHolder.erase(leaderSpawnId);
            ASSERT(erased, "Not registered group " UI64FMTD " in map %u", leaderSpawnId, map->GetId());
        }

        delete group;
    }
}

void FormationMgr::LoadCreatureFormations()
{
    uint32 oldMSTime = getMSTime();

    //Get group data
    QueryResult result = WorldDatabase.Query("SELECT leaderGUID, memberGUID, dist, angle, groupAI, point_1, point_2 FROM creature_formations ORDER BY leaderGUID");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">>  Loaded 0 creatures in formations. DB table `creature_formations` is empty!");
        return;
    }

    uint32 count = 0;
    std::unordered_set<ObjectGuid::LowType> leaderSpawnIds;
    do
    {
        Field* fields = result->Fetch();

        //Load group member data
        ObjectGuid::LowType leaderSpawnId = fields[0].GetUInt64();
        ObjectGuid::LowType memberSpawnId = fields[1].GetUInt64();

        // check data correctness
        {
            if (!sObjectMgr->GetCreatureData(leaderSpawnId))
            {
                TC_LOG_ERROR("sql.sql", "creature_formations table leader guid {} incorrect (not exist)", leaderSpawnId);
                continue;
            }

            if (!sObjectMgr->GetCreatureData(memberSpawnId))
            {
                TC_LOG_ERROR("sql.sql", "creature_formations table member guid {} incorrect (not exist)", memberSpawnId);
                continue;
            }

            leaderSpawnIds.insert(leaderSpawnId);
        }

        FormationInfo& member             = _creatureGroupMap[memberSpawnId];
        member.LeaderSpawnId              = leaderSpawnId;
        member.FollowDist                 = 0.f;
        member.FollowAngle                = 0.f;

        //If creature is group leader we may skip loading of dist/angle
        if (member.LeaderSpawnId != memberSpawnId)
        {
            member.FollowDist             = fields[2].GetFloat();
            member.FollowAngle            = fields[3].GetFloat() * float(M_PI) / 180.0f;
        }

        member.GroupAI                    = fields[4].GetUInt32();
        for (uint8 i = 0; i < 2; ++i)
            member.LeaderWaypointIDs[i]   = fields[5 + i].GetUInt16();

        ++count;
    } while (result->NextRow());

    for (ObjectGuid::LowType leaderSpawnId : leaderSpawnIds)
    {
        if (!_creatureGroupMap.contains(leaderSpawnId))
        {
            TC_LOG_ERROR("sql.sql", "creature_formation contains leader spawn {} which is not included on its formation, removing", leaderSpawnId);
            for (auto itr = _creatureGroupMap.begin(); itr != _creatureGroupMap.end();)
            {
                if (itr->second.LeaderSpawnId == leaderSpawnId)
                {
                    itr = _creatureGroupMap.erase(itr);
                    continue;
                }

                ++itr;
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} creatures in formations in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

FormationInfo* FormationMgr::GetFormationInfo(ObjectGuid::LowType spawnId)
{
    return Trinity::Containers::MapGetValuePtr(_creatureGroupMap, spawnId);
}

void FormationMgr::AddFormationMember(ObjectGuid::LowType spawnId, float followAng, float followDist, ObjectGuid::LowType leaderSpawnId, uint32 groupAI)
{
    FormationInfo& member = _creatureGroupMap[spawnId];
    member.LeaderSpawnId = leaderSpawnId;
    member.FollowDist    = followDist;
    member.FollowAngle   = followAng;
    member.GroupAI       = groupAI;
    for (uint8 i = 0; i < 2; ++i)
        member.LeaderWaypointIDs[i] = 0;
}

CreatureGroup::CreatureGroup(ObjectGuid::LowType leaderSpawnId) : _leader(nullptr), _members(), _leaderSpawnId(leaderSpawnId), _formed(false), _engaging(false)
{
}

CreatureGroup::~CreatureGroup() = default;

void CreatureGroup::AddMember(Creature* member)
{
    TC_LOG_DEBUG("entities.unit", "CreatureGroup::AddMember: Adding unit {}.", member->GetGUID());

    //Check if it is a leader
    if ((_leaderSpawnId && member->GetSpawnId() == _leaderSpawnId)
        || (!_leaderSpawnId && !_leader))   // in formations made of tempsummons first member to be added is leader
    {
        TC_LOG_DEBUG("entities.unit", "Unit {} is formation leader. Adding group.", member->GetGUID());
        _leader = member;
    }

    _members.emplace(member, sFormationMgr->GetFormationInfo(member->GetSpawnId()));
    member->SetFormation(this);
}

void CreatureGroup::RemoveMember(Creature* member)
{
    if (_leader == member)
        _leader = nullptr;

    _members.erase(member);
    member->SetFormation(nullptr);
}

void CreatureGroup::MemberEngagingTarget(Creature* member, Unit* target)
{
    // used to prevent recursive calls
    if (_engaging)
        return;

    FormationInfo const* formationInfo = Trinity::Containers::MapGetValuePtr(_members, member);
    if (!formationInfo)
        return;

    uint32 groupAI = formationInfo->GroupAI;
    if (!groupAI)
        return;

    if (member == _leader)
    {
        if (!(groupAI & FLAG_MEMBERS_ASSIST_LEADER))
            return;
    }
    else if (!(groupAI & FLAG_LEADER_ASSISTS_MEMBER))
        return;

    _engaging = true;

    for (auto const& [other, _] : _members)
    {
        if (other == member)
            continue;

        if (!other->IsAlive())
            continue;

        if (((other != _leader && (groupAI & FLAG_MEMBERS_ASSIST_LEADER)) || (other == _leader && (groupAI & FLAG_LEADER_ASSISTS_MEMBER))) && other->IsValidAttackTarget(target))
            other->EngageWithTarget(target);
    }

    _engaging = false;
}

void CreatureGroup::FormationReset(bool dismiss)
{
    for (auto const& [member, _] : _members)
    {
        if (member != _leader && member->IsAlive())
        {
            if (dismiss)
                member->GetMotionMaster()->Remove(FORMATION_MOTION_TYPE, MOTION_SLOT_DEFAULT);
            else
                member->GetMotionMaster()->MoveIdle();

            TC_LOG_DEBUG("entities.unit", "CreatureGroup::FormationReset: Set {} movement for member {}", dismiss ? "default" : "idle", member->GetGUID());
        }
    }

    _formed = !dismiss;
}

void CreatureGroup::LeaderStartedMoving()
{
    if (!_leader)
        return;

    for (auto const& [member, formationInfo] : _members)
    {
        if (member == _leader || !member->IsAlive() || member->IsEngaged() || !formationInfo || !(formationInfo->GroupAI & FLAG_IDLE_IN_FORMATION))
            continue;

        float angle = formationInfo->FollowAngle + float(M_PI); // for some reason, someone thought it was a great idea to invert relativ angles...
        float dist = formationInfo->FollowDist;

        if (!member->HasUnitState(UNIT_STATE_FOLLOW_FORMATION))
            member->GetMotionMaster()->MoveFormation(_leader, dist, angle, formationInfo->LeaderWaypointIDs[0], formationInfo->LeaderWaypointIDs[1]);
    }
}

bool CreatureGroup::CanLeaderStartMoving() const
{
    for (auto const& [member, _] : _members)
    {
        if (member != _leader && member->IsAlive())
        {
            if (member->IsEngaged() || member->IsReturningHome())
                return false;
        }
    }

    return true;
}

bool CreatureGroup::HasAliveMembers() const
{
    return std::ranges::any_of(_members, [](Creature const* member) { return member->IsAlive(); }, &MembersMap::value_type::first);
}

bool CreatureGroup::LeaderHasStringId(std::string_view id) const
{
    if (_leader)
        return _leader->HasStringId(id);

    if (CreatureData const* leaderCreatureData = sObjectMgr->GetCreatureData(_leaderSpawnId))
    {
        if (leaderCreatureData->StringId == id)
            return true;

        if (ASSERT_NOTNULL(sObjectMgr->GetCreatureTemplate(leaderCreatureData->id))->StringId == id)
            return true;
    }

    return false;
}
