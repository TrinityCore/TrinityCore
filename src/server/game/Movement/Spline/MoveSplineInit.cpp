/*
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

#include "MoveSplineInit.h"
#include "MovementPackets.h"
#include "MoveSpline.h"
#include "PathGenerator.h"
#include "Transport.h"
#include "Unit.h"

namespace Movement
{
    UnitMoveType SelectSpeedType(uint32 moveFlags)
    {
        if (moveFlags & MOVEMENTFLAG_FLYING)
        {
            if (moveFlags & MOVEMENTFLAG_BACKWARD /*&& speed_obj.flight >= speed_obj.flight_back*/)
                return MOVE_FLIGHT_BACK;
            else
                return MOVE_FLIGHT;
        }
        else if (moveFlags & MOVEMENTFLAG_SWIMMING)
        {
            if (moveFlags & MOVEMENTFLAG_BACKWARD /*&& speed_obj.swim >= speed_obj.swim_back*/)
                return MOVE_SWIM_BACK;
            else
                return MOVE_SWIM;
        }
        else if (moveFlags & MOVEMENTFLAG_WALKING)
        {
            //if (speed_obj.run > speed_obj.walk)
            return MOVE_WALK;
        }
        else if (moveFlags & MOVEMENTFLAG_BACKWARD /*&& speed_obj.run >= speed_obj.run_back*/)
            return MOVE_RUN_BACK;

        // Flying creatures use MOVEMENTFLAG_CAN_FLY or MOVEMENTFLAG_DISABLE_GRAVITY
        // Run speed is their default flight speed.
        return MOVE_RUN;
    }

    int32 MoveSplineInit::Launch()
    {
        MoveSpline& move_spline = *unit->movespline;

        bool transport = !unit->GetTransGUID().IsEmpty();
        Location real_position;
        // there is a big chance that current position is unknown if current state is not finalized, need compute it
        // this also allows calculate spline position and update map position in much greater intervals
        // Don't compute for transport movement if the unit is in a motion between two transports
        if (!move_spline.Finalized() && move_spline.onTransport == transport)
            real_position = move_spline.ComputePosition();
        else
        {
            Position const* pos;
            if (!transport)
                pos = unit;
            else
                pos = &unit->m_movementInfo.transport.pos;

            real_position.x = pos->GetPositionX();
            real_position.y = pos->GetPositionY();
            real_position.z = pos->GetPositionZ();
            real_position.orientation = unit->GetOrientation();
        }

        // should i do the things that user should do? - no.
        if (args.path.empty())
            return 0;

        // correct first vertex
        args.path[0] = real_position;
        args.initialOrientation = real_position.orientation;
        move_spline.onTransport = !unit->GetTransGUID().IsEmpty();

        uint32 moveFlags = unit->m_movementInfo.GetMovementFlags();
        if (!args.flags.backward)
            moveFlags = (moveFlags & ~MOVEMENTFLAG_BACKWARD) | MOVEMENTFLAG_FORWARD;
        else
            moveFlags = (moveFlags & ~MOVEMENTFLAG_FORWARD) | MOVEMENTFLAG_BACKWARD;

        if (moveFlags & MOVEMENTFLAG_ROOT)
            moveFlags &= ~MOVEMENTFLAG_MASK_MOVING;

        if (!args.HasVelocity)
        {
            // If spline is initialized with SetWalk method it only means we need to select
            // walk move speed for it but not add walk flag to unit
            uint32 moveFlagsForSpeed = moveFlags;
            if (args.walk)
                moveFlagsForSpeed |= MOVEMENTFLAG_WALKING;
            else
                moveFlagsForSpeed &= ~MOVEMENTFLAG_WALKING;

            args.velocity = unit->GetSpeed(SelectSpeedType(moveFlagsForSpeed));
        }

        if (!args.Validate(unit))
            return 0;

        unit->m_movementInfo.SetMovementFlags(moveFlags);
        move_spline.Initialize(args);

        WorldPackets::Movement::MonsterMove packet;
        packet.MoverGUID = unit->GetGUID();
        packet.Pos = Position(real_position.x, real_position.y, real_position.z, real_position.orientation);
        packet.InitializeSplineData(move_spline);
        if (transport)
        {
            packet.SplineData.Move.TransportGUID = unit->GetTransGUID();
            packet.SplineData.Move.VehicleSeat = unit->GetTransSeat();
        }

        unit->SendMessageToSet(packet.Write(), true);

        return move_spline.Duration();
    }

    void MoveSplineInit::Stop()
    {
        MoveSpline& move_spline = *unit->movespline;

        // No need to stop if we are not moving
        if (move_spline.Finalized())
            return;

        bool transport = !unit->GetTransGUID().IsEmpty();
        Location loc;
        if (move_spline.onTransport == transport)
            loc = move_spline.ComputePosition();
        else
        {
            Position const* pos;
            if (!transport)
                pos = unit;
            else
                pos = &unit->m_movementInfo.transport.pos;

            loc.x = pos->GetPositionX();
            loc.y = pos->GetPositionY();
            loc.z = pos->GetPositionZ();
            loc.orientation = unit->GetOrientation();
        }

        args.flags = MoveSplineFlag::Done;
        unit->m_movementInfo.RemoveMovementFlag(MOVEMENTFLAG_FORWARD);
        move_spline.onTransport = transport;
        move_spline.Initialize(args);

        WorldPackets::Movement::MonsterMove packet;
        packet.MoverGUID = unit->GetGUID();
        packet.Pos = Position(loc.x, loc.y, loc.z, loc.orientation);
        packet.SplineData.StopDistanceTolerance = 2;
        packet.SplineData.ID = move_spline.GetId();

        if (transport)
        {
            packet.SplineData.Move.TransportGUID = unit->GetTransGUID();
            packet.SplineData.Move.VehicleSeat = unit->GetTransSeat();
        }

        unit->SendMessageToSet(packet.Write(), true);
    }

    MoveSplineInit::MoveSplineInit(Unit* m) : unit(m)
    {
        args.splineId = splineIdGen.NewId();
        // Elevators also use MOVEMENTFLAG_ONTRANSPORT but we do not keep track of their position changes
        args.TransformForTransport = !unit->GetTransGUID().IsEmpty();
        // mix existing state into new
        args.flags.canSwim = unit->CanSwim();
        args.walk = unit->HasUnitMovementFlag(MOVEMENTFLAG_WALKING);
        args.flags.flying = unit->HasUnitMovementFlag(MovementFlags(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_DISABLE_GRAVITY));
        args.flags.smoothGroundPath = true; // enabled by default, CatmullRom mode or client config "pathSmoothing" will disable this
        args.flags.steering = unit->HasNpcFlag2(UNIT_NPC_FLAG_2_STEERING);
    }

    MoveSplineInit::~MoveSplineInit() = default;

    void MoveSplineInit::SetFacing(Vector3 const& spot)
    {
        TransportPathTransform transform(unit, args.TransformForTransport);
        Vector3 finalSpot = transform(spot);
        args.facing.f.x = finalSpot.x;
        args.facing.f.y = finalSpot.y;
        args.facing.f.z = finalSpot.z;
        args.facing.type = MONSTER_MOVE_FACING_SPOT;
    }

    void MoveSplineInit::SetFacing(Unit const* target)
    {
        args.facing.angle = unit->GetAngle(target);
        args.facing.target = target->GetGUID();
        args.facing.type = MONSTER_MOVE_FACING_TARGET;
    }

    void MoveSplineInit::SetFacing(float angle)
    {
        if (args.TransformForTransport)
        {
            if (Unit* vehicle = unit->GetVehicleBase())
                angle -= vehicle->GetOrientation();
            else if (Transport* transport = unit->GetTransport())
                angle -= transport->GetOrientation();
        }

        args.facing.angle = G3D::wrap(angle, 0.f, (float)G3D::twoPi());
        args.facing.type = MONSTER_MOVE_FACING_ANGLE;
    }

    void MoveSplineInit::MovebyPath(const PointsArray& controls, int32 path_offset)
    {
        args.path_Idx_offset = path_offset;
        args.path.reserve(controls.size());
        std::transform(controls.begin(), controls.end(), std::back_inserter(args.path), TransportPathTransform(unit, args.TransformForTransport));
    }

    void MoveSplineInit::MoveTo(float x, float y, float z, bool generatePath, bool forceDestination)
    {
        MoveTo(G3D::Vector3(x, y, z), generatePath, forceDestination);
    }

    void MoveSplineInit::MoveTo(const Vector3& dest, bool generatePath, bool forceDestination)
    {
        if (generatePath)
        {
            PathGenerator path(unit);
            bool result = path.CalculatePath(dest.x, dest.y, dest.z, forceDestination);
            if (result && !(path.GetPathType() & PATHFIND_NOPATH))
            {
                MovebyPath(path.GetPath());
                return;
            }
        }

        args.path_Idx_offset = 0;
        args.path.resize(2);
        TransportPathTransform transform(unit, args.TransformForTransport);
        args.path[1] = transform(dest);
    }

    void MoveSplineInit::SetFall()
    {
        args.flags.EnableFalling();
        args.flags.fallingSlow = unit->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);
    }

    Vector3 TransportPathTransform::operator()(Vector3 input)
    {
        if (_transformForTransport)
            if (TransportBase* transport = _owner->GetDirectTransport())
                transport->CalculatePassengerOffset(input.x, input.y, input.z);

        return input;
    }
}
