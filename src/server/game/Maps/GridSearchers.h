/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_GRIDSEARCH_H
#define SC_GRIDSEARCH_H

#include "Unit.h"
#include "GameObject.h"

#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

struct ObjectDistanceOrder
{
    Unit const* m_pSource;

    ObjectDistanceOrder(Unit const* pSource) : m_pSource(pSource) {};

    bool operator()(WorldObject const* pLeft, WorldObject const* pRight) const
    {
        return m_pSource->GetDistanceOrder(pLeft, pRight);
    }
};

struct ObjectDistanceOrderReversed
{
    Unit const* m_pSource;

    ObjectDistanceOrderReversed(Unit const* pSource) : m_pSource(pSource) {};

    bool operator()(WorldObject const* pLeft, WorldObject const* pRight) const
    {
        return !m_pSource->GetDistanceOrder(pLeft, pRight);
    }
};

GameObject* GetClosestGameObjectWithEntry(WorldObject* pSource, uint32 uiEntry, float fMaxSearchRange);
Creature* GetClosestCreatureWithEntry(WorldObject* pSource, uint32 uiEntry, float fMaxSearchRange);

void GetGameObjectListWithEntryInGrid(std::list<GameObject*>& lList, WorldObject* pSource, uint32 uiEntry, float fMaxSearchRange);
void GetGameObjectListWithEntryInGrid(std::list<GameObject*>& lList, WorldObject* pSource, std::vector<uint32> const& entries, float fMaxSearchRange);
void GetCreatureListWithEntryInGrid(std::list<Creature*>& lList, WorldObject* pSource, uint32 uiEntry, float fMaxSearchRange);
void GetCreatureListWithEntryInGrid(std::list<Creature*>& lList, WorldObject* pSource, std::vector<uint32> const& entries, float fMaxSearchRange);

/*
//Used in:
//hyjalAI.cpp
class AllFriendlyCreaturesInGrid
{
    public:
        AllFriendlyCreaturesInGrid(Unit const* obj) : pUnit(obj) {}
        bool operator() (Unit* u)
        {
            if (u->IsAlive() && u->GetVisibility() == VISIBILITY_ON && u->IsFriendlyTo(pUnit))
                return true;

            return false;
        }

    private:
        Unit const* pUnit;
};

class AllGameObjectsWithEntryInRangeCheck
{
    public:
        AllGameObjectsWithEntryInRangeCheck(WorldObject const* pObject, uint32 uiEntry, float fMaxRange) : m_pObject(pObject), m_uiEntry(uiEntry), m_fRange(fMaxRange) {}
        bool operator() (GameObject* pGo)
        {
            if (pGo->GetEntry() == m_uiEntry && m_pObject->IsWithinDist(pGo,m_fRange,false))
                return true;

            return false;
        }

    private:
        WorldObject const* m_pObject;
        uint32 m_uiEntry;
        float m_fRange;
};

class AllCreaturesOfEntryInRangeCheck
{
    public:
        AllCreaturesOfEntryInRangeCheck(WorldObject const* pObject, uint32 uiEntry, float fMaxRange) : m_pObject(pObject), m_uiEntry(uiEntry), m_fRange(fMaxRange) {}
        bool operator() (Unit* pUnit)
        {
            if (pUnit->GetEntry() == m_uiEntry && m_pObject->IsWithinDist(pUnit,m_fRange,false))
                return true;

            return false;
        }

    private:
        WorldObject const* m_pObject;
        uint32 m_uiEntry;
        float m_fRange;
};

class PlayerAtMinimumRangeAway
{
    public:
        PlayerAtMinimumRangeAway(Unit const* unit, float fMinRange) : pUnit(unit), fRange(fMinRange) {}
        bool operator() (Player* pPlayer)
        {
            //No threat list check, must be done explicit if expected to be in combat with creature
            if (!pPlayer->IsGameMaster() && pPlayer->IsAlive() && !pUnit->IsWithinDist(pPlayer,fRange,false))
                return true;

            return false;
        }

    private:
        Unit const* pUnit;
        float fRange;
};
*/

#endif
