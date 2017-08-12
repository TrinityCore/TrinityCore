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

#ifndef BATTLEFIELD_MGR_H_
#define BATTLEFIELD_MGR_H_

#include "Battlefield.h"
#include <unordered_map>

class Player;
class ZoneScript;
enum BattlefieldId;

class TC_GAME_API BattlefieldMgr
{
    public:
        static BattlefieldMgr* instance();

        // create battlefields
        void Initialize();

        // called when a player enters an battlefield area
        void HandlePlayerEnterZone(Player* player, uint32 zoneId);
        // called when player leaves an battlefield area
        void HandlePlayerLeaveZone(Player* player, uint32 zoneId);

        Battlefield* GetEnabledBattlefield(uint32 zoneId);
        Battlefield* GetBattlefield(BattlefieldId battleId);
        ZoneScript* GetZoneScript(uint32 zoneId);

        void Update(uint32 diff);

    private:
        BattlefieldMgr();
        ~BattlefieldMgr();

        // contains all initiated battlefields
        std::unordered_map<uint32/*zoneId*/, Battlefield*> _battlefieldContainer;
        // update interval
        uint32 _updateTimer;
};

#define sBattlefieldMgr BattlefieldMgr::instance()

#endif // BATTLEFIELD_MGR_H_
