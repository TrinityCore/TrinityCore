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

#ifndef TRINITYCORE_ARENATEAM_H
#define TRINITYCORE_ARENATEAM_H

#include "QueryResult.h"
#include "ObjectGuid.h"
#include <list>
#include <map>

class WorldSession;
class WorldPacket;
class Player;
class Group;

enum ArenaTeamCommandTypes
{
    ERR_ARENA_TEAM_CREATE_S                 = 0x00,
    ERR_ARENA_TEAM_INVITE_SS                = 0x01,
    ERR_ARENA_TEAM_QUIT_S                   = 0x03,
    ERR_ARENA_TEAM_FOUNDER_S                = 0x0E
};

enum ArenaTeamCommandErrors
{
    ERR_ARENA_TEAM_INTERNAL                 = 0x01,
    ERR_ALREADY_IN_ARENA_TEAM               = 0x02,
    ERR_ALREADY_IN_ARENA_TEAM_S             = 0x03,
    ERR_INVITED_TO_ARENA_TEAM               = 0x04,
    ERR_ALREADY_INVITED_TO_ARENA_TEAM_S     = 0x05,
    ERR_ARENA_TEAM_NAME_INVALID             = 0x06,
    ERR_ARENA_TEAM_NAME_EXISTS_S            = 0x07,
    ERR_ARENA_TEAM_LEADER_LEAVE_S           = 0x08,
    ERR_ARENA_TEAM_PERMISSIONS              = 0x08,
    ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM       = 0x09,
    ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM_SS    = 0x0A,
    ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S       = 0x0B,
    ERR_ARENA_TEAM_NOT_ALLIED               = 0x0C,
    ERR_ARENA_TEAM_IGNORING_YOU_S           = 0x13,
    ERR_ARENA_TEAM_TARGET_TOO_LOW_S         = 0x15,
    ERR_ARENA_TEAM_TARGET_TOO_HIGH_S        = 0x16,
    ERR_ARENA_TEAM_TOO_MANY_MEMBERS_S       = 0x17,
    ERR_ARENA_TEAM_NOT_FOUND                = 0x1B,
    ERR_ARENA_TEAMS_LOCKED                  = 0x1E
};

enum ArenaTeamEvents
{
    ERR_ARENA_TEAM_JOIN_SS                  = 3,            // player name + arena team name
    ERR_ARENA_TEAM_LEAVE_SS                 = 4,            // player name + arena team name
    ERR_ARENA_TEAM_REMOVE_SSS               = 5,            // player name + arena team name + captain name
    ERR_ARENA_TEAM_LEADER_IS_SS             = 6,            // player name + arena team name
    ERR_ARENA_TEAM_LEADER_CHANGED_SSS       = 7,            // old captain + new captain + arena team name
    ERR_ARENA_TEAM_DISBANDED_S              = 8             // captain name + arena team name
};

/*
need info how to send these ones:
ERR_ARENA_TEAM_YOU_JOIN_S - client show it automatically when accept invite
ERR_ARENA_TEAM_TARGET_TOO_LOW_S
ERR_ARENA_TEAM_TOO_MANY_MEMBERS_S
ERR_ARENA_TEAM_LEVEL_TOO_LOW_I
*/

// EnumUtils: DESCRIBE THIS
enum ArenaTeamTypes
{
    ARENA_TEAM_2v2      = 2,
    ARENA_TEAM_3v3      = 3,
    ARENA_TEAM_5v5      = 5
};

struct TC_GAME_API ArenaTeamMember
{
    ObjectGuid Guid;
    std::string Name;
    uint8 Class;
    uint16 WeekGames;
    uint16 WeekWins;
    uint16 SeasonGames;
    uint16 SeasonWins;
    uint16 PersonalRating;
    uint16 MatchMakerRating;

    void ModifyPersonalRating(Player* player, int32 mod, uint32 type);
    void ModifyMatchmakerRating(int32 mod, uint32 slot);
};

struct ArenaTeamStats
{
    uint16 Rating;
    uint16 WeekGames;
    uint16 WeekWins;
    uint16 SeasonGames;
    uint16 SeasonWins;
    uint32 Rank;
};

#define MAX_ARENA_SLOT 3                                    // 0..2 slots

class TC_GAME_API ArenaTeam
{
    public:
        ArenaTeam();
        ~ArenaTeam();

        bool Create(ObjectGuid captainGuid, uint8 type, std::string const& teamName, uint32 backgroundColor, uint8 emblemStyle, uint32 emblemColor, uint8 borderStyle, uint32 borderColor);
        void Disband(WorldSession* session);
        void Disband();

        typedef std::list<ArenaTeamMember> MemberList;

        uint32 GetId() const { return TeamId; }
        uint32 GetType() const { return Type; }
        uint8 GetSlot() const { return GetSlotByType(GetType()); }
        static uint8 GetSlotByType(uint32 type);
        ObjectGuid GetCaptain() const  { return CaptainGuid; }
        std::string const& GetName() const { return TeamName; }
        ArenaTeamStats const& GetStats() const { return Stats; }

        uint32 GetRating() const          { return Stats.Rating; }
        uint32 GetAverageMMR(Group* group) const;

        void SetCaptain(ObjectGuid guid);
        bool SetName(std::string const& name);
        bool AddMember(ObjectGuid PlayerGuid);
        void DelMember(ObjectGuid guid, bool cleanDb);

        size_t GetMembersSize() const { return Members.size(); }
        bool Empty() const { return Members.empty(); }
        MemberList::iterator m_membersBegin() { return Members.begin(); }
        MemberList::iterator m_membersEnd() { return Members.end(); }
        bool IsMember(ObjectGuid guid) const;

        ArenaTeamMember* GetMember(ObjectGuid guid);
        ArenaTeamMember* GetMember(std::string const& name);

        bool IsFighting() const;

        bool LoadArenaTeamFromDB(QueryResult arenaTeamDataResult);
        bool LoadMembersFromDB(QueryResult arenaTeamMembersResult);
        void LoadStatsFromDB(uint32 ArenaTeamId);
        void SaveToDB(bool forceMemberSave = false);

        void BroadcastPacket(WorldPacket* packet);
        void BroadcastEvent(ArenaTeamEvents event, ObjectGuid guid, uint8 strCount, std::string const& str1, std::string const& str2, std::string const& str3);
        void NotifyStatsChanged();

        void MassInviteToEvent(WorldSession* session);

        void Roster(WorldSession* session);
        void Query(WorldSession* session);
        void SendStats(WorldSession* session);
        void Inspect(WorldSession* session, ObjectGuid guid);

        uint32 GetPoints(uint32 MemberRating);
        int32 GetMatchmakerRatingMod(uint32 ownRating, uint32 opponentRating, bool won);
        int32 GetRatingMod(uint32 ownRating, uint32 opponentRating, bool won);
        float GetChanceAgainst(uint32 ownRating, uint32 opponentRating);
        int32 WonAgainst(uint32 Own_MMRating, uint32 Opponent_MMRating, int32& rating_change);
        void MemberWon(Player* player, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange);
        int32 LostAgainst(uint32 Own_MMRating, uint32 Opponent_MMRating, int32& rating_change);
        void MemberLost(Player* player, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange = -12);
        void OfflineMemberLost(ObjectGuid guid, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange = -12);

        void UpdateArenaPointsHelper(std::map<uint32, uint32> & PlayerPoints);

        bool FinishWeek(); // returns true if arena team played this week
        void FinishGame(int32 mod);

        void SetPreviousOpponents(uint32 arenaTeamId) { PreviousOpponents = arenaTeamId; }
        uint32 GetPreviousOpponents() { return PreviousOpponents; }

    protected:

        uint32 TeamId;
        uint8 Type;
        std::string TeamName;
        ObjectGuid CaptainGuid;

        uint32 BackgroundColor; // ARGB format
        uint8 EmblemStyle;      // icon id
        uint32 EmblemColor;     // ARGB format
        uint8 BorderStyle;      // border image id
        uint32 BorderColor;     // ARGB format

        MemberList Members;
        ArenaTeamStats Stats;

        uint32 PreviousOpponents;
};
#endif
