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

#ifndef SHADOPAN_MONASTERY_H_
#define SHADOPAN_MONASTERY_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

uint32 const EncounterCount = 4;

#define MAX_NOVICE              24

enum DataTypes
{
    DATA_GU_CLOUDSTRIKE         = 0,
    DATA_MASTER_SNOWDRIFT       = 1,
    DATA_SHA_VIOLENCE           = 2,
    DATA_TARAN_ZHU              = 3,

    DATA_RANDOM_FIRST_POS       = 4,
    DATA_RANDOM_SECOND_POS      = 5,
    DATA_RANDOM_MINIBOSS_POS    = 6,

    DATA_DEFEATED_NOVICE        = 7,
    DATA_DEFEATED_MINIBOSS      = 8,
    DATA_DEFEATED_CLONES        = 9,

    DATA_ARCHERY                = 10,

    MAX_DATA
};

enum CreaturesIds
{
    NPC_GU_CLOUDSTRIKE          = 56747,
    NPC_MASTER_SNOWDRIFT        = 56541,
    NPC_SHA_VIOLENCE            = 56719,
    NPC_TARAN_ZHU               = 56884,

    // Gu Cloudstrike
    NPC_AZURE_SERPENT           = 56754,
    NPC_GUARDIAN                = 59741,

    // Master Snowdrift
    NPC_NOVICE                  = 56395,
    NPC_SNOWDRIFT_POSITION      = 56397,

    NPC_FLAGRANT_LOTUS          = 56472,
    NPC_FLYING_SNOW             = 56473,

    NPC_SNOWDRIFT_CLONE         = 56713,

    // Sha of Violence
    NPC_LESSER_VOLATILE_ENERGY  = 66652,

    // Trashs
    NPC_ARCHERY_FIRST           = 64549,
    NPC_ARCHERY_SECOND          = 56767,
    NPC_ARCHERY_TARGET          = 64550,

    NPC_RESIDUAL_OF_HATRED      = 58803,
    NPC_VESTIGE_OF_HATRED       = 58807,
    NPC_FRAGMENT_OF_HATRED      = 58810
};

enum ObjectsIds
{
    GO_CLOUDSTRIKE_ENTRANCE     = 210863,
    GO_CLOUDSTRIKE_EXIT         = 210864,

    GO_SNOWDRIFT_ENTRANCE       = 213194,
    GO_SNOWDRIFT_FIRE_WALL      = 212908,
    GO_SNOWDRIFT_DOJO_DOOR      = 210800,
    GO_SNOWDRIFT_EXIT           = 210862,

    GO_SNOWDRIFT_POSSESSIONS    = 214519,

    GO_SHA_ENTRANCE             = 210867,
    GO_SHA_EXIT                 = 210866,

};

enum SharedActions
{
    ACTION_NOVICE_DONE          = 1,
    ACTION_MINIBOSS_DONE        = 2
};

enum SharedSpells
{
    SPELL_HATE                  = 107085,
    SPELL_HAZE_OF_HATE          = 107087,
    SPELL_HAZE_OF_HATE_VISUAL   = 107217
};

#endif // SHADOPAN_MONASTERY_H_
