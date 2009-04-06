/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

INSTANTIATE_SINGLETON_1(CreatureGroupManager);

CreatureGroupHolderType CreatureGroupHolder;
UNORDERED_MAP<uint32, FormationMember*> CreatureGroupMap;

void CreatureGroupManager::UpdateCreatureGroup(uint32 group_id, Creature &member)
{
    std::multimap<uint32, CreatureGroup *>::iterator cgroup_data = CreatureGroupHolder.find(group_id);

    if(cgroup_data != CreatureGroupHolder.end())
    {
        typedef std::multimap<uint32, CreatureGroup *>::iterator multiplegroup;
        std::pair<multiplegroup, multiplegroup> range = CreatureGroupHolder.equal_range(group_id);

        for(multiplegroup i = range.first; i != range.second; ++i)
        {
            if(i->second->getInstanceID() == member.GetInstanceId())
            {
                sLog.outDebug("Group found: %u, inserting creature GUID: %u, Group InstanceID %u", group_id, member.GetGUIDLow(), i->second->getInstanceID());
                i->second->AddMember(member);
                return;
            }
        }
    }

    sLog.outDebug("Group not found: %u. Creating new group.", group_id);
    CreatureGroup* cgroup = new CreatureGroup(group_id, member.GetInstanceId());
    cgroup->AddMember(member);
    CreatureGroupHolder.insert(std::make_pair(group_id, cgroup));
}

void CreatureGroupManager::DestroyGroup(CreatureGroup *&formation, uint64 guid)
{
    if(!formation || !guid)
        return;

    sLog.outDebug("Deleting member pointer to GUID: %u from group %u", formation->GetId(), guid);
    formation->RemoveMember(guid);

    if(formation->isEmpty())
    {
        uint32 id = formation->GetId();
        typedef std::multimap<uint32, CreatureGroup *>::iterator multiplegroup;
        std::pair<multiplegroup, multiplegroup> range = CreatureGroupHolder.equal_range(id);

        for(multiplegroup i = range.first; i != range.second; ++i)
        {
            if(i->second == formation)
            {
                sLog.outDebug("Deleting group with InstanceID %u", i->second->getInstanceID());
                CreatureGroupHolder.erase(i);
                delete formation;
            }
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
        sLog.outErrorDb(" ...an error occured while loading the table `creature_formations` ( maybe it doesn't exist ?)\n");
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
        group_member						= new FormationMember;
        group_member->leaderGUID			= fields[0].GetUInt32();
        group_member->memberGUID			= fields[1].GetUInt32();
        group_member->groupAI				= fields[4].GetUInt8();
        //If creature is group leader we may skip loading of dist/angle
        if(group_member->leaderGUID != group_member->memberGUID)
        {
            group_member->follow_dist			= fields[2].GetUInt32();
            group_member->follow_angle			= fields[3].GetUInt32();
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

void CreatureGroup::AddMember(Creature &member)
{
    sLog.outDebug("Adding unit GUID: %u.", member.GetGUIDLow());

    uint64 guid = member.GetGUID();
    //We first search creature member if exist
    if(CreatureGroupMembers.find(guid) != CreatureGroupMembers.end())
        return;
    //Check is that shit is a leader
    if(member.GetDBTableGUIDLow()==m_groupID)
    {	
        sLog.outDebug("Unit GUID: %u is formation leader. Adding group.", member.GetGUIDLow());
        m_leader = &member;
    }
    else
    {	
        sLog.outDebug("Unit GUID: %u is NOT a formation leader. Set IDLE as default movement.", member.GetGUIDLow());
        member.GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);
    }
    //Add to the club
    CreatureGroupMembers[guid] = &member;
    member.SetFormation(this);
    sLog.outDebug("Unit GUID: %u added.", member.GetGUID());
}

void CreatureGroup::RemoveMember(uint64 guid)
{
    if(CreatureGroupMembers.find(guid) != CreatureGroupMembers.end())
        CreatureGroupMembers.erase(guid);	
}

void CreatureGroup::MemberHasAttacked(Creature &member)
{
    uint8 groupAI = CreatureGroupMap[member.GetDBTableGUIDLow()]->groupAI;

    for(UNORDERED_MAP<uint64, Creature*>::iterator itr = CreatureGroupMembers.begin(); itr != CreatureGroupMembers.end(); ++itr)
    {
        sLog.outDebug("GROUP ATTACK: group instance id %u calls member instid %u", m_leader->GetInstanceId(), member.GetInstanceId());
        //sLog.outDebug("AI:%u:Group member found: %u, attacked by %s.", groupAI, itr->second->GetGUIDLow(), member.getVictim()->GetName());

        if(itr->second)
        {
            //Skip one check
            if(itr->second == &member)
                return;

            switch(groupAI)
            {
            case 0:
                return;
            case 1:
                if(&member != m_leader)
                    return;
            }	
            //Attack if everything is OK
            if(itr->second->isAlive() && itr->second->AI() && !itr->second->isInCombat() && 
                !itr->second->getVictim() && member.getVictim() && itr->second->canAttack(member.getVictim()))
                itr->second->AI()->AttackStart(member.getVictim());	
        }
    }
}

void CreatureGroup::LeaderMovedInEvade()
{
    for(UNORDERED_MAP<uint64, Creature*>::iterator itr = CreatureGroupMembers.begin(); itr != CreatureGroupMembers.end(); ++itr)
    {
        if(itr->second && itr->second != m_leader && itr->second->isAlive() && !itr->second->isInCombat() && !itr->second->getVictim())
        {
            SetMemberDestination(itr->second);		
            sLog.outDebug("GROUP MOVE IN EVADE: Set destination for member GUID %u", itr->second->GetGUIDLow());
        }
    }
}

void CreatureGroup::FormDismiss(bool dismiss)
{
    for(UNORDERED_MAP<uint64, Creature*>::iterator itr = CreatureGroupMembers.begin(); itr != CreatureGroupMembers.end(); ++itr)
    {
        if(itr->second && itr->second != m_leader && itr->second->isAlive())
        {
            dismiss ? itr->second->GetMotionMaster()->Initialize() : itr->second->GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);
            sLog.outDebug("Set %s movement for member GUID: %u", dismiss ? "default" : "idle", itr->second->GetGUIDLow());
        }
    }
    m_Formed = !dismiss;
}

void CreatureGroup::SetMemberDestination(Creature *member)
{
    if(!member || !m_leader || !member->isAlive() || member->isInCombat() || member->getVictim())
        return;

    sLog.outDebug("GROUP MOVE IN EVADE: leader instid %u set destination of member instid %u", m_leader->GetInstanceId(), member->GetInstanceId());

    float x,y,z;
    uint32 lowguid = member->GetDBTableGUIDLow();

    UNORDERED_MAP<uint32, FormationMember*>::iterator itr2 = CreatureGroupMap.find(lowguid);

    if(itr2 != CreatureGroupMap.end() && m_leader->GetMotionMaster()->GetDestination(x,y,z))
    {	
        float dist, angle, pathangle;

        angle		= itr2->second->follow_angle;	
        dist		= itr2->second->follow_dist;	
        pathangle	= atan2(m_leader->GetPositionY()-y, m_leader->GetPositionX()-x);

        x = x+cos(angle+pathangle)*dist;
        y = y+sin(angle+pathangle)*dist;

        if(member->GetDistance(m_leader) < dist+MAX_DESYNC)
            member->SetUnitMovementFlags(m_leader->GetUnitMovementFlags());
        else
            member->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

        member->GetMotionMaster()->Clear();
        member->GetMotionMaster()->MovePoint(0, x, y, z);
        member->SetHomePosition(x, y, z, pathangle);
    }
}
