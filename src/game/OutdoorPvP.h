#ifndef OUTDOOR_PVP_H_
#define OUTDOOR_PVP_H_

#include "Util.h"

#include <map>
#include <set>

#define OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL 1000

#define OPVP_TRIGGER_CREATURE_ENTRY 12999

enum ObjectiveStates{
    OBJECTIVESTATE_NEUTRAL = 0,
    OBJECTIVESTATE_ALLIANCE = 1,
    OBJECTIVESTATE_HORDE = 2,
    OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE = 3,
    OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE = 4,
    OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE = 5,
    OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE = 6
};

enum OutdoorPvPTypes{
    OUTDOOR_PVP_HP = 1,
    OUTDOOR_PVP_NA = 2,
    OUTDOOR_PVP_TF = 3,
    OUTDOOR_PVP_ZM = 4,
    OUTDOOR_PVP_SI = 5,
    OUTDOOR_PVP_EP = 6
};

// struct for go spawning
struct go_type{
    uint32 entry;
    uint32 map;
    float x;
    float y;
    float z;
    float o;
    float rot0;
    float rot1;
    float rot2;
    float rot3;
};

// struct for creature spawning
struct creature_type{
    uint32 entry;
    uint32 teamval;
    uint32 map;
    float x;
    float y;
    float z;
    float o;
};

// some class predefs
class Player;
class GameObject;
class WorldPacket;
class Creature;
class Unit;
struct GossipOption;

class OutdoorPvP;
class OutdoorPvPObjective
{
public:
    OutdoorPvPObjective(OutdoorPvP * pvp);

    virtual void FillInitialWorldStates(WorldPacket & data) {}

    // send world state update to all players present
    virtual void SendUpdateWorldState(uint32 field, uint32 value);
    // send kill notify to players in the controlling faction
    virtual void SendObjectiveComplete(uint32 id, uint64 guid);

    // used when player is activated/inactivated in the area
    virtual bool HandlePlayerEnter(Player * plr);
    virtual void HandlePlayerLeave(Player * plr);
    virtual void HandlePlayerActivityChanged(Player * plr);

    // checks if player is in range of a capture credit marker
    virtual bool IsInsideObjective(Player * plr);

    virtual bool HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go);
    virtual int32 HandleOpenGo(Player *plr, uint64 guid);

    // returns true if the state of the objective has changed, in this case, the OutdoorPvP must send a world state ui update.
    virtual bool Update(uint32 diff);

    virtual bool HandleCapturePointEvent(Player * plr, uint32 eventId) { return false; }

    virtual bool HandleCaptureCreaturePlayerMoveInLos(Player * p, Creature * c);

    virtual bool HandleGossipOption(Player *plr, uint64 guid, uint32 gossipid);

    virtual bool CanTalkTo(Player * plr, Creature * c, GossipOption &gso);

    virtual bool HandleDropFlag(Player * plr, uint32 spellId);

    virtual void DeleteSpawns();
protected:

    virtual bool AddCapturePoint(uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3);
    virtual bool AddObject(uint32 type, uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3);
    virtual bool AddCreature(uint32 type, uint32 entry, uint32 teamval, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay = 0);

    virtual bool DelCreature(uint32 type);
    virtual bool DelObject(uint32 type);
    virtual bool DelCapturePoint();

protected:
    // active players in the area of the objective
    std::set<uint64> m_ActivePlayerGuids;
    int32 m_AllianceActivePlayerCount;
    int32 m_HordeActivePlayerCount;
    // time left to capture the objective
    uint32 m_ShiftTimer;
    // total shift needed to capture the objective
    float m_ShiftMaxPhase;
    // maximum speed of capture
    float m_ShiftMaxCaptureSpeed;
    // the status of the objective
    float m_ShiftPhase;
    // phase before update, used to check which faction is in conquer / control
    float m_OldPhase;
    // objective states
    uint32 m_OldState;
    uint32 m_State;
    // neutral value on capture bar
    uint32 m_NeutralValue;

    // pointer to the OutdoorPvP this objective belongs to
    OutdoorPvP* m_PvP;

    // map to store the various gameobjects and creatures spawned by the objective
    //        type , guid
    std::map<uint32,uint64> m_Objects;
    std::map<uint32,uint64> m_Creatures;
    std::map<uint64,uint32> m_ObjectTypes;
    std::map<uint64,uint32> m_CreatureTypes;
    uint64 m_CapturePoint;
    uint64 m_CapturePointCreature;
};

// base class for specific outdoor pvp handlers
class OutdoorPvP
{
public:
    // ctor
    OutdoorPvP();
    // dtor
    ~OutdoorPvP();
    // deletes all gos/creatures spawned by the pvp
    void DeleteSpawns();

    typedef std::set<OutdoorPvPObjective *> OutdoorPvPObjectiveSet;

    // called from Player::UpdateZone to add / remove buffs given by outdoor pvp events
    virtual void HandlePlayerEnterZone(Player * plr, uint32 zone);
    virtual void HandlePlayerLeaveZone(Player * plr, uint32 zone);
    virtual void HandlePlayerActivityChanged(Player * plr);
    // called when a player triggers an areatrigger
    virtual bool HandleAreaTrigger(Player * plr, uint32 trigger);
    // called on custom spell
    virtual bool HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go);
    // called on go use
    virtual bool HandleOpenGo(Player *plr, uint64 guid);
    // called from moveinlineofsight
    virtual bool HandleCaptureCreaturePlayerMoveInLos(Player * p, Creature * c);

    // setup stuff
    virtual bool SetupOutdoorPvP() {return true;}

    // world state stuff
    virtual void SendRemoveWorldStates(Player * plr) {}
    virtual void FillInitialWorldStates(WorldPacket & data) {}

    // send world state update to all players present
    virtual void SendUpdateWorldState(uint32 field, uint32 value);

    // called by OutdoorPvPMgr, updates the objectives and if needed, sends new worldstateui information
    virtual bool Update(uint32 diff);

    // handle npc/player kill
    virtual void HandleKill(Player * killer, Unit * killed);
    virtual void HandleKillImpl(Player * killer, Unit * killed) {}

    // checks if player is in range of a capture credit marker
    virtual bool IsInsideObjective(Player * plr);

    // awards rewards for player kill
    virtual void AwardKillBonus(Player * plr) {}

    uint32 GetTypeId() {return m_TypeId;}

    virtual bool HandleDropFlag(Player * plr, uint32 spellId);

    virtual bool HandleGossipOption(Player *plr, uint64 guid, uint32 gossipid);

    virtual bool CanTalkTo(Player * plr, Creature * c, GossipOption &gso);
protected:
    // the map of the objectives belonging to this outdoorpvp
    OutdoorPvPObjectiveSet m_OutdoorPvPObjectives;
    // players in the zones of this outdoorpvp, 0 - alliance, 1 - horde
    std::set<uint64> m_PlayerGuids[2];
    uint32 m_TypeId;
};

#endif /*OUTDOOR_PVP_H_*/
