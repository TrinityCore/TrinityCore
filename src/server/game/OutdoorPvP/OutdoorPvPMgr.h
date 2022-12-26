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

#ifndef OUTDOOR_PVP_MGR_H_
#define OUTDOOR_PVP_MGR_H_

#define OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL 1000

#include "OutdoorPvP.h"
#include "Hash.h"
#include <array>
#include <memory>
#include <unordered_map>
#include <vector>

class Player;
class GameObject;
class Creature;
class Map;
class ZoneScript;
struct GossipMenuItems;

// class to handle player enter / leave / areatrigger / GO use events
class TC_GAME_API OutdoorPvPMgr
{
    private:
        OutdoorPvPMgr();
        ~OutdoorPvPMgr();

    public:
        static OutdoorPvPMgr* instance();

        // create outdoor pvp events
        void InitOutdoorPvP();

        // cleanup
        void Die();

        void CreateOutdoorPvPForMap(Map* map);

        void DestroyOutdoorPvPForMap(Map* map);

        // called when a player enters an outdoor pvp area
        void HandlePlayerEnterZone(Player* player, uint32 areaflag);

        // called when player leaves an outdoor pvp area
        void HandlePlayerLeaveZone(Player* player, uint32 areaflag);

        // called when player resurrects
        void HandlePlayerResurrects(Player* player, uint32 areaflag);

        // return assigned outdoor pvp
        OutdoorPvP* GetOutdoorPvPToZoneId(Map* map, uint32 zoneid);

        // handle custom (non-exist in dbc) spell if registered
        bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go);

        // handle custom go if registered
        bool HandleOpenGo(Player* player, GameObject* go);

        void AddZone(uint32 zoneid, OutdoorPvP* handle);

        void Update(uint32 diff);

        void HandleGossipOption(Player* player, Creature* creature, uint32 gossipid);

        bool CanTalkTo(Player* player, Creature* creature, GossipMenuItems const& gso);

        void HandleDropFlag(Player* player, uint32 spellId);

        std::string GetDefenseMessage(uint32 zoneId, uint32 id, LocaleConstant locale) const;

    private:
        typedef std::unordered_map<std::pair<Map*, uint32 /*zoneid*/>, OutdoorPvP*> OutdoorPvPMap;
        typedef std::array<uint32, MAX_OUTDOORPVP_TYPES> OutdoorPvPScriptIds;

        // contains all initiated outdoor pvp events
        // used when initing / cleaning up
        std::unordered_map<Map*, std::vector<std::unique_ptr<OutdoorPvP>>> m_OutdoorPvPByMap;

        // maps the zone ids to an outdoor pvp event
        // used in player event handling
        OutdoorPvPMap   m_OutdoorPvPMap;

        // Holds the outdoor PvP templates
        OutdoorPvPScriptIds m_OutdoorMapIds = { 0, 530, 530, 530, 530, 1 };
        OutdoorPvPScriptIds m_OutdoorPvPDatas;

        // update interval
        uint32 m_UpdateTimer;
};

#define sOutdoorPvPMgr OutdoorPvPMgr::instance()

#endif /*OUTDOOR_PVP_MGR_H_*/
