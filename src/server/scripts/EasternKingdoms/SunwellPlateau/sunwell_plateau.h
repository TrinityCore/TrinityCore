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

#ifndef SUNWELL_PLATEAU_H
#define SUNWELL_PLATEAU_H

#include "CreatureAIImpl.h"

#define SunwellPlateauScriptName "instance_sunwell_plateau"
#define DataHeader "SWP"

uint32 const EncounterCount = 6;

enum SWPDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_KALECGOS                            = 0,
    DATA_BRUTALLUS                           = 1,
    DATA_FELMYST                             = 2,
    DATA_EREDAR_TWINS                        = 3,
    DATA_MURU                                = 4,
    DATA_KILJAEDEN                           = 5,

    DATA_KALECGOS_DRAGON,
    DATA_KALECGOS_HUMAN,
    DATA_SATHROVARR,
    DATA_MADRIGOSA,
    DATA_ALYTHESS,
    DATA_SACROLASH,
    DATA_KILJAEDEN_CONTROLLER,
    DATA_ANVEENA,
    DATA_KALECGOS_KJ,

    // GameObject GUIDs
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_1,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_2,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_3,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_4,

    // Misc
    DATA_PLAYER_GUID
};

enum SWPCreatureIds
{
    NPC_MURU                                 = 25741,
    NPC_ENTROPIUS                            = 25840,
    NPC_KALECGOS                             = 24850,
    NPC_KALECGOS_HUMAN                       = 24891,
    NPC_SATHROVARR                           = 24892,
    NPC_BRUTALLUS                            = 24882,
    NPC_MADRIGOSA                            = 24895,
    NPC_FELMYST                              = 25038,

    NPC_DEAD                                 = 25268,
    NPC_FLIGHT_LEFT                          = 25357,
    NPC_FLIGHT_RIGHT                         = 25358,
    NPC_DEATH_CLOUD                          = 25703,
    NPC_VAPOR                                = 25265,
    NPC_VAPOR_TRAIL                          = 25267,

    NPC_GRAND_WARLOCK_ALYTHESS               = 25166,
    NPC_SHADOW_IMAGE                         = 25214,
    NPC_LADY_SACROLASH                       = 25165,

    NPC_ANVEENA                              = 26046, // Embodiment of the Sunwell
    NPC_KALECGOS_KJ                          = 25319, // Helps the raid throughout the fight
    NPC_PROPHET                              = 26246, // Outro
    NPC_KILJAEDEN                            = 25315, // Give it to 'em KJ!
    NPC_KILJAEDEN_CONTROLLER                 = 25608,
    NPC_HAND_OF_THE_DECEIVER                 = 25588, // Adds found before KJ emerges
    NPC_FELFIRE_PORTAL                       = 25603, // Portal spawned be Hand of the Deceivers
    NPC_VOLATILE_FELFIRE_FIEND               = 25598, // Fiends spawned by the above portal
    NPC_ARMAGEDDON_TARGET                    = 25735, // This mob casts meteor on itself.. I think
    NPC_SHIELD_ORB                           = 25502, // Shield orbs circle the room raining shadow bolts on raid
    NPC_THE_CORE_OF_ENTROPIUS                = 26262, // Used in the ending cinematic?
    NPC_POWER_OF_THE_BLUE_DRAGONFLIGHT       = 25653, // NPC that players possess when using the Orb of the Blue Dragonflight
    NPC_SPIKE_TARGET1                        = 30598, // Should summon these under Shadow Spike Channel on targets place
    NPC_SPIKE_TARGET2                        = 30614,
    NPC_SINISTER_REFLECTION                  = 25708, // Sinister Relection spawnd on Phase swichtes

    NPC_DARKNESS                             = 25879,
    NPC_DARK_FIENDS                          = 25744,
    NPC_BERSERKER                            = 25798,
    NPC_FURY_MAGE                            = 25799,
    NPC_VOID_SENTINEL                        = 25772,
    NPC_VOID_SPAWN                           = 25824,
    NPC_BLACK_HOLE                           = 25855,
    NPC_MURU_PORTAL_TARGET                   = 25770
};

enum SWPGameObjectIds
{
    GO_ORB_OF_THE_BLUE_DRAGONFLIGHT          = 188415,
    GO_FORCE_FIELD                           = 188421,
    GO_BOSS_COLLISION_1                      = 188523,
    GO_BOSS_COLLISION_2                      = 188524,
    GO_FIRE_BARRIER                          = 188075,
    GO_MURUS_GATE_1                          = 187990,
    GO_MURUS_GATE_2                          = 188118,
    GO_SPECTRAL_RIFT                         = 187055
};

template <class AI, class T>
AI* GetSunwellPlateauAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SunwellPlateauScriptName);
}

#define RegisterSunwellPlateauCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSunwellPlateauAI)

#endif // SUNWELL_PLATEAU_H
