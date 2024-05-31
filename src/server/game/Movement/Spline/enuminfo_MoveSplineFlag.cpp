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
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

using Movement::MoveSplineFlagEnum;

namespace Trinity::Impl::EnumUtilsImpl
{

/***************************************************************************\
|* data for enum 'MoveSplineFlagEnum' in 'MoveSplineFlag.h' auto-generated *|
\***************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<MoveSplineFlagEnum>::ToString(MoveSplineFlagEnum value)
{
    switch (value)
    {
        case MoveSplineFlagEnum::None: return { "None", "None", "" };
        case MoveSplineFlagEnum::Unknown_0x1: return { "Unknown_0x1", "Unknown_0x1", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Unknown_0x2: return { "Unknown_0x2", "Unknown_0x2", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Unknown_0x4: return { "Unknown_0x4", "Unknown_0x4", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Unknown_0x8: return { "Unknown_0x8", "Unknown_0x8", "NOT VERIFIED - does someting related to falling/fixed orientation" };
        case MoveSplineFlagEnum::FallingSlow: return { "FallingSlow", "FallingSlow", "" };
        case MoveSplineFlagEnum::Done: return { "Done", "Done", "" };
        case MoveSplineFlagEnum::Falling: return { "Falling", "Falling", "Affects elevation computation, can't be combined with Parabolic flag" };
        case MoveSplineFlagEnum::No_Spline: return { "No_Spline", "No_Spline", "" };
        case MoveSplineFlagEnum::Unknown_0x100: return { "Unknown_0x100", "Unknown_0x100", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Flying: return { "Flying", "Flying", "Smooth movement(Catmullrom interpolation mode), flying animation" };
        case MoveSplineFlagEnum::OrientationFixed: return { "OrientationFixed", "OrientationFixed", "Model orientation fixed" };
        case MoveSplineFlagEnum::Catmullrom: return { "Catmullrom", "Catmullrom", "Used Catmullrom interpolation mode" };
        case MoveSplineFlagEnum::Cyclic: return { "Cyclic", "Cyclic", "Movement by cycled spline" };
        case MoveSplineFlagEnum::Enter_Cycle: return { "Enter_Cycle", "Enter_Cycle", "Everytimes appears with cyclic flag in monster move packet, erases first spline vertex after first cycle done" };
        case MoveSplineFlagEnum::Frozen: return { "Frozen", "Frozen", "Will never arrive" };
        case MoveSplineFlagEnum::TransportEnter: return { "TransportEnter", "TransportEnter", "" };
        case MoveSplineFlagEnum::TransportExit: return { "TransportExit", "TransportExit", "" };
        case MoveSplineFlagEnum::Unknown_0x20000: return { "Unknown_0x20000", "Unknown_0x20000", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Unknown_0x40000: return { "Unknown_0x40000", "Unknown_0x40000", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Backward: return { "Backward", "Backward", "" };
        case MoveSplineFlagEnum::SmoothGroundPath: return { "SmoothGroundPath", "SmoothGroundPath", "" };
        case MoveSplineFlagEnum::CanSwim: return { "CanSwim", "CanSwim", "" };
        case MoveSplineFlagEnum::UncompressedPath: return { "UncompressedPath", "UncompressedPath", "" };
        case MoveSplineFlagEnum::Unknown_0x800000: return { "Unknown_0x800000", "Unknown_0x800000", "NOT VERIFIED" };
        case MoveSplineFlagEnum::FastSteering: return { "FastSteering", "FastSteering", "Predicts spline only 500ms into the future for smoothing instead of 1s (making turns sharper) and turns off clientside obstacle detection" };
        case MoveSplineFlagEnum::Animation: return { "Animation", "Animation", "Plays animation after some time passed" };
        case MoveSplineFlagEnum::Parabolic: return { "Parabolic", "Parabolic", "Affects elevation computation, can't be combined with Falling flag" };
        case MoveSplineFlagEnum::FadeObject: return { "FadeObject", "FadeObject", "" };
        case MoveSplineFlagEnum::Steering: return { "Steering", "Steering", "" };
        case MoveSplineFlagEnum::UnlimitedSpeed: return { "UnlimitedSpeed", "UnlimitedSpeed", "" };
        case MoveSplineFlagEnum::Unknown_0x40000000: return { "Unknown_0x40000000", "Unknown_0x40000000", "NOT VERIFIED" };
        case MoveSplineFlagEnum::Unknown_0x80000000: return { "Unknown_0x80000000", "Unknown_0x80000000", "NOT VERIFIED" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<MoveSplineFlagEnum>::Count() { return 33; }

template <>
TC_API_EXPORT MoveSplineFlagEnum EnumUtils<MoveSplineFlagEnum>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return MoveSplineFlagEnum::None;
        case 1: return MoveSplineFlagEnum::Unknown_0x1;
        case 2: return MoveSplineFlagEnum::Unknown_0x2;
        case 3: return MoveSplineFlagEnum::Unknown_0x4;
        case 4: return MoveSplineFlagEnum::Unknown_0x8;
        case 5: return MoveSplineFlagEnum::FallingSlow;
        case 6: return MoveSplineFlagEnum::Done;
        case 7: return MoveSplineFlagEnum::Falling;
        case 8: return MoveSplineFlagEnum::No_Spline;
        case 9: return MoveSplineFlagEnum::Unknown_0x100;
        case 10: return MoveSplineFlagEnum::Flying;
        case 11: return MoveSplineFlagEnum::OrientationFixed;
        case 12: return MoveSplineFlagEnum::Catmullrom;
        case 13: return MoveSplineFlagEnum::Cyclic;
        case 14: return MoveSplineFlagEnum::Enter_Cycle;
        case 15: return MoveSplineFlagEnum::Frozen;
        case 16: return MoveSplineFlagEnum::TransportEnter;
        case 17: return MoveSplineFlagEnum::TransportExit;
        case 18: return MoveSplineFlagEnum::Unknown_0x20000;
        case 19: return MoveSplineFlagEnum::Unknown_0x40000;
        case 20: return MoveSplineFlagEnum::Backward;
        case 21: return MoveSplineFlagEnum::SmoothGroundPath;
        case 22: return MoveSplineFlagEnum::CanSwim;
        case 23: return MoveSplineFlagEnum::UncompressedPath;
        case 24: return MoveSplineFlagEnum::Unknown_0x800000;
        case 25: return MoveSplineFlagEnum::FastSteering;
        case 26: return MoveSplineFlagEnum::Animation;
        case 27: return MoveSplineFlagEnum::Parabolic;
        case 28: return MoveSplineFlagEnum::FadeObject;
        case 29: return MoveSplineFlagEnum::Steering;
        case 30: return MoveSplineFlagEnum::UnlimitedSpeed;
        case 31: return MoveSplineFlagEnum::Unknown_0x40000000;
        case 32: return MoveSplineFlagEnum::Unknown_0x80000000;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<MoveSplineFlagEnum>::ToIndex(MoveSplineFlagEnum value)
{
    switch (value)
    {
        case MoveSplineFlagEnum::None: return 0;
        case MoveSplineFlagEnum::Unknown_0x1: return 1;
        case MoveSplineFlagEnum::Unknown_0x2: return 2;
        case MoveSplineFlagEnum::Unknown_0x4: return 3;
        case MoveSplineFlagEnum::Unknown_0x8: return 4;
        case MoveSplineFlagEnum::FallingSlow: return 5;
        case MoveSplineFlagEnum::Done: return 6;
        case MoveSplineFlagEnum::Falling: return 7;
        case MoveSplineFlagEnum::No_Spline: return 8;
        case MoveSplineFlagEnum::Unknown_0x100: return 9;
        case MoveSplineFlagEnum::Flying: return 10;
        case MoveSplineFlagEnum::OrientationFixed: return 11;
        case MoveSplineFlagEnum::Catmullrom: return 12;
        case MoveSplineFlagEnum::Cyclic: return 13;
        case MoveSplineFlagEnum::Enter_Cycle: return 14;
        case MoveSplineFlagEnum::Frozen: return 15;
        case MoveSplineFlagEnum::TransportEnter: return 16;
        case MoveSplineFlagEnum::TransportExit: return 17;
        case MoveSplineFlagEnum::Unknown_0x20000: return 18;
        case MoveSplineFlagEnum::Unknown_0x40000: return 19;
        case MoveSplineFlagEnum::Backward: return 20;
        case MoveSplineFlagEnum::SmoothGroundPath: return 21;
        case MoveSplineFlagEnum::CanSwim: return 22;
        case MoveSplineFlagEnum::UncompressedPath: return 23;
        case MoveSplineFlagEnum::Unknown_0x800000: return 24;
        case MoveSplineFlagEnum::FastSteering: return 25;
        case MoveSplineFlagEnum::Animation: return 26;
        case MoveSplineFlagEnum::Parabolic: return 27;
        case MoveSplineFlagEnum::FadeObject: return 28;
        case MoveSplineFlagEnum::Steering: return 29;
        case MoveSplineFlagEnum::UnlimitedSpeed: return 30;
        case MoveSplineFlagEnum::Unknown_0x40000000: return 31;
        case MoveSplineFlagEnum::Unknown_0x80000000: return 32;
        default: throw std::out_of_range("value");
    }
}
}
