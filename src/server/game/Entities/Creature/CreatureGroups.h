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
    ObjectGuid::LowType LeaderSpawnId;
    float FollowDist;
    float FollowAngle;
    uint32 GroupAI;
    uint32 LeaderWaypointIDs[2];
};

class TC_GAME_API FormationMgr
{
    private:
        FormationMgr();
        ~FormationMgr();

        std::unordered_map<ObjectGuid::LowType /*spawnID*/, FormationInfo> _creatureGroupMap;

    public:
        FormationMgr(FormationMgr const&) = delete;
        FormationMgr(FormationMgr&&) = delete;
        FormationMgr& operator=(FormationMgr const&) = delete;
        FormationMgr& operator=(FormationMgr&&) = delete;

        static FormationMgr* instance();

        static void AddCreatureToGroup(ObjectGuid::LowType leaderSpawnId, Creature* creature);
        static void RemoveCreatureFromGroup(CreatureGroup* group, Creature* member);

        void LoadCreatureFormations();
        FormationInfo* GetFormationInfo(ObjectGuid::LowType spawnId);

        void AddFormationMember(ObjectGuid::LowType spawnId, float followAng, float followDist, ObjectGuid::LowType leaderSpawnId, uint32 groupAI);
};

class TC_GAME_API CreatureGroup
{
    private:
        Creature* _leader;

        using MembersMap = std::unordered_map<Creature*, FormationInfo*>;
        MembersMap _members;

        ObjectGuid::LowType _leaderSpawnId;
        bool _formed;
        bool _engaging;

    public:
        //Group cannot be created empty
        explicit CreatureGroup(ObjectGuid::LowType leaderSpawnId);
        CreatureGroup(CreatureGroup const&) = delete;
        CreatureGroup(CreatureGroup&&) = delete;
        CreatureGroup& operator=(CreatureGroup const&) = delete;
        CreatureGroup& operator=(CreatureGroup&&) = delete;
        ~CreatureGroup();

        Creature* GetLeader() const { return _leader; }
        ObjectGuid::LowType GetLeaderSpawnId() const { return _leaderSpawnId; }
        bool IsEmpty() const { return _members.empty(); }
        bool IsFormed() const { return _formed; }
        bool IsLeader(Creature const* creature) const { return _leader == creature; }

        bool HasMember(Creature* member) const { return _members.contains(member); }
        void AddMember(Creature* member);
        void RemoveMember(Creature* member);
        void FormationReset(bool dismiss);

        void LeaderStartedMoving();
        void MemberEngagingTarget(Creature* member, Unit* target);
        bool CanLeaderStartMoving() const;

        bool HasAliveMembers() const;

        bool LeaderHasStringId(std::string_view id) const;
};

#define sFormationMgr FormationMgr::instance()

#endif
