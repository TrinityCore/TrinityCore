/*
 * Copyright (C) 2009-2012 /dev/rsa for MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
/* StateMgr based on idea and part of code from SilverIce (http:://github.com/SilverIce
*/
#ifndef _STATEMGR_H
#define _STATEMGR_H

#include "Common.h"
#include "MotionMaster.h"
#include "StateMgr_Impl.h"
#include "MovementGenerator.h"
#include "Log.h"
#include <sstream>
#include <algorithm>
#pragma once

class Unit;
class UnitStateMgr;

typedef ACE_Refcounted_Auto_Ptr<UnitAction,ACE_Null_Mutex> UnitActionPtr;

struct ActionInfo
{
    ActionInfo(UnitActionId _Id, UnitActionPtr _action, UnitActionPriority _priority, UnitCommandSource _source, uint32 _type, bool _initialized = false)
        : Id(_Id), action(_action), priority(_priority), source(_source), type(_type), initialized(_initialized)
    {
    }
    ~ActionInfo()
    {
    };

    bool operator < (const ActionInfo& val) const;
    void Delete();
    void Initialize(UnitStateMgr* mgr);
    void Finalize(UnitStateMgr* mgr);
    void Interrupt(UnitStateMgr* mgr);
    bool Update(UnitStateMgr* mgr, uint32 diff);
    UnitActionPtr Action() { return action; };

    const char* TypeName() const;
    bool IsType (ActionType _type) { return (type & _type); }

    UnitActionId       Id;
    UnitActionPtr      action;
    UnitActionPriority priority;
    uint32             type;
    UnitCommandSource  source;
    bool               initialized;
};

typedef std::multimap<UnitActionPriority, ActionInfo> UnitActionStorage;

class UnitStateMgr
{

protected:
    UnitStateMgr(const UnitStateMgr&);
    UnitStateMgr& operator = (const UnitStateMgr&);

public:
    explicit UnitStateMgr(Unit* owner);
    ~UnitStateMgr();

    void InitDefaults();

    void Update(uint32 diff);

    static UnitActionPtr CreateStandartState(UnitActionId stateId);

    void DropAction(UnitActionId actionId);
    void DropAction(UnitActionId actionId, UnitActionPriority priority);

    void DropAllStates();
    void DropAllAIStates();
    void DropAllAIStatesExcept(UnitActionPriority priority);

    void PushAction(UnitActionId actionId);
    void PushAction(UnitActionId actionId, UnitActionPtr state);
    void PushAction(UnitActionId actionId, UnitActionPriority priority, uint32 type = ACTION_TYPE_NONRESTOREABLE);
    void PushAction(UnitActionId actionId, UnitActionPtr state, UnitActionPriority priority, UnitCommandSource source, uint32 type);

    ActionInfo* GetAction(UnitActionPriority priority);

    UnitActionPtr CurrentAction();
    ActionInfo*   CurrentState();

    UnitActionPtr GetCurrentState() const;
    Unit*         GetOwner() const  { return m_owner; };

    // State counters
    uint32 const&     GetCounter(UnitActionId id) { return m_stateCounter[id]; };
    void              IncreaseCounter(UnitActionId id) { ++m_stateCounter[id]; };

    std::string const GetOwnerStr();

    ACE_RW_Mutex _checkStateLock;
private:
    void DropAction(UnitActionPriority priority, bool all = false);
    UnitActionStorage m_actions;
    Unit*             m_owner;
    ActionInfo*       m_oldAction;
    uint32            m_stateCounter[UNIT_ACTION_END];
};

#endif
