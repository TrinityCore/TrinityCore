/*
 * Copyright 2023 AzgathCore
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum GeneralSpells
{
    SPELL_HURL_BRICK = 121762,
    SPELL_CAUSTIC_PITCH_SELECTOR = 121440,
    SPELL_QUICK_DRY_RESIN = 121447,
};

enum GeneralEvents
{
    EVEMNT_FLY_TO_OPPOSITE_SIDE_OF_BRIDGE = 1,
    EVENT_CHECK_IF_REACHED_WP,
    EVENT_CAST_GUSTING_WINDS_1,
    EVENT_CAST_GUSTING_WINDS_2,
    EVENT_CAST_GUSTING_WINDS_3,
    EVENT_CAST_HURL_BRICK,
    EVENT_CAST_CAUSTIC_PITCH,
    EVENT_CAST_QUICK_DRY_RESIN,
};

enum GeneralPoints
{
    POINT_MOVE_UP = 1,

    POINT_MAIN_SIDE_GROUND,
    POINT_MAIN_SIDE_AIR_FROM_GROUND,
    POINT_MAIN_SIDE_AIR_FROM_OTHER_SIDE,

    POINT_OTHER_SIDE_GROUND,
    POINT_OTHER_SIDE_AIR_FROM_GROUND,
    POINT_OTHER_SIDE_AIR_FROM_MAIN_SIDE,
};

//struct BridgePositionMoveStruct
//{
//    uint32 pointId;
//    Position pos;
//};

Position BridgeSidePositions[4] =
{
    { 1887.084f, 5178.723f, 131.1692f, 0.0f }, //! Ground 1
    { 1877.906f, 5187.085f, 142.7834f, 0.0f }, //! Air 1

    { 1810.470f, 5249.528f, 131.1700f, 0.0f }, //! Ground 2
    { 1818.120f, 5242.493f, 142.5388f, 0.0f }, //! Air 2
};

void AddSC_boss_wing_leader_neronok()
{
    
}