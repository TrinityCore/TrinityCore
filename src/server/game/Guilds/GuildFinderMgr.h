/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __TRINITY_GUILDFINDER_H
#define __TRINITY_GUILDFINDER_H

#include <ace/Singleton.h>
#include "Common.h"
#include "World.h"
#include "GuildMgr.h"

enum GuildFinderOptionsInterest
{
    INTEREST_QUESTING        = 0x01,
    INTEREST_DUNGEONS        = 0x02,
    INTEREST_RAIDS           = 0x04,
    INTEREST_PVP             = 0x08,
    INTEREST_ROLE_PLAYING    = 0x10,
    ALL_INTERESTS            = INTEREST_QUESTING | INTEREST_DUNGEONS | INTEREST_RAIDS | INTEREST_PVP | INTEREST_ROLE_PLAYING
};

enum GuildFinderOptionsAvailability
{
    AVAILABILITY_WEEKDAYS     = 0x1,
    AVAILABILITY_WEEKENDS     = 0x2,
    AVAILABILITY_ALWAYS       = AVAILABILITY_WEEKDAYS | AVAILABILITY_WEEKENDS
};

enum GuildFinderOptionsRoles
{
    GUILDFINDER_ROLE_TANK        = 0x1,
    GUILDFINDER_ROLE_HEALER      = 0x2,
    GUILDFINDER_ROLE_DPS         = 0x4,
    GUILDFINDER_ALL_ROLES        = GUILDFINDER_ROLE_TANK | GUILDFINDER_ROLE_HEALER | GUILDFINDER_ROLE_DPS
};

enum GuildFinderOptionsLevel
{
    ANY_FINDER_LEVEL       = 0x1,
    MAX_FINDER_LEVEL       = 0x2,
    ALL_GUILDFINDER_LEVELS = ANY_FINDER_LEVEL | MAX_FINDER_LEVEL
};

/// Holds all required informations about a membership request
struct MembershipRequest
{
    public:
        MembershipRequest(MembershipRequest const& settings) : _comment(settings.GetComment())
        {
            _availability = settings.GetAvailability();
            _classRoles = settings.GetClassRoles();
            _interests = settings.GetInterests();
            _guildId = settings.GetGuildId();
            _playerGUID = settings.GetPlayerGUID();
            _time = settings.GetSubmitTime();
        }

        MembershipRequest(uint32 playerGUID, uint32 guildId, uint32 availability, uint32 classRoles, uint32 interests, std::string& comment, time_t submitTime) :
            _comment(comment), _guildId(guildId), _playerGUID(playerGUID), _availability(availability),
            _classRoles(classRoles), _interests(interests), _time(submitTime)  {}

        MembershipRequest() : _guildId(0), _playerGUID(0), _availability(0), _classRoles(0),
            _interests(0), _time(time(NULL)) {}

        uint32 GetGuildId() const      { return _guildId; }
        uint32 GetPlayerGUID() const   { return _playerGUID; }
        uint8 GetAvailability() const  { return _availability; }
        uint8 GetClassRoles() const    { return _classRoles; }
        uint8 GetInterests() const     { return _interests; }
        uint8 GetClass() const         { return sWorld->GetCharacterNameData(GetPlayerGUID())->m_class; }
        uint8 GetLevel() const         { return sWorld->GetCharacterNameData(GetPlayerGUID())->m_level; }
        time_t GetSubmitTime() const   { return _time; }
        time_t GetExpiryTime() const   { return time_t(_time + 30 * 24 * 3600); } // Adding 30 days
        std::string const& GetComment() const { return _comment; }
        std::string const& GetName() const    { return sWorld->GetCharacterNameData(GetPlayerGUID())->m_name; }
    private:
        std::string _comment;

        uint32 _guildId;
        uint32 _playerGUID;

        uint8 _availability;
        uint8 _classRoles;
        uint8 _interests;

        time_t _time;
};

/// Holds all informations about a player's finder settings. _NOT_ stored in database.
struct LFGuildPlayer
{
    public:
        LFGuildPlayer()
        {
            _guid = 0;
            _roles = 0;
            _availability = 0;
            _interests = 0;
            _level = 0;
        }

        LFGuildPlayer(uint32 guid, uint8 role, uint8 availability, uint8 interests, uint8 level)
        {
            _guid = guid;
            _roles = role;
            _availability = availability;
            _interests = interests;
            _level = level;
        }

        LFGuildPlayer(uint32 guid, uint8 role, uint8 availability, uint8 interests, uint8 level, std::string& comment) : _comment(comment)
        {
            _guid = guid;
            _roles = role;
            _availability = availability;
            _interests = interests;
            _level = level;
        }

        LFGuildPlayer(LFGuildPlayer const& settings) : _comment(settings.GetComment())
        {
            _guid = settings.GetGUID();
            _roles = settings.GetClassRoles();
            _availability = settings.GetAvailability();
            _interests = settings.GetInterests();
            _level = settings.GetLevel();
        }

        uint32 GetGUID() const         { return _guid; }
        uint8 GetClassRoles() const    { return _roles; }
        uint8 GetAvailability() const  { return _availability; }
        uint8 GetInterests() const     { return _interests; }
        uint8 GetLevel() const         { return _level; }
        std::string const& GetComment() const { return _comment; }

    private:
        std::string _comment;
        uint32 _guid;
        uint8 _roles;
        uint8 _availability;
        uint8 _interests;
        uint8 _level;
};

/// Holds settings for a guild in the finder system. Saved to database.
struct LFGuildSettings : public LFGuildPlayer
{
    public:
        LFGuildSettings() : LFGuildPlayer(), _listed(false), _team(TEAM_ALLIANCE) {}

        LFGuildSettings(bool listed, TeamId team) : LFGuildPlayer(), _listed(listed), _team(team) {}

        LFGuildSettings(bool listed, TeamId team, uint32 guid, uint8 role, uint8 availability, uint8 interests, uint8 level) :
            LFGuildPlayer(guid, role, availability, interests, level), _listed(listed), _team(team) {}

        LFGuildSettings(bool listed, TeamId team, uint32 guid, uint8 role, uint8 availability, uint8 interests, uint8 level, std::string& comment) :
            LFGuildPlayer(guid, role, availability, interests, level, comment), _listed(listed), _team(team) {}

        LFGuildSettings(LFGuildSettings const& settings) :
            LFGuildPlayer(settings), _listed(settings.IsListed()), _team(settings.GetTeam()) {}


        bool IsListed() const      { return _listed; }
        void SetListed(bool state) { _listed = state; }

        TeamId GetTeam() const     { return _team; }
    private:
        bool _listed;
        TeamId _team;
};

typedef std::map<uint32 /* guildGuid */, LFGuildSettings> LFGuildStore;
typedef std::map<uint32 /* guildGuid */, std::vector<MembershipRequest> > MembershipRequestStore;

class GuildFinderMgr
{
    friend class ACE_Singleton<GuildFinderMgr, ACE_Null_Mutex>;

    private:
        GuildFinderMgr();
        ~GuildFinderMgr();

        LFGuildStore  _guildSettings;

        MembershipRequestStore _membershipRequests;

        void LoadGuildSettings();
        void LoadMembershipRequests();

    public:
        void LoadFromDB();

        /**
         * @brief Stores guild settings and begins an asynchronous database insert
         * @param guildGuid The guild's database guid.
         * @param LFGuildSettings The guild's settings storage.
         */
        void SetGuildSettings(uint32 guildGuid, LFGuildSettings const& settings);

        /**
         * @brief Returns settings for a guild.
         * @param guildGuid The guild's database guid.
         */
        LFGuildSettings GetGuildSettings(uint32 guildGuid) { return _guildSettings[guildGuid]; }

        /**
         * @brief Files a membership request to a guild
         * @param guildGuid The guild's database GUID.
         * @param MembershipRequest An object storing all data related to the request.
         */
        void AddMembershipRequest(uint32 guildGuid, MembershipRequest const& request);

        /**
         * @brief Removes all membership request from a player.
         * @param playerId The player's database guid whose application shall be deleted.
         */
        void RemoveAllMembershipRequestsFromPlayer(uint32 playerId);

        /**
         * @brief Removes a membership request to a guild.
         * @param playerId The player's database guid whose application shall be deleted.
         * @param guildId  The guild's database guid
         */
        void RemoveMembershipRequest(uint32 playerId, uint32 guildId);

        /// Wipes everything related to a guild. Used when that guild is disbanded
        void DeleteGuild(uint32 guildId);

        /**
         * @brief Returns a set of membership requests for a guild
         * @param guildGuid The guild's database guid.
         */
        std::vector<MembershipRequest> GetAllMembershipRequestsForGuild(uint32 guildGuid) { return _membershipRequests[guildGuid]; }

        /**
         * @brief Returns a list of membership requests for a player.
         * @param playerGuid The player's database guid.
         */
        std::list<MembershipRequest> GetAllMembershipRequestsForPlayer(uint32 playerGuid);

        /**
         * @brief Returns a store of guilds matching the settings provided, using bitmask operators.
         * @param settings The player's finder settings
         * @param teamId   The player's faction (TEAM_ALLIANCE or TEAM_HORDE)
         */
        LFGuildStore GetGuildsMatchingSetting(LFGuildPlayer& settings, TeamId faction);

        /// Provided a player DB guid and a guild DB guid, determines if a pending request is filed with these keys.
        bool HasRequest(uint32 playerId, uint32 guildId);

        /// Counts the amount of pending membership requests, given the player's db guid.
        uint8 CountRequestsFromPlayer(uint32 playerId);

        void SendApplicantListUpdate(Guild& guild);
        void SendMembershipRequestListUpdate(Player& player);
};

#define sGuildFinderMgr ACE_Singleton<GuildFinderMgr, ACE_Null_Mutex>::instance()

#endif // __TRINITY_GUILDFINDER_H
