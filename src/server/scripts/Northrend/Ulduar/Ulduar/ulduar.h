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

enum UlduarBosses
{
    MAX_ENCOUNTER            = 20,

    BOSS_LEVIATHAN           = 0,
    BOSS_IGNIS               = 1,
    BOSS_RAZORSCALE          = 2,
    BOSS_XT002               = 3,
    BOSS_ASSEMBLY_OF_IRON    = 4,
    BOSS_STEELBREAKER        = 5,
    BOSS_MOLGEIM             = 6,
    BOSS_BRUNDIR             = 7,
    BOSS_KOLOGARN            = 8,
    BOSS_AURIAYA             = 9,
    BOSS_MIMIRON             = 10,
    BOSS_HODIR               = 11,
    BOSS_THORIM              = 12,
    BOSS_FREYA               = 13,
    BOSS_BRIGHTLEAF          = 14,
    BOSS_IRONBRANCH          = 15,
    BOSS_STONEBARK           = 16,
    BOSS_VEZAX               = 17,
    BOSS_YOGGSARON           = 18,
    BOSS_ALGALON             = 19,
    TYPE_NOGNNANON           = 30,
    TYPE_RHYDIAN             = 31,
};

enum UlduarNPCs
{
    // General
    NPC_LEVIATHAN                = 33113,
    NPC_SALVAGED_DEMOLISHER      = 33109,
    NPC_SALVAGED_SIEGE_ENGINE    = 33060,
    NPC_IGNIS                    = 33118,
    NPC_RAZORSCALE               = 33186,
    NPC_RAZORSCALE_CONTROLLER    = 33233,
    NPC_STEELFORGED_DEFFENDER    = 33236,
    NPC_EXPEDITION_COMMANDER     = 33210,
    NPC_XT002                    = 33293,
    NPC_XT_TOY_PILE              = 33337,
    NPC_STEELBREAKER             = 32867,
    NPC_MOLGEIM                  = 32927,
    NPC_BRUNDIR                  = 32857,
    NPC_KOLOGARN                 = 32930,
    NPC_FOCUSED_EYEBEAM          = 33632,
    NPC_FOCUSED_EYEBEAM_RIGHT    = 33802,
    NPC_LEFT_ARM                 = 32933,
    NPC_RIGHT_ARM                = 32934,
    NPC_RUBBLE                   = 33768,
    NPC_AURIAYA                  = 33515,
    NPC_MIMIRON                  = 33350,
    NPC_HODIR                    = 32845,
    NPC_THORIM                   = 32865,
    NPC_FREYA                    = 32906,
    NPC_VEZAX                    = 33271,
    NPC_YOGGSARON                = 33288,
    NPC_SARA                     = 33134,
    NPC_ALGALON                  = 32871,
    NPC_BRANN_ALGALON            = 34064,
    NPC_ULDUAR_WARMAGE           = 33662,
    NPC_RHYDIAN                  = 33696,
    NPC_KEEPER_UNIT              = 33721,
    NPC_NORGANNON                = 33686,
    NPC_BRONZEBEARD_RADIO        = 34054,    
    NPC_LOREKEEPER               = 33686, // Hard mode starter
    NPC_BRANN_BRONZBEARD         = 33579,
    NPC_BRANZ_BRONZBEARD         = 33579,
    NPC_DELORAH                  = 33701,
    NPC_ULDUAR_GAUNTLET_GENERATOR= 33571, // Trigger tied to towers
	
    // Mimiron
    NPC_LEVIATHAN_MKII           = 33432,
    NPC_VX_001                   = 33651,
    NPC_AERIAL_COMMAND_UNIT      = 33670,

    // Thorim
    NPC_RUNIC_COLOSSUS          = 32872,
    NPC_RUNE_GIANT              = 32873,	

    // Freya's Keepers
    NPC_IRONBRANCH               = 32913,
    NPC_BRIGHTLEAF               = 32915,
    NPC_STONEBARK                = 32914,

    // Hodir's Helper NPCs
    NPC_TOR_GREYCLOUD            = 32941,
    NPC_KAR_GREYCLOUD            = 33333,
    NPC_EIVI_NIGHTFEATHER        = 33325,
    NPC_ELLIE_NIGHTFEATHER       = 32901,
    NPC_SPIRITWALKER_TARA        = 33332,
    NPC_SPIRITWALKER_YONA        = 32950,
    NPC_ELEMENTALIST_MAHFUUN     = 33328,
    NPC_ELEMENTALIST_AVUUN       = 32900,
    NPC_AMIRA_BLAZEWEAVER        = 33331,
    NPC_VEESHA_BLAZEWEAVER       = 32946,
    NPC_MISSY_FLAMECUFFS         = 32893,
    NPC_SISSY_FLAMECUFFS         = 33327,
    NPC_BATTLE_PRIEST_ELIZA      = 32948,
    NPC_BATTLE_PRIEST_GINA       = 33330,
    NPC_FIELD_MEDIC_PENNY        = 32897,
    NPC_FIELD_MEDIC_JESSI        = 33326,

    // Freya's trash NPCs
    NPC_CORRUPTED_SERVITOR       = 33354,
    NPC_MISGUIDED_NYMPH          = 33355,
    NPC_GUARDIAN_LASHER          = 33430,
    NPC_FOREST_SWARMER           = 33431,
    NPC_MANGROVE_ENT             = 33525,
    NPC_IRONROOT_LASHER          = 33526,
    NPC_NATURES_BLADE            = 33527,
    NPC_GUARDIAN_OF_LIFE         = 33528,
};

enum UlduarGameObjects
{
    GO_TOWER_OF_STORMS                    = 194377,
    GO_TOWER_OF_FLAMES                    = 194371,
    GO_TOWER_OF_FROST                     = 194370,
    GO_TOWER_OF_LIFE                      = 194375,
    GO_REPAIR_STATION                     = 194261,
    GO_TELEPORTER                         = 194569,
    GO_CUPOLE                             = 194484,
    GO_KOLOGARN_CHEST_HERO                = 195047,
    GO_KOLOGARN_CHEST                     = 195046,
    GO_KOLOGARN_BRIDGE                    = 194232,
    GO_KOLOGARN_DOOR                      = 194553,
    GO_THORIM_CHEST_HERO                  = 194315,
    GO_THORIM_CHEST                       = 194314,
    GO_THORIM_ENCOUNTER_DOOR              = 194559,
    GO_THORIM_STONE_DOOR                  = 194558,
    GO_THORIM_RUNIC_DOOR                  = 194557,
    GO_HODIR_RARE_CACHE_OF_WINTER         = 194200,
    GO_HODIR_RARE_CACHE_OF_WINTER_HERO    = 194201,
    GO_HODIR_CHEST_HERO                   = 194308,
    GO_HODIR_CHEST                        = 194307,
    GO_LEVIATHAN_DOOR                     = 194905,
    GO_LEVIATHAN_GATE                     = 194630,
    GO_XT_002_DOOR                        = 194631,
    GO_VEZAX_DOOR                         = 194750,
    GO_MOLE_MACHINE                       = 194316,
    GO_RAZOR_HARPOON_1                    = 194542,
    GO_RAZOR_HARPOON_2                    = 194541,
    GO_RAZOR_HARPOON_3                    = 194543,
    GO_RAZOR_HARPOON_4                    = 194519,
    GO_RAZOR_BROKEN_HARPOON               = 194565,
    GO_HODIR_DOOR                         = 194442,
    GO_HODIR_ICE_DOOR                     = 194441,
    GO_HODIR_STONE_DOOR                   = 194634,
    GO_ARCHIVUM_DOOR                      = 194556,
    GO_MIMIRON_TRAIN                      = 194675,
    GO_MIMIRON_ELEVATOR                   = 194749,
    GO_MIMIRON_DOOR_1                     = 194776,
    GO_MIMIRON_DOOR_2                     = 194774,
    GO_MIMIRON_DOOR_3                     = 194775,
    GO_BIG_RED_BUTTON                     = 194739,
    GO_WAY_TO_YOGG                        = 194255,
    GO_YOGGSARON_DOOR                     = 194773,
    GO_YOGGBRAIN_DOOR_1                   = 194635,
    GO_YOGGBRAIN_DOOR_2                   = 194636,
    GO_YOGGBRAIN_DOOR_3                   = 194637,
    GO_ALGALON_DOOR                       = 194767,
    GO_ALGALON_FLOOR_COM                  = 194715,
    GO_ALGALON_FLOOR_OOC                  = 194716,
    GO_ALGALON_GLOBE                      = 194148,
    GO_ALGALON_BRIDGE                     = 194253,
    GO_ALGALON_INVISDOOR                  = 194910,
    GO_ALGALON_CONSOLE                    = 194628,
    GO_GIFT_OF_THE_OBSERVER               = 194821,
    GO_IRON_COUNCIL_ENTRANCE              = 194554,
    GO_XT002_DOOR                         = 194631,
};

enum UlduarSharedActions
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
    ACTION_ALGALON_ASCEND               = -123460, //Wipe Raid, don't respawn
};

enum UlduarAchievementCriteriaIds
{
    CRITERIA_CON_SPEED_ATORY    = 21597,
    CRITERIA_DISARMED           = 21687,
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

    //Mimiron
    DATA_LEVIATHAN_MK_II,
    DATA_VX_001,
    DATA_AERIAL_UNIT,
    DATA_MIMIRON_ELEVATOR,
    DATA_CALL_TRAM,

    // Thorim
    DATA_RUNIC_COLOSSUS,
    DATA_RUNE_GIANT,
    DATA_RUNIC_DOOR,
    DATA_STONE_DOOR,
    DATA_HODIR_RARE_CHEST,
	
    // Hodir
    DATA_HODIR_RARE_CACHE,
	
    //Algalon
    DATA_ALGALON_INTRO,
    DATA_ALGALON_TIMER,
    DATA_BRANN_ALGALON,
	
    //Yogg Saron
    TYPE_SARA,
    TYPE_BRAIN_DOOR_1,
    TYPE_BRAIN_DOOR_2,
    TYPE_BRAIN_DOOR_3,
    DATA_KEEPER_SUPPORT_YOGG,
    DATA_ADD_HELP_FLAG,
    DATA_PORTAL_PHASE = 1,
};

enum UlduarWorldStates
{
    WORLDSTATE_SHOW_TIMER                 = 4132,
    WORLDSTATE_ALGALON_TIMER              = 4131
};

enum UlduarAchievements
{
    ACHIEVEMENT_CHAMPION_OF_ULDUAR      = 2903,
    ACHIEVEMENT_CONQUEROR_OF_ULDUAR     = 2904
};

enum UlduarAchievementCriteria
{
    ACHIEVEMENT_UNBROKEN_10                              = 10044, // Leviathan
    ACHIEVEMENT_UNBROKEN_25                              = 10045,
    ACHIEVEMENT_CRITERIA_SHUTOUT_10                      = 10054,
    ACHIEVEMENT_CRITERIA_SHUTOUT_25                      = 10055,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_CHOPPER_10         = 10046,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_SIEGE_10           = 10047,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_DEMOLISHER_10      = 10048,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_CHOPPER_25         = 10049,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_SIEGE_25           = 10050,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_DEMOLISHER_25      = 10051,
    ACHIEVEMENT_CRITERIA_HOT_POCKET_10                   = 10430, // Ignis
    ACHIEVEMENT_CRITERIA_HOT_POCKET_25                   = 10431,
    ACHIEVEMENT_CRITERIA_QUICK_SHAVE_10                  = 10062, // Razorscale
    ACHIEVEMENT_CRITERIA_QUICK_SHAVE_25                             = 10063,
    ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_25         = 10321, // Yogg-Saron
    ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_10         = 10324,
    ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_25               = 10322,
    ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_10               = 10325,
    ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_25                   = 10323,
    ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_10                   = 10326,

    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FLAMELEVIATAN_10       = 10042,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_IGNIS_10               = 10342,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_RAZORSCALE_10          = 10340,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_XT002_10               = 10341,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ASSEMBLY_10            = 10598,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_KOLOGARN_10            = 10348,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_AURIAYA_10             = 10351,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_HODIR_10               = 10439,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_THORIM_10              = 10403,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FREYA_10               = 10582,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_MIMIRON_10             = 10347,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_VEZAX_10               = 10349,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_YOGGSARON_10           = 10350,

    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FLAMELEVIATAN_25       = 10352,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_IGNIS_25               = 10355,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_RAZORSCALE_25          = 10353,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_XT002_25               = 10354,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ASSEMBLY_25            = 10599,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_KOLOGARN_25            = 10357,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_AURIAYA_25             = 10363,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_HODIR_25               = 10719,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_THORIM_25              = 10404,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FREYA_25               = 10583,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_MIMIRON_25             = 10361,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_VEZAX_25               = 10362,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_YOGGSARON_25           = 10364,

    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_10             = 10568,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_25             = 10570
};

enum UlduarKeeperSupport
{
    THORIM_SUPPORT                      = 0x01,
    HODIR_SUPPORT                       = 0x02,
    FREYA_SUPPORT                       = 0x04,
    MIMIRON_SUPPORT                     = 0x08
};

enum UlduarBossDeadFlags
{
    DEAD_FLAME_LEVIATHAN                = 0x0001,
    DEAD_IGNIS                          = 0x0002,
    DEAD_RAZORSCALE                     = 0x0004,
    DEAD_XT002                          = 0x0008,
    DEAD_ASSEMBLY                       = 0x0010,
    DEAD_KOLOGARN                       = 0x0020,
    DEAD_AURIAYA                        = 0x0040,
    DEAD_HODIR                          = 0x0080,
    DEAD_THORIM                         = 0x0100,
    DEAD_FREYA                          = 0x0200,
    DEAD_MIMIRON                        = 0x0400,
    DEAD_VEZAX                          = 0x0800,
    DEAD_YOGGSARON                      = 0x1000
};

enum UlduarActions
{
    ACTION_ACTIVATE_HARD_MODE        = 12,
};

enum UlduarAchievementData
{
    // FL Achievement boolean
    DATA_UNBROKEN = 29052906, // 2905, 2906 are achievement IDs,
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

class PlayerOrPetCheck
{
    public:
        bool operator() (Unit* unit)
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                if (!unit->ToCreature()->isPet())
                    return true;

            return false;
        }
};

#endif
