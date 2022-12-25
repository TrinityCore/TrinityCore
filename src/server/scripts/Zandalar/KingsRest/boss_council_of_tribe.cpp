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

#include "GameObject.h"
#include "GameObjectAI.h"
#include "kings_rest.h"

enum Spells
{
    SPELL_SEVERING_AXE = 266231,
    SPEL_WHIRLING_AXES = 266206,
    SPELL_DEBILATING_BACKHAND = 266237,
    SPELL_BARREL_THROUGH = 266951,
    SPELL_BARREL_THROUGH_CHARGE = 266941,
    SPELL_BARREL_THROUGH_AOE = 266940,
    SPELL_LIGHTNING_BOLT = 267308,
    SPELL_POISON_NOVA = 267273,
    SPELL_CALL_OF_THE_ELEMENTS = 267060,
};

enum Events
{
    EVENT_SEVERING_AXE = 1,
    EVENT_WHIRLING_AXES,
    EVENT_DEBILATING_BACKHAND,
    EVENT_BARREL_THROUGH,
    EVENT_LIGHTNING_BOLT,
    EVENT_POISON_NOVA,
    EVENT_CALL_OF_THE_ELEMENTS
};

const Position middle_pos = { -1101.0f, 2911.0f, 775.560f, 3.11f };
const Position akali_pos = { -1122.0f, 2931.0f, 775.560f, 5.29f };
const Position zanazal_pos = { -1135.0f, 2911.0f, 775.577f, 0.0f };

void AddSC_boss_council_of_tribes()
{
    
}
