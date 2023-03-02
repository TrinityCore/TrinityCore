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
#include "CreatureGroups.h"

enum Says
{
    SAY_AGGRO           = 0,
    SAY_VILEBLOOD       = 1,
    SAY_FIXATION        = 2,
    SAY_DEATH           = 3,
};

enum Spells
{
    //Kyrak
    SPELL_DEBILITATING_FIXATION    = 177660,
    SPELL_VILEBLOOD_SERUM_TARGET   = 161207,
    SPELL_VILEBLOOD_SERUM_FIENDLY  = 161235,
    SPELL_VILEBLOOD_SERUM_AT       = 161210,
    SPELL_REJUVENATING_SERUM       = 161203,
    SPELL_SALVE_OF_TOXIC_FUMES     = 162589,
    //Trash
    SPELL_MONSTROUS_CLAWS          = 155032,
    SPELL_ERUPTION                 = 155037
};

enum eEvents
{
    //Kyrak
    EVENT_FIXATION      = 1,
    EVENT_VILEBLOOD     = 2,
    EVENT_REJUVENATING  = 3,
    EVENT_TOXIC_FUMES   = 4,
    //Trash
    EVENT_ERUPTION      = 1
};

Position const drakonidSpawn[2] = 
{
    {86.39f, -328.90f, 91.52f, 1.9f},
    {69.96f, -328.22f, 91.54f, 0.5f}
};

void AddSC_boss_kyrak()
{
   
}
