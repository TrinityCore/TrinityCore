/*
 *
 */

#include "Creature.h"
#include "CreatureAI.h"
#include "FearMovementGenerator.h"
#include "ObjectAccessor.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "PathFinder.h"
#include "MoveMap.h"

template<class T>
void FearMovementGenerator<T>::_setTargetLocation(T &owner)
{
    if (!&owner)
        return;

    // ignore in case other no reaction state
    if (owner.HasUnitState((UNIT_STAT_CAN_NOT_REACT | UNIT_STAT_CAN_NOT_MOVE | UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED) & ~UNIT_STAT_FLEEING))
        return;
    if (owner.IsRooted())
        return;

    float x, y, z;
    if (!_getPoint(owner, x, y, z))
        return;

    owner.AddUnitState(UNIT_STAT_FLEEING_MOVE);

    PathFinder path(&owner);
    path.SetTransport(owner.GetTransport());
    path.ExcludeSteepSlopes();
    path.setPathLengthLimit(PATH_LENGTH_LIMIT);
    path.calculate(x, y, z);
    path.CutPathWithDynamicLoS();

    if (path.getPathType() & PATHFIND_NOPATH)
    {
        i_nextCheckTime.Reset(urand(1000, 1500));
        return;
    }

    Movement::MoveSplineInit init(owner, "FearMovementGenerator");
    init.Move(&path);
    init.SetWalk(_forceWalking);
    if (_customSpeed > 0)
        init.SetVelocity(_customSpeed);
    int32 traveltime = init.Launch();
    i_nextCheckTime.Reset(traveltime + urand(NEXT_CHECK_TIME_LOWER_BOUND, NEXT_CHECK_TIME_UPPER_BOUND));
    _forceUpdate = false;
}

template<class T>
bool FearMovementGenerator<T>::_getPoint(T &owner, float &x, float &y, float &z)
{
    if (!&owner)
        return false;

    float sourceDist, sourceAngle;
    float targetDist, targetAngle;

    if (!i_initialFleeTime.Passed())
    {
        if (_pointInitDone)
            return false;

        if (Unit* fright = ObjectAccessor::GetUnit(owner, i_frightGuid))
        {
            sourceDist = fright->GetDistance(&owner);
            if (sourceDist > 0.5f)
                sourceAngle = fright->GetAngle(&owner);
            else
                sourceAngle = frand(0, 2 * M_PI_F);
        }
        else
        {
            sourceDist = 0.0f;
            sourceAngle = frand(0, 2 * M_PI_F);
        }

        targetDist = frand(0.8f, 1.3f) * DEFAULT_INIT_FLEE_DIST;
        targetAngle = sourceAngle + frand(-M_PI_F * INIT_FLEE_ANGLE_MULT, M_PI_F * INIT_FLEE_ANGLE_MULT);

        _pointInitDone = true;
    }
    else
    {
        targetDist = frand(0.6f, 1.2f) * POST_INIT_RADIUS;
        targetAngle = frand(0, 2 * M_PI_F);
    }

    owner.GetSafePosition(x, y, z);
    x += targetDist * cos(targetAngle);
    y += targetDist * sin(targetAngle);

    if (!MaNGOS::IsValidMapCoord(x, y, z))
        return false;

    float srcX, srcY, srcZ;
    owner.GetSafePosition(srcX, srcY, srcZ, owner.GetTransport());

    if (!owner.GetMap()->GetWalkHitPosition(owner.GetTransport(), srcX, srcY, srcZ, x, y, z, NAV_WATER | NAV_GROUND))
        owner.GetSafePosition(x, y, z);

    return owner.GetMap()->GetWalkRandomPosition(owner.GetTransport(), x, y, z, REACHABLE_RADIUS);
}

template<class T>
void FearMovementGenerator<T>::Initialize(T &owner)
{
    owner.AddUnitState(UNIT_STAT_FLEEING | UNIT_STAT_FLEEING_MOVE);
    owner.StopMoving();
    owner.UpdateControl();

    if (owner.GetTypeId() == TYPEID_UNIT)
    {
        owner.SetWalk(_forceWalking, false);
        owner.SetTargetGuid(0);
    }

    _setTargetLocation(owner);
}

template<>
void FearMovementGenerator<Player>::Finalize(Player &owner)
{
    owner.ClearUnitState(UNIT_STAT_FLEEING | UNIT_STAT_FLEEING_MOVE);
    owner.StopMoving();
    owner.UpdateControl();
}

template<>
void FearMovementGenerator<Creature>::Finalize(Creature &owner)
{
    owner.SetWalk(!owner.HasUnitState(UNIT_STAT_RUNNING), false);
    owner.ClearUnitState(UNIT_STAT_FLEEING | UNIT_STAT_FLEEING_MOVE);
    owner.UpdateControl();
}

template<class T>
void FearMovementGenerator<T>::Interrupt(T &owner)
{
    // flee state still applied while movegen disabled
    owner.ClearUnitState(UNIT_STAT_FLEEING_MOVE);
}

template<class T>
void FearMovementGenerator<T>::Reset(T &owner)
{
    Initialize(owner);
}

template<class T>
bool FearMovementGenerator<T>::Update(T &owner, uint32 const&  time_diff)
{
    if (!&owner || !owner.IsAlive())
        return false;

    if (owner.HasUnitState((UNIT_STAT_CAN_NOT_REACT | UNIT_STAT_CAN_NOT_MOVE | UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED) & ~UNIT_STAT_FLEEING))
    {
        owner.ClearUnitState(UNIT_STAT_FLEEING_MOVE);
        return true;
    }

    if (!_timeInitDone)
    {
        if (Unit* fright = ObjectAccessor::GetUnit(owner, i_frightGuid))
        {
            auto dist = fright->GetDistance(&owner);
            if (dist > MAX_DIST_BYPASS_INIT)
                i_initialFleeTime.Reset(i_initialFleeTime.GetExpiry() * frand(0, 1));

            _timeInitDone = true;
        }
    }

    i_nextCheckTime.Update(time_diff);
    i_initialFleeTime.Update(time_diff);

    if ((i_nextCheckTime.Passed() && owner.movespline->Finalized()) || _forceUpdate)
        _setTargetLocation(owner);

    return true;
}

template void FearMovementGenerator<Player>::Initialize(Player &);
template void FearMovementGenerator<Creature>::Initialize(Creature &);
template bool FearMovementGenerator<Player>::_getPoint(Player &, float &, float &, float &);
template bool FearMovementGenerator<Creature>::_getPoint(Creature &, float &, float &, float &);
template void FearMovementGenerator<Player>::_setTargetLocation(Player &);
template void FearMovementGenerator<Creature>::_setTargetLocation(Creature &);
template void FearMovementGenerator<Player>::Interrupt(Player &);
template void FearMovementGenerator<Creature>::Interrupt(Creature &);
template void FearMovementGenerator<Player>::Reset(Player &);
template void FearMovementGenerator<Creature>::Reset(Creature &);
template bool FearMovementGenerator<Player>::Update(Player &, uint32 const&);
template bool FearMovementGenerator<Creature>::Update(Creature &, uint32 const&);

void TimedFearMovementGenerator::Initialize(Unit& owner)
{
    ASSERT(owner.GetTypeId() == TYPEID_UNIT);
    _forceWalking = true;
    _customSpeed = ((Creature*)&owner)->GetFleeingSpeed();
    FearMovementGenerator<Creature>::Initialize(*((Creature*)&owner));
}

void TimedFearMovementGenerator::Finalize(Unit &owner)
{
    owner.ClearUnitState(UNIT_STAT_FLEEING | UNIT_STAT_FLEEING_MOVE);
    owner.UpdateControl();

    if (Unit* victim = owner.GetVictim())
    {
        if (owner.IsAlive())
        {
            owner.AttackStop(true);
            ((Creature*)&owner)->AI()->AttackStart(victim);
        }
    }
}

TimedFearMovementGenerator::TimedFearMovementGenerator(ObjectGuid fright, uint32 time) : FearMovementGenerator<Creature>(fright), i_totalFleeTime(time)
{
    i_initialFleeTime.Reset(DEFAULT_INIT_FLEE_TIME + urand(0, time * INIT_FLEE_TIME_RAND_MULT));
}

bool TimedFearMovementGenerator::Update(Unit & owner, uint32 const&  time_diff)
{
    if (!owner.IsAlive())
        return false;

    if (owner.HasUnitState((UNIT_STAT_CAN_NOT_REACT | UNIT_STAT_CAN_NOT_MOVE | UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED) & ~UNIT_STAT_FLEEING))
    {
        owner.ClearUnitState(UNIT_STAT_FLEEING_MOVE);
        return true;
    }
    
    i_totalFleeTime.Update(time_diff);

    if (i_totalFleeTime.Passed())
        return false;

    return MovementGeneratorMedium< Creature, FearMovementGenerator<Creature> >::Update(owner, time_diff);
}
