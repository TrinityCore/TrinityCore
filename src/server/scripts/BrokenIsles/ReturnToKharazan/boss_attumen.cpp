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

#include "new_karazhan.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_INTANGIBLE_PRESENCE = 1,
    SAY_RIDERLESS = 2,
    SAY_DEATH = 3,
    SAY_MIGHTY_STOMP = 4,
};

enum Spells
{
    ///Midnight
    SPELL_STAMP_VISUAL = 227640,
    SPELL_INTANGIBLE_PRESENCE = 227404,
    SPELL_INTANGIBLE_PRESENCE_VIS_1 = 227436,
    SPELL_INTANGIBLE_PRESENCE_VIS_2 = 227437,
    SPELL_INTANGIBLE_PRESENCE_DMG = 227415,
    SPELL_INTANGIBLE_PRESENCE_DMG_2 = 227419,
    SPELL_MIGHTY_STOMP = 227363,
    SPELL_SPECTRAL_CHARGE = 227587,
    SPELL_SPECTRAL_CHARGE_AT = 227367,

    SPELL_SHIMMERING = 227422,

    //Phase 2
    SPELL_RIDERLESS = 227338,
    SPELL_MEZAIR = 227339,

    SPELL_ENRAGE = 228895,

    ///Attumen
    SPELL_MOUNTED_STRIKE = 227636,
    SPELL_ANIM_DISMOUNTED = 227474,
    SPELL_MORTAL_STRIKE = 227493,
    SPELL_STAMP = 227638,
    SPELL_SHARED_SUFFERING = 228852,
    SPELL_FEIGN_DEATH = 114371,
};

enum eEvents
{
    ///Midnight
    EVENT_INTANGIBLE_PRESENCE = 1,
    EVENT_MIGHTY_STOMP = 2,
    EVENT_SPECTRAL_CHARGE = 3,

    //Phase 2
    EVENT_CHECK_HEALTH = 4,
    EVENT_MEZAIR = 5,
    EVENT_MOVING_TO_HUNTSMAN = 6,

    ///Attumen
    EVENT_MORTAL_STRIKE = 1,
    EVENT_SHARED_SUFFERING = 2,
    EVENT_CHECK_VICTIM = 3,
};

enum ePhase
{
    PHASE_1 = 0,
    PHASE_2
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
    EVENT_2,
};

void AddSC_boss_attumen_new()
{
    
}
