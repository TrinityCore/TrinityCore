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

#ifndef __ALTERAC_VALLEY_H
#define __ALTERAC_VALLEY_H

enum AlteracValleySharedActions
{
    ACTION_BUFF_YELL = -30001,
    ACTION_AV_INTERACT_CAPTURABLE_OBJECT = 1,
    ACTION_AV_CAPTURE_CAPTURABLE_OBJECT = 2,

    ACTION_TURN_IN_SCRAPS = 3,
    ACTION_TURN_IN_COMMANDER_1 = 4,
    ACTION_TURN_IN_COMMANDER_2 = 5,
    ACTION_TURN_IN_COMMANDER_3 = 6,
    ACTION_TURN_IN_BOSS_1,
    ACTION_TURN_IN_BOSS_2,
    ACTION_TURN_IN_NEAR_MINE,
    ACTION_TURN_IN_OTHER_MINE,
    ACTION_TURN_IN_RIDER_HIDE,
    ACTION_TURN_IN_RIDER_TAME
};

#endif
