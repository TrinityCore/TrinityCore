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

    char const* MovementFlagNames[] =
    {
        STRINGIZE(Forward           ), // 0x00000001
        STRINGIZE(Backward          ), // 0x00000002
        STRINGIZE(Strafe_Left       ), // 0x00000004
        STRINGIZE(Strafe_Right      ), // 0x00000008
        STRINGIZE(Turn_Left         ), // 0x00000010
        STRINGIZE(Turn_Right        ), // 0x00000020
        STRINGIZE(Pitch_Up          ), // 0x00000040
        STRINGIZE(Pitch_Down        ), // 0x00000080
        STRINGIZE(Walking           ), // 0x00000100               // Walking
        STRINGIZE(DisableGravity    ), // 0x00000200
        STRINGIZE(Root              ), // 0x00000400
        STRINGIZE(Falling           ), // 0x00000800
        STRINGIZE(FallingFar        ), // 0x00001000
        STRINGIZE(PendingStop       ), // 0x00002000
        STRINGIZE(PendingStrafeStop ), // 0x00004000
        STRINGIZE(PendingForward    ), // 0x00008000
        STRINGIZE(PendingBackward   ), // 0x00010000
        STRINGIZE(PendingStrafeLeft ), // 0x00020000
        STRINGIZE(PendingStrafeRight), // 0x00040000
        STRINGIZE(PendingRoot       ), // 0x00080000
        STRINGIZE(Swimming          ), // 0x00100000               // Appears With Fly Flag Also
        STRINGIZE(Ascending         ), // 0x00200000               // Swim Up Also
        STRINGIZE(Descending        ), // 0x00400000               // Swim Down Also
        STRINGIZE(Can_Fly           ), // 0x00800000               // Can Fly In 3.3?
        STRINGIZE(Flying            ), // 0x01000000               // Actual Flying Mode
        STRINGIZE(Spline_Elevation  ), // 0x02000000               // Used For Flight Paths
        STRINGIZE(Waterwalking      ), // 0x04000000               // Prevent Unit From Falling Through Water
        STRINGIZE(Safe_Fall         ), // 0x08000000               // Active Rogue Safe Fall Spell (Passive)
        STRINGIZE(Hover             ), // 0x10000000
        STRINGIZE(Local_Dirty       ), // 0x20000000
        STRINGIZE(None31            ), // 0x40000000
        STRINGIZE(None32            ), // 0x80000000
    };

    char const* MovementFlagExtraNames[] =
    {
        STRINGIZE(NoStrafe                           ), // 0x00000001
        STRINGIZE(NoJump                             ), // 0x00000002
        STRINGIZE(FullSpeedTurning                   ), // 0x00000004
        STRINGIZE(FullSpeedPitching                  ), // 0x00000008
        STRINGIZE(Allow_Pitching                     ), // 0x00000010
        STRINGIZE(VehicleExitVoluntary               ), // 0x00000020
        STRINGIZE(WaterwalkingFullPitch              ), // 0x00000040
        STRINGIZE(VehiclePassengerIsTransitionAllowed), // 0x00000080
        STRINGIZE(CanSwimToFlyTrans                  ), // 0x00000100
        STRINGIZE(Unk9                               ), // 0x00000200
        STRINGIZE(CanTurnWhileFalling                ), // 0x00000400
        STRINGIZE(IgnoreMovementForces               ), // 0x00000800
        STRINGIZE(CanDoubleJump                      ), // 0x00001000
        STRINGIZE(DoubleJump                         ), // 0x00002000
        STRINGIZE(Unk14                              ), // 0x00004000
        STRINGIZE(Unk15                              ), // 0x00008000
        STRINGIZE(AwaitingLoad                       ), // 0x00010000
        STRINGIZE(InterpolatedMovement               ), // 0x00020000
        STRINGIZE(InterpolatedTurning                ), // 0x00040000
        STRINGIZE(InterpolatedPitching               ), // 0x00080000
    };

    char const* SplineFlagNames[32] =
    {
        STRINGIZE(Unknown_0x1       ), // 0x00000001
        STRINGIZE(Unknown_0x2       ), // 0x00000002
        STRINGIZE(Unknown_0x4       ), // 0x00000004
        STRINGIZE(Unknown_0x8       ), // 0x00000008
        STRINGIZE(FallingSlow       ), // 0x00000010
        STRINGIZE(Done              ), // 0x00000020
        STRINGIZE(Falling           ), // 0x00000040           // Not Compartible With Trajectory Movement
        STRINGIZE(No_Spline         ), // 0x00000080
        STRINGIZE(Unknown_0x100     ), // 0x00000100
        STRINGIZE(Flying            ), // 0x00000200           // Smooth Movement(Catmullrom Interpolation Mode), Flying Animation
        STRINGIZE(OrientationFixed  ), // 0x00000400           // Model Orientation Fixed
        STRINGIZE(Catmullrom        ), // 0x00000800           // Used Catmullrom Interpolation Mode
        STRINGIZE(Cyclic            ), // 0x00001000           // Movement By Cycled Spline
        STRINGIZE(Enter_Cycle       ), // 0x00002000           // Everytime Appears With Cyclic Flag In Monster Move Packet
        STRINGIZE(Frozen            ), // 0x00004000
        STRINGIZE(TransportEnter    ), // 0x00008000
        STRINGIZE(TransportExit     ), // 0x00010000
        STRINGIZE(Unknown_0x20000   ), // 0x00020000
        STRINGIZE(Unknown_0x40000   ), // 0x00040000
        STRINGIZE(Backward          ), // 0x00080000           // Appears With Runmode Flag, Nodes ), // 1, Handles Orientation
        STRINGIZE(SmoothGroundPath  ), // 0x00100000
        STRINGIZE(CanSwim           ), // 0x00200000
        STRINGIZE(UncompressedPath  ), // 0x00400000
        STRINGIZE(Unknown_0x800000  ), // 0x00800000
        STRINGIZE(Unknown_0x1000000 ), // 0x01000000
        STRINGIZE(Animation         ), // 0x02000000           // Animationid (0...3), Uint32 Time, Not Compartible With Trajectory And Fall Movement
        STRINGIZE(Parabolic         ), // 0x04000000           // Not Compartible With Fall Movement
        STRINGIZE(FadeObject        ), // 0x08000000
        STRINGIZE(Steering          ), // 0x10000000
        STRINGIZE(Unknown_0x20000000), // 0x20000000
        STRINGIZE(Unknown_0x40000000), // 0x40000000
        STRINGIZE(Unknown_0x80000000), // 0x80000000
    };

    template<class Flags, int N>
    void PrintFlags(Flags t, char const* (&names)[N], std::string& str)
    {
        for (int i = 0; i < N; ++i)
        {
            if ((t & Flags(1 << i)) && names[i] != nullptr)
                str.append(" ").append(names[i]);
        }
    }

    std::string MoveSplineFlag::ToString() const
    {
        std::string str;
        PrintFlags(raw(), SplineFlagNames, str);
        return str;
    }

    std::string MovementFlags_ToString(uint32 flags)
    {
        std::string str;
        PrintFlags(flags, MovementFlagNames, str);
        return str;
    }

    std::string MovementFlagsExtra_ToString(uint32 flags)
    {
        std::string str;
        PrintFlags(flags, MovementFlagExtraNames, str);
        return str;
    }
}
