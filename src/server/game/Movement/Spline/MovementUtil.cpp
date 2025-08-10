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

#include "MoveSplineFlag.h"
#include "MovementTypedefs.h"
#include "SmartEnum.h"
#include <cmath>

namespace Movement
{
    UInt32Counter splineIdGen;

    /// Velocity bounds that makes fall speed limited
    float constexpr terminalVelocity = 60.148003f;
    float constexpr terminalSafefallVelocity = 7.0f;

    float constexpr terminal_length = float(terminalVelocity * terminalVelocity) / (2.0f * gravity);
    float constexpr terminal_safeFall_length = (terminalSafefallVelocity * terminalSafefallVelocity) / (2.0f * gravity);
    float constexpr terminal_fallTime = float(terminalVelocity / gravity); // the time that needed to reach terminalVelocity
    float constexpr terminal_safeFall_fallTime = float(terminalSafefallVelocity / gravity); // the time that needed to reach terminalVelocity with safefall

    float computeFallTime(float path_length, bool isSafeFall)
    {
        if (path_length < 0.0f)
            return 0.0f;

        float time;
        if (isSafeFall)
        {
            if (path_length >= terminal_safeFall_length)
                time = (path_length - terminal_safeFall_length) / terminalSafefallVelocity + terminal_safeFall_fallTime;
            else
                time = std::sqrt(2.0f * path_length / gravity);
        }
        else
        {
            if (path_length >= terminal_length)
                time = (path_length - terminal_length) / terminalVelocity + terminal_fallTime;
            else
                time = std::sqrt(2.0f * path_length / gravity);
        }

        return time;
    }

    float computeFallElevation(float t_passed, bool isSafeFall, float start_velocity /*= 0.0f*/)
    {
        float termVel;
        float result;

        if (isSafeFall)
            termVel = terminalSafefallVelocity;
        else
            termVel = terminalVelocity;

        if (start_velocity > termVel)
            start_velocity = termVel;

        float terminal_time = (isSafeFall ? terminal_safeFall_fallTime : terminal_fallTime) - start_velocity / gravity; // the time that needed to reach terminalVelocity

        if (t_passed > terminal_time)
        {
            result = termVel * (t_passed - terminal_time) +
                start_velocity * terminal_time +
                gravity * terminal_time * terminal_time * 0.5f;
        }
        else
            result = t_passed * (start_velocity + t_passed * gravity * 0.5f);

        return result;
    }

    template<class Flags>
    void PrintFlags(Flags t, std::string& str)
    {
        for (Flags flag : EnumUtils::Iterate<Flags>())
            if ((t & flag) != Flags(0))
                str.append(" ").append(EnumUtils::ToConstant(flag));
    }

    std::string MoveSplineFlag::ToString() const
    {
        std::string str;
        PrintFlags<MoveSplineFlagEnum>(Raw, str);
        return str;
    }

    std::string MovementFlags_ToString(MovementFlags flags)
    {
        std::string str;
        PrintFlags(flags, str);
        return str;
    }

    std::string MovementFlags_ToString(MovementFlags2 flags)
    {
        std::string str;
        PrintFlags(flags, str);
        return str;
    }

    std::string MovementFlags_ToString(MovementFlags3 flags)
    {
        std::string str;
        PrintFlags(flags, str);
        return str;
    }
}
