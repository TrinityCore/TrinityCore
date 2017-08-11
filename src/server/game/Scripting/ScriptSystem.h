/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef SC_SYSTEM_H
#define SC_SYSTEM_H

#include "Define.h"
#include "Hash.h"
#include "WaypointDefines.h"
#include <unordered_map>
#include <vector>

class Creature;
struct SplineChainLink;

#define TEXT_SOURCE_RANGE -1000000 // the amount of entries each text source has available

class TC_GAME_API SystemMgr
{
    public:
        static SystemMgr* instance();

        // database
        void LoadScriptWaypoints();
        void LoadScriptSplineChains();

        WaypointPath const* GetPath(uint32 creatureEntry) const;

        std::vector<SplineChainLink> const* GetSplineChain(uint32 entry, uint16 chainId) const;
        std::vector<SplineChainLink> const* GetSplineChain(Creature const* who, uint16 id) const;

    private:
        typedef std::pair<uint32, uint16> ChainKeyType; // creature entry + chain ID

        SystemMgr();
        ~SystemMgr();

        SystemMgr(SystemMgr const&) = delete;
        SystemMgr& operator=(SystemMgr const&) = delete;

        std::unordered_map<uint32, WaypointPath> _waypointStore;
        std::unordered_map<ChainKeyType, std::vector<SplineChainLink>> m_mSplineChainsMap; // spline chains
};

#define sScriptSystemMgr SystemMgr::instance()

#endif
