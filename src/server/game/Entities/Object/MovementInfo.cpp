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

#include "MovementInfo.h"
#include "GameTime.h"
#include "Log.h"
#include "UnitDefines.h"
#include "G3DPosition.hpp"

void MovementInfo::ResetTransport()
{
    transport.Reset();
}

void MovementInfo::ResetJump()
{
    jump.Reset();
}

bool MovementInfo::HasFallDirection() const
{
    return HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);
}

bool MovementInfo::HasFallData() const
{
    return (HasFallDirection() || jump.fallTime != 0);
}

bool MovementInfo::HasMovementFlags() const
{
    return GetMovementFlags() != 0;
};

bool MovementInfo::HasExtraMovementFlags() const
{
    return GetExtraMovementFlags() != 0;
};

bool MovementInfo::HasSpline() const
{
    // Todo: handle this
    return false;
};

bool MovementInfo::HasHeightChangeFailed() const
{
    return heightChangeFailed;
}

bool MovementInfo::HasTime() const
{
    return time != 0;
}

bool MovementInfo::HasOrientation() const
{
    return !G3D::fuzzyEq(pos.GetOrientation(), 0.0f);
}

bool MovementInfo::HasSplineElevation() const
{
    return HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION);
}

bool MovementInfo::HasPitch() const
{
    return (HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING));
}

bool MovementInfo::HasTransportData() const
{
    return !transport.guid.IsEmpty();
}

bool MovementInfo::HasTransportVehicleId() const
{
    return HasTransportData() && transport.vehicleId != 0;
}

bool MovementInfo::HasTransportTime2() const
{
    return HasTransportData() && transport.time2 != 0;
}

void MovementInfo::OutDebug()
{
    TC_LOG_DEBUG("misc", "MOVEMENT INFO");
    TC_LOG_DEBUG("misc", "%s", guid.ToString().c_str());
    TC_LOG_DEBUG("misc", "flags %u", flags);
    TC_LOG_DEBUG("misc", "flags2 %u", flags2);
    TC_LOG_DEBUG("misc", "time %u current time " UI64FMTD "", flags2, uint64(::GameTime::GetGameTime()));
    TC_LOG_DEBUG("misc", "position: `%s`", pos.ToString().c_str());
    if (transport.guid)
    {
        TC_LOG_DEBUG("misc", "TRANSPORT:");
        TC_LOG_DEBUG("misc", "%s", transport.guid.ToString().c_str());
        TC_LOG_DEBUG("misc", "position: `%s`", transport.pos.ToString().c_str());
        TC_LOG_DEBUG("misc", "seat: %i", transport.seat);
        TC_LOG_DEBUG("misc", "time: %u", transport.time);
        if (flags2 & MOVEMENTFLAG2_INTERPOLATED_MOVEMENT)
            TC_LOG_DEBUG("misc", "time2: %u", transport.time2);
        if (transport.vehicleId)
            TC_LOG_INFO("misc", "vehicleId: %u", transport.vehicleId);
    }

    if ((flags & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (flags2 & MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        TC_LOG_DEBUG("misc", "pitch: %f", pitch);

    if (flags & MOVEMENTFLAG_FALLING || jump.fallTime)
    {
        TC_LOG_INFO("misc", "fallTime: %u j_zspeed: %f", jump.fallTime, jump.zspeed);
        if (flags & MOVEMENTFLAG_FALLING)
            TC_LOG_DEBUG("misc", "j_zspeed: %f j_sinAngle: %f j_cosAngle: %f j_xyspeed: %f", jump.zspeed, jump.sinAngle, jump.cosAngle, jump.xyspeed);
    }

    if (flags & MOVEMENTFLAG_SPLINE_ELEVATION)
        TC_LOG_DEBUG("misc", "splineElevation: %f", splineElevation);
}
