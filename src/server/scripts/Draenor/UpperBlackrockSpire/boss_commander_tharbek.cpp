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

#include "upper_blackrock_spire.h"

#define MIN_X 111.0f
#define MAX_X 194.0f
#define MIN_Y -454.0f   
#define MAX_Y -385.0f
#define MIN_Z 100.0f
#define MAX_Z 120.0f

enum Says
{
    SAY_DEATH           = 0,
};

enum Spells
{
    //Tharbek
    SPELL_DIALOG_1              = 174129,
    SPELL_DIALOG_2              = 174138,
    SPELL_DIALOG_3              = 174142,
    SPELL_IRON_RAGE             = 161985,
    SPELL_IRON_REAVER           = 161987,
    SPELL_IMBUED_IRON_AXE       = 162085,
    SPELL_IMBUED_IRON_AXE_AURA  = 162092,
    SPELL_IRON_AXE              = 161765,
    //Skyreaver
    SPELL_RIDE_VEHICLE          = 43671,
    SPELL_NOXIOUS_SPIT          = 161811,
    SPELL_INCINERATING_BREATH   = 161883,

    //Christmas
    SPELL_CHRISTMAS_CAP         = 176922
};

enum eEvents
{
    EVENT_SUMMON             = 1,
    EVENT_SUMMON_2,
    EVENT_SUMMON_3,
    EVENT_SUMMON_4,
    EVENT_SUMMONS_ATTACK     = 5,
    EVENT_IRON_REAVER        = 6,
    EVENT_IMBUED_AXE         = 7,
    EVENT_IRON_AXE           = 8,
    //Skyreaver
    EVENT_NOXIOUS_SPIT       = 1,
    EVENT_BREATH             = 2,
    //Other
    EVENT_RANDOM_POS         = 1,
};

enum Miscs
{
    ACTION_1 = 1,
    ACTION_2,
};

void AddSC_boss_commander_tharbek()
{

}
