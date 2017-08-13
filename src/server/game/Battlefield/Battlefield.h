/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "Position.h"
#include "SharedDefines.h"
#include "Timer.h"
#include "ZoneScript.h"
#include <map>

class Creature;
class GameObject;
class Group;
class Map;
class Player;
class Unit;
class WorldPacket;
struct QuaternionData;
struct WorldSafeLocsEntry;

class BattlefieldGraveyard;
class BattlefieldCapturePoint;

typedef std::vector<BattlefieldGraveyard*> GraveyardVector;
typedef std::vector<BattlefieldCapturePoint*> BattlefieldCapturePointVector;
typedef std::map<ObjectGuid, time_t> PlayerTimerMap;

enum BattlefieldIDs
{
    BATTLEFIELD_BATTLEID_WG = 1 // Wintergrasp battle
};

enum BattlefieldObjectiveStates
{
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL = 0,
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE,
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE,
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE,
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE,
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE,
    BATTLEFIELD_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE
};

enum BattlefieldSounds
{
    BATTLEFIELD_SOUND_HORDE_WINS = 8454,
    BATTLEFIELD_SOUND_ALLIANCE_WINS = 8455,
    BATTLEFIELD_SOUND_START = 3439
};

enum BattlefieldTimers
{
    BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL = 1000
};

class TC_GAME_API Battlefield : public ZoneScript
{
    friend class BattlefieldMgr;

    public:
        Battlefield();
        ~Battlefield();

        virtual bool SetupBattlefield() { return true; }
        virtual void Update(uint32 diff);
        virtual void HandleKill(Player* /*killer*/, Unit* /*killed*/) { }
        virtual uint32 GetData(uint32 dataId) const override { return _data[dataId]; }
        virtual void SetData(uint32 dataId, uint32 value) override { _data[dataId] = value; }
        virtual void UpdateData(uint32 index, int32 pad) { _data[index] += pad; }
        virtual void OnBattleStart() { }
        virtual void OnBattleEnd(bool /*endByTimer*/) { }
        virtual void OnStartGrouping() { }
        virtual void OnPlayerJoinWar(Player* /*player*/) { }
        virtual void OnPlayerLeaveWar(Player* /*player*/) { }
        virtual void OnPlayerLeaveZone(Player* /*player*/) { }
        virtual void OnPlayerEnterZone(Player* /*player*/) { }
        virtual void DoCompleteOrIncrementAchievement(uint32 /*achievement*/, Player* /*player*/, uint8 /*incrementNumber = 1*/) { }
        virtual void SendInitWorldStatesToAll() = 0;
        virtual void FillInitialWorldStates(WorldPacket& /*data*/) = 0;
        virtual void AddPlayerToResurrectQueue(ObjectGuid creatureGUID, ObjectGuid playerGUID);

        void ToggleBattlefield(bool enable);
        void StartBattle();
        void EndBattle(bool endByTimer);
        void SendUpdateWorldState(uint32 field, uint32 value);
        void InvitePlayersInZoneToQueue();
        void InvitePlayersInQueueToWar();
        void InvitePlayersInZoneToWar();
        void KickPlayerFromBattlefield(ObjectGuid guid, Player* player = nullptr);
        void HandlePlayerEnterZone(Player* player, uint32 zone);
        void HandlePlayerLeaveZone(Player* player, uint32 zone);
        void PlayerAcceptInviteToQueue(Player* player);
        void PlayerAcceptInviteToWar(Player* player);
        void AskToLeaveQueue(Player* player, bool kick = false);
        void PlayerAskToLeave(Player* player);
        void InvitePlayerToQueue(Player* player);
        bool InvitePlayerToWar(Player* player);
        bool AddOrSetPlayerToCorrectBfGroup(Player* player);
        void RemovePlayerFromResurrectQueue(ObjectGuid playerGUID);
        void SetGraveyardNumber(uint32 number) { _graveyardList.resize(number); }
        void SendAreaSpiritHealerQueryOpcode(Player* player, ObjectGuid guid);
        Creature* SpawnCreature(uint32 entry, Position const& pos);
        GameObject* SpawnGameObject(uint32 entry, Position const& pos, QuaternionData const& rot);
        void HideCreature(Creature* creature);
        void ShowCreature(Creature* creature, bool aggressive);
        void DoPlaySoundToAll(uint32 soundId);
        void BroadcastPacketToZone(WorldPacket& data) const;
        void BroadcastPacketToQueue(WorldPacket& data) const;
        void BroadcastPacketToWar(WorldPacket& data) const;
        void AddCapturePoint(BattlefieldCapturePoint* capturePoint) { _capturePoints.push_back(capturePoint); }
        void TeamCastSpell(TeamId team, int32 spellId);

        bool IsEnabled() const { return _enabled; }
        bool IsWarTime() const { return _active; }
        bool CanFlyIn() const { return !_active; }
        bool HasPlayer(Player* player) const;

        uint32 GetZoneId() const { return _zoneId; }
        uint32 GetBattleId() const { return _battleId; }
        TeamId GetDefenderTeam() const { return _defenderTeam; }
        TeamId GetAttackerTeam() const { return TeamId(1 - _defenderTeam); }
        TeamId GetOtherTeam(TeamId team) const { return (team == TEAM_HORDE ? TEAM_ALLIANCE : TEAM_HORDE); }
        uint32 GetTimer() const { return _timer; }
        std::list<Player*> GetPlayerListInSourceRange(WorldObject* source, float range, TeamId teamId) const;
        BattlefieldGraveyard* GetGraveyard(uint32 id) const;
        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) const;
        Group* GetFreeGroup(TeamId TeamId) const;
        Group* GetGroupPlayer(ObjectGuid guid, TeamId TeamId) const;
        Creature* GetCreature(ObjectGuid guid);
        GameObject* GetGameObject(ObjectGuid guid);

        void SetTimer(uint32 timer) { _timer = timer; }
        void SetDefenderTeam(TeamId team) { _defenderTeam = team; }

    protected:
        uint32 _timer;
        BattlefieldCapturePointVector _capturePoints;
        GraveyardVector _graveyardList; // graveyard container
        GuidUnorderedSet _players[PVP_TEAMS_COUNT];
        GuidUnorderedSet _playersInQueue[PVP_TEAMS_COUNT];
        GuidUnorderedSet _playersInWar[PVP_TEAMS_COUNT];
        GuidUnorderedSet _groups[PVP_TEAMS_COUNT]; // contains the two different raid groups
        PlayerTimerMap _invitedPlayers[PVP_TEAMS_COUNT];
        PlayerTimerMap _playersToKick[PVP_TEAMS_COUNT];
        std::vector<uint32> _data;
        TeamId _defenderTeam;
        TimeTrackerSmall _kickCheckTimer; // timer to kick AFK players
        TimeTrackerSmall _lastResurrectTimer; // timer to resurrect players (every 30 sec)
        TimeTrackerSmall _startGroupingTimer; // timer to invite players in area 15 minute before starting
        bool _active;
        bool _startGrouping; // all players in area have been invited

        // constant information
        Map* _map;
        uint32 _battleId;
        uint32 _zoneId;
        uint32 _mapId;
        uint32 _maxPlayerCount; // maximum number of players that can participate
        uint32 _minPlayerLevel; // required player level to participate
        uint32 _battleTime; // length of the battle
        uint32 _noWarBattleTime; // time between two battles
        uint32 _restartAfterCrash; // delay to restart if the server crashed during a running battle
        uint32 _acceptInviteTime; // maximum time to accept battle invite
        bool _enabled;
};

class TC_GAME_API BattlefieldCapturePoint
{
    public:
        BattlefieldCapturePoint(Battlefield* battlefield);
        virtual ~BattlefieldCapturePoint() { }

        // Returns true if the state of the objective has changed
        virtual void Update(uint32 diff);
        virtual void ChangeTeam(TeamId /*oldTeam*/) { }
        virtual void SendChangePhase();
        virtual void FillInitialWorldStates(WorldPacket& /*data*/) { }
        // Used when player is activated/inactivated in the area
        virtual bool HandlePlayerEnter(Player* player);
        virtual GuidUnorderedSet::iterator HandlePlayerLeave(Player* player);

        // Send world state update to all players present
        void SendUpdateWorldState(uint32 field, uint32 value);
        // Send kill notify to players in the controlling faction
        void SendObjectiveComplete(uint32 id, ObjectGuid guid);
        void SetCapturePointData(GameObject* capturePoint);
        void SetTeam(TeamId newTeam);

        // Checks if player is in range of a capture credit marker
        bool IsInsideObjective(Player* player) const;
        GameObject* GetCapturePointGameObject();
        uint32 GetCapturePointEntry() const { return _capturePointEntry; }
        TeamId GetTeamId() const { return _team; }

    protected:
        // active Players in the area of the objective, 0 - alliance, 1 - horde
        GuidUnorderedSet _activePlayers[PVP_TEAMS_COUNT];
        // Total shift needed to capture the objective
        float _maxValue;
        float _minValue;
        // Maximum speed of capture
        float _maxSpeed;
        // The status of the objective
        float _value;
        TeamId _team;
        // Objective states
        BattlefieldObjectiveStates _oldState;
        BattlefieldObjectiveStates _state;
        // Neutral value on capture bar
        uint32 _neutralValuePct;
        // Capture point entry
        uint32 _capturePointEntry;
        // Gameobject related to that capture point
        ObjectGuid _capturePointGUID;
        // Pointer to the Battlefield this objective belongs to
        Battlefield* _battlefield;
};

class TC_GAME_API BattlefieldGraveyard
{
    public:
        BattlefieldGraveyard(Battlefield* battlefield);
        void Initialize(TeamId initialTeam, uint32 id);

        // Set spirit creature for the graveyard
        void SetSpirit(Creature* creature, TeamId team);
        // Add a player to the graveyard
        void AddPlayer(ObjectGuid playerGUID);
        // Remove a player from the graveyard
        void RemovePlayer(ObjectGuid playerGUID);
        // Resurrect players
        void Resurrect();
        // Change who controls the graveyard
        void GiveControlTo(TeamId team);
        // Move players in queue to nearest graveyard
        void RelocateDeadPlayers();

        // Get distance between a player and this graveyard
        float GetDistance(Player* player) const;
        // Check if this graveyard has a spirit guide
        bool HasCreature(ObjectGuid guid);
        TeamId GetSpiritTeamId(ObjectGuid guid);
        // Check if a player is in this graveyard's resurrect queue
        bool HasPlayer(ObjectGuid guid) const { return _resurrectQueue.find(guid) != _resurrectQueue.end(); }
        uint32 GetId() const { return _id; }
        TeamId GetControlTeamId() const { return _controlTeam; }

    protected:
        uint32 _id;
        TeamId _controlTeam;
        ObjectGuid _spiritGuides[PVP_TEAMS_COUNT];
        GuidUnorderedSet _resurrectQueue;
        Battlefield* _battlefield;
};

#endif
