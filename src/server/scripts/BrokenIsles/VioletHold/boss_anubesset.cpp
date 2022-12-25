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

enum Spells
{
    SPELL_MANDIBLE_STRIKE = 202217,
    SPELL_IMPALE = 202341,
    SPELL_IMPALE_TRIG = 202350,
    SPELL_CALL_OF_THE_SWARM = 201863,

    //Spitting Scarab
    SPELL_POISON_SPIT = 202300,
    SPELL_BURROW = 202304,

    //Blistering Beetle
    SPELL_BURROW_VISUAL = 202496,
    SPELL_FIXATE = 202480,
    SPELL_BLISTERING_OOZE_AT = 202483,
    SPELL_BLISTERING_OOZE_AT_2 = 202487,
    SPELL_BLISTERING_OOZE_DMG = 202485,
    SPELL_SUICIDE = 117624,

    //Heroic+
    SPELL_SUM_BEETLE_FILTER = 202526,
    SPELL_SUM_OOZING_BEETLE = 202513,
};

enum eEvents
{
    EVENT_MANDIBLE_STRIKE = 1,
    EVENT_IMPALE = 2,
    EVENT_CALL_OF_THE_SWARM = 3,
    EVENT_SUMMON_OOZING_BEETLE = 4,

    EVENT_1,
    EVENT_2,
};

void AddSC_boss_anubesset()
{
  
}
