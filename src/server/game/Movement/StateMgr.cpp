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
#include "ConfusedMovementGenerator.h"
#include "TargetedMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "Timer.h"
#include "StateMgr.h"
#include "Player.h"
#include "Creature.h"

static const class staticActionInfo
{
    public:
    staticActionInfo()
    {
        actionInfo[UNIT_ACTION_IDLE](UNIT_ACTION_PRIORITY_IDLE, UNIT_COMMAND_AI, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_NONSTACKABLE);
        actionInfo[UNIT_ACTION_DOWAYPOINTS](UNIT_ACTION_PRIORITY_DOWAYPOINTS, UNIT_COMMAND_AI, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_NONSTACKABLE);
        actionInfo[UNIT_ACTION_CHASE](UNIT_ACTION_PRIORITY_CHASE, UNIT_COMMAND_AI, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_NONSTACKABLE);
        actionInfo[UNIT_ACTION_ASSISTANCE](UNIT_ACTION_PRIORITY_ASSISTANCE, UNIT_COMMAND_AI, ACTION_TYPE_NONRESTOREABLE | ACTION_TYPE_NONSTACKABLE);
        actionInfo[UNIT_ACTION_CONFUSED](UNIT_ACTION_PRIORITY_CONFUSED, UNIT_COMMAND_AURA, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_STACKABLE);
        actionInfo[UNIT_ACTION_FEARED](UNIT_ACTION_PRIORITY_FEARED, UNIT_COMMAND_AURA, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_STACKABLE);
        actionInfo[UNIT_ACTION_ROOT](UNIT_ACTION_PRIORITY_ROOT, UNIT_COMMAND_AURA, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_STACKABLE);
        actionInfo[UNIT_ACTION_STUN](UNIT_ACTION_PRIORITY_STUN, UNIT_COMMAND_AURA, ACTION_TYPE_RESTOREABLE | ACTION_TYPE_STACKABLE);
        actionInfo[UNIT_ACTION_EFFECT](UNIT_ACTION_PRIORITY_EFFECT, UNIT_COMMAND_AURA, ACTION_TYPE_NONRESTOREABLE | ACTION_TYPE_NONSTACKABLE);
    }

    const StaticActionInfo& operator[](UnitActionId i) const { return actionInfo[i];}

    private:
    StaticActionInfo actionInfo[UNIT_ACTION_END];
} staticActionInfo;

class StunnedState : public IdleMovementGenerator
{
public:

    const char* Name() const { return "<Stunned>"; }
    void Interrupt(Unit &unit)
    {
        Unit* const target = &unit;

        target->ClearUnitState(UNIT_STATE_STUNNED);
        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        target->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);

        WorldPacket data(SMSG_FORCE_MOVE_UNROOT, target->GetPackGUID().size() + 4);
        data.append(target->GetPackGUID());
        data << uint32(0);
        target->SendMessageToSet(&data, true);
    }
    void Reset(Unit &unit)
    {
        Unit* const target = &unit;

        target->AddUnitState(UNIT_STATE_STUNNED);
        target->RemoveUnitMovementFlag(MOVEMENTFLAG_MASK_MOVING);
        target->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

        target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);

        // Creature specific
        if (target->GetTypeId() != TYPEID_PLAYER)
            target->StopMoving();
        else
            target->SetStandState(UNIT_STAND_STATE_STAND);// in 1.5 client

        WorldPacket data(SMSG_FORCE_MOVE_ROOT, target->GetPackGUID().size() + 4);
        data.append(target->GetPackGUID());
        data << uint32(0);
        target->SendMessageToSet(&data, true);
    }

    void Initialize(Unit &unit)
    {
       Reset(unit);
    }

    void Finalize(Unit &unit)
    {
        Interrupt(unit);
    }

};

class RootState : public IdleMovementGenerator
{
public:

    const char* Name() const { return "<Rooted>"; }
    void Interrupt(Unit &unit)
    {
        Unit* const target = &unit;

        target->ClearUnitState(UNIT_STATE_ROOT);
        target->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);

        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            WorldPacket data(SMSG_FORCE_MOVE_UNROOT, target->GetPackGUID().size() + 4);
            data.append(target->GetPackGUID());
            data << target->GetUnitStateMgr().GetCounter(UNIT_ACTION_ROOT);
            target->SendMessageToSet(&data, true);
        }
        else
        {
            WorldPacket data(SMSG_SPLINE_MOVE_UNROOT, target->GetPackGUID().size());
            data.append(target->GetPackGUID());
            target->SendMessageToSet(&data, true);
        }
    }
    void Reset(Unit &unit)
    {
        Unit* const target = &unit;

        target->RemoveUnitMovementFlag(MOVEMENTFLAG_MASK_MOVING);
        target->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
        target->AddUnitState(UNIT_STATE_ROOT);

        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            WorldPacket data(SMSG_FORCE_MOVE_ROOT, target->GetPackGUID().size() + 4);
            data.append(target->GetPackGUID());
            data << target->GetUnitStateMgr().GetCounter(UNIT_ACTION_ROOT);
            target->SendMessageToSet(&data, true);
        }
        else
        {
            target->StopMoving();
            WorldPacket data(SMSG_SPLINE_MOVE_ROOT, target->GetPackGUID().size());
            data.append(target->GetPackGUID());
            target->SendMessageToSet(&data, true);
        }
    }
    void Initialize(Unit &unit)
    {
        Reset(unit);
    }

    void Finalize(Unit &unit)
    {
        Interrupt(unit);
    }
};

UnitActionPtr UnitStateMgr::CreateStandartState(UnitActionId stateId)
{
    UnitActionPtr state = UnitActionPtr(NULL);
    switch (stateId)
    {
        case UNIT_ACTION_FEARED:
        case UNIT_ACTION_CONFUSED:
            break;
        case UNIT_ACTION_STUN:
            state = UnitActionPtr(new StunnedState());
            break;
        case UNIT_ACTION_ROOT:
            state = UnitActionPtr(new RootState());
            break;
        //case UNIT_ACTION_CHASE:   // related to MotionMaster only
        //    break;
        default:
            break;
    }

    if (!state)
        state = UnitActionPtr(new IdleMovementGenerator());

    return state;
}

UnitStateMgr::UnitStateMgr(Unit* owner) : m_owner(owner)
{
    for (int32 i = UNIT_ACTION_IDLE; i != UNIT_ACTION_END; ++i)
        m_stateCounter[i] = 0;

    InitDefaults();
}

UnitStateMgr::~UnitStateMgr()
{
}

void UnitStateMgr::InitDefaults()
{
    m_oldAction = NULL;

    m_actions.clear();
    PushAction(UNIT_ACTION_IDLE, UNIT_ACTION_PRIORITY_NONE, ACTION_TYPE_RESTOREABLE);
}

void UnitStateMgr::Update(uint32 diff)
{
    ActionInfo* action = CurrentState();

    if (m_oldAction != action)
    {
        action->Initialize(this);
        m_oldAction = action;
    }

    if (!action->Update(this, diff))
        DropAction(action->priority);
}

void UnitStateMgr::DropAction(UnitActionId actionId)
{
    DropAction(actionId, staticActionInfo[actionId].priority);
}

void UnitStateMgr::DropAction(UnitActionId actionId, UnitActionPriority priority)
{
    UnitActionStorage::iterator itr = m_actions.find(priority);
    if (itr != m_actions.end() && itr->second.Id == actionId)
        DropAction(priority);
}

void UnitStateMgr::DropAction(UnitActionPriority priority, bool all /*=false*/)
{
    if (priority <= UNIT_ACTION_PRIORITY_NONE)
        return;

    TRINITY_WRITE_GUARD(ACE_RW_Mutex, _checkStateLock);

    ActionInfo* currentInfo = CurrentState();

    UnitActionStorage::iterator itr = m_actions.find(priority);
    while (itr != m_actions.end())
    {
        bool finalize = false;
        UnitActionPtr currentAction = currentInfo->Action();
        if (&itr->second == currentInfo)
        {
            m_oldAction = NULL;
            finalize = true;
        }

        m_actions.erase(itr);

        itr = m_actions.find(priority);
        if (finalize)
        {
            sLog->outDebug(LOG_FILTER_STATEMGR, "UnitStateMgr: %s finalize action %s", GetOwnerStr().c_str(), currentAction->Name());
            currentAction->Finalize(*GetOwner());
        }

        if (!all) break;
        // UnitAction auto-delete.
    }
}

void UnitStateMgr::PushAction(UnitActionId actionId)
{
    UnitActionPtr state = CreateStandartState(actionId);
    PushAction(actionId, state, staticActionInfo[actionId].priority, staticActionInfo[actionId].source, staticActionInfo[actionId].type);
}

void UnitStateMgr::PushAction(UnitActionId actionId, UnitActionPriority priority, uint32 type)
{
    UnitActionPtr state = CreateStandartState(actionId);
    PushAction(actionId, state, priority, staticActionInfo[actionId].source, type);
}

void UnitStateMgr::PushAction(UnitActionId actionId, UnitActionPtr state)
{
    PushAction(actionId, state, staticActionInfo[actionId].priority, staticActionInfo[actionId].source, staticActionInfo[actionId].type);
}

void UnitStateMgr::PushAction(UnitActionId actionId, UnitActionPtr state, UnitActionPriority priority, UnitCommandSource source, uint32 type)
{
    ActionInfo* currentInfo = CurrentState();
    UnitActionPriority _priority = currentInfo ? currentInfo->priority : UNIT_ACTION_PRIORITY_IDLE;
    if (currentInfo && _priority <= priority)
    {
        if (currentInfo->IsType(ACTION_TYPE_NONRESTOREABLE))
            DropAction(currentInfo->priority);
        else if (_priority < priority || (currentInfo->IsType(ACTION_TYPE_STACKABLE) && (type & ACTION_TYPE_STACKABLE)))
            currentInfo->Interrupt(this);
    }

    UnitActionStorage::iterator itr = m_actions.find(priority);
    if (itr == m_actions.end() || itr->second.IsType(ACTION_TYPE_NONSTACKABLE) || (type & ACTION_TYPE_NONSTACKABLE))
        DropAction(priority, true);

    m_actions.insert(UnitActionStorage::value_type(priority,ActionInfo(actionId, state, priority, source, type)));

    IncreaseCounter(actionId);
}

ActionInfo* UnitStateMgr::GetAction(UnitActionPriority priority)
{
    UnitActionStorage::iterator itr = m_actions.find(priority);
    if (itr != m_actions.end())
        return &itr->second;
    return NULL;
}

UnitActionPtr UnitStateMgr::CurrentAction()
{
    return CurrentState() ? CurrentState()->action : UnitActionPtr();
}

ActionInfo* UnitStateMgr::CurrentState()
{
    return m_actions.empty() ? NULL : &m_actions.rbegin()->second;
}

void UnitStateMgr::DropAllStates()
{
    for (int32 i = UNIT_ACTION_PRIORITY_IDLE; i != UNIT_ACTION_PRIORITY_END; ++i)
        DropAction(UnitActionPriority(i), true);
}

void UnitStateMgr::DropAllAIStates()
{
    for (int32 i = UNIT_ACTION_PRIORITY_IDLE; i != UNIT_ACTION_PRIORITY_END; ++i)
    {
        UnitActionStorage::iterator itr = m_actions.find(UnitActionPriority(i));
        if (itr != m_actions.end() && itr->second.source == UNIT_COMMAND_AI)
            DropAction(UnitActionPriority(i), true);
    }
}

void UnitStateMgr::DropAllAIStatesExcept(UnitActionPriority priority)
{
    for (int32 i = UNIT_ACTION_PRIORITY_IDLE; i != UNIT_ACTION_PRIORITY_END; ++i)
    {
        UnitActionStorage::iterator itr = m_actions.find(UnitActionPriority(i));
        if (i != priority && itr != m_actions.end() && itr->second.source == UNIT_COMMAND_AI)
            DropAction(UnitActionPriority(i), true);
    }
}

std::string const UnitStateMgr::GetOwnerStr()
{
    if (GetOwner()->IsInWorld())
    {
        std::ostringstream str;
        str << GetOwner()->GetGUIDLow();
        return str.str();
    }

    return "<Uninitialized>"; 
};

bool ActionInfo::operator < (const ActionInfo& val) const
{
    if (priority > val.priority)
        return true;
    return false;
};

void ActionInfo::Delete()
{
    delete this;
}

void ActionInfo::Initialize(UnitStateMgr* mgr)
{
    TRINITY_READ_GUARD(ACE_RW_Mutex, mgr->_checkStateLock);
    if (!action)
        return;

    if (!initialized)
    {
        sLog->outDebug(LOG_FILTER_STATEMGR, "ActionInfo: %s initialize action %s", mgr->GetOwnerStr().c_str(), TypeName());
        initialized = true;
        action->Initialize(*mgr->GetOwner());
    }
    else
    {
        sLog->outDebug(LOG_FILTER_TSCR, "ActionInfo: %s reset action %s", mgr->GetOwnerStr().c_str(), TypeName());
        action->Reset(*mgr->GetOwner());
    }
}

void ActionInfo::Finalize(UnitStateMgr* mgr)    // Not used
{
    if (!initialized)
        return;
    sLog->outDebug(LOG_FILTER_STATEMGR, "ActionInfo: %s finalize action %s", mgr->GetOwnerStr().c_str(), TypeName());

    TRINITY_READ_GUARD(ACE_RW_Mutex, mgr->_checkStateLock);
    if (action)
        action->Finalize(*mgr->GetOwner());
}

void ActionInfo::Interrupt(UnitStateMgr* mgr)
{
    if (!initialized)
        return;
    sLog->outDebug(LOG_FILTER_STATEMGR, "ActionInfo: %s interrupt action %s", mgr->GetOwnerStr().c_str(), TypeName());

    TRINITY_READ_GUARD(ACE_RW_Mutex, mgr->_checkStateLock);
    if (action)
        action->Interrupt(*mgr->GetOwner());
}

bool ActionInfo::Update(UnitStateMgr* mgr, uint32 diff)
{
    TRINITY_READ_GUARD(ACE_RW_Mutex, mgr->_checkStateLock);
    if (action)
        return action->Update(*mgr->GetOwner(), diff);
    else
        return false;
}

const char* ActionInfo::TypeName() const 
{
    return (action ? action->Name() : "<empty>");
}
