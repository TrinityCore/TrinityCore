/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Utilities/Util.h"
#include "SharedDefines.h"
#include "ZoneScript.h"
#include "WorldPacket.h"
#include "GameObject.h"

enum BattlefieldTypes
{
    BATTLEFIELD_WG,                                         // Wintergrasp
    BATTLEFIELD_TB,                                         // Tol Barad (cataclysm)
};

enum BattlefieldIDs
{
    BATTLEFIELD_BATTLEID_WG                      = 1,       // Wintergrasp battle 
};

enum BattlefieldObjectiveStates
{
    BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL = 0,
    BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE,
    BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE,
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
class BfGraveYard;

typedef std::set < uint64 > GuidSet;
typedef std::vector < BfGraveYard * >GraveYardVect;
typedef std::map < uint64, uint32 > PlayerTimerMap;

class BfCapturePoint
{
public:
    BfCapturePoint(Battlefield * bf);

    virtual void FillInitialWorldStates(WorldPacket & /*data */ ) {}

    // send world state update to all players present
    void SendUpdateWorldState(uint32 field, uint32 value);

    // send kill notify to players in the controlling faction
    void SendObjectiveComplete(uint32 id, uint64 guid);

    // used when player is activated/inactivated in the area
    virtual bool HandlePlayerEnter(Player * plr);
    virtual void HandlePlayerLeave(Player * plr);
    //virtual void HandlePlayerActivityChanged(Player * plr);

    // checks if player is in range of a capture credit marker
    bool IsInsideObjective(Player * plr) const;

    // returns true if the state of the objective has changed, in this case, the OutdoorPvP must send a world state ui update.
    virtual bool Update(uint32 diff);
    virtual void ChangeTeam(TeamId /*oldTeam */ ) {}
    virtual void SendChangePhase();

    bool SetCapturePointData(uint32 entry, uint32 map, float x, float y, float z, float o);
    GameObject *GetCapturePointGo() { return m_capturePoint; }

    TeamId GetTeamId() {return m_team;}
protected:
    bool DelCapturePoint();

    // active players in the area of the objective, 0 - alliance, 1 - horde
    GuidSet m_activePlayers[2];

    // total shift needed to capture the objective
    float m_maxValue;
    float m_minValue;

    // maximum speed of capture
    float m_maxSpeed;

    // the status of the objective
    float m_value;
    TeamId m_team;

    // objective states
    BattlefieldObjectiveStates m_OldState;
    BattlefieldObjectiveStates m_State;

    // neutral value on capture bar
    uint32 m_neutralValuePct;

    // pointer to the Battlefield this objective belongs to
    Battlefield *m_Bf;
    uint32 m_capturePointEntry;
    GameObject *m_capturePoint;
};

class BfGraveYard
{
public:
    BfGraveYard(Battlefield *Bf);

    // method for change who control the graveyard
    void ChangeControl(TeamId team);
    TeamId GetControlTeamId() { return m_ControlTeam; }

    // use for found the nearest graveyard
    float GetDistance(Player * plr);
    void Init(uint32 horde_entry, uint32 alliance_entry, float x, float y, float z, float o, TeamId startcontrol, uint32 gy);
    void AddPlayer(uint64 player_guid);
    void RemovePlayer(uint64 player_guid);

    void Resurrect();
    void RelocateDeadPlayers();

    bool HasNpc(uint64 guid) { return (m_SpiritGuide[0]->GetGUID() == guid || m_SpiritGuide[1]->GetGUID() == guid); }
    bool HasPlayer(uint64 guid) { return m_ResurrectQueue.find(guid) != m_ResurrectQueue.end(); }
    uint32 GetGraveYardId() { return m_GraveyardId; }

protected:

    TeamId m_ControlTeam;
    uint32 m_GraveyardId;
    Creature *m_SpiritGuide[2];
    GuidSet m_ResurrectQueue;
    Battlefield *m_Bf;
};

class Battlefield:public ZoneScript
{
    friend class BattlefieldMgr;

  public:
    /// Constructor
    Battlefield();
    /// Destructor
    virtual ~Battlefield();

    /// typedef of map witch store capturepoint and the associate gameobject entry
    typedef std::map < uint32 /*lowguid */ , BfCapturePoint * >BfCapturePointMap;

    /// Call this to init the Battlefield
    virtual bool SetupBattlefield() { return true; }

    /// Generate packet which contain all worldstatedata of area
    virtual void FillInitialWorldStates(WorldPacket & /*data */ ) {}

    /// Call when a GameObject/Creature is created OR destroyed (view bool add)
    void OnGameObjectCreate(GameObject * /*go */ , bool /*add */ ) {}
    void OnCreatureCreate(Creature * /*cre */ , bool /*add */ ) {}

    /// Update data of a worldstate to all players present in zone
    void SendUpdateWorldState(uint32 field, uint32 value);

    /**
     * \brief Called every time for update bf data and time
     * -Update timer for start/end battle
     * -Invite player in zone to queue x minutes before start (x = m_StartGroupingTimer)
     * -Kick Afk players
     * \param diff : time ellapsed since last call (in ms)
     */
    virtual bool Update(uint32 diff);

    /// Invite all player in zone, to join the queue, called x minutes before battle start in Update()
    void InvitePlayerInZoneToQueue();
    /// Invite all player in queue to join battle on battle start
    void InvitePlayerInQueueToWar();
    /// Invite all player in zone to join battle on battle start
    void InvitePlayerInZoneToWar();

    /// Called when a Unit is kill in battlefield zone
    virtual void HandleKill(Player * /*killer */ , Unit * /*killed */ ) {};

    uint32 GetTypeId() { return m_TypeId; }
    uint32 GetZoneId() { return m_ZoneId; }

    void TeamApplyBuff(TeamId team, uint32 spellId, uint32 spellId2 = 0);

    /// Return true if battle is start, false if battle is not started
    bool IsWarTime() { return m_WarTime; }

    /// Enable or Disable battlefield
    void SetEnable(bool enable) { m_enable = enable; }
    /// Return if battlefield is enable
    bool GetEnable() { return m_enable; }

    /**
     * \brief Kick player from battlefield and teleport him to kick-point location
     * \param guid : guid of player who must be kick
     */
    void KickPlayerFromBf(uint64 guid);

    /// Called when player (plr) enter in zone
    void HandlePlayerEnterZone(Player * plr, uint32 zone);
    /// Called when player (plr) leave the zone
    void HandlePlayerLeaveZone(Player * plr, uint32 zone);

    // All-purpose data storage 64 bit
    virtual uint64 GetData64(uint32 DataId) { return m_Data64[DataId]; }
    virtual void SetData64(uint32 DataId, uint64 Value) { m_Data64[DataId] = Value; }

    // All-purpose data storage 32 bit
    virtual uint32 GetData(uint32 DataId) { return m_Data32[DataId]; }
    virtual void SetData(uint32 DataId, uint32 Value) { m_Data32[DataId] = Value; }

    // Battlefield - generic methods
    TeamId GetDefenderTeam() { return m_DefenderTeam; }
    TeamId GetAttackerTeam() { return TeamId(1 - m_DefenderTeam); }
    void SetDefenderTeam(TeamId team) { m_DefenderTeam = team; }

    // Group methods
    /**
     * \brief Find a not full battlefield group, if there is no, create one
     * \param TeamId : Id of player team for who we search a group (plr->GetTeamId())
     */
    Group *GetFreeBfRaid(TeamId TeamId);
    /// Return battlefield group where player is.
    Group *GetGroupPlayer(uint64 guid, TeamId TeamId);
    /// Force player to join a battlefield group
    bool AddOrSetPlayerToCorrectBfGroup(Player * plr);

    // Graveyard methods
    // Find which graveyard the player must be teleported to to be resurrected by spiritguide
    WorldSafeLocsEntry const *GetClosestGraveYard(Player * plr);

    virtual void AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid);
    void RemovePlayerFromResurrectQueue(uint64 player_guid);
    void SetGraveyardNumber(uint32 number) { m_GraveYardList.resize(number); }
    BfGraveYard *GetGraveYardById(uint32 id);

    // Misc methods
    Creature *SpawnCreature(uint32 entry, float x, float y, float z, float o, TeamId team);
    Creature *SpawnCreature(uint32 entry, Position pos, TeamId team);
    GameObject *SpawnGameObject(uint32 entry, float x, float y, float z, float o);

    // Script-methods

    /// Called on start
    virtual void OnBattleStart() {};
    /// Called at the end of battle
    virtual void OnBattleEnd(bool /*endbytimer */ ) {};
    /// Called x minutes before battle start when player in zone are invite to join queue
    virtual void OnStartGrouping() {};
    /// Called when a player accept to join the battle
    virtual void OnPlayerJoinWar(Player * /*plr */ ) {};
    /// Called when a player leave the battle
    virtual void OnPlayerLeaveWar(Player * /*plr */ ) {};
    /// Called when a player leave battlefield zone
    virtual void OnPlayerLeaveZone(Player * /*plr */ ) {};
    /// Called when a player enter in battlefield zone
    virtual void OnPlayerEnterZone(Player * /*plr */ ) {};

    WorldPacket BuildWarningAnnPacket(std::string msg);
    void SendWarningToAllInZone(uint32 entry);
    //void SendWarningToAllInWar(int32 entry, ...); -- UNUSED
    void SendWarningToPlayer(Player * plr, uint32 entry);

    void PlayerAcceptInviteToQueue(Player * plr);
    void PlayerAcceptInviteToWar(Player * plr);
    uint32 GetBattleId() { return m_BattleId; }
    void AskToLeaveQueue(Player * plr);

    virtual void DoCompleteOrIncrementAchievement(uint32 /*achievement */ , Player * /*player */ , uint8 /*incrementNumber = 1 */ ) {};

    /// Send all worldstate data to all player in zone.
    virtual void SendInitWorldStatesToAll() {};

    /// Return if we can use mount in battlefield
    bool CanFlyIn() { return !m_WarTime; }  // Used for check if we can use flying mount or not
    bool IncrementQuest(Player * player, uint32 quest, bool complete = false);
    void SendAreaSpiritHealerQueryOpcode(Player * pl, const uint64 & guid);

    void StartBattle();
    void EndBattle(bool endbytimer);

    void HideNpc(Creature * p_Creature);
    void ShowNpc(Creature * p_Creature, bool p_Aggressive);

    GraveYardVect GetGraveYardVect() { return m_GraveYardList; }

    uint32 GetTimer() { return m_Timer; }
    void SetTimer(uint32 timer) { m_Timer = timer; }

    void PlaySoundToAll(uint32 SoundID);

    void InvitePlayerToQueue(Player * plr);
    void InvitePlayerToWar(Player * plr);

    void InitStalker(uint32 entry, float x, float y, float z, float o);

protected:
    uint64 StalkerGuid;
    uint32 m_Timer;                                         // Global timer for event
    bool m_enable;
    bool m_WarTime;
    TeamId m_DefenderTeam;

    // the map of the objectives belonging to this outdoorpvp
    BfCapturePointMap m_capturePoints;

    // the set of player
    GuidSet m_players[BG_TEAMS_COUNT];                      // Players in zone
    GuidSet m_PlayersInQueue[BG_TEAMS_COUNT];               // Players in the queue
    GuidSet m_PlayersInWar[BG_TEAMS_COUNT];                 // Players in WG combat
    PlayerTimerMap m_InvitedPlayers[BG_TEAMS_COUNT];
    PlayerTimerMap m_PlayersWillBeKick[BG_TEAMS_COUNT];

    //Variables that must exist for each battlefield 
    uint32 m_TypeId;                                        // See enum BattlefieldTypes
    uint32 m_BattleId;                                      // BattleID (for packet)
    uint32 m_ZoneId;                                        // ZoneID of Wintergrasp = 4197
    uint32 m_MapId;                                         // MapId where is Battlefield
    uint32 m_MaxPlayer;                                     // Maximum number of player that participated to Battlefield
    uint32 m_MinPlayer;                                     // Minimum number of player for Battlefield start
    uint32 m_MinLevel;                                      // Required level to participate at Battlefield
    uint32 m_BattleTime;                                    // Length of a battle
    uint32 m_NoWarBattleTime;                               // Time between two battles
    uint32 m_RestartAfterCrash;                             // Delay to restart Wintergrasp if the server crashed during a running battle.
    uint32 m_TimeForAcceptInvite;
    uint32 m_uiKickDontAcceptTimer;
    WorldLocation KickPosition;                             // Position where player is teleport if they switch to afk during battle or if they dont accept invitation

    uint32 m_uiKickAfkTimer;                                // Timer for check Afk in war

    //Graveyard variables
    GraveYardVect m_GraveYardList;                          // Vector witch contain the different GY of the battle
    uint32 m_LastResurectTimer;                             // Timer for resurect player every 30 sec

    uint32 m_StartGroupingTimer;                            // Timer for invite players in area 15 minute before start battle
    bool m_StartGrouping;                                   // bool for know if all players in area has been invited

    GuidSet m_Groups[BG_TEAMS_COUNT];                       // Contain different raid group

    std::vector < uint64 > m_Data64;
    std::vector < uint32 > m_Data32;

    void KickAfk();
    // use for switch off all worldstate for client
    virtual void SendRemoveWorldStates(Player * /*plr */ ) {}

    // use for send a packet for all player list
    void BroadcastPacketZone(WorldPacket & data) const;
    void BroadcastPacketQueue(WorldPacket & data) const;
    void BroadcastPacketWar(WorldPacket & data) const;

    //CapturePoint system
    void AddCapturePoint(BfCapturePoint * cp) { m_capturePoints[cp->GetCapturePointGo()->GetEntry()] = cp; }

    BfCapturePoint *GetCapturePoint(uint32 lowguid) const
    {
        Battlefield::BfCapturePointMap::const_iterator itr = m_capturePoints.find(lowguid);
        if (itr != m_capturePoints.end())
            return itr->second;
        return NULL;
    }

    void RegisterZone(uint32 zoneid);
    bool HasPlayer(Player * plr) const;
    void TeamCastSpell(TeamId team, int32 spellId);

};

#endif
