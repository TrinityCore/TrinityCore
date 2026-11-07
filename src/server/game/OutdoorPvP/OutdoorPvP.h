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
#include <memory>

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

class TC_GAME_API OPvPCapturePoint
{
    public:

        OPvPCapturePoint(OutdoorPvP* pvp);

        virtual ~OPvPCapturePoint() { }

        OPvPCapturePoint(OPvPCapturePoint const& right) = delete;
        OPvPCapturePoint(OPvPCapturePoint&& right) = delete;
        OPvPCapturePoint& operator=(OPvPCapturePoint const& right) = delete;
        OPvPCapturePoint& operator=(OPvPCapturePoint&& right) = delete;

        virtual void Update([[maybe_unused]] uint32 diff) { }

        virtual bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go);

        virtual int32 HandleOpenGo(Player* player, GameObject* go);

        virtual void ChangeState() = 0;

        virtual void ChangeTeam(TeamId /*oldTeam*/) { }

        virtual bool HandleDropFlag(Player* /*player*/, uint32 /*spellId*/) { return false; }

    protected:

        TeamId m_team;

        // objective states
        ObjectiveStates m_OldState;
        ObjectiveStates m_State;

        // pointer to the OutdoorPvP this objective belongs to
        OutdoorPvP* m_PvP;
};

class TC_GAME_API OutdoorPvPControlZoneHandler : public ControlZoneHandler
{
public:
    explicit OutdoorPvPControlZoneHandler(OutdoorPvP* pvp) : _pvp(pvp) { }
    virtual ~OutdoorPvPControlZoneHandler() = default;

    OutdoorPvP* GetOutdoorPvP() const { return _pvp; }
private:
    OutdoorPvP* _pvp;
};

// base class for specific outdoor pvp handlers
class TC_GAME_API OutdoorPvP : public ZoneScript
{
    friend class OutdoorPvPMgr;

    public:

        // ctor
        explicit OutdoorPvP(Map* map);
        OutdoorPvP(OutdoorPvP const& right) = delete;
        OutdoorPvP(OutdoorPvP&& right) = delete;
        OutdoorPvP& operator=(OutdoorPvP const& right) = delete;
        OutdoorPvP& operator=(OutdoorPvP&& right) = delete;

        // dtor
        virtual ~OutdoorPvP();

        typedef std::map<ObjectGuid::LowType/*spawnId*/, std::unique_ptr<OPvPCapturePoint>> OPvPCapturePointMap;
        typedef std::unordered_map<uint32 /*control zone entry*/, std::unique_ptr<OutdoorPvPControlZoneHandler>> ControlZoneHandlerMap;

        // called when a player triggers an areatrigger
        virtual bool HandleAreaTrigger(Player* /*player*/, uint32 /*trigger*/, bool /*entered*/) { return false; }

        // called on custom spell
        virtual bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go);

        // called on go use
        virtual bool HandleOpenGo(Player* player, GameObject* go);

        // setup stuff
        virtual bool SetupOutdoorPvP() {return true;}

        void OnCreatureCreate(Creature*) override { }

        // send world state update to all players present
        int32 GetWorldState(int32 worldStateId) const;
        void SetWorldState(int32 worldStateId, int32 value);

        // called by OutdoorPvPMgr
        virtual void Update(uint32 diff);

        // handle npc/player kill
        virtual void HandleKill(Player* killer, Unit* killed);
        virtual void HandleKillImpl(Player* /*killer*/, Unit* /*killed*/) { }

        // awards rewards for player kill
        virtual void AwardKillBonus(Player* /*player*/) { }

        uint32 GetTypeId() const {return m_TypeId;}

        virtual bool HandleDropFlag(Player* player, uint32 spellId);

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

        void ProcessEvent([[maybe_unused]] WorldObject* target, [[maybe_unused]] uint32 eventId, [[maybe_unused]] WorldObject* invoker) override;

    protected:

        // the map of the objectives belonging to this outdoorpvp
        OPvPCapturePointMap m_capturePoints;

        ControlZoneHandlerMap ControlZoneHandlers;

        GuidSet m_players[2];

        uint32 m_TypeId;

        // world state stuff
        virtual void SendRemoveWorldStates(Player* /*player*/) { }

        void BroadcastPacket(WorldPacket const* data) const;

        virtual void HandlePlayerEnterZone(Player* player, uint32 zone);
        virtual void HandlePlayerLeaveZone(Player* player, uint32 zone);

        virtual void HandlePlayerResurrects(Player* player, uint32 zone);

        void RegisterZone(uint32 zoneid);

        bool HasPlayer(Player const* player) const;

        void TeamCastSpell(TeamId team, int32 spellId);

        template<class Worker>
        void BroadcastWorker(Worker& _worker, uint32 zoneId);

        Map* m_map;
};

#endif /*OUTDOOR_PVP_H_*/
