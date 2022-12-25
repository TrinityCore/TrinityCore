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
#include "SpellAuras.h"

enum eSpells
{
    SPELL_CORRUPTED = 131530,

    SPELL_RISING_HATE = 107356,
    SPELL_RING_OF_MALICE = 131521,
    SPELL_SHA_BLAST = 114999,
    SPELL_SUMMON_GRIPPING_HATRED = 115002,

    // Gripping Hatred
    SPELL_GRIP_OF_HATE = 115010,
    SPELL_POOL_OF_SHADOWS = 112929
};

enum eEvents
{
    EVENT_RISING_HATE = 1,
    EVENT_RING_OF_MALICE = 2,
    EVENT_SHA_BLAST = 3,
    EVENT_SUMMON_GRIPPING_HATRED = 4,

    EVENT_GRIP_OF_HATE = 5
};

void AddSC_boss_taran_zhu()
{
   
}
