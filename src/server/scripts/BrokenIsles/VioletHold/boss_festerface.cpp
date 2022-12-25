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

#include "violet_hold_assault.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_VOMIT = 1,
    SAY_YUM = 2,
    // SAY_          = 3  //Taste better going in!
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_FESTERFACE_AGGRO = 202000,
    SPELL_CONGEALING_VOMIT = 201598,
    SPELL_CONGEALING_VOMIT_VIS = 201624,
    SPELL_CONGEALING_VOMIT_SUM = 201569,
    SPELL_YUM = 201715,

    //Summons
    SPELL_GREEN_SLIME_COSMETICS = 205156,
    SPELL_FETID_STENCH = 201476,
    SPELL_RECONGEALING = 201495,
    SPELL_RECONGEALING_SEARCH = 202265, //Search Festerface

    //Heroic
    SPELL_ENERGY_TRACKER = 207677,
    SPELL_SUM_BLACK_BILE = 201729,
};

enum eEvents
{
    EVENT_CONGEALING_VOMIT = 1,
};

enum Misc
{
    DATA_ACHIEVEMENT,
};

enum Add
{
    NPC_BLACK_BILE = 102169,
};

void AddSC_boss_festerface()
{
    
}
