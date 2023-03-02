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

enum Spells
{
    SPELL_MAGMA_SPIT            = 155050,
    SPELL_RIPPING_CLAW          = 155065,
    SPELL_ENGULFING_FIRE        = 154996,
    SPELL_ENGULFING_FIRE_AURA   = 155025,
    SPELL_ENGULFING_FIRE_AT     = 155029,
    SPELL_SWIRLING_WINDS        = 167203,
    SPELL_FIRE_STORM            = 155070,
    SPELL_FIRE_STORM_DMG        = 155073,
    SPELL_FIRE_BREATH_CHECK     = 155605,
    SPELL_FIRE_BREATH_DMG       = 155606,
    SPELL_BURNING_RAGE          = 155620,
};

enum eEvents
{
    EVENT_MAGMA_SPIT            = 1,
    EVENT_RIPPING_CLAW          = 2,
    EVENT_ENGULFING_FIRE        = 3,
    EVENT_FLY                   = 4,
    EVENT_FIRE_STORM            = 5,
    EVENT_FIRE_BREATH           = 6,
    EVENT_FIRE_BREATH_DMG       = 7,
    EVENT_GROUND                = 8,
    EVENT_BURNING_RAGE          = 9,
    EVENT_ENGULFING_FIRE_END    = 10,
};

enum eSays
{
    SAY_WARN_ENGULFING_FIRE     = 0,
};

enum ePath
{
    PATH_FIRE_R  = 7681300,
    PATH_FIRE_L  = 7683700
};

enum ePhase
{
    PHASE_BATTLE    = 1,
    PHASE_FLY       = 2
};

void AddSC_boss_ragewing_untamed()
{
   
}
