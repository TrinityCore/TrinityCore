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

#ifndef _FORMATIONS_H
#define _FORMATIONS_H

#include "Define.h"
#include "ObjectGuid.h"
#include <unordered_map>
#include <map>

enum GroupAIFlags
{
    FLAG_AGGRO_NONE            = 0,                                                         // No creature group behavior
    FLAG_MEMBERS_ASSIST_LEADER = 0x00000001,                                                // The member aggroes if the leader aggroes
    FLAG_LEADER_ASSISTS_MEMBER = 0x00000002,                                                // The leader aggroes if the member aggroes
    FLAG_MEMBERS_ASSIST_MEMBER = (FLAG_MEMBERS_ASSIST_LEADER | FLAG_LEADER_ASSISTS_MEMBER), // every member will assist if any member is attacked
    FLAG_IDLE_IN_FORMATION     = 0x00000200,                                                // The member will follow the leader when pathing idly
};

class Creature;
class CreatureGroup;
class Unit;
struct Position;

struct FormationInfo
{
    ObjectGuid::LowType leaderGUID;
    float follow_dist;
    float follow_angle;
    uint32 groupAI;
    uint32 point_1;
    uint32 point_2;
};

typedef std::unordered_map<ObjectGuid::LowType/*memberDBGUID*/, FormationInfo*>   CreatureGroupInfoType;

class TC_GAME_API FormationMgr
{
    private:
        FormationMgr() { }
        ~FormationMgr();

    public:
        static FormationMgr* instance();

        void AddCreatureToGroup(ObjectGuid::LowType leaderGuid, Creature* creature);
        void RemoveCreatureFromGroup(CreatureGroup* group, Creature* creature);
        void LoadCreatureFormations();
        CreatureGroupInfoType CreatureGroupMap;
};

class TC_GAME_API CreatureGroup
{
    private:
        Creature* m_leader; //Important do not forget sometimes to work with pointers instead synonims :D:D
        typedef std::map<Creature*, FormationInfo*>  CreatureGroupMemberType;
        CreatureGroupMemberType m_members;

        ObjectGuid::LowType m_groupID;
        bool m_Formed;

    public:
        //Group cannot be created empty
        explicit CreatureGroup(ObjectGuid::LowType id) : m_leader(nullptr), m_groupID(id), m_Formed(false) { }
        ~CreatureGroup() { }

        Creature* getLeader() const { return m_leader; }
        ObjectGuid::LowType GetId() const { return m_groupID; }
        bool isEmpty() const { return m_members.empty(); }
        bool isFormed() const { return m_Formed; }
        bool IsLeader(Creature const* creature) const { return m_leader == creature; }

        void AddMember(Creature* member);
        void RemoveMember(Creature* member);
        void FormationReset(bool dismiss);

        void LeaderMoveTo(Position const& destination, uint32 id = 0, uint32 moveType = 0, bool orientation = false);
        void MemberEngagingTarget(Creature* member, Unit* target);
        bool CanLeaderStartMoving() const;
};

#define sFormationMgr FormationMgr::instance()

#endif
