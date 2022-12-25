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

#include "shadopan_monastery.h"
#include "SpellAuras.h"

enum eSpells
{
    SPELL_STEALTH_COSMETIC = 91194,
    SPELL_CRISE = 128248,
    SPELL_ICE_ARROW = 126114,
    SPELL_EXPLOSION_DAMAGE = 106966,
    SPELL_PURIFICATION_RITUAL = 111690,
    SPELL_APPARITIONS_AURA = 112060,

    // Residual Hatred
    SPELL_CURSE_OF_AGONY = 112999,
    SPELL_RING_OF_MALICE = 112932,
    SPELL_SHADOW_BOLT = 112998,

    // Vestige of Hatred
    SPELL_BLACK_CLEAVE = 113020,
    SPELL_DEATH_GRIP = 113021,
    SPELL_ICE_TRAP = 135382,
    SPELL_TOUCH_OF_WEAKNESS = 113022,

    // Fragment of Hatred
    //SPELL_ICE_TRAP              = 135382,
    SPELL_SINISTER_STRIKE = 112931,
    SPELL_VOLLEY_OF_HATRED = 112911
};

enum eEvents
{
    // Residual Hatred
    EVENT_CURSE_OF_AGONY = 1,
    EVENT_RING_OF_MALICE = 2,
    EVENT_SHADOW_BOLT = 3,

    // Vestige of Hatred
    EVENT_BLACK_CLEAVE = 4,
    EVENT_DEATH_GRIP = 5,
    EVENT_ICE_TRAP = 6,
    EVENT_TOUCH_OF_WEAKNESS = 7,

    // Fragment of Hatred
    //EVENT_ICE_TRAP              = 8,
    EVENT_SINISTER_STRIKE = 9,
    EVENT_VOLLEY_OF_HATRED = 10
};

void AddSC_shadopan_monastery()
{
    
}
