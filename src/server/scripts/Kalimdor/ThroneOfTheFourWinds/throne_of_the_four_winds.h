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

#ifndef THRONE_OF_THE_FOUR_WINDS_H_
#define THRONE_OF_THE_FOUR_WINDS_H_

#include "CreatureAIImpl.h"

#define TotFWScriptName "instance_throne_of_the_four_winds"
#define DataHeader   "TOTFW"

uint32 const EncounterCount = 2;

enum TFWDataTypes
{
    // Encounter States
    DATA_CONCLAVE_OF_WIND                       = 0,
    DATA_ALAKIR                                 = 1,

    // Additional Data
    DATA_ANSHAL                                 = 2,
    DATA_NEZIR                                  = 3,
    DATA_ROHASH                                 = 4,
    DATA_SKYWALL_RAID_CENTER_PLATFORM           = 5,
    DATA_SKYWALL_DJIN_TORNADO                   = 6,
    DATA_SKYWALL_DJIN_FROST                     = 7,
    DATA_SKYWALL_DJIN_HEALING                   = 8,
    DATA_SKYWALL_WIND_DRAFT_EFFECT_CENTER       = 9,
    DATA_FREE_HURRICANE_VEHICLE                 = 10,
    DATA_ACID_RAIN_WEATHER                      = 11,
    DATA_FREE_RELENTLESS_STORM_INITIAL_VEHICLE  = 12,
    DATA_WORLD_TRIGGER_INFINITE_AOI             = 13,
    DATA_FREE_RELENTLESS_STORM_VEHICLE          = 14
};

enum TFWCreatureIds
{
    // Bosses
    BOSS_ANSHAL                                         = 45870,
    BOSS_NEZIR                                          = 45871,
    BOSS_ROHASH                                         = 45872,
    BOSS_ALAKIR                                         = 46753,

    // Creatures
    NPC_WORLD_TRIGGER                                   = 21252,
    NPC_FALL_CATCHER                                    = 45710,

    // Conclave of Wind
    NPC_RAVENOUS_CREEPER                                = 45812,
    NPC_TORNADO                                         = 46207,
    NPC_WORLD_TRIGGER_IMMUNE_TO_PC                      = 19871,
    NPC_HURRICANE                                       = 46419,

    // Al'Akir
    NPC_SLIPSTREAM                                      = 47066,
    NPC_LIGHTNING_STRIKE_TRIGGER_HEROIC_CHAIN_CASTER    = 50254,
    NPC_ICE_STORM                                       = 46973,
    NPC_SQUALL_LINE_VEHICLE_SW                          = 47034,
    NPC_SQUALL_LINE_VEHICLE_SE                          = 48852,
    NPC_SQUALL_LINE_SW                                  = 48854,
    NPC_SQUALL_LINE_SE                                  = 48855,
    NPC_STORMLING_PRE_EFFECT                            = 47177,
    NPC_STORMLING                                       = 47175,
    NPC_RELENTLESS_STORM_INITIAL_VEHICLE                = 47806,
    NPC_WORLD_TRIGGER_INFINITE_AOI                      = 36171,
    NPC_LIGHTNING_CLOUDS_BOTTOM                         = 51597,
    NPC_LIGHTNING_CLOUDS_EXTRA_VISUALS_BOTTOM           = 51598,
    NPC_LIGHTNING_CLOUDS                                = 48190,
    NPC_LIGHTNING_CLOUDS_EXTRA_VISUALS                  = 48196,
    NPC_RELENTLESS_STORM                                = 47807
};

enum TFWSpells
{
    // World Trigger
    SPELL_POWER_GAIN            = 89898,
    SPELL_WIND_BLAST_SPEED_BUFF = 93106,

    // Players
    SPELL_SERENITY              = 89750,

    // Bosses
    SPELL_BERSERK               = 26662
};

enum TFWGameObjectIds
{
    GO_SKYWALL_RAID_CENTER_PLATFORM     = 207737,
    GO_SKYWALL_WIND_DRAFT_EFFECT_CENTER = 207922,
    GO_SKYALL_DJIN_TORNADO              = 206701,
    GO_SKYALL_DJIN_FROST                = 206700,
    GO_SKYALL_DJIN_HEALING              = 206699
};

enum TFWTexts
{
    // World Trigger
    SAY_ANNOUNCE_ALMOST_FULL_STRENGTH = 0
};

enum TFWActions
{
    ACTION_CONCLAVE_DEFEATED            = 1,
    // 2 - Re-use
    ACTION_CONCLAVE_AT_FULL_STRENGTH    = 3
};

enum TFWMisc
{
    ZONE_ID_THRONE_OF_THE_FOUR_WINDS = 5638,
    LIGHT_OVERRIDE_ID_ACID_RAIN      = 2810,
    LIGHT_OVERRIDE_ID_DEFAULT        = 2768
};

template <class AI, class T>
inline AI* GetThroneOfTheFourWindsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, TotFWScriptName);
}

#define RegisterThroneOfTheFourWindsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetThroneOfTheFourWindsAI)

#endif // THRONE_OF_THE_FOUR_WINDS_H_
