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

#ifndef _FORMATIONS_H
#define _FORMATIONS_H

#include <map>
#include "Creature.h"
#include "Policies/Singleton.h"

struct FormationMember
{
    float follow_dist;
    float follow_angle;
    uint32 memberGUID;
    uint32 leaderGUID;
    uint8 groupAI;
};

class CreatureGroupManager
{
    public:
        void UpdateCreatureGroup(uint32 group_id, Creature *member);
        void DestroyGroup(uint32 group_id, uint64 guid);
        void LoadCreatureFormations();
};

class CreatureGroup
{
    UNORDERED_MAP<uint64, Creature*>CreatureGroupMembers;
    Creature *m_leader; //Important do not forget sometimes to work with pointers instead synonims :D:D

    public:
        CreatureGroup() : m_leader(NULL) {}
        ~CreatureGroup(){sLog.outDebug("Destroying group");}
        void AddMember(Creature *);
        void RemoveMember(uint64 guid);
        void LeaderMovedInEvade();
        void MemberHasAttacked(Creature *);
        void SetMemberDestination(Creature *);
        bool isEmpty() {return CreatureGroupMembers.empty();}
};

typedef UNORDERED_MAP<uint32, CreatureGroup*> CreatureGroupHolderType;

extern CreatureGroupHolderType CreatureGroupHolder;
extern UNORDERED_MAP<uint32, FormationMember*> CreatureGroupMap;

#define formation_mgr Trinity::Singleton<CreatureGroupManager>::Instance()

#endif
