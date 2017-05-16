/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_SYSTEM_H
#define SC_SYSTEM_H

#include "ScriptMgr.h"
#include "SplineChain.h"

class Creature;

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
        SystemMgr() { }
        ~SystemMgr() { }

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

        SplineChain const* GetSplineChain(uint32 entry, uint16 chainId) const
        {
            auto it = m_mSplineChainsMap.find({ entry, chainId });
            if (it == m_mSplineChainsMap.end())
                return nullptr;
            return &it->second;
        }

        SplineChain const* GetSplineChain(Creature const* who, uint16 id) const;

    protected:
        PointMoveMap    m_mPointMoveMap;                    //coordinates for waypoints
        typedef std::pair<uint32, uint16> ChainKeyType; // creature entry + chain ID
        std::unordered_map<ChainKeyType, SplineChain> m_mSplineChainsMap; // spline chains
};

#define sScriptSystemMgr SystemMgr::instance()

#endif
