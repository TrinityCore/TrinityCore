/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_BLACKWING_LAIR_H
#define DEF_BLACKWING_LAIR_H

#include "CreatureAIImpl.h"

uint32 const EncounterCount     = 8;

#define BWLScriptName "instance_blackwing_lair"
#define DataHeader    "BWL"

enum BWLEncounter
{
    // Encounter States/Boss GUIDs
    DATA_RAZORGORE_THE_UNTAMED  = 0,
    DATA_VAELASTRAZ_THE_CORRUPT = 1,
    DATA_BROODLORD_LASHLAYER    = 2,
    DATA_FIREMAW                = 3,
    DATA_EBONROC                = 4,
    DATA_FLAMEGOR               = 5,
    DATA_CHROMAGGUS             = 6,
    DATA_NEFARIAN               = 7,

    // Additional Data
    DATA_LORD_VICTOR_NEFARIUS   = 8
};

enum BWLCreatureIds
{
    NPC_RAZORGORE               = 12435,
    NPC_BLACKWING_DRAGON        = 12422,
    NPC_BLACKWING_TASKMASTER    = 12458,
    NPC_BLACKWING_LEGIONAIRE    = 12416,
    NPC_BLACKWING_WARLOCK       = 12459,
    NPC_VAELASTRAZ              = 13020,
    NPC_BROODLORD               = 12017,
    NPC_FIREMAW                 = 11983,
    NPC_EBONROC                 = 14601,
    NPC_FLAMEGOR                = 11981,
    NPC_CHROMAGGUS              = 14020,
    NPC_VICTOR_NEFARIUS         = 10162,
    NPC_NEFARIAN                = 11583
};

enum BWLGameObjectIds
{
    GO_BLACK_DRAGON_EGG         = 177807,
    GO_PORTCULLIS               = 176965,
    GO_DRAKE_RIDER_PORTCULLIS   = 175185,
    GO_ALTERAC_VALLEY_GATE      = 180424,
    GO_GATE                     = 185483,
    GO_VACCUUM_EXIT_GATE        = 181125
};

enum BWLEvents
{
    EVENT_RAZOR_SPAWN       = 1,
    EVENT_RAZOR_PHASE_TWO   = 2,
    EVENT_RESPAWN_NEFARIUS  = 3
};

enum BWLMisc
{
    // Razorgore Egg Event
    ACTION_PHASE_TWO            = 1,
    DATA_EGG_EVENT
};

template <class AI, class T>
inline AI* GetBlackwingLairAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BWLScriptName);
}

#endif
