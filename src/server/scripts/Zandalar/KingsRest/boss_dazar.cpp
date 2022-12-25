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

#include "ScriptedCreature.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "kings_rest.h"

enum Spells
{
    SPELL_BLADE_COMBO = 268586,
    SPELL_QUAKING_LEAP = 268932,
    SPELL_GALE_SLASH = 268403,
    SPELL_GALE_SLASH_AT_DAMAGE = 268419,
};

enum Events
{
    EVENT_BLADE_COMBO = 1,
    EVENT_QUAKING_LEAP,
    EVENT_GALE_SLASH,
    EVENT_IMPALING_SPEAR
};

void AddSC_boss_dazar_the_first_king()
{
    
}
