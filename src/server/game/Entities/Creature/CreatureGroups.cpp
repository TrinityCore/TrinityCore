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
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "ObjectMgr.h"

#include <cmath>

#define MAX_DESYNC 5.0f

FormationMgr* FormationMgr::instance()
{
    static FormationMgr instance;
    return &instance;
}

void FormationMgr::AddCreatureToGroup(uint32 leaderGuid, Creature* creature)
{
    Map* map = creature->FindMap();
    if (!map)
        return;

    CreatureGroupHolderType::iterator itr = map->CreatureGroupHolder.find(leaderGuid);

    //Add member to an existing group
    if (itr != map->CreatureGroupHolder.end())
    {
        TC_LOG_DEBUG("entities.unit", "Group found: %u, inserting creature GUID: %u, Group InstanceID %u", leaderGuid, creature->GetGUID().GetCounter(), creature->GetInstanceId());
        itr->second->AddMember(creature);
    }
    //Create new group
    else
    {
        TC_LOG_DEBUG("entities.unit", "Group not found: %u. Creating new group.", leaderGuid);
        CreatureGroup* group = new CreatureGroup(leaderGuid);
        map->CreatureGroupHolder[leaderGuid] = group;
        group->AddMember(creature);
    }
}

void FormationMgr::RemoveCreatureFromGroup(CreatureGroup* group, Creature* member)
{
    TC_LOG_DEBUG("entities.unit", "Deleting member pointer to GUID: %u from group %u", group->GetId(), member->GetSpawnId());
    group->RemoveMember(member);

    if (group->isEmpty())
    {
        Map* map = member->FindMap();
        if (!map)
            return;

        TC_LOG_DEBUG("entities.unit", "Deleting group with InstanceID %u", member->GetInstanceId());
        map->CreatureGroupHolder.erase(group->GetId());
        delete group;
    }
}

void FormationMgr::LoadCreatureFormations()
{
    uint32 oldMSTime = getMSTime();

    CreatureGroupMap.clear();

    //Get group data
    QueryResult result = WorldDatabase.Query("SELECT LeaderGUID, MemberGUID, FollowDistance, FollowAngle, GroupAI, InversionPoint1, InversionPoint2 FROM creature_formations ORDER BY LeaderGUID");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">>  Loaded 0 creatures in formations. DB table `creature_formations` is empty!");
        return;
    }

    uint32 count = 0;
    Field* fields;
    FormationInfo group_member;

    do
    {
        fields = result->Fetch();

        // Load group member data
        group_member.LeaderGUID            = fields[0].GetUInt32();
        uint32 memberGUID                  = fields[1].GetUInt32();
        group_member.GroupAI               = fields[4].GetUInt32();
        group_member.InversionPoint1       = fields[5].GetInt32();
        group_member.InversionPoint2       = fields[6].GetInt32();
        // If creature is group leader we may skip loading of dist/angle
        if (group_member.LeaderGUID != memberGUID)
        {
            group_member.FollowDistance    = fields[2].GetFloat();
            group_member.FollowAngle       = fields[3].GetFloat() * float(M_PI) / 180;
        }
        else
        {
            group_member.FollowDistance    = 0;
            group_member.FollowAngle       = 0;
        }

        // check data correctness
        {
            if (!sObjectMgr->GetCreatureData(group_member.LeaderGUID))
            {
                TC_LOG_ERROR("sql.sql", "creature_formations table leader guid %u incorrect (not exist)", group_member.LeaderGUID);
                continue;
            }

            if (!sObjectMgr->GetCreatureData(memberGUID))
            {
                TC_LOG_ERROR("sql.sql", "creature_formations table member guid %u incorrect (not exist)", memberGUID);
                continue;
            }
        }

        CreatureGroupMap[memberGUID] = group_member;
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creatures in formations in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void CreatureGroup::AddMember(Creature* member)
{
    TC_LOG_DEBUG("entities.unit", "CreatureGroup::AddMember: Adding unit GUID: %u.", member->GetGUID().GetCounter());

    //Check if it is a leader
    if (member->GetSpawnId() == m_groupID)
    {
        TC_LOG_DEBUG("entities.unit", "Unit GUID: %u is formation leader. Adding group.", member->GetGUID().GetCounter());
        m_leader = member;
    }

    m_members[member] = sFormationMgr->CreatureGroupMap.find(member->GetSpawnId())->second;
    member->SetFormation(this);
}

void CreatureGroup::RemoveMember(Creature* member)
{
    if (m_leader == member)
        m_leader = nullptr;

    m_members.erase(member);
    member->SetFormation(nullptr);
}

void CreatureGroup::MemberEngagingTarget(Creature* member, Unit* target)
{
    uint8 groupAI = sFormationMgr->CreatureGroupMap[member->GetSpawnId()].GroupAI;
    if (!groupAI)
        return;

    if (member == m_leader)
    {
        if (!(groupAI & FLAG_MEMBERS_ASSIST_LEADER))
            return;
    }
    else if (!(groupAI & FLAG_LEADER_ASSISTS_MEMBER))
        return;

    for (CreatureGroupMemberType::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        Creature* other = itr->first;

        // Skip self
        if (other == member)
            continue;

        if (!other->IsAlive())
            continue;

        if (((other != m_leader && (groupAI & FLAG_MEMBERS_ASSIST_LEADER)) || (other == m_leader && (groupAI & FLAG_LEADER_ASSISTS_MEMBER))) && other->IsValidAttackTarget(target))
            other->EngageWithTarget(target);
    }
}

void CreatureGroup::FormationReset(bool dismiss)
{
    for (CreatureGroupMemberType::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        if (itr->first != m_leader && itr->first->IsAlive())
        {
            if (dismiss)
                itr->first->GetMotionMaster()->Initialize();
            else
                itr->first->GetMotionMaster()->MoveIdle();
            TC_LOG_DEBUG("entities.unit", "Set %s movement for member GUID: %u", dismiss ? "default" : "idle", itr->first->GetGUID().GetCounter());
        }
    }
    m_Formed = !dismiss;
}

void CreatureGroup::LeaderStartedMoving()
{
    if (!m_leader)
        return;

    for (CreatureGroupMemberType::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        Creature* member = itr->first;
        if (member == m_leader || !member->IsAlive() || member->GetVictim() || !(itr->second.GroupAI & FLAG_IDLE_IN_FORMATION))
            continue;

        float angle = itr->second.FollowAngle + float(M_PI);
        float dist = itr->second.FollowDistance;

        MovementGenerator const* moveGen = member->GetMotionMaster()->GetMotionSlot(MOTION_SLOT_IDLE);
        if (!moveGen || moveGen->GetMovementGeneratorType() != FORMATION_MOTION_TYPE)
            member->GetMotionMaster()->MoveFormation(m_leader, dist, angle, itr->second.InversionPoint1, itr->second.InversionPoint2);
    }
}

bool CreatureGroup::CanLeaderStartMoving() const
{
    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        if (itr->first != m_leader && itr->first->IsAlive())
        {
            if (itr->first->IsInCombat() || itr->first->IsReturningHome())
                return false;
        }
    }

    return true;
}
