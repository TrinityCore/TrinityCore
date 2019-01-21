/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef THRONEOFTHETIDES_H_
#define THRONEOFTHETIDES_H_

#include "CreatureAIImpl.h"

#define TotTScriptName "instance_throne_of_the_tides"
#define DataHeader "TOTT"

uint32 const EncounterCount = 4;

enum TotTDataTypes
{
    // Encounters
    DATA_LADY_NAZJAR                        = 0,
    DATA_COMMANDER_ULTHOK                   = 1,
    DATA_MINDBENDER_GURSHA                  = 2,
    DATA_OZUMAT                             = 3,

    // Additional Data Types
    DATA_CURRENT_EVENT_PROGRESS             = 4,
    DATA_LADY_NAZJAR_GAUNTLET               = 5,
    DATA_ABYSSAL_MAW_DOOR_1                 = 6,
    DATA_ABYSSAL_MAW_DOOR_2                 = 7,
    DATA_THRONE_OF_THE_TIDES_DEFENSE_SYSTEM = 8,
    DATA_OZUMAT_VEHICLE_BIG                 = 9,
    DATA_INVISIBLE_DOOR_1                   = 10,
    DATA_INVISIBLE_DOOR_2                   = 11,
    DATA_LEVIATHAN_TENTACLE_1               = 12,
    DATA_LEVIATHAN_TENTACLE_2               = 13,
    DATA_ABYSSAL_CORAL_CHUNK                = 14,
    DATA_NEPTULON                           = 15,
    DATA_OZUMAT_VEHICLE                     = 16
};

enum TotTCreatureIds
{
    // Bosses
    BOSS_LADY_NAZJAR                        = 40586,
    BOSS_COMMANDER_ULTHOK                   = 40765,
    BOSS_MINDBENDER_GURSHA                  = 40788,
    BOSS_OZUMAT                             = 44566,

    // Encounter Related
    /*Lady Naz'jar*/
    NPC_GEYSER                              = 40597,
    NPC_NAZJAR_HONOR_GUARD                  = 40633,
    NPC_NAZJAR_TEMPEST_WITCH                = 44404,
    NPC_WATERSPOUT                          = 48571,

    /*Ozumat*/
    NPC_NEPTULON                            = 40792,
    NPC_OZUMAT_COMBAT_TRIGGER               = 44864,
    NPC_WORLD_TRIGGER_FRIENDLY              = 18721,
    NPC_DEEP_MURLOC_INVADER                 = 44658,
    NPC_VICIOUS_MINDLASHER                  = 44715,
    NPC_UNYIELDING_BEHEMOTH                 = 44648,
    NPC_UNYIELDING_BEHEMOTH_LEAP_VEHICLE    = 44949,
    NPC_OZUMAT_ADD_SPAWNER                  = 44656,
    NPC_OZUMAT_VEHICLE                      = 44581,
    NPC_FACELESS_SAPPER                     = 44752,
    NPC_BLIGHT_BEAST                        = 44841,
    NPC_BLIGHT_OF_OZUMAT                    = 44801,
    NPC_BLIGHT_OF_OZUMAT_2                  = 44834,

    // Event Creatures
    NPC_OZUMAT_VEHICLE_BIG                  = 45030,
    NPC_WORLD_TRIGGER_INFINITE_AOI          = 36171,
    NPC_NAZJAR_SPIRITMENDER_1               = 41096,
    NPC_NAZJAR_SPIRITMENDER_2               = 41139,
    NPC_NAZJAR_INVADER_1                    = 39616,
    NPC_NAZJAR_INVADER_2                    = 40584,
    NPC_OZUMAT                              = 40655,
    NPC_WORLD_TRIGGER_NOT_IMMUNE_PC         = 21252,
    NPC_LADY_NAZJAR                         = 39959,

    // Generic Creatures
    NPC_GEYSER_DUMMY                        = 48983,
    NPC_GILGOBLIN_HUNTER                    = 40935,
    NPC_FACELESS_WATCHER                    = 40936,
    NPC_GILGOBLIN_AQUAMAGE                  = 40943
};

enum TotTGameObjectIds
{
    GO_TEMP_FALLING_ROCKS                   = 202742,
    GO_DOODAD_ABYSSAL_MAW_DOOR_1            = 204338,
    GO_DOODAD_ABYSSAL_MAW_DOOR_2            = 204339,
    GO_DOODAD_ABYSSAL_MAW_DOOR_4            = 204341,
    GO_THRONE_OF_THE_TIDES_DEFENSE_SYSTEM   = 203199,
    GO_DOODAD_INVISIBLE_DOOR_1              = 207997,
    GO_DOODAD_INVISIBLE_DOOR_2              = 207998,
    GO_DOODAD_ABYSSAL_LEVIATHAN_TENTACLE_1  = 208302,
    GO_DOODAD_ABYSSAL_LEVIATHAN_TENTACLE_2  = 208301,
    GO_DOODAD_ABYSSAL_CORAL_CHUNK_CEILING   = 205542,
    GO_NEPTULONS_CACHE_NORMAL               = 205216,
    GO_NEPTULONS_CACHE_HEROIC               = 207973
};

enum TotTSpells
{
    SPELL_SUMMON_FALLING_ROCKS                  = 74465,
    SPELL_WATER_JUMP_THROUGH_WINDOW_VISUAL      = 74048,
    SPELL_GEYSER_DUMMY                          = 91347,
    SPELL_GEYSER_DUMMY_KNOCKBACK                = 91349,
    SPELL_CAMERA                                = 77229,
    SPELL_SHOCK_DEFENSE                         = 85170,
    SPELL_SHOCK_DEFENSE_OZUMAT                  = 86635,
    SPELL_ULTHOK_INTRO_VISUAL_CEILING_IMPACT    = 76021,
    SPELL_ULTHOK_INTRO_JUMP                     = 82960,
    SPELL_ULTHOK_INTRO_VISUAL_STATE             = 76017
};

enum TotTCinematic
{
    CINEMATIC_DEFENSE_SYSTEM_ACTIVE = 169
};

enum TotTEventIndex
{
    EVENT_INDEX_NONE = 0,
    EVENT_INDEX_FIRST_INVADERS,
    EVENT_INDEX_LADY_NAZJAR_GAUNTLET,
    EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED,
    EVENT_INDEX_ULTHOK_ARRIVED,
    EVENT_INDEX_NEPTULON_INTRO_DONE
};

enum TotTActions
{
    ACTION_DEFENSE_SYSTEM_ACTIVATED = 1,
    ACTION_CORAL_GARDEN_ENTERED     = 1
};

enum TotTSounds
{
    SOUND_ULTHOK_INTRO = 18546
};

Position const TotTFirstInvaderPositions[] =
{
    { -409.0035f, 839.2552f, 262.0498f, 5.119945f }, // Naz'jar Spiritmender
    { -396.9653f, 779.9288f, 265.7069f, 1.55391f  }, // Naz'jar Spiritmender
    { -421.6042f, 839.7882f, 263.3889f, 4.842506f }, // Naz'jar Invader
    { -411.3646f, 778.8055f, 262.9503f, 1.528872f }  // Naz'Jar Invader
};

Position const TotTFirstInvaderInitialMovePositions[] =
{
    { -400.842f, 820.351f, 263.69f  },
    { -396.74f,  793.269f, 260.422f },
    { -418.925f, 819.314f, 261.505f },
    { -410.885f, 790.238f, 261.178f }
};

Position const TotTFirstInvaderJumpPositions[] =
{
    { -410.087f, 807.931f, 248.335f, 3.106686f },
    { -409.13f,  802.774f, 248.357f, 3.106686f },
    { -414.969f, 810.604f, 248.433f, 3.106686f },
    { -413.5f,   798.38f,  248.561f, 3.106686f }
};

Position const TotTLadyNazjarInvaderPositions[] =
{
    { -103.3125f, 775.8559f, 810.9689f, 1.448623f },
    { -70.23785f, 774.9618f, 810.3751f, 1.712018f },
    { -72.86459f, 831.441f,  809.7106f, 4.86808f  },
    { -135.0625f, 772.4739f, 810.089f,  1.448623f },
    { -135.5764f, 831.9948f, 808.1715f, 4.39823f  },
    { -103.8837f, 832.8108f, 808.739f,  4.572762f }
};

Position const TotTLadyNazjarInvaderInitialMovePositions[] =
{
    { -102.865f, 782.165f, 806.063f },
    { -71.2622f, 782.167f, 804.698f },
    { -71.4601f, 822.493f, 806.099f },
    { -134.22f,  785.163f, 809.356f },
    { -133.75f,  822.464f, 806.963f },
    { -102.62f,  822.491f, 806.619f }
};

Position const TotTLadyNazjarInvaderJumpPositions[] =
{
    { -101.747f, 798.698f, 796.926f, 3.159046f },
    { -68.9392f, 798.405f, 796.894f, 3.298672f },
    { -68.0035f, 805.835f, 796.846f, 3.211406f },
    { -136.613f, 799.226f, 796.844f, 3.176499f },
    { -135.474f, 806.198f, 796.912f, 3.176499f },
    { -101.955f, 806.373f, 796.964f, 3.071779f }
};

Position const TotTGilgoblinHunterPositions[] =
{
    { -296.0759f, 668.8297f, 280.8867f, 2.188809f },
    { -295.146f,  662.971f,  281.3593f, 2.202956f },
    { -291.068f,  665.408f,  281.9814f, 2.15424f  },
    { -296.477f,  661.01f,   281.4153f, 2.23188f  },
    { -297.7917f, 671.1694f, 280.5178f, 2.186387f },
    { -296.523f,  665.198f,  281.0583f, 2.25458f  }
};

Position const TotTGilgoblinAquamagePositions[] =
{
    { -288.911f, 667.142f, 282.2543f, 2.14487f  },
    { -297.938f, 659.363f, 281.7794f, 2.262644f }
};

Position const TotTFacelessWatcherPosition = { -292.3462f, 664.1631f, 281.7034f, 2.1634f };

template <class AI, class T>
inline AI* GetThroneOfTheTodesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotTScriptName);
}

#define RegisterThroneOfTheTidesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheTodesAI)

#endif // THRONEOFTHETIDES_H_
