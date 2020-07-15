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

#ifndef DEF_BLACKWING_DESCENT_H
#define DEF_BLACKWING_DESCENT_H

#include "CreatureAIImpl.h"

#define DataHeader "BWD"
#define BWDScriptName "instance_blackwing_descent"

uint32 const EncounterCount = 6;

enum BWDDataTypes
{
    // Bosses
    DATA_MAGMAW                     = 0,
    DATA_OMNOTRON_DEFENSE_SYSTEM    = 1,
    DATA_CHIMAERON                  = 2,
    DATA_ATRAMEDES                  = 3,
    DATA_MALORIAK                   = 4,
    DATA_NEFARIANS_END              = 5,

    /*Events*/
    DATA_RESET_DWARVEN_SPIRIT_GROUP,
    DATA_DWARVEN_SPIRIT_DIED,
    DATA_ANCIENT_BELL,
    DATA_COLUMN_OF_LIGHT,
    DATA_ATRAMEDES_INTRO,
    DATA_ENTRANCE_INTRO,
    DATA_NEFARIAN_ACHIEVEMENT_STATE,
    DATA_LORD_VICTOR_NEFARIUS_GENERIC,
    DATA_BOSS_DEFEATED,
    DATA_HEROES_ENTERED_HALLS,

    // Encounter Data
    /*Magmaw*/
    DATA_PREPARE_MASSIVE_CRASH_AND_GET_TARGET_GUID,
    DATA_NEFARIAN_MAGMAW,

    /*Omnotron Defense System*/
    DATA_ELECTRON, 
    DATA_MAGMATRON, 
    DATA_TOXITRON, 
    DATA_ARCANOTRON,
    DATA_LORD_VICTOR_NEFARIUS_OMNOTRON,

    /*Atramedes*/
    DATA_ATHENAEUM_DOOR,
    DATA_LORD_VICTOR_NEFARIUS_ATRAMEDES,

    /*Chimaeron*/
    DATA_BILE_O_TRON_800,
    DATA_FINKLE_EINHORN,

    /*Maloriak*/
    DATA_CAULDRON_TRIGGER,
    DATA_CAULDRON,
    DATA_LORD_VICTOR_NEFARIUS_MALORIAK,

    /*Nefarian's End*/
    DATA_LORD_VICTOR_NEFARIUS_NEFARIANS_END,
    DATA_INVISIBLE_STALKER,
    DATA_BLACKWING_ELEVATOR_ONYXIA,
    DATA_NEFARIANS_LIGHTNING_MACHINE,
    DATA_ONYXIA,
    DATA_CONTROLLER_STALKER,
    DATA_NEFARIANS_END_INTRO_DONE,
    DATA_RESET_ELEVATOR
};

enum BWDCreatureIds
{
    // Bosses
    BOSS_MAGMAW                             = 41570,
    BOSS_OMNOTRON                           = 42186,
    BOSS_CHIMAERON                          = 43296,
    BOSS_ATRAMEDES                          = 41442,
    BOSS_MALORIAK                           = 41378,
    BOSS_NEFARIAN                           = 41376,

    // Encounter related creatures
    /*Magmaw*/
    NPC_MAGMAWS_PINCER_1                    = 41620,
    NPC_MAGMAWS_PINCER_2                    = 41789,
    NPC_EXPOSED_HEAD_OF_MAGMAW              = 42347,
    NPC_EXPOSED_HEAD_OF_MAGMAW_2            = 48270,
    NPC_PILLAR_OF_FLAME                     = 41843,
    NPC_LAVA_PARASITE_1                     = 41806,
    NPC_LAVA_PARASITE_2                     = 42321,
    NPC_MASSIVE_CRASH                       = 47330,
    NPC_ROOM_STALKER                        = 47196,
    NPC_MAGMAW_SPIKE_STALKER                = 41767,
    NPC_NEFARIAN_MAGMAW                     = 49427,
    NPC_BLAZING_BONE_CONSTRUCT              = 49416,
    NPC_IGNITION                            = 49447,

    /*Omnotron Defense System*/
    NPC_MAGMATRON                           = 42178,
    NPC_ARCANOTRON                          = 42166,
    NPC_TOXITRON                            = 42180,
    NPC_ELECTRON                            = 42179,
    NPC_CHEMICAL_CLOUD                      = 42934,
    NPC_POISON_BOMB                         = 42897,
    NPC_POISON_PUDDLE                       = 42920,
    NPC_POWER_GENERATOR                     = 42733,
    NPC_LORD_VICTOR_NEFARIUS_OMNOTRON       = 49226,

    /*Atramedes*/
    NPC_SONAR_PULSE                         = 41546,
    NPC_SONAR_PULSE_BOMB                    = 49623,
    NPC_TRACKING_FLAMES                     = 41879,
    NPC_REVERBERATING_FLAME                 = 41962,
    NPC_LORD_VICTOR_NEFARIUS_ATRAMEDES      = 49580,
    NPC_OBNOXIOUS_FIEND                     = 49740,

    /*Chimaeron*/
    NPC_FINKLE_EINHORN                      = 44202,
    NPC_BILE_O_TRON_800                     = 44418,

    /*Maloriak*/
    NPC_CAULDRON_TRIGGER                    = 41505,
    NPC_ABERRATION                          = 41440,
    NPC_PRIME_SUBJECT                       = 41841,
    NPC_FLASH_FREEZE                        = 41576,
    NPC_ABSOLUTE_ZERO                       = 41961,
    NPC_LORD_VICTOR_NEFARIUS_MALORIAK       = 49799,
    NPC_VILE_SWILL                          = 49811,

    /*Nefarian's End*/
    NPC_LORD_VICTOR_NEFARIUS_NEFARIANS_END  = 41379,
    NPC_INVISIBLE_STALKER                   = 35592,
    NPC_INVISIBLE_STALKER_CATACLYSM_BOSS    = 42098,
    NPC_NEFARIANS_LIGHTNING_MACHINE         = 51089,
    NPC_ONYXIA                              = 41270,
    NPC_CHROMATIC_PROTOTYPE                 = 41948,
    NPC_CONTROLLER_STALKER                  = 42856,
    NPC_SHADOWBLAZE_FLASHPOINT              = 42595,
    NPC_DOMINION_STALKER                    = 43656,

    /*Events*/
    NPC_SPIRIT_OF_MOLTENFIST                = 43125,
    NPC_SPIRIT_OF_ANVILRAGE                 = 43128,
    NPC_SPIRIT_OF_SHADOWFORGE               = 43129,
    NPC_SPIRIT_OF_COREHAMMER                = 43122,
    NPC_SPIRIT_OF_ANGERFORGE                = 43119,
    NPC_SPIRIT_OF_IRONSTAR                  = 43127,
    NPC_SPIRIT_OF_THAURISSAN                = 43126,
    NPC_SPIRIT_OF_BURNINGEYE                = 43130,
    NPC_COLUMN_OF_LIGHT                     = 51506,
    NPC_LORD_VICTOR_NEFARIUS_GENERIC        = 48964,

    // Generic Creatures
    NPC_DRAKONID_DRUDGE                     = 42362,
    NPC_OVERHEAD_SMASH                      = 42690,
    NPC_EXECUTION_SENTENCE_VISUAL           = 43206
};

enum BWDGameObjectIds
{
    GO_INNER_CHAMBER_DOOR                       = 205830,
    GO_ANCIENT_BELL                             = 204276,
    GO_ATHENAEUM_DOOR                           = 208291,
    GO_DOODAD_BLACKROCKV2_LABROOM_CAULDRON_01   = 203306,
    GO_GROWTH_CHAMBER                           = 206704,
    GO_LARGE_GROWTH_CHAMBER                     = 206705,
    GO_DOODAD_BLACKWINGV2_ELEVATOR_ONYXIA       = 207834
};

enum BWDMisc
{
    // Magmaw
    MASSIVE_CRASH_SIDE_LEFT     = 0,
    MASSIVE_CRASH_SIDE_RIGHT    = 1,

    // Dwarven Spirit Council
    DWARVEN_SPIRIT_GROUP_LEFT   = 0,
    DWARVEN_SPIRIT_GROUP_RIGHT  = 1
};

enum BWDSpells
{
    // Room Stalker
    SPELL_LIGHT_SHOW            = 87949,

    // Massive Crash
    SPELL_MASSIVE_CRASH_DAMAGE  = 88287,

    // Column of Light
    SPELL_COLUMN_OF_LIGHT       = 95660
};

enum BWDWorldStates
{
    WS_KEEPING_IT_IN_THE_FAMILY = 0
};

template <class AI, class T>
inline AI* GetBlackwingDescentAI(T* obj)
{
    return GetInstanceAI<AI>(obj, BWDScriptName);
}

#define RegisterBlackwingDescentCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetBlackwingDescentAI)

#endif
