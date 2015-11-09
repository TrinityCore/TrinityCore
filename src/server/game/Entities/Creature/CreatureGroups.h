/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _FORMATIONS_H
#define _FORMATIONS_H

#include "Define.h"
#include <unordered_map>
#include <map>

class Creature;
class CreatureGroup;

struct FormationInfo
{
    uint32 leaderGUID;
    float follow_dist;
    float follow_angle;
    uint8 groupAI;
    uint32 point_1;
    uint32 point_2;
};

typedef std::unordered_map<uint32/*memberDBGUID*/, FormationInfo*>   CreatureGroupInfoType;

class FormationMgr
{
    private:
        FormationMgr() { }
        ~FormationMgr();

    public:
        static FormationMgr* instance()
        {
            static FormationMgr instance;
            return &instance;
        }

        void AddCreatureToGroup(uint32 group_id, Creature* creature);
        void RemoveCreatureFromGroup(CreatureGroup* group, Creature* creature);
        void LoadCreatureFormations();
        CreatureGroupInfoType CreatureGroupMap;
};

class CreatureGroup
{
    private:
        Creature* m_leader; //Important do not forget sometimes to work with pointers instead synonims :D:D
        typedef std::map<Creature*, FormationInfo*>  CreatureGroupMemberType;
        CreatureGroupMemberType m_members;

        uint32 m_groupID;
        bool m_Formed;

    public:
        //Group cannot be created empty
        explicit CreatureGroup(uint32 id) : m_leader(NULL), m_groupID(id), m_Formed(false) { }
        ~CreatureGroup() { }

        Creature* getLeader() const { return m_leader; }
        uint32 GetId() const { return m_groupID; }
        bool isEmpty() const { return m_members.empty(); }
        bool isFormed() const { return m_Formed; }

        void AddMember(Creature* member);
        void RemoveMember(Creature* member);
        void FormationReset(bool dismiss);

        void LeaderMoveTo(float x, float y, float z);
        void MemberAttackStart(Creature* member, Unit* target);
};

#define sFormationMgr FormationMgr::instance()

#endif
