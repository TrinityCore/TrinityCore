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

#ifndef STORMSTOUT_BREWERY_H_
#define STORMSTOUT_BREWERY_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define SBScriptName "instance_stormstout_brewery"

enum DataTypes
{
    DATA_OOK_OOK         = 1,
    DATA_HOPTALLUS       = 2,
    DATA_YAN_ZHU         = 3,
    DATA_HOPTALLUS_EVENT =4
};

enum CreaturesIds
{
    NPC_OOK_OOK                = 56637,
    NPC_BEER_BARREL_BUNNY      = 66215,
    NPC_HOPTALLUS              = 56717,
    NPC_YAN_ZHU                = 59479,
    NPC_ANCESTRAL_BREWMASTER   = 59075, ///< Friendly.
    NPC_ANCESTRAL_BREWMASTER_1 = 59075,
    NPC_BLOATED_BREW_ALEMENTAL = 59518,
    NPC_ANCESTRAL_BREWMASTER_2 = 65375,
    NPC_ANCESTRAL_BREWMASTER_3 = 65376
};

#endif // STORMSTOUT_BREWERY_H_
