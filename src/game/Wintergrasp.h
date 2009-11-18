/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_WINTERGRASP_H
#define TRINITY_WINTERGRASP_H

#include "OutdoorPvPImpl.h"

#define ZONE_WINTERGRASP         4197
#define POS_X_CENTER             5100
#define MAX_VEHICLE_PER_WORKSHOP    4

const uint32 WintergraspFaction[3] = {1732, 1735, 35};
const uint32 WG_MARK_OF_HONOR = 43589;
const uint32 VehNumWorldState[2] = {3680,3490};
const uint32 MaxVehNumWorldState[2] = {3681,3491};
const uint32 ClockWorldState[5] = {3785,3784,3782,3976,3975};

enum WintergraspSpell
{
    // Wartime auras
    SPELL_RECRUIT           = 37795,
    SPELL_CORPORAL          = 33280,
    SPELL_LIEUTENANT        = 55629,
    SPELL_TENACITY          = 58549,
    SPELL_TENACITY_VEHICLE  = 59911,
    SPELL_TOWER_CONTROL     = 62064,
    SPELL_SPIRITUAL_IMMUNITY = 58729,

    // Reward spells
    SPELL_VICTORY_REWARD    = 56902,
    SPELL_DEFEAT_REWARD     = 58494,
    SPELL_DAMAGED_TOWER     = 59135,
    SPELL_DESTROYED_TOWER   = 59136,
    SPELL_DAMAGED_BUILDING  = 59201,
    SPELL_INTACT_BUILDING   = 59203,

    // No Wartime auras
    SPELL_ESSENCE_OF_WG     = 58045,

    // other
    SPELL_NOFLYZONE_WG      = 58730,
    SPELL_PARACHUTE_WG      = 61243,

//    SPELL_TELEPORT_DALARAN  = 53360,
//    SPELL_VICTORY_AURA      = 60044,
};

enum WintergraspRewardEvent
{
    WIN_BATTLE,
    LOSE_BATTLE,
    DAMAGED_TOWER,
    DESTROYED_TOWER,
    DAMAGED_BUILDING,
    INTACT_BUILDING,
    WG_REWARD_EVENT_MAX,
};

/* Not used / Not implemented

const uint16 GameEventWintergraspDefender[2] = {50, 51};

enum OutdoorPvP_WG_Sounds
{
    OutdoorPvP_WG_SOUND_KEEP_CLAIMED            = 8192,
    OutdoorPvP_WG_SOUND_KEEP_CAPTURED_ALLIANCE  = 8173,
    OutdoorPvP_WG_SOUND_KEEP_CAPTURED_HORDE     = 8213,
    OutdoorPvP_WG_SOUND_KEEP_ASSAULTED_ALLIANCE = 8212,
    OutdoorPvP_WG_SOUND_KEEP_ASSAULTED_HORDE    = 8174,
    OutdoorPvP_WG_SOUND_NEAR_VICTORY            = 8456
};

enum DataId
{
    DATA_ENGINEER_DIE,
};

enum OutdoorPvP_WG_KeepStatus
{
    OutdoorPvP_WG_KEEP_TYPE_NEUTRAL             = 0,
    OutdoorPvP_WG_KEEP_TYPE_CONTESTED           = 1,
    OutdoorPvP_WG_KEEP_STATUS_ALLY_CONTESTED    = 1,
    OutdoorPvP_WG_KEEP_STATUS_HORDE_CONTESTED   = 2,
    OutdoorPvP_WG_KEEP_TYPE_OCCUPIED            = 3,
    OutdoorPvP_WG_KEEP_STATUS_ALLY_OCCUPIED     = 3,
    OutdoorPvP_WG_KEEP_STATUS_HORDE_OCCUPIED    = 4
};
*/

enum WintergraspCreType
{
    CREATURE_OTHER,
    CREATURE_SIEGE_VEHICLE,
    CREATURE_TURRET,
    CREATURE_ENGINEER,
    CREATURE_GUARD,
    CREATURE_SPECIAL,
    CREATURE_SPIRIT_GUIDE,
    CREATURE_SPIRIT_HEALER,
    CREATURE_QUESTGIVER,
};

enum BuildingType
{
    BUILDING_WALL,
    BUILDING_WORKSHOP,
    BUILDING_TOWER,
};

enum DamageState
{ // Do not change order
    DAMAGE_INTACT,
    DAMAGE_DAMAGED,
    DAMAGE_DESTROYED,
};

const uint32 AreaPOIIconId[3][3] = {{7,8,9},{4,5,6},{1,2,3}};

struct BuildingState
{
    explicit BuildingState(uint32 _worldState, TeamId _team, bool asDefault)
        : worldState(_worldState), health(0)
        , defaultTeam(asDefault ? _team : OTHER_TEAM(_team)), team(_team), damageState(DAMAGE_INTACT)
        , building(NULL), type(BUILDING_WALL), graveTeam(NULL)
    {}
    uint32 worldState;
    uint32 health;
    TeamId defaultTeam;
    DamageState damageState;
    GameObject *building;
    uint32 *graveTeam;
    BuildingType type;

    void SendUpdate(Player *player) const
    {
        player->SendUpdateWorldState(worldState, AreaPOIIconId[team][damageState]);
    }

    void FillData(WorldPacket &data) const
    {
        data << worldState << AreaPOIIconId[team][damageState];
    }

    TeamId GetTeam() const { return team; }
    void SetTeam(TeamId t)
    {
        team = t;
        if(graveTeam)
            if (uint32 newTeam = TeamId2Team[t])
                *graveTeam = newTeam;
    }

private:
    TeamId team;
};

typedef std::map<uint32, uint32> TeamPairMap;

class SiegeWorkshop;

class OPvPWintergrasp : public OutdoorPvP
{
    protected:
        typedef std::map<uint32, BuildingState *> BuildingStateMap;
        typedef std::set<Creature*> CreatureSet;
        typedef std::set<GameObject*> GameObjectSet;
        typedef std::map<std::pair<uint32, bool>, Position> QuestGiverPositionMap;
        typedef std::map<uint32, Creature*> QuestGiverMap;
    public:
        OPvPWintergrasp();
        bool SetupOutdoorPvP();

        uint32 GetCreatureEntry(uint32 guidlow, const CreatureData *data);
        //uint32 GetGameObjectEntry(uint32 guidlow, uint32 entry);

        void OnCreatureCreate(Creature *creature, bool add);
        void OnGameObjectCreate(GameObject *go, bool add);

        void ProcessEvent(GameObject *obj, uint32 eventId);

        void HandlePlayerEnterZone(Player *plr, uint32 zone);
        void HandlePlayerLeaveZone(Player *plr, uint32 zone);
        void HandlePlayerResurrects(Player * plr, uint32 zone);
        void HandleKill(Player *killer, Unit *victim);

        bool Update(uint32 diff);

        void BroadcastStateChange(BuildingState *state) const;

        uint32 GetData(uint32 id);
        void SetData(uint32 id, uint32 value);

        void ModifyWorkshopCount(TeamId team, bool add);
        uint32 GetTimer() const { return m_timer / 1000; };
        TeamId GetTeam() const { return m_defender; };
        bool isWarTime() const { return m_wartime; };
        void setTimer(uint32 timer)
        {
            if (timer >= 0)
                m_timer = timer;
        };
        void forceChangeTeam();
        void forceStopBattle();
        void forceStartBattle();

        // Temporal BG specific till 3.2
        void SendAreaSpiritHealerQueryOpcode(Player *pl, const uint64& guid);
        void AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid);
        void RemovePlayerFromResurrectQueue(uint64 player_guid);
        void RelocateDeadPlayers(Creature *cr);
        // BG end
    protected:
        // Temporal BG specific till 3.2
        std::vector<uint64> m_ResurrectQueue;               // Player GUID
        uint32 m_LastResurrectTime;
        // Spirit Guide guid + Player list GUIDS
        std::map<uint64, std::vector<uint64> >  m_ReviveQueue;

        uint32 GetLastResurrectTime() const { return m_LastResurrectTime; }
        uint32 GetReviveQueueSize() const { return m_ReviveQueue.size(); }
        // BG end

        TeamId m_defender;
        int32 m_tenacityStack;

        BuildingStateMap m_buildingStates;
        BuildingState *m_gate;

        CreatureSet m_creatures;
        CreatureSet m_vehicles[2];
        GameObjectSet m_gobjects;
        QuestGiverMap m_questgivers;

        TeamPairMap m_creEntryPair, m_goDisplayPair;
        QuestGiverPositionMap m_qgPosMap;

        bool m_wartime;
        bool m_changeDefender;
        uint32 m_timer;
        uint32 m_clock[5];
        uint32 m_workshopCount[2];
        uint32 m_towerDestroyedCount[2];
        uint32 m_towerDamagedCount[2];

        uint32 m_customHonorReward[WG_REWARD_EVENT_MAX];

        SiegeWorkshop *GetWorkshop(uint32 lowguid) const;
        SiegeWorkshop *GetWorkshopByEngGuid(uint32 lowguid) const;
        SiegeWorkshop *GetWorkshopByGOGuid(uint32 lowguid) const;

        void StartBattle();
        void EndBattle();

        void UpdateClock();
        void UpdateClockDigit(uint32 &timer, uint32 digit, uint32 mod);
        void PromotePlayer(Player *player) const;
        void UpdateTenacityStack();
        void UpdateAllWorldObject();
        bool UpdateCreatureInfo(Creature *creature);
        bool UpdateGameObjectInfo(GameObject *go) const;

        bool CanBuildVehicle(SiegeWorkshop *workshop) const;
        WintergraspCreType GetCreatureType(uint32 entry) const;

        void RebuildAllBuildings();

        void SendInitWorldStatesTo(Player *player = NULL) const;
        void RemoveOfflinePlayerWGAuras();
        void RewardMarkOfHonor(Player *player, uint32 count);
        void MoveQuestGiver(uint32 guid);
        void LoadQuestGiverMap(uint32 guid, Position posHorde, Position posAlli);
        bool UpdateQuestGiverPosition(uint32 guid, Creature *creature);
};

class SiegeWorkshop : public OPvPCapturePoint
{
    public:
        explicit SiegeWorkshop(OPvPWintergrasp *opvp, BuildingState *state);
        void SetTeamByBuildingState();
        void ChangeState() {}
        void ChangeTeam(TeamId oldteam);
        //void DespawnAllVehicles();

        //bool CanBuildVehicle() const { return m_vehicles.size() < MAX_VEHICLE_PER_WORKSHOP && m_buildingState->damageState != DAMAGE_DESTROYED; }

        uint32 *m_spiEntry;
        uint32 m_spiGuid;
        Creature *m_spiritguide;

        uint32 *m_engEntry;
        uint32 m_engGuid;
        Creature *m_engineer;
        uint32 m_workshopGuid;
        //CreatureSet m_vehicles;
        BuildingState *m_buildingState;
    protected:
        OPvPWintergrasp *m_wintergrasp;
};

#endif
