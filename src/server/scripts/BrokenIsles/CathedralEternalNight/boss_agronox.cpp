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

#include "cathedral_of_eternal_night.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_FLUMINATING_DEBUFF = 1,
    SAY_VINES = 2,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_TIMBER_SMASH = 235751, // 5 + 31
    SPELL_FULMINATING_LASHERS = 236527, // 10 + 30 (only 2 times)
    SPELL_FULMINATING_LASHERS_DEBUFF = 236524, // 10 + 20 

    // mythic
    SPELL_SUCCULENT_LASHERS = 236639, // 18 +/- 36
    SPELL_NATURE_HEAL = 242199, //! i don't know, where is it use

    // adds
    SPELL_FOCUS = 243613,
    SPELL_CHOKING_VINES_JUMP = 236651, // 24 + 30 (+12)
    SPELL_CHOKING_VINES_DMG = 238598,
};

Position const adds_pos[5]
{
    {-500.26f, 2541.83f, 388.13f, 4.49f},
    {-497.23f, 2534.99f, 388.13f, 4.01f},
    {-536.12f, 2551.06f, 388.13f, 4.89f},
    {-545.49f, 2548.70f, 388.13f, 4.99f},
    {-548.39f, 2539.13f, 388.13f, 5.13f}
};

Position const vines_pos[4]
{
    {-500.55f, 2536.22f, 388.27f, 4.31f},
    {-550.22f, 2534.58f, 388.13f, 5.28f},
    {-550.64f, 2501.10f, 388.17f, 5.98f},
    {-493.73f, 2507.01f, 388.16f, 3.95f}
};

enum eEvents
{
    EVENT_TIMBER_SMASH = 1,
    EVENT_FLUMINATING,
    EVENT_FLUMINATING_2,
    EVENT_FLUMINATING_DEBUFF,
    EVENT_CHOKING_VINES,

    EVENT_SUCCULENT_LAHSERS
};

void AddSC_boss_agronox()
{
    
}
