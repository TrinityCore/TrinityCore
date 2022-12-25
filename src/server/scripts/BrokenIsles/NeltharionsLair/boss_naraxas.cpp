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

#include "neltharions_lair.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_SUM = 0,
    SAY_EMOTE = 1,
};

enum Spells
{
    SPELL_INTRO_MYSTIC = 209625, //Boss 03 Intro Mystic Cast - визуально прячется?
    SPELL_INTRO_EMERGE = 209641, //Boss 03 Intro Emerge - hit npc 105766
    SPELL_GAIN_ENERGY = 200086,
    SPELL_PUTRID_SKIES = 198963,
    SPELL_FRENZY = 199775,
    SPELL_RANCID_MAW = 205549,
    SPELL_TOXIC_WRETCH = 210150,
    SPELL_TOXIC_WRETCH_AT = 210159,
    SPELL_SPIKED_TONGUE_CHANNEL = 199178,
    SPELL_SPIKED_TONGUE_CHECK_R = 199335, //Check Radius
    SPELL_SPIKED_TONGUE_RIDE = 205417,
    SPELL_SPIKED_TONGUE = 199176,
    SPELL_SPIKED_TONGUE_AT = 199187,
    SPELL_SPIKED_TONGUE_DMG = 199705,
    SPELL_SPIKED_TONGUE_JUMP = 204136,
    SPELL_RAVENOUS = 199246,
    SPELL_DEVOUR_FANATIC = 216797,

    //Heroic
    SPELL_CALL_ANGRY_CROWD = 217028,

    //Tresh
    SPELL_JUMP_VISUAL = 184483,
    SPELL_FANATICS_SACRIFICE = 209906,
    SPELL_RANCID_MAW_ROOT = 205609, //Movement speed reduced by 80%.
    SPELL_FANATIC_SACRIFICE = 209902,

    SPELL_HURLING_ROCKS = 199245,
};

enum eEvents
{
    EVENT_RANCID_MAW = 1,
    EVENT_TOXIC_WRETCH = 2,
    EVENT_SUM_WORMSPEAKER = 3,

    //Heroic
    EVENT_CALL_ANGRY_CROWD = 4,

    EVENT_1,
    EVENT_2,
};

enum Misc
{
    DATA_ACHIEVEMENT,
};

Position const speakerPos[6] =
{
    {3045.07f, 1807.39f, -44.13f, 3.54f},
    {3048.89f, 1799.60f, -45.43f, 3.35f},
    {3033.45f, 1791.01f, -61.25f, 2.44f},
    {3024.77f, 1802.29f, -60.10f, 2.44f},
    {2995.22f, 1808.65f, -61.29f, 1.82f},
    {3009.69f, 1826.31f, -60.35f, 3.08f}
};

void AddSC_boss_naraxas()
{
    
}
