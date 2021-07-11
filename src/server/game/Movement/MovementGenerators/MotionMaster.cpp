/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#include "MotionMaster.h"
#include "CreatureAISelector.h"
#include "Creature.h"
#include "Transport.h"

#include "ConfusedMovementGenerator.h"
#include "FleeingMovementGenerator.h"
#include "FearMovementGenerator.h"
#include "HomeMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "PointMovementGenerator.h"
#include "TargetedMovementGenerator.h"
#include "WaypointMovementGenerator.h"
#include "RandomMovementGenerator.h"

#include "MoveSpline.h"
#include "MoveSplineInit.h"

#include <cassert>

inline bool isStatic(MovementGenerator* mv)
{
    return (mv == &si_idleMovement);
}

void MotionMaster::Initialize()
{
    // stop current move
    if (!m_owner->IsStopped())
        m_owner->StopMoving();

    // clear ALL movement generators (including default)
    Clear(false, true);

    // set new default movement generator
    if (m_owner->IsCreature() && m_owner->IsAlive() && !m_owner->HasUnitState(UNIT_STAT_POSSESSED))
    {
        MovementGenerator* movement = FactorySelector::selectMovementGenerator(static_cast<Creature*>(m_owner));
        push(movement == nullptr ? &si_idleMovement : movement);
        top()->Initialize(*m_owner);
        if (top()->GetMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
            (static_cast<WaypointMovementGenerator<Creature>*>(top()))->InitializeWaypointPath(*(static_cast<Creature*>(m_owner)), 0, PATH_NO_PATH, 0, 0, 0, true);
    }
    else
        push(&si_idleMovement);

    // Pet movement after control movement spell.
    if (CharmInfo* ci = m_owner->GetCharmInfo())
    {
        ci->SetIsAtStay(false);
        ci->SetIsReturning(false);
        ci->SetIsFollowing(false);
    }
}

void MotionMaster::InitializeNewDefault(bool alwaysReplace)
{
    // This method changes the creature's default movement type
    // without interrupting the currently used movement generator
    
    if (empty())
    {
        Initialize();
        return;
    }

    Creature* pCreature = m_owner->ToCreature();
    if (!pCreature)
        return;

    MovementGeneratorType new_default = pCreature->GetDefaultMovementType();

    // Already using the same motion type as default
    if (!alwaysReplace && (size() == 1) && (top()->GetMovementGeneratorType() == new_default))
        return;

    // Get the current generator and eject it from the stack
    MovementGenerator* curr = top();
    pop();

    // Clear ALL other movement generators
    Clear(false, true);

    if (alwaysReplace || (curr->GetMovementGeneratorType() != new_default))
    {
        // Set new default movement generator
        if (!m_owner->HasUnitState(UNIT_STAT_POSSESSED))
        {
            MovementGenerator* movement = FactorySelector::selectMovementGenerator(pCreature);
            if (movement)
                new_default = movement->GetMovementGeneratorType();
            push(movement == nullptr ? &si_idleMovement : movement);
            top()->Initialize(*m_owner);
            if (top()->GetMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
                (static_cast<WaypointMovementGenerator<Creature>*>(top()))->InitializeWaypointPath(*(pCreature), 0, PATH_NO_PATH, 100, 0, 0, true);
        }
        else
            push(&si_idleMovement);

        // Restore the previous current generator, if its different from the new default
        if (curr->GetMovementGeneratorType() != new_default)
            push(curr);
        else
        {
            // Same as the new default, so we can delete it
            if (!m_expList)
                m_expList = new ExpireList();
            curr->Finalize(*m_owner);
            if (!isStatic(curr))
                m_expList->push_back(curr);
        }
    }
    else
        push(curr);
}

MotionMaster::~MotionMaster()
{
    // just deallocate movement generator, but do not Finalize since it may access to already deallocated owner's memory
    while (!empty())
    {
        MovementGenerator*  m = top();
        pop();
        if (!isStatic(m))
            delete m;
    }

    if (m_expList)
    {
        for (const auto mg : *m_expList)
        {
            if (!isStatic(mg))
                delete mg;
        }

        delete m_expList;
    }
}

void MotionMaster::UpdateMotion(uint32 diff)
{
    if (m_owner->HasUnitState(UNIT_STAT_CAN_NOT_MOVE))
        return;

    MANGOS_ASSERT(!empty());
    m_cleanFlag |= MMCF_UPDATE;

    if (!top()->Update(*m_owner, diff))
    {
        m_cleanFlag &= ~MMCF_UPDATE;
        MovementExpired();
    }
    else
        m_cleanFlag &= ~MMCF_UPDATE;

    if (m_expList)
    {
        for (const auto mg : *m_expList)
        {
            if (!isStatic(mg))
                delete mg;
        }

        delete m_expList;
        m_expList = nullptr;

        if (empty())
            Initialize();

        if (m_cleanFlag & MMCF_RESET)
        {
            top()->Reset(*m_owner);
            m_cleanFlag &= ~MMCF_RESET;
        }
    }
}

void MotionMaster::UpdateMotionAsync(uint32 diff)
{
    m_needsAsyncUpdate = false;
    if (m_owner->HasUnitState(UNIT_STAT_CAN_NOT_MOVE))
        return;

    MANGOS_ASSERT(!empty());
    m_cleanFlag |= MMCF_UPDATE;

    top()->UpdateAsync(*m_owner, diff);
}

void MotionMaster::DirectClean(bool reset, bool all)
{
    // Nostalrius: We need to clean top mvt gens, and call Finalize once it's done
    // because Finalize calls CreatureAI::MovementInform that can call MovePoint / ...

    typedef std::list<MovementGenerator*> MvtGenList;
    MvtGenList mvtGensToFinalize;
    while (all ? !empty() : size() > 1)
    {
        MovementGenerator* curr = top();
        pop();
        mvtGensToFinalize.push_back(curr);
    }
    if (!all && reset)
    {
        if (empty()) // Should not happen
            Initialize();
        MANGOS_ASSERT(!empty());
        top()->Reset(*m_owner);
    }
    for (MvtGenList::iterator it = mvtGensToFinalize.begin(); it != mvtGensToFinalize.end(); ++it)
    {
        (*it)->Finalize(*m_owner);
        if (!isStatic((*it)))
            delete(*it);
    }
}

void MotionMaster::DelayedClean(bool reset, bool all)
{
    if (reset)
        m_cleanFlag |= MMCF_RESET;
    else
        m_cleanFlag &= ~MMCF_RESET;

    if (empty() || (!all && size() == 1))
        return;

    if (!m_expList)
        m_expList = new ExpireList();

    typedef std::list<MovementGenerator*> MvtGenList;
    MvtGenList mvtGensToFinalize;
    while (all ? !empty() : size() > 1)
    {
        MovementGenerator* curr = top();
        pop();
        mvtGensToFinalize.push_back(curr);
    }
    for (const auto& it : mvtGensToFinalize)
    {
        it->Finalize(*m_owner);

        if (!isStatic(it))
            m_expList->push_back(it);
    }
}

void MotionMaster::DirectExpire(bool reset)
{
    if (empty() || size() == 1)
        return;

    MovementGenerator* curr = top();
    pop();

    // also drop stored under top() targeted motions
    typedef std::list<MovementGenerator*> MvtGenList;
    MvtGenList mvtGensToFinalize;
    while (!empty() && (top()->GetMovementGeneratorType() == CHASE_MOTION_TYPE || top()->GetMovementGeneratorType() == FOLLOW_MOTION_TYPE) && (curr->GetMovementGeneratorType() != DISTANCING_MOTION_TYPE))
    {
        MovementGenerator* temp = top();
        pop();
        mvtGensToFinalize.push_back(temp);
    }
    for (MvtGenList::iterator it = mvtGensToFinalize.begin(); it != mvtGensToFinalize.end(); ++it)
    {
        (*it)->Finalize(*m_owner);
        delete(*it);
    }
    // Store current top MMGen, as Finalize might push a new MMGen
    MovementGenerator* nowTop = empty() ? nullptr : top();
    // it can add another motions instead
    curr->Finalize(*m_owner);

    if (!isStatic(curr))
        delete curr;

    if (empty())
        Initialize();

    // Prevent reseting possible new pushed MMGen
    if (reset && top() == nowTop)
        top()->Reset(*m_owner);
}

void MotionMaster::DelayedExpire(bool reset)
{
    if (reset)
        m_cleanFlag |= MMCF_RESET;
    else
        m_cleanFlag &= ~MMCF_RESET;

    if (empty() || size() == 1)
        return;

    MovementGenerator* curr = top();
    pop();

    if (!m_expList)
        m_expList = new ExpireList();

    // also drop stored under top() targeted motions
    typedef std::list<MovementGenerator*> MvtGenList;
    MvtGenList mvtGensToFinalize;
    while (!empty() && (top()->GetMovementGeneratorType() == CHASE_MOTION_TYPE || top()->GetMovementGeneratorType() == FOLLOW_MOTION_TYPE) && (curr->GetMovementGeneratorType() != DISTANCING_MOTION_TYPE))
    {
        MovementGenerator* temp = top();
        pop();
        mvtGensToFinalize.push_back(temp);
    }
    for (const auto& it : mvtGensToFinalize)
    {
        it->Finalize(*m_owner);
        m_expList->push_back(it);
    }

    curr->Finalize(*m_owner);

    if (!isStatic(curr))
        m_expList->push_back(curr);
}

void MotionMaster::MoveIdle()
{
    if (empty() || !isStatic(top()))
        push(&si_idleMovement);
}

void MotionMaster::MoveRandom(bool use_current_position, float wander_distance, uint32 expire_time)
{
    if (!m_owner->IsCreature())
        sLog.outError("%s attempts to move random.", m_owner->GetGuidStr().c_str());
    else
    {
        DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s move random.", m_owner->GetGuidStr().c_str());
        Mutate(new RandomMovementGenerator(*static_cast<Creature*>(m_owner), use_current_position, wander_distance, expire_time));
    }
}

void MotionMaster::MoveTargetedHome()
{
    if (m_owner->HasUnitState(UNIT_STAT_LOST_CONTROL))
        return;

    Clear(false);

    if (m_owner->IsCreature() && !((Creature*)m_owner)->GetCharmerOrOwnerGuid())
    {
        // Manual exception for linked mobs
        if (m_owner->IsLinkingEventTrigger() && m_owner->GetMap()->GetCreatureLinkingHolder()->TryFollowMaster((Creature*)m_owner))
            DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s refollowed linked master", m_owner->GetGuidStr().c_str());
        else
        {
            if (m_owner->GetTransport())
                m_owner->GetTransport()->RemovePassenger(m_owner);

            DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s targeted home", m_owner->GetGuidStr().c_str());
            Mutate(new HomeMovementGenerator<Creature>());
        }
    }
    else if (m_owner->IsCreature() && ((Creature*)m_owner)->GetCharmerOrOwnerGuid())
    {
        if (Unit* target = ((Creature*)m_owner)->GetCharmerOrOwner())
        {
            DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s follow to %s", m_owner->GetGuidStr().c_str(), target->GetGuidStr().c_str());
            Mutate(new FollowMovementGenerator<Creature>(*target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE));
        }
        else
            DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s attempt but fail to follow owner", m_owner->GetGuidStr().c_str());
    }
    else
        sLog.outError("%s attempt targeted home", m_owner->GetGuidStr().c_str());
}

void MotionMaster::MoveConfused()
{
    DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s move confused", m_owner->GetGuidStr().c_str());

    if (m_owner->IsPlayer())
        Mutate(new ConfusedMovementGenerator<Player>());
    else
        Mutate(new ConfusedMovementGenerator<Creature>());
}

void MotionMaster::MoveChase(Unit* target, float dist, float angle)
{
    // ignore movement request if target not exist
    if (!target)
        return;

    DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s chase to %s", m_owner->GetGuidStr().c_str(), target->GetGuidStr().c_str());

    if (m_owner->IsPlayer())
        Mutate(new ChaseMovementGenerator<Player>(*target, dist, angle));
    else
    {
        // interrupt current movespline
        if (!m_owner->IsStopped())
            m_owner->StopMoving();
        
        Mutate(new ChaseMovementGenerator<Creature>(*target, dist, angle));
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, float angle)
{
    if (m_owner->HasUnitState(UNIT_STAT_LOST_CONTROL))
        return;

    Clear();

    // ignore movement request if target not exist
    if (!target)
        return;

    DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s follow to %s", m_owner->GetGuidStr().c_str(), target->GetGuidStr().c_str());

    if (m_owner->IsPlayer())
        Mutate(new FollowMovementGenerator<Player>(*target, dist, angle));
    else
        Mutate(new FollowMovementGenerator<Creature>(*target, dist, angle));
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z, uint32 options, float speed, float finalOrientation)
{
    DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s targeted point (Id: %u X: %f Y: %f Z: %f)", m_owner->GetGuidStr().c_str(), id, x, y, z);

    if (m_owner->IsPlayer())
        Mutate(new PointMovementGenerator<Player>(id, x, y, z, options, speed, finalOrientation));
    else
        Mutate(new PointMovementGenerator<Creature>(id, x, y, z, options, speed, finalOrientation));
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (m_owner->IsPlayer())
        sLog.outError("%s attempt to seek assistance", m_owner->GetGuidStr().c_str());
    else
    {
        DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s seek assistance (X: %f Y: %f Z: %f)",
                         m_owner->GetGuidStr().c_str(), x, y, z);
        Mutate(new AssistanceMovementGenerator(x, y, z));
    }
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (m_owner->IsPlayer())
        sLog.outError("%s attempt to call distract after assistance", m_owner->GetGuidStr().c_str());
    else
    {
        DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s is distracted after assistance call (Time: %u)",
                         m_owner->GetGuidStr().c_str(), time);
        Mutate(new AssistanceDistractMovementGenerator(time));
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s flee from %s", m_owner->GetGuidStr().c_str(), enemy->GetGuidStr().c_str());

    if (m_owner->IsPlayer())
        Mutate(new FleeingMovementGenerator<Player>(enemy->GetObjectGuid()));
    else
    {
        if (time)
            Mutate(new TimedFleeingMovementGenerator(enemy->GetObjectGuid(), time));
        else
            Mutate(new FleeingMovementGenerator<Creature>(enemy->GetObjectGuid()));
    }
}

void MotionMaster::MoveFeared(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    if (m_owner->IsPlayer())
        Mutate(new FearMovementGenerator<Player>(enemy->GetObjectGuid()));
    else
    {
        if (time)
            Mutate(new TimedFearMovementGenerator(enemy->GetObjectGuid(), time));
        else
            Mutate(new FearMovementGenerator<Creature>(enemy->GetObjectGuid()));
    }
}

void MotionMaster::MoveWaypointAsDefault(uint32 startPoint /*=0*/, uint32 source /*=0==PATH_NO_PATH*/, uint32 initialDelay /*=0*/, uint32 overwriteGuid /*=0*/, uint32 overwriteEntry /*=0*/, bool repeat /*=true*/)
{
    if (m_owner->IsCreature())
    {
        if (GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
        {
            sLog.outError("Creature %s (Entry %u) attempt to MoveWaypoint() but creature is already using waypoint", m_owner->GetGuidStr().c_str(), m_owner->GetEntry());
            return;
        }

        Creature* creature = (Creature*)m_owner;

        DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "Creature %s (Entry %u) start MoveWaypoint()", m_owner->GetGuidStr().c_str(), m_owner->GetEntry());
        WaypointMovementGenerator<Creature>* newWPMMgen = new WaypointMovementGenerator<Creature>(*creature);

        if (size() > 1)
        {
            // Get the current generator and eject it from the stack
            MovementGenerator* curr = top();
            pop();

            // Clear ALL other movement generators
            Clear(false, true);

            push(newWPMMgen); // add waypoint movement as default
            push(curr); // add back current generator on top
        }
        else
        {
            Clear(false, true);
            push(newWPMMgen);
        } 

        newWPMMgen->InitializeWaypointPath(*creature, startPoint, (WaypointPathOrigin)source, initialDelay, overwriteGuid, overwriteEntry, repeat);
    }
    else
        sLog.outError("Non-creature %s attempt to MoveWaypoint()", m_owner->GetGuidStr().c_str());
}

void MotionMaster::MoveWaypoint(uint32 startPoint /*=0*/, uint32 source /*=0==PATH_NO_PATH*/, uint32 initialDelay /*=0*/, uint32 overwriteGuid /*=0*/, uint32 overwriteEntry /*=0*/, bool repeat /*=true*/)
{
    if (m_owner->IsCreature())
    {
        if (GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
        {
            sLog.outError("Creature %s (Entry %u) attempt to MoveWaypoint() but creature is already using waypoint", m_owner->GetGuidStr().c_str(), m_owner->GetEntry());
            return;
        }

        Creature* creature = (Creature*)m_owner;

        DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "Creature %s (Entry %u) start MoveWaypoint()", m_owner->GetGuidStr().c_str(), m_owner->GetEntry());
        WaypointMovementGenerator<Creature>* newWPMMgen = new WaypointMovementGenerator<Creature>(*creature);
        Mutate(newWPMMgen);
        newWPMMgen->InitializeWaypointPath(*creature, startPoint, (WaypointPathOrigin)source, initialDelay, overwriteGuid, overwriteEntry, repeat);
    }
    else
        sLog.outError("Non-creature %s attempt to MoveWaypoint()", m_owner->GetGuidStr().c_str());
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (m_owner->IsPlayer())
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s taxi to (Path %u node %u)", m_owner->GetGuidStr().c_str(), path, pathnode);
            FlightPathMovementGenerator* mgen = new FlightPathMovementGenerator(sTaxiPathNodesByPath[path], pathnode);
            Mutate(mgen);
        }
        else
        {
            sLog.outError("%s attempt taxi to (nonexistent Path %u node %u)",
                          m_owner->GetGuidStr().c_str(), path, pathnode);
        }
    }
    else
    {
        sLog.outError("%s attempt taxi to (Path %u node %u)",
                      m_owner->GetGuidStr().c_str(), path, pathnode);
    }
}

void MotionMaster::MoveTaxiFlight()
{
    if (m_owner->IsPlayer())
    {
        TaxiPathNodeList const& path = m_owner->ToPlayer()->GetTaxi().GetTaxiPath();
        if (!path.empty())
        {
            uint32 foundPath = 0;
            std::stringstream debugString;
            debugString << m_owner->GetGuidStr().c_str() << " multiple taxi to ";
            for (uint32 nodeIndex = 0; nodeIndex < path.size(); ++nodeIndex)
            {
                if (path[nodeIndex].path != foundPath)
                {
                    foundPath = path[nodeIndex].path;
                    if (foundPath < sTaxiPathNodesByPath.size())
                        debugString << "(Path " << foundPath << ")";
                    else
                    {
                        sLog.outError("%s attempt taxi to (nonexistent Path %u)",
                            m_owner->GetGuidStr().c_str(), foundPath);
                        return;
                    }
                }
            }
            DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, debugString.str().c_str());
            FlightPathMovementGenerator* mgen = new FlightPathMovementGenerator(path);
            Mutate(mgen);
        }
        else
        {
            sLog.outError("%s attempt taxi on an empty path", m_owner->GetGuidStr().c_str());
        }
    }
    else
    {
        sLog.outError("%s attempt taxi multi path", m_owner->GetGuidStr().c_str());
    }
}

void MotionMaster::MoveDistract(uint32 timer)
{
    DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "%s distracted (timer: %u)", m_owner->GetGuidStr().c_str(), timer);
    DistractMovementGenerator* mgen = new DistractMovementGenerator(timer);
    Mutate(mgen);
}

void MotionMaster::Mutate(MovementGenerator* m)
{
    if (!empty())
    {
        switch (top()->GetMovementGeneratorType())
        {
            // Chase movement should not be preserved in most cases
            case CHASE_MOTION_TYPE:
            {
                if (m->GetMovementGeneratorType() == DISTANCING_MOTION_TYPE)
                    break;
            }
            // HomeMovement is not that important, delete it if meanwhile a new comes
            case HOME_MOTION_TYPE:
            // Distract and Distancing movement interrupted by any other movement
            case DISTRACT_MOTION_TYPE:
            case DISTANCING_MOTION_TYPE:
                MovementExpired(false);
                break;
        }

        if (!empty())
            top()->Interrupt(*m_owner);
    }

    m->Initialize(*m_owner);
    push(m);
}

void MotionMaster::PropagateSpeedChange()
{
    Impl::container_type::iterator it = Impl::c.begin();
    for (; it != end(); ++it)
        (*it)->UnitSpeedChanged();
}

bool MotionMaster::SetNextWaypoint(uint32 pointId)
{
    for (Impl::container_type::reverse_iterator rItr = Impl::c.rbegin(); rItr != Impl::c.rend(); ++rItr)
    {
        if ((*rItr)->GetMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
            return (static_cast<WaypointMovementGenerator<Creature>*>(*rItr))->SetNextWaypoint(pointId);
    }
    return false;
}

uint32 MotionMaster::getLastReachedWaypoint() const
{
    for (Impl::container_type::const_reverse_iterator rItr = Impl::c.rbegin(); rItr != Impl::c.rend(); ++rItr)
        if ((*rItr)->GetMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
            return (static_cast<WaypointMovementGenerator<Creature>*>(*rItr))->getLastReachedWaypoint();
    return 0;
}

char const* MotionMaster::GetMovementGeneratorTypeName(MovementGeneratorType generator)
{
    switch (generator)
    {
        case IDLE_MOTION_TYPE:
            return "IDLE_MOTION_TYPE";
        case RANDOM_MOTION_TYPE:
            return "RANDOM_MOTION_TYPE";
        case WAYPOINT_MOTION_TYPE:
            return "WAYPOINT_MOTION_TYPE";
        case MAX_DB_MOTION_TYPE:
            return "MAX_DB_MOTION_TYPE";
        case CONFUSED_MOTION_TYPE:
            return "CONFUSED_MOTION_TYPE";
        case CHASE_MOTION_TYPE:
            return "CHASE_MOTION_TYPE";
        case HOME_MOTION_TYPE:
            return "HOME_MOTION_TYPE";
        case FLIGHT_MOTION_TYPE:
            return "FLIGHT_MOTION_TYPE";
        case POINT_MOTION_TYPE:
            return "POINT_MOTION_TYPE";
        case FLEEING_MOTION_TYPE:
            return "FLEEING_MOTION_TYPE";
        case DISTRACT_MOTION_TYPE:
            return "DISTRACT_MOTION_TYPE";
        case ASSISTANCE_MOTION_TYPE:
            return "ASSISTANCE_MOTION_TYPE";
        case ASSISTANCE_DISTRACT_MOTION_TYPE:
            return "ASSISTANCE_DISTRACT_MOTION_TYPE";
        case TIMED_FLEEING_MOTION_TYPE:
            return "TIMED_FLEEING_MOTION_TYPE";
        case FOLLOW_MOTION_TYPE:
            return "FOLLOW_MOTION_TYPE";
        case EFFECT_MOTION_TYPE:
            return "EFFECT_MOTION_TYPE";
        case PATROL_MOTION_TYPE:
            return "PATROL_MOTION_TYPE";
        case CHARGE_MOTION_TYPE:
            return "CHARGE_MOTION_TYPE";
        case DISTANCING_MOTION_TYPE:
            return "DISTANCING_MOTION_TYPE";
    }

    return "UNKNOWN";
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
    if (empty())
        return IDLE_MOTION_TYPE;

    return top()->GetMovementGeneratorType();
}

void MotionMaster::GetUsedMovementGeneratorsList(std::vector<MovementGeneratorType>& list) const
{
    for (auto it = begin(); it != end(); it++)
        list.push_back((*it)->GetMovementGeneratorType());
}

void MotionMaster::GetWaypointPathInformation(std::ostringstream& oss) const
{
    for (Impl::container_type::const_reverse_iterator rItr = Impl::c.rbegin(); rItr != Impl::c.rend(); ++rItr)
    {
        if ((*rItr)->GetMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
        {
            static_cast<WaypointMovementGenerator<Creature>*>(*rItr)->GetPathInformation(oss);
            return;
        }
    }
}

bool MotionMaster::GetDestination(float &x, float &y, float &z)
{
    // Often used in motion gen, lock target movespline while checking in case
    // they are async updating their spline too. Don't blocking lock, otherwise
    // we deadlock if the owner is already locked and checking the user of
    // this function at the same time (interlocked deadlock). This is not a critical
    // function that MUST succeed, so better to fail if we cannot acquire the
    // lock. Example deadlock (same timestamp):
    //  2017-09-16 02:06:32 Targeted UpdateAsync::Acquiring movespline lock for Unit Pet (Petnumber: 87 Guid: 21) in map (0, 6) thread 3156
    //  2017-09-16 02:06:32 MotionMaster::Acquiring movespline lock for Unit Pet (Petnumber: 93 Guid: 22) in map (0, 6) thread 3156
    //  ...
    //  2017-09-16 02:06:32 Targeted UpdateAsync::Acquiring movespline lock for Unit Pet (Petnumber: 93 Guid: 22) in map (0, 6) thread 11156
    //  2017-09-16 02:06:32 MotionMaster::Acquiring movespline lock for Unit Pet (Petnumber: 87 Guid :21) in map (0, 6) thread 11156

    std::unique_lock<std::mutex> guard(m_owner->asyncMovesplineLock, std::try_to_lock);
    if (!guard.owns_lock())
        return false;

    if (m_owner->movespline->Finalized())
        return false;

    G3D::Vector3 const& dest = m_owner->movespline->FinalDestination();
    x = dest.x;
    y = dest.y;
    z = dest.z;
    return true;
}

void MotionMaster::UpdateFinalDistanceToTarget(float fDistance)
{
    if (!empty())
        top()->UpdateFinalDistance(fDistance);
}

void MotionMaster::MoveJump(float x, float y, float z, float horizontalSpeed, float max_height, uint32 id)
{
    // MOVE JUMP DOESN'T EXIST IN 1.12
    /*Movement::MoveSplineInit init(*m_owner);
    init.MoveTo(x,y,z);
    init.SetParabolic(max_height, 0, true);
    init.SetVelocity(horizontalSpeed);
    // TODO: Effet moche. Ameliorer !
    init.SetFall();
    init.Launch();
    Mutate(new EffectMovementGenerator(id));*/
}

void MotionMaster::MoveCharge(Unit* target, uint32 delay, bool triggerAutoAttack)
{
    if (m_owner->IsPlayer())
        Mutate(new ChargeMovementGenerator<Player>(*(m_owner->ToPlayer()), *target, delay, triggerAutoAttack));
    else
        Mutate(new ChargeMovementGenerator<Creature>(*(m_owner->ToCreature()), *target, delay, triggerAutoAttack));
}

bool MotionMaster::MoveDistance(Unit* pTarget, float distance)
{
    float x, y, z;
    pTarget->GetNearPoint(m_owner, x, y, z, 0, distance, pTarget->GetAngle(m_owner));
    
    if (z > (m_owner->GetPositionZ() + 10.0f))
        return false;

    if (!pTarget->IsWithinLOS(x, y, z, true, m_owner->GetCollisionHeight()))
        return false;

    if (m_owner->GetDistanceSqr(x, y, z) == 0.0f)
        return false;

    if (m_owner->IsPlayer())
        Mutate(new DistancingMovementGenerator<Player>(x, y, z));
    else
        Mutate(new DistancingMovementGenerator<Creature>(x, y, z));

    return true;
}

void MotionMaster::ClearType(MovementGeneratorType moveType)
{
    for (iterator it = begin(); it != end();)
    {
        if ((*it)->GetMovementGeneratorType() == moveType)
        {
            (*it)->Finalize(*m_owner);
            erase(it);
            it = begin();
        }
        else
            ++it;
    }
}

void MotionMaster::ReInitializePatrolMovement()
{
    for (iterator it = begin(); it != end(); it++)
    {
        if ((*it)->GetMovementGeneratorType() == PATROL_MOTION_TYPE)
        {
            PatrolMovementGenerator* pGenerator = static_cast<PatrolMovementGenerator*>((*it));
            pGenerator->InitPatrol(*((Creature*)m_owner));
            break;
        }
    }
}

void Creature::PauseOutOfCombatMovement(uint32 pauseTime)
{
    if (IsInCombat())
        return;

    switch (GetMotionMaster()->GetCurrentMovementGeneratorType())
    {
        case RANDOM_MOTION_TYPE:
        {
            if (!IsStopped())
                StopMoving();
            ((RandomMovementGenerator*)(GetMotionMaster()->GetCurrent()))->AddPauseTime(pauseTime);
            break;
        }
        case WAYPOINT_MOTION_TYPE:
        {
            if (!IsStopped())
                StopMoving();
            ((WaypointMovementGenerator<Creature>*)(GetMotionMaster()->GetCurrent()))->AddPauseTime(pauseTime);
            break;
        }
    }
}
