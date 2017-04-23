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

#include "CreatureAI.h"
#include "Creature.h"
#include "Player.h"
#include "VehicleDefines.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "PathGenerator.h"
#include "World.h"
#include "TargetedMovementGenerator.h"

template<class T, typename D>
TargetedMovementGenerator<T, D>::~TargetedMovementGenerator()
{
    delete _path;
}

template<class T, typename D>
bool TargetedMovementGenerator<T, D>::DoUpdate(T* owner, uint32 diff)
{
    if (!IsTargetValid() || !GetTarget()->IsInWorld())
        return false;

    if (!owner || !owner->IsAlive())
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting() || HasLostTarget(owner))
    {
        _interrupt = true;
        owner->StopMoving();
        return true;
    }

    if (_interrupt || _recalculateTravel)
    {
        _interrupt = false;
        SetTargetLocation(owner, true);
        return true;
    }

    bool targetMoved = false;
    _timer.Update(diff);
    if (!_interrupt && _timer.Passed())
    {
        _timer.Reset(100);

        float distance = owner->GetCombatReach() + sWorld->getRate(RATE_TARGET_POS_RECALCULATION_RANGE);
        if (owner->IsPet() && (owner->GetCharmerOrOwnerGUID() == GetTarget()->GetGUID()))
            distance = 1.f; // pet following owner

        G3D::Vector3 destination = owner->movespline->FinalDestination();
        if (owner->movespline->onTransport)
            if (TransportBase* transport = owner->GetDirectTransport())
                transport->CalculatePassengerPosition(destination.x, destination.y, destination.z);

        // First check distance
        if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->CanFly())
            targetMoved = !GetTarget()->IsWithinDist3d(destination.x, destination.y, destination.z, distance);
        else
            targetMoved = !GetTarget()->IsWithinDist2d(destination.x, destination.y, distance);

        // then, if the target is in range, check also Line of Sight.
        if (!targetMoved)
            targetMoved = !GetTarget()->IsWithinLOSInMap(owner);
    }

    if (targetMoved)
        SetTargetLocation(owner, true);
    else if (_speedChanged)
        SetTargetLocation(owner, false);

    if (!_targetReached && owner->movespline->Finalized())
    {
        MovementInform(owner);
        if (_angle == 0.f && !owner->HasInArc(0.01f, GetTarget()))
            owner->SetInFront(GetTarget());

        if (!_targetReached)
        {
            _targetReached = true;
            ReachTarget(owner);
        }
    }

    return true;
}

template<class T, typename D>
void TargetedMovementGenerator<T, D>::SetTargetLocation(T* owner, bool updateDestination)
{
    if (!IsTargetValid() || !GetTarget()->IsInWorld())
        return;

    if (!owner || !owner->IsAlive())
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting() || HasLostTarget(owner))
    {
        _interrupt = true;
        owner->StopMoving();
        return;
    }

    if (owner->GetTypeId() == TYPEID_UNIT && !GetTarget()->isInAccessiblePlaceFor(owner->ToCreature()))
    {
        owner->ToCreature()->SetCannotReachTarget(true);
        return;
    }

    float x, y, z;
    if (updateDestination || !_path)
    {
        if (!_offset)
        {
            if (GetTarget()->IsWithinDistInMap(owner, CONTACT_DISTANCE))
                return;

            GetTarget()->GetContactPoint(owner, x, y, z);
        }
        else
        {
            float distance = _offset + 1.0f;
            float size = owner->GetCombatReach();

            if (owner->IsPet() && GetTarget()->GetTypeId() == TYPEID_PLAYER)
            {
                distance = 1.0f;
                size = 1.0f;
            }

            if (GetTarget()->IsWithinDistInMap(owner, distance))
                return;

            GetTarget()->GetClosePoint(x, y, z, size, _offset, _angle);
        }
    }
    else
    {
        // the destination has not changed, we just need to refresh the path (usually speed change)
        G3D::Vector3 end = _path->GetEndPosition();
        x = end.x;
        y = end.y;
        z = end.z;
    }

    if (!_path)
        _path = new PathGenerator(owner);

    // allow pets to use shortcut if no path found when following their master
    bool forceDest = (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->IsPet() && owner->HasUnitState(UNIT_STATE_FOLLOW));

    bool result = _path->CalculatePath(x, y, z, forceDest);
    if (!result || (_path->GetPathType() & PATHFIND_NOPATH))
    {
        // can't reach target
        _recalculateTravel = true;
        if (owner->GetTypeId() == TYPEID_UNIT)
            owner->ToCreature()->SetCannotReachTarget(true);
        return;
    }

    _targetReached = false;
    _recalculateTravel = false;
    _speedChanged = false;

    AddUnitStateMove(owner);

    if (owner->GetTypeId() == TYPEID_UNIT)
        owner->ToCreature()->SetCannotReachTarget(false);

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(_path->GetPath());
    init.SetWalk(EnableWalking());
    // Using the same condition for facing target as the one that is used for SetInFront on movement end
    // - applies to ChaseMovementGenerator mostly
    if (_angle == 0.f)
        init.SetFacing(GetTarget());

    init.Launch();
}

template<class T, typename D>
bool TargetedMovementGenerator<T, D>::IsReachable() const
{
    return (_path) ? (_path->GetPathType() & PATHFIND_NORMAL) : true;
}

//---- ChaseMovementGenerator

template<class T>
void ChaseMovementGenerator<T>::DoInitialize(T*) { }

template<>
void ChaseMovementGenerator<Player>::DoInitialize(Player* owner)
{
    owner->AddUnitState(UNIT_STATE_CHASE);
    SetTargetLocation(owner, true);
}

template<>
void ChaseMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    owner->SetWalk(false);
    owner->AddUnitState(UNIT_STATE_CHASE);
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
void ChaseMovementGenerator<T>::ClearUnitStateMove(T* owner)
{
    owner->ClearUnitState(UNIT_STATE_CHASE_MOVE);
}

template<class T>
void ChaseMovementGenerator<T>::AddUnitStateMove(T* owner)
{
    owner->AddUnitState(UNIT_STATE_CHASE_MOVE);
}

template<class T>
bool ChaseMovementGenerator<T>::HasLostTarget(T* owner) const
{
    return owner->GetVictim() != TargetedMovementGeneratorBase::GetTarget();
}

template<class T>
void ChaseMovementGenerator<T>::ReachTarget(T* owner)
{
    ClearUnitStateMove(owner);

    if (owner->IsWithinMeleeRange(TargetedMovementGeneratorBase::GetTarget()))
        owner->Attack(TargetedMovementGeneratorBase::GetTarget(), true);

    if (owner->GetTypeId() == TYPEID_UNIT)
        owner->ToCreature()->SetCannotReachTarget(false);
}

template<class T>
void ChaseMovementGenerator<T>::MovementInform(T*) { }

template<>
void ChaseMovementGenerator<Creature>::MovementInform(Creature* owner)
{
    // Pass back the GUIDLow of the target. If it is pet's owner then PetAI will handle
    if (owner->AI())
        owner->AI()->MovementInform(CHASE_MOTION_TYPE, GetTarget()->GetGUID().GetCounter());
}

//---- FollowMovementGenerator

template<class T>
void FollowMovementGenerator<T>::UpdateSpeed(T*) { }

template<>
void FollowMovementGenerator<Player>::UpdateSpeed(Player* /*owner*/) { }

template<>
void FollowMovementGenerator<Creature>::UpdateSpeed(Creature* owner)
{
    // Pet only sync speed with owner
    // Make sure we are not in the process of a map change (IsInWorld)
    if (!owner->IsPet() || !owner->IsInWorld() || !IsTargetValid() || GetTarget()->GetGUID() != owner->GetOwnerGUID())
        return;

    owner->UpdateSpeed(MOVE_RUN);
    owner->UpdateSpeed(MOVE_WALK);
    owner->UpdateSpeed(MOVE_SWIM);
}

template<class T>
void FollowMovementGenerator<T>::DoInitialize(T* owner)
{
    owner->AddUnitState(UNIT_STATE_FOLLOW);
    UpdateSpeed(owner);
    TargetedMovementGenerator<T, FollowMovementGenerator<T>>::SetTargetLocation(owner, true);
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
void FollowMovementGenerator<T>::ClearUnitStateMove(T* owner)
{
    owner->ClearUnitState(UNIT_STATE_FOLLOW_MOVE);
}

template<class T>
void FollowMovementGenerator<T>::AddUnitStateMove(T* owner)
{
    owner->AddUnitState(UNIT_STATE_FOLLOW_MOVE);
}

template<class T>
void FollowMovementGenerator<T>::ReachTarget(T* owner)
{
    ClearUnitStateMove(owner);
}

template<>
bool FollowMovementGenerator<Creature>::EnableWalking() const
{
    return IsTargetValid() && GetTarget()->IsWalking();
}

template<>
bool FollowMovementGenerator<Player>::EnableWalking() const
{
    return false;
}

template<class T>
void FollowMovementGenerator<T>::MovementInform(T*) { }

template<>
void FollowMovementGenerator<Creature>::MovementInform(Creature* unit)
{
    // Pass back the GUIDLow of the target. If it is pet's owner then PetAI will handle
    if (unit->AI())
        unit->AI()->MovementInform(FOLLOW_MOTION_TYPE, GetTarget()->GetGUID().GetCounter());
}

//-----------------------------------------------//

template TargetedMovementGenerator<Player, ChaseMovementGenerator<Player> >::~TargetedMovementGenerator();
template TargetedMovementGenerator<Player, FollowMovementGenerator<Player> >::~TargetedMovementGenerator();
template TargetedMovementGenerator<Creature, ChaseMovementGenerator<Creature> >::~TargetedMovementGenerator();
template TargetedMovementGenerator<Creature, FollowMovementGenerator<Creature> >::~TargetedMovementGenerator();
template bool TargetedMovementGenerator<Player, ChaseMovementGenerator<Player> >::DoUpdate(Player*, uint32);
template bool TargetedMovementGenerator<Player, FollowMovementGenerator<Player> >::DoUpdate(Player*, uint32);
template bool TargetedMovementGenerator<Creature, ChaseMovementGenerator<Creature> >::DoUpdate(Creature*, uint32);
template bool TargetedMovementGenerator<Creature, FollowMovementGenerator<Creature> >::DoUpdate(Creature*, uint32);
template void TargetedMovementGenerator<Player, ChaseMovementGenerator<Player> >::SetTargetLocation(Player*, bool);
template void TargetedMovementGenerator<Player, FollowMovementGenerator<Player> >::SetTargetLocation(Player*, bool);
template void TargetedMovementGenerator<Creature, ChaseMovementGenerator<Creature> >::SetTargetLocation(Creature*, bool);
template void TargetedMovementGenerator<Creature, FollowMovementGenerator<Creature> >::SetTargetLocation(Creature*, bool);

template void ChaseMovementGenerator<Player>::DoFinalize(Player*);
template void ChaseMovementGenerator<Creature>::DoFinalize(Creature*);
template void ChaseMovementGenerator<Player>::DoReset(Player*);
template void ChaseMovementGenerator<Creature>::DoReset(Creature*);
template void ChaseMovementGenerator<Player>::ClearUnitStateMove(Player*);
template void ChaseMovementGenerator<Creature>::ClearUnitStateMove(Creature*);
template void ChaseMovementGenerator<Player>::AddUnitStateMove(Player*);
template void ChaseMovementGenerator<Creature>::AddUnitStateMove(Creature*);
template bool ChaseMovementGenerator<Player>::HasLostTarget(Player*) const;
template bool ChaseMovementGenerator<Creature>::HasLostTarget(Creature*) const;
template void ChaseMovementGenerator<Player>::ReachTarget(Player*);
template void ChaseMovementGenerator<Creature>::ReachTarget(Creature*);
template void ChaseMovementGenerator<Player>::MovementInform(Player*);

template void FollowMovementGenerator<Player>::DoInitialize(Player*);
template void FollowMovementGenerator<Creature>::DoInitialize(Creature*);
template void FollowMovementGenerator<Player>::DoFinalize(Player*);
template void FollowMovementGenerator<Creature>::DoFinalize(Creature*);
template void FollowMovementGenerator<Player>::DoReset(Player*);
template void FollowMovementGenerator<Creature>::DoReset(Creature*);
template void FollowMovementGenerator<Player>::ClearUnitStateMove(Player*);
template void FollowMovementGenerator<Creature>::ClearUnitStateMove(Creature*);
template void FollowMovementGenerator<Player>::AddUnitStateMove(Player*);
template void FollowMovementGenerator<Creature>::AddUnitStateMove(Creature*);
template void FollowMovementGenerator<Player>::ReachTarget(Player*);
template void FollowMovementGenerator<Creature>::ReachTarget(Creature*);
template void FollowMovementGenerator<Player>::MovementInform(Player*);
