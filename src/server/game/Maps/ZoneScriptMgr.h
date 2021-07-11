/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.TrinityCore.org/>
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

#ifndef ZONE_SCRIPT_MGR_H_
#define ZONE_SCRIPT_MGR_H_

#define OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL 1000

#include "ZoneScript.h"
#include <ace/Singleton.h>

class Player;
class GameObject;
class Creature;
class ZoneScript;
struct GossipMenuItems;
class Map;

// Scripts TC
class ZoneScript_Script
{
    public:
        ZoneScript_Script() {}
        virtual ~ZoneScript_Script() {}
        virtual ZoneScript* GetZoneScript() const = 0;
        virtual uint32 GetMapId() const = 0;
};

// class to handle player enter / leave / areatrigger / GO use events
class ZoneScriptMgr
{
    public:

        // ctor
        ZoneScriptMgr();

        // dtor
        ~ZoneScriptMgr();

        // create outdoor pvp events
        void InitZoneScripts();
        void InitMapZoneScripts(uint32 mapId, Map* pMap);
        void MapLoaded(uint32 mapId, Map* pMap) { InitMapZoneScripts(mapId, pMap); }

        // called when a player enters an outdoor pvp area
        void HandlePlayerEnterZone(Player* plr, uint32 areaflag);

        // called when player leaves an outdoor pvp area
        void HandlePlayerLeaveZone(Player* plr, uint32 areaflag);

        // return assigned outdoor pvp
        ZoneScript * GetZoneScriptToZoneId(uint32 zoneid);

        // handle custom (non-exist in dbc) spell if registered
        bool HandleCustomSpell(Player* plr, uint32 spellId, GameObject* go);

        // handle custom go if registered
        bool HandleOpenGo(Player* plr, uint64 guid);

        ZoneScript * GetZoneScript(uint32 zoneId);

        void AddZone(uint32 zoneid, ZoneScript * handle);

        void Update(uint32 diff);

        void HandleGossipOption(Player* player, uint64 guid, uint32 gossipid);

        void HandleDropFlag(Player* plr, uint32 spellId);

        typedef std::set<ZoneScript*> ZoneScriptsSet;
        typedef std::vector<ZoneScript_Script*> ZoneScript_ScriptSet;
        typedef std::map<uint32 /* zoneid */, ZoneScript*> ZoneScriptsMap;
        void AddScript(ZoneScript_Script* pScript) { m_ZoneScripts_Scripts.push_back(pScript); }
        void OnMapCrashed(Map* map);

    private:
        // HACK : les scripts
        ZoneScript_ScriptSet m_ZoneScripts_Scripts;

        // contains all initiated outdoor pvp events
        // used when initing / cleaning up
        ZoneScriptsSet  m_ZoneScriptsSet;

        // maps the zone ids to an outdoor pvp event
        // used in player event handling
        ZoneScriptsMap   m_ZoneScriptsMap;

        // update interval
        uint32 m_UpdateTimer;
};

#define sZoneScriptMgr MaNGOS::Singleton<ZoneScriptMgr>::Instance()
#endif /*OUTDOOR_PVP_MGR_H_*/
