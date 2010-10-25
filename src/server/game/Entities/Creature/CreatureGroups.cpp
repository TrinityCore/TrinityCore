/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Creature.h"
#include "CreatureGroups.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"

#include "CreatureAI.h"

#define MAX_DESYNC 5.0f

CreatureGroupInfoType   CreatureGroupMap;

void CreatureGroupManager::AddCreatureToGroup(uint32 groupId, Creature *member)
{
    Map *map = member->FindMap();
    if (!map)
        return;

    CreatureGroupHolderType::iterator itr = map->CreatureGroupHolder.find(groupId);

    //Add member to an existing group
    if (itr != map->CreatureGroupHolder.end())
    {
        sLog.outDebug("Group found: %u, inserting creature GUID: %u, Group InstanceID %u", groupId, member->GetGUIDLow(), member->GetInstanceId());
        itr->second->AddMember(member);
    }
    //Create new group
    else
    {
        sLog.outDebug("Group not found: %u. Creating new group.", groupId);
        CreatureGroup* group = new CreatureGroup(groupId);
        map->CreatureGroupHolder[groupId] = group;
        group->AddMember(member);
    }
}

void CreatureGroupManager::RemoveCreatureFromGroup(CreatureGroup *group, Creature *member)
{
    sLog.outDebug("Deleting member pointer to GUID: %u from group %u", group->GetId(), member->GetDBTableGUIDLow());
    group->RemoveMember(member);

    if (group->isEmpty())
    {
        Map *map = member->FindMap();
        if (!map)
            return;

        sLog.outDebug("Deleting group with InstanceID %u", member->GetInstanceId());
        map->CreatureGroupHolder.erase(group->GetId());
        delete group;
    }
}

void CreatureGroupManager::LoadCreatureFormations()
{
    //Clear existing map
    CreatureGroupMap.clear();

    //Check Integrity of the table
    QueryResult result = WorldDatabase.Query("SELECT MAX(leaderGUID) FROM creature_formations");

    if (!result)
    {
        sLog.outErrorDb(" ...an error occured while loading the table creature_formations (maybe it doesn't exist ?)\n");
        return;
    }

    //Get group data
    result = WorldDatabase.Query("SELECT leaderGUID, memberGUID, dist, angle, groupAI FROM creature_formations ORDER BY leaderGUID");

    if (!result)
    {
        sLog.outErrorDb("The table creature_formations is empty or corrupted");
        return;
    }

    std::set<uint32> guidSet;

    QueryResult guidResult = WorldDatabase.PQuery("SELECT guid FROM creature");
    if (guidResult)
    {
        do 
        {
            Field *fields = guidResult->Fetch();
            uint32 guid = fields[0].GetUInt32();

            guidSet.insert(guid);

        } while (guidResult->NextRow());
    }

    uint64 total_records = result->GetRowCount();
    barGoLink bar(total_records);
    Field *fields;

    FormationInfo *group_member;
    //Loading data...
    do
    {
        fields = result->Fetch();

        bar.step();
        //Load group member data
        group_member                        = new FormationInfo;
        group_member->leaderGUID            = fields[0].GetUInt32();
        uint32 memberGUID = fields[1].GetUInt32();
        group_member->groupAI                = fields[4].GetUInt8();
        //If creature is group leader we may skip loading of dist/angle
        if (group_member->leaderGUID != memberGUID)
        {
            group_member->follow_dist       = fields[2].GetFloat();
            group_member->follow_angle      = fields[3].GetFloat() * M_PI / 180;
        }
        else
        {
            group_member->follow_dist       = 0;
            group_member->follow_angle      = 0;
        }

        // check data correctness
        {
            if (guidSet.find(group_member->leaderGUID) == guidSet.end())
            {
                sLog.outErrorDb("creature_formations table leader guid %u incorrect (not exist)", group_member->leaderGUID);
                delete group_member;
                continue;
            }

            if (guidSet.find(memberGUID) == guidSet.end())
            {
                sLog.outErrorDb("creature_formations table member guid %u incorrect (not exist)", memberGUID);
                delete group_member;
                continue;
            }
        }

        CreatureGroupMap[memberGUID] = group_member;
    }
    while (result->NextRow()) ;

    sLog.outString();
    sLog.outString(">> Loaded " UI64FMTD " creatures in formations", total_records);
    sLog.outString();
}

void CreatureGroup::AddMember(Creature *member)
{
    sLog.outDebug("CreatureGroup::AddMember: Adding unit GUID: %u.", member->GetGUIDLow());

    //Check if it is a leader
    if (member->GetDBTableGUIDLow() == m_groupID)
    {
        sLog.outDebug("Unit GUID: %u is formation leader. Adding group.", member->GetGUIDLow());
        m_leader = member;
    }

    m_members[member] = CreatureGroupMap.find(member->GetDBTableGUIDLow())->second;
    member->SetFormation(this);
}

void CreatureGroup::RemoveMember(Creature *member)
{
    if (m_leader == member)
        m_leader = NULL;

    m_members.erase(member);
    member->SetFormation(NULL);
}

void CreatureGroup::MemberAttackStart(Creature *member, Unit *target)
{
    uint8 groupAI = CreatureGroupMap[member->GetDBTableGUIDLow()]->groupAI;
    if (!groupAI)
        return;

    if (groupAI == 1 && member != m_leader)
        return;

    for (CreatureGroupMemberType::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        if (m_leader) // avoid crash if leader was killed and reset.
            sLog.outDebug("GROUP ATTACK: group instance id %u calls member instid %u", m_leader->GetInstanceId(), member->GetInstanceId());

        //Skip one check
        if (itr->first == member)
            continue;

        if (!itr->first->isAlive())
            continue;

        if (itr->first->getVictim())
            continue;

        if (itr->first->canAttack(target) && itr->first->AI())
            itr->first->AI()->AttackStart(target);
    }
}

void CreatureGroup::FormationReset(bool dismiss)
{
    for (CreatureGroupMemberType::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        if (itr->first != m_leader && itr->first->isAlive())
        {
            if (dismiss)
                itr->first->GetMotionMaster()->Initialize();
            else
                itr->first->GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);
            sLog.outDebug("Set %s movement for member GUID: %u", dismiss ? "default" : "idle", itr->first->GetGUIDLow());
        }
    }
    m_Formed = !dismiss;
}

void CreatureGroup::LeaderMoveTo(float x, float y, float z)
{
    if (!m_leader)
        return;

    float pathangle    = atan2(m_leader->GetPositionY() - y, m_leader->GetPositionX() - x);

    for (CreatureGroupMemberType::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        Creature *member = itr->first;
        if (member == m_leader || !member->isAlive() || member->getVictim())
            continue;

        float angle = itr->second->follow_angle;
        float dist = itr->second->follow_dist;

        float dx = x + cos(angle + pathangle) * dist;
        float dy = y + sin(angle + pathangle) * dist;
        float dz = z;

        Trinity::NormalizeMapCoord(dx);
        Trinity::NormalizeMapCoord(dy);

        member->UpdateGroundPositionZ(dx, dy, dz);

        if (member->IsWithinDist(m_leader, dist + MAX_DESYNC))
            member->SetUnitMovementFlags(m_leader->GetUnitMovementFlags());
        else
            member->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

        member->GetMotionMaster()->MovePoint(0, dx, dy, dz);
        member->SetHomePosition(dx, dy, dz, pathangle);
    }
}
