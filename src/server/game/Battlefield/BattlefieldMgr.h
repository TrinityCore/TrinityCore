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

#ifndef BATTLEFIELD_MGR_H_
#define BATTLEFIELD_MGR_H_

#include "Battlefield.h"
#include "Hash.h"
#include <memory>
#include <unordered_map>
#include <vector>

class Player;
class ZoneScript;

// class to handle player enter / leave / areatrigger / GO use events
class TC_GAME_API BattlefieldMgr
{
    public:
        BattlefieldMgr(BattlefieldMgr const&) = delete;
        BattlefieldMgr(BattlefieldMgr&&) = delete;

        BattlefieldMgr& operator=(BattlefieldMgr const&) = delete;
        BattlefieldMgr& operator=(BattlefieldMgr&&) = delete;

        static BattlefieldMgr* instance();

        // create battlefield events
        void InitBattlefield();

        void CreateBattlefieldsForMap(Map* map);

        void DestroyBattlefieldsForMap(Map const* map);

        // called when a player enters an battlefield area
        void HandlePlayerEnterZone(Player* player, uint32 zoneId);
        // called when player leaves an battlefield area
        void HandlePlayerLeaveZone(Player* player, uint32 zoneId);

        bool IsWorldPvpArea(uint32 zoneId) const;

        // return assigned battlefield
        Battlefield* GetBattlefieldToZoneId(Map const* map, uint32 zoneId);
        Battlefield* GetBattlefieldByBattleId(Map const* map, uint32 battleId);

        void AddZone(uint32 zoneId, Battlefield* bf);

        void Update(uint32 diff);

    private:
        BattlefieldMgr();
        ~BattlefieldMgr();

        typedef std::unordered_map<Map const*, std::vector<std::unique_ptr<Battlefield>>> BattlefieldsMapByMap;
        typedef std::unordered_map<std::pair<Map const*, uint32 /*zoneid*/>, Battlefield*> BattlefieldMapByZone;
        // contains all initiated battlefield events
        // used when initing / cleaning up
        BattlefieldsMapByMap _battlefieldsByMap;
        // maps the zone ids to an battlefield event
        // used in player event handling
        BattlefieldMapByZone _battlefieldsByZone;
        // update interval
        uint32 _updateTimer;
};

#define sBattlefieldMgr BattlefieldMgr::instance()

#endif // BATTLEFIELD_MGR_H_
