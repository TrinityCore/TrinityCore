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

typedef std::vector<BattlefieldGraveyard*> BattlefieldGraveyardVector;
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
    BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL = 1000,
    BATTLEFIELD_RESURRECT_ITERVAL = 30000
};

enum BattlefieldSpells
{
    SPELL_WAITING_FOR_RESURRECT  = 2584,  // Waiting to Resurrect
    SPELL_SPIRIT_HEAL_CHANNEL    = 22011, // Spirit Heal Channel
    SPELL_SPIRIT_HEAL            = 22012, // Spirit Heal
    SPELL_RESURRECTION_VISUAL    = 24171, // Resurrection Impact Visual
    SPELL_SPIRIT_HEAL_MANA       = 44535, // Spirit Heal
    SPELL_AURA_PLAYER_INACTIVE   = 43681, // Inactive
    SPELL_HONORABLE_DEFENDER_25Y = 68652, // +50% honor when standing at a capture point that you control, 25yards radius (added in 3.2)
    SPELL_HONORABLE_DEFENDER_60Y = 66157  // +50% honor when standing at a capture point that you control, 60yards radius (added in 3.2)
};

class TC_GAME_API Battlefield : public ZoneScript
{
    public:
        Battlefield();
        ~Battlefield();

        virtual void Update(uint32 diff);
        virtual bool SetupBattlefield() { return true; }
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

        // enables or disables the battlefield
        void ToggleBattlefield(bool enable);
        void StartBattle();
        void EndBattle(bool endByTimer);
        // update data of a worldstate to all players present in zone
        void SendUpdateWorldState(uint32 field, uint32 value);
        void InvitePlayersInZoneToWar();
        void InvitePlayersInZoneToQueue();
        void InvitePlayersInQueueToWar();
        bool InvitePlayerToWar(Player* player);
        void InvitePlayerToQueue(Player* player);
        // zone handlers
        void HandlePlayerEnterZone(Player* player, uint32 zone);
        void HandlePlayerLeaveZone(Player* player, uint32 zone);
        // removes player from the battlefield and teleports to home bind if necessary
        void KickPlayer(ObjectGuid guid, Player* player = nullptr);
        // called in WorldSession::HandleBfQueueInviteResponse
        void PlayerAcceptsInviteToQueue(Player* player);
        // called in WorldSession::HandleBfEntryInviteResponse
        void PlayerAcceptsInviteToWar(Player* player);
        // called in WorldSession::HandleBfExitRequest
        void PlayerLeavesQueue(Player* player, bool kick = false);
        // move player to a battlefield group
        bool AddOrSetPlayerToCorrectBfGroup(Player* player);
        void RemovePlayerFromResurrectQueue(ObjectGuid playerGUID);
        void SendAreaSpiritHealerQueryOpcode(Player* player, ObjectGuid guid);
        Creature* SpawnCreature(uint32 entry, Position const& pos);
        GameObject* SpawnGameObject(uint32 entry, Position const& pos, QuaternionData const& rot);
        void HideCreature(Creature* creature);
        void ShowCreature(Creature* creature, bool aggressive);
        void DoPlaySoundToAll(uint32 soundId);
        // packet senders
        void BroadcastPacketToZone(WorldPacket& data) const;
        void BroadcastPacketToQueue(WorldPacket& data) const;
        void BroadcastPacketToWar(WorldPacket& data) const;
        void AddCapturePoint(BattlefieldCapturePoint* capturePoint) { _capturePoints.push_back(capturePoint); }
        void TeamCastSpell(TeamId team, int32 spellId);

        bool IsEnabled() const { return _enabled; }
        bool IsWarTime() const { return _active; }
        // flying mount available
        bool CanFlyIn() const { return !_active; }
        bool HasPlayer(Player* player) const;

        uint32 GetZoneId() const { return _zoneId; }
        uint32 GetBattleId() const { return _battleId; }
        TeamId GetDefenderTeam() const { return _defenderTeam; }
        TeamId GetAttackerTeam() const { return TeamId(1 - _defenderTeam); }
        TeamId GetOtherTeam(TeamId team) const { return (team == TEAM_HORDE ? TEAM_ALLIANCE : TEAM_HORDE); }
        uint32 GetTimer() const { return _timer.GetExpiry() < 0 ? 0 : _timer.GetExpiry(); }
        std::list<Player*> GetPlayerListInSourceRange(WorldObject* source, float range, TeamId teamId) const;
        BattlefieldGraveyard* GetGraveyard(uint32 id) const;
        // finds which graveyard the player must be teleported to
        WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) const;
        // finds a not full battlefield group
        Group* GetFreeGroup(TeamId TeamId) const;
        // returns battlefield group where the player is
        Group* GetGroup(ObjectGuid guid, TeamId TeamId) const;
        Creature* GetCreature(ObjectGuid guid);
        GameObject* GetGameObject(ObjectGuid guid);

        void SetTimer(uint32 timer) { _timer = timer; }
        void SetDefenderTeam(TeamId team) { _defenderTeam = team; }
        void SetGraveyardNumber(uint32 number) { _graveyardList.resize(number); }

    protected:
        TimeTrackerSmall _timer;
        BattlefieldCapturePointVector _capturePoints;
        BattlefieldGraveyardVector _graveyardList; // graveyard container
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
        bool _active;
        bool _enabled;
        bool _startGrouping; // all players in zone have been invited

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
        uint32 _startGroupingTime; // time to invite players in zone

    private:
        void RemovePlayer(ObjectGuid playerGUID);
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
