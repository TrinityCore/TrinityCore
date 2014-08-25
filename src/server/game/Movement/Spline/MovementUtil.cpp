/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#include "MoveSplineFlag.h"
#include <cmath>
#include <string>

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

    #define STR(x) #x

    char const* g_MovementFlag_names[] =
    {
        STR(Forward            ), // 0x00000001,
        STR(Backward           ), // 0x00000002,
        STR(Strafe_Left        ), // 0x00000004,
        STR(Strafe_Right       ), // 0x00000008,
        STR(Turn_Left          ), // 0x00000010,
        STR(Turn_Right         ), // 0x00000020,
        STR(Pitch_Up           ), // 0x00000040,
        STR(Pitch_Down         ), // 0x00000080,

        STR(Walk               ), // 0x00000100,               // Walking
        STR(Ontransport        ), // 0x00000200,
        STR(Levitation         ), // 0x00000400,
        STR(Root               ), // 0x00000800,
        STR(Falling            ), // 0x00001000,
        STR(Fallingfar         ), // 0x00002000,
        STR(Pendingstop        ), // 0x00004000,
        STR(PendingSTRafestop  ), // 0x00008000,
        STR(Pendingforward     ), // 0x00010000,
        STR(Pendingbackward    ), // 0x00020000,
        STR(PendingSTRafeleft  ), // 0x00040000,
        STR(PendingSTRaferight ), // 0x00080000,
        STR(Pendingroot        ), // 0x00100000,
        STR(Swimming           ), // 0x00200000,               // Appears With Fly Flag Also
        STR(Ascending          ), // 0x00400000,               // Swim Up Also
        STR(Descending         ), // 0x00800000,               // Swim Down Also
        STR(Can_Fly            ), // 0x01000000,               // Can Fly In 3.3?
        STR(Flying             ), // 0x02000000,               // Actual Flying Mode
        STR(Spline_Elevation   ), // 0x04000000,               // Used For Flight Paths
        STR(Spline_Enabled     ), // 0x08000000,               // Used For Flight Paths
        STR(Waterwalking       ), // 0x10000000,               // Prevent Unit From Falling Through Water
        STR(Safe_Fall          ), // 0x20000000,               // Active Rogue Safe Fall Spell (Passive)
        STR(Hover              ), // 0x40000000
        STR(Unknown13          ), // 0x80000000
        STR(Unk1               ),
        STR(Unk2               ),
        STR(Unk3               ),
        STR(Fullspeedturning   ),
        STR(Fullspeedpitching  ),
        STR(Allow_Pitching     ),
        STR(Unk4               ),
        STR(Unk5               ),
        STR(Unk6               ),
        STR(Unk7               ),
        STR(Interp_Move        ),
        STR(Interp_Turning     ),
        STR(Interp_Pitching    ),
        STR(Unk8               ),
        STR(Unk9               ),
        STR(Unk10              ),
    };

    char const* g_SplineFlag_names[32] =
    {
        STR(AnimBit1     ), // 0x00000001,
        STR(AnimBit2     ), // 0x00000002,
        STR(AnimBit3     ), // 0x00000004,
        STR(AnimBit4     ), // 0x00000008,
        STR(AnimBit5     ), // 0x00000010,
        STR(AnimBit6     ), // 0x00000020,
        STR(AnimBit7     ), // 0x00000040,
        STR(AnimBit8     ), // 0x00000080,
        STR(Done         ), // 0x00000100,
        STR(Falling      ), // 0x00000200,           // Not Compartible With Trajectory Movement
        STR(No_Spline    ), // 0x00000400,
        STR(Trajectory   ), // 0x00000800,           // Not Compartible With Fall Movement
        STR(Walkmode     ), // 0x00001000,
        STR(Flying       ), // 0x00002000,           // Smooth Movement(Catmullrom Interpolation Mode), Flying Animation
        STR(Knockback    ), // 0x00004000,           // Model Orientation Fixed
        STR(Final_Point  ), // 0x00008000,
        STR(Final_Target ), // 0x00010000,
        STR(Final_Angle  ), // 0x00020000,
        STR(Catmullrom   ), // 0x00040000,           // Used Catmullrom Interpolation Mode
        STR(Cyclic       ), // 0x00080000,           // Movement By Cycled Spline
        STR(Enter_Cycle  ), // 0x00100000,           // Everytime Appears With Cyclic Flag In Monster Move Packet
        STR(Animation    ), // 0x00200000,           // Animationid (0...3), Uint32 Time, Not Compartible With Trajectory And Fall Movement
        STR(Unknown4     ), // 0x00400000,           // Disables Movement By Path
        STR(Unknown5     ), // 0x00800000,
        STR(Unknown6     ), // 0x01000000,
        STR(Unknown7     ), // 0x02000000,
        STR(Unknown8     ), // 0x04000000,
        STR(OrientationInversed ), // 0x08000000,           // Appears With Runmode Flag, Nodes ), // 1, Handles Orientation
        STR(Unknown10    ), // 0x10000000,
        STR(Unknown11    ), // 0x20000000,
        STR(Unknown12    ), // 0x40000000,
        STR(Unknown13    ), // 0x80000000,
    };

    template<class Flags, int N>
    void print_flags(Flags t, char const* (&names)[N], std::string& str)
    {
        for (int i = 0; i < N; ++i)
        {
            if ((t & Flags(1 << i)) && names[i] != NULL)
                str.append(" ").append(names[i]);
        }
    }

    std::string MoveSplineFlag::ToString() const
    {
        std::string str;
        print_flags(raw(), g_SplineFlag_names, str);
        return str;
    }
}
