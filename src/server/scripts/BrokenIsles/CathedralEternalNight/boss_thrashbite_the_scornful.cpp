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
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_PULVERISING = 1,
    SAY_SCORNFUL = 2,
    SAY_SCORNFUL_DMG = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_PULVERIZING_CUDGEL = 237276,  // 5 + 27
    SPELL_HEAVE_CUDGEL = 243124, // 15 (7) + 38 + summon + 243158
    SPELL_SCORNFUL_GAZE = 237726,  //  27 + repeat 
    SPELL_SCORNFUL_GAZE_DMG = 238469,
    SPELL_SCORNFUL_GAZE_STUN = 240547,

    // mythic summon book
};

enum eEvents
{
    EVENT_PULVERIZING_CUDGEL = 1,
    EVENT_HEAVE_CUDGEL,
    EVENT_SCORNFUL_GAZE,
    EVENT_SCORNFUL_DMG,
    EVENT_SCORNFUL_STUN
};

enum BooksNpc
{
    NPC_FICTIONAL_BOOK = 121384,
    NPC_SATIRICAL_BOOK = 121364,
    NPC_BIOGRAPHICAL_BOOK = 121392,
};


std::map<uint32, uint32> npc_books =
{
    {0, NPC_FICTIONAL_BOOK},
    {1, NPC_SATIRICAL_BOOK},
    {2, NPC_BIOGRAPHICAL_BOOK}
};

void AddSC_boss_thrashbite_the_scornful()
{
   
}
