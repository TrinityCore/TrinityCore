/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "ByteBuffer.h"
#include "TargetedMovementGenerator.h"
#include "Errors.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "World.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Player.h"
#include "VehicleDefines.h"

template<class T, typename D>
TargetedMovementGeneratorMedium<T, D>::~TargetedMovementGeneratorMedium()
{
    delete m_path;
}

template<class T, typename D>
void TargetedMovementGeneratorMedium<T, D>::SetTargetLocation(T* owner, bool updateDestination)
{
    if (!m_target.isValid() || !m_target->IsInWorld())
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
        return;

    if (owner->GetTypeId() == TYPEID_UNIT && !m_target->isInAccessiblePlaceFor(owner->ToCreature()))
        return;

    if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->IsFocusing(nullptr, true))
        return;

    float x, y, z;

    if (updateDestination || !m_path)
    {
        if (!m_offset)
        {
            // to nearest contact position
            m_target->GetContactPoint(owner, x, y, z);
        }
        else
        {
            float dist;
            float size;

            // Pets need special handling.
            // We need to subtract GetObjectSize() because it gets added back further down the chain
            //  and that makes pets too far away. Subtracting it allows pets to properly
            //  be (GetCombatReach() + m_offset) away.
            // Only applies when m_target is pet's owner otherwise pets and mobs end up
            //   doing a "dance" while fighting
            if (owner->IsPet() && m_target->GetTypeId() == TYPEID_PLAYER)
            {
                dist = m_target->GetCombatReach();
                size = m_target->GetCombatReach() - m_target->GetObjectSize();
            }
            else
            {
                dist = m_offset + 1.0f;
                size = owner->GetObjectSize();
            }

            if (m_target->IsWithinDistInMap(owner, dist))
                return;

            // to at m_offset distance from target and m_angle from target facing
            m_target->GetClosePoint(x, y, z, size, m_offset, m_angle);
        }
    }
    else
    {
        // the destination has not changed, we just need to refresh the path (usually speed change)
        G3D::Vector3 end = m_path->GetEndPosition();
        x = end.x;
        y = end.y;
        z = end.z;
    }

    if (!m_path)
        m_path = new PathGenerator(owner);

    // allow pets to use shortcut if no path found when following their master
    bool forceDest = (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->IsPet()
        && owner->HasUnitState(UNIT_STATE_FOLLOW));

    bool result = m_path->CalculatePath(x, y, z, forceDest);
    if (!result || (m_path->GetPathType() & PATHFIND_NOPATH))
    {
        // Cant reach target
        m_recalculateTravel = true;
        return;
    }

    AddUnitStateMove(owner);
    m_targetReached = false;
    m_recalculateTravel = false;
    owner->AddUnitState(UNIT_STATE_CHASE);

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(m_path->GetPath());
    init.SetWalk(((D*)this)->EnableWalking());
    // Using the same condition for facing target as the one that is used for SetInFront on movement end
    // - applies to ChaseMovementGenerator mostly
    if (m_angle == 0.f)
        init.SetFacing(m_target.getTarget());

    init.Launch();
}

template<class T, typename D>
bool TargetedMovementGeneratorMedium<T, D>::DoUpdate(T* owner, uint32 time_diff)
{
    if (!m_target.isValid() || !m_target->IsInWorld())
        return false;

    if (!owner || !owner->IsAlive())
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        ClearUnitStateMove(owner);
        return true;
    }

    // prevent crash after creature killed pet
    if (static_cast<D*>(this)->HasLostTarget(owner))
    {
        ClearUnitStateMove(owner);
        return true;
    }

    m_interrupt = false;
    bool targetMoved = false;
    m_recheckDistance.Update(time_diff);
    if (m_recheckDistance.Passed())
    {
        m_recheckDistance.Reset(100);
        //More distance let have better performance, less distance let have more sensitive reaction at target move.
        float allowed_dist = owner->GetCombatReach() + sWorld->getRate(RATE_TARGET_POS_RECALCULATION_RANGE);
        G3D::Vector3 dest = owner->movespline->FinalDestination();
        if (owner->movespline->onTransport)
            if (TransportBase* transport = owner->GetDirectTransport())
                transport->CalculatePassengerPosition(dest.x, dest.y, dest.z);

        // First check distance
        if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->CanFly())
            targetMoved = !m_target->IsWithinDist3d(dest.x, dest.y, dest.z, allowed_dist);
        else
            targetMoved = !m_target->IsWithinDist2d(dest.x, dest.y, allowed_dist);

        // then, if the target is in range, check also Line of Sight.
        if (!targetMoved)
            targetMoved = !m_target->IsWithinLOSInMap(owner);
    }

    if (m_recalculateTravel || targetMoved)
        SetTargetLocation(owner, targetMoved);

    if (owner->movespline->Finalized())
    {
        static_cast<D*>(this)->MovementInform(owner);
        if (m_angle == 0.f && !owner->HasInArc(0.01f, m_target.getTarget()))
            owner->SetInFront(m_target.getTarget());

        if (!m_targetReached)
        {
            m_targetReached = true;
            static_cast<D*>(this)->HasReachedTarget(owner);
        }
    }

    return true;
}

template<class T, typename D>
void TargetedMovementGeneratorMedium<T, D>::DoInterrupt(T* owner)
{
    if (!m_interrupt && !owner->movespline->Finalized())
    {
        ClearUnitStateMove(owner);
        Movement::MoveSplineInit init(owner);
        init.Stop();
    }

    m_interrupt = true;
}

//---- ChaseMovementGenerator

template<class T>
void ChaseMovementGenerator<T>::HasReachedTarget(T* owner)
{
    if (owner->IsWithinMeleeRange(this->m_target.getTarget()))
        owner->Attack(this->m_target.getTarget(), true);
}

template<class T>
void ChaseMovementGenerator<T>::DoInitialize(T*) { }

template<>
void ChaseMovementGenerator<Player>::DoInitialize(Player* owner)
{
    owner->AddUnitState(UNIT_STATE_CHASE | UNIT_STATE_CHASE_MOVE);
    SetTargetLocation(owner, true);
}

template<>
void ChaseMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    owner->SetWalk(false);
    owner->AddUnitState(UNIT_STATE_CHASE | UNIT_STATE_CHASE_MOVE);
    SetTargetLocation(owner, true);
}

template<class T>
void ChaseMovementGenerator<T>::DoFinalize(T* owner)
{
    owner->ClearUnitState(UNIT_STATE_CHASE | UNIT_STATE_CHASE_MOVE);
}

template<class T>
void ChaseMovementGenerator<T>::DoReset(T* owner)
{
    DoInitialize(owner);
}

template<class T>
void ChaseMovementGenerator<T>::MovementInform(T* /*owner*/) { }

template<>
void ChaseMovementGenerator<Creature>::MovementInform(Creature* owner)
{
    // Pass back the GUIDLow of the target. If it is pet's owner then PetAI will handle
    if (owner->AI())
        owner->AI()->MovementInform(CHASE_MOTION_TYPE, m_target.getTarget()->GetGUID().GetCounter());
}

template<>
void ChaseMovementGenerator<Player>::MovementInform(Player* /*owner*/) { }

//---- FollowMovementGenerator

template<>
bool FollowMovementGenerator<Creature>::EnableWalking() const
{
    return m_target.isValid() && m_target->IsWalking();
}

template<>
bool FollowMovementGenerator<Player>::EnableWalking() const
{
    return false;
}

template<class T>
void FollowMovementGenerator<T>::UpdateSpeed(T*) { }

template<>
void FollowMovementGenerator<Player>::UpdateSpeed(Player* /*owner*/) { }

template<>
void FollowMovementGenerator<Creature>::UpdateSpeed(Creature* owner)
{
    // pet only sync speed with owner
    /// Make sure we are not in the process of a map change (IsInWorld)
    if (!owner->IsPet() || !owner->IsInWorld() || !m_target.isValid() || m_target->GetGUID() != owner->GetOwnerGUID())
        return;

    owner->UpdateSpeed(MOVE_RUN, true);
    owner->UpdateSpeed(MOVE_WALK, true);
    owner->UpdateSpeed(MOVE_SWIM, true);
}

template<class T>
void FollowMovementGenerator<T>::DoInitialize(T*) { }

template<>
void FollowMovementGenerator<Player>::DoInitialize(Player* owner)
{
    owner->AddUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_FOLLOW_MOVE);
    UpdateSpeed(owner);
    SetTargetLocation(owner, true);
}

template<>
void FollowMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    owner->AddUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_FOLLOW_MOVE);
    UpdateSpeed(owner);
    SetTargetLocation(owner, true);
}

template<class T>
void FollowMovementGenerator<T>::DoFinalize(T* owner)
{
    owner->ClearUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_FOLLOW_MOVE);
    UpdateSpeed(owner);
}

template<class T>
void FollowMovementGenerator<T>::DoReset(T* owner)
{
    DoInitialize(owner);
}

template<class T>
void FollowMovementGenerator<T>::MovementInform(T* /*unit*/) { }

template<>
void FollowMovementGenerator<Creature>::MovementInform(Creature* unit)
{
    // Pass back the GUIDLow of the target. If it is pet's owner then PetAI will handle
    if (unit->AI())
        unit->AI()->MovementInform(FOLLOW_MOTION_TYPE, m_target.getTarget()->GetGUID().GetCounter());
}

template<>
void FollowMovementGenerator<Player>::MovementInform(Player* /*owner*/) { }

//---- Templates

template TargetedMovementGeneratorMedium<Player, ChaseMovementGenerator<Player> >::~TargetedMovementGeneratorMedium();
template TargetedMovementGeneratorMedium<Player, FollowMovementGenerator<Player> >::~TargetedMovementGeneratorMedium();
template TargetedMovementGeneratorMedium<Creature, ChaseMovementGenerator<Creature> >::~TargetedMovementGeneratorMedium();
template TargetedMovementGeneratorMedium<Creature, FollowMovementGenerator<Creature> >::~TargetedMovementGeneratorMedium();
template void TargetedMovementGeneratorMedium<Player, ChaseMovementGenerator<Player> >::SetTargetLocation(Player*, bool);
template void TargetedMovementGeneratorMedium<Player, FollowMovementGenerator<Player> >::SetTargetLocation(Player*, bool);
template void TargetedMovementGeneratorMedium<Creature, ChaseMovementGenerator<Creature> >::SetTargetLocation(Creature*, bool);
template void TargetedMovementGeneratorMedium<Creature, FollowMovementGenerator<Creature> >::SetTargetLocation(Creature*, bool);
template bool TargetedMovementGeneratorMedium<Player, ChaseMovementGenerator<Player> >::DoUpdate(Player*, uint32);
template bool TargetedMovementGeneratorMedium<Player, FollowMovementGenerator<Player> >::DoUpdate(Player*, uint32);
template bool TargetedMovementGeneratorMedium<Creature, ChaseMovementGenerator<Creature> >::DoUpdate(Creature*, uint32);
template bool TargetedMovementGeneratorMedium<Creature, FollowMovementGenerator<Creature> >::DoUpdate(Creature*, uint32);
template void TargetedMovementGeneratorMedium<Player, ChaseMovementGenerator<Player> >::DoInterrupt(Player*);
template void TargetedMovementGeneratorMedium<Player, FollowMovementGenerator<Player> >::DoInterrupt(Player*);
template void TargetedMovementGeneratorMedium<Creature, ChaseMovementGenerator<Creature> >::DoInterrupt(Creature*);
template void TargetedMovementGeneratorMedium<Creature, FollowMovementGenerator<Creature> >::DoInterrupt(Creature*);

template void ChaseMovementGenerator<Player>::HasReachedTarget(Player*);
template void ChaseMovementGenerator<Creature>::HasReachedTarget(Creature*);
template void ChaseMovementGenerator<Player>::DoFinalize(Player*);
template void ChaseMovementGenerator<Creature>::DoFinalize(Creature*);
template void ChaseMovementGenerator<Player>::DoReset(Player*);
template void ChaseMovementGenerator<Creature>::DoReset(Creature*);

template void FollowMovementGenerator<Player>::DoFinalize(Player*);
template void FollowMovementGenerator<Creature>::DoFinalize(Creature*);
template void FollowMovementGenerator<Player>::DoReset(Player*);
template void FollowMovementGenerator<Creature>::DoReset(Creature*);
