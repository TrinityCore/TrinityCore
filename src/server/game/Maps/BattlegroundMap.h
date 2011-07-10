/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_BATTLEGROUND_MAP_H
#define TRINITY_BATTLEGROUND_MAP_H

enum BattlegroundTeamId
{
    BG_TEAM_ALLIANCE        = 0,
    BG_TEAM_HORDE           = 1,
    BG_TEAMS_COUNT          = 2
};

#include "BattlegroundTemplate.h"
#include "MapInstanced.h"

enum BattlegroundStartTimeIntervals
{
    BG_START_DELAY_2M               = 120000,               // ms (2 minutes)
    BG_START_DELAY_1M               = 60000,                // ms (1 minute)
    BG_START_DELAY_30S              = 30000,                // ms (30 seconds)
    BG_START_DELAY_15S              = 15000,                // ms (15 seconds) Used only in arena
    BG_START_DELAY_NONE             = 0,                    // ms
};

enum BattlegroundStartingEventsIds
{
    BG_STARTING_EVENT_FIRST,
    BG_STARTING_EVENT_SECOND,
    BG_STARTING_EVENT_THIRD,
    BG_STARTING_EVENT_FOURTH,
    BG_STARTING_EVENT_COUNT
};

enum BattlegroundStatus
{
    STATUS_NONE,                                // first status, should mean bg is not instance
    STATUS_WAIT_QUEUE,                                // means bg is empty and waiting for queue
    STATUS_WAIT_JOIN,                                // this means, that BG has already started and it is waiting for more players
    STATUS_IN_PROGRESS,                                // means bg is running
    STATUS_WAIT_LEAVE                                 // means some faction has won BG and it is ending
};

enum BattlegroundWinner
{
    WINNER_HORDE            = 0,
    WINNER_ALLIANCE         = 1,
    WINNER_NONE             = 2
};

enum BattlegroundTimeIntervals
{
    RESURRECTION_INTERVAL           = 30000,                // ms
    INVITATION_REMIND_TIME          = 20000,                // ms
    INVITE_ACCEPT_WAIT_TIME         = 40000,                // ms
    TIME_TO_AUTOREMOVE              = 120000,               // ms
    MAX_OFFLINE_TIME                = 300,                  // secs
    RESPAWN_ONE_DAY                 = 86400,                // secs
    RESPAWN_IMMEDIATELY             = 0,                    // secs
    BUFF_RESPAWN_TIME               = 180,                  // secs
};

// handle the queue types and bg types separately to enable joining queue for different sized arenas at the same time
enum BattlegroundQueueTypeId
{
    BATTLEGROUND_QUEUE_NONE,
    BATTLEGROUND_QUEUE_AV,
    BATTLEGROUND_QUEUE_WS,
    BATTLEGROUND_QUEUE_AB,
    BATTLEGROUND_QUEUE_EY,
    BATTLEGROUND_QUEUE_SA,
    BATTLEGROUND_QUEUE_IC,
    BATTLEGROUND_QUEUE_RB,
    BATTLEGROUND_QUEUE_2v2,
    BATTLEGROUND_QUEUE_3v3,
    BATTLEGROUND_QUEUE_5v5,
    MAX_BATTLEGROUND_QUEUE_TYPES
};

enum ScoreType
{
    SCORE_KILLING_BLOWS         = 1,
    SCORE_DEATHS                = 2,
    SCORE_HONORABLE_KILLS       = 3,
    SCORE_BONUS_HONOR           = 4,
    //EY, but in MSG_PVP_LOG_DATA opcode!
    SCORE_DAMAGE_DONE           = 5,
    SCORE_HEALING_DONE          = 6,
    //WS
    SCORE_FLAG_CAPTURES         = 7,
    SCORE_FLAG_RETURNS          = 8,
    //AB and IC
    SCORE_BASES_ASSAULTED       = 9,
    SCORE_BASES_DEFENDED        = 10,
    //AV
    SCORE_GRAVEYARDS_ASSAULTED  = 11,
    SCORE_GRAVEYARDS_DEFENDED   = 12,
    SCORE_TOWERS_ASSAULTED      = 13,
    SCORE_TOWERS_DEFENDED       = 14,
    SCORE_MINES_CAPTURED        = 15,
    SCORE_LEADERS_KILLED        = 16,
    SCORE_SECONDARY_OBJECTIVES  = 17,
    //SOTA
    SCORE_DESTROYED_DEMOLISHER  = 18,
    SCORE_DESTROYED_WALL        = 19,
};

enum BGHonorMode
{
    BG_NORMAL = 0,
    BG_HOLIDAY,
    BG_HONOR_MODE_NUM
};

enum BattlegroundBuffObjects
{
    BG_OBJECTID_SPEEDBUFF_ENTRY     = 179871,
    BG_OBJECTID_REGENBUFF_ENTRY     = 179904,
    BG_OBJECTID_BERSERKERBUFF_ENTRY = 179905
};

const uint32 BuffEntries[3] =
{
    BG_OBJECTID_SPEEDBUFF_ENTRY, 
    BG_OBJECTID_REGENBUFF_ENTRY, 
    BG_OBJECTID_BERSERKERBUFF_ENTRY
};

enum BattlegroundSpells
{
    SPELL_WAITING_FOR_RESURRECT     = 2584,                 // Waiting to Resurrect
    SPELL_SPIRIT_HEAL_CHANNEL       = 22011,                // Spirit Heal Channel
    SPELL_SPIRIT_HEAL               = 22012,                // Spirit Heal
    SPELL_RESURRECTION_VISUAL       = 24171,                // Resurrection Impact Visual
    SPELL_ARENA_PREPARATION         = 32727,                // use this one, 32728 not correct
    SPELL_ALLIANCE_GOLD_FLAG        = 32724,
    SPELL_ALLIANCE_GREEN_FLAG       = 32725,
    SPELL_HORDE_GOLD_FLAG           = 35774,
    SPELL_HORDE_GREEN_FLAG          = 35775,
    SPELL_PREPARATION               = 44521,                // Preparation
    SPELL_SPIRIT_HEAL_MANA          = 44535,                // Spirit Heal
    SPELL_RECENTLY_DROPPED_FLAG     = 42792,                // Recently Dropped Flag
    SPELL_AURA_PLAYER_INACTIVE      = 43681,                // Inactive
    SPELL_HONORABLE_DEFENDER_25Y    = 68652,                // +50% honor when standing at a capture point that you control, 25yards radius (added in 3.2)
    SPELL_HONORABLE_DEFENDER_60Y    = 66157                 // +50% honor when standing at a capture point that you control, 60yards radius (added in 3.2), probably for 40+ player battlegrounds
};


// Todo: IN MGR?
enum ArenaType
{
    ARENA_TYPE_2v2          = 2,
    ARENA_TYPE_3v3          = 3,
    ARENA_TYPE_5v5          = 5
};

class BattlegroundScore;

class BattlegroundMap : public MapInstanced
{
    friend class WorldSession;
    friend class MapManager;

    protected:
        // Typedefs here
        typedef std::map<uint32, BattlegroundScore*> BattlegroundScoreMap;

    protected:
        /* Template related methods */
        uint32 GetMaxPlayers() const { return _template.MaxPlayersPerTeam * 2; }
        uint32 GetMinPlayers() const { return _template.MinPlayersPerTeam * 2; }
        uint32 GetMinLevel() const { return _template.MinLevel; }
        uint32 GetMaxLevel() const { return _template.MaxLevel; }

        uint32 GetStatus() const { return Status; }

        uint32 GetBonusHonorFromKill(uint32 kills) const;

    protected:
        /* Methods called by upper level code */
        BattlegroundMap(uint32 id, time_t expiry, uint32 instanceId, BattlegroundTemplate* bgtemplate);
        virtual ~BattlegroundMap();

        bool Add(Player* player);
        void Remove(Player*, bool);

        void Update(uint32 const& diff);

        // processing methods
        virtual void ProcessPreparation(uint32 const& diff);
        virtual void ProcessInProgress(uint32 const& diff);
        virtual void ProcessEnded(uint32 const& diff);

        bool CanEnter(Player* player);
        void SetUnload();

        // Packet builders
        virtual void BuildPVPLogDataPacket(WorldPacket& data);

        // Achievement related methods
        void StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry);

        // Team event related methods
        void RewardHonorToTeam(uint32 amount, BattlegroundTeamId team);
        void RewardReputationToTeam(uint32 targetFaction, uint32 amount, BattlegroundTeamId team);
        void CastSpellOnTeam(uint32 spell, BattlegroundTeamId team);
        void RemoveAuraOnTeam(uint32 spell, BattlegroundTeamId team);

        /* Methods and attributes accessed by subclasses */
        // Initialization
        virtual void InitializeObjects() {}                 // Resize ObjectGUIDsByType and spawn objects
        virtual void InitializeTextIds() {};                // Initializes text IDs that are used in the battleground at any possible phase.
        virtual void InitializePreparationDelayTimes() {};  // Initializes preparation delay timers.
        virtual void FillInitialWorldStates(WorldPacket& data) {};
        
        virtual void InstallBattleground() {};  // Calls all overridable InitializeXX() methods and other variables
        virtual void StartBattleground() {};    // Initializes EndTimer and opens gameobjects
        virtual void EndBattleground(BattlegroundWinner winner) {};  // Handles out rewards etc
        virtual void DestroyBattleground() {};  // Contains battleground specific cleanup method calls.
        uint32 GetWinningTeam() const { return _winner; }  // Returns winning team (for packet)

        virtual void UpdatePlayerScore(Player* source, uint32 type, uint32 value, bool addHonor = true);
        void UpdateWorldState(uint32 type, uint32 value);
        void SendMessageToAll(int32 entry, ChatMsg type, Unit* source = NULL, Language language = LANG_UNIVERSAL);
        void SendMessageToAll(char const* string, ChatMsg type, Unit* source = NULL, Language language = LANG_UNIVERSAL);
        void PlaySoundToAll(uint32 soundId);

        char const* ParseStrings(int32 mainEntry, int32 args1, int32 args2 = 0);
        char const* ParseStrings(int32 mainEntry, char const* args1, char const* args2 = NULL);
        char const* ParseStrings(int32 mainEntry, int32 args1, const char* args2);
        char const* ParseStrings(char* const mainString, int32 args);

        // Entity management - GameObject
        GameObject* AddGameObject(uint32 type, uint32 entry, float x, float y, float z, float o, float r0, float r1, float r2, float r3, uint32 respawnTime = 0);   // Adds GO's to the map but doesn't necessarily spawn them
        GameObject* AddGameObject(uint32 type, uint32 entry, Position* pos, float r0, float r1, float r2, float r3, uint32 respawnTime = 0);   // Adds GO's to the map but doesn't necessarily spawn them
        GameObject* GetGameObject(uint32 type);
        void SpawnGameObject(uint32 type, uint32 respawntime);  // Spawns an already added gameobject
        bool DeleteGameObject(uint32 type); // Deletes an object with specified type designation 
        void DoorOpen(uint32 type);
        void DoorClose(uint32 type);

        // Entity management - Creature
        void AddSpiritGuide(uint32 type, float x, float y, float z, float o, uint32 team);
        Creature* AddCreature(uint32 entry, uint32 type, uint32 teamval, float x, float y, float z, float o, uint32 respawntime = 0); // Adds and spawns creatures to map
        Creature* AddCreature(uint32 entry, uint32 type, uint32 teamval, Position* pos, uint32 respawntime = 0); // Adds and spawns creatures to map
        Creature* GetCreature(uint32 type);
        bool DeleteCreature(uint32 type);

        int32 GetObjectType(uint64 const& guid) const;
        std::vector<uint64> ObjectGUIDsByType;      // Stores object GUIDs per enum-defined arbitrary type

        // Hooks called after Map methods
        virtual void OnPlayerJoin(Player* player);  // Initialize battleground specific variables.
        virtual void OnPlayerExit(Player* player);  // Remove battleground specific auras etc.

        // Misc. hooks
        virtual void OnPlayerKill(Player* victim, Player* killer) {};
        virtual void OnUnitKill(Creature* victim, Player* killer) {};
        virtual void OnPlayerResurrect(Player* player) {};
        virtual void OnTimeoutReached() { EndBattleground(WINNER_NONE); };        // Must be overwritten for subclasses with bg-specific rules on who wins on a draw
        
        // Status and overridable timers
        BattlegroundStatus Status;
        uint8 PreparationPhase;
        uint32 PreparationTimer;   // Time between map creation and start of the battleground
        uint32 PrematureCountdownTimer; // If teams are imbalanced the battleground will close after a certain delay
        uint32 PostEndTimer;       // Time between battleground ending and closing of the map

        uint32 EndTimer;        // Battleground specific time limit. Must be overwritten in subclass.
        uint32 PreparationPhaseTextIds[BG_STARTING_EVENT_COUNT];   // Must be initialized for each battleground
        uint32 PreparationDelayTimers[BG_STARTING_EVENT_COUNT];  //

        BattlegroundScoreMap PlayerScores;                  // Player scores
        int32 TeamScores[BG_TEAMS_COUNT];                   // Team scores - unused for arena's
        uint16 ParticipantCount[BG_TEAMS_COUNT];            // Players actually in the battleground

        std::map<uint64, std::vector<uint64>>  ReviveQueue; // Spirit Guide guid + Player list GUIDS
    private:
        // Private initializers, non overridable 
        void InitVisibilityDistance();  // Overwritten from class Map
        void InitializePreparationDelayTimer();

        void RemoveAllPlayers();

        // Packet senders
        void SendPacketToAll(WorldPacket* data);
        void SendPacketToTeam(WorldPacket* data, uint32 team, Player* exclude);
        void SendPlayerJoinedPacket(Player* player);
        void SendPlayerLeftPacket(Player* player);
       
        bool AreTeamsInBalance() const;
    
        BattlegroundTemplate _template;
        uint32 _instanceId;

        uint16 _invitedCount[BG_TEAMS_COUNT];       // Players invited to join the battleground
        BattlegroundWinner _winner;
};

#endif