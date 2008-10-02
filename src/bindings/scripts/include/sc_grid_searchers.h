/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

//Used in:
//sc_creature.cpp - DoSelectLowestHpFriendly()
class MostHPMissingInRange
{
public:
    MostHPMissingInRange(Unit const* obj, float range, uint32 hp) : i_obj(obj), i_range(range), i_hp(hp) {}
    bool operator()(Unit* u)
    {
        if(u->isAlive() && u->isInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && u->GetMaxHealth() - u->GetHealth() > i_hp)
        {
            i_hp = u->GetMaxHealth() - u->GetHealth();
            return true;
        }
        return false;
    }
private:
    Unit const* i_obj;
    float i_range;
    uint32 i_hp;
};

//Used in:
//sc_creature.cpp - DoFindFriendlyCC()
class FriendlyCCedInRange
{
public:
    FriendlyCCedInRange(Unit const* obj, float range) : i_obj(obj), i_range(range) {}
    bool operator()(Unit* u)
    {
        if(u->isAlive() && u->isInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) &&
            (u->isFeared() || u->isCharmed() || u->isFrozen() || u->hasUnitState(UNIT_STAT_STUNDED) || u->hasUnitState(UNIT_STAT_STUNDED) || u->hasUnitState(UNIT_STAT_CONFUSED)))
        {
            return true;
        }
        return false;
    }
private:
    Unit const* i_obj;
    float i_range;
};

//Used in:
//sc_creature.cpp - DoFindFriendlyMissingBuff()
class FriendlyMissingBuffInRange
{
public:
    FriendlyMissingBuffInRange(Unit const* obj, float range, uint32 spellid) : i_obj(obj), i_range(range), i_spell(spellid) {}
    bool operator()(Unit* u)
    {
        if(u->isAlive() && u->isInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && 
            !(u->HasAura(i_spell, 0) || u->HasAura(i_spell, 1) || u->HasAura(i_spell, 2)))
        {
            return true;
        }
        return false;
    }
private:
    Unit const* i_obj;
    float i_range;
    uint32 i_spell;
};

//Used in:
//hyjalAI.cpp
class AllFriendlyCreaturesInGrid
{
public:
    AllFriendlyCreaturesInGrid(Unit const* obj) : pUnit(obj) {}
    bool operator() (Unit* u)
    {
        if(u->isAlive() && u->GetVisibility() == VISIBILITY_ON && u->IsFriendlyTo(pUnit))
            return true;

        return false;
    }

private:
    Unit const* pUnit;
};

//Used in:
//hyjalAI.cpp
class AllGameObjectsWithEntryInGrid
{
public:
    AllGameObjectsWithEntryInGrid(uint32 ent) : entry(ent) {}
    bool operator() (GameObject* g)
    {
        if(g->GetEntry() == entry)
            return true;

        return false;
    }
private:
    uint32 entry;
};

class AllCreaturesOfEntryInRange
{
public:
    AllCreaturesOfEntryInRange(Unit const* obj, uint32 ent, float ran) : pUnit(obj), entry(ent), range(ran) {}
    bool operator() (Unit* u)
    {
        if(u->GetEntry() == entry && pUnit->IsWithinDistInMap(u, range))
            return true;

        return false;
    }

private:
    Unit const* pUnit;
    uint32 entry;
    float range;
};

#endif
