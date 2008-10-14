#ifndef OUTDOOR_PVP_MGR_H_
#define OUTDOOR_PVP_MGR_H_

#include "OutdoorPvP.h"
#include "Policies/Singleton.h"

class Player;
class GameObject;
class Creature;
struct GossipOption;

// class to handle player enter / leave / areatrigger / GO use events
class OutdoorPvPMgr
{
public:
    // ctor
    OutdoorPvPMgr();
    // dtor
    ~OutdoorPvPMgr();

    // create outdoor pvp events
    void InitOutdoorPvP();
    // called when a player enters an outdoor pvp area
    void HandlePlayerEnterZone(Player * plr, uint32 areaflag);
    // called when player leaves an outdoor pvp area
    void HandlePlayerLeaveZone(Player * plr, uint32 areaflag);
    // return assigned outdoor pvp
    OutdoorPvP * GetOutdoorPvPToZoneId(uint32 zoneid);
    // handle custom (non-exist in dbc) spell if registered
    bool HandleCustomSpell(Player * plr, uint32 spellId, GameObject* go);
    // handle custom go if registered
    bool HandleOpenGo(Player * plr, uint64 guid);

    void AddZone(uint32 zoneid, OutdoorPvP * handle);

    void Update(uint32 diff);

    bool HandleCaptureCreaturePlayerMoveInLos(Player * plr, Creature * c);

    void HandleGossipOption(Player * player, uint64 guid, uint32 gossipid);

    bool CanTalkTo(Player * player, Creature * creature, GossipOption & gso);

    void HandleDropFlag(Player * plr, uint32 spellId);

    typedef std::set<OutdoorPvP*> OutdoorPvPSet;
    typedef std::map<uint32 /* zoneid */, OutdoorPvP*> OutdoorPvPMap;
private:
    // contains all initiated outdoor pvp events
    // used when initing / cleaning up
    OutdoorPvPSet  m_OutdoorPvPSet;
    // maps the zone ids to an outdoor pvp event
    // used in player event handling
    OutdoorPvPMap   m_OutdoorPvPMap;
};

#define sOutdoorPvPMgr Trinity::Singleton<OutdoorPvPMgr>::Instance()

#endif /*OUTDOOR_PVP_MGR_H_*/
