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

#ifndef CUFProfile_h__
#define CUFProfile_h__

#include "Define.h"
#include <bitset>
#include <string>

/// Maximum number of CompactUnitFrames profiles
#define MAX_CUF_PROFILES 5

/// Bit index used in the many bool options of CompactUnitFrames
enum CUFBoolOptions
{
    CUF_KEEP_GROUPS_TOGETHER,
    CUF_DISPLAY_PETS,
    CUF_DISPLAY_MAIN_TANK_AND_ASSIST,
    CUF_DISPLAY_HEAL_PREDICTION,
    CUF_DISPLAY_AGGRO_HIGHLIGHT,
    CUF_DISPLAY_ONLY_DISPELLABLE_DEBUFFS,
    CUF_DISPLAY_POWER_BAR,
    CUF_DISPLAY_BORDER,
    CUF_USE_CLASS_COLORS,
    CUF_DISPLAY_NON_BOSS_DEBUFFS,
    CUF_DISPLAY_HORIZONTAL_GROUPS,
    CUF_LOCKED,
    CUF_SHOWN,
    CUF_AUTO_ACTIVATE_2_PLAYERS,
    CUF_AUTO_ACTIVATE_3_PLAYERS,
    CUF_AUTO_ACTIVATE_5_PLAYERS,
    CUF_AUTO_ACTIVATE_10_PLAYERS,
    CUF_AUTO_ACTIVATE_15_PLAYERS,
    CUF_AUTO_ACTIVATE_25_PLAYERS,
    CUF_AUTO_ACTIVATE_40_PLAYERS,
    CUF_AUTO_ACTIVATE_SPEC_1,
    CUF_AUTO_ACTIVATE_SPEC_2,
    CUF_AUTO_ACTIVATE_PVP,
    CUF_AUTO_ACTIVATE_PVE,
    CUF_UNK_145,
    CUF_UNK_156,
    CUF_UNK_157,

    // The unks is _LOCKED and _SHOWN and _DYNAMIC, unknown order

    CUF_BOOL_OPTIONS_COUNT
};

/// Represents a CompactUnitFrame profile
struct CUFProfile
{
    CUFProfile() : ProfileName(), BoolOptions() // might want to change default value for options
    {
        FrameHeight     = 0;
        FrameWidth      = 0;
        SortBy          = 0;
        HealthText      = 0;
        TopPoint        = 0;
        BottomPoint     = 0;
        LeftPoint       = 0;
        TopOffset       = 0;
        BottomOffset    = 0;
        LeftOffset      = 0;
    }

    CUFProfile(std::string const& name, uint16 frameHeight, uint16 frameWidth, uint8 sortBy, uint8 healthText, uint32 boolOptions,
        uint8 topPoint, uint8 bottomPoint, uint8 leftPoint, uint16 topOffset, uint16 bottomOffset, uint16 leftOffset)
        : ProfileName(name), BoolOptions((int)boolOptions)
    {
        FrameHeight     = frameHeight;
        FrameWidth      = frameWidth;
        SortBy          = sortBy;
        HealthText      = healthText;
        TopPoint        = topPoint;
        BottomPoint     = bottomPoint;
        LeftPoint       = leftPoint;
        TopOffset       = topOffset;
        BottomOffset    = bottomOffset;
        LeftOffset      = leftOffset;
    }

    std::string ProfileName;
    uint16 FrameHeight;
    uint16 FrameWidth;
    uint8 SortBy;
    uint8 HealthText;

    // LeftAlign, TopAlight, BottomAlign
    uint8 TopPoint;
    uint8 BottomPoint;
    uint8 LeftPoint;

    // LeftOffset, TopOffset and BottomOffset
    uint16 TopOffset;
    uint16 BottomOffset;
    uint16 LeftOffset;

    std::bitset<CUF_BOOL_OPTIONS_COUNT> BoolOptions;

    // More fields can be added to BoolOptions without changing DB schema (up to 32, currently 27)
};

#endif // CUFProfile_h__
