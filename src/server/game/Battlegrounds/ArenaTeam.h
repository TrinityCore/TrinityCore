/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITYCORE_ARENATEAM_H
#define TRINITYCORE_ARENATEAM_H

#include "QueryResult.h"
#include "Player.h"
#include "ObjectMgr.h"

class WorldSession;

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

enum ArenaTeamTypes
{
    ARENA_TEAM_2v2      = 2,
    ARENA_TEAM_3v3      = 3,
    ARENA_TEAM_5v5      = 5
};

struct ArenaTeamMember
{
    uint64 Guid;
    std::string Name;
    uint8 Class;
    uint16 WeekGames;
    uint16 WeekWins;
    uint16 SeasonGames;
    uint16 SeasonWins;
    uint16 PersonalRating;
    uint16 MatchMakerRating;

    void ModifyPersonalRating(Player* plr, int32 mod, uint32 slot);
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

class ArenaTeam
{
    public:
        ArenaTeam();
        ~ArenaTeam();

        bool Create(uint32 captainGuid, uint8 type, std::string teamName, uint32 backgroundColor, uint8 emblemStyle, uint32 emblemColor, uint8 borderStyle, uint32 borderColor);
        void Disband(WorldSession* session);

        typedef std::list<ArenaTeamMember> MemberList;

        uint32 GetId() const              { return TeamId; }
        uint32 GetType() const            { return Type; }
        uint8  GetSlot() const            { return GetSlotByType(GetType()); }
        static uint8 GetSlotByType(uint32 type);
        uint64 GetCaptain() const  { return CaptainGuid; }
        std::string GetName() const       { return TeamName; }
        const ArenaTeamStats& GetStats() const { return Stats; }

        uint32 GetRating() const          { return Stats.Rating; }
        uint32 GetAverageMMR(Group* group) const;

        void SetCaptain(uint64 guid);
        bool AddMember(uint64 PlayerGuid);

        // Shouldn't be uint64 ed, because than can reference guid from members on Disband
        // and this method removes given record from list. So invalid reference can happen.
        void DelMember(uint64 guid, bool cleanDb);

        size_t GetMembersSize() const         { return Members.size(); }
        bool   Empty() const                  { return Members.empty(); }
        MemberList::iterator m_membersBegin() { return Members.begin(); }
        MemberList::iterator m_membersEnd()   { return Members.end(); }
        bool IsMember(uint64 guid) const;

        ArenaTeamMember* GetMember(uint64 guid);
        ArenaTeamMember* GetMember(const std::string& name);

        bool IsFighting() const;

        bool LoadArenaTeamFromDB(QueryResult arenaTeamDataResult);
        bool LoadMembersFromDB(QueryResult arenaTeamMembersResult);
        void LoadStatsFromDB(uint32 ArenaTeamId);
        void SaveToDB();

        void BroadcastPacket(WorldPacket* packet);
        void BroadcastEvent(ArenaTeamEvents event, uint64 guid, uint8 strCount, std::string str1, std::string str2, std::string str3);
        void NotifyStatsChanged();

        void Roster(WorldSession* session);
        void Query(WorldSession* session);
        void SendStats(WorldSession* session);
        void Inspect(WorldSession* session, uint64 guid);

        uint32 GetPoints(uint32 MemberRating);
        int32  GetMatchmakerRatingMod(uint32 ownRating, uint32 opponentRating, bool won);
        int32  GetRatingMod(uint32 ownRating, uint32 opponentRating, bool won);
        float  GetChanceAgainst(uint32 ownRating, uint32 opponentRating);
        int32  WonAgainst(uint32 Own_MMRating, uint32 Opponent_MMRating, int32& rating_change);
        void   MemberWon(Player* plr, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange);
        int32  LostAgainst(uint32 Own_MMRating, uint32 Opponent_MMRating, int32& rating_change);
        void   MemberLost(Player* plr, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange = -12);
        void   OfflineMemberLost(uint64 guid, uint32 againstMatchmakerRating, int32 MatchmakerRatingChange = -12);

        void UpdateArenaPointsHelper(std::map<uint32, uint32> & PlayerPoints);

        void FinishWeek();
        void FinishGame(int32 mod);

    protected:

        uint32      TeamId;
        uint8       Type;
        std::string TeamName;
        uint64      CaptainGuid;

        uint32 BackgroundColor; // ARGB format
        uint8  EmblemStyle;     // icon id
        uint32 EmblemColor;     // ARGB format
        uint8  BorderStyle;     // border image id
        uint32 BorderColor;     // ARGB format

        MemberList     Members;
        ArenaTeamStats Stats;
};
#endif

