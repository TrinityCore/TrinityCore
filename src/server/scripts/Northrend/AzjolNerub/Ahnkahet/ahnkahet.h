/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef AHNKAHET_H_
#define AHNKAHET_H_

#include "CreatureAIImpl.h"

#define AhnKahetScriptName "instance_ahnkahet"
#define DataHeader         "AK"

uint32 const EncounterCount = 5;

enum AKDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_ELDER_NADOX                = 0,
    DATA_PRINCE_TALDARAM            = 1,
    DATA_JEDOGA_SHADOWSEEKER        = 2,
    DATA_AMANITAR                   = 3,
    DATA_HERALD_VOLAZJ              = 4,

    // Additional Data
    DATA_SPHERE_1                   = 5,
    DATA_SPHERE_2                   = 6,
    DATA_PRINCE_TALDARAM_PLATFORM   = 7
};

enum AKCreatureIds
{
    NPC_ELDER_NADOX                 = 29309,
    NPC_PRINCE_TALDARAM             = 29308,
    NPC_JEDOGA_SHADOWSEEKER         = 29310,
    NPC_AMANITAR                    = 30258,
    NPC_HERALD_VOLAZJ               = 29311,

    // Elder Nadox
    NPC_AHNKAHAR_GUARDIAN           = 30176,
    NPC_AHNKAHAR_SWARMER            = 30178,

    // Jedoga Shadowseeker
    NPC_TWILIGHT_INITIATE           = 30114,
    NPC_TWILIGHT_VOLUNTEER          = 30385,
    NPC_TWILIGHT_WORSHIPPER         = 30111,
    NPC_JEDOGA_CONTROLLER           = 30181,

    // Amanitar
    NPC_HEALTHY_MUSHROOM            = 30391,
    NPC_POISONOUS_MUSHROOM          = 30435,

    // Herald Volazj
    //NPC_TWISTED_VISAGE_1          = 30621,
    //NPC_TWISTED_VISAGE_2          = 30622,
    //NPC_TWISTED_VISAGE_3          = 30623,
    //NPC_TWISTED_VISAGE_4          = 30624,
    NPC_TWISTED_VISAGE              = 30625
};

enum AKGameObjectIds
{
    GO_PRINCE_TALDARAM_GATE         = 192236,
    GO_PRINCE_TALDARAM_PLATFORM     = 193564,
    GO_SPHERE_1                     = 193093,
    GO_SPHERE_2                     = 193094
};

template <class AI, class T>
inline AI* GetAhnKahetAI(T* obj)
{
    return GetInstanceAI<AI>(obj, AhnKahetScriptName);
}

#define RegisterAhnKahetCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAhnKahetAI)
#define RegisterAhnKahetGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetAhnKahetAI)

#endif // AHNKAHET_H_
