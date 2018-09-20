/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "SplineChainMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Errors.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "Log.h"
#include "Unit.h"

SplineChainMovementGenerator::SplineChainMovementGenerator(uint32 id, std::vector<SplineChainLink> const& chain, bool walk) : _id(id), _chain(chain), _chainSize(chain.size()), _walk(walk), _nextIndex(0), _nextFirstWP(0), _msToNext(0)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
}

SplineChainMovementGenerator::SplineChainMovementGenerator(SplineChainResumeInfo const& info) : _id(info.PointID), _chain(*info.Chain), _chainSize(info.Chain->size()), _walk(info.IsWalkMode), _nextIndex(info.SplineIndex), _nextFirstWP(info.PointIndex), _msToNext(info.TimeToNext)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;

    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    if (info.SplineIndex >= info.Chain->size())
        AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    BaseUnitState = UNIT_STATE_ROAMING;
}

uint32 SplineChainMovementGenerator::SendPathSpline(Unit* owner, Movement::PointsArray const& path) const
{
    uint32 nodeCount = path.size();
    ASSERT(nodeCount > 1, "SplineChainMovementGenerator::SendPathSpline: Every path must have source & destination (size > 1)! (%s)", owner->GetGUID().ToString().c_str());

    Movement::MoveSplineInit init(owner);
    if (nodeCount > 2)
        init.MovebyPath(path);
    else
        init.MoveTo(path[1], false, true);
    init.SetWalk(_walk);
    return init.Launch();
}

void SplineChainMovementGenerator::SendSplineFor(Unit* owner, uint32 index, uint32& duration)
{
    ASSERT(index < _chainSize, "SplineChainMovementGenerator::SendSplineFor: referenced index (%u) higher than path size (%u)!", index, _chainSize);
    TC_LOG_DEBUG("movement.splinechain", "SplineChainMovementGenerator::SendSplineFor: sending spline on index: %u. (%s)", index, owner->GetGUID().ToString().c_str());

    SplineChainLink const& thisLink = _chain[index];
    uint32 actualDuration = SendPathSpline(owner, thisLink.Points);
    if (actualDuration != thisLink.ExpectedDuration)
    {
        TC_LOG_DEBUG("movement.splinechain", "SplineChainMovementGenerator::SendSplineFor: sent spline on index: %u, duration: %u ms. Expected duration: %u ms (delta %d ms). Adjusting. (%s)", index, actualDuration, thisLink.ExpectedDuration, int32(actualDuration) - int32(thisLink.ExpectedDuration), owner->GetGUID().ToString().c_str());
        duration = uint32(double(actualDuration) / double(thisLink.ExpectedDuration) * duration);
    }
    else
    {
        TC_LOG_DEBUG("movement.splinechain", "SplineChainMovementGenerator::SendSplineFor: sent spline on index %u, duration: %u ms. (%s)", index, actualDuration, owner->GetGUID().ToString().c_str());
    }
}

void SplineChainMovementGenerator::Initialize(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (!_chainSize)
    {
        TC_LOG_ERROR("movement", "SplineChainMovementGenerator::Initialize: couldn't initialize generator, referenced spline is empty! (%s)", owner->GetGUID().ToString().c_str());
        return;
    }

    if (_nextFirstWP) // this is a resumed movegen that has to start with a partial spline
    {
        if (HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED))
            return;

        SplineChainLink const& thisLink = _chain[_nextIndex];
        if (_nextFirstWP >= thisLink.Points.size())
        {
            TC_LOG_ERROR("movement.splinechain", "SplineChainMovementGenerator::Initialize: attempted to resume spline chain from invalid resume state, _nextFirstWP >= path size (_nextIndex: %u, _nextFirstWP: %u). (%s)", _nextIndex, _nextFirstWP, owner->GetGUID().ToString().c_str());
            _nextFirstWP = thisLink.Points.size() - 1;
        }

        owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);
        Movement::PointsArray partial(thisLink.Points.begin() + (_nextFirstWP-1), thisLink.Points.end());
        SendPathSpline(owner, partial);

        TC_LOG_DEBUG("movement.splinechain", "SplineChainMovementGenerator::Initialize: resumed spline chain generator from resume state. (%s)", owner->GetGUID().ToString().c_str());

        ++_nextIndex;
        if (_nextIndex >= _chainSize)
            _msToNext = 0;
        else if (!_msToNext)
            _msToNext = 1;
        _nextFirstWP = 0;
    }
    else
    {
        _msToNext = std::max(_chain[_nextIndex].TimeToNext, 1u);
        SendSplineFor(owner, _nextIndex, _msToNext);

        ++_nextIndex;
        if (_nextIndex >= _chainSize)
            _msToNext = 0;
    }
}

void SplineChainMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    owner->StopMoving();
    Initialize(owner);
}

bool SplineChainMovementGenerator::Update(Unit* owner, uint32 diff)
{
    if (!owner || HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED))
        return false;

    // _msToNext being zero here means we're on the final spline
    if (!_msToNext)
    {
        if (owner->movespline->Finalized())
        {
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
            return false;
        }
        return true;
    }

    if (_msToNext <= diff)
    {
        // Send next spline
        TC_LOG_DEBUG("movement.splinechain", "SplineChainMovementGenerator::Update: sending spline on index %u (%u ms late). (%s)", _nextIndex, diff - _msToNext, owner->GetGUID().ToString().c_str());
        _msToNext = std::max(_chain[_nextIndex].TimeToNext, 1u);
        SendSplineFor(owner, _nextIndex, _msToNext);
        ++_nextIndex;
        if (_nextIndex >= _chainSize)
        {
            // We have reached the final spline, once it finalizes we should also finalize the movegen (start checking on next update)
            _msToNext = 0;
            return true;
        }
    }
    else
        _msToNext -= diff;

    return true;
}

void SplineChainMovementGenerator::Deactivate(Unit* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void SplineChainMovementGenerator::Finalize(Unit* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
    {
        Creature* ownerCreature = owner->ToCreature();
        if (CreatureAI* AI = ownerCreature ? ownerCreature->AI() : nullptr)
            AI->MovementInform(SPLINE_CHAIN_MOTION_TYPE, _id);
    }
}

MovementGeneratorType SplineChainMovementGenerator::GetMovementGeneratorType() const
{
    return SPLINE_CHAIN_MOTION_TYPE;
}

SplineChainResumeInfo SplineChainMovementGenerator::GetResumeInfo(Unit const* owner) const
{
    if (!_nextIndex)
        return SplineChainResumeInfo(_id, &_chain, _walk, 0, 0, _msToNext);

    if (owner->movespline->Finalized())
    {
        if (_nextIndex < _chainSize)
            return SplineChainResumeInfo(_id, &_chain, _walk, _nextIndex, 0, 1u);
        else
            return SplineChainResumeInfo();
    }

    return SplineChainResumeInfo(_id, &_chain, _walk, uint8(_nextIndex - 1), uint8(owner->movespline->_currentSplineIdx()), _msToNext);
}

/* static */ void SplineChainMovementGenerator::GetResumeInfo(SplineChainResumeInfo& info, Unit const* owner, Optional<uint32> id)
{
    std::function<bool(MovementGenerator const*)> criteria = [id](MovementGenerator const* movement) -> bool
    {
        if (movement->GetMovementGeneratorType() == SPLINE_CHAIN_MOTION_TYPE)
            return (!id || static_cast<SplineChainMovementGenerator const*>(movement)->GetId() == *id);

        return false;
    };

    if (MovementGenerator const* activeGenerator = owner->GetMotionMaster()->GetMovementGenerator(criteria))
        info = static_cast<SplineChainMovementGenerator const*>(activeGenerator)->GetResumeInfo(owner);
    else
        info.Clear();
}
