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

#ifndef OUTDOOR_PVP_H_
#define OUTDOOR_PVP_H_

#include "Position.h"
#include "QuaternionData.h"
#include "SharedDefines.h"
#include "ZoneScript.h"
#include <map>

enum OutdoorPvPTypes
{
    OUTDOOR_PVP_HP = 1,
    OUTDOOR_PVP_NA,
    OUTDOOR_PVP_TF,
    OUTDOOR_PVP_ZM,
    OUTDOOR_PVP_SI,

    MAX_OUTDOORPVP_TYPES
};

enum ObjectiveStates
{
    OBJECTIVESTATE_NEUTRAL = 0,
    OBJECTIVESTATE_ALLIANCE,
    OBJECTIVESTATE_HORDE,
    OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE,
    OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE,
    OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE,
    OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE
};

#define OTHER_TEAM(a) (a == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE)

// struct for go spawning
struct go_type
{
    uint32 entry;
    uint32 map;
    Position pos;
    QuaternionData rot;
};

// struct for creature spawning
struct creature_type
{
    uint32 entry;
    uint32 map;
    Position pos;
};

class Creature;
class GameObject;
class Map;
class OutdoorPvP;
class Player;
class Unit;
class WorldPacket;
struct GossipMenuItems;

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates;
    }
}

class TC_GAME_API OPvPCapturePoint
{
    public:

        OPvPCapturePoint(OutdoorPvP* pvp);

        virtual ~OPvPCapturePoint() { }

        virtual void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& /*packet*/) { }

        // send world state update to all players present
        void SendUpdateWorldState(uint32 field, uint32 value);

        // send kill notify to players in the controlling faction
        void SendObjectiveComplete(uint32 id, ObjectGuid guid);

        // used when player is activated/inactivated in the area
        virtual bool HandlePlayerEnter(Player* player);
        virtual void HandlePlayerLeave(Player* player);

        // checks if player is in range of a capture credit marker
        bool IsInsideObjective(Player* player) const;

        virtual bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go);

        virtual int32 HandleOpenGo(Player* player, GameObject* go);

        // returns true if the state of the objective has changed, in this case, the OutdoorPvP must send a world state ui update.
        virtual bool Update(uint32 diff);

        virtual void ChangeState() = 0;

        virtual void ChangeTeam(TeamId /*oldTeam*/) { }

        virtual void SendChangePhase();

        virtual bool HandleGossipOption(Player* /*player*/, Creature* /*guid*/, uint32 /*gossipId*/) { return false; }

        virtual bool CanTalkTo(Player* /*player*/, Creature* /*creature*/, GossipMenuItems const& /*gso*/) { return false; }

        virtual bool HandleDropFlag(Player* /*player*/, uint32 /*spellId*/) { return false; }

        virtual void DeleteSpawns();

        ObjectGuid::LowType m_capturePointSpawnId;

        GameObject* m_capturePoint;

        void AddGO(uint32 type, ObjectGuid::LowType guid);
        void AddCre(uint32 type, ObjectGuid::LowType guid);

        bool SetCapturePointData(uint32 entry, uint32 map, Position const& pos, QuaternionData const& rot);

    protected:

        bool AddObject(uint32 type, uint32 entry, uint32 map, Position const& pos, QuaternionData const& rot);
        bool AddCreature(uint32 type, uint32 entry, uint32 map, Position const& pos, TeamId teamId = TEAM_NEUTRAL, uint32 spawntimedelay = 0);

        bool DelObject(uint32 type);
        bool DelCreature(uint32 type);

        bool DelCapturePoint();

    protected:

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
        ObjectiveStates m_OldState;
        ObjectiveStates m_State;

        // neutral value on capture bar
        uint32 m_neutralValuePct;

        // pointer to the OutdoorPvP this objective belongs to
        OutdoorPvP* m_PvP;

        // map to store the various gameobjects and creatures spawned by the objective
        //        type, guid
        std::map<uint32, ObjectGuid::LowType> m_Objects;
        std::map<uint32, ObjectGuid::LowType> m_Creatures;
        std::map<ObjectGuid::LowType, uint32> m_ObjectTypes;
        std::map<ObjectGuid::LowType, uint32> m_CreatureTypes;
};

// base class for specific outdoor pvp handlers
class TC_GAME_API OutdoorPvP : public ZoneScript
{
    friend class OutdoorPvPMgr;

    public:

        // ctor
        OutdoorPvP();

        // dtor
        virtual ~OutdoorPvP();

        // deletes all gos/creatures spawned by the pvp
        void DeleteSpawns();

        typedef std::map<ObjectGuid::LowType/*spawnId*/, OPvPCapturePoint*> OPvPCapturePointMap;

        virtual void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates & /*packet*/) { }

        // called when a player triggers an areatrigger
        virtual bool HandleAreaTrigger(Player* /*player*/, uint32 /*trigger*/, bool /*entered*/) { return false; }

        // called on custom spell
        virtual bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go);

        // called on go use
        virtual bool HandleOpenGo(Player* player, GameObject* go);

        // setup stuff
        virtual bool SetupOutdoorPvP() {return true;}

        void OnGameObjectCreate(GameObject* go) override;
        void OnGameObjectRemove(GameObject* go) override;
        void OnCreatureCreate(Creature*) override { }

        // send world state update to all players present
        void SendUpdateWorldState(uint32 field, uint32 value);

        // called by OutdoorPvPMgr, updates the objectives and if needed, sends new worldstateui information
        virtual bool Update(uint32 diff);

        // handle npc/player kill
        virtual void HandleKill(Player* killer, Unit* killed);
        virtual void HandleKillImpl(Player* /*killer*/, Unit* /*killed*/) { }

        // checks if player is in range of a capture credit marker
        bool IsInsideObjective(Player* player) const;

        // awards rewards for player kill
        virtual void AwardKillBonus(Player* /*player*/) { }

        uint32 GetTypeId() const {return m_TypeId;}

        virtual bool HandleDropFlag(Player* player, uint32 spellId);

        virtual bool HandleGossipOption(Player* player, Creature* creature, uint32 gossipid);

        virtual bool CanTalkTo(Player* player, Creature* c, GossipMenuItems const& gso);

        void TeamApplyBuff(TeamId team, uint32 spellId, uint32 spellId2 = 0);

        static TeamId GetTeamIdByTeam(uint32 team)
        {
            switch (team)
            {
                case ALLIANCE:
                    return TEAM_ALLIANCE;
                case HORDE:
                    return TEAM_HORDE;
                default:
                    return TEAM_NEUTRAL;
            }
        }

        void SendDefenseMessage(uint32 zoneId, uint32 id);

        Map* GetMap() const { return m_map; }

    protected:

        // the map of the objectives belonging to this outdoorpvp
        OPvPCapturePointMap m_capturePoints;

        GuidSet m_players[2];

        uint32 m_TypeId;

        bool m_sendUpdate;

        // world state stuff
        virtual void SendRemoveWorldStates(Player* /*player*/) { }

        void BroadcastPacket(WorldPacket const* data) const;

        virtual void HandlePlayerEnterZone(Player* player, uint32 zone);
        virtual void HandlePlayerLeaveZone(Player* player, uint32 zone);

        virtual void HandlePlayerResurrects(Player* player, uint32 zone);

        void AddCapturePoint(OPvPCapturePoint* cp);

        OPvPCapturePoint* GetCapturePoint(ObjectGuid::LowType guid) const;

        void RegisterZone(uint32 zoneid);

        bool HasPlayer(Player const* player) const;

        void TeamCastSpell(TeamId team, int32 spellId);

        template<class Worker>
        void BroadcastWorker(Worker& _worker, uint32 zoneId);

        // Hack to store map because this code is just shit
        void SetMapFromZone(uint32 zone);

        Map* m_map;
};

#endif /*OUTDOOR_PVP_H_*/
