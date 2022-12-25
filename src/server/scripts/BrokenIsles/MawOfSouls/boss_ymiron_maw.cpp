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

#include "maw_of_souls.h"
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_INTRO = 0,
    SAY_INTRO_2 = 1,
    SAY_AGGRO = 2,
    SAY_SCREAMS = 3,
    SAY_WINDS = 4,
    SAY_BANE = 5,
    SAY_ARISE = 6,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_ZERO_REGEN = 118357,
    SPELL_POWER = 167922,
    SPELL_KNEELING_VISUAL = 197227, //State
    SPELL_SOUL_SIPHON = 194665, //Hit Target NPC 102375
    SPELL_DARK_SLASH = 193211,
    SPELL_SCREAMS_OF_DEAD = 193364,
    SPELL_WINDS_OF_NORTHREND = 193977,
    SPELL_BANE = 193460,
    SPELL_BANE_AT = 193465,
    SPELL_BANE_DMG = 193513,
    SPELL_BANE_NOVA = 200194,
    SPELL_ARISE_FALLEN = 193566, //Heroic+
    SPELL_ARISE_FALLEN_SUM = 193594,

    //Trash
    SPELL_STATE = 196025,
    SPELL_INSTAKILL = 117624,

    SPELL_BREAK_CHAINS = 201375,

    SPELL_VIGOR = 203816, //Heroic+
    SPELL_MOD_SCALE = 123978,
};

enum eEvents
{
    EVENT_DARK_SLASH = 1,
    EVENT_SCREAMS_OF_DEAD = 2,
    EVENT_WINDS_OF_NORTHREND = 3,
    EVENT_BANE = 4,
    EVENT_ARISE_FALLEN = 5,
    EVENT_INTRO = 6,

    //Trash
    EVENT_TRASH_INTRO = 1,
    EVENT_TRASH_INTRO_2 = 2,
    EVENT_FRACTURE = 3,
    EVENT_BARBED = 4,
    EVENT_SWIRLING = 5,

    EVENT_1,
    EVENT_2,
};

enum eMisc
{
    DATA_ACHIEVEMENT = 0,
};

Position const trashPos[9] =
{
    {7390.38f, 7285.93f, 43.86f, 0.32f},
    {7381.98f, 7295.84f, 43.85f, 0.21f},
    {7393.05f, 7312.54f, 43.86f, 5.58f},
    {7387.01f, 7299.40f, 43.86f, 5.83f},
    {7393.36f, 7306.04f, 43.91f, 5.58f},
    {7384.61f, 7286.07f, 43.86f, 0.51f},
    {7386.75f, 7292.16f, 43.86f, 0.05f},
    {7386.51f, 7304.95f, 43.92f, 5.69f},
    {7360.30f, 7301.24f, 43.68f, 1.87f}
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
};

void AddSC_boss_ymiron_maw()
{
    
}
