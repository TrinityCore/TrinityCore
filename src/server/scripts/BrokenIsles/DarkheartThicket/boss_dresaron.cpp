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

#include "darkheart_thicket.h"

enum Spells
{
    SPELL_BREATH_OF_CORRUPTION = 199329,
    SPELL_BREATH_OF_CORRUPTION_SUM = 199332,
    SPELL_BREATH_OF_CORRUPTION_DMG = 191325,
    SPELL_EARTHSHAKING_ROAR = 199389,
    SPELL_DOWN_DRAFT = 199345,

    //Egg
    SPELL_SUM_BIRTH_WHELPLING_1 = 199304, //Npc 100528 - unuseble?
    SPELL_SUM_BIRTH_WHELPLING_2 = 199313, //Npc 101074
    //Emerald Egg
    SPELL_HATESPAWN_ABOMINATION = 220921,

    //Whelpling
    SPELL_HATESPAWN_DETONATION = 212797,
};

enum eEvents
{
    EVENT_BREATH_OF_CORRUPTION = 1,
    EVENT_EARTHSHAKING_ROAR = 2,
    EVENT_DOWN_DRAFT = 3,
};

enum Misc
{
    ABOMINATION_KILLED = 1,
    ACTION_1,
};

void AddSC_boss_dresaron()
{
    
}
