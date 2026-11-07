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
    float gravity = static_cast<float>(19.29110527038574);
    UInt32Counter splineIdGen;

    /// Velocity bounds that makes fall speed limited
    float terminalVelocity = 60.148003f;
    float terminalSafefallVelocity = 7.0f;

    const float terminal_length = float(terminalVelocity * terminalVelocity) / (2.0f * gravity);
    const float terminal_safeFall_length = (terminalSafefallVelocity * terminalSafefallVelocity) / (2.0f * gravity);
    const float terminal_fallTime = float(terminalVelocity / gravity); // the time that needed to reach terminalVelocity
    const float terminal_safeFall_fallTime = float(terminalSafefallVelocity / gravity); // the time that needed to reach terminalVelocity with safefall

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

    char const* g_MovementFlag_names[] =
    {
        STRINGIZE(Forward           ), // 0x00000001,
        STRINGIZE(Backward          ), // 0x00000002,
        STRINGIZE(Strafe_Left       ), // 0x00000004,
        STRINGIZE(Strafe_Right      ), // 0x00000008,
        STRINGIZE(Turn_Left         ), // 0x00000010,
        STRINGIZE(Turn_Right        ), // 0x00000020,
        STRINGIZE(Pitch_Up          ), // 0x00000040,
        STRINGIZE(Pitch_Down        ), // 0x00000080,

        STRINGIZE(Walk              ), // 0x00000100,               // Walking
        STRINGIZE(Ontransport       ), // 0x00000200,
        STRINGIZE(Levitation        ), // 0x00000400,
        STRINGIZE(Root              ), // 0x00000800,
        STRINGIZE(Falling           ), // 0x00001000,
        STRINGIZE(Fallingfar        ), // 0x00002000,
        STRINGIZE(Pendingstop       ), // 0x00004000,
        STRINGIZE(PendingStrafeStop ), // 0x00008000,
        STRINGIZE(PendingForward    ), // 0x00010000,
        STRINGIZE(PendingBackward   ), // 0x00020000,
        STRINGIZE(PendingStrafeReft ), // 0x00040000,
        STRINGIZE(PendingStrafeRight), // 0x00080000,
        STRINGIZE(PendingRoot       ), // 0x00100000,
        STRINGIZE(Swimming          ), // 0x00200000,               // Appears With Fly Flag Also
        STRINGIZE(Ascending         ), // 0x00400000,               // Swim Up Also
        STRINGIZE(Descending        ), // 0x00800000,               // Swim Down Also
        STRINGIZE(Can_Fly           ), // 0x01000000,               // Can Fly In 3.3?
        STRINGIZE(Flying            ), // 0x02000000,               // Actual Flying Mode
        STRINGIZE(Spline_Elevation  ), // 0x04000000,               // Used For Flight Paths
        STRINGIZE(Spline_Enabled    ), // 0x08000000,               // Used For Flight Paths
        STRINGIZE(Waterwalking      ), // 0x10000000,               // Prevent Unit From Falling Through Water
        STRINGIZE(Safe_Fall         ), // 0x20000000,               // Active Rogue Safe Fall Spell (Passive)
        STRINGIZE(Hover             ), // 0x40000000
        STRINGIZE(Unknown13         ), // 0x80000000
        STRINGIZE(NoStrafe          ),
        STRINGIZE(NoJump            ),
        STRINGIZE(Unk3              ),
        STRINGIZE(FullSpeedTurning  ),
        STRINGIZE(FullSpeedPitching ),
        STRINGIZE(Allow_Pitching    ),
        STRINGIZE(Unk4              ),
        STRINGIZE(Unk5              ),
        STRINGIZE(Unk6              ),
        STRINGIZE(Unk7              ),
        STRINGIZE(Interp_Move       ),
        STRINGIZE(Interp_Turning    ),
        STRINGIZE(Interp_Pitching   ),
        STRINGIZE(Unk8              ),
        STRINGIZE(Unk9              ),
        STRINGIZE(Unk10             ),
    };

    char const* g_SplineFlag_names[32] =
    {
        STRINGIZE(AnimBit1      ), // 0x00000001,
        STRINGIZE(AnimBit2      ), // 0x00000002,
        STRINGIZE(AnimBit3      ), // 0x00000004,
        STRINGIZE(AnimBit4      ), // 0x00000008,
        STRINGIZE(AnimBit5      ), // 0x00000010,
        STRINGIZE(AnimBit6      ), // 0x00000020,
        STRINGIZE(AnimBit7      ), // 0x00000040,
        STRINGIZE(AnimBit8      ), // 0x00000080,
        STRINGIZE(Done          ), // 0x00000100,
        STRINGIZE(Falling       ), // 0x00000200,           // Not Compartible With Trajectory Movement
        STRINGIZE(No_Spline     ), // 0x00000400,
        STRINGIZE(Trajectory    ), // 0x00000800,           // Not Compartible With Fall Movement
        STRINGIZE(CanSwim       ), // 0x00001000,
        STRINGIZE(Flying        ), // 0x00002000,           // Smooth Movement(Catmullrom Interpolation Mode), Flying Animation
        STRINGIZE(Knockback     ), // 0x00004000,           // Model Orientation Fixed
        STRINGIZE(Final_Point   ), // 0x00008000,
        STRINGIZE(Final_Target  ), // 0x00010000,
        STRINGIZE(Final_Angle   ), // 0x00020000,
        STRINGIZE(Catmullrom    ), // 0x00040000,           // Used Catmullrom Interpolation Mode
        STRINGIZE(Cyclic        ), // 0x00080000,           // Movement By Cycled Spline
        STRINGIZE(Enter_Cycle   ), // 0x00100000,           // Everytime Appears With Cyclic Flag In Monster Move Packet
        STRINGIZE(Animation     ), // 0x00200000,           // Animationid (0...3), Uint32 Time, Not Compartible With Trajectory And Fall Movement
        STRINGIZE(Frozen        ), // 0x00400000,           // Disables Movement By Path
        STRINGIZE(TransportEnter), // 0x00800000,
        STRINGIZE(TransportExit ), // 0x01000000,
        STRINGIZE(Unknown7      ), // 0x02000000,
        STRINGIZE(Unknown8      ), // 0x04000000,
        STRINGIZE(Backward      ), // 0x08000000,           // Appears With Runmode Flag, Nodes ), // 1, Handles Orientation
        STRINGIZE(Unknown10     ), // 0x10000000,
        STRINGIZE(Unknown11     ), // 0x20000000,
        STRINGIZE(Unknown12     ), // 0x40000000,
        STRINGIZE(Unknown13     ), // 0x80000000,
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
        PrintFlags(raw(), g_SplineFlag_names, str);
        return str;
    }
}
