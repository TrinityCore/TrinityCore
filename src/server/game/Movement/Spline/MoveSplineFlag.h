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

#ifndef TRINITYSERVER_MOVESPLINEFLAG_H
#define TRINITYSERVER_MOVESPLINEFLAG_H

#include "Define.h"
#include "EnumFlag.h"
#include <string>

namespace Movement
{
    // EnumUtils: DESCRIBE THIS
    enum class MoveSplineFlagEnum : uint32
    {
        None                = 0x00000000,
        Unknown_0x1         = 0x00000001,           // NOT VERIFIED
        Unknown_0x2         = 0x00000002,           // NOT VERIFIED
        Unknown_0x4         = 0x00000004,           // NOT VERIFIED
        JumpOrientationFixed= 0x00000008,           // Model orientation fixed (jump animation)
        FallingSlow         = 0x00000010,
        Done                = 0x00000020,
        Falling             = 0x00000040,           // Affects elevation computation, can't be combined with Parabolic flag
        No_Spline           = 0x00000080,
        Unknown_0x100       = 0x00000100,           // NOT VERIFIED
        Flying              = 0x00000200,           // Smooth movement(Catmullrom interpolation mode), flying animation
        OrientationFixed    = 0x00000400,           // Model orientation fixed (knockback animation)
        Catmullrom          = 0x00000800,           // Used Catmullrom interpolation mode
        Cyclic              = 0x00001000,           // Movement by cycled spline
        Enter_Cycle         = 0x00002000,           // Everytimes appears with cyclic flag in monster move packet, erases first spline vertex after first cycle done
        Frozen              = 0x00004000,           // Will never arrive
        TransportEnter      = 0x00008000,
        TransportExit       = 0x00010000,
        Unknown_0x20000     = 0x00020000,           // NOT VERIFIED
        Unknown_0x40000     = 0x00040000,           // NOT VERIFIED
        Backward            = 0x00080000,
        SmoothGroundPath    = 0x00100000,
        CanSwim             = 0x00200000,
        UncompressedPath    = 0x00400000,
        Unknown_0x800000    = 0x00800000,           // NOT VERIFIED
        FastSteering        = 0x01000000,           // Predicts spline only 500ms into the future for smoothing instead of 1s (making turns sharper) and turns off clientside obstacle detection
        Animation           = 0x02000000,           // Plays animation after some time passed
        Parabolic           = 0x04000000,           // Affects elevation computation, can't be combined with Falling flag
        FadeObject          = 0x08000000,
        Steering            = 0x10000000,
        UnlimitedSpeed      = 0x20000000,
        Unknown_0x40000000  = 0x40000000,           // NOT VERIFIED
        Unknown_0x80000000  = 0x80000000,           // NOT VERIFIED

        // Masks
        // flags that shouldn't be appended into SMSG_MONSTER_MOVE\SMSG_MONSTER_MOVE_TRANSPORT packet, should be more probably
        Mask_No_Monster_Move = Done, // SKIP
        // Unused, not suported flags
        Mask_Unused         = No_Spline | Enter_Cycle | Frozen | Unknown_0x100 | Unknown_0x20000 | Unknown_0x40000
                            | Unknown_0x800000 | FadeObject | UnlimitedSpeed | Unknown_0x40000000 | Unknown_0x80000000 // SKIP
    };

    DEFINE_ENUM_FLAG(MoveSplineFlagEnum);

    consteval MoveSplineFlagEnum GetDisallowedFlagsFor(MoveSplineFlagEnum flag)
    {
        switch (flag)
        {
            case MoveSplineFlagEnum::JumpOrientationFixed: return MoveSplineFlagEnum::OrientationFixed;
            case MoveSplineFlagEnum::Falling: return MoveSplineFlagEnum::Parabolic | MoveSplineFlagEnum::Animation | MoveSplineFlagEnum::Flying;
            case MoveSplineFlagEnum::Flying: return MoveSplineFlagEnum::FallingSlow | MoveSplineFlagEnum::Falling;
            case MoveSplineFlagEnum::OrientationFixed: return MoveSplineFlagEnum::JumpOrientationFixed;
            case MoveSplineFlagEnum::Catmullrom: return MoveSplineFlagEnum::SmoothGroundPath;
            case MoveSplineFlagEnum::TransportEnter: return MoveSplineFlagEnum::TransportExit;
            case MoveSplineFlagEnum::TransportExit: return MoveSplineFlagEnum::TransportEnter;
            case MoveSplineFlagEnum::SmoothGroundPath: return MoveSplineFlagEnum::Steering;
            case MoveSplineFlagEnum::Animation: return MoveSplineFlagEnum::Falling | MoveSplineFlagEnum::Parabolic | MoveSplineFlagEnum::FallingSlow | MoveSplineFlagEnum::FadeObject;
            case MoveSplineFlagEnum::Parabolic: return MoveSplineFlagEnum::Falling | MoveSplineFlagEnum::Animation | MoveSplineFlagEnum::FallingSlow | MoveSplineFlagEnum::FadeObject;
            case MoveSplineFlagEnum::FadeObject: return MoveSplineFlagEnum::Falling | MoveSplineFlagEnum::Parabolic | MoveSplineFlagEnum::FallingSlow | MoveSplineFlagEnum::Animation;
            case MoveSplineFlagEnum::Steering: return MoveSplineFlagEnum::SmoothGroundPath;
            default: break;
        }
        return MoveSplineFlagEnum::None;
    }

    union MoveSplineFlag
    {
        constexpr MoveSplineFlag() : Raw(MoveSplineFlagEnum::None) { }
        constexpr MoveSplineFlag(MoveSplineFlagEnum f) : Raw(f) { }

        // Constant interface

        constexpr bool isSmooth() const { return Raw.HasFlag(MoveSplineFlagEnum::Catmullrom); }
        constexpr bool isLinear() const { return !isSmooth(); }

        constexpr bool HasAllFlags(MoveSplineFlagEnum f) const { return Raw.HasAllFlags(f); }
        constexpr bool HasFlag(MoveSplineFlagEnum f) const { return Raw.HasFlag(f); }
        constexpr MoveSplineFlagEnum operator&(MoveSplineFlagEnum f) const { return (Raw & f); }
        constexpr MoveSplineFlagEnum operator|(MoveSplineFlagEnum f) const { return (Raw | f); }
        std::string ToString() const;

        // Not constant interface

        constexpr MoveSplineFlag& operator&=(MoveSplineFlagEnum f) { Raw &= f; return *this; }
        constexpr MoveSplineFlag& operator|=(MoveSplineFlagEnum f) { Raw |= f; return *this; }

        EnumFlag<MoveSplineFlagEnum> Raw;

        template <MoveSplineFlagEnum Flag>
        struct FlagAccessor
        {
            // force compile time evaluation - workaround for clang <= 14
            static constexpr MoveSplineFlagEnum DisallowedFlag = std::integral_constant<MoveSplineFlagEnum, GetDisallowedFlagsFor(Flag)>::value;

            constexpr operator bool() const { return (Raw & Flag) != MoveSplineFlagEnum::None; }
            constexpr FlagAccessor& operator=(bool val) { if (val) { Raw = Raw & ~DisallowedFlag | Flag; } else Raw &= ~Flag; return *this; }
            MoveSplineFlagEnum Raw;
        };

#define MAKE_FLAG_ACCESSOR_FIELD(flag) FlagAccessor<MoveSplineFlagEnum::flag> flag

        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x1);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x2);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x4);
        MAKE_FLAG_ACCESSOR_FIELD(JumpOrientationFixed);
        MAKE_FLAG_ACCESSOR_FIELD(FallingSlow);
        MAKE_FLAG_ACCESSOR_FIELD(Done);
        MAKE_FLAG_ACCESSOR_FIELD(Falling);
        MAKE_FLAG_ACCESSOR_FIELD(No_Spline);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x100);
        MAKE_FLAG_ACCESSOR_FIELD(Flying);
        MAKE_FLAG_ACCESSOR_FIELD(OrientationFixed);
        MAKE_FLAG_ACCESSOR_FIELD(Catmullrom);
        MAKE_FLAG_ACCESSOR_FIELD(Cyclic);
        MAKE_FLAG_ACCESSOR_FIELD(Enter_Cycle);
        MAKE_FLAG_ACCESSOR_FIELD(Frozen);
        MAKE_FLAG_ACCESSOR_FIELD(TransportEnter);
        MAKE_FLAG_ACCESSOR_FIELD(TransportExit);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x20000);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x40000);
        MAKE_FLAG_ACCESSOR_FIELD(Backward);
        MAKE_FLAG_ACCESSOR_FIELD(SmoothGroundPath);
        MAKE_FLAG_ACCESSOR_FIELD(CanSwim);
        MAKE_FLAG_ACCESSOR_FIELD(UncompressedPath);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x800000);
        MAKE_FLAG_ACCESSOR_FIELD(FastSteering);
        MAKE_FLAG_ACCESSOR_FIELD(Animation);
        MAKE_FLAG_ACCESSOR_FIELD(Parabolic);
        MAKE_FLAG_ACCESSOR_FIELD(FadeObject);
        MAKE_FLAG_ACCESSOR_FIELD(Steering);
        MAKE_FLAG_ACCESSOR_FIELD(UnlimitedSpeed);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x40000000);
        MAKE_FLAG_ACCESSOR_FIELD(Unknown_0x80000000);

#undef MAKE_FLAG_ACCESSOR_FIELD
    };
}

#endif // TRINITYSERVER_MOVESPLINEFLAG_H
