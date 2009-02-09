/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Creature.h"
#include "CreatureGroups.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "Policies/SingletonImp.h"

#define MAX_DESYNC 5.0f
//TODO: Create group manager for each map
INSTANTIATE_SINGLETON_1(CreatureGroupManager);

UNORDERED_MAP<uint32, CreatureGroup*> CreatureGroupHolder;
UNORDERED_MAP<uint32, FormationMember*> CreatureGroupMap;

void CreatureGroupManager::UpdateCreatureGroup(uint32 group_id, Creature *member)
{
    if(CreatureGroupHolder.find(group_id) != CreatureGroupHolder.end())
    {
        sLog.outDebug("Group found: %u, inserting creature GUID: %u", group_id, member->GetGUIDLow());
        CreatureGroupHolder[group_id]->AddMember(member);
    }
    else
    {
        sLog.outDebug("Group not found: %u. Creating new group.", group_id);
        CreatureGroup* formation = new CreatureGroup;
        CreatureGroupHolder[group_id] = formation;
        formation->AddMember(member);
    }
}

void CreatureGroupManager::DestroyGroup(uint32 group_id, uint64 guid)
{
    if(CreatureGroupHolder.find(group_id) != CreatureGroupHolder.end())
    {
        sLog.outDebug("Deleting member pointer to GUID: %u from group %u", group_id, guid);
        CreatureGroupHolder[group_id]->RemoveMember(guid);

        if(CreatureGroupHolder[group_id]->isEmpty())
        {
            sLog.outDebug("Deleting group %u", group_id);
            delete CreatureGroupHolder[group_id];
            CreatureGroupHolder.erase(group_id);
        }
    }
}

void CreatureGroupManager::LoadCreatureFormations()
{
    //Clear existing map
    CreatureGroupMap.clear();

    //Check Integrity of the table
    QueryResult *result = WorldDatabase.PQuery("SELECT MAX(`leaderGUID`) FROM `creature_formations`");

    if(!result)
    {
        sLog.outErrorDb(" an error occured while loading the table `creature_formations` ( maybe it doesn't exist ?)\n");
        return;
    }
    delete result;

    //Get group data
    result = WorldDatabase.PQuery("SELECT `leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI` FROM `creature_formations` ORDER BY `leaderGUID`");

    if(!result)
    {
        sLog.outErrorDb("The table `creature_formations` is empty or corrupted");
        return;
    }

    uint32 total_records = result->GetRowCount(), lastLeaderGUID = 0;
    barGoLink bar( total_records);
    Field *fields;

    FormationMember *group_member;
    //Loading data...
    do
    {
        fields = result->Fetch();

        bar.step();
        //Load group member data
        group_member                        = new FormationMember;
        group_member->leaderGUID            = fields[0].GetUInt32();
        group_member->memberGUID            = fields[1].GetUInt32();
        group_member->groupAI               = fields[4].GetUInt8();
        //If creature is group leader we may skip loading of dist/angle
        if(group_member->leaderGUID != group_member->memberGUID)
        {
            group_member->follow_dist           = fields[2].GetUInt32();
            group_member->follow_angle          = fields[3].GetUInt32();
        }

        CreatureGroupMap[group_member->memberGUID] = group_member;

        if(lastLeaderGUID != group_member->leaderGUID)
            lastLeaderGUID = group_member->leaderGUID;
    }
    while(result->NextRow()) ;

    sLog.outString();
    sLog.outString( ">> Loaded %u creatures in formations", total_records );
    sLog.outString();
    //Free some heap
    delete result;
}

void CreatureGroup::AddMember(Creature *member)
{
    sLog.outDebug("Adding unit GUID: %u.", member->GetGUIDLow());

    uint64 guid = member->GetGUID();
    //We first search creature member if exist
    if(CreatureGroupMembers.find(guid) != CreatureGroupMembers.end())
        return;
    //Check is that shit is a leader
    if(member->IsFormationLeader())
    {
        sLog.outDebug("Unit GUID: %u is formation leader. Adding group.", member->GetGUIDLow());
        m_leader = member;
    }
    //Add to the club
    CreatureGroupMembers[guid] = member;
    sLog.outDebug("Unit GUID: %u added.", member->GetGUID());
}

void CreatureGroup::RemoveMember(uint64 guid)
{
    if(CreatureGroupMembers.find(guid) != CreatureGroupMembers.end())
        CreatureGroupMembers.erase(guid);
}

void CreatureGroup::MemberHasAttacked(Creature *member)
{
    uint8 groupAI = CreatureGroupMap[member->GetDBTableGUIDLow()]->groupAI;;

    for(UNORDERED_MAP<uint64, Creature*>::iterator itr = CreatureGroupMembers.begin(); itr != CreatureGroupMembers.end(); itr++)
    {
        sLog.outDebug("AI:%u:Group member found: %u, attacked by %s.", groupAI, itr->second->GetGUIDLow(), member->getVictim()->GetName());
        if(itr->second)
        {
            switch(groupAI)
            {
                case 0:
                    return;
                case 1:
                    if(!member->IsFormationLeader())
                        return;
            }
            //Attack if everything is OK
            itr->second->AI()->AttackStart(member->getVictim());
        }
    }
}

void CreatureGroup::LeaderMovedInEvade()
{
    for(UNORDERED_MAP<uint64, Creature*>::iterator itr = CreatureGroupMembers.begin(); itr != CreatureGroupMembers.end(); itr++)
    {
        if(itr->second && itr->second->isAlive() && !itr->second->isInCombat() && !itr->second->getVictim())
            SetMemberDestination(itr->second);
    }
}

void CreatureGroup::SetMemberDestination(Creature *member)
{
    if(!member || !m_leader || member->IsFormationLeader())
        return;

    float x,y,z;
    uint32 lowguid = member->GetGUIDLow();

    UNORDERED_MAP<uint32, FormationMember*>::iterator itr2 = CreatureGroupMap.find(lowguid);

    if(m_leader->GetMotionMaster()->GetDestination(x,y,z) && itr2 != CreatureGroupMap.end())
    {
        float dist, angle, pathangle;

        angle       = CreatureGroupMap[lowguid]->follow_angle;
        dist        = CreatureGroupMap[lowguid]->follow_dist;
        pathangle   = atan2(m_leader->GetPositionY()-y, m_leader->GetPositionX()-x);

        x = x+cos(angle+pathangle)*dist;
        y = y+sin(angle+pathangle)*dist;

        member->GetMotionMaster()->Clear();

        if(member->GetDistance(m_leader) < dist+MAX_DESYNC)
            member->SetUnitMovementFlags(m_leader->GetUnitMovementFlags());
        else
            member->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

        member->GetMotionMaster()->MovePoint(0, x, y, z);
    }
}
