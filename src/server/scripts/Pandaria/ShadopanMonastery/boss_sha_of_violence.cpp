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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shadopan_monastery.h"

enum eSpells
{
    SPELL_SMOKE_BLADES = 106826,
    SPELL_SHA_SPIKE = 106871,
    SPELL_DISORIENTING_SMASH = 106872,
    SPELL_PARTING_SMOKE = 127576,
    SPELL_ENRAGE = 130196,

    SPELL_ICE_TRAP = 110610,
    SPELL_EXPLOSION = 106966
};

enum eEvents
{
    // Gu
    EVENT_SMOKE_BLADES = 1,
    EVENT_SHA_SPIKE = 2,
    EVENT_DISORIENTING_SMASH = 3
};

void AddSC_boss_sha_of_violence()
{
   
}
