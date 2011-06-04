/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

<<<<<<< HEAD
enum Encounter
{
    BOSS_LEVIATHAN,
    BOSS_IGNIS,
    BOSS_RAZORSCALE,
    BOSS_XT002,
    BOSS_ASSEMBLY,
    BOSS_KOLOGARN,
    BOSS_AURIAYA,
    BOSS_MIMIRON,
    BOSS_HODIR,
    BOSS_THORIM,
    BOSS_FREYA,
    BOSS_VEZAX,
    BOSS_YOGGSARON,
    BOSS_ALGALON,
    MAX_BOSS_NUMBER
=======
#include "ObjectMgr.h"
#define UlduarScriptName "instance_ulduar"

enum UlduarBosses
{
    MAX_ENCOUNTER                                = 20,

    BOSS_LEVIATHAN                               = 0,
    BOSS_IGNIS                                   = 1,
    BOSS_RAZORSCALE                              = 2,
    BOSS_XT002                                   = 3,
    BOSS_ASSEMBLY_OF_IRON                        = 4,
    BOSS_STEELBREAKER                            = 5,
    BOSS_MOLGEIM                                 = 6,
    BOSS_BRUNDIR                                 = 7,
    BOSS_KOLOGARN                                = 8,
    BOSS_AURIAYA                                 = 9,
    BOSS_MIMIRON                                 = 10,
    BOSS_HODIR                                   = 11,
    BOSS_THORIM                                  = 12,
    BOSS_FREYA                                   = 13,
    BOSS_BRIGHTLEAF                              = 14,
    BOSS_IRONBRANCH                              = 15,
    BOSS_STONEBARK                               = 16,
    BOSS_VEZAX                                   = 17,
    BOSS_YOGGSARON                               = 18,
    BOSS_ALGALON                                 = 19,
    TYPE_COLOSSUS                                = 20,

    // Razorscale
    DATA_EXPEDITION_COMMANDER,
    DATA_RAZORSCALE_CONTROL,

    // Kologarn
    DATA_LEFT_ARM,
    DATA_RIGHT_ARM,

    // Hodir
    DATA_HODIR_RARE_CACHE,
};

enum UlduarNPCs
{
    NPC_LEVIATHAN                                = 33113,
    NPC_IGNIS                                    = 33118,
    NPC_RAZORSCALE                               = 33186,
    NPC_RAZORSCALE_CONTROLLER                    = 33233,
    NPC_STEELFORGED_DEFFENDER                    = 33236,
    NPC_EXPEDITION_COMMANDER                     = 33210,
    NPC_XT002                                    = 33293,
    NPC_STEELBREAKER                             = 32867,
    NPC_MOLGEIM                                  = 32927,
    NPC_BRUNDIR                                  = 32857,
    NPC_KOLOGARN                                 = 32930,
    NPC_KOLOGARN_BRIDGE                          = 34297,
    NPC_FOCUSED_EYEBEAM                          = 33632,
    NPC_FOCUSED_EYEBEAM_RIGHT                    = 33802,
    NPC_LEFT_ARM                                 = 32933,
    NPC_RIGHT_ARM                                = 32934,
    NPC_RUBBLE                                   = 33768,
    NPC_AURIAYA                                  = 33515,
    NPC_MIMIRON                                  = 33350,
    NPC_HODIR                                    = 32845,
    NPC_THORIM                                   = 32865,
    NPC_FREYA                                    = 32906,
    NPC_VEZAX                                    = 33271,
    NPC_YOGGSARON                                = 33288,
    NPC_ALGALON                                  = 32871,
    NPC_LEVIATHAN_MKII                           = 33432,
    NPC_VX_001                                   = 33651,
    NPC_AERIAL_COMMAND_UNIT                      = 33670,

    // Freya's Keepers
    NPC_IRONBRANCH                               = 32913,
    NPC_BRIGHTLEAF                               = 32915,
    NPC_STONEBARK                                = 32914,

    // Hodir's Helper NPCs
    NPC_TOR_GREYCLOUD                            = 32941,
    NPC_KAR_GREYCLOUD                            = 33333,
    NPC_EIVI_NIGHTFEATHER                        = 33325,
    NPC_ELLIE_NIGHTFEATHER                       = 32901,
    NPC_SPIRITWALKER_TARA                        = 33332,
    NPC_SPIRITWALKER_YONA                        = 32950,
    NPC_ELEMENTALIST_MAHFUUN                     = 33328,
    NPC_ELEMENTALIST_AVUUN                       = 32900,
    NPC_AMIRA_BLAZEWEAVER                        = 33331,
    NPC_VEESHA_BLAZEWEAVER                       = 32946,
    NPC_MISSY_FLAMECUFFS                         = 32893,
    NPC_SISSY_FLAMECUFFS                         = 33327,
    NPC_BATTLE_PRIEST_ELIZA                      = 32948,
    NPC_BATTLE_PRIEST_GINA                       = 33330,
    NPC_FIELD_MEDIC_PENNY                        = 32897,
    NPC_FIELD_MEDIC_JESSI                        = 33326,
};

enum UlduarGameObjects
{
    GO_KOLOGARN_CHEST_HERO                       = 195047,
    GO_KOLOGARN_CHEST                            = 195046,
    GO_KOLOGARN_BRIDGE                           = 194232,
    GO_KOLOGARN_DOOR                             = 194553,
    GO_THORIM_CHEST_HERO                         = 194315,
    GO_THORIM_CHEST                              = 194314,
    GO_HODIR_RARE_CACHE_OF_WINTER                = 194200,
    GO_HODIR_RARE_CACHE_OF_WINTER_HERO           = 194201,
    GO_HODIR_CHEST_HERO                          = 194308,
    GO_HODIR_CHEST                               = 194307,
    GO_FREYA_CHEST_HERO                          = 194325,
    GO_FREYA_CHEST                               = 194324,
    GO_LEVIATHAN_DOOR                            = 194905,
    GO_LEVIATHAN_GATE                            = 194630,
    GO_VEZAX_DOOR                                = 194750,
    GO_MOLE_MACHINE                              = 194316,
    GO_RAZOR_HARPOON_1                           = 194542,
    GO_RAZOR_HARPOON_2                           = 194541,
    GO_RAZOR_HARPOON_3                           = 194543,
    GO_RAZOR_HARPOON_4                           = 194519,
    GO_RAZOR_BROKEN_HARPOON                      = 194565,
    GO_HODIR_DOOR                                = 194634,
    GO_HODIR_ICE_DOOR                            = 194441,
>>>>>>> 665dbfd9aef9dd5620f2fe44844872c9d0f5ea8f
};

enum Data64
{
    DATA_LEVIATHAN,
    DATA_NORGANNON,
    DATA_IGNIS,
    DATA_RAZORSCALE,
    DATA_EXP_COMMANDER,
    DATA_XT002,
    DATA_STEELBREAKER,
    DATA_MOLGEIM,
    DATA_BRUNDIR,
    DATA_KOLOGARN,
    DATA_AURIAYA,
    DATA_BRIGHTLEAF,
    DATA_IRONBRANCH,
    DATA_STONEBARK,
    DATA_FREYA,
    DATA_THORIM,
    DATA_RUNIC_COLOSSUS,
    DATA_RUNE_GIANT,
    DATA_MIMIRON,
    DATA_LEVIATHAN_MK_II,
    DATA_VX_001,
    DATA_AERIAL_UNIT,
    DATA_MAGNETIC_CORE,
    DATA_VEZAX,
    DATA_YS_FREYA,
    DATA_YS_THORIM,
    DATA_YS_MIMIRON,
    DATA_YS_HODIR,
    DATA_YOGGSARON_BRAIN,
    DATA_YOGGSARON
};

enum Data
{
    DATA_LEVIATHAN_DOOR,
    DATA_TOWER_DESTROYED,
    DATA_RUNIC_DOOR,
    DATA_STONE_DOOR,
    DATA_CALL_TRAM,
    DATA_MIMIRON_ELEVATOR,
    DATA_HODIR_RARE_CHEST
};

template<class AI>
CreatureAI* GetUlduarAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == GetScriptId(UlduarScriptName))
                return new AI(creature);

    return NULL;
}

#endif
