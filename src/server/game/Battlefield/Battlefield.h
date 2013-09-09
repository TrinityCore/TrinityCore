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

#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Utilities/Util.h"
#include "SharedDefines.h"
#include "ZoneScript.h"
#include "WorldPacket.h"
#include "GameObject.h"
#include "Battleground.h"
#include "ObjectAccessor.h"

enum BattlefieldTypes
{
    BATTLEFIELD_WG,                                         // Wintergrasp
    BATTLEFIELD_TB                                          // Tol Barad (cataclysm)
};

enum BattlefieldIDs
{
    BATTLEFIELD_BATTLEID_WG                      = 1        // Wintergrasp battle
};

enum BattlefieldObjectiveStates
{
    BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL = 0,
    BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE
};

enum BattlefieldSounds
{
    BF_HORDE_WINS                                = 8454,
    BF_ALLIANCE_WINS                             = 8455,
    BF_START                                     = 3439
};

enum BattlefieldTimers
{
    BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL        = 1000
};

// some class predefs
class Player;
class GameObject;
class WorldPacket;
class Creature;
class Unit;

class Battlefield;
class BfGraveyard;

typedef std::set<uint64> GuidSet;
typedef std::vector<BfGraveyard*> GraveyardVect;
typedef std::map<uint64, time_t> PlayerTimerMap;

class BfCapturePoint
{
    public:
        BfCapturePoint(Battlefield* bf);

        virtual ~BfCapturePoint() { }

        virtual void FillInitialWorldStates(WorldPacket& /*data*/) {}

        // Send world state update to all players present
        void SendUpdateWorldState(uint32 field, uint32 value);

        // Send kill notify to players in the controlling faction
        void SendObjectiveComplete(uint32 id, uint64 guid);

        // Used when player is activated/inactivated in the area
        virtual bool HandlePlayerEnter(Player* player);
        virtual GuidSet::iterator HandlePlayerLeave(Player* player);
        //virtual void HandlePlayerActivityChanged(Player* player);

        // Checks if player is in range of a capture credit marker
        bool IsInsideObjective(Player* player) const;

        // Returns true if the state of the objective has changed, in this case, the OutdoorPvP must send a world state ui update.
        virtual bool Update(uint32 diff);
        virtual void ChangeTeam(TeamId /*oldTeam*/) {}
        virtual void SendChangePhase();

        bool SetCapturePointData(GameObject* capturePoint);
        GameObject* GetCapturePointGo();
        uint32 GetCapturePointEntry(){ return m_capturePointEntry; }

        TeamId GetTeamId() { return m_team; }
    protected:
        bool DelCapturePoint();

        // active Players in the area of the objective, 0 - alliance, 1 - horde
        GuidSet m_activePlayers[2];

        // Total shift needed to capture the objective
        float m_maxValue;
        float m_minValue;

        // Maximum speed of capture
        float m_maxSpeed;

        // The status of the objective
        float m_value;
        TeamId m_team;

        // Objective states
        BattlefieldObjectiveStates m_OldState;
        BattlefieldObjectiveStates m_State;

        // Neutral value on capture bar
        uint32 m_neutralValuePct;

        // Pointer to the Battlefield this objective belongs to
        Battlefield* m_Bf;

        // Capture point entry
        uint32 m_capturePointEntry;

        // Gameobject related to that capture point
        uint64 m_capturePointGUID;
};

class BfGraveyard
{
    public:
        BfGraveyard(Battlefield* Bf);

        // Method to changing who controls the graveyard
        void GiveControlTo(TeamId team);
        TeamId GetControlTeamId() const { return m_ControlTeam; }

        // Find the nearest graveyard to a player
        float GetDistance(Player* player);

        // Initialize the graveyard
        void Initialize(TeamId startcontrol, uint32 gy);

        // Set spirit service for the graveyard
        void SetSpirit(Creature* spirit, TeamId team);

        // Add a player to the graveyard
        void AddPlayer(uint64 player_guid);

        // Remove a player from the graveyard
        void RemovePlayer(uint64 player_guid);

        // Resurrect players
        void Resurrect();

        // Move players waiting to that graveyard on the nearest one
        void RelocateDeadPlayers();

        // Check if this graveyard has a spirit guide
        bool HasNpc(uint64 guid);

        // Check if a player is in this graveyard's ressurect queue
        bool HasPlayer(uint64 guid) { return m_ResurrectQueue.find(guid) != m_ResurrectQueue.end(); }

        // Get the graveyard's ID.
        uint32 GetGraveyardId() const { return m_GraveyardId; }

    protected:
        TeamId m_ControlTeam;
        uint32 m_GraveyardId;
        uint64 m_SpiritGuide[2];
        GuidSet m_ResurrectQueue;
        Battlefield* m_Bf;
};

class Battlefield : public ZoneScript
{
    friend class BattlefieldMgr;

    public:
        /// Constructor
        Battlefield();
        /// Destructor
        virtual ~Battlefield();

        /// typedef of map witch store capturepoint and the associate gameobject entry
        typedef std::map<uint32 /*lowguid */, BfCapturePoint*> BfCapturePointMap;

        /// Call this to init the Battlefield
        virtual bool SetupBattlefield() { return true; }

        /// Update data of a worldstate to all players present in zone
        void SendUpdateWorldState(uint32 field, uint32 value);

        /**
         * \brief Called every time for update bf data and time
         * - Update timer for start/end battle
         * - Invite player in zone to queue m_StartGroupingTimer minutes before start
         * - Kick Afk players
         * \param diff : time ellapsed since last call (in ms)
         */
        virtual bool Update(uint32 diff);

        /// Invite all players in zone to join the queue, called x minutes before battle start in Update()
        void InvitePlayersInZoneToQueue();
        /// Invite all players in queue to join battle on battle start
        void InvitePlayersInQueueToWar();
        /// Invite all players in zone to join battle on battle start
        void InvitePlayersInZoneToWar();

        /// Called when a Unit is kill in battlefield zone
        virtual void HandleKill(Player* /*killer*/, Unit* /*killed*/) {};

        uint32 GetTypeId() { return m_TypeId; }
        uint32 GetZoneId() { return m_ZoneId; }
        uint64 GetGUID()   { return m_Guid;   }

        void TeamApplyBuff(TeamId team, uint32 spellId, uint32 spellId2 = 0);

        /// Return true if battle is start, false if battle is not started
        bool IsWarTime() { return m_isActive; }

        /// Enable or Disable battlefield
        void ToggleBattlefield(bool enable) { m_IsEnabled = enable; }
        /// Return if battlefield is enable
        bool IsEnabled() { return m_IsEnabled; }

        /**
         * \brief Kick player from battlefield and teleport him to kick-point location
         * \param guid : guid of player who must be kick
         */
        void KickPlayerFromBattlefield(uint64 guid);

        /// Called when player (player) enter in zone
        void HandlePlayerEnterZone(Player* player, uint32 zone);
        /// Called when player (player) leave the zone
        void HandlePlayerLeaveZone(Player* player, uint32 zone);

        // All-purpose data storage 64 bit
        virtual uint64 GetData64(uint32 dataId) const { return m_Data64[dataId]; }
        virtual void SetData64(uint32 dataId, uint64 value) { m_Data64[dataId] = value; }

        // All-purpose data storage 32 bit
        virtual uint32 GetData(uint32 dataId) const { return m_Data32[dataId]; }
        virtual void SetData(uint32 dataId, uint32 value) { m_Data32[dataId] = value; }
        virtual void UpdateData(uint32 index, int32 pad) { m_Data32[index] += pad; }

        // Battlefield - generic methods
        TeamId GetDefenderTeam() { return m_DefenderTeam; }
        TeamId GetAttackerTeam() { return TeamId(1 - m_DefenderTeam); }
        TeamId GetOtherTeam(TeamId team) { return (team == TEAM_HORDE ? TEAM_ALLIANCE : TEAM_HORDE); }
        void SetDefenderTeam(TeamId team) { m_DefenderTeam = team; }

        // Group methods
        /**
         * \brief Find a not full battlefield group, if there is no, create one
         * \param TeamId : Id of player team for who we search a group (player->GetTeamId())
         */
        Group* GetFreeBfRaid(TeamId TeamId);
        /// Return battlefield group where player is.
        Group* GetGroupPlayer(uint64 guid, TeamId TeamId);
        /// Force player to join a battlefield group
        bool AddOrSetPlayerToCorrectBfGroup(Player* player);

        // Graveyard methods
        // Find which graveyard the player must be teleported to to be resurrected by spiritguide
        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player);

        virtual void AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid);
        void RemovePlayerFromResurrectQueue(uint64 player_guid);
        void SetGraveyardNumber(uint32 number) { m_GraveyardList.resize(number); }
        BfGraveyard* GetGraveyardById(uint32 id) const;

        // Misc methods
        Creature* SpawnCreature(uint32 entry, float x, float y, float z, float o, TeamId team);
        Creature* SpawnCreature(uint32 entry, const Position& pos, TeamId team);
        GameObject* SpawnGameObject(uint32 entry, float x, float y, float z, float o);

        Creature* GetCreature(uint64 GUID);
        GameObject* GetGameObject(uint64 GUID);

        // Script-methods

        /// Called on start
        virtual void OnBattleStart() { }
        /// Called at the end of battle
        virtual void OnBattleEnd(bool /*endByTimer*/) { }
        /// Called x minutes before battle start when player in zone are invite to join queue
        virtual void OnStartGrouping() { }
        /// Called when a player accept to join the battle
        virtual void OnPlayerJoinWar(Player* /*player*/) { }
        /// Called when a player leave the battle
        virtual void OnPlayerLeaveWar(Player* /*player*/) { }
        /// Called when a player leave battlefield zone
        virtual void OnPlayerLeaveZone(Player* /*player*/) { }
        /// Called when a player enter in battlefield zone
        virtual void OnPlayerEnterZone(Player* /*player*/) { }

        WorldPacket BuildWarningAnnPacket(std::string const& msg);
        void SendWarningToAllInZone(uint32 entry);
        //void SendWarningToAllInWar(int32 entry, ...); -- UNUSED
        void SendWarningToPlayer(Player* player, uint32 entry);

        void PlayerAcceptInviteToQueue(Player* player);
        void PlayerAcceptInviteToWar(Player* player);
        uint32 GetBattleId() { return m_BattleId; }
        void AskToLeaveQueue(Player* player);

        virtual void DoCompleteOrIncrementAchievement(uint32 /*achievement*/, Player* /*player*/, uint8 /*incrementNumber = 1*/) { }

        /// Send all worldstate data to all player in zone.
        virtual void SendInitWorldStatesToAll() = 0;
        virtual void FillInitialWorldStates(WorldPacket& /*data*/) = 0;

        /// Return if we can use mount in battlefield
        bool CanFlyIn() { return !m_isActive; }

        void SendAreaSpiritHealerQueryOpcode(Player* player, uint64 guid);

        void StartBattle();
        void EndBattle(bool endByTimer);

        void HideNpc(Creature* creature);
        void ShowNpc(Creature* creature, bool aggressive);

        GraveyardVect GetGraveyardVector() { return m_GraveyardList; }

        uint32 GetTimer() { return m_Timer; }
        void SetTimer(uint32 timer) { m_Timer = timer; }

        void DoPlaySoundToAll(uint32 SoundID);

        void InvitePlayerToQueue(Player* player);
        void InvitePlayerToWar(Player* player);

        void InitStalker(uint32 entry, float x, float y, float z, float o);

    protected:
        uint64 m_Guid;

        uint64 StalkerGuid;
        uint32 m_Timer;                                         // Global timer for event
        bool m_IsEnabled;
        bool m_isActive;
        TeamId m_DefenderTeam;

        // Map of the objectives belonging to this OutdoorPvP
        BfCapturePointMap m_capturePoints;

        // Players info maps
        GuidSet m_players[BG_TEAMS_COUNT];                      // Players in zone
        GuidSet m_PlayersInQueue[BG_TEAMS_COUNT];               // Players in the queue
        GuidSet m_PlayersInWar[BG_TEAMS_COUNT];                 // Players in WG combat
        PlayerTimerMap m_InvitedPlayers[BG_TEAMS_COUNT];
        PlayerTimerMap m_PlayersWillBeKick[BG_TEAMS_COUNT];

        // Variables that must exist for each battlefield
        uint32 m_TypeId;                                        // See enum BattlefieldTypes
        uint32 m_BattleId;                                      // BattleID (for packet)
        uint32 m_ZoneId;                                        // ZoneID of Wintergrasp = 4197
        uint32 m_MapId;                                         // MapId where is Battlefield
        Map* m_Map;
        uint32 m_MaxPlayer;                                     // Maximum number of player that participated to Battlefield
        uint32 m_MinPlayer;                                     // Minimum number of player for Battlefield start
        uint32 m_MinLevel;                                      // Required level to participate at Battlefield
        uint32 m_BattleTime;                                    // Length of a battle
        uint32 m_NoWarBattleTime;                               // Time between two battles
        uint32 m_RestartAfterCrash;                             // Delay to restart Wintergrasp if the server crashed during a running battle.
        uint32 m_TimeForAcceptInvite;
        uint32 m_uiKickDontAcceptTimer;
        WorldLocation KickPosition;                             // Position where players are teleported if they switch to afk during the battle or if they don't accept invitation

        uint32 m_uiKickAfkPlayersTimer;                         // Timer for check Afk in war

        // Graveyard variables
        GraveyardVect m_GraveyardList;                          // Vector witch contain the different GY of the battle
        uint32 m_LastResurectTimer;                             // Timer for resurect player every 30 sec

        uint32 m_StartGroupingTimer;                            // Timer for invite players in area 15 minute before start battle
        bool m_StartGrouping;                                   // bool for know if all players in area has been invited

        GuidSet m_Groups[BG_TEAMS_COUNT];                       // Contain different raid group

        std::vector<uint64> m_Data64;
        std::vector<uint32> m_Data32;

        void KickAfkPlayers();

        // use for switch off all worldstate for client
        virtual void SendRemoveWorldStates(Player* /*player*/) {}

        // use for send a packet for all player list
        void BroadcastPacketToZone(WorldPacket& data) const;
        void BroadcastPacketToQueue(WorldPacket& data) const;
        void BroadcastPacketToWar(WorldPacket& data) const;

        // CapturePoint system
        void AddCapturePoint(BfCapturePoint* cp) { m_capturePoints[cp->GetCapturePointEntry()] = cp; }

        BfCapturePoint* GetCapturePoint(uint32 lowguid) const
        {
            Battlefield::BfCapturePointMap::const_iterator itr = m_capturePoints.find(lowguid);
            if (itr != m_capturePoints.end())
                return itr->second;
            return NULL;
        }

        void RegisterZone(uint32 zoneid);
        bool HasPlayer(Player* player) const;
        void TeamCastSpell(TeamId team, int32 spellId);
};

#endif
