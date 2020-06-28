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

#ifndef SC_SYSTEM_H
#define SC_SYSTEM_H

#include "Define.h"
#include "Hash.h"
#include <unordered_map>
#include <vector>

class Creature;
struct SplineChainLink;

#define TEXT_SOURCE_RANGE -1000000                          //the amount of entries each text source has available

struct ScriptPointMove
{
    uint32 uiCreatureEntry;
    uint32 uiPointId;
    float  fX;
    float  fY;
    float  fZ;
    uint32 uiWaitTime;
};

typedef std::vector<ScriptPointMove> ScriptPointVector;

class TC_GAME_API SystemMgr
{
    private:
        SystemMgr();
        ~SystemMgr();
        SystemMgr(SystemMgr const&) = delete;
        SystemMgr& operator=(SystemMgr const&) = delete;

    public:
        static SystemMgr* instance();

        typedef std::unordered_map<uint32, ScriptPointVector> PointMoveMap;

        //Database
        void LoadScriptWaypoints();
        void LoadScriptSplineChains();

        ScriptPointVector const* GetPointMoveList(uint32 creatureEntry) const
        {
            PointMoveMap::const_iterator itr = m_mPointMoveMap.find(creatureEntry);

            if (itr == m_mPointMoveMap.end())
                return nullptr;

            return &itr->second;
        }

        std::vector<SplineChainLink> const* GetSplineChain(uint32 entry, uint16 chainId) const;
        std::vector<SplineChainLink> const* GetSplineChain(Creature const* who, uint16 id) const;

    protected:
        PointMoveMap    m_mPointMoveMap;                    //coordinates for waypoints
        typedef std::pair<uint32, uint16> ChainKeyType; // creature entry + chain ID
        std::unordered_map<ChainKeyType, std::vector<SplineChainLink>> m_mSplineChainsMap; // spline chains
};

#define sScriptSystemMgr SystemMgr::instance()

#endif
