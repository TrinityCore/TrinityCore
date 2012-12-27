/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#define UlduarScriptName "instance_ulduar"

extern Position const AlgalonLandPos;

enum UlduarBosses
{
    MAX_ENCOUNTER            = 17,

    BOSS_LEVIATHAN           = 0,
    BOSS_IGNIS               = 1,
    BOSS_RAZORSCALE          = 2,
    BOSS_XT002               = 3,
    BOSS_ASSEMBLY_OF_IRON    = 4,
    BOSS_KOLOGARN            = 5,
    BOSS_AURIAYA             = 6,
    BOSS_MIMIRON             = 7,
    BOSS_HODIR               = 8,
    BOSS_THORIM              = 9,
    BOSS_FREYA               = 10,
    BOSS_BRIGHTLEAF          = 11,
    BOSS_IRONBRANCH          = 12,
    BOSS_STONEBARK           = 13,
    BOSS_VEZAX               = 14,
    BOSS_YOGGSARON           = 15,
    BOSS_ALGALON             = 16,
};

enum UlduarNPCs
{
    // General
    NPC_LEVIATHAN                           = 33113,
    NPC_SALVAGED_DEMOLISHER                 = 33109,
    NPC_SALVAGED_SIEGE_ENGINE               = 33060,
    NPC_IGNIS                               = 33118,
    NPC_RAZORSCALE                          = 33186,
    NPC_RAZORSCALE_CONTROLLER               = 33233,
    NPC_STEELFORGED_DEFFENDER               = 33236,
    NPC_EXPEDITION_COMMANDER                = 33210,
    NPC_XT002                               = 33293,
    NPC_XT_TOY_PILE                         = 33337,
    NPC_STEELBREAKER                        = 32867,
    NPC_MOLGEIM                             = 32927,
    NPC_BRUNDIR                             = 32857,
    NPC_KOLOGARN                            = 32930,
    NPC_FOCUSED_EYEBEAM                     = 33632,
    NPC_FOCUSED_EYEBEAM_RIGHT               = 33802,
    NPC_LEFT_ARM                            = 32933,
    NPC_RIGHT_ARM                           = 32934,
    NPC_RUBBLE                              = 33768,
    NPC_AURIAYA                             = 33515,
    NPC_MIMIRON                             = 33350,
    NPC_HODIR                               = 32845,
    NPC_THORIM                              = 32865,
    NPC_FREYA                               = 32906,
    NPC_VEZAX                               = 33271,
    NPC_YOGGSARON                           = 33288,
    NPC_ALGALON                             = 32871,

    // Mimiron
    NPC_LEVIATHAN_MKII                      = 33432,
    NPC_VX_001                              = 33651,
    NPC_AERIAL_COMMAND_UNIT                 = 33670,

    // Freya's Keepers
    NPC_IRONBRANCH                          = 32913,
    NPC_BRIGHTLEAF                          = 32915,
    NPC_STONEBARK                           = 32914,

    // Hodir's Helper NPCs
    NPC_TOR_GREYCLOUD                       = 32941,
    NPC_KAR_GREYCLOUD                       = 33333,
    NPC_EIVI_NIGHTFEATHER                   = 33325,
    NPC_ELLIE_NIGHTFEATHER                  = 32901,
    NPC_SPIRITWALKER_TARA                   = 33332,
    NPC_SPIRITWALKER_YONA                   = 32950,
    NPC_ELEMENTALIST_MAHFUUN                = 33328,
    NPC_ELEMENTALIST_AVUUN                  = 32900,
    NPC_AMIRA_BLAZEWEAVER                   = 33331,
    NPC_VEESHA_BLAZEWEAVER                  = 32946,
    NPC_MISSY_FLAMECUFFS                    = 32893,
    NPC_SISSY_FLAMECUFFS                    = 33327,
    NPC_BATTLE_PRIEST_ELIZA                 = 32948,
    NPC_BATTLE_PRIEST_GINA                  = 33330,
    NPC_FIELD_MEDIC_PENNY                   = 32897,
    NPC_FIELD_MEDIC_JESSI                   = 33326,

    // Freya's trash NPCs
    NPC_CORRUPTED_SERVITOR                  = 33354,
    NPC_MISGUIDED_NYMPH                     = 33355,
    NPC_GUARDIAN_LASHER                     = 33430,
    NPC_FOREST_SWARMER                      = 33431,
    NPC_MANGROVE_ENT                        = 33525,
    NPC_IRONROOT_LASHER                     = 33526,
    NPC_NATURES_BLADE                       = 33527,
    NPC_GUARDIAN_OF_LIFE                    = 33528,

    // Algalon the Observer
    NPC_BRANN_BRONZBEARD_ALG                = 34064,
    NPC_AZEROTH                             = 34246,
    NPC_LIVING_CONSTELLATION                = 33052,
    NPC_ALGALON_STALKER                     = 33086,
    NPC_COLLAPSING_STAR                     = 32955,
    NPC_BLACK_HOLE                          = 32953,
    NPC_WORM_HOLE                           = 34099,
    NPC_ALGALON_VOID_ZONE_VISUAL_STALKER    = 34100,
    NPC_ALGALON_STALKER_ASTEROID_TARGET_01  = 33104,
    NPC_ALGALON_STALKER_ASTEROID_TARGET_02  = 33105,
    NPC_UNLEASHED_DARK_MATTER               = 34097,
};

enum UlduarGameObjects
{
    GO_KOLOGARN_CHEST_HERO                  = 195047,
    GO_KOLOGARN_CHEST                       = 195046,
    GO_KOLOGARN_BRIDGE                      = 194232,
    GO_KOLOGARN_DOOR                        = 194553,
    GO_THORIM_CHEST_HERO                    = 194315,
    GO_THORIM_CHEST                         = 194314,
    GO_HODIR_RARE_CACHE_OF_WINTER           = 194200,
    GO_HODIR_RARE_CACHE_OF_WINTER_HERO      = 194201,
    GO_HODIR_CHEST_HERO                     = 194308,
    GO_HODIR_CHEST                          = 194307,
    GO_LEVIATHAN_DOOR                       = 194905,
    GO_LEVIATHAN_GATE                       = 194630,
    GO_XT_002_DOOR                          = 194631,
    GO_VEZAX_DOOR                           = 194750,
    GO_MOLE_MACHINE                         = 194316,
    GO_RAZOR_HARPOON_1                      = 194542,
    GO_RAZOR_HARPOON_2                      = 194541,
    GO_RAZOR_HARPOON_3                      = 194543,
    GO_RAZOR_HARPOON_4                      = 194519,
    GO_RAZOR_BROKEN_HARPOON                 = 194565,
    GO_HODIR_DOOR                           = 194634,
    GO_HODIR_ICE_DOOR                       = 194441,
    GO_ARCHIVUM_DOOR                        = 194556,

    // Algalon the Observer
    GO_CELESTIAL_PLANETARIUM_ACCESS_10      = 194628,
    GO_CELESTIAL_PLANETARIUM_ACCESS_25      = 194752,
    GO_DOODAD_UL_SIGILDOOR_01               = 194767,
    GO_DOODAD_UL_SIGILDOOR_02               = 194911,
    GO_DOODAD_UL_SIGILDOOR_03               = 194910,
    GO_DOODAD_UL_UNIVERSEFLOOR_01           = 194715,
    GO_DOODAD_UL_UNIVERSEFLOOR_02           = 194716,
    GO_DOODAD_UL_UNIVERSEGLOBE01            = 194148,
    GO_DOODAD_UL_ULDUAR_TRAPDOOR_03         = 194253,
    GO_GIFT_OF_THE_OBSERVER_10              = 194821,
    GO_GIFT_OF_THE_OBSERVER_25              = 194822,
};

enum LeviathanData
{
    EVENT_TOWER_OF_STORM_DESTROYED      = 21031,
    EVENT_TOWER_OF_FROST_DESTROYED      = 21032,
    EVENT_TOWER_OF_FLAMES_DESTROYED     = 21033,
    EVENT_TOWER_OF_LIFE_DESTROYED       = 21030,
    ACTION_TOWER_OF_STORM_DESTROYED     = 1,
    ACTION_TOWER_OF_FROST_DESTROYED     = 2,
    ACTION_TOWER_OF_FLAMES_DESTROYED    = 3,
    ACTION_TOWER_OF_LIFE_DESTROYED      = 4,
    ACTION_MOVE_TO_CENTER_POSITION      = 10,
};

enum UlduarAchievementCriteriaIds
{
    CRITERIA_CON_SPEED_ATORY    = 21597,
    CRITERIA_DISARMED           = 21687,
    CRITERIA_HERALD_OF_TITANS   = 10678,
};

enum UlduarData
{
    // Collosus (Leviathan)
    DATA_COLOSSUS                = 20,

    // Razorscale
    DATA_EXPEDITION_COMMANDER,
    DATA_RAZORSCALE_CONTROL,

    // XT-002
    DATA_TOY_PILE_0,
    DATA_TOY_PILE_1,
    DATA_TOY_PILE_2,
    DATA_TOY_PILE_3,

    // Assembly of Iron
    DATA_STEELBREAKER,
    DATA_MOLGEIM,
    DATA_BRUNDIR,

    // Hodir
    DATA_HODIR_RARE_CACHE,

    // Algalon the Observer
    DATA_ALGALON_SUMMON_STATE,
    DATA_SIGILDOOR_01,
    DATA_SIGILDOOR_02,
    DATA_SIGILDOOR_03,
    DATA_UNIVERSE_FLOOR_01,
    DATA_UNIVERSE_FLOOR_02,
    DATA_UNIVERSE_GLOBE,
    DATA_ALGALON_TRAPDOOR,
    DATA_BRANN_BRONZEBEARD_ALG,
};

enum UlduarWorldStates
{
    WORLD_STATE_ALGALON_DESPAWN_TIMER   = 4131,
    WORLD_STATE_ALGALON_TIMER_ENABLED   = 4132,
};

enum UlduarAchievementData
{
    // FL Achievement boolean
    DATA_UNBROKEN = 29052906, // 2905, 2906 are achievement IDs,
    MAX_HERALD_ARMOR_ITEMLEVEL  = 226,
    MAX_HERALD_WEAPON_ITEMLEVEL = 232,
};

enum UlduarEvents
{
    EVENT_DESPAWN_ALGALON       = 1,
    EVENT_UPDATE_ALGALON_TIMER  = 2,
    ACTION_INIT_ALGALON         = 6,
};

template<class AI>
CreatureAI* GetUlduarAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(UlduarScriptName))
                return new AI(creature);

    return NULL;
}

template<class AI>
GameObjectAI* GetUlduarAI(GameObject* go)
{
    if (InstanceMap* instance = go->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(UlduarScriptName))
                return new AI(go);

    return NULL;
}

class PlayerOrPetCheck
{
    public:
        bool operator()(WorldObject* object) const
        {
            if (object->GetTypeId() != TYPEID_PLAYER)
                if (!object->ToCreature()->isPet())
                    return true;

            return false;
        }
};

#endif
